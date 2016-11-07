//---------------------------------------------------------------------------//
//!
//! \file   tstElectroionizationSubshellAdjointElectronScatteringDistribution.cpp
//! \author Luke Kersting
//! \brief  adjoint electroionization subshell scattering distribution Native factory unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>

// Trilinos Includes
#include <Teuchos_UnitTestHarness.hpp>
#include <Teuchos_VerboseObject.hpp>
#include <Teuchos_RCP.hpp>

// FRENSIE Includes
#include "MonteCarlo_ElectroionizationSubshellAdjointElectronScatteringDistribution.hpp"
#include "Data_AdjointElectronPhotonRelaxationDataContainer.hpp"
#include "Utility_TabularDistribution.hpp"
#include "Utility_RandomNumberGenerator.hpp"
#include "Utility_UnitTestHarnessExtensions.hpp"

//---------------------------------------------------------------------------//
// Testing Variables.
//---------------------------------------------------------------------------//

Teuchos::RCP<Data::AdjointElectronPhotonRelaxationDataContainer> data_container;

std::shared_ptr<const MonteCarlo::ElectroionizationSubshellAdjointElectronScatteringDistribution>
  native_distribution;

//---------------------------------------------------------------------------//
// Tests
//---------------------------------------------------------------------------//
// Check that the subshell binding energy
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   getBindingEnergy )
{

  // Get binding energy
  double binding_energy = native_distribution->getBindingEnergy();

  // Test original electron
  TEST_EQUALITY_CONST( binding_energy, 1.361E-05 );
}

//---------------------------------------------------------------------------//
// Check that the PDF can be evaluated for a given incoming and knock-on energy
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   evaluate )
{
  double pdf;

  // Check below the first bin
  pdf = native_distribution->evaluate( 1e-6, 2.3711E-5 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 0.0, 1e-12 );

  // Check the first bin
  pdf = native_distribution->evaluate( 1e-5, 2.3711E-5 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 2.51360045307012E+03, 1e-12 );

  // Check between two bins
  pdf = native_distribution->evaluate( 1.1e-5, 1e-3 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 6.24197871504572, 1e-12 );

  // Check the last bin
  pdf = native_distribution->evaluate( 20.0, 20.00002722 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 2.23186158924304E+04, 1e-12 );

  // Check above the last bin
  pdf = native_distribution->evaluate( 21.0, 22.1 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 0.0, 1e-12 );
}

//---------------------------------------------------------------------------//
// Check that the PDF can be evaluated for a given incoming and knock-on energy
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   evaluatePDF )
{
  double pdf;

  // Check below the first bin
  pdf = native_distribution->evaluatePDF( 1e-6, 2.3711E-5 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 0.0, 1e-12 );

  // Check the first bin
  pdf = native_distribution->evaluatePDF( 1e-5, 2.3711E-5 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 2.49893939125706E+03, 1e-12 );

  // Check between two bins
  pdf = native_distribution->evaluatePDF( 1.1e-5, 1e-3 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 6.20545711833511, 1e-12 );

  // Check the last bin
  pdf = native_distribution->evaluatePDF( 20.0, 20.00002722 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 1.88771105446117E+04, 1e-12 );

  // Check above the last bin
  pdf = native_distribution->evaluatePDF( 21.0, 22.1 );
  UTILITY_TEST_FLOATING_EQUALITY( pdf, 0.0, 1e-12 );
}

//---------------------------------------------------------------------------//
// Check that the PDF can be evaluated for a given incoming and knock-on energy
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   evaluateCDF )
{
  double cdf;

  // Check below the first bin
  cdf = native_distribution->evaluateCDF( 1e-5, 1.361e-5 );
  UTILITY_TEST_FLOATING_EQUALITY( cdf, 0.0, 1e-12 );

  // Check the first bin
  cdf = native_distribution->evaluateCDF( 1e-5, 2.3711E-5 );
  UTILITY_TEST_FLOATING_EQUALITY( cdf, 0.0, 1e-12 );

  // Check between two bins
  cdf = native_distribution->evaluateCDF( 1.1e-5, 1e-3 );
  UTILITY_TEST_FLOATING_EQUALITY( cdf, 1.33873139177471E-02, 1e-12 );

  // Check the last bin
  cdf = native_distribution->evaluateCDF( 20.0, 20.00002722 );
  UTILITY_TEST_FLOATING_EQUALITY( cdf, 1.0, 1e-12 );

  // Check above the last bin
  cdf = native_distribution->evaluateCDF( 21.0, 22.1 );
  UTILITY_TEST_FLOATING_EQUALITY( cdf, 0.0, 1e-12 );
}

//---------------------------------------------------------------------------//
// Check that the screening angle can be evaluated
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   sample )
{
  // Set fake random number stream
  std::vector<double> fake_stream( 1 );
  fake_stream[0] = 1.3137507341127E-02;

  Utility::RandomNumberGenerator::setFakeStream( fake_stream );

  double scattering_angle_cosine, outgoing_energy, incoming_energy = 1e-5;

  // sample the electron
  native_distribution->sample( incoming_energy,
                               outgoing_energy,
                               scattering_angle_cosine );

  // Test knock-on electron
  TEST_FLOATING_EQUALITY( scattering_angle_cosine, 1.0004842234463E-01, 1e-10 );
  TEST_FLOATING_EQUALITY( outgoing_energy, 1e-3, 1e-12 );

}

//---------------------------------------------------------------------------//
// Check that the screening angle can be evaluated
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   sampleAndRecordTrials )
{
  // Set fake random number stream
  std::vector<double> fake_stream( 1 );
  fake_stream[0] = 1.3137507341127E-02;

  unsigned trials = 0.0;

  double incoming_energy = 1e-5;

  double outgoing_energy, scattering_angle_cosine;

  // sample the electron
  native_distribution->sampleAndRecordTrials( incoming_energy,
                                              outgoing_energy,
                                              scattering_angle_cosine,
                                              trials );

  // Test trials
  TEST_EQUALITY_CONST( trials, 1.0 );

  // Test knock-on electron
  TEST_FLOATING_EQUALITY( scattering_angle_cosine, 1.0004842234463E-01, 1e-10 );
  TEST_FLOATING_EQUALITY( outgoing_energy, 1e-3, 1e-12 );

}

//---------------------------------------------------------------------------//
// Check that the screening angle can be evaluated
TEUCHOS_UNIT_TEST( ElectroionizationSubshellAdjointElectronScatteringDistribution,
                   scatterAdjointElectron )
{
  // Set fake random number stream
  std::vector<double> fake_stream( 1 );
  fake_stream[0] = 1.3137507341127E-02;

  Utility::RandomNumberGenerator::setFakeStream( fake_stream );

  MonteCarlo::ParticleBank bank;
  Data::SubshellType shell_of_interaction;

  MonteCarlo::AdjointElectronState electron( 0 );
  electron.setEnergy( 1e-5 );
  electron.setDirection( 0.0, 0.0, 1.0 );

  // Analytically scatter electron
  native_distribution->scatterAdjointElectron( electron,
                                               bank,
                                               shell_of_interaction );

  // Test original electron
  TEST_FLOATING_EQUALITY( electron.getZDirection(), 1.0004842234463E-01, 1e-10 );
  TEST_FLOATING_EQUALITY( electron.getEnergy(), 1e-3, 1e-12 );
}

//---------------------------------------------------------------------------//
// Custom main function
//---------------------------------------------------------------------------//
int main( int argc, char** argv )
{
  std::string test_native_file_name;

  Teuchos::CommandLineProcessor& clp = Teuchos::UnitTestRepository::getCLP();

  clp.setOption( "test_native_file",
                 &test_native_file_name,
                 "Test native file name" );

  const Teuchos::RCP<Teuchos::FancyOStream> out =
    Teuchos::VerboseObjectBase::getDefaultOStream();

  Teuchos::CommandLineProcessor::EParseCommandLineReturn parse_return =
    clp.parse(argc,argv);

  if ( parse_return != Teuchos::CommandLineProcessor::PARSE_SUCCESSFUL )
  {
    *out << "\nEnd Result: TEST FAILED" << std::endl;
    return parse_return;
  }

  // Create the native data file container
  data_container.reset( new Data::AdjointElectronPhotonRelaxationDataContainer(
                             test_native_file_name ) );

  // Set binding energy
  double binding_energy = 1.361E-05;

  std::vector<double> energy_grid =
    data_container->getAdjointElectronEnergyGrid();

  // Create the scattering function
  Utility::FullyTabularTwoDDistribution::DistributionType
     function_data( energy_grid.size() );

  for( unsigned n = 0; n < energy_grid.size(); ++n )
  {
    function_data[n].first = energy_grid[n];

    // Get the recoil energy distribution at the incoming energy
    Teuchos::Array<double> recoil_energy(
      data_container->getAdjointElectroionizationRecoilEnergy(
        1,
        energy_grid[n] ) );

    // Get the recoil energy pdf at the incoming energy
    Teuchos::Array<double> pdf(
      data_container->getAdjointElectroionizationRecoilPDF(
        1,
        energy_grid[n] ) );

    function_data[n].second.reset(
      new const Utility::TabularDistribution<Utility::LinLin>( recoil_energy,
                                                               pdf ) );
  }

  // Create the scattering function
  std::shared_ptr<Utility::FullyTabularTwoDDistribution> subshell_distribution(
    new Utility::InterpolatedFullyTabularTwoDDistribution<Utility::LinLinLog>(
            function_data ) );

  native_distribution.reset(
     new MonteCarlo::ElectroionizationSubshellAdjointElectronScatteringDistribution(
            subshell_distribution,
            binding_energy ) );

  // Initialize the random number generator
  Utility::RandomNumberGenerator::createStreams();

  // Run the unit tests
  Teuchos::GlobalMPISession mpiSession( &argc, &argv );

  const bool success = Teuchos::UnitTestRepository::runUnitTests( *out );

  if (success)
    *out << "\nEnd Result: TEST PASSED" << std::endl;
  else
    *out << "\nEnd Result: TEST FAILED" << std::endl;

  clp.printFinalTimerSummary(out.ptr());

  return (success ? 0 : 1);
}

//---------------------------------------------------------------------------//
// end tstElectroionizationSubshellAdjointElectronScatteringDistribution.cpp
//---------------------------------------------------------------------------//
