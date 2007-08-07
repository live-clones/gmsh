#ifndef _REVOLVED_PARABOLA_PROJECTION_SURFACE_H_
#define _REVOLVED_PARABOLA_PROJECTION_SURFACE_H_

#include <cmath>
#include <vector>
#include "Utils.h"
#include "ProjectionSurface.h"

namespace FM {

class RevolvedParabolaProjectionSurface : public ProjectionSurface {
 private:
  double twoPi_;
  double R_, K_[2];
 public:
  RevolvedParabolaProjectionSurface
    (int tag);
  RevolvedParabolaProjectionSurface
    (int tag, double O[3], double E0[3], double E1[3], double scale[3],
     double R, double K[2]);
  RevolvedParabolaProjectionSurface(RevolvedParabolaProjectionSurface *ps) 
    : ProjectionSurface(ps) 
  {
    twoPi_ = ps->twoPi_;
    R_ = ps->R_;
    K_[0] = ps->K_[0];
    K_[1] = ps->K_[1];
  }

  virtual ~RevolvedParabolaProjectionSurface
    () {}

  virtual ProjectionSurface *clone()
  {
    return new RevolvedParabolaProjectionSurface(this);
  }

  // Abstract methods of ProjectionSurface

  virtual void F
    (double u, double v, double &x, double &y, double &z);
  virtual bool Inverse
    (double x,double y,double z,double &u,double &v);
  virtual void Dfdu
    (double u, double v, double &x, double &y, double &z);
  virtual void Dfdv
    (double u, double v, double &x, double &y, double &z);
  virtual void Dfdfdudu
    (double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdudv
    (double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdvdv
    (double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdfdududu
    (double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdfdududv
    (double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdfdudvdv
    (double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdfdvdvdv
    (double u,double v,double &x,double &y,double &z);
  virtual bool OrthoProjectionOnSurface
    (double x, double y, double z, double &u,double &v);
  virtual void SetParameter
    (int i, double x);
  virtual double GetParameter
    (int i);
  virtual std::string GetLabel
    (int i);
};

}

#endif
