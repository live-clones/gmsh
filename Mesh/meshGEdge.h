// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GEDGE_H_
#define _MESH_GEDGE_H_

class GEdge;

// Create the mesh of the edge
class meshGEdge {
 public :
  meshGEdge ()  {}
  void operator () ( GEdge * );
};

// destroy the mesh of the edge
class deMeshGEdge {
  bool _STL;
 public :
  deMeshGEdge () {}
  void operator () ( GEdge * );
};

int MeshExtrudedCurve(GEdge *ge);

#endif
