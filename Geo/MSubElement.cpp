#include "MSubElement.h"



//--------------------------------------------------------------------------
// MSubTetrahedron
//--------------------------------------------------------------------------

MSubTetrahedron::~MSubTetrahedron()
{
  if(_owner)
    delete _orig;
}

const polynomialBasis* MSubTetrahedron::getFunctionSpace(int order) const
{
  if(_orig) return _orig->getFunctionSpace(order);
  return 0;
}
const JacobianBasis* MSubTetrahedron::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return 0;
}
void MSubTetrahedron::getShapeFunctions(double u, double v, double w, double s[], int o)
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
}
void MSubTetrahedron::getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
{
  if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
}
void MSubTetrahedron::getHessShapeFunctions(double u, double v, double w, double s[][3][3], int o)
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
}

bool MSubTetrahedron::isInside(double u, double v, double w)
{
  if(!_orig) return false;
  double uvw[3] = {u, v, w};
  double v_uvw[4][3];
  for(int i=0; i<4; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MVertex v3(v_uvw[3][0], v_uvw[3][1], v_uvw[3][2]);
  MTetrahedron t(&v0, &v1, &v2, &v3);
  double ksi[3];
  t.xyz2uvw(uvw, ksi);
  if(t.isInside(ksi[0], ksi[1], ksi[2]))
    return true;
  return false;
}
void MSubTetrahedron::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts=0;
  if(_intpt) delete [] _intpt;
  if(!_orig) return;
  _intpt = new IntPt[getNGQTetPts(pOrder)];
  int nptsi;
  IntPt *ptsi;

  double v_uvw[4][3];
  for(int i=0; i<4; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MVertex v3(v_uvw[3][0], v_uvw[3][1], v_uvw[3][2]);
  MTetrahedron tt(&v0, &v1, &v2, &v3);
  tt.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  double jac[3][3];
  for(int ip=0; ip<nptsi; ++ip)
  {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    tt.getJacobian(u, v, w, jac);
    SPoint3 p; tt.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}


//--------------------------------------------------------------------------
// MSubTriangle
//--------------------------------------------------------------------------

MSubTriangle::~MSubTriangle()
{
  if(_owner)
    delete _orig;
}

const polynomialBasis* MSubTriangle::getFunctionSpace(int order) const
{
  if(_orig) return _orig->getFunctionSpace(order);
  return 0;
}
const JacobianBasis* MSubTriangle::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return 0;
}
void MSubTriangle::getShapeFunctions(double u, double v, double w, double s[], int o)
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
}
void MSubTriangle::getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
{
  if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
}
void MSubTriangle::getHessShapeFunctions(double u, double v, double w, double s[][3][3], int o)
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
}

bool MSubTriangle::isInside(double u, double v, double w)
{
  if(!_orig) return false;
  double uvw[3] = {u, v, w};
  double v_uvw[3][3];
  for(int i=0; i<3; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MTriangle t(&v0, &v1, &v2);
  double ksi[3];
  t.xyz2uvw(uvw, ksi);
  if(t.isInside(ksi[0], ksi[1], ksi[2]))
    return true;
  return false;
}
void MSubTriangle::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts=0;
  if(_intpt) delete [] _intpt;
  if(!_orig) return;
  _intpt = new IntPt[getNGQTPts(pOrder)];
  int nptsi;
  IntPt *ptsi;

  double v_uvw[3][3];
  for(int i=0; i<3; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MTriangle t(&v0, &v1, &v2);
  t.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  double jac[3][3];
  for(int ip=0; ip<nptsi; ++ip)
  {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    t.getJacobian(u, v, w, jac);
    SPoint3 p; t.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}


//--------------------------------------------------------------------------
// MSubLine
//--------------------------------------------------------------------------

MSubLine::~MSubLine()
{
  if(_owner)
    delete _orig;
}

const polynomialBasis* MSubLine::getFunctionSpace(int order) const
{
  if(_orig) return _orig->getFunctionSpace(order);
  return 0;
}
const JacobianBasis* MSubLine::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return 0;
}
void MSubLine::getShapeFunctions(double u, double v, double w, double s[], int o)
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
}
void MSubLine::getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
{
  if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
}
void MSubLine::getHessShapeFunctions(double u, double v, double w, double s[][3][3], int o)
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
}

bool MSubLine::isInside(double u, double v, double w)
{
  if(!_orig) return false;
  double uvw[3] = {u, v, w};
  double v_uvw[2][3];
  for(int i=0; i<2; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  double ksi[3];
  l.xyz2uvw(uvw, ksi);
  if(l.isInside(ksi[0], ksi[1], ksi[2]))
    return true;
  return false;
}
void MSubLine::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  *npts=0;
  if(_intpt) delete [] _intpt;
  if(!_orig) return;
  _intpt = new IntPt[getNGQLPts(pOrder)];
  int nptsi;
  IntPt *ptsi;
  double v_uvw[2][3];
  for(int i=0; i<2; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  l.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  for(int ip=0; ip<nptsi; ++ip)
  {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    SPoint3 p; l.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}

//--------------------------------------------------------------------------
// MSubPoint
//--------------------------------------------------------------------------

MSubPoint::~MSubPoint()
{
  if(_owner)
    delete _orig;
}

const polynomialBasis* MSubPoint::getFunctionSpace(int order) const
{
  if(_orig) return _orig->getFunctionSpace(order);
  return 0;
}
const JacobianBasis* MSubPoint::getJacobianFuncSpace(int order) const
{
  if(_orig) return _orig->getJacobianFuncSpace(order);
  return 0;
}
void MSubPoint::getShapeFunctions(double u, double v, double w, double s[], int o)
{
  if(_orig) _orig->getShapeFunctions(u, v, w, s, o);
}
void MSubPoint::getGradShapeFunctions(double u, double v, double w, double s[][3], int o)
{
  if(_orig) _orig->getGradShapeFunctions(u, v, w, s, o);
}
void MSubPoint::getHessShapeFunctions(double u, double v, double w, double s[][3][3], int o)
{
  if(_orig) _orig->getHessShapeFunctions(u, v, w, s, o);
}

bool MSubPoint::isInside(double u, double v, double w)
{
  if(!_orig) return false;
  MVertex *v0 = getVertex(0);
  double v_xyz[3] = {v0->x(), v0->y(), v0->z()};
  double v_uvw[3];
  _orig->xyz2uvw(v_xyz, v_uvw);

  double p_xyz[3] = {u, v, w};
  double p_uvw[3];
  _orig->xyz2uvw(p_xyz, p_uvw);

  double d_xyz[3] = {p_uvw[0]-v_uvw[0], p_uvw[1]-v_uvw[1], p_uvw[2]-v_uvw[2]};
  double tol = _isInsideTolerance;

   if (d_xyz[0]*d_xyz[0]+d_xyz[1]*d_xyz[1]+d_xyz[2]*d_xyz[2]<tol*tol)
     return true;
  return false;
}
void MSubPoint::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  static IntPt GQL[1];
  GQL[0].pt[0] = 0;
  GQL[0].pt[1] = 0;
  GQL[0].pt[2] = 0;
  GQL[0].weight = 1;
  *npts = 1;
  *pts = GQL;
}
