#ifndef _GUI_H_
#define _GUI_H_

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

#include <FL/Fl_Window.H>
#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_draw.H>
#include <FL/gl.h>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Repeat_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Bitmap.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Hold_Browser.H>
#include <FL/x.H>
#include <FL/Fl_Color_Chooser.H>
#include <FL/fl_ask.H>
#include <FL/Fl_Tooltip.H>
#if defined(__APPLE__) && defined(HAVE_FLTK_1_1_5_OR_ABOVE)
#include <FL/Fl_Sys_Menu_Bar.H>
#endif

#include <vector>

#include "Opengl_Window.h"
#include "Colorbar_Window.h"

// The dynamic contexts

typedef struct{
  char *label;
  Fl_Callback* callback;
  void *arg;
} Context_Item;

extern Context_Item menu_geometry[]; 
extern    Context_Item menu_geometry_elementary[]; 
extern        Context_Item menu_geometry_elementary_add[]; 
extern            Context_Item menu_geometry_elementary_add_new[]; 
extern            Context_Item menu_geometry_elementary_add_translate[]; 
extern            Context_Item menu_geometry_elementary_add_rotate[]; 
extern            Context_Item menu_geometry_elementary_add_scale[]; 
extern            Context_Item menu_geometry_elementary_add_symmetry[]; 
extern        Context_Item menu_geometry_elementary_translate[]; 
extern        Context_Item menu_geometry_elementary_rotate[]; 
extern        Context_Item menu_geometry_elementary_scale[]; 
extern        Context_Item menu_geometry_elementary_symmetry[]; 
extern        Context_Item menu_geometry_elementary_extrude[]; 
extern            Context_Item menu_geometry_elementary_extrude_translate[]; 
extern            Context_Item menu_geometry_elementary_extrude_rotate[]; 
extern        Context_Item menu_geometry_elementary_delete[]; 
extern    Context_Item menu_geometry_physical[]; 
extern        Context_Item menu_geometry_physical_add[]; 
extern Context_Item menu_mesh[]; 
extern    Context_Item menu_mesh_define[]; 
extern        Context_Item menu_mesh_define_transfinite[]; 
extern Context_Item menu_solver[]; 
extern Context_Item menu_post[]; 

// Forward Declarations

class GMSH_Plugin;

// A generalized dialogbox for plugins

#define MAX_PLUGIN_OPTIONS 50

struct PluginDialogBox
{
  int current_view_index;
  Fl_Window *main_window;
  Fl_Return_Button *run_button;
  Fl_Value_Input *value[MAX_PLUGIN_OPTIONS];
  Fl_Input *input[MAX_PLUGIN_OPTIONS] ;
};

// The dialog for solvers

struct SolverDialogBox
{
  Fl_Window *window;
  Fl_Input *input[50] ;
  Fl_Choice *choice[10] ;
  Fl_Check_Button *butt[10] ;
  Fl_Button *command[10] ;
};

// The GUI class contains only the important widgets (which can be set/queried).

class GUI{

  int MH, fontsize ;
  Fl_Scroll *m_scroll;

  // Bitmaps
  Fl_Bitmap  *abort_bmp, *start_bmp, *stop_bmp, *rewind_bmp ;
  void add_post_plugins ( Fl_Menu_Button *button , int iView);
  void add_multiline_in_browser(Fl_Browser *o, char* prefix, char *str);

public:

  Fl_Bitmap  *ortho_bmp, *persp_bmp;

  // menu window
  Fl_Window        *m_window ;
#if defined(__APPLE__) && defined(HAVE_FLTK_1_1_5_OR_ABOVE)
  Fl_Sys_Menu_Bar  *m_sys_menu_bar ;
#endif
  Fl_Menu_Bar      *m_menu_bar ;
  Fl_Choice        *m_module_butt ;
  Fl_Button        *m_navig_butt  [2] ;
  std::vector<Fl_Button*>       m_push_butt ;
  std::vector<Fl_Light_Button*> m_toggle_butt ;
  std::vector<Fl_Button*>       m_toggle2_butt ;
  std::vector<Fl_Menu_Button*>  m_popup_butt ;
  std::vector<Fl_Menu_Button*>  m_popup2_butt ;
  std::vector<char*>            m_pop_label ;
  std::vector<std::pair<int, GMSH_Plugin*>*> m_pop_plugin;

  // graphic window
  Fl_Window        *g_window ;
  Opengl_Window    *g_opengl_window ;
  Fl_Button        *g_status_butt[8] ;
  Fl_Box           *g_status_label[3] ;

  // Option window
  Fl_Window        *opt_window ;
  Fl_Hold_Browser  *opt_browser ;

  // general options
  Fl_Group         *gen_group ;
  Fl_Check_Button  *gen_butt[20] ;
  Fl_Button        *gen_push_butt[20] ;
  Fl_Value_Input   *gen_value[50] ;
  Fl_Button        *gen_col[50] ;
  Fl_Input         *gen_input[20] ;
  Fl_Choice        *gen_choice[20] ;

  // geometry options
  Fl_Group         *geo_group ;
  Fl_Check_Button  *geo_butt[20] ;
  Fl_Value_Input   *geo_value[20] ;
  Fl_Button        *geo_col[50] ;
  Fl_Choice        *geo_choice[20] ;
  
  // mesh options
  Fl_Group         *mesh_group ;
  Fl_Check_Button  *mesh_butt[50] ;
  Fl_Input         *mesh_input[20] ;
  Fl_Value_Input   *mesh_value[20] ;
  Fl_Button        *mesh_col[50] ;
  Fl_Choice        *mesh_choice[20] ;

  // solver options
  Fl_Group         *solver_group ;
  Fl_Check_Button  *solver_butt[20] ;
  Fl_Value_Input   *solver_value[20] ;
  Fl_Input         *solver_input[20] ;

  // post-processing options
  Fl_Group         *post_group ;
  Fl_Check_Button  *post_butt[20] ;
  Fl_Value_Input   *post_value[20] ;
  Fl_Choice        *post_choice[20] ;

  // view options
  int view_number ;
  Fl_Group         *view_group ;
  Fl_Group         *view_range, *view_vector ;
  Fl_Check_Button  *view_butt[100] ;
  Fl_Value_Input   *view_value[100] ;
  Fl_Input         *view_input[100] ;
  Fl_Repeat_Button *view_butt_rep[100] ;
  Fl_Button        *view_push_butt[100] ;
  Fl_Choice        *view_choice[100] ;
  Fl_Button        *view_col[50] ;
  Colorbar_Window  *view_colorbar_window ;
  Fl_Return_Button *view_ok ;

  // statistics window
  Fl_Window        *stat_window ;
  Fl_Output        *stat_value[50] ;

  // message window
  Fl_Window        *msg_window ;
  Fl_Browser       *msg_browser ;

  // visibility window
  Fl_Window        *vis_window ;
  Fl_Choice        *vis_type, *vis_browser_mode, *vis_input_mode ;
  Fl_Browser       *vis_browser ;
  Fl_Check_Button  *vis_butt[20] ;
  Fl_Input         *vis_input[10];

  // clipping planes window
  Fl_Window        *clip_window ;
  Fl_Choice        *clip_choice ;
  Fl_Multi_Browser *clip_browser ;
  Fl_Value_Input   *clip_value[4];

  // manipulator window
  Fl_Window        *manip_window ;
  Fl_Value_Input   *manip_value[9] ;

  // about window
  Fl_Window        *about_window ;

  // geometry context window
  Fl_Window        *context_geometry_window ;
  Fl_Input         *context_geometry_input[30] ;

  // mesh context window
  Fl_Window        *context_mesh_window ;
  Fl_Input         *context_mesh_input[20] ;
  Fl_Choice        *context_mesh_choice[20] ;

  // solver windows
  SolverDialogBox  solver[5] ;

  // on-screen persistent messages
  char onscreen_buffer[2][256];

  // the constructor
  GUI(int argc, char **argv);

  // create the windows
  void create_menu_window(int argc, char **argv);
  void create_graphic_window(int argc, char **argv);
  void create_option_window();
  void hide_all_option_groups();
  void create_general_options_window();
  void create_geometry_options_window();
  void create_mesh_options_window();
  void create_solver_options_window();
  void create_post_options_window();
  PluginDialogBox *create_plugin_window(GMSH_Plugin *p);
  void create_view_options_window(int numview);
  void create_visibility_window();
  void create_clip_window();
  void create_manip_window();
  void create_statistics_window();
  void create_message_window();
  void create_about_window();
  void create_geometry_context_window(int num);
  void call_for_solver_plugin (int dim);
  void create_mesh_context_window(int num);
  void create_solver_window(int num);

  // general purpose interaction
  int run();
  void check();
  void wait();
  void make_opengl_current();
  void redraw_opengl();
  void set_size(int w, int h);
  void set_context(Context_Item menu[], int flag);
  int  get_context();
  void set_anim_buttons(int mode);
  void check_anim_buttons();
  void check_rotation_center_button();
  void set_status(char *msg, int num);
  void add_message(char *msg);
  void save_message(char *filename);
  void fatal_error(char *filename);
  void set_statistics();
  void update_view_window(int numview);
  void set_title(char *str);
  void add_handler();
  int  global_shortcuts(int event);
  int  arrow_shortcuts();
  void reset_visibility();
  void reset_option_browser();
  void reset_clip_browser();
  void update_manip_window(int force=0);
  void reset_external_view_list();
  int  selection, try_selection, quit_selection, end_selection, undo_selection;

};

// some utility font functions
int GetFontIndex(char *fontname);
int GetFontEnum(int index);
char *GetFontName(int index);
int GetFontAlign(char *alignstr);

#endif

