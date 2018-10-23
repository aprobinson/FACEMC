//---------------------------------------------------------------------------//
//!
//! \file   tstDecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution.cpp
//! \author Alex Robinson
//! \brief  Decoupled complete DB photon energy distribution unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>
#include <limits>
#include <memory>

// FRENSIE Includes
#include "MonteCarlo_DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution.hpp"
#include "MonteCarlo_ComptonProfilePolicy.hpp"
#include "MonteCarlo_ComptonProfileHelpers.hpp"
#include "MonteCarlo_ComptonProfileSubshellConverterFactory.hpp"
#include "MonteCarlo_StandardComptonProfile.hpp"
#include "Data_SubshellType.hpp"
#include "Data_ACEFileHandler.hpp"
#include "Data_XSSEPRDataExtractor.hpp"
#include "Utility_TabularDistribution.hpp"
#include "Utility_RandomNumberGenerator.hpp"
#include "Utility_AtomicMomentumUnit.hpp"
#include "Utility_InverseAtomicMomentumUnit.hpp"
#include "Utility_UnitTestHarnessWithMain.hpp"

//---------------------------------------------------------------------------//
// Testing Variables
//---------------------------------------------------------------------------//

std::shared_ptr<const MonteCarlo::DopplerBroadenedPhotonEnergyDistribution>
  half_distribution;

std::shared_ptr<const MonteCarlo::CompleteDopplerBroadenedPhotonEnergyDistribution>
  half_complete_distribution;

std::shared_ptr<const MonteCarlo::DopplerBroadenedPhotonEnergyDistribution>
  full_distribution;

std::shared_ptr<const MonteCarlo::CompleteDopplerBroadenedPhotonEnergyDistribution>
  full_complete_distribution;

//---------------------------------------------------------------------------//
// Tests.
//---------------------------------------------------------------------------//
// Check if the distribution is complete
FRENSIE_UNIT_TEST(
             DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
             isComplete )
{
  FRENSIE_CHECK( half_distribution->isComplete() );

  FRENSIE_CHECK( full_distribution->isComplete() );
}

//---------------------------------------------------------------------------//
// Check if a subshell is valid
FRENSIE_UNIT_TEST(
             DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
             isValidSubshell )
{
  // Half distribution
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                    Data::K_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::L1_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::L2_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::L3_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::M1_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::M2_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::M3_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::M4_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::M5_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N1_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N2_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N3_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N4_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N5_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N6_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::N7_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::O1_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::O2_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::O3_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::O4_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::O5_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::P1_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::P2_SUBSHELL ) );
  FRENSIE_CHECK( half_complete_distribution->isValidSubshell(
                                                   Data::P3_SUBSHELL ) );
  FRENSIE_CHECK( !half_complete_distribution->isValidSubshell(
                                                   Data::Q3_SUBSHELL ) );
  FRENSIE_CHECK( !half_complete_distribution->isValidSubshell(
                                              Data::INVALID_SUBSHELL ) );
  FRENSIE_CHECK( !half_complete_distribution->isValidSubshell(
                                              Data::UNKNOWN_SUBSHELL ) );

  // Full distribution
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                    Data::K_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::L1_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::L2_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::L3_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::M1_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::M2_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::M3_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::M4_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::M5_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N1_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N2_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N3_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N4_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N5_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N6_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::N7_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::O1_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::O2_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::O3_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::O4_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::O5_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::P1_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::P2_SUBSHELL ) );
  FRENSIE_CHECK( full_complete_distribution->isValidSubshell(
                                                   Data::P3_SUBSHELL ) );
  FRENSIE_CHECK( !full_complete_distribution->isValidSubshell(
                                                   Data::Q3_SUBSHELL ) );
  FRENSIE_CHECK( !full_complete_distribution->isValidSubshell(
                                              Data::INVALID_SUBSHELL ) );
  FRENSIE_CHECK( !full_complete_distribution->isValidSubshell(
                                              Data::UNKNOWN_SUBSHELL ) );
}

//---------------------------------------------------------------------------//
// Check that the subshell binding energy can be returned
FRENSIE_UNIT_TEST(
             DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
             getSubshellBindingEnergy )
{
  // Half distribution
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                      Data::K_SUBSHELL ),
                          0.088005,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::L1_SUBSHELL ),
                          0.015861,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::L2_SUBSHELL ),
                          0.0152,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::L3_SUBSHELL ),
                          0.013035,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M1_SUBSHELL ),
                          0.003851,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M2_SUBSHELL ),
                          0.003554,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M3_SUBSHELL ),
                          0.003066,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M4_SUBSHELL ),
                          0.002586,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M5_SUBSHELL ),
                          0.002484,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N1_SUBSHELL ),
                          0.000894,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N2_SUBSHELL ),
                          0.000764,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N3_SUBSHELL ),
                          0.000645,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N4_SUBSHELL ),
                          0.000434,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N5_SUBSHELL ),
                          0.000412,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N6_SUBSHELL ),
                          0.000141,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N7_SUBSHELL ),
                          0.000136,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O1_SUBSHELL ),
                          0.000148,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O2_SUBSHELL ),
                          0.000105,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O3_SUBSHELL ),
                          8.6e-5,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O4_SUBSHELL ),
                          2.0e-5,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O5_SUBSHELL ),
                          1.8e-5,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::P1_SUBSHELL ),
                          0.0,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::P2_SUBSHELL ),
                          0.0,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( half_complete_distribution->getSubshellBindingEnergy(
                                                     Data::P3_SUBSHELL ),
                          0.0,
                          1e-15 );

  // Full distribution
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                      Data::K_SUBSHELL ),
                          0.088005,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::L1_SUBSHELL ),
                          0.015861,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::L2_SUBSHELL ),
                          0.0152,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::L3_SUBSHELL ),
                          0.013035,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M1_SUBSHELL ),
                          0.003851,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M2_SUBSHELL ),
                          0.003554,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M3_SUBSHELL ),
                          0.003066,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M4_SUBSHELL ),
                          0.002586,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::M5_SUBSHELL ),
                          0.002484,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N1_SUBSHELL ),
                          0.000894,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N2_SUBSHELL ),
                          0.000764,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N3_SUBSHELL ),
                          0.000645,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N4_SUBSHELL ),
                          0.000434,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N5_SUBSHELL ),
                          0.000412,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N6_SUBSHELL ),
                          0.000141,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::N7_SUBSHELL ),
                          0.000136,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O1_SUBSHELL ),
                          0.000148,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O2_SUBSHELL ),
                          0.000105,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O3_SUBSHELL ),
                          8.6e-5,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O4_SUBSHELL ),
                          2.0e-5,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::O5_SUBSHELL ),
                          1.8e-5,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::P1_SUBSHELL ),
                          0.0,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::P2_SUBSHELL ),
                          0.0,
                          1e-15 );
  FRENSIE_CHECK_FLOATING_EQUALITY( full_complete_distribution->getSubshellBindingEnergy(
                                                     Data::P3_SUBSHELL ),
                          0.0,
                          1e-15 );
}

//---------------------------------------------------------------------------//
// Check that the subshell occupancy can be returned
FRENSIE_UNIT_TEST(
             DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
             getSubshellOccupancy )
{
  // Half distribution
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                      Data::K_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::L1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::L2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::L3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::M1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::M2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::M3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::M4_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::M5_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N4_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N5_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N6_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::N7_SUBSHELL ),
                       8 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::O1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::O2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::O3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::O4_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::O5_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::P1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::P2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( half_complete_distribution->getSubshellOccupancy(
                                                     Data::P3_SUBSHELL ),
                       2 );

  // Full distribution
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                      Data::K_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::L1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::L2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::L3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::M1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::M2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::M3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::M4_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::M5_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N4_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N5_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N6_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::N7_SUBSHELL ),
                       8 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::O1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::O2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::O3_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::O4_SUBSHELL ),
                       4 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::O5_SUBSHELL ),
                       6 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::P1_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::P2_SUBSHELL ),
                       2 );
  FRENSIE_CHECK_EQUAL( full_complete_distribution->getSubshellOccupancy(
                                                     Data::P3_SUBSHELL ),
                       2 );
}

//---------------------------------------------------------------------------//
// Check that the subshell distribution can be evaluated
FRENSIE_UNIT_TEST(
             DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
             evaluateSubshellWithElectronMomentumProjection_half )
{
  // pz_max <= 0.0, pz = pz_max
  double cross_section =
    half_complete_distribution->evaluateSubshellWithElectronMomentumProjection(
                        0.26055, -0.01189331797743439, 0.0, Data::K_SUBSHELL );
  
  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  cross_section =
    half_complete_distribution->evaluateSubshellWithElectronMomentumProjection(
                                        0.26055, -1.0, 0.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  // Mu = -1.0
  // Above pz_max (table pz_max, not the true pz_max)
  cross_section =
    half_complete_distribution->evaluateSubshellWithElectronMomentumProjection(
                             0.5, 0.7875582275970302, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );
  
  // pz = pz_max (table pz_max, not the true pz_max)
  cross_section =
    half_complete_distribution->evaluateSubshellWithElectronMomentumProjection(
                             0.5, 0.7297352569816316, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.02789302998932924, 1e-9 );
}

//---------------------------------------------------------------------------//
// Check that the subshell distribution can be evaluated
FRENSIE_UNIT_TEST( 
             DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
             evaluateSubshell_half )
{
  // Incoming energy below min energy (pz_max <= 0.0)
  double cross_section = half_complete_distribution->evaluateSubshell(
                                    0.26055, 0.172545, 0.0, Data::K_SUBSHELL );
  
  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  cross_section = half_complete_distribution->evaluateSubshell(
                                        0.26055, 1e-6, 0.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  // Mu = -1.0
  // Above max energy (table max, not the true max)
  cross_section = half_complete_distribution->evaluateSubshell(
                                          0.5, 0.389, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );
  
  // Max energy (table max, not the true max)
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.38831779122923316, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.09284777712806079, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.16909307700494494, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 1.0872312326605855, 1e-9 );

  // Min energy (corresponding to -pz_max) - not the true min energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.036654152201969, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.15368991735277307, 1e-9 );
  
  // Below the min energy
  cross_section = half_complete_distribution->evaluateSubshell(
                                          0.5, 0.036, -1.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  // Mu = 0.0
  // Above max energy
  cross_section = half_complete_distribution->evaluateSubshell(
                                           0.5, 0.412, 0.0, Data::K_SUBSHELL );
  
  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  // Max energy
  cross_section = half_complete_distribution->evaluateSubshell(
                                        0.5, 0.411995, 0.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.23568941788995593, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                             0.5, 0.25271981255859755, 0.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.8739457040455174, 1e-9 );

  // Min energy (corresponding to -pz_max) - not the true min energy
  cross_section = half_complete_distribution->evaluateSubshell(
                              0.5, 0.1259578643763628, 0.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.2961415215740492, 1e-9 );

  // Below the min energy  
  cross_section = half_complete_distribution->evaluateSubshell(
                                           0.5, 0.125, 0.0, Data::K_SUBSHELL );

  FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::L1_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 2.8795592631443463, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::L2_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 1.3641862029267904, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::L3_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 3.1058197315608105, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::M1_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 6.22294684805154, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::M2_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 3.5993492179041424, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::M3_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 7.849476872027157, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::M4_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 5.072957333261603, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::M5_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 7.80936397037139, 1e-9 );
  
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N1_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 12.724993765984314, 1e-9 );
  
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N2_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 8.017860671607723, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N3_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 17.404293921844925, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N4_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 12.934220762743779, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N5_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 19.866582309610457, 1e-9 );
  
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N6_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 16.340019178656313, 1e-9 );
  
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::N7_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 22.014409681317527, 1e-9 );
  
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::O1_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 29.614290862625364, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::O2_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 19.45765078643722, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::O3_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 42.95534691003039, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::O4_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 39.96137153322004, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::O5_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 61.61849575263572, 1e-9 );

  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::P1_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 94.62281727761084, 1e-9 );
  
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::P2_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 73.60158341273974, 1e-15 );
 
  // Compton-line energy
  cross_section = half_complete_distribution->evaluateSubshell(
                            0.5, 0.25271981255859755, 0.0, Data::P3_SUBSHELL );

  FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 73.60158341273974, 1e-15 );
}

// //---------------------------------------------------------------------------//
// // Check that the subshell distribution can be evaluated
// FRENSIE_UNIT_TEST( 
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluateSubshell_full )
// {
//   // Above max energy
//   double cross_section = full_complete_distribution->evaluateSubshell(
//                                                       0.5,
//                                                       0.412,
//                                                       0.0,
//                                                       Data::K_SUBSHELL );
  
//   FRENSIE_CHECK_EQUAL( cross_section, 0.0 );

//   // Max energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                       0.5,
//                                                       0.411995,
//                                                       0.0,
//                                                       Data::K_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 
//                           0.077179060436207,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                       0.5,
//                                                       0.25271981255859755,
//                                                       0.0,
//                                                       Data::K_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           0.24747240367306983,
//                           1e-15 );

//   // Min energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                       0.5,
//                                                       0.0,
//                                                       0.0,
//                                                       Data::K_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           0.009842522369949987,
//                           1e-15 ); 

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           0.815395566418701,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           0.38629223432666243,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           0.8794650180059378,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           1.7621319119578402,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           1.0192161806966558,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           2.2227112051752336,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           1.4364930672258214,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           2.2113525633910784,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           3.6032956960778817,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           2.2703919059658135,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           4.928318122205952,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           3.662541834095016,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           5.625556432361759,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N6_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           4.626950854598549,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N7_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           6.233749824572172,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           8.385783818059283,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           5.509760603731998,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           12.163527895643893,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           11.315733485067268,
//                           1e-15 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           17.448311930633853,
//                           1e-15 );
  
//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           26.794039864962183,
//                           1e-14 );

//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           20.841524452812,
//                           1e-15 );
 
//   // Compton-line energy
//   cross_section = full_complete_distribution->evaluateSubshell(
//                                                      0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section,
//                           20.841524452812,
//                           1e-15 );
// }

// //---------------------------------------------------------------------------//
// // Check that the complete distribution can be evaluated
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluate )
// {
//   // Compton-line energy
//   double cross_section = half_distribution->evaluate( 0.5,
//                                                       0.25271981255859755,
//                                                       0.0 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 144.39001687165862, 1e-15 );

//   // Compton-line energy
//   cross_section = full_distribution->evaluate( 0.5,
//                                                0.25271981255859755,
//                                                0.0 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 144.39001687165862, 1e-15 );
// }

// //---------------------------------------------------------------------------//
// // Check that the subshell integrated cross section can be evaluated
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluateSubshellIntegratedCrossSection_half )
// {
//   double cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                         0.5,
//                                                         0.0,
//                                                         Data::K_SUBSHELL,
//                                                         1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0506787976678307606, 1e-12 );
  
//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::L1_SUBSHELL,
//                                                        1e-3 );
                                                              
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0539421594075661509, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::L2_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0544804774400405936, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::L3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.108643678063119545, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M1_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0537557438879969415, 1e-12 );
  
//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M2_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0538845285472215121, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107670237956284012, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M4_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107645274793230467, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M5_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.161418283770527915, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N1_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0536342777913152297, 1e-12 );
 
//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N2_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.053665026335982989, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.10729807014692927, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N4_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107276124378478083, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N5_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.160895822405358047, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N6_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.160854431039325119, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N7_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.21446862724054877, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O1_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535797701764630513, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O2_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535831274038866892, 1e-12 );
  
//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O3_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107157222253782866, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O4_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107143514635324733, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O5_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.16071289870148503, 1e-12 );
  
//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::P1_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535621266370162954, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::P2_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535613424402932373, 1e-12 );

//   cross_section = 
//     half_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::P3_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535613424402932373, 1e-12 );
// }

// //---------------------------------------------------------------------------//
// // Check that the subshell integrated cross section can be evaluated
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluateSubshellIntegratedCrossSection_full )
// {
//   double cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                         0.5,
//                                                         0.0,
//                                                         Data::K_SUBSHELL,
//                                                         1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0519379030758085128, 1e-12 );
  
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::L1_SUBSHELL,
//                                                        1e-3 );
                                                              
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0542261359375576096, 1e-12 );
  
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::L2_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0545496676195199245, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::L3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.108712226617216717, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection( 
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M1_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0538286427776931836, 1e-12 );
  
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M2_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0539132788874106678, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107691472905151867, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M4_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107646395205054715, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::M5_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.161419179774725308, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N1_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0536534010499861644, 1e-12 );
 
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N2_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0536725588587172869, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107304077175130422, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N4_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.10727645774553729, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N5_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.160896098697318413, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N6_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.160854432895073562, 1e-12 );
  
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::N7_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.214468628834499186, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O1_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535835334668938595, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O2_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535845893672419471, 1e-12 );
  
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O3_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107158181783069198, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O4_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.107143553741129008, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::O5_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.160712932063177688, 1e-12 );
  
//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::P1_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.05356259121654907, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::P2_SUBSHELL,
//                                                        1e-3 );
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535614418966963851, 1e-12 );

//   cross_section = 
//     full_complete_distribution->evaluateSubshellIntegratedCrossSection(
//                                                        0.5,
//                                                        0.0,
//                                                        Data::P3_SUBSHELL,
//                                                        1e-3 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 0.0535614418966963851, 1e-12 );
// }

// //---------------------------------------------------------------------------//
// // Check that the complete integrated cross section can be evaluated
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluateIntegratedCrossSection )
// {
//   double cross_section = 
//     half_complete_distribution->evaluateIntegratedCrossSection(
//                                                               0.5, 0.0, 1e-4 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 2.1995115631200073, 1e-5 );

//   cross_section = 
//     full_complete_distribution->evaluateIntegratedCrossSection(
//                                                               0.5, 0.0, 1e-4 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( cross_section, 2.201357381591158, 1e-4 );
// }

// //---------------------------------------------------------------------------//
// // Check that the subshell PDF can be evaluated
// FRENSIE_UNIT_TEST( 
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluateSubshellPDF_half )
// {
//   // Compton-line energy
//   double pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::K_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 4.8831545944539485, 1e-12 );
                                                     
//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 15.116109094889707, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 7.090470797577038, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 8.094948861129208, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 32.78034651756172, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 18.91482041646647, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 20.64369177002927, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 13.344692277344242, 1e-12 );
  
//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 13.699517252548263, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 67.18270189258236, 1e-12 );
  
//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 42.30673235398174, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 45.93109750676158, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 34.14125794825788, 1e-12 );

//   // Compton-line energy
//   pdf_value = 
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 34.96396828867833, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N6_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 28.764833052484384, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N7_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 29.066021938865568, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 156.51026106384936, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 102.82640955616084, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 113.51104143812852, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 105.61286442377467, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 108.56821121149143, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 500.24227093412435, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 389.11505020705556, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     half_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 389.11505020705556, 1e-12 );

//   // Check that the pdf evaluates to 1.0
//   boost::function<double (double x)> double_diff_cs_wrapper = 
//     boost::bind<double>( &MonteCarlo::CompleteDopplerBroadenedPhotonEnergyDistribution::evaluateSubshellPDF,
//                          boost::cref( *half_complete_distribution ),
//                          0.5,
//                          _1,
//                          -1.0,
//                          Data::K_SUBSHELL,
//                          1e-3 );

//   Utility::GaussKronrodIntegrator quadrature_set( 1e-3 );

//   double abs_error, value;

//   const double binding_energy = half_complete_distribution->getSubshellBindingEnergy( Data::K_SUBSHELL );
  
//   quadrature_set.integrateAdaptively<15>( double_diff_cs_wrapper,
//                                           0.0,
//                                           0.5 - binding_energy,
//                                           value,
//                                           abs_error );
//   std::cout.precision( 18 );
//   std::cout << value << std::endl;
// }

// //---------------------------------------------------------------------------//
// // Check that the subshell PDF can be evaluated
// FRENSIE_UNIT_TEST( 
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluateSubshellPDF_full )
// {
//   // Compton-line energy
//   double pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::K_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 4.7647746446724915, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 15.036947632736435, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 7.081477324867008, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::L3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 8.089844586686603, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 32.73595285014459, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 32.73595285014459, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 18.904733708093087, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 20.63962118089761, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 13.344553382298198, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::M5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 13.699441209385501, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 67.15875649189272, 1e-12 );
  
//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 42.300794935866286, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 45.92852622144515, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 34.141151852558984, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 34.96390824829563, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N6_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 28.764832720629716, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::N7_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 29.06602172284424, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 156.49926900099578, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 102.82360411443777, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 113.51002502326621, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O4_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 105.61282587664924, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::O5_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 108.56818867429266, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P1_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 500.23793204171403, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P2_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 389.1143276726739, 1e-12 );

//   // Compton-line energy
//   pdf_value =
//     full_complete_distribution->evaluateSubshellPDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0,
//                                                      Data::P3_SUBSHELL );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 389.1143276726739, 1e-12 );
// }

// //---------------------------------------------------------------------------//
// // Check that the complete PDF can be evaluated
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              evaluatePDF )
// {
//   // Compton-line energy
//   double pdf_value = half_distribution->evaluatePDF( 0.5,
//                                                      0.25271981255859755,
//                                                      0.0 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 65.64640045212646, 1e-4 );

//   // Compton-line energy
//   pdf_value = full_distribution->evaluatePDF( 0.5,
//                                               0.25271981255859755,
//                                               0.0 );

//   FRENSIE_CHECK_FLOATING_EQUALITY( pdf_value, 65.59135653261916, 1e-5 );
// }

// //---------------------------------------------------------------------------//
// // Check that the subshell momentum can be sampled
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              sampleSubshellMomentum )
// {
  
// }

// //---------------------------------------------------------------------------//
// // Check that the electron momentum can be sampled
// FRENSIE_UNIT_TEST(
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              sampleMomentumAndRecordTrials )
// {
  
// }

// //---------------------------------------------------------------------------//
// // Check that the distribution can be sampled
// FRENSIE_UNIT_TEST( 
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              sample_half )
// {
//   double incoming_energy = 20.0, scattering_angle_cosine = 0.0;
//   double outgoing_energy;
//   Data::SubshellType shell_of_interaction;

//   // Set up the random number stream
//   std::vector<double> fake_stream( 4 );
//   fake_stream[0] = 0.005; // select first shell for collision - old
//   fake_stream[1] = 0.005; // select first shell for collision - endf
//   fake_stream[2] = 6.427713151861e-01; // select pz = 0.291894102792
//   fake_stream[3] = 0.25; // select energy loss
  
//   Utility::RandomNumberGenerator::setFakeStream( fake_stream );

//   half_distribution->sample( incoming_energy,
// 			     scattering_angle_cosine,
// 			     outgoing_energy,
// 			     shell_of_interaction );

//   Utility::RandomNumberGenerator::unsetFakeStream();
  
//   FRENSIE_CHECK_FLOATING_EQUALITY( outgoing_energy, 0.352804013048420073, 1e-12 );
//   FRENSIE_CHECK_EQUAL( shell_of_interaction, Data::K_SUBSHELL );
// }

// //---------------------------------------------------------------------------//
// // Check that the distribution can be sampled
// FRENSIE_UNIT_TEST( 
//              DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution,
//              sample_full )
// {
//   double incoming_energy = 20.0, scattering_angle_cosine = 0.0;
//   double outgoing_energy;
//   Data::SubshellType shell_of_interaction;

//   // Set up the random number stream
//   std::vector<double> fake_stream( 3 );
//   fake_stream[0] = 0.005; // select first shell for collision - old
//   fake_stream[1] = 0.005; // select first shell for collision - endf
//   fake_stream[2] = 0.5; // select pz = 0.0
  
//   Utility::RandomNumberGenerator::setFakeStream( fake_stream );

//   full_distribution->sample( incoming_energy,
// 			     scattering_angle_cosine,
// 			     outgoing_energy,
// 			     shell_of_interaction );

//   Utility::RandomNumberGenerator::unsetFakeStream();

//   FRENSIE_CHECK_FLOATING_EQUALITY( outgoing_energy, 0.4982681851517501, 1e-12 );
//   FRENSIE_CHECK_EQUAL( shell_of_interaction, Data::K_SUBSHELL );
// }

//---------------------------------------------------------------------------//
// Custom Setup
//---------------------------------------------------------------------------//
FRENSIE_CUSTOM_UNIT_TEST_SETUP_BEGIN();

std::string test_ace_file_name, test_ace_table_name;

FRENSIE_CUSTOM_UNIT_TEST_COMMAND_LINE_OPTIONS()
{
  ADD_STANDARD_OPTION_AND_ASSIGN_VALUE( "test_ace_file",
                                        test_ace_file_name, "",
                                        "Test ACE file name" );
  ADD_STANDARD_OPTION_AND_ASSIGN_VALUE( "test_ace_table",
                                        test_ace_table_name, "",
                                        "Test ACE table name" );
}

FRENSIE_CUSTOM_UNIT_TEST_INIT()
{
  // Create a file handler and data extractor
  std::shared_ptr<Data::ACEFileHandler> ace_file_handler(
				 new Data::ACEFileHandler( test_ace_file_name,
							   test_ace_table_name,
							   1u ) );
  std::shared_ptr<Data::XSSEPRDataExtractor> xss_data_extractor(
                            new Data::XSSEPRDataExtractor(
				      ace_file_handler->getTableNXSArray(),
				      ace_file_handler->getTableJXSArray(),
				      ace_file_handler->getTableXSSArray() ) );

  // Create the subshell order array
  Utility::ArrayView<const double> subshell_endf_des =
    xss_data_extractor->extractSubshellENDFDesignators();

  std::vector<Data::SubshellType> subshell_order(
						    subshell_endf_des.size() );

  for( unsigned i = 0; i < subshell_order.size(); ++i )
  {
    subshell_order[i] = Data::convertENDFDesignatorToSubshellEnum(
					      (unsigned)subshell_endf_des[i] );
  }

  // Create the Compton profile subshell converter
  std::shared_ptr<const MonteCarlo::ComptonProfileSubshellConverter> converter;

  MonteCarlo::ComptonProfileSubshellConverterFactory::createConverter(
				   converter,
			           xss_data_extractor->extractAtomicNumber() );

  // Create the compton profile distributions
  Utility::ArrayView<const double> lswd_block =
    xss_data_extractor->extractLSWDBlock();

  Utility::ArrayView<const double> swd_block =
    xss_data_extractor->extractSWDBlock();

  MonteCarlo::CompleteDopplerBroadenedPhotonEnergyDistribution::ComptonProfileArray
    half_compton_profiles( lswd_block.size() ),
    full_compton_profiles( lswd_block.size() );

  for( unsigned shell = 0; shell < lswd_block.size(); ++shell )
  {
    unsigned shell_index = lswd_block[shell]; // ignore interp parameter

    unsigned num_mom_vals = swd_block[shell_index];

    Utility::ArrayView<const double> raw_half_momentum_grid =
      swd_block( shell_index + 1, num_mom_vals );
    
    std::vector<double> half_momentum_grid( raw_half_momentum_grid.begin(),
                                            raw_half_momentum_grid.end() );

    Utility::ArrayView<const double> raw_half_profile =
      swd_block( shell_index + 1 + num_mom_vals, num_mom_vals );

    std::vector<double> half_profile( raw_half_profile.begin(),
                                      raw_half_profile.end() );
                                     
    std::vector<double> full_momentum_grid, full_profile;

    MonteCarlo::createFullProfileFromHalfProfile( half_momentum_grid.begin(),
						  half_momentum_grid.end(),
						  half_profile.begin(),
						  half_profile.end(),
						  full_momentum_grid,
						  full_profile,
                                                  true );

    // if( shell == 0 )
    // {
    //   Utility::ArrayView<const double> raw_half_cdf =
    //     swd_block( shell_index + 1 + 2*num_mom_vals, num_mom_vals );
      
    //   std::vector<double> half_cdf( raw_half_cdf.begin(),
    //                                 raw_half_cdf.end() );
                                   
    //   std::cout.precision( 18 );
    //   for( unsigned i = 0; i < half_momentum_grid.size(); ++i )
    //   {
    //     std::cout << half_momentum_grid[i] << " "
    //               << half_profile[i] << " "
    //               << half_cdf[i] << std::endl;
    //   }
    //   std::cout << std::endl << "FULL" << std::endl;
    //   for( unsigned i = 0; i < full_momentum_grid.size(); ++i )
    //   {
    //     std::cout << full_momentum_grid[i] << " "
    //               << full_profile[i] << std::endl;
    //   }
    // }

    std::shared_ptr<Utility::UnitAwareTabularUnivariateDistribution<Utility::Units::AtomicMomentum,Utility::Units::InverseAtomicMomentum> > raw_compton_profile(
       new Utility::UnitAwareTabularDistribution<Utility::LinLin,Utility::Units::AtomicMomentum,Utility::Units::InverseAtomicMomentum>(
                                                       half_momentum_grid,
                                                       half_profile ) );

    if( shell == 0 )
    {
      std::shared_ptr<Utility::UnitAwareTabularDistribution<Utility::LinLin,Utility::Units::AtomicMomentum,Utility::Units::InverseAtomicMomentum> > raw_compton_profile_copy = std::dynamic_pointer_cast<Utility::UnitAwareTabularDistribution<Utility::LinLin,Utility::Units::AtomicMomentum,Utility::Units::InverseAtomicMomentum> >( raw_compton_profile );

      raw_compton_profile_copy->toStream( std::cout );
    }

    half_compton_profiles[shell].reset(
       new MonteCarlo::StandardComptonProfile<Utility::Units::AtomicMomentum>(
                                                       raw_compton_profile ) );

    raw_compton_profile.reset(
       new Utility::UnitAwareTabularDistribution<Utility::LinLin,Utility::Units::AtomicMomentum,Utility::Units::InverseAtomicMomentum>(
                                                       full_momentum_grid,
                                                       full_profile ) );

    full_compton_profiles[shell].reset(
       new MonteCarlo::StandardComptonProfile<Utility::Units::AtomicMomentum>(
                                                       raw_compton_profile ) );

  }

  std::vector<double> subshell_occupancies(
                      xss_data_extractor->extractSubshellOccupancies().begin(),
                      xss_data_extractor->extractSubshellOccupancies().end() );

  std::vector<double> old_subshell_binding_energies(
                               xss_data_extractor->extractLBEPSBlock().begin(),
                               xss_data_extractor->extractLBEPSBlock().end() );

  std::vector<double> old_subshell_occupancies(
                               xss_data_extractor->extractLNEPSBlock().begin(),
                               xss_data_extractor->extractLNEPSBlock().end() );

  half_complete_distribution.reset(
     new MonteCarlo::DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution<MonteCarlo::DoubledHalfComptonProfilePolicy>(
                                       subshell_occupancies,
                                       subshell_order,
                                       old_subshell_binding_energies,
                                       old_subshell_occupancies,
                                       converter,
                                       half_compton_profiles ) );

  half_distribution = half_complete_distribution;

  full_complete_distribution.reset(
      new MonteCarlo::DecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution<MonteCarlo::FullComptonProfilePolicy>(
                                                 subshell_occupancies,
                                                 subshell_order,
			                         old_subshell_binding_energies,
                                                 old_subshell_occupancies,
                                                 converter,
                                                 full_compton_profiles ) );

  full_distribution = full_complete_distribution;

  // Clear setup data
  ace_file_handler.reset();
  xss_data_extractor.reset();

  // Initialize the random number generator
  Utility::RandomNumberGenerator::createStreams();
}

FRENSIE_CUSTOM_UNIT_TEST_SETUP_END();

//---------------------------------------------------------------------------//
// end tstDecoupledStandardCompleteDopplerBroadenedPhotonEnergyDistribution.cpp
//---------------------------------------------------------------------------//