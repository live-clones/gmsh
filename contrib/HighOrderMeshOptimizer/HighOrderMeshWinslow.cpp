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
#include "winslowAlphaTerm.h"
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
  printf("infos high order : order : %i / complete : %i / CAD %i\n",meshOrder,complete,CAD);
  highOrderWinslow how(m);
  how.smoothMesh(m,onlyVisible);

  double t2 = Cpu();
  Msg::StatusBar(true, "Done applying Winslow to high-order mesh (%g s)",
                 t2 - t1);
  
  // // now we smooth mesh the internal vertices of the faces
  // // we do that model face by model face
  // std::vector<MElement *> bad;
  // double worst;
  // //Voir si on fait quelque chose pour les surfaces ou pas
  // // checkHighOrderTriangles("Surface mesh", m, bad, worst);
  // // {
  // //   for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
  // //     if(onlyVisible && !(*it)->getVisibility()) continue;
  // //     std::vector<MElement *> v;
  // //     v.insert(v.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
  // //     v.insert(v.end(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
  // //     if(CAD)
  // //       hot.applySmoothingTo(v, (*it));
  // //     else
  // //       hot.applySmoothingTo(v, 1.e32, false);
  // //   }
  // // }
  // // checkHighOrderTriangles("Final surface mesh", m, bad, worst);
  
  // // Grab all boundary elements
  // std::vector<MElement *> boundaryElements;
  // for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
  //   boundaryElements.insert(boundaryElements.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
  //   boundaryElements.insert(boundaryElements.begin(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
  // }
  // //Compute face2el
  // std::vector<GEntity *> allGEnt;
  // m->getEntities(allGEnt,3);
  // MFaceVecMEltMap face2el;
  // for(int iEnt = 0; iEnt < allGEnt.size(); ++iEnt){
  //   GEntity *&gEnt = allGEnt[iEnt];
  //   calcFace2Elements(gEnt, face2el);
  // }
  
  // checkHighOrderTetrahedron("Volume mesh", m, bad, worst);
  // {
  //   for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
  //     if(onlyVisible && !(*it)->getVisibility()) continue;
  //     std::vector<MElement *> v;
  //     v.insert(v.begin(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
  //     v.insert(v.end(), (*it)->hexahedra.begin(), (*it)->hexahedra.end());
  //     v.insert(v.end(), (*it)->prisms.begin(), (*it)->prisms.end());
  //     if((*it)->pyramids.size())
  //       Msg::Error("Pyramids not yet handled in high-order Winslow");
  //     how.applyWinslowTo(m, v, boundaryElements, face2el, 1e-10);
  //   }
  // }
  // checkHighOrderTetrahedron("Final volume mesh", m, bad, worst);

  // double t2 = Cpu();
  // Msg::StatusBar(true, "Done applying Winslow to high-order mesh (%g s)",
  //                t2 - t1);
}

void highOrderWinslow::getBoundaryElementsRegionN(std::vector<MElement *> &boundaryElements, MFaceVecMEltMap &face2el, std::vector<MElement *> &eltsRegionN, std::vector<MElement *> &boundaryElementsRegionN){
  for(int i=0;i<boundaryElements.size();i++){
    MFace faceBnd = boundaryElements[i]->getFace(0);
    MFaceVecMEltMap::iterator itFace = face2el.find(faceBnd);
    bool inRegionN=false;
    if(itFace != face2el.end()){
      MElement *eVol = face2el[faceBnd][0];
      // std::vector<MElement *>::iterator itElReg = eltsRegionN.find(eVol);
      std::vector<MElement *>::iterator itElReg = std::find(eltsRegionN.begin(),eltsRegionN.end(),eVol);
      if(itElReg != eltsRegionN.end())
	inRegionN=true;
      // if interface
      if(face2el[faceBnd].size()>1){
	MElement *eVol1 = face2el[faceBnd][1];
	std::vector<MElement *>::iterator itElReg1 = std::find(eltsRegionN.begin(),eltsRegionN.end(),eVol1);
	// std::vector<MElement *>::iterator itElReg1 = eltsRegionN.find(eVol1);
	if(itElReg1 != eltsRegionN.end()){
	  inRegionN=true;
	  face2el[faceBnd][0]=eVol1;
	  face2el[faceBnd][1]=eVol;
	  printf("swap elements\n");
	}
      }
      if(inRegionN){
	boundaryElementsRegionN.push_back(boundaryElements[i]);
      }
    }
    else{
      printf("probleme finding face\n");
      exit(0);
    }
  }
  return;
}

void highOrderWinslow::smoothMesh(GModel *m, bool onlyVisible){
  
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
  
  // Grab all boundary elements
  std::vector<MElement *> boundaryElements;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    boundaryElements.insert(boundaryElements.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
    boundaryElements.insert(boundaryElements.begin(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
  }
  printf("boundary elements first : %i\n",boundaryElements.size());
  //Compute face2el
  std::vector<GEntity *> allGEnt;
  m->getEntities(allGEnt,3);
  MFaceVecMEltMap face2el;
  for(int iEnt = 0; iEnt < allGEnt.size(); ++iEnt){
    GEntity *&gEnt = allGEnt[iEnt];
    calcFace2Elements(gEnt, face2el);
  }
  
  checkHighOrderTetrahedron("Volume mesh", m, bad, worst);
  {
    int nR=0;
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
      nR++;
    int curR=0;
    for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
      curR++;
      if(curR==3||curR==2)//DBG
      	continue;
      printf("region %i over %i\n",curR,nR);
      if(onlyVisible && !(*it)->getVisibility()) continue;
      std::vector<MElement *> v;
      v.insert(v.begin(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      v.insert(v.end(), (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      v.insert(v.end(), (*it)->prisms.begin(), (*it)->prisms.end());
      if((*it)->pyramids.size())
        Msg::Error("Pyramids not yet handled in high-order Winslow");
      std::vector<MElement *> boundaryElementsRegionN;
      getBoundaryElementsRegionN(boundaryElements,face2el,v,boundaryElementsRegionN);
      this->applyWinslowTo(m, v, boundaryElementsRegionN, face2el, 1e-10);
      // this->applyWinslowTo(m, v, boundaryElements, face2el, 1e-10);
    }
  }
  checkHighOrderTetrahedron("Final volume mesh", m, bad, worst);
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

void highOrderWinslow::_picardPart1(std::vector<MElement *> &allElem,
				    std::vector<MElement *> &boundaryElem,
				    MFaceVecMEltMap &face2el,
				    std::set<MVertex *, MVertexPtrLessThan> &vertices,
				    std::map<MVertex *, SVector3> *currentSolution,
				    std::map<MVertex *, SVector3> *alpha,
				    int idAlphaComp){
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif
  // printf("*************** Solving alpha component %i\n",idAlphaComp);
  dofManager<double> myAssembler(lsys);
  winslowAlphaTerm winsAlphaTerm(0, &allElem, &face2el, currentSolution, idAlphaComp, _tag);
  // number vertices
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin();
      it != vertices.end(); ++it) {
    MVertex *vert = *it;
    myAssembler.numberVertex(vert, 0, _tag);
  }
  if(myAssembler.sizeOfR()){
    groupOfElements groupAllElem(allElem);
    groupOfElements groupBoundaryElem(boundaryElem);
    // assembly of the elasticity term on the
    winsAlphaTerm.addToMatrix(myAssembler, groupAllElem, groupAllElem);
    winsAlphaTerm.addToRightHandSide(myAssembler, groupAllElem);
    winsAlphaTerm.addToRightHandSide(myAssembler, groupBoundaryElem);
    // Msg::Info("Solving linear system (%d unknowns)...", myAssembler.sizeOfR());
    // solve the system
    lsys->systemSolve();
  }
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin();
      it != vertices.end(); ++it) {
    MVertex *vert = *it;
    double a;
    myAssembler.getDofValue(*it, 0, _tag, a);
    (*alpha)[*it][idAlphaComp]=a;
  }
  delete lsys;
  return;
}

void highOrderWinslow::_picardPart2(std::vector<MElement *> &allElem,
				    std::set<MVertex *, MVertexPtrLessThan> &vertices,
				    std::map<MVertex *, SVector3> *alpha,
				    std::map<MVertex *, SVector3> *currentSolution,
				    std::map<MVertex *, SVector3> *newSolution,
				    int idComponent){
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif
  dofManager<double> myAssembler(lsys);
  // printf("*************** Solving winslow component %i\n",idComponent);
  winslowTerm winsTerm(0, alpha, currentSolution, idComponent, _tag);
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin();
      it != vertices.end(); ++it) {
    MVertex *vert = *it;
    // Boundary conditions
    if(vert->onWhat()->dim() < _dim){
      if(idComponent==0)
      	myAssembler.fixVertex(vert, 0, _tag, (*currentSolution)[vert][0]);
      if(idComponent==1)
      	myAssembler.fixVertex(vert, 0, _tag, (*currentSolution)[vert][1]);
      if(idComponent==2)
      	myAssembler.fixVertex(vert, 0, _tag, (*currentSolution)[vert][2]);
    }
    // number vertices
    myAssembler.numberVertex(vert, 0, _tag);
  }
  //Assemblage matrice and Rhs
  if(myAssembler.sizeOfR()){
    groupOfElements groupAllElem(allElem);
    printf("add to mat\n");
    winsTerm.addToMatrix(myAssembler, groupAllElem, groupAllElem);
    printf("solve\n");
    lsys->systemSolve();
    printf("end solve component %i\n",idComponent);
  }
  //grab solution
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin();
      it != vertices.end(); ++it) {
    MVertex *vert = *it;
    double a;
    myAssembler.getDofValue(*it, 0, _tag, a);
    (*newSolution)[*it][idComponent]=a;
  }
  delete lsys;
  return;
}

void highOrderWinslow::_picardIteration(std::vector<MElement *> &allElem, std::vector<MElement *> &boundaryElem, MFaceVecMEltMap &face2el, std::set<MVertex *, MVertexPtrLessThan> &vertices, std::map<MVertex *, SVector3> *currentSolution, std::map<MVertex *, SVector3> *newSolution){
  std::map<MVertex *, SVector3> *alpha = new std::map<MVertex *, SVector3>;
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin(); it != vertices.end(); ++it)
    (*alpha)[*it]=SVector3(0.0);
  // First part: compute alpha (weak derivative contravMetric)
  printf("*************** Solving alpha\n");
#if defined(_OPENMP)
#pragma omp parallel
  {
#pragma omp for
#endif
    for(int i=0;i<3;i++)
      _picardPart1(allElem, boundaryElem, face2el, vertices, currentSolution, alpha, i);
#if defined(_OPENMP)
  }
#endif
  //Second part. Knowing alpha and the current solution, we can compute the new solution
  printf("*************** Solving x\n");
#if defined(_OPENMP)
#pragma omp parallel
  {
#pragma omp for
#endif
    for(int i=0;i<3;i++)
      _picardPart2(allElem, vertices, alpha, currentSolution, newSolution, i);
#if defined(_OPENMP)
  }
#endif  
  delete alpha;
  return;
}

double highOrderWinslow::_computeErrorPicard(std::map<MVertex *, SVector3> *currentSolution, std::map<MVertex *, SVector3> *newSolution){
  double error=0.0;
  for(std::map<MVertex *, SVector3, MVertexPtrLessThan>::iterator it = newSolution->begin(); it != newSolution->end(); ++it)
    for(int j=0;j<3;j++)
      error+=(it->second[j]-(*currentSolution)[it->first][j])*(it->second[j]-(*currentSolution)[it->first][j]);
  error=sqrt(error);
  return error;
}

void highOrderWinslow::calcFace2Elements(GEntity *entity, MFaceVecMEltMap &face2el)
{
  for(std::size_t iEl = 0; iEl < entity->getNumMeshElements(); iEl++) {
    MElement *elt = entity->getMeshElement(iEl);
    //    elt->setVisibility(0); // fordebug
    if(elt->getDim() == 3)
      for(int iFace = 0; iFace < elt->getNumFaces(); iFace++)
	face2el[elt->getFace(iFace)].push_back(elt);
  }
}

void highOrderWinslow::applyWinslowTo(GModel *gm,
				      std::vector<MElement *> &all,
				      std::vector<MElement *> &boundaryElements,
				      MFaceVecMEltMap &face2el,
				      double precision){
  //metric contrav changed to metroc cov in winsterm and winsalphaterm
  if(_dim!=3){
    Msg::Error("Winslow high-order optimizer implemented only for 3D");
    return;
  }
#if defined(_OPENMP)
  omp_set_num_threads(MAX_NUM_THREADS_OMP_);
#endif
  // std::vector<GEntity *> allGEnt;
  // gm->getEntities(allGEnt,3);
  // MFaceVecMEltMap face2el;
  // for(int iEnt = 0; iEnt < allGEnt.size(); ++iEnt){
  //   GEntity *&gEnt = allGEnt[iEnt];
  //   calcFace2Elements(gEnt, face2el);
  // }
  // std::vector<MElement *> boundaryElements; //FIXME: ici il y a toutes les faces. Il faut récupérer seulement celles du volume qui nou intéresse. De plus ce n'est pas forcément l'indice 0 de face2el dans le cas d'une interface
  // for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it){
  //   boundaryElements.insert(boundaryElements.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
  //   boundaryElements.insert(boundaryElements.begin(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
  // }
  // //DBG face2el
  // for(std::size_t i = 0; i < all.size(); i++){
  //   all[i]->setVisibility(0);
  // }
  // for(std::size_t i = 0; i < boundaryElements.size(); i++){
  //   face2el[boundaryElements[i]->getFace(0)][0]->setVisibility(1);
  // }

  printf("nElem : %i\n",all.size());
  printf("nFaces : %i\n",boundaryElements.size());
  Msg::Info("Computing Winslow smoothing...");
  for(std::size_t i = 0; i < all.size(); i++)
    _moveToStraightSidedLocation(all[i]);
  // Solutions containers
  std::map<MVertex *, SVector3> *currentSolution = new std::map<MVertex *, SVector3>;
  std::map<MVertex *, SVector3> *newSolution = new std::map<MVertex *, SVector3>;
  // indexing nodes ?
  std::set<MVertex *, MVertexPtrLessThan> vertices;
  for(std::size_t i = 0; i < all.size(); i++){
    for(int j = 0; j < all[i]->getNumVertices(); j++){
      MVertex *vert = all[i]->getVertex(j);
      vertices.insert(vert);
    }
  }
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin(); it != vertices.end(); ++it){
    MVertex *vert = *it;
    std::map<MVertex *, SVector3>::iterator itt = _targetLocation.find(vert);
    // high order displacement @ boundary
    if(itt != _targetLocation.end() && vert->onWhat()->dim() < _dim)
      (*currentSolution)[*it]=SVector3(itt->second.x(),itt->second.y(),itt->second.z());
    else
      (*currentSolution)[*it]=SVector3(vert->x(),vert->y(),vert->z());
    (*newSolution)[*it]=SVector3(0.0);
  }
  double epsilon=1e10;
  int nItMax=30;
  int nIt=0;
  while(epsilon>precision&&nIt<nItMax){
    printf("+++++++++++++++++++ picard iteration number : %i\n",nIt);
    _picardIteration(all, boundaryElements, face2el, vertices, currentSolution, newSolution);
    epsilon=_computeErrorPicard(currentSolution, newSolution);
    std::map<MVertex *, SVector3> *tempPtrSolution;
    tempPtrSolution=currentSolution;
    currentSolution=newSolution;
    newSolution=tempPtrSolution;
    printf("+++++++++++++++++++ error : %g\n",epsilon);
    // epsilon=0.0;
    nIt++;
  }
  for(std::set<MVertex *, MVertexPtrLessThan>::iterator it = vertices.begin(); it != vertices.end(); ++it){
    (*it)->x() = (*currentSolution)[*it][0];
    (*it)->y() = (*currentSolution)[*it][1];
    (*it)->z() = (*currentSolution)[*it][2];
  }

  delete currentSolution;
  delete newSolution;
  return;
}

#else

void HighOrderMeshWinslow(GModel *m, bool onlyVisible)
{
  Msg::Error("Winslow high-order optimizer requires the solver module");
}

#endif
