// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Frederic Duboeuf

#include "MSubElement.h"
#include "Numeric.h"
#include "GModel.h"

// MSubTetrahedron

MSubTetrahedron::~MSubTetrahedron()
{
  if(_pts) delete[] _pts;
  if(_base) delete _base;
}

void MSubTetrahedron::updateParent(GModel *gm)
{
  _orig = gm->getMeshElementByTag(_orig_N);
}

const nodalBasis *MSubTetrahedron::getFunctionSpace(int order,
                                                    bool serendip) const
{
  if(_orig) return _orig->getFunctionSpace(order, serendip);
  return nullptr;
}

const JacobianBasis *MSubTetrahedron::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return nullptr;
}

void MSubTetrahedron::getShapeFunctions(double u, double v, double w,
                                        double s[], int order) const
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, order);
}

void MSubTetrahedron::getGradShapeFunctions(double u, double v, double w,
                                            double s[][3], int order) const
{
  if(_orig) _orig->getGradShapeFunctions(u, v, w, s, order);
}

void MSubTetrahedron::getHessShapeFunctions(double u, double v, double w,
                                            double s[][3][3], int order) const
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, order);
}

void MSubTetrahedron::getThirdDerivativeShapeFunctions(double u, double v,
                                                       double w,
                                                       double s[][3][3][3],
                                                       int order) const
{
  if(_orig) _orig->getThirdDerivativeShapeFunctions(u, v, w, s, order);
}

double MSubTetrahedron::getJacobian(const fullMatrix<double> &gsf,
                                    double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubTetrahedron::getJacobian(const std::vector<SVector3> &gsf,
                                    double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubTetrahedron::getJacobian(double u, double v, double w,
                                    double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(u, v, w, jac);
  return 0;
}
double MSubTetrahedron::getPrimaryJacobian(double u, double v, double w,
                                           double jac[3][3]) const
{
  if(_orig) return _orig->getPrimaryJacobian(u, v, w, jac);
  return 0;
}

std::size_t MSubTetrahedron::getNumShapeFunctions() const
{
  if(_orig) return _orig->getNumShapeFunctions();
  return 0;
}

std::size_t MSubTetrahedron::getNumPrimaryShapeFunctions() const
{
  if(_orig) return _orig->getNumPrimaryShapeFunctions();
  return 0;
}

const MVertex *MSubTetrahedron::getShapeFunctionNode(int i) const
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

MVertex *MSubTetrahedron::getShapeFunctionNode(int i)
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

void MSubTetrahedron::xyz2uvw(double xyz[3], double uvw[3]) const
{
  if(_orig) _orig->xyz2uvw(xyz, uvw);
}

void MSubTetrahedron::movePointFromParentSpaceToElementSpace(double &u,
                                                             double &v,
                                                             double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  _orig->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwE[3];
  getBaseElement()->xyz2uvw(xyz, uvwE);
  u = uvwE[0];
  v = uvwE[1];
  w = uvwE[2];
}

void MSubTetrahedron::movePointFromElementSpaceToParentSpace(double &u,
                                                             double &v,
                                                             double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  getBaseElement()->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwP[3];
  _orig->xyz2uvw(xyz, uvwP);
  u = uvwP[0];
  v = uvwP[1];
  w = uvwP[2];
}

bool MSubTetrahedron::isInside(double u, double v, double w) const
{
  if(!_orig) return false;

  if(_orig->getDim() != getDim()) { // projection on the base Element
    SPoint3 p;
    _orig->pnt(u, v, w, p);
    double xyz[3] = {p.x(), p.y(), p.z()};
    double uvwE[3];
    getBaseElement()->xyz2uvw(xyz, uvwE);
    SPoint3 pE;
    getBaseElement()->pnt(uvwE[0], uvwE[1], uvwE[2], pE);
    double tol = _isInsideTolerance;
    if(fabs(p.x() - pE.x()) > tol) return false;
    if(fabs(p.y() - pE.y()) > tol) return false;
    if(fabs(p.z() - pE.z()) > tol) return false;
  }

  movePointFromParentSpaceToElementSpace(u, v, w);
  if(getBaseElement()->isInside(u, v, w)) return true;
  return false;
}

void MSubTetrahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  if(_pts) {
    if(pOrder == _pOrder) {
      *npts = _npts;
      *pts = _pts;
      return;
    }
    else
      delete[] _pts;
  }

  _pOrder = pOrder;

  if(!_orig) {
    getBaseElement()->getIntegrationPoints(pOrder, &_npts, &_pts);
    *npts = _npts;
    *pts = _pts;
    return;
  }

  // work in the parametric space of the parent element
  _pts = new IntPt[getNGQTetPts(pOrder)];

  // (i) get the integration points of the base element in its parametric space
  IntPt *ptsb;
  getBaseElement()->getIntegrationPoints(pOrder, &_npts, &ptsb);

  // (ii) get the coordinates of these points in the parametric space of parent
  // element
  double u, v, w;
  double jac[3][3];
  double baseJac, origJac;
  for(int i = 0; i < _npts; ++i) {
    u = ptsb[i].pt[0];
    v = ptsb[i].pt[1];
    w = ptsb[i].pt[2];
    baseJac = getBaseElement()->getJacobian(u, v, w, jac);

    movePointFromElementSpaceToParentSpace(u, v, w);
    origJac = _orig->getJacobian(u, v, w, jac);

    _pts[i].pt[0] = u;
    _pts[i].pt[1] = v;
    _pts[i].pt[2] = w;
    _pts[i].weight = ptsb[i].weight * baseJac / origJac;
  }
  *npts = _npts;
  *pts = _pts;
}

// MSubTriangle

MSubTriangle::~MSubTriangle()
{
  if(_pts) delete[] _pts;
  if(_base) delete _base;
}

void MSubTriangle::updateParent(GModel *gm)
{
  _orig = gm->getMeshElementByTag(_orig_N);
}

const nodalBasis *MSubTriangle::getFunctionSpace(int order, bool serendip) const
{
  if(_orig) return _orig->getFunctionSpace(order, serendip);
  return nullptr;
}

const JacobianBasis *MSubTriangle::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return nullptr;
}

void MSubTriangle::getShapeFunctions(double u, double v, double w, double s[],
                                     int order) const
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, order);
}

void MSubTriangle::getGradShapeFunctions(double u, double v, double w,
                                         double s[][3], int order) const
{
  if(!_orig) return;

  if(_orig->getDim() == getDim())
    return _orig->getGradShapeFunctions(u, v, w, s, order);

  std::size_t nsf = getNumShapeFunctions();
  double gradsuvw[1256][3];
  _orig->getGradShapeFunctions(u, v, w, gradsuvw, order);

  // work in the parametric space of the parent element
  double jac[3][3];
  double invjac[3][3];
  _orig->getJacobian(u, v, w, jac);
  inv3x3(jac, invjac);

  MEdge edge[2];
  edge[0] = getBaseElement()->getEdge(0);
  edge[1] = getBaseElement()->getEdge(1);
  SVector3 tang[2];
  tang[0] = edge[0].tangent();
  tang[1] = edge[1].tangent();
  SVector3 vect = crossprod(tang[0], tang[1]);
  tang[1] = crossprod(vect, tang[0]);

  double gradxyz[3];
  double projgradxyz[3];
  for(std::size_t i = 0; i < nsf; ++i) {
    // (i) get the cartesian coordinates of the gradient
    gradxyz[0] = invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] +
                 invjac[0][2] * gradsuvw[i][2];
    gradxyz[1] = invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] +
                 invjac[1][2] * gradsuvw[i][2];
    gradxyz[2] = invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] +
                 invjac[2][2] * gradsuvw[i][2];

    // (ii) projection of the gradient on edges in the cartesian space
    SVector3 grad(&gradxyz[0]);
    double prodscal[2];
    prodscal[0] = dot(tang[0], grad);
    prodscal[1] = dot(tang[1], grad);
    projgradxyz[0] = prodscal[0] * tang[0].x() + prodscal[1] * tang[1].x();
    projgradxyz[1] = prodscal[0] * tang[0].y() + prodscal[1] * tang[1].y();
    projgradxyz[2] = prodscal[0] * tang[0].z() + prodscal[1] * tang[1].z();

    // (iii) get the parametric coordinates of the projection in the parametric
    // space of the parent element
    s[i][0] = jac[0][0] * projgradxyz[0] + jac[0][1] * projgradxyz[1] +
              jac[0][2] * projgradxyz[2];
    s[i][1] = jac[1][0] * projgradxyz[0] + jac[1][1] * projgradxyz[1] +
              jac[1][2] * projgradxyz[2];
    s[i][2] = jac[2][0] * projgradxyz[0] + jac[2][1] * projgradxyz[1] +
              jac[2][2] * projgradxyz[2];
  }
}

void MSubTriangle::getHessShapeFunctions(double u, double v, double w,
                                         double s[][3][3], int order) const
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, order);
}

void MSubTriangle::getThirdDerivativeShapeFunctions(double u, double v,
                                                    double w,
                                                    double s[][3][3][3],
                                                    int order) const
{
  if(_orig) _orig->getThirdDerivativeShapeFunctions(u, v, w, s, order);
}

double MSubTriangle::getJacobian(const fullMatrix<double> &gsf,
                                 double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubTriangle::getJacobian(const std::vector<SVector3> &gsf,
                                 double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubTriangle::getJacobian(double u, double v, double w,
                                 double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(u, v, w, jac);
  return 0;
}
double MSubTriangle::getPrimaryJacobian(double u, double v, double w,
                                        double jac[3][3]) const
{
  if(_orig) return _orig->getPrimaryJacobian(u, v, w, jac);
  return 0;
}

std::size_t MSubTriangle::getNumShapeFunctions() const
{
  if(_orig) return _orig->getNumShapeFunctions();
  return 0;
}

std::size_t MSubTriangle::getNumPrimaryShapeFunctions() const
{
  if(_orig) return _orig->getNumPrimaryShapeFunctions();
  return 0;
}

const MVertex *MSubTriangle::getShapeFunctionNode(int i) const
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

MVertex *MSubTriangle::getShapeFunctionNode(int i)
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

void MSubTriangle::xyz2uvw(double xyz[3], double uvw[3]) const
{
  if(_orig) _orig->xyz2uvw(xyz, uvw);
}

void MSubTriangle::movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                          double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  _orig->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwE[3];
  getBaseElement()->xyz2uvw(xyz, uvwE);
  u = uvwE[0];
  v = uvwE[1];
  w = uvwE[2];
}

void MSubTriangle::movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                          double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  getBaseElement()->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwP[3];
  _orig->xyz2uvw(xyz, uvwP);
  u = uvwP[0];
  v = uvwP[1];
  w = uvwP[2];
}

bool MSubTriangle::isInside(double u, double v, double w) const
{
  if(!_orig) return false;

  if(_orig->getDim() != getDim()) { // projection on the base Element
    SPoint3 p;
    _orig->pnt(u, v, w, p);
    double xyz[3] = {p.x(), p.y(), p.z()};
    double uvwE[3];
    getBaseElement()->xyz2uvw(xyz, uvwE);
    SPoint3 pE;
    getBaseElement()->pnt(uvwE[0], uvwE[1], uvwE[2], pE);
    double tol = _isInsideTolerance;
    if(fabs(p.x() - pE.x()) > tol) return false;
    if(fabs(p.y() - pE.y()) > tol) return false;
    if(fabs(p.z() - pE.z()) > tol) return false;
  }

  movePointFromParentSpaceToElementSpace(u, v, w);
  if(getBaseElement()->isInside(u, v, w)) return true;
  return false;
}

void MSubTriangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  if(_pts) {
    if(pOrder == _pOrder) {
      *npts = _npts;
      *pts = _pts;
      return;
    }
    else
      delete[] _pts;
  }

  _pOrder = pOrder;

  if(!_orig) {
    getBaseElement()->getIntegrationPoints(pOrder, &_npts, &_pts);
    *npts = _npts;
    *pts = _pts;
    return;
  }
  // work in the parametric space of the parent element
  _pts = new IntPt[getNGQTPts(pOrder)];

  // (i) get the integration points of the base element in its parametric space
  IntPt *ptsb;
  getBaseElement()->getIntegrationPoints(pOrder, &_npts, &ptsb);

  // (ii) get the coordinates of these points in the parametric space of parent
  // element
  double u, v, w;
  double jac[3][3];
  double baseJac, origJac;
  for(int i = 0; i < _npts; ++i) {
    u = ptsb[i].pt[0];
    v = ptsb[i].pt[1];
    w = ptsb[i].pt[2];
    baseJac = getBaseElement()->getJacobian(u, v, w, jac);

    movePointFromElementSpaceToParentSpace(u, v, w);
    origJac = _orig->getJacobian(u, v, w, jac);

    _pts[i].pt[0] = u;
    _pts[i].pt[1] = v;
    _pts[i].pt[2] = w;
    _pts[i].weight = ptsb[i].weight * baseJac / origJac;
  }
  *npts = _npts;
  *pts = _pts;
}

// MSubLine

MSubLine::~MSubLine()
{
  if(_pts) delete[] _pts;
  if(_base) delete _base;
}

void MSubLine::updateParent(GModel *gm)
{
  _orig = gm->getMeshElementByTag(_orig_N);
}

const nodalBasis *MSubLine::getFunctionSpace(int order, bool serendip) const
{
  if(_orig) return _orig->getFunctionSpace(order, serendip);
  return nullptr;
}

const JacobianBasis *MSubLine::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return nullptr;
}

void MSubLine::getShapeFunctions(double u, double v, double w, double s[],
                                 int order) const
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, order);
}

void MSubLine::getGradShapeFunctions(double u, double v, double w,
                                     double s[][3], int order) const
{
  if(!_orig) return;

  if(_orig->getDim() == getDim())
    return _orig->getGradShapeFunctions(u, v, w, s, order);

  std::size_t nsf = _orig->getNumShapeFunctions();
  double gradsuvw[1256][3];
  _orig->getGradShapeFunctions(u, v, w, gradsuvw, order);

  double jac[3][3];
  double invjac[3][3];
  _orig->getJacobian(u, v, w, jac);
  inv3x3(jac, invjac);
  MEdge edge = getBaseElement()->getEdge(0);
  SVector3 tang = edge.tangent();

  double gradxyz[3];
  double projgradxyz[3];
  for(std::size_t i = 0; i < nsf; ++i) {
    // (i) get the cartesian coordinates of the gradient
    gradxyz[0] = invjac[0][0] * gradsuvw[i][0] + invjac[0][1] * gradsuvw[i][1] +
                 invjac[0][2] * gradsuvw[i][2];
    gradxyz[1] = invjac[1][0] * gradsuvw[i][0] + invjac[1][1] * gradsuvw[i][1] +
                 invjac[1][2] * gradsuvw[i][2];
    gradxyz[2] = invjac[2][0] * gradsuvw[i][0] + invjac[2][1] * gradsuvw[i][1] +
                 invjac[2][2] * gradsuvw[i][2];

    // (ii) projection of the gradient on edges in the cartesian space
    SVector3 grad(&gradxyz[0]);
    double prodscal = dot(tang, grad);
    projgradxyz[0] = prodscal * tang.x();
    projgradxyz[1] = prodscal * tang.y();
    projgradxyz[2] = prodscal * tang.z();

    // (iii) get the parametric coordinates of the projection in the parametric
    // space of the parent element
    s[i][0] = jac[0][0] * projgradxyz[0] + jac[0][1] * projgradxyz[1] +
              jac[0][2] * projgradxyz[2];
    s[i][1] = jac[1][0] * projgradxyz[0] + jac[1][1] * projgradxyz[1] +
              jac[1][2] * projgradxyz[2];
    s[i][2] = jac[2][0] * projgradxyz[0] + jac[2][1] * projgradxyz[1] +
              jac[2][2] * projgradxyz[2];
  }
}

void MSubLine::getHessShapeFunctions(double u, double v, double w,
                                     double s[][3][3], int order) const
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, order);
}

void MSubLine::getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                double s[][3][3][3],
                                                int order) const
{
  if(_orig) _orig->getThirdDerivativeShapeFunctions(u, v, w, s, order);
}

double MSubLine::getJacobian(const fullMatrix<double> &gsf,
                             double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubLine::getJacobian(const std::vector<SVector3> &gsf,
                             double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubLine::getJacobian(double u, double v, double w,
                             double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(u, v, w, jac);
  return 0;
}
double MSubLine::getPrimaryJacobian(double u, double v, double w,
                                    double jac[3][3]) const
{
  if(_orig) return _orig->getPrimaryJacobian(u, v, w, jac);
  return 0;
}

std::size_t MSubLine::getNumShapeFunctions() const
{
  if(_orig) return _orig->getNumShapeFunctions();
  return 0;
}

std::size_t MSubLine::getNumPrimaryShapeFunctions() const
{
  if(_orig) return _orig->getNumPrimaryShapeFunctions();
  return 0;
}

const MVertex *MSubLine::getShapeFunctionNode(int i) const
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

MVertex *MSubLine::getShapeFunctionNode(int i)
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

void MSubLine::xyz2uvw(double xyz[3], double uvw[3]) const
{
  if(_orig) _orig->xyz2uvw(xyz, uvw);
}

void MSubLine::movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                      double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  _orig->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwE[3];
  getBaseElement()->xyz2uvw(xyz, uvwE);
  u = uvwE[0];
  v = uvwE[1];
  w = uvwE[2];
}

void MSubLine::movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                      double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  getBaseElement()->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwP[3];
  _orig->xyz2uvw(xyz, uvwP);
  u = uvwP[0];
  v = uvwP[1];
  w = uvwP[2];
}

bool MSubLine::isInside(double u, double v, double w) const
{
  if(!_orig) return false;

  if(_orig->getDim() != getDim()) { // projection on the base Element
    SPoint3 p;
    _orig->pnt(u, v, w, p);
    double xyz[3] = {p.x(), p.y(), p.z()};
    double uvwE[3];
    getBaseElement()->xyz2uvw(xyz, uvwE);
    SPoint3 pE;
    getBaseElement()->pnt(uvwE[0], uvwE[1], uvwE[2], pE);
    double tol = _isInsideTolerance;
    if(fabs(p.x() - pE.x()) > tol) return false;
    if(fabs(p.y() - pE.y()) > tol) return false;
    if(fabs(p.z() - pE.z()) > tol) return false;
  }

  movePointFromParentSpaceToElementSpace(u, v, w);
  if(getBaseElement()->isInside(u, v, w)) return true;
  return false;
}

void MSubLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  if(_pts) {
    if(pOrder == _pOrder) {
      *npts = _npts;
      *pts = _pts;
      return;
    }
    else
      delete[] _pts;
  }

  _pOrder = pOrder;

  if(!_orig) {
    getBaseElement()->getIntegrationPoints(pOrder, &_npts, &_pts);
    *npts = _npts;
    *pts = _pts;
    return;
  }

  // work in the parametric space of the parent element
  _pts = new IntPt[getNGQLPts(pOrder)];

  // (i) get the integration points of the base element in its parametric space
  IntPt *ptsb;
  getBaseElement()->getIntegrationPoints(pOrder, &_npts, &ptsb);

  // (ii) get the coordinates of these points in the parametric space of parent
  // element
  double u, v, w;
  double jac[3][3];
  double baseJac, origJac;
  for(int i = 0; i < _npts; ++i) {
    u = ptsb[i].pt[0];
    v = ptsb[i].pt[1];
    w = ptsb[i].pt[2];
    baseJac = getBaseElement()->getJacobian(u, v, w, jac);

    movePointFromElementSpaceToParentSpace(u, v, w);
    origJac = _orig->getJacobian(u, v, w, jac);

    _pts[i].pt[0] = u;
    _pts[i].pt[1] = v;
    _pts[i].pt[2] = w;
    _pts[i].weight = ptsb[i].weight * baseJac / origJac;
  }
  *npts = _npts;
  *pts = _pts;
}

// MSubPoint

MSubPoint::~MSubPoint()
{
  if(_pts) delete[] _pts;
  if(_base) delete _base;
}

void MSubPoint::updateParent(GModel *gm)
{
  _orig = gm->getMeshElementByTag(_orig_N);
}

const nodalBasis *MSubPoint::getFunctionSpace(int order, bool serendip) const
{
  if(_orig) return _orig->getFunctionSpace(order, serendip);
  return nullptr;
}

const JacobianBasis *MSubPoint::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return nullptr;
}

void MSubPoint::getShapeFunctions(double u, double v, double w, double s[],
                                  int order) const
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, order);
}

void MSubPoint::getGradShapeFunctions(double u, double v, double w,
                                      double s[][3], int order) const
{
  if(_orig) _orig->getGradShapeFunctions(u, v, w, s, order);
}

void MSubPoint::getHessShapeFunctions(double u, double v, double w,
                                      double s[][3][3], int order) const
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, order);
}

void MSubPoint::getThirdDerivativeShapeFunctions(double u, double v, double w,
                                                 double s[][3][3][3],
                                                 int order) const
{
  if(_orig) _orig->getThirdDerivativeShapeFunctions(u, v, w, s, order);
}

double MSubPoint::getJacobian(const fullMatrix<double> &gsf,
                              double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubPoint::getJacobian(const std::vector<SVector3> &gsf,
                              double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(gsf, jac);
  return 0;
}
double MSubPoint::getJacobian(double u, double v, double w,
                              double jac[3][3]) const
{
  if(_orig) return _orig->getJacobian(u, v, w, jac);
  return 0;
}
double MSubPoint::getPrimaryJacobian(double u, double v, double w,
                                     double jac[3][3]) const
{
  if(_orig) return _orig->getPrimaryJacobian(u, v, w, jac);
  return 0;
}

std::size_t MSubPoint::getNumShapeFunctions() const
{
  if(_orig) return _orig->getNumShapeFunctions();
  return 0;
}

std::size_t MSubPoint::getNumPrimaryShapeFunctions() const
{
  if(_orig) return _orig->getNumPrimaryShapeFunctions();
  return 0;
}

const MVertex *MSubPoint::getShapeFunctionNode(int i) const
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

MVertex *MSubPoint::getShapeFunctionNode(int i)
{
  if(_orig) return _orig->getShapeFunctionNode(i);
  return nullptr;
}

void MSubPoint::xyz2uvw(double xyz[3], double uvw[3]) const
{
  if(_orig) _orig->xyz2uvw(xyz, uvw);
}

void MSubPoint::movePointFromParentSpaceToElementSpace(double &u, double &v,
                                                       double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  _orig->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwE[3];
  getBaseElement()->xyz2uvw(xyz, uvwE);
  u = uvwE[0];
  v = uvwE[1];
  w = uvwE[2];
}

void MSubPoint::movePointFromElementSpaceToParentSpace(double &u, double &v,
                                                       double &w) const
{
  if(!_orig) return;
  SPoint3 p;
  getBaseElement()->pnt(u, v, w, p);
  double xyz[3] = {p.x(), p.y(), p.z()};
  double uvwP[3];
  _orig->xyz2uvw(xyz, uvwP);
  u = uvwP[0];
  v = uvwP[1];
  w = uvwP[2];
}

bool MSubPoint::isInside(double u, double v, double w) const
{
  if(!_orig) return false;

  if(_orig->getDim() != getDim()) { // projection on the base Element
    SPoint3 p;
    _orig->pnt(u, v, w, p);
    double xyz[3] = {p.x(), p.y(), p.z()};
    double uvwE[3];
    getBaseElement()->xyz2uvw(xyz, uvwE);
    SPoint3 pE;
    getBaseElement()->pnt(uvwE[0], uvwE[1], uvwE[2], pE);
    double tol = _isInsideTolerance;
    if(fabs(p.x() - pE.x()) > tol) return false;
    if(fabs(p.y() - pE.y()) > tol) return false;
    if(fabs(p.z() - pE.z()) > tol) return false;
  }

  movePointFromParentSpaceToElementSpace(u, v, w);
  if(getBaseElement()->isInside(u, v, w)) return true;
  return false;
}

void MSubPoint::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  // invariable regardless of the order
  if(!_pts) {
    if(!_orig) return;

    _pts = new IntPt[1];
    // work in the parametric space of the parent element
    MVertex *vi = getVertex(0);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    double v_uvw[3];
    _orig->xyz2uvw(v_xyz, v_uvw);
    double jac[3][3];
    double origJac = _orig->getJacobian(v_uvw[0], v_uvw[1], v_uvw[2], jac);
    _pts[0].pt[0] = v_uvw[0];
    _pts[0].pt[1] = v_uvw[1];
    _pts[0].pt[2] = v_uvw[2];
    _pts[0].weight = 1. / origJac;
  }
  *npts = 1;
  *pts = _pts;
}
