//---------------------------------------------------------------------------//
//!
//! \file   MonteCarlo_AtomicExcitationElectronScatteringDistribution.hpp
//! \author Luke Kersting
//! \brief  The electron hard elastic scattering distribution base class
//!
//---------------------------------------------------------------------------//

#ifndef MONTE_CARLO_ATOMIC_EXCITATION_ELECTRON_SCATTERING_DISTRIBUTION_HPP
#define MONTE_CARLO_ATOMIC_EXCITATION_ELECTRON_SCATTERING_DISTRIBUTION_HPP

// Std Lib Includes
#include <limits>

// Boost Includes
#include <boost/function.hpp>
#include <boost/bind.hpp>

// Trilinos Includes
#include <Teuchos_Array.hpp>
#include <Teuchos_RCP.hpp>

// FRENSIE Includes
#include "MonteCarlo_ElectronState.hpp"
#include "MonteCarlo_ParticleBank.hpp"
#include "MonteCarlo_ElectronScatteringDistribution.hpp"
#include "Utility_OneDDistribution.hpp"

namespace MonteCarlo{

//! The atomic excitation scattering distribution base class
class AtomicExcitationElectronScatteringDistribution : public ElectronScatteringDistribution
{

public:

  //! Typedef for the atomic excitation distribution
  typedef Teuchos::RCP<const Utility::OneDDistribution> AtomicDistribution;

  //! Constructor
  AtomicExcitationElectronScatteringDistribution(
    const AtomicDistribution& energy_loss_distribution );

  //! Destructor 
  virtual ~AtomicExcitationElectronScatteringDistribution()
  { /* ... */ }

  //! Randomly scatter the electron
  void scatterElectron( ElectronState& electron,
	                    ParticleBank& bank,
                        SubshellType& shell_of_interaction ) const;

private:

  // elastic scattering distribution without forward screening data
  AtomicDistribution d_energy_loss_distribution;


};

} // end MonteCarlo namespace

#endif // end MONTE_CARLO_ATOMIC_EXCITATION_ELECTRON_SCATTERING_DISTRIBUTION_HPP

//---------------------------------------------------------------------------//
// end MonteCarlo_AtomicExcitationElectronScatteringDistribution.hpp
//---------------------------------------------------------------------------//