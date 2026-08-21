// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_DIRECTIONS_H
#define MESH_GFACE_DIRECTIONS_H

class GFace;

// Store, for every node of the surface mesh, the cross field directions and
// the background mesh size in GFace::storage1..storage4. Only called when
// Mesh.Algorithm3D is the R-tree (hex-dominant) algorithm; the data is
// consumed by contrib/domhex (directions3D.cpp).
void directions_storage(GFace *gf);

#endif
