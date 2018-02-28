//---------------------------------------------------------------------------//
//!
//! \file   tstRootModelProperties.cpp
//! \author Alex Robinson
//! \brief  Root model properties class unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>
#include <algorithm>

// FRENSIE Includes
#include "Geometry_RootModelProperties.hpp"
#include "Utility_UnitTestHarnessWithMain.hpp"
#include "ArchiveTestHelpers.hpp"

//---------------------------------------------------------------------------//
// Testing Types
//---------------------------------------------------------------------------//

typedef std::tuple<
  std::tuple<boost::archive::xml_oarchive,boost::archive::xml_iarchive>,
  std::tuple<boost::archive::text_oarchive,boost::archive::text_iarchive>,
  std::tuple<boost::archive::binary_oarchive,boost::archive::binary_iarchive>,
  std::tuple<Utility::HDF5OArchive,Utility::HDF5IArchive>,
  std::tuple<boost::archive::polymorphic_oarchive*,boost::archive::polymorphic_iarchive*>
  > TestArchives;

//---------------------------------------------------------------------------//
// Tests.
//---------------------------------------------------------------------------//
// Check that the default properties are correct
FRENSIE_UNIT_TEST( RootModelProperties, default_properties )
{
  const Geometry::RootModelProperties default_properties( "dummy.c" );

  FRENSIE_CHECK_EQUAL( default_properties.getMaterialPropertyName(), "mat" );
  FRENSIE_CHECK_EQUAL( default_properties.getVoidMaterialName(), "void" );
  FRENSIE_CHECK_EQUAL( default_properties.getTerminalMaterialName(), "graveyard" );
}

//---------------------------------------------------------------------------//
// Check that the file name can be returned
FRENSIE_UNIT_TEST( RootModelProperties, getModelFileName )
{
  const Geometry::RootModelProperties properties( "dummy.c" );

  FRENSIE_CHECK_EQUAL( properties.getModelFileName(), "dummy.c" );
}

//---------------------------------------------------------------------------//
// Check that the material property name can be set
FRENSIE_UNIT_TEST( RootModelProperties, setMaterialPropertyName )
{
  Geometry::RootModelProperties properties( "dummy.c" );
  properties.setMaterialPropertyName( "fill" );

  FRENSIE_CHECK_EQUAL( properties.getMaterialPropertyName(), "fill" );
}

//---------------------------------------------------------------------------//
// Check that the void material name can be set
FRENSIE_UNIT_TEST( RootModelProperties, setVoidMaterialName )
{
  Geometry::RootModelProperties properties( "dummy.c" );
  properties.setVoidMaterialName( "empty" );

  FRENSIE_CHECK_EQUAL( properties.getVoidMaterialName(), "empty" );
}

//---------------------------------------------------------------------------//
// Check that the terminal material name can be set
FRENSIE_UNIT_TEST( RootModelProperties, setTerminalMaterialName )
{
  Geometry::RootModelProperties properties( "dummy.c" );
  properties.setTerminalMaterialName( "blackhole" );

  FRENSIE_CHECK_EQUAL( properties.getTerminalMaterialName(), "blackhole" );
}

//---------------------------------------------------------------------------//
// Check that the properties can be archived
FRENSIE_UNIT_TEST_TEMPLATE_EXPAND( RootModelProperties,
                                   archive,
                                   TestArchives )
{
  FETCH_TEMPLATE_PARAM( 0, RawOArchive );
  FETCH_TEMPLATE_PARAM( 1, RawIArchive );

  typedef typename std::remove_pointer<RawOArchive>::type OArchive;
  typedef typename std::remove_pointer<RawIArchive>::type IArchive;

  std::string archive_base_name( "test_dagmc_model_properties" );
  std::ostringstream archive_ostream;

  // Create and archive some properties
  {
    std::unique_ptr<OArchive> oarchive;

    createOArchive( archive_base_name, archive_ostream, oarchive );

    Geometry::RootModelProperties properties( "dummy.root" );
    
    properties.setMaterialPropertyName( "fill" );
    properties.setVoidMaterialName( "empty" );
    properties.setTerminalMaterialName( "graveyard" );

    FRENSIE_REQUIRE_NO_THROW( (*oarchive) << BOOST_SERIALIZATION_NVP( properties ) );
  }

  // Copy the archive ostream to an istream
  std::istringstream archive_istream( archive_ostream.str() );

  // Load the archived distributions
  std::unique_ptr<IArchive> iarchive;

  createIArchive( archive_istream, iarchive );

  Geometry::RootModelProperties properties( "?.root" );

  FRENSIE_REQUIRE_NO_THROW( (*iarchive) >> BOOST_SERIALIZATION_NVP( properties ) );
  
  FRENSIE_CHECK_EQUAL( properties.getModelFileName(), "dummy.root" );
  FRENSIE_CHECK_EQUAL( properties.getVoidMaterialName(), "empty" );
  FRENSIE_CHECK_EQUAL( properties.getTerminalMaterialName(), "graveyard" );
}

//---------------------------------------------------------------------------//
// end tstRootModelProperties.cpp
//---------------------------------------------------------------------------//