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
  z = O_[0] + (u - 0.5) * scale_[1] * E1_[2] + (v - 0.5) * scale_[2] * E2_[2] +
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
  /*
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

  u = atan2(RdotNcT,RdotT);
  u /= twoPi_;
  u += 0.5;      

  double r1 = 0., r2 = 0.;
  for (int i=0;i<3;i++) {
    r1 += R[i] * (E1_[i] * scale_[1] * cos(twoPi_ * (u - 0.5)) +
		 E2_[i] * scale_[2] * sin(twoPi_ * (u - 0.5)));
    r2 += R[i] * scale_[0] * E0_[i];
  }

  double A = 
    scale_[1] * scale_[1] * cos(twoPi_ * (u - 0.5)) * cos(twoPi_ * (u - 0.5)) +
    scale_[2] * scale_[2] * sin(twoPi_ * (u - 0.5)) * sin(twoPi_ * (u - 0.5));
  double B = scale_[0] * scale_[0];

  double a = 2 * K_[1] * K_[1] * B * B;
  double b = K_[0] * K_[0] * A * A - 2 * K_[1] * r2 * B;
  double c = - K_[0] * r1 * A;

  std::vector<double> root = SolveCubic(a,b,c);

  if (root.size()) {

    for (int i=0;i<root.size();i++) {
      if (root[i] >= 0.) {
	v = root[i];
	break;
      }
    }
    double tol =1.e-4;
    if ((u > - tol) && (u < 1. + tol) && (v > - tol) && (v < 1. + tol))
      return true;
    else
      return false;
  }
  else
    return false;
*/
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
