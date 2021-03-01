// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include "GmshConfig.h"
#include "thermicSolver.h"
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"
#include "Numeric.h"
#include "GModel.h"
#include "functionSpace.h"
#include "terms.h"
#include "solverAlgorithms.h"
#include "quadratureRules.h"
#include "solverField.h"
#include "MPoint.h"
#include "gmshLevelset.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

void thermicSolver::setMesh(const std::string &meshFileName)
{
  pModel = new GModel();
  pModel->readMSH(meshFileName.c_str());
  _dim = pModel->getNumRegions() ? 3 : 2;

  if(LagSpace) delete LagSpace;
  LagSpace = new ScalarLagrangeFunctionSpace(_tag);

  if(LagrangeMultiplierSpace) delete LagrangeMultiplierSpace;
  LagrangeMultiplierSpace = new ScalarLagrangeFunctionSpaceOfElement(_tag + 1);
}

void thermicSolver::solve()
{
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
  lsys->setGmres(1);
  lsys->setNoisy(1);
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif
  assemble(lsys);
  lsys->systemSolve();
  printf("-- done solving!\n");
}

void thermicSolver::cutMesh(gLevelset *ls)
{
  pModel = pModel->buildCutGModel(ls);
  pModel->writeMSH("cutMesh.msh");
}

void thermicSolver::setThermicDomain(int phys, double k)
{
  thermicField field;
  field._k = k;
  field._tag = _tag;
  field.g = new groupOfElements(_dim, phys);
  thermicFields.push_back(field);
}

void thermicSolver::changeLMTau(int tag, double tau)
{
  for(std::size_t i = 0; i < LagrangeMultiplierFields.size(); i++) {
    if(LagrangeMultiplierFields[i]._tag == tag) {
      LagrangeMultiplierFields[i]._tau = tau;
    }
  }
}

void thermicSolver::setLagrangeMultipliers(int phys, double tau, int tag,
                                           simpleFunction<double> *f)
{
  LagrangeMultiplierFieldT field;
  field._tau = tau;
  field._tag = tag;
  field._f = f;
  field.g = new groupOfElements(_dim - 1, phys);
  LagrangeMultiplierFields.push_back(field);
}

void thermicSolver::setEdgeTemp(int edge, simpleFunction<double> *f)
{
  dirichletBCT diri;
  diri.g = new groupOfElements(1, edge);
  diri._f = f;
  diri._tag = edge;
  diri.onWhat = BoundaryConditionT::ON_EDGE;
  allDirichlet.push_back(diri);
}

void thermicSolver::setFaceTemp(int face, simpleFunction<double> *f)
{
  dirichletBCT diri;
  diri.g = new groupOfElements(2, face);
  diri._f = f;
  diri._tag = face;
  diri.onWhat = BoundaryConditionT::ON_FACE;
  allDirichlet.push_back(diri);
}

void thermicSolver::assemble(linearSystem<double> *lsys)
{
  if(pAssembler) delete pAssembler;
  pAssembler = new dofManager<double>(lsys);

  // we first do all fixations. the behavior of the dofManager is to
  // give priority to fixations : when a dof is fixed, it cannot be
  // numbered afterwards

  // Dirichlet conditions
  for(std::size_t i = 0; i < allDirichlet.size(); i++) {
    FilterDofTrivial filter;
    FixNodalDofs(*LagSpace, allDirichlet[i].g->begin(),
                 allDirichlet[i].g->end(), *pAssembler, *allDirichlet[i]._f,
                 filter);
  }
  // LagrangeMultipliers
  for(std::size_t i = 0; i < LagrangeMultiplierFields.size(); ++i) {
    NumberDofs(*LagrangeMultiplierSpace, LagrangeMultiplierFields[i].g->begin(),
               LagrangeMultiplierFields[i].g->end(), *pAssembler);
  }
  // Thermic Fields
  for(std::size_t i = 0; i < thermicFields.size(); ++i) {
    NumberDofs(*LagSpace, thermicFields[i].g->begin(),
               thermicFields[i].g->end(), *pAssembler);
  }
  // Neumann conditions
  GaussQuadrature Integ_Boundary(GaussQuadrature::Val);
  for(std::size_t i = 0; i < allNeumann.size(); i++) {
    std::cout << "Neumann BC" << std::endl;
    LoadTerm<double> Lterm(*LagSpace, allNeumann[i]._f);
    Assemble(Lterm, *LagSpace, allNeumann[i].g->begin(), allNeumann[i].g->end(),
             Integ_Boundary, *pAssembler);
  }
  // Assemble cross term, laplace term and rhs term for LM
  GaussQuadrature Integ_LagrangeMult(GaussQuadrature::ValVal);
  GaussQuadrature Integ_Laplace(GaussQuadrature::GradGrad);
  for(std::size_t i = 0; i < LagrangeMultiplierFields.size(); i++) {
    printf("Lagrange Mult Lag\n");
    LagrangeMultiplierTerm<double> LagTerm(*LagSpace, *LagrangeMultiplierSpace,
                                           1.);
    Assemble(LagTerm, *LagSpace, *LagrangeMultiplierSpace,
             LagrangeMultiplierFields[i].g->begin(),
             LagrangeMultiplierFields[i].g->end(), Integ_LagrangeMult,
             *pAssembler);
    printf("Lagrange Mult Lap\n");
    LaplaceTerm<double, double> LapTerm(*LagrangeMultiplierSpace,
                                        -LagrangeMultiplierFields[i]._tau);
    Assemble(LapTerm, *LagrangeMultiplierSpace,
             LagrangeMultiplierFields[i].g->begin(),
             LagrangeMultiplierFields[i].g->end(), Integ_Laplace, *pAssembler);
    printf("Lagrange Mult Load\n");
    LoadTermOnBorder<double> Lterm(*LagrangeMultiplierSpace,
                                   LagrangeMultiplierFields[i]._f);
    Assemble(Lterm, *LagrangeMultiplierSpace,
             LagrangeMultiplierFields[i].g->begin(),
             LagrangeMultiplierFields[i].g->end(), Integ_Boundary, *pAssembler);
  }
  // Assemble thermic term
  GaussQuadrature Integ_Bulk(GaussQuadrature::ValVal);
  for(std::size_t i = 0; i < thermicFields.size(); i++) {
    printf("Thermic Term\n");
    LaplaceTerm<double, double> Tterm(*LagSpace, thermicFields[i]._k);
    Assemble(Tterm, *LagSpace, thermicFields[i].g->begin(),
             thermicFields[i].g->end(), Integ_Bulk, *pAssembler);
  }

  /*for (int i = 0;i<pAssembler->sizeOfR();i++){
    for (int j = 0;j<pAssembler->sizeOfR();j++){
      double d; lsys->getFromMatrix(i, j, d);
      printf("%g ", d);
    }
    double d; lsys->getFromRightHandSide(i, d);
    printf(" |  %g\n", d);
  }*/

  printf("nDofs=%d\n", pAssembler->sizeOfR());
  printf("nFixed=%d\n", pAssembler->sizeOfF());
}

double thermicSolver::computeL2Norm(simpleFunction<double> *sol)
{
  double val = 0.0;
  SolverField<double> solField(pAssembler, LagSpace);
  for(std::size_t i = 0; i < thermicFields.size(); ++i) {
    for(auto it =
          thermicFields[i].g->begin();
        it != thermicFields[i].g->end(); ++it) {
      MElement *e = *it;
      // printf("element (%g,%g) (%g,%g)
      // (%g,%g)\n",e->getVertex(0)->x(),e->getVertex(0)->y(),e->getVertex(1)->x(),e->getVertex(1)->y(),e->getVertex(2)->x(),e->getVertex(2)->y());
      int npts;
      IntPt *GP;
      double jac[3][3];
      int integrationOrder = 2 * (e->getPolynomialOrder() + 5);
      e->getIntegrationPoints(integrationOrder, &npts, &GP);
      for(int j = 0; j < npts; j++) {
        double u = GP[j].pt[0];
        double v = GP[j].pt[1];
        double w = GP[j].pt[2];
        double weight = GP[j].weight;
        double detJ = fabs(e->getJacobian(u, v, w, jac));
        SPoint3 p;
        e->pnt(u, v, w, p);
        double FEMVALUE;
        solField.f(e, u, v, w, FEMVALUE);
        double diff = (*sol)(p.x(), p.y(), p.z()) - FEMVALUE;
        val += diff * diff * detJ * weight;
        // printf("(%g %g) : detJ=%g we=%g FV=%g sol=%g
        // diff=%g\n",p.x(),p.y(),detJ,weight,FEMVALUE,(*sol)(p.x(), p.y(),
        // p.z()),diff);
      }
    }
  }
  printf("L2Norm = %g\n", sqrt(val));
  return sqrt(val);
}

double thermicSolver::computeLagNorm(int tag, simpleFunction<double> *sol)
{
  double val = 0.0, val2 = 0.0;
  SolverField<double> solField(pAssembler, LagrangeMultiplierSpace);
  for(std::size_t i = 0; i < LagrangeMultiplierFields.size(); ++i) {
    if(tag != LagrangeMultiplierFields[i]._tag) continue;
    for(auto it =
          LagrangeMultiplierFields[i].g->begin();
        it != LagrangeMultiplierFields[i].g->end(); ++it) {
      MElement *e = *it;
      // printf("element (%g,%g)
      // (%g,%g)\n",e->getVertex(0)->x(),e->getVertex(0)->y(),e->getVertex(1)->x(),e->getVertex(1)->y());
      int npts;
      IntPt *GP;
      double jac[3][3];
      int integrationOrder = 2 * (e->getPolynomialOrder() + 1);
      e->getIntegrationPoints(integrationOrder, &npts, &GP);
      for(int j = 0; j < npts; j++) {
        double u = GP[j].pt[0];
        double v = GP[j].pt[1];
        double w = GP[j].pt[2];
        double weight = GP[j].weight;
        double detJ = fabs(e->getJacobian(u, v, w, jac));
        SPoint3 p;
        e->getParent()->pnt(u, v, w, p);
        double FEMVALUE;
        solField.f(e, u, v, w, FEMVALUE);
        double diff = (*sol)(p.x(), p.y(), p.z()) - FEMVALUE;
        val += diff * diff * detJ * weight;
        val2 += (*sol)(p.x(), p.y(), p.z()) * (*sol)(p.x(), p.y(), p.z()) *
                detJ * weight;
        // printf("(%g %g) : u,v=(%g,%g) detJ=%g we=%g FV=%g sol=%g
        // diff=%g\n",p.x(),p.y(),u,v,detJ,weight,FEMVALUE,(*sol)(p.x(), p.y(),
        // p.z()),diff);
      }
    }
  }
  printf("LagNorm = %g\n", sqrt(val / val2));
  return sqrt(val / val2);
}

#if defined(HAVE_POST)

PView *thermicSolver::buildTemperatureView(const std::string postFileName)
{
  std::cout << "build Temperature View" << std::endl;
  std::set<MVertex *> v;
  std::map<MVertex *, MElement *> vCut;
  for(std::size_t i = 0; i < thermicFields.size(); ++i) {
    for(auto it =
          thermicFields[i].g->begin();
        it != thermicFields[i].g->end(); ++it) {
      MElement *e = *it;
      if(e->getParent()) {
        for(std::size_t j = 0; j < e->getNumVertices(); ++j) {
          if(vCut.find(e->getVertex(j)) == vCut.end())
            vCut[e->getVertex(j)] = e->getParent();
        }
      }
      else {
        for(std::size_t j = 0; j < e->getNumVertices(); ++j)
          v.insert(e->getVertex(j));
      }
    }
  }
  std::map<int, std::vector<double> > data;
  SolverField<double> Field(pAssembler, LagSpace);
  for(auto it = v.begin(); it != v.end(); ++it) {
    double val;
    MPoint p(*it);
    Field.f(&p, 0, 0, 0, val); // printf("valv=%g\n",val);
    std::vector<double> vec;
    vec.push_back(val);
    data[(*it)->getNum()] = vec;
  }
  for(auto it = vCut.begin();
      it != vCut.end(); ++it) {
    double val;
    double uvw[3];
    double xyz[3] = {it->first->x(), it->first->y(), it->first->z()};
    it->second->xyz2uvw(xyz, uvw);
    Field.f(it->second, uvw[0], uvw[1], uvw[2],
            val); // printf("valvc=%g\n",val);
    std::vector<double> vec;
    vec.push_back(val);
    data[it->first->getNum()] = vec;
  }
  PView *pv = new PView(postFileName, "NodeData", pModel, data, 0.0, 1);
  return pv;
}

PView *
thermicSolver::buildLagrangeMultiplierView(const std::string &postFileName)
{
  std::cout << "build Lagrange Multiplier View" << std::endl;
  if(!LagrangeMultiplierSpace) return new PView();
  std::set<MVertex *> v;
  for(std::size_t i = 0; i < LagrangeMultiplierFields.size(); ++i) {
    for(auto it =
          LagrangeMultiplierFields[i].g->begin();
        it != LagrangeMultiplierFields[i].g->end(); ++it) {
      MElement *e = *it;
      for(std::size_t j = 0; j < e->getNumVertices(); ++j)
        v.insert(e->getVertex(j));
    }
  }
  std::map<int, std::vector<double> > data;
  SolverField<double> Field(pAssembler, LagrangeMultiplierSpace);
  for(auto it = v.begin(); it != v.end(); ++it) {
    double val;
    MPoint p(*it);
    Field.f(&p, 0, 0, 0, val);
    std::vector<double> vec;
    vec.push_back(val);
    data[(*it)->getNum()] = vec;
  }
  PView *pv = new PView(postFileName, "NodeData", pModel, data, 0.0, 1);
  return pv;
}

PView *thermicSolver::buildErrorEstimateView(const std::string &errorFileName,
                                             simpleFunction<double> *sol)
{
  std::cout << "build Error View" << std::endl;
  std::map<int, std::vector<double> > data;

  SolverField<double> solField(pAssembler, LagSpace);
  for(std::size_t i = 0; i < thermicFields.size(); ++i) {
    for(auto it =
          thermicFields[i].g->begin();
        it != thermicFields[i].g->end(); ++it) {
      MElement *e = *it;
      int npts;
      IntPt *GP;
      double jac[3][3];
      int integrationOrder = 2 * (e->getPolynomialOrder() + 5);
      e->getIntegrationPoints(integrationOrder, &npts, &GP);
      double val = 0.0;
      for(int j = 0; j < npts; j++) {
        double u = GP[j].pt[0];
        double v = GP[j].pt[1];
        double w = GP[j].pt[2];
        double weight = GP[j].weight;
        double detJ = fabs(e->getJacobian(u, v, w, jac));
        SPoint3 p;
        e->pnt(u, v, w, p);
        double FEMVALUE;
        solField.f(e, u, v, w, FEMVALUE);
        double diff = (*sol)(p.x(), p.y(), p.z()) - FEMVALUE;
        val += diff * diff * detJ * weight;
      }
      std::vector<double> vec;
      vec.push_back(sqrt(val));
      data[e->getNum()] = vec;
    }
  }

  PView *pv = new PView(errorFileName, "ElementData", pModel, data, 0.0, 1);
  return pv;
}

#endif
