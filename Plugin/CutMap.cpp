// $Id: CutMap.cpp,v 1.40 2004-10-30 15:23:23 geuzaine Exp $
//
// Copyright (C) 1997-2004 C. Geuzaine, J.-F. Remacle
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

#include "CutMap.h"
#include "List.h"
#include "Context.h"

extern Context_T CTX;

StringXNumber CutMapOptions_Number[] = {
  {GMSH_FULLRC, "A", GMSH_CutMapPlugin::callbackA, 1.},
  {GMSH_FULLRC, "dTimeStep", NULL, -1.},
  {GMSH_FULLRC, "dView", NULL, -1.},
  {GMSH_FULLRC, "iView", NULL, -1.}
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

double GMSH_CutMapPlugin::callbackA(int num, int action, double value)
{
  double min = 0., max = 1.;
  if(action > 0){
    int iview = (int)CutMapOptions_Number[3].def;
    if(iview < 0) iview = num;
    Post_View *v = (Post_View*)List_Pointer_Test(CTX.post.list, iview);
    if(v){
      min = v->Min;
      max = v->Max;
    }
  }
  switch(action){ // configure the input field
  case 1: return (min-max)/200.;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  return 0.;
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
         "Plugin(CutMap) extracts the isovalue surface of\n"
         "value `A' from the view `iView' and draws the\n"
	 "`dTimeStep'-th value of the view `dView' on this\n"
	 "isovalue surface. If `iView' < 0, the plugin is\n"
	 "run on the current view. If `dTimeStep' < 0, the\n"
	 "plugin uses, for each time step in `iView', the\n"
	 "corresponding time step in `dView'. If `dView'\n"
	 "< 0, the plugin uses `iView' as the value source.\n"
	 "\n"
	 "Plugin(CutMap) creates as many views as there are\n"
	 "time steps in `iView'.\n");
}

int GMSH_CutMapPlugin::getNbOptions() const
{
  return sizeof(CutMapOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutMapPlugin::getOption(int iopt)
{
  return &CutMapOptions_Number[iopt];
}

void GMSH_CutMapPlugin::catchErrorMessage(char *errorMessage) const
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
  int iView = (int)CutMapOptions_Number[3].def;
  _valueIndependent = 0;
  _valueView = (int)CutMapOptions_Number[2].def;
  _valueTimeStep = (int)CutMapOptions_Number[1].def;
  _orientation = GMSH_LevelsetPlugin::MAP;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = (Post_View*)List_Pointer(CTX.post.list, iView);

  return GMSH_LevelsetPlugin::execute(v1);
}
