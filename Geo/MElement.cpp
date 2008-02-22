// $Id: MElement.cpp,v 1.58 2008-02-22 07:19:07 geuzaine Exp $
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
#include "MElement.h"
#include "GEntity.h"
#include "GFace.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Numeric.h"
#  include "FunctionSpace.h"
#  include "Message.h"
#  include "Context.h"
#  include "qualityMeasures.h"
#endif

extern Context_T CTX;

int MElement::_globalNum = 0;
double MElementLessThanLexicographic::tolerance = 1.e-6;

void MElement::_getEdgeRep(MVertex *v0, MVertex *v1, 
			   double *x, double *y, double *z, SVector3 *n, 
			   int faceIndex)
{
  x[0] = v0->x(); y[0] = v0->y(); z[0] = v0->z();
  x[1] = v1->x(); y[1] = v1->y(); z[1] = v1->z();
  if(faceIndex >= 0){
    n[0] = n[1] = getFace(faceIndex).normal();
  }
  else{
    MEdge e(v0, v1);
    n[0] = n[1] = e.normal();
  }
}

void MElement::_getFaceRep(MVertex *v0, MVertex *v1, MVertex *v2, 
			   double *x, double *y, double *z, SVector3 *n)
{
  x[0] = v0->x(); x[1] = v1->x(); x[2] = v2->x(); 
  y[0] = v0->y(); y[1] = v1->y(); y[2] = v2->y();
  z[0] = v0->z(); z[1] = v1->z(); z[2] = v2->z();
  SVector3 t1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
  SVector3 t2(x[2] - x[0], y[2] - y[0], z[2] - z[0]);
  SVector3 normal = crossprod(t1, t2);
  normal.normalize();
  for(int i = 0; i < 3; i++) n[i] = normal;
}

char MElement::getVisibility()
{
  if(CTX.hide_unselected && _visible < 2) return false;
  return _visible; 
}

double MElement::minEdge()
{
  double m = 1.e25;
  for(int i = 0; i < getNumEdges(); i++){
    MEdge e = getEdge(i);
    m = std::min(m, e.getVertex(0)->distance(e.getVertex(1)));
  }
  return m;
}

double MElement::maxEdge()
{
  double m = 0.;
  for(int i = 0; i < getNumEdges(); i++){
    MEdge e = getEdge(i);
    m = std::max(m, e.getVertex(0)->distance(e.getVertex(1)));
  }
  return m;
}

double MElement::rhoShapeMeasure()
{
  double min = minEdge();
  double max = maxEdge();
  if(max)
    return min / max;
  else
    return 0.;
}

double MTriangle::gammaShapeMeasure()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 0.;
#else
  return qmTriangle(this, QMTRI_RHO);
#endif
}

double MTetrahedron::gammaShapeMeasure()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 0.;
#else
  double vol;
  return qmTet(this, QMTET_2, &vol);
#endif
}

double MTetrahedron::etaShapeMeasure()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 0.;
#else
  double vol;
  return qmTet(this, QMTET_3, &vol);
#endif
}

void MTetrahedron::getMat(double mat[3][3])
{
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[2]->x() - _v[0]->x();
  mat[0][2] = _v[3]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[2]->y() - _v[0]->y();
  mat[1][2] = _v[3]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[2]->z() - _v[0]->z();
  mat[2][2] = _v[3]->z() - _v[0]->z();
}

double MTetrahedron::getVolume()
{ 
  double mat[3][3];
  getMat(mat);
  return det3x3(mat) / 6.;
}

bool MTetrahedron::invertmapping(double *p, double *uvw, double tol)
{
  double mat[3][3];
  double b[3], dum;
  getMat(mat);
  b[0] = p[0] - getVertex(0)->x();
  b[1] = p[1] - getVertex(0)->y();
  b[2] = p[2] - getVertex(0)->z();
  sys3x3(mat, b, uvw, &dum);
  if(uvw[0] >= -tol && uvw[1] >= -tol && uvw[2] >= -tol &&
     uvw[0] <= 1. + tol && uvw[1] <= 1. + tol && uvw[2] <= 1. + tol &&
     1. - uvw[0] - uvw[1] - uvw[2] > -tol) {
    return true;
  }
  return false;
}

void MTetrahedron::circumcenter(double X[4], double Y[4], double Z[4], double *res)
{
  double mat[3][3], b[3], dum;    
  b[0] = X[1] * X[1] - X[0] * X[0] +
    Y[1] * Y[1] - Y[0] * Y[0] + Z[1] * Z[1] - Z[0] * Z[0];
  b[1] = X[2] * X[2] - X[1] * X[1] +
    Y[2] * Y[2] - Y[1] * Y[1] + Z[2] * Z[2] - Z[1] * Z[1];
  b[2] = X[3] * X[3] - X[2] * X[2] +
    Y[3] * Y[3] - Y[2] * Y[2] + Z[3] * Z[3] - Z[2] * Z[2];
  for(int i = 0; i < 3; i++)
    b[i] *= 0.5;
  mat[0][0] = X[1] - X[0];
  mat[0][1] = Y[1] - Y[0];
  mat[0][2] = Z[1] - Z[0];
  mat[1][0] = X[2] - X[1];
  mat[1][1] = Y[2] - Y[1];
  mat[1][2] = Z[2] - Z[1];
  mat[2][0] = X[3] - X[2];
  mat[2][1] = Y[3] - Y[2];
  mat[2][2] = Z[3] - Z[2];
  if(!sys3x3(mat, b, res, &dum)) {
    res[0] = res[1] = res[2] = 10.0e10;
  }
}

int MHexahedron::getVolumeSign()
{ 
  double mat[3][3];
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[3]->x() - _v[0]->x();
  mat[0][2] = _v[4]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[3]->y() - _v[0]->y();
  mat[1][2] = _v[4]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[3]->z() - _v[0]->z();
  mat[2][2] = _v[4]->z() - _v[0]->z();
  return sign(det3x3(mat));
}

int MPrism::getVolumeSign()
{ 
  double mat[3][3];
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[2]->x() - _v[0]->x();
  mat[0][2] = _v[3]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[2]->y() - _v[0]->y();
  mat[1][2] = _v[3]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[2]->z() - _v[0]->z();
  mat[2][2] = _v[3]->z() - _v[0]->z();
  return sign(det3x3(mat));
}

int MPyramid::getVolumeSign()
{ 
  double mat[3][3];
  mat[0][0] = _v[1]->x() - _v[0]->x();
  mat[0][1] = _v[3]->x() - _v[0]->x();
  mat[0][2] = _v[4]->x() - _v[0]->x();
  mat[1][0] = _v[1]->y() - _v[0]->y();
  mat[1][1] = _v[3]->y() - _v[0]->y();
  mat[1][2] = _v[4]->y() - _v[0]->y();
  mat[2][0] = _v[1]->z() - _v[0]->z();
  mat[2][1] = _v[3]->z() - _v[0]->z();
  mat[2][2] = _v[4]->z() - _v[0]->z();
  return sign(det3x3(mat));
}

SPoint3 MElement::barycenter()
{
  SPoint3 p(0., 0., 0.);
  int n = getNumVertices();
  for(int i = 0; i < n; i++) {
    MVertex *v = getVertex(i);
    p[0] += v->x();
    p[1] += v->y();
    p[2] += v->z();
  }
  p[0] /= (double)n;
  p[1] /= (double)n;
  p[2] /= (double)n;
  return p;
}

std::string MElement::getInfoString()
{
  char tmp[256];
  sprintf(tmp, "Element %d", getNum());
  return std::string(tmp);
}

void MElement::writeMSH(FILE *fp, double version, bool binary, int num, 
			int elementary, int physical)
{
  int type = getTypeForMSH();

  if(!type) return;

  // if necessary, change the ordering of the vertices to get positive
  // volume
  setVolumePositive();
  int n = getNumVertices();

  if(!binary){
    fprintf(fp, "%d %d", num ? num : _num, type);
    if(version < 2.0)
      fprintf(fp, " %d %d %d", abs(physical), elementary, n);
    else
      fprintf(fp, " 3 %d %d %d", abs(physical), elementary, _partition);
  }
  else{
    int tags[4] = {num ? num : _num, abs(physical), elementary, _partition};
    fwrite(tags, sizeof(int), 4, fp);
  }

  if(physical < 0) revert();

  int verts[30];
  for(int i = 0; i < n; i++)
    verts[i] = getVertex(i)->getNum();

  if(!binary){
    for(int i = 0; i < n; i++)
      fprintf(fp, " %d", verts[i]);
    fprintf(fp, "\n");
  }
  else{
    fwrite(verts, sizeof(int), n, fp);
  }

  if(physical < 0) revert();
}

void MElement::writePOS(FILE *fp, bool printElementary, bool printElementNumber, 
			bool printGamma, bool printEta, bool printRho, 
			double scalingFactor, int elementary)
{
  const char *str = getStringForPOS();
  if(!str) return;

  int n = getNumVertices();
  fprintf(fp, "%s(", str);
  for(int i = 0; i < n; i++){
    if(i) fprintf(fp, ",");
    fprintf(fp, "%g,%g,%g", getVertex(i)->x() * scalingFactor, 
	    getVertex(i)->y() * scalingFactor, getVertex(i)->z() * scalingFactor);
  }
  fprintf(fp, "){");
  bool first = true;
  if(printElementary){
    for(int i = 0; i < n; i++){
      if(first) first = false; else fprintf(fp, ",");
      fprintf(fp, "%d", elementary);
    }
  }
  if(printElementNumber){
    for(int i = 0; i < n; i++){
      if(first) first = false; else fprintf(fp, ",");
      fprintf(fp, "%d", getNum());
    }
  }
  if(printGamma){
    double gamma = gammaShapeMeasure();
    for(int i = 0; i < n; i++){
      if(first) first = false; else fprintf(fp, ",");
      fprintf(fp, "%g", gamma);
    }
  }
  if(printEta){
    double eta = etaShapeMeasure();
    for(int i = 0; i < n; i++){
      if(first) first = false; else fprintf(fp, ",");
      fprintf(fp, "%g", eta);
    }
  }
  if(printRho){
    double rho = rhoShapeMeasure();
    for(int i = 0; i < n; i++){
      if(first) first = false; else fprintf(fp, ",");
      fprintf(fp, "%g", rho);
    }
  }
  fprintf(fp, "};\n");
}

void MElement::writeSTL(FILE *fp, bool binary, double scalingFactor)
{
  if(getNumEdges() != 3 && getNumEdges() != 4) return;
  int qid[3] = {0, 2, 3};
  SVector3 n = getFace(0).normal();
  if(!binary){
    fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
    fprintf(fp, "  outer loop\n");
    for(int j = 0; j < 3; j++)
      fprintf(fp, "    vertex %g %g %g\n", 
	      getVertex(j)->x() * scalingFactor, 
	      getVertex(j)->y() * scalingFactor, 
	      getVertex(j)->z() * scalingFactor);
    fprintf(fp, "  endloop\n");
    fprintf(fp, "endfacet\n");
    if(getNumVertices() == 4){
      fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
      fprintf(fp, "  outer loop\n");
      for(int j = 0; j < 3; j++)
	fprintf(fp, "    vertex %g %g %g\n", 
		getVertex(qid[j])->x() * scalingFactor, 
		getVertex(qid[j])->y() * scalingFactor, 
		getVertex(qid[j])->z() * scalingFactor);
      fprintf(fp, "  endloop\n");
      fprintf(fp, "endfacet\n");
    }
  }
  else{
    char data[50];
    float *coords = (float*)data;
    coords[0] = n[0];
    coords[1] = n[1];
    coords[2] = n[2];
    for(int j = 0; j < 3; j++){
      coords[3 + 3 * j] = getVertex(j)->x() * scalingFactor;
      coords[3 + 3 * j + 1] = getVertex(j)->y() * scalingFactor;
      coords[3 + 3 * j + 2] = getVertex(j)->z() * scalingFactor;
    }
    data[48] = data[49] = 0;
    fwrite(data, sizeof(char), 50, fp);
    if(getNumVertices() == 4){
      for(int j = 0; j < 3; j++){
	coords[3 + 3 * j] = getVertex(qid[j])->x() * scalingFactor;
	coords[3 + 3 * j + 1] = getVertex(qid[j])->y() * scalingFactor;
	coords[3 + 3 * j + 2] = getVertex(qid[j])->z() * scalingFactor;
      }
      fwrite(data, sizeof(char), 50, fp);
    }
  }
}

void MElement::writeVRML(FILE *fp)
{
  for(int i = 0; i < getNumVertices(); i++)
    fprintf(fp, "%d,", getVertex(i)->getNum() - 1);
  fprintf(fp, "-1,\n");
}

void MElement::writeUNV(FILE *fp, int num, int elementary, int physical)
{
  int type = getTypeForUNV();
  if(!type) return;

  setVolumePositive();
  int n = getNumVertices();
  int physical_property = elementary;
  int material_property = abs(physical);
  int color = 7;
  fprintf(fp, "%10d%10d%10d%10d%10d%10d\n",
	  num ? num : _num, type, physical_property, material_property, color, n);
  if(type == 21 || type == 24) // linear beam or parabolic beam
    fprintf(fp, "%10d%10d%10d\n", 0, 0, 0);

  if(physical < 0) revert();

  for(int k = 0; k < n; k++) {
    fprintf(fp, "%10d", getVertexUNV(k)->getNum());
    if(k % 8 == 7)
      fprintf(fp, "\n");
  }
  if(n - 1 % 8 != 7)
    fprintf(fp, "\n");

  if(physical < 0) revert();
}

void MElement::writeMESH(FILE *fp, int elementary)
{
  for(int i = 0; i < getNumVertices(); i++)
    fprintf(fp, " %d", getVertex(i)->getNum());
  fprintf(fp, " %d\n", elementary);
}

void MElement::writeBDF(FILE *fp, int format, int elementary)
{
  const char *str = getStringForBDF();
  if(!str) return;

  setVolumePositive();
  int n = getNumVertices();
  const char *cont[4] = {"E", "F", "G", "H"};
  int ncont = 0;
  
  if(format == 0){ // free field format
    fprintf(fp, "%s,%d,%d", str, _num, elementary);
    for(int i = 0; i < n; i++){
      fprintf(fp, ",%d", getVertex(i)->getNum());
      if(i != n - 1 && !((i + 3) % 8)){
	fprintf(fp, ",+%s%d\n+%s%d", cont[ncont], _num, cont[ncont], _num);
	ncont++;
      }
    }
    if(n == 2) // CBAR
      fprintf(fp, ",0.,0.,0.");
    fprintf(fp, "\n");
  }
  else{ // small or large field format
    fprintf(fp, "%-8s%-8d%-8d", str, _num, elementary);
    for(int i = 0; i < n; i++){
      fprintf(fp, "%-8d", getVertex(i)->getNum());
      if(i != n - 1 && !((i + 3) % 8)){
	fprintf(fp, "+%s%-6d\n+%s%-6d", cont[ncont], _num, cont[ncont], _num);
	ncont++;
      }
    }
    if(n == 2) // CBAR
      fprintf(fp, "%-8s%-8s%-8s", "0.", "0.", "0.");
    fprintf(fp, "\n");
  }
}

bool MTriangle::invertmappingXY(double *p, double *uv, double tol)
{
  double mat[2][2];
  double b[2];
  getMat(mat);
  b[0] = p[0] - getVertex(0)->x();
  b[1] = p[1] - getVertex(0)->y();
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

bool MTriangle::invertmappingUV(GFace* gf, double *p, double *uv, double tol)
{
  double mat[2][2];
  double b[2];
  double u0, v0, u1, v1, u2, v2;

  parametricCoordinates(getVertex(0), gf, u0, v0);
  parametricCoordinates(getVertex(1), gf, u1, v1);
  parametricCoordinates(getVertex(2), gf, u2, v2);
  
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

double MTriangle::getSurfaceUV(GFace *gf)
{
  double u3, v3, u1, v1, u2, v2;

  parametricCoordinates(getVertex(0), gf, u1, v1);
  parametricCoordinates(getVertex(1), gf, u2, v2);
  parametricCoordinates(getVertex(2), gf, u3, v3);

  const double vv1 [2] = {u2 - u1, v2 - v1};
  const double vv2 [2] = {u3 - u1, v3 - v1};

  double s = vv1[0] * vv2[1] - vv1[1] * vv2[0]; 
  return s * 0.5;
}

double MTriangle::getSurfaceXY() const
{
  const double x1 = _v[0]->x();
  const double x2 = _v[1]->x();
  const double x3 = _v[2]->x();
  const double y1 = _v[0]->y();
  const double y2 = _v[1]->y();
  const double y3 = _v[2]->y();

  const double v1 [2] = {x2 - x1, y2 - y1};
  const double v2 [2] = {x3 - x1, y3 - y1};

  double s = v1[0] * v2[1] - v1[1] * v2[0]; 
  return s * 0.5;
}

void MTriangle::circumcenterXYZ(double *p1, double *p2, double *p3, 
				double *res, double *uv)
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

  circumcenterXY(p1P, p2P, p3P,resP);

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

void MTriangle::circumcenterXY(double *p1, double *p2, double *p3, double *res)
{
  double d, a1, a2, a3;

  const double x1 = p1[0];
  const double x2 = p2[0];
  const double x3 = p3[0];
  const double y1 = p1[1];
  const double y2 = p2[1];
  const double y3 = p3[1];

  d = 2. * (double)(y1 * (x2 - x3) + y2 * (x3 - x1) + y3 * (x1 - x2));
  if(d == 0.0) {
    Msg(WARNING, "Colinear points in circum circle computation");
    res[0] = res[1] = -99999.;
    return ;
  }

  a1 = x1 * x1 + y1 * y1;
  a2 = x2 * x2 + y2 * y2;
  a3 = x3 * x3 + y3 * y3;
  res[0] = (double)((a1 * (y3 - y2) + a2 * (y1 - y3) + a3 * (y2 - y1)) / d);
  res[1] = (double)((a1 * (x2 - x3) + a2 * (x3 - x1) + a3 * (x1 - x2)) / d);
}

void MTriangle::circumcenterUV(GFace *gf, double *res)
{
  double u3, v3, u1, v1, u2, v2;

  parametricCoordinates(getVertex(0), gf, u1, v1);
  parametricCoordinates(getVertex(1), gf, u2, v2);
  parametricCoordinates(getVertex(2), gf, u3, v3);

  double p1[2] = {u1, v1};
  double p2[2] = {u2, v2};
  double p3[2] = {u3, v3};

  circumcenterXY(p1, p2, p3, res);
}

void MTriangle::circumcenterXY(double *res) const
{
  double p1[2] = {_v[0]->x(), _v[0]->y()};
  double p2[2] = {_v[1]->x(), _v[1]->y()};
  double p3[2] = {_v[2]->x(), _v[2]->y()};
  circumcenterXY(p1, p2, p3, res);
}

void MTriangle::jac(int ord, MVertex *vs[], double uu, double vv, double j[2][3])
{
#if defined(HAVE_GMSH_EMBEDDED)
  return;
#else
  double grads[256][2];
  int nf = getNumFaceVertices();

  if (!nf){
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).df(uu, vv, grads); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).df(uu, vv, grads); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_9).df(uu, vv, grads); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_12).df(uu, vv, grads); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_15I).df(uu, vv, grads); break;
    default: throw;
    }
  }
  else{
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).df(uu, vv, grads); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).df(uu, vv, grads); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_10).df(uu, vv, grads); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_15).df(uu, vv, grads); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_21).df(uu, vv, grads); break;
    default: throw;
    }
  }
  j[0][0] = 0 ; for(int i = 0; i < 3; i++) j[0][0] += grads [i][0] * _v[i]->x();
  j[1][0] = 0 ; for(int i = 0; i < 3; i++) j[1][0] += grads [i][1] * _v[i]->x();
  j[0][1] = 0 ; for(int i = 0; i < 3; i++) j[0][1] += grads [i][0] * _v[i]->y();
  j[1][1] = 0 ; for(int i = 0; i < 3; i++) j[1][1] += grads [i][1] * _v[i]->y();
  j[0][2] = 0 ; for(int i = 0; i < 3; i++) j[0][2] += grads [i][0] * _v[i]->z();
  j[1][2] = 0 ; for(int i = 0; i < 3; i++) j[1][2] += grads [i][1] * _v[i]->z();

  if (ord == 1) return;

  for(int i = 3; i < 3 * ord + nf; i++) j[0][0] += grads[i][0] * vs[i - 3]->x();
  for(int i = 3; i < 3 * ord + nf; i++) j[1][0] += grads[i][1] * vs[i - 3]->x();
  for(int i = 3; i < 3 * ord + nf; i++) j[0][1] += grads[i][0] * vs[i - 3]->y();
  for(int i = 3; i < 3 * ord + nf; i++) j[1][1] += grads[i][1] * vs[i - 3]->y();
  for(int i = 3; i < 3 * ord + nf; i++) j[0][2] += grads[i][0] * vs[i - 3]->z();
  for(int i = 3; i < 3 * ord + nf; i++) j[1][2] += grads[i][1] * vs[i - 3]->z();
#endif
}

void MTriangle::pnt(int ord, MVertex *vs[], double uu, double vv, SPoint3 &p)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  double sf[256];
  int nf = getNumFaceVertices();

  if (!nf){
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).f(uu, vv, sf); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).f(uu, vv, sf); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_9).f(uu, vv, sf); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_12).f(uu, vv, sf); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_15I).f(uu, vv, sf); break;
    default: throw;
    }
  }
  else{
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).f(uu, vv, sf); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).f(uu, vv, sf); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_10).f(uu, vv, sf); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_15).f(uu, vv, sf); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_21).f(uu, vv, sf); break;
    default: throw;
    }
  }
  
  double x = 0 ; for(int i = 0; i < 3; i++) x += sf[i] * _v[i]->x();
  double y = 0 ; for(int i = 0; i < 3; i++) y += sf[i] * _v[i]->y();
  double z = 0 ; for(int i = 0; i < 3; i++) z += sf[i] * _v[i]->z();

  for(int i = 3; i < 3 * ord + nf; i++) x += sf[i] * vs[i - 3]->x();
  for(int i = 3; i < 3 * ord + nf; i++) y += sf[i] * vs[i - 3]->y();
  for(int i = 3; i < 3 * ord + nf; i++) z += sf[i] * vs[i - 3]->z();

  p = SPoint3(x,y,z);
#endif
}

void MTriangleN::jac(double uu, double vv , double j[2][3])  
{
  MTriangle::jac(_order, &(*(_vs.begin())), uu, vv, j);
}

void MTriangleN::pnt(double uu, double vv, SPoint3 &p){
  MTriangle::pnt(_order, &(*(_vs.begin())), uu, vv, p);
}

void MTriangle6::jac(double uu, double vv , double j[2][3])  
{
  MTriangle::jac(2, _vs, uu, vv, j);
}

void MTriangle6::pnt(double uu, double vv, SPoint3 &p){
  MTriangle::pnt(2, _vs, uu, vv, p);
}

void MTriangle::jac(double uu, double vv, double j[2][3])
{
  jac(1, 0, uu, vv, j);
}

void MTriangle::pnt(double uu, double vv, SPoint3 &p)
{
  MTriangle::pnt(1, 0, uu, vv, p);
}

int MTriangle6::getNumEdgesRep(){ return 3 * 6; }

void MTriangle6::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  n[0] = n[1] = getFace(0).normal();
  int N = getNumEdgesRep() / 3;
  if (num < N){
    SPoint3 pnt1, pnt2;
    pnt((double)num / N, 0., pnt1);
    pnt((double)(num + 1) / N, 0., pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return;
  }  
  if (num < 2 * N){
    SPoint3 pnt1, pnt2;
    num -= N;
    pnt(1. - (double)num / N, (double)num / N, pnt1);
    pnt(1. - (double)(num + 1) / N, (double)(num + 1) / N, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return ;
  }  
  {
    SPoint3 pnt1, pnt2;
    num -= 2 * N;
    pnt(0, (double)num / N, pnt1);
    pnt(0, (double)(num + 1) / N, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
  }
}

int MTriangleN::getNumEdgesRep(){ return 3 * 12; }

void MTriangleN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  n[0] = n[1] = getFace(0).normal();
  int N = getNumEdgesRep() / 3;
  if (num < N){
    SPoint3 pnt1, pnt2;
    pnt((double)num / N, 0., pnt1);
    pnt((double)(num + 1) / N, 0., pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return;
  }  
  if (num < 2 * N){
    SPoint3 pnt1, pnt2;
    num -= N;
    pnt(1. - (double)num / N, (double)num / N, pnt1);
    pnt(1. - (double)(num + 1) / N, (double)(num + 1) / N, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return ;
  }  
  {
    SPoint3 pnt1, pnt2;
    num -= 2 * N;
    pnt(0, (double)num / N, pnt1);
    pnt(0, (double)(num + 1) / N, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
  }
}
