// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _GEO_CONSISTENCY_CHECK_H_
#define _GEO_CONSISTENCY_CHECK_H_

#include <MElement.h>
#include <MVertex.h>
#include <GEntity.h>
#include <GRegion.h>
#include <GFace.h>
#include <GEdge.h>
#include <GVertex.h>
#include <unordered_map>
#include <set>
#include <optional>
#include <tuple>

class GModel;

// Count the number of times each vertex is used in the model, over a) all entites of the correct dim if "entities" is null, or b) all entities in the set "entities" (which must be of dimension "dim")
std::unordered_map<MVertex*, int> countVertexOccurences(GModel* model, const std::optional<std::set<GEntity*, GEntityPtrLessThan>>& entities, int dim = 3);

std::set<std::tuple<MVertex*, int, int>> findMismatch(const std::unordered_map<MVertex*, int>& saved, const std::unordered_map<MVertex*, int>& expected);

std::vector<std::set<MVertex*>> computeVertexAdjacency(GModel* model);
std::vector<std::set<MVertex*>> computeVertexAdjacency(GModel* model,
const std::set<GRegion*, GEntityPtrLessThan>& regions,
const std::set<GFace*, GEntityPtrLessThan>& faces,
const std::set<GEdge*, GEntityPtrLessThan>& edges,
const std::set<GVertex*, GEntityPtrLessThan>& vertices);

bool vertexInPartition(const MVertex* vert, int partition);




/// Utils

struct EntityPackage {
    std::set<GRegion*, GEntityPtrLessThan> regions;
    std::set<GFace*, GEntityPtrLessThan> faces;
    std::set<GEdge*, GEntityPtrLessThan> edges;
    std::set<GVertex*, GEntityPtrLessThan> vertices;

    EntityPackage() = default;
    EntityPackage(const GModel* model, int partitionToSave);
    // For all entities, loop over nodes from elements. Add the entities of the odes
    void fillFromNodes(const GModel* model);
    void addEntitiesFromNodes(const GEntity* entity);
};


#endif // _GEO_CONSISTENCY_CHECK_H_

