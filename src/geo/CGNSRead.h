// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_READ_H
#define CGNS_READ_H

#include <vector>
#include <map>
#include "GmshConfig.h"
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)

class GModel;
class MVertex;
class MElement;
class CGNSZone;

// types for high-order node tranformation (CPEX0045)
typedef std::vector<std::vector<int> > ZoneEltNodeTransfo;
typedef std::map<std::string, ZoneEltNodeTransfo> Family2EltNodeTransfo;

std::size_t nameIndex(const std::string &name,
                      std::vector<std::string> &allNames);

int readScale(int fileIndex, int baseIndex, double &scale);

int readEltNodeTransfo(int fileIndex, int baseIndex,
                       Family2EltNodeTransfo &allEltNodeTransfo);

int createZones(int fileIndex, int baseIndex, int meshDim,
                const Family2EltNodeTransfo &allEltNodeTransfo,
                std::vector<CGNSZone *> &allZones,
                std::map<std::string, int> &name2Zone, bool &postpro);

void setPeriodicityInEntities(const std::vector<CGNSZone *> &allZones);

int readPhysicals(int fileIndex, int baseIndex,
                  std::vector<std::string> &allPhysName,
                  std::multimap<std::string, int> &geomName2Phys);

void setGeomAndPhysicalEntities(GModel *model, int meshDim,
                                std::vector<std::string> &allGeomName,
                                std::vector<std::string> &allPhysName,
                                std::multimap<std::string, int> &geomName2Phys);

#endif // HAVE_LIBCGNS

#endif // CGNS_READ_H
