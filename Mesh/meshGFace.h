#ifndef _MESH_GFACE_H_
#define _MESH_GFACE_H_

#include <map>
#include "SPoint2.h"

class MVertex;
class GFace;
// Create the mesh of the face
class meshGFace 
{
  public :
  void operator () ( GFace * );
};

// destroy the mesh of the face
class deMeshGFace 
{
 public :
  void operator () ( GFace * );
};

#endif
