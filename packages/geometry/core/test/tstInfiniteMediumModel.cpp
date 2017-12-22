//---------------------------------------------------------------------------//
//!
//! \file   tstInfiniteMediumModel.cpp
//! \author Alex Robinson
//! \brief  Infinite medium model class unit tests
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <iostream>
#include <memory>

// FRENSIE Includes
#include "Geometry_InfiniteMediumModel.hpp"
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
// Tests
//---------------------------------------------------------------------------//
// Check if the model name can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getName )
{
  Geometry::InfiniteMediumModel model;

  FRENSIE_CHECK_EQUAL( model.getName(), "Infinite Medium" );
}

//---------------------------------------------------------------------------//
// Check if the model has cell estimator data
FRENSIE_UNIT_TEST( InfiniteMediumModel, hasCellEstimatorData )
{
  Geometry::InfiniteMediumModel model;

  FRENSIE_CHECK( !model.hasCellEstimatorData() );
}

//---------------------------------------------------------------------------//
// Check that the model material ids can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getMaterialIds )
{
  Geometry::InfiniteMediumModel model;

  Geometry::Model::MaterialIdSet material_ids;

  model.getMaterialIds( material_ids );

  FRENSIE_CHECK( material_ids.empty() );
}

//---------------------------------------------------------------------------//
// Check that the model cells can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getCells )
{
  Geometry::InfiniteMediumModel model( 1 );

  Geometry::Model::CellIdSet cells;

  // Get all cells except for the termination cells
  model.getCells( cells, true, false );

  FRENSIE_CHECK_EQUAL( cells.size(), 1 );
  FRENSIE_CHECK( cells.count( 1 ) );

  cells.clear();

  // Get all cells except the void cells
  model.getCells( cells, false, true );

  FRENSIE_CHECK( cells.empty() );

  cells.clear();
  
  // Get all cells except the void and termination cells
  model.getCells( cells, false, false );

  FRENSIE_CHECK( cells.empty() );

  cells.clear();

  // Get all cells
  model.getCells( cells, true, true );

  FRENSIE_CHECK_EQUAL( cells.size(), 1 );
  FRENSIE_CHECK( cells.count( 1 ) );
}

//---------------------------------------------------------------------------//
// Check that the cell material ids can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getCellMaterialIds )
{
  Geometry::InfiniteMediumModel model( 1 );

  Geometry::Model::CellIdMatIdMap cell_id_mat_id_map;

  model.getCellMaterialIds( cell_id_mat_id_map );

  FRENSIE_CHECK( cell_id_mat_id_map.empty() );
}

//---------------------------------------------------------------------------//
// Check that the cell densities can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getCellDensities )
{
  Geometry::InfiniteMediumModel model( 1 );

  Geometry::Model::CellIdDensityMap cell_id_density_map;

  model.getCellDensities( cell_id_density_map );

  FRENSIE_CHECK( cell_id_density_map.empty() );
}

//---------------------------------------------------------------------------//
// Check that the cell estimator data can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getCellEstimatorData )
{
  Geometry::InfiniteMediumModel model( 1 );

  Geometry::Model::CellEstimatorIdDataMap cell_estimator_id_data_map;

  model.getCellEstimatorData( cell_estimator_id_data_map );

  FRENSIE_CHECK( cell_estimator_id_data_map.empty() );
}

//---------------------------------------------------------------------------//
// Check if a cell exists
FRENSIE_UNIT_TEST( InfiniteMediumModel, doesCellExist )
{
  Geometry::InfiniteMediumModel model( 2 );

  FRENSIE_CHECK( !model.doesCellExist( 1 ) );
  FRENSIE_CHECK( model.doesCellExist( 2 ) );
  FRENSIE_CHECK( !model.doesCellExist( 3 ) );
}

//---------------------------------------------------------------------------//
// Check if the cell is a termination cell
FRENSIE_UNIT_TEST( InfiniteMediumModel, isTerminationCell )
{
  Geometry::InfiniteMediumModel model( 2 );

  FRENSIE_CHECK( !model.isTerminationCell( 2 ) );
}

//---------------------------------------------------------------------------//
// Check if the cell is a void cell
FRENSIE_UNIT_TEST( InfiniteMediumModel, isVoidCell )
{
  Geometry::InfiniteMediumModel model( 3 );
  
  FRENSIE_CHECK( model.isVoidCell( 3 ) );
}

//---------------------------------------------------------------------------//
// Check if the cell volume can be returned
FRENSIE_UNIT_TEST( InfiniteMediumModel, getCellVolume )
{
  Geometry::InfiniteMediumModel model( 1 );

  FRENSIE_CHECK_EQUAL( model.getCellVolume( 1 ),
                       std::numeric_limits<double>::infinity() );
}

//---------------------------------------------------------------------------//
// Check that a navigator can be created
FRENSIE_UNIT_TEST( InfiniteMediumModel, createNavigatorAdvanced )
{
  Geometry::InfiniteMediumModel model;
  
  std::shared_ptr<Geometry::InfiniteMediumNavigator> navigator(
                                             model.createNavigatorAdvanced() );

  FRENSIE_CHECK( navigator.get() != NULL );
}

//---------------------------------------------------------------------------//
// Check that a navigator can be created
FRENSIE_UNIT_TEST( InfiniteMediumModel, createNavigator )
{
  Geometry::InfiniteMediumModel model;
  
  std::shared_ptr<Geometry::Navigator> navigator = model.createNavigator();

  FRENSIE_CHECK( navigator.get() != NULL );
}

//---------------------------------------------------------------------------//
// Check that the navigator can be archived
FRENSIE_UNIT_TEST_TEMPLATE_EXPAND( InfiniteMediumModel,
                                   archive,
                                   TestArchives )
{
  FETCH_TEMPLATE_PARAM( 0, RawOArchive );
  FETCH_TEMPLATE_PARAM( 1, RawIArchive );

  typedef typename std::remove_pointer<RawOArchive>::type OArchive;
  typedef typename std::remove_pointer<RawIArchive>::type IArchive;

  std::string archive_base_name( "test_infinite_medium_model" );
  std::ostringstream archive_ostream;

  // Create and archive some infinite medium models
  {
    std::unique_ptr<OArchive> oarchive;

    createOArchive( archive_base_name, archive_ostream, oarchive );

    Geometry::InfiniteMediumModel model( 1 );

    std::unique_ptr<Geometry::Model> unique_model( new Geometry::InfiniteMediumModel( 2 ) );

    std::shared_ptr<Geometry::Model> shared_model( new Geometry::InfiniteMediumModel( 3 ) );

    FRENSIE_REQUIRE_NO_THROW( (*oarchive) << BOOST_SERIALIZATION_NVP( model ) );
    FRENSIE_REQUIRE_NO_THROW( (*oarchive) << BOOST_SERIALIZATION_NVP( unique_model ) );
    FRENSIE_REQUIRE_NO_THROW( (*oarchive) << BOOST_SERIALIZATION_NVP( shared_model ) );
  }

  // Copy the archive ostream to an istream
  std::istringstream archive_istream( archive_ostream.str() );

  // Load the archived distributions
  std::unique_ptr<IArchive> iarchive;

  createIArchive( archive_istream, iarchive );

  Geometry::InfiniteMediumModel model( 100 );

  FRENSIE_REQUIRE_NO_THROW( (*iarchive) >> BOOST_SERIALIZATION_NVP( model ) );
  FRENSIE_CHECK( model.doesCellExist( 1 ) );
  FRENSIE_CHECK( !model.doesCellExist( 100 ) );

  std::unique_ptr<Geometry::Model> unique_model;

  FRENSIE_REQUIRE_NO_THROW( (*iarchive) >> BOOST_SERIALIZATION_NVP( unique_model ) );
  FRENSIE_CHECK( unique_model->doesCellExist( 2 ) );
  
  std::shared_ptr<Geometry::Model> shared_model;

  FRENSIE_REQUIRE_NO_THROW( (*iarchive) >> BOOST_SERIALIZATION_NVP( shared_model ) );
  FRENSIE_CHECK( shared_model->doesCellExist( 3 ) );
}

//---------------------------------------------------------------------------//
// end tstInfiniteMediumModel.cpp
//---------------------------------------------------------------------------//
