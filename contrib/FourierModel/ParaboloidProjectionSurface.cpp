#include "ParaboloidProjectionSurface.h"

using namespace FM;

ParaboloidProjectionSurface::ParaboloidProjectionSurface
(int tag) : ProjectionSurface() 
{
  SetTag(tag);
  SetName(std::string("paraboloid"));

  numParameters_ = 0;

  O_[0] = O_[1] = O_[2] = 0.;

  E0_[0] = 0.; E0_[1] = 0.; E0_[2] = 1.;
  E1_[0] = 1.; E1_[1] = 0.; E1_[2] = 0.;
  E2_[0] = 0.; E2_[1] = 1.; E2_[2] = 0.;

  scale_[0] = scale_[1] = scale_[2] = 1.;
}

ParaboloidProjectionSurface::ParaboloidProjectionSurface
(int tag, double O[3], double E0[3], double E1[3], double scale[3]) 
  : ProjectionSurface() 
{
  SetTag(tag);
  SetName(std::string("Paraboloid"));

  O_[0] = O[0]; O_[1] = O[1]; O_[2] = O[2];

  E0_[0] = E0[0]; E0_[1] = E0[1]; E0_[2] = E0[2];
  E1_[0] = E1[0]; E1_[1] = E1[1]; E1_[2] = E1[2];

  E2_[0] = E0_[1] * E1_[2] - E0_[2] * E1_[1];
  E2_[1] = E0_[2] * E1_[0] - E0_[0] * E1_[2];
  E2_[2] = E0_[0] * E1_[1] - E0_[1] * E1_[0]; 

  scale_[0] = scale[0]; scale_[1] = scale[1]; scale_[2] = scale[2];
}

void ParaboloidProjectionSurface::F
(double u, double v, double &x, double &y, double &z)
{
  x = O_[0] + (u - 0.5) * scale_[1] * E1_[0] + (v - 0.5) * scale_[2] * E2_[0] +
    ((u - 0.5) * scale_[1] * (u - 0.5) * scale_[1] +
     (v - 0.5) * scale_[2] * (v - 0.5) * scale_[2]) * scale_[0] * E0_[0];
  y = O_[1] + (u - 0.5) * scale_[1] * E1_[1] + (v - 0.5) * scale_[2] * E2_[1] +
    ((u - 0.5) * scale_[1] * (u - 0.5) * scale_[1] +
     (v - 0.5) * scale_[2] * (v - 0.5) * scale_[2]) * scale_[0] * E0_[1];
  z = O_[2] + (u - 0.5) * scale_[1] * E1_[2] + (v - 0.5) * scale_[2] * E2_[2] +
    ((u - 0.5) * scale_[1] * (u - 0.5) * scale_[1] +
     (v - 0.5) * scale_[2] * (v - 0.5) * scale_[2]) * scale_[0] * E0_[2];
}

bool ParaboloidProjectionSurface::Inverse
(double x, double y, double z, double &u,double &v)
{
  double R[3];
  R[0] = x - O_[0];
  R[1] = y - O_[1];
  R[2] = z - O_[2];

  double RdotT = 0., RdotNcT = 0.;
  for (int i=0;i<3;i++) {
    RdotT += R[i] * E1_[i];
    RdotNcT += R[i] * E2_[i];
  }

  RdotT /= scale_[1];
  RdotNcT /= scale_[2];

  u = RdotT + 0.5;
  v = RdotNcT + 0.5;
}

void ParaboloidProjectionSurface::Dfdu
(double u, double v, double &x, double &y, double &z)
{
  x = scale_[1] * E1_[0] + 
    2 * scale_[0] * scale_[1] * scale_[1] * (u - 0.5) * E0_[0];
  y = scale_[1] * E1_[1] + 
    2 * scale_[0] * scale_[1] * scale_[1] * (u - 0.5) * E0_[1];
  z = scale_[1] * E1_[2] + 
    2 * scale_[0] * scale_[1] * scale_[1] * (u - 0.5) * E0_[2];
}

void ParaboloidProjectionSurface::Dfdv
(double u, double v, double &x, double &y, double &z)
{
  x = scale_[2] * E2_[0] + 2 * scale_[0] * scale_[2] * (v - 0.5) * E0_[0];
  y = scale_[2] * E2_[1] + 2 * scale_[0] * scale_[2] * (v - 0.5) * E0_[1];
  z = scale_[2] * E2_[2] + 2 * scale_[0] * scale_[2] * (v - 0.5) * E0_[2];
}

void ParaboloidProjectionSurface::Dfdfdudu
(double u,double v, double &x, double &y, double &z)
{
  x = 2 * scale_[0] * scale_[1] * E0_[0];
  y = 2 * scale_[0] * scale_[1] * E0_[1];
  z = 2 * scale_[0] * scale_[1] * E0_[2];
}

void ParaboloidProjectionSurface::Dfdfdudv
(double u, double v, double &x, double &y, double &z)
{
  x = y = z = 0.;
}

void ParaboloidProjectionSurface::Dfdfdvdv
(double u, double v, double &x, double &y, double &z)
{
  x = 2. * scale_[0] * scale_[2] * E0_[0];
  y = 2. * scale_[0] * scale_[2] * E0_[1];
  z = 2. * scale_[0] * scale_[2] * E0_[2];
}

void ParaboloidProjectionSurface::Dfdfdfdududu
(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void ParaboloidProjectionSurface::Dfdfdfdududv
(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void ParaboloidProjectionSurface::Dfdfdfdudvdv
(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void ParaboloidProjectionSurface::Dfdfdfdvdvdv
(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

bool ParaboloidProjectionSurface::OrthoProjectionOnSurface
(double x, double y, double z, double& u, double& v)
{
  double R[3];
  R[0] = x - O_[0];
  R[1] = y - O_[1];
  R[2] = z - O_[2];

  double x0 = 0., y0 = 0., z0 = 0.;
  for (int i=0;i<3;i++) {
    x0 += R[i] * E1_[i];
    y0 += R[i] * E2_[i];
    z0 += R[i] * E0_[i];
  }

  z0 /= scale_[0];

  double a = 4.;
  double b = 4. * (1. + z0);
  double c = 1 + 4. * z0;
  double d = z0 - x0 * x0 - y0 * y0;

  std::vector<double> root = SolveCubic(a,b,c,d);

  if (root.size()) {
    double xP,yP,zP;
    double minDist = 1.e12;
    double minRoot;
    for (int i=0;i<root.size();i++) {
      xP = x0 / (2 * root[i] + 1.);
      yP = y0 / (2 * root[i] + 1.);
      zP = z0 + root[i];
      double dist = sqrt((x0-xP)*(x0-xP)+(y0-yP)*(y0-yP)+(z0-zP)*(z0-zP));
      if (dist < minDist) {
        minDist = dist;
        minRoot = root[i];
      }
    }
    xP = x0 / (2 * minRoot + 1.);
    yP = y0 / (2 * minRoot + 1.);
    zP = z0 + minRoot;
    u = xP / scale_[1] + 0.5;
    v = yP / scale_[2] + 0.5;
    double tol =1.e-4;
    if ((u > - tol) && (u < 1. + tol) && (v > - tol) && (v < 1. + tol))
      return true;
    else
      return false;
  }
  else
    return false;
}

void ParaboloidProjectionSurface::
SetParameter(int i, double x)
{
}

double ParaboloidProjectionSurface::
GetParameter(int i)
{
  return 0.;
}

std::string ParaboloidProjectionSurface::
GetLabel(int i)
{
  return std::string(" ");
}
