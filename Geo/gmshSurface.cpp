// $Id: gmshSurface.cpp,v 1.3 2007-02-02 17:16:46 remacle Exp $
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

SPoint3  gmshSphere::point       (double par1, double par2) const 
{
  par2+= M_PI*.5;
  const double x = xc + r * sin ( par2 ) * cos ( par1 ); 
  const double y = yc + r * sin ( par2 ) * sin ( par1 ); 
  const double z = zc - r * cos ( par2 ); 
  //    printf("%g %g - %g %g %g\n",par1,par2,x,y,z);
  return SPoint3 (x,y,z);
}
