//---------------------------------------------------------------------------//
//!
//! \file   tstAdjointElectronPhotonRelaxationDataContainer.cpp
//! \author Alex Robinson
//! \brief  Electron-photon-relaxation data container class unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <string>
#include <iostream>

// Trilinos Includes
#include <Teuchos_UnitTestHarness.hpp>
#include <Teuchos_VerboseObject.hpp>

// FRENSIE Includes
#include "Data_AdjointElectronPhotonRelaxationVolatileDataContainer.hpp"
#include "Data_AdjointElectronPhotonRelaxationDataContainer.hpp"
#include "Utility_UnitTestHarnessExtensions.hpp"


//---------------------------------------------------------------------------//
// Testing Variables
//---------------------------------------------------------------------------//

Data::AdjointElectronPhotonRelaxationVolatileDataContainer epr_data_container;

const std::string notes( "This is a test data table. Do not use it for "
                         "anything other than tests!" );

//---------------------------------------------------------------------------//
// Tests.
//---------------------------------------------------------------------------//
// Check that the table notes can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setNotes )
{
  epr_data_container.setNotes( notes );

  TEST_EQUALITY_CONST( epr_data_container.getNotes(), notes );
}

//---------------------------------------------------------------------------//
// Basic Table Tests
//---------------------------------------------------------------------------//
// Check that the atomic number can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setAtomicNumber )
{
  epr_data_container.setAtomicNumber( 1u );

  TEST_EQUALITY_CONST( epr_data_container.getAtomicNumber(), 1u );
}

//---------------------------------------------------------------------------//
// Check that the min photon energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setMinPhotonEnergy )
{
  epr_data_container.setMinPhotonEnergy( 0.001 );

  TEST_EQUALITY_CONST( epr_data_container.getMinPhotonEnergy(),
                       0.001 );
}

//---------------------------------------------------------------------------//
// Check that the max photon energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setMaxPhotonEnergy )
{
  epr_data_container.setMaxPhotonEnergy( 20.0 );

  TEST_EQUALITY_CONST( epr_data_container.getMaxPhotonEnergy(),
                       20.0 );
}

//---------------------------------------------------------------------------//
// Check that the min electron energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setMinElectronEnergy )
{
  epr_data_container.setMinElectronEnergy( 1.0e-5 );

  TEST_EQUALITY_CONST( epr_data_container.getMinElectronEnergy(),
                       1.0e-5 );
}

//---------------------------------------------------------------------------//
// Check that the max electron energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setMaxElectronEnergy )
{
  epr_data_container.setMaxElectronEnergy( 1.0e+5 );

  TEST_EQUALITY_CONST( epr_data_container.getMaxElectronEnergy(),
                       1.0e+5 );
}

//---------------------------------------------------------------------------//
// Check that the grid convergence tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setGridConvergenceTolerance )
{
  epr_data_container.setGridConvergenceTolerance( 0.001 );

  TEST_EQUALITY_CONST( epr_data_container.getGridConvergenceTolerance(),
                       0.001 );
}

//---------------------------------------------------------------------------//
// Check that the grid absolute difference tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setGridAbsoluteDifferenceTolerance )
{
  epr_data_container.setGridAbsoluteDifferenceTolerance( 1e-42 );

  TEST_EQUALITY_CONST( epr_data_container.getGridAbsoluteDifferenceTolerance(),
                       1e-42 );
}

//---------------------------------------------------------------------------//
// Check that the grid distance tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setGridDistanceTolerance )
{
  epr_data_container.setGridDistanceTolerance( 1e-15 );

  TEST_EQUALITY_CONST( epr_data_container.getGridDistanceTolerance(),
                       1e-15 );
}

//---------------------------------------------------------------------------//
// Photon Table Tests
//---------------------------------------------------------------------------//
// Check that the adjoint pair production energy dist norm constant evaluation
// tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPairProductionEnergyDistNormConstantEvaluationTolerance )
{
  epr_data_container.setAdjointPairProductionEnergyDistNormConstantEvaluationTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointPairProductionEnergyDistNormConstantEvaluationTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint pair production energy dist norm constant nudge
// value can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPairProductionEnergyDistNormConstantNudgeValue )
{
  epr_data_container.setAdjointPairProductionEnergyDistNormConstantNudgeValue( 1e-6 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointPairProductionEnergyDistNormConstantNudgeValue(),
                       1e-6 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint triplet production energy dist norm constant
// evaluation tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTripletProductionEnergyDistNormConstantEvaluationTolerance )
{
  epr_data_container.setAdjointTripletProductionEnergyDistNormConstantEvaluationTolerance( 1e-4 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointTripletProductionEnergyDistNormConstantEvaluationTolerance(),
                       1e-4 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint triplet production energy dist norm constant nudge
// value can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTripletProductionEnergyDistNormConstantNudgeValue )
{
  epr_data_container.setAdjointTripletProductionEnergyDistNormConstantNudgeValue( 1e-5 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointTripletProductionEnergyDistNormConstantNudgeValue(),
                       1e-5 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent max energy nudge value can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointIncoherentMaxEnergyNudgeValue )
{
  epr_data_container.setAdjointIncoherentMaxEnergyNudgeValue( 0.2 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointIncoherentMaxEnergyNudgeValue(),
                       0.2 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent energy to max energy nudge value can be
// set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointIncoherentEnergyToMaxEnergyNudgeValue )
{
  epr_data_container.setAdjointIncoherentEnergyToMaxEnergyNudgeValue( 1e-6 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointIncoherentEnergyToMaxEnergyNudgeValue(),
                       1e-6 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent cross section evaluation tolerance can be
// set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointIncoherentEvaluationTolerance )
{
  epr_data_container.setAdjointIncoherentEvaluationTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointIncoherentEvaluationTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent grid convergence tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointIncoherentGridConvergenceTolerance )
{
  epr_data_container.setAdjointIncoherentGridConvergenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointIncoherentGridConvergenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent grid absolute difference tolerance can
// be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointIncoherentGridAbsoluteDifferenceTolerance )
{
  epr_data_container.setAdjointIncoherentGridAbsoluteDifferenceTolerance( 1e-20 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointIncoherentGridAbsoluteDifferenceTolerance(),
                       1e-20 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent grid distance tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointIncoherentGridDistanceTolerance )
{
  epr_data_container.setAdjointIncoherentGridDistanceTolerance( 1e-15 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointIncoherentGridDistanceTolerance(),
                       1e-15 );
}

//---------------------------------------------------------------------------//
// Electron Table Tests
//---------------------------------------------------------------------------//
// Check that the Cutoff Angle can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setCutoffAngleCosine )
{
  epr_data_container.setCutoffAngleCosine( 0.9 );

  TEST_EQUALITY_CONST( epr_data_container.getCutoffAngleCosine(),
                       0.9 );
}

//---------------------------------------------------------------------------//
// Check that the number of discrete moment preserving angles can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setNumberOfAdjointMomentPreservingAngles )
{
  epr_data_container.setNumberOfAdjointMomentPreservingAngles( 1 );

  TEST_EQUALITY_CONST( epr_data_container.getNumberOfAdjointMomentPreservingAngles(),
                       1 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electron_grid_convergence_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronGridConvergenceTolerance )
{
  epr_data_container.setAdjointElectronGridConvergenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectronGridConvergenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electron_absolute_diff_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronAbsoluteDifferenceTolerance )
{
  epr_data_container.setAdjointElectronAbsoluteDifferenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectronAbsoluteDifferenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electron_distance_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronDistanceTolerance )
{
  epr_data_container.setAdjointElectronDistanceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectronDistanceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the electron tabular tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setElectronTabularEvaluationTolerance )
{
  epr_data_container.setElectronTabularEvaluationTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getElectronTabularEvaluationTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_bremsstrahlung_max_energy_nudge_value can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungMaxEnergyNudgeValue )
{
  epr_data_container.setAdjointBremsstrahlungMaxEnergyNudgeValue( 0.2 );

  TEST_EQUALITY_CONST(
    epr_data_container.getAdjointBremsstrahlungMaxEnergyNudgeValue(),
    0.2 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_bremsstrahlung_energy_to_outgoing_energy_nudge_value can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungEnergyToOutgoingEnergyNudgeValue )
{
  epr_data_container.setAdjointBremsstrahlungEnergyToOutgoingEnergyNudgeValue( 0.2 );

  TEST_EQUALITY_CONST(
    epr_data_container.getAdjointBremsstrahlungEnergyToOutgoingEnergyNudgeValue(),
    0.2 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_bremsstrahlung_evaluation_tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungEvaluationTolerance )
{
  epr_data_container.setAdjointBremsstrahlungEvaluationTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointBremsstrahlungEvaluationTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_bremsstrahlung_convergence_tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungGridConvergenceTolerance )
{
  epr_data_container.setAdjointBremsstrahlungGridConvergenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointBremsstrahlungGridConvergenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_bremsstrahlung_absolute_diff_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungAbsoluteDifferenceTolerance )
{
  epr_data_container.setAdjointBremsstrahlungAbsoluteDifferenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointBremsstrahlungAbsoluteDifferenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_bremsstrahlung_distance_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungDistanceTolerance )
{
  epr_data_container.setAdjointBremsstrahlungDistanceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointBremsstrahlungDistanceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electroionization_evaluation_tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationEvaluationTolerance )
{
  epr_data_container.setAdjointElectroionizationEvaluationTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectroionizationEvaluationTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electroionization_convergence_tolerance can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationGridConvergenceTolerance )
{
  epr_data_container.setAdjointElectroionizationGridConvergenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectroionizationGridConvergenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electroionization_absolute_diff_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationAbsoluteDifferenceTolerance )
{
  epr_data_container.setAdjointElectroionizationAbsoluteDifferenceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectroionizationAbsoluteDifferenceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Check that the adjoint_electroionization_distance_tol can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationDistanceTolerance )
{
  epr_data_container.setAdjointElectroionizationDistanceTolerance( 1e-3 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointElectroionizationDistanceTolerance(),
                       1e-3 );
}

//---------------------------------------------------------------------------//
// Relaxation Tests
//---------------------------------------------------------------------------//
// Check that the subshells can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer, setSubshells )
{
  std::set<unsigned> subshells;
  subshells.insert( 1 );

  epr_data_container.setSubshells( subshells );

  TEST_ASSERT( epr_data_container.getSubshells().count( 1 ) );
  TEST_ASSERT( !epr_data_container.getSubshells().count( 0 ) );
  TEST_ASSERT( !epr_data_container.getSubshells().count( 2 ) );
}

//---------------------------------------------------------------------------//
// Check that the subshell occupancies can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setSubshellOccupancy )
{
  epr_data_container.setSubshellOccupancy( 1, 1.0 );

  TEST_EQUALITY_CONST( epr_data_container.getSubshellOccupancy( 1 ), 1.0 );
}

//---------------------------------------------------------------------------//
// Check that the subshell binding energies can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setSubshellBindingEnergy )
{
  epr_data_container.setSubshellBindingEnergy( 1, 1.361e-5 );

  TEST_EQUALITY_CONST( epr_data_container.getSubshellBindingEnergy( 1 ),
      1.361e-5 );
}

//---------------------------------------------------------------------------//
// Check that the number of subshell relaxation transitions can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   hasAdjointRelaxationData )
{
  TEST_ASSERT( !epr_data_container.hasAdjointRelaxationData() );
}

//---------------------------------------------------------------------------//
// Photon Tests
//---------------------------------------------------------------------------//
// Check that the Compton profile momentum grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setComptonProfileMomentumGrid )
{
  std::vector<double> compton_profile_momentum_grid( 3 );
  compton_profile_momentum_grid[0] = -1.0;
  compton_profile_momentum_grid[1] = 0.0;
  compton_profile_momentum_grid[2] = 1.0;

  epr_data_container.setComptonProfileMomentumGrid(
                                            1, compton_profile_momentum_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getComptonProfileMomentumGrid( 1 ),
                       compton_profile_momentum_grid );
}

//---------------------------------------------------------------------------//
// Check that the Compton profile for a subshell can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setComptonProfile )
{
  std::vector<double> compton_profile( 3 );
  compton_profile[0] = 1e-12;
  compton_profile[1] = 10.0;
  compton_profile[2] = 1e-12;

  epr_data_container.setComptonProfile( 1, compton_profile );

  TEST_COMPARE_ARRAYS( epr_data_container.getComptonProfile( 1 ),
                       compton_profile );
}

//---------------------------------------------------------------------------//
// Check that the occupation number momentum grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setOccupationNumberMomentumGrid )
{
  std::vector<double> momentum_grid( 3 );
  momentum_grid[0] = -1.0;
  momentum_grid[1] = 0.0;
  momentum_grid[2] = 1.0;

  epr_data_container.setOccupationNumberMomentumGrid( 1, momentum_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getOccupationNumberMomentumGrid( 1 ),
                       momentum_grid );
}

//---------------------------------------------------------------------------//
// Check that the occupation number of a subshell can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setOccupationNumber )
{
  std::vector<double> occupation_number( 3 );
  occupation_number[0] = 0.0;
  occupation_number[1] = 0.5;
  occupation_number[2] = 1.0;

  epr_data_container.setOccupationNumber( 1, occupation_number );

  TEST_COMPARE_ARRAYS( epr_data_container.getOccupationNumber( 1 ),
                       occupation_number );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree scattering function momentum grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeScatteringFunctionMomentumGrid )
{
  std::vector<double> momentum_grid( 4 );
  momentum_grid[0] = 1e-30;
  momentum_grid[1] = 1.0;
  momentum_grid[2] = 10.0;
  momentum_grid[3] = 1e8;

  epr_data_container.setWallerHartreeScatteringFunctionMomentumGrid(
                                                               momentum_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeScatteringFunctionMomentumGrid(),
                       momentum_grid );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree scattering function can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeScatteringFunction )
{
  std::vector<double> scattering_function( 4 );
  scattering_function[0] = 1e-30;
  scattering_function[1] = 1e-3;
  scattering_function[2] = 0.1;
  scattering_function[3] = 1.0;

  epr_data_container.setWallerHartreeScatteringFunction( scattering_function );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeScatteringFunction(),
                       scattering_function );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree atomic form factor momentum grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeAtomicFormFactorMomentumGrid )
{
  std::vector<double> momentum_grid( 4 );
  momentum_grid[0] = 1e-30;
  momentum_grid[1] = 1.0;
  momentum_grid[2] = 10.0;
  momentum_grid[3] = 1e8;

  epr_data_container.setWallerHartreeAtomicFormFactorMomentumGrid(
                                                               momentum_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeAtomicFormFactorMomentumGrid(),
                       momentum_grid );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree atomic form factor can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeAtomicFormFactor )
{
  std::vector<double> form_factor( 4 );
  form_factor[0] = 1.0;
  form_factor[1] = 1.0;
  form_factor[2] = 0.3;
  form_factor[3] = 1e-30;

  epr_data_container.setWallerHartreeAtomicFormFactor( form_factor );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeAtomicFormFactor(),
                       form_factor );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree atomic form factor momentum grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeSquaredAtomicFormFactorSquaredMomentumGrid )
{
  std::vector<double> squared_momentum_grid( 4 );
  squared_momentum_grid[0] = 0.0;
  squared_momentum_grid[1] = 1.0;
  squared_momentum_grid[2] = 100.0;
  squared_momentum_grid[3] = 1e16;

  epr_data_container.setWallerHartreeSquaredAtomicFormFactorSquaredMomentumGrid(
                                                       squared_momentum_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeSquaredAtomicFormFactorSquaredMomentumGrid(),
                       squared_momentum_grid );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree atomic form factor can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeSquaredAtomicFormFactor )
{
  std::vector<double> squared_form_factor( 4 );
  squared_form_factor[0] = 1.0;
  squared_form_factor[1] = 1.0;
  squared_form_factor[2] = 0.09;
  squared_form_factor[3] = 0.0;

  epr_data_container.setWallerHartreeSquaredAtomicFormFactor( squared_form_factor );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeSquaredAtomicFormFactor(),
                       squared_form_factor );
}

//---------------------------------------------------------------------------//
// Check that the adjoint photon energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPhotonEnergyGrid )
{
  std::vector<double> adjoint_photon_energy_grid( 3 );
  adjoint_photon_energy_grid[0] = 1e-3;
  adjoint_photon_energy_grid[1] = 1.0;
  adjoint_photon_energy_grid[2] = 20.0;

  epr_data_container.setAdjointPhotonEnergyGrid( adjoint_photon_energy_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPhotonEnergyGrid(),
                       adjoint_photon_energy_grid );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent max energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointWallerHartreeIncoherentMaxEnergyGrid )
{
  std::vector<std::vector<double> > max_energy_grid( 3 );
  max_energy_grid[0].resize( 3 );
  max_energy_grid[0][0] = 1.5e-3;
  max_energy_grid[0][1] = 2.0;
  max_energy_grid[0][2] = 20.2;

  max_energy_grid[1].resize( 3 );
  max_energy_grid[1][0] = 1.01;
  max_energy_grid[1][1] = 5.0;
  max_energy_grid[1][2] = 20.2;

  max_energy_grid[2].resize( 2 );
  max_energy_grid[2][0] = 20.1;
  max_energy_grid[2][0] = 20.2;

  epr_data_container.setAdjointWallerHartreeIncoherentMaxEnergyGrid( max_energy_grid );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointWallerHartreeIncoherentMaxEnergyGrid().size(),
                       max_energy_grid.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeIncoherentMaxEnergyGrid()[0],
                       max_energy_grid[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeIncoherentMaxEnergyGrid()[1],
                       max_energy_grid[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeIncoherentMaxEnergyGrid()[2],
                       max_energy_grid[2] );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointWallerHartreeIncoherentCrossSection )
{
  std::vector<std::vector<double> > cross_section( 3 );
  cross_section[0].resize( 3 );
  cross_section[0][0] = 1e-6;
  cross_section[0][1] = 0.5;
  cross_section[0][2] = 2.5;

  cross_section[1].resize( 3 );
  cross_section[1][0] = 1e-6;
  cross_section[1][1] = 1.5;
  cross_section[1][2] = 5.0;

  cross_section[2].resize( 2 );
  cross_section[2][0] = 0.0;
  cross_section[2][0] = 1e-6;

  epr_data_container.setAdjointWallerHartreeIncoherentCrossSection( cross_section );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointWallerHartreeIncoherentCrossSection().size(),
                       cross_section.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeIncoherentCrossSection()[0],
                       cross_section[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeIncoherentCrossSection()[1],
                       cross_section[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeIncoherentCrossSection()[2],
                       cross_section[2] );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent max energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointImpulseApproxIncoherentMaxEnergyGrid )
{
  std::vector<std::vector<double> > max_energy_grid( 3 );
  max_energy_grid[0].resize( 3 );
  max_energy_grid[0][0] = 1.8e-3;
  max_energy_grid[0][1] = 2.0;
  max_energy_grid[0][2] = 20.2;

  max_energy_grid[1].resize( 3 );
  max_energy_grid[1][0] = 1.3;
  max_energy_grid[1][1] = 5.0;
  max_energy_grid[1][2] = 20.2;

  max_energy_grid[2].resize( 2 );
  max_energy_grid[2][0] = 20.1;
  max_energy_grid[2][0] = 20.2;

  epr_data_container.setAdjointImpulseApproxIncoherentMaxEnergyGrid( max_energy_grid );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointImpulseApproxIncoherentMaxEnergyGrid().size(),
                       max_energy_grid.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxIncoherentMaxEnergyGrid()[0],
                       max_energy_grid[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxIncoherentMaxEnergyGrid()[1],
                       max_energy_grid[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxIncoherentMaxEnergyGrid()[2],
                       max_energy_grid[2] );
}

//---------------------------------------------------------------------------//
// Check that the adjoint incoherent cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointImpulseApproxIncoherentCrossSection )
{
  std::vector<std::vector<double> > cross_section( 3 );
  cross_section[0].resize( 3 );
  cross_section[0][0] = 1e-5;
  cross_section[0][1] = 0.7;
  cross_section[0][2] = 2.5;

  cross_section[1].resize( 3 );
  cross_section[1][0] = 1e-4;
  cross_section[1][1] = 1.7;
  cross_section[1][2] = 5.0;

  cross_section[2].resize( 2 );
  cross_section[2][0] = 0.0;
  cross_section[2][0] = 1e-6;

  epr_data_container.setAdjointImpulseApproxIncoherentCrossSection( cross_section );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointImpulseApproxIncoherentCrossSection().size(),
                       cross_section.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxIncoherentCrossSection()[0],
                       cross_section[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxIncoherentCrossSection()[1],
                       cross_section[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxIncoherentCrossSection()[2],
                       cross_section[2] );
}

//---------------------------------------------------------------------------//
// Check that the subshell adjoint incoherent max energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid )
{
  std::vector<std::vector<double> > max_energy_grid( 3 );
  max_energy_grid[0].resize( 3 );
  max_energy_grid[0][0] = 1.5e-3;
  max_energy_grid[0][1] = 2.0;
  max_energy_grid[0][2] = 20.2;

  max_energy_grid[1].resize( 3 );
  max_energy_grid[1][0] = 1.01;
  max_energy_grid[1][1] = 5.0;
  max_energy_grid[1][2] = 20.2;

  max_energy_grid[2].resize( 2 );
  max_energy_grid[2][0] = 20.1;
  max_energy_grid[2][0] = 20.2;

  epr_data_container.setAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1, max_energy_grid );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 ).size(),
                       max_energy_grid.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 )[0],
                       max_energy_grid[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 )[1],
                       max_energy_grid[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 )[2],
                       max_energy_grid[2] );
}

//---------------------------------------------------------------------------//
// Check that the subshell adjoint incoherent cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointImpulseApproxSubshellIncoherentCrossSection )
{
  std::vector<std::vector<double> > cross_section( 3 );
  cross_section[0].resize( 3 );
  cross_section[0][0] = 1e-6;
  cross_section[0][1] = 0.5;
  cross_section[0][2] = 2.5;

  cross_section[1].resize( 3 );
  cross_section[1][0] = 1e-6;
  cross_section[1][1] = 1.5;
  cross_section[1][2] = 5.0;

  cross_section[2].resize( 2 );
  cross_section[2][0] = 0.0;
  cross_section[2][0] = 1e-6;

  epr_data_container.setAdjointImpulseApproxSubshellIncoherentCrossSection( 1, cross_section );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 ).size(),
                       cross_section.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 )[0],
                       cross_section[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 )[1],
                       cross_section[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 )[2],
                       cross_section[2] );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree coherent cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHartreeCoherentCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setAdjointWallerHartreeCoherentCrossSection( cross_section );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeCoherentCrossSection(),
                       cross_section );
}

//---------------------------------------------------------------------------//
// Check that the adjoint total max energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointWallerHartreeTotalMaxEnergyGrid )
{
  std::vector<std::vector<double> > max_energy_grid( 3 );
  max_energy_grid[0].resize( 3 );
  max_energy_grid[0][0] = 1.0e-3;
  max_energy_grid[0][1] = 2.0;
  max_energy_grid[0][2] = 20.2;

  max_energy_grid[1].resize( 3 );
  max_energy_grid[1][0] = 1.0;
  max_energy_grid[1][1] = 5.0;
  max_energy_grid[1][2] = 20.2;

  max_energy_grid[2].resize( 2 );
  max_energy_grid[2][0] = 20.0;
  max_energy_grid[2][0] = 20.2;

  epr_data_container.setAdjointWallerHartreeTotalMaxEnergyGrid( max_energy_grid );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointWallerHartreeTotalMaxEnergyGrid().size(),
                       max_energy_grid.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeTotalMaxEnergyGrid()[0],
                       max_energy_grid[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeTotalMaxEnergyGrid()[1],
                       max_energy_grid[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeTotalMaxEnergyGrid()[2],
                       max_energy_grid[2] );
}

//---------------------------------------------------------------------------//
// Check that the adjoint total cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointWallerHartreeTotalCrossSection )
{
  std::vector<std::vector<double> > cross_section( 3 );
  cross_section[0].resize( 3 );
  cross_section[0][0] = 0.0;
  cross_section[0][1] = 0.5;
  cross_section[0][2] = 2.5;

  cross_section[1].resize( 3 );
  cross_section[1][0] = 0.0;
  cross_section[1][1] = 1.5;
  cross_section[1][2] = 5.0;

  cross_section[2].resize( 2 );
  cross_section[2][0] = 0.0;
  cross_section[2][0] = 1e-6;

  epr_data_container.setAdjointWallerHartreeTotalCrossSection( cross_section );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointWallerHartreeTotalCrossSection().size(),
                       cross_section.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeTotalCrossSection()[0],
                       cross_section[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeTotalCrossSection()[1],
                       cross_section[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointWallerHartreeTotalCrossSection()[2],
                       cross_section[2] );
}

//---------------------------------------------------------------------------//
// Check that the adjoint total max energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointImpulseApproxTotalMaxEnergyGrid )
{
  std::vector<std::vector<double> > max_energy_grid( 3 );
  max_energy_grid[0].resize( 3 );
  max_energy_grid[0][0] = 1.0e-3;
  max_energy_grid[0][1] = 2.0;
  max_energy_grid[0][2] = 20.2;

  max_energy_grid[1].resize( 3 );
  max_energy_grid[1][0] = 1.0;
  max_energy_grid[1][1] = 5.0;
  max_energy_grid[1][2] = 20.2;

  max_energy_grid[2].resize( 2 );
  max_energy_grid[2][0] = 20.0;
  max_energy_grid[2][0] = 20.2;

  epr_data_container.setAdjointImpulseApproxTotalMaxEnergyGrid( max_energy_grid );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointImpulseApproxTotalMaxEnergyGrid().size(),
                       max_energy_grid.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxTotalMaxEnergyGrid()[0],
                       max_energy_grid[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxTotalMaxEnergyGrid()[1],
                       max_energy_grid[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxTotalMaxEnergyGrid()[2],
                       max_energy_grid[2] );
}

//---------------------------------------------------------------------------//
// Check that the adjoint total cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointImpulseApproxTotalCrossSection )
{
  std::vector<std::vector<double> > cross_section( 3 );
  cross_section[0].resize( 3 );
  cross_section[0][0] = 0.0;
  cross_section[0][1] = 0.5;
  cross_section[0][2] = 2.5;

  cross_section[1].resize( 3 );
  cross_section[1][0] = 0.0;
  cross_section[1][1] = 1.5;
  cross_section[1][2] = 5.0;

  cross_section[2].resize( 2 );
  cross_section[2][0] = 0.0;
  cross_section[2][0] = 1e-6;

  epr_data_container.setAdjointImpulseApproxTotalCrossSection( cross_section );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointImpulseApproxTotalCrossSection().size(),
                       cross_section.size() );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxTotalCrossSection()[0],
                       cross_section[0] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxTotalCrossSection()[1],
                       cross_section[1] );
  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointImpulseApproxTotalCrossSection()[2],
                       cross_section[2] );
}

//---------------------------------------------------------------------------//
// Check that the Waller-Hartree total cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setWallerHatreeTotalCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setWallerHartreeTotalCrossSection( cross_section );

  TEST_COMPARE_ARRAYS( epr_data_container.getWallerHartreeTotalCrossSection(),
                       cross_section );
}

//---------------------------------------------------------------------------//
// Check that the impulse approx. total cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setImpulseApproxTotalCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setImpulseApproxTotalCrossSection( cross_section );

  TEST_COMPARE_ARRAYS( epr_data_container.getImpulseApproxTotalCrossSection(),
                       cross_section );
}

//---------------------------------------------------------------------------//
// Check that the adjoint pair production energy distribution grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPairProductionEnergyDistributionGrid )
{
  std::vector<double> energy_dist_grid( 3 );
  energy_dist_grid[0] = 1.02199782026;
  energy_dist_grid[1] = 5.0;
  energy_dist_grid[2] = 20.2;

  epr_data_container.setAdjointPairProductionEnergyDistributionGrid( energy_dist_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPairProductionEnergyDistributionGrid(),
                       energy_dist_grid );
}

//---------------------------------------------------------------------------//
// Check that the adjoint pair production energy distribution can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPairProductionEnergyDistribution )
{
  std::vector<double> energy_dist( 3 );
  energy_dist[0] = 0.0;
  energy_dist[1] = 0.1;
  energy_dist[2] = 10.0;

  epr_data_container.setAdjointPairProductionEnergyDistribution( energy_dist );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPairProductionEnergyDistribution(),
                       energy_dist );
}

//---------------------------------------------------------------------------//
// Check that the adjoint pair production energy dist norm const grid can be
// set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPairProductionEnergyDistributionNormConstantGrid )
{
  std::vector<double> norm_const_grid( 3 );
  norm_const_grid[0] = 1.02199782026;
  norm_const_grid[1] = 5.0;
  norm_const_grid[2] = 20.2;

  epr_data_container.setAdjointPairProductionEnergyDistributionNormConstantGrid( norm_const_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPairProductionEnergyDistributionNormConstantGrid(),
                       norm_const_grid );
}

//---------------------------------------------------------------------------//
// Check that the adjoint pair production energy dist norm constant can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPairProductionEnergyDistributionNormConstant )
{
  std::vector<double> norm_const( 3 );
  norm_const[0] = 0.0;
  norm_const[1] = 10.0;
  norm_const[2] = 50.0;

  epr_data_container.setAdjointPairProductionEnergyDistributionNormConstant( norm_const );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPairProductionEnergyDistributionNormConstant(),
                       norm_const );
}

//---------------------------------------------------------------------------//
// Check that the adjoint triplet production energy distribution grid can be
// set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTripletProductionEnergyDistributionGrid )
{
  std::vector<double> energy_dist_grid( 3 );
  energy_dist_grid[0] = 2.04399564052;
  energy_dist_grid[1] = 5.0;
  energy_dist_grid[2] = 20.2;

  epr_data_container.setAdjointTripletProductionEnergyDistributionGrid( energy_dist_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointTripletProductionEnergyDistributionGrid(),
                       energy_dist_grid );
}

//---------------------------------------------------------------------------//
// Check that the adjoint triplet production energy distribution can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTripletProductionEnergyDistribution )
{
  std::vector<double> energy_dist( 3 );
  energy_dist[0] = 0.0;
  energy_dist[1] = 5.0;
  energy_dist[2] = 0.1;

  epr_data_container.setAdjointTripletProductionEnergyDistribution( energy_dist );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointTripletProductionEnergyDistribution(),
                       energy_dist );
}

//---------------------------------------------------------------------------//
// Check that the adjoint triplet production energy dist norm const grid can be
// set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTripletProductionEnergyDistributionNormConstantGrid )
{
  std::vector<double> norm_const_grid( 3 );
  norm_const_grid[0] = 2.04399564052;
  norm_const_grid[1] = 5.0;
  norm_const_grid[2] = 20.2;

  epr_data_container.setAdjointTripletProductionEnergyDistributionNormConstantGrid( norm_const_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointTripletProductionEnergyDistributionNormConstantGrid(),
                       norm_const_grid );
}

//---------------------------------------------------------------------------//
// Check that the adjoint triplet production energy dist norm constant can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTripletProductionEnergyDistributionNormConstant )
{
  std::vector<double> norm_const( 3 );
  norm_const[0] = 0.0;
  norm_const[1] = 10.0;
  norm_const[2] = 11.0;

  epr_data_container.setAdjointTripletProductionEnergyDistributionNormConstant( norm_const );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointTripletProductionEnergyDistributionNormConstant(),
                       norm_const );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPhotonBremsstrahlungEnergyGrid )
{
  std::vector<double> energy_grid(2), grid(2);
  energy_grid[0] = 1.0;
  energy_grid[1] = 2.0;

  epr_data_container.setAdjointPhotonBremsstrahlungEnergyGrid( energy_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPhotonBremsstrahlungEnergyGrid(),
                       energy_grid );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPhotonBremsstrahlungEnergyAtIncomingEnergy )
{
  std::vector<double> photon_energy( 3 );
  photon_energy[0] = 0.01;
  photon_energy[1] = 0.001;
  photon_energy[2] = 0.0001;

  epr_data_container.setAdjointPhotonBremsstrahlungEnergyAtIncomingEnergy( 1.0,
                                                                   photon_energy );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPhotonBremsstrahlungEnergy(1.0),
                       photon_energy );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPhotonBremsstrahlungPDFAtIncomingEnergy )
{
  std::vector<double> photon_pdf( 3 );
  photon_pdf[0] = 1.0;
  photon_pdf[1] = 2.0;
  photon_pdf[2] = 5.0;

  epr_data_container.setAdjointPhotonBremsstrahlungPDFAtIncomingEnergy( 1.0,
                                                                photon_pdf );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPhotonBremsstrahlungPDF(1.0),
                       photon_pdf );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPhotonBremsstrahlungEnergy )
{
  std::vector<double> energy( 3 );
  energy[0] = 0.01;
  energy[1] = 0.001;
  energy[2] = 0.0001;

  double energy_bin = 1.0;

  std::map<double,std::vector<double> > photon_energy;

  photon_energy[energy_bin] = energy;

  epr_data_container.setAdjointPhotonBremsstrahlungEnergy( photon_energy );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPhotonBremsstrahlungEnergy(energy_bin),
                       energy );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointPhotonBremsstrahlungPDF )
{
  std::vector<double> pdf( 3 );
  pdf[0] = 1.0;
  pdf[1] = 2.0;
  pdf[2] = 5.0;

  double energy_bin = 1.0;

  std::map<double,std::vector<double> > photon_pdf;

  photon_pdf[energy_bin] = pdf;

  epr_data_container.setAdjointPhotonBremsstrahlungPDF( photon_pdf );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointPhotonBremsstrahlungPDF(energy_bin),
                       pdf );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungPhotonCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setAdjointBremsstrahlungPhotonCrossSection( cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointBremsstrahlungPhotonCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungPhotonCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setAdjointBremsstrahlungPhotonCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointBremsstrahlungPhotonCrossSectionThresholdEnergyIndex(),
                       0 );
}


//---------------------------------------------------------------------------//
// Electron Tests
//---------------------------------------------------------------------------//
// Check that the electron TwoDInterpPolicy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setElectronTwoDInterpPolicy )
{
  std::string interp = "Lin-Lin-Lin";
  epr_data_container.setElectronTwoDInterpPolicy( interp );

  TEST_EQUALITY_CONST( interp,
                       epr_data_container.getElectronTwoDInterpPolicy() );
}

//---------------------------------------------------------------------------//
// Check that the electron TwoDGridPolicy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setElectronTwoDGridPolicy )
{
  std::string grid = "Direct";
  epr_data_container.setElectronTwoDGridPolicy( grid );

  TEST_EQUALITY_CONST( grid,
                       epr_data_container.getElectronTwoDGridPolicy() );
}

//---------------------------------------------------------------------------//
// Check that the angular energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElasticAngularEnergyGrid )
{
  std::vector<double> angular_energy_grid(1), grid(1);
  angular_energy_grid[0] = 1.0;

  epr_data_container.setAdjointElasticAngularEnergyGrid(
                                    angular_energy_grid );

  grid = epr_data_container.getAdjointElasticAngularEnergyGrid();
  TEST_EQUALITY_CONST( grid[0], angular_energy_grid[0] );
}

//---------------------------------------------------------------------------//
// Check that the elastic angles can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointCutoffElasticAnglesAtEnergy )
{
  std::vector<double> angles( 3 );
  angles[0] = -1.0;
  angles[1] = 0.0;
  angles[2] = 0.90;

  epr_data_container.setAdjointCutoffElasticAnglesAtEnergy( 1.0, angles );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointCutoffElasticAngles(1.0),
                       angles );
}

//---------------------------------------------------------------------------//
// Check that the elastic pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointCutoffElasticPDFAtEnergy )
{
  std::vector<double> pdf( 3 );
  pdf[0] = 0.1;
  pdf[1] = 0.2;
  pdf[2] = 0.7;

  epr_data_container.setAdjointCutoffElasticPDFAtEnergy( 1.0, pdf );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointCutoffElasticPDF(1.0),
                       pdf );
}

//---------------------------------------------------------------------------//
// Check that the elastic angles can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointCutoffElasticAngles )
{
  std::vector<double> angles( 3 );
  angles[0] = -1.0;
  angles[1] = 0.0;
  angles[2] = 0.90;

  double energy = 1.0;
  std::map<double, std::vector<double> > angles_map, map;

  angles_map[energy] = angles;

  epr_data_container.setAdjointCutoffElasticAngles( angles_map );

  map = epr_data_container.getAdjointCutoffElasticAngles();

  TEST_COMPARE_ARRAYS( map.find(1.0)->second,
                       angles );
}

//---------------------------------------------------------------------------//
// Check that the elastic pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointCutoffElasticPDF )
{
  std::vector<double> pdf( 3 );
  pdf[0] = 0.1;
  pdf[1] = 0.2;
  pdf[2] = 0.7;

  double energy = 1.0;
  std::map<double, std::vector<double> > pdf_map, map;

  pdf_map[energy] = pdf;

  epr_data_container.setAdjointCutoffElasticPDF( pdf_map );

  map = epr_data_container.getAdjointCutoffElasticPDF();

  TEST_COMPARE_ARRAYS( map.find(1.0)->second,
                       pdf );
}

//---------------------------------------------------------------------------//
// Check that the moment preserving elastic discrete angles can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointMomentPreservingCrossSectionReduction )
{
  TEST_ASSERT( !epr_data_container.hasAdjointMomentPreservingData() );

  std::vector<double> reductions( 1 );
  reductions[0] = 0.90;

  epr_data_container.setAdjointMomentPreservingCrossSectionReduction( reductions );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointMomentPreservingCrossSectionReduction(),
                       reductions );
}

//---------------------------------------------------------------------------//
// Check that the moment preserving elastic discrete angles can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointMomentPreservingElasticDiscreteAngles )
{
  TEST_ASSERT( !epr_data_container.hasAdjointMomentPreservingData() );

  std::vector<double> discrete_angles( 3 );
  discrete_angles[0] = 0.90;
  discrete_angles[1] = 0.95;
  discrete_angles[2] = 0.99;

  epr_data_container.setAdjointMomentPreservingElasticDiscreteAnglesAtEnergy( 1.0,
                                                            discrete_angles );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointMomentPreservingElasticDiscreteAngles(1.0),
                       discrete_angles );

  TEST_ASSERT( epr_data_container.hasAdjointMomentPreservingData() );
}

//---------------------------------------------------------------------------//
// Check that the moment preserving elastic weights can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointMomentPreservingElasticWeights )
{
  std::vector<double> weights( 3 );
  weights[0] = 0.1;
  weights[1] = 0.2;
  weights[2] = 0.7;

  epr_data_container.setAdjointMomentPreservingElasticWeightsAtEnergy( 1.0, weights );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointMomentPreservingElasticWeights(1.0),
                       weights );
}

//---------------------------------------------------------------------------//
// Check if there is a seperate electroionization incoming electron energy grid for the scattering spectrum
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   seperateAdjointElectroionizationEnergyGrid )
{
  TEST_ASSERT( !epr_data_container.seperateAdjointElectroionizationEnergyGrid() );
}

//---------------------------------------------------------------------------//
// Check that the electroionization energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationEnergyGrid )
{
  std::vector<double> energy_grid(2), grid(2);
  energy_grid[0] = 1.0;
  energy_grid[1] = 2.0;

  unsigned subshell = 1;

  epr_data_container.setAdjointElectroionizationEnergyGrid(
                                subshell,
                                energy_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectroionizationEnergyGrid( subshell ),
                       energy_grid );
  TEST_ASSERT( epr_data_container.seperateAdjointElectroionizationEnergyGrid() );
}

//---------------------------------------------------------------------------//
// Check that the electroionization recoil energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationRecoilEnergyAtIncomingEnergy )
{
  std::vector<double> recoil_energy( 3 );
  recoil_energy[0] = 0.01;
  recoil_energy[1] = 0.001;
  recoil_energy[2] = 0.0001;

  unsigned subshell = 1;
  double energy = 1.0;

  epr_data_container.setAdjointElectroionizationRecoilEnergyAtIncomingEnergy(
                                subshell,
                                energy,
                                recoil_energy );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectroionizationRecoilEnergy(subshell, energy),
                       recoil_energy );
}

//---------------------------------------------------------------------------//
// Check that the electroionization recoil pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationRecoilPDFAtIncomingEnergy )
{
  std::vector<double> recoil_pdf( 3 );
  recoil_pdf[0] = 1.0;
  recoil_pdf[1] = 2.0;
  recoil_pdf[2] = 5.0;

  unsigned subshell = 1;
  double energy = 1.0;

  epr_data_container.setAdjointElectroionizationRecoilPDFAtIncomingEnergy(
                                subshell,
                                energy,
                                recoil_pdf );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectroionizationRecoilPDF( subshell, energy ),
                       recoil_pdf );
}

//---------------------------------------------------------------------------//
// Check that the electroionization recoil energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationRecoilEnergy )
{
  std::vector<double> energy( 3 );
  energy[0] = 0.01;
  energy[1] = 0.001;
  energy[2] = 0.0001;

  unsigned subshell = 1;
  double energy_bin = 1.0;

  std::map<double,std::vector<double> > recoil_energy;

  recoil_energy[energy_bin] = energy;

  epr_data_container.setAdjointElectroionizationRecoilEnergy(
                                subshell,
                                recoil_energy );

  TEST_COMPARE_ARRAYS(
    epr_data_container.getAdjointElectroionizationRecoilEnergy(subshell, energy_bin),
    energy );
}

//---------------------------------------------------------------------------//
// Check that the electroionization recoil pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationRecoilPDF )
{
  std::vector<double> pdf( 3 );
  pdf[0] = 1.0;
  pdf[1] = 2.0;
  pdf[2] = 5.0;

  unsigned subshell = 1;
  double energy_bin = 1.0;

  std::map<double,std::vector<double> > recoil_pdf;

  recoil_pdf[energy_bin] = pdf;

  epr_data_container.setAdjointElectroionizationRecoilPDF(
                                subshell,
                                recoil_pdf );

  TEST_COMPARE_ARRAYS(
    epr_data_container.getAdjointElectroionizationRecoilPDF( subshell, energy_bin ),
    pdf );
}

//---------------------------------------------------------------------------//
// Check if there is a seperate bremsstrahlung incoming electron energy grid for the scattering spectrum
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   seperateAdjointBremsstrahlungEnergyGrid )
{
  TEST_ASSERT( !epr_data_container.seperateAdjointBremsstrahlungEnergyGrid() );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronBremsstrahlungEnergyGrid )
{
  std::vector<double> energy_grid(2), grid(2);
  energy_grid[0] = 1.0;
  energy_grid[1] = 2.0;

  epr_data_container.setAdjointElectronBremsstrahlungEnergyGrid( energy_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectronBremsstrahlungEnergyGrid(),
                       energy_grid );
  TEST_ASSERT( epr_data_container.seperateAdjointBremsstrahlungEnergyGrid() );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronBremsstrahlungEnergyAtIncomingEnergy )
{
  std::vector<double> photon_energy( 3 );
  photon_energy[0] = 0.01;
  photon_energy[1] = 0.001;
  photon_energy[2] = 0.0001;

  epr_data_container.setAdjointElectronBremsstrahlungEnergyAtIncomingEnergy( 1.0,
                                                                   photon_energy );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectronBremsstrahlungEnergy(1.0),
                       photon_energy );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronBremsstrahlungPDFAtIncomingEnergy )
{
  std::vector<double> photon_pdf( 3 );
  photon_pdf[0] = 1.0;
  photon_pdf[1] = 2.0;
  photon_pdf[2] = 5.0;

  epr_data_container.setAdjointElectronBremsstrahlungPDFAtIncomingEnergy( 1.0,
                                                                photon_pdf );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectronBremsstrahlungPDF(1.0),
                       photon_pdf );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon energy can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronBremsstrahlungEnergy )
{
  std::vector<double> energy( 3 );
  energy[0] = 0.01;
  energy[1] = 0.001;
  energy[2] = 0.0001;

  double energy_bin = 1.0;

  std::map<double,std::vector<double> > photon_energy;

  photon_energy[energy_bin] = energy;

  epr_data_container.setAdjointElectronBremsstrahlungEnergy( photon_energy );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectronBremsstrahlungEnergy(energy_bin),
                       energy );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung photon pdf can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronBremsstrahlungPDF )
{
  std::vector<double> pdf( 3 );
  pdf[0] = 1.0;
  pdf[1] = 2.0;
  pdf[2] = 5.0;

  double energy_bin = 1.0;

  std::map<double,std::vector<double> > photon_pdf;

  photon_pdf[energy_bin] = pdf;

  epr_data_container.setAdjointElectronBremsstrahlungPDF( photon_pdf );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectronBremsstrahlungPDF(energy_bin),
                       pdf );
}

//---------------------------------------------------------------------------//
// Check that the atomic excitation energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointAtomicExcitationEnergyGrid )
{
  std::vector<double> energy_grid(3);
  energy_grid[0] = 1.0;
  energy_grid[1] = 5.0;
  energy_grid[2] = 10.0;

  epr_data_container.setAdjointAtomicExcitationEnergyGrid(
                                    energy_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointAtomicExcitationEnergyGrid(),
                       energy_grid );
}

//---------------------------------------------------------------------------//
// Check that the atomic excitation energy gain can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointAtomicExcitationEnergyGain )
{
  std::vector<double> energy_gain(3);
  energy_gain[0] = 1.0;
  energy_gain[1] = 5.0;
  energy_gain[2] = 10.0;

  epr_data_container.setAdjointAtomicExcitationEnergyGain(
                                    energy_gain );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointAtomicExcitationEnergyGain(),
                       energy_gain );
}

//---------------------------------------------------------------------------//
// Check that the electron energy grid can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectronEnergyGrid )
{
  std::vector<double> electron_energy_grid( 3 );
  electron_energy_grid[0] = 1e-3;
  electron_energy_grid[1] = 1.0;
  electron_energy_grid[2] = 20.0;

  epr_data_container.setAdjointElectronEnergyGrid( electron_energy_grid );

  TEST_COMPARE_ARRAYS( epr_data_container.getAdjointElectronEnergyGrid(),
                       electron_energy_grid );
}

//---------------------------------------------------------------------------//
// Check that the cutoff elastic electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointCutoffElasticCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 0.5e-6;
  cross_section[1] = 0.5e-1;
  cross_section[2] = 0.5;

  epr_data_container.setAdjointCutoffElasticCrossSection(
                        cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointCutoffElasticCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the elastic cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointCutoffElasticCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setAdjointCutoffElasticCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointCutoffElasticCrossSectionThresholdEnergyIndex(),
                       0 );
}

//---------------------------------------------------------------------------//
// Check that the screened rutherford elastic electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointScreenedRutherfordElasticCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 0.6e-6;
  cross_section[1] = 0.6e-1;
  cross_section[2] = 0.6;

  epr_data_container.setAdjointScreenedRutherfordElasticCrossSection(
                        cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointScreenedRutherfordElasticCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the elastic cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST(
    epr_data_container.getAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex(),
    0 );
}

//---------------------------------------------------------------------------//
// Check that the total elastic electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTotalElasticCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setAdjointTotalElasticCrossSection(
                        cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointTotalElasticCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the elastic cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointTotalElasticCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setAdjointTotalElasticCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointTotalElasticCrossSectionThresholdEnergyIndex(),
                       0 );
}

//---------------------------------------------------------------------------//
// Check that the reduced cutoff cross section ratios can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setReducedCutoffCrossSectionRatios )
{
  std::vector<double> ratios( 3 );
  ratios[0] = 0.1;
  ratios[1] = 0.2;
  ratios[2] = 0.7;

  epr_data_container.setReducedCutoffCrossSectionRatios( ratios );

  TEST_COMPARE_ARRAYS( epr_data_container.getReducedCutoffCrossSectionRatios(),
                       ratios );
}

//---------------------------------------------------------------------------//
// Check that the electroionization electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  unsigned subshell = 1;

  epr_data_container.setAdjointElectroionizationCrossSection(
                        subshell,
                        cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointElectroionizationCrossSection( subshell ),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the electroionization cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointElectroionizationCrossSectionThresholdEnergyIndex )
{
  unsigned subshell = 1;

  epr_data_container.setAdjointElectroionizationCrossSectionThresholdEnergyIndex( subshell, 0 );

  TEST_EQUALITY_CONST(
    epr_data_container.getAdjointElectroionizationCrossSectionThresholdEnergyIndex( subshell ),
    0 );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungElectronCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setAdjointBremsstrahlungElectronCrossSection(
                        cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointBremsstrahlungElectronCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the bremsstrahlung cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointBremsstrahlungElectronCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setAdjointBremsstrahlungElectronCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointBremsstrahlungElectronCrossSectionThresholdEnergyIndex(),
                       0 );
}

//---------------------------------------------------------------------------//
// Check that the atomic excitation electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointAtomicExcitationCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setAdjointAtomicExcitationCrossSection(
                        cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getAdjointAtomicExcitationCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the atomic excitation cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setAdjointAtomicExcitationCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setAdjointAtomicExcitationCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST( epr_data_container.getAdjointAtomicExcitationCrossSectionThresholdEnergyIndex(),
                       0 );
}

//---------------------------------------------------------------------------//
// Check that the atomic excitation electron cross section can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setForwardInelasticElectronCrossSection )
{
  std::vector<double> cross_section( 3 );
  cross_section[0] = 1e-6;
  cross_section[1] = 1e-1;
  cross_section[2] = 1.0;

  epr_data_container.setForwardInelasticElectronCrossSection(  cross_section );

  TEST_COMPARE_ARRAYS(
            epr_data_container.getForwardInelasticElectronCrossSection(),
            cross_section );
}

//---------------------------------------------------------------------------//
// Check that the atomic excitation cs threshold index can be set
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   setForwardInelasticElectronCrossSectionThresholdEnergyIndex )
{
  epr_data_container.setForwardInelasticElectronCrossSectionThresholdEnergyIndex( 0 );

  TEST_EQUALITY_CONST(
    epr_data_container.getForwardInelasticElectronCrossSectionThresholdEnergyIndex(),
    0 );
}

//---------------------------------------------------------------------------//
// Check that the data can be exported and imported
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   export_importData_ascii )
{
  const std::string test_ascii_file_name( "test_epr_data_container.txt" );

  epr_data_container.exportData( test_ascii_file_name,
                                 Utility::ArchivableObject::ASCII_ARCHIVE );

  const Data::AdjointElectronPhotonRelaxationDataContainer
    epr_data_container_copy( test_ascii_file_name,
                             Utility::ArchivableObject::ASCII_ARCHIVE );

  // Table Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getAtomicNumber(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMinPhotonEnergy(), 0.001 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMaxPhotonEnergy(), 20.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMinElectronEnergy(), 1.0e-5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMaxElectronEnergy(), 1.0e5 );

  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistNormConstantEvaluationTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistNormConstantNudgeValue(), 1e-6 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistNormConstantEvaluationTolerance(), 1e-4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistNormConstantNudgeValue(), 1e-5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentMaxEnergyNudgeValue(), 0.2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentEnergyToMaxEnergyNudgeValue(), 1e-6 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentEvaluationTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridConvergenceTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridAbsoluteDifferenceTolerance(), 1e-20 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridDistanceTolerance(), 1e-15 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getCutoffAngleCosine(), 0.9 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getNumberOfAdjointMomentPreservingAngles(), 1 );

  TEST_EQUALITY_CONST( epr_data_container_copy.getGridConvergenceTolerance(), 0.001 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridAbsoluteDifferenceTolerance(), 1e-42 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridDistanceTolerance(), 1e-15 );

  // Relaxation Tests
  TEST_ASSERT( epr_data_container_copy.getSubshells().count( 1 ) );
  TEST_ASSERT( !epr_data_container_copy.getSubshells().count( 0 ) );
  TEST_ASSERT( !epr_data_container_copy.getSubshells().count( 2 ) );
  TEST_EQUALITY_CONST( epr_data_container_copy.getSubshellOccupancy( 1 ), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getSubshellBindingEnergy( 1 ),
                       1.361e-5 );

  // Photon Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getComptonProfileMomentumGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getComptonProfile( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getOccupationNumberMomentumGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getOccupationNumber( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeScatteringFunctionMomentumGrid().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeScatteringFunction().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeAtomicFormFactorMomentumGrid().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeAtomicFormFactor().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeSquaredAtomicFormFactorSquaredMomentumGrid().size(),
                       4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeSquaredAtomicFormFactor().size(),
                       4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeIncoherentMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeIncoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxIncoherentMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxIncoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeCoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeTotalMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxTotalMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getImpulseApproxTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistribution().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionNormConstantGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionNormConstant().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistribution().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionNormConstantGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionNormConstant().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().size(), 2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergy(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungPDF(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungPhotonCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungPhotonCrossSectionThresholdEnergyIndex(), 0 );

  // Electron Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getElectronTwoDInterpPolicy(), "Lin-Lin-Lin" );
  TEST_EQUALITY_CONST( epr_data_container_copy.getCutoffAngleCosine(), 0.9 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElasticAngularEnergyGrid().size(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElasticAngularEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticAngles(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticPDF(1.0).size(), 3 );
  TEST_ASSERT( epr_data_container_copy.hasAdjointMomentPreservingData() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingCrossSectionReduction().size(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingElasticDiscreteAngles(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingElasticWeights(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getReducedCutoffCrossSectionRatios().size(), 3 );
  TEST_ASSERT( epr_data_container.seperateAdjointElectroionizationEnergyGrid() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).size(), 2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationRecoilEnergy(1u, 1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationRecoilPDF(1u, 1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().size(), 2 );
  TEST_ASSERT( epr_data_container.seperateAdjointBremsstrahlungEnergyGrid() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergy(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungPDF(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationEnergyGain().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointScreenedRutherfordElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTotalElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTotalElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationCrossSection(1u).size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationCrossSectionThresholdEnergyIndex(1u), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungElectronCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungElectronCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationCrossSection().size(), 3u );
  TEST_EQUALITY_CONST(
    epr_data_container_copy.getAdjointAtomicExcitationCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST(
    epr_data_container_copy.getForwardInelasticElectronCrossSection().size(), 3u );
  TEST_EQUALITY_CONST(
    epr_data_container_copy.getForwardInelasticElectronCrossSectionThresholdEnergyIndex(), 0 );
}

//---------------------------------------------------------------------------//
// Check that the data can be exported and imported
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   export_importData_xml )
{
  const std::string test_xml_file_name( "test_epr_data_container.xml" );

  epr_data_container.exportData( test_xml_file_name,
                                 Utility::ArchivableObject::XML_ARCHIVE );

  const Data::AdjointElectronPhotonRelaxationDataContainer
    epr_data_container_copy( test_xml_file_name,
                             Utility::ArchivableObject::XML_ARCHIVE );

  // Table Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getAtomicNumber(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMinPhotonEnergy(), 0.001 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMaxPhotonEnergy(), 20.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMinElectronEnergy(), 1.0e-5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMaxElectronEnergy(), 1.0e5 );

  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistNormConstantEvaluationTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistNormConstantNudgeValue(), 1e-6 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistNormConstantEvaluationTolerance(), 1e-4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistNormConstantNudgeValue(), 1e-5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentMaxEnergyNudgeValue(), 0.2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentEnergyToMaxEnergyNudgeValue(), 1e-6 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentEvaluationTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridConvergenceTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridAbsoluteDifferenceTolerance(), 1e-20 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridDistanceTolerance(), 1e-15 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getCutoffAngleCosine(), 0.9 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getNumberOfAdjointMomentPreservingAngles(), 1 );

  TEST_EQUALITY_CONST( epr_data_container_copy.getGridConvergenceTolerance(), 0.001 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridAbsoluteDifferenceTolerance(), 1e-42 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridDistanceTolerance(), 1e-15 );

  // Relaxation Tests
  TEST_ASSERT( epr_data_container_copy.getSubshells().count( 1 ) );
  TEST_ASSERT( !epr_data_container_copy.getSubshells().count( 0 ) );
  TEST_ASSERT( !epr_data_container_copy.getSubshells().count( 2 ) );
  TEST_EQUALITY_CONST( epr_data_container_copy.getSubshellOccupancy( 1 ), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getSubshellBindingEnergy( 1 ), 1.361e-5 );

  // Photon Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getComptonProfileMomentumGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getComptonProfile( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getOccupationNumberMomentumGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getOccupationNumber( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeScatteringFunctionMomentumGrid().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeScatteringFunction().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeAtomicFormFactorMomentumGrid().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeAtomicFormFactor().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeSquaredAtomicFormFactorSquaredMomentumGrid().size(),
                       4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeSquaredAtomicFormFactor().size(),
                       4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeIncoherentMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeIncoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxIncoherentMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxIncoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeCoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeTotalMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxTotalMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getImpulseApproxTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeCoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistribution().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionNormConstantGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionNormConstant().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistribution().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionNormConstantGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionNormConstant().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().size(), 2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergy(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungPDF(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungPhotonCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungPhotonCrossSectionThresholdEnergyIndex(), 0 );

  // Electron Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getElectronTwoDInterpPolicy(), "Lin-Lin-Lin" );
  TEST_EQUALITY_CONST( epr_data_container_copy.getCutoffAngleCosine(), 0.9 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElasticAngularEnergyGrid().size(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElasticAngularEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticAngles(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticPDF(1.0).size(), 3 );
  TEST_ASSERT( epr_data_container_copy.hasAdjointMomentPreservingData() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingCrossSectionReduction().size(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingElasticDiscreteAngles(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingElasticWeights(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getReducedCutoffCrossSectionRatios().size(), 3 );
  TEST_ASSERT( epr_data_container.seperateAdjointElectroionizationEnergyGrid() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).size(), 2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationRecoilEnergy(1u, 1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationRecoilPDF(1u, 1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().size(), 2 );
  TEST_ASSERT( epr_data_container.seperateAdjointBremsstrahlungEnergyGrid() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergy(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungPDF(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationEnergyGain().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointScreenedRutherfordElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTotalElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTotalElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationCrossSection(1u).size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationCrossSectionThresholdEnergyIndex(1u), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungElectronCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungElectronCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getForwardInelasticElectronCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getForwardInelasticElectronCrossSectionThresholdEnergyIndex(), 0 );
}

//---------------------------------------------------------------------------//
// Check that the data can be packed into a string and unpacked from a string
TEUCHOS_UNIT_TEST( AdjointElectronPhotonRelaxationDataContainer,
                   pack_unpackDataFromString )
{
  std::string packed_data = epr_data_container.packDataInString();

  Data::AdjointElectronPhotonRelaxationVolatileDataContainer epr_data_container_copy;

  epr_data_container_copy.unpackDataFromString( packed_data );

  // Table Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getAtomicNumber(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMinPhotonEnergy(), 0.001 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMaxPhotonEnergy(), 20.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMinElectronEnergy(), 1.0e-5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getMaxElectronEnergy(), 1.0e5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistNormConstantEvaluationTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistNormConstantNudgeValue(), 1e-6 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistNormConstantEvaluationTolerance(), 1e-4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistNormConstantNudgeValue(), 1e-5 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentMaxEnergyNudgeValue(), 0.2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentEnergyToMaxEnergyNudgeValue(), 1e-6 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentEvaluationTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridConvergenceTolerance(), 1e-3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridAbsoluteDifferenceTolerance(), 1e-20 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointIncoherentGridDistanceTolerance(), 1e-15 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getCutoffAngleCosine(), 0.9 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getNumberOfAdjointMomentPreservingAngles(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridConvergenceTolerance(), 0.001 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridAbsoluteDifferenceTolerance(), 1e-42 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getGridDistanceTolerance(), 1e-15 );

  // Relaxation Tests
  TEST_ASSERT( epr_data_container_copy.getSubshells().count( 1 ) );
  TEST_ASSERT( !epr_data_container_copy.getSubshells().count( 0 ) );
  TEST_ASSERT( !epr_data_container_copy.getSubshells().count( 2 ) );
  TEST_EQUALITY_CONST( epr_data_container_copy.getSubshellOccupancy( 1 ), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getSubshellBindingEnergy( 1 ), 1.361e-5 );

  // Photon Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getComptonProfileMomentumGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getComptonProfile( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getOccupationNumberMomentumGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getOccupationNumber( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeScatteringFunctionMomentumGrid().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeScatteringFunction().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeAtomicFormFactorMomentumGrid().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeAtomicFormFactor().size(), 4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeSquaredAtomicFormFactorSquaredMomentumGrid().size(),
                       4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeSquaredAtomicFormFactor().size(),
                       4 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeIncoherentMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeIncoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxSubshellIncoherentCrossSection( 1 ).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxIncoherentMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxIncoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeCoherentCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeTotalMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointWallerHartreeTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxTotalMaxEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointImpulseApproxTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getWallerHartreeTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getImpulseApproxTotalCrossSection().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistribution().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionNormConstantGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPairProductionEnergyDistributionNormConstant().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistribution().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionNormConstantGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTripletProductionEnergyDistributionNormConstant().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().size(), 2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergyGrid().back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungEnergy(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointPhotonBremsstrahlungPDF(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungPhotonCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungPhotonCrossSectionThresholdEnergyIndex(), 0 );

  // Electron Tests
  TEST_EQUALITY_CONST( epr_data_container_copy.getElectronTwoDInterpPolicy(), "Lin-Lin-Lin" );
  TEST_EQUALITY_CONST( epr_data_container_copy.getCutoffAngleCosine(), 0.9 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElasticAngularEnergyGrid().size(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElasticAngularEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticAngles(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticPDF(1.0).size(), 3 );
  TEST_ASSERT( epr_data_container_copy.hasAdjointMomentPreservingData() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingCrossSectionReduction().size(), 1 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingElasticDiscreteAngles(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointMomentPreservingElasticWeights(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getReducedCutoffCrossSectionRatios().size(), 3 );
  TEST_ASSERT( epr_data_container.seperateAdjointElectroionizationEnergyGrid() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).size(), 2 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationEnergyGrid(1u).back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationRecoilEnergy(1u, 1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationRecoilPDF(1u, 1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().size(), 2 );
  TEST_ASSERT( epr_data_container.seperateAdjointBremsstrahlungEnergyGrid() );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().front(), 1.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergyGrid().back(), 2.0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungEnergy(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronBremsstrahlungPDF(1.0).size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationEnergyGain().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectronEnergyGrid().size(), 3 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointCutoffElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointScreenedRutherfordElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTotalElasticCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointTotalElasticCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationCrossSection(1u).size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointElectroionizationCrossSectionThresholdEnergyIndex(1u), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungElectronCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointBremsstrahlungElectronCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getAdjointAtomicExcitationCrossSectionThresholdEnergyIndex(), 0 );
  TEST_EQUALITY_CONST( epr_data_container_copy.getForwardInelasticElectronCrossSection().size(), 3u );
  TEST_EQUALITY_CONST( epr_data_container_copy.getForwardInelasticElectronCrossSectionThresholdEnergyIndex(), 0 );
}

//---------------------------------------------------------------------------//
// end tstAdjointElectronPhotonRelaxationDataContainer.cpp
//---------------------------------------------------------------------------//
