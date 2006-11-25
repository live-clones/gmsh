// $Id: Options.cpp,v 1.316 2006-11-25 16:52:41 geuzaine Exp $
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

#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshDefines.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"
#include "BackgroundMesh.h"
#include "PluginManager.h"

extern Context_T CTX;

#if defined(HAVE_FLTK)
#include "Solvers.h"
#include "GUI.h"
extern GUI *WID;
extern void activate_cb(Fl_Widget* w, void* data);
#endif

extern Post_View *Post_ViewReference;

// General routines

void Init_Options_Safe(int num)
{
  ColorTable_InitParam(1, &Post_ViewReference->CT);
  ColorTable_Recompute(&Post_ViewReference->CT);

  // Default string options
  Set_DefaultStringOptions(num, GeneralOptions_String);
  Set_DefaultStringOptions(num, GeometryOptions_String);
  Set_DefaultStringOptions(num, MeshOptions_String);
  Set_DefaultStringOptions(num, SolverOptions_String);
  Set_DefaultStringOptions(num, PostProcessingOptions_String);
  Set_DefaultStringOptions(num, ViewOptions_String);
  Set_DefaultStringOptions(num, PrintOptions_String);

  // Default number options
  Set_DefaultNumberOptions(num, GeneralOptions_Number);
  Set_DefaultNumberOptions(num, GeometryOptions_Number);
  Set_DefaultNumberOptions(num, MeshOptions_Number);
  Set_DefaultNumberOptions(num, SolverOptions_Number);
  Set_DefaultNumberOptions(num, PostProcessingOptions_Number);
  Set_DefaultNumberOptions(num, ViewOptions_Number);
  Set_DefaultNumberOptions(num, PrintOptions_Number);

  // Default color options
  Set_DefaultColorOptions(num, GeneralOptions_Color);
  Set_DefaultColorOptions(num, GeometryOptions_Color);
  Set_DefaultColorOptions(num, MeshOptions_Color);
  Set_DefaultColorOptions(num, SolverOptions_Color);
  Set_DefaultColorOptions(num, PostProcessingOptions_Color);
  Set_DefaultColorOptions(num, ViewOptions_Color);
  Set_DefaultColorOptions(num, PrintOptions_Color);
}

char *gmsh_getenv(char *var)
{
#if !defined(WIN32)
  return getenv(var);
#else
  char *tmp = getenv(var);
  // Don't accept top dir or anything partially expanded like
  // c:\Documents and Settings\%USERPROFILE%, etc.
  if(!tmp || !strcmp(tmp, "/") || strstr(tmp, "%") || strstr(tmp, "$"))
    return NULL;
  else
    return tmp;
#endif
}

void Init_Options(int num)
{
  // Is machine big- or little-endian?
  short int word = 0x0001;
  char *byte = (char *) &word;
  CTX.big_endian = (byte[0] ? 0 : 1);

  // Home directory
  char *tmp;
  if((tmp = gmsh_getenv("GMSH_HOME")))
    strcpy(CTX.home_dir, tmp);
  else if((tmp = gmsh_getenv("HOME")))
    strcpy(CTX.home_dir, tmp);
  else if((tmp = gmsh_getenv("TMP")))
    strcpy(CTX.home_dir, tmp);
  else if((tmp = gmsh_getenv("TEMP")))
    strcpy(CTX.home_dir, tmp);
  else
    strcpy(CTX.home_dir, "");
  
  int len = strlen(CTX.home_dir);
  if(len && CTX.home_dir[len-1] != '/')
    strcat(CTX.home_dir, "/");

  // Reference view storing default options
  Post_ViewReference = (Post_View *) Malloc(sizeof(Post_View));

  Init_Options_Safe(num);

  // The following defaults cannot be set by the user 
  CTX.batch = 0;
  CTX.output_filename = NULL;
  CTX.bgm_filename = NULL;
  CTX.files = List_Create(10, 10, sizeof(char*));
  CTX.lc = 1.0;
  CTX.viewport[0] = CTX.viewport[1] = 0;
  CTX.min[0] = CTX.min[1] = CTX.min[2] = 0.0;
  CTX.max[0] = CTX.max[1] = CTX.max[2] = 1.0;
  CTX.cg[0] = CTX.cg[1] = CTX.cg[2] = 0.0;
  CTX.vxmin = CTX.vymin = CTX.vxmax = CTX.vymax = 0.;
  CTX.render_mode = GMSH_RENDER;
  CTX.pixel_equiv_x = CTX.pixel_equiv_y = 0.;
  CTX.polygon_offset = 0;
  CTX.printing = 0;
  CTX.mesh_timer[0] = CTX.mesh_timer[1] = CTX.mesh_timer[2] = 0.;
  CTX.draw_rotation_center = 0;
  CTX.pick_elements = 0;
  CTX.geom.draw = 1;
  CTX.mesh.draw = 1;
  CTX.post.draw = 1;
  CTX.post.list = NULL;
  CTX.post.force_num = 0;
  CTX.threads_lock = 0; // very primitive locking
  CTX.mesh.changed = 0;
  CTX.mesh.oldxtrude = CTX.mesh.oldxtrude_recombine = 0; // old extrusion mesh generator
  CTX.mesh.bgmesh_type = WITHPOINTS;
  CTX.post.combine_time = 0; // try to combine_time views at startup
  CTX.post.plugin_draw_function = NULL;
#if defined(HAVE_FLTK)
  CTX.gl_font_enum = FL_HELVETICA;
#else
  CTX.gl_font_enum = -1;
#endif
  CTX.forced_bbox = 0;
}

void ReInit_Options(int num)
{
  // horrible trick so that the opt_view_XXX will act on the reference view
  List_T *l = CTX.post.list;
  CTX.post.list = NULL; 
  Init_Options_Safe(num);
  CTX.post.list = l;

  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    CopyViewOptions(Post_ViewReference, v);
  }
}

void Init_Options_GUI(int num)
{
  Set_StringOptions_GUI(num, GeneralOptions_String);
  Set_StringOptions_GUI(num, GeometryOptions_String);
  Set_StringOptions_GUI(num, MeshOptions_String);
  Set_StringOptions_GUI(num, SolverOptions_String);
  Set_StringOptions_GUI(num, PostProcessingOptions_String);
  Set_StringOptions_GUI(num, PrintOptions_String);

  Set_NumberOptions_GUI(num, GeneralOptions_Number);
  Set_NumberOptions_GUI(num, GeometryOptions_Number);
  Set_NumberOptions_GUI(num, MeshOptions_Number);
  Set_NumberOptions_GUI(num, SolverOptions_Number);
  Set_NumberOptions_GUI(num, PostProcessingOptions_Number);
  Set_NumberOptions_GUI(num, PrintOptions_Number);

  Set_ColorOptions_GUI(num, GeneralOptions_Color);
  Set_ColorOptions_GUI(num, GeometryOptions_Color);
  Set_ColorOptions_GUI(num, MeshOptions_Color);
  Set_ColorOptions_GUI(num, SolverOptions_Color);
  Set_ColorOptions_GUI(num, PostProcessingOptions_Color);
  Set_ColorOptions_GUI(num, PrintOptions_Color);
}

void Print_OptionCategory(int level, int diff, int help, char *cat, FILE * file)
{
  if(diff || !help || !(level & GMSH_FULLRC))
    return;
  if(file) {
    fprintf(file, "//\n");
    fprintf(file, "// %s\n", cat);
    fprintf(file, "//\n");
  }
  else {
    Msg(DIRECT, "//");
    Msg(DIRECT, "// %s", cat);
    Msg(DIRECT, "//");
  }
}

void Print_Options(int num, int level, int diff, int help, char *filename)
{
  FILE *file;
  char tmp[256];
  int i;

  if(filename) {
    file = fopen(filename, "w");
    if(!file) {
      Msg(GERROR, "Unable to open file '%s'", filename);
      return;
    }
  }
  else
    file = NULL;

  if((level & GMSH_SESSIONRC) && file) {
    fprintf(file, "// Gmsh Session File\n");
    fprintf(file, "//\n");
    fprintf(file, "// This file contains session specific info (that is info\n");
    fprintf(file, "// you want to keep between two Gmsh sessions). You are\n");
    fprintf(file, "// not supposed to edit it manually, but of course you\n");
    fprintf(file, "// can. This file will be entirely rewritten every time\n");
    fprintf(file, "// you quit Gmsh if the option 'General.SaveSession' is\n");
    fprintf(file, "// set.\n");
    fprintf(file, "//\n");
  }

  if((level & GMSH_OPTIONSRC) && file) {
    fprintf(file, "// Gmsh Option File\n");
    fprintf(file, "//\n");
    fprintf(file, "// This file contains configuration options (preferences) that\n");
    fprintf(file, "// are loaded each time Gmsh is launched. You can create this\n");
    fprintf(file, "// file by hand, or let Gmsh generate it for you (with\n");
    fprintf(file, "// 'Tools->Options->Save'). This file can also be automatically\n");
    fprintf(file, "// saved every time you quit Gmsh if the option 'General.SaveOptions'\n");
    fprintf(file, "// is set.\n");
    fprintf(file, "//\n");
  }

  Print_OptionCategory(level, diff, help, "General options (strings)", file);
  Print_StringOptions(num, level, diff, help, GeneralOptions_String, "General.", file);
  Print_OptionCategory(level, diff, help, "General options (numbers)", file);
  Print_NumberOptions(num, level, diff, help, GeneralOptions_Number, "General.", file);
  Print_OptionCategory(level, diff, help, "General options (colors)", file);
  Print_ColorOptions(num, level, diff, help, GeneralOptions_Color, "General.", file);

  Print_OptionCategory(level, diff, help, "Geometry options (strings)", file);
  Print_StringOptions(num, level, diff, help, GeometryOptions_String, "Geometry.", file);
  Print_OptionCategory(level, diff, help, "Geometry options (numbers)", file);
  Print_NumberOptions(num, level, diff, help, GeometryOptions_Number, "Geometry.", file);
  Print_OptionCategory(level, diff, help, "Geometry options (colors)", file);
  Print_ColorOptions(num, level, diff, help, GeometryOptions_Color, "Geometry.", file);

  Print_OptionCategory(level, diff, help, "Mesh options (strings)", file);
  Print_StringOptions(num, level, diff, help, MeshOptions_String, "Mesh.", file);
  Print_OptionCategory(level, diff, help, "Mesh options (numbers)", file);
  Print_NumberOptions(num, level, diff, help, MeshOptions_Number, "Mesh.", file);
  Print_OptionCategory(level, diff, help, "Mesh options (colors)", file);
  Print_ColorOptions(num, level, diff, help, MeshOptions_Color, "Mesh.", file);

  Print_OptionCategory(level, diff, help, "Solver options (strings)", file);
  Print_StringOptions(num, level, diff, help, SolverOptions_String, "Solver.", file);
  Print_OptionCategory(level, diff, help, "Solver options (numbers)", file);
  Print_NumberOptions(num, level, diff, help, SolverOptions_Number, "Solver.", file);
  Print_OptionCategory(level, diff, help, "Solver options (colors)", file);
  Print_ColorOptions(num, level, diff, help, SolverOptions_Color, "Solver.", file);

  Print_OptionCategory(level, diff, help, "Post-processing options (strings)", file);
  Print_StringOptions(num, level, diff, help, PostProcessingOptions_String,
                      "PostProcessing.", file);
  Print_OptionCategory(level, diff, help, "Post-processing options (numbers)", file);
  Print_NumberOptions(num, level, diff, help, PostProcessingOptions_Number,
                      "PostProcessing.", file);
  Print_OptionCategory(level, diff, help, "Post-processing options (colors)", file);
  Print_ColorOptions(num, level, diff, help, PostProcessingOptions_Color,
                     "PostProcessing.", file);

  if(level & GMSH_FULLRC) {
    for(i = 0; i < List_Nbr(CTX.post.list); i++) {
      sprintf(tmp, "View[%d].", i);
      Print_OptionCategory(level, diff, help, "View options (strings)", file);
      Print_StringOptions(i, level, diff, help, ViewOptions_String, tmp, file);
      Print_OptionCategory(level, diff, help, "View options (numbers)", file);
      Print_NumberOptions(i, level, diff, help, ViewOptions_Number, tmp, file);
      Print_OptionCategory(level, diff, help, "View options (colors)", file);
      Print_ColorOptions(i, level, diff, help, ViewOptions_Color, tmp, file);
      strcat(tmp, "ColorTable");
      Print_ColorTable(i, diff, tmp, file);
    }
  }
  else if(level & GMSH_OPTIONSRC) {
    Print_OptionCategory(level, diff, help, "View options (strings)", file);
    Print_StringOptions(num, level, diff, help, ViewOptions_String, "View.", file);
    Print_OptionCategory(level, diff, help, "View options (numbers)", file);
    Print_NumberOptions(num, level, diff, help, ViewOptions_Number, "View.", file);
    Print_OptionCategory(level, diff, help, "View options (colors)", file);
    Print_ColorOptions(num, level, diff, help, ViewOptions_Color, "View.", file);
    Print_ColorTable(num, diff, "View.ColorTable", file);
  }

  Print_OptionCategory(level, diff, help, "Print options (strings)", file);
  Print_StringOptions(num, level, diff, help, PrintOptions_String, "Print.", file);
  Print_OptionCategory(level, diff, help, "Print options (numbers)", file);
  Print_NumberOptions(num, level, diff, help, PrintOptions_Number, "Print.", file);
  Print_OptionCategory(level, diff, help, "Print options (colors)", file);
  Print_ColorOptions(num, level, diff, help, PrintOptions_Color, "Print.", file);

  if(filename) fclose(file);
}

char * Get_OptionSaveLevel(int level){
  if(level & GMSH_SESSIONRC){
    return "General.SessionFileName";
  }
  else if(level & GMSH_OPTIONSRC){
    return "General.OptionsFileName";
  }
  else{
    return "-";
  }
}

void Print_OptionsDoc()
{
  FILE *file;
  char *warn =
    "@c\n"
    "@c This file is generated automatically by running \"gmsh -doc\".\n"
    "@c Do not edit by hand!\n"
    "@c\n\n";
  
  file = fopen("opt_general.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_general.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(GeneralOptions_String, "General.", file);
  Print_NumberOptionsDoc(GeneralOptions_Number, "General.", file);
  Print_ColorOptionsDoc(GeneralOptions_Color, "General.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_print.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_print.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(PrintOptions_String, "Print.", file);
  Print_NumberOptionsDoc(PrintOptions_Number, "Print.", file);
  Print_ColorOptionsDoc(PrintOptions_Color, "Print.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_geometry.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_geometry.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(GeometryOptions_String, "Geometry.", file);
  Print_NumberOptionsDoc(GeometryOptions_Number, "Geometry.", file);
  Print_ColorOptionsDoc(GeometryOptions_Color, "Geometry.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_mesh.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_mesh.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(MeshOptions_String, "Mesh.", file);
  Print_NumberOptionsDoc(MeshOptions_Number, "Mesh.", file);
  Print_ColorOptionsDoc(MeshOptions_Color, "Mesh.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_solver.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_solver.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(SolverOptions_String, "Solver.", file);
  Print_NumberOptionsDoc(SolverOptions_Number, "Solver.", file);
  Print_ColorOptionsDoc(SolverOptions_Color, "Solver.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_post.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_post.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(PostProcessingOptions_String, "PostProcessing.", file);
  Print_NumberOptionsDoc(PostProcessingOptions_Number, "PostProcessing.", file);
  Print_ColorOptionsDoc(PostProcessingOptions_Color, "PostProcessing.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_view.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_view.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  Print_StringOptionsDoc(ViewOptions_String, "View.", file);
  Print_NumberOptionsDoc(ViewOptions_Number, "View.", file);
  Print_ColorOptionsDoc(ViewOptions_Color, "View.", file);
  fprintf(file, "@item View.ColorTable\n");
  fprintf(file, "Color table used to draw the view@*\n");
  fprintf(file, "Saved in: @code{%s}\n\n",
	  Get_OptionSaveLevel(GMSH_FULLRC|GMSH_OPTIONSRC));
  fprintf(file, "@end ftable\n");
  fclose(file);


  file = fopen("opt_plugin.texi", "w");
  if(!file) {
    Msg(GERROR, "Unable to open file 'opt_plugin.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  char author[256], copyright[256], help[4096];
  for(GMSH_PluginManager::iter it = GMSH_PluginManager::instance()->begin();
      it != GMSH_PluginManager::instance()->end(); ++it) {
    GMSH_Plugin *p = (*it).second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
      p->getInfos(author, copyright, help);
      fprintf(file, "@item Plugin(%s)\n", (*it).first);
      fprintf(file, "%s\n", help);

      int m = p->getNbOptionsStr();
      if(m){
	fprintf(file, "String options:\n");
	fprintf(file, "@table @code\n");
	for(int i = 0; i < m; i++) {
	  StringXString *sxs = p->getOptionStr(i);
	  fprintf(file, "@item %s\n", sxs->str);
	  fprintf(file, "Default value: @code{\"%s\"}\n", sxs->def);
	}
	fprintf(file, "@end table\n");
      }

      int n = p->getNbOptions();
      if(n){
	fprintf(file, "Numeric options:\n");
	fprintf(file, "@table @code\n");
	for(int i = 0; i < n; i++) {
	  StringXNumber *sxn = p->getOption(i);
	  fprintf(file, "@item %s\n", sxn->str);
	  fprintf(file, "Default value: @code{%g}\n", sxn->def);
	}
	fprintf(file, "@end table\n");
      }

    }
    fprintf(file, "\n");
  }
  fprintf(file, "@end ftable\n");
  fclose(file);
}

// General routines for string options

StringXString *Get_StringOptionCategory(char *cat)
{
  if(!strcmp(cat, "General"))
    return GeneralOptions_String;
  else if(!strcmp(cat, "Geometry"))
    return GeometryOptions_String;
  else if(!strcmp(cat, "Mesh"))
    return MeshOptions_String;
  else if(!strcmp(cat, "Solver"))
    return SolverOptions_String;
  else if(!strcmp(cat, "PostProcessing"))
    return PostProcessingOptions_String;
  else if(!strcmp(cat, "View"))
    return ViewOptions_String;
  else if(!strcmp(cat, "Print"))
    return PrintOptions_String;
  else
    return NULL;
}

void Set_DefaultStringOptions(int num, StringXString s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_SET, s[i].def);
    i++;
  }
}

void Set_StringOptions_GUI(int num, StringXString s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_GUI, 0);
    i++;
  }
}

void *Get_StringOption(char *str, StringXString s[])
{
  int i = 0;
  while((s[i].str != NULL) && (strcmp(s[i].str, str)))
    i++;
  if(!s[i].str)
    return NULL;
  else
    return (void *)s[i].function;
}

void Print_StringOptions(int num, int level, int diff, int help, 
			 StringXString s[], char *prefix, FILE * file)
{
  int i = 0;
  char tmp[1024];
  while(s[i].str) {
    if(s[i].level & level) {
      if(!diff || strcmp(s[i].function(num, GMSH_GET, NULL), s[i].def)){
	sprintf(tmp, "%s%s = \"%s\";%s%s", prefix,
		s[i].str, s[i].function(num, GMSH_GET, NULL), 
		help ? " // " : "", help ? s[i].help : "");
	if(file)
	  fprintf(file, "%s\n", tmp);
	else
	  Msg(DIRECT, "%s", tmp);
      }
    }
    i++;
  }
}

void Print_StringOptionsDoc(StringXString s[], char *prefix, FILE * file)
{
  int i = 0, j;
  char tmp[1024];

  while(s[i].str) {
    fprintf(file, "@item %s%s\n", prefix, s[i].str);
    fprintf(file, "%s@*\n", s[i].help);

    // sanitize the string for texinfo
    char *ptr = s[i].function(0, GMSH_GET, NULL);
    int len = strlen(ptr);
    j = 0;
    while(j < len){
      tmp[j] = *(ptr++);
      if(j && tmp[j] == '\n' && tmp[j-1] == '\n')
	tmp[j-1] = '.';
      j++;
      if(j == 1023) break;
    }
    tmp[j] = '\0';

    fprintf(file, "Default value: @code{\"%s\"}@*\n", tmp);
    fprintf(file, "Saved in: @code{%s}\n\n", Get_OptionSaveLevel(s[i].level));
    i++;
  }
}

// General routines for numeric options

StringXNumber *Get_NumberOptionCategory(char *cat)
{
  if(!strcmp(cat, "General"))
    return GeneralOptions_Number;
  else if(!strcmp(cat, "Geometry"))
    return GeometryOptions_Number;
  else if(!strcmp(cat, "Mesh"))
    return MeshOptions_Number;
  else if(!strcmp(cat, "Solver"))
    return SolverOptions_Number;
  else if(!strcmp(cat, "PostProcessing"))
    return PostProcessingOptions_Number;
  else if(!strcmp(cat, "View"))
    return ViewOptions_Number;
  else if(!strcmp(cat, "Print"))
    return PrintOptions_Number;
  else
    return NULL;
}

void Set_DefaultNumberOptions(int num, StringXNumber s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_SET, s[i].def);
    i++;
  }
}

void Set_NumberOptions_GUI(int num, StringXNumber s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_GUI, 0);
    i++;
  }
}

void *Get_NumberOption(char *str, StringXNumber s[])
{
  int i = 0;

  while((s[i].str != NULL) && (strcmp(s[i].str, str)))
    i++;
  if(!s[i].str)
    return NULL;
  else {
    return (void *)s[i].function;
  }
}

void Print_NumberOptions(int num, int level, int diff, int help,
			 StringXNumber s[], char *prefix, FILE * file)
{
  int i = 0;
  char tmp[1024];
  while(s[i].str) {
    if(s[i].level & level) {
      if(!diff || (s[i].function(num, GMSH_GET, 0) != s[i].def)){
	sprintf(tmp, "%s%s = %.16g;%s%s", prefix,
		s[i].str, s[i].function(num, GMSH_GET, 0), 
		help ? " // " : "", help ? s[i].help : "");
	if(file)
	  fprintf(file, "%s\n", tmp);
	else
	  Msg(DIRECT, tmp);
      }
    }
    i++;
  }
}

void Print_NumberOptionsDoc(StringXNumber s[], char *prefix, FILE * file)
{
  int i = 0;
  while(s[i].str) {
    fprintf(file, "@item %s%s\n", prefix, s[i].str);
    fprintf(file, "%s@*\n", s[i].help);
    fprintf(file, "Default value: @code{%g}@*\n", s[i].function(0, GMSH_GET, 0));
    fprintf(file, "Saved in: @code{%s}\n\n", Get_OptionSaveLevel(s[i].level));
    i++;
  }
}

// General routines for color options

StringXColor *Get_ColorOptionCategory(char *cat)
{
  if(!strcmp(cat, "General"))
    return GeneralOptions_Color;
  else if(!strcmp(cat, "Geometry"))
    return GeometryOptions_Color;
  else if(!strcmp(cat, "Mesh"))
    return MeshOptions_Color;
  else if(!strcmp(cat, "Solver"))
    return SolverOptions_Color;
  else if(!strcmp(cat, "PostProcessing"))
    return PostProcessingOptions_Color;
  else if(!strcmp(cat, "View"))
    return ViewOptions_Color;
  else if(!strcmp(cat, "Print"))
    return PrintOptions_Color;
  else
    return NULL;
}

void Set_DefaultColorOptions(int num, StringXColor s[])
{
  int i = 0;
  // Warning: this assumes that CTX.color_scheme is set...
  switch (CTX.color_scheme) {
  case 1:
    while(s[i].str) {
      s[i].function(num, GMSH_SET, CTX.PACK_COLOR(s[i].def2[0], s[i].def2[1],
						  s[i].def2[2], s[i].def2[3]));
      i++;
    }
    break;
  case 2:
    while(s[i].str) {
      s[i].function(num, GMSH_SET, CTX.PACK_COLOR(s[i].def3[0], s[i].def3[1],
						  s[i].def3[2], s[i].def3[3]));
      i++;
    }
    break;
  default:
    while(s[i].str) {
      s[i].function(num, GMSH_SET, CTX.PACK_COLOR(s[i].def1[0], s[i].def1[1],
						  s[i].def1[2], s[i].def1[3]));
      i++;
    }
    break;
  }
}

void Set_ColorOptions_GUI(int num, StringXColor s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_GUI, 0);
    i++;
  }
}

void *Get_ColorOption(char *str, StringXColor s[])
{
  int i = 0;
  while((s[i].str != NULL) && (strcmp(s[i].str, str)))
    i++;
  if(!s[i].str)
    return NULL;
  else
    return (void *)s[i].function;
}

void Print_ColorOptions(int num, int level, int diff, int help,
			StringXColor s[], char *prefix, FILE * file)
{
  int i = 0;
  char tmp[1024];
  while(s[i].str) {
    if(s[i].level & level) {
      unsigned int def;
      switch (CTX.color_scheme) {
      case 1: 
	def = CTX.PACK_COLOR(s[i].def2[0], s[i].def2[1],
			     s[i].def2[2], s[i].def2[3]);
	break;
      case 2: 
	def = CTX.PACK_COLOR(s[i].def3[0], s[i].def3[1], 
			     s[i].def3[2], s[i].def3[3]);
	break;
      default: 
	def = CTX.PACK_COLOR(s[i].def1[0], s[i].def1[1], 
			     s[i].def1[2], s[i].def1[3]);
	break;
      }
      if(!diff || (s[i].function(num, GMSH_GET, 0) != def)){
	sprintf(tmp, "%sColor.%s = {%d,%d,%d};%s%s",
		prefix, s[i].str,
		CTX.UNPACK_RED(s[i].function(num, GMSH_GET, 0)),
		CTX.UNPACK_GREEN(s[i].function(num, GMSH_GET, 0)),
		CTX.UNPACK_BLUE(s[i].function(num, GMSH_GET, 0)), 
		help ? " // " : "", help ? s[i].help : "");
	if(file)
	  fprintf(file, "%s\n", tmp);
	else
	  Msg(DIRECT, tmp);
      }
    }
    i++;
  }
}

void Print_ColorOptionsDoc(StringXColor s[], char *prefix, FILE * file)
{
  int i = 0;
  while(s[i].str) {
    fprintf(file, "@item %sColor.%s\n", prefix, s[i].str);
    fprintf(file, "%s@*\n", s[i].help);
    fprintf(file, "Default value: @code{@{%d,%d,%d@}}@*\n",
	    CTX.UNPACK_RED(s[i].function(0, GMSH_GET, 0)),
	    CTX.UNPACK_GREEN(s[i].function(0, GMSH_GET, 0)),
	    CTX.UNPACK_BLUE(s[i].function(0, GMSH_GET, 0)));
    fprintf(file, "Saved in: @code{%s}\n\n", Get_OptionSaveLevel(s[i].level));
    i++;
  }
}

int Get_ColorForString(StringX4Int SX4I[], int alpha,
                       char *str, int *FlagError)
{
  int i = 0;
  while((SX4I[i].str != NULL) && (strcmp(SX4I[i].str, str)))
    i++;
  *FlagError = (SX4I[i].str == NULL) ? 1 : 0;
  if(alpha > 0)
    return CTX.PACK_COLOR(SX4I[i].int1, SX4I[i].int2, SX4I[i].int3, alpha);
  else
    return CTX.PACK_COLOR(SX4I[i].int1, SX4I[i].int2, SX4I[i].int3, SX4I[i].int4);
}





// String option routines

#define GET_VIEW(error_val)						\
  Post_View *v, **vv;							\
  if(!List_Nbr(CTX.post.list))						\
    v = Post_ViewReference ;						\
  else{									\
    if(!(vv = (Post_View **)List_Pointer_Test(CTX.post.list, num))){	\
      Msg(WARNING, "View[%d] does not exist", num) ;			\
      return (error_val) ;						\
    }									\
    v = *vv;                                                            \
  }

char *opt_general_axes_label0(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    strcpy(CTX.axes_label[0], val);
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[6]->value(CTX.axes_label[0]);
#endif
  return CTX.axes_label[0];
}

char *opt_general_axes_label1(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    strcpy(CTX.axes_label[1], val);
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[7]->value(CTX.axes_label[1]);
#endif
  return CTX.axes_label[1];
}

char *opt_general_axes_label2(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    strcpy(CTX.axes_label[2], val);
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[8]->value(CTX.axes_label[2]);
#endif
  return CTX.axes_label[2];
}

char *opt_general_axes_format0(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    strcpy(CTX.axes_format[0], val);
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[3]->value(CTX.axes_format[0]);
#endif
  return CTX.axes_format[0];
}

char *opt_general_axes_format1(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    strcpy(CTX.axes_format[1], val);
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[4]->value(CTX.axes_format[1]);
#endif
  return CTX.axes_format[1];
}

char *opt_general_axes_format2(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    strcpy(CTX.axes_format[2], val);
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[5]->value(CTX.axes_format[2]);
#endif
  return CTX.axes_format[2];
}

char *opt_general_display(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX.display = val;
  return CTX.display;
}

char *opt_general_filename(OPT_ARGS_STR)
{
  return CTX.filename;
}

char *opt_general_default_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET){
    CTX.default_filename = val;
    strcpy(CTX.default_filename_fullpath, getenv("PWD") ? "" : CTX.home_dir);
    strcat(CTX.default_filename_fullpath, CTX.default_filename);
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[0]->value(CTX.default_filename);
#endif
  return CTX.default_filename;
}

char *opt_general_tmp_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET){
    CTX.tmp_filename = val;
    strcpy(CTX.tmp_filename_fullpath, CTX.home_dir);
    strcat(CTX.tmp_filename_fullpath, CTX.tmp_filename);
  }
  return CTX.tmp_filename;
}

char *opt_general_error_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET){
    CTX.error_filename = val;
    strcpy(CTX.error_filename_fullpath, CTX.home_dir);
    strcat(CTX.error_filename_fullpath, CTX.error_filename);
  }
  return CTX.error_filename;
}

char *opt_general_session_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) {
    CTX.session_filename = val;
    strcpy(CTX.session_filename_fullpath, CTX.home_dir);
    strcat(CTX.session_filename_fullpath, CTX.session_filename);
  }
  return CTX.session_filename;
}

char *opt_general_options_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) {
    CTX.options_filename = val;
    strcpy(CTX.options_filename_fullpath, CTX.home_dir);
    strcat(CTX.options_filename_fullpath, CTX.options_filename);
  }
  return CTX.options_filename;
}

char *opt_general_editor(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX.editor = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[1]->value(CTX.editor);
#endif
  return CTX.editor;
}

char *opt_general_web_browser(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX.web_browser = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_input[2]->value(CTX.web_browser);
#endif
  return CTX.web_browser;
}

char *opt_general_gui_theme(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX.gui_theme = val;
  return CTX.gui_theme;
}

char *opt_general_graphics_font(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX.gl_font = val;
#if defined(HAVE_FLTK)
  int index = GetFontIndex(CTX.gl_font);
  if(action & GMSH_SET){
    CTX.gl_font = GetFontName(index);
    CTX.gl_font_enum = GetFontEnum(index);
  }
  if(WID && (action & GMSH_GUI)){
    WID->gen_choice[1]->value(index);
  }
#endif
  return CTX.gl_font;
}

char *opt_mesh_triangle_options(OPT_ARGS_STR){
  if(action & GMSH_SET)
    CTX.mesh.triangle_options = val;
  return CTX.mesh.triangle_options;
}

char *opt_solver_socket_name(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX.solver.socket_name = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->solver_input[0]->value(CTX.solver.socket_name);
#endif
  return CTX.solver.socket_name;
}

char *opt_solver_name(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].name, val);
  if(WID && (action & GMSH_GUI))
    WID->solver[num].window->label(SINFO[num].name);
  return SINFO[num].name;
#else
  return "undefined";
#endif
}

char *opt_solver_name0(OPT_ARGS_STR)
{
  return opt_solver_name(0, action, val);
}

char *opt_solver_name1(OPT_ARGS_STR)
{
  return opt_solver_name(1, action, val);
}

char *opt_solver_name2(OPT_ARGS_STR)
{
  return opt_solver_name(2, action, val);
}

char *opt_solver_name3(OPT_ARGS_STR)
{
  return opt_solver_name(3, action, val);
}

char *opt_solver_name4(OPT_ARGS_STR)
{
  return opt_solver_name(4, action, val);
}

char *opt_solver_executable(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].executable_name, val);
  if(WID && (action & GMSH_GUI))
    WID->solver[num].input[2]->value(SINFO[num].executable_name);
  return SINFO[num].executable_name;
#else
  return "undefined";
#endif
}

char *opt_solver_executable0(OPT_ARGS_STR)
{
  return opt_solver_executable(0, action, val);
}

char *opt_solver_executable1(OPT_ARGS_STR)
{
  return opt_solver_executable(1, action, val);
}

char *opt_solver_executable2(OPT_ARGS_STR)
{
  return opt_solver_executable(2, action, val);
}

char *opt_solver_executable3(OPT_ARGS_STR)
{
  return opt_solver_executable(3, action, val);
}

char *opt_solver_executable4(OPT_ARGS_STR)
{
  return opt_solver_executable(4, action, val);
}

char *opt_solver_help(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    SINFO[num].help = val;
  return SINFO[num].help;
#else
  return "undefined";
#endif
}

char *opt_solver_help0(OPT_ARGS_STR)
{
  return opt_solver_help(0, action, val);
}

char *opt_solver_help1(OPT_ARGS_STR)
{
  return opt_solver_help(1, action, val);
}

char *opt_solver_help2(OPT_ARGS_STR)
{
  return opt_solver_help(2, action, val);
}

char *opt_solver_help3(OPT_ARGS_STR)
{
  return opt_solver_help(3, action, val);
}

char *opt_solver_help4(OPT_ARGS_STR)
{
  return opt_solver_help(4, action, val);
}

char *opt_solver_extension(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].extension, val);
  return SINFO[num].extension;
#else
  return "undefined";
#endif
}

char *opt_solver_extension0(OPT_ARGS_STR)
{
  return opt_solver_extension(0, action, val);
}

char *opt_solver_extension1(OPT_ARGS_STR)
{
  return opt_solver_extension(1, action, val);
}

char *opt_solver_extension2(OPT_ARGS_STR)
{
  return opt_solver_extension(2, action, val);
}

char *opt_solver_extension3(OPT_ARGS_STR)
{
  return opt_solver_extension(3, action, val);
}

char *opt_solver_extension4(OPT_ARGS_STR)
{
  return opt_solver_extension(4, action, val);
}

char *opt_solver_mesh_name(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].mesh_name, val);
  return SINFO[num].mesh_name;
#else
  return "undefined";
#endif
}

char *opt_solver_mesh_name0(OPT_ARGS_STR)
{
  return opt_solver_mesh_name(0, action, val);
}

char *opt_solver_mesh_name1(OPT_ARGS_STR)
{
  return opt_solver_mesh_name(1, action, val);
}

char *opt_solver_mesh_name2(OPT_ARGS_STR)
{
  return opt_solver_mesh_name(2, action, val);
}

char *opt_solver_mesh_name3(OPT_ARGS_STR)
{
  return opt_solver_mesh_name(3, action, val);
}

char *opt_solver_mesh_name4(OPT_ARGS_STR)
{
  return opt_solver_mesh_name(4, action, val);
}

char *opt_solver_mesh_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].mesh_command, val);
  if(WID && (action & GMSH_GUI))
    WID->solver[num].input[1]->value(SINFO[num].mesh_name);
  return SINFO[num].mesh_command;
#else
  return "undefined";
#endif
}

char *opt_solver_mesh_command0(OPT_ARGS_STR)
{
  return opt_solver_mesh_command(0, action, val);
}

char *opt_solver_mesh_command1(OPT_ARGS_STR)
{
  return opt_solver_mesh_command(1, action, val);
}

char *opt_solver_mesh_command2(OPT_ARGS_STR)
{
  return opt_solver_mesh_command(2, action, val);
}

char *opt_solver_mesh_command3(OPT_ARGS_STR)
{
  return opt_solver_mesh_command(3, action, val);
}

char *opt_solver_mesh_command4(OPT_ARGS_STR)
{
  return opt_solver_mesh_command(4, action, val);
}

char *opt_solver_socket_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].socket_command, val);
  return SINFO[num].socket_command;
#else
  return "undefined";
#endif
}

char *opt_solver_socket_command0(OPT_ARGS_STR)
{
  return opt_solver_socket_command(0, action, val);
}

char *opt_solver_socket_command1(OPT_ARGS_STR)
{
  return opt_solver_socket_command(1, action, val);
}

char *opt_solver_socket_command2(OPT_ARGS_STR)
{
  return opt_solver_socket_command(2, action, val);
}

char *opt_solver_socket_command3(OPT_ARGS_STR)
{
  return opt_solver_socket_command(3, action, val);
}

char *opt_solver_socket_command4(OPT_ARGS_STR)
{
  return opt_solver_socket_command(4, action, val);
}

char *opt_solver_name_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].name_command, val);
  return SINFO[num].name_command;
#else
  return "undefined";
#endif
}

char *opt_solver_name_command0(OPT_ARGS_STR)
{
  return opt_solver_name_command(0, action, val);
}

char *opt_solver_name_command1(OPT_ARGS_STR)
{
  return opt_solver_name_command(1, action, val);
}

char *opt_solver_name_command2(OPT_ARGS_STR)
{
  return opt_solver_name_command(2, action, val);
}

char *opt_solver_name_command3(OPT_ARGS_STR)
{
  return opt_solver_name_command(3, action, val);
}

char *opt_solver_name_command4(OPT_ARGS_STR)
{
  return opt_solver_name_command(4, action, val);
}

char *opt_solver_option_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].option_command, val);
  return SINFO[num].option_command;
#else
  return "undefined";
#endif
}

char *opt_solver_option_command0(OPT_ARGS_STR)
{
  return opt_solver_option_command(0, action, val);
}

char *opt_solver_option_command1(OPT_ARGS_STR)
{
  return opt_solver_option_command(1, action, val);
}

char *opt_solver_option_command2(OPT_ARGS_STR)
{
  return opt_solver_option_command(2, action, val);
}

char *opt_solver_option_command3(OPT_ARGS_STR)
{
  return opt_solver_option_command(3, action, val);
}

char *opt_solver_option_command4(OPT_ARGS_STR)
{
  return opt_solver_option_command(4, action, val);
}

char *opt_solver_first_option(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].option_name[0], val);
  return SINFO[num].option_name[0];
#else
  return "undefined";
#endif
}

char *opt_solver_first_option0(OPT_ARGS_STR)
{
  return opt_solver_first_option(0, action, val);
}

char *opt_solver_first_option1(OPT_ARGS_STR)
{
  return opt_solver_first_option(1, action, val);
}

char *opt_solver_first_option2(OPT_ARGS_STR)
{
  return opt_solver_first_option(2, action, val);
}

char *opt_solver_first_option3(OPT_ARGS_STR)
{
  return opt_solver_first_option(3, action, val);
}

char *opt_solver_first_option4(OPT_ARGS_STR)
{
  return opt_solver_first_option(4, action, val);
}

char *opt_solver_second_option(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].option_name[1], val);
  return SINFO[num].option_name[1];
#else
  return "undefined";
#endif
}

char *opt_solver_second_option0(OPT_ARGS_STR)
{
  return opt_solver_second_option(0, action, val);
}

char *opt_solver_second_option1(OPT_ARGS_STR)
{
  return opt_solver_second_option(1, action, val);
}

char *opt_solver_second_option2(OPT_ARGS_STR)
{
  return opt_solver_second_option(2, action, val);
}

char *opt_solver_second_option3(OPT_ARGS_STR)
{
  return opt_solver_second_option(3, action, val);
}

char *opt_solver_second_option4(OPT_ARGS_STR)
{
  return opt_solver_second_option(4, action, val);
}

char *opt_solver_third_option(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].option_name[2], val);
  return SINFO[num].option_name[2];
#else
  return "undefined";
#endif
}

char *opt_solver_third_option0(OPT_ARGS_STR)
{
  return opt_solver_third_option(0, action, val);
}

char *opt_solver_third_option1(OPT_ARGS_STR)
{
  return opt_solver_third_option(1, action, val);
}

char *opt_solver_third_option2(OPT_ARGS_STR)
{
  return opt_solver_third_option(2, action, val);
}

char *opt_solver_third_option3(OPT_ARGS_STR)
{
  return opt_solver_third_option(3, action, val);
}

char *opt_solver_third_option4(OPT_ARGS_STR)
{
  return opt_solver_third_option(4, action, val);
}

char *opt_solver_fourth_option(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].option_name[3], val);
  return SINFO[num].option_name[3];
#else
  return "undefined";
#endif
}

char *opt_solver_fourth_option0(OPT_ARGS_STR)
{
  return opt_solver_fourth_option(0, action, val);
}

char *opt_solver_fourth_option1(OPT_ARGS_STR)
{
  return opt_solver_fourth_option(1, action, val);
}

char *opt_solver_fourth_option2(OPT_ARGS_STR)
{
  return opt_solver_fourth_option(2, action, val);
}

char *opt_solver_fourth_option3(OPT_ARGS_STR)
{
  return opt_solver_fourth_option(3, action, val);
}

char *opt_solver_fourth_option4(OPT_ARGS_STR)
{
  return opt_solver_fourth_option(4, action, val);
}

char *opt_solver_fifth_option(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].option_name[4], val);
  return SINFO[num].option_name[4];
#else
  return "undefined";
#endif
}

char *opt_solver_fifth_option0(OPT_ARGS_STR)
{
  return opt_solver_fifth_option(0, action, val);
}

char *opt_solver_fifth_option1(OPT_ARGS_STR)
{
  return opt_solver_fifth_option(1, action, val);
}

char *opt_solver_fifth_option2(OPT_ARGS_STR)
{
  return opt_solver_fifth_option(2, action, val);
}

char *opt_solver_fifth_option3(OPT_ARGS_STR)
{
  return opt_solver_fifth_option(3, action, val);
}

char *opt_solver_fifth_option4(OPT_ARGS_STR)
{
  return opt_solver_fifth_option(4, action, val);
}

char *opt_solver_first_button(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_name[0], val);
  return SINFO[num].button_name[0];
#else
  return "undefined";
#endif
}

char *opt_solver_first_button0(OPT_ARGS_STR)
{
  return opt_solver_first_button(0, action, val);
}

char *opt_solver_first_button1(OPT_ARGS_STR)
{
  return opt_solver_first_button(1, action, val);
}

char *opt_solver_first_button2(OPT_ARGS_STR)
{
  return opt_solver_first_button(2, action, val);
}

char *opt_solver_first_button3(OPT_ARGS_STR)
{
  return opt_solver_first_button(3, action, val);
}

char *opt_solver_first_button4(OPT_ARGS_STR)
{
  return opt_solver_first_button(4, action, val);
}

char *opt_solver_first_button_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_command[0], val);
  return SINFO[num].button_command[0];
#else
  return "undefined";
#endif
}

char *opt_solver_first_button_command0(OPT_ARGS_STR)
{
  return opt_solver_first_button_command(0, action, val);
}

char *opt_solver_first_button_command1(OPT_ARGS_STR)
{
  return opt_solver_first_button_command(1, action, val);
}

char *opt_solver_first_button_command2(OPT_ARGS_STR)
{
  return opt_solver_first_button_command(2, action, val);
}

char *opt_solver_first_button_command3(OPT_ARGS_STR)
{
  return opt_solver_first_button_command(3, action, val);
}

char *opt_solver_first_button_command4(OPT_ARGS_STR)
{
  return opt_solver_first_button_command(4, action, val);
}

char *opt_solver_second_button(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_name[1], val);
  return SINFO[num].button_name[1];
#else
  return "undefined";
#endif
}

char *opt_solver_second_button0(OPT_ARGS_STR)
{
  return opt_solver_second_button(0, action, val);
}

char *opt_solver_second_button1(OPT_ARGS_STR)
{
  return opt_solver_second_button(1, action, val);
}

char *opt_solver_second_button2(OPT_ARGS_STR)
{
  return opt_solver_second_button(2, action, val);
}

char *opt_solver_second_button3(OPT_ARGS_STR)
{
  return opt_solver_second_button(3, action, val);
}

char *opt_solver_second_button4(OPT_ARGS_STR)
{
  return opt_solver_second_button(4, action, val);
}

char *opt_solver_second_button_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_command[1], val);
  return SINFO[num].button_command[1];
#else
  return "undefined";
#endif
}

char *opt_solver_second_button_command0(OPT_ARGS_STR)
{
  return opt_solver_second_button_command(0, action, val);
}

char *opt_solver_second_button_command1(OPT_ARGS_STR)
{
  return opt_solver_second_button_command(1, action, val);
}

char *opt_solver_second_button_command2(OPT_ARGS_STR)
{
  return opt_solver_second_button_command(2, action, val);
}

char *opt_solver_second_button_command3(OPT_ARGS_STR)
{
  return opt_solver_second_button_command(3, action, val);
}

char *opt_solver_second_button_command4(OPT_ARGS_STR)
{
  return opt_solver_second_button_command(4, action, val);
}

char *opt_solver_third_button(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_name[2], val);
  return SINFO[num].button_name[2];
#else
  return "undefined";
#endif
}

char *opt_solver_third_button0(OPT_ARGS_STR)
{
  return opt_solver_third_button(0, action, val);
}

char *opt_solver_third_button1(OPT_ARGS_STR)
{
  return opt_solver_third_button(1, action, val);
}

char *opt_solver_third_button2(OPT_ARGS_STR)
{
  return opt_solver_third_button(2, action, val);
}

char *opt_solver_third_button3(OPT_ARGS_STR)
{
  return opt_solver_third_button(3, action, val);
}

char *opt_solver_third_button4(OPT_ARGS_STR)
{
  return opt_solver_third_button(4, action, val);
}

char *opt_solver_third_button_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_command[2], val);
  return SINFO[num].button_command[2];
#else
  return "undefined";
#endif
}

char *opt_solver_third_button_command0(OPT_ARGS_STR)
{
  return opt_solver_third_button_command(0, action, val);
}

char *opt_solver_third_button_command1(OPT_ARGS_STR)
{
  return opt_solver_third_button_command(1, action, val);
}

char *opt_solver_third_button_command2(OPT_ARGS_STR)
{
  return opt_solver_third_button_command(2, action, val);
}

char *opt_solver_third_button_command3(OPT_ARGS_STR)
{
  return opt_solver_third_button_command(3, action, val);
}

char *opt_solver_third_button_command4(OPT_ARGS_STR)
{
  return opt_solver_third_button_command(4, action, val);
}

char *opt_solver_fourth_button(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_name[3], val);
  return SINFO[num].button_name[3];
#else
  return "undefined";
#endif
}

char *opt_solver_fourth_button0(OPT_ARGS_STR)
{
  return opt_solver_fourth_button(0, action, val);
}

char *opt_solver_fourth_button1(OPT_ARGS_STR)
{
  return opt_solver_fourth_button(1, action, val);
}

char *opt_solver_fourth_button2(OPT_ARGS_STR)
{
  return opt_solver_fourth_button(2, action, val);
}

char *opt_solver_fourth_button3(OPT_ARGS_STR)
{
  return opt_solver_fourth_button(3, action, val);
}

char *opt_solver_fourth_button4(OPT_ARGS_STR)
{
  return opt_solver_fourth_button(4, action, val);
}

char *opt_solver_fourth_button_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_command[3], val);
  return SINFO[num].button_command[3];
#else
  return "undefined";
#endif
}

char *opt_solver_fourth_button_command0(OPT_ARGS_STR)
{
  return opt_solver_fourth_button_command(0, action, val);
}

char *opt_solver_fourth_button_command1(OPT_ARGS_STR)
{
  return opt_solver_fourth_button_command(1, action, val);
}

char *opt_solver_fourth_button_command2(OPT_ARGS_STR)
{
  return opt_solver_fourth_button_command(2, action, val);
}

char *opt_solver_fourth_button_command3(OPT_ARGS_STR)
{
  return opt_solver_fourth_button_command(3, action, val);
}

char *opt_solver_fourth_button_command4(OPT_ARGS_STR)
{
  return opt_solver_fourth_button_command(4, action, val);
}

char *opt_solver_fifth_button(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_name[4], val);
  return SINFO[num].button_name[4];
#else
  return "undefined";
#endif
}

char *opt_solver_fifth_button0(OPT_ARGS_STR)
{
  return opt_solver_fifth_button(0, action, val);
}

char *opt_solver_fifth_button1(OPT_ARGS_STR)
{
  return opt_solver_fifth_button(1, action, val);
}

char *opt_solver_fifth_button2(OPT_ARGS_STR)
{
  return opt_solver_fifth_button(2, action, val);
}

char *opt_solver_fifth_button3(OPT_ARGS_STR)
{
  return opt_solver_fifth_button(3, action, val);
}

char *opt_solver_fifth_button4(OPT_ARGS_STR)
{
  return opt_solver_fifth_button(4, action, val);
}

char *opt_solver_fifth_button_command(OPT_ARGS_STR)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    strcpy(SINFO[num].button_command[4], val);
  return SINFO[num].button_command[4];
#else
  return "undefined";
#endif
}

char *opt_solver_fifth_button_command0(OPT_ARGS_STR)
{
  return opt_solver_fifth_button_command(0, action, val);
}

char *opt_solver_fifth_button_command1(OPT_ARGS_STR)
{
  return opt_solver_fifth_button_command(1, action, val);
}

char *opt_solver_fifth_button_command2(OPT_ARGS_STR)
{
  return opt_solver_fifth_button_command(2, action, val);
}

char *opt_solver_fifth_button_command3(OPT_ARGS_STR)
{
  return opt_solver_fifth_button_command(3, action, val);
}

char *opt_solver_fifth_button_command4(OPT_ARGS_STR)
{
  return opt_solver_fifth_button_command(4, action, val);
}

#if defined(HAVE_FLTK)
int _gui_action_valid(int action, int num)
{
  return ((WID) &&
	  (action & GMSH_GUI) && 
	  (num == WID->view_number));
}
#endif

char *opt_view_name(OPT_ARGS_STR)
{
  GET_VIEW(""); 
  if(action & GMSH_SET) {
    strcpy(v->Name, val);
#if defined(HAVE_FLTK)
    if(WID && (num < (int)WID->m_toggle_butt.size())) {
      // this is OK even if v->Name is not static or allocated, since
      // we reset it correctly in the main GUI routines when the view
      // associated with the button changes (i.e., when views are
      // removed)
      WID->m_toggle_butt[num]->label(v->Name);
      WID->m_toggle_butt[num]->redraw();
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_input[0]->value(v->Name);
  }
#endif
  return v->Name;
}

char *opt_view_format(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->Format, val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[1]->value(v->Format);
#endif
  return v->Format;
}

char *opt_view_filename(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->FileName, val);
  }
  return v->FileName;
}

char *opt_view_axes_label0(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->AxesLabel[0], val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[10]->value(v->AxesLabel[0]);
#endif
  return v->AxesLabel[0];
}

char *opt_view_axes_label1(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->AxesLabel[1], val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[11]->value(v->AxesLabel[1]);
#endif
  return v->AxesLabel[1];
}

char *opt_view_axes_label2(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->AxesLabel[2], val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[12]->value(v->AxesLabel[2]);
#endif
  return v->AxesLabel[2];
}

char *opt_view_axes_format0(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->AxesFormat[0], val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[7]->value(v->AxesFormat[0]);
#endif
  return v->AxesFormat[0];
}

char *opt_view_axes_format1(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->AxesFormat[1], val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[8]->value(v->AxesFormat[1]);
#endif
  return v->AxesFormat[1];
}

char *opt_view_axes_format2(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->AxesFormat[2], val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[9]->value(v->AxesFormat[2]);
#endif
  return v->AxesFormat[2];
}

char * opt_view_gen_raise0(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->GenRaiseX, val);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[4]->value(v->GenRaiseX);
#endif
  return v->GenRaiseX;
}

char * opt_view_gen_raise1(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->GenRaiseY, val);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[5]->value(v->GenRaiseY);
#endif
  return v->GenRaiseY;
}

char * opt_view_gen_raise2(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strcpy(v->GenRaiseZ, val);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_input[6]->value(v->GenRaiseZ);
#endif
  return v->GenRaiseZ;
}

int _h2d(char c)
{
  switch(c){
  case 'a': case 'A': return 10;
  case 'b': case 'B': return 11;
  case 'c': case 'C': return 12;
  case 'd': case 'D': return 13;
  case 'e': case 'E': return 14;
  case 'f': case 'F': return 15;
  default :
    if(c >= '0' && c <= '9')
      return c - '0';
    else
      return 0;
  }
}

void _string2stipple(char str[32], int &repeat, int &pattern)
{
  // "n*0xabcd"
  if(str[1] != '*' || str[2] != '0' || str[3] != 'x'){
    // bad format
    repeat = 1;
    pattern = 0xFFFF;
  }
  else{
    repeat = (int)str[0] - '0';
    pattern = 16*16*16*_h2d(str[4]) + 16*16*_h2d(str[5]) + 16*_h2d(str[6]) + _h2d(str[7]);
  }
}

char * opt_view_stipple0(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[0], val, 31);
    v->StippleString[0][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[0], v->Stipple[0][0], v->Stipple[0][1]);
  }
  return v->StippleString[0];
}

char * opt_view_stipple1(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[1], val, 31);
    v->StippleString[1][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[1], v->Stipple[1][0], v->Stipple[1][1]);
  }
  return v->StippleString[1];
}

char * opt_view_stipple2(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[2], val, 31);
    v->StippleString[2][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[2], v->Stipple[2][0], v->Stipple[2][1]);
  }
  return v->StippleString[2];
}

char * opt_view_stipple3(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[3], val, 31);
    v->StippleString[3][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[3], v->Stipple[3][0], v->Stipple[3][1]);
  }
  return v->StippleString[3];
}

char * opt_view_stipple4(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[4], val, 31);
    v->StippleString[4][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[4], v->Stipple[4][0], v->Stipple[4][1]);
  }
  return v->StippleString[4];
}

char * opt_view_stipple5(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[5], val, 31);
    v->StippleString[5][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[5], v->Stipple[5][0], v->Stipple[5][1]);
  }
  return v->StippleString[5];
}

char * opt_view_stipple6(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[6], val, 31);
    v->StippleString[6][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[6], v->Stipple[6][0], v->Stipple[6][1]);
  }
  return v->StippleString[6];
}

char * opt_view_stipple7(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[7], val, 31);
    v->StippleString[7][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[7], v->Stipple[7][0], v->Stipple[7][1]);
  }
  return v->StippleString[7];
}

char * opt_view_stipple8(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[8], val, 31);
    v->StippleString[8][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[8], v->Stipple[8][0], v->Stipple[8][1]);
  }
  return v->StippleString[8];
}

char * opt_view_stipple9(OPT_ARGS_STR)
{
  GET_VIEW("");
  if(action & GMSH_SET) {
    strncpy(v->StippleString[9], val, 31);
    v->StippleString[9][31] = '\0'; // just as a precaution
    _string2stipple(v->StippleString[9], v->Stipple[9][0], v->Stipple[9][1]);
  }
  return v->StippleString[9];
}

// Numeric option routines

double opt_general_initial_context(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.initial_context = (int)val;
  return CTX.initial_context;
}

double opt_general_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.fontsize = (int)val;
  return CTX.fontsize;
}

double opt_general_graphics_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.gl_fontsize = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[12]->value(CTX.gl_fontsize);
#endif
  return CTX.gl_fontsize;
}

double opt_general_viewport2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.viewport[2] = (int)val;
  return CTX.viewport[2];
}

double opt_general_viewport3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.viewport[3] = (int)val;
  return CTX.viewport[3];
}

double opt_general_polygon_offset_always(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.polygon_offset_always = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[4]->value(CTX.polygon_offset_always);
#endif
  return CTX.polygon_offset_always;
}

double opt_general_polygon_offset_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.polygon_offset_factor = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[15]->value(CTX.polygon_offset_factor);
#endif
  return CTX.polygon_offset_factor;
}

double opt_general_polygon_offset_units(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.polygon_offset_units = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[16]->value(CTX.polygon_offset_units);
#endif
  return CTX.polygon_offset_units;
}

double opt_general_graphics_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.gl_position[0] = (int)val;
  return CTX.gl_position[0];
}

double opt_general_graphics_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.gl_position[1] = (int)val;
  return CTX.gl_position[1];
}

double opt_general_menu_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.position[0] = (int)val;
  return CTX.position[0];
}

double opt_general_menu_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.position[1] = (int)val;
  return CTX.position[1];
}

double opt_general_solver_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.solver_position[0] = (int)val;
  return CTX.solver_position[0];
}

double opt_general_solver_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.solver_position[1] = (int)val;
  return CTX.solver_position[1];
}

double opt_general_context_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.ctx_position[0] = (int)val;
  return CTX.ctx_position[0];
}

double opt_general_context_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.ctx_position[1] = (int)val;
  return CTX.ctx_position[1];
}

double opt_general_file_chooser_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.file_chooser_position[0] = (int)val;
  return CTX.file_chooser_position[0];
}

double opt_general_file_chooser_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.file_chooser_position[1] = (int)val;
  return CTX.file_chooser_position[1];
}

double opt_general_system_menu_bar(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.system_menu_bar = (int)val;
  return CTX.system_menu_bar;
}

double opt_general_message_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.msg_position[0] = (int)val;
  return CTX.msg_position[0];
}

double opt_general_message_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.msg_position[1] = (int)val;
  return CTX.msg_position[1];
}

double opt_general_message_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.msg_size[0] = (int)val;
  return CTX.msg_size[0];
}

double opt_general_message_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.msg_size[1] = (int)val;
  return CTX.msg_size[1];
}

double opt_general_option_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.opt_position[0] = (int)val;
  return CTX.opt_position[0];
}

double opt_general_option_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.opt_position[1] = (int)val;
  return CTX.opt_position[1];
}

double opt_general_statistics_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.stat_position[0] = (int)val;
  return CTX.stat_position[0];
}

double opt_general_statistics_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.stat_position[1] = (int)val;
  return CTX.stat_position[1];
}

double opt_general_visibility_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.vis_position[0] = (int)val;
  return CTX.vis_position[0];
}

double opt_general_visibility_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.vis_position[1] = (int)val;
  return CTX.vis_position[1];
}
 
double opt_general_clip_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_position[0] = (int)val;
  return CTX.clip_position[0];
}

double opt_general_clip_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_position[1] = (int)val;
  return CTX.clip_position[1];
}

double opt_general_manip_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.manip_position[0] = (int)val;
  return CTX.manip_position[0];
}

double opt_general_manip_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.manip_position[1] = (int)val;
  return CTX.manip_position[1];
}

double opt_general_session_save(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.session_save = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[8]->value(CTX.session_save);
#endif
  return CTX.session_save;
}

double opt_general_options_save(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.options_save = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[9]->value(CTX.options_save);
#endif
  return CTX.options_save;
}

double opt_general_confirm_overwrite(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.confirm_overwrite = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[14]->value(CTX.confirm_overwrite);
#endif
  return CTX.confirm_overwrite;
}

double opt_general_rotation0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.r[0] = val;
  return CTX.r[0];
}

double opt_general_rotation1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.r[1] = val;
  return CTX.r[1];
}

double opt_general_rotation2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.r[2] = val;
  return CTX.r[2];
}

double opt_general_rotation_center0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.rotation_center[0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[8]->value(CTX.rotation_center[0]);
#endif
  return CTX.rotation_center[0];
}

double opt_general_rotation_center1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.rotation_center[1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[9]->value(CTX.rotation_center[1]);
#endif
  return CTX.rotation_center[1];
}

double opt_general_rotation_center2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.rotation_center[2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[10]->value(CTX.rotation_center[2]);
#endif
  return CTX.rotation_center[2];
}

double opt_general_quaternion0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.quaternion[0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.quaternion[0];
}

double opt_general_quaternion1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.quaternion[1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.quaternion[1];
}

double opt_general_quaternion2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.quaternion[2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.quaternion[2];
}

double opt_general_quaternion3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.quaternion[3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.quaternion[3];
}

double opt_general_translation0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.t[0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.t[0];
}

double opt_general_translation1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.t[1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.t[1];
}

double opt_general_translation2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.t[2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.t[2];
}

double opt_general_scale0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.s[0] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.s[0];
}

double opt_general_scale1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.s[1] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.s[1];
}

double opt_general_scale2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.s[2] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->update_manip_window();
#endif
  return CTX.s[2];
}

double opt_general_clip_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    // should NEVER be zero (or negative)
    if(val < 0.01) 
      CTX.clip_factor = 0.01;
    else
      CTX.clip_factor = val;    
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[14]->value(CTX.clip_factor);
#endif
  return CTX.clip_factor;
}

double opt_general_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.point_size = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[6]->value(CTX.point_size);
#endif
  return CTX.point_size;
}

double opt_general_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.line_width = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[7]->value(CTX.line_width);
#endif
  return CTX.line_width;
}

double opt_general_shine(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.shine = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[1]->value(CTX.shine);
#endif
  return CTX.shine;
}

double opt_general_shine_exponent(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.shine_exponent = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[0]->value(CTX.shine_exponent);
#endif
  return CTX.shine_exponent;
}

double opt_general_verbosity(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.verbosity = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[5]->value(CTX.verbosity);
#endif
  return CTX.verbosity;
}

double opt_general_nopopup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.nopopup = (int)val;
  return CTX.nopopup;
}

double opt_general_terminal(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.terminal = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[7]->value(CTX.terminal);
#endif
  return CTX.terminal;
}

double opt_general_tooltips(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.tooltips = (int)val;
#if defined(HAVE_FLTK)
    if(CTX.tooltips)
      Fl_Tooltip::enable();
    else
      Fl_Tooltip::disable();
#endif
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[13]->value(CTX.tooltips);
#endif
  return CTX.tooltips;
}

double opt_general_orthographic(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.ortho = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    if(CTX.ortho){
      WID->gen_choice[2]->value(0);
      if(!CTX.batch) Msg(STATUS2N, "Orthographic projection");
    }
    else{
      WID->gen_choice[2]->value(1);
      if(!CTX.batch) Msg(STATUS2N, "Perspective projection");
    }
  }
#endif
  return CTX.ortho;
}

double opt_general_mouse_selection(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.enable_mouse_selection = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    switch(CTX.enable_mouse_selection){
    case 1:
      if(!CTX.batch) Msg(STATUS2N, "Mouse selection ON");
      WID->g_status_butt[9]->color(FL_BACKGROUND_COLOR);
      break;
    case 2:
      if(!CTX.batch) Msg(STATUS2N, "Mouse selection ON (with mesh hover)");
      WID->g_status_butt[9]->color(FL_GREEN);
      break;
    case 0:
    default:
      if(!CTX.batch) Msg(STATUS2N, "Mouse selection OFF");
      WID->g_status_butt[9]->color(FL_RED);
      break;
    }
    WID->g_status_butt[9]->redraw();
  }
#endif
  return CTX.enable_mouse_selection;
}

double opt_general_fast_redraw(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.fast_redraw = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_butt[2]->value(CTX.fast_redraw);
    activate_cb(NULL, (void*)"fast_redraw");
  }
#endif
  return CTX.fast_redraw;
}

double opt_general_draw_bounding_box(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.draw_bbox = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[6]->value(CTX.draw_bbox);
#endif
  return CTX.draw_bbox;
}

double opt_general_axes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX.axes = (int)val;
    if(CTX.axes < 0 || CTX.axes > 5)
      CTX.axes = 0;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_choice[4]->value(CTX.axes);
    activate_cb(NULL, (void*)"general_axes");
  }
#endif
  return CTX.axes;
}

double opt_general_axes_auto_position(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_auto_position = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_butt[0]->value(CTX.axes_auto_position);
    activate_cb(NULL, (void*)"general_axes_auto");
  }
#endif
  return CTX.axes_auto_position;
}

double opt_general_axes_tics0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_tics[0] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[17]->value(CTX.axes_tics[0]);
#endif
  return CTX.axes_tics[0];
}

double opt_general_axes_tics1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_tics[1] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[18]->value(CTX.axes_tics[1]);
#endif
  return CTX.axes_tics[1];
}

double opt_general_axes_tics2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_tics[2] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[19]->value(CTX.axes_tics[2]);
#endif
  return CTX.axes_tics[2];
}

double opt_general_axes_xmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_position[0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[20]->value(CTX.axes_position[0]);
#endif
  return CTX.axes_position[0];
}

double opt_general_axes_xmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_position[1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[23]->value(CTX.axes_position[1]);
#endif
  return CTX.axes_position[1];
}

double opt_general_axes_ymin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_position[2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[21]->value(CTX.axes_position[2]);
#endif
  return CTX.axes_position[2];
}

double opt_general_axes_ymax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_position[3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[24]->value(CTX.axes_position[3]);
#endif
  return CTX.axes_position[3];
}

double opt_general_axes_zmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_position[4] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[22]->value(CTX.axes_position[4]);
#endif
  return CTX.axes_position[4];
}

double opt_general_axes_zmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.axes_position[5] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[25]->value(CTX.axes_position[5]);
#endif
  return CTX.axes_position[5];
}

double opt_general_small_axes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.small_axes = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_butt[1]->value(CTX.small_axes);
    activate_cb(NULL, (void*)"general_small_axes");
  }
#endif
  return CTX.small_axes;
}

double opt_general_small_axes_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.small_axes_pos[0] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[26]->value(CTX.small_axes_pos[0]);
#endif
  return CTX.small_axes_pos[0];
}

double opt_general_small_axes_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.small_axes_pos[1] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[27]->value(CTX.small_axes_pos[1]);
#endif
  return CTX.small_axes_pos[1];
}

double opt_general_small_axes_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.small_axes_size = (int)val;
  return CTX.small_axes_size;
}

double opt_general_quadric_subdivisions(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.quadric_subdivisions = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[11]->value(CTX.quadric_subdivisions);
#endif
  return CTX.quadric_subdivisions;
}

double opt_general_double_buffer(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.db = (int)val;
#if defined(HAVE_FLTK)
    if(WID) {
      if(CTX.db) {
        Msg(INFO, "Setting OpenGL visual to double buffered");
        WID->g_opengl_window->mode(FL_RGB | FL_DEPTH | FL_DOUBLE);
      }
      else {
        Msg(INFO, "Setting OpenGL visual to single buffered");
        WID->g_opengl_window->mode(FL_RGB | FL_DEPTH | FL_SINGLE);
      }
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[3]->value(CTX.db);
#endif
  return CTX.db;
}

double opt_general_alpha_blending(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.alpha = (int)val;
  return CTX.alpha;
}

double opt_general_vector_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.vector_type = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    switch (CTX.vector_type) {
    case DRAW_POST_SEGMENT:
      WID->gen_choice[0]->value(0);
      break;
    case DRAW_POST_ARROW:
      WID->gen_choice[0]->value(1);
      break;
    case DRAW_POST_PYRAMID:
      WID->gen_choice[0]->value(2);
      break;
    case DRAW_POST_ARROW3D:
    default:
      WID->gen_choice[0]->value(3);
      break;
    }
  }
#endif
  return CTX.vector_type;
}

double opt_general_arrow_head_radius(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX.arrow_rel_head_radius = val;
  }
  return CTX.arrow_rel_head_radius;
}

double opt_general_arrow_stem_length(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX.arrow_rel_stem_length = val;
  }
  return CTX.arrow_rel_stem_length;
}

double opt_general_arrow_stem_radius(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX.arrow_rel_stem_radius = val;
  }
  return CTX.arrow_rel_stem_radius;
}

double opt_general_color_scheme(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.color_scheme = (int)val;
    if(CTX.color_scheme > 2)
      CTX.color_scheme = 0;
    Set_DefaultColorOptions(0, GeneralOptions_Color);
    Set_DefaultColorOptions(0, GeometryOptions_Color);
    Set_DefaultColorOptions(0, MeshOptions_Color);
    Set_DefaultColorOptions(0, SolverOptions_Color);
    Set_DefaultColorOptions(0, PostProcessingOptions_Color);
    for(int i = 0; i < List_Nbr(CTX.post.list); i++)
      Set_DefaultColorOptions(i, ViewOptions_Color);
    Set_DefaultColorOptions(0, PrintOptions_Color);

    Set_ColorOptions_GUI(0, GeneralOptions_Color);
    Set_ColorOptions_GUI(0, GeometryOptions_Color);
    Set_ColorOptions_GUI(0, MeshOptions_Color);
    Set_ColorOptions_GUI(0, SolverOptions_Color);
    Set_ColorOptions_GUI(0, PostProcessingOptions_Color);
    for(int i = 0; i < List_Nbr(CTX.post.list); i++)
      Set_ColorOptions_GUI(i, ViewOptions_Color);
    Set_ColorOptions_GUI(0, PrintOptions_Color);

    // horrible trick so that the opt_view_XXX will act on the reference view
    List_T *l = CTX.post.list;
    CTX.post.list = NULL; 
    Set_DefaultColorOptions(0, ViewOptions_Color);
    CTX.post.list = l;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_choice[3]->value(CTX.color_scheme);
#endif
  return CTX.color_scheme;
}

double opt_general_background_gradient(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX.bg_gradient = (int)val;
    if(CTX.bg_gradient < 0 || CTX.bg_gradient > 3)
      CTX.bg_gradient = 0;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_choice[5]->value(CTX.bg_gradient);
#endif
  return CTX.bg_gradient;
}

double opt_general_trackball(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.useTrackball = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[5]->value(CTX.useTrackball);
#endif
  return CTX.useTrackball;
}

double opt_general_rotation_center_cg(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.rotation_center_cg = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_butt[15]->value(CTX.rotation_center_cg);
    activate_cb(NULL, (void*)"rotation_center");
  }
#endif
  return CTX.rotation_center_cg;
}

double opt_general_zoom_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.zoom_factor = val;
  return CTX.zoom_factor;
}

double opt_general_expert_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.expert_mode = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[10]->value(CTX.expert_mode);
#endif
  return CTX.expert_mode;
}

double opt_general_clip0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip[0] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip[0];
}

double opt_general_clip0a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[0][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[0][0];
}

double opt_general_clip0b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[0][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[0][1];
}

double opt_general_clip0c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[0][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[0][2];
}

double opt_general_clip0d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[0][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[0][3];
}

double opt_general_clip1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip[1] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip[1];
}

double opt_general_clip1a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[1][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[1][0];
}

double opt_general_clip1b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[1][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[1][1];
}

double opt_general_clip1c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[1][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[1][2];
}

double opt_general_clip1d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[1][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[1][3];
}

double opt_general_clip2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip[2] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip[2];
}

double opt_general_clip2a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[2][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[2][0];
}

double opt_general_clip2b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[2][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[2][1];
}

double opt_general_clip2c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[2][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[2][2];
}

double opt_general_clip2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[2][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[2][3];
}

double opt_general_clip3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip[3] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip[3];
}

double opt_general_clip3a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[3][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[3][0];
}

double opt_general_clip3b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[3][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[3][1];
}

double opt_general_clip3c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[3][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[3][2];
}

double opt_general_clip3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[3][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[3][3];
}

double opt_general_clip4(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip[4] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip[4];
}

double opt_general_clip4a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[4][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[4][0];
}

double opt_general_clip4b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[4][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[4][1];
}

double opt_general_clip4c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[4][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[4][2];
}

double opt_general_clip4d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[4][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[4][3];
}

double opt_general_clip5(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip[5] = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip[5];
}

double opt_general_clip5a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[5][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[5][0];
}

double opt_general_clip5b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[5][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[5][1];
}

double opt_general_clip5c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[5][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[5][2];
}

double opt_general_clip5d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.clip_plane[5][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->reset_clip_browser();
#endif
  return CTX.clip_plane[5][3];
}

double opt_general_light0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light[0] = (int)val;
  return CTX.light[0];
}

double opt_general_light00(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[0][0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_value[2]->value(CTX.light_position[0][0]);
    WID->gen_sphere->setValue(CTX.light_position[0][0],
			      CTX.light_position[0][1],
			      CTX.light_position[0][2]);
  }
#endif
  return CTX.light_position[0][0];
}

double opt_general_light01(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[0][1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_value[3]->value(CTX.light_position[0][1]);
    WID->gen_sphere->setValue(CTX.light_position[0][0],
			      CTX.light_position[0][1],
			      CTX.light_position[0][2]);
  }
#endif
  return CTX.light_position[0][1];
}

double opt_general_light02(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[0][2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->gen_value[4]->value(CTX.light_position[0][2]);
    WID->gen_sphere->setValue(CTX.light_position[0][0],
			      CTX.light_position[0][1],
			      CTX.light_position[0][2]);
  }
#endif
  return CTX.light_position[0][2];
}

double opt_general_light03(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[0][3] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->gen_value[13]->value(CTX.light_position[0][3]);
#endif
  return CTX.light_position[0][3];
}

double opt_general_light1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light[1] = (int)val;
  return CTX.light[1];
}

double opt_general_light10(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[1][0] = val;
  return CTX.light_position[1][0];
}

double opt_general_light11(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[1][1] = val;
  return CTX.light_position[1][1];
}

double opt_general_light12(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[1][2] = val;
  return CTX.light_position[1][2];
}

double opt_general_light13(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[1][3] = val;
  return CTX.light_position[1][3];
}

double opt_general_light2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light[2] = (int)val;
  return CTX.light[2];
}

double opt_general_light20(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[2][0] = val;
  return CTX.light_position[2][0];
}

double opt_general_light21(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[2][1] = val;
  return CTX.light_position[2][1];
}

double opt_general_light22(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[2][2] = val;
  return CTX.light_position[2][2];
}

double opt_general_light23(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[2][3] = val;
  return CTX.light_position[2][3];
}

double opt_general_light3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light[3] = (int)val;
  return CTX.light[3];
}

double opt_general_light30(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[3][0] = val;
  return CTX.light_position[3][0];
}

double opt_general_light31(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[3][1] = val;
  return CTX.light_position[3][1];
}

double opt_general_light32(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[3][2] = val;
  return CTX.light_position[3][2];
}

double opt_general_light33(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[3][3] = val;
  return CTX.light_position[3][3];
}

double opt_general_light4(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light[4] = (int)val;
  return CTX.light[4];
}

double opt_general_light40(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[4][0] = val;
  return CTX.light_position[4][0];
}

double opt_general_light41(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[4][1] = val;
  return CTX.light_position[4][1];
}

double opt_general_light42(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[4][2] = val;
  return CTX.light_position[4][2];
}

double opt_general_light43(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[4][3] = val;
  return CTX.light_position[4][3];
}

double opt_general_light5(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light[5] = (int)val;
  return CTX.light[5];
}

double opt_general_light50(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[5][0] = val;
  return CTX.light_position[5][0];
}

double opt_general_light51(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[5][1] = val;
  return CTX.light_position[5][1];
}

double opt_general_light52(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[5][2] = val;
  return CTX.light_position[5][2];
}

double opt_general_light53(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.light_position[5][3] = val;
  return CTX.light_position[5][3];
}

double opt_geometry_auto_coherence(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.auto_coherence = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[8]->value(CTX.geom.auto_coherence);
#endif
  return CTX.geom.auto_coherence;
}

double opt_geometry_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.normals = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_value[0]->value(CTX.geom.normals);
#endif
  return CTX.geom.normals;
}

double opt_geometry_tangents(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.tangents = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_value[1]->value(CTX.geom.tangents);
#endif
  return CTX.geom.tangents;
}

double opt_geometry_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.points = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[0]->value(CTX.geom.points);
#endif
  return CTX.geom.points;
}

double opt_geometry_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.lines = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[1]->value(CTX.geom.lines);
#endif
  return CTX.geom.lines;
}

double opt_geometry_surfaces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.surfaces = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[2]->value(CTX.geom.surfaces);
#endif
  return CTX.geom.surfaces;
}

double opt_geometry_volumes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.volumes = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[3]->value(CTX.geom.volumes);
#endif
  return CTX.geom.volumes;
}

double opt_geometry_points_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.points_num = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[4]->value(CTX.geom.points_num);
#endif
  return CTX.geom.points_num;
}

double opt_geometry_lines_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.lines_num = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[5]->value(CTX.geom.lines_num);
#endif
  return CTX.geom.lines_num;
}

double opt_geometry_surfaces_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.surfaces_num = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[6]->value(CTX.geom.surfaces_num);
#endif
  return CTX.geom.surfaces_num;
}

double opt_geometry_volumes_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.volumes_num = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[7]->value(CTX.geom.volumes_num);
#endif
  return CTX.geom.volumes_num;
}

double opt_geometry_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.point_size = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_value[3]->value(CTX.geom.point_size);
#endif
  return CTX.geom.point_size;
}

double opt_geometry_point_sel_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.point_sel_size = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_value[5]->value(CTX.geom.point_sel_size);
#endif
  return CTX.geom.point_sel_size;
}

double opt_geometry_point_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.geom.point_type = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    WID->geo_choice[0]->value(CTX.geom.point_type);
  }
#endif
  return CTX.geom.point_type;
}

double opt_geometry_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.line_width = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_value[4]->value(CTX.geom.line_width);
#endif
  return CTX.geom.line_width;
}

double opt_geometry_line_sel_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.line_sel_width = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->geo_value[6]->value(CTX.geom.line_sel_width);
#endif
  return CTX.geom.line_sel_width;
}

double opt_geometry_line_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.geom.line_type = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    WID->geo_choice[1]->value(CTX.geom.line_type);
  }
#endif
  return CTX.geom.line_type;
}

double opt_geometry_light(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.light = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    WID->geo_butt[9]->value(CTX.geom.light);
  }
#endif
  return CTX.geom.light;
}

double opt_geometry_old_circle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.old_circle = (int)val;
  return CTX.geom.old_circle;
}

double opt_geometry_old_newreg(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.old_newreg = (int)val;
  return CTX.geom.old_newreg;
}

double opt_geometry_circle_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.circle_points = (int)val;
  return CTX.geom.circle_points;
}

double opt_geometry_extrude_spline_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.extrude_spline_points = (int)val;
  return CTX.geom.extrude_spline_points;
}

double opt_geometry_scaling_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.scaling_factor = (int)val;
  return CTX.geom.scaling_factor;
}

double opt_geometry_snap0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.snap[0] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->context_geometry_value[0]->value(CTX.geom.snap[0]);
#endif
  return CTX.geom.snap[0];
}

double opt_geometry_snap1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.snap[1] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->context_geometry_value[1]->value(CTX.geom.snap[1]);
#endif
  return CTX.geom.snap[1];
}

double opt_geometry_snap2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.geom.snap[2] = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->context_geometry_value[2]->value(CTX.geom.snap[2]);
#endif
  return CTX.geom.snap[2];
}

double opt_mesh_optimize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.optimize =(int) val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[2]->value(CTX.mesh.optimize);
#endif
  return CTX.mesh.optimize;
}

double opt_mesh_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.quality = val;
  return CTX.mesh.quality;
}

double opt_mesh_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.normals = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[8]->value(CTX.mesh.normals);
#endif
  return CTX.mesh.normals;
}

double opt_mesh_tangents(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.tangents = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[13]->value(CTX.mesh.tangents);
#endif
  return CTX.mesh.tangents;
}

double opt_mesh_explode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.explode != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.explode = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[9]->value(CTX.mesh.explode);
#endif
  return CTX.mesh.explode;
}

double opt_mesh_scaling_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.scaling_factor = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[1]->value(CTX.mesh.scaling_factor);
#endif
  return CTX.mesh.scaling_factor;
}

double opt_mesh_lc_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.lc_factor = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[2]->value(CTX.mesh.lc_factor);
#endif
  return CTX.mesh.lc_factor;
}

double opt_mesh_rand_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.rand_factor = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[3]->value(CTX.mesh.rand_factor);
#endif
  return CTX.mesh.rand_factor;
}

double opt_mesh_quality_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.quality_type != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.quality_type = (int)val;
    if(CTX.mesh.quality_type < 0 || CTX.mesh.quality_type > 2)
      CTX.mesh.quality_type = 0;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->mesh_choice[6]->value(CTX.mesh.quality_type);
  }
#endif
  return CTX.mesh.quality_type;
}

double opt_mesh_quality_inf(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.quality_inf != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.quality_inf = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[4]->value(CTX.mesh.quality_inf);
#endif
  return CTX.mesh.quality_inf;
}

double opt_mesh_quality_sup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.quality_sup != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.quality_sup = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[5]->value(CTX.mesh.quality_sup);
#endif
  return CTX.mesh.quality_sup;
}

double opt_mesh_radius_inf(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.radius_inf != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.radius_inf = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[6]->value(CTX.mesh.radius_inf);
#endif
  return CTX.mesh.radius_inf;
}

double opt_mesh_radius_sup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.radius_sup != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.radius_sup = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[7]->value(CTX.mesh.radius_sup);
#endif
  return CTX.mesh.radius_sup;
}

double opt_mesh_label_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.label_type = (int)val;
    if(CTX.mesh.label_type < 0 || CTX.mesh.label_type > 4)
      CTX.mesh.label_type = 0;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->mesh_choice[7]->value(CTX.mesh.label_type);
  }
#endif
  return CTX.mesh.label_type;
}

double opt_mesh_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.points = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[6]->value(CTX.mesh.points);
#endif
  return CTX.mesh.points;
}

double opt_mesh_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.lines != val) 
      CTX.mesh.changed = ENT_LINE;
    CTX.mesh.lines = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[7]->value(CTX.mesh.lines);
#endif
  return CTX.mesh.lines;
}

double opt_mesh_triangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.triangles != val) 
      CTX.mesh.changed = ENT_SURFACE;
    CTX.mesh.triangles = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    if(CTX.mesh.triangles)
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[0].set();
    else
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[0].clear();
  }
#endif
  return CTX.mesh.triangles;
}

double opt_mesh_quadrangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.quadrangles != val) 
      CTX.mesh.changed = ENT_SURFACE;
    CTX.mesh.quadrangles = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    if(CTX.mesh.quadrangles)
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[1].set();
    else
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[1].clear();
  }
#endif
  return CTX.mesh.quadrangles;
}

double opt_mesh_tetrahedra(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.tetrahedra != val) 
      CTX.mesh.changed = ENT_VOLUME;
    CTX.mesh.tetrahedra = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    if(CTX.mesh.tetrahedra)
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[2].set();
    else
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[2].clear();
  }
#endif
  return CTX.mesh.tetrahedra;
}

double opt_mesh_hexahedra(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.hexahedra != val) 
      CTX.mesh.changed = ENT_VOLUME;
    CTX.mesh.hexahedra = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    if(CTX.mesh.hexahedra)
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[3].set();
    else
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[3].clear();
  }
#endif
  return CTX.mesh.hexahedra;
}

double opt_mesh_prisms(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.prisms != val) 
      CTX.mesh.changed = ENT_VOLUME;
    CTX.mesh.prisms = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    if(CTX.mesh.prisms)
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[4].set();
    else
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[4].clear();
  }
#endif
  return CTX.mesh.prisms;
}

double opt_mesh_pyramids(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.pyramids != val)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.mesh.pyramids = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    if(CTX.mesh.pyramids)
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[5].set();
    else
      ((Fl_Menu_Item*)WID->mesh_menu_butt->menu())[5].clear();
  }
#endif
  return CTX.mesh.pyramids;
}

double opt_mesh_surfaces_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.surfaces_edges != val) 
      CTX.mesh.changed = ENT_SURFACE;
    CTX.mesh.surfaces_edges = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[8]->value(CTX.mesh.surfaces_edges);
#endif
  return CTX.mesh.surfaces_edges;
}

double opt_mesh_surfaces_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.surfaces_faces != val)
      CTX.mesh.changed = ENT_SURFACE;
    CTX.mesh.surfaces_faces = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[9]->value(CTX.mesh.surfaces_faces);
#endif
  return CTX.mesh.surfaces_faces;
}

double opt_mesh_volumes_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.volumes_edges != val)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.mesh.volumes_edges = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[10]->value(CTX.mesh.volumes_edges);
#endif
  return CTX.mesh.volumes_edges;
}

double opt_mesh_volumes_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.volumes_faces != val)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.mesh.volumes_faces = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[11]->value(CTX.mesh.volumes_faces);
#endif
  return CTX.mesh.volumes_faces;
}

double opt_mesh_points_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.points_num = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[12]->value(CTX.mesh.points_num);
#endif
  return CTX.mesh.points_num;
}

double opt_mesh_lines_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.lines_num = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[13]->value(CTX.mesh.lines_num);
#endif
  return CTX.mesh.lines_num;
}

double opt_mesh_surfaces_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.surfaces_num = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[14]->value(CTX.mesh.surfaces_num);
#endif
  return CTX.mesh.surfaces_num;
}

double opt_mesh_volumes_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.volumes_num = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[15]->value(CTX.mesh.volumes_num);
#endif
  return CTX.mesh.volumes_num;
}

double opt_mesh_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.point_size = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[10]->value(CTX.mesh.point_size);
#endif
  return CTX.mesh.point_size;
}

double opt_mesh_point_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.point_type = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    WID->mesh_choice[0]->value(CTX.mesh.point_type ? 1 : 0);
  }
#endif
  return CTX.mesh.point_type;
}

double opt_mesh_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.line_width = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[11]->value(CTX.mesh.line_width);
#endif
  return CTX.mesh.line_width;
}

double opt_mesh_label_frequency(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.label_frequency = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[12]->value(CTX.mesh.label_frequency);
#endif
  return CTX.mesh.label_frequency;
}

double opt_mesh_reverse_all_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.reverse_all_normals != val)
      CTX.mesh.changed = ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.reverse_all_normals = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[0]->value(CTX.mesh.reverse_all_normals);
#endif
  return CTX.mesh.reverse_all_normals;
}

double opt_mesh_smooth_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.smooth_normals != val)
      CTX.mesh.changed = ENT_SURFACE;
    CTX.mesh.smooth_normals = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[19]->value(CTX.mesh.smooth_normals);
#endif
  return CTX.mesh.smooth_normals;
}

double opt_mesh_angle_smooth_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX.mesh.angle_smooth_normals != val)
      CTX.mesh.changed = ENT_SURFACE;
    CTX.mesh.angle_smooth_normals = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[18]->value(CTX.mesh.angle_smooth_normals);
#endif
  return CTX.mesh.angle_smooth_normals;
}

double opt_mesh_light(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.light = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->mesh_butt[17]->value(CTX.mesh.light);
    activate_cb(NULL, (void*)"mesh_light");
  }
#endif
  return CTX.mesh.light;
}

double opt_mesh_light_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.light_lines = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[20]->value(CTX.mesh.light_lines);
#endif
  return CTX.mesh.light_lines;
}

double opt_mesh_light_two_side(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.light_two_side = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[18]->value(CTX.mesh.light_two_side);
#endif
  return CTX.mesh.light_two_side;
}

double opt_mesh_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.format = (int)val;
  return CTX.mesh.format;
}

double opt_mesh_stl_distance_tol(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.stl_distance_tol = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[19]->value(CTX.mesh.stl_distance_tol);
#endif
  return CTX.mesh.stl_distance_tol;
}

double opt_mesh_dihedral_angle_tol(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.dihedral_angle_tol = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[20]->value(CTX.mesh.dihedral_angle_tol);
#endif
  return CTX.mesh.dihedral_angle_tol;
}

double opt_mesh_edge_prolongation_threshold(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.edge_prolongation_threshold = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[21]->value(CTX.mesh.edge_prolongation_threshold);
#endif
  return CTX.mesh.edge_prolongation_threshold;
}

double opt_mesh_nb_elem_per_rc(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.nb_elem_per_rc = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[22]->value(CTX.mesh.nb_elem_per_rc);
#endif
  return CTX.mesh.nb_elem_per_rc;
}

double opt_mesh_min_elem_size_fact(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.min_elem_size_fact = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[23]->value(CTX.mesh.min_elem_size_fact);
#endif
  return CTX.mesh.min_elem_size_fact;
}

double opt_mesh_target_elem_size_fact(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.target_elem_size_fact = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[24]->value(CTX.mesh.target_elem_size_fact);
#endif
  return CTX.mesh.target_elem_size_fact;
}

double opt_mesh_beta_smooth_metric(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.beta_smooth_metric = val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[25]->value(CTX.mesh.beta_smooth_metric);
#endif
  return CTX.mesh.beta_smooth_metric;
}

double opt_mesh_msh_file_version(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.msh_file_version = val;
  return CTX.mesh.msh_file_version;
}

double opt_mesh_msh_binary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.msh_binary = (int)val;
  return CTX.mesh.msh_binary;
}

double opt_mesh_stl_binary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.stl_binary = (int)val;
  return CTX.mesh.stl_binary;
}

double opt_mesh_bdf_field_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX.mesh.bdf_field_format = (int)val;
    if(CTX.mesh.bdf_field_format < 0 ||
       CTX.mesh.bdf_field_format > 2)
      CTX.mesh.bdf_field_format = 1;
  }
  return CTX.mesh.bdf_field_format;
}

double opt_mesh_nb_smoothing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.nb_smoothing = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[0]->value(CTX.mesh.nb_smoothing);
#endif
  return CTX.mesh.nb_smoothing;
}

double opt_mesh_nb_partitions(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.nbPartitions = (int)val;
  return CTX.mesh.nbPartitions;
}

double opt_mesh_algo2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    int algo = (int)val;
    if(algo != DELAUNAY_ISO &&
       algo != DELAUNAY_TRIANGLE &&
       algo != DELAUNAY_ANISO){
      Msg(WARNING, "Unknown mesh algorithm: keeping existing value");
    }
    else{
      CTX.mesh.algo2d = algo;
    }
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    switch (CTX.mesh.algo2d) {
    case DELAUNAY_ISO:
      WID->mesh_choice[2]->value(0);
      break;
    case DELAUNAY_ANISO:
      WID->mesh_choice[2]->value(1);
      break;
    case DELAUNAY_TRIANGLE:
    default:
      WID->mesh_choice[2]->value(2);
      break;
    }
  }
#endif
  return CTX.mesh.algo2d;
}

double opt_mesh_recombine_algo(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    int algo = (int)val;
    if(algo != 1 && algo != 2){
      Msg(WARNING, "Unknown mesh algorithm: keeping existing value");
    }
    else{
      CTX.mesh.algo_recombine = algo;
    }
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    switch (CTX.mesh.algo_recombine) {
    case 2:
      WID->mesh_choice[5]->value(1);
      break;
    default :
      WID->mesh_choice[5]->value(0);
      break;
    }
  }
#endif
  return CTX.mesh.algo_recombine;
}

double opt_mesh_algo3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    int algo = (int)val;
    if(algo != DELAUNAY_ISO && algo != FRONTAL_NETGEN && algo != DELAUNAY_TETGEN){
      Msg(WARNING, "Unknown mesh algorithm: keeping existing value");
    }
    else{
      CTX.mesh.algo3d = algo;
    }
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    switch (CTX.mesh.algo3d) {
    case FRONTAL_NETGEN:
      WID->mesh_choice[3]->value(1);
      break;
    case DELAUNAY_TETGEN:
      WID->mesh_choice[3]->value(2);
      break;
    case DELAUNAY_ISO:
    default:
      WID->mesh_choice[3]->value(0);
      break;
    }
  }
#endif
  return CTX.mesh.algo3d;
}

double opt_mesh_point_insertion(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.point_insertion = (int)val;
  return CTX.mesh.point_insertion;
}

double opt_mesh_speed_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.speed_max = (int)val;
  return CTX.mesh.speed_max;
}

double opt_mesh_min_circ_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.min_circ_points = (int)val;
  return CTX.mesh.min_circ_points;
}

double opt_mesh_constrained_bgmesh(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.constrained_bgmesh = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[5]->value(CTX.mesh.constrained_bgmesh);
#endif
  return CTX.mesh.constrained_bgmesh;
}

double opt_mesh_order(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.order = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[3]->value(CTX.mesh.order == 2);
#endif
  return CTX.mesh.order;
}

double opt_mesh_second_order_linear(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.second_order_linear = (int)val;
  return CTX.mesh.second_order_linear;
}

double opt_mesh_second_order_incomplete(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.second_order_incomplete = (int)val;
  return CTX.mesh.second_order_incomplete;
}

double opt_mesh_dual(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.mesh.dual = (int)val;
  }
  return CTX.mesh.dual;
}

double opt_mesh_interactive(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.interactive = (int)val;
  return CTX.mesh.interactive;
}

double opt_mesh_initial_only(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.initial_only = (int)val;
  return CTX.mesh.initial_only;
}

double opt_mesh_use_cut_plane(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.use_cut_plane != (int)val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.use_cut_plane = (int)val;
#if defined(HAVE_FLTK)
    if(WID){
      double val1 = 0;
      for(int i = 0; i < 3; i++)
	val1 = std::max(val1, std::max(fabs(CTX.min[i]), fabs(CTX.max[i])));
      val1 *= 1.5;
      WID->mesh_value[17]->step(val1/200.);
      WID->mesh_value[17]->minimum(-val1);
      WID->mesh_value[17]->maximum(val1);
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->mesh_butt[16]->value(CTX.mesh.use_cut_plane);
    activate_cb(NULL, (void*)"mesh_cut_plane");
  }
#endif
  return CTX.mesh.use_cut_plane;
}

double opt_mesh_cut_plane_draw_intersect(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.cut_plane_draw_intersect != (int)val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.cut_plane_draw_intersect = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[22]->value(CTX.mesh.cut_plane_draw_intersect);
#endif
  return CTX.mesh.cut_plane_draw_intersect;
}

double opt_mesh_cut_plane_only_volume(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.cut_plane_only_volume != (int)val)
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.cut_plane_only_volume = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[23]->value(CTX.mesh.cut_plane_only_volume);
#endif
  return CTX.mesh.cut_plane_only_volume;
}

double opt_mesh_cut_planea(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.cut_planea != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.cut_planea = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[14]->value(CTX.mesh.cut_planea);
#endif
  return CTX.mesh.cut_planea;
}

double opt_mesh_cut_planeb(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.cut_planeb != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.cut_planeb = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[15]->value(CTX.mesh.cut_planeb);
#endif
  return CTX.mesh.cut_planeb;
}

double opt_mesh_cut_planec(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.cut_planec != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.cut_planec = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[16]->value(CTX.mesh.cut_planec);
#endif
  return CTX.mesh.cut_planec;
}

double opt_mesh_cut_planed(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX.mesh.cut_planed != val) 
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.cut_planed = val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[17]->value(CTX.mesh.cut_planed);
#endif
  return CTX.mesh.cut_planed;
}

double opt_mesh_allow_degenerated_extrude(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.allow_degenerated_extrude = (int)val;
  return CTX.mesh.allow_degenerated_extrude;
}

double opt_mesh_save_all(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.mesh.save_all = (int)val;
  return CTX.mesh.save_all;
}

double opt_mesh_color_carousel(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type or by partition
    if(CTX.mesh.color_carousel != (int)val && 
       ((val == 0. || val == 3.) || CTX.pick_elements))
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.mesh.color_carousel = (int)val;
    if(CTX.mesh.color_carousel < 0 || CTX.mesh.color_carousel > 3)
      CTX.mesh.color_carousel = 0;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)){
    WID->mesh_choice[4]->value(CTX.mesh.color_carousel);
  }
#endif
  return CTX.mesh.color_carousel;
}

extern void GetStatistics(double s[50], double quality[3][100]=0);

double opt_mesh_nb_nodes(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[4] + s[5] + s[6];
}

double opt_mesh_nb_triangles(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[7];
}

double opt_mesh_nb_quadrangles(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[8];
}

double opt_mesh_nb_tetrahedra(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[9];
}

double opt_mesh_nb_hexahedra(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[10];
}

double opt_mesh_nb_prisms(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[11];
}

double opt_mesh_nb_pyramids(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[12];
}

double opt_mesh_cpu_time(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[13] + s[14] + s[15];
}

double opt_solver_max_delay(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.solver.max_delay = (val >= 0) ? (int)val : 0;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->solver_value[0]->value(CTX.solver.max_delay);
#endif
  return CTX.solver.max_delay;
}

double opt_solver_listen(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.solver.listen = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->solver_butt[0]->value(CTX.solver.listen);
#endif
  return CTX.solver.listen;
}

double opt_solver_plugins(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.solver.plugins = (int)val;
  return CTX.solver.plugins;
}

double opt_solver_client_server(OPT_ARGS_NUM)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    SINFO[num].client_server = (int)val;
  if(WID && (action & GMSH_GUI))
    WID->solver[num].butt[2]->value(SINFO[num].client_server);
  return SINFO[num].client_server;
#else
  return 0.;
#endif
}

double opt_solver_client_server0(OPT_ARGS_NUM)
{
  return opt_solver_client_server(0, action, val);
}

double opt_solver_client_server1(OPT_ARGS_NUM)
{
  return opt_solver_client_server(1, action, val);
}

double opt_solver_client_server2(OPT_ARGS_NUM)
{
  return opt_solver_client_server(2, action, val);
}

double opt_solver_client_server3(OPT_ARGS_NUM)
{
  return opt_solver_client_server(3, action, val);
}

double opt_solver_client_server4(OPT_ARGS_NUM)
{
  return opt_solver_client_server(4, action, val);
}

double opt_solver_popup_messages(OPT_ARGS_NUM)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    SINFO[num].popup_messages = (int)val;
  if(WID && (action & GMSH_GUI))
    WID->solver[num].butt[0]->value(SINFO[num].popup_messages);
  return SINFO[num].popup_messages;
#else
  return 1.;
#endif
}

double opt_solver_popup_messages0(OPT_ARGS_NUM)
{
  return opt_solver_popup_messages(0, action, val);
}

double opt_solver_popup_messages1(OPT_ARGS_NUM)
{
  return opt_solver_popup_messages(1, action, val);
}

double opt_solver_popup_messages2(OPT_ARGS_NUM)
{
  return opt_solver_popup_messages(2, action, val);
}

double opt_solver_popup_messages3(OPT_ARGS_NUM)
{
  return opt_solver_popup_messages(3, action, val);
}

double opt_solver_popup_messages4(OPT_ARGS_NUM)
{
  return opt_solver_popup_messages(4, action, val);
}

double opt_solver_merge_views(OPT_ARGS_NUM)
{
#if defined(HAVE_FLTK)
  if(action & GMSH_SET)
    SINFO[num].merge_views = (int)val;
  if(WID && (action & GMSH_GUI))
    WID->solver[num].butt[1]->value(SINFO[num].merge_views);
  return SINFO[num].merge_views;
#else
  return 1.;
#endif
}

double opt_solver_merge_views0(OPT_ARGS_NUM)
{
  return opt_solver_merge_views(0, action, val);
}

double opt_solver_merge_views1(OPT_ARGS_NUM)
{
  return opt_solver_merge_views(1, action, val);
}

double opt_solver_merge_views2(OPT_ARGS_NUM)
{
  return opt_solver_merge_views(2, action, val);
}

double opt_solver_merge_views3(OPT_ARGS_NUM)
{
  return opt_solver_merge_views(3, action, val);
}

double opt_solver_merge_views4(OPT_ARGS_NUM)
{
  return opt_solver_merge_views(4, action, val);
}

double opt_post_vertex_arrays(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX.post.vertex_arrays = (int)val;
  }
  return CTX.post.vertex_arrays;
}

double opt_post_horizontal_scales(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.horizontal_scales = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->post_butt[2]->value(CTX.post.horizontal_scales);
#endif
  return CTX.post.horizontal_scales;
}

double opt_post_link(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX.post.link = (int)val;
    if(CTX.post.link < 0 || CTX.post.link > 4)
      CTX.post.link = 0;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI)) {
    WID->post_choice[0]->value(CTX.post.link);
  }
#endif
  return CTX.post.link;
}

double opt_post_smooth(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.smooth = (int)val;
  return CTX.post.smooth;
}

double opt_post_anim_delay(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.anim_delay = (val >= 0.) ? val : 0.;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->post_value[0]->value(CTX.post.anim_delay);
#endif
  return CTX.post.anim_delay;
}

double opt_post_anim_cycle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.anim_cycle = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->post_butt[0]->value(CTX.post.anim_cycle);
  if(WID)
    WID->check_anim_buttons();
#endif
  return CTX.post.anim_cycle;
}

double opt_post_combine_remove_orig(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.combine_remove_orig = (int)val;
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI))
    WID->post_butt[1]->value(CTX.post.combine_remove_orig);
#endif
  return CTX.post.combine_remove_orig;
}

double opt_post_plugins(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.plugins = (int)val;
  return CTX.post.plugins;
}

double opt_post_nb_views(OPT_ARGS_NUM)
{
  return List_Nbr(CTX.post.list);
}

double opt_post_file_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.post.file_format = (int)val;
  return CTX.post.file_format;
}

double opt_view_nb_timestep(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET)
    v->NbTimeStep = (int)val;
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[50]->maximum(v->NbTimeStep - 1);
  if(WID)
    WID->check_anim_buttons();
#endif
  return v->NbTimeStep;
}

double opt_view_timestep(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->TimeStep = (int)val;
    if(v->TimeStep > v->NbTimeStep - 1)
      v->TimeStep = 0;
    else if(v->TimeStep < 0)
      v->TimeStep = v->NbTimeStep - 1;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[50]->value(v->TimeStep);
#endif
  return v->TimeStep;
}

double opt_view_min(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->Min;
}

double opt_view_max(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->Max;
}

double opt_view_custom_min(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CustomMin = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[31]->value(v->CustomMin);
  }
#endif
  return v->CustomMin;
}

double opt_view_custom_max(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CustomMax = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[32]->value(v->CustomMax);
#endif
  return v->CustomMax;
}

double opt_view_xmin(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->BBox[0];
}

double opt_view_xmax(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->BBox[1];
}

double opt_view_ymin(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->BBox[2];
}

double opt_view_ymax(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->BBox[3];
}

double opt_view_zmin(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->BBox[4];
}

double opt_view_zmax(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  return v->BBox[5];
}

double opt_view_offset0(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Offset[0] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[40]->value(v->Offset[0]);
#endif
  return v->Offset[0];
}

double opt_view_offset1(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Offset[1] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[41]->value(v->Offset[1]);
#endif
  return v->Offset[1];
}

double opt_view_offset2(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Offset[2] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[42]->value(v->Offset[2]);
#endif
  return v->Offset[2];
}

double opt_view_raise0(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Raise[0] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[43]->value(v->Raise[0]);
#endif
  return v->Raise[0];
}

double opt_view_raise1(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Raise[1] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[44]->value(v->Raise[1]);
#endif
  return v->Raise[1];
}

double opt_view_raise2(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Raise[2] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[45]->value(v->Raise[2]);
#endif
  return v->Raise[2];
}

double opt_view_transform00(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[0][0] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[51]->value(v->Transform[0][0]);
#endif
  return v->Transform[0][0];
}

double opt_view_transform01(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[0][1] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[52]->value(v->Transform[0][1]);
#endif
  return v->Transform[0][1];
}

double opt_view_transform02(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[0][2] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[53]->value(v->Transform[0][2]);
#endif
  return v->Transform[0][2];
}

double opt_view_transform10(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[1][0] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[54]->value(v->Transform[1][0]);
#endif
  return v->Transform[1][0];
}

double opt_view_transform11(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[1][1] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[55]->value(v->Transform[1][1]);
#endif
  return v->Transform[1][1];
}

double opt_view_transform12(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[1][2] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[56]->value(v->Transform[1][2]);
#endif
  return v->Transform[1][2];
}

double opt_view_transform20(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[2][0] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[57]->value(v->Transform[2][0]);
#endif
  return v->Transform[2][0];
}

double opt_view_transform21(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[2][1] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[58]->value(v->Transform[2][1]);
#endif
  return v->Transform[2][1];
}

double opt_view_transform22(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Transform[2][2] = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[59]->value(v->Transform[2][2]);
#endif
  return v->Transform[2][2];
}

double opt_view_arrow_size(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ArrowSize = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[60]->value(v->ArrowSize);
#endif
  return v->ArrowSize;
}

double opt_view_arrow_size_proportional(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ArrowSizeProportional = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[0]->value(v->ArrowSizeProportional);
#endif
  return v->ArrowSizeProportional;
}

double opt_view_arrow_head_radius(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    v->ArrowRelHeadRadius = val;
  }
  return v->ArrowRelHeadRadius;
}

double opt_view_arrow_stem_length(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    v->ArrowRelStemLength = val;
  }
  return v->ArrowRelStemLength;
}

double opt_view_arrow_stem_radius(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    v->ArrowRelStemRadius = val;
  }
  return v->ArrowRelStemRadius;
}

double opt_view_normals(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Normals = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[0]->value(v->Normals);
#endif
  return v->Normals;
}

double opt_view_tangents(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Tangents = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[1]->value(v->Tangents);
#endif
  return v->Tangents;
}

double opt_view_displacement_factor(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DisplacementFactor = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[63]->value(v->DisplacementFactor);
#endif
  return v->DisplacementFactor;
}

double opt_view_fake_transparency(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->FakeTransparency = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[24]->value(v->FakeTransparency);
#endif
  return v->FakeTransparency;
}

double opt_view_explode(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Explode = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[12]->value(v->Explode);
#endif
  return v->Explode;
}

double opt_view_visible(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Visible = (int)val;
  }
#if defined(HAVE_FLTK)
  if(WID && (action & GMSH_GUI) && (num < (int)WID->m_toggle_butt.size()))
    WID->m_toggle_butt[num]->value(v->Visible);
#endif
  Msg(DEBUG1, "View %d", v->Num);
  Msg(DEBUG2, "  -> Name '%s'", v->Name);
  Msg(DEBUG2, "  -> FileName '%s'", v->FileName);
  Msg(DEBUG2, "  -> AliasOf %d", v->AliasOf);
  Msg(DEBUG3, "  -> Links %d", v->Links);
  return v->Visible;
}

double opt_view_intervals_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    int type = (int)val;
    if(type != DRAW_POST_ISO &&
       type != DRAW_POST_DISCRETE &&
       type != DRAW_POST_CONTINUOUS &&
       type != DRAW_POST_NUMERIC){
      Msg(WARNING, "Unknown interval type: keeping existing value");
    }
    else{
      v->IntervalsType = type;
      v->Changed = 1;
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    switch (v->IntervalsType) {
    case DRAW_POST_ISO:
      WID->view_choice[0]->value(0);
      break;
    case DRAW_POST_DISCRETE:
      WID->view_choice[0]->value(1);
      break;
    case DRAW_POST_NUMERIC:
      WID->view_choice[0]->value(3);
      break;
    case DRAW_POST_CONTINUOUS:
    default:
      WID->view_choice[0]->value(2);
      break;
    }
  }
#endif
  return v->IntervalsType;
}

double opt_view_saturate_values(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->SaturateValues = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_butt[38]->value(v->SaturateValues);
  }
#endif
  return v->SaturateValues;
}


double opt_view_max_recursion_level(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    if(v->adaptive)
      v->adaptive->setGlobalResolutionLevel(v,(int)val);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if (v->adaptive){
      WID->view_value[33]->value(v->adaptive->getGlobalResolutionLevel());
    }
  }
#endif
  if(v->adaptive)
    return v->adaptive->getGlobalResolutionLevel();
  return 0;
}

double opt_view_target_error(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    if(v->adaptive) {
      v->adaptive->setTolerance(val);
      v->adaptive->setGlobalResolutionLevel(v,v->adaptive->getGlobalResolutionLevel());
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(v->adaptive){
      WID->view_value[34]->value(v->adaptive->getTolerance());
    }
  }
#endif
  if (v->adaptive)
    return v->adaptive->getTolerance();
  return 1.e-2;
}


double opt_view_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    int type = (int)val;
    if(type != DRAW_POST_3D &&
       type != DRAW_POST_2D_SPACE &&
       type != DRAW_POST_2D_TIME){
      Msg(WARNING, "Unknown view type: keeping existing value");
    }
    else{
      v->Type = type;
      v->Changed = 1;
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    switch (v->Type) {
    case DRAW_POST_3D:
      WID->view_choice[13]->value(0);
      break;
    case DRAW_POST_2D_SPACE:
      WID->view_choice[13]->value(1);
      break;
    case DRAW_POST_2D_TIME:
    default:
      WID->view_choice[13]->value(2);
      break;
    }
  }
#endif
  return v->Type;
}

double opt_view_auto_position(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AutoPosition = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_butt[7]->value(v->AutoPosition);
    activate_cb(NULL, (void*)"view_axes_auto_2d");
  }
#endif
  return v->AutoPosition;
}

double opt_view_position0(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Position[0] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[20]->value(v->Position[0]);
#endif
  return v->Position[0];
}

double opt_view_position1(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Position[1] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[21]->value(v->Position[1]);
#endif
  return v->Position[1];
}

double opt_view_size0(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Size[0] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[22]->value(v->Size[0]);
#endif
  return v->Size[0];
}

double opt_view_size1(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Size[1] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[23]->value(v->Size[1]);
#endif
  return v->Size[1];
}

double opt_view_axes(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Axes = (int)val;
    if(v->Axes < 0 || v->Axes > 5)
      v->Axes = 0;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_choice[8]->value(v->Axes);
    activate_cb(NULL, (void*)"view_axes");
  }
#endif
  return v->Axes;
}

double opt_view_axes_auto_position(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesAutoPosition = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_butt[25]->value(v->AxesAutoPosition);
    activate_cb(NULL, (void*)"view_axes_auto_3d");
  }
#endif
  return v->AxesAutoPosition;
}

double opt_view_axes_xmin(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesPosition[0] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[13]->value(v->AxesPosition[0]);
  }
#endif
  return v->AxesPosition[0];
}

double opt_view_axes_xmax(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesPosition[1] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[16]->value(v->AxesPosition[1]);
  }
#endif
  return v->AxesPosition[1];
}

double opt_view_axes_ymin(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesPosition[2] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[14]->value(v->AxesPosition[2]);
  }
#endif
  return v->AxesPosition[2];
}

double opt_view_axes_ymax(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesPosition[3] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[17]->value(v->AxesPosition[3]);
  }
#endif
  return v->AxesPosition[3];
}

double opt_view_axes_zmin(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesPosition[4] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[15]->value(v->AxesPosition[4]);
  }
#endif
  return v->AxesPosition[4];
}

double opt_view_axes_zmax(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesPosition[5] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[18]->value(v->AxesPosition[5]);
  }
#endif
  return v->AxesPosition[5];
}

double opt_view_axes_tics0(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesTics[0] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[3]->value(v->AxesTics[0]);
  }
#endif
  return v->AxesTics[0];
}

double opt_view_axes_tics1(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesTics[1] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[4]->value(v->AxesTics[1]);
  }
#endif
  return v->AxesTics[1];
}

double opt_view_axes_tics2(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AxesTics[2] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_value[5]->value(v->AxesTics[2]);
  }
#endif
  return v->AxesTics[2];
}

double opt_view_nb_iso(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->NbIso = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[30]->value(v->NbIso);
#endif
  return v->NbIso;
}

double opt_view_boundary(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Boundary = (int)val;
    if(v->Boundary < 0 || v->Boundary > 3)
      v->Boundary = 0;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_choice[9]->value(v->Boundary);
  }
#endif
  return v->Boundary;
}

double opt_view_light(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->Light = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    WID->view_butt[11]->value(v->Light);
    activate_cb(NULL, (void*)"view_light");
  }
#endif
  return v->Light;
}

double opt_view_light_two_side(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->LightTwoSide = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[9]->value(v->LightTwoSide);
#endif
  return v->LightTwoSide;
}

double opt_view_light_lines(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->LightLines = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[8]->value(v->LightLines);
#endif
  return v->LightLines;
}

double opt_view_smooth_normals(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->SmoothNormals = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[12]->value(v->SmoothNormals);
#endif
  return v->SmoothNormals;
}

double opt_view_angle_smooth_normals(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->AngleSmoothNormals = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[10]->value(v->AngleSmoothNormals);
#endif
  return v->AngleSmoothNormals;
}

double opt_view_show_element(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ShowElement = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[10]->value(v->ShowElement);
#endif
  return v->ShowElement;
}

double opt_view_show_time(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ShowTime = (int)val;
    if(v->ShowTime < 0 || v->ShowTime > 4)
      v->ShowTime = 0;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_choice[12]->value(v->ShowTime);
#endif
  return v->ShowTime;
}

double opt_view_show_scale(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ShowScale = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[4]->value(v->ShowScale);
#endif
  return v->ShowScale;
}

double opt_view_draw_strings(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawStrings = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_butt[5]->value(v->DrawStrings);
#endif
  return v->DrawStrings;
}

double opt_view_draw_points(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawPoints = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawPoints)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[0].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[0].clear();
  }
#endif
  return v->DrawPoints;
}

double opt_view_draw_lines(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawLines = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawLines)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[1].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[1].clear();
  }
#endif
  return v->DrawLines;
}

double opt_view_draw_triangles(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawTriangles = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawTriangles)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[2].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[2].clear();
  }
#endif
  return v->DrawTriangles;
}

double opt_view_draw_quadrangles(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawQuadrangles = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawQuadrangles)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[3].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[3].clear();
  }
#endif
  return v->DrawQuadrangles;
}

double opt_view_draw_tetrahedra(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawTetrahedra = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawTetrahedra)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[4].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[4].clear();
  }
#endif
  return v->DrawTetrahedra;
}

double opt_view_draw_hexahedra(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawHexahedra = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawHexahedra)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[5].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[5].clear();
  }
#endif
  return v->DrawHexahedra;
}

double opt_view_draw_prisms(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawPrisms = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawPrisms)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[6].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[6].clear();
  }
#endif
  return v->DrawPrisms;
}

double opt_view_draw_pyramids(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawPyramids = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawPyramids)
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[7].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[1]->menu())[7].clear();
  }
#endif
  return v->DrawPyramids;
}

double opt_view_draw_scalars(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawScalars = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawScalars)
      ((Fl_Menu_Item*)WID->view_menu_butt[0]->menu())[0].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[0]->menu())[0].clear();
  }
#endif
  return v->DrawScalars;
}

double opt_view_draw_vectors(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawVectors = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawVectors)
      ((Fl_Menu_Item*)WID->view_menu_butt[0]->menu())[1].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[0]->menu())[1].clear();
  }
#endif
  return v->DrawVectors;
}

double opt_view_draw_tensors(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->DrawTensors = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(v->DrawTensors)
      ((Fl_Menu_Item*)WID->view_menu_butt[0]->menu())[2].set();
    else
      ((Fl_Menu_Item*)WID->view_menu_butt[0]->menu())[2].clear();
  }
#endif
  return v->DrawTensors;
}

double opt_view_scale_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    int type = (int)val;
    if(type != DRAW_POST_LINEAR &&
       type != DRAW_POST_LOGARITHMIC &&
       type != DRAW_POST_DOUBLELOGARITHMIC){
      Msg(WARNING, "Unknown scale type: keeping existing value");
    }
    else{
      v->ScaleType = type;
      v->Changed = 1;
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    switch (v->ScaleType) {
    case DRAW_POST_LOGARITHMIC:
      WID->view_choice[1]->value(1);
      break;
    case DRAW_POST_DOUBLELOGARITHMIC:
      WID->view_choice[1]->value(2);
      break;
    case DRAW_POST_LINEAR:
    default:
      WID->view_choice[1]->value(0);
      break;
    }
  }
#endif
  return v->ScaleType;
}

double opt_view_range_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->RangeType = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    switch(v->RangeType){
    case DRAW_POST_RANGE_PER_STEP:
      WID->view_choice[7]->value(1);
      break;
    case DRAW_POST_RANGE_CUSTOM:
      WID->view_choice[7]->value(2);
      break;
    case DRAW_POST_RANGE_DEFAULT:
    default:
      WID->view_choice[7]->value(0);
      break;
    }
    activate_cb(NULL, (void*)"custom_range");
  }
#endif
  return v->RangeType;
}

double opt_view_tensor_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->TensorType = (int)val;
    v->Changed = 1;
  }
 #if defined(HAVE_FLTK)
   if(_gui_action_valid(action, num)) {
     switch (v->TensorType) {
     case DRAW_POST_LMGC90:
       WID->view_choice[4]->value(1);
       break;
     case DRAW_POST_LMGC90_TYPE:
       WID->view_choice[4]->value(2);
       break;
     case DRAW_POST_LMGC90_COORD:
       WID->view_choice[4]->value(3);
       break;
     case DRAW_POST_LMGC90_PRES:
       WID->view_choice[4]->value(4);
       break;
     case DRAW_POST_LMGC90_SN:
       WID->view_choice[4]->value(5);
       break;
     case DRAW_POST_LMGC90_DEPX:
       WID->view_choice[4]->value(6);
       break;
     case DRAW_POST_LMGC90_DEPY:
       WID->view_choice[4]->value(7);
       break;
     case DRAW_POST_LMGC90_DEPZ:
       WID->view_choice[4]->value(8);
       break;
     case DRAW_POST_LMGC90_DEPAV:
       WID->view_choice[4]->value(9);
       break;
     case DRAW_POST_LMGC90_DEPNORM:
       WID->view_choice[4]->value(10);
       break;
     case DRAW_POST_VONMISES:
     default:
       WID->view_choice[4]->value(0);
       break;
     }
   }
 #endif
  return v->TensorType;
}

double opt_view_vector_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->VectorType = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    switch (v->VectorType) {
    case DRAW_POST_SEGMENT:
      WID->view_choice[2]->value(0);
      break;
    case DRAW_POST_ARROW:
      WID->view_choice[2]->value(1);
      break;
    case DRAW_POST_PYRAMID:
      WID->view_choice[2]->value(2);
      break;
    case DRAW_POST_DISPLACEMENT:
      WID->view_choice[2]->value(4);
      break;
    case DRAW_POST_ARROW3D:
    default:
      WID->view_choice[2]->value(3);
      break;
    }
  }
#endif
  return v->VectorType;
}

double opt_view_glyph_location(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->GlyphLocation = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    switch (v->GlyphLocation) {
    case DRAW_POST_LOCATE_VERTEX:
      WID->view_choice[3]->value(1);
      break;
    case DRAW_POST_LOCATE_COG:
    default:
      WID->view_choice[3]->value(0);
      break;
    }
  }
#endif
  return v->GlyphLocation;
}

double opt_view_point_size(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->PointSize = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[61]->value(v->PointSize);
#endif
  return v->PointSize;
}

double opt_view_line_width(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->LineWidth = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[62]->value(v->LineWidth);
#endif
  return v->LineWidth;
}

double opt_view_point_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->PointType = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_choice[5]->value(v->PointType ? 1 : 0);
  }
#endif
  return v->PointType;
}

double opt_view_line_type(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->LineType = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_choice[6]->value(v->LineType ? 1 : 0);
  }
#endif
  return v->LineType;
}

double opt_view_colormap_alpha(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.dpar[COLORTABLE_ALPHA] = val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.dpar[COLORTABLE_ALPHA];
}

double opt_view_colormap_alpha_power(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.dpar[COLORTABLE_ALPHAPOW] = val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.dpar[COLORTABLE_ALPHAPOW];
}

double opt_view_colormap_beta(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.dpar[COLORTABLE_BETA] = val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.dpar[COLORTABLE_BETA];
}

double opt_view_colormap_bias(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.dpar[COLORTABLE_BIAS] = val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.dpar[COLORTABLE_BIAS];
}

double opt_view_colormap_curvature(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.dpar[COLORTABLE_CURVATURE] = val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.dpar[COLORTABLE_CURVATURE];
}

double opt_view_colormap_invert(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.ipar[COLORTABLE_INVERT] = (int)val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.ipar[COLORTABLE_INVERT];
}

double opt_view_colormap_number(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.ipar[COLORTABLE_NUMBER] = (int)val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.ipar[COLORTABLE_NUMBER];
}

double opt_view_colormap_rotation(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.ipar[COLORTABLE_ROTATION] = (int)val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.ipar[COLORTABLE_ROTATION];
}

double opt_view_colormap_swap(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->CT.ipar[COLORTABLE_SWAP] = (int)val;
    ColorTable_Recompute(&v->CT);
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    WID->view_colorbar_window->redraw();
  }
#endif
  return v->CT.ipar[COLORTABLE_SWAP];
}

double opt_view_external_view(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ExternalViewIndex = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    // warning: Fl_Choice::size() returns number of items+1
    int item = v->ExternalViewIndex + 1;
    if(item > -1 && item < WID->view_choice[10]->size()-1)
      WID->view_choice[10]->value(item);
    else
      WID->view_choice[10]->value(0);
  }
#endif
  return v->ExternalViewIndex;
}

double opt_view_gen_raise_view(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->ViewIndexForGenRaise = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    // warning: Fl_Choice::size() returns number of items+1
    int item = v->ViewIndexForGenRaise + 1;
    if(item > -1 && item < WID->view_choice[11]->size()-1)
      WID->view_choice[11]->value(item);
    else
      WID->view_choice[11]->value(0);
  }
#endif
  return v->ViewIndexForGenRaise;
}

double opt_view_gen_raise_factor(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->GenRaiseFactor = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    WID->view_value[2]->value(v->GenRaiseFactor);
#endif
  return v->GenRaiseFactor;
}

double opt_view_use_gen_raise(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->UseGenRaise = (int)val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    WID->view_butt[6]->value(v->UseGenRaise);
    activate_cb(NULL, (void*)"general_transform");
  }
#endif
  return v->UseGenRaise;
}

double opt_view_use_stipple(OPT_ARGS_NUM)
{
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    v->UseStipple = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    WID->view_butt[26]->value(v->UseStipple);
  }
#endif
  return v->UseStipple;
}

double opt_print_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.format = (int)val;
  return CTX.print.format;
}

double opt_print_eps_compress(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_compress = (int)val;
  return CTX.print.eps_compress;
}

double opt_print_eps_ps3shading(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_ps3shading = (int)val;
  return CTX.print.eps_ps3shading;
}

double opt_print_eps_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_quality = (int)val;
  return CTX.print.eps_quality;
}

double opt_print_eps_occlusion_culling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_occlusion_culling = (int)val;
  return CTX.print.eps_occlusion_culling;
}

double opt_print_eps_best_root(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_best_root = (int)val;
  return CTX.print.eps_best_root;
}

double opt_print_eps_background(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_background = (int)val;
  return CTX.print.eps_background;
}

double opt_print_eps_line_width_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_line_width_factor = val;
  return CTX.print.eps_line_width_factor;
}

double opt_print_eps_point_size_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.eps_point_size_factor = val;
  return CTX.print.eps_point_size_factor;
}

double opt_print_jpeg_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.jpeg_quality = (int)val;
  return CTX.print.jpeg_quality;
}

double opt_print_jpeg_smoothing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.jpeg_smoothing = (int)val;
  return CTX.print.jpeg_smoothing;
}

double opt_print_gif_dither(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.gif_dither = (int)val;
  return CTX.print.gif_dither;
}

double opt_print_gif_sort(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.gif_sort = (int)val;
  return CTX.print.gif_sort;
}

double opt_print_gif_interlace(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.gif_interlace = (int)val;
  return CTX.print.gif_interlace;
}

double opt_print_gif_transparent(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.gif_transparent = (int)val;
  return CTX.print.gif_transparent;
}

double opt_print_text(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX.print.text = (int)val;
  return CTX.print.text;
}

// Color option routines

#if defined(HAVE_FLTK)

#define CCC(col,but)							\
  if(WID && (action & GMSH_GUI)){					\
    Fl_Color c = fl_color_cube(CTX.UNPACK_RED(col)*FL_NUM_RED/256, 	\
			       CTX.UNPACK_GREEN(col)*FL_NUM_GREEN/256,	\
			       CTX.UNPACK_BLUE(col)*FL_NUM_BLUE/256);	\
    (but)->color(c);							\
    (but)->labelcolor(fl_contrast(FL_BLACK,c));				\
    (but)->redraw();							\
  }

#endif

unsigned int opt_general_color_background(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX.color.bg = val;
#if defined(HAVE_FLTK)
    if(WID)
      WID->view_colorbar_window->redraw();
#endif
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.bg, WID->gen_col[0]);
#endif
  return CTX.color.bg;
}

unsigned int opt_general_color_background_gradient(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.bg_grad = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.bg_grad, WID->gen_col[1]);
#endif
  return CTX.color.bg_grad;
}

unsigned int opt_general_color_foreground(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.fg = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.fg, WID->gen_col[2]);
#endif
  return CTX.color.fg;
}

unsigned int opt_general_color_text(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.text = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.text, WID->gen_col[3]);
#endif
  return CTX.color.text;
}

unsigned int opt_general_color_axes(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.axes = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.axes, WID->gen_col[4]);
#endif
  return CTX.color.axes;
}

unsigned int opt_general_color_small_axes(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.small_axes = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.small_axes, WID->gen_col[5]);
#endif
  return CTX.color.small_axes;
}

unsigned int opt_general_color_ambient_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++)
      CTX.color.ambient_light[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.ambient_light[0], WID->gen_col[6]);
#endif
  return CTX.color.ambient_light[0];
}

unsigned int opt_general_color_diffuse_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++)
      CTX.color.diffuse_light[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.diffuse_light[0], WID->gen_col[7]);
#endif
  return CTX.color.diffuse_light[0];
}

unsigned int opt_general_color_specular_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++)
      CTX.color.specular_light[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.specular_light[0], WID->gen_col[8]);
#endif
  return CTX.color.specular_light[0];
}

unsigned int opt_geometry_color_points(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.point = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.point, WID->geo_col[0]);
#endif
  return CTX.color.geom.point;
}

unsigned int opt_geometry_color_lines(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.line = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.line, WID->geo_col[1]);
#endif
  return CTX.color.geom.line;
}

unsigned int opt_geometry_color_surfaces(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.surface = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.surface, WID->geo_col[2]);
#endif
  return CTX.color.geom.surface;
}

unsigned int opt_geometry_color_volumes(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.volume = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.volume, WID->geo_col[3]);
#endif
  return CTX.color.geom.volume;
}

unsigned int opt_geometry_color_points_select(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.point_sel = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.point_sel, WID->geo_col[4]);
#endif
  return CTX.color.geom.point_sel;
}

unsigned int opt_geometry_color_lines_select(OPT_ARGS_COL)
{
  if(action & GMSH_SET){
    CTX.color.geom.line_sel = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.line_sel, WID->geo_col[5]);
#endif
  return CTX.color.geom.line_sel;
}

unsigned int opt_geometry_color_surfaces_select(OPT_ARGS_COL)
{
  if(action & GMSH_SET){
    CTX.color.geom.surface_sel = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.surface_sel, WID->geo_col[6]);
#endif
  return CTX.color.geom.surface_sel;
}

unsigned int opt_geometry_color_volumes_select(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.volume_sel = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.volume_sel, WID->geo_col[7]);
#endif
  return CTX.color.geom.volume_sel;
}

unsigned int opt_geometry_color_tangents(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.tangents = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.tangents, WID->geo_col[8]);
#endif
  return CTX.color.geom.tangents;
}

unsigned int opt_geometry_color_normals(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX.color.geom.normals = val;
#if defined(HAVE_FLTK)
  CCC(CTX.color.geom.normals, WID->geo_col[9]);
#endif
  return CTX.color.geom.normals;
}

unsigned int opt_mesh_color_points(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX.color.mesh.vertex = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.vertex, WID->mesh_col[0]);
#endif
  return CTX.color.mesh.vertex;
}

unsigned int opt_mesh_color_lines(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.line != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.color.mesh.line = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.line, WID->mesh_col[1]);
#endif
  return CTX.color.mesh.line;
}

unsigned int opt_mesh_color_triangles(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.triangle != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_SURFACE;
    CTX.color.mesh.triangle = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.triangle, WID->mesh_col[2]);
#endif
  return CTX.color.mesh.triangle;
}

unsigned int opt_mesh_color_quadrangles(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.quadrangle != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_SURFACE;
    CTX.color.mesh.quadrangle = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.quadrangle, WID->mesh_col[3]);
#endif
  return CTX.color.mesh.quadrangle;
}

unsigned int opt_mesh_color_tetrahedra(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.tetrahedron != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.color.mesh.tetrahedron = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.tetrahedron, WID->mesh_col[4]);
#endif
  return CTX.color.mesh.tetrahedron;
}

unsigned int opt_mesh_color_hexahedra(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.hexahedron != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.color.mesh.hexahedron = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.hexahedron, WID->mesh_col[5]);
#endif
  return CTX.color.mesh.hexahedron;
}

unsigned int opt_mesh_color_prisms(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.prism != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.color.mesh.prism = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.prism, WID->mesh_col[6]);
#endif
  return CTX.color.mesh.prism;
}

unsigned int opt_mesh_color_pyramid(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX.color.mesh.pyramid != val && CTX.mesh.color_carousel == 0)
      CTX.mesh.changed = ENT_VOLUME;
    CTX.color.mesh.pyramid = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.pyramid, WID->mesh_col[7]);
#endif
  return CTX.color.mesh.pyramid;
}

unsigned int opt_mesh_color_tangents(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX.color.mesh.tangents = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.tangents, WID->mesh_col[8]);
#endif
  return CTX.color.mesh.tangents;
}

unsigned int opt_mesh_color_normals(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX.color.mesh.normals = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.normals, WID->mesh_col[9]);
#endif
  return CTX.color.mesh.normals;
}

unsigned int opt_mesh_color_(int i, OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // partition
    if(CTX.color.mesh.carousel[i] != val && CTX.mesh.color_carousel == 3)
      CTX.mesh.changed = ENT_LINE | ENT_SURFACE | ENT_VOLUME;
    CTX.color.mesh.carousel[i] = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX.color.mesh.carousel[i], WID->mesh_col[10+i]);
#endif
  return CTX.color.mesh.carousel[i];
}

unsigned int opt_mesh_color_0(OPT_ARGS_COL){ return opt_mesh_color_(0, num, action, val); }
unsigned int opt_mesh_color_1(OPT_ARGS_COL){ return opt_mesh_color_(1, num, action, val); }
unsigned int opt_mesh_color_2(OPT_ARGS_COL){ return opt_mesh_color_(2, num, action, val); }
unsigned int opt_mesh_color_3(OPT_ARGS_COL){ return opt_mesh_color_(3, num, action, val); }
unsigned int opt_mesh_color_4(OPT_ARGS_COL){ return opt_mesh_color_(4, num, action, val); }
unsigned int opt_mesh_color_5(OPT_ARGS_COL){ return opt_mesh_color_(5, num, action, val); }
unsigned int opt_mesh_color_6(OPT_ARGS_COL){ return opt_mesh_color_(6, num, action, val); }
unsigned int opt_mesh_color_7(OPT_ARGS_COL){ return opt_mesh_color_(7, num, action, val); }
unsigned int opt_mesh_color_8(OPT_ARGS_COL){ return opt_mesh_color_(8, num, action, val); }
unsigned int opt_mesh_color_9(OPT_ARGS_COL){ return opt_mesh_color_(9, num, action, val); }
unsigned int opt_mesh_color_10(OPT_ARGS_COL){ return opt_mesh_color_(10, num, action, val); }
unsigned int opt_mesh_color_11(OPT_ARGS_COL){ return opt_mesh_color_(11, num, action, val); }
unsigned int opt_mesh_color_12(OPT_ARGS_COL){ return opt_mesh_color_(12, num, action, val); }
unsigned int opt_mesh_color_13(OPT_ARGS_COL){ return opt_mesh_color_(13, num, action, val); }
unsigned int opt_mesh_color_14(OPT_ARGS_COL){ return opt_mesh_color_(14, num, action, val); }
unsigned int opt_mesh_color_15(OPT_ARGS_COL){ return opt_mesh_color_(15, num, action, val); }
unsigned int opt_mesh_color_16(OPT_ARGS_COL){ return opt_mesh_color_(16, num, action, val); }
unsigned int opt_mesh_color_17(OPT_ARGS_COL){ return opt_mesh_color_(17, num, action, val); }
unsigned int opt_mesh_color_18(OPT_ARGS_COL){ return opt_mesh_color_(18, num, action, val); }
unsigned int opt_mesh_color_19(OPT_ARGS_COL){ return opt_mesh_color_(19, num, action, val); }

unsigned int opt_view_color_points(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.point = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.point, WID->view_col[0]);
  }
#endif
  return v->color.point;
}

unsigned int opt_view_color_lines(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.line = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.line, WID->view_col[1]);
  }
#endif
  return v->color.line;
}

unsigned int opt_view_color_triangles(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.triangle = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.triangle, WID->view_col[2]);
  }
#endif
  return v->color.triangle;
}

unsigned int opt_view_color_quadrangles(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.quadrangle = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.quadrangle, WID->view_col[3]);
  }
#endif
  return v->color.quadrangle;
}

unsigned int opt_view_color_tetrahedra(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.tetrahedron = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.tetrahedron, WID->view_col[4]);
  }
#endif
  return v->color.tetrahedron;
}

unsigned int opt_view_color_hexahedra(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.hexahedron = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.hexahedron, WID->view_col[5]);
  }
#endif
  return v->color.hexahedron;
}

unsigned int opt_view_color_prisms(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.prism = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.prism, WID->view_col[6]);
  }
#endif
  return v->color.prism;
}

unsigned int opt_view_color_pyramids(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.pyramid = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.pyramid, WID->view_col[7]);
  }
#endif
  return v->color.pyramid;
}

unsigned int opt_view_color_tangents(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.tangents = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.tangents, WID->view_col[8]);
  }
#endif
  return v->color.tangents;
}

unsigned int opt_view_color_normals(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.normals = val;
    v->Changed = 1;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.normals, WID->view_col[9]);
  }
#endif
  return v->color.normals;
}

unsigned int opt_view_color_text2d(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.text2d = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.text2d, WID->view_col[10]);
  }
#endif
  return v->color.text2d;
}

unsigned int opt_view_color_text3d(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.text3d = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.text3d, WID->view_col[11]);
  }
#endif
  return v->color.text3d;
}

unsigned int opt_view_color_axes(OPT_ARGS_COL)
{
  GET_VIEW(0);
  if(action & GMSH_SET) {
    v->color.axes = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(v->color.axes, WID->view_col[12]);
  }
#endif
  return v->color.axes;
}

