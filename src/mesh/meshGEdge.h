// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GEDGE_H
#define MESH_GEDGE_H

class GEdge;

// Create the mesh of the edge
struct meshGEdge {
  meshGEdge() {}
  void operator()(GEdge *);
};

// destroy the mesh of the edge
struct deMeshGEdge {
  deMeshGEdge() {}
  void operator()(GEdge *);
};

// Orient the mesh of an edge. This is necessary to comply with the orientation
// constraints
struct orientMeshGEdge {
  void operator()(GEdge *);
};

int MeshExtrudedCurve(GEdge *ge);

// compute the target number of points on the curve considering all meshing
// options, counting the boundary vertices
int meshGEdgeTargetNumberOfPoints(GEdge *);

#endif
