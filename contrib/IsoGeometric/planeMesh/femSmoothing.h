#include <gmshfem/GmshFem.h>
#include <gmshfem/Formulation.h>
using namespace gmshfem::common;
using namespace gmshfem::domain;
using namespace gmshfem::post;
using namespace gmshfem::equation;
using namespace gmshfem::problem;
using namespace gmshfem::field;


void femSmoothing(const int physicalSurface,
                  const int physicalBoundary,
                  const int physicalPoints,
                  const double gravity,
                  const double ratio,
                  const std::vector<MVertex*> & nodes,
                  std::vector<double> & u)
{
  std::string gauss = "Gauss4";
  //const std::complex< double > im(0., 1.);

  // Domain domain;
  // if (physicalSurface != 0)
  //   domain |= Domain(2, physicalSurface);
  // Domain boundary;
  // if (physicalBoundary != 0)
  //   boundary |= Domain(1, physicalBoundary);
  // Domain points;
  // if (physicalPoints != 0)
  //   points |= Domain(0, physicalPoints);

  Domain domain;
  domain.addEntity(2, 0);
  Domain boundary;
  boundary.addEntity(1, 0);

  Formulation<double> gravityFormulation("Gravity_Formulation");

  Field<double, Form::Form0> gField("g", domain | boundary, FunctionSpaceTypeForm0::Lagrange);

  gravityFormulation.integral(grad(dof(gField)), grad(tf(gField)), domain, gauss);
  gravityFormulation.integral(gravity, tf(gField), domain, gauss);

  gField.addConstraint(boundary, 0.);

  gravityFormulation.pre();
  gravityFormulation.assemble();
  gravityFormulation.solve();


  save(gField);
  double minG = 0;
  auto gfunc = gField.getEvaluableFunction();
  for (size_t i = 0; i < nodes.size(); i++) {
    auto n = nodes[i];
    double tmpG = evaluate(gfunc, n->x(), n->y(), n->z());
    if (tmpG < minG) minG = tmpG;
  }



  Formulation<double> formulation("Surface_Expansion");

  Field<double, Form::Form0> uField("u", domain | boundary, FunctionSpaceTypeForm0::Lagrange);

  formulation.integral(grad(dof(uField)), grad(tf(uField)), domain, gauss);
  formulation.integral(-minG, tf(uField), domain, gauss);
  // formulation.integral(gField, tf(uField), domain, gauss);
  formulation.integral(gravity, tf(uField), domain, gauss);

  // formulation.integral(ratio, tf(uField), boundary, gauss);
  //formulation.integral(dof(uField), tf(uField), boundary, gauss);

  uField.addConstraint(boundary, 0.);

  formulation.pre();
  formulation.assemble();
  formulation.solve();

  save(uField);

  auto func = uField.getEvaluableFunction();
  u.resize(nodes.size());
  for (size_t i = 0; i < nodes.size(); i++) {
    auto n = nodes[i];
    int index = n->getIndex();
    u[index] = evaluate(func, n->x(), n->y(), n->z());
  }

}
