// $Id: GVertex.cpp,v 1.23 2008-06-05 16:52:14 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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

#include <string.h>
#include <algorithm>
#include "GVertex.h"
#include "GFace.h"
#include "MVertex.h"

#if defined(HAVE_GMSH_EMBEDDED)
#  include "GmshEmbedded.h"
#else
#  include "Message.h"
#endif

GVertex::GVertex(GModel *m, int tag, double ms) : GEntity(m, tag), meshSize(ms) 
{
}

GVertex::~GVertex()
{
  for(unsigned int i = 0; i < mesh_vertices.size(); i++)
    delete mesh_vertices[i];
}

void GVertex::setPosition(GPoint &p)
{
  Msg::Error("Cannot set position of this kind of vertex");
}

void GVertex::addEdge(GEdge *e)
{ 
  l_edges.push_back(e);
}

void GVertex::delEdge(GEdge *e)
{ 
  l_edges.erase(std::find(l_edges.begin(), l_edges.end(), e));
}

SPoint2 GVertex::reparamOnFace(GFace *gf, int) const
{
  return gf->parFromPoint(SPoint3(x(), y(), z()));
}

std::string GVertex::getAdditionalInfoString()
{
  char str[256];
  sprintf(str, "{%g,%g,%g}", x(), y(), z());
  double lc = prescribedMeshSizeAtVertex();
  if(lc < 1.e22){
    char str2[256];
    sprintf(str2, " (cl: %g)", lc);
    strcat(str, str2);
  }
  return std::string(str);
}
