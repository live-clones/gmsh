// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FILTER_OVERLAPPING_ELEMENTS
#define FILTER_OVERLAPPING_ELEMENTS

#include <map>
#include <vector>
#include "boundaryLayersData.h"

class MElement;
class MTriangle;
class MQuadrangle;
class MLine;

void filterOverlappingElements(std::vector<MLine *> &_lines,
                               std::vector<MTriangle *> &blTris,
                               std::vector<MQuadrangle *> &blQuads,
                               blElemColumns &_elemColumns,
                               blElemToFirst &_toFirst);
void filterColumns(std::vector<MElement *> &elem, blElemColumns &_elemColumns);

#endif
