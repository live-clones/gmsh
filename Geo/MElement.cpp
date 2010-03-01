// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <math.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "MElement.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "GEntity.h"
#include "GFace.h"
#include "StringUtils.h"
#include "Numeric.h"
#include "Context.h"

#define SQU(a)      ((a)*(a))

int MElement::_globalNum = 0;
double MElement::_isInsideTolerance = 1.e-6;
double MElementLessThanLexicographic::tolerance = 1.e-6;

MElement::MElement(int num, int part) : _visible(1) 
{
#pragma omp critical
  {
    if(num){
      _num = num;
      _globalNum = std::max(_globalNum, _num);
    }
    else{
      _num = ++_globalNum;
    }
    _partition = (short)part; 
  }
}

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

char MElement::getVisibility() const
{
  if(CTX::instance()->hideUnselected && _visible < 2) return false;
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

void MElement::getShapeFunctions(double u, double v, double w, double s[], int o)
{
  const polynomialBasis* fs = getFunctionSpace(o);
  if(fs) fs->f(u, v, w, s);
  else Msg::Error("Function space not implemented for this type of element");
}

void MElement::getGradShapeFunctions(double u, double v, double w, double s[][3], 
                                     int o)
{
  const polynomialBasis* fs = getFunctionSpace(o);
  if(fs) fs->df(u, v, w, s);
  else Msg::Error("Function space not implemented for this type of element");
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

static double _computeDeterminantAndRegularize(MElement *ele, double jac[3][3])
{
  double dJ = 0;
  
  switch (ele->getDim()) {

  case 0:
    {
      dJ = 1.0;
      jac[0][0] = jac[1][1] = jac[2][2] = 1.0;
      jac[0][1] = jac[1][0] = jac[2][0] = 0.0;
      jac[0][2] = jac[1][2] = jac[2][1] = 0.0;    
      break;
    } 
  case 1: 
    {
      dJ = sqrt(SQU(jac[0][0]) + SQU(jac[0][1]) + SQU(jac[0][2]));

      // regularize matrix
      double a[3], b[3], c[3];
      a[0] = jac[0][0];
      a[1] = jac[0][1];
      a[2] = jac[0][2];
      if((fabs(a[0]) >= fabs(a[1]) && fabs(a[0]) >= fabs(a[2])) ||
         (fabs(a[1]) >= fabs(a[0]) && fabs(a[1]) >= fabs(a[2]))) {
        b[0] = a[1]; b[1] = -a[0]; b[2] = 0.;
      }
      else {
        b[0] = 0.; b[1] = a[2]; b[2] = -a[1];
      }
      norme(b);
      prodve(a, b, c);
      norme(c);
      jac[0][1] = b[0]; jac[1][1] = b[1]; jac[2][1] = b[2]; 
      jac[0][2] = c[0]; jac[1][2] = c[1]; jac[2][2] = c[2]; 
      break;
    }
  case 2:
    {
      dJ = sqrt(SQU(jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0]) +
                SQU(jac[0][2] * jac[1][0] - jac[0][0] * jac[1][2]) +
                SQU(jac[0][1] * jac[1][2] - jac[0][2] * jac[1][1]));

      // regularize matrix
      double a[3], b[3], c[3];
      a[0] = jac[0][0];
      a[1] = jac[0][1];
      a[2] = jac[0][2];
      b[0] = jac[1][0];
      b[1] = jac[1][1];
      b[2] = jac[1][2];
      prodve(a, b, c);
      norme(c);
      jac[2][0] = c[0]; jac[2][1] = c[1]; jac[2][2] = c[2];
      break;
    }
  case 3:
    {
      dJ = fabs(jac[0][0] * jac[1][1] * jac[2][2] + jac[0][2] * jac[1][0] * jac[2][1] +
                jac[0][1] * jac[1][2] * jac[2][0] - jac[0][2] * jac[1][1] * jac[2][0] -
                jac[0][0] * jac[1][2] * jac[2][1] - jac[0][1] * jac[1][0] * jac[2][2]);
      break;
    }
  }
  return dJ; 
}

double MElement::getJacobian(double u, double v, double w, double jac[3][3])
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  double gsf[256][3];
  getGradShapeFunctions(u, v, w, gsf);
  for (int i = 0; i < getNumVertices(); i++) {
    const MVertex* v = getVertex(i);
    double* gg = gsf[i];
    for (int j = 0; j < 3; j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  return _computeDeterminantAndRegularize(this, jac);
}

double MElement::getPrimaryJacobian(double u, double v, double w, double jac[3][3])
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  double gsf[256][3];
  getGradShapeFunctions(u, v, w, gsf, 1);
  for(int i = 0; i < getNumPrimaryVertices(); i++) {
    const MVertex* v = getVertex(i);
    double* gg = gsf[i];
    for (int j = 0; j < 3; j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  return _computeDeterminantAndRegularize(this, jac);
}

void MElement::pnt(double u, double v, double w, SPoint3 &p)
{
  double x = 0., y = 0., z = 0.;
  double sf[256];
  getShapeFunctions(u, v, w, sf);
  for (int j = 0; j < getNumVertices(); j++) {
    const MVertex* v = getVertex(j);
    x += sf[j] * v->x();
    y += sf[j] * v->y();
    z += sf[j] * v->z();
  } 
  p = SPoint3(x, y, z);
}

void MElement::primaryPnt(double u, double v, double w, SPoint3 &p)
{
  double x = 0., y = 0., z = 0.;
  double sf[256];
  getShapeFunctions(u, v, w, sf, 1);
  for (int j = 0; j < getNumPrimaryVertices(); j++) {
    const MVertex* v = getVertex(j);
    x += sf[j] * v->x();
    y += sf[j] * v->y();
    z += sf[j] * v->z();
  }
  p = SPoint3(x,y,z);
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
    double sf[256];
    getShapeFunctions(uvw[0], uvw[1], uvw[2], sf);
    for (int i = 0; i < getNumVertices(); i++) {
      MVertex *v = getVertex(i);
      xn += v->x() * sf[i];
      yn += v->y() * sf[i];
      zn += v->z() * sf[i];
    }
    double inv[3][3];
    inv3x3(jac, inv);
    double un = uvw[0] + inv[0][0] * (xyz[0] - xn) + 
      inv[1][0] * (xyz[1] - yn) + inv[2][0] * (xyz[2] - zn);
    double vn = uvw[1] + inv[0][1] * (xyz[0] - xn) +
      inv[1][1] * (xyz[1] - yn) + inv[2][1] * (xyz[2] - zn);
    double wn = uvw[2] + inv[0][2] * (xyz[0] - xn) +
      inv[1][2] * (xyz[1] - yn) + inv[2][2] * (xyz[2] - zn);
    error = sqrt(SQU(un - uvw[0]) + SQU(vn - uvw[1]) + SQU(wn - uvw[2]));
    uvw[0] = un;
    uvw[1] = vn;
    uvw[2] = wn;
    iter++ ;
  }
}

double MElement::interpolate(double val[], double u, double v, double w, int stride,
                             int order)
{
  double sum = 0;
  int j = 0;
  double sf[256];
  getShapeFunctions(u, v, w, sf, order);
  for(int i = 0; i < getNumVertices(); i++){
    sum += val[j] * sf[i];
    j += stride;
  }
  return sum;
}

void MElement::interpolateGrad(double val[], double u, double v, double w, double f[3],
                               int stride, double invjac[3][3], int order)
{
  double dfdu[3] = {0., 0., 0.};
  int j = 0;
  double gsf[256][3];
  getGradShapeFunctions(u, v, w, gsf, order);
  for(int i = 0; i < getNumVertices(); i++){
    dfdu[0] += val[j] * gsf[i][0];
    dfdu[1] += val[j] * gsf[i][1];
    dfdu[2] += val[j] * gsf[i][2];
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
                               int stride, int order)
{
  double fx[3], fy[3], fz[3], jac[3][3], inv[3][3];
  getJacobian(u, v, w, jac);
  inv3x3(jac, inv);
  interpolateGrad(&val[0], u, v, w, fx, stride, inv, order);
  interpolateGrad(&val[1], u, v, w, fy, stride, inv, order);
  interpolateGrad(&val[2], u, v, w, fz, stride, inv, order);
  f[0] = fz[1] - fy[2];
  f[1] = -(fz[0] - fx[2]);
  f[2] = fy[0] - fx[1];
}

double MElement::interpolateDiv(double val[], double u, double v, double w, 
                                int stride, int order)
{
  double fx[3], fy[3], fz[3], jac[3][3], inv[3][3];
  getJacobian(u, v, w, jac);
  inv3x3(jac, inv);
  interpolateGrad(&val[0], u, v, w, fx, stride, inv, order);
  interpolateGrad(&val[1], u, v, w, fy, stride, inv, order);
  interpolateGrad(&val[2], u, v, w, fz, stride, inv, order);
  return fx[0] + fy[1] + fz[2];
}

void MElement::writeMSH(FILE *fp, double version, bool binary, int num, 
                        int elementary, int physical, int parentNum,
                        std::vector<short> *ghosts)
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
    else if(!_partition)
      fprintf(fp, " 2 %d %d", abs(physical), elementary);
    else if(!ghosts)
      fprintf(fp, " 4 %d %d 1 %d", abs(physical), elementary, _partition);
    else{
      int numGhosts = ghosts->size();
      fprintf(fp, " %d %d %d %d %d", 4 + numGhosts, abs(physical), elementary, 
              1 + numGhosts, _partition);
      for(unsigned int i = 0; i < ghosts->size(); i++)
        fprintf(fp, " %d", -(*ghosts)[i]);
    }
  }
  else{
    int numTags, numGhosts = 0;
    if(!_partition) numTags = 2;
    else if(!ghosts) numTags = 4;
    else{
      numGhosts = ghosts->size();
      numTags = 4 + numGhosts;
    }
    // we write elements in blobs of single elements; this will lead
    // to suboptimal reads, but it's much simpler when the number of
    // tags change from element to element (third-party codes can
    // still write MSH file optimized for reading speed, by grouping
    // elements with the same number of tags in blobs)
    int blob[60] = {type, 1, numTags, num ? num : _num, abs(physical), elementary, 
                    1 + numGhosts, _partition};
    if(ghosts)
      for(int i = 0; i < numGhosts; i++) blob[8 + i] = -(*ghosts)[i];
    fwrite(blob, sizeof(int), 4 + numTags, fp);
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

  setVolumePositive();
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
  if(getType() != TYPE_TRI && getType() != TYPE_QUA) return;
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
    coords[0] = (float)n[0];
    coords[1] = (float)n[1];
    coords[2] = (float)n[2];
    for(int j = 0; j < 3; j++){
      coords[3 + 3 * j] = (float)(getVertex(j)->x() * scalingFactor);
      coords[3 + 3 * j + 1] = (float)(getVertex(j)->y() * scalingFactor);
      coords[3 + 3 * j + 2] = (float)(getVertex(j)->z() * scalingFactor);
    }
    data[48] = data[49] = 0;
    fwrite(data, sizeof(char), 50, fp);
    if(getNumVertices() == 4){
      for(int j = 0; j < 3; j++){
        coords[3 + 3 * j] = (float)(getVertex(qid[j])->x() * scalingFactor);
        coords[3 + 3 * j + 1] = (float)(getVertex(qid[j])->y() * scalingFactor);
        coords[3 + 3 * j + 2] = (float)(getVertex(qid[j])->z() * scalingFactor);
      }
      fwrite(data, sizeof(char), 50, fp);
    }
  }
}

void MElement::writeVRML(FILE *fp)
{
  setVolumePositive();
  for(int i = 0; i < getNumVertices(); i++)
    fprintf(fp, "%d,", getVertex(i)->getIndex() - 1);
  fprintf(fp, "-1,\n");
}

void MElement::writeVTK(FILE *fp, bool binary, bool bigEndian)
{
  if(!getTypeForVTK()) return;

  setVolumePositive();

  int n = getNumVertices();
  if(binary){
    int verts[60];
    verts[0] = n;
    for(int i = 0; i < n; i++)
      verts[i + 1] = getVertexVTK(i)->getIndex() - 1;
    // VTK always expects big endian binary data
    if(!bigEndian) SwapBytes((char*)verts, sizeof(int), n + 1);
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

void MElement::writeMESH(FILE *fp, int elementTagType, int elementary, 
                         int physical)
{
  setVolumePositive();
  for(int i = 0; i < getNumVertices(); i++)
    fprintf(fp, " %d", getVertex(i)->getIndex());
  fprintf(fp, " %d\n", (elementTagType == 3) ? _partition : 
          (elementTagType == 2) ? physical : elementary);
}

void MElement::writeFEA(FILE *fp, int elementTagType, int num, int elementary, 
                        int physical)
{
  int numVert = getNumVertices();
  setVolumePositive();
  fprintf(fp, "%d %d %d", num, (elementTagType == 3) ? _partition : 
          (elementTagType == 2) ? physical : elementary, numVert);
  for(int i = 0; i < numVert; i++)
    fprintf(fp, " %d", getVertex(i)->getIndex());
  fprintf(fp, "\n");
}

void MElement::writeBDF(FILE *fp, int format, int elementTagType, int elementary,
                        int physical)
{
  const char *str = getStringForBDF();
  if(!str) return;

  setVolumePositive();
  int n = getNumVertices();
  const char *cont[4] = {"E", "F", "G", "H"};
  int ncont = 0;
  
  int tag =  (elementTagType == 3) ? _partition : (elementTagType == 2) ? 
    physical : elementary;

  if(format == 0){ // free field format
    fprintf(fp, "%s,%d,%d", str, _num, tag);
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
    fprintf(fp, "%-8s%-8d%-8d", str, _num, tag);
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

void MElement::writeDIFF(FILE *fp, int num, bool binary, int physical_property)
{
  const char *str = getStringForDIFF();
  if(!str) return;

  setVolumePositive();

  int n = getNumVertices();
  if(binary){
    // TODO
  }
  else{
    fprintf(fp, "%d %s %d ", num, str, physical_property);
    for(int i = 0; i < n; i++)
      fprintf(fp, " %d", getVertexDIFF(i)->getIndex());
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
  case MSH_QUA_9  : if(name) *name = "Quadrilateral 9"; return 9;
  case MSH_QUA_16  : if(name) *name = "Quadrilateral 16"; return 16;
  case MSH_QUA_25  : if(name) *name = "Quadrilateral 25"; return 25;
  case MSH_QUA_36  : if(name) *name = "Quadrilateral 36"; return 36;
  case MSH_QUA_12 : if(name) *name = "Quadrilateral 12"; return 12;
  case MSH_QUA_16I : if(name) *name = "Quadrilateral 16I"; return 16;
  case MSH_QUA_20 : if(name) *name = "Quadrilateral 20"; return 20;
  case MSH_POLYG_ : if(name) *name = "Polygon";         return 0;
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
  case MSH_POLYH_ : if(name) *name = "Polyhedron";      return 0;
  default: 
    Msg::Error("Unknown type of element %d", typeMSH); 
    if(name) *name = "Unknown"; 
    return 0;
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
  case MSH_QUA_16:  return new MQuadrangleN(v, 3, num, part);
  case MSH_QUA_25:  return new MQuadrangleN(v, 4, num, part);
  case MSH_QUA_36:  return new MQuadrangleN(v, 5, num, part);
  case MSH_POLYG_: return new MPolygon(v, num, part);
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
  case MSH_POLYH_: return new MPolyhedron(v, num, part);
  default:         return 0;
  }
}

#include "Bindings.h"

void MElement::registerBindings(binding *b)
{
  classBinding *cb = b->addClass<MElement>("MElement");
  cb->setDescription("A mesh element.");
  methodBinding *cm;
  cm = cb->addMethod("getNum",&MElement::getNum);
  cm->setDescription("return the tag of the element");
  cm = cb->addMethod("getNumVertices", &MElement::getNumVertices);
  cm->setDescription("get the number of vertices of this element");
  cm = cb->addMethod("getVertex", &MElement::getVertex);
  cm->setDescription("return the i-th vertex of this element");
  cm->setArgNames("i",NULL);
  cm = cb->addMethod("getType", &MElement::getType);
  cm->setDescription("get the type of the element");
  cm = cb->addMethod("getTypeForMSH", &MElement::getTypeForMSH);
  cm->setDescription("get the gmsh type of the element");
  cm = cb->addMethod("getPartition", &MElement::getPartition);
  cm->setDescription("get the partition to which the element belongs");
  cm = cb->addMethod("getPolynomialOrder", &MElement::getPolynomialOrder);
  cm->setDescription("return the polynomial order the element");
  cm = cb->addMethod("getDim", &MElement::getDim);
  cm->setDescription("return the geometrical dimension of the element");
}
