#ifndef _DG_SYSTEM_OF_EQUATIONS_
#define _DG_SYSTEM_OF_EQUATIONS_
#include <vector>
#include <utility>
#include "GmshConfig.h"
#include "GModel.h"
#include "dgGroupOfElements.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"
#include "dgLimiter.h"
#include "dgTransformNodalValue.h"
#include "dgDofContainer.h"


class binding;


class dgSystemOfEquations {
  private:
  // the mesh and the model
  GModel *_gm;
  dgGroupCollection _groups;
  // the conservation law
  dgConservationLaw *_claw;
  std::string _cLawName;
  // polynomial order (should be more general)
  int _order;
  // dimension of the problem
  int _dimension;
  // solution and righ hand sides
  dgDofContainer *_solution;
  dgDofContainer *_rightHandSide;
  dgSystemOfEquations(const dgSystemOfEquations &) {}
  double computeTimeStepMethodOfLines () const;
public:
  const dgConservationLaw * getLaw() const {return _claw;}
  const GModel            * getModel() const {return _gm;}
  void setOrder (int order); // set the polynomial order
  void setConservationLaw (dgConservationLaw *law); // set the conservationLaw
  dgSystemOfEquations(GModel *_gm);
  void setup (); // setup the groups and allocate
  void exportSolution (std::string filename); // export the solution
  void limitSolution (); // apply the limiter on the solution
  void L2Projection (const function *f); // assign the solution to a given function
  double RK44(double dt);
  double RK44_limiter(double dt);
  double RK44_TransformNodalValue(double dt);
  double RK44_TransformNodalValue_limiter(double dt);

  double ForwardEuler(double dt);

  double computeInvSpectralRadius();

  static void registerBindings(binding *b);

  void saveSolution (std::string fileName) ;
  void loadSolution (std::string fileName);

  ~dgSystemOfEquations();
};

#endif // _DG_SYSTEM_OF_EQUATIONS_

