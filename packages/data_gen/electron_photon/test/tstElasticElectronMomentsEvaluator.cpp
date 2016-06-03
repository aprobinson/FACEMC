//---------------------------------------------------------------------------//
//!
//! \file   tstElasticElectronMomentsEvaluator.cpp
//! \author Luke Kersting
//! \brief  Elastic electron cross section moments evaluator unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>

// Trilinos Includes
#include <Teuchos_UnitTestHarness.hpp>
#include <Teuchos_VerboseObject.hpp>
#include <Teuchos_RCP.hpp>

// FRENSIE Includes
#include "DataGen_ElasticElectronMomentsEvaluator.hpp"
#include "Data_ElectronPhotonRelaxationDataContainer.hpp"
#include "Utility_UnitTestHarnessExtensions.hpp"
#include "MonteCarlo_HardElasticElectroatomicReaction.hpp"
#include "MonteCarlo_HardElasticElectronScatteringDistribution.hpp"
#include "MonteCarlo_HardElasticElectronScatteringDistributionACEFactory.hpp"
#include "MonteCarlo_ElectroatomicReactionACEFactory.hpp"

//---------------------------------------------------------------------------//
// Testing Structs.
//---------------------------------------------------------------------------//
class TestElasticElectronMomentsEvaluator : public DataGen::ElasticElectronMomentsEvaluator
{
public:
  TestElasticElectronMomentsEvaluator( 
        const Data::ElectronPhotonRelaxationDataContainer& data_container )
    : ElasticElectronMomentsEvaluator( data_container, 0.999999 )
  { /* ... */ }

  ~TestElasticElectronMomentsEvaluator()
  { /* ... */ }

  // Allow public access to the ElasticElectronMomentsEvaluator protected member functions
  using DataGen::ElasticElectronMomentsEvaluator::evaluateCutoffPDFMoment;
  using DataGen::ElasticElectronMomentsEvaluator::evaluateScreenedRutherfordPDFMoment;
};

//---------------------------------------------------------------------------//
// Testing Variables
//---------------------------------------------------------------------------//

Teuchos::RCP<Data::ElectronPhotonRelaxationDataContainer> pb_data, al_data;
Teuchos::RCP<DataGen::ElasticElectronMomentsEvaluator>
  pb_evaluator, al_evaluator;

Teuchos::RCP<TestElasticElectronMomentsEvaluator>
  test_al_evaluator;

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
// Check that the legendre expanded screened rutherford pdf can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateLegendreExpandedRutherford )
{
  double n = 4;
  
  double expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedRutherford( 0.999999,
                                                      1.000000000000E-05,
                                                      n );
  double pdf = 5.00E-01;
  double legendre_expansion = 0.999990000022499982500004375;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );

  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedRutherford( 1.0,
                                                      1.000000000000E-03,
                                                      n );

  pdf = 9.078446769559230E+01;
  legendre_expansion = 1.0;

  UTILITY_TEST_FLOATING_EQUALITY(  
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );

  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedRutherford( 0.999999,
                                                      1.000000000000E+05,
                                                      n );

  pdf = 9.863740E+05;
  legendre_expansion = 0.9999900000225;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-10 );		


n = 2;
  
  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedRutherford( 1.0,
                                                      1.000000000000E-05,
                                                      n );

  pdf = 5.00000000397902E-01;
  legendre_expansion = 1.0;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );
}

//---------------------------------------------------------------------------//
// Check that the legendre expanded differential cross section can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateLegendreExpandedPDF )
{
  double n = 4;
  
  double expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDF( 0.999999,
                                               1.000000000000E-05,
                                               n );

  double pdf = 5.00E-01/9.999995000E-01;
  double legendre_expansion = 0.999990000022499982500004375;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );

  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDF( -1.0,
                                               1.000000000000E-03,
                                               n );

  pdf = 5.968430E-01/9.9999985651050E-01;
  legendre_expansion = 1.0;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );

  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDF( 0.9999979,
                                               1.000000000000E+05,
                                               n );

  pdf = 2.237270E+05/9.99999722875817E-01;
  legendre_expansion = 9.999790000992240E-01;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-10 );


n = 2;
  
  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDF( -1.0,
                                               1.000000000000E-05,
                                               n );

  pdf = 5.000E-01/9.999995000E-01;
  legendre_expansion = 1.0;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );	
}

//---------------------------------------------------------------------------//
// Check that the hydrogen expanded differential cross section can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateLegendreExpandedPDFAtEnergyBin )
{
  double n = 4;
  
  double expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDFAtEnergyBin( 0.999999,
                                                          0,
                                                          n );

  double pdf = 5.00E-01/9.999995000E-01;
  double legendre_expansion = 0.999990000022499982500004375;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );

  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDFAtEnergyBin( -1.0,
                                                          1,
                                                          n );

  pdf = 5.968430E-01/9.9999985651050E-01;
  legendre_expansion = 1.0;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );

  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDFAtEnergyBin( 0.9999979,
                                                          13,
                                                          n );

  pdf = 2.237270E+05/9.99999722875817E-01;
  legendre_expansion = 9.999790000992240E-01;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-10 );		


  n = 2;
  
  expanded_pdf = 
    pb_evaluator->evaluateLegendreExpandedPDFAtEnergyBin( -1.0,
                                                          0,
                                                          n );

  pdf = 5.000E-01/9.999995000E-01;
  legendre_expansion = 1.0;

  UTILITY_TEST_FLOATING_EQUALITY( 
                    expanded_pdf,
                    pdf*legendre_expansion,
                    1e-12 );
}

//---------------------------------------------------------------------------//
// Check that the screened rutherford moments can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateScreenedRutherfordPDFMoment )
{
  unsigned n = 2;
  double energy = 1.0e5;
  double tol = 1e-14;
  Teuchos::Array<Utility::long_float> moments(n+1);
  Utility::long_float rutherford_moment;

  moments[0] = 1.0;
  moments[1] = 9.999999999999E-01L;
  moments[2] = 9.999999999997E-01L;

   test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

   test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

   test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );

  energy = 4.375000000000E+01;

  tol = 1e-16;
  moments.clear();
  moments[0] = 1.0L;
  moments[1] = 0.99999992222034858054L;
  moments[2] = 0.99999976666108267169L;

   test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

   test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

   test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );

  energy = 1.0e-5;

  moments.clear();
  moments[0] = 1.0L;
  moments[1] = 9.500000000000E-01L;
  moments[2] = 8.550000000001E-01L;

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         energy, 
                                         2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );


  tol = 1e-14;
  Utility::long_float eta = 2.855935652488E-15L;
  eta *= 2;
  energy = 1.0e5;

  moments.clear();
  moments[0] = 1.0L;
  moments[1] = 9.999999999999E-01L;
  moments[2] = 9.999999999997E-01L;

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );


  eta = (Utility::long_float)6.407445779740E-09L;
  eta *= 2;
  energy = 6.625E+01L;

  moments.clear();
  moments[0] = 1.0L;
  moments[1] = 9.999999560977E-01L;
  moments[2] = 9.999998682932E-01L;

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );

  eta = (Utility::long_float)1.457796275283E-08L;
  eta *= 2;
  energy = 4.3750E+01L;

  moments.clear();
  moments[0] = 1.0L;
  moments[1] = 9.999999222195E-01L;
  moments[2] = 9.999997666585E-01L;

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  test_al_evaluator->
    evaluateScreenedRutherfordPDFMoment( rutherford_moment,
                                         eta,
                                         energy, 
                                         2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );
}

//---------------------------------------------------------------------------//
// Check that the screened rutherford moments can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateScreenedRutherfordMoment )
{
  unsigned n = 6;
  double energy = 1.0e5;
  double tol = 1e-15;
  Teuchos::Array<Utility::long_float> moments(n+1);
  Utility::long_float rutherford_moment;

  long double cross_section = 2.11160991169490E+06L;

  moments[0] = cross_section;
  moments[1] = 9.9999999999933626914E-01L*cross_section;
  moments[2] = 9.9999999999800880748E-01L*cross_section;
  moments[3] = 9.9999999999601761514E-01L*cross_section;
  moments[4] = 9.9999999999336269232E-01L*cross_section;
  moments[5] = 9.9999999999004403926E-01L*cross_section;
  moments[6] = 9.9999999998606165627E-01L*cross_section;

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      0 );

  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );	

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      1 );

  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );	

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      2 );
	
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(), 
                                  tol );

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      3 );

  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[3].convert_to<double>(),  
                                  tol );

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      4 );

  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[4].convert_to<double>(),
                                  tol ); 

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      5 );

  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[5].convert_to<double>(),  
                                  tol ); 

  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      n );

  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[6].convert_to<double>(),
                                  tol ); 

  tol = 1e-15;
  n = 0;
  moments.resize(n+1);
  moments[0] = 0.0; 

  energy = 1.0e-5;
  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );	

  energy = 6.30957E+00;
  pb_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  n = 2;
  energy = 1.0e5;
  moments.resize(n+1);

  cross_section = 3.8550699778229999356e+05L;
  moments[0] = cross_section;
  moments[1] = 9.999999999999E-01L*cross_section;
  moments[2] = 9.999999999997E-01L*cross_section; 

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  energy = 4.375000000000E+01;

  tol = 1e-15;
  cross_section = 3.7500648271852370817e+05L;
  moments.clear();
  moments[0] = cross_section;
  moments[1] = 0.99999992222034858054L*cross_section;
  moments[2] = 0.99999976666108267169L*cross_section;

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );

  energy = 1.0e-5;

  cross_section = 0.0L;
  moments.clear();
  moments[0] = cross_section;
  moments[1] = 9.500000000000E-01L*cross_section;
  moments[2] = 8.550000000001E-01L*cross_section;

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      0 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[0].convert_to<double>(),
                                  tol );

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      1 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[1].convert_to<double>(),
                                  tol );

  al_evaluator->
    evaluateScreenedRutherfordMoment( rutherford_moment,
                                      energy, 
                                      2 );
  
  UTILITY_TEST_FLOATING_EQUALITY( rutherford_moment.convert_to<double>(), 
                                  moments[2].convert_to<double>(),
                                  tol );

}


//---------------------------------------------------------------------------//
// Check that the moments can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateCutoffPDFMoment )
{
  unsigned n = 6;
  double energy = 1.0e5;
  double tol = 1e-13;
  Teuchos::Array<Utility::long_float> moments(n+1);
  Utility::long_float cutoff_moment;

  moments[0] = 1.0L;
  moments[1] = 9.999999999993360E-01L;
  moments[2] = 9.999999999980090E-01L;
  moments[3] = 9.999999999960180E-01L;
  moments[4] = 9.999999999933630E-01L;
  moments[5] = 9.999999999900440E-01L;
  moments[6] = 9.999999999860620E-01L;

}

//---------------------------------------------------------------------------//
// Check that the moments can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateCutoffMoment )
{
  unsigned n = 6;
  double energy = 1.0e5;
  double tol = 1e-13;
  Teuchos::Array<Utility::long_float> moments(n+1);
  Utility::long_float cutoff_moment;

  long double cross_section = 1.0L;

  moments[0] = cross_section;
  moments[1] = 9.999999999993360E-01L*cross_section;
  moments[2] = 9.999999999980090E-01L*cross_section;
  moments[3] = 9.999999999960180E-01L*cross_section;
  moments[4] = 9.999999999933630E-01L*cross_section;
  moments[5] = 9.999999999900440E-01L*cross_section;
  moments[6] = 9.999999999860620E-01L*cross_section;
}

/*
//---------------------------------------------------------------------------//
// Check that the moments can be evaluated
TEUCHOS_UNIT_TEST( ElasticElectronMomentsEvaluator,
                   evaluateElasticMoment )
{
  double precision = 1e-10;
  double n = 0;
  double energy = 1.0e-5;
  double tol = 1e-10;

  Teuchos::RCP<DataGen::ElasticElectronMomentsEvaluator> full_evaluator; 

  full_evaluator.reset( new DataGen::ElasticElectronMomentsEvaluator(
                                    *pb_data,
                                    -1.0 ) );

  Teuchos::Array<Utility::long_float> total_moments(n+1);
/*
  full_evaluator->evaluateElasticMoment( total_moments, energy, n, precision );
  
  double cutoff_cross_section = 2.48924E+09;
  double sr_cross_section = 0.0;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );	

  energy = 0.001;
  full_evaluator->evaluateElasticMoment( total_moments, energy, n, precision );
  

  cutoff_cross_section = 2.90281E+08;
  sr_cross_section = 0.0;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );	

  energy = 5.5e1;
  full_evaluator->evaluateElasticMoment( total_moments, energy, n, precision );
  
  cutoff_cross_section = 2.51776896157372E+05;
  sr_cross_section = 1.89076556817226E+06;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );			 

  unsigned energy_bin = 0;

  full_evaluator->evaluateElasticMoment( total_moments, energy_bin, n, precision );
  
  cutoff_cross_section = 2.48924E+09;
  sr_cross_section = 0.0;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );	

  energy_bin = 1;
  full_evaluator->evaluateElasticMoment( total_moments, energy_bin, n, precision );
  
  cutoff_cross_section = 2.90281E+08;
  sr_cross_section = 0.0;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );	

  energy_bin = 12;
  full_evaluator->evaluateElasticMoment( total_moments, energy_bin, n, precision );
  
  cutoff_cross_section = 2.51776896157372E+05;
  sr_cross_section = 1.89076556817226E+06;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );			 


 
  energy_bin = 1;
  pb_evaluator->evaluateElasticMoment( total_moments, energy_bin, n, precision );
  
  double integrated_pdf = 7.56010292504539E-01;
  cutoff_cross_section = 2.90281E+08*integrated_pdf;
  sr_cross_section = 0.0;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );	

  energy_bin = 12;
  pb_evaluator->evaluateElasticMoment( total_moments, energy_bin, n, precision );
  
  integrated_pdf = 9.999834891716050E-01;
  cutoff_cross_section = 2.51776896157372E+05*integrated_pdf;
  sr_cross_section = 1.89076556817226E+06;

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(),
                                  cutoff_cross_section + sr_cross_section,
                                  tol );	

  pb_evaluator->evaluateElasticMoment( total_moments, energy_bin, 6, precision ); 
/*
  precision = 1e-13;
  n = 8;
  energy = 1e-5;
  total_moments.resize(n+1);
  pb_evaluator->evaluateElasticMoment( total_moments, energy, n, precision );

  UTILITY_TEST_FLOATING_EQUALITY( total_moments[0].convert_to<double>(), 
                                  5.000000000000020E-02,
                                  tol );	
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[1].convert_to<double>(), 
                                  4.750000000000010E-02,
                                  tol );		
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[2].convert_to<double>(), 
                                  4.275000000000010E-02, 
                                  tol );
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[3].convert_to<double>(), 
                                  3.621875000000010E-02,  
                                  tol );
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[4].convert_to<double>(), 
                                  2.853562500000020E-02,
                                  tol ); 
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[5].convert_to<double>(), 
                                  2.041371875000010E-02,  
                                  tol ); 
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[6].convert_to<double>(), 
                                  1.256475937499990E-02,
                                  tol ); 
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[7].convert_to<double>(), 
                                  5.617386367188300E-03,
                                  tol ); 
  UTILITY_TEST_FLOATING_EQUALITY( total_moments[8].convert_to<double>(), 
                                  4.957330078227900E-05,
                                  5e-11 ); *//*
}
*/

//---------------------------------------------------------------------------//
// Custom main function
//---------------------------------------------------------------------------//
int main( int argc, char** argv )
{
  std::string test_native_pb_file_name, test_native_al_file_name;
  
  Teuchos::CommandLineProcessor& clp = Teuchos::UnitTestRepository::getCLP();

  clp.setOption( "test_native_pb_file",
		 &test_native_pb_file_name,
		 "Test Native Pb file name" );
  clp.setOption( "test_native_al_file",
		 &test_native_al_file_name,
		 "Test Native Al file name" );

  const Teuchos::RCP<Teuchos::FancyOStream> out = 
    Teuchos::VerboseObjectBase::getDefaultOStream();

  Teuchos::CommandLineProcessor::EParseCommandLineReturn parse_return = 
    clp.parse(argc,argv);

  if ( parse_return != Teuchos::CommandLineProcessor::PARSE_SUCCESSFUL ) {
    *out << "\nEnd Result: TEST FAILED" << std::endl;
    return parse_return;
  }

  {
  // Create the native data file container
  al_data.reset( new Data::ElectronPhotonRelaxationDataContainer( 
						     test_native_al_file_name ) );


  // Create the moment evaluator
  al_evaluator.reset( new DataGen::ElasticElectronMomentsEvaluator(
                                    *al_data ) );

  // Create the test moment evaluator
  test_al_evaluator.reset( new TestElasticElectronMomentsEvaluator(
                                    *al_data ) );
  }

  {
  // Create the native data file container
  pb_data.reset( new Data::ElectronPhotonRelaxationDataContainer( 
						     test_native_pb_file_name ) );


  // Create the moment evaluator
  pb_evaluator.reset( new DataGen::ElasticElectronMomentsEvaluator(
                                    *pb_data,
                                    0.9 ) );
  }

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
// end tstElasticElectronMomentsEvaluator.cpp
//---------------------------------------------------------------------------//
