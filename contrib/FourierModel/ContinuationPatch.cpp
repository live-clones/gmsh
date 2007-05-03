#include <math.h>
#include "Message.h"
#include "ContinuationPatch.h"

ContinuationPatch::ContinuationPatch(PatchInfo *PI, int derivative) : Patch(PI)
{
  _NcrossT[0] = _PI->normal[1] * _PI->tangent[2] - 
    _PI->normal[2] * _PI->tangent[1];
  _NcrossT[1] = _PI->normal[2] * _PI->tangent[0] - 
    _PI->normal[0] * _PI->tangent[2];
  _NcrossT[2] = _PI->normal[0] * _PI->tangent[1] - 
    _PI->normal[1] * _PI->tangent[0];

  _derivative = derivative;

  _uModes = _PI->nModes[0];
  _vModes = _PI->nModes[1];

  _periodU = (1-_PI->periodic[0]) + 1;
  _periodV = (1-_PI->periodic[1]) + 1;

  //Msg::Info("Period : %g %g",_periodU,_periodV);

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

  // Initialize Data
  _coeffData = new std::complex<double>*[_uModes];
  for(int j = 0; j < _uModes; j++){
    _coeffData[j] = new std::complex<double>[_vModes];
    for(int k = 0; k < _vModes; k++)
      _coeffData[j][k] = _PI->coeff[j][k];
  }

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

ContinuationPatch::~ContinuationPatch()
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

std::complex<double> ContinuationPatch::
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

std::complex<double> ContinuationPatch::
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

void ContinuationPatch::P(double u, double v, double &x, double &y, double &z,
			  double &nx, double &ny, double &nz)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    x = _PI->origin[0] + _PI->normal[0] * _PI->scale[1] * v;
    y = _PI->origin[1] + _PI->normal[1] * _PI->scale[1] * v;
    z = _PI->origin[2] + _PI->normal[2] * _PI->scale[1] * v;

    nx = _PI->tangent[0] * cos(_PI->scale[0] * (u - 0.5)) + 
      _NcrossT[0] * sin(_PI->scale[0] * (u - 0.5));
    ny = _PI->tangent[1] * cos(_PI->scale[0] * (u - 0.5)) +
      _NcrossT[1] * sin(_PI->scale[0] * (u - 0.5));
    nz = _PI->tangent[2] * cos(_PI->scale[0] * (u - 0.5)) +
      _NcrossT[2] * sin(_PI->scale[0] * (u - 0.5));

    double norm = sqrt(nx * nx + ny * ny + nz * nz);
    nx /= norm;
    ny /= norm;
    nz /= norm;
  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx = ny = nz = 0;
  }
  else {
    Msg::Info("Unknown projection surface");
    x = y = z = nx = ny = nz = 0;
  }
}

bool ContinuationPatch::pInverse(double x,double y,double z,
				 double &u,double &v)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    double t = (x - _PI->origin[0]) * _PI->normal[0] +
      (y - _PI->origin[1]) * _PI->normal[1] +
      (z - _PI->origin[2]) * _PI->normal[2];
    v = t / _PI->scale[1];
    double n[3];
    n[0] = x - (_PI->origin[0] + t * _PI->normal[0]);
    n[1] = y - (_PI->origin[1] + t * _PI->normal[1]);
    n[2] = z - (_PI->origin[2] + t * _PI->normal[2]);
    double norm = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    for (int i=0;i<3;i++)
      n[i] /= norm;
    u = atan2((n[0]*_NcrossT[0]+n[1]*_NcrossT[1]+n[2]*_NcrossT[2]),
	      (n[0]*_PI->tangent[0]+n[1]*_PI->tangent[1]+
	       n[2]*_PI->tangent[2]));
    u /= _PI->scale[0];
    u += 0.5;

  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    u = v = 0.;
  }
  else {
    Msg::Info("Unknown projection surface");
    u = v = 0.;
  }
}

void ContinuationPatch::Dpdu(double u, double v, 
			     double &x, double &y, double &z,
			     double &nx, double &ny, double &nz)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = 0.;

    double n[3], nu[3];
    for (int i=0;i<3;i++) {
      n[i] = _PI->tangent[i] * cos(_PI->scale[0] * u) + 
	_NcrossT[i] * sin(_PI->scale[0] * u);
      nu[i] = _PI->scale[0] * (- _PI->tangent[i] * sin(_PI->scale[0] * u) +
			      _NcrossT[i] * cos(_PI->scale[0] * u));
    }
    double norm = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    double NdotNu = n[0] * nu[0] + n[1] * nu[1] + n[2] * nu[2];
    nx =  nu[0] / norm - NdotNu * n[0] / (norm * norm * norm);
    ny =  nu[1] / norm - NdotNu * n[1] / (norm * norm * norm);
    nz =  nu[2] / norm - NdotNu * n[2] / (norm * norm * norm);
  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx = ny = nz = 0;
  }
  else {
    Msg::Info("Unknown projection surface");
    x = y = z = nx = ny = nz = 0;
  }
}

void ContinuationPatch::Dpdv(double u, double v, 
			     double &x, double &y, double &z,
			     double &nx, double &ny, double &nz)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    x = _PI->normal[0] * _PI->scale[1];
    y = _PI->normal[1] * _PI->scale[1];
    z = _PI->normal[2] * _PI->scale[1];

    nx =  ny =  nz =  0.;
  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx = ny = nz = 0;
  }
  else {
    Msg::Info("Unknown projection surface");
    x = y = z = nx = ny = nz = 0;
  }
}

void ContinuationPatch::Dpdpdudu(double u,double v,
				 double &x, double &y, double &z,
				 double &nx, double &ny, double &nz)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = 0.;
    double n[3], nu[3], nuu[3];
    for (int i=0;i<3;i++) {
      n[i] = _PI->tangent[i] * cos(_PI->scale[0] * (u-0.5)) + 
	_NcrossT[i] * sin(_PI->scale[0] * (u-0.5));
      nu[i] = _PI->scale[0] * 
	(- _PI->tangent[i] * sin(_PI->scale[0] * (u-0.5)) +
	 _NcrossT[i] * cos(_PI->scale[0] * (u-0.5)));
      nuu[i] = -  _PI->scale[0] *  _PI->scale[0] *
	(_PI->tangent[i] * cos(_PI->scale[0] * (u-0.5)) +
	 _NcrossT[i] * sin(_PI->scale[0] * (u-0.5)));
    }
    double norm = sqrt(n[0] * n[0] + n[1] * n[1] + n[2] * n[2]);
    double NdotNu = n[0] * nu[0] + n[1] * nu[1] + n[2] * nu[2];
    double NudotNu = nu[0] * nu[0] + nu[1] * nu[1] + nu[2] * nu[2];
    double NdotNuu = n[0] * nuu[0] + n[1] * nuu[1] + n[2] * nuu[2];

    nx =  nuu[0] / norm - (NdotNu * nu[0] + (NdotNuu + NudotNu) * n[0] +
			   NdotNu * nu[0]) / (norm * norm * norm) +
      3 * NdotNu * NdotNu * n[0] / (norm * norm * norm * norm * norm);
    ny =  nuu[1] / norm - (NdotNu * nu[1] + (NdotNuu + NudotNu) * n[1] +
			   NdotNu * nu[1]) / (norm * norm * norm) +
      3 * NdotNu * NdotNu * n[1] / (norm * norm * norm * norm * norm);
    nz =  nuu[2] / norm - (NdotNu * nu[2] + (NdotNuu + NudotNu) * n[2] +
			   NdotNu * nu[2]) / (norm * norm * norm) +
      3 * NdotNu * NdotNu * n[2] / (norm * norm * norm * norm * norm);
  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx = ny = nz = 0;
  }
  else {
    Msg::Info("Unknown projection surface");
    x = y = z = nx = ny = nz = 0;
  }
}

void ContinuationPatch::Dpdpdudv(double u, double v, 
				 double &x, double &y, double &z,
				 double &nx, double &ny, double &nz)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx =  ny =  nz =  0.;
  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx = ny = nz = 0;
  }
  else {
    Msg::Info("Unknown projection surface");
    x = y = z = nx = ny = nz = 0;
  }
}

void ContinuationPatch::Dpdpdvdv(double u, double v, 
				 double &x, double &y, double &z,
				 double &nx, double &ny, double &nz)
{
  if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx =  ny =  nz =  0.;
  }
  else if (!strcmp(_PI->projection,"cylinder")) {
    x = y = z = nx = ny = nz = 0;
  }
  else {
    Msg::Info("Unknown projection surface");
    x = y = z = nx = ny = nz = 0;
  }
}

void ContinuationPatch::
F(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  P(u,v,px,py,pz,nx,ny,nz);
  d = _Interpolate(u, v, 0, 0).real();
  x = px + d * nx;
  y = py + d * ny;
  z = pz + d * nz;
}

bool ContinuationPatch::
Inverse(double x,double y,double z,double &u,double &v)
{
  pInverse(x,y,z,u,v);
}

void ContinuationPatch::
Dfdu(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxu, pyu, pzu, nxu, nyu, nzu, du;
  P(u,v,px,py,pz,nx,ny,nz);
  Dpdu(u,v,pxu,pyu,pzu,nxu,nyu,nzu);
  d = _Interpolate(u, v, 0, 0).real();
  du = _Interpolate(u, v, 1, 0).real();

  x = pxu + du * nx + d * nxu;
  y = pyu + du * ny + d * nyu;
  z = pzu + du * nz + d * nzu;
}

void ContinuationPatch::
Dfdv(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxv, pyv, pzv, nxv, nyv, nzv, dv;
  P(u,v,px,py,pz,nx,ny,nz);
  Dpdu(u,v,pxv,pyv,pzv,nxv,nyv,nzv);
  d = _Interpolate(u, v, 0, 0).real();
  dv = _Interpolate(u, v, 0, 1).real();

  x = pxv + dv * nx + d * nxv;
  y = pyv + dv * ny + d * nyv;
  z = pzv + dv * nz + d * nzv;
}

void ContinuationPatch::
Dfdfdudu(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxu, pyu, pzu, nxu, nyu, nzu, du;
  double pxuu, pyuu, pzuu, nxuu, nyuu, nzuu, duu;

  P(u,v,px,py,pz,nx,ny,nz);
  Dpdu(u,v,pxu,pyu,pzu,nxu,nyu,nzu);
  Dpdpdudu(u,v,pxuu,pyuu,pzuu,nxuu,nyuu,nzuu);

  d = _Interpolate(u, v, 0, 0).real();
  du = _Interpolate(u, v, 1, 0).real();
  duu = _Interpolate(u, v, 2, 0).real();

  x = pxuu + duu * nx + du * nxu + du * nxu + d * nxuu;
  y = pyuu + duu * ny + du * nyu + du * nyu + d * nyuu;
  z = pzuu + duu * nz + du * nzu + du * nzu + d * nzuu;
}

void ContinuationPatch::
Dfdfdvdv(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxv, pyv, pzv, nxv, nyv, nzv, dv;
  double pxvv, pyvv, pzvv, nxvv, nyvv, nzvv, dvv;

  P(u,v,px,py,pz,nx,ny,nz);
  Dpdv(u,v,pxv,pyv,pzv,nxv,nyv,nzv);
  Dpdpdvdv(u,v,pxvv,pyvv,pzvv,nxvv,nyvv,nzvv);

  d = _Interpolate(u, v, 0, 0).real();
  dv = _Interpolate(u, v, 0, 1).real();
  dvv = _Interpolate(u, v, 0, 2).real();

  x = pxvv + dvv * nx + dv * nxv + dv * nxv + d * nxvv;
  y = pyvv + dvv * ny + dv * nyv + dv * nyv + d * nyvv;
  z = pzvv + dvv * nz + dv * nzv + dv * nzv + d * nzvv;
}

void ContinuationPatch::
Dfdfdudv(double u, double v, double &x, double &y, double &z)
{
  double px, py, pz, nx, ny, nz, d;
  double pxu, pyu, pzu, nxu, nyu, nzu, du;
  double pxv, pyv, pzv, nxv, nyv, nzv, dv;
  double pxuv, pyuv, pzuv, nxuv, nyuv, nzuv, duv;

  P(u,v,px,py,pz,nx,ny,nz);
  Dpdu(u,v,pxu,pyu,pzu,nxu,nyu,nzu);
  Dpdv(u,v,pxv,pyv,pzv,nxv,nyv,nzv);
  Dpdpdudv(u,v,pxuv,pyuv,pzuv,nxuv,nyuv,nzuv);

  d = _Interpolate(u, v, 0, 0).real();
  du = _Interpolate(u, v, 1, 0).real();
  dv = _Interpolate(u, v, 1, 0).real();
  duv = _Interpolate(u, v, 1, 1).real();

  x = pxuv + duv * nx + du * nxv + dv * nxu + d * nxuv;
  y = pyuv + duv * ny + du * nyv + dv * nyu + d * nyuv;
  z = pzuv + duv * nz + du * nzv + dv * nzu + d * nzuv;
}

double  ContinuationPatch::GetPou(double u, double v)
{
  return 1.;
}

