// $Id: gmshSurface.cpp,v 1.2 2007-02-01 21:05:53 geuzaine Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
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

#include "gmshSurface.h"
#include "Message.h"

std::map<int,gmshSurface*> gmshSurface::allGmshSurfaces;

gmshSurface * gmshSphere :: NewSphere ( int iSphere , double x, double y, double z, double r )
{
  gmshSphere *sph = new gmshSphere ( x,y,z,r );
  
  if (allGmshSurfaces.find(iSphere) != allGmshSurfaces.end())
    {
      Msg(GERROR,"gmshSurface %d already exists",iSphere);
    }

  allGmshSurfaces [iSphere] = sph;
}

gmshSurface * gmshSurface :: surfaceByTag ( int iSurface ) 
{
  std::map<int,gmshSurface*>::iterator it = allGmshSurfaces.find(iSurface);
  if (it == allGmshSurfaces.end())
    {
      Msg(GERROR,"gmshSurface %d does not exist",iSurface);
      return 0;
    }
  return it->second;
}
