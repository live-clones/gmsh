// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_VALENCE_H
#define MESH_GFACE_VALENCE_H

class GFace;

// Rework the triangle mesh of a planar surface toward valence 6 (and the
// ideal valence on the boundary) and toward equilateral triangles, according
// to Mesh.ValenceRepair2D and Mesh.ValenceRepairThreshold2D. See
// meshGFaceValence.cpp.
void repairValence2D(GFace *gf);

#endif
