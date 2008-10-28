// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

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
    Msg::Info("OCC Region %d - New Shell",num);
    for(exp3.Init(shell, TopAbs_FACE); exp3.More(); exp3.Next()){         
      TopoDS_Face face = TopoDS::Face(exp3.Current());
      int index = fmap.FindIndex(face);
      GFace *f = m->getFaceByTag(index);
      if(f){
	l_faces.push_back(f);
	f->addRegion(this);
      }
      else
	Msg::Error("Unknown face %d in region %d", index, num);
    }      
  }
  Msg::Info("OCC Region %d with %d faces", num, l_faces.size());
}

GEntity::GeomType OCCRegion::geomType() const
{
  return Unknown;
}

#endif
