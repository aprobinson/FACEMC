//---------------------------------------------------------------------------//
//!
//! \file   Data_AdjointElectronPhotonRelaxationVolatileDataContainer.hpp
//! \author Luke Kersting
//! \brief  The native adjoint electron-photon-relaxation volatile data container class
//!
//---------------------------------------------------------------------------//

#ifndef DATA_ADJOINT_ELECTRON_PHOTON_RELAXATION_VOLATILE_DATA_CONTAINER_HPP
#define DATA_ADJOINT_ELECTRON_PHOTON_RELAXATION_VOLATILE_DATA_CONTAINER_HPP

// FRENSIE Includes
#include "Data_AdjointElectronPhotonRelaxationDataContainer.hpp"

namespace Data{

//! The electron-photon-relaxation volatile data container
class AdjointElectronPhotonRelaxationVolatileDataContainer : public AdjointElectronPhotonRelaxationDataContainer
{

public:

  //! Default constructor
  AdjointElectronPhotonRelaxationVolatileDataContainer();

  //! Constructor (from saved archive)
  AdjointElectronPhotonRelaxationVolatileDataContainer(
		   const std::string& archive_name,
		   const Utility::ArchivableObject::ArchiveType archive_type );

  // Add the setter member functions to the public interface
  using AdjointElectronPhotonRelaxationDataContainer::setAtomicNumber;
  using AdjointElectronPhotonRelaxationDataContainer::setMinPhotonEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setMaxPhotonEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setMinElectronEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setMaxElectronEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setCutoffAngleCosine;
  using AdjointElectronPhotonRelaxationDataContainer::setNumberOfAdjointMomentPreservingAngles;
  using AdjointElectronPhotonRelaxationDataContainer::setGridConvergenceTolerance;
  using AdjointElectronPhotonRelaxationDataContainer::setGridAbsoluteDifferenceTolerance;
  using AdjointElectronPhotonRelaxationDataContainer::setGridDistanceTolerance;

  // Relaxation functions
  using AdjointElectronPhotonRelaxationDataContainer::setSubshells;
  using AdjointElectronPhotonRelaxationDataContainer::setSubshellOccupancy;
  using AdjointElectronPhotonRelaxationDataContainer::setSubshellBindingEnergy;

  // Photon functions
  using AdjointElectronPhotonRelaxationDataContainer::setComptonProfileMomentumGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setComptonProfile;
  using AdjointElectronPhotonRelaxationDataContainer::setOccupationNumberMomentumGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setOccupationNumber;
  using AdjointElectronPhotonRelaxationDataContainer::setWallerHartreeScatteringFunctionMomentumGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setWallerHartreeScatteringFunction;
  using AdjointElectronPhotonRelaxationDataContainer::setWallerHartreeAtomicFormFactorMomentumGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setWallerHartreeAtomicFormFactor;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointPhotonEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointWallerHartreeIncoherentMaxEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointWallerHartreeIncoherentCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointImpulseApproxSubshellIncoherentMaxEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointImpulseApproxSubshellIncoherentCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointWallerHartreeCoherentCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointPairProductionEnergyDistributionGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointPairProductionEnergyDistribution;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointPairProductionEnergyDistributionNormConstantGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointPairProductionEnergyDistributionNormConstant;
  using AdjointElectronPhotonRelaxationDataContainer::setWallerHartreeTotalCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setImpulseApproxTotalCrossSection;

  // Electron functions
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElasticAngularEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointCutoffElasticAnglesAtEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointCutoffElasticPDFAtEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointCutoffElasticAngles;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointCutoffElasticPDF;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointMomentPreservingElasticDiscreteAnglesAtEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointMomentPreservingElasticWeightsAtEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointMomentPreservingElasticDiscreteAngles;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointMomentPreservingElasticWeights;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationRecoilEnergyAtIncomingEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationRecoilPDFAtIncomingEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationRecoilEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationRecoilPDF;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungPhotonEnergyAtIncomingEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungPhotonPDFAtIncomingEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungPhotonEnergy;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungPhotonPDF;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointAtomicExcitationEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointAtomicExcitationEnergyGain;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectronEnergyGrid;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointCutoffElasticCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointCutoffElasticCrossSectionThresholdEnergyIndex;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointScreenedRutherfordElasticCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointScreenedRutherfordElasticCrossSectionThresholdEnergyIndex;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointTotalElasticCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointTotalElasticCrossSectionThresholdEnergyIndex;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointMomentPreservingCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointMomentPreservingCrossSectionThresholdEnergyIndex;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointElectroionizationCrossSectionThresholdEnergyIndex;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointBremsstrahlungCrossSectionThresholdEnergyIndex;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointAtomicExcitationCrossSection;
  using AdjointElectronPhotonRelaxationDataContainer::setAdjointAtomicExcitationCrossSectionThresholdEnergyIndex;

  // Add the export member function to the public interface
  using AdjointElectronPhotonRelaxationDataContainer::exportData;

  // Add the packDataInString member function to the public interface
  using AdjointElectronPhotonRelaxationDataContainer::packDataInString;
};

} // end Data namespace

#endif // end DATA_ADJOINT_ELECTRON_PHOTON_RELAXATION_VOLATILE_DATA_CONTAINER_HPP

//---------------------------------------------------------------------------//
// end Data_AdjointElectronPhotonRelaxationVolatileDataContainer.hpp
//---------------------------------------------------------------------------//

