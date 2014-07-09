//---------------------------------------------------------------------------//
//!
//! \file   tstIsotopesArray.cpp
//! \author Alex Bennett
//! \brief  Decay Matrix unit test
//!
//---------------------------------------------------------------------------//

// Boost Includes
#include <boost/unordered_map.hpp>

// Trilinos Includes
#include <Teuchos_UnitTestHarness.hpp>
#include <Teuchos_Utils.hpp>
#include <Teuchos_Array.hpp>
#include <Teuchos_UnitTestHarness.hpp>

// FRENSIE Includes
#include "Transmutation_IsotopesArray.hpp"
#include "Transmutation_IsotopesForDepletion.hpp"

//---------------------------------------------------------------------------//
// Testing Variables 
//---------------------------------------------------------------------------//

//---------------------------------------------------------------------------//
// Tests 
//---------------------------------------------------------------------------//
TEUCHOS_UNIT_TEST( IsotopesArray, getOrderedIsotopesArray )
{
   boost::unordered_map<int,double> number_densities; 

   number_densities.insert( std::pair<int,double>(1001,5.0) );
   number_densities.insert( std::pair<int,double>(2004,10.0) );

   Teuchos::Array<double> number_densities_array;

   Transmutation::IsotopesArray::getOrderedIsotopesArray( number_densities , number_densities_array );

   TEST_COMPARE(number_densities_array.length() ,==, 3255);
   TEST_FLOATING_EQUALITY(number_densities_array[0], 5.0, 1e-15);
   TEST_FLOATING_EQUALITY(number_densities_array[8],10.0, 1e-15);
   TEST_FLOATING_EQUALITY(number_densities_array[10],0.0, 1e-15);
   
}

TEUCHOS_UNIT_TEST( IsotopesArray, isIsotopeInList )
{
   TEST_ASSERT( Transmutation::IsotopesArray::isIsotopeInList(1001) );
   TEST_ASSERT( !Transmutation::IsotopesArray::isIsotopeInList(1) );
}

TEUCHOS_UNIT_TEST( IsotopesArray, getIsotopeNumberDensityMap )
{
   boost::unordered_map<int,double> number_densities; 

   number_densities.insert( std::pair<int,double>(1001,5.0) );
   number_densities.insert( std::pair<int,double>(2004,10.0) );

   Teuchos::Array<double> number_densities_array;

   Transmutation::IsotopesArray::getOrderedIsotopesArray( number_densities , number_densities_array );

   Transmutation::IsotopesArray::getIsotopesNumberDensityMap( number_densities, number_densities_array );

   TEST_FLOATING_EQUALITY( number_densities[1001], 5.0, 1e-15)
   TEST_FLOATING_EQUALITY( number_densities[2004],10.0, 1e-15)
}

TEUCHOS_UNIT_TEST( IsotopesArray, getNumberDensityMapFromUnorderedArray )
{
   Teuchos::Array<std::pair<int,double> > unordered_number_densities(2);

   unordered_number_densities[0] = std::pair<int,double> (1001,5.0);
   unordered_number_densities[1] = std::pair<int,double> (2004,10.0);

   boost::unordered_map<int,double> number_densities; 

   Transmutation::IsotopesArray::getNumberDensityMapFromUnorderedArray( number_densities , unordered_number_densities );

   TEST_FLOATING_EQUALITY( number_densities[1001], 5.0, 1e-15)
   TEST_FLOATING_EQUALITY( number_densities[2004],10.0, 1e-15)
}

TEUCHOS_UNIT_TEST( IsotopesArray, getUnorderedArray )
{
   boost::unordered_map<int,double> number_densities; 

   number_densities.insert( std::pair<int,double>(1001,5.0) );
   number_densities.insert( std::pair<int,double>(2004,10.0) );

   Teuchos::Array<double> number_densities_array;

   Transmutation::IsotopesArray::getOrderedIsotopesArray( number_densities , number_densities_array );

   Teuchos::Array<std::pair<int,double> > unordered_number_densities;

   Transmutation::IsotopesArray::getUnorderedArray(unordered_number_densities, number_densities_array);

   TEST_COMPARE( unordered_number_densities.length() ,==, 2 );
   TEST_COMPARE( unordered_number_densities[0].first ,==, 1001 );
   TEST_FLOATING_EQUALITY( unordered_number_densities[0].second, 5.0, 1e-15);
   TEST_COMPARE( unordered_number_densities[1].first ,==, 2004 );
   TEST_FLOATING_EQUALITY( unordered_number_densities[1].second, 10.0, 1e-15);
}
//---------------------------------------------------------------------------//
// Custom Main Function 
//---------------------------------------------------------------------------//
int main( int argc, char** argv )
{
   Teuchos::CommandLineProcessor& clp = Teuchos::UnitTestRepository::getCLP();

   Teuchos::GlobalMPISession mpiSession( &argc, &argv );
   return Teuchos::UnitTestRepository::runUnitTestsFromMain( argc, argv );
}

 
//---------------------------------------------------------------------------//
// end tstIsotopesArray.cpp 
//---------------------------------------------------------------------------//
