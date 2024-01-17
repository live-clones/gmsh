// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by K. Hillewaert

#include <cmath>
#include <vector>

#include "fullMatrix.h"

template <class FLOAT>
bool computeAffineTransformation(const FLOAT *rc, const FLOAT *ra,
                                 const FLOAT *tr, std::vector<double> &tfo)
{
  // rotation matrix
  double rotData[9] = {1., 0., 0., 0., 1., 0., 0., 0., 1.};
  fullMatrix<double> rot(rotData, 3, 3);

  // rotation about x-axis
  if(ra[0] != 0.) {
    fullMatrix<double> tmp(rot);
    const double ca = std::cos(ra[0]), sa = std::sin(ra[0]);
    double rotX[9] = {1., 0., 0., 0., ca, -sa, 0., sa, ca};
    rot.gemm(fullMatrix<double>(rotX, 3, 3), tmp, 1., 0.);
  }

  // rotation about y-axis
  if(ra[1] != 0.) {
    fullMatrix<double> tmp(rot);
    const double ca = std::cos(ra[1]), sa = std::sin(ra[1]);
    double rotY[9] = {ca, 0., sa, 0., 1., 0., -sa, 0., ca};
    rot.gemm(fullMatrix<double>(rotY, 3, 3), tmp, 1., 0.);
  }

  // rotation about z-axis
  if(ra[2] != 0.) {
    fullMatrix<double> tmp(rot);
    const double ca = std::cos(ra[2]), sa = std::sin(ra[2]);
    double rotZ[9] = {ca, -sa, 0., sa, ca, 0., 0, 0, 1.};
    rot.gemm(fullMatrix<double>(rotZ, 3, 3), tmp, 1., 0.);
  }

  // compute displacement from rotation center (I-R)*x and translation t
  double rotCenterData[3] = {rc[0], rc[1], rc[2]};
  fullVector<double> rotCenter(rotCenterData, 3);
  fullVector<double> dispRot(3);
  rot.mult(rotCenter, dispRot);
  double disp[3];
  for(int i = 0; i < 3; i++) disp[i] = tr[i] + rc[i] - dispRot(i);

  // copy to tfo
  tfo.clear();
  tfo.reserve(16.);
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) tfo.push_back(rot(i, j));
    tfo.push_back(disp[i]);
  }
  for(int i = 0; i < 3; i++) tfo.push_back(0.);
  tfo.push_back(1.);

  return true;
}

// explicit instantiations for float and double
template bool computeAffineTransformation(const float *rc, const float *ra,
                                          const float *tr,
                                          std::vector<double> &tfo);
template bool computeAffineTransformation(const double *rc, const double *ra,
                                          const double *tr,
                                          std::vector<double> &tfo);

template <class FLOAT>
bool getAffineTransformationParameters(const std::vector<double> &tfo,
                                       FLOAT *rc, FLOAT *ra, FLOAT *tr)
{
  // rotation angles
  ra[0] = std::atan2(-tfo[2 * 4 + 1], tfo[2 * 4 + 2]);
  ra[1] = std::asin(tfo[2 * 4 + 0]);
  ra[2] = std::atan2(-tfo[1 * 4 + 0], tfo[0 * 4 + 0]);

  // translation
  for(int i = 0; i < 3; i++) rc[i] = 0.;
  for(int i = 0; i < 3; i++) tr[i] = tfo[4 * i + 3];

  return true;
}

// explicit instantiations for float and double
template bool getAffineTransformationParameters(const std::vector<double> &tfo,
                                                float *rc, float *ra,
                                                float *tr);
template bool getAffineTransformationParameters(const std::vector<double> &tfo,
                                                double *rc, double *ra,
                                                double *tr);

bool invertAffineTransformation(const std::vector<double> &tfo,
                                std::vector<double> &newTfo)
{
  fullMatrix<double> inv(4, 4);
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) inv(i, j) = tfo[i * 4 + j];
  inv.invertInPlace();
  newTfo.clear();
  for(int i = 0; i < 4; i++)
    for(int j = 0; j < 4; j++) newTfo.push_back(inv(i, j));
  return true;
}

bool setUnitAffineTransformation(std::vector<double> &tfo)
{
  tfo.resize(16, 0);
  for(int i = 0; i < 16; i += 5) tfo[i] = 1;
  return true;
}
