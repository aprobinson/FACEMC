//---------------------------------------------------------------------------//
//!
//! \file   Geometry_RootModelProperties.cpp
//! \author Alex Robinson
//! \brief  Root model properties class definition
//!
//---------------------------------------------------------------------------//

// Boost Includes
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/polymorphic_oarchive.hpp>
#include <boost/archive/polymorphic_iarchive.hpp>
#include <boost/serialization/string.hpp>

// FRENSIE Includes
#include "Geometry_RootModelProperties.hpp"
#include "Utility_HDF5IArchive.hpp"
#include "Utility_HDF5OArchive.hpp"
#include "Utility_ContractException.hpp"

namespace Geometry{

// Default constructor
RootModelProperties::RootModelProperties()
  : RootModelProperties( "dummy" )
{ /* ... */ }

// Constructor
RootModelProperties::RootModelProperties( const std::string& filename )
  : d_file_name( filename ),
    d_material_property_name( "mat" ),
    d_void_material_name( "void" ),
    d_terminal_material_name( "graveyard" )
{
  // Make sure that the file name is valid
  testPrecondition( filename.size() > 0 );
}

// Get the model file name
const std::string& RootModelProperties::getModelFileName() const
{
  return d_file_name;
}

// Get the material property name
const std::string& RootModelProperties::getMaterialPropertyName() const
{
  return d_material_property_name;
}

// Set the material property name
void RootModelProperties::setMaterialPropertyName(
                                    const std::string& material_property_name )
{
  // Make sure that the material property name is valid
  testPrecondition( material_property_name.size() > 0 );

  d_material_property_name = material_property_name;
}

// Get the void material property name
const std::string& RootModelProperties::getVoidMaterialName() const
{
  return d_void_material_name;
}

// Set the void material property name
void RootModelProperties::setVoidMaterialName(
                                        const std::string& void_material_name )
{
  // Make sure that the void material name is valid
  testPrecondition( void_material_name.size() > 0 );
  
  d_void_material_name = void_material_name;
}

// Get the terminal material property name
const std::string& RootModelProperties::getTerminalMaterialName() const
{
  return d_terminal_material_name;
}

// Set the terminal material property name
void RootModelProperties::setTerminalMaterialName(
                                    const std::string& terminal_material_name )
{
  // Make sure that the terminal material name is valid
  testPrecondition( terminal_material_name.size() > 0 );
  
  d_terminal_material_name = terminal_material_name;
}

// Save the model to an archive
template<typename Archive>
void RootModelProperties::save( Archive& ar, const unsigned version ) const
{
  ar & BOOST_SERIALIZATION_NVP( d_file_name );
  ar & BOOST_SERIALIZATION_NVP( d_material_property_name );
  ar & BOOST_SERIALIZATION_NVP( d_void_material_name );
  ar & BOOST_SERIALIZATION_NVP( d_terminal_material_name );
}

// Load the model from an archive
template<typename Archive>
void RootModelProperties::load( Archive& ar, const unsigned version )
{
  ar & BOOST_SERIALIZATION_NVP( d_file_name );
  ar & BOOST_SERIALIZATION_NVP( d_material_property_name );
  ar & BOOST_SERIALIZATION_NVP( d_void_material_name );
  ar & BOOST_SERIALIZATION_NVP( d_terminal_material_name );
}

EXPLICIT_GEOMETRY_CLASS_SAVE_LOAD_INST( RootModelProperties );
  
} // end Geometry namespace

BOOST_SERIALIZATION_CLASS_EXPORT_IMPLEMENT( RootModelProperties, Geometry );

//---------------------------------------------------------------------------//
// end Geometry_RootModelProperties.cpp
//---------------------------------------------------------------------------//