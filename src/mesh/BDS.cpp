// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stack>
#include <cmath>
#include <stdio.h>

#include "GmshMessage.h"
#include "OS.h"
#include "robustPredicates.h"
#include "Numeric.h"
#include "BDS.h"
#include "GFace.h"
#include "discreteFace.h"
#include "meshGFaceDelaunayInsertion.h"
#include "Numeric.h"
#include "qualityMeasures.h"

static double _cos_N(BDS_Point *_p1, BDS_Point *_p2, BDS_Point *_p3, GFace *gf)
{
  double n[3];
  normal_triangle(_p1, _p2, _p3, n);
#if 0
  // average surface normal at 3 triangle nodes; bad for surface with high
  // curvature on small area, e.g. U-shaped near a boundary
  SVector3 N1 = gf->normal(SPoint2(_p1->u, _p1->v));
  SVector3 N2 = gf->normal(SPoint2(_p2->u, _p2->v));
  SVector3 N3 = gf->normal(SPoint2(_p3->u, _p3->v));
  SVector3 N = N1 + N2 + N3;
  N.normalize();
#else // surface normal at triangle barycenter
  double u = (_p1->u + _p2->u + _p3->u) / 3.;
  double v = (_p1->v + _p2->v + _p3->v) / 3.;
  SVector3 N = gf->normal(SPoint2(u, v));
#endif
  return N.x() * n[0] + N.y() * n[1] + N.z() * n[2];
}

double BDS_Face_Validity(GFace *gf, BDS_Face *f)
{
  BDS_Point *pts[4];
  if(!f->getNodes(pts)) return 0.;
  if((pts[0]->degenerated ? 1 : 0) + (pts[1]->degenerated ? 1 : 0) +
       (pts[2]->degenerated ? 1 : 0) <
     2) {
    double qa1 = qmTriangle::gamma(pts[0], pts[1], pts[2]);
    return qa1 * _cos_N(pts[0], pts[1], pts[2], gf);
  }
  return 1.0;
}

void outputScalarField(std::vector<BDS_Face *> &t, const char *iii, int param,
                       GFace *gf)
{
  Msg::Info("Writing debug file '%s'", iii);
  if(gf && 0) {
    FILE *view_c = Fopen("param_mesh_as_it_is_in_3D.pos", "w");
    if(!view_c) {
      Msg::Error("Could not open file 'param_mesh_as_it_is_in_3D.pos'");
      return;
    }
    fprintf(view_c, "View \"paramC\"{\n");
    auto tit = t.begin();
    auto tite = t.end();
    while(tit != tite) {
      BDS_Point *pts[4];
      if(!(*tit)->deleted && (*tit)->getNodes(pts)) {
        for(int j = 0; j < 3; j++) {
          double U1 =
            pts[j]->degenerated == 1 ? pts[(j + 1) % 3]->u : pts[j]->u;
          double U2 = pts[(j + 1) % 3]->degenerated == 1 ? pts[j]->u :
                                                           pts[(j + 1) % 3]->u;
          double V1 =
            pts[j]->degenerated == 2 ? pts[(j + 1) % 3]->v : pts[j]->v;
          double V2 = pts[(j + 1) % 3]->degenerated == 2 ? pts[j]->v :
                                                           pts[(j + 1) % 3]->v;
          SPoint2 p1(U1, V1);
          SPoint2 p2(U2, V2);
          SPoint2 prev = p1;
          for(int k = 1; k < 30; k++) {
            double t = (double)k / 29;
            SPoint2 p = p1 * (1. - t) + p2 * t;
            GPoint pa = gf->point(p.x(), p.y());
            GPoint pb = gf->point(prev.x(), prev.y());
            fprintf(view_c, "SL(%g,%g,%g,%g,%g,%g){1,1,1};\n", pa.x(), pa.y(),
                    pa.z(), pb.x(), pb.y(), pb.z());
            prev = p;
          }
        }
      }
      ++tit;
    }
    fprintf(view_c, "};\n");
    fclose(view_c);
  }

  FILE *f = Fopen(iii, "w");
  if(!f) {
    Msg::Error("Could not open file '%s'", iii);
    return;
  }
  fprintf(f, "View \"scalar\" {\n");
  auto tit = t.begin();
  auto tite = t.end();
  while(tit != tite) {
    BDS_Point *pts[4];
    if(!(*tit)->deleted && (*tit)->getNodes(pts)) {
      if(!param) {
        fprintf(f,
                "ST(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%"
                "22.15E,%22.15E){%g,%g,%g};\n",
                pts[0]->X, pts[0]->Y, pts[0]->Z, pts[1]->X, pts[1]->Y,
                pts[1]->Z, pts[2]->X, pts[2]->Y, pts[2]->Z, (double)pts[0]->iD,
                (double)pts[1]->iD, (double)pts[2]->iD);
      }
      if(param && gf) {
        // FIXME --- LOOK AT THE VALUE OG DEGENERATED
        if((pts[0]->degenerated ? 1 : 0) + (pts[1]->degenerated ? 1 : 0) +
             (pts[2]->degenerated ? 1 : 0) >
           1) {}
        else if(pts[0]->degenerated == 1)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[1]->u, pts[1]->v, 0.0, pts[2]->u, pts[2]->v, 0.0,
                  pts[2]->u, pts[0]->v, 0.0, pts[1]->u, pts[0]->v, 0.0,
                  (double)pts[1]->iD, (double)pts[2]->iD, (double)pts[0]->iD,
                  (double)pts[0]->iD);
        else if(pts[1]->degenerated == 1)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[2]->u, pts[2]->v, 0.0, pts[0]->u, pts[0]->v, 0.0,
                  pts[0]->u, pts[1]->v, 0.0, pts[2]->u, pts[1]->v, 0.0,
                  (double)pts[2]->iD, (double)pts[0]->iD, (double)pts[1]->iD,
                  (double)pts[1]->iD);
        else if(pts[2]->degenerated == 1)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[0]->u, pts[0]->v, 0.0, pts[1]->u, pts[1]->v, 0.0,
                  pts[1]->u, pts[2]->v, 0.0, pts[0]->u, pts[2]->v, 0.0,
                  (double)pts[0]->iD, (double)pts[1]->iD, (double)pts[2]->iD,
                  (double)pts[2]->iD);
        else if(pts[0]->degenerated == 2)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[1]->u, pts[1]->v, 0.0, pts[2]->u, pts[2]->v, 0.0,
                  pts[0]->u, pts[2]->v, 0.0, pts[0]->u, pts[1]->v, 0.0,
                  (double)pts[1]->iD, (double)pts[2]->iD, (double)pts[0]->iD,
                  (double)pts[0]->iD);
        else if(pts[1]->degenerated == 2)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[2]->u, pts[2]->v, 0.0, pts[0]->u, pts[0]->v, 0.0,
                  pts[1]->u, pts[0]->v, 0.0, pts[1]->u, pts[2]->v, 0.0,
                  (double)pts[2]->iD, (double)pts[0]->iD, (double)pts[1]->iD,
                  (double)pts[1]->iD);
        else if(pts[2]->degenerated == 2)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[0]->u, pts[0]->v, 0.0, pts[1]->u, pts[1]->v, 0.0,
                  pts[2]->u, pts[1]->v, 0.0, pts[2]->u, pts[0]->v, 0.0,
                  (double)pts[0]->iD, (double)pts[1]->iD, (double)pts[2]->iD,
                  (double)pts[2]->iD);
        else {
          fprintf(f,
                  "ST(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%"
                  "22.15E,%22.15E){%g,%g,%g};\n",
                  pts[0]->u, pts[0]->v, 0.0, pts[1]->u, pts[1]->v, 0.0,
                  pts[2]->u, pts[2]->v, 0.0, (double)pts[0]->iD,
                  (double)pts[1]->iD, (double)pts[2]->iD);
        }
      }
    }
    ++tit;
  }
  fprintf(f, "};\n");
  fclose(f);
}

static void vector_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3,
                            double c[3])
{
  double a[3] = {p1->X - p2->X, p1->Y - p2->Y, p1->Z - p2->Z};
  double b[3] = {p1->X - p3->X, p1->Y - p3->Y, p1->Z - p3->Z};
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

static double vector_triangle_parametric(BDS_Point *p1, BDS_Point *p2,
                                         BDS_Point *p3)
{
  double const a[2] = {p1->u - p2->u, p1->v - p2->v};
  double const b[2] = {p1->u - p3->u, p1->v - p3->v};
  return a[0] * b[1] - a[1] * b[0];
}

void normal_triangle(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3])
{
  vector_triangle(p1, p2, p3, c);
  norme(c);
}

static double surface_triangle_param(BDS_Point *p1, BDS_Point *p2,
                                     BDS_Point *p3)
{
  // FIXME
  // THIS ASSUMES DEGENERATED EDGES ALONG AXIS U !!!
  // SEEMS TO BE THE CASE WITH OCC

  if(!p1 || !p2 || !p3) {
    Msg::Error("Invalid point in parametric triangle surface computation");
    return 0;
  }

  double c;
  if((p1->degenerated ? 1 : 0) + (p2->degenerated ? 1 : 0) +
       (p3->degenerated ? 1 : 0) >
     1)
    c = 0; // vector_triangle_parametric(p1, p2, p3, c);
  else if(p1->degenerated == 1) {
    double du = fabs(p3->u - p2->u);
    c = 2 * fabs(0.5 * (p3->v + p2->v) - p1->v) * du;
  }
  else if(p2->degenerated == 1) {
    double du = fabs(p3->u - p1->u);
    c = 2 * fabs(0.5 * (p3->v + p1->v) - p2->v) * du;
  }
  else if(p3->degenerated == 1) {
    double du = fabs(p2->u - p1->u);
    c = 2 * fabs(0.5 * (p2->v + p1->v) - p3->v) * du;
  }
  else if(p1->degenerated == 2) {
    double dv = fabs(p3->v - p2->v);
    c = 2 * fabs(0.5 * (p3->u + p2->u) - p1->u) * dv;
  }
  else if(p2->degenerated == 2) {
    double dv = fabs(p3->v - p1->v);
    c = 2 * fabs(0.5 * (p3->u + p1->u) - p2->u) * dv;
  }
  else if(p3->degenerated == 2) {
    double dv = fabs(p2->v - p1->v);
    c = 2 * fabs(0.5 * (p2->u + p1->u) - p3->u) * dv;
  }
  else
    c = vector_triangle_parametric(p1, p2, p3);
  return (0.5 * c);
}

std::vector<BDS_Face *> BDS_Point::getTriangles() const
{
  std::vector<BDS_Face *> t;
  t.reserve(edges.size());

  auto it = edges.begin();
  while(it != edges.end()) {
    std::size_t const number_of_faces = (*it)->numfaces();

    for(std::size_t i = 0; i < number_of_faces; ++i) {
      BDS_Face *const tt = (*it)->faces(i);
      if(tt && std::find(t.begin(), t.end(), tt) == t.end()) {
        t.push_back(tt);
      }
    }
    ++it;
  }
  return t;
}

BDS_Point *BDS_Mesh::add_point(int const num, double const x, double const y,
                               double const z)
{
  BDS_Point *pp = new BDS_Point(num, x, y, z);
  points.insert(pp);
  MAXPOINTNUMBER = std::max(MAXPOINTNUMBER, num);
  return pp;
}

BDS_Point *BDS_Mesh::add_point(int num, double u, double v, GFace *gf)
{
  GPoint gp = gf->point(u, v);
  BDS_Point *pp = new BDS_Point(num, gp.x(), gp.y(), gp.z());
  pp->u = u;
  pp->v = v;
  points.insert(pp);
  MAXPOINTNUMBER = std::max(MAXPOINTNUMBER, num);
  return pp;
}

BDS_Point *BDS_Mesh::find_point(int p)
{
  BDS_Point P(p);
  auto it = points.find(&P);

  return it != points.end() ? static_cast<BDS_Point *>(*it) : nullptr;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p, int num2)
{
  auto eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if((*eit)->p1 == p && (*eit)->p2->iD == num2) return (*eit);
    if((*eit)->p2 == p && (*eit)->p1->iD == num2) return (*eit);
    ++eit;
  }
  return nullptr;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p1, BDS_Point *p2)
{
  return find_edge(p1, p2->iD);
}

BDS_Edge *BDS_Mesh::find_edge(int num1, int num2)
{
  BDS_Point *p = find_point(num1);
  return find_edge(p, num2);
}

int Intersect_Edges_2d(double x1, double y1, double x2, double y2, double x3,
                       double y3, double x4, double y4, double x[2])
{
  double mat[2][2];
  double rhs[2];
  mat[0][0] = (x2 - x1);
  mat[0][1] = -(x4 - x3);
  mat[1][0] = (y2 - y1);
  mat[1][1] = -(y4 - y3);
  rhs[0] = x3 - x1;
  rhs[1] = y3 - y1;
  if(!sys2x2(mat, rhs, x)) return 0;
  if(x[0] >= 0.0 && x[0] <= 1.0 && x[1] >= 0.0 && x[1] <= 1.0) return 1;
  return 0;
}

BDS_Edge *BDS_Mesh::recover_edge_fast(BDS_Point *p1, BDS_Point *p2)
{
  std::vector<BDS_Face *> ts = p1->getTriangles();

  auto it = ts.begin();
  while(it != ts.end()) {
    BDS_Face *t = *it;
    if(!t->e4) {
      BDS_Edge *e = t->oppositeEdge(p1);
      BDS_Face *f = e->otherFace(t);
      if(!f->e4) {
        BDS_Point *p2b = f->oppositeVertex(e);
        if(p2b && p2 == p2b) {
          if(swap_edge(e, BDS_SwapEdgeTestRecover(), true)) {
            return find_edge(p1, p2->iD);
          }
        }
      }
    }
    ++it;
  }
  return nullptr;
}

BDS_Edge *BDS_Mesh::recover_edge(int num1, int num2, bool &_fatal,
                                 std::set<EdgeToRecover> *e2r,
                                 std::set<EdgeToRecover> *not_recovered)
{
  BDS_Edge *e = find_edge(num1, num2);
  _fatal = false;

  if(e) return e;

  BDS_Point *p1 = find_point(num1);
  BDS_Point *p2 = find_point(num2);

  if(!p1 || !p2) {
    Msg::Error("Could not find points %d or %d in BDS mesh", num1, num2);
    return nullptr;
  }

  Msg::Debug("Edge %d %d has to be recovered", num1, num2);

  int ix = 0;
  double x[2];
  while(1) {
    std::vector<BDS_Edge *> intersected;

    bool selfIntersection = false;

    auto it = edges.begin();
    while(it != edges.end()) {
      e = (*it);
      if(!e->deleted && e->p1 != p1 && e->p1 != p2 && e->p2 != p1 &&
         e->p2 != p2)
        if(Intersect_Edges_2d(e->p1->u, e->p1->v, e->p2->u, e->p2->v, p1->u,
                              p1->v, p2->u, p2->v, x)) {
          // intersect
          if(e2r && e2r->find(EdgeToRecover(e->p1->iD, e->p2->iD, nullptr)) !=
                      e2r->end()) {
            auto itr1 = e2r->find(EdgeToRecover(e->p1->iD, e->p2->iD, nullptr));
            auto itr2 = e2r->find(EdgeToRecover(num1, num2, nullptr));
            Msg::Debug("edge %d %d on model edge %d cannot be recovered because"
                       " it intersects %d %d on model edge %d",
                       num1, num2, itr2->ge->tag(), e->p1->iD, e->p2->iD,
                       itr1->ge->tag());
            // now throw a class that contains the diagnostic
            not_recovered->insert(EdgeToRecover(num1, num2, itr2->ge));
            not_recovered->insert(
              EdgeToRecover(e->p1->iD, e->p2->iD, itr1->ge));
            selfIntersection = true;
          }
          if(e->numfaces() != e->numTriangles()) return nullptr;
          intersected.push_back(e);
        }
      ++it;
    }

    if(selfIntersection) return nullptr;

    if(!intersected.size() || ix > 300) {
      BDS_Edge *eee = find_edge(num1, num2);
      if(!eee) {
        if(Msg::GetVerbosity() > 98) {
          outputScalarField(triangles, "debugp.pos", 1);
          outputScalarField(triangles, "debugr.pos", 0);
          Msg::Debug(
            "edge %d %d cannot be recovered at all, look at debugp.pos "
            "and debugr.pos",
            num1, num2);
        }
        else {
          Msg::Debug("edge %d %d cannot be recovered at all", num1, num2);
        }
        _fatal = true;
        return nullptr;
      }
      return eee;
    }

    std::vector<int>::size_type ichoice = 0;
    bool success = false;
    while(!success && ichoice < intersected.size()) {
      success = swap_edge(intersected[ichoice++], BDS_SwapEdgeTestRecover());
    }

    if(!success) {
      Msg::Debug("edge %d %d cannot be recovered at all\n", num1, num2);
      _fatal = true;
      return nullptr;
    }

    ix++;
  }
  return nullptr;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p1, BDS_Point *p2, BDS_Face *t) const
{
  BDS_Point P1(p1->iD);
  BDS_Point P2(p2->iD);
  BDS_Edge E(&P1, &P2);
  if(t->e1->p1->iD == E.p1->iD && t->e1->p2->iD == E.p2->iD) return t->e1;
  if(t->e2->p1->iD == E.p1->iD && t->e2->p2->iD == E.p2->iD) return t->e2;
  if(t->e3->p1->iD == E.p1->iD && t->e3->p2->iD == E.p2->iD) return t->e3;
  return nullptr;
}

static bool is_equivalent(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3,
                          BDS_Edge *o1, BDS_Edge *o2, BDS_Edge *o3)
{
  return (o1 == e1 && o2 == e2 && o3 == e3) ||
         (o1 == e1 && o2 == e3 && o3 == e2) ||
         (o1 == e2 && o2 == e1 && o3 == e3) ||
         (o1 == e2 && o2 == e3 && o3 == e1) ||
         (o1 == e3 && o2 == e1 && o3 == e2) ||
         (o1 == e3 && o2 == e2 && o3 == e1);
}

BDS_Face *BDS_Mesh::find_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3)
{
  for(int i = 0; i < e1->numfaces(); i++) {
    BDS_Face *t = e1->faces(i);
    if(is_equivalent(e1, e2, e3, t->e1, t->e2, t->e3)) { return t; }
  }
  for(int i = 0; i < e2->numfaces(); i++) {
    BDS_Face *t = e2->faces(i);
    if(is_equivalent(e1, e2, e3, t->e1, t->e2, t->e3)) { return t; }
  }
  for(int i = 0; i < e3->numfaces(); i++) {
    BDS_Face *t = e3->faces(i);
    if(is_equivalent(e1, e2, e3, t->e1, t->e2, t->e3)) { return t; }
  }
  return nullptr;
}

BDS_Edge *BDS_Mesh::add_edge(int const p1, int const p2)
{
  BDS_Edge *efound = find_edge(p1, p2);
  if(efound) return efound;

  BDS_Point *pp1 = find_point(p1);
  BDS_Point *pp2 = find_point(p2);

  if(!pp1 || !pp2) {
    Msg::Error("Could not find points %d or %d", p1, p2);
    return nullptr;
  }
  edges.push_back(new BDS_Edge(pp1, pp2));

  return edges.back();
}

BDS_Face *BDS_Mesh::add_triangle(int p1, int p2, int p3)
{
  BDS_Edge *e1 = add_edge(p1, p2);
  BDS_Edge *e2 = add_edge(p2, p3);
  BDS_Edge *e3 = add_edge(p3, p1);
  if(e1 && e2 && e3) return add_triangle(e1, e2, e3);
  return nullptr;
}

BDS_Face *BDS_Mesh::add_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3)
{
  if(e1 && e2 && e3) {
    BDS_Face *t = new BDS_Face(e1, e2, e3);
    triangles.push_back(t);
    return t;
  }
  return nullptr;
}

void BDS_Mesh::del_face(BDS_Face *t)
{
  if(!t) return;
  t->e1->del(t);
  t->e2->del(t);
  t->e3->del(t);
  if(t->e4) t->e4->del(t);
  t->deleted = true;
}

void BDS_Mesh::del_edge(BDS_Edge *e)
{
  if(!e) return;
  e->p1->del(e);
  e->p2->del(e);
  e->deleted = true;
}

void BDS_Mesh::del_point(BDS_Point *p)
{
  if(!p) return;
  if(points.erase(p)) delete p;
}

void BDS_Mesh::add_geom(int p1, int p2)
{
  BDS_GeomEntity *e = new BDS_GeomEntity(p1, p2);
  auto res = geom.insert(e);
  if(!res.second) delete e;
}

void BDS_Edge::computeNeighborhood(BDS_Point *pts1[4], BDS_Point *pts2[4],
                                   BDS_Point *oface[2]) const
{
  oface[0] = oface[1] = nullptr;
  pts1[0] = pts1[1] = pts1[2] = pts1[3] = nullptr;
  pts2[0] = pts2[1] = pts2[2] = pts2[3] = nullptr;
  if(faces(0)) {
    if(!faces(0)->getNodes(pts1)) return;
    if(pts1[0] != p1 && pts1[0] != p2)
      oface[0] = pts1[0];
    else if(pts1[1] != p1 && pts1[1] != p2)
      oface[0] = pts1[1];
    else
      oface[0] = pts1[2];
  }
  if(faces(1)) {
    if(!faces(1)->getNodes(pts2)) return;
    if(pts2[0] != p1 && pts2[0] != p2)
      oface[1] = pts2[0];
    else if(pts2[1] != p1 && pts2[1] != p2)
      oface[1] = pts2[1];
    else
      oface[1] = pts2[2];
  }
}

void BDS_Edge::oppositeof(BDS_Point *oface[2]) const
{
  oface[0] = oface[1] = nullptr;
  if(faces(0)) {
    BDS_Point *pts[4];
    if(!faces(0)->getNodes(pts)) return;
    if(pts[0] != p1 && pts[0] != p2)
      oface[0] = pts[0];
    else if(pts[1] != p1 && pts[1] != p2)
      oface[0] = pts[1];
    else
      oface[0] = pts[2];
  }
  if(faces(1)) {
    BDS_Point *pts[4];
    if(!faces(1)->getNodes(pts)) return;
    if(pts[0] != p1 && pts[0] != p2)
      oface[1] = pts[0];
    else if(pts[1] != p1 && pts[1] != p2)
      oface[1] = pts[1];
    else
      oface[1] = pts[2];
  }
}

BDS_GeomEntity *BDS_Mesh::get_geom(int p1, int p2)
{
  BDS_GeomEntity ge(p1, p2);
  auto it = geom.find(&ge);
  if(it == geom.end()) return nullptr;
  return (BDS_GeomEntity *)(*it);
}

void recur_tag(BDS_Face *t, BDS_GeomEntity *g)
{
  std::stack<BDS_Face *> _stack;
  _stack.push(t);

  while(!_stack.empty()) {
    t = _stack.top();
    _stack.pop();
    if(!t->g) {
      t->g = g;
      if(!t->e1->g && t->e1->numfaces() == 2) {
        _stack.push(t->e1->otherFace(t));
      }
      if(!t->e2->g && t->e2->numfaces() == 2) {
        _stack.push(t->e2->otherFace(t));
      }
      if(!t->e3->g && t->e3->numfaces() == 2) {
        _stack.push(t->e3->otherFace(t));
      }
    }
  }
}

double PointLessThanLexicographic::t = 0;

template <class IT> void DESTROOOY(IT beg, IT end)
{
  while(beg != end) {
    delete *beg;
    beg++;
  }
}

struct is_not_deleted {
  template <class T> bool operator()(T *const face) { return !face->deleted; }
};

void BDS_Mesh::cleanup()
{
  {
    auto last =
      std::partition(triangles.begin(), triangles.end(), is_not_deleted());
    auto it = last;
    while(it != triangles.end()) {
      delete *it;
      ++it;
    }
    triangles.erase(last, triangles.end());
  }
  {
    auto last = std::partition(edges.begin(), edges.end(), is_not_deleted());
    auto it = last;
    while(it != edges.end()) {
      delete *it;
      ++it;
    }
    edges.erase(last, edges.end());
  }
}

BDS_Mesh::~BDS_Mesh()
{
  DESTROOOY(geom.begin(), geom.end());
  DESTROOOY(points.begin(), points.end());
  cleanup();
  DESTROOOY(edges.begin(), edges.end());
  DESTROOOY(triangles.begin(), triangles.end());
}

bool BDS_Mesh::split_edge(BDS_Edge *e, BDS_Point *mid, bool check_area_param)
{
  /*
        p1
      / | \
     /  |  \
 op1/ 0mid1 \op2
    \   |   /
     \  |  /
      \ p2/

     //  p1,op1,mid -
     //  p2,op2,mid -
     //  p2,op1,mid +
     //  p1,op2,mid +
  */

  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;

  e->oppositeof(op);
  if(!op[0] || !op[1]) return false;

  const int CHECK1 = -1, CHECK2 = -1;

  if(p1->iD == CHECK1 && p2->iD == CHECK2)
    printf("splitting edge %d %d opp %d %d new %d\n", p1->iD, p2->iD, op[0]->iD,
           op[1]->iD, mid->iD);
  if(check_area_param) {
    double area0 = fabs(surface_triangle_param(p2, p1, op[0])) +
                   fabs(surface_triangle_param(p2, p1, op[1]));
    double area1 = fabs(surface_triangle_param(mid, p1, op[1])) +
                   fabs(surface_triangle_param(mid, op[1], p2)) +
                   fabs(surface_triangle_param(mid, p2, op[0])) +
                   fabs(surface_triangle_param(mid, op[0], p1));
    // heuristic - abort if area changed too much
    if(area1 > 1.1 * area0 || area1 < 0.9 * area0) { return false; }
  }

  if(p1->iD == CHECK1 && p2->iD == CHECK2)
    printf("%d %d %d %d\n", p1->iD, p2->iD, op[0]->iD, op[1]->iD);

  BDS_Point *pts1[4];
  if(!e->faces(0)->getNodes(pts1)) return false;

  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      orientation = pts1[(i + 1) % 3] == p2 ? 1 : -1;
      break;
    }
  }

  BDS_GeomEntity *g1 = nullptr, *g2 = nullptr, *ge = e->g;

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  if(e->faces(0)) {
    g1 = e->faces(0)->g;
    del_face(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    g2 = e->faces(0)->g;
    del_face(e->faces(0));
  }

  del_edge(e);

  BDS_Edge *p1_mid = new BDS_Edge(p1, mid);
  edges.push_back(p1_mid);
  BDS_Edge *mid_p2 = new BDS_Edge(mid, p2);
  edges.push_back(mid_p2);
  BDS_Edge *op1_mid = new BDS_Edge(op[0], mid);
  edges.push_back(op1_mid);
  BDS_Edge *mid_op2 = new BDS_Edge(mid, op[1]);
  edges.push_back(mid_op2);

  BDS_Face *t1, *t2, *t3, *t4;
  if(orientation == 1) {
    t1 = new BDS_Face(op1_mid, p1_op1, p1_mid);
    t2 = new BDS_Face(mid_op2, op2_p2, mid_p2);
    t3 = new BDS_Face(op1_p2, op1_mid, mid_p2);
    t4 = new BDS_Face(p1_op2, mid_op2, p1_mid);
  }
  else {
    t1 = new BDS_Face(p1_op1, op1_mid, p1_mid);
    t2 = new BDS_Face(op2_p2, mid_op2, mid_p2);
    t3 = new BDS_Face(op1_mid, op1_p2, mid_p2);
    t4 = new BDS_Face(mid_op2, p1_op2, p1_mid);
  }
  t1->g = g1;
  t2->g = g2;
  t3->g = g1;
  t4->g = g2;

  p1_mid->g = ge;
  mid_p2->g = ge;
  op1_mid->g = g1;
  mid_op2->g = g2;

  mid->g = ge;

  triangles.push_back(t1);
  triangles.push_back(t2);
  triangles.push_back(t3);
  triangles.push_back(t4);

  return true;
  // config has changed
  p1->config_modified = true;
  p2->config_modified = true;
  op[0]->config_modified = true;
  op[1]->config_modified = true;
  return true;
}

bool BDS_SwapEdgeTestRecover::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_q1, BDS_Point *_q2) const
{
  double p1[2] = {_p1->u, _p1->v};
  double p2[2] = {_p2->u, _p2->v};
  double op1[2] = {_q1->u, _q1->v};
  double op2[2] = {_q2->u, _q2->v};

  double ori_t1 = robustPredicates::orient2d(op1, p1, op2);
  double ori_t2 = robustPredicates::orient2d(op1, op2, p2);

  return (ori_t1 * ori_t2 > 0); // the quadrangle was strictly convex !
}

bool BDS_SwapEdgeTestRecover::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_p3, BDS_Point *_q1,
                                         BDS_Point *_q2, BDS_Point *_q3,
                                         BDS_Point *_op1, BDS_Point *_op2,
                                         BDS_Point *_op3, BDS_Point *_oq1,
                                         BDS_Point *_oq2, BDS_Point *_oq3) const
{
  return true;
}

// This function does actually the swap without taking into account
// the feasability of the operation. Those conditions have to be
// taken into account before doing the edge swap

bool BDS_SwapEdgeTestQuality::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_q1, BDS_Point *_q2) const
{
  if(!testSmallTriangles) return true;

  // AVOID CREATING POINTS WITH 2 NEIGHBORING TRIANGLES
  //  std::vector<BDS_Face*> f1 = p1->getTriangles();
  //  std::vector<BDS_Face*> f2 = p2->getTriangles();
  if(_p1->g && _p1->g->classif_degree == 2 && _p1->edges.size() <= 4)
    return false;
  if(_p2->g && _p2->g->classif_degree == 2 && _p2->edges.size() <= 4)
    return false;
  if(_p1->g && _p1->g->classif_degree < 2 && _p1->edges.size() <= 3)
    return false;
  if(_p2->g && _p2->g->classif_degree < 2 && _p2->edges.size() <= 3)
    return false;

  double s1 = fabs(surface_triangle_param(_p1, _p2, _q1));
  double s2 = fabs(surface_triangle_param(_p1, _p2, _q2));
  double s3 = fabs(surface_triangle_param(_p1, _q1, _q2));
  double s4 = fabs(surface_triangle_param(_p2, _q1, _q2));
  if(fabs(s1 + s2 - s3 - s4) > 1.e-12 * (s3 + s4)) { return false; }

  return true;
}

bool BDS_SwapEdgeTestQuality::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_p3, BDS_Point *_q1,
                                         BDS_Point *_q2, BDS_Point *_q3,
                                         BDS_Point *_op1, BDS_Point *_op2,
                                         BDS_Point *_op3, BDS_Point *_oq1,
                                         BDS_Point *_oq2, BDS_Point *_oq3) const
{
  // Check if new edge is not on a seam or degenerated
  BDS_Point *p1 = nullptr, *p2 = nullptr;
  if(_op1 != _oq1 && _op1 != _oq2 && _op1 != _oq3) {
    p1 = _op2;
    p2 = _op3;
  }
  else if(_op2 != _oq1 && _op2 != _oq2 && _op2 != _oq3) {
    p1 = _op1;
    p2 = _op3;
  }
  else if(_op3 != _oq1 && _op3 != _oq2 && _op3 != _oq3) {
    p1 = _op1;
    p2 = _op2;
  }
  else {
    Msg::Warning("Unable to detect the new edge in BDS_SwapEdgeTestQuality\n");
  }

  if(p1 && p2) {
    if(p1->degenerated && p2->degenerated) return false;
    if(p1->_periodicCounterpart && p2->_periodicCounterpart) return false;
  }

  if(!testQuality) return true;

  double qa1 = qmTriangle::gamma(_p1, _p2, _p3);
  double qa2 = qmTriangle::gamma(_q1, _q2, _q3);
  double qb1 = qmTriangle::gamma(_op1, _op2, _op3);
  double qb2 = qmTriangle::gamma(_oq1, _oq2, _oq3);

  // we swap for a better configuration
  double const mina = std::min(qa1, qa2);
  double const minb = std::min(qb1, qb2);

  return minb > mina;
}

bool BDS_SwapEdgeTestNormals::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_q1, BDS_Point *_q2) const
{
  double s1 = fabs(surface_triangle_param(_p1, _p2, _q1));
  double s2 = fabs(surface_triangle_param(_p1, _p2, _q2));
  double s3 = fabs(surface_triangle_param(_p1, _q1, _q2));
  double s4 = fabs(surface_triangle_param(_p2, _q1, _q2));
  if(fabs(s1 + s2 - s3 - s4) > 1.e-12 * (s3 + s4)) { return false; }
  return true;
}

bool BDS_SwapEdgeTestNormals::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_p3, BDS_Point *_q1,
                                         BDS_Point *_q2, BDS_Point *_q3,
                                         BDS_Point *_op1, BDS_Point *_op2,
                                         BDS_Point *_op3, BDS_Point *_oq1,
                                         BDS_Point *_oq2, BDS_Point *_oq3) const
{
  double qa1 = qmTriangle::gamma(_p1, _p2, _p3);
  double qa2 = qmTriangle::gamma(_q1, _q2, _q3);
  double qb1 = qmTriangle::gamma(_op1, _op2, _op3);
  double qb2 = qmTriangle::gamma(_oq1, _oq2, _oq3);

  double OLD = std::min(_ori * qa1 * _cos_N(_p1, _p2, _p3, gf),
                        _ori * qa2 * _cos_N(_q1, _q2, _q3, gf));

  double NEW = std::min(_ori * qb1 * _cos_N(_op1, _op2, _op3, gf),
                        _ori * qb2 * _cos_N(_oq1, _oq2, _oq3, gf));

  if(OLD < 0.5 && OLD < NEW) return true;
  return false;
}

bool BDS_Mesh::swap_edge(BDS_Edge *e, const BDS_SwapEdgeTest &theTest,
                         bool force)
{
  /*
        p1
      / | \
     /  |  \
 op1/ 0 | 1 \op2
    \   |   /
     \  |  /
      \ p2/

     // op1 p1 op2
     // op1 op2 p2
   */

  // we test if the edge is deleted
  // return false;

  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;

  if(e->deleted) return false;

  int nbFaces = e->numfaces();
  if(nbFaces != 2) return false;

  if(e->g && e->g->classif_degree == 1) return false;

  const int CHECK1 = -1, CHECK2 = -1;

  BDS_Point *op[2];
  BDS_Point *pts1[4];
  BDS_Point *pts2[4];
  e->computeNeighborhood(pts1, pts2, op);
  if(!op[0] || !op[1]) return false;

  if(p1->iD == CHECK1 && p2->iD == CHECK2) {
    printf("- e %d %d --> %d %d\n", p1->iD, p2->iD, op[0]->iD, op[1]->iD);
    printf("-  %d %d %d\n", pts1[0]->iD, pts1[1]->iD, pts1[2]->iD);
    printf("-  %d %d %d\n", pts2[0]->iD, pts2[1]->iD, pts2[2]->iD);
  }

  if(!force && !p1->config_modified && !p2->config_modified &&
     !op[0]->config_modified && !op[1]->config_modified)
    return false;

  if(p1->iD == CHECK1 && p2->iD == CHECK2) printf("topology OK \n");

  BDS_GeomEntity *g1 = nullptr, *g2 = nullptr, *ge = e->g;

  // compute the orientation of the face
  // with respect to the edge
  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      orientation = pts1[(i + 1) % 3] == p2 ? 1 : -1;
      break;
    }
  }

  if(orientation == 1) {
    if(!theTest(p1, p2, op[0], p2, p1, op[1], p1, op[1], op[0], op[1], p2,
                op[0]))
      return false;
  }
  else {
    if(!theTest(p2, p1, op[0], p1, p2, op[1], p1, op[0], op[1], op[1], op[0],
                p2))
      return false;
  }

  if(p1->iD == CHECK1 && p2->iD == CHECK2) printf("TEST1 OK\n");

  if(!theTest(p1, p2, op[0], op[1])) return false;

  if(p1->iD == CHECK1 && p2->iD == CHECK2) printf("TEST2 OK\n");

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  // degenerate
  if(p1_op1 == p1_op2 || op2_p2 == op1_p2) return false;

  if(e->faces(0)) {
    g1 = e->faces(0)->g;
    del_face(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    g2 = e->faces(0)->g;
    del_face(e->faces(0));
  }
  del_edge(e);

  edges.push_back(new BDS_Edge(op[0], op[1]));

  BDS_Face *t1, *t2;
  if(orientation == 1) {
    t1 = new BDS_Face(p1_op1, p1_op2, edges.back());
    t2 = new BDS_Face(edges.back(), op2_p2, op1_p2);
  }
  else {
    t1 = new BDS_Face(p1_op2, p1_op1, edges.back());
    t2 = new BDS_Face(op2_p2, edges.back(), op1_p2);
  }

  t1->g = g1;
  t2->g = g2;

  edges.back()->g = ge;

  triangles.push_back(t1);
  triangles.push_back(t2);

  p1->config_modified = true;
  p2->config_modified = true;
  op[0]->config_modified = true;
  op[1]->config_modified = true;

  return true;
}

int BDS_Edge::numTriangles() const
{
  return std::count_if(
    begin(_faces), end(_faces),
    [](const BDS_Face *const face) { return face->numEdges() == 3; });
}

/*
  VERTICES C AND D LOSE ONE EDGE !!
  AS IF TWO EDGE SWAPS WERE DONE

  OTHER GAIN EDGES --> NO SOUCI

           C------B
         /  \    / \
        /    \  /    \
       /      \/      \
       x-------A-------D
        \      /\     /
          \  /    \ /
            x-------x
 */

bool BDS_Mesh::collapse_edge_parametric(BDS_Edge *e, BDS_Point *p, bool force)
{
  if(!force && e->numfaces() != 2) return false;
  if(!force && p->g && p->g->classif_degree == 0) return false;
  // not really ok but 'til now this is the best choice not to do collapses on
  // model edges
  if(!force && p->g && p->g->classif_degree == 1) return false;
  if(!force && e->g && p->g) {
    if(e->g->classif_degree == 2 && p->g != e->g) return false;
  }

  const int CHECK1 = -1, CHECK2 = -1;

  if(e->p1->iD == CHECK1 && e->p2->iD == CHECK2) {
    printf("collapsing edge %p %p onto %p\n", (void*)e->p1, (void*)e->p2,
           (void*)p);
    printf("collapsing edge %d %d onto %d\n", e->p1->iD, e->p2->iD, p->iD);
  }

  if(!force) {
    for(size_t i = 0; i < e->p1->edges.size(); i++) {
      for(size_t j = 0; j < e->p2->edges.size(); j++) {
        BDS_Point *p1 = e->p1->edges[i]->p1 == e->p1 ? e->p1->edges[i]->p2 :
                                                       e->p1->edges[i]->p1;
        BDS_Point *p2 = e->p2->edges[j]->p1 == e->p2 ? e->p2->edges[j]->p2 :
                                                       e->p2->edges[j]->p1;
        if(p1->_periodicCounterpart == p2) return false;
      }
    }
  }

  if(e->numfaces() == 2) {
    BDS_Point *oface[2];
    e->oppositeof(oface);
    if(!oface[0] || !oface[1]) {
      Msg::Error("No opposite face in edge collapse");
      return false;
    }
    for(size_t i = 0; i < oface[0]->edges.size(); i++) {
      if(oface[0]->edges[i]->p1 == oface[0] &&
         oface[0]->edges[i]->p2 == oface[1])
        return false;
      if(oface[0]->edges[i]->p1 == oface[1] &&
         oface[0]->edges[i]->p2 == oface[0])
        return false;
    }
    if(!force && oface[0]->g && oface[0]->g->classif_degree == 2 &&
       oface[0]->edges.size() <= 4)
      return false;
    if(!force && oface[1]->g && oface[1]->g->classif_degree == 2 &&
       oface[1]->edges.size() <= 4)
      return false;
    if(!force && oface[0]->g && oface[0]->g->classif_degree < 2 &&
       oface[0]->edges.size() <= 3)
      return false;
    if(!force && oface[1]->g && oface[1]->g->classif_degree < 2 &&
       oface[1]->edges.size() <= 3)
      return false;
  }
  std::vector<BDS_Face *> t = p->getTriangles();
  BDS_Point *o = e->othervertex(p);

  BDS_Point *pt[3][1024];
  BDS_GeomEntity *gs[1024];
  int ept[2][1024];
  BDS_GeomEntity *egs[1024];
  int nt = 0;
  double area_old = 0.0;
  double area_new = 0.0;
  {
    auto it = t.begin();
    while(it != t.end()) {
      BDS_Face *t = *it;
      BDS_Point *pts[4];
      if(t->getNodes(pts)) {
        double sold = std::abs(surface_triangle_param(pts[0], pts[1], pts[2]));
        area_old += sold;
        if(t->e1 != e && t->e2 != e && t->e3 != e) {
          gs[nt] = t->g;
          pt[0][nt] = (pts[0] == p) ? o : pts[0];
          pt[1][nt] = (pts[1] == p) ? o : pts[1];
          pt[2][nt] = (pts[2] == p) ? o : pts[2];
          if(!pt[0][nt] || !pt[1][nt] || !pt[2][nt]) {
            Msg::Error("Invalid point in edge collapse");
            return false;
          }
          double snew =
            std::abs(surface_triangle_param(pt[0][nt], pt[1][nt], pt[2][nt]));
          if(!force && snew < .02 * sold) { return false; }
          area_new += snew;
          ++nt;
        }
      }
      ++it;
    }
  }

  // if(!force && nt == 2) return false;

  if(!force && fabs(area_old - area_new) > 1.e-12 * (area_old + area_new)) {
    // printf("%g %g\n", fabs(area_old - area_new), 1.e-12 * (area_old +
    // area_new));
    return false;
  }
  {
    auto it = t.begin();
    while(it != t.end()) {
      del_face(*it);
      ++it;
    }
  }

  int kk = 0;
  {
    std::vector<BDS_Edge *> edges(p->edges);
    auto eit = edges.begin();
    while(eit != edges.end()) {
      (*eit)->p1->config_modified = (*eit)->p2->config_modified = true;
      ept[0][kk] = ((*eit)->p1 == p) ? (o ? o->iD : -1) : (*eit)->p1->iD;
      ept[1][kk] = ((*eit)->p2 == p) ? (o ? o->iD : -1) : (*eit)->p2->iD;
      if(ept[0][kk] < 0 || ept[1][kk] < 0) {
        Msg::Error("Something wrong in edge collapse");
        return false;
      }
      egs[kk++] = (*eit)->g;
      del_edge(*eit);
      ++eit;
    }
  }

  // FIXME
  // del_point(p);

  {
    for(int k = 0; k < nt; k++) {
      BDS_Face *t = add_triangle(pt[0][k]->iD, pt[1][k]->iD, pt[2][k]->iD);
      t->g = gs[k];
    }
  }

  for(int i = 0; i < kk; ++i) {
    BDS_Edge *e = find_edge(ept[0][i], ept[1][i]);
    if(e && !e->g) e->g = egs[i];
  }

  return true;
}

// Tutte's simple smoothing
// other implementations are coming

static inline bool validityOfCavity(const BDS_Point *p,
                                    const std::vector<BDS_Point *> &nbg)
{
  double p_[2] = {p->u, p->v};
  double q_[2] = {nbg[0]->degenerated == 1 ? nbg[1]->u : nbg[0]->u,
                  nbg[0]->degenerated == 2 ? nbg[1]->v : nbg[0]->v};
  double r_[2] = {nbg[1]->degenerated == 1 ? nbg[0]->u : nbg[1]->u,
                  nbg[1]->degenerated == 2 ? nbg[0]->v : nbg[1]->v};
  double sign = robustPredicates::orient2d(p_, q_, r_);
  for(size_t i = 1; i < nbg.size(); ++i) {
    BDS_Point *p0 = nbg[i];
    BDS_Point *p1 = nbg[(i + 1) % nbg.size()];
    double qq_[2] = {p0->degenerated == 1 ? p1->u : p0->u,
                     p0->degenerated == 2 ? p1->v : p0->v};
    double rr_[2] = {p1->degenerated == 1 ? p0->u : p1->u,
                     p1->degenerated == 2 ? p0->v : p1->v};
    double sign_ = robustPredicates::orient2d(p_, qq_, rr_);
    if(sign * sign_ <= 0) return false;
  }
  return true;
}

static inline bool getOrderedNeighboringVertices(BDS_Point *p,
                                                 std::vector<BDS_Point *> &nbg,
                                                 std::vector<BDS_Face *> &ts,
                                                 int CHECK)
{
  if(p->iD == CHECK) {
    printf("LISTING THE TRIANGLES\n");
    for(size_t i = 0; i < ts.size(); i++) {
      BDS_Point *pts[4];
      if(ts[i]->getNodes(pts)) {
        printf("TR %lu : %p %p %p\n", i, (void*)pts[0], (void*)pts[1],
               (void*)pts[2]);
        printf("TR %lu : %d %d - %d %d - %d %d\n", i, ts[i]->e1->p1->iD,
               ts[i]->e1->p2->iD, ts[i]->e2->p1->iD, ts[i]->e2->p2->iD,
               ts[i]->e3->p1->iD, ts[i]->e3->p2->iD);
      }
    }
  }

  if(ts.empty()) return false;
  while(1) {
    bool found = false;
    for(size_t i = 0; i < ts.size(); i++) {
      BDS_Point *pts[4];
      if(!ts[i]->getNodes(pts)) continue;
      BDS_Point *pp[2];
      if(pts[0] == p) {
        pp[0] = pts[1];
        pp[1] = pts[2];
      }
      else if(pts[1] == p) {
        pp[0] = pts[0];
        pp[1] = pts[2];
      }
      else {
        pp[0] = pts[0];
        pp[1] = pts[1];
      }
      if(nbg.empty()) {
        nbg.push_back(pp[0]);
        nbg.push_back(pp[1]);
        found = true;
        break;
      }
      else {
        BDS_Point *p0 = nbg[nbg.size() - 2];
        BDS_Point *p1 = nbg[nbg.size() - 1];
        if(p1 == pp[0] && p0 != pp[1]) {
          nbg.push_back(pp[1]);
          found = true;
          break;
        }
        else if(p1 == pp[1] && p0 != pp[0]) {
          nbg.push_back(pp[0]);
          found = true;
          break;
        }
      }
    }

    if(nbg.size() == ts.size()) break;
    if(!found) return false;
  }

  if(p->iD == CHECK) {
    printf("FINALLY : ");
    for(size_t i = 0; i < nbg.size(); i++) { printf("%d ", nbg[i]->iD); }
    printf("\n");
  }
  return true;
}

static inline double getTutteEnergy(const BDS_Point *p,
                                    const std::vector<BDS_Point *> &nbg,
                                    double &RATIO)
{
  if(nbg.empty()) return 1.e22;
  double E = 0;
  double MAX = 0., MIN = 0.;
  for(size_t i = 0; i < nbg.size(); ++i) {
    const double dx = p->X - nbg[i]->X;
    const double dy = p->Y - nbg[i]->Y;
    const double dz = p->Z - nbg[i]->Z;
    const double l2 = dx * dx + dy * dy + dz * dz;
    MAX = i ? std::max(MAX, l2) : l2;
    MIN = i ? std::min(MIN, l2) : l2;
    E += l2;
  }
  if(!MAX) return 1.e22;
  RATIO = MIN / MAX;
  return E;
}

static inline void getCentroidUV(const BDS_Point *p, GFace *gf,
                                 const std::vector<SPoint2> &kernel,
                                 const std::vector<double> &lc, double &U,
                                 double &V, double &LC)
{
  U = V = LC = 0.;
  double factSum = 0;
  for(size_t i = 0; i < kernel.size(); ++i) {
    GPoint gp = gf->point(kernel[i]);
    double du = p->u - gp.u();
    double dv = p->v - gp.v();
    double denom = (du * du + dv * dv);
    if(denom) {
      double dx = p->X - gp.x();
      double dy = p->Y - gp.y();
      double dz = p->Z - gp.z();
      double fact = sqrt((dx * dx + dy * dy + dz * dz) / denom);
      factSum += fact;
      U += kernel[i].x() * fact;
      V += kernel[i].y() * fact;
      LC += lc[i] * fact;
    }
  }
  if(factSum) {
    U /= factSum;
    V /= factSum;
    LC /= factSum;
  }
}

static inline void getCentroidUV(const std::vector<SPoint2> &kernel,
                                 const std::vector<double> &lc, double &U,
                                 double &V, double &LC)
{
  U = V = LC = 0.;
  for(size_t i = 0; i < kernel.size(); ++i) {
    U += kernel[i].x();
    V += kernel[i].y();
    LC += lc[i];
  }
  U /= kernel.size();
  V /= kernel.size();
  LC /= kernel.size();
}

static inline void getIntersection(const SPoint2 &p1, const SPoint2 &p2,
                                   const SPoint2 &q1, const SPoint2 &q2,
                                   double x[2])
{
  double A[2][2];
  A[0][0] = p2.x() - p1.x();
  A[0][1] = q1.x() - q2.x();
  A[1][0] = p2.y() - p1.y();
  A[1][1] = q1.y() - q2.y();
  double b[2] = {q1.x() - p1.x(), q1.y() - p1.y()};
  sys2x2(A, b, x);
}

static inline void computeSomeKindOfKernel(const BDS_Point *p,
                                           const std::vector<BDS_Point *> &nbg,
                                           std::vector<SPoint2> &kernel,
                                           std::vector<double> &lc, int check)
{
  FILE *f = nullptr;
  if(p->iD == check) f = fopen("kernel.pos", "w");

  SPoint2 pp(p->u, p->v);
  if(p->iD == check) {
    fprintf(f, "View \"kernel\"{\n");
    fprintf(f, "SP(%g,%g,0){2};\n", p->u, p->v);
  }

  double ll = p->lc();
  kernel.clear();
  lc.clear();
  for(size_t i = 0; i < nbg.size(); i++) {
    if(nbg[i]->degenerated == 1) {
      kernel.push_back(SPoint2(p->u, nbg[i]->v));
      kernel.push_back(SPoint2(nbg[(i + 1) % nbg.size()]->u, nbg[i]->v));

      lc.push_back(nbg[i]->lc());
      lc.push_back(nbg[i]->lc());
    }
    else if(nbg[i]->degenerated == 2) {
      kernel.push_back(SPoint2(nbg[i]->u, p->v));
      kernel.push_back(SPoint2(nbg[i]->u, nbg[(i + 1) % nbg.size()]->v));

      lc.push_back(nbg[i]->lc());
      lc.push_back(nbg[i]->lc());
    }
    else if(nbg[(i + 1) % nbg.size()]->degenerated == 1) {
      kernel.push_back(SPoint2(nbg[i]->u, nbg[i]->v));
      kernel.push_back(SPoint2(nbg[i]->u, nbg[(i + 1) % nbg.size()]->v));
      lc.push_back(nbg[i]->lc());
      lc.push_back(nbg[i]->lc());
    }
    else if(nbg[(i + 1) % nbg.size()]->degenerated == 2) {
      kernel.push_back(SPoint2(nbg[i]->u, nbg[i]->v));
      kernel.push_back(SPoint2(nbg[(i + 1) % nbg.size()]->u, nbg[i]->v));
      lc.push_back(nbg[i]->lc());
      lc.push_back(nbg[i]->lc());
    }
    else {
      kernel.push_back(SPoint2(nbg[i]->u, nbg[i]->v));
      lc.push_back(nbg[i]->lc());
    }
  }
  // return;
  if(p->iD == check) {
    for(size_t i = 0; i < kernel.size(); i++) {
      fprintf(f, "SL(%g,%g,0,%g,%g,0){4,4};\n", kernel[i].x(), kernel[i].y(),
              kernel[(i + 1) % kernel.size()].x(),
              kernel[(i + 1) % kernel.size()].y());
    }
  }

  //  bool changed = false;
  // we should compute the true kernel
  for(size_t i = 0; i < kernel.size(); i++) {
    SPoint2 p_now = kernel[i];
    double lc_now = lc[i];
    for(size_t j = 0; j < kernel.size(); j++) {
      if(i != j && i != (j + 1) % kernel.size()) {
        const SPoint2 &p0 = kernel[j];
        const SPoint2 &p1 = kernel[(j + 1) % kernel.size()];
        double x[2];
        getIntersection(pp, p_now, p0, p1, x);
        if(x[0] > 0 && x[0] < 1.0) {
          p_now = (pp * (1. - x[0])) + (p_now * x[0]);
          lc_now = ll * (1. - x[0]) + lc_now * x[0];
          //	  changed = true;
        }
      }
    }
    kernel[i] = p_now;
    lc[i] = lc_now;
  }

  if(p->iD == check) {
    fprintf(f, "};\n");
    fclose(f);
  }
  // if (changed)getchar();
}

static GPoint _closestPoint(BDS_Point *p, GFace *gf,
                            const std::vector<SPoint2> &kernel, SPoint3 &target,
                            int N)
{
  double minDist = 1.e22;
  SPoint2 p0(p->u, p->v);
  SPoint2 pMin = p0;
  for(size_t i = 0; i < kernel.size(); ++i) {
    SPoint2 p1(kernel[i].x(), kernel[i].y());
    SPoint2 p2(kernel[(i + 1) % kernel.size()].x(),
               kernel[(i + 1) % kernel.size()].y());
    for(int j = 1; j < N; j++) {
      for(int k = 1; k < N - j; k++) {
        double xi = (double)j / (2 * N);
        double eta = (double)k / (2 * N);
        SPoint2 p = p0 * (1 - xi - eta) + p1 * xi + p2 * eta;
        GPoint gp = gf->point(p);
        double d = ((target.x() - gp.x()) * (target.x() - gp.x()) +
                    (target.y() - gp.y()) * (target.y() - gp.y()) +
                    (target.z() - gp.z()) * (target.z() - gp.z()));
        if(d < minDist) {
          pMin = p;
          minDist = d;
        }
      }
    }
  }

  return gf->point(pMin);
}

static inline bool minimizeTutteEnergyProj(BDS_Point *p, double E_unmoved,
                                           double RATIO,
                                           const std::vector<BDS_Point *> &nbg,
                                           const std::vector<SPoint2> &kernel,
                                           const std::vector<double> &lc,
                                           GFace *gf, int check)
{
  SPoint3 x;
  double oldX = p->X, oldY = p->Y, oldZ = p->Z, oldU = p->u, oldV = p->v;
  double sum = 0;
  SPoint3 p0(oldX, oldY, oldZ);
  for(size_t i = 0; i < nbg.size(); ++i) {
    SPoint3 pi(nbg[i]->X, nbg[i]->Y, nbg[i]->Z);
    SPoint3 pip(nbg[(i + 1) % nbg.size()]->X, nbg[(i + 1) % nbg.size()]->Y,
                nbg[(i + 1) % nbg.size()]->Z);
    SVector3 v1 = pi - p0;
    SVector3 v2 = pip - p0;
    SVector3 pv = crossprod(v1, v2);
    double nrm = pv.norm();
    x += (pi + p0 + pip) * (nrm / 3.0);
    sum += nrm;
  }
  x /= sum;
  if(p->iD == check) printf("%12.5E %12.5E %12.5E\n", x.x(), x.y(), x.z());
  GPoint gp;
  if(gf->geomType() == GEntity::BSplineSurface ||
     gf->geomType() == GEntity::BezierSurface ||
     gf->geomType() == GEntity::Unknown) {
    gp = _closestPoint(p, gf, kernel, x, 5);
  }
  else {
    double U, V, LC;
    getCentroidUV(kernel, lc, U, V, LC);
    double uv[2] = {U, V};
    gp = gf->closestPoint(x, uv);
  }
  p->u = gp.u();
  p->v = gp.v();
  if(p->iD == check) {
    printf("%g %g %d\n", p->u, p->v, validityOfCavity(p, nbg));
  }

  if(validityOfCavity(p, nbg)) {
    p->X = gp.x();
    p->Y = gp.y();
    p->Z = gp.z();
    double E_moved = getTutteEnergy(p, nbg, RATIO);
    if(E_moved < E_unmoved) { return true; }
  }

  p->X = oldX;
  p->Y = oldY;
  p->Z = oldZ;
  p->u = oldU;
  p->v = oldV;
  if(p->iD == check) printf("NO WAY\n");
  return false;
}

static inline bool minimizeTutteEnergyParam(BDS_Point *p, double E_unmoved,
                                            double RATIO1,
                                            const std::vector<BDS_Point *> &nbg,
                                            const std::vector<SPoint2> &kernel,
                                            const std::vector<double> &lc,
                                            GFace *gf, int check)
{
  double U, V, LC, oldX = p->X, oldY = p->Y, oldZ = p->Z, oldU = p->u,
                   oldV = p->v;
  double RATIO2 = 0;
  getCentroidUV(p, gf, kernel, lc, U, V, LC);
  GPoint gp = gf->point(U, V);
  if(!gp.succeeded()) return false;
  p->X = gp.x();
  p->Y = gp.y();
  p->Z = gp.z();
  double E_moved = getTutteEnergy(p, nbg, RATIO2);

  if(p->iD == check) printf("%g vs %g\n", E_unmoved, E_moved);

  if(E_moved < E_unmoved) {
    p->u = U;
    p->v = V;
    if(!validityOfCavity(p, nbg)) {
      p->X = oldX;
      p->Y = oldY;
      p->Z = oldZ;
      p->u = oldU;
      p->v = oldV;
      return false;
    }
    p->lc() = LC;
    return RATIO2 > .25;
  }
  p->X = oldX;
  p->Y = oldY;
  p->Z = oldZ;
  return false;
}

bool BDS_Mesh::smooth_point_centroid(BDS_Point *p, GFace *gf, double threshold)
{
  if(p->degenerated) return false;
  if(p->g && p->g->classif_degree <= 1) return false;
  if(p->g && p->g->classif_tag < 0) {
    p->config_modified = true;
    return true;
  }

  int CHECK = -1;

  if(p->iD == CHECK)
    printf("VERTEX %d TRYING TO MOVE from its initial position %g %g\n", CHECK,
           p->u, p->v);

  std::vector<BDS_Point *> nbg;
  std::vector<double> lc;
  std::vector<SPoint2> kernel;
  std::vector<BDS_Face *> ts = p->getTriangles();

  if(p->iD == CHECK) printf("%d adjacent triangles\n", (int)ts.size());

  if(!getOrderedNeighboringVertices(p, nbg, ts, CHECK)) return false;

  if(p->iD == CHECK) printf("%d adjacent vertices\n", (int)nbg.size());

  double RATIO = 0;
  double E_unmoved = getTutteEnergy(p, nbg, RATIO);
  if(RATIO > threshold) return false;

  computeSomeKindOfKernel(p, nbg, kernel, lc, CHECK);

  if(!minimizeTutteEnergyParam(p, E_unmoved, RATIO, nbg, kernel, lc, gf,
                               CHECK)) {
    if(!minimizeTutteEnergyProj(p, E_unmoved, RATIO, nbg, kernel, lc, gf,
                                CHECK)) {
      return false;
    }
    else {
      p->config_modified = true;
      E_unmoved = getTutteEnergy(p, nbg, RATIO);
      minimizeTutteEnergyProj(p, E_unmoved, RATIO, nbg, kernel, lc, gf, CHECK);
    }
  }
  else {
    p->config_modified = true;
  }

  return true;
}
