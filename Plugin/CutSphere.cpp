// $Id: CutSphere.cpp,v 1.36 2004-11-25 02:10:40 geuzaine Exp $
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

#include <string.h>
#include "CutSphere.h"
#include "List.h"
#include "Context.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "Draw.h"
#endif

extern Context_T CTX;

StringXNumber CutSphereOptions_Number[] = {
  {GMSH_FULLRC, "Xc", GMSH_CutSpherePlugin::callbackX, 0.},
  {GMSH_FULLRC, "Yc", GMSH_CutSpherePlugin::callbackY, 0.},
  {GMSH_FULLRC, "Zc", GMSH_CutSpherePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "R", GMSH_CutSpherePlugin::callbackR, 0.25},
  {GMSH_FULLRC, "iView", NULL, -1.},
  {GMSH_FULLRC, "recurLevel", NULL, 4}
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

void GMSH_CutSpherePlugin::draw()
{
#if defined(HAVE_FLTK)
  static GLUquadricObj *qua;
  static int first = 1;
  if(first) {
    first = 0;
    qua = gluNewQuadric();
  }
  GLint mode[2];
  glGetIntegerv(GL_POLYGON_MODE, mode);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
  glPushMatrix();
  glColor4ubv((GLubyte *) & CTX.color.fg);
  glTranslated(CutSphereOptions_Number[0].def,
	       CutSphereOptions_Number[1].def,
	       CutSphereOptions_Number[2].def);
  gluSphere(qua, CutSphereOptions_Number[3].def, 40, 40);
  glPopMatrix();
  glPolygonMode(GL_FRONT_AND_BACK, mode[1]);
#endif
}

void GMSH_CutSpherePlugin::callback()
{
#if defined(HAVE_FLTK)
  CTX.post.plugin_draw_function = draw;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }
  if(!CTX.batch) 
    Draw();
  CTX.post.plugin_draw_function = NULL;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
#endif
}

double GMSH_CutSpherePlugin::callbackX(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return CTX.lc/200.;
  case 2: return -CTX.lc;
  case 3: return CTX.lc;
  default: break;
  }
  CutSphereOptions_Number[0].def = value;
  callback();
  return 0.;
}

double GMSH_CutSpherePlugin::callbackY(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return CTX.lc/200.;
  case 2: return -CTX.lc;
  case 3: return CTX.lc;
  default: break;
  }
  CutSphereOptions_Number[1].def = value;
  callback();
  return 0.;
}

double GMSH_CutSpherePlugin::callbackZ(int num, int action, double value)
{
  switch(action){ // configure the input field
  case 1: return CTX.lc/200.;
  case 2: return -CTX.lc;
  case 3: return CTX.lc;
  default: break;
  }
  CutSphereOptions_Number[2].def = value;
  callback();
  return 0.;
}

double GMSH_CutSpherePlugin::callbackR(int num, int action, double value)
{
  switch(action){
  case 1: return CTX.lc/200.;
  case 2: return 0.;
  case 3: return 2*CTX.lc;
  default: break;
  }
  CutSphereOptions_Number[3].def = value;
  callback();
  return 0.;
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
         "Plugin(CutSphere) cuts the view `iView' with the\n"
	 "sphere (X-`Xc')^2 + (Y-`Yc')^2 + (Z-`Zc')^2 = `R'^2.\n"
	 "If `iView' < 0, the plugin is run on the current\n"
	 "view.\n"
	 "\n"
	 "Plugin(CutSphere) creates one new view.\n");
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
  int iView = (int)CutSphereOptions_Number[4].def;
  _ref[0] = CutSphereOptions_Number[0].def;
  _ref[1] = CutSphereOptions_Number[1].def;
  _ref[2] = CutSphereOptions_Number[2].def;
  _recurLevel = (int)CutSphereOptions_Number[5].def;

  _valueIndependent = 1;
  _valueView = -1;
  _valueTimeStep = -1;
  _orientation = GMSH_LevelsetPlugin::SPHERE;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  return GMSH_LevelsetPlugin::execute(v1);
}
