// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GmshMessage.h"
#include "GaussIntegration.h"
#include "GaussLegendre1D.h"

IntPt GQQ1[1] = {{{0.0, 0.0, 0.0}, 4.0}};

const double xq3[3] = {0.816496580928, -0.408248290464, -0.408248290464};
const double yq3[3] = {0.0, 0.840896415255, -0.840896415255};
const double pq3[3] = {1.3333333333333, 1.3333333333333, 1.3333333333333};
IntPt GQQ3[3] = {{{xq3[0], yq3[0], 0}, pq3[0]},
                 {{xq3[1], yq3[1], 0}, pq3[1]},
                 {{xq3[2], yq3[2], 0}, pq3[2]}};

const double xq4[4] = {0.577350269189626, -0.577350269189626, 0.577350269189626,
                       -0.577350269189626};
const double yq4[4] = {0.577350269189626, 0.577350269189626, -0.577350269189626,
                       -0.577350269189626};
const double pq4[4] = {1., 1., 1., 1.};
IntPt GQQ4[4] = {
  {{xq4[0], yq4[0], 0}, pq4[0]},
  {{xq4[1], yq4[1], 0}, pq4[1]},
  {{xq4[2], yq4[2], 0}, pq4[2]},
  {{xq4[3], yq4[3], 0}, pq4[3]},
};

const double xq7[7] = {0.,
                       0.,
                       0.,
                       0.7745966692414834,
                       0.7745966692414834,
                       -0.7745966692414834,
                       -0.7745966692414834};
const double yq7[7] = {0.,
                       0.9660917830792959,
                       -0.9660917830792959,
                       0.7745966692414834,
                       -0.7745966692414834,
                       0.7745966692414834,
                       -0.7745966692414834};
const double pq7[7] = {1.1428571428571428,  0.31746031746031744,
                       0.31746031746031744, 0.5555555555555556,
                       0.5555555555555556,  0.5555555555555556,
                       0.5555555555555556};
IntPt GQQ7[7] = {{{xq7[0], yq7[0], 0}, pq7[0]}, {{xq7[1], yq7[1], 0}, pq7[1]},
                 {{xq7[2], yq7[2], 0}, pq7[2]}, {{xq7[3], yq7[3], 0}, pq7[3]},
                 {{xq7[4], yq7[4], 0}, pq7[4]}, {{xq7[5], yq7[5], 0}, pq7[5]},
                 {{xq7[6], yq7[6], 0}, pq7[6]}};

const double a9 = 0.774596669241483;
const double z = 0.0;
const double xq9[9] = {-a9, z, a9, -a9, z, a9, -a9, z, a9};
const double yq9[9] = {-a9, -a9, -a9, z, z, z, a9, a9, a9};
const double pb2 = 0.888888888888889 * 0.888888888888889;
const double pc2 = 0.555555555555556 * 0.555555555555556;
const double pbc = 0.555555555555556 * 0.888888888888889;
const double pq9[9] = {pc2, pbc, pc2, pbc, pb2, pbc, pc2, pbc, pc2};

IntPt GQQ9[9] = {{{xq9[0], yq9[0], 0}, pq9[0]}, {{xq9[1], yq9[1], 0}, pq9[1]},
                 {{xq9[2], yq9[2], 0}, pq9[2]}, {{xq9[3], yq9[3], 0}, pq9[3]},
                 {{xq9[4], yq9[4], 0}, pq9[4]}, {{xq9[5], yq9[5], 0}, pq9[5]},
                 {{xq9[6], yq9[6], 0}, pq9[6]}, {{xq9[7], yq9[7], 0}, pq9[7]},
                 {{xq9[8], yq9[8], 0}, pq9[8]}};

const double a16 = 0.861136311594053;
const double b16 = 0.339981043584856;
const double xq16[16] = {-a16, -b16, b16, a16, -a16, -b16, b16, a16,
                         -a16, -b16, b16, a16, -a16, -b16, b16, a16};
const double yq16[16] = {-a16, -a16, -a16, -a16, -b16, -b16, -b16, -b16,
                         b16,  b16,  b16,  b16,  a16,  a16,  a16,  a16};
const double pe2 = 0.347854845137454 * 0.347854845137454;
const double pf2 = 0.652145154862546 * 0.652145154862546;
const double pef = 0.347854845137454 * 0.652145154862546;

double pq16[16] = {pe2, pef, pef, pe2, pef, pf2, pf2, pef,
                   pef, pf2, pf2, pef, pe2, pef, pef, pe2};

IntPt GQQ16[16] = {
  {{xq16[0], yq16[0], 0}, pq16[0]},    {{xq16[1], yq16[1], 0}, pq16[1]},
  {{xq16[2], yq16[2], 0}, pq16[2]},    {{xq16[3], yq16[3], 0}, pq16[3]},
  {{xq16[4], yq16[4], 0}, pq16[4]},    {{xq16[5], yq16[5], 0}, pq16[5]},
  {{xq16[6], yq16[6], 0}, pq16[6]},    {{xq16[7], yq16[7], 0}, pq16[7]},
  {{xq16[8], yq16[8], 0}, pq16[8]},    {{xq16[9], yq16[9], 0}, pq16[9]},
  {{xq16[10], yq16[10], 0}, pq16[10]}, {{xq16[11], yq16[11], 0}, pq16[11]},
  {{xq16[12], yq16[12], 0}, pq16[12]}, {{xq16[13], yq16[13], 0}, pq16[13]},
  {{xq16[14], yq16[14], 0}, pq16[14]}, {{xq16[15], yq16[15], 0}, pq16[15]}};

// Not clear which rule to use for order 2 - with this choice Gauss2 has 7
// points, but only 4 for the tensor rule...
static IntPt *GQQ[3] = {GQQ1, GQQ3, GQQ7};
static int GQQnPt[3] = {1, 3, 7};
static std::vector<IntPt *> GQQGL(40, nullptr);

IntPt *getGQQPts(int order, bool forceTensorRule)
{
  if(!forceTensorRule && order <= 2) return GQQ[order];

  if(static_cast<int>(GQQGL.size()) < order + 1)
    GQQGL.resize(order + 1, nullptr);
  if(!GQQGL[order]) {
    int n = (order + 1) / (float)2 + 0.5;
    double *pt, *wt;
    gmshGaussLegendre1D(n, &pt, &wt);
    IntPt *intpt = new IntPt[n * n];
    int k = 0;
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < n; j++) {
        intpt[k].pt[0] = pt[i];
        intpt[k].pt[1] = pt[j];
        intpt[k].pt[2] = 0.0;
        intpt[k++].weight = wt[i] * wt[j];
      }
    }
    GQQGL[order] = intpt;
  }
  return GQQGL[order];
}

int getNGQQPts(int order, bool forceTensorRule)
{
  if(!forceTensorRule && order <= 2) return GQQnPt[order];

  int n = (order + 1) / (float)2 + 0.5;
  return n * n;
}
