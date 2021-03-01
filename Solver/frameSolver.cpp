// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "GModel.h"
#include "GVertex.h"
#include "GEdge.h"
#include "frameSolver.h"
#include "linearSystemCSR.h"
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#endif

frameSolver2d::frameSolver2d(GModel *gm) : pAssembler(nullptr), _myModel(gm) {}

void frameSolver2d::addFixations(const std::vector<int> &dirs,
                                 const std::vector<int> &modelVertices,
                                 double value)
{
  for(std::size_t j = 0; j < modelVertices.size(); j++) {
    GVertex *gv = _myModel->getVertexByTag(modelVertices[j]);
    if(gv) {
      for(std::size_t i = 0; i < dirs.size(); i++) {
        _fixations.push_back(gmshFixation(gv, dirs[i], value));
      }
    }
  }
}

void frameSolver2d::addNodalForces(const std::vector<int> &modelVertices,
                                   const std::vector<double> &force)
{
  for(std::size_t j = 0; j < modelVertices.size(); j++) {
    GVertex *gv = _myModel->getVertexByTag(modelVertices[j]);
    if(gv) {
      _nodalForces.push_back(std::make_pair(gv, force));
    }
  }
}

void frameSolver2d::addBeamsOrBars(const std::vector<int> &modelEdges, double E,
                                   double I, double A, int r[2])
{
  int r_middle[2] = {1, 1}, r_left[2] = {r[0], 1}, r_right[2] = {0, r[1]};
  //  printf("adding %d beams\n",modelEdges.size());
  for(std::size_t i = 0; i < modelEdges.size(); i++) {
    GEdge *ge = _myModel->getEdgeByTag(modelEdges[i]);
    if(ge) {
      //      printf("model edge %d found\n",ge->tag());
      for(std::size_t j = 0; j < ge->lines.size(); ++j) {
        MLine *l = ge->lines[j];
        if(j == 0 && j == ge->lines.size() - 1)
          _beams.push_back(gmshBeam2d(l, E, I, A, r));
        else if(j == 0)
          _beams.push_back(gmshBeam2d(l, E, I, A, r_left));
        else if(j == ge->lines.size() - 1)
          _beams.push_back(gmshBeam2d(l, E, I, A, r_right));
        else
          _beams.push_back(gmshBeam2d(l, E, I, A, r_middle));
      }
    }
  }
}

void frameSolver2d::addBeams(const std::vector<int> &modelEdges, double E,
                             double I, double A)
{
  int r[2] = {1, 1};
  addBeamsOrBars(modelEdges, E, I, A, r);
}

void frameSolver2d::addBars(const std::vector<int> &modelEdges, double E,
                            double I, double A)
{
  int r[2] = {0, 0};
  addBeamsOrBars(modelEdges, E, I, A, r);
}

// solve any time a parameter is modified
/*

  A vertex is connected to beams. The question
  is how many bars are rotuled

  We define 2 dofs per node

 */
void frameSolver2d::createDofs()
{
  //  printf("coucou %d fixations\n",_fixations.size());
  for(std::size_t i = 0; i < _fixations.size(); ++i) {
    const gmshFixation &f = _fixations[i];
    //    printf("f._vertex(%d) = %p %d
    //    %g\n",i,f._vertex,f._direction,f._value);
    MVertex *v = f._vertex->mesh_vertices[0];
    Dof DOF(v->getNum(), f._direction);
    pAssembler->fixDof(DOF, f._value);
  }

  //  printf("coucou2\n");
  computeRotationTags();
  //  printf("coucou3\n");
  for(std::size_t i = 0; i < _beams.size(); i++) {
    //    printf("beam[%d] rot %d
    //    %d\n",i,_beams[i]._rotationTags[0],_beams[i]._rotationTags[1]);
    for(std::size_t j = 0; j < 2; j++) {
      MVertex *v = _beams[i]._element->getVertex(j);
      Dof theta(v->getNum(),
                Dof::createTypeWithTwoInts(2, _beams[i]._rotationTags[j]));
      pAssembler->numberDof(theta);
      Dof U(v->getNum(), 0);
      pAssembler->numberDof(U);
      Dof V(v->getNum(), 1);
      pAssembler->numberDof(V);
    }
  }
  //  printf("%d dofs\n",pAssembler->sizeOfR());
}

void frameSolver2d::computeStiffnessMatrix(int iBeam, fullMatrix<double> &K)
{
  const gmshBeam2d &b = _beams[iBeam];
  const double BS = b._e * b._i / (b._l * b._l * b._l);
  const double TS = b._e * b._a / b._l;
  const MVertex *v1 = b._element->getVertex(0);
  const MVertex *v2 = b._element->getVertex(1);
  const double alpha = atan2(v2->y() - v1->y(), v2->x() - v1->x());
  const double C = cos(alpha);
  const double S = sin(alpha);

  printf("beam %d %g %g %g\n", iBeam, alpha, C, S);

  fullMatrix<double> R(6, 6);
  R(0, 0) = R(1, 1) = R(3, 3) = R(4, 4) = C;
  R(0, 1) = R(3, 4) = S;
  R(1, 0) = R(4, 3) = -S;
  R(2, 2) = R(5, 5) = 1.0;

  fullMatrix<double> k(6, 6);

  // tensile stiffness
  k(0, 0) = k(3, 3) = TS;
  k(0, 3) = k(3, 0) = -TS;
  // bending stiffness
  k(1, 1) = k(4, 4) = 12 * BS;
  k(2, 2) = k(5, 5) = 4. * BS * b._l * b._l;
  k(1, 2) = k(2, 1) = k(1, 5) = k(5, 1) = 6 * BS * b._l;
  k(4, 2) = k(2, 4) = k(4, 5) = k(5, 4) = -6 * BS * b._l;
  k(4, 1) = k(1, 4) = -12 * BS;
  k(5, 2) = k(2, 5) = -2 * BS * b._l * b._l;

  fullMatrix<double> Rt(R), temp(6, 6);
  Rt.transposeInPlace();
  Rt.mult(k, temp);
  temp.mult(R, K);
}

void frameSolver2d::solve()
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

  if(pAssembler) delete pAssembler;
  pAssembler = new dofManager<double>(lsys);

  // fix dofs and create free ones
  createDofs();

  // force vector
  auto it =
    _nodalForces.begin();
  for(; it != _nodalForces.end(); ++it) {
    MVertex *v = it->first->mesh_vertices[0];
    const std::vector<double> &F = it->second;
    Dof DOFX(v->getNum(), 0);
    Dof DOFY(v->getNum(), 1);
    pAssembler->assemble(DOFX, F[0]);
    pAssembler->assemble(DOFY, F[1]);
  }

  // stifness matrix
  for(std::size_t i = 0; i < _beams.size(); i++) {
    fullMatrix<double> K(6, 6);
    computeStiffnessMatrix(i, K);
    _beams[i]._stiffness = K;
    MVertex *v0 = _beams[i]._element->getVertex(0);
    MVertex *v1 = _beams[i]._element->getVertex(1);
    Dof theta0(v0->getNum(),
               Dof::createTypeWithTwoInts(2, _beams[i]._rotationTags[0]));
    Dof theta1(v1->getNum(),
               Dof::createTypeWithTwoInts(2, _beams[i]._rotationTags[1]));
    Dof U0(v0->getNum(), 0);
    Dof U1(v1->getNum(), 0);
    Dof V0(v0->getNum(), 1);
    Dof V1(v1->getNum(), 1);
    Dof DOFS[6] = {U0, V0, theta0, U1, V1, theta1};
    for(int j = 0; j < 6; j++) {
      for(int k = 0; k < 6; k++) {
        pAssembler->assemble(DOFS[j], DOFS[k], K(j, k));
      }
    }
  }
  lsys->systemSolve();

  // save the solution
  for(std::size_t i = 0; i < _beams.size(); i++) {
    MVertex *v0 = _beams[i]._element->getVertex(0);
    MVertex *v1 = _beams[i]._element->getVertex(1);
    Dof theta0(v0->getNum(),
               Dof::createTypeWithTwoInts(2, _beams[i]._rotationTags[0]));
    Dof theta1(v1->getNum(),
               Dof::createTypeWithTwoInts(2, _beams[i]._rotationTags[1]));
    Dof U0(v0->getNum(), 0);
    Dof U1(v1->getNum(), 0);
    Dof V0(v0->getNum(), 1);
    Dof V1(v1->getNum(), 1);
    Dof DOFS[6] = {U0, V0, theta0, U1, V1, theta1};
    for(int j = 0; j < 6; j++) {
      pAssembler->getDofValue(DOFS[j], _beams[i]._displacement[j]);
    }
  }
  delete lsys;
  delete pAssembler;
}

void frameSolver2d::exportFrameData(const char *DISPL, const char *M)
{
#if defined(HAVE_POST)
  {
    std::map<int, std::vector<double> > data;
    for(std::size_t i = 0; i < _beams.size(); i++) {
      std::vector<double> tmp;
      // tmp.push_back(_beams[i]._e);
      // tmp.push_back(_beams[i]._i);
      // tmp.push_back(_beams[i]._a);
      tmp.reserve(6);
      for(int j = 0; j < 6; j++) {
        tmp.push_back(_beams[i]._displacement[j]);
      }
      data[_beams[i]._element->getNum()] = tmp;
    }
    PView *pv = new PView("displacements", "Beam", _myModel, data, 0.0, 6);
    pv->getData()->writeMSH(DISPL);
    delete pv;
  }
  {
    std::map<int, std::vector<double> > data;
    for(std::size_t i = 0; i < _beams.size(); i++) {
      std::vector<double> tmp;
      fullVector<double> d(_beams[i]._displacement, 6), F(6);
      _beams[i]._stiffness.mult(d, F);
      tmp.push_back(-F(2));
      tmp.push_back(F(5));
      data[_beams[i]._element->getNum()] = tmp;
    }
    PView *pv =
      new PView("Momentum", "ElementNodeData", _myModel, data, 0.0, 1);
    pv->getData()->writeMSH(M);
    delete pv;
  }
#endif
}

void frameSolver2d::computeRotationTags()
{
  std::multimap<MVertex *, gmshBeam2d *> v2b;
  for(std::size_t i = 0; i < _beams.size(); i++) {
    v2b.insert(std::make_pair(_beams[i]._element->getVertex(0), &_beams[i]));
    v2b.insert(std::make_pair(_beams[i]._element->getVertex(1), &_beams[i]));
  }

  std::multimap<MVertex *, gmshBeam2d *>::iterator s_it;
  for(auto it = v2b.begin(); it != v2b.end(); it = s_it) {
    MVertex *theKey = it->first;

    std::pair<std::multimap<MVertex *, gmshBeam2d *>::iterator,
              std::multimap<MVertex *, gmshBeam2d *>::iterator>
      keyRange = v2b.equal_range(theKey);
    int countRotules = 0;
    for(s_it = keyRange.first; s_it != keyRange.second; ++s_it) {
      gmshBeam2d *b = s_it->second;
      if(!b->isRigid(theKey)) {
        b->setRotationTag(theKey, ++countRotules);
      }
    }
  }
}
