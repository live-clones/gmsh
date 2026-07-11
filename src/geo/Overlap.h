// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Martin

#ifndef OVERLAP_H
#define OVERLAP_H

#include "OverlapEntities.h"

class OverlapManager;

// Overlap collection: for each partition,
// we store all covered entities (of other partitions) with the subset of
// elements to use. Can be multiple layers if built accordingly

// Build a 1-layer overlap efficiently: we loop over all volume elements. If one
// of its vertices belongs to a shared partitionEntity, that element is part of
// the overlap of that other partition.
template <int dim> OverlapCollection<dim> quickOverlap(GModel *const model);

// For each partition: find all elements on other partitions touching the
// current overlap
template <int dim>
void extendOverlapCollection(GModel *const model,
                             OverlapCollection<dim> &overlaps);

// Read an overlap collection and modify the GModel to add overlap entities.
// No new elements are created but these entities will point to underlying
// elements of their covered partitionEntity. Does not handle any boundary.
// Overlap data is stored in the provided OverlapManager.
template <int dim>
void buildOverlapEntities(GModel *const model, OverlapManager &mgr,
                          const OverlapCollection<dim> &overlaps);

// For each entity, identify the boundary (set of MEdge/MFace) of the overlap
// patch. This includes all parts of the patch, including the interface between
// the inner and overlap. These boundaries are computed per parent entity, so a
// physical interface will be a boundary.
template <int dim>
OverlapBoundariesMesh<dim>
findBoundaryOfOverlapEntities(const OverlapCollection<dim> &overlaps);

/**
 * Create the boundary entities of the overlap patches and register them in
 * the manager. Facets lying on an existing dim-1 entity become "overlaps of
 * boundaries" (grouped by that entity); facets on a partition interface not
 * involving the overlap's partition (robustness for deep overlaps on thin
 * partitions), or on no existing entity at all, become new "inner boundary"
 * entities. Facets on an interface involving the partition itself are not
 * duplicated: the existing interface entity already represents them.
 * TODO: check the orientation of the created boundary elements.
 */
template <int dim>
void overlapBuildBoundaries(GModel *const model, OverlapManager &mgr,
                            const OverlapCollection<dim> &overlaps);

/**
 * Export-related helpers
 */

template <int dim>
CoveredElementsMap<dim>
findCoveredEntitiesAndElementsToSave(GModel *const model,
                                     const std::vector<int> &partitions);

template <int dim>
EntityToVerticesMap
findNonOwnedVerticesToSave(GModel *const model,
                           const std::vector<int> &partitions,
                           const CoveredElementsMap<dim> &coveredEntities);

#endif
