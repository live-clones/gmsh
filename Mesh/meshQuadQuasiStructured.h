// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_QUASI_STRUCTURED_H
#define MESH_QUAD_QUASI_STRUCTURED_H

class GModel;

/**
 * @brief The QuadQuasiStructured meshing mode requires control
 *        over various meshing parameters which are stored in the
 *        global context. To deal with this without adding conditions
 *        everywhere in the other meshing parts, we use this updater
 *        which must be created at the beginning of the meshing cycle,
 *        and deleted at the end to restore the initial values.
 */
class QuadqsContextUpdater {
public:
  QuadqsContextUpdater();
  ~QuadqsContextUpdater();

protected:
  void setQuadqsOptions();
  void restoreInitialOption();

protected:
  int algo2d;
  int recombineAll;
  int algoRecombine;
  int recombineOptimizeTopology;
  double lcFactor;
  double lcMin;
  double lcMax;
  int lcFromPoints;
  int minCurveNodes;
  int minCircleNodes;
};

/**
 * @brief
 *
 * @param[in] gm GModel containing the CAD and/or meshes
 * @param[in] overwriteGModelMesh delete existing mesh, rebuild from CAD
 * @param[in] deleteGModelMeshAfter after background mesh creation, delete the
 * GModel mesh
 * @param[in] N the N-symmetry field invariance. N=4 for cross and N=6 for
 * asterisk fields
 *
 * @return 0 if success
 */
int BuildBackgroundMeshAndGuidingField(GModel *gm,
                                       bool overwriteGModelMesh = false,
                                       bool deleteGModelMeshAfter = false,
                                       int N = 4);

/**
 * @brief To check if a compatible background mesh and
 *        guiding field already exists
 *
 * @return true if exists
 */
bool backgroundMeshAndGuidingFieldExists(GModel *gm);

/**
 * @brief Look for non-ideal vertex valences in quad mesh and find a better
 *        local remeshing by looking into all disk quadrangulations.
 *        Quad quality (SICN) is monitored and the minimum will not decrease.
 *        Executes over CAD faces in parallel if multiple threads available.
 *        Only faces whose meshing status is GFace::PENDING are processed
 *
 * @param gm The model containing the face quad meshes.
 *
 * @return 0 if success
 */
int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel *gm);

/**
 * @brief Mesh vertices on seam curves (and isolated corners) are
 *        reparametrized on the associated GFace and transfered.
 *        The seam curves have empty meshes in the end.
 *
 * @param gm The model containing the meshes
 *
 * @return 0 if success
 */
int transferSeamGEdgesVerticesToGFace(GModel *gm);

/**
 * @brief Look for patches of quads with >=3 irregular vertices which
 *        can be remeshed with more regular quad meshes. The replacement
 *        meshes are subdivisions of a list of predefined patterns.
 *        Irregular vertices matching cross field singularities are
 *        preserved.
 *        Executes over CAD faces in parallel if multiple threads available.
 *        Only faces whose meshing status is GFace::PENDING are processed
 *
 * @param gm The model containing the face quad meshes.
 *
 * @return 0 if success
 */
int optimizeTopologyWithCavityRemeshing(GModel *gm);

/**
 * @brief Look for simple CAD faces (topological disk, a few corners)
 *        which can be remeshed with simple quad patterns.
 *        The patterns are the same that are used in cavity remeshing.
 *        Executes over CAD faces in parallel if multiple threads available.
 *        Only faces whose meshing status is GFace::PENDING are processed
 *
 * @param gm The model containing the face quad meshes.
 * @param minimumQualityRequired Minimum quality (SICN) required to accept a new
 * quad mesh
 *
 * @return 0 if success
 */
int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired = 0.5);

/**
 * @brief Midpoint subdivision of the surface mesh with projections
 *        on the CAD surfaces, using the background mesh for
 *        faster projections.
 *
 * @param gm The model containing the surface meshes
 *
 * @return 0 if success
 */
int RefineMeshWithBackgroundMeshProjection(GModel *gm);

/**
 * @brief The initial unstructured quad-tri mesh may contain
 * very bad configurations (e.g. valence 50+) due to failures
 * in algo pack. This method replaces them by meshes produced
 * with algo meshadapt.
 *
 * @param gm The model containing the surface meshes
 *
 * @return 0 if success
 */
int replaceBadQuadDominantMeshes(GModel *gm);

#endif
