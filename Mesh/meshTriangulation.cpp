// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <utility>
#include <list>
#include <map>
#include <unordered_map>
#include "gmsh.h"
#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "MLine.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "meshTriangulation.h"
#include "SBoundingBox3d.h"
#include "robustPredicates.h"
#include "meshGFaceDelaunayInsertion.h"
#include "qualityMeasures.h"
#include "Numeric.h"

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

int GFace2PolyMesh(int faceTag, PolyMesh **pm)
{
  *pm = new PolyMesh;

  std::unordered_map<size_t, size_t> nodeLabels;

  {
    std::vector<std::size_t> nodeTags;
    std::vector<double> coord;
    std::vector<double> parametricCoord;
    gmsh::model::mesh::getNodes(nodeTags, coord, parametricCoord, 2, faceTag,
                                true, true);

    size_t j = 0;
    for(size_t i = 0; i < nodeTags.size(); i++, j += 2) {
      (*pm)->vertices.push_back(new PolyMesh::Vertex(
        parametricCoord[j], parametricCoord[j + 1], 0.0, nodeTags[i]));
      nodeLabels[nodeTags[i]] = i;
    }
  }

  {
    std::vector<int> elementTypes = {3};
    std::vector<std::vector<std::size_t> > elementTags;
    std::vector<std::vector<std::size_t> > nodeTags;
    gmsh::model::mesh::getElements(elementTypes, elementTags, nodeTags, 2,
                                   faceTag);
    std::unordered_map<std::pair<size_t, size_t>, PolyMesh::HalfEdge *,
                       pair_hash>
      opposites;

    for(size_t i = 0; i < nodeTags.size(); i += 3) {
      size_t currentHE = (*pm)->hedges.size();
      size_t currentF = (*pm)->faces.size();
      for(int j = 0; j < 3; j++)
        (*pm)->hedges.push_back(
          new PolyMesh::HalfEdge((*pm)->vertices[nodeTags[0][i + j]]));
      PolyMesh::HalfEdge *he0 = (*pm)->hedges[currentHE + 0];
      PolyMesh::HalfEdge *he1 = (*pm)->hedges[currentHE + 1];
      PolyMesh::HalfEdge *he2 = (*pm)->hedges[currentHE + 2];
      (*pm)->faces.push_back(new PolyMesh::Face(he0));
      he0->prev = he2;
      he0->next = he1;
      he1->prev = he0;
      he1->next = he2;
      he2->prev = he1;
      he2->next = he0;
      he0->v->he = he0;
      he1->v->he = he1;
      he2->v->he = he2;
      he0->f = (*pm)->faces[currentF];
      he1->f = (*pm)->faces[currentF];
      he2->f = (*pm)->faces[currentF];
      std::pair<size_t, size_t> p0 =
        std::make_pair(nodeTags[0][i + 1], nodeTags[0][i]);
      std::pair<size_t, size_t> p1 =
        std::make_pair(nodeTags[0][i + 2], nodeTags[0][i + 1]);
      std::pair<size_t, size_t> p2 =
        std::make_pair(nodeTags[0][i], nodeTags[0][i + 2]);
      auto it0 = opposites.find(p0);
      auto it1 = opposites.find(p1);
      auto it2 = opposites.find(p2);
      if(it0 == opposites.end()) {
        p0 = std::make_pair(nodeTags[0][i + 0], nodeTags[0][i + 1]);
        opposites[p0] = he0;
      }
      else {
        he0->opposite = it0->second;
        it0->second->opposite = he0;
      }

      if(it1 == opposites.end()) {
        p1 = std::make_pair(nodeTags[0][i + 1], nodeTags[0][i + 2]);
        opposites[p1] = he1;
      }
      else {
        he1->opposite = it1->second;
        it1->second->opposite = he1;
      }

      if(it2 == opposites.end()) {
        p2 = std::make_pair(nodeTags[0][i + 2], nodeTags[0][i]);
        opposites[p2] = he2;
      }
      else {
        he2->opposite = it2->second;
        it2->second->opposite = he2;
      }
    }
  }
  return 0;
}

static int delaunayEdgeCriterionPlaneIsotropic(PolyMesh::HalfEdge *he, void *)
{
  if(he->opposite == NULL) return -1;
  PolyMesh::Vertex *v0 = he->v;
  PolyMesh::Vertex *v1 = he->next->v;
  PolyMesh::Vertex *v2 = he->next->next->v;
  PolyMesh::Vertex *v = he->opposite->next->next->v;

  // FIXME : should be oriented anyway !
  double result = -robustPredicates::incircle(v0->position, v1->position,
                                              v2->position, v->position);

  return (result > 0) ? 1 : 0;
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
      /*      printf("Face %g %g %g / %g %g %g / %g %g %g \n",
         v0->position.x(), v0->position.y(), v0->position.z(),
         v1->position.x(), v1->position.y(), v1->position.z(),
         v2->position.x(), v2->position.y(), v2->position.z());
         printf("point %g %g CURRENT FACE %p %g %g %g\n", x,y,he->f,
         s0,s1,s2);*/
      //      getchar();
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
      printf("Face %g %g %g / %g %g %g / %g %g %g \n", v0->position.x(),
             v0->position.y(), v0->position.z(), v1->position.x(),
             v1->position.y(), v1->position.z(), v2->position.x(),
             v2->position.y(), v2->position.z());
      printf("ERROR point %g %g CURRENT FACE %p %g %g %g\n", x, y, he->f, s0,
             s1, s2);
    }
    if(he == NULL) break;
  }
  // should only come here wether the triangulated domain is not convex
  //  printf("NO FACE FOUND\n");
  return NULL;
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

int recover_edge(PolyMesh *pm, PolyMesh::Vertex *v_start,
                 PolyMesh::Vertex *v_end)
{
  PolyMesh::HalfEdge *he = v_start->he;
  std::list<PolyMesh::HalfEdge *> _list;

  //  printf("recovering edge %d %d\n",v_start->data,v_end->data);

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
      //      printf("INTERSECTION WITH %d %d\n",v1->data,v2->data);
      _list.push_back(he->next);
      break;
    }
    he = he->next->next->opposite;
  } while(he != v_start->he);

  if(_list.empty()) { return -1; }

  // -)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)-)
  // find all intersections
  while(1) {
    he = _list.back();
    he = he->opposite;
    if(!he) return -2;
    he = he->next;
    PolyMesh::Vertex *v1 = he->v;
    PolyMesh::Vertex *v2 = he->next->v;
    if(v2 == v_end) {
      //  printf("END FOUND %d\n",v2->data);
      break;
    }
    if(intersect(v_start, v_end, v1, v2)) {
      //      printf("INTESECTION %d %d\n",v1->data,v2->data);
      _list.push_back(he);
    }
    else {
      he = he->next;
      v1 = he->v;
      v2 = he->next->v;
      if(v2 == v_end) {
        //	printf("END FOUND %d\n",v2->data);
        break;
      }
      if(intersect(v_start, v_end, v1, v2)) {
        //	printf("INTESECTION %d %d\n",v1->data,v2->data);
        _list.push_back(he);
      }
      else {
        return -3;
      }
    }
  }

  int nbIntersection = _list.size();
  //  printf("%d intersections\n",nbIntersection);
  //  int K = 100;
  while(!_list.empty()) {
    he = *_list.begin();
    _list.erase(_list.begin());
    // ensure that swap is allowed (convex quad)
    if(intersect(he->v, he->next->v, he->next->next->v,
                 he->opposite->next->next->v)) {
      // ensure that swap removes one intersection
      int still_intersect = intersect(v_start, v_end, he->next->next->v,
                                      he->opposite->next->next->v);
      //      printf("swapping %d %d\n",he->v->data,he->next->v->data);
      pm->swap_edge(he);
      //      pm->print4debug(K++);
      if(still_intersect) _list.push_back(he);
    }
    else
      _list.push_back(he);
  }
  return nbIntersection;
}
//-------------------------------------------------------------------------------------

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
      if(he->data == -1 && he->opposite != NULL &&
         he->opposite->f->data == -1) {
        _stack.push(he->opposite->f);
      }
      else if(he->data != -1 && he->opposite != NULL) {
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
          pm->split_triangle(gp.u(), gp.v(), 0, f,
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

            //	    printf("step %d %lu touched : ",I,_f.size());
            for(auto pf : _f) {
              q = faceQuality(pf->he, gf);
              //	      printf("%12.5E ",q);
              if(q < _limit && pf->data == gf->tag()) _list.push_back(pf->he);
            }
            //	    printf("\n");
          }
          //	  pm->print4debug(100000+I++);
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
  //  bowyerWatsonFrontal(gf);
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

//// INITIAL MESH --------- colored

static void getNodeCopies(GFace *gf, std::map<size_t, nodeCopies> &copies)
{
  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> emb_edges = gf->getEmbeddedEdges();
  edges.insert(edges.end(), emb_edges.begin(), emb_edges.end());
  std::set<GEdge *> touched;

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
      //      printf("model edge %lu %lu
      //      vertices\n",e->tag(),e_vertices.size());
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
          reparamMeshVertexOnFace(v, gf, param);
        }
        std::map<size_t, nodeCopies>::iterator it = copies.find(v->getNum());
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

PolyMesh *GFaceInitialMesh(int faceTag, int recover)
{
  GFace *gf = GModel::current()->getFaceByTag(faceTag);

  PolyMesh *pm = new PolyMesh;

  std::map<size_t, nodeCopies> copies;
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
  for(std::map<size_t, nodeCopies>::iterator it = copies.begin();
      it != copies.end(); ++it) {
    for(size_t i = 0; i < it->second.nbCopies; i++) {
      double x = it->second.u[i];
      double y = it->second.v[i];
      // find face in which lies x,y
      f = Walk(f, x, y);
      // split f and then swap edges to recover delaunayness
      pm->split_triangle(x, y, 0, f, delaunayEdgeCriterionPlaneIsotropic, NULL);
      // remember node tags
      it->second.id[i] = pm->vertices.size() - 1;
      pm->vertices[pm->vertices.size() - 1]->data = it->first;
    }
  }

  if(!recover) return pm;

  // recover edges ...

  //  pm->print4debug(100000);

  std::vector<GEdge *> edges = gf->edges();
  std::vector<GEdge *> emb_edges = gf->getEmbeddedEdges();
  edges.insert(edges.end(), emb_edges.begin(), emb_edges.end());

  for(auto e : edges) {
    if(!e->isMeshDegenerated()) {
      for(auto l : e->lines) {
        auto c0 = copies.find(l->getVertex(0)->getNum());
        auto c1 = copies.find(l->getVertex(1)->getNum());
        if(c0 == copies.end() || c1 == copies.end())
          Msg::Error("unable to find %lu %lu %d %d", l->getVertex(0)->getNum(),
                     l->getVertex(1)->getNum(), c0 == copies.end(),
                     c1 == copies.end());
        if(c0->second.nbCopies > c1->second.nbCopies) {
          auto cc = c0;
          c0 = c1;
          c1 = cc;
        }
        for(size_t j = 0; j < c0->second.nbCopies; j++) {
          PolyMesh::Vertex *v0 = pm->vertices[c0->second.id[j]];
          PolyMesh::Vertex *v1 =
            pm->vertices[c1->second.closest(c0->second.u[j], c0->second.v[j])];
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

  //  pm->print4debug(200000);

  return pm;
}
//------------------------------------------------

#if 0
  bb *= 1./1.1;
  const size_t N = 100000;
  std::vector<double> X(N),Y(N);
  std::vector<size_t> HC(N), IND(N);
  for (size_t i = 0; i< N ; i++){
    double R = drand48();
    X[i] = bb.min().x() + R * (bb.max().x()-bb.min().x());
    R = drand48();
    Y[i] = bb.min().y() + R * (bb.max().y()-bb.min().y());
    HC[i] = HilbertCoordinates(X[i], Y[i], bb.center().x(), bb.center().y(),
			       bb.max().x() - bb.center().x(),0,
			       0, bb.max().y() - bb.center().y());
    IND[i] = i;
  }
  std::sort( IND.begin(),IND.end(), [&](size_t i,size_t j){return HC[i]<HC[j];} );
    double t1 = gmsh::logger::getCpuTime();
    for (size_t i = 0; i< N ; i++){
      size_t I = IND[i];
      f = Walk (f,X[I],Y[I]);
      pm->split_triangle(X[I],Y[I],0,f,delaunayEdgeCriterionPlaneIsotropic,NULL);
    }
    double t2 = gmsh::logger::getCpuTime();
    //    printf("%12.5E Seconds\n",t2-t1);
    pm->print4debug( nodeTags.size() );
}
#endif
#if 0
    PolyMesh::Vertex *v0 = pm->vertices[nodeLabels[1]];
    PolyMesh::Vertex *v1 = pm->vertices[nodeLabels[3]];
    int result = recover_edge (pm, v0, v1);
#endif
