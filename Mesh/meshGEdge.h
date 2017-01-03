// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _MESH_GEDGE_H_
#define _MESH_GEDGE_H_

class GEdge;

// Create the mesh of the edge
class meshGEdge {
 public :
  meshGEdge() {}
  void operator () (GEdge *);
};

// destroy the mesh of the edge
class deMeshGEdge {
 public :
  deMeshGEdge() {}
  void operator () (GEdge *);
};

// Orient the mesh of an edge. This is necessary to comply with the orientation
// constraints
class orientMeshGEdge {
 public :
  void operator()(GEdge *);
};

int MeshExtrudedCurve(GEdge *ge);

#endif
