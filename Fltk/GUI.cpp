// $Id: GUI.cpp,v 1.167 2002-04-24 22:17:21 geuzaine Exp $

// To make the interface as visually consistent as possible, please:
// - use the IW, BB, BH, BW and WB values
// - examine what's already done before adding something new...

#include "PluginManager.h"
#include "Plugin.h"

#include "Gmsh.h"
#include "GmshUI.h"
#include "Numeric.h"
#include "GmshVersion.h"
#include "Context.h"
#include "Options.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Bitmaps.h"
#include "Icon.h"
#include "OpenFile.h"
#include "GetOptions.h"

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 0)
#define WINDOW_BOX FL_FLAT_BOX
#define TOGGLE_BOX FL_DOWN_BOX
#define TOGGLE_COLOR FL_YELLOW
#define RADIO_BOX  FL_DIAMOND_DOWN_BOX
#define RADIO_COLOR FL_YELLOW
#else
#define WINDOW_BOX FL_FLAT_BOX
#define TOGGLE_BOX FL_DOWN_BOX
#define TOGGLE_COLOR FL_BLACK
#define RADIO_BOX  FL_ROUND_DOWN_BOX
#define RADIO_COLOR FL_BLACK
#endif

#define IW  (10*CTX.fontsize) // input field width
#define BB  (5*CTX.fontsize-2) // width of a button with internal label
#define BH  (2*CTX.fontsize+1) // button height
#define WB  (5) // window border

extern Context_T  CTX;

//******************* Definition of the static menus ***********************************

// Don't define shortcuts for FL_CTRL+'n', FL_CTRL+'p', FL_CTRL+'f', FL_CTRL+'b'
// these are used by fltk for widget navigation (in the same way as the 4 arrow keys)

Fl_Menu_Item m_menubar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"Open...",          FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"Merge...",         FL_CTRL+'m', (Fl_Callback *)file_merge_cb, 0},
    {"Save as",          0, 0, 0, FL_MENU_DIVIDER|FL_SUBMENU},
      {"By extension...",  FL_CTRL+'e', (Fl_Callback *)file_save_as_auto_cb, 0, FL_MENU_DIVIDER},
      {"Geometry",  0, 0, 0, FL_SUBMENU},
         {"Gmsh current options (opt)...",    0, (Fl_Callback *)file_save_as_geo_options_cb, 0},
         {"Gmsh unrolled geometry (geo)...",  0, (Fl_Callback *)file_save_as_geo_cb, 0},
         {0},
      {"Mesh",  0, 0, 0, FL_SUBMENU},
         {"Gmsh (msh)...",                  0, (Fl_Callback *)file_save_as_msh_cb, 0},
         {"Gmsh all elements...",           0, (Fl_Callback *)file_save_as_msh_all_cb, 0},
         {"GREF (gref)...",                 0, (Fl_Callback *)file_save_as_gref_cb, 0},
         {"I-DEAS universal (unv)...",      0, (Fl_Callback *)file_save_as_unv_cb, 0},
         {"VRML lines/surfaces (wrl)...",   0, (Fl_Callback *)file_save_as_vrml_cb, 0},
         {0},
      {"Image",  0, 0, 0, FL_SUBMENU},
         {"GIF (gif)...",                 0, (Fl_Callback *)file_save_as_gif_cb, 0},
         {"GIF dithered...",              0, (Fl_Callback *)file_save_as_gif_dithered_cb, 0},
         {"GIF transparent...",           0, (Fl_Callback *)file_save_as_gif_transparent_cb, 0},
         {"JPEG (jpg)...",                0, (Fl_Callback *)file_save_as_jpeg_cb, 0},
         {"PostScript fast (ps)...",      0, (Fl_Callback *)file_save_as_ps_simple_cb, 0},
         {"PostScript accurate...",       0, (Fl_Callback *)file_save_as_ps_accurate_cb, 0},
         {"PPM (ppm)...",                 0, (Fl_Callback *)file_save_as_ppm_cb, 0},
         {"LaTeX JPEG...",                0, (Fl_Callback *)file_save_as_jpegtex_cb, 0},
         {"LaTeX PostScript fast...",     0, (Fl_Callback *)file_save_as_pstex_simple_cb, 0},
         {"LaTeX PostScript accurate...", 0, (Fl_Callback *)file_save_as_pstex_accurate_cb, 0},
         {"LaTeX TeX (tex)...",           0, (Fl_Callback *)file_save_as_tex_cb, 0},
         {"UCB YUV (yuv)...",             0, (Fl_Callback *)file_save_as_yuv_cb, 0},
         {0},
      {0},
    {"Visibility...",    FL_SHIFT+'v', (Fl_Callback *)opt_visibility_cb, 0},
    {"Messages...",      FL_SHIFT+'l', (Fl_Callback *)opt_message_cb, 0},
    {"Statistics...",    FL_SHIFT+'i', (Fl_Callback *)opt_statistics_cb, 0, FL_MENU_DIVIDER},
    {"Quit",             FL_CTRL+'q', (Fl_Callback *)file_quit_cb, 0},
    {0},
  {"Options",0,0,0,FL_SUBMENU},
    {"General...",         FL_SHIFT+'o', (Fl_Callback *)opt_general_cb, 0, FL_MENU_DIVIDER},
    {"Geometry...",        FL_SHIFT+'g', (Fl_Callback *)opt_geometry_cb, 0},
    {"Mesh...",            FL_SHIFT+'m', (Fl_Callback *)opt_mesh_cb, 0},
    {"Solver...",          FL_SHIFT+'s', (Fl_Callback *)opt_solver_cb, 0},
    {"Post-processing...", FL_SHIFT+'p', (Fl_Callback *)opt_post_cb, 0, FL_MENU_DIVIDER},
    {"Save options now",   0,            (Fl_Callback *)opt_save_cb, 0},
    {0},
  {"Help",0,0,0,FL_SUBMENU},
    {"Current options...",       0, (Fl_Callback *)status_xyz1p_cb, (void*)4},
    {"Shortcuts...",             0, (Fl_Callback *)help_short_cb, 0},
    {"Command line options...",  0, (Fl_Callback *)help_command_line_cb, 0, FL_MENU_DIVIDER},
    {"About...",                 0, (Fl_Callback *)help_about_cb, 0},
    {0},
  {0}
};

Fl_Menu_Item m_module_table[] = {
  {"Geometry",        'g', (Fl_Callback *)mod_geometry_cb, 0},
  {"Mesh",            'm', (Fl_Callback *)mod_mesh_cb, 0},
  {"Solver",          's', (Fl_Callback *)mod_solver_cb, 0},
  {"Post-processing", 'p', (Fl_Callback *)mod_post_cb, 0},
  {0}
};

//********************* Definition of the dynamic contexts *****************************

Context_Item menu_geometry[] = 
{ { "0Geometry", NULL } ,
  { "Elementary", (Fl_Callback *)geometry_elementary_cb } ,
  { "Physical",   (Fl_Callback *)geometry_physical_cb } ,
  { "Edit",       (Fl_Callback *)geometry_edit_cb } , 
  { "Reload",     (Fl_Callback *)geometry_reload_cb } , 
  { NULL }
};  
    Context_Item menu_geometry_elementary[] = 
    { { "0Geometry Elementary", NULL } ,
      { "Add",       (Fl_Callback *)geometry_elementary_add_cb } ,
      { "Translate", (Fl_Callback *)geometry_elementary_translate_cb } ,
      { "Rotate",    (Fl_Callback *)geometry_elementary_rotate_cb } ,
      { "Scale",     (Fl_Callback *)geometry_elementary_scale_cb } ,
      { "Symmetry",  (Fl_Callback *)geometry_elementary_symmetry_cb } ,
      { "Extrude",   (Fl_Callback *)geometry_elementary_extrude_cb } ,
      { "Delete",    (Fl_Callback *)geometry_elementary_delete_cb } ,
      { NULL } 
    };  
        Context_Item menu_geometry_elementary_add[] = 
	{ { "0Geometry Elementary Add", NULL } ,
          { "New",       (Fl_Callback *)geometry_elementary_add_new_cb } ,
	  { "Translate", (Fl_Callback *)geometry_elementary_add_translate_cb } ,
	  { "Rotate",    (Fl_Callback *)geometry_elementary_add_rotate_cb } ,
	  { "Scale",     (Fl_Callback *)geometry_elementary_add_scale_cb } ,
	  { "Symmetry",  (Fl_Callback *)geometry_elementary_add_symmetry_cb } ,
	  { NULL } 
	};  
            Context_Item menu_geometry_elementary_add_new[] = 
	    { { "0Geometry Elementary Add New", NULL } ,
              { "Parameter",     (Fl_Callback *)geometry_elementary_add_new_parameter_cb } ,
	      { "Point",         (Fl_Callback *)geometry_elementary_add_new_point_cb } ,
	      { "Line",          (Fl_Callback *)geometry_elementary_add_new_line_cb } ,
	      { "Spline",        (Fl_Callback *)geometry_elementary_add_new_spline_cb } ,
	      { "B-Spline",      (Fl_Callback *)geometry_elementary_add_new_bspline_cb } ,
	      { "Circle",        (Fl_Callback *)geometry_elementary_add_new_circle_cb } ,
	      { "Ellipse",       (Fl_Callback *)geometry_elementary_add_new_ellipse_cb } ,
	      { "Plane surface", (Fl_Callback *)geometry_elementary_add_new_planesurface_cb } ,
	      { "Ruled surface", (Fl_Callback *)geometry_elementary_add_new_ruledsurface_cb } ,
	      { "Volume",        (Fl_Callback *)geometry_elementary_add_new_volume_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_translate[] = 
	    { { "0Geometry Elementary Add Translate", NULL } ,
              { "Point",   (Fl_Callback *)geometry_elementary_add_translate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_translate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_translate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_rotate[] = 
	    { { "0Geometry Elementary Add Rotate", NULL } ,
              { "Point",   (Fl_Callback *)geometry_elementary_add_rotate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_rotate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_rotate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_scale[] = 
	    { { "0Geometry Elementary Add Scale", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_add_scale_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_scale_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_scale_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_symmetry[] = 
	    { { "0Geometry Elementary Add Symmetry", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_add_symmetry_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_symmetry_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_symmetry_surface_cb } ,
	      { NULL } 
	    };  
        Context_Item menu_geometry_elementary_translate[] = 
	{ { "0Geometry Elementary Translate", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_translate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_translate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_translate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_rotate[] = 
	{ { "0Geometry Elementary Rotate", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_rotate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_rotate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_rotate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_scale[] = 
	{ { "0Geometry Elementary Scale", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_scale_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_scale_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_scale_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_symmetry[] = 
	{ { "0Geometry Elementary Symmetry", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_symmetry_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_symmetry_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_symmetry_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_extrude[] = 
	{ { "0Geometry Elementary Extrude", NULL } ,
	  { "Translate",   (Fl_Callback *)geometry_elementary_extrude_translate_cb } ,
	  { "Rotate",   (Fl_Callback *)geometry_elementary_extrude_rotate_cb } ,
	  { NULL } 
 	};  
            Context_Item menu_geometry_elementary_extrude_translate[] = 
	    { { "0Geometry Elementary Extrude Translate", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_extrude_translate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_extrude_translate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_extrude_translate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_extrude_rotate[] = 
	    { { "0Geometry Elementary Extrude Rotate", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_extrude_rotate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_extrude_rotate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_extrude_rotate_surface_cb } ,
	      { NULL } 
	    };  
        Context_Item menu_geometry_elementary_delete[] = 
	{ { "0Geometry Elementary Delete", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_delete_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_delete_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_delete_surface_cb } ,
	  { NULL } 
	};  
    Context_Item menu_geometry_physical[] = 
    { { "0Geometry Physical", NULL } ,
      { "Add",    (Fl_Callback *)geometry_physical_add_cb } ,
      { NULL } 
    };  
        Context_Item menu_geometry_physical_add[] = 
	{ { "0Geometry Physical Add", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_physical_add_point_cb  } ,
	  { "Curve",   (Fl_Callback *)geometry_physical_add_curve_cb  } ,
	  { "Surface", (Fl_Callback *)geometry_physical_add_surface_cb  } ,
	  { "Volume",  (Fl_Callback *)geometry_physical_add_volume_cb  } ,
	  { NULL } 
	};  

Context_Item menu_mesh[] = 
{ { "1Mesh", NULL } ,
  { "Define", (Fl_Callback *)mesh_define_cb } ,
  { "1D",     (Fl_Callback *)mesh_1d_cb } ,
  { "2D",     (Fl_Callback *)mesh_2d_cb } , 
  { "3D",     (Fl_Callback *)mesh_3d_cb } , 
  { "Save",   (Fl_Callback *)mesh_save_cb } ,
  { "Save all", (Fl_Callback *)mesh_save_all_cb } ,
  { NULL } 
};  
    Context_Item menu_mesh_define[] = 
    { { "1Mesh Define", NULL } ,
      { "Length",      (Fl_Callback *)mesh_define_length_cb  } ,
      { "Recombine",   (Fl_Callback *)mesh_define_recombine_cb  } ,
      { "Transfinite", (Fl_Callback *)mesh_define_transfinite_cb  } , 
      { NULL } 
    };  
        Context_Item menu_mesh_define_transfinite[] = 
	{ { "1Mesh Define Transfinite", NULL } ,
	  { "Line",    (Fl_Callback *)mesh_define_transfinite_line_cb } ,
	  { "Surface", (Fl_Callback *)mesh_define_transfinite_surface_cb } ,
	  { "Volume",  (Fl_Callback *)mesh_define_transfinite_volume_cb } , 
	  { NULL } 
	};  

Context_Item menu_solver[] = 
{ { "2Solver", NULL } ,
  { "Solver 0", (Fl_Callback *)solver_cb , (void*)0} ,
  { "Solver 1", (Fl_Callback *)solver_cb , (void*)1} ,
  { "Solver 2", (Fl_Callback *)solver_cb , (void*)2} ,
  { "Solver 3", (Fl_Callback *)solver_cb , (void*)3} ,
  { "Solver 4", (Fl_Callback *)solver_cb , (void*)4} ,
  { NULL } };

Context_Item menu_post[] = 
{ { "3Post-processing", NULL } ,
  { NULL } };

//********************** Definition of global shortcuts ********************************

int GUI::global_shortcuts(int event){
  int i, j;

  // we only handle shortcuts here
  if(event != FL_SHORTCUT) return 0 ;


  if(Fl::test_shortcut(FL_SHIFT+FL_Escape) ||
     Fl::test_shortcut(FL_CTRL+FL_Escape) ||
     Fl::test_shortcut(FL_ALT+FL_Escape)){
    return 1;
  }
  if(Fl::test_shortcut('0') || Fl::test_shortcut(FL_Escape)){
    geometry_reload_cb(0,0);
    mod_geometry_cb(0,0);
    return 1;
  }
#if (FL_MAJOR_VERSION == 2)
  else if(Fl::test_shortcut('1') || Fl::test_shortcut(FL_F(1))){
#else
  else if(Fl::test_shortcut('1') || Fl::test_shortcut(FL_F+1)){
#endif
    mesh_1d_cb(0,0);
    mod_mesh_cb(0,0);
    return 1;
  }
#if (FL_MAJOR_VERSION == 2)
  else if(Fl::test_shortcut('1') || Fl::test_shortcut(FL_F(2))){
#else
  else if(Fl::test_shortcut('2') || Fl::test_shortcut(FL_F+2)){
#endif
    mesh_2d_cb(0,0);
    mod_mesh_cb(0,0);
    return 1;
  }
#if (FL_MAJOR_VERSION == 2)
  else if(Fl::test_shortcut('1') || Fl::test_shortcut(FL_F(3))){
#else
  else if(Fl::test_shortcut('3') || Fl::test_shortcut(FL_F+3)){
#endif
    mesh_3d_cb(0,0);
    mod_mesh_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('g')){
    mod_geometry_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('m')){
    mod_mesh_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('s')){
    mod_solver_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('p')){
    mod_post_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('b')){
    mod_back_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('f')){
    mod_forward_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('e')){
    end_selection = 1;
    return 1;
  }
  else if(Fl::test_shortcut('q')){
    quit_selection = 1;
    return 1;
  }
  else if(Fl::test_shortcut(FL_CTRL+'s')){
    mesh_save_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut(FL_CTRL+FL_SHIFT+'d')){
    opt_post_anim_delay(0,GMSH_SET|GMSH_GUI,opt_post_anim_delay(0,GMSH_GET,0) + 0.01);
    return 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT+'d')){
    opt_post_anim_delay(0,GMSH_SET|GMSH_GUI,opt_post_anim_delay(0,GMSH_GET,0) - 0.01);
    return 1;
  }
  else if(Fl::test_shortcut(FL_CTRL+'z')){
    g_window->iconize() ;
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'f')){
    opt_general_fast_redraw(0,GMSH_SET|GMSH_GUI,!opt_general_fast_redraw(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'b')){
    opt_post_scales(0,GMSH_SET|GMSH_GUI,!opt_post_scales(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'o')){
    opt_general_orthographic(0,GMSH_SET|GMSH_GUI,!opt_general_orthographic(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'c')){
    opt_general_color_scheme(0,GMSH_SET|GMSH_GUI,opt_general_color_scheme(0,GMSH_GET,0)+1);
    opt_geometry_color_scheme(0,GMSH_SET|GMSH_GUI,opt_geometry_color_scheme(0,GMSH_GET,0)+1);
    opt_mesh_color_scheme(0,GMSH_SET|GMSH_GUI,opt_mesh_color_scheme(0,GMSH_GET,0)+1);
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'d')){
    opt_mesh_aspect(0,GMSH_SET|GMSH_GUI,opt_mesh_aspect(0,GMSH_GET,0)+1);
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'x')){
    status_xyz1p_cb(0,(void*)0);
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'y')){
    status_xyz1p_cb(0,(void*)1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'z')){
    status_xyz1p_cb(0,(void*)2);
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+FL_SHIFT+'a')){
    opt_general_axes(0,GMSH_SET|GMSH_GUI,!opt_general_axes(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'a')){
    opt_general_small_axes(0,GMSH_SET|GMSH_GUI,!opt_general_small_axes(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'p')){
    opt_geometry_points(0,GMSH_SET|GMSH_GUI,!opt_geometry_points(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'l')){
    opt_geometry_lines(0,GMSH_SET|GMSH_GUI,!opt_geometry_lines(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'s')){
    opt_geometry_surfaces(0,GMSH_SET|GMSH_GUI,!opt_geometry_surfaces(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'v')){
    opt_geometry_volumes(0,GMSH_SET|GMSH_GUI,!opt_geometry_volumes(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+FL_SHIFT+'p')){
    opt_mesh_points(0,GMSH_SET|GMSH_GUI,!opt_mesh_points(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+FL_SHIFT+'l')){
    opt_mesh_lines(0,GMSH_SET|GMSH_GUI,!opt_mesh_lines(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+FL_SHIFT+'s')){
    opt_mesh_surfaces(0,GMSH_SET|GMSH_GUI,!opt_mesh_surfaces(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+FL_SHIFT+'v')){
    opt_mesh_volumes(0,GMSH_SET|GMSH_GUI,!opt_mesh_volumes(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'m')){
    opt_mesh_points(0,GMSH_SET|GMSH_GUI,!opt_mesh_points(0,GMSH_GET,0));
    opt_mesh_lines(0,GMSH_SET|GMSH_GUI,!opt_mesh_lines(0,GMSH_GET,0));
    opt_mesh_surfaces(0,GMSH_SET|GMSH_GUI,!opt_mesh_surfaces(0,GMSH_GET,0));
    opt_mesh_volumes(0,GMSH_SET|GMSH_GUI,!opt_mesh_volumes(0,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'t')){
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++){
      if(opt_view_visible(i,GMSH_GET,0)){
	j = (int)opt_view_intervals_type(i, GMSH_GET, 0);
	opt_view_intervals_type(i, GMSH_SET|GMSH_GUI, 
				(j == DRAW_POST_ISO) ? DRAW_POST_DISCRETE :
				(j == DRAW_POST_DISCRETE) ? DRAW_POST_CONTINUOUS :
				DRAW_POST_ISO);
      }
    }
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'n')){
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++)
      if(opt_view_visible(i,GMSH_GET,0))
	opt_view_draw_strings(i, GMSH_SET|GMSH_GUI,!opt_view_draw_strings(i,GMSH_GET,0));
    redraw_opengl();
    return 1;
  }
  else if(Fl::test_shortcut(FL_ALT+'h')){
    static int show = 0;
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++)
      opt_view_visible(i, GMSH_SET|GMSH_GUI, show);
    redraw_opengl();
    show = !show;
    return 1;
  }
  else if(arrow_shortcuts()){
    return 1;
  }

  return 0;
}

// Test the arrow shortcuts (this is not in the global_shortcuts)
// since it is used elsewhere (where we want to override widget
// navigation: necessary since FLTK>=1.1)

int GUI::arrow_shortcuts(){
  if(Fl::test_shortcut(FL_Left)){
    ManualPlay(1,-1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Right)){
    ManualPlay(1,1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Up)){
    ManualPlay(0,-1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Down)){
    ManualPlay(0,1);
    return 1;
  }
  return 0;
}


//***************************** The GUI constructor ************************************

GUI::GUI(int argc, char **argv) {
  int i;

  // initialize static windows
  m_window = NULL;
  g_window = NULL;
  gen_window = NULL;
  geo_window = NULL;
  mesh_window = NULL;
  solver_window = NULL;
  post_window = NULL;
  stat_window = NULL;
  msg_window = NULL;
  vis_window = NULL;
  about_window = NULL;
  view_window = NULL;
  context_geometry_window = NULL;
  context_mesh_window = NULL;

  // set X display
  if(strlen(CTX.display)) Fl::display(CTX.display);

  // add global shortcuts
  Fl::add_handler(SetGlobalShortcut);

  // set default font size
#if !((FL_MAJOR_VERSION == 2) && (FL_MINOR_VERSION == 0))
  FL_NORMAL_SIZE = CTX.fontsize;
#endif

  // handle themes and tooltip font size
#if !((FL_MAJOR_VERSION == 1 || FL_MAJOR_VERSION == 2) && (FL_MINOR_VERSION == 0))
  if(strlen(CTX.theme)) Fl::scheme(CTX.theme);
  Fl_Tooltip::size(CTX.fontsize);
#endif

  // disable default fltk keyboard navigation. It is not necessary
  // anymore, since correct handlers for the graphic and the colorbar
  // window have been added.
  // Fl::visible_focus(0);

  // All static windows are contructed (even if some are not
  // displayed) since the shortcuts should be valid even for hidden
  // windows, and we don't want to test for widget existence every time

  create_menu_window(argc, argv);
  create_graphic_window(argc, argv);

#if defined(WIN32)
  m_window->icon((char *)LoadImage(fl_display, MAKEINTRESOURCE(IDI_ICON),
  				   IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR));
#elif defined(__APPLE__)
  /* ??? */
#else
  fl_open_display();
  Pixmap p1 = XCreateBitmapFromData(fl_display, DefaultRootWindow(fl_display),
				    g1_bits, g1_width, g1_height);
  Pixmap p2 = XCreateBitmapFromData(fl_display, DefaultRootWindow(fl_display),
				    g2_bits, g2_width, g2_height);
  m_window->icon((char *)p1); 
  g_window->icon((char *)p2);
#endif

  m_window->show(1, argv);
  g_window->show(1, argv);

  create_general_options_window();
  create_geometry_options_window();
  create_mesh_options_window();
  create_solver_options_window();
  create_post_options_window();
  create_view_options_window(-1);
  create_message_window();
  create_visibility_window();
  create_about_window();

  for(i=0; i<5; i++){
    solver[i].window = NULL;
    create_solver_window(i);
  }

  // Draw the scene
  g_opengl_window->redraw();

}

// Run the GUI until no window is left

void GUI::run(){
  Fl::run();
}

// Check (now) if any pending events and run them

void GUI::check(){
  Fl::check();
}

// Wait for any events and run them

void GUI::wait(){
  Fl::wait();
}

//********************************* Create the menu window *****************************


void GUI::add_post_plugins (Fl_Menu_Button *button , int iView){
  char name[256],menuname[256];
  for(GMSH_PluginManager::iter it = GMSH_PluginManager::Instance()->begin();
      it != GMSH_PluginManager::Instance()->end();
      ++it){
    GMSH_Plugin *p = (*it).second;
    if(p->getType() == GMSH_Plugin::GMSH_POST_PLUGIN){
      p->getName(name);
      std::pair<int,GMSH_Plugin*> *pair = new std::pair<int,GMSH_Plugin*>(iView,p);
      sprintf(menuname,"Plugins/%s...",name);
      button->add(menuname, 0,(Fl_Callback *)view_options_plugin_cb, (void*)(pair), 0);
      p->dialogBox = 0;
    }
  }
}

void GUI::create_menu_window(int argc, char **argv){
  int i, y;
  
  if(m_window){
    m_window->show(1, argv);
    return;
  }

  int width = 13*CTX.fontsize-CTX.fontsize/2-2 ;
  MH = BH + BH+6 ; // this is the initial height: no dynamic button is shown!
  
  m_window = new Fl_Window(width,MH);
  m_window->box(WINDOW_BOX);
  m_window->label("Gmsh");
  m_window->callback(file_quit_cb);
  
  m_menu_bar = new Fl_Menu_Bar(0,0,width,BH); 
  m_menu_bar->menu(m_menubar_table);
  m_menu_bar->box(FL_UP_BOX);
  m_menu_bar->global();
  
  Fl_Box *o = new Fl_Box(0,BH,width,BH+6);
  o->box(FL_UP_BOX);
  
  y = BH + 3;
  
  m_navig_butt[0] = new Fl_Button(1,y,18,BH/2,"@<");
  m_navig_butt[0]->labeltype(FL_SYMBOL_LABEL);
  m_navig_butt[0]->labelsize(11);
  m_navig_butt[0]->box(FL_FLAT_BOX);
  m_navig_butt[0]->selection_color(FL_WHITE);
  m_navig_butt[0]->callback(mod_back_cb);
  
  m_navig_butt[1] = new Fl_Button(1,y+BH/2,18,BH/2,"@>");
  m_navig_butt[1]->labeltype(FL_SYMBOL_LABEL);
  m_navig_butt[1]->labelsize(11);
  m_navig_butt[1]->box(FL_FLAT_BOX);
  m_navig_butt[1]->selection_color(FL_WHITE);
  m_navig_butt[1]->callback(mod_forward_cb);

#if !((FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 0))
  m_navig_butt[0]->tooltip("Go back in menu history");
  m_navig_butt[1]->tooltip("Go forward in menu history");
#endif
  
  m_module_butt = new Fl_Choice(19,y,width-24,BH);
  m_module_butt->menu(m_module_table);
  m_module_butt->box(FL_THIN_DOWN_BOX);
  
  y = MH ;
  
  for(i=0; i<NB_BUTT_MAX; i++){
    m_push_butt[i] = new Fl_Button(0,y+i*BH,width,BH); 
    m_push_butt[i]->hide();
    m_toggle_butt[i] = new Fl_Light_Button(0,y+i*BH,width,BH); 
    m_toggle_butt[i]->callback(view_toggle_cb, (void*)i);
    m_toggle_butt[i]->hide();
    m_popup_butt[i] = new Fl_Menu_Button(0,y+i*BH,width,BH);
    m_popup_butt[i]->type(Fl_Menu_Button::POPUP3);
    m_popup_butt[i]->add("Reload/View", 0, 
			 (Fl_Callback *)view_reload_cb, (void*)i, 0);
    m_popup_butt[i]->add("Reload/All views", 0, 
			 (Fl_Callback *)view_reload_all_cb, (void*)i, 0);
    m_popup_butt[i]->add("Reload/All visible views", 0, 
			 (Fl_Callback *)view_reload_visible_cb, (void*)i, 0);
    m_popup_butt[i]->add("Remove/View", 0, 
			 (Fl_Callback *)view_remove_cb, (void*)i, 0);
    m_popup_butt[i]->add("Remove/All views", 0, 
			 (Fl_Callback *)view_remove_all_cb, (void*)i, 0);
    m_popup_butt[i]->add("Remove/All visible views", 0, 
			 (Fl_Callback *)view_remove_visible_cb, (void*)i, 0);
    m_popup_butt[i]->add("Remove/All invisible views", 0, 
			 (Fl_Callback *)view_remove_invisible_cb, (void*)i, 0);
    m_popup_butt[i]->add("Duplicate/View without options", 0,
			 (Fl_Callback *)view_duplicate_cb, (void*)i, 0) ;
    m_popup_butt[i]->add("Duplicate/View with options", 0,
			 (Fl_Callback *)view_duplicate_with_options_cb, (void*)i, 0) ;
    m_popup_butt[i]->add("Save as/ASCII view...", 0,
			 (Fl_Callback *)view_save_ascii_cb, (void*)i, 0) ;
    m_popup_butt[i]->add("Save as/Binary view...", 0,
			 (Fl_Callback *)view_save_binary_cb, (void*)i, 0) ;
    add_post_plugins(m_popup_butt[i], i);
    m_popup_butt[i]->add("Apply as background mesh", 0,
			 (Fl_Callback *)view_applybgmesh_cb, (void*)i, FL_MENU_DIVIDER);
    m_popup_butt[i]->add("Options...", 0,
			 (Fl_Callback *)view_options_cb, (void*)i, 0);
    m_popup_butt[i]->hide();
  }
  
  m_window->position(CTX.position[0],CTX.position[1]);
  m_window->end();
  
}

// Dynamically set the height of the menu window

void GUI::set_menu_size(int nb_butt){
  m_window->size(m_window->w(), MH + nb_butt*BH);
}

// Dynamically set the context

void GUI::set_context(Context_Item *menu_asked, int flag){
  static int nb_back = 0, nb_forward = 0, init_context=0;
  static Context_Item *menu_history[NB_HISTORY_MAX];
  Context_Item *menu;
  Post_View *v;
  int i;
  
  if(!init_context){
    init_context = 1;
    for(i=0 ; i<NB_HISTORY_MAX ; i++){
      menu_history[i] = NULL ;
    }
  }
  
  if(nb_back > NB_HISTORY_MAX-2) nb_back = 1; // we should do a circular list
  
  if(flag == -1){
    if(nb_back > 1){
      nb_back--;
      nb_forward++;
      menu = menu_history[nb_back-1];
    }
    else return;
  }
  else if(flag == 1){
    if(nb_forward > 0){
      nb_back++;
      nb_forward--;
      menu = menu_history[nb_back-1];
    }
    else return;
  }
  else{
    menu = menu_asked;
    if(!nb_back || menu_history[nb_back-1] != menu){
      menu_history[nb_back++] = menu;
    }
    nb_forward = 0;
  }
  
  int nb = 0;
  
  if(menu[0].label[0] == '0')      m_module_butt->value(0);
  else if(menu[0].label[0] == '1') m_module_butt->value(1);
  else if(menu[0].label[0] == '2') m_module_butt->value(2);
  else if(menu[0].label[0] == '3') m_module_butt->value(3);
  else {
    Msg(WARNING, "Something is wrong in your dynamic context definition");
    return;
  }
  
  Msg(STATUS2, menu[0].label+1);
  
  switch(m_module_butt->value()){
  case 3 : // post-processing contexts
    for(i = 0 ; i < List_Nbr(CTX.post.list) ; i++) {
      if(i == NB_BUTT_MAX) break;
      nb++ ;
      v = (Post_View*)List_Pointer(CTX.post.list,i);
      m_push_butt[i]->hide();
      m_toggle_butt[i]->show();
      m_toggle_butt[i]->value(v->Visible);
      m_toggle_butt[i]->label(v->Name);
      m_popup_butt[i]->show();
    }
    for(i = List_Nbr(CTX.post.list) ; i < NB_BUTT_MAX ; i++) {
      m_push_butt[i]->hide();
      m_toggle_butt[i]->hide();
      m_popup_butt[i]->hide();
    }
    break;
  default : // geometry, mesh, solver contexts
    if(m_module_butt->value() == 2){ //solver
      menu[1].label = opt_solver_name0(0,GMSH_GET,0);
      menu[2].label = opt_solver_name1(0,GMSH_GET,0);
      menu[3].label = opt_solver_name2(0,GMSH_GET,0);
      menu[4].label = opt_solver_name3(0,GMSH_GET,0);
      menu[5].label = opt_solver_name4(0,GMSH_GET,0);
      for(i=0 ; i<5 ; i++){
	if(!strlen(menu[i+1].label)) menu[i+1].label = NULL;
      }
    }
    for(i=0 ; i < NB_BUTT_MAX ; i++){
      m_toggle_butt[i]->hide();
      m_popup_butt[i]->hide();
      if(menu[i+1].label){
	m_push_butt[i]->label(menu[i+1].label);
	m_push_butt[i]->callback(menu[i+1].callback,menu[i+1].arg);
	m_push_butt[i]->redraw();
	m_push_butt[i]->show();
	nb++;
      }
      else
	break;
    }
    for(i=nb ; i<NB_BUTT_MAX ; i++){
      m_toggle_butt[i]->hide();
      m_popup_butt[i]->hide();
      m_push_butt[i]->hide();
    }
    break ;
  }
  
  set_menu_size(nb);
  
}

int GUI::get_context(){
  return m_module_butt->value();
}


//******************************** Create the graphic window ***************************

void GUI::create_graphic_window(int argc, char **argv){
  int i, x;
  
  if(g_window){
    g_window->show(1, argv);
    return;
  }
  
  int sh = 2*CTX.fontsize-4; // status bar height
  int sw = CTX.fontsize+4; //status button width
  int width = CTX.viewport[2]-CTX.viewport[0];
  int glheight = CTX.viewport[3]-CTX.viewport[1];
  int height = glheight + sh;
  
  g_window = new Fl_Window(width, height);
  g_window->callback(file_quit_cb);
  
  g_opengl_window = new Opengl_Window(0,0,width,glheight);
  if(!opt_general_double_buffer(0,GMSH_GET,0)){
    Msg(INFO, "Setting OpenGL visual to single buffered");
    g_opengl_window->mode(FL_RGB | FL_DEPTH | FL_SINGLE);
  }
  g_opengl_window->end();

  Fl_Box *bottom = new Fl_Box(0,glheight,width,sh);
  bottom->box(FL_THIN_UP_BOX);

  x = 2;
  
  g_status_butt[0] = new Fl_Button(x,glheight+2,sw,sh-4,"X"); x+=sw;
  g_status_butt[0]->callback(status_xyz1p_cb, (void*)0);
  g_status_butt[1] = new Fl_Button(x,glheight+2,sw,sh-4,"Y"); x+=sw;
  g_status_butt[1]->callback(status_xyz1p_cb, (void*)1);
  g_status_butt[2] = new Fl_Button(x,glheight+2,sw,sh-4,"Z"); x+=sw;
  g_status_butt[2]->callback(status_xyz1p_cb, (void*)2);
  g_status_butt[3] = new Fl_Button(x,glheight+2,2*CTX.fontsize,sh-4,"1:1"); x+=2*CTX.fontsize;
  g_status_butt[3]->callback(status_xyz1p_cb, (void*)3);
  g_status_butt[4] = new Fl_Button(x,glheight+2,sw,sh-4,"?"); x+=sw;
  g_status_butt[4]->callback(status_xyz1p_cb, (void*)4);
  g_status_butt[5] = new Fl_Button(x,glheight+2,sw,sh-4); x+=sw;
  g_status_butt[5]->callback(status_rewind_cb);
  rewind_bmp = new Fl_Bitmap(rewind_bits,rewind_width,rewind_height);
  rewind_bmp->label(g_status_butt[5]);
  g_status_butt[5]->deactivate();
  g_status_butt[6] = new Fl_Button(x,glheight+2,sw,sh-4); x+=sw;
  g_status_butt[6]->callback(status_play_cb);
  start_bmp = new Fl_Bitmap(start_bits,start_width,start_height);
  start_bmp->label(g_status_butt[6]);
  stop_bmp = new Fl_Bitmap(stop_bits,stop_width,stop_height);
  g_status_butt[6]->deactivate();

  /*
  g_status_butt[7] = new Fl_Button(x,glheight+2,sw,sh-4); x+=sw;
  g_status_butt[7]->callback(status_cancel_cb);
  abort_bmp = new Fl_Bitmap(abort_bits,abort_width,abort_height);
  abort_bmp->label(g_status_butt[7]);
  g_status_butt[7]->deactivate();
  */
  for(i = 0 ; i<7 ; i++){
    g_status_butt[i]->box(FL_FLAT_BOX);
    g_status_butt[i]->selection_color(FL_WHITE);
    g_status_butt[i]->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
  }
  
  g_status_label[0] = new Fl_Box(x,glheight+2,(width-x)/3,sh-4);
  g_status_label[1] = new Fl_Box(x+(width-x)/3,glheight+2,(width-x)/3,sh-4);
  g_status_label[2] = new Fl_Box(x+2*(width-x)/3,glheight+2,(width-x)/3-2,sh-4);
  for(i = 0 ; i<3 ; i++){
    g_status_label[i]->box(FL_FLAT_BOX);
    g_status_label[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
  }


#if !((FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 0))
  g_status_butt[0]->tooltip("Set X view (Y=Z=0)");
  g_status_butt[1]->tooltip("Set Y view (X=Z=0)");
  g_status_butt[2]->tooltip("Set Z view (X=Y=0)");
  g_status_butt[3]->tooltip("Set unit scale");
  g_status_butt[4]->tooltip("Show current options");
  g_status_butt[5]->tooltip("Rewind animation");
  g_status_butt[6]->tooltip("Play/pause animation");
#endif
  
  g_window->resizable(new Dummy_Box(x,0,width-x,glheight));
  
  g_window->position(CTX.gl_position[0],CTX.gl_position[1]);
  g_window->end();   
}

// Set the size of the graphical window

void GUI::set_size(int new_w, int new_h){
  g_window->size(new_w,new_h+g_window->h()-g_opengl_window->h());
}

// Set graphic window title

void GUI::set_title(char *str){
  g_window->label(str);
}

// Set animation button

void GUI::set_anim_buttons(int mode){
  if(mode){
    g_status_butt[6]->callback(status_play_cb);
    start_bmp->label(g_status_butt[6]);
  }
  else{
    g_status_butt[6]->callback(status_pause_cb);
    stop_bmp->label(g_status_butt[6]);
  }
}

void GUI::check_anim_buttons(){
  int i, play=0;
  if(CTX.post.anim_cycle){
    play = 1;
  }
  else{
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++){
      if(((Post_View*)List_Pointer(CTX.post.list,i))->NbTimeStep > 1){
	play = 1 ; 
	break ;
      }
    }
  }
  if(!play){
    g_status_butt[5]->deactivate();
    g_status_butt[6]->deactivate();
  }
  else{
    g_status_butt[5]->activate();
    g_status_butt[6]->activate();
  }
}

// Set the status messages

void GUI::set_status(char *msg, int num){
  g_status_label[num]->label(msg);
  g_status_label[num]->redraw();
}

// set the current drawing context 

void GUI::make_opengl_current(){
  g_opengl_window->make_current();
}

void GUI::make_overlay_current(){
  g_opengl_window->make_overlay_current();
}

// Draw the opengl window

void GUI::redraw_opengl(){
  g_opengl_window->redraw();
}

// Draw the opengl overlay window

void GUI::redraw_overlay(){
  g_opengl_window->redraw_overlay();
}

//************************ Create the window for general options ***********************

void GUI::create_general_options_window(){
  int i;
  
  if(gen_window){
    gen_window->show();
    return;
  }
    
  int width = 25*CTX.fontsize;
  int height = 5*WB+11*BH ;
  int BW = width-4*WB;
  
  gen_window = new Fl_Window(width,height);
  gen_window->box(WINDOW_BOX);
  gen_window->label("General options");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Display");
      gen_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Show moving axes");
      gen_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Show small axes");
      gen_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Enable fast redraw");
      gen_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW, BH, "Enable double buffering");
      gen_butt[4] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW, BH, "Use display lists");
      gen_butt[5] = new Fl_Check_Button(2*WB, 2*WB+6*BH, BW, BH, "Enable alpha blending");
      gen_butt[6] = new Fl_Check_Button(2*WB, 2*WB+7*BH, BW, BH, "Use trackball rotation mode");
      for(i=0 ; i<7 ; i++){
	gen_butt[i]->type(FL_TOGGLE_BUTTON);
	gen_butt[i]->down_box(TOGGLE_BOX);
	gen_butt[i]->selection_color(TOGGLE_COLOR);
      }
      gen_butt[13] = new Fl_Check_Button(2*WB, 2*WB+8*BH, BW, BH, "Show tooltips");
      gen_butt[13]->type(FL_TOGGLE_BUTTON);
      gen_butt[13]->down_box(TOGGLE_BOX);
      gen_butt[13]->selection_color(TOGGLE_COLOR);

      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Output");
      gen_butt[7] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Print messages on terminal");
      gen_butt[8] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Save session information on exit");
      gen_butt[9] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Save options on exit");
      for(i=7 ; i<10 ; i++){
	gen_butt[i]->type(FL_TOGGLE_BUTTON);
	gen_butt[i]->down_box(TOGGLE_BOX);
	gen_butt[i]->selection_color(TOGGLE_COLOR);
      }
      gen_value[5] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Message verbosity");
      gen_value[5]->minimum(0); 
      gen_value[5]->maximum(10); 
      gen_value[5]->step(1);
      gen_value[5]->align(FL_ALIGN_RIGHT);
      gen_input[0] = new Fl_Input(2*WB, 2*WB+5*BH, IW, BH, "Default file name");
      gen_input[1] = new Fl_Input(2*WB, 2*WB+6*BH, IW, BH, "Temporary file");
      gen_input[2] = new Fl_Input(2*WB, 2*WB+7*BH, IW, BH, "Error file");
      gen_input[3] = new Fl_Input(2*WB, 2*WB+8*BH, IW, BH, "Option file");
      gen_input[4] = new Fl_Input(2*WB, 2*WB+9*BH, IW, BH, "Text editor command");
      for(i=0 ; i<5 ; i++){
	gen_input[i]->align(FL_ALIGN_RIGHT);
      }
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Aspect");
      o->hide();
      gen_butt[10] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Orthographic projection");
      gen_butt[11] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Perspective projection");
      for(i=10 ; i<12 ; i++){
	gen_butt[i]->type(FL_RADIO_BUTTON);
	gen_butt[i]->down_box(RADIO_BOX);
	gen_butt[i]->selection_color(RADIO_COLOR);
      }
      gen_value[6] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Point size");
      gen_value[6]->minimum(0.1);
      gen_value[6]->maximum(50);
      gen_value[6]->step(0.1);
      gen_value[7] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Line width");
      gen_value[7]->minimum(0.1);
      gen_value[7]->maximum(50);
      gen_value[7]->step(0.1);
      for(i=6 ; i<= 7 ; i++){
	gen_value[i]->align(FL_ALIGN_RIGHT);
      }
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Colors");
      o->hide();
      gen_value[0] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Predefined color scheme");
      gen_value[0]->minimum(0); 
      gen_value[0]->maximum(2); 
      gen_value[0]->step(1);
      gen_value[0]->align(FL_ALIGN_RIGHT);
      gen_value[0]->callback(opt_general_color_scheme_cb);
      
      Fl_Scroll* s = new Fl_Scroll(2*WB, 3*WB+2*BH, IW+20, height-3*WB-4*BH);
      i = 0;
      while(GeneralOptions_Color[i].str){
	gen_col[i] = new Fl_Button(2*WB, 3*WB+(2+i)*BH, IW, BH, GeneralOptions_Color[i].str);
	gen_col[i]->callback(color_cb, (void*)GeneralOptions_Color[i].function) ;
	i++;
      }
      s->end();
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Light");
      o->hide();
      gen_value[1] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Material shininess");
      gen_value[1]->minimum(0); 
      gen_value[1]->maximum(10);
      gen_value[1]->step(0.1);
      gen_butt[12] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Moving light");
      gen_butt[12]->type(FL_TOGGLE_BUTTON);
      gen_butt[12]->down_box(TOGGLE_BOX);
      gen_butt[12]->selection_color(TOGGLE_COLOR);
      gen_value[2] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Light position X");
      gen_value[2]->minimum(-1); 
      gen_value[2]->maximum(1);
      gen_value[2]->step(0.01);
      gen_value[3] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Light position Y");
      gen_value[3]->minimum(-1); 
      gen_value[3]->maximum(1); 
      gen_value[3]->step(0.01);
      gen_value[4] = new Fl_Value_Input(2*WB, 2*WB+5*BH, IW, BH, "Light position Z");
      gen_value[4]->minimum(-1); 
      gen_value[4]->maximum(1); 
      gen_value[4]->step(0.01);
      for(i=1 ; i<5 ; i++){
	gen_value[i]->align(FL_ALIGN_RIGHT);
      }
      o->end();
    }
    o->end();
  }
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
    o->callback(opt_general_ok_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)gen_window);
  }
  
  if(CTX.center_windows)
    gen_window->position(m_window->x()+m_window->w()/2-width/2,
			 m_window->y()+9*BH-height/2);
  gen_window->end();
  
}

//************************ Create the window for geometry options **********************

void GUI::create_geometry_options_window(){
  int i;
  
  if(geo_window){
    geo_window->show();
    return;
  }
    
  int width = 25*CTX.fontsize;
  int height = 5*WB+10*BH ;
  int BW = width-4*WB;
  
  geo_window = new Fl_Window(width,height);
  geo_window->box(WINDOW_BOX);
  geo_window->label("Geometry options");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "General");
      o->hide();
      geo_butt[8] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Auto coherence (suppress duplicates)");
      geo_butt[8]->type(FL_TOGGLE_BUTTON);
      geo_butt[8]->down_box(TOGGLE_BOX);
      geo_butt[8]->selection_color(TOGGLE_COLOR);
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Visibility");
      geo_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW/2-WB, BH, "Points");
      geo_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW/2-WB, BH, "Curves");
      geo_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW/2-WB, BH, "Surfaces");
      geo_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW/2-WB, BH, "Volumes");
      geo_butt[4] = new Fl_Check_Button(width/2, 2*WB+1*BH, BW/2-WB, BH, "Point numbers");
      geo_butt[5] = new Fl_Check_Button(width/2, 2*WB+2*BH, BW/2-WB, BH, "Curve numbers");
      geo_butt[6] = new Fl_Check_Button(width/2, 2*WB+3*BH, BW/2-WB, BH, "Surface numbers");
      geo_butt[7] = new Fl_Check_Button(width/2, 2*WB+4*BH, BW/2-WB, BH, "Volume numbers");
      for(i=0 ; i<8 ; i++){
	geo_butt[i]->type(FL_TOGGLE_BUTTON);
	geo_butt[i]->down_box(TOGGLE_BOX);
	geo_butt[i]->selection_color(TOGGLE_COLOR);
      }
      
      geo_value[0] = new Fl_Value_Input(2*WB, 2*WB+5*BH, IW, BH, "Normals");
      geo_value[0]->minimum(0); 
      geo_value[0]->maximum(100);
      geo_value[0]->step(0.1);
      geo_value[1] = new Fl_Value_Input(2*WB, 2*WB+6*BH, IW, BH, "Tangents");
      geo_value[1]->minimum(0);
      geo_value[1]->maximum(100);
      geo_value[1]->step(0.1);
      for(i=0 ; i<2 ; i++){
	geo_value[i]->align(FL_ALIGN_RIGHT);
      }
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Aspect");
      o->hide();
      geo_value[3] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Point size");
      geo_value[3]->minimum(0.1);
      geo_value[3]->maximum(50);
      geo_value[3]->step(0.1);
      geo_value[4] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Line width");
      geo_value[4]->minimum(0.1);
      geo_value[4]->maximum(50);
      geo_value[4]->step(0.1);
      for(i=3 ; i<= 4 ; i++){
	geo_value[i]->align(FL_ALIGN_RIGHT);
      }
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Colors");
      o->hide();
      geo_value[2] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Predefined color scheme");
      geo_value[2]->minimum(0); 
      geo_value[2]->maximum(2); 
      geo_value[2]->step(1);
      geo_value[2]->align(FL_ALIGN_RIGHT);
      geo_value[2]->callback(opt_geometry_color_scheme_cb);
      
      Fl_Scroll* s = new Fl_Scroll(2*WB, 3*WB+2*BH, IW+20, height-3*WB-4*BH);
      i = 0;
      while(GeometryOptions_Color[i].str){
	geo_col[i] = new Fl_Button(2*WB, 3*WB+(2+i)*BH, IW, BH, GeometryOptions_Color[i].str);
	geo_col[i]->callback(color_cb, (void*)GeometryOptions_Color[i].function) ;
	i++;
      }
      s->end();
      o->end();
    }
    o->end();
  }
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
    o->callback(opt_geometry_ok_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)geo_window);
  }
  
  if(CTX.center_windows)
    geo_window->position(m_window->x()+m_window->w()/2-width/2,
			 m_window->y()+9*BH-height/2);
  geo_window->end();
  
}

//****************************** Create the window for mesh options ********************

void GUI::create_mesh_options_window(){
  int i;
  
  if(mesh_window){
    mesh_window->show();
    return;
  }
    
  int width = 25*CTX.fontsize;
  int height = 5*WB+10*BH ;
  int BW = width-4*WB;
  
  mesh_window = new Fl_Window(width,height);
  mesh_window->box(WINDOW_BOX);
  mesh_window->label("Mesh options");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "General");
      o->hide();
      
      mesh_value[0] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Number of smoothing steps");
      mesh_value[0]->minimum(0);
      mesh_value[0]->maximum(100); 
      mesh_value[0]->step(1);
      mesh_value[1] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Mesh scaling factor");
      mesh_value[1]->minimum(0.001);
      mesh_value[1]->maximum(1000); 
      mesh_value[1]->step(0.001);
      mesh_value[2] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Characteristic length factor");
      mesh_value[2]->minimum(0.001);
      mesh_value[2]->maximum(1000); 
      mesh_value[2]->step(0.001);
      mesh_value[3] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Random perturbation factor");
      mesh_value[3]->minimum(1.e-6);
      mesh_value[3]->maximum(1.e-1); 
      mesh_value[3]->step(1.e-6);
      for(i = 0 ; i<4 ; i++){
	mesh_value[i]->align(FL_ALIGN_RIGHT);
      }
      
      mesh_butt[3] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW, BH, "Second order elements");
      mesh_butt[3]->deactivate();//2nd order elements do not work. Disable the graphical option.
      mesh_butt[3]->type(FL_TOGGLE_BUTTON);
      mesh_butt[3]->down_box(TOGGLE_BOX);
      mesh_butt[3]->selection_color(TOGGLE_COLOR);

      mesh_butt[5] = new Fl_Check_Button(2*WB, 2*WB+6*BH, BW, BH, "Constrain background mesh");
      mesh_butt[5]->type(FL_TOGGLE_BUTTON);
      mesh_butt[5]->down_box(TOGGLE_BOX);
      mesh_butt[5]->selection_color(TOGGLE_COLOR);

      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "2D");
      o->hide();
      
      mesh_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Old isotropic algorithm");
      mesh_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "New isotropic algorithm");
      mesh_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Anisotropic algorithm");
      for(i=0 ; i<3 ; i++){
	mesh_butt[i]->type(FL_RADIO_BUTTON);
	mesh_butt[i]->down_box(RADIO_BOX);
	mesh_butt[i]->selection_color(RADIO_COLOR);
      }
      mesh_butt[4] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW, BH, "Interactive");
      mesh_butt[4]->type(FL_TOGGLE_BUTTON);
      mesh_butt[4]->down_box(TOGGLE_BOX);
      mesh_butt[4]->selection_color(TOGGLE_COLOR);

      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Visibility");
      mesh_butt[6] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW/2-WB, BH, "Points");
      mesh_butt[7] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW/2-WB, BH, "Lines");
      mesh_butt[8] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW/2-WB, BH, "Surfaces");
      mesh_butt[9] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW/2-WB, BH, "Volumes");
      mesh_butt[10] = new Fl_Check_Button(width/2, 2*WB+1*BH, BW/2-WB, BH, "Point numbers");
      mesh_butt[11] = new Fl_Check_Button(width/2, 2*WB+2*BH, BW/2-WB, BH, "Line numbers");
      mesh_butt[12] = new Fl_Check_Button(width/2, 2*WB+3*BH, BW/2-WB, BH, "Surface numbers");
      mesh_butt[13] = new Fl_Check_Button(width/2, 2*WB+4*BH, BW/2-WB, BH, "Volume numbers");
      for(i=6 ; i<14 ; i++){
	mesh_butt[i]->type(FL_TOGGLE_BUTTON);
	mesh_butt[i]->down_box(TOGGLE_BOX);
	mesh_butt[i]->selection_color(TOGGLE_COLOR);
      }
      mesh_value[4] = new Fl_Value_Input(2*WB, 2*WB+5*BH, IW/2, BH);
      mesh_value[4]->minimum(0); 
      mesh_value[4]->maximum(1);
      mesh_value[4]->step(0.001);
      mesh_value[5] = new Fl_Value_Input(2*WB+IW/2, 2*WB+5*BH, IW/2, BH, "Quality range");
      mesh_value[5]->minimum(0); 
      mesh_value[5]->maximum(1);
      mesh_value[5]->step(0.001);
      
      mesh_value[6] = new Fl_Value_Input(2*WB, 2*WB+6*BH, IW/2, BH);
      mesh_value[7] = new Fl_Value_Input(2*WB+IW/2, 2*WB+6*BH, IW/2, BH, "Size range");
      
      mesh_value[8] = new Fl_Value_Input(2*WB, 2*WB+7*BH, IW, BH, "Normals");
      mesh_value[8]->minimum(0); 
      mesh_value[8]->maximum(100);
      mesh_value[8]->step(0.1);
      for(i=4 ; i<9 ; i++){
	mesh_value[i]->align(FL_ALIGN_RIGHT);
      }

      mesh_value[13] = new Fl_Value_Input(2*WB, 2*WB+8*BH, IW, BH, "Tangents");
      mesh_value[13]->minimum(0); 
      mesh_value[13]->maximum(100);
      mesh_value[13]->step(0.1);
      mesh_value[13]->align(FL_ALIGN_RIGHT);

      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Aspect");
      o->hide();
      mesh_butt[14] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Wireframe");
      mesh_butt[15] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Hidden lines");
      mesh_butt[16] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Solid");
      for(i=14 ; i<17 ; i++){
	mesh_butt[i]->type(FL_RADIO_BUTTON);
	mesh_butt[i]->down_box(RADIO_BOX);
	mesh_butt[i]->selection_color(RADIO_COLOR);
      }
      mesh_value[9] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Explode elements");
      mesh_value[9]->minimum(0);
      mesh_value[9]->maximum(1);
      mesh_value[9]->step(0.01);
      mesh_value[10] = new Fl_Value_Input(2*WB, 2*WB+5*BH, IW, BH, "Point size");
      mesh_value[10]->minimum(0.1);
      mesh_value[10]->maximum(50);
      mesh_value[10]->step(0.1);
      mesh_value[11] = new Fl_Value_Input(2*WB, 2*WB+6*BH, IW, BH, "Line width");
      mesh_value[11]->minimum(0.1);
      mesh_value[11]->maximum(50);
      mesh_value[11]->step(0.1);
      for(i=9 ; i<= 11 ; i++){
	mesh_value[i]->align(FL_ALIGN_RIGHT);
      }
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Colors");
      o->hide();
      mesh_butt[17] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Switch color by entity");
      mesh_butt[17]->type(FL_TOGGLE_BUTTON);
      mesh_butt[17]->down_box(TOGGLE_BOX);
      mesh_butt[17]->selection_color(TOGGLE_COLOR);
      
      mesh_value[12] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Predefined color scheme");
      mesh_value[12]->minimum(0); 
      mesh_value[12]->maximum(2); 
      mesh_value[12]->step(1);
      mesh_value[12]->align(FL_ALIGN_RIGHT);
      mesh_value[12]->callback(opt_mesh_color_scheme_cb);
      
      Fl_Scroll* s = new Fl_Scroll(2*WB, 3*WB+3*BH, IW+20, height-3*WB-5*BH);
      i = 0;
      while(MeshOptions_Color[i].str){
	mesh_col[i] = new Fl_Button(2*WB, 3*WB+(3+i)*BH, IW, BH, MeshOptions_Color[i].str);
	mesh_col[i]->callback(color_cb, (void*)MeshOptions_Color[i].function) ;
	i++;
      }
      s->end();
      o->end();
    }
    o->end();
  }
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
    o->callback(opt_mesh_ok_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)mesh_window);
  }
  
  if(CTX.center_windows)
    mesh_window->position(m_window->x()+m_window->w()/2-width/2,
			  m_window->y()+9*BH-height/2);
  mesh_window->end();
  
}

//******************** Create the window for solver options *******************

void GUI::create_solver_options_window(){

  if(solver_window){
    solver_window->show();
    return;
  }

  int width = 20*CTX.fontsize;
  int height = 5*WB+8*BH ;

  solver_window = new Fl_Window(width,height);
  solver_window->box(WINDOW_BOX);
  solver_window->label("Solver options");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Solvers");

      Fl_Box *text =  new Fl_Box(FL_NO_BOX, 2*WB, 3*WB+1*BH, width-4*WB, 2*BH,
				 "There are no global solver options available yet.\n\n"
				 "To define your own solver interface, edit the option file.");
      text->align(FL_ALIGN_LEFT|FL_ALIGN_TOP|FL_ALIGN_INSIDE|FL_ALIGN_WRAP);
      /*
	int BW = width-4*WB;
	solver_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Use Unix sockets");
	solver_butt[0]->type(FL_TOGGLE_BUTTON);
	solver_butt[0]->down_box(TOGGLE_BOX);
	solver_butt[0]->selection_color(TOGGLE_COLOR);
      */
      o->end();
    }
    o->end();
  }
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
    o->callback(opt_solver_ok_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)solver_window);
  }
  
  if(CTX.center_windows)
    solver_window->position(m_window->x()+m_window->w()/2-width/2,
			    m_window->y()+9*BH-height/2);
  solver_window->end();
  
}


//******************** Create the window for post-processing options *******************

void GUI::create_post_options_window(){
  int i;

  if(post_window){
    post_window->show();
    return;
  }

  int width = 25*CTX.fontsize;
  int height = 5*WB+10*BH ;
  int BW = width-4*WB;
  
  post_window = new Fl_Window(width,height);
  post_window->box(WINDOW_BOX);
  post_window->label("Post-processing options");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Views");
      post_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Independent views");
      post_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Apply next changes to all visible views");
      post_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Apply next changes to all views");
      post_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW, BH, "Force same options for all visible views");
      post_butt[4] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW, BH, "Force same options for all views");
      for(i=0 ; i<5 ; i++){
	post_butt[i]->type(FL_RADIO_BUTTON);
	post_butt[i]->down_box(RADIO_BOX);
	post_butt[i]->selection_color(RADIO_COLOR);
      }
      Fl_Box *text =  new Fl_Box(FL_NO_BOX, 2*WB, 3*WB+6*BH, width-4*WB, 2*BH,
				 "Individual view options are available "
				 "by right-clicking on each view button "
				 "in the post-processing menu");
      text->align(FL_ALIGN_LEFT|FL_ALIGN_TOP|FL_ALIGN_INSIDE|FL_ALIGN_WRAP);
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Smoothing");
      post_butt[5] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Smooth views during merge");
      post_butt[5]->type(FL_TOGGLE_BUTTON);
      post_butt[5]->down_box(TOGGLE_BOX);
      post_butt[5]->selection_color(TOGGLE_COLOR);
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Animation");
      o->hide();
      post_value[0] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Delay");
      post_value[0]->minimum(0);
      post_value[0]->maximum(10); 
      post_value[0]->step(0.01);
      post_value[0]->align(FL_ALIGN_RIGHT);

      post_butt[6] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Cycle through views instead of time steps");
      post_butt[6]->type(FL_TOGGLE_BUTTON);
      post_butt[6]->down_box(TOGGLE_BOX);
      post_butt[6]->selection_color(TOGGLE_COLOR);
      o->end();
    }
    o->end();
  }
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
    o->callback(opt_post_ok_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)post_window);
  }
  
  if(CTX.center_windows)
    post_window->position(m_window->x()+m_window->w()/2-width/2,
			  m_window->y()+9*BH-height/2);
  post_window->end();
  
}

//*********************** Create the window for the statistics *************************

void GUI::create_statistics_window(){
  int i, num=0;

  if(stat_window){
    if(!stat_window->shown()) set_statistics();
    stat_window->show();
    return;
  }

  int width = 25*CTX.fontsize;
  int height = 5*WB+17*BH ;
  
  stat_window = new Fl_Window(width,height);
  stat_window->box(WINDOW_BOX);
  stat_window->label("Statistics");
  {
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Geometry");
      o->hide();
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+1*BH, IW, BH, "Points");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+2*BH, IW, BH, "Curves");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+3*BH, IW, BH, "Surfaces");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+4*BH, IW, BH, "Volumes");
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Mesh");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+1*BH, IW, BH, "Nodes on curves");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+2*BH, IW, BH, "Nodes on surfaces");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+3*BH, IW, BH, "Nodes in volumes");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+4*BH, IW, BH, "Triangles");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+5*BH, IW, BH, "Quadrangles");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+6*BH, IW, BH, "Tetrahedra");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+7*BH, IW, BH, "Hexahedra");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+8*BH, IW, BH, "Prisms");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+9*BH, IW, BH, "Pyramids");
      
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+10*BH, IW, BH, "Time for 1D mesh");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+11*BH, IW, BH, "Time for 2D mesh");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+12*BH, IW, BH, "Time for 3D mesh");
      
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+13*BH, IW, BH, "Gamma factor");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+14*BH, IW, BH, "Eta factor");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+15*BH, IW, BH, "Rho factor");
      
      Fl_Button* b0 = new Fl_Button(width-BB-2*WB, 2*WB+13*BH, BB, BH, "Graph");
      b0->callback(opt_statistics_histogram_cb, (void*)0);
      Fl_Button* b1 = new Fl_Button(width-BB-2*WB, 2*WB+14*BH, BB, BH, "Graph");
      b1->callback(opt_statistics_histogram_cb, (void*)1);
      Fl_Button* b2 = new Fl_Button(width-BB-2*WB, 2*WB+15*BH, BB, BH, "Graph");
      b2->callback(opt_statistics_histogram_cb, (void*)2);
      
      o->end();
    }
    { 
      Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Post-processing");
      o->hide();
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+1*BH, IW, BH, "Views");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+2*BH, IW, BH, "Visible points");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+3*BH, IW, BH, "Visible lines");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+4*BH, IW, BH, "Visible triangles");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+5*BH, IW, BH, "Visible tetrahedra");
      stat_value[num++] = new Fl_Output(2*WB, 2*WB+6*BH, IW, BH, "Visible strings");
      o->end();
    }
    o->end();
  }
  
  for(i=0 ; i<num ; i++){
    stat_value[i]->align(FL_ALIGN_RIGHT);
    stat_value[i]->value(0);
  }
  
  { 
    Fl_Button* o = new Fl_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "Update");
    o->callback(opt_statistics_update_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)stat_window);
  }
  
  if(CTX.center_windows)
    stat_window->position(m_window->x()+m_window->w()/2-width/2,
			  m_window->y()+9*BH-height/2);
  stat_window->end();
  set_statistics();
  stat_window->show();

}

void GUI::set_statistics(){

  int i,num=0;
  static double  s[50], p[20];
  static char    label[50][256];

  GetStatistics(s);

  // geom
  sprintf(label[num], "%g", s[0]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[1]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[2]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[3]); stat_value[num]->value(label[num]); num++;

  // mesh
  sprintf(label[num], "%g", s[4]);  stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[5]);  stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[6]);  stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[7]-s[8]); 
                                    stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[8]);  stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[9]);  stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[10]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[11]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[12]); stat_value[num]->value(label[num]); num++;

  sprintf(label[num], "%g", s[13]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[14]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g", s[15]); stat_value[num]->value(label[num]); num++;

  sprintf(label[num], "%.4g (%.4g->%.4g)", s[17], s[19], s[18]); 
                                    stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%.4g (%.4g->%.4g)", s[20], s[22], s[21]); 
                                    stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%.4g (%.4g->%.4g)", s[23], s[25], s[24]);
                                    stat_value[num]->value(label[num]); num++;

  // post
  p[0] = List_Nbr(CTX.post.list) ;
  sprintf(label[num], "%g", p[0]); stat_value[num]->value(label[num]); num++;
  p[1] = p[2] = p[3] = p[4] = p[5] = p[6] = p[7] = p[8] = p[9] = p[10] = 0 ;
  for(i=0 ; i<List_Nbr(CTX.post.list) ; i++){
    Post_View *v = (Post_View*)List_Pointer(CTX.post.list, i);
    p[1] += v->NbSP + v->NbVP + v->NbTP;
    p[2] += v->NbSL + v->NbVL + v->NbTL;
    p[3] += v->NbST + v->NbVT + v->NbTT;
    p[4] += v->NbSS + v->NbVS + v->NbTS;
    p[5] += v->NbT2 + v->NbT3;
    if(v->Visible){
      if(v->DrawPoints)	p[6] += (v->DrawScalars ? v->NbSP : 0) + 
			        (v->DrawVectors ? v->NbVP : 0) + 
			        (v->DrawTensors ? v->NbTP : 0) ;
      if(v->DrawLines) p[7] += (v->DrawScalars ? v->NbSL : 0) + 
			       (v->DrawVectors ? v->NbVL : 0) + 
			       (v->DrawTensors ? v->NbTL : 0) ;
      if(v->DrawTriangles) p[8] += (v->DrawScalars ? v->NbST : 0) + 
			           (v->DrawVectors ? v->NbVT : 0) + 
			           (v->DrawTensors ? v->NbTT : 0) ;
      if(v->DrawTetrahedra) p[9] += (v->DrawScalars ? v->NbSS : 0) + 
			            (v->DrawVectors ? v->NbVS : 0) + 
   			            (v->DrawTensors ? v->NbTS : 0) ;
      if(v->DrawStrings) p[10] += v->NbT2 + v->NbT3 ;
    }
  }
  sprintf(label[num], "%g/%g", p[6],p[1]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g/%g", p[7],p[2]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g/%g", p[8],p[3]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g/%g", p[9],p[4]); stat_value[num]->value(label[num]); num++;
  sprintf(label[num], "%g/%g", p[10],p[5]); stat_value[num]->value(label[num]); num++;
}


//*********************** Create the window for the plugins *************************

void GUI::add_multiline_in_browser(Fl_Browser *o, char* prefix, char *str){
  int start = 0, len;
  char *buff;
  if(!str || !strlen(str) || !strcmp(str, "\n")){
    o->add("");
    return;
  }
  for(unsigned int i=0 ; i<strlen(str) ; i++){
    if(i==strlen(str)-1 || str[i]=='\n'){
      len = i-start+(str[i]=='\n'?0:1);
      buff = new char[len+strlen(prefix)+2];
      strcpy(buff, prefix);
      strncat(buff, &str[start], len);
      buff[len+strlen(prefix)]='\0';
      o->add(buff);
      start = i+1;
    }
  }
}

PluginDialogBox * GUI::create_plugin_window(GMSH_Plugin *p){
  char buffer[1024],namep[1024],copyright[256],author[256],help[1024];

  // get plugin info

  int n = p->getNbOptions();
  p->getName(namep);
  p->getInfos(author,copyright,help);

  // create window

  int width = 20*CTX.fontsize;
  int height = ((n>5?n:5)+2)*BH + 5*WB;

  PluginDialogBox *pdb = new PluginDialogBox;
  pdb->main_window = new Fl_Window(width,height);
  pdb->main_window->box(WINDOW_BOX);
  sprintf(buffer,"%s Plugin",namep);
  char *nbuffer = new char[strlen(buffer)+1];
  strcpy(nbuffer,buffer);
  pdb->main_window->label(nbuffer);

  { 
    Fl_Tabs *o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-1*BH);
    { 
      Fl_Group *g = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Options");

      if(n > 20)Msg(GERROR, "Plugin has too many parameters");
      
      for(int i=0;i<n;i++){
	StringXNumber *sxn;
	sxn = p->GetOption(i);
	pdb->view_value[i] = new Fl_Value_Input(2*WB, 2*WB+(i+1)*BH, IW, BH, sxn->str);
	pdb->view_value[i]->align(FL_ALIGN_RIGHT);
	pdb->view_value[i]->value(sxn->def);
      }

      g->end();
    }
    { 
      Fl_Group *g = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "About");

      Fl_Browser *o = new Fl_Browser(2*WB, 2*WB+1*BH, width-4*WB, height-5*WB-2*BH);

      o->add("");
      add_multiline_in_browser(o, "@c@b@.", namep);
      o->add("");
      add_multiline_in_browser(o, "", help);
      o->add("");
      add_multiline_in_browser(o, "Author(s): ", author);
      add_multiline_in_browser(o, "Copyright: ", copyright);
      
      g->end();
    }
    o->end();
  }

  Fl_Button* cancel = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Close");
  cancel->callback(cancel_cb, (void*)pdb->main_window);

  pdb->run_button = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "Run");

  pdb->main_window->resizable(new Fl_Box(2*WB,2*WB+BH,10,10));

  if(CTX.center_windows)
    pdb->main_window->position(m_window->x()+m_window->w()/2-width/2,
			       m_window->y()+9*BH-height/2);

  pdb->main_window->end();  

  return pdb;
}

//********************** Create the window for the messages ****************************

void GUI::create_message_window(){

  if(msg_window){
    if(msg_window->shown())
      msg_window->redraw();
    else
      msg_window->show();
    return;
  }
  
  int width = CTX.msg_size[0];
  int height = CTX.msg_size[1];
  
  msg_window = new Fl_Window(width,height);
  msg_window->box(WINDOW_BOX);
  msg_window->label("Messages");
  
  msg_browser = new Fl_Browser(WB, WB, width-2*WB, height-3*WB-BH);
  msg_browser->textfont(FL_COURIER);
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-3*BB-3*WB, height-BH-WB, BB, BH, "Save");
    o->callback(opt_message_save_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "Clear");
    o->callback(opt_message_clear_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)msg_window);
  }
  
  msg_window->resizable(new Fl_Box(WB,WB, 100,10));
  msg_window->size_range(WB+100 + 3*BB+4*WB,100);
  
  msg_window->position(CTX.msg_position[0], CTX.msg_position[1]);
  msg_window->end();
  
}

void GUI::add_message(char *msg){
  for(int i=0 ; i<(int)strlen(msg) ; i++) if(msg[i]=='\n') msg[i] = ' ';
  msg_browser->add(msg,0);
  msg_browser->bottomline(msg_browser->size());
}

void GUI::save_message(char *filename){
  FILE *fp;

  if(!(fp = fopen(filename,"w"))) {
    Msg(GERROR, "Unable to open file '%s'", filename); 
    return;
  }
  for(int i = 1 ; i<=msg_browser->size() ; i++){
    const char *c=msg_browser->text(i);
    if(c[0]=='@') fprintf(fp, "%s\n", &c[3]);
    else fprintf(fp, "%s\n", c);
  }

  Msg(INFO, "Log creation complete '%s'", filename);
  Msg(STATUS2, "Wrote '%s'", filename);
  fclose(fp);
}

void GUI::fatal_error(char *filename){
  fl_alert("A fatal error has occurred, which will force Gmsh to exit "
	   "(all messages have been saved in the error log file '%s')", filename);
}

//********************** Create the visibility window ****************************

void GUI::reset_visibility(){
  if(vis_window){
    vis_browser->clear();
    if(vis_window->shown()) 
      opt_visibility_cb(NULL,NULL);
  }
}

void GUI::create_visibility_window(){

  if(vis_window){
    vis_window->show();
    return;
  }

  static int cols[5] = {15,95,95,180,0};  
  static Fl_Menu_Item type_table[] = {
    {"Elementary",  0, (Fl_Callback *)opt_visibility_cb},
    {"Physical",    0, (Fl_Callback *)opt_visibility_cb},
    {0}
  };
  static Fl_Menu_Item browser_mode_table[] = {
    {"Geometry+Mesh",  0, (Fl_Callback *)opt_visibility_cb},
    {"Geometry",       0, (Fl_Callback *)opt_visibility_cb},
    {"Mesh",           0, (Fl_Callback *)opt_visibility_cb},
    {0}
  };
  static Fl_Menu_Item input_mode_table[] = {
    {"Node",     0, 0},
    {"Element",  0, 0},
    {"Point",    0, 0},
    {"Curve",    0, 0},
    {"Surface",  0, 0},
    {"Volume",   0, 0},
    {0}
  };

  int width = cols[0]+cols[1]+cols[2]+cols[3]+2*WB;
  int height = 15*BH ;
  
  vis_window = new Fl_Window(width,height);
  vis_window->box(WINDOW_BOX);
  vis_window->label("Visibility");
  
  int brw = width-2*WB;

  vis_type = new Fl_Choice(1*WB,1*WB+0*BH,brw/3,BH);
  vis_type->menu(type_table);
  
  vis_browser_mode = new Fl_Choice(2*WB+(brw-2*WB)/3,1*WB+0*BH,(brw-2*WB)/3,BH);
  vis_browser_mode->menu(browser_mode_table);
  
  vis_butt[0] = new Fl_Check_Button(3*WB+2*(brw-2*WB)/3, 1*WB+0*BH, (brw-2*WB)/3, BH, "Recursive");
  vis_butt[0]->type(FL_TOGGLE_BUTTON);
  vis_butt[0]->down_box(TOGGLE_BOX);
  vis_butt[0]->selection_color(TOGGLE_COLOR);
  vis_butt[0]->value(1);

  Fl_Button* o0 = new Fl_Button(1*WB, 2*WB+1*BH, cols[0], BH, "*");
  o0->callback(opt_visibility_sort_cb, (void*)0);

  Fl_Button* o1 = new Fl_Button(1*WB+cols[0], 2*WB+1*BH, cols[1], BH, "Type");
  //Fl_Box *a = new Fl_Box(FL_NO_BOX, 1*WB+15+cols[0]-15-20, 2*WB+1*BH, 15, BH, "@#UpArrow");
  //a->labeltype(FL_SYMBOL_LABEL);
  o1->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
  o1->callback(opt_visibility_sort_cb, (void*)1);

  Fl_Button* o2 = new Fl_Button(1*WB+cols[0]+cols[1], 2*WB+1*BH, cols[2], BH, "Number");
  o2->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
  o2->callback(opt_visibility_sort_cb, (void*)2);

  Fl_Button* o3 = new Fl_Button(1*WB+cols[0]+cols[1]+cols[2], 2*WB+1*BH, cols[3], BH, "Name");
  o3->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
  o3->callback(opt_visibility_sort_cb, (void*)3);

  vis_browser = new Fl_Browser(1*WB, 2*WB+2*BH, brw, height-5*WB-4*BH);
  vis_browser->textfont(FL_COURIER);
  vis_browser->type(FL_MULTI_BROWSER);
  vis_browser->column_widths(cols);

  vis_window->resizable(new Fl_Box(width-3*WB-2*BB-10,3*WB+2*BH+10, 10,10));
  vis_window->size_range(width, 5*BH+5*WB);

  vis_input = new Fl_Input(1*WB, height-2*WB-2*BH, (brw-2*WB)/3, BH);
  vis_input->callback(opt_visibility_number_cb);
  vis_input->when(FL_WHEN_ENTER_KEY|FL_WHEN_NOT_CHANGED);

  vis_input_mode = new Fl_Choice(2*WB+(brw-2*WB)/3, height-2*WB-2*BH, (brw-2*WB)/3, BH);
  vis_input_mode->menu(input_mode_table);
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
    o->callback(opt_visibility_ok_cb);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)vis_window);
  }

  if(CTX.center_windows)
    vis_window->position(m_window->x()+m_window->w()/2-width/2,
			 m_window->y()+9*BH-height/2);
  vis_window->end();
}

//******************************* Create the about window ******************************

void GUI::create_about_window(){
  char buffer[1024];

  if(about_window){
    about_window->show();
    return;
  }

  int width = 40*CTX.fontsize;
  int height = 10*BH ;
  
  about_window = new Fl_Window(width,height);
  about_window->box(WINDOW_BOX);
  about_window->label("About Gmsh");
  
  {
    Fl_Box *o = new Fl_Box(2*WB, WB, about_width, height-3*WB-BH);
    about_bmp = new Fl_Bitmap(about_bits,about_width,about_height);
    about_bmp->label(o);
  }
  
  {
    Fl_Browser *o = new Fl_Browser(WB+80, WB, width-2*WB-80, height-3*WB-BH);
    o->add("");
    o->add("@c@b@.Gmsh");
    o->add("@c@.A three-dimensional finite element mesh generator");
    o->add("@c@.with built-in pre- and post-processing facilities");
    o->add("");
    o->add("@c@.Copyright (c) 1997-2002");
    o->add("@c@.Christophe Geuzaine and Jean-François Remacle");
    o->add("");
    o->add("@c@.Please send all questions and bug reports to");
    o->add("@c@b@.gmsh@geuz.org");
    o->add("");
    sprintf(buffer, "@c@.Version: %d.%d.%d", GMSH_MAJOR_VERSION, 
	    GMSH_MINOR_VERSION, GMSH_PATCH_VERSION); o->add(buffer);
    sprintf(buffer, "@c@.Build date: %s", GMSH_DATE); o->add(buffer);
    sprintf(buffer, "@c@.Build OS: %s", GMSH_OS); o->add(buffer);
    sprintf(buffer, "@c@.Graphical user interface toolkit: FLTK %d.%d.%d",
	    FL_MAJOR_VERSION, FL_MINOR_VERSION, FL_PATCH_VERSION); o->add(buffer);
    sprintf(buffer, "@c@.Build host: %s", GMSH_HOST); o->add(buffer);
    sprintf(buffer, "@c@.Packaged by: %s", GMSH_PACKAGER); o->add(buffer);
    o->add("");
    o->add("@c@.Visit http://www.geuz.org/gmsh/ for more information");
  }
  
  { 
    Fl_Return_Button* o = new Fl_Return_Button(width-BB-WB, height-BH-WB, BB, BH, "OK");
    o->callback(cancel_cb, (void*)about_window);
  }
  
  if(CTX.center_windows)
    about_window->position(m_window->x()+m_window->w()/2-width/2,
			   m_window->y()+9*BH-height/2);
  about_window->end();
  
}

//************************* Create the window for view options *************************

// WARNING! Don't forget to add the set_changed_cb() callback to any new widget!

void GUI::create_view_options_window(int num){
  int i;

  if(view_window){
    update_view_window(num);
    view_window->show();
    return;
  }

  int width = 34*CTX.fontsize;
  int height = 5*WB+11*BH;
  int BW = width-4*WB;

  // initialise all buttons to NULL (see the clear_changed() in opt_view_options_bd)
  for(i=0; i<VIEW_OPT_BUTT; i++){
    view_butt[i] = NULL;
    view_value[i] = NULL;
    view_input[i] = NULL;
  }
  
  view_window = new Fl_Window(width,height);
  view_window->box(WINDOW_BOX);
  
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    // General
    { 
      Fl_Group *o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "General");
      
      view_butt[1] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW/2-WB, BH, "3D view");
      view_butt[2] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW/2-WB, BH, "2D space table");
      view_butt[3] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW/2-WB, BH, "2D time table");
      for(i=1 ; i<=3 ; i++){
	view_butt[i]->type(FL_RADIO_BUTTON);
	view_butt[i]->down_box(RADIO_BOX);
	view_butt[i]->selection_color(RADIO_COLOR);
	view_butt[i]->callback(set_changed_cb, 0);
      }
      
      view_input[0] = new Fl_Input(2*WB, 2*WB+4*BH, IW, BH, "Name");
      view_input[1] = new Fl_Input(2*WB, 2*WB+5*BH, IW, BH, "Format");
      for(i=0 ; i<=1 ; i++){
	view_input[i]->align(FL_ALIGN_RIGHT);
	view_input[i]->callback(set_changed_cb, 0);
      }

      int sw=(int)(1.5*CTX.fontsize);
      view_butt_rep[0] = new Fl_Repeat_Button(2*WB, 2*WB+6*BH, sw, BH, "-");
      //no set_changed since has its own callback
      view_butt_rep[1] = new Fl_Repeat_Button(2*WB+IW-sw, 2*WB+6*BH, sw, BH, "+");
      //no set_changed since has its own callback
      view_value[50] = new Fl_Value_Input(2*WB+sw, 2*WB+6*BH, IW-2*sw, BH);
      view_value[50]->align(FL_ALIGN_RIGHT);
      view_value[50]->minimum(0); 
      view_value[50]->maximum(0); 
      view_value[50]->step(1);
      //no set_changed since has its own callback
      Fl_Box *a = new Fl_Box(2*WB+IW, 2*WB+6*BH, IW/2, BH, "Time step");
      a->box(FL_NO_BOX);
      a->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);


      view_value[20] = new Fl_Value_Input(2*WB, 2*WB+7*BH, IW/2, BH);
      view_value[21] = new Fl_Value_Input(2*WB+IW/2, 2*WB+7*BH, IW/2, BH, "Position");
      view_value[22] = new Fl_Value_Input(2*WB, 2*WB+8*BH, IW/2, BH);
      view_value[23] = new Fl_Value_Input(2*WB+IW/2, 2*WB+8*BH, IW/2, BH, "Size");
      for(i=20 ; i<=23 ; i++){
	view_value[i]->align(FL_ALIGN_RIGHT);
	view_value[i]->callback(set_changed_cb, 0);
      }


      view_butt[8] = new Fl_Check_Button(width/2, 2*WB+1*BH, BW/2-WB, BH, "Show time");
      view_butt[5] = new Fl_Check_Button(width/2, 2*WB+2*BH, BW/2-WB, BH, "Show annotations");
      view_butt[4] = new Fl_Check_Button(width/2, 2*WB+3*BH, BW/2-WB, BH, "Show scale");
      view_butt[6] = new Fl_Check_Button(width/2, 2*WB+4*BH, BW/2-WB, BH, "Transparent scale");
      view_butt[7] = new Fl_Check_Button(width/2, 2*WB+5*BH, BW/2-WB, BH, "Scale/2D graph auto position");
      for(i=4 ; i<=8 ; i++){
	view_butt[i]->type(FL_TOGGLE_BUTTON);
	view_butt[i]->down_box(TOGGLE_BOX);
	view_butt[i]->selection_color(TOGGLE_COLOR);
	view_butt[i]->callback(set_changed_cb, 0);
      }
      
      
      o->end();
    }
    // 3D
    { 
      view_3d = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "3D");
      view_3d->hide();
      
      view_butt[10] = new Fl_Check_Button(width/2, 2*WB+1*BH, BW/2-WB, BH, "Show elements");
      view_butt[11] = new Fl_Check_Button(width/2, 2*WB+2*BH, BW/2-WB, BH, "Enable Lighting");
      view_butt[12] = new Fl_Check_Button(width/2, 2*WB+3*BH, BW/2-WB, BH, "Smooth normals");	
      for(i=10 ; i<=12 ; i++){
	view_butt[i]->type(FL_TOGGLE_BUTTON);
	view_butt[i]->down_box(TOGGLE_BOX);
	view_butt[i]->selection_color(TOGGLE_COLOR);
	view_butt[i]->callback(set_changed_cb, 0);
      }
      view_value[10] = new Fl_Value_Input(width/2, 2*WB+4*BH, IW, BH, "Angle");
      view_value[10]->minimum(0.); 
      view_value[10]->step(1.); 
      view_value[10]->maximum(180.); 
      view_value[11] = new Fl_Value_Input(width/2, 2*WB+5*BH, IW, BH, "Boundary");
      view_value[11]->minimum(0); 
      view_value[11]->step(1); 
      view_value[11]->maximum(3); 
      view_value[12] = new Fl_Value_Input(width/2, 2*WB+6*BH, IW, BH, "Explode");
      view_value[12]->minimum(0.); 
      view_value[12]->step(0.01); 
      view_value[12]->maximum(1.); 
      for(i=10 ; i<=12 ; i++){
	view_value[i]->align(FL_ALIGN_RIGHT);
	view_value[i]->callback(set_changed_cb, 0);
      }
      
      view_butt[13] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW/2-WB, BH, "Draw points");
      view_butt[14] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW/2-WB, BH, "Draw lines");
      view_butt[15] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW/2-WB, BH, "Draw triangles");
      view_butt[16] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW/2-WB, BH, "Draw tetrahedra");
      view_butt[17] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW/2-WB, BH, "Draw scalar values");
      view_butt[18] = new Fl_Check_Button(2*WB, 2*WB+6*BH, BW/2-WB, BH, "Draw vector values");
      view_butt[19] = new Fl_Check_Button(2*WB, 2*WB+7*BH, BW/2-WB, BH, "Draw tensor values");
      for(i=13 ; i<=19 ; i++){
	view_butt[i]->type(FL_TOGGLE_BUTTON);
	view_butt[i]->down_box(TOGGLE_BOX);
	view_butt[i]->selection_color(TOGGLE_COLOR);
	view_butt[i]->callback(set_changed_cb, 0);
      }
      
      view_3d->end();
    }
    // 2D
    { 
      view_2d = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "2D");
      view_2d->hide();
      
      view_input[2] = new Fl_Input(2*WB, 2*WB+1*BH, IW, BH, "Abscissa name");
      view_input[2]->align(FL_ALIGN_RIGHT);
      view_input[2]->callback(set_changed_cb, 0);
      
      view_value[25] = new Fl_Value_Input(2*WB, 2*WB+ 2*BH, IW, BH, "Abscissa points");
      view_value[25]->minimum(0.); 
      view_value[25]->step(1); 
      view_value[25]->maximum(256); 
      view_value[26] = new Fl_Value_Input(2*WB, 2*WB+ 3*BH, IW, BH, "Grid mode");
      view_value[26]->minimum(0.); 
      view_value[26]->step(1); 
      view_value[26]->maximum(3); 
      for(i=25 ; i<=26 ; i++){
	view_value[i]->align(FL_ALIGN_RIGHT);
	view_value[i]->callback(set_changed_cb, 0);
      }
      
      view_2d->end();
    }
    // Range
    { 
      view_range = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Range");
      view_range->hide();
      
      view_value[30] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Intervals");
      view_value[30]->align(FL_ALIGN_RIGHT);
      view_value[30]->minimum(1); 
      view_value[30]->maximum(256); 
      view_value[30]->step(1);
      view_value[30]->callback(set_changed_cb, 0);
      
      {
	Fl_Group *o2 = new Fl_Group(2*WB, 2*WB+2*BH, width/2, 4*BH, 0);
	view_butt[30] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW/2-WB, BH, "Iso-values");
	view_butt[31] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW/2-WB, BH, "Filled iso-values");
	view_butt[32] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW/2-WB, BH, "Continuous map");
	view_butt[33] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW/2-WB, BH, "Numeric values");
	for(i=30 ; i<=33 ; i++){
	  view_butt[i]->type(FL_RADIO_BUTTON);
	  view_butt[i]->down_box(RADIO_BOX);
	  view_butt[i]->selection_color(RADIO_COLOR);
	  view_butt[i]->callback(set_changed_cb, 0);
	}
	o2->end();
      }
      
      view_butt[34] = new Fl_Check_Button(width/2, 2*WB+1*BH, BW/2-WB, BH, "Custom range");
      view_butt[34]->type(FL_TOGGLE_BUTTON);
      view_butt[34]->down_box(TOGGLE_BOX);
      view_butt[34]->selection_color(TOGGLE_COLOR);
      //no set_changed since customrange has its own callback
      
      view_value[31] = new Fl_Value_Input(width/2, 2*WB+3*BH, IW, BH, "Minimum");
      view_value[32] = new Fl_Value_Input(width/2, 2*WB+4*BH, IW, BH, "Maximum");
      for(i=31 ; i<=32 ; i++){
	view_value[i]->align(FL_ALIGN_RIGHT);
	view_value[i]->callback(set_changed_cb, 0);
      }
      
      {
	Fl_Group *o2 = new Fl_Group(width/2, 2*WB+5*BH, width-4*WB, 3*BH, 0);
	view_butt[35] = new Fl_Check_Button(width/2, 2*WB+5*BH, BW/2-WB, BH, "Linear");
	view_butt[36] = new Fl_Check_Button(width/2, 2*WB+6*BH, BW/2-WB, BH, "Logarithmic");
	view_butt[37] = new Fl_Check_Button(width/2, 2*WB+7*BH, BW/2-WB, BH, "Double logarithmic");
	for(i=35 ; i<=37 ; i++){
	  view_butt[i]->type(FL_RADIO_BUTTON);
	  view_butt[i]->down_box(RADIO_BOX);
	  view_butt[i]->selection_color(RADIO_COLOR);
	  view_butt[i]->callback(set_changed_cb, 0);
	}
	o2->end();
      }
      
      view_butt[38] = new Fl_Check_Button(width/2, 2*WB+2*BH, BW/2-WB, BH, "Saturate values");
      view_butt[38]->type(FL_TOGGLE_BUTTON);
      view_butt[38]->down_box(TOGGLE_BOX);
      view_butt[38]->selection_color(TOGGLE_COLOR);
      view_butt[38]->callback(set_changed_cb, 0);
      
      view_range->end();
    }
    // Offset and Raise
    { 
      Fl_Group *o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Offset");
      o->hide();
      view_value[40] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "X offset");
      view_value[41] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Y offset");
      view_value[42] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Z offset");
      view_value[43] = new Fl_Value_Input(width/2, 2*WB+1*BH, IW, BH, "X raise");
      view_value[44] = new Fl_Value_Input(width/2, 2*WB+2*BH, IW, BH, "Y raise");
      view_value[45] = new Fl_Value_Input(width/2, 2*WB+3*BH, IW, BH, "Z raise");
      for(i=40 ; i<=45 ; i++){
	view_value[i]->align(FL_ALIGN_RIGHT);
	view_value[i]->callback(set_changed_cb, 0);
      }	
      o->end();
    }
    // Aspect
    { 
      Fl_Group *o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Aspect");
      o->hide();
      
      {
	view_vector = new Fl_Group(width/2, WB+BH, width-2*WB, height-3*WB-2*BH, 0);
	{
	  Fl_Group *o = new Fl_Group(width/2, 2*WB+2*BH, width-4*WB, 4*BH, 0);
	  view_butt[60] = new Fl_Check_Button(width/2, 2*WB+2*BH, BW/2-WB, BH, "Line");
	  view_butt[61] = new Fl_Check_Button(width/2, 2*WB+3*BH, BW/2-WB, BH, "Arrow");
	  view_butt[62] = new Fl_Check_Button(width/2, 2*WB+4*BH, BW/2-WB, BH, "Cone");
	  view_butt[63] = new Fl_Check_Button(width/2, 2*WB+5*BH, BW/2-WB, BH, "Displacement");
	  o->end();
	}
	{
	  Fl_Group *o = new Fl_Group(width/2, 2*WB+6*BH, width-4*WB, 2*BH, 0);
	  view_butt[64] = new Fl_Check_Button(width/2, 2*WB+6*BH, BW/2-WB, BH, "Cell centered");
	  view_butt[65] = new Fl_Check_Button(width/2, 2*WB+7*BH, BW/2-WB, BH, "Vertex centered");
	  o->end();
	}
	{
	  Fl_Group *o = new Fl_Group(width/2, 2*WB+8*BH, width-4*WB, 2*BH, 0);
	  view_butt[66] = new Fl_Check_Button(width/2, 2*WB+8*BH, BW/2-WB, BH, "Von-Mises");
	  view_butt[67] = new Fl_Check_Button(width/2, 2*WB+9*BH, BW/2-WB, BH, "Eigenvectors");
	  o->end();
	}
	for(i=60 ; i<=67 ; i++){
	  view_butt[i]->type(FL_RADIO_BUTTON);
	  view_butt[i]->down_box(RADIO_BOX);
	  view_butt[i]->selection_color(RADIO_COLOR);
	  view_butt[i]->callback(set_changed_cb, 0);
	}
	
	view_value[60] = new Fl_Value_Input(width/2, 2*WB+ 1*BH, IW, BH, "Vector size");
	view_value[60]->minimum(0); 
	view_vector->end();
      }
      
      view_value[61] = new Fl_Value_Input(2*WB, 2*WB+ 1*BH, IW, BH, "Point size");
      view_value[61]->minimum(0.1); 
      view_value[61]->maximum(50);
      view_value[61]->step(0.1);
      view_value[62] = new Fl_Value_Input(2*WB, 2*WB+ 2*BH, IW, BH, "Line width");
      view_value[62]->minimum(0.1); 
      view_value[62]->maximum(50);
      view_value[62]->step(0.1);
      for(i=60 ; i<=62 ; i++){
	view_value[i]->align(FL_ALIGN_RIGHT);
	view_value[i]->callback(set_changed_cb, 0);
      }

      o->end();
    }
    // Colors
    { 
      Fl_Group *o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Colors");
      o->hide();
      view_colorbar_window = new Colorbar_Window(2*WB, 2*WB+1*BH,
						 width-4*WB, height-5*WB-2*BH);
      view_colorbar_window->end();
      //no set_changed since colorbarwindow has its own callbacks
      o->end();
    }
    o->end();
  }
  
  { 
    view_ok = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)view_window);
  }
  
  if(CTX.center_windows)
    view_window->position(m_window->x()+m_window->w()/2-width/2,
			  m_window->y()+9*BH-height/2);
  
  view_window->end();
  
}

void GUI::update_view_window(int num){
  int i;
  double val;

  view_number = num ;
  Post_View *v = (Post_View*)List_Pointer(CTX.post.list, num);

  static char buffer[1024];
  sprintf(buffer, "Options for \"%s\" (\"%s\")", v->Name, v->FileName);
  view_window->label(buffer);

  // general
  opt_view_name(num, GMSH_GUI, NULL);
  opt_view_format(num, GMSH_GUI, NULL);
  opt_view_type(num, GMSH_GUI, 0);
  opt_view_show_scale(num, GMSH_GUI, 0);
  opt_view_draw_strings(num, GMSH_GUI, 0);
  opt_view_transparent_scale(num, GMSH_GUI, 0);
  opt_view_auto_position(num, GMSH_GUI, 0);
  if(v->NbSP){
    view_butt[2]->activate();
    view_butt[3]->activate();
  }
  else{
    view_butt[2]->deactivate();
    view_butt[3]->deactivate();
  }
  opt_view_position0(num, GMSH_GUI, 0);
  opt_view_position1(num, GMSH_GUI, 0);
  opt_view_size0(num, GMSH_GUI, 0);
  opt_view_size1(num, GMSH_GUI, 0);

  //3D
  if(v->TextOnly){
    view_3d->deactivate();
    view_range->deactivate();
    view_butt[1]->deactivate();
  }
  else{
    view_3d->activate();
    view_range->activate();
    view_butt[1]->activate();
  }
  opt_view_show_element(num, GMSH_GUI, 0);
  opt_view_light(num, GMSH_GUI, 0);
  opt_view_smooth_normals(num, GMSH_GUI, 0);
  opt_view_angle_smooth_normals(num, GMSH_GUI, 0);
  opt_view_boundary(num, GMSH_GUI, 0);
  opt_view_explode(num, GMSH_GUI, 0);
  opt_view_draw_points(num, GMSH_GUI, 0);
  opt_view_draw_lines(num, GMSH_GUI, 0);
  opt_view_draw_triangles(num, GMSH_GUI, 0);
  opt_view_draw_tetrahedra(num, GMSH_GUI, 0);
  opt_view_draw_scalars(num, GMSH_GUI, 0);
  opt_view_draw_vectors(num, GMSH_GUI, 0);
  opt_view_draw_tensors(num, GMSH_GUI, 0);

  //2D
  if(v->NbSP)
    view_2d->activate();
  else
    view_2d->deactivate();
  opt_view_abscissa_name(num, GMSH_GUI, NULL);
  opt_view_nb_abscissa(num, GMSH_GUI, 0);
  opt_view_grid(num, GMSH_GUI, 0);

  // range
  opt_view_nb_iso(num, GMSH_GUI, 0);
  opt_view_intervals_type(num, GMSH_GUI, 0);
  opt_view_range_type(num, GMSH_GUI, 0);
  view_butt[34]->callback(view_options_custom_cb, (void*)num);
  view_options_custom_cb(0,0);
  view_butt[34]->clear_changed();
  opt_view_custom_min(num, GMSH_GUI, 0);
  opt_view_custom_max(num, GMSH_GUI, 0);
  for(i=31 ; i<=32 ; i++){
    view_value[i]->minimum(v->CustomMin); 
    view_value[i]->maximum(v->CustomMax); 
  }
  opt_view_scale_type(num, GMSH_GUI, 0);
  opt_view_saturate_values(num, GMSH_GUI, 0);

  // offset/raise
  opt_view_offset0(num, GMSH_GUI, 0);
  opt_view_offset1(num, GMSH_GUI, 0);
  opt_view_offset2(num, GMSH_GUI, 0);
  opt_view_raise0(num, GMSH_GUI, 0);
  opt_view_raise1(num, GMSH_GUI, 0);
  opt_view_raise2(num, GMSH_GUI, 0);
  val = 10.*CTX.lc ;
  for(i=40 ; i<=45 ; i++){
    view_value[i]->step(val,1000); 
    view_value[i]->minimum(-val); 
    view_value[i]->maximum(val); 
  }

  // timestep
  if(v->NbTimeStep==1){
    view_value[50]->deactivate();
    view_butt_rep[0]->deactivate();
    view_butt_rep[1]->deactivate();
    view_butt[8]->deactivate();
  }
  else{
    view_value[50]->activate();
    view_butt_rep[0]->activate();
    view_butt_rep[1]->activate();
    view_butt[8]->activate();
  }
  view_value[50]->callback(view_options_timestep_cb, (void*)num);
  view_value[50]->maximum(v->NbTimeStep-1); 
  view_butt_rep[0]->callback(view_options_timestep_decr_cb, (void*)num);
  view_butt_rep[1]->callback(view_options_timestep_incr_cb, (void*)num);
  opt_view_timestep(num, GMSH_GUI, 0);
  opt_view_show_time(num, GMSH_GUI, 0);

  // aspect
  if(v->ScalarOnly) view_vector->deactivate();
  else view_vector->activate();
  opt_view_point_size(num, GMSH_GUI, 0);
  opt_view_line_width(num, GMSH_GUI, 0);
  opt_view_arrow_type(num, GMSH_GUI, 0);
  opt_view_arrow_scale(num, GMSH_GUI, 0);
  opt_view_arrow_location(num, GMSH_GUI, 0);
  opt_view_tensor_type(num, GMSH_GUI, 0);

  // colors
  view_colorbar_window->update(v->Name, v->Min, v->Max, &v->CT, &v->Changed);

  // OK
  view_ok->callback(view_options_ok_cb, (void*)num);
}

//*************** Create the window for geometry context dependant definitions *********

void GUI::create_geometry_context_window(int num){
  static Fl_Group *g[10];
  int i;

  if(context_geometry_window){
    for(i=0 ; i<6 ; i++) g[i]->hide();
    g[num]->show();
    context_geometry_window->show();
    return;
  }

  int width = 31*CTX.fontsize;
  int height = 5*WB+9*BH ;
  
  context_geometry_window = new Fl_Window(width,height);
  context_geometry_window->box(WINDOW_BOX);
  context_geometry_window->label("Contextual geometry definitions");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    // 0: Parameter
    { 
      g[0] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Parameter");
      context_geometry_input[0] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Name");
      context_geometry_input[1] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Value");
      for(i=0 ; i<2 ; i++){
	context_geometry_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "Add");
	o->callback(con_geometry_define_parameter_cb);
      }
      g[0]->end();
    }
    // 1: Point
    { 
      g[1] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Point");
      context_geometry_input[2] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "X coordinate");
      context_geometry_input[3] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Y coordinate");
      context_geometry_input[4] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, "Z coordinate");
      context_geometry_input[5] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, "Characteristic length");
      for(i=2 ; i<6 ; i++){
	context_geometry_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "Add");
	o->callback(con_geometry_define_point_cb);
      }
      g[1]->end();
    }
    // 2: Translation
    { 
      g[2] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Translation");
      context_geometry_input[6] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "X component");
      context_geometry_input[7] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Y component");
      context_geometry_input[8] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, "Z component");
      for(i=6 ; i<9 ; i++){
	context_geometry_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "Set");
	o->callback(con_geometry_define_translation_cb);
      }
      g[2]->end();
    }
    // 3: Rotation
    { 
      g[3] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Rotation");
      context_geometry_input[9]  = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "X coordinate of an axis point");
      context_geometry_input[10] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Y coordinate of an axis point");
      context_geometry_input[11] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, "Z coordinate of an axis point");
      context_geometry_input[12] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, "X component of direction");
      context_geometry_input[13] = new Fl_Input (2*WB, 2*WB+5*BH, IW, BH, "Y component of direction");
      context_geometry_input[14] = new Fl_Input (2*WB, 2*WB+6*BH, IW, BH, "Z component of direction");
      context_geometry_input[15] = new Fl_Input (2*WB, 2*WB+7*BH, IW, BH, "Angle in radians");
      for(i=9 ; i<16 ; i++){
	context_geometry_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "Set");
	o->callback(con_geometry_define_rotation_cb);
      }
      g[3]->end();
    }
    // 4: Scale
    { 
      g[4] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Scale");
      context_geometry_input[16] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "X component of direction");
      context_geometry_input[17] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Y component of direction");
      context_geometry_input[18] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, "Z component of direction");
      context_geometry_input[19] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, "Factor");
      for(i=16 ; i<20 ; i++){
	context_geometry_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "Set");
	o->callback(con_geometry_define_scale_cb);
      }
      g[4]->end();
    }
    // 5: Symmetry
    { 
      g[5] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Symmetry");
      context_geometry_input[20] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "1st plane equation coefficient");
      context_geometry_input[21] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "2nd plane equation coefficient");
      context_geometry_input[22] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, "3rd plane equation coefficient");
      context_geometry_input[23] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, "4th plane equation coefficient");
      for(i=20 ; i<24 ; i++){
	context_geometry_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "Set");
	o->callback(con_geometry_define_symmetry_cb);
      }
      g[5]->end();
    }
    o->end();
  }
  
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)context_geometry_window);
  }
  
  for(i=0 ; i<6 ; i++) g[i]->hide();
  g[num]->show();
  
  if(CTX.center_windows)
    context_geometry_window->position(m_window->x()+m_window->w()/2-width/2,
				      m_window->y()+9*BH-height/2);
  context_geometry_window->end();
  context_geometry_window->show();
  
}

//************** Create the window for mesh context dependant definitions **************

void GUI::create_mesh_context_window(int num){
  static Fl_Group *g[10];
  int i;

  if(context_mesh_window){
    for(i=0 ; i<3 ; i++) g[i]->hide();
    g[num]->show();
    context_mesh_window->show();
    return;
  }

  int width = 31*CTX.fontsize;
  int height = 5*WB+5*BH ;
  
  context_mesh_window = new Fl_Window(width,height);
  context_mesh_window->box(WINDOW_BOX);
  context_mesh_window->label("Contextual mesh definitions");
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
    // 0: Characteristic length
    { 
      g[0] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Characteristic length");
      context_mesh_input[0] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Value");
      context_mesh_input[0]->align(FL_ALIGN_RIGHT);
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+3*BH, BB, BH, "Set");
	o->callback(con_mesh_define_length_cb);
      }
      g[0]->end();
    }
    // 1: Transfinite line
    { 
      g[1] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Transfinite line");
      context_mesh_input[1] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Number of points");
      context_mesh_input[2] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Distribution");
      for(i=1 ; i<3 ; i++){
	context_mesh_input[i]->align(FL_ALIGN_RIGHT);
      }
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+3*BH, BB, BH, "Set");
	o->callback(con_mesh_define_transfinite_line_cb);
      }
      g[1]->end();
    }
    // 2: Transfinite volume
    { 
      g[2] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Transfinite volume");
      context_mesh_input[3] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Volume number");
      context_mesh_input[3]->align(FL_ALIGN_RIGHT);
      { 
	Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+3*BH, BB, BH, "Set");
	o->callback(con_mesh_define_transfinite_line_cb);
      }
      g[2]->end();
    }
    o->end();
  }
  
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)context_mesh_window);
  }
  
  for(i=0 ; i<3 ; i++) g[i]->hide();
  g[num]->show();
  
  if(CTX.center_windows)
    context_mesh_window->position(m_window->x()+m_window->w()/2-width/2,
				  m_window->y()+9*BH-height/2);
  context_mesh_window->end();
  context_mesh_window->show();
}


//************** Create the windows for the solvers **************

#include "Solvers.h"

void GUI::create_solver_window(int num){
  int i, nbbutts=0, newrow=0;
  static Fl_Group *g[10];

  int LL = (int)(1.75*IW);

  if(solver[num].window){
    solver[num].window->show();
    return;
  }

  for(i=0; i<5; i++)
    if(strlen(SINFO[num].option_name[i])) SINFO[num].nboptions = i+1;

  for(i=0; i<5; i++)
    if(strlen(SINFO[num].button_name[i])) nbbutts++ ;
  if(nbbutts > 3) newrow = 1;

  int width = 5*BB+6*WB;
  int height = (8+SINFO[num].nboptions+newrow)*WB+ (6+SINFO[num].nboptions+newrow)*BH  ;
  if(height < 7*WB+7*BH) height = 7*WB+7*BH; //minimum height required by Options tab
  
  solver[num].window = new Fl_Window(width,height);
  solver[num].window->box(WINDOW_BOX);
  { 
    Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-(3+newrow)*WB-(1+newrow)*BH);
    { 
      g[0] = new Fl_Group(WB, WB+BH, width-2*WB, height-(3+newrow)*WB-(2+newrow)*BH, "General");
      
      solver[num].input[0] = new Fl_Input(2*WB, 2*WB+1*BH, LL, BH, "Problem");
      Fl_Button *b1 = new Fl_Button(2*WB, 3*WB+2*BH, BB, BH, "Choose");
      b1->callback(solver_file_open_cb, (void*)num);
      Fl_Button *b2 = new Fl_Button(3*WB+BB, 3*WB+2*BH, BB, BH, "Edit");
      b2->callback(solver_file_edit_cb, (void*)num);

      solver[num].input[1] = new Fl_Input(2*WB, 4*WB+3*BH, LL, BH, "Mesh");
      Fl_Button *b3 = new Fl_Button(2*WB, 5*WB+4*BH, BB, BH, "Choose");
      b3->callback(solver_choose_mesh_cb, (void*)num);

      for(i=0 ; i<2 ; i++){
	solver[num].input[i]->align(FL_ALIGN_RIGHT);
      }

      for(i=0; i<SINFO[num].nboptions; i++){
	solver[num].choice[i] = new Fl_Choice(2*WB, (6+i)*WB+(5+i)*BH, LL, BH,
					      SINFO[num].option_name[i]);
	solver[num].choice[i]->align(FL_ALIGN_RIGHT);
      }

      g[0]->end();
    }
    { 
      g[1] = new Fl_Group(WB, WB+BH, width-2*WB, height-(3+newrow)*WB-(2+newrow)*BH, "Options");
      
      solver[num].input[2] = new Fl_Input(2*WB, 2*WB+1*BH, LL, BH, "Executable");
      solver[num].input[2]->align(FL_ALIGN_RIGHT);
      Fl_Button *b = new Fl_Button(2*WB, 3*WB+2*BH, BB, BH, "Choose");
      b->callback(solver_choose_executable_cb, (void*)num);
      
      solver[num].butt[2] = new Fl_Check_Button(2*WB, 4*WB+3*BH, LL, BH, 
						"Client/server connection");
      solver[num].butt[0] = new Fl_Check_Button(2*WB, 4*WB+4*BH, LL, BH, 
						"Automatic message display");
      solver[num].butt[1] = new Fl_Check_Button(2*WB, 4*WB+5*BH, LL, BH, 
						"Automatic view merge");
      for(i=0 ; i<3 ; i++){
	solver[num].butt[i]->type(FL_TOGGLE_BUTTON);
	solver[num].butt[i]->down_box(TOGGLE_BOX);
	solver[num].butt[i]->selection_color(TOGGLE_COLOR);
      }
      
      Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 
						 height-(3+newrow)*WB-(2+newrow)*BH, BB, BH, "OK");
      o->callback(solver_ok_cb, (void*)num);
      
      g[1]->end();
    }
    { 
      g[2] = new Fl_Group(WB, WB+BH, width-2*WB, height-(3+newrow)*WB-(2+newrow)*BH, "About");
      
      Fl_Browser *o = new Fl_Browser(2*WB, 2*WB+1*BH, width-4*WB,
				     height-(5+newrow)*WB-(2+newrow)*BH);
      o->add("");
      add_multiline_in_browser(o, "@c@b@.", SINFO[num].name);
      o->add("");
      add_multiline_in_browser(o, "@c@. ", SINFO[num].help);
      
      g[2]->end();
    }
    o->end();
  }

  static int arg[5][5][2];
  int nb=0;
  for(i=4; i>=0; i--){
    if(strlen(SINFO[num].button_name[i])){
      arg[num][i][0]=num;
      arg[num][i][1]=i;
      solver[num].command[nb] = new Fl_Button(width-(1+nb+2*!newrow)*BB-(1+nb+2*!newrow)*WB, 
					      height-(1+newrow)*BH-(1+newrow)*WB, 
					      BB, BH,
					      SINFO[num].button_name[i]);
      solver[num].command[nb]->callback(solver_command_cb,(void*)arg[num][i]);
      nb++;
    }
  }
  
  { 
    Fl_Button* o = new Fl_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "Kill");
    o->callback(solver_kill_cb, (void*)num);
  }
  { 
    Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "Cancel");
    o->callback(cancel_cb, (void*)solver[num].window);
  }
  
  
  if(CTX.center_windows)
    solver[num].window->position(m_window->x()+m_window->w()/2-width/2,
				 m_window->y()+9*BH-height/2);
  solver[num].window->end();
}



