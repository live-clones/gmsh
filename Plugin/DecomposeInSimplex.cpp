// $Id: DecomposeInSimplex.cpp,v 1.4 2003-11-22 01:45:48 geuzaine Exp $
//
// Copyright (C) 1997-2003 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

#include "Plugin.h"
#include "DecomposeInSimplex.h"
#include "List.h"
#include "Tree.h"
#include "Views.h"
#include "Context.h"
#include "Malloc.h"

extern Context_T CTX;

StringXNumber DecomposeInSimplexOptions_Number[] = {
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterDecomposeInSimplexPlugin()
  {
    return new GMSH_DecomposeInSimplexPlugin();
  }
}

GMSH_DecomposeInSimplexPlugin::GMSH_DecomposeInSimplexPlugin()
{
  ;
}

void GMSH_DecomposeInSimplexPlugin::getName(char *name) const
{
  strcpy(name, "DecomposeInSimplex");
}

void GMSH_DecomposeInSimplexPlugin::getInfos(char *author, char *copyright,
					     char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(DecomposeInSimplex) decomposes any non-\n"
	 "simplectic element in the view 'iView' into\n"
	 "simplices. If 'iView' < 0, the plugin is run on\n"
	 "the current view.\n");
}

int GMSH_DecomposeInSimplexPlugin::getNbOptions() const
{
  return sizeof(DecomposeInSimplexOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_DecomposeInSimplexPlugin::getOption(int iopt)
{
  return &DecomposeInSimplexOptions_Number[iopt];
}

void GMSH_DecomposeInSimplexPlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "DecomposeInSimplex failed...");
}

Post_View *GMSH_DecomposeInSimplexPlugin::execute(Post_View * v)
{
  Post_View *vv;

  int iView = (int)DecomposeInSimplexOptions_Number[0].def;

  if(v && iView < 0)
    vv = v;
  else {
    if(!v && iView < 0)
      iView = 0;
    if(!(vv = (Post_View *) List_Pointer_Test(CTX.post.list, iView))) {
      Msg(WARNING, "View[%d] does not exist", iView);
      return 0;
    }
  }

  if(vv->NbSQ || vv->NbVQ || vv->NbTQ) { // quad
  }

  if(vv->NbSH || vv->NbVH || vv->NbTH) { // hexa
  }

  if(vv->NbSI || vv->NbVI || vv->NbTI) { // prism
  }

  if(vv->NbSY || vv->NbVY || vv->NbTY) { // pyram
  }

  return 0;
}

// Utility class 

int DecomposeInSimplex::numSimplices()
{
  switch(_numNodes) {
  case 4: return 2; // quad -> 2 tris
  case 5: return 2; // pyramid -> 2 tets
  case 6: return 3; // prism -> 3 tets
  case 8: return 6; // hexa -> 6 tets
  }
  return 0;
}

int DecomposeInSimplex::numSimplexNodes()
{
  if(_numNodes == 4)
    return 3; // quad -> tris
  else
    return 4; // all others -> tets
}

void DecomposeInSimplex::reorder(int map[4], int n,
				 double *x, double *y, double *z, double *val,
				 double *xn, double *yn, double *zn, double *valn)
{
  for(int i = 0; i < n; i++) {
    xn[i] = x[map[i]];
    yn[i] = y[map[i]];
    zn[i] = z[map[i]];
    for(int j = 0; j < _numComponents; j++)
      valn[i*_numComponents+j] = val[map[i]*_numComponents+j];
  }
}

void DecomposeInSimplex::decompose(int num, 
				   double *x, double *y, double *z, double *val,
				   double *xn, double *yn, double *zn, double *valn)
{
  int quadTri[2][4] = {{0,1,2,-1}, {0,2,3,-1}};
  int hexaTet[6][4] = {{0,1,2,5}, {0,2,5,6}, {0,4,5,6}, {0,2,3,6}, {0,4,6,7}, {0,3,6,7}};
  int prisTet[3][4] = {{0,1,2,4}, {0,2,4,5}, {0,3,4,5}};
  int pyraTet[2][4] = {{0,1,3,4}, {1,2,3,4}};

  if(num < 0 || num > numSimplices()-1) {
    Msg(GERROR, "Invalid decomposition");
    num = 0;
  }
    
  switch(_numNodes) {
  case 4: reorder(quadTri[num], 3, x, y, z, val, xn, yn, zn, valn); break ;
  case 8: reorder(hexaTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  case 6: reorder(prisTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  case 5: reorder(pyraTet[num], 4, x, y, z, val, xn, yn, zn, valn); break ;
  }
}
