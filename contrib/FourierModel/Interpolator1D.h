#ifndef _INTERPOLATOR_1D_H_
#define _INTERPOLATOR_1D_H_

#include <vector>
#include <complex>
#include <fftw3.h>
#include "Message.h"

// The base class for the 1D interpolators
class Interpolator1D {
 public:
  Interpolator1D(){}
  virtual ~Interpolator1D(){}
  // interpolates the data at u
  virtual std::complex<double> F(double u) = 0;
  // interpolates the first derivative of the data at u
  virtual std::complex<double> Dfdu(double u) = 0;
  // interpolates the second derivative of the data at u
  virtual std::complex<double> Dfdfdudu(double u) = 0;
};

// FFT + polynomial interpolation on refined grid (assumes that the
// input grid is equally spaced and the input data is periodic)
class FftPolyInterpolator1D : public Interpolator1D {
 private:
  // refinement factor (e.g. 16; if equal to 1, we just perform
  // standard piecewise polynomial interpolation, without any FFTs)
  int _refineFactor;
  // order of the interpolating polynomial
  int _polyOrder;
  // signed length of the interval
  double _uLength;
  // temporary interpolation variables
  double *_tmpInterp, *_tmpPnts, *_tmpValsReal, *_tmpValsImag;
  // interpolation polynomial coefficients computation routine
  void _interPolyCoeff(std::complex<double> *locpol, std::complex<double> *u,
		       int rn,double fineh,int npoly);
  // 1D polynomial interpolation routine
  double _PolyInterp(double *pnts, double *vals, double t);
  // interpolation wrappers
  std::complex<double> _Interpolate(double u, int derivative=0);
  std::complex<double> _InterpolateFromCoeffs(double u, int derivative=0);
  // persistent fftw data (used to avoid recomputing the FFTW plans
  // and reallocating memory every time)
  static int _forwardSize, _backwardSize;
  static fftw_plan _forwardPlan, _backwardPlan;
  static fftw_complex *_forwardData, *_backwardData;
  void _SetForwardPlan(int n);
  void _SetBackwardPlan(int n);
 protected:
  // number of intervals in the original and in the refined mesh
  int _uIntervals, _uFineIntervals;
  // fine mesh spacing
  double _hUFine;
  // min/max of input mesh
  double _uMin, _uMax;
  // bitfield telling if we also interpolate the derivative(s)
  int _derivative;
  // flag set if we should store the polynomial coefficients
  bool _storeCoefs;
  // grid points of the refined mesh
  double *_uFine;
  // data (and its first 2 derivatives) on the refined regular grid
  std::complex<double> *_fineData, *_fineDeriv, *_fineDeriv2;
  // number of local interpolating polynomials
  int _nLocPol;
  // polynomial coefficients
  std::complex<double> *_locpol, *_locpolDeriv, *_locpolDeriv2;
  // This routine computes the forward FFT (ignoring the last element
  // of the data)
  void _ForwardFft(int n, std::complex<double> *fftData);
  // This routine computes the inverse FFT (ignoring the last element
  // in the array), returns values in entire array (by using the
  // periodic extension)
  void _BackwardFft(int n, std::complex<double> *fftData);
 public:
  FftPolyInterpolator1D(const std::vector<double> &u,
			const std::vector< std::complex<double> > &data,
			int refineFactor=16, int polyOrder=3, 
			int derivative=0, bool storeCoefs=true);
  ~FftPolyInterpolator1D();
  virtual std::complex<double> F(double u);
  virtual std::complex<double> Dfdu(double u);
  virtual std::complex<double> Dfdfdudu(double u);
  std::complex<double> Integrate();
};

// FFT + spline interpolation on refined grid
class FftSplineInterpolator1D : public FftPolyInterpolator1D {
 protected:
  // 1D spline interpolation
  std::complex<double> _SplineInterp(double *pnts,
				     std::complex<double> *vals,
				     std::complex<double> *deriv,
				     double t);
 public:
  FftSplineInterpolator1D(const std::vector<double> &u,
			  const std::vector< std::complex<double> > &data,
			  int refineFactor=16);
  ~FftSplineInterpolator1D(){}
  virtual std::complex<double> F(double u);
};

#endif
