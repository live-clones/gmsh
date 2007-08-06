#include <cmath>
#include "ProjectionSurface.h"

ProjectionSurface::ProjectionSurface
(double uPeriod, double vPeriod)
{
  printf("here in ProjectoionSufrace\n");
  tag_ = -1;
  name_ = std::string("default");
  numParameters_ = 0;

  uPeriod_ = uPeriod;
  vPeriod_ = vPeriod;

  if (uPeriod_ < 0.)
    uPeriodic_ = false;
  else
    uPeriodic_ = true;

  if (vPeriod_ < 0.)
    vPeriodic_ = false;
  else
    vPeriodic_ = true;

  for (int l=0;l<3;l++) {
    O_[l] = E0_[l] = E1_[l] = E2_[l] = scale_[l] = 0.;
  }
}

void ProjectionSurface::GetNormal
(double u, double v, double &x, double &y, double &z)
{
  double dfdu[3], dfdv[3];
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  x = dfdu[1] * dfdv[2] - dfdu[2] * dfdv[1];
  y = dfdu[2] * dfdv[0] - dfdu[0] * dfdv[2];
  z = dfdu[0] * dfdv[1] - dfdu[1] * dfdv[0];
}

void ProjectionSurface::GetUnitNormal
(double u, double v, double &x, double &y, double &z)
{
  GetNormal(u, v, x, y, z);
  double norm = sqrt(x * x + y * y + z * z);
  if(norm > 0.) {
    x /= norm;
    y /= norm;
    z /= norm;
  }  
}

void ProjectionSurface::Dndu
(double u, double v, double &x, double &y, double &z) 
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

void ProjectionSurface::
Dndv(double u, double v, double &x, double &y, double &z) 
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

void ProjectionSurface::
Dndndudu(double u, double v, double &x, double &y, double &z)
{
  double n[3],dfdu[3],dfdv[3],dfdfdudu[3],dfdfdudv[3],dfdfdvdv[3],
    dfdfdfdududu[3],dfdfdfdududv[3],dfdfdfdudvdv[3],dfdfdfdvdvdv[3],
    dndu[3],dndndudu[3];

  GetNormal(u,v,n[0],n[1],n[2]);
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  Dfdfdudu(u, v, dfdfdudu[0], dfdfdudu[1], dfdfdudu[2]);
  Dfdfdudv(u, v, dfdfdudv[0], dfdfdudv[1], dfdfdudv[2]);
  Dfdfdvdv(u, v, dfdfdvdv[0], dfdfdvdv[1], dfdfdvdv[2]);
  Dfdfdfdududu(u,v,dfdfdfdududu[0],dfdfdfdududu[1],dfdfdfdududu[2]);
  Dfdfdfdududv(u,v,dfdfdfdududv[0],dfdfdfdududv[1],dfdfdfdududv[2]);
  Dfdfdfdudvdv(u,v,dfdfdfdudvdv[0],dfdfdfdudvdv[1],dfdfdfdudvdv[2]);
  Dfdfdfdvdvdv(u,v,dfdfdfdvdvdv[0],dfdfdfdvdvdv[1],dfdfdfdvdvdv[2]);

  dndu[0] = dfdfdudu[1] * dfdv[2] + dfdu[1] * dfdfdudv[2] -
    dfdfdudu[2] * dfdv[1] - dfdu[2] * dfdfdudv[1];
  dndu[1] = dfdfdudu[2] * dfdv[0] + dfdu[2] * dfdfdudv[0] -
    dfdfdudu[0] * dfdv[2] - dfdu[0] * dfdfdudv[2];
  dndu[2] = dfdfdudu[0] * dfdv[1] + dfdu[0] * dfdfdudv[1] -
    dfdfdudu[1] * dfdv[0] - dfdu[1] * dfdfdudv[0];

  dndndudu[0] = dfdfdfdududu[1] * dfdv[2] + dfdfdudu[1] * dfdfdudv[2] + 
    dfdfdudu[1] * dfdfdudv[2] + dfdu[1] * dfdfdfdududv[2] -
    dfdfdfdududu[2] * dfdv[1] - dfdfdudu[2] * dfdfdudv[1]  - 
    dfdfdudu[2] * dfdfdudv[1] - dfdu[2] * dfdfdfdududv[1];
  dndndudu[1] = dfdfdfdududu[2] * dfdv[0] + dfdfdudu[2] * dfdfdudv[0] +
    dfdfdudu[2] * dfdfdudv[0] + dfdu[2] * dfdfdfdududv[0]  -
    dfdfdfdududu[0] * dfdv[2] - dfdfdudu[0] * dfdfdudv[2]  - 
    dfdfdudu[0] * dfdfdudv[2] - dfdu[0] * dfdfdfdududv[2];
  dndndudu[2] = dfdfdfdududu[0] * dfdv[1] + dfdfdudu[0] * dfdfdudv[1] +
    dfdfdudu[0] * dfdfdudv[1] +  dfdu[0] * dfdfdfdududv[1] -
    dfdfdfdududu[1] * dfdv[0] - dfdfdudu[1] * dfdfdudv[0]  - 
    dfdfdudu[1] * dfdfdudv[0] - dfdu[1] * dfdfdfdududv[0];

  double nDotN = n[0]*n[0]+n[1]*n[1]+n[2]*n[2];
  double nDotNu = n[0] * dndu[0] + n[1] * dndu[1] + n[2] * dndu[2];
  double nuDotNu = dndu[0] * dndu[0] + dndu[1] * dndu[1] + dndu[2] * dndu[2];
  double nDotNuu = n[0] * dndndudu[0] + n[1] * dndndudu[1] + 
    n[2] * dndndudu[2];
  
  double norm = sqrt(nDotN);
  double normCubed = nDotN * norm;
  double normToFive = nDotN * normCubed;

  x = (nDotN * dndndudu[0] - 2 * nDotNu * dndu[0] - 
       (nuDotNu + nDotNuu) * n[0]) / normCubed +
    3 * nDotNu * nDotNu * n[0] / normToFive;
  y = (nDotN * dndndudu[1] - 2 * nDotNu * dndu[1] - 
       (nuDotNu + nDotNuu) * n[1]) / normCubed +
    3 * nDotNu * nDotNu * n[1] / normToFive;
  z = (nDotN * dndndudu[2] - 2 * nDotNu * dndu[2] - 
       (nuDotNu + nDotNuu) * n[2]) / normCubed +
    3 * nDotNu * nDotNu * n[2] / normToFive;
}

void ProjectionSurface::
Dndndudv(double u, double v, double &x, double &y, double &z)
{
  double n[3],dfdu[3],dfdv[3],dfdfdudu[3],dfdfdudv[3],dfdfdvdv[3],
    dfdfdfdududu[3],dfdfdfdududv[3],dfdfdfdudvdv[3],dfdfdfdvdvdv[3],
    dndu[3],dndv[3],dndndudv[3];

  GetNormal(u,v,n[0],n[1],n[2]);
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  Dfdfdudu(u, v, dfdfdudu[0], dfdfdudu[1], dfdfdudu[2]);
  Dfdfdudv(u, v, dfdfdudv[0], dfdfdudv[1], dfdfdudv[2]);
  Dfdfdvdv(u, v, dfdfdvdv[0], dfdfdvdv[1], dfdfdvdv[2]);
  Dfdfdfdududu(u,v,dfdfdfdududu[0],dfdfdfdududu[1],dfdfdfdududu[2]);
  Dfdfdfdududv(u,v,dfdfdfdududv[0],dfdfdfdududv[1],dfdfdfdududv[2]);
  Dfdfdfdudvdv(u,v,dfdfdfdudvdv[0],dfdfdfdudvdv[1],dfdfdfdudvdv[2]);
  Dfdfdfdvdvdv(u,v,dfdfdfdvdvdv[0],dfdfdfdvdvdv[1],dfdfdfdvdvdv[2]);

  dndu[0] = dfdfdudu[1] * dfdv[2] + dfdu[1] * dfdfdudv[2] -
    dfdfdudu[2] * dfdv[1] - dfdu[2] * dfdfdudv[1];
  dndu[1] = dfdfdudu[2] * dfdv[0] + dfdu[2] * dfdfdudv[0] -
    dfdfdudu[0] * dfdv[2] - dfdu[0] * dfdfdudv[2];
  dndu[2] = dfdfdudu[0] * dfdv[1] + dfdu[0] * dfdfdudv[1] -
    dfdfdudu[1] * dfdv[0] - dfdu[1] * dfdfdudv[0];

  dndv[0] = dfdfdudv[1] * dfdv[2] + dfdu[1] * dfdfdvdv[2] -
    dfdfdudv[2] * dfdv[1] - dfdu[2] * dfdfdvdv[1];
  dndv[1] = dfdfdudv[2] * dfdv[0] + dfdu[2] * dfdfdvdv[0] -
    dfdfdudv[0] * dfdv[2] - dfdu[0] * dfdfdvdv[2];
  dndv[2] = dfdfdudv[0] * dfdv[1] + dfdu[0] * dfdfdvdv[1] -
    dfdfdudv[1] * dfdv[0] - dfdu[1] * dfdfdvdv[0];

  dndndudv[0] = dfdfdfdududv[1] * dfdv[2] + dfdfdudu[1] * dfdfdvdv[2] + 
    dfdfdudv[1] * dfdfdudv[2] + dfdu[1] * dfdfdfdudvdv[2] -
    dfdfdfdududv[2] * dfdv[1] - dfdfdudu[2] * dfdfdvdv[1]  - 
    dfdfdudv[2] * dfdfdudv[1] - dfdu[2] * dfdfdfdudvdv[1];
  dndndudv[1] = dfdfdfdududv[2] * dfdv[0] + dfdfdudu[2] * dfdfdvdv[0] +
    dfdfdudv[2] * dfdfdudv[0] + dfdu[2] * dfdfdfdudvdv[0]  -
    dfdfdfdududv[0] * dfdv[2] - dfdfdudu[0] * dfdfdvdv[2]  - 
    dfdfdudv[0] * dfdfdudv[2] - dfdu[0] * dfdfdfdudvdv[2];
  dndndudv[2] = dfdfdfdududv[0] * dfdv[1] + dfdfdudu[0] * dfdfdvdv[1] +
    dfdfdudv[0] * dfdfdudv[1] +  dfdu[0] * dfdfdfdudvdv[1] -
    dfdfdfdududv[1] * dfdv[0] - dfdfdudu[1] * dfdfdvdv[0]  - 
    dfdfdudv[1] * dfdfdudv[0] - dfdu[1] * dfdfdfdudvdv[0];

  double nDotN = n[0]*n[0]+n[1]*n[1]+n[2]*n[2];
  double nDotNu = n[0] * dndu[0] + n[1] * dndu[1] + n[2] * dndu[2];
  double nDotNv = n[0] * dndv[0] + n[1] * dndv[1] + n[2] * dndv[2];
  double nuDotNv = dndu[0] * dndv[0] + dndu[1] * dndv[1] + dndu[2] * dndv[2];
  double nDotNuv = n[0] * dndndudv[0] + n[1] * dndndudv[1] + 
    n[2] * dndndudv[2];
  
  double norm = sqrt(nDotN);
  double normCubed = nDotN * norm;
  double normToFive = nDotN * normCubed;

  x = (nDotN * dndndudv[0] - nDotNv * dndu[0] - nDotNu * dndv[0] -
       (nuDotNv + nDotNuv) * n[0]) / normCubed +
    3 * nDotNu * nDotNv * n[0] / normToFive;
  y = (nDotN * dndndudv[1] - nDotNv * dndu[1] - nDotNu * dndv[1] -
       (nuDotNv + nDotNuv) * n[1]) / normCubed +
    3 * nDotNu * nDotNv * n[1] / normToFive;
  z = (nDotN * dndndudv[2] - nDotNv * dndu[2] - nDotNu * dndv[2] -
       (nuDotNv + nDotNuv) * n[2]) / normCubed +
    3 * nDotNu * nDotNv * n[2] / normToFive;
}

void ProjectionSurface::
Dndndvdv(double u, double v, double &x, double &y, double &z)
{
  double n[3],dfdu[3],dfdv[3],dfdfdudu[3],dfdfdudv[3],dfdfdvdv[3],
    dfdfdfdududu[3],dfdfdfdududv[3],dfdfdfdudvdv[3],dfdfdfdvdvdv[3],
    dndv[3],dndndvdv[3];

  GetNormal(u,v,n[0],n[1],n[2]);
  Dfdu(u, v, dfdu[0], dfdu[1], dfdu[2]);
  Dfdv(u, v, dfdv[0], dfdv[1], dfdv[2]);
  Dfdfdudu(u, v, dfdfdudu[0], dfdfdudu[1], dfdfdudu[2]);
  Dfdfdudv(u, v, dfdfdudv[0], dfdfdudv[1], dfdfdudv[2]);
  Dfdfdvdv(u, v, dfdfdvdv[0], dfdfdvdv[1], dfdfdvdv[2]);
  Dfdfdfdududu(u,v,dfdfdfdududu[0],dfdfdfdududu[1],dfdfdfdududu[2]);
  Dfdfdfdududv(u,v,dfdfdfdududv[0],dfdfdfdududv[1],dfdfdfdududv[2]);
  Dfdfdfdudvdv(u,v,dfdfdfdudvdv[0],dfdfdfdudvdv[1],dfdfdfdudvdv[2]);
  Dfdfdfdvdvdv(u,v,dfdfdfdvdvdv[0],dfdfdfdvdvdv[1],dfdfdfdvdvdv[2]);

  dndv[0] = dfdfdudv[1] * dfdv[2] + dfdu[1] * dfdfdvdv[2] -
    dfdfdudv[2] * dfdv[1] - dfdu[2] * dfdfdvdv[1];
  dndv[1] = dfdfdudv[2] * dfdv[0] + dfdu[2] * dfdfdvdv[0] -
    dfdfdudv[0] * dfdv[2] - dfdu[0] * dfdfdvdv[2];
  dndv[2] = dfdfdudv[0] * dfdv[1] + dfdu[0] * dfdfdvdv[1] -
    dfdfdudv[1] * dfdv[0] - dfdu[1] * dfdfdvdv[0];

  dndndvdv[0] = dfdfdfdudvdv[1] * dfdv[2] + dfdfdudv[1] * dfdfdvdv[2] + 
    dfdfdudv[1] * dfdfdvdv[2] + dfdu[1] * dfdfdfdvdvdv[2] -
    dfdfdfdudvdv[2] * dfdv[1] - dfdfdudv[2] * dfdfdvdv[1]  - 
    dfdfdudv[2] * dfdfdvdv[1] - dfdu[2] * dfdfdfdvdvdv[1];
  dndndvdv[1] = dfdfdfdudvdv[2] * dfdv[0] + dfdfdudv[2] * dfdfdvdv[0] +
    dfdfdudv[2] * dfdfdvdv[0] + dfdu[2] * dfdfdfdvdvdv[0]  -
    dfdfdfdudvdv[0] * dfdv[2] - dfdfdudv[0] * dfdfdvdv[2]  - 
    dfdfdudv[0] * dfdfdvdv[2] - dfdu[0] * dfdfdfdvdvdv[2];
  dndndvdv[2] = dfdfdfdudvdv[0] * dfdv[1] + dfdfdudv[0] * dfdfdvdv[1] +
    dfdfdudv[0] * dfdfdvdv[1] +  dfdu[0] * dfdfdfdvdvdv[1] -
    dfdfdfdudvdv[1] * dfdv[0] - dfdfdudv[1] * dfdfdvdv[0]  - 
    dfdfdudv[1] * dfdfdvdv[0] - dfdu[1] * dfdfdfdvdvdv[0];

  double nDotN = n[0]*n[0]+n[1]*n[1]+n[2]*n[2];
  double nDotNv = n[0] * dndv[0] + n[1] * dndv[1] + n[2] * dndv[2];
  double nvDotNv = dndv[0] * dndv[0] + dndv[1] * dndv[1] + dndv[2] * dndv[2];
  double nDotNvv = n[0] * dndndvdv[0] + n[1] * dndndvdv[1] + 
    n[2] * dndndvdv[2];
  
  double norm = sqrt(nDotN);
  double normCubed = nDotN * norm;
  double normToFive = nDotN * normCubed;

  x = (nDotN * dndndvdv[0] - 2 * nDotNv * dndv[0] - 
       (nvDotNv + nDotNvv) * n[0]) / normCubed +
    3 * nDotNv * nDotNv * n[0] / normToFive;
  y = (nDotN * dndndvdv[1] - 2 * nDotNv * dndv[1] - 
       (nvDotNv + nDotNvv) * n[1]) / normCubed +
    3 * nDotNv * nDotNv * n[1] / normToFive;
  z = (nDotN * dndndvdv[2] - 2 * nDotNv * dndv[2] - 
       (nvDotNv + nDotNvv) * n[2]) / normCubed +
    3 * nDotNv * nDotNv * n[2] / normToFive;
}

void ProjectionSurface::
Rotate(double A0, double A1, double A2)
{
  double tol = 1.e-14;

  A0 = A0 * M_PI / 180.;
  A1 = A1 * M_PI / 180.;
  A2 = A2 * M_PI / 180.;

  double cosA0 = cos(A0);
  double sinA0 = sin(A0);
  double cosA1 = cos(A1);
  double sinA1 = sin(A1);
  double cosA2 = cos(A2);
  double sinA2 = sin(A2);

  double c[3], E0[3], E1[3], E2[3];

  for (int l = 0; l < 3; l++) {
    E0[l] = E0_[l];
    E1[l] = E1_[l];
    E2[l] = E2_[l];
  }

  c[0] = cosA1 * cosA2;
  c[1] = cosA1 * sinA2;
  c[2] = - sinA1;

  for (int l = 0; l < 3; l++)
    E0_[l] = c[0] * E0[l] + c[1] * E1[l] + c[2] * E2[l];

  c[0] = sinA0 * sinA1 * cosA2 - cosA0 * sinA2;
  c[1] = sinA0 * sinA1 * sinA2 + cosA0 * cosA2;;
  c[2] = sinA0 * cosA1;

  for (int l = 0; l < 3; l++)
    E1_[l] = c[0] * E0[l] + c[1] * E1[l] + c[2] * E2[l];

  c[0] = cosA0 * sinA1 * cosA2 + sinA0 * sinA2;
  c[1] = cosA0 * sinA1 * sinA2 - sinA0 * cosA2;;
  c[2] = cosA0 * cosA1;

  for (int l = 0; l < 3; l++)
    E2_[l] = c[0] * E0[l] + c[1] * E1[l] + c[2] * E2[l];
}

void ProjectionSurface::
Translate(double D0, double D1, double D2)
{
  O_[0] += D0;
  O_[1] += D1;
  O_[2] += D2;
}

void ProjectionSurface::
Rescale(double S0, double S1, double S2)
{
  scale_[0] *= S0;
  scale_[1] *= S1;
  scale_[2] *= S2;
}
