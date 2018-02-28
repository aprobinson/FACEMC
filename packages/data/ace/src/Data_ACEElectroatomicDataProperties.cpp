//---------------------------------------------------------------------------//
//!
//! \file   Data_ACEElectroatomicDataProperties.cpp
//! \author Alex Robinson
//! \brief  The ACE electroatomic data properties class definition
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

// FRENSIE Includes
#include "Data_ACEElectroatomicDataProperties.hpp"
#include "Utility_HDF5IArchive.hpp"
#include "Utility_HDF5OArchive.hpp"
#include "Utility_FromStringTraits.hpp"
#include "Utility_ExceptionTestMacros.hpp"
#include "Utility_ContractException.hpp"

namespace Data{

// Default constructor
ACEElectroatomicDataProperties::ACEElectroatomicDataProperties()
{ /* ... */ }

// Constructor
ACEElectroatomicDataProperties::ACEElectroatomicDataProperties(
                                      const boost::filesystem::path& file_path,
                                      const size_t file_start_line,
                                      const ACETableName& file_table_name )
  : d_file_path( file_path ),
    d_file_start_line( file_start_line ),
    d_file_table_name( file_table_name )
{
  // Make sure that the file path is valid
  testPrecondition( !file_path.string().empty() );

  // Convert to the preferred path format
  d_file_path.make_preferred();

  if( d_file_table_name.typeKey() == 'e' )
  {
    TEST_FOR_EXCEPTION( d_file_table_name.version() > 12,
                        std::runtime_error,
                        "The electroatomic table version is not supported!" );
  }
  else if( d_file_table_name.typeKey() == 'p' )
  {
    TEST_FOR_EXCEPTION( d_file_table_name.version() < 12,
                        std::runtime_error,
                        "The electroatomic table version is not supported!" );
  }
  else
  {
    THROW_EXCEPTION( std::runtime_error,
                     "Table " << file_table_name << " is unsupported!" );
  }
}

// Copy constructor
ACEElectroatomicDataProperties::ACEElectroatomicDataProperties(
                                  const ACEElectroatomicDataProperties& other )
  : d_file_path( other.d_file_path ),
    d_file_start_line( other.d_file_start_line ),
    d_file_table_name( other.d_file_table_name )
{
  // Convert to the preferred path format
  d_file_path.make_preferred();
}

// Get the atom that the file specifies data for
AtomType ACEElectroatomicDataProperties::atom() const
{
  return d_file_table_name.zaid().atom();
}

// Get the electroatomic data file type
auto ACEElectroatomicDataProperties::fileType() const -> FileType
{
  if( d_file_table_name.version() < 12 )
    return ElectroatomicDataProperties::ACE_FILE;
  else
    return ElectroatomicDataProperties::ACE_EPR_FILE;
}

// Get the electroatomic data file path (relative to the data directory)
boost::filesystem::path ACEElectroatomicDataProperties::filePath() const
{
  return d_file_path;
}

// Get the electroatomic data file start line
size_t ACEElectroatomicDataProperties::fileStartLine() const
{
  return d_file_start_line;
}

// Get the photoatomic data file version
unsigned ACEElectroatomicDataProperties::fileVersion() const
{
  return d_file_table_name.version();
}

// Get the electroatomic table name
std::string ACEElectroatomicDataProperties::tableName() const
{
  return d_file_table_name.toRaw();
}

// Clone the properties
ACEElectroatomicDataProperties* ACEElectroatomicDataProperties::clone() const
{
  return new ACEElectroatomicDataProperties( *this );
}

// Save the properties to an archive
template<typename Archive>
void ACEElectroatomicDataProperties::save( Archive& ar, const unsigned version ) const
{
  // Save the base class first
  ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP( ElectroatomicDataProperties );

  // Save the local member data
  std::string raw_path = d_file_path.string();
  
  ar & BOOST_SERIALIZATION_NVP( raw_path );
  ar & BOOST_SERIALIZATION_NVP( d_file_start_line );
  ar & BOOST_SERIALIZATION_NVP( d_file_table_name );
}

// Load the properties from an archive
template<typename Archive>
void ACEElectroatomicDataProperties::load( Archive& ar, const unsigned version )
{
  // Load the base class first
  ar & BOOST_SERIALIZATION_BASE_OBJECT_NVP( ElectroatomicDataProperties );

  // Load the local member data
  std::string raw_path;  
  ar & BOOST_SERIALIZATION_NVP( raw_path );

  d_file_path = raw_path;
  d_file_path.make_preferred();
  
  ar & BOOST_SERIALIZATION_NVP( d_file_start_line );
  ar & BOOST_SERIALIZATION_NVP( d_file_table_name );
}

EXPLICIT_DATA_CLASS_SAVE_LOAD_INST( ACEElectroatomicDataProperties );

} // end Data namespace

BOOST_SERIALIZATION_CLASS_EXPORT_IMPLEMENT( ACEElectroatomicDataProperties, Data );

//---------------------------------------------------------------------------//
// end Data_ACEElectroatomicDataProperties.cpp
//---------------------------------------------------------------------------//