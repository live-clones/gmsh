// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <math.h>
#include "MElement.h"
#include "GEntity.h"
#include "GFace.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Numeric.h"
#  include "FunctionSpace.h"
#  include "GaussLegendre1D.h"
#  include "Message.h"
#  include "Context.h"
#  include "qualityMeasures.h"
#  include "meshGFaceDelaunayInsertion.h"
#  include "meshGRegionDelaunayInsertion.h"
#endif

#define SQU(a)      ((a)*(a))

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

void MElement::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
  Msg::Error("No integration points defined for this type of element");
}

SPoint3 MTriangle::circumcenter()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 0.;
#else
  double p1[3] = {_v[0]->x(),_v[0]->y(),_v[0]->z()};
  double p2[3] = {_v[1]->x(),_v[1]->y(),_v[1]->z()};
  double p3[3] = {_v[2]->x(),_v[2]->y(),_v[2]->z()};
  double res[3];
  circumCenterXYZ(p1,p2,p3,res);
  return SPoint3(res[0],res[1],res[2]);
#endif
}

SPoint3 MTetrahedron::circumcenter()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 0.;
#else
  MTet4 t(this,0);
  double res[3];
  t.circumcenter(res);
  return SPoint3(res[0],res[1],res[2]);
#endif
}


double MTriangle::distoShapeMeasure()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 1.;
#else
  return qmDistorsionOfMapping(this);
#endif
}

double MTetrahedron::distoShapeMeasure()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return 1.;
#else
  return qmDistorsionOfMapping(this);
#endif
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

double MTetrahedron::getVolume()
{
  double mat[3][3];
  getMat(mat);
  return det3x3(mat) / 6.;
}

void MTetrahedron::xyz2uvw(double xyz[3], double uvw[3])
{
  double mat[3][3], b[3], det;
  getMat(mat);
  b[0] = xyz[0] - getVertex(0)->x();
  b[1] = xyz[1] - getVertex(0)->y();
  b[2] = xyz[2] - getVertex(0)->z();
  sys3x3(mat, b, uvw, &det);
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

double MElement::getJacobian(double u, double v, double w, double jac[3][3])
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;
  double s[3];
  switch(getDim()){
  case 3 :
    for(int i = 0; i < getNumVertices(); i++) {
      getGradShapeFunction(i, u, v, w, s);
      MVertex *p = getVertex(i);
      jac[0][0] += p->x() * s[0]; jac[0][1] += p->y() * s[0]; jac[0][2] += p->z() * s[0];
      jac[1][0] += p->x() * s[1]; jac[1][1] += p->y() * s[1]; jac[1][2] += p->z() * s[1];
      jac[2][0] += p->x() * s[2]; jac[2][1] += p->y() * s[2]; jac[2][2] += p->z() * s[2];
    }
    return fabs(jac[0][0] * jac[1][1] * jac[2][2] + jac[0][2] * jac[1][0] * jac[2][1] +
                jac[0][1] * jac[1][2] * jac[2][0] - jac[0][2] * jac[1][1] * jac[2][0] -
                jac[0][0] * jac[1][2] * jac[2][1] - jac[0][1] * jac[1][0] * jac[2][2]);
  case 2 :
    for(int i = 0; i < getNumVertices(); i++) {
      getGradShapeFunction(i, u, v, w, s);
      MVertex *p = getVertex(i);
      jac[0][0] += p->x() * s[0]; jac[0][1] += p->y() * s[0]; jac[0][2] += p->z() * s[0];
      jac[1][0] += p->x() * s[1]; jac[1][1] += p->y() * s[1]; jac[1][2] += p->z() * s[1];
    }
    {
      double a[3], b[3], c[3];
      a[0] = getVertex(1)->x() - getVertex(0)->x(); 
      a[1] = getVertex(1)->y() - getVertex(0)->y();
      a[2] = getVertex(1)->z() - getVertex(0)->z();     
      b[0] = getVertex(2)->x() - getVertex(0)->x(); 
      b[1] = getVertex(2)->y() - getVertex(0)->y();
      b[2] = getVertex(2)->z() - getVertex(0)->z();     
      prodve(a, b, c);
      jac[2][0] = c[0]; jac[2][1] = c[1]; jac[2][2] = c[2]; 
    }
    return sqrt(SQU(jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0]) +
                SQU(jac[0][2] * jac[1][0] - jac[0][0] * jac[1][2]) +
                SQU(jac[0][1] * jac[1][2] - jac[0][2] * jac[1][1]));
  case 1:
    for(int i = 0; i < getNumVertices(); i++) {
      getGradShapeFunction(i, u, v, w, s);
      MVertex *p = getVertex(i);
      jac[0][0] += p->x() * s[0]; jac[0][1] += p->y() * s[0]; jac[0][2] += p->z() * s[0];
    }
    {
      double a[3], b[3], c[3];
      a[0] = getVertex(1)->x() - getVertex(0)->x(); 
      a[1] = getVertex(1)->y() - getVertex(0)->y();
      a[2] = getVertex(1)->z() - getVertex(0)->z();     
      if((fabs(a[0]) >= fabs(a[1]) && fabs(a[0]) >= fabs(a[2])) ||
         (fabs(a[1]) >= fabs(a[0]) && fabs(a[1]) >= fabs(a[2]))) {
        b[0] = a[1]; b[1] = -a[0]; b[2] = 0.;
      }
      else {
        b[0] = 0.; b[1] = a[2]; b[2] = -a[1];
      }
      prodve(a, b, c);
      jac[1][0] = b[0]; jac[1][1] = b[1]; jac[1][2] = b[2]; 
      jac[2][0] = c[0]; jac[2][1] = c[1]; jac[2][2] = c[2]; 
    }
    return sqrt(SQU(jac[0][0]) + SQU(jac[0][1]) + SQU(jac[0][2]));
  default:
    return 1.;
  }
}

void MElement::xyz2uvw(double xyz[3], double uvw[3])
{
  // general Newton routine for the nonlinear case (more efficient
  // routines are implemented for simplices, where the basis functions
  // are linear)
  uvw[0] = uvw[1] = uvw[2] = 0.;
  int iter = 1, maxiter = 20;
  double error = 1., tol = 1.e-6;

  while (error > tol && iter < maxiter){
    double jac[3][3];
    if(!getJacobian(uvw[0], uvw[1], uvw[2], jac)) break;
    double xn = 0., yn = 0., zn = 0.;
    for (int i = 0; i < getNumVertices(); i++) {
      double s;
      getShapeFunction(i, uvw[0], uvw[1], uvw[2], s);
      MVertex *v = getVertex(i);
      xn += v->x() * s;
      yn += v->y() * s;
      zn += v->z() * s;
    }
    double inv[3][3];
    inv3x3(jac, inv);
    double un = uvw[0] +
      inv[0][0] * (xyz[0] - xn) + inv[1][0] * (xyz[1] - yn) + inv[2][0] * (xyz[2] - zn);
    double vn = uvw[1] +
      inv[0][1] * (xyz[0] - xn) + inv[1][1] * (xyz[1] - yn) + inv[2][1] * (xyz[2] - zn) ;
    double wn = uvw[2] +
      inv[0][2] * (xyz[0] - xn) + inv[1][2] * (xyz[1] - yn) + inv[2][2] * (xyz[2] - zn) ;
    error = sqrt(SQU(un - uvw[0]) + SQU(vn - uvw[1]) + SQU(wn - uvw[2]));
    uvw[0] = un;
    uvw[1] = vn;
    uvw[2] = wn;
    iter++ ;
  }
}

double MElement::interpolate(double val[], double u, double v, double w, int stride)
{
  double sum = 0;
  int j = 0;
  for(int i = 0; i < getNumVertices(); i++){
    double s;
    getShapeFunction(i, u, v, w, s);
    sum += val[j] * s;
    j += stride;
  }
  return sum;
}

void MElement::interpolateGrad(double val[], double u, double v, double w, double f[3],
                               int stride, double invjac[3][3])
{
  double dfdu[3] = {0., 0., 0.};
  int j = 0;
  for(int i = 0; i < getNumVertices(); i++){
    double s[3];
    getGradShapeFunction(i, u, v, w, s);
    dfdu[0] += val[j] * s[0];
    dfdu[1] += val[j] * s[1];
    dfdu[2] += val[j] * s[2];
    j += stride;
  }
  if(invjac){
    matvec(invjac, dfdu, f);
  }
  else{
    double jac[3][3], inv[3][3];
    getJacobian(u, v, w, jac);
    inv3x3(jac, inv);
    matvec(inv, dfdu, f);
  }
}

void MElement::interpolateCurl(double val[], double u, double v, double w, double f[3],
                               int stride)
{
  double fx[3], fy[3], fz[3], jac[3][3], inv[3][3];
  getJacobian(u, v, w, jac);
  inv3x3(jac, inv);
  interpolateGrad(&val[0], u, v, w, fx, stride, inv);
  interpolateGrad(&val[1], u, v, w, fy, stride, inv);
  interpolateGrad(&val[2], u, v, w, fz, stride, inv);
  f[0] = fz[1] - fy[2];
  f[1] = -(fz[0] - fx[2]);
  f[2] = fy[0] - fx[1];
}

double MElement::interpolateDiv(double val[], double u, double v, double w, int stride)
{
  double fx[3], fy[3], fz[3], jac[3][3], inv[3][3];
  getJacobian(u, v, w, jac);
  inv3x3(jac, inv);
  interpolateGrad(&val[0], u, v, w, fx, stride, inv);
  interpolateGrad(&val[1], u, v, w, fy, stride, inv);
  interpolateGrad(&val[2], u, v, w, fz, stride, inv);
  return fx[0] + fy[1] + fz[2];
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

  int verts[60];
  for(int i = 0; i < n; i++)
    verts[i] = getVertex(i)->getIndex();

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
                        bool printDisto, double scalingFactor, int elementary)
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
  if(printDisto){
    double disto = distoShapeMeasure();
    for(int i = 0; i < n; i++){
      if(first) first = false; else fprintf(fp, ",");
      fprintf(fp, "%g", disto);
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
    fprintf(fp, "%d,", getVertex(i)->getIndex() - 1);
  fprintf(fp, "-1,\n");
}

void MElement::writeVTK(FILE *fp, bool binary)
{
  int type = getTypeForUNV();
  if(!type) return;

  setVolumePositive();

  int n = getNumVertices();
  if(binary){
    int verts[60];
    verts[0] = n;
    for(int i = 0; i < n; i++)
      verts[i + 1] = getVertexVTK(i)->getIndex() - 1;
    fwrite(verts, sizeof(int), n + 1, fp);
  }
  else{
    fprintf(fp, "%d", n);
    for(int i = 0; i < n; i++)
      fprintf(fp, " %d", getVertexVTK(i)->getIndex() - 1);
    fprintf(fp, "\n");
  }
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
    fprintf(fp, "%10d", getVertexUNV(k)->getIndex());
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
    fprintf(fp, " %d", getVertex(i)->getIndex());
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
      fprintf(fp, ",%d", getVertexBDF(i)->getIndex());
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
      fprintf(fp, "%-8d", getVertexBDF(i)->getIndex());
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

int MElement::getInfoMSH(const int typeMSH, const char **const name)
{
  switch(typeMSH){
  case MSH_PNT    : if(name) *name = "Point";           return 1;
  case MSH_LIN_2  : if(name) *name = "Line 2";          return 2;
  case MSH_LIN_3  : if(name) *name = "Line 3";          return 2 + 1;
  case MSH_LIN_4  : if(name) *name = "Line 4";          return 2 + 2;
  case MSH_LIN_5  : if(name) *name = "Line 5";          return 2 + 3;
  case MSH_LIN_6  : if(name) *name = "Line 6";          return 2 + 4;
  case MSH_TRI_3  : if(name) *name = "Triangle 3";      return 3;
  case MSH_TRI_6  : if(name) *name = "Triangle 6";      return 3 + 3;
  case MSH_TRI_9  : if(name) *name = "Triangle 9";      return 3 + 6;
  case MSH_TRI_10 : if(name) *name = "Triangle 10";     return 3 + 6 + 1;
  case MSH_TRI_12 : if(name) *name = "Triangle 12";     return 3 + 9;
  case MSH_TRI_15 : if(name) *name = "Triangle 15";     return 3 + 9 + 3;
  case MSH_TRI_15I: if(name) *name = "Triangle 15I";    return 3 + 12;
  case MSH_TRI_21 : if(name) *name = "Triangle 21";     return 3 + 12 + 6;
  case MSH_QUA_4  : if(name) *name = "Quadrilateral 4"; return 4;
  case MSH_QUA_8  : if(name) *name = "Quadrilateral 8"; return 4 + 4;
  case MSH_QUA_9  : if(name) *name = "Quadrilateral 9"; return 4 + 4 + 1;
  case MSH_TET_4  : if(name) *name = "Tetrahedron 4";   return 4;
  case MSH_TET_10 : if(name) *name = "Tetrahedron 10";  return 4 + 6;
  case MSH_TET_20 : if(name) *name = "Tetrahedron 20";  return 4 + 12 + 4;
  case MSH_TET_34 : if(name) *name = "Tetrahedron 34";  return 4 + 18 + 12 + 0;
  case MSH_TET_35 : if(name) *name = "Tetrahedron 35";  return 4 + 18 + 12 + 1;
  case MSH_TET_52 : if(name) *name = "Tetrahedron 52";  return 4 + 24 + 24 + 0;
  case MSH_TET_56 : if(name) *name = "Tetrahedron 56";  return 4 + 24 + 24 + 4;
  case MSH_HEX_8  : if(name) *name = "Hexahedron 8";    return 8;
  case MSH_HEX_20 : if(name) *name = "Hexahedron 20";   return 8 + 12;
  case MSH_HEX_27 : if(name) *name = "Hexahedron 27";   return 8 + 12 + 6 + 1;
  case MSH_PRI_6  : if(name) *name = "Prism 6";         return 6;
  case MSH_PRI_15 : if(name) *name = "Prism 15";        return 6 + 9;
  case MSH_PRI_18 : if(name) *name = "Prism 18";        return 6 + 9 + 3;
  case MSH_PYR_5  : if(name) *name = "Pyramid 5";       return 5;
  case MSH_PYR_13 : if(name) *name = "Pyramid 13";      return 5 + 8;
  case MSH_PYR_14 : if(name) *name = "Pyramid 14";      return 5 + 8 + 1;
  default: 
    Msg::Error("Unknown type of element %d", typeMSH); 
    if(name) *name = "Unknown"; 
    return 0;
  }               
}                 

void MTriangle::jac(int ord, MVertex *vs[], double uu, double vv, double ww,
		    double j[2][3])
{
#if !defined(HAVE_GMSH_EMBEDDED)
  double grads[256][2];
  int nf = getNumFaceVertices();

  if (!nf){
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).df(uu, vv, ww, grads); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).df(uu, vv, ww, grads); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_9).df(uu, vv, ww, grads); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_12).df(uu, vv, ww, grads); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_15I).df(uu, vv, ww, grads); break;
    default: Msg::Error("Order %d triangle jac not implemented", ord); break;
    }
  }
  else{
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).df(uu, vv, ww, grads); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).df(uu, vv, ww, grads); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_10).df(uu, vv, ww, grads); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_15).df(uu, vv, ww, grads); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_21).df(uu, vv, ww, grads); break;
    default: Msg::Error("Order %d triangle jac not implemented", ord); break;
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

void MTriangle::pnt(int ord, MVertex *vs[], double uu, double vv, double ww,
		    SPoint3 &p)
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
    default: Msg::Error("Order %d triangle pnt not implemented", ord); break;
    }
  }
  else{
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TRI_3).f(uu, vv, sf); break;
    case 2: gmshFunctionSpaces::find(MSH_TRI_6).f(uu, vv, sf); break;
    case 3: gmshFunctionSpaces::find(MSH_TRI_10).f(uu, vv, sf); break;
    case 4: gmshFunctionSpaces::find(MSH_TRI_15).f(uu, vv, sf); break;
    case 5: gmshFunctionSpaces::find(MSH_TRI_21).f(uu, vv, sf); break;
    default: Msg::Error("Order %d triangle pnt not implemented", ord); break;
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

void MTetrahedron::jac(int ord, MVertex *vs[], double uu, double vv, double ww,
		       double j[3][3])
{
#if !defined(HAVE_GMSH_EMBEDDED)
  double grads[256][3];
  switch(ord){
  case 1: gmshFunctionSpaces::find(MSH_TET_4) .df(uu, vv, ww, grads); break;
  case 2: gmshFunctionSpaces::find(MSH_TET_10).df(uu, vv, ww, grads); break;
  case 3: gmshFunctionSpaces::find(MSH_TET_20).df(uu, vv, ww, grads); break;
  case 4: gmshFunctionSpaces::find(MSH_TET_35).df(uu, vv, ww, grads); break;
  case 5: gmshFunctionSpaces::find(MSH_TET_56).df(uu, vv, ww, grads); break;
  default: Msg::Error("Order %d tetrahedron jac not implemented", ord); break;
  }
 
  j[0][0] = 0 ; for(int i = 0; i < 4; i++) j[0][0] += grads [i][0] * _v[i]->x();
  j[1][0] = 0 ; for(int i = 0; i < 4; i++) j[1][0] += grads [i][1] * _v[i]->x();
  j[2][0] = 0 ; for(int i = 0; i < 4; i++) j[2][0] += grads [i][2] * _v[i]->x();
  
  j[0][1] = 0 ; for(int i = 0; i < 4; i++) j[0][1] += grads [i][0] * _v[i]->y();
  j[1][1] = 0 ; for(int i = 0; i < 4; i++) j[1][1] += grads [i][1] * _v[i]->y();
  j[2][1] = 0 ; for(int i = 0; i < 4; i++) j[2][1] += grads [i][2] * _v[i]->y();
  
  j[0][2] = 0 ; for(int i = 0; i < 4; i++) j[0][2] += grads [i][0] * _v[i]->z();
  j[1][2] = 0 ; for(int i = 0; i < 4; i++) j[1][2] += grads [i][1] * _v[i]->z();
  j[2][2] = 0 ; for(int i = 0; i < 4; i++) j[2][2] += grads [i][2] * _v[i]->z();
  
  if (ord == 1) return;

  const int N = (ord+1)*(ord+2)*(ord+3)/6;

  for(int i = 4; i < N; i++) j[0][0] += grads[i][0] * vs[i - 4]->x();
  for(int i = 4; i < N; i++) j[1][0] += grads[i][1] * vs[i - 4]->x();
  for(int i = 4; i < N; i++) j[2][0] += grads[i][2] * vs[i - 4]->x();

  for(int i = 4; i < N; i++) j[0][1] += grads[i][0] * vs[i - 4]->y();
  for(int i = 4; i < N; i++) j[1][1] += grads[i][1] * vs[i - 4]->y();
  for(int i = 4; i < N; i++) j[2][1] += grads[i][2] * vs[i - 4]->y();

  for(int i = 4; i < N; i++) j[0][2] += grads[i][0] * vs[i - 4]->z();
  for(int i = 4; i < N; i++) j[1][2] += grads[i][1] * vs[i - 4]->z();
  for(int i = 4; i < N; i++) j[2][2] += grads[i][2] * vs[i - 4]->z();
#endif
}

void MTetrahedron::pnt(int ord, MVertex *vs[], double uu, double vv, double ww,
		       SPoint3 &p)
{
#if !defined(HAVE_GMSH_EMBEDDED)
  double sf[256];

  int nv = getNumVolumeVertices();

  if (!nv){
    switch(ord){
    case 1: gmshFunctionSpaces::find(MSH_TET_4).f(uu, vv, ww, sf); break;
    case 2: gmshFunctionSpaces::find(MSH_TET_10).f(uu, vv, ww, sf); break;
    case 3: gmshFunctionSpaces::find(MSH_TET_20).f(uu, vv, ww, sf); break;
    case 4: gmshFunctionSpaces::find(MSH_TET_34).f(uu, vv, ww, sf); break;
    case 5: gmshFunctionSpaces::find(MSH_TET_52).f(uu, vv, ww, sf); break;
    default: Msg::Error("Order %d tetrahedron pnt not implemented", ord); break;
    }
  }
  else{
    switch(ord){
    case 4: gmshFunctionSpaces::find(MSH_TET_35).f(uu, vv, ww, sf); break;
    case 5: gmshFunctionSpaces::find(MSH_TET_56).f(uu, vv, ww, sf); break;
    default: Msg::Error("Order %d tetrahedron pnt not implemented", ord); break;
    }
  }
    
  double x = 0 ; for(int i = 0; i < 4; i++) x += sf[i] * _v[i]->x();
  double y = 0 ; for(int i = 0; i < 4; i++) y += sf[i] * _v[i]->y();
  double z = 0 ; for(int i = 0; i < 4; i++) z += sf[i] * _v[i]->z();

  const int N = (ord+1)*(ord+2)*(ord+3)/6;
  
  
  for(int i = 4; i < N; i++) x += sf[i] * vs[i - 4]->x();
  for(int i = 4; i < N; i++) y += sf[i] * vs[i - 4]->y();
  for(int i = 4; i < N; i++) z += sf[i] * vs[i - 4]->z();

  p = SPoint3(x,y,z);
#endif
}

const int numSubEdges = 6;

int MTriangleN::getNumFacesRep(){ return numSubEdges * numSubEdges; }

void MTriangleN::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  //  on the first layer, we have (numSubEdges-1) * 2 + 1 triangles
  //  on the second layer, we have (numSubEdges-2) * 2 + 1 triangles
  //  on the ith layer, we have (numSubEdges-1-i) * 2 + 1 triangles
  int ix = 0, iy = 0;
  int nbt = 0;
  for (int i = 0; i < numSubEdges; i++){
    int nbl = (numSubEdges - i - 1) * 2 + 1;
    nbt += nbl;
    if (nbt > num){
      iy = i;
      ix = nbl - (nbt - num);
      break;
    }
  }

  const double d = 1. / numSubEdges;

  SPoint3 pnt1, pnt2, pnt3;
  double J1[2][3], J2[2][3], J3[2][3];
  if (ix % 2 == 0){
    pnt(ix / 2 * d, iy * d, 0, pnt1);
    pnt((ix / 2 + 1) * d, iy * d, 0, pnt2);
    pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    jac(ix / 2 * d, iy * d, 0, J1);
    jac((ix / 2 + 1) * d, iy * d, 0, J2);
    jac(ix / 2 * d, (iy + 1) * d, 0, J3);
  }
  else{
    pnt((ix / 2 + 1) * d, iy * d, 0, pnt1);
    pnt((ix / 2 + 1) * d, (iy + 1) * d, 0, pnt2);
    pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    jac((ix / 2 + 1) * d, iy * d, 0, J1);
    jac((ix / 2 + 1) * d, (iy + 1) * d, 0, J2);
    jac(ix / 2 * d, (iy + 1) * d, 0, J3);
  }
  {
    SVector3 d1(J1[0][0], J1[0][1], J1[0][2]);
    SVector3 d2(J1[1][0], J1[1][1], J1[1][2]);
    n[0] = crossprod(d1, d2);
    n[0].normalize();
  }
  {
    SVector3 d1(J2[0][0], J2[0][1], J2[0][2]);
    SVector3 d2(J2[1][0], J2[1][1], J2[1][2]);
    n[1] = crossprod(d1, d2);
    n[1].normalize();
  }
  {
    SVector3 d1(J3[0][0], J3[0][1], J3[0][2]);
    SVector3 d2(J3[1][0], J3[1][1], J3[1][2]);
    n[2] = crossprod(d1, d2);
    n[2].normalize();
  }

  x[0] = pnt1.x(); x[1] = pnt2.x(); x[2] = pnt3.x();
  y[0] = pnt1.y(); y[1] = pnt2.y(); y[2] = pnt3.y();
  z[0] = pnt1.z(); z[1] = pnt2.z(); z[2] = pnt3.z();
}

int MTriangleN::getNumEdgesRep(){ return 3 * numSubEdges; }

void MTriangleN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  n[0] = n[1] = getFace(0).normal();
  int N = getNumEdgesRep() / 3;
  if (num < N){
    SPoint3 pnt1, pnt2;
    pnt((double)num / N, 0., 0,pnt1);
    pnt((double)(num + 1) / N, 0., 0, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return;
  }  
  if (num < 2 * N){
    SPoint3 pnt1, pnt2;
    num -= N;
    pnt(1. - (double)num / N, (double)num / N, 0, pnt1);
    pnt(1. - (double)(num + 1) / N, (double)(num + 1) / N, 0, pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
    return ;
  }  
  {
    SPoint3 pnt1, pnt2;
    num -= 2 * N;
    pnt(0, (double)num / N, 0,pnt1);
    pnt(0, (double)(num + 1) / N, 0,pnt2);
    x[0] = pnt1.x(); x[1] = pnt2.x();
    y[0] = pnt1.y(); y[1] = pnt2.y();
    z[0] = pnt1.z(); z[1] = pnt2.z();
  }
}

MElement *MElementFactory::create(int type, std::vector<MVertex*> &v, 
				  int num, int part)
{
  switch (type) {
  case MSH_PNT:    return new MPoint(v, num, part);
  case MSH_LIN_2:  return new MLine(v, num, part);
  case MSH_LIN_3:  return new MLine3(v, num, part);
  case MSH_LIN_4:  return new MLineN(v, num, part);
  case MSH_LIN_5:  return new MLineN(v, num, part);
  case MSH_LIN_6:  return new MLineN(v, num, part);
  case MSH_TRI_3:  return new MTriangle(v, num, part);
  case MSH_TRI_6:  return new MTriangle6(v, num, part);
  case MSH_TRI_9:  return new MTriangleN(v, 3, num, part);
  case MSH_TRI_10: return new MTriangleN(v, 3, num, part);
  case MSH_TRI_12: return new MTriangleN(v, 4, num, part);
  case MSH_TRI_15: return new MTriangleN(v, 4, num, part);
  case MSH_TRI_15I:return new MTriangleN(v, 5, num, part);
  case MSH_TRI_21: return new MTriangleN(v, 5, num, part);
  case MSH_QUA_4:  return new MQuadrangle(v, num, part);
  case MSH_QUA_8:  return new MQuadrangle8(v, num, part);
  case MSH_QUA_9:  return new MQuadrangle9(v, num, part);
  case MSH_TET_4:  return new MTetrahedron(v, num, part);
  case MSH_TET_10: return new MTetrahedron10(v, num, part);
  case MSH_HEX_8:  return new MHexahedron(v, num, part);
  case MSH_HEX_20: return new MHexahedron20(v, num, part);
  case MSH_HEX_27: return new MHexahedron27(v, num, part);
  case MSH_PRI_6:  return new MPrism(v, num, part);
  case MSH_PRI_15: return new MPrism15(v, num, part);
  case MSH_PRI_18: return new MPrism18(v, num, part);
  case MSH_PYR_5:  return new MPyramid(v, num, part);
  case MSH_PYR_13: return new MPyramid13(v, num, part);
  case MSH_PYR_14: return new MPyramid14(v, num, part);
  case MSH_TET_20: return new MTetrahedronN(v, 3, num, part);
  case MSH_TET_34: return new MTetrahedronN(v, 3, num, part);
  case MSH_TET_35: return new MTetrahedronN(v, 4, num, part);
  case MSH_TET_52: return new MTetrahedronN(v, 5, num, part);
  case MSH_TET_56: return new MTetrahedronN(v, 5, num, part);
  default:         return 0;
  }
}

extern int getNGQTPts(int order);
extern IntPt *getGQTPts (int order);
extern int getNGQTetPts(int order);
extern IntPt *getGQTetPts(int order);
extern int getNGQQPts(int order);
extern IntPt *getGQQPts(int order);
extern int getNGQHPts(int order);
extern IntPt *getGQHPts(int order);

IntPt GQL[100]; 

void MLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  double *t, *w;
  int nbP = pOrder / 2 + 1;
  gmshGaussLegendre1D(nbP, &t, &w);
  for (int i = 0; i < nbP; i++){
    GQL[i].pt[0] = t[i];
    GQL[i].pt[1] = 0;
    GQL[i].pt[2] = 0;
    GQL[i].weight = w[i];
  }
  *npts = nbP;
  *pts = GQL;
#endif
}

void MTriangle:: getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  *npts = getNGQTPts(pOrder);
  *pts = getGQTPts(pOrder);
#endif
}

void MTetrahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  *npts = getNGQTetPts(pOrder);
  *pts = getGQTetPts(pOrder);
#endif
}

void MHexahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  *npts = getNGQHPts(pOrder);
  *pts = getGQHPts(pOrder);
#endif
}

void MQuadrangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts) const
{
#if !defined(HAVE_GMSH_EMBEDDED)
  *npts = getNGQQPts(pOrder);
  *pts = getGQQPts(pOrder);
#endif
}
