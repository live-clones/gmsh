// $Id: Smooth.cpp,v 1.11 2003-01-23 20:19:26 geuzaine Exp $
//
// Copyright (C) 1997 - 2003 C. Geuzaine, J.-F. Remacle
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
#include "Smooth.h"
#include "List.h"
#include "Views.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber SmoothOptions_Number[] = {
  { GMSH_FULLRC, "iView" , NULL , -1. }
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSmoothPlugin ()
  {
    return new GMSH_SmoothPlugin();
  }
}


GMSH_SmoothPlugin::GMSH_SmoothPlugin()
{
}

void GMSH_SmoothPlugin::getName(char *name) const
{
  strcpy(name,"Smooth");
}

void GMSH_SmoothPlugin::getInfos(char *author, char *copyright, char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text, 
	 "Smoothes a discontinuous view by averaging all the values at each node.\n"
	 "Script name: Plugin(Smooth).");
}

int GMSH_SmoothPlugin::getNbOptions() const
{
  return sizeof(SmoothOptions_Number)/sizeof(StringXNumber);
}

StringXNumber *GMSH_SmoothPlugin:: GetOption (int iopt)
{
  return &SmoothOptions_Number[iopt];
}

void GMSH_SmoothPlugin::CatchErrorMessage (char *errorMessage) const
{
  strcpy(errorMessage,"Smooth failed...");
}

Post_View *GMSH_SmoothPlugin::execute (Post_View *v)
{
  Post_View *vv;
  int iView = (int)SmoothOptions_Number[0].def;

  if(v && iView < 0)
    vv = v;
  else{
    if(!v && iView < 0) iView = 0;
    if(!(vv = (Post_View*)List_Pointer_Test(CTX.post.list,iView))){
      Msg(WARNING,"View[%d] does not exist",iView);
      return 0;
    }
  }

  vv->smooth();
  return vv;
}

void GMSH_SmoothPlugin::Run ()
{
  execute(0);
}

void GMSH_SmoothPlugin::Save ()
{
}
