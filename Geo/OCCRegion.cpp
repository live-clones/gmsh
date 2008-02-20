// $Id: OCCRegion.cpp,v 1.9 2008-02-20 09:20:45 geuzaine Exp $
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

#include "GModel.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"
#include "Message.h"

#if defined(HAVE_OCC)

OCCRegion::OCCRegion(GModel *m, TopoDS_Solid _s, int num, TopTools_IndexedMapOfShape &fmap)
  : GRegion(m, num), s(_s)
{
  TopExp_Explorer exp0, exp01, exp1, exp2, exp3;
  for(exp2.Init(s, TopAbs_SHELL); exp2.More(); exp2.Next()){
    TopoDS_Shape shell = exp2.Current();
    Msg(INFO,"OCC Region %d - New Shell",num);
    for(exp3.Init(shell, TopAbs_FACE); exp3.More(); exp3.Next()){	  
      TopoDS_Face face = TopoDS::Face(exp3.Current());
      int index = fmap.FindIndex(face);
      GFace *f = m->getFace(index);
      if(!f) throw;
      l_faces.push_back(f);
      f->addRegion(this);
    }      
  }
  Msg(INFO, "OCC Region %d with %d edges", num, l_faces.size());
}

GEntity::GeomType OCCRegion::geomType() const
{
  return Unknown;
}

#endif
