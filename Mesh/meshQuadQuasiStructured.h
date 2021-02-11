// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_QUASI_STRUCTURED_H
#define MESH_QUAD_QUASI_STRUCTURED_H

class GModel;

/**
 * @brief 
 *
 * @param gm GModel containing the CAD and/or meshes
 * @param overwriteGModelMesh delete existing mesh, rebuild from CAD
 * @param deleteGModelMeshAfter after background mesh creation, delete the GModel mesh
 *
 * @return 0 if success
 */
int BuildBackgroundMeshAndGuidingField(
    GModel* gm, 
    bool overwriteGModelMesh = false,
    bool deleteGModelMeshAfter = false);

/**
 * @brief To check if a compatible background mesh and
 *        guiding field already exists
 *
 * @return true if exists
 */
bool backgroundMeshAndGuidingFieldExists(GModel* gm);

/**
 * @brief Look for non-ideal vertex valences in quad mesh and find a better
 *        local remeshing by looking into all disk quadrangulations.
 *        Quad quality (SICN) is monitored and the minimum will not decrease.
 *        Executes over CAD faces in parallel if multiple threads available.
 *
 * @param gm The model containing the face quad meshes.
 *
 * @return 0 if success
 */
int optimizeTopologyWithDiskQuadrangulationRemeshing(GModel* gm);

/**
 * @brief Mesh vertices on seam curves (and isolated corners) are
 *        reparametrized on the associated GFace and transfered.
 *        The seam curves have empty meshes in the end.
 *
 * @param gm The model containing the meshes
 *
 * @return 0 if success
 */
int transferSeamGEdgesVerticesToGFace(GModel* gm);

/**
 * @brief Look for patches of quads with >=3 irregular vertices which 
 *        can be remeshed with more regular quad meshes. The replacement
 *        meshes are subdivisions of a list of predefined patterns.
 *        Irregular vertices matching cross field singularities are
 *        preserved.
 *
 * @param gm The model containing the face quad meshes.
 *
 * @return 0 if success
 */
int optimizeTopologyWithCavityRemeshing(GModel* gm);

#endif
