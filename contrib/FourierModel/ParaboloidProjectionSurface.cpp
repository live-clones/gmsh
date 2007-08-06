#include "ParaboloidProjectionSurface.h"

ParaboloidProjectionSurface::ParaboloidProjectionSurface
(int tag) : ProjectionSurface(1.) 
{
  SetTag(tag);
  SetName(std::string("paraboloid"));

  twoPi_ = 2 * M_PI;
  K_[0] = K_[1] = 0.5;

  numParameters_ = 2;

  O_[0] = O_[1] = O_[2] = 0.;

  E0_[0] = 0.; E0_[1] = 0.; E0_[2] = 1.;
  E1_[0] = 1.; E1_[1] = 0.; E1_[2] = 0.;
  E2_[0] = 0.; E2_[1] = 1.; E2_[2] = 0.;

  scale_[0] = scale_[1] = scale_[2] = 1.;
}

ParaboloidProjectionSurface::ParaboloidProjectionSurface
(int tag, double O[3], double E0[3], double E1[3], double scale[3],
 double K[2]) : ProjectionSurface(1.) 
{
  SetTag(tag);
  SetName(std::string("Paraboloid"));

  twoPi_ = 2 * M_PI;
  K_[0] = K[0]; K_[1] = K[1];

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
  x = O_[0] + K_[0] * v * (scale_[1] * E1_[0] * cos(twoPi_ * (u - 0.5)) + 
			   scale_[2] * E2_[0] * sin(twoPi_ * (u - 0.5))) + 
    K_[1] * v * v * scale_[0] * E0_[0];
  y = O_[1] + K_[0] * v * (scale_[1] * E1_[1] * cos(twoPi_ * (u - 0.5)) + 
			   scale_[2] * E2_[1] * sin(twoPi_ * (u - 0.5))) + 
    K_[1] * v * v * scale_[0] * E0_[1];
  z = O_[2] + K_[0] * v * (scale_[1] * E1_[2] * cos(twoPi_ * (u - 0.5)) + 
			   scale_[2] * E2_[2] * sin(twoPi_ * (u - 0.5))) + 
    K_[1] * v * v * scale_[0] * E0_[2];
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

  u = atan2(RdotNcT,RdotT);
  u /= twoPi_;
  u += 0.5;

  v = sqrt(RdotT * RdotT + RdotNcT * RdotNcT);
  v /= K_[0];
}

void ParaboloidProjectionSurface::Dfdu
(double u, double v, double &x, double &y, double &z)
{
  x = twoPi_ * K_[0] * v * (- scale_[1] * E1_[0] * sin(twoPi_ * (u - 0.5)) + 
			    scale_[2] * E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = twoPi_ * K_[0] * v * (- scale_[1] * E1_[1] * sin(twoPi_ * (u - 0.5)) + 
			    scale_[2] * E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = twoPi_ * K_[0] * v * (- scale_[1] * E1_[2] * sin(twoPi_ * (u - 0.5)) + 
			    scale_[2] * E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void ParaboloidProjectionSurface::Dfdv
(double u, double v, double &x, double &y, double &z)
{
  x = K_[0] * (scale_[1] * E1_[0] * cos(twoPi_ * (u - 0.5)) + 
	       scale_[2] * E2_[0] * sin(twoPi_ * (u - 0.5))) + 
    2. * K_[1] * v * scale_[0] * E0_[0];
  y = K_[0] * (scale_[1] * E1_[1] * cos(twoPi_ * (u - 0.5)) + 
	       scale_[2] * E2_[1] * sin(twoPi_ * (u - 0.5))) + 
    2. * K_[1] * v * scale_[0] * E0_[1];
  z = K_[0] * (scale_[1] * E1_[2] * cos(twoPi_ * (u - 0.5)) + 
	       scale_[2] * E2_[2] * sin(twoPi_ * (u - 0.5))) + 
    2. * K_[1] * v * scale_[0] * E0_[2];
}

void ParaboloidProjectionSurface::Dfdfdudu
(double u,double v, double &x, double &y, double &z)
{
  x = -  twoPi_ *  twoPi_ * K_[0] * v *
    (scale_[1] * E1_[0] * cos(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[0] * sin(twoPi_ * (u - 0.5)));
  y = -  twoPi_ *  twoPi_ * K_[0] * v *
    (scale_[1] * E1_[1] * cos(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[1] * sin(twoPi_ * (u - 0.5)));
  z = -  twoPi_ *  twoPi_ * K_[0] * v *
    (scale_[1] * E1_[2] * cos(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[2] * sin(twoPi_ * (u - 0.5)));
}

void ParaboloidProjectionSurface::Dfdfdudv
(double u, double v, double &x, double &y, double &z)
{
  x = K_[0] * twoPi_ * (- scale_[1] * E1_[0] * sin(twoPi_ * (u - 0.5)) + 
			scale_[2] * E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = K_[0] * twoPi_ * (- scale_[1] * E1_[1] * sin(twoPi_ * (u - 0.5)) + 
			scale_[2] * E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = K_[0] * twoPi_ * (- scale_[1] * E1_[2] * sin(twoPi_ * (u - 0.5)) + 
			scale_[2] * E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void ParaboloidProjectionSurface::Dfdfdvdv
(double u, double v, double &x, double &y, double &z)
{
  x = 2. * K_[1] * scale_[0] * E0_[0];
  y = 2. * K_[1] * scale_[0] * E0_[1];
  z = 2. * K_[1] * scale_[0] * E0_[2];
}

void ParaboloidProjectionSurface::Dfdfdfdududu
(double u,double v,double &x,double &y,double &z)
{
  x = twoPi_ *  twoPi_ * twoPi_ * K_[0] * v *
    (scale_[1] * E1_[0] * sin(twoPi_ * (u - 0.5)) - 
     scale_[2] * E2_[0] * cos(twoPi_ * (u - 0.5)));
  y = twoPi_ *  twoPi_ * twoPi_ * K_[0] * v *
    (scale_[1] * E1_[1] * sin(twoPi_ * (u - 0.5)) - 
     scale_[2] * E2_[1] * cos(twoPi_ * (u - 0.5)));
  z = twoPi_ *  twoPi_ * twoPi_ * K_[0] * v *
    (scale_[1] * E1_[2] * sin(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[2] * cos(twoPi_ * (u - 0.5)));
}

void ParaboloidProjectionSurface::Dfdfdfdududv
(double u,double v,double &x,double &y,double &z)
{
  x = -  twoPi_ *  twoPi_ * K_[0] *
    (scale_[1] * E1_[0] * cos(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[0] * sin(twoPi_ * (u - 0.5)));
  y = -  twoPi_ *  twoPi_ * K_[0]  *
    (scale_[1] * E1_[1] * cos(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[1] * sin(twoPi_ * (u - 0.5)));
  z = -  twoPi_ *  twoPi_ * K_[0] *
    (scale_[1] * E1_[2] * cos(twoPi_ * (u - 0.5)) + 
     scale_[2] * E2_[2] * sin(twoPi_ * (u - 0.5)));
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
    /*
    double xP,yP,zP;
    double minDist = 1.e12;
    for (int i=0;i<root.size();i++) {
      F(u,root[i],xP,yP,zP);
      double dist = sqrt((x-xP)*(x-xP)+(y-yP)*(y-yP)+(z-zP)*(z-zP));
      if (dist < minDist) {
	minDist = dist;
	v = root[i];
      }
    }
    */
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
}

void ParaboloidProjectionSurface::
SetParameter(int i, double x)
{
  switch (i) {
  case 0:
    K_[0] = x;
  case 1:
    K_[1] = x;
  }
}

double ParaboloidProjectionSurface::
GetParameter(int i)
{
  switch (i) {
  case 0:
    return K_[0];
  case 1:
    return K_[1];
  }
}

std::string ParaboloidProjectionSurface::
GetLabel(int i)
{
  switch (i) {
  case 0:
    return std::string("Parabola Scale 1");
  case 1:
    return std::string("Parabola Scale 2");
  }
}
