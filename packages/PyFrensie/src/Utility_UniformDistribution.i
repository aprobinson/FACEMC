//---------------------------------------------------------------------------//
//!
//! \file   Utility_UniformDistribution.i
//! \author Alex Robinson
//! \brief  The uniform distribution swig interface file. Note that units
//!         will not be enabled in the interface.
//!
//---------------------------------------------------------------------------//

%{
#include "Utility_UniformDistribution.hpp"
#include "Utility_RandomNumberGenerator.hpp"
%}

%inline %{
//! Initialize the random number generator
void initFrensiePrng()
{
  // Initilize the random number generator
  Utility::RandomNumberGenerator::createStreams();
}
%}

%ignore Utility::UnitAwareOneDDistribution<void,void>::IndepUnit;
%ignore Utility::UnitAwareOneDDistribution<void,void>::DepUnit;
%ignore Utility::UnitAwareOneDDistribution<void,void>::IndepQuantity;
%ignore Utility::UnitAwareOneDDistribution<void,void>::InverseIndepQuantity;
%ignore Utility::UnitAwareOneDDistribution<void,void>::DepQuantity;
%ignore Utility::UnitAwareOneDDistribution<void,void>::getDistributionType;
%import "Utility_OneDDistribution.hpp"

%typemap(in) Utility::UnitAwareOneDDistribution<void,void>::IndepQuantity {
  $1 = PyFloat_AsDouble($input);
}

%typemap(out) Utility::UnitAwareOneDDistribution<void,void>::IndepQuantity {
  $result = PyFloat_FromDouble($1);
}

%typemap(out) Utility::UnitAwareOneDDistribution<void,void>::DepQuantity {
  $result = PyFloat_FromDouble($1);
}

%typemap(out) Utility::UnitAwareOneDDistribution<void,void>::InverseIndepQuantity {
  $result = PyFloat_FromDouble($1);
}

%template(OneDDistribution) Utility::UnitAwareOneDDistribution<void,void>;

%ignore Utility::UnitAwareTabularOneDDistribution<void,void>::IndepQuantity;
%ignore Utility::UnitAwareTabularOneDDistribution<void,void>::InverseIndepQuantity;
%ignore Utility::UnitAwareTabularOneDDistribution<void,void>::DepQuantity;
%import "Utility_TabularOneDDistribution.hpp"

%typemap(in) Utility::UnitAwareTabularOneDDistribution<void,void>::IndepQuantity {
  $1 = PyFloat_AsDouble($input);
}

%typemap(out) Utility::UnitAwareTabularOneDDistribution<void,void>::IndepQuantity {
  $result = PyFloat_FromDouble($1);
}

%typemap(out) Utility::UnitAwareTabularOneDDistribution<void,void>::DepQuantity {
  $result = PyFloat_FromDouble($1);
}

%typemap(out) Utility::UnitAwareTabularOneDDistribution<void,void>::InverseIndepQuantity {
  $result = PyFloat_FromDouble($1);
}

%template(TabularOneDDistribution) Utility::UnitAwareTabularOneDDistribution<void,void>;

%ignore Utility::UnitAwareUniformDistribution<void,void>::ThisType;
%ignore Utility::UnitAwareUniformDistribution<void,void>::IndepQuantity;
%ignore Utility::UnitAwareUniformDistribution<void,void>::InverseIndepQuantity;
%ignore Utility::UnitAwareUniformDistribution<void,void>::getDistributionType;
%ignore Utility::UnitAwareUniformDistribution<void,void>::fromUnitlessDistribution;
%ignore Utility::UnitAwareUniformDistribution<void,void>::DepQuantity;
%ignore Utility::UnitAwareUniformDistribution<void,void>::toStream;
%ignore Utility::UnitAwareUniformDistribution<void,void>::fromStream;
%ignore Utility::UnitAwareUniformDistribution<void,void>::sample( const IndepQuantity, const IndepQuantity );
%ignore Utility::UnitAwareUniformDistribution<void,void>::sampleAndRecordTrials( const IndepQuantity, const IndepQuantity, usigned& );
%ignore Utility::UnitAwareUniformDistribution<void,void>::sampleWithRandomNumber( const IndepQuantity, const IndepQuantity, double );
%import "Utility_UniformDistribution.hpp"

%typemap(in) Utility::UnitAwareUniformDistribution<void,void>::IndepQuantity {
  $1 = PyFloat_AsDouble($input);
}

%typemap(out) Utility::UnitAwareUniformDistribution<void,void>::IndepQuantity {
  $result = PyFloat_FromDouble($1);
}

%typemap(out) Utility::UnitAwareUniformDistribution<void,void>::DepQuantity {
  $result = PyFloat_FromDouble($1);
}

%typemap(out) Utility::UnitAwareUniformDistribution<void,void>::InverseIndepQuantity {
  $result = PyFloat_FromDouble($1);
}

%extend Utility::UnitAwareUniformDistribution<void,void> {
%template(UniformDistribution) Utility::UnitAwareUniformDistribution::UnitAwareUniformDistribution<double,double>;
};

%template(UniformDistribution) Utility::UnitAwareUniformDistribution<void,void>;





