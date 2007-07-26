#ifndef _PATCH_H_
#define _PATCH_H_

#include <cmath>
#include "FM_Info.h"
#include "ProjectionSurface.h"

// The base class for the patches
class Patch {
 protected:
  // bitfield telling if we also interpolate the derivative(s)
  int _derivative;
  double _uMin, _uMax;
  double _vMin, _vMax;
  int _periodicityU, _periodicityV;
  ProjectionSurface* _ps;
 public:
  PatchInfo* _PI;
  Patch();
  Patch(PatchInfo* PI);
  virtual ~Patch() {}

  int GetTag();

  inline double GetMinU() { return _uMin; }
  inline double GetMaxU() { return _uMax; }
  inline double GetMinV() { return _vMin; }
  inline double GetMaxV() { return _vMax; }
  inline void SetMinU(double uMin) { _uMin = uMin; }
  inline void SetMaxU(double uMax) { _uMax = uMax; }
  inline void SetMinV(double vMin) { _vMin = vMin; }
  inline void SetMaxV(double vMax) { _vMax = vMax; }

  inline bool IsUPeriodic() 
    { if (_periodicityU) return true; else return false; }
  inline bool IsVPeriodic() 
    { if (_periodicityV) return true; else return false; }

  inline void SetPeriodicity(int pU, int pV) 
    { _periodicityU = pU; _periodicityV = pV; }

  inline double RescaleU(double u)
    {
      u = _uMin + u * (_uMax - _uMin);
      if (_periodicityU) {
	u -= std::floor(float(u));
      }
      return u;
    }
  inline double RescaleV(double v)
    {
      v = _vMin + v * (_vMax - _vMin);
      if (_periodicityV) {
	v -= std::floor(float(v));
      }
      return v;
    }

  inline double UnscaleU(double u)
    {
      u -= _uMin;
      //printf("u1 = %.16g\n",u);
      if (_periodicityU) {
	if ((std::abs(u) < 1.e-4)||(std::abs(u-1.) < 1.e-4)||
	    (std::abs(u+1.) < 1.e-4))
	  u -= std::floor(round(u));
	else
	  u -= std::floor(u);
      }
      //printf("u2 = %.16g\n",u);
      u /= (_uMax - _uMin);
      return u;
    }
  inline double UnscaleV(double v)
    {
      v -= _vMin;
      if (_periodicityV) {
	v -= std::floor(float(v));
      }
      v /= (_vMax - _vMin);
      return v;
    }

  inline int GetUModes() { return _PI->nM[0]; }
  inline int GetVModes() { return _PI->nM[1]; }
  inline int GetDerivativeBitField() { return _derivative; }

  inline ProjectionSurface* GetProjectionSurface() { return _ps; }
  inline void SetProjectionSurface(ProjectionSurface* ps) { _ps = ps; }

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
