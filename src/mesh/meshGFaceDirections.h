// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GFACE_DIRECTIONS_H
#define MESH_GFACE_DIRECTIONS_H

class GFace;
class Field;
class MVertex;
class SPoint2;
class SVector3;

// The direction at a node of a surface mesh from the scaled cross field
// guiding it (PACK, QuadQS): the field vector projected on the tangent plane
// (t1, unit), the unit normal and the size (the norm of the field vector),
// with the parameter of the node. False if one of them is degenerate.
bool crossFieldDirection(GFace *gf, Field *crossField, MVertex *vertex,
                         SPoint2 &uv, SVector3 &t1, SVector3 &normal,
                         double &size);

// Store, for every node of the surface mesh, the cross field directions and
// the mesh size in GFace::storage1..storage4: those of the scaled cross field
// guiding the surface mesh if any (PACK, QuadQS), else of the background
// mesh of the surface. Only called when
// Mesh.Algorithm3D is the R-tree (hex-dominant) algorithm; the data is
// consumed by contrib/domhex (directions3D.cpp).
void directions_storage(GFace *gf);

#endif
