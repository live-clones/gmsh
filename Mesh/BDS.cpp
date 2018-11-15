// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

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
#include "qualityMeasures.h"

double _COS_N(BDS_Point *_p1, BDS_Point *_p2, BDS_Point *_p3, GFace *gf)
{
  double n[3];
  normal_triangle(_p1, _p2, _p3, n);
  SVector3 N1 = gf->normal(SPoint2(_p1->u, _p1->v));
  SVector3 N2 = gf->normal(SPoint2(_p2->u, _p2->v));
  SVector3 N3 = gf->normal(SPoint2(_p3->u, _p3->v));
  SVector3 N = N1 + N2 + N3;
  N.normalize();
  return N.x() * n[0] + N.y() * n[1] + N.z() * n[2];
}

double BDS_Face_Validity(GFace *gf, BDS_Face *f)
{
  //  if (gf->model()->//  return 1;
  BDS_Point *pts[4];
  f->getNodes(pts);
  if(pts[0]->degenerated + pts[1]->degenerated + pts[2]->degenerated < 2) {
    double qa1 = qmTriangle::gamma(pts[0], pts[1], pts[2]);
    return qa1 * _COS_N(pts[0], pts[1], pts[2], gf);
  }
  return 1.0;
}

void outputScalarField(std::vector<BDS_Face *> &t, const char *iii, int param,
                       GFace *gf)
{
  if(gf) {
    FILE *view_c = Fopen("param_mesh_as_it_is_in_3D.pos", "w");
    if(!view_c) {
      Msg::Error("Could not open file param_mesh_as_it_is_in_3D.pos");
      return;
    }
    fprintf(view_c, "View \"paramC\"{\n");
    std::vector<BDS_Face *>::iterator tit = t.begin();
    std::vector<BDS_Face *>::iterator tite = t.end();
    while(tit != tite) {
      BDS_Point *pts[4];
      if(!(*tit)->deleted) {
        (*tit)->getNodes(pts);
        for(int j = 0; j < 3; j++) {
          double U1 = pts[j]->degenerated ? pts[(j + 1) % 3]->u : pts[j]->u;
          double U2 =
            pts[(j + 1) % 3]->degenerated ? pts[j]->u : pts[(j + 1) % 3]->u;
          SPoint2 p1(U1, pts[j]->v);
          SPoint2 p2(U2, pts[(j + 1) % 3]->v);
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
  std::vector<BDS_Face *>::iterator tit = t.begin();
  std::vector<BDS_Face *>::iterator tite = t.end();
  while(tit != tite) {
    BDS_Point *pts[4];
    if(!(*tit)->deleted) {
      (*tit)->getNodes(pts);
      // double v = BDS_Face_Validity (gf, *tit);
      if(!param && gf) {
        if(pts[0]->degenerated + pts[1]->degenerated + pts[2]->degenerated <
           2) {
          fprintf(f,
                  "ST(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%"
                  "22.15E,%22.15E){%g,%g,%g};\n",
                  pts[0]->X, pts[0]->Y, pts[0]->Z, pts[1]->X, pts[1]->Y,
                  pts[1]->Z, pts[2]->X, pts[2]->Y, pts[2]->Z,
                  (double)pts[0]->iD, (double)pts[1]->iD, (double)pts[2]->iD);
        }
      }
      if(param && gf) {
        if(pts[0]->degenerated + pts[1]->degenerated + pts[2]->degenerated >
           1) {
        }
        else if(pts[0]->degenerated)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[1]->u, pts[1]->v, 0.0, pts[2]->u, pts[2]->v, 0.0,
                  pts[2]->u, pts[0]->v, 0.0, pts[1]->u, pts[0]->v, 0.0,
                  //		  v,v,v,v);
                  (double)pts[1]->iD, (double)pts[2]->iD, (double)pts[0]->iD,
                  (double)pts[0]->iD);
        else if(pts[1]->degenerated)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[2]->u, pts[2]->v, 0.0, pts[0]->u, pts[0]->v, 0.0,
                  pts[0]->u, pts[1]->v, 0.0, pts[2]->u, pts[1]->v, 0.0,
                  // v,v,v,v);
                  (double)pts[2]->iD, (double)pts[0]->iD, (double)pts[1]->iD,
                  (double)pts[1]->iD);
        else if(pts[2]->degenerated)
          fprintf(f, "SQ(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g};\n",
                  pts[0]->u, pts[0]->v, 0.0, pts[1]->u, pts[1]->v, 0.0,
                  pts[1]->u, pts[2]->v, 0.0, pts[0]->u, pts[2]->v, 0.0,
                  // v,v,v,v);
                  (double)pts[0]->iD, (double)pts[1]->iD, (double)pts[2]->iD,
                  (double)pts[2]->iD);
        else {
          fprintf(f,
                  "ST(%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%22.15E,%"
                  "22.15E,%22.15E){%g,%g,%g};\n",
                  pts[0]->u, pts[0]->v, 0.0, pts[1]->u, pts[1]->v, 0.0,
                  pts[2]->u, pts[2]->v, 0.0,
                  //		    v,v,v);
                  (double)pts[0]->iD, (double)pts[1]->iD, (double)pts[2]->iD);
        }
      }
    }
    ++tit;
  }
  fprintf(f, "};\n");
  fclose(f);
}

BDS_Vector::BDS_Vector(const BDS_Point &p2, const BDS_Point &p1)
  : x(p2.X - p1.X), y(p2.Y - p1.Y), z(p2.Z - p1.Z)
{
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

double surface_triangle_param(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3)
{
  // FIXME
  // THIS ASSUMES DEGENERATED EDGES ALONG AXIS U !!!
  // SEEMS TO BE THE CASE WITH OCC

  double c;
  if(p1->degenerated + p2->degenerated + p3->degenerated > 1)
    c = 0; // vector_triangle_parametric(p1, p2, p3, c);
  else if(p1->degenerated) {
    double du = fabs(p3->u - p2->u);
    c = 2 * fabs(0.5 * (p3->v + p2->v) - p1->v) * du;
  }
  else if(p2->degenerated) {
    double du = fabs(p3->u - p1->u);
    c = 2 * fabs(0.5 * (p3->v + p1->v) - p2->v) * du;
  }
  else if(p3->degenerated) {
    double du = fabs(p2->u - p1->u);
    c = 2 * fabs(0.5 * (p2->v + p1->v) - p3->v) * du;
  }
  else
    c = vector_triangle_parametric(p1, p2, p3);
  return (0.5 * c);
}

std::vector<BDS_Face *> BDS_Point::getTriangles() const
{
  std::vector<BDS_Face *> t;
  t.reserve(edges.size());

  std::vector<BDS_Edge *>::const_iterator it = edges.begin();
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
  std::set<BDS_Point *, PointLessThan>::iterator it = points.find(&P);

  return it != points.end() ? static_cast<BDS_Point *>(*it) : NULL;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p, int num2)
{
  std::vector<BDS_Edge *>::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if((*eit)->p1 == p && (*eit)->p2->iD == num2) return (*eit);
    if((*eit)->p2 == p && (*eit)->p1->iD == num2) return (*eit);
    ++eit;
  }
  return 0;
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
  //   double p1[2] = {x1,y1};
  //   double p2[2] = {x2,y2};
  //   double q1[2] = {x3,y3};
  //   double q2[2] = {x4,y4};

  //   double rp1 = robustPredicates::orient2d(p1, p2, q1);
  //   double rp2 = robustPredicates::orient2d(p1, p2, q2);
  //   double rq1 = robustPredicates::orient2d(q1, q2, p1);
  //   double rq2 = robustPredicates::orient2d(q1, q2, p2);

  //   if(rp1*rp2<=0 && rq1*rq2<=0){
  // //      printf("p1 %22.15E %22.15E %22.15E %22.15E \n",x1,y1,x2,y2);
  // //      printf("p2 %22.15E %22.15E %22.15E %22.15E \n",x3,y3,x4,y4);
  // //      printf("or %22.15E %22.15E %22.15E %22.15E\n",rp1,rp2,rq1,rq2);
  //     return 1;
  //   }
  //   return 0;

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

  std::vector<BDS_Face *>::const_iterator it = ts.begin();
  while(it != ts.end()) {
    BDS_Face *t = *it;
    if(!t->e4) {
      BDS_Edge *e = t->oppositeEdge(p1);
      BDS_Face *f = e->otherFace(t);
      if(!f->e4) {
        BDS_Point *p2b = f->oppositeVertex(e);
        if(p2 == p2b) {
          if(swap_edge(e, BDS_SwapEdgeTestRecover(), true)) {
            return find_edge(p1, p2->iD);
          }
        }
      }
    }
    ++it;
  }
  return 0;
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
    Msg::Fatal("Could not find points %d or %d in BDS mesh", num1, num2);
    return 0;
  }

  Msg::Debug("edge %d %d has to be recovered", num1, num2);

  int ix = 0;
  double x[2];
  while(1) {
    std::vector<BDS_Edge *> intersected;

    bool selfIntersection = false;

    std::vector<BDS_Edge *>::const_iterator it = edges.begin();
    while(it != edges.end()) {
      e = (*it);
      if(!e->deleted && e->p1 != p1 && e->p1 != p2 && e->p2 != p1 &&
         e->p2 != p2)
        if(Intersect_Edges_2d(e->p1->u, e->p1->v, e->p2->u, e->p2->v, p1->u,
                              p1->v, p2->u, p2->v, x)) {
          // intersect
          if(e2r &&
             e2r->find(EdgeToRecover(e->p1->iD, e->p2->iD, 0)) != e2r->end()) {
            std::set<EdgeToRecover>::iterator itr1 =
              e2r->find(EdgeToRecover(e->p1->iD, e->p2->iD, 0));
            std::set<EdgeToRecover>::iterator itr2 =
              e2r->find(EdgeToRecover(num1, num2, 0));
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
          if(e->numfaces() != e->numTriangles()) return 0;
          intersected.push_back(e);
        }
      ++it;
    }

    if(selfIntersection) return 0;

    // if(ix > 300){
    //   Msg::Warning("edge %d %d cannot be recovered after %d iterations,
    //   trying again",
    //      num1, num2, ix);
    //   ix = 0;
    // }
    // printf("%d %d\n",intersected.size(),ix);

    //    printf("%d intersected\n",intersected.size());

    if(!intersected.size() || ix > 100000) {
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
        return 0;
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
      return 0;
    }

    ix++;
  }
  return 0;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point *p1, BDS_Point *p2, BDS_Face *t) const
{
  BDS_Point P1(p1->iD);
  BDS_Point P2(p2->iD);
  BDS_Edge E(&P1, &P2);
  if(t->e1->p1->iD == E.p1->iD && t->e1->p2->iD == E.p2->iD) return t->e1;
  if(t->e2->p1->iD == E.p1->iD && t->e2->p2->iD == E.p2->iD) return t->e2;
  if(t->e3->p1->iD == E.p1->iD && t->e3->p2->iD == E.p2->iD) return t->e3;
  return 0;
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
    if(is_equivalent(e1, e2, e3, t->e1, t->e2, t->e3)) {
      return t;
    }
  }
  for(int i = 0; i < e2->numfaces(); i++) {
    BDS_Face *t = e2->faces(i);
    if(is_equivalent(e1, e2, e3, t->e1, t->e2, t->e3)) {
      return t;
    }
  }
  for(int i = 0; i < e3->numfaces(); i++) {
    BDS_Face *t = e3->faces(i);
    if(is_equivalent(e1, e2, e3, t->e1, t->e2, t->e3)) {
      return t;
    }
  }
  return 0;
}

BDS_Edge *BDS_Mesh::add_edge(int const p1, int const p2)
{
  BDS_Edge *efound = find_edge(p1, p2);
  if(efound) return efound;

  BDS_Point *pp1 = find_point(p1);
  BDS_Point *pp2 = find_point(p2);

  if(!pp1 || !pp2) {
    Msg::Fatal("Could not find points %d or %d in BDS mesh", p1, p2);
    return 0;
  }
  edges.push_back(new BDS_Edge(pp1, pp2));

  return edges.back();
}

BDS_Face *BDS_Mesh::add_triangle(int p1, int p2, int p3)
{
  BDS_Edge *e1 = add_edge(p1, p2);
  BDS_Edge *e2 = add_edge(p2, p3);
  BDS_Edge *e3 = add_edge(p3, p1);
  return add_triangle(e1, e2, e3);
}

BDS_Face *BDS_Mesh::add_triangle(BDS_Edge *e1, BDS_Edge *e2, BDS_Edge *e3)
{
  // BDS_Face *tfound = find_triangle(e1, e2, e3);
  // if(tfound) return tfound;

  BDS_Face *t = new BDS_Face(e1, e2, e3);
  triangles.push_back(t);
  return t;
}

void BDS_Mesh::del_face(BDS_Face *t)
{
  t->e1->del(t);
  t->e2->del(t);
  t->e3->del(t);
  if(t->e4) t->e4->del(t);
  t->deleted = true;
}

void BDS_Mesh::del_edge(BDS_Edge *e)
{
  e->p1->del(e);
  e->p2->del(e);
  e->deleted = true;
}

void BDS_Mesh::del_point(BDS_Point *p)
{
  points.erase(p);
  delete p;
}

void BDS_Mesh::add_geom(int p1, int p2)
{
  geom.insert(new BDS_GeomEntity(p1, p2));
}

void BDS_Edge::computeNeighborhood(BDS_Point *pts1[4], BDS_Point *pts2[4],
                                   BDS_Point *oface[2]) const
{
  oface[0] = oface[1] = 0;
  if(faces(0)) {
    faces(0)->getNodes(pts1);
    if(pts1[0] != p1 && pts1[0] != p2)
      oface[0] = pts1[0];
    else if(pts1[1] != p1 && pts1[1] != p2)
      oface[0] = pts1[1];
    else
      oface[0] = pts1[2];
  }
  if(faces(1)) {
    faces(1)->getNodes(pts2);
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
  // FIXME !!!!!!!!!!!!

  oface[0] = oface[1] = 0;
  if(faces(0)) {
    BDS_Point *pts[4];
    faces(0)->getNodes(pts);
    if(pts[0] != p1 && pts[0] != p2)
      oface[0] = pts[0];
    else if(pts[1] != p1 && pts[1] != p2)
      oface[0] = pts[1];
    else
      oface[0] = pts[2];
  }
  if(faces(1)) {
    BDS_Point *pts[4];
    faces(1)->getNodes(pts);
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
  std::set<BDS_GeomEntity *, GeomLessThan>::iterator it = geom.find(&ge);
  if(it == geom.end()) return 0;
  return (BDS_GeomEntity *)(*it);
}

void recur_tag(BDS_Face *t, BDS_GeomEntity *g)
{
  std::stack<BDS_Face *> _stack;
  _stack.push(t);

  //  BDS_Point *pts[4];
  //  t->getNodes(pts);
  //  printf("starting with trioangle %d %d %d\n",pts[0]->iD,pts[1]->iD,pts[2]->iD);

  while(!_stack.empty()) {
    t = _stack.top();
    _stack.pop();
    if(!t->g) {
      //      t->getNodes(pts);
      //      printf("now in trioangle %d %d %d\n",pts[0]->iD,pts[1]->iD,pts[2]->iD);
      t->g = g;
      // g->t.push_back(t);
      if(!t->e1->g && t->e1->numfaces() == 2) {
	//	printf("going through %d %d\n",t->e1->p1->iD,t->e1->p2->iD);
        _stack.push(t->e1->otherFace(t));
        //	recur_tag(t->e1->otherFace(t), g);
      }
      if(!t->e2->g && t->e2->numfaces() == 2) {
	//	printf("going through %d %d\n",t->e2->p1->iD,t->e2->p2->iD);
        _stack.push(t->e2->otherFace(t));
        //	recur_tag(t->e2->otherFace(t), g);
      }
      if(!t->e3->g && t->e3->numfaces() == 2) {
	//	printf("going through %d %d\n",t->e3->p1->iD,t->e3->p2->iD);
        _stack.push(t->e3->otherFace(t));
        //	recur_tag(t->e3->otherFace(t), g);
      }
    }
  }
}

double PointLessThanLexicographic::t = 0;
double BDS_Vector::t = 0;

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
    std::vector<BDS_Face *>::iterator last =
      std::partition(triangles.begin(), triangles.end(), is_not_deleted());
    std::vector<BDS_Face *>::iterator it = last;
    while(it != triangles.end()) {
      delete *it;
      ++it;
    }
    triangles.erase(last, triangles.end());
  }
  {
    std::vector<BDS_Edge *>::iterator last =
      std::partition(edges.begin(), edges.end(), is_not_deleted());
    std::vector<BDS_Edge *>::iterator it = last;
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

bool BDS_Mesh::split_edge(BDS_Edge *e, BDS_Point *mid)
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

  int CHECK1 = -1, CHECK2 = 46;

  if(p1->iD == CHECK1 && p2->iD == CHECK2)
    printf("splitting edge %d %d opp %d %d new %d\n", p1->iD, p2->iD, op[0]->iD, op[1]->iD,mid->iD);

  double ori0 = fabs(surface_triangle_param(p2, p1, op[0])) +
                fabs(surface_triangle_param(p2, p1, op[1]));
  double ori1 = fabs(surface_triangle_param(mid, p1, op[1]));
  double ori2 = fabs(surface_triangle_param(mid, op[1], p2));
  double ori3 = fabs(surface_triangle_param(mid, p2, op[0]));
  double ori4 = fabs(surface_triangle_param(mid, op[0], p1));

  double eps = 1.e-2;
  if(ori1 < eps * ori0 || ori2 < eps * ori0 || ori3 < eps * ori0 ||
     ori4 < eps * ori0) {
    //    printf("%g %g %g %g %g\n",ori0,ori1,ori2,ori3,ori4);
    //    return false;
  }

  if(p1->iD == CHECK1 && p2->iD == CHECK2)
    printf("coucou 2 %d %d %d %d\n", p1->iD, p2->iD, op[0]->iD, op[1]->iD);

  BDS_Point *pts1[4];
  e->faces(0)->getNodes(pts1);

  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      orientation = pts1[(i + 1) % 3] == p2 ? 1 : -1;
      break;
    }
  }

  BDS_GeomEntity *g1 = 0, *g2 = 0, *ge = e->g;

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

  //  double t_l = e->target_length;

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
  if(fabs(s1 + s2 - s3 - s4) > 1.e-12 * (s3 + s4)) {
    return false;
  }
  // THIS WAS CAUSIN' TROUBLES ...
  //if(s3 < .02 * (s1 + s2) || s4 < .02 * (s1 + s2)) return false;

  /*
  if(!testSmallTriangles) {
    double p1[2] = {_p1->u, _p1->v};
    double p2[2] = {_p2->u, _p2->v};
    double op1[2] = {_q1->u, _q1->v};
    double op2[2] = {_q2->u, _q2->v};

    double ori_t1 = robustPredicates::orient2d(op1, p1, op2);
    double ori_t2 = robustPredicates::orient2d(op1, op2, p2);

    // printf("%d %d %d %d %g
    // %g\n",_p1->iD,_p2->iD,_q1->iD,_q2->iD,ori_t1,ori_t2);

    return (ori_t1 * ori_t2 > 0); // the quadrangle was strictly convex !
  }

  double s1 = std::abs(surface_triangle_param(_p1, _p2, _q1));
  double s2 = std::abs(surface_triangle_param(_p1, _p2, _q2));
  double s3 = std::abs(surface_triangle_param(_p1, _q1, _q2));
  double s4 = std::abs(surface_triangle_param(_p2, _q1, _q2));
  if(std::abs(s1 + s2 - s3 - s4) > 1.e-12 * (s1 + s2)) return false;
  if(s3 < .02 * (s1 + s2) || s4 < .02 * (s1 + s2)) return false;
  */

  return true;
}
/*
bool BDS_SwapEdgeTestQuality::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                        BDS_Point *_p3, BDS_Point *_q1,
                                        BDS_Point *_q2, BDS_Point *_q3,
                                        BDS_Point *_op1, BDS_Point *_op2,
                                        BDS_Point *_op3, BDS_Point *_oq1,
                                        BDS_Point *_oq2, BDS_Point *_oq3) const
{
 if(!testQuality) return true;

 double n[3], q[3], on[3], oq[3];
 normal_triangle(_p1, _p2, _p3, n);
 normal_triangle(_q1, _q2, _q3, q);
 normal_triangle(_op1, _op2, _op3, on);
 normal_triangle(_oq1, _oq2, _oq3, oq);

 double const cosnq = prosca(n, q);
 double const cosonq = prosca(on, oq);

 double qa1 = qmTriangle::gamma(_p1, _p2, _p3);
 double qa2 = qmTriangle::gamma(_q1, _q2, _q3);
 double qb1 = qmTriangle::gamma(_op1, _op2, _op3);
 double qb2 = qmTriangle::gamma(_oq1, _oq2, _oq3);

 // we swap for a better configuration
 double const mina = std::min(qa1, qa2);
 double const minb = std::min(qb1, qb2);

 // if(cosnq < .3 && cosonq > .5 && minb > .1)
 //   printf("mina = %g minb = %g cos %g %g\n",mina,minb,cosnq,cosonq);
 if(cosnq < 0.3 && cosonq > 0.5 && minb > 0.1) return true;

 return minb > mina;
 //  if(mina > minb && cosnq <= cosonq)return true;
}
*/

bool BDS_SwapEdgeTestQuality::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_p3, BDS_Point *_q1,
                                         BDS_Point *_q2, BDS_Point *_q3,
                                         BDS_Point *_op1, BDS_Point *_op2,
                                         BDS_Point *_op3, BDS_Point *_oq1,
                                         BDS_Point *_oq2, BDS_Point *_oq3) const
{
  // Check if new edge is not on a seam or degenerated
  BDS_Point *p1 = 0, *p2 = 0;
  if (_op1 != _oq1 && _op1 != _oq2 && _op1 != _oq3){
    p1 = _op2;
    p2 = _op3;
  }
  else if (_op2 != _oq1 && _op2 != _oq2 && _op2 != _oq3){
    p1 = _op1;
    p2 = _op3;
  }
  else if (_op3 != _oq1 && _op3 != _oq2 && _op3 != _oq3){
    p1 = _op1;
    p2 = _op2;
  }
  else {
    Msg::Warning("Unable to detect the new edge in BDS_SwapEdgeTestQuality\n");
  }

  if (p1 && p2){
    if (p1->degenerated && p2->degenerated) return false;
    if (p1->_periodicCounterpart && p2->_periodicCounterpart) return false;
  }

  if(!testQuality) return true;

  double qa1 = qmTriangle::gamma(_p1, _p2, _p3);
  double qa2 = qmTriangle::gamma(_q1, _q2, _q3);
  double qb1 = qmTriangle::gamma(_op1, _op2, _op3);
  double qb2 = qmTriangle::gamma(_oq1, _oq2, _oq3);

  // we swap for a better configuration
  double const mina = std::min(qa1, qa2);
  double const minb = std::min(qb1, qb2);

  //  printf("%g %g -> %g %g\n",qa1,qa2,qb1,qb2);

  // if(cosnq < .3 && cosonq > .5 && minb > .1)
  //   printf("mina = %g minb = %g cos %g %g\n",mina,minb,cosnq,cosonq);
  //  if(cosnq < 0.3 && cosonq > 0.5 && minb > 0.1) return true;

  return minb > mina;
}

bool BDS_SwapEdgeTestNormals::operator()(BDS_Point *_p1, BDS_Point *_p2,
                                         BDS_Point *_q1, BDS_Point *_q2) const
{
  //  if (_p1->g && _p1->g->classif_degree == 2 && _p1->edges.size() <= 4)return
  //  false; if (_p2->g && _p2->g->classif_degree == 2 && _p2->edges.size() <=
  //  4)return false; if (_p1->g && _p1->g->classif_degree < 2 &&
  //  _p1->edges.size() <= 3)return false; if (_p2->g && _p2->g->classif_degree
  //  < 2 && _p2->edges.size() <= 3)return false;

  double s1 = fabs(surface_triangle_param(_p1, _p2, _q1));
  double s2 = fabs(surface_triangle_param(_p1, _p2, _q2));
  double s3 = fabs(surface_triangle_param(_p1, _q1, _q2));
  double s4 = fabs(surface_triangle_param(_p2, _q1, _q2));
  if(fabs(s1 + s2 - s3 - s4) > 1.e-12 * (s3 + s4)) {
    return false;
  }
  //  if(s3 < .02 * (s1 + s2) || s4 < .02 * (s1 + s2)) return false;
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

  //double mina = std::min(qa1, qa2);
  //double minb = std::min(qb1, qb2);
  //  if(minb > 5 * mina) return true;

  double OLD = std::min(_ori * qa1 * _COS_N(_p1, _p2, _p3, gf),
                        _ori * qa2 * _COS_N(_q1, _q2, _q3, gf));

  double NEW = std::min(_ori * qb1 * _COS_N(_op1, _op2, _op3, gf),
                        _ori * qb2 * _COS_N(_oq1, _oq2, _oq3, gf));

  //  printf("%d %d %g %g\n",_p1->iD, _p2->iD, OLD, NEW);

  if(OLD < 0.2 && OLD < NEW) return true;
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
  //return false;



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
  //  if (op[0] == op[1])return false;

  if(p1->iD == CHECK1 && p2->iD == CHECK2) {
    printf("--------------  e %d %d --> %d %d\n", p1->iD, p2->iD, op[0]->iD,
           op[1]->iD);
    printf("--------------  %d %d %d\n", pts1[0]->iD, pts1[1]->iD, pts1[2]->iD);
    printf("--------------  %d %d %d\n", pts2[0]->iD, pts2[1]->iD, pts2[2]->iD);
  }

  if(!force && !p1->config_modified && !p2->config_modified &&
     !op[0]->config_modified && !op[1]->config_modified)
    return false;

  // AVOID CREATING POINTS WITH 2 NEIGHBORING TRIANGLES
  //  std::vector<BDS_Face*> f1 = p1->getTriangles();
  //  std::vector<BDS_Face*> f2 = p2->getTriangles();
  //  if (p1->g && p1->g->classif_degree == 2 && p1->edges.size() <= 4)return
  //  false; if (p2->g && p2->g->classif_degree == 2 && p2->edges.size() <=
  //  4)return false; if (p1->g && p1->g->classif_degree == 1 &&
  //  p1->edges.size() <= 3)return false; if (p2->g && p2->g->classif_degree ==
  //  1 && p2->edges.size() <= 3)return false;
  //      || p2->edges.size() == 4)return false;
  if(p1->iD == CHECK1 && p2->iD == CHECK2) printf("topology OK \n");

  BDS_GeomEntity *g1 = 0, *g2 = 0, *ge = e->g;

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

  if(!theTest(p1, p2, op[0], op[1])) return false;

  if(p1->iD == CHECK1 && p2->iD == CHECK2) printf("TEST2 OK\n");

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
  //  printf("e %d %d\n",p1->iD,p2->iD);

  return true;
}

int BDS_Edge::numTriangles() const
{
  // TODO C++11 use std::count_if
  int NT = 0;
  for(unsigned int i = 0; i < _faces.size(); i++)
    if(faces(i)->numEdges() == 3) NT++;
  return NT;
}

// use robust predicates for not allowing to revert a triangle by
// moving one of its vertices
static bool test_move_point_parametric_quad(BDS_Point *p, double u, double v,
                                            BDS_Face *t)
{
  BDS_Point *pts[4];
  t->getNodes(pts);

  double pa[2] = {pts[0]->u, pts[0]->v};
  double pb[2] = {pts[1]->u, pts[1]->v};
  double pc[2] = {pts[2]->u, pts[2]->v};
  double pd[2] = {pts[3]->u, pts[3]->v};

  double const ori_init1 = robustPredicates::orient2d(pa, pb, pc);
  double const ori_init2 = robustPredicates::orient2d(pc, pd, pa);

  if(p == pts[0]) {
    pa[0] = u;
    pa[1] = v;
  }
  else if(p == pts[1]) {
    pb[0] = u;
    pb[1] = v;
  }
  else if(p == pts[2]) {
    pc[0] = u;
    pc[1] = v;
  }
  else if(p == pts[3]) {
    pd[0] = u;
    pd[1] = v;
  }
  else {
    Msg::Error("Something wrong in move_point_parametric_quad");
    return false;
  }

  double ori_final1 = robustPredicates::orient2d(pa, pb, pc);
  double ori_final2 = robustPredicates::orient2d(pc, pd, pa);
  // allow to move a point when a triangle was flat
  return (ori_init1 * ori_final1 > 0) && (ori_init2 * ori_final2 > 0);
}

static bool test_move_point_parametric_triangle(BDS_Point *p, double u,
                                                double v, BDS_Face *t)
{
  if(t->e4) return test_move_point_parametric_quad(p, u, v, t);
  BDS_Point *pts[4];
  t->getNodes(pts);

  double pa[2] = {pts[0]->u, pts[0]->v};
  double pb[2] = {pts[1]->u, pts[1]->v};
  double pc[2] = {pts[2]->u, pts[2]->v};

  double a[2] = {pb[0] - pa[0], pb[1] - pa[1]};
  double b[2] = {pc[0] - pa[0], pc[1] - pa[1]};

  double area_init = std::abs(a[0] * b[1] - a[1] * b[0]);

  if(area_init == 0.0) return true;

  double const ori_init = robustPredicates::orient2d(pa, pb, pc);

  if(p == pts[0]) {
    pa[0] = u;
    pa[1] = v;
  }
  else if(p == pts[1]) {
    pb[0] = u;
    pb[1] = v;
  }
  else if(p == pts[2]) {
    pc[0] = u;
    pc[1] = v;
  }
  else {
    return false;
  }

  a[0] = pb[0] - pa[0];
  a[1] = pb[1] - pa[1];
  b[0] = pc[0] - pa[0];
  b[1] = pc[1] - pa[1];

  double area_final = std::abs(a[0] * b[1] - a[1] * b[0]);
  if(area_final < 0.1 * area_init) return false;
  double ori_final = robustPredicates::orient2d(pa, pb, pc);
  // allow to move a point when a triangle was flat
  return ori_init * ori_final > 0;
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
    std::vector<BDS_Face *>::iterator it = t.begin();
    while(it != t.end()) {
      BDS_Face *t = *it;
      BDS_Point *pts[4];
      t->getNodes(pts);
      double sold = std::abs(surface_triangle_param(pts[0], pts[1], pts[2]));
      area_old += sold;

      if(t->e1 != e && t->e2 != e && t->e3 != e) {
        gs[nt] = t->g;
        pt[0][nt] = (pts[0] == p) ? o : pts[0];
        pt[1][nt] = (pts[1] == p) ? o : pts[1];
        pt[2][nt] = (pts[2] == p) ? o : pts[2];
        double snew =
          std::abs(surface_triangle_param(pt[0][nt], pt[1][nt], pt[2][nt]));
        if(!force && snew < .02 * sold) {
          //	  printf("argh\n");
          return false;
        }
        area_new += snew;
        ++nt;
      }
      ++it;
    }
  }
  if(!force && nt == 2) return false;

  if(!force && fabs(area_old - area_new) > 1.e-12 * (area_old + area_new))
    return false;

  {
    std::vector<BDS_Face *>::iterator it = t.begin();
    while(it != t.end()) {
      del_face(*it);
      ++it;
    }
  }

  // printf("%d triangles 2 add\n",nt);

  int kk = 0;
  {
    std::vector<BDS_Edge *> edges(p->edges);
    std::vector<BDS_Edge *>::iterator eit = edges.begin();
    while(eit != edges.end()) {
      (*eit)->p1->config_modified = (*eit)->p2->config_modified = true;
      ept[0][kk] = ((*eit)->p1 == p) ? o->iD : (*eit)->p1->iD;
      ept[1][kk] = ((*eit)->p2 == p) ? o->iD : (*eit)->p2->iD;
      egs[kk++] = (*eit)->g;
      del_edge(*eit);
      ++eit;
    }
  }

  // FIXME
  //  del_point(p);

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

#if 0

bool BDS_Mesh::smooth_point_centroid(BDS_Point *p, GFace *gf, bool test_quality)
{
  //  return true;
  //  printf("coucou\n");
 //  if(!p->config_modified) return false;
 if(p->g && p->g->classif_degree <= 1) return false;
 if(p->g && p->g->classif_tag < 0) {
   p->config_modified = true;
   return true;
 }

 // TODO C++11 if (std::any_of() ) return false;
 std::vector<BDS_Edge *>::iterator eit = p->edges.begin();
 while(eit != p->edges.end()) {
   if((*eit)->numfaces() == 1) return false;
   eit++;
 }

 /*    TEST    */
 double radius;
 SPoint3 center;
 bool isSphere = gf->isSphere(radius, center);
 //  bool isBSplineSurface = gf->geomType() == GEntity::BSplineSurface;
 double XX = 0, YY = 0, ZZ = 0;

 double U = 0;
 double V = 0;
 double LC = 0;
 double oldU = p->u;
 double oldV = p->v;

 std::vector<BDS_Face *> ts = p->getTriangles();

 double const size_total = p->edges.size();

 std::vector<BDS_Edge *>::iterator edge_iterator = p->edges.begin();
 while(edge_iterator != p->edges.end()) {
   BDS_Edge const *const edge = *edge_iterator;
   BDS_Point const *const n = edge->othervertex(p);

   double const fact = 1.0;

   U += n->u * fact;
   V += n->v * fact;
   XX += n->X;
   YY += n->Y;
   ZZ += n->Z;
   LC += n->lc() * fact;
   ++edge_iterator;
 }
 U /= size_total;
 V /= size_total;
 LC /= size_total;
 XX /= size_total;
 YY /= size_total;
 ZZ /= size_total;

 GPoint gp;
 double uv[2];
 SVector3 normal;
 if(isSphere /*|| isBSplineSurface*/) {
   gp = gf->closestPoint(SPoint3(XX, YY, ZZ), uv);
   U = gp.u();
   V = gp.v();
 }
 else if(gf->geomType() == GEntity::DiscreteSurface) {
   //    gp = gf->closestPoint(SPoint3(XX, YY, ZZ), uv);
   //    U = gp.u();
   //    V = gp.v();
   discreteFace *df = static_cast<discreteFace *>(gf);
   if(df) {
     gp = df->closestPoint(SPoint3(XX, YY, ZZ), LC, &normal);
     //      gp = gf->closestPoint(SPoint3(XX, YY, ZZ), uv);
     U = gp.u();
     V = gp.v();
     //      double dx = sqrt ((gp.x()-gp2.x())*(gp.x()-gp2.x())+
     //			(gp.y()-gp2.y())*(gp.y()-gp2.y())+
     //			(gp.z()-gp2.z())*(gp.z()-gp2.z()));
     //      if (dx > 1.e-8){
     //	printf("ERROR %12.5E\n",dx);
     //	printf("%g %g %g vs. %g %g %g \n",gp2.x(),gp2.y(),gp2.z(),
     //	       gp.x(),gp.y(),gp.z());
     //      }
   }
 }
 else
   gp = gf->point(U, V);

 if(!gp.succeeded()) { return false; }
 //    if (!gf->containsParam(SPoint2(U,V)))return false;

 const double oldX = p->X;
 const double oldY = p->Y;
 const double oldZ = p->Z;

 double s1 = 0, s2 = 0;

 double newWorst = 1.0, oldWorst = 1.0;

 std::vector<BDS_Face *>::const_iterator it = ts.begin();
 while(it != ts.end()) {
   BDS_Face *t = *it;
   BDS_Point *n[4];
   t->getNodes(n);
   p->u = U;
   p->v = V;
   double snew = std::abs(surface_triangle_param(n[0], n[1], n[2]));
   s1 += snew;
   p->u = oldU;
   p->v = oldV;
   double sold = std::abs(surface_triangle_param(n[0], n[1], n[2]));
   s2 += sold;
   if(snew < .1 * sold) return false;

   p->X = gp.x();
   p->Y = gp.y();
   p->Z = gp.z();
   newWorst = std::min(newWorst, qmTriangle::gamma(*it));
   double norm1[3], norm2[3];
   normal_triangle(n[0], n[1], n[2], norm1);
   p->X = oldX;
   p->Y = oldY;
   p->Z = oldZ;
   normal_triangle(n[0], n[1], n[2], norm2);
   oldWorst = std::min(oldWorst, qmTriangle::gamma(*it));
   double ps;
   if(gf->geomType() == GEntity::DiscreteSurface) {
     ps = prosca(norm1, normal);
     if(ps > 0) return false;
   }
   if(isSphere) {
     double const dx = center.x() - gp.x();
     double const dy = center.y() - gp.y();
     double const dz = center.z() - gp.z();
     ps = dx * norm1[0] + dy * norm1[1] + dz * norm1[2];
     if(ps < 0) return false;
   }
   else {
     ps = prosca(norm1, norm2);
     double threshold = 0.5;
     if(ps < threshold) { return false; }
   }
   ++it;
 }
 // printf("%22.15E %22.15E %22.15E\n",s1,s2,std::abs(s2-s1));
 if(std::abs(s2 - s1) > 1.e-14 * (s2 + s1)) return false;

 //  if(test_quality && newWorst < oldWorst){
 //    return false;
 //  }

 p->u = U;
 p->v = V;
 p->lc() = LC;
 p->X = gp.x();
 p->Y = gp.y();
 p->Z = gp.z();
 eit = p->edges.begin();
 while(eit != p->edges.end()) {
   (*eit)->update();
   ++eit;
 }
 return true;
}

#else

// Tutte's simple smoothing
// other implementations are coming
bool BDS_Mesh::smooth_point_centroid(BDS_Point *p, GFace *gf, bool hard)
{
  // return false;
  if(p->degenerated) return false;
  if(!p->config_modified) return false;
  int CHECK = -1;
  if(p->g && p->g->classif_degree <= 1) return false;
  if(p->g && p->g->classif_tag < 0) {
    p->config_modified = true;
    return true;
  }
  std::vector<BDS_Edge *>::const_iterator eit = p->edges.begin();
  std::vector<BDS_Edge *>::const_iterator itede = p->edges.end();
  while(eit != itede) {
    if((*eit)->numfaces() == 1) return false;
    eit++;
  }

  if(p->iD == CHECK) printf("point %d connected to ", CHECK);

  double XX = 0, YY = 0, ZZ = 0;
  double U = 0;
  double V = 0;
  double LC = 0;
  double oldU = p->u;
  double oldV = p->v;

  std::vector<BDS_Face *> ts = p->getTriangles();

  double sTot = p->edges.size();
  double fact = 0.0;
  double ENERGY = 0.0;
  eit = p->edges.begin();

  if(eit == itede) {
    // Msg::Debug("Hidden bug ... I should have deleted a point but I still do "
    //            "not know why it segfault when I do it :-) ");
    return false;
  }

  while(eit != itede) {
    BDS_Edge *e = *eit;
    BDS_Point *n = e->othervertex(p);
    double NU = n->degenerated ? p->u : n->u;
    if(p->iD == CHECK) printf("%d ", n->iD);
    double du = sqrt((NU - oldU) * (NU - oldU) + (n->v - oldV) * (n->v - oldV));
    if(du == 0) {
      return false;
    }
    double length = e->length();
    ENERGY += length * length;
    double factloc = du / length;
    U += NU * factloc;
    V += n->v * factloc;
    fact += factloc;
    XX += n->X;
    YY += n->Y;
    ZZ += n->Z;
    LC += n->lc();
    ++eit;
  }
  if(p->iD == CHECK) printf("\n");
  // printf("%g\n",fact);
  // sTot *= fact;
  U /= (fact);
  V /= (fact);
  LC /= (sTot);
  XX /= (sTot);
  YY /= (sTot);
  ZZ /= (sTot);

  GPoint gp = gf->point(U, V);

  if(!gp.succeeded()) {
    return false;
  }

  eit = p->edges.begin();
  double ENERGY_NEW = 0;
  while(eit != itede) {
    BDS_Edge *e = *eit;
    BDS_Point *n = e->othervertex(p);
    double l2 = (gp.x() - n->X) * (gp.x() - n->X) +
                (gp.y() - n->Y) * (gp.y() - n->Y) +
                (gp.z() - n->Z) * (gp.z() - n->Z);
    ENERGY_NEW += l2;
    ++eit;
  }

  // simple strategy has failed to reduce energy
  if(p->iD == CHECK)
    printf("SIMPLE CENTROID SCHEME %g %g\n", ENERGY_NEW, ENERGY);

  if(ENERGY_NEW > ENERGY /* || hard*/) {
    double uv[2] = {U, V};
    gp = gf->closestPoint(SPoint3(XX, YY, ZZ), uv);
    U = gp.u();
    V = gp.v();
    //    return false;
    eit = p->edges.begin();
    ENERGY_NEW = 0;
    while(eit != itede) {
      BDS_Edge *e = *eit;
      BDS_Point *n = e->othervertex(p);
      double l2 = (gp.x() - n->X) * (gp.x() - n->X) +
                  (gp.y() - n->Y) * (gp.y() - n->Y) +
                  (gp.z() - n->Z) * (gp.z() - n->Z);
      ENERGY_NEW += l2;
      ++eit;
    }
    if(p->iD == CHECK) printf("PROJECTION : %g %g\n", ENERGY_NEW, ENERGY);
    if(ENERGY_NEW > ENERGY) {
      Msg::Debug("Impossible to move vertex %d using simple strategies... "
                 "leaving it there",
                 p->iD);
      return false;
    }
  }

  const double oldX = p->X;
  const double oldY = p->Y;
  const double oldZ = p->Z;

  double s1 = 0, s2 = 0;

  double newWorst = 1.0, oldWorst = 1.0;
  // double OLD = 1, NEW = 1;
  std::vector<BDS_Face *>::const_iterator it = ts.begin();
  while(it != ts.end()) {
    BDS_Face *t = *it;
    BDS_Point *n[4];
    t->getNodes(n);
    //    OLD = std::min (OLD,_COS_N ( n[0], n[1], n[2], gf));
    p->u = U;
    p->v = V;
    double snew = std::abs(surface_triangle_param(n[0], n[1], n[2]));
    s1 += snew;
    p->u = oldU;
    p->v = oldV;
    double sold = std::abs(surface_triangle_param(n[0], n[1], n[2]));
    s2 += sold;
    if(snew < 0.02 * sold) return false;
    p->X = gp.x();
    p->Y = gp.y();
    p->Z = gp.z();
    newWorst = std::min(newWorst, qmTriangle::gamma(*it));
    p->X = oldX;
    p->Y = oldY;
    p->Z = oldZ;
    oldWorst = std::min(oldWorst, qmTriangle::gamma(*it));

    ++it;
  }

  // if(p->edges.size() == 3)printf("3 -> %22.15E\n", fabs(s2-s1));
  if(fabs(s2 - s1) > 1.e-12 * (s2 + s1)) {
    // if(p->iD == CHECK)
    //   printf("PARAMETRIC TRIANGLES OVERLAP %22.15E!!\n", fabs(s2-s1));
    // else
    return false;
  }
  if(newWorst < oldWorst) return false;
  // if (p->edges.size() == 3) printf("OK \n");

  // if(OLD < 0 && NEW > OLD){
  //   return true;
  // }
  // if(NEW < 0) return false;

  p->u = U;
  p->v = V;
  p->lc() = LC;
  p->X = gp.x();
  p->Y = gp.y();
  p->Z = gp.z();
  eit = p->edges.begin();
  while(eit != p->edges.end()) {
    (*eit)->update();
    ++eit;
  }
  return true;
}

#endif

bool BDS_Mesh::smooth_point_parametric(BDS_Point *const point, GFace *const gf)
{
  if(!point->config_modified) return false;

  if(point->g && point->g->classif_degree <= 1) return false;

  double U = 0.0, V = 0.0;
  double tot_length = 0;
  double LC = 0;

  std::vector<BDS_Face *> triangles = point->getTriangles();
  std::vector<BDS_Face *>::iterator it = triangles.begin();

  while(it != triangles.end()) {
    BDS_Face *t = *it;
    BDS_Point *n[4];
    t->getNodes(n);
    for(int i = 0; i < t->numEdges(); i++) {
      U += n[i]->u;
      V += n[i]->v;
      LC += n[i]->lc();
      tot_length += 1;
    }
    ++it;
  }
  U /= tot_length;
  V /= tot_length;
  LC /= point->edges.size();

  it = triangles.begin();
  while(it != triangles.end()) {
    BDS_Face *t = *it;
    if(!test_move_point_parametric_triangle(point, U, V, t)) {
      //      printf("coucou %g %g -> %g %g\n", point->u, point->v,U,V);
      return false;
    }
    ++it;
  }
  GPoint gp = gf->point(U, V);
  if(!gp.succeeded()) return false;

  point->u = U;
  point->v = V;
  point->lc() = LC;
  point->X = gp.x();
  point->Y = gp.y();
  point->Z = gp.z();
  std::vector<BDS_Edge *>::iterator eit = point->edges.begin();
  while(eit != point->edges.end()) {
    (*eit)->update();
    ++eit;
  }

  return true;
}
