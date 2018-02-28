//---------------------------------------------------------------------------//
//!
//! \file   Utility_DistributionSerializationHelpers.hpp
//! \author Alex Robinson
//! \brief  Distribution serialization helper macro definitions
//!
//---------------------------------------------------------------------------//

#ifndef UTILITY_DISTRIBUTION_SERIALIZATION_HELPERS_HPP
#define UTILITY_DISTRIBUTION_SERIALIZATION_HELPERS_HPP

// FRENSIE Includes
#include "Utility_SerializationHelpers.hpp"

/*! Declare the version of a distribution class with two template parameters
 *
 * This macro must be called from the global namespace.
 * \ingroup boost_serialization_helpers
 * \ingroup univariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION2_VERSION( FullName, Version )  \
  BOOST_SERIALIZATION_CLASS2_VERSION( FullName, Utility, Version )

/*! Declare the version of a distribution class with three template parameters
 *
 * This macro must be called from the global namespace.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION3_VERSION( FullName, Version )  \
  BOOST_SERIALIZATION_CLASS3_VERSION( FullName, Utility, Version )

/*! Declare the version of a distribution class with four template parameters
 *
 * This macro must be called from the global namespace.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION4_VERSION( FullName, Version )  \
  BOOST_SERIALIZATION_CLASS4_VERSION( FullName, Utility, Version )

/*! Declare that a distribution class with two template parameters is abstract
 *
 * This macro must be called from the global namespace.
 * \ingroup boost_serialization_helpers
 * \ingroup univariate_distributions
 */
#define BOOST_SERIALIZATION_ASSUME_ABSTRACT_DISTRIBUTION2( FullName )   \
  BOOST_SERIALIZATION_ASSUME_ABSTRACT_CLASS2( FullName, Utility )

/*! \brief Declare that a distribution class with three template parameters is
 *  abstract
 *
 * This macro must be called from the global namespace.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_ASSUME_ABSTRACT_DISTRIBUTION3( FullName )   \
  BOOST_SERIALIZATION_ASSUME_ABSTRACT_CLASS3( FullName, Utility )

/*! \brief Declare the GUID (key) of a distribution class that has two template
 * parameters.
 *
 * The BaseName is the distribution class name without the UnitAware prefix.
 * \ingroup boost_serialization_helpers
 * \ingroup univariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION2_EXPORT_STANDARD_KEY( BaseName ) \
  BOOST_SERIALIZATION_CLASS2_EXPORT_STANDARD_KEY( UnitAware##BaseName, Utility ) 

/*! \brief Declare the GUID (key) of a distribution class that has three 
 * template parameters.
 *
 * The BaseName is the distribution class name without the UnitAware prefix.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION3_EXPORT_STANDARD_KEY( BaseName ) \
  BOOST_SERIALIZATION_CLASS3_EXPORT_STANDARD_KEY( UnitAware##BaseName, Utility )

/*! \brief Declare the GUID (key) of a distribution class that has four 
 * template parameters.
 *
 * The BaseName is the distribution class name without the UnitAware prefix.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION4_EXPORT_STANDARD_KEY( BaseName ) \
  BOOST_SERIALIZATION_CLASS4_EXPORT_STANDARD_KEY( UnitAware##BaseName, Utility ) 

/*! Register the GUID of a distribution class with two template parameters.
 *
 * This macro must be called after calling the 
 * BOOST_SERIALIZATION_DISTRIBUTION2_EXPORT_STANDARD_KEY.
 * \ingroup boost_serialization_helpers
 * \ingroup univariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION2_EXPORT_IMPLEMENT( FullName )  \
  BOOST_SERIALIZATION_CLASS2_EXPORT_IMPLEMENT( FullName, Utility )

/*! Register the GUID of a distribution class with three template parameters.
 *
 * This macro must be called after calling the 
 * BOOST_SERIALIZATION_DISTRIBUTION3_EXPORT_STANDARD_KEY.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION3_EXPORT_IMPLEMENT( FullName )  \
  BOOST_SERIALIZATION_CLASS3_EXPORT_IMPLEMENT( FullName, Utility )

/*! Register the GUID of a distribution class with four template parameters.
 *
 * This macro must be called after calling the 
 * BOOST_SERIALIZATION_DISTRIBUTION3_EXPORT_STANDARD_KEY.
 * \ingroup boost_serialization_helpers
 * \ingroup bivariate_distributions
 */
#define BOOST_SERIALIZATION_DISTRIBUTION4_EXPORT_IMPLEMENT( FullName )  \
  BOOST_SERIALIZATION_CLASS4_EXPORT_IMPLEMENT( FullName, Utility )

#endif // end UTILITY_DISTRIBUTION_SERIALIZATION_HELPERS_HPP

//---------------------------------------------------------------------------//
// end Utility_DistributionSerializationHelpers.hpp
//---------------------------------------------------------------------------//