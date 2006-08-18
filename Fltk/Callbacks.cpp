// $Id: Callbacks.cpp,v 1.441 2006-08-18 21:11:42 geuzaine Exp $
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

#include <signal.h>
#include <time.h>
#include <map>

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "CAD.h"
#include "ExtractContour.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "CreateFile.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Context.h"
#include "Options.h"
#include "GUI.h"
#include "GUI_Extras.h"
#include "Callbacks.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "Visibility.h"
#include "Numeric.h"
#include "Solvers.h"
#include "OS.h"
#include "GModel.h"

using namespace std;

extern Context_T CTX;
extern GUI *WID;
extern GModel *GMODEL;

// Helper routines

void UpdateViewsInGUI()
{
  if(WID) {
    WID->check_anim_buttons();
    if(WID->get_context() == 3)
      WID->set_context(menu_post, 0);
    WID->reset_option_browser();
    WID->reset_clip_browser();
    WID->reset_external_view_list();
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
      HighlightEntityNum(0, abs(ip), 0, 0, 1);
    }
    break;
  case ENT_SURFACE:
    k = allFacesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      List_Read(List, i, &ip);
      HighlightEntityNum(0, 0, abs(ip), 0, 1);
    }
    break;
  }

  Draw();
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
  uchar r = CTX.UNPACK_RED(fct(0, GMSH_GET, 0));
  uchar g = CTX.UNPACK_GREEN(fct(0, GMSH_GET, 0));
  uchar b = CTX.UNPACK_BLUE(fct(0, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(0, GMSH_SET | GMSH_GUI, CTX.PACK_COLOR(r, g, b, 255));
  Draw();
}

void view_color_cb(CALLBACK_ARGS)
{
  unsigned int (*fct) (int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = CTX.UNPACK_RED(fct(WID->view_number, GMSH_GET, 0));
  uchar g = CTX.UNPACK_GREEN(fct(WID->view_number, GMSH_GET, 0));
  uchar b = CTX.UNPACK_BLUE(fct(WID->view_number, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(WID->view_number, GMSH_SET | GMSH_GUI, CTX.PACK_COLOR(r, g, b, 255));
  Draw();
}

void redraw_cb(CALLBACK_ARGS)
{
  Draw();
}

void window_cb(CALLBACK_ARGS)
{
  static int oldx = 0, oldy = 0, oldw = 0, oldh = 0, zoom = 1;
  char *str = (char*)data;

  if(!strcmp(str, "minimize")){
    WID->g_window->iconize();
    if(WID->opt_window->shown()) WID->opt_window->iconize();
    if(WID->vis_window->shown()) WID->vis_window->iconize();
    if(WID->clip_window->shown()) WID->clip_window->iconize();
    if(WID->manip_window->shown()) WID->manip_window->iconize();
    if(WID->stat_window->shown()) WID->stat_window->iconize();
    if(WID->msg_window->shown()) WID->msg_window->iconize();
    WID->m_window->iconize();
  }
  else if(!strcmp(str, "zoom")){
    if(zoom){
      oldx = WID->g_window->x();
      oldy = WID->g_window->y();
      oldw = WID->g_window->w();
      oldh = WID->g_window->h();
      WID->g_window->resize(Fl::x(), Fl::y(), Fl::w(), Fl::h());
      zoom = 0;
    }
    else{
      WID->g_window->resize(oldx, oldy, oldw, oldh);
      zoom = 1;
    }
    WID->g_window->show();
    WID->m_window->show();
  }
  else if(!strcmp(str, "front")){
    // the order is important!
    WID->g_window->show();
    if(WID->opt_window->shown()) WID->opt_window->show();
    if(WID->context_geometry_window->shown()) WID->context_geometry_window->show();
    if(WID->context_mesh_window->shown()) WID->context_mesh_window->show();
    for(int i = 0; i < MAXSOLVERS; i++) {
      if(WID->solver[i].window->shown()) WID->solver[i].window->show();
    }
    if(WID->vis_window->shown()) WID->vis_window->show();
    if(WID->clip_window->shown()) WID->clip_window->show();
    if(WID->manip_window->shown()) WID->manip_window->show();
    if(WID->stat_window->shown()) WID->stat_window->show();
    if(WID->msg_window->shown()) WID->msg_window->show();
    WID->m_window->show();
  }
}

void activate_cb(CALLBACK_ARGS)
{
  // this is a central callback to activate/deactivate parts of the
  // GUI depending on the user's choices (or the option settings)

  char *str = (char*)data;

  if(!strcmp(str, "rotation_center")){
    if(WID->gen_butt[15]->value()) {
      WID->gen_push_butt[0]->deactivate();
      WID->gen_value[8]->deactivate();
      WID->gen_value[9]->deactivate();
      WID->gen_value[10]->deactivate();
    }
    else {
      WID->gen_push_butt[0]->activate();
      WID->gen_value[8]->activate();
      WID->gen_value[9]->activate();
      WID->gen_value[10]->activate();
    }
  }
  else if(!strcmp(str, "custom_range")){
    if(WID->view_choice[7]->value() == 2){
      WID->view_value[31]->activate();
      WID->view_value[32]->activate();
      WID->view_push_butt[1]->activate();
      WID->view_push_butt[2]->activate();
    }
    else {
      WID->view_value[31]->deactivate();
      WID->view_value[32]->deactivate();
      WID->view_push_butt[1]->deactivate();
      WID->view_push_butt[2]->deactivate();
    }
  }
  else if(!strcmp(str, "general_transform")){
    if(WID->view_butt[6]->value()){
      WID->view_choice[11]->activate();
      WID->view_value[2]->activate();
      WID->view_input[4]->activate();
      WID->view_input[5]->activate();
      WID->view_input[6]->activate();
    }
    else{
      WID->view_choice[11]->deactivate();
      WID->view_value[2]->deactivate();
      WID->view_input[4]->deactivate();
      WID->view_input[5]->deactivate();
      WID->view_input[6]->deactivate();
    }
  }
  else if(!strcmp(str, "general_axes")){
    if(WID->gen_choice[4]->value()){
      WID->gen_value[17]->activate();
      WID->gen_value[18]->activate();
      WID->gen_value[19]->activate();
      WID->gen_input[3]->activate();
      WID->gen_input[4]->activate();
      WID->gen_input[5]->activate();
      WID->gen_input[6]->activate();
      WID->gen_input[7]->activate();
      WID->gen_input[8]->activate();
    }
    else{
      WID->gen_value[17]->deactivate();
      WID->gen_value[18]->deactivate();
      WID->gen_value[19]->deactivate();
      WID->gen_input[3]->deactivate();
      WID->gen_input[4]->deactivate();
      WID->gen_input[5]->deactivate();
      WID->gen_input[6]->deactivate();
      WID->gen_input[7]->deactivate();
      WID->gen_input[8]->deactivate();
    }
  }
  else if(!strcmp(str, "general_axes_auto")){
    if(WID->gen_butt[0]->value()){
      WID->gen_value[20]->deactivate();
      WID->gen_value[21]->deactivate();
      WID->gen_value[22]->deactivate();
      WID->gen_value[23]->deactivate();
      WID->gen_value[24]->deactivate();
      WID->gen_value[25]->deactivate();
    }
    else{
      WID->gen_value[20]->activate();
      WID->gen_value[21]->activate();
      WID->gen_value[22]->activate();
      WID->gen_value[23]->activate();
      WID->gen_value[24]->activate();
      WID->gen_value[25]->activate();
    }
  }
  else if(!strcmp(str, "general_small_axes")){
    if(WID->gen_butt[1]->value()){
      WID->gen_value[26]->activate();
      WID->gen_value[27]->activate();
    }
    else{
      WID->gen_value[26]->deactivate();
      WID->gen_value[27]->deactivate();
    }
  }
  else if(!strcmp(str, "mesh_cut_plane")){
    if(WID->mesh_butt[16]->value()){
      WID->mesh_cut_plane->activate();
    }
    else{
      WID->mesh_cut_plane->deactivate();
    }
  }
  else if(!strcmp(str, "mesh_light")){
    if(WID->mesh_butt[17]->value()){
      WID->mesh_butt[18]->activate();
      WID->mesh_butt[19]->activate();
      WID->mesh_butt[20]->activate();
      WID->mesh_value[18]->activate();
    }
    else{
      WID->mesh_butt[18]->deactivate();
      WID->mesh_butt[19]->deactivate();
      WID->mesh_butt[20]->deactivate();
      WID->mesh_value[18]->deactivate();
    }
  }
  else if(!strcmp(str, "view_light")){
    if(WID->view_butt[11]->value()){
      WID->view_butt[8]->activate();
      WID->view_butt[9]->activate();
      WID->view_butt[12]->activate();
      WID->view_value[10]->activate();
    }
    else{
      WID->view_butt[8]->deactivate();
      WID->view_butt[9]->deactivate();
      WID->view_butt[12]->deactivate();
      WID->view_value[10]->deactivate();
    }
  }
  else if(!strcmp(str, "view_axes")){
    if(WID->view_choice[8]->value()){
      WID->view_value[3]->activate();
      WID->view_value[4]->activate();
      WID->view_value[5]->activate();
      WID->view_input[7]->activate();
      WID->view_input[8]->activate();
      WID->view_input[9]->activate();
      WID->view_input[10]->activate();
      WID->view_input[11]->activate();
      WID->view_input[12]->activate();
    }
    else{
      WID->view_value[3]->deactivate();
      WID->view_value[4]->deactivate();
      WID->view_value[5]->deactivate();
      WID->view_input[7]->deactivate();
      WID->view_input[8]->deactivate();
      WID->view_input[9]->deactivate();
      WID->view_input[10]->deactivate();
      WID->view_input[11]->deactivate();
      WID->view_input[12]->deactivate();
    }
  }
  else if(!strcmp(str, "view_axes_auto_3d")){
    if(WID->view_butt[25]->value()){
      WID->view_value[13]->deactivate();
      WID->view_value[14]->deactivate();
      WID->view_value[15]->deactivate();
      WID->view_value[16]->deactivate();
      WID->view_value[17]->deactivate();
      WID->view_value[18]->deactivate();
    }
    else{
      WID->view_value[13]->activate();
      WID->view_value[14]->activate();
      WID->view_value[15]->activate();
      WID->view_value[16]->activate();
      WID->view_value[17]->activate();
      WID->view_value[18]->activate();
    }
  }
  else if(!strcmp(str, "view_axes_auto_2d")){
    if(WID->view_butt[7]->value()){
      WID->view_value[20]->deactivate();
      WID->view_value[21]->deactivate();
      WID->view_value[22]->deactivate();
      WID->view_value[23]->deactivate();
    }
    else{
      WID->view_value[20]->activate();
      WID->view_value[21]->activate();
      WID->view_value[22]->activate();
      WID->view_value[23]->activate();
    }
  }
}

// Graphical window 

void status_xyz1p_cb(CALLBACK_ARGS)
{
  char *str = (char*)data;

  if(!strcmp(str, "r")){ // rotate 90 degress around axis perp to the screen
    double axis[3] = {0., 0., 1.};
    if(!Fl::event_state(FL_SHIFT))
      CTX.addQuaternionFromAxisAndAngle(axis, -90.);
    else
      CTX.addQuaternionFromAxisAndAngle(axis, 90.);
    Draw();
  }
  else if(!strcmp(str, "x")){ // X pointing out or into the screen
    if(!Fl::event_state(FL_SHIFT)){
      CTX.r[0] = -90.;
      CTX.r[1] = 0.;
      CTX.r[2] = -90.;
    }
    else{
      CTX.r[0] = -90.;
      CTX.r[1] = 0.;
      CTX.r[2] = 90.;
    }
    CTX.setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "y")){ // Y pointing out or into the screen
    if(!Fl::event_state(FL_SHIFT)){
      CTX.r[0] = -90.;
      CTX.r[1] = 0.;
      CTX.r[2] = 180.;
    }
    else{
      CTX.r[0] = -90.;
      CTX.r[1] = 0.;
      CTX.r[2] = 0.;
    }
    CTX.setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "z")){ // Z pointing out or into the screen
    if(!Fl::event_state(FL_SHIFT)){
      CTX.r[0] = 0.;
      CTX.r[1] = 0.;
      CTX.r[2] = 0.;
    }
    else{
      CTX.r[0] = 0.;
      CTX.r[1] = 180.;
      CTX.r[2] = 0.;
    }
    CTX.setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "1:1")){ // reset translation and scaling
    CTX.t[0] = CTX.t[1] = CTX.t[2] = 0.;
    CTX.s[0] = CTX.s[1] = CTX.s[2] = 1.;
    Draw();
  }
  else if(!strcmp(str, "reset")){ // reset everything
    CTX.t[0] = CTX.t[1] = CTX.t[2] = 0.;
    CTX.s[0] = CTX.s[1] = CTX.s[2] = 1.;
    CTX.r[0] = 0.;
    CTX.r[1] = 0.;
    CTX.r[2] = 0.;
    CTX.setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "p")){ // toggle projection mode
    if(!Fl::event_state(FL_SHIFT)){
      opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 
			       !opt_general_orthographic(0, GMSH_GET, 0));
    }
    else{
      perspective_editor();
    }
    Draw();
  }
  else if(!strcmp(str, "?")){ // display options
    Print_Options(0, GMSH_FULLRC, 0, 1, NULL);
    WID->create_message_window();
  }
  else if(!strcmp(str, "S")){ // mouse selection
    if(Fl::event_state(FL_SHIFT)){
      // full mouse hover and select for geometry and mesh
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 2);
    }
    else if(CTX.enable_mouse_selection){
      // mouse does nothing
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
      WID->g_opengl_window->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);      
    }
    else{
      // mouse hover and select for geometry, but mouse select only
      // for mesh (default)
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
    }
  }
  WID->update_manip_window();
}

static int stop_anim, view_in_cycle = -1, busy = 0;

void ManualPlay(int time, int step)
{
  // avoid firing ManualPlay recursively (can happen e.g when keeping
  // the finger down on the arrow key: if the system generates too
  // many events, we can overflow the stack--that happened on my
  // powerbook with the new, optimzed FLTK event handler)
  if(busy) return;
  busy = 1;
  if(time) {
    for(int i = 0; i < List_Nbr(CTX.post.list); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                          opt_view_timestep(i, GMSH_GET, 0) + step);
  }
  else { // hide all views except view_in_cycle
    if(step > 0) {
      if((view_in_cycle += step) >= List_Nbr(CTX.post.list))
        view_in_cycle = 0;
      for(int i = 0; i < List_Nbr(CTX.post.list); i += step)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else {
      if((view_in_cycle += step) < 0)
        view_in_cycle = List_Nbr(CTX.post.list) - 1;
      for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i += step)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
  }
  Draw();
  busy = 0;
}

void status_play_cb(CALLBACK_ARGS)
{
  static double anim_time;
  WID->set_anim_buttons(0);
  stop_anim = 0;
  anim_time = GetTimeInSeconds();
  while(1) {
    if(stop_anim)
      break;
    if(GetTimeInSeconds() - anim_time > CTX.post.anim_delay) {
      anim_time = GetTimeInSeconds();
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
  if(file_chooser(0, 1, "New", "*")) {
    char *name = file_chooser_get_name(1);
    if(!StatFile(name)){
      if(fl_choice("File '%s' already exists.\n\nDo you want to erase it?",
		   "Cancel", "Erase", NULL, name))
	UnlinkFile(name);
      else
	goto test;
    }
    FILE *fp = fopen(name, "w");
    if(!fp){
      Msg(GERROR, "Unable to open file '%s'", name);
      return;
    }
    time_t now;
    time(&now);
    fprintf(fp, "// Gmsh project created on %s", ctime(&now));
    fclose(fp);
    OpenProblem(name);
    Draw();
  }
}

static char *file_types =
  "*"
  "\tGmsh geometry (*.geo)"
  "\tGmsh mesh (*.msh)"
  "\tGmsh post-processing (*.pos)"
  "\tSTL surface mesh (*.stl)"
  "\tINRIA mesh (*.mesh)"
  "\tJPEG (*.jpg)"
  "\tPNG (*.png)"
  "\tBMP (*.bmp)"
  "\tPPM (*.ppm)"
  "\tPGM (*.pgm)"
  "\tPBM (*.pbm)"
  "\tPNM (*.pnm)";

void file_open_cb(CALLBACK_ARGS)
{
  int n = List_Nbr(CTX.post.list);
  if(file_chooser(0, 0, "Open", file_types)) {
    OpenProblem(file_chooser_get_name(1));
    Draw();
  }
  if(n != List_Nbr(CTX.post.list))
    WID->set_context(menu_post, 0);
}

void file_merge_cb(CALLBACK_ARGS)
{
  int n = List_Nbr(CTX.post.list);
  int f = file_chooser(1, 0, "Merge", file_types);
  if(f) {
    for(int i = 1; i <= f; i++)
      MergeProblem(file_chooser_get_name(i));
    Draw();
  }
  if(n != List_Nbr(CTX.post.list))
    WID->set_context(menu_post, 0);
}

int _save_options(char *name)
{
  return options_dialog(name);
}

int _save_geo(char *name)
{
  CreateOutputFile(name, FORMAT_GEO);
  return 1;
}

int _save_msh(char *name)
{
  return msh_dialog(name);
}

int _save_pos(char *name)
{
  CreateOutputFile(name, FORMAT_POS);
  return 1;
}

int _save_unv(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_UNV);
  return 1;
}

int _save_mesh(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_MESH);
  return 1;
}

int _save_vrml(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_VRML);
  return 1;
}

int _save_stl(char *name)
{
  CreateOutputFile(name, CTX.mesh.format = FORMAT_STL);
  return 1;
}

int _save_ps(char *name)
{
  return gl2ps_dialog(name, "PS Options", 0, 0);
}

int _save_eps(char *name)
{
  return gl2ps_dialog(name, "EPS Options", 1, 0);
}

int _save_epstex(char *name)
{
  return gl2ps_dialog(name, "EPS Options", 1, 1);
}

int _save_pdf(char *name)
{
  return gl2ps_dialog(name, "PDF Options", 2, 0);
}

int _save_pdftex(char *name)
{
  return gl2ps_dialog(name, "PDF Options", 2, 1);
}

int _save_svg(char *name)
{
  return gl2ps_dialog(name, "SVG Options", 3, 0);
}

int _save_jpegtex(char *name)
{
  return jpeg_dialog(name, 1);
}

int _save_pngtex(char *name)
{
  CreateOutputFile(name, FORMAT_PNGTEX);
  return 1;
}

int _save_tex(char *name)
{
  CreateOutputFile(name, FORMAT_TEX);
  return 1;
}

int _save_jpeg(char *name)
{
  return jpeg_dialog(name, 0);
}

int _save_png(char *name)
{
  CreateOutputFile(name, FORMAT_PNG);
  return 1;
}

int _save_gif(char *name)
{
  return gif_dialog(name);
}

int _save_ppm(char *name)
{
  CreateOutputFile(name, FORMAT_PPM);
  return 1;
}

int _save_yuv(char *name)
{
  CreateOutputFile(name, FORMAT_YUV);
  return 1;
}

int _save_auto(char *name)
{
  switch(GuessFileFormatFromFileName(name)){
  case FORMAT_OPT     : return _save_options(name);
  case FORMAT_MSH     : return _save_msh(name);
  case FORMAT_PS      : return _save_ps(name);
  case FORMAT_EPS     : return _save_eps(name);
  case FORMAT_EPSTEX  : return _save_epstex(name);
  case FORMAT_PDF     : return _save_pdf(name);
  case FORMAT_PDFTEX  : return _save_pdftex(name);
  case FORMAT_SVG     : return _save_svg(name);
  case FORMAT_JPEGTEX : return _save_jpegtex(name);
  case FORMAT_JPEG    : return _save_jpeg(name);
  case FORMAT_GIF     : return _save_gif(name);
  default :
    CreateOutputFile(name, FORMAT_AUTO); 
    return 1;
  }
}

typedef struct{
  char *pat;
  int (*func) (char *name);
} patXfunc;

void file_save_as_cb(CALLBACK_ARGS)
{
  int i, nbformats;
  static char *pat = NULL;
  static patXfunc formats[] = {
    {"Guess from extension (*.*)", _save_auto},
    {" ", _save_auto},
    {"Gmsh mesh (*.msh)", _save_msh},
    {"Gmsh mesh statistics (*.pos)", _save_pos},
    {"Gmsh options (*.opt)", _save_options},
    {"Gmsh unrolled geometry (*.geo)", _save_geo},
    {"  ", _save_auto},
    {"I-DEAS universal mesh (*.unv)", _save_unv},
    {"INRIA mesh (*.mesh)", _save_mesh},
    {"STL surface mesh (*.stl)", _save_stl},
    {"VRML surface mesh (*.wrl)", _save_vrml},
    {"   ", _save_auto},
    {"Encapsulated PostScript (*.eps)", _save_eps},
    {"GIF (*.gif)", _save_gif},
#if defined(HAVE_LIBJPEG)
    {"JPEG (*.jpg)", _save_jpeg},
#endif
    {"LaTeX EPS part without text (*.eps)", _save_epstex},
#if defined(HAVE_LIBJPEG)
    {"LaTeX JPEG part without text (*.jpg)", _save_jpegtex},
#endif
    {"LaTeX PDF part without text (*.pdf)", _save_pdftex},
#if defined(HAVE_LIBPNG)
    {"LaTeX PNG part without text (*.png)", _save_pngtex},
#endif
    {"LaTeX text part (*.tex)", _save_tex},
    {"PDF (*.pdf)", _save_pdf},
#if defined(HAVE_LIBPNG)
    {"PNG (*.png)", _save_png},
#endif
    {"PostScript (*.ps)", _save_ps},
    {"PPM (*.ppm)", _save_ppm},
    {"SVG (*.svg)", _save_svg},
    {"YUV (*.yuv)", _save_yuv},
    {"    ", _save_auto},
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
  if(file_chooser(0, 1, "Save As", pat)) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
		      "Cancel", "Replace", NULL, name))
          goto test;
    }
    i = file_chooser_get_filter();
    if(i >= 0 && i < nbformats){
      if(!formats[i].func(name))
	goto test;
    }
    else // handle any additional automatic fltk filter
      _save_auto(name);
  }
}

void file_rename_cb(CALLBACK_ARGS)
{
 test:
  if(file_chooser(0, 1, "Rename", "*", CTX.filename)) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
		      "Cancel", "Replace", NULL, name))
          goto test;
    }
    rename(CTX.filename, name);
    OpenProblem(name);
    Draw();
  }
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
  Msg(STATUS2, "Writing '%s'", CTX.options_filename_fullpath);
  Print_Options(0, GMSH_OPTIONSRC, 1, 1, CTX.options_filename_fullpath);
  Msg(STATUS2, "Wrote '%s'", CTX.options_filename_fullpath);
}

void options_restore_defaults_cb(CALLBACK_ARGS)
{
  // not sure if we have to remove the file...
  UnlinkFile(CTX.session_filename_fullpath);
  UnlinkFile(CTX.options_filename_fullpath);
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
  opt_general_color_scheme(0, GMSH_SET, WID->gen_choice[3]->value());
  Draw();
}

void general_options_rotation_center_select_cb(CALLBACK_ARGS)
{
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int ne;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  Msg(ONSCREEN, "Select point\n[Press 'q' to abort]");
  char ib = SelectEntity(ENT_POINT, &ne, v, c, s, r);
  if(ib == 'l') {
    // This would bypass the "Apply" button... Not necessarily bad,
    // but it's not consistent with the rest of the GUI.
    //opt_general_rotation_center0(0, GMSH_SET|GMSH_GUI, v->x());
    //opt_general_rotation_center1(0, GMSH_SET|GMSH_GUI, v->y());
    //opt_general_rotation_center2(0, GMSH_SET|GMSH_GUI, v->z());

    // This is more conform to the way we do things elsewhere:
    WID->gen_value[8]->value(v[0]->x());
    WID->gen_value[9]->value(v[0]->y());
    WID->gen_value[10]->value(v[0]->z());
  }
  ZeroHighlight();
  Draw();
  Msg(ONSCREEN, "");
}

void general_options_ok_cb(CALLBACK_ARGS)
{
  opt_general_axes_auto_position(0, GMSH_SET, WID->gen_butt[0]->value());
  opt_general_small_axes(0, GMSH_SET, WID->gen_butt[1]->value());
  opt_general_fast_redraw(0, GMSH_SET, WID->gen_butt[2]->value());
  if(opt_general_double_buffer(0, GMSH_GET, 0) != WID->gen_butt[3]->value())
    opt_general_double_buffer(0, GMSH_SET, WID->gen_butt[3]->value());
  opt_general_trackball(0, GMSH_SET, WID->gen_butt[5]->value());
  opt_general_terminal(0, GMSH_SET, WID->gen_butt[7]->value());
  double sessionrc = opt_general_session_save(0, GMSH_GET, 0);
  opt_general_session_save(0, GMSH_SET, WID->gen_butt[8]->value());
  if(sessionrc && !opt_general_session_save(0, GMSH_GET, 0))
    Print_Options(0, GMSH_SESSIONRC, 1, 1, CTX.session_filename_fullpath);
  opt_general_options_save(0, GMSH_SET, WID->gen_butt[9]->value());
  opt_general_expert_mode(0, GMSH_SET, WID->gen_butt[10]->value());
  opt_general_tooltips(0, GMSH_SET, WID->gen_butt[13]->value());
  opt_general_confirm_overwrite(0, GMSH_SET, WID->gen_butt[14]->value());
  opt_general_rotation_center_cg(0, GMSH_SET, WID->gen_butt[15]->value());
  opt_general_draw_bounding_box(0, GMSH_SET, WID->gen_butt[6]->value());
  opt_general_polygon_offset_always(0, GMSH_SET, WID->gen_butt[4]->value());
  
  opt_general_shine(0, GMSH_SET, WID->gen_value[1]->value());
  opt_general_shine_exponent(0, GMSH_SET, WID->gen_value[0]->value());
  opt_general_light00(0, GMSH_SET, WID->gen_value[2]->value());
  opt_general_light01(0, GMSH_SET, WID->gen_value[3]->value());
  opt_general_light02(0, GMSH_SET, WID->gen_value[4]->value());
  opt_general_light03(0, GMSH_SET, WID->gen_value[13]->value());
  opt_general_verbosity(0, GMSH_SET, WID->gen_value[5]->value());
  opt_general_point_size(0, GMSH_SET, WID->gen_value[6]->value());
  opt_general_line_width(0, GMSH_SET, WID->gen_value[7]->value());
  opt_general_rotation_center0(0, GMSH_SET, WID->gen_value[8]->value());
  opt_general_rotation_center1(0, GMSH_SET, WID->gen_value[9]->value());
  opt_general_rotation_center2(0, GMSH_SET, WID->gen_value[10]->value());
  opt_general_quadric_subdivisions(0, GMSH_SET, WID->gen_value[11]->value());
  opt_general_graphics_fontsize(0, GMSH_SET, WID->gen_value[12]->value());
  opt_general_clip_factor(0, GMSH_SET, WID->gen_value[14]->value());
  opt_general_polygon_offset_factor(0, GMSH_SET, WID->gen_value[15]->value());
  opt_general_polygon_offset_units(0, GMSH_SET, WID->gen_value[16]->value());
  opt_general_axes_tics0(0, GMSH_SET, WID->gen_value[17]->value());
  opt_general_axes_tics1(0, GMSH_SET, WID->gen_value[18]->value());
  opt_general_axes_tics2(0, GMSH_SET, WID->gen_value[19]->value());
  opt_general_axes_xmin(0, GMSH_SET, WID->gen_value[20]->value());
  opt_general_axes_ymin(0, GMSH_SET, WID->gen_value[21]->value());
  opt_general_axes_zmin(0, GMSH_SET, WID->gen_value[22]->value());
  opt_general_axes_xmax(0, GMSH_SET, WID->gen_value[23]->value());
  opt_general_axes_ymax(0, GMSH_SET, WID->gen_value[24]->value());
  opt_general_axes_zmax(0, GMSH_SET, WID->gen_value[25]->value());
  opt_general_small_axes_position0(0, GMSH_SET, WID->gen_value[26]->value());
  opt_general_small_axes_position1(0, GMSH_SET, WID->gen_value[27]->value());

  opt_general_default_filename(0, GMSH_SET, (char *)WID->gen_input[0]->value());
  opt_general_editor(0, GMSH_SET, (char *)WID->gen_input[1]->value());
  opt_general_web_browser(0, GMSH_SET, (char *)WID->gen_input[2]->value());
  opt_general_axes_format0(0, GMSH_SET, (char *)WID->gen_input[3]->value());
  opt_general_axes_format1(0, GMSH_SET, (char *)WID->gen_input[4]->value());
  opt_general_axes_format2(0, GMSH_SET, (char *)WID->gen_input[5]->value());
  opt_general_axes_label0(0, GMSH_SET, (char *)WID->gen_input[6]->value());
  opt_general_axes_label1(0, GMSH_SET, (char *)WID->gen_input[7]->value());
  opt_general_axes_label2(0, GMSH_SET, (char *)WID->gen_input[8]->value());

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
  opt_general_orthographic(0, GMSH_SET, !WID->gen_choice[2]->value());
  opt_general_axes(0, GMSH_SET, WID->gen_choice[4]->value());
  opt_general_background_gradient(0, GMSH_SET, WID->gen_choice[5]->value());
}

void general_arrow_param_cb(CALLBACK_ARGS)
{
  double a = opt_general_arrow_head_radius(0, GMSH_GET, 0);
  double b = opt_general_arrow_stem_length(0, GMSH_GET, 0);
  double c = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
  while(arrow_editor("Arrow Editor", a, b, c)){
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

void mesh_options_ok_cb(CALLBACK_ARGS)
{
  opt_mesh_optimize(0, GMSH_SET, WID->mesh_butt[2]->value());
  opt_mesh_order(0, GMSH_SET, WID->mesh_butt[3]->value()? 2 : 1);
  opt_mesh_constrained_bgmesh(0, GMSH_SET, WID->mesh_butt[5]->value());
  opt_mesh_points(0, GMSH_SET, WID->mesh_butt[6]->value());
  opt_mesh_lines(0, GMSH_SET, WID->mesh_butt[7]->value());
  opt_mesh_triangles(0, GMSH_SET, WID->mesh_menu_butt->menu()[0].value());
  opt_mesh_quadrangles(0, GMSH_SET, WID->mesh_menu_butt->menu()[1].value());
  opt_mesh_tetrahedra(0, GMSH_SET, WID->mesh_menu_butt->menu()[2].value());
  opt_mesh_hexahedra(0, GMSH_SET, WID->mesh_menu_butt->menu()[3].value());
  opt_mesh_prisms(0, GMSH_SET, WID->mesh_menu_butt->menu()[4].value());
  opt_mesh_pyramids(0, GMSH_SET, WID->mesh_menu_butt->menu()[5].value());
  opt_mesh_surfaces_edges(0, GMSH_SET, WID->mesh_butt[8]->value());
  opt_mesh_surfaces_faces(0, GMSH_SET, WID->mesh_butt[9]->value());
  opt_mesh_volumes_edges(0, GMSH_SET, WID->mesh_butt[10]->value());
  opt_mesh_volumes_faces(0, GMSH_SET, WID->mesh_butt[11]->value());
  opt_mesh_points_num(0, GMSH_SET, WID->mesh_butt[12]->value());
  opt_mesh_lines_num(0, GMSH_SET, WID->mesh_butt[13]->value());
  opt_mesh_surfaces_num(0, GMSH_SET, WID->mesh_butt[14]->value());
  opt_mesh_volumes_num(0, GMSH_SET, WID->mesh_butt[15]->value());
  opt_mesh_use_cut_plane(0, GMSH_SET, WID->mesh_butt[16]->value());
  opt_mesh_cut_plane_draw_intersect(0, GMSH_SET, WID->mesh_butt[22]->value());
  opt_mesh_cut_plane_only_volume(0, GMSH_SET, WID->mesh_butt[23]->value());
  opt_mesh_light(0, GMSH_SET, WID->mesh_butt[17]->value());
  opt_mesh_light_two_side(0, GMSH_SET, WID->mesh_butt[18]->value());
  opt_mesh_reverse_all_normals(0, GMSH_SET, WID->mesh_butt[0]->value());
  opt_mesh_smooth_normals(0, GMSH_SET, WID->mesh_butt[19]->value());
  opt_mesh_light_lines(0, GMSH_SET, WID->mesh_butt[20]->value());

  opt_mesh_nb_smoothing(0, GMSH_SET, WID->mesh_value[0]->value());
  opt_mesh_scaling_factor(0, GMSH_SET, WID->mesh_value[1]->value());
  opt_mesh_lc_factor(0, GMSH_SET, WID->mesh_value[2]->value());
  opt_mesh_rand_factor(0, GMSH_SET, WID->mesh_value[3]->value());
  opt_mesh_quality_inf(0, GMSH_SET, WID->mesh_value[4]->value());
  opt_mesh_quality_sup(0, GMSH_SET, WID->mesh_value[5]->value());
  opt_mesh_radius_inf(0, GMSH_SET, WID->mesh_value[6]->value());
  opt_mesh_radius_sup(0, GMSH_SET, WID->mesh_value[7]->value());
  opt_mesh_normals(0, GMSH_SET, WID->mesh_value[8]->value());
  opt_mesh_explode(0, GMSH_SET, WID->mesh_value[9]->value());
  opt_mesh_tangents(0, GMSH_SET, WID->mesh_value[13]->value());
  opt_mesh_point_size(0, GMSH_SET, WID->mesh_value[10]->value());
  opt_mesh_line_width(0, GMSH_SET, WID->mesh_value[11]->value());
  opt_mesh_label_frequency(0, GMSH_SET, WID->mesh_value[12]->value());
  opt_mesh_cut_planea(0, GMSH_SET, WID->mesh_value[14]->value());
  opt_mesh_cut_planeb(0, GMSH_SET, WID->mesh_value[15]->value());
  opt_mesh_cut_planec(0, GMSH_SET, WID->mesh_value[16]->value());
  opt_mesh_cut_planed(0, GMSH_SET, WID->mesh_value[17]->value());
  opt_mesh_angle_smooth_normals(0, GMSH_SET, WID->mesh_value[18]->value());
  opt_mesh_stl_distance_tol(0, GMSH_SET, WID->mesh_value[19]->value());
  opt_mesh_dihedral_angle_tol(0, GMSH_SET, WID->mesh_value[20]->value());
  opt_mesh_edge_prolongation_threshold(0, GMSH_SET, WID->mesh_value[21]->value());
  opt_mesh_nb_elem_per_rc(0, GMSH_SET, WID->mesh_value[22]->value());
  opt_mesh_min_elem_size_fact(0, GMSH_SET, WID->mesh_value[23]->value());
  opt_mesh_target_elem_size_fact(0, GMSH_SET, WID->mesh_value[24]->value());
  opt_mesh_beta_smooth_metric(0, GMSH_SET, WID->mesh_value[25]->value());

  opt_mesh_point_type(0, GMSH_SET, WID->mesh_choice[0]->value());
  opt_mesh_line_type(0, GMSH_SET, WID->mesh_choice[1]->value());
  opt_mesh_algo2d(0, GMSH_SET,
		  (WID->mesh_choice[2]->value() == 0) ? DELAUNAY_ISO :
		  (WID->mesh_choice[2]->value() == 1) ? DELAUNAY_ANISO :
		  DELAUNAY_TRIANGLE);
  opt_mesh_recombine_algo(0, GMSH_SET,
		  (WID->mesh_choice[5]->value() == 0) ? 1 : 2);
  opt_mesh_algo3d(0, GMSH_SET,
		  (WID->mesh_choice[3]->value() == 0) ? DELAUNAY_ISO :
		  (WID->mesh_choice[3]->value() == 1) ? FRONTAL_NETGEN :
		  DELAUNAY_TETGEN);
  opt_mesh_color_carousel(0, GMSH_SET, WID->mesh_choice[4]->value());
  opt_mesh_quality_type(0, GMSH_SET, WID->mesh_choice[6]->value());
  opt_mesh_label_type(0, GMSH_SET, WID->mesh_choice[7]->value());
}

void mesh_cut_plane_cb(CALLBACK_ARGS)
{
  if(!CTX.mesh.use_cut_plane)
    return;

  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }

  opt_mesh_cut_planea(0, GMSH_SET, WID->mesh_value[14]->value());
  opt_mesh_cut_planeb(0, GMSH_SET, WID->mesh_value[15]->value());
  opt_mesh_cut_planec(0, GMSH_SET, WID->mesh_value[16]->value());
  opt_mesh_cut_planed(0, GMSH_SET, WID->mesh_value[17]->value());

  Draw();

  CTX.draw_bbox = old;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
}

void mesh_cut_plane_invert_cb(CALLBACK_ARGS)
{
  WID->mesh_value[14]->value(-WID->mesh_value[14]->value());
  WID->mesh_value[15]->value(-WID->mesh_value[15]->value());
  WID->mesh_value[16]->value(-WID->mesh_value[16]->value());
  WID->mesh_value[17]->value(-WID->mesh_value[17]->value());
  mesh_cut_plane_cb(NULL, NULL);
}

// Solver options

void solver_options_cb(CALLBACK_ARGS)
{
  WID->create_solver_options_window();
}

void solver_options_ok_cb(CALLBACK_ARGS)
{
  int old_listen = (int)opt_solver_listen(0, GMSH_GET, WID->solver_butt[0]->value());
  opt_solver_listen(0, GMSH_SET, WID->solver_butt[0]->value());
  if(!old_listen && WID->solver_butt[0]->value())
    Solver(-1, NULL);

  opt_solver_max_delay(0, GMSH_SET, WID->solver_value[0]->value());

  opt_solver_socket_name(0, GMSH_SET, (char *)WID->solver_input[0]->value());
}

// Post options

void post_options_cb(CALLBACK_ARGS)
{
  WID->create_post_options_window();
}

void post_options_ok_cb(CALLBACK_ARGS)
{
  opt_post_anim_cycle(0, GMSH_SET, WID->post_butt[0]->value());
  opt_post_combine_remove_orig(0, GMSH_SET, WID->post_butt[1]->value());
  opt_post_horizontal_scales(0, GMSH_SET, WID->post_butt[2]->value());

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
  char *name = (char*)data;
  int type;
  if(!strcmp(name, "Gamma"))
    type = 0;
  else if(!strcmp(name, "Eta"))
    type = 1;
  else
    type = 2;
  Create2DGraph(name, "# Elements", 100, 0, WID->quality[type]);
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
        strcat(buff, &c[5]);
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
  if(file_chooser(0, 1, "Save", "*")) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
		      "Cancel", "Replace", NULL, name))
          goto test;
    }
    WID->save_message(name);
  }
}

// Visibility Menu

void visibility_cb(CALLBACK_ARGS)
{
  // get the visibility info from the model, and update the browser accordingly
  WID->create_visibility_window();
  WID->vis_browser->clear();
  VisibilityManager::instance()->update(WID->vis_type->value());
  for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
    WID->vis_browser->add(VisibilityManager::instance()->getBrowserLine(i).c_str());
    if(VisibilityManager::instance()->getVisibility(i))
      WID->vis_browser->select(i + 1);
  }
  // active the delete button for physicals and partitions only!
  if(WID->vis_type->value() == 1 || WID->vis_type->value() == 2)
    WID->vis_push_butt[0]->activate();
  else
    WID->vis_push_butt[0]->deactivate();
}

void visibility_ok_cb(CALLBACK_ARGS)
{
  // if the browser is not empty, get the selections made in the
  // browser and apply them into the model
  if(VisibilityManager::instance()->getNumEntities()){
    CTX.mesh.changed = 1;
    VisibilityManager::instance()->setAllInvisible(WID->vis_type->value());
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++)
      if(WID->vis_browser->selected(i + 1))
	VisibilityManager::instance()->setVisibility(i, true, WID->vis_butt[0]->value());
    // then refresh the browser to account for recursive selections
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++)
      if(VisibilityManager::instance()->getVisibility(i))
	WID->vis_browser->select(i + 1);
    Draw();
  }
}

void visibility_save_cb(CALLBACK_ARGS)
{
  visibility_ok_cb(NULL, NULL);
  std::string str = VisibilityManager::instance()->getStringForGEO();
  add_infile((char*)str.c_str(), CTX.filename);
}

void visibility_delete_cb(CALLBACK_ARGS)
{
  if(WID->vis_type->value() == 1)
    GMODEL->deletePhysicalGroups();
  else if(WID->vis_type->value() == 2)
    GMODEL->deleteMeshPartitions();
  visibility_cb(NULL, NULL);
}

void visibility_sort_cb(CALLBACK_ARGS)
{
  char *str = (char*)data;
  int val;
  if(!strcmp(str, "type"))
    val = 1;
  else if(!strcmp(str, "number"))
    val = 2;
  else if(!strcmp(str, "name"))
    val = 3;
  else if(!strcmp(str, "-"))
    val = -1;
  else if(!strcmp(str, "+"))
    val = -2;
  else
    val = 0;

  if(val == 0) { // select or deselect everything
    int selectall = 0;
    for(int i = 0; i < WID->vis_browser->size(); i++)
      if(!WID->vis_browser->selected(i + 1)) {
        selectall = 1;
        break;
      }
    if(selectall)
      for(int i = 0; i < WID->vis_browser->size(); i++)
        WID->vis_browser->select(i + 1);
    else
      WID->vis_browser->deselect();
  }
  else if(val == -1){ // invert the selection
    int *state = new int[WID->vis_browser->size()];
    for(int i = 0; i < WID->vis_browser->size(); i++)
      state[i] = WID->vis_browser->selected(i + 1);
    WID->vis_browser->deselect();
    for(int i = 0; i < WID->vis_browser->size(); i++)
      if(!state[i]) WID->vis_browser->select(i + 1);
    delete [] state;
  }
  else if(val == -2){ // create new parameter name for selection
    for(int i = 0; i < WID->vis_browser->size(); i++){
      if(WID->vis_browser->selected(i + 1)){
	static char tmpstr[256];
	sprintf(tmpstr, "%d", VisibilityManager::instance()->getTag(i));
	WID->context_geometry_input[1]->value(tmpstr);
	break;
      }
    }
    WID->context_geometry_input[0]->value("NewName");
    WID->create_geometry_context_window(0);
  }
  else { // set new sorting mode
    VisibilityManager::instance()->setSortMode(val);
    visibility_cb(NULL, NULL);
  }
}

void visibility_number_cb(CALLBACK_ARGS)
{
  CTX.mesh.changed = 1;

  int type = (int)(long)data;
  bool val;
  if(type >= 100){ // show
    val = true;
    type -= 100;
  }
  else{ // hide
    val = false;
  }
  
  char *str = (char *)WID->vis_input[type]->value();  
  int all = !strcmp(str, "all") || !strcmp(str, "*");
  int num = all ? 0 : atoi(str); 
  VisibilityManager::instance()->setVisibilityByNumber(type, num, all, val);
  int pos = WID->vis_browser->position();
  visibility_cb(NULL, NULL);
  WID->vis_browser->position(pos);
  Draw();
}

// Clipping planes menu

void clip_cb(CALLBACK_ARGS)
{
  WID->create_clip_window();
}

void clip_num_cb(CALLBACK_ARGS)
{
  WID->reset_clip_browser();
}

void clip_update_cb(CALLBACK_ARGS)
{
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw){
    CTX.post.draw = 0;
    CTX.mesh.draw = 0;
  }

  int idx = WID->clip_choice->value();
  CTX.clip[idx] = 0;
  for(int i = 0; i < WID->clip_browser->size(); i++)
    if(WID->clip_browser->selected(i+1))
      CTX.clip[idx] += (1<<i);
  for(int i = 0; i < 4; i++)
    CTX.clip_plane[idx][i] = WID->clip_value[i]->value();
  Draw();

  CTX.draw_bbox = old;
  CTX.post.draw = 1;
  CTX.mesh.draw = 1;
}

void clip_invert_cb(CALLBACK_ARGS)
{
  for(int i = 0; i < 4; i++)
    WID->clip_value[i]->value(-WID->clip_value[i]->value());
  clip_update_cb(NULL, NULL);
}

void clip_reset_cb(CALLBACK_ARGS)
{
  for(int i = 0; i < 6; i++){
    CTX.clip[i] = 0;
    CTX.clip_plane[i][0] = 1.;
    for(int j = 1; j < 4; j++)
      CTX.clip_plane[i][j] = 0.;
  }
  WID->reset_clip_browser();
  Draw();
}

// Manipulator menu

void manip_cb(CALLBACK_ARGS)
{
  WID->create_manip_window();
}

void manip_update_cb(CALLBACK_ARGS)
{
  CTX.r[0] = WID->manip_value[0]->value();
  CTX.r[1] = WID->manip_value[1]->value();
  CTX.r[2] = WID->manip_value[2]->value();
  CTX.t[0] = WID->manip_value[3]->value();
  CTX.t[1] = WID->manip_value[4]->value();
  CTX.t[2] = WID->manip_value[5]->value();
  CTX.s[0] = WID->manip_value[6]->value();
  CTX.s[1] = WID->manip_value[7]->value();
  CTX.s[2] = WID->manip_value[8]->value();
  CTX.setQuaternionFromEulerAngles();
  Draw();
}

// Help Menu (if you change the following, please also change the
// texinfo documentation in doc/texinfo/shortcuts.texi)

#if defined(__APPLE__)
#  define CC(str) "Cmd+" str " "
#else
#  define CC(str) "Ctrl+" str
#endif

void help_short_cb(CALLBACK_ARGS)
{
  Msg(DIRECT, " ");
  Msg(DIRECT, "Keyboard shortcuts:");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Left arrow    Go to previous time step"); 
  Msg(DIRECT, "  Right arrow   Go to next time step"); 
  Msg(DIRECT, "  Up arrow      Make previous view visible"); 
  Msg(DIRECT, "  Down arrow    Make next view visible"); 
  Msg(DIRECT, " ");
  Msg(DIRECT, "  <             Go back to previous context");
  Msg(DIRECT, "  >             Go forward to next context");
  Msg(DIRECT, "  0             Reload project file");
  Msg(DIRECT, "  1 or F1       Mesh lines");
  Msg(DIRECT, "  2 or F2       Mesh surfaces");
  Msg(DIRECT, "  3 or F3       Mesh volumes");
  Msg(DIRECT, "  Escape        Cancel lasso zoom/selection, toggle mouse selection ON/OFF");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  g             Go to geometry module");
  Msg(DIRECT, "  m             Go to mesh module");
  Msg(DIRECT, "  p             Go to post-processing module");
  Msg(DIRECT, "  s             Go to solver module");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Shift+a       Bring all windows to front");
  Msg(DIRECT, "  Shift+g       Show geometry options");
  Msg(DIRECT, "  Shift+m       Show mesh options");
  Msg(DIRECT, "  Shift+o       Show general options"); 
  Msg(DIRECT, "  Shift+p       Show post-processing options");
  Msg(DIRECT, "  Shift+s       Show solver options"); 
  Msg(DIRECT, "  Shift+w       Show post-processing view options");
  Msg(DIRECT, "  Shift+Escape  Enable full mouse selection");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  " CC("i") "        Show statistics window"); 
  Msg(DIRECT, "  " CC("l") "        Show message console");
#if defined(__APPLE__)
  Msg(DIRECT, "  " CC("m") "        Minimize window"); 
#endif
  Msg(DIRECT, "  " CC("n") "        Create new project file"); 
  Msg(DIRECT, "  " CC("o") "        Open project file"); 
  Msg(DIRECT, "  " CC("q") "        Quit");
  Msg(DIRECT, "  " CC("r") "        Rename project file");
  Msg(DIRECT, "  " CC("s") "        Save file as");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Shift+" CC("c") "  Show clipping plane window");
  Msg(DIRECT, "  Shift+" CC("m") "  Show manipulator window"); 
  Msg(DIRECT, "  Shift+" CC("n") "  Show option window"); 
  Msg(DIRECT, "  Shift+" CC("o") "  Merge file(s)"); 
  Msg(DIRECT, "  Shift+" CC("s") "  Save mesh in default format");
  Msg(DIRECT, "  Shift+" CC("v") "  Show visibility window");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Alt+a         Loop through axes modes"); 
  Msg(DIRECT, "  Alt+b         Hide/show bounding boxes");
  Msg(DIRECT, "  Alt+c         Loop through predefined color schemes");
  Msg(DIRECT, "  Alt+f         Change redraw mode (fast/full)"); 
  Msg(DIRECT, "  Alt+g         Loop through axes modes for visible post-processing views"); 
  Msg(DIRECT, "  Alt+h         Hide/show all post-processing views"); 
  Msg(DIRECT, "  Alt+i         Hide/show all post-processing view scales");
  Msg(DIRECT, "  Alt+l         Hide/show geometry lines");
  Msg(DIRECT, "  Alt+m         Toggle visibility of all mesh entities");
  Msg(DIRECT, "  Alt+n         Hide/show all post-processing view annotations");
  Msg(DIRECT, "  Alt+o         Change projection mode (orthographic/perspective)");
  Msg(DIRECT, "  Alt+p         Hide/show geometry points");
  Msg(DIRECT, "  Alt+s         Hide/show geometry surfaces");
  Msg(DIRECT, "  Alt+t         Loop through interval modes for visible post-processing views"); 
  Msg(DIRECT, "  Alt+v         Hide/show geometry volumes");
  Msg(DIRECT, "  Alt+w         Enable/disable all lighting");
  Msg(DIRECT, "  Alt+x         Set X view"); 
  Msg(DIRECT, "  Alt+y         Set Y view"); 
  Msg(DIRECT, "  Alt+z         Set Z view"); 
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Alt+Shift+a   Hide/show small axes"); 
  Msg(DIRECT, "  Alt+Shift+b   Hide/show mesh volume faces");
  Msg(DIRECT, "  Alt+Shift+d   Hide/show mesh surface faces");
  Msg(DIRECT, "  Alt+Shift+l   Hide/show mesh lines");
  Msg(DIRECT, "  Alt+Shift+o   Adjust projection parameters");
  Msg(DIRECT, "  Alt+Shift+p   Hide/show mesh points");
  Msg(DIRECT, "  Alt+Shift+s   Hide/show mesh surface edges");
  Msg(DIRECT, "  Alt+Shift+v   Hide/show mesh volume edges");
  Msg(DIRECT, "  Alt+Shift+w   Reverse all mesh normals");
  Msg(DIRECT, "  Alt+Shift+x   Set -X view"); 
  Msg(DIRECT, "  Alt+Shift+y   Set -Y view"); 
  Msg(DIRECT, "  Alt+Shift+z   Set -Z view"); 
  Msg(DIRECT, " ");
  WID->create_message_window();
}

void help_mouse_cb(CALLBACK_ARGS)
{
  Msg(DIRECT, " ");
  Msg(DIRECT, "Mouse actions:");
  Msg(DIRECT, " ");
  Msg(DIRECT, "  Move                - Highlight the elementary geometrical entity");
  Msg(DIRECT, "                        currently under the mouse pointer and display");
  Msg(DIRECT, "                        its properties in the status bar");
  Msg(DIRECT, "                      - Resize a lasso zoom/(un)selection");
  Msg(DIRECT, "  Left button         - Rotate");
  Msg(DIRECT, "                      - Select an entity");
  Msg(DIRECT, "                      - Accept a lasso zoom/selection"); 
  Msg(DIRECT, "  Ctrl+Left button    Start a lasso zoom/(un)selection"); 
  Msg(DIRECT, "  Middle button       - Zoom");
  Msg(DIRECT, "                      - Unselect an entity");
  Msg(DIRECT, "                      - Accept a lasso zoom/unselection");
  Msg(DIRECT, "  Ctrl+Middle button  Orthogonalize display"); 
  Msg(DIRECT, "  Right button        - Pan");
  Msg(DIRECT, "                      - Cancel a lasso zoom/(un)selection");
  Msg(DIRECT, "                      - Pop-up menu on post-processing view button");
  Msg(DIRECT, "  Ctrl+Right button   Reset to default viewpoint");   
  Msg(DIRECT, " ");   
  Msg(DIRECT, "  For a 2 button mouse, Middle button = Shift+Left button");
  Msg(DIRECT, "  For a 1 button mouse, Middle button = Shift+Left button, Right button = Alt+Left button");
  Msg(DIRECT, " ");
  WID->create_message_window();
}

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
  char prog[1024], cmd[1024];
  FixWindowsPath(CTX.web_browser, prog);
  _replace_multi_format(prog, "http://www.geuz.org/gmsh/doc/texinfo/", cmd);
  SystemCall(cmd);
}

void help_credits_cb(CALLBACK_ARGS)
{
  char prog[1024], cmd[1024];
  FixWindowsPath(CTX.web_browser, prog);
  _replace_multi_format(prog, "http://www.geuz.org/gmsh/doc/CREDITS", cmd);
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
  char prog[1024], file[1024], cmd[1024];
  FixWindowsPath(CTX.editor, prog);
  FixWindowsPath(CTX.filename, file);
  _replace_multi_format(prog, file, cmd);
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
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  WID->create_geometry_context_window(1);

  while(1) {
    WID->g_opengl_window->AddPointMode = true;
    Msg(ONSCREEN, "Move mouse and/or enter coordinates\n"
	"[Press 'Shift' to hold position, 'e' to add point or 'q' to abort]");
    GVertex *v[SELECTION_MAX_HITS];
    GEdge *c[SELECTION_MAX_HITS];
    GFace *s[SELECTION_MAX_HITS];
    GRegion *r[SELECTION_MAX_HITS];
    int ne;
    char ib = SelectEntity(ENT_NONE, &ne, v, c, s, r);
    if(ib == 'e'){
      add_point(CTX.filename,
		(char*)WID->context_geometry_input[2]->value(),
		(char*)WID->context_geometry_input[3]->value(),
		(char*)WID->context_geometry_input[4]->value(),
		(char*)WID->context_geometry_input[5]->value());
      WID->reset_visibility();
      Draw();
    }
    if(ib == 'q'){
      WID->g_opengl_window->AddPointMode = false;
      break;
    }
  }

  Msg(ONSCREEN, "");
}

static void _new_multiline(int type)
{
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int n, p[100], ne;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  n = 0;
  while(1) {
    if(n == 0)
      Msg(ONSCREEN, "Select control points\n"
	  "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg(ONSCREEN, "Select control points\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &ne, v, c, s, r);
    if(ib == 'l') {
      for(int i = 0; i < ne; i++)
	p[n++] = v[i]->tag();
    }
    if(ib == 'r') {
      Msg(WARNING, "Entity de-selection not supported yet during multi-line creation");
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
      WID->reset_visibility();
      ZeroHighlight();
      Draw();
      n = 0;
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0, 0);
	Draw();
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
  }

  Msg(ONSCREEN, "");
}

void geometry_elementary_add_new_line_cb(CALLBACK_ARGS)
{
  // Disallow multiline selection at the moment, since multilines
  // dont't work so well...
  //
  //_new_multiline(0);
  //
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int n, p[100], ne;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  n = 0;
  while(1) {
    if(n == 0)
      Msg(ONSCREEN, "Select start point\n"
	  "[Press 'q' to abort]");
    if(n == 1)
      Msg(ONSCREEN, "Select end point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &ne, v, c, s, r);
    if(ib == 'l') {
      p[n++] = v[0]->tag();
    }
    if(ib == 'r') {
      Msg(WARNING, "Entity de-selection not supported yet during line creation");
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0, 0);
	Draw();
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(n == 2) {
      add_multline(2, p, CTX.filename);
      WID->reset_visibility();
      ZeroHighlight();
      Draw();
      n = 0;
    }
  }

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
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int n, p[100], ne;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  n = 0;
  while(1) {
    if(n == 0)
      Msg(ONSCREEN, "Select start point\n"
	  "[Press 'q' to abort]");
    if(n == 1)
      Msg(ONSCREEN, "Select center point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    if(n == 2)
      Msg(ONSCREEN, "Select end point\n"
	  "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, &ne, v, c, s, r);
    if(ib == 'l') {
      p[n++] = v[0]->tag();
    }
    if(ib == 'r') {
      Msg(WARNING, "Entity de-selection not supported yet during circle creation");
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0, 0);
	Draw();
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(n == 3) {
      add_circ(p[0], p[1], p[2], CTX.filename); // begin, center, end
      WID->reset_visibility();
      ZeroHighlight();
      Draw();
      n = 0;
    }
  }

  Msg(ONSCREEN, "");
}

void geometry_elementary_add_new_ellipse_cb(CALLBACK_ARGS)
{
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int n, p[100], ne;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  n = 0;
  while(1) {
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
    char ib = SelectEntity(ENT_POINT, &ne, v, c, s, r);
    if(ib == 'l') {
      p[n++] = v[0]->tag();
    }
    if(ib == 'r') {
      Msg(WARNING, "Entity de-selection not supported yet during ellipse creation");
    }
    if(ib == 'u') {
      if(n > 0){
	ZeroHighlightEntityNum(p[n-1], 0, 0, 0);
	Draw();
	n--;
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(n == 4) {
      add_ell(p[0], p[1], p[2], p[3], CTX.filename);
      WID->reset_visibility();
      ZeroHighlight();
      Draw();
      n = 0;
    }
  }

  Msg(ONSCREEN, "");
}

static void _new_surface_volume(int mode)
{
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int type, num, ne;

  List_T *List1 = List_Create(10, 10, sizeof(int));
  List_T *List2 = List_Create(10, 10, sizeof(int));

  if(mode == 2) {
    type = ENT_SURFACE;
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else {
    type = ENT_LINE;
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  Draw();

  while(1) {
    List_Reset(List1);
    List_Reset(List2);

    while(1) {
      if(type == ENT_LINE){
	if(!List_Nbr(List1))
	  Msg(ONSCREEN, "Select surface boundary\n"
	      "[Press 'q' to abort]");
	else
	  Msg(ONSCREEN, "Select surface boundary\n"
	      "[Press 'u' to undo last selection or 'q' to abort]");
      }
      else{
	if(!List_Nbr(List1))
	  Msg(ONSCREEN, "Select volume boundary\n"
	      "[Press 'q' to abort]");
	else
	  Msg(ONSCREEN, "Select volume boundary\n"
	      "[Press 'u' to undo last selection or 'q' to abort]");
      }

      char ib = SelectEntity(type, &ne, v, c, s, r);
      if(ib == 'q') {
        ZeroHighlight();
        Draw();
        goto stopall;
      }
      if(ib == 'u') {
	if(List_Nbr(List1) > 0){
	  List_Read(List1, List_Nbr(List1)-1, &num);
	  ZeroHighlightEntityNum(0,
				 (type == ENT_LINE) ? abs(num) : 0, 
				 (type != ENT_LINE) ? abs(num) : 0,
				 0);
	  List_Pop(List1);
	  Draw();
	}
      }
      if(ib == 'r') {
	Msg(WARNING, "Entity de-selection not supported yet during surface/volume creation");
      }
      if(ib == 'l') {
	int num = (type == ENT_LINE) ? c[0]->tag() : s[0]->tag();
	if(SelectContour(type, num, List1)) {
	  if(type == ENT_LINE)
	    add_lineloop(List1, CTX.filename, &num);
	  else
	    add_surfloop(List1, CTX.filename, &num);
	  List_Reset(List1);
	  List_Add(List2, &num);
	  while(1) {
	    if(!List_Nbr(List1))
	      Msg(ONSCREEN, "Select hole boundaries (if none, press 'e')\n"
		  "[Press 'e' to end selection or 'q' to abort]");
	    else
	      Msg(ONSCREEN, "Select hole boundaries\n"
		  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
	    ib = SelectEntity(type, &ne, v, c, s, r);
	    if(ib == 'q') {
	      ZeroHighlight();
	      Draw();
	      goto stopall;
	    }
	    if(ib == 'e') {
	      ZeroHighlight();
	      Draw();
	      List_Reset(List1);
	      break;
	    }
	    if(ib == 'u') {
	      if(List_Nbr(List1) > 0){
		List_Read(List1, List_Nbr(List1)-1, &num);	    
		ZeroHighlightEntityNum(0,
				       (type == ENT_LINE) ? abs(num) : 0, 
				       (type != ENT_LINE) ? abs(num) : 0,
				       0);
		List_Pop(List1);
		Draw();
	      }
	    }
	    if(ib == 'l') {
	      num = (type == ENT_LINE) ? c[0]->tag() : s[0]->tag();
	      if(SelectContour(type, num, List1)) {
		if(type == ENT_LINE)
		  add_lineloop(List1, CTX.filename, &num);
		else
		  add_surfloop(List1, CTX.filename, &num);
		List_Reset(List1);
		List_Add(List2, &num);
	      }
	    }
	    if(ib == 'r') {
	      Msg(WARNING, "Entity de-selection not supported yet during surface/volume creation");
	    }
	  }
	  if(List_Nbr(List2)) {
	    switch (mode) {
	    case 0: add_surf(List2, CTX.filename, 0, 2); break;
	    case 1: add_surf(List2, CTX.filename, 0, 1); break;
	    case 2: add_vol(List2, CTX.filename); break;
	    }
	    WID->reset_visibility();
	    ZeroHighlight();
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

static void _action_point_line_surface_volume(int action, int mode, char *what)
{
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  int type, ne;
  char *str;

  if(!strcmp(what, "Point")) {
    type = ENT_POINT;
    str = "points";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Line")) {
    type = ENT_LINE;
    str = "lines";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Surface")) {
    type = ENT_SURFACE;
    str = "surfaces";
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Volume")) {
    type = ENT_VOLUME;
    str = "volumes";
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else{
    Msg(GERROR, "Unknown entity to select");
    return;
  }

  if(action == 8){
    WID->create_mesh_context_window(0);
  }
  else if(action == 10){
    Msg(GERROR, "BDS->classify(angle, edge_prolongation) must be reinterfaced");
  }

  Draw();
    
  List_T *List1 = List_Create(5, 5, sizeof(int));
  while(1) {
    if(!List_Nbr(List1))
      Msg(ONSCREEN, "Select %s\n"
	  "[Press 'e' to end selection or 'q' to abort]", str);
    else
      Msg(ONSCREEN, "Select %s\n"
	  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]", str);

    char ib = SelectEntity(type, &ne, v, c, s, r);
    if(ib == 'l') {
      // we don't use List_Insert in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      for(int i = 0; i < ne; i++){
	int tag;
	switch (type) {
	case ENT_POINT: 
	  tag = v[i]->tag();
	  if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
	    List_Add(List1, &tag);
	  break;
	case ENT_LINE:
	  tag = c[i]->tag();
	  if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
	    List_Add(List1, &tag);
	  break;
	case ENT_SURFACE:
	  tag = s[i]->tag();
	  if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
	    List_Add(List1, &tag);
	  break;
	case ENT_VOLUME:
	  tag = r[i]->tag();
	  if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
	    List_Add(List1, &tag);
	  break;
	}
      }
    }
    if(ib == 'r') {
      // we don't use List_Suppress in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      for(int i = 0; i < ne; i++){
	int index, tag;
	switch (type) {
	case ENT_POINT:
	  tag = v[i]->tag();
	  index = List_ISearchSeq(List1, &tag, fcmp_int); 
	  if(index >= 0) List_PSuppress(List1, index);
	  ZeroHighlightEntityNum(tag, 0, 0, 0);
	  break;
	case ENT_LINE:
	  tag = c[i]->tag();
	  index = List_ISearchSeq(List1, &tag, fcmp_int); 
	  if(index >= 0) List_PSuppress(List1, index);
	  ZeroHighlightEntityNum(0, tag, 0, 0);
	  break;
	case ENT_SURFACE:
	  tag = s[i]->tag();
	  index = List_ISearchSeq(List1, &tag, fcmp_int); 
	  if(index >= 0) List_PSuppress(List1, index);
	  ZeroHighlightEntityNum(0, 0, tag, 0);
	  break;
	case ENT_VOLUME:
	  tag = r[i]->tag();
	  index = List_ISearchSeq(List1, &tag, fcmp_int); 
	  if(index >= 0) List_PSuppress(List1, index);
	  ZeroHighlightEntityNum(0, 0, 0, tag);
	  break;
	}
      }
      Draw();
    }
    if(ib == 'u') {
      if(List_Nbr(List1)) {
	int num;
	List_Read(List1, List_Nbr(List1)-1, &num);
	ZeroHighlightEntityNum((type == ENT_POINT) ? num : 0,
			       (type == ENT_LINE) ? num : 0,
			       (type == ENT_SURFACE) ? num : 0,
			       (type == ENT_VOLUME) ? num : 0);
	Draw();
	List_Pop(List1);
      }
    }
    if(ib == 'e') {
      if(List_Nbr(List1)){
	switch (action) {
	case 0:
	  translate(mode, List1, CTX.filename, what,
		    (char*)WID->context_geometry_input[6]->value(),
		    (char*)WID->context_geometry_input[7]->value(),
		    (char*)WID->context_geometry_input[8]->value());
	  break;
	case 1:
	  rotate(mode, List1, CTX.filename, what,
		 (char*)WID->context_geometry_input[12]->value(),
		 (char*)WID->context_geometry_input[13]->value(),
		 (char*)WID->context_geometry_input[14]->value(),
		 (char*)WID->context_geometry_input[9]->value(),
		 (char*)WID->context_geometry_input[10]->value(),
		 (char*)WID->context_geometry_input[11]->value(),
		 (char*)WID->context_geometry_input[15]->value());
	  break;
	case 2:
	  dilate(mode, List1, CTX.filename, what,
		 (char*)WID->context_geometry_input[16]->value(),
		 (char*)WID->context_geometry_input[17]->value(),
		 (char*)WID->context_geometry_input[18]->value(),
		 (char*)WID->context_geometry_input[19]->value());
	  break;
	case 3:
	  symmetry(mode, List1, CTX.filename, what,
		   (char*)WID->context_geometry_input[20]->value(),
		   (char*)WID->context_geometry_input[21]->value(),
		   (char*)WID->context_geometry_input[22]->value(),
		   (char*)WID->context_geometry_input[23]->value());
	  break;
	case 4:
	  extrude(List1, CTX.filename, what,
		  (char*)WID->context_geometry_input[6]->value(),
		  (char*)WID->context_geometry_input[7]->value(),
		  (char*)WID->context_geometry_input[8]->value());
	  break;
	case 5:
	  protude(List1, CTX.filename, what,
		  (char*)WID->context_geometry_input[12]->value(),
		  (char*)WID->context_geometry_input[13]->value(),
		  (char*)WID->context_geometry_input[14]->value(),
		  (char*)WID->context_geometry_input[9]->value(),
		  (char*)WID->context_geometry_input[10]->value(),
		  (char*)WID->context_geometry_input[11]->value(),
		  (char*)WID->context_geometry_input[15]->value());
	  break;
	case 6:
	  delet(List1, CTX.filename, what);
	  break;
	case 7:
	  add_physical(List1, CTX.filename, type);
	  break;
	case 8:
	  add_charlength(List1, CTX.filename, (char*)WID->context_mesh_input[0]->value());
	  break;
	case 9:
	  add_recosurf(List1, CTX.filename);
	  break;
	case 10:
	  Msg(GERROR, "BDS->get_geom and set status must be reinterfaced");
	  break;
	default:
	  Msg(GERROR, "Unknown action on selected entities");
	  break;
	}
	List_Reset(List1);
	WID->reset_visibility();
	ZeroHighlight();
	if(action <= 6) SetBoundingBox();
	Draw();
      }
    }
    if(ib == 'q') {
      if(action == 10){
	Msg(GERROR, "BDS->classify() must be reinterfaced");
      }
      ZeroHighlight();
      Draw();
      break;
    }
  }
  List_Delete(List1);

  Msg(ONSCREEN, "");
}
  
void geometry_elementary_add_translate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_translate, 0);
}

void geometry_elementary_add_translate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(0, 1, "Point");
}

void geometry_elementary_add_translate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(0, 1, "Line");
}

void geometry_elementary_add_translate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(0, 1, "Surface");
}

void geometry_elementary_translate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_translate, 0);
}

void geometry_elementary_translate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(0, 0, "Point");
}

void geometry_elementary_translate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(0, 0, "Line");
}

void geometry_elementary_translate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(0, 0, "Surface");
}

void geometry_elementary_add_rotate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_rotate, 0);
}

void geometry_elementary_add_rotate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(1, 1, "Point");
}

void geometry_elementary_add_rotate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(1, 1, "Line");
}

void geometry_elementary_add_rotate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(1, 1, "Surface");
}

void geometry_elementary_rotate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_rotate, 0);
}

void geometry_elementary_rotate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(1, 0, "Point");
}

void geometry_elementary_rotate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(1, 0, "Line");
}

void geometry_elementary_rotate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(1, 0, "Surface");
}

void geometry_elementary_add_scale_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_scale, 0);
}

void geometry_elementary_add_scale_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _action_point_line_surface_volume(2, 1, "Point");
}

void geometry_elementary_add_scale_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _action_point_line_surface_volume(2, 1, "Line");
}

void geometry_elementary_add_scale_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _action_point_line_surface_volume(2, 1, "Surface");
}

void geometry_elementary_scale_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_scale, 0);
}

void geometry_elementary_scale_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _action_point_line_surface_volume(2, 0, "Point");
}

void geometry_elementary_scale_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _action_point_line_surface_volume(2, 0, "Line");
}

void geometry_elementary_scale_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(4);
  _action_point_line_surface_volume(2, 0, "Surface");
}

void geometry_elementary_add_symmetry_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_add_symmetry, 0);
}

void geometry_elementary_add_symmetry_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _action_point_line_surface_volume(3, 1, "Point");
}

void geometry_elementary_add_symmetry_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _action_point_line_surface_volume(3, 1, "Line");
}

void geometry_elementary_add_symmetry_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _action_point_line_surface_volume(3, 1, "Surface");
}

void geometry_elementary_symmetry_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_symmetry, 0);
}

void geometry_elementary_symmetry_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _action_point_line_surface_volume(3, 0, "Point");
}

void geometry_elementary_symmetry_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _action_point_line_surface_volume(3, 0, "Line");
}

void geometry_elementary_symmetry_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(5);
  _action_point_line_surface_volume(3, 0, "Surface");
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
  _action_point_line_surface_volume(4, 0, "Point");
}

void geometry_elementary_extrude_translate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(4, 0, "Line");
}

void geometry_elementary_extrude_translate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(2);
  _action_point_line_surface_volume(4, 0, "Surface");
}

void geometry_elementary_extrude_rotate_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_extrude_rotate, 0);
}

void geometry_elementary_extrude_rotate_point_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(5, 0, "Point");
}

void geometry_elementary_extrude_rotate_line_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(5, 0, "Line");
}

void geometry_elementary_extrude_rotate_surface_cb(CALLBACK_ARGS)
{
  WID->create_geometry_context_window(3);
  _action_point_line_surface_volume(5, 0, "Surface");
}

void geometry_elementary_coherence_cb(CALLBACK_ARGS)
{
  coherence(CTX.filename);
}

void geometry_elementary_delete_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_elementary_delete, 0);
}

void geometry_elementary_delete_point_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(6, 0, "Point");
}

void geometry_elementary_delete_line_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(6, 0, "Line");
}

void geometry_elementary_delete_surface_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(6, 0, "Surface");
}

void geometry_physical_add_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_geometry_physical_add, 0);
}

void geometry_physical_add_point_cb(CALLBACK_ARGS)
{
  WID->call_for_solver_plugin(0);
  _action_point_line_surface_volume(7, 0, "Point");
}

void geometry_physical_add_line_cb(CALLBACK_ARGS)
{
  WID->call_for_solver_plugin(1);
  _action_point_line_surface_volume(7, 0, "Line");
}

void geometry_physical_add_surface_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(7, 0, "Surface");
}

void geometry_physical_add_volume_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(7, 0, "Volume");
}

// Dynamic Mesh Menus

void mesh_save_cb(CALLBACK_ARGS)
{
  char name[256];
  if(CTX.output_filename)
    strcpy(name, CTX.output_filename);
  else
    GetDefaultFileName(CTX.mesh.format, name);
  if(CTX.confirm_overwrite) {
    if(!StatFile(name))
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
		    "Cancel", "Replace", NULL, name))
	return;
  }
  CreateOutputFile(name, CTX.mesh.format);
}

void mesh_define_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_mesh_define, 0);
}

void mesh_1d_cb(CALLBACK_ARGS)
{
  mai3d(1);
  Draw();
  Msg(STATUS2N, " ");
}

void mesh_2d_cb(CALLBACK_ARGS)
{
  mai3d(2);
  Draw();
  Msg(STATUS2N, " ");
}

void mesh_3d_cb(CALLBACK_ARGS)
{
  mai3d(3);
  Draw();
  Msg(STATUS2N, " ");
}

void mesh_stl_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_mesh_stl, 0);
}

void mesh_degree_cb(CALLBACK_ARGS)
{
  switch ((long)data) {
  case 2: 
    Degre2(GMODEL->getMeshStatus());
    break;
  case 1:
  default:
    Degre1();
    break;
  }
  CTX.mesh.changed = 1;
  Draw();
  Msg(STATUS2N, " ");
}

void mesh_optimize_cb(CALLBACK_ARGS)
{
  if(CTX.threads_lock) {
    Msg(INFO, "I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;
  Optimize_Netgen();
  CTX.threads_lock = 0;

  CTX.mesh.changed = 1;
  Draw();
  Msg(STATUS2N, " ");
}

void mesh_remesh_cb(CALLBACK_ARGS)
{
  ReMesh();
  Draw();
  Msg(STATUS2N, " ");
}

void mesh_update_edges_cb(CALLBACK_ARGS)
{
  Msg(GERROR, "BDS->classify() must be reinterfaced");
}

void mesh_update_more_edges_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(10, 0, "Line");
}

void mesh_define_length_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(8, 0, "Point");
}

void mesh_define_recombine_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(9, 0, "Surface");
}

void mesh_define_transfinite_cb(CALLBACK_ARGS)
{
  WID->set_context(menu_mesh_define_transfinite, 0);
}

static void _add_transfinite_elliptic(int type, int dim)
{
  GVertex *v[SELECTION_MAX_HITS];
  GEdge *c[SELECTION_MAX_HITS];
  GFace *s[SELECTION_MAX_HITS];
  GRegion *r[SELECTION_MAX_HITS];
  char ib;
  int n, p[100], ne;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  switch (dim) {
  case 1: opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1); break;
  case 2: opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1); break;
  case 3: opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1); break;
  }
  Draw();

  n = 0;
  while(1) {
    switch (dim) {
    case 1:
      if(n == 0)
	Msg(ONSCREEN, "Select lines\n"
	    "[Press 'e' to end selection or 'q' to abort]");
      else
	Msg(ONSCREEN, "Select lines\n"
	    "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
      ib = SelectEntity(ENT_LINE, &ne, v, c, s, r);
      break;
    case 2:
      Msg(ONSCREEN, "Select surface\n[Press 'q' to abort]");
      ib = SelectEntity(ENT_SURFACE, &ne, v, c, s, r);
      break;
    case 3:
      Msg(ONSCREEN, "Select volume\n[Press 'q' to abort]");
      ib = SelectEntity(ENT_VOLUME, &ne, v, c, s, r);
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
      ZeroHighlight();
      Draw();
      n = 0;
    }
    if(ib == 'u') {
      if(dim == 1) {
        if(n > 0){
	  ZeroHighlightEntityNum(0, p[n-1], 0, 0);
	  Draw();
	  n--;
	}
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(ib == 'r') {
      Msg(WARNING, "Entity de-selection not supported yet during transfinite definition");
    }
    if(ib == 'l') {
      switch (dim) {
      case 1:
        p[n++] = c[0]->tag();
        break;
      case 2:
      case 3:
	if(dim == 2)
	  p[n++] = s[0]->tag(); 
	else
	  p[n++] = r[0]->tag(); 
        while(1) {
	  if(n == 1)
	    Msg(ONSCREEN, "Select (ordered) boundary points\n"
		"[Press 'e' to end selection or 'q' to abort]");
	  else
	    Msg(ONSCREEN, "Select (ordered) boundary points\n"
		"[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
          ib = SelectEntity(ENT_POINT, &ne, v, c, s, r);
          if(ib == 'l') {
            p[n++] = v[0]->tag();
          }
	  if(ib == 'u') {
	    if(n > 1){
	      ZeroHighlightEntityNum(p[n-1], 0, 0, 0);
	      Draw();
	      n--;
	    }
	  }
	  if(ib == 'r') {
	    Msg(WARNING, "Entity de-selection not supported yet during transfinite definition");
	  }
          if(ib == 'e') {
            switch (dim) {
            case 2:
              if(n == 3 + 1 || n == 4 + 1)
                add_trsfellisurf(type, n, p, CTX.filename,
				 (char*)WID->context_mesh_choice[1]->text());
              else
                Msg(GERROR, "Wrong number of points for %s surface",
		    type ? "elliptic" : "transfinite");
              break;
            case 3:
              if(n == 6 + 1 || n == 8 + 1)
                add_trsfvol(n, p, CTX.filename);
              else
                Msg(GERROR, "Wrong number of points for transfinite volume");
              break;
            }
            ZeroHighlight();
            Draw();
            n = 0;
            break;
          }
          if(ib == 'q') {
            ZeroHighlight();
            Draw();
            goto stopall;
          }
        }
        break;
      }
    }
  }

stopall:
  Msg(ONSCREEN, "");
}

void mesh_define_transfinite_line_cb(CALLBACK_ARGS)
{
  WID->create_mesh_context_window(1);
  _add_transfinite_elliptic(0, 1);
}

void mesh_define_transfinite_surface_cb(CALLBACK_ARGS)
{
  WID->create_mesh_context_window(2);
  _add_transfinite_elliptic(0, 2);
}

void mesh_define_transfinite_volume_cb(CALLBACK_ARGS)
{
  _add_transfinite_elliptic(0, 3);
}

void mesh_define_elliptic_surface_cb(CALLBACK_ARGS)
{
  _add_transfinite_elliptic(1, 2);
}

// Dynamic Solver Menus

void solver_cb(CALLBACK_ARGS)
{
  static int init = 0, first[MAXSOLVERS];
  int num = (int)(long)data;

  if(!init) {
    for(int i = 0; i < MAXSOLVERS; i++)
      first[i] = 1;
    init = 1;
  }

  if(first[num]) {
    char file[256];
    first[num] = 0;
    strcpy(file, CTX.base_filename);
    strcat(file, SINFO[num].extension);
    WID->solver[num].input[0]->value(file);
  }
  if(SINFO[num].nboptions) {
    char file[256], tmp[256];
    FixWindowsPath((char*)WID->solver[num].input[0]->value(), file);
    sprintf(tmp, "\"%s\"", file);
    sprintf(file, SINFO[num].name_command, tmp);
    sprintf(tmp, "%s %s", SINFO[num].option_command, file);           
    Solver(num, tmp);
  }
  WID->create_solver_window(num);
}

void solver_file_open_cb(CALLBACK_ARGS)
{
  char tmp[256];
  int num = (int)(long)data;
  sprintf(tmp, "*%s", SINFO[num].extension);

  // We allow to create the .pro file... Or should we add a "New file"
  // button?
  if(file_chooser(0, 1, "Choose", tmp)) {
    WID->solver[num].input[0]->value(file_chooser_get_name(1));
    if(SINFO[num].nboptions) {
      char file[1024];
      FixWindowsPath(file_chooser_get_name(1), file);
      sprintf(tmp, "\"%s\"", file);
      sprintf(file, SINFO[num].name_command, tmp);
      sprintf(tmp, "%s %s", SINFO[num].option_command, file);
      Solver(num, tmp);
    }
  }
}

void solver_file_edit_cb(CALLBACK_ARGS)
{
  char prog[1024], file[1024], cmd[1024];
  int num = (int)(long)data;
  FixWindowsPath(CTX.editor, prog);
  FixWindowsPath((char*)WID->solver[num].input[0]->value(), file);
  _replace_multi_format(prog, file, cmd);
  SystemCall(cmd);
}

void solver_choose_mesh_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose", "*.msh"))
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
    WID->create_message_window(true);

  if(strlen(WID->solver[num].input[1]->value())) {
    FixWindowsPath((char*)WID->solver[num].input[1]->value(), mesh);
    sprintf(tmp, "\"%s\"", mesh);
    sprintf(mesh, SINFO[num].mesh_command, tmp);
  }
  else {
    strcpy(mesh, "");
  }

  if(nbs(SINFO[num].button_command[idx])) {
    for(i = 0; i < idx; i++)
      usedopts += nbs(SINFO[num].button_command[i]);
    if(usedopts > SINFO[num].nboptions) {
      Msg(GERROR, "Missing options to execute command");
      return;
    }
    sprintf(command, SINFO[num].button_command[idx],
            SINFO[num].option[usedopts][WID->solver[num].choice[usedopts]->value()]);
  }
  else {
    strcpy(command, SINFO[num].button_command[idx]);
  }

  FixWindowsPath((char*)WID->solver[num].input[0]->value(), tmp);
  sprintf(arg, "\"%s\"", tmp);
  sprintf(tmp, SINFO[num].name_command, arg);
  sprintf(arg, "%s %s %s", tmp, mesh, command);
  Solver(num, arg);
}

void solver_kill_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  if(SINFO[num].pid > 0) {
    if(KillProcess(SINFO[num].pid))
      Msg(INFO, "Killed %s pid %d", SINFO[num].name, SINFO[num].pid);
  }
  SINFO[num].pid = -1;
}

void solver_choose_executable_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose",
#if defined(WIN32)
                  "*.exe"
#else
                  "*"
#endif
                  ))
    WID->solver[num].input[2]->value(file_chooser_get_name(1));
}

void solver_ok_cb(CALLBACK_ARGS)
{
  int retry = 0, num = (int)(long)data;
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
  int num = (int)(long)data;
  opt_view_visible(num, GMSH_SET,
                   WID->m_toggle_butt[num]->value());
  Draw();
}

static void _view_reload(int num)
{
  if(!CTX.post.list)
    return;

  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, num);

  if(StatFile(v->FileName)){
    Msg(GERROR, "File '%s' does not exist", v->FileName);
    return;
  }

  CTX.post.force_num = v->Num;
  MergeProblem(v->FileName);
  CTX.post.force_num = 0;

  Post_View *v2 = *(Post_View **) List_Pointer(CTX.post.list, num);
  CopyViewOptions(v, v2);

  // In case the reloaded view has a different number of time steps
  if(v2->TimeStep > v2->NbTimeStep - 1)
    v2->TimeStep = 0;

  FreeView(v);
}

void view_reload_cb(CALLBACK_ARGS)
{
  _view_reload((int)(long)data);
  Draw();
}

void view_reload_all_cb(CALLBACK_ARGS)
{
  for(int i = 0; i < List_Nbr(CTX.post.list); i++)
    _view_reload(i);
  Draw();
}

void view_reload_visible_cb(CALLBACK_ARGS)
{
  for(int i = 0; i < List_Nbr(CTX.post.list); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      _view_reload(i);
  Draw();
}

void view_remove_other_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list) return;
  for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--)
    if(i != (long)data)
      RemoveViewByIndex(i);
  UpdateViewsInGUI();
  Draw();
}

void view_remove_all_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list) return;
  while(List_Nbr(CTX.post.list))
    RemoveViewByIndex(0);
  UpdateViewsInGUI();
  Draw();
}

void view_remove_visible_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list) return;
  for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--)
    if(opt_view_visible(i, GMSH_GET, 0))
      RemoveViewByIndex(i);
  UpdateViewsInGUI();
  Draw();
}

void view_remove_invisible_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list) return;
  for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--)
    if(!opt_view_visible(i, GMSH_GET, 0))
      RemoveViewByIndex(i);
  UpdateViewsInGUI();
  Draw();
}

void view_remove_empty_cb(CALLBACK_ARGS)
{
  if(!CTX.post.list) return;
  for(int i = List_Nbr(CTX.post.list) - 1; i >= 0; i--){
    Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, i);
    if(v->empty())
      RemoveViewByIndex(i);
  }
  UpdateViewsInGUI();
  Draw();
}

void view_remove_cb(CALLBACK_ARGS)
{
  RemoveViewByIndex((int)(long)data);
  UpdateViewsInGUI();
  Draw();
}

static void _view_save_as(int view_num, char *title, int type)
{
  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, view_num);
  
 test:
  if(file_chooser(0, 1, title, "*", v->FileName)) {
    char *name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
		      "Cancel", "Replace", NULL, name))
          goto test;
    }
    WriteView(v, name, type, 0);
  }
}

void view_save_ascii_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As ASCII View", 0);
}

void view_save_binary_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Binary View", 1);
}

void view_save_parsed_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Parsed View", 2);
}

void view_save_stl_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As STL Triangulation", 3);
}

void view_save_txt_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Text", 4);
}

void view_save_msh_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Mesh", 5);
}

void view_alias_cb(CALLBACK_ARGS)
{
  AliasView((int)(long)data, 0);
  Draw();
}

void view_alias_with_options_cb(CALLBACK_ARGS)
{
  AliasView((int)(long)data, 1);
  Draw();
}

void view_combine_space_all_cb(CALLBACK_ARGS)
{
  CombineViews(0, 1, CTX.post.combine_remove_orig);
  Draw();
}

void view_combine_space_visible_cb(CALLBACK_ARGS)
{
  CombineViews(0, 0, CTX.post.combine_remove_orig);
  Draw();
}

void view_combine_space_by_name_cb(CALLBACK_ARGS)
{
  CombineViews(0, 2, CTX.post.combine_remove_orig);
  Draw();
}

void view_combine_time_all_cb(CALLBACK_ARGS)
{
  CombineViews(1, 1, CTX.post.combine_remove_orig);
  Draw();
}

void view_combine_time_visible_cb(CALLBACK_ARGS)
{
  CombineViews(1, 0, CTX.post.combine_remove_orig);
  Draw();
}

void view_combine_time_by_name_cb(CALLBACK_ARGS)
{
  CombineViews(1, 2, CTX.post.combine_remove_orig);
  Draw();
}

void view_all_visible_cb(CALLBACK_ARGS)
{
  for(int i = 0; i < List_Nbr(CTX.post.list); i ++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI, 
		     (long)data < 0 ? !opt_view_visible(i, GMSH_GET, 0) :
		     (long)data > 0 ? 1 : 0);
  Draw();
}

void view_applybgmesh_cb(CALLBACK_ARGS)
{
  Post_View *v = *(Post_View **) List_Pointer(CTX.post.list, (int)(long)data);
  if(!v->ScalarOnly || v->TextOnly) {
    Msg(GERROR, "Background mesh generation impossible with non-scalar view");
    return;
  }
  BGMWithView(v);
}

void view_options_cb(CALLBACK_ARGS)
{
  WID->create_view_options_window((int)(long)data);
}

void view_plugin_cancel_cb(CALLBACK_ARGS)
{
  if(data)
    ((Fl_Window *) data)->hide();
  if(CTX.post.plugin_draw_function){
    CTX.post.plugin_draw_function = NULL;
    Draw();
  }
}

void view_plugin_run_cb(CALLBACK_ARGS)
{
  GMSH_Post_Plugin *p = (GMSH_Post_Plugin *) data;
  char name[256];
  p->getName(name);
  int iView;

  if(p->dialogBox) { // get the values from the GUI
    iView = p->dialogBox->current_view_index;
    int m = p->getNbOptionsStr();
    int n = p->getNbOptions();
    if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;
    if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;
    for(int i = 0; i < m; i++) {
      StringXString *sxs = p->getOptionStr(i);
      sxs->def = (char*)p->dialogBox->input[i]->value();
    }
    for(int i = 0; i < n; i++) {
      StringXNumber *sxn = p->getOption(i);
      sxn->def = p->dialogBox->value[i]->value();
    }
  }
  else
    iView = 0;

  try {
    Post_View **vv = (Post_View **) List_Pointer_Test(CTX.post.list, iView);
    if(!vv)
      p->execute(0);
    else
      p->execute(*vv);
    CTX.post.plugin_draw_function = NULL;
    Draw();
  }
  catch(GMSH_Plugin * err) {
    p->catchErrorMessage(name);
    Msg(WARNING, "%s", name);
  }
}

void view_plugin_input_value_cb(CALLBACK_ARGS)
{
  double (*f)(int, int, double) = (double (*)(int, int, double)) data;
  Fl_Value_Input *input = (Fl_Value_Input*) w;
  f(-1, 0, input->value());
}

void view_plugin_input_cb(CALLBACK_ARGS)
{
  char* (*f)(int, int, char*) = (char* (*)(int, int, char*)) data;
  Fl_Input *input = (Fl_Input*) w;
  f(-1, 0, (char*)input->value());
}

void view_plugin_options_cb(CALLBACK_ARGS)
{
  std::pair<int, GMSH_Plugin *> *pair = (std::pair<int, GMSH_Plugin *>*) data;
  int iView = pair->first;
  GMSH_Plugin *p = pair->second;

  if(!p->dialogBox)
    p->dialogBox = WID->create_plugin_window(p);

  p->dialogBox->current_view_index = iView;
  p->dialogBox->run_button->callback(view_plugin_run_cb, (void *)p);

  // configure the input value fields (we get step, min and max by
  // calling the option function with action==1, 2 and 3,
  // respectively) and set the Fl_Value_Input callbacks
  int n = p->getNbOptions();
  if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;
  for(int i = 0; i < n; i++) {
    StringXNumber *sxn = p->getOption(i);
    if(sxn->function){
      p->dialogBox->value[i]->callback(view_plugin_input_value_cb, (void*)sxn->function);
      p->dialogBox->value[i]->step(sxn->function(iView, 1, 0.));
      p->dialogBox->value[i]->minimum(sxn->function(iView, 2, 0.));
      p->dialogBox->value[i]->maximum(sxn->function(iView, 3, 0.));
    }
  }

  // set the Fl_Input callbacks
  int m = p->getNbOptionsStr();
  if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;
  for(int i = 0; i < m; i++) {
    StringXString *sxs = p->getOptionStr(i);
    if(sxs->function){
      p->dialogBox->input[i]->callback(view_plugin_input_cb, (void*)sxs->function);
    }
  }

  p->dialogBox->main_window->show();
}

void view_options_timestep_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == WID->view_number)) {
      opt_view_timestep(i, GMSH_SET, ((Fl_Value_Input *) w)->value());
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
       (links == 0 && i == WID->view_number)) {
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
       (links == 0 && i == WID->view_number)) {
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) + 1);
    }
  }
  Draw();
}

void view_options_custom_set_cb(CALLBACK_ARGS)
{
  char *str = (char*)data;

  if(!strcmp(str, "Min")){
    WID->view_value[31]->value(opt_view_min(WID->view_number, GMSH_GET, 0));
  }
  else if(!strcmp(str, "Max")){
    WID->view_value[32]->value(opt_view_max(WID->view_number, GMSH_GET, 0));
  }
}

void view_options_ok_cb(CALLBACK_ARGS)
{
  int current = (int)(long)data;

  if(current < 0)
    return;

  int force = 0, links = (int)opt_post_link(0, GMSH_GET, 0);

  // get the old values for the current view

  double scale_type = opt_view_scale_type(current, GMSH_GET, 0);
  double intervals_type = opt_view_intervals_type(current, GMSH_GET, 0);
  double point_type = opt_view_point_type(current, GMSH_GET, 0);
  double line_type = opt_view_line_type(current, GMSH_GET, 0);
  double vector_type = opt_view_vector_type(current, GMSH_GET, 0);
  double glyph_location = opt_view_glyph_location(current, GMSH_GET, 0);
  double tensor_type = opt_view_tensor_type(current, GMSH_GET, 0);
  double range_type = opt_view_range_type(current, GMSH_GET, 0);
  double axes = opt_view_axes(current, GMSH_GET, 0);
  double boundary = opt_view_boundary(current, GMSH_GET, 0);
  double external_view = opt_view_external_view(current, GMSH_GET, 0);
  double gen_raise_view = opt_view_gen_raise_view(current, GMSH_GET, 0);
  double show_time = opt_view_show_time(current, GMSH_GET, 0);

  double type = opt_view_type(current, GMSH_GET, 0);
  double saturate_values = opt_view_saturate_values(current, GMSH_GET, 0);
  double max_recursion_level = opt_view_max_recursion_level(current, GMSH_GET, 0);
  double target_error = opt_view_target_error(current, GMSH_GET, 0);
  double show_element = opt_view_show_element(current, GMSH_GET, 0);
  double show_scale = opt_view_show_scale(current, GMSH_GET, 0);
  double auto_position = opt_view_auto_position(current, GMSH_GET, 0);
  double axes_auto_position = opt_view_axes_auto_position(current, GMSH_GET, 0);
  double draw_strings = opt_view_draw_strings(current, GMSH_GET, 0);
  double light = opt_view_light(current, GMSH_GET, 0);
  double light_two_side = opt_view_light_two_side(current, GMSH_GET, 0);
  double light_lines = opt_view_light_lines(current, GMSH_GET, 0);
  double smooth_normals = opt_view_smooth_normals(current, GMSH_GET, 0);
  double draw_points = opt_view_draw_points(current, GMSH_GET, 0);
  double draw_lines = opt_view_draw_lines(current, GMSH_GET, 0);
  double draw_triangles = opt_view_draw_triangles(current, GMSH_GET, 0);
  double draw_quadrangles = opt_view_draw_quadrangles(current, GMSH_GET, 0);
  double draw_tetrahedra = opt_view_draw_tetrahedra(current, GMSH_GET, 0);
  double draw_hexahedra = opt_view_draw_hexahedra(current, GMSH_GET, 0);
  double draw_prisms = opt_view_draw_prisms(current, GMSH_GET, 0);
  double draw_pyramids = opt_view_draw_pyramids(current, GMSH_GET, 0);
  double draw_scalars = opt_view_draw_scalars(current, GMSH_GET, 0);
  double draw_vectors = opt_view_draw_vectors(current, GMSH_GET, 0);
  double draw_tensors = opt_view_draw_tensors(current, GMSH_GET, 0);
  double use_gen_raise = opt_view_use_gen_raise(current, GMSH_GET, 0);
  double fake_transparency = opt_view_fake_transparency(current, GMSH_GET, 0);
  double use_stipple = opt_view_use_stipple(current, GMSH_GET, 0);

  double normals = opt_view_normals(current, GMSH_GET, 0);
  double tangents = opt_view_tangents(current, GMSH_GET, 0);
  double custom_min = opt_view_custom_min(current, GMSH_GET, 0);
  double custom_max = opt_view_custom_max(current, GMSH_GET, 0);
  double nb_iso = opt_view_nb_iso(current, GMSH_GET, 0);
  double offset0 = opt_view_offset0(current, GMSH_GET, 0);
  double offset1 = opt_view_offset1(current, GMSH_GET, 0);
  double offset2 = opt_view_offset2(current, GMSH_GET, 0);
  double transform00 = opt_view_transform00(current, GMSH_GET, 0);
  double transform01 = opt_view_transform01(current, GMSH_GET, 0);
  double transform02 = opt_view_transform02(current, GMSH_GET, 0);
  double transform10 = opt_view_transform10(current, GMSH_GET, 0);
  double transform11 = opt_view_transform11(current, GMSH_GET, 0);
  double transform12 = opt_view_transform12(current, GMSH_GET, 0);
  double transform20 = opt_view_transform20(current, GMSH_GET, 0);
  double transform21 = opt_view_transform21(current, GMSH_GET, 0);
  double transform22 = opt_view_transform22(current, GMSH_GET, 0);
  double raise0 = opt_view_raise0(current, GMSH_GET, 0);
  double raise1 = opt_view_raise1(current, GMSH_GET, 0);
  double raise2 = opt_view_raise2(current, GMSH_GET, 0);
  double timestep = opt_view_timestep(current, GMSH_GET, 0);
  double arrow_size = opt_view_arrow_size(current, GMSH_GET, 0);
  double arrow_size_proportional = opt_view_arrow_size_proportional(current, GMSH_GET, 0);
  double displacement_factor = opt_view_displacement_factor(current, GMSH_GET, 0);
  double point_size = opt_view_point_size(current, GMSH_GET, 0);
  double line_width = opt_view_line_width(current, GMSH_GET, 0);
  double explode = opt_view_explode(current, GMSH_GET, 0);
  double angle_smooth_normals = opt_view_angle_smooth_normals(current, GMSH_GET, 0);
  double position0 = opt_view_position0(current, GMSH_GET, 0);
  double position1 = opt_view_position1(current, GMSH_GET, 0);
  double size0 = opt_view_size0(current, GMSH_GET, 0);
  double size1 = opt_view_size1(current, GMSH_GET, 0);
  double axes_tics0 = opt_view_axes_tics0(current, GMSH_GET, 0);
  double axes_tics1 = opt_view_axes_tics1(current, GMSH_GET, 0);
  double axes_tics2 = opt_view_axes_tics2(current, GMSH_GET, 0);
  double axes_xmin = opt_view_axes_xmin(current, GMSH_GET, 0);
  double axes_ymin = opt_view_axes_ymin(current, GMSH_GET, 0);
  double axes_zmin = opt_view_axes_zmin(current, GMSH_GET, 0);
  double axes_xmax = opt_view_axes_xmax(current, GMSH_GET, 0);
  double axes_ymax = opt_view_axes_ymax(current, GMSH_GET, 0);
  double axes_zmax = opt_view_axes_zmax(current, GMSH_GET, 0);
  double gen_raise_factor = opt_view_gen_raise_factor(current, GMSH_GET, 0);

  char name[256];
  strcpy(name, opt_view_name(current, GMSH_GET, NULL));
  char format[256];
  strcpy(format, opt_view_format(current, GMSH_GET, NULL));
  char axes_label0[256];
  strcpy(axes_label0, opt_view_axes_label0(current, GMSH_GET, NULL));
  char axes_label1[256];
  strcpy(axes_label1, opt_view_axes_label1(current, GMSH_GET, NULL));
  char axes_label2[256];
  strcpy(axes_label2, opt_view_axes_label2(current, GMSH_GET, NULL));
  char axes_format0[256];
  strcpy(axes_format0, opt_view_axes_format0(current, GMSH_GET, NULL));
  char axes_format1[256];
  strcpy(axes_format1, opt_view_axes_format1(current, GMSH_GET, NULL));
  char axes_format2[256];
  strcpy(axes_format2, opt_view_axes_format2(current, GMSH_GET, NULL));
  char gen_raise0[256];
  strcpy(gen_raise0, opt_view_gen_raise0(current, GMSH_GET, NULL));
  char gen_raise1[256];
  strcpy(gen_raise1, opt_view_gen_raise1(current, GMSH_GET, NULL));
  char gen_raise2[256];
  strcpy(gen_raise2, opt_view_gen_raise2(current, GMSH_GET, NULL));

  // modify only the views that need to be updated
  for(int i = 0; i < List_Nbr(CTX.post.list); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == current)) {

      if(links == 3 || links == 4)
        force = 1;

      double val;

      // view_choice

      switch (WID->view_choice[1]->value()) {
      case 0: val = DRAW_POST_LINEAR; break;
      case 1: val = DRAW_POST_LOGARITHMIC; break;
      default: val = DRAW_POST_DOUBLELOGARITHMIC; break; // 2
      }
      if(force || (val != scale_type))
        opt_view_scale_type(i, GMSH_SET, val);

      switch (WID->view_choice[0]->value()) {
      case 0: val = DRAW_POST_ISO; break;
      case 1: val = DRAW_POST_DISCRETE; break;
      case 2: val = DRAW_POST_CONTINUOUS; break;
      default: val = DRAW_POST_NUMERIC; break; // 3
      }
      if(force || (val != intervals_type))
	opt_view_intervals_type(i, GMSH_SET, val);
      
      val = WID->view_choice[5]->value();
      if(force || (val != point_type))
	opt_view_point_type(i, GMSH_SET, val);
      
      val = WID->view_choice[6]->value();
      if(force || (val != line_type))
        opt_view_line_type(i, GMSH_SET, val);

      switch (WID->view_choice[2]->value()) {
      case 0: val = DRAW_POST_SEGMENT; break;
      case 1: val = DRAW_POST_ARROW; break;
      case 2: val = DRAW_POST_PYRAMID; break;
      case 4: val = DRAW_POST_DISPLACEMENT; break;
      default: val = DRAW_POST_ARROW3D; break; // 3
      }
      if(force || (val != vector_type))
        opt_view_vector_type(i, GMSH_SET, val);

      switch (WID->view_choice[3]->value()) {
      case 0: val = DRAW_POST_LOCATE_COG; break;
      default: val = DRAW_POST_LOCATE_VERTEX; break;
      }
      if(force || (val != glyph_location))
        opt_view_glyph_location(i, GMSH_SET, val);

     switch (WID->view_choice[4]->value()) {
     case 0: val = DRAW_POST_VONMISES; break;
     case 2: val = DRAW_POST_LMGC90_TYPE; break;
     case 3: val = DRAW_POST_LMGC90_COORD; break;
     case 4: val = DRAW_POST_LMGC90_PRES; break;
     case 5: val = DRAW_POST_LMGC90_SN; break;
     case 6: val = DRAW_POST_LMGC90_DEPX; break;
     case 7: val = DRAW_POST_LMGC90_DEPY; break;
     case 8: val = DRAW_POST_LMGC90_DEPZ; break;
     case 9: val = DRAW_POST_LMGC90_DEPAV; break;
     case 10: val = DRAW_POST_LMGC90_DEPNORM; break;
     default: val = DRAW_POST_LMGC90; break; // 1
     }
     if(force || (val != tensor_type))
       opt_view_tensor_type(i, GMSH_SET, val);

      switch (WID->view_choice[7]->value()) {
      case 0: val = DRAW_POST_RANGE_DEFAULT; break;
      case 1: val = DRAW_POST_RANGE_PER_STEP; break;
      default: val = DRAW_POST_RANGE_CUSTOM; break; // 2
      }
      if(force || (val != range_type))
        opt_view_range_type(i, GMSH_SET, val);

      val = WID->view_choice[8]->value();
      if(force || (val != axes))
        opt_view_axes(i, GMSH_SET, val);

      val = WID->view_choice[9]->value();
      if(force || (val != boundary))
        opt_view_boundary(i, GMSH_SET, val);

      val = WID->view_choice[10]->value() - 1;
      if(force || (val != external_view))
        opt_view_external_view(i, GMSH_SET, val);

      val = WID->view_choice[11]->value() - 1;
      if(force || (val != gen_raise_view))
        opt_view_gen_raise_view(i, GMSH_SET, val);

      val = WID->view_choice[12]->value();
      if(force || (val != show_time))
        opt_view_show_time(i, GMSH_SET, val);
      
      switch(WID->view_choice[13]->value()){
      case 0: val = DRAW_POST_3D; break;
      case 1: val = DRAW_POST_2D_SPACE; break;
      default: val = DRAW_POST_2D_TIME; break; // 2
      }
      if(force || (val != type))
        opt_view_type(i, GMSH_SET, val);

      // view_butts

      val = WID->view_butt[0]->value();
      if(force || (val != arrow_size_proportional))
        opt_view_arrow_size_proportional(i, GMSH_SET, val);

      val = WID->view_butt[38]->value();
      if(force || (val != saturate_values))
        opt_view_saturate_values(i, GMSH_SET, val);

      val = WID->view_butt[10]->value();
      if(force || (val != show_element))
        opt_view_show_element(i, GMSH_SET, val);

      val = WID->view_butt[4]->value();
      if(force || (val != show_scale))
        opt_view_show_scale(i, GMSH_SET, val);

      val = WID->view_butt[7]->value();
      if(force || (val != auto_position))
        opt_view_auto_position(i, GMSH_SET, val);

      val = WID->view_butt[25]->value();
      if(force || (val != axes_auto_position))
        opt_view_axes_auto_position(i, GMSH_SET, val);

      val = WID->view_butt[5]->value();
      if(force || (val != draw_strings))
        opt_view_draw_strings(i, GMSH_SET, val);

      val = WID->view_butt[11]->value();
      if(force || (val != light))
        opt_view_light(i, GMSH_SET, val);

      val = WID->view_butt[8]->value();
      if(force || (val != light_lines))
        opt_view_light_lines(i, GMSH_SET, val);

      val = WID->view_butt[9]->value();
      if(force || (val != light_two_side))
        opt_view_light_two_side(i, GMSH_SET, val);

      val = WID->view_butt[12]->value();
      if(force || (val != smooth_normals))
        opt_view_smooth_normals(i, GMSH_SET, val);

      val = WID->view_menu_butt[0]->menu()[0].value() ? 1 : 0;
      if(force || (val != draw_scalars))
        opt_view_draw_scalars(i, GMSH_SET, val);

      val = WID->view_menu_butt[0]->menu()[1].value() ? 1 : 0;
      if(force || (val != draw_vectors))
        opt_view_draw_vectors(i, GMSH_SET, val);

      val = WID->view_menu_butt[0]->menu()[2].value() ? 1 : 0;
      if(force || (val != draw_tensors))
        opt_view_draw_tensors(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[0].value() ? 1 : 0;
      if(force || (val != draw_points))
        opt_view_draw_points(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[1].value() ? 1 : 0;
      if(force || (val != draw_lines))
        opt_view_draw_lines(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[2].value() ? 1 : 0;
      if(force || (val != draw_triangles))
        opt_view_draw_triangles(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[3].value() ? 1 : 0;
      if(force || (val != draw_quadrangles))
        opt_view_draw_quadrangles(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[4].value() ? 1 : 0;
      if(force || (val != draw_tetrahedra))
        opt_view_draw_tetrahedra(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[5].value() ? 1 : 0;
      if(force || (val != draw_hexahedra))
        opt_view_draw_hexahedra(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[6].value() ? 1 : 0;
      if(force || (val != draw_prisms))
        opt_view_draw_prisms(i, GMSH_SET, val);

      val = WID->view_menu_butt[1]->menu()[7].value() ? 1 : 0;
      if(force || (val != draw_pyramids))
        opt_view_draw_pyramids(i, GMSH_SET, val);

      val = WID->view_butt[6]->value();
      if(force || (val != use_gen_raise))
        opt_view_use_gen_raise(i, GMSH_SET, val);

      val = WID->view_butt[24]->value();
      if(force || (val != fake_transparency))
        opt_view_fake_transparency(i, GMSH_SET, val);

      val = WID->view_butt[26]->value();
      if(force || (val != use_stipple))
        opt_view_use_stipple(i, GMSH_SET, val);

      // view_values
      
      val = WID->view_value[0]->value();
      if(force || (val != normals))
        opt_view_normals(i, GMSH_SET, val);

      val = WID->view_value[1]->value();
      if(force || (val != tangents))
        opt_view_tangents(i, GMSH_SET, val);

      val = WID->view_value[31]->value();
      if(force || (val != custom_min))
        opt_view_custom_min(i, GMSH_SET, val);

      val = WID->view_value[32]->value();
      if(force || (val != custom_max))
        opt_view_custom_max(i, GMSH_SET, val);

      val = WID->view_value[33]->value();
      if(force || (val != max_recursion_level))
        opt_view_max_recursion_level(i, GMSH_SET, val);

      val = WID->view_value[34]->value();
      if(force || (val != target_error))
        opt_view_target_error(i, GMSH_SET, val);

      val = WID->view_value[30]->value();
      if(force || (val != nb_iso))
        opt_view_nb_iso(i, GMSH_SET, val);

      val = WID->view_value[40]->value();
      if(force || (val != offset0))
        opt_view_offset0(i, GMSH_SET, val);

      val = WID->view_value[41]->value();
      if(force || (val != offset1))
        opt_view_offset1(i, GMSH_SET, val);

      val = WID->view_value[42]->value();
      if(force || (val != offset2))
        opt_view_offset2(i, GMSH_SET, val);

      val = WID->view_value[51]->value();
      if(force || (val != transform00))
        opt_view_transform00(i, GMSH_SET, val);

      val = WID->view_value[52]->value();
      if(force || (val != transform01))
        opt_view_transform01(i, GMSH_SET, val);

      val = WID->view_value[53]->value();
      if(force || (val != transform02))
        opt_view_transform02(i, GMSH_SET, val);

      val = WID->view_value[54]->value();
      if(force || (val != transform10))
        opt_view_transform10(i, GMSH_SET, val);

      val = WID->view_value[55]->value();
      if(force || (val != transform11))
        opt_view_transform11(i, GMSH_SET, val);

      val = WID->view_value[56]->value();
      if(force || (val != transform12))
        opt_view_transform12(i, GMSH_SET, val);

      val = WID->view_value[57]->value();
      if(force || (val != transform20))
        opt_view_transform20(i, GMSH_SET, val);

      val = WID->view_value[58]->value();
      if(force || (val != transform21))
        opt_view_transform21(i, GMSH_SET, val);

      val = WID->view_value[59]->value();
      if(force || (val != transform22))
        opt_view_transform22(i, GMSH_SET, val);

      val = WID->view_value[43]->value();
      if(force || (val != raise0))
        opt_view_raise0(i, GMSH_SET, val);

      val = WID->view_value[44]->value();
      if(force || (val != raise1))
        opt_view_raise1(i, GMSH_SET, val);

      val = WID->view_value[45]->value();
      if(force || (val != raise2))
        opt_view_raise2(i, GMSH_SET, val);

      val = WID->view_value[50]->value();
      if(force || (val != timestep))
        opt_view_timestep(i, GMSH_SET, val);

      val = WID->view_value[60]->value();
      if(force || (val != arrow_size))
        opt_view_arrow_size(i, GMSH_SET, val);

      val = WID->view_value[63]->value();
      if(force || (val != displacement_factor))
        opt_view_displacement_factor(i, GMSH_SET, val);

      val = WID->view_value[61]->value();
      if(force || (val != point_size))
        opt_view_point_size(i, GMSH_SET, val);

      val = WID->view_value[62]->value();
      if(force || (val != line_width))
        opt_view_line_width(i, GMSH_SET, val);

      val = WID->view_value[12]->value();
      if(force || (val != explode))
        opt_view_explode(i, GMSH_SET, val);

      val = WID->view_value[10]->value();
      if(force || (val != angle_smooth_normals))
        opt_view_angle_smooth_normals(i, GMSH_SET, val);

      val = WID->view_value[20]->value();
      if(force || (val != position0))
        opt_view_position0(i, GMSH_SET, val);

      val = WID->view_value[21]->value();
      if(force || (val != position1))
        opt_view_position1(i, GMSH_SET, val);

      val = WID->view_value[22]->value();
      if(force || (val != size0))
        opt_view_size0(i, GMSH_SET, val);
      
      val = WID->view_value[23]->value();
      if(force || (val != size1))
        opt_view_size1(i, GMSH_SET, val);

      val = WID->view_value[13]->value();
      if(force || (val != axes_xmin))
        opt_view_axes_xmin(i, GMSH_SET, val);

      val = WID->view_value[14]->value();
      if(force || (val != axes_ymin))
        opt_view_axes_ymin(i, GMSH_SET, val);

      val = WID->view_value[15]->value();
      if(force || (val != axes_zmin))
        opt_view_axes_zmin(i, GMSH_SET, val);

      val = WID->view_value[16]->value();
      if(force || (val != axes_xmax))
        opt_view_axes_xmax(i, GMSH_SET, val);

      val = WID->view_value[17]->value();
      if(force || (val != axes_ymax))
        opt_view_axes_ymax(i, GMSH_SET, val);

      val = WID->view_value[18]->value();
      if(force || (val != axes_zmax))
        opt_view_axes_zmax(i, GMSH_SET, val);

      val = WID->view_value[2]->value();
      if(force || (val != gen_raise_factor))
        opt_view_gen_raise_factor(i, GMSH_SET, val);

      val = WID->view_value[3]->value();
      if(force || (val != axes_tics0))
        opt_view_axes_tics0(i, GMSH_SET, val);

      val = WID->view_value[4]->value();
      if(force || (val != axes_tics1))
        opt_view_axes_tics1(i, GMSH_SET, val);

      val = WID->view_value[5]->value();
      if(force || (val != axes_tics2))
        opt_view_axes_tics2(i, GMSH_SET, val);

      // view_inputs

      char *str;

      str = (char *)WID->view_input[0]->value();
      if(force || strcmp(str, name))
        opt_view_name(i, GMSH_SET, str);

      str = (char *)WID->view_input[1]->value();
      if(force || strcmp(str, format))
        opt_view_format(i, GMSH_SET, str);

      str = (char *)WID->view_input[10]->value();
      if(force || strcmp(str, axes_label0))
        opt_view_axes_label0(i, GMSH_SET, str);

      str = (char *)WID->view_input[11]->value();
      if(force || strcmp(str, axes_label1))
        opt_view_axes_label1(i, GMSH_SET, str);

      str = (char *)WID->view_input[12]->value();
      if(force || strcmp(str, axes_label2))
        opt_view_axes_label2(i, GMSH_SET, str);

      str = (char *)WID->view_input[7]->value();
      if(force || strcmp(str, axes_format0))
        opt_view_axes_format0(i, GMSH_SET, str);

      str = (char *)WID->view_input[8]->value();
      if(force || strcmp(str, axes_format1))
        opt_view_axes_format1(i, GMSH_SET, str);

      str = (char *)WID->view_input[9]->value();
      if(force || strcmp(str, axes_format2))
        opt_view_axes_format2(i, GMSH_SET, str);

      str = (char *)WID->view_input[4]->value();
      if(force || strcmp(str, gen_raise0))
        opt_view_gen_raise0(i, GMSH_SET, str);

      str = (char *)WID->view_input[5]->value();
      if(force || strcmp(str, gen_raise1))
        opt_view_gen_raise1(i, GMSH_SET, str);

      str = (char *)WID->view_input[6]->value();
      if(force || strcmp(str, gen_raise2))
        opt_view_gen_raise2(i, GMSH_SET, str);

      // colors (since the color buttons modify the values directly
      // through callbacks, we can use the opt_XXX routines directly)
      if(force || (i != current)){
        opt_view_color_points(i, GMSH_SET, opt_view_color_points(current, GMSH_GET, 0));
	opt_view_color_lines(i, GMSH_SET, opt_view_color_lines(current, GMSH_GET, 0));
	opt_view_color_triangles(i, GMSH_SET, opt_view_color_triangles(current, GMSH_GET, 0));
	opt_view_color_quadrangles(i, GMSH_SET, opt_view_color_quadrangles(current, GMSH_GET, 0));
        opt_view_color_tetrahedra(i, GMSH_SET, opt_view_color_tetrahedra(current, GMSH_GET, 0));
        opt_view_color_hexahedra(i, GMSH_SET, opt_view_color_hexahedra(current, GMSH_GET, 0));
        opt_view_color_prisms(i, GMSH_SET, opt_view_color_prisms(current, GMSH_GET, 0));
        opt_view_color_pyramids(i, GMSH_SET, opt_view_color_pyramids(current, GMSH_GET, 0));
        opt_view_color_tangents(i, GMSH_SET, opt_view_color_tangents(current, GMSH_GET, 0));
        opt_view_color_normals(i, GMSH_SET, opt_view_color_normals(current, GMSH_GET, 0));
        opt_view_color_text2d(i, GMSH_SET, opt_view_color_text2d(current, GMSH_GET, 0));
        opt_view_color_text3d(i, GMSH_SET, opt_view_color_text3d(current, GMSH_GET, 0));
        opt_view_color_axes(i, GMSH_SET, opt_view_color_axes(current, GMSH_GET, 0));
      }

      // colorbar window

      if(force || (WID->view_colorbar_window->changed() && i != current)) {
	Post_View *src = *(Post_View **)List_Pointer(CTX.post.list, current);
	Post_View *dest = *(Post_View **)List_Pointer(CTX.post.list, i);
        ColorTable_Copy(&src->CT);
        ColorTable_Paste(&dest->CT);
	dest->Changed = 1;
      }
    }
  }

  // clear the changed flag on the colorbar
  WID->view_colorbar_window->clear_changed();
}

void view_arrow_param_cb(CALLBACK_ARGS)
{
  double a = opt_view_arrow_head_radius(WID->view_number, GMSH_GET, 0);
  double b = opt_view_arrow_stem_length(WID->view_number, GMSH_GET, 0);
  double c = opt_view_arrow_stem_radius(WID->view_number, GMSH_GET, 0);
  while(arrow_editor("Arrow Editor", a, b, c)){
    opt_view_arrow_head_radius(WID->view_number, GMSH_SET, a);
    opt_view_arrow_stem_length(WID->view_number, GMSH_SET, b);
    opt_view_arrow_stem_radius(WID->view_number, GMSH_SET, c);
    Draw();
  }
}

// Contextual windows for geometry

void con_geometry_define_parameter_cb(CALLBACK_ARGS)
{
  add_param((char *)WID->context_geometry_input[0]->value(),
            (char *)WID->context_geometry_input[1]->value(), CTX.filename);
  WID->reset_visibility();
}

void con_geometry_define_point_cb(CALLBACK_ARGS)
{
  add_point(CTX.filename,
	    (char*)WID->context_geometry_input[2]->value(),
	    (char*)WID->context_geometry_input[3]->value(),
	    (char*)WID->context_geometry_input[4]->value(),
	    (char*)WID->context_geometry_input[5]->value());
  WID->reset_visibility();
  ZeroHighlight();
  SetBoundingBox();
  Draw();
}

void con_geometry_snap_cb(CALLBACK_ARGS)
{
  CTX.geom.snap[0] = WID->context_geometry_value[0]->value();
  CTX.geom.snap[1] = WID->context_geometry_value[1]->value();
  CTX.geom.snap[2] = WID->context_geometry_value[2]->value();
}
