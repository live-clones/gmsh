// $Id: meshGFaceExtruded.cpp,v 1.1 2006-11-26 04:36:46 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "ExtrudeParams.h"
#include "meshGFace.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "Message.h"

int MeshExtrudedSurface(GFace *gf)
{
  ExtrudeParams *ep = gf->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh)
    return false;

  Msg(GERROR, "Extrusion has yet to be reinterfaced!");

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // extruded from a curve
    /*
    c = FindCurve(abs(ep->geo.Source));
    if(!c)
      return false;
    for(int i = 0; i < List_Nbr(c->Vertices); i++) {
      List_Read(c->Vertices, i, &v1);
      Extrude_Vertex(&v1, NULL);
    }
    Extrude_Curve(&c, NULL);
    */
  }
  else {
    // this is the "hat" of an extruded surface
    /*
    source = FindSurface(ep->geo.Source);
    if(!source)
      return false;
    copy_mesh(ss, s);
    */
  }

  return 1;
}
  
