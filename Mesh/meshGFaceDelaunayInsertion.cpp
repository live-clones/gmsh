// $Id: meshGFaceDelaunayInsertion.cpp,v 1.12 2008-03-12 08:36:49 remacle Exp $
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

#include "BDS.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceOptimize.h"
#include "meshGFace.h"
#include "GFace.h"
#include "Numeric.h"
#include "Message.h"
#include <set>
#include <map>
#include <algorithm>

bool circumCenterMetricInTriangle(MTriangle *base, 
				  const double *metric,
				  const std::vector<double> &Us,
				  const std::vector<double> &Vs)
{
  double R, x[2], uv[2];
  circumCenterMetric(base, metric, Us, Vs, x, R);
  return invMapUV(base, x, Us, Vs, uv, 1.e-8);
}

void circumCenterMetric(double *pa, double *pb, double *pc,
			const double *metric,
			double *x, double &Radius2) 
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

  sys2x2(sys, rhs, x);

  Radius2 = 
    (x[0] - pa[0]) * (x[0] - pa[0]) * a +
    (x[1] - pa[1]) * (x[1] - pa[1]) * d +
    2. * (x[0] - pa[0]) * (x[1] - pa[1]) * b;
}

void circumCenterMetric(MTriangle *base, 
			const double *metric,
			const std::vector<double> &Us,
			const std::vector<double> &Vs,
			double *x, double &Radius2) 
{
  // d = (u2-u1) M (u2-u1) = u2 M u2 + u1 M u1 - 2 u2 M u1 
  double pa[2] = {Us[base->getVertex(0)->getNum()],
		  Vs[base->getVertex(0)->getNum()]};
  double pb[2] = {Us[base->getVertex(1)->getNum()],
		  Vs[base->getVertex(1)->getNum()]};
  double pc[2] = {Us[base->getVertex(2)->getNum()],
		  Vs[base->getVertex(2)->getNum()]};
  circumCenterMetric(pa, pb, pc, metric, x, Radius2);
}

void buildMetric(GFace *gf, double *uv, double *metric)
{
  Pair<SVector3, SVector3> der = gf->firstDer(SPoint2(uv[0], uv[1]));
  metric[0] = dot(der.first(), der.first());
  metric[1] = dot(der.second(), der.first());
  metric[2] = dot(der.second(), der.second());
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
  double pa[2] = {(Us[base->getVertex(0)->getNum()] + Us[base->getVertex(1)->getNum()] +
		   Us[base->getVertex(2)->getNum()]) / 3.,
  		  (Vs[base->getVertex(0)->getNum()] + Vs[base->getVertex(1)->getNum()] + 
		   Vs[base->getVertex(2)->getNum()]) / 3.};
  
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

MTri3::MTri3(MTriangle *t, double lc) : deleted(false), base(t)
{
  neigh[0] = neigh[1] = neigh[2] = 0;

  // compute the circumradius of the triangle
  double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(), base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(), base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(), base->getVertex(2)->z()};
  double center[3];
  base->circumcenterXYZ(pa, pb, pc, center);
  const double dx = base->getVertex(0)->x() - center[0];
  const double dy = base->getVertex(0)->y() - center[1];
  const double dz = base->getVertex(0)->z() - center[2];
  
  circum_radius = sqrt(dx * dx + dy * dy + dz * dz);
  circum_radius /= lc;
}

int MTri3::inCircumCircle(const double *p) const
{
  double pa[3] = {base->getVertex(0)->x(), base->getVertex(0)->y(), base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(), base->getVertex(1)->y(), base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(), base->getVertex(2)->y(), base->getVertex(2)->z()};
  double fourth[3];
  fourthPoint(pa, pb, pc, fourth);

  double result = gmsh::insphere(pa, pb, pc, fourth, (double*)p) * 
    gmsh::orient3d(pa, pb, pc,fourth);  
  return (result > 0) ? 1 : 0;  
}

int inCircumCircle(MTriangle *base, 
		   const double *p, const double *param ,
		   std::vector<double> &Us, std::vector<double> &Vs) 
{
  double pa[2] = {Us[base->getVertex(0)->getNum()],
		  Vs[base->getVertex(0)->getNum()]};
  double pb[2] = {Us[base->getVertex(1)->getNum()],
		  Vs[base->getVertex(1)->getNum()]};
  double pc[2] = {Us[base->getVertex(2)->getNum()],
		  Vs[base->getVertex(2)->getNum()]};

  double result = gmsh::incircle(pa, pb, pc, (double*)param) * gmsh::orient2d(pa, pb, pc);  
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
  // the cavity that has to be removed
  // because it violates delaunay criterion
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

void recurFindCavityAniso (GFace *gf,
			   std::list<edgeXface> &shell, std::list<MTri3*> &cavity, 
			   double *metric, double *param,  MTri3 *t,
			   std::vector<double> &Us, std::vector<double> &Vs)
{
  t->setDeleted(true);
  // the cavity that has to be removed
  // because it violates delaunay criterion
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
  double u1 [3] = {Us[t->getVertex(0)->getNum()], Vs[t->getVertex(0)->getNum()], 0};
  double u2 [3] = {Us[t->getVertex(1)->getNum()], Vs[t->getVertex(1)->getNum()], 0};
  double u3 [3] = {Us[t->getVertex(2)->getNum()], Vs[t->getVertex(2)->getNum()], 0};
  t->circumcenterXY(u1, u2, u3, res);
  return true;
  double p1 [3] = {t->getVertex(0)->x(), t->getVertex(0)->y(), t->getVertex(0)->z()};
  double p2 [3] = {t->getVertex(1)->x(), t->getVertex(1)->y(), t->getVertex(1)->z()};
  double p3 [3] = {t->getVertex(2)->x(), t->getVertex(2)->y(), t->getVertex(2)->z()};
  double resxy[3], uv[2];
  t->circumcenterXYZ(p1, p2, p3, resxy,uv);
  return true;
}

bool invMapUV(MTriangle *t, double *p,
	      const std::vector<double> &Us, const std::vector<double> &Vs,
	      double *uv, double tol)
{
  double mat[2][2];
  double b[2];

  double u0 = Us[t->getVertex(0)->getNum()];
  double v0 = Vs[t->getVertex(0)->getNum()];
  double u1 = Us[t->getVertex(1)->getNum()];
  double v1 = Vs[t->getVertex(1)->getNum()];
  double u2 = Us[t->getVertex(2)->getNum()];
  double v2 = Vs[t->getVertex(2)->getNum()];

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
  double u1 = Us[t->getVertex(0)->getNum()];
  double v1 = Vs[t->getVertex(0)->getNum()];
  double u2 = Us[t->getVertex(1)->getNum()];
  double v2 = Vs[t->getVertex(1)->getNum()];
  double u3 = Us[t->getVertex(2)->getNum()];
  double v3 = Vs[t->getVertex(2)->getNum()];
  const double vv1 [2] = {u2 - u1, v2 - v1};
  const double vv2 [2] = {u3 - u1, v3 - v1};
  double s = vv1[0] * vv2[1] - vv1[1] * vv2[0]; 
  return s * 0.5;
}

bool insertVertex(GFace *gf, MVertex *v, double *param , MTri3 *t,
		  std::set<MTri3*, compareTri3Ptr> &allTets,
		  std::vector<double> &vSizes, std::vector<double> &vSizesBGM,
		  std::vector<double> &Us, std::vector<double> &Vs,
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

  while (it != shell.end()){
    MTriangle *t = new MTriangle(it->v[0], it->v[1], v);
    double lc = 0.3333333333 * (vSizes [t->getVertex(0)->getNum()]+
				vSizes [t->getVertex(1)->getNum()]+
				vSizes [t->getVertex(2)->getNum()]);
    double lcBGM = 0.3333333333 * (vSizesBGM [t->getVertex(0)->getNum()]+
				   vSizesBGM [t->getVertex(1)->getNum()]+
				   vSizesBGM [t->getVertex(2)->getNum()]);
    MTri3 *t4 = new MTri3(t, Extend1dMeshIn2dSurfaces() ? std::min(lc, lcBGM) : lcBGM); 
    newTris[k++] = t4;
    // all new triangles are pushed front in order to
    // ba able to destroy them if the cavity is not
    // star shaped around the new vertex.
    new_cavity.push_back (t4);
    MTri3 *otherSide = it->t1->getNeigh(it->i1);
    if (otherSide)
      new_cavity.push_back (otherSide);
    double ss = fabs(getSurfUV(t4->tri(),Us,Vs));
    if (ss < 1.e-25)ss = 1256172121;
    newVolume += ss;
    ++it;
  }
  if (fabs(oldVolume - newVolume) < 1.e-12 * oldVolume){      
    connectTris(new_cavity.begin(),new_cavity.end());      
    allTets.insert(newTris,newTris+shell.size());
    delete [] newTris;
    return true;
  }
  // The cavity is NOT star shaped
  else{      
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
		std::vector<double> &Us, std::vector<double> &Vs)
{
  FILE *ff = fopen (name,"w");
  fprintf(ff,"View\"test\"{\n");
  std::set<MTri3*,compareTri3Ptr>::iterator it = AllTris.begin();
  while (it != AllTris.end() ){
    MTri3 *worst = *it;
    if (!worst->isDeleted()){
      fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0};\n",
	      Us [(worst)->tri()->getVertex(0)->getNum()],
	      Vs [(worst)->tri()->getVertex(0)->getNum()],
	      0.0,
	      Us [(worst)->tri()->getVertex(1)->getNum()],
	      Vs [(worst)->tri()->getVertex(1)->getNum()],
	      0.0,
	      Us [(worst)->tri()->getVertex(2)->getNum()],
	      Vs [(worst)->tri()->getVertex(2)->getNum()],
	      0.0);
    }
    ++it;
  }
  fprintf(ff,"};\n");
  fclose (ff);
}

void insertVerticesInFace(GFace *gf, BDS_Mesh *bds)
{
  std::set<MTri3*,compareTri3Ptr> AllTris;
  std::vector<double> vSizes, vSizesBGM, Us, Vs;

  buidMeshGenerationDataStructures(gf, AllTris, vSizes, vSizesBGM, Us, Vs);

  // _printTris ("before.pos", AllTris, Us,Vs);
  int nbSwaps = edgeSwapPass(gf, AllTris, SWCR_DEL, Us, Vs, vSizes, vSizesBGM);
  // _printTris ("after2.pos", AllTris, Us,Vs);
  Msg(DEBUG,"Delaunization of the initial mesh done (%d swaps)", nbSwaps);

  int ITER = 0;
  while (1){
    MTri3 *worst = *AllTris.begin();
    if (worst->isDeleted()){
      delete worst->tri();
      delete worst;
      AllTris.erase(AllTris.begin());
    }
    else{
      if(ITER++ % 5000 == 0)
	Msg(DEBUG,"%7d points created -- Worst tri radius is %8.3f",
	    vSizes.size(), worst->getRadius());
      double center[2],uv[2],metric[3],r2;
      if (worst->getRadius() < 0.5 * sqrt(2.0)) break;
      circUV(worst->tri(), Us, Vs, center, gf);
      MTriangle *base = worst->tri();
      double pa[2] = {(Us[base->getVertex(0)->getNum()] + 
		       Us[base->getVertex(1)->getNum()] + 
		       Us[base->getVertex(2)->getNum()]) / 3.,
		      (Vs[base->getVertex(0)->getNum()] + 
		       Vs[base->getVertex(1)->getNum()] + 
		       Vs[base->getVertex(2)->getNum()]) / 3.};
      buildMetric(gf, pa, metric);
      circumCenterMetric(worst->tri(), metric, Us, Vs, center, r2); 

      bool inside = invMapUV(worst->tri(), center, Us, Vs, uv, 1.e-8);
      if (!inside && worst->getNeigh(0))
	inside |= invMapUV(worst->getNeigh(0)->tri(), center, Us, Vs, uv, 1.e-8);
      if (!inside && worst->getNeigh(1))
	inside |= invMapUV(worst->getNeigh(1)->tri(), center, Us, Vs, uv, 1.e-8);
      if (!inside && worst->getNeigh(2))
	inside |= invMapUV(worst->getNeigh(2)->tri(), center, Us, Vs, uv, 1.e-8);
      if (inside) {
	// we use here local coordinates as real coordinates
	// x,y and z will be computed hereafter
	//	      Msg(INFO,"Point is inside");
	GPoint p = gf->point(center[0], center[1]);
	MVertex *v = new MFaceVertex(p.x(), p.y(), p.z(), gf, center[0], center[1]);
	v->setNum(Us.size());
	double lc1 = ((1. - uv[0] - uv[1]) * vSizes[worst->tri()->getVertex(0)->getNum()] + 
		      uv[0] * vSizes [worst->tri()->getVertex(1)->getNum()] + 
		      uv[1] * vSizes [worst->tri()->getVertex(2)->getNum()]); 
	// double eigMetricSurface = gf->getMetricEigenvalue(SPoint2(center[0],center[1]));
	double lc = BGM_MeshSize(gf,center[0],center[1],p.x(),p.y(),p.z());
	vSizesBGM.push_back(lc);
	vSizes.push_back(lc1);
	Us.push_back(center[0]);
	Vs.push_back(center[1]);
	
	if (!insertVertex(gf, v, center, worst, AllTris, vSizes, vSizesBGM, 
			  Us, Vs, metric)) {
	  Msg(DEBUG,"2D Delaunay : a cavity is not star shaped");
	  AllTris.erase(AllTris.begin());
	  worst->forceRadius(-1);
	  AllTris.insert(worst);		  
	  delete v;
	}
	else 
	  gf->mesh_vertices.push_back(v);
      }
      else {
	Msg(DEBUG,"Point %g %g is outside (%g %g , %g %g , %g %g) (metric %g %g %g)",center[0],center[1],
	    Us[base->getVertex(0)->getNum()], 
	    Vs[base->getVertex(0)->getNum()], 
	    Us[base->getVertex(1)->getNum()], 
	    Vs[base->getVertex(1)->getNum()], 
	    Us[base->getVertex(2)->getNum()], 
	    Vs[base->getVertex(2)->getNum()],metric[0],metric[1],metric[2]);
	AllTris.erase(AllTris.begin());
	worst->forceRadius(0);
	AllTris.insert(worst);
      }
    }
  }    
  for (int i=0;i<10;i++){
    //  bool splits = edgeSplitPass(1.4, gf, AllTris, SPCR_ALLWAYS, Us, Vs, vSizes, vSizesBGM);
    //  edgeSwapPass(gf, AllTris, SWCR_QUAL, Us, Vs, vSizes, vSizesBGM);
    //  bool collapses = edgeCollapsePass(0.67, gf, AllTris, Us, Vs, vSizes, vSizesBGM);
    //  edgeSwapPass(gf, AllTris, SWCR_QUAL, Us, Vs, vSizes, vSizesBGM);
    //  if (!collapses && !splits) break;
  }
  
  //_printTris ("yo.pos", AllTris, Us, Vs);

  transferDataStructure(gf, AllTris); 
}
