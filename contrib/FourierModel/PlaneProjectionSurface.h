#ifndef _PLANE_PROJECTION_SURFACE_H_
#define _PLANE_PROJECTION_SURFACE_H_

#include <cmath>
#include "ProjectionSurface.h"

namespace FM {

class PlaneProjectionSurface : public ProjectionSurface {
 public:
  PlaneProjectionSurface
    (int tag);
  PlaneProjectionSurface
    (int tag, double O[3], double E0[3], double E1[3], double scale[3]);
  PlaneProjectionSurface(PlaneProjectionSurface *ps) 
    : ProjectionSurface(ps) {}

  virtual ~PlaneProjectionSurface
    () {}

  virtual ProjectionSurface *clone()
  {
    return new PlaneProjectionSurface(this);
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

  // Redefinitions for PlaneProjectionSurface

  virtual void GetNormal
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndu
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndv
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndndudu
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndndudv
    (double u, double v, double &x, double &y, double &z);
  virtual void Dndndvdv
    (double u, double v, double &x, double &y, double &z);
};

}

#endif
