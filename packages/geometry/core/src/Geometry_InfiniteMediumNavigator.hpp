//---------------------------------------------------------------------------//
//!
//! \file   Geometry_InfiniteMediumNavigator.hpp
//! \author Alex Robinson
//! \brief  The infinite medium model navigator class declaration
//!
//---------------------------------------------------------------------------//

#ifndef GEOMETRY_INFINITE_MEDIUM_NAVIGATOR_HPP
#define GEOMETRY_INFINITE_MEDIUM_NAVIGATOR_HPP

// FRENSIE Includes
#include "Geometry_Navigator.hpp"
#include "Geometry_ExplicitTemplateInstantiationMacros.hpp"

namespace Geometry{

//! The infinite medium geometry navigator
class InfiniteMediumNavigator : public Navigator
{

public:

  //! Constructor
  InfiniteMediumNavigator( const InternalCellHandle infinite_medium_cell_id );

  //! Destructor
  ~InfiniteMediumNavigator();

  //! Get the location of a point w.r.t. a given cell
  PointLocation getPointLocation(
                                const Length position[3],
                                const double direction[3],
                                const InternalCellHandle cell ) const override;
  
  //! Get the surface normal at a point on the surface
  void getSurfaceNormal( const InternalSurfaceHandle surface_id,
                         const Length position[3],
                         const double direction[3],
                         double normal[3] ) const override;

  //! Find the cell that contains a given ray
  InternalCellHandle findCellContainingRay(
                                  const Length position[3],
                                  const double direction[3],
                                  CellIdSet& found_cell_cache ) const override;

  //! Find the cell that contains a given ray
  InternalCellHandle findCellContainingRay(
                                    const Length position[3],
                                    const double direction[3] ) const override;
  
  //! Check if an internal ray has been set
  bool isStateSet() const override;

  //! Set the internal ray with unknown starting cell
  void setState( const Length x_position,
                 const Length y_position,
                 const Length z_position,
                 const double x_direction,
                 const double y_direction,
                 const double z_direction ) override;
  
  //! Set the internal ray with known starting cell
  void setState( const Length x_position,
                 const Length y_position,
                 const Length z_position,
                 const double x_direction,
                 const double y_direction,
                 const double z_direction,
                 const InternalCellHandle start_cell ) override;

  //! Get the internal ray position
  const Length* getPosition() const override;

  //! Get the internal ray direction
  const double* getDirection() const override;

  //! Get the cell that contains the internal ray
  InternalCellHandle getCurrentCell() const override;

  //! Fire the internal ray through the geometry
  Length fireRay( InternalSurfaceHandle* surface_hit ) override;

  //! Advance the internal ray to the cell boundary
  bool advanceToCellBoundary( double* surface_normal ) override;

  //! Advance the internal ray by a substep (less than distance to boundary)
  void advanceBySubstep( const Length step_size ) override;

  //! Change the internal ray direction
  void changeDirection( const double x_direction,
                        const double y_direction,
                        const double z_direction ) override;

  //! Clone the navigator
  InfiniteMediumNavigator* clone() const override;

private:

  // Default constructor
  InfiniteMediumNavigator();

  // Save the model to an archive
  template<typename Archive>
  void save( Archive& ar, const unsigned version ) const;

  // Load the model from an archive
  template<typename Archive>
  void load( Archive& ar, const unsigned version );

  BOOST_SERIALIZATION_SPLIT_MEMBER();

  // Declare the boost serialization access object as a friend
  friend class boost::serialization::access;

  // The infinite medium cell id
  InternalCellHandle d_cell;
  
  // The position
  Length* d_position;

  // The direction
  double* d_direction;
};

} // end Geometry namespace

BOOST_SERIALIZATION_CLASS_VERSION( InfiniteMediumNavigator, Geometry, 0 );
BOOST_SERIALIZATION_CLASS_EXPORT_STANDARD_KEY( InfiniteMediumNavigator, Geometry );
EXTERN_EXPLICIT_GEOMETRY_CLASS_SAVE_LOAD_INST( InfiniteMediumNavigator );

#endif // end GEOMETRY_INFINITE_MEDIUM_NAVIGATOR_HPP

//---------------------------------------------------------------------------//
// end Geometry_InfiniteMediumNavigator.hpp
//---------------------------------------------------------------------------//