// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include <list>
#include <set>
#include "Plugin.h"
#include "adaptiveData.h"

std::set<adaptivePoint> adaptivePoint::all;
std::list<adaptiveLine*> adaptiveLine::all;
std::list<adaptiveTriangle*> adaptiveTriangle::all;
std::list<adaptiveQuadrangle*> adaptiveQuadrangle::all;
std::list<adaptiveTetrahedron*> adaptiveTetrahedron::all;
std::list<adaptiveHexahedron*> adaptiveHexahedron::all;
std::list<adaptivePrism*> adaptivePrism::all;

int adaptiveLine::numNodes = 2;
int adaptiveTriangle::numNodes = 3;
int adaptiveQuadrangle::numNodes = 4;
int adaptivePrism::numNodes = 6;
int adaptiveTetrahedron::numNodes = 4;
int adaptiveHexahedron::numNodes = 8;

int adaptiveLine::numEdges = 1;
int adaptiveTriangle::numEdges = 3;
int adaptiveQuadrangle::numEdges = 4;
int adaptivePrism::numEdges = 9;
int adaptiveTetrahedron::numEdges = 6;
int adaptiveHexahedron::numEdges = 12;

template <class T>
static void cleanElement()
{  
  for(typename std::list<T*>::iterator it = T::all.begin(); it != T::all.end(); ++it)
    delete *it;
  T::all.clear();
  adaptivePoint::all.clear();
}

static void computeShapeFunctions(Double_Matrix *coeffs, Double_Matrix *eexps,
				  double u, double v, double w, double *sf)
{
  static double powsuvw[256];
  for(int j = 0; j < eexps->size1(); ++j) {
    powsuvw[j] = pow(u, (*eexps)(j, 0));
    if(eexps->size2() > 1) powsuvw[j] *= pow(v, (*eexps)(j, 1));
    if(eexps->size2() > 2) powsuvw[j] *= pow(w, (*eexps)(j, 2));
  }
  for(int i = 0; i < coeffs->size1(); ++i) {
    sf[i] = 0.;
    for(int j = 0; j < coeffs->size2(); ++j) {
      sf[i] += (*coeffs)(i, j) * powsuvw[j];
    }
  }
}

adaptivePoint *adaptivePoint::create(double x, double y, double z,
				     Double_Matrix *coeffs, Double_Matrix *eexps)
{
  adaptivePoint p;
  p.x = x;
  p.y = y;
  p.z = z;
  std::set<adaptivePoint>::iterator it = all.find(p);
  if(it == all.end()) {
    all.insert(p);
    it = all.find(p);
    computeShapeFunctions(coeffs, eexps, x, y, z, (double*)it->shapeFunctions);
  }
  return (adaptivePoint*)&(*it);
}

void adaptiveLine::create(int maxlevel, 
			  Double_Matrix *coeffs, Double_Matrix *eexps)
{
  cleanElement<adaptiveLine>();
  adaptivePoint *p1 = adaptivePoint::create(-1, 0, 0, coeffs, eexps);
  adaptivePoint *p2 = adaptivePoint::create(1, 0, 0, coeffs, eexps);
  adaptiveLine *t = new adaptiveLine(p1, p2);
  recurCreate(t, maxlevel, 0, coeffs, eexps);
}

void adaptiveLine::recurCreate(adaptiveLine *e, int maxlevel, int level,
			       Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all.push_back(e);
  if(level++ >= maxlevel) return;

  // p1    p12    p2
  adaptivePoint *p1 = e->p[0];
  adaptivePoint *p2 = e->p[1];
  adaptivePoint *p12 = adaptivePoint::create
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     coeffs, eexps);
  adaptiveLine *e1 = new adaptiveLine(p1, p12);
  recurCreate(e1, maxlevel, level, coeffs, eexps);
  adaptiveLine *e2 = new adaptiveLine(p12, p2);
  recurCreate(e2, maxlevel, level, coeffs, eexps);
  e->e[0] = e1;
  e->e[1] = e2;
}

void adaptiveLine::error(double AVG, double tol)
{
  adaptiveLine *e = *all.begin();
  recurError(e, AVG, tol);
}

void adaptiveLine::recurError(adaptiveLine *e, double AVG, double tol)
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
        recurError(e->e[0], AVG, tol);
        recurError(e->e[1], AVG, tol);
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
        recurError(e->e[0], AVG, tol);
        recurError(e->e[1], AVG, tol);
      }
      else
        e->visible = true;
    }
  }
}

void adaptiveTriangle::create(int maxlevel, 
			      Double_Matrix *coeffs, Double_Matrix *eexps)
{
  cleanElement<adaptiveTriangle>();
  adaptivePoint *p1 = adaptivePoint::create(0, 0, 0, coeffs, eexps);
  adaptivePoint *p2 = adaptivePoint::create(0, 1, 0, coeffs, eexps);
  adaptivePoint *p3 = adaptivePoint::create(1, 0, 0, coeffs, eexps);
  adaptiveTriangle *t = new adaptiveTriangle(p1, p2, p3);
  recurCreate(t, maxlevel, 0, coeffs, eexps);
}

void adaptiveTriangle::recurCreate(adaptiveTriangle *t, int maxlevel, int level,
				   Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all.push_back(t);
  if(level++ >= maxlevel) return;

  // p3
  // p13   p23
  // p1    p12    p2
  adaptivePoint *p1 = t->p[0];
  adaptivePoint *p2 = t->p[1];
  adaptivePoint *p3 = t->p[2];
  adaptivePoint *p12 = adaptivePoint::create
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p13 = adaptivePoint::create
    ((p1->x + p3->x) * 0.5, (p1->y + p3->y) * 0.5, (p1->z + p3->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p23 = adaptivePoint::create
    ((p3->x + p2->x) * 0.5, (p3->y + p2->y) * 0.5, (p3->z + p2->z) * 0.5, 
     coeffs, eexps);
  adaptiveTriangle *t1 = new adaptiveTriangle(p1, p12, p13);
  recurCreate(t1, maxlevel, level, coeffs, eexps);
  adaptiveTriangle *t2 = new adaptiveTriangle(p2, p23, p12);
  recurCreate(t2, maxlevel, level, coeffs, eexps);
  adaptiveTriangle *t3 = new adaptiveTriangle(p3, p13, p23);
  recurCreate(t3, maxlevel, level, coeffs, eexps);
  adaptiveTriangle *t4 = new adaptiveTriangle(p12, p23, p13);
  recurCreate(t4, maxlevel, level, coeffs, eexps);
  t->e[0] = t1;
  t->e[1] = t2;
  t->e[2] = t3;
  t->e[3] = t4;
}

void adaptiveTriangle::error(double AVG, double tol)
{
  adaptiveTriangle *t = *all.begin();
  recurError(t, AVG, tol);
}

void adaptiveTriangle::recurError(adaptiveTriangle *t, double AVG, double tol)
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
        recurError(t->e[0], AVG, tol);
        recurError(t->e[1], AVG, tol);
        recurError(t->e[2], AVG, tol);
        recurError(t->e[3], AVG, tol);
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
        recurError(t->e[0], AVG, tol);
        recurError(t->e[1], AVG, tol);
        recurError(t->e[2], AVG, tol);
        recurError(t->e[3], AVG, tol);
      }
      else
        t->visible = true;
    }
  }
}

void adaptiveQuadrangle::create(int maxlevel, 
				Double_Matrix *coeffs, Double_Matrix *eexps)
{
  cleanElement<adaptiveQuadrangle>();
  adaptivePoint *p1 = adaptivePoint::create(-1, -1, 0, coeffs, eexps);
  adaptivePoint *p2 = adaptivePoint::create(1, -1, 0, coeffs, eexps);
  adaptivePoint *p3 = adaptivePoint::create(1, 1, 0, coeffs, eexps);
  adaptivePoint *p4 = adaptivePoint::create(-1, 1, 0, coeffs, eexps);
  adaptiveQuadrangle *q = new adaptiveQuadrangle(p1, p2, p3, p4);
  recurCreate(q, maxlevel, 0, coeffs, eexps);
}

void adaptiveQuadrangle::recurCreate(adaptiveQuadrangle *q, int maxlevel, int level,
				     Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all.push_back(q);
  if(level++ >= maxlevel) return;

  // p4   p34    p3
  // p14  pc     p23
  // p1   p12    p2
  adaptivePoint *p1 = q->p[0];
  adaptivePoint *p2 = q->p[1];
  adaptivePoint *p3 = q->p[2];
  adaptivePoint *p4 = q->p[3];
  adaptivePoint *p12 = adaptivePoint::create
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p23 = adaptivePoint::create
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p34 = adaptivePoint::create
    ((p3->x + p4->x) * 0.5, (p3->y + p4->y) * 0.5, (p3->z + p4->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p14 = adaptivePoint::create
    ((p1->x + p4->x) * 0.5, (p1->y + p4->y) * 0.5, (p1->z + p4->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *pc = adaptivePoint::create
    ((p1->x + p2->x + p3->x + p4->x) * 0.25, (p1->y + p2->y + p3->y + p4->y) * 0.25, 
     (p1->z + p2->z + p3->z + p4->z) * 0.25, coeffs, eexps);
  adaptiveQuadrangle *q1 = new adaptiveQuadrangle(p1, p12, pc, p14);
  recurCreate(q1, maxlevel, level, coeffs, eexps);
  adaptiveQuadrangle *q2 = new adaptiveQuadrangle(p2, p23, pc, p12);
  recurCreate(q2, maxlevel, level, coeffs, eexps);
  adaptiveQuadrangle *q3 = new adaptiveQuadrangle(p3, p34, pc, p23);
  recurCreate(q3, maxlevel, level, coeffs, eexps);
  adaptiveQuadrangle *q4 = new adaptiveQuadrangle(p4, p14, pc, p34);
  recurCreate(q4, maxlevel, level, coeffs, eexps);
  q->e[0] = q1;
  q->e[1] = q2;
  q->e[2] = q3;
  q->e[3] = q4;
}

void adaptiveQuadrangle::error(double AVG, double tol)
{
  adaptiveQuadrangle *q = *all.begin();
  recurError(q, AVG, tol);
}

void adaptiveQuadrangle::recurError(adaptiveQuadrangle *q, double AVG, double tol)
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
        recurError(q->e[0], AVG, tol);
        recurError(q->e[1], AVG, tol);
        recurError(q->e[2], AVG, tol);
        recurError(q->e[3], AVG, tol);
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
        recurError(q->e[0], AVG, tol);
        recurError(q->e[1], AVG, tol);
        recurError(q->e[2], AVG, tol);
        recurError(q->e[3], AVG, tol);
      }
      else
        q->visible = true;
    }
  }
}

void adaptivePrism::create(int maxlevel, 
				Double_Matrix *coeffs, Double_Matrix *eexps)
{
  cleanElement<adaptivePrism>();
  adaptivePoint *p1 = adaptivePoint::create(0, 0, -1, coeffs, eexps);
  adaptivePoint *p2 = adaptivePoint::create(1, 0, -1, coeffs, eexps);
  adaptivePoint *p3 = adaptivePoint::create(0, 1, -1, coeffs, eexps);
  adaptivePoint *p4 = adaptivePoint::create(0, 0, 1, coeffs, eexps);
  adaptivePoint *p5 = adaptivePoint::create(1, 0, 1, coeffs, eexps);
  adaptivePoint *p6 = adaptivePoint::create(0, 1, 1, coeffs, eexps);
  adaptivePrism *p = new adaptivePrism(p1, p2, p3, p4, p5, p6);
  recurCreate(p, maxlevel, 0, coeffs, eexps);
}

void adaptivePrism::recurCreate(adaptivePrism *p, int maxlevel, int level,
				     Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all.push_back(p);
  if(level++ >= maxlevel) return;

  // p4   p34    p3
  // p14  pc     p23
  // p1   p12    p2
  adaptivePoint *p1 = p->p[0];
  adaptivePoint *p2 = p->p[1];
  adaptivePoint *p3 = p->p[2];
  adaptivePoint *p4 = p->p[3];
  adaptivePoint *p5 = p->p[4];
  adaptivePoint *p6 = p->p[5];
  adaptivePoint *p14 = adaptivePoint::create
    ((p1->x + p4->x) * 0.5, (p1->y + p4->y) * 0.5, (p1->z + p4->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p25 = adaptivePoint::create
    ((p2->x + p5->x) * 0.5, (p2->y + p5->y) * 0.5, (p2->z + p5->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p36 = adaptivePoint::create
    ((p3->x + p6->x) * 0.5, (p3->y + p6->y) * 0.5, (p3->z + p6->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p12 = adaptivePoint::create
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p23 = adaptivePoint::create
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p31 = adaptivePoint::create
    ((p3->x + p1->x) * 0.5, (p3->y + p1->y) * 0.5, (p3->z + p1->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p1425 = adaptivePoint::create
    ((p14->x + p25->x) * 0.5, (p14->y + p25->y) * 0.5, (p14->z + p25->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p2536 = adaptivePoint::create
    ((p25->x + p36->x) * 0.5, (p25->y + p36->y) * 0.5, (p25->z + p36->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p3614 = adaptivePoint::create
    ((p36->x + p14->x) * 0.5, (p36->y + p14->y) * 0.5, (p36->z + p14->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p45 = adaptivePoint::create
    ((p4->x + p5->x) * 0.5, (p4->y + p5->y) * 0.5, (p4->z + p5->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p56 = adaptivePoint::create
    ((p5->x + p6->x) * 0.5, (p5->y + p6->y) * 0.5, (p5->z + p6->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p64 = adaptivePoint::create
    ((p6->x + p4->x) * 0.5, (p6->y + p4->y) * 0.5, (p6->z + p4->z) * 0.5, 
     coeffs, eexps);
  p->e[0] = new adaptivePrism(p1, p12, p31, p14, p1425, p3614);
  recurCreate(p->e[0], maxlevel, level, coeffs, eexps);
  p->e[1] = new adaptivePrism(p2, p23, p12, p25, p2536, p1425);
  recurCreate(p->e[1], maxlevel, level, coeffs, eexps);
  p->e[2] = new adaptivePrism(p3, p31, p23, p36, p3614, p2536);
  recurCreate(p->e[2], maxlevel, level, coeffs, eexps);
  p->e[3] = new adaptivePrism(p12, p23, p31, p1425, p2536, p3614);
  recurCreate(p->e[3], maxlevel, level, coeffs, eexps);
  p->e[4] = new adaptivePrism(p14, p1425, p3614, p4, p45, p64);
  recurCreate(p->e[4], maxlevel, level, coeffs, eexps);
  p->e[5] = new adaptivePrism(p25, p2536, p1425, p5, p56, p45);
  recurCreate(p->e[5], maxlevel, level, coeffs, eexps);
  p->e[6] = new adaptivePrism(p36, p3614, p2536, p6, p64, p56);
  recurCreate(p->e[6], maxlevel, level, coeffs, eexps);
  p->e[7] = new adaptivePrism(p1425, p2536, p3614, p45, p56, p64);
  recurCreate(p->e[7], maxlevel, level, coeffs, eexps);
}

void adaptivePrism::error(double AVG, double tol)
{
  adaptivePrism *p = *all.begin();
  recurError(p, AVG, tol);
}

void adaptivePrism::recurError(adaptivePrism *p, double AVG, double tol)
{
  if(!p->e[0])
    p->visible = true;
  else {
    double vr;
    if(!p->e[0]->e[0]) {
      double v1 = p->e[0]->V();
      double v2 = p->e[1]->V();
      double v3 = p->e[2]->V();
      double v4 = p->e[3]->V();
      double v5 = p->e[4]->V();
      double v6 = p->e[5]->V();
      double v7 = p->e[6]->V();
      double v8 = p->e[7]->V();
      vr = (v1 + v2 + v3 + v4/2 +v5 +v6 +v7 +v8/2) / 7;
      double v = p->V();
      if(fabs(v - vr) > AVG * tol){
        p->visible = false;
        recurError(p->e[0], AVG, tol);
        recurError(p->e[1], AVG, tol);
        recurError(p->e[2], AVG, tol);
        recurError(p->e[3], AVG, tol);
        recurError(p->e[4], AVG, tol);
        recurError(p->e[5], AVG, tol);
        recurError(p->e[6], AVG, tol);
        recurError(p->e[7], AVG, tol);
      }
      else
        p->visible = true;
    }
    else {
      bool err=false;
      double ve[8];
      for(int i=0; i<8; i++){
        double v1 = p->e[i]->e[0]->V();
        double v2 = p->e[i]->e[1]->V();
        double v3 = p->e[i]->e[2]->V();
        double v4 = p->e[i]->e[3]->V();
        double v5 = p->e[i]->e[4]->V();
        double v6 = p->e[i]->e[5]->V();
        double v7 = p->e[i]->e[6]->V();
        double v8 = p->e[i]->e[7]->V();
        double vr = (v1 + v2 + v3 + v4/2 +v5 +v6 +v7 +v8/2) / 7;
        ve[i] = p->e[i]->V();
        err |= (fabs((ve[i] - vr)) > AVG*tol);
      }
      double vr = (ve[0] + ve[1] + ve[2] + ve[3] / 2 + 
                   ve[4] + ve[5] + ve[6] + ve[7] / 2) / 7;
      err |= (fabs((p->V() - vr))>AVG*tol);
      if(err) {
        p->visible = false;
        for(int i=0;i<8;i++)
          recurError(p->e[i], AVG, tol);
      }
      else
        p->visible = true;
    }
  }
}

void adaptiveTetrahedron::create(int maxlevel,
				 Double_Matrix *coeffs, Double_Matrix *eexps)
{
  cleanElement<adaptiveTetrahedron>();
  adaptivePoint *p1 = adaptivePoint::create(0, 0, 0, coeffs, eexps);
  adaptivePoint *p2 = adaptivePoint::create(0, 1, 0, coeffs, eexps);
  adaptivePoint *p3 = adaptivePoint::create(1, 0, 0, coeffs, eexps);
  adaptivePoint *p4 = adaptivePoint::create(0, 0, 1, coeffs, eexps);
  adaptiveTetrahedron *t = new adaptiveTetrahedron(p1, p2, p3, p4);
  recurCreate(t, maxlevel, 0, coeffs, eexps);
}

void adaptiveTetrahedron::recurCreate(adaptiveTetrahedron *t, int maxlevel, int level,
			              Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all.push_back(t);
  if(level++ >= maxlevel) return;

  adaptivePoint *p0 = t->p[0];
  adaptivePoint *p1 = t->p[1];
  adaptivePoint *p2 = t->p[2];
  adaptivePoint *p3 = t->p[3];
  adaptivePoint *pe0 = adaptivePoint::create
    ((p0->x + p1->x) * 0.5, (p0->y + p1->y) * 0.5, (p0->z + p1->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *pe1 = adaptivePoint::create
    ((p0->x + p2->x) * 0.5, (p0->y + p2->y) * 0.5, (p0->z + p2->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *pe2 = adaptivePoint::create
    ((p0->x + p3->x) * 0.5, (p0->y + p3->y) * 0.5, (p0->z + p3->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *pe3 = adaptivePoint::create
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *pe4 = adaptivePoint::create
    ((p1->x + p3->x) * 0.5, (p1->y + p3->y) * 0.5, (p1->z + p3->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *pe5 = adaptivePoint::create
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5,
     coeffs, eexps);
  adaptiveTetrahedron *t1 = new adaptiveTetrahedron(p0, pe0, pe2, pe1);
  recurCreate(t1, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t2 = new adaptiveTetrahedron(p1, pe0, pe3, pe4);
  recurCreate(t2, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t3 = new adaptiveTetrahedron(p2, pe3, pe1, pe5);
  recurCreate(t3, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t4 = new adaptiveTetrahedron(p3, pe2, pe4, pe5);
  recurCreate(t4, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t5 = new adaptiveTetrahedron(pe3, pe5, pe2, pe4);
  recurCreate(t5, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t6 = new adaptiveTetrahedron(pe3, pe2, pe0, pe4);
  recurCreate(t6, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t7 = new adaptiveTetrahedron(pe2, pe5, pe3, pe1);
  recurCreate(t7, maxlevel, level, coeffs, eexps);
  adaptiveTetrahedron *t8 = new adaptiveTetrahedron(pe0, pe2, pe3, pe1);
  recurCreate(t8, maxlevel, level, coeffs, eexps);
  t->e[0] = t1;
  t->e[1] = t2;
  t->e[2] = t3;
  t->e[3] = t4;
  t->e[4] = t5;
  t->e[5] = t6;
  t->e[6] = t7;
  t->e[7] = t8;
}

void adaptiveTetrahedron::error(double AVG, double tol)
{
  adaptiveTetrahedron *t = *all.begin();
  recurError(t, AVG, tol);
}

void adaptiveTetrahedron::recurError(adaptiveTetrahedron *t, double AVG, double tol)
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
        recurError(t->e[0], AVG, tol);
        recurError(t->e[1], AVG, tol);
        recurError(t->e[2], AVG, tol);
        recurError(t->e[3], AVG, tol);
        recurError(t->e[4], AVG, tol);
        recurError(t->e[5], AVG, tol);
        recurError(t->e[6], AVG, tol);
        recurError(t->e[7], AVG, tol);
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
        recurError(t->e[0], AVG, tol);
        recurError(t->e[1], AVG, tol);
        recurError(t->e[2], AVG, tol);
        recurError(t->e[3], AVG, tol);
        recurError(t->e[4], AVG, tol);
        recurError(t->e[5], AVG, tol);
        recurError(t->e[6], AVG, tol);
        recurError(t->e[7], AVG, tol);
      }
      else
        t->visible = true;
    }
  }
}

void adaptiveHexahedron::create(int maxlevel, 
				Double_Matrix *coeffs, Double_Matrix *eexps)
{
  cleanElement<adaptiveHexahedron>();
  adaptivePoint *p1 = adaptivePoint::create(-1, -1, -1, coeffs, eexps);
  adaptivePoint *p2 = adaptivePoint::create(-1, 1, -1, coeffs, eexps);
  adaptivePoint *p3 = adaptivePoint::create(1, 1, -1, coeffs, eexps);
  adaptivePoint *p4 = adaptivePoint::create(1, -1, -1, coeffs, eexps);
  adaptivePoint *p11 = adaptivePoint::create(-1, -1, 1, coeffs, eexps);
  adaptivePoint *p21 = adaptivePoint::create(-1, 1, 1, coeffs, eexps);
  adaptivePoint *p31 = adaptivePoint::create(1, 1, 1, coeffs, eexps);
  adaptivePoint *p41 = adaptivePoint::create(1, -1, 1, coeffs, eexps);
  adaptiveHexahedron *h = new adaptiveHexahedron(p1, p2, p3, p4, p11, p21, p31, p41);
  recurCreate(h, maxlevel, 0, coeffs, eexps);
}

void adaptiveHexahedron::recurCreate(adaptiveHexahedron *h, int maxlevel, int level,
				     Double_Matrix *coeffs, Double_Matrix *eexps)
{
  all.push_back(h);
  if(level++ >= maxlevel) return;

  adaptivePoint *p0 = h->p[0];
  adaptivePoint *p1 = h->p[1];
  adaptivePoint *p2 = h->p[2];
  adaptivePoint *p3 = h->p[3];
  adaptivePoint *p4 = h->p[4];
  adaptivePoint *p5 = h->p[5];
  adaptivePoint *p6 = h->p[6];
  adaptivePoint *p7 = h->p[7];
  adaptivePoint *p01 = adaptivePoint::create
    ((p0->x + p1->x) * 0.5, (p0->y + p1->y) * 0.5, (p0->z + p1->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p12 = adaptivePoint::create
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p23 = adaptivePoint::create
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p03 = adaptivePoint::create
    ((p3->x + p0->x) * 0.5, (p3->y + p0->y) * 0.5, (p3->z + p0->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p45 = adaptivePoint::create
    ((p4->x + p5->x) * 0.5, (p4->y + p5->y) * 0.5, (p4->z + p5->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p56 = adaptivePoint::create
    ((p5->x + p6->x) * 0.5, (p5->y + p6->y) * 0.5, (p5->z + p6->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p67 = adaptivePoint::create
    ((p6->x + p7->x) * 0.5, (p6->y + p7->y) * 0.5, (p6->z + p7->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p47 = adaptivePoint::create
    ((p7->x + p4->x) * 0.5, (p7->y + p4->y) * 0.5, (p7->z + p4->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p04 = adaptivePoint::create
    ((p4->x + p0->x) * 0.5, (p4->y + p0->y) * 0.5, (p4->z + p0->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p15 = adaptivePoint::create
    ((p5->x + p1->x) * 0.5, (p5->y + p1->y) * 0.5, (p5->z + p1->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p26 = adaptivePoint::create
    ((p6->x + p2->x) * 0.5, (p6->y + p2->y) * 0.5, (p6->z + p2->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p37 = adaptivePoint::create
    ((p7->x + p3->x) * 0.5, (p7->y + p3->y) * 0.5, (p7->z + p3->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p0145 = adaptivePoint::create
    ((p45->x + p01->x) * 0.5, (p45->y + p01->y) * 0.5,(p45->z + p01->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p1256 = adaptivePoint::create
    ((p12->x + p56->x) * 0.5, (p12->y + p56->y) * 0.5, (p12->z + p56->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p2367 = adaptivePoint::create
    ((p23->x + p67->x) * 0.5, (p23->y + p67->y) * 0.5, (p23->z + p67->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p0347 = adaptivePoint::create
    ((p03->x + p47->x) * 0.5, (p03->y + p47->y) * 0.5, (p03->z + p47->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *p4756 = adaptivePoint::create
    ((p47->x + p56->x) * 0.5, (p47->y + p56->y) * 0.5, (p47->z + p56->z) * 0.5, 
     coeffs, eexps);
  adaptivePoint *p0312 = adaptivePoint::create
    ((p03->x + p12->x) * 0.5, (p03->y + p12->y) * 0.5, (p03->z + p12->z) * 0.5,
     coeffs, eexps);
  adaptivePoint *pc = adaptivePoint::create
    ((p0->x + p1->x + p2->x + p3->x + p4->x + p5->x + p6->x + p7->x) * 0.125,
     (p0->y + p1->y + p2->y + p3->y + p4->y + p5->y + p6->y + p7->y) * 0.125,
     (p0->z + p1->z + p2->z + p3->z + p4->z + p5->z + p6->z + p7->z) * 0.125,
     coeffs, eexps);

  adaptiveHexahedron *h1 = new adaptiveHexahedron
    (p0, p01, p0312, p03, p04, p0145, pc, p0347); // p0
  recurCreate(h1, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h2 = new adaptiveHexahedron
    (p01, p0145, p15, p1, p0312, pc, p1256, p12); // p1
  recurCreate(h2, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h3 = new adaptiveHexahedron
    (p04, p4, p45, p0145, p0347, p47, p4756, pc); // p4
  recurCreate(h3, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h4 = new adaptiveHexahedron
    (p0145, p45, p5, p15, pc, p4756, p56, p1256); // p5
  recurCreate(h4, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h5 = new adaptiveHexahedron
    (p0347, p47, p4756, pc, p37, p7, p67, p2367); // p7
  recurCreate(h5, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h6 = new adaptiveHexahedron
    (pc, p4756, p56, p1256, p2367, p67, p6, p26); // p6
  recurCreate(h6, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h7 = new adaptiveHexahedron
    (p03, p0347, pc, p0312, p3, p37, p2367, p23); // p3
  recurCreate(h7, maxlevel, level, coeffs, eexps);
  adaptiveHexahedron *h8 = new adaptiveHexahedron
    (p0312, pc, p1256, p12, p23, p2367, p26, p2); //p2
  recurCreate(h8, maxlevel, level, coeffs, eexps);
  h->e[0] = h1;
  h->e[1] = h2;
  h->e[2] = h3;
  h->e[3] = h4;
  h->e[4] = h5;
  h->e[5] = h6;
  h->e[6] = h7;
  h->e[7] = h8;
}

void adaptiveHexahedron::error(double AVG, double tol)
{
  adaptiveHexahedron *h = *all.begin();
  recurError(h, AVG, tol);
}

void adaptiveHexahedron::recurError(adaptiveHexahedron *h, double AVG, double tol)
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
      recurError(h->e[0], AVG, tol);
      recurError(h->e[1], AVG, tol);
      recurError(h->e[2], AVG, tol);
      recurError(h->e[3], AVG, tol);
      recurError(h->e[4], AVG, tol);
      recurError(h->e[5], AVG, tol);
      recurError(h->e[6], AVG, tol);
      recurError(h->e[7], AVG, tol);
    }
    else
      h->visible = true;
  }
}

template <class T>
int adaptiveElements<T>::_zoomElement(int ielem, int level, GMSH_Post_Plugin *plug)
{
  const int N = _coeffs->size1();
  
  Double_Vector val(N),  res(adaptivePoint::all.size());
  Double_Vector valx(N), resx(adaptivePoint::all.size());
  Double_Vector valy(N), resy(adaptivePoint::all.size());
  Double_Vector valz(N), resz(adaptivePoint::all.size());
  Double_Matrix xyz(_posX->size2(), 3);
  Double_Matrix XYZ(adaptivePoint::all.size(), 3);

  for(int k = 0; k < _posX->size2(); ++k){
    xyz(k, 0) = (*_posX)(ielem, k);
    xyz(k, 1) = (*_posY)(ielem, k);
    xyz(k, 2) = (*_posZ)(ielem, k);
  }

  for(int k = 0; k < N; ++k)
    val(k) = (*_val)(ielem, k);

  _interpolate->mult(val, res);

  if(_valX){
    for(int k = 0; k < N; ++k){
      valx(k) = (*_valX)(ielem, k);
      valy(k) = (*_valY)(ielem, k);
      valz(k) = (*_valZ)(ielem, k);
    }           
    _interpolate->mult(valx, resx);
    _interpolate->mult(valy, resy);
    _interpolate->mult(valz, resz);
  }

  _geometry->mult(xyz, XYZ);

  int k = 0;
  for(std::set<adaptivePoint>::iterator it = adaptivePoint::all.begin();
      it != adaptivePoint::all.end(); ++it){
    adaptivePoint *p = (adaptivePoint*)&(*it);
    p->val = res(k);
    if(_valX){
      p->valx = resx(k);
      p->valy = resy(k);
      p->valz = resz(k);
    }
    p->X = XYZ(k, 0);
    p->Y = XYZ(k, 1);
    p->Z = XYZ(k, 2);
    if(_minVal > p->val) _minVal = p->val;
    if(_maxVal < p->val) _maxVal = p->val;
    k++;
  }

  for(typename std::list<T*>::iterator it = T::all.begin(); 
      it != T::all.end(); it++) 
    (*it)->visible = false;

  if(!plug || _tol != 0.)
    T::error(_maxVal - _minVal, _tol);

  if(plug)
    plug->assignSpecificVisibility();

  for(typename std::list<T*>::iterator it = T::all.begin(); 
      it != T::all.end(); it++){
    if((*it)->visible && !(*it)->e[0] && level != _level)
      return 0;
  }
  
  for(typename std::list<T*>::iterator it = T::all.begin(); 
      it != T::all.end(); it++){
    if((*it)->visible){
      adaptivePoint **p = (*it)->p;
      for(int k = 0; k < T::numNodes; ++k) List_Add(_listEle, &p[k]->X);
      for(int k = 0; k < T::numNodes; ++k) List_Add(_listEle, &p[k]->Y);
      for(int k = 0; k < T::numNodes; ++k) List_Add(_listEle, &p[k]->Z);
      if(_valX){
        for(int k = 0; k < T::numNodes; ++k){
          List_Add(_listEle, &p[k]->valx);
          List_Add(_listEle, &p[k]->valy);
          List_Add(_listEle, &p[k]->valz);
        }
      }
      else{
        for (int k = 0; k < T::numNodes; ++k) 
	  List_Add(_listEle, &p[k]->val);
      }
      (*_numEle)++;
    }
  }
  return 1;
}

template <class T> 
void adaptiveElements<T>::_changeResolution(int level, GMSH_Post_Plugin *plug, int *done)
{
  const int N = _coeffs->size1();
  const int nbelm = _posX->size1();

  double sf[100];
  T::create(level, _coeffs, _eexps);

  if(_interpolate) delete _interpolate;
  _interpolate = new Double_Matrix(adaptivePoint::all.size(), N);

  if(_geometry) delete _geometry;
  _geometry = new Double_Matrix(adaptivePoint::all.size(), _posX->size2());

  int kk = 0;
  for(std::set<adaptivePoint>::iterator it = adaptivePoint::all.begin(); 
      it != adaptivePoint::all.end(); ++it) {
    adaptivePoint *p = (adaptivePoint*)&(*it);
    for(int k = 0; k < N; ++k)
      (*_interpolate)(kk, k) = p->shapeFunctions[k];
    if(_coeffsGeom)
      computeShapeFunctions(_coeffsGeom, _eexpsGeom, p->x, p->y, p->z, sf);
    else
      T::GSF(p->x, p->y, p->z, sf);
    for(int k = 0; k < _posX->size2(); k++)
      (*_geometry) (kk, k) = sf[k];
    kk++;
  }

  for(int i = 0; i < nbelm; ++i)
    done[i] = _zoomElement(i, level, plug);
}

template <class T>
adaptiveElements<T>::~adaptiveElements()
{
  if(_posX) delete _posX;
  if(_posY) delete _posY;
  if(_posZ) delete _posZ;
  if(_val) delete _val;
  if(_valX) delete _valX;
  if(_valY) delete _valY;
  if(_valZ) delete _valZ;
  if(_interpolate) delete _interpolate;
  if(_geometry) delete _geometry;
  cleanElement<T>();
}

template <class T>
void adaptiveElements<T>::initData(PViewData *data, int step)
{
  int numComp = data->getNumComponents(0, 0, 0);
  if(numComp != 1 && numComp != 3) return;

  int numEle = 0;
  switch(T::numEdges){
  case 1: numEle = data->getNumLines(); break;
  case 3: numEle = data->getNumTriangles(); break;
  case 4: numEle = data->getNumQuadrangles(); break;
  case 6: numEle = data->getNumTetrahedra(); break;
  case 9: numEle = data->getNumPrisms(); break;
  case 12: numEle = data->getNumHexahedra(); break;
  }
  if(!numEle) return;

  int numNodes = getNumNodes();
  int numVal = _coeffs->size1() * numComp;

  _minVal = VAL_INF;
  _maxVal = -VAL_INF;

  if(_posX) delete _posX;
  if(_posY) delete _posY;
  if(_posZ) delete _posZ;
  if(_val) delete _val;
  if(_valX) delete _valX;
  if(_valY) delete _valY;
  if(_valZ) delete _valZ;
  _posX = new Double_Matrix(numEle, numNodes);
  _posY = new Double_Matrix(numEle, numNodes);
  _posZ = new Double_Matrix(numEle, numNodes);
  _val = new Double_Matrix(numEle, numVal);
  if(numComp == 3){
    _valX = new Double_Matrix(numEle, numVal);
    _valY = new Double_Matrix(numEle, numVal);
    _valZ = new Double_Matrix(numEle, numVal);
  }

  // store non-interpolated data
  int k = 0;
  for(int ent = 0; ent < data->getNumEntities(step); ent++){    
    for(int ele = 0; ele < data->getNumElements(step, ent); ele++){    
      if(data->skipElement(step, ent, ele) ||
	 data->getNumEdges(step, ent, ele) != T::numEdges) continue;
      if(numVal != data->getNumValues(step, ent, ele)){
	Msg::Error("Wrong number of values (%d) in element %d (expecting %d)",
		   numVal, ele, data->getNumValues(step, ent, ele));
	continue;
      }
      if(numNodes != data->getNumNodes(step, ent, ele)){
	Msg::Error("Wrong number of nodes (%d) in element %d (expecting %d)",
		   numNodes, ele, data->getNumNodes(step, ent, ele));
	continue;
      }
      for(int nod = 0; nod < numNodes; nod++){
	double x, y, z;
	data->getNode(step, ent, ele, nod, x, y, z);
	(*_posX)(k, nod) = x; 
	(*_posY)(k, nod) = y; 
	(*_posZ)(k, nod) = z; 
      }
      if(numComp == 1){
	for(int i = 0; i < numVal; i++){
	  double val;
	  data->getValue(step, ent, ele, i, val);
	  (*_val)(k, i) = val;
	}
      }
      else if(numComp == 3){
	for(int i = 0; i < numVal / 3; i++){
	  double val[3];
	  // adaptation of the visualization mesh is based on the norm
	  // squared of the vector
 	  data->getValue(step, ent, ele, 3 * i, val[0]); 
 	  data->getValue(step, ent, ele, 3 * i + 1, val[1]); 
 	  data->getValue(step, ent, ele, 3 * i + 2, val[2]); 
	  (*_val)(k, i) = (val[0] * val[0] + val[1] * val[1] + val[2] * val[2]);
	  (*_valX)(k, i) = val[0];
	  (*_valY)(k, i) = val[1];
	  (*_valZ)(k, i) = val[2];
	}
      }
      k++;
    }
  }
}

template <class T>
void adaptiveElements<T>::changeResolution(int level, double tol, GMSH_Post_Plugin *plug)
{
  if(!_val){
    Msg::Error("No data available to change adaptive resolution");
    return;
  }
  
  _level = level;
  _tol = tol;

  List_Reset(_listEle);
  *_numEle = 0;
  
  if(!_posX->size1()) return;

  std::vector<int> done(_posX->size1(), 0);

  // We first do the adaptive stuff at level 2 and will only process
  // elements that have reached the maximal recursion level
  int level_act = (level > 2) ? 2 : level;
  while(1){
    _changeResolution(level_act, plug, &done[0]);
    int numDone = 0;
    for(int i = 0; i < _posX->size1(); ++i) numDone += done[i];
    if(numDone == _posX->size1()) break;
    if(level_act >= level) break;
    level_act++;
  }
}

adaptiveData::adaptiveData(PViewData *data)
  : _step(-1), _level(-1), _tol(-1.), _inData(data), 
    _lines(0), _triangles(0), _quadrangles(0), 
    _tetrahedra(0), _hexahedra(0), _prisms(0)
{
  // We could do this, but it's a bit tricky (need to set a flag in
  // the view to say "don't use the adaptive stuff anymore!")
  /*
  if(dynamic_cast<PViewDataList*>(_inData) && _inData->getNumTimeSteps() == 1)
    _outData = (PViewDataList*)_inData;
  else
  */
  _outData = new PViewDataList(true);

  int numComp = _inData->getNumComponents(0, 0, 0);
  std::vector<Double_Matrix*> p;
  if(_inData->getNumLines() && _inData->getInterpolationMatrices(1, p) >= 2){
    _lines = new adaptiveElements<adaptiveLine>
      ((numComp == 1) ? _outData->SL : _outData->VL,
       (numComp == 1) ? &_outData->NbSL : &_outData->NbVL,
       p[0], p[1], (p.size() == 4) ? p[2] : 0, (p.size() == 4) ? p[3] : 0);
  }
  if(_inData->getNumTriangles() && _inData->getInterpolationMatrices(3, p) >= 2){
    _triangles = new adaptiveElements<adaptiveTriangle>
      ((numComp == 1) ? _outData->ST : _outData->VT,
       (numComp == 1) ? &_outData->NbST : &_outData->NbVT,
       p[0], p[1], (p.size() == 4) ? p[2] : 0, (p.size() == 4) ? p[3] : 0);
  }
  if(_inData->getNumQuadrangles() && _inData->getInterpolationMatrices(4, p) >= 2){
    _quadrangles = new adaptiveElements<adaptiveQuadrangle>
      ((numComp == 1) ? _outData->SQ : _outData->VQ,
       (numComp == 1) ? &_outData->NbSQ : &_outData->NbVQ,
       p[0], p[1], (p.size() == 4) ? p[2] : 0, (p.size() == 4) ? p[3] : 0);
  }
  if(_inData->getNumTetrahedra() && _inData->getInterpolationMatrices(6, p) >= 2){
    _tetrahedra = new adaptiveElements<adaptiveTetrahedron>
      ((numComp == 1) ? _outData->SS : _outData->VS,
       (numComp == 1) ? &_outData->NbSS : &_outData->NbVS,
       p[0], p[1], (p.size() == 4) ? p[2] : 0, (p.size() == 4) ? p[3] : 0);
  }
  if(_inData->getNumPrisms() && _inData->getInterpolationMatrices(9, p) >= 2){
    _prisms = new adaptiveElements<adaptivePrism>
      ((numComp == 1) ? _outData->SI : _outData->VI,
       (numComp == 1) ? &_outData->NbSI : &_outData->NbVI, 
       p[0], p[1], (p.size() == 4) ? p[2] : 0, (p.size() == 4) ? p[3] : 0);
  }
  if(_inData->getNumHexahedra() && _inData->getInterpolationMatrices(12, p) >= 2){
    _hexahedra = new adaptiveElements<adaptiveHexahedron>
      ((numComp == 1) ? _outData->SH : _outData->VH,
       (numComp == 1) ? &_outData->NbSH : &_outData->NbVH, 
       p[0], p[1], (p.size() == 4) ? p[2] : 0, (p.size() == 4) ? p[3] : 0);
  }
}

adaptiveData::~adaptiveData()
{
  if(_lines) delete _lines;
  if(_triangles) delete _triangles;
  if(_quadrangles) delete _quadrangles;
  if(_tetrahedra) delete _tetrahedra;
  if(_prisms) delete _prisms;
  if(_hexahedra) delete _hexahedra;
  if(_inData != _outData) delete _outData;
}

void adaptiveData::changeResolution(int step, int level, double tol, GMSH_Post_Plugin *plug)
{
  if(_step != step){
    if(_lines) _lines->initData(_inData, step);
    if(_triangles) _triangles->initData(_inData, step);
    if(_quadrangles) _quadrangles->initData(_inData, step);
    if(_tetrahedra) _tetrahedra->initData(_inData, step);
    if(_prisms) _prisms->initData(_inData, step);
    if(_hexahedra) _hexahedra->initData(_inData, step);
  }
  if(plug || _step != step || _level != level || _tol != tol){
    _outData->setDirty(true);
    if(_lines) _lines->changeResolution(level, tol, plug);
    if(_triangles) _triangles->changeResolution(level, tol, plug);
    if(_quadrangles) _quadrangles->changeResolution(level, tol, plug);
    if(_tetrahedra) _tetrahedra->changeResolution(level, tol, plug);
    if(_prisms) _prisms->changeResolution(level, tol, plug);
    if(_hexahedra) _hexahedra->changeResolution(level, tol, plug);
    _outData->finalize();
  }
  _step = step;
  _level = level;
  _tol = tol;
}
