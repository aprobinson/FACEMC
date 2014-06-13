//---------------------------------------------------------------------------//
//!
//! \file   Facemc_ParticleLeavingCellEventDispatcherDB.hpp
//! \author Alex Robinson
//! \brief  Particle leaving cell event dispatcher database class decl.
//!
//---------------------------------------------------------------------------//

#ifndef FACEMC_PARTICLE_LEAVING_CELL_EVENT_DISPATCHER_DP_HPP
#define FACEMC_PARTICLE_LEAVING_CELL_EVENT_DISPATCHER_DP_HPP

// Boost Includes
#include <boost/unordered_map.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/deref.hpp>

// Teuchos Includes
#include <Teuchos_RCP.hpp>

// FRENSIE Includes
#include "Facemc_ParticleLeavingCellEventDispatcher.hpp"

namespace Facemc{

//! The particle leaving cell event dispatcher database class
class ParticleLeavingCellEventDispatcherDB
{
  
public:

  //! Get the appropriate dispatcher for the given cell id
  static Teuchos::RCP<ParticleLeavingCellEventDispatcher>& getDispatcher(
		    const Geometry::ModuleTraits::InternalCellHandle cell_id );

  //! Attach an observer to the appropriate dispatcher
  static void attachObserver(
		    const Geometry::ModuleTraits::InternalCellHandle cell_id,
		    const ModuleTraits::InternalEstimatorHandle estimator_id,
		    Teuchos::RCP<ParticleLeavingCellEventObserver>& observer );

  //! Detach the observer from the appropriate dispatcher
  static void detachObserver(
		    const Geometry::ModuleTraits::InternalCellHandle cell_id,
		    const ModuleTraits::InternalEstimatorHandle estimator_id );

  //! Detach the observer from all dispatchers
  static void detachObserver(
		    const ModuleTraits::InternalEstimatorHandle estimator_id );

  //! Detach all observers
  static void detachAllObservers();

  //! Dispatch the particle leaving cell event to the observers
  static void dispatchParticleLeavingCellEvent(
	       const ParticleState& particle,
	       const Geometry::ModuleTraits::InternalCellHandle cell_leaving );

private:

  // Constructor
  ParticleLeavingCellEventDispatcherDB();

  // Typedef for the dispatcher map
  typedef boost::unordered_map<Geometry::ModuleTraits::InternalCellHandle,
			     Teuchos::RCP<ParticleLeavingCellEventDispatcher> >
  DispatcherMap;

  static DispatcherMap master_map;
};

// Dispatch the particle leaving cell event to the observers
inline void
ParticleLeavingCellEventDispatcherDB::dispatchParticleLeavingCellEvent( 
	        const ParticleState& particle,
	        const Geometry::ModuleTraits::InternalCellHandle cell_leaving )
{
  DispatcherMap::iterator it = 
    ParticleLeavingCellEventDispatcherDB::master_map.find( cell_leaving );

  if( it != ParticleLeavingCellEventDispatcherDB::master_map.end() )
    it->second->dispatchParticleLeavingCellEvent( particle, cell_leaving );
}

} // end Facemc namespace

#endif // end FACEMC_PARTICLE_LEAVING_CELL_EVENT_DISPATCHER_DP_HPP

//---------------------------------------------------------------------------//
// end Facemc_ParticleLeavingCellEventDispatcherDB.hpp
//---------------------------------------------------------------------------//