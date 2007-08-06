#include "RevolvedParabolaProjectionSurface.h"

RevolvedParabolaProjectionSurface::RevolvedParabolaProjectionSurface
(int tag) : ProjectionSurface(1.) 
{
  SetTag(tag);
  SetName(std::string("revolvedParabola"));

  twoPi_ = 2 * M_PI;

  R_ = 1.;
  K_[0] = K_[1] = 0.5;

  numParameters_ = 3;

  O_[0] = O_[1] = O_[2] = 0.;

  E0_[0] = 0.; E0_[1] = 0.; E0_[2] = 1.;
  E1_[0] = 1.; E1_[1] = 0.; E1_[2] = 0.;
  E2_[0] = 0.; E2_[1] = 1.; E2_[2] = 0.;

  scale_[0] = scale_[1] = scale_[2] = 1.;
}

RevolvedParabolaProjectionSurface::RevolvedParabolaProjectionSurface
(int tag, double O[3], double E0[3], double E1[3], double scale[3],
 double R, double K[2]) : ProjectionSurface(1.) 
{
  printf("here\n");

  SetTag(tag);
  SetName(std::string("revolvedParabola"));

  twoPi_ = 2 * M_PI;

  R_ = R;
  K_[0] = K[0]; K_[1] = K[1];

  O_[0] = O[0]; O_[1] = O[1]; O_[2] = O[2];

  E0_[0] = E0[0]; E0_[1] = E0[1]; E0_[2] = E0[2];
  E1_[0] = E1[0]; E1_[1] = E1[1]; E1_[2] = E1[2];

  E2_[0] = E0_[1] * E1_[2] - E0_[2] * E1_[1];
  E2_[1] = E0_[2] * E1_[0] - E0_[0] * E1_[2];
  E2_[2] = E0_[0] * E1_[1] - E0_[1] * E1_[0]; 

  scale_[0] = scale[0]; scale_[1] = scale[1]; scale_[2] = scale[2];

  printf("P : %g %g %g\n",R_,K_[0],K_[1]);
  printf("O : %g %g %g\n",O_[0],O_[1],O_[2]);
  printf("E0 : %g %g %g\n",E0_[0],E0_[1],E0_[2]);
  printf("E1 : %g %g %g\n",E1_[0],E1_[1],E1_[2]);
  printf("s : %g %g %g\n",scale_[0],scale_[1],scale_[2]);
}

void RevolvedParabolaProjectionSurface::F
(double u, double v, double &x, double &y, double &z)
{
  x = O_[0] + (R_ + K_[0] * (v - 0.5)) *
    (E1_[0] * cos(twoPi_ * (u - 0.5)) + E2_[0] * sin(twoPi_ * (u - 0.5))) + 
    K_[1] * (v - 0.5) * (v - 0.5) * E0_[0];
  y = O_[1] + (R_ + K_[0] * (v - 0.5)) *
    (E1_[1] * cos(twoPi_ * (u - 0.5)) + E2_[1] * sin(twoPi_ * (u - 0.5))) + 
    K_[1] * (v - 0.5) * (v - 0.5) * E0_[1];
  z = O_[2] + (R_ + K_[0] * (v - 0.5)) *
    (E1_[2] * cos(twoPi_ * (u - 0.5)) + E2_[2] * sin(twoPi_ * (u - 0.5))) + 
    K_[1] * (v - 0.5) * (v - 0.5) * E0_[2];
}

bool RevolvedParabolaProjectionSurface::Inverse
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

  u = atan2(RdotNcT,RdotT);
  u /= twoPi_;
  u += 0.5;

  v = sqrt(RdotT * RdotT + RdotNcT * RdotNcT);
  v -= R_;
  v /= K_[0];
  v += 0.5;
}

void RevolvedParabolaProjectionSurface::Dfdu
(double u, double v, double &x, double &y, double &z)
{
  x = twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (- E1_[0] * sin(twoPi_ * (u - 0.5)) + E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (- E1_[1] * sin(twoPi_ * (u - 0.5)) + E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (- E1_[2] * sin(twoPi_ * (u - 0.5)) + E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void RevolvedParabolaProjectionSurface::Dfdv
(double u, double v, double &x, double &y, double &z)
{
  x = K_[0] * 
    (E1_[0] * cos(twoPi_ * (u - 0.5)) + E2_[0] * sin(twoPi_ * (u - 0.5))) + 
    2. * K_[1] * (v - 0.5) * E0_[0];
  y = K_[0] *
    (E1_[1] * cos(twoPi_ * (u - 0.5)) + E2_[1] * sin(twoPi_ * (u - 0.5))) + 
    2. * K_[1] * (v - 0.5) * E0_[1];
  z = K_[0] *
    (E1_[2] * cos(twoPi_ * (u - 0.5)) + E2_[2] * sin(twoPi_ * (u - 0.5))) + 
    2. * K_[1] * (v - 0.5) * E0_[2];
}

void RevolvedParabolaProjectionSurface::Dfdfdudu
(double u,double v, double &x, double &y, double &z)
{
  x = -  twoPi_ *  twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (E1_[0] * cos(twoPi_ * (u - 0.5)) + E2_[0] * sin(twoPi_ * (u - 0.5)));
  y = -  twoPi_ *  twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (E1_[1] * cos(twoPi_ * (u - 0.5)) + E2_[1] * sin(twoPi_ * (u - 0.5)));
  z = -  twoPi_ *  twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (E1_[2] * cos(twoPi_ * (u - 0.5)) + E2_[2] * sin(twoPi_ * (u - 0.5)));
}

void RevolvedParabolaProjectionSurface::Dfdfdudv
(double u, double v, double &x, double &y, double &z)
{
  x = K_[0] * twoPi_ *
    (- E1_[0] * sin(twoPi_ * (u - 0.5)) + E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = K_[0] * twoPi_ *
    (- E1_[1] * sin(twoPi_ * (u - 0.5)) + E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = K_[0] * twoPi_ *
    (- E1_[2] * sin(twoPi_ * (u - 0.5)) + E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void RevolvedParabolaProjectionSurface::Dfdfdvdv
(double u, double v, double &x, double &y, double &z)
{
  x = 2. * K_[1] * E0_[0];
  y = 2. * K_[1] * E0_[1];
  z = 2. * K_[1] * E0_[2];
}

void RevolvedParabolaProjectionSurface::Dfdfdfdududu
(double u,double v,double &x,double &y,double &z)
{
  x = twoPi_ *  twoPi_ * twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (E1_[0] * sin(twoPi_ * (u - 0.5)) - E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = twoPi_ *  twoPi_ * twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (E1_[1] * sin(twoPi_ * (u - 0.5)) - E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = twoPi_ *  twoPi_ * twoPi_ * (R_ + K_[0] * (v - 0.5)) *
    (E1_[2] * sin(twoPi_ * (u - 0.5)) + E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void RevolvedParabolaProjectionSurface::Dfdfdfdududv
(double u,double v,double &x,double &y,double &z)
{
  x = -  twoPi_ *  twoPi_ * K_[0] *
    (E1_[0] * cos(twoPi_ * (u - 0.5)) + E2_[0] * sin(twoPi_ * (u - 0.5)));
  y = -  twoPi_ *  twoPi_ * K_[0]  *
    (E1_[1] * cos(twoPi_ * (u - 0.5)) + E2_[1] * sin(twoPi_ * (u - 0.5)));
  z = -  twoPi_ *  twoPi_ * K_[0] *
    (E1_[2] * cos(twoPi_ * (u - 0.5)) + E2_[2] * sin(twoPi_ * (u - 0.5)));
}

void RevolvedParabolaProjectionSurface::Dfdfdfdudvdv
(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

void RevolvedParabolaProjectionSurface::Dfdfdfdvdvdv
(double u,double v,double &x,double &y,double &z)
{
  x = y = z = 0.;
}

bool RevolvedParabolaProjectionSurface::OrthoProjectionOnSurface
(double x, double y, double z, double& u, double& v)
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

  u = atan2(RdotNcT,RdotT);
  u /= twoPi_;
  u += 0.5;      

  double A = - R_, B = 0.;
  for (int i=0;i<3;i++) {
    A += R[i] * (E1_[i] * cos(twoPi_ * (u - 0.5)) +
		 E2_[i] * sin(twoPi_ * (u - 0.5)));
    B += R[i] * E0_[i];
  }

  double a = 2 * K_[1] * K_[1];
  double b = K_[0] * K_[0] - 2 * K_[1] * B;
  double c = - K_[0] * A;

  std::vector<double> root = SolveCubic(a,b,c);

  if (root.size()) {
    double xP,yP,zP;
    double minDist = 1.e12;
    for (int i=0;i<root.size();i++) {
      F(u,root[i] + 0.5,xP,yP,zP);
      double dist = sqrt((x-xP)*(x-xP)+(y-yP)*(y-yP)+(z-zP)*(z-zP));
      if (dist < minDist) {
	minDist = dist;
	v = root[i] + 0.5;
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
}

void RevolvedParabolaProjectionSurface::
SetParameter(int i, double x)
{
  switch (i) {
  case 0:
    R_ = x;
  case 1:
    K_[0] = x;
  case 2:
    K_[1] = x;
  }
}

double RevolvedParabolaProjectionSurface::
GetParameter(int i)
{
  switch (i) {
  case 0:
    return R_;
  case 1:
    return K_[0];
  case 2:
    return K_[1];
  }
}

std::string RevolvedParabolaProjectionSurface::
GetLabel(int i)
{
  switch (i) {
  case 0:
    return std::string("Radius");
  case 1:
    return std::string("Parabola Scale 1");
  case 2:
    return std::string("Parabola Scale 2");
  }
}
