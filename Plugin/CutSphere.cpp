// $Id: CutSphere.cpp,v 1.28 2003-11-22 18:45:40 geuzaine Exp $
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

#include <string.h>
#include "CutSphere.h"
#include "List.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber CutSphereOptions_Number[] = {
  {GMSH_FULLRC, "Xc", NULL, 0.},
  {GMSH_FULLRC, "Yc", NULL, 0.},
  {GMSH_FULLRC, "Zc", NULL, 0.},
  {GMSH_FULLRC, "R", NULL, 0.25},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin()
  {
    return new GMSH_CutSpherePlugin();
  }
}


GMSH_CutSpherePlugin::GMSH_CutSpherePlugin()
{
  ;
}

void GMSH_CutSpherePlugin::getName(char *name) const
{
  strcpy(name, "Cut sphere");
}

void GMSH_CutSpherePlugin::getInfos(char *author, char *copyright,
                                    char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(CutSphere) cuts the view 'iView' with the\n"
	 "sphere (X-'Xc')^2 + (Y-'Yc')^2 + (Z-'Zc')^2 = 'R'^2.\n"
	 "If 'iView' < 0, the plugin is run on the current\n"
	 "view.\n");
}

int GMSH_CutSpherePlugin::getNbOptions() const
{
  return sizeof(CutSphereOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutSpherePlugin::getOption(int iopt)
{
  return &CutSphereOptions_Number[iopt];
}

void GMSH_CutSpherePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutSphere failed...");
}

double GMSH_CutSpherePlugin::levelset(double x, double y, double z,
                                      double val) const
{
  double a = CutSphereOptions_Number[0].def;
  double b = CutSphereOptions_Number[1].def;
  double c = CutSphereOptions_Number[2].def;
  double r = CutSphereOptions_Number[3].def;
  return (x - a) * (x - a) + (y - b) * (y - b) + (z - c) * (z - c) - r * r;
}

Post_View *GMSH_CutSpherePlugin::execute(Post_View * v)
{
  Post_View *vv;

  int iView = (int)CutSphereOptions_Number[4].def;
  _ref[0] = CutSphereOptions_Number[0].def;
  _ref[1] = CutSphereOptions_Number[1].def;
  _ref[2] = CutSphereOptions_Number[2].def;
  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::SPHERE;

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
