// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "CondNumBasis.h"

#include "GmshDefines.h"
#include "GmshMessage.h"

#include <vector>
#include "polynomialBasis.h"
#include "pyramidalBasis.h"
#include "pointsGenerators.h"
#include "BasisFactory.h"
#include "Numeric.h"


namespace {


// Compute the determinant of a 3x3 matrix
inline double calcDet3x3(double M11, double M12, double M13,
                         double M21, double M22, double M23,
                         double M31, double M32, double M33)
{
  return M11 * (M22*M33 - M23*M32)
       - M12 * (M21*M33 - M23*M31)
       + M13 * (M21*M32 - M22*M31);
}


// Compute the squared Frobenius norm of the inverse of a matrix
template<bool sign>
inline double calcInvCondNum2D(double dxdX, double dxdY,
                               double dydX, double dydY,
                               double dzdX, double dzdY,
                               double nx, double ny, double nz)
{
  static const double Eps = 1e-10;
  const double dxdXSq = dxdX*dxdX, dydXSq = dydX*dydX, dzdXSq = dzdX*dzdX;
  const double dxdYSq = dxdY*dxdY, dydYSq = dydY*dydY, dzdYSq = dzdY*dzdY;
  const double Dx = dxdXSq - dxdYSq, Dy = dydXSq - dydYSq;
  const double Cx = dxdX * dxdY, Cy = dydX * dydY;
  const double S1 = dzdYSq * dzdYSq;
  const double S2 = (dzdXSq - Dy - Dx) * dzdYSq;
  const double S3 = (Cy + Cx) * dzdX * dzdY;
  const double S4 = dzdXSq * dzdXSq;
  const double S5 = (Dy + Dx) * dzdXSq;
  const double S6 = Cx * Cy;
  const double S7 = dydXSq * dydXSq;
  const double S8 = Dy*dydXSq;
  const double S9 = dxdXSq * dxdXSq;
  const double S10 = Dx*dxdXSq;
  const double S11 = Dy*Dy;
  const double S12 = Dx*Dy;
  const double S13 = Dx*Dx;
  const double S = 2.*(S2+S5+S12)+ 4.*(S7-S8+S9-S10) + 8.*(S3+S6) + S1+S4+S11+S13;
  const double N = dxdXSq + dxdYSq + dydXSq + dydYSq + dzdXSq + dzdYSq;
  const double sqrtS = sqrt(S);
  const double sigma1Sq = 0.5 * (N + sqrtS), sigma2Sq = 0.5 * (N - sqrtS);
  if (sigma2Sq < Eps) return 0.;
  const double iCN = 2. / sqrt((sigma1Sq + sigma2Sq) * (1./sigma1Sq + 1./sigma2Sq));
  if (sign) {
    const double lnx = dydX*dzdY - dzdX*dydY, lny = dzdX*dxdY - dxdX*dzdY,      // Local normal from mapping gradients
                 lnz = dxdX*dydY - dydX*dxdY;
    const double dp = lnx*nx + lny*ny + lnz*nz;                                 // Dot product to determine element validity
    if (dp == 0.) return 0.;
    return (dp > 0.) ? iCN : -iCN;
  }
  else
    return iCN;
//  return std::min(sqrt(sigma1Sq), sqrt(sigma2Sq)) / std::max(sqrt(sigma1Sq), sqrt(sigma2Sq));
}


// Compute the squared Frobenius norm of the inverse of a matrix
template<bool sign>
inline double calcInvCondNum3D(double J11, double J12, double J13,
                               double J21, double J22, double J23,
                               double J31, double J32, double J33)
{
  const double D = calcDet3x3(J11, J12, J13, J21, J22, J23, J31, J32, J33);
  if (D == 0.) return 0.;
  const double I11 = J22*J33-J23*J32, I12 = J13*J32-J12*J33, I13 = J12*J23-J13*J22,
               I21 = J23*J31-J21*J33, I22 = J11*J33-J13*J31, I23 = J13*J21-J11*J23,
               I31 = J21*J32-J22*J31, I32 = J12*J31-J11*J32, I33 = J11*J22-J12*J21;
  const double nSqJ = J11*J11 + J12*J12 + J13*J13
                    + J21*J21 + J22*J22 + J23*J23
                    + J31*J31 + J32*J32 + J33*J33;
  const double nSqDInvJ = I11*I11 + I12*I12 + I13*I13
                        + I21*I21 + I22*I22 + I23*I23
                        + I31*I31 + I32*I32 + I33*I33;
  if (sign)
    return 3.*D/sqrt(nSqJ*nSqDInvJ);
  else
    return 3.*std::fabs(D)/sqrt(nSqJ*nSqDInvJ);
}


// Compute condition number and its gradients
// w.r.t. node positions, at one location in a 2D element
template<bool sign>
inline void calcGradInvCondNum2D(double dxdX, double dxdY,
                                 double dydX, double dydY,
                                 double dzdX, double dzdY,
                                 double nx, double ny, double nz,
                                 int i, int numMapNodes,
                                 const fullMatrix<double> &gSMatX,
                                 const fullMatrix<double> &gSMatY,
                                 fullMatrix<double> &IDI)
{
  bool posJac = true;
  if (sign) {
    const double lnx = dydX*dzdY - dzdX*dydY, lny = dzdX*dxdY - dxdX*dzdY,            // Local normal from mapping gradients
                 lnz = dxdX*dydY - dydX*dxdY;
    const double dp = lnx*nx + lny*ny + lnz*nz;                                       // Dot product to determine element validity
    posJac = (dp > 0.);
  }

  const double dxdXSq = dxdX*dxdX, dydXSq = dydX*dydX, dzdXSq = dzdX*dzdX;
  const double dxdYSq = dxdY*dxdY, dydYSq = dydY*dydY, dzdYSq = dzdY*dzdY;
  const double Dx = dxdXSq - dxdYSq, Dy = dydXSq - dydYSq;
  const double Cx = dxdX * dxdY, Cy = dydX * dydY;
  const double S1 = dzdYSq * dzdYSq;
  const double S2 = (dzdXSq - Dy - Dx) * dzdYSq;
  const double S3 = (Cy + Cx) * dzdX * dzdY;
  const double S4 = dzdXSq * dzdXSq;
  const double S5 = (Dy + Dx) * dzdXSq;
  const double S6 = Cx * Cy;
  const double S7 = dydXSq * dydXSq;
  const double S8 = Dy*dydXSq;
  const double S9 = dxdXSq * dxdXSq;
  const double S10 = Dx*dxdXSq;
  const double S11 = Dy*Dy;
  const double S12 = Dx*Dy;
  const double S13 = Dx*Dx;
  const double S = 2.*(S2+S5+S12)+ 4.*(S7-S8+S9-S10) + 8.*(S3+S6) + S1+S4+S11+S13;
  if (S == 0.) {                                                                        // S == 0. -> Ideal element
    for (int j = 0; j<3*numMapNodes; j++) IDI(i, j) = 0.;
    IDI(i, 3*numMapNodes) = posJac ? 1. : -1.;
    return;
  }
  const double N = dxdXSq + dxdYSq + dydXSq + dydYSq + dzdXSq + dzdYSq;
  const double sqrtS = sqrt(S), invSqrtS = 1./sqrtS;
  const double sigma1Sq = 0.5 * (N + sqrtS), sigma2Sq = 0.5 * (N - sqrtS);
//  if (sigma2Sq < Eps) {                                                               // TODO: Degenerate element (sigma2 == 0.)
//    const double dnx = dydX*nz - dzdX*ny, dny = dzdX*nx - dxdX*nz,
//                 dnz = dxdX*ny - dydX*nx;
//
//  }
  const double invSigma1Sq = 1./sigma1Sq;
  const double invSigma2Sq = 1./sigma2Sq;
  const double invProd = 1. / ((sigma1Sq + sigma2Sq) * (invSigma1Sq + invSigma2Sq));
  const double invSqrtProd = sqrt(invProd);
  IDI(i, 3*numMapNodes) = posJac ? 2. * invSqrtProd : -2. * invSqrtProd;
//  std::cout << "DBGTT: Value " << i << "\n";
//  std::cout << "DBGTT:   -> I = " << IDI(i, 3*numMapNodes) << "\n";
//  std::cout << "DBGTT:   -> S = " << S << ", sqrt(S) = " << sqrtS << "\n";
//  std::cout << "DBGTT:   -> N = " << N << "\n";
//  std::cout << "DBGTT:   -> sigma1Sq, sigma2Sq = (" << sigma1Sq << ", " << sigma2Sq << ")\n";

  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dPhidY = gSMatY(i, j);
//    std::cout << "DBGTT:   -> Node " << j << ":\n";

    const double ddxdXSqdxj = 2.*dPhidX*dxdX, ddxdYSqdxj = 2.*dPhidY*dxdY;
    const double dDxdxj = ddxdXSqdxj - ddxdYSqdxj;
    const double dCxdxj = dPhidX*dxdY + dxdX*dPhidY;
    const double dS2dxj = -dDxdxj * dzdYSq;
    const double dS3dxj = dCxdxj * dzdX * dzdY;
    const double dS5dxj = dDxdxj * dzdXSq;
    const double dS6dxj = dCxdxj * Cy;
    const double dS9dxj = 2. * ddxdXSqdxj * dxdXSq;
    const double dS10dxj = dDxdxj*dxdXSq + Dx*ddxdXSqdxj;
    const double dS12dxj = dDxdxj * Dy;
    const double dS13dxj = 2. * dDxdxj* Dx;
    const double dSdxj = 2.*(dS2dxj+dS5dxj+dS12dxj)+ 4.*(dS9dxj-dS10dxj)
                       + 8.*(dS3dxj+dS6dxj) + dS13dxj;
    const double dNdxj = ddxdXSqdxj + ddxdYSqdxj;
    const double dsqrtSdxj = 0.5*dSdxj*invSqrtS;
    const double dsigma1Sqdxj = 0.5 * (dNdxj + dsqrtSdxj),
                 dsigma2Sqdxj = 0.5 * (dNdxj - dsqrtSdxj);
    const double dinvSigma1Sqdxj = -dsigma1Sqdxj*invSigma1Sq*invSigma1Sq,
                 dinvSigma2Sqdxj = -dsigma2Sqdxj*invSigma2Sq*invSigma2Sq;
    const double dProddxj = (dsigma1Sqdxj + dsigma2Sqdxj) * (invSigma1Sq + invSigma2Sq)
                          + (sigma1Sq + sigma2Sq) * (dinvSigma1Sqdxj + dinvSigma2Sqdxj);
    const double mdiCNdxj = dProddxj*invProd*invSqrtProd;
    IDI(i, j) = posJac ? -mdiCNdxj : mdiCNdxj;
//    std::cout << "DBGTT:     -> d(dxdX)dxj  = " << dPhidX << ", d(dxdY)dxj = " << dPhidY << "\n";
//    std::cout << "DBGTT:     -> dNdxj  = " << dNdxj << ", dSdxj = " << dSdxj << "\n";
//    std::cout << "DBGTT:     -> dsigma1Sqdxj = " << dsigma1Sqdxj << ", dsigma2Sqdxj = " << dsigma2Sqdxj << "\n";
//    std::cout << "DBGTT:     -> dinvSigma1Sqdxj = " << dinvSigma1Sqdxj << ", dinvSigma2Sqdxj = " << dinvSigma2Sqdxj << "\n";
//    std::cout << "DBGTT:     -> mdiCNdxj = " << mdiCNdxj
//              << ", -dsigma2Sqdxj/sqrt(sigma1Sq*sigma2Sq) = " << -dsigma2Sqdxj/sqrt(sigma1Sq*sigma2Sq)
//              << ", T1 = " << -dNdxj/sqrt(N*N-S) << ", T21 = " << (0.5*dSdxj/sqrtS)/sqrt(N*N-S) << "\n";

    const double ddydXSqdyj = 2.*dPhidX*dydX, ddydYSqdyj = 2.*dPhidY*dydY;
    const double dDydyj = ddydXSqdyj - ddydYSqdyj;
    const double dCydyj = dPhidX*dydY + dydX*dPhidY;
    const double dS2dyj = -dDydyj * dzdYSq;
    const double dS3dyj = dCydyj * dzdX * dzdY;
    const double dS5dyj = dDydyj * dzdXSq;
    const double dS6dyj = Cx * dCydyj;
    const double dS7dyj = 2. * ddydXSqdyj * dydXSq;
    const double dS8dyj = dDydyj*dydXSq + Dy*ddydXSqdyj;
    const double dS11dyj = 2. * dDydyj * Dy;
    const double dS12dyj = Dx* dDydyj;
    const double dSdyj = 2.*(dS2dyj+dS5dyj+dS12dyj)+ 4.*(dS7dyj-dS8dyj)
                       + 8.*(dS3dyj+dS6dyj) + dS11dyj;
    const double dNdyj = ddydXSqdyj + ddydYSqdyj;
    const double dsqrtSdyj = 0.5*dSdyj*invSqrtS;
    const double dsigma1Sqdyj = 0.5 * (dNdyj + dsqrtSdyj),
                 dsigma2Sqdyj = 0.5 * (dNdyj - dsqrtSdyj);
    const double dinvSigma1Sqdyj = -dsigma1Sqdyj*invSigma1Sq*invSigma1Sq,
                 dinvSigma2Sqdyj = -dsigma2Sqdyj*invSigma2Sq*invSigma2Sq;
    const double dProddyj = (dsigma1Sqdyj + dsigma2Sqdyj) * (invSigma1Sq + invSigma2Sq)
                          + (sigma1Sq + sigma2Sq) * (dinvSigma1Sqdyj + dinvSigma2Sqdyj);
    const double mdiCNdyj = dProddyj*invProd*invSqrtProd;
    IDI(i, j+numMapNodes) = posJac ? -mdiCNdyj : mdiCNdyj;
//    std::cout << "DBGTT:     -> d(dydX)dyj  = " << dPhidX << ", d(dydY)dyj = " << dPhidY << "\n";
//    std::cout << "DBGTT:     -> dNdyj  = " << dNdyj << ", dSdyj = " << dSdyj << "\n";
//    std::cout << "DBGTT:     -> dsigma1Sqdyj = " << dsigma1Sqdyj << ", dsigma2Sqdyj = " << dsigma2Sqdyj << "\n";
//    std::cout << "DBGTT:     -> dinvSigma1Sqdyj = " << dinvSigma1Sqdyj << ", dinvSigma2Sqdyj = " << dinvSigma2Sqdyj << "\n";

    const double ddzdXSqdzj = 2.*dPhidX*dzdX, ddzdYSqdzj = 2.*dPhidY*dzdY;
    const double dS1dzj = 2. * ddzdYSqdzj * dzdYSq;
    const double dS2dzj = (dzdXSq - Dy - Dx) * ddzdYSqdzj;
    const double dS3dzj = (Cy + Cx) *
                          (ddzdXSqdzj*dzdY + dzdX*ddzdYSqdzj);
    const double dS4dzj = 2. * ddzdXSqdzj * dzdXSq;
    const double dS5dzj = (Dy + Dx) * ddzdXSqdzj;
    const double dSdzj = 2.*(dS2dzj+dS5dzj) + 8.*dS3dzj + dS1dzj+dS4dzj;
    const double dNdzj = ddzdXSqdzj + ddzdYSqdzj;
    const double dsqrtSdzj = 0.5*dSdzj*invSqrtS;
    const double dsigma1Sqdzj = 0.5 * (dNdzj + dsqrtSdzj),
                 dsigma2Sqdzj = 0.5 * (dNdzj - dsqrtSdzj);
    const double dinvSigma1Sqdzj = -dsigma1Sqdzj*invSigma1Sq*invSigma1Sq,
                 dinvSigma2Sqdzj = -dsigma2Sqdzj*invSigma2Sq*invSigma2Sq;
    const double dProddzj = (dsigma1Sqdzj + dsigma2Sqdzj) * (invSigma1Sq + invSigma2Sq)
                          + (sigma1Sq + sigma2Sq) * (dinvSigma1Sqdzj + dinvSigma2Sqdzj);
    const double mdiCNdzj = dProddzj*invProd*invSqrtProd;
    IDI(i, j+2*numMapNodes) = posJac ? -mdiCNdzj : mdiCNdzj;
//    std::cout << "DBGTT:     -> d(dzdX)dzj  = " << dPhidX << ", d(dzdY)dzj = " << dPhidY << "\n";
//    std::cout << "DBGTT:     -> dNdzj  = " << dNdzj << ", dSdzj = " << dSdzj << "\n";
//    std::cout << "DBGTT:     -> dsigma1Sqdzj = " << dsigma1Sqdzj << ", dsigma2Sqdzj = " << dsigma2Sqdzj << "\n";
//    std::cout << "DBGTT:     -> dinvSigma1Sqdzj = " << dinvSigma1Sqdzj << ", dinvSigma2Sqdzj = " << dinvSigma2Sqdzj << "\n";
//    std::cout << "DBGTT:     -> dId{x,y,z} = (" << IDI(i, j) << ", "
//              << IDI(i, j+numMapNodes) << ", " << IDI(i, j+2*numMapNodes) << ")\n";
  }
}


// Compute condition number and its gradients
// w.r.t. node positions, at one location in a 3D element
template<bool sign>
inline void calcGradInvCondNum3D(double dxdX, double dxdY, double dxdZ,
                                 double dydX, double dydY, double dydZ,
                                 double dzdX, double dzdY, double dzdZ,
                                 int i, int numMapNodes,
                                 const fullMatrix<double> &gSMatX,
                                 const fullMatrix<double> &gSMatY,
                                 const fullMatrix<double> &gSMatZ,
                                 fullMatrix<double> &IDI)
{
  const double normJSq = dxdX*dxdX + dxdY*dxdY + dxdZ*dxdZ
                       + dydX*dydX + dydY*dydY + dydZ*dydZ
                       + dzdX*dzdX + dzdY*dzdY + dzdZ*dzdZ;
  const double I11 = dydY*dzdZ - dydZ*dzdY, I12 = dxdZ*dzdY - dxdY*dzdZ,
               I13 = dxdY*dydZ - dxdZ*dydY, I21 = dydZ*dzdX - dydX*dzdZ,
               I22 = dxdX*dzdZ - dxdZ*dzdX, I23 = dxdZ*dydX - dxdX*dydZ,
               I31 = dydX*dzdY - dydY*dzdX, I32 = dxdY*dzdX - dxdX*dzdY,
               I33 = dxdX*dydY - dxdY*dydX;
  const double normISq = I11*I11 + I12*I12 + I13*I13
                       + I21*I21 + I22*I22 + I23*I23
                       + I31*I31 + I32*I32 + I33*I33;
  const double invProd = 1./(normJSq*normISq), invSqrtProd = sqrt(invProd);
  const double D = calcDet3x3(dxdX, dxdY, dxdZ,
                              dydX, dydY, dydZ,
                              dzdX, dzdY, dzdZ);
  const bool reverse = (!sign && (D < 0.));
  const double sICN = 3.*D*invSqrtProd;
  IDI(i, 3*numMapNodes) = reverse ? -sICN : sICN;

  for (int j = 0; j < numMapNodes; j++) {
    const double &dPhidX = gSMatX(i, j);
    const double &dPhidY = gSMatY(i, j);
    const double &dPhidZ = gSMatZ(i, j);

    const double dNormJSqdxj = 2.*(dPhidX*dxdX + dPhidY*dxdY + dPhidZ*dxdZ);
    const double dNormISqdxj = 2.*((dPhidZ*dzdY - dPhidY*dzdZ)*I12 + (dPhidY*dydZ - dPhidZ*dydY)*I13
                                 + (dPhidX*dzdZ - dPhidZ*dzdX)*I22 + (dPhidZ*dydX - dPhidX*dydZ)*I23
                                 + (dPhidY*dzdX - dPhidX*dzdY)*I32 + (dPhidX*dydY - dPhidY*dydX)*I33);
    const double dProddxj = dNormJSqdxj*normISq + dNormISqdxj*normJSq;
    const double dDdxj = dPhidX * dydY * dzdZ + dzdX * dPhidY * dydZ +
                         dydX * dzdY * dPhidZ - dzdX * dydY * dPhidZ -
                         dPhidX * dzdY * dydZ - dydX * dPhidY * dzdZ;
    const double dsICNdxj = 3. * (dDdxj*invSqrtProd - 0.5*D*dProddxj*invProd*invSqrtProd);
    IDI(i, j) = reverse ? -dsICNdxj : dsICNdxj;

    const double dNormJSqdyj = 2.*(dPhidX*dydX + dPhidY*dydY + dPhidZ*dydZ);
    const double dNormISqdyj = 2.*((dPhidY*dzdZ - dPhidZ*dzdY)*I11 + (dxdY*dPhidZ - dxdZ*dPhidY)*I13
                                 + (dPhidZ*dzdX - dPhidX*dzdZ)*I21 + (dxdZ*dPhidX - dxdX*dPhidZ)*I23
                                 + (dPhidX*dzdY - dPhidY*dzdX)*I31 + (dxdX*dPhidY - dxdY*dPhidX)*I33);
    const double dProddyj = dNormJSqdyj*normISq + dNormISqdyj*normJSq;
    const double dDdyj = dxdX * dPhidY * dzdZ + dzdX * dxdY * dPhidZ +
                         dPhidX * dzdY * dxdZ - dzdX * dPhidY * dxdZ -
                         dxdX * dzdY * dPhidZ - dPhidX * dxdY * dzdZ;
    const double dsICNdyj = 3. * (dDdyj*invSqrtProd - 0.5*D*dProddyj*invProd*invSqrtProd);
    IDI(i, j+numMapNodes) = reverse ? -dsICNdyj : dsICNdyj;

    const double dNormJSqdzj = 2.*(dPhidX*dzdX + dPhidY*dzdY + dPhidZ*dzdZ);
    const double dNormISqdzj = 2.*((dydY*dPhidZ - dydZ*dPhidY)*I11 + (dxdZ*dPhidY - dxdY*dPhidZ)*I12
                                 + (dydZ*dPhidX - dydX*dPhidZ)*I21 + (dxdX*dPhidZ - dxdZ*dPhidX)*I22
                                 + (dydX*dPhidY - dydY*dPhidX)*I31 + (dxdY*dPhidX - dxdX*dPhidY)*I32);
    const double dProddzj = dNormJSqdzj*normISq + dNormISqdzj*normJSq;
    const double dDdzj = dxdX * dydY * dPhidZ + dPhidX * dxdY * dydZ +
                         dydX * dPhidY * dxdZ - dPhidX * dydY * dxdZ -
                         dxdX * dPhidY * dydZ - dydX * dxdY * dPhidZ;
    const double dsICNdzj = 3. * (dDdzj*invSqrtProd - 0.5*D*dProddzj*invProd*invSqrtProd);
    IDI(i, j+2*numMapNodes) = reverse ? -dsICNdzj : dsICNdzj;
  }
}


}


CondNumBasis::CondNumBasis(int tag, int cnOrder) :
    _tag(tag), _dim(ElementType::DimensionFromTag(tag)),
    _condNumOrder(cnOrder >= 0 ? cnOrder : condNumOrder(tag))
{
  const bool serendip = false;
  FuncSpaceData data(true, tag, _condNumOrder, &serendip);

  _gradBasis = BasisFactory::getGradientBasis(data);

  fullMatrix<double> lagPoints;                                  // Sampling points
  gmshGeneratePoints(data, lagPoints);
  _nCondNumNodes = lagPoints.size1();
  _nMapNodes = BasisFactory::getNodalBasis(tag)->getNumShapeFunctions();

  // Store shape function gradients of mapping at condition number nodes
  _gradBasis = BasisFactory::getGradientBasis(tag, _condNumOrder);

  // Compute shape function gradients of primary mapping at barycenter,
  // in order to compute normal to straight element
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int primMapType = ElementType::getTag(parentType, 1, false);
  const nodalBasis *primMapBasis = BasisFactory::getNodalBasis(primMapType);
  _nPrimMapNodes = primMapBasis->getNumShapeFunctions();

  double xBar = 0., yBar = 0., zBar = 0.;
  double barycenter[3] = {0., 0., 0.};
  for (int i = 0; i < _nPrimMapNodes; i++) {
    for (int j = 0; j < primMapBasis->points.size2(); ++j) {
      barycenter[j] += primMapBasis->points(i, j);
    }
  }
  barycenter[0] /= _nPrimMapNodes;
  barycenter[1] /= _nPrimMapNodes;
  barycenter[2] /= _nPrimMapNodes;

  double (*barDPsi)[3] = new double[_nPrimMapNodes][3];
  primMapBasis->df(xBar, yBar, zBar, barDPsi);

  // TODO: Make primGradShape from ideal element
  primGradShapeBarycenterX.resize(_nPrimMapNodes);
  primGradShapeBarycenterY.resize(_nPrimMapNodes);
  primGradShapeBarycenterZ.resize(_nPrimMapNodes);
  for (int j=0; j<_nPrimMapNodes; j++) {
    primGradShapeBarycenterX(j) = barDPsi[j][0];
    primGradShapeBarycenterY(j) = barDPsi[j][1];
    primGradShapeBarycenterZ(j) = barDPsi[j][2];
  }

  delete[] barDPsi;
}


int CondNumBasis::condNumOrder(int tag)
{
  const int parentType = ElementType::ParentTypeFromTag(tag);
  const int order = ElementType::OrderFromTag(tag);
  return condNumOrder(parentType, order);
}


int CondNumBasis::condNumOrder(int parentType, int order)
{
  switch (parentType) {
    case TYPE_PNT : return 0;
    case TYPE_LIN : return order - 1;
    case TYPE_TRI : return 2*order - 2;
    case TYPE_QUA : return 2*order - 1;
    case TYPE_TET : return 3*order - 3;
    case TYPE_PRI : return 3*order - 1;
    case TYPE_HEX : return 3*order - 1;
    case TYPE_PYR : return 3*order - 3;
    default :
      Msg::Error("Unknown element type %d, return order 0", parentType);
      return 0;
  }
}


// Calculate the inverse condition number in Frobenius norm for one element, with normal vectors to straight
// element for regularization. Evaluation points depend on the given matrices for shape function gradients.
template<bool sign>
inline void CondNumBasis::getInvCondNumGeneral(int nCondNumNodes,
                                               const fullMatrix<double> &gSMatX,
                                               const fullMatrix<double> &gSMatY,
                                               const fullMatrix<double> &gSMatZ,
                                               const fullMatrix<double> &nodesXYZ,
                                               const fullMatrix<double> &normals,
                                               fullVector<double> &condNum) const
{
  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nCondNumNodes; i++) condNum(i) = 1.;
      break;
    }

    case 1 : {
      Msg::Warning("Inverse condition number not implemented in 1D");
      condNum.setAll(0.);
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(nCondNumNodes,3), dxyzdY(nCondNumNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < nCondNumNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &nx = normals(0,0), &ny = normals(0,1), &nz = normals(0,2);
        condNum(i) = calcInvCondNum2D<sign>(dxdX, dxdY, dydX, dydY, dzdX, dzdY, nx, ny, nz);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(nCondNumNodes, 3), dxyzdY(nCondNumNodes, 3), dxyzdZ(nCondNumNodes, 3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      gSMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < nCondNumNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        condNum(i) = calcInvCondNum3D<sign>(dxdX, dxdY, dxdZ,
                                            dydX, dydY, dydZ,
                                            dzdX, dzdY, dzdZ);
     }
      break;
    }
  }
}


void CondNumBasis::getInvCondNumGeneral(int nCondNumNodes,
                                        const fullMatrix<double> &gSMatX,
                                        const fullMatrix<double> &gSMatY,
                                        const fullMatrix<double> &gSMatZ,
                                        const fullMatrix<double> &nodesXYZ,
                                        fullVector<double> &invCond) const
{
  fullMatrix<double> dumNormals;
  getInvCondNumGeneral<false>(nCondNumNodes, gSMatX, gSMatY, gSMatZ,
                              nodesXYZ, dumNormals, invCond);
}


void CondNumBasis::getSignedInvCondNumGeneral(int nCondNumNodes,
                                              const fullMatrix<double> &gSMatX,
                                              const fullMatrix<double> &gSMatY,
                                              const fullMatrix<double> &gSMatZ,
                                              const fullMatrix<double> &nodesXYZ,
                                              const fullMatrix<double> &normals,
                                              fullVector<double> &invCond) const
{
  getInvCondNumGeneral<true>(nCondNumNodes, gSMatX, gSMatY, gSMatZ,
                             nodesXYZ, normals, invCond);
}


// Calculate the inverse condition number in Frobenius norm and its gradients w.r.t. node position,
// with normal vectors to straight element  for regularization. Evaluation points depend on the
// given matrices for shape function gradients.
template<bool sign>
inline void CondNumBasis::getInvCondNumAndGradientsGeneral(int nCondNumNodes,
                                                           const fullMatrix<double> &gSMatX,
                                                           const fullMatrix<double> &gSMatY,
                                                           const fullMatrix<double> &gSMatZ,
                                                           const fullMatrix<double> &nodesXYZ,
                                                           const fullMatrix<double> &normals,
                                                           fullMatrix<double> &IDI) const
{
  fullMatrix<double> JDJ(nCondNumNodes, 3*_nMapNodes+1);

  switch (_dim) {

    case 0 : {
      for (int i = 0; i < nCondNumNodes; i++) {
        for (int j = 0; j < _nMapNodes; j++) {
          IDI(i,j) = 0.;
          IDI(i,j+1*_nMapNodes) = 0.;
          IDI(i,j+2*_nMapNodes) = 0.;
        }
        IDI(i,3*_nMapNodes) = 1.;
      }
      break;
    }

    case 1 : {
      Msg::Warning("Inverse condition number not implemented in 1D");
      IDI.setAll(0.);
      break;
    }

    case 2 : {
      fullMatrix<double> dxyzdX(nCondNumNodes,3), dxyzdY(nCondNumNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      for (int i = 0; i < nCondNumNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &nx = normals(0,0), &ny = normals(0,1), &nz = normals(0,2);
        calcGradInvCondNum2D<sign>(dxdX, dxdY, dydX, dydY, dzdX, dzdY,
                                   nx, ny, nz, i, _nMapNodes, gSMatX, gSMatY, IDI);
      }
      break;
    }

    case 3 : {
      fullMatrix<double> dxyzdX(nCondNumNodes,3), dxyzdY(nCondNumNodes,3), dxyzdZ(nCondNumNodes,3);
      gSMatX.mult(nodesXYZ, dxyzdX);
      gSMatY.mult(nodesXYZ, dxyzdY);
      gSMatZ.mult(nodesXYZ, dxyzdZ);
      for (int i = 0; i < nCondNumNodes; i++) {
        const double &dxdX = dxyzdX(i,0), &dydX = dxyzdX(i,1), &dzdX = dxyzdX(i,2);
        const double &dxdY = dxyzdY(i,0), &dydY = dxyzdY(i,1), &dzdY = dxyzdY(i,2);
        const double &dxdZ = dxyzdZ(i,0), &dydZ = dxyzdZ(i,1), &dzdZ = dxyzdZ(i,2);
        calcGradInvCondNum3D<sign>(dxdX, dxdY, dxdZ,
                                   dydX, dydY, dydZ,
                                   dzdX, dzdY, dzdZ,
                                   i, _nMapNodes,
                                   gSMatX, gSMatY, gSMatZ, IDI);
      }
      break;
    }
  }
}


void CondNumBasis::getInvCondNumAndGradientsGeneral(int nCondNumNodes,
                                                    const fullMatrix<double> &gSMatX,
                                                    const fullMatrix<double> &gSMatY,
                                                    const fullMatrix<double> &gSMatZ,
                                                    const fullMatrix<double> &nodesXYZ,
                                                    fullMatrix<double> &IDI) const
{
  fullMatrix<double> dumNormals;
  getInvCondNumAndGradientsGeneral<false>(nCondNumNodes, gSMatX, gSMatY, gSMatZ,
                                          nodesXYZ, dumNormals, IDI);
}


void CondNumBasis::getSignedInvCondNumAndGradientsGeneral(int nCondNumNodes,
                                                          const fullMatrix<double> &gSMatX,
                                                          const fullMatrix<double> &gSMatY,
                                                          const fullMatrix<double> &gSMatZ,
                                                          const fullMatrix<double> &nodesXYZ,
                                                          const fullMatrix<double> &normals,
                                                          fullMatrix<double> &IDI) const
{
  getInvCondNumAndGradientsGeneral<true>(nCondNumNodes, gSMatX, gSMatY, gSMatZ,
                                         nodesXYZ, normals, IDI);
}
