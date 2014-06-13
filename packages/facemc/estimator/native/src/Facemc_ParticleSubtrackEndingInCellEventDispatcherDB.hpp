//---------------------------------------------------------------------------//
//!
//! \file   Facemc_ParticleSubtrackEndingInCellEventDispatcherDB.hpp
//! \author Alex Robinson
//! \brief  Particle subtrack ending in cell event dispatcher database decl.
//!
//---------------------------------------------------------------------------//

#ifndef FACEMC_PARTICLE_SUBTRACK_ENDING_IN_CELL_EVENT_DISPATCHER_DB_HPP
#define FACEMC_PARTICLE_SUBTRACK_ENDING_IN_CELL_EVENT_DISPATCHER_DB_HPP

// Boost Includes
#include <boost/unordered_map.hpp>
#include <boost/mpl/find.hpp>
#include <boost/mpl/deref.hpp>

// Teuchos Includes
#include <Teuchos_RCP.hpp>

// FRENSIE Includes
#include "Facemc_ParticleSubtrackEndingInCellEventDispatcher.hpp"

namespace Facemc{

//! The particle subtrack ending in cell event dispatcher database class
class ParticleSubtrackEndingInCellEventDispatcherDB
{

public:

  //! Get the appropriate dispatcher for the given cell id
  static Teuchos::RCP<ParticleSubtrackEndingInCellEventDispatcher>& 
  getDispatcher( const Geometry::ModuleTraits::InternalCellHandle cell_id );

  //! Attach an observer to the appropriate dispatcher
  static void attachObserver(
	   const Geometry::ModuleTraits::InternalCellHandle cell_id,
	   const ModuleTraits::InternalEstimatorHandle estimator_id,
	   Teuchos::RCP<ParticleSubtrackEndingInCellEventObserver>& observer );
  
  //! Detach an observer from the appropriate dispatcher
  static void detachObserver(
		    const Geometry::ModuleTraits::InternalCellHandle cell_id,
		    const ModuleTraits::InternalEstimatorHandle estimator_id );

  //! Detach the observer from all dispatchers
  static void detachObserver(
		    const ModuleTraits::InternalEstimatorHandle estimator_id );

  //! Detach all observers
  static void detachAllObservers();

  //! Dispatch the particle subtrack ending in cell event to the observers
  static void dispatchParticleSubtrackEndingInCellEvent(
	     const ParticleState& particle,
	     const Geometry::ModuleTraits::InternalCellHandle cell_of_subtrack,
	     const double track_length );

private:

  // Constructor
  ParticleSubtrackEndingInCellEventDispatcherDB();

  // Typedef for the dispatcher map
  typedef boost::unordered_map<Geometry::ModuleTraits::InternalCellHandle,
		    Teuchos::RCP<ParticleSubtrackEndingInCellEventDispatcher> >
  DispatcherMap;

  static DispatcherMap master_map;
};

// Dispatch the particle subtrack ending in cell event to the observers
inline void 
ParticleSubtrackEndingInCellEventDispatcherDB::dispatchParticleSubtrackEndingInCellEvent(
	    const ParticleState& particle,
	    const Geometry::ModuleTraits::InternalCellHandle  cell_of_subtrack,
	    const double track_length )
{
  DispatcherMap::iterator it = 
    ParticleSubtrackEndingInCellEventDispatcherDB::master_map.find( 
							    cell_of_subtrack );

  if( it != ParticleSubtrackEndingInCellEventDispatcherDB::master_map.end() )
  {
    it->second->dispatchParticleSubtrackEndingInCellEvent( particle, 
							   cell_of_subtrack,
							   track_length );
  }
}

} // end Facemc namespace

#endif // end FACEMC_PARTICLE_SUBTRACK_ENDING_IN_CELL_EVENT_DISPATCHER_DB_HPP

//---------------------------------------------------------------------------//
// end Facemc_ParticleSubtrackEndingInCellEventDispatcherDB.hpp
//---------------------------------------------------------------------------//