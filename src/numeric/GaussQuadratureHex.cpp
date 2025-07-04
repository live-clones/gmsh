// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

const double a1 = 0.40824826;
const double ma1 = -0.40824826;
const double a2 = 0.81649658;
const double ma2 = -0.81649658;
const double b1 = 0.70710678;
const double mb1 = -0.70710678;
const double c1 = 0.57735027;
const double mc1 = -0.57735027;
const double w1 = 1.3333333333;
const double xh6[6] = {a1, a1, ma1, ma1, ma2, a2};
const double yh6[6] = {b1, mb1, b1, mb1, 0., 0.};
const double zh6[6] = {mc1, mc1, c1, c1, mc1, c1};
const double ph6[6] = {w1, w1, w1, w1, w1, w1};

IntPt GQH1[1] = {{{0.0, 0.0, 0.0}, 8.0}};

IntPt GQH6[6] = {
  {{xh6[0], yh6[0], zh6[0]}, ph6[0]}, {{xh6[1], yh6[1], zh6[1]}, ph6[1]},
  {{xh6[2], yh6[2], zh6[2]}, ph6[2]}, {{xh6[3], yh6[3], zh6[3]}, ph6[3]},
  {{xh6[4], yh6[4], zh6[4]}, ph6[4]}, {{xh6[5], yh6[5], zh6[5]}, ph6[5]}};

const double xh8[8] = {
  0.577350269189626, -0.577350269189626, 0.577350269189626, -0.577350269189626,
  0.577350269189626, -0.577350269189626, 0.577350269189626, -0.577350269189626};
const double yh8[8] = {
  0.577350269189626, 0.577350269189626, -0.577350269189626, -0.577350269189626,
  0.577350269189626, 0.577350269189626, -0.577350269189626, -0.577350269189626};
const double zh8[8] = {-0.577350269189626, -0.577350269189626,
                       -0.577350269189626, -0.577350269189626,
                       0.577350269189626,  0.577350269189626,
                       0.577350269189626,  0.577350269189626};
const double ph8[8] = {1., 1., 1., 1., 1., 1., 1., 1.};
IntPt GQH8[8] = {
  {{xh8[0], yh8[0], zh8[0]}, ph8[0]}, {{xh8[1], yh8[1], zh8[1]}, ph8[1]},
  {{xh8[2], yh8[2], zh8[2]}, ph8[2]}, {{xh8[3], yh8[3], zh8[3]}, ph8[3]},
  {{xh8[4], yh8[4], zh8[4]}, ph8[4]}, {{xh8[5], yh8[5], zh8[5]}, ph8[5]},
  {{xh8[6], yh8[6], zh8[6]}, ph8[6]}, {{xh8[7], yh8[7], zh8[7]}, ph8[7]}};

IntPt GQH34[34] = {
  {{0.9317380000, 0., 0.}, 0.28465447168},
  {{-0.9317380000, 0., 0.}, 0.28465447168},
  {{0., 0.9317380000, 0.}, 0.28465447168},
  {{0., -0.9317380000, 0.}, 0.28465447168},
  {{0., 0., 0.9317380000}, 0.28465447168},
  {{0., 0., -0.9317380000}, 0.28465447168},
  {{0.9167441779, 0.9167441779, 0.}, 0.09983142160},
  {{-0.9167441779, 0.9167441779, 0.}, 0.09983142160},
  {{0.9167441779, -0.9167441779, 0.}, 0.09983142160},
  {{-0.9167441779, -0.9167441779, 0.}, 0.09983142160},
  {{0., 0.9167441779, 0.9167441779}, 0.09983142160},
  {{0., -0.9167441779, 0.9167441779}, 0.09983142160},
  {{0., 0.9167441779, -0.9167441779}, 0.09983142160},
  {{0., -0.9167441779, -0.9167441779}, 0.09983142160},
  {{0.9167441779, 0., 0.9167441779}, 0.09983142160},
  {{-0.9167441779, 0., 0.9167441779}, 0.09983142160},
  {{0.9167441779, 0., -0.9167441779}, 0.09983142160},
  {{-0.9167441779, 0., -0.9167441779}, 0.09983142160},
  {{0.4086003800, 0.4086003800, 0.4086003800}, 0.42294183928},
  {{0.4086003800, 0.4086003800, -0.4086003800}, 0.42294183928},
  {{0.4086003800, -0.4086003800, 0.4086003800}, 0.42294183928},
  {{0.4086003800, -0.4086003800, -0.4086003800}, 0.42294183928},
  {{-0.4086003800, 0.4086003800, 0.4086003800}, 0.42294183928},
  {{-0.4086003800, 0.4086003800, -0.4086003800}, 0.42294183928},
  {{-0.4086003800, -0.4086003800, 0.4086003800}, 0.42294183928},
  {{-0.4086003800, -0.4086003800, -0.4086003800}, 0.42294183928},
  {{0.7398529500, 0.7398529500, 0.7398529500}, 0.21382017456},
  {{0.7398529500, 0.7398529500, -0.7398529500}, 0.21382017456},
  {{0.7398529500, -0.7398529500, 0.7398529500}, 0.21382017456},
  {{0.7398529500, -0.7398529500, -0.7398529500}, 0.21382017456},
  {{-0.7398529500, 0.7398529500, 0.7398529500}, 0.21382017456},
  {{-0.7398529500, 0.7398529500, -0.7398529500}, 0.21382017456},
  {{-0.7398529500, -0.7398529500, 0.7398529500}, 0.21382017456},
  {{-0.7398529500, -0.7398529500, -0.7398529500}, 0.21382017456}};

static IntPt *GQH[2] = {GQH1, GQH6};
static int GQHnPt[2] = {1, 6};
static std::vector<IntPt *> GQHGL(40, nullptr);

IntPt *getGQHPts(int order, bool forceTensorRule)
{
  if(!forceTensorRule && order <= 1) return GQH[order];

  if(static_cast<int>(GQHGL.size()) < order + 1)
    GQHGL.resize(order + 1, nullptr);
  if(!GQHGL[order]) {
    int n = (order + 1) / (float)2 + 0.5;
    double *pt, *wt;
    gmshGaussLegendre1D(n, &pt, &wt);
    IntPt *intpt = new IntPt[n * n * n];
    int l = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        for(int k = 0; k < n; k++) {
          intpt[l].pt[0] = pt[i];
          intpt[l].pt[1] = pt[j];
          intpt[l].pt[2] = pt[k];
          intpt[l++].weight = wt[i] * wt[j] * wt[k];
        }
      }
    }
    GQHGL[order] = intpt;
  }
  return GQHGL[order];
}

int getNGQHPts(int order, bool forceTensorRule)
{
  if(!forceTensorRule && order <= 1) return GQHnPt[order];
  int n = (order + 1) / (float)2 + 0.5;
  return n * n * n;
}
