// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CROSS_FIELDS_H
#define CROSS_FIELDS_H

#include <string>
#include <map>
#include <vector>
class GModel;

int computeCrossField    (GModel *, std::vector<int> &tags);
int computeCrossFieldAndH(GModel *gm,
			  std::map<int, std::vector<double> > &dataH,
			  std::map<int, std::vector<double> > &dataDir,
			  std::map<int, std::vector<double> > &dataDirOrtho);

#endif
