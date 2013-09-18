//---------------------------------------------------------------------------//
//!
//! \file   TupleGetSetMemberPolicy.hpp
//! \author Alex Robinson
//! \brief  Tuple get and set member policy specializations
//!
//---------------------------------------------------------------------------//

#ifndef TUPLE_GET_SET_MEMBER_POLICY_HPP
#define TUPLE_GET_SET_MEMBER_POLICY_HPP

// FACEMC Includes
#include "TupleGetSetMemberPolicyDecl.hpp"
#include "Tuple.hpp"

namespace FACEMC{

/*! \brief The partial specialization of the FACEMC::TupleGetSetMemberPolicy for
 * the FIRST tuple member enumeration.
 * \ingroup tuple_gsm_policy
 */
template<typename T>
struct TupleGetSetMemberPolicy<T,FIRST>
{
  typedef typename T::firstType tupleMemberType;
  static inline tupleMemberType get(const T &tuple) { return tuple.first; }
  static inline void set(T &tuple, tupleMemberType value) { tuple.first = value; }
};

/*! \brief The partial specialization of the FACEMC::TupleGetSetMemberPolicy for
 * the SECOND tuple member enumeration.
 * \ingroup tuple_gsm_policy
 */
template<typename T>
struct TupleGetSetMemberPolicy<T,SECOND>
{
  typedef typename T::secondType tupleMemberType;
  static inline tupleMemberType get(const T &tuple) { return tuple.second; }
  static inline void set(T &tuple, tupleMemberType value) { tuple.second = value; }
};

/*! \brief The partial specialization of the FACEMC::TupleGetSetMemberPolicy for
 * the THIRD tuple member enumeration.
 * \ingroup tuple_gsm_policy
 */
template<typename T>
struct TupleGetSetMemberPolicy<T,THIRD>
{
  typedef typename T::thirdType tupleMemberType;
  static inline tupleMemberType get(const T &tuple) { return tuple.third; }
  static inline void set(T &tuple, tupleMemberType value) { tuple.third = value; }
};

/*! \brief The partial specialization of the FACEMC::TupleGetSetMemberPolicy for
 * the FOURTH tuple member enumeration.
 * \ingroup tuple_gsm_policy
 */
template<typename T>
struct TupleGetSetMemberPolicy<T,FOURTH>
{
  typedef typename T::fourthType tupleMemberType;
  static inline tupleMemberType get(const T &tuple) { return tuple.fourth; }
  static inline void set(T &tuple, tupleMemberType value) { tuple.fourth = value; }
};
  
} // end FACEMC namespace

#endif // end TUPLE_GET_SET_MEMBER_POLICY_HPP

//---------------------------------------------------------------------------//
// end TupleGetSetMemberPolicy.hpp
//---------------------------------------------------------------------------//
