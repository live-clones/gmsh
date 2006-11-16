// $Id: OCCVertex.cpp,v 1.2 2006-11-16 18:48:00 geuzaine Exp $
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

double max_surf_curvature ( double x, double y, double z , const GEdge *_myGEdge)
{
  std::list<GFace *> faces = _myGEdge->faces();
  std::list<GFace *>::iterator it =  faces.begin();
  double curv = 0;
  while (it != faces.end())
    {
      SPoint2 par = (*it)->parFromPoint(SPoint3 (x,y,z));
      double cc = (*it)->curvature ( par );
      if (cc < 1.e4) curv = std::max(curv, cc );					
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
	  max_curvature = std::max ( max_surf_curvature (x(), y(), z(), *it) , max_curvature);  
	}
      //      printf("max curvature (%d) = %12.5E lc = %12.5E\n",tag(),max_curvature,prescribedMeshSizeAtVertex());

    }
  return max_curvature;
}
 
#endif
