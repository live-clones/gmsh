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

struct dgDofContainer {
private:
  dgDofContainer (const dgDofContainer&);  
  int totalNbElements; 
  int nbFields;
  dgGroupCollection &_groups;
public:
  int _dataSize; // the full data size i.e. concerning all groups (not ghost, see bellow)
  int _dataSizeGhost; 
  std::vector<fullMatrix<double> *> _dataProxys; // proxys 
  fullVector<double> * _data; // the full data itself
  fullVector<double> * _ghostData;
  inline int getDataSize(){return _dataSize;}
  inline fullMatrix<double> &getGroupProxy(int gId){ return *(_dataProxys[gId]); }
  dgDofContainer (dgGroupCollection &groups, const dgConservationLaw &claw);
  ~dgDofContainer ();  
  int getNbElements() {return totalNbElements;}
};

class binding;


class dgSystemOfEquations {
//////////////
  //parallel section, should be moved to a new class
  int *shiftSend,*shiftRecv;
  int *nGhostElements,*nParentElements;
  int totalSend, totalRecv;
  public :
  void scatter(dgDofContainer *solution);
  std::vector< std::vector<std::pair<int,int> > >_elementsToSend; //{group,id} of the elements to send to each proc
//////////////
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
  void setOrder (int order); // set the polynomial order
  void setConservationLaw (dgConservationLaw *law); // set the conservationLaw
  dgSystemOfEquations(GModel *_gm);
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
    return fullMatrix<double> ( *_solution->_dataProxys [iGroup] ,
				iElement * _claw->nbFields(),_claw->nbFields());
  }
  void export_solution_as_is (const std::string &fileName);
  void saveSolution (std::string fileName) ;
  void loadSolution (std::string fileName);
  ~dgSystemOfEquations();
};

#endif // _DG_SYSTEM_OF_EQUATIONS_

