//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include <list>
#include <set>
#include "AdaptiveViews.h"
#include "Plugin.h"

std::set<adapt_point> adapt_point::all_points;
std::list<adapt_edge*> adapt_edge::all_elems;
std::list<adapt_triangle*> adapt_triangle::all_elems;
std::list<adapt_tet*> adapt_tet::all_elems;
std::list<adapt_quad*> adapt_quad::all_elems;
std::list<adapt_hex*> adapt_hex::all_elems;

int adapt_edge::nbNod = 2;
int adapt_triangle::nbNod = 3;
int adapt_tet::nbNod = 4;
int adapt_quad::nbNod = 4;
int adapt_hex::nbNod = 8;

void computeShapeFunctions(Double_Matrix *coeffs, Double_Matrix *eexps,
                           double u, double v, double w, double *sf)
{
  static double powsuvw[256];
  for(int j = 0; j < coeffs->size2(); ++j) {
    double powu = (*eexps)(j, 0);
    double powv = (*eexps)(j, 1);
    double poww = (*eexps)(j, 2);
    powsuvw[j] = pow(u, powu) * pow(v, powv) * pow(w, poww);
  }

  for(int i = 0; i < coeffs->size1(); ++i) {
    sf[i] = 0.0;
    for(int j = 0; j < coeffs->size2(); ++j) {
      sf[i] += (*coeffs)(i, j) * powsuvw[j];
    }
  }
}

adapt_point *adapt_point::New(double x, double y, double z,
                              Double_Matrix *coeffs, Double_Matrix *eexps)
{
  adapt_point p;
  p.x = x;
  p.y = y;
  p.z = z;
  std::set < adapt_point >::iterator it = all_points.find(p);
  if(it == all_points.end()) {
    all_points.insert(p);
    it = all_points.find(p);
    double *kkk = (double *)(it->shape_functions);
    computeShapeFunctions(coeffs, eexps, x, y, z, kkk);
    return (adapt_point *) &(*it);
  }
  else
    return (adapt_point *) &(*it);
}

void adapt_edge::Create(int maxlevel, Double_Matrix *coeffs,
                        Double_Matrix *eexps)
{
  int level = 0;
  cleanElement<adapt_edge>();
  adapt_point *p1 = adapt_point::New(-1, 0, 0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New(1, 0, 0, coeffs, eexps);
  adapt_edge *t = new adapt_edge(p1, p2);
  Recur_Create(t, maxlevel, level, coeffs, eexps);
}

void adapt_triangle::Create(int maxlevel, Double_Matrix *coeffs,
                            Double_Matrix *eexps)
{
  int level = 0;
  cleanElement<adapt_triangle>();
  adapt_point *p1 = adapt_point::New(0, 0, 0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New(0, 1, 0, coeffs, eexps);
  adapt_point *p3 = adapt_point::New(1, 0, 0, coeffs, eexps);
  adapt_triangle *t = new adapt_triangle(p1, p2, p3);
  Recur_Create(t, maxlevel, level, coeffs, eexps);
}


void adapt_quad::Create(int maxlevel, Double_Matrix *coeffs,
                        Double_Matrix *eexps)
{
  int level = 0;
  cleanElement<adapt_quad>();
  adapt_point *p1 = adapt_point::New(-1, -1, 0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New(1, -1, 0, coeffs, eexps);
  adapt_point *p3 = adapt_point::New(1, 1, 0, coeffs, eexps);
  adapt_point *p4 = adapt_point::New(-1, 1, 0, coeffs, eexps);
  adapt_quad *q = new adapt_quad(p1, p2, p3, p4);
  Recur_Create(q, maxlevel, level, coeffs, eexps);
}

void adapt_tet::Create(int maxlevel, Double_Matrix *coeffs,
                       Double_Matrix *eexps)
{
  int level = 0;
  cleanElement<adapt_tet>();
  adapt_point *p1 = adapt_point::New(0, 0, 0, coeffs, eexps);
  adapt_point *p2 = adapt_point::New(0, 1, 0, coeffs, eexps);
  adapt_point *p3 = adapt_point::New(1, 0, 0, coeffs, eexps);
  adapt_point *p4 = adapt_point::New(0, 0, 1, coeffs, eexps);
  adapt_tet *t = new adapt_tet(p1, p2, p3, p4);
  Recur_Create(t, maxlevel, level, coeffs, eexps);
}

void adapt_hex::Create(int maxlevel, Double_Matrix *coeffs,
                       Double_Matrix *eexps)
{
  int level = 0;
  cleanElement<adapt_hex>();
  adapt_point *p1 = adapt_point::New(-1, -1, -1, coeffs, eexps);
  adapt_point *p2 = adapt_point::New(-1, 1, -1, coeffs, eexps);
  adapt_point *p3 = adapt_point::New(1, 1, -1, coeffs, eexps);
  adapt_point *p4 = adapt_point::New(1, -1, -1, coeffs, eexps);
  adapt_point *p11 = adapt_point::New(-1, -1, 1, coeffs, eexps);
  adapt_point *p21 = adapt_point::New(-1, 1, 1, coeffs, eexps);
  adapt_point *p31 = adapt_point::New(1, 1, 1, coeffs, eexps);
  adapt_point *p41 = adapt_point::New(1, -1, 1, coeffs, eexps);
  adapt_hex *h = new adapt_hex(p1, p2, p3, p4, p11, p21, p31, p41);
  Recur_Create(h, maxlevel, level, coeffs, eexps);
}

void adapt_edge::Recur_Create(adapt_edge *e, int maxlevel, int level,
                              Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all_elems.push_back(e);
  if(level++ >= maxlevel) return;

  /*
     p1    p12    p2
   */

  adapt_point *p1 = e->p[0];
  adapt_point *p2 = e->p[1];
  adapt_point *p12 = adapt_point::New((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5,
				      (p1->z + p2->z) * 0.5, coeffs, eexps);
  adapt_edge *e1 = new adapt_edge(p1, p12);
  Recur_Create(e1, maxlevel, level, coeffs, eexps);
  adapt_edge *e2 = new adapt_edge(p12, p2);
  Recur_Create(e2, maxlevel, level, coeffs, eexps);
  e->e[0] = e1;
  e->e[1] = e2;
}

void adapt_triangle::Recur_Create(adapt_triangle *t, int maxlevel, int level,
                                  Double_Matrix *coeffs,
                                  Double_Matrix *eexps)
{
  all_elems.push_back(t);
  if(level++ >= maxlevel) return;

  /*
     p3

     p13   p23

     p1    p12    p2
   */

  adapt_point *p1 = t->p[0];
  adapt_point *p2 = t->p[1];
  adapt_point *p3 = t->p[2];
  adapt_point *p12 = adapt_point::New((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, 0, 
				      coeffs, eexps);
  adapt_point *p13 = adapt_point::New((p1->x + p3->x) * 0.5, (p1->y + p3->y) * 0.5, 0, 
				      coeffs, eexps);
  adapt_point *p23 = adapt_point::New((p3->x + p2->x) * 0.5, (p3->y + p2->y) * 0.5, 0, 
				      coeffs, eexps);
  adapt_triangle *t1 = new adapt_triangle(p1, p12, p13);
  Recur_Create(t1, maxlevel, level, coeffs, eexps);
  adapt_triangle *t2 = new adapt_triangle(p2, p23, p12);
  Recur_Create(t2, maxlevel, level, coeffs, eexps);
  adapt_triangle *t3 = new adapt_triangle(p3, p13, p23);
  Recur_Create(t3, maxlevel, level, coeffs, eexps);
  adapt_triangle *t4 = new adapt_triangle(p12, p23, p13);
  Recur_Create(t4, maxlevel, level, coeffs, eexps);
  t->e[0] = t1;
  t->e[1] = t2;
  t->e[2] = t3;
  t->e[3] = t4;
}

void adapt_quad::Recur_Create(adapt_quad *q, int maxlevel, int level,
                              Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all_elems.push_back(q);
  if(level++ >= maxlevel) return;

  /*
     p4   p34    p3

     p14  pc     p23

     p1   p12    p2
   */

  adapt_point *p1 = q->p[0];
  adapt_point *p2 = q->p[1];
  adapt_point *p3 = q->p[2];
  adapt_point *p4 = q->p[3];
  adapt_point *p12 = adapt_point::New((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, 0,
				      coeffs, eexps);
  adapt_point *p23 = adapt_point::New((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, 0,
				      coeffs, eexps);
  adapt_point *p34 = adapt_point::New((p3->x + p4->x) * 0.5, (p3->y + p4->y) * 0.5, 0,
				      coeffs, eexps);
  adapt_point *p14 = adapt_point::New((p1->x + p4->x) * 0.5, (p1->y + p4->y) * 0.5, 0, 
				      coeffs, eexps);
  adapt_point *pc = adapt_point::New((p1->x + p2->x + p3->x + p4->x) * 0.25,
				     (p1->y + p2->y + p3->y + p4->y) * 0.25, 0, 
				     coeffs, eexps);
  adapt_quad *q1 = new adapt_quad(p1, p12, pc, p14);
  Recur_Create(q1, maxlevel, level, coeffs, eexps);
  adapt_quad *q2 = new adapt_quad(p2, p23, pc, p12);
  Recur_Create(q2, maxlevel, level, coeffs, eexps);
  adapt_quad *q3 = new adapt_quad(p3, p34, pc, p23);
  Recur_Create(q3, maxlevel, level, coeffs, eexps);
  adapt_quad *q4 = new adapt_quad(p4, p14, pc, p34);
  Recur_Create(q4, maxlevel, level, coeffs, eexps);
  q->e[0] = q1;
  q->e[1] = q2;
  q->e[2] = q3;
  q->e[3] = q4;
}

void adapt_tet::Recur_Create(adapt_tet *t, int maxlevel, int level,
                             Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all_elems.push_back(t);
  if(level++ >= maxlevel) return;

  adapt_point *p0 = t->p[0];
  adapt_point *p1 = t->p[1];
  adapt_point *p2 = t->p[2];
  adapt_point *p3 = t->p[3];
  adapt_point *pe0 =  adapt_point::New((p0->x + p1->x) * 0.5, (p0->y + p1->y) * 0.5,
				       (p0->z + p1->z) * 0.5, coeffs, eexps);
  adapt_point *pe1 =  adapt_point::New((p0->x + p2->x) * 0.5, (p0->y + p2->y) * 0.5,
				       (p0->z + p2->z) * 0.5, coeffs, eexps);
  adapt_point *pe2 =  adapt_point::New((p0->x + p3->x) * 0.5, (p0->y + p3->y) * 0.5,
				       (p0->z + p3->z) * 0.5, coeffs, eexps);
  adapt_point *pe3 =  adapt_point::New((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5,
				       (p1->z + p2->z) * 0.5, coeffs, eexps);
  adapt_point *pe4 =  adapt_point::New((p1->x + p3->x) * 0.5, (p1->y + p3->y) * 0.5,
				       (p1->z + p3->z) * 0.5, coeffs, eexps);
  adapt_point *pe5 =  adapt_point::New((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5,
				       (p2->z + p3->z) * 0.5, coeffs, eexps);

  adapt_tet *t1 = new adapt_tet(p0, pe0, pe2, pe1);
  Recur_Create(t1, maxlevel, level, coeffs, eexps);
  adapt_tet *t2 = new adapt_tet(p1, pe0, pe3, pe4);
  Recur_Create(t2, maxlevel, level, coeffs, eexps);
  adapt_tet *t3 = new adapt_tet(p2, pe3, pe1, pe5);
  Recur_Create(t3, maxlevel, level, coeffs, eexps);
  adapt_tet *t4 = new adapt_tet(p3, pe2, pe4, pe5);
  Recur_Create(t4, maxlevel, level, coeffs, eexps);

  adapt_tet *t5 = new adapt_tet(pe3, pe5, pe2, pe4);
  Recur_Create(t5, maxlevel, level, coeffs, eexps);
  adapt_tet *t6 = new adapt_tet(pe3, pe2, pe0, pe4);
  Recur_Create(t6, maxlevel, level, coeffs, eexps);
  adapt_tet *t7 = new adapt_tet(pe2, pe5, pe3, pe1);
  Recur_Create(t7, maxlevel, level, coeffs, eexps);
  adapt_tet *t8 = new adapt_tet(pe0, pe2, pe3, pe1);
  Recur_Create(t8, maxlevel, level, coeffs, eexps);

  t->e[0] = t1;
  t->e[1] = t2;
  t->e[2] = t3;
  t->e[3] = t4;
  t->e[4] = t5;
  t->e[5] = t6;
  t->e[6] = t7;
  t->e[7] = t8;
}

void adapt_hex::Recur_Create(adapt_hex *h, int maxlevel, int level,
                             Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all_elems.push_back(h);
  if(level++ >= maxlevel) return;

  adapt_point *p0 = h->p[0];
  adapt_point *p1 = h->p[1];
  adapt_point *p2 = h->p[2];
  adapt_point *p3 = h->p[3];
  adapt_point *p4 = h->p[4];
  adapt_point *p5 = h->p[5];
  adapt_point *p6 = h->p[6];
  adapt_point *p7 = h->p[7];
  adapt_point *p01 = adapt_point::New((p0->x + p1->x) * 0.5, (p0->y + p1->y) * 0.5,
				      (p0->z + p1->z) * 0.5, coeffs, eexps);
  adapt_point *p12 = adapt_point::New((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5,
				      (p1->z + p2->z) * 0.5, coeffs, eexps);
  adapt_point *p23 = adapt_point::New((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5,
				      (p2->z + p3->z) * 0.5, coeffs, eexps);
  adapt_point *p03 = adapt_point::New((p3->x + p0->x) * 0.5, (p3->y + p0->y) * 0.5,
				      (p3->z + p0->z) * 0.5, coeffs, eexps);
  adapt_point *p45 = adapt_point::New((p4->x + p5->x) * 0.5, (p4->y + p5->y) * 0.5,
				      (p4->z + p5->z) * 0.5, coeffs, eexps);
  adapt_point *p56 = adapt_point::New((p5->x + p6->x) * 0.5, (p5->y + p6->y) * 0.5,
				      (p5->z + p6->z) * 0.5, coeffs, eexps);
  adapt_point *p67 = adapt_point::New((p6->x + p7->x) * 0.5, (p6->y + p7->y) * 0.5,
				      (p6->z + p7->z) * 0.5, coeffs, eexps);
  adapt_point *p47 = adapt_point::New((p7->x + p4->x) * 0.5, (p7->y + p4->y) * 0.5,
				      (p7->z + p4->z) * 0.5, coeffs, eexps);
  adapt_point *p04 = adapt_point::New((p4->x + p0->x) * 0.5, (p4->y + p0->y) * 0.5,
				      (p4->z + p0->z) * 0.5, coeffs, eexps);
  adapt_point *p15 = adapt_point::New((p5->x + p1->x) * 0.5, (p5->y + p1->y) * 0.5,
				      (p5->z + p1->z) * 0.5, coeffs, eexps);
  adapt_point *p26 = adapt_point::New((p6->x + p2->x) * 0.5, (p6->y + p2->y) * 0.5,
				      (p6->z + p2->z) * 0.5, coeffs, eexps);
  adapt_point *p37 = adapt_point::New((p7->x + p3->x) * 0.5, (p7->y + p3->y) * 0.5,
				      (p7->z + p3->z) * 0.5, coeffs, eexps);

  adapt_point *p0145 = adapt_point::New((p45->x + p01->x) * 0.5, (p45->y + p01->y) * 0.5,
					(p45->z + p01->z) * 0.5, coeffs, eexps);
  adapt_point *p1256 = adapt_point::New((p12->x + p56->x) * 0.5, (p12->y + p56->y) * 0.5,
					(p12->z + p56->z) * 0.5, coeffs, eexps);
  adapt_point *p2367 = adapt_point::New((p23->x + p67->x) * 0.5, (p23->y + p67->y) * 0.5,
					(p23->z + p67->z) * 0.5, coeffs, eexps);
  adapt_point *p0347 = adapt_point::New((p03->x + p47->x) * 0.5, (p03->y + p47->y) * 0.5,
					(p03->z + p47->z) * 0.5, coeffs, eexps);
  adapt_point *p4756 = adapt_point::New((p47->x + p56->x) * 0.5, (p47->y + p56->y) * 0.5,
					(p47->z + p56->z) * 0.5, coeffs, eexps);
  adapt_point *p0312 = adapt_point::New((p03->x + p12->x) * 0.5, (p03->y + p12->y) * 0.5,
					(p03->z + p12->z) * 0.5, coeffs, eexps);

  adapt_point *pc = 
    adapt_point::New((p0->x + p1->x + p2->x + p3->x + p4->x + p5->x + p6->x + p7->x) * 0.125,
		     (p0->y + p1->y + p2->y + p3->y + p4->y + p5->y + p6->y + p7->y) * 0.125,
		     (p0->z + p1->z + p2->z + p3->z + p4->z + p5->z + p6->z + p7->z) * 0.125,
		     coeffs, eexps);

  adapt_hex *h1 = new adapt_hex(p0, p01, p0312, p03, p04, p0145, pc, p0347);    //p0
  Recur_Create(h1, maxlevel, level, coeffs, eexps);
  adapt_hex *h2 = new adapt_hex(p01, p0145, p15, p1, p0312, pc, p1256, p12);    //p1
  Recur_Create(h2, maxlevel, level, coeffs, eexps);
  adapt_hex *h3 = new adapt_hex(p04, p4, p45, p0145, p0347, p47, p4756, pc);    //p4
  Recur_Create(h3, maxlevel, level, coeffs, eexps);
  adapt_hex *h4 = new adapt_hex(p0145, p45, p5, p15, pc, p4756, p56, p1256);    //p5
  Recur_Create(h4, maxlevel, level, coeffs, eexps);
  adapt_hex *h5 = new adapt_hex(p0347, p47, p4756, pc, p37, p7, p67, p2367);    //p7
  Recur_Create(h5, maxlevel, level, coeffs, eexps);
  adapt_hex *h6 = new adapt_hex(pc, p4756, p56, p1256, p2367, p67, p6, p26);    //p6
  Recur_Create(h6, maxlevel, level, coeffs, eexps);
  adapt_hex *h7 = new adapt_hex(p03, p0347, pc, p0312, p3, p37, p2367, p23);    //p3
  Recur_Create(h7, maxlevel, level, coeffs, eexps);
  adapt_hex *h8 = new adapt_hex(p0312, pc, p1256, p12, p23, p2367, p26, p2);    //p2
  Recur_Create(h8, maxlevel, level, coeffs, eexps);

  h->e[0] = h1;
  h->e[1] = h2;
  h->e[2] = h3;
  h->e[3] = h4;
  h->e[4] = h5;
  h->e[5] = h6;
  h->e[6] = h7;
  h->e[7] = h8;
}

void adapt_edge::Error(double AVG, double tol)
{
  adapt_edge *e = *all_elems.begin();
  Recur_Error(e, AVG, tol);
}

void adapt_triangle::Error(double AVG, double tol)
{
  adapt_triangle *t = *all_elems.begin();
  Recur_Error(t, AVG, tol);
}

void adapt_quad::Error(double AVG, double tol)
{
  adapt_quad *q = *all_elems.begin();
  Recur_Error(q, AVG, tol);
}

void adapt_tet::Error(double AVG, double tol)
{
  adapt_tet *t = *all_elems.begin();
  Recur_Error(t, AVG, tol);
}
void adapt_hex::Error(double AVG, double tol)
{
  adapt_hex *h = *all_elems.begin();
  Recur_Error(h, AVG, tol);
}

void adapt_edge::Recur_Error(adapt_edge *e, double AVG, double tol)
{
  if(!e->e[0])
    e->visible = true;
  else {
    double vr;
    if(!e->e[0]->e[0]) {
      double v1 = e->e[0]->V();
      double v2 = e->e[1]->V();
      vr = (v1 + v2) / 2.;
      double v = e->V();
      if(fabs(v - vr) > AVG * tol){
        e->visible = false;
        Recur_Error(e->e[0], AVG, tol);
        Recur_Error(e->e[1], AVG, tol);
      }
      else
        e->visible = true;
    }
    else {
      double v11 = e->e[0]->e[0]->V();
      double v12 = e->e[0]->e[1]->V();

      double v21 = e->e[1]->e[0]->V();
      double v22 = e->e[1]->e[1]->V();

      double vr1 = (v11 + v12) / 2.;
      double vr2 = (v21 + v22) / 2.;
      vr = (vr1 + vr2) / 2.;
      if(fabs(e->e[0]->V() - vr1) > AVG * tol ||
         fabs(e->e[1]->V() - vr2) > AVG * tol ||
         fabs(e->V() - vr) > AVG * tol) {
        e->visible = false;
        Recur_Error(e->e[0], AVG, tol);
        Recur_Error(e->e[1], AVG, tol);
      }
      else
        e->visible = true;
    }
  }
}

void adapt_triangle::Recur_Error(adapt_triangle *t, double AVG, double tol)
{
  if(!t->e[0])
    t->visible = true;
  else {
    double vr;
    if(!t->e[0]->e[0]) {
      double v1 = t->e[0]->V();
      double v2 = t->e[1]->V();
      double v3 = t->e[2]->V();
      double v4 = t->e[3]->V();
      vr = (2 * v1 + 2 * v2 + 2 * v3 + v4) / 7.;
      double v = t->V();
      if(fabs(v - vr) > AVG * tol){
        t->visible = false;
        Recur_Error(t->e[0], AVG, tol);
        Recur_Error(t->e[1], AVG, tol);
        Recur_Error(t->e[2], AVG, tol);
        Recur_Error(t->e[3], AVG, tol);
      }
      else
        t->visible = true;
    }
    else {
      double v11 = t->e[0]->e[0]->V();
      double v12 = t->e[0]->e[1]->V();
      double v13 = t->e[0]->e[2]->V();
      double v14 = t->e[0]->e[3]->V();
      double v21 = t->e[1]->e[0]->V();
      double v22 = t->e[1]->e[1]->V();
      double v23 = t->e[1]->e[2]->V();
      double v24 = t->e[1]->e[3]->V();
      double v31 = t->e[2]->e[0]->V();
      double v32 = t->e[2]->e[1]->V();
      double v33 = t->e[2]->e[2]->V();
      double v34 = t->e[2]->e[3]->V();
      double v41 = t->e[3]->e[0]->V();
      double v42 = t->e[3]->e[1]->V();
      double v43 = t->e[3]->e[2]->V();
      double v44 = t->e[3]->e[3]->V();
      double vr1 = (2 * v11 + 2 * v12 + 2 * v13 + v14) / 7.;
      double vr2 = (2 * v21 + 2 * v22 + 2 * v23 + v24) / 7.;
      double vr3 = (2 * v31 + 2 * v32 + 2 * v33 + v34) / 7.;
      double vr4 = (2 * v41 + 2 * v42 + 2 * v43 + v44) / 7.;
      vr = (2 * vr1 + 2 * vr2 + 2 * vr3 + vr4) / 7.;
      if(fabs(t->e[0]->V() - vr1) > AVG * tol ||
         fabs(t->e[1]->V() - vr2) > AVG * tol ||
         fabs(t->e[2]->V() - vr3) > AVG * tol ||
         fabs(t->e[3]->V() - vr4) > AVG * tol ||
         fabs(t->V() - vr) > AVG * tol){
        t->visible = false;
        Recur_Error(t->e[0], AVG, tol);
        Recur_Error(t->e[1], AVG, tol);
        Recur_Error(t->e[2], AVG, tol);
        Recur_Error(t->e[3], AVG, tol);
      }
      else
        t->visible = true;
    }
  }
}

void adapt_quad::Recur_Error(adapt_quad *q, double AVG, double tol)
{
  if(!q->e[0])
    q->visible = true;
  else {
    double vr;
    if(!q->e[0]->e[0]) {
      double v1 = q->e[0]->V();
      double v2 = q->e[1]->V();
      double v3 = q->e[2]->V();
      double v4 = q->e[3]->V();
      vr = (v1 + v2 + v3 + v4) / 4.;
      double v = q->V();
      if(fabs(v - vr) > AVG * tol){
        q->visible = false;
        Recur_Error(q->e[0], AVG, tol);
        Recur_Error(q->e[1], AVG, tol);
        Recur_Error(q->e[2], AVG, tol);
        Recur_Error(q->e[3], AVG, tol);
      }
      else
        q->visible = true;
    }
    else {
      double v11 = q->e[0]->e[0]->V();
      double v12 = q->e[0]->e[1]->V();
      double v13 = q->e[0]->e[2]->V();
      double v14 = q->e[0]->e[3]->V();
      double v21 = q->e[1]->e[0]->V();
      double v22 = q->e[1]->e[1]->V();
      double v23 = q->e[1]->e[2]->V();
      double v24 = q->e[1]->e[3]->V();
      double v31 = q->e[2]->e[0]->V();
      double v32 = q->e[2]->e[1]->V();
      double v33 = q->e[2]->e[2]->V();
      double v34 = q->e[2]->e[3]->V();
      double v41 = q->e[3]->e[0]->V();
      double v42 = q->e[3]->e[1]->V();
      double v43 = q->e[3]->e[2]->V();
      double v44 = q->e[3]->e[3]->V();
      double vr1 = (v11 + v12 + v13 + v14) / 4.;
      double vr2 = (v21 + v22 + v23 + v24) / 4.;
      double vr3 = (v31 + v32 + v33 + v34) / 4.;
      double vr4 = (v41 + v42 + v43 + v44) / 4.;
      vr = (vr1 + vr2 + vr3 + vr4) / 4.;
      if(fabs(q->e[0]->V() - vr1) > AVG * tol ||
         fabs(q->e[1]->V() - vr2) > AVG * tol ||
         fabs(q->e[2]->V() - vr3) > AVG * tol ||
         fabs(q->e[3]->V() - vr4) > AVG * tol ||
         fabs(q->V() - vr) > AVG * tol){
        q->visible = false;
        Recur_Error(q->e[0], AVG, tol);
        Recur_Error(q->e[1], AVG, tol);
        Recur_Error(q->e[2], AVG, tol);
        Recur_Error(q->e[3], AVG, tol);
      }
      else
        q->visible = true;
    }
  }
}

void adapt_tet::Recur_Error(adapt_tet *t, double AVG, double tol)
{
  if(!t->e[0])
    t->visible = true;
  else {
    const double v1 = t->e[0]->V();
    const double v2 = t->e[1]->V();
    const double v3 = t->e[2]->V();
    const double v4 = t->e[3]->V();
    const double v5 = t->e[4]->V();
    const double v6 = t->e[5]->V();
    const double v7 = t->e[6]->V();
    const double v8 = t->e[7]->V();
    const double vr = (v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8) * .125;
    const double v = t->V();
    if(!t->e[0]->e[0]) {
      if(fabs(v - vr) > AVG * tol) {
        t->visible = false;
        Recur_Error(t->e[0], AVG, tol);
        Recur_Error(t->e[1], AVG, tol);
        Recur_Error(t->e[2], AVG, tol);
        Recur_Error(t->e[3], AVG, tol);
        Recur_Error(t->e[4], AVG, tol);
        Recur_Error(t->e[5], AVG, tol);
        Recur_Error(t->e[6], AVG, tol);
        Recur_Error(t->e[7], AVG, tol);
      }
      else
        t->visible = true;
    }
    else {
      double vi[8][8];
      for(int k = 0; k < 8; k++)
        for(int l = 0; l < 8; l++)
          vi[k][l] = t->e[k]->e[l]->V();
      double vri[8];
      for(int k = 0; k < 8; k++) {
        vri[k] = 0.0;
        for(int l = 0; l < 8; l++) {
          vri[k] += vi[k][l];
        }
        vri[k] /= 8.0;
      }
      if(fabs(t->e[0]->V() - vri[0]) > AVG * tol ||
         fabs(t->e[1]->V() - vri[1]) > AVG * tol ||
         fabs(t->e[2]->V() - vri[2]) > AVG * tol ||
         fabs(t->e[3]->V() - vri[3]) > AVG * tol ||
         fabs(t->e[4]->V() - vri[4]) > AVG * tol ||
         fabs(t->e[5]->V() - vri[5]) > AVG * tol ||
         fabs(t->e[6]->V() - vri[6]) > AVG * tol ||
         fabs(t->e[7]->V() - vri[7]) > AVG * tol ||
         fabs(v - vr) > AVG * tol) {
        t->visible = false;
        Recur_Error(t->e[0], AVG, tol);
        Recur_Error(t->e[1], AVG, tol);
        Recur_Error(t->e[2], AVG, tol);
        Recur_Error(t->e[3], AVG, tol);
        Recur_Error(t->e[4], AVG, tol);
        Recur_Error(t->e[5], AVG, tol);
        Recur_Error(t->e[6], AVG, tol);
        Recur_Error(t->e[7], AVG, tol);
      }
      else
        t->visible = true;
    }
  }
}

void adapt_hex::Recur_Error(adapt_hex *h, double AVG, double tol)
{
  if(!h->e[0])
    h->visible = true;
  else {
    double vr;
    double v1 = h->e[0]->V();
    double v2 = h->e[1]->V();
    double v3 = h->e[2]->V();
    double v4 = h->e[3]->V();
    double v5 = h->e[4]->V();
    double v6 = h->e[5]->V();
    double v7 = h->e[6]->V();
    double v8 = h->e[7]->V();
    vr = (v1 + v2 + v3 + v4 + v5 + v6 + v7 + v8) * .125;
    double v = h->V();
    if(fabs(v - vr) > AVG * tol) {
      h->visible = false;
      Recur_Error(h->e[0], AVG, tol);
      Recur_Error(h->e[1], AVG, tol);
      Recur_Error(h->e[2], AVG, tol);
      Recur_Error(h->e[3], AVG, tol);
      Recur_Error(h->e[4], AVG, tol);
      Recur_Error(h->e[5], AVG, tol);
      Recur_Error(h->e[6], AVG, tol);
      Recur_Error(h->e[7], AVG, tol);
    }
    else
      h->visible = true;
  }
}

template < class ELEM >
int Adaptive_Post_View::zoomElement(int ielem,
				    int level,
				    int levelmax,
				    GMSH_Post_Plugin *plug,
				    List_T *theList, int *counter)
{
  const int nbNod = ELEM::nbNod;

  typename std::set<adapt_point>::iterator it = adapt_point::all_points.begin();
  typename std::set<adapt_point>::iterator ite = adapt_point::all_points.end();

  const int N = _coefs->size1();
  
  Double_Vector val(N), res(adapt_point::all_points.size());
  Double_Vector valx(N), resx(adapt_point::all_points.size());
  Double_Vector valy(N), resy(adapt_point::all_points.size());
  Double_Vector valz(N), resz(adapt_point::all_points.size());
  Double_Matrix xyz(_STposX->size2(),3);
  Double_Matrix XYZ(adapt_point::all_points.size(),3);

  for(int k = 0; k < _STposX->size2(); ++k){
    xyz(k, 0) = (*_STposX)(ielem, k);
    xyz(k, 1) = (*_STposY)(ielem, k);
    xyz(k, 2) = (*_STposZ)(ielem, k);
  }

  for(int k = 0; k < N; ++k){
    val(k) = (*_STval)(ielem, k);
  }

  _Interpolate->mult(val,res);

  if(_STvalX){
    for(int k = 0; k < N; ++k){
      valx(k) = (*_STvalX)(ielem, k);
      valy(k) = (*_STvalY)(ielem, k);
      valz(k) = (*_STvalZ)(ielem, k);
    }	        
    _Interpolate->mult(valx, resx);
    _Interpolate->mult(valy, resy);
    _Interpolate->mult(valz, resz);
  }

  _Geometry->mult(xyz, XYZ);

  int kk = 0;
  for(; it !=ite; ++it){
    adapt_point *p = (adapt_point*) &(*it);
    p->val = res(kk);
    if(_STvalX){
      p->valx = resx(kk);
      p->valy = resy(kk);
      p->valz = resz(kk);
    }
    p->val = res(kk);
    p->X = XYZ(kk, 0);
    p->Y = XYZ(kk, 1);
    p->Z = XYZ(kk, 2);
    if(minval > p->val) minval = p->val;
    if(maxval < p->val) maxval = p->val;
    kk++;
  }

  typename std::list<ELEM*>::iterator itt = ELEM::all_elems.begin();
  typename std::list<ELEM*>::iterator itte = ELEM::all_elems.end();

  for(; itt != itte; itt++) {
    (*itt)->visible = false;
  }

  if(!plug || tol != 0.0) {
    ELEM::Error(maxval - minval, tol);
  }

  if(plug)
    plug->assignSpecificVisibility();

  itt = ELEM::all_elems.begin();

   for(; itt != itte; itt++) {
     if((*itt)->visible && !(*itt)->e[0] && level != levelmax)
       return 0;
   }

  itt = ELEM::all_elems.begin();
  adapt_point **p;

  for(; itt != itte; itt++){
    if((*itt)->visible){
      p = (*itt)->p;
      for(int k=0; k < nbNod; ++k) List_Add(theList, &p[k]->X);
      for(int k=0; k < nbNod; ++k) List_Add(theList, &p[k]->Y);
      for(int k=0; k < nbNod; ++k) List_Add(theList, &p[k]->Z);
      if(_STvalX){
	for(int k = 0; k < nbNod; ++k){
	  List_Add(theList, &p[k]->valx);
	  List_Add(theList, &p[k]->valy);
	  List_Add(theList, &p[k]->valz);
	}
      }
      else{
	for (int k = 0; k < nbNod; ++k) List_Add(theList, &p[k]->val);
      }
      (*counter)++;
    }
  }
  
  return 1;
}

/*
  We first do the adaptive stuff at level 2 and will only process
  elements that have reached the maximal recursion level

  We compute first the matrix at max recursion level (those should be
  stored on disk once in the GMSHPLUGINSHOME directory, i'll do that
  at some point).
*/

void Adaptive_Post_View::setAdaptiveResolutionLevel(PViewDataList *data, int level,
                                                    GMSH_Post_Plugin *plug)
{

  if(presentTol == tol && presentZoomLevel == level && !plug) return;

  int *done = new int[_STposX->size1()];
  for(int i = 0; i < _STposX->size1(); ++i)
    done[i] = 0;
  int level_act = (level > 2) ? 2 : level;
  int nbelm = _STposX->size1();

  int TYP = 0;
  if(data->NbSL) {
    TYP = 7;
    List_Delete(data->SL);
    data->NbSL = 0;
    data->SL = List_Create(nbelm * 8, nbelm, sizeof(double));
  }
  if(data->NbVT) {
    TYP = 5;
    List_Delete(data->VT); 
    data->NbVT = 0;
    data->VT = List_Create(nbelm * 36, nbelm , sizeof(double));	
  }
  else if(data->NbST) {
    TYP = 1;
    List_Delete(data->ST);
    data->NbST = 0;
    data->ST = List_Create(nbelm * 4, nbelm, sizeof(double));
  }
  if(data->NbSS) {
    TYP = 3;
    List_Delete(data->SS);
    data->NbSS = 0;
    data->SS = List_Create(nbelm * 4, nbelm, sizeof(double));
  }
  if(data->NbSQ) {
    TYP = 2;
    List_Delete(data->SQ);
    data->NbSQ = 0;
    data->SQ = List_Create(nbelm * 20, nbelm * 20, sizeof(double));
  }
  if(data->NbVQ) {
    TYP = 6;
    List_Delete(data->VQ);
    data->NbVQ = 0;
    data->VQ = List_Create(nbelm * 60, nbelm * 20, sizeof(double));
  }
  if(data->NbSH) {
    TYP = 4;
    List_Delete(data->SH);
    data->NbSH = 0;
    data->SH = List_Create(nbelm * 4, nbelm, sizeof(double));
  }

  data->NbTimeStep = 1;

  while(1){
    if(TYP == 7)
      setAdaptiveResolutionLevel_TEMPL<adapt_edge>(level_act, level, plug, 
						   &(data->SL), &(data->NbSL), done);
    if(TYP == 1)
      setAdaptiveResolutionLevel_TEMPL<adapt_triangle>(level_act, level, plug,
						       &(data->ST), &(data->NbST), done);
    if(TYP == 5)
      setAdaptiveResolutionLevel_TEMPL<adapt_triangle>(level_act, level, plug,
						       &(data->VT), &(data->NbVT), done);
    if(TYP == 2)
      setAdaptiveResolutionLevel_TEMPL<adapt_quad>(level_act, level, plug,
						   &(data->SQ), &(data->NbSQ), done);
    if(TYP == 6)
      setAdaptiveResolutionLevel_TEMPL<adapt_quad>(level_act, level, plug,
						   &(data->VQ), &(data->NbVQ), done);
    if(TYP == 4)
      setAdaptiveResolutionLevel_TEMPL<adapt_hex>(level_act, level, plug,
						  &(data->SH), &(data->NbSH), done);
    if(TYP == 3)
      setAdaptiveResolutionLevel_TEMPL<adapt_tet>(level_act, level, plug,
						  &(data->SS), &(data->NbSS), done);
    int nbDone = 0;
    for(int i = 0; i < _STposX->size1(); ++i) nbDone += done[i];
    if(nbDone == _STposX->size1())  break;
    if(level_act >= level) break;
    level_act++;
  }

  data->finalize();

  presentZoomLevel = level;
  presentTol = tol;

  delete [] done;
}

template<class ELEM> 
void Adaptive_Post_View::setAdaptiveResolutionLevel_TEMPL(int level, int levelmax,
							  GMSH_Post_Plugin *plug,
							  List_T **myList,
							  int *counter, int *done)
{
  const int N = _coefs->size1();
  const int nbelm = _STposX->size1();

  double sf[100];
  ELEM::Create(level, _coefs, _eexps);
  std::set<adapt_point>::iterator it = adapt_point::all_points.begin();
  std::set<adapt_point>::iterator ite = adapt_point::all_points.end();

  if(_Interpolate)
    delete _Interpolate;
  if(_Geometry)
    delete _Geometry;
  _Interpolate = new Double_Matrix(adapt_point::all_points.size(), N);
  _Geometry = new Double_Matrix(adapt_point::all_points.size(), _STposX->size2());

  int kk = 0;
  for(; it != ite; ++it) {
    adapt_point *p = (adapt_point *) & (*it);
    for(int k = 0; k < N; ++k) {
      (*_Interpolate)(kk, k) = p->shape_functions[k];
    }

    if(_coefsGeom){
      computeShapeFunctions(_coefsGeom, _eexpsGeom, p->x, p->y, p->z, sf);
    }
    else{
      ELEM::GSF(p->x, p->y, p->z, sf);
    }
    for(int k = 0; k < _STposX->size2(); k++)
      (*_Geometry) (kk, k) = sf[k];
    kk++;
  }

  for(int i = 0; i < nbelm; ++i) {//    if(!done[i])
      done[i] = zoomElement<ELEM>(i, level, levelmax, plug, *myList, counter);
  }
}

void Adaptive_Post_View::initWithLowResolution(PViewDataList *data)
{
  List_T *myList;
  int nbelm;
  int nbnod;
  int nbComp = 1;

  if(data->NbST){
    myList = data->ST;
    nbelm = data->NbST;
    nbnod = 3;
  }
  else if(data->NbSL){
    myList = data->SL;
    nbelm = data->NbSL;
    nbnod = 2;
  }
  else if(data->NbVT){
    myList = data->VT;
    nbelm = data->NbVT;
    nbnod = 3;
    nbComp = 3;
  }
  else if(data->NbVQ){
    myList = data->VQ;
    nbelm = data->NbVQ;
    nbnod = 4;
    nbComp = 3;
  }
  else if(data->NbSS){
    myList = data->SS;
    nbelm = data->NbSS;
    nbnod = 4;
  }
  else if(data->NbSQ){
    myList = data->SQ;
    nbelm = data->NbSQ;
    nbnod = 4;
  }
  else if(data->NbSH){
    myList = data->SH;
    nbelm = data->NbSH;
    nbnod = 8;
  }
	else if(data->NbSI){
		myList = data->SI;
		nbelm = data->NbSI;
		nbnod = 6;
	}
	else if(data->NbVI){
		myList = data->VI;
		nbelm = data->NbVI;
		nbnod = 6;
	}
  else return;

  // if there exists a polynomial representation
  // of the geometry , then use it
  if(_coefsGeom){
    nbnod = _coefsGeom->size1();
  }  

  minval = VAL_INF;
  maxval = -VAL_INF;

  int nb = List_Nbr(myList) / (nbelm);

  _STposX = new Double_Matrix(nbelm, nbnod);
  _STposY = new Double_Matrix(nbelm, nbnod);
  _STposZ = new Double_Matrix(nbelm, nbnod);
  _STval = new Double_Matrix(nbelm, (nb - 3 * nbnod) / nbComp);

  if(nbComp == 3){
    _STvalX = new Double_Matrix(nbelm, (nb - 3 * nbnod) / nbComp);
    _STvalY = new Double_Matrix(nbelm, (nb - 3 * nbnod) / nbComp);
    _STvalZ = new Double_Matrix(nbelm, (nb - 3 * nbnod) / nbComp);
  }

  // Store non interpolated data
  int k = 0;
  for(int i = 0; i < List_Nbr(myList); i+= nb){    
    double *x = (double*)List_Pointer_Fast(myList, i);
    double *y = (double*)List_Pointer_Fast(myList, i + nbnod); 
    double *z = (double*)List_Pointer_Fast(myList, i + 2 * nbnod); 
    for(int NN = 0; NN < nbnod; NN++){
      (*_STposX)(k, NN) = x[NN]; 
      (*_STposY)(k, NN) = y[NN]; 
      (*_STposZ)(k, NN) = z[NN]; 
    }
    double *val = (double*)List_Pointer_Fast(myList, i + 3 * nbnod);
    if(nbComp == 1){
      for(int j = 0; j < (nb - 3 * nbnod) / nbComp; j++){
	(*_STval)(k, j) = val[j];
      }      	  
    }
    else if(nbComp == 3){
      int size = (nb - 3 * nbnod) / 3;
      for(int j = 0; j < size; j++){
	int index1 = j;
	int index2 = j + size;
	int index3 = j + 2 * size;
	// adaptation of the visualization mesh bases on the norm squared of the vector 
	(*_STval)(k, j) = (val[index1] * val[index1] + val[index2] * val[index2] + 
			   val[index3] * val[index3]);      
	(*_STvalX)(k, j) = val[index1];
	(*_STvalY)(k, j) = val[index2];
	(*_STvalZ)(k, j) = val[index3];
      }      	  	  
    }
    k++;
  }
  setAdaptiveResolutionLevel(data, 0);
}

Adaptive_Post_View::Adaptive_Post_View(PViewDataList *data, 
				       List_T *_c,
                                       List_T *_pol,
				       List_T *_cGeom,
				       List_T *_polGeom)
  : tol(1.e-3), _coefsGeom(0), _eexpsGeom(0)
{

  _Interpolate = _Geometry = 0;
  _coefs = new Double_Matrix(List_Nbr(_c), List_Nbr(_c));
  _eexps = new Double_Matrix(List_Nbr(_c), 3);

  _STvalX = _STvalY = _STvalZ =0;

  for(int i = 0; i < List_Nbr(_c); ++i) {
    List_T **line = (List_T**)List_Pointer_Fast(_c, i);
    List_T **eexp = (List_T**)List_Pointer_Fast(_pol, i);

    double dpowu, dpowv, dpoww;

    List_Read(*eexp, 0, &dpowu);
    List_Read(*eexp, 1, &dpowv);
    List_Read(*eexp, 2, &dpoww);

    (*_eexps)(i, 0) = dpowu;
    (*_eexps)(i, 1) = dpowv;
    (*_eexps)(i, 2) = dpoww;

    for(int j = 0; j < List_Nbr(*line); ++j) {
      double val;
      List_Read(*line, j, &val);
      (*_coefs)(i, j) = val;
    }
  }

  if(_cGeom && _polGeom){
    _coefsGeom = new Double_Matrix(List_Nbr(_cGeom), List_Nbr(_cGeom));
    _eexpsGeom = new Double_Matrix(List_Nbr(_cGeom), 3);
    for(int i = 0; i < List_Nbr(_cGeom); ++i) {
      List_T **line = (List_T**)List_Pointer_Fast(_cGeom, i);
      List_T **eexp = (List_T**)List_Pointer_Fast(_polGeom, i);
      double dpowu, dpowv, dpoww;
      List_Read(*eexp, 0, &dpowu);
      List_Read(*eexp, 1, &dpowv);
      List_Read(*eexp, 2, &dpoww);
      (*_eexpsGeom)(i, 0) = dpowu;
      (*_eexpsGeom)(i, 1) = dpowv;
      (*_eexpsGeom)(i, 2) = dpoww;
      for(int j = 0; j < List_Nbr(*line); ++j) {
	double val;
	List_Read(*line, j, &val);
	(*_coefsGeom)(i, j) = val;
      }
    }      
  }
  initWithLowResolution(data);
}

Adaptive_Post_View::~Adaptive_Post_View()
{
  delete _coefs;
  delete _eexps;
  delete _STposX;
  delete _STposY;
  delete _STposZ;
  delete _STval;

  if(_coefsGeom)
    delete _coefsGeom;
  if(_eexpsGeom)
    delete _eexpsGeom;

  if(_Interpolate)
    delete _Interpolate;
  if(_Geometry)
    delete _Geometry;

  cleanElement<adapt_edge>();
  cleanElement<adapt_triangle>();
  cleanElement<adapt_tet>();
  cleanElement<adapt_hex>();
  cleanElement<adapt_quad>();
}
