// $Id: Options.cpp,v 1.65 2001-11-19 14:24:01 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"

extern Context_T   CTX ;

#ifdef _FLTK
#include "Solvers.h"
#include "GUI.h"
extern GUI        *WID ;
#endif

extern Post_View  *Post_ViewReference;

// ************** General routines ****************************************

void Init_Options(int num){
  char *tmp;

  // Home directory
#if !defined(WIN32) // Some WinNT systems have bad HOME variables...
  if((tmp = getenv("HOME")))      strcpy(CTX.home_dir, tmp);
  else 
#endif
  if((tmp = getenv("TMP")))       strcpy(CTX.home_dir, tmp);
  else if((tmp = getenv("TEMP"))) strcpy(CTX.home_dir, tmp);
  else                            strcpy(CTX.home_dir, "");
  if(strlen(CTX.home_dir)){
#if defined(WIN32) && !defined(__CYGWIN__)
    strcat(CTX.home_dir, "\\");
#else
    strcat(CTX.home_dir, "/");
#endif
  }

  // Reference view storing default options
  Post_ViewReference = (Post_View*)Malloc(sizeof(Post_View)) ;
  Post_ViewReference->CT.size = 255;
  Post_ViewReference->CT.ipar[COLORTABLE_MODE] = COLORTABLE_RGB;
  ColorTable_InitParam(1, &Post_ViewReference->CT, 1, 1);
  ColorTable_Recompute(&Post_ViewReference->CT, 1, 1);

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
  Set_DefaultColorOptions(num, GeneralOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, GeometryOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, MeshOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, SolverOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, PostProcessingOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, ViewOptions_Color, CTX.color_scheme);
  Set_DefaultColorOptions(num, PrintOptions_Color, CTX.color_scheme);

  // The following defaults cannot be set by the user 
  CTX.batch = 0 ;
  CTX.mesh.initial_only = 0 ;
  CTX.output_filename = NULL ;
  CTX.expose = 0 ;
  CTX.lc = 1.0 ;
  CTX.viewport[0] = CTX.viewport[1] = 0 ;
  CTX.min[0] = CTX.min[1] = CTX.min[2] = 0.0 ;
  CTX.max[0] = CTX.max[1] = CTX.max[2] = 1.0 ;
  CTX.range[0] = CTX.range[1] = CTX.range[2] = 1.0 ;
  CTX.vxmin = CTX.vymin = CTX.vxmax = CTX.vymax = 0. ;
  CTX.render_mode = GMSH_RENDER ;
  CTX.pixel_equiv_x = CTX.pixel_equiv_y = 0. ; 
  CTX.geom.vis_type = 0 ;
  CTX.geom.level = ELEMENTARY ;
  CTX.mesh.vis_type = 0 ;
  CTX.mesh.draw = 1 ;  
  CTX.post.draw = 1 ;
  CTX.post.list = NULL ;
  CTX.post.force_num = 0 ;
  CTX.print.gl_fonts = 1;
  CTX.threads_lock = 0 ; //very primitive locking during mesh generation
  CTX.mesh.histogram = 0 ;
  CTX.mesh.oldxtrude = CTX.mesh.oldxtrude_recombine = 0; //old extrusion mesh generator
  CTX.mesh.check_duplicates = 0; //check for duplicate nodes in Read_Mesh
}

void Init_Options_GUI(int num){
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

void Print_OptionCategory(int level, char *cat, FILE *file){
  if(level & GMSH_SESSIONRC) return ;
  if(file){
    fprintf(file, "//\n");
    fprintf(file, "// %s\n", cat);
    fprintf(file, "//\n");
  }
  else{
    Msg(DIRECT, "//");
    Msg(DIRECT, "// %s", cat);
    Msg(DIRECT, "//");
  }
}

void Print_Options(int num, int level, char *filename){
  FILE *file;
  char tmp[256];
  int i ;
  
  if(filename){
    file = fopen(filename,"w");
    if(!file){
      Msg(GERROR, "Unable to open file '%s'", filename);
      return;
    }
  }
  else
    file = NULL ;

  if((level & GMSH_SESSIONRC) && file){
    fprintf(file, "// Gmsh Session File\n");
    fprintf(file, "//\n");
    fprintf(file, "// This file takes session specific info (that is info\n");
    fprintf(file, "// you want to keep between two Gmsh sessions). You are\n");
    fprintf(file, "// not supposed to edit it manually, but of course you\n");
    fprintf(file, "// can do. This file will be entirely rewritten every time\n");
    fprintf(file, "// you quit Gmsh if the option 'General.SaveSession' is\n");
    fprintf(file, "// set. If this file isn't found, defaults are used.\n");
    fprintf(file, "//\n");
  }

  if((level & GMSH_OPTIONSRC) && file){
    fprintf(file, "// Gmsh Option File\n");
    fprintf(file, "//\n");
    fprintf(file, "// This file takes configuration options (preferences) that\n");
    fprintf(file, "// should be loaded each time Gmsh is launched. You can create\n");
    fprintf(file, "// this file by hand, or let Gmsh generate it for you (with\n");
    fprintf(file, "// the 'Options->Save options now' menu button). This file can\n");
    fprintf(file, "// also be automatically regenerated every time you quit\n");
    fprintf(file, "// Gmsh if the option 'General.SaveOptions' is set. If\n");
    fprintf(file, "// this file isn't found, defaults are used.\n");
    fprintf(file, "//\n");
  }

  Print_OptionCategory(level, "General options (strings)", file);
  Print_StringOptions(num, level, GeneralOptions_String, "General.", file);
  Print_OptionCategory(level, "General options (numbers)", file);
  Print_NumberOptions(num, level, GeneralOptions_Number, "General.", file);
  Print_OptionCategory(level, "General options (colors)", file);
  Print_ColorOptions(num, level, GeneralOptions_Color, "General.", file);

  Print_OptionCategory(level, "Geometry options (strings)", file);
  Print_StringOptions(num, level, GeometryOptions_String, "Geometry.", file);
  Print_OptionCategory(level, "Geometry options (numbers)", file);
  Print_NumberOptions(num, level, GeometryOptions_Number, "Geometry.", file);
  Print_OptionCategory(level, "Geometry options (colors)", file);
  Print_ColorOptions(num, level, GeometryOptions_Color, "Geometry.", file);

  Print_OptionCategory(level, "Mesh options (strings)", file);
  Print_StringOptions(num, level, MeshOptions_String, "Mesh.", file);
  Print_OptionCategory(level, "Mesh options (numbers)", file);
  Print_NumberOptions(num, level, MeshOptions_Number, "Mesh.", file);
  Print_OptionCategory(level, "Mesh options (colors)", file);
  Print_ColorOptions(num, level, MeshOptions_Color, "Mesh.", file);

  Print_OptionCategory(level, "Solver options (strings)", file);
  Print_StringOptions(num, level, SolverOptions_String, "Solver.", file);
  Print_OptionCategory(level, "Solver options (numbers)", file);
  Print_NumberOptions(num, level, SolverOptions_Number, "Solver.", file);
  Print_OptionCategory(level, "Solver options (colors)", file);
  Print_ColorOptions(num, level, SolverOptions_Color, "Solver.", file);

  Print_OptionCategory(level, "Post-processing options (strings)", file);
  Print_StringOptions(num, level, PostProcessingOptions_String, "PostProcessing.", file);
  Print_OptionCategory(level, "Post-processing options (numbers)", file);
  Print_NumberOptions(num, level, PostProcessingOptions_Number, "PostProcessing.", file);
  Print_OptionCategory(level, "Post-processing options (colors)", file);
  Print_ColorOptions(num, level, PostProcessingOptions_Color, "PostProcessing.", file);

  if(level & GMSH_FULLRC){
    for(i=0; i<List_Nbr(CTX.post.list) ; i++){
      sprintf(tmp, "View[%d].", i);
      Print_OptionCategory(level, "View options (strings)", file);
      Print_StringOptions(i, level, ViewOptions_String, tmp, file);
      Print_OptionCategory(level, "View options (numbers)", file);
      Print_NumberOptions(i, level, ViewOptions_Number, tmp, file);
      Print_OptionCategory(level, "View options (colors)", file);
      Print_ColorOptions(i, level, ViewOptions_Color, tmp, file);
      strcat(tmp, "ColorTable");
      Print_ColorTable(i, tmp, file);
    }
  }
  else if(level & GMSH_OPTIONSRC){
    Print_OptionCategory(level, "View options (strings)", file);
    Print_StringOptions(num, level, ViewOptions_String, "View.", file);
    Print_OptionCategory(level, "View options (numbers)", file);
    Print_NumberOptions(num, level, ViewOptions_Number, "View.", file);
    Print_OptionCategory(level, "View options (colors)", file);
    Print_ColorOptions(num, level, ViewOptions_Color, "View.", file);
    Print_ColorTable(num, "View.ColorTable", file);
  }

  Print_OptionCategory(level, "Print options (strings)", file);
  Print_StringOptions(num, level, PrintOptions_String, "Print.", file);
  Print_OptionCategory(level, "Print options (numbers)", file);
  Print_NumberOptions(num, level, PrintOptions_Number, "Print.", file);
  Print_OptionCategory(level, "Print options (colors)", file);
  Print_ColorOptions(num, level, PrintOptions_Color, "Print.", file);

  if(filename){
    if((level & GMSH_OPTIONSRC) || (level & GMSH_FULLRC)){
      Msg(INFO, "Options output complete '%s'", filename);
      Msg(STATUS2, "Wrote '%s'", filename);
    }
    fclose(file);
  }
}

// ************** General routines for string options ************************

StringXString * Get_StringOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_String ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_String ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_String ;
  else if(!strcmp(cat,"Solver"))         return SolverOptions_String ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_String ;
  else if(!strcmp(cat,"View"))           return ViewOptions_String ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_String ;
  else                                   return NULL ;
}

void Set_DefaultStringOptions(int num, StringXString s[]){
  int i = 0;
  while(s[i].str){
    s[i].function(num, GMSH_SET, s[i].def) ;
    i++;
  }
}

void Set_StringOptions_GUI(int num, StringXString s[]){
  int i = 0;
  while(s[i].str){
    s[i].function(num, GMSH_GUI, 0) ;
    i++;
  }
}

void * Get_StringOption(char *str, StringXString s[]){
  int i = 0;
  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else
    return (void*)s[i].function;
}

void Print_StringOptions(int num, int level, StringXString s[], char *prefix, FILE *file){
  int i = 0;
  char tmp[1024];
  while(s[i].str){
    if(s[i].level & level){
      sprintf(tmp, "%s%s = \"%s\"; // %s", prefix, 
	      s[i].str, s[i].function(num, GMSH_GET, NULL), s[i].help) ;
      if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, "%s", tmp);
    }
    i++;
  }
}

// ************** General routines for numeric options ************************

StringXNumber * Get_NumberOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_Number ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_Number ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_Number ;
  else if(!strcmp(cat,"Solver"))         return SolverOptions_Number ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_Number ;
  else if(!strcmp(cat,"View"))           return ViewOptions_Number ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_Number ;
  else                                   return NULL ;
}

void Set_DefaultNumberOptions(int num, StringXNumber s[]){
  int i = 0;
  while(s[i].str){
    s[i].function(num, GMSH_SET, s[i].def) ;
    i++;
  }
}

void Set_NumberOptions_GUI(int num, StringXNumber s[]){
  int i = 0;
  while(s[i].str){
    s[i].function(num, GMSH_GUI, 0) ;
    i++ ;
  }
}

void * Get_NumberOption(char *str, StringXNumber s[]){
  int i = 0;

  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else{
    return (void*)s[i].function;
  }
}

void Print_NumberOptions(int num, int level, StringXNumber s[], char *prefix, FILE *file){
  int i = 0;
  char tmp[1024];
  while(s[i].str){
    if(s[i].level & level){
      sprintf(tmp, "%s%s = %.16g; // %s", prefix, 
	      s[i].str, s[i].function(num, GMSH_GET, 0), s[i].help);
      if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
    }
    i++;
  }
}

// ************** General routines for color options ************************

StringXColor * Get_ColorOptionCategory(char * cat){
  if     (!strcmp(cat,"General"))        return GeneralOptions_Color ;
  else if(!strcmp(cat,"Geometry"))       return GeometryOptions_Color ;
  else if(!strcmp(cat,"Mesh"))           return MeshOptions_Color ;
  else if(!strcmp(cat,"Solver"))         return SolverOptions_Color ;
  else if(!strcmp(cat,"PostProcessing")) return PostProcessingOptions_Color ;
  else if(!strcmp(cat,"View"))           return ViewOptions_Color ;
  else if(!strcmp(cat,"Print"))          return PrintOptions_Color ;
  else                                   return NULL ;
}

void Set_DefaultColorOptions(int num, StringXColor s[], int scheme){
  int i = 0;
  switch(scheme){
  case 0 : 
    while(s[i].str){
      s[i].function(num, GMSH_SET, s[i].def1) ; 
      i++;
    }
    break;
  case 1 : 
    while(s[i].str){ 
      s[i].function(num, GMSH_SET, s[i].def2) ;
      i++;
    }
    break;
  case 2 : 
    while(s[i].str){ 
      s[i].function(num, GMSH_SET, s[i].def3) ; 
      i++;
    }
    break;
  }
}

void Set_ColorOptions_GUI(int num, StringXColor s[]){
  int i = 0;
  while(s[i].str){
    s[i].function(num, GMSH_GUI, 0) ;
    i++;
  }
}

void * Get_ColorOption(char *str, StringXColor s[]) {
  int i = 0;
  while ((s[i].str != NULL) && (strcmp(s[i].str, str))) i++ ;
  if(!s[i].str)
    return NULL;
  else
    return (void*)s[i].function;
}

void Print_ColorOptions(int num, int level, StringXColor s[], char *prefix, FILE *file){
  int i = 0;
  char tmp[1024];
  while(s[i].str){
    if(s[i].level & level){
      sprintf(tmp, "%sColor.%s = {%d,%d,%d}; // %s", 
	      prefix, s[i].str,
	      UNPACK_RED  (s[i].function(num, GMSH_GET, 0)),
	      UNPACK_GREEN(s[i].function(num, GMSH_GET, 0)),
	      UNPACK_BLUE (s[i].function(num, GMSH_GET, 0)),
	      s[i].help);
      if(file) fprintf(file, "%s\n", tmp); else Msg(DIRECT, tmp);
    }
    i++;
  }
}

int Get_ColorForString(StringX4Int SX4I[], int alpha, 
		       char * str, int * FlagError) {
  int  i = 0 ;
  while ((SX4I[i].str != NULL) && (strcmp(SX4I[i].str, str)))  i++ ;
  *FlagError = (SX4I[i].str == NULL)? 1 : 0 ;
  if(alpha > 0)
    return PACK_COLOR(SX4I[i].int1,SX4I[i].int2,SX4I[i].int3,alpha) ;
  else
    return PACK_COLOR(SX4I[i].int1,SX4I[i].int2,SX4I[i].int3,SX4I[i].int4) ;
}





// ************** String option routines ****************************

#define GET_VIEW(error_val)						\
  Post_View *v;								\
  if(!CTX.post.list)							\
    v = Post_ViewReference ;						\
  else{									\
    if(!(v = (Post_View*)List_Pointer_Test(CTX.post.list, num))){	\
      Msg(WARNING, "View[%d] does not exist", num) ;			\
      return (error_val) ;						\
    }									\
  }

char * opt_general_display(OPT_ARGS_STR){
  if(action & GMSH_SET) CTX.display = val;
  return CTX.display;
}
char * opt_general_default_filename(OPT_ARGS_STR){
  if(action & GMSH_SET) CTX.default_filename = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_input[0]->value(CTX.default_filename);
#endif
  return CTX.default_filename;
}
char * opt_general_tmp_filename(OPT_ARGS_STR){
  if(action & GMSH_SET) CTX.tmp_filename = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_input[1]->value(CTX.tmp_filename);
#endif
  return CTX.tmp_filename;
}
char * opt_general_error_filename(OPT_ARGS_STR){
  if(action & GMSH_SET) CTX.error_filename = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_input[2]->value(CTX.error_filename);
#endif
  return CTX.error_filename;
}
char * opt_general_session_filename(OPT_ARGS_STR){
  if(action & GMSH_SET){
    CTX.session_filename = val;
    strcpy(CTX.sessionrc_filename, CTX.home_dir);
    strcat(CTX.sessionrc_filename, CTX.session_filename);
  }
  return CTX.session_filename;
}
char * opt_general_options_filename(OPT_ARGS_STR){
  if(action & GMSH_SET){
    CTX.options_filename = val;
    strcpy(CTX.optionsrc_filename, CTX.home_dir);
    strcat(CTX.optionsrc_filename, CTX.options_filename);
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_input[3]->value(CTX.options_filename);
#endif
  return CTX.options_filename;
}
char * opt_general_editor(OPT_ARGS_STR){
  if(action & GMSH_SET) CTX.editor = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_input[4]->value(CTX.editor);
#endif
  return CTX.editor;
}

char * opt_solver_getdp_command(OPT_ARGS_STR){
#ifdef _FLTK
  if(action & GMSH_SET) strcpy(GetDP_Info.command, val);
  if(WID && (action & GMSH_GUI))
    WID->getdp_input[2]->value(GetDP_Info.command);
  return GetDP_Info.command;
#else
  return "getdp";
#endif
}

char * opt_view_name(OPT_ARGS_STR){
  GET_VIEW(NULL) ;
  if(action & GMSH_SET){
    strcpy(v->Name, val);
#ifdef _FLTK
    if(WID && num<NB_BUTT_MAX){
      WID->m_toggle_butt[num]->label(v->Name);
      WID->m_toggle_butt[num]->redraw();
    }
#endif
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_input[0]->value(v->Name);
  }
#endif
  return v->Name;
}
char * opt_view_format(OPT_ARGS_STR){
  GET_VIEW(NULL) ;
  if(action & GMSH_SET){
    strcpy(v->Format, val);
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_input[1]->value(v->Format);
#endif
  return v->Format;
}
char * opt_view_filename(OPT_ARGS_STR){
  GET_VIEW(NULL) ;
  if(action & GMSH_SET)
    strcpy(v->FileName, val);
  return v->FileName;
}
char * opt_view_abscissa_name(OPT_ARGS_STR){
  GET_VIEW(NULL) ;
  if(action & GMSH_SET){
    strcpy(v->AbscissaName, val);
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_input[2]->value(v->AbscissaName);
#endif
  return v->AbscissaName;
}


char * opt_print_eps_font(OPT_ARGS_STR){
  if(action & GMSH_SET) CTX.print.eps_font = val;
  return CTX.print.eps_font;
}


// ************** Numeric option routines ****************************


double opt_general_initial_context(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.initial_context = (int)val;
  return CTX.initial_context;
}
double opt_general_fontsize(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.fontsize = (int)val;
  return CTX.fontsize;
}
double opt_general_graphics_fontsize(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.gl_fontsize = (int)val;
  return CTX.gl_fontsize;
}
double opt_general_viewport2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.viewport[2] = (int)val;
  return CTX.viewport[2];
}
double opt_general_viewport3(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.viewport[3] = (int)val;
  return CTX.viewport[3];
}
double opt_general_graphics_position0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.gl_position[0] = (int)val;
  return CTX.gl_position[0];
}
double opt_general_graphics_position1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.gl_position[1] = (int)val;
  return CTX.gl_position[1];
}
double opt_general_menu_position0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.position[0] = (int)val;
  return CTX.position[0];
}
double opt_general_menu_position1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.position[1] = (int)val;
  return CTX.position[1];
}
double opt_general_message_position0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.msg_position[0] = (int)val;
  return CTX.msg_position[0];
}
double opt_general_message_position1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.msg_position[1] = (int)val;
  return CTX.msg_position[1];
}
double opt_general_message_size0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.msg_size[0] = (int)val;
  return CTX.msg_size[0];
}
double opt_general_message_size1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.msg_size[1] = (int)val;
  return CTX.msg_size[1];
}
double opt_general_center_windows(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.center_windows = (int)val;
  return CTX.center_windows;
}
double opt_general_session_save(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.session_save = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[8]->value(CTX.session_save);
#endif
  return CTX.session_save;
}
double opt_general_options_save(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.options_save = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[9]->value(CTX.options_save);
#endif
  return CTX.options_save;
}
double opt_general_rotation0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.r[0] = val;
  return CTX.r[0];
}
double opt_general_rotation1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.r[1] = val;
  return CTX.r[1];
}
double opt_general_rotation2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.r[2] = val;
  return CTX.r[3];
}
double opt_general_quaternion0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.quaternion[0] = val;
  return CTX.quaternion[0];
}
double opt_general_quaternion1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.quaternion[1] = val;
  return CTX.quaternion[1];
}
double opt_general_quaternion2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.quaternion[2] = val;
  return CTX.quaternion[2];
}
double opt_general_quaternion3(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.quaternion[3] = val;
  return CTX.quaternion[3];
}
double opt_general_translation0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.t[0] = val;
  return CTX.t[0];
}
double opt_general_translation1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.t[1] = val;
  return CTX.t[1];
}
double opt_general_translation2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.t[2] = val;
  return CTX.t[2];
}
double opt_general_scale0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.s[0] = val;
  return CTX.s[0];
}
double opt_general_scale1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.s[1] = val;
  return CTX.s[1];
}
double opt_general_scale2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.s[2] = val;
  return CTX.s[2];
}
double opt_general_point_size(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.point_size = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[6]->value(CTX.point_size);
#endif
  return CTX.point_size;
}
double opt_general_line_width(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.line_width = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[7]->value(CTX.line_width);
#endif
  return CTX.line_width;
}
double opt_general_shine(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.shine = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[1]->value(CTX.shine);
#endif
  return CTX.shine;
}
double opt_general_verbosity(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.verbosity = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[5]->value(CTX.verbosity);
#endif
  return CTX.verbosity;
}
double opt_general_terminal(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.terminal = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[7]->value(CTX.terminal);
#endif
  return CTX.terminal;
}
double opt_general_orthographic(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.ortho = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI)){
    WID->gen_butt[10]->value(CTX.ortho);
    WID->gen_butt[11]->value(!CTX.ortho);
  }
#endif
  return CTX.ortho;
}
double opt_general_fast_redraw(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.fast = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[2]->value(CTX.fast);
#endif
  return CTX.fast;
}
double opt_general_axes(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.axes = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[0]->value(CTX.axes);
#endif
  return CTX.axes;
}
double opt_general_small_axes(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.small_axes = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[1]->value(CTX.small_axes);
#endif
  return CTX.small_axes;
}
double opt_general_small_axes_position0(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.small_axes_pos[0] = (int)val;
  return CTX.small_axes_pos[0];
}
double opt_general_small_axes_position1(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.small_axes_pos[1] = (int)val;
  return CTX.small_axes_pos[1];
}
double opt_general_display_lists(OPT_ARGS_NUM){
  int i;
  if(action & GMSH_SET){
    CTX.display_lists = (int)val;
    if(CTX.display_lists)
      for(i=0 ; i<List_Nbr(CTX.post.list) ; i++)
	((Post_View*)List_Pointer_Test(CTX.post.list, i))->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[4]->value(CTX.display_lists);
#endif
  return CTX.display_lists;
}
double opt_general_double_buffer(OPT_ARGS_NUM){
  if(action & GMSH_SET){
    CTX.db = (int)val;
#ifdef _FLTK
    if(WID){
      if(CTX.db){
	Msg(INFO, "Setting OpenGL visual to double buffered");
	WID->g_opengl_window->mode(FL_RGB | FL_DEPTH | FL_DOUBLE);
      }
      else{
	Msg(INFO, "Setting OpenGL visual to single buffered");
	WID->g_opengl_window->mode(FL_RGB | FL_DEPTH | FL_SINGLE);
      }
    }
#endif
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[3]->value(CTX.db);
#endif
  return CTX.db;
}
double opt_general_alpha_blending(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.alpha = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[5]->value(CTX.alpha);
#endif
  return CTX.alpha;
}
double opt_general_color_scheme(OPT_ARGS_NUM){
  if(action & GMSH_SET){
    CTX.color_scheme = (int)val;
    if(CTX.color_scheme>2) CTX.color_scheme=0;
    Set_DefaultColorOptions(0, GeneralOptions_Color, CTX.color_scheme);
    Set_ColorOptions_GUI(0, GeneralOptions_Color);
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[0]->value(CTX.color_scheme);
#endif
  return CTX.color_scheme;
}
double opt_general_trackball(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.useTrackball = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[6]->value(CTX.useTrackball);
#endif
  return CTX.useTrackball;
}
double opt_general_zoom_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.zoom_factor = val;
  return CTX.zoom_factor;
}
double opt_general_default_plugins(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.default_plugins = (int)val;
  return CTX.default_plugins;
}
double opt_general_clip0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip[0] = (int)val;
  return CTX.clip[0];
}
double opt_general_clip0a(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[0][0] = val;
  return CTX.clip_plane[0][0];
}
double opt_general_clip0b(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[0][1] = val;
  return CTX.clip_plane[0][1];
}
double opt_general_clip0c(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[0][2] = val;
  return CTX.clip_plane[0][2];
}
double opt_general_clip0d(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[0][3] = val;
  return CTX.clip_plane[0][3];
}
double opt_general_clip1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip[1] = (int)val;
  return CTX.clip[1];
}
double opt_general_clip1a(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[1][0] = val;
  return CTX.clip_plane[1][0];
}
double opt_general_clip1b(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[1][1] = val;
  return CTX.clip_plane[1][1];
}
double opt_general_clip1c(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[1][2] = val;
  return CTX.clip_plane[1][2];
}
double opt_general_clip1d(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[1][3] = val;
  return CTX.clip_plane[1][3];
}
double opt_general_clip2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip[2] = (int)val;
  return CTX.clip[2];
}
double opt_general_clip2a(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[2][0] = val;
  return CTX.clip_plane[2][0];
}
double opt_general_clip2b(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[2][1] = val;
  return CTX.clip_plane[2][1];
}
double opt_general_clip2c(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[2][2] = val;
  return CTX.clip_plane[2][2];
}
double opt_general_clip2d(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[2][3] = val;
  return CTX.clip_plane[2][3];
}
double opt_general_clip3(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip[3] = (int)val;
  return CTX.clip[3];
}
double opt_general_clip3a(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[3][0] = val;
  return CTX.clip_plane[3][0];
}
double opt_general_clip3b(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[3][1] = val;
  return CTX.clip_plane[3][1];
}
double opt_general_clip3c(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[3][2] = val;
  return CTX.clip_plane[3][2];
}
double opt_general_clip3d(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[3][3] = val;
  return CTX.clip_plane[3][3];
}
double opt_general_clip4(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip[4] = (int)val;
  return CTX.clip[4];
}
double opt_general_clip4a(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[4][0] = val;
  return CTX.clip_plane[4][0];
}
double opt_general_clip4b(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[4][1] = val;
  return CTX.clip_plane[4][1];
}
double opt_general_clip4c(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[4][2] = val;
  return CTX.clip_plane[4][2];
}
double opt_general_clip4d(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[4][3] = val;
  return CTX.clip_plane[4][3];
}
double opt_general_clip5(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip[5] = (int)val;
  return CTX.clip[5];
}
double opt_general_clip5a(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[5][0] = val;
  return CTX.clip_plane[5][0];
}
double opt_general_clip5b(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[5][1] = val;
  return CTX.clip_plane[5][1];
}
double opt_general_clip5c(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[5][2] = val;
  return CTX.clip_plane[5][2];
}
double opt_general_clip5d(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.clip_plane[5][3] = val;
  return CTX.clip_plane[5][3];
}
double opt_general_moving_light(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.moving_light = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_butt[12]->value(CTX.moving_light);
#endif
  return CTX.moving_light;
}
double opt_general_light0(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light[0] = (int)val;
  return CTX.light[0];
}
double opt_general_light00(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[0][0] = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[2]->value(CTX.light_position[0][0]);
#endif
  return CTX.light_position[0][0];
}
double opt_general_light01(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[0][1] = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[3]->value(CTX.light_position[0][1]);
#endif
  return CTX.light_position[0][1];
}
double opt_general_light02(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[0][2] = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->gen_value[4]->value(CTX.light_position[0][2]);
#endif
  return CTX.light_position[0][2];
}
double opt_general_light1(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light[1] = (int)val;
  return CTX.light[1];
}
double opt_general_light10(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[1][0] = val;
  return CTX.light_position[1][0];
}
double opt_general_light11(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[1][1] = val;
  return CTX.light_position[1][1];
}
double opt_general_light12(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[1][2] = val;
  return CTX.light_position[1][2];
}
double opt_general_light2(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light[2] = (int)val;
  return CTX.light[2];
}
double opt_general_light20(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[2][0] = val;
  return CTX.light_position[2][0];
}
double opt_general_light21(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[2][1] = val;
  return CTX.light_position[2][1];
}
double opt_general_light22(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[2][2] = val;
  return CTX.light_position[2][2];
}
double opt_general_light3(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light[3] = (int)val;
  return CTX.light[3];
}
double opt_general_light30(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[3][0] = val;
  return CTX.light_position[3][0];
}
double opt_general_light31(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[3][1] = val;
  return CTX.light_position[3][1];
}
double opt_general_light32(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[3][2] = val;
  return CTX.light_position[3][2];
}
double opt_general_light4(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light[4] = (int)val;
  return CTX.light[4];
}
double opt_general_light40(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[4][0] = val;
  return CTX.light_position[4][0];
}
double opt_general_light41(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[4][1] = val;
  return CTX.light_position[4][1];
}
double opt_general_light42(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[4][2] = val;
  return CTX.light_position[4][2];
}
double opt_general_light5(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light[5] = (int)val;
  return CTX.light[5];
}
double opt_general_light50(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[5][0] = val;
  return CTX.light_position[5][0];
}
double opt_general_light51(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[5][1] = val;
  return CTX.light_position[5][1];
}
double opt_general_light52(OPT_ARGS_NUM){
  if(action & GMSH_SET) CTX.light_position[5][2] = val;
  return CTX.light_position[5][2];
}



double opt_geometry_auto_coherence(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.auto_coherence = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[8]->value(CTX.geom.auto_coherence);
#endif
  return CTX.geom.auto_coherence;
}
double opt_geometry_normals(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.normals = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_value[0]->value(CTX.geom.normals);
#endif
  return CTX.geom.normals;
}
double opt_geometry_tangents(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.tangents = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_value[1]->value(CTX.geom.tangents);
#endif
  return CTX.geom.tangents;
}
double opt_geometry_points(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.points = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[0]->value(CTX.geom.points);
#endif
  return CTX.geom.points;
}
double opt_geometry_lines(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.lines = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[1]->value(CTX.geom.lines);
#endif
  return CTX.geom.lines;
}
double opt_geometry_surfaces(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.surfaces = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[2]->value(CTX.geom.surfaces);
#endif
  return CTX.geom.surfaces;
}
double opt_geometry_volumes(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.volumes = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[3]->value(CTX.geom.volumes);
#endif
  return CTX.geom.volumes;
}
double opt_geometry_points_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.points_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[4]->value(CTX.geom.points_num);
#endif
  return CTX.geom.points_num;
}
double opt_geometry_lines_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.lines_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[5]->value(CTX.geom.lines_num);
#endif
  return CTX.geom.lines_num;
}
double opt_geometry_surfaces_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.surfaces_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[6]->value(CTX.geom.surfaces_num);
#endif
  return CTX.geom.surfaces_num;
}
double opt_geometry_volumes_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.volumes_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_butt[7]->value(CTX.geom.volumes_num);
#endif
  return CTX.geom.volumes_num;
}
double opt_geometry_point_size(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.point_size = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_value[3]->value(CTX.geom.point_size);
#endif
  return CTX.geom.point_size;
}
double opt_geometry_point_sel_size(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.point_sel_size = val;
  return CTX.geom.point_sel_size;
}
double opt_geometry_line_width(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.line_width = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_value[4]->value(CTX.geom.line_width);
#endif
  return CTX.geom.line_width;
}
double opt_geometry_line_sel_width(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.line_sel_width = val;
  return CTX.geom.line_sel_width;
}
double opt_geometry_aspect(OPT_ARGS_NUM){
  if(action & GMSH_SET){ 
    switch((int)val){
    case 1  : CTX.geom.hidden = 1; CTX.geom.shade = 0; break ;
    case 2  : CTX.geom.hidden = 1; CTX.geom.shade = 1; break ;
    default : CTX.geom.hidden = CTX.geom.shade = 0; break ;
    }
  }
  if(CTX.geom.hidden && !CTX.geom.shade) return 1;
  else if(CTX.geom.hidden && CTX.geom.shade) return 2;
  else return 0;
}
double opt_geometry_highlight(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.highlight = (int)val;
  return CTX.geom.highlight;
}
double opt_geometry_old_circle(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.old_circle = (int)val;
  return CTX.geom.old_circle;
}
double opt_geometry_old_newreg(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.old_newreg = (int)val;
  return CTX.geom.old_newreg;
}
double opt_geometry_circle_points(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.circle_points = (int)val;
  return CTX.geom.circle_points;
}
double opt_geometry_extrude_spline_points(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.extrude_spline_points = (int)val;
  return CTX.geom.extrude_spline_points;
}
double opt_geometry_scaling_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.geom.scaling_factor = (int)val;
  return CTX.geom.scaling_factor;
}
double opt_geometry_color_scheme(OPT_ARGS_NUM){
  if(action & GMSH_SET){
    CTX.geom.color_scheme = (int)val;
    if(CTX.geom.color_scheme>2) CTX.geom.color_scheme=0;
    Set_DefaultColorOptions(0, GeometryOptions_Color, CTX.geom.color_scheme);
    Set_ColorOptions_GUI(0, GeometryOptions_Color);
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->geo_value[2]->value(CTX.geom.color_scheme);
#endif
  return CTX.geom.color_scheme;
}


double opt_mesh_quality(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.quality = val;
  return CTX.mesh.quality;
}
double opt_mesh_normals(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.normals = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[8]->value(CTX.mesh.normals);
#endif
  return CTX.mesh.normals;
}
double opt_mesh_tangents(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.tangents = val;
  return CTX.mesh.tangents;
}
double opt_mesh_explode(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.explode = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[9]->value(CTX.mesh.explode);
#endif
  return CTX.mesh.explode;
}
double opt_mesh_scaling_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.scaling_factor = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[1]->value(CTX.mesh.scaling_factor);
#endif
  return CTX.mesh.scaling_factor;
}
double opt_mesh_lc_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.lc_factor = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[2]->value(CTX.mesh.lc_factor);
#endif
  return CTX.mesh.lc_factor;
}
double opt_mesh_rand_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.rand_factor = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[3]->value(CTX.mesh.rand_factor);
#endif
  return CTX.mesh.rand_factor;
}
double opt_mesh_gamma_inf(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.gamma_inf = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[4]->value(CTX.mesh.gamma_inf);
#endif
  return CTX.mesh.gamma_inf;
}
double opt_mesh_gamma_sup(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.gamma_sup = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[5]->value(CTX.mesh.gamma_sup);
#endif
  return CTX.mesh.gamma_sup;
}
double opt_mesh_radius_inf(OPT_ARGS_NUM){
  if(action & GMSH_SET)
    CTX.mesh.radius_inf = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[6]->value(CTX.mesh.radius_inf);
#endif
  return CTX.mesh.radius_inf;
}
double opt_mesh_radius_sup(OPT_ARGS_NUM){
  if(action & GMSH_SET)
    CTX.mesh.radius_sup = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[7]->value(CTX.mesh.radius_sup);
#endif
  return CTX.mesh.radius_sup;
}
double opt_mesh_points(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.points = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[6]->value(CTX.mesh.points);
#endif
  return CTX.mesh.points;
}
double opt_mesh_lines(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.lines = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[7]->value(CTX.mesh.lines);
#endif
  return CTX.mesh.lines;
}
double opt_mesh_surfaces(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.surfaces = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[8]->value(CTX.mesh.surfaces);
#endif
  return CTX.mesh.surfaces;
}
double opt_mesh_volumes(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.volumes = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[9]->value(CTX.mesh.volumes);
#endif
  return CTX.mesh.volumes;
}
double opt_mesh_points_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.points_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[10]->value(CTX.mesh.points_num);
#endif
  return CTX.mesh.points_num;
}
double opt_mesh_lines_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.lines_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[11]->value(CTX.mesh.lines_num);
#endif
  return CTX.mesh.lines_num;
}
double opt_mesh_surfaces_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.surfaces_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[12]->value(CTX.mesh.surfaces_num);
#endif
  return CTX.mesh.surfaces_num;
}
double opt_mesh_volumes_num(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.volumes_num = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[13]->value(CTX.mesh.volumes_num);
#endif
  return CTX.mesh.volumes_num;
}
double opt_mesh_point_size(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.point_size = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[10]->value(CTX.mesh.point_size);
#endif
  return CTX.mesh.point_size;
}
double opt_mesh_line_width(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.line_width = val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[11]->value(CTX.mesh.line_width);
#endif
  return CTX.mesh.line_width;
}
double opt_mesh_aspect(OPT_ARGS_NUM){
  if(action & GMSH_SET){ 
    switch((int)val){
    case 1  : CTX.mesh.hidden = 1; CTX.mesh.shade = 0; break ;
    case 2  : CTX.mesh.hidden = 1; CTX.mesh.shade = 1; break ;
    default : CTX.mesh.hidden = CTX.mesh.shade = 0; break ;
    }
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI)){
    WID->mesh_butt[14]->value(!CTX.mesh.hidden && !CTX.mesh.shade);
    WID->mesh_butt[15]->value(CTX.mesh.hidden && !CTX.mesh.shade);
    WID->mesh_butt[16]->value(CTX.mesh.hidden && CTX.mesh.shade);
  }
#endif
  if(CTX.mesh.hidden && !CTX.mesh.shade) return 1;
  else if(CTX.mesh.hidden && CTX.mesh.shade) return 2;
  else return 0;
}
double opt_mesh_format(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.format = (int)val;
  return CTX.mesh.format;
}
double opt_mesh_nb_smoothing(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.nb_smoothing = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[0]->value(CTX.mesh.nb_smoothing);
#endif
  return CTX.mesh.nb_smoothing;
}
double opt_mesh_algo(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.algo = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI)){
    WID->mesh_butt[0]->value(CTX.mesh.algo==DELAUNAY_ISO);
    WID->mesh_butt[1]->value(CTX.mesh.algo==DELAUNAY_SHEWCHUK);
    WID->mesh_butt[2]->value(CTX.mesh.algo==DELAUNAY_ANISO);
  }
#endif
  return CTX.mesh.algo;
}
double opt_mesh_point_insertion(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.point_insertion = (int)val;
  return CTX.mesh.point_insertion;
}
double opt_mesh_speed_max(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.speed_max = (int)val;
  return CTX.mesh.speed_max;
}
double opt_mesh_min_circ_points(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.min_circ_points = (int)val;
  return CTX.mesh.min_circ_points;
}
double opt_mesh_constrained_bgmesh(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.constrained_bgmesh = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[5]->value(CTX.mesh.constrained_bgmesh);
#endif
  return CTX.mesh.constrained_bgmesh;
}
double opt_mesh_degree(OPT_ARGS_NUM){
  if(action & GMSH_SET)
    CTX.mesh.degree = 1; //(int)val;  INTERDIT POUR LE MOMENT !!!
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[3]->value(CTX.mesh.degree==2);
#endif
  return CTX.mesh.degree;
}
double opt_mesh_dual(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.dual = (int)val;
  return CTX.mesh.dual;
}
double opt_mesh_interactive(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.interactive = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[4]->value(CTX.mesh.interactive);
#endif
  return CTX.mesh.interactive;
}
double opt_mesh_use_cut_plane(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.use_cut_plane = (int)val;
  return CTX.mesh.use_cut_plane;
}
double opt_mesh_cut_planea(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.cut_planea = val;
  return CTX.mesh.cut_planea;
}
double opt_mesh_cut_planeb(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.cut_planeb = val;
  return CTX.mesh.cut_planeb;
}
double opt_mesh_cut_planec(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.cut_planec = val;
  return CTX.mesh.cut_planec;
}
double opt_mesh_cut_planed(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.cut_planed = val;
  return CTX.mesh.cut_planed;
}
double opt_mesh_allow_degenerated_extrude(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.allow_degenerated_extrude = (int)val;
  return CTX.mesh.allow_degenerated_extrude;
}
double opt_mesh_save_all(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.mesh.save_all = (int)val;
  return CTX.mesh.save_all;
}
double opt_mesh_color_scheme(OPT_ARGS_NUM){
  if(action & GMSH_SET){
    CTX.mesh.color_scheme = (int)val;
    if(CTX.mesh.color_scheme>2) CTX.mesh.color_scheme=0;
    Set_DefaultColorOptions(0, MeshOptions_Color, CTX.mesh.color_scheme);
    Set_ColorOptions_GUI(0, MeshOptions_Color);
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_value[12]->value(CTX.mesh.color_scheme);
#endif
  return CTX.mesh.color_scheme;
}
double opt_mesh_color_carousel(OPT_ARGS_NUM){
  if(action & GMSH_SET)
    CTX.mesh.color_carousel = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->mesh_butt[17]->value(CTX.mesh.color_carousel);
#endif
  return CTX.mesh.color_carousel;
}
double opt_mesh_nb_nodes(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[6]?s[6]:(s[5]?s[5]:s[4]);
}
double opt_mesh_nb_triangles(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[7]-s[8];
}
double opt_mesh_nb_quadrangles(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[8];
}
double opt_mesh_nb_tetrahedra(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[9];
}
double opt_mesh_nb_hexahedra(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[10];
}
double opt_mesh_nb_prisms(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[11];
}
double opt_mesh_nb_pyramids(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[12];
}
double opt_mesh_cpu_time(OPT_ARGS_NUM){
  double  s[50];
  GetStatistics(s);
  return s[13]+s[14]+s[15];
}



double opt_solver_getdp_popupmessages(OPT_ARGS_NUM){
#ifdef _FLTK
  if(action & GMSH_SET)
    GetDP_Info.popupmessages = (int)val;
  if(WID && (action & GMSH_GUI))
    WID->getdp_butt[0]->value(GetDP_Info.popupmessages);
  return GetDP_Info.popupmessages;
#else
  return 1.;
#endif
}
double opt_solver_getdp_mergeviews(OPT_ARGS_NUM){
#ifdef _FLTK
  if(action & GMSH_SET)
    GetDP_Info.mergeviews = (int)val;
  if(WID && (action & GMSH_GUI))
    WID->getdp_butt[1]->value(GetDP_Info.mergeviews);
  return GetDP_Info.mergeviews;
#else
  return 1.;
#endif
}


double opt_post_scales(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.post.scales = (int)val;
  return CTX.post.scales;
}
double opt_post_link(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.post.link = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI)){
    WID->post_butt[0]->value(CTX.post.link==0);
    WID->post_butt[1]->value(CTX.post.link==1);
    WID->post_butt[2]->value(CTX.post.link==2);
    WID->post_butt[3]->value(CTX.post.link==3);
    WID->post_butt[4]->value(CTX.post.link==4);
  }
#endif
  return CTX.post.link;
}
double opt_post_smooth(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.post.smooth = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->post_butt[3]->value(CTX.post.smooth);
#endif
  return CTX.post.smooth;
}
double opt_post_anim_delay(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.post.anim_delay = (val>=0.)? val : 0. ;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI))
    WID->post_value[0]->value(CTX.post.anim_delay);
#endif
  return CTX.post.anim_delay;
}
double opt_post_nb_views(OPT_ARGS_NUM){
  return List_Nbr(CTX.post.list);
}



double opt_view_nb_timestep(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET) 
    v->NbTimeStep = (int)val;
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[50]->maximum(v->NbTimeStep-1);
  if(WID && (action & GMSH_GUI) && v->NbTimeStep > 1)
    WID->g_status_butt[5]->activate();
#endif
  return v->NbTimeStep;
}
double opt_view_timestep(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->TimeStep = (int)val;
    if(v->TimeStep > v->NbTimeStep-1 || v->TimeStep < 0)
      v->TimeStep = 0 ;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[50]->value(v->TimeStep);
#endif
  return v->TimeStep;
}
double opt_view_min(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){ 
    v->Min = val;
    v->Changed = 1;
  }
  return v->Min;
}
double opt_view_max(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Max = val;
    v->Changed = 1;
  }
  return v->Max;
}
double opt_view_custom_min(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->CustomMin = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_value[31]->value(v->CustomMin);
  }
#endif
  return v->CustomMin;
}
double opt_view_custom_max(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->CustomMax = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[32]->value(v->CustomMax);
#endif
  return v->CustomMax;
}
double opt_view_offset0(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Offset[0] = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[40]->value(v->Offset[0]);
#endif
  return v->Offset[0];
}
double opt_view_offset1(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Offset[1] = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[41]->value(v->Offset[1]);
#endif
  return v->Offset[1];
}
double opt_view_offset2(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Offset[2] = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[42]->value(v->Offset[2]);
#endif
  return v->Offset[2];
}
double opt_view_raise0(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Raise[0] = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[43]->value(v->Raise[0]);
#endif
  return v->Raise[0];
}
double opt_view_raise1(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Raise[1] = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[44]->value(v->Raise[1]);
#endif
  return v->Raise[1];
}
double opt_view_raise2(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Raise[2] = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[45]->value(v->Raise[2]);
#endif
  return v->Raise[2];
}
double opt_view_arrow_scale(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ArrowScale = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[60]->value(v->ArrowScale);
#endif
  return v->ArrowScale;
}
double opt_view_explode(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Explode = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[12]->value(v->Explode);
#endif
  return v->Explode;
}
double opt_view_visible(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Visible = (int)val;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && num<NB_BUTT_MAX)
    WID->m_toggle_butt[num]->value(v->Visible);
#endif
  Msg(DEBUG1, "View %d", v->Num);
  Msg(DEBUG2, "  -> Name '%s'", v->Name);
  Msg(DEBUG2, "  -> FileName '%s'", v->FileName);
  Msg(DEBUG2, "  -> DuplicateOf %d", v->DuplicateOf);
  Msg(DEBUG3, "  -> Links %d", v->Links);
  return v->Visible;
}
double opt_view_intervals_type(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->IntervalsType = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[30]->value(v->IntervalsType==DRAW_POST_ISO);
    WID->view_butt[31]->value(v->IntervalsType==DRAW_POST_DISCRETE);
    WID->view_butt[32]->value(v->IntervalsType==DRAW_POST_CONTINUOUS);
    WID->view_butt[33]->value(v->IntervalsType==DRAW_POST_NUMERIC);
  }
#endif
  return v->IntervalsType;
}

double opt_view_saturate_values(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->SaturateValues = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[38]->value(v->SaturateValues);
  }
#endif
  return v->SaturateValues;
}

double opt_view_type(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Type = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[1]->value(v->Type==DRAW_POST_3D);
    WID->view_butt[2]->value(v->Type==DRAW_POST_2D_SPACE);
    WID->view_butt[3]->value(v->Type==DRAW_POST_2D_TIME);
  }
#endif
  return v->Type;
}

double opt_view_position0(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Position[0] = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[20]->value(v->Position[0]);
#endif
  return v->Position[0];
}

double opt_view_position1(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Position[1] = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[21]->value(v->Position[1]);
#endif
  return v->Position[1];
}

double opt_view_auto_position(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->AutoPosition = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[7]->value(v->AutoPosition);
  }
#endif
  return v->AutoPosition;
}

double opt_view_size0(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Size[0] = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[22]->value(v->Size[0]);
#endif
  return v->Size[0];
}

double opt_view_size1(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Size[1] = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[23]->value(v->Size[1]);
#endif
  return v->Size[1];
}

double opt_view_grid(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Grid = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_value[26]->value(v->Grid);
  }
#endif
  return v->Grid;
}

double opt_view_nb_abscissa(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->NbAbscissa = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_value[25]->value(v->NbAbscissa);
  }
#endif
  return v->NbAbscissa;
}

double opt_view_nb_iso(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->NbIso = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[30]->value(v->NbIso);
#endif
  return v->NbIso;
}
double opt_view_boundary(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Boundary = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_value[11]->value(v->Boundary);
  }
#endif
  return v->Boundary;
}
double opt_view_light(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->Light = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[11]->value(v->Light);
#endif
  return v->Light;
}
double opt_view_smooth_normals(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->SmoothNormals = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[12]->value(v->SmoothNormals);
#endif
  return v->SmoothNormals;
}

double opt_view_angle_smooth_normals(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->AngleSmoothNormals = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[10]->value(v->AngleSmoothNormals);
#endif
  return v->AngleSmoothNormals;
}
double opt_view_show_element(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ShowElement = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[10]->value(v->ShowElement);
#endif
  return v->ShowElement;
}
double opt_view_show_time(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ShowTime = (int)val;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[50]->value(v->ShowTime);
#endif
  return v->ShowTime;
}
double opt_view_show_scale(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ShowScale = (int)val;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[4]->value(v->ShowScale);
#endif
  return v->ShowScale;
}
double opt_view_draw_strings(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawStrings = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[5]->value(v->DrawStrings);
#endif
  return v->DrawStrings;
}
double opt_view_draw_points(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawPoints = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[13]->value(v->DrawPoints);
#endif
  return v->DrawPoints;
}
double opt_view_draw_lines(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawLines = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[14]->value(v->DrawLines);
#endif
  return v->DrawLines;
}
double opt_view_draw_triangles(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawTriangles = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[15]->value(v->DrawTriangles);
#endif
  return v->DrawTriangles;
}
double opt_view_draw_tetrahedra(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawTetrahedra = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[16]->value(v->DrawTetrahedra);
#endif
  return v->DrawTetrahedra;
}
double opt_view_draw_scalars(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawScalars = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[17]->value(v->DrawScalars);
#endif
  return v->DrawScalars;
}
double opt_view_draw_vectors(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawVectors = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[18]->value(v->DrawVectors);
#endif
  return v->DrawVectors;
}
double opt_view_draw_tensors(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->DrawTensors = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[19]->value(v->DrawTensors);
#endif
  return v->DrawTensors;
}
double opt_view_transparent_scale(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->TransparentScale = (int)val;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[6]->value(v->TransparentScale);
#endif
  return v->TransparentScale;
}
double opt_view_scale_type(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ScaleType = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[35]->value(v->ScaleType==DRAW_POST_LINEAR);
    WID->view_butt[36]->value(v->ScaleType==DRAW_POST_LOGARITHMIC);
    WID->view_butt[37]->value(v->ScaleType==DRAW_POST_DOUBLELOGARITHMIC);
  }
#endif
  return v->ScaleType;
}
double opt_view_range_type(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->RangeType = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_butt[34]->value(v->RangeType==DRAW_POST_CUSTOM);
#endif
  return v->RangeType;
}
double opt_view_arrow_type(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ArrowType = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[60]->value(v->ArrowType==DRAW_POST_SEGMENT);
    WID->view_butt[61]->value(v->ArrowType==DRAW_POST_ARROW);
    WID->view_butt[62]->value(v->ArrowType==DRAW_POST_CONE);
    WID->view_butt[63]->value(v->ArrowType==DRAW_POST_DISPLACEMENT);
  }
#endif
  return v->ArrowType;
}
double opt_view_arrow_location(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->ArrowLocation = (int)val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number)){
    WID->view_butt[64]->value(v->ArrowLocation==DRAW_POST_LOCATE_COG);
    WID->view_butt[65]->value(v->ArrowLocation==DRAW_POST_LOCATE_VERTEX);
  }
#endif
  return v->ArrowLocation;
}
double opt_view_point_size(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->PointSize = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[61]->value(v->PointSize);
#endif
  return v->PointSize;
}
double opt_view_line_width(OPT_ARGS_NUM){
  GET_VIEW(0.) ;
  if(action & GMSH_SET){
    v->LineWidth = val;
    v->Changed = 1;
  }
#ifdef _FLTK
  if(WID && (action & GMSH_GUI) && (num == WID->view_number))
    WID->view_value[62]->value(v->LineWidth);
#endif
  return v->LineWidth;
}


double opt_print_format(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.format = (int)val;
  return CTX.print.format;
}
double opt_print_eps_quality(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.eps_quality = (int)val;
  return CTX.print.eps_quality;
}
double opt_print_eps_background(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.eps_background = (int)val;
  return CTX.print.eps_background;
}
double opt_print_eps_font_size(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.eps_font_size = (int)val;
  return CTX.print.eps_font_size;
}
double opt_print_eps_line_width_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.eps_line_width_factor = val;
  return CTX.print.eps_line_width_factor;
}
double opt_print_eps_point_size_factor(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.eps_point_size_factor = val;
  return CTX.print.eps_point_size_factor;
}
double opt_print_jpeg_quality(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.jpeg_quality = (int)val;
  return CTX.print.jpeg_quality;
}
double opt_print_gif_dither(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.gif_dither = (int)val;
  return CTX.print.gif_dither;
}
double opt_print_gif_sort(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.gif_sort = (int)val;
  return CTX.print.gif_sort;
}
double opt_print_gif_interlace(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.gif_interlace = (int)val;
  return CTX.print.gif_interlace;
}
double opt_print_gif_transparent(OPT_ARGS_NUM){
  if(action & GMSH_SET) 
    CTX.print.gif_transparent = (int)val;
  return CTX.print.gif_transparent;
}

// ************** Color option routines ****************************

#ifdef _FLTK

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 1)
#define contrast fl_contrast
#endif

#define CCC(col,but)							\
  if(WID && (action & GMSH_GUI)){					\
    Fl_Color c = fl_color_cube(UNPACK_RED(col)*FL_NUM_RED/256, 		\
			       UNPACK_GREEN(col)*FL_NUM_GREEN/256,	\
			       UNPACK_BLUE(col)*FL_NUM_BLUE/256);	\
    (but)->color(c);							\
    (but)->labelcolor(contrast(FL_BLACK,c));				\
    (but)->redraw();							\
  }

#endif

unsigned int opt_general_color_background(OPT_ARGS_COL){
  if(action & GMSH_SET){
    CTX.color.bg = val;
#ifdef _FLTK
    if(WID) WID->view_colorbar_window->redraw();
#endif
  }
#ifdef _FLTK
  CCC(CTX.color.bg,WID->gen_col[0]);
#endif
  return CTX.color.bg;
}
unsigned int opt_general_color_foreground(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.fg = val;
#ifdef _FLTK
  CCC(CTX.color.fg,WID->gen_col[1]);
#endif
  return CTX.color.fg;
}
unsigned int opt_general_color_text(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.text = val;
#ifdef _FLTK
  CCC(CTX.color.text,WID->gen_col[2]);
#endif
  return CTX.color.text;
}
unsigned int opt_general_color_axes(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.axes = val;
#ifdef _FLTK
  CCC(CTX.color.axes,WID->gen_col[3]);
#endif
  return CTX.color.axes;
}
unsigned int opt_general_color_small_axes(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.small_axes = val;
#ifdef _FLTK
  CCC(CTX.color.small_axes,WID->gen_col[4]);
#endif
  return CTX.color.small_axes;
}
unsigned int opt_geometry_color_points(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.point = val;
#ifdef _FLTK
  CCC(CTX.color.geom.point,WID->geo_col[0]);
#endif
  return CTX.color.geom.point;
} 
unsigned int opt_geometry_color_lines(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.line = val;
#ifdef _FLTK
  CCC(CTX.color.geom.line,WID->geo_col[1]);
#endif
  return CTX.color.geom.line;
}
unsigned int opt_geometry_color_surfaces(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.surface = val;
#ifdef _FLTK
  CCC(CTX.color.geom.surface,WID->geo_col[2]);
#endif
  return CTX.color.geom.surface;
}
unsigned int opt_geometry_color_volumes(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.volume = val;
#ifdef _FLTK
  CCC(CTX.color.geom.volume,WID->geo_col[3]);
#endif
  return CTX.color.geom.volume;
}
unsigned int opt_geometry_color_points_select(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.point_sel = val;
#ifdef _FLTK
  CCC(CTX.color.geom.point_sel,WID->geo_col[4]);
#endif
  return CTX.color.geom.point_sel;
}
unsigned int opt_geometry_color_lines_select(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.line_sel = val;
#ifdef _FLTK
  CCC(CTX.color.geom.line_sel,WID->geo_col[5]);
#endif
  return CTX.color.geom.line_sel;
}
unsigned int opt_geometry_color_surfaces_select(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.surface_sel = val;
#ifdef _FLTK
  CCC(CTX.color.geom.surface_sel,WID->geo_col[6]);
#endif
  return CTX.color.geom.surface_sel;
}
unsigned int opt_geometry_color_volumes_select(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.volume_sel = val;
#ifdef _FLTK
  CCC(CTX.color.geom.volume_sel,WID->geo_col[7]);
#endif
  return CTX.color.geom.volume_sel;
}
unsigned int opt_geometry_color_points_highlight(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.point_hlt = val;
#ifdef _FLTK
  CCC(CTX.color.geom.point_hlt,WID->geo_col[8]);
#endif
  return CTX.color.geom.point_hlt;
}
unsigned int opt_geometry_color_lines_highlight(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.line_hlt = val;
#ifdef _FLTK
  CCC(CTX.color.geom.line_hlt,WID->geo_col[9]);
#endif
  return CTX.color.geom.line_hlt;
}
unsigned int opt_geometry_color_surfaces_highlight(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.surface_hlt = val;
#ifdef _FLTK
  CCC(CTX.color.geom.surface_hlt,WID->geo_col[10]);
#endif
  return CTX.color.geom.surface_hlt;
}
unsigned int opt_geometry_color_volumes_highlight(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.volume_hlt = val;
#ifdef _FLTK
  CCC(CTX.color.geom.volume_hlt,WID->geo_col[11]);
#endif
  return CTX.color.geom.volume_hlt;
}
unsigned int opt_geometry_color_tangents(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.tangents = val;
#ifdef _FLTK
  CCC(CTX.color.geom.tangents,WID->geo_col[12]);
#endif
  return CTX.color.geom.tangents;
}
unsigned int opt_geometry_color_normals(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.geom.normals = val;
#ifdef _FLTK
  CCC(CTX.color.geom.normals,WID->geo_col[13]);
#endif
  return CTX.color.geom.normals;
}
unsigned int opt_mesh_color_points(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.vertex = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.vertex,WID->mesh_col[0]);
#endif
  return CTX.color.mesh.vertex;
} 
unsigned int opt_mesh_color_points_supp(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.vertex_supp = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.vertex_supp,WID->mesh_col[1]);
#endif
  return CTX.color.mesh.vertex_supp;
} 
unsigned int opt_mesh_color_lines(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.line = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.line,WID->mesh_col[2]);
#endif
  return CTX.color.mesh.line;
} 
unsigned int opt_mesh_color_triangles(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.triangle = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.triangle,WID->mesh_col[3]);
#endif
  return CTX.color.mesh.triangle;
}
unsigned int opt_mesh_color_quadrangles(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.quadrangle = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.quadrangle,WID->mesh_col[4]);
#endif
  return CTX.color.mesh.quadrangle;
}
unsigned int opt_mesh_color_tetrahedra(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.tetrahedron = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.tetrahedron,WID->mesh_col[5]);
#endif
  return CTX.color.mesh.tetrahedron;
}
unsigned int opt_mesh_color_hexahedra(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.hexahedron = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.hexahedron,WID->mesh_col[6]);
#endif
  return CTX.color.mesh.hexahedron;
}
unsigned int opt_mesh_color_prisms(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.prism = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.prism,WID->mesh_col[7]);
#endif
  return CTX.color.mesh.prism;
}
unsigned int opt_mesh_color_pyramid(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.pyramid = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.pyramid,WID->mesh_col[8]);
#endif
  return CTX.color.mesh.pyramid;
}
unsigned int opt_mesh_color_tangents(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.tangents = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.tangents,WID->mesh_col[9]);
#endif
  return CTX.color.mesh.tangents;
}
unsigned int opt_mesh_color_normals(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.normals = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.normals,WID->mesh_col[10]);
#endif
  return CTX.color.mesh.normals;
}
unsigned int opt_mesh_color_1(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[0] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[0],WID->mesh_col[11]);
#endif
  return CTX.color.mesh.carousel[0];
}
unsigned int opt_mesh_color_2(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[1] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[1],WID->mesh_col[12]);
#endif
  return CTX.color.mesh.carousel[1];
}
unsigned int opt_mesh_color_3(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[2] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[2],WID->mesh_col[13]);
#endif
  return CTX.color.mesh.carousel[2];
}
unsigned int opt_mesh_color_4(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[3] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[3],WID->mesh_col[14]);
#endif
  return CTX.color.mesh.carousel[3];
}
unsigned int opt_mesh_color_5(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[4] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[4],WID->mesh_col[15]);
#endif
  return CTX.color.mesh.carousel[4];
}
unsigned int opt_mesh_color_6(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[5] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[5],WID->mesh_col[16]);
#endif
  return CTX.color.mesh.carousel[5];
}
unsigned int opt_mesh_color_7(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[6] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[6],WID->mesh_col[17]);
#endif
  return CTX.color.mesh.carousel[6];
}
unsigned int opt_mesh_color_8(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[7] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[7],WID->mesh_col[18]);
#endif
  return CTX.color.mesh.carousel[7];
}
unsigned int opt_mesh_color_9(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[8] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[8],WID->mesh_col[19]);
#endif
  return CTX.color.mesh.carousel[8];
}
unsigned int opt_mesh_color_10(OPT_ARGS_COL){
  if(action & GMSH_SET) 
    CTX.color.mesh.carousel[9] = val;
#ifdef _FLTK
  CCC(CTX.color.mesh.carousel[9],WID->mesh_col[20]);
#endif
  return CTX.color.mesh.carousel[9];
}
