//---------------------------------------------------------------------------//
//!
//! \file   Facemc_StandardCellEstimator.cpp
//! \author Alex Robinson
//! \brief  Standard cell estimator class definition.
//!
//---------------------------------------------------------------------------//

// FRENSIE Includes
#include "Facemc_StandardCellEstimator.hpp"

namespace Facemc{

// Constructor
StandardCellEstimator::StandardCellEstimator(
	     const Estimator::idType id,
	     const double multiplier,
	     const Teuchos::Array<StandardCellEstimator::cellIdType>& cell_ids,
	     const Teuchos::Array<double>& cell_volumes )
  : StandardEntityEstimator<cellIdType>(id, multiplier, cell_ids, cell_volumes)
{ /* ... */ }

// Set the particle types that can contribute to the estimator
/*! \details Photons, electrons and neutrons (or their adjoint
 * couterparts) can contribute to the estimator. Combinations are not 
 * allowed.
 */
void StandardCellEstimator::setParticleTypes(
			   const Teuchos::Array<ParticleType>& particle_types )
{
  if( particle_types.size() > 1 )
  {
    std::cerr << "Warning: Standard cell estimators can only have one "
	      << "particle type contribute. All but the first particle type "
	      << "requested in estimator " << this->getId() 
	      << " will be ignored."
	      << std::endl;
    
    Teuchos::Array<ParticleType> valid_particle_types( 1 );
    valid_particle_types[0] = particle_types.front();
    
    Estimator::setParticleTypes( valid_particle_types );
  }
  else
    Estimator::setParticleTypes( particle_types );
}

// Assign bin boundaries to an estimator dimension
/*! \details The Facemc::COSINE_DIMENSION cannot be discretized in standard
 * cell estimators.
 */
void StandardCellEstimator::assignBinBoundaries(
	 const Teuchos::RCP<EstimatorDimensionDiscretization>& bin_boundaries )
{
  if( bin_boundaries->getDimension() == COSINE_DIMENSION )
  {
    std::cerr << "Warning: " << bin_boundaries->getDimensionName()
	      << " bins cannot be set for standard cell estimators. The bins "
	      << "requested for standard cell estimator " << this->getId()
	      << " will be ignored."
	      << std::endl;
  }
  else
    StandardEntityEstimator<cellIdType>::assignBinBoundaries( bin_boundaries );
}

} // end Facemc namespace

//---------------------------------------------------------------------------//
// end Facemc_StandardCellEstimator.cpp
//---------------------------------------------------------------------------//
