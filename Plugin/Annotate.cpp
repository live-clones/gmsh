// $Id: Annotate.cpp,v 1.6 2005-01-17 05:19:59 geuzaine Exp $
//
// Copyright (C) 1997-2005 C. Geuzaine, J.-F. Remacle
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

#include "Plugin.h"
#include "Annotate.h"
#include "List.h"
#include "Views.h"
#include "Context.h"
#include "Numeric.h"

#if defined(HAVE_FLTK)
#include "GmshUI.h"
#include "GUI.h"
#endif

extern Context_T CTX;

StringXNumber AnnotateOptions_Number[] = {
  {GMSH_FULLRC, "X", NULL, 50.},
  {GMSH_FULLRC, "Y", NULL, 30.},
  {GMSH_FULLRC, "Z", NULL, 0.},
  {GMSH_FULLRC, "3D", NULL, 0.},
  {GMSH_FULLRC, "FontSize", NULL, 14.},
  {GMSH_FULLRC, "iView", NULL, -1.}
};

StringXString AnnotateOptions_String[] = {
  {GMSH_FULLRC, "Text", NULL, "My Text"},
  {GMSH_FULLRC, "Font", NULL, "Helvetica"},
  {GMSH_FULLRC, "Align", NULL, "Left"}
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
         "Plugin(Annotate) adds the text string `Text' in\n"
	 "font `Font' and size `FontSize' in the view `iView'.\n"
	 "If `3D' is equal to 1, the plugin inserts the\n"
	 "string in model coordinates at the position\n"
	 "(`X',`Y',`Z'). If `3D' is equal to 0, the plugin\n"
	 "inserts the string in screen coordinates at the\n"
	 "position (`X',`Y'), and aligns it according to\n"
	 "`Align'. If `iView' < 0, the plugin is run on the\n"
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
  int fontsize = (int)AnnotateOptions_Number[4].def;
  int iView = (int)AnnotateOptions_Number[5].def;
  char *text = AnnotateOptions_String[0].def;
  char *fontname = AnnotateOptions_String[1].def;
  char *alignstr =  AnnotateOptions_String[2].def;

  if(iView < 0)
    iView = v ? v->Index : 0;

  if(!List_Pointer_Test(CTX.post.list, iView)) {
    Msg(GERROR, "View[%d] does not exist", iView);
    return v;
  }

  int font = 0, align = 0;
#if defined(HAVE_FLTK)
  font = GetFontIndex(fontname);
  // align only makes sense in screen coordinates at the moment:
  if(!dim3)
    align = GetFontAlign(alignstr);
#endif

  Post_View *v1 = *(Post_View **)List_Pointer(CTX.post.list, iView);

  double style = (double)((align<<16)|(font<<8)|(fontsize));

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
