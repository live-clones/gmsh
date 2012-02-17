// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <set>
#include <map>
#include <algorithm>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceOptimize.h"
#include "meshGFace.h"
#include "GFace.h"
#include "Numeric.h"
#include "STensor3.h"
#include "Context.h"
#include "MLine.h"
#include "MQuadrangle.h"
#include "Field.h"
#include "GModel.h"

double LIMIT_ = 0.5 * sqrt(2.0) * 1;

int MTri3::radiusNorm = 2;

// This function controls the frontal algorithm
static bool isBoundary(MTri3 *t, double limit_, int &active){
  if (t->isDeleted()) return false;
  for (active = 0; active < 3; active++){
    MTri3 *neigh = t->getNeigh(active);
    if (!neigh) return true;
  }
  return false;
}

static bool isActive(MTri3 *t, double limit_, int &active)
{
  if (t->isDeleted()) return false;
  for (active = 0; active < 3; active++){
    MTri3 *neigh = t->getNeigh(active);
    if (!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      return true;
    }
  }
  return false;
}

static bool isActive(MTri3 *t, double limit_, int &i, std::set<MEdge,Less_Edge> *front)
{
  if (t->isDeleted()) return false;
  for (i = 0; i < 3; i++){
    MTri3 *neigh = t->getNeigh(i);
    if (!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      int ip1 = i - 1 < 0 ? 2 : i - 1;
      int ip2 = i; 
      MEdge me (t->tri()->getVertex(ip1),t->tri()->getVertex(ip2));
      if(front->find(me) != front->end()){
	return true;
      }
    }
  }
  return false;
}


static void updateActiveEdges(MTri3 *t, double limit_, std::set<MEdge,Less_Edge> &front)
{
  if (t->isDeleted()) return;
  for (int active = 0; active < 3; active++){
    MTri3 *neigh = t->getNeigh(active);
    if (!neigh || (neigh->getRadius() < limit_ && neigh->getRadius() > 0)) {
      int ip1 = active - 1 < 0 ? 2 : active - 1;
      int ip2 = active; 
      MEdge me (t->tri()->getVertex(ip1),t->tri()->getVertex(ip2));
      front.insert(me);
    }
  }
}


bool circumCenterMetricInTriangle(MTriangle *base, const double *metric,
                                  const std::vector<double> &Us,
                                  const std::vector<double> &Vs)
{
  double R, x[2], uv[2];
  circumCenterMetric(base, metric, Us, Vs, x, R);
  return invMapUV(base, x, Us, Vs, uv, 1.e-8);
}

void circumCenterMetric(double *pa, double *pb, double *pc,
                        const double *metric, double *x, double &Radius2) 
{
  // d = (u2-u1) M (u2-u1) = u2 M u2 + u1 M u1 - 2 u2 M u1 
  double sys[2][2];
  double rhs[2];

  const double a = metric[0];
  const double b = metric[1];
  const double d = metric[2];

  sys[0][0] = 2. * a * (pa[0] - pb[0]) + 2. * b * (pa[1] - pb[1]);
  sys[0][1] = 2. * d * (pa[1] - pb[1]) + 2. * b * (pa[0] - pb[0]);
  sys[1][0] = 2. * a * (pa[0] - pc[0]) + 2. * b * (pa[1] - pc[1]);
  sys[1][1] = 2. * d * (pa[1] - pc[1]) + 2. * b * (pa[0] - pc[0]);

  rhs[0] =
    a * (pa[0] * pa[0] - pb[0] * pb[0]) + 
    d * (pa[1] * pa[1] - pb[1] * pb[1]) + 
    2. * b * (pa[0] * pa[1] - pb[0] * pb[1]);
  rhs[1] =
    a * (pa[0] * pa[0] - pc[0] * pc[0]) + 
    d * (pa[1] * pa[1] - pc[1] * pc[1]) + 
    2. * b * (pa[0] * pa[1] - pc[0] * pc[1]);

  if (!sys2x2(sys, rhs, x)){
    //    printf("%g %g %g\n",a,b,d);
  }

  Radius2 = 
    (x[0] - pa[0]) * (x[0] - pa[0]) * a +
    (x[1] - pa[1]) * (x[1] - pa[1]) * d +
    2. * (x[0] - pa[0]) * (x[1] - pa[1]) * b;
}

void circumCenterMetricXYZ(double *p1, double *p2, double *p3, SMetric3 & metric, 
                           double *res, double *uv, double &radius)
{
  double v1[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double v2[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3]; prodve(vx, vy, vz); prodve(vz, vx, vy);
  norme(vx); norme(vy); norme(vz);
  double p1P[2] = {0.0, 0.0};
  double p2P[2]; prosca(v1, vx, &p2P[0]); prosca(v1, vy, &p2P[1]);
  double p3P[2]; prosca(v2, vx, &p3P[0]); prosca(v2, vy, &p3P[1]);
  double resP[2];

  fullMatrix<double> T(3,3);
  for (int i = 0; i < 3; i++)T(0,i) = vx[i];
  for (int i = 0; i < 3; i++)T(1,i) = vy[i];
  for (int i = 0; i < 3; i++)T(2,i) = vz[i];
  SMetric3 tra = metric.transform(T);
  double mm[3] = {tra(0,0),tra(0,1),tra(1,1)};

  circumCenterMetric(p1P, p2P, p3P, mm, resP, radius);
  
  if(uv){
    double mat[2][2] = {{p2P[0] - p1P[0], p3P[0] - p1P[0]},
                        {p2P[1] - p1P[1], p3P[1] - p1P[1]}};
    double rhs[2] = {resP[0] - p1P[0], resP[1] - p1P[1]};
    sys2x2(mat, rhs, uv);
  }
  
  res[0] = p1[0] + resP[0] * vx[0] + resP[1] * vy[0];
  res[1] = p1[1] + resP[0] * vx[1] + resP[1] * vy[1];
  res[2] = p1[2] + resP[0] * vx[2] + resP[1] * vy[2];
}

void circumCenterMetric(MTriangle *base, const double *metric,
                        const std::vector<double> &Us,
                        const std::vector<double> &Vs,
                        double *x, double &Radius2) 
{
  // d = (u2-u1) M (u2-u1) = u2 M u2 + u1 M u1 - 2 u2 M u1 
  double pa[2] = {Us[base->getVertex(0)->getIndex()],
                  Vs[base->getVertex(0)->getIndex()]};
  double pb[2] = {Us[base->getVertex(1)->getIndex()],
                  Vs[base->getVertex(1)->getIndex()]};
  double pc[2] = {Us[base->getVertex(2)->getIndex()],
                  Vs[base->getVertex(2)->getIndex()]};
  circumCenterMetric(pa, pb, pc, metric, x, Radius2);
}

void buildMetric(GFace *gf, double *uv, double *metric)
{
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));
  
  metric[0] = dot(der.first(), der.first());
  metric[1] = dot(der.second(), der.first());
  metric[2] = dot(der.second(), der.second());
} 

// m 3x3 
// d 3x2
// M = d^T m d 

void buildMetric(GFace *gf, double *uv, SMetric3 & m, double *metric)
{

  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));

  SVector3 x1(m(0,0) * der.first().x() +
              m(1,0) * der.first().y() +
              m(2,0) * der.first().z(),
              m(0,1) * der.first().x() +
              m(1,1) * der.first().y() +
              m(2,1) * der.first().z(),
              m(0,2) * der.first().x() +
              m(1,2) * der.first().y() +
              m(2,2) * der.first().z());
  SVector3 x2(m(0,0) * der.second().x() +
              m(1,0) * der.second().y() +
              m(2,0) * der.second().z(),
              m(0,1) * der.second().x() +
              m(1,1) * der.second().y() +
              m(2,1) * der.second().z(),
              m(0,2) * der.second().x() +
              m(1,2) * der.second().y() +
              m(2,2) * der.second().z());

  metric[0] = dot(x1, der.first());
  metric[1] = dot(x2, der.first());
  metric[2] = dot(x2, der.second());
} 

int inCircumCircleAniso(GFace *gf, double *p1, double *p2, double *p3, 
                        double *uv, double *metric) 
{
  double x[2], Radius2;
  circumCenterMetric(p1, p2, p3, metric, x, Radius2);
  const double a = metric[0];
  const double b = metric[1];
  const double d = metric[2];
  double d2 = (x[0] - uv[0]) * (x[0] - uv[0]) * a
    + (x[1] - uv[1]) * (x[1] - uv[1]) * d
    + 2. * (x[0] - uv[0]) * (x[1] - uv[1]) * b;
  return d2 < Radius2;  
}

int inCircumCircleAniso(GFace *gf, MTriangle *base, 
                        const double *uv, const double *metricb,
                        const std::vector<double> &Us,
                        const std::vector<double> &Vs) 
{
  double x[2], Radius2, metric[3];
  double pa[2] = {(Us[base->getVertex(0)->getIndex()] + 
                   Us[base->getVertex(1)->getIndex()] +
                   Us[base->getVertex(2)->getIndex()]) / 3.,
                  (Vs[base->getVertex(0)->getIndex()] +
                   Vs[base->getVertex(1)->getIndex()] + 
                   Vs[base->getVertex(2)->getIndex()]) / 3.};
  
  buildMetric(gf, pa, metric);
  circumCenterMetric(base, metric, Us, Vs, x, Radius2);

  const double a = metric[0];
  const double b = metric[1];
  const double d = metric[2];

  double d2 = (x[0] - uv[0]) * (x[0] - uv[0]) * a
    + (x[1] - uv[1]) * (x[1] - uv[1]) * d
    + 2. * (x[0] - uv[0]) * (x[1] - uv[1]) * b;
  
  return d2 < Radius2;  
}

MTri3::MTri3(MTriangle *t, double lc, SMetric3 *metric, const std::vector<double> *Us, const std::vector<double> *Vs, GFace *gf) 
  : deleted(false), base(t)
{
  neigh[0] = neigh[1] = neigh[2] = 0;
  double center[3];
  double pa[3] =
    {base->getVertex(0)->x(), base->getVertex(0)->y(), base->getVertex(0)->z()};
  double pb[3] =
    {base->getVertex(1)->x(), base->getVertex(1)->y(), base->getVertex(1)->z()};
  double pc[3] =
    {base->getVertex(2)->x(), base->getVertex(2)->y(), base->getVertex(2)->z()};

  // compute the circumradius of the triangle
  
  if (!metric){
    if (radiusNorm == 2){
      circumCenterXYZ(pa, pb, pc, center);
      const double dx = base->getVertex(0)->x() - center[0];
      const double dy = base->getVertex(0)->y() - center[1];
      const double dz = base->getVertex(0)->z() - center[2];    
      circum_radius = sqrt(dx * dx + dy * dy + dz * dz);
      circum_radius /= lc;
    }
    else {
      double p1[2] = {(*Us)[base->getVertex(0)->getIndex()],
		      (*Vs)[base->getVertex(0)->getIndex()]};
      double p2[2] = {(*Us)[base->getVertex(1)->getIndex()],
		      (*Vs)[base->getVertex(1)->getIndex()]};
      double p3[2] = {(*Us)[base->getVertex(2)->getIndex()],
		      (*Vs)[base->getVertex(2)->getIndex()]};
      
      double midpoint[2] = {(p1[0]+p2[0]+p3[0])/3.0,(p1[1]+p2[1]+p3[1])/3.0};

      double quadAngle  =  backgroundMesh::current() ? backgroundMesh::current()->getAngle (midpoint[0],midpoint[1],0) : 0.0;            

      double x0 =  p1[0] * cos(quadAngle) + p1[1] * sin(quadAngle);
      double y0 = -p1[0] * sin(quadAngle) + p1[1] * cos(quadAngle); 
      double x1 =  p2[0] * cos(quadAngle) + p2[1] * sin(quadAngle);
      double y1 = -p2[0] * sin(quadAngle) + p2[1] * cos(quadAngle); 
      double x2 =  p3[0] * cos(quadAngle) + p3[1] * sin(quadAngle);
      double y2 = -p3[0] * sin(quadAngle) + p3[1] * cos(quadAngle); 
      double xmax = std::max(std::max(x0,x1),x2);
      double ymax = std::max(std::max(y0,y1),y2);
      double xmin = std::min(std::min(x0,x1),x2);
      double ymin = std::min(std::min(y0,y1),y2);
      
      double metric[3];
      buildMetric(gf, midpoint, metric);
      double RATIO = 1./pow(metric[0]*metric[2]-metric[1]*metric[1],0.25);

      circum_radius = std::max(xmax-xmin,ymax-ymin) / RATIO;
      circum_radius /= lc;      
    }
  }
  else{
    double uv[2];
    circumCenterMetricXYZ(pa, pb, pc, *metric, center, uv, circum_radius);    
  }
}


int MTri3::inCircumCircle(const double *p) const
{
  double pa[3] =
    {base->getVertex(0)->x(), base->getVertex(0)->y(), base->getVertex(0)->z()};
  double pb[3] =
    {base->getVertex(1)->x(), base->getVertex(1)->y(), base->getVertex(1)->z()};
  double pc[3] =
    {base->getVertex(2)->x(), base->getVertex(2)->y(), base->getVertex(2)->z()};
  double fourth[3];
  fourthPoint(pa, pb, pc, fourth);

  double result = robustPredicates::insphere(pa, pb, pc, fourth, (double*)p) * 
    robustPredicates::orient3d(pa, pb, pc,fourth);  
  return (result > 0) ? 1 : 0;  
}

int inCircumCircle(MTriangle *base, 
                   const double *p, const double *param ,
                   std::vector<double> &Us, std::vector<double> &Vs) 
{
  double pa[2] = {Us[base->getVertex(0)->getIndex()],
                  Vs[base->getVertex(0)->getIndex()]};
  double pb[2] = {Us[base->getVertex(1)->getIndex()],
                  Vs[base->getVertex(1)->getIndex()]};
  double pc[2] = {Us[base->getVertex(2)->getIndex()],
                  Vs[base->getVertex(2)->getIndex()]};

  double result = robustPredicates::incircle(pa, pb, pc, (double*)param) * 
    robustPredicates::orient2d(pa, pb, pc);  
  return (result > 0) ? 1 : 0;  
}

template <class ITER>
void connectTris(ITER beg, ITER end)
{
  std::set<edgeXface> conn;
  while (beg != end){
    if (!(*beg)->isDeleted()){
      for (int i = 0; i < 3; i++){
        edgeXface fxt(*beg, i);
        std::set<edgeXface>::iterator found = conn.find(fxt);
        if (found == conn.end())
          conn.insert(fxt);
        else if (found->t1 != *beg){
          found->t1->setNeigh(found->i1, *beg);
          (*beg)->setNeigh(i, found->t1);
        }
      }
    }
    ++beg;
  }
}

void connectTriangles(std::list<MTri3*> &l)
{
  connectTris(l.begin(), l.end());
}

void connectTriangles(std::vector<MTri3*> &l)
{
  connectTris(l.begin(), l.end());
}

void connectTriangles(std::set<MTri3*, compareTri3Ptr> &l)
{
  connectTris(l.begin(), l.end());
}

void recurFindCavity(std::list<edgeXface> &shell, std::list<MTri3*> &cavity, 
                     double *v, double *param, MTri3 *t,
                     std::vector<double> &Us, std::vector<double> &Vs)
{
  t->setDeleted(true);
  // the cavity that has to be removed because it violates delaunay
  // criterion
  cavity.push_back(t);

  for (int i = 0; i < 3; i++){
    MTri3 *neigh =  t->getNeigh(i) ;
    if (!neigh)
      shell.push_back(edgeXface(t, i));
    else if (!neigh->isDeleted()){
      int circ =  inCircumCircle(neigh->tri(), v , param, Us, Vs);
      if (circ)
        recurFindCavity(shell, cavity, v, param, neigh, Us, Vs);
      else
        shell.push_back(edgeXface(t, i));
    }
  }
}

void recurFindCavityAniso(GFace *gf,
                          std::list<edgeXface> &shell, std::list<MTri3*> &cavity, 
                          double *metric, double *param,  MTri3 *t,
                          std::vector<double> &Us, std::vector<double> &Vs)
{
  t->setDeleted(true);
  // the cavity that has to be removed because it violates delaunay
  // criterion
  cavity.push_back(t);

  for (int i = 0; i < 3; i++){
    MTri3 *neigh = t->getNeigh(i) ;
    if (!neigh)
      shell.push_back(edgeXface(t, i));
    else  if (!neigh->isDeleted()){
      int circ =  inCircumCircleAniso(gf, neigh->tri(), param, metric, Us, Vs);
      if (circ)
        recurFindCavityAniso(gf, shell, cavity,metric, param, neigh, Us, Vs);
      else
        shell.push_back(edgeXface(t, i));
    }
  }
}

bool circUV(MTriangle *t, std::vector<double> & Us, std::vector<double> &Vs,
            double *res, GFace *gf)
{
  double u1[3] = {Us[t->getVertex(0)->getIndex()], Vs[t->getVertex(0)->getIndex()], 0};
  double u2[3] = {Us[t->getVertex(1)->getIndex()], Vs[t->getVertex(1)->getIndex()], 0};
  double u3[3] = {Us[t->getVertex(2)->getIndex()], Vs[t->getVertex(2)->getIndex()], 0};
  circumCenterXY(u1, u2, u3, res);
  return true;
  double p1[3] = {t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z()};
  double p2[3] = {t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z()};
  double p3[3] = {t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z()};
  double resxy[3], uv[2];
  circumCenterXYZ(p1, p2, p3, resxy,uv);
  return true;
}

bool invMapUV(MTriangle *t, double *p,
              const std::vector<double> &Us, const std::vector<double> &Vs,
              double *uv, double tol)
{
  double mat[2][2];
  double b[2];

  double u0 = Us[t->getVertex(0)->getIndex()];
  double v0 = Vs[t->getVertex(0)->getIndex()];
  double u1 = Us[t->getVertex(1)->getIndex()];
  double v1 = Vs[t->getVertex(1)->getIndex()];
  double u2 = Us[t->getVertex(2)->getIndex()];
  double v2 = Vs[t->getVertex(2)->getIndex()];

  mat[0][0] = u1 - u0;
  mat[0][1] = u2 - u0;
  mat[1][0] = v1 - v0;
  mat[1][1] = v2 - v0;

  b[0] = p[0] - u0;
  b[1] = p[1] - v0;
  sys2x2(mat, b, uv);

  if(uv[0] >= -tol && 
     uv[1] >= -tol && 
     uv[0] <= 1. + tol && 
     uv[1] <= 1. + tol && 
     1. - uv[0] - uv[1] > -tol) {
    return true;
  }
  return false; 
}

double getSurfUV(MTriangle *t, std::vector<double> &Us, std::vector<double> &Vs)
{
  double u1 = Us[t->getVertex(0)->getIndex()];
  double v1 = Vs[t->getVertex(0)->getIndex()];
  double u2 = Us[t->getVertex(1)->getIndex()];
  double v2 = Vs[t->getVertex(1)->getIndex()];
  double u3 = Us[t->getVertex(2)->getIndex()];
  double v3 = Vs[t->getVertex(2)->getIndex()];
  const double vv1[2] = {u2 - u1, v2 - v1};
  const double vv2[2] = {u3 - u1, v3 - v1};
  double s = vv1[0] * vv2[1] - vv1[1] * vv2[0]; 
  return s * 0.5;
}

bool insertVertex(bool force, GFace *gf, MVertex *v, double *param , MTri3 *t,
                  std::set<MTri3*, compareTri3Ptr> &allTets,
                  std::set<MTri3*, compareTri3Ptr> *activeTets,
                  std::vector<double> &vSizes, 
                  std::vector<double> &vSizesBGM,
                  std::vector<SMetric3> &vMetricsBGM,
                  std::vector<double> &Us, 
                  std::vector<double> &Vs,
                  double *metric = 0)
{
  std::list<edgeXface> shell;
  std::list<MTri3*> cavity; 
  std::list<MTri3*> new_cavity;

  if (!metric){
    double p[3] = {v->x(), v->y(), v->z()};
    recurFindCavity(shell, cavity, p, param, t, Us, Vs);
  }
  else{
    recurFindCavityAniso(gf, shell, cavity, metric, param, t, Us, Vs);  
    //    printf("RECURSIVELY FIND A CAVITY %d %d \n",shell.size(),cavity.size());
  }
  
  // check that volume is conserved
  double newVolume = 0;
  double oldVolume = 0;

  std::list<MTri3*>::iterator ittet = cavity.begin();
  std::list<MTri3*>::iterator ittete = cavity.end();
  while(ittet != ittete){
    oldVolume += fabs(getSurfUV((*ittet)->tri(),Us,Vs));
    ++ittet;
  }
  
  MTri3 **newTris = new MTri3*[shell.size()];
  int k = 0;
  std::list<edgeXface>::iterator it = shell.begin();

  bool onePointIsTooClose = false;
  while (it != shell.end()){
    MTriangle *t = new MTriangle(it->v[0], it->v[1], v);
    const double ONE_THIRD = 1./3.;
    double lc = ONE_THIRD * (vSizes[t->getVertex(0)->getIndex()] +
                             vSizes[t->getVertex(1)->getIndex()] +
                             vSizes[t->getVertex(2)->getIndex()]);
    double lcBGM = ONE_THIRD * (vSizesBGM[t->getVertex(0)->getIndex()] +
                                vSizesBGM[t->getVertex(1)->getIndex()] +
                                vSizesBGM[t->getVertex(2)->getIndex()]);
    double LL = Extend1dMeshIn2dSurfaces() ? std::min(lc, lcBGM) : lcBGM;

    MTri3 *t4;
    t4 = new MTri3(t, LL,0,&Us,&Vs,gf); 
    
    double d1 = sqrt((it->v[0]->x() - v->x()) * (it->v[0]->x() - v->x()) +
                     (it->v[0]->y() - v->y()) * (it->v[0]->y() - v->y()) +
                     (it->v[0]->z() - v->z()) * (it->v[0]->z() - v->z()));
    double d2 = sqrt((it->v[1]->x() - v->x()) * (it->v[1]->x() - v->x()) +
                     (it->v[1]->y() - v->y()) * (it->v[1]->y() - v->y()) +
                     (it->v[1]->z() - v->z()) * (it->v[1]->z() - v->z()));
    const double MID[3] = {0.5*(it->v[0]->x()+it->v[1]->x()),0.5*(it->v[0]->y()+it->v[1]->y()),0.5*(it->v[0]->z()+it->v[1]->z())}; 
    double d3 = sqrt((MID[0] - v->x()) * (MID[0] - v->x()) + (MID[1] - v->y()) * (MID[1] - v->y()) + (MID[2] - v->z()) * (MID[2] - v->z()));
    if ((d1 < LL * .25 || d2 < LL * .25 || d3 < LL * .25) && !force) {
      //      printf("TOO CLOSE %g %g %g %g %g %g\n",d1,d2,d3,LL,lc,lcBGM);
      onePointIsTooClose = true;
    }
    // if (t4->getRadius () < LIMIT_ / 2) onePointIsTooClose = true;

    newTris[k++] = t4;
    // all new triangles are pushed front in order to be able to
    // destroy them if the cavity is not star shaped around the new
    // vertex.
    new_cavity.push_back(t4);
    MTri3 *otherSide = it->t1->getNeigh(it->i1);
    if (otherSide)
      new_cavity.push_back(otherSide);
    double ss = fabs(getSurfUV(t4->tri(), Us, Vs));
    if (ss < 1.e-25) ss = 1.e22;
    newVolume += ss;
    ++it;
  }
  if (fabs(oldVolume - newVolume) < 1.e-12 * oldVolume && shell.size() >= 3 && 
      !onePointIsTooClose){
    connectTris(new_cavity.begin(), new_cavity.end());      
    allTets.insert(newTris, newTris + shell.size());
    //    printf("shell.size() = %d triangles.size() = %d \n",shell.size(),allTets.size());
    if (activeTets){
      for (std::list<MTri3*>::iterator i = new_cavity.begin(); i != new_cavity.end(); ++i){
        int active_edge;
        if(isActive(*i, LIMIT_, active_edge) && (*i)->getRadius() > LIMIT_){
          if ((*activeTets).find(*i) == (*activeTets).end())
            (*activeTets).insert(*i);
        }
      }
    }
    delete [] newTris;
    return true;
  }
  // The cavity is NOT star shaped
  else{      
    //    printf("cavity not star shaped %22.15E vs %22.15E\n",oldVolume,newVolume);
    //    printf("shell.size() = %d triangles.size() = %d \n",shell.size(),allTets.size());
    for (unsigned int i = 0; i < shell.size(); i++) delete newTris[i];
    delete [] newTris;      
    ittet = cavity.begin();
    ittete = cavity.end();  
    while(ittet != ittete){
      (*ittet)->setDeleted(false);
      ++ittet;
    }
    return false;
  }
}

void _printTris(char *name, std::set<MTri3*, compareTri3Ptr> &AllTris,
                std::vector<double> &Us, std::vector<double> &Vs, bool param=true)
{
  FILE *ff = fopen (name,"w");
  fprintf(ff,"View\"test\"{\n");
  std::set<MTri3*,compareTri3Ptr>::iterator it = AllTris.begin();
  while (it != AllTris.end() ){
    MTri3 *worst = *it;
    if (!worst->isDeleted()){
      if (param)
        fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
                Us[(worst)->tri()->getVertex(0)->getIndex()],
                Vs[(worst)->tri()->getVertex(0)->getIndex()],
                0.0,
                Us[(worst)->tri()->getVertex(1)->getIndex()],
                Vs[(worst)->tri()->getVertex(1)->getIndex()],
                0.0,
                Us[(worst)->tri()->getVertex(2)->getIndex()],
                Vs[(worst)->tri()->getVertex(2)->getIndex()],
                0.0,
                (worst)->getRadius(),
                (worst)->getRadius(),
                (worst)->getRadius());
      else
        fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {%g,%g,%g};\n",
                (worst)->tri()->getVertex(0)->x(),
                (worst)->tri()->getVertex(0)->y(),
                (worst)->tri()->getVertex(0)->z(),
                (worst)->tri()->getVertex(1)->x(),
                (worst)->tri()->getVertex(1)->y(),
                (worst)->tri()->getVertex(1)->z(),
                (worst)->tri()->getVertex(2)->x(),
                (worst)->tri()->getVertex(2)->y(),
                (worst)->tri()->getVertex(2)->z(),
                (worst)->getRadius(),
                (worst)->getRadius(),
                (worst)->getRadius()
                );
    }
    ++it;
  }
  fprintf(ff,"};\n");
  fclose (ff);
}

static MTri3* search4Triangle (MTri3 *t, double pt[2], 
			       std::vector<double> &Us, std::vector<double> &Vs,
			       std::set<MTri3*,compareTri3Ptr> &AllTris) {
  
  double uv[2];
  bool inside = invMapUV(t->tri(), pt, Us, Vs, uv, 1.e-8);    
  if (inside) return t;
  SPoint3 q1(pt[0],pt[1],0);
  int ITER = 0;
  while (1){
    //    printf("%d %d %d\n",t->tri()->getVertex(0)->getIndex(),t->tri()->getVertex(1)->getIndex() ,t->tri()->getVertex(2)->getIndex());
    SPoint3 q2((Us[t->tri()->getVertex(0)->getIndex()] +  Us[t->tri()->getVertex(1)->getIndex()] + Us[t->tri()->getVertex(2)->getIndex()])/3.0,
	       (Vs[t->tri()->getVertex(0)->getIndex()] +  Vs[t->tri()->getVertex(1)->getIndex()] + Vs[t->tri()->getVertex(2)->getIndex()])/3.0,
	       0);
    int i;
    for (i=0;i<3;i++){
      SPoint3 p1 ( Us[t->tri()->getVertex(i == 0 ? 2 : i-1)->getIndex()], Vs[t->tri()->getVertex(i == 0 ? 2 : i-1)->getIndex()], 0);
      SPoint3 p2 ( Us[t->tri()->getVertex(i)->getIndex()], Vs[t->tri()->getVertex(i)->getIndex()], 0);
      double xcc[2];
      if (intersection_segments(p1,p2,q1,q2,xcc))break;
    }
    if (i>=3)break;
    t =  t->getNeigh(i); 
    if (!t)break;
    bool inside = invMapUV(t->tri(), pt, Us, Vs, uv, 1.e-8);        
    if (inside) {return t;}
    if (ITER++ > AllTris.size())break;
  }

  for(std::set<MTri3*,compareTri3Ptr>::iterator itx =  AllTris.begin(); itx != AllTris.end();++itx){
    if (!(*itx)->isDeleted()){
      inside = invMapUV((*itx)->tri(), pt, Us, Vs, uv, 1.e-8);    
      if (inside){
	return *itx;
      }
    }
  }
  return 0;
}

static bool insertAPoint(GFace *gf, std::set<MTri3*,compareTri3Ptr>::iterator it,
                         double center[2], double metric[3], 
                         std::vector<double> &Us, std::vector<double> &Vs,
                         std::vector<double> &vSizes, 
                         std::vector<double> &vSizesBGM,
                         std::vector<SMetric3> &vMetricsBGM,
                         std::set<MTri3*,compareTri3Ptr> &AllTris,
                         std::set<MTri3*,compareTri3Ptr> *ActiveTris = 0,
                         MTri3 *worst = 0)
{
  if (worst){
    it = AllTris.find(worst);
    if (worst != *it){
      Msg::Error("Could not insert point");
      return false;
    }
  }
  else worst = *it;

  MTri3 *ptin = 0;
  bool inside = false;
  double uv[2];
  // FIXME !!!
  if (MTri3::radiusNorm == 2){
    inside = invMapUV(worst->tri(), center, Us, Vs, uv, 1.e-8);    
    if (inside)ptin = worst;
    if (!inside && worst->getNeigh(0)){
      inside |= invMapUV(worst->getNeigh(0)->tri(), center, Us, Vs, uv, 1.e-8);
      if (inside)ptin = worst->getNeigh(0);
    }
    if (!inside && worst->getNeigh(1)){
      inside |= invMapUV(worst->getNeigh(1)->tri(), center, Us, Vs, uv, 1.e-8);
      if (inside)ptin = worst->getNeigh(1);
    }
    if (!inside && worst->getNeigh(2)){
    inside |= invMapUV(worst->getNeigh(2)->tri(), center, Us, Vs, uv, 1.e-8);
    if (inside)ptin = worst->getNeigh(2);
    }
  }
  else {
    ptin =  search4Triangle (worst, center, Us, Vs, AllTris);
    if (ptin)inside = true;
    //    if (!ptin)printf("strange : %g %g seems to be out of the domain for face %d\n",center[0],center[1],gf->tag());
  }

  //  if (!ptin)ptin = worst;
  if ( inside) {
    // we use here local coordinates as real coordinates
    // x,y and z will be computed hereafter
    // Msg::Info("Point is inside");
    GPoint p = gf->point(center[0], center[1]);
    // printf("the new point is %g %g\n",p.x(),p.y());
    MVertex *v = new MFaceVertex(p.x(), p.y(), p.z(), gf, center[0], center[1]);
    v->setIndex(Us.size());
    double lc1,lc;
    if (backgroundMesh::current()){
      lc1 = lc = 
	backgroundMesh::current()->operator()(center[0], center[1], 0.0);
    }
    else {
      lc1 = ((1. - uv[0] - uv[1]) * vSizes[ptin->tri()->getVertex(0)->getIndex()] + 
		    uv[0] * vSizes[ptin->tri()->getVertex(1)->getIndex()] + 
		    uv[1] * vSizes[ptin->tri()->getVertex(2)->getIndex()]); 
      lc = BGM_MeshSize(gf, center[0], center[1], p.x(), p.y(), p.z());
    }
    //SMetric3 metr = BGM_MeshMetric(gf, center[0], center[1], p.x(), p.y(), p.z());
    //                               vMetricsBGM.push_back(metr);
    vSizesBGM.push_back(lc);
    vSizes.push_back(lc1);
    Us.push_back(center[0]);
    Vs.push_back(center[1]);
    
    if(!p.succeeded() || !insertVertex
       (false, gf, v, center, worst, AllTris,ActiveTris, vSizes, vSizesBGM,vMetricsBGM, 
        Us, Vs, metric) ) {
           
      MTriangle *base = worst->tri();
                  
      //      Msg::Info("Point %g %g cannot be inserted because %d", center[0], center[1], p.succeeded() );
      
      AllTris.erase(it);
      worst->forceRadius(-1);
      AllTris.insert(worst);                    
      delete v;
      return false;
    }
    else {
      //      printf("ouf ! %d\n",AllTris.size());
      gf->mesh_vertices.push_back(v);
      return true;
    }
  }
  else {
    MTriangle *base = worst->tri();    
    /*    
    Msg::Info("Point %g %g is outside (%g %g , %g %g , %g %g)",
	      center[0], center[1],
	      Us[base->getVertex(0)->getIndex()], 
	      Vs[base->getVertex(0)->getIndex()], 
	      Us[base->getVertex(1)->getIndex()], 
	      Vs[base->getVertex(1)->getIndex()], 
	      Us[base->getVertex(2)->getIndex()], 
	      Vs[base->getVertex(2)->getIndex()]);
    */
    AllTris.erase(it);
    worst->forceRadius(0);
    AllTris.insert(worst);
    return false;
  }
}


void bowyerWatson(GFace *gf)
{
  std::set<MTri3*,compareTri3Ptr> AllTris;
  std::vector<double> vSizes, vSizesBGM, Us, Vs;
  std::vector<SMetric3> vMetricsBGM;

  buildMeshGenerationDataStructures
    (gf, AllTris, vSizes, vSizesBGM, vMetricsBGM, Us, Vs);

  // _printTris ("before.pos", AllTris, Us,Vs);
  int nbSwaps = edgeSwapPass(gf, AllTris, SWCR_DEL, Us, Vs, vSizes, vSizesBGM);
  // _printTris ("after2.pos", AllTris, Us,Vs);
  Msg::Debug("Delaunization of the initial mesh done (%d swaps)", nbSwaps);

  if(AllTris.empty()){
    Msg::Error("No triangles in initial mesh");
    return;
  }

  int ITER = 0;
  while (1){
    //    if(ITER % 1== 0){
    //      char name[245];
    //      sprintf(name,"del2d%d-ITER%4d.pos",gf->tag(),ITER);
    //      _printTris (name, AllTris, Us,Vs,false);
    //    }
    MTri3 *worst = *AllTris.begin();
    if (worst->isDeleted()){
      delete worst->tri();
      delete worst;
      AllTris.erase(AllTris.begin());
    }
    else{
      if(ITER++ % 5000 == 0)
        Msg::Debug("%7d points created -- Worst tri radius is %8.3f",
                   vSizes.size(), worst->getRadius());
      double center[2],metric[3],r2;
      if (worst->getRadius() < /*1.333333/(sqrt(3.0))*/0.5 * sqrt(2.0)) break;
      circUV(worst->tri(), Us, Vs, center, gf);
      MTriangle *base = worst->tri();
      double pa[2] = {(Us[base->getVertex(0)->getIndex()] + 
                       Us[base->getVertex(1)->getIndex()] + 
                       Us[base->getVertex(2)->getIndex()]) / 3.,
                      (Vs[base->getVertex(0)->getIndex()] + 
                       Vs[base->getVertex(1)->getIndex()] + 
                       Vs[base->getVertex(2)->getIndex()]) / 3.};
      buildMetric(gf, pa,  metric);
      circumCenterMetric(worst->tri(), metric, Us, Vs, center, r2);       
      insertAPoint(gf, AllTris.begin(), center, metric, Us, Vs, vSizes, 
                   vSizesBGM, vMetricsBGM, AllTris);
    }
  }    
  {
    FieldManager *fields = gf->model()->getFields();
    BoundaryLayerField *blf = 0;
    if(fields->getBackgroundField() > 0){
      Field *bl_field = fields->get(fields->getBoundaryLayerField());
      blf = dynamic_cast<BoundaryLayerField*> (bl_field);
      if (blf && !blf->iRecombine)quadsToTriangles(gf,10000);
    }
  }
  transferDataStructure(gf, AllTris, Us, Vs); 
}

/*
  Let's try a frontal delaunay approach now that the delaunay mesher is stable

  We use the approach of Rebay (JCP 1993) that we extend to anisotropic metrics

  The point isertion is done on the Voronoi Edges
*/

double lengthInfniteNorm(const double p[2], const double q[2], 
				const double quadAngle){
  double xp =  p[0] * cos(quadAngle) + p[1] * sin(quadAngle);
  double yp = -p[0] * sin(quadAngle) + p[1] * cos(quadAngle);
  double xq =  q[0] * cos(quadAngle) + q[1] * sin(quadAngle);
  double yq = -q[0] * sin(quadAngle) + q[1] * cos(quadAngle);
  double xmax = std::max(xp,xq);
  double xmin = std::min(xp,xq);
  double ymax = std::max(yp,yq);
  double ymin = std::min(yp,yq);
  return std::max(xmax-xmin,ymax-ymin);
}

void circumCenterInfinite (MTriangle *base, double quadAngle,                        
			   const std::vector<double> &Us,
			   const std::vector<double> &Vs, double *x) {
  double pa[2] = {Us[base->getVertex(0)->getIndex()],
                  Vs[base->getVertex(0)->getIndex()]};
  double pb[2] = {Us[base->getVertex(1)->getIndex()],
                  Vs[base->getVertex(1)->getIndex()]};
  double pc[2] = {Us[base->getVertex(2)->getIndex()],
                  Vs[base->getVertex(2)->getIndex()]};
  double xa =  pa[0] * cos(quadAngle) - pa[1] * sin(quadAngle);
  double ya =  pa[0] * sin(quadAngle) + pa[1] * cos(quadAngle);
  double xb =  pb[0] * cos(quadAngle) - pb[1] * sin(quadAngle);
  double yb =  pb[0] * sin(quadAngle) + pb[1] * cos(quadAngle);
  double xc =  pc[0] * cos(quadAngle) - pc[1] * sin(quadAngle);
  double yc =  pc[0] * sin(quadAngle) + pc[1] * cos(quadAngle);
  double xmax = std::max(std::max(xa,xb),xc);
  double ymax = std::max(std::max(ya,yb),yc);
  double xmin = std::min(std::min(xa,xb),xc);
  double ymin = std::min(std::min(ya,yb),yc);
  x[0] = 0.5 * (xmax-xmin);
  x[1] = 0.5 * (ymax-ymin);
}


static double lengthMetric(const double p[2], const double q[2], 
                           const double metric[3])
{
  return sqrt (     (p[0] - q[0]) * metric[0] * (p[0] - q[0]) +
                2 * (p[0] - q[0]) * metric[1] * (p[1] - q[1]) +
                    (p[1] - q[1]) * metric[2] * (p[1] - q[1]) );
}

/*
          /|
         / |
        /  |
       /   |
   lc /    |  r
     /     |
    /      |  
   /       x
  /        |    
 /         |  r/2
/          |  
-----------+
     lc/2

     (3 r/2)^2 = lc^2 - lc^2/4 
     -> lc^2 3/4 = 9r^2/4
     -> lc^2 = 3 r^2

     r^2 /4 + lc^2/4 = r^2
     -> lc^2 = 3 r^2
     
*/

void optimalPointFrontal (GFace *gf, 
			  MTri3* worst, 
			  int active_edge,
			  std::vector<double> &Us,
			  std::vector<double> &Vs,
			  std::vector<double> &vSizes,
			  std::vector<double> &vSizesBGM,			  
			  double newPoint[2],
			  double metric[3]){
  double center[2],r2;
  MTriangle *base = worst->tri();
  circUV(base, Us, Vs, center, gf);
  double pa[2] = {(Us[base->getVertex(0)->getIndex()] + 
		   Us[base->getVertex(1)->getIndex()] + 
		   Us[base->getVertex(2)->getIndex()]) / 3.,
		  (Vs[base->getVertex(0)->getIndex()] + 
		   Vs[base->getVertex(1)->getIndex()] + 
		   Vs[base->getVertex(2)->getIndex()]) / 3.};
  buildMetric(gf, pa, metric);
  circumCenterMetric(worst->tri(), metric, Us, Vs, center, r2); 
  // compute the middle point of the edge
  int ip1 = active_edge - 1 < 0 ? 2 : active_edge - 1;
  int ip2 = active_edge;

  double P[2] =  {Us[base->getVertex(ip1)->getIndex()],  
		  Vs[base->getVertex(ip1)->getIndex()]};
  double Q[2] =  {Us[base->getVertex(ip2)->getIndex()], 
		  Vs[base->getVertex(ip2)->getIndex()]};
  double midpoint[2] = {0.5 * (P[0] + Q[0]), 0.5 * (P[1] + Q[1])};
      
  // now we have the edge center and the center of the circumcircle, 
  // we try to find a point that would produce a perfect triangle while
  // connecting the 2 points of the active edge
  
  double dir[2] = {center[0] - midpoint[0], center[1] - midpoint[1]};
  double norm = sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
  dir[0] /= norm;
  dir[1] /= norm;
  const double RATIO = sqrt(dir[0] * dir[0] * metric[0] +
			    2 * dir[1] * dir[0] * metric[1] +
			    dir[1] * dir[1] * metric[2]);    
  
  const double p = 0.5 * lengthMetric(P, Q, metric); // / RATIO;
  const double q = lengthMetric(center, midpoint, metric);
  const double rhoM1 = 0.5 * 
    (vSizes[base->getVertex(ip1)->getIndex()] + 
     vSizes[base->getVertex(ip2)->getIndex()] ) / sqrt(3.);// * RATIO;
  const double rhoM2 = 0.5 * 
    (vSizesBGM[base->getVertex(ip1)->getIndex()] + 
     vSizesBGM[base->getVertex(ip2)->getIndex()] ) / sqrt(3.);// * RATIO;
  const double rhoM  = Extend1dMeshIn2dSurfaces() ? std::min(rhoM1, rhoM2) : rhoM2;
  
  const double rhoM_hat = std::min(std::max(rhoM, p), (p * p + q * q) / (2 * q));
  const double d = (rhoM_hat + sqrt (rhoM_hat * rhoM_hat - p * p)) / RATIO;
  
  //  printf("(%g %g) (%g %g) %g %g %g %g %g %g\n",P[0],P[1],Q[0],Q[1],RATIO,p,q,rhoM,rhoM_hat,d);


  newPoint[0] = midpoint[0] + d * dir[0]; 
  newPoint[1] = midpoint[1] + d * dir[1];
}

/*
            x
            |       
            |       
            | d =  3^{1/2}/2 h       
            |       
            |          
      ------p------->   n
            h
 
   x point of the plane
*/

void optimalPointFrontalB (GFace *gf, 
			   MTri3* worst, 
			   int active_edge,
			   std::vector<double> &Us,
			   std::vector<double> &Vs,
			   std::vector<double> &vSizes,
			   std::vector<double> &vSizesBGM,			  
			   double newPoint[2],
			   double metric[3]){
  double center[2],r2;
  MTriangle *base = worst->tri();
  circUV(base, Us, Vs, center, gf);
  double pa[2] = {(Us[base->getVertex(0)->getIndex()] + 
		   Us[base->getVertex(1)->getIndex()] + 
		   Us[base->getVertex(2)->getIndex()]) / 3.,
		  (Vs[base->getVertex(0)->getIndex()] + 
		   Vs[base->getVertex(1)->getIndex()] + 
		   Vs[base->getVertex(2)->getIndex()]) / 3.};
  buildMetric(gf, pa, metric);
  circumCenterMetric(worst->tri(), metric, Us, Vs, center, r2); 
  // compute the middle point of the edge
  int ip1 = active_edge - 1 < 0 ? 2 : active_edge - 1;
  int ip2 = active_edge;

  double P[2] =  {Us[base->getVertex(ip1)->getIndex()],  
		  Vs[base->getVertex(ip1)->getIndex()]};
  double Q[2] =  {Us[base->getVertex(ip2)->getIndex()], 
		  Vs[base->getVertex(ip2)->getIndex()]};
  double midpoint[2] = {0.5 * (P[0] + Q[0]), 0.5 * (P[1] + Q[1])};
      
  // now we have the edge center and the center of the circumcircle, 
  // we try to find a point that would produce a perfect triangle while
  // connecting the 2 points of the active edge
  
  double dir[2] = {center[0] - midpoint[0], center[1] - midpoint[1]};
  double norm = sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
  dir[0] /= norm;
  dir[1] /= norm;
  const double RATIO = sqrt(dir[0] * dir[0] * metric[0] +
			    2 * dir[1] * dir[0] * metric[1] +
			    dir[1] * dir[1] * metric[2]);    
  
  const double p = 0.5 * lengthMetric(P, Q, metric); // / RATIO;
  const double q = lengthMetric(center, midpoint, metric);
  const double rhoM1 = 0.5 * 
    (vSizes[base->getVertex(ip1)->getIndex()] + 
     vSizes[base->getVertex(ip2)->getIndex()] ) / sqrt(3.);// * RATIO;
  const double rhoM2 = 0.5 * 
    (vSizesBGM[base->getVertex(ip1)->getIndex()] + 
     vSizesBGM[base->getVertex(ip2)->getIndex()] ) / sqrt(3.);// * RATIO;
  const double rhoM  = Extend1dMeshIn2dSurfaces() ? std::min(rhoM1, rhoM2) : rhoM2;
  
  const double rhoM_hat = std::min(std::max(rhoM, p), (p * p + q * q) / (2 * q));
  const double d = (rhoM_hat + sqrt (rhoM_hat * rhoM_hat - p * p)) / RATIO;
  
  //  printf("(%g %g) (%g %g) %g %g %g %g %g %g\n",P[0],P[1],Q[0],Q[1],RATIO,p,q,rhoM,rhoM_hat,d);


  newPoint[0] = midpoint[0] + d * dir[0]; 
  newPoint[1] = midpoint[1] + d * dir[1];
}



void bowyerWatsonFrontal(GFace *gf)
{
  std::set<MTri3*,compareTri3Ptr> AllTris;
  std::set<MTri3*,compareTri3Ptr> ActiveTris;
  std::vector<double> vSizes, vSizesBGM, Us, Vs;
  std::vector<SMetric3> vMetricsBGM;

  buildMeshGenerationDataStructures
    (gf, AllTris, vSizes, vSizesBGM, vMetricsBGM,Us, Vs);

  // delaunise the initial mesh
  int nbSwaps = edgeSwapPass(gf, AllTris, SWCR_DEL, Us, Vs, vSizes, vSizesBGM);
  Msg::Debug("Delaunization of the initial mesh done (%d swaps)", nbSwaps);
  
  int ITER = 0, active_edge;
  // compute active triangle
  std::set<MTri3*,compareTri3Ptr>::iterator it = AllTris.begin();
  for ( ; it!=AllTris.end();++it){
    if(isActive(*it,LIMIT_,active_edge))
      ActiveTris.insert(*it);
    else if ((*it)->getRadius() < LIMIT_)break;
  }

  
  // insert points
  while (1){
    /*
        if(ITER % 1== 0){
          char name[245];
          sprintf(name,"delfr2d%d-ITER%d.pos",gf->tag(),ITER);
          _printTris (name, AllTris, Us,Vs,false);
          sprintf(name,"delfr2dA%d-ITER%d.pos",gf->tag(),ITER);
          _printTris (name, ActiveTris, Us,Vs,false);
        }
    */
    if (!ActiveTris.size())break;
    MTri3 *worst = (*ActiveTris.begin());
    ActiveTris.erase(ActiveTris.begin());
    // printf("active_tris.size = %d\n",ActiveTris.size());

    if (!worst->isDeleted() && isActive(worst, LIMIT_, active_edge) && 
        worst->getRadius() > LIMIT_){
      if(ITER++ % 5000 == 0)
        Msg::Debug("%7d points created -- Worst tri radius is %8.3f",
                   vSizes.size(), worst->getRadius());
      double newPoint[2], metric[3];
      optimalPointFrontal (gf,worst,active_edge,Us,Vs,vSizes,vSizesBGM,newPoint,metric);
      insertAPoint(gf, AllTris.end(), newPoint, metric, Us, Vs, vSizes,
                   vSizesBGM, vMetricsBGM, AllTris, &ActiveTris, worst);
    } 
    
    /*   if(ITER % 1== 0){
       char name[245];
       sprintf(name,"frontal%d-ITER%d.pos",gf->tag(),ITER);
       _printTris (name, AllTris, Us,Vs,false);
     }
    */
  }

//   char name[245];
//   sprintf(name,"frontal%d-real.pos", gf->tag());
//   _printTris (name, AllTris, Us, Vs,false);
//   sprintf(name,"frontal%d-param.pos", gf->tag());
//   _printTris (name, AllTris, Us, Vs,true);
  transferDataStructure(gf, AllTris, Us, Vs); 
  // in case of boundary layer meshing 
  {
    FieldManager *fields = gf->model()->getFields();
    BoundaryLayerField *blf = 0;
    if(fields->getBackgroundField() > 0){
      Field *bl_field = fields->get(fields->getBoundaryLayerField());
      blf = dynamic_cast<BoundaryLayerField*> (bl_field);
      if (blf && !blf->iRecombine)quadsToTriangles(gf,10000);
    }
  }
} 

void optimalPointFrontalQuad (GFace *gf, 
			      MTri3* worst, 
			      int active_edge,
			      std::vector<double> &Us,
			      std::vector<double> &Vs,
			      std::vector<double> &vSizes,
			      std::vector<double> &vSizesBGM,			  
			      double newPoint[2],
			      double metric[3]){
  MTriangle *base = worst->tri();
  int ip1 = active_edge - 1 < 0 ? 2 : active_edge - 1;
  int ip2 = active_edge;
  int ip3 = (active_edge+1)%3;
	
  double P[2] =  {Us[base->getVertex(ip1)->getIndex()],  
		  Vs[base->getVertex(ip1)->getIndex()]};
  double Q[2] =  {Us[base->getVertex(ip2)->getIndex()], 
		  Vs[base->getVertex(ip2)->getIndex()]};
  double O[2] =  {Us[base->getVertex(ip3)->getIndex()], 
		  Vs[base->getVertex(ip3)->getIndex()]};
  double midpoint[2] = {0.5 * (P[0] + Q[0]), 0.5 * (P[1] + Q[1])};
  
  // compute background mesh data
  double quadAngle  = backgroundMesh::current()->getAngle (midpoint[0],midpoint[1],0);
  double center[2];
  circumCenterInfinite (base, quadAngle,Us,Vs,center);                        
  
  // rotate the points with respect to the angle
  double XP1 = 0.5*(Q[0] - P[0]);
  double YP1 = 0.5*(Q[1] - P[1]);
  double xp =  XP1 * cos(quadAngle) + YP1 * sin(quadAngle); 
  double yp = -XP1 * sin(quadAngle) + YP1 * cos(quadAngle); 	  
  // ensure xp > yp
  bool exchange = false;
  if (fabs(xp) < fabs(yp)){
    double temp = xp;
    xp = yp;
    yp = temp;
    exchange = true;
  }
	
  buildMetric(gf, midpoint, metric);
  double RATIO = 1./pow(metric[0]*metric[2]-metric[1]*metric[1],0.25);
  
  const double p = 0.5 * lengthInfniteNorm(P, Q, quadAngle); 
  const double q = lengthInfniteNorm(center, midpoint, quadAngle);
  const double rhoM1 = 0.5 * RATIO * 
    (vSizes[base->getVertex(ip1)->getIndex()] + 
     vSizes[base->getVertex(ip2)->getIndex()] ) / sqrt(3.);// * RATIO;
  const double rhoM2 = 0.5 * RATIO *  
    (vSizesBGM[base->getVertex(ip1)->getIndex()] + 
     vSizesBGM[base->getVertex(ip2)->getIndex()] ) / sqrt(3.);// * RATIO;
  const double rhoM  = Extend1dMeshIn2dSurfaces() ? std::min(rhoM1, rhoM2) : rhoM2;
  
  const double rhoM_hat = std::min(std::max(rhoM, p), (p * p + q * q) / (2 * q));
  const double factor = (rhoM_hat + sqrt (rhoM_hat * rhoM_hat - p * p)) /(sqrt(3.)*p);
	
  double npx,npy;
  if (xp*yp >  0){
    npx = - fabs(xp)*factor;
    npy = fabs(xp)*(1.+factor) - fabs(yp);
  }
  else {
    npx = fabs(xp) * factor;
    npy = (1.+factor)*fabs(xp) - fabs(yp);
  }
  if (exchange){
    double temp = npx;
    npx = npy;
    npy = temp;
  }	  
  
  
  newPoint[0] = midpoint[0] + cos(quadAngle) * npx - sin(quadAngle) * npy;
  newPoint[1] = midpoint[1] + sin(quadAngle) * npx + cos(quadAngle) * npy;

  if ((midpoint[0] - newPoint[0])*(midpoint[0] - O[0]) +
      (midpoint[1] - newPoint[1])*(midpoint[1] - O[1]) < 0){
    newPoint[0] = midpoint[0] - cos(quadAngle) * npx + sin(quadAngle) * npy;
    newPoint[1] = midpoint[1] - sin(quadAngle) * npx - cos(quadAngle) * npy;
  } 
}	

void optimalPointFrontalQuadAniso (GFace *gf, 
				   MTri3* worst, 
				   int active_edge,
				   std::vector<double> &Us,
				   std::vector<double> &Vs,
				   std::vector<double> &vSizes,
				   std::vector<double> &vSizesBGM,			  
				   double newPoint[2],
				   double metric[3]){
  MTriangle *base = worst->tri();
  int ip1 = active_edge - 1 < 0 ? 2 : active_edge - 1;
  int ip2 = active_edge;
  int ip3 = (active_edge+1)%3;
	
  double P[2] =  {Us[base->getVertex(ip1)->getIndex()],  
		  Vs[base->getVertex(ip1)->getIndex()]};
  double Q[2] =  {Us[base->getVertex(ip2)->getIndex()], 
		  Vs[base->getVertex(ip2)->getIndex()]};
  double O[2] =  {Us[base->getVertex(ip3)->getIndex()], 
		  Vs[base->getVertex(ip3)->getIndex()]};
  double midpoint[2] = {0.5 * (P[0] + Q[0]), 0.5 * (P[1] + Q[1])};
  
  // compute background mesh data
  double quadAngle  = backgroundMesh::current()->getAngle (midpoint[0],midpoint[1],0);
  double center[2];
  circumCenterInfinite (base, quadAngle,Us,Vs,center);                        
  
  // rotate the points with respect to the angle
  double XP1 = 0.5*(Q[0] - P[0]);
  double YP1 = 0.5*(Q[1] - P[1]);

  double DX = 0.5*(Q[0] + P[0]);
  double DY = 0.5*(Q[0] + P[0]);

  double xp =  XP1 * cos(quadAngle) + YP1 * sin(quadAngle); 
  double yp = -XP1 * sin(quadAngle) + YP1 * cos(quadAngle); 	  

  double X4 = O[0] -DX;
  double Y4 = O[1] -DY;

  double x4 =  X4 * cos(quadAngle) + Y4 * sin(quadAngle); 
  double y4 = -X4 * sin(quadAngle) + Y4 * cos(quadAngle); 	  

  // ensure xp > yp
  bool exchange = false;
  if (fabs(xp) < fabs(yp)){
    double temp = xp;
    xp = yp;
    yp = temp;
    temp = x4;
    x4 = y4;
    y4 = temp;
    exchange = true;
  }
	
  buildMetric(gf, midpoint, metric);
  double RATIO = 1./pow(metric[0]*metric[2]-metric[1]*metric[1],0.25);  
  const double rhoM1 = 0.5 * RATIO * 
    (vSizes[base->getVertex(ip1)->getIndex()] + 
     vSizes[base->getVertex(ip2)->getIndex()] );
  const double rhoM2 = 0.5 * RATIO *  
    (vSizesBGM[base->getVertex(ip1)->getIndex()] + 
     vSizesBGM[base->getVertex(ip2)->getIndex()] );// * RATIO;
  const double rhoM  = Extend1dMeshIn2dSurfaces() ? std::min(rhoM1, rhoM2) : rhoM2;
  
  
  double npx,npy;

  const double L_edge = lengthInfniteNorm(P,Q,quadAngle);

  const double XP[2]={fabs(xp),fabs(yp)};
  if (xp*yp >  0){
    double xe[2] = { rhoM - fabs(xp) + fabs(yp), rhoM };
    double xc[2]  = {0.5*(x4 - fabs(xp)), 0.5*(x4 + fabs(xp)) - fabs(yp)};
    double xl[2] = {rhoM, rhoM+fabs(xp)-fabs(yp)};
    const double R_Active = lengthInfniteNorm(xc,XP,0.0); // alerady rotated !
    const double L_ec = lengthInfniteNorm(xe,xc,0.0); // alerady rotated !
    const double L_el = lengthInfniteNorm(xe,xl,0.0); // alerady rotated !    
    double t = ( L_edge - rhoM)/(L_edge - R_Active);
    t = std::max(1.,t);
    t = std::min(-L_el/L_ec,t);  
    npx = xe[0] + t*(xc[0]-xe[0]);
    npy = xe[1] + t*(xc[1]-xe[1]);
  }
  else {
    double xe[2] = { rhoM - xp + yp, rhoM };
    double xc[2]  = {0.5*(x4 - xp), 0.5*(x4 + xp) - yp};
    double xl[2] = {rhoM, rhoM+xp-yp};
    const double R_Active = lengthInfniteNorm(xc,XP,0.0); // alerady rotated !
    const double L_ec = lengthInfniteNorm(xe,xc,0.0); // alerady rotated !
    const double L_el = lengthInfniteNorm(xe,xl,0.0); // alerady rotated !    
    const double XP[2]={xp,yp};
    double t = ( L_edge - rhoM)/(L_edge - R_Active);
    t = std::max(1.,t);
    t = std::min(-L_el/L_ec,t);  
    npx = xe[0] + t*(xc[0]-xe[0]);
    npy = xe[1] + t*(xc[1]-xe[1]);
  }

  /*
  if (xp*yp >  0){
    npx = - fabs(xp)*factor;
    npy = fabs(xp)*(1.+factor) - fabs(yp);
  }
  else {
    npx = fabs(xp) * factor;
    npy = (1.+factor)*fabs(xp) - fabs(yp);
  }
  */
  if (exchange){
    double temp = npx;
    npx = npy;
    npy = temp;
  }	  
  
  
  newPoint[0] = midpoint[0] + cos(quadAngle) * npx - sin(quadAngle) * npy;
  newPoint[1] = midpoint[1] + sin(quadAngle) * npx + cos(quadAngle) * npy;

  if ((midpoint[0] - newPoint[0])*(midpoint[0] - O[0]) +
      (midpoint[1] - newPoint[1])*(midpoint[1] - O[1]) < 0){
    newPoint[0] = midpoint[0] - cos(quadAngle) * npx + sin(quadAngle) * npy;
    newPoint[1] = midpoint[1] - sin(quadAngle) * npx - cos(quadAngle) * npy;
  } 
}	


void buildBackGroundMesh (GFace *gf) {

  //  printf("build bak mesh\n");
  quadsToTriangles(gf, 100000);

  if (!backgroundMesh::current()) {
    std::vector<MTriangle*> TR;
    //    std::vector<MQuadrangle*> QR;
    for(int i=0;i<gf->triangles.size();i++){
      TR.push_back(new MTriangle(gf->triangles[i]->getVertex(0),
				 gf->triangles[i]->getVertex(1),
				 gf->triangles[i]->getVertex(2)));
    }
    /*
    for(int i=0;i<gf->quadrangles.size();i++){
      QR.push_back(new MQuadrangle(gf->quadrangles[i]->getVertex(0),
				   gf->quadrangles[i]->getVertex(1),
				   gf->quadrangles[i]->getVertex(2),
				   gf->quadrangles[i]->getVertex(3)));
    }
    */
    // avoid computing curvatures on the fly : only on the 
    // BGM computes once curvatures at each node
    //  Disable curvature control
    int CurvControl = CTX::instance()->mesh.lcFromCurvature;
    CTX::instance()->mesh.lcFromCurvature = 0;    
    //  Do a background mesh
    bowyerWatson(gf);
    //  Re-enable curv control if asked
    CTX::instance()->mesh.lcFromCurvature = CurvControl;    
    // apply this to the BGM
    //    printf("1 end build bak mesh\n");
    backgroundMesh::set(gf);
    //    printf("2 end build bak mesh\n");
    char name[256];
    if (CTX::instance()->mesh.saveAll){
      sprintf(name,"bgm-%d.pos",gf->tag());
      backgroundMesh::current()->print(name,gf);
      sprintf(name,"cross-%d.pos",gf->tag());
      backgroundMesh::current()->print(name,gf,1);
    }
    gf->triangles = TR;
    //    gf->quadrangles = QR;
  }  
  //  printf("end build bak mesh\n");

}

void bowyerWatsonFrontalLayers(GFace *gf, bool quad)
{

  std::set<MTri3*,compareTri3Ptr> AllTris;
  std::set<MTri3*,compareTri3Ptr> ActiveTris;
  std::vector<double> vSizes, vSizesBGM, Us, Vs;
  std::vector<SMetric3> vMetricsBGM;

  if (quad){
    LIMIT_ = sqrt(2.) * .99;
    //LIMIT_ = 4./3.;//sqrt(2.) * .99;
    MTri3::radiusNorm =-1;
  }
  
  buildMeshGenerationDataStructures
    (gf, AllTris, vSizes, vSizesBGM, vMetricsBGM,Us, Vs);

  // delaunise the initial mesh
  int nbSwaps = edgeSwapPass(gf, AllTris, SWCR_DEL, Us, Vs, vSizes, vSizesBGM);
  Msg::Debug("Delaunization of the initial mesh done (%d swaps)", nbSwaps);
  
  int ITER = 0, active_edge;
  // compute active triangle
  std::set<MTri3*,compareTri3Ptr>::iterator it = AllTris.begin();
  std::set<MEdge,Less_Edge> _front;
  for ( ; it!=AllTris.end();++it){
    if(isActive(*it,LIMIT_,active_edge)){
      ActiveTris.insert(*it);
      updateActiveEdges(*it, LIMIT_, _front);
    }
    else if ((*it)->getRadius() < LIMIT_)break;
  }

  // insert points
  int ITERATION = 1;
  int max_layers = quad ? 10000 : 4;
  while (1){
    ITERATION ++;
    if(ITERATION % 1== 0 && CTX::instance()->mesh.saveAll){
      char name[245];
      sprintf(name,"denInfinite_GFace_%d_Layer_%d.pos",gf->tag(),ITERATION);
      _printTris (name, AllTris, Us,Vs,true);
      sprintf(name,"denInfinite_GFace_%d_Layer_%d_Active.pos",gf->tag(),ITERATION);
      _printTris (name, ActiveTris, Us,Vs,true);
    }     
    
    std::set<MTri3*,compareTri3Ptr> ActiveTrisNotInFront;

    //    printf("%d active triangles\n",ActiveTris.size());

    while (1){
      
      if (!ActiveTris.size())break;
      
      //      if (gf->tag() == 1900){      char name[245];
	//	sprintf(name,"x_GFace_%d_Layer_%d.pos",gf->tag(),ITER);
	//	_printTris (name, AllTris, Us,Vs,true);
      //      }

      std::set<MTri3*,compareTri3Ptr>::iterator WORST_ITER = ActiveTris.begin();
      
      MTri3 *worst = (*WORST_ITER);
      ActiveTris.erase(WORST_ITER);
      if (!worst->isDeleted() && (ITERATION > max_layers ? isActive(worst, LIMIT_, active_edge) : isActive(worst, LIMIT_, active_edge,&_front) ) && 
	  worst->getRadius() > LIMIT_){
	//	for (active_edge = 0 ; active_edge < 0 ; active_edge ++){
	//	  if (active_edges[active_edge])break;	
	//	}
	//	Msg::Info("%7d points created -- Worst tri infinite radius is %8.3f -- front size %6d",
	//		     vSizes.size(), worst->getRadius(),_front.size());
	if(ITER++ % 5000 == 0)
	  Msg::Debug("%7d points created -- Worst tri infinite radius is %8.3f -- front size %6d",
		     vSizes.size(), worst->getRadius(),_front.size());
	
	// compute the middle point of the edge
	double newPoint[2],metric[3]={1,0,1};
	if (quad)optimalPointFrontalQuad (gf,worst,active_edge,Us,Vs,vSizes,vSizesBGM,newPoint,metric);
	else optimalPointFrontal (gf,worst,active_edge,Us,Vs,vSizes,vSizesBGM,newPoint,metric);
	
	
	//	printf("start INSERT A POINT %g %g \n",newPoint[0],newPoint[1]);
	insertAPoint(gf, AllTris.end(), newPoint, 0, Us, Vs, vSizes,
		     vSizesBGM, vMetricsBGM, AllTris, &ActiveTris, worst);
	//      else if (!worst->isDeleted() && worst->getRadius() > LIMIT_){
	//	ActiveTrisNotInFront.insert(worst);
	//      }
	//	printf("-----------------> size %d\n",AllTris.size());
	
	/*
	  if(ITER % 1== 0){
	  char name[245];
	  sprintf(name,"frontal%d-ITER%d.pos",gf->tag(),ITER);
	  _printTris (name, AllTris, Us,Vs,false);
	  }
	*/
      }
      else if (!worst->isDeleted() && worst->getRadius() > LIMIT_){
	ActiveTrisNotInFront.insert(worst);
      }
    }
    _front.clear();
        it = ActiveTrisNotInFront.begin();
	//it = AllTris.begin();
        for ( ; it!=ActiveTrisNotInFront.end();++it){
	  //    for ( ; it!=AllTris.end();++it){
      if((*it)->getRadius() > LIMIT_ && isActive(*it,LIMIT_,active_edge)){
	ActiveTris.insert(*it);
	updateActiveEdges(*it, LIMIT_, _front);
      }
    }
	//	Msg::Info("%d active tris %d front edges %d not in front",ActiveTris.size(),_front.size(),ActiveTrisNotInFront.size());
    if (!ActiveTris.size())break;
  }
  
     char name[245];
  //   sprintf(name,"frontal%d-real.pos", gf->tag());
  //   _printTris (name, AllTris, Us, Vs,false);
     //     sprintf(name,"frontal%d-param.pos", gf->tag());
     //     _printTris (name, AllTris, Us, Vs,true);
  transferDataStructure(gf, AllTris, Us, Vs); 
  MTri3::radiusNorm = 2;
  LIMIT_ = 0.5 * sqrt(2.0) * 1;
  backgroundMesh::unset();
} 


