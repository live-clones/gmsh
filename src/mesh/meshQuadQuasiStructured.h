// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_QUASI_STRUCTURED_H
#define MESH_QUAD_QUASI_STRUCTURED_H

#include <vector>

class GModel;
class GFace;
class GEdge;

namespace CppUtils {
  template <typename T> class RestoreValueAtEndOfLife;
}

// The QuadQuasiStructured meshing mode needs control over various meshing
// parameters stored in the global context. To deal with that without adding
// conditions everywhere in the other meshing parts, we use this updater, which
// must be created at the beginning of the meshing cycle and deleted at the end
// to restore the initial values.
class QuadqsContextUpdater {
public:
  QuadqsContextUpdater();
  ~QuadqsContextUpdater();

protected:
  void setQuadqsOptions();
  void restoreInitialOption();

protected:
  std::vector<CppUtils::RestoreValueAtEndOfLife<bool>* > backups_bool;
  std::vector<CppUtils::RestoreValueAtEndOfLife<char>* > backups_char;
  std::vector<CppUtils::RestoreValueAtEndOfLife<int>* > backups_int;
  std::vector<CppUtils::RestoreValueAtEndOfLife<double>* > backups_double;
};

// Build the background mesh and the guiding field of gm, which contains the
// CAD and/or the meshes. Returns 0 on success.
//
// overwriteGModelMesh: delete the existing mesh and rebuild it from the CAD
// deleteGModelMeshAfter: delete the GModel mesh once the background mesh is
//   built
// overwriteField: overwrite the existing background field
// N: the N-symmetry field invariance, 4 for cross and 6 for asterisk fields
int BuildBackgroundMeshAndGuidingField(GModel *gm,
                                       bool overwriteGModelMesh = false,
                                       bool deleteGModelMeshAfter = false,
                                       bool overwriteField = false,
                                       int N = 4);

// Check whether a compatible background mesh and guiding field already exist.
bool backgroundMeshAndGuidingFieldExists(GModel *gm);

// Look for non-ideal node valences in the quad meshes of gm and find a better
// local remeshing by looking into all disk quadrangulations. Quad quality
// (SICN) is monitored and its minimum will not decrease. Runs over the CAD
// faces in parallel if several threads are available, and only processes faces
// whose meshing status is GFace::PENDING. Returns 0 on success.
int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel *gm);

// Reparametrize the mesh nodes on seam curves (and isolated corners) of gm on
// the associated GFace and transfer them there; the seam curves end up with
// empty meshes. Returns 0 on success.
int transferSeamGEdgesVerticesToGFace(GModel *gm);

// Look for patches of quads with three or more irregular nodes in gm that can
// be remeshed with more regular quad meshes; the replacement meshes are
// subdivisions of a list of predefined patterns. Irregular nodes matching
// cross field singularities are preserved. Runs over the CAD faces in parallel
// if several threads are available, and only processes faces whose meshing
// status is GFace::PENDING. Returns 0 on success.
int optimizeTopologyWithCavityRemeshing(GModel *gm);

// Look for simple CAD faces of gm (topological disk, a few corners) that can
// be remeshed with simple quad patterns, the same ones used in cavity
// remeshing. Runs over the CAD faces in parallel if several threads are
// available, and only processes faces whose meshing status is GFace::PENDING.
// Returns 0 on success.
//
// minimumQualityRequired: minimum quality (SICN) to accept a new quad mesh
int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired = 0.5);

// Midpoint subdivision of the surface meshes of gm, with projections on the
// CAD surfaces, using the background mesh for faster projections. Returns 0 on
// success.
int RefineMeshWithBackgroundMeshProjection(GModel *gm);

// The initial unstructured quad-tri mesh may contain very bad configurations
// (valence 50+, say) when the packing algorithm fails; replace those by meshes
// produced with MeshAdapt. Returns 0 on success.
int replaceBadQuadDominantMeshes(GModel *gm);

// Identify the acute corners of the faces of gm and set the first nodes of the
// curve meshes at the same length from the corner. Returns 0 on success.
int optimize1DMeshAtAcuteCorners(GModel *gm);

// Add one extruded quad layer on the curves of gm where the boundary quad
// valences are not ideal. Returns 0 on success.
int optimizeQuadMeshBoundaries(GModel *gm);

// Delete the background meshes and fields used by quadqs meshing and
// remeshing. Returns 0 on success.
int quadqsCleanup(GModel *gm);

#endif
