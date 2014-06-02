//---------------------------------------------------------------------------//
//!
//! \file   Facemc_SurfaceFluxEstimator_def.hpp
//! \author Alex Robinson
//! \brief  Surface flux estimator class definition
//!
//---------------------------------------------------------------------------//

#ifndef FACEMC_SURFACE_FLUX_ESTIMATOR_DEF_HPP
#define FACEMC_SURFACE_FLUX_ESTIMATOR_DEF_HPP

// FRENSIE Includes
#include "Utility_ContractException.hpp"

namespace Facemc{

// Constructor
template<typename ContributionMultiplierPolicy>
SurfaceFluxEstimator<ContributionMultiplierPolicy>::SurfaceFluxEstimator(
    const Estimator::idType id,
    const double multiplier,
    const Teuchos::Array<StandardSurfaceEstimator::surfaceIdType>& surface_ids,
    const Teuchos::Array<double>& surface_areas )
  : StandardSurfaceEstimator( id, multiplier, surface_ids, surface_areas )
{ /* ... */ }

// Add estimator contribution from a portion of the current history
template<typename ContributionMultiplierPolicy>
void SurfaceFluxEstimator<
		  ContributionMultiplierPolicy>::addPartialHistoryContribution(
		 const ParticleState& particle,
		 const StandardSurfaceEstimator::surfaceIdType surface_crossed,
		 const double angle_cosine )
{
  // Make sure the surface is assigned to this estimator
  testPrecondition( isEntityAssigned( surface_crossed ) );
  // Make sure the particle type is assigned
  testPrecondition( isParticleTypeAssigned( particle.getParticleType() ) );
  // Make sure the angle cosine is valid
  testPrecondition( angle_cosine <= 1.0 );
  testPrecondition( angle_cosine >= -1.0 );

  double contribution; 
  
  // If the angle cosine is very close to zero, set it to eps/2 to
  // prevent large contributions to the estimator
  if( ST::magnitude( angle_cosine ) > 
      StandardSurfaceEstimator::getAngleCosineCutoff() )
    contribution = 1.0/ST::magnitude( angle_cosine );
  else
    contribution = StandardSurfaceEstimator::getAngleCosineCutoff()/2;
  
  contribution *= ContributionMultiplierPolicy::multiplier( particle );
  
  StandardEntityEstimator<
       StandardSurfaceEstimator::surfaceIdType>::addPartialHistoryContribution(
						               surface_crossed,
							       particle, 
							       angle_cosine,
							       contribution );
}

// Print the estimator data
template<typename ContributionMultiplierPolicy>
void SurfaceFluxEstimator<
		 ContributionMultiplierPolicy>::print( std::ostream& os ) const
{
  os << "Surface Flux Estimator: " << getId() << std::endl;

  printImplementation( os, "Surface" );
}

} // end Facemc namespace

#endif // end FACEMC_SURFACE_FLUX_ESTIMATOR_DEF_HPP

//---------------------------------------------------------------------------//
// end Facemc_SurfaceFluxEstimator_def.hpp
//---------------------------------------------------------------------------//