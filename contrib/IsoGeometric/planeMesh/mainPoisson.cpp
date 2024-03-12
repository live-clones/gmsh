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

  int order = std::stoi(fname.substr(fname.find("polyfit") + 7));
  std::string gauss = "Gauss" + std::to_string(2 * order + 1);
    
  gmsh::open(fname);

  Formulation< double > formulation("Poisson");

  Domain omega("surface");
  Domain gammaSmall("inner");
  Domain gammaBig("outer");

  Field< double, Form::Form0 > v("v", omega, FunctionSpaceTypeForm0::Lagrange, order);

  v.addConstraint(gammaBig, 0.);

  // v.addConstraint(gammaSmall, 1.);
  formulation.integral(0, tf(v), gammaSmall, gauss);

  formulation.integral(grad(dof(v)), grad(tf(v)), omega, gauss);
  formulation.integral(-1., tf(v), omega, gauss);

  formulation.pre();
  formulation.assemble();
  formulation.solve();

  save(v);

  return 0;
}
