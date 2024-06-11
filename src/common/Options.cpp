// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits>
#include "GmshConfig.h"
#include "GmshVersion.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "StringUtils.h"
#include "GModel.h"
#include "Context.h"
#include "Options.h"
#include "OS.h"
#include "Colors.h"
#include "CommandLine.h"
#include "GamePad.h"
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
#include "drawContextFltk.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "clippingWindow.h"
#include "onelabGroup.h"
#include "viewButton.h"
#include "drawContextFltkCairo.h"
#include "drawContextFltkStringTexture.h"
#endif

// General routines for string options

bool StringOption(int action, const char *category, int num, const char *name,
                  std::string &val, bool warnIfUnknown)
{
  StringXString *s = nullptr;
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
  else {
    if(warnIfUnknown)
      Msg::Error("Unknown string option category '%s'", category);
    return false;
  }

  int i = 0;
  while(s[i].str && strcmp(s[i].str, name)) i++;
  if(!s[i].str) {
    if(warnIfUnknown)
      Msg::Error("Unknown string option '%s.%s'", category, name);
    return false;
  }

  if(action & GMSH_GET_DEFAULT)
    val = s[i].def;
  else if(action & GMSH_SET_DEFAULT)
    val = s[i].function(num, action | GMSH_SET, s[i].def);
  else
    val = s[i].function(num, action, val);
  return true;
}

static void SetDefaultStringOptions(int num, StringXString s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_SET_DEFAULT | GMSH_SET, s[i].def);
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
                               StringXString s[], const char *prefix,
                               FILE *file, std::vector<std::string> *vec = nullptr)
{
  int i = 0;
  while(s[i].str) {
    if((s[i].level & level) && !(s[i].level & GMSH_DEPRECATED)) {
      if(!diff || s[i].function(num, GMSH_GET, "") != s[i].def) {
        char tmp[1024];
        sprintf(tmp, "%s%s = \"%s\";%s%s", prefix, s[i].str,
                s[i].function(num, GMSH_GET, "").c_str(), help ? " // " : "",
                help ? s[i].help : "");
        if(file)
          fprintf(file, "%s\n", tmp);
        else {
          // remove \n, \t, \r
          for(std::size_t i = 0; i < strlen(tmp); i++)
            if(tmp[i] == '\n' || tmp[i] == '\t' || tmp[i] == '\r') tmp[i] = ' ';
          if(vec)
            vec->push_back(std::string(tmp) + '\0' + "string");
          else
            Msg::Direct("%s", tmp);
        }
      }
    }
    i++;
  }
}

static const char *GetOptionSaveLevel(int level)
{
  if(level & GMSH_SESSIONRC) { return "General.SessionFileName"; }
  else if(level & GMSH_OPTIONSRC) {
    return "General.OptionsFileName";
  }
  else {
    return "-";
  }
}

static void PrintStringOptionsDoc(StringXString s[], const char *prefix,
                                  FILE *file)
{
  int i = 0;
  while(s[i].str) {
    if(!(s[i].level & GMSH_DEPRECATED)) {
      fprintf(file, "@item %s%s\n", prefix, s[i].str);
      fprintf(file, "%s@*\n", s[i].help);

      // sanitize the string for texinfo
      std::string val = s[i].function(0, GMSH_GET, "");
      for(std::size_t j = 1; j < val.size(); j++) {
        if(val[j] == '\n' && val[j - 1] == '\n') val[j - 1] = '.';
      }
      fprintf(file, "Default value: @code{\"%s\"}@*\n", val.c_str());
      fprintf(file, "Saved in: @code{%s}\n\n", GetOptionSaveLevel(s[i].level));
    }
    i++;
  }
}

// General routines for numeric options

bool NumberOption(int action, const char *category, int num, const char *name,
                  double &val, bool warnIfUnknown)
{
  StringXNumber *s = nullptr;
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
  else {
    if(warnIfUnknown)
      Msg::Error("Unknown number option category '%s'", category);
    return false;
  }

  int i = 0;
  while(s[i].str && strcmp(s[i].str, name)) i++;
  if(!s[i].str) {
    if(warnIfUnknown)
      Msg::Error("Unknown number option '%s.%s'", category, name);
    return false;
  }

  if(action & GMSH_GET_DEFAULT)
    val = s[i].def;
  else if(action & GMSH_SET_DEFAULT)
    val = s[i].function(num, action | GMSH_SET, s[i].def);
  else
    val = s[i].function(num, action, val);

  return true;
}

static void SetDefaultNumberOptions(int num, StringXNumber s[])
{
  int i = 0;
  while(s[i].str) {
    s[i].function(num, GMSH_SET_DEFAULT | GMSH_SET, s[i].def);
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
                               StringXNumber s[], const char *prefix,
                               FILE *file, std::vector<std::string> *vec = nullptr)
{
  int i = 0;
  char tmp[1024];
  while(s[i].str) {
    if((s[i].level & level) && !(s[i].level & GMSH_DEPRECATED)) {
      if(!diff || (s[i].function(num, GMSH_GET, 0) != s[i].def)) {
        sprintf(tmp, "%s%s = %.16g;%s%s", prefix, s[i].str,
                s[i].function(num, GMSH_GET, 0), help ? " // " : "",
                help ? s[i].help : "");
        if(file)
          fprintf(file, "%s\n", tmp);
        else if(vec)
          vec->push_back(std::string(tmp) + '\0' + "number");
        else
          Msg::Direct(tmp);
      }
    }
    i++;
  }
}

static void PrintNumberOptionsDoc(StringXNumber s[], const char *prefix,
                                  FILE *file)
{
  int i = 0;
  while(s[i].str) {
    if(!(s[i].level & GMSH_DEPRECATED)) {
      fprintf(file, "@item %s%s\n", prefix, s[i].str);
      fprintf(file, "%s@*\n", s[i].help);
      fprintf(file, "Default value: @code{%g}@*\n",
              s[i].function(0, GMSH_GET, 0));
      fprintf(file, "Saved in: @code{%s}\n\n", GetOptionSaveLevel(s[i].level));
    }
    i++;
  }
}

// General routines for color options

bool ColorOption(int action, const char *category, int num, const char *name,
                 unsigned int &val, bool warnIfUnknown)
{
  StringXColor *s = nullptr;
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
  else {
    if(warnIfUnknown)
      Msg::Error("Unknown color option category '%s'", category);
    return false;
  }

  int i = 0;
  while(s[i].str && strcmp(s[i].str, name)) i++;
  if(!s[i].str) {
    if(warnIfUnknown)
      Msg::Error("Unknown color option '%s.%s'", category, name);
    return false;
  }

  if(action & GMSH_GET_DEFAULT)
    val = CTX::instance()->packColor(s[i].def1[0], s[i].def1[1], s[i].def1[2],
                                     s[i].def1[3]);
  else if(action & GMSH_SET_DEFAULT)
    val = s[i].function(num, action | GMSH_SET,
                        CTX::instance()->packColor(s[i].def1[0], s[i].def1[1],
                                                   s[i].def1[2], s[i].def1[3]));
  else
    val = s[i].function(num, action, val);
  return true;
}

int GetColorForString(int alpha, const char *str, int *FlagError)
{
  int i = 0;
  while(ColorString[i].str && strcmp(ColorString[i].str, str)) i++;
  *FlagError = !ColorString[i].str ? 1 : 0;
  if(alpha > 0)
    return CTX::instance()->packColor(ColorString[i].int1, ColorString[i].int2,
                                      ColorString[i].int3, alpha);
  else
    return CTX::instance()->packColor(ColorString[i].int1, ColorString[i].int2,
                                      ColorString[i].int3, ColorString[i].int4);
}

bool GetRGBForString(const char *str, int &r, int &g, int &b)
{
  int i = 0;
  while(ColorString[i].str && strcmp(ColorString[i].str, str)) i++;
  if(!ColorString[i].str) {
    r = g = b = 0;
    return false;
  }
  r = ColorString[i].int1;
  g = ColorString[i].int2;
  b = ColorString[i].int3;
  return true;
}

static void SetDefaultColorOptions(int num, StringXColor s[])
{
  int i = 0;
  // Warning: this assumes that CTX::instance()->color_scheme is set...
  switch(CTX::instance()->colorScheme) {
  case 1:
    while(s[i].str) {
      s[i].function(num, GMSH_SET_DEFAULT | GMSH_SET,
                    CTX::instance()->packColor(s[i].def2[0], s[i].def2[1],
                                               s[i].def2[2], s[i].def2[3]));
      i++;
    }
    break;
  case 2:
    while(s[i].str) {
      s[i].function(num, GMSH_SET_DEFAULT | GMSH_SET,
                    CTX::instance()->packColor(s[i].def3[0], s[i].def3[1],
                                               s[i].def3[2], s[i].def3[3]));
      i++;
    }
    break;
  case 3:
    while(s[i].str) {
      s[i].function(num, GMSH_SET_DEFAULT | GMSH_SET,
                    CTX::instance()->packColor(s[i].def4[0], s[i].def4[1],
                                               s[i].def4[2], s[i].def4[3]));
      i++;
    }
    break;
  default:
    while(s[i].str) {
      s[i].function(num, GMSH_SET_DEFAULT | GMSH_SET,
                    CTX::instance()->packColor(s[i].def1[0], s[i].def1[1],
                                               s[i].def1[2], s[i].def1[3]));
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
                              StringXColor s[], const char *prefix, FILE *file,
                              std::vector<std::string> *vec)
{
  int i = 0;
  char tmp[1024];
  while(s[i].str) {
    if((s[i].level & level) && !(s[i].level & GMSH_DEPRECATED)) {
      unsigned int def;
      switch(CTX::instance()->colorScheme) {
      case 1:
        def = CTX::instance()->packColor(s[i].def2[0], s[i].def2[1],
                                         s[i].def2[2], s[i].def2[3]);
        break;
      case 2:
        def = CTX::instance()->packColor(s[i].def3[0], s[i].def3[1],
                                         s[i].def3[2], s[i].def3[3]);
        break;
      case 3:
        def = CTX::instance()->packColor(s[i].def4[0], s[i].def4[1],
                                         s[i].def4[2], s[i].def4[3]);
        break;
      default:
        def = CTX::instance()->packColor(s[i].def1[0], s[i].def1[1],
                                         s[i].def1[2], s[i].def1[3]);
        break;
      }
      if(!diff || (s[i].function(num, GMSH_GET, 0) != def)) {
        sprintf(tmp, "%sColor.%s = {%d,%d,%d};%s%s", prefix, s[i].str,
                CTX::instance()->unpackRed(s[i].function(num, GMSH_GET, 0)),
                CTX::instance()->unpackGreen(s[i].function(num, GMSH_GET, 0)),
                CTX::instance()->unpackBlue(s[i].function(num, GMSH_GET, 0)),
                help ? " // " : "", help ? s[i].help : "");
        if(file)
          fprintf(file, "%s\n", tmp);
        else if(vec)
          vec->push_back(std::string(tmp) + '\0' + "color");
        else
          Msg::Direct(tmp);
      }
    }
    i++;
  }
}

static void PrintColorOptionsDoc(StringXColor s[], const char *prefix,
                                 FILE *file)
{
  int i = 0;
  while(s[i].str) {
    if(!(s[i].level & GMSH_DEPRECATED)) {
      fprintf(file, "@item %sColor.%s\n", prefix, s[i].str);
      fprintf(file, "%s@*\n", s[i].help);
      fprintf(file, "Default value: @code{@{%d,%d,%d@}}@*\n",
              CTX::instance()->unpackRed(s[i].function(0, GMSH_GET, 0)),
              CTX::instance()->unpackGreen(s[i].function(0, GMSH_GET, 0)),
              CTX::instance()->unpackBlue(s[i].function(0, GMSH_GET, 0)));
      fprintf(file, "Saved in: @code{%s}\n\n", GetOptionSaveLevel(s[i].level));
    }
    i++;
  }
}

// General routines

void InitOptions(int num)
{
  CTX::instance()->init();

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
  std::vector<PView *> tmp = PView::list;
  PView::list.clear();
#endif

  InitOptions(num);

#if defined(HAVE_POST)
  PView::list = tmp;
  for(std::size_t i = 0; i < PView::list.size(); i++)
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
                                FILE *file, std::vector<std::string> *vec = nullptr)
{
  if(diff || !help || !(level & GMSH_FULLRC)) return;
  if(file) {
    fprintf(file, "//\n");
    fprintf(file, "// %s\n", cat);
    fprintf(file, "//\n");
  }
  else if(vec) {
    vec->push_back("//");
    vec->push_back(std::string("// ") + cat);
    vec->push_back("//");
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
    opt = PViewOptions::reference();
  else {
    opt = PView::list[num]->getOptions();
    // assume that if we access the colortable we will change it
    PView::list[num]->setChanged(true);
  }
  return &opt->colorTable;
#else
  return 0;
#endif
}

static void PrintColorTable(int num, int diff, const char *prefix, FILE *file,
                            std::vector<std::string> *vec)
{
#if defined(HAVE_POST)
  PViewOptions *opt;
  if(PView::list.empty() || num < 0 || num > (int)PView::list.size() - 1)
    opt = PViewOptions::reference();
  else
    opt = PView::list[num]->getOptions();

  if(diff) {
    // compare the current colormap with a vanilla colormap having the
    // parameters
    GmshColorTable ref;
    ColorTable_InitParam(opt->colorTable.ipar[COLORTABLE_NUMBER], &ref);
    for(int i = 0; i < COLORTABLE_NBMAX_PARAM; i++) {
      ref.ipar[i] = opt->colorTable.ipar[i];
      ref.dpar[i] = opt->colorTable.dpar[i];
    }
    ColorTable_Recompute(&ref);
    if(!ColorTable_Diff(&ref, &opt->colorTable)) return;
  }

  char tmp[1024];
  sprintf(tmp, "%s = {", prefix);
  if(file)
    fprintf(file, "%s\n", tmp);
  else if(vec)
    vec->push_back(tmp);
  else
    Msg::Direct(tmp);
  ColorTable_Print(&opt->colorTable, file, vec);
  sprintf(tmp, "};");
  if(file)
    fprintf(file, "%s\n", tmp);
  else if(vec)
    vec->push_back(tmp);
  else
    Msg::Direct(tmp);
#endif
}

void Sanitize_String_Texi(std::string &s)
{
  int i = -1;
  while((i = s.find('\n', i + 1)) >= 0) {
    s.insert(i, "@*");
    i += 2;
  }
  i = -1;
  while((i = s.find_first_of("{}", i + 1)) >= 0) s.insert(i++, "@");
}

void PrintOptions(int num, int level, int diff, int help, const char *filename,
                  std::vector<std::string> *vec)
{
#if defined(HAVE_FLTK)
  if(FlGui::available()) FlGui::instance()->storeCurrentWindowsInfo();
#endif

  FILE *file;

  if(filename) {
    file = Fopen(filename, "w");
    if(!file) {
      Msg::Error("Unable to open file '%s'", filename);
      return;
    }
  }
  else
    file = nullptr;

  if((level & GMSH_SESSIONRC) && file) {
    fprintf(file, "// Gmsh Session File\n");
    fprintf(file, "//\n");
    fprintf(file,
            "// This file contains session specific info (that is info you\n");
    fprintf(
      file,
      "// want to keep between two Gmsh sessions). You are not supposed\n");
    fprintf(
      file,
      "// to edit it manually, but of course you can. This file will be\n");
    fprintf(file,
            "// entirely rewritten every time you quit Gmsh if the option \n");
    fprintf(file, "// 'General.SaveSession' is set.\n");
    fprintf(file, "//\n");
  }

  if((level & GMSH_OPTIONSRC) && file) {
    fprintf(file, "// Gmsh Option File\n");
    fprintf(file, "//\n");
    fprintf(file,
            "// This file contains configuration options (preferences) that\n");
    fprintf(file,
            "// are loaded each time Gmsh is launched. You can create this\n");
    fprintf(file, "// file by hand, or let Gmsh generate it for you (with\n");
    fprintf(file, "// 'File->Save Default Options'). This file can also be\n");
    fprintf(file,
            "// automatically saved every time you quit Gmsh if the option\n");
    fprintf(file, "// 'General.SaveOptions' is set.\n");
    fprintf(file, "//\n");
  }

  PrintOptionCategory(level, diff, help, "General options (strings)", file,
                      vec);
  PrintStringOptions(num, level, diff, help, GeneralOptions_String, "General.",
                     file, vec);
  PrintOptionCategory(level, diff, help, "General options (numbers)", file,
                      vec);
  PrintNumberOptions(num, level, diff, help, GeneralOptions_Number, "General.",
                     file, vec);
  PrintOptionCategory(level, diff, help, "General options (colors)", file, vec);
  PrintColorOptions(num, level, diff, help, GeneralOptions_Color, "General.",
                    file, vec);

  PrintOptionCategory(level, diff, help, "Geometry options (strings)", file,
                      vec);
  PrintStringOptions(num, level, diff, help, GeometryOptions_String,
                     "Geometry.", file, vec);
  PrintOptionCategory(level, diff, help, "Geometry options (numbers)", file,
                      vec);
  PrintNumberOptions(num, level, diff, help, GeometryOptions_Number,
                     "Geometry.", file, vec);
  PrintOptionCategory(level, diff, help, "Geometry options (colors)", file,
                      vec);
  PrintColorOptions(num, level, diff, help, GeometryOptions_Color, "Geometry.",
                    file, vec);

  PrintOptionCategory(level, diff, help, "Mesh options (strings)", file, vec);
  PrintStringOptions(num, level, diff, help, MeshOptions_String, "Mesh.", file,
                     vec);
  PrintOptionCategory(level, diff, help, "Mesh options (numbers)", file, vec);
  PrintNumberOptions(num, level, diff, help, MeshOptions_Number, "Mesh.", file,
                     vec);
  PrintOptionCategory(level, diff, help, "Mesh options (colors)", file, vec);
  PrintColorOptions(num, level, diff, help, MeshOptions_Color, "Mesh.", file,
                    vec);

  PrintOptionCategory(level, diff, help, "Solver options (strings)", file, vec);
  PrintStringOptions(num, level, diff, help, SolverOptions_String, "Solver.",
                     file, vec);
  PrintOptionCategory(level, diff, help, "Solver options (numbers)", file, vec);
  PrintNumberOptions(num, level, diff, help, SolverOptions_Number, "Solver.",
                     file, vec);
  PrintOptionCategory(level, diff, help, "Solver options (colors)", file, vec);
  PrintColorOptions(num, level, diff, help, SolverOptions_Color, "Solver.",
                    file, vec);

  PrintOptionCategory(level, diff, help, "Post-processing options (strings)",
                      file, vec);
  PrintStringOptions(num, level, diff, help, PostProcessingOptions_String,
                     "PostProcessing.", file, vec);
  PrintOptionCategory(level, diff, help, "Post-processing options (numbers)",
                      file, vec);
  PrintNumberOptions(num, level, diff, help, PostProcessingOptions_Number,
                     "PostProcessing.", file, vec);
  PrintOptionCategory(level, diff, help, "Post-processing options (colors)",
                      file, vec);
  PrintColorOptions(num, level, diff, help, PostProcessingOptions_Color,
                    "PostProcessing.", file, vec);

  if(level & GMSH_FULLRC) {
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++) {
      char tmp[256];
      sprintf(tmp, "View[%lu].", i);
      PrintOptionCategory(level, diff, help, "View options (strings)", file,
                          vec);
      PrintStringOptions(i, level, diff, help, ViewOptions_String, tmp, file,
                         vec);
      PrintOptionCategory(level, diff, help, "View options (numbers)", file,
                          vec);
      PrintNumberOptions(i, level, diff, help, ViewOptions_Number, tmp, file,
                         vec);
      PrintOptionCategory(level, diff, help, "View options (colors)", file,
                          vec);
      PrintColorOptions(i, level, diff, help, ViewOptions_Color, tmp, file,
                        vec);
      strcat(tmp, "ColorTable");
      PrintColorTable(i, diff, tmp, file, vec);
    }
#endif
  }
  else if(level & GMSH_OPTIONSRC) {
    PrintOptionCategory(level, diff, help, "View options (strings)", file, vec);
    PrintStringOptions(num, level, diff, help, ViewOptions_String, "View.",
                       file, vec);
    PrintOptionCategory(level, diff, help, "View options (numbers)", file, vec);
    PrintNumberOptions(num, level, diff, help, ViewOptions_Number, "View.",
                       file, vec);
    PrintOptionCategory(level, diff, help, "View options (colors)", file, vec);
    PrintColorOptions(num, level, diff, help, ViewOptions_Color, "View.", file,
                      vec);
    PrintColorTable(num, diff, "View.ColorTable", file, vec);
  }

  PrintOptionCategory(level, diff, help, "Print options (strings)", file, vec);
  PrintStringOptions(num, level, diff, help, PrintOptions_String, "Print.",
                     file, vec);
  PrintOptionCategory(level, diff, help, "Print options (numbers)", file, vec);
  PrintNumberOptions(num, level, diff, help, PrintOptions_Number, "Print.",
                     file, vec);
  PrintOptionCategory(level, diff, help, "Print options (colors)", file, vec);
  PrintColorOptions(num, level, diff, help, PrintOptions_Color, "Print.", file,
                    vec);

  if(filename) fclose(file);
}

void PrintOptionsDoc()
{
  const char *warn =
    "@c This file was generated by \"gmsh -doc\": do not edit manually!\n\n";

  {
    FILE *file = Fopen("opt_general.texi", "w");
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
  }
  {
    FILE *file = Fopen("opt_print.texi", "w");
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
  }
  {
    FILE *file = Fopen("opt_geometry.texi", "w");
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
  }
  {
    FILE *file = Fopen("opt_mesh.texi", "w");
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
  }
  {
    FILE *file = Fopen("opt_solver.texi", "w");
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
  }
  {
    FILE *file = Fopen("opt_post.texi", "w");
    if(!file) {
      Msg::Error("Unable to open file 'opt_post.texi'");
      return;
    }
    fprintf(file, "%s@ftable @code\n", warn);
    PrintStringOptionsDoc(PostProcessingOptions_String, "PostProcessing.",
                          file);
    PrintNumberOptionsDoc(PostProcessingOptions_Number, "PostProcessing.",
                          file);
    PrintColorOptionsDoc(PostProcessingOptions_Color, "PostProcessing.", file);
    fprintf(file, "@end ftable\n");
    fclose(file);
  }
  {
#if defined(HAVE_POST)
    FILE *file = Fopen("opt_view.texi", "w");
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
            GetOptionSaveLevel(GMSH_FULLRC | GMSH_OPTIONSRC));
    fprintf(file, "@end ftable\n");
    fclose(file);
#endif
  }
  {
#if defined(HAVE_PLUGINS)
    FILE *file = Fopen("plugins.texi", "w");
    if(!file) {
      Msg::Error("Unable to open file 'plugins.texi'");
      return;
    }
    fprintf(file, "%s@ftable @code\n", warn);
    for(auto it =
          PluginManager::instance()->begin();
        it != PluginManager::instance()->end(); ++it) {
      GMSH_Plugin *p = it->second;
      fprintf(file, "@item Plugin(%s)\n", p->getName().c_str());
      std::string help = p->getHelp();
      Sanitize_String_Texi(help);
      fprintf(file, "%s\n", help.c_str());
      int m = p->getNbOptionsStr();
      if(m) {
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
      if(n) {
        fprintf(file, "Numeric options:\n");
        fprintf(file, "@table @code\n");
        for(int i = 0; i < n; i++) {
          StringXNumber *sxn = p->getOption(i);
          fprintf(file, "@item %s\n", sxn->str);
          fprintf(file, "Default value: @code{%g}\n", sxn->def);
        }
        fprintf(file, "@end table\n");
      }
      fprintf(file, "\n");
    }
    fprintf(file, "@end ftable\n");
    fclose(file);
#endif
  }

#if defined(HAVE_MESH)
  {
    FILE *file = Fopen("fields.texi", "w");
    if(!file) {
      Msg::Error("Unable to open file 'fields.texi'");
      return;
    }
    fprintf(file, "%s@ftable @code\n", warn);
    FieldManager &fields = *GModel::current()->getFields();
    for(auto it = fields.mapTypeName.begin(); it != fields.mapTypeName.end();
        it++) {
      if(it->first == "Attractor") continue;
      Field *f = (*it->second)();
      if(f->isDeprecated()) continue;
      fprintf(file, "@item %s\n", it->first.c_str());
      std::string field_description = f->getDescription();
      Sanitize_String_Texi(field_description);
      fprintf(file, "%s@*\n", field_description.c_str());
      if(!f->options.empty()) {
        fprintf(file, "@*\nOptions:@*\n");
        fprintf(file, "@table @code\n");
        for(auto it2 = f->options.begin(); it2 != f->options.end(); it2++) {
          if(it2->second->isDeprecated()) continue;
          fprintf(file, "@item %s\n", it2->first.c_str());
          std::string val;
          it2->second->getTextRepresentation(val);
          Sanitize_String_Texi(val);
          fprintf(file, "%s@*\nType: %s@*\nDefault value: @code{%s}\n",
                  it2->second->getDescription().c_str(),
                  it2->second->getTypeName().c_str(), val.c_str());
        }
        fprintf(file, "@end table\n\n");
      }
      if(!f->callbacks.empty()) {
        fprintf(file, "Actions:@*\n");
        fprintf(file, "@table @code\n");
        for(auto it2 =
              f->callbacks.begin();
            it2 != f->callbacks.end(); it2++) {
          fprintf(file, "@item %s\n", it2->first.c_str());
          fprintf(file, "%s@*\n", it2->second->getDescription().c_str());
        }
        fprintf(file, "@end table\n\n");
      }
    }
    fprintf(file, "@end ftable\n");
    fclose(file);
  }
#endif
  {
    FILE *file = Fopen("shortcuts.texi", "w");
    if(!file) {
      Msg::Error("Unable to open file 'shortcuts.texi'");
      return;
    }
    std::vector<std::pair<std::string, std::string> > s =
      GetShortcutsUsage("Ctrl+");
    fprintf(file, "%s@table @kbd\n", warn);
    for(std::size_t i = 0; i < s.size(); i++)
      fprintf(file, "@item %s\n%s\n", s[i].first.c_str(), s[i].second.c_str());
    fprintf(file, "@end table\n");
    fclose(file);
  }
  {
    FILE *file = Fopen("mouse.texi", "w");
    if(!file) {
      Msg::Error("Unable to open file 'mouse.texi'");
      return;
    }
    std::vector<std::pair<std::string, std::string> > s = GetMouseUsage();
    fprintf(file, "%s@table @kbd\n", warn);
    for(std::size_t i = 0; i < s.size(); i++)
      fprintf(file, "@item %s\n%s\n", s[i].first.c_str(), s[i].second.c_str());
    fprintf(file, "@end table\n");
    fclose(file);
  }
  {
    FILE *file = Fopen("commandline.texi", "w");
    if(!file) {
      Msg::Error("Unable to open file 'commandline.texi'");
      return;
    }
    std::vector<std::pair<std::string, std::string> > s = GetUsage();
    fprintf(file, "%s@ftable @code\n", warn);
    for(std::size_t i = 0; i < s.size(); i++)
      if(s[i].first.size() && s[i].second.size())
        fprintf(file, "@item %s\n%s\n", s[i].first.c_str(),
                s[i].second.c_str());
      else if(s[i].first.size() && s[i].second.empty())
        fprintf(file, "@end ftable\n %s\n@ftable @code\n", s[i].first.c_str());
    fprintf(file, "@end ftable\n");
    fclose(file);
  }
}

#define GET_VIEW(error_val)                                                    \
  PView *view = 0;                                                             \
  PViewData *data = 0;                                                         \
  PViewOptions *opt;                                                           \
  if(PView::list.empty())                                                      \
    opt = PViewOptions::reference();                                           \
  else {                                                                       \
    if(num < 0 || num >= (int)PView::list.size()) {                            \
      Msg::Warning("View[%d] does not exist", num);                            \
      return (error_val);                                                      \
    }                                                                          \
    view = PView::list[num];                                                   \
    data = view->getData();                                                    \
    opt = view->getOptions();                                                  \
  }

#define GET_VIEWo(error_val)                                                   \
  PView *view = 0;                                                             \
  PViewOptions *opt;                                                           \
  if(PView::list.empty())                                                      \
    opt = PViewOptions::reference();                                           \
  else {                                                                       \
    if(num < 0 || num >= (int)PView::list.size()) {                            \
      Msg::Warning("View[%d] does not exist", num);                            \
      return (error_val);                                                      \
    }                                                                          \
    view = PView::list[num];                                                   \
    opt = view->getOptions();                                                  \
  }

#define GET_VIEWd(error_val)                                                   \
  PView *view = 0;                                                             \
  PViewData *data = 0;                                                         \
  if(!PView::list.empty()) {                                                   \
    if(num < 0 || num >= (int)PView::list.size()) {                            \
      Msg::Warning("View[%d] does not exist", num);                            \
      return (error_val);                                                      \
    }                                                                          \
    view = PView::list[num];                                                   \
    data = view->getData();                                                    \
  }

// String option routines

std::string opt_general_axes_label0(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->axesLabel[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[6]->value(
      CTX::instance()->axesLabel[0].c_str());
#endif
  return CTX::instance()->axesLabel[0];
}

std::string opt_general_axes_label1(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->axesLabel[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[7]->value(
      CTX::instance()->axesLabel[1].c_str());
#endif
  return CTX::instance()->axesLabel[1];
}

std::string opt_general_axes_label2(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->axesLabel[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[8]->value(
      CTX::instance()->axesLabel[2].c_str());
#endif
  return CTX::instance()->axesLabel[2];
}

std::string opt_general_axes_format0(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->axesFormat[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[3]->value(
      CTX::instance()->axesFormat[0].c_str());
#endif
  return CTX::instance()->axesFormat[0];
}

std::string opt_general_axes_format1(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->axesFormat[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[4]->value(
      CTX::instance()->axesFormat[1].c_str());
#endif
  return CTX::instance()->axesFormat[1];
}

std::string opt_general_axes_format2(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->axesFormat[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[5]->value(
      CTX::instance()->axesFormat[2].c_str());
#endif
  return CTX::instance()->axesFormat[2];
}

std::string opt_general_display(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->display = val;
  return CTX::instance()->display;
}

std::string opt_general_background_image_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) {
#if defined(HAVE_FLTK)
    if(CTX::instance()->bgImageFileName != val && FlGui::available()) {
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()
            ->graph[i]
            ->gl[j]
            ->getDrawContext()
            ->invalidateBgImageTexture();
    }
#endif
    CTX::instance()->bgImageFileName = val;
  }
  return CTX::instance()->bgImageFileName;
}

std::string opt_general_version(OPT_ARGS_STR) { return GMSH_VERSION; }

std::string opt_general_build_options(OPT_ARGS_STR)
{
  std::string s = GMSH_CONFIG_OPTIONS;
  s.erase(0, 1);
  return s;
}

std::string opt_general_build_info(OPT_ARGS_STR)
{
  std::vector<std::string> ss = GetBuildInfo();
  std::string s;
  for(std::size_t i = 0; i < ss.size(); i++) {
    s += ReplaceSubString(" :", ":", ss[i]);
    if(i != ss.size() - 1) s += "; ";
  }
  std::string::size_type pos;
  while((pos = s.find("  ")) != std::string::npos) {
    s.replace(pos, 2, " ");
  }
  return s;
}

std::string opt_general_filename(OPT_ARGS_STR)
{
  return GModel::current()->getFileName();
}

std::string opt_general_executable_filename(OPT_ARGS_STR)
{
  return CTX::instance()->exeFileName;
}

std::string opt_general_default_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->defaultFileName = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[0]->value(
      CTX::instance()->defaultFileName.c_str());
#endif
  return CTX::instance()->defaultFileName;
}

std::string opt_general_tmp_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->tmpFileName = val;
  return CTX::instance()->tmpFileName;
}

std::string opt_general_error_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->errorFileName = val;
  return CTX::instance()->errorFileName;
}

std::string opt_general_number_format(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->numberFormat = val;
  return CTX::instance()->numberFormat;
}

std::string opt_general_session_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->sessionFileName = val;
  return CTX::instance()->sessionFileName;
}

std::string opt_general_options_filename(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->optionsFileName = val;
  return CTX::instance()->optionsFileName;
}

std::string opt_general_recent_file0(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[0] = val;
  return CTX::instance()->recentFiles[0];
}

std::string opt_general_recent_file1(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[1] = val;
  return CTX::instance()->recentFiles[1];
}

std::string opt_general_recent_file2(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[2] = val;
  return CTX::instance()->recentFiles[2];
}

std::string opt_general_recent_file3(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[3] = val;
  return CTX::instance()->recentFiles[3];
}

std::string opt_general_recent_file4(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[4] = val;
  return CTX::instance()->recentFiles[4];
}

std::string opt_general_recent_file5(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[5] = val;
  return CTX::instance()->recentFiles[5];
}

std::string opt_general_recent_file6(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[6] = val;
  return CTX::instance()->recentFiles[6];
}

std::string opt_general_recent_file7(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[7] = val;
  return CTX::instance()->recentFiles[7];
}

std::string opt_general_recent_file8(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[8] = val;
  return CTX::instance()->recentFiles[8];
}

std::string opt_general_recent_file9(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->recentFiles[9] = val;
  return CTX::instance()->recentFiles[9];
}

std::string opt_general_scripting_languages(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->scriptLang = SplitString(val, ',', true);
  std::string out = "";
  for(std::size_t i = 0; i < CTX::instance()->scriptLang.size(); i++) {
    if(i) out += ", ";
    out += CTX::instance()->scriptLang[i];
  }
  return out;
}

std::string opt_general_editor(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->editor = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.input[1]->value(
      CTX::instance()->editor.c_str());
#endif
  return CTX::instance()->editor;
}

std::string opt_general_watch_file_pattern(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->watchFilePattern = val;
  return CTX::instance()->watchFilePattern;
}

std::string opt_general_gui_theme(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->guiTheme = val;
  return CTX::instance()->guiTheme;
}

std::string opt_general_graphics_font(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->glFont = val;
#if defined(HAVE_FLTK)
  drawContextFltk dc;
  int index = dc.getFontIndex(CTX::instance()->glFont.c_str());
  if(action & GMSH_SET) {
    CTX::instance()->glFont = dc.getFontName(index);
    CTX::instance()->glFontEnum = dc.getFontEnum(index);
  }
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.choice[1]->value(index);
  }
#endif
  return CTX::instance()->glFont;
}

std::string opt_general_graphics_font_title(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->glFontTitle = val;
#if defined(HAVE_FLTK)
  drawContextFltk dc;
  int index = dc.getFontIndex(CTX::instance()->glFontTitle.c_str());
  if(action & GMSH_SET) {
    CTX::instance()->glFontTitle = dc.getFontName(index);
    CTX::instance()->glFontEnumTitle = dc.getFontEnum(index);
  }
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.choice[6]->value(index);
  }
#endif
  return CTX::instance()->glFontTitle;
}

std::string opt_general_graphics_font_engine(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->glFontEngine = val;

#if defined(HAVE_FLTK)
  if(action & GMSH_SET) {
    drawContextGlobal *old = drawContext::global();
    if(!old || old->getName() != CTX::instance()->glFontEngine) {
#if defined(HAVE_CAIRO)
      if(CTX::instance()->glFontEngine == "Cairo")
        drawContext::setGlobal(new drawContextFltkCairo);
      else
#endif
        if(CTX::instance()->glFontEngine == "StringTexture")
        drawContext::setGlobal(new drawContextFltkStringTexture);
      else
        drawContext::setGlobal(new drawContextFltk);
      if(old) delete old;
    }
  }
  if(FlGui::available() && (action & GMSH_GUI)) {
    int index = 0;
#if defined(HAVE_CAIRO)
    if(CTX::instance()->glFontEngine == "Cairo") index = 1;
#endif
    if(CTX::instance()->glFontEngine == "StringTexture") index = 2;
    FlGui::instance()->options->general.choice[7]->value(index);
  }
#endif

  return CTX::instance()->glFontEngine;
}

std::string opt_geometry_double_clicked_point_command(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.doubleClickedPointCommand = val;
  return CTX::instance()->geom.doubleClickedPointCommand;
}

std::string opt_geometry_double_clicked_curve_command(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.doubleClickedCurveCommand = val;
  return CTX::instance()->geom.doubleClickedCurveCommand;
}

std::string opt_geometry_double_clicked_surface_command(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.doubleClickedSurfaceCommand = val;
  return CTX::instance()->geom.doubleClickedSurfaceCommand;
}

std::string opt_geometry_double_clicked_volume_command(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.doubleClickedVolumeCommand = val;
  return CTX::instance()->geom.doubleClickedVolumeCommand;
}

std::string opt_geometry_occ_target_unit(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occTargetUnit = val;
  return CTX::instance()->geom.occTargetUnit;
}

std::string opt_geometry_occ_step_description(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepDescription = val;
  return CTX::instance()->geom.occStepDescription;
}

std::string opt_geometry_occ_step_implementation_level(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepImplementationLevel = val;
  return CTX::instance()->geom.occStepImplementationLevel;
}

std::string opt_geometry_occ_step_model_name(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepModelName = val;
  return CTX::instance()->geom.occStepModelName;
}

std::string opt_geometry_occ_step_time_stamp(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepTimeStamp = val;
  return CTX::instance()->geom.occStepTimeStamp;
}

std::string opt_geometry_occ_step_author(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepAuthor = val;
  return CTX::instance()->geom.occStepAuthor;
}

std::string opt_geometry_occ_step_organization(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepOrganization = val;
  return CTX::instance()->geom.occStepOrganization;
}

std::string opt_geometry_occ_step_preprocessor_version(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepPreprocessorVersion = val;
  return CTX::instance()->geom.occStepPreprocessorVersion;
}

std::string opt_geometry_occ_step_originating_system(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepOriginatingSystem = val;
  return CTX::instance()->geom.occStepOriginatingSystem;
}

std::string opt_geometry_occ_step_authorization(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepAuthorization = val;
  return CTX::instance()->geom.occStepAuthorization;
}

std::string opt_geometry_occ_step_schema_identifier(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.occStepSchemaIdentifier = val;
  return CTX::instance()->geom.occStepSchemaIdentifier;
}

std::string opt_geometry_pipe_default_trihedron(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->geom.pipeDefaultTrihedron = val;
  return CTX::instance()->geom.pipeDefaultTrihedron;
}

std::string opt_solver_socket_name(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->solver.socketName = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.input[0]->value(
      CTX::instance()->solver.socketName.c_str());
#endif
  return CTX::instance()->solver.socketName;
}

std::string opt_solver_name(OPT_ARGS_STR)
{
  if(num < 0 || num > NUM_SOLVERS - 1) return "";
  if(action & GMSH_SET) CTX::instance()->solver.name[num] = val;
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

std::string opt_solver_name5(OPT_ARGS_STR)
{
  return opt_solver_name(5, action, val);
}

std::string opt_solver_name6(OPT_ARGS_STR)
{
  return opt_solver_name(6, action, val);
}

std::string opt_solver_name7(OPT_ARGS_STR)
{
  return opt_solver_name(7, action, val);
}

std::string opt_solver_name8(OPT_ARGS_STR)
{
  return opt_solver_name(8, action, val);
}

std::string opt_solver_name9(OPT_ARGS_STR)
{
  return opt_solver_name(9, action, val);
}

std::string opt_solver_extension(OPT_ARGS_STR)
{
  if(num < 0 || num > NUM_SOLVERS - 1) return "";
  if(action & GMSH_SET) CTX::instance()->solver.extension[num] = val;
  return CTX::instance()->solver.extension[num];
}

std::string opt_solver_extension0(OPT_ARGS_STR)
{
  return opt_solver_extension(0, action, val);
}

std::string opt_solver_extension1(OPT_ARGS_STR)
{
  return opt_solver_extension(1, action, val);
}

std::string opt_solver_extension2(OPT_ARGS_STR)
{
  return opt_solver_extension(2, action, val);
}

std::string opt_solver_extension3(OPT_ARGS_STR)
{
  return opt_solver_extension(3, action, val);
}

std::string opt_solver_extension4(OPT_ARGS_STR)
{
  return opt_solver_extension(4, action, val);
}

std::string opt_solver_extension5(OPT_ARGS_STR)
{
  return opt_solver_extension(5, action, val);
}

std::string opt_solver_extension6(OPT_ARGS_STR)
{
  return opt_solver_extension(6, action, val);
}

std::string opt_solver_extension7(OPT_ARGS_STR)
{
  return opt_solver_extension(7, action, val);
}

std::string opt_solver_extension8(OPT_ARGS_STR)
{
  return opt_solver_extension(8, action, val);
}

std::string opt_solver_extension9(OPT_ARGS_STR)
{
  return opt_solver_extension(9, action, val);
}

std::string opt_solver_executable(OPT_ARGS_STR)
{
  if(num < 0 || num > NUM_SOLVERS - 1) return "";
  if(action & GMSH_SET) CTX::instance()->solver.executable[num] = val;
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

std::string opt_solver_executable5(OPT_ARGS_STR)
{
  return opt_solver_executable(5, action, val);
}

std::string opt_solver_executable6(OPT_ARGS_STR)
{
  return opt_solver_executable(6, action, val);
}

std::string opt_solver_executable7(OPT_ARGS_STR)
{
  return opt_solver_executable(7, action, val);
}

std::string opt_solver_executable8(OPT_ARGS_STR)
{
  return opt_solver_executable(8, action, val);
}

std::string opt_solver_executable9(OPT_ARGS_STR)
{
  return opt_solver_executable(9, action, val);
}

std::string opt_solver_remote_login(OPT_ARGS_STR)
{
  if(num < 0 || num > NUM_SOLVERS - 1) return "";
  if(action & GMSH_SET) CTX::instance()->solver.remoteLogin[num] = val;
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

std::string opt_solver_remote_login5(OPT_ARGS_STR)
{
  return opt_solver_remote_login(5, action, val);
}

std::string opt_solver_remote_login6(OPT_ARGS_STR)
{
  return opt_solver_remote_login(6, action, val);
}

std::string opt_solver_remote_login7(OPT_ARGS_STR)
{
  return opt_solver_remote_login(7, action, val);
}

std::string opt_solver_remote_login8(OPT_ARGS_STR)
{
  return opt_solver_remote_login(8, action, val);
}

std::string opt_solver_remote_login9(OPT_ARGS_STR)
{
  return opt_solver_remote_login(9, action, val);
}

std::string opt_solver_python_interpreter(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->solver.pythonInterpreter = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.input[1]->value(
      CTX::instance()->solver.pythonInterpreter.c_str());
#endif
  return CTX::instance()->solver.pythonInterpreter;
}

std::string opt_solver_octave_interpreter(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->solver.octaveInterpreter = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.input[2]->value(
      CTX::instance()->solver.octaveInterpreter.c_str());
#endif
  return CTX::instance()->solver.octaveInterpreter;
}

std::string opt_post_double_clicked_graph_point_command(OPT_ARGS_STR)
{
  if(action & GMSH_SET)
    CTX::instance()->post.doubleClickedGraphPointCommand = val;
  return CTX::instance()->post.doubleClickedGraphPointCommand;
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
  GET_VIEWd("");
  if(!data) return "";
  if(action & GMSH_SET) {
    data->setName(val);
#if defined(HAVE_FLTK)
    // change name in GUI for the view and its aliases
    if(FlGui::available()) {
      for(int i = 0; i < (int)PView::list.size(); i++) {
        if((i == num || PView::list[i]->getAliasOf() == view->getTag() ||
            PView::list[i]->getTag() == view->getAliasOf()) &&
           FlGui::instance()->onelab->getViewButton(i)) {
          FlGui::instance()->onelab->getViewButton(i)->copy_label(
            data->getName());
          FlGui::instance()->onelab->getViewButton(i)->redraw();
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

std::string opt_view_number_format(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->format = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[1]->value(opt->format.c_str());
#endif
  return opt->format;
#else
  return "";
#endif
}

std::string opt_view_double_clicked_command(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->doubleClickedCommand = val; }
  return opt->doubleClickedCommand;
#else
  return "";
#endif
}

std::string opt_view_group(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->group = val; }
  return opt->group;
#else
  return "";
#endif
}

std::string opt_view_filename(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWd("");
  if(!data) return "";
  return data->getFileName();
#else
  return "";
#endif
}

std::string opt_view_axes_label0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->axesLabel[0] = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[10]->value(
      opt->axesLabel[0].c_str());
#endif
  return opt->axesLabel[0];
#else
  return "";
#endif
}

std::string opt_view_axes_label1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->axesLabel[1] = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[11]->value(
      opt->axesLabel[1].c_str());
#endif
  return opt->axesLabel[1];
#else
  return "";
#endif
}

std::string opt_view_axes_label2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->axesLabel[2] = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[12]->value(
      opt->axesLabel[2].c_str());
#endif
  return opt->axesLabel[2];
#else
  return "";
#endif
}

std::string opt_view_axes_format0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->axesFormat[0] = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[7]->value(
      opt->axesFormat[0].c_str());
#endif
  return opt->axesFormat[0];
#else
  return "";
#endif
}

std::string opt_view_axes_format1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->axesFormat[1] = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[8]->value(
      opt->axesFormat[1].c_str());
#endif
  return opt->axesFormat[1];
#else
  return "";
#endif
}

std::string opt_view_axes_format2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) { opt->axesFormat[2] = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.input[9]->value(
      opt->axesFormat[2].c_str());
#endif
  return opt->axesFormat[2];
#else
  return "";
#endif
}

std::string opt_view_gen_raise0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
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
  GET_VIEWo("");
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
  GET_VIEWo("");
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
  switch(c) {
  case 'a':
  case 'A': return 10;
  case 'b':
  case 'B': return 11;
  case 'c':
  case 'C': return 12;
  case 'd':
  case 'D': return 13;
  case 'e':
  case 'E': return 14;
  case 'f':
  case 'F': return 15;
  default:
    if(c >= '0' && c <= '9')
      return c - '0';
    else
      return 0;
  }
}

void _string2stipple(std::string str, int &repeat, int &pattern)
{
  // "n*0xabcd"
  if(str.size() < 8) {
    repeat = 1;
    pattern = 0xFFFF;
  }
  else if(str[1] != '*' || str[2] != '0' || str[3] != 'x') {
    // bad format
    repeat = 1;
    pattern = 0xFFFF;
  }
  else {
    repeat = (int)str[0] - '0';
    pattern = 16 * 16 * 16 * _h2d(str[4]) + 16 * 16 * _h2d(str[5]) +
              16 * _h2d(str[6]) + _h2d(str[7]);
  }
}

std::string opt_view_stipple0(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[0] = val;
    _string2stipple(opt->stippleString[0], opt->stipple[0][0],
                    opt->stipple[0][1]);
  }
  return opt->stippleString[0];
#else
  return "";
#endif
}

std::string opt_view_stipple1(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[1] = val;
    _string2stipple(opt->stippleString[1], opt->stipple[1][0],
                    opt->stipple[1][1]);
  }
  return opt->stippleString[1];
#else
  return "";
#endif
}

std::string opt_view_stipple2(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[2] = val;
    _string2stipple(opt->stippleString[2], opt->stipple[2][0],
                    opt->stipple[2][1]);
  }
  return opt->stippleString[2];
#else
  return "";
#endif
}

std::string opt_view_stipple3(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[3] = val;
    _string2stipple(opt->stippleString[3], opt->stipple[3][0],
                    opt->stipple[3][1]);
  }
  return opt->stippleString[3];
#else
  return "";
#endif
}

std::string opt_view_stipple4(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[4] = val;
    _string2stipple(opt->stippleString[4], opt->stipple[4][0],
                    opt->stipple[4][1]);
  }
  return opt->stippleString[4];
#else
  return "";
#endif
}

std::string opt_view_stipple5(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[5] = val;
    _string2stipple(opt->stippleString[5], opt->stipple[5][0],
                    opt->stipple[5][1]);
  }
  return opt->stippleString[5];
#else
  return "";
#endif
}

std::string opt_view_stipple6(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[6] = val;
    _string2stipple(opt->stippleString[6], opt->stipple[6][0],
                    opt->stipple[6][1]);
  }
  return opt->stippleString[6];
#else
  return "";
#endif
}

std::string opt_view_stipple7(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[7] = val;
    _string2stipple(opt->stippleString[7], opt->stipple[7][0],
                    opt->stipple[7][1]);
  }
  return opt->stippleString[7];
#else
  return "";
#endif
}

std::string opt_view_stipple8(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[8] = val;
    _string2stipple(opt->stippleString[8], opt->stipple[8][0],
                    opt->stipple[8][1]);
  }
  return opt->stippleString[8];
#else
  return "";
#endif
}

std::string opt_view_stipple9(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) {
    opt->stippleString[9] = val;
    _string2stipple(opt->stippleString[9], opt->stipple[9][0],
                    opt->stipple[9][1]);
  }
  return opt->stippleString[9];
#else
  return "";
#endif
}

std::string opt_view_attributes(OPT_ARGS_STR)
{
#if defined(HAVE_POST)
  GET_VIEWo("");
  if(action & GMSH_SET) opt->attributes = val;
  return opt->attributes;
#else
  return "";
#endif
}

std::string opt_print_parameter_command(OPT_ARGS_STR)
{
  if(action & GMSH_SET) CTX::instance()->print.parameterCommand = val;
  return CTX::instance()->print.parameterCommand;
}

// Numeric option routines

double opt_general_abort_on_error(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->abortOnError = (int)val;
  return CTX::instance()->abortOnError;
}

double opt_general_initial_context(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->initialContext = (int)val;
  return CTX::instance()->initialContext;
}

double opt_general_show_options_on_startup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->showOptionsOnStartup = (int)val;
  return CTX::instance()->showOptionsOnStartup;
}

double opt_general_show_messages_on_startup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->showMessagesOnStartup = (int)val;
  return CTX::instance()->showMessagesOnStartup;
}

double opt_general_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->fontSize = (int)val; }
  return CTX::instance()->fontSize;
}

double opt_general_gui_color_scheme(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->guiColorScheme = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.butt[21]->value(
      CTX::instance()->guiColorScheme);
  }
  if(action & GMSH_SET && FlGui::available()) {
    FlGui::instance()->applyColorScheme(true);
  }
#endif
  return CTX::instance()->guiColorScheme;
}

double opt_general_gui_refresh_rate(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->guiRefreshRate = val;
  return CTX::instance()->guiRefreshRate;
}

double opt_general_graphics_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->glFontSize = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[12]->value(
      CTX::instance()->glFontSize);
#endif
  return CTX::instance()->glFontSize;
}

double opt_general_graphics_fontsize_title(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->glFontSizeTitle = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[28]->value(
      CTX::instance()->glFontSizeTitle);
#endif
  return CTX::instance()->glFontSizeTitle;
}

double opt_general_polygon_offset_always(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->polygonOffsetAlways = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[4]->value(
      CTX::instance()->polygonOffsetAlways);
#endif
  return CTX::instance()->polygonOffsetAlways;
}

double opt_general_polygon_offset_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->polygonOffsetFactor = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[15]->value(
      CTX::instance()->polygonOffsetFactor);
#endif
  return CTX::instance()->polygonOffsetFactor;
}

double opt_general_polygon_offset_units(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->polygonOffsetUnits = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[16]->value(
      CTX::instance()->polygonOffsetUnits);
#endif
  return CTX::instance()->polygonOffsetUnits;
}

double opt_general_graphics_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->glPosition[0] = (int)val;
  return CTX::instance()->glPosition[0];
}

double opt_general_graphics_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->glPosition[1] = (int)val;
  return CTX::instance()->glPosition[1];
}

double opt_general_graphics_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->glSize[0] = (int)val;
    if(CTX::instance()->glSize[0] <= 0) CTX::instance()->glSize[0] = 600;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->graph[0]->setGlWidth(CTX::instance()->glSize[0]);
  }
#endif
  return CTX::instance()->glSize[0];
}

double opt_general_graphics_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->glSize[1] = (int)val;
    if(CTX::instance()->glSize[1] <= 0) CTX::instance()->glSize[1] = 600;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->graph[0]->setGlHeight(CTX::instance()->glSize[1]);
  }
#endif
  return CTX::instance()->glSize[1];
}

double opt_general_context_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->ctxPosition[0] = (int)val;
  return CTX::instance()->ctxPosition[0];
}

double opt_general_context_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->ctxPosition[1] = (int)val;
  return CTX::instance()->ctxPosition[1];
}

double opt_general_file_chooser_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fileChooserPosition[0] = (int)val;
  return CTX::instance()->fileChooserPosition[0];
}

double opt_general_file_chooser_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fileChooserPosition[1] = (int)val;
  return CTX::instance()->fileChooserPosition[1];
}

double opt_general_system_menu_bar(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->systemMenuBar = (int)val;
  return CTX::instance()->systemMenuBar;
}

double opt_general_native_file_chooser(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->nativeFileChooser = (int)val;
  return CTX::instance()->nativeFileChooser;
}

double opt_general_show_module_menu(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->showModuleMenu = (int)val;
  return CTX::instance()->showModuleMenu;
}

double opt_general_message_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->msgSize = (int)val;
    if(CTX::instance()->msgSize <= 0) CTX::instance()->msgSize = 100;
  }
  return CTX::instance()->msgSize;
}

double opt_general_message_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->msgFontSize = (int)val;
#if defined(HAVE_FLTK)
    if(FlGui::available() && (action & GMSH_GUI)) {
      FlGui::instance()->graph[0]->setMessageFontSize(
        CTX::instance()->msgFontSize);
    }
#endif
  }
  return CTX::instance()->msgFontSize;
}

double opt_general_detached_menu(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->detachedMenu = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->detachedMenu)
      FlGui::instance()->graph[0]->detachMenu();
    else
      FlGui::instance()->graph[0]->attachMenu();
  }
#endif
  return CTX::instance()->detachedMenu;
}

double opt_general_detached_process(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->detachedProcess = (int)val;
  return CTX::instance()->detachedProcess;
}

double opt_general_menu_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->menuSize[0] = (int)val;
    if(CTX::instance()->menuSize[0] < 0) CTX::instance()->menuSize[0] = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->graph[0]->setMenuWidth(CTX::instance()->menuSize[0]);
  }
#endif
  return CTX::instance()->menuSize[0];
}

double opt_general_menu_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->menuSize[1] = (int)val;
    if(CTX::instance()->menuSize[1] < 0) CTX::instance()->menuSize[1] = 300;
  }
  return CTX::instance()->menuSize[1];
}

double opt_general_menu_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->menuPosition[0] = (int)val;
    if(CTX::instance()->menuPosition[0] < 0)
      CTX::instance()->menuPosition[0] = 0;
  }
  return CTX::instance()->menuPosition[0];
}

double opt_general_menu_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->menuPosition[1] = (int)val;
    if(CTX::instance()->menuPosition[1] < 0)
      CTX::instance()->menuPosition[1] = 300;
  }
  return CTX::instance()->menuPosition[1];
}

double opt_general_option_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->optPosition[0] = (int)val;
  return CTX::instance()->optPosition[0];
}

double opt_general_option_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->optPosition[1] = (int)val;
  return CTX::instance()->optPosition[1];
}

double opt_general_plugin_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->pluginPosition[0] = (int)val;
  return CTX::instance()->pluginPosition[0];
}

double opt_general_plugin_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->pluginPosition[1] = (int)val;
  return CTX::instance()->pluginPosition[1];
}

double opt_general_plugin_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->pluginSize[0] = (int)val;
  return CTX::instance()->pluginSize[0];
}

double opt_general_plugin_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->pluginSize[1] = (int)val;
  return CTX::instance()->pluginSize[1];
}

double opt_general_field_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fieldPosition[0] = (int)val;
  return CTX::instance()->fieldPosition[0];
}

double opt_general_field_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fieldPosition[1] = (int)val;
  return CTX::instance()->fieldPosition[1];
}

double opt_general_field_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fieldSize[0] = (int)val;
  return CTX::instance()->fieldSize[0];
}

double opt_general_field_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fieldSize[1] = (int)val;
  return CTX::instance()->fieldSize[1];
}

double opt_general_extra_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->extraPosition[0] = (int)val;
  return CTX::instance()->extraPosition[0];
}

double opt_general_extra_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->extraPosition[1] = (int)val;
  return CTX::instance()->extraPosition[1];
}

double opt_general_extra_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->extraSize[0] = (int)val;
  return CTX::instance()->extraSize[0];
}

double opt_general_extra_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->extraSize[1] = (int)val;
  return CTX::instance()->extraSize[1];
}

double opt_general_statistics_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->statPosition[0] = (int)val;
  return CTX::instance()->statPosition[0];
}

double opt_general_statistics_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->statPosition[1] = (int)val;
  return CTX::instance()->statPosition[1];
}

double opt_general_visibility_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->visPosition[0] = (int)val;
  return CTX::instance()->visPosition[0];
}

double opt_general_visibility_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->visPosition[1] = (int)val;
  return CTX::instance()->visPosition[1];
}

double opt_general_clip_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPosition[0] = (int)val;
  return CTX::instance()->clipPosition[0];
}

double opt_general_clip_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPosition[1] = (int)val;
  return CTX::instance()->clipPosition[1];
}

double opt_general_manip_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->manipPosition[0] = (int)val;
  return CTX::instance()->manipPosition[0];
}

double opt_general_manip_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->manipPosition[1] = (int)val;
  return CTX::instance()->manipPosition[1];
}

double opt_general_hot_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->hotPosition[0] = (int)val;
  return CTX::instance()->hotPosition[0];
}

double opt_general_hot_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->hotPosition[1] = (int)val;
  return CTX::instance()->hotPosition[1];
}

double opt_general_high_resolution_graphics(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->highResolutionGraphics = (int)val;
  return CTX::instance()->highResolutionGraphics;
}

double opt_general_session_save(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->sessionSave = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[8]->value(
      CTX::instance()->sessionSave);
#endif
  return CTX::instance()->sessionSave;
}

double opt_general_options_save(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->optionsSave = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[9]->value(
      CTX::instance()->optionsSave ? 1 : 0);
#endif
  return CTX::instance()->optionsSave;
}

double opt_general_confirm_overwrite(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->confirmOverwrite = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[14]->value(
      CTX::instance()->confirmOverwrite);
#endif
  return CTX::instance()->confirmOverwrite;
}

double opt_general_rotation0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpRotation[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->r[0] = val;
    return gl->getDrawContext()->r[0];
  }
#endif
  return CTX::instance()->tmpRotation[0];
}

double opt_general_rotation1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpRotation[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->r[1] = val;
    return gl->getDrawContext()->r[1];
  }
#endif
  return CTX::instance()->tmpRotation[1];
}

double opt_general_rotation2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpRotation[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->r[2] = val;
    return gl->getDrawContext()->r[2];
  }
#endif
  return CTX::instance()->tmpRotation[2];
}

double opt_general_rotation_center0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->rotationCenter[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[8]->value(
      CTX::instance()->rotationCenter[0]);
#endif
  return CTX::instance()->rotationCenter[0];
}

double opt_general_rotation_center1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->rotationCenter[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[9]->value(
      CTX::instance()->rotationCenter[1]);
#endif
  return CTX::instance()->rotationCenter[1];
}

double opt_general_rotation_center2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->rotationCenter[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[10]->value(
      CTX::instance()->rotationCenter[2]);
#endif
  return CTX::instance()->rotationCenter[2];
}

double opt_general_quaternion0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpQuaternion[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->quaternion[0] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->quaternion[0];
  }
#endif
  return CTX::instance()->tmpQuaternion[0];
}

double opt_general_quaternion1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpQuaternion[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->quaternion[1] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->quaternion[1];
  }
#endif
  return CTX::instance()->tmpQuaternion[1];
}

double opt_general_quaternion2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpQuaternion[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->quaternion[2] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->quaternion[2];
  }
#endif
  return CTX::instance()->tmpQuaternion[2];
}

double opt_general_quaternion3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpQuaternion[3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->quaternion[3] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->quaternion[3];
  }
#endif
  return CTX::instance()->tmpQuaternion[3];
}

double opt_general_translation0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpTranslation[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->t[0] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->t[0];
  }
#endif
  return CTX::instance()->tmpTranslation[0];
}

double opt_general_translation1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpTranslation[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->t[1] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->t[1];
  }
#endif
  return CTX::instance()->tmpTranslation[1];
}

double opt_general_translation2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpTranslation[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->t[2] = val;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->t[2];
  }
#endif
  return CTX::instance()->tmpTranslation[2];
}

double opt_general_scale0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpScale[0] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->s[0] = val ? val : 1.0;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->s[0];
  }
#endif
  return CTX::instance()->tmpScale[0];
}

double opt_general_scale1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpScale[1] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->s[1] = val ? val : 1.0;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->s[1];
  }
#endif
  return CTX::instance()->tmpScale[1];
}

double opt_general_scale2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->tmpScale[2] = val ? val : 1.0;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
    if(action & GMSH_SET) gl->getDrawContext()->s[2] = val ? val : 1.0;
    if(action & GMSH_GUI) FlGui::instance()->manip->update();
    return gl->getDrawContext()->s[2];
  }
#endif
  return CTX::instance()->tmpScale[2];
}

double opt_general_clip_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    // should never be zero (or negative)
    if(val < 0.01)
      CTX::instance()->clipFactor = 0.01;
    else
      CTX::instance()->clipFactor = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[14]->value(
      CTX::instance()->clipFactor);
#endif
  return CTX::instance()->clipFactor;
}

double opt_general_display_border_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->displayBorderFactor = val;
  return CTX::instance()->displayBorderFactor;
}

double opt_geometry_reparam_on_face_robust(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.reparamOnFaceRobust = val;
  return CTX::instance()->geom.reparamOnFaceRobust;
}

double opt_general_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->pointSize = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[6]->value(
      CTX::instance()->pointSize);
#endif
  return CTX::instance()->pointSize;
}

double opt_general_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lineWidth = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[7]->value(
      CTX::instance()->lineWidth);
#endif
  return CTX::instance()->lineWidth;
}

double opt_general_shine(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->shine = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[1]->value(CTX::instance()->shine);
#endif
  return CTX::instance()->shine;
}

double opt_general_shine_exponent(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->shineExponent = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[0]->value(
      CTX::instance()->shineExponent);
#endif
  return CTX::instance()->shineExponent;
}

double opt_general_verbosity(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { Msg::SetVerbosity((int)val); }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[5]->value(Msg::GetVerbosity());
#endif
  return Msg::GetVerbosity();
}

double opt_general_progress_meter_step(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { Msg::SetProgressMeterStep((int)val); }
  return Msg::GetProgressMeterStep();
}

double opt_general_nopopup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->noPopup = (int)val;
  return CTX::instance()->noPopup;
}

double opt_general_non_modal_windows(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->nonModalWindows = (int)val;
  return CTX::instance()->nonModalWindows;
}

double opt_general_terminal(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->terminal = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[7]->value(
      CTX::instance()->terminal);
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
    FlGui::instance()->options->general.butt[13]->value(
      CTX::instance()->tooltips);
#endif
  return CTX::instance()->tooltips;
}

double opt_general_input_scrolling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->inputScrolling = (int)val; }
  return CTX::instance()->inputScrolling;
}

double opt_general_orthographic(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->ortho = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->ortho) {
      FlGui::instance()->options->general.choice[2]->value(0);
      if(FlGui::available()) Msg::StatusBar(false, "Orthographic projection");
    }
    else {
      FlGui::instance()->options->general.choice[2]->value(1);
      if(FlGui::available()) Msg::StatusBar(false, "Perspective projection");
    }
  }
#endif
  return CTX::instance()->ortho;
}

double opt_general_mouse_selection(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mouseSelection = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mouseSelection) {
      if(FlGui::available()) Msg::StatusBar(false, "Mouse selection ON");
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getSelectionButton()->color(
          FL_BACKGROUND_COLOR);
    }
    else {
      if(FlGui::available()) Msg::StatusBar(false, "Mouse selection OFF");
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        FlGui::instance()->graph[i]->getSelectionButton()->color(FL_RED);
    }
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->getSelectionButton()->redraw();
  }
#endif
  return CTX::instance()->mouseSelection;
}

double opt_general_mouse_hover_meshes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mouseHoverMeshes = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[11]->value(
      CTX::instance()->mouseHoverMeshes);
#endif
  return CTX::instance()->mouseHoverMeshes;
}

double opt_general_mouse_invert_zoom(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mouseInvertZoom = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[22]->value(
      CTX::instance()->mouseInvertZoom);
#endif
  return CTX::instance()->mouseInvertZoom;
}

double opt_general_fast_redraw(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->fastRedraw = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.butt[2]->value(
      CTX::instance()->fastRedraw);
    FlGui::instance()->options->activate("fast_redraw");
  }
#endif
  return CTX::instance()->fastRedraw;
}

double opt_general_draw_bounding_box(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->drawBBox = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[6]->value(
      CTX::instance()->drawBBox);
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

double opt_general_lc(OPT_ARGS_NUM) { return CTX::instance()->lc; }

double opt_general_axes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->axes = (int)val;
    if(CTX::instance()->axes < 0 || CTX::instance()->axes > 5)
      CTX::instance()->axes = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.choice[4]->value(CTX::instance()->axes);
    FlGui::instance()->options->activate("general_axes");
  }
#endif
  return CTX::instance()->axes;
}

double opt_general_axes_mikado(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->axesMikado = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[16]->value(
      CTX::instance()->axesMikado);
#endif
  return CTX::instance()->axesMikado;
}

double opt_general_axes_auto_position(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesAutoPosition = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.butt[0]->value(
      CTX::instance()->axesAutoPosition);
    FlGui::instance()->options->activate("general_axes_auto");
  }
#endif
  return CTX::instance()->axesAutoPosition;
}

double opt_general_axes_tics0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesTics[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[17]->value(
      CTX::instance()->axesTics[0]);
#endif
  return CTX::instance()->axesTics[0];
}

double opt_general_axes_tics1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesTics[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[18]->value(
      CTX::instance()->axesTics[1]);
#endif
  return CTX::instance()->axesTics[1];
}

double opt_general_axes_tics2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesTics[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[19]->value(
      CTX::instance()->axesTics[2]);
#endif
  return CTX::instance()->axesTics[2];
}

double opt_general_axes_xmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesPosition[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[20]->value(
      CTX::instance()->axesPosition[0]);
#endif
  return CTX::instance()->axesPosition[0];
}

double opt_general_axes_xmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesPosition[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[23]->value(
      CTX::instance()->axesPosition[1]);
#endif
  return CTX::instance()->axesPosition[1];
}

double opt_general_axes_ymin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesPosition[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[21]->value(
      CTX::instance()->axesPosition[2]);
#endif
  return CTX::instance()->axesPosition[2];
}

double opt_general_axes_ymax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesPosition[3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[24]->value(
      CTX::instance()->axesPosition[3]);
#endif
  return CTX::instance()->axesPosition[3];
}

double opt_general_axes_zmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesPosition[4] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[22]->value(
      CTX::instance()->axesPosition[4]);
#endif
  return CTX::instance()->axesPosition[4];
}

double opt_general_axes_zmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesPosition[5] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[25]->value(
      CTX::instance()->axesPosition[5]);
#endif
  return CTX::instance()->axesPosition[5];
}

double opt_general_axes_force_value(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesForceValue = (int)val;
  return CTX::instance()->axesForceValue;
}

double opt_general_axes_value_xmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesValue[0] = val;
  return CTX::instance()->axesValue[0];
}

double opt_general_axes_value_xmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesValue[1] = val;
  return CTX::instance()->axesValue[1];
}

double opt_general_axes_value_ymin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesValue[2] = val;
  return CTX::instance()->axesValue[2];
}

double opt_general_axes_value_ymax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesValue[3] = val;
  return CTX::instance()->axesValue[3];
}

double opt_general_axes_value_zmin(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesValue[4] = val;
  return CTX::instance()->axesValue[4];
}

double opt_general_axes_value_zmax(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->axesValue[5] = val;
  return CTX::instance()->axesValue[5];
}

double opt_general_small_axes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->smallAxes = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.butt[1]->value(
      CTX::instance()->smallAxes);
    FlGui::instance()->options->activate("general_small_axes");
  }
#endif
  return CTX::instance()->smallAxes;
}

double opt_general_small_axes_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->smallAxesPos[0] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[26]->value(
      CTX::instance()->smallAxesPos[0]);
#endif
  return CTX::instance()->smallAxesPos[0];
}

double opt_general_small_axes_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->smallAxesPos[1] = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[27]->value(
      CTX::instance()->smallAxesPos[1]);
#endif
  return CTX::instance()->smallAxesPos[1];
}

double opt_general_small_axes_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->smallAxesSize = (int)val;
  return CTX::instance()->smallAxesSize;
}

double opt_general_quadric_subdivisions(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->quadricSubdivisions = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    if(action & GMSH_GUI)
      FlGui::instance()->options->general.value[11]->value(
        CTX::instance()->quadricSubdivisions);
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
      int mode =
        FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
      if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->mode(mode);
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[3]->value(CTX::instance()->db);
#endif
  return CTX::instance()->db;
}

double opt_general_antialiasing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->antialiasing = (int)val;
#if defined(HAVE_FLTK)
    if(FlGui::available()) {
      int mode =
        FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
      if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
      for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
        for(std::size_t j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->mode(mode);
    }
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[12]->value(
      CTX::instance()->antialiasing);
#endif
  return CTX::instance()->antialiasing;
}

double opt_general_alpha_blending(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->alpha = (int)val;
  return CTX::instance()->alpha;
}

double opt_general_vector_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->vectorType = (int)val;
    if(CTX::instance()->vectorType < 1 || CTX::instance()->vectorType > 4)
      CTX::instance()->vectorType = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.choice[0]->value(
      CTX::instance()->vectorType - 1);
  }
#endif
  return CTX::instance()->vectorType;
}

double opt_general_arrow_head_radius(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX::instance()->arrowRelHeadRadius = val;
  }
  return CTX::instance()->arrowRelHeadRadius;
}

double opt_general_arrow_stem_length(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(val < 0.) val = 0.;
    if(val > 1.) val = 1.;
    CTX::instance()->arrowRelStemLength = val;
  }
  return CTX::instance()->arrowRelStemLength;
}

double opt_general_arrow_stem_radius(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
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
    if(CTX::instance()->colorScheme > 3) CTX::instance()->colorScheme = 0;
    SetDefaultColorOptions(0, GeneralOptions_Color);
    SetDefaultColorOptions(0, GeometryOptions_Color);
    SetDefaultColorOptions(0, MeshOptions_Color);
    SetDefaultColorOptions(0, SolverOptions_Color);
    SetDefaultColorOptions(0, PostProcessingOptions_Color);
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++)
      SetDefaultColorOptions(i, ViewOptions_Color);
#endif
    SetDefaultColorOptions(0, PrintOptions_Color);

    SetColorOptionsGUI(0, GeneralOptions_Color);
    SetColorOptionsGUI(0, GeometryOptions_Color);
    SetColorOptionsGUI(0, MeshOptions_Color);
    SetColorOptionsGUI(0, SolverOptions_Color);
    SetColorOptionsGUI(0, PostProcessingOptions_Color);
#if defined(HAVE_POST)
    for(std::size_t i = 0; i < PView::list.size(); i++)
      SetColorOptionsGUI(i, ViewOptions_Color);
#endif
    SetColorOptionsGUI(0, PrintOptions_Color);

#if defined(HAVE_POST)
    // horrible trick so that opt_view_XXX will act on the reference view
    std::vector<PView *> tmp = PView::list;
    PView::list.clear();
    SetDefaultColorOptions(0, ViewOptions_Color);
    PView::list = tmp;
#endif
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.choice[3]->value(
      CTX::instance()->colorScheme);
#endif
  return CTX::instance()->colorScheme;
}

double opt_general_background_gradient(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->bgGradient = (int)val;
    if(CTX::instance()->bgGradient < 0 || CTX::instance()->bgGradient > 3)
      CTX::instance()->bgGradient = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.choice[5]->value(
      CTX::instance()->bgGradient);
#endif
  return CTX::instance()->bgGradient;
}

double opt_general_background_image_position0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->bgImagePosition[0] = val;
  return CTX::instance()->bgImagePosition[0];
}

double opt_general_background_image_position1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->bgImagePosition[1] = val;
  return CTX::instance()->bgImagePosition[1];
}

double opt_general_background_image_size0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->bgImageSize[0] = val;
  return CTX::instance()->bgImageSize[0];
}

double opt_general_background_image_size1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->bgImageSize[1] = val;
  return CTX::instance()->bgImageSize[1];
}

double opt_general_background_image_3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->bgImage3d = (int)val;
  return CTX::instance()->bgImage3d;
}

double opt_general_background_image_page(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->bgImagePage = (int)val;
  return CTX::instance()->bgImagePage;
}

double opt_general_trackball(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->useTrackball = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[5]->value(
      CTX::instance()->useTrackball);
#endif
  return CTX::instance()->useTrackball;
}

double opt_general_trackball_hyperbolic_sheet(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->trackballHyperbolicSheet = (int)val;
  return CTX::instance()->trackballHyperbolicSheet;
}

double opt_general_gamepad(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(val) {
      if(!CTX::instance()->gamepad) {
        CTX::instance()->gamepad = new GamePad();
        if(CTX::instance()->gamepad->active)
          opt_general_camera_mode(0, GMSH_SET, 1);
      }
    }
    else {
      if(CTX::instance()->gamepad) {
        delete CTX::instance()->gamepad;
        CTX::instance()->gamepad = nullptr;
      }
    }
  }
  return CTX::instance()->gamepad ? 1 : 0;
}

double opt_general_rotation_center_cg(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->rotationCenterCg = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.butt[15]->value(
      CTX::instance()->rotationCenterCg);
    FlGui::instance()->options->activate("rotation_center");
  }
#endif
  return CTX::instance()->rotationCenterCg;
}

double opt_general_zoom_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->zoomFactor = val;
  return CTX::instance()->zoomFactor;
}

double opt_general_expert_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->expertMode = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[10]->value(
      CTX::instance()->expertMode);
#endif
  return CTX::instance()->expertMode;
}

#if defined(HAVE_VISUDEV)
double opt_general_heavy_visualization(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->heavyVisu != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->heavyVisu = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[20]->value(
      CTX::instance()->heavyVisu);
#endif
  return CTX::instance()->heavyVisu;
}
#endif

double opt_general_stereo_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->stereo = (int)val;
  if(CTX::instance()->stereo) opt_general_camera_mode(num, action, 1.);
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.butt[17]->value(CTX::instance()->stereo);
#endif
  return CTX::instance()->stereo;
}

double opt_general_eye_sep_ratio(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->eye_sep_ratio = (double)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[29]->value
      (CTX::instance()->eye_sep_ratio) ;
#endif
  return CTX::instance()->eye_sep_ratio;
}

double opt_general_focallength_ratio(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->focallength_ratio = (double)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[30]->value
      (CTX::instance()->focallength_ratio);
#endif
  return CTX::instance()->focallength_ratio;
}

double opt_general_camera_aperture(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->camera_aperture = (double)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[31]->value
      (CTX::instance()->camera_aperture);
#endif
  return CTX::instance()->camera_aperture;
}

double opt_general_camera_mode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->camera = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)){
    FlGui::instance()->options->general.butt[18]->value
      (CTX::instance()->camera);
    FlGui::instance()->options->activate("general_camera");
  }
#endif
  return CTX::instance()->camera;
}

double opt_general_clip0a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[0][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][0];
}

double opt_general_clip0b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[0][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][1];
}

double opt_general_clip0c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[0][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][2];
}

double opt_general_clip0d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[0][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[0][3];
}

double opt_general_clip1a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[1][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][0];
}

double opt_general_clip1b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[1][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][1];
}

double opt_general_clip1c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[1][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][2];
}

double opt_general_clip1d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[1][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[1][3];
}

double opt_general_clip2a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[2][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][0];
}

double opt_general_clip2b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[2][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][1];
}

double opt_general_clip2c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[2][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][2];
}

double opt_general_clip2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[2][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[2][3];
}

double opt_general_clip3a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[3][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][0];
}

double opt_general_clip3b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[3][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][1];
}

double opt_general_clip3c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[3][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][2];
}

double opt_general_clip3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[3][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[3][3];
}

double opt_general_clip4a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[4][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][0];
}

double opt_general_clip4b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[4][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][1];
}

double opt_general_clip4c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[4][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][2];
}

double opt_general_clip4d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[4][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[4][3];
}

double opt_general_clip5a(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[5][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][0];
}

double opt_general_clip5b(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[5][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][1];
}

double opt_general_clip5c(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[5][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][2];
}

double opt_general_clip5d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipPlane[5][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->clipPlane[5][3];
}

double opt_general_clip_whole_elements(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipWholeElements = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->clipping->butt[0]->value(
      CTX::instance()->clipWholeElements);
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
    FlGui::instance()->clipping->butt[1]->value(
      CTX::instance()->clipOnlyDrawIntersectingVolume);
#endif
  return CTX::instance()->clipOnlyDrawIntersectingVolume;
}

double opt_general_clip_only_volume(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->clipOnlyVolume = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->butt[2]->value(
      CTX::instance()->clipOnlyVolume);
#endif
  return CTX::instance()->clipOnlyVolume;
}

double opt_general_light0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->light[0] = (int)val;
  return CTX::instance()->light[0];
}

double opt_general_light00(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[0][0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.value[2]->value(
      CTX::instance()->lightPosition[0][0]);
    FlGui::instance()->options->general.sphere->setValue(
      CTX::instance()->lightPosition[0][0],
      CTX::instance()->lightPosition[0][1],
      CTX::instance()->lightPosition[0][2]);
  }
#endif
  return CTX::instance()->lightPosition[0][0];
}

double opt_general_light01(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[0][1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.value[3]->value(
      CTX::instance()->lightPosition[0][1]);
    FlGui::instance()->options->general.sphere->setValue(
      CTX::instance()->lightPosition[0][0],
      CTX::instance()->lightPosition[0][1],
      CTX::instance()->lightPosition[0][2]);
  }
#endif
  return CTX::instance()->lightPosition[0][1];
}

double opt_general_light02(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[0][2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->general.value[4]->value(
      CTX::instance()->lightPosition[0][2]);
    FlGui::instance()->options->general.sphere->setValue(
      CTX::instance()->lightPosition[0][0],
      CTX::instance()->lightPosition[0][1],
      CTX::instance()->lightPosition[0][2]);
  }
#endif
  return CTX::instance()->lightPosition[0][2];
}

double opt_general_light03(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[0][3] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[13]->value(
      CTX::instance()->lightPosition[0][3]);
#endif
  return CTX::instance()->lightPosition[0][3];
}

double opt_general_light1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->light[1] = (int)val;
  return CTX::instance()->light[1];
}

double opt_general_light10(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[1][0] = val;
  return CTX::instance()->lightPosition[1][0];
}

double opt_general_light11(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[1][1] = val;
  return CTX::instance()->lightPosition[1][1];
}

double opt_general_light12(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[1][2] = val;
  return CTX::instance()->lightPosition[1][2];
}

double opt_general_light13(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[1][3] = val;
  return CTX::instance()->lightPosition[1][3];
}

double opt_general_light2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->light[2] = (int)val;
  return CTX::instance()->light[2];
}

double opt_general_light20(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[2][0] = val;
  return CTX::instance()->lightPosition[2][0];
}

double opt_general_light21(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[2][1] = val;
  return CTX::instance()->lightPosition[2][1];
}

double opt_general_light22(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[2][2] = val;
  return CTX::instance()->lightPosition[2][2];
}

double opt_general_light23(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[2][3] = val;
  return CTX::instance()->lightPosition[2][3];
}

double opt_general_light3(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->light[3] = (int)val;
  return CTX::instance()->light[3];
}

double opt_general_light30(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[3][0] = val;
  return CTX::instance()->lightPosition[3][0];
}

double opt_general_light31(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[3][1] = val;
  return CTX::instance()->lightPosition[3][1];
}

double opt_general_light32(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[3][2] = val;
  return CTX::instance()->lightPosition[3][2];
}

double opt_general_light33(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[3][3] = val;
  return CTX::instance()->lightPosition[3][3];
}

double opt_general_light4(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->light[4] = (int)val;
  return CTX::instance()->light[4];
}

double opt_general_light40(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[4][0] = val;
  return CTX::instance()->lightPosition[4][0];
}

double opt_general_light41(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[4][1] = val;
  return CTX::instance()->lightPosition[4][1];
}

double opt_general_light42(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[4][2] = val;
  return CTX::instance()->lightPosition[4][2];
}

double opt_general_light43(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[4][3] = val;
  return CTX::instance()->lightPosition[4][3];
}

double opt_general_light5(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->light[5] = (int)val;
  return CTX::instance()->light[5];
}

double opt_general_light50(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[5][0] = val;
  return CTX::instance()->lightPosition[5][0];
}

double opt_general_light51(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[5][1] = val;
  return CTX::instance()->lightPosition[5][1];
}

double opt_general_light52(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[5][2] = val;
  return CTX::instance()->lightPosition[5][2];
}

double opt_general_light53(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->lightPosition[5][3] = val;
  return CTX::instance()->lightPosition[5][3];
}

double opt_general_num_threads(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->numThreads = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->general.value[32]->value(CTX::instance()->numThreads);
#endif
  return CTX::instance()->numThreads;
}

double opt_geometry_transform(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.useTransform = (int)val;
    if(CTX::instance()->geom.useTransform < 0 ||
       CTX::instance()->geom.useTransform > 1)
      CTX::instance()->geom.useTransform = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    if(action & GMSH_GUI)
      FlGui::instance()->options->geo.choice[3]->value(
        CTX::instance()->geom.useTransform);
    if(action & GMSH_SET) {
      openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
      if(CTX::instance()->geom.useTransform == 1) {
        drawTransform *tr = new drawTransformScaled(
          CTX::instance()->geom.transform, CTX::instance()->geom.offset);
        gl->getDrawContext()->setTransform(tr);
      }
      else {
        drawTransform *tr = gl->getDrawContext()->getTransform();
        gl->getDrawContext()->setTransform(nullptr);
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
  if(action & GMSH_SET) CTX::instance()->geom.transform[ii][jj] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    if(action & GMSH_GUI)
      FlGui::instance()->options->geo.value[nn]->value(
        CTX::instance()->geom.transform[ii][jj]);
    if(action & GMSH_SET) {
      openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
      drawTransform *tr = gl->getDrawContext()->getTransform();
      if(tr)
        tr->setMatrix(CTX::instance()->geom.transform,
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
  if(action & GMSH_SET) CTX::instance()->geom.offset[ii] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available()) {
    if(action & GMSH_GUI)
      FlGui::instance()->options->geo.value[nn]->value(
        CTX::instance()->geom.offset[ii]);
    if(action & GMSH_SET) {
      openglWindow *gl = FlGui::instance()->getCurrentOpenglWindow();
      drawTransform *tr = gl->getDrawContext()->getTransform();
      if(tr)
        tr->setMatrix(CTX::instance()->geom.transform,
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
  if(action & GMSH_SET) CTX::instance()->geom.autoCoherence = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[8]->value(
      CTX::instance()->geom.autoCoherence);
#endif
  return CTX::instance()->geom.autoCoherence;
}

double opt_geometry_oriented_physicals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.orientedPhysicals = (int)val;
  return CTX::instance()->geom.orientedPhysicals;
}

double opt_geometry_first_entity_tag(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.firstEntityTag = (val > 1) ? (int)val : 1;
  }
  return CTX::instance()->geom.firstEntityTag;
}

double opt_geometry_first_physical_tag(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.firstPhysicalTag = (val > 1) ? (int)val : 1;
  }
  return CTX::instance()->geom.firstPhysicalTag;
}

double opt_geometry_highlight_orphans(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.highlightOrphans = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[10]->value(
      CTX::instance()->geom.highlightOrphans);
#endif
  return CTX::instance()->geom.highlightOrphans;
}

double opt_geometry_tolerance(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.tolerance = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[2]->value(
      CTX::instance()->geom.tolerance);
#endif
  return CTX::instance()->geom.tolerance;
}

double opt_geometry_tolerance_boolean(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.toleranceBoolean = val;
  return CTX::instance()->geom.toleranceBoolean;
}

double opt_geometry_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.normals = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[0]->value(
      CTX::instance()->geom.normals);
#endif
  return CTX::instance()->geom.normals;
}

double opt_geometry_tangents(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.tangents = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[1]->value(
      CTX::instance()->geom.tangents);
#endif
  return CTX::instance()->geom.tangents;
}

double opt_geometry_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.points = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[0]->value(
      CTX::instance()->geom.points);
#endif
  return CTX::instance()->geom.points;
}

double opt_geometry_curves(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.curves = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[1]->value(
      CTX::instance()->geom.curves);
#endif
  return CTX::instance()->geom.curves;
}

double opt_geometry_surfaces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.surfaces = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[2]->value(
      CTX::instance()->geom.surfaces);
#endif
  return CTX::instance()->geom.surfaces;
}

double opt_geometry_volumes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.volumes = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[3]->value(
      CTX::instance()->geom.volumes);
#endif
  return CTX::instance()->geom.volumes;
}

double opt_geometry_point_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.pointLabels = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[4]->value(
      CTX::instance()->geom.pointLabels);
#endif
  return CTX::instance()->geom.pointLabels;
}

double opt_geometry_curve_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.curveLabels = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[5]->value(
      CTX::instance()->geom.curveLabels);
#endif
  return CTX::instance()->geom.curveLabels;
}

double opt_geometry_surface_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.surfaceLabels = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[6]->value(
      CTX::instance()->geom.surfaceLabels);
#endif
  return CTX::instance()->geom.surfaceLabels;
}

double opt_geometry_volume_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.volumeLabels = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[7]->value(
      CTX::instance()->geom.volumeLabels);
#endif
  return CTX::instance()->geom.volumeLabels;
}

double opt_geometry_label_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.labelType = (int)val;
    if(CTX::instance()->geom.labelType < 0 ||
       CTX::instance()->geom.labelType > 4)
      CTX::instance()->geom.labelType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[4]->value(
      CTX::instance()->geom.labelType);
  }
#endif
  return CTX::instance()->geom.labelType;
}

double opt_geometry_point_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.pointSize = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[3]->value(
      CTX::instance()->geom.pointSize);
#endif
  return CTX::instance()->geom.pointSize;
}

double opt_geometry_point_sel_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.selectedPointSize = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[5]->value(
      CTX::instance()->geom.selectedPointSize);
#endif
  return CTX::instance()->geom.selectedPointSize;
}

double opt_geometry_point_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->geom.pointType = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[0]->value(
      CTX::instance()->geom.pointType);
  }
#endif
  return CTX::instance()->geom.pointType;
}

double opt_geometry_curve_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.curveWidth = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[4]->value(
      CTX::instance()->geom.curveWidth);
#endif
  return CTX::instance()->geom.curveWidth;
}

double opt_geometry_curve_sel_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.selectedCurveWidth = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.value[6]->value(
      CTX::instance()->geom.selectedCurveWidth);
#endif
  return CTX::instance()->geom.selectedCurveWidth;
}

double opt_geometry_curve_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->geom.curveType = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[1]->value(
      CTX::instance()->geom.curveType);
  }
#endif
  return CTX::instance()->geom.curveType;
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
    FlGui::instance()->options->geo.choice[2]->value(
      CTX::instance()->geom.surfaceType);
  }
#endif
  return CTX::instance()->geom.surfaceType;
}

double opt_geometry_volume_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.volumeType = (int)val;
    if(CTX::instance()->geom.volumeType < 0 ||
       CTX::instance()->geom.volumeType > 1)
      CTX::instance()->geom.volumeType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.choice[5]->value(
      CTX::instance()->geom.volumeType);
  }
#endif
  return CTX::instance()->geom.volumeType;
}

double opt_geometry_light(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.light = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[9]->value(CTX::instance()->geom.light);
  }
#endif
  return CTX::instance()->geom.light;
}

double opt_geometry_light_two_side(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.lightTwoSide = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->geo.butt[15]->value(
      CTX::instance()->geom.lightTwoSide);
#endif
  return CTX::instance()->geom.lightTwoSide;
}

double opt_geometry_occ_auto_embed(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occAutoEmbed = val ? 1 : 0;
  return CTX::instance()->geom.occAutoEmbed;
}

double opt_geometry_occ_fast_unbind(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occFastUnbind = (int)val;
  return CTX::instance()->geom.occFastUnbind;
}

double opt_geometry_occ_auto_fix(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occAutoFix = val ? 1 : 0;
  return CTX::instance()->geom.occAutoFix;
}

double opt_geometry_occ_bounds_use_stl(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occBoundsUseSTL = val ? 1 : 0;
  return CTX::instance()->geom.occBoundsUseSTL;
}

double opt_geometry_occ_brep_format_version(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occBrepFormatVersion = (int)val;
  return CTX::instance()->geom.occBrepFormatVersion;
}

double opt_geometry_occ_disable_stl(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occDisableSTL = val ? 1 : 0;
  return CTX::instance()->geom.occDisableSTL;
}

double opt_geometry_occ_fix_degenerated(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occFixDegenerated = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[16]->value(
      CTX::instance()->geom.occFixDegenerated);
  }
#endif
  return CTX::instance()->geom.occFixDegenerated;
}

double opt_geometry_occ_fix_small_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occFixSmallEdges = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[11]->value(
      CTX::instance()->geom.occFixSmallEdges);
  }
#endif
  return CTX::instance()->geom.occFixSmallEdges;
}

double opt_geometry_occ_fix_small_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occFixSmallFaces = val ? 1 : 0;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[12]->value(
      CTX::instance()->geom.occFixSmallFaces);
  }
#endif
  return CTX::instance()->geom.occFixSmallFaces;
}

double opt_geometry_occ_sew_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->geom.occSewFaces = val ? 1 : 0; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[13]->value(
      CTX::instance()->geom.occSewFaces);
  }
#endif
  return CTX::instance()->geom.occSewFaces;
}

double opt_geometry_occ_make_solids(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->geom.occMakeSolids = val ? 1 : 0; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.butt[14]->value(
      CTX::instance()->geom.occMakeSolids);
  }
#endif
  return CTX::instance()->geom.occMakeSolids;
}

double opt_geometry_occ_thrusections_degree(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occThruSectionsDegree = (int)val;
  return CTX::instance()->geom.occThruSectionsDegree;
}

double opt_geometry_occ_parallel(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occParallel = (int)val;
  return CTX::instance()->geom.occParallel;
}

double opt_geometry_occ_boolean_check_inverted(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occBooleanCheckInverted = (int)val;
  return CTX::instance()->geom.occBooleanCheckInverted;
}

double opt_geometry_occ_boolean_glue(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occBooleanGlue = (int)val;
  return CTX::instance()->geom.occBooleanGlue;
}

double opt_geometry_occ_boolean_non_destructive(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occBooleanNonDestructive = (int)val;
  return CTX::instance()->geom.occBooleanNonDestructive;
}

double opt_geometry_occ_boolean_preserve_numbering(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occBooleanPreserveNumbering = (int)val;
  return CTX::instance()->geom.occBooleanPreserveNumbering;
}

double opt_geometry_occ_boolean_simplify(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.occBooleanSimplify = (int)val;
  return CTX::instance()->geom.occBooleanSimplify;
}

double opt_geometry_occ_scaling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occScaling = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.value[20]->value(
      CTX::instance()->geom.occScaling);
  }
#endif
  return CTX::instance()->geom.occScaling;
}

double opt_geometry_occ_export_only_visible(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occExportOnlyVisible = (int)val;
  return CTX::instance()->geom.occExportOnlyVisible;
}

double opt_geometry_occ_import_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occImportLabels = (int)val;
  return CTX::instance()->geom.occImportLabels;
}

double opt_geometry_occ_use_generic_closest_point(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.occUseGenericClosestPoint = (int)val;
  return CTX::instance()->geom.occUseGenericClosestPoint;
}

double opt_geometry_old_circle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.oldCircle = (int)val;
  return CTX::instance()->geom.oldCircle;
}

double opt_geometry_old_ruled_surface(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.oldRuledSurface = (int)val;
  return CTX::instance()->geom.oldRuledSurface;
}

double opt_geometry_old_newreg(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.oldNewreg = (int)val;
  return CTX::instance()->geom.oldNewreg;
}

double opt_geometry_num_sub_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->geom.numSubEdges = (int)val;
    if(CTX::instance()->geom.numSubEdges < 1)
      CTX::instance()->geom.numSubEdges = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->geo.value[19]->value(
      CTX::instance()->geom.numSubEdges);
  }
#endif
  return CTX::instance()->geom.numSubEdges;
}

double opt_geometry_extrude_spline_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.extrudeSplinePoints = (int)val;
  return CTX::instance()->geom.extrudeSplinePoints;
}

double opt_geometry_extrude_return_lateral(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.extrudeReturnLateral = (int)val;
  return CTX::instance()->geom.extrudeReturnLateral;
}

double opt_geometry_scaling_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.scalingFactor = val;
  return CTX::instance()->geom.scalingFactor;
}

double opt_geometry_snap_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.snapPoints = val;
  return CTX::instance()->geom.snapPoints;
}

double opt_geometry_snap0(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.snap[0] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->elementaryContext->value[0]->value(
      CTX::instance()->geom.snap[0]);
#endif
  return CTX::instance()->geom.snap[0];
}

double opt_geometry_snap1(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.snap[1] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->elementaryContext->value[1]->value(
      CTX::instance()->geom.snap[1]);
#endif
  return CTX::instance()->geom.snap[1];
}

double opt_geometry_snap2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.snap[2] = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->elementaryContext->value[2]->value(
      CTX::instance()->geom.snap[2]);
#endif
  return CTX::instance()->geom.snap[2];
}

double opt_geometry_clip(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.clip = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->geom.clip;
}

double opt_geometry_copy_meshing_method(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.copyMeshingMethod = (int)val;
  return CTX::instance()->geom.copyMeshingMethod;
}

double opt_geometry_double_clicked_entity_tag(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.doubleClickedEntityTag = (int)val;
  return CTX::instance()->geom.doubleClickedEntityTag;
}

double opt_geometry_exact_extrusion(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.exactExtrusion = (int)val;
  return CTX::instance()->geom.exactExtrusion;
}

double opt_geometry_match_geom_and_mesh(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.matchGeomAndMesh = (int)val;
  return CTX::instance()->geom.matchGeomAndMesh;
}

double opt_geometry_match_mesh_scale_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->geom.matchMeshScaleFactor = (double)val;
  return CTX::instance()->geom.matchMeshScaleFactor;
}

double opt_geometry_match_mesh_tolerance(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->geom.matchMeshTolerance = (double)val;
  return CTX::instance()->geom.matchMeshTolerance;
}

double opt_mesh_optimize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.optimize)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.optimize = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[2]->value(
      CTX::instance()->mesh.optimize);
#endif
  return CTX::instance()->mesh.optimize;
}

double opt_mesh_optimize_threshold(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.optimizeThreshold)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.optimizeThreshold = val;
  }
  return CTX::instance()->mesh.optimizeThreshold;
}

double opt_mesh_optimize_netgen(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.optimizeNetgen)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.optimizeNetgen = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[24]->value(
      CTX::instance()->mesh.optimizeNetgen);
#endif
  return CTX::instance()->mesh.optimizeNetgen;
}

double opt_mesh_refine_steps(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.refineSteps)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.refineSteps = (int)val;
  }
  return CTX::instance()->mesh.refineSteps;
}

double opt_mesh_renumber(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.renumber = (int)val;
  return CTX::instance()->mesh.renumber;
}

double opt_mesh_normals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.normals = val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[8]->value(
      CTX::instance()->mesh.normals);
#endif
  return CTX::instance()->mesh.normals;
}

double opt_mesh_num_sub_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.numSubEdges != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.numSubEdges = (int)val;
    if(CTX::instance()->mesh.numSubEdges < 1)
      CTX::instance()->mesh.numSubEdges = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[14]->value(
      CTX::instance()->mesh.numSubEdges);
#endif
  return CTX::instance()->mesh.numSubEdges;
}

double opt_mesh_tangents(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.tangents = val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[13]->value(
      CTX::instance()->mesh.tangents);
#endif
  return CTX::instance()->mesh.tangents;
}

double opt_mesh_explode(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.explode != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.explode = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[9]->value(
      CTX::instance()->mesh.explode);
#endif
  return CTX::instance()->mesh.explode;
}

double opt_mesh_scaling_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.scalingFactor)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.scalingFactor = val;
  }
  return CTX::instance()->mesh.scalingFactor;
}

double opt_mesh_lc_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(val > 0) {
      if(!(action & GMSH_SET_DEFAULT) && val != CTX::instance()->mesh.lcFactor)
        Msg::SetOnelabChanged(2);
      CTX::instance()->mesh.lcFactor = val;
      if(CTX::instance()->mesh.lcFactor <= 0.0){
        Msg::Error("Mesh element size factor must be > 0");
        CTX::instance()->mesh.lcFactor = 1.;
      }
    }
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[2]->value(
      CTX::instance()->mesh.lcFactor);
#endif
  return CTX::instance()->mesh.lcFactor;
}

double opt_mesh_lc_min(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) && val != CTX::instance()->mesh.lcMin)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcMin = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[25]->value(
      CTX::instance()->mesh.lcMin);
#endif
  return CTX::instance()->mesh.lcMin;
}

double opt_mesh_lc_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) && val != CTX::instance()->mesh.lcMax)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcMax = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[26]->value(
      CTX::instance()->mesh.lcMax);
#endif
  return CTX::instance()->mesh.lcMax;
}

double opt_mesh_tolerance_edge_length(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.toleranceEdgeLength)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.toleranceEdgeLength = val;
  }
  return CTX::instance()->mesh.toleranceEdgeLength;
}

double opt_mesh_tolerance_initial_delaunay(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.toleranceInitialDelaunay)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.toleranceInitialDelaunay = val;
  }
  return CTX::instance()->mesh.toleranceInitialDelaunay;
}

double opt_mesh_lc_from_curvature(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.lcFromCurvature)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcFromCurvature = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.value[1]->value(
      CTX::instance()->mesh.lcFromCurvature);
  }
#endif
  return CTX::instance()->mesh.lcFromCurvature;
}

double opt_mesh_lc_from_curvature_iso(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.lcFromCurvatureIso)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcFromCurvatureIso = (int)val;
  }
  return CTX::instance()->mesh.lcFromCurvatureIso;
}

double opt_mesh_lc_from_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.lcFromPoints)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcFromPoints = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.butt[5]->value(
      CTX::instance()->mesh.lcFromPoints ? 1 : 0);
  }
#endif
  return CTX::instance()->mesh.lcFromPoints;
}

double opt_mesh_lc_from_parametric_points(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.lcFromParametricPoints)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcFromParametricPoints = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[26]->value(
      CTX::instance()->mesh.lcFromParametricPoints ? 1 : 0);
#endif
  return CTX::instance()->mesh.lcFromParametricPoints;
}

double opt_mesh_lc_extend_from_boundary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.lcExtendFromBoundary)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcExtendFromBoundary = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[16]->value(
      CTX::instance()->mesh.lcExtendFromBoundary ? 1 : 0);
#endif
  return CTX::instance()->mesh.lcExtendFromBoundary;
}

double opt_mesh_lc_integration_precision(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.lcIntegrationPrecision)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.lcIntegrationPrecision = val;
  }
  return CTX::instance()->mesh.lcIntegrationPrecision;
}

double opt_mesh_check_surface_normal_validity(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.checkSurfaceNormalValidity = (int)val;
  }
  return CTX::instance()->mesh.checkSurfaceNormalValidity;
}

double opt_mesh_rand_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) && val != CTX::instance()->mesh.randFactor)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.randFactor = val;
  }
  return CTX::instance()->mesh.randFactor;
}

double opt_mesh_rand_factor3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.randFactor3d)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.randFactor3d = val;
  }
  return CTX::instance()->mesh.randFactor3d;
}

double opt_mesh_quality_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.qualityType != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.qualityType = (int)val;
    if(CTX::instance()->mesh.qualityType < 0 ||
       CTX::instance()->mesh.qualityType > 3)
      CTX::instance()->mesh.qualityType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[6]->value(
      CTX::instance()->mesh.qualityType);
  }
#endif
  return CTX::instance()->mesh.qualityType;
}

double opt_mesh_quality_inf(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.qualityInf != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.qualityInf = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[4]->value(
      CTX::instance()->mesh.qualityInf);
#endif
  return CTX::instance()->mesh.qualityInf;
}

double opt_mesh_quality_sup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.qualitySup != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.qualitySup = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[5]->value(
      CTX::instance()->mesh.qualitySup);
#endif
  return CTX::instance()->mesh.qualitySup;
}

double opt_mesh_radius_inf(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.radiusInf != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.radiusInf = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[6]->value(
      CTX::instance()->mesh.radiusInf);
#endif
  return CTX::instance()->mesh.radiusInf;
}

double opt_mesh_radius_sup(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.radiusSup != val)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.radiusSup = val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[7]->value(
      CTX::instance()->mesh.radiusSup);
#endif
  return CTX::instance()->mesh.radiusSup;
}

double opt_mesh_label_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.labelType = (int)val;
    if(CTX::instance()->mesh.labelType < 0 ||
       CTX::instance()->mesh.labelType > 4)
      CTX::instance()->mesh.labelType = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[7]->value(
      CTX::instance()->mesh.labelType);
  }
#endif
  return CTX::instance()->mesh.labelType;
}

double opt_mesh_first_element_tag(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.firstElementTag = (val > 1) ? (int)val : 1;
  }
  return CTX::instance()->mesh.firstElementTag;
}

double opt_mesh_first_node_tag(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.firstNodeTag = (val > 1) ? (int)val : 1;
  }
  return CTX::instance()->mesh.firstNodeTag;
}

double opt_mesh_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.nodes = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[6]->value(
      CTX::instance()->mesh.nodes);
#endif
  return CTX::instance()->mesh.nodes;
}

double opt_mesh_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.lines != val)
      CTX::instance()->mesh.changed |= ENT_CURVE;
    CTX::instance()->mesh.lines = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[7]->value(
      CTX::instance()->mesh.lines);
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
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.triangles)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[0].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[0]
        .clear();
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
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.quadrangles)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[1].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[1]
        .clear();
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
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.tetrahedra)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[2].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[2]
        .clear();
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
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.hexahedra)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[3].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[3]
        .clear();
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
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.prisms)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[4].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[4]
        .clear();
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
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.pyramids)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[5].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[5]
        .clear();
  }
#endif
  return CTX::instance()->mesh.pyramids;
}

double opt_mesh_trihedra(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.trihedra != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.trihedra = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    if(CTX::instance()->mesh.trihedra)
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[6].set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->mesh.menu->menu())[6]
        .clear();
  }
#endif
  return CTX::instance()->mesh.trihedra;
}

double opt_mesh_transfinite_tri(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.transfiniteTri = (int)val;
  return CTX::instance()->mesh.transfiniteTri;
}

double opt_mesh_surface_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.surfaceEdges != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.surfaceEdges = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[8]->value(
      CTX::instance()->mesh.surfaceEdges);
#endif
  return CTX::instance()->mesh.surfaceEdges;
}

double opt_mesh_surface_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.surfaceFaces != val)
      CTX::instance()->mesh.changed |= ENT_SURFACE;
    CTX::instance()->mesh.surfaceFaces = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[9]->value(
      CTX::instance()->mesh.surfaceFaces);
#endif
  return CTX::instance()->mesh.surfaceFaces;
}

double opt_mesh_volume_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.volumeEdges != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.volumeEdges = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[10]->value(
      CTX::instance()->mesh.volumeEdges);
#endif
  return CTX::instance()->mesh.volumeEdges;
}

double opt_mesh_volume_faces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.volumeFaces != val)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->mesh.volumeFaces = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[11]->value(
      CTX::instance()->mesh.volumeFaces);
#endif
  return CTX::instance()->mesh.volumeFaces;
}

double opt_mesh_node_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.nodeLabels = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[12]->value(
      CTX::instance()->mesh.nodeLabels);
#endif
  return CTX::instance()->mesh.nodeLabels;
}

double opt_mesh_line_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.lineLabels = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[13]->value(
      CTX::instance()->mesh.lineLabels);
#endif
  return CTX::instance()->mesh.lineLabels;
}

double opt_mesh_surface_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.surfaceLabels = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[14]->value(
      CTX::instance()->mesh.surfaceLabels);
#endif
  return CTX::instance()->mesh.surfaceLabels;
}

double opt_mesh_volume_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.volumeLabels = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[15]->value(
      CTX::instance()->mesh.volumeLabels);
#endif
  return CTX::instance()->mesh.volumeLabels;
}

double opt_mesh_node_size(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.nodeSize = val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[10]->value(
      CTX::instance()->mesh.nodeSize);
#endif
  return CTX::instance()->mesh.nodeSize;
}

double opt_mesh_node_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.nodeType = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[0]->value(
      CTX::instance()->mesh.nodeType ? 1 : 0);
  }
#endif
  return CTX::instance()->mesh.nodeType;
}

double opt_mesh_line_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.lineWidth = val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[11]->value(
      CTX::instance()->mesh.lineWidth);
#endif
  return CTX::instance()->mesh.lineWidth;
}

double opt_mesh_label_sampling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.labelSampling = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[12]->value(
      CTX::instance()->mesh.labelSampling);
#endif
  return CTX::instance()->mesh.labelSampling;
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
    FlGui::instance()->options->mesh.butt[19]->value(
      CTX::instance()->mesh.smoothNormals);
#endif
  return CTX::instance()->mesh.smoothNormals;
}

double opt_mesh_smooth_ratio(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.smoothRatio = val;
  return CTX::instance()->mesh.smoothRatio;
}

double opt_mesh_aniso_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.anisoMax = val;
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
    FlGui::instance()->options->mesh.value[18]->value(
      CTX::instance()->mesh.angleSmoothNormals);
#endif
  return CTX::instance()->mesh.angleSmoothNormals;
}

double opt_mesh_light(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.light = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.butt[17]->value(
      CTX::instance()->mesh.light);
    FlGui::instance()->options->activate("mesh_light");
  }
#endif
  return CTX::instance()->mesh.light;
}

double opt_mesh_light_lines(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(CTX::instance()->mesh.lightLines != (int)val)
      CTX::instance()->mesh.changed |= ENT_SURFACE | ENT_VOLUME;
    CTX::instance()->mesh.lightLines = (int)val;
    if(CTX::instance()->mesh.lightLines < 0 ||
       CTX::instance()->mesh.lightLines > 2)
      CTX::instance()->mesh.lightLines = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.choice[10]->value(
      CTX::instance()->mesh.lightLines);
#endif
  return CTX::instance()->mesh.lightLines;
}

double opt_mesh_light_two_side(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.lightTwoSide = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[18]->value(
      CTX::instance()->mesh.lightTwoSide);
#endif
  return CTX::instance()->mesh.lightTwoSide;
}

double opt_mesh_file_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.fileFormat = (int)val;
  return CTX::instance()->mesh.fileFormat;
}

double opt_mesh_newton_convergence_test_xyz(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.NewtonConvergenceTestXYZ = (int)val;
  return CTX::instance()->mesh.NewtonConvergenceTestXYZ;
}

double opt_mesh_msh_file_version(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.mshFileVersion = val;
  return CTX::instance()->mesh.mshFileVersion;
}

double opt_mesh_med_file_minor_version(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.medFileMinorVersion = val;
  return CTX::instance()->mesh.medFileMinorVersion;
}

double opt_mesh_med_import_groups_of_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.medImportGroupsOfNodes = (int)val;
  return CTX::instance()->mesh.medImportGroupsOfNodes;
}

double opt_mesh_med_single_model(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.medSingleModel = (int)val;
  return CTX::instance()->mesh.medSingleModel;
}

double opt_mesh_partition_split_mesh_files(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.partitionSplitMeshFiles = (int)val;
  return CTX::instance()->mesh.partitionSplitMeshFiles;
}

double opt_mesh_partition_save_topology_file(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.partitionSaveTopologyFile = (int)val;
  return CTX::instance()->mesh.partitionSaveTopologyFile;
}

double opt_mesh_partition_hex_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionHexWeight = (int)val;
  return CTX::instance()->mesh.partitionHexWeight;
}

double opt_mesh_partition_pri_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionPriWeight = (int)val;
  return CTX::instance()->mesh.partitionPriWeight;
}

double opt_mesh_partition_pyr_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionPyrWeight = (int)val;
  return CTX::instance()->mesh.partitionPyrWeight;
}

double opt_mesh_partition_trih_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionTrihWeight = (int)val;
  return CTX::instance()->mesh.partitionTrihWeight;
}

double opt_mesh_partition_qua_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionQuaWeight = (int)val;
  return CTX::instance()->mesh.partitionQuaWeight;
}

double opt_mesh_partition_tet_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionTetWeight = (int)val;
  return CTX::instance()->mesh.partitionTetWeight;
}

double opt_mesh_partition_tri_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionTriWeight = (int)val;
  return CTX::instance()->mesh.partitionTriWeight;
}

double opt_mesh_partition_line_weight(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionLinWeight = (int)val;
  return CTX::instance()->mesh.partitionLinWeight;
}

double opt_mesh_partition_create_physicals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionCreatePhysicals = val;
  return CTX::instance()->mesh.partitionCreatePhysicals;
}

double opt_mesh_partition_create_topology(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionCreateTopology = val;
  return CTX::instance()->mesh.partitionCreateTopology;
}

double opt_mesh_partition_create_ghost_cells(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionCreateGhostCells = val;
  return CTX::instance()->mesh.partitionCreateGhostCells;
}

double opt_mesh_partition_old_style_msh2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionOldStyleMsh2 = val;
  return CTX::instance()->mesh.partitionOldStyleMsh2;
}

double opt_mesh_partition_convert_msh2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.partitionConvertMsh2 = val;
  return CTX::instance()->mesh.partitionConvertMsh2;
}

double opt_mesh_create_topology_msh2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.createTopologyMsh2 = val;
  return CTX::instance()->mesh.createTopologyMsh2;
}

double opt_mesh_binary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.binary = (int)val;
  return CTX::instance()->mesh.binary;
}

double opt_mesh_boundary_layer_fan_elements(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int n = (int)val;
    if(n < 0) n = 0;
    CTX::instance()->mesh.boundaryLayerFanElements = n;
  }
  return CTX::instance()->mesh.boundaryLayerFanElements;
}

double opt_mesh_smooth_cross_field(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.smoothCrossField = (int)val;
  return CTX::instance()->mesh.smoothCrossField;
}

double opt_mesh_cross_field_closest_point(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.crossFieldClosestPoint = (int)val;
  return CTX::instance()->mesh.crossFieldClosestPoint;
}

double opt_mesh_bdf_field_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.bdfFieldFormat = (int)val;
    if(CTX::instance()->mesh.bdfFieldFormat < 0 ||
       CTX::instance()->mesh.bdfFieldFormat > 2)
      CTX::instance()->mesh.bdfFieldFormat = 1;
  }
  return CTX::instance()->mesh.bdfFieldFormat;
}

double opt_mesh_stl_remove_duplicate_triangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.stlRemoveDuplicateTriangles = (int)val;
  }
  return CTX::instance()->mesh.stlRemoveDuplicateTriangles;
}

double opt_mesh_stl_one_solid_per_surface(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.stlOneSolidPerSurface = (int)val;
  }
  return CTX::instance()->mesh.stlOneSolidPerSurface;
}

double opt_mesh_stl_linear_deflection(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.stlLinearDeflection = val; }
  return CTX::instance()->mesh.stlLinearDeflection;
}

double opt_mesh_stl_linear_deflection_relative(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.stlLinearDeflectionRelative = val ? true : false;
  }
  return CTX::instance()->mesh.stlLinearDeflectionRelative ? 1 : 0;
}

double opt_mesh_stl_angular_deflection(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.stlAngularDeflection = val; }
  return CTX::instance()->mesh.stlAngularDeflection;
}

double opt_mesh_nb_smoothing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.nbSmoothing = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[0]->value(
      CTX::instance()->mesh.nbSmoothing);
#endif
  return CTX::instance()->mesh.nbSmoothing;
}

double opt_mesh_algo2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) && (int)val != CTX::instance()->mesh.algo2d)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.algo2d = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    switch(CTX::instance()->mesh.algo2d) {
    case ALGO_2D_MESHADAPT:
      FlGui::instance()->options->mesh.choice[2]->value(1);
      break;
    case ALGO_2D_DELAUNAY:
      FlGui::instance()->options->mesh.choice[2]->value(2);
      break;
    case ALGO_2D_FRONTAL:
      FlGui::instance()->options->mesh.choice[2]->value(3);
      break;
    case ALGO_2D_BAMG:
      FlGui::instance()->options->mesh.choice[2]->value(4);
      break;
    case ALGO_2D_FRONTAL_QUAD:
      FlGui::instance()->options->mesh.choice[2]->value(5);
      break;
    case ALGO_2D_PACK_PRLGRMS:
      FlGui::instance()->options->mesh.choice[2]->value(6);
      break;
    case ALGO_2D_QUAD_QUASI_STRUCT:
      FlGui::instance()->options->mesh.choice[2]->value(7);
      break;
    case ALGO_2D_INITIAL_ONLY:
      FlGui::instance()->options->mesh.choice[2]->value(8);
      break;
    case ALGO_2D_AUTO:
    default: FlGui::instance()->options->mesh.choice[2]->value(0); break;
    }
  }
#endif
  return CTX::instance()->mesh.algo2d;
}

double opt_mesh_algo_switch_on_failure(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.algoSwitchOnFailure = (int)val;
  }
  return CTX::instance()->mesh.algoSwitchOnFailure;
}

double opt_mesh_max_retries(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.maxRetries = (int)val; }
  return CTX::instance()->mesh.maxRetries;
}

double opt_mesh_algo_recombine(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.algoRecombine)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.algoRecombine = (int)val;
    if(CTX::instance()->mesh.algoRecombine < 0 ||
       CTX::instance()->mesh.algoRecombine > 4)
      CTX::instance()->mesh.algoRecombine = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[1]->value(
      CTX::instance()->mesh.algoRecombine);
  }
#endif
  return CTX::instance()->mesh.algoRecombine;
}

double opt_mesh_recombine_all(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.recombineAll)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.recombineAll = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[21]->value(
      CTX::instance()->mesh.recombineAll);
#endif
  return CTX::instance()->mesh.recombineAll;
}

double opt_mesh_recombine_optimize_topology(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.recombineOptimizeTopology = (int)val;
  }
  return CTX::instance()->mesh.recombineOptimizeTopology;
}

double opt_mesh_recombine_node_repositioning(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.recombineNodeRepositioning = (int)val;
  }
  return CTX::instance()->mesh.recombineNodeRepositioning;
}

double opt_mesh_recombine_minimum_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.recombineMinimumQuality = val;
  }
  return CTX::instance()->mesh.recombineMinimumQuality;
}

double opt_mesh_recombine3d_all(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.recombine3DAll)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.recombine3DAll = (int)val;
  }
  return CTX::instance()->mesh.recombine3DAll;
}

double opt_mesh_recombine3d_level(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.recombine3DLevel = (int)val; }
  return CTX::instance()->mesh.recombine3DLevel;
}

double opt_mesh_recombine3d_conformity(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.recombine3DConformity = (int)val;
  }
  return CTX::instance()->mesh.recombine3DConformity;
}

double opt_mesh_flexible_transfinite(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.flexibleTransfinite = (int)val;
  }
  return CTX::instance()->mesh.flexibleTransfinite;
}

double opt_mesh_quasi_transfinite(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.quasiTransfinite = (int)val;
  }
  return CTX::instance()->mesh.quasiTransfinite;
}

double opt_mesh_algo_subdivide(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.algoSubdivide)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.algoSubdivide = (int)val;
    if(CTX::instance()->mesh.algoSubdivide < 0 &&
       CTX::instance()->mesh.algoSubdivide > 2)
      CTX::instance()->mesh.algoSubdivide = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[5]->value(
      CTX::instance()->mesh.algoSubdivide);
  }
#endif
  return CTX::instance()->mesh.algoSubdivide;
}

double opt_mesh_algo3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) && (int)val != CTX::instance()->mesh.algo3d)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.algo3d = (int)val;
    // "New Delaunay" is now simply "Delaunay"
    if(CTX::instance()->mesh.algo3d == 2)
      CTX::instance()->mesh.algo3d = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    switch(CTX::instance()->mesh.algo3d) {
    case ALGO_3D_FRONTAL:
      FlGui::instance()->options->mesh.choice[3]->value(1);
      break;
    case ALGO_3D_HXT:
      FlGui::instance()->options->mesh.choice[3]->value(2);
      break;
    case ALGO_3D_MMG3D:
      FlGui::instance()->options->mesh.choice[3]->value(3);
      break;
    case ALGO_3D_INITIAL_ONLY:
      FlGui::instance()->options->mesh.choice[3]->value(4);
      break;
    case ALGO_3D_DELAUNAY:
    default: FlGui::instance()->options->mesh.choice[3]->value(0); break;
    }
  }
#endif
  return CTX::instance()->mesh.algo3d;
}

double opt_mesh_mesh_only_visible(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.meshOnlyVisible)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.meshOnlyVisible = (int)val;
  }
  return CTX::instance()->mesh.meshOnlyVisible;
}

double opt_mesh_mesh_only_empty(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.meshOnlyEmpty)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.meshOnlyEmpty = (int)val;
  }
  return CTX::instance()->mesh.meshOnlyEmpty;
}

double opt_mesh_min_line_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.minLineNodes)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.minLineNodes = std::max((int)val, 2);
  }
  return CTX::instance()->mesh.minLineNodes;
}

double opt_mesh_min_circle_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.minCircleNodes)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.minCircleNodes = std::max((int)val, 2);
  }
  return CTX::instance()->mesh.minCircleNodes;
}

double opt_mesh_allow_swap_edge_angle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.allowSwapEdgeAngle = val;
  return CTX::instance()->mesh.allowSwapEdgeAngle;
}

double opt_mesh_min_curve_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.minCurveNodes)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.minCurveNodes = std::max((int)val, 2);
  }
  return CTX::instance()->mesh.minCurveNodes;
}

double opt_mesh_order(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) && (int)val != CTX::instance()->mesh.order)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.order = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.value[3]->value(
      CTX::instance()->mesh.order);
#endif
  return CTX::instance()->mesh.order;
}

double opt_mesh_ho_optimize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoOptimize = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[3]->value(
      CTX::instance()->mesh.hoOptimize == 2 ? 1 : 0);
#endif
  return CTX::instance()->mesh.hoOptimize;
}

double opt_mesh_ho_periodic(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoPeriodic = (int)val;
  return CTX::instance()->mesh.hoPeriodic;
}

double opt_mesh_ho_save_periodic(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoSavePeriodic = (int)val;
  return CTX::instance()->mesh.hoSavePeriodic;
}

double opt_mesh_ho_nlayers(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoNLayers = (int)val;
  return CTX::instance()->mesh.hoNLayers;
}

double opt_mesh_ho_threshold_min(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoThresholdMin = val;
  return CTX::instance()->mesh.hoThresholdMin;
}

double opt_mesh_ho_threshold_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoThresholdMax = val;
  return CTX::instance()->mesh.hoThresholdMax;
}

double opt_mesh_ho_prim_surf_mesh(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoPrimSurfMesh = (int)val;
  return CTX::instance()->mesh.hoPrimSurfMesh;
}

double opt_mesh_ho_dist_cad(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoDistCAD = (int)val;
  return CTX::instance()->mesh.hoDistCAD;
}

double opt_mesh_ho_iter_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoIterMax = (int)val;
  return CTX::instance()->mesh.hoIterMax;
}

double opt_mesh_ho_pass_max(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoPassMax = (int)val;
  return CTX::instance()->mesh.hoPassMax;
}

double opt_mesh_ho_poisson(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    double ratio = val;
    if(ratio <= -1.0)
      ratio = -0.999;
    else if(ratio >= 0.5)
      ratio = 0.499;
    CTX::instance()->mesh.hoPoissonRatio = ratio;
  }
  return CTX::instance()->mesh.hoPoissonRatio;
}

double opt_mesh_ho_fast_new_algo(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.hoNewFastCurvingAlgo = !(val == 0.);
  return CTX::instance()->mesh.hoNewFastCurvingAlgo ? 1. : 0.;
}

double opt_mesh_ho_curve_outer_BL(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoCurveOuterBL = (int)val;
  return CTX::instance()->mesh.hoCurveOuterBL;
}

double opt_mesh_ho_max_rho(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoMaxRho = val;
  return CTX::instance()->mesh.hoMaxRho;
}

double opt_mesh_ho_max_angle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoMaxAngle = val;
  return CTX::instance()->mesh.hoMaxAngle;
}

double opt_mesh_ho_max_in_angle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoMaxInnerAngle = val;
  return CTX::instance()->mesh.hoMaxInnerAngle;
}

double opt_mesh_ho_fix_bnd_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoFixBndNodes = val;
  return CTX::instance()->mesh.hoFixBndNodes;
}

double opt_mesh_ho_skip_quality_check(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.hoSkipQualityCheck = val;
  return CTX::instance()->mesh.hoSkipQualityCheck;
}

double opt_mesh_second_order_linear(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.secondOrderLinear)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.secondOrderLinear = (int)val;
  }
  return CTX::instance()->mesh.secondOrderLinear;
}

double opt_mesh_second_order_incomplete(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       (int)val != CTX::instance()->mesh.secondOrderIncomplete)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.secondOrderIncomplete = (int)val;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->mesh.butt[4]->value(
      CTX::instance()->mesh.secondOrderIncomplete);
#endif
  return CTX::instance()->mesh.secondOrderIncomplete;
}

double opt_mesh_cgns_import_order(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    int value = std::min((int)val, 4);
    CTX::instance()->mesh.cgnsImportOrder = value;
  }
  return CTX::instance()->mesh.cgnsImportOrder;
}

double opt_mesh_cgns_import_ignore_bc(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.cgnsImportIgnoreBC = (int)val;
  }
  return CTX::instance()->mesh.cgnsImportIgnoreBC;
}

double opt_mesh_cgns_import_ignore_solution(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.cgnsImportIgnoreSolution = (int)val;
  }
  return CTX::instance()->mesh.cgnsImportIgnoreSolution;
}

double opt_mesh_cgns_construct_topology(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.cgnsConstructTopology = (int)val;
  }
  return CTX::instance()->mesh.cgnsConstructTopology;
}

double opt_mesh_cgns_export_cpex0045(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.cgnsExportCPEX0045 = (int)val;
  }
  return CTX::instance()->mesh.cgnsExportCPEX0045;
}

double opt_mesh_cgns_export_structured(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.cgnsExportStructured = (int)val;
  }
  return CTX::instance()->mesh.cgnsExportStructured;
}

double opt_mesh_dual(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.dual = (int)val; }
  return CTX::instance()->mesh.dual;
}

double opt_mesh_voronoi(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.voronoi = (int)val; }
  return CTX::instance()->mesh.voronoi;
}

double opt_mesh_draw_skin_only(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->mesh.drawSkinOnly = (int)val; }
  return CTX::instance()->mesh.drawSkinOnly;
}

double opt_mesh_save_all(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.saveAll = (int)val;
  return CTX::instance()->mesh.saveAll;
}

double opt_mesh_save_element_tag_type(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.saveElementTagType = (int)val;
  return CTX::instance()->mesh.saveElementTagType;
}

double opt_mesh_save_parametric(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.saveParametric = val ? 1 : 0;
  return CTX::instance()->mesh.saveParametric;
}

double opt_mesh_save_without_orphans(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.saveWithoutOrphans = (int)val;
  return CTX::instance()->mesh.saveWithoutOrphans;
}

double opt_mesh_save_topology(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.saveTopology = val ? 1 : 0;
  return CTX::instance()->mesh.saveTopology;
}

double opt_mesh_read_groups_of_elements(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.readGroupsOfElements = (int)val;
  return CTX::instance()->mesh.readGroupsOfElements;
}

double opt_mesh_save_groups_of_elements(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.saveGroupsOfElements = (int)val;
  return CTX::instance()->mesh.saveGroupsOfElements;
}

double opt_mesh_save_groups_of_nodes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.saveGroupsOfNodes = (int)val;
  return CTX::instance()->mesh.saveGroupsOfNodes;
}

double opt_mesh_color_carousel(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type or by partition
    if(CTX::instance()->mesh.colorCarousel != (int)val &&
       ((val == 0. || val == 3.) || CTX::instance()->pickElements))
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->mesh.colorCarousel = (int)val;
    if(CTX::instance()->mesh.colorCarousel < 0 ||
       CTX::instance()->mesh.colorCarousel > 3)
      CTX::instance()->mesh.colorCarousel = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->mesh.choice[4]->value(
      CTX::instance()->mesh.colorCarousel);
    drawContext::global()->resetFontTextures();
  }
#endif
  return CTX::instance()->mesh.colorCarousel;
}

double opt_mesh_compound_classify(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.compoundClassify = (int)val;
  return CTX::instance()->mesh.compoundClassify;
}

double opt_mesh_compound_lc_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.compoundLcFactor = val;
  return CTX::instance()->mesh.compoundLcFactor;
}

double opt_mesh_random_seed(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.randomSeed = (unsigned int)val;
  return CTX::instance()->mesh.randomSeed;
}

double opt_mesh_switch_elem_tags(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.switchElementTags = val ? 1 : 0;
  return CTX::instance()->mesh.switchElementTags;
}

double opt_mesh_zone_definition(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->mesh.zoneDefinition = (int)val;
    if((CTX::instance()->mesh.zoneDefinition < 0 ||
        CTX::instance()->mesh.zoneDefinition > 2) ||
       (CTX::instance()->mesh.zoneDefinition == 1))
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
  return s[4];
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

double opt_mesh_nb_trihedra(OPT_ARGS_NUM)
{
  double s[50];
  GetStatistics(s);
  return s[13];
}

double opt_mesh_cpu_time(OPT_ARGS_NUM)
{
  return CTX::instance()->mesh.timer[0] + CTX::instance()->mesh.timer[1] +
    CTX::instance()->mesh.timer[2];
}

double opt_mesh_min_quality(OPT_ARGS_NUM)
{
  return CTX::instance()->mesh.minQuality;
}

double opt_mesh_partition_num(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    const int ival = std::max(0, (int)val);
    CTX::instance()->mesh.numPartitions = ival;
    CTX::instance()->mesh.metisAlgorithm = (ival <= 8) ? 1 : 2;
  }
  return CTX::instance()->mesh.numPartitions;
}

double opt_mesh_partition_metis_algorithm(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.metisAlgorithm = (int)val;
  return CTX::instance()->mesh.metisAlgorithm;
}

double opt_mesh_partition_metis_edge_matching(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.metisEdgeMatching = (int)val;
  return CTX::instance()->mesh.metisEdgeMatching;
}

double opt_mesh_partition_metis_refinement_algorithm(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.metisRefinementAlgorithm = (int)val;
  return CTX::instance()->mesh.metisRefinementAlgorithm;
}

double opt_mesh_partition_metis_max_load_imbalance(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.metisMaxLoadImbalance = val;
  return CTX::instance()->mesh.metisMaxLoadImbalance;
}

double opt_mesh_partition_metis_objective(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.metisObjective = (int)val;
  return CTX::instance()->mesh.metisObjective;
}

double opt_mesh_partition_metis_min_conn(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.metisMinConn = (int)val;
  return CTX::instance()->mesh.metisMinConn;
}

double opt_mesh_clip(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.clip = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->clipping->resetBrowser();
#endif
  return CTX::instance()->mesh.clip;
}

double opt_mesh_preserve_numbering_msh2(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.preserveNumberingMsh2 = (int)val;
  return CTX::instance()->mesh.preserveNumberingMsh2;
}

double opt_mesh_ignore_unknown_sections(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.ignoreUnknownSections = (int)val;
  return CTX::instance()->mesh.ignoreUnknownSections;
}

double opt_mesh_ignore_periodicity(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.ignorePeriodicityMsh2 = (int)val;
  return CTX::instance()->mesh.ignorePeriodicityMsh2;
}

double opt_mesh_max_iter_delaunay_3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.maxIterDelaunay3D = (int)val;
  return CTX::instance()->mesh.maxIterDelaunay3D;
}

double opt_mesh_max_num_threads_1d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.maxNumThreads1D = (int)val;
  return CTX::instance()->mesh.maxNumThreads1D;
}

double opt_mesh_max_num_threads_2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.maxNumThreads2D = (int)val;
  return CTX::instance()->mesh.maxNumThreads2D;
}

double opt_mesh_max_num_threads_3d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.maxNumThreads3D = (int)val;
  return CTX::instance()->mesh.maxNumThreads3D;
}

double opt_mesh_angle_tolerance_facet_overlap(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    if(!(action & GMSH_SET_DEFAULT) &&
       val != CTX::instance()->mesh.angleToleranceFacetOverlap)
      Msg::SetOnelabChanged(2);
    CTX::instance()->mesh.angleToleranceFacetOverlap = val;
  }
  return CTX::instance()->mesh.angleToleranceFacetOverlap;
}

double opt_mesh_tolerance_reference_element(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.toleranceReferenceElement = val;
  return CTX::instance()->mesh.toleranceReferenceElement;
}

double opt_mesh_unv_strict_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.unvStrictFormat = (int)val;
  return CTX::instance()->mesh.unvStrictFormat;
}

double opt_mesh_reparam_max_triangles(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.reparamMaxTriangles = (int)val;
  return CTX::instance()->mesh.reparamMaxTriangles;
}

double opt_mesh_ignore_parametrization(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.ignoreParametrizationMsh4 = (int)val;
  return CTX::instance()->mesh.ignoreParametrizationMsh4;
}

double opt_mesh_quadqs_sizemap_method(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->mesh.quadqsSizemapMethod = (int)val;
  return CTX::instance()->mesh.quadqsSizemapMethod;
}

double opt_mesh_quadqs_remeshing_boldness(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.quadqsRemeshingBoldness = (double)val;
  return CTX::instance()->mesh.quadqsRemeshingBoldness;
}

double opt_mesh_quadqs_topo_optim_methods(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.quadqsTopoOptimMethods = (int)val;
  return CTX::instance()->mesh.quadqsTopoOptimMethods;
}

double opt_mesh_quadqs_scaling_on_triangulation(OPT_ARGS_NUM) {
  if(action & GMSH_SET) CTX::instance()->mesh.quadqsScalingOnTriangulation = (double)val;
  return CTX::instance()->mesh.quadqsScalingOnTriangulation;
}

double opt_mesh_old_initial_delaunay_2d(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->mesh.oldInitialDelaunay2D = (int)val;
  return CTX::instance()->mesh.oldInitialDelaunay2D;
}

double opt_solver_listen(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.listen = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.butt[0]->value(
      CTX::instance()->solver.listen);
#endif
  return CTX::instance()->solver.listen;
}

double opt_solver_timeout(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.timeout = val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->solver.value[0]->value(
      CTX::instance()->solver.timeout);
#endif
  return CTX::instance()->solver.timeout;
}

double opt_solver_plugins(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.plugins = (int)val;
  return CTX::instance()->solver.plugins;
}

double opt_solver_auto_load_database(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoLoadDatabase = (int)val;
  return CTX::instance()->solver.autoLoadDatabase;
}

double opt_solver_auto_save_database(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoSaveDatabase = (int)val;
  return CTX::instance()->solver.autoSaveDatabase;
}

double opt_solver_auto_archive_output_files(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.autoArchiveOutputFiles = (int)val;
  return CTX::instance()->solver.autoArchiveOutputFiles;
}

double opt_solver_auto_check(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoCheck = (int)val;
  return CTX::instance()->solver.autoCheck;
}

double opt_solver_auto_mesh(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoMesh = (int)val;
  return CTX::instance()->solver.autoMesh;
}

double opt_solver_auto_merge_file(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoMergeFile = (int)val;
  return CTX::instance()->solver.autoMergeFile;
}

double opt_solver_auto_show_views(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoShowViews = (int)val;
  return CTX::instance()->solver.autoShowViews;
}

double opt_solver_auto_show_last_step(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->solver.autoShowLastStep = (int)val;
  return CTX::instance()->solver.autoShowLastStep;
}

double opt_solver_show_invisible_parameters(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->solver.showInvisibleParameters = (int)val;
  return CTX::instance()->solver.showInvisibleParameters;
}

double opt_post_horizontal_scales(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.horizontalScales = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.butt[2]->value(
      CTX::instance()->post.horizontalScales);
#endif
  return CTX::instance()->post.horizontalScales;
}

double opt_post_binary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.binary = (int)val;
  return CTX::instance()->post.binary;
}

double opt_post_link(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) { CTX::instance()->post.link = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI)) {
    FlGui::instance()->options->post.choice[0]->value(
      CTX::instance()->post.link ? 1 : 0);
  }
#endif
  return CTX::instance()->post.link;
}

double opt_post_smooth(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.smooth = (int)val;
  return CTX::instance()->post.smooth;
}

double opt_post_anim_delay(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.animDelay = (val >= 0.) ? val : 0.;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.value[0]->value(
      CTX::instance()->post.animDelay);
#endif
  return CTX::instance()->post.animDelay;
}

double opt_post_anim_cycle(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->post.animCycle = (int)val;
    if(CTX::instance()->post.animCycle < 0 ||
       CTX::instance()->post.animCycle > 2)
      CTX::instance()->post.animCycle = 0;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.butt[0]->value(
      CTX::instance()->post.animCycle);
  if(FlGui::available())
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
      FlGui::instance()->graph[i]->checkAnimButtons();
#endif
  return CTX::instance()->post.animCycle;
}

double opt_post_anim_step(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) {
    CTX::instance()->post.animStep = (int)val;
    if(CTX::instance()->post.animStep < 1) CTX::instance()->post.animStep = 1;
  }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.value[1]->value(
      CTX::instance()->post.animStep);
#endif
  return CTX::instance()->post.animStep;
}

double opt_post_combine_remove_orig(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.combineRemoveOrig = (int)val;
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI))
    FlGui::instance()->options->post.butt[1]->value(
      CTX::instance()->post.combineRemoveOrig);
#endif
  return CTX::instance()->post.combineRemoveOrig;
}

double opt_post_combine_copy_options(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.combineCopyOptions = (int)val;
  return CTX::instance()->post.combineCopyOptions;
}

double opt_post_plugins(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.plugins = (int)val;
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
  if(action & GMSH_SET) CTX::instance()->post.fileFormat = (int)val;
  return CTX::instance()->post.fileFormat;
}

double opt_post_force_node_data(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.forceNodeData = (int)val;
  return CTX::instance()->post.forceNodeData;
}

double opt_post_force_element_data(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.forceElementData = (int)val;
  return CTX::instance()->post.forceElementData;
}

double opt_post_save_mesh(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.saveMesh = (int)val;
  return CTX::instance()->post.saveMesh;
}

double opt_post_save_interpolation_matrices(OPT_ARGS_NUM)
{
  if(action & GMSH_SET)
    CTX::instance()->post.saveInterpolationMatrices = (int)val;
  return CTX::instance()->post.saveInterpolationMatrices;
}

double opt_post_double_clicked_graph_point_x(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.doubleClickedGraphPointX = val;
  return CTX::instance()->post.doubleClickedGraphPointX;
}

double opt_post_double_clicked_graph_point_y(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.doubleClickedGraphPointY = val;
  return CTX::instance()->post.doubleClickedGraphPointY;
}

double opt_post_double_clicked_view(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->post.doubleClickedView = (int)val;
  return CTX::instance()->post.doubleClickedView;
}

double opt_view_nb_timestep(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 1;
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num))
    FlGui::instance()->options->view.value[50]->maximum(
      data->getNumTimeSteps() - 1);
  if(FlGui::available())
    for(std::size_t i = 0; i < FlGui::instance()->graph.size(); i++)
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
  GET_VIEWd(0.);
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
  if(action & GMSH_SET) {
    opt->timeStep = (int)val;
    if(data) {
      if(opt->timeStep > data->getNumTimeSteps() - 1)
        opt->timeStep = 0;
      else if(opt->timeStep < 0)
        opt->timeStep = data->getNumTimeSteps() - 1;
      if(data->getAdaptiveData())
        data->getAdaptiveData()->changeResolution(
          opt->timeStep, opt->maxRecursionLevel, opt->targetError);
      opt->currentTime = data->getTime(opt->timeStep);
    }
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

double opt_view_time(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(data && (action & GMSH_SET)) {
    if(val >= 0.) {
      // if negative (the default), don't do anything so that we do not compete
      // with timestep
      double dt_min = std::numeric_limits<double>::max();
      int step = 0;
      for(int i = 0; i < data->getNumTimeSteps(); i++) {
        double dt = std::abs(data->getTime(i) - val);
        if(dt < dt_min) {
          step = i;
          dt_min = std::min(dt_min, dt);
        }
      }
      opt_view_timestep(num, action, step);
    }
  }
  return opt->currentTime;
#else
  return 0.;
#endif
}

double opt_view_min(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
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
  GET_VIEWd(0.);
  if(!data) return 0.;
  // use adaptive data if available
  return view->getData(true)->getMax();
#else
  return 0.;
#endif
}

double opt_view_min_visible(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  int tensorRep = (opt->tensorType == PViewOptions::VonMises) ?
                    0 :
                    (opt->tensorType == PViewOptions::MaxEigenValue) ? 1 : 2;
  return data->getMin(opt->timeStep, true, tensorRep, opt->forceNumComponents,
                      opt->componentMap);
#else
  return 0.;
#endif
}

double opt_view_max_visible(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEW(0.);
  if(!data) return 0.;
  int tensorRep = (opt->tensorType == PViewOptions::VonMises) ?
                    0 :
                    (opt->tensorType == PViewOptions::MinEigenValue) ? 2 : 1;
  return data->getMax(opt->timeStep, true, tensorRep, opt->forceNumComponents,
                      opt->componentMap);
#else
  return 0.;
#endif
}

double opt_view_custom_min(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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

double opt_view_custom_abscissa_min(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->customAbscissaMin = val;
    if(view) view->setChanged(true);
  }
  return opt->customAbscissaMin;
#else
  return 0.;
#endif
}

double opt_view_custom_abscissa_max(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->customAbscissaMax = val;
    if(view) view->setChanged(true);
  }
  return opt->customAbscissaMax;
#else
  return 0.;
#endif
}

double opt_view_xmin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 0.;
  return data->getBoundingBox().min().x();
#else
  return 0.;
#endif
}

double opt_view_xmax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 0.;
  return data->getBoundingBox().max().x();
#else
  return 0.;
#endif
}

double opt_view_ymin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 0.;
  return data->getBoundingBox().min().y();
#else
  return 0.;
#endif
}

double opt_view_ymax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 0.;
  return data->getBoundingBox().max().y();
#else
  return 0.;
#endif
}

double opt_view_zmin(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 0.;
  return data->getBoundingBox().min().z();
#else
  return 0.;
#endif
}

double opt_view_zmax(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWd(0.);
  if(!data) return 0.;
  return data->getBoundingBox().max().z();
#else
  return 0.;
#endif
}

double opt_view_offset0(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->arrowSizeMin = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->arrowSizeMax = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->normals = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->tangents = val; }
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->visible = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI) && num >= 0 &&
     FlGui::instance()->onelab->getViewButton(num))
    FlGui::instance()->onelab->getViewButton(num)->value(opt->visible);
#endif
  return opt->visible;
#else
  return 0.;
#endif
}

double opt_view_intervals_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->intervalsType = (int)val;
    if(opt->intervalsType < 1 || opt->intervalsType > 4) opt->intervalsType = 1;
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
  GET_VIEWo(0.);
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
    if(data) {
      if(opt->adaptVisualizationGrid)
        data->initAdaptiveData(opt->timeStep, opt->maxRecursionLevel,
                               opt->targetError);
      else
        data->destroyAdaptiveData();
      view->setChanged(true);
    }
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.butt[0]->value(
      opt->adaptVisualizationGrid);
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
    if(data && data->getAdaptiveData()) {
      data->getAdaptiveData()->changeResolution(
        opt->timeStep, opt->maxRecursionLevel, opt->targetError);
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
    if(data && data->getAdaptiveData()) {
      data->getAdaptiveData()->changeResolution(
        opt->timeStep, opt->maxRecursionLevel, opt->targetError);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->type = (int)val;
    if(opt->type < 1 || opt->type > 4) opt->type = 1;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->autoPosition = (int)val;
    if(opt->autoPosition < 0 || opt->autoPosition > 12) opt->autoPosition = 0;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->position[0] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->position[1] = val; }
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->size[0] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->size[1] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->axes = (int)val;
    if(opt->axes < 0 || opt->axes > 5) opt->axes = 0;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesMikado = (int)val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesAutoPosition = (int)val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesPosition[0] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesPosition[1] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesPosition[2] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesPosition[3] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesPosition[4] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesPosition[5] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesTics[0] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesTics[1] = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->axesTics[2] = val; }
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->boundary = (int)val;
    if(opt->boundary < 0 || opt->boundary > 3) opt->boundary = 0;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->light = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->lightTwoSide = (int)val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->lightLines = (int)val; }
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->showTime = (int)val;
    if(opt->showTime < 0 || opt->showTime > 7) opt->showTime = 0;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->showScale = (int)val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->drawStrings = (int)val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawPoints = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawPoints)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[0]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[0]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawLines = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawLines)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[1]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[1]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawTriangles = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawTriangles)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[2]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[2]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawQuadrangles = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawQuadrangles)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[3]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[3]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawTetrahedra = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawTetrahedra)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[4]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[4]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawHexahedra = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawHexahedra)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[5]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[5]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawPrisms = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawPrisms)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[6]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[6]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawPyramids = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawPyramids)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[7]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[7]
        .clear();
  }
#endif
  return opt->drawPyramids;
#else
  return 0.;
#endif
}

double opt_view_draw_trihedra(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawTrihedra = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawTrihedra)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[8]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[1]->menu())[8]
        .clear();
  }
#endif
  return opt->drawTrihedra;
#else
  return 0.;
#endif
}

double opt_view_draw_scalars(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawScalars = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawScalars)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[0]->menu())[0]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[0]->menu())[0]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawVectors = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawVectors)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[0]->menu())[1]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[0]->menu())[1]
        .clear();
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->drawTensors = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    if(opt->drawTensors)
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[0]->menu())[2]
        .set();
    else
      ((Fl_Menu_Item *)FlGui::instance()->options->view.menu[0]->menu())[2]
        .clear();
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->scaleType = (int)val;
    if(opt->scaleType < 1 || opt->scaleType > 3) opt->scaleType = 1;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->rangeType = (int)val;
    if(opt->rangeType < 1 || opt->rangeType > 3) opt->rangeType = 1;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.choice[7]->value(opt->rangeType - 1);
    FlGui::instance()->options->activate("custom_range");
  }
#endif
  return opt->rangeType;
#else
  return 0.;
#endif
}

double opt_view_abscissa_range_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->abscissaRangeType = (int)val;
    if(opt->abscissaRangeType < 1 || opt->abscissaRangeType > 3)
      opt->abscissaRangeType = 1;
    if(view) view->setChanged(true);
  }
  return opt->abscissaRangeType;
#else
  return 0.;
#endif
}

double opt_view_tensor_type(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->tensorType = (int)val;
    if(opt->tensorType > 8 || opt->tensorType < 1) opt->tensorType = 1;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->vectorType = (int)val;
    if(opt->vectorType < 1 || opt->vectorType > 6) opt->vectorType = 1;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->glyphLocation = (int)val;
    if(opt->glyphLocation < 1 || opt->glyphLocation > 2) opt->glyphLocation = 1;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->centerGlyphs = (int)val;
    if(opt->centerGlyphs < 0 || opt->centerGlyphs > 2) opt->glyphLocation = 0;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->pointSize = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->lineWidth = val; }
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->pointType = (int)val;
    if(opt->pointType < 0 || opt->pointType > 3) opt->pointType = 0;
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->lineType = (int)val;
    if(opt->lineType < 0 || opt->lineType > 2) opt->lineType = 0;
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    int n = (int)val;
    if(n < 0) n = 24;
    if(n > 24) n = 0;
    opt->colorTable.ipar[COLORTABLE_NUMBER] = n;
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->externalViewIndex = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    // warning: Fl_Choice::size() returns number of items+1
    int item = opt->externalViewIndex + 1;
    if(item > -1 &&
       item < FlGui::instance()->options->view.choice[10]->size() - 1)
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->viewIndexForGenRaise = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    // warning: Fl_Choice::size() returns number of items+1
    int item = opt->viewIndexForGenRaise + 1;
    if(item > -1 &&
       item < FlGui::instance()->options->view.choice[11]->size() - 1)
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
  GET_VIEWo(0.);
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->useGenRaise = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->useStipple = (int)val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->clip = (int)val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->forceNumComponents = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0.);
  if(action & GMSH_SET) {
    opt->componentMap[nn] = (int)val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    FlGui::instance()->options->view.value[70 + nn]->value(
      opt->componentMap[nn]);
  }
#endif
  return opt->componentMap[nn];
#else
  return 0.;
#endif
}

double opt_view_component_map0(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 0);
}
double opt_view_component_map1(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 1);
}
double opt_view_component_map2(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 2);
}
double opt_view_component_map3(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 3);
}
double opt_view_component_map4(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 4);
}
double opt_view_component_map5(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 5);
}
double opt_view_component_map6(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 6);
}
double opt_view_component_map7(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 7);
}
double opt_view_component_map8(OPT_ARGS_NUM)
{
  return ovcm(num, action, val, 8);
}

double opt_view_closed(OPT_ARGS_NUM)
{
#if defined(HAVE_POST)
  GET_VIEWo(0.);
  if(action & GMSH_SET) { opt->closed = (int)val; }
#if defined(HAVE_FLTK)
  if(FlGui::available() && (action & GMSH_GUI) && num >= 0) {
    FlGui::instance()->onelab->openCloseViewButton(num);
  }
#endif
  return opt->closed;
#else
  return 0.;
#endif
}

double opt_print_file_format(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.fileFormat = (int)val;
  return CTX::instance()->print.fileFormat;
}

double opt_print_eps_compress(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsCompress = (int)val;
  return CTX::instance()->print.epsCompress;
}

double opt_print_eps_ps3shading(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsPS3Shading = (int)val;
  return CTX::instance()->print.epsPS3Shading;
}

double opt_print_eps_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsQuality = (int)val;
  return CTX::instance()->print.epsQuality;
}

double opt_print_eps_occlusion_culling(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsOcclusionCulling = (int)val;
  return CTX::instance()->print.epsOcclusionCulling;
}

double opt_print_eps_best_root(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsBestRoot = (int)val;
  return CTX::instance()->print.epsBestRoot;
}

double opt_print_eps_line_width_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsLineWidthFactor = val;
  return CTX::instance()->print.epsLineWidthFactor;
}

double opt_print_eps_point_size_factor(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.epsPointSizeFactor = val;
  return CTX::instance()->print.epsPointSizeFactor;
}

double opt_print_jpeg_quality(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.jpegQuality = (int)val;
  return CTX::instance()->print.jpegQuality;
}

double opt_print_jpeg_smoothing(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.jpegSmoothing = (int)val;
  return CTX::instance()->print.jpegSmoothing;
}

double opt_print_geo_labels(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.geoLabels = (int)val;
  return CTX::instance()->print.geoLabels;
}

double opt_print_geo_only_physicals(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.geoOnlyPhysicals = (int)val;
  return CTX::instance()->print.geoOnlyPhysicals;
}

double opt_print_pos_elementary(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posElementary = (int)val;
  return CTX::instance()->print.posElementary;
}

double opt_print_pos_element(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posElement = (int)val;
  return CTX::instance()->print.posElement;
}

double opt_print_pos_gamma(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posGamma = (int)val;
  return CTX::instance()->print.posGamma;
}

double opt_print_pos_eta(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posEta = (int)val;
  return CTX::instance()->print.posEta;
}

double opt_print_pos_SICN(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posSICN = (int)val;
  return CTX::instance()->print.posSICN;
}

double opt_print_pos_SIGE(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posSIGE = (int)val;
  return CTX::instance()->print.posSIGE;
}

double opt_print_pos_disto(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.posDisto = (int)val;
  return CTX::instance()->print.posDisto;
}

double opt_print_gif_dither(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.gifDither = (int)val;
  return CTX::instance()->print.gifDither;
}

double opt_print_gif_sort(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.gifSort = (int)val;
  return CTX::instance()->print.gifSort;
}

double opt_print_gif_interlace(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.gifInterlace = (int)val;
  return CTX::instance()->print.gifInterlace;
}

double opt_print_gif_transparent(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.gifTransparent = (int)val;
  return CTX::instance()->print.gifTransparent;
}

double opt_print_background(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.background = (int)val;
  return CTX::instance()->print.background;
}

double opt_print_pgf_two_dim(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.pgfTwoDim = (int)val;
  return CTX::instance()->print.pgfTwoDim;
}
double opt_print_pgf_export_axis(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.pgfExportAxis = (int)val;
  return CTX::instance()->print.pgfExportAxis;
}
double opt_print_pgf_horiz_bar(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.pgfHorizBar = (int)val;
  return CTX::instance()->print.pgfHorizBar;
}

double opt_print_text(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.text = (int)val;
  return CTX::instance()->print.text;
}

double opt_print_tex_as_equation(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.texAsEquation = (int)val;
  return CTX::instance()->print.texAsEquation;
}

double opt_print_tex_force_fontsize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.texForceFontSize = (int)val;
  return CTX::instance()->print.texForceFontSize;
}

double opt_print_tex_width_in_mm(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.texWidthInMm = val;
  return CTX::instance()->print.texWidthInMm;
}

double opt_print_composite_windows(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.compositeWindows = (int)val;
  return CTX::instance()->print.compositeWindows;
}

double opt_print_delete_tmp_files(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.deleteTmpFiles = (int)val;
  return CTX::instance()->print.deleteTmpFiles;
}

double opt_print_height(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.height = (int)val;
  return CTX::instance()->print.height;
}

double opt_print_width(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.width = (int)val;
  return CTX::instance()->print.width;
}

double opt_print_parameter(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.parameter = val;
  return CTX::instance()->print.parameter;
}

double opt_print_parameter_first(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.parameterFirst = val;
  return CTX::instance()->print.parameterFirst;
}

double opt_print_parameter_last(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.parameterLast = val;
  return CTX::instance()->print.parameterLast;
}

double opt_print_parameter_steps(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.parameterSteps = val;
  return CTX::instance()->print.parameterSteps;
}

double opt_print_x3d_compatibility(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dCompatibility = (int)val;
  return CTX::instance()->print.x3dCompatibility;
}

double opt_print_x3d_transparency(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dTransparency = val;
  return CTX::instance()->print.x3dTransparency;
}

double opt_print_x3d_remove_inner_borders(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dRemoveInnerBorders = (int)val;
  return CTX::instance()->print.x3dRemoveInnerBorders;
}

double opt_print_x3d_precision(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dPrecision = val;
  return CTX::instance()->print.x3dPrecision;
}

double opt_print_x3d_surfaces(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dSurfaces = (int)val;
  return CTX::instance()->print.x3dSurfaces;
}

double opt_print_x3d_edges(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dEdges = (int)val;
  return CTX::instance()->print.x3dEdges;
}

double opt_print_x3d_vertices(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dVertices = (int)val;
  return CTX::instance()->print.x3dVertices;
}

double opt_print_x3d_volumes(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dVolumes = (int)val;
  return CTX::instance()->print.x3dVolumes;
}

double opt_print_x3d_colorize(OPT_ARGS_NUM)
{
  if(action & GMSH_SET) CTX::instance()->print.x3dColorize = (int)val;
  return CTX::instance()->print.x3dColorize;
}

// Color option routines

#if defined(HAVE_FLTK)

#define CCC(col, but)                                                          \
  if(FlGui::available() && (action & GMSH_GUI)) {                              \
    Fl_Color c =                                                               \
      fl_color_cube(CTX::instance()->unpackRed(col) * FL_NUM_RED / 256,        \
                    CTX::instance()->unpackGreen(col) * FL_NUM_GREEN / 256,    \
                    CTX::instance()->unpackBlue(col) * FL_NUM_BLUE / 256);     \
    (but)->color(c);                                                           \
    (but)->labelcolor(fl_contrast(FL_BLACK, c));                               \
    (but)->redraw();                                                           \
  }

#endif

unsigned int opt_general_color_background(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.bg = val;
#if defined(HAVE_FLTK)
    if(FlGui::available()) FlGui::instance()->options->view.colorbar->redraw();
#endif
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.bg, FlGui::instance()->options->general.color[0]);
#endif
  return CTX::instance()->color.bg;
}

unsigned int opt_general_color_background_gradient(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.bgGrad = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.bgGrad,
      FlGui::instance()->options->general.color[1]);
#endif
  return CTX::instance()->color.bgGrad;
}

unsigned int opt_general_color_foreground(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.fg = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.fg, FlGui::instance()->options->general.color[2]);
#endif
  return CTX::instance()->color.fg;
}

unsigned int opt_general_color_text(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.text = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.text,
      FlGui::instance()->options->general.color[3]);
  drawContext::global()->resetFontTextures();
#endif
  return CTX::instance()->color.text;
}

unsigned int opt_general_color_axes(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.axes = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.axes,
      FlGui::instance()->options->general.color[4]);
  drawContext::global()->resetFontTextures();
#endif
  return CTX::instance()->color.axes;
}

unsigned int opt_general_color_small_axes(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.smallAxes = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.smallAxes,
      FlGui::instance()->options->general.color[5]);
  drawContext::global()->resetFontTextures();
#endif
  return CTX::instance()->color.smallAxes;
}

unsigned int opt_general_color_ambient_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++) CTX::instance()->color.ambientLight[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.ambientLight[0],
      FlGui::instance()->options->general.color[6]);
#endif
  return CTX::instance()->color.ambientLight[0];
}

unsigned int opt_general_color_diffuse_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++) CTX::instance()->color.diffuseLight[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.diffuseLight[0],
      FlGui::instance()->options->general.color[7]);
#endif
  return CTX::instance()->color.diffuseLight[0];
}

unsigned int opt_general_color_specular_light(OPT_ARGS_COL)
{
  if(action & GMSH_SET)
    for(int i = 0; i < 6; i++) CTX::instance()->color.specularLight[i] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.specularLight[0],
      FlGui::instance()->options->general.color[8]);
#endif
  return CTX::instance()->color.specularLight[0];
}

unsigned int opt_geometry_color_points(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.point = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.point,
      FlGui::instance()->options->geo.color[0]);
#endif
  return CTX::instance()->color.geom.point;
}

unsigned int opt_geometry_color_curves(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.curve = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.curve,
      FlGui::instance()->options->geo.color[1]);
#endif
  return CTX::instance()->color.geom.curve;
}

unsigned int opt_geometry_color_surfaces(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    CTX::instance()->color.geom.surface = val;
    GModel::current()->deleteGeometryVertexArrays();
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.surface,
      FlGui::instance()->options->geo.color[2]);
#endif
  return CTX::instance()->color.geom.surface;
}

unsigned int opt_geometry_color_volumes(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.volume = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.volume,
      FlGui::instance()->options->geo.color[3]);
#endif
  return CTX::instance()->color.geom.volume;
}

unsigned int opt_geometry_color_selection(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.selection = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.selection,
      FlGui::instance()->options->geo.color[4]);
#endif
  return CTX::instance()->color.geom.selection;
}

unsigned int opt_geometry_color_highlight0(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.geom.highlight[0] = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.highlight[0],
      FlGui::instance()->options->geo.color[5]);
#endif
  return CTX::instance()->color.geom.highlight[0];
}

unsigned int opt_geometry_color_highlight1(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.geom.highlight[1] = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.highlight[1],
      FlGui::instance()->options->geo.color[6]);
#endif
  return CTX::instance()->color.geom.highlight[1];
}

unsigned int opt_geometry_color_highlight2(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.highlight[2] = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.highlight[2],
      FlGui::instance()->options->geo.color[7]);
#endif
  return CTX::instance()->color.geom.highlight[2];
}

unsigned int opt_geometry_color_tangents(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.tangents = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.tangents,
      FlGui::instance()->options->geo.color[8]);
#endif
  return CTX::instance()->color.geom.tangents;
}

unsigned int opt_geometry_color_normals(OPT_ARGS_COL)
{
  if(action & GMSH_SET) CTX::instance()->color.geom.normals = val;
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.normals,
      FlGui::instance()->options->geo.color[9]);
#endif
  return CTX::instance()->color.geom.normals;
}

unsigned int opt_geometry_color_projection(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.geom.projection = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.geom.projection,
      FlGui::instance()->options->geo.color[10]);
#endif
  return CTX::instance()->color.geom.projection;
}

unsigned int opt_mesh_color_nodes(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.mesh.node = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.node,
      FlGui::instance()->options->mesh.color[0]);
#endif
  return CTX::instance()->color.mesh.node;
}

unsigned int opt_mesh_color_nodes_sup(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.mesh.nodeSup = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.nodeSup,
      FlGui::instance()->options->mesh.color[1]);
#endif
  return CTX::instance()->color.mesh.nodeSup;
}

unsigned int opt_mesh_color_lines(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.line != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->color.mesh.line = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.line,
      FlGui::instance()->options->mesh.color[2]);
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
  CCC(CTX::instance()->color.mesh.triangle,
      FlGui::instance()->options->mesh.color[3]);
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
  CCC(CTX::instance()->color.mesh.quadrangle,
      FlGui::instance()->options->mesh.color[4]);
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
  CCC(CTX::instance()->color.mesh.tetrahedron,
      FlGui::instance()->options->mesh.color[5]);
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
  CCC(CTX::instance()->color.mesh.prism,
      FlGui::instance()->options->mesh.color[7]);
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
  CCC(CTX::instance()->color.mesh.pyramid,
      FlGui::instance()->options->mesh.color[8]);
#endif
  return CTX::instance()->color.mesh.pyramid;
}

unsigned int opt_mesh_color_trihedron(OPT_ARGS_COL)
{
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // element type
    if(CTX::instance()->color.mesh.trihedron != val &&
       CTX::instance()->mesh.colorCarousel == 0)
      CTX::instance()->mesh.changed |= ENT_VOLUME;
    CTX::instance()->color.mesh.trihedron = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.trihedron,
      FlGui::instance()->options->mesh.color[9]);
#endif
  return CTX::instance()->color.mesh.trihedron;
}

unsigned int opt_mesh_color_tangents(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.mesh.tangents = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.tangents,
      FlGui::instance()->options->mesh.color[10]);
#endif
  return CTX::instance()->color.mesh.tangents;
}

unsigned int opt_mesh_color_normals(OPT_ARGS_COL)
{
  if(action & GMSH_SET) { CTX::instance()->color.mesh.normals = val; }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.normals,
      FlGui::instance()->options->mesh.color[11]);
#endif
  return CTX::instance()->color.mesh.normals;
}

unsigned int opt_mesh_color_(int i, OPT_ARGS_COL)
{
  int n = (i < 0 || i >= 20) ? 0 : i;
  if(action & GMSH_SET) {
    // vertex arrays need to be regenerated only when we color by
    // partition
    if(CTX::instance()->color.mesh.carousel[n] != val &&
       CTX::instance()->mesh.colorCarousel == 3)
      CTX::instance()->mesh.changed |= (ENT_CURVE | ENT_SURFACE | ENT_VOLUME);
    CTX::instance()->color.mesh.carousel[n] = val;
  }
#if defined(HAVE_FLTK)
  CCC(CTX::instance()->color.mesh.carousel[n],
      FlGui::instance()->options->mesh.color[12 + n]);
#endif
  return CTX::instance()->color.mesh.carousel[n];
}

unsigned int opt_mesh_color_0(OPT_ARGS_COL)
{
  return opt_mesh_color_(0, num, action, val);
}
unsigned int opt_mesh_color_1(OPT_ARGS_COL)
{
  return opt_mesh_color_(1, num, action, val);
}
unsigned int opt_mesh_color_2(OPT_ARGS_COL)
{
  return opt_mesh_color_(2, num, action, val);
}
unsigned int opt_mesh_color_3(OPT_ARGS_COL)
{
  return opt_mesh_color_(3, num, action, val);
}
unsigned int opt_mesh_color_4(OPT_ARGS_COL)
{
  return opt_mesh_color_(4, num, action, val);
}
unsigned int opt_mesh_color_5(OPT_ARGS_COL)
{
  return opt_mesh_color_(5, num, action, val);
}
unsigned int opt_mesh_color_6(OPT_ARGS_COL)
{
  return opt_mesh_color_(6, num, action, val);
}
unsigned int opt_mesh_color_7(OPT_ARGS_COL)
{
  return opt_mesh_color_(7, num, action, val);
}
unsigned int opt_mesh_color_8(OPT_ARGS_COL)
{
  return opt_mesh_color_(8, num, action, val);
}
unsigned int opt_mesh_color_9(OPT_ARGS_COL)
{
  return opt_mesh_color_(9, num, action, val);
}
unsigned int opt_mesh_color_10(OPT_ARGS_COL)
{
  return opt_mesh_color_(10, num, action, val);
}
unsigned int opt_mesh_color_11(OPT_ARGS_COL)
{
  return opt_mesh_color_(11, num, action, val);
}
unsigned int opt_mesh_color_12(OPT_ARGS_COL)
{
  return opt_mesh_color_(12, num, action, val);
}
unsigned int opt_mesh_color_13(OPT_ARGS_COL)
{
  return opt_mesh_color_(13, num, action, val);
}
unsigned int opt_mesh_color_14(OPT_ARGS_COL)
{
  return opt_mesh_color_(14, num, action, val);
}
unsigned int opt_mesh_color_15(OPT_ARGS_COL)
{
  return opt_mesh_color_(15, num, action, val);
}
unsigned int opt_mesh_color_16(OPT_ARGS_COL)
{
  return opt_mesh_color_(16, num, action, val);
}
unsigned int opt_mesh_color_17(OPT_ARGS_COL)
{
  return opt_mesh_color_(17, num, action, val);
}
unsigned int opt_mesh_color_18(OPT_ARGS_COL)
{
  return opt_mesh_color_(18, num, action, val);
}
unsigned int opt_mesh_color_19(OPT_ARGS_COL)
{
  return opt_mesh_color_(19, num, action, val);
}

unsigned int opt_view_color_points(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.point = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.line = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.triangle = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.quadrangle = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.tetrahedron = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.hexahedron = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.prism = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.pyramid = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.pyramid, FlGui::instance()->options->view.color[7]);
  }
#endif
  return opt->color.pyramid;
#else
  return 0;
#endif
}

unsigned int opt_view_color_trihedra(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.trihedron = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.trihedron, FlGui::instance()->options->view.color[8]);
  }
#endif
  return opt->color.trihedron;
#else
  return 0;
#endif
}

unsigned int opt_view_color_tangents(OPT_ARGS_COL)
{
#if defined(HAVE_POST)
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.tangents = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.tangents, FlGui::instance()->options->view.color[9]);
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
  GET_VIEWo(0);
  if(action & GMSH_SET) {
    opt->color.normals = val;
    if(view) view->setChanged(true);
  }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.normals, FlGui::instance()->options->view.color[10]);
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
  GET_VIEWo(0);
  if(action & GMSH_SET) { opt->color.text2d = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.text2d, FlGui::instance()->options->view.color[11]);
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
  GET_VIEWo(0);
  if(action & GMSH_SET) { opt->color.text3d = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.text3d, FlGui::instance()->options->view.color[12]);
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
  GET_VIEWo(0);
  if(action & GMSH_SET) { opt->color.axes = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.axes, FlGui::instance()->options->view.color[13]);
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
  GET_VIEWo(0);
  if(action & GMSH_SET) { opt->color.background2d = val; }
#if defined(HAVE_FLTK)
  if(_gui_action_valid(action, num)) {
    CCC(opt->color.background2d, FlGui::instance()->options->view.color[14]);
    drawContext::global()->resetFontTextures();
  }
#endif
  return opt->color.background2d;
#else
  return 0;
#endif
}
