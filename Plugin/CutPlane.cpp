// $Id: CutPlane.cpp,v 1.38 2004-11-25 02:10:40 geuzaine Exp $
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

#include "CutPlane.h"
#include "List.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#endif

extern Context_T CTX;

int GMSH_CutPlanePlugin::iview = 0;

StringXNumber CutPlaneOptions_Number[] = {
  {GMSH_FULLRC, "A", GMSH_CutPlanePlugin::callbackA, 1.},
  {GMSH_FULLRC, "B", GMSH_CutPlanePlugin::callbackB, 0.},
  {GMSH_FULLRC, "C", GMSH_CutPlanePlugin::callbackC, 0.},
  {GMSH_FULLRC, "D", GMSH_CutPlanePlugin::callbackD, -0.01},
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "recurLevel", NULL, 4}
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

void GMSH_CutPlanePlugin::draw()
{
#if defined(HAVE_FLTK)
  int num = (int)CutPlaneOptions_Number[4].def;
  if(num < 0) num = iview;
  Post_View **vv = (Post_View **)List_Pointer_Test(CTX.post.list, num);
  if(!vv) return;
  Draw_PlaneInBoundingBox((*vv)->BBox[0], (*vv)->BBox[2], (*vv)->BBox[4],
			  (*vv)->BBox[1], (*vv)->BBox[3], (*vv)->BBox[5],
			  CutPlaneOptions_Number[0].def,
			  CutPlaneOptions_Number[1].def,
			  CutPlaneOptions_Number[2].def,
			  CutPlaneOptions_Number[3].def);
#endif
}

void GMSH_CutPlanePlugin::callback()
{
#if defined(HAVE_FLTK)
  CTX.post.plugin_draw_function = draw;
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }
  if(!CTX.batch) 
    Draw();
  CTX.post.plugin_draw_function = NULL;
  CTX.draw_bbox = old;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
#endif
}

double GMSH_CutPlanePlugin::callbackA(int num, int action, double value)
{
  if(action > 0) iview = num;
  switch(action){ // configure the input field
  case 1: return 0.01;
  case 2: return -1.;
  case 3: return 1.;
  default: break;
  }
  CutPlaneOptions_Number[0].def = value;
  callback();
  return 0.;
}

double GMSH_CutPlanePlugin::callbackB(int num, int action, double value)
{
  if(action > 0) iview = num;
  switch(action){
  case 1: return 0.01;
  case 2: return -1.;
  case 3: return 1.;
  default: break;
  }
  CutPlaneOptions_Number[1].def = value;
  callback();
  return 0.;
}

double GMSH_CutPlanePlugin::callbackC(int num, int action, double value)
{
  if(action > 0) iview = num;
  switch(action){
  case 1: return 0.01;
  case 2: return -1.;
  case 3: return 1.;
  default: break;
  }
  CutPlaneOptions_Number[2].def = value;
  callback();
  return 0.;
}

double GMSH_CutPlanePlugin::callbackD(int num, int action, double value)
{
  if(action > 0) iview = num;
  switch(action){
  case 1: return CTX.lc/200.;
  case 2: return -CTX.lc;
  case 3: return CTX.lc;
  default: break;
  }
  CutPlaneOptions_Number[3].def = value;
  callback();
  return 0.;
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
         "Plugin(CutPlane) cuts the view `iView' with\n"
	 "the plane `A'*X + `B'*Y + `C'*Z + `D' = 0. If\n"
	 "`iView' < 0, the plugin is run on the current\n"
	 "view.\n"
	 "\n"
	 "Plugin(CutPlane) creates one new view.\n");
}

int GMSH_CutPlanePlugin::getNbOptions() const
{
  return sizeof(CutPlaneOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_CutPlanePlugin::getOption(int iopt)
{
  return &CutPlaneOptions_Number[iopt];
}

void GMSH_CutPlanePlugin::catchErrorMessage(char *errorMessage) const
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
  int iView = (int)CutPlaneOptions_Number[4].def;
  _ref[0] = CutPlaneOptions_Number[0].def;
  _ref[1] = CutPlaneOptions_Number[1].def;
  _ref[2] = CutPlaneOptions_Number[2].def;
  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::PLANE;
  _recurLevel = (int)CutPlaneOptions_Number[5].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  return GMSH_LevelsetPlugin::execute(v1);
}
