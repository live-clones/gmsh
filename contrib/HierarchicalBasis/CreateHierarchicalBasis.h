// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CREATE_HIERARCHICAL_BASIS_H
#define CREATE_HIERARCHICAL_BASIS_H

#include <string>
class HierarchicalBasis;

HierarchicalBasis* CreateHierarchicalBasis(const std::string &fsName, int familyType, int fsOrder);

#endif // CREATE_HIERARCHICAL_BASIS_H
