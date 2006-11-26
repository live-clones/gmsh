// $Id: meshGFaceExtruded.cpp,v 1.2 2006-11-26 16:24:04 geuzaine Exp $
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
#include "GModel.h"
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
    return 0;

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // extruded from a curve
    GEdge *ge = gf->model()->edgeByTag(ep->geo.Source);
    if(!ge) return 0;
    for(unsigned int i = 0; i < ge->mesh_vertices.size(); i++) {
      //printf("extruding vertex %d\n", i);
    }
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
    // copy of a surface ("chapeau")
    /*
    source = FindSurface(ep->geo.Source);
    if(!source)
      return false;
    copy_mesh(ss, s);
    */
  }

  return 1;
}
  
