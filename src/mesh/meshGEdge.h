// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MESH_GEDGE_H
#define MESH_GEDGE_H

class GEdge;
class GEntity;

// Create the mesh of the edge
struct meshGEdge {
  int ForceNumberOfSubdivisions;
  meshGEdge() : ForceNumberOfSubdivisions (-1){}
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

// whether the mesh of an entity can be extruded or copied by an extrusion:
// not if it is of high order (the extrusion makes first-order elements from
// all the nodes), nor if it is the mesh of a curve read without its elements
// (the nodes are copied in the order of the elements); an error says why
bool extrudableMesh(GEntity *from);

// compute the target number of points on the curve considering all meshing
// options, counting the boundary vertices
int meshGEdgeTargetNumberOfPoints(GEdge *);

// add one point on ends of an edge at a given distance
int meshGEdgeInsertBoundaryLayer(GEdge *ge, double width);

#endif
