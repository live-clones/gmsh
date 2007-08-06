#include "CylindricalProjectionSurface.h"

CylindricalProjectionSurface::CylindricalProjectionSurface
(int tag) : ProjectionSurface(1.)
{
  SetTag(tag);
  SetName(std::string("Cylinder"));

  twoPi_ = 2 * M_PI;

  R_ = 1.;
  Z_ = 1.;

  numParameters_ = 2;

  O_[0] = O_[1] = O_[2] = 0.;

  E0_[0] = 1.; E0_[1] = 0.; E0_[2] = 0.;
  E1_[0] = 0.; E1_[1] = 1.; E1_[2] = 0.;
  E2_[0] = 0.; E2_[1] = 0.; E2_[2] = 1.;

  scale_[0] = scale_[1] = scale_[2] = 1.;
}

CylindricalProjectionSurface::CylindricalProjectionSurface
(int tag, double O[3], double E0[3], double E1[3], double scale[3])
  : ProjectionSurface(1.)
{
  SetTag(tag);
  SetName(std::string("Cylinder"));

  twoPi_ = 2 * M_PI;

  O_[0] = O[0]; O_[1] = O[1]; O_[2] = O[2];

  E0_[0] = E0[0]; E0_[1] = E0[1]; E0_[2] = E0[2];
  E1_[0] = E1[0]; E1_[1] = E1[1]; E1_[2] = E1[2];

  E2_[0] = E0_[1] * E1_[2] - E0_[2] * E1_[1];
  E2_[1] = E0_[2] * E1_[0] - E0_[0] * E1_[2];
  E2_[2] = E0_[0] * E1_[1] - E0_[1] * E1_[0];

  scale_[0] = scale[0]; scale_[1] = scale[1]; scale_[2] = scale[2];
}

CylindricalProjectionSurface::CylindricalProjectionSurface
(int tag, double O[3], double E0[3], double E1[3], double scale[3],
 double R, double Z)
  : ProjectionSurface(1.)
{
  SetTag(tag);
  SetName(std::string("Cylinder"));

  twoPi_ = 2 * M_PI;

  O_[0] = O[0]; O_[1] = O[1]; O_[2] = O[2];

  E0_[0] = E0[0]; E0_[1] = E0[1]; E0_[2] = E0[2];
  E1_[0] = E1[0]; E1_[1] = E1[1]; E1_[2] = E1[2];

  E2_[0] = E0_[1] * E1_[2] - E0_[2] * E1_[1];
  E2_[1] = E0_[2] * E1_[0] - E0_[0] * E1_[2];
  E2_[2] = E0_[0] * E1_[1] - E0_[1] * E1_[0];

  scale_[0] = scale[0]; scale_[1] = scale[1]; scale_[2] = scale[2];

  R_ = R;
  Z_ = Z;
}

void CylindricalProjectionSurface::
F(double u, double v, double &x, double &y, double &z)
{
  x = O_[0] + E0_[0] * Z_ * v;
  y = O_[1] + E0_[1] * Z_ * v;
  z = O_[2] + E0_[2] * Z_ * v;
  
  x += R_ * (E1_[0] * cos(twoPi_ * (u - 0.5)) + 
	     E2_[0] * sin(twoPi_ * (u - 0.5)));
  y += R_ * (E1_[1] * cos(twoPi_ * (u - 0.5)) +
	     E2_[1] * sin(twoPi_ * (u - 0.5)));
  z += R_ * (E1_[2] * cos(twoPi_ * (u - 0.5)) +
	     E2_[2] * sin(twoPi_ * (u - 0.5)));
}

bool CylindricalProjectionSurface::
Inverse(double x, double y, double z, double &u,double &v)
{
  double tol =1.e-12;

  double t = (x - O_[0]) * E0_[0] +
    (y - O_[1]) * E0_[1] +
    (z - O_[2]) * E0_[2];
  v = t / Z_;
  double n[3];
  n[0] = x - (O_[0] + t * E0_[0]);
  n[1] = y - (O_[1] + t * E0_[1]);
  n[2] = z - (O_[2] + t * E0_[2]);
  double norm = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
  for (int i=0;i<3;i++)
    n[i] /= norm;
  u = atan2((n[0]*E2_[0]+n[1]*E2_[1]+n[2]*E2_[2]),
	    (n[0]*E1_[0]+n[1]*E1_[1]+
	     n[2]*E1_[2]));
  u /= twoPi_;
  u += 0.5;

  if ((u > - tol) && (u < 1. + tol) && (v > - tol) && (v < 1. + tol))
    return true;
  else
    return false;
}

void CylindricalProjectionSurface::
Dfdu(double u, double v, double &x, double &y, double &z)
{
  x = twoPi_ * R_ * 
    (- E1_[0] * sin(twoPi_ * (u - 0.5)) +
     E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = twoPi_ * R_ *
    (- E1_[1] * sin(twoPi_ * (u - 0.5)) +
     E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = twoPi_ * R_ *
    (- E1_[2] * sin(twoPi_ * (u - 0.5)) +
     E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void CylindricalProjectionSurface::
Dfdv(double u, double v, double &x, double &y, double &z)
{
  x = E0_[0] * Z_;
  y = E0_[1] * Z_;
  z = E0_[2] * Z_;
}

void CylindricalProjectionSurface::
Dfdfdudu(double u,double v, double &x, double &y, double &z)
{
  x = -  twoPi_ *  twoPi_ * R_ *
    (E1_[0] * cos(twoPi_ * (u - 0.5)) +
     E2_[0] * sin(twoPi_ * (u - 0.5)));
  y = -  twoPi_ *  twoPi_ * R_ *
    (E1_[1] * cos(twoPi_ * (u - 0.5)) +
     E2_[1] * sin(twoPi_ * (u - 0.5)));
  z = -  twoPi_ *  twoPi_ * R_ *
    (E1_[2] * cos(twoPi_ * (u - 0.5)) +
     E2_[2] * sin(twoPi_ * (u - 0.5)));
}

void CylindricalProjectionSurface::
Dfdfdudv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void CylindricalProjectionSurface::
Dfdfdvdv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void CylindricalProjectionSurface::
Dfdfdfdududu(double u,double v,double &x,double &y,double &z)
{
  x = twoPi_ *  twoPi_ * twoPi_ * R_ *
    (E1_[0] * sin(twoPi_ * (u - 0.5)) -
     E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = twoPi_ *  twoPi_ * twoPi_ * R_ *
    (E1_[1] * sin(twoPi_ * (u - 0.5)) -
     E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = twoPi_ *  twoPi_ * twoPi_ * R_ *
    (E1_[2] * sin(twoPi_ * (u - 0.5)) +
     E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void CylindricalProjectionSurface::
Dfdfdfdududv(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void CylindricalProjectionSurface::
Dfdfdfdudvdv(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void CylindricalProjectionSurface::
Dfdfdfdvdvdv(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void CylindricalProjectionSurface::
GetNormal(double u, double v, double &x, double &y, double &z)
{
  x = E1_[0] * cos(twoPi_ * (u - 0.5)) + 
    E2_[0] * sin(twoPi_ * (u - 0.5));
  y = E1_[1] * cos(twoPi_ * (u - 0.5)) +
    E2_[1] * sin(twoPi_ * (u - 0.5));
  z = E1_[2] * cos(twoPi_ * (u - 0.5)) +
    E2_[2] * sin(twoPi_ * (u - 0.5));
}

void CylindricalProjectionSurface::
Dndu(double u, double v, double &x, double &y, double &z)
{
  Dfdu(u,v,x,y,z);
}

void CylindricalProjectionSurface::
Dndv(double u, double v, double &x, double &y, double &z)
{
  Dfdv(u,v,x,y,z);
}

void CylindricalProjectionSurface::
Dndndudu(double u, double v, double &x, double &y, double &z)
{
  Dfdfdudu(u,v,x,y,z);
}

void CylindricalProjectionSurface::
Dndndudv(double u, double v, double &x, double &y, double &z)
{
  Dfdfdudv(u,v,x,y,z);
}

void CylindricalProjectionSurface::
Dndndvdv(double u, double v, double &x, double &y, double &z)
{
  Dfdfdvdv(u,v,x,y,z);
}

bool CylindricalProjectionSurface::
OrthoProjectionOnSurface(double x, double y, double z, double &u,double &v)
{
  return Inverse(x,y,z,u,v);
}

void CylindricalProjectionSurface::
SetParameter(int i, double x)
{
  switch (i) {
  case 0:
    R_ = x;
  case 1:
    Z_ = x;
  }
}

double CylindricalProjectionSurface::
GetParameter(int i)
{
  switch (i) {
  case 0:
    return R_;
  case 1:
    return Z_;
  }
}

std::string CylindricalProjectionSurface::
GetLabel(int i)
{
  switch (i) {
  case 0:
    return std::string("R");
  case 1:
    return std::string("Hight Scale");
  }
}
