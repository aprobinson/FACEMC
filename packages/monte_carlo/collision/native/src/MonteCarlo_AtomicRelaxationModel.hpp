//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_AtomicRelaxationModel.hpp
//! \author Alex Robinson
//! \brief  Atomic relaxtion model base class declaration.
//!
//---------------------------------------------------------------------------//

#ifndef MONTE_CARLO_ATOMIC_RELAXATION_MODEL_HPP
#define MONTE_CARLO_ATOMIC_RELAXATION_MODEL_HPP

// FRENSIE Includes
#include "MonteCarlo_SubshellType.hpp"
#include "MonteCarlo_ParticleBank.hpp"

//! The atomic relaxation model base class
class AtomicRelaxationModel
{
  
public:

  //! Constructor
  AtomicRelaxationModel()
  { /* ... */ }

  //! Destructor
  ~AtomicRelaxationModel()
  { /* ... */ }

  //! Relax atom
  virtual void relaxAtom( const SubshellType vacancy_shell,
			  ParticleBank& bank ) const = 0;
};

#endif // end MONTE_CARLO_ATOMIC_RELAXATION_MODEL_HPP

//---------------------------------------------------------------------------//
// end MonteCarlo_AtomicRelaxationModel.hpp
//---------------------------------------------------------------------------//



