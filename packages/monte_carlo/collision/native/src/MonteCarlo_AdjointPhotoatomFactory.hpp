//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_AdjointPhotoatomFactory.hpp
//! \author Alex Robinson
//! \brief  The adjoint photoatom factory class declaration
//!
//---------------------------------------------------------------------------//

#ifndef MONTE_CARLO_ADJOINT_PHOTOATOM_FACTORY_HPP
#define MONTE_CARLO_ADJOINT_PHOTOATOM_FACTORY_HPP

// Std Lib Includes
#include <string>
#include <unordered_set>
#include <unordered_map>

// Trilinos Includes
#include <Teuchos_ParameterList.hpp>
#include <Teuchos_ArrayRCP.hpp>
#include <Teuchos_Array.hpp>
#include <Teuchos_RCP.hpp>

// FRENSIE Includes
#include "MonteCarlo_AdjointPhotoatom.hpp"
#include "MonteCarlo_IncoherentAdjointModelType.hpp"

namespace MonteCarlo{

//! The adjoint photoatom factory class
class AdjointPhotoatomFactory
{

public:

  //! Constructor
  AdjointPhotoatomFactory(
              const std::string& cross_sections_xml_directory,
              const Teuchos::ParameterList& cross_section_table_info,
              const std::unordered_set<std::string>& adjoint_photoatom_aliases,
              const double max_energy,
              const unsigned hash_grid_bins,
              const IncoherentAdjointModelType incoherent_adjoint_model,
              const Teuchos::Array<double>& user_critical_line_energies,
              std::ostream* os_message = &std::cout );

  //! Destructor
  ~AdjointPhotoatomFactory()
  { /* ... */ }

  //! Create the map of adjoint photoatoms
  void createAdjointPhotoatomMap(
               std::unordered_map<std::string,Teuchos::RCP<AdjointPhotoatom> >&
               adjoint_photoatom_map ) const;

private:

  // Create an adjoint photoatom from a Native table
  void createAdjointPhotoatomFromNativeTable(
                   const std::string& cross_sections_xml_directory,
                   const std::string& adjoint_photoatom_alias,
                   const std::string& native_file_path,
                   const double atomic_weight,
                   const double max_energy,
                   const unsigned hash_grid_bins,
                   const IncoherentAdjointModelType incoherent_adjoint_model,
                   const Teuchos::Array<double>& user_critical_line_energies );

  // The adjoint photoatom map
  std::unordered_map<std::string,Teuchos::RCP<AdjointPhotoatom> >
  d_adjoint_photoatom_name_map;

  // The table map
  std::unordered_map<std::string,Teuchos::RCP<AdjointPhotoatom> >
  d_adjoint_photoatomic_table_name_map;

  // The message output stream
  std::ostream* d_os_message;
};
  
} // end MonteCarlo namespace

#endif // end MONTE_CARLO_ADJOINT_PHOTOATOM_FACTORY_HPP

//---------------------------------------------------------------------------//
// end MonteCarlo_AdjointPhotoatomFactory.hpp
//---------------------------------------------------------------------------//
