// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributed by J. Lambrechts

#ifndef DECASTELJAU_H
#define DECASTELJAU_H

#include <vector>
class SPoint3;
void decasteljau(double tol, const SPoint3 &p0, const SPoint3 &p1,
                 const SPoint3 &p2, std::vector<SPoint3> &pts,
                 std::vector<double> &ts);
void decasteljau(double tol, const SPoint3 &p0, const SPoint3 &p1,
                 const SPoint3 &p2, const SPoint3 &p3,
                 std::vector<SPoint3> &pts, std::vector<double> &ts);
void decasteljau(double tol, const std::vector<SPoint3> &controlPoints,
                 std::vector<SPoint3> &pts, std::vector<double> &ts);

#endif
