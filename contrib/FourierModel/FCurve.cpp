#include "FCurve.h"

FCurve::FCurve
(int tag, Patch* patch) 
  : Curve(tag)
{
  patch_ = patch;

  // default end points
  SP_[0] = SP_[1] = 0.;
  EP_[0] = 1.; EP_[1] = 0.;
}

FCurve::FCurve
(int tag, Patch* patch, double SP[2], double EP[2]) 
  : Curve(tag)
{
  patch_ = patch;

  SP_[0] = SP[0]; SP_[1] = SP[1];
  EP_[0] = EP[0]; EP_[1] = EP[1];
}

double FCurve::GetPou
(double t)
{
  return 1.;
}

void FCurve::F
(double t, double &x, double &y, double &z)
{
  double u = SP_[0] + t * (EP_[0] - SP_[0]);
  double v = SP_[1] + t * (EP_[1] - SP_[1]);

  patch_->F(u,v,x,y,z);
}

bool FCurve::Inverse
(double x, double y, double z, double &t)
{
  double u, v;
  if (patch_->Inverse(x,y,z,u,v)) {
    if (std::abs(EP_[0] - SP_[0]) > 1.e-12)
      t = (u - SP_[0]) / (EP_[0] - SP_[0]);
    else if (std::abs(EP_[1] - SP_[1]) > 1.e-12)
      t = (v - SP_[1]) / (EP_[1] - SP_[1]);
    else
      t = 0.;
    return true;
  }
  else
    return false;
}

void FCurve::Dfdt
(double t, double &x, double &y, double &z)
{
  double u = SP_[0] + t * (EP_[0] - SP_[0]);
  double v = SP_[1] + t * (EP_[1] - SP_[1]);

  double dfdu[3], dfdv[3];
  patch_->Dfdu(u,v,dfdu[0],dfdu[1],dfdu[2]);
  patch_->Dfdv(u,v,dfdv[0],dfdv[1],dfdv[2]);

  x = dfdu[0] * (EP_[0] - SP_[0]) + dfdv[0] * (EP_[1] - SP_[1]);
  y = dfdu[1] * (EP_[0] - SP_[0]) + dfdv[1] * (EP_[1] - SP_[1]);
  z = dfdu[2] * (EP_[0] - SP_[0]) + dfdv[2] * (EP_[1] - SP_[1]);
}

void FCurve::Dfdfdtdt
(double t, double &x, double &y, double &z)
{
  double u = SP_[0] + t * (EP_[0] - SP_[0]);
  double v = SP_[1] + t * (EP_[1] - SP_[1]);

  double dfdfdudu[3], dfdfdudv[3], dfdfdvdv[3];
  patch_->Dfdfdudu(u,v,dfdfdudu[0],dfdfdudu[1],dfdfdudu[2]);
  patch_->Dfdfdudv(u,v,dfdfdudv[0],dfdfdudv[1],dfdfdudv[2]);
  patch_->Dfdfdvdv(u,v,dfdfdvdv[0],dfdfdvdv[1],dfdfdvdv[2]);  

  x = 
    dfdfdudu[0] * (EP_[0] - SP_[0]) * (EP_[0] - SP_[0]) +
    dfdfdudv[0] * (EP_[0] - SP_[0]) * (EP_[1] - SP_[1]) * 2. +
    dfdfdvdv[0] * (EP_[1] - SP_[1]) * (EP_[1] - SP_[1]);
  y = 
    dfdfdudu[1] * (EP_[0] - SP_[0]) * (EP_[0] - SP_[0]) +
    dfdfdudv[1] * (EP_[0] - SP_[0]) * (EP_[1] - SP_[1]) * 2. +
    dfdfdvdv[1] * (EP_[1] - SP_[1]) * (EP_[1] - SP_[1]);
  z = 
    dfdfdudu[2] * (EP_[0] - SP_[0]) * (EP_[0] - SP_[0]) +
    dfdfdudv[2] * (EP_[0] - SP_[0]) * (EP_[1] - SP_[1]) * 2. +
    dfdfdvdv[2] * (EP_[1] - SP_[1]) * (EP_[1] - SP_[1]);
}
