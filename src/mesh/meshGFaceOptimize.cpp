// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stack>
#include "GmshConfig.h"
#include "meshGFaceOptimize.h"
#include "qualityMeasures.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "GModel.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MLine.h"
#include "BackgroundMeshTools.h"
#include "Numeric.h"
#include "GmshMessage.h"
#include "Context.h"
#include "OS.h"
#include "SVector3.h"
#include "SPoint3.h"
#include "meshRelocateVertex.h"
#include "Field.h"

#if defined(HAVE_BLOSSOM)
extern "C" struct CCdatagroup;
extern "C" int perfect_match(int ncount, CCdatagroup *dat, int ecount,
                             int **elist, int **elen, char *blo_filename,
                             char *mat_filename, int just_fractional,
                             int no_fractional, int use_all_trees,
                             int partialprice, double *totalzeit);
#endif

RecombineTriangle::RecombineTriangle(const MEdge &me, MElement *_t1,
                                     MElement *_t2, Field *cross_field)
  : t1(_t1), t2(_t2)
{
  n1 = me.getVertex(0);
  n2 = me.getVertex(1);
  n3 = 0;
  n4 = 0;

  if(t1->getVertex(0) != n1 && t1->getVertex(0) != n2)
    n3 = t1->getVertex(0);
  else if(t1->getVertex(1) != n1 && t1->getVertex(1) != n2)
    n3 = t1->getVertex(1);
  else if(t1->getVertex(2) != n1 && t1->getVertex(2) != n2)
    n3 = t1->getVertex(2);

  if(t2->getVertex(0) != n1 && t2->getVertex(0) != n2)
    n4 = t2->getVertex(0);
  else if(t2->getVertex(1) != n1 && t2->getVertex(1) != n2)
    n4 = t2->getVertex(1);
  else if(t2->getVertex(2) != n1 && t2->getVertex(2) != n2)
    n4 = t2->getVertex(2);

  if(!n3) {
    Msg::Warning("Invalid quadrangle in recombination");
    n3 = n1;
  }
  if(!n4) {
    Msg::Warning("Invalid quadrangle in recombination");
    n4 = n2;
  }

  MQuadrangle q(n1, n3, n2, n4);
  angle = q.etaShapeMeasure();

  double const a1 = 180 * angle3Vertices(n1, n4, n2) / M_PI;
  double const a2 = 180 * angle3Vertices(n4, n2, n3) / M_PI;
  double const a3 = 180 * angle3Vertices(n2, n3, n1) / M_PI;
  double const a4 = 180 * angle3Vertices(n3, n1, n4) / M_PI;
  quality = std::abs(90. - a1);
  quality = std::max(std::abs(90. - a2), quality);
  quality = std::max(std::abs(90. - a3), quality);
  quality = std::max(std::abs(90. - a4), quality);

  if(cross_field) {
    SVector3 t1;
    SVector3 t2(me.getVertex(1)->x() - me.getVertex(0)->x(),
                me.getVertex(1)->y() - me.getVertex(0)->y(),
                me.getVertex(1)->z() - me.getVertex(0)->z());
    (*cross_field)(0.5 * (me.getVertex(0)->x() + me.getVertex(1)->x()),
                   0.5 * (me.getVertex(0)->y() + me.getVertex(1)->y()),
                   0.5 * (me.getVertex(0)->z() + me.getVertex(1)->z()), t1,
                   NULL);
    //    double L1 = t1.norm();
    t1.normalize();
    //    double L2 = t2.norm();
    t2.normalize();
    SVector3 n = crossprod(t1, t2);
    double ErrDir = std::min(fabs(dot(t1, t2)), n.norm());
    //    double ErrL = fabs(L1-L2)/(L1);
    //    printf("quality %g err %g L %g %g\n",quality,ErrL,L1,L2);
    quality /= ErrDir;
    if(n1->onWhat()->dim() < 2 || n2->onWhat()->dim() < 2) quality /= 10;
  }
}

edge_angle::edge_angle(MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2)
  : v1(_v1), v2(_v2)
{
  if(!t2)
    angle = 0;
  else {
    double c1[3];
    double c2[3];
    double c3[3];
    {
      MVertex *p1 = t1->getVertex(0);
      MVertex *p2 = t1->getVertex(1);
      MVertex *p3 = t1->getVertex(2);
      double a[3] = {p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z()};
      double b[3] = {p1->x() - p3->x(), p1->y() - p3->y(), p1->z() - p3->z()};
      c1[2] = a[0] * b[1] - a[1] * b[0];
      c1[1] = -a[0] * b[2] + a[2] * b[0];
      c1[0] = a[1] * b[2] - a[2] * b[1];
    }
    {
      MVertex *p1 = t2->getVertex(0);
      MVertex *p2 = t2->getVertex(1);
      MVertex *p3 = t2->getVertex(2);
      double a[3] = {p1->x() - p2->x(), p1->y() - p2->y(), p1->z() - p2->z()};
      double b[3] = {p1->x() - p3->x(), p1->y() - p3->y(), p1->z() - p3->z()};
      c2[2] = a[0] * b[1] - a[1] * b[0];
      c2[1] = -a[0] * b[2] + a[2] * b[0];
      c2[0] = a[1] * b[2] - a[2] * b[1];
    }
    norme(c1);
    norme(c2);
    prodve(c1, c2, c3);
    double const cosa = prosca(c1, c2);
    double const sina = norme(c3);
    angle = std::atan2(sina, cosa);
  }
}

static void setLcsInit(MTriangle *t, std::map<MVertex *, double> &vSizes)
{
  for(int i = 0; i < 3; i++) {
    for(int j = i + 1; j < 3; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      vSizes[vi] = -1;
      vSizes[vj] = -1;
    }
  }
}

static void setLcs(MTriangle *t, std::map<MVertex *, double> &vSizes,
                   bidimMeshData &data)
{
  for(int i = 0; i < 3; i++) {
    for(int j = i + 1; j < 3; j++) {
      MVertex *vi = t->getVertex(i);
      MVertex *vj = t->getVertex(j);
      if(vi != data.equivalent(vj) && vj != data.equivalent(vi)) {
        double dx = vi->x() - vj->x();
        double dy = vi->y() - vj->y();
        double dz = vi->z() - vj->z();
        double l = sqrt(dx * dx + dy * dy + dz * dz);
        auto iti = vSizes.find(vi);
        auto itj = vSizes.find(vj);
        if(iti->second < 0 || iti->second > l) iti->second = l;
        if(itj->second < 0 || itj->second > l) itj->second = l;
      }
    }
  }
}

bool buildMeshGenerationDataStructures(
  GFace *gf, std::set<MTri3 *, compareTri3Ptr> &AllTris, bidimMeshData &data)
{
  std::map<MVertex *, double> vSizesMap;

  for(std::size_t i = 0; i < gf->triangles.size(); i++)
    setLcsInit(gf->triangles[i], vSizesMap);

  auto itfind = vSizesMap.find(nullptr);
  if(itfind != vSizesMap.end()) {
    Msg::Error("Some NULL points exist in 2D mesh");
    return false;
  }

  for(std::size_t i = 0; i < gf->triangles.size(); i++)
    setLcs(gf->triangles[i], vSizesMap, data);

  // take care of embedded vertices
  std::set<MVertex *> embeddedVertices;
  {
    std::vector<GVertex *> emb_vertx = gf->getEmbeddedVertices();
    auto itvx = emb_vertx.begin();
    while(itvx != emb_vertx.end()) {
      if((*itvx)->mesh_vertices.size()) {
        MVertex *v = *((*itvx)->mesh_vertices.begin());
        vSizesMap[v] =
          std::min(vSizesMap[v], (*itvx)->prescribedMeshSizeAtVertex());
        embeddedVertices.insert(v);
      }
      ++itvx;
    }
  }

  // take good care of embedded edges
  {
    std::vector<GEdge *> embedded_edges = gf->getEmbeddedEdges();
    auto ite = embedded_edges.begin();
    while(ite != embedded_edges.end()) {
      if(!(*ite)->isMeshDegenerated()) {
        for(std::size_t i = 0; i < (*ite)->lines.size(); i++)
          data.internalEdges.insert(MEdge((*ite)->lines[i]->getVertex(0),
                                          (*ite)->lines[i]->getVertex(1)));
      }
      ++ite;
    }
  }

  // take care of small edges in  order not to "pollute" the size field
  {
    std::vector<GEdge *> _edges = gf->edges();
    auto ite = _edges.begin();
    while(ite != _edges.end()) {
      if(!(*ite)->isMeshDegenerated()) {
        for(std::size_t i = 0; i < (*ite)->lines.size(); i++) {
          double d = distance((*ite)->lines[i]->getVertex(0),
                              (*ite)->lines[i]->getVertex(1));
          double d0 = vSizesMap[(*ite)->lines[i]->getVertex(0)];
          double d1 = vSizesMap[(*ite)->lines[i]->getVertex(1)];
          if(d0 < .5 * d) vSizesMap[(*ite)->lines[i]->getVertex(0)] = .5 * d;
          if(d1 < .5 * d) vSizesMap[(*ite)->lines[i]->getVertex(1)] = .5 * d;
        }
      }
      ++ite;
    }
  }

  for(auto it = vSizesMap.begin(); it != vSizesMap.end(); ++it) {
    SPoint2 param;
    reparamMeshVertexOnFace(it->first, gf, param);
    // Add size of background mesh to embedded vertices. For the other nodes,
    // use the size in vSizesMap
    const double lcBGM = (embeddedVertices.count(it->first) > 0) ?
                           BGM_MeshSize(gf, param[0], param[1], it->first->x(),
                                        it->first->y(), it->first->z()) :
                           it->second;
    data.addVertex(it->first, param[0], param[1], it->second, lcBGM);
  }
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    double lc = 0.3333333333 *
                (data.vSizes[data.getIndex(gf->triangles[i]->getVertex(0))] +
                 data.vSizes[data.getIndex(gf->triangles[i]->getVertex(1))] +
                 data.vSizes[data.getIndex(gf->triangles[i]->getVertex(2))]);
    double lcBGM =
      0.3333333333 *
      (data.vSizesBGM[data.getIndex(gf->triangles[i]->getVertex(0))] +
       data.vSizesBGM[data.getIndex(gf->triangles[i]->getVertex(1))] +
       data.vSizesBGM[data.getIndex(gf->triangles[i]->getVertex(2))]);

    double LL = Extend1dMeshIn2dSurfaces(gf) ? std::min(lc, lcBGM) : lcBGM;
    AllTris.insert(new MTri3(gf->triangles[i], LL, nullptr, &data, gf));
  }
  gf->triangles.clear();
  connectTriangles(AllTris);

  return true;
}

void computeEquivalences(GFace *gf, bidimMeshData &data)
{
  if(data.equivalence) {
    std::vector<MTriangle *> newT;
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      MVertex *v[3];
      for(int j = 0; j < 3; j++) {
        v[j] = t->getVertex(j);
        auto it = data.equivalence->find(v[j]);
        if(it != data.equivalence->end()) { v[j] = it->second; }
      }
      if(v[0] != v[1] && v[0] != v[2] && v[2] != v[1])
        newT.push_back(new MTriangle(v[0], v[1], v[2]));
      delete t;
    }
    gf->triangles = newT;
  }
}

struct equivalentTriangle {
  MTriangle *_t;
  MVertex *_v[3];
  equivalentTriangle(MTriangle *t, std::map<MVertex *, MVertex *> *equivalence)
    : _t(t)
  {
    for(int i = 0; i < 3; i++) {
      MVertex *v = t->getVertex(i);
      auto it = equivalence->find(v);
      if(it == equivalence->end())
        _v[i] = v;
      else
        _v[i] = it->second;
    }
    std::sort(_v, _v + 3);
  }
  bool operator<(const equivalentTriangle &other) const
  {
    for(int i = 0; i < 3; i++) {
      if(other._v[i] > _v[i]) return true;
      if(other._v[i] < _v[i]) return false;
    }
    return false;
  }
};

bool computeEquivalentTriangles(GFace *gf,
                                std::map<MVertex *, MVertex *> *equivalence)
{
  if(!equivalence) return false;
  std::vector<MTriangle *> WTF;
  if(!equivalence) return false;
  std::set<equivalentTriangle> eqTs;
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    equivalentTriangle et(gf->triangles[i], equivalence);
    auto iteq = eqTs.find(et);
    if(iteq == eqTs.end())
      eqTs.insert(et);
    else {
      WTF.push_back(iteq->_t);
      WTF.push_back(gf->triangles[i]);
    }
  }

  if(WTF.size()) {
    Msg::Info("%d triangles are equivalent", WTF.size());
    for(std::size_t i = 0; i < WTF.size(); i++) {}
    return true;
  }
  return false;
}

void splitEquivalentTriangles(GFace *gf, bidimMeshData &data)
{
  computeEquivalentTriangles(gf, data.equivalence);
}

void transferDataStructure(GFace *gf,
                           std::set<MTri3 *, compareTri3Ptr> &AllTris,
                           bidimMeshData &data)
{
  while(1) {
    if(AllTris.begin() == AllTris.end()) break;
    MTri3 *worst = *AllTris.begin();
    if(worst->isDeleted())
      delete worst->tri();
    else
      gf->triangles.push_back(worst->tri());
    delete worst;
    AllTris.erase(AllTris.begin());
  }

  // make sure all the triangles are oriented in the same way in
  // parameter space (it would be nicer to change the actual algorithm
  // to ensure that we create correctly-oriented triangles in the
  // first place)

  // if BL triangles are considered, then all that is WRONG !

  if(gf->triangles.size() > 1) {
    bool BL = !gf->getColumns()->_toFirst.empty();

    double n1[3], n2[3];
    MTriangle *t = gf->triangles[0];
    MVertex *v0 = t->getVertex(0), *v1 = t->getVertex(1), *v2 = t->getVertex(2);

    if(!BL) {
      int index0 = data.getIndex(v0);
      int index1 = data.getIndex(v1);
      int index2 = data.getIndex(v2);
      normal3points(data.Us[index0], data.Vs[index0], 0., data.Us[index1],
                    data.Vs[index1], 0., data.Us[index2], data.Vs[index2], 0.,
                    n1);
    }
    else {
      // BL --> PLANAR FACES !!!
      normal3points(v0->x(), v0->y(), v0->z(), v1->x(), v1->y(), v1->z(),
                    v2->x(), v2->y(), v2->z(), n1);
    }
    for(std::size_t j = 1; j < gf->triangles.size(); j++) {
      t = gf->triangles[j];
      v0 = t->getVertex(0);
      v1 = t->getVertex(1);
      v2 = t->getVertex(2);
      if(!BL) {
        int index0 = data.getIndex(v0);
        int index1 = data.getIndex(v1);
        int index2 = data.getIndex(v2);
        normal3points(data.Us[index0], data.Vs[index0], 0., data.Us[index1],
                      data.Vs[index1], 0., data.Us[index2], data.Vs[index2], 0.,
                      n2);
      }
      else {
        // BL --> PLANAR FACES !!!
        normal3points(v0->x(), v0->y(), v0->z(), v1->x(), v1->y(), v1->z(),
                      v2->x(), v2->y(), v2->z(), n2);
      }
      // orient the bignou
      if(prosca(n1, n2) < 0.0) t->reverse();
    }
  }
  splitEquivalentTriangles(gf, data);
  computeEquivalences(gf, data);
}

template <class T>
void buildEdgeToElement(std::vector<T *> &elements, e2t_cont &adj)
{
  for(std::size_t i = 0; i < elements.size(); i++) {
    T *t = elements[i];
    for(int j = 0; j < t->getNumEdges(); j++) {
      MEdge e = t->getEdge(j);
      auto it = adj.find(e);
      if(it == adj.end()) {
        std::pair<MElement *, MElement *> one =
          std::make_pair(t, (MElement *)nullptr);
        adj[e] = one;
      }
      else {
        it->second.second = t;
      }
    }
  }
}

void buildEdgeToElement(GFace *gf, e2t_cont &adj)
{
  adj.clear();
  buildEdgeToElement(gf->triangles, adj);
  buildEdgeToElement(gf->quadrangles, adj);
}

void buildEdgeToTriangle(std::vector<MTriangle *> &tris, e2t_cont &adj)
{
  adj.clear();
  buildEdgeToElement(tris, adj);
}

void buildEdgeToElements(std::vector<MElement *> &tris, e2t_cont &adj)
{
  adj.clear();
  buildEdgeToElement(tris, adj);
}

void buildListOfEdgeAngle(e2t_cont adj, std::vector<edge_angle> &edges_detected,
                          std::vector<edge_angle> &edges_lonly)
{
  auto it = adj.begin();
  for(; it != adj.end(); ++it) {
    if(it->second.second)
      edges_detected.push_back(edge_angle(it->first.getVertex(0),
                                          it->first.getVertex(1),
                                          it->second.first, it->second.second));
    else
      edges_lonly.push_back(edge_angle(it->first.getVertex(0),
                                       it->first.getVertex(1), it->second.first,
                                       it->second.second));
  }
  std::sort(edges_detected.begin(), edges_detected.end());
}

static void parametricCoordinates(MElement *t, GFace *gf, double u[4],
                                  double v[4], MVertex *close = nullptr)
{
  for(std::size_t j = 0; j < t->getNumVertices(); j++) {
    MVertex *ver = t->getVertex(j);
    SPoint2 param, dummy;
    if(!close)
      reparamMeshVertexOnFace(ver, gf, param);
    else
      reparamMeshEdgeOnFace(ver, close, gf, param, dummy);
    u[j] = param[0];
    v[j] = param[1];
  }
}

double surfaceFaceUV(MElement *t, GFace *gf, bool maximal = true)
{
  const int N = t->getNumVertices();
  if(N > 4) {
    Msg::Warning("surfaceFaceUV only for first order elements");
    return 0;
  }

  double u[4], v[4];
  parametricCoordinates(t, gf, u, v);
  if(N == 3)
    return 0.5 *
           fabs((u[1] - u[0]) * (v[2] - v[0]) - (u[2] - u[0]) * (v[1] - v[0]));
  else {
    const double a1 =
      0.5 *
        fabs((u[1] - u[0]) * (v[2] - v[0]) - (u[2] - u[0]) * (v[1] - v[0])) +
      0.5 * fabs((u[3] - u[2]) * (v[0] - v[2]) - (u[0] - u[2]) * (v[3] - v[2]));
    const double a2 =
      0.5 *
        fabs((u[2] - u[1]) * (v[3] - v[1]) - (u[3] - u[1]) * (v[2] - v[1])) +
      0.5 * fabs((u[0] - u[3]) * (v[1] - v[3]) - (u[1] - u[3]) * (v[0] - v[3]));
    return maximal ? std::max(a2, a1) : std::min(a2, a1);
  }
}

static int _removeTwoQuadsNodes(GFace *gf)
{
  v2t_cont adj;
  buildVertexToElement(gf->triangles, adj);
  buildVertexToElement(gf->quadrangles, adj);
  auto it = adj.begin();
  std::set<MElement *> touched;
  std::set<MVertex *> vtouched;
  while(it != adj.end()) {
    MVertex *v = it->first;
    if(it->second.size() == 2 && v->onWhat() == gf) {
      MElement *q1 = it->second[0];
      MElement *q2 = it->second[1];
      if(q1->getNumVertices() == 4 && q2->getNumVertices() == 4 &&
         touched.find(q1) == touched.end() &&
         touched.find(q2) == touched.end()) {
        int comm = 0;
        for(int i = 0; i < 4; i++) {
          if(q1->getVertex(i) == v) {
            comm = i;
            break;
          }
        }
        MVertex *v1 = q1->getVertex((comm + 1) % 4);
        MVertex *v2 = q1->getVertex((comm + 2) % 4);
        MVertex *v3 = q1->getVertex((comm + 3) % 4);
        MVertex *v4 = nullptr;
        for(int i = 0; i < 4; i++) {
          if(q2->getVertex(i) != v1 && q2->getVertex(i) != v3 &&
             q2->getVertex(i) != v) {
            v4 = q2->getVertex(i);
            break;
          }
        }
        if(!v4) {
          Msg::Error("Bug in removeTwoQuadsNodes %p,%p,%p", v1, v2, v3);
          q1->writePOS(stdout, true, false, false, false, false, false);
          q2->writePOS(stdout, true, false, false, false, false, false);
          return 0;
        }
        MQuadrangle *q = new MQuadrangle(v1, v2, v3, v4);
        touched.insert(q1);
        touched.insert(q2);
        gf->quadrangles.push_back(q);
        vtouched.insert(v);
      }
    }
    it++;
  }
  std::vector<MQuadrangle *> quadrangles2;
  quadrangles2.reserve(gf->quadrangles.size() - touched.size());
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    if(touched.find(gf->quadrangles[i]) == touched.end()) {
      quadrangles2.push_back(gf->quadrangles[i]);
    }
    else {
      delete gf->quadrangles[i];
    }
  }
  gf->quadrangles = quadrangles2;

  std::vector<MVertex *> mesh_vertices2;
  mesh_vertices2.reserve(gf->mesh_vertices.size() - vtouched.size());
  for(std::size_t i = 0; i < gf->mesh_vertices.size(); i++) {
    if(vtouched.find(gf->mesh_vertices[i]) == vtouched.end()) {
      mesh_vertices2.push_back(gf->mesh_vertices[i]);
    }
    else {
      delete gf->mesh_vertices[i];
    }
  }
  gf->mesh_vertices = mesh_vertices2;

  return vtouched.size();
}

int removeTwoQuadsNodes(GFace *gf)
{
  int nbRemove = 0;
  while(1) {
    int x = _removeTwoQuadsNodes(gf);
    if(!x) break;
    nbRemove += x;
  }
  Msg::Debug("%i two-quadrangles nodes removed", nbRemove);
  return nbRemove;
}

static bool _tryToCollapseThatVertex2(GFace *gf, std::vector<MElement *> &e1,
                                      std::vector<MElement *> &e2, MElement *q,
                                      MVertex *v1, MVertex *v2)
{
  std::vector<MElement *> e = e1;
  e.insert(e.end(), e2.begin(), e2.end());

  double x1 = v1->x();
  double y1 = v1->y();
  double z1 = v1->z();

  double x2 = v2->x();
  double y2 = v2->y();
  double z2 = v2->z();

  // new position of v1 && v2
  double initialGuess[2] = {0, 0};
  GPoint pp = gf->closestPoint(
    SPoint3(0.5 * (x1 + x2), 0.5 * (y1 + y2), 0.5 * (z1 + z2)), initialGuess);

  double worst_quality_old = 1.0;
  double worst_quality_new = 1.0;

  // int count = 0;
  for(std::size_t j = 0; j < e.size(); ++j) {
    if(e[j] != q) {
      // count++;
      worst_quality_old = std::min(worst_quality_old, e[j]->etaShapeMeasure());
      v1->x() = pp.x();
      v1->y() = pp.y();
      v1->z() = pp.z();
      v2->x() = pp.x();
      v2->y() = pp.y();
      v2->z() = pp.z();
      worst_quality_new = std::min(worst_quality_new, e[j]->etaShapeMeasure());
      v1->x() = x1;
      v1->y() = y1;
      v1->z() = z1;
      v2->x() = x2;
      v2->y() = y2;
      v2->z() = z2;
    }
  }

  if(worst_quality_new > worst_quality_old) {
    v1->x() = pp.x();
    v1->y() = pp.y();
    v1->z() = pp.z();
    for(std::size_t j = 0; j < e.size(); ++j) {
      if(e[j] != q) {
        for(int k = 0; k < 4; k++) {
          if(e[j]->getVertex(k) == v2) { e[j]->setVertex(k, v1); }
        }
      }
    }
    return true;
  }
  return false;
}

// collapse v1 & v2 to their middle and replace into e1 & e2
static bool _tryToCollapseThatVertex(GFace *gf, std::vector<MElement *> &e1,
                                     std::vector<MElement *> &e2, MElement *q,
                                     MVertex *v1, MVertex *v2)
{
  std::vector<MElement *> e = e1;
  e.insert(e.end(), e2.begin(), e2.end());

  double uu1, vv1;
  if(!v1->getParameter(0, uu1)) {
    return _tryToCollapseThatVertex2(gf, e1, e2, q, v1, v2);
  }
  v1->getParameter(1, vv1);
  double x1 = v1->x();
  double y1 = v1->y();
  double z1 = v1->z();

  double uu2, vv2;
  v2->getParameter(0, uu2);
  v2->getParameter(1, vv2);
  double x2 = v2->x();
  double y2 = v2->y();
  double z2 = v2->z();

  // new position of v1 && v2
  GPoint pp = gf->point(0.5 * (uu1 + uu2), 0.5 * (vv1 + vv2));
  double worst_quality_old = 1.0;
  double worst_quality_new = 1.0;
  // int count = 0;
  for(std::size_t j = 0; j < e.size(); ++j) {
    if(e[j] != q) {
      // count++;
      worst_quality_old = std::min(worst_quality_old, e[j]->etaShapeMeasure());
      v1->x() = pp.x();
      v1->y() = pp.y();
      v1->z() = pp.z();
      v1->setParameter(0, pp.u());
      v1->setParameter(1, pp.v());
      v2->x() = pp.x();
      v2->y() = pp.y();
      v2->z() = pp.z();
      v2->setParameter(0, pp.u());
      v2->setParameter(1, pp.v());
      worst_quality_new = std::min(worst_quality_new, e[j]->etaShapeMeasure());
      v1->x() = x1;
      v1->y() = y1;
      v1->z() = z1;
      v1->setParameter(0, uu1);
      v1->setParameter(1, vv1);
      v2->x() = x2;
      v2->y() = y2;
      v2->z() = z2;
      v2->setParameter(0, uu2);
      v1->setParameter(1, vv2);
    }
  }

  if(worst_quality_new > worst_quality_old) {
    v1->x() = pp.x();
    v1->y() = pp.y();
    v1->z() = pp.z();
    v1->setParameter(0, pp.u());
    v1->setParameter(1, pp.v());
    for(std::size_t j = 0; j < e.size(); ++j) {
      if(e[j] != q) {
        for(int k = 0; k < 4; k++) {
          if(e[j]->getVertex(k) == v2) { e[j]->setVertex(k, v1); }
        }
      }
    }
    return true;
  }
  return false;
}

// Squared sine and cosine of the smallest corner angle of the (first order)
// triangle (p0, p1, p2) - the angle whose atan2 the eta shape quality of
// qmTriangle would evaluate. The squared sine numerator |a x b|^2 is the
// same at the three corners (twice the triangle area, squared), so it is
// computed once; and since cos(angle) = c / sqrt(c^2 + sin2) increases with
// the dot product c for a fixed sin2, the smallest angle is simply the
// corner with the largest c. No sqrt, no atan2, and a single cross product;
// ties within round-off pick the first of the tied corners, whose angle is
// then equal to the smallest one up to round-off
static void _minCornerSin2Cos(const double *p0, const double *p1,
                              const double *p2, double &sin2min,
                              double &cosmin)
{
  double e01[3] = {p1[0] - p0[0], p1[1] - p0[1], p1[2] - p0[2]};
  double e12[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double e20[3] = {p0[0] - p2[0], p0[1] - p2[1], p0[2] - p2[2]};

  double cx = e01[1] * e12[2] - e12[1] * e01[2];
  double cy = -(e01[0] * e12[2] - e12[0] * e01[2]);
  double cz = e01[0] * e12[1] - e12[0] * e01[1];
  sin2min = cx * cx + cy * cy + cz * cz;

  // dot products of the vectors of each corner: at p0, (p1-p0).(p2-p0) =
  // e01.(-e20), and similarly at p1 and p2
  double c0 = -(e01[0] * e20[0] + e01[1] * e20[1] + e01[2] * e20[2]);
  double c1 = -(e01[0] * e12[0] + e01[1] * e12[1] + e01[2] * e12[2]);
  double c2 = -(e12[0] * e20[0] + e12[1] * e20[1] + e12[2] * e20[2]);

  cosmin = c0;
  if(c1 > cosmin) cosmin = c1;
  if(c2 > cosmin) cosmin = c2;
}

// Shape quality of an element for the relocation test. For first order
// triangles the squared sine and the cosine of the smallest corner angle
// are kept instead of the eta quality itself, so that qualities can be
// compared without evaluating eta (no atan2, no sqrt): eta increases with
// the smallest angle, whose cosine is always positive (the angle is at
// most 60 degrees), so the comparison of the squared cosines scaled by the
// squared side norms gives the comparison of the qualities, up to
// round-off. For other element types the exact eta values are compared.
struct elementQuality {
  double s2, c; // valid when isSin2Cos
  double val; // valid when !isSin2Cos
  bool isSin2Cos;
  double eta() const
  {
    if(!isSin2Cos) return val;
    // same formula as qmTriangle::eta
    double amin = 180 * std::atan2(std::sqrt(s2), c) / M_PI;
    return 1. - std::abs(60. - amin) * (1. / 60.);
  }
  bool operator<(const elementQuality &o) const
  {
    if(isSin2Cos && o.isSin2Cos && c > 0 && o.c > 0) {
      double x = c * c * (o.s2 + o.c * o.c);
      double y = o.c * o.c * (s2 + c * c);
      return x > y; // larger scaled cos^2: smaller angle, lower quality
    }
    return eta() < o.eta();
  }
};

// Everything needed to test the relocation of a vertex inside its star (the
// elements that surround it), fetched once per vertex: the parametric and
// cartesian coordinates of the corners, which corner is the relocated
// vertex, and the element type. evaluate() computes the total parametric
// area (with the formulas of surfaceFaceUV) and the minimum shape quality
// (ordered like the eta of etaShapeMeasure, up to round-off - see
// elementQuality) of the whole star for a candidate position of the vertex.
struct vertexStar {
  MElement *const *elements;
  std::size_t n;
  std::vector<double> u, v; // parametric coordinates, 4 corners per element
  std::vector<double> p; // cartesian coordinates, 3 per corner
  std::vector<int> nv; // number of corners of each element
  std::vector<int> iver; // corner index of the relocated vertex
  std::vector<char> isTri; // first order triangle?
  void build(GFace *gf, MVertex *ver, MElement *const *lt, std::size_t nlt)
  {
    elements = lt;
    n = nlt;
    u.resize(4 * n);
    v.resize(4 * n);
    p.resize(12 * n);
    nv.resize(n);
    iver.resize(n);
    isTri.resize(n);
    for(std::size_t i = 0; i < n; i++) {
      MElement *e = lt[i];
      int m = (int)e->getNumVertices();
      nv[i] = m;
      iver[i] = -1; // stays -1 when the vertex is a high order node
      isTri[i] = (e->getType() == TYPE_TRI && e->getPolynomialOrder() == 1);
      for(int j = 0; j < m; j++) {
        MVertex *w = e->getVertex(j);
        if(w == ver) {
          iver[i] = j;
          continue;
        }
        // only the (up to 4) corners enter the area formula; higher order
        // elements should not get here (laplaceSmoothing rejects them), and
        // if one does, surface() warns and gives it a zero area, like
        // surfaceFaceUV
        if(j >= 4) continue;
        // a corner classified on the surface carries its parametric
        // coordinates, which is what reparamMeshVertexOnFace would return
        double uu, vv;
        if(w->onWhat() == gf && w->getParameter(0, uu) &&
           w->getParameter(1, vv)) {
          u[4 * i + j] = uu;
          v[4 * i + j] = vv;
        }
        else {
          SPoint2 q;
          reparamMeshVertexOnFace(w, gf, q);
          u[4 * i + j] = q.x();
          v[4 * i + j] = q.y();
        }
        p[12 * i + 3 * j] = w->x();
        p[12 * i + 3 * j + 1] = w->y();
        p[12 * i + 3 * j + 2] = w->z();
      }
    }
  }
  // area formula of surfaceFaceUV(element, gf, false) on the cached corners
  double surface(std::size_t i) const
  {
    if(nv[i] > 4) {
      Msg::Warning("surfaceFaceUV only for first order elements");
      return 0;
    }
    const double *uu = &u[4 * i], *vv = &v[4 * i];
    if(nv[i] == 3)
      return 0.5 * fabs((uu[1] - uu[0]) * (vv[2] - vv[0]) -
                        (uu[2] - uu[0]) * (vv[1] - vv[0]));
    const double a1 =
      0.5 * fabs((uu[1] - uu[0]) * (vv[2] - vv[0]) -
                 (uu[2] - uu[0]) * (vv[1] - vv[0])) +
      0.5 * fabs((uu[3] - uu[2]) * (vv[0] - vv[2]) -
                 (uu[0] - uu[2]) * (vv[3] - vv[2]));
    const double a2 =
      0.5 * fabs((uu[2] - uu[1]) * (vv[3] - vv[1]) -
                 (uu[3] - uu[1]) * (vv[2] - vv[1])) +
      0.5 * fabs((uu[0] - uu[3]) * (vv[1] - vv[3]) -
                 (uu[1] - uu[3]) * (vv[0] - vv[3]));
    return std::min(a2, a1);
  }
  // total area and minimum quality with the relocated vertex at the
  // parametric position `uvVer` and cartesian position `xyzVer`; for the
  // (rare) elements that are not first order triangles the quality is
  // evaluated on the mesh, so the relocated vertex itself must be at
  // `xyzVer` when calling this
  void evaluate(const SPoint2 &uvVer, const double *xyzVer, double &surface_,
                elementQuality &minq)
  {
    surface_ = 0;
    elementQuality q;
    for(std::size_t i = 0; i < n; i++) {
      int k = iver[i];
      if(k >= 0 && k < 4) {
        u[4 * i + k] = uvVer.x();
        v[4 * i + k] = uvVer.y();
        double *pk = &p[12 * i + 3 * k];
        pk[0] = xyzVer[0];
        pk[1] = xyzVer[1];
        pk[2] = xyzVer[2];
      }
      surface_ += surface(i);
      if(isTri[i]) {
        _minCornerSin2Cos(&p[12 * i], &p[12 * i + 3], &p[12 * i + 6], q.s2,
                          q.c);
        q.isSin2Cos = true;
      }
      else {
        q.val = elements[i]->etaShapeMeasure();
        q.isSin2Cos = false;
      }
      if(i == 0) {
        minq = q;
        // cap the initial minimum at 1; only relevant for element types
        // whose eta may exceed 1 (the eta of a triangle never does)
        if(!q.isSin2Cos) minq.val = std::min(q.val, 1.0);
      }
      else if(q < minq) {
        minq = q;
      }
    }
  }
};

// Move v1 from `before` to `after` if this does not increase the parametric
// surface area of its star and does not decrease the minimum shape quality.
// `surface` and `minq` hold the area and quality at `before`; they are
// updated to the values at `after` when the move is accepted. Return true
// (with v1 left at `after`) if the move was accepted.
static bool _isItAGoodIdeaToMoveThatVertex(GFace *gf, vertexStar &star,
                                           MVertex *v1, const SPoint2 &before,
                                           const SPoint2 &after,
                                           double &surface,
                                           elementQuality &minq)
{
  GPoint gp = gf->point(after);
  if(!gp.succeeded()) return false;
  SPoint3 pbefore(v1->x(), v1->y(), v1->z());

  v1->setParameter(0, after.x());
  v1->setParameter(1, after.y());
  v1->setXYZ(gp.x(), gp.y(), gp.z());

  double xyz[3] = {gp.x(), gp.y(), gp.z()};
  double surface_new;
  elementQuality minq_new;
  star.evaluate(after, xyz, surface_new, minq_new);

  if((1. + 1.e-10) * surface < surface_new || minq_new < minq) {
    v1->setParameter(0, before.x());
    v1->setParameter(1, before.y());
    v1->setXYZ(pbefore.x(), pbefore.y(), pbefore.z());
    return false;
  }
  surface = surface_new;
  minq = minq_new;
  return true;
}

void getAllBoundaryLayerVertices(GFace *gf, std::set<MVertex *> &vs)
{
  vs.clear();
  BoundaryLayerColumns *_columns = gf->getColumns();
  if(!_columns) return;
  for(auto it = _columns->_data.begin(); it != _columns->_data.end(); it++) {
    BoundaryLayerData &data = it->second;
    for(size_t i = 0; i < data._column.size(); i++) vs.insert(data._column[i]);
  }
}

static bool has_none_of(std::set<MVertex *> const &touched, MVertex *const v1,
                        MVertex *const v2, MVertex *const v3, MVertex *const v4)
{
  return touched.find(v1) == touched.end() &&
         touched.find(v2) == touched.end() &&
         touched.find(v3) == touched.end() && touched.find(v4) == touched.end();
}

static bool are_all_on_surface(MVertex *const v1, MVertex *const v2,
                               MVertex *const v3, MVertex *const v4, GFace *gf)
{
  return v1->onWhat() == gf && v2->onWhat() == gf && v3->onWhat() == gf &&
         v4->onWhat() == gf;
}

template <class InputIterator>
bool are_size_three(InputIterator iterator1, InputIterator iterator2)
{
  return iterator1->second.size() == 3 && iterator2->second.size() == 3;
}

static int _removeDiamonds(GFace *const gf)
{
  v2t_cont adj;
  buildVertexToElement(gf->quadrangles, adj);

  std::vector<MElement *> diamonds;
  std::set<MVertex *> touched;
  std::vector<MVertex *> deleted;

  std::vector<MQuadrangle *> quadrangles2;
  quadrangles2.reserve(gf->quadrangles.size());

  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    touched.insert(gf->triangles[i]->getVertex(0));
    touched.insert(gf->triangles[i]->getVertex(1));
    touched.insert(gf->triangles[i]->getVertex(2));
  }

  std::set<MVertex *> vs;
  getAllBoundaryLayerVertices(gf, vs);
  touched.insert(vs.begin(), vs.end());

  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    MQuadrangle *const q = gf->quadrangles[i];

    MVertex *const v1 = q->getVertex(0);
    MVertex *const v2 = q->getVertex(1);
    MVertex *const v3 = q->getVertex(2);
    MVertex *const v4 = q->getVertex(3);

    if(has_none_of(touched, v1, v2, v3, v4)) {
      auto it1 = adj.find(v1);
      auto it2 = adj.find(v2);
      auto it3 = adj.find(v3);
      auto it4 = adj.find(v4);

      if(are_all_on_surface(v1, v2, v3, v4, gf) && are_size_three(it1, it3) &&
         _tryToCollapseThatVertex(gf, it1->second, it3->second, q, v1, v3)) {
        touched.insert(v1);
        touched.insert(v2);
        touched.insert(v3);
        touched.insert(v4);

        deleted.push_back(v3);

        diamonds.push_back(q);
      }
      else if(are_all_on_surface(v1, v2, v3, v4, gf) &&
              are_size_three(it2, it4) &&
              _tryToCollapseThatVertex(gf, it2->second, it4->second, q, v2,
                                       v4)) {
        touched.insert(v1);
        touched.insert(v2);
        touched.insert(v3);
        touched.insert(v4);

        deleted.push_back(v4);

        diamonds.push_back(q);
      }
      else {
        quadrangles2.push_back(q);
      }
    }
    else {
      quadrangles2.push_back(q);
    }
  }
  std::sort(deleted.begin(), deleted.end());
  deleted.erase(std::unique(deleted.begin(), deleted.end()), deleted.end());

  gf->quadrangles = quadrangles2;

  std::vector<MVertex *> mesh_vertices2;
  mesh_vertices2.reserve(gf->mesh_vertices.size());

  for(std::size_t i = 0; i < gf->mesh_vertices.size(); i++) {
    if(!std::binary_search(deleted.begin(), deleted.end(),
                           gf->mesh_vertices[i])) {
      mesh_vertices2.push_back(gf->mesh_vertices[i]);
    }
    else {
      delete gf->mesh_vertices[i];
    }
  }
  gf->mesh_vertices = mesh_vertices2;

  std::sort(diamonds.begin(), diamonds.end());

  return std::distance(diamonds.begin(),
                       std::unique(diamonds.begin(), diamonds.end()));
}

int removeDiamonds(GFace *gf)
{
  std::size_t nbRemove = 0;
  while(1) {
    int x = _removeDiamonds(gf);
    if(!x) break;
    nbRemove += x;
  }
  Msg::Debug("%i diamond quads removed", nbRemove);
  return nbRemove;
}

struct p1p2p3 {
  MVertex *p1, *p2;
};

static void _relocate(GFace *gf, MVertex *ver, MElement *const *lt,
                      std::size_t nlt,
                      std::vector<std::pair<MVertex *, SPoint2> > &pts,
                      vertexStar &star)
{
  if(ver->onWhat() != gf) return;
  MFaceVertex *fv = dynamic_cast<MFaceVertex *>(ver);
  if(fv && fv->bl_data) return;

  double initu, initv;
  ver->getParameter(0, initu);
  ver->getParameter(1, initv);

  // compute the vertices connected to that one. A neighbour classified on
  // the surface has a single parametrization, read once (its second
  // occurrence, on the other edge that joins it to the vertex, is skipped);
  // the other neighbours keep the parameters of their last occurrence
  pts.clear();
  for(std::size_t i = 0; i < nlt; i++) {
    // for first order triangles and quadrangles (the only elements that
    // reach this point), edge j connects vertices j and j + 1
    int ne = lt[i]->getNumEdges();
    for(int j = 0; j < ne; j++) {
      MVertex *e0 = lt[i]->getVertex(j);
      MVertex *e1 = lt[i]->getVertex(j == ne - 1 ? 0 : j + 1);
      MVertex *nbr;
      if(e0 == ver)
        nbr = e1;
      else if(e1 == ver)
        nbr = e0;
      else
        continue;
      std::pair<MVertex *, SPoint2> *entry = nullptr;
      for(std::size_t k = 0; k < pts.size(); k++) {
        if(pts[k].first == nbr) {
          entry = &pts[k];
          break;
        }
      }
      if(entry && nbr->onWhat() == gf) continue;
      // a neighbour classified on the surface carries its parametric
      // coordinates, which is what reparamMeshEdgeOnFace would return
      SPoint2 pn;
      double uu, vv;
      if(nbr->onWhat() == gf && nbr->getParameter(0, uu) &&
         nbr->getParameter(1, vv)) {
        pn = SPoint2(uu, vv);
      }
      else {
        SPoint2 param0, param1;
        reparamMeshEdgeOnFace(e0, e1, gf, param0, param1);
        pn = (e0 == ver) ? param1 : param0;
      }
      if(entry)
        entry->second = pn;
      else
        pts.push_back(std::pair<MVertex *, SPoint2>(nbr, pn));
    }
  }
  // accumulate in increasing vertex number order, so that the target does
  // not depend on the order in which the elements list the neighbours
  std::sort(pts.begin(), pts.end(),
            [](const std::pair<MVertex *, SPoint2> &a,
               const std::pair<MVertex *, SPoint2> &b) {
              return a.first->getNum() < b.first->getNum();
            });

  SPoint2 before(initu, initv);
  double metric[3];
  SPoint2 after(0, 0);
  double COUNT = 0.0;
  for(auto it = pts.begin(); it != pts.end(); ++it) {
    SPoint2 adj = it->second;
    SVector3 d(adj.x() - before.x(), adj.y() - before.y(), 0.0);
    d.normalize();
    buildMetric(gf, adj, metric);
    const double F =
      sqrt(metric[0] * d.x() * d.x() + 2 * metric[1] * d.x() * d.y() +
           metric[2] * d.y() * d.y());
    after += adj * F;
    COUNT += F;
  }
  after *= (1.0 / COUNT);
  // surface area and minimum quality of the elements around ver at its
  // current position: they only change when a trial move is accepted, in
  // which case _isItAGoodIdeaToMoveThatVertex updates them
  star.build(gf, ver, lt, nlt);
  double xyz0[3] = {ver->x(), ver->y(), ver->z()};
  double surface;
  elementQuality minq;
  star.evaluate(before, xyz0, surface, minq);
  double FACTOR = 1.0;
  const int MAXITER = 5;
  SPoint2 actual = before;
  for(int ITER = 0; ITER < MAXITER; ITER++) {
    SPoint2 trial = after * FACTOR + before * (1. - FACTOR);
    if(_isItAGoodIdeaToMoveThatVertex(gf, star, ver, actual, trial, surface,
                                      minq)) {
      actual = trial;
    }
    FACTOR /= 1.4;
  }
}

void VertexToElementCSR::finalize()
{
  _elements.resize(_pairs.size());
  if(_pairs.empty()) {
    _first.push_back(0);
    return;
  }
  const std::size_t minNum = _minNum;
  const std::size_t range = _maxNum - minNum + 1;
  if(range <= 2 * _pairs.size() + 1024) {
    // the vertex numbers span a compact range (the common case for a freshly
    // generated mesh): distribute the elements with a counting sort, in O(N)
    std::vector<std::size_t> first(range + 1, 0);
    std::vector<MVertex *> byNum(range, nullptr);
    for(std::size_t i = 0; i < _pairs.size(); i++)
      first[_pairs[i].first->getNum() - minNum + 1]++;
    for(std::size_t k = 0; k < range; k++) first[k + 1] += first[k];
    std::vector<std::size_t> next(first.begin(), first.end() - 1);
    for(std::size_t i = 0; i < _pairs.size(); i++) {
      std::size_t k = _pairs[i].first->getNum() - minNum;
      byNum[k] = _pairs[i].first;
      _elements[next[k]++] = _pairs[i].second;
    }
    for(std::size_t k = 0; k < range; k++) {
      if(first[k + 1] != first[k]) {
        _vertices.push_back(byNum[k]);
        _first.push_back(first[k]);
      }
    }
    _first.push_back(_pairs.size());
  }
  else {
    // sparse vertex numbers: a stable sort keeps, for each vertex, the
    // elements in insertion order
    std::stable_sort(_pairs.begin(), _pairs.end(),
                     [](const std::pair<MVertex *, MElement *> &a,
                        const std::pair<MVertex *, MElement *> &b) {
                       return a.first->getNum() < b.first->getNum();
                     });
    for(std::size_t i = 0; i < _pairs.size(); i++) {
      if(i == 0 || _pairs[i].first != _pairs[i - 1].first) {
        _vertices.push_back(_pairs[i].first);
        _first.push_back(i);
      }
      _elements[i] = _pairs[i].second;
    }
    _first.push_back(_pairs.size());
  }
  _pairs.clear();
  _pairs.shrink_to_fit();
}

void laplaceSmoothing(GFace *gf, int niter, bool infinity_norm)
{
  if((gf->triangles.size() > 0 && gf->triangles[0]->getPolynomialOrder() > 1) ||
     (gf->quadrangles.size() > 0 &&
      gf->quadrangles[0]->getPolynomialOrder() > 1)) {
    Msg::Error(
      "Surface mesh smoothing only valid for first order mesh (use the high-"
      "order optimization tools for high-order meshes)");
    return;
  }

  if(!niter) return;

  Msg::Debug("laplacian smoothing ...");

  std::set<MVertex *> vs;
  getAllBoundaryLayerVertices(gf, vs);
  VertexToElementCSR adj;
  adj.add(gf->triangles);
  adj.add(gf->quadrangles);
  adj.finalize();
  std::vector<std::pair<MVertex *, SPoint2> > pts;
  vertexStar star;
  for(int i = 0; i < niter; i++) {
    for(std::size_t j = 0; j < adj.numVertices(); j++) {
      MVertex *v = adj.vertex(j);
      if(vs.find(v) == vs.end()) {
        _relocate(gf, v, adj.elements(j), adj.numElements(j), pts, star);
      }
    }
  }
}

static void _recombineIntoQuads(GFace *gf, bool blossom, bool cubicGraph = 1)
{
  if(gf->triangles.empty()) return;
  if(gf->compound.size()) return;

  std::set<MEdge, MEdgeLessThan> bndedges;
  std::set<MEdge, MEdgeLessThan> embedges;
  {
    std::vector<GEdge *> emb_edges = gf->getEmbeddedEdges();
    for(auto ee : emb_edges)
      for(auto l : ee->lines)
        embedges.insert(MEdge(l->getVertex(0), l->getVertex(1)));

    std::vector<GEdge *> edges = gf->edges();
    for(auto ee : edges)
      for(auto l : ee->lines)
        bndedges.insert(MEdge(l->getVertex(0), l->getVertex(1)));
  }

  e2t_cont adj;
  buildEdgeToElement(gf->triangles, adj);

  FieldManager *fields = gf->model()->getFields();
  Field *cross_field = NULL;
  SVector3 t1;

  if(fields->getBackgroundField() > 0) {
    cross_field = fields->get(fields->getBackgroundField());
    if(cross_field->numComponents() != 3) { // we hae a true scaled cross fiel
      cross_field = NULL;
    }
  }

  std::vector<RecombineTriangle> pairs;

  std::map<MVertex *, std::pair<MElement *, MElement *>> makeGraphPeriodic;

  for(auto it = adj.begin(); it != adj.end(); ++it) {
    MEdge ed(it->first.getVertex(0), it->first.getVertex(1));
    if(bndedges.find(ed) == bndedges.end() &&
       embedges.find(ed) == embedges.end() &&
       it->second.second && it->second.first->getNumVertices() == 3 &&
       it->second.second->getNumVertices() == 3) {
      pairs.push_back(RecombineTriangle(it->first, it->second.first,
                                        it->second.second, cross_field));
    }
    else if(embedges.find(ed) == embedges.end() &&
            !it->second.second && it->second.first->getNumVertices() == 3) {
      for(int i = 0; i < 2; i++) {
        MVertex *const v = it->first.getVertex(i);
        auto itv = makeGraphPeriodic.find(v);
        if(itv == makeGraphPeriodic.end()) {
          makeGraphPeriodic[v] =
            std::make_pair(it->second.first, static_cast<MElement *>(nullptr));
        }
        else {
          if(itv->second.first != it->second.first)
            itv->second.second = it->second.first;
          else
            makeGraphPeriodic.erase(itv);
        }
      }
    }
  }

  std::sort(pairs.begin(), pairs.end());
  std::set<MElement *> touched;

  if(blossom) {
#if defined(HAVE_BLOSSOM)
    int ncount = gf->triangles.size();
    if(ncount % 2 != 0) {
      Msg::Warning("Cannot apply Blossom: odd number of triangles (%d) in "
                   "surface %d",
                   ncount, gf->tag());
    }
    else {
      int ecount =
        cubicGraph ? (pairs.size() + makeGraphPeriodic.size()) : pairs.size();
      Msg::Info("Blossom: %d internal %d closed", (int)pairs.size(),
                (int)makeGraphPeriodic.size());
      Msg::Debug("Perfect Match Starts %d edges %d nodes", ecount, ncount);
      std::map<MElement *, int> t2n;
      std::map<int, MElement *> n2t;
      for(std::size_t i = 0; i < gf->triangles.size(); ++i) {
        t2n[gf->triangles[i]] = i;
        n2t[i] = gf->triangles[i];
      }
      // do not use new[] here, blossom will free it with free() and not with
      // delete
      int *elist = (int *)malloc(sizeof(int) * 2 * ecount);
      int *elen = (int *)malloc(sizeof(int) * ecount);

      for(std::size_t i = 0; i < pairs.size(); ++i) {
        elist[2 * i] = t2n[pairs[i].t1];
        elist[2 * i + 1] = t2n[pairs[i].t2];
        elen[i] = (int)1000 * std::exp(-pairs[i].angle);
        int NB = 0;
        if(pairs[i].n1->onWhat()->dim() < 2) NB++;
        if(pairs[i].n2->onWhat()->dim() < 2) NB++;
        if(pairs[i].n3->onWhat()->dim() < 2) NB++;
        if(pairs[i].n4->onWhat()->dim() < 2) NB++;
        if(elen[i] > static_cast<int>(1000 * std::exp(0.1)) && NB > 2) {
          elen[i] = 5000;
        }
        else if(elen[i] >= 1000 && NB > 2) {
          elen[i] = 10000;
        }
      }

      if(cubicGraph) {
        auto itv = makeGraphPeriodic.begin();
        std::size_t CC = pairs.size();
        for(; itv != makeGraphPeriodic.end(); ++itv) {
          elist[2 * CC] = t2n[itv->second.first];
          elist[2 * CC + 1] = t2n[itv->second.second];
          elen[CC++] = 100000;
        }
      }

      double matzeit = 0.0;
      char MATCHFILE[256];
      sprintf(MATCHFILE, ".face.match");
      if(perfect_match(ncount, nullptr, ecount, &elist, &elen, nullptr,
                       MATCHFILE, 0, 0, 0, 0, &matzeit)) {
        Msg::Warning(
          "Perfect Match failed in quadrangulation, try something else");
        free(elist);
        pairs.clear();
        _recombineIntoQuads(gf, false, cubicGraph);
      }
      else {
        // TEST
        for(int k = 0; k < elist[0]; k++) {
          int i1 = elist[1 + 3 * k], i2 = elist[1 + 3 * k + 1],
              an = elist[1 + 3 * k + 2];
          // FIXME !
          if(an == 100000 /*|| an == 1000*/) {
            // toProcess.push_back(std::make_pair(n2t[i1],n2t[i2]));
            // Msg::Warning("Extra edge found in blossom algorithm,
            // optimization"
            //              "will be required");
          }
          else {
            MElement *t1 = n2t[i1];
            MElement *t2 = n2t[i2];
            touched.insert(t1);
            touched.insert(t2);
            MVertex *other = nullptr;
            for(int i = 0; i < 3; i++) {
              if(t1->getVertex(0) != t2->getVertex(i) &&
                 t1->getVertex(1) != t2->getVertex(i) &&
                 t1->getVertex(2) != t2->getVertex(i)) {
                other = t2->getVertex(i);
                break;
              }
            }
            int start = 0;
            for(int i = 0; i < 3; i++) {
              if(t2->getVertex(0) != t1->getVertex(i) &&
                 t2->getVertex(1) != t1->getVertex(i) &&
                 t2->getVertex(2) != t1->getVertex(i)) {
                start = i;
                break;
              }
            }
            MVertex *vs[4] = {t1->getVertex(start),
                              t1->getVertex((start + 1) % 3), other,
                              t1->getVertex((start + 2) % 3)};
            MEdge e1(vs[0], vs[2]);
            MEdge e2(vs[1], vs[3]);
            if(embedges.find(e1) != embedges.end()) {
              MTriangle *t1 = new MTriangle(vs[0], vs[1], vs[2]);
              MTriangle *t2 = new MTriangle(vs[2], vs[3], vs[0]);
              gf->triangles.push_back(t1);
              gf->triangles.push_back(t2);
            }
            else if(embedges.find(e2) != embedges.end()) {
              MTriangle *t1 = new MTriangle(vs[1], vs[2], vs[3]);
              MTriangle *t2 = new MTriangle(vs[3], vs[0], vs[1]);
              gf->triangles.push_back(t1);
              gf->triangles.push_back(t2);
            }
            else {
              MQuadrangle *q = new MQuadrangle(vs[0], vs[1], vs[2], vs[3]);
              gf->quadrangles.push_back(q);
            }
          }
        }
        free(elist);
        pairs.clear();
        Msg::Debug("Perfect Match Succeeded in Quadrangulation (%g sec)",
                   matzeit);
      }
    }
#else
    Msg::Warning("Gmsh should be compiled with the Blossom IV code and "
                 " CONCORDE in order to allow the Blossom optimization");
#endif
  }

  // simple greedy recombination
  auto itp = pairs.begin();
  while(itp != pairs.end()) {
    if(itp->angle < gf->meshAttributes.recombineAngle) {
      MElement *t1 = itp->t1;
      MElement *t2 = itp->t2;
      if(touched.find(t1) == touched.end() &&
         touched.find(t2) == touched.end()) {
        touched.insert(t1);
        touched.insert(t2);
        int orientation = 0;
        for(int i = 0; i < 3; i++) {
          if(t1->getVertex(i) == itp->n1) {
            if(t1->getVertex((i + 1) % 3) == itp->n2)
              orientation = 1;
            else
              orientation = -1;
            break;
          }
        }
        gf->quadrangles.push_back(
          new MQuadrangle(itp->n1, orientation < 0 ? itp->n3 : itp->n4, itp->n2,
                          orientation < 0 ? itp->n4 : itp->n3));
      }
    }
    ++itp;
  }

  std::vector<MTriangle *> triangles2;
  triangles2.reserve(gf->triangles.size());
  for(std::size_t i = 0; i < gf->triangles.size(); i++) {
    if(touched.find(gf->triangles[i]) == touched.end()) {
      triangles2.push_back(gf->triangles[i]);
    }
    else {
      delete gf->triangles[i];
    }
  }
  gf->triangles = triangles2;
}

static double printStats(GFace *gf, const char *message)
{
  int nbBad = 0;
  int nbInv = 0;
  double Qav = 0;
  double Qmin = 1;
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    double Q = gf->quadrangles[i]->etaShapeMeasure();
    if(Q <= 0.0) nbInv++;
    if(Q <= 0.1) nbBad++;
    Qav += Q;
    Qmin = std::min(Q, Qmin);
  }
  Msg::Info(
    "%s: %d quads, %d triangles, %d invalid quads, %d quads with Q < 0.1, "
    "avg Q = %g, min Q = %g",
    message, gf->quadrangles.size(), gf->triangles.size(), nbInv, nbBad,
    Qav / std::max((int)gf->quadrangles.size(), 1), Qmin);
  return Qmin;
}

// The topological optimization routines assume that a full topology of the
// model exists. When reading multi-surface STL files for example, if
// CreateTopology or ReclassifySurfaces is not called, quads can have nodes
// owned by an adjacent surface. Since the topological optimization routines
// remove nodes, this will produce an invalide model mesh (and crash).
static bool _isModelOkForTopologicalOpti(GModel *m)
{
  for(auto it = m->firstFace(); it != m->lastFace(); it++) {
    GFace *gf = *it;
    for(std::size_t j = 0; j < gf->getNumMeshElements(); j++) {
      MElement *e = gf->getMeshElement(j);
      for(std::size_t k = 0; k < e->getNumVertices(); k++) {
        GEntity *ge = e->getVertex(k)->onWhat();
        if(!ge) return false;
        if(ge->dim() == 2 && ge != gf) return false;
      }
    }
  }
  return true;
}

void recombineIntoQuads(GFace *gf, bool blossom, int topologicalOptiPasses,
                        bool nodeRepositioning, double minqual)
{
  double t1 = Cpu(), w1 = TimeOfDay();

  bool haveParam = (gf->geomType() != GEntity::DiscreteSurface);
  bool debug = (Msg::GetVerbosity() == 99);

  if(debug) gf->model()->writeMSH("recombine_0before.msh");

  _recombineIntoQuads(gf, blossom);

  if(debug) gf->model()->writeMSH("recombine_1raw.msh");

  if(haveParam && nodeRepositioning) {
    RelocateVertices(gf, CTX::instance()->mesh.nbSmoothing);
    if(debug) gf->model()->writeMSH("recombine_2smoothed.msh");
  }

// FIXME: not thread-safe
#pragma omp critical(recombineIntoQuads)
  {
    if(topologicalOptiPasses > 0) {
      if(!_isModelOkForTopologicalOpti(gf->model())) {
        Msg::Info(
          "Skipping topological optimization - mesh topology is not complete");
      }
      else {
        int iter = 0, nbTwoQuadNodes = 1, nbDiamonds = 1;
        while(nbTwoQuadNodes || nbDiamonds) {
          Msg::Debug("Topological optimization of quad mesh: pass %d", iter);
          nbTwoQuadNodes = removeTwoQuadsNodes(gf);
          // removeDiamonds uses the parametrization or searches for closest
          // point
          nbDiamonds = haveParam ? removeDiamonds(gf) : 0;
          if(haveParam && nodeRepositioning)
            RelocateVertices(gf, CTX::instance()->mesh.nbSmoothing);
          iter++;
          if(iter > topologicalOptiPasses) break;
        }
        if(debug) gf->model()->writeMSH("recombine_3topo.msh");
      }
    }
  }

  // re-split bad quads into triangles
  if(minqual > 0) quadsToTriangles(gf, minqual);

  if(debug) gf->model()->writeMSH("recombine_4quality.msh");

  if(haveParam && nodeRepositioning)
    RelocateVertices(gf, CTX::instance()->mesh.nbSmoothing);

  double t2 = Cpu(), w2 = TimeOfDay();

  char name[256];
  sprintf(name, "%s recombination completed (Wall %gs, CPU %gs)",
          blossom ? "Blossom" : "Simple", w2 - w1, t2 - t1);
  printStats(gf, name);
  if(debug) gf->model()->writeMSH("recombine_5final.msh");
}

void quadsToTriangles(GFace *gf, double minqual)
{
  std::vector<MQuadrangle *> qds;
  std::map<MElement *, std::pair<MElement *, MElement *>> change;
  for(std::size_t i = 0; i < gf->quadrangles.size(); i++) {
    MQuadrangle *q = gf->quadrangles[i];
    if(q->etaShapeMeasure() < minqual + 1e-12) {
      MTriangle *t11 =
        new MTriangle(q->getVertex(0), q->getVertex(1), q->getVertex(2));
      MTriangle *t12 =
        new MTriangle(q->getVertex(2), q->getVertex(3), q->getVertex(0));
      MTriangle *t21 =
        new MTriangle(q->getVertex(1), q->getVertex(2), q->getVertex(3));
      MTriangle *t22 =
        new MTriangle(q->getVertex(3), q->getVertex(0), q->getVertex(1));
      double qual1 =
        std::min(t11->gammaShapeMeasure(), t12->gammaShapeMeasure());
      double qual2 =
        std::min(t21->gammaShapeMeasure(), t22->gammaShapeMeasure());
      double ori2 = dot(t21->getFace(0).normal(), t22->getFace(0).normal());
      // choose (t11, t12) if it leads to the best quality OR if choosing (t21,
      // t22) would revert the orientation (which can happen if q is not convex)
      if(qual1 > qual2 || ori2 < 0) {
        gf->triangles.push_back(t11);
        gf->triangles.push_back(t12);
        change[q] = std::make_pair(t11, t12);
        delete t21;
        delete t22;
      }
      else {
        gf->triangles.push_back(t21);
        gf->triangles.push_back(t22);
        change[q] = std::make_pair(t21, t22);
        delete t11;
        delete t12;
      }
      delete q;
    }
    else {
      qds.push_back(q);
    }
  }
  gf->quadrangles = qds;

  BoundaryLayerColumns *_columns = gf->getColumns();
  if(!_columns) return;

  // Update the data struture for boundary layers
  // WARNING: First quad element is replaced by one of the two triangles,
  // without taking care of if it is the truly the first one or not.

  //  std::map<MElement*,MElement*> _toFirst;
  std::map<MElement *, std::vector<MElement *>> newElemColumns;

  for(auto it = _columns->_elemColumns.begin();
      it != _columns->_elemColumns.end(); it++) {
    MElement *firstEl = it->first;
    auto it2 = change.find(firstEl);
    if(it2 != change.end()) firstEl = it2->second.first;
    // it2->second.first may be the one that touch boundary or not...

    std::vector<MElement *> &newColumn = newElemColumns[firstEl];
    std::vector<MElement *> &oldColumn = it->second;

    for(std::size_t i = 0; i < oldColumn.size(); i++) {
      MElement *oldEl = oldColumn[i];
      it2 = change.find(oldEl);
      if(it2 == change.end()) {
        newColumn.push_back(oldEl);
        _columns->_toFirst[oldEl] = firstEl;
      }
      else {
        newColumn.push_back(it2->second.first);
        newColumn.push_back(it2->second.second);
        _columns->_toFirst.erase(oldEl);
        _columns->_toFirst[it2->second.first] = firstEl;
        _columns->_toFirst[it2->second.second] = firstEl;
      }
    }
  }
  _columns->_elemColumns = newElemColumns;
}

void splitElementsInBoundaryLayerIfNeeded(GFace *gf)
{
  if(!CTX::instance()->mesh.recombineAll && !gf->meshAttributes.recombine) {
    int numSplit = 0;
    int numNoSplit = 0;
    FieldManager *fields = gf->model()->getFields();
    int n = fields->getNumBoundaryLayerFields();
    for(int i = 0; i < n; ++i) {
      Field *bl_field = fields->get(fields->getBoundaryLayerField(i));
      if(!bl_field) continue;
      BoundaryLayerField *blf = dynamic_cast<BoundaryLayerField *>(bl_field);
      if(!blf) continue;
      if(blf->iRecombine)
        ++numNoSplit;
      else
        ++numSplit;
    }

    if(numSplit > 0 && numNoSplit > 0)
      Msg::Warning("Cannot generate simplicial and non-simplicial boundary "
                   "layers together. Keeping them non-simplicial...");
    if(numNoSplit == 0 && numSplit > 0) quadsToTriangles(gf, 10000);
  }
}
