#include <cmath>
#include "Patch.h"

Patch::Patch() :_ps(0), _uMin(0.), _uMax(1.), _vMin(0.), _vMax(1.),
		_periodicityU(0), _periodicityV(0), _derivative(3), 
		_tag(-1) {}

void Patch::GetNormal(double u, double v, double &x, double &y, double &z)
{
  double dfdu[3], dfdv[3];
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  x = dfdu[1] * dfdv[2] - dfdu[2] * dfdv[1];
  y = dfdu[2] * dfdv[0] - dfdu[0] * dfdv[2];
  z = dfdu[0] * dfdv[1] - dfdu[1] * dfdv[0];
}

void Patch::GetUnitNormal(double u, double v, double &x, double &y, double &z)
{
  GetNormal(u, v, x, y, z);
  double norm = sqrt(x * x + y * y + z * z);
  if(norm > 0.) {
    x /= norm;
    y /= norm;
    z /= norm;
  }  
}

void Patch::Dndu(double u, double v, double &x, double &y, double &z) 
{
  double n[3],dfdu[3],dfdv[3],dfdfdudu[3],dfdfdudv[3],dfdfdvdv[3],dndu[3];
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  Dfdfdudu(u, v, dfdfdudu[0], dfdfdudu[1], dfdfdudu[2]);
  Dfdfdudv(u, v, dfdfdudv[0], dfdfdudv[1], dfdfdudv[2]);
  Dfdfdvdv(u, v, dfdfdvdv[0], dfdfdvdv[1], dfdfdvdv[2]);
  GetNormal(u,v,n[0],n[1],n[2]);
  double norm = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  double normSquared = norm * norm;
  double normCubed = normSquared * norm;

  dndu[0] = dfdfdudu[1] * dfdv[2] + dfdu[1] * dfdfdudv[2] - 
    dfdfdudu[2] * dfdv[1] - dfdu[2] * dfdfdudv[1];
  dndu[1] = dfdfdudu[2] * dfdv[0] + dfdu[2] * dfdfdudv[0] - 
    dfdfdudu[0] * dfdv[2] - dfdu[0] * dfdfdudv[2];
  dndu[2] = dfdfdudu[0] * dfdv[1] + dfdu[0] * dfdfdudv[1] - 
    dfdfdudu[1] * dfdv[0] - dfdu[1] * dfdfdudv[0];

  x = ((normSquared - n[0]*n[0])*dndu[0] - n[0]*n[1]*dndu[1] - 
       n[0]*n[2]*dndu[2]) / normCubed;
  y = ((normSquared - n[1]*n[1])*dndu[1] - n[1]*n[0]*dndu[0] -
       n[1]*n[2]*dndu[2]) / normCubed;
  z = ((normSquared - n[2]*n[2])*dndu[2] - n[2]*n[0]*dndu[0] -
       n[2]*n[1]*dndu[1]) / normCubed;
}

void Patch::Dndv(double u, double v, double &x, double &y, double &z) 
{
  double n[3],dfdu[3],dfdv[3],dfdfdudu[3],dfdfdudv[3],dfdfdvdv[3],dndv[3];
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  Dfdfdudu(u, v, dfdfdudu[0], dfdfdudu[1], dfdfdudu[2]);
  Dfdfdudv(u, v, dfdfdudv[0], dfdfdudv[1], dfdfdudv[2]);
  Dfdfdvdv(u, v, dfdfdvdv[0], dfdfdvdv[1], dfdfdvdv[2]);
  GetNormal(u,v,n[0],n[1],n[2]);
  double norm = sqrt(n[0]*n[0]+n[1]*n[1]+n[2]*n[2]);
  double normSquared = norm * norm;
  double normCubed = normSquared * norm;

  dndv[0] = dfdfdudv[1] * dfdv[2] + dfdu[1] * dfdfdvdv[2] -
    dfdfdudv[2] * dfdv[1] - dfdu[2] * dfdfdvdv[1];
  dndv[1] = dfdfdudv[2] * dfdv[0] + dfdu[2] * dfdfdvdv[0] -
    dfdfdudv[0] * dfdv[2] - dfdu[0] * dfdfdvdv[2];
  dndv[2] = dfdfdudv[0] * dfdv[1] + dfdu[0] * dfdfdvdv[1] -
    dfdfdudv[1] * dfdv[0] - dfdu[1] * dfdfdvdv[0];

  x = ((normSquared - n[0]*n[0])*dndv[0] - n[0]*n[1]*dndv[1] - 
       n[0]*n[2]*dndv[2]) / normCubed;
  y = ((normSquared - n[1]*n[1])*dndv[1] - n[1]*n[0]*dndv[0] -
       n[1]*n[2]*dndv[2]) / normCubed;
  z = ((normSquared - n[2]*n[2])*dndv[2] - n[2]*n[0]*dndv[0] -
       n[2]*n[1]*dndv[1]) / normCubed;
}
