#ifndef _GUI_H_
#define _GUI_H_

#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Menu_Bar.H>
#include <FL/fl_draw.H>
#include <FL/gl.h>
#include <FL/Fl_Gl_Window.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Scroll.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Return_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Bitmap.H>
#include <FL/Fl_Browser.H>
#include <FL/x.H>
#include <FL/Fl_Color_Chooser.H>

#include "Opengl_Window.h"
#include "Colorbar_Window.h"

#define NB_BUTT_MAX    100
#define NB_HISTORY_MAX 1000

// The dynamic contexts

typedef struct{
  char *label;
  Fl_Callback* callback;
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
extern Context_Item menu_post[]; 

// The GUI class contains only the important widgets (which can be set/queried).

class GUI{

  int BH; // check_button height
  int BW; // check_button width
  int BB; // button width
  int WB; // borders
  int IW; // input field width
  int MH; // height of the unchangeable part of the menu window

  // All other diemnsions are automatic, or governed by CTX
  
  // Bitmaps
  Fl_Bitmap  *icon1_bmp, *icon2_bmp, *icon3_bmp;
  Fl_Bitmap  *abort_bmp, *start_bmp, *stop_bmp, *about_bmp ;

  // We keep the following widgets for easy further reference

public:

  // menu window
  int init_menu_window;
  Fl_Window        *m_window ;
  Fl_Menu_Bar      *m_menu_bar ;
  Fl_Choice        *m_module_butt ;
  Fl_Button        *m_navig_butt  [2] ;
  Fl_Button        *m_push_butt   [NB_BUTT_MAX] ;
  Fl_Light_Button  *m_toggle_butt [NB_BUTT_MAX] ;
  Fl_Menu_Button   *m_popup_butt  [NB_BUTT_MAX] ;

  // graphic window
  int init_graphic_window;
  Fl_Window        *g_window ;
  Opengl_Window    *g_opengl_window ;
  Fl_Button        *g_status_butt[7] ;
  Fl_Box           *g_status_label[3] ;

  // general options window
  int init_general_options_window;
  Fl_Window        *gen_window ;
  Fl_Check_Button  *gen_butt[20] ;
  Fl_Value_Input   *gen_value[10] ;
  Fl_Button        *gen_col[50] ;
  Fl_Input         *gen_input[10] ;

  // geometry options window
  int init_geometry_options_window;
  Fl_Window        *geo_window ;
  Fl_Check_Button  *geo_butt[10] ;
  Fl_Input         *geo_input ;
  Fl_Value_Input   *geo_value[10] ;
  Fl_Button        *geo_col[50] ;
  
  // mesh options window
  int init_mesh_options_window;
  Fl_Window        *mesh_window ;
  Fl_Check_Button  *mesh_butt[20] ;
  Fl_Input         *mesh_input ;
  Fl_Value_Input   *mesh_value[20] ;
  Fl_Button        *mesh_col[50] ;

  // post-processing options window
  int init_post_options_window;
  Fl_Window        *post_window ;
  Fl_Check_Button  *post_butt[20] ;
  Fl_Value_Input   *post_value[20] ;

  // statistics window
  int init_statistics_window;
  Fl_Window        *stat_window ;
  Fl_Output        *stat_value[50] ;

  // message window
  int init_message_window;
  Fl_Window        *msg_window ;
  Fl_Browser       *msg_browser ;

  // about window
  int init_about_window;
  Fl_Window        *about_window ;

  // view options window
  int init_view_window, view_number ;
  Fl_Window        *view_window ;
  Fl_Group         *view_timestep, *view_vector ;
  Fl_Check_Button  *view_butt[20] ;
  Fl_Value_Input   *view_value[20] ;
  Fl_Input         *view_input[20] ;
  Colorbar_Window  *view_colorbar_window ;
  Fl_Return_Button *view_ok ;
  
  // geometry context window
  int init_geometry_context_window;
  Fl_Window        *context_geometry_window ;
  Fl_Input         *context_geometry_input[30] ;

  // mesh context window
  int init_mesh_context_window;
  Fl_Window        *context_mesh_window ;
  Fl_Input         *context_mesh_input[20] ;


  // the constructor
  GUI(int argc, char **argv);

  // create the windows
  void create_menu_window(int argc, char **argv);
  void create_graphic_window(int argc, char **argv);
  void create_general_options_window();
  void create_geometry_options_window();
  void create_mesh_options_window();
  void create_post_options_window();
  void create_view_options_window(int numview);
  void create_statistics_window();
  void create_message_window();
  void create_about_window();
  void create_geometry_context_window(int num);
  void create_mesh_context_window(int num);

  // general purpose interaction
  void run();
  void check();
  void wait();
  void make_opengl_current();
  void make_overlay_current();
  void redraw_opengl();
  void redraw_overlay();
  void set_size(int w, int h);
  void set_menu_size(int nb_butt);
  void set_context(Context_Item menu[], int flag);
  int  get_context();
  void set_anim(int mode);
  void set_status(char *msg, int num);
  void add_message(char *msg);
  void clear_message();
  void save_message(char *filename);
  void set_statistics();
  void update_view_window(int numview);
  void set_title(char *str);
  void add_handler();
  int  global_shortcuts(int event);
  int  try_selection, quit_selection, end_selection;

};


#endif

