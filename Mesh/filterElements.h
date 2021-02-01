// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FILTER_OVERLAPPING_ELEMENTS
#define FILTER_OVERLAPPING_ELEMENTS

#include <map>
#include <vector>

class MElement;
class MTriangle;
class MQuadrangle;
class MLine;

void filterOverlappingElements(
  std::vector<MLine *> &_lines, std::vector<MTriangle *> &blTris,
  std::vector<MQuadrangle *> &blQuads,
  std::map<MElement *, std::vector<MElement *> > &_elemColumns,
  std::map<MElement *, MElement *> &_toFirst);
void filterColumns(
  std::vector<MElement *> &elem,
  std::map<MElement *, std::vector<MElement *> > &_elemColumns);

#endif
