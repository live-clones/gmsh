// $Id: Callbacks.cpp,v 1.252 2004-06-30 17:49:51 geuzaine Exp $
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

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <map>

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "CAD.h"
#include "ExtractContour.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Timer.h"
#include "CreateFile.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Context.h"
#include "Options.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Plugin.h"
#include "Visibility.h"
#include "MinMax.h"

using namespace std;

#include <errno.h>

extern GUI *WID;
extern Mesh *THEM;
extern Context_T CTX;

// File chooser (re)definitions

#include <FL/filename.H>
#include <FL/Fl_File_Chooser.H>

static Fl_File_Chooser *fc = NULL;

int file_chooser(int multi, int create, const char *message,
		 const char *pat, int patindex, char *fname=NULL)
{
  static char oldfilter[1024];

  Fl_File_Chooser::show_label = "Format:";
  Fl_File_Chooser::all_files_label = "All files (*)";

  if(!fc) {
    fc = new Fl_File_Chooser(getenv("PWD") ? "." : CTX.home_dir, pat, 
			     Fl_File_Chooser::SINGLE, message);
    strncpy(oldfilter, pat, 1024);
  }

  fc->label(message);

  if(fname)
    fc->value(fname);

  if(strncmp(oldfilter, pat, 1024)) {
    strncpy(oldfilter, pat, 1024);
    fc->filter(pat);
    fc->filter_value(patindex);
  }

  if(multi)
    fc->type(Fl_File_Chooser::MULTI);
  else if(create)
    fc->type(Fl_File_Chooser::CREATE);
  else
    fc->type(Fl_File_Chooser::SINGLE);

  fc->show();

  while(fc->shown())
    Fl::wait();

  if(fc->value())
    return fc->count();
  else
    return 0;
}

char *file_chooser_get_name(int num)
{
  // to get the relative path:
  // static char retname[1024];
  // fl_filename_relative(retname, sizeof(retname), fc->value(num));
  // return retname;

  return (char *)fc->value(num);
}

int file_chooser_get_filter()
{
  return fc->filter_value();
}

// arrow editor

#include <FL/Fl_Value_Slider.H>

int arrow_editor(char *title, double &a, double &b, double &c)
{
  struct _editor{
    Fl_Window *window;
    Fl_Value_Slider *sa, *sb, *sc;
    Fl_Button *apply, *cancel;
  };
  static _editor *editor = NULL;

  if(!editor){
    editor = new _editor;
    editor->window = new Fl_Window(200, 140);
    editor->sa = new Fl_Value_Slider(10, 10, 100, 25, "Head radius");
    editor->sa->type(FL_HOR_SLIDER);
    editor->sa->align(FL_ALIGN_RIGHT);
    editor->sb = new Fl_Value_Slider(10, 40, 100, 25, "Stem length");
    editor->sb->type(FL_HOR_SLIDER);
    editor->sb->align(FL_ALIGN_RIGHT);
    editor->sc = new Fl_Value_Slider(10, 70, 100, 25, "Stem radius");
    editor->sc->type(FL_HOR_SLIDER);
    editor->sc->align(FL_ALIGN_RIGHT);
    editor->apply = new Fl_Return_Button(10, 105, 85, 25, "Apply");
    editor->cancel = new Fl_Button(105, 105, 85, 25, "Cancel");
    editor->window->end();
    editor->window->hotspot(editor->window);
  }
  
  editor->window->label(title);
  editor->sa->value(a);
  editor->sb->value(b);
  editor->sc->value(c);
  editor->window->show();

  while(editor->window->shown()){
    Fl::wait();
    for (;;) {
      Fl_Widget* o = Fl::readqueue();
      if (!o) break;
      if (o == editor->apply) {
	a = editor->sa->value();
	b = editor->sb->value();
	c = editor->sc->value();
	return 1;
      }
      if (o == editor->window || o == editor->cancel){
	editor->window->hide();
	return 0;
      }
    }
  }
  return 0;
}

// Compatibility/local routines

void UpdateViewsInGUI()
{
  if(WID) {
    WID->check_anim_buttons();
    if(WID->get_context() == 3)
      WID->set_context(menu_post, 0);
    WID->reset_option_browser();
  }
}

int SetGlobalShortcut(int event)
{
  return WID->global_shortcuts(event);
}

int SelectContour(int type, int num, List_T * List)
{
  int k = 0, ip;

  switch (type) {
  case ENT_LINE:
    k = allEdgesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      List_Read(List, i, &ip);
      HighlightEntityNum(0, abs(ip), 0, 1);
    }
    break;
  case ENT_SURFACE:
    k = allFacesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      List_Read(List, i, &ip);
      HighlightEntityNum(0, 0, abs(ip), 1);
    }
    break;
  }

  return k;
}


// Common callbacks 

void cancel_cb(CALLBACK_ARGS)
{
  if(data)
    ((Fl_Window *) data)->hide();
}

void color_cb(CALLBACK_ARGS)
{
  unsigned int (*fct) (int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = UNPACK_RED(fct(0, GMSH_GET, 0));
  uchar g = UNPACK_GREEN(fct(0, GMSH_GET, 0));
  uchar b = UNPACK_BLUE(fct(0, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(0, GMSH_SET | GMSH_GUI, PACK_COLOR(r, g, b, 255));
  Draw();
}

void set_changed_cb(CALLBACK_ARGS)
{
  w->set_changed();
}

// Graphical window 

void status_xyz1p_cb(CALLBACK_ARGS)
{
  extern void set_r(int i, double val);
  extern void set_t(int i, double val);
  extern void set_s(int i, double val);

  switch ((long int)data) {
  case 0:
    if(CTX.useTrackball)
      CTX.setQuaternion(0., -1. / sqrt(2.), 0., 1. / sqrt(2.));
    set_r(0, 0.);
    set_r(1, 90.);
    set_r(2, 0.);
    Draw();
    break;
  case 1:
    if(CTX.useTrackball)
      CTX.setQuaternion(1. / sqrt(2.), 0., 0., 1. / sqrt(2.));
    set_r(0, -90.);
    set_r(1, 0.);
    set_r(2, 0.);
    Draw();
    break;
  case 2:
    if(CTX.useTrackball)
      CTX.setQuaternion(0., 0., 0., 1.);
    set_r(0, 0.);
    set_r(1, 0.);
    set_r(2, 0.);
    Draw();
    break;
  case 3:
    set_t(0, 0.);
    set_t(1, 0.);
    set_t(2, 0.);
    set_s(0, 1.);
    set_s(1, 1.);
    set_s(2, 1.);
    Draw();
    break;
  case 4:
    opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 
			     !opt_general_orthographic(0, GMSH_GET, 0));
    Draw();
    break;
  case 5:
    Print_Options(0, GMSH_FULLRC, false, NULL);
    WID->create_message_window();
    break;
  }
}

static int stop_anim, view_in_cycle = -1;

void ManualPlay(int time, int step)
{
  int i;
  if(time) {
    for(i = 0; i < List_Nbr(CTX.post.list); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                          opt_view_timestep(i, GMSH_GET, 0) + step);
  }
  else {        //hide all views except view_in_cycle
    if(step > 0) {
      if((view_in_cycle += step) >= List_Nbr(CTX.post.list))
        view_in_cycle = 0;
      for(i = 0; i < List_Nbr(CTX.post.list); i += step)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else {
      if((view_in_cycle += step) < 0)
        view_in_cycle = List_Nbr(CTX.post.list) - 1;
      for(i = List_Nbr(CTX.post.list) - 1; i >= 0; i += step)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
  }
  Draw();
}

void status_play_cb(CALLBACK_ARGS)
{
  static long anim_time;
  WID->set_anim_buttons(0);
  stop_anim = 0;
  anim_time = GetTime();
  while(1) {
    if(stop_anim)
      break;
    if(GetTime() - anim_time > 1.e6 * CTX.post.anim_delay) {
      anim_time = GetTime();
      ManualPlay(!CTX.post.anim_cycle, 1);
    }
    WID->check();
  }
}

void status_pause_cb(CALLBACK_ARGS)
{
  stop_anim = 1;
  WID->set_anim_buttons(1);
}

void status_rewind_cb(CALLBACK_ARGS)
{
  int i;
  if(!CTX.post.anim_cycle) {
    for(i = 0; i < List_Nbr(CTX.post.list); i++)
      opt_view_timestep(i, GMSH_SET | GMSH_GUI, 0);
  }
  else {
    view_in_cycle = 0;
    for(i = 0; i < List_Nbr(CTX.post.list); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, !i);
  }
  Draw();
}

void status_cancel_cb(CALLBACK_ARGS)
{
  ;
}

// File Menu

void file_new_cb(CALLBACK_ARGS)
{
 test:
  if(file_chooser(0, 1, "New file", "*", 0)) {
    char *name = file_chooser_get_name(1);
    struct stat buf;
    if(!stat(name, &buf)){
      if(fl_ask("%s already exists.\nDo you want to erase it?", name))
	unlink(name);
      else
	goto test;
    }
    // create a zero length file so that it actually exists (and stupid
    // Mac/Windows editors accept to deal with it)
    FILE *fp = fopen(name, "w");
    if(!fp){
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    fprintf(fp, "");
    fclose(fp);
    OpenProblem(name);
    Draw();
  }
}

void file_open_cb(CALLBACK_ARGS)
{
  int n = List_Nbr(CTX.post.list);
  if(file_chooser(0, 0, "Open file", "*", 0)) {
    OpenProblem(file_chooser_get_name(1));
    Draw();
  }
  if(n != List_Nbr(CTX.post.list))
    WID->set_context(menu_post, 0);
}

void file_merge_cb(CALLBACK_ARGS)
{
  int n = List_Nbr(CTX.post.list);
  int f = file_chooser(1, 0, "Merge file(s)", "*", 0);
  if(f) {
    for(int i = 1; i <= f; i++)
      MergeProblem(file_chooser_get_name(i));
    Draw();
  }
  if(n != List_Nbr(CTX.post.list))
    WID->set_context(menu_post, 0);
}

void _save_auto(char *name)
{
  CreateOutputFile(name, FORMAT_AUTO);
}
void _save_geo_options(char *name)
{
  CreateOutputFile(name, FORMAT_OPT);
}
void _save_geo_options_diff(char *name)
{
  Print_Options(0, GMSH_FULLRC, true, name);
}
void _save_geo(char *name)
{
  CreateOutputFile(name, FORMAT_GEO);
}
void _save_msh(char *name)
{
  double ver = CTX.mesh.msh_file_version;
  CTX.mesh.msh_file_version = 1.0;
  CreateOutputFile(name, CTX.mesh.format = FORMAT_MSH);
  CTX.mesh.msh_file_version = ver;
}
void _save_msh_all(char *name)
{
  int all = CTX.mesh.save_all;
  double ver = CTX.mesh.msh_file_version;
  CTX.mesh.msh_file_version = 1.0;
  CTX.mesh.save_all = 1;
  CreateOutputFile(name, CTX.mesh.format = FORMAT_MSH);
  CTX.mesh.save_all = all;
  CTX.mesh.msh_file_version = ver;
}
void _save_msh_v2(char *name)
{
  double ver = CTX.mesh.msh_file_version;
  CTX.mesh.msh_file_version = 2.0;
  CreateOutputFile(name, CTX.mesh.format = FORMAT_MSH);
  CTX.mesh.msh_file_version = ver;
}
void _save_msh_all_v2(char *name)
{
  int all = CTX.mesh.save_all;
  double ver = CTX.mesh.msh_file_version;
  CTX.mesh.msh_file_version = 2.0;
  CTX.mesh.save_all = 1;
  CreateOutputFile(name, CTX.mesh.format = FORMAT_MSH);
  CTX.mesh.save_all = all;
  CTX.mesh.msh_file_version = ver;
}
void _save_lc_sur(char *name)
{
  CreateOutputFile(name, FORMAT_LC_SUR);
}
void _save_lc_vol(char *name)
{
  CreateOutputFile(name, FORMAT_LC_VOL);
}
void _save_gref(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_GREF);
}
void _save_unv(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_UNV);
}
void _save_vrml(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_VRML);
}
void _save_ps_raster(char *name)
{
  CreateOutputFile(name, FORMAT_PS_RASTER);
}
void _save_ps_simple(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 1;
  CreateOutputFile(name, FORMAT_PS);
  CTX.print.eps_quality = old;
}
void _save_ps_accurate(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 2;
  CreateOutputFile(name, FORMAT_PS);
  CTX.print.eps_quality = old;
}
void _save_eps_raster(char *name)
{
  CreateOutputFile(name, FORMAT_EPS_RASTER);
}
void _save_eps_simple(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 1;
  CreateOutputFile(name, FORMAT_EPS);
  CTX.print.eps_quality = old;
}
void _save_eps_accurate(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 2;
  CreateOutputFile(name, FORMAT_EPS);
  CTX.print.eps_quality = old;
}
void _save_epstex_raster(char *name)
{
  CreateOutputFile(name, FORMAT_EPSTEX_RASTER);
}
void _save_epstex_simple(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 1;
  CreateOutputFile(name, FORMAT_EPSTEX);
  CTX.print.eps_quality = old;
}
void _save_epstex_accurate(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 2;
  CreateOutputFile(name, FORMAT_EPSTEX);
  CTX.print.eps_quality = old;
}
void _save_pdf_raster(char *name)
{
  CreateOutputFile(name, FORMAT_PDF_RASTER);
}
void _save_pdf_simple(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 1;
  CreateOutputFile(name, FORMAT_PDF);
  CTX.print.eps_quality = old;
}
void _save_pdf_accurate(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 2;
  CreateOutputFile(name, FORMAT_PDF);
  CTX.print.eps_quality = old;
}
void _save_pdftex_raster(char *name)
{
  CreateOutputFile(name, FORMAT_PDFTEX_RASTER);
}
void _save_pdftex_simple(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 1;
  CreateOutputFile(name, FORMAT_PDFTEX);
  CTX.print.eps_quality = old;
}
void _save_pdftex_accurate(char *name)
{
  int old = CTX.print.eps_quality;
  CTX.print.eps_quality = 2;
  CreateOutputFile(name, FORMAT_PDFTEX);
  CTX.print.eps_quality = old;
}
void _save_jpegtex(char *name)
{
  CreateOutputFile(name, FORMAT_JPEGTEX);
}
void _save_pngtex(char *name)
{
  CreateOutputFile(name, FORMAT_PNGTEX);
}
void _save_tex(char *name)
{
  CreateOutputFile(name, FORMAT_TEX);
}
void _save_jpeg(char *name)
{
  CreateOutputFile(name, FORMAT_JPEG);
}
void _save_png(char *name)
{
  CreateOutputFile(name, FORMAT_PNG);
}
void _save_gif(char *name)
{
  int dither = CTX.print.gif_dither;
  int transp = CTX.print.gif_transparent;
  CTX.print.gif_dither = 0;
  CTX.print.gif_transparent = 0;
  CreateOutputFile(name, FORMAT_GIF);
  CTX.print.gif_dither = dither;
  CTX.print.gif_transparent = transp;
}
void _save_gif_dithered(char *name)
{
  int dither = CTX.print.gif_dither;
  int transp = CTX.print.gif_transparent;
  CTX.print.gif_dither = 1;
  CTX.print.gif_transparent = 0;
  CreateOutputFile(name, FORMAT_GIF);
  CTX.print.gif_dither = dither;
  CTX.print.gif_transparent = transp;
}
void _save_gif_transparent(char *name)
{
  int dither = CTX.print.gif_dither;
  int transp = CTX.print.gif_transparent;
  CTX.print.gif_dither = 0;
  CTX.print.gif_transparent = 1;
  CreateOutputFile(name, FORMAT_GIF);
  CTX.print.gif_dither = dither;
  CTX.print.gif_transparent = transp;
}
void _save_ppm(char *name)
{
  CreateOutputFile(name, FORMAT_PPM);
}
void _save_yuv(char *name)
{
  CreateOutputFile(name, FORMAT_YUV);
}

typedef struct{
  char *pat;
  void (*func) (char *name);
} patXfunc;

void file_save_as_cb(CALLBACK_ARGS)
{
  int i, nbformats;
  static int patindex = 0;
  static char *pat = NULL;
  static patXfunc formats[] = {
    {"By extension (*)", _save_auto},
    {"Gmsh options (*.opt)", _save_geo_options},
    {"Gmsh modified options (*.opt)", _save_geo_options_diff},
    {"Gmsh unrolled geometry (*.geo)", _save_geo},
    {"Gmsh mesh v1.0 (*.msh)", _save_msh},
    {"Gmsh mesh v1.0 without physicals (*.msh)", _save_msh_all},
    {"Gmsh mesh v2.0 (*.msh)", _save_msh_v2},
    {"Gmsh mesh v2.0 without physicals (*.msh)", _save_msh_all_v2},
    {"Gmsh surface LC field (*.pos)", _save_lc_sur},
    {"Gmsh volume LC field (*.pos)", _save_lc_vol},
    {"GREF mesh (*.gref)", _save_gref},
    {"I-DEAS universal mesh format (*.unv)", _save_unv},
    {"VRML surface mesh (*.wrl)", _save_vrml},
    {"GIF (*.gif)", _save_gif},
    {"GIF dithered (*.gif)", _save_gif_dithered},
    {"GIF transparent (*.gif)", _save_gif_transparent},
#if defined(HAVE_LIBJPEG)
    {"JPEG (*.jpg)", _save_jpeg},
#endif
#if defined(HAVE_LIBPNG)
    {"PNG (*.png)", _save_png},
#endif
    {"Raster PS (*.ps)", _save_ps_raster},
    {"Raster EPS (*.eps)", _save_eps_raster},
    {"Raster PDF (*.pdf)", _save_pdf_raster},
    {"Vector PS fast (*.ps)", _save_ps_simple},
    {"Vector PS accurate (*.ps)", _save_ps_accurate},
    {"Vector EPS fast (*.eps)", _save_eps_simple},
    {"Vector EPS accurate (*.eps)", _save_eps_accurate},
    {"Vector PDF fast (*.pdf)", _save_pdf_simple},
    {"Vector PDF accurate (*.pdf)", _save_pdf_accurate},
    {"PPM (*.ppm)", _save_ppm},
#if defined(HAVE_LIBJPEG)
    {"LaTeX JPEG part (*.jpg)", _save_jpegtex},
#endif
#if defined(HAVE_LIBPNG)
    {"LaTeX PNG part (*.png)", _save_pngtex},
#endif
    {"LaTeX Raster EPS part (*.eps)", _save_epstex_raster},
    {"LaTeX Raster PDF part (*.pdf)", _save_pdftex_raster},
    {"LaTeX Vector EPS part fast (*.eps)", _save_epstex_simple},
    {"LaTeX Vector EPS part accurate (*.eps)", _save_epstex_accurate},
    {"LaTeX Vector PDF part fast (*.pdf)", _save_pdftex_simple},
    {"LaTeX Vector PDF part accurate (*.pdf)", _save_pdftex_accurate},
    {"LaTeX TeX part (*.tex)", _save_tex},
    {"UCB YUV (*.yuv)", _save_yuv}
  };

  nbformats = sizeof(formats) / sizeof(formats[0]);

  if(!pat) {
    pat = (char *)Malloc(nbformats * 256 * sizeof(char));
    strcpy(pat, formats[0].pat);
    for(i = 1; i < nbformats; i++) {
      strcat(pat, "\t");
      strcat(pat, formats[i].pat);
    }
  }

test:

  if(file_chooser(0, 1, "Save file as", pat, patindex)) {

    char *name = file_chooser_get_name(1);

    if(CTX.confirm_overwrite) {
      struct stat buf;
      if(!stat(name, &buf))
        if(fl_ask("%s already exists.\nDo you want to replace it?", name))
          goto save;
        else
          goto test;
    }

  save:
    i = file_chooser_get_filter();
    if(i >= 0 && i < nbformats)
      formats[i].func(name);
    else        // handle any additional automatic fltk filter
      _save_auto(name);

  }

  patindex = file_chooser_get_filter();
}

void file_quit_cb(CALLBACK_ARGS)
{
  Exit(0);
}

// Option Menu

void options_cb(CALLBACK_ARGS)
{
  WID->create_option_window();
}

void options_browser_cb(CALLBACK_ARGS)
{
  switch (WID->opt_browser->value()) {
  case 0:
    break;
  case 1:
    WID->create_general_options_window();
    break;
  case 2:
    WID->create_geometry_options_window();
    break;
  case 3:
    WID->create_mesh_options_window();
    break;
  case 4:
    WID->create_solver_options_window();
    break;
  case 5:
    WID->create_post_options_window();
    break;
  default:
    WID->create_view_options_window(WID->opt_browser->value() - 6);
    break;
  }
}

void options_save_cb(CALLBACK_ARGS)
{
  Print_Options(0, GMSH_OPTIONSRC, true, CTX.options_filename_fullpath);
}

void options_restore_defaults_cb(CALLBACK_ARGS)
{
  // not sure if we have to remove the file...
  unlink(CTX.session_filename_fullpath);
  unlink(CTX.options_filename_fullpath);
  ReInit_Options(0);
  Init_Options_GUI(0);
  if(WID && WID->get_context() == 3)    // hack to refresh the buttons
    WID->set_context(menu_post, 0);
  Draw();
}

void options_ok_cb(CALLBACK_ARGS)
{
  general_options_ok_cb(w, data);
  geometry_options_ok_cb(w, data);
  mesh_options_ok_cb(w, data);
  solver_options_ok_cb(w, data);
  post_options_ok_cb(w, data);
  view_options_ok_cb(w, (void *)WID->view_number);
  Draw();
}

// General options

void general_options_cb(CALLBACK_ARGS)
{
  WID->create_general_options_window();
}

void general_options_color_scheme_cb(CALLBACK_ARGS)
{
  opt_general_color_scheme(0, GMSH_SET, WID->gen_value[0]->value());
  Draw();
}

void general_options_rotation_center_cb(CALLBACK_ARGS)
{
  WID->check_rotation_center_button();
}

void general_options_rotation_center_select_cb(CALLBACK_ARGS)
{
  Vertex *v;
  Curve *c;
  Surface *s;

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  Msg(STATUS3N, "Setting rotation center");
  Msg(ONSCREEN, "Select point\n[Press 'q' to abort]");
  char ib = SelectEntity(ENT_POINT, &v, &c, &s);
  if(ib == 'l') {
    // This would bypass the "Apply" button... Not necessarily bad,
    // but it's not consistent with the rest of the GUI.
    //opt_general_rotation_center0(0, GMSH_SET|GMSH_GUI, v->Pos.X);
    //opt_general_rotation_center1(0, GMSH_SET|GMSH_GUI, v->Pos.Y);
    //opt_general_rotation_center2(0, GMSH_SET|GMSH_GUI, v->Pos.Z);

    // This is more conform to the way we do things elsewhere:
    WID->gen_value[8]->value(v->Pos.X);
    WID->gen_value[9]->value(v->Pos.Y);
    WID->gen_value[10]->value(v->Pos.Z);
  }
  ZeroHighlight(THEM);
  Draw();
  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void general_options_ok_cb(CALLBACK_ARGS)
{
  opt_general_axes(0, GMSH_SET, WID->gen_butt[0]->value());
  opt_general_small_axes(0, GMSH_SET, WID->gen_butt[1]->value());
  opt_general_fast_redraw(0, GMSH_SET, WID->gen_butt[2]->value());
  if(opt_general_double_buffer(0, GMSH_GET, 0) != WID->gen_butt[3]->value())
    opt_general_double_buffer(0, GMSH_SET, WID->gen_butt[3]->value());
  opt_general_fake_transparency(0, GMSH_SET, WID->gen_butt[4]->value());
  opt_general_trackball(0, GMSH_SET, WID->gen_butt[5]->value());
  opt_general_terminal(0, GMSH_SET, WID->gen_butt[7]->value());
  double sessionrc = opt_general_session_save(0, GMSH_GET, 0);
  opt_general_session_save(0, GMSH_SET, WID->gen_butt[8]->value());
  if(sessionrc && !opt_general_session_save(0, GMSH_GET, 0))
    Print_Options(0, GMSH_SESSIONRC, true, CTX.session_filename_fullpath);
  opt_general_options_save(0, GMSH_SET, WID->gen_butt[9]->value());
  opt_general_tooltips(0, GMSH_SET, WID->gen_butt[13]->value());
  opt_general_confirm_overwrite(0, GMSH_SET, WID->gen_butt[14]->value());
  opt_general_rotation_center_cg(0, GMSH_SET, WID->gen_butt[15]->value());

  opt_general_shine(0, GMSH_SET, WID->gen_value[1]->value());
  opt_general_light00(0, GMSH_SET, WID->gen_value[2]->value());
  opt_general_light01(0, GMSH_SET, WID->gen_value[3]->value());
  opt_general_light02(0, GMSH_SET, WID->gen_value[4]->value());
  opt_general_verbosity(0, GMSH_SET, WID->gen_value[5]->value());
  opt_general_point_size(0, GMSH_SET, WID->gen_value[6]->value());
  opt_general_line_width(0, GMSH_SET, WID->gen_value[7]->value());
  opt_general_rotation_center0(0, GMSH_SET, WID->gen_value[8]->value());
  opt_general_rotation_center1(0, GMSH_SET, WID->gen_value[9]->value());
  opt_general_rotation_center2(0, GMSH_SET, WID->gen_value[10]->value());
  opt_general_quadric_subdivisions(0, GMSH_SET, WID->gen_value[11]->value());
  opt_general_graphics_fontsize(0, GMSH_SET, WID->gen_value[12]->value());

  opt_general_default_filename(0, GMSH_SET, (char *)WID->gen_input[0]->value());
  opt_general_editor(0, GMSH_SET, (char *)WID->gen_input[1]->value());
  opt_general_web_browser(0, GMSH_SET, (char *)WID->gen_input[2]->value());

  int val;
  switch (WID->gen_choice[0]->value()) {
  case 0:
    val = DRAW_POST_SEGMENT;
    break;
  case 1:
    val = DRAW_POST_ARROW;
    break;
  case 2:
    val = DRAW_POST_PYRAMID;
    break;
  default:
    val = DRAW_POST_ARROW3D;
    break;
  }
  opt_general_vector_type(0, GMSH_SET, val);
  opt_general_graphics_font(0, GMSH_SET, (char *)WID->gen_choice[1]->text());
  opt_general_orthographic(0, GMSH_SET | GMSH_GUI, !WID->gen_choice[2]->value());
}

void general_arrow_param_cb(CALLBACK_ARGS)
{
  double a = opt_general_arrow_head_radius(0, GMSH_GET, 0);
  double b = opt_general_arrow_stem_length(0, GMSH_GET, 0);
  double c = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
  while(arrow_editor("Arrow editor", a, b, c)){
    opt_general_arrow_head_radius(0, GMSH_SET, a);
    opt_general_arrow_stem_length(0, GMSH_SET, b);
    opt_general_arrow_stem_radius(0, GMSH_SET, c);
    Draw();
  }
}

// Geometry options

void geometry_options_cb(CALLBACK_ARGS)
{
  WID->create_geometry_options_window();
}

void geometry_options_color_scheme_cb(CALLBACK_ARGS)
{
  opt_geometry_color_scheme(0, GMSH_SET, WID->geo_value[2]->value());
  Draw();
}

void geometry_options_ok_cb(CALLBACK_ARGS)
{
  opt_geometry_points(0, GMSH_SET, WID->geo_butt[0]->value());
  opt_geometry_lines(0, GMSH_SET, WID->geo_butt[1]->value());
  opt_geometry_surfaces(0, GMSH_SET, WID->geo_butt[2]->value());
  opt_geometry_volumes(0, GMSH_SET, WID->geo_butt[3]->value());
  opt_geometry_points_num(0, GMSH_SET, WID->geo_butt[4]->value());
  opt_geometry_lines_num(0, GMSH_SET, WID->geo_butt[5]->value());
  opt_geometry_surfaces_num(0, GMSH_SET, WID->geo_butt[6]->value());
  opt_geometry_volumes_num(0, GMSH_SET, WID->geo_butt[7]->value());
  opt_geometry_auto_coherence(0, GMSH_SET, WID->geo_butt[8]->value());
  opt_geometry_light(0, GMSH_SET, WID->geo_butt[9]->value());

  opt_geometry_normals(0, GMSH_SET, WID->geo_value[0]->value());
  opt_geometry_tangents(0, GMSH_SET, WID->geo_value[1]->value());
  opt_geometry_point_size(0, GMSH_SET, WID->geo_value[3]->value());
  opt_geometry_line_width(0, GMSH_SET, WID->geo_value[4]->value());
  opt_geometry_point_sel_size(0, GMSH_SET, WID->geo_value[5]->value());
  opt_geometry_line_sel_width(0, GMSH_SET, WID->geo_value[6]->value());

  opt_geometry_point_type(0, GMSH_SET, WID->geo_choice[0]->value());
  opt_geometry_line_type(0, GMSH_SET, WID->geo_choice[1]->value());
}

// Mesh options

void mesh_options_cb(CALLBACK_ARGS)
{
  WID->create_mesh_options_window();
}

void mesh_options_color_scheme_cb(CALLBACK_ARGS)
{
  opt_mesh_color_scheme(0, GMSH_SET, WID->mesh_value[12]->value());
  Draw();
}

void mesh_options_ok_cb(CALLBACK_ARGS)
{
  opt_mesh_optimize(0, GMSH_SET, WID->mesh_butt[2]->value());
  opt_mesh_order(0, GMSH_SET, WID->mesh_butt[3]->value()? 2 : 1);
  opt_mesh_interactive(0, GMSH_SET, WID->mesh_butt[4]->value());
  opt_mesh_constrained_bgmesh(0, GMSH_SET, WID->mesh_butt[5]->value());
  opt_mesh_points(0, GMSH_SET, WID->mesh_butt[6]->value());
  opt_mesh_lines(0, GMSH_SET, WID->mesh_butt[7]->value());
  opt_mesh_surfaces_edges(0, GMSH_SET, WID->mesh_butt[8]->value());
  opt_mesh_surfaces_faces(0, GMSH_SET, WID->mesh_butt[9]->value());
  opt_mesh_volumes_edges(0, GMSH_SET, WID->mesh_butt[10]->value());
  opt_mesh_volumes_faces(0, GMSH_SET, WID->mesh_butt[11]->value());
  opt_mesh_points_num(0, GMSH_SET, WID->mesh_butt[12]->value());
  opt_mesh_lines_num(0, GMSH_SET, WID->mesh_butt[13]->value());
  opt_mesh_surfaces_num(0, GMSH_SET, WID->mesh_butt[14]->value());
  opt_mesh_volumes_num(0, GMSH_SET, WID->mesh_butt[15]->value());
  opt_mesh_use_cut_plane(0, GMSH_SET, WID->mesh_butt[16]->value());
  opt_mesh_cut_plane_as_surface(0, GMSH_SET, WID->mesh_butt[22]->value());
  opt_mesh_light(0, GMSH_SET, WID->mesh_butt[17]->value());
  opt_mesh_light_two_side(0, GMSH_SET, WID->mesh_butt[23]->value());

  opt_mesh_nb_smoothing(0, GMSH_SET, WID->mesh_value[0]->value());
  opt_mesh_scaling_factor(0, GMSH_SET, WID->mesh_value[1]->value());
  opt_mesh_lc_factor(0, GMSH_SET, WID->mesh_value[2]->value());
  opt_mesh_rand_factor(0, GMSH_SET, WID->mesh_value[3]->value());
  opt_mesh_gamma_inf(0, GMSH_SET, WID->mesh_value[4]->value());
  opt_mesh_gamma_sup(0, GMSH_SET, WID->mesh_value[5]->value());
  opt_mesh_radius_inf(0, GMSH_SET, WID->mesh_value[6]->value());
  opt_mesh_radius_sup(0, GMSH_SET, WID->mesh_value[7]->value());
  opt_mesh_normals(0, GMSH_SET, WID->mesh_value[8]->value());
  opt_mesh_explode(0, GMSH_SET, WID->mesh_value[9]->value());
  opt_mesh_tangents(0, GMSH_SET, WID->mesh_value[13]->value());
  opt_mesh_point_size(0, GMSH_SET, WID->mesh_value[10]->value());
  opt_mesh_line_width(0, GMSH_SET, WID->mesh_value[11]->value());
  opt_mesh_cut_planea(0, GMSH_SET, WID->mesh_value[14]->value());
  opt_mesh_cut_planeb(0, GMSH_SET, WID->mesh_value[15]->value());
  opt_mesh_cut_planec(0, GMSH_SET, WID->mesh_value[16]->value());
  opt_mesh_cut_planed(0, GMSH_SET, WID->mesh_value[17]->value());

  opt_mesh_point_type(0, GMSH_SET, WID->mesh_choice[0]->value());
  opt_mesh_line_type(0, GMSH_SET, WID->mesh_choice[1]->value());
  opt_mesh_algo2d(0, GMSH_SET,
		  (WID->mesh_choice[2]->value() == 0) ? DELAUNAY_ISO :
		  (WID->mesh_choice[2]->value() == 1) ? DELAUNAY_TRIANGLE :
		  DELAUNAY_ANISO);
  opt_mesh_algo3d(0, GMSH_SET,
		  (WID->mesh_choice[3]->value() == 0) ? DELAUNAY_ISO :
		  FRONTAL_NETGEN);
  opt_mesh_color_carousel(0, GMSH_SET, WID->mesh_choice[4]->value());
}

// Solver options

void solver_options_cb(CALLBACK_ARGS)
{
  WID->create_solver_options_window();
}

void solver_options_ok_cb(CALLBACK_ARGS)
{
}

// Post options

void post_options_cb(CALLBACK_ARGS)
{
  WID->create_post_options_window();
}

void post_options_ok_cb(CALLBACK_ARGS)
{
  opt_post_anim_cycle(0, GMSH_SET, WID->post_butt[0]->value());

  opt_post_anim_delay(0, GMSH_SET, WID->post_value[0]->value());

  opt_post_link(0, GMSH_SET, WID->post_choice[0]->value());
}

// Statistics Menu

void statistics_cb(CALLBACK_ARGS)
{
  WID->create_statistics_window();
}

void statistics_update_cb(CALLBACK_ARGS)
{
  WID->set_statistics();
}

void statistics_histogram_cb(CALLBACK_ARGS)
{
  int i, type = (long int)data;

  Print_Histogram(THEM->Histogram[type]);

  double *x = (double *)Malloc(NB_HISTOGRAM * sizeof(double));
  double *y = (double *)Malloc(NB_HISTOGRAM * sizeof(double));
  for(i = 0; i < NB_HISTOGRAM; i++) {
    x[i] = (double)(i + 1) / (double)NB_HISTOGRAM;
    y[i] = (double)THEM->Histogram[type][i];
  }
  char *name;
  if(type == 0)
    name = "Gamma";
  else if(type == 1)
    name = "Eta";
  else
    name = "Rho";
  Create2DGraph(name, "Elements", NB_HISTOGRAM, x, y);
  Draw();
}

// Messages Menu

void message_cb(CALLBACK_ARGS)
{
  WID->create_message_window();
}

void message_copy_cb(CALLBACK_ARGS)
{
#define BUFFL 50000
  static char buff[BUFFL];
  strcpy(buff, "");
  for(int i = 1; i <= WID->msg_browser->size(); i++) {
    if(WID->msg_browser->selected(i)) {
      const char *c = WID->msg_browser->text(i);
      if(strlen(buff) + strlen(c) > BUFFL - 2) {
        Msg(GERROR, "Text selection too large to copy");
        break;
      }
      if(c[0] == '@')
        strcat(buff, &c[3]);
      else
        strcat(buff, c);
      strcat(buff, "\n");
    }
  }
  // bof bof bof
  Fl::copy(buff, strlen(buff), 0);
  Fl::copy(buff, strlen(buff), 1);
}

void message_clear_cb(CALLBACK_ARGS)
{
  WID->msg_browser->clear();
}

void message_save_cb(CALLBACK_ARGS)
{
test:
  if(file_chooser(0, 1, "Save messages", "*", 0)) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      struct stat buf;
      if(!stat(name, &buf))
        if(fl_ask("%s already exists.\nDo you want to replace it?", name))
          goto save;
        else
          goto test;
    }
  save:
    WID->save_message(name);
  }
}

// Option Visibility Menu

void select_vis_browser(int mode)
{
  int i;
  Entity *e;
  for(i = 1; i <= WID->vis_browser->size(); i++) {
    e = (Entity *) WID->vis_browser->data(i);
    if((mode == VIS_GEOM | VIS_MESH && e->Visible() == mode) ||
       (mode == VIS_GEOM && e->Visible() & VIS_GEOM) ||
       (mode == VIS_MESH && e->Visible() & VIS_MESH))
      WID->vis_browser->select(i);
  }
}

void visibility_cb(CALLBACK_ARGS)
{
  int i, type, mode;
  List_T *list;
  Entity *e;

  WID->create_visibility_window();
  WID->vis_browser->clear();

  switch (WID->vis_type->value()) {
  case 0:
    type = ELEMENTARY;
    break;
  case 1:
    type = PHYSICAL;
    break;
  default :
    type = PARTITION;
    break;
  }
  switch (WID->vis_browser_mode->value()) {
  case 0:
    mode = VIS_GEOM | VIS_MESH;
    break;
  case 1:
    mode = VIS_GEOM;
    break;
  default:
    mode = VIS_MESH;
    break;
  }

  list = GetVisibilityList(type);

  for(i = 0; i < List_Nbr(list); i++) {
    e = (Entity *) List_Pointer(list, i);
    WID->vis_browser->add(e->BrowserLine(), e);
  }
  select_vis_browser(mode);
}

void visibility_ok_cb(CALLBACK_ARGS)
{
  int i, mode;
  Entity *e;

  InitVisibilityThroughPhysical();

  switch (WID->vis_type->value()) {
  case 0:
    ClearVisibilityList(PHYSICAL);
    break;
  case 1:
    ClearVisibilityList(ELEMENTARY);
    break;
  default:
    // partitions: do nothing
    break;
  }
  switch (WID->vis_browser_mode->value()) {
  case 0:
    mode = VIS_GEOM | VIS_MESH;
    CTX.mesh.changed = 1;
    break;
  case 1:
    mode = VIS_GEOM;
    break;
  default:
    mode = VIS_MESH;
    CTX.mesh.changed = 1;
    break;
  }

  for(i = 1; i <= WID->vis_browser->size(); i++) {
    e = (Entity *) WID->vis_browser->data(i);
    if(WID->vis_browser->selected(i)) {
      e->Visible(e->Visible() | mode);
    }
    else {
      switch (WID->vis_browser_mode->value()) {
      case 0:
        e->Visible(0);
        break;
      case 1:
        if(e->Visible() & VIS_MESH)
          e->Visible(VIS_MESH);
        else
          e->Visible(0);
        break;
      default:
        if(e->Visible() & VIS_GEOM)
          e->Visible(VIS_GEOM);
        else
          e->Visible(0);
        break;
      }
    }
  }

  if(WID->vis_butt[0]->value()) {
    for(i = 1; i <= WID->vis_browser->size(); i++) {
      e = (Entity *) WID->vis_browser->data(i);
      e->RecurVisible();
    }
    select_vis_browser(mode);
  }

  Draw();
}

void visibility_sort_cb(CALLBACK_ARGS)
{
  int i, val = (long int)data, selectall;

  if(!val) {
    selectall = 0;
    for(i = 1; i <= WID->vis_browser->size(); i++)
      if(!WID->vis_browser->selected(i)) {
        selectall = 1;
        break;
      }
    if(selectall)
      for(i = 1; i <= WID->vis_browser->size(); i++)
        WID->vis_browser->select(i);
    else
      WID->vis_browser->deselect();
  }
  else {
    SetVisibilitySort(val);
    visibility_cb(NULL, NULL);
  }
}

void visibility_number_cb(CALLBACK_ARGS)
{
  int pos, mode, type = WID->vis_input_mode->value(), val = (long int)data;
  char *str = (char *)WID->vis_input->value();

  if(val){ // show
    switch (WID->vis_browser_mode->value()) {
    case 0:
      mode = VIS_GEOM | VIS_MESH;
      CTX.mesh.changed = 1;
      break;
    case 1:
      mode = VIS_GEOM;
      break;
    default:
      mode = VIS_MESH;
      CTX.mesh.changed = 1;
      break;
    }
  }
  else{ // hide
    mode = 0;
    CTX.mesh.changed = 1;
  }

  SetVisibilityByNumber(str, type, mode);
  pos = WID->vis_browser->position();
  visibility_cb(NULL, NULL);
  WID->vis_browser->position(pos);

  Draw();
}

// Help Menu

// The fltk guys still have to decide how to map apple keys. Let's
// just keep the "Windows-Unix" style stuff at the moment. We might
// want to change all occurences of FL_CTRL with FL_COMMAND in the
// future. FL_COMMAND would get mapped to Ctrl on Windows/Unix and to
// Cmd on Macs.
#if 0
#define XX "Cmd "
#else
#define XX "Ctrl"
#endif

// If you change the following, please also change the texinfo
// documentation (doc/texinfo/shortcuts.texi)

void help_short_cb(CALLBACK_ARGS)
{
  Msg(DIRECT, " ");
  Msg(DIRECT, "Keyboard shortcuts:");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Left arrow    go to previous time step"); 
  Msg(DIRECT, "  Right arrow   go to next time step"); 
  Msg(DIRECT, "  Up arrow      make previous view visible"); 
  Msg(DIRECT, "  Down arrow    make next view visible"); 
  Msg(DIRECT, "  <             go back to previous context");
  Msg(DIRECT, "  >             go forward to next context");
  Msg(DIRECT, "  0 or Esc      reload geometry input file");
  Msg(DIRECT, "  1 or F1       mesh lines");
  Msg(DIRECT, "  2 or F2       mesh surfaces");
  Msg(DIRECT, "  3 or F3       mesh volumes");
  Msg(DIRECT, "  Alt+a         hide/show small axes"); 
  Msg(DIRECT, "  Shift+a       raise (show) all open windows");
  Msg(DIRECT, "  Alt+Shift+a   hide/show big moving axes"); 
  Msg(DIRECT, "  Alt+b         hide/show all post-processing scales");
  Msg(DIRECT, "  Alt+c         loop through predefined color schemes");
  Msg(DIRECT, "  Alt+d         change mesh display mode (solid/wireframe)");
  Msg(DIRECT, "  Shift+d       decrease animation delay");
  Msg(DIRECT, "  "XX"+Shift+d  increase animation delay");
  Msg(DIRECT, "  Alt+f         change redraw mode (fast/full)"); 
  Msg(DIRECT, "  g             go to geometry module");
  Msg(DIRECT, "  Shift+g       show geometry options");
  Msg(DIRECT, "  Alt+h         hide/show all post-processing views"); 
  Msg(DIRECT, "  Shift+i       show statistics window"); 
  Msg(DIRECT, "  Alt+l         hide/show geometry lines");
  Msg(DIRECT, "  Alt+Shift+l   hide/show surface mesh edges");
  Msg(DIRECT, "  m             go to mesh module");
  Msg(DIRECT, "  Alt+m         change visibility of all mesh entities");
  Msg(DIRECT, "  Shift+m       show mesh options");
  Msg(DIRECT, "  "XX"+m        merge file"); 
  Msg(DIRECT, "  Shift+n       show general options"); 
  Msg(DIRECT, "  "XX"+n        new file"); 
  Msg(DIRECT, "  Alt+o         change projection mode (ortho/perspective)");
  Msg(DIRECT, "  Shift+o       show option window"); 
  Msg(DIRECT, "  "XX"+o        open file"); 
  Msg(DIRECT, "  p             go to post-processor module");
  Msg(DIRECT, "  Alt+p         hide/show geometry points");
  Msg(DIRECT, "  Shift+p       show general post-processing options");
  Msg(DIRECT, "  Alt+Shift+p   hide/show mesh points");
  Msg(DIRECT, "  "XX"+q        quit");
  Msg(DIRECT, "  Alt+s         hide/show geometry surfaces");
  Msg(DIRECT, "  Alt+Shift+s   hide/show mesh surfaces");
  Msg(DIRECT, "  "XX"+s        save mesh in default format");
  Msg(DIRECT, "  "XX"+Shift+s  save file as");
  Msg(DIRECT, "  Alt+t         loop through interval modes for all post-processing views"); 
  Msg(DIRECT, "  Alt+v         hide/show geometry volumes");
  Msg(DIRECT, "  Alt+Shift+v   hide/show mesh volumes");
  Msg(DIRECT, "  Alt+w         enable/disable all lighting");
  Msg(DIRECT, "  Shift+w       show current post-processing view options");
  Msg(DIRECT, "  Alt+x         set X view"); 
  Msg(DIRECT, "  Alt+y         set Y view"); 
  Msg(DIRECT, "  Alt+z         set Z view"); 
  Msg(DIRECT, " ");
  WID->create_message_window();
}

void help_mouse_cb(CALLBACK_ARGS)
{
  Msg(DIRECT, " ");
  Msg(DIRECT, "Mouse actions:");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  move                - highlight the elementary geometrical entity");
  Msg(DIRECT, "                        currently under the mouse pointer and display");
  Msg(DIRECT, "                        its properties in the status bar");
  Msg(DIRECT, "                      - size a rubber zoom started with "XX"+Left button");
  Msg(DIRECT, "  Left button         - rotate");
  Msg(DIRECT, "                      - accept a rubber zoom started with "XX"+Left button"); 
  Msg(DIRECT, "  "XX"+Left button     start (anisotropic) rubber zoom"); 
  Msg(DIRECT, "  Middle button       - zoom (isotropic)");
  Msg(DIRECT, "                      - cancel a rubber zoom");
  Msg(DIRECT, "  "XX"+Middle button  orthogonalize display"); 
  Msg(DIRECT, "  Right button        - pan");
  Msg(DIRECT, "                      - cancel a rubber zoom");
  Msg(DIRECT, "                      - pop up menu on post-processing view button");
  Msg(DIRECT, "  "XX"+Right button   reset to default viewpoint");   
  Msg(DIRECT, " ");   
  Msg(DIRECT, "  For a 2 button mouse, Middle button = Shift+Left button");
  Msg(DIRECT, "  For a 1 button mouse, Middle button = Shift+Left button, Right button = Alt+Left button");
  Msg(DIRECT, " ");
  WID->create_message_window();
}

#undef XX

void help_command_line_cb(CALLBACK_ARGS)
{
  Msg(DIRECT, " ");
  Print_Usage("gmsh");
  WID->create_message_window();
}

void help_license_cb(CALLBACK_ARGS)
{
  extern void print_license();
  Msg(DIRECT, " ");
  print_license();
  WID->create_message_window();
}

void help_about_cb(CALLBACK_ARGS)
{
  WID->create_about_window();
}

void _replace_multi_format(char *in, char *val, char *out){
  unsigned int i = 0, j = 0;

  out[0] = '\0';
  while(i < strlen(in)){
    if(in[i] == '%' && i != strlen(in)-1){
      if(in[i+1] == 's'){
	strcat(out, val);
	i += 2;
	j += strlen(val);
      }
      else{
	Msg(WARNING, "Skipping unknown format '%%%c' in '%s'", in[i+1], in);
	i += 2;
      }
    }
    else{
      out[j] = in[i];
      out[j+1] = '\0';
      i++;
      j++;
    }
  }
  out[j] = '\0';
}

void help_online_cb(CALLBACK_ARGS)
{
  char cmd[1000];
  _replace_multi_format(CTX.web_browser, "http://www.geuz.org/gmsh/doc/texinfo/", cmd);
  SystemCall(cmd);
}

// Module Menu

void mod_geometry_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry, 0);
}

void mod_mesh_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_mesh, 0);
}

void mod_solver_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_solver, 0);
}

void mod_post_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_post, 0);
}

void mod_back_cb(CALLBACK_ARGS)
{
  WID->set_context(NULL, -1);
}

void mod_forward_cb(CALLBACK_ARGS)
{
  WID->set_context(NULL, 1);
}

// Dynamic Geomtry Menus

void geometry_elementary_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary, 0);
}

void geometry_physical_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_physical, 0);
}

void geometry_edit_cb(CALLBACK_ARGS)
{
  char cmd[1000];
  _replace_multi_format(CTX.editor, CTX.filename, cmd);
  SystemCall(cmd);
}

void geometry_reload_cb(CALLBACK_ARGS)
{
  OpenProblem(CTX.filename);
  Draw();
}

void geometry_elementary_add_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add, 0);
}

void geometry_elementary_add_new_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_new, 0);
}

void geometry_elementary_add_new_parameter_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(0);
}

void geometry_elementary_add_new_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(1);
}

static void _new_multiline(int type)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int n, p[100];

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  n = 0;
  while(1) {
    Msg(STATUS3N, "Creating curve");
    if(n == 0)
      Msg(ONSCREEN, "Select control points\n"
	  "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg(ONSCREEN, "Select control points\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &v, &c, &s);
    if(ib == 'l') {
      p[n++] = v->Num;
    }
    if(ib == 'e') {
      if(n >= 2) {
        switch (type) {
        case 0:
          add_multline(n, p, CTX.filename);
          break;
        case 1:
          add_spline(n, p, CTX.filename);
          break;
        case 2:
          add_bspline(n, p, CTX.filename);
          break;
        case 3:
          add_bezier(n, p, CTX.filename);
          break;
        }
      }
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0);
	Draw(); // inefficient, but hard to do otherwise
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
  }

  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void geometry_elementary_add_new_line_cb(CALLBACK_ARGS)
{
  // Disallow multiline selection at the moment, since multilines
  // dont't work so well...
  //
  //_new_multiline(0);
  //
  Vertex *v;
  Curve *c;
  Surface *s;
  int n, p[100];

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  n = 0;
  while(1) {
    Msg(STATUS3N, "Creating straight line");
    if(n == 0)
      Msg(ONSCREEN, "Select start point\n"
	  "[Press 'q' to abort]");
    if(n == 1)
      Msg(ONSCREEN, "Select end point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &v, &c, &s);
    if(ib == 'l') {
      p[n++] = v->Num;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0);
	Draw(); // inefficient, but hard to do otherwise
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(n == 2) {
      add_multline(2, p, CTX.filename);
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
  }

  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void geometry_elementary_add_new_spline_cb(CALLBACK_ARGS)
{
  _new_multiline(1);
}

void geometry_elementary_add_new_bspline_cb(CALLBACK_ARGS)
{
  _new_multiline(2);
}

void geometry_elementary_add_new_circle_cb(CALLBACK_ARGS)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int n, p[100];

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  n = 0;
  while(1) {
    Msg(STATUS3N, "Creating circle");
    if(n == 0)
      Msg(ONSCREEN, "Select start point\n"
	  "[Press 'q' to abort]");
    if(n == 1)
      Msg(ONSCREEN, "Select center point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    if(n == 2)
      Msg(ONSCREEN, "Select end point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &v, &c, &s);
    if(ib == 'l') {
      p[n++] = v->Num;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0);
	Draw(); // inefficient, but hard to do otherwise
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(n == 3) {
      add_circ(p[0], p[1], p[2], CTX.filename); /* begin, center, end */
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
  }

  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void geometry_elementary_add_new_ellipse_cb(CALLBACK_ARGS)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int n, p[100];

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  n = 0;
  while(1) {
    Msg(STATUS3N, "Creating ellipse");
    if(n == 0)
      Msg(ONSCREEN, "Select start point\n"
	  "[Press 'q' to abort]");
    if(n == 1)
      Msg(ONSCREEN, "Select center point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    if(n == 2)
      Msg(ONSCREEN, "Select major axis point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    if(n == 3)
      Msg(ONSCREEN, "Select end point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &v, &c, &s);
    if(ib == 'l') {
      p[n++] = v->Num;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0);
	Draw(); // inefficient, but hard to do otherwise
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(n == 4) {
      add_ell(p[0], p[1], p[2], p[3], CTX.filename);
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
  }

  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

static void _new_surface_volume(int mode)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int type, num;

  List_T *List1 = List_Create(10, 10, sizeof(int));
  List_T *List2 = List_Create(10, 10, sizeof(int));

  if(mode == 2) {
    type = ENT_SURFACE;
    if(!opt_geometry_surfaces(0, GMSH_GET, 0)) {
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }
  else {
    type = ENT_LINE;
    if(!opt_geometry_lines(0, GMSH_GET, 0)) {
      opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }

  while(1) {
    List_Reset(List1);
    List_Reset(List2);

    while(1) {
      if(type == ENT_LINE){
	Msg(STATUS3N, "Creating surface");
	if(!List_Nbr(List1))
	  Msg(ONSCREEN, "Select surface boundary\n"
	      "[Press 'q' to abort]");
	else
	  Msg(ONSCREEN, "Select surface boundary\n"
	      "[Press 'u' to undo last selection or 'q' to abort]");
      }
      else{
	Msg(STATUS3N, "Creating volume");
	if(!List_Nbr(List1))
	  Msg(ONSCREEN, "Select volume boundary\n"
	      "[Press 'q' to abort]");
	else
	  Msg(ONSCREEN, "Select volume boundary\n"
	      "[Press 'u' to undo last selection or 'q' to abort]");
      }

      char ib = SelectEntity(type, &v, &c, &s);
      if(ib == 'q') {
        ZeroHighlight(THEM);
        Draw();
        goto stopall;
      }
      if(ib == 'u') {
	if(List_Nbr(List1) > 0){
	  List_Read(List1, List_Nbr(List1)-1, &num);	    
	  ZeroHighlightEntityNum(0,
				 (type == ENT_LINE) ? abs(num) : 0, 
				 (type != ENT_LINE) ? abs(num) : 0);
	  List_Pop(List1);
	  Draw();
	}
      }
      if(ib == 'l') {
	int num = (type == ENT_LINE) ? c->Num : s->Num;
	if(SelectContour(type, num, List1)) {
	  if(type == ENT_LINE)
	    add_loop(List1, CTX.filename, &num);
	  else
	    add_vol(List1, CTX.filename, &num);
	  List_Reset(List1);
	  List_Add(List2, &num);
	  while(1) {
	    if(!List_Nbr(List1))
	      Msg(ONSCREEN, "Select hole boundaries (if none, press 'e')\n"
		  "[Press 'e' to end selection or 'q' to abort]");
	    else
	      Msg(ONSCREEN, "Select hole boundaries\n"
		  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
	    ib = SelectEntity(type, &v, &c, &s);
	    if(ib == 'q') {
	      ZeroHighlight(THEM);
	      Draw();
	      goto stopall;
	    }
	    if(ib == 'e') {
	      ZeroHighlight(THEM);
	      Draw();
	      List_Reset(List1);
	      break;
	    }
	    if(ib == 'u') {
	      if(List_Nbr(List1) > 0){
		List_Read(List1, List_Nbr(List1)-1, &num);	    
		ZeroHighlightEntityNum(0,
				       (type == ENT_LINE) ? abs(num) : 0, 
				       (type != ENT_LINE) ? abs(num) : 0);
		List_Pop(List1);
		Draw();
	      }
	    }
	    if(ib == 'l') {
	      num = (type == ENT_LINE) ? c->Num : s->Num;
	      if(SelectContour(type, num, List1)) {
		if(type == ENT_LINE)
		  add_loop(List1, CTX.filename, &num);
		else
		  add_vol(List1, CTX.filename, &num);
		List_Reset(List1);
		List_Add(List2, &num);
	      }
	    }
	  }
	  if(List_Nbr(List2)) {
	    switch (mode) {
	    case 0: add_surf(List2, CTX.filename, 0, 2); break;
	    case 1: add_surf(List2, CTX.filename, 0, 1); break;
	    case 2: add_multvol(List2, CTX.filename); break;
	    }
	    ZeroHighlight(THEM);
	    Draw();
	    break;
	  }
	} // if SelectContour
      }
    }
  }

stopall:;
  List_Delete(List1);
  List_Delete(List2);
  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void geometry_elementary_add_new_planesurface_cb(CALLBACK_ARGS)
{
  _new_surface_volume(0);
}

void geometry_elementary_add_new_ruledsurface_cb(CALLBACK_ARGS)
{
  _new_surface_volume(1);
}

void geometry_elementary_add_new_volume_cb(CALLBACK_ARGS)
{
  _new_surface_volume(2);
}

static void _transform_point_line_surface(int transfo, int mode, char *what)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int type, num = 0;
  char *str;

  if(!strcmp(what, "Point")) {
    type = ENT_POINT;
    str = "point";
    if(!opt_geometry_points(0, GMSH_GET, 0)) {
      opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }
  else if(!strcmp(what, "Line")) {
    type = ENT_LINE;
    str = "line";
    if(!opt_geometry_lines(0, GMSH_GET, 0)) {
      opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }
  else {
    type = ENT_SURFACE;
    str = "surface";
    if(!opt_geometry_surfaces(0, GMSH_GET, 0)) {
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }

  Msg(ONSCREEN, "Select %s\n[Press 'q' to abort]", str);

  while(1) {
    Msg(STATUS3N, "Transforming %s", str);
    char ib = SelectEntity(type, &v, &c, &s);
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(ib == 'l') {
      switch (type) {
      case ENT_POINT:
	num = v->Num;
	break;
      case ENT_LINE:
	num = c->Num;
	break;
      case ENT_SURFACE:
	num = s->Num;
	break;
      }
      switch (transfo) {
      case 0:
	translate(mode, num, CTX.filename, what,
		  (char*)WID->context_geometry_input[6]->value(),
		  (char*)WID->context_geometry_input[7]->value(),
		  (char*)WID->context_geometry_input[8]->value());
	break;
      case 1:
	rotate(mode, num, CTX.filename, what,
	       (char*)WID->context_geometry_input[12]->value(),
	       (char*)WID->context_geometry_input[13]->value(),
	       (char*)WID->context_geometry_input[14]->value(),
	       (char*)WID->context_geometry_input[9]->value(),
	       (char*)WID->context_geometry_input[10]->value(),
	       (char*)WID->context_geometry_input[11]->value(),
	       (char*)WID->context_geometry_input[15]->value());
	break;
      case 2:
	dilate(mode, num, CTX.filename, what,
	       (char*)WID->context_geometry_input[16]->value(),
	       (char*)WID->context_geometry_input[17]->value(),
	       (char*)WID->context_geometry_input[18]->value(),
	       (char*)WID->context_geometry_input[19]->value());
	break;
      case 3:
	symmetry(mode, num, CTX.filename, what,
		 (char*)WID->context_geometry_input[20]->value(),
		 (char*)WID->context_geometry_input[21]->value(),
		 (char*)WID->context_geometry_input[22]->value(),
		 (char*)WID->context_geometry_input[23]->value());
	break;
      case 4:
	extrude(num, CTX.filename, what,
		(char*)WID->context_geometry_input[6]->value(),
		(char*)WID->context_geometry_input[7]->value(),
		(char*)WID->context_geometry_input[8]->value());
	break;
      case 5:
	protude(num, CTX.filename, what,
		(char*)WID->context_geometry_input[12]->value(),
		(char*)WID->context_geometry_input[13]->value(),
		(char*)WID->context_geometry_input[14]->value(),
		(char*)WID->context_geometry_input[9]->value(),
		(char*)WID->context_geometry_input[10]->value(),
		(char*)WID->context_geometry_input[11]->value(),
		(char*)WID->context_geometry_input[15]->value());
	break;
      case 6:
	delet(num, CTX.filename, what);
	break;
      }
      ZeroHighlight(THEM);
      CalculateMinMax(THEM->Points, NULL);
      Draw();
    }
  }

  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void geometry_elementary_add_translate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_translate, 0);
}

void geometry_elementary_add_translate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(0, 1, "Point");
}

void geometry_elementary_add_translate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(0, 1, "Line");
}

void geometry_elementary_add_translate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(0, 1, "Surface");
}

void geometry_elementary_translate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_translate, 0);
}

void geometry_elementary_translate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(0, 0, "Point");
}

void geometry_elementary_translate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(0, 0, "Line");
}

void geometry_elementary_translate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(0, 0, "Surface");
}

void geometry_elementary_add_rotate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_rotate, 0);
}

void geometry_elementary_add_rotate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(1, 1, "Point");
}

void geometry_elementary_add_rotate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(1, 1, "Line");
}

void geometry_elementary_add_rotate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(1, 1, "Surface");
}

void geometry_elementary_rotate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_rotate, 0);
}

void geometry_elementary_rotate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(1, 0, "Point");
}

void geometry_elementary_rotate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(1, 0, "Line");
}

void geometry_elementary_rotate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(1, 0, "Surface");
}

void geometry_elementary_add_scale_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_scale, 0);
}

void geometry_elementary_add_scale_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _transform_point_line_surface(2, 1, "Point");
}

void geometry_elementary_add_scale_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _transform_point_line_surface(2, 1, "Line");
}

void geometry_elementary_add_scale_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _transform_point_line_surface(2, 1, "Surface");
}

void geometry_elementary_scale_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_scale, 0);
}

void geometry_elementary_scale_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _transform_point_line_surface(2, 0, "Point");
}

void geometry_elementary_scale_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _transform_point_line_surface(2, 0, "Line");
}

void geometry_elementary_scale_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _transform_point_line_surface(2, 0, "Surface");
}

void geometry_elementary_add_symmetry_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_symmetry, 0);
}

void geometry_elementary_add_symmetry_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _transform_point_line_surface(3, 1, "Point");
}

void geometry_elementary_add_symmetry_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _transform_point_line_surface(3, 1, "Line");
}

void geometry_elementary_add_symmetry_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _transform_point_line_surface(3, 1, "Surface");
}

void geometry_elementary_symmetry_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_symmetry, 0);
}

void geometry_elementary_symmetry_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _transform_point_line_surface(3, 0, "Point");
}

void geometry_elementary_symmetry_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _transform_point_line_surface(3, 0, "Line");
}

void geometry_elementary_symmetry_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _transform_point_line_surface(3, 0, "Surface");
}

void geometry_elementary_extrude_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_extrude, 0);
}

void geometry_elementary_extrude_translate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_extrude_translate, 0);
}

void geometry_elementary_extrude_translate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(4, 0, "Point");
}

void geometry_elementary_extrude_translate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(4, 0, "Line");
}

void geometry_elementary_extrude_translate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _transform_point_line_surface(4, 0, "Surface");
}

void geometry_elementary_extrude_rotate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_extrude_rotate, 0);
}

void geometry_elementary_extrude_rotate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(5, 0, "Point");
}

void geometry_elementary_extrude_rotate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(5, 0, "Line");
}

void geometry_elementary_extrude_rotate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _transform_point_line_surface(5, 0, "Surface");
}

void geometry_elementary_delete_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_delete, 0);
}

void geometry_elementary_delete_point_cb(CALLBACK_ARGS)
{
  _transform_point_line_surface(6, 0, "Point");
}

void geometry_elementary_delete_line_cb(CALLBACK_ARGS)
{
  _transform_point_line_surface(6, 0, "Line");
}

void geometry_elementary_delete_surface_cb(CALLBACK_ARGS)
{
  _transform_point_line_surface(6, 0, "Surface");
}

static void _add_physical(char *what)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int type, num;
  char *str;
  List_T *List1;

  if(!strcmp(what, "Point")) {
    type = ENT_POINT;
    str = "points";
    if(!opt_geometry_points(0, GMSH_GET, 0)) {
      opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }
  else if(!strcmp(what, "Line")) {
    type = ENT_LINE;
    str = "lines";
    if(!opt_geometry_lines(0, GMSH_GET, 0)) {
      opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }
  else if(!strcmp(what, "Surface")) {
    type = ENT_SURFACE;
    str = "surfaces";
    if(!opt_geometry_surfaces(0, GMSH_GET, 0)) {
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
  }
  else {
    type = ENT_VOLUME;
    str = "volumes";
    if(!opt_geometry_volumes(0, GMSH_GET, 0)) {
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
    Msg(GERROR, "Interactive volume selection not done "
        "(you will have to edit the input file manually)");
    return;
  }

  List1 = List_Create(5, 5, sizeof(int));
  while(1) {
    Msg(STATUS3N, "Creating physical %s", str);
    if(!List_Nbr(List1))
      Msg(ONSCREEN, "Select %s\n"
	  "[Press 'e' to end selection or 'q' to abort]", str);
    else
      Msg(ONSCREEN, "Select %s\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]", str);
    char ib = SelectEntity(type, &v, &c, &s);
    if(ib == 'l') {
      switch (type) {
      case ENT_POINT:
        List_Add(List1, &v->Num);
        break;
      case ENT_LINE:
        List_Add(List1, &c->Num);
        break;
      case ENT_SURFACE:
        List_Add(List1, &s->Num);
        break;
      }
    }
    if(ib == 'u') {
      if(List_Nbr(List1)) {
	List_Read(List1, List_Nbr(List1)-1, &num);
	ZeroHighlightEntityNum((type == ENT_POINT) ? num : 0,
			       (type == ENT_LINE) ? num : 0,
			       (type == ENT_SURFACE) ? num : 0);
	Draw(); // inefficient, but hard to do otherwise
	List_Pop(List1);
      }
    }
    if(ib == 'e') {
      if(List_Nbr(List1)) {
        add_physical(List1, CTX.filename, type, &num);
        List_Reset(List1);
        ZeroHighlight(THEM);
        Draw();
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
  }
  List_Delete(List1);
  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void geometry_physical_add_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_physical_add, 0);
}

void geometry_physical_add_point_cb(CALLBACK_ARGS)
{
  _add_physical("Point");
}

void geometry_physical_add_line_cb(CALLBACK_ARGS)
{
  _add_physical("Line");
}

void geometry_physical_add_surface_cb(CALLBACK_ARGS)
{
  _add_physical("Surface");
}

void geometry_physical_add_volume_cb(CALLBACK_ARGS)
{
  _add_physical("Volume");
}

// Dynamic Mesh Menus

void mesh_save_cb(CALLBACK_ARGS)
{
  Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
}

void mesh_save_all_cb(CALLBACK_ARGS)
{
  int all = CTX.mesh.save_all;
  CTX.mesh.save_all = 1;
  Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
  CTX.mesh.save_all = all;
}

void mesh_define_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_mesh_define, 0);
}

void mesh_1d_cb(CALLBACK_ARGS)
{
  mai3d(THEM, 1);
  Draw();
  Msg(STATUS3N, "Ready");
}

void mesh_2d_cb(CALLBACK_ARGS)
{
  mai3d(THEM, 2);
  Draw();
  Msg(STATUS3N, "Ready");
}

void mesh_3d_cb(CALLBACK_ARGS)
{
  mai3d(THEM, 3);
  Draw();
  Msg(STATUS3N, "Ready");
}

void mesh_degree_cb(CALLBACK_ARGS)
{
  switch ((long int)data) {
  case 2: 
    Degre2(THEM->status);
    break;
  case 1:
  default:
    Degre1();
    break;
  }
  CTX.mesh.changed = 1;
  Draw();
  Msg(STATUS3N, "Ready");
}

void mesh_optimize_cb(CALLBACK_ARGS)
{
  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;
  Optimize_Netgen(THEM);
  CTX.threads_lock = 0;

  CTX.mesh.changed = 1;
  Draw();
  Msg(STATUS3N, "Ready");
}

void mesh_define_length_cb(CALLBACK_ARGS)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int n = 0, p[100];

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  WID->create_mesh_context_window(0);

  while(1) {
    Msg(STATUS3N, "Setting characteristic length");
    if(n == 0)
      Msg(ONSCREEN, "Select points\n"
	  "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg(ONSCREEN, "Select points\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &v, &c, &s);
    if(ib == 'l') {
      p[n++] = v->Num;
    }
    if(ib == 'e') {
      if(n > 0)
        add_charlength(n, p, CTX.filename, (char*)WID->context_mesh_input[0]->value());
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0);
	Draw(); // inefficient, but hard to do otherwise
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
  }
  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void mesh_define_recombine_cb(CALLBACK_ARGS)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  int n, p[100];

  if(!opt_geometry_surfaces(0, GMSH_GET, 0)) {
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  n = 0;
  while(1) {
    Msg(STATUS3N, "Selecting recombined surfaces");
    if(n == 0)
      Msg(ONSCREEN, "Select surfaces\n"
	  "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg(ONSCREEN, "Select surfaces\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_SURFACE, &v, &c, &s);
    if(ib == 'l') {
      p[n++] = s->Num;
    }
    if(ib == 'e') {
      if(n > 0)
        add_recosurf(n, p, CTX.filename);
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(0, 0, p[n-1]);
	Draw(); // inefficient, but hard to do otherwise
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
  }
  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void mesh_define_transfinite_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_mesh_define_transfinite, 0);
}

static void _add_transfinite(int dim)
{
  Vertex *v;
  Curve *c;
  Surface *s;
  char ib;
  int n, p[100];

  if(!opt_geometry_points(0, GMSH_GET, 0)) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
    Draw();
  }

  switch (dim) {
  case 1:
    if(!opt_geometry_lines(0, GMSH_GET, 0)) {
      opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
    break;
  case 2:
    if(!opt_geometry_surfaces(0, GMSH_GET, 0)) {
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
    break;
  case 3:
    if(!opt_geometry_volumes(0, GMSH_GET, 0)) {
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
      Draw();
    }
    break;
  }

  n = 0;
  while(1) {
    Msg(STATUS3N, "Setting transfinite contraints");
    switch (dim) {
    case 1:
      if(n == 0)
	Msg(ONSCREEN, "Select lines\n"
	    "[Press 'e' to end selection or 'q' to abort]");
      else
	Msg(ONSCREEN, "Select lines\n"
	    "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
      ib = SelectEntity(ENT_LINE, &v, &c, &s);
      break;
    case 2:
      Msg(ONSCREEN, "Select surface\n[Press 'q' to abort]");
      ib = SelectEntity(ENT_SURFACE, &v, &c, &s);
      break;
    default:
      ib = 'l';
      break;
    }

    if(ib == 'e') {
      if(dim == 1) {
        if(n > 0)
          add_trsfline(n, p, CTX.filename,
		       (char*)WID->context_mesh_choice[0]->text(),
		       (char*)WID->context_mesh_input[2]->value(),
		       (char*)WID->context_mesh_input[1]->value());
      }
      ZeroHighlight(THEM);
      Draw();
      n = 0;
    }
    if(ib == 'u') {
      if(dim == 1) {
        if(n > 0){
	  ZeroHighlightEntityNum(0, p[n-1], 0);
	  Draw(); // inefficient, but hard to do otherwise
	  n--;
	}
      }
    }
    if(ib == 'q') {
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(ib == 'l') {
      switch (dim) {
      case 1:
        p[n++] = c->Num;
        break;
      case 2:
        p[n++] = s->Num; // fall-through
      case 3:
        while(1) {
	  if(n == ((dim == 2) ? 1 : 0))
	    Msg(ONSCREEN, "Select (ordered) boundary points\n"
		"[Press 'e' to end selection or 'q' to abort]");
	  else
	    Msg(ONSCREEN, "Select (ordered) boundary points\n"
		"[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
          ib = SelectEntity(ENT_POINT, &v, &c, &s);
          if(ib == 'l') {
            p[n++] = v->Num;
          }
	  if(ib == 'u') {
	    if(n > ((dim == 2) ? 1 : 0)){
	      ZeroHighlightEntityNum(p[n-1], 0, 0);
	      Draw(); // inefficient, but hard to do otherwise
	      n--;
	    }
	  }
          if(ib == 'e') {
            switch (dim) {
            case 2:
              if(n == 3 + 1 || n == 4 + 1)
                add_trsfsurf(n, p, CTX.filename);
              else
                Msg(GERROR, "Wrong number of points for transfinite surface");
              break;
            case 3:
              if(n == 6 || n == 8)
                add_trsfvol(n, p, CTX.filename, 
			    (char*)WID->context_mesh_input[3]->value());
              else
                Msg(GERROR, "Wrong number of points for transfinite volume");
              break;
            }
            ZeroHighlight(THEM);
            Draw();
            n = 0;
            break;
          }
          if(ib == 'q') {
            ZeroHighlight(THEM);
            Draw();
            goto stopall;
          }
        }
        break;
      }
    }
  }

stopall:
  Msg(STATUS3N, "Ready");
  Msg(ONSCREEN, "");
}

void mesh_define_transfinite_line_cb(CALLBACK_ARGS)
{
  WID->create_mesh_context_window(1);
  _add_transfinite(1);
}

void mesh_define_transfinite_surface_cb(CALLBACK_ARGS)
{
  _add_transfinite(2);
}

void mesh_define_transfinite_volume_cb(CALLBACK_ARGS)
{
  WID->create_mesh_context_window(2);
  _add_transfinite(3);
}

// Dynamic Solver Menus

#include "Solvers.h"

void solver_cb(CALLBACK_ARGS)
{
  char file[256], tmp[256];
  static int init = 0, first[MAXSOLVERS];
  int i, num = (int)data;

  if(!init) {
    for(i = 0; i < MAXSOLVERS; i++)
      first[i] = 1;
    init = 1;
  }

  if(first[num]) {
    first[num] = 0;
    strcpy(file, CTX.base_filename);
    strcat(file, SINFO[num].extension);
    WID->solver[num].input[0]->value(file);
  }
  if(SINFO[num].nboptions) {
    sprintf(tmp, "%s \"%s\"", SINFO[num].option_command,
            (char *)WID->solver[num].input[0]->value());
    Solver(num, tmp);
  }
  WID->create_solver_window(num);
}

void solver_file_open_cb(CALLBACK_ARGS)
{
  char tmp[256];
  int num = (int)data;
  sprintf(tmp, "*%s", SINFO[num].extension);

  // We allow to create the .pro file... Or should we add a "New file"
  // button?
  if(file_chooser(0, 1, "Open problem definition file", tmp, 0)) {
    WID->solver[num].input[0]->value(file_chooser_get_name(1));
    if(SINFO[num].nboptions) {
      sprintf(tmp, "%s \"%s\"", SINFO[num].option_command,
              file_chooser_get_name(1));
      Solver(num, tmp);
    }
  }
}
void solver_file_edit_cb(CALLBACK_ARGS)
{
  char cmd[1000];
  int num = (int)data;
  sprintf(cmd, CTX.editor, WID->solver[num].input[0]->value());
  SystemCall(cmd);
}

void solver_choose_mesh_cb(CALLBACK_ARGS)
{
  int num = (int)data;
  if(file_chooser(0, 0, "Open mesh file", "*.msh", 0))
    WID->solver[num].input[1]->value(file_chooser_get_name(1));
}
int nbs(char *str)
{
  int i, nb = 0;
  for(i = 0; i < (int)strlen(str) - 1; i++) {
    if(str[i] == '%' && str[i + 1] == 's') {
      nb++;
      i++;
    }
  }
  return nb;
}

void solver_command_cb(CALLBACK_ARGS)
{
  char tmp[256], arg[512], mesh[256], command[256];
  int num = ((int *)data)[0];
  int idx = ((int *)data)[1];
  int i, usedopts = 0;

  if(SINFO[num].popup_messages)
    WID->create_message_window();

  if(strlen(WID->solver[num].input[1]->value())) {
    sprintf(tmp, "\"%s\"", WID->solver[num].input[1]->value());
    sprintf(mesh, SINFO[num].mesh_command, tmp);
  }
  else {
    strcpy(mesh, "");
  }

  //printf("num%d idx%d %s -> %d\n", 
  //     num, idx, SINFO[num].button_command[idx], nbs(SINFO[num].button_command[idx]));

  if(nbs(SINFO[num].button_command[idx])) {
    for(i = 0; i < idx; i++)
      usedopts += nbs(SINFO[num].button_command[i]);
    if(usedopts > SINFO[num].nboptions) {
      Msg(GERROR, "Missing options to execute command");
      return;
    }
    sprintf(command, SINFO[num].button_command[idx],
            SINFO[num].option[usedopts][WID->solver[num].choice[usedopts]->
                                        value()]);
  }
  else {
    strcpy(command, SINFO[num].button_command[idx]);
  }

  sprintf(arg, "\"%s\" %s %s", WID->solver[num].input[0]->value(), mesh,
          command);

  Solver(num, arg);
}

void solver_kill_cb(CALLBACK_ARGS)
{
  int num = (int)data;
  if(SINFO[num].pid > 0) {
    kill(SINFO[num].pid, 9);
    Msg(INFO, "Killed %s pid %d", SINFO[num].name, SINFO[num].pid);
  }
  SINFO[num].pid = -1;
}

void solver_choose_executable_cb(CALLBACK_ARGS)
{
  int num = (int)data;
  if(file_chooser(0, 0, "Choose executable",
#if defined(WIN32)
                  "*.exe"
#else
                  "*"
#endif
                  , 0))
    WID->solver[num].input[2]->value(file_chooser_get_name(1));
}

void solver_ok_cb(CALLBACK_ARGS)
{
  int num = (int)data;
  int retry = 0;
  opt_solver_popup_messages(num, GMSH_SET, WID->solver[num].butt[0]->value());
  opt_solver_merge_views(num, GMSH_SET, WID->solver[num].butt[1]->value());
  opt_solver_client_server(num, GMSH_SET, WID->solver[num].butt[2]->value());
  if(strcmp(opt_solver_executable(num, GMSH_GET, NULL),
            WID->solver[num].input[2]->value()))
    retry = 1;
  opt_solver_executable(num, GMSH_SET,
                        (char *)WID->solver[num].input[2]->value());
  if(retry)
    solver_cb(NULL, data);
}

// Dynamic Post Menus

void view_toggle_cb(CALLBACK_ARGS)
{
  opt_view_visible((long int)data, GMSH_SET,
                   WID->m_toggle_butt[(long int)data]->value());
  Draw();
}

static int RELOAD_ALL_VIEWS = 0;

void view_reload_all_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list)
    return;
  RELOAD_ALL_VIEWS = 1;
  for(int i = 0; i < List_Nbr(CTX.post.list); i++)
    view_reload_cb(NULL, (void *)i);
  RELOAD_ALL_VIEWS = 0;
  Draw();
}

void view_reload_visible_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list)
    return;
  RELOAD_ALL_VIEWS = 1;
  for(int i = 0; i < List_Nbr(CTX.post.list); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_reload_cb(NULL, (void *)i);
  RELOAD_ALL_VIEWS = 0;
  Draw();
}

void view_reload_cb(CALLBACK_ARGS)
{
  Post_View tmp;
  char filename[256];

  if(!CTX.post.list)
    return;

  Post_View *v = (Post_View *) List_Pointer(CTX.post.list, (long int)data);
  strcpy(filename, v->FileName);

  struct stat buf;
  if(stat(filename, &buf)){
    Msg(GERROR, "File '%s' does not exist", filename);
    return;
  }

  CopyViewOptions(v, &tmp);
  FreeView(v);

  CTX.post.force_num = v->Num;
  MergeProblem(filename);
  CTX.post.force_num = 0;

  v = (Post_View *) List_Pointer(CTX.post.list, (long int)data);
  CopyViewOptions(&tmp, v);

  // In case the reloaded view has a different number of time steps
  if(v->TimeStep > v->NbTimeStep - 1)
    v->TimeStep = 0;

  if(!RELOAD_ALL_VIEWS)
    Draw();
}

static int REMOVE_ALL_VIEWS = 0;

void view_remove_all_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list)
    return;
  REMOVE_ALL_VIEWS = 1;
  while(List_Nbr(CTX.post.list))
    view_remove_cb(NULL, (void *)0);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_visible_cb(CALLBACK_ARGS)
{
  int i;
  if(!CTX.post.list)
    return;
  REMOVE_ALL_VIEWS = 1;
  for(i = List_Nbr(CTX.post.list) - 1; i >= 0; i--)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_remove_cb(NULL, (void *)i);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_invisible_cb(CALLBACK_ARGS)
{
  int i;
  if(!CTX.post.list)
    return;
  REMOVE_ALL_VIEWS = 1;
  for(i = List_Nbr(CTX.post.list) - 1; i >= 0; i--)
    if(!opt_view_visible(i, GMSH_GET, 0))
      view_remove_cb(NULL, (void *)i);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_cb(CALLBACK_ARGS)
{
  RemoveViewByIndex((long int)data);

  if(!REMOVE_ALL_VIEWS)
    Draw();
}

void view_save_ascii_cb(CALLBACK_ARGS)
{
  Post_View *v = (Post_View *) List_Pointer(CTX.post.list, (long int)data);
  if(!v) return;
  
test:
  if(file_chooser(0, 1, "Save view in ASCII format", "*", 0, v->FileName)) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      struct stat buf;
      if(!stat(name, &buf))
        if(fl_ask("%s already exists.\nDo you want to replace it?", name))
          goto save;
        else
          goto test;
    }
  save:
    WriteView(v, name, 0, 0);
  }
}

void view_save_binary_cb(CALLBACK_ARGS)
{
  Post_View *v = (Post_View *) List_Pointer(CTX.post.list, (long int)data);
  if(!v) return;

test:
  if(file_chooser(0, 1, "Save view in binary format", "*", 0, v->FileName)) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      struct stat buf;
      if(!stat(name, &buf))
        if(fl_ask("%s already exists.\nDo you want to replace it?", name))
          goto save;
        else
          goto test;
    }
  save:
    WriteView(v, name, 1, 0);
  }
}

void view_duplicate_cb(CALLBACK_ARGS)
{
  DuplicateView((long int)data, 0);
  Draw();
}

void view_duplicate_with_options_cb(CALLBACK_ARGS)
{
  DuplicateView((long int)data, 1);
  Draw();
}

void view_combine_all_cb(CALLBACK_ARGS)
{
  CombineViews(1, 0);
  Draw();
}

void view_combine_all_and_remove_cb(CALLBACK_ARGS)
{
  CombineViews(1, 1);
  Draw();
}

void view_combine_visible_cb(CALLBACK_ARGS)
{
  CombineViews(0, 0);
  Draw();
}

void view_combine_visible_and_remove_cb(CALLBACK_ARGS)
{
  CombineViews(0, 1);
  Draw();
}

void view_combine_time_all_cb(CALLBACK_ARGS)
{
  CombineViews_Time(1, 0);
  Draw();
}

void view_combine_time_all_and_remove_cb(CALLBACK_ARGS)
{
  CombineViews_Time(1, 1);
  Draw();
}

void view_combine_time_visible_cb(CALLBACK_ARGS)
{
  CombineViews_Time(0, 0);
  Draw();
}

void view_combine_time_visible_and_remove_cb(CALLBACK_ARGS)
{
  CombineViews_Time(0, 1);
  Draw();
}

void view_combine_time_by_name_cb(CALLBACK_ARGS)
{
  CombineViews_Time(2, 0);
  Draw();
}

void view_combine_time_by_name_and_remove_cb(CALLBACK_ARGS)
{
  CombineViews_Time(2, 1);
  Draw();
}

void view_applybgmesh_cb(CALLBACK_ARGS)
{
  Post_View *v = (Post_View *) List_Pointer(CTX.post.list, (long int)data);
  if(!v->ScalarOnly || v->TextOnly) {
    Msg(GERROR, "Background mesh generation impossible with non-scalar view");
    return;
  }
  BGMWithView(v);
}

void view_options_cb(CALLBACK_ARGS)
{
  WID->create_view_options_window((long int)data);
}

void view_plugin_cb(CALLBACK_ARGS)
{
  char name[256];
  std::pair < int, GMSH_Plugin * >*pair =
    (std::pair < int, GMSH_Plugin * >*)data;
  int iView = pair->first;
  GMSH_Post_Plugin *p = (GMSH_Post_Plugin *) pair->second;
  p->getName(name);

  if(p->dialogBox) {    //Get the values from the GUI
    int m = p->getNbOptionsStr();
    int n = p->getNbOptions();
    if(m > 20) m = 20;
    if(n > 20) n = 20;
    for(int i = 0; i < m; i++) {
      StringXString *sxs = p->getOptionStr(i);
      sxs->def = (char*)p->dialogBox->input[i]->value();
    }
    for(int i = 0; i < n; i++) {
      StringXNumber *sxn = p->getOption(i);
      sxn->def = p->dialogBox->value[i]->value();
    }
  }

  try {
    Post_View *v = (Post_View *) List_Pointer_Test(CTX.post.list, iView);
    p->execute(v);
    Draw();
  }
  catch(GMSH_Plugin * err) {
    p->catchErrorMessage(name);
    Msg(WARNING, "%s", name);
  }
}

void view_options_plugin_cb(CALLBACK_ARGS)
{
  std::pair < int, GMSH_Plugin * >*pair =
    (std::pair < int, GMSH_Plugin * >*)data;
  GMSH_Plugin *p = pair->second;

  if(!p->dialogBox)
    p->dialogBox = WID->create_plugin_window(p);

  p->dialogBox->run_button->callback(view_plugin_cb, (void *)pair);
  p->dialogBox->main_window->show();
}

void view_options_custom_cb(CALLBACK_ARGS)
{
  int custom = (int)data;
    
  if(custom){
    WID->view_value[31]->activate();
    WID->view_value[32]->activate();
  }
  else {
    WID->view_value[31]->deactivate();
    WID->view_value[32]->deactivate();
  }

  if(w) w->set_changed();
}

void view_options_timestep_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (long int)data)) {
      opt_view_timestep(i, GMSH_SET, (int)((Fl_Value_Input *) w)->value());
    }
  }
  Draw();
}

void view_options_timestep_decr_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (long int)data)) {
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) - 1);
    }
  }
  Draw();
}

void view_options_timestep_incr_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (long int)data)) {
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) + 1);
    }
  }
  Draw();
}

void view_options_ok_cb(CALLBACK_ARGS)
{
  int i, links, force = 0;

  if((long int)data < 0)
    return;

  links = (int)opt_post_link(0, GMSH_GET, 0);

  for(i = 0; i < List_Nbr(CTX.post.list); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (long int)data)) {

      if(links == 3 || links == 4)
        force = 1;

      // view_choice

      if(force || WID->view_choice[1]->changed()) {
        int val;
        switch (WID->view_choice[1]->value()) {
        case 0:
          val = DRAW_POST_LINEAR;
          break;
        case 1:
          val = DRAW_POST_LOGARITHMIC;
          break;
        default:
          val = DRAW_POST_DOUBLELOGARITHMIC;
          break;
        }
        opt_view_scale_type(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[0]->changed()) {
        int val;
        switch (WID->view_choice[0]->value()) {
        case 0:
          val = DRAW_POST_ISO;
          break;
        case 1:
          val = DRAW_POST_DISCRETE;
          break;
        case 2:
          val = DRAW_POST_CONTINUOUS;
          break;
        default:
          val = DRAW_POST_NUMERIC;
          break;
        }
        opt_view_intervals_type(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[5]->changed()) {
        int val;
        switch (WID->view_choice[5]->value()) {
        case 0:
          val = 0;
          break;
        default:
          val = 1;
          break;
        }
        opt_view_point_type(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[6]->changed()) {
        int val;
        switch (WID->view_choice[6]->value()) {
        case 0:
          val = 0;
          break;
        default:
          val = 1;
          break;
        }
        opt_view_line_type(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[2]->changed()) {
        int val;
        switch (WID->view_choice[2]->value()) {
        case 0:
          val = DRAW_POST_SEGMENT;
          break;
        case 1:
          val = DRAW_POST_ARROW;
          break;
        case 2:
          val = DRAW_POST_PYRAMID;
          break;
        case 4:
          val = DRAW_POST_DISPLACEMENT;
	  break;
	default: // 3
          val = DRAW_POST_ARROW3D;
          break;
        }
        opt_view_vector_type(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[3]->changed()) {
        int val;
        switch (WID->view_choice[3]->value()) {
        case 0:
          val = DRAW_POST_LOCATE_COG;
          break;
        default:
          val = DRAW_POST_LOCATE_VERTEX;
          break;
        }
        opt_view_arrow_location(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[4]->changed()) {
        int val;
        switch (WID->view_choice[4]->value()) {
        case 0:
          val = DRAW_POST_VONMISES;
          break;
        default:
          val = DRAW_POST_EIGENVECTORS;
          break;
        }
        opt_view_tensor_type(i, GMSH_SET, val);
      }

      if(force || WID->view_choice[7]->changed()) {
        int val;
        switch (WID->view_choice[7]->value()) {
        case 0:
          val = DRAW_POST_RANGE_DEFAULT;
          break;
        case 1:
          val = DRAW_POST_RANGE_PER_STEP;
          break;
        default:
          val = DRAW_POST_RANGE_CUSTOM;
          break;
        }
        opt_view_range_type(i, GMSH_SET, val);
      }

      // view_butts

      if(force || WID->view_butt[1]->changed() ||
         WID->view_butt[2]->changed() || WID->view_butt[3]->changed())
        opt_view_type(i, GMSH_SET,
                      WID->view_butt[1]->value()? DRAW_POST_3D :
                      WID->view_butt[2]->value()? DRAW_POST_2D_SPACE :
                      DRAW_POST_2D_TIME);

      if(force || WID->view_butt[38]->changed())
        opt_view_saturate_values(i, GMSH_SET, WID->view_butt[38]->value());

      if(force || WID->view_butt[10]->changed())
        opt_view_show_element(i, GMSH_SET, WID->view_butt[10]->value());

      if(force || WID->view_butt[4]->changed())
        opt_view_show_scale(i, GMSH_SET, WID->view_butt[4]->value());

      if(force || WID->view_butt[7]->changed())
        opt_view_auto_position(i, GMSH_SET, WID->view_butt[7]->value());

      if(force || WID->view_butt[8]->changed())
        opt_view_show_time(i, GMSH_SET, WID->view_butt[8]->value());

      if(force || WID->view_butt[5]->changed())
        opt_view_draw_strings(i, GMSH_SET, WID->view_butt[5]->value());

      if(force || WID->view_butt[6]->changed())
        opt_view_transparent_scale(i, GMSH_SET, WID->view_butt[6]->value());

      if(force || WID->view_butt[11]->changed())
        opt_view_light(i, GMSH_SET, WID->view_butt[11]->value());

      if(force || WID->view_butt[9]->changed())
        opt_view_light_two_side(i, GMSH_SET, WID->view_butt[9]->value());

      if(force || WID->view_butt[12]->changed())
        opt_view_smooth_normals(i, GMSH_SET, WID->view_butt[12]->value());

      if(force || WID->view_butt[13]->changed())
        opt_view_draw_points(i, GMSH_SET, WID->view_butt[13]->value());

      if(force || WID->view_butt[14]->changed())
        opt_view_draw_lines(i, GMSH_SET, WID->view_butt[14]->value());

      if(force || WID->view_butt[15]->changed())
        opt_view_draw_triangles(i, GMSH_SET, WID->view_butt[15]->value());

      if(force || WID->view_butt[16]->changed())
        opt_view_draw_quadrangles(i, GMSH_SET, WID->view_butt[16]->value());

      if(force || WID->view_butt[17]->changed())
        opt_view_draw_tetrahedra(i, GMSH_SET, WID->view_butt[17]->value());

      if(force || WID->view_butt[18]->changed())
        opt_view_draw_hexahedra(i, GMSH_SET, WID->view_butt[18]->value());

      if(force || WID->view_butt[19]->changed())
        opt_view_draw_prisms(i, GMSH_SET, WID->view_butt[19]->value());

      if(force || WID->view_butt[20]->changed())
        opt_view_draw_pyramids(i, GMSH_SET, WID->view_butt[20]->value());

      if(force || WID->view_butt[21]->changed())
        opt_view_draw_scalars(i, GMSH_SET, WID->view_butt[21]->value());

      if(force || WID->view_butt[22]->changed())
        opt_view_draw_vectors(i, GMSH_SET, WID->view_butt[22]->value());

      if(force || WID->view_butt[23]->changed())
        opt_view_draw_tensors(i, GMSH_SET, WID->view_butt[23]->value());

      // view_values

      if(force || WID->view_value[31]->changed())
        opt_view_custom_min(i, GMSH_SET, WID->view_value[31]->value());

      if(force || WID->view_value[32]->changed())
        opt_view_custom_max(i, GMSH_SET, WID->view_value[32]->value());

      if(force || WID->view_value[30]->changed())
        opt_view_nb_iso(i, GMSH_SET, WID->view_value[30]->value());

      if(force || WID->view_value[40]->changed())
        opt_view_offset0(i, GMSH_SET, WID->view_value[40]->value());

      if(force || WID->view_value[41]->changed())
        opt_view_offset1(i, GMSH_SET, WID->view_value[41]->value());

      if(force || WID->view_value[42]->changed())
        opt_view_offset2(i, GMSH_SET, WID->view_value[42]->value());

      if(force || WID->view_value[43]->changed())
        opt_view_raise0(i, GMSH_SET, WID->view_value[43]->value());

      if(force || WID->view_value[44]->changed())
        opt_view_raise1(i, GMSH_SET, WID->view_value[44]->value());

      if(force || WID->view_value[45]->changed())
        opt_view_raise2(i, GMSH_SET, WID->view_value[45]->value());

      if(force || WID->view_value[50]->changed())
        opt_view_timestep(i, GMSH_SET, WID->view_value[50]->value());

      if(force || WID->view_value[60]->changed())
        opt_view_arrow_size(i, GMSH_SET, WID->view_value[60]->value());

      if(force || WID->view_value[63]->changed())
        opt_view_displacement_factor(i, GMSH_SET, WID->view_value[63]->value());

      if(force || WID->view_value[61]->changed())
        opt_view_point_size(i, GMSH_SET, WID->view_value[61]->value());

      if(force || WID->view_value[62]->changed())
        opt_view_line_width(i, GMSH_SET, WID->view_value[62]->value());

      if(force || WID->view_value[11]->changed())
        opt_view_boundary(i, GMSH_SET, WID->view_value[11]->value());

      if(force || WID->view_value[12]->changed())
        opt_view_explode(i, GMSH_SET, WID->view_value[12]->value());

      if(force || WID->view_value[10]->changed())
        opt_view_angle_smooth_normals(i, GMSH_SET,
                                      WID->view_value[10]->value());

      if(force || WID->view_value[20]->changed())
        opt_view_position0(i, GMSH_SET, WID->view_value[20]->value());

      if(force || WID->view_value[21]->changed())
        opt_view_position1(i, GMSH_SET, WID->view_value[21]->value());

      if(force || WID->view_value[22]->changed())
        opt_view_size0(i, GMSH_SET, WID->view_value[22]->value());

      if(force || WID->view_value[23]->changed())
        opt_view_size1(i, GMSH_SET, WID->view_value[23]->value());

      if(force || WID->view_value[25]->changed())
        opt_view_nb_abscissa(i, GMSH_SET, WID->view_value[25]->value());

      if(force || WID->view_value[26]->changed())
        opt_view_grid(i, GMSH_SET, WID->view_value[26]->value());

      // view_inputs

      if(force || WID->view_input[0]->changed())
        opt_view_name(i, GMSH_SET, (char *)WID->view_input[0]->value());

      if(force || WID->view_input[1]->changed())
        opt_view_format(i, GMSH_SET, (char *)WID->view_input[1]->value());

      if(force || WID->view_input[2]->changed())
        opt_view_abscissa_name(i, GMSH_SET,
                               (char *)WID->view_input[2]->value());

      if(force || WID->view_input[3]->changed())
        opt_view_abscissa_format(i, GMSH_SET,
                                 (char *)WID->view_input[3]->value());

      // colorbar window

      if(force
         || (WID->view_colorbar_window->changed() && i != (long int)data)) {
        ColorTable_Copy(&
                        ((Post_View *)
                         List_Pointer(CTX.post.list, (long int)data))->CT);
        ColorTable_Paste(&((Post_View *) List_Pointer(CTX.post.list, i))->CT);
      }
    }
  }

  // we clear all the flags
  for(i = 0; i < VIEW_OPT_BUTT; i++) {
    if(WID->view_butt[i])
      WID->view_butt[i]->clear_changed();
    if(WID->view_value[i])
      WID->view_value[i]->clear_changed();
    if(WID->view_input[i])
      WID->view_input[i]->clear_changed();
    if(WID->view_choice[i])
      WID->view_choice[i]->clear_changed();
    WID->view_colorbar_window->clear_changed();
  }
}

void view_arrow_param_cb(CALLBACK_ARGS)
{
  double a = opt_view_arrow_head_radius((long int)data, GMSH_GET, 0);
  double b = opt_view_arrow_stem_length((long int)data, GMSH_GET, 0);
  double c = opt_view_arrow_stem_radius((long int)data, GMSH_GET, 0);
  while(arrow_editor("Arrow editor", a, b, c)){
    opt_view_arrow_head_radius((long int)data, GMSH_SET, a);
    opt_view_arrow_stem_length((long int)data, GMSH_SET, b);
    opt_view_arrow_stem_radius((long int)data, GMSH_SET, c);
    Draw();
  }
}

// Contextual windows for geometry

void con_geometry_define_parameter_cb(CALLBACK_ARGS)
{
  add_param((char *)WID->context_geometry_input[0]->value(),
            (char *)WID->context_geometry_input[1]->value(), CTX.filename);
}

void con_geometry_define_point_cb(CALLBACK_ARGS)
{
  add_point(CTX.filename,
	    (char*)WID->context_geometry_input[2]->value(),
	    (char*)WID->context_geometry_input[3]->value(),
	    (char*)WID->context_geometry_input[4]->value(),
	    (char*)WID->context_geometry_input[5]->value());
  ZeroHighlight(THEM);
  CalculateMinMax(THEM->Points, NULL);
  Draw();
}

