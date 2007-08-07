#include "PlaneProjectionSurface.h"

using namespace FM;

PlaneProjectionSurface::PlaneProjectionSurface
(int tag) : ProjectionSurface()
{
  SetTag(tag);
  SetName(std::string("plane"));

  numParameters_ = 0;

  O_[0] = O_[1] = O_[2] = 0.;

  E0_[0] = 1.; E0_[1] = 0.; E0_[2] = 0.;
  E1_[0] = 0.; E1_[1] = 1.; E1_[2] = 0.;
  E2_[0] = 0.; E2_[1] = 0.; E2_[2] = 1.;

  scale_[0] = scale_[1] = scale_[2] = 1.;
}

PlaneProjectionSurface::PlaneProjectionSurface
(int tag, double O[3], double E0[3], double E1[3], double scale[3])
  : ProjectionSurface()
{
  SetTag(tag);
  SetName(std::string("Plane"));

  O_[0] = O[0]; O_[1] = O[1]; O_[2] = O[2];

  E0_[0] = E0[0]; E0_[1] = E0[1]; E0_[2] = E0[2];
  E1_[0] = E1[0]; E1_[1] = E1[1]; E1_[2] = E1[2];

  E2_[0] = E0_[1] * E1_[2] - E0_[2] * E1_[1];
  E2_[1] = E0_[2] * E1_[0] - E0_[0] * E1_[2];
  E2_[2] = E0_[0] * E1_[1] - E0_[1] * E1_[0];

  scale_[0] = scale[0]; scale_[1] = scale[1]; scale_[2] = scale[2];
}

void PlaneProjectionSurface::
F(double u, double v, double &x, double &y, double &z)
{
  x = O_[0] + u * scale_[1] * E1_[0] + v * scale_[2] * E2_[0];
  y = O_[1] + u * scale_[1] * E1_[1] + v * scale_[2] * E2_[1];
  z = O_[2] + u * scale_[1] * E1_[2] + v * scale_[2] * E2_[2];
}

bool PlaneProjectionSurface::
Inverse(double x, double y, double z, double &u,double &v)
{
  u = (x - O_[0]) * E1_[0] + (y - O_[1]) * E1_[1] + (z - O_[2]) * E1_[2];
  v = (x - O_[0]) * E2_[0] + (y - O_[1]) * E2_[1] + (z - O_[2]) * E2_[2];
  
  u /= scale_[1];
  v /= scale_[2];

  double tol = 1.e-12;
  
  if ((u > - tol) && (u < 1. + tol) && (v > - tol) && (v < 1. + tol))
    return true;
  else
    return false;
}

void PlaneProjectionSurface::
Dfdu(double u, double v, double &x, double &y, double &z)
{
  x = scale_[1] * E1_[0];
  y = scale_[1] * E1_[1];
  z = scale_[1] * E1_[2];
}

void PlaneProjectionSurface::
Dfdv(double u, double v, double &x, double &y, double &z)
{
  x = scale_[2] * E2_[0];
  y = scale_[2] * E2_[1];
  z = scale_[2] * E2_[2];
}

void PlaneProjectionSurface::
Dfdfdudu(double u,double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dfdfdudv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dfdfdvdv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dfdfdfdududu(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dfdfdfdududv(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dfdfdfdudvdv(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dfdfdfdvdvdv(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
GetNormal(double u, double v, double &x, double &y, double &z)
{
  x = E0_[0];
  y = E0_[1];
  z = E0_[2];
}

void PlaneProjectionSurface::
Dndu(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dndv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dndndudu(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dndndudv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void PlaneProjectionSurface::
Dndndvdv(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

bool PlaneProjectionSurface::
OrthoProjectionOnSurface(double x, double y, double z, double &u,double &v)
{
  return Inverse(x,y,z,u,v);
}

void PlaneProjectionSurface::
SetParameter(int i, double x)
{
}

double PlaneProjectionSurface::
GetParameter(int i)
{
  return 0.;
}

std::string PlaneProjectionSurface::
GetLabel(int i)
{
  return std::string(" ");
}
