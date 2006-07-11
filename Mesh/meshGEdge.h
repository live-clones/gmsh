#ifndef _MESH_GEDGE_H_
#define _MESH_GEDGE_H_

class GEdge;
// Create the mesh of the edge
class meshGEdge 
{
 public :
  void operator () ( GEdge * );
};

// destroy the mesh of the edge
class deMeshGEdge 
{
 public :
  void operator () ( GEdge * );
};

#endif
