//---------------------------------------------------------------------------//
//!
//! \file   Utility_BasicBivariateDistribution.cpp
//! \author Alex Robinson
//! \brief  The basic bivariate distribution class template instantiations
//!
//---------------------------------------------------------------------------//

// Boost Includes
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

// FRENSIE Includes
#include "Utility_BasicBivariateDistribution.hpp"
#include "Utility_HDF5IArchive.hpp"
#include "Utility_HDF5OArchive.hpp"

namespace Utility{

// Explicit instantiation
EXPLICIT_DISTRIBUTION_INST( UnitAwareBasicBivariateDistribution<void,void,void> );
  
} // end Utility namespace

//---------------------------------------------------------------------------//
// end Utility_BasicBivariateDistribution.cpp
//---------------------------------------------------------------------------//