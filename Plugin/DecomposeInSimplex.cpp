// $Id: DecomposeInSimplex.cpp,v 1.2 2003-11-14 21:20:55 geuzaine Exp $
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

StringXNumber *GMSH_DecomposeInSimplexPlugin::GetOption(int iopt)
{
  return &DecomposeInSimplexOptions_Number[iopt];
}

void GMSH_DecomposeInSimplexPlugin::CatchErrorMessage(char *errorMessage) const
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

void GMSH_DecomposeInSimplexPlugin::Run()
{
  execute(0);
}

void GMSH_DecomposeInSimplexPlugin::Save()
{
  ;
}
