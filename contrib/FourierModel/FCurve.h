#ifndef _F_CURVE_H_
#define _F_CURVE_H_

#include "Curve.h"
#include "Patch.h"

namespace FM {

// The base class for the patches
class FCurve : public Curve {
 protected:
  // Underlying Patch
  Patch* patch_;
  // End Points
  double SP_[2],EP_[2];

 public:
  FCurve(int tag, Patch* patch);
  FCurve(int tag, Patch* patch, double SP[2], double EP[2]);  
  virtual ~FCurve() {}

  void SetStartPoint
    (double u, double v) 
  { 
    SP_[0] = u; SP_[1] = v; 
  }
  void GetStartPoint
    (double &u, double &v) 
  { 
    u = SP_[0]; v = SP_[1]; 
  }
  void SetEndPoint
    (double u, double v) 
  { 
    EP_[0] = u; EP_[1] = v; 
  }
  void GetEndPoint
    (double &u, double &v) 
  { 
    u = EP_[0]; v = EP_[1]; 
  }

  // These are the virtual functions that must be provided by all
  // derived patches: GetPou() returns the original smooth
  // (non-normalized) cutoff on the patch; F() and Inverse() implement
  // the mapping f: (t)->(x,y,z) and its inverse; and the Df*() and Dn*()
  // functions return the derivatives of the mapping f and unit normal n 
  // with respect to u and v

  virtual double GetPou
    (double t);
  virtual void F
    (double t, double &x, double &y, double &z);
  virtual bool Inverse
    (double x,double y,double z,double &t);
  virtual void Dfdt
    (double t, double &x, double &y, double &z);
  virtual void Dfdfdtdt
    (double t, double &x, double &y, double &z);
};

}

#endif
