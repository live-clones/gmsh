#ifndef _INTERPOLATOR_2D_H_
#define _INTERPOLATOR_2D_H_

#include <vector>
#include <complex>
#include <fftw3.h>
#include "Message.h"

// The base class for the 2D interpolators
class Interpolator2D {
 public:
  Interpolator2D(){}
  virtual ~Interpolator2D(){}
  // interpolates the data at u,v
  virtual std::complex<double> F(double u, double v) = 0;
  // interpolates the first u derivative of the data at u,v
  virtual std::complex<double> Dfdu(double u, double v)
  {
    Msg::Error("First derivative not implemented for this interpolator");
    return 0.; 
  }
  // interpolates the first v derivative of the data at u,v
  virtual std::complex<double> Dfdv(double u, double v)
  {
    Msg::Error("First derivative not implemented for this interpolator");
    return 0.; 
  }
  // interpolates the second u derivative of the data at u,v
  virtual std::complex<double> Dfdfdudu(double u, double v)
  {
    Msg::Error("Second derivative not implemented for this interpolator");
    return 0.; 
  }
  // interpolates the second v derivative of the data at u,v
  virtual std::complex<double> Dfdfdvdv(double u, double v)
  {
    Msg::Error("Second derivative not implemented for this interpolator");
    return 0.; 
  }
  // interpolates the second cross derivative of the data at u,v
  virtual std::complex<double> Dfdfdudv(double u, double v)
  {
    Msg::Error("Second derivative not implemented for this interpolator");
    return 0.; 
  }
  // checks if the interpolation point is good enough
  virtual bool IsPointInInterpolationRange(double u, double v)
  {
    Msg::Error("Goodness check not implemented for this interpolator");
    return 0; 
  }
  // returns the size of interpolation data
  virtual int GetDataSize()
  {
    Msg::Error("GetDataSize not implemented for this interpolator");
    return 0;
  }
};

// FFT + polynomial interpolation on refined grid (assumes that the
// input grid is equally spaced and the input data is periodic)
class FftPolyInterpolator2D : public Interpolator2D {
 private:
  // refinement factor (e.g. 16; if equal to 1, we just perform
  // standard piecewise polynomial interpolation, without any FFTs)
  int _refineFactor;
  // order of the interpolating polynomial
  int _polyOrder;
  // signed length of the interval
  double _uLength, _vLength;
  // temporary interpolation variables
  double *_tmpSpace, *_tmpValsReal, *_tmpValsImag, *_tmpInterpReal, *_tmpInterpImag;
  // 1D polynomial interpolation routine
  double _PolyInterp(double start, double h, const double *vals, 
		     double t, double *space);
  // interpolation wrapper
  std::complex<double> _Interpolate(double u, double v, int uDer=0, int vDer=0);
  // persistent fftw data (used to avoid recomputing the FFTW plans
  // and reallocating memory every time)
  static int _forwardSizeU, _forwardSizeV;
  static int _backwardSizeU, _backwardSizeV;
  static fftw_plan _forwardPlan, _backwardPlan;
  static fftw_complex *_forwardData, *_backwardData;
  void _SetForwardPlan(int n, int m);
  void _SetBackwardPlan(int n, int m);
 protected:
  // number of intervals in the original and in the refined mesh
  int _uIntervals, _vIntervals, _uFineIntervals, _vFineIntervals;
  // fine mesh spacing
  double _hUFine, _hVFine;
  // min/max of input mesh
  double _uMin, _uMax, _vMin, _vMax;
  // bitfield telling if we also interpolate the derivative(s)
  int _derivative;
  // grid points of the refined mesh
  double *_uFine, *_vFine;
  // data (and its first 2 derivatives) on the refined regular grid
  std::complex<double> **_fineData, **_fineDerivU, **_fineDerivV;
  std::complex<double> **_fineDerivUU, **_fineDerivVV, **_fineDerivUV;
  // This routine computes the forward FFT (ignoring the last row and
  // column of the data)
  void _ForwardFft(int n, int m, std::complex<double> **fftData);
  // This routine computes the inverse FFT (ignoring the last row and
  // column in the array), returns values in entire array (by using
  // the periodic extension)
  void _BackwardFft(int n, int m, std::complex<double> **fftData);
 public:
  FftPolyInterpolator2D(const std::vector<double> &u,
			const std::vector<double> &v,
			const std::vector<std::vector<std::complex<double> > >
			&data, int refineFactor=16, int polyOrder=3, 
			int derivative=0);
  ~FftPolyInterpolator2D();
  virtual std::complex<double> F(double u, double v);
  virtual std::complex<double> Dfdu(double u, double v);
  virtual std::complex<double> Dfdv(double u, double v);
  virtual std::complex<double> Dfdfdudu(double u, double v);
  virtual std::complex<double> Dfdfdvdv(double u, double v);
  virtual std::complex<double> Dfdfdudv(double u, double v);
};

// Fourier Continuation interpolation
class FourierContinuationInterpolator2D : public Interpolator2D {
 private:
  friend class Body;
  // u and v data
  std::vector<double> _u, _v;
  // temporary interpolation variables
  std::vector< std::complex<double> > _tmpCoeff, _tmpInterp;
 protected:
  // bitfield telling if we also interpolate the derivative(s)
  int _derivative;
  // Data Size
  int _nData;
  // Number of Fourier Modes
  int _uModes, _vModes, _nModes;
  // Period Information
  double _periodU, _periodV;
  // Limits of Fourier Series
  int _uModesLower, _uModesUpper, _vModesLower, _vModesUpper;
  // data (and its first 2 derivatives)
  std::complex<double> **_coeffData, **_coeffDerivU, **_coeffDerivV;
  std::complex<double> **_coeffDerivUU, **_coeffDerivVV, **_coeffDerivUV;
  // polynomial evaluator
  std::complex<double> _PolyEval(std::vector< std::complex<double> > _coeff, 
				 std::complex<double> x);
  // interpolation wrapper
  std::complex<double> _Interpolate(double u,double v,int uDer=0,int vDer=0);
 public:
  FourierContinuationInterpolator2D
    (const std::vector<double> &u, const std::vector<double> &v,
     const std::vector< std::complex<double> > &data,
     int derivative = 0, int uModes = 1, int vModes = 1, 
     double periodU = 2, double periodV = 2);
  ~FourierContinuationInterpolator2D();
  virtual std::complex<double> F(double u, double v);
  virtual std::complex<double> Dfdu(double u, double v);
  virtual std::complex<double> Dfdv(double u, double v);
  virtual std::complex<double> Dfdfdudu(double u, double v);
  virtual std::complex<double> Dfdfdvdv(double u, double v);
  virtual std::complex<double> Dfdfdudv(double u, double v);
  virtual bool IsPointInInterpolationRange(double u, double v);
  virtual int GetDataSize();
};

#endif
