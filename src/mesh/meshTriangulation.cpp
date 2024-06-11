// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <utility>
#include <list>
#include <map>
#include <unordered_map>
#include "Context.h"
#include "gmsh.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MLine.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "meshTriangulation.h"
#include "SBoundingBox3d.h"
#include "robustPredicates.h"
#include "meshGFaceDelaunayInsertion.h"
#include "qualityMeasures.h"
#include "Numeric.h"
#include "SPoint3.h"

void swap(double &a, double &b)
{
  double temp = a;
  a = b;
  b = temp;
}

size_t HilbertCoordinates(double x, double y, double x0, double y0, double xRed,
                          double yRed, double xBlue, double yBlue)
{
  size_t BIG = 1073741824;
  size_t RESULT = 0;
  for(int i = 0; i < 16; i++) {
    double coordRed = (x - x0) * xRed + (y - y0) * yRed;
    double coordBlue = (x - x0) * xBlue + (y - y0) * yBlue;
    xRed /= 2;
    yRed /= 2;
    xBlue /= 2;
    yBlue /= 2;
    if(coordRed <= 0 && coordBlue <= 0) { // quadrant 0
      x0 -= (xBlue + xRed);
      y0 -= (yBlue + yRed);
      swap(xRed, xBlue);
      swap(yRed, yBlue);
    }
    else if(coordRed <= 0 && coordBlue >= 0) { // quadrant 1
      RESULT += BIG;
      x0 += (xBlue - xRed);
      y0 += (yBlue - yRed);
    }
    else if(coordRed >= 0 && coordBlue >= 0) { // quadrant 2
      RESULT += 2 * BIG;
      x0 += (xBlue + xRed);
      y0 += (yBlue + yRed);
    }
    else if(coordRed >= 0 && coordBlue <= 0) { // quadrant 3
      x0 += (-xBlue + xRed);
      y0 += (-yBlue + yRed);
      swap(xRed, xBlue);
      swap(yRed, yBlue);
      xBlue = -xBlue;
      yBlue = -yBlue;
      xRed = -xRed;
      yRed = -yRed;
      RESULT += 3 * BIG;
    }
    else
      Msg::Warning("Hilbert failed %d %d", coordRed, coordBlue);
    BIG /= 4;
  }
  return RESULT;
}

struct pair_hash {
  template <class T1, class T2>
  std::size_t operator()(const std::pair<T1, T2> &pair) const
  {
    return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
  }
};

int PolyMesh2GFace(PolyMesh *pm, int faceTag)
{
  GFace *gf = GModel::current()->getFaceByTag(faceTag);

  if(!gf){
    Msg::Error("PolyMesh2GFace cannot find surface %d", faceTag);
    return 0;
  }

  for(auto t : gf->triangles) delete t;
  for(auto q : gf->quadrangles) delete q;
  gf->triangles.clear();
  gf->quadrangles.clear();

  std::unordered_map<int, MVertex *> news;
  std::unordered_map<PolyMesh::HalfEdge *, GPoint> hon;

  if(!pm->high_order_nodes.empty()) {
    for(size_t i = 0; i < pm->high_order_nodes.size(); i++) {
      auto it = hon.find(pm->hedges[i]);
      if(it == hon.end()) {
        double uv[2] = {0, 0};
        SVector3 p = pm->high_order_nodes[i];
        GPoint gp = gf->closestPoint(SPoint3(p.x(), p.y(), p.z()), uv);
        if(!gp.succeeded()) {
          gp.x() = p.x();
          gp.y() = p.y();
          gp.z() = p.z();
        }
        hon[pm->hedges[i]] = gp;
        if(pm->hedges[i]->opposite) hon[pm->hedges[i]] = gp;
      }
    }
  }

  std::map<MEdge, GPoint, MEdgeLessThan> hop;

  for(auto f : pm->faces) {
    if(f->data == faceTag) {
      PolyMesh::Vertex *v[4] = {f->he->v, f->he->next->v, f->he->next->next->v,
                                f->he->next->next->next->v};
      MVertex *v_gmsh[4];

      for(int i = 0; i < pm->num_sides(f->he); i++) {
        if(v[i]->data != -1) {
          auto it = news.find(v[i]->data);
          if(it == news.end())
            v_gmsh[i] = GModel::current()->getMeshVertexByTag(v[i]->data);
          else
            v_gmsh[i] = it->second;
        }
        else {
          double uv[2] = {0, 0};
          GPoint gp = gf->closestPoint(
            SPoint3(v[i]->position.x(), v[i]->position.y(), v[i]->position.z()),
            uv);
          if(gp.succeeded())
            v_gmsh[i] =
              new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
          else
            v_gmsh[i] = new MFaceVertex(v[i]->position.x(), v[i]->position.y(),
                                        v[i]->position.z(), gf,
                                        v[i]->position.x(), v[i]->position.y());
          gf->mesh_vertices.push_back(v_gmsh[i]);
          v[i]->data = v_gmsh[i]->getNum();
          news[v[i]->data] = v_gmsh[i];
        }
      }

      if(hon.size()) {
        MEdge l01(v_gmsh[0], v_gmsh[1]);
        hop[l01] = hon[f->he];
        MEdge l12(v_gmsh[1], v_gmsh[2]);
        hop[l12] = hon[f->he->next];
        MEdge l20(v_gmsh[2], v_gmsh[0]);
        hop[l20] = hon[f->he->next->next];
      }

      if(pm->num_sides(f->he) == 3)
        gf->triangles.push_back(new MTriangle(v_gmsh[0], v_gmsh[1], v_gmsh[2]));
      else if(pm->num_sides(f->he) == 4)
        gf->quadrangles.push_back(
          new MQuadrangle(v_gmsh[0], v_gmsh[1], v_gmsh[2], v_gmsh[3]));
    }
  }

  if(!hon.empty()) {
    GModel::current()->setOrderN(2, 0, 0, 0);
#if 1
    for(auto t : gf->triangles) {
      for(int i = 0; i < 3; i++) {
        MEdge li(t->getVertex(i), t->getVertex((i + 1) % 3));
        GPoint gp = hop[li];
        MVertex *vint = t->getVertex(i + 3);
        vint->x() = gp.x();
        vint->y() = gp.y();
        vint->z() = gp.z();
      }
    }
#endif
  }

  CTX::instance()->mesh.changed = ENT_ALL;

  return 0;
}

int GFace2PolyMesh(int faceTag, PolyMesh **pm)
{
  // FIXME using the public API inside Gmsh is not a good idea
  if(!gmsh::isInitialized()) gmsh::initialize();
  *pm = new PolyMesh;

  std::unordered_map<size_t, size_t> nodeLabels;
  std::unordered_map<std::pair<size_t, size_t>, PolyMesh::HalfEdge *, pair_hash>
    opposites;

  // FIXME should probably not use the public API here
  std::vector<int> elementTypes;
  std::vector<std::vector<std::size_t> > elementTags;
  std::vector<std::vector<std::size_t> > nodeTags;
  gmsh::model::mesh::getElements(elementTypes, elementTags, nodeTags, 2,
                                 faceTag);

  for(size_t K = 0; K < elementTypes.size(); K++) {
    int eT = elementTypes[K];
    int nNod = 0;
    if(eT == 2)
      nNod = 3;
    else if(eT == 3)
      nNod = 4;
    else {
      Msg::Error("GFace2PolyMesh only support quads (element type 3) and "
                 "triangles (element type 2)");
      return -1;
    }
    PolyMesh::Vertex *v[4] = {nullptr, nullptr, nullptr, nullptr};

    for(size_t i = 0; i < elementTags[K].size(); i++) {
      for(int j = 0; j < nNod; j++) {
        size_t nodeTag = nodeTags[K][nNod * i + j];
        auto it = nodeLabels.find(nodeTag);
        if(it == nodeLabels.end()) {
          // FIXME should probably not use the public API here
          std::vector<double> coord(3), parametricCoord(3);
          int entityDim, entityTag;
          gmsh::model::mesh::getNode(nodeTag, coord, parametricCoord, entityDim,
                                     entityTag);
          v[j] = new PolyMesh::Vertex(coord[0], coord[1], coord[2], nodeTag);
          nodeLabels[nodeTag] = (*pm)->vertices.size();
          (*pm)->vertices.push_back(v[j]);
        }
        else
          v[j] = (*pm)->vertices[it->second];
      }

      PolyMesh::HalfEdge *he[4];
      for(int j = 0; j < nNod; j++) {
        he[j] = new PolyMesh::HalfEdge(v[j]);
        (*pm)->hedges.push_back(he[j]);
        v[j]->he = he[j];
      }

      PolyMesh::Face *ff = new PolyMesh::Face(he[0]);
      (*pm)->faces.push_back(ff);

      for(int j = 0; j < nNod; j++) {
        he[j]->next = he[(j + 1) % nNod];
        he[j]->prev = he[(j - 1 + nNod) % nNod];
        he[j]->f = ff;
        //	size_t n0 = v[j]->data;
        //	size_t n1 = v[(j+1)%nNod]->data;
        //	std::pair<size_t, size_t> pj =
        //	  std::make_pair(std::min(n0,n1),std::max(n0,n1));
        //	auto itj = opposites.find(pj);
        //	if(itj == opposites.end()) opposites[pj] = he[j];
        //	else {
        //	  he[j]->opposite = itj->second;
        //	  itj->second->opposite = he[j];
        //	}
      }
    }
  }

  HalfEdgePtrLessThan compare;
  std::sort((*pm)->hedges.begin(), (*pm)->hedges.end(), compare);

  HalfEdgePtrEqual equal;
  for(size_t i = 0; i < (*pm)->hedges.size() - 1; i++) {
    PolyMesh::HalfEdge *h0 = (*pm)->hedges[i];
    PolyMesh::HalfEdge *h1 = (*pm)->hedges[i + 1];
    if(equal(h0, h1)) {
      h0->opposite = h1;
      h1->opposite = h0;
      i++;
    }
  }
  return 0;
}

static int delaunayEdgeCriterionPlaneIsotropic(PolyMesh::HalfEdge *he, void *)
{
  if(he->opposite == nullptr) return -1;
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;

  // FIXME : should be oriented anyway !
  double result = -robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);

  return (result > 0) ? 1 : 0;
}

static double faceQuality(PolyMesh::Vertex *v0,
			  PolyMesh::Vertex *v1,
			  PolyMesh::Vertex *v2)
{
  return qmTriangle::gamma(v0->position.x(), v0->position.y(), v0->position.z(),
			   v1->position.x(), v1->position.y(), v1->position.z(),
			   v2->position.x(), v2->position.y(), v2->position.z());
}

static int enhanceQuality(PolyMesh::HalfEdge *he, void *)
{
  if(he->opposite == nullptr) return -1;

  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v3 = he->opposite->next->next->v;

  int d0 = degree(v0);
  int d1 = degree(v1);
  int d2 = degree(v2);
  int d3 = degree(v3);

  if ((d0 > 7 || d1 > 7) && (d2 < 7 && d3 < 7))return 1;
    
  double qBefore = std::min(faceQuality(v0,v1,v2), faceQuality(v1,v0,v3));
  double qAfter  = std::min(faceQuality(v2,v3,v0), faceQuality(v3,v2,v1));
  
  return qAfter > qBefore ? 1 : 0;
}


static void faceCircumCenter(PolyMesh::HalfEdge *he, GFace *gf, double *res,
                             double *uv)
{
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  GPoint p0 = gf->point(v0->position.x(), v0->position.y());
  GPoint p1 = gf->point(v1->position.x(), v1->position.y());
  GPoint p2 = gf->point(v2->position.x(), v2->position.y());
  double q0[3] = {p0.x(), p0.y(), p0.z()};
  double q1[3] = {p1.x(), p1.y(), p1.z()};
  double q2[3] = {p2.x(), p2.y(), p2.z()};
  circumCenterXYZ(q0, q1, q2, res, uv);
}


static double faceQuality(PolyMesh::HalfEdge *he, GFace *gf)
{
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  GPoint p0 = gf->point(v0->position.x(), v0->position.y());
  GPoint p1 = gf->point(v1->position.x(), v1->position.y());
  GPoint p2 = gf->point(v2->position.x(), v2->position.y());
  return qmTriangle::gamma(p0.x(), p0.y(), p0.z(), p1.x(), p1.y(), p1.z(),
                           p2.x(), p2.y(), p2.z());
}

/*
static int qualityCriterion3D(PolyMesh::HalfEdge *he, void *p){
  if (he->data > 0) return -1;
  if (he->opposite == nullptr) return -1;
  if (p == nullptr) return -1;

  GFace *gf = (GFace*)p;

  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v3 = he->opposite->next->next->v;

  GPoint p0 = gf->point (v0->position.x(),v0->position.y());
  GPoint p1 = gf->point (v1->position.x(),v1->position.y());
  GPoint p2 = gf->point (v2->position.x(),v2->position.y());
  GPoint p3 = gf->point (v3->position.x(),v3->position.y());

  double q1 = qmTriangle::gamma
(p0.x(),p0.y(),p0.z(),p1.x(),p1.y(),p1.z(),p2.x(),p2.y(),p2.z()); double q2 =
qmTriangle::gamma
(p2.x(),p2.y(),p2.z(),p3.x(),p3.y(),p3.z(),p0.x(),p0.y(),p0.z());

  double o1 = qmTriangle::gamma
(p1.x(),p1.y(),p1.z(),p2.x(),p2.y(),p2.z(),p3.x(),p3.y(),p3.z()); double o2 =
qmTriangle::gamma
(p3.x(),p3.y(),p3.z(),p0.x(),p0.y(),p0.z(),p1.x(),p1.y(),p1.z());

  return std::max(fabs(q1),fabs(q2)) > std::max(fabs(o1),fabs(o2)) ? 0 : 1;
}
*/

static PolyMesh::Face *Walk(PolyMesh::Face *f, double x, double y)
{
  double POS[2] = {x, y};
  PolyMesh::HalfEdge *he = f->he;

  while(1) {
    PolyMesh::Vertex *v0 = he->v;
    PolyMesh::Vertex *v1 = he->next->v;
    PolyMesh::Vertex *v2 = he->next->next->v;

    double s0 = -robustPredicates::orient2d(v0->position, v1->position, POS);
    double s1 = -robustPredicates::orient2d(v1->position, v2->position, POS);
    double s2 = -robustPredicates::orient2d(v2->position, v0->position, POS);

    if(s0 >= 0 && s1 >= 0 && s2 >= 0) {
      /* printf("Face %g %g %g / %g %g %g / %g %g %g \n",
                v0->position.x(), v0->position.y(), v0->position.z(),
                v1->position.x(), v1->position.y(), v1->position.z(),
                v2->position.x(), v2->position.y(), v2->position.z());
                printf("point %g %g CURRENT FACE %p %g %g %g\n", x,y,he->f,
                s0,s1,s2); */
      // getchar();
      return he->f;
    }
    else if(s0 <= 0 && s1 >= 0 && s2 >= 0)
      he = he->opposite;
    else if(s1 <= 0 && s0 >= 0 && s2 >= 0)
      he = he->next->opposite;
    else if(s2 <= 0 && s0 >= 0 && s1 >= 0)
      he = he->next->next->opposite;
    else if(s0 <= 0 && s1 <= 0)
      he = s0 > s1 ? he->opposite : he->next->opposite;
    else if(s0 <= 0 && s2 <= 0)
      he = s0 > s2 ? he->opposite : he->next->next->opposite;
    else if(s1 <= 0 && s2 <= 0)
      he = s1 > s2 ? he->next->opposite : he->next->next->opposite;
    else {
      Msg::Error("Could not find half-edge in walk for point %g %g on "
                 "face %g %g %g / %g %g %g / %g %g %g "
                 "(orientation tests %g %g %g)", x, y,
                 v0->position.x(), v0->position.y(), v0->position.z(),
                 v1->position.x(), v1->position.y(), v1->position.z(),
                 v2->position.x(), v2->position.y(), v2->position.z(),
                 s0, s1, s2);
    }
    if(he == nullptr) break;
  }
  // should only come here wether the triangulated domain is not convex
  return nullptr;
}

// recover an edge that goes from v_start --> v_end
// ----------------------------------- assume it's internal !!!

static int intersect(PolyMesh::Vertex *v0, PolyMesh::Vertex *v1,
                     PolyMesh::Vertex *b0, PolyMesh::Vertex *b1)
{
  double s0 =
    robustPredicates::orient2d(v0->position, v1->position, b0->position);
  double s1 =
    robustPredicates::orient2d(v0->position, v1->position, b1->position);
  if(s0 * s1 >= 0) return 0;
  double t0 =
    robustPredicates::orient2d(b0->position, b1->position, v0->position);
  double t1 =
    robustPredicates::orient2d(b0->position, b1->position, v1->position);
  if(t0 * t1 >= 0) return 0;
  return 1;
}

static int recover_edge(PolyMesh *pm, PolyMesh::Vertex *v_start,
                        PolyMesh::Vertex *v_end)
{
  PolyMesh::HalfEdge *he = v_start->he;
  std::list<PolyMesh::HalfEdge *> _list;

  do {
    PolyMesh::Vertex *v1 = he->next->v;
    if(v1 == v_end) {
      return 0; // edge exists
    }
    PolyMesh::Vertex *v2 = he->next->next->v;
    if(v2 == v_end) {
      return 0; // edge exists
    }

    if(intersect(v_start, v_end, v1, v2)) {
      // printf("INTERSECTION WITH %d %d\n", v1->data, v2->data);
      _list.push_back(he->next);
      break;
    }
    he = he->next->next->opposite;
  } while(he != v_start->he);

  if(_list.empty()) { return -1; }

  // find all intersections
  while(1) {
    he = _list.back();
    he = he->opposite;
    if(!he) return -2;
    he = he->next;
    PolyMesh::Vertex *v1 = he->v;
    PolyMesh::Vertex *v2 = he->next->v;
    if(v2 == v_end) {
      // printf("END FOUND %d\n", v2->data);
      break;
    }
    if(intersect(v_start, v_end, v1, v2)) {
      // printf("INTESECTION %d %d\n", v1->data, v2->data);
      _list.push_back(he);
    }
    else {
      he = he->next;
      v1 = he->v;
      v2 = he->next->v;
      if(v2 == v_end) {
        // printf("END FOUND %d\n", v2->data);
        break;
      }
      if(intersect(v_start, v_end, v1, v2)) {
        // printf("INTESECTION %d %d\n", v1->data, v2->data);
        _list.push_back(he);
      }
      else {
        return -3;
      }
    }
  }

  int nbIntersection = _list.size();
  // printf("%d intersections\n", nbIntersection);
  // int K = 100;
  while(!_list.empty()) {
    he = *_list.begin();
    _list.erase(_list.begin());
    // ensure that swap is allowed (convex quad)
    if(intersect(he->v, he->next->v, he->next->next->v,
                 he->opposite->next->next->v)) {
      // ensure that swap removes one intersection
      int still_intersect = intersect(v_start, v_end, he->next->next->v,
                                      he->opposite->next->next->v);
      // printf("swapping %d %d\n", he->v->data, he->next->v->data);
      pm->swap_edge(he);
      // pm->print4debug(K++);
      if(still_intersect) _list.push_back(he);
    }
    else
      _list.push_back(he);
  }
  return nbIntersection;
}

static PolyMesh::HalfEdge *Color(PolyMesh::HalfEdge *he, int color)
{
  std::stack<PolyMesh::Face *> _stack;
  _stack.push(he->f);

  PolyMesh::HalfEdge *other_side = nullptr;

  while(!_stack.empty()) {
    PolyMesh::Face *f = _stack.top();
    _stack.pop();
    f->data = color;
    he = f->he;
    for(int i = 0; i < 3; i++) {
      if(he->data == -1 && he->opposite != nullptr &&
         he->opposite->f->data == -1) {
        _stack.push(he->opposite->f);
      }
      else if(he->data != -1 && he->opposite != nullptr) {
        other_side = he->opposite;
      }
      he = he->next;
    }
  }
  return other_side;
}

void GFaceDelaunayRefinement(size_t faceTag)
{
  GFace *gf = GModel::current()->getFaceByTag(faceTag);

  PolyMesh *pm = GFaceInitialMesh(faceTag, 1);

  std::list<PolyMesh::HalfEdge *> _list;
  double _limit = 0.7;
  for(auto f : pm->faces) {
    double q = faceQuality(f->he, gf);
    if(q < _limit && f->data == gf->tag()) _list.push_back(f->he);
  }
  //  int I = 1;
  while(!_list.empty()) {
    PolyMesh::HalfEdge *he = *_list.begin();
    _list.erase(_list.begin());
    double q = faceQuality(he, gf);
    if(q < _limit) {
      double uv[2];
      SPoint3 cc;
      faceCircumCenter(he, gf, cc, uv);
      GPoint gp = gf->closestPoint(cc, uv);
      if(gp.succeeded()) {
        PolyMesh::Face *f = he->f;
        f = Walk(f, gp.u(), gp.v());
        if(f && f->data == (int)faceTag) {
          std::vector<PolyMesh::HalfEdge *> _touched;
          pm->split_triangle(-1, gp.u(), gp.v(), 0, f,
                             delaunayEdgeCriterionPlaneIsotropic, gf,
                             &_touched);
          if(_touched.size() == 3) {
            // we should unsplit ...
            // pm->undo_split(_touched);
          }
          else {
            std::vector<PolyMesh::Face *> _f;
            for(auto h : _touched)
              if(std::find(_f.begin(), _f.end(), h->f) == _f.end())
                _f.push_back(h->f);

            // printf("step %d %lu touched : ", I, _f.size());
            for(auto pf : _f) {
              q = faceQuality(pf->he, gf);
              // printf("%12.5E ", q);
              if(q < _limit && pf->data == gf->tag()) _list.push_back(pf->he);
            }
            // printf("\n");
          }
          // pm->print4debug(100000 + I++);
        }
      }
    }
  }
}

void GFaceDelaunayRefinementOldMesher(int faceTag)
{
  PolyMesh *pm = GFaceInitialMesh(faceTag);

  GFace *gf = GModel::current()->getFaceByTag(faceTag);

  // use old code ---

  for(auto f : pm->faces) {
    if(f->data == faceTag) {
      size_t n0 = f->he->v->data;
      size_t n1 = f->he->next->v->data;
      size_t n2 = f->he->next->next->v->data;
      MVertex *v0 = GModel::current()->getMeshVertexByTag(n0);
      MVertex *v1 = GModel::current()->getMeshVertexByTag(n1);
      MVertex *v2 = GModel::current()->getMeshVertexByTag(n2);
      gf->triangles.push_back(new MTriangle(v0, v1, v2));
    }
  }
  delete pm;
  // bowyerWatsonFrontal(gf);
}

struct nodeCopies {
  MVertex *mv;
  size_t nbCopies;
  double u[8], v[8]; // max 8 copies -- reduced to 4
  size_t id[8];
  nodeCopies(MVertex *_mv, double _u, double _v) : mv(_mv), nbCopies(1)
  {
    u[0] = _u;
    v[0] = _v;
  }
  void addCopy(double _u, double _v)
  {
    for(size_t i = 0; i < nbCopies; i++) {
      if(fabs(u[i] - _u) < 1.e-9 && fabs(v[i] - _v) < 1.e-9) return;
    }
    u[nbCopies] = _u;
    v[nbCopies] = _v;
    nbCopies++;
  }
  size_t closest(double _u, double _v)
  {
    double minD = 1.e22;
    size_t I = 0;
    for(size_t i = 0; i < nbCopies; i++) {
      double dist = sqrt((_u - u[i]) * (_u - u[i]) + (_v - v[i]) * (_v - v[i]));
      if(dist < minD) {
        minD = dist;
        I = i;
      }
    }
    return id[I];
  }
};

// INITIAL MESH --------- colored

static void getNodeCopies(GFace *gf,
                          std::unordered_map<size_t, nodeCopies> &copies)
{
  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> emb_edges = gf->getEmbeddedEdges();
  edges.insert(edges.end(), emb_edges.begin(), emb_edges.end());
  std::set<GEdge *> touched;

  if(edges.empty())
    edges.insert(edges.end(), gf->model()->firstEdge(),
                 gf->model()->lastEdge());

  for(auto e : edges) {
    if(!e->isMeshDegenerated()) {
      std::set<MVertex *, MVertexPtrLessThan> e_vertices;
      for(std::size_t i = 0; i < e->lines.size(); i++) {
        MVertex *v1 = e->lines[i]->getVertex(0);
        MVertex *v2 = e->lines[i]->getVertex(1);
        e_vertices.insert(v1);
        e_vertices.insert(v2);
      }
      int direction = -1;
      if(e->isSeam(gf)) {
        direction = 0;
        if(touched.find(e) == touched.end())
          touched.insert(e);
        else
          direction = 1;
      }
      // printf("model edge %lu %lu vertices\n", e->tag(), e_vertices.size());
      for(auto v : e_vertices) {
        SPoint2 param;
        if(direction != -1) {
          double t = 0;
          if(v->onWhat()->dim() == 0)
            reparamMeshVertexOnEdge(v, e, t);
          else if(v->onWhat()->dim() == 1)
            v->getParameter(0, t);
          else
            Msg::Error("a seam edge without CAD ?");
          param = e->reparamOnFace(gf, t, direction);
        }
        else {
          // Hmm...
          if(!gf->haveParametrization() &&
             gf->geomType() == GEntity::DiscreteSurface) {
            param = SPoint2(v->x(), v->y());
          }
          else
            reparamMeshVertexOnFace(v, gf, param);
        }
        std::unordered_map<size_t, nodeCopies>::iterator it =
          copies.find(v->getNum());
        if(it == copies.end()) {
          nodeCopies c(v, param.x(), param.y());
          copies.insert(std::make_pair(v->getNum(), c));
        }
        else {
          it->second.addCopy(param.x(), param.y());
        }
      }
    }
  }

  std::vector<GVertex *> emb_vertx = gf->getEmbeddedVertices();
  for(auto v : emb_vertx) {
    SPoint2 param;
    reparamMeshVertexOnFace(v->mesh_vertices[0], gf, param);
    nodeCopies c(v->mesh_vertices[0], param.x(), param.y());
    copies.insert(std::make_pair(v->mesh_vertices[0]->getNum(), c));
  }
}

void addPoints(PolyMesh *pm, std::vector<double> &pts, SBoundingBox3d &bb)
{
  const size_t N = pts.size() / 2;
  std::vector<double> X(N), Y(N);
  std::vector<size_t> HC(N), IND(N);
  PolyMesh::Face *f = pm->faces[0];
  for(size_t i = 0; i < N; i++) {
    X[i] = pts[2 * i];
    Y[i] = pts[2 * i + 1];
    HC[i] = HilbertCoordinates(X[i], Y[i], bb.center().x(), bb.center().y(),
                               bb.max().x() - bb.center().x(), 0, 0,
                               bb.max().y() - bb.center().y());
    IND[i] = i;
  }
  std::sort(IND.begin(), IND.end(),
            [&](size_t i, size_t j) { return HC[i] < HC[j]; });

  for(size_t i = 0; i < N; i++) {
    size_t I = IND[i];
    f = Walk(f, X[I], Y[I]);
    pm->split_triangle(i, X[I], Y[I], 0, f, delaunayEdgeCriterionPlaneIsotropic,
                       nullptr);
  }
}

PolyMesh *GFaceInitialMesh(int faceTag, int recover,
                           std::vector<double> *additional)
{
  GFace *gf = GModel::current()->getFaceByTag(faceTag);

  if(!gf) Msg::Error("GFaceInitialMesh: no face with tag %d", faceTag);

  PolyMesh *pm = new PolyMesh;

  std::unordered_map<size_t, nodeCopies> copies;
  getNodeCopies(gf, copies);

  SBoundingBox3d bb;
  for(auto c : copies) {
    for(size_t i = 0; i < c.second.nbCopies; i++)
      bb += SPoint3(c.second.u[i], c.second.v[i], 0);
  }
  bb *= 1.1;
  pm->initialize_rectangle(bb.min().x(), bb.max().x(), bb.min().y(),
                           bb.max().y());
  PolyMesh::Face *f = pm->faces[0];
  for(std::unordered_map<size_t, nodeCopies>::iterator it = copies.begin();
      it != copies.end(); ++it) {
    for(size_t i = 0; i < it->second.nbCopies; i++) {
      double x = it->second.u[i];
      double y = it->second.v[i];
      // find face in which lies x,y
      f = Walk(f, x, y);
      // split f and then swap edges to recover delaunayness
      pm->split_triangle(-1, x, y, 0, f, delaunayEdgeCriterionPlaneIsotropic,
                         nullptr);
      // remember node tags
      it->second.id[i] = pm->vertices.size() - 1;
      pm->vertices[pm->vertices.size() - 1]->data = it->first;
    }
  }

  //pm->print4debug(faceTag);

  if(recover) {
    std::vector<GEdge *> edges = gf->edges();
    std::vector<GEdge *> emb_edges = gf->getEmbeddedEdges();
    edges.insert(edges.end(), emb_edges.begin(), emb_edges.end());
    if(edges.empty())
      edges.insert(edges.end(), gf->model()->firstEdge(),
                   gf->model()->lastEdge());

    for(auto e : edges) {
      if(!e->isMeshDegenerated()) {
        for(auto l : e->lines) {
          auto c0 = copies.find(l->getVertex(0)->getNum());
          auto c1 = copies.find(l->getVertex(1)->getNum());
          if(c0 == copies.end() || c1 == copies.end())
            Msg::Error("unable to find %lu %lu %d %d",
                       l->getVertex(0)->getNum(), l->getVertex(1)->getNum(),
                       c0 == copies.end(), c1 == copies.end());
          if(c0->second.nbCopies > c1->second.nbCopies) {
            auto cc = c0;
            c0 = c1;
            c1 = cc;
          }
          for(size_t j = 0; j < c0->second.nbCopies; j++) {
            PolyMesh::Vertex *v0 = pm->vertices[c0->second.id[j]];
            PolyMesh::Vertex *v1 = pm->vertices[c1->second.closest(
              c0->second.u[j], c0->second.v[j])];
            int result = recover_edge(pm, v0, v1);
            if(result < 0) {
              Msg::Warning("Impossible to recover edge %lu %lu (error tag %d)",
                           l->getVertex(0)->getNum(), l->getVertex(0)->getNum(),
                           result);
            }
            else {
              PolyMesh::HalfEdge *he = pm->getEdge(v0, v1);
              if(he) {
                if(he->opposite) he->opposite->data = e->tag();
                he->data = e->tag();
              }
            }
          }
        }
      }
    }

    // color all PolyMesh::Faces
    // the first 4 vertices are "infinite vertices" --> color them with tag -2
    // meaning exterior
    PolyMesh::HalfEdge *other_side = Color(pm->vertices[0]->he, -2);
    // other_side is inthernal to the face --> color them with tag faceTag
    other_side = Color(other_side, faceTag);
    // holes will be tagged -1

    // flip edges that have been scrambled
    int iter = 0;
    while(iter++ < 100) {
      int count = 0;
      for(auto he : pm->hedges) {
        if(he->opposite && he->f->data == faceTag &&
           he->opposite->f->data == faceTag) {
          if(delaunayEdgeCriterionPlaneIsotropic(he, nullptr)) {
            if(intersect(he->v, he->next->v, he->next->next->v,
                         he->opposite->next->next->v)) {
              pm->swap_edge(he);
              count++;
            }
          }
        }
      }
      if(!count) break;
    }
  }

  if(additional) addPoints(pm, *additional, bb);

  return pm;
}

// -----------------------------------
// only on planar faces ...
int PolyMeshDelaunayize (int faceTag){

  PolyMesh *pm;
  GFace2PolyMesh(faceTag, &pm);

  for(auto ff : pm->faces)ff->data = faceTag;

  // flip edges that are not delaunay
  int iter = 0;
  while(iter++ < 100) {
    int count = 0;
    for(auto he : pm->hedges) {
      if(he->opposite && enhanceQuality(he, nullptr)) {
	if(intersect(he->v, he->next->v, he->next->next->v,
		     he->opposite->next->next->v)) {
	  pm->swap_edge(he);
	  count++;
	}
      }
    }
    if(!count) break;
  }
  PolyMesh2GFace(pm, faceTag);
  
  delete pm;
  return 0;
}
// -----------------------------------


