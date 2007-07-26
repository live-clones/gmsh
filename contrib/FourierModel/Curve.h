#ifndef _CURVE_H_
#define _CURVE_H_

#include "Patch.h"
#include "FM_Info.h"

// The base class for the patches
class Curve {
 private:
  int _along;
  double _h, _tol;
 protected:
  // Patches
  Patch* _patch0;
  Patch* _patch1;
  // End Points
  double _SP0[2],_EP0[2];
  double _SP1[2],_EP1[2];

 public:
  // Intersection Information
  IntersectionInfo* _II;
  Curve(IntersectionInfo* II, std::vector<Patch*> patches);
  virtual ~Curve() {}

  // These are the virtual functions that must be provided by all
  // derived patches: GetPou() returns the original smooth
  // (non-normalized) cutoff on the patch; F() and Inverse() implement
  // the mapping f: (t)->(x,y,z) and its inverse; and the Df*() and Dn*()
  // functions return the derivatives of the mapping f and unit normal n 
  // with respect to u and v
  virtual double GetPou(double t);
  virtual int GetTag();
  virtual int GetEdgeType();
  virtual void GetEdgeParExtent(double &start, double &end);
  virtual void F(double t, double &x, double &y, double &z);
  virtual bool Inverse(double x,double y,double z,double &t);
};

#endif
