//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_FilledGeometryModel.cpp
//! \author Alex Robinson
//! \brief  The filled geometry model class definition
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <stdexcept>

// FRENSIE Includes
#include "MonteCarlo_FilledGeometryModel.hpp"
#include "MonteCarlo_AtomicRelaxationModelFactory.hpp"
#include "MonteCarlo_ParticleModeTypeTraits.hpp"
#include "Utility_ExceptionTestMacros.hpp"
#include "Utility_ExceptionCatchMacros.hpp"

namespace MonteCarlo{

// Constructor
FilledGeometryModel::FilledGeometryModel(
       const boost::filesystem::path& database_path,
       const ScatteringCenterDefinitionDatabase& scattering_center_definitions,
       const MaterialDefinitionDatabase& material_definitions,
       const SimulationProperties& properties,
       const std::shared_ptr<const Geometry::Model>& geometry_model,
       const bool verbose_construction )
  : FilledNeutronGeometryModel( geometry_model ),
    FilledPhotonGeometryModel( geometry_model ),
    FilledAdjointPhotonGeometryModel( geometry_model ),
    FilledElectronGeometryModel( geometry_model ),
    FilledAdjointElectronGeometryModel( geometry_model ),
    FilledPositronGeometryModel( geometry_model ),
    d_unfilled_model( geometry_model )
{
  // Get the material ids defined in the geometry
  Geometry::Model::MaterialIdSet required_material_ids;

  geometry_model->getMaterialIds( required_material_ids );

  // Check that the required material ids are valid
  Geometry::Model::MaterialIdSet::const_iterator required_material_id_it =
    required_material_ids.begin();

  while( required_material_id_it != required_material_ids.end() )
  {
    TEST_FOR_EXCEPTION( !material_definitions.doesDefinitionExist( *required_material_id_it ),
                        std::runtime_error,
                        "No definition for material "
                        << *required_material_id_it << " has been defined!" );

    ++required_material_id_it;
  }

  std::cout << "required materials: " << required_material_ids << std::endl;

  // Check for extraneous user-defined materials
  MaterialDefinitionDatabase::MaterialDefinitionIterator
    database_material_id_it = material_definitions.begin();

  std::cout << material_definitions.getDefinition( 2 ) << std::endl;

  while( database_material_id_it != material_definitions.end() )
  {
    if( required_material_ids.find( database_material_id_it->first ) ==
        required_material_ids.end() )
    {
      FRENSIE_LOG_TAGGED_WARNING( "FilledGeometryModel",
                                  "Material "
                                  << database_material_id_it->first <<
                                  " is not used!" );
    }

    ++database_material_id_it;
  }

  // Get the unique scattering center names used by materials
  MaterialDefinitionDatabase::ScatteringCenterNameSet
    unique_scattering_center_names;

  material_definitions.getUniqueScatteringCenterNames(
                                              required_material_ids,
                                              unique_scattering_center_names );

  // Check that every scattering center has a definition
  MaterialDefinitionDatabase::ScatteringCenterNameSet::const_iterator
    unique_scattering_center_names_it = unique_scattering_center_names.begin();

  while( unique_scattering_center_names_it != unique_scattering_center_names.end() )
  {
    TEST_FOR_EXCEPTION( !scattering_center_definitions.doesDefinitionExist( *unique_scattering_center_names_it ),
                        std::runtime_error,
                        "Scattering center "
                        << *unique_scattering_center_names_it <<
                        " is not defined!" );

    ++unique_scattering_center_names_it;
  }

  // Create the cell id data maps
  Geometry::Model::CellIdMatIdMap cell_id_mat_id_map;
  Geometry::Model::CellIdDensityMap cell_id_density_map;

  geometry_model->getCellMaterialIds( cell_id_mat_id_map );
  geometry_model->getCellDensities( cell_id_density_map );

  Geometry::Model::CellIdMatIdMap::const_iterator cell_id_mat_id_it =
    cell_id_mat_id_map.begin();

  // Make sure that the maps have the same size
  while( cell_id_mat_id_it != cell_id_mat_id_map.end() )
  {
    TEST_FOR_EXCEPTION( cell_id_density_map.find( cell_id_mat_id_it->first ) ==
                        cell_id_density_map.end(),
                        std::runtime_error,
                        "Cell " << cell_id_mat_id_it->first <<
                        " has a material id assigned in the geometry model "
                        "but not a density!" );

    ++cell_id_mat_id_it;
  }

  Geometry::Model::CellIdDensityMap::const_iterator cell_id_density_it =
    cell_id_density_map.begin();

  while( cell_id_density_it != cell_id_density_map.end() )
  {
    TEST_FOR_EXCEPTION( cell_id_mat_id_map.find( cell_id_density_it->first ) ==
                        cell_id_mat_id_map.end(),
                        std::runtime_error,
                        "Cell " << cell_id_density_it->first <<
                        " has a density assigned in the geometry model but "
                        "not a material!" );

    ++cell_id_density_it;
  }

  // Initialize an atomic relaxation model factory
  std::shared_ptr<AtomicRelaxationModelFactory>
    atomic_relaxation_model_factory( new AtomicRelaxationModelFactory );

  // Only load the particle materials required by the simulation mode
  ParticleModeType mode = properties.getParticleMode();

  // Load the neutron materials
  if( MonteCarlo::isParticleTypeCompatible( mode, NEUTRON ) )
  {
    try{
      FilledNeutronGeometryModel::loadMaterialsAndFillModel(
                                               database_path,
                                               unique_scattering_center_names,
                                               scattering_center_definitions,
                                               atomic_relaxation_model_factory,
                                               properties,
                                               verbose_construction,
                                               material_definitions,
                                               cell_id_mat_id_map,
                                               cell_id_density_map );
    }
    EXCEPTION_CATCH_RETHROW( std::runtime_error,
                             "Could not fill the model with neutron "
                             "materials!" );
  }

  // Load the photon materials
  if( MonteCarlo::isParticleTypeCompatible( mode, PHOTON ) )
  {
    try{
      FilledPhotonGeometryModel::loadMaterialsAndFillModel(
                                               database_path,
                                               unique_scattering_center_names,
                                               scattering_center_definitions,
                                               atomic_relaxation_model_factory,
                                               properties,
                                               verbose_construction,
                                               material_definitions,
                                               cell_id_mat_id_map,
                                               cell_id_density_map );
    }
    EXCEPTION_CATCH_RETHROW( std::runtime_error,
                             "Could not fill the model with photon "
                             "materials!" );
  }

  // Load the adjoint photon materials
  if( MonteCarlo::isParticleTypeCompatible( mode, ADJOINT_PHOTON ) )
  {
    try{
      FilledAdjointPhotonGeometryModel::loadMaterialsAndFillModel(
                                               database_path,
                                               unique_scattering_center_names,
                                               scattering_center_definitions,
                                               atomic_relaxation_model_factory,
                                               properties,
                                               verbose_construction,
                                               material_definitions,
                                               cell_id_mat_id_map,
                                               cell_id_density_map );
    }
    EXCEPTION_CATCH_RETHROW( std::runtime_error,
                             "Could not fill the model with adjoint photon "
                             "materials!" );
  }

  // Load the electron materials
  if( MonteCarlo::isParticleTypeCompatible( mode, ELECTRON ) )
  {
    try{
      FilledElectronGeometryModel::loadMaterialsAndFillModel(
                                               database_path,
                                               unique_scattering_center_names,
                                               scattering_center_definitions,
                                               atomic_relaxation_model_factory,
                                               properties,
                                               verbose_construction,
                                               material_definitions,
                                               cell_id_mat_id_map,
                                               cell_id_density_map );
    }
    EXCEPTION_CATCH_RETHROW( std::runtime_error,
                             "Could not fill the model with electron "
                             "materials!" );

    try{
      FilledPositronGeometryModel::loadMaterialsAndFillModel(
                                               database_path,
                                               unique_scattering_center_names,
                                               scattering_center_definitions,
                                               atomic_relaxation_model_factory,
                                               properties,
                                               verbose_construction,
                                               material_definitions,
                                               cell_id_mat_id_map,
                                               cell_id_density_map );
    }
    EXCEPTION_CATCH_RETHROW( std::runtime_error,
                             "Could not fill the model with positron "
                             "materials!" );
  }

  // Load the adjoint electron materials
  if( MonteCarlo::isParticleTypeCompatible( mode, ADJOINT_ELECTRON ) )
  {
    try{
      FilledAdjointElectronGeometryModel::loadMaterialsAndFillModel(
                                               database_path,
                                               unique_scattering_center_names,
                                               scattering_center_definitions,
                                               atomic_relaxation_model_factory,
                                               properties,
                                               verbose_construction,
                                               material_definitions,
                                               cell_id_mat_id_map,
                                               cell_id_density_map );
    }
    EXCEPTION_CATCH_RETHROW( std::runtime_error,
                             "Could not fill the model with adjoint electron "
                             "materials!" );
  }
}
  
// Check if a cell is void
bool FilledGeometryModel::isCellVoid(
                           const Geometry::Model::InternalCellHandle cell,
                           const MonteCarlo::ParticleType particle_type ) const
{
  switch( particle_type )
  {
  case NEUTRON:
    return FilledNeutronGeometryModel::isCellVoid( cell );
  case PHOTON:
    return FilledPhotonGeometryModel::isCellVoid( cell );
  case ADJOINT_PHOTON:
    return FilledAdjointPhotonGeometryModel::isCellVoid( cell );
  case ELECTRON:
    return FilledElectronGeometryModel::isCellVoid( cell );
  case ADJOINT_ELECTRON:
    return FilledAdjointElectronGeometryModel::isCellVoid( cell );
  case POSITRON:
    return FilledPositronGeometryModel::isCellVoid( cell );
  default:
    THROW_EXCEPTION( std::logic_error,
                     "Particle type " << particle_type <<
                     " is not recognized by the collision kernel!" );
  }
}

// Convert to a const unfilled model reference
FilledGeometryModel::operator const Geometry::Model&() const
{
  return *d_unfilled_model;
}

// Convert to a shared unfilled model
FilledGeometryModel::operator std::shared_ptr<const Geometry::Model>() const
{
  return d_unfilled_model;
}
  
} // end MonteCarlo namespace

//---------------------------------------------------------------------------//
// end MonteCarlo_FilledGeometryModel.cpp
//---------------------------------------------------------------------------//
