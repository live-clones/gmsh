// $Id: GFace.cpp,v 1.17 2006-11-14 17:11:33 remacle Exp $
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
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "GFace.h"
#include "GEdge.h"
#include "Message.h"

#if defined(HAVE_GSL)
#include <gsl/gsl_vector.h>
#include <gsl/gsl_linalg.h>
#else
#define NRANSI
#include "nrutil.h"
void dsvdcmp(double **a, int m, int n, double w[], double **v);
#endif

GFace::GFace(GModel *model, int tag) : GEntity(model, tag), r1(0), r2(0) 
{
  meshAttributes.recombine = 0;
  meshAttributes.recombineAngle = 0.;
  meshAttributes.Method = LIBRE;
  meshAttributes.transfiniteArrangement = 0;
  meshAttributes.extrude = 0;
}

GFace::~GFace()
{ 
  std::list<GEdge*>::iterator it = l_edges.begin();

  while (it != l_edges.end()){
    (*it)->delFace(this);
    ++it;
  }

  for(unsigned int i = 0; i < mesh_vertices.size(); i++) 
    delete mesh_vertices[i];
  mesh_vertices.clear();

  for(unsigned int i = 0; i < triangles.size(); i++) 
    delete triangles[i];
  triangles.clear();

  for(unsigned int i = 0; i < quadrangles.size(); i++) 
    delete quadrangles[i];
  quadrangles.clear();
}

SBoundingBox3d GFace::bounds() const
{
  SBoundingBox3d res;
  if(geomType() != DiscreteSurface){
    std::list<GEdge*>::const_iterator it = l_edges.begin();
    for(; it != l_edges.end(); it++)
      res += (*it)->bounds();
  }
  else{
    for(unsigned int i = 0; i < mesh_vertices.size(); i++)
      res += mesh_vertices[i]->point();
  }
  return res;
}

std::list<GVertex*> GFace::vertices() const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  std::list<GVertex*>ret;
  while (it != l_edges.end()){
    GVertex *v1 = (*it)->getBeginVertex();
    GVertex *v2 = (*it)->getEndVertex();
    if(std::find(ret.begin(), ret.end(), v1) == ret.end())
      ret.push_back(v1);
    if(std::find(ret.begin(), ret.end(), v2) == ret.end())
      ret.push_back(v2);
    ++it;
  }
  return ret;
}

void GFace::setVisibility(char val, bool recursive)
{
  GEntity::setVisibility(val);
  if(recursive){
    std::list<GEdge*>::iterator it = l_edges.begin();
    while (it != l_edges.end()){
      (*it)->setVisibility(val, recursive);
      ++it;
    }
  }
}

void GFace::recomputeMeshPartitions()
{
  for(unsigned int i = 0; i < triangles.size(); i++) {
    int part = triangles[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
  for(unsigned int i = 0; i < quadrangles.size(); i++) {
    int part = quadrangles[i]->getPartition();
    if(part) model()->getMeshPartitions().insert(part);
  }
}

void GFace::deleteMeshPartitions()
{
  for(unsigned int i = 0; i < triangles.size(); i++)
    triangles[i]->setPartition(0);
  for(unsigned int i = 0; i < quadrangles.size(); i++)
    quadrangles[i]->setPartition(0);
}

void GFace::computeMeanPlane()
{
  std::vector<SPoint3> pts;
  std::list<GVertex*> verts = vertices();
  std::list<GVertex*>::const_iterator itv = verts.begin();
  for(; itv != verts.end(); itv++){
    const GVertex *v = *itv; 
    pts.push_back(SPoint3(v->x(), v->y(), v->z()));
  }
  computeMeanPlane(pts);
}

void GFace::computeMeanPlane(const std::vector<MVertex*> &points)
{
  std::vector<SPoint3> pts;
  for(unsigned int i = 0; i < points.size(); i++)
    pts.push_back(SPoint3(points[i]->x(), points[i]->y(), points[i]->z()));
  computeMeanPlane(pts);
}

void GFace::computeMeanPlane(const std::vector<SPoint3> &points)
{
  // The concept of a mean plane computed in the sense of least
  // squares is fine for plane surfaces(!), but not really the best
  // one for non-plane surfaces. Indeed, imagine a quarter of a circle
  // extruded along a very small height: the mean plane will be in the
  // plane of the circle... Until we implement something better, there
  // is a test in this routine that checks the coherence of the
  // computation for non-plane surfaces and reverts to a basic mean
  // plane approximatation if the check fails.

  double xm = 0., ym = 0., zm = 0.;
  int ndata = points.size();
  int na = 3;
  for(int i = 0; i < ndata; i++) {
    xm += points[i].x();
    ym += points[i].y();
    zm += points[i].z();
  }
  xm /= (double)ndata;
  ym /= (double)ndata;
  zm /= (double)ndata;

  int min;
  double res[4], svd[3];
#if defined(HAVE_GSL)
  gsl_matrix *U = gsl_matrix_alloc(ndata, na);
  gsl_matrix *V = gsl_matrix_alloc(na, na);
  gsl_vector *W = gsl_vector_alloc(na);
  gsl_vector *TMPVEC = gsl_vector_alloc(na);
  for(int i = 0; i < ndata; i++) {
    gsl_matrix_set(U, i, 0, points[i].x() - xm);
    gsl_matrix_set(U, i, 1, points[i].y() - ym);
    gsl_matrix_set(U, i, 2, points[i].z() - zm);
  }
  gsl_linalg_SV_decomp(U, V, W, TMPVEC);
  svd[0] = gsl_vector_get(W, 0);
  svd[1] = gsl_vector_get(W, 1);
  svd[2] = gsl_vector_get(W, 2);
  if(fabs(svd[0]) < fabs(svd[1]) && fabs(svd[0]) < fabs(svd[2]))
    min = 0;
  else if(fabs(svd[1]) < fabs(svd[0]) && fabs(svd[1]) < fabs(svd[2]))
    min = 1;
  else
    min = 2;
  res[0] = gsl_matrix_get(V, 0, min);
  res[1] = gsl_matrix_get(V, 1, min);
  res[2] = gsl_matrix_get(V, 2, min);
  norme(res);
  gsl_matrix_free(U);
  gsl_matrix_free(V);
  gsl_vector_free(W);
  gsl_vector_free(TMPVEC);
#else
  double **U = dmatrix(1, ndata, 1, na);
  double **V = dmatrix(1, na, 1, na);
  double *W = dvector(1, na);
  for(int i = 0; i < ndata; i++) {
    U[i + 1][1] = points[i].x() - xm;
    U[i + 1][2] = points[i].y() - ym;
    U[i + 1][3] = points[i].z() - zm;
  }
  dsvdcmp(U, ndata, na, W, V);
  if(fabs(W[1]) < fabs(W[2]) && fabs(W[1]) < fabs(W[3]))
    min = 1;
  else if(fabs(W[2]) < fabs(W[1]) && fabs(W[2]) < fabs(W[3]))
    min = 2;
  else
    min = 3;
  svd[0] = W[1];
  svd[1] = W[2];
  svd[2] = W[3];
  res[0] = V[1][min];
  res[1] = V[2][min];
  res[2] = V[3][min];
  norme(res);
  free_dmatrix(U, 1, ndata, 1, na);
  free_dmatrix(V, 1, na, 1, na);
  free_dvector(W, 1, na);
#endif

  double ex[3], t1[3], t2[3];

  // check coherence of results for non-plane surfaces
  if(geomType() != GEntity::Plane) {
    double res2[3], c[3], cosc, sinc, angplan;
    double eps = 1.e-3;

    GPoint v1 = point(0.5, 0.5);
    GPoint v2 = point(0.5 + eps, 0.5);
    GPoint v3 = point(0.5, 0.5 + eps);
    t1[0] = v2.x() - v1.x();
    t1[1] = v2.y() - v1.y();
    t1[2] = v2.z() - v1.z();
    t2[0] = v3.x() - v1.x();
    t2[1] = v3.y() - v1.y();
    t2[2] = v3.z() - v1.z();
    norme(t1);
    norme(t2);
    // prodve(t1, t2, res2);
    // Warning: the rest of the code assumes res = t2 x t1, not t1 x t2 (WTF?)
    prodve(t2, t1, res2); 
    norme(res2);
    prodve(res, res2, c);
    prosca(res, res2, &cosc);
    sinc = sqrt(c[0] * c[0] + c[1] * c[1] + c[2] * c[2]);
    angplan = myatan2(sinc, cosc);
    angplan = angle_02pi(angplan) * 180. / Pi;
    if((angplan > 70 && angplan < 110) || (angplan > 260 && angplan < 280)) {
      Msg(INFO, "SVD failed (angle=%g): using rough algo...", angplan);
      res[0] = res2[0];
      res[1] = res2[1];
      res[2] = res2[2];
      goto end;
    }
  }

  ex[0] = ex[1] = ex[2] = 0.0;
  if(res[0] == 0.)
    ex[0] = 1.0;
  else if(res[1] == 0.)
    ex[1] = 1.0;
  else
    ex[2] = 1.0;

  prodve(res, ex, t1);
  norme(t1);
  prodve(t1, res, t2);
  norme(t2);

end:
  res[3] = (xm * res[0] + ym * res[1] + zm * res[2]);

  for(int i = 0; i < 3; i++)
    meanPlane.plan[0][i] = t1[i];
  for(int i = 0; i < 3; i++)
    meanPlane.plan[1][i] = t2[i];
  for(int i = 0; i < 3; i++)
    meanPlane.plan[2][i] = res[i];

  meanPlane.a = res[0];
  meanPlane.b = res[1];
  meanPlane.c = res[2];
  meanPlane.d = res[3];

  meanPlane.x = meanPlane.y = meanPlane.z = 0.;
  if(fabs(meanPlane.a) >= fabs(meanPlane.b) && 
     fabs(meanPlane.a) >= fabs(meanPlane.c) ){
    meanPlane.x = meanPlane.d / meanPlane.a;
  }
  else if(fabs(meanPlane.b) >= fabs(meanPlane.a) && 
	  fabs(meanPlane.b) >= fabs(meanPlane.c)){
    meanPlane.y = meanPlane.d / meanPlane.b;
  }
  else{
    meanPlane.z = meanPlane.d / meanPlane.c;
  }
  
  Msg(DEBUG1, "Surface: %d", tag());
  Msg(DEBUG2, "SVD    : %g,%g,%g (min=%d)", svd[0], svd[1], svd[2], min);
  Msg(DEBUG2, "Plane  : (%g x + %g y + %g z = %g)", 
      meanPlane.a, meanPlane.b, meanPlane.c, meanPlane.d);
  Msg(DEBUG2, "Normal : (%g , %g , %g )", 
      meanPlane.a, meanPlane.b, meanPlane.c);
  Msg(DEBUG3, "t1     : (%g , %g , %g )", t1[0], t1[1], t1[2]);
  Msg(DEBUG3, "t2     : (%g , %g , %g )", t2[0], t2[1], t2[2]);
  Msg(DEBUG3, "pt     : (%g , %g , %g )", 
      meanPlane.x, meanPlane.y, meanPlane.z);

  //check coherence for plane surfaces
  if(geomType() == GEntity::Plane) {
    SBoundingBox3d bb = bounds();
    double lc = norm(SVector3(bb.max(), bb.min()));
    std::list<GVertex*> verts = vertices();
    std::list<GVertex*>::const_iterator itv = verts.begin();
    for(; itv != verts.end(); itv++){
      const GVertex *v = *itv; 
      double d = meanPlane.a * v->x() + meanPlane.b * v->y() + 
	meanPlane.c * v->z() - meanPlane.d;
      if(fabs(d) > lc * 1.e-3) {
	Msg(GERROR1, "Plane surface %d (%gx+%gy+%gz+%g=0) is not plane!",
	    tag(), meanPlane.a, meanPlane.b, meanPlane.c, meanPlane.d);
	Msg(GERROR3, "Control point %d = (%g,%g,%g), val=%g",
	    v->tag(), v->x(), v->y(), v->z(), d);
	return;
      }
    }
  }
}

void GFace::getMeanPlaneData(double VX[3], double VY[3], 
			     double &x, double &y, double &z) const
{
  VX[0] = meanPlane.plan[0][0];
  VX[1] = meanPlane.plan[0][1];
  VX[2] = meanPlane.plan[0][2];
  VY[0] = meanPlane.plan[1][0];
  VY[1] = meanPlane.plan[1][1];
  VY[2] = meanPlane.plan[1][2];
  x = meanPlane.x;  
  y = meanPlane.y;  
  z = meanPlane.z;  
}

double GFace::curvature (const SPoint2 &param) const
{
  if (geomType() == Plane)return 0;

  // X=X(u,v) Y=Y(u,v) Z=Z(u,v)
  // curv = div n = dnx/dx + dny/dy + dnz/dz
  // dnx/dx = dnx/du du/dx + dnx/dv dv/dx

  const double eps = 1.e-3;

  Pair<SVector3,SVector3> der = firstDer(param) ;

  SVector3 du = der.first();
  SVector3 dv = der.second();
  SVector3 nml  = crossprod(du,dv);

  double detJ = norm ( nml );

  du.normalize();
  dv.normalize();

  SVector3 n1 = normal(SPoint2(param.x() - eps ,  param.y()  )) ;
  SVector3 n2 = normal(SPoint2(param.x() + eps ,  param.y()  )) ;
  SVector3 n3 = normal(SPoint2(param.x() ,  param.y()  - eps )) ;
  SVector3 n4 = normal(SPoint2(param.x() ,  param.y()  + eps )) ;

  SVector3 dndu = 500 * ( n2-n1 );
  SVector3 dndv = 500 * ( n4-n3 );

  double c = fabs(dot(dndu,du) +  dot(dndv,dv)) / detJ; 

  //  Msg (INFO,"c = %g detJ %g",c,detJ);

  return  c;
}

// edges are given, compute their orientation
// i.e. two following edges should 
void GFace :: computeDirs ()
{
  throw;
}
