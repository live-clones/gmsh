// $Id: CutPlane.cpp,v 1.27 2003-11-14 21:20:55 geuzaine Exp $
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

#include "CutPlane.h"
#include "List.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber CutPlaneOptions_Number[] = {
  {GMSH_FULLRC, "A", NULL, 1.},
  {GMSH_FULLRC, "B", NULL, 0.},
  {GMSH_FULLRC, "C", NULL, 0.},
  {GMSH_FULLRC, "D", NULL, 0.01},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutPlanePlugin()
  {
    return new GMSH_CutPlanePlugin();
  }
}


GMSH_CutPlanePlugin::GMSH_CutPlanePlugin()
{
  ;
}

void GMSH_CutPlanePlugin::getName(char *name) const
{
  strcpy(name, "Cut plane");
}

void GMSH_CutPlanePlugin::getInfos(char *author, char *copyright,
                                   char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutPlane) cuts the simplectic 3D scalar\n"
	 "view 'iView' with the plane 'A'*X + 'B'*Y + 'C'*Z +\n"
	 "'D' = 0. If 'iView' < 0, the plugin is run on the\n"
	 "current view.\n");
}

int GMSH_CutPlanePlugin::getNbOptions() const
{
  return sizeof(CutPlaneOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutPlanePlugin::GetOption(int iopt)
{
  return &CutPlaneOptions_Number[iopt];
}

void GMSH_CutPlanePlugin::CatchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutPlane failed...");
}

double GMSH_CutPlanePlugin::levelset(double x, double y, double z, double val) const
{
  return CutPlaneOptions_Number[0].def * x +
    CutPlaneOptions_Number[1].def * y +
    CutPlaneOptions_Number[2].def * z + CutPlaneOptions_Number[3].def;
}

Post_View *GMSH_CutPlanePlugin::execute(Post_View * v)
{
  Post_View *vv;

  int iView = (int)CutPlaneOptions_Number[4].def;
  _orientation = ORIENT_PLANE;
  _ref[0] = CutPlaneOptions_Number[0].def;
  _ref[1] = CutPlaneOptions_Number[1].def;
  _ref[2] = CutPlaneOptions_Number[2].def;

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

  return GMSH_LevelsetPlugin::execute(vv);
}
