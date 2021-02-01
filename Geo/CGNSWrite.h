// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_WRITE_H
#define CGNS_WRITE_H

#include <vector>
#include <map>
#include <set>
#include <string>
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)

class GModel;
class GEntity;
class MVertex;

// Type for global node index -> (partition, local node index) correspondence
struct LocalData {
  LocalData() : partition(0), index(0) {}
  unsigned int partition;
  cgsize_t index;
};
// typedef std::vector<LocalData> Global2LocalData;
typedef std::map<MVertex *, std::vector<LocalData> > Vertex2LocalData;

void getEntitiesToSave(const std::vector<GEntity *> &allEntities, bool saveAll,
                       std::vector<GEntity *> &entities);

void getPeriodicEntities(const std::vector<GEntity *> &allEntities,
                         std::vector<GEntity *> &entitiesPer);

void getPartitionInterfaceEntities(const std::vector<GEntity *> &entities,
                                   bool saveAll,
                                   std::vector<GEntity *> &entitiesInt);

void initInterfVertex2LocalData(const std::vector<GEntity *> &entitiesPer,
                                const std::vector<GEntity *> &entitiesInterf,
                                Vertex2LocalData &interfVert2Local);

int writeZone(GModel *model, bool saveAll, double scalingFactor, int meshDim,
              std::size_t numNodesTotal, std::size_t partition,
              const std::vector<GEntity *> &entities, int cgIndexFile,
              int cgIndexBase, std::vector<std::string> &zoneName,
              Vertex2LocalData &interfVert2Local, std::set<int> &eleMshTypes,
              std::map<GEntity *, std::string> &geomEntities);

int writePeriodic(const std::vector<GEntity *> &entitiesPer, int cgIndexFile,
                  int cgIndexBase, const std::vector<std::string> &zoneName,
                  Vertex2LocalData &interfVert2Local);

void getEntitiesInPartitions(
  const std::vector<GEntity *> &entities,
  std::vector<std::vector<GEntity *> > &entitiesPart);

int writeInterfaces(const std::vector<GEntity *> &entitiesInterf,
                    int cgIndexFile, int cgIndexBase,
                    const std::vector<std::string> &zoneName,
                    Vertex2LocalData &interfVert2Local);

int writeHOPointInfo(const std::set<int> &eleMshTypes, int cgIndexFile,
                     int cgIndexBase);

int writeGeomEntities(std::map<GEntity *, std::string> &geomEntities,
                      int cgIndexFile, int cgIndexBase);

#endif // HAVE_LIBCGNS

#endif // CGNS_WRITE_H
