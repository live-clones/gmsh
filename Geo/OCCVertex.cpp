// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "GModel.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"
#include "MVertex.h"
#include "MElement.h"

#if defined(HAVE_OCC)

OCCVertex::OCCVertex(GModel *m, int num, TopoDS_Vertex _v) 
  : GVertex(m, num), v(_v)
{
  max_curvature = -1;
  gp_Pnt pnt = BRep_Tool::Pnt(v);
  _x = pnt.X();
  _y = pnt.Y();
  _z = pnt.Z();
  mesh_vertices.push_back(new MVertex(x(), y(), z(), this));
  points.push_back(new MPoint(mesh_vertices.back()));
}

void OCCVertex::setPosition(GPoint &p)
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

double max_surf_curvature(const GVertex *gv, double x, double y, double z, 
                          const GEdge *_myGEdge)
{
  std::list<GFace *> faces = _myGEdge->faces();
  std::list<GFace *>::iterator it = faces.begin();
  double curv = 1.e-22;
  while(it != faces.end()){
    SPoint2 par = gv->reparamOnFace((*it), 1);
    double cc = (*it)->curvature(par);
    if(cc > 0) curv = std::max(curv, cc);
    ++it;
  }  
  return curv;
}

double OCCVertex::max_curvature_of_surfaces() const
{  
  if(max_curvature < 0){
    for(std::list<GEdge*>::const_iterator it = l_edges.begin(); 
        it != l_edges.end(); ++it){
      max_curvature = std::max(max_surf_curvature(this, x(), y(), z(), *it),
                               max_curvature);
    }
    // printf("max curvature (%d) = %12.5E lc = %12.5E\n",tag(),
    //        max_curvature, prescribedMeshSizeAtVertex());
  }
  return max_curvature;
}

SPoint2 OCCVertex::reparamOnFace(GFace *gf, int dir) const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  while(it != l_edges.end()){
    std::list<GEdge*> l = gf->edges();
    if(std::find(l.begin(), l.end(), *it) != l.end()){
      if((*it)->isSeam(gf)){
        const TopoDS_Face *s = (TopoDS_Face*)gf->getNativePtr();
        const TopoDS_Edge *c = (TopoDS_Edge*)(*it)->getNativePtr();
        double s1,s0;
        Handle(Geom2d_Curve) curve2d = BRep_Tool::CurveOnSurface(*c, *s, s0, s1);
        if((*it)->getBeginVertex() == this)
          return (*it)->reparamOnFace(gf, s0, dir);
        else if((*it)->getEndVertex() == this)
          return (*it)->reparamOnFace(gf, s1, dir);
      }
    }
    ++it;
  }  
  it = l_edges.begin();
  while(it != l_edges.end()){
    std::list<GEdge*> l = gf->edges();
    if(std::find(l.begin(), l.end(), *it) != l.end()){
      const TopoDS_Face *s = (TopoDS_Face*)gf->getNativePtr();
      const TopoDS_Edge *c = (TopoDS_Edge*)(*it)->getNativePtr();
      double s1,s0;
      Handle(Geom2d_Curve) curve2d = BRep_Tool::CurveOnSurface(*c, *s, s0, s1);
      if((*it)->getBeginVertex() == this)
        return (*it)->reparamOnFace(gf, s0, dir);
      else if((*it)->getEndVertex() == this)
        return (*it)->reparamOnFace(gf, s1, dir);
    }
    ++it;
  }

  // normally never here
  return GVertex::reparamOnFace(gf, dir);
}

#endif
