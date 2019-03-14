//---------------------------------------------------------------------------//
//!
//! \file   DataGen_FreeGasElasticCrossSectionFactory.cpp
//! \author Eli Moll
//! \brief  Free gas elastic cross section factory
//!
//---------------------------------------------------------------------------//

// Std Lib Includes
#include <limits>

// Trilinos Includes
#include <Teuchos_ScalarTraits.hpp>

// FRENSIE Includes
#include "MonteCarlo_AceLaw4NuclearScatteringEnergyDistribution.hpp"
#include "Utility_TabularDistribution.hpp"
#include "Utility_ContractException.hpp"
#include "Utility_ExceptionTestMacros.hpp"
#include "Utility_SearchAlgorithms.hpp"
#include "Utility_RandomNumberGenerator.hpp"
#include "DataGen_FreeGasElasticCrossSectionFactory.hpp"

namespace DataGen{

//! Constructor
FreeGasElasticCrossSectionFactory::FreeGasElasticCrossSectionFactory(
    const std::string& file_name,
	  const std::string& table_name,
	  const unsigned table_start_line,
	  const bool is_ascii )
    : d_file_name( file_name ),
      d_table_name( table_name ),
      d_table_start_line( table_start_line ),
      d_is_ascii( is_ascii ),
      d_A(),
      d_kT(),
      d_energy_cutoff(),
      d_unmodified_elastic_cross_section(),
      d_zero_temperature_cross_section(),
      d_energy_array()
{
  // Set the value of pi^3
  d_pi3 = Utility::PhysicalConstants::pi*
          Utility::PhysicalConstants::pi*
          Utility::PhysicalConstants::pi;

  // Extract and convert the ACE elastic scattering cross section
  this->extractCrossSectionFromACE();
  this->extractAngularDistributionFromACE();
  this->convertCrossSectionToZeroTemperature();
  // this->generateFreeGasCrossSection();
}

// Accessor for zero-temperature elastic cross section
void FreeGasElasticCrossSectionFactory::getZeroTemperatureElasticCrossSection( 
      Teuchos::Array<double>& zero_temperature_cross_section )
{
  zero_temperature_cross_section = d_zero_temperature_cross_section;
}

// Accessor for energy array
void FreeGasElasticCrossSectionFactory::getEnergyArray(
      Teuchos::Array<double>& energy_array )
{
  energy_array = d_energy_array;
}

// Accessor for unmodified elastic cross section 
void FreeGasElasticCrossSectionFactory::getUnmodifiedElasticCrossSection(
      Teuchos::Array<double>& unmodified_cross_section )
{
  unmodified_cross_section = d_unmodified_elastic_cross_section;
}

// Extract the cross section from the specified 
void FreeGasElasticCrossSectionFactory::extractCrossSectionFromACE()
{
  // Construct the ACE file handler
  Teuchos::RCP<Data::ACEFileHandler> ace_file_handler( 
			  new Data::ACEFileHandler( d_file_name,
						                      d_table_name,
						                      1u ) );

  // Extract system parameters
  d_A  = ace_file_handler->getTableAtomicWeightRatio();
  d_kT = ace_file_handler->getTableTemperature();

  // Set the cutoff energy for upscattering from thermal treatment
  d_energy_cutoff = Utility::calculateBetaMax( d_A )*d_kT/3.0;

  // Extract the elastic cross section at kT from the XSS array
  Teuchos::RCP<Data::XSSNeutronDataExtractor> xss_neutron_data_extractor;
  xss_neutron_data_extractor.reset( 
    new Data::XSSNeutronDataExtractor( ace_file_handler->getTableNXSArray(),
				                               ace_file_handler->getTableJXSArray(),
				                               ace_file_handler->getTableXSSArray() ) );
  
  // Cross section extraction
  Teuchos::ArrayView<const double> elastic_cross_section = 
    xss_neutron_data_extractor->extractElasticCrossSection();
  const Teuchos::Array<double> elastic_cross_section_array( elastic_cross_section() );
  d_unmodified_elastic_cross_section();
  d_unmodified_elastic_cross_section = elastic_cross_section_array;

  // Energy grid extraction
  Teuchos::ArrayView<const double> energy_grid = 
    xss_neutron_data_extractor->extractEnergyGrid();
  const Teuchos::Array<double> energy_grid_array( energy_grid() );
  d_energy_array();
  d_energy_array = energy_grid_array;
}

// Extract the angular distribution from ACE (if exists)
void FreeGasElasticCrossSectionFactory::extractAngularDistributionFromACE()
{
  // Initialize the scattering probability distribution
  Teuchos::RCP<Utility::TabularOneDDistribution> isotropic_distribution(
        new Utility::UniformDistribution( -1.0, 1.0, 0.5 ) );

  // Initialize the scattering distribution
  MonteCarlo::NuclearScatteringAngularDistribution::AngularDistribution
    distribution( 2 );

  distribution[0].first = 0.0;
  distribution[0].second = isotropic_distribution;
  
  distribution[1].first = 20.0;
  distribution[1].second = isotropic_distribution;

  d_ace_angular_distribution.reset( 
      new MonteCarlo::NuclearScatteringAngularDistribution(
                    distribution ) );
}

// Convert cross section to zero-temperature cross section
void FreeGasElasticCrossSectionFactory::convertCrossSectionToZeroTemperature()
{
  Teuchos::Array<double> zero_temperature_cross_section;
  zero_temperature_cross_section = d_unmodified_elastic_cross_section;

  for ( int i = 0; i < d_energy_array.size(); ++i )
  {
    double E = d_energy_array[i];
    double a = std::sqrt(E * d_A/d_kT);
    double scaling_factor = ( 1  + 0.5/(a*a))*std::erf(a) + 
      std::exp(-1*a*a)/(a*std::sqrt(Utility::PhysicalConstants::pi));

    zero_temperature_cross_section[i] = zero_temperature_cross_section[i]/scaling_factor;
  }

  d_zero_temperature_cross_section();
  d_zero_temperature_cross_section = zero_temperature_cross_section;

  d_zero_temperature_cross_section_distribution.reset(
    new Utility::TabularDistribution<Utility::LinLin>( 
      d_energy_array,
      d_zero_temperature_cross_section ) );
}

// Generate the free gas S(alpha,beta) cross section
void FreeGasElasticCrossSectionFactory::generateFreeGasCrossSection()
{
  //std::vector<double> energy_array{1e-11, 1e-10, 1e-9, 1e-8, 1e-7, 1e-6, 1e-5, 1e-4, 1e-3, 1e-2, 1e-1, 1, 10};

  // Loop over all energies and generate the cross section value
  for( int i = 0; i < d_energy_array.size(); ++i )
  {
    // Assign the energy
    double E = d_energy_array[i];

    // Add the cross section value
    if (E > d_energy_cutoff)
    {
      d_free_gas_cross_section.append( 
        d_zero_temperature_cross_section_distribution->evaluate( E ) );
    }
    else
    {
      d_beta_function.reset( new DataGen::FreeGasElasticMarginalBetaFunction(
                    d_zero_temperature_cross_section_distribution, 
                    d_ace_angular_distribution,
                    d_A,
                    d_kT,
                    E ) );

      double xs_value = ( (d_A+1)*(d_A+1)*(d_A+1)*(d_A+1)*
        (d_kT/E)/(4*d_A*sqrt(d_pi3))*
         d_beta_function->getNormalizationConstant() );

      d_free_gas_cross_section.append( xs_value );
    }
  }

  d_free_gas_cross_section_distribution.reset( 
    new Utility::TabularDistribution<Utility::LinLin>( 
      d_energy_array,
      d_free_gas_cross_section ) );
}

void FreeGasElasticCrossSectionFactory::generateFreeGasPDF( double E, 
       Teuchos::Array<double>& free_gas_PDF )
{
  std::vector<double> test_energy{1e-11, 1e-9, 1e-7, 1e-6};
  Teuchos::Array<double> t_energy_array(test_energy);

  d_beta_function.reset( new DataGen::FreeGasElasticMarginalBetaFunction(
                    d_zero_temperature_cross_section_distribution, 
                    d_ace_angular_distribution,
                    d_A,
                    d_kT,
                    E ) );

  d_beta_function->populatePDF( t_energy_array );
  d_beta_function->getPDF( free_gas_PDF );
}

void FreeGasElasticCrossSectionFactory::generateFreeGasCDF( double E, 
       Teuchos::Array<double>& free_gas_CDF )
{
  d_beta_function.reset( new DataGen::FreeGasElasticMarginalBetaFunction(
                    d_zero_temperature_cross_section_distribution, 
                    d_ace_angular_distribution,
                    d_A,
                    d_kT,
                    E ) );

  d_beta_function->populateCDF( d_energy_array );
  d_beta_function->getCDF( free_gas_CDF );
}

void FreeGasElasticCrossSectionFactory::generateFreeGasPDFDistributions()
{
  std::vector<double> test_energy{1e-11, 1e-9, 1e-7, 1e-6};
  Teuchos::Array<double> t_energy_array(test_energy);

  MonteCarlo::AceLaw4NuclearScatteringEnergyDistribution::EnergyDistribution energy_distribution( t_energy_array.size() );

  for( int i = 0; i < t_energy_array.size(); ++i )
  {
    energy_distribution[i].first = t_energy_array[i];

    Teuchos::Array<double> pdf;
    
    this->generateFreeGasPDF( t_energy_array[i], pdf );

    energy_distribution[i].second.reset( new Utility::TabularDistribution<Utility::LinLin>( t_energy_array, pdf ) );
  }

  d_energy_distribution.reset( 
      new MonteCarlo::AceLaw4NuclearScatteringEnergyDistribution( energy_distribution ) );
}

void FreeGasElasticCrossSectionFactory::getEnergyDistribution( 
  Teuchos::RCP<MonteCarlo::AceLaw4NuclearScatteringEnergyDistribution>& distribution )
{
  distribution = d_energy_distribution;
}

// Extract Beta Distribution for Testing
void FreeGasElasticCrossSectionFactory::getFreeGasCrossSection( 
       Teuchos::Array<double>& free_gas_cross_section )
{
  free_gas_cross_section = d_free_gas_cross_section;
}

// Extract Beta Distribution for Testing
void FreeGasElasticCrossSectionFactory::getFreeGasCrossSectionDistribution( 
       Teuchos::RCP<Utility::OneDDistribution>& free_gas_cross_section_distribution )
{
  free_gas_cross_section_distribution = d_free_gas_cross_section_distribution;
}

} // end DataGen namespace

//---------------------------------------------------------------------------//
// end DataGen_FreeGasElasticCrossSectionFactory.cpp
//---------------------------------------------------------------------------//
