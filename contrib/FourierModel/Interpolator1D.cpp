#include <vector>
#include <math.h>
#include <complex>
#include "Interpolator1D.h"

FftPolyInterpolator1D::FftPolyInterpolator1D(const std::vector<double> &u,
					     const std::vector< std::complex<double> > &data,
					     int refineFactor, int polyOrder, int derivative,
					     bool storeCoefs)
  : _refineFactor(refineFactor), _polyOrder(polyOrder), _derivative(derivative), 
    _storeCoefs(storeCoefs), _uFine(0), _fineData(0), _fineDeriv(0), _fineDeriv2(0)
{
  _uIntervals = u.size() - 1;
  _uFineIntervals = _refineFactor * _uIntervals;

  // min/max of input mesh
  if(u[_uIntervals] > u[0]) {
    _uMin = u[0];
    _uMax = u[_uIntervals];
  } 
  else {
    _uMin = u[_uIntervals];
    _uMax = u[0];
  }

  // signed length of interval
  _uLength = u[_uIntervals] - u[0];
  
  // Sanity checks
  if(std::abs(data[0] - data[_uIntervals]) > 1.e-10){
    Msg::Warning("Data is not periodic: f(%g)=(%.16g,%.16g), f(%g)=(%.16g,%.16g)",
		 u[0], data[0].real(), data[0].imag(),
		 u[_uIntervals], data[_uIntervals].real(), data[_uIntervals].imag());
  }
  if(fabs(u[1] - u[0]) - fabs(u[2] - u[1]) > 1.e-10){
    Msg::Fatal("Input grid is not equispaced");
  }
  if(_uFineIntervals < _polyOrder){
    Msg::Fatal("Number of intervals is smaller than polynomial order (%d < %d)",
	       _uFineIntervals, _polyOrder);
  }

  // Compute the fine grid spacing (assuming the u grid is equally spaced)
  _hUFine = (u[1] - u[0]) / _refineFactor;

  // Compute the points on the fine grid
  _uFine = new double[_uFineIntervals + 1];
  for(int i = 0; i < _uFineIntervals + 1; i++)
    _uFine[i] = u[0] + i * _hUFine;

  // Initialize _fineData to zero
  _fineData = new std::complex<double>[_uFineIntervals + 1];
  for(int i = 0; i < _uFineIntervals + 1; i++)
    _fineData[i] = 0.;

  if(_storeCoefs){
    // number of local interpolating polynomials
    _nLocPol = 1;
    int flag = 0;
    while ((flag + _polyOrder) < (_uFineIntervals + 1)) {
      _nLocPol++;
      flag += _polyOrder;
    }
    if ((_uFineIntervals + 1 - flag) == 1) _nLocPol--;
    
    // local interpolating polynomial coefficients
    _locpol = new std::complex<double>[_nLocPol * (_polyOrder + 1)];
    for(int i = 0; i < _nLocPol * (_polyOrder + 1); i++)
      _locpol[i] = 0.;
  }
  
  std::complex<double> *forwardData = new std::complex<double>[_uIntervals+1];

  if (_refineFactor == 1){ // No Fourier interpolation
    // Copy data into _fineData
    for(int i = 0; i < _uFineIntervals + 1; i++)
      _fineData[i] = data[i];
  }
  else {
    // Compute the forward FFT of the one-dimensional data (only uses
    // data in i=0,...,uIntervals-1 and scales by 1/uIntervals)
    for(int i = 0; i < _uIntervals + 1; i++)
      forwardData[i] = data[i];
    _ForwardFft(_uIntervals + 1, forwardData);
    
    // Copy the Fourier coefficients into _fineData
    int halfIndexU = _uIntervals / 2;
    for(int i = 0; i < _uIntervals; i++){
      int iFine = i;
      if(i > halfIndexU)
        iFine = _uFineIntervals + (i - _uIntervals);
      _fineData[iFine] = forwardData[i];
    }

    // Compute inverse FFT on _fineData to interpolate the data on the
    // fine grid
    _BackwardFft(_uFineIntervals + 1, _fineData);
  }

  // Check if we need to interpolate the derivative(s)
  if(_derivative){
    if(_refineFactor == 1){
      // No Fourier interpolation was performed, so we need to do it here...
      for(int i = 0; i < _uIntervals + 1; i++)
	forwardData[i] = data[i];
      _ForwardFft(_uIntervals + 1, forwardData);
    }

    // Initialize _fineDeriv and _fineDeriv2 to zero
    if(_derivative & 1){
      _fineDeriv = new std::complex<double>[_uFineIntervals + 1];
      for(int i = 0; i < _uFineIntervals + 1; i++)
	_fineDeriv[i] = 0.;
      if(_storeCoefs){
	// local interpolating polynomial coefficients
	_locpolDeriv = new std::complex<double>[_nLocPol*(_polyOrder+1)];
	for(int i = 0; i < _nLocPol*(_polyOrder+1); i++)
	  _locpolDeriv[i] = 0.;
      }
    }
    if(_derivative & 2){
      _fineDeriv2 = new std::complex<double>[_uFineIntervals + 1];
      for(int i = 0; i < _uFineIntervals + 1; i++)
	_fineDeriv2[i] = 0.;
      if(_storeCoefs){
	// local interpolating polynomial coefficients
	_locpolDeriv2 = new std::complex<double>[_nLocPol*(_polyOrder+1)];
	for(int i = 0; i < _nLocPol*(_polyOrder+1); i++)
	  _locpolDeriv2[i] = 0.;
      }
    }

    // Copy the Fourier coefficients into _fineDeriv and _fineDeriv2
    std::complex<double> I(0., 1.);
    int halfIndexU = _uIntervals / 2;
    for(int i = 0; i < _uIntervals; i++){
      int iFine = i;
      double k = i;
      if(i > halfIndexU){
	k = i - _uIntervals;
	iFine = _uFineIntervals + (i - _uIntervals);
      }
      // multiply by (2*pi*i*k) to get the derivative
      if(_derivative & 1)
	_fineDeriv[iFine] = (2. * M_PI * k * I) * forwardData[i] / _uLength;
      // multiply by (2*pi*i*k)^2 to get the second derivative
      if(_derivative & 2)
	_fineDeriv2[iFine] = 
	  -(4. * M_PI * M_PI * k * k) * forwardData[i] / (_uLength * _uLength);
    }

    // Perform an inverse FFT on _fineDeriv to interpolate the
    // derivative to the fine grid
    if(_derivative & 1)
      _BackwardFft(_uFineIntervals + 1, _fineDeriv);
    if(_derivative & 2)
      _BackwardFft(_uFineIntervals + 1, _fineDeriv2);
  }

  delete [] forwardData;

  if(_storeCoefs){
    _interPolyCoeff(_locpol, _fineData, _uFineIntervals, _hUFine, _polyOrder);
    if(_derivative & 1)
      _interPolyCoeff(_locpolDeriv, _fineDeriv, _uFineIntervals, _hUFine, 
		      _polyOrder);
    if(_derivative & 2)
      _interPolyCoeff(_locpolDeriv2, _fineDeriv2, _uFineIntervals, _hUFine, 
		      _polyOrder);
  }

  // Initialize temp interpolation variables
  _tmpInterp = new double[_polyOrder + 1];
  _tmpPnts = new double[_polyOrder + 1];
  _tmpValsReal = new double[_polyOrder + 1];
  _tmpValsImag = new double[_polyOrder + 1];
}

FftPolyInterpolator1D::~FftPolyInterpolator1D()
{
  delete[] _uFine;
  delete[] _fineData;
  if(_storeCoefs)
    delete[] _locpol;
  if(_fineDeriv) {
    delete[] _fineDeriv; 
    if(_storeCoefs)
      delete[] _locpolDeriv;
  }
  if(_fineDeriv2) {
    delete[] _fineDeriv2; 
    if(_storeCoefs)
      delete[] _locpolDeriv2;
  }
  
  delete[] _tmpInterp;
  delete[] _tmpPnts; 
  delete[] _tmpValsReal; 
  delete[] _tmpValsImag;
}

int FftPolyInterpolator1D::_forwardSize = 0;
int FftPolyInterpolator1D::_backwardSize = 0;
fftw_plan FftPolyInterpolator1D::_forwardPlan;
fftw_plan FftPolyInterpolator1D::_backwardPlan;
fftw_complex *FftPolyInterpolator1D::_forwardData = 0;
fftw_complex *FftPolyInterpolator1D::_backwardData = 0;

void FftPolyInterpolator1D::_SetForwardPlan(int n)
{
  if(n != _forwardSize){
    if(_forwardSize){
      fftw_destroy_plan(_forwardPlan);
      fftw_free(_forwardData);
    }
    _forwardSize = n;
    _forwardData = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * _forwardSize);
    _forwardPlan = fftw_plan_dft_1d(_forwardSize, _forwardData, _forwardData,
				    FFTW_FORWARD, FFTW_ESTIMATE);
  }
}

void FftPolyInterpolator1D::_SetBackwardPlan(int n)
{
  if(n != _backwardSize){
    if(_backwardSize){
      fftw_destroy_plan(_backwardPlan);
      fftw_free(_backwardData);
    }
    _backwardSize = n;
    _backwardData = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * _backwardSize);
    _backwardPlan = fftw_plan_dft_1d(_backwardSize, _backwardData, _backwardData,
				     FFTW_BACKWARD, FFTW_ESTIMATE);
  }
}

void FftPolyInterpolator1D::_ForwardFft(int n, std::complex<double> *fftData)
{
  // Initialize fftw plan and array (ignoring the last element of
  // fftData, which should just be the periodic extension)
  _SetForwardPlan(n - 1);
  for(int i = 0; i < n - 1; i++){
    _forwardData[i][0] = fftData[i].real();
    _forwardData[i][1] = fftData[i].imag();
  }

  // Perform forward FFT
  fftw_execute(_forwardPlan);

  // Copy data back into fftData and scale by 1/(n - 1)
  double s = 1. / (double)(n - 1);
  for(int i = 0; i < n - 1; i++)
    fftData[i] = s * std::complex<double>(_forwardData[i][0], _forwardData[i][1]);
}

void FftPolyInterpolator1D::_BackwardFft(int n, std::complex<double> *fftData)
{
  // Initialize fftw plan and array (ignoring last element of fftData)
  _SetBackwardPlan(n - 1);
  for(int i = 0; i < n - 1; i++){
    _backwardData[i][0] = fftData[i].real();
    _backwardData[i][1] = fftData[i].imag();
  }

  // Perform backward FFT
  fftw_execute(_backwardPlan);

  // Copy data back into fftData
  for(int i = 0; i < n - 1; i++)
    fftData[i] = std::complex<double>(_backwardData[i][0], _backwardData[i][1]);

  // Fill in last element with copy of first element
  fftData[n - 1] = fftData[0];
}

double FftPolyInterpolator1D::_PolyInterp(double *pnts, double *vals, double t)
{
  // Neville's Algorithm from Stoer and Bulirsch, Section 2.1.2
  for(int i = 0; i <= _polyOrder; i++){
    _tmpInterp[i] = vals[i];
    for(int j = i-1; j >= 0; j--)
      _tmpInterp[j] = _tmpInterp[j+1] +
        (_tmpInterp[j+1] - _tmpInterp[j]) * (t - pnts[i]) / (pnts[i] - pnts[j]);
  }
  return _tmpInterp[0];
}

std::complex<double> FftPolyInterpolator1D::_Interpolate(double u, int derivative)
{
  if((derivative == 1 && !(_derivative & 1)) ||
     (derivative == 2 && !(_derivative & 2)) ||
     derivative < 0 || derivative > 2){
    Msg::Error("Derivative data not available: check constructor call");
    return 0.;
  }

  if(u == _uMax)
    u = _uMin;

  double epsilon = 1e-12;
  if(u < _uMin - epsilon || u > _uMax + epsilon){
    Msg::Error("Trying to interpolate outside interval: u=%.16g not in [%g,%g]", 
	       u, _uMin, _uMax);
    return 0.;
  }

  // Choose uIndexStart so that u is centered in the polynomial
  // interpolation grid
  int uIndexStart = (int)floor((u - _uFine[0]) / _hUFine) - _polyOrder / 2;
  if(uIndexStart < 0)
    uIndexStart = 0;
  else if((uIndexStart + _polyOrder) > _uFineIntervals)
    uIndexStart = _uFineIntervals - _polyOrder;
  
  // Interpolate to find value at u
  for(int i = 0; i <= _polyOrder; i++){
    _tmpPnts[i] = _uFine[uIndexStart + i];
    if(derivative == 0){
      _tmpValsReal[i] = _fineData[uIndexStart + i].real();
      _tmpValsImag[i] = _fineData[uIndexStart + i].imag();
    }
    else if(derivative == 1){
      _tmpValsReal[i] = _fineDeriv[uIndexStart + i].real();
      _tmpValsImag[i] = _fineDeriv[uIndexStart + i].imag();
    }
    else{
      _tmpValsReal[i] = _fineDeriv2[uIndexStart + i].real();
      _tmpValsImag[i] = _fineDeriv2[uIndexStart + i].imag();
    }
  }

  return std::complex<double>(_PolyInterp(_tmpPnts, _tmpValsReal, u),
			      _PolyInterp(_tmpPnts, _tmpValsImag, u));
}

void polyint(double *xa, double *ya, int n, double x, double &y)
{
#define ind(ii) ((ii) - 1)
  int i, m, ns = 1;
  double dy, den, dif, dift, ho, hp, w;
 
  double *c = new double[n];
  double *d = new double[n];
  
  dif = fabs(x - xa[ind(1)]);
  for (i = 1; i <= n; i++) {
    if ((dift = fabs(x - xa[ind(i)])) < dif) {
      ns = i;
      dif = dift;
    }
    c[ind(i)] = ya[ind(i)];
    d[ind(i)] = ya[ind(i)];
  }
  y = ya[ind(ns--)];
  for (m = 1; m < n; m++) {
    for (i = 1; i <= n - m; i++) {
      ho = xa[ind(i)] - x;
      hp = xa[ind(i + m)] - x;
      w = c[ind(i + 1)] - d[ind(i)];
      if ((den = ho - hp) == 0) {
	Msg::Error("Error in POLYINT");
        return;
      }
      den = w / den;
      d[ind(i)] = hp * den;
      c[ind(i)] = ho * den;
    }
    if (2 * ns < (n - m))
      dy = c[ind(ns + 1)];
    else {
      dy = d[ind(ns)];
      ns--;
    }
    y += dy;
  }
  delete[] c;
  delete[] d;
}

void polcof(double *x, double *y, int n, double *cof)
{ 
  int k;
  double xmin;
  
  double *xtemp = new double[n + 1];
  double *ytemp = new double[n + 1];
  
  for (int j = 0; j <= n; j++) {
    xtemp[j] = x[j];
    ytemp[j] = y[j];
  }
  for (int j = 0; j <= n; j++) {
    polyint(xtemp, ytemp, n + 1 - j, 0.0, cof[j]);
    xmin = 1.0e38;
    k = -1;
    for (int i = 0; i <= n - j; i++) {
      if (fabs(xtemp[i]) < xmin) {
        xmin = fabs(xtemp[i]);
        k = i;
      }
      if (xtemp[i] != 0) ytemp[i] = (ytemp[i] - cof[j]) / xtemp[i];
    }
    for (int i = k + 1; i<= n - j; i++) {
      xtemp[i - 1] = xtemp[i];
      ytemp[i - 1] = ytemp[i];
    }
  }
  delete[] xtemp;
  delete[] ytemp;
}

void getcoeff(double *f,double *x,int n)
{
  double *ya = new double[n];
  double *cof = new double[n];

  for (int i = 0; i < n; i++) {
    ya[i] = f[i];
  }
  polcof(x, ya, n - 1, cof);
  for (int i = 0; i < n; i++)
    f[i] = cof[i];

  delete[] ya;
  delete[] cof;
}

void FftPolyInterpolator1D::_interPolyCoeff(std::complex<double> *locpol,
					    std::complex<double> *u,
					    int rn, double fineh, int npoly)
{
  double *x = new double[npoly + 1];
  double *freal = new double[npoly + 1];
  double *fimag = new double[npoly + 1];
  int rem;

  int l = 0;
  int flag = 0;
  while ((flag + npoly) < rn) {
    for (int i = 0; i <= npoly; i++)
      x[i] = (flag + i) * fineh;
      for (int i = 0; i <= npoly; i++) {
	freal[i] = real(u[flag + i]);
	fimag[i] = imag(u[flag + i]);
      }
      getcoeff(freal, x, npoly + 1);
      getcoeff(fimag, x, npoly + 1);
      for (int i = 0; i < npoly + 1; i++)
	locpol[(npoly + 1) * l + i] = std::complex<double>(freal[i], fimag[i]);
    l++;
    flag += npoly;
  }

  rem = rn - flag;
  if (rem > 1) {
    for (int i = 0; i <= npoly; i++)
      x[i] = (flag + i - (npoly + 1) + rem) * fineh;
    for (int i=0;i<=npoly;i++) {
      freal[i] = real(u[flag + i - (npoly + 1) + rem]);
      fimag[i] = imag(u[flag + i - (npoly + 1) + rem]);
    }
    getcoeff(freal, x, npoly + 1);
    getcoeff(fimag, x, npoly + 1);
    for (int i = 0; i < npoly + 1; i++)
      locpol[(npoly + 1) * l + i] = std::complex<double>(freal[i], fimag[i]);
  }
  
  delete[] x;
  delete[] freal;
  delete[] fimag;
}

std::complex<double> FftPolyInterpolator1D::_InterpolateFromCoeffs(double u, 
								   int derivative)
{
  if((derivative == 1 && !(_derivative & 1)) ||
     (derivative == 2 && !(_derivative & 2)) ||
     derivative < 0 || derivative > 2){
    Msg::Error("Derivative data not available: check constructor call");
    return 0.;
  }

  if(u == _uMax)
    u = _uMin;

  double epsilon = 1e-12;
  if(u < _uMin - epsilon || u > _uMax + epsilon){
    Msg::Error("Trying to interpolate outside interval: u=%.16g not in [%g,%g]", 
	       u, _uMin, _uMax);
    return 0.;
  }
  
  std::complex<double> out(0.,0.);
  
  // find the polynomial to be used for interpolating at u
  int l = (int)floor((u - _uFine[0])/(_polyOrder * _hUFine));

  if (derivative == 0) {
    out = u * _locpol[(_polyOrder + 1) * l + _polyOrder];
    for (int r = _polyOrder - 1; r > 0; r--)
      out = u * (out + _locpol[(_polyOrder + 1) * l + r]);
    out = out + _locpol[(_polyOrder + 1) * l + 0];
  }
  else if (derivative == 1) {
    out = u * _locpolDeriv[(_polyOrder + 1) * l + _polyOrder];
    for (int r = _polyOrder - 1; r > 0 ; r--)
      out = u * (out + _locpolDeriv[(_polyOrder + 1) * l + r]);
    out = out + _locpolDeriv[(_polyOrder + 1) * l + 0];
  }
  else if (derivative == 2) {
    out = u * _locpolDeriv2[(_polyOrder + 1) * l + _polyOrder];
    for (int r = _polyOrder - 1; r > 0; r--)
      out = u * (out + _locpolDeriv2[(_polyOrder + 1) * l + r]);
    out = out + _locpolDeriv2[(_polyOrder + 1) * l + 0];
  }

  return out;
}

std::complex<double> FftPolyInterpolator1D::F(double u)
{
  if(_storeCoefs) 
    return _InterpolateFromCoeffs(u, 0);
  else
    return _Interpolate(u, 0);
}

std::complex<double> FftPolyInterpolator1D::Dfdu(double u)
{
  if(_storeCoefs) 
    return _InterpolateFromCoeffs(u, 1);
  else
    return _Interpolate(u, 1);
}

std::complex<double> FftPolyInterpolator1D::Dfdfdudu(double u)
{
  if(_storeCoefs) 
    return _InterpolateFromCoeffs(u, 2);
  else
    return _Interpolate(u, 2);
}

std::complex<double> FftPolyInterpolator1D::Integrate()
{
  std::complex<double> value(0., 0.);
  for(int i = 0; i < _uFineIntervals; i++){
    value += (0.5 * _fineData[i] + 0.5 * _fineData[i + 1]) * 
      fabs(_uFine[i + 1] - _uFine[i]);
  }
  return value;
}

FftSplineInterpolator1D::FftSplineInterpolator1D(const std::vector<double> &u,
						 const std::vector< std::complex<double> > &data,
						 int refineFactor)
  : FftPolyInterpolator1D(u, data, refineFactor, 3, 2)
{
}

std::complex<double> FftSplineInterpolator1D::_SplineInterp(double *pnts,
							    std::complex<double> *vals,
							    std::complex<double> *deriv,
							    double t)
{
  double h = pnts[1] - pnts[0];
  double a = (pnts[1] - t) / h;
  double b = (t - pnts[0]) / h;
  double a1 = a * a * a - a;
  double b1 = b * b * b - b;
  double h1 = (h * h) / 6.;
  return a * vals[0] + b * vals[1] + (a1 * deriv[0] + b1 * deriv[1]) * h1;
}

std::complex<double> FftSplineInterpolator1D::F(double u)
{
  double pnts[2];
  std::complex<double> vals[2], deriv[2];

  double epsilon = 1e-12;
  if(u < _uMin - epsilon || u > _uMax + epsilon){
    Msg::Error("Trying to interpolate outside interval: u=%.16g not in [%g,%g]", 
	       u, _uMin, _uMax);
    return 0.;
  }

  // Get indices of grid points surrounding u
  int uIndexStart = (int)floor((u - _uFine[0]) / _hUFine);
  if(uIndexStart < 0)
    uIndexStart = 0;
  else if(uIndexStart > _uFineIntervals - 1)
    uIndexStart = _uFineIntervals - 1;

  pnts[0] = _uFine[uIndexStart];
  pnts[1] = _uFine[uIndexStart + 1];
  vals[0] = _fineData[uIndexStart];
  vals[1] = _fineData[uIndexStart + 1];
  deriv[0] = _fineDeriv2[uIndexStart];
  deriv[1] = _fineDeriv2[uIndexStart + 1];

  return _SplineInterp(pnts, vals, deriv, u);
}
