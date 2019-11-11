//---------------------------------------------------------------------------//
//!
//! \file   tstPositronionizationSubshellPositronatomicReactionNative.cpp
//! \author Luke Kersting
//! \brief  Positronionization Subshell positron-atomic reaction unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>

// FRENSIE Includes
#include "MonteCarlo_PositronionizationSubshellPositronatomicReaction.hpp"
#include "MonteCarlo_ElectroionizationSubshellElectronScatteringDistributionNativeFactory.hpp"
#include "MonteCarlo_ElectroionizationSubshellElectronScatteringDistributionACEFactory.hpp"
#include "MonteCarlo_PositronatomicReactionType.hpp"
#include "Data_ElectronPhotonRelaxationDataContainer.hpp"
#include "Data_SubshellType.hpp"
#include "Data_ACEFileHandler.hpp"
#include "Data_XSSEPRDataExtractor.hpp"
#include "Utility_RandomNumberGenerator.hpp"
#include "Utility_HistogramDistribution.hpp"
#include "Utility_UnitTestHarnessWithMain.hpp"

//---------------------------------------------------------------------------//
// Testing Variables.
//---------------------------------------------------------------------------//

std::shared_ptr<MonteCarlo::PositronionizationSubshellPositronatomicReaction<Utility::LogLog> >
    native_first_subshell_reaction, native_last_subshell_reaction;

double max_ionization_subshell_adjoint_energy;
double ace_first_binding_energy, ace_last_binding_energy;
double native_first_binding_energy, native_last_binding_energy;

//---------------------------------------------------------------------------//
// Testing Functions.
//---------------------------------------------------------------------------//
bool notEqualZero( double value )
{
  return value != 0.0;
}

//---------------------------------------------------------------------------//
// Tests
//---------------------------------------------------------------------------//
// Check that the hydrogen differential cross section can be evaluated for the first subshell
FRENSIE_UNIT_TEST( PositronionizationSubshellPositronatomicReaction,
                   getDifferentialCrossSection_native )
{
  // First subshell
  // double diff_cross_section =
  //   native_first_subshell_reaction->getDifferentialCrossSection(
  //       1.70425200079801E-03,
  //       8.52126000399011E-04 );

  // FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 1.0422076549158518e+08, 1e-12 );

  // diff_cross_section =
  //   native_first_subshell_reaction->getDifferentialCrossSection(
  //       1.70425200079802E-03,
  //       8.52126000399011E-04 );

  // FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 1.0422076549158294e+08, 1e-12 );

  // diff_cross_section =
  //   native_first_subshell_reaction->getDifferentialCrossSection(
  //       1.98284583249127E-03,
  //       8.52126000399011E-04 );

  // FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 6.3604864772376753e+07, 1e-12 );

  // diff_cross_section =
  //   native_first_subshell_reaction->getDifferentialCrossSection(
  //       2.00191878322064E-03,
  //       8.52126000399011E-04 );

  // FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 5.9982050362880379e+07, 1e-12 );


  // Last subshell
  double diff_cross_section =
    native_last_subshell_reaction->getDifferentialCrossSection(
        0.0025118800000459599528,
        0.0012514500000459765489 );

  FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 2.323969587494164333e+07, 1e-12 );

  diff_cross_section =
    native_last_subshell_reaction->getDifferentialCrossSection(
        0.0025118800000459773,
        0.0012514500000459765489 );

  FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 2.323969587494142726e+07, 1e-12 );

  diff_cross_section =
    native_last_subshell_reaction->getDifferentialCrossSection(
        0.002511885,
        0.0012514500000459765489 );

  FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 2.323968814544089139e+07, 1e-12 );

  diff_cross_section =
    native_last_subshell_reaction->getDifferentialCrossSection(
        0.0025118897153524992472,
        0.0012514500000459765489 );

  FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 2.323968085650828853e+07, 1e-12 );

  diff_cross_section =
    native_last_subshell_reaction->getDifferentialCrossSection(
        0.0025118908794333669708,
        0.0012514500000459765489 );

  FRENSIE_CHECK_FLOATING_EQUALITY( diff_cross_section, 2.323796410036558285e+07, 1e-12 );
}

//---------------------------------------------------------------------------//
// Custom setup
//---------------------------------------------------------------------------//
FRENSIE_CUSTOM_UNIT_TEST_SETUP_BEGIN();

std::string test_native_file_name;

FRENSIE_CUSTOM_UNIT_TEST_COMMAND_LINE_OPTIONS()
{
  ADD_STANDARD_OPTION_AND_ASSIGN_VALUE( "test_native_file",
                                        test_native_file_name, "",
                                        "Test Native file name" );
}

FRENSIE_CUSTOM_UNIT_TEST_INIT()
{
  // Create the native data file container
  std::shared_ptr<Data::ElectronPhotonRelaxationDataContainer> data_container;
  data_container.reset( new Data::ElectronPhotonRelaxationDataContainer(
                                                    test_native_file_name ) );

  // Extract the common electron energy grid
  std::shared_ptr<const std::vector<double> > energy_grid(
          new std::vector<double>( data_container->getElectronEnergyGrid() ) );

  // Create the hash-based grid searcher
  std::shared_ptr<Utility::HashBasedGridSearcher<double> > grid_searcher(
       new Utility::StandardHashBasedGridSearcher<std::vector<double>,false>(
                  energy_grid,
                  energy_grid->front(),
                  energy_grid->back(),
                  energy_grid->size()/10 + 1 ) );

  // Extract the subshell information
  std::set<unsigned> subshells = data_container->getSubshells();

  // Create the distribution for the first subshell
  {
    std::set<unsigned>::iterator shell = data_container->getSubshells().begin();

    // Convert subshell number to enum
    Data::SubshellType subshell_type =
      Data::convertENDFDesignatorToSubshellEnum( *shell );

    // Positronionization cross section
    std::shared_ptr<std::vector<double> > subshell_cross_section(
       new std::vector<double>( data_container->getElectroionizationCrossSection( *shell ) ) );

    // Positronionization cross section threshold energy bin index
    size_t threshold_energy_index =
        data_container->getElectroionizationCrossSectionThresholdEnergyIndex(
        *shell );

    // The electroionization subshell distribution
    std::shared_ptr<const MonteCarlo::ElectroionizationSubshellElectronScatteringDistribution>
        electroionization_subshell_distribution;

    native_first_binding_energy =
      data_container->getSubshellBindingEnergy( *shell );

    MonteCarlo::ElectroionizationSamplingType sampling_type =
      MonteCarlo::KNOCK_ON_SAMPLING;

    // Create the electroionization subshell distribution
    MonteCarlo::ElectroionizationSubshellElectronScatteringDistributionNativeFactory::createElectroionizationSubshellDistribution<Utility::LogLogLog,Utility::UnitBaseCorrelated>(
        *data_container,
        *shell,
        native_first_binding_energy,
        electroionization_subshell_distribution,
        sampling_type,
        1e-15 );

    // Create the subshell electroelectric reaction
    native_first_subshell_reaction.reset(
        new MonteCarlo::PositronionizationSubshellPositronatomicReaction<Utility::LogLog>(
                energy_grid,
                subshell_cross_section,
                threshold_energy_index,
                grid_searcher,
                subshell_type,
                electroionization_subshell_distribution ) );
  }

  // Create the distribution for the last subshell
  {
    // Last subshell
    std::set<unsigned>::iterator shell = data_container->getSubshells().end();
    --shell;

    // Convert subshell number to enum
    Data::SubshellType subshell_type =
      Data::convertENDFDesignatorToSubshellEnum( *shell );

    // Positronionization cross section
    std::shared_ptr<std::vector<double> > subshell_cross_section(
       new std::vector<double>( data_container->getElectroionizationCrossSection( *shell ) ) );

    // Positronionization cross section threshold energy bin index
    size_t threshold_energy_index =
        data_container->getElectroionizationCrossSectionThresholdEnergyIndex(
        *shell );

    // The electroionization subshell distribution
    std::shared_ptr<const MonteCarlo::ElectroionizationSubshellElectronScatteringDistribution>
        electroionization_subshell_distribution;

    native_last_binding_energy =
      data_container->getSubshellBindingEnergy( *shell );

    MonteCarlo::ElectroionizationSamplingType sampling_type =
      MonteCarlo::KNOCK_ON_SAMPLING;

    // Create the electroionization subshell distribution
    MonteCarlo::ElectroionizationSubshellElectronScatteringDistributionNativeFactory::createElectroionizationSubshellDistribution<Utility::LogLogLog,Utility::UnitBaseCorrelated>(
        *data_container,
        *shell,
        native_last_binding_energy,
        electroionization_subshell_distribution,
        sampling_type,
        1e-12 );

    // Create the subshell electroelectric reaction
    native_last_subshell_reaction.reset(
        new MonteCarlo::PositronionizationSubshellPositronatomicReaction<Utility::LogLog>(
                energy_grid,
                subshell_cross_section,
                threshold_energy_index,
                grid_searcher,
                subshell_type,
                electroionization_subshell_distribution ) );
  }
  
  // Initialize the random number generator
  Utility::RandomNumberGenerator::createStreams();
}

FRENSIE_CUSTOM_UNIT_TEST_SETUP_END();

//---------------------------------------------------------------------------//
// end tstPositronionizationSubshellPositronatomicReactionNative.cpp
//---------------------------------------------------------------------------//
