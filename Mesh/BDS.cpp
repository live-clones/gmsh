// $Id: BDS.cpp,v 1.55 2006-07-25 13:00:07 remacle Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "gmsh@geuz.org".

#include <math.h>
#include <stdio.h>
#include "Numeric.h"
#include "GmshMatrix.h"
#include "BDS.h"
#include "Message.h"

double BDS_Point::min_edge_length()
{
  std::list<BDS_Edge*>::iterator it  = edges.begin();
  std::list<BDS_Edge*>::iterator ite = edges.end();
  double L = 1.e245;
  while(it!=ite){
    double l = (*it)->length();
    if (l<L)L=l;
    ++it;
  }
  return L;
}

void outputScalarField(std::list < BDS_Triangle * >t, const char *iii)
{
  FILE *f = fopen(iii, "w");
  fprintf(f, "View \"scalar\" {\n");
  std::list < BDS_Triangle * >::iterator tit = t.begin();
  std::list < BDS_Triangle * >::iterator tite = t.end();
  while(tit != tite) {
    BDS_Point *pts[3];
    (*tit)->getNodes(pts);
    fprintf(f, "ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%g,%g,%g};\n",
            pts[0]->X, pts[0]->Y, pts[0]->Z,
            pts[1]->X, pts[1]->Y, pts[1]->Z,
            pts[2]->X, pts[2]->Y, pts[2]->Z,
            pts[0]->radius_of_curvature, pts[1]->radius_of_curvature,
            pts[2]->radius_of_curvature);
    ++tit;
  }
  fprintf(f, "};\n");
  fclose(f);
}

double BDS_Quadric::normalCurv(double x, double y, double z) const
{
  // K = div n = div ( Grad(f) / ||Grad(f)||)
  //   = Laplacian (f) /  ||Grad(f)|| - Grad^t(f) Hessian Grad(f) / ||Grad(f)||^3
  BDS_Vector g = Gradient(x, y, z);
  const double normG2 = 1. / (g.x * g.x + g.y * g.y + g.z * g.z);
  double normG = sqrt(normG2);
  double c1 = 2 * (a + b + c);
  double c2 =
    2 * a * g.x * g.x +
    2 * b * g.y * g.y +
    2 * c * g.z * g.z +
    4 * d * g.x * g.y + 4 * e * g.x * g.z + 4 * f * g.y * g.z;

  // printf("%g %g %g %g %g %g\n",a,b,c,normG,c1, c2 / (normG*normG*normG));
  return fabs(c1 - c2 * (normG2)) * normG;
}

void BDS_Quadric::projection(double xa, double ya, double za,
                             double &x, double &y, double &z) const
{
  x = xa;
  y = ya;
  z = za;
  const double residual = signedDistanceTo(xa, ya, za);

  int ITER = 0;
  while(1) {
    // the equation to solve is 
    // X = XA + z * N (XA)
    // N = Gradient F (XA)
    // F(X) is the quadric :: X^t A X + X^t B + C
    // z^2 ( N^t A N ) + z ( XA^t A N + N^t A XA + N^t B) + F ( XA )  
    BDS_Vector grad = Gradient(x, y, z);
    double coef1 =
      a * grad.x * grad.x +
      b * grad.y * grad.y +
      c * grad.z * grad.z +
      2 * d * grad.x * grad.y +
      2 * e * grad.x * grad.z + 2 * f * grad.y * grad.z;
    double coef2 =
      2 * a * xa * grad.x +
      2 * b * ya * grad.y +
      2 * c * za * grad.z +
      2 * d * (xa * grad.y + ya * grad.x) +
      2 * e * (xa * grad.z + za * grad.x) +
      2 * f * (za * grad.y + ya * grad.z) +
      grad.x * g + grad.y * h + grad.z * i;
    double delta = coef2 * coef2 - 4. * coef1 * residual;
    if(delta < 0) {
      // printf("aaargh error projection delta = %g\n",delta);
    }
    else {
      double alpha;
      double alpha1 = (-coef2 + sqrt(delta)) / (2 * coef1);
      double alpha2 = (-coef2 - sqrt(delta)) / (2 * coef1);
      if(fabs(alpha1) > fabs(alpha2))
        alpha = alpha2;
      else
        alpha = alpha1;
      x = xa + alpha * grad.x;
      y = ya + alpha * grad.y;
      z = za + alpha * grad.z;
    }
    // printf("point (%g,%g,%g) ==> (%g,%g,%g) dist %g\n",
    //        xa,ya,za,x,y,z,signedDistanceTo(x,y,z));;
    if(ITER++ == 0)
      break;
  }
}

void BDS_GeomEntity::getClosestTriangles(double x, double y, double z,
                                         std::list < BDS_Triangle * >&l,
                                         double &radius ,
                                         double &X, double &Y, double &Z)
{
#ifdef HAVE_ANN_
  l.clear();

  if(kdTree == 0) {
    l = t;
    return;
  }

  queryPt[0] = x;
  queryPt[1] = y;
  queryPt[2] = z;

  double eps = 0.;
  kdTree->annkSearch(queryPt,  // query point
		     nbK,      // number of near neighbors
		     nnIdx,    // nearest neighbors (returned)
		     dists,    // distance (returned)
		     eps);     // error bound

  std::list < BDS_Triangle * >l1, l2, l3;

  X = kdTree->thePoints()[nnIdx[0]][0];
  Y = kdTree->thePoints()[nnIdx[0]][1];
  Z = kdTree->thePoints()[nnIdx[0]][2];

  radius = sR[nnIdx[0]];

  for(int K = 0; K < nbK; K++) {
    BDS_Edge *e = sE[nnIdx[K]];
    e->p1->getTriangles(l1);
    e->p2->getTriangles(l2);
    l.insert(l.begin(), l1.begin(), l1.end());
    l.insert(l.begin(), l2.begin(), l2.end());
    l.sort();
    l.unique();
  }

#else
  {
    l = t;
  }
#endif
}


BDS_Vector::BDS_Vector(const BDS_Point & p2, const BDS_Point & p1)
  :x(p2.X - p1.X), y(p2.Y - p1.Y), z(p2.Z - p1.Z)
{
}

BDS_Vector BDS_Point::N() const
{
  std::list < BDS_Triangle * >t;
  getTriangles(t);
  std::list < BDS_Triangle * >::iterator tit = t.begin();
  std::list < BDS_Triangle * >::iterator tite = t.end();
  BDS_Vector SumN;
  while(tit != tite) {
    SumN += (*tit)->N();
    ++tit;
  }
  double NORM = sqrt(SumN * SumN);
  SumN /= NORM;
  return SumN;
}

double dist_droites_gauches(BDS_Point * p1, BDS_Point * p2,
                            BDS_Point * p3, BDS_Point * p4)
{
  BDS_Vector u1(*p2, *p1);
  BDS_Vector u2(*p4, *p3);
  BDS_Vector a(*p2, *p4);
  BDS_Vector u1xu2 = u1 % u2;
  double x = sqrt(u1xu2 * u1xu2);
  // les droites sont paralleles
  if(x == 0) {
    return 1.e18;
  }
  // les droites sont gauches
  else {
    double y = fabs((a % u1) * u2);
    return y / x;
  }
}

bool proj_point_triangle(double xa, double ya, double za,
                         const BDS_Vector & n,
                         BDS_Triangle * t, double &x, double &y, double &z)
{
  const double eps_prec = 1.e-10;
  //  BDS_Vector n = t->N();
  double mat[3][3];
  double b[3];
  double res[2];
  double det;
  BDS_Point *pts[3];
  t->getNodes(pts);

  mat[0][0] = pts[1]->X - pts[0]->X;
  mat[0][1] = pts[2]->X - pts[0]->X;
  mat[0][2] = -n.x;

  mat[1][0] = pts[1]->Y - pts[0]->Y;
  mat[1][1] = pts[2]->Y - pts[0]->Y;
  mat[1][2] = -n.y;

  mat[2][0] = pts[1]->Z - pts[0]->Z;
  mat[2][1] = pts[2]->Z - pts[0]->Z;
  mat[2][2] = -n.z;

  b[0] = xa - pts[0]->X;
  b[1] = ya - pts[0]->Y;
  b[2] = za - pts[0]->Z;
  if(!sys3x3(mat, b, res, &det))
    return false;

  // coordonnees dans la face
  if(res[0] >= 1.0 + eps_prec || res[0] <= -eps_prec)
    return false;
  if(res[1] >= 1.0 + eps_prec || res[1] <= -eps_prec)
    return false;
  if(res[1] >= 1. + eps_prec - res[0])
    return false;

  x = xa + res[2] * n.x;
  y = ya + res[2] * n.y;
  z = za + res[2] * n.z;
  return true;
}

void proj_point_plane(double xa, double ya, double za,
                      BDS_Point * p1, BDS_Point * p2, BDS_Point * p3,
                      double &x, double &y, double &z)
{
  // plane ax+by+cz+1 = 0;

  double mat[3][3];
  mat[0][0] = p1->X;
  mat[0][1] = p1->Y;
  mat[0][2] = p1->Z;
  mat[1][0] = p2->X;
  mat[1][1] = p2->Y;
  mat[1][2] = p2->Z;
  mat[2][0] = p3->X;
  mat[2][1] = p3->Y;
  mat[2][2] = p3->Z;
  double b[3] = { -1, -1, -1 };
  double pl[3], det;
  sys3x3(mat, b, pl, &det);
  double n[3] = { pl[0], pl[1], pl[2] };
  //    norme(n);
  // pp(x,y,z) = p + k n
  // pp belongs to the plane
  // a x + b y + c z + 1 = 0
  // x = xa + k nx
  // y = ya + k ny
  // z = za + k nz
  // a(xa + k nx) + b( ya + k ny ) + c(  za + k nz ) + 1 = 0
  // k = - ( a xa + b ya + c za + 1) / (a nx + b ny + c nz )
  double k =
    -(pl[0] * xa + pl[1] * ya + pl[2] * za + 1) / (pl[0] * n[0] +
                                                   pl[1] * n[1] +
                                                   pl[2] * n[2]);
  x = xa + k * n[0];
  y = ya + k * n[1];
  z = za + k * n[2];
}

void print_face(BDS_Triangle * t)
{
  BDS_Point *pts[3];
  t->getNodes(pts);
  printf("face %p with nodes %d %d %d and edges %p (%d %d) %p (%d %d) %p (%d %d)\n",
	 (void *)t, pts[0]->iD, pts[1]->iD, pts[2]->iD, (void *)t->e1,
	 t->e1->p1->iD, t->e1->p2->iD, (void *)t->e2, t->e2->p1->iD,
	 t->e2->p2->iD, (void *)t->e3, t->e3->p1->iD, t->e3->p2->iD);
}

void print_edge(BDS_Edge * e)
{
  printf("edge %p with nodes %d %d ------------------\n", (void *)e,
         e->p1->iD, e->p2->iD);
  printf("faces : \n ");
  for(int i = 0; i < e->numfaces(); ++i)
    print_face(e->faces(i));

  printf("----------------------------------------------\n ");
}

void vector_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3,
                     double c[3])
{
  double a[3] = { p1->X - p2->X, p1->Y - p2->Y, p1->Z - p2->Z };
  double b[3] = { p1->X - p3->X, p1->Y - p3->Y, p1->Z - p3->Z };
  c[2] = a[0] * b[1] - a[1] * b[0];
  c[1] = -a[0] * b[2] + a[2] * b[0];
  c[0] = a[1] * b[2] - a[2] * b[1];
}

void normal_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3,
                     double c[3])
{
  vector_triangle(p1, p2, p3, c);
  double l = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
  if(l == 0)
    return;
  c[0] /= l;
  c[1] /= l;
  c[2] /= l;
}

double surface_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3)
{
  double c[3];
  vector_triangle(p1, p2, p3, c);
  return 0.5 * sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
}

double quality_triangle(BDS_Point * p1, BDS_Point * p2, BDS_Point * p3)
{
  double e12 = ((p1->X - p2->X) * (p1->X - p2->X) +
                (p1->Y - p2->Y) * (p1->Y - p2->Y) +
                (p1->Z - p2->Z) * (p1->Z - p2->Z));
  double e22 = ((p1->X - p3->X) * (p1->X - p3->X) +
                (p1->Y - p3->Y) * (p1->Y - p3->Y) +
                (p1->Z - p3->Z) * (p1->Z - p3->Z));
  double e32 = ((p3->X - p2->X) * (p3->X - p2->X) +
                (p3->Y - p2->Y) * (p3->Y - p2->Y) +
                (p3->Z - p2->Z) * (p3->Z - p2->Z));
  double a = surface_triangle(p1, p2, p3);
  return a / (e12 + e22 + e32);
}

void BDS_Point::getTriangles(std::list < BDS_Triangle * >&t) const
{
  t.clear();
  std::list < BDS_Edge * >::const_iterator it = edges.begin();
  std::list < BDS_Edge * >::const_iterator ite = edges.end();
  while(it != ite) {
    int NF = (*it)->numfaces();
    for(int i = 0; i < NF; ++i) {
      BDS_Triangle *tt = (*it)->faces(i);
      if(tt) {
        std::list < BDS_Triangle * >::iterator tit = t.begin();
        std::list < BDS_Triangle * >::iterator tite = t.end();
        int found = 0;
        while(tit != tite) {
          if(tt == *tit)
            found = 1;
          ++tit;
        }
        if(!found)
          t.push_back(tt);
      }
    }
    ++it;
  }
}

BDS_Point *BDS_Mesh::add_point(int num, double x, double y, double z)
{
  BDS_Point *pp = new BDS_Point(num, x, y, z);
  points.insert(pp);
  MAXPOINTNUMBER = (MAXPOINTNUMBER < num) ? num : MAXPOINTNUMBER;
  return pp;
}

BDS_Point *BDS_Mesh::find_point(int p)
{
  BDS_Point P(p);
  std::set < BDS_Point *, PointLessThan >::iterator it = points.find(&P);
  if(it != points.end())
    return (BDS_Point *) (*it);
  else
    return 0;
}

BDS_Edge *BDS_Mesh::find_edge(int num1, int num2)
{
  BDS_Point *p = find_point(num1);
  std::list < BDS_Edge * >::iterator eit = p->edges.begin();
  while(eit != p->edges.end()) {
    if((*eit)->p1 == p && (*eit)->p2->iD == num2)
      return (*eit);
    if((*eit)->p2 == p && (*eit)->p1->iD == num2)
      return (*eit);
    ++eit;
  }
  return 0;
}

BDS_Edge *BDS_Mesh::find_edge(BDS_Point * p1, BDS_Point * p2,
                              BDS_Triangle * t) const
{
  BDS_Point P1(p1->iD);
  BDS_Point P2(p2->iD);
  BDS_Edge E(&P1, &P2);
  if(t->e1->p1->iD == E.p1->iD && t->e1->p2->iD == E.p2->iD)
    return t->e1;
  if(t->e2->p1->iD == E.p1->iD && t->e2->p2->iD == E.p2->iD)
    return t->e2;
  if(t->e3->p1->iD == E.p1->iD && t->e3->p2->iD == E.p2->iD)
    return t->e3;
  return 0;
}

BDS_Triangle *BDS_Mesh::find_triangle(BDS_Edge * e1, BDS_Edge * e2,
                                      BDS_Edge * e3)
{
  int i;
  for(i = 0; i < e1->numfaces(); i++) {
    BDS_Triangle *t = e1->faces(i);
    BDS_Edge *o1 = t->e1;
    BDS_Edge *o2 = t->e2;
    BDS_Edge *o3 = t->e3;
    if((o1 == e1 && o2 == e2 && o3 == e3) ||
       (o1 == e1 && o2 == e3 && o3 == e2) ||
       (o1 == e2 && o2 == e1 && o3 == e3) ||
       (o1 == e2 && o2 == e3 && o3 == e1) ||
       (o1 == e3 && o2 == e1 && o3 == e2) ||
       (o1 == e3 && o2 == e2 && o3 == e1))
      return t;
  }
  for(i = 0; i < e2->numfaces(); i++) {
    BDS_Triangle *t = e2->faces(i);
    BDS_Edge *o1 = t->e1;
    BDS_Edge *o2 = t->e2;
    BDS_Edge *o3 = t->e3;
    if((o1 == e1 && o2 == e2 && o3 == e3) ||
       (o1 == e1 && o2 == e3 && o3 == e2) ||
       (o1 == e2 && o2 == e1 && o3 == e3) ||
       (o1 == e2 && o2 == e3 && o3 == e1) ||
       (o1 == e3 && o2 == e1 && o3 == e2) ||
       (o1 == e3 && o2 == e2 && o3 == e1))
      return t;
  }
  for(i = 0; i < e3->numfaces(); i++) {
    BDS_Triangle *t = e3->faces(i);
    BDS_Edge *o1 = t->e1;
    BDS_Edge *o2 = t->e2;
    BDS_Edge *o3 = t->e3;
    if((o1 == e1 && o2 == e2 && o3 == e3) ||
       (o1 == e1 && o2 == e3 && o3 == e2) ||
       (o1 == e2 && o2 == e1 && o3 == e3) ||
       (o1 == e2 && o2 == e3 && o3 == e1) ||
       (o1 == e3 && o2 == e1 && o3 == e2) ||
       (o1 == e3 && o2 == e2 && o3 == e1))
      return t;
  }
  return 0;
}

BDS_Edge *BDS_Mesh::add_edge(int p1, int p2)
{
  BDS_Edge *efound = find_edge(p1, p2);
  if(efound)
    return efound;

  BDS_Point *pp1 = find_point(p1);
  BDS_Point *pp2 = find_point(p2);
  if(!pp1 || !pp2)
    throw;
  BDS_Edge *e = new BDS_Edge(pp1, pp2);
  edges.push_back(e);
  return e;
}

BDS_Triangle *BDS_Mesh::add_triangle(int p1, int p2, int p3)
{
  BDS_Edge *e1 = add_edge(p1, p2);
  BDS_Edge *e2 = add_edge(p2, p3);
  BDS_Edge *e3 = add_edge(p3, p1);
  return add_triangle(e1, e2, e3);
}

BDS_Triangle *BDS_Mesh::add_triangle(BDS_Edge * e1, BDS_Edge * e2,
                                     BDS_Edge * e3)
{

  BDS_Triangle *tfound = find_triangle(e1, e2, e3);
  if(tfound)
    return tfound;

  try {
    BDS_Triangle *t = new BDS_Triangle(e1, e2, e3);
    triangles.push_back(t);
    return t;
  }
  catch(...) {
    return 0;
  }
}

BDS_Tet *BDS_Mesh::add_tet(int p1, int p2, int p3, int p4)
{
  BDS_Edge *e1 = add_edge(p1, p2);
  BDS_Edge *e2 = add_edge(p2, p3);
  BDS_Edge *e3 = add_edge(p3, p1);
  BDS_Edge *e4 = add_edge(p1, p4);
  BDS_Edge *e5 = add_edge(p2, p4);
  BDS_Edge *e6 = add_edge(p3, p4);
  BDS_Triangle *t1 = add_triangle(e1, e2, e3);
  BDS_Triangle *t2 = add_triangle(e1, e4, e5);
  BDS_Triangle *t3 = add_triangle(e2, e6, e5);
  BDS_Triangle *t4 = add_triangle(e3, e4, e6);
  BDS_Tet *t = new BDS_Tet(t1, t2, t3, t4);
  tets.push_back(t);
  return t;
}

void BDS_Mesh::del_triangle(BDS_Triangle * t)
{
  t->e1->del(t);
  t->e2->del(t);
  t->e3->del(t);
  t->deleted = true;
}

void BDS_Mesh::del_edge(BDS_Edge * e)
{
  // edges.erase(e);
  e->p1->del(e);
  e->p2->del(e);
  e->deleted = true;
  // edges_to_delete.insert(e);
}

void BDS_Mesh::del_point(BDS_Point * p)
{
  points.erase(p);
  delete p;
}

void BDS_Mesh::add_geom(int p1, int p2)
{
  geom.insert(new BDS_GeomEntity(p1, p2));
}

void BDS_Edge::oppositeof(BDS_Point * oface[2]) const
{
  oface[0] = oface[1] = 0;
  if(faces(0)) {
    BDS_Point *pts[3];
    faces(0)->getNodes(pts);
    if(pts[0] != p1 && pts[0] != p2)
      oface[0] = pts[0];
    else if(pts[1] != p1 && pts[1] != p2)
      oface[0] = pts[1];
    else
      oface[0] = pts[2];
  }
  if(faces(1)) {
    BDS_Point *pts[3];
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
  std::set < BDS_GeomEntity *, GeomLessThan >::iterator it = geom.find(&ge);
  if(it == geom.end())
    return 0;
  return (BDS_GeomEntity *) (*it);
}

void recur_tag(BDS_Triangle * t, BDS_GeomEntity * g)
{
  if(!t->g) {
    t->g = g;
    g->t.push_back(t);
    if(!t->e1->g && t->e1->numfaces() == 2) {
      recur_tag(t->e1->otherFace(t), g);
    }
    if(!t->e2->g && t->e2->numfaces() == 2) {
      recur_tag(t->e2->otherFace(t), g);
    }
    if(!t->e3->g && t->e3->numfaces() == 2) {
      recur_tag(t->e3->otherFace(t), g);
    }
  }
}

void BDS_Mesh::reverseEngineerCAD()
{
  for(std::set < BDS_GeomEntity *, GeomLessThan >::iterator it = geom.begin();
      it != geom.end(); ++it) {
    if((*it)->classif_degree == 2) {
      std::set < BDS_Vector > pts;
      std::list < BDS_Triangle * >::iterator tit = (*it)->t.begin();
      std::list < BDS_Triangle * >::iterator tite = (*it)->t.end();
      BDS_Vector::t = LC / 1.e6;
      while(tit != tite) {
        BDS_Point *nod[3];
        (*tit)->getNodes(nod);
        BDS_Vector p1 = BDS_Vector(nod[0]->X, nod[0]->Y, nod[0]->Z);
        BDS_Vector p2 = BDS_Vector(nod[1]->X, nod[1]->Y, nod[1]->Z);
        BDS_Vector p3 = BDS_Vector(nod[2]->X, nod[2]->Y, nod[2]->Z);
        pts.insert(p1);
        pts.insert(p2);
        pts.insert(p3);
        pts.insert((p1 + p2) * 0.5);
        pts.insert((p1 + p3) * 0.5);
        pts.insert((p2 + p3) * 0.5);
        tit++;
      }

      // We consider the following implicit quadrics surface
      // f(x) = x^T A x + b^T x + c = 0 
      // A symmetric ( 6 coeffs ), b a vector ( 3 coeffs ) and c a scalar
      // 10 coefficients
      // we try to fit that using least squares
      // we use both points and edges mid points for the fitting 

      if(pts.size() > 3) {
        // TEST PLANE (easier than quadrics...)
        {
          Double_Matrix PLANE(pts.size(), 3);
          Double_Vector ONES(pts.size());
          Double_Vector RSLT(3);
          std::set < BDS_Vector >::iterator pit = pts.begin();
          std::set < BDS_Vector >::iterator pite = pts.end();
          int k = 0;
          while(pit != pite) {
            PLANE(k, 0) = (*pit).x + (rand() % 1000) * LC / 1.e12;
            PLANE(k, 1) = (*pit).y + (rand() % 1000) * LC / 1.e12;
            PLANE(k, 2) = (*pit).z + (rand() % 1000) * LC / 1.e12;
            ONES(k) = -1;
            k++;
            ++pit;
          }

          PLANE.least_squares(ONES, RSLT);
          // printf("%d points plane surface %d ?? : %g %g %g\n",
	  //        pts.size(),(*it)->classif_tag,RSLT(0),RSLT(1),RSLT(2));

          bool plane = true;
          for(unsigned int i = 0; i < pts.size(); i++) {
            const double dist = PLANE(i, 0) * RSLT(0) + PLANE(i, 1) * RSLT(1) +
	      PLANE(i, 2) * RSLT(2) + 1;
            if(fabs(dist) >
               1.e-5 * LC * sqrt(RSLT(0) * RSLT(0) + RSLT(1) * RSLT(1) +
                                 RSLT(2) * RSLT(2)))
              plane = false;
          }

          if(plane) {
            // printf("plane surface %d found : %g %g %g\n",
	    //        (*it)->classif_tag,RSLT(0),RSLT(1),RSLT(2));
            (*it)->surf = new BDS_Plane(RSLT(0), RSLT(1), RSLT(2));
          }
        }
        if(!(*it)->surf && pts.size() > 20) {
          Double_Matrix QUADRIC(pts.size(), 9);
          Double_Vector ONES(pts.size());
          Double_Vector RSLT(9);
          std::set < BDS_Vector >::iterator pit = pts.begin();
          std::set < BDS_Vector >::iterator pite = pts.end();
          int k = 0;
          while(pit != pite) {
            QUADRIC(k, 0) = (*pit).x * (*pit).x;
            QUADRIC(k, 1) = (*pit).y * (*pit).y;
            QUADRIC(k, 2) = (*pit).z * (*pit).z;
            QUADRIC(k, 3) = 2 * (*pit).x * (*pit).y;
            QUADRIC(k, 4) = 2 * (*pit).x * (*pit).z;
            QUADRIC(k, 5) = 2 * (*pit).y * (*pit).z;
            QUADRIC(k, 6) = (*pit).x;
            QUADRIC(k, 7) = (*pit).y;
            QUADRIC(k, 8) = (*pit).z;
            ONES(k) = 1;
            k++;
            ++pit;
          }
          QUADRIC.least_squares(ONES, RSLT);
          bool quad = true;
          BDS_Quadric temp(RSLT(0), RSLT(1), RSLT(2), RSLT(3), RSLT(4),
                           RSLT(5), RSLT(6), RSLT(7), RSLT(8));
          pit = pts.begin();
          while(pit != pite) {
            double x, y, z;
            temp.projection((*pit).x, (*pit).y, (*pit).z, x, y, z);
            const double dist = sqrt(((*pit).x - x) * ((*pit).x - x) +
                                     ((*pit).y - y) * ((*pit).y - y) +
                                     ((*pit).z - z) * ((*pit).z - z));
            // printf("%g %g %g ... %g %g %g\n",(*pit).x , (*pit).y , (*pit).z ,x,y,z);

            if(dist > 1.e-3 * LC)
              quad = false;
            ++pit;
          }
          if(quad) {
            // printf("quadric surface %d found : %g %g %g %g %g %g %g %g %g\n",
	    //       (*it)->classif_tag, RSLT(0),RSLT(1),RSLT(2),RSLT(3),RSLT(4),
	    //       RSLT(5),RSLT(6),RSLT(7),RSLT(8));
            (*it)->surf =
              new BDS_Quadric(RSLT(0), RSLT(1), RSLT(2), RSLT(3), RSLT(4),
                              RSLT(5), RSLT(6), RSLT(7), RSLT(8));
            //test
            /*
               FILE *f = fopen ("QUADRIC.pos","w");
               fprintf(f,"View \"quadric\" {\n");
               const int NNN = 20;
               for (int I=0;I<NNN;I++){
               for (int J=0;J<NNN;J++){
               for (int K=0;K<NNN;K++){
               double u1 = (double)I/NNN;
               double v1 = (double)J/NNN;
               double w1 = (double)K/NNN;
               double X1 = Min[0] + u1 * (Max[0]-Min[0]);
               double Y1 = Min[1] + v1 * (Max[1]-Min[1]);
               double Z1 = Min[2] + w1 * (Max[2]-Min[2]);
               double u2 = (double)(I+1)/NNN;
               double v2 = (double)(J+1)/NNN;
               double w2 = (double)(K+1)/NNN;
               double X2 = Min[0] + u2 * (Max[0]-Min[0]);
               double Y2 = Min[1] + v2 * (Max[1]-Min[1]);
               double Z2 = Min[2] + w2 * (Max[2]-Min[2]);
               fprintf(f,"SH(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,"
	                  "%g,%g,%g,%g,%g,%g,%g){%g,%g,%g,%g,%g,%g,%g,%g};\n",
			  X1,Y1,Z1,X2,Y1,Z1,X2,Y2,Z1,X1,Y2,Z1,X1,Y1,Z2,X2,
			  Y1,Z2,X2,Y2,Z2,X1,Y2,Z2,
			  (*it)->surf->signedDistanceTo (X1,Y1,Z1),
			  (*it)->surf->signedDistanceTo (X2,Y1,Z1),
			  (*it)->surf->signedDistanceTo (X2,Y2,Z1),
			  (*it)->surf->signedDistanceTo (X1,Y2,Z1),
			  (*it)->surf->signedDistanceTo (X1,Y1,Z2),
			  (*it)->surf->signedDistanceTo (X2,Y1,Z2),
			  (*it)->surf->signedDistanceTo (X2,Y2,Z2),
			  (*it)->surf->signedDistanceTo (X1,Y2,Z2));
               }
               }
               }
               fprintf(f,"};\n");
               fclose(f);                 
             */
          }
        }
      }
    }
  }
}

void BDS_Mesh::createSearchStructures()
{
#ifdef HAVE_ANN_

  Msg(INFO, "Creating the ANN search structure");

  const double LC_SEARCH = LC * 1e-3;

  for(std::set < BDS_GeomEntity *, GeomLessThan >::iterator it = geom.begin();
      it != geom.end(); ++it) {
    if((*it)->classif_degree == 2 && !(*it)->surf) {
      if((*it)->t.size() > 5) {
        int maxPts = 0;
	
        std::set < BDS_Edge * >edg;

        std::list < BDS_Triangle * >::iterator tit = (*it)->t.begin();
        std::list < BDS_Triangle * >::iterator tite = (*it)->t.end();

        while(tit != tite) {
          edg.insert((*tit)->e1);
          edg.insert((*tit)->e2);
          edg.insert((*tit)->e3);
          tit++;
        }

        std::set < BDS_Edge * >::iterator eit = edg.begin();
        std::set < BDS_Edge * >::iterator eite = edg.end();
        while(eit != eite) {
          double l = (*eit)->length();
          maxPts += (int)(l / (LC_SEARCH) + 2);
          eit++;
        }

        // printf("%d pts found\n", maxPts);

        const int dim = 3;
        (*it)->queryPt = annAllocPt(dim);       // allocate query point
        (*it)->dataPts = annAllocPts(maxPts, dim);      // allocate data points
        (*it)->nnIdx = new ANNidx[(*it)->nbK];  // allocate near neigh indices
        (*it)->dists = new ANNdist[(*it)->nbK]; // allocate near neighbor dists  
        (*it)->sE.resize(maxPts);
        (*it)->sR.resize(maxPts);
        int I = 0;

        eit = edg.begin();
        eite = edg.end();
        while(eit != eite) {
          double l = (*eit)->length();
          int N = (int)(l / (LC_SEARCH) + 2);
          BDS_Point *p1 = (*eit)->p1;
          BDS_Point *p2 = (*eit)->p2;

          for(int i = 0; i < N; i++) {
            double u = (double)i / (N - 1);
            (*it)->dataPts[I][0] = p1->X + (p2->X - p1->X) * (u);
            (*it)->dataPts[I][1] = p1->Y + (p2->Y - p1->Y) * (u);
            (*it)->dataPts[I][2] = p1->Z + (p2->Z - p1->Z) * (u);
            (*it)->sE[I] = (*eit);
            (*it)->sR[I] =
              p1->radius_of_curvature + (p2->radius_of_curvature -
                                         p1->radius_of_curvature) * (u);;
            I++;
          }
          eit++;
        }
        // printf("building kd Tree for surface %d -- %d points\n",(*it)->classif_tag,maxPts);
        (*it)->kdTree = new ANNkd_tree( // build search structure
                                        (*it)->dataPts, // the data points
                                        maxPts, // number of points
                                        dim);
      }
    }
  }
#endif
}

void BDS_Point::compute_curvature()
{
  std::list < BDS_Triangle * >t;
  getTriangles(t);

  // printf("curvature using %d triangles\n",t.size());

  if(g && g->classif_degree != 2) {
    radius_of_curvature = 1.e22;
    return;
  }

  if(t.size() > 4) {
    Double_Matrix M(t.size(), 4);
    Double_Vector Nx(t.size());
    Double_Vector Ny(t.size());
    Double_Vector Nz(t.size());
    Double_Vector Cx(4);
    Double_Vector Cy(4);
    Double_Vector Cz(4);

    std::list < BDS_Triangle * >::iterator tit = t.begin();
    std::list < BDS_Triangle * >::iterator tite = t.end();
    int k = 0;
    while(tit != tite) {
      const BDS_Vector cog = (*tit)->cog();
      M(k, 0) = X - cog.x;
      M(k, 1) = Y - cog.y;
      M(k, 2) = Z - cog.z;
      M(k, 3) = 1.0;
      BDS_Vector N = (*tit)->N();
      Nx(k) = N.x;
      Ny(k) = N.y;
      Nz(k) = N.z;
      k++;
      ++tit;
    }
    M.least_squares(Nx, Cx);
    M.least_squares(Ny, Cy);
    M.least_squares(Nz, Cz);

    // curvature = divergence of n

    double curvature = fabs(Cx(0)) + fabs(Cy(1)) + fabs(Cz(2));

    if(curvature != 0.0)
      radius_of_curvature = fabs(1. / curvature);
    else
      radius_of_curvature = 1.e22;
    // printf(" R = %g\n",radius_of_curvature);
  }
}

void compute_curvatures(std::list < BDS_Edge * >&edges)
{
  {
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) {
      (*it)->target_length = 1.e22;
      (*it)->p1->radius_of_curvature = 1.e22;
      (*it)->p2->radius_of_curvature = 1.e22;
      ++it;
    }

  }
  {
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) {
      if((*it)->numfaces() == 2) {
        if((*it)->faces(0)->g == (*it)->faces(1)->g) {
          double l1 = 2 * (*it)->faces(0)->inscribed_radius();
          double l2 = 2 * (*it)->faces(1)->inscribed_radius();
          BDS_Vector N1 = (*it)->faces(0)->N();
          BDS_Vector N2 = (*it)->faces(1)->N();
          BDS_Vector DIFFN = N2 - N1;
          BDS_Vector DIST = l1 + l2;
          double crv = 1. / sqrt((DIFFN * DIFFN) / (DIST * DIST));

          if((*it)->p1->radius_of_curvature > crv)
            (*it)->p1->radius_of_curvature = crv;
          if((*it)->p2->radius_of_curvature > crv)
            (*it)->p2->radius_of_curvature = crv;
        }
      }
      ++it;
    }
  }
}


void recur_color_plane_surf(const double eps,
                            BDS_Triangle * t,
                            const BDS_Vector & n,
                            std::set < BDS_Triangle * >&all,
                            std::list < BDS_Triangle * >&plane)
{
  if(all.find(t) == all.end()) {
    BDS_Vector n2 = t->N();
    double angle = fabs(n2.angle(n));
    // printf("triangle %p angle %g\n",t,angle);
    if(angle < eps) {
      all.insert(t);
      plane.push_back(t);
      if(t->e1->numfaces() == 2)
        recur_color_plane_surf(eps, t->e1->otherFace(t), n, all, plane);
      if(t->e2->numfaces() == 2)
        recur_color_plane_surf(eps, t->e2->otherFace(t), n, all, plane);
      if(t->e3->numfaces() == 2)
        recur_color_plane_surf(eps, t->e3->otherFace(t), n, all, plane);
    }
  }
}




void BDS_Mesh::color_plane_surf(double eps, int NB_T)
{
  int current_status = 100000;
  std::set < BDS_Triangle * >all;
  std::list < BDS_Triangle * >::iterator it = triangles.begin();
  std::list < BDS_Triangle * >::iterator ite = triangles.end();
  while(it != ite) 
    {
      if(all.find(*it) == all.end()) 
	{
	  std::list < BDS_Triangle * >plane;
	  BDS_Triangle *start = (BDS_Triangle *) (*it);
	  recur_color_plane_surf(eps, start, start->N(), all, plane);
	  if((int)plane.size() > NB_T) 
	    {
	      // printf("plane surface found %d triangles\n",plane.size());
	      std::list < BDS_Triangle * >::iterator xit = plane.begin();
	      std::list < BDS_Triangle * >::iterator xite = plane.end();
	      while(xit != xite) 
		{
		  (*xit)->status = current_status;
		  ++xit;
		}
	      current_status++;
	    }
	}
      ++it;
    }
}

bool BDS_Mesh::extractVolumes()
{
  bool closed = true;
  {
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) 
      {
	if ( (*it)->numfaces() !=2 ) closed = false;	  
	++it;
      }    
  }
  
  // printf("the domain is closed ? : %d\n",closed);
  return closed;
}


void BDS_Mesh::classify(double angle, int NB_T)
{
  // printf("  classifying \n");

  static BDS_GeomEntity EDGE_CLAS(0, 1);
  // clear everything

  {
    {
      std::set < BDS_Point *, PointLessThan >::iterator it = points.begin();
      std::set < BDS_Point *, PointLessThan >::iterator ite = points.end();
      while(it != ite) {
        (*it)->g = 0;
        ++it;
      }
    }
    {
      std::list < BDS_Edge * >::iterator it = edges.begin();
      std::list < BDS_Edge * >::iterator ite = edges.end();
      while(it != ite) {
        (*it)->g = 0;
        ++it;
      }
    }
    {
      std::list < BDS_Triangle * >::iterator it = triangles.begin();
      std::list < BDS_Triangle * >::iterator ite = triangles.end();
      while(it != ite) {
        (*it)->g = 0;
        if((*it)->status > 10000)
          (*it)->status = 0;
        ++it;
      }
    }
    geom.clear();
  }

  color_plane_surf(3.1415/200, 40);

  {
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) {
      BDS_Edge & e = *((BDS_Edge *) * it);
      if(e.status == 1) {
        e.g = &EDGE_CLAS;
      }
      else if(e.status == -1) {
      }
      else if(e.numfaces() == 1) {
        e.g = &EDGE_CLAS;
      }
      else if(e.numfaces() == 2 && e.faces(0)->status != e.faces(1)->status) {
        e.g = &EDGE_CLAS;
      }
      else if(e.numfaces() == 2) {
        BDS_Vector N0 = e.faces(0)->N();
        BDS_Vector N1 = e.faces(1)->N();
        double ag = N0.angle(N1);
        if(fabs(ag) > angle) {
          e.g = &EDGE_CLAS;
        }
      }
      else {
        e.g = &EDGE_CLAS;
      }
      ++it;
    }
  }

  /*
     {
     std::list<BDS_Triangle*>::iterator it  = triangles.begin();
     std::list<BDS_Triangle*>::iterator ite = triangles.end();
     while(it!=ite){
     (*it)->g = 0;
     ++it;
     }
     geom.clear();
     }
   */

  // printf("  classifying faces\n");

  {
    int tag = 1;
    while(1) {
      std::list < BDS_Triangle * >::iterator it = triangles.begin();
      std::list < BDS_Triangle * >::iterator ite = triangles.end();
      BDS_Triangle *start = 0;
      while(it != ite) {
        if(!(*it)->deleted && !(*it)->g) {
          start = (BDS_Triangle *) (*it);
        }
        if(start)
          break;
        ++it;
      }
      if(!start)
        break;
      add_geom(tag, 2);
      BDS_GeomEntity *g = get_geom(tag, 2);
      recur_tag(start, g);
      tag++;
    }
    // printf("  classifying edges (%d face tags found)\n",tag-1);
  }

  int edgetag = 1;
  {
    std::map < std::pair < int, int >, int >edgetags;
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) {
      BDS_Edge & e = *((BDS_Edge *) * it);

      if(e.g) {
        int MIN_FAC = 100000;
        int MAX_FAC = -100000;
        std::map < std::pair < int, int >, int >::iterator found;
        BDS_GeomEntity *g;
        if(e.numfaces() == 1) {
          found =
            edgetags.find(std::make_pair(e.faces(0)->g->classif_tag, -1));
        }
        else if(e.numfaces() == 2) { // && e.faces(0)->g->classif_tag != e.faces(1)->g->classif_tag)
          if(e.faces(0)->g->classif_tag > e.faces(1)->g->classif_tag)
            found =
              edgetags.
              find(std::
                   make_pair(e.faces(1)->g->classif_tag,
                             e.faces(0)->g->classif_tag));
          else
            found =
              edgetags.
              find(std::
                   make_pair(e.faces(0)->g->classif_tag,
                             e.faces(1)->g->classif_tag));
        }
        else {
          for(int K = 0; K < e.numfaces(); K++) {
            if(MIN_FAC > e.faces(K)->g->classif_tag)
              MIN_FAC = e.faces(K)->g->classif_tag;
            if(MAX_FAC < e.faces(K)->g->classif_tag)
              MAX_FAC = e.faces(K)->g->classif_tag;
            found = edgetags.find(std::make_pair(MIN_FAC, MAX_FAC));
          }
        }

        if(e.g) {
          if(found == edgetags.end()) {
            add_geom(edgetag, 1);
            g = get_geom(edgetag, 1);
            if(e.numfaces() == 1) {
              edgetags[std::make_pair(e.faces(0)->g->classif_tag, -1)] = edgetag;
            }
            else if(e.numfaces() == 2) {
              if(e.faces(0)->g->classif_tag > e.faces(1)->g->classif_tag)
                edgetags[std::make_pair(e.faces(1)->g->classif_tag,
					e.faces(0)->g->classif_tag)] = edgetag;
              else
                edgetags[std::make_pair(e.faces(0)->g->classif_tag,
					e.faces(1)->g->classif_tag)] = edgetag;
            }
            else {
              edgetags[std::make_pair(MIN_FAC, MAX_FAC)] = edgetag;
            }
            edgetag++;
          }
          else {
            g = get_geom(found->second, 1);
          }
          e.g = g;
          g->e.push_back(&e);
        }
      }
      else {
        e.g = e.faces(0)->g;
        e.g->e.push_back(&e);
      }
      ++it;
    }
  }

  // printf("  classifying points\n");

  int vertextag = 1;
  {
    std::set < BDS_Point *, PointLessThan >::iterator it = points.begin();
    std::set < BDS_Point *, PointLessThan >::iterator ite = points.end();
    while(it != ite) {
      std::list < BDS_Edge * >::iterator eit = (*it)->edges.begin();
      std::list < BDS_Edge * >::iterator eite = (*it)->edges.end();
      std::set < BDS_GeomEntity * >geoms;
      BDS_GeomEntity *vg = 0;
      while(eit != eite) {
        if((*eit)->g && (*eit)->g->classif_degree == 1)
          geoms.insert((*eit)->g);
        else
          vg = (*eit)->g;
        ++eit;
      }
      if(geoms.size() == 0) {
        (*it)->g = vg;
      }
      else if(geoms.size() == 1) {
        (*it)->g = (*(geoms.begin()));
      }
      else {
        add_geom(vertextag, 0);
        (*it)->g = get_geom(vertextag++, 0);
        (*it)->g->p = (*it);
      }
      if(!(*it)->g)
        Msg(GERROR, "Error in BDS");
      ++it;
    }
  }
  {
    std::set < BDS_Point *, PointLessThan >::iterator it = points.begin();
    std::set < BDS_Point *, PointLessThan >::iterator ite = points.end();
    while(it != ite) {
      if((*it)->g->classif_degree > 1) {
        std::list < BDS_Triangle * >t;
        (*it)->getTriangles(t);
        BDS_Vector SumN = (*it)->N();
        std::list < BDS_Triangle * >::iterator tit = t.begin();
        std::list < BDS_Triangle * >::iterator tite = t.end();
        double max_angle = 0;
        while(tit != tite) {
          double ag = SumN.angle((*tit)->N());
          if(fabs(ag) > max_angle)
            max_angle = fabs(ag);
          ++tit;
        }
        if(fabs(max_angle) > angle) {
          add_geom(vertextag, 0);
          (*it)->g = get_geom(vertextag++, 0);
          (*it)->g->p = (*it);
        }
      }
      ++it;
    }
  }

  Msg(INFO, "Computing curvatures");
  compute_curvatures(edges);
  Msg(INFO, "Reverse engineering surfaces");

  reverseEngineerCAD();
  Msg(INFO, "Creating search structures");
  createSearchStructures();
  Msg(INFO, "End classifying %d edgetags %d vertextags", edgetag - 1, vertextag - 1);
  //  outputScalarField (triangles,"R_curvature.pos");
  extractVolumes();
}

double PointLessThanLexicographic::t = 0;
double BDS_Vector::t = 0;

bool BDS_Mesh::read_stl(const char *filename, const double tolerance)
{
  // add 'b' for pure Windows programs, since some of these files
  // contain binary data
  FILE *f = fopen(filename, "rb");
  if(!f)
    return false;
  char buffer[256], name[256];

  PointLessThanLexicographic::t = tolerance;

  fgets(buffer, 255, f);

  std::set < BDS_Point *, PointLessThanLexicographic > pts;

  sscanf(buffer, "%s", name);
  // ASCII STL    
  if(!strcmp(name, "solid")) {
    rewind(f);
    fgets(buffer, 255, f);

    Min[0] = Min[1] = Min[2] = 1.e12;
    Max[0] = Max[1] = Max[2] = -1.e12;

    double XCG = 0;
    double YCG = 0;
    double ZCG = 0;

    int Nf = 0;
    while(!feof(f)) {
      char s1[256], s2[256];
      float x, y, z;
      fgets(buffer, 255, f);
      sscanf(buffer, "%s", s1);
      if(!strcmp(s1, "endsolid"))
        break;
      sscanf(buffer, "%s %s %f %f %f", s1, s2, &x, &y, &z);
      fgets(buffer, 255, f);
      fgets(buffer, 255, f);    // 1st point
      sscanf(buffer, "%s %f %f %f", s2, &x, &y, &z);
      BDS_Point P1(0, x, y, z);
      fgets(buffer, 255, f);    // 2nd point
      sscanf(buffer, "%s %f %f %f", s2, &x, &y, &z);
      BDS_Point P2(0, x, y, z);
      fgets(buffer, 255, f);    // 3rd point
      sscanf(buffer, "%s %f %f %f", s2, &x, &y, &z);
      BDS_Point P3(0, x, y, z);
      fgets(buffer, 255, f);    // end loop
      fgets(buffer, 255, f);    // end facet

      Nf++;

      if(P1.X < Min[0])
        Min[0] = P1.X;
      if(P2.X < Min[0])
        Min[0] = P2.X;
      if(P3.X < Min[0])
        Min[0] = P3.X;

      if(P1.Y < Min[1])
        Min[1] = P1.Y;
      if(P2.Y < Min[1])
        Min[1] = P2.Y;
      if(P3.Y < Min[1])
        Min[1] = P3.Y;

      if(P1.Z < Min[2])
        Min[2] = P1.Z;
      if(P2.Z < Min[2])
        Min[2] = P2.Z;
      if(P3.Z < Min[2])
        Min[2] = P3.Z;

      if(P1.X > Max[0])
        Max[0] = P1.X;
      if(P2.X > Max[0])
        Max[0] = P2.X;
      if(P3.X > Max[0])
        Max[0] = P3.X;

      if(P1.Y > Max[1])
        Max[1] = P1.Y;
      if(P2.Y > Max[1])
        Max[1] = P2.Y;
      if(P3.Y > Max[1])
        Max[1] = P3.Y;

      if(P1.Z > Max[2])
        Max[2] = P1.Z;
      if(P2.Z > Max[2])
        Max[2] = P2.Z;
      if(P3.Z > Max[2])
        Max[2] = P3.Z;

      XCG += (P1.X + P2.X + P3.X);
      YCG += (P1.Y + P2.Y + P3.Y);
      ZCG += (P1.Z + P2.Z + P3.Z);
    }

    XCG /= (3 * Nf);
    YCG /= (3 * Nf);
    ZCG /= (3 * Nf);

    Min[0] -= XCG;
    Min[1] -= YCG;
    Min[2] -= ZCG;
    Max[0] -= XCG;
    Max[1] -= YCG;
    Max[2] -= ZCG;

    LC = sqrt((Min[0] - Max[0]) * (Min[0] - Max[0]) +
              (Min[1] - Max[1]) * (Min[1] - Max[1]) +
              (Min[2] - Max[2]) * (Min[2] - Max[2]));

    // printf("LC = %g\n",LC);

    PointLessThanLexicographic::t = LC * tolerance;

    rewind(f);
    fgets(buffer, 255, f);
    while(!feof(f)) {
      char s1[256], s2[256];
      float x, y, z;
      fgets(buffer, 255, f);
      sscanf(buffer, "%s", s1);
      if(!strcmp(s1, "endsolid"))
        break;
      sscanf(buffer, "%s %s %f %f %f", s1, s2, &x, &y, &z);
      fgets(buffer, 255, f);
      fgets(buffer, 255, f);    // 1st point
      sscanf(buffer, "%s %f %f %f", s2, &x, &y, &z);
      BDS_Point P1(0, x - XCG, y - YCG, z - ZCG);
      fgets(buffer, 255, f);    // 2nd point
      sscanf(buffer, "%s %f %f %f", s2, &x, &y, &z);
      BDS_Point P2(0, x - XCG, y - YCG, z - ZCG);
      fgets(buffer, 255, f);    // 3rd point
      sscanf(buffer, "%s %f %f %f", s2, &x, &y, &z);
      BDS_Point P3(0, x - XCG, y - YCG, z - ZCG);
      fgets(buffer, 255, f);    // end loop
      fgets(buffer, 255, f);    // end facet
      BDS_Point *p1 = 0;
      BDS_Point *p2 = 0;
      BDS_Point *p3 = 0;
      std::set < BDS_Point *, PointLessThanLexicographic >::iterator it1 =
        pts.find(&P1);
      if(it1 != pts.end()) {
        p1 = *it1;
      }
      else {
        MAXPOINTNUMBER++;
        p1 = add_point(MAXPOINTNUMBER, P1.X, P1.Y, P1.Z);
        pts.insert(p1);
      }
      std::set < BDS_Point *, PointLessThanLexicographic >::iterator it2 =
        pts.find(&P2);
      if(it2 != pts.end()) {
        p2 = *it2;
      }
      else {
        MAXPOINTNUMBER++;
        p2 = add_point(MAXPOINTNUMBER, P2.X, P2.Y, P2.Z);
        pts.insert(p2);
      }
      std::set < BDS_Point *, PointLessThanLexicographic >::iterator it3 =
        pts.find(&P3);
      if(it3 != pts.end()) {
        p3 = *it3;
      }
      else {
        MAXPOINTNUMBER++;
        p3 = add_point(MAXPOINTNUMBER, P3.X, P3.Y, P3.Z);
        pts.insert(p3);
      }
      add_triangle(p1->iD, p2->iD, p3->iD);
    }
  }
  // BINARY STL 
  else {
    rewind(f);
    char DUMMY[80];
    fread(DUMMY, 1, 80, f);

    unsigned long int Nf;
    size_t x = fread(&Nf, sizeof(unsigned long int), 1, f);
    char *DATA = new char[Nf * 50 * sizeof(char)];
    x = fread(DATA, sizeof(char), Nf * 50, f);

    Msg(INFO, "BINARY STL data read, %ld facets", Nf);

    Min[0] = Min[1] = Min[2] = 1.e12;
    Max[0] = Max[1] = Max[2] = -1.e12;

    double XCG = 0;
    double YCG = 0;
    double ZCG = 0;

    for(unsigned int i = 0; i < Nf; ++i) {
      float *X = (float *)&DATA[i * 50 * sizeof(char)];

      if(X[3] < Min[0])
        Min[0] = X[3];
      if(X[6] < Min[0])
        Min[0] = X[6];
      if(X[9] < Min[0])
        Min[0] = X[9];

      if(X[4] < Min[1])
        Min[1] = X[4];
      if(X[7] < Min[1])
        Min[1] = X[7];
      if(X[10] < Min[1])
        Min[1] = X[10];

      if(X[5] < Min[2])
        Min[2] = X[5];
      if(X[8] < Min[2])
        Min[2] = X[8];
      if(X[11] < Min[2])
        Min[2] = X[11];

      if(X[3] > Max[0])
        Max[0] = X[3];
      if(X[6] > Max[0])
        Max[0] = X[6];
      if(X[9] > Max[0])
        Max[0] = X[9];

      if(X[4] > Max[1])
        Max[1] = X[4];
      if(X[7] > Max[1])
        Max[1] = X[7];
      if(X[10] > Max[1])
        Max[1] = X[10];

      if(X[5] > Max[2])
        Max[2] = X[5];
      if(X[8] > Max[2])
        Max[2] = X[8];
      if(X[11] > Max[2])
        Max[2] = X[11];
      XCG += (X[3] + X[6] + X[9]);
      YCG += (X[4] + X[7] + X[10]);
      ZCG += (X[5] + X[8] + X[11]);
    }

    XCG /= (3 * Nf);
    YCG /= (3 * Nf);
    ZCG /= (3 * Nf);

    Min[0] -= XCG;
    Min[1] -= YCG;
    Min[2] -= ZCG;
    Max[0] -= XCG;
    Max[1] -= YCG;
    Max[2] -= ZCG;
    LC = sqrt((Min[0] - Max[0]) * (Min[0] - Max[0]) +
              (Min[1] - Max[1]) * (Min[1] - Max[1]) +
              (Min[2] - Max[2]) * (Min[2] - Max[2]));

    PointLessThanLexicographic::t = LC * tolerance;

    for(unsigned int i = 0; i < Nf; ++i) {
      float *X = (float *)&DATA[i * 50 * sizeof(char)];
      // printf("%g %g %g %g %g %g %g %g %g %g %g %g\n",
      //        X[0],X[1],X[2],X[3],X[4],X[5],X[6],X[7],X[8],X[9],X[10],X[11]);
      BDS_Point P1(0, X[3] - XCG, X[4] - YCG, X[5] - ZCG);
      BDS_Point P2(0, X[6] - XCG, X[7] - YCG, X[8] - ZCG);
      BDS_Point P3(0, X[9] - XCG, X[10] - YCG, X[11] - ZCG);
      BDS_Point *p1 = 0;
      BDS_Point *p2 = 0;
      BDS_Point *p3 = 0;
      std::set < BDS_Point *, PointLessThanLexicographic >::iterator it1 =
        pts.find(&P1);
      if(it1 != pts.end()) {
        p1 = *it1;
      }
      else {
        MAXPOINTNUMBER++;
        p1 = add_point(MAXPOINTNUMBER, P1.X, P1.Y, P1.Z);
        pts.insert(p1);
      }
      std::set < BDS_Point *, PointLessThanLexicographic >::iterator it2 =
        pts.find(&P2);
      if(it2 != pts.end()) {
        p2 = *it2;
      }
      else {
        MAXPOINTNUMBER++;
        p2 = add_point(MAXPOINTNUMBER, P2.X, P2.Y, P2.Z);
        pts.insert(p2);
      }
      std::set < BDS_Point *, PointLessThanLexicographic >::iterator it3 =
        pts.find(&P3);
      if(it3 != pts.end()) {
        p3 = *it3;
      }
      else {
        MAXPOINTNUMBER++;
        p3 = add_point(MAXPOINTNUMBER, P3.X, P3.Y, P3.Z);
        pts.insert(p3);
      }
      add_triangle(p1->iD, p2->iD, p3->iD);
    }
    delete[]DATA;
  }
  fclose(f);
  // classify(M_PI);
  return true;
}

bool BDS_Mesh::import_view(Post_View *view, const double tolerance)
{
  // imports all the tris+quads from a post-processing view

  Min[0] = view->BBox[0]; Max[0] = view->BBox[1];
  Min[1] = view->BBox[2]; Max[1] = view->BBox[3];
  Min[2] = view->BBox[4]; Max[2] = view->BBox[5];
  LC = sqrt((Min[0] - Max[0]) * (Min[0] - Max[0]) +
	    (Min[1] - Max[1]) * (Min[1] - Max[1]) +
	    (Min[2] - Max[2]) * (Min[2] - Max[2]));
  
  PointLessThanLexicographic::t = tolerance;
  std::set < BDS_Point *, PointLessThanLexicographic > pts;

  for(int type = 0; type < 6; type++){
    int nbList, nbNod;
    List_T *list;
    switch(type){
    case 0: list = view->ST; nbList = view->NbST; nbNod = 3; break;
    case 1: list = view->VT; nbList = view->NbVT; nbNod = 3; break;
    case 2: list = view->TT; nbList = view->NbTT; nbNod = 3; break;
    case 3: list = view->SQ; nbList = view->NbSQ; nbNod = 4; break;
    case 4: list = view->VQ; nbList = view->NbVQ; nbNod = 4; break;
    case 5: list = view->TQ; nbList = view->NbTQ; nbNod = 4; break;
    }
    if(nbList){
      int nb = List_Nbr(list) / nbList;
      for(int i = 0; i < List_Nbr(list); i += nb) {
	double *x = (double *)List_Pointer_Fast(list, i);
	double *y = (double *)List_Pointer_Fast(list, i + nbNod);
	double *z = (double *)List_Pointer_Fast(list, i + 2 * nbNod);
	BDS_Point *p[4];
	for(int j = 0; j < nbNod; j++){
	  BDS_Point P(0, x[j], y[j], z[j]);    
	  std::set < BDS_Point *, PointLessThanLexicographic >::iterator it = pts.find(&P);
	  if(it != pts.end()) {
	    p[j] = *it;
	  }
	  else {
	    MAXPOINTNUMBER++;
	    p[j] = add_point(MAXPOINTNUMBER, P.X, P.Y, P.Z);
	    pts.insert(p[j]);
	  }
	}
	if(nbNod == 3){
	  add_triangle(p[0]->iD, p[1]->iD, p[2]->iD);
	}
	else{
	  add_triangle(p[0]->iD, p[1]->iD, p[2]->iD);
	  add_triangle(p[0]->iD, p[2]->iD, p[3]->iD);
	}
      }
    }
  }
  return true;
}

// INRIA FORMAT
bool BDS_Mesh::read_mesh(const char *filename)
{
  FILE *f = fopen(filename, "r");
  if(!f)
    return false;
  char buffer[256], name[256];

  fgets(buffer, 255, f);

  int format;

  sscanf(buffer, "%s %d", name, &format);
  // ASCII MESH  
  if(format == 1) {

    while(!feof(f)) {
      fgets(buffer, 255, f);
      if(buffer[0] != '#') {    // skip comments
        sscanf(buffer, "%s", name);

        if(!strcmp(name, "Dimension"))
          fgets(buffer, 255, f);
        else if(!strcmp(name, "Vertices")) {
          Min[0] = Min[1] = Min[2] = 1.e12;
          Max[0] = Max[1] = Max[2] = -1.e12;
          int nbv, cl;
          double x, y, z;
          fgets(buffer, 255, f);
          sscanf(buffer, "%d", &nbv);
          for(int i = 0; i < nbv; i++) {
            fgets(buffer, 255, f);
            sscanf(buffer, "%lf %lf %lf %d", &x, &y, &z, &cl);
            Min[0] = (Min[0] < x) ? Min[0] : x;
            Min[1] = (Min[1] < y) ? Min[1] : y;
            Min[2] = (Min[2] < z) ? Min[2] : z;
            Max[0] = (Max[0] > x) ? Max[0] : x;
            Max[1] = (Max[1] > y) ? Max[1] : y;
            Max[2] = (Max[2] > z) ? Max[2] : z;
            add_point(i + 1, x, y, z);
          }

	  // NORMALIZE HERE

	  LC = sqrt((Min[0] - Max[0]) * (Min[0] - Max[0]) +
		    (Min[1] - Max[1]) * (Min[1] - Max[1]) +
		    (Min[2] - Max[2]) * (Min[2] - Max[2]));
	  	  
	  std::set < BDS_Point *, PointLessThan >::iterator it = points.begin();
	  std::set < BDS_Point *, PointLessThan >::iterator ite = points.end();
	  
	  while(it != ite) 
	    {
	      (*it)->X /= LC;
	      (*it)->Y /= LC;
	      (*it)->Z /= LC;
	      ++it;
	    }
	  Min[0]/=LC;Min[1]/=LC;Min[2]/=LC;
	  Max[0]/=LC;Max[1]/=LC;Max[2]/=LC;
	  LC = 1;

          MAXPOINTNUMBER = nbv + 1;
        }
        else if(!strcmp(name, "Triangles")) {
          int nbt, cl, n1, n2, n3;
          fgets(buffer, 255, f);
          sscanf(buffer, "%d", &nbt);
          for(int i = 0; i < nbt; i++) {
            fgets(buffer, 255, f);
            sscanf(buffer, "%d %d %d %d", &n1, &n2, &n3, &cl);
            BDS_Triangle *t = add_triangle(n1, n2, n3);
            t->status = cl;
          }
        }
        else if(!strcmp(name, "Quadrilaterals")) {
          int nbt, cl, n1, n2, n3, n4;
          fgets(buffer, 255, f);
          sscanf(buffer, "%d", &nbt);
          for(int i = 0; i < nbt; i++) {
            fgets(buffer, 255, f);
            sscanf(buffer, "%d %d %d %d %d", &n1, &n2, &n3, &n4, &cl);
            BDS_Triangle *t1 = add_triangle(n1, n2, n3);
            // pas 12
            // pas 13
            BDS_Triangle *t2 = add_triangle(n1, n3, n4);
            t1->status = cl;
            t2->status = cl;
          }
        }
      }
    }



  }
  else {
    throw;
  }

  return true;
}

void BDS_Mesh::save_gmsh_format(const char *filename)
{
  cleanup();

  int nbModelVertex = 0;

  FILE *f = fopen(filename, "w");
  {
    std::set < BDS_Point *, PointLessThan >::iterator it = points.begin();
    std::set < BDS_Point *, PointLessThan >::iterator ite = points.end();

    fprintf(f, "$NOD\n");
    fprintf(f, "%d\n", (int)points.size());
    while(it != ite) {
      if((*it)->g && (*it)->g->classif_degree == 0)
        nbModelVertex++;
      fprintf(f, "%d %g %g %g\n", (*it)->iD, (*it)->X, (*it)->Y, (*it)->Z);
      ++it;
    }
    fprintf(f, "$ENDNOD\n");
  }
  {
    fprintf(f, "$ELM\n");

    int nbClasEdges = 0;
    {
      std::list < BDS_Edge * >::iterator it = edges.begin();
      std::list < BDS_Edge * >::iterator ite = edges.end();
      while(it != ite) {
        if((*it)->g && (*it)->g->classif_degree == 1)
          nbClasEdges++;
        ++it;
      }
    }

    fprintf(f, "%d\n", nbClasEdges + nbModelVertex + triangles.size());

    int k = 1;
    {
      std::set < BDS_Point *, PointLessThan >::iterator it = points.begin();
      std::set < BDS_Point *, PointLessThan >::iterator ite = points.end();
      while(it != ite) {
        if((*it)->g && (*it)->g->classif_degree == 0) {
          fprintf(f, "%d %d %d %d %d %d\n",
                  k++, 15, (*it)->g->classif_tag, (*it)->g->classif_tag, 1,
                  (*it)->iD);
        }
        ++it;
      }
    }
    {
      std::list < BDS_Edge * >::iterator it = edges.begin();
      std::list < BDS_Edge * >::iterator ite = edges.end();
      while(it != ite) {
        if((*it)->g && (*it)->g->classif_degree == 1)
          fprintf(f, "%d %d %d %d %d %d %d\n",
                  k++, 1, (*it)->g->classif_tag, (*it)->g->classif_tag, 2,
                  (*it)->p1->iD, (*it)->p2->iD);
        ++it;

      }
    }
    {
      std::list < BDS_Triangle * >::iterator it = triangles.begin();
      std::list < BDS_Triangle * >::iterator ite = triangles.end();
      while(it != ite) {
        if((*it)->deleted) {
	  Msg(GERROR, "Error in BDS");
          throw;
        }
        BDS_Point *nod[3];
        (*it)->getNodes(nod);
        if((*it)->g)
          fprintf(f, "%d %d %d %d %d %d %d %d\n",
                  k++, 2, (*it)->g->classif_tag, (*it)->g->classif_tag, 3,
                  nod[0]->iD, nod[1]->iD, nod[2]->iD);
        else
          fprintf(f, "%d %d %d %d %d %d %d %d\n",
                  k++, 2, 1, 1, 3, nod[0]->iD, nod[1]->iD, nod[2]->iD);
        ++it;

      }
    }
    fprintf(f, "$ENDELM\n");
  }
  fclose(f);
}

template < class IT > void DESTROOOY(IT beg, IT end)
{
  while(beg != end) {
    delete *beg;
    beg++;
  }
}

void BDS_Mesh::cleanup()
{
  {
    for (std::list<BDS_Triangle*> :: iterator it = triangles.begin();
	 it != triangles.end();
	 it++)
      {
	while (it != triangles.end() && (*it)->deleted)
	  {
	    delete *it;
	    it = triangles.erase (it);
	  }
      }	   
  }
  { 
    for (std::list<BDS_Edge*> :: iterator it = edges.begin();
	 it != edges.end();
	 it++)
      {
	while (it != edges.end() && (*it)->deleted)
	  {
	    delete *it;
	    it = edges.erase (it);
	  }	
      }	   
  } 
}

BDS_Mesh ::~ BDS_Mesh ()
{
   DESTROOOY ( geom.begin(),geom.end());
   DESTROOOY ( points.begin(),points.end());
   cleanup();
   DESTROOOY ( edges.begin(),edges.end());
   DESTROOOY ( triangles.begin(),triangles.end());
   DESTROOOY ( tets.begin(),tets.end());
}


BDS_Point* BDS_Mesh::split_edge(BDS_Edge * e, double coord, BDS_Mesh * geom)
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

  int nbFaces = e->numfaces();

  if(nbFaces != 2)
    return 0;

  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;

  BDS_Point *pts1[3];
  e->faces(0)->getNodes(pts1);

  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      if(pts1[(i + 1) % 3] == p2)
        orientation = 1;
      else
        orientation = -1;

      break;
    }
  }

  MAXPOINTNUMBER++;
  BDS_Point *mid = add_point(MAXPOINTNUMBER,
                             coord * p1->X + (1 - coord) * p2->X,
                             coord * p1->Y + (1 - coord) * p2->Y,
                             coord * p1->Z + (1 - coord) * p2->Z);

  mid->radius_of_curvature =
    coord * p1->radius_of_curvature + (1 - coord) * p2->radius_of_curvature;

  // we should project 
  e->oppositeof(op);
  BDS_GeomEntity *g1 = 0, *g2 = 0, *ge = e->g;

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  if(e->faces(0)) {
    g1 = e->faces(0)->g;
    del_triangle(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    g2 = e->faces(0)->g;
    del_triangle(e->faces(0));
  }

  double t_l = e->target_length;

  del_edge(e);

  BDS_Edge *p1_mid = new BDS_Edge(p1, mid);
  edges.push_back(p1_mid);
  BDS_Edge *mid_p2 = new BDS_Edge(mid, p2);
  edges.push_back(mid_p2);
  BDS_Edge *op1_mid = new BDS_Edge(op[0], mid);
  edges.push_back(op1_mid);
  BDS_Edge *mid_op2 = new BDS_Edge(mid, op[1]);
  edges.push_back(mid_op2);

  p1_mid->target_length = t_l;
  op1_mid->target_length = t_l;
  mid_p2->target_length = t_l;
  mid_op2->target_length = t_l;

  // printf("split ends 1 %d (%d %d) %d %d \n",
  //         p1_op1->numfaces(), p1->iD, op[0]->iD, 
  //         op1_mid->numfaces(),p1_mid->numfaces());
  BDS_Triangle *t1, *t2, *t3, *t4;
  if(orientation == 1) {
    t1 = new BDS_Triangle(op1_mid, p1_op1, p1_mid);
    t2 = new BDS_Triangle(mid_op2, op2_p2, mid_p2);
    t3 = new BDS_Triangle(op1_p2, op1_mid, mid_p2);
    t4 = new BDS_Triangle(p1_op2, mid_op2, p1_mid);
  }
  else {
    t1 = new BDS_Triangle(p1_op1, op1_mid, p1_mid);
    t2 = new BDS_Triangle(op2_p2, mid_op2, mid_p2);
    t3 = new BDS_Triangle(op1_mid, op1_p2, mid_p2);
    t4 = new BDS_Triangle(mid_op2, p1_op2, p1_mid);
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

  if(geom || (mid->g && mid->g->surf))
      snap_point(mid, geom);

  return mid;
}

bool BDS_SwapEdgeTestNonPlanar::operator () (BDS_Edge *e,
					     BDS_Point *p1,BDS_Point *p2,BDS_Point *p3,
					     BDS_Point *q1,BDS_Point *q2,BDS_Point *q3) const
{
  double cb1[3],cb2[3];
  normal_triangle ( p1,p2,p3,cb1);
  normal_triangle ( q1,q2,q3,cb2);  
  BDS_Vector n1 = e->faces(0)->N();
  BDS_Vector n2 = e->faces(1)->N();

  double psc = n1.x * cb1[0] +n1.y * cb1[1] +n1.z * cb1[2];
  if (psc < 0) return false;
  psc = n2.x * cb1[0] +n2.y * cb1[1] +n2.z * cb1[2];
  if (psc < 0) return false;
  psc = n2.x * cb2[0] +n2.y * cb2[1] +n2.z * cb2[2];
  if (psc < 0) return false;
  psc = n1.x * cb2[0] +n1.y * cb2[1] +n1.z * cb2[2];
  if (psc < 0) return false;
  return true;
}

bool BDS_SwapEdgeTestPlanar::operator () (BDS_Edge *e,
					  BDS_Point *p1,BDS_Point *p2,BDS_Point *p3,
					  BDS_Point *q1,BDS_Point *q2,BDS_Point *q3) const
{
  double s1 = surface_triangle ( p1,p2,p3);
  double s2 = surface_triangle ( q1,q2,q3);  
  double n1 = e->faces(0)->S();
  double n2 = e->faces(1)->S();

  if (s1 < 1.e-4 * (n1+n2))return false;
  if (s2 < 1.e-4 * (n1+n2))return false;
  if (fabs(s1+s2 - n1-n2) > 1.e-10 * (s1+s2))return false;

  return true;
}


// This function does actually the swap without taking into account
// the feasability of the operation. Those conditions have to be
// taken into account before doing the edge swap

bool BDS_Mesh::swap_edge(BDS_Edge * e, const BDS_SwapEdgeTest &theTest)
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
  if(e->deleted)
    return false;

  int nbFaces = e->numfaces();
  if(nbFaces != 2)
    return false;

  if(e->g && e->g->classif_degree == 1)
    return false;

  BDS_Point *op[2];
  BDS_Point *p1 = e->p1;
  BDS_Point *p2 = e->p2;
  e->oppositeof(op);

  BDS_GeomEntity *g1 = 0, *g2 = 0, *ge = e->g;

  BDS_Point *pts1[3];
  e->faces(0)->getNodes(pts1);


  // compute the orientation of the face
  // with respect to the edge
  int orientation = 0;
  for(int i = 0; i < 3; i++) {
    if(pts1[i] == p1) {
      if(pts1[(i + 1) % 3] == p2)
        orientation = 1;
      else
        orientation = -1;
      break;
    }
  }

  if(orientation == 1) {
    if (!theTest ( e, p1, op[1], op[0] , op[1], p2, op[0]))
      return false;
  }
  else {
    if (!theTest ( e, p1, op[0], op[1] , op[1], op[0], p2))
      return false;
  }

  BDS_Edge *p1_op1 = find_edge(p1, op[0], e->faces(0));
  BDS_Edge *op1_p2 = find_edge(op[0], p2, e->faces(0));
  BDS_Edge *p1_op2 = find_edge(p1, op[1], e->faces(1));
  BDS_Edge *op2_p2 = find_edge(op[1], p2, e->faces(1));

  if(e->faces(0)) {
    g1 = e->faces(0)->g;
    del_triangle(e->faces(0));
  }
  // not a bug !!!
  if(e->faces(0)) {
    g2 = e->faces(0)->g;
    del_triangle(e->faces(0));
  }
  del_edge(e);


  BDS_Edge *op1_op2 = new BDS_Edge(op[0], op[1]);
  edges.push_back(op1_op2);

  BDS_Triangle *t1, *t2;
  if(orientation == 1) {
    t1 = new BDS_Triangle(p1_op1, p1_op2, op1_op2);
    t2 = new BDS_Triangle(op1_op2, op2_p2, op1_p2);
  }
  else {
    t1 = new BDS_Triangle(p1_op2, p1_op1, op1_op2);
    t2 = new BDS_Triangle(op2_p2, op1_op2, op1_p2);
  }

  t1->g = g1;
  t2->g = g2;

  op1_op2->g = ge;

  triangles.push_back(t1);
  triangles.push_back(t2);
  return true;
}


bool BDS_Mesh::collapse_edge(BDS_Edge * e, BDS_Point * p, const double eps)
{

  if(e->numfaces() != 2)
    return false;
  if(p->g && p->g->classif_degree == 0)
    return false;
  // not really ok but 'til now this is the best choice not to do collapses on model edges
  if(p->g && p->g->classif_degree == 1)
    return false;
  if(e->g && p->g) {
    if(e->g->classif_degree == 2 && p->g != e->g)
      return false;
  }

  std::list < BDS_Triangle * >t;
  BDS_Point *o = e->othervertex(p);

  if(o->g != p->g)
    return false;

  double X = p->X;
  double Y = p->Y;
  double Z = p->Z;

  // printf("collapsing an edge :");
  // print_edge(e);

  static int pt[3][1024];
  static BDS_GeomEntity *gs[1024];
  static int ept[2][1024];
  static BDS_GeomEntity *egs[1024];
  int nt = 0;

  p->getTriangles(t);
  {
    std::list < BDS_Triangle * >::iterator it = t.begin();
    std::list < BDS_Triangle * >::iterator ite = t.end();

    while(it != ite) {
      BDS_Triangle *t = *it;
      //          print_face(t);
      if(t->e1 != e && t->e2 != e && t->e3 != e) {
        BDS_Vector n1, n2;
        BDS_Point *pts[3];
        t->getNodes(pts);
        p->X = o->X;
        p->Y = o->Y;
        p->Z = o->Z;
        double s_after = surface_triangle(pts[0], pts[1], pts[2]);
        n1 = t->N_on_the_fly();
        p->X = X;
        p->Y = Y;
        p->Z = Z;
        n2 = t->N();

	if(n1*n2 < 0) return false;
	
        double s_before = surface_triangle(pts[0], pts[1], pts[2]);
        // normals should not be opposed or change too dramatically
        // this does not concern the triangles with the small edge that
        // are collapsed too
        double angle = n1.angle(n2);
        if(fabs(angle) > M_PI / 12)
          return false;
        if(s_after+s_before < 3.e-1 * fabs(s_before-s_after)) {
          return false;
        }
        if(s_after < 1.e-1 * s_before) {
          return false;
        }
        gs[nt] = t->g;
        pt[0][nt] = (pts[0] == p) ? o->iD : pts[0]->iD;
        pt[1][nt] = (pts[1] == p) ? o->iD : pts[1]->iD;
        pt[2][nt++] = (pts[2] == p) ? o->iD : pts[2]->iD;
      }
      ++it;
    }
  }

  {
    std::list < BDS_Triangle * >::iterator it = t.begin();
    std::list < BDS_Triangle * >::iterator ite = t.end();

    while(it != ite) {
      BDS_Triangle *t = *it;
      del_triangle(t);
      ++it;
    }
  }

  // printf("%d triangles 2 add\n",nt);

  int kk = 0;
  {
    std::list < BDS_Edge * >edges(p->edges);
    std::list < BDS_Edge * >::iterator eit = edges.begin();
    std::list < BDS_Edge * >::iterator eite = edges.end();
    while(eit != eite) {
      ept[0][kk] = ((*eit)->p1 == p) ? o->iD : (*eit)->p1->iD;
      ept[1][kk] = ((*eit)->p2 == p) ? o->iD : (*eit)->p2->iD;
      egs[kk++] = (*eit)->g;
      del_edge(*eit);
      ++eit;
    }
  }

  del_point(p);

  {
    for(int k = 0; k < nt; k++) {
      BDS_Triangle *t = add_triangle(pt[0][k], pt[1][k], pt[2][k]);
      t->g = gs[k];
    }
  }

  for(int i = 0; i < kk; ++i) {
    BDS_Edge *e = find_edge(ept[0][i], ept[1][i]);
    if(e)
      e->g = egs[i];
  }


  return true;
}

bool project_point_on_a_list_of_triangles(BDS_Point * p,
                                          const std::list <
                                          BDS_Triangle * >&t, double &X,
                                          double &Y, double &Z)
{
  bool global_ok = false;

  int p_classif = p->g->classif_tag;
  std::list < BDS_Triangle * >::const_iterator it = t.begin();
  std::list < BDS_Triangle * >::const_iterator ite = t.end();
  double dist2 = 1.e22;
  double XX = p->X;
  double YY = p->Y;
  double ZZ = p->Z;

  while(it != ite) {
    if((*it)->g->classif_tag == p_classif) {
      {
        double xp, yp, zp;
        bool ok =
          proj_point_triangle(p->X, p->Y, p->Z, (*it)->N(), *it, xp, yp, zp);
        if(ok) {
          global_ok = true;
          double d2 =
            ((xp - X) * (xp - X) + (yp - Y) * (yp - Y) + (zp - Z) * (zp - Z));
          if(d2 < dist2) {
            // printf("one found among %d\n",t.size());
            XX = xp;
            YY = yp;
            ZZ = zp;
            dist2 = d2;
          }
        }
        // ok = proj_point_triangle ( p->X,p->Y,p->Z,p->N(),*it,xp,yp,zp);
        // if(ok){
        //     global_ok = true;
        //     double d2 = ((xp-X)*(xp-X)+(yp-Y)*(yp-Y)+(zp-Z)*(zp-Z));
        //     if(d2 < dist2 ){
        //         //              printf("one found among %d\n",t.size());
        //         XX = xp; YY = yp; ZZ = zp;
        //         dist2 = d2;
        //       }
        //   }

      }
    }
    ++it;
  }

  X = XX;
  Y = YY;
  Z = ZZ;
  return global_ok;
}

bool BDS_Mesh::move_point(BDS_Point * p, double X, double Y, double Z)
{
  std::list < BDS_Triangle * >t;
  p->getTriangles(t);
  std::list < BDS_Triangle * >::iterator tit = t.begin();
  std::list < BDS_Triangle * >::iterator tite = t.end();
  const double oldx = p->X;
  const double oldy = p->Y;
  const double oldz = p->Z;
  while(tit != tite) {
    BDS_Vector n1 = (*tit)->N();
    p->X = X;
    p->Y = Y;
    p->Z = Z;
    BDS_Vector n2 = (*tit)->N_on_the_fly();
    p->X = oldx;
    p->Y = oldy;
    p->Z = oldz;

    if (n1*n2 < 0) return false;

    double angle = n1.angle(n2);
    if(fabs(angle) > M_PI / 3)
      return false;
    ++tit;
  }
  p->X = X;
  p->Y = Y;
  p->Z = Z;

  tit = t.begin();
  while(tit != tite) {
    (*tit)->_update();
    ++tit;
  }
  return true;
}

void BDS_Mesh::snap_point(BDS_Point * p, BDS_Mesh * geom_mesh)
{
  double X, Y, Z;
  if(p->g && p->g->surf) {
    p->g->surf->projection(p->X, p->Y, p->Z, X, Y, Z);
    if(move_point(p, X, Y, Z)) {
      SNAP_SUCCESS++;
    }
    else {
      SNAP_FAILURE++;
    }
  }
  else if(p->g && p->g->classif_degree == 2 && geom_mesh) {
    double xx, yy, zz;
    std::list < BDS_Triangle * >l;
    BDS_GeomEntity *gg =
      geom_mesh->get_geom(p->g->classif_tag, p->g->classif_degree);
    gg->getClosestTriangles(p->X, p->Y, p->Z, l, p->radius_of_curvature, xx,
                            yy, zz);

    bool ok = project_point_on_a_list_of_triangles(p, l, X, Y, Z);

    if(!ok) {
      if(move_point(p, xx, yy, zz)) {
        SNAP_SUCCESS++;
      }
      else {
        SNAP_FAILURE++;
      }
    }
    else {
      if(move_point(p, X, Y, Z)) {
        SNAP_SUCCESS++;
      }
      else {
        SNAP_FAILURE++;
      }
    }
  }
  else {
    return;
  }
}

bool BDS_Mesh::smooth_point(BDS_Point * p, BDS_Mesh * geom_mesh)
{

  if(p->g && p->g->classif_degree <= 1)
    return false;
  //  if(!p->g->surf)
  //    return false;


  double X = 0;
  double Y = 0;
  double Z = 0;

  std::list < BDS_Edge * >::iterator eit = p->edges.begin();

  while(eit != p->edges.end()) {
    if ((*eit)->numfaces() == 1) return false;
    BDS_Point *op = ((*eit)->p1 == p) ? (*eit)->p2 : (*eit)->p1;
    X += op->X;
    Y += op->Y;
    Z += op->Z;
    // lengths are wrong;
    (*eit)->target_length = -1;
    ++eit;
  }

  bool success =
    move_point(p, X / p->edges.size(), Y / p->edges.size(),
               Z / p->edges.size());

  if(success)
    snap_point(p, geom_mesh);

  return true;
}

void BDS_Mesh::compute_metric_edge_lengths(const BDS_Metric & metric)
{
  

  // printf("computation of metric lengths\n");
  {
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) {
      if(!(*it)->deleted) {
        (*it)->target_length =
          metric.target_length(0.5 * ((*it)->p2->X + (*it)->p1->X),
                               0.5 * ((*it)->p2->Y + (*it)->p1->Y),
                               0.5 * ((*it)->p2->Z + (*it)->p1->Z));
	BDS_Edge *e = (*it);
	BDS_GeomEntity *g = e->g;
	if (g && g->classif_degree == 1)
	  {
	    double l = (*it)->length() * 1000;
	    if (l < (*it)->target_length)
	      (*it)->target_length =l;
	  }   
      }
      ++it;
    }
  }

  

  {
    std::list < BDS_Edge * >::iterator it = edges.begin();
    std::list < BDS_Edge * >::iterator ite = edges.end();
    while(it != ite) {
      BDS_Edge *e = (*it);
      BDS_GeomEntity *g = e->g;
     
      // do not unrefined curves
      // minimal length is the actual length 
   
        if(g && g->surf) {
        double curvature = g->surf->normalCurv(0.5 * (e->p1->X + e->p2->X),
                                               0.5 * (e->p1->Y + e->p2->Y),
                                               0.5 * (e->p1->Z + e->p2->Z));
        double radius = 1. / curvature;
        double target = radius / metric.nb_elements_per_radius_of_curvature;
        e->target_length =
          metric.update_target_length(target, e->target_length);
        // printf("e1 radius %g target %g length %g mlp %g\n",
	//        radius, target,e->length(),e->length()/target);
      }
      else {
        double radius =
          0.5 * (e->p1->radius_of_curvature + e->p2->radius_of_curvature);
        double target =
          3.14159 * radius / metric.nb_elements_per_radius_of_curvature;
        e->target_length =
          metric.update_target_length(target, e->target_length);
      }
      ++it;
    }
  }
  //  printf("smoothing\n");
  const int NITER = 3;
  const double BETA = metric.beta;

  std::vector<BDS_Point *> temp(points.size());
  std::copy( points.begin(),points.end(),temp.begin());

  for(int I = 0; I < NITER; ++I) {

    std::vector < BDS_Point * >::const_iterator it = temp.begin();
    std::vector < BDS_Point * >::const_iterator ite = temp.end();

    while(it != ite) {

      std::list < BDS_Edge * >::iterator eit = (*it)->edges.begin();
      std::list < BDS_Edge * >::iterator eite = (*it)->edges.end();

      double l_min = metric._max;      

      while(eit != eite) {
	BDS_Edge *ee = (*eit);
        if(l_min > ee->target_length)
          l_min = ee->target_length;
        ++eit;
      }

      l_min /= BETA;

      eit = (*it)->edges.begin();
      while(eit != eite) {
	BDS_Edge *ee = (*eit);
        if(ee->target_length > l_min)
          ee->target_length = l_min;
        ++eit;
      }
      ++it;
    }
  }

  // printf("end computation of metric lengths\n");
}


void BDS_Mesh::applyOptimizationPatterns()
{
  std::set<BDS_Point*, PointLessThan>::iterator it   = points.begin();
  std::set<BDS_Point*, PointLessThan>::iterator ite  = points.end();
  while (it != ite)
    {
      if ((*it)->edges.size() == 3 && (*it)->g->classif_degree == 2)
	{
	  BDS_Edge *e = *((*it)->edges.begin());
	  if (!e->deleted)collapse_edge ( e , *it , .1);
	}
      ++it;
    }
}


int BDS_Mesh::adapt_mesh(const BDS_Metric & metric, bool smooth,
                         BDS_Mesh * geom_mesh)
{
  int nb_modif = 0;
  SNAP_SUCCESS = 0;
  SNAP_FAILURE = 0;

  std::list < BDS_Edge * >small_to_long(edges);

  // split edges
  for(int ii=0;ii<2;ii++){
    std::list < BDS_Edge * >::iterator it = small_to_long.begin();
    std::list < BDS_Edge * >::iterator ite = small_to_long.end();
    compute_metric_edge_lengths(metric);

    while(it != ite) {
      if((*it)->numfaces() == 2) {
        double length = (*it)->length();
        if(!(*it)->deleted && length > (*it)->target_length / 0.7) {
          split_edge(*it, 0.5, geom_mesh);
          nb_modif++;
        }
      }
      ++it;
    }
    cleanup();
    small_to_long = edges;
  }
  
  // collapse 
  for(int ii=0;ii<1;ii++){    	
    std::list<BDS_Edge*>::iterator it = small_to_long.begin();
    std::list<BDS_Edge*>::iterator ite  = small_to_long.end();
    //	compute_metric_edge_lengths (metric);
    
    while (it != ite)
      {
	double length = (*it)->length();
	if (!(*it)->deleted && length < (*it)->target_length * 0.7 ){
	  if (nb_modif %2 )
	    {
	      if (collapse_edge (*it, (*it)->p1, 0.1 ))
		nb_modif++;
	    }
	  else
	    {
	      if (collapse_edge (*it, (*it)->p2, 0.1 ))
		nb_modif++;
	    }
	}
	++it;
      }
    cleanup();  
    small_to_long = edges;
  }
  
  {    
    std::list<BDS_Edge*>::iterator it = small_to_long.begin();
    std::list<BDS_Edge*>::iterator ite  = small_to_long.end();
    while (it != ite)
      {
	if (!(*it)->deleted && (*it)->numfaces()==2)
	  {
	    BDS_Point *op[2];
	    (*it)->oppositeof (op);
	    
	    double qa1 = quality_triangle ( (*it)->p1 , (*it)->p2 , op[0] );
	    double qa2 = quality_triangle ( (*it)->p1 , (*it)->p2 , op[1] );
	    double qb1 = quality_triangle ( (*it)->p1 , op[0] , op[1] );
	    double qb2 = quality_triangle ( (*it)->p2 , op[0] , op[1] );
	    double qa = (qa1<qa2)?qa1:qa2; 
	    double qb = (qb1<qb2)?qb1:qb2; 

	    double dd = dist_droites_gauches((*it)->p1 , (*it)->p2,
					     op[0],op[1]);
	    
	    double ll = (*it)->length();

	    if ((qb > qa && dd < 0.1 * ll) || (qb > 5 * qa))	      
	      {
		nb_modif++;
		swap_edge ( *it , BDS_SwapEdgeTestNonPlanar()) ;
	      }
	  }	
	++it;
      }
  }

  cleanup();  
  if (smooth ){
    Msg(INFO,"smoothing %d points\n",points.size());

    std::vector <BDS_Point *> temp_l(points.size());
    std::copy( points.begin(),points.end(),temp_l.begin());
    std::vector < BDS_Point * >::iterator itx = temp_l.begin();
    std::vector < BDS_Point * >::iterator itxe = temp_l.end();
    while (itx != itxe)
      {
	smooth_point(*itx,geom_mesh);
	++itx;
      }
    printf("coucouc1\n");
  }
  
  Msg(INFO,"%d snaps have succeeded , %d have failed\n",SNAP_SUCCESS,SNAP_FAILURE);
  // outputScalarField (triangles,"b.pos");
   applyOptimizationPatterns(); // FIXME: this is buggy
  cleanup();  
  return nb_modif;
}



BDS_Mesh::BDS_Mesh(const BDS_Mesh & other)
{
  MAXPOINTNUMBER = other.MAXPOINTNUMBER;
  LC = other.LC;
  for(int i = 0; i < 3; i++) {
    Min[i] = other.Min[i];
    Max[i] = other.Max[i];
  }
  for(std::set < BDS_GeomEntity *, GeomLessThan >::const_iterator it =
      other.geom.begin(); it != other.geom.end(); ++it) {
    add_geom((*it)->classif_tag, (*it)->classif_degree);
    BDS_GeomEntity *g = get_geom((*it)->classif_tag, (*it)->classif_degree);
    g->surf = (*it)->surf;
  }
  for(std::set < BDS_Point *, PointLessThan >::const_iterator it =
      other.points.begin(); it != other.points.end(); ++it) {
    BDS_Point *p = add_point((*it)->iD, (*it)->X, (*it)->Y, (*it)->Z);
    p->g =
      ((*it)->g) ? get_geom((*it)->g->classif_tag,
                            (*it)->g->classif_degree) : 0;
    p->radius_of_curvature = (*it)->radius_of_curvature;
    if(p->g->classif_degree == 0)
      p->g->p = p;
  }
  for(std::list < BDS_Edge * >::const_iterator it = other.edges.begin();
      it != other.edges.end(); ++it) {
    BDS_Edge *e = add_edge((*it)->p1->iD, (*it)->p2->iD);
    e->g =
      ((*it)->g) ? get_geom((*it)->g->classif_tag,
                            (*it)->g->classif_degree) : 0;
    if(e->g->classif_degree == 1)
      e->g->e.push_back(e);
    e->partition = (*it)->partition;
  }
  for(std::list < BDS_Triangle * >::const_iterator it =
      other.triangles.begin(); it != other.triangles.end(); ++it) {
    BDS_Point *n[3];
    (*it)->getNodes(n);
    BDS_Triangle *t = add_triangle(n[0]->iD, n[1]->iD, n[2]->iD);
    t->g = get_geom((*it)->g->classif_tag, (*it)->g->classif_degree);
    t->g->t.push_back(t);
    t->partition = (*it)->partition;
  }

  for(std::list < BDS_Tet * >::const_iterator it = other.tets.begin();
      it != other.tets.end(); ++it) {
    BDS_Point *n[4];
    (*it)->getNodes(n);
    BDS_Tet *t = add_tet(n[0]->iD, n[1]->iD, n[2]->iD, n[3]->iD);
    t->g = get_geom((*it)->g->classif_tag, (*it)->g->classif_degree);
    // t->g->t.push_back(t);
    t->partition = (*it)->partition;
  }

}

/*
void BDS_Mesh::recombineIntoQuads (const double angle)
{
  for(std::list < BDS_Edge * >::const_iterator it = edges.begin();
      it != edges.end(); ++it) 
    {
      BDS_Edge *e = *it;
      if (e->numfaces() == 2 
	  && !e->faces(0)->q
	  && !e->faces(1)->q)
	{
	  BDS_Point *op[2];
	  e->oppositeof(op);

	}
    }
  
}
*/
