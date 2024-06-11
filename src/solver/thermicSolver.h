// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef THERMIC_SOLVER_H
#define THERMIC_SOLVER_H

#include <map>
#include <string>
#include "GmshConfig.h"
#include "SVector3.h"
#include "dofManager.h"
#include "simpleFunction.h"
#include "functionSpace.h"

class GModel;
class PView;
class groupOfElements;
class gLevelset;

struct LagrangeMultiplierFieldT {
  int _tag;
  groupOfElements *g;
  double _tau;
  simpleFunction<double> *_f;
  LagrangeMultiplierFieldT() : _tag(0), g(nullptr) {}
};

struct thermicField {
  int _tag; // tag for the dofManager
  groupOfElements *g; // support for this field
  double _k; // diffusivity
  thermicField() : _tag(0), g(nullptr) {}
};

struct BoundaryConditionT {
  int _tag; // tag for the dofManager
  enum location { UNDEF, ON_VERTEX, ON_EDGE, ON_FACE, ON_VOLUME };
  location onWhat; // on vertices or elements
  groupOfElements *g; // support for this BC
  BoundaryConditionT() : _tag(0), onWhat(UNDEF), g(nullptr) {}
};

struct dirichletBCT : public BoundaryConditionT {
  simpleFunction<double> *_f;
  dirichletBCT() : BoundaryConditionT(), _f(nullptr) {}
};

struct neumannBCT : public BoundaryConditionT {
  simpleFunction<double> *_f;
  neumannBCT() : BoundaryConditionT(), _f(nullptr) {}
};
// a thermic solver ...
class thermicSolver {
protected:
  GModel *pModel;
  int _dim, _tag;
  dofManager<double> *pAssembler;
  FunctionSpace<double> *LagSpace;
  FunctionSpace<double> *LagrangeMultiplierSpace;

  // young modulus and poisson coefficient per physical
  std::vector<thermicField> thermicFields;
  std::vector<LagrangeMultiplierFieldT> LagrangeMultiplierFields;
  // neumann BC
  std::vector<neumannBCT> allNeumann;
  // dirichlet BC
  std::vector<dirichletBCT> allDirichlet;

public:
  thermicSolver(int tag)
    : _tag(tag), pAssembler(nullptr), LagSpace(nullptr), LagrangeMultiplierSpace(nullptr)
  {
  }

  virtual ~thermicSolver()
  {
    if(LagSpace) delete LagSpace;
    if(LagrangeMultiplierSpace) delete LagrangeMultiplierSpace;
    if(pAssembler) delete pAssembler;
  }
  void assemble(linearSystem<double> *lsys);
  virtual void setMesh(const std::string &meshFileName);
  void cutMesh(gLevelset *ls);
  void setThermicDomain(int phys, double k);
  void setLagrangeMultipliers(int phys, double tau, int tag,
                              simpleFunction<double> *f);
  void changeLMTau(int tag, double tau);
  void setEdgeTemp(int edge, simpleFunction<double> *f);
  void setFaceTemp(int face, simpleFunction<double> *f);
  void solve();
  double computeL2Norm(simpleFunction<double> *f);
  double computeLagNorm(int tag, simpleFunction<double> *f);
#if defined(HAVE_POST)
  virtual PView *buildTemperatureView(const std::string postFileName);
  virtual PView *buildLagrangeMultiplierView(const std::string &postFileName);
  PView *buildErrorEstimateView(const std::string &errorFileName,
                                simpleFunction<double> *sol);
#endif
};

#endif
