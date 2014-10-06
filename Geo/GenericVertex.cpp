// Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#include "GmshConfig.h"
#include "GModel.h"
#include "MVertex.h"
#include "MPoint.h"
#include "GenericVertex.h"
#include "GenericEdge.h"
#include "GenericFace.h"
#include<algorithm>

//------------------------------------------------------------------------

GenericVertex::ptrfunction_int_vector GenericVertex::VertexXYZ = NULL;

//------------------------------------------------------------------------

GenericVertex::GenericVertex(GModel *m, int num, int _native_id):GVertex(m, num), id(_native_id){
  if (!VertexXYZ)
    Msg::Fatal("GenericVertex::ERROR: Callback not set");

  vector<double> vec(3,0.);
  bool ok = VertexXYZ(id,vec);
  if (!ok) Msg::Error("GenericVertex::ERROR from callback VertexXYZ ");
  _x=vec[0];
  _y=vec[1];
  _z=vec[2];
}

//------------------------------------------------------------------------

GenericVertex::~GenericVertex(){
}

//------------------------------------------------------------------------

SPoint2 GenericVertex::reparamOnFace(const GFace *gf, int dir) const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  //      // TODO: isSeam not ready yet !!!
  //  while(it != l_edges.end()){
  //    std::list<GEdge*> l = gf->edges();
  //    if(std::find(l.begin(), l.end(), *it) != l.end()){
  //      if((*it)->isSeam(gf)){
  //        const TopoDS_Face *s = (TopoDS_Face*)gf->getNativePtr();
  //        const TopoDS_Edge *c = (TopoDS_Edge*)(*it)->getNativePtr();
  //        double s1,s0;
  //        Handle(Geom2d_Curve) curve2d = BRep_Tool::CurveOnSurface(*c, *s, s0, s1);
  //        if((*it)->getBeginVertex() == this)
  //          return (*it)->reparamOnFace(gf, s0, dir);
  //        else if((*it)->getEndVertex() == this)
  //          return (*it)->reparamOnFace(gf, s1, dir);
  //      }
  //    }
  //    ++it;
  //  }
  it = l_edges.begin();
  while(it != l_edges.end()){
    std::list<GEdge*> l = gf->edges();
    if(std::find(l.begin(), l.end(), *it) != l.end()){
      // the vertex belongs to an edge, which belongs to a face -> just find if begin or end vertex and edge->reparamOnFace(begin or end param)
      Range<double> vec = (*it)->parBounds(0);
      if((*it)->getBeginVertex() == this)
        return (*it)->reparamOnFace(gf, vec.low(), dir);
      else if((*it)->getEndVertex() == this)
        return (*it)->reparamOnFace(gf, vec.high(), dir);
    }
    ++it;
  }

  // normally never here
  return GVertex::reparamOnFace(gf, dir);
}

//------------------------------------------------------------------------

void GenericVertex::setPosition(GPoint &p)
{
  _x = p.x();
  _y = p.y();
  _z = p.z();
  if(mesh_vertices.size()){
    mesh_vertices[0]->x() = p.x();
    mesh_vertices[0]->y() = p.y();
    mesh_vertices[0]->z() = p.z();
  }
}

//------------------------------------------------------------------------
