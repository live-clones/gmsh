// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CROSS_FIELDS_H
#define CROSS_FIELDS_H

#include <string>
class GModel;

int computeQuadDecomposition(GModel *, const std::string &THETA, const std::string &H);
int computeCrossFieldAndH   (GModel *, const std::string &THETA, const std::string &H);
int computeCrossField       (GModel *);

#endif
