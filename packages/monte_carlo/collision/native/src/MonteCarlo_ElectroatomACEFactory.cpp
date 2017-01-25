//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_ElectroatomACEFactory.hpp
//! \author Luke Kersting
//! \brief  The electroatom ace factory class definition.
//!
//---------------------------------------------------------------------------//

// Trilinos Includes
#include <Teuchos_Array.hpp>
#include <Teuchos_ArrayRCP.hpp>

// FRENSIE Includes
#include "MonteCarlo_ElectroatomACEFactory.hpp"
#include "MonteCarlo_ElectroatomicReactionACEFactory.hpp"
#include "Utility_ContractException.hpp"

namespace MonteCarlo{

// Create a electroatom core (using the provided atomic relaxation model)
/*! \details The provided atomic relaxation model will be used with this
 * core. Special care must be taken to assure that the model corresponds to
 * the atom of interest. If the use of atomic relaxation data has been
 * requested, a electroionization reaction for each subshell will be created.
 * Otherwize a single total electroionization reaction will be created.
 */
void ElectroatomACEFactory::createElectroatomCore(
    const Data::XSSEPRDataExtractor& raw_electroatom_data,
    const Teuchos::RCP<AtomicRelaxationModel>& atomic_relaxation_model,
    Teuchos::RCP<ElectroatomCore>& electroatom_core,
    const unsigned hash_grid_bins,
    const bool use_atomic_relaxation_data,
    const bool use_elastic_data,
    const bool use_electroionization_data,
    const bool use_bremsstrahlung_data,
    const bool use_atomic_excitation_data,
    const BremsstrahlungAngularDistributionType
        photon_distribution_function,
    const double cutoff_angle_cosine )
{
  // Make sure the atomic relaxation model is valid
  testPrecondition( !atomic_relaxation_model.is_null() );

  electroatom_core.reset( new ElectroatomCore() );

  Electroatom::ReactionMap scattering_reactions, absorption_reactions;

  // Extract the common energy grid used for this atom
  Teuchos::ArrayRCP<double> energy_grid;
  energy_grid.deepCopy( raw_electroatom_data.extractElectronEnergyGrid() );

  // Create a hash based energy grid seacher
  Teuchos::RCP<Utility::HashBasedGridSearcher> grid_searcher(
     new Utility::StandardHashBasedGridSearcher<Teuchos::ArrayRCP<const double>, false>(
						     energy_grid,
						     hash_grid_bins ) );

  // Create the elastic scattering reaction
  if ( use_elastic_data )
  {
    // Create the cutoff elastic scattering reaction
    {
      Electroatom::ReactionMap::mapped_type& reaction_pointer =
        scattering_reactions[CUTOFF_ELASTIC_ELECTROATOMIC_REACTION];

      ElectroatomicReactionACEFactory::createCutoffElasticReaction(
        raw_electroatom_data,
        energy_grid,
        grid_searcher,
        reaction_pointer,
        cutoff_angle_cosine );
    }
  }

  // Create the bremsstrahlung scattering reaction
  if ( use_bremsstrahlung_data )
  {
    Electroatom::ReactionMap::mapped_type& reaction_pointer =
      scattering_reactions[BREMSSTRAHLUNG_ELECTROATOMIC_REACTION];

    ElectroatomicReactionACEFactory::createBremsstrahlungReaction(
        raw_electroatom_data,
        energy_grid,
        grid_searcher,
        reaction_pointer,
        photon_distribution_function );
  }

  // Create the atomic excitation scattering reaction
  if ( use_atomic_excitation_data )
  {
    Electroatom::ReactionMap::mapped_type& reaction_pointer =
      scattering_reactions[ATOMIC_EXCITATION_ELECTROATOMIC_REACTION];

    ElectroatomicReactionACEFactory::createAtomicExcitationReaction(
        raw_electroatom_data,
        energy_grid,
        grid_searcher,
        reaction_pointer );
  }

  // Create the electroionization reaction(s)
  if ( use_electroionization_data )
  {
    std::vector<std::shared_ptr<ElectroatomicReaction> > reaction_pointers;

    ElectroatomicReactionACEFactory::createSubshellElectroionizationReactions(
        raw_electroatom_data,
        energy_grid,
        grid_searcher,
        reaction_pointers );

    for( unsigned i = 0; i < reaction_pointers.size(); ++i )
    {
      scattering_reactions[reaction_pointers[i]->getReactionType()] =
        reaction_pointers[i];
    }
  }

  // Create the electroatom core
  electroatom_core.reset( new ElectroatomCore( energy_grid,
                                               scattering_reactions,
                                               absorption_reactions,
                                               atomic_relaxation_model,
                                               false,
                                               Utility::LinLin() ) );
}

// Create a electroatom (using the provided atomic relaxation model)
/*! \details The provided atomic relaxation model will be used with this
 * atom. Special care must be taken to assure that the model corresponds to
 * the atom of interest. If the use of atomic relaxation data has been
 * requested, a electroionization reaction for each subshell will be created.
 * Otherwise a single total electroionization reaction will be created.
 */
void ElectroatomACEFactory::createElectroatom(
        const Data::XSSEPRDataExtractor& raw_electroatom_data,
        const std::string& electroatom_name,
        const double atomic_weight,
        const unsigned hash_grid_bins,
        const Teuchos::RCP<AtomicRelaxationModel>& atomic_relaxation_model,
        Teuchos::RCP<Electroatom>& electroatom,
        const bool use_atomic_relaxation_data,
        const bool use_elastic_data,
        const bool use_electroionization_data,
        const bool use_bremsstrahlung_data,
        const bool use_atomic_excitation_data,
        const BremsstrahlungAngularDistributionType
            photon_distribution_function,
        const double cutoff_angle_cosine )
{
  // Make sure the atomic weight is valid
  testPrecondition( atomic_weight > 0.0 );
  // Make sure the atomic relaxation model is valid
  testPrecondition( !atomic_relaxation_model.is_null() );

  Teuchos::RCP<ElectroatomCore> core;

  ElectroatomACEFactory::createElectroatomCore( raw_electroatom_data,
                                                atomic_relaxation_model,
                                                core,
                                                hash_grid_bins,
                                                use_atomic_relaxation_data,
                                                use_elastic_data,
                                                use_electroionization_data,
                                                use_bremsstrahlung_data,
                                                use_atomic_excitation_data,
                                                photon_distribution_function,
                                                cutoff_angle_cosine );

  // Create the electroatom
  electroatom.reset(
    new Electroatom( electroatom_name,
                     raw_electroatom_data.extractAtomicNumber(),
                     atomic_weight,
                     *core ) );
}

} // end MonteCarlo namespace

//---------------------------------------------------------------------------//
// end MonteCarlo_ElectroatomACEFactory.cpp
//---------------------------------------------------------------------------//
