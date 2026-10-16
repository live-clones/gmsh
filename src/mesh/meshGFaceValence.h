// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_VALENCE_H
#define MESH_GFACE_VALENCE_H

#include <vector>

class GFace;

// Rework the triangle mesh of a planar surface toward valence 6 (and the
// ideal valence on the boundary) and toward equilateral triangles, according
// to Mesh.ValenceRepair2D and Mesh.ValenceRepairThreshold2D, after its
// meshing; the triangles of the discrete surfaces that touch it are frozen
// neighbors. See meshGFaceValence.cpp.
void repairValence2D(GFace *gf);

// The same on existing meshes (gmsh::model::mesh::optimize, type 2 if
// Mesh.ValenceRepair2D is 0): the surfaces of faces that lie in a plane are
// repaired together (the nodes of the curves between them may slide), the
// triangles of the other surfaces that touch them frozen; each surface alone
// otherwise.
void repairValence2D(const std::vector<GFace *> &faces);

#endif
