//---------------------------------------------------------------------------//
//!
//! \file   Facemc_ParticleEnteringCellEventDispatcher.cpp
//! \author Alex Robinson
//! \brief  Particle entering cell event dispatcher declaration.
//!
//---------------------------------------------------------------------------//

// FRENSIE Includes
#include "Facemc_ParticleEnteringCellEventDispatcher.hpp"
#include "Utility_ContractException.hpp"

namespace Facemc{

// Constructor
ParticleEnteringCellEventDispatcher::ParticleEnteringCellEventDispatcher(
		     const Geometry::ModuleTraits::InternalCellHandle cell_id )
  : ParticleEventDispatcher<Geometry::ModuleTraits::InternalCellHandle,
			    ParticleEnteringCellEventObserver>( cell_id )
{ /* ... */ }

// Dispatch the new event to the observers
void ParticleEnteringCellEventDispatcher::dispatchParticleEnteringCellEvent(
	       const ParticleState& particle,
	       const Geometry::ModuleTraits::InternalCellHandle cell_entering )
{
  // Make sure the cell being entered is valid
  testPrecondition( cell_entering == this->getId() );

  ObserverIdMap::iterator it = observer_id_map().begin();

  while( it != observer_id_map().end() )
  {
    it->second->updateFromParticleEnteringCellEvent( particle, cell_entering );

    ++it;
  }
}

} // end Facemc namespace

//---------------------------------------------------------------------------//
// end Facemc_ParticleEnteringCellEventDispatcher.cpp
//---------------------------------------------------------------------------//
