// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <math.h>
#include <list>
#include <set>
#include "adaptiveData.h"
#include "Plugin.h"
#include "ListUtils.h"

std::set<adaptivePoint> adaptiveLine::allPoints;
std::set<adaptivePoint> adaptiveTriangle::allPoints;
std::set<adaptivePoint> adaptiveQuadrangle::allPoints;
std::set<adaptivePoint> adaptiveTetrahedron::allPoints;
std::set<adaptivePoint> adaptiveHexahedron::allPoints;
std::set<adaptivePoint> adaptivePrism::allPoints;

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
  T::allPoints.clear();
}

static void computeShapeFunctions(Double_Matrix *coeffs, Double_Matrix *eexps,
				  double u, double v, double w, Double_Vector *sf,
                                  Double_Vector *tmp)
{
  for(int i = 0; i < eexps->size1(); i++) {
    (*tmp)(i) = pow(u, (*eexps)(i, 0));
    if(eexps->size2() > 1) (*tmp)(i) *= pow(v, (*eexps)(i, 1));
    if(eexps->size2() > 2) (*tmp)(i) *= pow(w, (*eexps)(i, 2));
  }
  coeffs->mult(*tmp, *sf);
}

adaptivePoint *adaptivePoint::add(double x, double y, double z,
                                  std::set<adaptivePoint> &allPoints)
{
  adaptivePoint p;
  p.x = x;
  p.y = y;
  p.z = z;
  std::set<adaptivePoint>::iterator it = allPoints.find(p);
  if(it == allPoints.end()){
    allPoints.insert(p);
    it = allPoints.find(p);
  }
  return (adaptivePoint*)&(*it);
}

void adaptiveLine::create(int maxlevel)
{
  cleanElement<adaptiveLine>();
  adaptivePoint *p1 = adaptivePoint::add(-1, 0, 0, allPoints);
  adaptivePoint *p2 = adaptivePoint::add(1, 0, 0, allPoints);
  adaptiveLine *t = new adaptiveLine(p1, p2);
  recurCreate(t, maxlevel, 0);
}

void adaptiveLine::recurCreate(adaptiveLine *e, int maxlevel, int level)
{
  all.push_back(e);
  if(level++ >= maxlevel) return;

  // p1    p12    p2
  adaptivePoint *p1 = e->p[0];
  adaptivePoint *p2 = e->p[1];
  adaptivePoint *p12 = adaptivePoint::add
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     allPoints);
  adaptiveLine *e1 = new adaptiveLine(p1, p12);
  recurCreate(e1, maxlevel, level);
  adaptiveLine *e2 = new adaptiveLine(p12, p2);
  recurCreate(e2, maxlevel, level);
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

void adaptiveTriangle::create(int maxlevel)
{
  cleanElement<adaptiveTriangle>();
  adaptivePoint *p1 = adaptivePoint::add(0, 0, 0, allPoints);
  adaptivePoint *p2 = adaptivePoint::add(0, 1, 0, allPoints);
  adaptivePoint *p3 = adaptivePoint::add(1, 0, 0, allPoints);
  adaptiveTriangle *t = new adaptiveTriangle(p1, p2, p3);
  recurCreate(t, maxlevel, 0);
}

void adaptiveTriangle::recurCreate(adaptiveTriangle *t, int maxlevel, int level)
{
  all.push_back(t);
  if(level++ >= maxlevel) return;

  // p3
  // p13   p23
  // p1    p12    p2
  adaptivePoint *p1 = t->p[0];
  adaptivePoint *p2 = t->p[1];
  adaptivePoint *p3 = t->p[2];
  adaptivePoint *p12 = adaptivePoint::add
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     allPoints);
  adaptivePoint *p13 = adaptivePoint::add
    ((p1->x + p3->x) * 0.5, (p1->y + p3->y) * 0.5, (p1->z + p3->z) * 0.5, 
     allPoints);
  adaptivePoint *p23 = adaptivePoint::add
    ((p3->x + p2->x) * 0.5, (p3->y + p2->y) * 0.5, (p3->z + p2->z) * 0.5, 
     allPoints);
  adaptiveTriangle *t1 = new adaptiveTriangle(p1, p12, p13);
  recurCreate(t1, maxlevel, level);
  adaptiveTriangle *t2 = new adaptiveTriangle(p2, p23, p12);
  recurCreate(t2, maxlevel, level);
  adaptiveTriangle *t3 = new adaptiveTriangle(p3, p13, p23);
  recurCreate(t3, maxlevel, level);
  adaptiveTriangle *t4 = new adaptiveTriangle(p12, p23, p13);
  recurCreate(t4, maxlevel, level);
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

void adaptiveQuadrangle::create(int maxlevel)
{
  cleanElement<adaptiveQuadrangle>();
  adaptivePoint *p1 = adaptivePoint::add(-1, -1, 0, allPoints);
  adaptivePoint *p2 = adaptivePoint::add(1, -1, 0, allPoints);
  adaptivePoint *p3 = adaptivePoint::add(1, 1, 0, allPoints);
  adaptivePoint *p4 = adaptivePoint::add(-1, 1, 0, allPoints);
  adaptiveQuadrangle *q = new adaptiveQuadrangle(p1, p2, p3, p4);
  recurCreate(q, maxlevel, 0);
}

void adaptiveQuadrangle::recurCreate(adaptiveQuadrangle *q, int maxlevel, int level)
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
  adaptivePoint *p12 = adaptivePoint::add
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     allPoints);
  adaptivePoint *p23 = adaptivePoint::add
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5, 
     allPoints);
  adaptivePoint *p34 = adaptivePoint::add
    ((p3->x + p4->x) * 0.5, (p3->y + p4->y) * 0.5, (p3->z + p4->z) * 0.5, 
     allPoints);
  adaptivePoint *p14 = adaptivePoint::add
    ((p1->x + p4->x) * 0.5, (p1->y + p4->y) * 0.5, (p1->z + p4->z) * 0.5, 
     allPoints);
  adaptivePoint *pc = adaptivePoint::add
    ((p1->x + p2->x + p3->x + p4->x) * 0.25, (p1->y + p2->y + p3->y + p4->y) * 0.25, 
     (p1->z + p2->z + p3->z + p4->z) * 0.25, allPoints);
  adaptiveQuadrangle *q1 = new adaptiveQuadrangle(p1, p12, pc, p14);
  recurCreate(q1, maxlevel, level);
  adaptiveQuadrangle *q2 = new adaptiveQuadrangle(p2, p23, pc, p12);
  recurCreate(q2, maxlevel, level);
  adaptiveQuadrangle *q3 = new adaptiveQuadrangle(p3, p34, pc, p23);
  recurCreate(q3, maxlevel, level);
  adaptiveQuadrangle *q4 = new adaptiveQuadrangle(p4, p14, pc, p34);
  recurCreate(q4, maxlevel, level);
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

void adaptiveTetrahedron::create(int maxlevel)
{
  cleanElement<adaptiveTetrahedron>();
  adaptivePoint *p1 = adaptivePoint::add(0, 0, 0, allPoints);
  adaptivePoint *p2 = adaptivePoint::add(0, 1, 0, allPoints);
  adaptivePoint *p3 = adaptivePoint::add(1, 0, 0, allPoints);
  adaptivePoint *p4 = adaptivePoint::add(0, 0, 1, allPoints);
  adaptiveTetrahedron *t = new adaptiveTetrahedron(p1, p2, p3, p4);
  recurCreate(t, maxlevel, 0);
}

void adaptiveTetrahedron::recurCreate(adaptiveTetrahedron *t, int maxlevel, int level)
{
  all.push_back(t);
  if(level++ >= maxlevel) return;

  adaptivePoint *p0 = t->p[0];
  adaptivePoint *p1 = t->p[1];
  adaptivePoint *p2 = t->p[2];
  adaptivePoint *p3 = t->p[3];
  adaptivePoint *pe0 = adaptivePoint::add
    ((p0->x + p1->x) * 0.5, (p0->y + p1->y) * 0.5, (p0->z + p1->z) * 0.5,
     allPoints);
  adaptivePoint *pe1 = adaptivePoint::add
    ((p0->x + p2->x) * 0.5, (p0->y + p2->y) * 0.5, (p0->z + p2->z) * 0.5,
     allPoints);
  adaptivePoint *pe2 = adaptivePoint::add
    ((p0->x + p3->x) * 0.5, (p0->y + p3->y) * 0.5, (p0->z + p3->z) * 0.5,
     allPoints);
  adaptivePoint *pe3 = adaptivePoint::add
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     allPoints);
  adaptivePoint *pe4 = adaptivePoint::add
    ((p1->x + p3->x) * 0.5, (p1->y + p3->y) * 0.5, (p1->z + p3->z) * 0.5,
     allPoints);
  adaptivePoint *pe5 = adaptivePoint::add
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5,
     allPoints);
  adaptiveTetrahedron *t1 = new adaptiveTetrahedron(p0, pe0, pe2, pe1);
  recurCreate(t1, maxlevel, level);
  adaptiveTetrahedron *t2 = new adaptiveTetrahedron(p1, pe0, pe3, pe4);
  recurCreate(t2, maxlevel, level);
  adaptiveTetrahedron *t3 = new adaptiveTetrahedron(p2, pe3, pe1, pe5);
  recurCreate(t3, maxlevel, level);
  adaptiveTetrahedron *t4 = new adaptiveTetrahedron(p3, pe2, pe4, pe5);
  recurCreate(t4, maxlevel, level);
  adaptiveTetrahedron *t5 = new adaptiveTetrahedron(pe3, pe5, pe2, pe4);
  recurCreate(t5, maxlevel, level);
  adaptiveTetrahedron *t6 = new adaptiveTetrahedron(pe3, pe2, pe0, pe4);
  recurCreate(t6, maxlevel, level);
  adaptiveTetrahedron *t7 = new adaptiveTetrahedron(pe2, pe5, pe3, pe1);
  recurCreate(t7, maxlevel, level);
  adaptiveTetrahedron *t8 = new adaptiveTetrahedron(pe0, pe2, pe3, pe1);
  recurCreate(t8, maxlevel, level);
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

void adaptiveHexahedron::create(int maxlevel)
{
  cleanElement<adaptiveHexahedron>();
  adaptivePoint *p1 = adaptivePoint::add(-1, -1, -1, allPoints);
  adaptivePoint *p2 = adaptivePoint::add(-1, 1, -1, allPoints);
  adaptivePoint *p3 = adaptivePoint::add(1, 1, -1, allPoints);
  adaptivePoint *p4 = adaptivePoint::add(1, -1, -1, allPoints);
  adaptivePoint *p11 = adaptivePoint::add(-1, -1, 1, allPoints);
  adaptivePoint *p21 = adaptivePoint::add(-1, 1, 1, allPoints);
  adaptivePoint *p31 = adaptivePoint::add(1, 1, 1, allPoints);
  adaptivePoint *p41 = adaptivePoint::add(1, -1, 1, allPoints);
  adaptiveHexahedron *h = new adaptiveHexahedron(p1, p2, p3, p4, p11, p21, p31, p41);
  recurCreate(h, maxlevel, 0);
}

void adaptiveHexahedron::recurCreate(adaptiveHexahedron *h, int maxlevel, int level)
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
  adaptivePoint *p01 = adaptivePoint::add
    ((p0->x + p1->x) * 0.5, (p0->y + p1->y) * 0.5, (p0->z + p1->z) * 0.5, 
     allPoints);
  adaptivePoint *p12 = adaptivePoint::add
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5,
     allPoints);
  adaptivePoint *p23 = adaptivePoint::add
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5,
     allPoints);
  adaptivePoint *p03 = adaptivePoint::add
    ((p3->x + p0->x) * 0.5, (p3->y + p0->y) * 0.5, (p3->z + p0->z) * 0.5,
     allPoints);
  adaptivePoint *p45 = adaptivePoint::add
    ((p4->x + p5->x) * 0.5, (p4->y + p5->y) * 0.5, (p4->z + p5->z) * 0.5,
     allPoints);
  adaptivePoint *p56 = adaptivePoint::add
    ((p5->x + p6->x) * 0.5, (p5->y + p6->y) * 0.5, (p5->z + p6->z) * 0.5,
     allPoints);
  adaptivePoint *p67 = adaptivePoint::add
    ((p6->x + p7->x) * 0.5, (p6->y + p7->y) * 0.5, (p6->z + p7->z) * 0.5,
     allPoints);
  adaptivePoint *p47 = adaptivePoint::add
    ((p7->x + p4->x) * 0.5, (p7->y + p4->y) * 0.5, (p7->z + p4->z) * 0.5,
     allPoints);
  adaptivePoint *p04 = adaptivePoint::add
    ((p4->x + p0->x) * 0.5, (p4->y + p0->y) * 0.5, (p4->z + p0->z) * 0.5,
     allPoints);
  adaptivePoint *p15 = adaptivePoint::add
    ((p5->x + p1->x) * 0.5, (p5->y + p1->y) * 0.5, (p5->z + p1->z) * 0.5,
     allPoints);
  adaptivePoint *p26 = adaptivePoint::add
    ((p6->x + p2->x) * 0.5, (p6->y + p2->y) * 0.5, (p6->z + p2->z) * 0.5,
     allPoints);
  adaptivePoint *p37 = adaptivePoint::add
    ((p7->x + p3->x) * 0.5, (p7->y + p3->y) * 0.5, (p7->z + p3->z) * 0.5,
     allPoints);
  adaptivePoint *p0145 = adaptivePoint::add
    ((p45->x + p01->x) * 0.5, (p45->y + p01->y) * 0.5,(p45->z + p01->z) * 0.5, 
     allPoints);
  adaptivePoint *p1256 = adaptivePoint::add
    ((p12->x + p56->x) * 0.5, (p12->y + p56->y) * 0.5, (p12->z + p56->z) * 0.5, 
     allPoints);
  adaptivePoint *p2367 = adaptivePoint::add
    ((p23->x + p67->x) * 0.5, (p23->y + p67->y) * 0.5, (p23->z + p67->z) * 0.5, 
     allPoints);
  adaptivePoint *p0347 = adaptivePoint::add
    ((p03->x + p47->x) * 0.5, (p03->y + p47->y) * 0.5, (p03->z + p47->z) * 0.5,
     allPoints);
  adaptivePoint *p4756 = adaptivePoint::add
    ((p47->x + p56->x) * 0.5, (p47->y + p56->y) * 0.5, (p47->z + p56->z) * 0.5, 
     allPoints);
  adaptivePoint *p0312 = adaptivePoint::add
    ((p03->x + p12->x) * 0.5, (p03->y + p12->y) * 0.5, (p03->z + p12->z) * 0.5,
     allPoints);
  adaptivePoint *pc = adaptivePoint::add
    ((p0->x + p1->x + p2->x + p3->x + p4->x + p5->x + p6->x + p7->x) * 0.125,
     (p0->y + p1->y + p2->y + p3->y + p4->y + p5->y + p6->y + p7->y) * 0.125,
     (p0->z + p1->z + p2->z + p3->z + p4->z + p5->z + p6->z + p7->z) * 0.125,
     allPoints);

  adaptiveHexahedron *h1 = new adaptiveHexahedron
    (p0, p01, p0312, p03, p04, p0145, pc, p0347); // p0
  recurCreate(h1, maxlevel, level);
  adaptiveHexahedron *h2 = new adaptiveHexahedron
    (p01, p0145, p15, p1, p0312, pc, p1256, p12); // p1
  recurCreate(h2, maxlevel, level);
  adaptiveHexahedron *h3 = new adaptiveHexahedron
    (p04, p4, p45, p0145, p0347, p47, p4756, pc); // p4
  recurCreate(h3, maxlevel, level);
  adaptiveHexahedron *h4 = new adaptiveHexahedron
    (p0145, p45, p5, p15, pc, p4756, p56, p1256); // p5
  recurCreate(h4, maxlevel, level);
  adaptiveHexahedron *h5 = new adaptiveHexahedron
    (p0347, p47, p4756, pc, p37, p7, p67, p2367); // p7
  recurCreate(h5, maxlevel, level);
  adaptiveHexahedron *h6 = new adaptiveHexahedron
    (pc, p4756, p56, p1256, p2367, p67, p6, p26); // p6
  recurCreate(h6, maxlevel, level);
  adaptiveHexahedron *h7 = new adaptiveHexahedron
    (p03, p0347, pc, p0312, p3, p37, p2367, p23); // p3
  recurCreate(h7, maxlevel, level);
  adaptiveHexahedron *h8 = new adaptiveHexahedron
    (p0312, pc, p1256, p12, p23, p2367, p26, p2); //p2
  recurCreate(h8, maxlevel, level);
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

void adaptivePrism::create(int maxlevel)
{
  cleanElement<adaptivePrism>();
  adaptivePoint *p1 = adaptivePoint::add(0, 0, -1, allPoints);
  adaptivePoint *p2 = adaptivePoint::add(1, 0, -1, allPoints);
  adaptivePoint *p3 = adaptivePoint::add(0, 1, -1, allPoints);
  adaptivePoint *p4 = adaptivePoint::add(0, 0, 1, allPoints);
  adaptivePoint *p5 = adaptivePoint::add(1, 0, 1, allPoints);
  adaptivePoint *p6 = adaptivePoint::add(0, 1, 1, allPoints);
  adaptivePrism *p = new adaptivePrism(p1, p2, p3, p4, p5, p6);
  recurCreate(p, maxlevel, 0);
}

void adaptivePrism::recurCreate(adaptivePrism *p, int maxlevel, int level)
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
  adaptivePoint *p14 = adaptivePoint::add
    ((p1->x + p4->x) * 0.5, (p1->y + p4->y) * 0.5, (p1->z + p4->z) * 0.5, 
     allPoints);
  adaptivePoint *p25 = adaptivePoint::add
    ((p2->x + p5->x) * 0.5, (p2->y + p5->y) * 0.5, (p2->z + p5->z) * 0.5, 
     allPoints);
  adaptivePoint *p36 = adaptivePoint::add
    ((p3->x + p6->x) * 0.5, (p3->y + p6->y) * 0.5, (p3->z + p6->z) * 0.5, 
     allPoints);
  adaptivePoint *p12 = adaptivePoint::add
    ((p1->x + p2->x) * 0.5, (p1->y + p2->y) * 0.5, (p1->z + p2->z) * 0.5, 
     allPoints);
  adaptivePoint *p23 = adaptivePoint::add
    ((p2->x + p3->x) * 0.5, (p2->y + p3->y) * 0.5, (p2->z + p3->z) * 0.5, 
     allPoints);
  adaptivePoint *p31 = adaptivePoint::add
    ((p3->x + p1->x) * 0.5, (p3->y + p1->y) * 0.5, (p3->z + p1->z) * 0.5, 
     allPoints);
  adaptivePoint *p1425 = adaptivePoint::add
    ((p14->x + p25->x) * 0.5, (p14->y + p25->y) * 0.5, (p14->z + p25->z) * 0.5, 
     allPoints);
  adaptivePoint *p2536 = adaptivePoint::add
    ((p25->x + p36->x) * 0.5, (p25->y + p36->y) * 0.5, (p25->z + p36->z) * 0.5, 
     allPoints);
  adaptivePoint *p3614 = adaptivePoint::add
    ((p36->x + p14->x) * 0.5, (p36->y + p14->y) * 0.5, (p36->z + p14->z) * 0.5, 
     allPoints);
  adaptivePoint *p45 = adaptivePoint::add
    ((p4->x + p5->x) * 0.5, (p4->y + p5->y) * 0.5, (p4->z + p5->z) * 0.5, 
     allPoints);
  adaptivePoint *p56 = adaptivePoint::add
    ((p5->x + p6->x) * 0.5, (p5->y + p6->y) * 0.5, (p5->z + p6->z) * 0.5, 
     allPoints);
  adaptivePoint *p64 = adaptivePoint::add
    ((p6->x + p4->x) * 0.5, (p6->y + p4->y) * 0.5, (p6->z + p4->z) * 0.5, 
     allPoints);
  p->e[0] = new adaptivePrism(p1, p12, p31, p14, p1425, p3614);
  recurCreate(p->e[0], maxlevel, level);
  p->e[1] = new adaptivePrism(p2, p23, p12, p25, p2536, p1425);
  recurCreate(p->e[1], maxlevel, level);
  p->e[2] = new adaptivePrism(p3, p31, p23, p36, p3614, p2536);
  recurCreate(p->e[2], maxlevel, level);
  p->e[3] = new adaptivePrism(p12, p23, p31, p1425, p2536, p3614);
  recurCreate(p->e[3], maxlevel, level);
  p->e[4] = new adaptivePrism(p14, p1425, p3614, p4, p45, p64);
  recurCreate(p->e[4], maxlevel, level);
  p->e[5] = new adaptivePrism(p25, p2536, p1425, p5, p56, p45);
  recurCreate(p->e[5], maxlevel, level);
  p->e[6] = new adaptivePrism(p36, p3614, p2536, p6, p64, p56);
  recurCreate(p->e[6], maxlevel, level);
  p->e[7] = new adaptivePrism(p1425, p2536, p3614, p45, p56, p64);
  recurCreate(p->e[7], maxlevel, level);
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
      bool err = false;
      double ve[8];
      for(int i = 0; i < 8; i++){
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
        for(int i = 0; i < 8; i++)
          recurError(p->e[i], AVG, tol);
      }
      else
        p->visible = true;
    }
  }
}

template <class T>
adaptiveElements<T>::adaptiveElements(std::vector<Double_Matrix*> &p)
  : _coeffsVal(0), _eexpsVal(0), _interpolVal(0),
    _coeffsGeom(0), _eexpsGeom(0), _interpolGeom(0)
{
  if(p.size() >= 2){
    _coeffsVal = p[0];
    _eexpsVal = p[1];
  }
  if(p.size() == 4){
    _coeffsGeom = p[2];
    _eexpsGeom = p[3];
  }
}

template <class T>
adaptiveElements<T>::~adaptiveElements()
{
  if(_interpolVal) delete _interpolVal;
  if(_interpolGeom) delete _interpolGeom;
  cleanElement<T>();
}

template <class T>
void adaptiveElements<T>::init(int level)
{
  T::create(level);
  int numVals = _coeffsVal ? _coeffsVal->size1() : T::numNodes;
  int numNodes = _coeffsGeom ? _coeffsGeom->size1() : T::numNodes;
  
  if(_interpolVal) delete _interpolVal;
  _interpolVal = new Double_Matrix(T::allPoints.size(), numVals);
  
  if(_interpolGeom) delete _interpolGeom;
  _interpolGeom = new Double_Matrix(T::allPoints.size(), numNodes);
  
  Double_Vector sfv(numVals), *tmpv = 0;
  Double_Vector sfg(numNodes), *tmpg = 0;
  if(_eexpsVal) tmpv = new Double_Vector(_eexpsVal->size1());
  if(_eexpsGeom) tmpg = new Double_Vector(_eexpsGeom->size1());

  int i = 0;
  for(std::set<adaptivePoint>::iterator it = T::allPoints.begin(); 
      it != T::allPoints.end(); ++it) {

    if(_coeffsVal && _eexpsVal)
      computeShapeFunctions(_coeffsVal, _eexpsVal, it->x, it->y, it->z, &sfv, tmpv);
    else
      T::GSF(it->x, it->y, it->z, sfv);
    for(int j = 0; j < numVals; j++)
      (*_interpolVal)(i, j) = sfv(j);

    if(_coeffsGeom && _eexpsGeom)
      computeShapeFunctions(_coeffsGeom, _eexpsGeom, it->x, it->y, it->z, &sfg, tmpg);
    else
      T::GSF(it->x, it->y, it->z, sfg);
    for(int j = 0; j < numNodes; j++)
      (*_interpolGeom)(i, j) = sfg(j);

    i++;
  }

  if(tmpv) delete tmpv;
  if(tmpg) delete tmpg;
}

template <class T>
void adaptiveElements<T>::adapt(double tol, int numComp, 
                                std::vector<PCoords> &coords,
                                std::vector<PValues> &values, 
                                double &minVal, double &maxVal, 
                                GMSH_Post_Plugin *plug,
                                bool onlyComputeMinMax)
{
  if(numComp != 1 && numComp != 3){
    Msg::Error("Can only adapt scalar or vector data");
    return;
  }
  
  int numPoints = T::allPoints.size();

  if(!numPoints){
    Msg::Error("No adapted points to interpolate");
    return;
  }
  
  int numVals = _coeffsVal ? _coeffsVal->size1() : T::numNodes;
  if(numVals != values.size()){
    Msg::Error("Wrong number of values in adaptation %d != %i", 
               numVals, values.size());
    return;
  }
  
  Double_Vector val(numVals), res(numPoints);
  if(numComp == 1){
    for(int i = 0; i < numVals; i++)
      val(i) = values[i].v[0];
  }
  else{
    for(int i = 0; i < numVals; i++)
      val(i) = values[i].v[0] * values[i].v[0] + values[i].v[1] * values[i].v[1] +
        values[i].v[2] * values[i].v[2];
  }
  _interpolVal->mult(val, res);

  //minVal = VAL_INF;  
  //maxVal = -VAL_INF;  
  for(int i = 0; i < numPoints; i++){
    minVal = std::min(minVal, res(i));
    maxVal = std::max(maxVal, res(i));
  }
  if(onlyComputeMinMax) return;
  
  Double_Vector *resx = 0, *resy = 0, *resz = 0;
  if(numComp == 3){
    Double_Vector valx(numVals), valy(numVals), valz(numVals);
    resx = new Double_Vector(numPoints);
    resy = new Double_Vector(numPoints);
    resz = new Double_Vector(numPoints);
    for(int i = 0; i < numVals; i++){
      valx(i) = values[i].v[0];
      valy(i) = values[i].v[1];
      valz(i) = values[i].v[2];
    }
    _interpolVal->mult(valx, *resx);
    _interpolVal->mult(valy, *resy);
    _interpolVal->mult(valz, *resz);
  }
  
  int numNodes = _coeffsGeom ? _coeffsGeom->size1() : T::numNodes;
  if(numNodes != coords.size()){
    Msg::Error("Wrong number of nodes in adaptation %d != %i", 
               numNodes, coords.size());
    return;
  }
  
  Double_Matrix xyz(numNodes, 3), XYZ(numPoints, 3);
  for(int i = 0; i < numNodes; i++){
    xyz(i, 0) = coords[i].c[0];
    xyz(i, 1) = coords[i].c[1];
    xyz(i, 2) = coords[i].c[2];
  }
  _interpolGeom->mult(xyz, XYZ);
  
  int i = 0;
  for(std::set<adaptivePoint>::iterator it = T::allPoints.begin();
      it != T::allPoints.end(); ++it){
    // ok because we know this will not change the set ordering
    adaptivePoint *p = (adaptivePoint*)&(*it);
    p->val = res(i);
    if(resx){
      p->valx = (*resx)(i);
      p->valy = (*resy)(i);
      p->valz = (*resz)(i);
    }
    p->X = XYZ(i, 0);
    p->Y = XYZ(i, 1);
    p->Z = XYZ(i, 2);
    i++;
  }
  
  if(resx) delete resx;
  if(resy) delete resy;
  if(resz) delete resz;
  
  for(typename std::list<T*>::iterator it = T::all.begin(); 
      it != T::all.end(); it++)
    (*it)->visible = false;
  
  if(!plug || tol != 0.)
    T::error(fabs(maxVal - minVal), tol);
  
  if(plug)
    plug->assignSpecificVisibility();
  
  coords.clear();
  values.clear();
  for(typename std::list<T*>::iterator it = T::all.begin();
      it != T::all.end(); it++){
    if((*it)->visible){
      adaptivePoint **p = (*it)->p;
      for(int i = 0; i < T::numNodes; i++) {
        coords.push_back(PCoords(p[i]->X, p[i]->Y, p[i]->Z));
        if(numComp == 1)
          values.push_back(PValues(p[i]->val));
        else
          values.push_back(PValues(p[i]->valx, p[i]->valy, p[i]->valz));
      }
    }
  }
}

template <class T>
void adaptiveElements<T>::addInView(double tol, int step, 
                                    PViewData *in, PViewDataList *out, 
                                    GMSH_Post_Plugin *plug)
{
  int numComp = in->getNumComponents(0, 0, 0);
  if(numComp != 1 && numComp != 3) return;
  
  int numEle = 0, *outNb = 0;
  List_T *outList = 0;
  switch(T::numEdges){
  case 1: 
    numEle = in->getNumLines(); 
    outNb = (numComp == 1) ? &out->NbSL : &out->NbVL;
    outList = (numComp == 1) ? out->SL : out->VL;
    break;
  case 3:
    numEle = in->getNumTriangles();
    outNb = (numComp == 1) ? &out->NbST : &out->NbVT;
    outList = (numComp == 1) ? out->ST : out->VT;
    break;
  case 4:
    numEle = in->getNumQuadrangles();
    outNb = (numComp == 1) ? &out->NbSQ : &out->NbVQ;
    outList = (numComp == 1) ? out->SQ : out->VQ;
    break;
  case 6:
    numEle = in->getNumTetrahedra();
    outNb = (numComp == 1) ? &out->NbSS : &out->NbVS;
    outList = (numComp == 1) ? out->SS : out->VS;
    break;
  case 9: 
    numEle = in->getNumPrisms();
    outNb = (numComp == 1) ? &out->NbSI : &out->NbVI;
    outList = (numComp == 1) ? out->SI : out->VI;
    break;
  case 12: 
    numEle = in->getNumHexahedra();
    outNb = (numComp == 1) ? &out->NbSH : &out->NbVH;
    outList = (numComp == 1) ? out->SH : out->VH;
    break;
  }
  if(!numEle) return;
  
  List_Reset(outList);
  *outNb = 0;
  
  for(int ent = 0; ent < in->getNumEntities(step); ent++){
    for(int ele = 0; ele < in->getNumElements(step, ent); ele++){
      if(in->skipElement(step, ent, ele) ||
         in->getNumEdges(step, ent, ele) != T::numEdges) continue;
      int numNodes = in->getNumNodes(step, ent, ele);
      std::vector<PCoords> coords;
      for(int i = 0; i < numNodes; i++){
        double x, y, z;
        in->getNode(step, ent, ele, i, x, y, z);
        coords.push_back(PCoords(x, y, z));
      }
      int numVal = in->getNumValues(step, ent, ele);
      std::vector<PValues> values;
      if(numComp == 1){
        for(int i = 0; i < numVal; i++){
          double val;
          in->getValue(step, ent, ele, i, val);
          values.push_back(PValues(val));
        }
      }
      else if(numComp == 3){
        for(int i = 0; i < numVal / 3; i++){
          double vx, vy, vz;
          in->getValue(step, ent, ele, 3 * i, vx); 
          in->getValue(step, ent, ele, 3 * i + 1, vy); 
          in->getValue(step, ent, ele, 3 * i + 2, vz); 
          values.push_back(PValues(vx, vy, vz));
        }
      }
      adapt(tol, numComp, coords, values, out->Min, out->Max, plug);
      *outNb += coords.size() / T::numNodes;
      for(unsigned int i = 0; i < coords.size() / T::numNodes; i++){
        for(int k = 0; k < T::numNodes; ++k) 
          List_Add(outList, &coords[T::numNodes * i + k].c[0]);
        for(int k = 0; k < T::numNodes; ++k) 
          List_Add(outList, &coords[T::numNodes * i + k].c[1]);
        for(int k = 0; k < T::numNodes; ++k) 
          List_Add(outList, &coords[T::numNodes * i + k].c[2]);
        for(int k = 0; k < T::numNodes; ++k)
          for(int l = 0; l < numComp; ++l)
            List_Add(outList, &values[T::numNodes * i + k].v[l]);
      }
    }
  }
}

adaptiveData::adaptiveData(PViewData *data)
  : _step(-1), _level(-1), _tol(-1.), _inData(data), 
    _lines(0), _triangles(0), _quadrangles(0), 
    _tetrahedra(0), _hexahedra(0), _prisms(0)
{
  _outData = new PViewDataList(true);
  std::vector<Double_Matrix*> p;
  if(_inData->getNumLines()){
    _inData->getInterpolationMatrices(1, p);
    _lines = new adaptiveElements<adaptiveLine>(p);
  }
  if(_inData->getNumTriangles()){
    _inData->getInterpolationMatrices(3, p);
    _triangles = new adaptiveElements<adaptiveTriangle>(p);
  }
  if(_inData->getNumQuadrangles()){
    _inData->getInterpolationMatrices(4, p);
    _quadrangles = new adaptiveElements<adaptiveQuadrangle>(p);
  }
  if(_inData->getNumTetrahedra()){
    _inData->getInterpolationMatrices(6, p);
    _tetrahedra = new adaptiveElements<adaptiveTetrahedron>(p);
  }
  if(_inData->getNumPrisms()){
    _inData->getInterpolationMatrices(9, p);
    _prisms = new adaptiveElements<adaptivePrism>(p);
  }
  if(_inData->getNumHexahedra()){
    _inData->getInterpolationMatrices(12, p);
    _hexahedra = new adaptiveElements<adaptiveHexahedron>(p);
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
  delete _outData;
}

void adaptiveData::changeResolution(int step, int level, double tol, GMSH_Post_Plugin *plug)
{
  if(_level != level){
    if(_lines) _lines->init(level);
    if(_triangles) _triangles->init(level);
    if(_quadrangles) _quadrangles->init(level);
    if(_tetrahedra) _tetrahedra->init(level);
    if(_prisms) _prisms->init(level);
    if(_hexahedra) _hexahedra->init(level);
  }
  if(plug || _step != step || _level != level || _tol != tol){
    _outData->setDirty(true);
    if(_lines) _lines->addInView(tol, step, _inData, _outData, plug);
    if(_triangles) _triangles->addInView(tol, step, _inData, _outData, plug);
    if(_quadrangles) _quadrangles->addInView(tol, step, _inData, _outData, plug);
    if(_tetrahedra) _tetrahedra->addInView(tol, step, _inData, _outData, plug);
    if(_prisms) _prisms->addInView(tol, step, _inData, _outData, plug);
    if(_hexahedra) _hexahedra->addInView(tol, step, _inData, _outData, plug);
    _outData->finalize();
  }
  _step = step;
  _level = level;
  _tol = tol;
}
