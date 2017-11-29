//---------------------------------------------------------------------------//
//!
//! \file   tstAdjointElectroatomFactory.cpp
//! \author Luke Kersting
//! \brief  Adjoint electroatom factory unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>

// Trilinos Includes
#include <Teuchos_UnitTestHarness.hpp>
#include <Teuchos_VerboseObject.hpp>
#include <Teuchos_RCP.hpp>
#include <Teuchos_XMLParameterListCoreHelpers.hpp>

// FRENSIE Includes
#include "MonteCarlo_AdjointElectroatomFactory.hpp"
#include "MonteCarlo_AtomicRelaxationModelFactory.hpp"
#include "MonteCarlo_BremsstrahlungAngularDistributionType.hpp"
#include "MonteCarlo_CutoffElasticElectronScatteringDistribution.hpp"
#include "MonteCarlo_ElasticElectronScatteringDistributionNativeFactory.hpp"
#include "MonteCarlo_ParticleBank.hpp"
#include "MonteCarlo_AdjointElectronState.hpp"
#include "MonteCarlo_SimulationAdjointElectronProperties.hpp"
#include "Utility_UnitTestHarnessExtensions.hpp"
#include "Data_CrossSectionsXMLProperties.hpp"

//---------------------------------------------------------------------------//
// Testing Variables
//---------------------------------------------------------------------------//

std::string cross_sections_xml_directory;
Teuchos::ParameterList cross_section_table_info;

std::shared_ptr<MonteCarlo::SimulationAdjointElectronProperties> properties;

//---------------------------------------------------------------------------//
// Tests
//---------------------------------------------------------------------------//
// Check that a adjoint electroatom map can be created (only basic data)
TEUCHOS_UNIT_TEST( AdjointElectroatomFactory, createAdjointElectroatomMap_basic )
{
  // Create the set of electroatom aliases
  std::unordered_set<std::string> electroatom_aliases;
  electroatom_aliases.insert( "H-Native" );

  properties->setAdjointElasticCutoffAngleCosine( 0.9 );
  properties->setAdjointElectronEvaluationTolerance( 1e-7 );
  properties->setAdjointElasticElectronDistributionMode( MonteCarlo::HYBRID_DISTRIBUTION );

  std::shared_ptr<MonteCarlo::AdjointElectroatomFactory> electroatom_factory(
                    new MonteCarlo::AdjointElectroatomFactory(
                                                cross_sections_xml_directory,
                                                cross_section_table_info,
                                                electroatom_aliases,
                                                *properties ) );

  std::string electroatom_file_path, electroatom_file_type, electroatom_table_name;
  int electroatom_file_start_line;
  double atomic_weight;

  Data::CrossSectionsXMLProperties::extractInfoFromAdjointElectroatomTableInfoParameterList(
                          cross_sections_xml_directory,
                          "H-Native",
                          cross_section_table_info,
                          electroatom_file_path,
                          electroatom_file_type,
                          electroatom_table_name,
                          electroatom_file_start_line,
                          atomic_weight );

  // Create the native data file container
  Teuchos::RCP<Data::AdjointElectronPhotonRelaxationDataContainer> data_container(
    new Data::AdjointElectronPhotonRelaxationDataContainer(
                             electroatom_file_path ) );

  std::shared_ptr<const MonteCarlo::CutoffElasticElectronScatteringDistribution>
    cutoff_elastic_distribution;

  MonteCarlo::ElasticElectronScatteringDistributionNativeFactory::createCutoffElasticDistribution<Utility::LogLogCosLog,Utility::Exact>(
        cutoff_elastic_distribution,
        *data_container,
        properties->getAdjointElasticCutoffAngleCosine(),
        properties->getAdjointElectronEvaluationTolerance() );

  std::unordered_map<std::string,Teuchos::RCP<MonteCarlo::AdjointElectroatom> >
    electroatom_map;

  electroatom_factory->createAdjointElectroatomMap( electroatom_map );

  TEST_EQUALITY_CONST( electroatom_map.size(), 1 );
  TEST_ASSERT( electroatom_map.count( "H-Native" ) );
  TEST_ASSERT( !electroatom_map["H-Native"].is_null() );

  Teuchos::RCP<MonteCarlo::AdjointElectroatom>& atom = electroatom_map["H-Native"];

  // Test the electroatom properties
  TEST_EQUALITY_CONST( atom->getAtomicNumber(), 1 );
  TEST_FLOATING_EQUALITY( atom->getAtomicWeight(), 1.00790034799796868, 1e-12 );

  // Test that the total cross section can be returned
  double energy = 1e-5;
  double cross_section = atom->getTotalCrossSection( energy );
  TEST_FLOATING_EQUALITY( cross_section, 4.6910490263724777e+10, 1e-12 );

  energy = 1e-3;
  cross_section = atom->getTotalCrossSection( energy );
  TEST_FLOATING_EQUALITY( cross_section, 2.9058935591302350e+07, 1e-12 );

  energy = 20.0;
  cross_section = atom->getTotalCrossSection( energy );
  TEST_FLOATING_EQUALITY( cross_section, 1.4402886899031530e+05, 1e-12 );


  // Test that the absorption cross section can be returned
  cross_section = atom->getAbsorptionCrossSection( 1e-5 );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section =  atom->getAbsorptionCrossSection( 1e-3 );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getAbsorptionCrossSection( 20.0 );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  MonteCarlo::AdjointElectroatomicReactionType reaction;

  // Test that the atomic excitation cross section can be returned
  reaction = MonteCarlo::ATOMIC_EXCITATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 6.1243057898416743e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.0551636170350602e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 8.1829299836129925e+04, 1e-12 );


  // Test that the bremsstrahlung cross section can be returned
  reaction = MonteCarlo::BREMSSTRAHLUNG_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 4.6329278793906738e+01, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.6620526718982738e+01, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 7.7114113565473230e-01, 1e-12 );


  // Test that the coupled elastic cross section can be returned
  reaction = MonteCarlo::DECOUPLED_ELASTIC_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  // Test that the coupled elastic cross section can be returned
  reaction = MonteCarlo::COUPLED_ELASTIC_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  // Test that there is no hybrid elastic cross section
  reaction = MonteCarlo::HYBRID_ELASTIC_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 2.7336893667900169e+08, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.9778260498147749e+06, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 2.0523455605114753, 1e-12 );


  // Test that there is no total electroionization
  reaction = MonteCarlo::TOTAL_ELECTROIONIZATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  // Test that the K subshell electroionization cross section can be returned
  reaction = MonteCarlo::K_SUBSHELL_ELECTROIONIZATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 4.6575878222818077e+10, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.6529456750610253e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 6.2196745667489216e+04, 1e-12 );


  // Test that the L1 subshell electroionization cross section can be returned
  reaction = MonteCarlo::L1_SUBSHELL_ELECTROIONIZATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );
}

//---------------------------------------------------------------------------//
// Check that a adjoint electroatom map can be created (electroionization subshell data)
TEUCHOS_UNIT_TEST( AdjointElectroatomFactory,
                   createAdjointElectroatomMap_ionization_subshells )
{
  // Create the set of electroatom aliases
  std::unordered_set<std::string> electroatom_aliases;
  electroatom_aliases.insert( "C-Native" );

  properties->setAdjointElasticCutoffAngleCosine( 1.0 );

  std::shared_ptr<MonteCarlo::AdjointElectroatomFactory> electroatom_factory(
                    new MonteCarlo::AdjointElectroatomFactory(
                                              cross_sections_xml_directory,
                                              cross_section_table_info,
                                              electroatom_aliases,
                                              *properties ) );

  std::unordered_map<std::string,Teuchos::RCP<MonteCarlo::AdjointElectroatom> >
    electroatom_map;

  electroatom_factory->createAdjointElectroatomMap( electroatom_map );

  TEST_EQUALITY_CONST( electroatom_map.size(), 1 );
  TEST_ASSERT( electroatom_map.count( "C-Native" ) );
  TEST_ASSERT( !electroatom_map["C-Native"].is_null() );

  Teuchos::RCP<MonteCarlo::AdjointElectroatom>& atom = electroatom_map["C-Native"];

  // Test the adjoint electroatom properties
  TEST_EQUALITY_CONST( atom->getAtomicNumber(), 6 );
  TEST_FLOATING_EQUALITY( atom->getAtomicWeight(), 12.010980086796003263, 1e-12 );

  // Test that the total cross section can be returned
  double energy = 1e-5;
  double cross_section = atom->getTotalCrossSection( energy );
  TEST_FLOATING_EQUALITY( cross_section, 2.4899387289024814e+11, 1e-12 );

  energy = 1e-3;
  cross_section = atom->getTotalCrossSection( energy );
  TEST_FLOATING_EQUALITY( cross_section, 1.8671976244059610e+08, 1e-12 );

  energy = 20.0;
  cross_section = atom->getTotalCrossSection( energy );
  TEST_FLOATING_EQUALITY( cross_section, 4.8752150499570474e+05, 1e-12 );


  // Test that the absorption cross section can be returned
  cross_section = atom->getAbsorptionCrossSection( 1e-5 );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section =  atom->getAbsorptionCrossSection( 1e-3 );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getAbsorptionCrossSection( 20.0 );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  MonteCarlo::AdjointElectroatomicReactionType reaction;

  // Test that the atomic excitation cross section can be returned
  reaction = MonteCarlo::ATOMIC_EXCITATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 5.9000914445996724e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 3.5191230693157382e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.2407699864974697e+05, 1e-12 );


  // Test that the bremsstrahlung cross section can be returned
  reaction = MonteCarlo::BREMSSTRAHLUNG_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.0401092096617892e+03, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 4.4175902182747922e+02, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.0324283679526513e+01, 1e-12 );


  // Test that the coupled elastic cross section can be returned
  reaction = MonteCarlo::DECOUPLED_ELASTIC_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 3.06351e+09, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 5.2833237650446758e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.4129048986120211e+05, 1e-12 );


  // Test that the coupled elastic cross section can be returned
  reaction = MonteCarlo::COUPLED_ELASTIC_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  // Test that there is no hybrid elastic cross section
  reaction = MonteCarlo::HYBRID_ELASTIC_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  // Test that there is no total electroionization
  reaction = MonteCarlo::TOTAL_ELECTROIONIZATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_EQUALITY_CONST( cross_section, 0.0 );


  // Test that the K subshell electroionization cross section can be returned
  reaction = MonteCarlo::K_SUBSHELL_ELECTROIONIZATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.6303270887674353e+09, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.8444779381484181e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.0141974126108344e+04, 1e-12 );

  // Test that there is no P3 subshell electroionization cross section
  reaction = MonteCarlo::L3_SUBSHELL_ELECTROIONIZATION_ADJOINT_ELECTROATOMIC_REACTION;
  cross_section = atom->getReactionCrossSection( 1e-5, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.3606805988184300e+11, 1e-12 );

  cross_section = atom->getReactionCrossSection( 1e-3, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 3.6828335423926719e+07, 1e-12 );

  cross_section = atom->getReactionCrossSection( 20.0, reaction );
  TEST_FLOATING_EQUALITY( cross_section, 1.1872062043218795e+05, 1e-12 );

  // Reset the adjoint electroatom factory
  electroatom_factory.reset();
}

//---------------------------------------------------------------------------//
// Check that tables are not duplicated
TEUCHOS_UNIT_TEST( AdjointElectroatomFactory, no_duplicate_tables )
{
  // Create the set of electroatom aliases
  std::unordered_set<std::string> electroatom_aliases;
  electroatom_aliases.insert( "H-Native" );
  electroatom_aliases.insert( "H-1-Native" );

  properties->setAdjointElasticCutoffAngleCosine( 1.0 );

  std::shared_ptr<MonteCarlo::AdjointElectroatomFactory> electroatom_factory(
                    new MonteCarlo::AdjointElectroatomFactory(
                                                cross_sections_xml_directory,
                                                cross_section_table_info,
                                                electroatom_aliases,
                                                *properties ) );

  std::unordered_map<std::string,Teuchos::RCP<MonteCarlo::AdjointElectroatom> >
    electroatom_map;

  electroatom_factory->createAdjointElectroatomMap( electroatom_map );

  TEST_EQUALITY_CONST( electroatom_map.size(), 2 );

  TEST_ASSERT( electroatom_map.count( "H-Native" ) );
  TEST_ASSERT( !electroatom_map["H-Native"].is_null() );

  TEST_ASSERT( electroatom_map.count( "H-1-Native" ) );
  TEST_ASSERT( !electroatom_map["H-1-Native"].is_null() );

  TEST_EQUALITY( electroatom_map["H-Native"], electroatom_map["H-1-Native"] );
}

//---------------------------------------------------------------------------//
// Custom setup
//---------------------------------------------------------------------------//
UTILITY_CUSTOM_TEUCHOS_UNIT_TEST_SETUP_BEGIN();

UTILITY_CUSTOM_TEUCHOS_UNIT_TEST_COMMAND_LINE_OPTIONS()
{
  clp().setOption( "test_cross_sections_xml_directory",
                   &cross_sections_xml_directory,
                   "Test cross_sections.xml file name" );
}

UTILITY_CUSTOM_TEUCHOS_UNIT_TEST_DATA_INITIALIZATION()
{
  {
    std::string cross_sections_xml_file = cross_sections_xml_directory;
    cross_sections_xml_file += "/cross_sections.xml";

    // Read in the xml file storing the cross section table info
    Teuchos::updateParametersFromXmlFile(
           cross_sections_xml_file,
           Teuchos::inoutArg( cross_section_table_info ) );
  }

  // Create the simulation properties
  properties.reset( new MonteCarlo::SimulationAdjointElectronProperties );
  properties->setNumberOfAdjointElectronHashGridBins( 100 );
}

UTILITY_CUSTOM_TEUCHOS_UNIT_TEST_SETUP_END();


//---------------------------------------------------------------------------//
// end tstAdjointElectroatomFactory.cpp
//---------------------------------------------------------------------------//