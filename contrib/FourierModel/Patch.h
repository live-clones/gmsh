#ifndef _PATCH_H_
#define _PATCH_H_

#include "FM_Info.h"

// The base class for the patches
class Patch {
 public:
  PatchInfo* _PI;
  Patch() :_PI(0) {}
  Patch(PatchInfo* PI) : _PI(PI) {}
  virtual ~Patch() {}

  int GetTag();

  // These are the virtual functions that must be provided by all
  // derived patches: GetPou() returns the original smooth
  // (non-normalized) cutoff on the patch; F() and Inverse() implement
  // the mapping f: (u,v)->(x,y,z) and its inverse; and the Df*() and Dn*()
  // functions return the derivatives of the mapping f and unit normal n 
  // with respect to u and v
  virtual double GetPou(double u, double v) = 0;
  virtual void F(double u, double v, double &x, double &y, double &z) = 0;
  virtual bool Inverse(double x,double y,double z,double &u,double &v) = 0;
  virtual void Dfdu(double u, double v, double &x, double &y, double &z) = 0;
  virtual void Dfdv(double u, double v, double &x, double &y, double &z) = 0;
  virtual void Dfdfdudu(double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdudv(double u,double v,double &x,double &y,double &z) = 0;
  virtual void Dfdfdvdv(double u,double v,double &x,double &y,double &z) = 0;

  // These functions may also be provided by the derived patches
  // (usually for better performance), but they don't have to
  virtual void Dndu(double u, double v, double &x, double &y, double &z);
  virtual void Dndv(double u, double v, double &x, double &y, double &z);
  virtual void GetUnitNormal(double u,double v,double &x,double &y,double &z);
  virtual void GetNormal(double u, double v, double &x, double &y, double &z);

};

#endif
