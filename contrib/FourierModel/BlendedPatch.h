#ifndef _BLENDED_PATCH_H_
#define _BLENDED_PATCH_H_

#include <fftw3.h>
#include "Message.h"
#include "Patch.h"
#include "BlendOperator.h"
#include "PartitionOfUnity.h"

namespace FM {

class BlendedPatch {
 private:
  Patch* patch_;
  BlendOperator* blendOp_;

  int nPatches_;
  int patchTag_;

  bool IsUPeriodic, IsVPeriodic;

  // bitfield telling if we also interpolate the derivative(s)
  int _derivative;
  // Number of Modes in reprocessed Fourier/Chebyshev series
  int _uM, _vM;
   // Period Information
  double _periodU, _periodV;
  // Limits in the series
  int _uMLower, _uMUpper, _vMLower, _vMUpper;
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
  // other internal functions
  void _ProcessSeriesCoeff();
  // persistent fftw data (used to avoid recomputing the FFTW plans
  // and reallocating memory every time)
  static int _forwardSize, _backwardSize;
  static fftw_plan _forwardPlan, _backwardPlan;
  static fftw_complex *_forwardData, *_backwardData;
  void _SetForwardPlan(int n);
  void _SetBackwardPlan(int n);
  // This routine computes the forward FFT (ignoring the last element
  // of the data)
  void _ForwardFft(int n, std::complex<double> *fftData);
  // This routine computes the inverse FFT (ignoring the last element
  // in the array), returns values in entire array (by using the
  // periodic extension)
  void _BackwardFft(int n, std::complex<double> *fftData);

 protected:

 public:
  BlendedPatch(Patch* patch, BlendOperator* blendOp);
  ~BlendedPatch();

  double GetPou(double u, double v);

  void F
    (double u, double v, double &x, double &y, double &z);

  bool Inverse
    (double x,double y,double z,double &u,double &v);

  void Dfdu
    (double u, double v, double &x, double &y, double &z);

  void Dfdv
    (double u, double v, double &x, double &y, double &z);

  void Dfdfdudu
    (double u,double v,double &x,double &y,double &z);

  void Dfdfdudv
    (double u,double v,double &x,double &y,double &z);

  void Dfdfdvdv
    (double u,double v,double &x,double &y,double &z);

  void Dndu
    (double u, double v, double &x, double &y, double &z);

  void Dndv
    (double u, double v, double &x, double &y, double &z);

  void GetUnitNormal
    (double u,double v,double &x,double &y,double &z);

  void GetNormal
    (double u, double v, double &x, double &y, double &z);

  int GetTag
    () { return patchTag_; }
};

}

#endif
