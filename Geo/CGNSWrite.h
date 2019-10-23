// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_WRITE_H
#define CGNS_WRITE_H

#include <vector>
#include <map>
#include <string>
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)


class GModel;
class GEntity;
class MVertex;


// Type for global node index -> (partition, local node index) correspondence
struct LocalData { unsigned int partition = 0; cgsize_t index = 0; };
// typedef std::vector<LocalData> Global2LocalData;
typedef std::map<MVertex *, std::vector<LocalData> > Vertex2LocalData;


void getPeriodicEntities(const std::vector<GEntity *> &entities,
                         std::vector<GEntity *> &entitiesPer);

void getPartitionInterfaceEntities(const std::vector<GEntity *> &entities,
                                   std::vector<GEntity *> &entitiesInt);

void initInterfVertex2LocalData(const std::vector<GEntity *> &entitiesPer,
                                const std::vector<GEntity *> &entitiesInterf,
                                Vertex2LocalData &interfVert2Local);

int writeZone(GModel *model, bool saveAll, double scalingFactor,
              int meshDim, std::size_t numNodesTotal, std::size_t partition,
              const std::vector<GEntity *> &entities, int cgIndexFile,
              int cgIndexBase, std::vector<std::string> &zoneName,
              Vertex2LocalData &interfVert2Local);

int writePeriodic(const std::vector<GEntity *> &entitiesPer, int cgIndexFile,
                   int cgIndexBase, const std::vector<std::string> &zoneName,
                   Vertex2LocalData &interfVert2Local);

void getEntitiesInPartitions(const std::vector<GEntity *> &entities,
                          std::vector<std::vector<GEntity *> > &entitiesPart);

int writeInterfaces(const std::vector<GEntity *> &entitiesInterf,
                    int cgIndexFile, int cgIndexBase,
                    const std::vector<std::string> &zoneName,
                    Vertex2LocalData &interfVert2Local);

#endif // HAVE_LIBCGNS

#endif // CGNS_WRITE_H
