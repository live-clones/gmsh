// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _ELASTICITY_SOLVER_H_
#define _ELASTICITY_SOLVER_H_

#include <map>
#include <string>
#include "SVector3.h"
#include "dofManager.h"
#include "simpleFunction.h"

class GModel;
class PView;
class groupOfElements;

struct elasticField {
  int _tag; // tag for the dofManager
  groupOfElements *g; // support for this field
  simpleFunction<double> *_enrichment; // XFEM enrichment
  double _E,_nu; // specific elastic datas (should be somewhere else)
  elasticField () : g(0),_enrichment(0){}
};

// an elastic solver ...
class elasticitySolver{
 protected:
  GModel *pModel;
  int _dim, _tag;
  dofManager<double, double> *pAssembler;
  // young modulus and poisson coefficient per physical
  std::vector<elasticField > elasticFields;
  // imposed nodal forces
  std::map<int, SVector3> nodalForces;
  // imposed line forces
  std::map<int, SVector3> lineForces;
  // imposed face forces
  std::map<int, SVector3> faceForces;
  // imposed volume forces
  std::map<int, SVector3> volumeForces;
  // imposed nodal displacements
  std::map<std::pair<int,int>, double> nodalDisplacements;
  // imposed edge displacements
  std::map<std::pair<int,int>, double> edgeDisplacements;
  // imposed face displacements
  std::map<std::pair<int,int>, double> faceDisplacements;
 public:
  elasticitySolver(int tag) : _tag(tag) {}
  void addNodalForces (int iNode, const SVector3 &f)
  { 
    nodalForces[iNode] = f;
  }
  void addNodalDisplacement(int iNode, int dir, double val) 
  {
    nodalDisplacements[std::make_pair(iNode, dir)] = val;
  }
  //  void addElasticConstants(double e, double nu, int physical)
  //  {
  //    elasticConstants[physical] = std::make_pair(e, nu);
  //  }
  void setMesh(const std::string &meshFileName);  
  virtual void solve();  
  void readInputFile(const std::string &meshFileName);
  PView *buildDisplacementView(const std::string &postFileName);
  // PView *buildVonMisesView(const std::string &postFileName);
  // std::pair<PView *, PView*> buildErrorEstimateView
  //   (const std::string &errorFileName, double, int);
  // std::pair<PView *, PView*> buildErrorEstimateView
  //   (const std::string &errorFileName, const elasticityData &ref, double, int);
};

#endif
