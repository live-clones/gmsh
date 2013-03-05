// Gmsh - Copyright (C) 1997-2013 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.
//
// Contributor(s):
//   Frederic Duboeuf

#include "MSubElement.h"

// MSubTetrahedron

MSubTetrahedron::~MSubTetrahedron()
{
  if(_intpt) delete [] _intpt;
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

  // work in the parametric space of the parent element
  // (i) get the parametric coordinates of MSubElement vertices in this space
  double v_uvw[4][3];
  for(int i=0; i<4; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  // (ii) build a MElement on the vertices with these coordinates in this space
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MVertex v3(v_uvw[3][0], v_uvw[3][1], v_uvw[3][2]);
  MTetrahedron tt(&v0, &v1, &v2, &v3);
  // (iii) get the integration points of the new element in its parametric space 
  tt.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  // (iv) get the coordinates of these points in the parametric space of parent element
  for(int ip=0; ip<nptsi; ++ip)
  {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    SPoint3 p; tt.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}


// MSubTriangle

MSubTriangle::~MSubTriangle()
{
  if(_intpt) delete [] _intpt;
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

  // work in the parametric space of the parent element
  // (i) get the parametric coordinates of MSubElement vertices in this space
  double v_uvw[3][3];
  for(int i=0; i<3; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  // (ii) build a MElement on the vertices with these coordinates in this space
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MVertex v2(v_uvw[2][0], v_uvw[2][1], v_uvw[2][2]);
  MTriangle t(&v0, &v1, &v2);
  // (iii) get the integration points of the new element in its parametric space 
  t.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  // (iv) get the coordinates of these points in the parametric space of parent element
  for(int ip=0; ip<nptsi; ++ip)
  {
    const double u = ptsi[ip].pt[0];
    const double v = ptsi[ip].pt[1];
    const double w = ptsi[ip].pt[2];
    SPoint3 p; t.pnt(u, v, w, p);
    _intpt[*npts + ip].pt[0] = p.x();
    _intpt[*npts + ip].pt[1] = p.y();
    _intpt[*npts + ip].pt[2] = p.z();
    _intpt[*npts + ip].weight = ptsi[ip].weight;
  }
  *npts = nptsi;
  *pts = _intpt;
}


// MSubLine

MSubLine::~MSubLine()
{
  if(_intpt) delete [] _intpt;
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

  // work in the parametric space of the parent element
  // (i) get the parametric coordinates of MSubElement vertices in this space
  double v_uvw[2][3];
  for(int i=0; i<2; ++i)
  {
    MVertex *vi = getVertex(i);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    _orig->xyz2uvw(v_xyz, v_uvw[i]);
  }
  // (ii) build a MElement on the vertices with these coordinates in this space
  MVertex v0(v_uvw[0][0], v_uvw[0][1], v_uvw[0][2]);
  MVertex v1(v_uvw[1][0], v_uvw[1][1], v_uvw[1][2]);
  MLine l(&v0, &v1);
  // (iii) get the integration points of the new element in its parametric space 
  l.getIntegrationPoints(pOrder, &nptsi, &ptsi);
  // (iv) get the coordinates of these points in the parametric space of parent element
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


// MSubPoint

MSubPoint::~MSubPoint()
{
  if(_intpt) delete [] _intpt;
}


bool MSubPoint::isInside(double u, double v, double w)
{
  if(!_orig) return false;
  MVertex *v0 = getVertex(0);
  double v_xyz[3] = {v0->x(), v0->y(), v0->z()};
  double v_uvw[3];
  _orig->xyz2uvw(v_xyz, v_uvw);

  double d_xyz[3] = {u-v_uvw[0], v-v_uvw[1], w-v_uvw[2]};
  double tol = _isInsideTolerance;

   if (d_xyz[0]*d_xyz[0]+d_xyz[1]*d_xyz[1]+d_xyz[2]*d_xyz[2]<tol*tol)
     return true;
  return false;
}

void MSubPoint::getIntegrationPoints(int pOrder, int *npts, IntPt **pts)
{
  // invariable regardless of the order
  if(!_intpt)
  {
    if(!_orig) return;
    _intpt = new IntPt[1];
    // work in the parametric space of the parent element
    MVertex *vi = getVertex(0);
    double v_xyz[3] = {vi->x(), vi->y(), vi->z()};
    double v_uvw[3];
    _orig->xyz2uvw(v_xyz, v_uvw);
    _intpt[0].pt[0] = v_uvw[0];
    _intpt[0].pt[1] = v_uvw[1];
    _intpt[0].pt[2] = v_uvw[2];
    _intpt[0].weight = 1;
  }
  *npts = 1;
  *pts = _intpt;
}
