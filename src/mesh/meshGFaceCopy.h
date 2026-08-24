// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_COPY_H
#define MESH_GFACE_COPY_H

class GFace;

// Copy the mesh of a surface onto another surface that has it as mesh master,
// mapping the nodes through the affine transformation relating the two.
void copyMesh(GFace *source, GFace *target);

#endif
