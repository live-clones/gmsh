// $Id: CutMap.cpp,v 1.29 2003-03-01 22:36:43 geuzaine Exp $
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

#include "CutMap.h"
#include "List.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber CutMapOptions_Number[] = {
  {GMSH_FULLRC, "A", NULL, 1.},
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "iField", NULL, 0.}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMapPlugin()
  {
    return new GMSH_CutMapPlugin();
  }
}


GMSH_CutMapPlugin::GMSH_CutMapPlugin()
{
  ;
}

void GMSH_CutMapPlugin::getName(char *name) const
{
  strcpy(name, "Cut map");
}

void GMSH_CutMapPlugin::getInfos(char *author, char *copyright,
                                 char *help_text) const
{
  strcpy(author, "J.-F. Remacle (remacle@scorec.rpi.edu)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Extracts the isovalue surface of value A from a\n"
         "3D scalar map and draw ith component of the field on the iso.\n"
         "Script name: Plugin(CutMap).");
}

int GMSH_CutMapPlugin::getNbOptions() const
{
  return sizeof(CutMapOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutMapPlugin::GetOption(int iopt)
{
  return &CutMapOptions_Number[iopt];
}

void GMSH_CutMapPlugin::CatchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "CutMap failed...");
}

double GMSH_CutMapPlugin::levelset(double x, double y, double z, double val) const
{
  // we must look into the map for A - Map(x,y,z)
  // this is the case when the map is the same as the view,
  // the result is the extraction of isovalue A
  return CutMapOptions_Number[0].def - val;
}

Post_View *GMSH_CutMapPlugin::execute(Post_View * v)
{
  Post_View *vv;

  int iView = (int)CutMapOptions_Number[1].def;
  _ith_field_to_draw_on_the_iso = (int)CutMapOptions_Number[2].def;
  _orientation = ORIENT_MAP;

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
