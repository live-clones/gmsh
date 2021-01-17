// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "robustPredicates.h"
#include "qualityMeasures.h"
#include "BDS.h"
#include "MVertex.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MPrism.h"
#include "MHexahedron.h"
#include "Numeric.h"
#include "polynomialBasis.h"
#include "JacobianBasis.h"
#include "GmshMessage.h"
#include <limits>
#include <string.h>

namespace {

  // Compute unit vector and gradients w.r.t. x0, y0, z0
  // Remark: gradients w.r.t. x1, y1, z1 not computed as they are just the
  // opposite
  inline void unitVecAndGrad(const SPoint3 &p0, const SPoint3 &p1,
                             SVector3 &vec, std::vector<SVector3> &grad)
  {
    vec = SVector3(p0, p1);
    const double n = vec.normalize(), invN = 1 / n;
    grad[0] = invN * vec[0] * vec;
    grad[0][0] -= invN; // dv01/dx0
    grad[1] = invN * vec[1] * vec;
    grad[1][1] -= invN; // dv01/dy0
    grad[2] = invN * vec[2] * vec;
    grad[2][2] -= invN; // dv01/dz0
  }

  // Given vectors (0, 1) and (0, 2), their gradients and opposite of gradients,
  // and the unit normal vector, compute NCJ from area of triangle defined by
  // both vectors and gradients w.r.t. x0, y0, z0, x1, y1, z1, x2, y2, z2
  inline void
  NCJAndGrad2D(const SVector3 &v01, const std::vector<SVector3> &dv01dp0,
               const std::vector<SVector3> &dv01dp1, const SVector3 &v02,
               const std::vector<SVector3> &dv02dp0,
               const std::vector<SVector3> &dv02dp2, const SVector3 &normal,
               double &NCJ, std::vector<double> &dNCJ)
  {
    const SVector3 dvndx0 =
      crossprod(v01, dv02dp0[0]) +
      crossprod(dv01dp0[0], v02); // v01 x dv02/dx0 + dv01/dx0 x v02
    const SVector3 dvndy0 =
      crossprod(v01, dv02dp0[1]) +
      crossprod(dv01dp0[1], v02); // v01 x dv02/dy0 + dv01/dy0 x v02
    const SVector3 dvndz0 =
      crossprod(v01, dv02dp0[2]) +
      crossprod(dv01dp0[2], v02); // v01 x dv02/dz0 + dv01/dz0 x v02
    const SVector3 dvndx1 =
      crossprod(dv01dp1[0], v02); // dv01/dx1 x v02 (= -dv01/dx0 x v02)
    const SVector3 dvndy1 =
      crossprod(dv01dp1[1], v02); // dv01/dy1 x v02 (= -dv01/dy0 x v02)
    const SVector3 dvndz1 =
      crossprod(dv01dp1[2], v02); // dv01/dz1 x v02 (= -dv01/dz0 x v02)
    const SVector3 dvndx2 =
      crossprod(v01, dv02dp2[0]); // v01 x dv02/dx2 (= v01 x -dv02/dx0)
    const SVector3 dvndy2 =
      crossprod(v01, dv02dp2[1]); // v01 x dv02/dy2 (= v01 x -dv02/dy0)
    const SVector3 dvndz2 =
      crossprod(v01, dv02dp2[2]); // v01 x dv02/dz2 (= v01 x -dv02/dz0)

    SVector3 vn = crossprod(v01, v02);
    NCJ = dot(vn, normal); // NCJ
    dNCJ[0] = dot(dvndx0, normal); // dNCJ/dx0
    dNCJ[1] = dot(dvndy0, normal); // dNCJ/dy0
    dNCJ[2] = dot(dvndz0, normal); // dNCJ/dz0
    dNCJ[3] = dot(dvndx1, normal); // dNCJ/dx1
    dNCJ[4] = dot(dvndy1, normal); // dNCJ/dy1
    dNCJ[5] = dot(dvndz1, normal); // dNCJ/dz1
    dNCJ[6] = dot(dvndx2, normal); // dNCJ/dx2
    dNCJ[7] = dot(dvndy2, normal); // dNCJ/dy2
    dNCJ[8] = dot(dvndz2, normal); // dNCJ/dz2
  }

  //// Revert vector and gradients
  // inline void revertVG(const fullMatrix<double> &vg, fullMatrix<double> &res)
  //{
  //  res(0, 0) = -vg(0, 3); res(0, 1) = -vg(0, 4); res(0, 2) = -vg(0, 5);
  //  res(0, 6) = -vg(0, 6); res(1, 0) = -vg(1, 3); res(1, 1) = -vg(1, 4);
  //  res(1, 2) = -vg(1, 5); res(1, 6) = -vg(1, 6); res(2, 0) = -vg(2, 3);
  //  res(2, 1) = -vg(2, 4); res(2, 2) = -vg(2, 5); res(2, 6) = -vg(2, 6);
  //}

  // Scatter the NCJ gradients at vertex iV w.r.t vertices i0, i1 and i2
  // in the vector of gradients for 2D element of nV vertices
  template <int iV, int nV, int i0, int i1, int i2>
  inline void scatterNCJGrad(const std::vector<double> &dNCJi,
                             std::vector<double> &dNCJ)
  {
    dNCJ[(iV * nV + i0) * 3] = dNCJi[0];
    dNCJ[(iV * nV + i0) * 3 + 1] = dNCJi[1];
    dNCJ[(iV * nV + i0) * 3 + 2] = dNCJi[2];
    dNCJ[(iV * nV + i1) * 3] = dNCJi[3];
    dNCJ[(iV * nV + i1) * 3 + 1] = dNCJi[4];
    dNCJ[(iV * nV + i1) * 3 + 2] = dNCJi[5];
    dNCJ[(iV * nV + i2) * 3] = dNCJi[6];
    dNCJ[(iV * nV + i2) * 3 + 1] = dNCJi[7];
    dNCJ[(iV * nV + i2) * 3 + 2] = dNCJi[8];
  }

  // Scatter the NCJ gradients at vertex iV w.r.t vertices i0, i1, i2 and i3
  // in the vector of gradients for 3D element of nV vertices
  template <int iV, int nV, int i0, int i1, int i2, int i3>
  inline void scatterNCJGrad(const std::vector<double> &dNCJi,
                             std::vector<double> &dNCJ)
  {
    dNCJ[iV * nV + i0 * 3] = dNCJi[0];
    dNCJ[iV * nV + i0 * 3 + 1] = dNCJi[1];
    dNCJ[iV * nV + i0 * 3 + 2] = dNCJi[2];
    dNCJ[iV * nV + i1 * 3] = dNCJi[3];
    dNCJ[iV * nV + i1 * 3 + 1] = dNCJi[4];
    dNCJ[iV * nV + i1 * 3 + 2] = dNCJi[5];
    dNCJ[iV * nV + i2 * 3] = dNCJi[6];
    dNCJ[iV * nV + i2 * 3 + 1] = dNCJi[7];
    dNCJ[iV * nV + i2 * 3 + 2] = dNCJi[8];
    dNCJ[iV * nV + i2 * 3] = dNCJi[9];
    dNCJ[iV * nV + i2 * 3 + 1] = dNCJi[10];
    dNCJ[iV * nV + i2 * 3 + 2] = dNCJi[11];
  }

} // namespace

double qmTriangle::gamma(const BDS_Point *p1, const BDS_Point *p2,
                         const BDS_Point *p3)
{
  return gamma(p1->X, p1->Y, p1->Z, p2->X, p2->Y, p2->Z, p3->X, p3->Y, p3->Z);
}

double qmTriangle::gamma(BDS_Face *t)
{
  BDS_Point *n[4];
  t->getNodes(n);
  return gamma(n[0], n[1], n[2]);
}

double qmTriangle::gamma(MTriangle *t)
{
  return gamma(t->getVertex(0), t->getVertex(1), t->getVertex(2));
}

double qmTriangle::gamma(const MVertex *v1, const MVertex *v2,
                         const MVertex *v3)
{
  return gamma(v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(), v3->x(),
               v3->y(), v3->z());
}

// Triangle abc
// quality is between 0 and 1
double qmTriangle::gamma(const double &xa, const double &ya, const double &za,
                         const double &xb, const double &yb, const double &zb,
                         const double &xc, const double &yc, const double &zc)
{
  // quality = rho / R = 2 * inscribed radius / circumradius
  double a[3] = {xc - xb, yc - yb, zc - zb};
  double b[3] = {xa - xc, ya - yc, za - zc};
  double c[3] = {xb - xa, yb - ya, zb - za};
  norme(a);
  norme(b);
  norme(c);
  double pva[3];
  prodve(b, c, pva);
  const double sina = norm3(pva);
  double pvb[3];
  prodve(c, a, pvb);
  const double sinb = norm3(pvb);
  double pvc[3];
  prodve(a, b, pvc);
  const double sinc = norm3(pvc);

  if(sina == 0.0 && sinb == 0.0 && sinc == 0.0)
    return 0.0;
  else
    return 2 * (2 * sina * sinb * sinc / (sina + sinb + sinc));
}

double qmTriangle::eta(MTriangle *el)
{
  MVertex *_v[3] = {el->getVertex(0), el->getVertex(1), el->getVertex(2)};

  double a1 = 180 * angle3Vertices(_v[0], _v[1], _v[2]) / M_PI;
  double a2 = 180 * angle3Vertices(_v[1], _v[2], _v[0]) / M_PI;
  double a3 = 180 * angle3Vertices(_v[2], _v[0], _v[1]) / M_PI;

  double amin = std::min(std::min(a1, a2), a3);
  double angle = std::abs(60. - amin);
  return 1. - angle / 60;
}

double qmTriangle::angles(MTriangle *e)
{
  double a = 500;
  double worst_quality = std::numeric_limits<double>::max();
  double mat[3][3];
  double mat2[3][3];
  double den = atan(a * (M_PI / 9)) + atan(a * (M_PI / 9));

  // This matrix is used to "rotate" the triangle to get each vertex
  // as the "origin" of the mapping in turn
  double rot[3][3];
  rot[0][0] = -1;
  rot[0][1] = 1;
  rot[0][2] = 0;
  rot[1][0] = -1;
  rot[1][1] = 0;
  rot[1][2] = 0;
  rot[2][0] = 0;
  rot[2][1] = 0;
  rot[2][2] = 1;
  double tmp[3][3];

  // double minAngle = 120.0;
  for(std::size_t i = 0; i < e->getNumPrimaryVertices(); i++) {
    const double u = i == 1 ? 1 : 0;
    const double v = i == 2 ? 1 : 0;
    const double w = 0;
    e->getJacobian(u, v, w, mat);
    e->getPrimaryJacobian(u, v, w, mat2);
    for(std::size_t j = 0; j < i; j++) {
      matmat(rot, mat, tmp);
      memcpy(mat, tmp, sizeof(mat));
    }
    // get angle
    double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
    double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
    double v3[3] = {mat2[0][0], mat2[0][1], mat2[0][2]};
    double v4[3] = {mat2[1][0], mat2[1][1], mat2[1][2]};
    norme(v1);
    norme(v2);
    norme(v3);
    norme(v4);
    double v12[3], v34[3];
    prodve(v1, v2, v12);
    prodve(v3, v4, v34);
    norme(v12);
    norme(v34);
    double const orientation = prosca(v12, v34);

    // If the triangle is "flipped" it's no good
    if(orientation < 0) return -std::numeric_limits<double>::max();

    double const c = prosca(v1, v2);
    double x = std::acos(c) - M_PI / 3;
    // double angle = (x+M_PI/3)/M_PI*180;
    double quality =
      (std::atan(a * (x + M_PI / 9)) + std::atan(a * (M_PI / 9 - x))) / den;
    worst_quality = std::min(worst_quality, quality);

    // minAngle = std::min(angle, minAngle);
    // printf("Angle %g ", angle);
    // printf("Quality %g\n",quality);
  }
  // printf("MinAngle %g \n", minAngle);
  // return minAngle;

  return worst_quality;
}

void qmTriangle::NCJRange(const MTriangle *el, double &valMin, double &valMax)
{
  const JacobianBasis *jac = el->getJacobianFuncSpace();
  fullMatrix<double> primNodesXYZ(3, 3);
  for(int i = 0; i < jac->getNumPrimMapNodes(); i++) {
    const MVertex *v = el->getVertex(i);
    primNodesXYZ(i, 0) = v->x();
    primNodesXYZ(i, 1) = v->y();
    primNodesXYZ(i, 2) = v->z();
  }
  fullMatrix<double> nM(1, 3);
  jac->getPrimNormal2D(primNodesXYZ, nM);
  SVector3 normal(nM(0, 0), nM(0, 1), nM(0, 2));

  std::vector<double> ncj(3);
  NCJ(el->getVertex(0)->point(), el->getVertex(1)->point(),
      el->getVertex(2)->point(), normal, ncj);
  valMin = *std::min_element(ncj.begin(), ncj.end());
  valMax = *std::max_element(ncj.begin(), ncj.end());
}

void qmTriangle::NCJ(const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                     const SVector3 &normal, std::vector<double> &NCJ)
{
  // Compute unit vectors for each edge
  SVector3 v01n(p0, p1), v12n(p1, p2), v20n(p2, p0);
  v01n.normalize();
  v12n.normalize();
  v20n.normalize();

  // Compute NCJ at vertex from unit vectors a and b as
  // 0.5*||a^b||/A_equilateral Factor = 2./sqrt(3.) = 0.5/A_equilateral
  NCJ[0] = 2.0 / std::sqrt(3.0) * dot(crossprod(v01n, -v20n), normal);
  NCJ[1] = 2.0 / std::sqrt(3.0) * dot(crossprod(v12n, -v01n), normal);
  NCJ[2] = 2.0 / std::sqrt(3.0) * dot(crossprod(v20n, -v12n), normal);
}

// Compute NCJ and its gradients at corners
// Gradients packed in vector: (dNCJ0/dx0, dNCJ0/dy0, dNCJ0/dz0,
//                              dNCJ0/dx1, ... dNCJ0/dz3, dNCJ1/dx0, ...,
//                              dNCJ3/dz3)
void qmTriangle::NCJAndGradients(const SPoint3 &p0, const SPoint3 &p1,
                                 const SPoint3 &p2, const SVector3 &normal,
                                 std::vector<double> &NCJ,
                                 std::vector<double> &dNCJ)
{
  // Factor = 2./sqrt(3.) = 0.5/A_equilateral
  static const double fact = 2. / sqrt(3.);

  // Compute unit vector, its gradients and opposite grandients for edge (0, 1)
  SVector3 v01n, v10n;
  std::vector<SVector3> dv01ndp0(3), dv01ndp1(3);
  unitVecAndGrad(p0, p1, v01n, dv01ndp0);
  v10n = -v01n;
  for(int i = 0; i < 3; i++) dv01ndp1[i] = -dv01ndp0[i];
  const std::vector<SVector3> &dv10ndp1 = dv01ndp0, &dv10ndp0 = dv01ndp1;

  // Compute unit vector, its gradients and opposite grandients for edge (1, 2)
  SVector3 v12n, v21n;
  std::vector<SVector3> dv12ndp1(3), dv12ndp2(3);
  unitVecAndGrad(p1, p2, v12n, dv12ndp1);
  v21n = -v12n;
  for(int i = 0; i < 3; i++) dv12ndp2[i] = -dv12ndp1[i];
  const std::vector<SVector3> &dv21ndp2 = dv12ndp1, &dv21ndp1 = dv12ndp2;

  // Compute unit vector, its gradients and opposite grandients for edge (2, 0)
  SVector3 v20n, v02n;
  std::vector<SVector3> dv20ndp2(3), dv20ndp0(3);
  unitVecAndGrad(p2, p0, v20n, dv20ndp2);
  v02n = -v20n;
  for(int i = 0; i < 3; i++) dv20ndp0[i] = -dv20ndp2[i];
  const std::vector<SVector3> &dv02ndp0 = dv20ndp2, &dv02ndp2 = dv20ndp0;

  // Compute NCJ at vertex 0 as 0.5*||u01^u02||/A_triEqui
  // and gradients w.r.t. x0, y0, z0, x1, y1, z1, x2, y2, z2
  std::vector<double> dNCJ0(9);
  NCJAndGrad2D(v01n, dv01ndp0, dv01ndp1, v02n, dv02ndp0, dv02ndp2, normal,
               NCJ[0], dNCJ0);
  //  dNCJ[0] = dNCJ0[0]; dNCJ[1] = dNCJ0[1]; dNCJ[2] = dNCJ0[2];
  //  dNCJ[3] = dNCJ0[3]; dNCJ[4] = dNCJ0[4]; dNCJ[5] = dNCJ0[5];
  //  dNCJ[6] = dNCJ0[6]; dNCJ[7] = dNCJ0[7]; dNCJ[8] = dNCJ0[8];
  scatterNCJGrad<0, 3, 0, 1, 2>(dNCJ0, dNCJ);

  // Compute NCJ at vertex 1 as 0.5*||u12^u10||/A_triEqui
  // and gradients w.r.t. x1, y1, z1, x2, y2, z2, x0, y0, z0
  std::vector<double> dNCJ1(9);
  NCJAndGrad2D(v12n, dv12ndp1, dv12ndp2, v10n, dv10ndp1, dv10ndp0, normal,
               NCJ[1], dNCJ1);
  //  dNCJ[9] = dNCJ1[6]; dNCJ[10] = dNCJ1[7]; dNCJ[11] = dNCJ1[8];
  //  dNCJ[10] = dNCJ1[0]; dNCJ[11] = dNCJ1[1]; dNCJ[12] = dNCJ1[2];
  //  dNCJ[13] = dNCJ1[3]; dNCJ[14] = dNCJ1[4]; dNCJ[15] = dNCJ1[5];
  scatterNCJGrad<1, 3, 1, 2, 0>(dNCJ1, dNCJ);

  // Compute NCJ at vertex 2 as 0.5*||u20^u21||/A_triEqui
  // Compute NCJ at vertex 2 and gradients w.r.t. x2, y2, z2, x0, y0, z0, x1,
  // y1, z1
  std::vector<double> dNCJ2(9);
  NCJAndGrad2D(v20n, dv20ndp2, dv20ndp0, v21n, dv21ndp2, dv21ndp1, normal,
               NCJ[2], dNCJ2);
  //  dNCJ[16] = dNCJ2[3]; dNCJ[17] = dNCJ2[4]; dNCJ[18] = dNCJ2[5];
  //  dNCJ[19] = dNCJ2[6]; dNCJ[20] = dNCJ2[7]; dNCJ[21] = dNCJ2[8];
  //  dNCJ[22] = dNCJ2[0]; dNCJ[23] = dNCJ2[1]; dNCJ[24] = dNCJ2[2];
  scatterNCJGrad<2, 3, 2, 0, 1>(dNCJ2, dNCJ);

  for(int i = 0; i < 3; i++) NCJ[i] *= fact;
  for(int i = 0; i < 27; i++) dNCJ[i] *= fact;

  //  for (int iV=0; iV<3; iV++) {
  //    std::cout << "DBGTT: Vertex " << iV << ":\n";
  //    std::cout << "DBGTT:     -> NCJ = " << NCJ[iV] << "\n";
  //    for (unsigned ig=0; ig<3; ig++) {
  //      int ind = iV*9+ig*3;
  //      std::cout << "DBGTT:     -> dNCJ/dp" << ig << " = (" << dNCJ[ind] <<
  //      ", " <<  dNCJ[ind+1] << ", " <<  dNCJ[ind+2] << ")\n";
  ////      int ind2 = ig*3;
  ////      std::vector<double> dNCJLoc = (iV == 0) ? dNCJ0 : (iV == 1) ? dNCJ1
  ///: dNCJ2; /      std::cout << "DBGTT:     -> dNCJ/dp" << ig << " (local) =
  ///(" << dNCJLoc[ind2] << ", " <<  dNCJLoc[ind2+1] << ", " <<  dNCJLoc[ind2+2]
  ///<< ")\n";
  //    }
  //  }
}

double qmQuadrangle::eta(MQuadrangle *el)
{
  double AR = 1; // pow(el->minEdge()/el->maxEdge(),.25);

  MVertex *_v[4] = {el->getVertex(0), el->getVertex(1), el->getVertex(2),
                    el->getVertex(3)};

  SVector3 v01(_v[1]->x() - _v[0]->x(), _v[1]->y() - _v[0]->y(),
               _v[1]->z() - _v[0]->z());
  SVector3 v12(_v[2]->x() - _v[1]->x(), _v[2]->y() - _v[1]->y(),
               _v[2]->z() - _v[1]->z());
  SVector3 v23(_v[3]->x() - _v[2]->x(), _v[3]->y() - _v[2]->y(),
               _v[3]->z() - _v[2]->z());
  SVector3 v30(_v[0]->x() - _v[3]->x(), _v[0]->y() - _v[3]->y(),
               _v[0]->z() - _v[3]->z());

  SVector3 a = crossprod(v01, v12);
  SVector3 b = crossprod(v12, v23);
  SVector3 c = crossprod(v23, v30);
  SVector3 d = crossprod(v30, v01);

  double sign = 1.0;
  if(dot(a, b) < 0 || dot(a, c) < 0 || dot(a, d) < 0) sign = -1;
  // FIXME ...
  //  if (a.z() > 0 || b.z() > 0 || c.z() > 0 || d.z() > 0) sign = -1;

  double a1 = 180 * angle3Vertices(_v[0], _v[1], _v[2]) / M_PI;
  double a2 = 180 * angle3Vertices(_v[1], _v[2], _v[3]) / M_PI;
  double a3 = 180 * angle3Vertices(_v[2], _v[3], _v[0]) / M_PI;
  double a4 = 180 * angle3Vertices(_v[3], _v[0], _v[1]) / M_PI;

  a1 = std::min(180., a1);
  a2 = std::min(180., a2);
  a3 = std::min(180., a3);
  a4 = std::min(180., a4);
  double angle = fabs(90. - a1);
  angle = std::max(fabs(90. - a2), angle);
  angle = std::max(fabs(90. - a3), angle);
  angle = std::max(fabs(90. - a4), angle);

  return sign * (1. - angle / 90) * AR;
}

double qmQuadrangle::angles(MQuadrangle *e)
{
  double a = 100;
  double worst_quality = std::numeric_limits<double>::max();
  double mat[3][3];
  double mat2[3][3];
  double den = atan(a * (M_PI / 4)) + atan(a * (2 * M_PI / 4 - (M_PI / 4)));

  // This matrix is used to "rotate" the triangle to get each vertex
  // as the "origin" of the mapping in turn
  // double rot[3][3];
  // rot[0][0]=-1; rot[0][1]=1; rot[0][2]=0;
  // rot[1][0]=-1; rot[1][1]=0; rot[1][2]=0;
  // rot[2][0]= 0; rot[2][1]=0; rot[2][2]=1;
  // double tmp[3][3];

  const double u[9] = {-1, -1, 1, 1, 0, 0, 1, -1, 0};
  const double v[9] = {-1, 1, 1, -1, -1, 1, 0, 0, 0};

  for(int i = 0; i < 9; i++) {
    e->getJacobian(u[i], v[i], 0, mat);
    e->getPrimaryJacobian(u[i], v[i], 0, mat2);
    // for (int j = 0; j < i; j++) {
    //  matmat(rot,mat,tmp);
    //  memcpy(mat, tmp, sizeof(mat));
    //}

    // get angle
    double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
    double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
    double v3[3] = {mat2[0][0], mat2[0][1], mat2[0][2]};
    double v4[3] = {mat2[1][0], mat2[1][1], mat2[1][2]};
    norme(v1);
    norme(v2);
    norme(v3);
    norme(v4);
    double v12[3], v34[3];
    prodve(v1, v2, v12);
    prodve(v3, v4, v34);
    norme(v12);
    norme(v34);

    // If the if the triangle is "flipped" it's no good
    // double const orientation = prosca(v12, v34);
    //    if (orientation < 0)
    //      return -std::numeric_limits<double>::max();

    double const c = prosca(v1, v2);
    double const x = std::abs(std::acos(c)) - M_PI / 2;
    // double angle = std::fabs(std::acos(c))*180/M_PI;
    double const quality = (std::atan(a * (x + M_PI / 4)) +
                            std::atan(a * (2 * M_PI / 4 - (x + M_PI / 4)))) /
                           den;
    worst_quality = std::min(worst_quality, quality);
  }
  return worst_quality;
}

void qmQuadrangle::NCJRange(const MQuadrangle *el, double &valMin,
                            double &valMax)
{
  const JacobianBasis *jac = el->getJacobianFuncSpace();
  fullMatrix<double> primNodesXYZ(4, 3);
  for(int i = 0; i < jac->getNumPrimMapNodes(); i++) {
    const MVertex *v = el->getVertex(i);
    primNodesXYZ(i, 0) = v->x();
    primNodesXYZ(i, 1) = v->y();
    primNodesXYZ(i, 2) = v->z();
  }
  fullMatrix<double> nM(1, 3);
  jac->getPrimNormal2D(primNodesXYZ, nM);
  SVector3 normal(nM(0, 0), nM(0, 1), nM(0, 2));

  std::vector<double> ncj(4);
  NCJ(el->getVertex(0)->point(), el->getVertex(1)->point(),
      el->getVertex(2)->point(), el->getVertex(3)->point(), normal, ncj);
  valMin = *std::min_element(ncj.begin(), ncj.end());
  valMax = *std::max_element(ncj.begin(), ncj.end());
}

void qmQuadrangle::NCJ(const SPoint3 &p0, const SPoint3 &p1, const SPoint3 &p2,
                       const SPoint3 &p3, const SVector3 &normal,
                       std::vector<double> &ncj)
{
  // Compute unit vectors for each edge
  SVector3 v01n(p0, p1), v12n(p1, p2), v23n(p2, p3), v30n(p3, p0);
  v01n.normalize();
  v12n.normalize();
  v23n.normalize();
  v30n.normalize();

  // Compute NCJ at vertex from unit vectors a and b as
  // 0.5*||a^b||/A_equilateral
  ncj[0] = dot(crossprod(v01n, -v30n), normal);
  ncj[1] = dot(crossprod(v12n, -v01n), normal);
  ncj[2] = dot(crossprod(v23n, -v12n), normal);
  ncj[3] = dot(crossprod(v30n, -v23n), normal);
}

void qmQuadrangle::NCJAndGradients(const SPoint3 &p0, const SPoint3 &p1,
                                   const SPoint3 &p2, const SPoint3 &p3,
                                   const SVector3 &normal,
                                   std::vector<double> &NCJ,
                                   std::vector<double> &dNCJ)
{
  // Compute unit vector, its gradients and opposite gradients for edge (0,1)
  SVector3 v01n, v10n;
  std::vector<SVector3> dv01ndp0(3), dv01ndp1(3);
  unitVecAndGrad(p0, p1, v01n, dv01ndp0);
  v10n = -v01n;
  for(int i = 0; i < 3; i++) dv01ndp1[i] = -dv01ndp0[i];
  const std::vector<SVector3> &dv10ndp1 = dv01ndp0, &dv10ndp0 = dv01ndp1;

  // Compute unit vector, its gradients and opposite gradients for edge (1,2)
  SVector3 v12n, v21n;
  std::vector<SVector3> dv12ndp1(3), dv12ndp2(3);
  unitVecAndGrad(p1, p2, v12n, dv12ndp1);
  v21n = -v12n;
  for(int i = 0; i < 3; i++) dv12ndp2[i] = -dv12ndp1[i];
  const std::vector<SVector3> &dv21ndp2 = dv12ndp1, &dv21ndp1 = dv12ndp2;

  // Compute unit vector, its gradients and opposite gradients for edge (2,3)
  SVector3 v23n, v32n;
  std::vector<SVector3> dv23ndp2(3), dv23ndp3(3);
  unitVecAndGrad(p2, p3, v23n, dv23ndp2);
  v32n = -v23n;
  for(int i = 0; i < 3; i++) dv23ndp3[i] = -dv23ndp2[i];
  const std::vector<SVector3> &dv32ndp3 = dv23ndp2, &dv32ndp2 = dv23ndp3;

  // Compute unit vector, its gradients and opposite gradients for edge (3,0)
  SVector3 v30n, v03n;
  std::vector<SVector3> dv30ndp3(3), dv30ndp0(3);
  unitVecAndGrad(p3, p0, v30n, dv30ndp3);
  v03n = -v30n;
  for(int i = 0; i < 3; i++) dv30ndp0[i] = -dv30ndp3[i];
  const std::vector<SVector3> &dv03ndp0 = dv30ndp3, &dv03ndp3 = dv30ndp0;

  // Compute NCJ at vertex 0 as 0.5*||u01^u03||/A_triRect
  // and gradients w.r.t. x0, y0, z0, x1, y1, z1, x3, y3, z3
  std::vector<double> dNCJ0(9);
  NCJAndGrad2D(v01n, dv01ndp0, dv01ndp1, v03n, dv03ndp0, dv03ndp3, normal,
               NCJ[0], dNCJ0);
  scatterNCJGrad<0, 4, 0, 1, 3>(dNCJ0, dNCJ);

  // Compute NCJ at vertex 1 as 0.5*||u12^u10||/A_triRect
  // and gradients w.r.t. x1, y1, z1, x2, y2, z2, x0, y0, z0
  std::vector<double> dNCJ1(9);
  NCJAndGrad2D(v12n, dv12ndp1, dv12ndp2, v10n, dv10ndp1, dv10ndp0, normal,
               NCJ[1], dNCJ1);
  scatterNCJGrad<1, 4, 1, 2, 0>(dNCJ1, dNCJ);

  // Compute NCJ at vertex 2 as 0.5*||u23^u21||/A_triRect
  // and gradients w.r.t. x2, y2, z2, x3, y3, z3, x1, y1, z1
  std::vector<double> dNCJ2(9);
  NCJAndGrad2D(v23n, dv23ndp2, dv23ndp3, v21n, dv21ndp2, dv21ndp1, normal,
               NCJ[2], dNCJ2);
  scatterNCJGrad<2, 4, 2, 3, 1>(dNCJ2, dNCJ);

  // Compute NCJ at vertex 3 as 0.5*||u30^u32||/A_triRect
  // and gradients w.r.t. x3, y3, z3, x0, y0, z0, x2, y2, z2
  std::vector<double> dNCJ3(9);
  NCJAndGrad2D(v30n, dv30ndp3, dv30ndp0, v32n, dv32ndp3, dv32ndp2, normal,
               NCJ[3], dNCJ3);
  scatterNCJGrad<3, 4, 3, 0, 2>(dNCJ3, dNCJ);

  //  for (int iV=0; iV<4; iV++) {
  //    std::cout << "DBGTT: Vertex " << iV << ":\n";
  //    std::cout << "DBGTT:     -> NCJ = " << NCJ[iV] << "\n";
  //    for (unsigned ig=0; ig<4; ig++) {
  //      int ind = iV*12+ig*3;
  //      std::cout << "DBGTT:     -> dNCJ/dp" << ig << " = (" << dNCJ[ind] <<
  //      ", " <<  dNCJ[ind+1] << ", " <<  dNCJ[ind+2] << ")\n";
  ////      int ind2 = ig*3;
  ////      std::vector<double> dNCJLoc = (iV == 0) ? dNCJ0 : (iV == 1) ? dNCJ1
  ///: dNCJ2; /      std::cout << "DBGTT:     -> dNCJ/dp" << ig << " (local) =
  ///(" << dNCJLoc[ind2] << ", " <<  dNCJLoc[ind2+1] << ", " <<  dNCJLoc[ind2+2]
  ///<< ")\n";
  //    }
  //  }
}

double qmTetrahedron::qm(MTetrahedron *t, const Measures &cr, double *volume)
{
  return qm(t->getVertex(0), t->getVertex(1), t->getVertex(2), t->getVertex(3),
            cr, volume);
}

double qmTetrahedron::qm(const MVertex *v1, const MVertex *v2,
                         const MVertex *v3, const MVertex *v4,
                         const Measures &cr, double *volume)
{
  return qm(v1->x(), v1->y(), v1->z(), v2->x(), v2->y(), v2->z(), v3->x(),
            v3->y(), v3->z(), v4->x(), v4->y(), v4->z(), cr, volume);
}

double qmTetrahedron::qm(const double &x1, const double &y1, const double &z1,
                         const double &x2, const double &y2, const double &z2,
                         const double &x3, const double &y3, const double &z3,
                         const double &x4, const double &y4, const double &z4,
                         const Measures &cr, double *volume)
{
  switch(cr) {
  case QMTET_ONE: return 1.0;
  case QMTET_ETA:
    return eta(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, volume);
  case QMTET_GAMMA: {
    double G = gamma(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, volume);
    *volume = fabs(*volume);
    return G;
  }
  case QMTET_COND:
    return cond(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4, volume);
  default: Msg::Error("Unknown quality measure"); return 0.;
  }
}

double qmTetrahedron::eta(const double &x1, const double &y1, const double &z1,
                          const double &x2, const double &y2, const double &z2,
                          const double &x3, const double &y3, const double &z3,
                          const double &x4, const double &y4, const double &z4,
                          double *volume)
{
  double p0[3] = {x1, y1, z1};
  double p1[3] = {x2, y2, z2};
  double p2[3] = {x3, y3, z3};
  double p3[3] = {x4, y4, z4};

  *volume = fabs(robustPredicates::orient3d(p0, p1, p2, p3)) / 6.0;

  double l =
    ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1));
  l += ((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1));
  l += ((x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1));
  l += ((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2));
  l += ((x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2) + (z4 - z2) * (z4 - z2));
  l += ((x3 - x4) * (x3 - x4) + (y3 - y4) * (y3 - y4) + (z3 - z4) * (z3 - z4));
  return 12. * pow(3 * fabs(*volume), 2. / 3.) / l;
}

double qmTetrahedron::gamma(const double &x1, const double &y1,
                            const double &z1, const double &x2,
                            const double &y2, const double &z2,
                            const double &x3, const double &y3,
                            const double &z3, const double &x4,
                            const double &y4, const double &z4, double *volume)
{
  // quality = rho / R = 3 * inradius / circumradius

  double p0[3] = {x1, y1, z1};
  double p1[3] = {x2, y2, z2};
  double p2[3] = {x3, y3, z3};
  double p3[3] = {x4, y4, z4};

  *volume = (robustPredicates::orient3d(p0, p1, p2, p3)) / 6.0;

  if(fabs(*volume) == 0) return 0;

  double la =
    (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) + (z2 - z1) * (z2 - z1);
  double lb =
    (x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) + (z3 - z1) * (z3 - z1);
  double lc =
    (x4 - x1) * (x4 - x1) + (y4 - y1) * (y4 - y1) + (z4 - z1) * (z4 - z1);
  double lA =
    (x4 - x3) * (x4 - x3) + (y4 - y3) * (y4 - y3) + (z4 - z3) * (z4 - z3);
  double lB =
    (x4 - x2) * (x4 - x2) + (y4 - y2) * (y4 - y2) + (z4 - z2) * (z4 - z2);
  double lC =
    (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2) + (z3 - z2) * (z3 - z2);

  double lalA = std::sqrt(la * lA);
  double lblB = std::sqrt(lb * lB);
  double lclC = std::sqrt(lc * lC);

  double insideSqrt = (lalA + lblB + lclC) * (lalA + lblB - lclC) *
                      (lalA - lblB + lclC) * (-lalA + lblB + lclC);

  // This happens when the 4 points are (nearly) co-planar
  // => R is actually undetermined but the quality is (close to) zero
  if(insideSqrt <= 0) return 0;

  double R = std::sqrt(insideSqrt) / 24 / *volume;

  double s1 = fabs(triangle_area(p0, p1, p2));
  double s2 = fabs(triangle_area(p0, p2, p3));
  double s3 = fabs(triangle_area(p0, p1, p3));
  double s4 = fabs(triangle_area(p1, p2, p3));
  double rho = 3 * 3 * *volume / (s1 + s2 + s3 + s4);

  return rho / R;
}

double qmTetrahedron::cond(const double &x1, const double &y1, const double &z1,
                           const double &x2, const double &y2, const double &z2,
                           const double &x3, const double &y3, const double &z3,
                           const double &x4, const double &y4, const double &z4,
                           double *volume)
{
  /// condition number is defined as (see Knupp & Freitag in IJNME)
  double INVW[3][3] = {{1, -1. / sqrt(3.), -1. / sqrt(6.)},
                       {0, 2 / sqrt(3.), -1. / sqrt(6.)},
                       {0, 0, sqrt(1.5)}};
  double A[3][3] = {{x2 - x1, y2 - y1, z2 - z1},
                    {x3 - x1, y3 - y1, z3 - z1},
                    {x4 - x1, y4 - y1, z4 - z1}};
  double S[3][3], INVS[3][3];
  matmat(A, INVW, S);
  *volume = inv3x3(S, INVS) * 0.70710678118654762; // 2/sqrt(2);
  double normS = norm2(S);
  double normINVS = norm2(INVS);
  return normS * normINVS;
}

// TODO: Replace this
static double prismNCJ(const MVertex *a, const MVertex *b, const MVertex *c,
                       const MVertex *d)
{
  static const double fact = 2. / sqrt(3.);

  const SVector3 vec1 =
    SVector3(b->x() - a->x(), b->y() - a->y(), b->z() - a->z());
  const SVector3 vec2 =
    SVector3(c->x() - a->x(), c->y() - a->y(), c->z() - a->z());
  const SVector3 vec3 =
    SVector3(d->x() - a->x(), d->y() - a->y(), d->z() - a->z());

  const double l1 = vec1.norm();
  const double l2 = vec2.norm();
  const double l3 = vec3.norm();

  const double val = dot(vec1, crossprod(vec2, vec3));
  return fact * fabs(val) / (l1 * l2 * l3);
}

double qmPrism::minNCJ(const MPrism *el)
{
  const MVertex *a = el->getVertex(0), *b = el->getVertex(1),
                *c = el->getVertex(2);
  const MVertex *d = el->getVertex(3), *e = el->getVertex(4),
                *f = el->getVertex(5);
  const double j[6] = {prismNCJ(a, b, c, d), prismNCJ(b, a, c, e),
                       prismNCJ(c, a, b, f), prismNCJ(d, a, e, f),
                       prismNCJ(e, b, d, f), prismNCJ(f, c, d, e)};
  const double result = *std::min_element(j, j + 6);
  return result;
}

// void qmPrism::NCJ(const double &x0, const double &y0, const double &z0,
//                  const double &x1, const double &y1, const double &z1,
//                  const double &x2, const double &y2, const double &z2,
//                  const double &x3, const double &y3, const double &z3,
//                  const double &x4, const double &y4, const double &z4,
//                  fullVector<double> &ncj)
//{
//  // Compute unit vectors for each edge
//  double x01n, y01n, z01n, x12n, y12n, z12n, x23n, y23n, z23n, x30n, y30n,
//  z30n; unitVec(x0, y0, z0, x1, y1, z1, x01n, y01n, z01n); unitVec(x1, y1, z1,
//  x2, y2, z2, x12n, y12n, z12n); unitVec(x2, y2, z2, x3, y3, z3, x23n, y23n,
//  z23n); unitVec(x3, y3, z3, x0, y0, z0, x30n, y30n, z30n);
//
//  // Compute NCJ at vertex from unit vectors a and b as
//  0.5*||a^b||/A_equilateral
//  // Factor = 2./sqrt(3.) = 0.5/A_equilateral
//  static const double fact = 1.1547005383792517;
//  ncj(0) = triArea(fact, x01n, y01n, z01n, -x20n, -y20n, -z20n);
//  ncj(1) = triArea(fact, x12n, y12n, z12n, -x01n, -y01n, -z01n);
//  ncj(2) = triArea(fact, x20n, y20n, z20n, -x12n, -y12n, -z12n);
//}

// TODO: Remove this (useless as quality measure)
double qmHexahedron::angles(MHexahedron *el)
{
  double angleMax = 0.0;
  double angleMin = M_PI;
  double zeta = 0.0;
  for(int i = 0; i < el->getNumFaces(); i++) {
    std::vector<MVertex *> vv;
    vv.push_back(el->getFace(i).getVertex(0));
    vv.push_back(el->getFace(i).getVertex(1));
    vv.push_back(el->getFace(i).getVertex(2));
    vv.push_back(el->getFace(i).getVertex(3));
    // MVertex *v0 = new MVertex(0, 0, 0); vv.push_back(v0);
    // MVertex *v1 = new MVertex(1., 0, 0);vv.push_back(v1);
    // MVertex *v2 = new MVertex(2., 1., 0);vv.push_back(v2);
    // MVertex *v3 = new MVertex(1, 1., 0);vv.push_back(v3);
    for(int j = 0; j < 4; j++) {
      SVector3 a(vv[(j + 2) % 4]->x() - vv[(j + 1) % 4]->x(),
                 vv[(j + 2) % 4]->y() - vv[(j + 1) % 4]->y(),
                 vv[(j + 2) % 4]->z() - vv[(j + 1) % 4]->z());
      SVector3 b(vv[(j + 1) % 4]->x() - vv[(j) % 4]->x(),
                 vv[(j + 1) % 4]->y() - vv[(j) % 4]->y(),
                 vv[(j + 1) % 4]->z() - vv[(j) % 4]->z());
      double angle = acos(dot(a, b) / (norm(a) * norm(b))); //*180/M_PI;
      angleMax = std::max(angleMax, angle);
      angleMin = std::min(angleMin, angle);
    }
    // printf("angle max =%g min =%g \n", angleMax*180/M_PI, angleMin*180/M_PI);
  }
  zeta = 1. - std::max((angleMax - 0.5 * M_PI) / (0.5 * M_PI),
                       (0.5 * M_PI - angleMin) / (0.5 * M_PI));
  return zeta;
}
