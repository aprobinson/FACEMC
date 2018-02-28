//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_ObserverPhaseSpaceDimensionTraits.hpp
//! \author Alex Robinson
//! \brief  Observer phase space dimension traits class specializations
//!
//---------------------------------------------------------------------------//

#ifndef MONTE_CARLO_OBSERVER_PHASE_SPACE_DIMENSION_TRAITS_HPP
#define MONTE_CARLO_OBSERVER_PHASE_SPACE_DIMENSION_TRAITS_HPP

// Std Lib Includes
#include <limits>

// Trilinos Includes
#include <Teuchos_Array.hpp>

// FRENSIE Includes
#include "MonteCarlo_ObserverPhaseSpaceDimensionTraitsDecl.hpp"
#include "MonteCarlo_ObserverPhaseSpaceDimension.hpp"
#include "MonteCarlo_ParticleState.hpp"

namespace MonteCarlo{

/*! \brief The specialization of the ObserverPhaseSpaceDimensionTraits for 
 * OBSERVER_COSINE_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct ObserverPhaseSpaceDimensionTraits<OBSERVER_COSINE_DIMENSION>
{
  typedef double dimensionType;

  typedef dimensionType dimensionBinType;

  typedef boost::mpl::bool_<true> isOrdered;

  static inline std::string name()
  { return "Cosine"; }

  static inline std::string basicName()
  { return "Cosine"; }

  static inline dimensionType lowerBound()
  { return -1.0; }

  static inline dimensionType upperBound()
  { return 1.0; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getAngleCosine(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getAngleCosine();
    range_end = range_start;
  }
};

/*! \brief The specialization of the ObserverPhaseSpaceDimensionTraits for OBSERVER_SOURCE_ENERGY_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct ObserverPhaseSpaceDimensionTraits<OBSERVER_SOURCE_ENERGY_DIMENSION>
{
  typedef ParticleState::energyType dimensionType;

  typedef dimensionType dimensionBinType;

  typedef boost::mpl::bool_<true> isOrdered;

  static inline std::string name()
  { return "Source Energy"; }

  static inline std::string basicName()
  { return "Source_Energy"; }

  static inline dimensionType lowerBound()
  { return 0.0; }

  static inline dimensionType upperBound()
  { return std::numeric_limits<dimensionType>::infinity(); }

  static inline bool isContinuous()
  { return true; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getParticleState().getSourceEnergy(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getParticleState().getSourceEnergy();
    range_end = range_start;
  }
};

/*! \brief The specialization of the ObserverPhaseSpaceDimensionTraits for 
 * OBSERVER_ENERGY_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct PhaseSpaceDimensionTraits<ENERGY_DIMENSION>
{
  typedef ParticleState::energyType dimensionType;

  typedef dimensionType dimensionBinType;

  typedef boost::mpl::bool_<true> isOrdered;

  static inline std::string name()
  { return "Energy"; }

  static inline std::string basicName()
  { return "Energy"; }

  static inline dimensionType lowerBound()
  { return 0.0; }

  static inline dimensionType upperBound()
  { return std::numeric_limits<dimensionType>::infinity(); }

  static inline bool isContinuous()
  { return true; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getParticleState().getEnergy(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getParticleState().getEnergy();
    range_end = range_start;
  }
};

/*! The specialization of the PhaseSpaceDimensionTraits for SOURCE_TIME_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct ObserverPhaseSpaceDimensionTraits<SOURCE_TIME_DIMENSION>
{
  typedef ParticleState::timeType dimensionType;

  typedef dimensionType dimensionBinType;

  typedef boost::mpl::bool_<true> isOrdered;

  static inline std::string name()
  { return "Source Time"; }

  static inline std::string basicName()
  { return "Source_Time"; }

  static inline dimensionType lowerBound()
  { return 0.0; }

  static inline dimensionType upperBound()
  { return std::numeric_limits<dimensionType>::infinity(); }

  static inline bool isContinuous()
  { return true; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getParticleState().getSourceTime(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getParticleState().getSourceTime();
    range_end = range_start;
  }
};

/*! \brief The specialization of the ObserverPhaseSpaceDimensionTraits for 
 * OBSERVER_TIME_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct ObserverPhaseSpaceDimensionTraits<OBSERVER_TIME_DIMENSION>
{
  typedef ParticleState::timeType dimensionType;

  typedef dimensionType dimensionBinType;

  typedef boost::mpl::bool_<true> isOrdered;

  static inline std::string name()
  { return "Time"; }

  static inline std::string basicName()
  { return "Time"; }

  static inline dimensionType lowerBound()
  { return 0.0; }

  static inline dimensionType upperBound()
  { return std::numeric_limits<dimensionType>::infinity(); }

  static inline bool isContinuous()
  { return true; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getParticleState().getTime(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getStartTime();
    range_end = particle_wrapper.getEndTime();
  }
};

/*! \brief The specialization of the ObserverPhaseSpaceDimensionTraits for
 * OBSERVER_COLLISION_NUMBER_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct ObserverPhaseSpaceDimensionTraits<OBSERVER_COLLISION_NUMBER_DIMENSION>
{
  typedef ParticleState::collisionNumberType dimensionType;

  typedef dimensionType dimensionBinType;

  typedef boost::mpl::bool_<true> isOrdered;

  static inline std::string name()
  { return "Collision Number"; }

  static inline std::string basicName()
  { return "Collision_Number"; }

  static inline dimensionType lowerBound()
  { return 0u; }

  static inline dimensionType upperBound()
  { return std::numeric_limits<dimensionType>::max(); }

  static inline bool isContinuous()
  { return false; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getParticleState().getCollisionNumber(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getParticleState().getCollisionNumber();
    range_end = range_start;
  }
};

/*! \brief The specialization of the ObserverPhaseSpaceDimensionTraits for
 * OBSERVER_SOURCE_ID_DIMENSION
 * \ingroup observer_phase_space_dim_traits
 */
template<>
struct ObserverPhaseSpaceDimensionTraits<OBSERVER_SOURCE_ID_DIMENSION>
{
  typedef MonteCarlo::ModuleTraits::InternalROIHandle dimensionType;

  typedef Teuchos::Array<dimensionType> dimensionBinType;

  typedef boost::mpl::bool_<false> isOrdered;

  static inline std::string name()
  { return "Source Id"; }

  static inline std::string basicName()
  { return "Source_Id"; }

  static inline dimensionType lowerBound()
  { return 0; }

  static inline dimensionType upperBound()
  { return std::numeric_limits<dimensionType>::max(); }

  static inline bool isContinuous()
  { return false; }

  static inline dimensionType getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  { return particle_wrapper.getParticleState().getSourceId(); }

  static inline dimensionType getDimensionValue( const Teuchos::any& any_value )
  { return Teuchos::any_cast<dimensionType>( any_value ); }

  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    range_start = particle_wrapper.getParticleState().getSourceId();
    range_end = range_start;
  }
};

} // end MonteCarlo namespace

#endif // end MONTE_CARLO_OBSERVER_PHASE_SPACE_DIMENSION_TRAITS_HPP

//---------------------------------------------------------------------------//
// end MonteCarlo_ObserverPhaseSpaceDimensionTraits.hpp
//---------------------------------------------------------------------------//