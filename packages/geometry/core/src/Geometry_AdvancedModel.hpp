//---------------------------------------------------------------------------//
//!
//! \file   Geometry_Model.hpp
//! \author Alex Robinson
//! \brief  The advanced geometry model base class declaration
//!
//---------------------------------------------------------------------------//

#ifndef GEOMETRY_ADVANCED_MODEL_HPP
#define GEOMETRY_ADVANCED_MODEL_HPP

// FRENSIE Includes
#include "Geometry_Model.hpp"

namespace Geometry{

//! The advanced model base class
class AdvancedModel : public Model
{
  
public:

  //! The surface id set type
  typedef std::set<ModuleTraits::InternalSurfaceHandle> SurfaceIdSet;

  //! The surface id array type
  typedef std::vector<ModuleTraits::InternalSurfaceHandle> SurfaceIdArray;

  //! The surface estimator data type
  typedef std::tuple<EstimatorType,ParticleType,SurfaceIdArray> SurfaceEstimatorData;

  //! surface estimator id data map type
  typedef std::map<ModuleTraits::InternalEstimatorHandle,SurfaceEstimatorData> SurfaceEstimatorIdDataMap;

  //! Constructor
  AdvancedModel()
  { /* ... */ }

  //! Destructor
  virtual ~AdvancedModel()
  { /* ... */ }

  //! Check if this is an advanced model
  bool isAdvanced() const override
  { return true; }

  //! Check if the model has surface estimator data
  virtual bool hasSurfaceEstimatorData() const = 0;

  //! Get the surfaces
  virtual void getSurfaces( SurfaceIdSet& surfaces ) const = 0;

  //! Get the surface estimator data
  virtual void getSurfaceEstimatorData( SurfaceEstimatorIdDataMap& surface_estimator_id_data_map ) const = 0;

  //! Check if a surface exists
  virtual bool doesSurfaceExist(
              const ModuleTraits::InternalSurfaceHandle surface_id ) const = 0;

  //! Get the surface area
  virtual double getSurfaceArea(
              const ModuleTraits::InternalSurfaceHandle surface_id ) const = 0;

  //! Check if the surface is a reflecting surface
  virtual bool isReflectingSurface(
              const ModuleTraits::InternalSurfaceHandle surface_id ) const = 0;

private:

  // Save the model to an archive
  template<typename Archive>
  void save( Archive& ar, const unsigned version ) const
  { ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP( Model ); }

  // Load the model from an archive
  template<typename Archive>
  void load( Archive& ar, const unsigned version )
  { ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP( Model ); }

  BOOST_SERIALIZATION_SPLIT_MEMBER();

  // Declare the boost serialization access object as a friend
  friend class boost::serialization::access;
};
  
} // end Geometry namespace

BOOST_SERIALIZATION_ASSUME_ABSTRACT_CLASS( AdvancedModel, Geometry );
BOOST_SERIALIZATION_CLASS_VERSION( AdvancedModel, Geometry, 0 );

#endif // end GEOMETRY_ADVANCED_MODEL_HPP

//---------------------------------------------------------------------------//
// end Geometry_AdvancedModel.hpp
//---------------------------------------------------------------------------//
