#ifndef _EXACT_PATCH_H_
#define _EXACT_PATCH_H_

#include "Patch.h"
#include "FM_Info.h"
#include "ProjectionSurface.h"

// The base class for the patches
class ExactPatch : public Patch {
 public:
  ExactPatch(PatchInfo* PI, ProjectionSurface* ps);
  virtual ~ExactPatch() {}

  PatchInfo* _PI;

  // These are the virtual functions that must be provided by all
  // derived patches: GetPou() returns the original smooth
  // (non-normalized) cutoff on the patch; F() and Inverse() implement
  // the mapping f: (u,v)->(x,y,z) and its inverse; and the Df*() and Dn*()
  // functions return the derivatives of the mapping f and unit normal n 
  // with respect to u and v
  virtual double GetPou(double u, double v);
  virtual void F(double u, double v, double &x, double &y, double &z);
  virtual bool Inverse(double x,double y,double z,double &u,double &v);
  virtual void Dfdu(double u, double v, double &x, double &y, double &z);
  virtual void Dfdv(double u, double v, double &x, double &y, double &z);
  virtual void Dfdfdudu(double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdudv(double u,double v,double &x,double &y,double &z);
  virtual void Dfdfdvdv(double u,double v,double &x,double &y,double &z);
};
#endif
