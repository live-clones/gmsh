#ifndef _DG_SYSTEM_OF_EQUATIONS_
#define _DG_SYSTEM_OF_EQUATIONS_
#include "GmshConfig.h"
#include "GModel.h"
#include "dgAlgorithm.h"
#include "dgGroupOfElements.h"
#include "dgAlgorithm.h"
#include "dgConservationLaw.h"
#include "Gmsh.h"

struct dgDofContainer {
private:
  dgDofContainer (const dgDofContainer&);  
public:
  int _dataSize; // the full data size i.e. concerning all groups
  fullVector<double> * _data; // the full data itself
  std::vector<fullMatrix<double> *> _dataProxys; // proxys 
  dgDofContainer (std::vector<dgGroupOfElements*> &groups, const dgConservationLaw &claw);
  ~dgDofContainer ();  
};

class methodBinding;
class constructorBinding;

class dgSystemOfEquations {
  // the mesh and the model
  GModel *_gm;
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
  // groups of elements (volume terms)
  std::vector<dgGroupOfElements*> _elementGroups;
  // groups of faces (interface terms)
  std::vector<dgGroupOfFaces*> _faceGroups;
  // groups of faces (boundary conditions)
  std::vector<dgGroupOfFaces*> _boundaryGroups;
  dgSystemOfEquations(const dgSystemOfEquations &) {}
public:
  void setOrder (int order); // set the polynomial order
  void setConservationLaw (dgConservationLaw *law); // set the conservationLaw
  dgSystemOfEquations(GModel *_gm);
  void setup (); // setup the groups and allocate
  void exportSolution (std::string filename); // export the solution
  double RK44 (double dt); 
  void L2Projection (std::string functionName); // assign the solution to a given function

  static const char className[];
  static const char parentClassName[];
  static methodBinding *methods[];
  static constructorBinding *constructorMethod;

  inline const fullMatrix<double> getSolutionProxy (int iGroup, int iElement){
    return fullMatrix<double> ( *_solution->_dataProxys [iGroup] ,
				iElement * _claw->nbFields(),_claw->nbFields());
  }
  void export_solution_as_is (const std::string &fileName);
  ~dgSystemOfEquations();
private:
};

#endif // _DG_SYSTEM_OF_EQUATIONS_

