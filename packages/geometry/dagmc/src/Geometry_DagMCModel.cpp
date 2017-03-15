//---------------------------------------------------------------------------//
//!
//! \file   Geometry_DagMCModel.cpp
//! \author Alex Robinson
//! \brief  DagMC model class definition
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <exception>
#include <unordered_set>

// FRENSIE Includes
#include "Geometry_DagMCModel.hpp"
#include "Geometry_StandardDagMCCellHandler.hpp"
#include "Geometry_FastDagMCCellHandler.hpp"
#include "Geometry_StandardDagMCSurfaceHandler.hpp"
#include "Geometry_FastDagMCSurfaceHandler.hpp"
#include "Geometry_DagMCLoggingMacros.hpp"
#include "Utility_3DCartesianVectorHelpers.hpp"
#include "Utility_MOABException.hpp"
#include "Utility_ExceptionCatchMacros.hpp"
#include "Utility_ContractException.hpp"

namespace Geometry{

// Initialize static member data
std::shared_ptr<DagMCModel> DagMCModel::s_instance;

// Get the DagMC instance
std::shared_ptr<DagMCModel> DagMCModel::getInstance()
{
  // Just-in-time initialization
  if( !s_instance )
    s_instance.reset( new DagMCModel );

  return s_instance;
}

// Constructor
DagMCModel::DagMCModel()
  : d_dagmc( NULL ),
    d_cell_handler(),
    d_surface_handler(),
    d_termination_cells(),
    d_reflecting_surfaces(),
    d_model_properties()
{ /* ... */ }

// Check if the DagMC model has been initialized
bool DagMCModel::isInitialized() const
{
  return d_dagmc != NULL;
}

// Initialize the DagMC model
void DagMCModel::initialize( const DagMCModelProperties& model_properties,
                             const bool suppress_dagmc_output )
{
  // Make sure that the model has not been initialized yet
  testPrecondition( !this->isInitialized() );
  
  if( !this->isInitialized() )
  {
    FRENSIE_LOG_DAGMC_NOTIFICATION( "Loading DagMC model "
                                    << d_model_properties->getModelFileName()
                                    << "..." );
    FRENSIE_FLUSH_ALL_LOGS();
    
    // Cache the model properties
    d_model_properties.reset( new DagMCModelProperties( model_properties ) );

    try{
      this->loadDagMCGeometry( suppress_dagmc_output );
    }
    EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                             "Unable to load DagMC geometry file "
                             << d_model_properties->getModelFileName() <<
                             "!" );

    // Validate the properties in the geometry
    try{
      this->validatePropertyNames();
    }
    EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                             "Invalid DagMC geometry properties encountered!" );

    // Parse the properties
    try{
      this->parseProperties();
    }
    EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                             "Unable to parse the DagMC properties!" );
    
    // Construct the cell and surface handlers
    try{
      this->constructEntityHandlers();
    }
    EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                             "Unable to construct the entity handlers!" );
    
    // Extract the termination cells
    try{
      this->extractTerminationCells();
    }
    EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                             "Unable to extract the termination cells!" );
    
    // Get the reflecting surfaces
    try{
      this->extractReflectingSurfaces();
    }
    EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                             "Unable to extract the reflecting surfaces!" );

    FRENSIE_LOG_DAGMC_NOTIFICATION( "Finished loading DagMC model!" );
    FRENSIE_FLUSH_ALL_LOGS();
  }
  // A model has already been loaded - ignore new model
  else
  {
    FRENSIE_LOG_DAGMC_WARNING( "Cannot load requested DagMC model ("
                               << model_properties.getModelFileName() <<
                               ") because a model has already been loaded!" );
  }
}

// validate the properties
void DagMCModel::validatePropertyNames() const
{
  // Get the property names in the DagMC geometry
  std::vector<std::string> properties;

  moab::ErrorCode return_value = d_dagmc->detect_available_props( properties );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
                      InvalidDagMCGeometry,
                      moab::ErrorCodeStr[return_value] );
  
  // Get the valid property names
  std::vector<std::string> valid_properties;
  d_model_properties->getPropertyNames( valid_properties );

  // Record any invalid property names
  std::string invalid_properties;

  for( unsigned i = 0; i < properties.size(); ++i )
  {
    bool valid_property = false;

    for( unsigned j = 0; j < valid_properties.size(); ++j )
    {
      if( properties[i] == valid_properties[j] )
      {
        valid_property = true;

        break;
      }
    }

    if( !valid_property )
    {
      if( invalid_properties.size() > 0 )
        invalid_properties += ", ";

      invalid_properties += properties[i];
    }
  }

  if( invalid_properties.size() > 0 )
  {
    FRENSIE_LOG_DAGMC_WARNING( "Unknown properties were detected in the "
                               "DagMC geometry! Here are the unknown "
                               "properties: " << invalid_properties );
  }
}

// Load the DagMC geometry file
void DagMCModel::loadDagMCGeometry( const bool suppress_dagmc_output )
{
  // Create a new DagMC instance
  d_dagmc = moab::DagMC::instance();

  // Check if DagMC output should be suppressed on initialization
  std::streambuf* cout_streambuf, *cerr_streambuf;
  
  if( suppress_dagmc_output )
  {
    cout_streambuf = std::cout.rdbuf();
    cerr_streambuf = std::cerr.rdbuf();

    std::cout.rdbuf( NULL );
    std::cerr.rdbuf( NULL );
  }

  // Load the geometry
  moab::ErrorCode return_value =
    d_dagmc->load_file( d_model_properties->getModelFileName().c_str(),
                        d_model_properties->getFacetTolerance() );

  // Restore cout and cerr if they were suppressed
  if( suppress_dagmc_output )
  {
    std::cout.rdbuf( cout_streambuf );
    std::cerr.rdbuf( cerr_streambuf );
  }

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
                      InvalidDagMCGeometry,
                      moab::ErrorCodeStr[return_value] );

  if( suppress_dagmc_output )
  {
    cout_streambuf = std::cout.rdbuf();
    cerr_streambuf = std::cerr.rdbuf();

    std::cout.rdbuf( NULL );
    std::cerr.rdbuf( NULL );
  }

  // Initialize the OBB Tree
  return_value = d_dagmc->init_OBBTree();

  // Restore cout and cerr if they were suppressed
  if( suppress_dagmc_output )
  {
    std::cout.rdbuf( cout_streambuf );
    std::cerr.rdbuf( cerr_streambuf );
  }

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
		      InvalidDagMCGeometry,
		      moab::ErrorCodeStr[return_value] );
}

// Parse the properties
void DagMCModel::parseProperties() const
{
  std::vector<std::string> properties;

  d_model_properties->getPropertyNames( properties );

  moab::ErrorCode return_value = d_dagmc->parse_properties( properties );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
                      InvalidDagMCGeometry,
                      moab::ErrorCodeStr[return_value] );
}

// Construct the entity handlers
void DagMCModel::constructEntityHandlers()
{
  if( d_model_properties->isFastIdLookupUsed() )
  {
    try{
      d_cell_handler.reset( new FastDagMCCellHandler( d_dagmc ) );

      d_surface_handler.reset( new FastDagMCSurfaceHandler( d_dagmc ) );
    }
    EXCEPTION_CATCH_RETHROW_AS( Utility::MOABException,
                                InvalidDagMCGeometry,
                                "Unable to set up the model entity "
                                "handlers!" );
  }
  else
  {
    try{
      d_cell_handler.reset( new StandardDagMCCellHandler( d_dagmc ) );

      d_surface_handler.reset( new StandardDagMCSurfaceHandler( d_dagmc ) );
    }
    EXCEPTION_CATCH_RETHROW_AS( Utility::MOABException,
                                InvalidDagMCGeometry,
                                "Unable to set up the problem entity "
                                "handlers!" );
  }
}

// Extract the termination cells
void DagMCModel::extractTerminationCells()
{
  std::vector<moab::EntityHandle> cells_with_property;

  try{
    this->getCellsWithProperty(
                        cells_with_property,
                        d_model_properties->getTerminationCellPropertyName() );
  }
  EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                           "Unable to parse the termination cells!" );
  
  for( unsigned i = 0; i < cells_with_property.size(); ++i )
  {
    d_termination_cells.insert(
                         d_cell_handler->getCellId( cells_with_property[i] ) );
  }

  // Make sure that at least one termination cell has been set
  TEST_FOR_EXCEPTION( d_termination_cells.size() == 0,
                      InvalidDagMCGeometry,
                      "At least one termination cell must be set!" );
}

// Extract the reflecting surfaces
void DagMCModel::extractReflectingSurfaces()
{
  std::vector<moab::EntityHandle> surfaces_with_property;

  try{
    this->getSurfacesWithProperty(
                      surfaces_with_property,
                      d_model_properties->getReflectingSurfacePropertyName() );
  }
  EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                           "Unable to parse the reflecting surfaces!" );

  // Initialize the reflecting surfaces
  d_reflecting_surfaces.reset( new ReflectingSurfaceIdHandleMap );
  
  for( unsigned i = 0; i < surfaces_with_property.size(); ++i )
  {
    ModuleTraits::InternalSurfaceHandle surface_id =
      d_surface_handler->getSurfaceId( surfaces_with_property[i] );
    
    d_reflecting_surfaces->insert( ReflectingSurfaceIdHandleMap::value_type(
                                     surface_id, surfaces_with_property[i] ) );
  }
}

// Get the model properties
const DagMCModelProperties& DagMCModel::getModelProperties() const
{
  return *d_model_properties;
}

// Get the material ids
void DagMCModel::getMaterialIds( MaterialIdSet& material_ids ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  std::vector<std::string> raw_material_ids;

  this->getPropertyValues( d_model_properties->getMaterialPropertyName(),
                           raw_material_ids );

  // Convert the material names to material ids
  for( unsigned i = 0; i < raw_material_ids.size(); ++i )
  {
    TEST_FOR_EXCEPTION( raw_material_ids[i].find_first_not_of( "0123456789" ) <
                        raw_material_ids[i].size(),
                        InvalidDagMCGeometry,
                        "An invalid material id ("
                        << raw_material_ids[i] <<
                        ") was found! " );

    std::istringstream iss( raw_material_ids[i] );

    typename MaterialIdSet::value_type material_id;

    iss >> material_id;

    material_ids.insert( material_id );
  }
}

// Get the problem cells
void DagMCModel::getCells( CellIdSet& cell_set,
                           const bool include_void_cells,
                           const bool include_termination_cells ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  moab::Range::const_iterator cell_handle_it = d_cell_handler->begin();

  while( cell_handle_it != d_cell_handler->end() )
  {
    ModuleTraits::InternalCellHandle cell_id =
      d_cell_handler->getCellId( *cell_handle_it );

    // Check if it is a termination cell
    if( this->isTerminationCell( cell_id ) )
    {
      if( include_termination_cells )
        cell_set.insert( cell_id );
    }
    // Check if it is a void cell
    else if( this->isVoidCell( cell_id ) )
    {
      if( include_void_cells )
        cell_set.insert( cell_id );
    }
    // Cell with material
    else
      cell_set.insert( cell_id );

    ++cell_handle_it;
  }
}

// Get the cell material ids
/*! \details The key type must be a ModuleTraits::InternalCellHandle. The
 * mapped type must be an unsigned int. This method is thread safe as long as
 * enableThreadSupport has been called.
 */
void DagMCModel::getCellMaterialIds( CellIdMatIdMap& cell_id_mat_id_map ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  // Load a map of the cell ids and material names
  std::unordered_map<ModuleTraits::InternalCellHandle,std::vector<std::string> >
    cell_id_mat_name_map;

  try{
    this->getCellPropertyValues( d_model_properties->getMaterialPropertyName(),
                                 cell_id_mat_name_map );
  }
  EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                           "Unable to parse the cell material ids!" );

  // Convert the material names to material ids
  std::unordered_map<ModuleTraits::InternalCellHandle,std::vector<std::string> >::const_iterator
    cell_it = cell_id_mat_name_map.begin();

  while( cell_it != cell_id_mat_name_map.end() )
  {
    TEST_FOR_EXCEPTION( cell_it->second.size() > 1,
                        InvalidDagMCGeometry,
                        "Cell " << cell_it->first << " has multiple "
                        "materials assigned!" );

    TEST_FOR_EXCEPTION(
                    cell_it->second.front().find_first_not_of( "0123456789" ) <
                    cell_it->second.size(),
                    InvalidDagMCGeometry,
                    "Cell " << cell_it->first << " has an invalid "
                    "material id (" << cell_it->second.front() << ")! " );

    std::istringstream iss( cell_it->second.front() );

    iss >> cell_id_mat_id_map[cell_it->first];

    ++cell_it;
  }
}

// Get the cell densities
/*! \details Void and terminal cells will not be added to the map.
 */
void DagMCModel::getCellDensities( CellIdDensityMap& cell_id_density_map ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  // Load a map of the cell ids and density names
  typedef std::unordered_map<ModuleTraits::InternalCellHandle,std::vector<std::string> > CellIdDensityNameMap;
  CellIdDensityNameMap cell_id_density_name_map;

  try{
    this->getCellPropertyValues( d_model_properties->getDensityPropertyName(),
                                 cell_id_density_name_map );
  }
  EXCEPTION_CATCH_RETHROW( InvalidDagMCGeometry,
                           "Unable to parse the cell densities!" );

  // Convert the material names to material ids
  CellIdDensityNameMap::const_iterator cell_it =
    cell_id_density_name_map.begin();

  while( cell_it != cell_id_density_name_map.end() )
  {
    TEST_FOR_EXCEPTION( cell_it->second.size() > 1,
                        InvalidDagMCGeometry,
                        "Cell " << cell_it->first << " has multiple "
                        "densities assigned!" );

    TEST_FOR_EXCEPTION(
                  cell_it->second.front().find_first_not_of( "-.0123456789" ) <
                  cell_it->second.size(),
                  InvalidDagMCGeometry,
                  "Cell " << cell_it->first << " has an invalid "
                  "density (" << cell_it->second.front() << ")! " );

    std::istringstream iss( cell_it->second.front() );

    iss >> cell_id_density_map[cell_it->first];

    ++cell_it;
  }
}

// Get the problem surfaces
void DagMCModel::getSurfaces( SurfaceIdSet& surface_set ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  moab::Range::const_iterator surface_handle_it = d_surface_handler->begin();

  while( surface_handle_it != d_surface_handler->end() )
  {
    ModuleTraits::InternalSurfaceHandle surface_id =
      d_surface_handler->getSurfaceId( *surface_handle_it );

    surface_set.insert( surface_id );

    ++surface_handle_it;
  }
}

// Check if a cell exists
bool DagMCModel::doesCellExist(
                         const ModuleTraits::InternalCellHandle cell_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  return d_cell_handler->doesCellExist( cell_id );
}

// Check if the surface exists
bool DagMCModel::doesSurfaceExist(
                   const ModuleTraits::InternalSurfaceHandle surface_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  return d_surface_handler->doesSurfaceExist( surface_id );
}

// Get the cell volume
double DagMCModel::getCellVolume(
                         const ModuleTraits::InternalCellHandle cell_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  // Make sure the cell exists
  testPrecondition( this->doesCellExist( cell_id ) );

  moab::EntityHandle cell_handle = d_cell_handler->getCellHandle( cell_id );

  double volume = 0.0;

  moab::ErrorCode return_value =
   d_dagmc->measure_volume( cell_handle, volume );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
		      InvalidDagMCGeometry,
		      moab::ErrorCodeStr[return_value] );

  TEST_FOR_EXCEPTION( volume <= 0.0,
                      InvalidDagMCGeometry,
                      "an invalid volume was calculated for cell "
                      << cell_id << "!" );

  return volume;
}

// Get the surface area
double DagMCModel::getSurfaceArea(
                   const ModuleTraits::InternalSurfaceHandle surface_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  // Make sure the cell exists
  testPrecondition( this->doesSurfaceExist( surface_id ) );

  moab::EntityHandle surface_handle =
    d_surface_handler->getSurfaceHandle( surface_id );

  double surface_area = 0.0;

  moab::ErrorCode return_value =
    d_dagmc->measure_area( surface_handle, surface_area );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
		      InvalidDagMCGeometry,
		      moab::ErrorCodeStr[return_value] );

  TEST_FOR_EXCEPTION( surface_area <= 0.0,
                      InvalidDagMCGeometry,
                      "an invalid surface area was calculated for "
                      "surface " << surface_id << "!" );

  return surface_area;
}

// Check if the cell is a termination cell
bool DagMCModel::isTerminationCell(
                         const ModuleTraits::InternalCellHandle cell_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  // Make sure the cell exists
  testPrecondition( this->doesCellExist( cell_id ) );

  return d_termination_cells.find( cell_id ) !=
    d_termination_cells.end();
}

// Check if the cell is a void cell
bool DagMCModel::isVoidCell(
                         const ModuleTraits::InternalCellHandle cell_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  // Make sure the cell exists
  testPrecondition( this->doesCellExist( cell_id ) );

  moab::EntityHandle cell_handle = d_cell_handler->getCellHandle( cell_id );

  return !d_dagmc->has_prop( cell_handle,
                             d_model_properties->getMaterialPropertyName() );
}

// Check if the surface is a reflecting surface
bool DagMCModel::isReflectingSurface(
                   const ModuleTraits::InternalSurfaceHandle surface_id ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  // Make sure the surface exists
  testPrecondition( this->doesSurfaceExist( surface_id ) );

  return d_reflecting_surfaces->left.find( surface_id ) !=
    d_reflecting_surfaces->left.end();
}

// Create a DagMC navigator
std::shared_ptr<DagMCNavigator> DagMCModel::createDagMCNavigator() const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  
  return std::shared_ptr<DagMCNavigator>(
                                 new DagMCNavigator( d_dagmc,
                                                     d_cell_handler,
                                                     d_surface_handler,
                                                     d_reflecting_surfaces ) );
}

// Create a navigator
std::shared_ptr<Navigator> DagMCModel::createNavigator() const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );
  
  return this->createDagMCNavigator();
}

// Get the cells associated with a property name
// Note: If a property value is passed only the cells with both the property
// and value will be returned.
void DagMCModel::getCellsWithProperty(
                                  std::vector<moab::EntityHandle>& cells,
                                  const std::string& property,
                                  const std::string* property_value ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  moab::ErrorCode return_value =
    d_dagmc->entities_by_property( property, cells, 3, property_value );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
                      InvalidDagMCGeometry,
		      moab::ErrorCodeStr[return_value] );
}

// Get the surfaces associated with a property name
// Note: If a property value is passed only the cells with both the property
// and value will be returned.
void DagMCModel::getSurfacesWithProperty(
                                     std::vector<moab::EntityHandle>& surfaces,
                                     const std::string& property,
                                     const std::string* property_value ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  moab::ErrorCode return_value =
    d_dagmc->entities_by_property( property, surfaces, 2, property_value );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
                      InvalidDagMCGeometry,
		      moab::ErrorCodeStr[return_value] );
}

// Get the property values associated with a property name
void DagMCModel::getPropertyValues( const std::string& property,
                                    std::vector<std::string>& values ) const
{
  // Make sure DagMC has been initialized
  testPrecondition( this->isInitialized() );

  // Get all of the property values
  moab::ErrorCode return_value =
    d_dagmc->get_all_prop_values( property, values );

  TEST_FOR_EXCEPTION( return_value != moab::MB_SUCCESS,
		      InvalidDagMCGeometry,
		      moab::ErrorCodeStr[return_value] );
}

}  // end Geometry namespace

//---------------------------------------------------------------------------//
// end Geometry_DagMC.cpp
//---------------------------------------------------------------------------//