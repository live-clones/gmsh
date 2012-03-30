// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "GModel.h"
#include "Context.h"
#include "Options.h"
#include "DefaultOptions.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#include "BackgroundMesh.h"
#endif

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "adaptiveData.h"
#endif

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#include "Plugin.h"
#endif

#if defined(HAVE_FLTK)
#include <FL/Fl_Tooltip.H>
#include "FlGui.h"
#include "menuWindow.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "clippingWindow.h"
#endif

// General routines for string options

bool StringOption(int action, const char *category, int num,
                  const char *name, std::string &val)
{
  StringXString *s = 0;
  if(!strcmp(category, "General"))
    s = GeneralOptions_String;
  else if(!strcmp(category, "Geometry"))
    s = GeometryOptions_String;
  else if(!strcmp(category, "Mesh"))
    s = MeshOptions_String;
  else if(!strcmp(category, "Solver"))
    s = SolverOptions_String;
  else if(!strcmp(category, "PostProcessing"))
    s = PostProcessingOptions_String;
  else if(!strcmp(category, "View"))
    s = ViewOptions_String;
  else if(!strcmp(category, "Print"))
    s = PrintOptions_String;
  else{
    Msg::Error("Unknown string option category '%s'", category);
    return false;
  }

  int i = 0;
  while(s[i].str && strcmp(s[i].str, name)) i++;
  if(!s[i].str){
    Msg::Error("Unknown string option '%s.%s'", category, name);
    return false;
  }

  val = s[i].function(num, action, val);
  return true;
}

static void SetDefaultStringOptions(int num, StringXString s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_SET, s[i].def);
    i++;
  }
}

static void SetStringOptionsGUI(int num, StringXString s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_GUI, "");
    i++;
  }
}

static void PrintStringOptions(int num, int level, int diff, int help,
                               StringXString s[], const char *prefix, FILE *file)
{
  int i = 0;
  while(s[i].str) {
    if(s[i].level & level) {
      if(!diff || s[i].function(num, GMSH_GET, "") != s[i].def){
        char tmp[1024];
        sprintf(tmp, "%s%s = \"%s\";%s%s", prefix,
                s[i].str, s[i].function(num, GMSH_GET, "").c_str(),
                help ? " // " : "", help ? s[i].help : "");
        if(file)
          fprintf(file, "%s\n", tmp);
        else{
          // remove \n, \t, \r
          for(unsigned int i = 0; i < strlen(tmp); i++)
            if(tmp[i] == '\n' || tmp[i] == '\t' || tmp[i] == '\r') tmp[i] = ' ';
          // Warning: must call Msg::Direct(level, ...) here, because
          // we cannot use tmp as a format string (it can contain %s!)
          Msg::Direct(3, "%s", tmp);
        }
      }
    }
    i++;
  }
}

static const char *GetOptionSaveLevel(int level)
{
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

static void PrintStringOptionsDoc(StringXString s[], const char *prefix, FILE *file)
{
  int i = 0;
  while(s[i].str) {
    fprintf(file, "@item %s%s\n", prefix, s[i].str);
    fprintf(file, "%s@*\n", s[i].help);

    // sanitize the string for texinfo
    std::string val = s[i].function(0, GMSH_GET, "");
    for(unsigned int j = 1; j < val.size(); j++){
      if(val[j] == '\n' && val[j - 1] == '\n')
        val[j - 1] = '.';
    }
    fprintf(file, "Default value: @code{\"%s\"}@*\n", val.c_str());
    fprintf(file, "Saved in: @code{%s}\n\n", GetOptionSaveLevel(s[i].level));
    i++;
  }
}

// General routines for numeric options

bool NumberOption(int action, const char *category, int num,
                  const char *name, double &val)
{
  StringXNumber *s = 0;
  if(!strcmp(category, "General"))
    s = GeneralOptions_Number;
  else if(!strcmp(category, "Geometry"))
    s = GeometryOptions_Number;
  else if(!strcmp(category, "Mesh"))
    s = MeshOptions_Number;
  else if(!strcmp(category, "Solver"))
    s = SolverOptions_Number;
  else if(!strcmp(category, "PostProcessing"))
    s = PostProcessingOptions_Number;
  else if(!strcmp(category, "View"))
    s = ViewOptions_Number;
  else if(!strcmp(category, "Print"))
    s = PrintOptions_Number;
  else{
    Msg::Error("Unknown number option category '%s'", category);
    return false;
  }

  int i = 0;
  while(s[i].str && strcmp(s[i].str, name)) i++;
  if(!s[i].str){
    Msg::Error("Unknown number option '%s.%s'", category, name);
    return false;
  }
  val = s[i].function(num, action, val);
  return true;
}

static void SetDefaultNumberOptions(int num, StringXNumber s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_SET, s[i].def);
    i++;
  }
}

static void SetNumberOptionsGUI(int num, StringXNumber s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_GUI, 0);
    i++;
  }
}

static void PrintNumberOptions(int num, int level, int diff, int help,
                               StringXNumber s[], const char *prefix, FILE * file)
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
          Msg::Direct(tmp);
      }
    }
    i++;
  }
}

static void PrintNumberOptionsDoc(StringXNumber s[], const char *prefix, FILE * file)
{
  int i = 0;
  while(s[i].str) {
    fprintf(file, "@item %s%s\n", prefix, s[i].str);
    fprintf(file, "%s@*\n", s[i].help);
    fprintf(file, "Default value: @code{%g}@*\n", s[i].function(0, GMSH_GET, 0));
    fprintf(file, "Saved in: @code{%s}\n\n", GetOptionSaveLevel(s[i].level));
    i++;
  }
}

// General routines for color options

bool ColorOption(int action, const char *category, int num,
                 const char *name, unsigned int &val)
{
  StringXColor *s = 0;
  if(!strcmp(category, "General"))
    s = GeneralOptions_Color;
  else if(!strcmp(category, "Geometry"))
    s = GeometryOptions_Color;
  else if(!strcmp(category, "Mesh"))
    s = MeshOptions_Color;
  else if(!strcmp(category, "Solver"))
    s = SolverOptions_Color;
  else if(!strcmp(category, "PostProcessing"))
    s = PostProcessingOptions_Color;
  else if(!strcmp(category, "View"))
    s = ViewOptions_Color;
  else if(!strcmp(category, "Print"))
    s = PrintOptions_Color;
  else{
    Msg::Error("Unknown color option category '%s'", category);
    return false;
  }

  int i = 0;
  while(s[i].str && strcmp(s[i].str, name)) i++;
  if(!s[i].str){
    Msg::Error("Unknown color option '%s.%s'", category, name);
    return false;
  }
  val = s[i].function(num, action, val);
  return true;
}

int GetColorForString(StringX4Int SX4I[], int alpha,
                      const char *str, int *FlagError)
{
  int i = 0;
  while(SX4I[i].str && strcmp(SX4I[i].str, str))
    i++;
  *FlagError = !SX4I[i].str ? 1 : 0;
  if(alpha > 0)
    return CTX::instance()->packColor
      (SX4I[i].int1, SX4I[i].int2, SX4I[i].int3, alpha);
  else
    return CTX::instance()->packColor
      (SX4I[i].int1, SX4I[i].int2, SX4I[i].int3, SX4I[i].int4);
}

static void SetDefaultColorOptions(int num, StringXColor s[])
{
  int i = 0;
  // Warning: this assumes that CTX::instance()->color_scheme is set...
  switch (CTX::instance()->colorScheme) {
  case 1:
    while(s[i].str) {
      s[i].function(num, GMSH_SET, CTX::instance()->packColor
                    (s[i].def2[0], s[i].def2[1], s[i].def2[2], s[i].def2[3]));
      i++;
    }
    break;
  case 2:
    while(s[i].str) {
      s[i].function(num, GMSH_SET, CTX::instance()->packColor
                    (s[i].def3[0], s[i].def3[1], s[i].def3[2], s[i].def3[3]));
      i++;
    }
    break;
  default:
    while(s[i].str) {
      s[i].function(num, GMSH_SET, CTX::instance()->packColor
                    (s[i].def1[0], s[i].def1[1], s[i].def1[2], s[i].def1[3]));
      i++;
    }
    break;
  }
}

static void SetColorOptionsGUI(int num, StringXColor s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_GUI, 0);
    i++;
  }
}

static void PrintColorOptions(int num, int level, int diff, int help,
                              StringXColor s[], const char *prefix, FILE * file)
{
  int i = 0;
  char tmp[1024];
  while(s[i].str) {
    if(s[i].level & level) {
      unsigned int def;
      switch (CTX::instance()->colorScheme) {
      case 1:
        def = CTX::instance()->packColor
          (s[i].def2[0], s[i].def2[1], s[i].def2[2], s[i].def2[3]);
        break;
      case 2:
        def = CTX::instance()->packColor
          (s[i].def3[0], s[i].def3[1], s[i].def3[2], s[i].def3[3]);
        break;
      default:
        def = CTX::instance()->packColor
          (s[i].def1[0], s[i].def1[1], s[i].def1[2], s[i].def1[3]);
        break;
      }
      if(!diff || (s[i].function(num, GMSH_GET, 0) != def)){
        sprintf(tmp, "%sColor.%s = {%d,%d,%d};%s%s",
                prefix, s[i].str,
                CTX::instance()->unpackRed(s[i].function(num, GMSH_GET, 0)),
                CTX::instance()->unpackGreen(s[i].function(num, GMSH_GET, 0)),
                CTX::instance()->unpackBlue(s[i].function(num, GMSH_GET, 0)),
                help ? " // " : "", help ? s[i].help : "");
        if(file)
          fprintf(file, "%s\n", tmp);
        else
          Msg::Direct(tmp);
      }
    }
    i++;
  }
}

static void PrintColorOptionsDoc(StringXColor s[], const char *prefix, FILE * file)
{
  int i = 0;
  while(s[i].str) {
    fprintf(file, "@item %sColor.%s\n", prefix, s[i].str);
    fprintf(file, "%s@*\n", s[i].help);
    fprintf(file, "Default value: @code{@{%d,%d,%d@}}@*\n",
            CTX::instance()->unpackRed(s[i].function(0, GMSH_GET, 0)),
            CTX::instance()->unpackGreen(s[i].function(0, GMSH_GET, 0)),
            CTX::instance()->unpackBlue(s[i].function(0, GMSH_GET, 0)));
    fprintf(file, "Saved in: @code{%s}\n\n", GetOptionSaveLevel(s[i].level));
    i++;
  }
}

// General routines

void InitOptions(int num)
{
  // Default string options
  SetDefaultStringOptions(num, GeneralOptions_String);
  SetDefaultStringOptions(num, GeometryOptions_String);
  SetDefaultStringOptions(num, MeshOptions_String);
  SetDefaultStringOptions(num, SolverOptions_String);
  SetDefaultStringOptions(num, PostProcessingOptions_String);
  SetDefaultStringOptions(num, ViewOptions_String);
  SetDefaultStringOptions(num, PrintOptions_String);

  // Default number options
  SetDefaultNumberOptions(num, GeneralOptions_Number);
  SetDefaultNumberOptions(num, GeometryOptions_Number);
  SetDefaultNumberOptions(num, MeshOptions_Number);
  SetDefaultNumberOptions(num, SolverOptions_Number);
  SetDefaultNumberOptions(num, PostProcessingOptions_Number);
  SetDefaultNumberOptions(num, ViewOptions_Number);
  SetDefaultNumberOptions(num, PrintOptions_Number);

  // Default color options
  SetDefaultColorOptions(num, GeneralOptions_Color);
  SetDefaultColorOptions(num, GeometryOptions_Color);
  SetDefaultColorOptions(num, MeshOptions_Color);
  SetDefaultColorOptions(num, SolverOptions_Color);
  SetDefaultColorOptions(num, PostProcessingOptions_Color);
  SetDefaultColorOptions(num, ViewOptions_Color);
  SetDefaultColorOptions(num, PrintOptions_Color);
}

void ReInitOptions(int num)
{
  // horrible trick so that opt_view_XXX will act on the reference view
#if defined(HAVE_POST)
  std::vector<PView*> tmp = PView::list;
  PView::list.clear();
#endif

  InitOptions(num);

#if defined(HAVE_POST)
  PView::list = tmp;
  for(unsigned int i = 0; i < PView::list.size(); i++)
    PView::list[i]->setOptions();
#endif
}

void InitOptionsGUI(int num)
{
  SetStringOptionsGUI(num, GeneralOptions_String);
  SetStringOptionsGUI(num, GeometryOptions_String);
  SetStringOptionsGUI(num, MeshOptions_String);
  SetStringOptionsGUI(num, SolverOptions_String);
  SetStringOptionsGUI(num, PostProcessingOptions_String);
  SetStringOptionsGUI(num, PrintOptions_String);

  SetNumberOptionsGUI(num, GeneralOptions_Number);
  SetNumberOptionsGUI(num, GeometryOptions_Number);
  SetNumberOptionsGUI(num, MeshOptions_Number);
  SetNumberOptionsGUI(num, SolverOptions_Number);
  SetNumberOptionsGUI(num, PostProcessingOptions_Number);
  SetNumberOptionsGUI(num, PrintOptions_Number);

  SetColorOptionsGUI(num, GeneralOptions_Color);
  SetColorOptionsGUI(num, GeometryOptions_Color);
  SetColorOptionsGUI(num, MeshOptions_Color);
  SetColorOptionsGUI(num, SolverOptions_Color);
  SetColorOptionsGUI(num, PostProcessingOptions_Color);
  SetColorOptionsGUI(num, PrintOptions_Color);
}

static void PrintOptionCategory(int level, int diff, int help, const char *cat,
                                 FILE *file)
{
  if(diff || !help || !(level & GMSH_FULLRC))
    return;
  if(file) {
    fprintf(file, "//\n");
    fprintf(file, "// %s\n", cat);
    fprintf(file, "//\n");
  }
  else {
    Msg::Direct("//");
    Msg::Direct("// %s", cat);
    Msg::Direct("//");
  }
}

GmshColorTable *GetColorTable(int num)
{
#if defined(HAVE_POST)
  PViewOptions *opt;
  if(PView::list.empty() || num < 0 || num > (int)PView::list.size() - 1)
    opt = &PViewOptions::reference;
  else{
    opt = PView::list[num]->getOptions();
    // assume that if we access the colortable we will change it
    PView::list[num]->setChanged(true);
  }
  return &opt->colorTable;
#else
  return 0;
#endif
}

static void PrintColorTable(int num, int diff, const char *prefix, FILE *file)
{
#if defined(HAVE_POST)
  PViewOptions *opt;
  if(PView::list.empty() || num < 0 || num > (int)PView::list.size() - 1)
    opt = &PViewOptions::reference;
  else
    opt = PView::list[num]->getOptions();

  if(diff){
    // compare the current colormap with a vanilla colormap having the
    // parameters
    GmshColorTable ref;
    ColorTable_InitParam(opt->colorTable.ipar[COLORTABLE_NUMBER], &ref);
    for(int i = 0; i < COLORTABLE_NBMAX_PARAM; i++){
      ref.ipar[i] = opt->colorTable.ipar[i];
      ref.dpar[i] = opt->colorTable.dpar[i];
    }
    ColorTable_Recompute(&ref);
    if(!ColorTable_Diff(&ref, &opt->colorTable))
      return;
  }

  char tmp[1024];
  sprintf(tmp, "%s = {", prefix);
  if(file)
    fprintf(file, "%s\n", tmp);
  else
    Msg::Direct(tmp);
  ColorTable_Print(&opt->colorTable, file);
  sprintf(tmp, "};");
  if(file)
    fprintf(file, "%s\n", tmp);
  else
    Msg::Direct(tmp);
#endif
}

//used in field options, sorry if it's already implemented somewhere else...
static void Sanitize_String_Texi(std::string &s)
{
  int i = -1;
  while ((i = s.find('\n', i + 1)) >= 0){
    s.insert(i, "@*");
    i += 2;
  }
  i = -1;
  while ((i = s.find_first_of("{}", i + 1)) >= 0)
    s.insert(i++, "@");
}

void PrintOptions(int num, int level, int diff, int help, const char *filename)
{
#if defined(HAVE_FLTK)
  if(FlGui::available())
    FlGui::instance()->storeCurrentWindowsInfo();
#endif

  FILE *file;

  if(filename) {
    file = fopen(filename, "w");
    if(!file) {
      Msg::Error("Unable to open file '%s'", filename);
      return;
    }
  }
  else
    file = 0;

  if((level & GMSH_SESSIONRC) && file) {
    fprintf(file, "// Gmsh Session File\n");
    fprintf(file, "//\n");
    fprintf(file, "// This file contains session specific info (that is info you\n");
    fprintf(file, "// want to keep between two Gmsh sessions). You are not supposed\n");
    fprintf(file, "// to edit it manually, but of course you can. This file will be\n");
    fprintf(file, "// entirely rewritten every time you quit Gmsh if the option \n");
    fprintf(file, "// 'General.SaveSession' is set.\n");
    fprintf(file, "//\n");
  }

  if((level & GMSH_OPTIONSRC) && file) {
    fprintf(file, "// Gmsh Option File\n");
    fprintf(file, "//\n");
    fprintf(file, "// This file contains configuration options (preferences) that\n");
    fprintf(file, "// are loaded each time Gmsh is launched. You can create this\n");
    fprintf(file, "// file by hand, or let Gmsh generate it for you (with\n");
    fprintf(file, "// 'File->Save Default Options'). This file can also be\n");
    fprintf(file, "// automatically saved every time you quit Gmsh if the option\n");
    fprintf(file, "// 'General.SaveOptions' is set.\n");
    fprintf(file, "//\n");
  }

  PrintOptionCategory(level, diff, help, "General options (strings)", file);
  PrintStringOptions(num, level, diff, help, GeneralOptions_String, "General.", file);
  PrintOptionCategory(level, diff, help, "General options (numbers)", file);
  PrintNumberOptions(num, level, diff, help, GeneralOptions_Number, "General.", file);
  PrintOptionCategory(level, diff, help, "General options (colors)", file);
  PrintColorOptions(num, level, diff, help, GeneralOptions_Color, "General.", file);

  PrintOptionCategory(level, diff, help, "Geometry options (strings)", file);
  PrintStringOptions(num, level, diff, help, GeometryOptions_String, "Geometry.", file);
  PrintOptionCategory(level, diff, help, "Geometry options (numbers)", file);
  PrintNumberOptions(num, level, diff, help, GeometryOptions_Number, "Geometry.", file);
  PrintOptionCategory(level, diff, help, "Geometry options (colors)", file);
  PrintColorOptions(num, level, diff, help, GeometryOptions_Color, "Geometry.", file);

  PrintOptionCategory(level, diff, help, "Mesh options (strings)", file);
  PrintStringOptions(num, level, diff, help, MeshOptions_String, "Mesh.", file);
  PrintOptionCategory(level, diff, help, "Mesh options (numbers)", file);
  PrintNumberOptions(num, level, diff, help, MeshOptions_Number, "Mesh.", file);
  PrintOptionCategory(level, diff, help, "Mesh options (colors)", file);
  PrintColorOptions(num, level, diff, help, MeshOptions_Color, "Mesh.", file);

  PrintOptionCategory(level, diff, help, "Solver options (strings)", file);
  PrintStringOptions(num, level, diff, help, SolverOptions_String, "Solver.", file);
  PrintOptionCategory(level, diff, help, "Solver options (numbers)", file);
  PrintNumberOptions(num, level, diff, help, SolverOptions_Number, "Solver.", file);
  PrintOptionCategory(level, diff, help, "Solver options (colors)", file);
  PrintColorOptions(num, level, diff, help, SolverOptions_Color, "Solver.", file);

  PrintOptionCategory(level, diff, help, "Post-processing options (strings)", file);
  PrintStringOptions(num, level, diff, help, PostProcessingOptions_String,
                     "PostProcessing.", file);
  PrintOptionCategory(level, diff, help, "Post-processing options (numbers)", file);
  PrintNumberOptions(num, level, diff, help, PostProcessingOptions_Number,
                     "PostProcessing.", file);
  PrintOptionCategory(level, diff, help, "Post-processing options (colors)", file);
  PrintColorOptions(num, level, diff, help, PostProcessingOptions_Color,
                    "PostProcessing.", file);

  if(level & GMSH_FULLRC) {
#if defined(HAVE_POST)
    for(unsigned int i = 0; i < PView::list.size(); i++) {
      char tmp[256];
      sprintf(tmp, "View[%d].", i);
      PrintOptionCategory(level, diff, help, "View options (strings)", file);
      PrintStringOptions(i, level, diff, help, ViewOptions_String, tmp, file);
      PrintOptionCategory(level, diff, help, "View options (numbers)", file);
      PrintNumberOptions(i, level, diff, help, ViewOptions_Number, tmp, file);
      PrintOptionCategory(level, diff, help, "View options (colors)", file);
      PrintColorOptions(i, level, diff, help, ViewOptions_Color, tmp, file);
      strcat(tmp, "ColorTable");
      PrintColorTable(i, diff, tmp, file);
    }
#endif
  }
  else if(level & GMSH_OPTIONSRC) {
    PrintOptionCategory(level, diff, help, "View options (strings)", file);
    PrintStringOptions(num, level, diff, help, ViewOptions_String, "View.", file);
    PrintOptionCategory(level, diff, help, "View options (numbers)", file);
    PrintNumberOptions(num, level, diff, help, ViewOptions_Number, "View.", file);
    PrintOptionCategory(level, diff, help, "View options (colors)", file);
    PrintColorOptions(num, level, diff, help, ViewOptions_Color, "View.", file);
    PrintColorTable(num, diff, "View.ColorTable", file);
  }

  PrintOptionCategory(level, diff, help, "Print options (strings)", file);
  PrintStringOptions(num, level, diff, help, PrintOptions_String, "Print.", file);
  PrintOptionCategory(level, diff, help, "Print options (numbers)", file);
  PrintNumberOptions(num, level, diff, help, PrintOptions_Number, "Print.", file);
  PrintOptionCategory(level, diff, help, "Print options (colors)", file);
  PrintColorOptions(num, level, diff, help, PrintOptions_Color, "Print.", file);

  if(filename) fclose(file);
}

void PrintOptionsDoc()
{
  const char *warn =
    "@c\n"
    "@c This file is generated automatically by running \"gmsh -doc\".\n"
    "@c Do not edit by hand!\n"
    "@c\n\n";

  FILE *file = fopen("opt_general.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_general.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(GeneralOptions_String, "General.", file);
  PrintNumberOptionsDoc(GeneralOptions_Number, "General.", file);
  PrintColorOptionsDoc(GeneralOptions_Color, "General.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_print.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_print.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(PrintOptions_String, "Print.", file);
  PrintNumberOptionsDoc(PrintOptions_Number, "Print.", file);
  PrintColorOptionsDoc(PrintOptions_Color, "Print.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_geometry.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_geometry.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(GeometryOptions_String, "Geometry.", file);
  PrintNumberOptionsDoc(GeometryOptions_Number, "Geometry.", file);
  PrintColorOptionsDoc(GeometryOptions_Color, "Geometry.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_mesh.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_mesh.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(MeshOptions_String, "Mesh.", file);
  PrintNumberOptionsDoc(MeshOptions_Number, "Mesh.", file);
  PrintColorOptionsDoc(MeshOptions_Color, "Mesh.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_solver.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_solver.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(SolverOptions_String, "Solver.", file);
  PrintNumberOptionsDoc(SolverOptions_Number, "Solver.", file);
  PrintColorOptionsDoc(SolverOptions_Color, "Solver.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

  file = fopen("opt_post.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_post.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(PostProcessingOptions_String, "PostProcessing.", file);
  PrintNumberOptionsDoc(PostProcessingOptions_Number, "PostProcessing.", file);
  PrintColorOptionsDoc(PostProcessingOptions_Color, "PostProcessing.", file);
  fprintf(file, "@end ftable\n");
  fclose(file);

#if defined(HAVE_POST)
  file = fopen("opt_view.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_view.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  PrintStringOptionsDoc(ViewOptions_String, "View.", file);
  PrintNumberOptionsDoc(ViewOptions_Number, "View.", file);
  PrintColorOptionsDoc(ViewOptions_Color, "View.", file);
  fprintf(file, "@item View.ColorTable\n");
  fprintf(file, "Color table used to draw the view@*\n");
  fprintf(file, "Saved in: @code{%s}\n\n",
          GetOptionSaveLevel(GMSH_FULLRC|GMSH_OPTIONSRC));
  fprintf(file, "@end ftable\n");
  fclose(file);
#endif

#if defined(HAVE_PLUGINS)
  file = fopen("opt_plugin.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_plugin.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  for(std::map<std::string, GMSH_Plugin*>::iterator it = PluginManager::
        instance()->begin(); it != PluginManager::instance()->end(); ++it) {
    GMSH_Plugin *p = it->second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN) {
      fprintf(file, "@item Plugin(%s)\n", p->getName().c_str());
      fprintf(file, "%s\n", p->getHelp().c_str());

      int m = p->getNbOptionsStr();
      if(m){
        fprintf(file, "String options:\n");
        fprintf(file, "@table @code\n");
        for(int i = 0; i < m; i++) {
          StringXString *sxs = p->getOptionStr(i);
          fprintf(file, "@item %s\n", sxs->str);
          fprintf(file, "Default value: @code{\"%s\"}\n", sxs->def.c_str());
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
#endif

#if defined(HAVE_MESH)
  file = fopen("opt_fields.texi", "w");
  if(!file) {
    Msg::Error("Unable to open file 'opt_fields.texi'");
    return;
  }
  fprintf(file, "%s@ftable @code\n", warn);
  FieldManager &fields = *GModel::current()->getFields();
  for(std::map<std::string, FieldFactory*>::iterator it = fields.map_type_name.begin();
      it != fields.map_type_name.end(); it++){
    fprintf(file, "@item %s\n", it->first.c_str());
    Field *f = (*it->second)();
    std::string field_description=f->getDescription();
    Sanitize_String_Texi(field_description);
    fprintf(file,"%s@*\n",field_description.c_str());
    if (!f->options.empty()) {
      fprintf(file, "Options:@*\n");
      fprintf(file, "@table @code\n");
      for(std::map<std::string, FieldOption*>::iterator it2 = f->options.begin();
          it2 != f->options.end(); it2++){
        fprintf(file, "@item %s\n", it2->first.c_str());
        std::string val;
        it2->second->getTextRepresentation(val);
        Sanitize_String_Texi(val);
        fprintf(file, "%s@*\ntype: %s@*\ndefault value: @code{%s}\n",
            it2->second->getDescription().c_str(),
            it2->second->getTypeName().c_str(), val.c_str());
      }
      fprintf(file, "@end table\n\n");
    }
    if (!f->callbacks.empty()) {
      fprintf(file, "Actions:@*\n");
      fprintf(file, "@table @code\n");
      for(std::map<std::string, FieldCallback*>::iterator it2 = f->callbacks.begin();
          it2 != f->callbacks.end(); it2++){
        fprintf(file, "@item %s\n", it2->first.c_str());
        fprintf(file, "%s@*\n", it2->second->getDescription().c_str());
      }
      fprintf(file, "@end table\n\n");
    }
  }
  fprintf(file, "@end ftable\n");
  fclose(file);
#endif
}

#define GET_VIEW(error_val)                             \
  PView *view = 0;                                      \
  PViewData *data = 0;                                  \
  PViewOptions *opt;                                    \
  if(PView::list.empty())                               \
    opt = &PViewOptions::reference;                     \
  else{                                                 \
    if(num < 0 || num >= (int)PView::list.size()){      \
      Msg::Warning("View[%d] does not exist", num);     \
      return (error_val);                               \
    }                                                   \
    view = PView::list[num];                            \
    data = view->getData();                             \
    opt = view->getOptions();                           \
  }

// String option routines

std::string opt_general_axes_label0(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->axesLabel[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[6]->value
      (CTX::instance()->axesLabel[0].c_str());
#endif
  return CTX::instance()->axesLabel[0];
}

std::string opt_general_axes_label1(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->axesLabel[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[7]->value
      (CTX::instance()->axesLabel[1].c_str());
#endif
  return CTX::instance()->axesLabel[1];
}

std::string opt_general_axes_label2(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->axesLabel[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[8]->value
      (CTX::instance()->axesLabel[2].c_str());
#endif
  return CTX::instance()->axesLabel[2];
}

std::string opt_general_axes_format0(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->axesFormat[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[3]->value
      (CTX::instance()->axesFormat[0].c_str());
#endif
  return CTX::instance()->axesFormat[0];
}

std::string opt_general_axes_format1(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->axesFormat[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[4]->value
      (CTX::instance()->axesFormat[1].c_str());
#endif
  return CTX::instance()->axesFormat[1];
}

std::string opt_general_axes_format2(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->axesFormat[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[5]->value
      (CTX::instance()->axesFormat[2].c_str());
#endif
  return CTX::instance()->axesFormat[2];
}

std::string opt_general_display(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->display = val;
  return CTX::instance()->display;
}

std::string opt_general_background_image_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->bgImageFileName = val;
  return CTX::instance()->bgImageFileName;
}

std::string opt_general_filename(OPT_ARGS_STR)
{
  return GModel::current()->getFileName();
}

std::string opt_general_default_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->defaultFileName = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[0]->value
      (CTX::instance()->defaultFileName.c_str());
#endif
  return CTX::instance()->defaultFileName;
}

std::string opt_general_tmp_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpFileName = val;
  return CTX::instance()->tmpFileName;
}

std::string opt_general_error_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->errorFileName = val;
  return CTX::instance()->errorFileName;
}

std::string opt_general_session_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->sessionFileName = val;
  return CTX::instance()->sessionFileName;
}

std::string opt_general_options_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->optionsFileName = val;
  return CTX::instance()->optionsFileName;
}

std::string opt_general_recent_file0(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->recentFiles[0] = val;
  return CTX::instance()->recentFiles[0];
}

std::string opt_general_recent_file1(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->recentFiles[1] = val;
  return CTX::instance()->recentFiles[1];
}

std::string opt_general_recent_file2(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->recentFiles[2] = val;
  return CTX::instance()->recentFiles[2];
}

std::string opt_general_recent_file3(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->recentFiles[3] = val;
  return CTX::instance()->recentFiles[3];
}

std::string opt_general_recent_file4(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->recentFiles[4] = val;
  return CTX::instance()->recentFiles[4];
}

std::string opt_general_editor(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->editor = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[1]->value
      (CTX::instance()->editor.c_str());
#endif
  return CTX::instance()->editor;
}

std::string opt_general_web_browser(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->webBrowser = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[2]->value
      (CTX::instance()->webBrowser.c_str());
#endif
  return CTX::instance()->webBrowser;
}

std::string opt_general_watch_file_pattern(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->watchFilePattern = val;
  return CTX::instance()->watchFilePattern;
}

std::string opt_general_gui_theme(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->guiTheme = val;
  return CTX::instance()->guiTheme;
}

std::string opt_general_graphics_font(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->glFont = val;
#if defined(HAVE_FLTK)
  int index = drawContext::global()->getFontIndex(CTX::instance()->glFont.c_str());
  if(action & GMSH_SET){
    CTX::instance()->glFont = drawContext::global()->getFontName(index);
    CTX::instance()->glFontEnum = drawContext::global()->getFontEnum(index);
  }
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.choice[1]->value(index);
  }
#endif
  return CTX::instance()->glFont;
}

std::string opt_general_graphics_font_title(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->glFontTitle = val;
#if defined(HAVE_FLTK)
  int index = drawContext::global()->getFontIndex(CTX::instance()->glFontTitle.c_str());
  if(action & GMSH_SET){
    CTX::instance()->glFontTitle = drawContext::global()->getFontName(index);
    CTX::instance()->glFontEnumTitle = drawContext::global()->getFontEnum(index);
  }
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.choice[6]->value(index);
  }
#endif
  return CTX::instance()->glFontTitle;
}

std::string opt_solver_socket_name(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.socketName = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.input[0]->value
      (CTX::instance()->solver.socketName.c_str());
#endif
  return CTX::instance()->solver.socketName;
}

std::string opt_solver_name(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.name[num] = val;
  return CTX::instance()->solver.name[num];
}

std::string opt_solver_name0(OPT_ARGS_STR)
{
  return opt_solver_name(0, action, val);
}

std::string opt_solver_name1(OPT_ARGS_STR)
{
  return opt_solver_name(1, action, val);
}

std::string opt_solver_name2(OPT_ARGS_STR)
{
  return opt_solver_name(2, action, val);
}

std::string opt_solver_name3(OPT_ARGS_STR)
{
  return opt_solver_name(3, action, val);
}

std::string opt_solver_name4(OPT_ARGS_STR)
{
  return opt_solver_name(4, action, val);
}

std::string opt_solver_executable(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.executable[num] = val;
  return CTX::instance()->solver.executable[num];
}

std::string opt_solver_executable0(OPT_ARGS_STR)
{
  return opt_solver_executable(0, action, val);
}

std::string opt_solver_executable1(OPT_ARGS_STR)
{
  return opt_solver_executable(1, action, val);
}

std::string opt_solver_executable2(OPT_ARGS_STR)
{
  return opt_solver_executable(2, action, val);
}

std::string opt_solver_executable3(OPT_ARGS_STR)
{
  return opt_solver_executable(3, action, val);
}

std::string opt_solver_executable4(OPT_ARGS_STR)
{
  return opt_solver_executable(4, action, val);
}

std::string opt_solver_remote_login(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.remoteLogin[num] = val;
  return CTX::instance()->solver.remoteLogin[num];
}

std::string opt_solver_remote_login0(OPT_ARGS_STR)
{
  return opt_solver_remote_login(0, action, val);
}

std::string opt_solver_remote_login1(OPT_ARGS_STR)
{
  return opt_solver_remote_login(1, action, val);
}

std::string opt_solver_remote_login2(OPT_ARGS_STR)
{
  return opt_solver_remote_login(2, action, val);
}

std::string opt_solver_remote_login3(OPT_ARGS_STR)
{
  return opt_solver_remote_login(3, action, val);
}

std::string opt_solver_remote_login4(OPT_ARGS_STR)
{
  return opt_solver_remote_login(4, action, val);
}

#if defined(HAVE_FLTK)
int _gui_action_valid(int action, int num)
{
  if(!FlGui::available()) return 0;
  return (action & GMSH_GUI) && (num == FlGui::instance()->options->view.index);
}
#endif

std::string opt_view_name(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(!data) return "";
  if(action & GMSH_SET) {
    data->setName(val);
#if defined(HAVE_FLTK)
    // change name in GUI for the view and its aliases
    if(FlGui::available()){
      for(int i = 0; i < (int)PView::list.size(); i++){
        if((i == num ||
            PView::list[i]->getAliasOf() == view->getNum() ||
            PView::list[i]->getNum() == view->getAliasOf()) &&
           i < (int)FlGui::instance()->menu->toggle.size()) {
          FlGui::instance()->menu->toggle[i]->copy_label(data->getName().c_str());
          FlGui::instance()->menu->toggle[i]->redraw();
        }
      }
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.input[0]->value(data->getName().c_str());
  }
#endif
  return data->getName();
#else
  return "";
#endif
}

std::string opt_view_format(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->format = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[1]->value(opt->format.c_str());
#endif
  return opt->format;
#else
  return "";
#endif
}

std::string opt_view_filename(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(!data) return "";
  return data->getFileName();
#else
  return "";
#endif
}

std::string opt_view_axes_label0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->axesLabel[0] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[10]->value(opt->axesLabel[0].c_str());
#endif
  return opt->axesLabel[0];
#else
  return "";
#endif
}

std::string opt_view_axes_label1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->axesLabel[1] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[11]->value(opt->axesLabel[1].c_str());
#endif
  return opt->axesLabel[1];
#else
  return "";
#endif
}

std::string opt_view_axes_label2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->axesLabel[2] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[12]->value(opt->axesLabel[2].c_str());
#endif
  return opt->axesLabel[2];
#else
  return "";
#endif
}

std::string opt_view_axes_format0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->axesFormat[0] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[7]->value(opt->axesFormat[0].c_str());
#endif
  return opt->axesFormat[0];
#else
  return "";
#endif
}

std::string opt_view_axes_format1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->axesFormat[1] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[8]->value(opt->axesFormat[1].c_str());
#endif
  return opt->axesFormat[1];
#else
  return "";
#endif
}

std::string opt_view_axes_format2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->axesFormat[2] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[9]->value(opt->axesFormat[2].c_str());
#endif
  return opt->axesFormat[2];
#else
  return "";
#endif
}

std::string opt_view_gen_raise0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->genRaiseX = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[4]->value(opt->genRaiseX.c_str());
#endif
  return opt->genRaiseX;
#else
  return "";
#endif
}

std::string opt_view_gen_raise1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->genRaiseY = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[5]->value(opt->genRaiseY.c_str());
#endif
  return opt->genRaiseY;
#else
  return "";
#endif
}

std::string opt_view_gen_raise2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->genRaiseZ = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[6]->value(opt->genRaiseZ.c_str());
#endif
  return opt->genRaiseZ;
#else
  return "";
#endif
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

void _string2stipple(std::string str, int &repeat, int &pattern)
{
  // "n*0xabcd"
  if(str.size() < 8){
    repeat = 1;
    pattern = 0xFFFF;
  }
  else if(str[1] != '*' || str[2] != '0' || str[3] != 'x'){
    // bad format
    repeat = 1;
    pattern = 0xFFFF;
  }
  else{
    repeat = (int)str[0] - '0';
    pattern = 16 * 16 * 16 * _h2d(str[4]) + 16 * 16 * _h2d(str[5]) +
      16 * _h2d(str[6]) + _h2d(str[7]);
  }
}

std::string opt_view_stipple0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[0] = val;
    _string2stipple(opt->stippleString[0], opt->stipple[0][0], opt->stipple[0][1]);
  }
  return opt->stippleString[0];
#else
  return "";
#endif
}

std::string opt_view_stipple1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[1] = val;
    _string2stipple(opt->stippleString[1], opt->stipple[1][0], opt->stipple[1][1]);
  }
  return opt->stippleString[1];
#else
  return "";
#endif
}

std::string opt_view_stipple2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[2] = val;
    _string2stipple(opt->stippleString[2], opt->stipple[2][0], opt->stipple[2][1]);
  }
  return opt->stippleString[2];
#else
  return "";
#endif
}

std::string opt_view_stipple3(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[3] = val;
    _string2stipple(opt->stippleString[3], opt->stipple[3][0], opt->stipple[3][1]);
  }
  return opt->stippleString[3];
#else
  return "";
#endif
}

std::string opt_view_stipple4(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[4] = val;
    _string2stipple(opt->stippleString[4], opt->stipple[4][0], opt->stipple[4][1]);
  }
  return opt->stippleString[4];
#else
  return "";
#endif
}

std::string opt_view_stipple5(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[5] = val;
    _string2stipple(opt->stippleString[5], opt->stipple[5][0], opt->stipple[5][1]);
  }
  return opt->stippleString[5];
#else
  return "";
#endif
}

std::string opt_view_stipple6(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[6] = val;
    _string2stipple(opt->stippleString[6], opt->stipple[6][0], opt->stipple[6][1]);
  }
  return opt->stippleString[6];
#else
  return "";
#endif
}

std::string opt_view_stipple7(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[7] = val;
    _string2stipple(opt->stippleString[7], opt->stipple[7][0], opt->stipple[7][1]);
  }
  return opt->stippleString[7];
#else
  return "";
#endif
}

std::string opt_view_stipple8(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[8] = val;
    _string2stipple(opt->stippleString[8], opt->stipple[8][0], opt->stipple[8][1]);
  }
  return opt->stippleString[8];
#else
  return "";
#endif
}

std::string opt_view_stipple9(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEW("");
  if(action & GMSH_SET) {
    opt->stippleString[9] = val;
    _string2stipple(opt->stippleString[9], opt->stipple[9][0], opt->stipple[9][1]);
  }
  return opt->stippleString[9];
#else
  return "";
#endif
}

// Numeric option routines

double opt_general_initial_context(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->initialContext = (int)val;
  return CTX::instance()->initialContext;
}

double opt_general_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fontSize = (int)val;
  return CTX::instance()->fontSize;
}

double opt_general_graphics_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->glFontSize = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[12]->value
      (CTX::instance()->glFontSize);
#endif
  return CTX::instance()->glFontSize;
}

double opt_general_graphics_fontsize_title(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->glFontSizeTitle = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[28]->value
      (CTX::instance()->glFontSizeTitle);
#endif
  return CTX::instance()->glFontSizeTitle;
}

double opt_general_polygon_offset_always(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->polygonOffsetAlways = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[4]->value
      (CTX::instance()->polygonOffsetAlways);
#endif
  return CTX::instance()->polygonOffsetAlways;
}

double opt_general_polygon_offset_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->polygonOffsetFactor = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[15]->value
      (CTX::instance()->polygonOffsetFactor);
#endif
  return CTX::instance()->polygonOffsetFactor;
}

double opt_general_polygon_offset_units(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->polygonOffsetUnits = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[16]->value
      (CTX::instance()->polygonOffsetUnits);
#endif
  return CTX::instance()->polygonOffsetUnits;
}

double opt_general_graphics_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->glPosition[0] = (int)val;
  return CTX::instance()->glPosition[0];
}

double opt_general_graphics_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->glPosition[1] = (int)val;
  return CTX::instance()->glPosition[1];
}

double opt_general_graphics_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->glSize[0] = (int)val;
    if(CTX::instance()->glSize[0] <= 0) CTX::instance()->glSize[0] = 600;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET){
      FlGui::instance()->graph[0]->win->size
        (CTX::instance()->glSize[0],
         FlGui::instance()->graph[0]->win->h());
      // workaround resizing bug on Mac
      FlGui::instance()->graph[0]->win->size_range
        (FlGui::instance()->graph[0]->minWidth, FlGui::instance()->graph[0]->minHeight);
    }
  }
#endif
  return CTX::instance()->glSize[0];
}

double opt_general_graphics_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->glSize[1] = (int)val;
    if(CTX::instance()->glSize[1] <= 0) CTX::instance()->glSize[1] = 600;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET){
      FlGui::instance()->graph[0]->win->size
        (FlGui::instance()->graph[0]->win->w(),
         FlGui::instance()->graph[0]->bottom->h() + CTX::instance()->glSize[1]);
      // workaround resizing bug on Mac
      FlGui::instance()->graph[0]->win->size_range
        (FlGui::instance()->graph[0]->minWidth, FlGui::instance()->graph[0]->minHeight);
    }
  }
#endif
  return CTX::instance()->glSize[1];
}

double opt_general_menu_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->menuPosition[0] = (int)val;
  return CTX::instance()->menuPosition[0];
}

double opt_general_menu_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->menuPosition[1] = (int)val;
  return CTX::instance()->menuPosition[1];
}

double opt_general_solver_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solverPosition[0] = (int)val;
  return CTX::instance()->solverPosition[0];
}

double opt_general_solver_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solverPosition[1] = (int)val;
  return CTX::instance()->solverPosition[1];
}

double opt_general_context_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->ctxPosition[0] = (int)val;
  return CTX::instance()->ctxPosition[0];
}

double opt_general_context_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->ctxPosition[1] = (int)val;
  return CTX::instance()->ctxPosition[1];
}

double opt_general_file_chooser_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fileChooserPosition[0] = (int)val;
  return CTX::instance()->fileChooserPosition[0];
}

double opt_general_file_chooser_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fileChooserPosition[1] = (int)val;
  return CTX::instance()->fileChooserPosition[1];
}

double opt_general_system_menu_bar(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->systemMenuBar = (int)val;
  return CTX::instance()->systemMenuBar;
}

double opt_general_message_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->msgSize = (int)val;
    if(CTX::instance()->msgSize < 0) CTX::instance()->msgSize = 0;
  }
  return CTX::instance()->msgSize;
}

double opt_general_option_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->optPosition[0] = (int)val;
  return CTX::instance()->optPosition[0];
}

double opt_general_option_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->optPosition[1] = (int)val;
  return CTX::instance()->optPosition[1];
}

double opt_general_plugin_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->pluginPosition[0] = (int)val;
  return CTX::instance()->pluginPosition[0];
}

double opt_general_plugin_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->pluginPosition[1] = (int)val;
  return CTX::instance()->pluginPosition[1];
}

double opt_general_plugin_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->pluginSize[0] = (int)val;
  return CTX::instance()->pluginSize[0];
}

double opt_general_plugin_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->pluginSize[1] = (int)val;
  return CTX::instance()->pluginSize[1];
}

double opt_general_field_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fieldPosition[0] = (int)val;
  return CTX::instance()->fieldPosition[0];
}

double opt_general_field_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fieldPosition[1] = (int)val;
  return CTX::instance()->fieldPosition[1];
}

double opt_general_field_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fieldSize[0] = (int)val;
  return CTX::instance()->fieldSize[0];
}

double opt_general_field_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fieldSize[1] = (int)val;
  return CTX::instance()->fieldSize[1];
}

double opt_general_statistics_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->statPosition[0] = (int)val;
  return CTX::instance()->statPosition[0];
}

double opt_general_statistics_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->statPosition[1] = (int)val;
  return CTX::instance()->statPosition[1];
}

double opt_general_visibility_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->visPosition[0] = (int)val;
  return CTX::instance()->visPosition[0];
}

double opt_general_visibility_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->visPosition[1] = (int)val;
  return CTX::instance()->visPosition[1];
}

double opt_general_clip_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPosition[0] = (int)val;
  return CTX::instance()->clipPosition[0];
}

double opt_general_clip_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPosition[1] = (int)val;
  return CTX::instance()->clipPosition[1];
}

double opt_general_manip_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->manipPosition[0] = (int)val;
  return CTX::instance()->manipPosition[0];
}

double opt_general_manip_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->manipPosition[1] = (int)val;
  return CTX::instance()->manipPosition[1];
}

double opt_general_session_save(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->sessionSave = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[8]->value
      (CTX::instance()->sessionSave);
#endif
  return CTX::instance()->sessionSave;
}

double opt_general_options_save(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->optionsSave = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[9]->value
      (CTX::instance()->optionsSave ? 1 : 0);
#endif
  return CTX::instance()->optionsSave;
}

double opt_general_confirm_overwrite(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->confirmOverwrite = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[14]->value
      (CTX::instance()->confirmOverwrite);
#endif
  return CTX::instance()->confirmOverwrite;
}

double opt_general_rotation0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpRotation[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->r[0] = val;
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->r[0];
  }
#endif
  return CTX::instance()->tmpRotation[0];
}

double opt_general_rotation1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpRotation[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->r[1] = val;
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->r[1];
  }
#endif
  return CTX::instance()->tmpRotation[1];
}

double opt_general_rotation2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpRotation[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->r[2] = val;
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->r[2];
  }
#endif
  return CTX::instance()->tmpRotation[2];
}

double opt_general_rotation_center0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->rotationCenter[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[8]->value
      (CTX::instance()->rotationCenter[0]);
#endif
  return CTX::instance()->rotationCenter[0];
}

double opt_general_rotation_center1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->rotationCenter[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[9]->value
      (CTX::instance()->rotationCenter[1]);
#endif
  return CTX::instance()->rotationCenter[1];
}

double opt_general_rotation_center2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->rotationCenter[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[10]->value
      (CTX::instance()->rotationCenter[2]);
#endif
  return CTX::instance()->rotationCenter[2];
}

double opt_general_quaternion0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpQuaternion[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[0] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[0];
  }
#endif
  return CTX::instance()->tmpQuaternion[0];
}

double opt_general_quaternion1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpQuaternion[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[1] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[1];
  }
#endif
  return CTX::instance()->tmpQuaternion[1];
}

double opt_general_quaternion2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpQuaternion[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[2] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[2];
  }
#endif
  return CTX::instance()->tmpQuaternion[2];
}

double opt_general_quaternion3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpQuaternion[3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[3] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->quaternion[3];
  }
#endif
  return CTX::instance()->tmpQuaternion[3];
}

double opt_general_translation0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpTranslation[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->t[0] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->t[0];
  }
#endif
  return CTX::instance()->tmpTranslation[0];
}

double opt_general_translation1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpTranslation[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->t[1] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->t[1];
  }
#endif
  return CTX::instance()->tmpTranslation[1];
}

double opt_general_translation2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpTranslation[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->t[2] = val;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->t[2];
  }
#endif
  return CTX::instance()->tmpTranslation[2];
}

double opt_general_scale0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpScale[0] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->s[0] = val ? val : 1.0;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->s[0];
  }
#endif
  return CTX::instance()->tmpScale[0];
}

double opt_general_scale1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpScale[1] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->s[1] = val ? val : 1.0;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->s[1];
  }
#endif
  return CTX::instance()->tmpScale[1];
}

double opt_general_scale2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->tmpScale[2] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_SET)
      FlGui::instance()->graph[0]->gl[0]->getDrawContext()->s[2] = val ? val : 1.0;
    if(action & GMSH_GUI)
      FlGui::instance()->manip->update();
    return FlGui::instance()->graph[0]->gl[0]->getDrawContext()->s[2];
  }
#endif
  return CTX::instance()->tmpScale[2];
}

double opt_general_clip_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    // should NEVER be zero (or negative)
    if(val < 0.01)
      CTX::instance()->clipFactor = 0.01;
    else
      CTX::instance()->clipFactor = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[14]->value
      (CTX::instance()->clipFactor);
#endif
  return CTX::instance()->clipFactor;
}

double opt_general_display_border_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->displayBorderFactor = val;
  return CTX::instance()->displayBorderFactor;
}

double opt_general_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->pointSize = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[6]->value
      (CTX::instance()->pointSize);
#endif
  return CTX::instance()->pointSize;
}

double opt_general_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lineWidth = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[7]->value
      (CTX::instance()->lineWidth);
#endif
  return CTX::instance()->lineWidth;
}

double opt_general_shine(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->shine = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[1]->value
      (CTX::instance()->shine);
#endif
  return CTX::instance()->shine;
}

double opt_general_shine_exponent(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->shineExponent = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[0]->value
      (CTX::instance()->shineExponent);
#endif
  return CTX::instance()->shineExponent;
}

double opt_general_verbosity(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    Msg::SetVerbosity((int)val);
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[5]->value
      (Msg::GetVerbosity());
#endif
  return Msg::GetVerbosity();
}

double opt_general_nopopup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->noPopup = (int)val;
  return CTX::instance()->noPopup;
}

double opt_general_non_modal_windows(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->nonModalWindows = (int)val;
  return CTX::instance()->nonModalWindows;
}

double opt_general_terminal(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->terminal = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[7]->value
      (CTX::instance()->terminal);
#endif
  return CTX::instance()->terminal;
}

double opt_general_tooltips(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->tooltips = (int)val;
#if defined(HAVE_FLTK)
    if(CTX::instance()->tooltips)
      Fl_Tooltip::enable();
    else
      Fl_Tooltip::disable();
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[13]->value
      (CTX::instance()->tooltips);
#endif
  return CTX::instance()->tooltips;
}

double opt_general_orthographic(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->ortho = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->ortho){
      FlGui::instance()->options->general.choice[2]->value(0);
      if(FlGui::available())
        Msg::StatusBar(2, false, "Orthographic projection");
    }
    else{
      FlGui::instance()->options->general.choice[2]->value(1);
      if(FlGui::available())
        Msg::StatusBar(2, false, "Perspective projection");
    }
  }
#endif
  return CTX::instance()->ortho;
}

double opt_general_mouse_selection(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mouseSelection = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mouseSelection){
      if(FlGui::available())
        Msg::StatusBar(2, false, "Mouse selection ON");
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->butt[9]->color(FL_BACKGROUND_COLOR);
    }
    else{
      if(FlGui::available())
        Msg::StatusBar(2, false, "Mouse selection OFF");
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->butt[9]->color(FL_RED);
    }
    for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->butt[9]->redraw();
  }
#endif
  return CTX::instance()->mouseSelection;
}

double opt_general_mouse_hover_meshes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mouseHoverMeshes = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[11]->value
      (CTX::instance()->mouseHoverMeshes);
#endif
  return CTX::instance()->mouseHoverMeshes;
}

double opt_general_fast_redraw(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->fastRedraw = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.butt[2]->value
      (CTX::instance()->fastRedraw);
    FlGui::instance()->options->activate("fast_redraw");
  }
#endif
  return CTX::instance()->fastRedraw;
}

double opt_general_draw_bounding_box(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->drawBBox = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[6]->value
      (CTX::instance()->drawBBox);
#endif
  return CTX::instance()->drawBBox;
}

double opt_general_xmin(OPT_ARGS_NUM)
{
  SBoundingBox3d bb = GModel::current()->bounds();
  return bb.empty() ? 0. : bb.min().x();
}

double opt_general_xmax(OPT_ARGS_NUM)
{
  SBoundingBox3d bb = GModel::current()->bounds();
  return bb.empty() ? 0. : bb.max().x();
}

double opt_general_ymin(OPT_ARGS_NUM)
{
  SBoundingBox3d bb = GModel::current()->bounds();
  return bb.empty() ? 0. : bb.min().y();
}

double opt_general_ymax(OPT_ARGS_NUM)
{
  SBoundingBox3d bb = GModel::current()->bounds();
  return bb.empty() ? 0. : bb.max().y();
}

double opt_general_zmin(OPT_ARGS_NUM)
{
  SBoundingBox3d bb = GModel::current()->bounds();
  return bb.empty() ? 0. : bb.min().z();
}

double opt_general_zmax(OPT_ARGS_NUM)
{
  SBoundingBox3d bb = GModel::current()->bounds();
  return bb.empty() ? 0. : bb.max().z();
}

double opt_general_axes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->axes = (int)val;
    if(CTX::instance()->axes < 0 || CTX::instance()->axes > 5)
      CTX::instance()->axes = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.choice[4]->value
      (CTX::instance()->axes);
    FlGui::instance()->options->activate("general_axes");
  }
#endif
  return CTX::instance()->axes;
}

double opt_general_axes_mikado(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->axesMikado = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[16]->value
      (CTX::instance()->axesMikado);
#endif
  return CTX::instance()->axesMikado;
}

double opt_general_axes_auto_position(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesAutoPosition = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.butt[0]->value
      (CTX::instance()->axesAutoPosition);
    FlGui::instance()->options->activate("general_axes_auto");
  }
#endif
  return CTX::instance()->axesAutoPosition;
}

double opt_general_axes_tics0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesTics[0] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[17]->value
      (CTX::instance()->axesTics[0]);
#endif
  return CTX::instance()->axesTics[0];
}

double opt_general_axes_tics1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesTics[1] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[18]->value
      (CTX::instance()->axesTics[1]);
#endif
  return CTX::instance()->axesTics[1];
}

double opt_general_axes_tics2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesTics[2] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[19]->value
      (CTX::instance()->axesTics[2]);
#endif
  return CTX::instance()->axesTics[2];
}

double opt_general_axes_xmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesPosition[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[20]->value
      (CTX::instance()->axesPosition[0]);
#endif
  return CTX::instance()->axesPosition[0];
}

double opt_general_axes_xmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesPosition[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[23]->value
      (CTX::instance()->axesPosition[1]);
#endif
  return CTX::instance()->axesPosition[1];
}

double opt_general_axes_ymin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesPosition[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[21]->value
      (CTX::instance()->axesPosition[2]);
#endif
  return CTX::instance()->axesPosition[2];
}

double opt_general_axes_ymax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesPosition[3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[24]->value
      (CTX::instance()->axesPosition[3]);
#endif
  return CTX::instance()->axesPosition[3];
}

double opt_general_axes_zmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesPosition[4] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[22]->value
      (CTX::instance()->axesPosition[4]);
#endif
  return CTX::instance()->axesPosition[4];
}

double opt_general_axes_zmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->axesPosition[5] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[25]->value
      (CTX::instance()->axesPosition[5]);
#endif
  return CTX::instance()->axesPosition[5];
}

double opt_general_small_axes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->smallAxes = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.butt[1]->value
      (CTX::instance()->smallAxes);
    FlGui::instance()->options->activate("general_small_axes");
  }
#endif
  return CTX::instance()->smallAxes;
}

double opt_general_small_axes_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->smallAxesPos[0] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[26]->value
      (CTX::instance()->smallAxesPos[0]);
#endif
  return CTX::instance()->smallAxesPos[0];
}

double opt_general_small_axes_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->smallAxesPos[1] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[27]->value
      (CTX::instance()->smallAxesPos[1]);
#endif
  return CTX::instance()->smallAxesPos[1];
}

double opt_general_small_axes_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->smallAxesSize = (int)val;
  return CTX::instance()->smallAxesSize;
}

double opt_general_quadric_subdivisions(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->quadricSubdivisions = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_GUI)
      FlGui::instance()->options->general.value[11]->value
        (CTX::instance()->quadricSubdivisions);
  }
#endif
  return CTX::instance()->quadricSubdivisions;
}

double opt_general_double_buffer(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->db = (int)val;
#if defined(HAVE_FLTK)
    if(FlGui::available()) {
      int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
      if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
        for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->mode(mode);
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[3]->value
      (CTX::instance()->db);
#endif
  return CTX::instance()->db;
}

double opt_general_antialiasing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->antialiasing = (int)val;
#if defined(HAVE_FLTK)
    if(FlGui::available()) {
      int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
      if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
        for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->mode(mode);
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[12]->value
      (CTX::instance()->antialiasing);
#endif
  return CTX::instance()->antialiasing;
}

double opt_general_alpha_blending(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->alpha = (int)val;
  return CTX::instance()->alpha;
}

double opt_general_vector_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->vectorType = (int)val;
    if(CTX::instance()->vectorType < 1 || CTX::instance()->vectorType > 4)
      CTX::instance()->vectorType = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.choice[0]->value
      (CTX::instance()->vectorType - 1);
  }
#endif
  return CTX::instance()->vectorType;
}

double opt_general_arrow_head_radius(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX::instance()->arrowRelHeadRadius = val;
  }
  return CTX::instance()->arrowRelHeadRadius;
}

double opt_general_arrow_stem_length(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX::instance()->arrowRelStemLength = val;
  }
  return CTX::instance()->arrowRelStemLength;
}

double opt_general_arrow_stem_radius(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX::instance()->arrowRelStemRadius = val;
  }
  return CTX::instance()->arrowRelStemRadius;
}

double opt_general_color_scheme(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->colorScheme = (int)val;
    if(CTX::instance()->colorScheme > 2)
      CTX::instance()->colorScheme = 0;
    SetDefaultColorOptions(0, GeneralOptions_Color);
    SetDefaultColorOptions(0, GeometryOptions_Color);
    SetDefaultColorOptions(0, MeshOptions_Color);
    SetDefaultColorOptions(0, SolverOptions_Color);
    SetDefaultColorOptions(0, PostProcessingOptions_Color);
#if defined(HAVE_POST)
    for(unsigned int i = 0; i < PView::list.size(); i++)
      SetDefaultColorOptions(i, ViewOptions_Color);
#endif
    SetDefaultColorOptions(0, PrintOptions_Color);

    SetColorOptionsGUI(0, GeneralOptions_Color);
    SetColorOptionsGUI(0, GeometryOptions_Color);
    SetColorOptionsGUI(0, MeshOptions_Color);
    SetColorOptionsGUI(0, SolverOptions_Color);
    SetColorOptionsGUI(0, PostProcessingOptions_Color);
#if defined(HAVE_POST)
    for(unsigned int i = 0; i < PView::list.size(); i++)
      SetColorOptionsGUI(i, ViewOptions_Color);
#endif
    SetColorOptionsGUI(0, PrintOptions_Color);

#if defined(HAVE_POST)
    // horrible trick so that opt_view_XXX will act on the reference view
    std::vector<PView*> tmp = PView::list;
    PView::list.clear();
    SetDefaultColorOptions(0, ViewOptions_Color);
    PView::list = tmp;
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.choice[3]->value
      (CTX::instance()->colorScheme);
#endif
  return CTX::instance()->colorScheme;
}

double opt_general_background_gradient(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->bgGradient = (int)val;
    if(CTX::instance()->bgGradient < 0 || CTX::instance()->bgGradient > 3)
      CTX::instance()->bgGradient = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.choice[5]->value
      (CTX::instance()->bgGradient);
#endif
  return CTX::instance()->bgGradient;
}

double opt_general_background_image_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->bgImagePosition[0] = val;
  return CTX::instance()->bgImagePosition[0];
}

double opt_general_background_image_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->bgImagePosition[1] = val;
  return CTX::instance()->bgImagePosition[1];
}

double opt_general_trackball(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->useTrackball = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[5]->value
      (CTX::instance()->useTrackball);
#endif
  return CTX::instance()->useTrackball;
}

double opt_general_trackball_hyperbolic_sheet(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->trackballHyperbolicSheet = (int)val;
  return CTX::instance()->trackballHyperbolicSheet;
}

double opt_general_rotation_center_cg(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->rotationCenterCg = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.butt[15]->value
      (CTX::instance()->rotationCenterCg);
    FlGui::instance()->options->activate("rotation_center");
  }
#endif
  return CTX::instance()->rotationCenterCg;
}

double opt_general_zoom_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->zoomFactor = val;
  return CTX::instance()->zoomFactor;
}

double opt_general_expert_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->expertMode = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[10]->value
      (CTX::instance()->expertMode);
#endif
  return CTX::instance()->expertMode;
}

double opt_general_stereo_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->stereo = (int)val;
  if (CTX::instance()->stereo) // when stereo mode is active camera mode is obligatory
    opt_general_camera_mode(num, action, 1.);
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[17]->value(CTX::instance()->stereo);
#endif
  return CTX::instance()->stereo ;
}

double opt_general_eye_sep_ratio(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->eye_sep_ratio =  (double)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[29]->value
      (CTX::instance()->eye_sep_ratio) ;
#endif
  return CTX::instance()->eye_sep_ratio ;
}

double opt_general_focallength_ratio(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->focallength_ratio = (double) val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[30]->value
      (CTX::instance()->focallength_ratio) ;
#endif
  return CTX::instance()->focallength_ratio ;
}

double opt_general_camera_aperture(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->camera_aperture = (double)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[31]->value
      (CTX::instance()->camera_aperture);
#endif
  return CTX::instance()->camera_aperture;
}

double opt_general_camera_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->camera = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.butt[18]->value
      (CTX::instance()->camera);
    FlGui::instance()->options->activate("general_camera");
  }
#endif
  return CTX::instance()->camera ;
}

double opt_general_clip0a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[0][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][0];
}

double opt_general_clip0b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[0][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][1];
}

double opt_general_clip0c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[0][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][2];
}

double opt_general_clip0d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[0][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][3];
}

double opt_general_clip1a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[1][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][0];
}

double opt_general_clip1b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[1][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][1];
}

double opt_general_clip1c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[1][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][2];
}

double opt_general_clip1d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[1][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][3];
}

double opt_general_clip2a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[2][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][0];
}

double opt_general_clip2b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[2][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][1];
}

double opt_general_clip2c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[2][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][2];
}

double opt_general_clip2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[2][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][3];
}

double opt_general_clip3a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[3][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][0];
}

double opt_general_clip3b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[3][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][1];
}

double opt_general_clip3c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[3][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][2];
}

double opt_general_clip3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[3][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][3];
}

double opt_general_clip4a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[4][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][0];
}

double opt_general_clip4b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[4][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][1];
}

double opt_general_clip4c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[4][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][2];
}

double opt_general_clip4d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[4][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][3];
}

double opt_general_clip5a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[5][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][0];
}

double opt_general_clip5b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[5][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][1];
}

double opt_general_clip5c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[5][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][2];
}

double opt_general_clip5d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipPlane[5][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][3];
}

double opt_general_clip_whole_elements(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipWholeElements = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->clipping->butt[0]->value
      (CTX::instance()->clipWholeElements);
    FlGui::instance()->options->activate("clip_whole_elements");
  }
#endif
  return CTX::instance()->clipWholeElements;
}

double opt_general_clip_only_draw_intersecting_volume(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipOnlyDrawIntersectingVolume = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->butt[1]->value
      (CTX::instance()->clipOnlyDrawIntersectingVolume);
#endif
  return CTX::instance()->clipOnlyDrawIntersectingVolume;
}

double opt_general_clip_only_volume(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->clipOnlyVolume = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->butt[2]->value
      (CTX::instance()->clipOnlyVolume);
#endif
  return CTX::instance()->clipOnlyVolume;
}

double opt_general_light0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->light[0] = (int)val;
  return CTX::instance()->light[0];
}

double opt_general_light00(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[0][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.value[2]->value
      (CTX::instance()->lightPosition[0][0]);
    FlGui::instance()->options->general.sphere->setValue
      (CTX::instance()->lightPosition[0][0],
       CTX::instance()->lightPosition[0][1],
       CTX::instance()->lightPosition[0][2]);
  }
#endif
  return CTX::instance()->lightPosition[0][0];
}

double opt_general_light01(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[0][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.value[3]->value
      (CTX::instance()->lightPosition[0][1]);
    FlGui::instance()->options->general.sphere->setValue
      (CTX::instance()->lightPosition[0][0],
       CTX::instance()->lightPosition[0][1],
       CTX::instance()->lightPosition[0][2]);
  }
#endif
  return CTX::instance()->lightPosition[0][1];
}

double opt_general_light02(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[0][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.value[4]->value
      (CTX::instance()->lightPosition[0][2]);
    FlGui::instance()->options->general.sphere->setValue
      (CTX::instance()->lightPosition[0][0],
       CTX::instance()->lightPosition[0][1],
       CTX::instance()->lightPosition[0][2]);
  }
#endif
  return CTX::instance()->lightPosition[0][2];
}

double opt_general_light03(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[0][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[13]->value
      (CTX::instance()->lightPosition[0][3]);
#endif
  return CTX::instance()->lightPosition[0][3];
}

double opt_general_light1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->light[1] = (int)val;
  return CTX::instance()->light[1];
}

double opt_general_light10(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[1][0] = val;
  return CTX::instance()->lightPosition[1][0];
}

double opt_general_light11(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[1][1] = val;
  return CTX::instance()->lightPosition[1][1];
}

double opt_general_light12(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[1][2] = val;
  return CTX::instance()->lightPosition[1][2];
}

double opt_general_light13(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[1][3] = val;
  return CTX::instance()->lightPosition[1][3];
}

double opt_general_light2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->light[2] = (int)val;
  return CTX::instance()->light[2];
}

double opt_general_light20(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[2][0] = val;
  return CTX::instance()->lightPosition[2][0];
}

double opt_general_light21(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[2][1] = val;
  return CTX::instance()->lightPosition[2][1];
}

double opt_general_light22(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[2][2] = val;
  return CTX::instance()->lightPosition[2][2];
}

double opt_general_light23(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[2][3] = val;
  return CTX::instance()->lightPosition[2][3];
}

double opt_general_light3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->light[3] = (int)val;
  return CTX::instance()->light[3];
}

double opt_general_light30(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[3][0] = val;
  return CTX::instance()->lightPosition[3][0];
}

double opt_general_light31(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[3][1] = val;
  return CTX::instance()->lightPosition[3][1];
}

double opt_general_light32(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[3][2] = val;
  return CTX::instance()->lightPosition[3][2];
}

double opt_general_light33(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[3][3] = val;
  return CTX::instance()->lightPosition[3][3];
}

double opt_general_light4(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->light[4] = (int)val;
  return CTX::instance()->light[4];
}

double opt_general_light40(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[4][0] = val;
  return CTX::instance()->lightPosition[4][0];
}

double opt_general_light41(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[4][1] = val;
  return CTX::instance()->lightPosition[4][1];
}

double opt_general_light42(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[4][2] = val;
  return CTX::instance()->lightPosition[4][2];
}

double opt_general_light43(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[4][3] = val;
  return CTX::instance()->lightPosition[4][3];
}

double opt_general_light5(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->light[5] = (int)val;
  return CTX::instance()->light[5];
}

double opt_general_light50(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[5][0] = val;
  return CTX::instance()->lightPosition[5][0];
}

double opt_general_light51(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[5][1] = val;
  return CTX::instance()->lightPosition[5][1];
}

double opt_general_light52(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[5][2] = val;
  return CTX::instance()->lightPosition[5][2];
}

double opt_general_light53(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->lightPosition[5][3] = val;
  return CTX::instance()->lightPosition[5][3];
}

double opt_geometry_transform(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->geom.useTransform = (int)val;
    if(CTX::instance()->geom.useTransform < 0 ||
       CTX::instance()->geom.useTransform > 1)
      CTX::instance()->geom.useTransform = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_GUI)
      FlGui::instance()->options->geo.choice[3]->value
        (CTX::instance()->geom.useTransform);
    if(action & GMSH_SET){
      if(CTX::instance()->geom.useTransform == 1){
        drawTransform *tr = new drawTransformScaled
          (CTX::instance()->geom.transform, CTX::instance()->geom.offset);
        FlGui::instance()->graph[0]->gl[0]->getDrawContext()->setTransform(tr);
      }
      else{
        drawTransform *tr = FlGui::instance()->graph[0]->gl[0]->
          getDrawContext()->getTransform();
        FlGui::instance()->graph[0]->gl[0]->getDrawContext()->setTransform(0);
        if(tr) delete tr;
      }
    }
    FlGui::instance()->options->activate("geo_transform");
  }
#endif
  return CTX::instance()->geom.useTransform;
}

static double _opt_geometry_transform(OPT_ARGS_NUM, int ii, int jj, int nn)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.transform[ii][jj] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_GUI)
      FlGui::instance()->options->geo.value[nn]->value
        (CTX::instance()->geom.transform[ii][jj]);
    if(action & GMSH_SET){
      drawTransform *tr = FlGui::instance()->graph[0]->gl[0]->
        getDrawContext()->getTransform();
      if(tr) tr->setMatrix(CTX::instance()->geom.transform,
                           CTX::instance()->geom.offset);
    }
  }
#endif
  return CTX::instance()->geom.transform[ii][jj];
}

double opt_geometry_transform00(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 0, 0, 7);
}

double opt_geometry_transform01(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 0, 1, 8);
}

double opt_geometry_transform02(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 0, 2, 9);
}

double opt_geometry_transform10(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 1, 0, 11);
}

double opt_geometry_transform11(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 1, 1, 12);
}

double opt_geometry_transform12(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 1, 2, 13);
}

double opt_geometry_transform20(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 2, 0, 15);
}

double opt_geometry_transform21(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 2, 1, 16);
}

double opt_geometry_transform22(OPT_ARGS_NUM)
{
  return _opt_geometry_transform(num, action, val, 2, 2, 17);
}

static double _opt_geometry_offset(OPT_ARGS_NUM, int ii, int nn)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.offset[ii] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()){
    if(action & GMSH_GUI)
      FlGui::instance()->options->geo.value[nn]->value
        (CTX::instance()->geom.offset[ii]);
    if(action & GMSH_SET){
      drawTransform *tr = FlGui::instance()->graph[0]->gl[0]->
        getDrawContext()->getTransform();
      if(tr) tr->setMatrix(CTX::instance()->geom.transform,
                           CTX::instance()->geom.offset);
    }
  }
#endif
  return CTX::instance()->geom.offset[ii];
}

double opt_geometry_offset0(OPT_ARGS_NUM)
{
  return _opt_geometry_offset(num, action, val, 0, 10);
}

double opt_geometry_offset1(OPT_ARGS_NUM)
{
  return _opt_geometry_offset(num, action, val, 1, 14);
}

double opt_geometry_offset2(OPT_ARGS_NUM)
{
  return _opt_geometry_offset(num, action, val, 2, 18);
}

double opt_geometry_auto_coherence(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.autoCoherence = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[8]->value
      (CTX::instance()->geom.autoCoherence);
#endif
  return CTX::instance()->geom.autoCoherence;
}

double opt_geometry_hide_compounds(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.hideCompounds = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->geo.butt[17]->value
      (CTX::instance()->geom.hideCompounds);
  }
#endif
  return CTX::instance()->geom.hideCompounds;
}

double opt_geometry_highlight_orphans(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.highlightOrphans = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[10]->value
      (CTX::instance()->geom.highlightOrphans);
#endif
  return CTX::instance()->geom.highlightOrphans;
}

double opt_geometry_tolerance(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.tolerance = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[2]->value
      (CTX::instance()->geom.tolerance);
#endif
  return CTX::instance()->geom.tolerance;
}

double opt_geometry_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.normals = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[0]->value
      (CTX::instance()->geom.normals);
#endif
  return CTX::instance()->geom.normals;
}

double opt_geometry_tangents(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.tangents = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[1]->value
      (CTX::instance()->geom.tangents);
#endif
  return CTX::instance()->geom.tangents;
}

double opt_geometry_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.points = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[0]->value
      (CTX::instance()->geom.points);
#endif
  return CTX::instance()->geom.points;
}

double opt_geometry_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.lines = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[1]->value
      (CTX::instance()->geom.lines);
#endif
  return CTX::instance()->geom.lines;
}

double opt_geometry_surfaces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.surfaces = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[2]->value
      (CTX::instance()->geom.surfaces);
#endif
  return CTX::instance()->geom.surfaces;
}

double opt_geometry_volumes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.volumes = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[3]->value
      (CTX::instance()->geom.volumes);
#endif
  return CTX::instance()->geom.volumes;
}

double opt_geometry_points_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.pointsNum = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[4]->value
      (CTX::instance()->geom.pointsNum);
#endif
  return CTX::instance()->geom.pointsNum;
}

double opt_geometry_lines_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.linesNum = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[5]->value
      (CTX::instance()->geom.linesNum);
#endif
  return CTX::instance()->geom.linesNum;
}

double opt_geometry_surfaces_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.surfacesNum = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[6]->value
      (CTX::instance()->geom.surfacesNum);
#endif
  return CTX::instance()->geom.surfacesNum;
}

double opt_geometry_volumes_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.volumesNum = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[7]->value
      (CTX::instance()->geom.volumesNum);
#endif
  return CTX::instance()->geom.volumesNum;
}

double opt_geometry_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.pointSize = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[3]->value
      (CTX::instance()->geom.pointSize);
#endif
  return CTX::instance()->geom.pointSize;
}

double opt_geometry_point_sel_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.selectedPointSize = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[5]->value
      (CTX::instance()->geom.selectedPointSize);
#endif
  return CTX::instance()->geom.selectedPointSize;
}

double opt_geometry_point_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.pointType = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[0]->value
      (CTX::instance()->geom.pointType);
  }
#endif
  return CTX::instance()->geom.pointType;
}

double opt_geometry_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.lineWidth = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[4]->value
      (CTX::instance()->geom.lineWidth);
#endif
  return CTX::instance()->geom.lineWidth;
}

double opt_geometry_line_sel_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.selectedLineWidth = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[6]->value
      (CTX::instance()->geom.selectedLineWidth);
#endif
  return CTX::instance()->geom.selectedLineWidth;
}

double opt_geometry_line_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.lineType = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[1]->value
      (CTX::instance()->geom.lineType);
  }
#endif
  return CTX::instance()->geom.lineType;
}

double opt_geometry_surface_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.surfaceType = (int)val;
    if(CTX::instance()->geom.surfaceType < 0 ||
       CTX::instance()->geom.surfaceType > 2)
      CTX::instance()->geom.surfaceType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[2]->value
      (CTX::instance()->geom.surfaceType);
  }
#endif
  return CTX::instance()->geom.surfaceType;
}

double opt_geometry_light(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.light = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[9]->value
      (CTX::instance()->geom.light);
  }
#endif
  return CTX::instance()->geom.light;
}

double opt_geometry_light_two_side(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.lightTwoSide = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[14]->value
      (CTX::instance()->geom.lightTwoSide);
#endif
  return CTX::instance()->geom.lightTwoSide;
}

double opt_geometry_occ_fix_degenerated(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occFixDegenerated = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[16]->value
      (CTX::instance()->geom.occFixDegenerated);
  }
#endif
  return CTX::instance()->geom.occFixDegenerated;
}

double opt_geometry_occ_fix_small_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occFixSmallEdges = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[11]->value
      (CTX::instance()->geom.occFixSmallEdges);
  }
#endif
  return CTX::instance()->geom.occFixSmallEdges;
}

double opt_geometry_occ_fix_small_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occFixSmallFaces = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[12]->value
      (CTX::instance()->geom.occFixSmallFaces);
  }
#endif
  return CTX::instance()->geom.occFixSmallFaces;
}

double opt_geometry_occ_sew_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occSewFaces = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[13]->value
      (CTX::instance()->geom.occSewFaces);
  }
#endif
  return CTX::instance()->geom.occSewFaces;
}

double opt_geometry_occ_connect_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occConnectFaces = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[15]->value
      (CTX::instance()->geom.occConnectFaces);
  }
#endif
  return CTX::instance()->geom.occConnectFaces;
}

double opt_geometry_old_circle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.oldCircle = (int)val;
  return CTX::instance()->geom.oldCircle;
}

double opt_geometry_old_newreg(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.oldNewreg = (int)val;
  return CTX::instance()->geom.oldNewreg;
}

double opt_geometry_num_sub_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->geom.numSubEdges = (int)val;
    if(CTX::instance()->geom.numSubEdges < 1)
      CTX::instance()->geom.numSubEdges = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.value[19]->value
      (CTX::instance()->geom.numSubEdges);
  }
#endif
  return CTX::instance()->geom.numSubEdges;
}

double opt_geometry_extrude_spline_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.extrudeSplinePoints = (int)val;
  return CTX::instance()->geom.extrudeSplinePoints;
}

double opt_geometry_extrude_return_lateral(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.extrudeReturnLateral = (int)val;
  return CTX::instance()->geom.extrudeReturnLateral;
}

double opt_geometry_scaling_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.scalingFactor = (int)val;
  return CTX::instance()->geom.scalingFactor;
}

double opt_geometry_snap0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.snap[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->geoContext->value[0]->value
      (CTX::instance()->geom.snap[0]);
#endif
  return CTX::instance()->geom.snap[0];
}

double opt_geometry_snap1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.snap[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->geoContext->value[1]->value
      (CTX::instance()->geom.snap[1]);
#endif
  return CTX::instance()->geom.snap[1];
}

double opt_geometry_snap2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.snap[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->geoContext->value[2]->value
      (CTX::instance()->geom.snap[2]);
#endif
  return CTX::instance()->geom.snap[2];
}

double opt_geometry_clip(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.clip = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->geom.clip;
}

double opt_geometry_copy_meshing_method(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.copyMeshingMethod = (int)val;
  return CTX::instance()->geom.copyMeshingMethod;
}

double opt_geometry_exact_extrusion(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.exactExtrusion = (int)val;
  return CTX::instance()->geom.exactExtrusion;
}

double opt_geometry_match_geom_and_mesh(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.matchGeomAndMesh = (int)val;
  return CTX::instance()->geom.matchGeomAndMesh;
}

double opt_mesh_optimize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.optimize = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[2]->value
      (CTX::instance()->mesh.optimize);
#endif
  return CTX::instance()->mesh.optimize;
}

double opt_mesh_optimize_netgen(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.optimizeNetgen = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[24]->value
      (CTX::instance()->mesh.optimizeNetgen);
#endif
  return CTX::instance()->mesh.optimizeNetgen;
}

double opt_mesh_remove_4_triangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.remove4triangles = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[25]->value
      (CTX::instance()->mesh.remove4triangles);
#endif
  return CTX::instance()->mesh.remove4triangles;

}

double opt_mesh_refine_steps(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.refineSteps = (int)val;
  return CTX::instance()->mesh.refineSteps;
}

double opt_mesh_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.normals = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[8]->value
      (CTX::instance()->mesh.normals);
#endif
  return CTX::instance()->mesh.normals;
}

double opt_mesh_num_sub_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(CTX::instance()->mesh.numSubEdges != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.numSubEdges = (int)val;
    if(CTX::instance()->mesh.numSubEdges < 1)
      CTX::instance()->mesh.numSubEdges = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[14]->value
      (CTX::instance()->mesh.numSubEdges);
#endif
  return CTX::instance()->mesh.numSubEdges;
}

double opt_mesh_tangents(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.tangents = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[13]->value
      (CTX::instance()->mesh.tangents);
#endif
  return CTX::instance()->mesh.tangents;
}

double opt_mesh_explode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.explode != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.explode = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[9]->value
      (CTX::instance()->mesh.explode);
#endif
  return CTX::instance()->mesh.explode;
}

double opt_mesh_scaling_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.scalingFactor = val;
  return CTX::instance()->mesh.scalingFactor;
}

double opt_mesh_lc_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    if(val > 0)
      CTX::instance()->mesh.lcFactor = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[2]->value
      (CTX::instance()->mesh.lcFactor);
#endif
  return CTX::instance()->mesh.lcFactor;
}

double opt_mesh_lc_min(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lcMin = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[25]->value
      (CTX::instance()->mesh.lcMin);
#endif
  return CTX::instance()->mesh.lcMin;
}

double opt_mesh_lc_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lcMax = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[26]->value
      (CTX::instance()->mesh.lcMax);
#endif
  return CTX::instance()->mesh.lcMax;
}

double opt_mesh_tolerance_edge_length(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.toleranceEdgeLength = val;
  return CTX::instance()->mesh.toleranceEdgeLength;
}

double opt_mesh_lc_from_curvature(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lcFromCurvature = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[1]->value
      (CTX::instance()->mesh.lcFromCurvature ? 1 : 0);
#endif
  return CTX::instance()->mesh.lcFromCurvature;
}

double opt_mesh_lc_from_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lcFromPoints = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[5]->value
      (CTX::instance()->mesh.lcFromPoints ? 1 : 0);
#endif
  return CTX::instance()->mesh.lcFromPoints;
}

double opt_mesh_lc_extend_from_boundary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lcExtendFromBoundary = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[16]->value
      (CTX::instance()->mesh.lcExtendFromBoundary ? 1 : 0);
#endif
  return CTX::instance()->mesh.lcExtendFromBoundary;
}

double opt_mesh_lc_integration_precision(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lcIntegrationPrecision = val;
  return CTX::instance()->mesh.lcIntegrationPrecision;
}

double opt_mesh_rand_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.randFactor = val;
  return CTX::instance()->mesh.randFactor;
}

double opt_mesh_quality_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.qualityType != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.qualityType = (int)val;
    if(CTX::instance()->mesh.qualityType < 0 || CTX::instance()->mesh.qualityType > 3)
      CTX::instance()->mesh.qualityType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->mesh.choice[6]->value
      (CTX::instance()->mesh.qualityType);
  }
#endif
  return CTX::instance()->mesh.qualityType;
}

double opt_mesh_quality_inf(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.qualityInf != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.qualityInf = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[4]->value
      (CTX::instance()->mesh.qualityInf);
#endif
  return CTX::instance()->mesh.qualityInf;
}

double opt_mesh_quality_sup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.qualitySup != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.qualitySup = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[5]->value
      (CTX::instance()->mesh.qualitySup);
#endif
  return CTX::instance()->mesh.qualitySup;
}

double opt_mesh_radius_inf(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.radiusInf != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.radiusInf = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[6]->value
      (CTX::instance()->mesh.radiusInf);
#endif
  return CTX::instance()->mesh.radiusInf;
}

double opt_mesh_radius_sup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.radiusSup != val)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.radiusSup = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[7]->value
      (CTX::instance()->mesh.radiusSup);
#endif
  return CTX::instance()->mesh.radiusSup;
}

double opt_mesh_label_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.labelType = (int)val;
    if(CTX::instance()->mesh.labelType < 0 || CTX::instance()->mesh.labelType > 4)
      CTX::instance()->mesh.labelType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->mesh.choice[7]->value
      (CTX::instance()->mesh.labelType);
  }
#endif
  return CTX::instance()->mesh.labelType;
}

double opt_mesh_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.points = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[6]->value
      (CTX::instance()->mesh.points);
#endif
  return CTX::instance()->mesh.points;
}

double opt_mesh_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.lines != val)
      CTX::instance()->mesh.changed |= ENT_LINE;
    CTX::instance()->mesh.lines = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[7]->value
      (CTX::instance()->mesh.lines);
#endif
  return CTX::instance()->mesh.lines;
}

double opt_mesh_triangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.triangles != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.triangles = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    if(CTX::instance()->mesh.triangles)
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[0].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[0].clear();
  }
#endif
  return CTX::instance()->mesh.triangles;
}

double opt_mesh_quadrangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.quadrangles != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.quadrangles = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    if(CTX::instance()->mesh.quadrangles)
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[1].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[1].clear();
  }
#endif
  return CTX::instance()->mesh.quadrangles;
}

double opt_mesh_tetrahedra(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.tetrahedra != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.tetrahedra = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    if(CTX::instance()->mesh.tetrahedra)
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[2].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[2].clear();
  }
#endif
  return CTX::instance()->mesh.tetrahedra;
}

double opt_mesh_hexahedra(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.hexahedra != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.hexahedra = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    if(CTX::instance()->mesh.hexahedra)
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[3].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[3].clear();
  }
#endif
  return CTX::instance()->mesh.hexahedra;
}

double opt_mesh_prisms(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.prisms != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.prisms = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    if(CTX::instance()->mesh.prisms)
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[4].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[4].clear();
  }
#endif
  return CTX::instance()->mesh.prisms;
}

double opt_mesh_pyramids(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.pyramids != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.pyramids = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    if(CTX::instance()->mesh.pyramids)
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[5].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->mesh.menu->menu())[5].clear();
  }
#endif
  return CTX::instance()->mesh.pyramids;
}

double opt_mesh_surfaces_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.surfacesEdges != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.surfacesEdges = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[8]->value
      (CTX::instance()->mesh.surfacesEdges);
#endif
  return CTX::instance()->mesh.surfacesEdges;
}

double opt_mesh_surfaces_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.surfacesFaces != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.surfacesFaces = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[9]->value
      (CTX::instance()->mesh.surfacesFaces);
#endif
  return CTX::instance()->mesh.surfacesFaces;
}

double opt_mesh_volumes_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.volumesEdges != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.volumesEdges = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[10]->value
      (CTX::instance()->mesh.volumesEdges);
#endif
  return CTX::instance()->mesh.volumesEdges;
}

double opt_mesh_volumes_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.volumesFaces != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.volumesFaces = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[11]->value
      (CTX::instance()->mesh.volumesFaces);
#endif
  return CTX::instance()->mesh.volumesFaces;
}

double opt_mesh_points_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.pointsNum = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[12]->value
      (CTX::instance()->mesh.pointsNum);
#endif
  return CTX::instance()->mesh.pointsNum;
}

double opt_mesh_lines_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.linesNum = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[13]->value
      (CTX::instance()->mesh.linesNum);
#endif
  return CTX::instance()->mesh.linesNum;
}

double opt_mesh_surfaces_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.surfacesNum = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[14]->value
      (CTX::instance()->mesh.surfacesNum);
#endif
  return CTX::instance()->mesh.surfacesNum;
}

double opt_mesh_volumes_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.volumesNum = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[15]->value
      (CTX::instance()->mesh.volumesNum);
#endif
  return CTX::instance()->mesh.volumesNum;
}

double opt_mesh_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.pointSize = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[10]->value
      (CTX::instance()->mesh.pointSize);
#endif
  return CTX::instance()->mesh.pointSize;
}

double opt_mesh_point_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.pointType = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[0]->value
      (CTX::instance()->mesh.pointType ? 1 : 0);
  }
#endif
  return CTX::instance()->mesh.pointType;
}

double opt_mesh_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.lineWidth = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[11]->value
      (CTX::instance()->mesh.lineWidth);
#endif
  return CTX::instance()->mesh.lineWidth;
}

double opt_mesh_label_sampling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.labelSampling = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[12]->value
      (CTX::instance()->mesh.labelSampling);
#endif
  return CTX::instance()->mesh.labelSampling;
}

double opt_mesh_reverse_all_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.reverseAllNormals != val)
      CTX::instance()->mesh.changed |= (ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.reverseAllNormals = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[0]->value
      (CTX::instance()->mesh.reverseAllNormals);
#endif
  return CTX::instance()->mesh.reverseAllNormals;
}

double opt_mesh_smooth_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.smoothNormals != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.smoothNormals = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[19]->value
      (CTX::instance()->mesh.smoothNormals);
#endif
  return CTX::instance()->mesh.smoothNormals;
}

double opt_mesh_smooth_ratio(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.smoothRatio = val;
  return CTX::instance()->mesh.smoothRatio;
}

double opt_mesh_aniso_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.anisoMax = val;
  return CTX::instance()->mesh.anisoMax;
}

double opt_mesh_angle_smooth_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.angleSmoothNormals != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.angleSmoothNormals = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[18]->value
      (CTX::instance()->mesh.angleSmoothNormals);
#endif
  return CTX::instance()->mesh.angleSmoothNormals;
}

double opt_mesh_light(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.light = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->mesh.butt[17]->value
      (CTX::instance()->mesh.light);
    FlGui::instance()->options->activate("mesh_light");
  }
#endif
  return CTX::instance()->mesh.light;
}

double opt_mesh_light_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lightLines = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[20]->value
      (CTX::instance()->mesh.lightLines);
#endif
  return CTX::instance()->mesh.lightLines;
}

double opt_mesh_light_two_side(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.lightTwoSide = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[18]->value
      (CTX::instance()->mesh.lightTwoSide);
#endif
  return CTX::instance()->mesh.lightTwoSide;
}

double opt_mesh_file_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.fileFormat = (int)val;
  return CTX::instance()->mesh.fileFormat;
}

double opt_mesh_msh_file_version(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.mshFileVersion = val;
  return CTX::instance()->mesh.mshFileVersion;
}

double opt_mesh_msh_file_partitioned(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.mshFilePartitioned = val;
  return CTX::instance()->mesh.mshFilePartitioned;
}

double opt_mesh_partition_hex_weight(OPT_ARGS_NUM)
{
  if (action & GMSH_SET)
    CTX::instance()->partitionOptions.hexWeight = (int) val;
  return CTX::instance()->partitionOptions.hexWeight;
}

double opt_mesh_partition_pri_weight(OPT_ARGS_NUM)
{
  if (action & GMSH_SET)
    CTX::instance()->partitionOptions.priWeight = (int) val;
  return CTX::instance()->partitionOptions.priWeight;
}

double opt_mesh_partition_pyr_weight(OPT_ARGS_NUM)
{
  if (action & GMSH_SET)
    CTX::instance()->partitionOptions.pyrWeight = (int) val;
  return CTX::instance()->partitionOptions.pyrWeight;
}

double opt_mesh_partition_qua_weight(OPT_ARGS_NUM)
{
  if (action & GMSH_SET)
    CTX::instance()->partitionOptions.quaWeight = (int) val;
  return CTX::instance()->partitionOptions.quaWeight;
}

double opt_mesh_partition_tet_weight(OPT_ARGS_NUM)
{
  if (action & GMSH_SET)
    CTX::instance()->partitionOptions.tetWeight = (int) val;
  return CTX::instance()->partitionOptions.tetWeight;
}

double opt_mesh_partition_tri_weight(OPT_ARGS_NUM)
{
  if (action & GMSH_SET)
    CTX::instance()->partitionOptions.triWeight = (int) val;
  return CTX::instance()->partitionOptions.triWeight;
}

double opt_mesh_binary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.binary = (int)val;
  return CTX::instance()->mesh.binary;
}

double opt_mesh_bunin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.bunin = (int)val;
  return CTX::instance()->mesh.bunin;
}

double opt_mesh_bdf_field_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.bdfFieldFormat = (int)val;
    if(CTX::instance()->mesh.bdfFieldFormat < 0 ||
       CTX::instance()->mesh.bdfFieldFormat > 2)
      CTX::instance()->mesh.bdfFieldFormat = 1;
  }
  return CTX::instance()->mesh.bdfFieldFormat;
}

double opt_mesh_nb_smoothing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.nbSmoothing = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[0]->value
      (CTX::instance()->mesh.nbSmoothing);
#endif
  return CTX::instance()->mesh.nbSmoothing;
}

double opt_mesh_algo2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    int algo = (int)val;
    CTX::instance()->mesh.algo2d = algo;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    switch (CTX::instance()->mesh.algo2d) {
    case ALGO_2D_MESHADAPT:
      FlGui::instance()->options->mesh.choice[2]->value(1);
      break;
    case ALGO_2D_DELAUNAY:
      FlGui::instance()->options->mesh.choice[2]->value(2);
      break;
    case ALGO_2D_FRONTAL:
      FlGui::instance()->options->mesh.choice[2]->value(3);
      break;
    case ALGO_2D_FRONTAL_QUAD:
      FlGui::instance()->options->mesh.choice[2]->value(4);
      break;
    case ALGO_2D_AUTO:
    default:
      FlGui::instance()->options->mesh.choice[2]->value(0);
      break;
    }
  }
#endif
  return CTX::instance()->mesh.algo2d;
}

double opt_mesh_algo_recombine(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.algoRecombine = (int)val;
    if(CTX::instance()->mesh.algoRecombine < 0 &&
       CTX::instance()->mesh.algoRecombine > 1)
      CTX::instance()->mesh.algoRecombine = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[1]->value
      (CTX::instance()->mesh.algoRecombine);
  }
#endif
  return CTX::instance()->mesh.algoRecombine;
}

double opt_mesh_recombine_all(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.recombineAll = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[21]->value
      (CTX::instance()->mesh.recombineAll);
#endif
  return CTX::instance()->mesh.recombineAll;
}

double opt_mesh_remesh_algo(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.remeshAlgo = (int)val;
    if(CTX::instance()->mesh.remeshAlgo < 0 &&
       CTX::instance()->mesh.remeshAlgo > 2)
      CTX::instance()->mesh.remeshAlgo = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[8]->value
      (CTX::instance()->mesh.remeshAlgo);
  }
#endif
  return CTX::instance()->mesh.remeshAlgo;
}

double opt_mesh_remesh_param(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.remeshParam = (int)val;
    if(CTX::instance()->mesh.remeshParam < 0 &&
       CTX::instance()->mesh.remeshParam > 2)
      CTX::instance()->mesh.remeshParam = 0;
  }
#if defined(HAVE_FLTK)
   if(FlGui::available() && (action & GMSH_GUI)) {
     FlGui::instance()->options->mesh.choice[9]->value
       (CTX::instance()->mesh.remeshParam);
   }
#endif
  return CTX::instance()->mesh.remeshParam;
}

double opt_mesh_algo_subdivide(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.algoSubdivide = (int)val;
    if(CTX::instance()->mesh.algoSubdivide < 0 &&
       CTX::instance()->mesh.algoSubdivide > 2)
      CTX::instance()->mesh.algoSubdivide = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[5]->value
      (CTX::instance()->mesh.algoSubdivide);
  }
#endif
  return CTX::instance()->mesh.algoSubdivide;
}

double opt_mesh_algo3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    int algo = (int)val;
    CTX::instance()->mesh.algo3d = algo;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    switch (CTX::instance()->mesh.algo3d) {
    case ALGO_3D_MMG3D:
      FlGui::instance()->options->mesh.choice[3]->value(4);
      break;
    case ALGO_3D_FRONTAL_HEX:
      FlGui::instance()->options->mesh.choice[3]->value(3);
      break;
    case ALGO_3D_FRONTAL_DEL:
      FlGui::instance()->options->mesh.choice[3]->value(2);
      break;
    case ALGO_3D_FRONTAL:
      FlGui::instance()->options->mesh.choice[3]->value(1);
      break;
    case ALGO_3D_RTREE:
      FlGui::instance()->options->mesh.choice[3]->value(5);
      break;
    case ALGO_3D_DELAUNAY:
    default:
      FlGui::instance()->options->mesh.choice[3]->value(0);
      break;
    }
  }
#endif
  return CTX::instance()->mesh.algo3d;
}

double opt_mesh_mesh_only_visible(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.meshOnlyVisible = (int)val;
  return CTX::instance()->mesh.meshOnlyVisible;
}

double opt_mesh_min_circ_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.minCircPoints = (int)val;
  return CTX::instance()->mesh.minCircPoints;
}

double opt_mesh_allow_swap_edge_angle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.allowSwapEdgeAngle = val;
  return CTX::instance()->mesh.allowSwapEdgeAngle;
}

double opt_mesh_min_curv_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.minCurvPoints = (int)val;
  return CTX::instance()->mesh.minCurvPoints;
}

double opt_mesh_order(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.order = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[3]->value
      (CTX::instance()->mesh.order);
#endif
  return CTX::instance()->mesh.order;
}

double opt_mesh_smooth_internal_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.smoothInternalEdges = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[3]->value
      (CTX::instance()->mesh.smoothInternalEdges);
#endif
  return CTX::instance()->mesh.smoothInternalEdges;
}

double opt_mesh_ho_nlayers(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.smoothNLayers = (int)val;
  return CTX::instance()->mesh.smoothNLayers;
}

double opt_mesh_ho_mindisto(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.smoothDistoTreshold = val;
  return CTX::instance()->mesh.smoothDistoTreshold;
}

double opt_mesh_second_order_experimental(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.secondOrderExperimental = (int)val;
  return CTX::instance()->mesh.secondOrderExperimental;
}

double opt_mesh_multiple_passes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.multiplePasses = (int)val;
  return CTX::instance()->mesh.multiplePasses;
}

double opt_mesh_second_order_linear(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.secondOrderLinear = (int)val;
  return CTX::instance()->mesh.secondOrderLinear;
}

double opt_mesh_second_order_incomplete(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.secondOrderIncomplete = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[4]->value
      (CTX::instance()->mesh.secondOrderIncomplete);
#endif
  return CTX::instance()->mesh.secondOrderIncomplete;
}

double opt_mesh_cgns_import_order(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int value = (int)val;
    double order = val;
    while(order >= 2.0) {
      order = order / 2.0;
    }

    if (order != 1.0)
      value = 1;
    CTX::instance()->mesh.cgnsImportOrder = value;
  }
  return CTX::instance()->mesh.cgnsImportOrder;
}

double opt_mesh_dual(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.dual = (int)val;
  }
  return CTX::instance()->mesh.dual;
}

double opt_mesh_voronoi(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.voronoi= (int)val;
  }
  return CTX::instance()->mesh.voronoi;
}

double opt_mesh_draw_skin_only(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.drawSkinOnly = (int)val;
  }
  return CTX::instance()->mesh.drawSkinOnly;
}

double opt_mesh_save_all(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.saveAll = val ? 1 : 0;
  return CTX::instance()->mesh.saveAll;
}

double opt_mesh_save_element_tag_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.saveElementTagType = (int)val;
  return CTX::instance()->mesh.saveElementTagType;
}

double opt_mesh_save_parametric(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.saveParametric = val ? 1 : 0;
  return CTX::instance()->mesh.saveParametric;
}

double opt_mesh_save_groups_of_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.saveGroupsOfNodes = val ? 1 : 0;
  return CTX::instance()->mesh.saveGroupsOfNodes;
}

double opt_mesh_color_carousel(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type or by partition
    if(CTX::instance()->mesh.colorCarousel != (int)val &&
       ((val == 0. || val == 3.) || CTX::instance()->pickElements))
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.colorCarousel = (int)val;
    if(CTX::instance()->mesh.colorCarousel < 0 ||
       CTX::instance()->mesh.colorCarousel > 3)
      CTX::instance()->mesh.colorCarousel = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->mesh.choice[4]->value
      (CTX::instance()->mesh.colorCarousel);
    drawContext::global()->resetFontTextures();
  }
#endif
  return CTX::instance()->mesh.colorCarousel;
}

double opt_mesh_switch_elem_tags(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.switchElementTags = val ? 1 : 0;
  return CTX::instance()->mesh.switchElementTags;
}

double opt_mesh_zone_definition(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->mesh.zoneDefinition = (int)val;
    if( (CTX::instance()->mesh.zoneDefinition < 0 ||
         CTX::instance()->mesh.zoneDefinition > 2) ||
        (CTX::instance()->mesh.zoneDefinition == 1 &&
         GModel::current()->getMinPartitionSize() +
         GModel::current()->getMaxPartitionSize() == 0) )
      CTX::instance()->mesh.zoneDefinition = 0;
  }
  return CTX::instance()->mesh.zoneDefinition;
}

#if !defined(HAVE_MESH)
static void GetStatistics(double stat[50])
{
  for(int i = 0; i < 50; i++) stat[i] = 0;
}
#endif

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

double opt_mesh_partition_partitioner(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = (int)val;
    CTX::instance()->partitionOptions.partitioner =
      (ival < 1 || ival > 2) ? 1 : ival;
  }
  return CTX::instance()->partitionOptions.partitioner;
}

double opt_mesh_partition_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = std::max(1, (int)val);
    CTX::instance()->partitionOptions.num_partitions = ival;
    unsigned hcdim = 0;  // log2 to get hypercube dimensions
    unsigned jval = ival;
    while(jval >>= 1) ++hcdim;
    CTX::instance()->partitionOptions.ndims_tot = hcdim;
    CTX::instance()->partitionOptions.mesh_dims[0] = ival;
    CTX::instance()->partitionOptions.mesh_dims[1] = 1;
    CTX::instance()->partitionOptions.mesh_dims[2] = 1;
    if(CTX::instance()->partitionOptions.partitioner == 2)  // METIS
      CTX::instance()->partitionOptions.algorithm = (ival <= 8) ? 1 : 2;
  }
  return CTX::instance()->partitionOptions.num_partitions;
}

double opt_mesh_partition_chaco_global_method(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int ival = (int)val;
    CTX::instance()->partitionOptions.global_method =
      (ival < 1 || ival > 6 || ival == 3) ? 1 : ival;
  }
  return  CTX::instance()->partitionOptions.global_method;
}

double opt_mesh_partition_chaco_architecture(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = (int)val;
    CTX::instance()->partitionOptions.architecture =
      (ival < 0 || ival > 3) ? 1 : ival;
  }
  return CTX::instance()->partitionOptions.architecture;
}

double opt_mesh_partition_chaco_ndims_tot(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = std::max(1, (int)val);
    CTX::instance()->partitionOptions.ndims_tot = ival;
    CTX::instance()->partitionOptions.num_partitions = 1 << ival;
  }
  return CTX::instance()->partitionOptions.ndims_tot;
}

double opt_mesh_partition_chaco_mesh_dims1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = std::max(1, (int)val);
    CTX::instance()->partitionOptions.mesh_dims[0] = ival;
    CTX::instance()->partitionOptions.num_partitions = ival;
    if(CTX::instance()->partitionOptions.architecture >= 2)
      CTX::instance()->partitionOptions.num_partitions *=
        CTX::instance()->partitionOptions.mesh_dims[1];
    if(CTX::instance()->partitionOptions.architecture == 3)
      CTX::instance()->partitionOptions.num_partitions *=
        CTX::instance()->partitionOptions.mesh_dims[2];
  }
  return CTX::instance()->partitionOptions.mesh_dims[0];
}

double opt_mesh_partition_chaco_mesh_dims2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = std::max(1, (int)val);
    CTX::instance()->partitionOptions.mesh_dims[1] = ival;
    CTX::instance()->partitionOptions.num_partitions =
      CTX::instance()->partitionOptions.mesh_dims[0]*ival;
    if(CTX::instance()->partitionOptions.architecture == 3)
      CTX::instance()->partitionOptions.num_partitions *=
        CTX::instance()->partitionOptions.mesh_dims[2];
  }
  return CTX::instance()->partitionOptions.mesh_dims[1];
}

double opt_mesh_partition_chaco_mesh_dims3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = std::max(1, (int)val);
    CTX::instance()->partitionOptions.mesh_dims[2] = ival;
    CTX::instance()->partitionOptions.num_partitions =
      CTX::instance()->partitionOptions.mesh_dims[0]*
      CTX::instance()->partitionOptions.mesh_dims[1]*ival;
  }
  return CTX::instance()->partitionOptions.mesh_dims[2];
}

double opt_mesh_partition_chaco_local_method(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int ival = (int)val;
    if(CTX::instance()->partitionOptions.algorithm == 1) ival = 1;
    CTX::instance()->partitionOptions.local_method = (ival < 0 || ival > 1) ? 1 : ival;
  }
  return CTX::instance()->partitionOptions.local_method;
}

double opt_mesh_partition_chaco_eigensolver(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int ival = val ? 1 : 0;
    CTX::instance()->partitionOptions.rqi_flag = ival;
  }
  return CTX::instance()->partitionOptions.rqi_flag;
}

double opt_mesh_partition_chaco_vmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = (int)val;
    CTX::instance()->partitionOptions.vmax = (ival < 1) ? 1 : ival;
  }
  return CTX::instance()->partitionOptions.vmax;
}

double opt_mesh_partition_chaco_nsection(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = (int)val;
    CTX::instance()->partitionOptions.ndims = (ival < 1 || ival > 3) ? 1 : ival;
    if(CTX::instance()->partitionOptions.ndims > 1 &&
       CTX::instance()->partitionOptions.algorithm == 2)
      CTX::instance()->partitionOptions.terminal_propogation = false;
  }
  return CTX::instance()->partitionOptions.ndims;
}

double opt_mesh_partition_chaco_eigtol(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->partitionOptions.eigtol = (val <= 0.) ? 1.E-3 : val;
  return CTX::instance()->partitionOptions.eigtol;
}

double opt_mesh_partition_chaco_seed(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->partitionOptions.seed = (long)val;
  return CTX::instance()->partitionOptions.seed;
}

double opt_mesh_partition_chaco_refine_partition(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->partitionOptions.refine_partition = val ? 1 : 0;
  return CTX::instance()->partitionOptions.refine_partition;
}

double opt_mesh_partition_chaco_internal_vertices(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->partitionOptions.internal_vertices = val ? 1 : 0;
  return CTX::instance()->partitionOptions.internal_vertices;
}

double opt_mesh_partition_chaco_refine_map(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->partitionOptions.refine_map = val ? 1 : 0;
  return CTX::instance()->partitionOptions.refine_map;
}

double opt_mesh_partition_chaco_terminal_propogation(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->partitionOptions.terminal_propogation = val ? 1 : 0;
    if(CTX::instance()->partitionOptions.terminal_propogation &&
       CTX::instance()->partitionOptions.algorithm == 2)
      CTX::instance()->partitionOptions.ndims = 1;
  }
  return CTX::instance()->partitionOptions.terminal_propogation;
}

double opt_mesh_partition_metis_algorithm(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int ival = (int)val;
    if(ival < 1 || ival > 3)
      ival = (CTX::instance()->partitionOptions.num_partitions <= 8) ? 1 : 2;
    CTX::instance()->partitionOptions.algorithm = ival;
  }
  return  CTX::instance()->partitionOptions.algorithm;
}

double opt_mesh_partition_metis_edge_matching(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = (int)val;
    CTX::instance()->partitionOptions.edge_matching =
      (ival < 1 || ival > 3) ? 3 : ival;
  }
  return CTX::instance()->partitionOptions.edge_matching;
}

double opt_mesh_partition_metis_refine_algorithm(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = (int)val;
    CTX::instance()->partitionOptions.refine_algorithm =
      (ival < 1 || ival > 3) ? 3 : ival;
  }
  return CTX::instance()->partitionOptions.refine_algorithm;
}

double opt_mesh_clip(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.clip = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->mesh.clip;
}

double opt_solver_listen(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.listen = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.butt[0]->value
      (CTX::instance()->solver.listen);
#endif
  return CTX::instance()->solver.listen;
}

double opt_solver_timeout(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.timeout = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.value[0]->value(CTX::instance()->solver.timeout);
#endif
  return CTX::instance()->solver.timeout;
}

double opt_solver_plugins(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.plugins = (int)val;
  return CTX::instance()->solver.plugins;
}

double opt_post_horizontal_scales(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.horizontalScales = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.butt[2]->value
      (CTX::instance()->post.horizontalScales);
#endif
  return CTX::instance()->post.horizontalScales;
}

double opt_post_link(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->post.link = (int)val;
    if(CTX::instance()->post.link < 0 || CTX::instance()->post.link > 4)
      CTX::instance()->post.link = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->post.choice[0]->value
      (CTX::instance()->post.link);
  }
#endif
  return CTX::instance()->post.link;
}

double opt_post_smooth(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.smooth = (int)val;
  return CTX::instance()->post.smooth;
}

double opt_post_anim_delay(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.animDelay = (val >= 0.) ? val : 0.;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.value[0]->value
      (CTX::instance()->post.animDelay);
#endif
  return CTX::instance()->post.animDelay;
}

double opt_post_anim_cycle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.animCycle = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.butt[0]->value
      (CTX::instance()->post.animCycle);
  if(FlGui::available())
    for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->checkAnimButtons();
#endif
  return CTX::instance()->post.animCycle;
}

double opt_post_anim_step(OPT_ARGS_NUM)
{
  if(action & GMSH_SET){
    CTX::instance()->post.animStep = (int)val;
    if(CTX::instance()->post.animStep < 1) CTX::instance()->post.animStep = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.value[1]->value
      (CTX::instance()->post.animStep);
#endif
  return CTX::instance()->post.animStep;
}

double opt_post_combine_remove_orig(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.combineRemoveOrig = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.butt[1]->value
      (CTX::instance()->post.combineRemoveOrig);
#endif
  return CTX::instance()->post.combineRemoveOrig;
}

double opt_post_plugins(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.plugins = (int)val;
  return CTX::instance()->post.plugins;
}

double opt_post_nb_views(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  return PView::list.size();
#else
  return 0;
#endif
}

double opt_post_file_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.fileFormat = (int)val;
  return CTX::instance()->post.fileFormat;
}

double opt_view_nb_timestep(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 1;
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[50]->maximum(data->getNumTimeSteps() - 1);
  if(FlGui::available())
    for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->checkAnimButtons();
#endif
  return data->getNumTimeSteps();
#else
  return 0.;
#endif
}

double opt_view_nb_non_empty_timestep(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0;
  int n = 0;
  for(int i = 0; i < data->getNumTimeSteps(); i++)
    if(data->hasTimeStep(i)) n++;
  return n;
#else
  return 0.;
#endif
}

double opt_view_timestep(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0;
  if(action & GMSH_SET) {
    opt->timeStep = (int)val;
    if(opt->timeStep > data->getNumTimeSteps() - 1)
      opt->timeStep = 0;
    else if(opt->timeStep < 0)
      opt->timeStep = data->getNumTimeSteps() - 1;
    if(data->getAdaptiveData())
      data->getAdaptiveData()->changeResolution
        (opt->timeStep, opt->maxRecursionLevel, opt->targetError);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[50]->value(opt->timeStep);
#endif
  return opt->timeStep;
#else
  return 0.;
#endif
}

double opt_view_min(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  // use adaptive data if available
  return view->getData(true)->getMin();
#else
  return 0.;
#endif
}

double opt_view_max(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  // use adaptive data if available
  return view->getData(true)->getMax();
#else
  return 0.;
#endif
}

double opt_view_custom_min(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->customMin = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[31]->value(opt->customMin);
  }
#endif
  return opt->customMin;
#else
  return 0.;
#endif
}

double opt_view_custom_max(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->customMax = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[32]->value(opt->customMax);
#endif
  return opt->customMax;
#else
  return 0.;
#endif
}

double opt_view_xmin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  return data->getBoundingBox().min().x();
#else
  return 0.;
#endif
}

double opt_view_xmax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  return data->getBoundingBox().max().x();
#else
  return 0.;
#endif
}

double opt_view_ymin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  return data->getBoundingBox().min().y();
#else
  return 0.;
#endif
}

double opt_view_ymax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  return data->getBoundingBox().max().y();
#else
  return 0.;
#endif
}

double opt_view_zmin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  return data->getBoundingBox().min().z();
#else
  return 0.;
#endif
}

double opt_view_zmax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  return data->getBoundingBox().max().z();
#else
  return 0.;
#endif
}

double opt_view_offset0(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->offset[0] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[40]->value(opt->offset[0]);
#endif
  return opt->offset[0];
#else
  return 0.;
#endif
}

double opt_view_offset1(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->offset[1] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[41]->value(opt->offset[1]);
#endif
  return opt->offset[1];
#else
  return 0.;
#endif
}

double opt_view_offset2(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->offset[2] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[42]->value(opt->offset[2]);
#endif
  return opt->offset[2];
#else
  return 0.;
#endif
}

double opt_view_raise0(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->raise[0] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[43]->value(opt->raise[0]);
#endif
  return opt->raise[0];
#else
  return 0.;
#endif
}

double opt_view_raise1(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->raise[1] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[44]->value(opt->raise[1]);
#endif
  return opt->raise[1];
#else
  return 0.;
#endif
}

double opt_view_raise2(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->raise[2] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[45]->value(opt->raise[2]);
#endif
  return opt->raise[2];
#else
  return 0.;
#endif
}

double opt_view_normal_raise(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->normalRaise = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[46]->value(opt->normalRaise);
#endif
  return opt->normalRaise;
#else
  return 0.;
#endif
}

double opt_view_transform00(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[0][0] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[51]->value(opt->transform[0][0]);
#endif
  return opt->transform[0][0];
#else
  return 0.;
#endif
}

double opt_view_transform01(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[0][1] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[52]->value(opt->transform[0][1]);
#endif
  return opt->transform[0][1];
#else
  return 0.;
#endif
}

double opt_view_transform02(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[0][2] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[53]->value(opt->transform[0][2]);
#endif
  return opt->transform[0][2];
#else
  return 0.;
#endif
}

double opt_view_transform10(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[1][0] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[54]->value(opt->transform[1][0]);
#endif
  return opt->transform[1][0];
#else
  return 0.;
#endif
}

double opt_view_transform11(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[1][1] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[55]->value(opt->transform[1][1]);
#endif
  return opt->transform[1][1];
#else
  return 0.;
#endif
}

double opt_view_transform12(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[1][2] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[56]->value(opt->transform[1][2]);
#endif
  return opt->transform[1][2];
#else
  return 0.;
#endif
}

double opt_view_transform20(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[2][0] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[57]->value(opt->transform[2][0]);
#endif
  return opt->transform[2][0];
#else
  return 0.;
#endif
}

double opt_view_transform21(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[2][1] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[58]->value(opt->transform[2][1]);
#endif
  return opt->transform[2][1];
#else
  return 0.;
#endif
}

double opt_view_transform22(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->transform[2][2] = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[59]->value(opt->transform[2][2]);
#endif
  return opt->transform[2][2];
#else
  return 0.;
#endif
}

double opt_view_arrow_size_min(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->arrowSizeMin = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[64]->value(opt->arrowSizeMin);
#endif
  return opt->arrowSizeMin;
#else
  return 0.;
#endif
}

double opt_view_arrow_size_max(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->arrowSizeMax = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[60]->value(opt->arrowSizeMax);
#endif
  return opt->arrowSizeMax;
#else
  return 0.;
#endif
}

double opt_view_normals(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->normals = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[0]->value(opt->normals);
#endif
  return opt->normals;
#else
  return 0.;
#endif
}

double opt_view_tangents(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->tangents = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[1]->value(opt->tangents);
#endif
  return opt->tangents;
#else
  return 0.;
#endif
}

double opt_view_displacement_factor(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->displacementFactor = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[63]->value(opt->displacementFactor);
#endif
  return opt->displacementFactor;
#else
  return 0.;
#endif
}

double opt_view_fake_transparency(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->fakeTransparency = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[24]->value(opt->fakeTransparency);
#endif
  return opt->fakeTransparency;
#else
  return 0.;
#endif
}

double opt_view_explode(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->explode = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[12]->value(opt->explode);
#endif
  return opt->explode;
#else
  return 0.;
#endif
}

double opt_view_visible(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->visible = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI) && num >= 0 &&
     num < (int)FlGui::instance()->menu->toggle.size())
    FlGui::instance()->menu->toggle[num]->value(opt->visible);
#endif
  return opt->visible;
#else
  return 0.;
#endif
}

double opt_view_intervals_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->intervalsType = (int)val;
    if(opt->intervalsType < 1 || opt->intervalsType > 4)
      opt->intervalsType = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[0]->value(opt->intervalsType - 1);
  }
#endif
  return opt->intervalsType;
#else
  return 0.;
#endif
}

double opt_view_saturate_values(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->saturateValues = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.butt[38]->value(opt->saturateValues);
  }
#endif
  return opt->saturateValues;
#else
  return 0.;
#endif
}

double opt_view_adapt_visualization_grid(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->adaptVisualizationGrid = (int)val;
    if(data){
      if(opt->adaptVisualizationGrid)
        data->initAdaptiveData
          (opt->timeStep, opt->maxRecursionLevel, opt->targetError);
      else
        data->destroyAdaptiveData();
      view->setChanged(true);
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.butt[0]->value(opt->adaptVisualizationGrid);
    FlGui::instance()->options->activate("view_adaptive");
  }
#endif
  return opt->adaptVisualizationGrid;
#else
  return 0.;
#endif
}

double opt_view_max_recursion_level(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->maxRecursionLevel = (int)val;
    if(data && data->getAdaptiveData()){
      data->getAdaptiveData()->changeResolution
        (opt->timeStep, opt->maxRecursionLevel, opt->targetError);
      view->setChanged(true);
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[33]->value(opt->maxRecursionLevel);
  }
#endif
  return opt->maxRecursionLevel;
#else
  return 0.;
#endif
}

double opt_view_target_error(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->targetError = val;
    if(data && data->getAdaptiveData()){
      data->getAdaptiveData()->changeResolution
        (opt->timeStep, opt->maxRecursionLevel, opt->targetError);
      view->setChanged(true);
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[34]->value(opt->targetError);
  }
#endif
  return opt->targetError;
#else
  return 0.;
#endif
}

double opt_view_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->type = (int)val;
    if(opt->type < 1 || opt->type > 4)
      opt->type = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[13]->value(opt->type - 1);
  }
#endif
  return opt->type;
#else
  return 0.;
#endif
}

double opt_view_auto_position(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->autoPosition = (int)val;
    if(opt->autoPosition < 0 || opt->autoPosition > 9)
      opt->autoPosition = 0;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[16]->value(opt->autoPosition);
    FlGui::instance()->options->activate("view_axes_auto_2d");
  }
#endif
  return opt->autoPosition;
#else
  return 0.;
#endif
}

double opt_view_position0(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->position[0] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[20]->value(opt->position[0]);
#endif
  return opt->position[0];
#else
  return 0.;
#endif
}

double opt_view_position1(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->position[1] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[21]->value(opt->position[1]);
#endif
  return opt->position[1];
#else
  return 0.;
#endif
}

double opt_view_sampling(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->sampling = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[6]->value(opt->sampling);
#endif
  return opt->sampling;
#else
  return 1.;
#endif
}

double opt_view_size0(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->size[0] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[22]->value(opt->size[0]);
#endif
  return opt->size[0];
#else
  return 0.;
#endif
}

double opt_view_size1(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->size[1] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[23]->value(opt->size[1]);
#endif
  return opt->size[1];
#else
  return 0.;
#endif
}

double opt_view_axes(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axes = (int)val;
    if(opt->axes < 0 || opt->axes > 5)
      opt->axes = 0;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[8]->value(opt->axes);
    FlGui::instance()->options->activate("view_axes");
  }
#endif
  return opt->axes;
#else
  return 0.;
#endif
}

double opt_view_axes_mikado(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesMikado = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.butt[3]->value(opt->axesMikado);
  }
#endif
  return opt->axesMikado;
#else
  return 0.;
#endif
}

double opt_view_axes_auto_position(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesAutoPosition = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.butt[25]->value(opt->axesAutoPosition);
    FlGui::instance()->options->activate("view_axes_auto_3d");
  }
#endif
  return opt->axesAutoPosition;
#else
  return 0.;
#endif
}

double opt_view_axes_xmin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesPosition[0] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[13]->value(opt->axesPosition[0]);
  }
#endif
  return opt->axesPosition[0];
#else
  return 0.;
#endif
}

double opt_view_axes_xmax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesPosition[1] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[16]->value(opt->axesPosition[1]);
  }
#endif
  return opt->axesPosition[1];
#else
  return 0.;
#endif
}

double opt_view_axes_ymin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesPosition[2] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[14]->value(opt->axesPosition[2]);
  }
#endif
  return opt->axesPosition[2];
#else
  return 0.;
#endif
}

double opt_view_axes_ymax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesPosition[3] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[17]->value(opt->axesPosition[3]);
  }
#endif
  return opt->axesPosition[3];
#else
  return 0.;
#endif
}

double opt_view_axes_zmin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesPosition[4] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[15]->value(opt->axesPosition[4]);
  }
#endif
  return opt->axesPosition[4];
#else
  return 0.;
#endif
}

double opt_view_axes_zmax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesPosition[5] = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[18]->value(opt->axesPosition[5]);
  }
#endif
  return opt->axesPosition[5];
#else
  return 0.;
#endif
}

double opt_view_axes_tics0(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesTics[0] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[3]->value(opt->axesTics[0]);
  }
#endif
  return opt->axesTics[0];
#else
  return 0.;
#endif
}

double opt_view_axes_tics1(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesTics[1] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[4]->value(opt->axesTics[1]);
  }
#endif
  return opt->axesTics[1];
#else
  return 0.;
#endif
}

double opt_view_axes_tics2(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->axesTics[2] = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[5]->value(opt->axesTics[2]);
  }
#endif
  return opt->axesTics[2];
#else
  return 0.;
#endif
}

double opt_view_nb_iso(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->nbIso = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[30]->value(opt->nbIso);
#endif
  return opt->nbIso;
#else
  return 0.;
#endif
}

double opt_view_boundary(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->boundary = (int)val;
    if(opt->boundary < 0 || opt->boundary > 3)
      opt->boundary = 0;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[9]->value(opt->boundary);
  }
#endif
  return opt->boundary;
#else
  return 0.;
#endif
}

double opt_view_light(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->light = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    FlGui::instance()->options->view.butt[11]->value(opt->light);
    FlGui::instance()->options->activate("view_light");
  }
#endif
  return opt->light;
#else
  return 0.;
#endif
}

double opt_view_light_two_side(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->lightTwoSide = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[9]->value(opt->lightTwoSide);
#endif
  return opt->lightTwoSide;
#else
  return 0.;
#endif
}

double opt_view_light_lines(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->lightLines = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[8]->value(opt->lightLines);
#endif
  return opt->lightLines;
#else
  return 0.;
#endif
}

double opt_view_smooth_normals(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->smoothNormals = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[12]->value(opt->smoothNormals);
#endif
  return opt->smoothNormals;
#else
  return 0.;
#endif
}

double opt_view_angle_smooth_normals(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->angleSmoothNormals = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[10]->value(opt->angleSmoothNormals);
#endif
  return opt->angleSmoothNormals;
#else
  return 0.;
#endif
}

double opt_view_show_element(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->showElement = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[10]->value(opt->showElement);
#endif
  return opt->showElement;
#else
  return 0.;
#endif
}

double opt_view_show_time(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->showTime = (int)val;
    if(opt->showTime < 0 || opt->showTime > 4)
      opt->showTime = 0;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.choice[12]->value(opt->showTime);
#endif
  return opt->showTime;
#else
  return 0.;
#endif
}

double opt_view_show_scale(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->showScale = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[4]->value(opt->showScale);
#endif
  return opt->showScale;
#else
  return 0.;
#endif
}

double opt_view_draw_strings(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawStrings = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[5]->value(opt->drawStrings);
#endif
  return opt->drawStrings;
#else
  return 0.;
#endif
}

double opt_view_draw_points(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawPoints = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawPoints)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[0].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[0].clear();
  }
#endif
  return opt->drawPoints;
#else
  return 0.;
#endif
}

double opt_view_draw_lines(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawLines = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawLines)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[1].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[1].clear();
  }
#endif
  return opt->drawLines;
#else
  return 0.;
#endif
}

double opt_view_draw_triangles(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawTriangles = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawTriangles)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[2].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[2].clear();
  }
#endif
  return opt->drawTriangles;
#else
  return 0.;
#endif
}

double opt_view_draw_quadrangles(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawQuadrangles = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawQuadrangles)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[3].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[3].clear();
  }
#endif
  return opt->drawQuadrangles;
#else
  return 0.;
#endif
}

double opt_view_draw_tetrahedra(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawTetrahedra = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawTetrahedra)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[4].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[4].clear();
  }
#endif
  return opt->drawTetrahedra;
#else
  return 0.;
#endif
}

double opt_view_draw_hexahedra(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawHexahedra = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawHexahedra)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[5].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[5].clear();
  }
#endif
  return opt->drawHexahedra;
#else
  return 0.;
#endif
}

double opt_view_draw_prisms(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawPrisms = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawPrisms)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[6].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[6].clear();
  }
#endif
  return opt->drawPrisms;
#else
  return 0.;
#endif
}

double opt_view_draw_pyramids(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawPyramids = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawPyramids)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[7].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[1]->menu())[7].clear();
  }
#endif
  return opt->drawPyramids;
#else
  return 0.;
#endif
}

double opt_view_draw_scalars(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawScalars = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawScalars)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[0]->menu())[0].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[0]->menu())[0].clear();
  }
#endif
  return opt->drawScalars;
#else
  return 0.;
#endif
}

double opt_view_draw_vectors(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawVectors = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawVectors)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[0]->menu())[1].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[0]->menu())[1].clear();
  }
#endif
  return opt->drawVectors;
#else
  return 0.;
#endif
}

double opt_view_draw_tensors(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawTensors = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->drawTensors)
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[0]->menu())[2].set();
    else
      ((Fl_Menu_Item*)FlGui::instance()->options->view.menu[0]->menu())[2].clear();
  }
#endif
  return opt->drawTensors;
#else
  return 0.;
#endif
}

double opt_view_draw_skin_only(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->drawSkinOnly = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.butt[2]->value(opt->drawSkinOnly);
#endif
  return opt->drawSkinOnly;
#else
  return 0.;
#endif
}

double opt_view_scale_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->scaleType = (int)val;
    if(opt->scaleType < 1 || opt->scaleType > 3)
      opt->scaleType = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[1]->value(opt->scaleType - 1);
  }
#endif
  return opt->scaleType;
#else
  return 0.;
#endif
}

double opt_view_range_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->rangeType = (int)val;
    if(opt->rangeType < 1 || opt->rangeType > 3)
      opt->rangeType = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    FlGui::instance()->options->view.choice[7]->value(opt->rangeType - 1);
    FlGui::instance()->options->activate("custom_range");
  }
#endif
  return opt->rangeType;
#else
  return 0.;
#endif
}

double opt_view_tensor_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->tensorType = (int)val;
    if(opt->tensorType > 6 || opt->tensorType < 1)
      opt->tensorType = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[4]->value(opt->tensorType - 1);
  }
#endif
  return opt->tensorType;
#else
  return 0.;
#endif
}

double opt_view_vector_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->vectorType = (int)val;
    if(opt->vectorType < 1 || opt->vectorType > 6)
      opt->vectorType = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[2]->value(opt->vectorType - 1);
  }
#endif
  return opt->vectorType;
#else
  return 0.;
#endif
}

double opt_view_glyph_location(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->glyphLocation = (int)val;
    if(opt->glyphLocation < 1 || opt->glyphLocation > 2)
      opt->glyphLocation = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[3]->value(opt->glyphLocation - 1);
  }
#endif
  return opt->glyphLocation;
#else
  return 0.;
#endif
}

double opt_view_center_glyphs(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->centerGlyphs = (int)val;
    if(opt->centerGlyphs < 0 || opt->centerGlyphs > 2)
      opt->glyphLocation = 0;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[15]->value(opt->centerGlyphs);
  }
#endif
  return opt->centerGlyphs;
#else
  return 0.;
#endif
}

double opt_view_point_size(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->pointSize = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[61]->value(opt->pointSize);
#endif
  return opt->pointSize;
#else
  return 0.;
#endif
}

double opt_view_line_width(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->lineWidth = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[62]->value(opt->lineWidth);
#endif
  return opt->lineWidth;
#else
  return 0.;
#endif
}

double opt_view_point_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->pointType = (int)val;
    if(opt->pointType < 0 || opt->pointType > 3)
      opt->pointType = 0;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[5]->value(opt->pointType);
  }
#endif
  return opt->pointType;
#else
  return 0.;
#endif
}

double opt_view_line_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->lineType = (int)val;
    if(opt->lineType < 0 || opt->lineType > 2)
      opt->lineType = 0;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[6]->value(opt->lineType);
  }
#endif
  return opt->lineType;
#else
  return 0.;
#endif
}

double opt_view_colormap_alpha(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.dpar[COLORTABLE_ALPHA] = val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.dpar[COLORTABLE_ALPHA];
#else
  return 0.;
#endif
}

double opt_view_colormap_alpha_power(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.dpar[COLORTABLE_ALPHAPOW] = val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.dpar[COLORTABLE_ALPHAPOW];
#else
  return 0.;
#endif
}

double opt_view_colormap_beta(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.dpar[COLORTABLE_BETA] = val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.dpar[COLORTABLE_BETA];
#else
  return 0.;
#endif
}

double opt_view_colormap_bias(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.dpar[COLORTABLE_BIAS] = val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.dpar[COLORTABLE_BIAS];
#else
  return 0.;
#endif
}

double opt_view_colormap_curvature(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.dpar[COLORTABLE_CURVATURE] = val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.dpar[COLORTABLE_CURVATURE];
#else
  return 0.;
#endif
}

double opt_view_colormap_invert(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.ipar[COLORTABLE_INVERT] = (int)val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.ipar[COLORTABLE_INVERT];
#else
  return 0.;
#endif
}

double opt_view_colormap_number(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.ipar[COLORTABLE_NUMBER] = (int)val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.ipar[COLORTABLE_NUMBER];
#else
  return 0.;
#endif
}

double opt_view_colormap_rotation(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.ipar[COLORTABLE_ROTATION] = (int)val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.ipar[COLORTABLE_ROTATION];
#else
  return 0.;
#endif
}

double opt_view_colormap_swap(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->colorTable.ipar[COLORTABLE_SWAP] = (int)val;
    ColorTable_Recompute(&opt->colorTable);
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.colorbar->redraw();
  }
#endif
  return opt->colorTable.ipar[COLORTABLE_SWAP];
#else
  return 0.;
#endif
}

double opt_view_external_view(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->externalViewIndex = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    // warning: Fl_Choice::size() returns number of items+1
    int item = opt->externalViewIndex + 1;
    if(item > -1 && item < FlGui::instance()->options->view.choice[10]->size()-1)
      FlGui::instance()->options->view.choice[10]->value(item);
    else
      FlGui::instance()->options->view.choice[10]->value(0);
  }
#endif
  return opt->externalViewIndex;
#else
  return 0.;
#endif
}

double opt_view_gen_raise_view(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->viewIndexForGenRaise = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    // warning: Fl_Choice::size() returns number of items+1
    int item = opt->viewIndexForGenRaise + 1;
    if(item > -1 && item < FlGui::instance()->options->view.choice[11]->size()-1)
      FlGui::instance()->options->view.choice[11]->value(item);
    else
      FlGui::instance()->options->view.choice[11]->value(0);
  }
#endif
  return opt->viewIndexForGenRaise;
#else
  return 0.;
#endif
}

double opt_view_gen_raise_factor(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->genRaiseFactor = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[2]->value(opt->genRaiseFactor);
#endif
  return opt->genRaiseFactor;
#else
  return 0.;
#endif
}

double opt_view_use_gen_raise(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->useGenRaise = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    FlGui::instance()->options->view.butt[6]->value(opt->useGenRaise);
    FlGui::instance()->options->activate("view_general_transform");
  }
#endif
  return opt->useGenRaise;
#else
  return 0.;
#endif
}

double opt_view_use_stipple(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->useStipple = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    FlGui::instance()->options->view.butt[26]->value(opt->useStipple);
  }
#endif
  return opt->useStipple;
#else
  return 0.;
#endif
}

double opt_view_clip(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->clip = (int)val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    FlGui::instance()->clipping->resetBrowser();
  }
#endif
  return opt->clip;
#else
  return 0.;
#endif
}

double opt_view_force_num_components(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->forceNumComponents = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    if(opt->forceNumComponents == 1)
      FlGui::instance()->options->view.choice[14]->value(1);
    else if(opt->forceNumComponents == 3)
      FlGui::instance()->options->view.choice[14]->value(2);
    else if(opt->forceNumComponents == 9)
      FlGui::instance()->options->view.choice[14]->value(3);
    else
      FlGui::instance()->options->view.choice[14]->value(0);
  }
#endif
  return opt->forceNumComponents;
#else
  return 0.;
#endif
}

static double ovcm(OPT_ARGS_NUM, int nn)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(action & GMSH_SET) {
    opt->componentMap[nn] = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    FlGui::instance()->options->view.value[70 + nn]->value
      (opt->componentMap[nn]);
  }
#endif
  return opt->componentMap[nn];
#else
  return 0.;
#endif
}

double opt_view_component_map0(OPT_ARGS_NUM){ return ovcm(num, action, val, 0); }
double opt_view_component_map1(OPT_ARGS_NUM){ return ovcm(num, action, val, 1); }
double opt_view_component_map2(OPT_ARGS_NUM){ return ovcm(num, action, val, 2); }
double opt_view_component_map3(OPT_ARGS_NUM){ return ovcm(num, action, val, 3); }
double opt_view_component_map4(OPT_ARGS_NUM){ return ovcm(num, action, val, 4); }
double opt_view_component_map5(OPT_ARGS_NUM){ return ovcm(num, action, val, 5); }
double opt_view_component_map6(OPT_ARGS_NUM){ return ovcm(num, action, val, 6); }
double opt_view_component_map7(OPT_ARGS_NUM){ return ovcm(num, action, val, 7); }
double opt_view_component_map8(OPT_ARGS_NUM){ return ovcm(num, action, val, 8); }

double opt_print_file_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.fileFormat = (int)val;
  return CTX::instance()->print.fileFormat;
}

double opt_print_eps_compress(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsCompress = (int)val;
  return CTX::instance()->print.epsCompress;
}

double opt_print_eps_ps3shading(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsPS3Shading = (int)val;
  return CTX::instance()->print.epsPS3Shading;
}

double opt_print_eps_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsQuality = (int)val;
  return CTX::instance()->print.epsQuality;
}

double opt_print_eps_occlusion_culling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsOcclusionCulling = (int)val;
  return CTX::instance()->print.epsOcclusionCulling;
}

double opt_print_eps_best_root(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsBestRoot = (int)val;
  return CTX::instance()->print.epsBestRoot;
}

double opt_print_eps_line_width_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsLineWidthFactor = val;
  return CTX::instance()->print.epsLineWidthFactor;
}

double opt_print_eps_point_size_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.epsPointSizeFactor = val;
  return CTX::instance()->print.epsPointSizeFactor;
}

double opt_print_jpeg_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.jpegQuality = (int)val;
  return CTX::instance()->print.jpegQuality;
}

double opt_print_jpeg_smoothing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.jpegSmoothing = (int)val;
  return CTX::instance()->print.jpegSmoothing;
}

double opt_print_geo_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.geoLabels = (int)val;
  return CTX::instance()->print.geoLabels;
}

double opt_print_geo_only_physicals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.geoOnlyPhysicals = (int)val;
  return CTX::instance()->print.geoOnlyPhysicals;
}

double opt_print_pos_elementary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.posElementary = (int)val;
  return CTX::instance()->print.posElementary;
}

double opt_print_pos_element(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.posElement = (int)val;
  return CTX::instance()->print.posElement;
}

double opt_print_pos_gamma(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.posGamma = (int)val;
  return CTX::instance()->print.posGamma;
}

double opt_print_pos_eta(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.posEta = (int)val;
  return CTX::instance()->print.posEta;
}

double opt_print_pos_rho(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.posRho = (int)val;
  return CTX::instance()->print.posRho;
}

double opt_print_pos_disto(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.posDisto = (int)val;
  return CTX::instance()->print.posDisto;
}

double opt_print_gif_dither(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.gifDither = (int)val;
  return CTX::instance()->print.gifDither;
}

double opt_print_gif_sort(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.gifSort = (int)val;
  return CTX::instance()->print.gifSort;
}

double opt_print_gif_interlace(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.gifInterlace = (int)val;
  return CTX::instance()->print.gifInterlace;
}

double opt_print_gif_transparent(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.gifTransparent = (int)val;
  return CTX::instance()->print.gifTransparent;
}

double opt_print_background(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.background = (int)val;
  return CTX::instance()->print.background;
}

double opt_print_text(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.text = (int)val;
  return CTX::instance()->print.text;
}

double opt_print_tex_as_equation(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.texAsEquation = (int)val;
  return CTX::instance()->print.texAsEquation;
}

double opt_print_composite_windows(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.compositeWindows = (int)val;
  return CTX::instance()->print.compositeWindows;
}

double opt_print_delete_tmp_files(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->print.deleteTmpFiles = (int)val;
  return CTX::instance()->print.deleteTmpFiles;
}

// Color option routines

#if defined(HAVE_FLTK)

#define CCC(col,but)                                                    \
  if(FlGui::available() && (action & GMSH_GUI)){                          \
    Fl_Color c = fl_color_cube(CTX::instance()->unpackRed(col)*FL_NUM_RED/256, \
                               CTX::instance()->unpackGreen(col)*FL_NUM_GREEN/256, \
                               CTX::instance()->unpackBlue(col)*FL_NUM_BLUE/256); \
    (but)->color(c);                                                    \
    (but)->labelcolor(fl_contrast(FL_BLACK,c));                         \
    (but)->redraw();                                                    \
  }

#endif

unsigned int opt_general_color_background(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.bg = val;
#if defined(HAVE_FLTK)
    if(FlGui::available())
      FlGui::instance()->options->view.colorbar->redraw();
#endif
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.bg, FlGui::instance()->options->general.color[0]);
#endif
  return CTX::instance()->color.bg;
}

unsigned int opt_general_color_background_gradient(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.bgGrad = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.bgGrad, FlGui::instance()->options->general.color[1]);
#endif
  return CTX::instance()->color.bgGrad;
}

unsigned int opt_general_color_foreground(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.fg = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.fg, FlGui::instance()->options->general.color[2]);
#endif
  return CTX::instance()->color.fg;
}

unsigned int opt_general_color_text(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.text = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.text, FlGui::instance()->options->general.color[3]);
  drawContext::global()->resetFontTextures();
#endif
  return CTX::instance()->color.text;
}

unsigned int opt_general_color_axes(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.axes = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.axes, FlGui::instance()->options->general.color[4]);
  drawContext::global()->resetFontTextures();
#endif
  return CTX::instance()->color.axes;
}

unsigned int opt_general_color_small_axes(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.smallAxes = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.smallAxes, FlGui::instance()->options->general.color[5]);
  drawContext::global()->resetFontTextures();
#endif
  return CTX::instance()->color.smallAxes;
}

unsigned int opt_general_color_ambient_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++)
      CTX::instance()->color.ambientLight[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.ambientLight[0], FlGui::instance()->options->general.color[6]);
#endif
  return CTX::instance()->color.ambientLight[0];
}

unsigned int opt_general_color_diffuse_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++)
      CTX::instance()->color.diffuseLight[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.diffuseLight[0], FlGui::instance()->options->general.color[7]);
#endif
  return CTX::instance()->color.diffuseLight[0];
}

unsigned int opt_general_color_specular_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++)
      CTX::instance()->color.specularLight[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.specularLight[0], FlGui::instance()->options->general.color[8]);
#endif
  return CTX::instance()->color.specularLight[0];
}

unsigned int opt_geometry_color_points(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.point = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.point, FlGui::instance()->options->geo.color[0]);
#endif
  return CTX::instance()->color.geom.point;
}

unsigned int opt_geometry_color_lines(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.line = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.line, FlGui::instance()->options->geo.color[1]);
#endif
  return CTX::instance()->color.geom.line;
}

unsigned int opt_geometry_color_surfaces(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.surface = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.surface, FlGui::instance()->options->geo.color[2]);
#endif
  return CTX::instance()->color.geom.surface;
}

unsigned int opt_geometry_color_volumes(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.volume = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.volume, FlGui::instance()->options->geo.color[3]);
#endif
  return CTX::instance()->color.geom.volume;
}

unsigned int opt_geometry_color_selection(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.selection = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.selection, FlGui::instance()->options->geo.color[4]);
#endif
  return CTX::instance()->color.geom.selection;
}

unsigned int opt_geometry_color_highlight0(OPT_ARGS_COL)
{
  if(action & GMSH_SET){
    CTX::instance()->color.geom.highlight[0] = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.highlight[0], FlGui::instance()->options->geo.color[5]);
#endif
  return CTX::instance()->color.geom.highlight[0];
}

unsigned int opt_geometry_color_highlight1(OPT_ARGS_COL)
{
  if(action & GMSH_SET){
    CTX::instance()->color.geom.highlight[1] = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.highlight[1], FlGui::instance()->options->geo.color[6]);
#endif
  return CTX::instance()->color.geom.highlight[1];
}

unsigned int opt_geometry_color_highlight2(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.highlight[2] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.highlight[2], FlGui::instance()->options->geo.color[7]);
#endif
  return CTX::instance()->color.geom.highlight[2];
}

unsigned int opt_geometry_color_tangents(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.tangents = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.tangents, FlGui::instance()->options->geo.color[8]);
#endif
  return CTX::instance()->color.geom.tangents;
}

unsigned int opt_geometry_color_normals(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    CTX::instance()->color.geom.normals = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.normals, FlGui::instance()->options->geo.color[9]);
#endif
  return CTX::instance()->color.geom.normals;
}

unsigned int opt_geometry_color_projection(OPT_ARGS_COL)
{
  if(action & GMSH_SET){
    CTX::instance()->color.geom.projection = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.projection, FlGui::instance()->options->geo.color[10]);
#endif
  return CTX::instance()->color.geom.projection;
}

unsigned int opt_mesh_color_points(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.mesh.vertex = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.vertex, FlGui::instance()->options->mesh.color[0]);
#endif
  return CTX::instance()->color.mesh.vertex;
}

unsigned int opt_mesh_color_points_sup(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.mesh.vertexSup = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.vertexSup, FlGui::instance()->options->mesh.color[1]);
#endif
  return CTX::instance()->color.mesh.vertexSup;
}

unsigned int opt_mesh_color_lines(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.line != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->color.mesh.line = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.line, FlGui::instance()->options->mesh.color[2]);
#endif
  return CTX::instance()->color.mesh.line;
}

unsigned int opt_mesh_color_triangles(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.triangle != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->color.mesh.triangle = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.triangle, FlGui::instance()->options->mesh.color[3]);
#endif
  return CTX::instance()->color.mesh.triangle;
}

unsigned int opt_mesh_color_quadrangles(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.quadrangle != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->color.mesh.quadrangle = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.quadrangle, FlGui::instance()->options->mesh.color[4]);
#endif
  return CTX::instance()->color.mesh.quadrangle;
}

unsigned int opt_mesh_color_tetrahedra(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.tetrahedron != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->color.mesh.tetrahedron = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.tetrahedron, FlGui::instance()->options->mesh.color[5]);
#endif
  return CTX::instance()->color.mesh.tetrahedron;
}

unsigned int opt_mesh_color_hexahedra(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.hexahedron != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->color.mesh.hexahedron = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.hexahedron,
      FlGui::instance()->options->mesh.color[6]);
#endif
  return CTX::instance()->color.mesh.hexahedron;
}

unsigned int opt_mesh_color_prisms(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.prism != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->color.mesh.prism = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.prism, FlGui::instance()->options->mesh.color[7]);
#endif
  return CTX::instance()->color.mesh.prism;
}

unsigned int opt_mesh_color_pyramid(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.pyramid != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->color.mesh.pyramid = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.pyramid, FlGui::instance()->options->mesh.color[8]);
#endif
  return CTX::instance()->color.mesh.pyramid;
}

unsigned int opt_mesh_color_tangents(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.mesh.tangents = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.tangents, FlGui::instance()->options->mesh.color[9]);
#endif
  return CTX::instance()->color.mesh.tangents;
}

unsigned int opt_mesh_color_normals(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.mesh.normals = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.normals, FlGui::instance()->options->mesh.color[10]);
#endif
  return CTX::instance()->color.mesh.normals;
}

unsigned int opt_mesh_color_(int i, OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // partition
    if(CTX::instance()->color.mesh.carousel[i] != val &&
       CTX::instance()->mesh.colorCarousel == 3)
      CTX::instance()->mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->color.mesh.carousel[i] = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.carousel[i], FlGui::instance()->options->mesh.color[11+i]);
#endif
  return CTX::instance()->color.mesh.carousel[i];
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
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.point = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.point, FlGui::instance()->options->view.color[0]);
  }
#endif
  return opt->color.point;
#else
  return 0;
#endif
}

unsigned int opt_view_color_lines(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.line = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.line, FlGui::instance()->options->view.color[1]);
  }
#endif
  return opt->color.line;
#else
  return 0;
#endif
}

unsigned int opt_view_color_triangles(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.triangle = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.triangle, FlGui::instance()->options->view.color[2]);
  }
#endif
  return opt->color.triangle;
#else
  return 0;
#endif
}

unsigned int opt_view_color_quadrangles(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.quadrangle = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.quadrangle, FlGui::instance()->options->view.color[3]);
  }
#endif
  return opt->color.quadrangle;
#else
  return 0;
#endif
}

unsigned int opt_view_color_tetrahedra(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.tetrahedron = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.tetrahedron, FlGui::instance()->options->view.color[4]);
  }
#endif
  return opt->color.tetrahedron;
#else
  return 0;
#endif
}

unsigned int opt_view_color_hexahedra(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.hexahedron = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.hexahedron, FlGui::instance()->options->view.color[5]);
  }
#endif
  return opt->color.hexahedron;
#else
  return 0;
#endif
}

unsigned int opt_view_color_prisms(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.prism = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.prism, FlGui::instance()->options->view.color[6]);
  }
#endif
  return opt->color.prism;
#else
  return 0;
#endif
}

unsigned int opt_view_color_pyramids(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.pyramid = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.pyramid, FlGui::instance()->options->view.color[7]);
  }
#endif
  return opt->color.pyramid;
#else
  return 0;
#endif
}

unsigned int opt_view_color_tangents(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.tangents = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.tangents, FlGui::instance()->options->view.color[8]);
  }
#endif
  return opt->color.tangents;
#else
  return 0;
#endif
}

unsigned int opt_view_color_normals(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.normals = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.normals, FlGui::instance()->options->view.color[9]);
  }
#endif
  return opt->color.normals;
#else
  return 0;
#endif
}

unsigned int opt_view_color_text2d(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.text2d = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.text2d, FlGui::instance()->options->view.color[10]);
    drawContext::global()->resetFontTextures();
  }
#endif
  return opt->color.text2d;
#else
  return 0;
#endif
}

unsigned int opt_view_color_text3d(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.text3d = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.text3d, FlGui::instance()->options->view.color[11]);
    drawContext::global()->resetFontTextures();
  }
#endif
  return opt->color.text3d;
#else
  return 0;
#endif
}

unsigned int opt_view_color_axes(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.axes = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.axes, FlGui::instance()->options->view.color[12]);
    drawContext::global()->resetFontTextures();
  }
#endif
  return opt->color.axes;
#else
  return 0;
#endif
}

unsigned int opt_view_color_background2d(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEW(0);
  if(action & GMSH_SET) {
    opt->color.background2d = val;
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)){
    CCC(opt->color.background2d, FlGui::instance()->options->view.color[13]);
    drawContext::global()->resetFontTextures();
  }
#endif
  return opt->color.background2d;
#else
  return 0;
#endif
}
