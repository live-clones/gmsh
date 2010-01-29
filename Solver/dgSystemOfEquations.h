#ifndef _DG_SYSTEM_OF_EQUATIONS_
#define _DG_SYSTEM_OF_EQUATIONS_
#include <vector>
#include <utility>
#include "GmshConfig.h"
#include "GModel.h"
#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"
#include "dgLimiter.h"
#include "dgDofContainer.h"


class binding;


class dgSystemOfEquations {
  private:
  // the mesh and the model
  GModel *_gm;
  dgGroupCollection _groups;
  // the algorithm that computes DG operators
  dgAlgorithm *_algo;
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
  std::pair<dgGroupOfElements*,int> getElementPosition (MElement *);
  void setOrder (int order); // set the polynomial order
  void setConservationLaw (dgConservationLaw *law); // set the conservationLaw
  dgSystemOfEquations(GModel *_gm);
  void createGroups(std::string groupType); // create groups from criterion: minEdge (2 groups), maxEdge (2 groups), elementType, allocate (same as setup())
  void setup (); // setup the groups and allocate
  void exportSolution (std::string filename); // export the solution
  void limitSolution (); // apply the limiter on the solution
  double RK44 (double dt);
  double RK44_limiter (double dt); 
  double ForwardEuler (double dt); 
  double multirateRK43 (double dt); 
  void L2Projection (std::string functionName); // assign the solution to a given function
  double computeInvSpectralRadius();

  static void registerBindings(binding *b);

  inline const fullMatrix<double> getSolutionProxy (int iGroup, int iElement){
    return fullMatrix<double> ( _solution->getGroupProxy(iGroup), iElement * _claw->nbFields(),_claw->nbFields());
  }
  void export_solution_as_is (const std::string &fileName);
  void saveSolution (std::string fileName) ;
  void loadSolution (std::string fileName);
  ~dgSystemOfEquations();
};

#endif // _DG_SYSTEM_OF_EQUATIONS_

