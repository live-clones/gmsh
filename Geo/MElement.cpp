// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include <math.h>
#include "MElement.h"
#include "GEntity.h"
#include "GFace.h"
#include "FunctionSpace.h"
#include "Message.h"

#if defined(HAVE_GMSH_EMBEDDED)
#include "GmshEmbedded.h"
#else
#include "Numeric.h"
#include "GaussLegendre1D.h"
#include "Context.h"
#include "qualityMeasures.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGRegionDelaunayInsertion.h"
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

void MElement::getShapeFunction(int num,double u,double v,double w,double &s) {
#if !defined(HAVE_GMSH_EMBEDDED)
  double sf[256];
  getFunctionSpace()->f(u,v,w,sf);
  s = sf[num];
#endif
}

void MElement::getGradShapeFunction(int num,double uu,double vv,double ww,double s[3]) {
#if !defined(HAVE_GMSH_EMBEDDED)
  double sf[256][3];
  getFunctionSpace()->df(uu, vv, ww, sf);
  for (int i=0;i<3;i++) s[i] = sf[num][i];
#endif
}


SPoint3 MTriangle::circumcenter()
{
#if defined(HAVE_GMSH_EMBEDDED)
  return SPoint3();
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
  return SPoint3();
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

const gmshFunctionSpace* MTriangle::getFunctionSpace(int o) const {

  int order = (o == -1) ? getPolynomialOrder() : o;

  int nf = getNumFaceVertices();  

  if ((nf ==0) && (o == -1)) {
    switch (order) {
    case 1: return &gmshFunctionSpaces::find(MSH_TRI_3); break;
    case 2: return &gmshFunctionSpaces::find(MSH_TRI_6); break;
    case 3: return &gmshFunctionSpaces::find(MSH_TRI_9); break;
    case 4: return &gmshFunctionSpaces::find(MSH_TRI_12); break;
    case 5: return &gmshFunctionSpaces::find(MSH_TRI_15I); break;
    default: Msg::Error("Order %d triangle function space not implemented", order); break;
    }
  }
  else { 
    switch (order) {
    case 1: return &gmshFunctionSpaces::find(MSH_TRI_3); break;
    case 2: return &gmshFunctionSpaces::find(MSH_TRI_6); break;
    case 3: return &gmshFunctionSpaces::find(MSH_TRI_10); break;
    case 4: return &gmshFunctionSpaces::find(MSH_TRI_15); break;
    case 5: return &gmshFunctionSpaces::find(MSH_TRI_21); break;
    default: Msg::Error("Order %d triangle function space implemented", order); break;
    }
  }
  return NULL;
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


const gmshFunctionSpace* MTetrahedron::getFunctionSpace(int o) const {

  int order = (o == -1) ? getPolynomialOrder() : o;

  int nv = getNumVolumeVertices();
  
  
  if ((nv == 0) && (o == -1)) {
    switch (order) {
    case 1: return &gmshFunctionSpaces::find(MSH_TET_4); break;
    case 2: return &gmshFunctionSpaces::find(MSH_TET_10); break;
    case 3: return &gmshFunctionSpaces::find(MSH_TET_20); break;
    case 4: return &gmshFunctionSpaces::find(MSH_TET_34); break;
    case 5: return &gmshFunctionSpaces::find(MSH_TET_52); break;
    default: Msg::Error("Order %d tetrahedron function space not implemented", order); break;
    }
  }
  else { 
    switch (order) {
    case 1: return &gmshFunctionSpaces::find(MSH_TET_4); break;
    case 2: return &gmshFunctionSpaces::find(MSH_TET_10); break;
    case 3: return &gmshFunctionSpaces::find(MSH_TET_20); break;
    case 4: return &gmshFunctionSpaces::find(MSH_TET_35); break;
    case 5: return &gmshFunctionSpaces::find(MSH_TET_56); break;
    default: Msg::Error("Order %d tetrahedron function space implemented", order); break;
    }
  }
  return NULL;
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

  const gmshFunctionSpace* fs = getFunctionSpace();
  
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  double gsf[256][3];
  fs->df(u,v,w,gsf);
  for (int i=0;i<getNumVertices();i++) {
    
    const MVertex* v = getVertex(i);
    double* gg = gsf[i];
    
    for (int j=0;j<3;j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  double dJ = 0;
  
  switch (fs->monomials.size2()) {

  case 1: 
    {
      dJ = sqrt(jac[0][0] * jac[0][0] + jac[1][1] * jac[0][0] + jac[2][2] * jac[2][2]);
      break;
    }
  case 2:
    {
      dJ = sqrt(SQU(jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0]) +
                SQU(jac[0][2] * jac[1][0] - jac[0][0] * jac[1][2]) +
                SQU(jac[0][1] * jac[1][2] - jac[0][2] * jac[1][1]));
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



double MElement::getPrimaryJacobian(double u, double v, double w, double jac[3][3])
{

  const gmshFunctionSpace* fs = getFunctionSpace(1);
  
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  double gsf[256][3];
  fs->df(u,v,w,gsf);
  
  for (int i=0;i<getNumPrimaryVertices();i++) {
    
    const MVertex* v = getVertex(i);
    double* gg = gsf[i];
    
    for (int j=0;j<3;j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  double dJ = 0;
  
  switch (fs->monomials.size2()) {

  case 1: 
    {
      dJ = sqrt(jac[0][0] * jac[0][0] + jac[0][0] * jac[0][0] + jac[0][0] * jac[0][0]);
      break;
    }
  case 2:
    {
      dJ = sqrt(SQU(jac[0][0] * jac[1][1] - jac[0][1] * jac[1][0]) +
                SQU(jac[0][2] * jac[1][0] - jac[0][0] * jac[1][2]) +
                SQU(jac[0][1] * jac[1][2] - jac[0][2] * jac[1][1]));
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

void MElement::pnt(double uu, double vv, double ww, SPoint3 &p) {


  double x=0.;
  double y=0.;
  double z=0.;
  
  const gmshFunctionSpace* fs = getFunctionSpace();

  if (fs) {

    double sf[256];
    fs->f(uu,vv,ww,sf);
    
    for (int j=0;j<getNumVertices();j++) {
      const MVertex* v = getVertex(j);
      x += sf[j] * v->x();
      y += sf[j] * v->y();
      z += sf[j] * v->z();
    } 
  }
  else Msg::Fatal("Could not find function space\n");
  
  p = SPoint3(x,y,z);
  
}

void MElement::primaryPnt(double uu, double vv, double ww, SPoint3 &p) {
  
  double x=0.;
  double y=0.;
  double z=0.;
  
  const gmshFunctionSpace* fs = getFunctionSpace(1);

  if (fs) {

    double sf[256];
    fs->f(uu,vv,ww,sf);
    if (getNumPrimaryVertices() != 4) printf("Incorrect number of vertices %d\n",getNumPrimaryVertices()
                                             );
    
    
    for (int j=0;j<getNumPrimaryVertices();j++) {
      const MVertex* v = getVertex(j);
      x += sf[j] * v->x();
      y += sf[j] * v->y();
      z += sf[j] * v->z();
    } 
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

const gmshFunctionSpace* MLine::getFunctionSpace(int o) const {

  int order = o == -1 ? getPolynomialOrder() : o;
  
  switch (order) {
  case 1: return &gmshFunctionSpaces::find(MSH_LIN_2); break;
  case 2: return &gmshFunctionSpaces::find(MSH_LIN_3); break;
  case 3: return &gmshFunctionSpaces::find(MSH_LIN_4); break;
  case 4: return &gmshFunctionSpaces::find(MSH_LIN_5); break;
  case 5: return &gmshFunctionSpaces::find(MSH_LIN_6); break;
  default: Msg::Error("Order %d line point interpolation not implemented", getPolynomialOrder()); break;
  }
  return NULL;
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
  double J1[3][3], J2[3][3], J3[3][3];
  if (ix % 2 == 0){
    pnt(ix / 2 * d, iy * d, 0, pnt1);
    pnt((ix / 2 + 1) * d, iy * d, 0, pnt2);
    pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    getJacobian(ix / 2 * d, iy * d, 0, J1);
    getJacobian((ix / 2 + 1) * d, iy * d, 0, J2);
    getJacobian(ix / 2 * d, (iy + 1) * d, 0, J3);
  }
  else{
    pnt((ix / 2 + 1) * d, iy * d, 0, pnt1);
    pnt((ix / 2 + 1) * d, (iy + 1) * d, 0, pnt2);
    pnt(ix / 2 * d, (iy + 1) * d, 0, pnt3);
    getJacobian((ix / 2 + 1) * d, iy * d, 0, J1);
    getJacobian((ix / 2 + 1) * d, (iy + 1) * d, 0, J2);
    getJacobian(ix / 2 * d, (iy + 1) * d, 0, J3);
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
  n[0] = n[1] = n[2] = getFace(0).normal();
  int N = getNumEdgesRep() / 3;
  if (num < N){
    SPoint3 pnt1, pnt2;
    pnt((double)num / N, 0., 0.,pnt1);
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

int MTetrahedronN::getNumEdgesRep(){ return 6 * numSubEdges; }

void MTetrahedronN::getEdgeRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  static double pp[4][3] = {{0,0,0},{1,0,0},{0,1,0},{0,0,1}};
  static int ed [6][2] = {{0,1},{0,2},{0,3},{1,2},{1,3},{2,3}};
  int iEdge = num / numSubEdges;
  int iSubEdge = num % numSubEdges;  

  
  int iVertex1 = ed [iEdge][0];
  int iVertex2 = ed [iEdge][1];
  double t1 = (double) iSubEdge / (double) numSubEdges;
  double u1 = pp[iVertex1][0] * (1.-t1) + pp[iVertex2][0] * t1;
  double v1 = pp[iVertex1][1] * (1.-t1) + pp[iVertex2][1] * t1;
  double w1 = pp[iVertex1][2] * (1.-t1) + pp[iVertex2][2] * t1;

  double t2 = (double) (iSubEdge+1) / (double) numSubEdges;
  double u2 = pp[iVertex1][0] * (1.-t2) + pp[iVertex2][0] * t2;
  double v2 = pp[iVertex1][1] * (1.-t2) + pp[iVertex2][1] * t2;
  double w2 = pp[iVertex1][2] * (1.-t2) + pp[iVertex2][2] * t2;

  SPoint3 pnt1, pnt2;
  pnt(u1,v1,w1,pnt1);
  pnt(u2,v2,w2,pnt2);
  x[0] = pnt1.x(); x[1] = pnt2.x(); 
  y[0] = pnt1.y(); y[1] = pnt2.y();
  z[0] = pnt1.z(); z[1] = pnt2.z();
}

int MTetrahedronN::getNumFacesRep(){ return 4 * numSubEdges * numSubEdges ; }

void MTetrahedronN::getFaceRep(int num, double *x, double *y, double *z, SVector3 *n)
{
  static double pp[4][3] = {{0,0,0},{1,0,0},{0,1,0},{0,0,1}};
  static int fak [4][3] = {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};
  int iFace    = num / (numSubEdges*numSubEdges);
  int iSubFace = num % (numSubEdges*numSubEdges);  
  
  int iVertex1 = fak [iFace][0];
  int iVertex2 = fak [iFace][1];
  int iVertex3 = fak [iFace][2];

  /*
    0
    0 1
    0 1 2
    0 1 2 3
    0 1 2 3 4
    0 1 2 3 4 5
  */

  //  on the first layer, we have (numSubEdges-1) * 2 + 1 triangles
  //  on the second layer, we have (numSubEdges-2) * 2 + 1 triangles
  //  on the ith layer, we have (numSubEdges-1-i) * 2 + 1 triangles
  int ix = 0, iy = 0;
  int nbt = 0;
  for (int i = 0; i < numSubEdges; i++){
    int nbl = (numSubEdges - i - 1) * 2 + 1;
    nbt += nbl;
    if (nbt > iSubFace){
      iy = i;
      ix = nbl - (nbt - iSubFace);
      break;
    }
  }

  const double d = 1. / numSubEdges;

  SPoint3 pnt1, pnt2, pnt3;
  double J1[2][3], J2[2][3], J3[2][3];
  double u1,v1,u2,v2,u3,v3;
  if (ix % 2 == 0){
    u1 = ix / 2 * d; v1= iy*d;
    u2 = (ix / 2 + 1) * d ; v2 =  iy * d;
    u3 = ix / 2 * d ; v3 =  (iy+1) * d;
  }
  else{
    u1 = (ix / 2 + 1) * d; v1= iy * d;
    u2 = (ix / 2 + 1) * d; v2= (iy + 1) * d;
    u3 = ix / 2 * d ; v3 =  (iy + 1) * d;
  }

  double U1 = pp[iVertex1][0] * (1.-u1-v1) + pp[iVertex2][0] * u1 + pp[iVertex3][0] * v1;
  double U2 = pp[iVertex1][0] * (1.-u2-v2) + pp[iVertex2][0] * u2 + pp[iVertex3][0] * v2;
  double U3 = pp[iVertex1][0] * (1.-u3-v3) + pp[iVertex2][0] * u3 + pp[iVertex3][0] * v3;

  double V1 = pp[iVertex1][1] * (1.-u1-v1) + pp[iVertex2][1] * u1 + pp[iVertex3][1] * v1;
  double V2 = pp[iVertex1][1] * (1.-u2-v2) + pp[iVertex2][1] * u2 + pp[iVertex3][1] * v2;
  double V3 = pp[iVertex1][1] * (1.-u3-v3) + pp[iVertex2][1] * u3 + pp[iVertex3][1] * v3;

  double W1 = pp[iVertex1][2] * (1.-u1-v1) + pp[iVertex2][2] * u1 + pp[iVertex3][2] * v1;
  double W2 = pp[iVertex1][2] * (1.-u2-v2) + pp[iVertex2][2] * u2 + pp[iVertex3][2] * v2;
  double W3 = pp[iVertex1][2] * (1.-u3-v3) + pp[iVertex2][2] * u3 + pp[iVertex3][2] * v3;

  pnt(U1,V1,W1,pnt1);
  pnt(U2,V2,W2,pnt2);
  pnt(U3,V3,W3,pnt3);

  x[0] = pnt1.x(); x[1] = pnt2.x(); x[2] = pnt3.x();
  y[0] = pnt1.y(); y[1] = pnt2.y(); y[2] = pnt3.y();
  z[0] = pnt1.z(); z[1] = pnt2.z(); z[2] = pnt3.z();

  // facetted first

  SVector3 d1(x[1]-x[0],y[1]-y[0],z[1]-z[0]);
  SVector3 d2(x[2]-x[0],y[2]-y[0],z[2]-z[0]);
  n[0] = crossprod(d1, d2);
  n[0].normalize();
  n[1] = n[0];
  n[2] = n[0];
 
  return;
 
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
