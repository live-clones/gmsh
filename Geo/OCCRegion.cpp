// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "OCCRegion.h"

#if defined(HAVE_OCC)
#include "GModelIO_OCC.h"

OCCRegion::OCCRegion(GModel *m, TopoDS_Solid _s, int num)
  : GRegion(m, num), s(_s)
{
  setup();
  model()->getOCCInternals()->bind(s, num);
}

OCCRegion::~OCCRegion()
{
  model()->getOCCInternals()->unbind(s, tag());
}

void OCCRegion::setup()
{
  l_faces.clear();
  TopExp_Explorer exp2, exp3;
  for(exp2.Init(s, TopAbs_SHELL); exp2.More(); exp2.Next()){
    TopoDS_Shape shell = exp2.Current();
    Msg::Debug("OCC Region %d - New Shell",tag());
    for(exp3.Init(shell, TopAbs_FACE); exp3.More(); exp3.Next()){
      TopoDS_Face face = TopoDS::Face(exp3.Current());
      GFace *f = model()->getOCCInternals()->getOCCFaceByNativePtr(model(),face);
      if(!f){
        Msg::Error("Unknown face in region %d", tag());
      }
      else if (face.Orientation() == TopAbs_INTERNAL){
        Msg::Info("Adding embedded face %d", f->tag());
        embedded_faces.push_back(f);
      }
      else{
        l_faces.push_back(f);
        f->addRegion(this);
      }
    }
  }

  for (exp3.Init(s, TopAbs_EDGE); exp3.More(); exp3.Next()){
    TopoDS_Edge edge = TopoDS::Edge(exp3.Current());
    GEdge *e = model()->getOCCInternals()->getOCCEdgeByNativePtr(model(), edge);
    if (!e){
      Msg::Error("Unknown edge in region %d", tag());
    }
    else if (edge.Orientation() == TopAbs_INTERNAL){
      Msg::Info("Adding embedded edge %d", e->tag());
      embedded_edges.push_back(e);
      //OCCEdge *occe = (OCCEdge*)e;
      //occe->setTrimmed(this);
    }
  }

  for (exp3.Init(s, TopAbs_VERTEX); exp3.More(); exp3.Next()){
    TopoDS_Vertex vertex = TopoDS::Vertex(exp3.Current());
    GVertex *v = model()->getOCCInternals()->getOCCVertexByNativePtr(model(), vertex);
    if (!v){
      Msg::Error("Unknown vertex in region %d", tag());
    }
    else if (vertex.Orientation() == TopAbs_INTERNAL){
      Msg::Info("Adding embedded vertex %d", v->tag());
      embedded_vertices.push_back(v);
    }
  }

  Msg::Debug("OCC Region %d with %d faces", tag(), l_faces.size());
}

SBoundingBox3d OCCRegion::bounds() const
{
  Bnd_Box b;
  BRepBndLib::Add(s, b);
  double xmin, ymin, zmin, xmax, ymax, zmax;
  b.Get(xmin, ymin, zmin, xmax, ymax, zmax);
  SBoundingBox3d bbox(xmin, ymin, zmin, xmax, ymax, zmax);
  return bbox;
}

GEntity::GeomType OCCRegion::geomType() const
{
  return Unknown;
}

bool FaceHaveDifferentOrientations(const TopoDS_Face& aFR,
				   const TopoDS_Face& aF)
{
  // FIXME !!!
  return false;
}

void OCCRegion::replaceFacesInternal(std::list<GFace*> &new_faces)
{
  // we simply replace old faces by new faces in the structure
  TopExp_Explorer aExpS, aExpF;
  BRep_Builder aBB;
  TopoDS_Compound aCmp;
  aBB.MakeCompound(aCmp);
  TopoDS_Solid _s_replacement;
  aBB.MakeSolid(_s_replacement);
  _s_replacement.Orientation(s.Orientation());
  aExpS.Init(s, TopAbs_SHELL);
  for (; aExpS.More(); aExpS.Next()) {
    const TopoDS_Shell& _shell=TopoDS::Shell(aExpS.Current());
    TopoDS_Shell _shell_replacement;
    aBB.MakeShell(_shell_replacement);
    _shell_replacement.Orientation(_shell.Orientation());
    aExpF.Init(_shell, TopAbs_FACE);
    for (; aExpF.More(); aExpF.Next()) {
      const TopoDS_Face& _face=TopoDS::Face(aExpF.Current());
      TopoDS_Face _face_replacement;

      std::list<GFace*>::iterator it  = l_faces.begin();
      std::list<GFace*>::iterator it2 = new_faces.begin();

      for ( ; it != l_faces.end() ; ++it,++it2){
	OCCFace *occF = dynamic_cast<OCCFace*>(*it);
	if (occF){
	  TopoDS_Face oldf = occF->getTopoDS_Face();
	  if (oldf.IsSame(_face)){
	    _face_replacement = *((TopoDS_Face*)(*it2)->getNativePtr());
	  }
	  else {
	    oldf = occF->getTopoDS_FaceOld();
	    if (oldf.IsSame(_face)){
	      _face_replacement = *((TopoDS_Face*)(*it2)->getNativePtr());
	    }
	  }
	}
      }
      if (_face_replacement.IsNull()){
	Msg::Error("cannot find an face for gluing a region");
      }

      if (_face_replacement.IsSame(_face)) {
	aBB.Add(_shell_replacement, _face);
      }
      else {
	if(FaceHaveDifferentOrientations(_face, _face_replacement))
          _face_replacement.Reverse();
	aBB.Add(_shell_replacement, _face_replacement);
      }
    }
    aBB.Add(_s_replacement, _shell_replacement);
  }
  s = _s_replacement;
  setup();
}

#endif
