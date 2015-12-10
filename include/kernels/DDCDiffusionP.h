/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/

#ifndef DDCDIFFUSIONP_H
#define DDCDIFFUSIONP_H

#include "Kernel.h"

class DDCDiffusionP;

template<>
InputParameters validParams<DDCDiffusionP>();

class DDCDiffusionP : public Kernel
{
public:

  DDCDiffusionP(const InputParameters & parameters);

protected:

  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();
  virtual Real computeQpOffDiagJacobian(unsigned int jvar);

private:

  /// Porosity
  const MaterialProperty<Real> & _porosity;
  /// Fluid density
  const MaterialProperty<Real> & _density;
  /// Effective diffusivity
  const MaterialProperty<Real> & _diffusivity;
  /// Water density
  const MaterialProperty<Real> & _water_density;
  /// Solute density
  const MaterialProperty<Real> & _solute_density;

  /// Gradient of the solute mass fraction variable
  VariableGradient & _grad_solute_mass_fraction;
  /// Variable number of the solute mass fraction variable
  unsigned int _xvar;

};

#endif //DDCDIFFUSIONP_H
