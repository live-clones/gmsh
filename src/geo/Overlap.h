// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Boris Martin

#ifndef OVERLAP_H
#define OVERLAP_H

#include "OverlapEntities.h"

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
template <int dim>
void buildOverlapEntities(GModel *const model,
                          const OverlapCollection<dim> &overlaps);

// For each entity, identify the boundary (set of MEdge/MFace) of the overlap
// patch. This includes all parts of the patch, including the interface between
// the inner and overlap. These boundaries are computed per parent entity, so a
// physical interface will be a boundary.
template <int dim>
OveralBoundariesMesh<dim>
findBoundaryOfOverlapEntities(const OverlapCollection<dim> &overlaps);

/**
 * Robustness wrt to deep overlaps:
 * for inner partitions, if it's an interface, we look af whether it is an
 * internal interface or not
 * TODO: create entities, add correct elem type. Orientation of the elements ?
 */

template <int dim>
void overlapBuildBoundaries(GModel *const model,
                            const OverlapCollection<dim> &overlaps);

/**
 * Export-related helpers
 */

template <int dim>
std::unordered_map<typename EntityTraits<dim>::PartitionEntity *,
                   std::unordered_set<MElement *>>
findCoveredEntitiesAndElementsToSave(GModel *const model, int partition);

template <int dim>
std::unordered_map<GEntity *, std::unordered_set<MVertex *>>
findNonOwnedVerticesToSave(
  GModel *const model, int partition,
  const std::unordered_map<typename EntityTraits<dim>::PartitionEntity *,
                           std::unordered_set<MElement *>> &coveredEntities);

#endif // OVERLAP_H