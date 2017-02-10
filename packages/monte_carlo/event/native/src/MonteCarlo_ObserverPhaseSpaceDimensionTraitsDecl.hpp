//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_ObserverPhaseSpaceDimensionTraits.hpp
//! \author Alex Robinson
//! \brief  Observer phase space dimension traits class declaration
//!
//---------------------------------------------------------------------------//

#ifndef MONTE_CARLO_OBSERVER_PHASE_SPACE_DIMENSION_TRAITS_DECL_HPP
#define MONTE_CARLO_OBSERVER_PHASE_SPACE_DIMENSION_TRAITS_DECL_HPP

// Std Lib Includes
#include <string>

// Boost Includes
#include <boost/mpl/bool.hpp>

// Trilinos Includes
#include <Teuchos_any.hpp>

// FRENSIE Includes
#include "MonteCarlo_EstimatorParticleStateWrapper.hpp"
#include "MonteCarlo_ObserverPhaseSpaceDimension.hpp"
#include "Utility_Tuple.hpp"

/*! \defgroup observer_phase_space_dim_traits Observer Phase Space Dimension Traits
 * \ingroup traits
 */

namespace MonteCarlo{

/*! The undefined observer phase space dimension traits
 * \ingroup observer_phase_space_dim_traits
 */
template<typename DimensionType, ObserverPhaseSpaceDimension dimension>
struct UndefinedObserverPhaseSpaceDimensionTraits
{
  //! This function should not compile if there is any attempt to instantiate
  static inline void notDefined() { return DimensionType::desired_dimension_is_missing_specialization(); }
};

/*! This structure defines the properties of an observer phase space dimension.
 * \ingroup observer_phase_space_dim_traits
 */
template<ObserverPhaseSpaceDimension dimension>
struct ObserverPhaseSpaceDimensionTraits
{
  //! The value type associated with the dimension
  typedef double dimensionType;

  //! The value associated with a bin of the dimension
  typedef double dimensionBinType;

  //! Indicates if the dimension is ordered (ranges must be sorted)
  typedef boost::mpl::bool_<true> isOrdered;

  //! The name of the dimension
  static inline std::string name()
  {
    (void)UndefinedObserverPhaseSpaceDimensionTraits<dimensionType,dimension>::notDefined();
    return std::string();
  }

  //! The lower bound of the dimension
  static inline dimensionType lowerBound()
  {
    (void)UndefinedObserverPhaseSpaceDimensionTraits<dimensionType,dimension>::notDefined();
    return 0;
  }

  //! The upper bound of the dimension
  static inline dimensionType upperBound()
  {
    (void)UndefinedObserverPhaseSpaceDimensionTraits<dimensionType,dimension>::notDefined();
    return 0;
  }

  //! Extract a value from an estimator particle state wrapper
  static inline const dimensionType& getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
  {
    (void)UndefinedObserverPhaseSpaceDimensionTraits<dimensionType,dimension>::notDefined();
    return 0;
  }

  //! Extract a value from an Teuchos::any container
  static inline const dimensionType& getDimensionValue( const Teuchos::any& any_value )
  {
    (void)UndefinedObserverPhaseSpaceDimensionTraits<dimensionType,dimension>::notDefined();
    return 0;
  }

  //! Extract a value range from an estimator particle state wrapper
  static inline void getDimensionRange( const EstimatorParticleStateWrapper& particle_wrapper,
                                        dimensionType& range_start,
                                        dimensionType& range_end )
  {
    (void)UndefinedObserverPhaseSpaceDimensionTraits<dimensionType,dimension>::notDefined();
    return 0;
  }
};

/*! \brief This function allows access to the getDimensionValue 
 * ObserserPhaseSpaceDimension traits function
 * \ingrouop observer_phase_space_dim_traits
 */
template<ObserverPhaseSpaceDimension dimension>
inline typename ObserverPhaseSpaceDimensionTraits<dimension>::dimensionType
getDimensionValue( const EstimatorParticleStateWrapper& particle_wrapper )
{
  return ObserverPhaseSpaceDimensionTraits<dimension>::getDimensionValue(
                                                            particle_wrapper );
}

/*! This function allows access to the getDimensionvalue ObserverPhaseSpaceDimension
 * traits function
 * \ingroup observer_phase_space_dim_traits
 */
template<ObserverPhaseSpaceDimension dimension>
inline typename ObserverPhaseSpaceDimensionTraits<dimension>::dimensionType
getDimensionValue( const Teuchos::any& any_value )
{
  return ObserverPhaseSpaceDimensionTraits<dimension>::getDimensionValue( any_value );
}

/*! \brief This function allows access to the getDimensionRange 
 * ObserverPhaseSpaceDimension traits function
 * \ingroup observer_phase_space_dim_traits
 */
template<ObserverPhaseSpaceDimension dimension>
inline typename void getDimensionRange(
      const EstimatorParticleStateWrapper& particle_wrapper,
      ObserverPhaseSpaceDimensionTraits<dimension>::dimensionType& range_start,
      ObserverPhaseSpaceDimensionTraits<dimension>::dimensionType& range_end )
{
  return ObserverPhaseSpaceDimensionTraits<dimension>::getDimensionRange(
                                                              particle_wrapper,
                                                              range_start,
                                                              range_end );
}

} // end MonteCarlo namespace

#endif // end MONTE_CARLO_OBSERVER_PHASE_SPACE_DIMENSION_TRAITS_DECL_HPP

//---------------------------------------------------------------------------//
// end MonteCarlo_ObserverPhaseSpaceDimensionTraits.hpp
//---------------------------------------------------------------------------//