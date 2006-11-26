// $Id: meshGFaceExtruded.cpp,v 1.3 2006-11-26 19:30:23 geuzaine Exp $
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

int extrudeVertex(GFace *gf, MVertex *v)
{
  ExtrudeParams *ep = gf->meshAttributes.extrude;
  for(int i = 0; i < ep->mesh.NbLayer; i++) {
    for(int j = 1; j < ep->mesh.NbElmLayer[i]; j++) {
      double x = v->x(), y = v->y(), z = v->z();
      ep->Extrude(i, j, x, y, z);
      gf->mesh_vertices.push_back(new MVertex(x, y, z, gf));
    }
  }
}

int copyMesh(GFace *gf, GFace *from)
{
  ExtrudeParams *ep = gf->meshAttributes.extrude;
  for(unsigned int i = 0; i < from->mesh_vertices.size(); i++){
    MVertex *v = from->mesh_vertices[i];
    double x = v->x(), y = v->y(), z = v->z();
    ep->Extrude(ep->mesh.NbLayer - 1, ep->mesh.NbElmLayer[ep->mesh.NbLayer - 1], 
		x, y, z);
    gf->mesh_vertices.push_back(new MVertex(x, y, z, gf));
  }
}

int MeshExtrudedSurface(GFace *gf)
{
  ExtrudeParams *ep = gf->meshAttributes.extrude;

  if(!ep || !ep->mesh.ExtrudeMesh)
    return 0;

  if(ep->geo.Mode == EXTRUDED_ENTITY) {
    // extruded from a curve
    GEdge *e = gf->model()->edgeByTag(std::abs(ep->geo.Source));
    if(!e) return 0;
    for(unsigned int i = 0; i < e->mesh_vertices.size(); i++)
      extrudeVertex(gf, e->mesh_vertices[i]);
    // get bounding edges and create quads/tris
  }
  else {
    // copy of a surface ("chapeau")
    GFace *f = gf->model()->faceByTag(std::abs(ep->geo.Source));
    if(!f) return 0;
    copyMesh(gf, f);
  }

  return 1;
}
