// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Anthony Royer
//   Boris Martin

#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <variant>

#include "GModel.h"
#include "GEntity.h"
#include "Overlap.h"

#if defined(HAVE_POST)
#include "PView.h"
#endif

bool readMSH4Physicals(GModel *const model, FILE *fp, GEntity *const entity,
                       bool binary, bool swap);

bool readMSH4BoundingEntities(GModel *const model, FILE *fp,
                              GEntity *const entity, bool binary, bool swap,
                              int maxTagEmbed);

bool readMSH4EntityInfo(FILE *fp, bool binary, bool swap, double version,
                        bool partition, int dim, int &tag, int &parentDim,
                        int &parentTag, std::vector<int> &partitions,
                        double &minX, double &minY, double &minZ, double &maxX,
                        double &maxY, double &maxZ);

bool readMSH4Entities(GModel *const model, FILE *fp, bool partition,
                      bool binary, bool swap, double version);

MVertex **readMSH4Nodes(GModel *const model, FILE *fp, bool binary, bool &dense,
                        std::size_t &totalNumRead, std::size_t &maxNodeNum,
                        bool swap, double version);

std::pair<MElement *, GEntity *> *
readMSH4Elements(GModel *const model, FILE *fp, bool binary, bool &dense,
                 std::size_t &totalNumRead, std::size_t &maxElementNum,
                 bool swap, double version);

bool readMSH4PeriodicNodes(GModel *const model, FILE *fp, bool binary,
                           bool swap, double version);

bool readMSH4GhostElements(GModel *const model, FILE *fp, bool binary,
                           bool swap);

bool readMSH4Parametrizations(GModel *const model, FILE *fp, bool binary);

template <int dim>
bool readMSH4Overlaps(GModel *const model, FILE *fp, bool binary);

template <int dim>
bool readMSH4OverlapBoundaries(GModel *const model, FILE *fp, bool binary);

bool readMSH4Edges(GModel *const model, FILE *fp, bool binary);

bool readMSH4Faces(GModel *const model, FILE *fp, bool binary);

void writeMSH4Physicals(FILE *fp, GEntity *const entity, bool binary);

void writeMSH4BoundingBox(SBoundingBox3d boundBox, FILE *fp,
                          double scalingFactor, bool binary, int dim,
                          double version);

void writeMSH4Entities(
  GModel *const model, FILE *fp, bool partition, bool binary,
  double scalingFactor, double version,
  std::map<GEntity *, SBoundingBox3d> *entityBounds, int partitionToSave,
  const std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
    &entitiesWithSubsetToExport);

template <class It>
void writeMSH4EntityNodes(GEntity *ge, FILE *fp, bool binary,
                          int saveParametric, double scalingFactor,
                          double version, It begin, It end, size_t numVerts);

std::size_t
getAdditionalEntities(std::set<GRegion *, GEntityPtrLessThan> &regions,
                      std::set<GFace *, GEntityPtrLessThan> &faces,
                      std::set<GEdge *, GEntityPtrLessThan> &edges,
                      std::set<GVertex *, GEntityPtrLessThan> &vertices);

void getEntitiesToSave(GModel *const model, bool partitioned,
                       int partitionToSave, bool saveAll,
                       std::set<GRegion *, GEntityPtrLessThan> &regions,
                       std::set<GFace *, GEntityPtrLessThan> &faces,
                       std::set<GEdge *, GEntityPtrLessThan> &edges,
                       std::set<GVertex *, GEntityPtrLessThan> &vertices);

void writeMSH4Nodes(GModel *const model, FILE *fp, bool partitioned,
                    int partitionToSave, bool binary, int saveParametric,
                    double scalingFactor, bool saveAll, double version,
                    std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
                      &entitiesWithSubsetToExport);

void writeMSH4Elements(
  GModel *const model, FILE *fp, bool partitioned, int partitionToSave,
  bool binary, bool saveAll, double version,
  const std::variant<
    std::monostate,
    decltype(findCoveredEntitiesAndElementsToSave<2>(model, partitionToSave)),
    decltype(findCoveredEntitiesAndElementsToSave<3>(model, partitionToSave))>
    &overlapElements);

void writeMSH4Edges(GModel *const model, FILE *fp, bool binary,
                    bool partitioned, int partitionToSave);

void writeMSH4Faces(GModel *const model, FILE *fp, bool binary,
                    bool partitioned, int partitionToSave);

void writeMSH4PeriodicNodes(GModel *const model, FILE *fp, bool binary,
                            double version);

void writeMSH4GhostCells(GModel *const model, FILE *fp, int partitionToSave,
                         bool binary);

void writeMSH4Parametrizations(GModel *const model, FILE *fp, bool binary);

// Overlap exports
template <int dim>
void writeMSH4Overlaps(GModel *const model, FILE *fp, int partitionToSave,
                       bool binary);

template <int dim> const auto &getInnerOverlap(GModel *const model);

template <int dim> const auto &getOuterOverlap(GModel *const model);

template <int dim>
void writeMSH4OverlapBoundaries(GModel *const model, FILE *fp,
                                int partitionToSave, bool binary);

bool getPhyscialNameInfo(const std::string &name, int &parentPhysicalTag,
                         std::vector<int> &partitions);
