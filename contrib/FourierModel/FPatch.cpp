#include <math.h>
#include "Message.h"
#include "FPatch.h"

extern "C" {
  void zgelss_(int &,int &,int &,std::complex<double> *,int &,
               std::complex<double> *,int &,double *,double &,int &,
               std::complex<double> *,int &,double *,int &);
}

FPatch::FPatch(int tag, ProjectionSurface* ps, 
	       std::vector<double> &u, std::vector<double> &v,
	       std::vector< std::complex<double> > &data, int derivative,
	       int uModes, int vModes, int uM, int vM,
	       bool hardEdge0, bool hardEdge1, bool hardEdge2, bool hardEdge3) 
  : _coeffOriginalData(0),_coeffData(0),_coeffDerivU(0),
    _coeffDerivV(0),_coeffDerivUU(0),_coeffDerivVV(0),_coeffDerivUV(0)
{
  _ps = ps;

  _tag = tag;
  _derivative = derivative;

  _uModes = uModes;
  _vModes = vModes;

  _uM = (int)(log((double)uM) / log(2.));
  _vM = (int)(log((double)vM) / log(2.));

  if (_ps->IsUPeriodic())
    _uM++;
  if (_ps->IsVPeriodic())
    _vM++;

  _hardEdge[0] = hardEdge0;
  _hardEdge[1] = hardEdge1;
  _hardEdge[2] = hardEdge2;
  _hardEdge[3] = hardEdge3;

  if (_ps->IsUPeriodic())
    _periodicityU = 1;
  if (_ps->IsVPeriodic())
    _periodicityV = 1;

  if (_ps->IsUPeriodic())
    _periodU = 1.;
  else
    _periodU = 2.;

  if (_ps->IsVPeriodic())
    _periodV = 1.;
  else
    _periodV = 2.;

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

  if (_ps->IsUPeriodic()) {
    if ((_uM % 2) == 0) {
      _uMLower = - _uM/2;
      _uMUpper = _uM/2 - 1;
    }
    else {
      _uMLower = - (_uM - 1)/2;
      _uMUpper = (_uM - 1)/2;
    }
  }
  else {
    _uMLower = 0;
    _uMUpper = _uM;
  }
  if (_ps->IsVPeriodic()) {
    if ((_vM % 2) == 0) {
      _vMLower = - _vM/2;
      _vMUpper = _vM/2 - 1;
    }
    else {
      _vMLower = - (_vM - 1)/2;
      _vMUpper = (_vM - 1)/2;
    }
  }
  else {
    _vMLower = 0;
    _vMUpper = _vM;    
  }


  // Initialize Data

  _coeffOriginalData = new std::complex<double>*[_uModes];
  for(int j = 0; j < _uModes; j++){
    _coeffOriginalData[j] = new std::complex<double>[_vModes];

    //for(int k = 0; k < _vModes; k++)
    //_coeffOriginalData[j][k] = _PI->coeff[j][k];
  }

  _nData = data.size();
  _nModes = _uModes * _vModes;

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
      _coeffOriginalData[j][k] = LSRhs[k+_vModes*j];

  // deleting lease square arrays
  delete[] s, rwork, work;
  delete[] LSMatrix, LSRhs;


  // Initialize interpolation variables
  _tmpOrigCoeff = std::vector< std::complex<double> >(_vModes);
  _tmpOrigInterp = std::vector< std::complex<double> >(_uModes);

  if (_derivative)
    _ReprocessSeriesCoeff();

  // Check if we need to interpolate the derivative(s)
  if(_derivative){
    // Initialize _fineDeriv and _fineDeriv2 to zero
    if(_derivative & 1){
      _coeffDerivU = new std::complex<double>*[_uM];
      _coeffDerivV = new std::complex<double>*[_uM];
      for(int j = 0; j < _uM; j++){
        _coeffDerivU[j] = new std::complex<double>[_vM];
        _coeffDerivV[j] = new std::complex<double>[_vM];
        for(int k = 0; k < _vM; k++){
          _coeffDerivU[j][k] = 0.;
          _coeffDerivV[j][k] = 0.;
        }
      }
    }

    if(_derivative & 2){
      _coeffDerivUU = new std::complex<double>*[_uM];
      _coeffDerivVV = new std::complex<double>*[_uM];
      _coeffDerivUV = new std::complex<double>*[_uM];
      for(int j = 0; j < _uM; j++){
        _coeffDerivUU[j] = new std::complex<double>[_vM];
        _coeffDerivVV[j] = new std::complex<double>[_vM];
        _coeffDerivUV[j] = new std::complex<double>[_vM];
        for(int k = 0; k < _vM; k++){
          _coeffDerivUU[j][k] = 0.;
          _coeffDerivVV[j][k] = 0.;
          _coeffDerivUV[j][k] = 0.;
        }
      }
    }

    // Copy the Fourier coefficients into _coeffDeriv and _coeffDeriv2
    std::complex<double> I(0., 1.);
    for(int j = _uM - 1; j >= 0; j--){
      for(int k = _vM - 1; k >= 0; k--){
        if(_derivative & 1){
	  if (_ps->IsUPeriodic()) {
	    int J = j+_uMLower;
	    _coeffDerivU[j][k] = (2 * M_PI * J * I / _periodU) *
	      _coeffData[j][k];
	  }
	  else {
	    if (j == _uM - 1)
	      _coeffDerivU[j][k] = 0.;
	    else if (j == _uM - 2)
	      _coeffDerivU[j][k] = 2. * (double)(j + 1) * _coeffData[j + 1][k];
	    else
	      _coeffDerivU[j][k] = _coeffDerivU[j + 2][k] +
		2. * (double)(j + 1) * _coeffData[j + 1][k];
	    //if (j != 0)
	    //_coeffDerivU[j][k] *= 2.;
	  }
	  if (_ps->IsVPeriodic()) {
	    int K = k+_vMLower;
	    _coeffDerivV[j][k] = (2 * M_PI * K * I / _periodV) *
	      _coeffData[j][k];
	  }
	  else {
	    if (k == _vM - 1)
	      _coeffDerivV[j][k] = 0.;
	    else if (k == _vM - 2)
	      _coeffDerivV[j][k] = 2. * (double)(k + 1) * _coeffData[j][k + 1];
	    else
	      _coeffDerivV[j][k] = _coeffDerivV[j][k + 2] +
		2. * (double)(k + 1) * _coeffData[j][k + 1];
	    //if (k != 0)
	    //_coeffDerivV[j][k] *= 2.;
	  }
        }
      }
    }
    for (int j = 0; j < _uM; j++) {
      for (int k = 0; k < _vM; k++) {
	if (_derivative & 1) {
	  if (!_ps->IsUPeriodic()) {
	    if (j != 0) {
	      _coeffDerivU[j][k] *= 2.;
	    }
	  }
	  if (!_ps->IsVPeriodic()) {
	    if (k != 0) {
	      _coeffDerivV[j][k] *= 2.;
	    }
	  }
	}
      }
    }

    for(int j = _uM - 1; j >= 0; j--) {
      for(int k = _vM - 1; k >= 0; k--) {
	if(_derivative & 2) {
	  if (_ps->IsUPeriodic()) {
	    int J = j+_uMLower;
	    _coeffDerivUU[j][k] = (2 * M_PI * J * I / _periodU) * 
	      _coeffDerivU[j][k];
	  }
	  else {
	    if (j == _uM - 1)
	      _coeffDerivUU[j][k] = 0.;
	    else if (j == _uM - 2)
	      _coeffDerivUU[j][k] = 2. * (double)(j + 1) * 
		_coeffDerivU[j + 1][k];
	    else
	      _coeffDerivUU[j][k] = _coeffDerivUU[j + 2][k] +
		2. * (double)(j + 1) * _coeffDerivU[j + 1][k];
	    //if (j != 0)
	    //_coeffDerivUU[j][k] *= 2.;
	  }
	  if (_ps->IsVPeriodic()) {
	    int K = k+_vMLower;
	    _coeffDerivVV[j][k] = (2 * M_PI * K * I / _periodV) * 
	      _coeffDerivV[j][k];
	    _coeffDerivUV[j][k] = (2 * M_PI * K * I / _periodV) * 
	      _coeffDerivU[j][k];
	  }
	  else {
	    if (k == _vM - 1) {
	      _coeffDerivVV[j][k] = 0.;
	      _coeffDerivUV[j][k] = 0.;
	    }
	    else if (k == _vM - 2) {
	      _coeffDerivVV[j][k] = 2. * (double)(k + 1) * 
		_coeffDerivV[j][k + 1];
	      _coeffDerivUV[j][k] = 2. * (double)(k + 1) * 
		_coeffDerivU[j][k + 1];
	    }
	    else {
	      _coeffDerivVV[j][k] = _coeffDerivVV[j][k + 2] +
		2. * (double)(k + 1) * _coeffDerivV[j][k + 1];
	      _coeffDerivUV[j][k] = _coeffDerivUV[j][k + 2] +
		2. * (double)(k + 1) * _coeffDerivU[j][k + 1];
	    }
	  }
	}
      }
    }
    for (int j = 0; j < _uM; j++) {
      for (int k = 0; k < _vM; k++) {
	if (_derivative & 2) {
	  if (!_ps->IsUPeriodic() && _ps->IsVPeriodic()) {
	    if (j != 0) {
	      _coeffDerivUU[j][k] *= 2.;
	    }
	  }
	  if (_ps->IsUPeriodic() && !_ps->IsVPeriodic()) {
	    if (k != 0) {
	      _coeffDerivVV[j][k] *= 2.;
	      _coeffDerivUV[j][k] *= 2.;
	    }
	  }
	}
      }
    }
  }

  // Initialize interpolation variables
  _tmpCoeff = std::vector< std::complex<double> >(_vM);
  _tmpInterp = std::vector< std::complex<double> >(_uM);

}

FPatch::~FPatch()
{
  for(int j = 0; j < _uModes; j++)
    delete [] _coeffOriginalData[j];
  delete [] _coeffOriginalData;

  for(int j = 0; j < _uM; j++)
    delete [] _coeffData[j];
  delete [] _coeffData;

  if(_coeffDerivU){
    for(int j = 0; j < _uM; j++)
      delete [] _coeffDerivU[j];
    delete [] _coeffDerivU;
  }
  if(_coeffDerivV){
    for(int j = 0; j < _uM; j++)
      delete [] _coeffDerivV[j];
    delete [] _coeffDerivV;
  }
  if(_coeffDerivUU){
    for(int j = 0; j < _uM; j++)
      delete [] _coeffDerivUU[j];
    delete [] _coeffDerivUU;
  }
  if(_coeffDerivVV){
    for(int j = 0; j < _uM; j++)
      delete [] _coeffDerivVV[j];
    delete [] _coeffDerivVV;
  }
  if(_coeffDerivUV){
    for(int j = 0; j < _uM; j++)
      delete [] _coeffDerivUV[j];
    delete [] _coeffDerivUV;
  }
}

int FPatch::_forwardSize = 0;
int FPatch::_backwardSize = 0;
fftw_plan FPatch::_forwardPlan;
fftw_plan FPatch::_backwardPlan;
fftw_complex *FPatch::_forwardData = 0;
fftw_complex *FPatch::_backwardData = 0;

void FPatch::_SetForwardPlan(int n)
{
  if(n != _forwardSize){
    if(_forwardSize){
      fftw_destroy_plan(_forwardPlan);
      fftw_free(_forwardData);
    }
    _forwardSize = n;
    _forwardData = 
      (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * _forwardSize);
    _forwardPlan = 
      fftw_plan_dft_1d(_forwardSize, _forwardData, _forwardData,
		       FFTW_FORWARD, FFTW_ESTIMATE);
  }
}

void FPatch::_SetBackwardPlan(int n)
{
  if(n != _backwardSize){
    if(_backwardSize){
      fftw_destroy_plan(_backwardPlan);
      fftw_free(_backwardData);
    }
    _backwardSize = n;
    _backwardData = 
      (fftw_complex*)fftw_malloc(sizeof(fftw_complex) * _backwardSize);
    _backwardPlan = 
      fftw_plan_dft_1d(_backwardSize, _backwardData, _backwardData,
		       FFTW_BACKWARD, FFTW_ESTIMATE);
  }
}

void FPatch::_ForwardFft(int n, std::complex<double> *fftData)
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
    fftData[i] = 
      s * std::complex<double>(_forwardData[i][0], _forwardData[i][1]);
}

void FPatch::_BackwardFft(int n, std::complex<double> *fftData)
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
    fftData[i] = 
      std::complex<double>(_backwardData[i][0], _backwardData[i][1]);

  // Fill in last element with copy of first element
  fftData[n - 1] = fftData[0];
}

void FPatch::_ReprocessSeriesCoeff()
{
  _coeffData = new std::complex<double>*[_uM];
  for(int j = 0; j < _uM; j++) {
    _coeffData[j] = new std::complex<double>[_vM];
    for(int k = 0; k < _vM; k++)
      _coeffData[j][k] = 0.;
  }
  if (_ps->IsUPeriodic() && _ps->IsVPeriodic()) {
    int uShift = (_uM-_uModes)%2 == 0 ? (_uM-_uModes)/2 : (_uM-_uModes)/2 + 1;
    int vShift = (_vM-_vModes)%2 == 0 ? (_vM-_vModes)/2 : (_vM-_vModes)/2 + 1;
    for (int j = 0; j < _uModes; j++)
      for (int k = 0; k < _vModes; k++)
	_coeffData[uShift + j][vShift + k] = _coeffOriginalData[j][k];
  }
  else if (_ps->IsUPeriodic()) {
    std::vector<double> u(_uM), v(_vM + 1);
    for (int j = 0; j < _uM; j++)
      u[j] = (double)j / (double)(_uM-1);
    for (int j = 0; j < _vM + 1; j++)
      v[j] = (double)j / (double)_vM;

    std::complex<double> **dataU = new std::complex<double> *[_vM];
    for (int k = 0; k < _vM; k++)
      dataU[k] = new std::complex<double> [_uM];
    std::complex<double> *dataV = new std::complex<double>[2*_vM + 1];
    for (int j = 0; j < _uM - 1; j++) {
      for (int k = 0; k < _vM + 1; k++) {
	//dataV[k] = 1.;
	//dataV[k] = 2. * cos(M_PI * v[k]) * cos(M_PI * v[k]) - 1.;
	//dataV[k] = 2. * (0.5 * cos(M_PI * v[k]) + 0.5) *
	//(0.5 * cos(M_PI * v[k]) + 0.5) - 1.;
	//dataV[k] = 2. * (0.5 * cos(M_PI * v[k]) + 0.5) *
	//(0.5 * cos(M_PI * v[k]) + 0.5) * cos(2 * M_PI * u[j]);
	//dataV[k] = cos(0.5 * cos(M_PI * v[k]) + 0.5) * 
	//cos(2 * M_PI * u[j]);
	dataV[k] = _Interpolate(u[j],0.5 * cos(M_PI * v[k]) + 0.5);
      }
      for (int k = 1; k < _vM+1; k++)
	dataV[_vM + k] = dataV[_vM -k];
      _BackwardFft(2*_vM + 1, dataV);
      dataU[0][j] = 0.5 * dataV[0] / (double)_vM;
      for (int k=1; k<_vM-1; k++)
	dataU[k][j] = dataV[k] / (double)_vM;
      dataU[_vM-1][j] = 0.5 * dataV[_vM-1] / (double)_vM;
    }
    for (int k = 0; k < _vM; k++) {
      dataU[k][_uM - 1] = dataU[k][0];
      _ForwardFft(_uM, dataU[k]);
    }
    for (int j = _uMLower; j <= _uMUpper; j++) {
      for (int k = 0; k < _vM; k++)
	if ((j == _uMLower) || (j == _uMUpper))
	  _coeffData[_uMUpper + j][k] = dataU[k][_uMUpper] / 2.;
	else if ((j >= 0) && (j < _uMUpper))
	  _coeffData[_uMUpper + j][k] = dataU[k][j];
	else
	  _coeffData[_uMUpper + j][k] = dataU[k][_uM + j -1];
    }
    for (int k = 0; k < _vM; k++)
      delete [] dataU[k];
    delete [] dataU;
    delete [] dataV;
  }
  else {
    std::vector<double> u(_uM + 1), v(_vM);
    for (int j = 0; j < _uM + 1; j++)
      u[j] = (double)j / (double)_uM;
    for (int j = 0; j < _vM; j++)
      v[j] = (double)j / (double)(_vM-1);

    std::complex<double> **dataV = new std::complex<double> *[_uM];
    for (int j = 0; j < _uM; j++)
      dataV[j] = new std::complex<double> [_vM];
    std::complex<double> *dataU = new std::complex<double>[2*_uM + 1];
    for (int k = 0; k < _vM - 1; k++) {
      for (int j = 0; j < _uM + 1; j++) {
	//dataU[j] = 1.;
	//dataU[j] = 2. * cos(M_PI * u[j]) * cos(M_PI * u[j]);
	dataU[j] = _Interpolate(0.5 * cos(M_PI * u[j]) + 0.5,v[k]);
      }
      for (int j = 1; j < _uM+1; j++)
	dataU[_uM + j] = dataU[_uM -j];
      _BackwardFft(2*_uM + 1, dataU);
      dataV[0][k] = 0.5 * dataU[0] / (double)_uM;
      for (int j=1; j<_uM-1; j++)
	dataV[j][k] = dataU[j] / (double)_uM;
      dataV[_uM-1][k] = 0.5 * dataU[_uM-1] / (double)_uM;
    }
    for (int j = 0; j < _uM; j++) {
      dataV[j][_uM - 1] = dataV[j][0];
      _ForwardFft(_vM, dataV[j]);
    }
    for (int k = _vMLower; k <= _vMUpper; k++) {
      //for (int j = 0; j < _uM - 1; j++) {
      for (int j = 0; j < _uM; j++)
	if ((k == _vMLower) || (k == _vMUpper))
	  _coeffData[j][_vMUpper + k] = dataV[j][_vMUpper] / 2.;
	else if ((j >= 0) && (j < _vMUpper))
	  _coeffData[j][_uMUpper + k] = dataV[j][k];
	else
	  _coeffData[j][_uMUpper + k] = dataV[j][_uM + k -1];
    }
    for (int j = 0; j < _uM; j++)
      delete [] dataV[j];
    delete [] dataV;
    delete [] dataU;
  }
}

std::complex<double> FPatch::
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

std::complex<double> FPatch::
  _Interpolate(double u, double v)
{
  double epsilon = 1e-12;
  if (u < 0. - epsilon || u > 1. + epsilon || 
      v < 0. - epsilon || v > 1. + epsilon) {
    Msg::Error("Trying to interpolate outside interval: (u,v)=(%.16g,%.16g) "
               "not in [%g,%g]x[%g,%g]", u, v, 0., 1., 0., 1.); 
  }
  
  // Interpolate to find value at (u,v)
  for(int j = 0; j < _uModes; j++){
    for(int k = 0; k < _vModes; k++) {
      _tmpOrigCoeff[k] = _coeffOriginalData[j][k];
    }
    std::complex<double> y(cos(2 * M_PI * v / _periodV),
                           sin(2 * M_PI * v / _periodV));
    _tmpOrigInterp[j] = _PolyEval(_tmpOrigCoeff, y);
    _tmpOrigInterp[j] *= std::complex<double>
      (cos(2 * M_PI * _vModesLower * v / _periodV),
       sin(2 * M_PI * _vModesLower * v / _periodV));
  }
  std::complex<double> x(cos(2 * M_PI * u / _periodU),
                         sin(2 * M_PI * u / _periodU));
  return _PolyEval(_tmpOrigInterp, x) * std::complex<double>
    (cos(2 * M_PI * _uModesLower * u / _periodU),
     sin(2 * M_PI * _uModesLower * u / _periodU));
}

std::complex<double> FPatch::
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
  if (u < 0. - epsilon || u > 1. + epsilon) {
    Msg::Error("Trying to interpolate outside interval: (u,v)=(%.16g,%.16g) "
               "not in [%g,%g]x[%g,%g]", u, v, 0., 1., 0., 1.); 
  }
  std::vector<double> uT(_uM,0.);
  std::vector<double> vT(_vM,0.);
  if (!_ps->IsUPeriodic()) {
    for (int j = 0; j < _uM; j++)
      if (j == 0)
	uT[j] = 1.;
      else if (j == 1)
	uT[j] = 2. * u - 1;
      else
	uT[j] = 2. * uT[1] * uT[j-1] - uT[j-2];
  }
  if (!_ps->IsVPeriodic()) {
    for (int k = 0; k < _vM; k++)
      if (k == 0)
	vT[k] = 1.;
      else if (k == 1)
	vT[k] = 2. * v - 1.;
      else
	vT[k] = 2. * vT[1] * vT[k-1] - vT[k-2];
  }
  // Interpolate to find value at (u,v)
  for(int j = 0; j < _uM; j++){
    _tmpInterp[j] = 0.;
    for(int k = 0; k < _vM; k++){
      //printf("i was here %d %d\n",j,k);
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
    //printf("i was here 00\n");
    if (_ps->IsVPeriodic()) {
      std::complex<double> y(cos(2 * M_PI * v / _periodV),
			     sin(2 * M_PI * v / _periodV));
      _tmpInterp[j] = _PolyEval(_tmpCoeff, y);
      _tmpInterp[j] *= std::complex<double>
	(cos(2 * M_PI * _vMLower * v / _periodV),
	 sin(2 * M_PI * _vMLower * v / _periodV));
    }
    else {
      //printf("i was here 0\n");
      for(int k = 0; k < _vM; k++)
	_tmpInterp[j] += _tmpCoeff[k] * vT[k];
    }
  }
  //printf("i was here\n");
  if (_ps->IsUPeriodic()) {
    std::complex<double> x(cos(2 * M_PI * u / _periodU),
			   sin(2 * M_PI * u / _periodU));
    return _PolyEval(_tmpInterp, x) * std::complex<double>
      (cos(2 * M_PI * _uMLower * u / _periodU),
       sin(2 * M_PI * _uMLower * u / _periodU));
  }
  else {
    std::complex<double> tmp = 0.;
    for(int j = 0; j < _uM; j++)
      tmp += _tmpInterp[j] * uT[j];
    return tmp;
  }
}

void FPatch::
F(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;

  u = RescaleU(u);
  v = RescaleV(v);

  _ps->F(u,v,px,py,pz);
  _ps->GetUnitNormal(u,v,nx,ny,nz);

  d = _Interpolate(u, v).real();

  x = px + d * nx;
  y = py + d * ny;
  z = pz + d * nz;
}

bool FPatch::
Inverse(double x,double y,double z,double &u,double &v)
{
  bool result = _ps->OrthoProjectionOnSurface(x,y,z,u,v);

  u = UnscaleU(u);
  v = UnscaleV(v);

  double tol = 1.e-12;
  if ((u > - tol) && (u < 1. + tol) && (v > - tol) && (v < 1. + tol))
    result = true;
  else
    result = false;

  return result;
}

void FPatch::
Dfdu(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxu, pyu, pzu, nxu, nyu, nzu, du;

  u = RescaleU(u);
  v = RescaleV(v);

  _ps->F(u,v,px,py,pz);
  _ps->GetUnitNormal(u,v,nx,ny,nz);
  _ps->Dfdu(u,v,pxu,pyu,pzu);
  _ps->Dndu(u,v,nxu, nyu, nzu);

  d = _Interpolate(u, v, 0, 0).real();
  du = _Interpolate(u, v, 1, 0).real();

  x = pxu + du * nx + d * nxu;
  y = pyu + du * ny + d * nyu;
  z = pzu + du * nz + d * nzu;
}

void FPatch::
Dfdv(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxv, pyv, pzv, nxv, nyv, nzv, dv;

  u = RescaleU(u);
  v = RescaleV(v);

  _ps->F(u,v,px,py,pz);
  _ps->GetUnitNormal(u,v,nx,ny,nz);
  _ps->Dfdv(u,v,pxv,pyv,pzv);
  _ps->Dndv(u,v,nxv,nyv,nzv);

  d = _Interpolate(u, v, 0, 0).real();
  dv = _Interpolate(u, v, 0, 1).real();

  x = pxv + dv * nx + d * nxv;
  y = pyv + dv * ny + d * nyv;
  z = pzv + dv * nz + d * nzv;
}

void FPatch::
Dfdfdudu(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxu, pyu, pzu, nxu, nyu, nzu, du;
  double pxuu, pyuu, pzuu, nxuu, nyuu, nzuu, duu;

  u = RescaleU(u);
  v = RescaleV(v);

  _ps->F(u,v,px,py,pz);
  _ps->GetUnitNormal(u,v,nx,ny,nz);
  _ps->Dfdu(u,v,pxu,pyu,pzu);
  _ps->Dndu(u,v,nxu,nyu,nzu);
  _ps->Dfdfdudu(u,v,pxuu,pyuu,pzuu);
  _ps->Dndndudu(u,v,nxuu,nyuu,nzuu);

  d = _Interpolate(u, v, 0, 0).real();
  du = _Interpolate(u, v, 1, 0).real();
  duu = _Interpolate(u, v, 2, 0).real();

  x = pxuu + duu * nx + du * nxu + du * nxu + d * nxuu;
  y = pyuu + duu * ny + du * nyu + du * nyu + d * nyuu;
  z = pzuu + duu * nz + du * nzu + du * nzu + d * nzuu;
}

void FPatch::
Dfdfdvdv(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxv, pyv, pzv, nxv, nyv, nzv, dv;
  double pxvv, pyvv, pzvv, nxvv, nyvv, nzvv, dvv;

  u = RescaleU(u);
  v = RescaleV(v);

  _ps->F(u,v,px,py,pz);
  _ps->GetUnitNormal(u,v,nx,ny,nz);
  _ps->Dfdv(u,v,pxv,pyv,pzv);
  _ps->Dndv(u,v,nxv,nyv,nzv);
  _ps->Dfdfdvdv(u,v,pxvv,pyvv,pzvv);
  _ps->Dndndvdv(u,v,nxvv,nyvv,nzvv);

  d = _Interpolate(u, v, 0, 0).real();
  dv = _Interpolate(u, v, 0, 1).real();
  dvv = _Interpolate(u, v, 0, 2).real();

  x = pxvv + dvv * nx + dv * nxv + dv * nxv + d * nxvv;
  y = pyvv + dvv * ny + dv * nyv + dv * nyv + d * nyvv;
  z = pzvv + dvv * nz + dv * nzv + dv * nzv + d * nzvv;
}

void FPatch::
Dfdfdudv(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxu, pyu, pzu, nxu, nyu, nzu, du;
  double pxv, pyv, pzv, nxv, nyv, nzv, dv;
  double pxuv, pyuv, pzuv, nxuv, nyuv, nzuv, duv;

  u = RescaleU(u);
  v = RescaleV(v);

  _ps->F(u,v,px,py,pz);
  _ps->GetUnitNormal(u,v,nx,ny,nz);
  _ps->Dfdu(u,v,pxu,pyu,pzu);
  _ps->Dndu(u,v,nxu,nyu,nzu);
  _ps->Dfdv(u,v,pxv,pyv,pzv);
  _ps->Dndv(u,v,nxv,nyv,nzv);
  _ps->Dfdfdudv(u,v,pxuv,pyuv,pzuv);
  _ps->Dndndudv(u,v,nxuv,nyuv,nzuv);

  d = _Interpolate(u, v, 0, 0).real();
  du = _Interpolate(u, v, 1, 0).real();
  dv = _Interpolate(u, v, 1, 0).real();
  duv = _Interpolate(u, v, 1, 1).real();

  x = pxuv + duv * nx + du * nxv + dv * nxu + d * nxuv;
  y = pyuv + duv * ny + du * nyv + dv * nyu + d * nyuv;
  z = pzuv + duv * nz + du * nzv + dv * nzu + d * nzuv;
}

double  FPatch::GetPou(double u, double v)
{
  double pouU, pouV;

  if (_hardEdge[3])
    pouU = OneSidedPartitionOfUnity(0.,1.,u);
  else if (_hardEdge[1])
    pouU = 1. - OneSidedPartitionOfUnity(0.,1.,u);
  else
    pouU = PartitionOfUnity(u, 0., 0.3, 0.7, 1.);

  if (_hardEdge[0])
    pouV = OneSidedPartitionOfUnity(0.,1.,v);
  else if (_hardEdge[2])
    pouV = 1. - OneSidedPartitionOfUnity(0.,1.,v);
  else
    pouV = PartitionOfUnity(v, 0., 0.3, 0.7, 1.);

  return pouU * pouV;
}
