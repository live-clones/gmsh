#ifndef _CONTUNATION_PATCH_H_
#define _CONTINUATION_PATCH_H_

#include "Patch.h"

// The base class for the patches
class ContinuationPatch : public Patch {
 private:
  // third axis
  double _NcrossT[3];
  // bitfield telling if we also interpolate the derivative(s)
  int _derivative;
  // Number of Fourier Modes
  int _uModes, _vModes;
   // Period Information
  double _periodU, _periodV;
  // Limits of Fourier Series
  int _uModesLower, _uModesUpper, _vModesLower, _vModesUpper;
  // data (and its first 2 derivatives)
  std::complex<double> **_coeffData, **_coeffDerivU, **_coeffDerivV;
  std::complex<double> **_coeffDerivUU, **_coeffDerivVV, **_coeffDerivUV;
  // temporary interpolation variables
  std::vector< std::complex<double> > _tmpCoeff, _tmpInterp;
  // polynomial evaluator
  std::complex<double> _PolyEval(std::vector< std::complex<double> > _coeff,
                                 std::complex<double> x);
  // interpolation wrapper
  std::complex<double> _Interpolate(double u,double v,int uDer=0,int vDer=0);
  void P(double u, double v, double &x, double &y, double &z,
	 double &nx, double &ny, double &nz);
  bool pInverse(double x,double y,double z,double &u,double &v);
  void Dpdu(double u, double v, double &x, double &y, double &z,
	    double &nx, double &ny, double &nz);
  void Dpdv(double u, double v, double &x, double &y, double &z,
	    double &nx, double &ny, double &nz);
  void Dpdpdudu(double u,double v,double &x,double &y,double &z,
		double &nx, double &ny, double &nz);
  void Dpdpdudv(double u,double v,double &x,double &y,double &z,
		double &nx, double &ny, double &nz);
  void Dpdpdvdv(double u,double v,double &x,double &y,double &z,
		double &nx, double &ny, double &nz);
 public:
  ContinuationPatch(PatchInfo* PI, int derivative = 0);
  virtual ~ContinuationPatch();

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
