// $Id: Annotate.cpp,v 1.14 2006-01-06 00:34:32 geuzaine Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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

#include <iostream>
#include <vector>
#include "Plugin.h"
#include "Annotate.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "GUI.h"
#include "Draw.h"
#endif

extern Context_T CTX;

StringXNumber AnnotateOptions_Number[] = {
  {GMSH_FULLRC, "X", GMSH_AnnotatePlugin::callbackX, 50.},
  {GMSH_FULLRC, "Y", GMSH_AnnotatePlugin::callbackY, 30.},
  {GMSH_FULLRC, "Z", GMSH_AnnotatePlugin::callbackZ, 0.},
  {GMSH_FULLRC, "3D", GMSH_AnnotatePlugin::callback3D, 0.},
  {GMSH_FULLRC, "FontSize", GMSH_AnnotatePlugin::callbackFontSize, 14.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString AnnotateOptions_String[] = {
  {GMSH_FULLRC, "Text", GMSH_AnnotatePlugin::callbackText, "My Text"},
  {GMSH_FULLRC, "Font", GMSH_AnnotatePlugin::callbackFont, "Helvetica"},
  {GMSH_FULLRC, "Align", GMSH_AnnotatePlugin::callbackAlign, "Left"}
};

extern "C"
{
  GMSH_Plugin *GMSH_RegisterAnnotatePlugin()
  {
    return new GMSH_AnnotatePlugin();
  }
}

GMSH_AnnotatePlugin::GMSH_AnnotatePlugin()
{
  ;
}

static double getStyle()
{
  int fontsize = (int)AnnotateOptions_Number[4].def, font = 0, align = 0;
#if defined(HAVE_FLTK)
  font = GetFontIndex(AnnotateOptions_String[1].def);
  align = GetFontAlign(AnnotateOptions_String[2].def);
#endif
  return (double)((align<<16)|(font<<8)|(fontsize));
}

void GMSH_AnnotatePlugin::draw()
{
#if defined(HAVE_FLTK)
  double X = AnnotateOptions_Number[0].def;
  double Y = AnnotateOptions_Number[1].def;
  double Z = AnnotateOptions_Number[2].def;
  double style = getStyle();

  glColor4ubv((GLubyte *) & CTX.color.fg);
  if(AnnotateOptions_Number[3].def){ // 3D
    glRasterPos3d(X, Y, Z);
    Draw_String(AnnotateOptions_String[0].def, style);
    // draw 10-pixel marker
    double d = 10 * CTX.pixel_equiv_x / CTX.s[0];
    glBegin(GL_LINES);
    glVertex3d(X-d,Y,Z); glVertex3d(X+d,Y,Z);
    glVertex3d(X,Y-d,Z); glVertex3d(X,Y+d,Z);
    glVertex3d(X,Y,Z-d); glVertex3d(X,Y,Z+d);
    glEnd();
  }
  else{
    double modelview[16], projection[16];
    glGetDoublev(GL_PROJECTION_MATRIX, projection);
    glGetDoublev(GL_MODELVIEW_MATRIX, modelview);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho((double)CTX.viewport[0], (double)CTX.viewport[2],
	    (double)CTX.viewport[1], (double)CTX.viewport[3], -1., 1.);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Fix2DCoordinates(&X, &Y);
    glRasterPos2d(X, Y);
    Draw_String(AnnotateOptions_String[0].def, style);
    // draw 10-pixel marker
    glBegin(GL_LINES);
    glVertex2d(X-10,Y); glVertex2d(X+10,Y);
    glVertex2d(X,Y-10); glVertex2d(X,Y+10);
    glEnd();

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixd(projection);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixd(modelview);
  }
#endif
}

double GMSH_AnnotatePlugin::callback(int num, int action, double value, double *opt,
				     double step, double min, double max)
{
  switch(action){ // configure the input field
  case 1: return step;
  case 2: return min;
  case 3: return max;
  default: break;
  }
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return 0.;
}

char *GMSH_AnnotatePlugin::callbackStr(int num, int action, char *value, char **opt)
{
  *opt = value;
#if defined(HAVE_FLTK)
  DrawPlugin(draw);
#endif
  return NULL;
}

double GMSH_AnnotatePlugin::callbackX(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[0].def,
		  dim3 ? CTX.lc/200. : 0.5, 
		  dim3 ? -CTX.lc : -100., 
		  dim3 ? CTX.lc : 100000.);
}

double GMSH_AnnotatePlugin::callbackY(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[1].def,
		  dim3 ? CTX.lc/200. : 0.5, 
		  dim3 ? -CTX.lc : -100., 
		  dim3 ? CTX.lc : 100000.);
}

double GMSH_AnnotatePlugin::callbackZ(int num, int action, double value)
{
  // not perfect: the change will only take place if we reopen the dialog...
  int dim3 = (int)AnnotateOptions_Number[3].def;
  return callback(num, action, value, &AnnotateOptions_Number[2].def,
		  dim3 ? CTX.lc/200. : 0.5, 
		  dim3 ? -CTX.lc : -100., 
		  dim3 ? CTX.lc : 100000.);
}

double GMSH_AnnotatePlugin::callback3D(int num, int action, double value)
{
  return callback(num, action, value, &AnnotateOptions_Number[3].def,
		  1, 0, 1);
}

double GMSH_AnnotatePlugin::callbackFontSize(int num, int action, double value)
{
  return callback(num, action, value, &AnnotateOptions_Number[4].def,
		  1, 5, 100);
}

char *GMSH_AnnotatePlugin::callbackText(int num, int action, char *value)
{
  return callbackStr(num, action, value, &AnnotateOptions_String[0].def);
}

char *GMSH_AnnotatePlugin::callbackFont(int num, int action, char *value)
{
  return callbackStr(num, action, value, &AnnotateOptions_String[1].def);
}

char *GMSH_AnnotatePlugin::callbackAlign(int num, int action, char *value)
{
  return callbackStr(num, action, value, &AnnotateOptions_String[2].def);
}

void GMSH_AnnotatePlugin::getName(char *name) const
{
  strcpy(name, "Annotate");
}

void GMSH_AnnotatePlugin::getInfos(char *author, char *copyright,
				   char *help_text) const
{
  strcpy(author, "C. Geuzaine (geuz@geuz.org)");
  strcpy(copyright, "DGR (www.multiphysics.com)");
  strcpy(help_text,
         "Plugin(Annotate) adds the text string `Text', in\n"
	 "font `Font' and size `FontSize', in the view `iView'.\n"
	 "If `3D' is equal to 1, the plugin inserts the\n"
	 "string in model coordinates at the position\n"
	 "(`X',`Y',`Z'). If `3D' is equal to 0, the plugin\n"
	 "inserts the string in screen coordinates at the\n"
	 "position (`X',`Y'). The string is aligned according\n"
	 "to `Align'. If `iView' < 0, the plugin is run on the\n"
	 "current view.\n"
	 "\n"
	 "Plugin(Annotate) is executed in-place.\n");
}

int GMSH_AnnotatePlugin::getNbOptions() const
{
  return sizeof(AnnotateOptions_Number) / sizeof(StringXNumber);
}

StringXNumber *GMSH_AnnotatePlugin::getOption(int iopt)
{
  return &AnnotateOptions_Number[iopt];
}

int GMSH_AnnotatePlugin::getNbOptionsStr() const
{
  return sizeof(AnnotateOptions_String) / sizeof(StringXString);
}

StringXString *GMSH_AnnotatePlugin::getOptionStr(int iopt)
{
  return &AnnotateOptions_String[iopt];
}

void GMSH_AnnotatePlugin::catchErrorMessage(char *errorMessage) const
{
  strcpy(errorMessage, "Annotate failed...");
}

Post_View *GMSH_AnnotatePlugin::execute(Post_View * v)
{
  double X = AnnotateOptions_Number[0].def;
  double Y = AnnotateOptions_Number[1].def;
  double Z = AnnotateOptions_Number[2].def;
  int dim3 = (int)AnnotateOptions_Number[3].def;
  int iView = (int)AnnotateOptions_Number[5].def;
  char *text = AnnotateOptions_String[0].def;
  double style = getStyle();

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  if(dim3){
    List_Add(v1->T3D, &X);
    List_Add(v1->T3D, &Y);
    List_Add(v1->T3D, &Z);
    List_Add(v1->T3D, &style); 
    double d = List_Nbr(v1->T3C);
    List_Add(v1->T3D, &d); 
    for(int i = 0; i < (int)strlen(text)+1; i++) 
      List_Add(v1->T3C, &text[i]); 
    v1->NbT3++;
  }
  else{
    List_Add(v1->T2D, &X);
    List_Add(v1->T2D, &Y);
    List_Add(v1->T2D, &style); 
    double d = List_Nbr(v1->T2C);
    List_Add(v1->T2D, &d); 
    for(int i = 0; i < (int)strlen(text)+1; i++) 
      List_Add(v1->T2C, &text[i]); 
    v1->NbT2++;
  }

  return v1;
}
