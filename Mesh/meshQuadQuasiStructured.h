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

#endif
