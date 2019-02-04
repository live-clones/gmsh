// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by K. Hillewaert

#include <vector>

#include "fullMatrix.h"

template <class FLOAT>
bool computeAffineTransformationTemplate(const FLOAT *rc, const FLOAT *ra,
                                         const FLOAT *tr,
                                         std::vector<double> &tfo)
{
  tfo.clear();
  tfo.reserve(16);

  fullMatrix<double> compoundRotation(3, 3);
  for(int i = 0; i < 3; i++) compoundRotation(i, i) = 1;

  for(int i = 0; i < 3; i++) {
    if(ra[i] != 0) {
      fullMatrix<double> tmp(compoundRotation);

      fullMatrix<double> rotation(3, 3);
      rotation(i, i) = 1;

      int ii = (i + 1) % 3;
      int jj = (i + 2) % 3;

      double ca = cos(ra[i]);
      double sa = sin(ra[i]);

      // rotation with alpha

      rotation(ii, ii) = ca;
      rotation(ii, jj) = sa;
      rotation(jj, ii) = -sa;
      rotation(jj, jj) = ca;

      compoundRotation.gemm(rotation, tmp, 1, 0);
    }
  }

  // compute displacement from rotation center

  fullVector<double> disp(3);

  fullVector<double> center(3);
  for(int i = 0; i < 3; i++) center(i) = rc[i];
  compoundRotation.mult(center, disp);

  // add specified translation

  for(int i = 0; i < 3; i++) disp(i) = -tr[i];

  // copy to tfo

  tfo.clear();

  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) tfo.push_back(compoundRotation(i, j));
    tfo.push_back(disp(i));
  }
  for(int i = 0; i < 3; i++) tfo.push_back(0);
  tfo.push_back(1);

  return true;
}

bool computeAffineTransformation(const float *rc, const float *ra,
                                 const float *tr, std::vector<double> &tfo)
{
  return computeAffineTransformationTemplate(rc, ra, tr, tfo);
}

bool computeAffineTransformation(const double *rc, const double *ra,
                                 const double *tr, std::vector<double> &tfo)
{
  return computeAffineTransformationTemplate(rc, ra, tr, tfo);
}

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
