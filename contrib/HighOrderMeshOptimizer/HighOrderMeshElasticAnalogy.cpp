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

#include "HighOrderMeshElasticAnalogy.h"
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
#include "linearSystemPETSc.h"
#include "linearSystemFull.h"
#include "linearSystemCSR.h"
#include "OS.h"

#define SQU(a) ((a) * (a))

void HighOrderMeshElasticAnalogy(GModel *m, bool onlyVisible)
{
  double t1 = Cpu();
  Msg::StatusBar(true, "Applying elastic analogy to high-order mesh...");

  highOrderTools hot(m);
  // now we smooth mesh the internal vertices of the faces
  // we do that model face by model face
  std::vector<MElement *> bad;
  double worst;
  checkHighOrderTriangles("Surface mesh", m, bad, worst);
  {
    for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
      if(onlyVisible && !(*it)->getVisibility()) continue;
      std::vector<MElement *> v;
      v.insert(v.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
      v.insert(v.end(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
      if((*it)->isFullyDiscrete())
        hot.applySmoothingTo(v, 1.e32, false);
      else
        hot.applySmoothingTo(v, (*it));
    }
  }
  checkHighOrderTriangles("Final surface mesh", m, bad, worst);

  checkHighOrderTetrahedron("Volume mesh", m, bad, worst);
  {
    for(auto it = m->firstRegion(); it != m->lastRegion(); ++it) {
      if(onlyVisible && !(*it)->getVisibility()) continue;
      std::vector<MElement *> v;
      v.insert(v.begin(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      v.insert(v.end(), (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      v.insert(v.end(), (*it)->prisms.begin(), (*it)->prisms.end());
      if((*it)->pyramids.size())
        Msg::Error("Pyramids not yet handled in high-order elastic analogy");
      hot.applySmoothingTo(v, 1.e32, false);
    }
  }
  checkHighOrderTetrahedron("Final volume mesh", m, bad, worst);

  double t2 = Cpu();
  Msg::StatusBar(
    true, "Done applying elastic analogy to high-order mesh (%g s)", t2 - t1);
}

void highOrderTools::_moveToStraightSidedLocation(MElement *e) const
{
  for(int i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    auto it = _straightSidedLocation.find(v);
    if(it != _straightSidedLocation.end()) {
      v->x() = it->second.x();
      v->y() = it->second.y();
      v->z() = it->second.z();
    }
  }
}

void highOrderTools::ensureMinimumDistorsion(MElement *e, double threshold)
{
  double dist = e->distoShapeMeasure();
  if(dist > threshold) return;
  double a1 = 0., a2 = 1.0, x[1000][3], X[1000][3];
  for(int i = 0; i < e->getNumVertices(); i++) {
    MVertex *v = e->getVertex(i);
    x[i][0] = v->x();
    x[i][1] = v->y();
    x[i][2] = v->z();
    std::map<MVertex *, SVector3>::const_iterator it =
      _straightSidedLocation.find(v);
    if(it != _straightSidedLocation.end()) {
      X[i][0] = it->second.x();
      X[i][1] = it->second.y();
      X[i][2] = it->second.z();
    }
    else {
      X[i][0] = v->x();
      X[i][1] = v->y();
      X[i][2] = v->z();
    }
  }
  // a == 0 -> straight
  // a == 1 -> curved
  int ITER = 1;
  while(1) {
    double a = 0.5 * (a1 + a2);
    if(ITER > 10) a = 0.;
    for(int i = 0; i < e->getNumVertices(); i++) {
      MVertex *v = e->getVertex(i);
      v->x() = a * x[i][0] + (1. - a) * X[i][0];
      v->y() = a * x[i][1] + (1. - a) * X[i][1];
      v->z() = a * x[i][2] + (1. - a) * X[i][2];
    }
    double dist = e->distoShapeMeasure();
    //    printf("a = %g dist = %g\n",a,dist);
    //    getchar();
    if(dist > 0 && fabs(dist - threshold) < .05) break;
    if(dist < threshold)
      a2 = a;
    else
      a1 = a;
    if(a > .99 || a < .01) break;
    ++ITER;
  }
  //  printf("element done\n");
}

static void getDistordedElements(const std::vector<MElement *> &v,
                                 const double &threshold,
                                 std::vector<MElement *> &d, double &minD)
{
  d.clear();
  minD = 1;
  for(std::size_t i = 0; i < v.size(); i++) {
    const double disto = v[i]->distoShapeMeasure();
    if(disto < threshold) d.push_back(v[i]);
    minD = std::min(minD, disto);
  }
}

static void addOneLayer(const std::vector<MElement *> &v,
                        std::vector<MElement *> &d,
                        std::vector<MElement *> &layer)
{
  std::set<MVertex *, MVertexPtrLessThan> all;
  for(std::size_t i = 0; i < d.size(); i++) {
    MElement *e = d[i];
    int n = e->getNumPrimaryVertices();
    for(int j = 0; j < n; j++) { all.insert(e->getVertex(j)); }
  }
  layer.clear();
  std::sort(d.begin(), d.end());

  for(std::size_t i = 0; i < v.size(); i++) {
    MElement *e = v[i];
    bool found = std::binary_search(d.begin(), d.end(), e);
    // element is not yet there
    if(!found) {
      int n = e->getNumPrimaryVertices();
      for(int j = 0; j < n; j++) {
        MVertex *vert = e->getVertex(j);
        if(all.find(vert) != all.end()) {
          layer.push_back(e);
          j = n;
        }
      }
    }
  }
}

double highOrderTools::applySmoothingTo(GFace *gf, double tres, bool mixed)
{
  if(!gf) {
    Msg::Error("Cannot smooth that face");
    return -1;
  }
  std::vector<MElement *> v;
  v.insert(v.begin(), gf->triangles.begin(), gf->triangles.end());
  v.insert(v.begin(), gf->quadrangles.begin(), gf->quadrangles.end());
  return applySmoothingTo(v, tres, mixed);
}

void highOrderTools::ensureMinimumDistorsion(double threshold)
{
  std::vector<MElement *> v;
  if(_dim == 2) {
    for(auto fit = _gm->firstFace(); fit != _gm->lastFace(); ++fit) {
      v.insert(v.begin(), (*fit)->triangles.begin(), (*fit)->triangles.end());
      v.insert(v.begin(), (*fit)->quadrangles.begin(),
               (*fit)->quadrangles.end());
    }
  }
  else if(_dim == 3) {
    for(auto rit = _gm->firstRegion(); rit != _gm->lastRegion(); ++rit) {
      v.insert(v.begin(), (*rit)->hexahedra.begin(), (*rit)->hexahedra.end());
      v.insert(v.begin(), (*rit)->tetrahedra.begin(), (*rit)->tetrahedra.end());
      v.insert(v.begin(), (*rit)->prisms.begin(), (*rit)->prisms.end());
    }
  }
  ensureMinimumDistorsion(v, threshold);
}

void highOrderTools::_computeMetricInfo(GFace *gf, MElement *e,
                                        fullMatrix<double> &J,
                                        fullMatrix<double> &JT,
                                        fullVector<double> &D)
{
  int nbNodes = e->getNumVertices();
  for(int j = 0; j < nbNodes; j++) {
    SPoint2 param;
    reparamMeshVertexOnFace(e->getVertex(j), gf, param);
    Pair<SVector3, SVector3> der = gf->firstDer(param);
    int XJ = j;
    int YJ = j + nbNodes;
    int ZJ = j + 2 * nbNodes;
    int UJ = j;
    int VJ = j + nbNodes;
    J(XJ, UJ) = der.first().x();
    J(YJ, UJ) = der.first().y();
    J(ZJ, UJ) = der.first().z();
    J(XJ, VJ) = der.second().x();
    J(YJ, VJ) = der.second().y();
    J(ZJ, VJ) = der.second().z();

    JT(UJ, XJ) = der.first().x();
    JT(UJ, YJ) = der.first().y();
    JT(UJ, ZJ) = der.first().z();
    JT(VJ, XJ) = der.second().x();
    JT(VJ, YJ) = der.second().y();
    JT(VJ, ZJ) = der.second().z();

    SVector3 ss = getSSL(e->getVertex(j));
    GPoint gp = gf->point(param);
    D(XJ) = (gp.x() - ss.x());
    D(YJ) = (gp.y() - ss.y());
    D(ZJ) = (gp.z() - ss.z());
  }
}

void highOrderTools::applySmoothingTo(std::vector<MElement *> &all, GFace *gf)
{
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif

  // compute the straight sided positions of high order nodes that are
  // on the edges of the face in the UV plane
  dofManager<double> myAssembler(lsys);
  elasticityTerm El(nullptr, 1.0, CTX::instance()->mesh.hoPoissonRatio, _tag);
  std::vector<MElement *> layer, v;
  double minD;
  getDistordedElements(all, CTX::instance()->mesh.hoThresholdMin, v, minD);
  int numBad = v.size();
  const int nbLayers = CTX::instance()->mesh.hoNLayers;
  for(int i = 0; i < nbLayers; i++) {
    addOneLayer(all, v, layer);
    v.insert(v.end(), layer.begin(), layer.end());
  }

  if(!v.size()) return;

  Msg::Info("Smoothing surface %d (%d elements considered in elastic analogy, "
            "worst mapping %12.5E, %3d bad elements)",
            gf->tag(), v.size(), minD, numBad);

  addOneLayer(all, v, layer);
  std::set<MVertex *, MVertexPtrLessThan>::iterator it;
  std::set<MVertex *, MVertexPtrLessThan> verticesToMove;

  // on the last layer, fix displacement to 0
  for(std::size_t i = 0; i < layer.size(); i++) {
    for(int j = 0; j < layer[i]->getNumVertices(); j++) {
      MVertex *vert = layer[i]->getVertex(j);
      myAssembler.fixVertex(vert, 0, _tag, 0);
      myAssembler.fixVertex(vert, 1, _tag, 0);
    }
  }

  // fix all vertices that cannot move
  for(std::size_t i = 0; i < v.size(); i++) {
    _moveToStraightSidedLocation(v[i]);
    for(int j = 0; j < v[i]->getNumVertices(); j++) {
      MVertex *vert = v[i]->getVertex(j);
      if(vert->onWhat()->dim() < 2) {
        double du = 0, dv = 0;
        myAssembler.fixVertex(vert, 0, _tag, du);
        myAssembler.fixVertex(vert, 1, _tag, dv);
      }
    }
  }

  // number the other DOFs
  for(std::size_t i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i]->getNumVertices(); j++) {
      MVertex *vert = v[i]->getVertex(j);
      myAssembler.numberVertex(vert, 0, _tag);
      myAssembler.numberVertex(vert, 1, _tag);
      verticesToMove.insert(vert);
    }
  }

  double dx0 = _smoothMetric(v, gf, myAssembler, verticesToMove, El);
  double dx = dx0;
  Msg::Debug(" dx0 = %12.5E", dx0);
  int iter = 0;
  while(0) {
    double dx2 = _smoothMetric(v, gf, myAssembler, verticesToMove, El);
    Msg::Debug(" dx2  = %12.5E", dx2);
    if(fabs(dx2 - dx) < 1.e-4 * dx0) break;
    if(iter++ > 2) break;
    dx = dx2;
  }

  for(it = verticesToMove.begin(); it != verticesToMove.end(); ++it) {
    SPoint2 param;
    if((*it)->onWhat()->dim() == 2) {
      reparamMeshVertexOnFace(*it, gf, param);
      GPoint gp = gf->point(param);
      (*it)->x() = gp.x();
      (*it)->y() = gp.y();
      (*it)->z() = gp.z();
      _targetLocation[*it] = SVector3(gp.x(), gp.y(), gp.z());
    }
    else {
      SVector3 p = getTL(*it);
      (*it)->x() = p.x();
      (*it)->y() = p.y();
      (*it)->z() = p.z();
    }
  }
  delete lsys;
}

double highOrderTools::_smoothMetric(
  std::vector<MElement *> &v, GFace *gf, dofManager<double> &myAssembler,
  std::set<MVertex *, MVertexPtrLessThan> &verticesToMove, elasticityTerm &El)
{
  std::set<MVertex *, MVertexPtrLessThan>::iterator it;
  double dx = 0.0;

  if(myAssembler.sizeOfR()) {
    // while convergence
    for(std::size_t i = 0; i < v.size(); i++) {
      MElement *e = v[i];
      int nbNodes = e->getNumVertices();
      const int n2 = 2 * nbNodes;
      const int n3 = 3 * nbNodes;

      fullMatrix<double> K33(n3, n3);
      fullMatrix<double> K22(n2, n2);
      fullMatrix<double> J32(n3, n2);
      fullMatrix<double> J23(n2, n3);
      fullVector<double> D3(n3);
      fullVector<double> R2(n2);
      fullMatrix<double> J23K33(n2, n3);
      K33.setAll(0.0);
      SElement se(e);
      El.elementMatrix(&se, K33);
      _computeMetricInfo(gf, e, J32, J23, D3);
      J23K33.gemm(J23, K33, 1, 0);
      K22.gemm(J23K33, J32, 1, 0);
      J23K33.mult(D3, R2);
      for(int j = 0; j < n2; j++) {
        Dof RDOF = El.getLocalDofR(&se, j);
        myAssembler.assemble(RDOF, -R2(j));
        for(int k = 0; k < n2; k++) {
          Dof CDOF = El.getLocalDofC(&se, k);
          myAssembler.assemble(RDOF, CDOF, K22(j, k));
        }
      }
    }
    myAssembler.systemSolve();
    // for all element, compute detJ at integration points --> material law end
    // while convergence

    for(it = verticesToMove.begin(); it != verticesToMove.end(); ++it) {
      if((*it)->onWhat()->dim() == 2) {
        SPoint2 param;
        reparamMeshVertexOnFace((*it), gf, param);
        SPoint2 dparam;
        myAssembler.getDofValue((*it), 0, _tag, dparam[0]);
        myAssembler.getDofValue((*it), 1, _tag, dparam[1]);
        SPoint2 newp = param + dparam;
        dx += newp.x() * newp.x() + newp.y() * newp.y();
        (*it)->setParameter(0, newp.x());
        (*it)->setParameter(1, newp.y());
      }
    }
    myAssembler.systemClear();
  }

  return dx;
}

highOrderTools::highOrderTools(GModel *gm) : _gm(gm), _tag(111), _dim(2)
{
  _computeStraightSidedPositions();
}

highOrderTools::highOrderTools(GModel *gm, GModel *mesh, int order)
  : _gm(gm), _tag(111), _dim(2)
{
  GeomMeshMatcher::instance()->forceTomatch(gm, mesh, 1.e-5);
  GeomMeshMatcher::instance()->destroy();
  SetOrderN(gm, order, false, false);
  _computeStraightSidedPositions();
}

void highOrderTools::_computeStraightSidedPositions()
{
  _clean();
  // compute straigh sided positions that are actually X,Y,Z positions
  // that are NOT always on curves and surfaces

  // points classified on model vertices shall not move !
  for(auto it = _gm->firstVertex(); it != _gm->lastVertex(); ++it) {
    if((*it)->points.size()) {
      MPoint *p = (*it)->points[0];
      MVertex *v = p->getVertex(0);
      _straightSidedLocation[v] = SVector3((*it)->x(), (*it)->y(), (*it)->z());
      _targetLocation[v] = SVector3((*it)->x(), (*it)->y(), (*it)->z());
    }
  }

  // compute stright sided positions of vertices that are classified on model
  // edges
  for(auto it = _gm->firstEdge(); it != _gm->lastEdge(); ++it) {
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
  for(auto it = _gm->firstFace(); it != _gm->lastFace(); ++it) {
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

  for(auto it = _gm->firstRegion(); it != _gm->lastRegion(); ++it) {
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
      MPrism p_1((*it)->prisms[i]->getVertex(0), (*it)->prisms[i]->getVertex(1),
                 (*it)->prisms[i]->getVertex(2), (*it)->prisms[i]->getVertex(3),
                 (*it)->prisms[i]->getVertex(4),
                 (*it)->prisms[i]->getVertex(5));
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

// apply a displacement that does not create elements that are distorted over a
// value "thres"
double highOrderTools::_applyIncrementalDisplacement(
  double max_incr, std::vector<MElement *> &v, bool mixed, double thres,
  char *meshName, std::vector<MElement *> &disto)
{
  if(v.empty()) return 1.;

#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif

  // assume that the mesh is OK, yet already curved
  Msg::Info("Generating elastic system...");
  dofManager<double> myAssembler(lsys);
  elasticityMixedTerm El_mixed(nullptr, 1.0, .333, _tag);
  elasticityTerm El(nullptr, 1.0, .333, _tag);

  std::set<MVertex *, MVertexPtrLessThan> _vertices;

  // Boundary Conditions & Numbering

  // fix all dof that correspond to vertices on the boundary the value is equal
  for(std::size_t i = 0; i < v.size(); i++) {
    for(int j = 0; j < v[i]->getNumVertices(); j++) {
      MVertex *vert = v[i]->getVertex(j);
      _vertices.insert(vert);
    }
  }

  // Fix d tr(eps) = 0
  if(mixed) {
    for(std::size_t i = 0; i < disto.size(); i++) {
      for(int j = 0; j < disto[i]->getNumVertices(); j++) {
        MVertex *vert = disto[i]->getVertex(j);
        myAssembler.fixVertex(vert, 4, _tag, 0.0);
      }
    }
  }

  for(auto it = _vertices.begin(); it != _vertices.end(); ++it) {
    MVertex *vert = *it;
    auto itt = _targetLocation.find(vert);
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
    if(_dim == 2) myAssembler.fixVertex(vert, 2, _tag, 0);
    // number vertices
    myAssembler.numberVertex(vert, 0, _tag);
    myAssembler.numberVertex(vert, 1, _tag);
    myAssembler.numberVertex(vert, 2, _tag);
    if(mixed) {
      myAssembler.numberVertex(vert, 3, _tag);
      myAssembler.numberVertex(vert, 4, _tag);
    }
  }

  if(myAssembler.sizeOfR()) {
    // assembly of the elasticity term on the
    for(std::size_t i = 0; i < v.size(); i++) {
      SElement se(v[i]);
      if(mixed)
        El_mixed.addToMatrix(myAssembler, &se);
      else
        El.addToMatrix(myAssembler, &se);
    }
    Msg::Info("Solving linear system (%d unknowns)...", myAssembler.sizeOfR());
    // solve the system
    lsys->systemSolve();
  }

  // Move vertices @ maximum
  // FILE *fd = Fopen("d.msh", "w");
  // fprintf(fd, "$MeshFormat\n2 0 8\n$EndMeshFormat\n$NodeData\n1\n"
  //            "\"tr(sigma)\"\n1\n0.0\n3\n1\n3\n%d\n",
  //            (int)_vertices.size());
  for(auto it = _vertices.begin(); it != _vertices.end(); ++it) {
    double ax, ay, az;
    myAssembler.getDofValue(*it, 0, _tag, ax);
    myAssembler.getDofValue(*it, 1, _tag, ay);
    myAssembler.getDofValue(*it, 2, _tag, az);
    (*it)->x() += max_incr * ax;
    (*it)->y() += max_incr * ay;
    (*it)->z() += max_incr * az;
    // fprintf(fd, "%d %g %g %g\n", (*it)->getIndex(), ax, ay, az);
  }
  // fprintf(fd, "$EndNodeData\n");
  // fclose(fd);

  // Check now if elements are ok

  // (*_vertices.begin())->onWhat()->model()->writeMSH(meshName);

  double percentage = max_incr * 100.;
  while(1) {
    std::vector<MElement *> disto;
    double minD;
    getDistordedElements(v, 0.5, disto, minD);
    if(minD < thres) {
      percentage -= 10.;
      for(auto it = _vertices.begin(); it != _vertices.end(); ++it) {
        double ax, ay, az;
        myAssembler.getDofValue(*it, 0, _tag, ax);
        myAssembler.getDofValue(*it, 1, _tag, ay);
        myAssembler.getDofValue(*it, 2, _tag, az);
        (*it)->x() -= .1 * ax;
        (*it)->y() -= .1 * ay;
        (*it)->z() -= .1 * az;
      }
    }
    else
      break;
  }

  delete lsys;
  return percentage;
}

// uncurve elements that are invalid
void highOrderTools::ensureMinimumDistorsion(std::vector<MElement *> &all,
                                             double threshold)
{
  for(int tries = 0; tries < 100; tries++) {
    double minD;
    std::vector<MElement *> disto;
    getDistordedElements(all, threshold, disto, minD);
    if(disto.empty()) break;
    Msg::Info("Fixing %d bad curved elements (worst disto %g)", disto.size(),
              minD);
    for(std::size_t i = 0; i < disto.size(); i++) {
      ensureMinimumDistorsion(disto[i], threshold);
    }
  }
}

double highOrderTools::applySmoothingTo(std::vector<MElement *> &all,
                                        double threshold, bool mixed)
{
  int ITER = 0;
  double minD;
  std::vector<MElement *> disto;

  // move the points to their straight sided locations
  for(std::size_t i = 0; i < all.size(); i++)
    _moveToStraightSidedLocation(all[i]);

  // apply the displacement

  // _gm->writeMSH("straightSided.msh");

  char sm[] = "sm.msh";
  double percentage_of_what_is_left =
    _applyIncrementalDisplacement(1., all, mixed, -100000000, sm, all);

  // ensureMinimumDistorsion (all, threshold);

  return 1.;

  double percentage = 0.0;
  while(1) {
    char NN[256];
    sprintf(NN, "smoothing-%d.msh", ITER++);
    percentage_of_what_is_left =
      _applyIncrementalDisplacement(1., all, mixed, threshold, NN, all);
    percentage += (1. - percentage) * percentage_of_what_is_left / 100.;
    Msg::Info("Smoother was able to do %3d percent of the motion",
              (int)(percentage * 100.));
    if(percentage_of_what_is_left == 0.0)
      break;
    else if(percentage_of_what_is_left == 100.)
      break;
  }

  getDistordedElements(all, 0.3, disto, minD);
  Msg::Info(" - Iter %d: %d elements / %d distorted, min Disto = %g", ITER,
            all.size(), disto.size(), minD);
  return percentage;
}

void printJacobians(GModel *m, const char *nm)
{
  const int n = 100;
  double D[n][n], X[n][n], Y[n][n], Z[n][n];

  FILE *f = Fopen(nm, "w");
  fprintf(f, "View \"\"{\n");
  for(auto it = m->firstFace(); it != m->lastFace(); ++it) {
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

void highOrderTools::makePosViewWithJacobians(const char *fn)
{
  printJacobians(_gm, fn);
}

#else

void HighOrderMeshElasticAnalogy(GModel *m, bool onlyVisible)
{
  Msg::Error("Elastic analogy high-order optimzer requires the solver module");
}

#endif
