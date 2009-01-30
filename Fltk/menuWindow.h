// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MENU_WINDOW_H_
#define _MENU_WINDOW_H_

#include <string>
#include <vector>
#include <FL/Fl_Window.H>
#if defined(__APPLE__)
#include <FL/Fl_Sys_Menu_Bar.H>
#endif
#include <FL/Fl_Menu_Bar.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Light_Button.H>
#include "popupButton.h"

// The dynamic menu contexts
typedef struct{
  std::string label;
  Fl_Callback *callback;
  void *arg;
} contextItem;

extern contextItem menu_geometry[]; 
extern    contextItem menu_geometry_elementary[]; 
extern        contextItem menu_geometry_elementary_add[]; 
extern            contextItem menu_geometry_elementary_add_new[]; 
extern            contextItem menu_geometry_elementary_add_translate[]; 
extern            contextItem menu_geometry_elementary_add_rotate[]; 
extern            contextItem menu_geometry_elementary_add_scale[]; 
extern            contextItem menu_geometry_elementary_add_symmetry[]; 
extern        contextItem menu_geometry_elementary_translate[]; 
extern        contextItem menu_geometry_elementary_rotate[]; 
extern        contextItem menu_geometry_elementary_scale[]; 
extern        contextItem menu_geometry_elementary_symmetry[]; 
extern        contextItem menu_geometry_elementary_extrude[]; 
extern            contextItem menu_geometry_elementary_extrude_translate[]; 
extern            contextItem menu_geometry_elementary_extrude_rotate[]; 
extern        contextItem menu_geometry_elementary_delete[]; 
extern        contextItem menu_geometry_elementary_split[]; 
extern    contextItem menu_geometry_physical[]; 
extern        contextItem menu_geometry_physical_add[]; 
extern contextItem menu_mesh[]; 
extern    contextItem menu_mesh_edit[]; 
extern        contextItem menu_mesh_delete[]; 
extern    contextItem menu_mesh_define[]; 
extern        contextItem menu_mesh_define_transfinite[]; 
extern contextItem menu_solver[]; 
extern contextItem menu_post[]; 

class menuWindow{
 private:
  int _MH;
 public:
  Fl_Window *win;
#if defined(__APPLE__)
  Fl_Sys_Menu_Bar *sysbar;
#endif
  Fl_Menu_Bar *bar;
  Fl_Choice *module;
  Fl_Button *navig[2];
  Fl_Scroll *scroll;
  std::vector<Fl_Button*> push;
  std::vector<Fl_Light_Button*> toggle;
  std::vector<Fl_Button*> toggle2;
  std::vector<popupButton*> popup;
  std::vector<popupButton*> popup2;
  std::vector<char*> label;
 public:
  menuWindow();
  void setContext(contextItem *menu_asked, int flag);
};

void file_quit_cb(Fl_Widget *w, void *data);
void mod_geometry_cb(Fl_Widget *w, void *data);
void mod_mesh_cb(Fl_Widget *w, void *data);
void mod_solver_cb(Fl_Widget *w, void *data);
void mod_post_cb(Fl_Widget *w, void *data);
void mod_back_cb(Fl_Widget *w, void *data);
void mod_forward_cb(Fl_Widget *w, void *data);
void geometry_reload_cb(Fl_Widget *w, void *data);
void mesh_1d_cb(Fl_Widget *w, void *data);
void mesh_2d_cb(Fl_Widget *w, void *data);
void mesh_3d_cb(Fl_Widget *w, void *data);

#endif
