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
