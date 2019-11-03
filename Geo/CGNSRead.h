// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_READ_H
#define CGNS_READ_H

#include "CGNSCommon.h"
#include <vector>
#include <map>

#if defined(HAVE_LIBCGNS)


class MVertex;
class MElement;


struct ZoneInfo
{
  int index;
  char name[CGNS_MAX_STR_LEN];
  ZoneType_t type;
  cgsize_t size[9];
  cgsize_t startNode, nbNode;
  std::vector<bool> interfaceNode;
};


double readScale();

int readAllZoneInfo(int cgIndexFile, int cgIndexBase, int meshDim,
                    std::vector<ZoneInfo> &allZoneInfo);

int readZone(int cgIndexFile, int cgIndexBase, const ZoneInfo &zone, int dim,
             double scale, std::vector<MVertex *> &allVert,
             std::map<int, std::vector<MElement *> > *allElt,
             std::vector<std::string> &allBCName, std::map<int, int> &bc2Family,
             std::vector<std::string> &allBCFamilyName);


#endif // HAVE_LIBCGNS

#endif // CGNS_READ_H
