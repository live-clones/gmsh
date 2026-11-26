// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_QUAD_QUASI_STRUCTURED_H
#define MESH_QUAD_QUASI_STRUCTURED_H

// What the packing of parallelograms (Mesh.Algorithm = 9) keeps of the former
// quasi-structured quad mesher: the background mesh and its guiding field,
// the quad patterns of simple faces and the transfer of the seam nodes.

class GModel;

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

// Reparametrize the mesh nodes on seam curves (and isolated corners) of gm on
// the associated GFace and transfer them there; the seam curves end up with
// empty meshes. Returns 0 on success.
int transferSeamGEdgesVerticesToGFace(GModel *gm);

// Look for simple CAD faces of gm (topological disk, a few corners) that can
// be remeshed with simple quad patterns. Returns 0 on success.
//
// minimumQualityRequired: minimum quality (SICN) to accept a new quad mesh
int quadMeshingOfSimpleFacesWithPatterns(GModel *gm,
                                         double minimumQualityRequired = 0.5);

#endif
