// $Id: OCCVertex.cpp,v 1.4 2006-11-20 12:44:09 remacle Exp $
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

#include "GModel.h"
#include "OCCVertex.h"
#include "OCCEdge.h"
#include "OCCFace.h"

#if defined(HAVE_OCC)

double max_surf_curvature ( const GVertex *gv, double x, double y, double z , const GEdge *_myGEdge)
{
  std::list<GFace *> faces = _myGEdge->faces();
  std::list<GFace *>::iterator it =  faces.begin();
  double curv = 0;
  while (it != faces.end())
    {
      SPoint2 par = gv->reparamOnFace((*it),1);
      double cc = (*it)->curvature ( par );
      if (cc < 1.e2) curv = std::max(curv, cc );					
      ++it;
    }  
  return curv;
}

double OCCVertex::max_curvature_of_surfaces() const
{  
  if (max_curvature <0)
    {
      for (std::list<GEdge*> :: const_iterator it = l_edges.begin() ; it != l_edges.end() ; ++it )
	{
	  max_curvature = std::max ( max_surf_curvature (this, x(), y(), z(), *it) , max_curvature);  
	}
      //      printf("max curvature (%d) = %12.5E lc = %12.5E\n",tag(),max_curvature,prescribedMeshSizeAtVertex());

    }
  return max_curvature;
}

SPoint2 OCCVertex::reparamOnFace ( GFace *gf , int dir) const
{
  std::list<GEdge*>::const_iterator it = l_edges.begin();
  while (it != l_edges.end())
    {
      std::list<GEdge*> l_edges = gf->edges();
      if (std::find(l_edges.begin(),l_edges.end(),*it) != l_edges.end())
	{
	  if ((*it)->isSeam(gf))
	    {
	      const TopoDS_Face *s = (TopoDS_Face*) gf->getNativePtr();
	      const TopoDS_Edge *c = (TopoDS_Edge*) (*it)->getNativePtr();
	      double s1,s0;
	      Handle(Geom2d_Curve) curve2d = BRep_Tool::CurveOnSurface(*c, *s, s0, s1);
	      if ((*it)->getBeginVertex() == this)
		return (*it)->reparamOnFace(gf,s0,dir);
	      else if ((*it)->getEndVertex() == this)
		return (*it)->reparamOnFace(gf,s1,dir);
	    }
	}
      ++it;
    }  
  it = l_edges.begin();
  while (it != l_edges.end())
    {
      std::list<GEdge*> l_edges = gf->edges();
      if (std::find(l_edges.begin(),l_edges.end(),*it) != l_edges.end())
	{
	  const TopoDS_Face *s = (TopoDS_Face*) gf->getNativePtr();
	  const TopoDS_Edge *c = (TopoDS_Edge*) (*it)->getNativePtr();
	  double s1,s0;
	  Handle(Geom2d_Curve) curve2d = BRep_Tool::CurveOnSurface(*c, *s, s0, s1);
	  if ((*it)->getBeginVertex() == this)
	    return (*it)->reparamOnFace(gf,s0,dir);
	  else if ((*it)->getEndVertex() == this)
	    return (*it)->reparamOnFace(gf,s1,dir);
	}
      ++it;
    }
}

#endif
