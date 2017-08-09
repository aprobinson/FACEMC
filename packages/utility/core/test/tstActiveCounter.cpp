//---------------------------------------------------------------------------//
//!
//! \file   tstActiveCounter.hpp
//! \author Alex Robinson
//! \brief  Active counter unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>
#include <memory>

// Trilinos Includes
#include <Teuchos_UnitTestHarness.hpp>

// FRENSIE Includes
#include "Utility_ActiveCounter.hpp"
#include "Utility_UnitTestHarnessExtensions.hpp"

//---------------------------------------------------------------------------//
// Instantiation macros
//---------------------------------------------------------------------------//
#define UNIT_TEST_INSTANTIATION( type, name )   \
  typedef unsigned long long uint64;            \
  typedef unsigned long uint32;                 \
  TEUCHOS_UNIT_TEST_TEMPLATE_1_INSTANT( type, name, unsigned )		\
  TEUCHOS_UNIT_TEST_TEMPLATE_1_INSTANT( type, name, uint32 )		\
  TEUCHOS_UNIT_TEST_TEMPLATE_1_INSTANT( type, name, uint64 )            \
  TEUCHOS_UNIT_TEST_TEMPLATE_1_INSTANT( type, name, double )

//---------------------------------------------------------------------------//
// Tests.
//---------------------------------------------------------------------------//
// Check that the counter can be incremented
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, increment, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter( new Utility::ActiveCounter<T> );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 0 ) );

  counter->increment();

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 1 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, increment );

//---------------------------------------------------------------------------//
// Check that the counter can be pre-incremented
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, preincrement, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter( new Utility::ActiveCounter<T> );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 0 ) );

  ++(*counter);

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 1 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, preincrement );

//---------------------------------------------------------------------------//
// Check that a value can be added to the counter
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, addToCount_raw, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter( new Utility::ActiveCounter<T> );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 0 ) );

  counter->addToCount( static_cast<T>( 2 ) );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 2 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, addToCount_raw );

//---------------------------------------------------------------------------//
// Check that the assignment operator can be used
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, assignment_raw, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter( new Utility::ActiveCounter<T> );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 0 ) );

  (*counter) += static_cast<T>( 2 );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 2 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, assignment_raw );

//---------------------------------------------------------------------------//
// Check that two counters can be added
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, addToCount, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter_a( new Utility::ActiveCounter<T> );

  std::shared_ptr<Utility::Counter<T> >
    counter_b( new Utility::ActiveCounter<T> );

  ++(*counter_a);

  *counter_b += static_cast<T>( 2 );

  counter_a->addToCount( *counter_b );

  TEST_EQUALITY_CONST( counter_a->getCount(), static_cast<T>( 3 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, addToCount );

//---------------------------------------------------------------------------//
// Check that two counters can be added
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, assignment, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter_a( new Utility::ActiveCounter<T> );

  std::shared_ptr<Utility::Counter<T> >
    counter_b( new Utility::ActiveCounter<T> );

  ++(*counter_a);

  *counter_b += static_cast<T>( 2 );

  *counter_a += *counter_b;

  TEST_EQUALITY_CONST( counter_a->getCount(), static_cast<T>( 3 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, assignment );

//---------------------------------------------------------------------------//
// Check that the implicit conversion operator can be used
TEUCHOS_UNIT_TEST_TEMPLATE_1_DECL( ActiveCounter, implicit_conversion, T )
{
  std::shared_ptr<Utility::Counter<T> >
    counter( new Utility::ActiveCounter<T> );

  TEST_EQUALITY_CONST( counter->getCount(), static_cast<T>( 0 ) );

  T raw_counter = *counter;

  TEST_EQUALITY_CONST( raw_counter, static_cast<T>( 0 ) );
}

UNIT_TEST_INSTANTIATION( ActiveCounter, implicit_conversion );

//---------------------------------------------------------------------------//
// end tstActiveCounter.cpp
//---------------------------------------------------------------------------//