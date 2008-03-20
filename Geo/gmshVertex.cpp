// $Id: gmshVertex.cpp,v 1.10 2008-03-20 11:44:07 geuzaine Exp $
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

#include "GFace.h"
#include "GEdge.h"
#include "gmshVertex.h"
#include "Geo.h"
#include "GeoInterpolation.h"
#include "Message.h"

SPoint2 gmshVertex::reparamOnFace(GFace *face, int dir) const
{
  Surface *s = (Surface*)face->getNativePtr();

  if(s->geometry){
    // It is not always right if it is periodic.
    if(l_edges.size() == 1 && 
       (*l_edges.begin())->getBeginVertex() ==
       (*l_edges.begin())->getEndVertex()){
      Range<double> bb = (*l_edges.begin())->parBounds(0);
      return (*l_edges.begin())->reparamOnFace(face, bb.low(), dir);
    } 
    return v->pntOnGeometry;
  }

  if(s->Typ ==  MSH_SURF_REGL){
    Curve *C[4];
    for(int i = 0; i < 4; i++)
      List_Read(s->Generatrices, i, &C[i]);

    double U, V;    
    if ((C[0]->beg == v && C[3]->beg == v) ||
        (C[0]->end == v && C[3]->beg == v) ||
        (C[0]->beg == v && C[3]->end == v) ||
        (C[0]->end == v && C[3]->end == v)){
      U = V = 0;
    }
    else if ((C[0]->beg == v && C[1]->beg == v) ||
             (C[0]->end == v && C[1]->beg == v) ||
             (C[0]->beg == v && C[1]->end == v) ||
             (C[0]->end == v && C[1]->end == v)){
      U = 1;
      V = 0;
    }
    else if ((C[2]->beg == v && C[1]->beg == v) ||
             (C[2]->end == v && C[1]->beg == v) ||
             (C[2]->beg == v && C[1]->end == v) ||
             (C[2]->end == v && C[1]->end == v)){
      U = 1;
      V = 1;
    }
    else if ((C[2]->beg == v && C[3]->beg == v) ||
             (C[2]->end == v && C[3]->beg == v) ||
             (C[2]->beg == v && C[3]->end == v) ||
             (C[2]->end == v && C[3]->end == v)){
      U = 0;
      V = 1;
    }
    else{
      Msg(INFO, "Reparameterizing point %d on face %d", v->Num, s->Num);
      return GVertex::reparamOnFace(face, dir);
    }
    return SPoint2(U, V);
  }
  else{
    return GVertex::reparamOnFace(face, dir);
  }
}

GEntity::GeomType gmshVertex::geomType() const
{
  if(v->Typ == MSH_POINT_BND_LAYER)
    return BoundaryLayerPoint;
  else
    return Point;
}
