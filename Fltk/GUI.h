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
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Light_Button.H>
#include <FL/Fl_Menu_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Value_Output.H>
#include <FL/Fl_Multiline_Output.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Bitmap.H>

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
extern            Context_Item menu_geometry_elementary_add_dilate[]; 
extern            Context_Item menu_geometry_elementary_add_symmetry[]; 
extern        Context_Item menu_geometry_elementary_translate[]; 
extern        Context_Item menu_geometry_elementary_rotate[]; 
extern        Context_Item menu_geometry_elementary_dilate[]; 
extern        Context_Item menu_geometry_elementary_symmetry[]; 
extern        Context_Item menu_geometry_elementary_extrude[]; 
extern        Context_Item menu_geometry_elementary_delete[]; 
extern    Context_Item menu_geometry_physical[]; 
extern        Context_Item menu_geometry_physical_add[]; 
extern        Context_Item menu_geometry_physical_delete[]; 
extern Context_Item menu_mesh[]; 
extern    Context_Item menu_mesh_define[]; 
extern        Context_Item menu_mesh_define_transfinite[]; 
extern Context_Item menu_post[]; 

// New composite widgets

class Opengl_Window : public Fl_Gl_Window {
  void draw();
  void draw_overlay();
  int handle(int);

  // new
  void draw_highlight();
  void clear_overlay();
  void draw_overlay_zoom();
  void draw_overlay_highlight();

public:
  Opengl_Window(int x,int y,int w,int h,const char *l=0)
    : Fl_Gl_Window(x, y, w, h, l) {}
};

// The GUI class contains only the important widgets

class GUI{

  int BH; // generic button height
  int WB; // generic window border
  int MH; // height of the unchangeable part of the menu window
  // All other diemnsions are automatic, or governed by CTX
  
  // Windows
  Fl_Window  *m_window, *g_window, *gen_window, *geo_window ;
  Fl_Window  *mesh_window, *post_window, *stat_window ;
  Fl_Window  *help_window, *about_window, *view_window ;
  Opengl_Window *g_opengl_window ;
  
  // Bitmaps
  Fl_Bitmap  *icon1_bmp, *icon2_bmp, *icon3_bmp;
  Fl_Bitmap  *abort_bmp, *start_bmp, *stop_bmp, *about_bmp ;

  // We keep the following widgets for easy further reference

  // menu window
  Fl_Choice        *m_module_butt ;
  Fl_Button        *m_navig_butt  [2] ;
  Fl_Button        *m_push_butt   [NB_BUTT_MAX] ;
  Fl_Light_Button  *m_toggle_butt [NB_BUTT_MAX] ;
  Fl_Menu_Button   *m_popup_butt  [NB_BUTT_MAX] ;

  // graphic window
  Fl_Button        *g_status_butt[7] ;
  Fl_Box           *g_status_label[3] ;

  // general options window
  Fl_Check_Button  *gen_butt[10] ;
  Fl_Value_Input   *gen_value[10] ;

  // geometry options window
  Fl_Check_Button  *geo_butt[10] ;
  Fl_Value_Input   *geo_value[10] ;
  
  // mesh options window
  Fl_Check_Button  *mesh_butt[20] ;
  Fl_Value_Input   *mesh_value[20] ;

  // post-processing options window
  Fl_Check_Button  *post_butt[20] ;
  Fl_Value_Input   *post_value[20] ;

  // statistics window
  Fl_Value_Output  *stat_value[40] ;

  // view options window
  Fl_Check_Button  *view_butt[20] ;
  Fl_Value_Input   *view_value[10] ;
  Fl_Input         *view_input[10] ;

public:

  GUI();
  void run();
  void check();
  void make_gl_current();
  void draw_gl();
  void draw_gl_overlay();
  void set_gl_size(int w, int h);
  void set_menu_size(int nb_butt);
  void set_context(Context_Item menu[], int flag);
  int  get_context();
  void set_anim(int mode);
  void set_status(char *msg, int num);

  // create option windows
  void opt_general();
  void opt_geometry();
  void opt_mesh();
  void opt_post();
  void opt_stat();
  void opt_view();

  // create help windows
  void help_short();
  void help_about();

};


#endif

