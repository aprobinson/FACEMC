//---------------------------------------------------------------------------//
//!
//! \file   Facemc_ParticleSubtrackEndingInCellEventObserver.hpp
//! \author Alex Robinson
//! \brief  Particle subtrack ending in cell event observer base class decl.
//!
//---------------------------------------------------------------------------//

#ifndef FACEMC_PARTICLE_SUBTRACK_ENDING_IN_CELL_EVENT_OBSERVER_HPP
#define FACEMC_PARTICLE_SUBTRACK_ENDING_IN_CELL_EVENT_OBSERVER_HPP

// Trilinos Includes
#include <Teuchos_Array.hpp>

// FRENSIE Includes
#include "Facemc_ModuleTraits.hpp"
#include "Facemc_ParticleState.hpp"
#include "Geometry_ModuleTraits.hpp"

namespace Facemc{

//! The particle subtrack ending in cell event observer
class ParticleSubtrackEndingInCellEventObserver
{
  
public:

  //! The event tag type
  struct ParticleSubtrackEndingInCellEvent{};

  //! Typedef for the observer event tat
  typedef ParticleSubtrackEndingInCellEvent EventTag;

  //! Constructor
  ParticleSubtrackEndingInCellEventObserver()
  { /* ... */ }

  //! Destructor
  virtual ~ParticleSubtrackEndingInCellEventObserver()
  { /* ... */ }

  //! Update the observer
  virtual void updateFromParticleSubtrackEndingInCellEvent(
	     const ParticleState& particle,
	     const Geometry::ModuleTraits::InternalCellHandle cell_of_subtrack,
	     const double track_length ) = 0;
};

} // end Facemc namespace

#endif // end FACEMC_PARTICLE_SUBTRACK_ENDING_IN_CELL_EVENT_OBSERVER_HPP

//---------------------------------------------------------------------------//
// end Facemc_ParticleSubtrackEndingInCellEventObserver.hpp
//---------------------------------------------------------------------------//