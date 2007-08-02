#include <vector>
#include <math.h>
#include <complex>
#include "Interpolator2D.h"

extern "C" {
  void zgelss_(int &,int &,int &,std::complex<double> *,int &,
	       std::complex<double> *,int &,double *,double &,int &,
	       std::complex<double> *,int &,double *,int &);
}

FftPolyInterpolator2D::
FftPolyInterpolator2D(const std::vector<double> &u, 
		      const std::vector<double> &v,
		      const std::vector< std::vector< std::complex<double> > > 
		      &data, int refineFactor, int polyOrder, int derivative)
  : _refineFactor(refineFactor), _polyOrder(polyOrder), _derivative(derivative),
    _uFine(0), _vFine(0), _fineData(0), _fineDerivU(0), _fineDerivV(0), 
    _fineDerivUU(0), _fineDerivVV(0), _fineDerivUV(0)
{
  _uIntervals = u.size() - 1;
  _uFineIntervals = _refineFactor * _uIntervals;
  _vIntervals = v.size() - 1;
  _vFineIntervals = _refineFactor * _vIntervals;

  // min/max of input mesh
  if(u[_uIntervals] > u[0]) {
    _uMin = u[0];
    _uMax = u[_uIntervals];
  } 
  else {
    _uMin = u[_uIntervals];
    _uMax = u[0];
  }
  if(v[_vIntervals] > u[0]) {
    _vMin = v[0];
    _vMax = v[_vIntervals];
  } 
  else {
    _vMin = u[_vIntervals];
    _vMax = u[0];
  }

  // signed length of interval
  _uLength = u[_uIntervals] - u[0];
  _vLength = v[_vIntervals] - v[0];

  // Sanity checks
  if(std::abs(data[0][0] - data[_uIntervals][0]) > 1.e-10 ||
     std::abs(data[0][0] - data[0][_vIntervals]) > 1.e-10) {
    Msg::Warning("Data is not periodic");
  }
  if(fabs(u[1] - u[0]) - fabs(u[2] - u[1]) > 1.e-10 ||
     fabs(v[1] - v[0]) - fabs(v[2] - v[1]) > 1.e-10){
    Msg::Fatal("Input grid is not equispaced");
  }
  if((_uFineIntervals < _polyOrder) || (_vFineIntervals < _polyOrder)){
    Msg::Fatal("Number of intervals is smaller than polynomial order (%d < %d or %d < %d)",
               _uFineIntervals, _polyOrder, _vFineIntervals, _polyOrder);
  }

  // Compute the fine grid spacing (assuming the u and v are equally spaced)
  _hUFine = (u[1] - u[0]) / _refineFactor;
  _hVFine = (v[1] - v[0]) / _refineFactor;
  
  // Compute the points on the fine grid
  _uFine = new double[_uFineIntervals + 1];
  for(int i = 0; i < _uFineIntervals + 1; i++)
    _uFine[i] = u[0] + i * _hUFine;
  
  _vFine = new double[_vFineIntervals + 1];
  for(int i = 0; i < _vFineIntervals + 1; i++)
    _vFine[i] = v[0] + i * _hVFine;
  
  // Initialize _fineData to zero
  _fineData = new std::complex<double>*[_uFineIntervals + 1];
  for(int i = 0; i < _uFineIntervals + 1; i++){
    _fineData[i] = new std::complex<double>[_vFineIntervals + 1];
    for(int j = 0; j < _vFineIntervals + 1; j++)
      _fineData[i][j] = 0.;
  }

  std::complex<double> **forwardData = new std::complex<double>*[_uIntervals + 1];
  for(int i = 0; i < _uIntervals + 1; i++)
    forwardData[i] = new std::complex<double>[_vIntervals + 1];
  
  if (_refineFactor == 1){ // No Fourier interpolation
    // Copy data into _fineData
    for(int i = 0; i < _uFineIntervals + 1; i++)
      for(int j = 0; j < _vFineIntervals + 1; j++)
	_fineData[i][j] = data[i][j];
  }
  else {
    // Compute the forward FFT of the two dimensional data (only uses
    // data in i=0,...,uIntervals-1 and j=0,...,vIntervals-1 and
    // scales by 1/(uIntervals*vIntervals))
    for(int i = 0; i < _uIntervals + 1; i++)
      for(int j = 0; j < _vIntervals + 1; j++)
	forwardData[i][j] = data[i][j];
    _ForwardFft(_uIntervals + 1, _vIntervals + 1, forwardData);
    
    // Copy the Fourier coefficients into _fineData
    int halfIndexU = _uIntervals / 2;
    int halfIndexV = _vIntervals / 2;
    for(int i = 0; i < _uIntervals; i++)
      for(int j = 0; j < _vIntervals; j++){
	int iFine = i;
	int jFine = j;
	if(i > halfIndexU)
	  iFine = _uFineIntervals + (i - _uIntervals);
	if(j > halfIndexV)
	  jFine = _vFineIntervals + (j - _vIntervals);
	_fineData[iFine][jFine] = forwardData[i][j];
      }
    
    // Compute inverse FFT on _fineData to interpolate the data on the
    // fine grid
    _BackwardFft(_uFineIntervals + 1, _vFineIntervals + 1, _fineData);
  }

  // Check if we need to interpolate the derivative(s)
  if(_derivative){
    if(_refineFactor == 1){
      // No Fourier interpolation was performed, so we need to do it here...
      for(int i = 0; i < _uIntervals + 1; i++)
	for(int j = 0; j < _vIntervals + 1; j++)
	  forwardData[i][j] = data[i][j];
      _ForwardFft(_uIntervals + 1, _vIntervals + 1, forwardData);
    }
    
    // Initialize _fineDeriv and _fineDeriv2 to zero
    if(_derivative & 1){
      _fineDerivU = new std::complex<double>*[_uFineIntervals + 1];
      _fineDerivV = new std::complex<double>*[_uFineIntervals + 1];
      for(int i = 0; i < _uFineIntervals + 1; i++){
	_fineDerivU[i] = new std::complex<double>[_vFineIntervals + 1];
	_fineDerivV[i] = new std::complex<double>[_vFineIntervals + 1];
	for(int j = 0; j < _vFineIntervals + 1; j++){
	  _fineDerivU[i][j] = 0.;
	  _fineDerivV[i][j] = 0.;
	}
      }
    }
    
    if(_derivative & 2){
      _fineDerivUU = new std::complex<double>*[_uFineIntervals + 1];
      _fineDerivVV = new std::complex<double>*[_uFineIntervals + 1];
      _fineDerivUV = new std::complex<double>*[_uFineIntervals + 1];
      for(int i = 0; i < _uFineIntervals + 1; i++){
	_fineDerivUU[i] = new std::complex<double>[_vFineIntervals + 1];
	_fineDerivVV[i] = new std::complex<double>[_vFineIntervals + 1];
	_fineDerivUV[i] = new std::complex<double>[_vFineIntervals + 1];
	for(int j = 0; j < _vFineIntervals + 1; j++){
	  _fineDerivUU[i][j] = 0.;
	  _fineDerivVV[i][j] = 0.;
	  _fineDerivUV[i][j] = 0.;
	}
      }
    }

    // Copy the Fourier coefficients into _fineDeriv and _fineDeriv2
    std::complex<double> I(0., 1.);
    int halfIndexU = _uIntervals / 2;
    int halfIndexV = _vIntervals / 2;
    for(int i = 0; i < _uIntervals; i++){
      for(int j = 0; j < _vIntervals; j++){
	int iFine = i;
	int jFine = j;
	double kU = i;
	double kV = j;
	if(i > halfIndexU){
	  kU = i - _uIntervals;
	  iFine = _uFineIntervals + (i - _uIntervals);
	}
	if(j > halfIndexV){
	  kV = j - _vIntervals;
	  jFine = _vFineIntervals + (j - _vIntervals);
	}
	if(_derivative & 1){
	  _fineDerivU[iFine][jFine] = (2. * M_PI * kU * I) * forwardData[i][j] / _uLength;
	  _fineDerivV[iFine][jFine] = (2. * M_PI * kV * I) * forwardData[i][j] / _vLength;
	}
	if(_derivative & 2){
	  _fineDerivUU[iFine][jFine] = 
	    -(4. * M_PI * M_PI * kU * kU) * forwardData[i][j] / (_uLength * _uLength);
	  _fineDerivVV[iFine][jFine] = 
	    -(4. * M_PI * M_PI * kV * kV) * forwardData[i][j] / (_vLength * _vLength);
	  _fineDerivUV[iFine][jFine] = 
	    -(4. * M_PI * M_PI * kU * kV) * forwardData[i][j] / (_uLength * _vLength);
	}
      }
    }
    
    // Perform an inverse FFT on _fineDeriv to interpolate the
    // derivative to the fine grid
    if(_derivative & 1){
      _BackwardFft(_uFineIntervals + 1, _vFineIntervals + 1, _fineDerivU);
      _BackwardFft(_uFineIntervals + 1, _vFineIntervals + 1, _fineDerivV);
    }
    if(_derivative & 2){
      _BackwardFft(_uFineIntervals + 1, _vFineIntervals + 1, _fineDerivUU);
      _BackwardFft(_uFineIntervals + 1, _vFineIntervals + 1, _fineDerivVV);
      _BackwardFft(_uFineIntervals + 1, _vFineIntervals + 1, _fineDerivUV);
    }
  }

  for(int i = 0; i < _uIntervals + 1; i++)
    delete [] forwardData[i];
  delete [] forwardData;

  // Initialize interpolation variables
  _tmpSpace = new double[_polyOrder + 1];
  _tmpValsReal = new double[_polyOrder + 1];
  _tmpValsImag = new double[_polyOrder + 1];
  _tmpInterpReal = new double[_polyOrder + 1];
  _tmpInterpImag = new double[_polyOrder + 1];
}

FftPolyInterpolator2D::~FftPolyInterpolator2D()
{
  delete[] _uFine; 
  delete[] _vFine; 

  for(int i = 0; i < _uFineIntervals + 1; i++)
    delete [] _fineData[i];
  delete [] _fineData;

  if(_fineDerivU){
    for(int i = 0; i < _uFineIntervals + 1; i++)
      delete [] _fineDerivU[i];
    delete [] _fineDerivU;
  }
  if(_fineDerivV){
    for(int i = 0; i < _uFineIntervals + 1; i++)
      delete [] _fineDerivV[i];
    delete [] _fineDerivV;
  }
  if(_fineDerivUU){
    for(int i = 0; i < _uFineIntervals + 1; i++)
      delete [] _fineDerivUU[i];
    delete [] _fineDerivUU;
  }
  if(_fineDerivVV){
    for(int i = 0; i < _uFineIntervals + 1; i++)
      delete [] _fineDerivVV[i];
    delete [] _fineDerivVV;
  }
  if(_fineDerivUV){
    for(int i = 0; i < _uFineIntervals + 1; i++)
      delete [] _fineDerivUV[i];
    delete [] _fineDerivUV;
  }
  
  delete[] _tmpSpace;
  delete[] _tmpValsReal;
  delete[] _tmpValsImag;
  delete[] _tmpInterpReal;
  delete[] _tmpInterpImag;
}

int FftPolyInterpolator2D::_forwardSizeU = 0;
int FftPolyInterpolator2D::_forwardSizeV = 0;
int FftPolyInterpolator2D::_backwardSizeU = 0;
int FftPolyInterpolator2D::_backwardSizeV = 0;
fftw_plan FftPolyInterpolator2D::_forwardPlan;
fftw_plan FftPolyInterpolator2D::_backwardPlan;
fftw_complex *FftPolyInterpolator2D::_forwardData = 0;
fftw_complex *FftPolyInterpolator2D::_backwardData = 0;

void FftPolyInterpolator2D::_SetForwardPlan(int n, int m)
{
  if(n != _forwardSizeU || m != _forwardSizeV){
    if(_forwardSizeU || _forwardSizeV){
      fftw_destroy_plan(_forwardPlan);
      fftw_free(_forwardData);
    }
    _forwardSizeU = n;
    _forwardSizeV = m;
    _forwardData = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) *
					      _forwardSizeU * _forwardSizeV);
    _forwardPlan = fftw_plan_dft_2d(_forwardSizeU, _forwardSizeV, 
				    _forwardData, _forwardData,
				    FFTW_FORWARD, FFTW_ESTIMATE);
  }
}

void FftPolyInterpolator2D::_SetBackwardPlan(int n, int m)
{
  if(n != _backwardSizeU || m != _backwardSizeV){
    if(_backwardSizeU || _backwardSizeV){
      fftw_destroy_plan(_backwardPlan);
      fftw_free(_backwardData);
    }
    _backwardSizeU = n;
    _backwardSizeV = m;
    _backwardData = (fftw_complex*)fftw_malloc(sizeof(fftw_complex) *
					      _backwardSizeU * _backwardSizeV);
    _backwardPlan = fftw_plan_dft_2d(_backwardSizeU, _backwardSizeV, 
				    _backwardData, _backwardData,
				    FFTW_BACKWARD, FFTW_ESTIMATE);
  }
}

void FftPolyInterpolator2D::_ForwardFft(int n, int m, std::complex<double> **fftData)
{
  // Initialize fftw plan and array (ignoring the last row and column
  // of fftData, which should just be the periodic extension)
  _SetForwardPlan(n - 1, m - 1);
  int k = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      _forwardData[k][0] = fftData[i][j].real();
      _forwardData[k][1] = fftData[i][j].imag();
      k++;
    }
  }
  
  // Perform forward FFT
  fftw_execute(_forwardPlan);

  // Copy data back into fftData and scale by 1/((n-1) * (m-1))
  double s = 1. / (double)((n - 1) * (m - 1));
  k = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      fftData[i][j] = s * std::complex<double>(_forwardData[k][0], _forwardData[k][1]);
      k++;
    }
  }
}

void FftPolyInterpolator2D::_BackwardFft(int n, int m, std::complex<double> **fftData)
{
  // Initialize fftw plan and array (ignoring last row and column of fftData)
  _SetBackwardPlan(n - 1, m - 1);
  int k = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      _backwardData[k][0] = fftData[i][j].real();
      _backwardData[k][1] = fftData[i][j].imag();
      k++;
    }
  }

  // Perform backward FFT
  fftw_execute(_backwardPlan);

  // Copy data back into fftData 
  k = 0;
  for(int i = 0; i < n - 1; i++){
    for(int j = 0; j < m - 1; j++){
      fftData[i][j] = std::complex<double>(_backwardData[k][0], _backwardData[k][1]);
      k++;
    }
  }

  // Fill in last row and column with copy of first row and column
  for(int i = 0; i <= n - 1; i++)
    fftData[i][m - 1] = fftData[i][0];
  for(int j = 0; j <= m - 1; j++)
    fftData[n - 1][j] = fftData[0][j];
}

double FftPolyInterpolator2D::_PolyInterp(double start, double h, const double *vals, 
					  double t, double *space)
{
  // Neville's Algorithm from Stoer and Bulirsch, Section 2.1.2
  double tmp = (t - start)/h;
  for(int i = 0; i <= _polyOrder; i++){
    space[i] = vals[i];
    for(int j = i - 1; j >= 0; j--)
      space[j] = space[j + 1] + (space[j + 1] - space[j]) * ((tmp - i) / (i - j));
  }
  return space[0];
}

std::complex<double> FftPolyInterpolator2D::_Interpolate(double u, double v,
							 int uDer, int vDer)
{
  if( ( (uDer == 2 || vDer == 2 || (uDer == 1 && vDer == 1)) && !(_derivative & 2) ) ||
      ( (uDer == 1 || vDer == 1) && !(_derivative & 1) ) ||
      (uDer < 0 || uDer > 2 || vDer < 0 || vDer > 2) ){
    Msg::Error("Derivative data not available: check contructor call %d %d %d",uDer,vDer,_derivative);
    return 0.;
  }

  double epsilon = 1e-12;
  if(u < _uMin - epsilon || u > _uMax + epsilon){
    Msg::Error("Trying to interpolate outside interval: (u,v)=(%.16g,%.16g) "
	       "not in [%g,%g]x[%g,%g]", u, v, _uMin, _uMax, _vMin, _vMax);
    return 0.;
  }

  // Choose uIndexStart and vIndexStart so that (u,v) is centered in
  // the polynomial interpolation grid
  int uIndexStart = (int)floor((u - _uFine[0]) / _hUFine) - _polyOrder / 2;
  if(uIndexStart < 0)
    uIndexStart = 0;
  else if((uIndexStart + _polyOrder) > _uFineIntervals)
    uIndexStart = _uFineIntervals - _polyOrder;

  int vIndexStart = (int)floor((v - _vFine[0]) / _hVFine) - _polyOrder / 2;
  if(vIndexStart < 0)
    vIndexStart = 0;
  else if((vIndexStart + _polyOrder) > _vFineIntervals)
    vIndexStart = _vFineIntervals - _polyOrder;
  
  // Interpolate to find value at (u,v)
  double start = _vFine[vIndexStart];
  for(int i = 0; i <= _polyOrder; i++){
    for(int j = 0; j <= _polyOrder; j++){
      std::complex<double> tmp;
      if(uDer == 0 && vDer == 0)
	tmp = _fineData[uIndexStart + i][vIndexStart + j];
      else if(uDer == 1 && vDer == 0)
	tmp = _fineDerivU[uIndexStart + i][vIndexStart + j];
      else if(uDer == 0 && vDer == 1)
	tmp = _fineDerivV[uIndexStart + i][vIndexStart + j];
      else if(uDer == 2 && vDer == 0)
	tmp = _fineDerivUU[uIndexStart + i][vIndexStart + j];
      else if(uDer == 0 && vDer == 2)
	tmp = _fineDerivVV[uIndexStart + i][vIndexStart + j];
      else
	tmp = _fineDerivUV[uIndexStart + i][vIndexStart + j];
      _tmpValsReal[j] = tmp.real();
      _tmpValsImag[j] = tmp.imag();
    }
    _tmpInterpReal[i] = _PolyInterp(start, _hVFine, _tmpValsReal, v, _tmpSpace);
    _tmpInterpImag[i] = _PolyInterp(start, _hVFine, _tmpValsImag, v, _tmpSpace);
  }
  
  start = _uFine[uIndexStart];
  return std::complex<double>(_PolyInterp(start, _hUFine, _tmpInterpReal, u, _tmpSpace), 
			      _PolyInterp(start, _hUFine, _tmpInterpImag, u, _tmpSpace));
}

std::complex<double> FftPolyInterpolator2D::F(double u, double v)
{
  return _Interpolate(u, v, 0, 0);
}

std::complex<double> FftPolyInterpolator2D::Dfdu(double u, double v)
{
  return _Interpolate(u, v, 1, 0);
}

std::complex<double> FftPolyInterpolator2D::Dfdv(double u, double v)
{
  return _Interpolate(u, v, 0, 1);
}

std::complex<double> FftPolyInterpolator2D::Dfdfdudu(double u, double v)
{
  return _Interpolate(u, v, 2, 0);
}

std::complex<double> FftPolyInterpolator2D::Dfdfdvdv(double u, double v)
{
  return _Interpolate(u, v, 0, 2);
}

std::complex<double> FftPolyInterpolator2D::Dfdfdudv(double u, double v)
{
  return _Interpolate(u, v, 1, 1);
}



FourierContinuationInterpolator2D::FourierContinuationInterpolator2D
(const std::vector<double> &u, const std::vector<double> &v,
 const std::vector< std::complex<double> > &data, 
 int derivative, int uModes, int vModes, double periodU, double periodV)
  : _derivative(derivative), _uModes(uModes), _vModes(vModes), 
    _periodU(periodU), _periodV(periodV),
    _coeffData(0), _coeffDerivU(0), _coeffDerivV(0), _coeffDerivUU(0), 
    _coeffDerivVV(0), _coeffDerivUV(0)
{ 
  // sanity check
  if (!((u.size() == v.size()) && (v.size() == data.size()))) {
    Msg::Fatal("Input data of unequal size.");
  }
  _nData = data.size();
  _nModes = _uModes * _vModes;

  for (int i=0;i<_nData;i++) {
    _u.push_back(u[i]);
    _v.push_back(v[i]);
  }

  // Initialize _Data to zero
  _coeffData = new std::complex<double>*[_uModes];
  for(int j = 0; j < _uModes; j++){
    _coeffData[j] = new std::complex<double>[_vModes];
    for(int k = 0; k < _vModes; k++)
      _coeffData[j][k] = 0.;
  }

  if ((_uModes % 2) == 0) {
    _uModesLower = - _uModes/2;
    _uModesUpper = _uModes/2 - 1;
  }
  else {
    _uModesLower = - (_uModes - 1)/2;
    _uModesUpper = (_uModes - 1)/2;
  }
  if ((_vModes % 2) == 0) {
    _vModesLower = - _vModes/2;
    _vModesUpper = _vModes/2 - 1;
  }
  else {
    _vModesLower = - (_vModes - 1)/2;
    _vModesUpper = (_vModes - 1)/2;
  }

  std::complex<double> *LSRhs = new std::complex<double> [_nData];
  std::complex<double> *LSMatrix = new std::complex<double> [_nModes * _nData];

  for (int i=0;i<_nData;i++)
    LSRhs[i] = data[i];

  for (int j=0;j<_uModes;j++)
    for (int k=0;k<_vModes;k++)
      for (int i=0;i<_nData;i++)
	LSMatrix[i+_nData*(k+_vModes*j)] = std::complex<double>
	  (cos(2*M_PI * ((j + _uModesLower) * u[i] / _periodU + 
			 (k + _vModesLower) * v[i] / _periodV)),
	   sin(2*M_PI * ((j + _uModesLower) * u[i] / _periodU + 
			 (k + _vModesLower) * v[i] / _periodV)));

  // some parameters for the lease square solvers "zgelss"
  int info, rank;
  int lwork = 66*_nData, one = 1;
  double rcond = -1.;
  double *s = new double [_nModes];
  double *rwork = new double [5*_nModes];
  std::complex<double> *work = new std::complex<double> [lwork];

  zgelss_(_nData,_nModes,one,&LSMatrix[0],_nData,&LSRhs[0],_nData,&s[0],rcond,
	  rank,&work[0],lwork,&rwork[0],info);

  for(int j = 0; j < _uModes; j++)
    for(int k = 0; k < _vModes; k++)
      _coeffData[j][k] = LSRhs[k+_vModes*j];

  // deleting lease square arrays
  delete[] s, rwork, work;
  delete[] LSMatrix, LSRhs;

  // Check if we need to interpolate the derivative(s)
  if(_derivative){
    // Initialize _fineDeriv and _fineDeriv2 to zero
    if(_derivative & 1){
      _coeffDerivU = new std::complex<double>*[_uModes];
      _coeffDerivV = new std::complex<double>*[_uModes];
      for(int j = 0; j < _uModes; j++){
	_coeffDerivU[j] = new std::complex<double>[_vModes];
	_coeffDerivV[j] = new std::complex<double>[_vModes];
	for(int k = 0; k < _vModes; k++){
	  _coeffDerivU[j][k] = 0.;
	  _coeffDerivV[j][k] = 0.;
	}
      }
    }
    
    if(_derivative & 2){
      _coeffDerivUU = new std::complex<double>*[_uModes];
      _coeffDerivVV = new std::complex<double>*[_uModes];
      _coeffDerivUV = new std::complex<double>*[_uModes];
      for(int j = 0; j < _uModes; j++){
	_coeffDerivUU[j] = new std::complex<double>[_vModes];
	_coeffDerivVV[j] = new std::complex<double>[_vModes];
	_coeffDerivUV[j] = new std::complex<double>[_vModes];
	for(int k = 0; k < _vModes; k++){
	  _coeffDerivUU[j][k] = 0.;
	  _coeffDerivVV[j][k] = 0.;
	  _coeffDerivUV[j][k] = 0.;
	}
      }
    }
    
    // Copy the Fourier coefficients into _coeffDeriv and _coeffDeriv2
    std::complex<double> I(0., 1.);
    for(int j = 0; j < _uModes; j++){
      for(int k = 0; k < _vModes; k++){
	int J = j+_uModesLower;
	int K = k+_vModesLower;
	if(_derivative & 1){
	  _coeffDerivU[j][k] = (2 * M_PI * J * I / _periodU) *_coeffData[j][k];
	  _coeffDerivV[j][k] = (2 * M_PI * K * I / _periodV) *_coeffData[j][k];
	}
	if(_derivative & 2){
	  _coeffDerivUU[j][k] = - (4 * M_PI * M_PI * J * J / 
				   (_periodU * _periodU)) * _coeffData[j][k];
	  _coeffDerivVV[j][k] = - (4 * M_PI * M_PI * K * K /
				   (_periodV * _periodV)) * _coeffData[j][k];
	  _coeffDerivUV[j][k] = - (4 * M_PI * M_PI * J * K /
				   (_periodU * _periodV)) * _coeffData[j][k];
	}
      }
    }
  }    
  // Initialize interpolation variables
  _tmpCoeff = std::vector< std::complex<double> >(_vModes);
  _tmpInterp = std::vector< std::complex<double> >(_uModes);
}

FourierContinuationInterpolator2D::~FourierContinuationInterpolator2D()
{
  for(int j = 0; j < _uModes; j++)
    delete [] _coeffData[j];
  delete [] _coeffData;

  if(_coeffDerivU){
    for(int j = 0; j < _uModes; j++)
      delete [] _coeffDerivU[j];
    delete [] _coeffDerivU;
  }
  if(_coeffDerivV){
    for(int j = 0; j < _uModes; j++)
      delete [] _coeffDerivV[j];
    delete [] _coeffDerivV;
  }
  if(_coeffDerivUU){
    for(int j = 0; j < _uModes; j++)
      delete [] _coeffDerivUU[j];
    delete [] _coeffDerivUU;
  }
  if(_coeffDerivVV){
    for(int j = 0; j < _uModes; j++)
      delete [] _coeffDerivVV[j];
    delete [] _coeffDerivVV;
  }
  if(_coeffDerivUV){
    for(int j = 0; j < _uModes; j++)
      delete [] _coeffDerivUV[j];
    delete [] _coeffDerivUV;
  }
}

std::complex<double> FourierContinuationInterpolator2D::
_PolyEval(std::vector< std::complex<double> > _coeff, std::complex<double> x)
{
  int _polyOrder = _coeff.size()-1;
  std::complex<double> out = 0.;

  out = x * _coeff[_polyOrder];
  for (int i = _polyOrder - 1; i > 0; i--)
    out = x * (out + _coeff[i]);
  out = out + _coeff[0];
  
  return out;
}

std::complex<double> FourierContinuationInterpolator2D::
  _Interpolate(double u, double v, int uDer, int vDer)
{
  //Msg::Info("%d %d %d",uDer,vDer,_derivative);
  if (((uDer==2 || vDer==2 || (uDer==1 && vDer==1)) && !(_derivative & 2) ) || 
      ((uDer==1 || vDer==1) && !(_derivative & 1)) ||
      (uDer<0 || uDer>2 || vDer<0 || vDer>2) ) {
    Msg::Error("Derivative data not available: check contructor call %d %d %d",
	       uDer,vDer,_derivative);
    return 0.;
  }

  double epsilon = 1e-12;
  if(u < 0. - epsilon || u > 1. + epsilon){
    Msg::Error("Trying to interpolate outside interval: (u,v)=(%.16g,%.16g) "
	       "not in [%g,%g]x[%g,%g]", u, v, 0., 1., 0., 1.);
    return 0.;
  }

  // Interpolate to find value at (u,v)
  for(int j = 0; j < _uModes; j++){
    for(int k = 0; k < _vModes; k++){
      std::complex<double> tmp;
      if(uDer == 0 && vDer == 0)
	tmp = _coeffData[j][k];
      else if(uDer == 1 && vDer == 0)
	tmp = _coeffDerivU[j][k];
      else if(uDer == 0 && vDer == 1)
	tmp = _coeffDerivV[j][k];
      else if(uDer == 2 && vDer == 0)
	tmp = _coeffDerivUU[j][k];
      else if(uDer == 0 && vDer == 2)
	tmp = _coeffDerivVV[j][k];
      else
	tmp = _coeffDerivUV[j][k];
      _tmpCoeff[k] = tmp;
    }
    std::complex<double> y(cos(2 * M_PI * v / _periodV), 
			   sin(2 * M_PI * v / _periodV));
    _tmpInterp[j] = _PolyEval(_tmpCoeff, y);
    _tmpInterp[j] *= std::complex<double>
      (cos(2 * M_PI * _vModesLower * v / _periodV), 
       sin(2 * M_PI * _vModesLower * v / _periodV));
  }
  std::complex<double> x(cos(2 * M_PI * u / _periodU), 
			 sin(2 * M_PI * u / _periodU));
  return _PolyEval(_tmpInterp, x) * std::complex<double>
    (cos(2 * M_PI * _uModesLower * u / _periodU),
     sin(2 * M_PI * _uModesLower * u / _periodU));
}

std::complex<double> FourierContinuationInterpolator2D::F(double u, double v)
{
  return _Interpolate(u, v, 0, 0);
}

std::complex<double> FourierContinuationInterpolator2D::Dfdu(double u, double v)
{
  return _Interpolate(u, v, 1, 0);
}

std::complex<double> FourierContinuationInterpolator2D::Dfdv(double u, double v)
{
  return _Interpolate(u, v, 0, 1);
}

std::complex<double> FourierContinuationInterpolator2D::Dfdfdudu(double u, double v)
{
  return _Interpolate(u, v, 2, 0);
}

std::complex<double> FourierContinuationInterpolator2D::Dfdfdvdv(double u, double v)
{
  return _Interpolate(u, v, 0, 2);
}

std::complex<double> FourierContinuationInterpolator2D::Dfdfdudv
(double u, double v)
{
  return _Interpolate(u, v, 1, 1);
}

bool FourierContinuationInterpolator2D::IsPointInInterpolationRange
(double u, double v)
{
  double nbdRadius = 1.e-2;
  bool status = false;
  for (int i=0;i<_nData;i++) {
    double tmp = sqrt((u - _u[i])*(u - _u[i])+(v - _v[i])*(v - _v[i]));
    if (tmp < nbdRadius) {
      status = true;
      break;
    }
  }
  return status;
}

int FourierContinuationInterpolator2D::GetDataSize()
{
  return _nData;
}
