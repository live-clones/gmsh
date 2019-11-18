// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_READ_H
#define CGNS_READ_H

#include <vector>
#include <map>
#include "fullMatrix.h"
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)


class MVertex;
class MElement;
class CGNSZone;


int readScale(int fileIndex, int baseIndex, double &scale);

int readEltNodeTransfo(int fileIndex, int baseIndex,
                       Family2EltNodeTransfo &allEltNodeTransfo);

int createZones(int fileIndex, int baseIndex, int meshDim,
                const Family2EltNodeTransfo &allEltNodeTransfo,
                std::vector<CGNSZone *> &allZones,
                std::map<std::string, int> &name2Zone);

void setPeriodicityInEntities(const std::vector<CGNSZone *> &allZones);

#endif // HAVE_LIBCGNS

#endif // CGNS_READ_H
