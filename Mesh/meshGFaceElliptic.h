// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_GFACE_ELLIPTIC_H_
#define _MESH_GFACE_ELLIPTIC_H_

#include <map>
#include <vector>
#include "MElement.h"
#include "MEdge.h"
#include "STensor3.h"

class GFace;
class GVertex;
class MVertex;
class Centerline;


bool createRegularTwoCircleGrid (Centerline *center, GFace *gf);


#endif
