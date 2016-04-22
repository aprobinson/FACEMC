//---------------------------------------------------------------------------//
//!
//! \file   Data_ACE.i
//! \author Alex Robinson
//! \brief  The ACE subpackage interface file
//!
//---------------------------------------------------------------------------//

%{
// PyTrilinos Includes
#define NO_IMPORT_ARRAY
#include "numpy_include.h"

// FRENSIE Includes
#include "PyFrensie_TeuchosArrayConversionHelpers.hpp"
#include "Data_ACEFileHandler.hpp"
#include "Data_XSSNeutronDataExtractor.hpp"
#include "Data_XSSEPRDataExtractor.hpp"
%}

// Include std::string support
%include <std_string.i>

// Include Teuchos::Array support
#define TEUCHOSCORE_LIB_DLL_EXPORT
%include <Teuchos_Array.i>
#undef TEUCHOSCORE_LIB_DLL_EXPORT

// Import the PyFrensie Teuchos Array conversion helpers
%import "PyFrensie_TeuchosArrayConversionHelpers.hpp"

// Include the Teuchos::ArrayRCP support
%include "PyFrensie_ArrayRCP.i"

//---------------------------------------------------------------------------//
// Add support for the ACEFileHandler
//---------------------------------------------------------------------------//
// Add a more detailed docstrings for the ACEFileHandler
%feature("docstring")
Data::ACEFileHandler
"
The ACEFileHandler can be used to read in any ACE table and extract
the NXS array, JXS array and XSS array. Usually, these arrays are then
passed to one of the XSSDataExtractor classes to extract the individual 
data blocks from the XSS array. A brief usage tutorial for this class is
shown below:

  import PyFrensie.Data, PyTrilinos.Teuchos, numpy
  
  source = PyTrilinos.Teuchos.FileInputSource( 'datadir/cross_sections.xml' )
  xml_obj = source.getObject()
  cs_list = PyTrilinos.Teuchos.XMLParameterListReader().toParameterList( xml_obj )
  
  h_data_list = cs_list.get( 'H' )
  h_ace_file_name = 'datadir' + h_data_list.get( 'photoatomic_file_path' )

  h_ace_file = PyFrensie.Data.ACEFileHandler( h_ace_file_name, h_data_list.get( 'photoatomic_table_name' ), h_data_list.get( 'photoatomic_file_start_line' ) )
  
  nxs_array = h_ace_file.getTableNXSArray()
  jxs_array = h_ace_file.getTableJXSArray()
  xss_array = h_ace_file.getTableXSSArray()
"

// Add some useful methods to the ACEFileHandler class
%extend Data::ACEFileHandler
{
  // String conversion method
  PyObject* __str__() const
  {
    std::string string_rep( $self->getTableName() );
    string_rep += " from ";
    string_rep += $self->getLibraryName();
    
    return PyString_FromString( string_rep.c_str() );
  }

  // String representation method
  PyObject* __repr__() const
  {
    std::string string_rep( "ACEFileHandler(" );
    string_rep += $self->getTableName();
    string_rep += " from ";
    string_rep += $self->getLibraryName();
    string_rep += ")";
      
    return PyString_FromString( string_rep.c_str() );
  }
};

// Include ACEFileHandler
%include "Data_ACEFileHandler.hpp"

//---------------------------------------------------------------------------//
// Macro for setting up the XSS data extractor classes
//---------------------------------------------------------------------------//
%define %data_extractor_setup( EXTRACTOR )

// Ignore the constructor (a new one will be provided)
%ignore Data::EXTRACTOR::EXTRACTOR( const Teuchos::ArrayView<const int>&, const Teuchos::ArrayView<const int>&, const Teuchos::ArrayRCP<const double>& );

// Define the new constructor
%extend Data::EXTRACTOR
{
  // Constructor
  EXTRACTOR( PyObject* nxs_py_array, 
             PyObject* jxs_py_array, 
             PyObject* xss_py_array )
  {
    Teuchos::Array<int> nxs_array;

    PyFrensie::CopyNumPyToTeuchosWithCheck( nxs_py_array, nxs_array );

    Teuchos::Array<int> jxs_array;

    PyFrensie::CopyNumPyToTeuchosWithCheck( jxs_py_array, jxs_array );

    Teuchos::ArrayRCP<double> xss_array;

    PyFrensie::CopyNumPyToTeuchosWithCheck( xss_py_array, xss_array );

    return new Data::EXTRACTOR( nxs_array(),
                                jxs_array(),
                                xss_array.getConst() );
  }
};

%enddef

//---------------------------------------------------------------------------//
// Add support for the XSSNeutronDataExtractor
//---------------------------------------------------------------------------//
// Add a more detailed docstrings for the XSSNeutronDataExtractor
%feature("docstring")
Data::XSSNeutronDataExtractor
"
The XSSNeutronDataExtractor can be used to extract the data blocks from the
xss array found in an ACE data table.  A brief usage tutorial for this class is
shown below:

  import PyFrensie.Data, PyTrilinos.Teuchos, numpy, matplotlib.pyplot
  
  source = PyTrilinos.Teuchos.FileInputSource( 'datadir/cross_sections.xml' )
  xml_obj = source.getObject()
  cs_list = PyTrilinos.Teuchos.XMLParameterListReader().toParameterList( xml_obj )
  
  h_1_data_list = cs_list.get( 'H-1_293.6K_v8' )
  h_1_ace_file_name = 'datadir' + h_1_data_list.get( 'nuclear_file_path' )

  h_1_ace_file = PyFrensie.Data.ACEFileHandler( h_1_ace_file_name, h_1_data_list.get( 'nuclear_table_name' ), h_1_data_list.get( 'nuclear_file_start_line' ) )
  
  neutron_data_extractor = PyFrensie.Data.XSSNeutronDataExtractor( h_1_ace_file.getTableNXSArray(), h_1_ace_file.getTableJXSArray(), h_1_ace_file.getTableXSSArray() )  

  matplotlib.pyplot.loglog( neutron_data_extractor.extractEnergyGrid(), neutron_data_extractor.extractTotalCrossSection() )
  matplotlib.pyplot.show()
"

%data_extractor_setup( XSSNeutronDataExtractor )

// Include XSSNeutronDataExtractor
%include "Data_XSSNeutronDataExtractor.hpp"

//---------------------------------------------------------------------------//
// Add support for the XSSEPRDataExtractor
//---------------------------------------------------------------------------//
// Add a more detailed docstrings for the XSSEPRDataExtractor
%feature("docstring")
Data::XSSEPRDataExtractor
"
The XSSEPRDataExtractor can be used to extract the data blocks from the
xss array found in an ACE data table.  A brief usage tutorial for this class is
shown below:

  import PyFrensie.Data, PyTrilinos.Teuchos, numpy, matplotlib.pyplot
  
  source = PyTrilinos.Teuchos.FileInputSource( 'datadir/cross_sections.xml' )
  xml_obj = source.getObject()
  cs_list = PyTrilinos.Teuchos.XMLParameterListReader().toParameterList( xml_obj )
  
  h_1_data_list = cs_list.get( 'H-1_293.6K_v8' )
  h_1_ace_file_name = 'datadir' + h_1_data_list.get( 'photoatomic_file_path' )

  h_1_ace_file = PyFrensie.Data.ACEFileHandler( h_1_ace_file_name, h_1_data_list.get( 'photoatomic_table_name' ), h_1_data_list.get( 'photoatomic_file_start_line' ) )
  
  neutron_data_extractor = PyFrensie.Data.XSSEPRDataExtractor( h_1_ace_file.getTableNXSArray(), h_1_ace_file.getTableJXSArray(), h_1_ace_file.getTableXSSArray() )  

  matplotlib.pyplot.loglog( neutron_data_extractor.extractPhotonEnergyGrid(), neutron_data_extractor.extractIncoherentCrossSection() )
  matplotlib.pyplot.loglog( neutron_data_extractor.extractPhotonEnergyGrid(), neutron_data_extractor.extractCoherentCrossSection() )
  matplotlib.pyplot.loglog( neutron_data_extractor.extractPhotonEnergyGrid(), neutron_data_extractor.extractPhotoelectricCrossSection() )
  matplotlib.pyplot.loglog( neutron_data_extractor.extractPhotonEnergyGrid(), neutron_data_extractor.extractPairProductionCrossSection() )
  matplotlib.pyplot.show()
"

%data_extractor_setup( XSSEPRDataExtractor )

// Include XSSEPRDataExtractor
%include "Data_XSSEPRDataExtractor.hpp"

//---------------------------------------------------------------------------//
// end Data_ACE.i
//---------------------------------------------------------------------------//
