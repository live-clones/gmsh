// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include <cmath>
#include <limits>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MElementCut.h"
#include "MSubElement.h"
#include "GEntity.h"
#include "StringUtils.h"
#include "Numeric.h"
#include "nodalBasis.h"
#include "CondNumBasis.h"
#include "Context.h"
#include "FuncSpaceData.h"
#include "bezierBasis.h"
#include "polynomialBasis.h"

#if defined(HAVE_MESH)
#include "qualityMeasuresJacobian.h"
#endif

#define SQU(a) ((a) * (a))

MElement::MElement(std::size_t num, int part) : _visible(1)
{
  // we should make GModel a mandatory argument to the constructor
  GModel *m = GModel::current();
  if(num) {
    _num = num;
    m->setMaxElementNumber(_num);
  }
  else {
    _num = m->incrementAndGetMaxElementNumber();
  }
  _partition = (short)part;
}

void MElement::forceNum(std::size_t num)
{
  GModel *m = GModel::current();
  _num = num;
  m->setMaxElementNumber(_num);
}

double MElement::getTolerance() const
{
  return CTX::instance()->mesh.toleranceReferenceElement;
}

bool MElement::_getFaceInfo(const MFace &face, const MFace &other, int &sign,
                            int &rot)
{
  // Looks how is 'other' compared to 'face'. We suppose that 'face'
  // is the reference.
  // Return false if they are different.
  // In case sign = 1, then rot = 1 if 'other' is equal to 'face' rotated
  // one time according to the right hand side.
  // In case sign = -1, then rot = 0 if 'other' is equal to reversed 'face'.
  // In case sign = -1, then rot = 1 if 'other' is equal to reversed 'face'
  // rotated one time according to the right hand side.
  int N = face.getNumVertices();

  sign = 0;
  rot = -1;

  if(face.getNumVertices() != other.getNumVertices()) return false;

  sign = 1;
  for(rot = 0; rot < N; ++rot) {
    int i;
    for(i = 0; i < N; ++i) {
      if(other.getVertex(i) != face.getVertex((i + rot) % N)) break;
    }
    if(i == N) return true;
  }

  sign = -1;
  for(rot = 0; rot < N; ++rot) {
    int i;
    for(i = 0; i < N; ++i) {
      if(other.getVertex(i) != face.getVertex((N + rot - i) % N)) break;
    }
    if(i == N) return true;
  }

  sign = 0;
  rot = -1;
  return false;
}

void MElement::_getEdgeRep(MVertex *v0, MVertex *v1, double *x, double *y,
                           double *z, SVector3 *n, int faceIndex)
{
  x[0] = v0->x();
  y[0] = v0->y();
  z[0] = v0->z();
  x[1] = v1->x();
  y[1] = v1->y();
  z[1] = v1->z();
  if(faceIndex >= 0) { n[0] = n[1] = getFace(faceIndex).normal(); }
  else {
    MEdge e(v0, v1);
    n[0] = n[1] = e.normal();
  }
}

#if defined(HAVE_VISUDEV)
void MElement::_getFaceRepQuad(MVertex *v0, MVertex *v1, MVertex *v2,
                               MVertex *v3, double *x, double *y, double *z,
                               SVector3 *n)
{
  x[0] = v0->x();
  x[1] = v1->x();
  x[2] = (x[0] + x[1] + v2->x() + v3->x()) / 4;
  y[0] = v0->y();
  y[1] = v1->y();
  y[2] = (y[0] + y[1] + v2->y() + v3->y()) / 4;
  z[0] = v0->z();
  z[1] = v1->z();
  z[2] = (z[0] + z[1] + v2->z() + v3->z()) / 4;
  ;
  SVector3 t1(x[1] - x[0], y[1] - y[0], z[1] - z[0]);
  SVector3 t2(x[2] - x[0], y[2] - y[0], z[2] - z[0]);
  SVector3 normal = crossprod(t1, t2);
  normal.normalize();
  for(int i = 0; i < 3; i++) n[i] = normal;
}
#endif

void MElement::_getFaceRep(MVertex *v0, MVertex *v1, MVertex *v2, double *x,
                           double *y, double *z, SVector3 *n)
{
  x[0] = v0->x();
  x[1] = v1->x();
  x[2] = v2->x();
  y[0] = v0->y();
  y[1] = v1->y();
  y[2] = v2->y();
  z[0] = v0->z();
  z[1] = v1->z();
  z[2] = v2->z();
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

MEdgeN MElement::getHighOrderEdge(int num, int sign)
{
  const int order = getPolynomialOrder();
  std::vector<MVertex *> vertices(static_cast<std::size_t>(order) + 1);
  vertices[0] = getVertex(numEdge2numVertex(num, sign > 0 ? 0 : 1));
  vertices[1] = getVertex(numEdge2numVertex(num, sign > 0 ? 1 : 0));
  const int start = (int)getNumPrimaryVertices() + num * (order - 1);
  const int end = (int)getNumPrimaryVertices() + (num + 1) * (order - 1);
  int k = 1;
  if(sign > 0) {
    for(int i = start; i < end; ++i) { vertices[++k] = getVertex(i); }
  }
  else {
    for(int i = end - 1; i >= start; --i) { vertices[++k] = getVertex(i); }
  }
  return MEdgeN(vertices);
}

bool MElement::getEdgeInfo(const MEdge &edge, int &ithEdge, int &sign) const
{
  for(ithEdge = 0; ithEdge < getNumEdges(); ithEdge++) {
    const MVertex *v0 = getVertex(numEdge2numVertex(ithEdge, 0));
    const MVertex *v1 = getVertex(numEdge2numVertex(ithEdge, 1));
    if(v0 == edge.getVertex(0) && v1 == edge.getVertex(1)) {
      sign = 1;
      return true;
    }
    if(v1 == edge.getVertex(0) && v0 == edge.getVertex(1)) {
      sign = -1;
      return true;
    }
  }
  Msg::Error("Could not get edge information for element %lu", getNum());
  return false;
}

MFaceN MElement::getHighOrderFace(int num, int sign, int rot)
{
  if(getDim() < 2 || getDim() > 3) {
    Msg::Error("Wrong dimension for getHighOrderFace");
    return MFaceN();
  }

  if(getDim() == 2) {
    std::vector<MVertex *> vertices(getNumVertices());
    getVertices(vertices);
    return MFaceN(getType(), getPolynomialOrder(), vertices);
  }

  const nodalBasis *fs = getFunctionSpace();
  int id = fs->getClosureId(num, sign, rot);
  const std::vector<int> &closure = fs->getClosure(id);

  std::vector<MVertex *> vertices(closure.size());
  for(std::size_t i = 0; i < closure.size(); ++i) {
    vertices[i] = getVertex(closure[i]);
  }

  static int type2numTriFaces[9] = {0, 0, 0, 1, 0, 4, 4, 2, 0};
  int typeFace = TYPE_TRI;
  if(num >= type2numTriFaces[getType()]) typeFace = TYPE_QUA;

  return MFaceN(typeFace, getPolynomialOrder(), vertices);
}

double MElement::minEdge()
{
  double m = 1.e25;
  for(int i = 0; i < getNumEdges(); i++) {
    MEdge e = getEdge(i);
    m = std::min(m, e.getVertex(0)->distance(e.getVertex(1)));
  }
  return m;
}

double MElement::maxEdge()
{
  double m = 0.;
  for(int i = 0; i < getNumEdges(); i++) {
    MEdge e = getEdge(i);
    m = std::max(m, e.getVertex(0)->distance(e.getVertex(1)));
  }
  return m;
}

double MElement::maxDistToStraight() const
{
  const nodalBasis *lagBasis = getFunctionSpace();
  const fullMatrix<double> &uvw = lagBasis->points;
  const int &nV = uvw.size1();
  const int &dim = uvw.size2();
  const nodalBasis *lagBasis1 = getFunctionSpace(1);
  const int &nV1 = lagBasis1->points.size1();
  std::vector<SPoint3> xyz1(nV1);
  for(int iV = 0; iV < nV1; ++iV) xyz1[iV] = getVertex(iV)->point();
  double maxdx = 0.;
  for(int iV = nV1; iV < nV; ++iV) {
    double f[256];
    lagBasis1->f(uvw(iV, 0), (dim > 1) ? uvw(iV, 1) : 0.,
                 (dim > 2) ? uvw(iV, 2) : 0., f);
    SPoint3 xyzS(0., 0., 0.);
    for(int iSF = 0; iSF < nV1; ++iSF) xyzS += xyz1[iSF] * f[iSF];
    SVector3 vec(xyzS, getVertex(iV)->point());
    double dx = vec.norm();
    if(dx > maxdx) maxdx = dx;
  }
  return maxdx;
}

double MElement::minIsotropyMeasure(bool knownValid, bool reversedOK)
{
#if defined(HAVE_MESH)
  return jacobianBasedQuality::minICNMeasure(this, knownValid, reversedOK);
#else
  return 0.;
#endif
}

double MElement::minScaledJacobian(bool knownValid, bool reversedOK)
{
#if defined(HAVE_MESH)
  return jacobianBasedQuality::minIGEMeasure(this, knownValid, reversedOK);
#else
  return 0.;
#endif
}

void MElement::scaledJacRange(double &jmin, double &jmax, GEntity *ge) const
{
  jmin = jmax = 1.0;
#if defined(HAVE_MESH)
  const JacobianBasis *jac = getJacobianFuncSpace();
  fullMatrix<double> nodesXYZ(jac->getNumMapNodes(), 3);
  getNodesCoord(nodesXYZ);
  fullVector<double> SJi(jac->getNumSamplingPnts());
  jac->getScaledJacobian(nodesXYZ, SJi);
  if(ge && (ge->dim() == 2) && ge->haveParametrization()) {
    // If parametrized surface entity provided...
    SVector3 geoNorm(0., 0., 0.);
    // ... correct Jacobian sign with geometrical normal
    for(int i = 0; i < jac->getNumPrimMapNodes(); i++) {
      const MVertex *vert = getVertex(i);
      if(vert->onWhat() == ge) {
        double u, v;
        vert->getParameter(0, u);
        vert->getParameter(1, v);
        geoNorm += ((GFace *)ge)->normal(SPoint2(u, v));
      }
    }
    if(geoNorm.normSq() == 0.) {
      // If no vertex on surface or average is zero, take normal at barycenter
      SPoint2 param = ((GFace *)ge)->parFromPoint(barycenter(true), false);
      geoNorm = ((GFace *)ge)->normal(param);
    }
    fullMatrix<double> elNorm(1, 3);
    jac->getPrimNormal2D(nodesXYZ, elNorm);
    const double scal = geoNorm(0) * elNorm(0, 0) + geoNorm(1) * elNorm(0, 1) +
                        geoNorm(2) * elNorm(0, 2);
    if(scal < 0.) SJi.scale(-1.);
  }
  bezierCoeff Bi(jac->getFuncSpaceData(), SJi);
  jmin = *std::min_element(Bi.getDataPtr(), Bi.getDataPtr() + Bi.getNumCoeff());
  jmax = *std::max_element(Bi.getDataPtr(), Bi.getDataPtr() + Bi.getNumCoeff());
#endif
}

void MElement::idealJacRange(double &jmin, double &jmax, GEntity *ge)
{
  jmin = jmax = 1.0;
#if defined(HAVE_MESH)
  const JacobianBasis *jac = getJacobianFuncSpace();
  fullMatrix<double> nodesXYZ(jac->getNumMapNodes(), 3);
  getNodesCoord(nodesXYZ);
  fullVector<double> iJi(jac->getNumSamplingPnts());
  jac->getSignedIdealJacobian(nodesXYZ, iJi);
  const int nEd = getNumEdges(), dim = getDim();
  double sumEdLength = 0.;
  for(int iEd = 0; iEd < nEd; iEd++) sumEdLength += getEdge(iEd).length();
  const double invMeanEdLength = double(nEd) / sumEdLength;
  if(sumEdLength == 0.) {
    jmin = 0.;
    jmax = 0.;
    return;
  }
  double scale =
    (dim == 1.) ? invMeanEdLength :
    (dim == 2.) ? invMeanEdLength * invMeanEdLength :
                  invMeanEdLength * invMeanEdLength * invMeanEdLength;
  if(ge && (ge->dim() == 2) && ge->haveParametrization()) {
    // If parametrized surface entity provided...
    SVector3 geoNorm(0., 0., 0.);
    // ... correct Jacobian sign with geometrical normal
    for(int i = 0; i < jac->getNumPrimMapNodes(); i++) {
      const MVertex *vert = getVertex(i);
      if(vert->onWhat() == ge) {
        double u, v;
        vert->getParameter(0, u);
        vert->getParameter(1, v);
        geoNorm += ((GFace *)ge)->normal(SPoint2(u, v));
      }
    }
    if(geoNorm.normSq() == 0.) {
      // If no vertex on surface or average is zero, take normal at barycenter
      SPoint2 param = ((GFace *)ge)->parFromPoint(barycenter(true), false);
      geoNorm = ((GFace *)ge)->normal(param);
    }
    fullMatrix<double> elNorm(1, 3);
    jac->getPrimNormal2D(nodesXYZ, elNorm, true);
    const double dp = geoNorm(0) * elNorm(0, 0) + geoNorm(1) * elNorm(0, 1) +
                      geoNorm(2) * elNorm(0, 2);
    if(dp < 0.) scale = -scale;
  }
  bezierCoeff Bi(jac->getFuncSpaceData(), iJi);
  jmin = *std::min_element(Bi.getDataPtr(), Bi.getDataPtr() + Bi.getNumCoeff());
  jmax = *std::max_element(Bi.getDataPtr(), Bi.getDataPtr() + Bi.getNumCoeff());
#endif
}

void MElement::signedInvCondNumRange(double &iCNMin, double &iCNMax,
                                     GEntity *ge)
{
  iCNMin = iCNMax = 1.0;
#if defined(HAVE_MESH)
  const CondNumBasis *cnb = BasisFactory::getCondNumBasis(getTypeForMSH());
  const int numCNNodes = cnb->getNumCondNumNodes();
  fullMatrix<double> nodesXYZ(cnb->getNumMapNodes(), 3), normals;
  getNodesCoord(nodesXYZ);
  if(getDim() == 2.) {
    SVector3 nVec = getFace(0).normal();
    normals.resize(1, 3);
    normals(0, 0) = nVec[0];
    normals(0, 1) = nVec[1];
    normals(0, 2) = nVec[2];
  }
  if(ge && (ge->dim() == 2) && ge->haveParametrization()) {
    // If parametrized surface entity provided...
    SVector3 geoNorm(0., 0., 0.);
    // ... correct Jacobian sign with geometrical normal
    for(std::size_t i = 0; i < getNumPrimaryVertices(); i++) {
      const MVertex *vert = getVertex(i);
      if(vert->onWhat() == ge) {
        double u, v;
        vert->getParameter(0, u);
        vert->getParameter(1, v);
        geoNorm += ((GFace *)ge)->normal(SPoint2(u, v));
      }
    }
    if(geoNorm.normSq() == 0.) {
      // If no vertex on surface or average is zero, take normal at barycenter
      SPoint2 param = ((GFace *)ge)->parFromPoint(barycenter(true), false);
      geoNorm = ((GFace *)ge)->normal(param);
    }
    const double dp = geoNorm(0) * normals(0, 0) + geoNorm(1) * normals(0, 1) +
                      geoNorm(2) * normals(0, 2);
    if(dp < 0.) {
      normals(0, 0) = -normals(0, 0);
      normals(0, 1) = -normals(0, 1);
      normals(0, 2) = -normals(0, 2);
    }
  }
  fullVector<double> invCondNum(numCNNodes);
  cnb->getSignedInvCondNum(nodesXYZ, normals, invCondNum);
  iCNMin = *std::min_element(invCondNum.getDataPtr(),
                             invCondNum.getDataPtr() + numCNNodes);
  iCNMax = *std::max_element(invCondNum.getDataPtr(),
                             invCondNum.getDataPtr() + numCNNodes);
#endif
}

void MElement::signedInvGradErrorRange(double &minSIGE, double &maxSIGE)
{
#if defined(HAVE_MESH)
  jacobianBasedQuality::sampleIGEMeasure(this, getPolynomialOrder(), minSIGE,
                                         maxSIGE);
#endif
}

void MElement::getNode(int num, double &u, double &v, double &w) const
{
  // Should we always do this instead of using lookup table for linear elements?
  const nodalBasis *nb = getFunctionSpace();
  const fullMatrix<double> &refpnts = nb->getReferenceNodes();
  u = refpnts(num, 0);
  v = getDim() > 1 ? refpnts(num, 1) : 0;
  w = getDim() > 2 ? refpnts(num, 2) : 0;
}

void MElement::getShapeFunctions(double u, double v, double w, double s[],
                                 int o) const
{
  const nodalBasis *fs = getFunctionSpace(o);
  if(fs)
    fs->f(u, v, w, s);
  else
    Msg::Error("Function space not implemented for this type of element");
}

void MElement::getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int o) const
{
  const nodalBasis *fs = getFunctionSpace(o);
  if(fs)
    fs->df(u, v, w, s);
  else
    Msg::Error("Function space not implemented for this type of element");
}

void MElement::getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int o) const
{
  const nodalBasis *fs = getFunctionSpace(o);
  if(fs)
    fs->ddf(u, v, w, s);
  else
    Msg::Error("Function space not implemented for this type of element");
}

void MElement::getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3],
                                                int o) const
{
  const nodalBasis *fs = getFunctionSpace(o);
  if(fs)
    fs->dddf(u, v, w, s);
  else
    Msg::Error("Function space not implemented for this type of element");
}

SPoint3 MElement::barycenter_infty() const
{
  double xmin = getVertex(0)->x();
  double xmax = xmin;
  double ymin = getVertex(0)->y();
  double ymax = ymin;
  double zmin = getVertex(0)->z();
  double zmax = zmin;
  int n = getNumVertices();
  for(int i = 0; i < n; i++) {
    const MVertex *v = getVertex(i);
    xmin = std::min(xmin, v->x());
    xmax = std::max(xmax, v->x());
    ymin = std::min(ymin, v->y());
    ymax = std::max(ymax, v->y());
    zmin = std::min(zmin, v->z());
    zmax = std::max(zmax, v->z());
  }
  return SPoint3(0.5 * (xmin + xmax), 0.5 * (ymin + ymax), 0.5 * (zmin + zmax));
}

SPoint3 MElement::barycenter(bool primary) const
{
  SPoint3 p(0., 0., 0.);
  std::size_t n = primary ? getNumPrimaryVertices() : getNumVertices();
  for(std::size_t i = 0; i < n; i++) {
    const MVertex *v = getVertex(i);
    p[0] += v->x();
    p[1] += v->y();
    p[2] += v->z();
  }
  p[0] /= (double)n;
  p[1] /= (double)n;
  p[2] /= (double)n;
  return p;
}

SPoint3 MElement::fastBarycenter(bool primary) const
{
  SPoint3 p(0., 0., 0.);
  std::size_t n = primary ? getNumPrimaryVertices() : getNumVertices();
  for(std::size_t i = 0; i < n; i++) {
    const MVertex *v = getVertex(i);
    p[0] += v->x();
    p[1] += v->y();
    p[2] += v->z();
  }

  return p;
}

SPoint3 MElement::barycenterUVW() const
{
  SPoint3 p(0., 0., 0.);
  int n = getNumVertices();
  for(int i = 0; i < n; i++) {
    double x, y, z;
    getNode(i, x, y, z);
    p[0] += x;
    p[1] += y;
    p[2] += z;
  }
  p[0] /= (double)n;
  p[1] /= (double)n;
  p[2] /= (double)n;
  return p;
}

double MElement::getVolume()
{
  int npts;
  IntPt *pts;
  getIntegrationPoints(getPolynomialOrder() + 3, &npts, &pts);
  double vol = 0.;
  for(int i = 0; i < npts; i++) {
    vol += getJacobianDeterminant(pts[i].pt[0], pts[i].pt[1], pts[i].pt[2]) *
           pts[i].weight;
  }
  return vol;
}

int MElement::getVolumeSign()
{
  double v = getVolume();
  if(v < 0.)
    return -1;
  else if(v > 0.)
    return 1;
  else
    return 0;
}

bool MElement::setVolumePositive()
{
  if(getDim() < 3) return true;
  int s = getVolumeSign();
  if(s < 0) reverse();
  if(!s) return false;
  return true;
}

int MElement::getValidity()
{
#if defined(HAVE_MESH)
  double jmin, jmax;
  jacobianBasedQuality::minMaxJacobianDeterminant(this, jmin, jmax);
  if(jmin > .0) return 1; // valid
  if(jmax >= .0) return 0; // invalid
  // Here, jmax < 0 (and jmin < 0). The element validity is quite indeterminate.
  // It can be valid but with a wrong numbering of the nodes,
  // or it can be invalid, i.e. with nodes that are incorrectly located.
  return -1;
#else
  return 0;
#endif
}

std::string MElement::getInfoString(bool multline)
{
  std::ostringstream sstream;
  sstream.precision(12);

  sstream << "Element " << getNum() << ":";
  if(multline) sstream << "\n";

  const char *name;
  MElement::getInfoMSH(getTypeForMSH(), &name);
  sstream << " " << name << " (MSH type " << getTypeForMSH() << ", dimension "
          << getDim() << ", order " << getPolynomialOrder() << ", partition "
          << getPartition() << ")";
  if(multline) sstream << "\n";

  sstream << " Nodes:";
  for(std::size_t i = 0; i < getNumVertices(); i++)
    sstream << " " << getVertex(i)->getNum();
  if(multline) sstream << "\n";

  sstream << " Volume: " << getVolume() << "\n";

  SPoint3 pt = barycenter();
  sstream << " Barycenter: (" << pt[0] << ", " << pt[1] << ", " << pt[2] << ")";
  if(multline) sstream << "\n";

  sstream << " Edge length: "
          << "min = " << minEdge() << " "
          << "max = " << maxEdge();
  if(multline) sstream << "\n";

  sstream << " Quality: "
          << "gamma = " << gammaShapeMeasure();
  if(multline) sstream << "\n";

  double sICNMin, sICNMax;
  signedInvCondNumRange(sICNMin, sICNMax);
  sstream << " SICN range: " << sICNMin << " " << sICNMax;
  if(multline) sstream << "\n";

  double sIGEMin, sIGEMax;
  signedInvGradErrorRange(sIGEMin, sIGEMax);
  sstream << " SIGE range: " << sIGEMin << " " << sIGEMax;
  if(multline) sstream << "\n";

  sstream << " Inner / outer radius: " << getInnerRadius() << " / "
          << getOuterRadius();
  return sstream.str();
}

const nodalBasis *MElement::getFunctionSpace(int order, bool serendip) const
{
  if(order == -1) return BasisFactory::getNodalBasis(getTypeForMSH());
  int type = ElementType::getType(getType(), order, serendip);
  return type ? BasisFactory::getNodalBasis(type) : nullptr;
}

const FuncSpaceData MElement::getFuncSpaceData(int order, bool serendip) const
{
  if(order == -1) return FuncSpaceData(this);
  return FuncSpaceData(this, order, serendip);
}

const JacobianBasis *MElement::getJacobianFuncSpace(int orderElement) const
{
  if(orderElement == -1) return BasisFactory::getJacobianBasis(getTypeForMSH());
  int tag = ElementType::getType(getType(), orderElement);
  return tag ? BasisFactory::getJacobianBasis(tag) : nullptr;
}

const FuncSpaceData MElement::getJacobianFuncSpaceData(int orderElement) const
{
  if(orderElement == -1) orderElement = getPolynomialOrder();
  int orderJac = JacobianBasis::jacobianOrder(this->getType(), orderElement);
  return FuncSpaceData(this, orderJac, false);
}

static double _computeDeterminantAndRegularize(const MElement *ele,
                                               double jac[3][3])
{
  double dJ = 0;

  switch(ele->getDim()) {
  case 0: {
    dJ = 1.0;
    jac[0][0] = jac[1][1] = jac[2][2] = 1.0;
    jac[0][1] = jac[1][0] = jac[2][0] = 0.0;
    jac[0][2] = jac[1][2] = jac[2][1] = 0.0;
    break;
  }
  case 1: {
    dJ = sqrt(SQU(jac[0][0]) + SQU(jac[0][1]) + SQU(jac[0][2]));

    // regularize matrix
    double a[3], b[3], c[3];
    a[0] = jac[0][0];
    a[1] = jac[0][1];
    a[2] = jac[0][2];
    if((fabs(a[0]) >= fabs(a[1]) && fabs(a[0]) >= fabs(a[2])) ||
       (fabs(a[1]) >= fabs(a[0]) && fabs(a[1]) >= fabs(a[2]))) {
      b[0] = a[1];
      b[1] = -a[0];
      b[2] = 0.;
    }
    else {
      b[0] = 0.;
      b[1] = a[2];
      b[2] = -a[1];
    }
    norme(b);
    prodve(a, b, c);
    norme(c);
    jac[1][0] = b[0];
    jac[1][1] = b[1];
    jac[1][2] = b[2];
    jac[2][0] = c[0];
    jac[2][1] = c[1];
    jac[2][2] = c[2];
    break;
  }
  case 2: {
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
    jac[2][0] = c[0];
    jac[2][1] = c[1];
    jac[2][2] = c[2];
    break;
  }
  case 3: {
    dJ =
      (jac[0][0] * jac[1][1] * jac[2][2] + jac[0][2] * jac[1][0] * jac[2][1] +
       jac[0][1] * jac[1][2] * jac[2][0] - jac[0][2] * jac[1][1] * jac[2][0] -
       jac[0][0] * jac[1][2] * jac[2][1] - jac[0][1] * jac[1][0] * jac[2][2]);
    break;
  }
  }
  return dJ;
}

static double _computeDeterminantAndRegularize(const MElement *ele, double *jac)
{
  double dJ = 0;

  // 'jac' is a row-major order array :
  //
  //  |0 1 2|
  //  |3 4 5|
  //  |6 7 8|

  switch(ele->getDim()) {
  case 0: {
    dJ = 1.0;
    jac[0] = jac[4] = jac[8] = 1.0;
    jac[1] = jac[2] = jac[3] = 0.0;
    jac[5] = jac[6] = jac[7] = 0.0;
    break;
  }
  case 1: {
    dJ = sqrt(SQU(jac[0]) + SQU(jac[1]) + SQU(jac[2]));

    // regularize matrix
    double a[3], b[3], c[3];
    a[0] = jac[0];
    a[1] = jac[1];
    a[2] = jac[2];
    if((fabs(a[0]) >= fabs(a[1]) && fabs(a[0]) >= fabs(a[2])) ||
       (fabs(a[1]) >= fabs(a[0]) && fabs(a[1]) >= fabs(a[2]))) {
      b[0] = a[1];
      b[1] = -a[0];
      b[2] = 0.;
    }
    else {
      b[0] = 0.;
      b[1] = a[2];
      b[2] = -a[1];
    }
    norme(b);
    prodve(a, b, c);
    norme(c);
    jac[3] = b[0];
    jac[4] = b[1];
    jac[5] = b[2];
    jac[6] = c[0];
    jac[7] = c[1];
    jac[8] = c[2];
    break;
  }
  case 2: {
    dJ = sqrt(SQU(jac[0] * jac[4] - jac[1] * jac[3]) +
              SQU(jac[2] * jac[3] - jac[0] * jac[5]) +
              SQU(jac[1] * jac[5] - jac[2] * jac[4]));

    // regularize matrix
    double a[3], b[3], c[3];
    a[0] = jac[0];
    a[1] = jac[1];
    a[2] = jac[2];
    b[0] = jac[3];
    b[1] = jac[4];
    b[2] = jac[5];
    prodve(a, b, c);
    norme(c);
    jac[6] = c[0];
    jac[7] = c[1];
    jac[8] = c[2];
    break;
  }
  case 3: {
    dJ = (jac[0] * jac[4] * jac[8] + jac[2] * jac[3] * jac[7] +
          jac[1] * jac[5] * jac[6] - jac[2] * jac[4] * jac[6] -
          jac[0] * jac[5] * jac[7] - jac[1] * jac[3] * jac[8]);
    break;
  }
  }
  return dJ;
}

double MElement::getJacobian(double u, double v, double w,
                             double jac[3][3]) const
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;
  if(getDim() > 3) return 0;

  double gsf[1256][3];
  getGradShapeFunctions(u, v, w, gsf);
  for(std::size_t i = 0; i < getNumShapeFunctions(); i++) {
    const MVertex *ver = getShapeFunctionNode(i);
    double *gg = gsf[i];
    for(int j = 0; j < getDim(); j++) {
      jac[j][0] += ver->x() * gg[j];
      jac[j][1] += ver->y() * gg[j];
      jac[j][2] += ver->z() * gg[j];
    }
  }

  return _computeDeterminantAndRegularize(this, jac);
}

double MElement::getJacobian(const fullMatrix<double> &gsf,
                             double jac[3][3]) const
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;
  if(gsf.size2() > 3) return 0;

  const std::size_t numShapeFunctions = getNumShapeFunctions();
  for(std::size_t i = 0; i < numShapeFunctions; i++) {
    const MVertex *v = getShapeFunctionNode(i);
    for(int j = 0; j < gsf.size2(); j++) {
      jac[j][0] += v->x() * gsf(i, j);
      jac[j][1] += v->y() * gsf(i, j);
      jac[j][2] += v->z() * gsf(i, j);
    }
  }
  return _computeDeterminantAndRegularize(this, jac);
}

double MElement::getJacobian(const std::vector<SVector3> &gsf,
                             double jac[3][3]) const
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  const int numShapeFunctions = getNumVertices();
  for(int i = 0; i < numShapeFunctions; i++) {
    const MVertex *v = getShapeFunctionNode(i);
    for(int j = 0; j < 3; j++) {
      const double mult = gsf[i][j];
      jac[j][0] += v->x() * mult;
      jac[j][1] += v->y() * mult;
      jac[j][2] += v->z() * mult;
    }
  }
  return _computeDeterminantAndRegularize(this, jac);
}

double MElement::getJacobian(const std::vector<SVector3> &gsf,
                             double *jac) const
{
  for(std::size_t i = 0; i < 9; i++) { jac[i] = 0.; }

  const int numShapeFunctions = getNumVertices();
  for(int i = 0; i < numShapeFunctions; i++) {
    const MVertex *v = getShapeFunctionNode(i);
    for(int j = 0; j < 3; j++) {
      const double mult = gsf[i][j];
      jac[3 * j + 0] += v->x() * mult;
      jac[3 * j + 1] += v->y() * mult;
      jac[3 * j + 2] += v->z() * mult;
    }
  }
  return _computeDeterminantAndRegularize(this, jac);
}

double MElement::getJacobian(double u, double v, double w,
                             fullMatrix<double> &j) const
{
  double JAC[3][3];
  const double detJ = getJacobian(u, v, w, JAC);
  for(int i = 0; i < 3; i++) {
    j(i, 0) = JAC[i][0];
    j(i, 1) = JAC[i][1];
    j(i, 2) = JAC[i][2];
  }
  return detJ;
}

double MElement::getPrimaryJacobian(double u, double v, double w,
                                    double jac[3][3]) const
{
  jac[0][0] = jac[0][1] = jac[0][2] = 0.;
  jac[1][0] = jac[1][1] = jac[1][2] = 0.;
  jac[2][0] = jac[2][1] = jac[2][2] = 0.;

  double gsf[1256][3];
  getGradShapeFunctions(u, v, w, gsf, 1);
  for(std::size_t i = 0; i < getNumPrimaryShapeFunctions(); i++) {
    const MVertex *v = getShapeFunctionNode(i);
    double *gg = gsf[i];
    for(std::size_t j = 0; j < 3; j++) {
      jac[j][0] += v->x() * gg[j];
      jac[j][1] += v->y() * gg[j];
      jac[j][2] += v->z() * gg[j];
    }
  }

  return _computeDeterminantAndRegularize(this, jac);
}

void MElement::getSignedJacobian(fullVector<double> &jacobian, int o) const
{
  const int numNodes = getNumVertices();
  fullMatrix<double> nodesXYZ(numNodes, 3);
  getNodesCoord(nodesXYZ);
  getJacobianFuncSpace(o)->getSignedJacobian(nodesXYZ, jacobian);
}

void MElement::getNodesCoord(fullMatrix<double> &nodesXYZ) const
{
  const int numNodes = getNumVertices();
  for(int i = 0; i < numNodes; i++) {
    const MVertex *v = getShapeFunctionNode(i);
    nodesXYZ(i, 0) = v->x();
    nodesXYZ(i, 1) = v->y();
    nodesXYZ(i, 2) = v->z();
  }
}

void MElement::getNodesCoordNonSerendip(fullMatrix<double> &nodesXYZ) const
{
  int tag = ElementType::getType(getType(), getPolynomialOrder(), false);
  const nodalBasis *basis = BasisFactory::getNodalBasis(tag);
  const fullMatrix<double> nodesUVW = basis->getReferenceNodes();
  nodesXYZ.resize(nodesUVW.size1(), 3, false);

  getNodesCoord(nodesXYZ);

  double xyz[3];
  for(int i = getNumVertices(); i < nodesUVW.size1(); ++i) {
    pnt(nodesUVW(i, 0), nodesUVW(i, 1), nodesUVW(i, 2), xyz);
    nodesXYZ(i, 0) = xyz[0];
    nodesXYZ(i, 1) = xyz[1];
    nodesXYZ(i, 2) = xyz[2];
  }
}

bezierCoeff *MElement::getBezierVerticesCoord() const
{
  const bezierBasis *basis;
  basis = BasisFactory::getBezierBasis(getType(), getPolynomialOrder());
  const fullMatrix<double> pntUVW =
    basis->getSamplingPointsToComputeBezierCoeff();

  fullMatrix<double> pntXYZ(pntUVW.size1(), 3);
  double xyz[3];
  double uvw[3];
  for(int i = 0; i < pntUVW.size1(); ++i) {
    uvw[0] = uvw[1] = uvw[2] = 0.;
    for(int j = 0; j < pntUVW.size2(); ++j) {
      uvw[j] = pntUVW(i, j);
    }
    pnt(uvw[0], uvw[1], uvw[2], xyz);
    pntXYZ(i, 0) = xyz[0];
    pntXYZ(i, 1) = xyz[1];
    pntXYZ(i, 2) = xyz[2];
  }

  return new bezierCoeff(getFuncSpaceData(getPolynomialOrder(), false), pntXYZ);
}

double MElement::getEigenvaluesMetric(double u, double v, double w,
                                      double values[3]) const
{
  double jac[3][3];
  getJacobian(u, v, w, jac);
  GradientBasis::mapFromIdealElement(getType(), jac);

  switch(getDim()) {
  case 1:
    values[0] = 0;
    values[1] = -1;
    values[2] = -1;
    for(int d = 0; d < 3; ++d) values[0] += jac[d][0] * jac[d][0];
    return 1;

  case 2: {
    fullMatrix<double> metric(2, 2);
    for(int i = 0; i < 2; ++i) {
      for(int j = 0; j < 2; ++j) {
        for(int d = 0; d < 3; ++d) metric(i, j) += jac[d][i] * jac[d][j];
      }
    }
    fullVector<double> valReal(values, 2), valImag(2);
    fullMatrix<double> vecLeft(2, 2), vecRight(2, 2);
    metric.eig(valReal, valImag, vecLeft, vecRight, true);
    values[2] = -1;
    return std::sqrt(valReal(0) / valReal(1));
  }

  case 3: {
    fullMatrix<double> metric(3, 3);
    for(int i = 0; i < 3; ++i) {
      for(int j = 0; j < 3; ++j) {
        for(int d = 0; d < 3; ++d) metric(i, j) += jac[d][i] * jac[d][j];
      }
    }

    fullVector<double> valReal(values, 3), valImag(3);
    fullMatrix<double> vecLeft(3, 3), vecRight(3, 3);
    metric.eig(valReal, valImag, vecLeft, vecRight, true);

    return std::sqrt(valReal(0) / valReal(2));
  }

  default:
    Msg::Error("wrong dimension for getEigenvaluesMetric function");
    return -1;
  }
}

void MElement::pnt(double u, double v, double w, SPoint3 &p) const
{
  double x = 0., y = 0., z = 0.;
  double sf[1256];
  getShapeFunctions(u, v, w, sf);
  for(std::size_t j = 0; j < getNumShapeFunctions(); j++) {
    const MVertex *v = getShapeFunctionNode(j);
    x += sf[j] * v->x();
    y += sf[j] * v->y();
    z += sf[j] * v->z();
  }
  p = SPoint3(x, y, z);
}

void MElement::pnt(double u, double v, double w, double *p) const
{
  double x = 0., y = 0., z = 0.;
  double sf[1256];
  getShapeFunctions(u, v, w, sf);
  for(std::size_t j = 0; j < getNumShapeFunctions(); j++) {
    const MVertex *v = getShapeFunctionNode(j);
    x += sf[j] * v->x();
    y += sf[j] * v->y();
    z += sf[j] * v->z();
  }
  p[0] = x;
  p[1] = y;
  p[2] = z;
}

void MElement::pnt(const std::vector<double> &sf, SPoint3 &p) const
{
  double x = 0., y = 0., z = 0.;
  for(std::size_t j = 0; j < getNumShapeFunctions(); j++) {
    const MVertex *v = getShapeFunctionNode(j);
    x += sf[j] * v->x();
    y += sf[j] * v->y();
    z += sf[j] * v->z();
  }
  p = SPoint3(x, y, z);
}

void MElement::primaryPnt(double u, double v, double w, SPoint3 &p)
{
  double x = 0., y = 0., z = 0.;
  double sf[1256];
  getShapeFunctions(u, v, w, sf, 1);
  for(std::size_t j = 0; j < getNumPrimaryShapeFunctions(); j++) {
    const MVertex *v = getShapeFunctionNode(j);
    x += sf[j] * v->x();
    y += sf[j] * v->y();
    z += sf[j] * v->z();
  }
  p = SPoint3(x, y, z);
}

void MElement::xyz2uvw(double xyz[3], double uvw[3]) const
{
  // general Newton routine for the nonlinear case (more efficient
  // routines are implemented for simplices, where the basis functions
  // are linear)
  uvw[0] = uvw[1] = uvw[2] = 0.;

  // For high order elements, start from the nearer point
  if(getPolynomialOrder() > 2) {
    int numNearer = 0;
    const MVertex *v = getShapeFunctionNode(0);
    double distNearer = (v->x() - xyz[0]) * (v->x() - xyz[0]) +
                        (v->y() - xyz[1]) * (v->y() - xyz[1]) +
                        (v->z() - xyz[2]) * (v->z() - xyz[2]);
    for(std::size_t i = 1; i < getNumShapeFunctions(); i++) {
      const MVertex *v = getShapeFunctionNode(i);
      double dist = (v->x() - xyz[0]) * (v->x() - xyz[0]) +
                    (v->y() - xyz[1]) * (v->y() - xyz[1]) +
                    (v->z() - xyz[2]) * (v->z() - xyz[2]);
      if(dist < distNearer) {
        numNearer = i;
        distNearer = dist;
      }
    }
    const nodalBasis *nb = getFunctionSpace();
    fullMatrix<double> refpnts = nb->getReferenceNodes();
    for(int i = 0; i < getDim(); i++) { uvw[i] = refpnts(numNearer, i); }
  }

  int iter = 1, maxiter = 20;
  double error = 1., tol = 1.e-6;

  while(error > tol && iter < maxiter) {
    double jac[3][3];
    if(!getJacobian(uvw[0], uvw[1], uvw[2], jac)) break;
    double xn = 0., yn = 0., zn = 0.;
    double sf[1256];
    getShapeFunctions(uvw[0], uvw[1], uvw[2], sf);
    for(std::size_t i = 0; i < getNumShapeFunctions(); i++) {
      const MVertex *v = getShapeFunctionNode(i);
      xn += v->x() * sf[i];
      yn += v->y() * sf[i];
      zn += v->z() * sf[i];
    }
    double inv[3][3];
    inv3x3(jac, inv);
    double un = uvw[0] + inv[0][0] * (xyz[0] - xn) + inv[1][0] * (xyz[1] - yn) +
                inv[2][0] * (xyz[2] - zn);
    double vn = uvw[1] + inv[0][1] * (xyz[0] - xn) + inv[1][1] * (xyz[1] - yn) +
                inv[2][1] * (xyz[2] - zn);
    double wn = uvw[2] + inv[0][2] * (xyz[0] - xn) + inv[1][2] * (xyz[1] - yn) +
                inv[2][2] * (xyz[2] - zn);
    error = sqrt(SQU(un - uvw[0]) + SQU(vn - uvw[1]) + SQU(wn - uvw[2]));
    uvw[0] = un;
    uvw[1] = vn;
    uvw[2] = wn;
    iter++;
  }
}

void MElement::movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const
{
  if(!getParent()) return;
  SPoint3 p;
  getParent()->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwE[3];
  xyz2uvw(xyz, uvwE);
  u = uvwE[0];
  v = uvwE[1];
  w = uvwE[2];
}

void MElement::movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const
{
  if(!getParent()) return;
  SPoint3 p;
  pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwP[3];
  getParent()->xyz2uvw(xyz, uvwP);
  u = uvwP[0];
  v = uvwP[1];
  w = uvwP[2];
}

double MElement::interpolate(double val[], double u, double v, double w,
                             int stride, int order)
{
  double sum = 0;
  int j = 0;
  double sf[1256];
  getShapeFunctions(u, v, w, sf, order);
  for(std::size_t i = 0; i < getNumShapeFunctions(); i++) {
    sum += val[j] * sf[i];
    j += stride;
  }
  return sum;
}

void MElement::interpolateGrad(double val[], double u, double v, double w,
                               double f[], int stride, double invjac[3][3],
                               int order)
{
  double dfdu[3] = {0., 0., 0.};
  int j = 0;
  double gsf[1256][3];
  getGradShapeFunctions(u, v, w, gsf, order);
  for(std::size_t i = 0; i < getNumShapeFunctions(); i++) {
    dfdu[0] += val[j] * gsf[i][0];
    dfdu[1] += val[j] * gsf[i][1];
    dfdu[2] += val[j] * gsf[i][2];
    j += stride;
  }
  if(invjac) { matvec(invjac, dfdu, f); }
  else {
    double jac[3][3], inv[3][3];
    getJacobian(u, v, w, jac);
    inv3x3(jac, inv);
    matvec(inv, dfdu, f);
  }
}

void MElement::interpolateCurl(double val[], double u, double v, double w,
                               double f[], int stride, int order)
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

double MElement::integrate(double val[], int pOrder, int stride, int order)
{
  int npts;
  IntPt *gp;
  getIntegrationPoints(pOrder, &npts, &gp);
  double sum = 0;
  for(int i = 0; i < npts; i++) {
    double u = gp[i].pt[0];
    double v = gp[i].pt[1];
    double w = gp[i].pt[2];
    double weight = gp[i].weight;
    double detuvw = getJacobianDeterminant(u, v, w);
    sum += interpolate(val, u, v, w, stride, order) * weight * detuvw;
  }
  return sum;
}

double MElement::integrateCirc(double val[], int edge, int pOrder, int order)
{
  if(edge > getNumEdges() - 1) {
    Msg::Error("No edge %d for this element", edge);
    return 0;
  }

  std::vector<MVertex *> v;
  getEdgeVertices(edge, v);
  MElementFactory f;
  int type = ElementType::getType(TYPE_LIN, getPolynomialOrder());
  MElement *ee = f.create(type, v);

  double intv[3];
  for(int i = 0; i < 3; i++) {
    intv[i] = ee->integrate(&val[i], pOrder, 3, order);
  }
  delete ee;

  double t[3] = {v[1]->x() - v[0]->x(), v[1]->y() - v[0]->y(),
                 v[1]->z() - v[0]->z()};
  norme(t);

  return prosca(t, intv);
}

double MElement::integrateFlux(double val[], int face, int pOrder, int order)
{
  if(face > getNumFaces() - 1) {
    Msg::Error("No face %d for this element", face);
    return 0;
  }
  std::vector<MVertex *> v;
  getFaceVertices(face, v);
  MElementFactory f;
  int type = 0;
  switch(getType()) {
  case TYPE_TRI:
  case TYPE_TET:
  case TYPE_QUA:
  case TYPE_HEX:
    type = ElementType::getType(getType(), getPolynomialOrder());
    break;
  case TYPE_PYR:
    if(face < 4)
      type = ElementType::getType(TYPE_TRI, getPolynomialOrder());
    else
      type = ElementType::getType(TYPE_QUA, getPolynomialOrder());
    break;
  case TYPE_PRI:
    if(face < 2)
      type = ElementType::getType(TYPE_TRI, getPolynomialOrder());
    else
      type = ElementType::getType(TYPE_QUA, getPolynomialOrder());
    break;
  default: type = 0; break;
  }
  MElement *fe = f.create(type, v);

  double intv[3];
  for(int i = 0; i < 3; i++) {
    intv[i] = fe->integrate(&val[i], pOrder, 3, order);
  }
  delete fe;

  double n[3];
  normal3points(v[0]->x(), v[0]->y(), v[0]->z(), v[1]->x(), v[1]->y(),
                v[1]->z(), v[2]->x(), v[2]->y(), v[2]->z(), n);

  return prosca(n, intv);
}

void MElement::writeMSH2(FILE *fp, double version, bool binary, int num,
                         int elementary, int physical, int parentNum,
                         int dom1Num, int dom2Num, std::vector<short> *ghosts)
{
  int type = getTypeForMSH();

  if(!type) return;

  int n = getNumVerticesForMSH();
  int par = (parentNum) ? 1 : 0;
  int dom = (dom1Num) ? 2 : 0;
  bool poly = (type == MSH_POLYG_ || type == MSH_POLYH_ || type == MSH_POLYG_B);

  // if polygon loop over children (triangles and tets)
  if(CTX::instance()->mesh.saveTri) {
    if(poly) {
      for(int i = 0; i < getNumChildren(); i++) {
        MElement *t = getChild(i);
        t->writeMSH2(fp, version, binary, num++, elementary, physical, 0, 0, 0,
                     ghosts);
      }
      return;
    }
    if(type == MSH_TRI_B) {
      MTriangle *t = new MTriangle(getVertex(0), getVertex(1), getVertex(2));
      t->writeMSH2(fp, version, binary, num++, elementary, physical, 0, 0, 0,
                   ghosts);
      delete t;
      return;
    }
    if(type == MSH_LIN_B || type == MSH_LIN_C) {
      MLine *l = new MLine(getVertex(0), getVertex(1));
      l->writeMSH2(fp, version, binary, num++, elementary, physical, 0, 0, 0,
                   ghosts);
      delete l;
      return;
    }
  }

  if(CTX::instance()->mesh.preserveNumberingMsh2) num = (int)_num;

  if(!binary) {
    fprintf(fp, "%d %d", num ? num : (int)_num, type);
    if(version < 2.0)
      fprintf(fp, " %d %d %d", abs(physical), elementary, n);
    else if(version < 2.2)
      fprintf(fp, " %d %d %d", abs(physical), elementary, _partition);
    else if(!_partition && !par && !dom)
      fprintf(fp, " %d %d %d", 2 + par + dom, abs(physical), elementary);
    else if(!ghosts)
      fprintf(fp, " %d %d %d 1 %d", 4 + par + dom, abs(physical), elementary,
              _partition);
    else {
      int numGhosts = ghosts->size();
      fprintf(fp, " %d %d %d %d %d", 4 + numGhosts + par + dom, abs(physical),
              elementary, 1 + numGhosts, _partition);
      for(std::size_t i = 0; i < ghosts->size(); i++)
        fprintf(fp, " %d", -(*ghosts)[i]);
    }
    if(version >= 2.0 && par) fprintf(fp, " %d", parentNum);
    if(version >= 2.0 && dom) fprintf(fp, " %d %d", dom1Num, dom2Num);
    if(version >= 2.0 && poly) fprintf(fp, " %d", n);
  }
  else {
    int numTags, numGhosts = 0;
    if(!_partition)
      numTags = 2;
    else if(!ghosts)
      numTags = 4;
    else {
      numGhosts = ghosts->size();
      numTags = 4 + numGhosts;
    }
    numTags += par;
    // we write elements in blobs of single elements; this will lead
    // to suboptimal reads, but it's much simpler when the number of
    // tags change from element to element (third-party codes can
    // still write MSH file optimized for reading speed, by grouping
    // elements with the same number of tags in blobs)
    int blob[60] = {
      type,          1,          numTags,       num ? num : (int)_num,
      abs(physical), elementary, 1 + numGhosts, _partition};
    if(ghosts)
      for(int i = 0; i < numGhosts; i++) blob[8 + i] = -(*ghosts)[i];
    if(par) blob[8 + numGhosts] = parentNum;
    if(poly) Msg::Error("Unable to write polygons/polyhedra in binary files.");
    fwrite(blob, sizeof(int), 4 + numTags, fp);
  }

  if(physical < 0) reverse();

  std::vector<int> verts;
  getVerticesIdForMSH(verts);

  if(!binary) {
    for(int i = 0; i < n; i++) fprintf(fp, " %d", verts[i]);
    fprintf(fp, "\n");
  }
  else {
    fwrite(&verts[0], sizeof(int), n, fp);
  }

  if(physical < 0) reverse();
}

void MElement::writeMSH3(FILE *fp, bool binary, int entity,
                         std::vector<short> *ghosts)
{
  int num = (int)getNum();
  int type = getTypeForMSH();
  if(!type) return;

  std::vector<int> verts;
  getVerticesIdForMSH(verts);

  // FIXME: once we create elements using their own interpretion of data, we
  // should move this also into each element base class
  std::vector<int> data;
  data.insert(data.end(), verts.begin(), verts.end());
  if(getParent()) data.push_back(getParent()->getNum());
  if(getPartition()) {
    if(ghosts) {
      data.push_back(1 + ghosts->size());
      data.push_back(getPartition());
      data.insert(data.end(), ghosts->begin(), ghosts->end());
    }
    else {
      data.push_back(1);
      data.push_back(getPartition());
    }
  }
  int numData = data.size();

  if(!binary) {
    fprintf(fp, "%d %d %d %d", num, type, entity, numData);
    for(int i = 0; i < numData; i++) fprintf(fp, " %d", data[i]);
    fprintf(fp, "\n");
  }
  else {
    fwrite(&num, sizeof(int), 1, fp);
    fwrite(&type, sizeof(int), 1, fp);
    fwrite(&entity, sizeof(int), 1, fp);
    fwrite(&numData, sizeof(int), 1, fp);
    fwrite(&data[0], sizeof(int), numData, fp);
  }
}

void MElement::writePOS(FILE *fp, bool printElementary, bool printElementNumber,
                        bool printSICN, bool printSIGE, bool printGamma,
                        bool printDisto, double scalingFactor, int elementary)
{
  const char *str = getStringForPOS();
  if(!str) return;

  int n = getNumVertices();
  fprintf(fp, "%s(", str);
  for(int i = 0; i < n; i++) {
    if(i) fprintf(fp, ",");
    fprintf(fp, "%g,%g,%g", getVertex(i)->x() * scalingFactor,
            getVertex(i)->y() * scalingFactor,
            getVertex(i)->z() * scalingFactor);
  }
  fprintf(fp, "){");
  bool first = true;
  if(printElementary) {
    for(int i = 0; i < n; i++) {
      if(first)
        first = false;
      else
        fprintf(fp, ",");
      fprintf(fp, "%d", elementary);
    }
  }
  if(printElementNumber) {
    for(int i = 0; i < n; i++) {
      if(first)
        first = false;
      else
        fprintf(fp, ",");
      fprintf(fp, "%lu", getNum());
    }
  }
  if(printSICN) {
    double sICNMin = minSICNShapeMeasure();
    for(int i = 0; i < n; i++) {
      if(first)
        first = false;
      else
        fprintf(fp, ",");
      fprintf(fp, "%g", sICNMin);
    }
  }
  if(printSIGE) {
    double sIGEMin = minSIGEShapeMeasure();
    for(int i = 0; i < n; i++) {
      if(first)
        first = false;
      else
        fprintf(fp, ",");
      fprintf(fp, "%g", sIGEMin);
    }
  }
  if(printGamma) {
    double gamma = gammaShapeMeasure();
    for(int i = 0; i < n; i++) {
      if(first)
        first = false;
      else
        fprintf(fp, ",");
      fprintf(fp, "%g", gamma);
    }
  }
  if(printDisto) {
    double disto = distoShapeMeasure();
    for(int i = 0; i < n; i++) {
      if(first)
        first = false;
      else
        fprintf(fp, ",");
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
  if(!binary) {
    fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
    fprintf(fp, "  outer loop\n");
    for(int j = 0; j < 3; j++)
      fprintf(
        fp, "    vertex %.16g %.16g %.16g\n", getVertex(j)->x() * scalingFactor,
        getVertex(j)->y() * scalingFactor, getVertex(j)->z() * scalingFactor);
    fprintf(fp, "  endloop\n");
    fprintf(fp, "endfacet\n");
    if(getNumVertices() == 4) {
      fprintf(fp, "facet normal %g %g %g\n", n[0], n[1], n[2]);
      fprintf(fp, "  outer loop\n");
      for(int j = 0; j < 3; j++)
        fprintf(fp, "    vertex %.16g %.16g %.16g\n",
                getVertex(qid[j])->x() * scalingFactor,
                getVertex(qid[j])->y() * scalingFactor,
                getVertex(qid[j])->z() * scalingFactor);
      fprintf(fp, "  endloop\n");
      fprintf(fp, "endfacet\n");
    }
  }
  else {
    char data[50];
    float *coords = (float *)data;
    coords[0] = (float)n[0];
    coords[1] = (float)n[1];
    coords[2] = (float)n[2];
    for(int j = 0; j < 3; j++) {
      coords[3 + 3 * j] = (float)(getVertex(j)->x() * scalingFactor);
      coords[3 + 3 * j + 1] = (float)(getVertex(j)->y() * scalingFactor);
      coords[3 + 3 * j + 2] = (float)(getVertex(j)->z() * scalingFactor);
    }
    data[48] = data[49] = 0;
    fwrite(data, sizeof(char), 50, fp);
    if(getNumVertices() == 4) {
      for(int j = 0; j < 3; j++) {
        coords[3 + 3 * j] = (float)(getVertex(qid[j])->x() * scalingFactor);
        coords[3 + 3 * j + 1] = (float)(getVertex(qid[j])->y() * scalingFactor);
        coords[3 + 3 * j + 2] = (float)(getVertex(qid[j])->z() * scalingFactor);
      }
      fwrite(data, sizeof(char), 50, fp);
    }
  }
}

void MElement::writeX3D(FILE *fp, double scalingFactor)
{
  if(getType() != TYPE_TRI && getType() != TYPE_QUA) return;
  int qid[3] = {0, 2, 3};

  for(int j = 0; j < 3; j++)
    fprintf(fp, "%g %g %g\n", getVertex(j)->x() * scalingFactor,
            getVertex(j)->y() * scalingFactor,
            getVertex(j)->z() * scalingFactor);
  if(getNumVertices() == 4) {
    for(int j = 0; j < 3; j++) {
      fprintf(fp, "%g %g %g\n", getVertex(qid[j])->x() * scalingFactor,
              getVertex(qid[j])->y() * scalingFactor,
              getVertex(qid[j])->z() * scalingFactor);
    }
  }
}

void MElement::writePLY2(FILE *fp)
{
  fprintf(fp, "3 ");
  for(std::size_t i = 0; i < getNumVertices(); i++)
    fprintf(fp, " %ld", getVertex(i)->getIndex() - 1);
  fprintf(fp, "\n");
}

void MElement::writeVRML(FILE *fp)
{
  for(std::size_t i = 0; i < getNumVertices(); i++)
    fprintf(fp, "%ld,", getVertex(i)->getIndex() - 1);
  fprintf(fp, "-1,\n");
}

void MElement::writeTOCHNOG(FILE *fp, int num)
{
  const char *str = getStringForTOCHNOG();
  if(!str) return;

  int n = getNumVertices();
  fprintf(fp, "element %d %s ", num, str);
  for(int i = 0; i < n; i++) {
    fprintf(fp, " %ld", getVertexTOCHNOG(i)->getIndex());
  }
  fprintf(fp, "\n");
}

void MElement::writeVTK(FILE *fp, bool binary, bool bigEndian)
{
  if(!getTypeForVTK()) return;

  int n = getNumVertices();
  if(binary) {
    int verts[60];
    verts[0] = n;
    for(int i = 0; i < n; i++)
      verts[i + 1] = (int)getVertexVTK(i)->getIndex() - 1;
    // VTK always expects big endian binary data
    if(!bigEndian) SwapBytes((char *)verts, sizeof(int), n + 1);
    fwrite(verts, sizeof(int), n + 1, fp);
  }
  else {
    fprintf(fp, "%d", n);
    for(int i = 0; i < n; i++)
      fprintf(fp, " %ld", getVertexVTK(i)->getIndex() - 1);
    fprintf(fp, "\n");
  }
}

void MElement::writeMATLAB(FILE *fp, int filetype, int elementary, int physical,
                           bool binary)
{
  // Matlab use the same names as MSH
  if(!getTypeForMSH()) return;
  if(binary) {
    Msg::Warning(
      "Binary format not available for Matlab, saving into ASCII format");
    binary = false;
  }

  // Simple version
  if(filetype == 0) {
    int n = getNumVertices();
    for(int i = 0; i < n; i++)
      fprintf(fp, " %ld", getVertexMATLAB(i)->getIndex());
    fprintf(fp, ";\n");
  }
  // same as load_gmsh2.m
  if(filetype == 1) {
    if(physical < 0) reverse();

    for(std::size_t i = 0; i < getNumVertices(); i++)
      fprintf(fp, " %ld", getVertex(i)->getIndex());
    fprintf(fp, " %d\n", physical ? abs(physical) : elementary);

    if(physical < 0) reverse();
  }
}

void MElement::writeUNV(FILE *fp, int num, int elementary, int physical)
{
  int type = getTypeForUNV();
  if(!type) return;

  int n = getNumVertices();
  int physical_property = elementary;
  int material_property = abs(physical);
  int color = 7;
  fprintf(fp, "%10d%10d%10d%10d%10d%10d\n", num ? num : (int)_num, type,
          physical_property, material_property, color, n);
  if(type == 21 || type == 24) // linear beam or parabolic beam
    fprintf(fp, "%10d%10d%10d\n", 0, 0, 0);

  if(physical < 0) reverse();

  for(int k = 0; k < n; k++) {
    fprintf(fp, "%10ld", getVertexUNV(k)->getIndex());
    if(k % 8 == 7) fprintf(fp, "\n");
  }
  if(n - 1 % 8 != 7) fprintf(fp, "\n");

  if(physical < 0) reverse();
}

void MElement::writeMESH(FILE *fp, int elementTagType, int elementary,
                         int physical)
{
  if(physical < 0) reverse();

  for(std::size_t i = 0; i < getNumVertices(); i++)
    if(getTypeForMSH() == MSH_TET_10 && i == 8)
      fprintf(fp, " %ld", getVertex(9)->getIndex());
    else if(getTypeForMSH() == MSH_TET_10 && i == 9)
      fprintf(fp, " %ld", getVertex(8)->getIndex());
    else
      fprintf(fp, " %ld", getVertex(i)->getIndex());
  fprintf(fp, " %d\n",
          (elementTagType == 3) ? _partition :
          (elementTagType == 2) ? abs(physical) :
                                  elementary);

  if(physical < 0) reverse();
}

void MElement::writeNEU(FILE *fp, unsigned gambitType, int idAdjust, int phys)
{
  if(phys < 0) reverse();

  fprintf(fp, "%8lu %2d %2lu ", _num - idAdjust, gambitType, getNumVertices());
  for(std::size_t i = 0; i < getNumVertices(); ++i) {
    if(i == 7) fprintf(fp, "\n               ");
    fprintf(fp, "%8ld", getVertexNEU(i)->getIndex());
  }
  fprintf(fp, "\n");

  if(phys < 0) reverse();
}

void MElement::writeIR3(FILE *fp, int elementTagType, int num, int elementary,
                        int physical)
{
  if(physical < 0) reverse();

  int numVert = getNumVertices();
  fprintf(fp, "%d %d %d", num,
          (elementTagType == 3) ? _partition :
          (elementTagType == 2) ? abs(physical) :
                                  elementary,
          numVert);
  for(int i = 0; i < numVert; i++)
    fprintf(fp, " %ld", getVertex(i)->getIndex());
  fprintf(fp, "\n");

  if(physical < 0) reverse();
}

void MElement::writeBDF(FILE *fp, int format, int elementTagType,
                        int elementary, int physical)
{
  const char *str = getStringForBDF();
  if(!str) return;

  int n = getNumVertices();
  const char *cont[4] = {"E", "F", "G", "H"};
  int ncont = 0;

  if(physical < 0) reverse();

  int tag = (elementTagType == 3) ? _partition :
            (elementTagType == 2) ? abs(physical) :
                                    elementary;

  if(format == 0) { // free field format
    fprintf(fp, "%s,%lu,%d", str, _num, tag);
    for(int i = 0; i < n; i++) {
      fprintf(fp, ",%ld", getVertexBDF(i)->getIndex());
      if(i != n - 1 && !((i + 3) % 8)) {
        fprintf(fp, ",+%s%lu\n+%s%lu", cont[ncont], _num, cont[ncont], _num);
        ncont++;
      }
    }
    if(n == 2) // CBAR
      fprintf(fp, ",0.,0.,0.");
    fprintf(fp, "\n");
  }
  else if(format == 1) { // small field format
    fprintf(fp, "%-8s%-8lu%-8d", str, _num, tag);
    for(int i = 0; i < n; i++) {
      fprintf(fp, "%-8ld", getVertexBDF(i)->getIndex());
      if(i != n - 1 && !((i + 3) % 8)) {
        fprintf(fp, "+%s%-6lu\n+%s%-6lu", cont[ncont], _num, cont[ncont], _num);
        ncont++;
      }
    }
    if(n == 2) // CBAR
      fprintf(fp, "%-8s%-8s%-8s", "0.", "0.", "0.");
    fprintf(fp, "\n");
  }
  else { // large field format
    fprintf(fp, "%-8s%-8lu%-8d", str, _num, tag);
    for(int i = 0; i < n; i++) {
      fprintf(fp, "%-8ld", getVertexBDF(i)->getIndex());
      if(i != n - 1 && !((i + 3) % 8)) {
        fprintf(fp, "\n        ");
        ncont++;
      }
    }
    if(n == 2) // CBAR
      fprintf(fp, "%-8s%-8s%-8s", "0.", "0.", "0.");
    fprintf(fp, "\n");
  }

  if(physical < 0) reverse();
}

void MElement::writeDIFF(FILE *fp, int num, bool binary, int physical)
{
  const char *str = getStringForDIFF();
  if(!str) return;

  if(physical < 0) reverse();

  int n = getNumVertices();
  if(binary) {
    // TODO
  }
  else {
    fprintf(fp, "%d %s %d ", num, str, abs(physical));
    for(int i = 0; i < n; i++)
      fprintf(fp, " %ld", getVertexDIFF(i)->getIndex());
    fprintf(fp, "\n");
  }

  if(physical < 0) reverse();
}

void MElement::writeINP(FILE *fp, int num)
{
  fprintf(fp, "%d, ", num);
  int n = getNumVertices();
  for(int i = 0; i < n; i++) {
    fprintf(fp, "%ld", getVertexINP(i)->getIndex());
    if(i != n - 1) {
      fprintf(fp, ", ");
      if(i && !((i + 2) % 16)) fprintf(fp, "\n");
    }
  }
  fprintf(fp, "\n");
}

void MElement::writeKEY(FILE *fp, int pid, int num)
{
  fprintf(fp, "%d, %d, ", num, pid);
  int n = getNumVertices();
  int nid[64];
  int i;
  for(i = 0; i < n; i++) nid[i] = (int)getVertexKEY(i)->getIndex();
  if(getDim() == 3) {
    if(n == 4) { /* tet4, repeating n4 */
      nid[7] = nid[6] = nid[5] = nid[4] = nid[3];
    }
    else if(n == 6) { /* penta6, n8=n7 & n4=n3 */
      nid[7] = nid[6] = nid[5];
      nid[5] = nid[4];
    }
    if(n < 8) n = 8;
  }
  else if(getDim() == 2) {
    if(n == 3) { /* 3-node shell */
      nid[3] = nid[2];
      n++;
    }
    else if(n == 6) { /* 6-node shell */
      nid[7] = nid[6] = nid[5];
      nid[5] = nid[4];
      nid[4] = nid[3];
      nid[3] = nid[2];
      n = 8;
    }
  }
  else if(getDim() == 1) {
    if(n == 3) { /* elbow, write the third node on the next line */
      nid[8] = nid[2];
      for(i = 2; i < 8; i++) nid[i] = 0;
      n = 9;
    }
  }
  for(i = 0; i < n; i++) {
    fprintf(fp, "%d", nid[i]);
    if(i != n - 1) {
      fprintf(fp, ", ");
      if(!((i + 2) % 10)) fprintf(fp, "\n");
    }
  }
  fprintf(fp, "\n");
}

void MElement::writeRAD(FILE *fp, int num)
{
  fprintf(fp, "%10d", num);
  int n = getNumVertices();
  int nid[64];
  int i;
  for(i = 0; i < n; i++) nid[i] = (int)getVertexRAD(i)->getIndex();
  if(getDim() == 3) {
    if(n == 4) { /* tet4, repeating n4 */
      n = 4;
    }
    else if(n == 6) { /* penta degenerated hexa, n7=n6 & n8=n5 */
      nid[50] = nid[3];
      nid[51] = nid[0];
      nid[53] = nid[5];
      nid[55] = nid[1];
      nid[0] = nid[50];
      nid[1] = nid[51];
      nid[3] = nid[53];
      nid[5] = nid[55];
      nid[6] = nid[5];
      nid[7] = nid[4];
      n = 8;
//    }
//    else if(n == 8) { n = 8;
    }
    else if (n == 10) {/* tetra 10, id line 1, nodes line2 */
      fprintf(fp, "\n");
      n = 10;
    }
    else if (n == 20) {/* Bric20, id and nodes 1-8 line1, nodes 9-16 line2, nodes 17-20 line3 */
      for(i = 0; i < 8; i++) {
        fprintf(fp, "%10d", nid[i]);
      }
      fprintf(fp, "\n");
      for(i = 8; i < 16; i++) {
        fprintf(fp, "%10d", nid[i]);
      }
      fprintf(fp, "\n");
      for(i = 16; i < 20; i++) {
        fprintf(fp, "%10d", nid[i]);
      }
      fprintf(fp, "\n");
      return;
    }
    else if (n == 27) {/* Bric27 does not exist in Radioss write as Bric20 */
      for(i = 0; i < 8; i++) {
        fprintf(fp, "%10d", nid[i]);
      }
      fprintf(fp, "\n");
      for(i = 8; i < 16; i++) {
        fprintf(fp, "%10d", nid[i]);
      }
      fprintf(fp, "\n");
      for(i = 16; i < 20; i++) {
        fprintf(fp, "%10d", nid[i]);
      }
      fprintf(fp, "\n");
      n = 20;
      return;
    }
  }
  else if(getDim() == 2) {
    if(n == 3) { /* 3-node shell */
      n = 3;
    }
    else if(n == 6) { /* 6-node shell */
      nid[7] = nid[6] = nid[5];
      nid[5] = nid[4];
      nid[4] = nid[3];
      nid[3] = nid[2];
      n = 8;
    }
  }
//  else if(getDim() == 1) {
//    if(n == 3) { /* elbow, write the third node on the next line */
//      nid[8] = nid[2];
//      for(i = 2; i < 8; i++) nid[i] = 0;
//      n = 9;
//    }
//  }
  for(i = 0; i < n; i++) {
    fprintf(fp, "%10d", nid[i]);
  }
  fprintf(fp, "\n");
}

void MElement::writeSU2(FILE *fp, int num)
{
  fprintf(fp, "%d ", getTypeForVTK());
  for(std::size_t i = 0; i < getNumVertices(); i++)
    fprintf(fp, "%ld ", getVertexVTK(i)->getIndex() - 1);
  if(num >= 0)
    fprintf(fp, "%d\n", num);
  else
    fprintf(fp, "\n");
}

unsigned int MElement::getInfoMSH(const int typeMSH, const char **const name)
{
  switch(typeMSH) {
  case MSH_PNT:
    if(name) *name = "Point";
    return 1;
  case MSH_LIN_1:
    if(name) *name = "Line 1";
    return 1;
  case MSH_LIN_2:
    if(name) *name = "Line 2";
    return 2;
  case MSH_LIN_3:
    if(name) *name = "Line 3";
    return 2 + 1;
  case MSH_LIN_4:
    if(name) *name = "Line 4";
    return 2 + 2;
  case MSH_LIN_5:
    if(name) *name = "Line 5";
    return 2 + 3;
  case MSH_LIN_6:
    if(name) *name = "Line 6";
    return 2 + 4;
  case MSH_LIN_7:
    if(name) *name = "Line 7";
    return 2 + 5;
  case MSH_LIN_8:
    if(name) *name = "Line 8";
    return 2 + 6;
  case MSH_LIN_9:
    if(name) *name = "Line 9";
    return 2 + 7;
  case MSH_LIN_10:
    if(name) *name = "Line 10";
    return 2 + 8;
  case MSH_LIN_11:
    if(name) *name = "Line 11";
    return 2 + 9;
  case MSH_LIN_B:
    if(name) *name = "Line Border";
    return 2;
  case MSH_LIN_C:
    if(name) *name = "Line Child";
    return 2;
  case MSH_TRI_1:
    if(name) *name = "Triangle 1";
    return 1;
  case MSH_TRI_3:
    if(name) *name = "Triangle 3";
    return 3;
  case MSH_TRI_6:
    if(name) *name = "Triangle 6";
    return 3 + 3;
  case MSH_TRI_9:
    if(name) *name = "Triangle 9";
    return 3 + 6;
  case MSH_TRI_10:
    if(name) *name = "Triangle 10";
    return 3 + 6 + 1;
  case MSH_TRI_12:
    if(name) *name = "Triangle 12";
    return 3 + 9;
  case MSH_TRI_15:
    if(name) *name = "Triangle 15";
    return 3 + 9 + 3;
  case MSH_TRI_15I:
    if(name) *name = "Triangle 15I";
    return 3 + 12;
  case MSH_TRI_21:
    if(name) *name = "Triangle 21";
    return 3 + 12 + 6;
  case MSH_TRI_28:
    if(name) *name = "Triangle 28";
    return 3 + 15 + 10;
  case MSH_TRI_36:
    if(name) *name = "Triangle 36";
    return 3 + 18 + 15;
  case MSH_TRI_45:
    if(name) *name = "Triangle 45";
    return 3 + 21 + 21;
  case MSH_TRI_55:
    if(name) *name = "Triangle 55";
    return 3 + 24 + 28;
  case MSH_TRI_66:
    if(name) *name = "Triangle 66";
    return 3 + 27 + 36;
  case MSH_TRI_18:
    if(name) *name = "Triangle 18";
    return 3 + 15;
  case MSH_TRI_21I:
    if(name) *name = "Triangle 21I";
    return 3 + 18;
  case MSH_TRI_24:
    if(name) *name = "Triangle 24";
    return 3 + 21;
  case MSH_TRI_27:
    if(name) *name = "Triangle 27";
    return 3 + 24;
  case MSH_TRI_30:
    if(name) *name = "Triangle 30";
    return 3 + 27;
  case MSH_TRI_B:
    if(name) *name = "Triangle Border";
    return 3;
  case MSH_QUA_1:
    if(name) *name = "Quadrilateral 1";
    return 1;
  case MSH_QUA_4:
    if(name) *name = "Quadrilateral 4";
    return 4;
  case MSH_QUA_8:
    if(name) *name = "Quadrilateral 8";
    return 4 + 4;
  case MSH_QUA_9:
    if(name) *name = "Quadrilateral 9";
    return 9;
  case MSH_QUA_16:
    if(name) *name = "Quadrilateral 16";
    return 16;
  case MSH_QUA_25:
    if(name) *name = "Quadrilateral 25";
    return 25;
  case MSH_QUA_36:
    if(name) *name = "Quadrilateral 36";
    return 36;
  case MSH_QUA_49:
    if(name) *name = "Quadrilateral 49";
    return 49;
  case MSH_QUA_64:
    if(name) *name = "Quadrilateral 64";
    return 64;
  case MSH_QUA_81:
    if(name) *name = "Quadrilateral 81";
    return 81;
  case MSH_QUA_100:
    if(name) *name = "Quadrilateral 100";
    return 100;
  case MSH_QUA_121:
    if(name) *name = "Quadrilateral 121";
    return 121;
  case MSH_QUA_12:
    if(name) *name = "Quadrilateral 12";
    return 12;
  case MSH_QUA_16I:
    if(name) *name = "Quadrilateral 16I";
    return 16;
  case MSH_QUA_20:
    if(name) *name = "Quadrilateral 20";
    return 20;
  case MSH_QUA_24:
    if(name) *name = "Quadrilateral 24";
    return 24;
  case MSH_QUA_28:
    if(name) *name = "Quadrilateral 28";
    return 28;
  case MSH_QUA_32:
    if(name) *name = "Quadrilateral 32";
    return 32;
  case MSH_QUA_36I:
    if(name) *name = "Quadrilateral 36I";
    return 36;
  case MSH_QUA_40:
    if(name) *name = "Quadrilateral 40";
    return 40;
  case MSH_POLYG_:
    if(name) *name = "Polygon";
    return 0;
  case MSH_POLYG_B:
    if(name) *name = "Polygon Border";
    return 0;
  case MSH_TET_1:
    if(name) *name = "Tetrahedron 1";
    return 1;
  case MSH_TET_4:
    if(name) *name = "Tetrahedron 4";
    return 4;
  case MSH_TET_10:
    if(name) *name = "Tetrahedron 10";
    return 4 + 6;
  case MSH_TET_20:
    if(name) *name = "Tetrahedron 20";
    return 4 + 12 + 4;
  case MSH_TET_35:
    if(name) *name = "Tetrahedron 35";
    return 4 + 18 + 12 + 1;
  case MSH_TET_56:
    if(name) *name = "Tetrahedron 56";
    return 4 + 24 + 24 + 4;
  case MSH_TET_84:
    if(name) *name = "Tetrahedron 84";
    return (7 * 8 * 9) / 6;
  case MSH_TET_120:
    if(name) *name = "Tetrahedron 120";
    return (8 * 9 * 10) / 6;
  case MSH_TET_165:
    if(name) *name = "Tetrahedron 165";
    return (9 * 10 * 11) / 6;
  case MSH_TET_220:
    if(name) *name = "Tetrahedron 220";
    return (10 * 11 * 12) / 6;
  case MSH_TET_286:
    if(name) *name = "Tetrahedron 286";
    return (11 * 12 * 13) / 6;
  case MSH_TET_16:
    if(name) *name = "Tetrahedron 16";
    return 4 + 6 * 2;
  case MSH_TET_22:
    if(name) *name = "Tetrahedron 22";
    return 4 + 6 * 3;
  case MSH_TET_28:
    if(name) *name = "Tetrahedron 28";
    return 4 + 6 * 4;
  case MSH_TET_34:
    if(name) *name = "Tetrahedron 34";
    return 4 + 6 * 5;
  case MSH_TET_40:
    if(name) *name = "Tetrahedron 40";
    return 4 + 6 * 6;
  case MSH_TET_46:
    if(name) *name = "Tetrahedron 46";
    return 4 + 6 * 7;
  case MSH_TET_52:
    if(name) *name = "Tetrahedron 52";
    return 4 + 6 * 8;
  case MSH_TET_58:
    if(name) *name = "Tetrahedron 58";
    return 4 + 6 * 9;
  case MSH_HEX_1:
    if(name) *name = "Hexahedron 1";
    return 1;
  case MSH_HEX_8:
    if(name) *name = "Hexahedron 8";
    return 8;
  case MSH_HEX_20:
    if(name) *name = "Hexahedron 20";
    return 8 + 12;
  case MSH_HEX_27:
    if(name) *name = "Hexahedron 27";
    return 8 + 12 + 6 + 1;
  case MSH_HEX_64:
    if(name) *name = "Hexahedron 64";
    return 64;
  case MSH_HEX_125:
    if(name) *name = "Hexahedron 125";
    return 125;
  case MSH_HEX_216:
    if(name) *name = "Hexahedron 216";
    return 216;
  case MSH_HEX_343:
    if(name) *name = "Hexahedron 343";
    return 343;
  case MSH_HEX_512:
    if(name) *name = "Hexahedron 512";
    return 512;
  case MSH_HEX_729:
    if(name) *name = "Hexahedron 729";
    return 729;
  case MSH_HEX_1000:
    if(name) *name = "Hexahedron 1000";
    return 1000;
  case MSH_HEX_32:
    if(name) *name = "Hexahedron 32";
    return 8 + 12 * 2;
  case MSH_HEX_44:
    if(name) *name = "Hexahedron 44";
    return 8 + 12 * 3;
  case MSH_HEX_56:
    if(name) *name = "Hexahedron 56";
    return 8 + 12 * 4;
  case MSH_HEX_68:
    if(name) *name = "Hexahedron 68";
    return 8 + 12 * 5;
  case MSH_HEX_80:
    if(name) *name = "Hexahedron 80";
    return 8 + 12 * 6;
  case MSH_HEX_92:
    if(name) *name = "Hexahedron 92";
    return 8 + 12 * 7;
  case MSH_HEX_104:
    if(name) *name = "Hexahedron 104";
    return 8 + 12 * 8;
  case MSH_PRI_1:
    if(name) *name = "Prism 1";
    return 1;
  case MSH_PRI_6:
    if(name) *name = "Prism 6";
    return 6;
  case MSH_PRI_15:
    if(name) *name = "Prism 15";
    return 6 + 9;
  case MSH_PRI_18:
    if(name) *name = "Prism 18";
    return 6 + 9 + 3;
  case MSH_PRI_40:
    if(name) *name = "Prism 40";
    return 6 + 18 + 12 + 2 + 2 * 1;
  case MSH_PRI_75:
    if(name) *name = "Prism 75";
    return 6 + 27 + 27 + 6 + 3 * 3;
  case MSH_PRI_126:
    if(name) *name = "Prism 126";
    return 6 + 36 + 48 + 12 + 4 * 6;
  case MSH_PRI_196:
    if(name) *name = "Prism 196";
    return 6 + 45 + 75 + 20 + 5 * 10;
  case MSH_PRI_288:
    if(name) *name = "Prism 288";
    return 6 + 54 + 108 + 30 + 6 * 15;
  case MSH_PRI_405:
    if(name) *name = "Prism 405";
    return 6 + 63 + 147 + 42 + 7 * 21;
  case MSH_PRI_550:
    if(name) *name = "Prism 550";
    return 6 + 72 + 192 + 56 + 8 * 28;
  case MSH_PRI_24:
    if(name) *name = "Prism 24";
    return 6 + 9 * 2;
  case MSH_PRI_33:
    if(name) *name = "Prism 33";
    return 6 + 9 * 3;
  case MSH_PRI_42:
    if(name) *name = "Prism 42";
    return 6 + 9 * 4;
  case MSH_PRI_51:
    if(name) *name = "Prism 51";
    return 6 + 9 * 5;
  case MSH_PRI_60:
    if(name) *name = "Prism 60";
    return 6 + 9 * 6;
  case MSH_PRI_69:
    if(name) *name = "Prism 69";
    return 6 + 9 * 7;
  case MSH_PRI_78:
    if(name) *name = "Prism 78";
    return 6 + 9 * 8;
  case MSH_PYR_1:
    if(name) *name = "Pyramid 1";
    return 1;
  case MSH_PYR_5:
    if(name) *name = "Pyramid 5";
    return 5;
  case MSH_PYR_13:
    if(name) *name = "Pyramid 13";
    return 5 + 8;
  case MSH_PYR_14:
    if(name) *name = "Pyramid 14";
    return 5 + 8 + 1;
  case MSH_PYR_30:
    if(name) *name = "Pyramid 30";
    return 5 + 8 * 2 + 4 * 1 + 1 * 4 + 1;
  case MSH_PYR_55:
    if(name) *name = "Pyramid 55";
    return 5 + 8 * 3 + 4 * 3 + 1 * 9 + 5;
  case MSH_PYR_91:
    if(name) *name = "Pyramid 91";
    return 5 + 8 * 4 + 4 * 6 + 1 * 16 + 14;
  case MSH_PYR_140:
    if(name) *name = "Pyramid 140";
    return 5 + 8 * 5 + 4 * 10 + 1 * 25 + 30;
  case MSH_PYR_204:
    if(name) *name = "Pyramid 204";
    return 5 + 8 * 6 + 4 * 15 + 1 * 36 + 55;
  case MSH_PYR_285:
    if(name) *name = "Pyramid 285";
    return 5 + 8 * 7 + 4 * 21 + 1 * 49 + 91;
  case MSH_PYR_385:
    if(name) *name = "Pyramid 385";
    return 5 + 8 * 8 + 4 * 28 + 1 * 64 + 140;
  case MSH_PYR_21:
    if(name) *name = "Pyramid 21";
    return 5 + 8 * 2;
  case MSH_PYR_29:
    if(name) *name = "Pyramid 29";
    return 5 + 8 * 3;
  case MSH_PYR_37:
    if(name) *name = "Pyramid 37";
    return 5 + 8 * 4;
  case MSH_PYR_45:
    if(name) *name = "Pyramid 45";
    return 5 + 8 * 5;
  case MSH_PYR_53:
    if(name) *name = "Pyramid 53";
    return 5 + 8 * 6;
  case MSH_PYR_61:
    if(name) *name = "Pyramid 61";
    return 5 + 8 * 7;
  case MSH_PYR_69:
    if(name) *name = "Pyramid 69";
    return 5 + 8 * 8;
  case MSH_TRIH_4:
    if(name) *name = "Trihedron 4";
    return 4;
  case MSH_POLYH_:
    if(name) *name = "Polyhedron";
    return 0;
  case MSH_PNT_SUB:
    if(name) *name = "Point Xfem";
    return 1;
  case MSH_LIN_SUB:
    if(name) *name = "Line Xfem";
    return 2;
  case MSH_TRI_SUB:
    if(name) *name = "Triangle Xfem";
    return 3;
  case MSH_TET_SUB:
    if(name) *name = "Tetrahedron Xfem";
    return 4;
  default:
    Msg::Error("Unknown type of element %d", typeMSH);
    if(name) *name = "Unknown";
    return -1;
  }
}

std::string MElement::getName()
{
  const char *name;
  MElement::getInfoMSH(getTypeForMSH(), &name);
  return name;
}

void MElement::getVerticesIdForMSH(std::vector<int> &verts)
{
  int n = getNumVerticesForMSH();
  verts.resize(n);
  for(int i = 0; i < n; i++) verts[i] = (int)getVertex(i)->getIndex();
}

MElement *MElement::copy(std::map<std::size_t, MVertex *> &vertexMap,
                         std::map<MElement *, MElement *> &newParents,
                         std::map<MElement *, MElement *> &newDomains)
{
  if(newDomains.count(this)) return newDomains.find(this)->second;
  std::vector<MVertex *> vmv;
  int eType = getTypeForMSH();
  MElement *eParent = getParent();
  if(getNumChildren() == 0) {
    for(std::size_t i = 0; i < getNumVertices(); i++) {
      MVertex *v = getVertex(i);
      std::size_t numV = v->getNum();
      if(vertexMap.count(numV))
        vmv.push_back(vertexMap[numV]);
      else {
        MVertex *mv = new MVertex(v->x(), v->y(), v->z(), nullptr, numV);
        vmv.push_back(mv);
        vertexMap[numV] = mv;
      }
    }
  }
  else {
    for(int i = 0; i < getNumChildren(); i++) {
      for(std::size_t j = 0; j < getChild(i)->getNumVertices(); j++) {
        MVertex *v = getChild(i)->getVertex(j);
        std::size_t numV = v->getNum();
        if(vertexMap.count(numV))
          vmv.push_back(vertexMap[numV]);
        else {
          MVertex *mv = new MVertex(v->x(), v->y(), v->z(), nullptr, numV);
          vmv.push_back(mv);
          vertexMap[numV] = mv;
        }
      }
    }
  }

  MElement *parent = nullptr;
  if(eParent && !getDomain(0) && !getDomain(1)) {
    auto it = newParents.find(eParent);
    MElement *newParent;
    if(it == newParents.end()) {
      newParent = eParent->copy(vertexMap, newParents, newDomains);
      newParents[eParent] = newParent;
    }
    else
      newParent = it->second;
    parent = newParent;
  }

  MElementFactory f;
  MElement *newEl =
    f.create(eType, vmv, getNum(), _partition, ownsParent(), 0, parent);

  for(int i = 0; i < 2; i++) {
    MElement *dom = getDomain(i);
    if(!dom) continue;
    auto it = newDomains.find(dom);
    MElement *newDom;
    if(it == newDomains.end()) {
      newDom = dom->copy(vertexMap, newParents, newDomains);
      newDomains[dom] = newDom;
    }
    else
      newDom = newDomains.find(dom)->second;
    newEl->setDomain(newDom, i);
  }
  return newEl;
}

MElement *MElementFactory::create(int type, std::vector<MVertex *> &v,
                                  std::size_t num, int part, bool owner,
                                  int parent, MElement *parent_ptr,
                                  MElement *d1, MElement *d2)
{
  switch(type) {
  case MSH_PNT: return new MPoint(v, num, part);
  case MSH_LIN_2: return new MLine(v, num, part);
  case MSH_LIN_3: return new MLine3(v, num, part);
  case MSH_LIN_4: return new MLineN(v, num, part);
  case MSH_LIN_5: return new MLineN(v, num, part);
  case MSH_LIN_6: return new MLineN(v, num, part);
  case MSH_LIN_7: return new MLineN(v, num, part);
  case MSH_LIN_8: return new MLineN(v, num, part);
  case MSH_LIN_9: return new MLineN(v, num, part);
  case MSH_LIN_10: return new MLineN(v, num, part);
  case MSH_LIN_11: return new MLineN(v, num, part);
  case MSH_LIN_B: return new MLineBorder(v, num, part, d1, d2);
  case MSH_LIN_C: return new MLineChild(v, num, part, owner, parent_ptr);
  case MSH_TRI_3: return new MTriangle(v, num, part);
  case MSH_TRI_6: return new MTriangle6(v, num, part);
  case MSH_TRI_10: return new MTriangleN(v, 3, num, part);
  case MSH_TRI_15: return new MTriangleN(v, 4, num, part);
  case MSH_TRI_21: return new MTriangleN(v, 5, num, part);
  case MSH_TRI_28: return new MTriangleN(v, 6, num, part);
  case MSH_TRI_36: return new MTriangleN(v, 7, num, part);
  case MSH_TRI_45: return new MTriangleN(v, 8, num, part);
  case MSH_TRI_55: return new MTriangleN(v, 9, num, part);
  case MSH_TRI_66: return new MTriangleN(v, 10, num, part);
  case MSH_TRI_9: return new MTriangleN(v, 3, num, part);
  case MSH_TRI_12: return new MTriangleN(v, 4, num, part);
  case MSH_TRI_15I: return new MTriangleN(v, 5, num, part);
  case MSH_TRI_18: return new MTriangleN(v, 6, num, part);
  case MSH_TRI_21I: return new MTriangleN(v, 7, num, part);
  case MSH_TRI_24: return new MTriangleN(v, 8, num, part);
  case MSH_TRI_27: return new MTriangleN(v, 9, num, part);
  case MSH_TRI_30: return new MTriangleN(v, 10, num, part);
  case MSH_TRI_B: return new MTriangleBorder(v, num, part, d1, d2);
  case MSH_QUA_4: return new MQuadrangle(v, num, part);
  case MSH_QUA_9: return new MQuadrangle9(v, num, part);
  case MSH_QUA_16: return new MQuadrangleN(v, 3, num, part);
  case MSH_QUA_25: return new MQuadrangleN(v, 4, num, part);
  case MSH_QUA_36: return new MQuadrangleN(v, 5, num, part);
  case MSH_QUA_49: return new MQuadrangleN(v, 6, num, part);
  case MSH_QUA_64: return new MQuadrangleN(v, 7, num, part);
  case MSH_QUA_81: return new MQuadrangleN(v, 8, num, part);
  case MSH_QUA_100: return new MQuadrangleN(v, 9, num, part);
  case MSH_QUA_121: return new MQuadrangleN(v, 10, num, part);
  case MSH_QUA_8: return new MQuadrangle8(v, num, part);
  case MSH_QUA_12: return new MQuadrangleN(v, 3, num, part);
  case MSH_QUA_16I: return new MQuadrangleN(v, 4, num, part);
  case MSH_QUA_20: return new MQuadrangleN(v, 5, num, part);
  case MSH_QUA_24: return new MQuadrangleN(v, 6, num, part);
  case MSH_QUA_28: return new MQuadrangleN(v, 7, num, part);
  case MSH_QUA_32: return new MQuadrangleN(v, 8, num, part);
  case MSH_QUA_36I: return new MQuadrangleN(v, 9, num, part);
  case MSH_QUA_40: return new MQuadrangleN(v, 10, num, part);
  case MSH_POLYG_: return new MPolygon(v, num, part, owner, parent_ptr);
  case MSH_POLYG_B: return new MPolygonBorder(v, num, part, d1, d2);
  case MSH_TET_4: return new MTetrahedron(v, num, part);
  case MSH_TET_10: return new MTetrahedron10(v, num, part);
  case MSH_HEX_8: return new MHexahedron(v, num, part);
  case MSH_HEX_20: return new MHexahedron20(v, num, part);
  case MSH_HEX_27: return new MHexahedron27(v, num, part);
  case MSH_PRI_6: return new MPrism(v, num, part);
  case MSH_PRI_15: return new MPrism15(v, num, part);
  case MSH_PRI_18: return new MPrism18(v, num, part);
  case MSH_PRI_40: return new MPrismN(v, 3, num, part);
  case MSH_PRI_75: return new MPrismN(v, 4, num, part);
  case MSH_PRI_126: return new MPrismN(v, 5, num, part);
  case MSH_PRI_196: return new MPrismN(v, 6, num, part);
  case MSH_PRI_288: return new MPrismN(v, 7, num, part);
  case MSH_PRI_405: return new MPrismN(v, 8, num, part);
  case MSH_PRI_550: return new MPrismN(v, 9, num, part);
  case MSH_PRI_24: return new MPrismN(v, 3, num, part);
  case MSH_PRI_33: return new MPrismN(v, 4, num, part);
  case MSH_PRI_42: return new MPrismN(v, 5, num, part);
  case MSH_PRI_51: return new MPrismN(v, 6, num, part);
  case MSH_PRI_60: return new MPrismN(v, 7, num, part);
  case MSH_PRI_69: return new MPrismN(v, 8, num, part);
  case MSH_PRI_78: return new MPrismN(v, 9, num, part);
  case MSH_PRI_1: return new MPrismN(v, 0, num, part);
  case MSH_TET_20: return new MTetrahedronN(v, 3, num, part);
  case MSH_TET_35: return new MTetrahedronN(v, 4, num, part);
  case MSH_TET_56: return new MTetrahedronN(v, 5, num, part);
  case MSH_TET_84: return new MTetrahedronN(v, 6, num, part);
  case MSH_TET_120: return new MTetrahedronN(v, 7, num, part);
  case MSH_TET_165: return new MTetrahedronN(v, 8, num, part);
  case MSH_TET_220: return new MTetrahedronN(v, 9, num, part);
  case MSH_TET_286: return new MTetrahedronN(v, 10, num, part);
  case MSH_TET_16: return new MTetrahedronN(v, 3, num, part);
  case MSH_TET_22: return new MTetrahedronN(v, 4, num, part);
  case MSH_TET_28: return new MTetrahedronN(v, 5, num, part);
  case MSH_TET_34: return new MTetrahedronN(v, 6, num, part);
  case MSH_TET_40: return new MTetrahedronN(v, 7, num, part);
  case MSH_TET_46: return new MTetrahedronN(v, 8, num, part);
  case MSH_TET_52: return new MTetrahedronN(v, 9, num, part);
  case MSH_TET_58: return new MTetrahedronN(v, 10, num, part);
  case MSH_POLYH_: return new MPolyhedron(v, num, part, owner, parent_ptr);
  case MSH_HEX_32: return new MHexahedronN(v, 3, num, part);
  case MSH_HEX_64: return new MHexahedronN(v, 3, num, part);
  case MSH_HEX_125: return new MHexahedronN(v, 4, num, part);
  case MSH_HEX_216: return new MHexahedronN(v, 5, num, part);
  case MSH_HEX_343: return new MHexahedronN(v, 6, num, part);
  case MSH_HEX_512: return new MHexahedronN(v, 7, num, part);
  case MSH_HEX_729: return new MHexahedronN(v, 8, num, part);
  case MSH_HEX_1000: return new MHexahedronN(v, 9, num, part);
  case MSH_PNT_SUB:
    return (parent_ptr) ? new MSubPoint(v, num, part, owner, parent_ptr) :
                          new MSubPoint(v, num, part, owner, parent);
  case MSH_LIN_SUB:
    return (parent_ptr) ? new MSubLine(v, num, part, owner, parent_ptr) :
                          new MSubLine(v, num, part, owner, parent);
  case MSH_TRI_SUB:
    return (parent_ptr) ? new MSubTriangle(v, num, part, owner, parent_ptr) :
                          new MSubTriangle(v, num, part, owner, parent);
  case MSH_TET_SUB:
    return (parent_ptr) ? new MSubTetrahedron(v, num, part, owner, parent_ptr) :
                          new MSubTetrahedron(v, num, part, owner, parent);
  case MSH_PYR_5: return new MPyramid(v, num, part);
  case MSH_PYR_13: return new MPyramidN(v, 2, num, part);
  case MSH_PYR_14: return new MPyramidN(v, 2, num, part);
  case MSH_PYR_30: return new MPyramidN(v, 3, num, part);
  case MSH_PYR_55: return new MPyramidN(v, 4, num, part);
  case MSH_PYR_91: return new MPyramidN(v, 5, num, part);
  case MSH_PYR_140: return new MPyramidN(v, 6, num, part);
  case MSH_PYR_204: return new MPyramidN(v, 7, num, part);
  case MSH_PYR_285: return new MPyramidN(v, 8, num, part);
  case MSH_PYR_385: return new MPyramidN(v, 9, num, part);
  case MSH_TRIH_4: return new MTrihedron(v, num, part);
  default: return nullptr;
  }
}

MElement *MElementFactory::create(int num, int type,
                                  const std::vector<int> &data, GModel *model)
{
  // This should be rewritten: each element should register itself in a static
  // factory owned e.g. directly by MElement, and interpret its data by
  // itself. This would remove the ugly switch in the routine above.

  int numVertices = MElement::getInfoMSH(type), startVertices = 0;
  if(data.size() && !numVertices) {
    startVertices = 1;
    numVertices = data[0];
  }

  std::vector<MVertex *> vertices(numVertices);
  if((int)data.size() > startVertices + numVertices - 1) {
    for(int i = 0; i < numVertices; i++) {
      int numVertex = data[startVertices + i];
      MVertex *v = model->getMeshVertexByTag(numVertex);
      if(v) { vertices[i] = v; }
      else {
        Msg::Error("Unknown node %d in element %d", numVertex, num);
        return nullptr;
      }
    }
  }
  else {
    Msg::Error("Missing data in element %d", num);
    return nullptr;
  }

  unsigned int part = 0;
  int startPartitions = startVertices + numVertices;

  int parent = 0;
  if((type == MSH_PNT_SUB || type == MSH_LIN_SUB || type == MSH_TRI_SUB ||
      type == MSH_TET_SUB)) {
    parent = data[startPartitions];
    startPartitions += 1;
  }

  std::vector<short> ghosts;
  if((int)data.size() > startPartitions) {
    int numPartitions = data[startPartitions];
    if(numPartitions > 0 &&
       (int)data.size() > startPartitions + numPartitions - 1) {
      part = data[startPartitions + 1];
      for(int i = 1; i < numPartitions; i++)
        ghosts.push_back(data[startPartitions + 1 + i]);
    }
  }

  MElement *element = create(type, vertices, num, part, false, parent);

  //for(std::size_t j = 0; j < ghosts.size(); j++) {
    // model->getGhostCells().insert(std::make_pair(element, ghosts[j]));
  //}
  if(part > model->getNumPartitions()) model->setNumPartitions(part);

  return element;
}

double MElement::skewness()
{
  double minsk = 1.0;
  for(int i = 0; i < getNumFaces(); i++) {
    MFace f = getFace(i);
    if(f.getNumVertices() == 3) {
      // MTriangle t (f.getVertex(0),f.getVertex(1),f.getVertex(2));
      // minsk = std::min(minsk, t.etaShapeMeasure ());
    }
    else if(f.getNumVertices() == 4) {
      MQuadrangle q(f.getVertex(0), f.getVertex(1), f.getVertex(2),
                    f.getVertex(3));
      minsk = std::min(minsk, q.etaShapeMeasure());
    }
  }
  return minsk;
}
