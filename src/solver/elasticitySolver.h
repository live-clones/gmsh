// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ELASTICITY_SOLVER_H
#define ELASTICITY_SOLVER_H

#include <map>
#include <string>
#include "GmshConfig.h"
#include "SVector3.h"
#include "dofManager.h"
#include "functionSpace.h"

template <class scalar> class simpleFunction;
class GModel;
class PView;
class groupOfElements;
class gLevelset;

struct LagrangeMultiplierField {
  int _tag;
  groupOfElements *g;
  double _tau;
  SVector3 _d;
  simpleFunction<double> *_f;
  LagrangeMultiplierField() : _tag(0), g(nullptr) {}
};

struct elasticField {
  int _tag; // tag for the dofManager
  groupOfElements *g; // support for this field
  double _e, _nu; // specific elastic datas (should be somewhere else)
  elasticField() : _tag(0), g(nullptr) {}
};

struct BoundaryCondition {
  int _tag; // tag for the dofManager
  enum location { UNDEF, ON_VERTEX, ON_EDGE, ON_FACE, ON_VOLUME };
  location onWhat; // on vertices or elements
  groupOfElements *g; // support for this BC
  BoundaryCondition() : _tag(0), onWhat(UNDEF), g(nullptr) {}
};

struct dirichletBC : public BoundaryCondition {
  int _comp; // component
  simpleFunction<double> *_f;
  dirichletBC() : BoundaryCondition(), _comp(0), _f(nullptr) {}
};

struct neumannBC : public BoundaryCondition {
  simpleFunction<SVector3> *_f;
  neumannBC() : BoundaryCondition(), _f(nullptr) {}
};
// an elastic solver ...
class elasticitySolver {
public:
  GModel *pModel;
  int _dim, _tag;
  dofManager<double> *pAssembler;
  FunctionSpace<SVector3> *LagSpace;
  std::vector<FunctionSpace<double> *> LagrangeMultiplierSpaces;

  // young modulus and poisson coefficient per physical
  std::vector<elasticField> elasticFields;

  std::vector<LagrangeMultiplierField> LagrangeMultiplierFields;
  // neumann BC
  std::vector<neumannBC> allNeumann;
  // dirichlet BC
  std::vector<dirichletBC> allDirichlet;

public:
  elasticitySolver(int tag) : _tag(tag), pAssembler(nullptr), LagSpace(nullptr) {}

  elasticitySolver(GModel *model, int tag);

  void addDirichletBC(int dim, int entityId, int component, double value);
  void addDirichletBC(int dim, std::string phys, int component, double value);
  void addNeumannBC(int dim, int entityId, const std::vector<double> value);
  void addNeumannBC(int dim, std::string phys, const std::vector<double> value);
  void addElasticDomain(int tag, double e, double nu);
  void addElasticDomain(std::string phys, double e, double nu);

  virtual ~elasticitySolver()
  {
    if(LagSpace) delete LagSpace;
    for(std::size_t i = 0; i < LagrangeMultiplierSpaces.size(); i++)
      if(LagrangeMultiplierSpaces[i]) delete LagrangeMultiplierSpaces[i];
    LagrangeMultiplierSpaces.clear();
    if(pAssembler) delete pAssembler;
  }
  void assemble(linearSystem<double> *lsys);
  void readInputFile(const std::string &meshFileName);
  void read(const std::string s) { readInputFile(s.c_str()); }
  virtual void setMesh(const std::string &meshFileName, int dim = 0);
  void cutMesh(gLevelset *ls);
  void setElasticDomain(int phys, double E, double nu);
  void setLagrangeMultipliers(int phys, double tau, const SVector3 &d, int tag,
                              simpleFunction<double> *f);
  void changeLMTau(int tag, double tau);
  void setEdgeDisp(int edge, int comp, simpleFunction<double> *f);
  void solve();
  void postSolve();
  void exportKb();
  void computeEffectiveStiffness(std::vector<double> stiff);
  void computeEffectiveStrain(std::vector<double> strain);
  double computeDisplacementError(simpleFunction<double> *f0,
                                  simpleFunction<double> *f1,
                                  simpleFunction<double> *f2);
  double computeL2Norm(simpleFunction<double> *f0, simpleFunction<double> *f1,
                       simpleFunction<double> *f2);
  double computeLagNorm(int tag, simpleFunction<double> *f);

#if defined(HAVE_POST)
  virtual PView *buildDisplacementView(const std::string postFileName);
  virtual PView *buildStrainView(const std::string postFileName);
  virtual PView *buildStressesView(const std::string postFileName);
  virtual PView *buildLagrangeMultiplierView(const std::string &posFileName,
                                             int tag = -1);
  virtual PView *buildElasticEnergyView(const std::string postFileName);
  virtual PView *buildVonMisesView(const std::string postFileName);
  virtual PView *buildVolumeView(const std::string postFileName);
  virtual PView *buildErrorView(const std::string postFileName,
                                simpleFunction<double> *f0,
                                simpleFunction<double> *f1,
                                simpleFunction<double> *f2);
#endif
};

#endif
