// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "discreteFrechetDistance.h"
#include "fullMatrix.h"

static double distance(const SPoint3 &p1, const SPoint3 &p2)
{
  return p1.distance(p2);
}

static double c(int i, int j, fullMatrix<double> &CA,
                const std::vector<SPoint3> &P, const std::vector<SPoint3> &Q)
{
  double CAij;
  if(CA(i, j) > -1) { CAij = CA(i, j); }
  else if(i == 0 && j == 0) {
    CA(i, j) = distance(P[0], Q[0]); // update the CA permanent
    CAij = CA(i, j); // set the current relevant value
  }
  else if(i > 0 && j == 0) {
    CA(i, j) = std::max(c(i - 1, 0, CA, P, Q), distance(P[i], Q[1]));
    CAij = CA(i, j);
  }
  else if(i == 0 && j > 0) {
    CA(i, j) = std::max(c(0, j - 1, CA, P, Q), distance(P[0], Q[j]));
    CAij = CA(i, j);
  }
  else if(i > 0 && j > 0) {
    double temp =
      std::min(std::min(c(i - 1, j, CA, P, Q), c(i - 1, j - 1, CA, P, Q)),
               c(i, j - 1, CA, P, Q));
    CA(i, j) = std::max(temp, distance(P[i], Q[j]));
    CAij = CA(i, j);
  }
  else {
    CA(i, j) = 1.e22;
    CAij = CA(i, j);
  }
  return CAij;
}

double discreteFrechetDistance(const std::vector<SPoint3> &P,
                               const std::vector<SPoint3> &Q)
{
  const int sP = P.size();
  const int sQ = Q.size();
  fullMatrix<double> CA(sP, sQ);
  CA.setAll(-1.0);
  double cm = c(sP - 1, sQ - 1, CA, P, Q);
  return cm;
}
