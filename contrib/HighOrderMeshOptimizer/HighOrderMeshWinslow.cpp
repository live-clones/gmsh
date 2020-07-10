// HighOrderMeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#include "HighOrderMeshWinslow.hpp"
#include "GModel.h"
#include "GmshConfig.h"

#if defined(HAVE_SOLVER)

#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPoint.h"
#include "HighOrder.h"
#include "meshGFaceOptimize.h"
#include "GFace.h"
#include "GRegion.h"
#include "GeomMeshMatcher.h"
#include "Context.h"
#include "Numeric.h"
#include "dofManager.h"
#include "elasticityTerm.h"
#include "winslowTerm.h"
#include "laplaceTerm.h"
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"
#include "linearSystemCSR.h"
#include "OS.h"
#include "OpenNL_psm.h"

#if defined(_OPENMP)
#include <omp.h>
#endif

#ifndef MAX_NUM_THREADS_OMP_
#define MAX_NUM_THREADS_OMP_ 8
#endif

void HighOrderMeshWinslow(GModel *m, bool onlyVisible){
  bool CAD, complete;
  int meshOrder;

  double t1 = Cpu();
  Msg::StatusBar(true, "Applying Winslow smoothing to high-order mesh...");

  getMeshInfoForHighOrder(m, meshOrder, complete, CAD);
  highOrderWinslow how(m);
  // now we smooth mesh the internal vertices of the faces
  // we do that model face by model face
  std::vector<MElement *> bad;
  double worst;
  //Voir si on fait quelque chose pour les surfaces ou pas
  // checkHighOrderTriangles("Surface mesh", m, bad, worst);
  // {
  //   for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
  //     if(onlyVisible && !(*it)->getVisibility()) continue;
  //     std::vector<MElement *> v;
  //     v.insert(v.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
  //     v.insert(v.end(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
  //     if(CAD)
  //       hot.applySmoothingTo(v, (*it));
  //     else
  //       hot.applySmoothingTo(v, 1.e32, false);
  //   }
  // }
  // checkHighOrderTriangles("Final surface mesh", m, bad, worst);

  checkHighOrderTetrahedron("Volume mesh", m, bad, worst);
  {
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
      if(onlyVisible && !(*it)->getVisibility()) continue;
      std::vector<MElement *> v;
      v.insert(v.begin(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      v.insert(v.end(), (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      v.insert(v.end(), (*it)->prisms.begin(), (*it)->prisms.end());
      if((*it)->pyramids.size())
        Msg::Error("Pyramids not yet handled in high-order Winslow");
      how.applyWinslowTo(v, 1e-10);
    }
  }
  checkHighOrderTetrahedron("Final volume mesh", m, bad, worst);

  double t2 = Cpu();
  Msg::StatusBar(true, "Done applying Winslow to high-order mesh (%g s)",
                 t2 - t1);
}

void highOrderWinslow::_moveToStraightSidedLocation(MElement *e) const{
  for(int i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    std::map<MVertex *, SVector3>::const_iterator it =
      _straightSidedLocation.find(v);
    if(it != _straightSidedLocation.end()) {
      v->x() = it->second.x();
      v->y() = it->second.y();
      v->z() = it->second.z();
    }
  }
}

highOrderWinslow::highOrderWinslow(GModel *gm) : _gm(gm), _tag(111), _dim(2){
  _computeStraightSidedPositions();
}

highOrderWinslow::highOrderWinslow(GModel *gm, GModel *mesh, int order)
  : _gm(gm), _tag(111), _dim(2){
  GeomMeshMatcher::instance()->forceTomatch(gm, mesh, 1.e-5);
  GeomMeshMatcher::instance()->destroy();
  SetOrderN(gm, order, false, false);
  _computeStraightSidedPositions();
}

void highOrderWinslow::_computeStraightSidedPositions(){
  _clean();
  // compute straigh sided positions that are actually X,Y,Z positions
  // that are NOT always on curves and surfaces

  // points classified on model vertices shall not move !
  for(GModel::viter it = _gm->firstVertex(); it != _gm->lastVertex(); ++it) {
    if((*it)->points.size()) {
      MPoint *p = (*it)->points[0];
      MVertex *v = p->getVertex(0);
      _straightSidedLocation[v] = SVector3((*it)->x(), (*it)->y(), (*it)->z());
      _targetLocation[v] = SVector3((*it)->x(), (*it)->y(), (*it)->z());
    }
  }

  // compute stright sided positions of vertices that are classified on model
  // edges
  for(GModel::eiter it = _gm->firstEdge(); it != _gm->lastEdge(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      MLine *l = (*it)->lines[i];
      int N = l->getNumVertices() - 2;
      SVector3 p0((*it)->lines[i]->getVertex(0)->x(),
                  (*it)->lines[i]->getVertex(0)->y(),
                  (*it)->lines[i]->getVertex(0)->z());
      SVector3 p1((*it)->lines[i]->getVertex(1)->x(),
                  (*it)->lines[i]->getVertex(1)->y(),
                  (*it)->lines[i]->getVertex(1)->z());

      for(int j = 1; j <= N; j++) {
        const double xi = (double)(j) / (N + 1);
        //	printf("xi = %g\n",xi);
        const SVector3 straightSidedPoint = p0 * (1. - xi) + p1 * xi;
        MVertex *v = (*it)->lines[i]->getVertex(j + 1);
        if(_straightSidedLocation.find(v) == _straightSidedLocation.end()) {
          _straightSidedLocation[v] = straightSidedPoint;
          _targetLocation[v] = SVector3(v->x(), v->y(), v->z());
        }
      }
    }
  }

  // compute stright sided positions of vertices that are classified on model
  // faces
  for(GModel::fiter it = _gm->firstFace(); it != _gm->lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->mesh_vertices.size(); i++) {
      MVertex *v = (*it)->mesh_vertices[i];
      _targetLocation[v] = SVector3(v->x(), v->y(), v->z());
    }

    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MTriangle *t = (*it)->triangles[i];
      MFace face = t->getFace(0);
      const nodalBasis *fs = t->getFunctionSpace();
      for(int j = 0; j < t->getNumVertices(); j++) {
        if(t->getVertex(j)->onWhat() == *it) {
          const double t1 = fs->points(j, 0);
          const double t2 = fs->points(j, 1);
          SPoint3 pc = face.interpolate(t1, t2);
          _straightSidedLocation[t->getVertex(j)] =
            SVector3(pc.x(), pc.y(), pc.z());
        }
      }
    }
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++) {
      MQuadrangle *q = (*it)->quadrangles[i];
      MFace face = q->getFace(0);
      const nodalBasis *fs = q->getFunctionSpace();
      for(int j = 0; j < q->getNumVertices(); j++) {
        if(q->getVertex(j)->onWhat() == *it) {
          const double t1 = fs->points(j, 0);
          const double t2 = fs->points(j, 1);
          SPoint3 pc = face.interpolate(t1, t2);
          _straightSidedLocation[q->getVertex(j)] =
            SVector3(pc.x(), pc.y(), pc.z());
        }
      }
    }
  }

  for(GModel::riter it = _gm->firstRegion(); it != _gm->lastRegion(); ++it) {
    for(std::size_t i = 0; i < (*it)->mesh_vertices.size(); i++) {
      MVertex *v = (*it)->mesh_vertices[i];
      _targetLocation[v] = SVector3(v->x(), v->y(), v->z());
    }
    for(std::size_t i = 0; i < (*it)->tetrahedra.size(); i++) {
      _dim = 3;
      MTetrahedron *t = (*it)->tetrahedra[i];
      MTetrahedron t_1(
        (*it)->tetrahedra[i]->getVertex(0), (*it)->tetrahedra[i]->getVertex(1),
        (*it)->tetrahedra[i]->getVertex(2), (*it)->tetrahedra[i]->getVertex(3));
      const nodalBasis *fs = t->getFunctionSpace();
      for(int j = 0; j < t->getNumVertices(); j++) {
        if(t->getVertex(j)->onWhat() == *it) {
          double t1 = fs->points(j, 0);
          double t2 = fs->points(j, 1);
          double t3 = fs->points(j, 2);
          SPoint3 pc;
          t_1.pnt(t1, t2, t3, pc);
          _straightSidedLocation[t->getVertex(j)] =
            SVector3(pc.x(), pc.y(), pc.z());
        }
      }
    }
    for(std::size_t i = 0; i < (*it)->hexahedra.size(); i++) {
      _dim = 3;
      MHexahedron *h = (*it)->hexahedra[i];
      MHexahedron h_1(
        (*it)->hexahedra[i]->getVertex(0), (*it)->hexahedra[i]->getVertex(1),
        (*it)->hexahedra[i]->getVertex(2), (*it)->hexahedra[i]->getVertex(3),
        (*it)->hexahedra[i]->getVertex(4), (*it)->hexahedra[i]->getVertex(5),
        (*it)->hexahedra[i]->getVertex(6), (*it)->hexahedra[i]->getVertex(7));
      const nodalBasis *fs = h->getFunctionSpace();
      for(int j = 0; j < h->getNumVertices(); j++) {
        if(h->getVertex(j)->onWhat() == *it) {
          double t1 = fs->points(j, 0);
          double t2 = fs->points(j, 1);
          double t3 = fs->points(j, 2);
          SPoint3 pc;
          h_1.pnt(t1, t2, t3, pc);
          _straightSidedLocation[h->getVertex(j)] =
            SVector3(pc.x(), pc.y(), pc.z());
        }
      }
    }
    for(std::size_t i = 0; i < (*it)->prisms.size(); i++) {
      _dim = 3;
      MPrism *p = (*it)->prisms[i];
      MPrism p_1(
        (*it)->prisms[i]->getVertex(0), (*it)->prisms[i]->getVertex(1),
        (*it)->prisms[i]->getVertex(2), (*it)->prisms[i]->getVertex(3),
        (*it)->prisms[i]->getVertex(4), (*it)->prisms[i]->getVertex(5));
      const nodalBasis *fs = p->getFunctionSpace();
      for(int j = 0; j < p->getNumVertices(); j++) {
        if(p->getVertex(j)->onWhat() == *it) {
          double t1 = fs->points(j, 0);
          double t2 = fs->points(j, 1);
          double t3 = fs->points(j, 2);
          SPoint3 pc;
          p_1.pnt(t1, t2, t3, pc);
          _straightSidedLocation[p->getVertex(j)] =
            SVector3(pc.x(), pc.y(), pc.z());
        }
      }
    }
  }

  Msg::Info("High-order tools set up: %d nodes are considered",
            _straightSidedLocation.size());
}

void highOrderWinslow::_printJacobians(GModel *m, const char *nm){
  const int n = 100;
  double D[n][n], X[n][n], Y[n][n], Z[n][n];

  FILE *f = Fopen(nm, "w");
  fprintf(f, "View \"\"{\n");
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    for(std::size_t j = 0; j < (*it)->triangles.size(); j++) {
      MTriangle *t = (*it)->triangles[j];
      for(int i = 0; i < n; i++) {
        for(int k = 0; k < n - i; k++) {
          SPoint3 pt;
          double u = (double)i / (n - 1);
          double v = (double)k / (n - 1);
          t->pnt(u, v, 0, pt);
          D[i][k] = 0.; // mesh_functional_distorsion_2D(t, u, v);
          // X[i][k] = u;
          // Y[i][k] = v;
          // Z[i][k] = 0.0;
          X[i][k] = pt.x();
          Y[i][k] = pt.y();
          Z[i][k] = pt.z();
        }
      }
      for(int i = 0; i < n - 1; i++) {
        for(int k = 0; k < n - i - 1; k++) {
          fprintf(f,
                  "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%22.15E,%22.15E,%22.15E};\n",
                  X[i][k], Y[i][k], Z[i][k], X[i + 1][k], Y[i + 1][k],
                  Z[i + 1][k], X[i][k + 1], Y[i][k + 1], Z[i][k + 1], D[i][k],
                  D[i + 1][k], D[i][k + 1]);
          if(i != n - 2 && k != n - i - 2)
            fprintf(
              f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%22.15E,%22.15E,%22.15E};\n",
              X[i + 1][k], Y[i + 1][k], Z[i + 1][k], X[i + 1][k + 1],
              Y[i + 1][k + 1], Z[i + 1][k + 1], X[i][k + 1], Y[i][k + 1],
              Z[i][k + 1], D[i + 1][k], D[i + 1][k + 1], D[i][k + 1]);
        }
      }
    }
  }
  fprintf(f, "};\n");
  fclose(f);
}

void highOrderWinslow::makePosViewWithJacobians(const char *fn){
  _printJacobians(_gm, fn);
}

void highOrderWinslow::_picardIteration(std::vector<MElement *> &allElem, std::set<MVertex *, MVertexPtrLessThan> &vertices){
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif
  dofManager<double> myAssembler(lsys);
  winslowTerm winsTerm(0, 1.0, .333, _tag);
  // Boundary conditions
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin();
      it != vertices.end(); ++it) {
    MVertex *vert = *it;
    std::map<MVertex *, SVector3>::iterator itt = _targetLocation.find(vert);
    // impose displacement @ boundary
    if(itt != _targetLocation.end() && vert->onWhat()->dim() < _dim) {
      myAssembler.fixVertex(vert, 0, _tag, itt->second.x() - vert->x());
      myAssembler.fixVertex(vert, 1, _tag, itt->second.y() - vert->y());
      myAssembler.fixVertex(vert, 2, _tag, itt->second.z() - vert->z());
    }
    // ensure we do not touch any vertex that is on the boundary
    else if(vert->onWhat()->dim() < _dim) {
      myAssembler.fixVertex(vert, 0, _tag, 0);
      myAssembler.fixVertex(vert, 1, _tag, 0);
      myAssembler.fixVertex(vert, 2, _tag, 0);
    }
    // number vertices
    myAssembler.numberVertex(vert, 0, _tag);
    myAssembler.numberVertex(vert, 1, _tag);
    myAssembler.numberVertex(vert, 2, _tag);
  }
  //Assemblage matrice and Rhs
  if(myAssembler.sizeOfR()){
    groupOfElements groupAllElem(allElem);
    // assembly of the elasticity term on the
    winsTerm.addToMatrix(myAssembler, groupAllElem, groupAllElem);
    winsTerm.addToRightHandSide(myAssembler, groupAllElem);
    Msg::Info("Solving linear system (%d unknowns)...", myAssembler.sizeOfR());
    // solve the system
    lsys->systemSolve();
  }
  //calcul matrice elementaire
  
  //solve
  
  delete lsys;
  return;
}

double highOrderWinslow::applyWinslowTo(std::vector<MElement *> &all, double precision){
  if(_dim!=3){
    Msg::Error("Winslow high-order optimizer implemented only for 3D");
  }
  Msg::Info("Computing Winslow smoothing...");
  for(std::size_t i = 0; i < all.size(); i++)
    _moveToStraightSidedLocation(all[i]);
  // Solutions containers
  std::map<MVertex *, SVector3> currentSolution;
  std::map<MVertex *, SVector3> newSolution;
  // indexing nodes ?
  std::set<MVertex *, MVertexPtrLessThan> vertices;
  for(std::size_t i = 0; i < all.size(); i++) {
    for(int j = 0; j < all[i]->getNumVertices(); j++) {
      MVertex *vert = all[i]->getVertex(j);
      vertices.insert(vert);
    }
  }
  double epsilon=1e10;
  while(epsilon>precision){
    // _picardIteration(all, vertices, currentSol, newSol);
    // _computeErrorPicard(currentSol, newSol);
    // -- fct picard iterations (*elem, currentSol, newSol)
    // -- calcul epsilon
    // apply displacements
  }

  
  return 0.0;
}

#else

void HighOrderMeshWinslow(GModel *m, bool onlyVisible)
{
  Msg::Error("Winslow high-order optimizer requires the solver module");
}

#endif
