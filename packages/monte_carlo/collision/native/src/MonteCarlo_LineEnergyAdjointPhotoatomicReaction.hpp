//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_LineEnergyAdjointPhotoatomicReaction.hpp
//! \author Alex Robinson
//! \brief  The line energy adjoint photoatomic reaction class decl.
//!
//---------------------------------------------------------------------------//

#ifndef MONTE_CARLO_LINE_ENERGY_ADJOINT_PHOTOATOMIC_REACTION_HPP
#define MONTE_CARLO_LINE_ENERGY_ADJOINT_PHOTOATOMIC_REACTION_HPP

// Std Lib Includes
#include <memory>

// FRENSIE Includes
#include "MonteCarlo_AdjointPhotoatomicReaction.hpp"
#include "MonteCarlo_LineEnergyAdjointPhotonScatteringDistribution.hpp"

namespace MonteCarlo{

//! The line energy adjoint photoatomic reaction class
class LineEnergyAdjointPhotoatomicReaction : public AdjointPhotoatomicReaction
{

public:

  //! Constructor
  LineEnergyAdjointPhotoatomicReaction(
    const AdjointPhotoatomicReactionType reaction,
    const double cross_section_value,
    const std::shared_ptr<const LineEnergyAdjointPhotonScatteringDistribution>&
    energy_dist );

  //! Destructor
  ~LineEnergyAdjointPhotoatomicReaction()
  { /* ... */ }

  //! Return the minimum outgoing energy
  double getMinOutgoingEnergy() const;

  //! Return the maximum outgoing energy
  double getMaxOutgoingEnergy() const;

  //! Test if the energy falls within the energy grid
  bool isEnergyWithinEnergyGrid( const double energy ) const;

  //! Return the cross section at the given energy
  double getCrossSection( const double energy ) const;

  //! Return the cross section at the given energy (efficient)
  double getCrossSection( const double energy,
			  const unsigned bin_index ) const;

  //! Return the line energy
  double getLineEnergy() const;

  //! Return the max energy
  double getMaxEnergy() const;

  //! Return the threshold energy
  double getThresholdEnergy() const;

  //! Return the number of adjoint photons emitted from the rxn at the given energy
  unsigned getNumberOfEmittedPhotons( const double energy ) const;

  //! Return the number of adjoint electrons emitted from the rxn at the given energy
  unsigned getNumberOfEmittedElectrons( const double energy ) const;

  //! Return the reaction type
  AdjointPhotoatomicReactionType getReactionType() const;

  //! Simulate the reaction
  void react( AdjointPhotonState& adjoint_photon,
	      ParticleBank& bank,
	      Data::SubshellType& shell_of_interaction ) const;

protected:

  //! Return the head of the energy grid
  const double* getEnergyGridHead() const;

private:

  // The reaction type
  AdjointPhotoatomicReactionType d_reaction_type;

  // The cross section value
  double d_cross_section;

  // The scattering distribution
  std::shared_ptr<const LineEnergyAdjointPhotonScatteringDistribution>
    d_scattering_distribution;
};
  
} // end MonteCarlo namespace

#endif // end MONTE_CARLO_LINE_ENERGY_ADJOINT_PHOTOATOMIC_REACTION_HPP

//---------------------------------------------------------------------------//
// end MonteCarlo_LineEnergyAdjointPhotoatomicReaction.hpp
//---------------------------------------------------------------------------//
