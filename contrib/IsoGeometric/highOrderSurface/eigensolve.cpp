#include <gmsh.h>
#include <gmshfem/Formulation.h>
#include <gmshfem/GmshFem.h>

using namespace gmshfem;
using namespace gmshfem::algebra;
using namespace gmshfem::common;
using namespace gmshfem::problem;
using namespace gmshfem::domain;
using namespace gmshfem::field;
using namespace gmshfem::function;
using namespace gmshfem::post;
using namespace gmshfem::equation;

#define OPT true


int main(int argc, char **argv)
{
  GmshFem gmshFem(argc, argv);

  unsigned int nMode = 5;
  gmshFem.userDefinedParameter(nMode, "nMode");
  bool withDamping = false;
  gmshFem.userDefinedParameter(withDamping, "withDamping");
  unsigned int basisOrder = 5;
  gmshFem.userDefinedParameter(basisOrder, "order");
  std::string gauss = "Gauss" + std::to_string(2 * basisOrder + 1);
  gmshFem.userDefinedParameter(gauss, "gauss");

  gmsh::open("polyfit"+std::to_string(basisOrder)+".msh");
  int physicalGroup = gmsh::model::addPhysicalGroup(2, {1});
  gmsh::model::setPhysicalName(2, physicalGroup, "surface");

  //*****
  // Problem declaration
  //*****

  Formulation< std::complex< double > > formulation("Laplacian modes");
  Domain omega("surface");

  Field< std::complex< double >, Form::Form0 > u("u", omega, FunctionSpaceTypeForm0::HierarchicalH1, basisOrder);
  //Field< std::complex< double >, Form::Form0 > u("u", omega, FunctionSpaceTypeForm0::Lagrange, basisOrder);

  // Mass
  formulation.integral(dt2_dof(u), tf(u), omega, gauss);
  // Damping
  if(withDamping) {
    formulation.integral(dt_dof(u), tf(u), omega, gauss);
  }
  // Stiffness
  formulation.integral(grad(dof(u)), grad(tf(u)), omega, gauss);

  formulation.pre();
  formulation.assemble(true);

  Vector< std::complex< double > > eigenvalues;
  formulation.eigensolve(eigenvalues, true, nMode);

  eigenvalues.save("eigenvalues");
  for(unsigned int i = 0; i < eigenvalues.size(); ++i) {
    msg::info << "Mode " << i << " of eigenvalue " << eigenvalues[i] << msg::endl;
    save(eigenfunction(u, i), omega, "mode_" + std::to_string(i));
  }

  return 0;
}
