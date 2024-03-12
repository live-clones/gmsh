#include <gmsh.h>
#include <gmshfem/Formulation.h>
#include <gmshfem/GmshFem.h>

using namespace gmshfem;
using namespace gmshfem::common;
using namespace gmshfem::problem;
using namespace gmshfem::domain;
using namespace gmshfem::field;
using namespace gmshfem::function;
using namespace gmshfem::post;
using namespace gmshfem::equation;

int main(int argc, char **argv)
{
  GmshFem gmshFem(argc, argv);

  std::string fname = "./0polyfit4.msh";
  gmshFem.userDefinedParameter(fname, "f");

  // int order = std::stoi(fname.substr(fname.find("polyfit") + 7));
  int order = 1;
  std::string gauss = "Gauss" + std::to_string(2 * order + 1);
    
  gmsh::open(fname);

  gmsh::model::mesh::generate(2);

  Formulation< double > formulation("Elasticity");

  Domain surface("surface");
  Domain bottom("bottom");
  Domain top("top");

  Field< double, Form::Form0 > ux("ux", surface, FunctionSpaceTypeForm0::Lagrange, order);
  Field< double, Form::Form0 > uy("uy", surface, FunctionSpaceTypeForm0::Lagrange, order);

  double lambda = 1., mu = 1.;

  TensorFunction< double > C_xx = tensor< double >((lambda + 2. * mu), 0., 0., 0., mu, 0., 0., 0., 0.);
  TensorFunction< double > C_xy = tensor< double >(0., lambda, 0., mu, 0., 0., 0., 0., 0.);
  TensorFunction< double > C_yx = tensor< double >(0., mu, 0., lambda, 0., 0., 0., 0., 0.);
  TensorFunction< double > C_yy = tensor< double >(mu, 0., 0., 0., (lambda + 2. * mu), 0., 0., 0., 0.);

  formulation.integral(C_xx * grad(dof(ux)), grad(tf(ux)), surface, gauss);
  formulation.integral(C_xy * grad(dof(uy)), grad(tf(ux)), surface, gauss);
  formulation.integral(C_yx * grad(dof(ux)), grad(tf(uy)), surface, gauss);
  formulation.integral(C_yy * grad(dof(uy)), grad(tf(uy)), surface, gauss);

  ux.addConstraint(bottom, 0.);
  uy.addConstraint(bottom, 0.);

  uy.addConstraint(top, .1);

  formulation.pre();
  formulation.assemble();
  formulation.solve();

  save(ux);
  save(uy);

  return 0;
}
