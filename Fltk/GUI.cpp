// $Id: GUI.cpp,v 1.30 2001-01-29 08:43:44 geuzaine Exp $

// To make the interface as visually consistent as possible, please:
// - use the BH, BW, WB, IW values for button heights/widths, window borders, etc.
// - use CTX.fontsize for font sizes
// - examine what's already done before adding something new...

#include "Gmsh.h"
#include "GmshUI.h"
#include "GmshVersion.h"
#include "Context.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Bitmaps.h"
#include "GetOptions.h"

extern Context_T  CTX;

//******************* Definition of the static menus ***********************************

Fl_Menu_Item m_menubar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"Open...",          FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"Merge...",         FL_CTRL+'m', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"Save",             FL_CTRL+'s', (Fl_Callback *)file_save_cb, 0},
    {"Save As",          0, 0, 0, FL_MENU_DIVIDER|FL_SUBMENU},
      {"By extension...",      FL_CTRL+'p', (Fl_Callback *)file_save_as_auto_cb, 0},
      {"GEO...",               0, (Fl_Callback *)file_save_as_geo_cb, 0},
      {"GEO options...",       0, (Fl_Callback *)file_save_as_geo_options_cb, 0},
      {"MSH...",               0, (Fl_Callback *)file_save_as_msh_cb, 0},
      {"UNV...",               0, (Fl_Callback *)file_save_as_unv_cb, 0},
      {"GREF...",              0, (Fl_Callback *)file_save_as_gref_cb, 0},
      {"EPS simple sort...",   0, (Fl_Callback *)file_save_as_eps_simple_cb, 0},
      {"EPS accurate sort...", 0, (Fl_Callback *)file_save_as_eps_accurate_cb, 0},
      {"JPEG...",              0, (Fl_Callback *)file_save_as_jpeg_cb, 0},
      {"GIF...",               0, (Fl_Callback *)file_save_as_gif_cb, 0},
      {"GIF dithered...",      0, (Fl_Callback *)file_save_as_gif_dithered_cb, 0},
      {"GIF transparent...",   0, (Fl_Callback *)file_save_as_gif_transparent_cb, 0},
      {"PPM...",               0, (Fl_Callback *)file_save_as_ppm_cb, 0},
      {"UCB YUV...",           0, (Fl_Callback *)file_save_as_yuv_cb, 0},
      {0},
    {"Reload All Views", FL_CTRL+'l', (Fl_Callback *)file_reload_all_views_cb, 0},
    {"Remove All Views", FL_CTRL+'r', (Fl_Callback *)file_remove_all_views_cb, 0, FL_MENU_DIVIDER},
    {"Quit",             FL_CTRL+'q', (Fl_Callback *)file_quit_cb, 0},
    {0},
  {"Options",0,0,0,FL_SUBMENU},
    {"General...",         FL_SHIFT+'o', (Fl_Callback *)opt_general_cb, 0},
    {"Geometry...",        FL_SHIFT+'g', (Fl_Callback *)opt_geometry_cb, 0},
    {"Mesh...",            FL_SHIFT+'m', (Fl_Callback *)opt_mesh_cb, 0},
    {"Post-Processing...", FL_SHIFT+'p', (Fl_Callback *)opt_post_cb, 0, FL_MENU_DIVIDER},
    {"Statistics...",      FL_SHIFT+'i', (Fl_Callback *)opt_statistics_cb, 0},
    {"Message log...",     FL_SHIFT+'l', (Fl_Callback *)opt_message_cb, 0},
    {0},
  {"Help",0,0,0,FL_SUBMENU},
    {"Short Help...",   0, (Fl_Callback *)help_short_cb, 0, FL_MENU_DIVIDER},
    {"About...",        0, (Fl_Callback *)help_about_cb, 0},
    {0},
  {0}
};

Fl_Menu_Item m_module_table[] = {
  {"Geometry",        'g', (Fl_Callback *)mod_geometry_cb, 0},
  {"Mesh",            'm', (Fl_Callback *)mod_mesh_cb, 0},
  {"Post-Processing", 'p', (Fl_Callback *)mod_post_cb, 0},
  {0}
};

//********************* Definition of the dynamic contexts *****************************

Context_Item menu_geometry[] = 
{ { "0", NULL } ,
  { "Elementary", (Fl_Callback *)geometry_elementary_cb } ,
  { "Physical",   (Fl_Callback *)geometry_physical_cb } ,
  { "Reload",     (Fl_Callback *)geometry_reload_cb } , 
  { NULL }
};  
    Context_Item menu_geometry_elementary[] = 
    { { "0Elementary", NULL } ,
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
	{ { "0Elementary Add", NULL } ,
          { "New",       (Fl_Callback *)geometry_elementary_add_new_cb } ,
	  { "Translate", (Fl_Callback *)geometry_elementary_add_translate_cb } ,
	  { "Rotate",    (Fl_Callback *)geometry_elementary_add_rotate_cb } ,
	  { "Scale",     (Fl_Callback *)geometry_elementary_add_scale_cb } ,
	  { "Symmetry",  (Fl_Callback *)geometry_elementary_add_symmetry_cb } ,
	  { NULL } 
	};  
            Context_Item menu_geometry_elementary_add_new[] = 
	    { { "0Elementary Add New", NULL } ,
              { "Parameter",     (Fl_Callback *)geometry_elementary_add_new_parameter_cb } ,
	      { "Point",         (Fl_Callback *)geometry_elementary_add_new_point_cb } ,
	      { "Line",          (Fl_Callback *)geometry_elementary_add_new_line_cb } ,
	      { "Spline",        (Fl_Callback *)geometry_elementary_add_new_spline_cb } ,
	      { "Circle",        (Fl_Callback *)geometry_elementary_add_new_circle_cb } ,
	      { "Ellipsis",      (Fl_Callback *)geometry_elementary_add_new_ellipsis_cb } ,
	      { "Plane Surface", (Fl_Callback *)geometry_elementary_add_new_planesurface_cb } ,
	      { "Ruled Surface", (Fl_Callback *)geometry_elementary_add_new_ruledsurface_cb } ,
	      { "Volume",        (Fl_Callback *)geometry_elementary_add_new_volume_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_translate[] = 
	    { { "0Elementary Add Translate", NULL } ,
              { "Point",   (Fl_Callback *)geometry_elementary_add_translate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_translate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_translate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_rotate[] = 
	    { { "0Elementary Add Rotate", NULL } ,
              { "Point",   (Fl_Callback *)geometry_elementary_add_rotate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_rotate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_rotate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_scale[] = 
	    { { "0Elementary Add Scale", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_add_scale_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_scale_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_scale_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_symmetry[] = 
	    { { "0Elementary Add Symmetry", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_add_symmetry_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_symmetry_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_symmetry_surface_cb } ,
	      { NULL } 
	    };  
        Context_Item menu_geometry_elementary_translate[] = 
	{ { "0Elementary Translate", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_translate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_translate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_translate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_rotate[] = 
	{ { "0Elementary Rotate", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_rotate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_rotate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_rotate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_scale[] = 
	{ { "0Elementary Scale", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_scale_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_scale_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_scale_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_symmetry[] = 
	{ { "0Elementary Symmetry", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_symmetry_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_symmetry_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_symmetry_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_extrude[] = 
	{ { "0Elementary Extrude", NULL } ,
	  { "Translate",   (Fl_Callback *)geometry_elementary_extrude_translate_cb } ,
	  { "Rotate",   (Fl_Callback *)geometry_elementary_extrude_rotate_cb } ,
	  { NULL } 
 	};  
            Context_Item menu_geometry_elementary_extrude_translate[] = 
	    { { "0Elementary Extrude Translate", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_extrude_translate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_extrude_translate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_extrude_translate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_extrude_rotate[] = 
	    { { "0Elementary Extrude Rotate", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_extrude_rotate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_extrude_rotate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_extrude_rotate_surface_cb } ,
	      { NULL } 
	    };  
        Context_Item menu_geometry_elementary_delete[] = 
	{ { "0Elementary Delete", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_delete_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_delete_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_delete_surface_cb } ,
	  { NULL } 
	};  
    Context_Item menu_geometry_physical[] = 
    { { "0Physical", NULL } ,
      { "Add",    (Fl_Callback *)geometry_physical_add_cb } ,
      { NULL } 
    };  
        Context_Item menu_geometry_physical_add[] = 
	{ { "0Physical Add", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_physical_add_point_cb  } ,
	  { "Curve",   (Fl_Callback *)geometry_physical_add_curve_cb  } ,
	  { "Surface", (Fl_Callback *)geometry_physical_add_surface_cb  } ,
	  { "Volume",  (Fl_Callback *)geometry_physical_add_volume_cb  } ,
	  { NULL } 
	};  

Context_Item menu_mesh[] = 
{ { "1", NULL } ,
  { "Define", (Fl_Callback *)mesh_define_cb } ,
  { "1D",     (Fl_Callback *)mesh_1d_cb } ,
  { "2D",     (Fl_Callback *)mesh_2d_cb } , 
  { "3D",     (Fl_Callback *)mesh_3d_cb } , 
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

Context_Item menu_post[] = 
{ { "2", NULL } ,
  { NULL } };

//********************** Definition of global shortcuts ********************************

int GUI::global_shortcuts(int event){
  // we only handle shortcuts here
  if(event != FL_SHORTCUT) return 0 ;

  // test...
  if(Fl::test_shortcut('e')){
    end_selection = 1;
    return 1;
  }
  else if(Fl::test_shortcut('q')){
    quit_selection = 1;
    return 1;
  }
  else if(Fl::test_shortcut('1')){
    mesh_1d_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('2')){
    mesh_2d_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut('3')){
    mesh_3d_cb(0,0);
    return 1;
  }
  else if(Fl::test_shortcut(FL_CTRL+'z')){
    g_window->iconize();
    return 1;
  }
  else if(Fl::test_shortcut(FL_Escape)){
    return 1;
  }

  return 0;
}


//***************************** The GUI constructor ************************************

GUI::GUI(int argc, char **argv) {

  IW = 10*CTX.fontsize; // input field width
  BW = 3*IW/2; // width of a button with external label
  BB = 5*CTX.fontsize; // width of a button with internal label
  BH = 2*CTX.fontsize+2; // button height
  WB = CTX.fontsize-6; // window border


  if(strlen(CTX.display)) Fl::display(CTX.display);

  Fl::add_handler(SetGlobalShortcut);

  // Icons

  icon1_bmp = new Fl_Bitmap(g1_bits,g1_width,g1_height);
  icon2_bmp = new Fl_Bitmap(g2_bits,g2_width,g2_height);
  icon3_bmp = new Fl_Bitmap(g3_bits,g3_width,g3_height);

  // All static windows are contructed (even if some are not
  // displayed) since the shortcuts should be valid even for hidden
  // windows

  create_menu_window(argc, argv);
  create_graphic_window(argc, argv);

#ifndef WIN32
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
  create_post_options_window();
  create_message_window();
  create_help_window();
  create_about_window();

  // Draw the scene

  g_opengl_window->redraw();

}

// Run the GUI until no window is left

void GUI::run(){
  Fl::run();
}

// Check if any pending events and run them

void GUI::check(){
  Fl::check();
}

//********************************* Create the menu window *****************************

void GUI::create_menu_window(int argc, char **argv){
  static int init_menu_window = 0;
  int i, y;

  if(!init_menu_window){
    init_menu_window = 1 ;

    int width = 13*CTX.fontsize ;
    MH = 2*BH+6 ; // this is the initial height: no dynamic button is shown!

    m_window = new Fl_Window(width,MH);
    m_window->box(FL_THIN_UP_BOX);
    m_window->label("Gmsh");

    m_menu_bar = new Fl_Menu_Bar(0,0,width,BH); 
    m_menu_bar->menu(m_menubar_table);
    m_menu_bar->textsize(CTX.fontsize);
    m_menu_bar->box(FL_UP_BOX);
    m_menu_bar->global();

    Fl_Box *o = new Fl_Box(0,BH,width,BH+6);
    o->box(FL_UP_BOX);

    y = BH + 3;
    
    m_navig_butt[0] = new Fl_Button(2,y,20,BH/2,"@<");
    m_navig_butt[0]->labeltype(FL_SYMBOL_LABEL);
    m_navig_butt[0]->box(FL_FLAT_BOX);
    m_navig_butt[0]->selection_color(FL_WHITE);
    m_navig_butt[0]->callback(mod_back_cb);
    m_navig_butt[1] = new Fl_Button(2,y+BH/2,20,BH/2,"@>");
    m_navig_butt[1]->labeltype(FL_SYMBOL_LABEL);
    m_navig_butt[1]->box(FL_FLAT_BOX);
    m_navig_butt[1]->selection_color(FL_WHITE);
    m_navig_butt[1]->callback(mod_forward_cb);
    
    m_module_butt = new Fl_Choice(22,y,width-28,BH);
    m_module_butt->menu(m_module_table);
    m_module_butt->textsize(CTX.fontsize);
    m_module_butt->box(FL_THIN_DOWN_BOX);
    
    y = MH ;
    
    for(i=0; i<NB_BUTT_MAX; i++){
      m_push_butt[i] = new Fl_Button(0,y+i*BH,width,BH); 
      m_push_butt[i]->labelsize(CTX.fontsize);
      m_push_butt[i]->hide();
      m_toggle_butt[i] = new Fl_Light_Button(0,y+i*BH,width,BH); 
      m_toggle_butt[i]->labelsize(CTX.fontsize); 
      m_toggle_butt[i]->callback(view_toggle_cb, (void*)i);
      m_toggle_butt[i]->hide();
      m_popup_butt[i] = new Fl_Menu_Button(0,y+i*BH,width,BH);
      m_popup_butt[i]->type(Fl_Menu_Button::POPUP3);
      m_popup_butt[i]->add("Reload", 0, 
			   (Fl_Callback *)view_reload_cb, (void*)i, 0);
      m_popup_butt[i]->add("Remove", 0, 
			   (Fl_Callback *)view_remove_cb, (void*)i, 0);
      m_popup_butt[i]->add("Duplicate", 0,
			   (Fl_Callback *)view_duplicate_cb, (void*)i, FL_MENU_DIVIDER) ;
      m_popup_butt[i]->add("Lighting", 0,
			   (Fl_Callback *)view_lighting_cb, (void*)i, 0);
      m_popup_butt[i]->add("Show Elements", 0,
			   (Fl_Callback *)view_elements_cb, (void*)i, 0);
      m_popup_butt[i]->add("Apply as Background Mesh", 0,
			   (Fl_Callback *)view_applybgmesh_cb, (void*)i, FL_MENU_DIVIDER);
      m_popup_butt[i]->add("Options...", 0,
			   (Fl_Callback *)view_options_cb, (void*)i, 0);
      m_popup_butt[i]->textsize(CTX.fontsize);
      m_popup_butt[i]->hide();
    }
    
    m_window->position(CTX.position[0],CTX.position[1]);
    m_window->end();
  }
  else{
    if(m_window->shown())
      m_window->redraw();
    else
      m_window->show(1, argv);
    
  }

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
  else {
    Msg(WARNING, "Something Wrong in your Dynamic Context Definition");
    return;
  }

  if(m_module_butt->value() == 2){ // post-processing contexts
    for(i = 0 ; i < List_Nbr(Post_ViewList) ; i++) {
      if(i == NB_BUTT_MAX) break;
      nb++ ;
      v = (Post_View*)List_Pointer(Post_ViewList,i);
      m_push_butt[i]->hide();
      m_toggle_butt[i]->show();
      m_toggle_butt[i]->value(v->Visible);
      m_toggle_butt[i]->label(v->Name);
      m_popup_butt[i]->show();
    }
    for(i = List_Nbr(Post_ViewList) ; i < NB_BUTT_MAX ; i++) {
      m_push_butt[i]->hide();
      m_toggle_butt[i]->hide();
      m_popup_butt[i]->hide();
    }
  }
  else{ // geometry and mesh contexts
    Msg(STATUS2, menu[0].label+1);
    for(i=0 ; i < NB_BUTT_MAX ; i++){
      m_toggle_butt[i]->hide();
      m_popup_butt[i]->hide();
      if(menu[i+1].label){
	m_push_butt[i]->label(menu[i+1].label);
	m_push_butt[i]->callback(menu[i+1].callback);
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
  }

  set_menu_size(nb);

}

int GUI::get_context(){
  return m_module_butt->value();
}


//******************************** Create the graphic window ***************************

void GUI::create_graphic_window(int argc, char **argv){
  static int init_graphic_window = 0;
  int i, x;

  if(!init_graphic_window){
    init_graphic_window = 1 ;

    int sh = 2*CTX.fontsize-4; // status bar height
    int sw = CTX.fontsize+4; //status button width
    int width = CTX.viewport[2]-CTX.viewport[0];
    int glheight = CTX.viewport[3]-CTX.viewport[1];
    int height = glheight + sh;


    g_window = new Fl_Window(width, height);
    g_opengl_window = new Opengl_Window(0,0,width,glheight);
    g_opengl_window->end();

    {
      Fl_Group *o = new Fl_Group(0,glheight,width,sh);
      o->box(FL_THIN_UP_BOX);

      x = 2;
      
      g_status_butt[0] = new Fl_Button(x,glheight+2,sw,sh-4,"X"); x+=sw;
      g_status_butt[0]->callback(status_xyz1p_cb, (void*)0);
      //g_status_butt[0]->tooltip("Set X view");
      g_status_butt[1] = new Fl_Button(x,glheight+2,sw,sh-4,"Y"); x+=sw;
      g_status_butt[1]->callback(status_xyz1p_cb, (void*)1);
      g_status_butt[2] = new Fl_Button(x,glheight+2,sw,sh-4,"Z"); x+=sw;
      g_status_butt[2]->callback(status_xyz1p_cb, (void*)2);
      g_status_butt[3] = new Fl_Button(x,glheight+2,2*CTX.fontsize,sh-4,"1:1"); x+=2*CTX.fontsize;
      g_status_butt[3]->callback(status_xyz1p_cb, (void*)3);
      g_status_butt[4] = new Fl_Button(x,glheight+2,sw,sh-4,"?"); x+=sw;
      g_status_butt[4]->callback(status_xyz1p_cb, (void*)4);

      g_status_butt[5] = new Fl_Button(x,glheight+2,sw,sh-4); x+=sw;
      g_status_butt[5]->callback(status_play_cb);
      start_bmp = new Fl_Bitmap(start_bits,start_width,start_height);
      start_bmp->label(g_status_butt[5]);
      stop_bmp = new Fl_Bitmap(stop_bits,stop_width,stop_height);

      g_status_butt[6] = new Fl_Button(x,glheight+2,sw,sh-4); x+=sw;
      g_status_butt[6]->callback(status_cancel_cb);
      abort_bmp = new Fl_Bitmap(abort_bits,abort_width,abort_height);
      abort_bmp->label(g_status_butt[6]);
      g_status_butt[6]->deactivate();

      for(i = 0 ; i<7 ; i++){
	g_status_butt[i]->box(FL_FLAT_BOX);
	g_status_butt[i]->selection_color(FL_WHITE);
	g_status_butt[i]->labelsize(CTX.fontsize);
	g_status_butt[i]->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
      }

      g_status_label[0] = new Fl_Box(x,glheight+2,(width-x)/3,sh-4);
      g_status_label[1] = new Fl_Box(x+(width-x)/3,glheight+2,(height-x)/3,sh-4);
      g_status_label[2] = new Fl_Box(x+2*(width-x)/3,glheight+2,(height-x)/3-2,sh-4);
      for(i = 0 ; i<3 ; i++){
	g_status_label[i]->box(FL_FLAT_BOX);
	g_status_label[i]->labelsize(CTX.fontsize);
	g_status_label[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
      }
      
      o->end();
    }

    g_window->resizable(g_opengl_window);
    g_window->position(CTX.gl_position[0],CTX.gl_position[1]);
    g_window->end();   
  }
  else{
    if(g_window->shown())
      g_window->redraw();
    else
      g_window->show(1, argv);
    
  }
}

// Set the size of the graphical window

void GUI::set_size(int new_w, int new_h){
  g_window->size(new_w,new_h+g_window->h()-g_opengl_window->h());
}

// Get the position of the 2 main windows

void GUI::get_position(int m[2], int g[2]){
  m[0] = m_window->x();
  m[1] = m_window->y();
  g[0] = g_window->x();
  g[1] = g_window->y();
}

// Set graphic window title

void GUI::set_title(char *str){
  g_window->label(str);
}

// Set animation button

void GUI::set_anim(int mode){
  if(mode){
    g_status_butt[5]->callback(status_play_cb);
    start_bmp->label(g_status_butt[5]);
  }
  else{
    g_status_butt[5]->callback(status_pause_cb);
    stop_bmp->label(g_status_butt[5]);
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

void GUI::make_colorbar_current(){
  view_colorbar_window->make_current();
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
  static int init_general_options_window = 0;
  int i;

  if(!init_general_options_window){
    init_general_options_window = 1 ;

    int width = 25*CTX.fontsize;
    int height = 5*WB+8*BH ;
    
    gen_window = new Fl_Window(width,height);
    gen_window->box(FL_THIN_UP_BOX);
    gen_window->label("General Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Display");
	o->labelsize(CTX.fontsize);
        gen_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Show moving axes");
	gen_butt[0]->callback(opt_general_moving_axes_cb);
	gen_butt[0]->value(CTX.axes);
        gen_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Show small axes");
	gen_butt[1]->callback(opt_general_small_axes_cb);
	gen_butt[1]->value(CTX.small_axes);
        gen_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Enable fast redraw");
	gen_butt[2]->callback(opt_general_fast_redraw_cb);
	gen_butt[2]->value(CTX.fast);
        gen_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW, BH, "Use display lists");
	gen_butt[3]->callback(opt_general_display_lists_cb);
	gen_butt[3]->value(CTX.display_lists);
        gen_butt[4] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW, BH, "Enable alpha blending");
	gen_butt[4]->callback(opt_general_alpha_blending_cb);
	gen_butt[4]->value(CTX.alpha);
        gen_butt[5] = new Fl_Check_Button(2*WB, 2*WB+6*BH, BW, BH, "Use trackball rotation mode");
	gen_butt[5]->callback(opt_general_trackball_cb);
	gen_butt[5]->value(CTX.useTrackball);
	for(i=0 ; i<6 ; i++){
	  gen_butt[i]->type(FL_TOGGLE_BUTTON);
	  gen_butt[i]->down_box(FL_DOWN_BOX);
	  gen_butt[i]->labelsize(CTX.fontsize);
	  gen_butt[i]->selection_color(FL_YELLOW);
	}
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Projection");
	o->labelsize(CTX.fontsize);
        o->hide();
        gen_butt[6] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Orthographic");
	gen_butt[6]->callback(opt_general_orthographic_cb, (void*)1);
	gen_butt[6]->value(CTX.ortho);
        gen_butt[7] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Perspective");
	gen_butt[7]->callback(opt_general_orthographic_cb, (void*)0);
	gen_butt[7]->value(!CTX.ortho);
	for(i=6 ; i<8 ; i++){
	  gen_butt[i]->type(FL_RADIO_BUTTON);
	  gen_butt[i]->labelsize(CTX.fontsize);
	  gen_butt[i]->selection_color(FL_YELLOW);
	}
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Light and color");
	o->labelsize(CTX.fontsize);
        o->hide();
        gen_value[0] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Predefined color scheme");
	gen_value[0]->minimum(1); 
	gen_value[0]->maximum(3); 
	gen_value[0]->step(1);
	gen_value[0]->value(0);
	gen_value[0]->callback(opt_general_color_cb);
	gen_value[1] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Material shininess");
	gen_value[1]->minimum(0); 
	gen_value[1]->maximum(10);
	gen_value[1]->step(0.1);
	gen_value[1]->value(CTX.shine);
	gen_value[1]->callback(opt_general_shininess_cb);
        gen_value[2] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Light position X");
	gen_value[2]->minimum(-1); 
	gen_value[2]->maximum(1);
	gen_value[2]->step(0.01);
	gen_value[2]->value(CTX.light_position[0][0]);
	gen_value[2]->callback(opt_general_light_cb, (void*)0);
        gen_value[3] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Light position Y");
	gen_value[3]->minimum(-1); 
	gen_value[3]->maximum(1); 
	gen_value[3]->step(0.01);
	gen_value[3]->value(CTX.light_position[0][1]);
	gen_value[3]->callback(opt_general_light_cb, (void*)1);
        gen_value[4] = new Fl_Value_Input(2*WB, 2*WB+5*BH, IW, BH, "Light position Z");
	gen_value[4]->minimum(-1); 
	gen_value[4]->maximum(1); 
	gen_value[4]->step(0.01);
	gen_value[4]->value(CTX.light_position[0][2]);
	gen_value[4]->callback(opt_general_light_cb, (void*)2);
	for(i=0 ; i<5 ; i++){
	  gen_value[i]->labelsize(CTX.fontsize);
	  gen_value[i]->type(FL_HORIZONTAL);
	  gen_value[i]->align(FL_ALIGN_RIGHT);
	}
        o->end();
      }
      o->end();

    }

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)gen_window);
    }

    if(CTX.center_windows)
      gen_window->position(m_window->x()+m_window->w()/2-width/2,
			   m_window->y()+2*MH);
    gen_window->end();
  }
  else{
    if(gen_window->shown())
      gen_window->redraw();
    else
      gen_window->show();
    
  }

}

//************************ Create the window for geometry options **********************

void GUI::create_geometry_options_window(){
  static int init_geometry_options_window = 0;
  int i;

  if(!init_geometry_options_window){
    init_geometry_options_window = 1 ;

    int width = 24*CTX.fontsize;
    int height = 5*WB+9*BH ;
    
    geo_window = new Fl_Window(width,height);
    geo_window->box(FL_THIN_UP_BOX);
    geo_window->label("Geometry Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Visibility");
	o->labelsize(CTX.fontsize);
        geo_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, IW, BH, "Points");
	geo_butt[0]->callback(opt_geometry_entity_cb, (void*)0);
	geo_butt[0]->value(CTX.geom.points);
        geo_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, IW, BH, "Curves");
	geo_butt[1]->callback(opt_geometry_entity_cb, (void*)1);
	geo_butt[1]->value(CTX.geom.lines);
        geo_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, IW, BH, "Surfaces");
	geo_butt[2]->callback(opt_geometry_entity_cb, (void*)2);
	geo_butt[2]->value(CTX.geom.surfaces);
        geo_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, IW, BH, "Volumes");
	geo_butt[3]->callback(opt_geometry_entity_cb, (void*)3);
	geo_butt[3]->value(CTX.geom.volumes);
        geo_butt[4] = new Fl_Check_Button(width/2, 2*WB+1*BH, IW, BH, "Point numbers");
	geo_butt[4]->callback(opt_geometry_num_cb, (void*)0);
	geo_butt[4]->value(CTX.geom.points_num);
        geo_butt[5] = new Fl_Check_Button(width/2, 2*WB+2*BH, IW, BH, "Curve numbers");
	geo_butt[5]->callback(opt_geometry_num_cb, (void*)1);
	geo_butt[5]->value(CTX.geom.lines_num);
        geo_butt[6] = new Fl_Check_Button(width/2, 2*WB+3*BH, IW, BH, "Surface numbers");
	geo_butt[6]->callback(opt_geometry_num_cb, (void*)2);
	geo_butt[6]->value(CTX.geom.surfaces_num);
        geo_butt[7] = new Fl_Check_Button(width/2, 2*WB+4*BH, IW, BH, "Volume numbers");
	geo_butt[7]->callback(opt_geometry_num_cb, (void*)3);
	geo_butt[7]->value(CTX.geom.volumes_num);
	for(i=0 ; i<8 ; i++){
	  geo_butt[i]->type(FL_TOGGLE_BUTTON);
	  geo_butt[i]->down_box(FL_DOWN_BOX);
	  geo_butt[i]->labelsize(CTX.fontsize);
	  geo_butt[i]->selection_color(FL_YELLOW);
	}
        geo_input = new Fl_Input(2*WB, 2*WB+5*BH, IW, BH, "Show by entity number");
	geo_input->callback(opt_geometry_show_by_entity_num_cb);
	geo_input->labelsize(CTX.fontsize);
	geo_input->align(FL_ALIGN_RIGHT);

	geo_value[0] = new Fl_Value_Input(2*WB, 2*WB+6*BH, IW, BH, "Normals");
	geo_value[0]->minimum(0); 
	geo_value[0]->maximum(100);
	geo_value[0]->step(0.1);
	geo_value[0]->callback(opt_geometry_normals_cb);
	geo_value[0]->value(CTX.geom.normals);

        geo_value[1] = new Fl_Value_Input(2*WB, 2*WB+7*BH, IW, BH, "Tangents");
	geo_value[1]->minimum(0);
	geo_value[1]->maximum(100);
	geo_value[1]->step(0.1);
	geo_value[1]->callback(opt_geometry_tangents_cb);
	geo_value[1]->value(CTX.mesh.tangents);
	for(i=0 ; i<2 ; i++){
	  geo_value[i]->labelsize(CTX.fontsize);
	  geo_value[i]->type(FL_HORIZONTAL);
	  geo_value[i]->align(FL_ALIGN_RIGHT);
	}
        o->end();
      }
      o->end();
    }

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)geo_window);
    }

    if(CTX.center_windows)
      geo_window->position(m_window->x()+m_window->w()/2-width/2,
			   m_window->y()+2*MH);
    geo_window->end();
  }
  else{
    if(geo_window->shown())
      geo_window->redraw();
    else
      geo_window->show();
    
  }

}

//****************************** Create the window for mesh options ********************

void GUI::create_mesh_options_window(){
  static int init_mesh_options_window = 0;
  int i;

  if(!init_mesh_options_window){
    init_mesh_options_window = 1 ;

    int width = 26*CTX.fontsize;
    int height = 5*WB+9*BH ;
    
    mesh_window = new Fl_Window(width,height);
    mesh_window->box(FL_THIN_UP_BOX);
    mesh_window->label("Mesh Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Algorithm");
	o->labelsize(CTX.fontsize);
        o->hide();
        mesh_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Second order elements");
	mesh_butt[0]->callback(opt_mesh_degree_cb, (void*)0);
	mesh_butt[0]->value(CTX.mesh.degree==2);
        mesh_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Interactive");
	mesh_butt[1]->callback(opt_mesh_interactive_cb, (void*)0);
	mesh_butt[1]->value(CTX.mesh.interactive);
        mesh_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Anisotropic");
	mesh_butt[2]->callback(opt_mesh_algo_cb, (void*)0);
	mesh_butt[2]->value(CTX.mesh.algo==DELAUNAY_NEWALGO);
	for(i=0 ; i<3 ; i++){
	  mesh_butt[i]->type(FL_TOGGLE_BUTTON);
	  mesh_butt[i]->down_box(FL_DOWN_BOX);
	  mesh_butt[i]->labelsize(CTX.fontsize);
	  mesh_butt[i]->selection_color(FL_YELLOW);
	}
        mesh_value[0] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH,
					   "Number of smoothing steps");
	mesh_value[0]->minimum(0);
	mesh_value[0]->maximum(100); 
	mesh_value[0]->step(1);
	mesh_value[0]->callback(opt_mesh_smoothing_cb);
	mesh_value[0]->value(CTX.mesh.nb_smoothing);
	mesh_value[0]->labelsize(CTX.fontsize);
	mesh_value[0]->type(FL_HORIZONTAL);
	mesh_value[0]->align(FL_ALIGN_RIGHT);

        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Visibility");
	o->labelsize(CTX.fontsize);
        mesh_butt[3] = new Fl_Check_Button(2*WB, 2*WB+1*BH, IW, BH, "Points");
	mesh_butt[3]->callback(opt_mesh_entity_cb, (void*)0);
	mesh_butt[3]->value(CTX.mesh.points);
        mesh_butt[4] = new Fl_Check_Button(2*WB, 2*WB+2*BH, IW, BH, "Curves");
	mesh_butt[4]->callback(opt_mesh_entity_cb, (void*)1);
	mesh_butt[4]->value(CTX.mesh.lines);
        mesh_butt[5] = new Fl_Check_Button(2*WB, 2*WB+3*BH, IW, BH, "Surfaces");
	mesh_butt[5]->callback(opt_mesh_entity_cb, (void*)2);
	mesh_butt[5]->value(CTX.mesh.surfaces);
        mesh_butt[6] = new Fl_Check_Button(2*WB, 2*WB+4*BH, IW, BH, "Volumes");
	mesh_butt[6]->callback(opt_mesh_entity_cb, (void*)3);
	mesh_butt[6]->value(CTX.mesh.volumes);
        mesh_butt[7] = new Fl_Check_Button(width/2, 2*WB+1*BH, IW, BH, "Point Numbers");
	mesh_butt[7]->callback(opt_mesh_num_cb, (void*)0);
	mesh_butt[7]->value(CTX.mesh.points_num);
        mesh_butt[8] = new Fl_Check_Button(width/2, 2*WB+2*BH, IW, BH, "Curve Numbers");
	mesh_butt[8]->callback(opt_mesh_num_cb, (void*)1);
	mesh_butt[8]->value(CTX.mesh.lines_num);
        mesh_butt[9] = new Fl_Check_Button(width/2, 2*WB+3*BH, IW, BH, "Surface Numbers");
	mesh_butt[9]->callback(opt_mesh_num_cb, (void*)2);
	mesh_butt[9]->value(CTX.mesh.surfaces_num);
        mesh_butt[10] = new Fl_Check_Button(width/2, 2*WB+4*BH, IW, BH, "Volume Numbers");
	mesh_butt[10]->callback(opt_mesh_num_cb, (void*)3);
	mesh_butt[10]->value(CTX.mesh.volumes_num);
	for(i=3 ; i<11 ; i++){
	  mesh_butt[i]->type(FL_TOGGLE_BUTTON);
	  mesh_butt[i]->down_box(FL_DOWN_BOX);
	  mesh_butt[i]->labelsize(CTX.fontsize);
	  mesh_butt[i]->selection_color(FL_YELLOW);
	}
        mesh_input = new Fl_Input(2*WB, 2*WB+5*BH, IW, BH, "Show by entity Number");
	mesh_input->callback(opt_mesh_show_by_entity_num_cb);
	mesh_input->labelsize(CTX.fontsize);
	mesh_input->align(FL_ALIGN_RIGHT);

        mesh_value[1] = new Fl_Value_Input(2*WB, 2*WB+6*BH, IW, BH, "Show by element quality");
	mesh_value[1]->minimum(0); 
	mesh_value[1]->maximum(1);
	mesh_value[1]->step(0.001);
	mesh_value[1]->callback(opt_mesh_show_by_quality_cb);
	mesh_value[1]->value(CTX.mesh.limit_gamma);
	mesh_value[2] = new Fl_Value_Input(2*WB, 2*WB+7*BH, IW, BH, "Normals");
	mesh_value[2]->minimum(0); 
	mesh_value[2]->maximum(100);
	mesh_value[2]->step(1);
	mesh_value[2]->callback(opt_mesh_normals_cb);
	mesh_value[2]->value(CTX.mesh.normals);
	for(i=1 ; i<3 ; i++){
	  mesh_value[i]->labelsize(CTX.fontsize);
	  mesh_value[i]->type(FL_HORIZONTAL);
	  mesh_value[i]->align(FL_ALIGN_RIGHT);
	}
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Aspect");
	o->labelsize(CTX.fontsize);
        o->hide();
        mesh_butt[11] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Wireframe");
	mesh_butt[11]->callback(opt_mesh_aspect_cb, (void*)0);
	mesh_butt[11]->value(!CTX.mesh.hidden);
        mesh_butt[12] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Hidden lines");
	mesh_butt[12]->callback(opt_mesh_aspect_cb, (void*)1);
	mesh_butt[12]->value(CTX.mesh.hidden);
        mesh_butt[13] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Solid");
	mesh_butt[13]->callback(opt_mesh_aspect_cb, (void*)2);
	mesh_butt[13]->value(CTX.mesh.shade);
	for(i=11 ; i<14 ; i++){
	  mesh_butt[i]->type(FL_RADIO_BUTTON);
	  mesh_butt[i]->down_box(FL_DOWN_BOX);
	  mesh_butt[i]->labelsize(CTX.fontsize);
	  mesh_butt[i]->selection_color(FL_YELLOW);
	}
        mesh_value[4] = new Fl_Value_Input(2*WB, 2*WB+4*BH, IW, BH, "Explode elements");
	mesh_value[4]->minimum(0);
	mesh_value[4]->maximum(1);
	mesh_value[4]->step(0.01);
	mesh_value[4]->callback(opt_mesh_explode_cb);
	mesh_value[4]->value(CTX.mesh.explode);
	mesh_value[4]->labelsize(CTX.fontsize);
	mesh_value[4]->type(FL_HORIZONTAL);
	mesh_value[4]->align(FL_ALIGN_RIGHT);
        o->end();
      }
      o->end();
    }

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)mesh_window);
    }

    if(CTX.center_windows)
      mesh_window->position(m_window->x()+m_window->w()/2-width/2,
			    m_window->y()+2*MH);
    mesh_window->end();
  }
  else{
    if(mesh_window->shown())
      mesh_window->redraw();
    else
      mesh_window->show();
    
  }

}


//******************** Create the window for post-processing options *******************

void GUI::create_post_options_window(){
  static int init_post_options_window = 0;
  int i;

  if(!init_post_options_window){
    init_post_options_window = 1 ;

    int width = 17*CTX.fontsize;
    int height = 5*WB+5*BH ;
    
    post_window = new Fl_Window(width,height);
    post_window->box(FL_THIN_UP_BOX);
    post_window->label("Post Processing Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Links");
	o->labelsize(CTX.fontsize);
        post_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "No link between views");
	post_butt[0]->callback(opt_post_link_cb, (void*)0);
	post_butt[0]->value(CTX.post.link==0);
        post_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Link visible views");
	post_butt[1]->callback(opt_post_link_cb, (void*)1);
	post_butt[1]->value(CTX.post.link==1);
        post_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Link all views");
	post_butt[2]->callback(opt_post_link_cb, (void*)2);
	post_butt[2]->value(CTX.post.link==2);
	for(i=0 ; i<3 ; i++){
	  post_butt[i]->type(FL_RADIO_BUTTON);
	  post_butt[i]->labelsize(CTX.fontsize);
	  post_butt[i]->selection_color(FL_YELLOW);
	}
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Animation");
	o->labelsize(CTX.fontsize);
	o->hide();
        post_value[0] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Delay");
	post_value[0]->minimum(0);
	post_value[0]->maximum(10); 
	post_value[0]->step(0.01);
	post_value[0]->callback(opt_post_anim_delay_cb);
	post_value[0]->value(CTX.post.anim_delay);
	post_value[0]->labelsize(CTX.fontsize);
	post_value[0]->type(FL_HORIZONTAL);
	post_value[0]->align(FL_ALIGN_RIGHT);
	o->end();
      }
      o->end();
    }

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)post_window);
    }

    if(CTX.center_windows)
      post_window->position(m_window->x()+m_window->w()/2-width/2,
			    m_window->y()+2*MH);
    post_window->end();
  }
  else{
    if(post_window->shown())
      post_window->redraw();
    else
      post_window->show();
    
  }

}

//*********************** Create the window for the statistics *************************

void GUI::create_statistics_window(){
  static int init_statistics_window = 0;
  int i;

  if(!init_statistics_window){
    init_statistics_window = 1 ;

    int width = 22*CTX.fontsize;
    int height = 5*WB+16*BH ;
    
    stat_window = new Fl_Window(width,height);
    stat_window->box(FL_THIN_UP_BOX);
    stat_window->label("Statistics");
    {
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Geometry");
	o->labelsize(CTX.fontsize);
	o->hide();
        stat_value[0] = new Fl_Output(width/2, 2*WB+1*BH, IW, BH, "Number of points");
        stat_value[1] = new Fl_Output(width/2, 2*WB+2*BH, IW, BH, "Number of curves");
        stat_value[2] = new Fl_Output(width/2, 2*WB+3*BH, IW, BH, "Number of surfaces");
        stat_value[3] = new Fl_Output(width/2, 2*WB+4*BH, IW, BH, "Number of volumes");
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Mesh");
	o->labelsize(CTX.fontsize);
        stat_value[4] = new Fl_Output(width/2, 2*WB+1*BH, IW, BH, "Nodes on curves");
        stat_value[5] = new Fl_Output(width/2, 2*WB+2*BH, IW, BH, "Nodes on surfaces");
        stat_value[6] = new Fl_Output(width/2, 2*WB+3*BH, IW, BH, "Nodes in volumes");
        stat_value[7] = new Fl_Output(width/2, 2*WB+4*BH, IW, BH, "Triangles");
        stat_value[8] = new Fl_Output(width/2, 2*WB+5*BH, IW, BH, "Quadrangles");
        stat_value[9] = new Fl_Output(width/2, 2*WB+6*BH, IW, BH, "Tetrahedra");
        stat_value[10] = new Fl_Output(width/2, 2*WB+7*BH, IW, BH, "Hexahedra");
        stat_value[11] = new Fl_Output(width/2, 2*WB+8*BH, IW, BH, "Prisms");
        stat_value[12] = new Fl_Output(width/2, 2*WB+9*BH, IW, BH, "Time for 1D mesh");
        stat_value[13] = new Fl_Output(width/2, 2*WB+10*BH, IW, BH, "Time for 2D mesh");
        stat_value[14] = new Fl_Output(width/2, 2*WB+11*BH, IW, BH, "Time for 3D mesh");
        stat_value[15] = new Fl_Output(width/2, 2*WB+12*BH, IW, BH, "Gamma factor");
        stat_value[16] = new Fl_Output(width/2, 2*WB+13*BH, IW, BH, "Eta factor");
        stat_value[17] = new Fl_Output(width/2, 2*WB+14*BH, IW, BH, "Rho factor");
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Post-processing");
	o->labelsize(CTX.fontsize);
	o->hide();
        stat_value[18] = new Fl_Output(width/2, 2*WB+1*BH, IW, BH, "Views loaded");
        stat_value[19] = new Fl_Output(width/2, 2*WB+2*BH, IW, BH, "Visible Points");
        stat_value[20] = new Fl_Output(width/2, 2*WB+3*BH, IW, BH, "Visible lines");
        stat_value[21] = new Fl_Output(width/2, 2*WB+4*BH, IW, BH, "Visible triangles");
        stat_value[22] = new Fl_Output(width/2, 2*WB+5*BH, IW, BH, "Visible tetrahedra");
        o->end();
      }
      o->end();
    }

    for(i=0 ; i<23 ; i++){
      stat_value[i]->labelsize(CTX.fontsize);
      stat_value[i]->type(FL_HORIZONTAL);
      stat_value[i]->align(FL_ALIGN_LEFT);
      stat_value[i]->value(0);
    }

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-BB/3-2*WB, height-BH-WB, BB+BB/3, BH, "update");
      o->labelsize(CTX.fontsize);
      o->callback(opt_statistics_update_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)stat_window);
    }

    if(CTX.center_windows)
      stat_window->position(m_window->x()+m_window->w()/2-width/2,
			    m_window->y()+2*MH);
    stat_window->end();
    set_statistics();
    stat_window->show();
  }
  else{
    if(stat_window->shown())
      stat_window->redraw();
    else{
      set_statistics();
      stat_window->show();     
    }
  }

}

void GUI::set_statistics(){

  int i;	
  static double  s[50];
  static char    label[50][256];

  GetStatistics(s);

  // geom
  sprintf(label[0], "%g", s[0]); stat_value[0]->value(label[0]);
  sprintf(label[1], "%g", s[1]); stat_value[1]->value(label[1]);
  sprintf(label[2], "%g", s[2]); stat_value[2]->value(label[2]);
  sprintf(label[3], "%g", s[3]); stat_value[3]->value(label[3]);
                                                
  // mesh
  sprintf(label[4], "%g", s[4]); stat_value[4]->value(label[4]);
  sprintf(label[5], "%g", s[5]); stat_value[5]->value(label[5]);
  sprintf(label[6], "%g", s[6]); stat_value[6]->value(label[6]);
  sprintf(label[7], "%g", s[7]-s[8]); stat_value[7]->value(label[7]);
  sprintf(label[8], "%g", s[8]); stat_value[8]->value(label[8]);
  sprintf(label[9], "%g", s[9]); stat_value[9]->value(label[9]);
  sprintf(label[10], "%g", s[10]); stat_value[10]->value(label[10]);
  sprintf(label[11], "%g", s[11]); stat_value[11]->value(label[11]);

  sprintf(label[12], "%g", s[12]); stat_value[12]->value(label[12]);
  sprintf(label[13], "%g", s[13]); stat_value[13]->value(label[13]);
  sprintf(label[14], "%g", s[14]); stat_value[14]->value(label[14]);

  sprintf(label[15], "%.4g (%.4g->%.4g)", s[17], s[19], s[18]); 
  stat_value[15]->value(label[15]);
  sprintf(label[16], "%.4g (%.4g->%.4g)", s[20], s[22], s[21]); 
  stat_value[16]->value(label[16]);
  sprintf(label[17], "%.4g (%.4g->%.4g)", s[23], s[25], s[24]);
  stat_value[17]->value(label[17]);

  // post
  
  s[15] = List_Nbr(Post_ViewList) ;
  sprintf(label[18], "%g", s[15]);   stat_value[18]->value(label[18]);

  s[16] = s[17] = s[18] = s[19] = 0 ;
  for(i=0 ; i<List_Nbr(Post_ViewList) ; i++){
    Post_View *v = (Post_View*)List_Pointer(Post_ViewList, i);
    if(v->Visible){
      s[16] += v->NbSP + v->NbVP + v->NbTP;
      s[17] += v->NbSL + v->NbVL + v->NbTL;
      s[18] += v->NbST + v->NbVT + v->NbTT;
      s[19] += v->NbSS + v->NbVS + v->NbTS;
    }
  }
  sprintf(label[19], "%g", s[16]); stat_value[19]->value(label[19]);
  sprintf(label[20], "%g", s[17]); stat_value[20]->value(label[20]);
  sprintf(label[21], "%g", s[18]); stat_value[21]->value(label[21]);
  sprintf(label[22], "%g", s[19]); stat_value[22]->value(label[22]);

  for(i=0 ; i<23 ; i++)
    stat_value[16]->redraw();

}

//********************** Create the window for the messages ****************************

void GUI::create_message_window(){
  static int init_message_window = 0;

  if(!init_message_window){
    init_message_window = 1 ;

    int width = 35*CTX.fontsize;
    int height = 35*CTX.fontsize;
    
    msg_window = new Fl_Window(width,height);
    msg_window->box(FL_THIN_UP_BOX);
    msg_window->label("Messages");
    
    msg_browser = new Fl_Browser(WB, WB, width-2*WB, height-3*WB-BH);
    msg_browser->textfont(FL_COURIER);
    msg_browser->textsize(CTX.fontsize);

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "save");
      o->labelsize(CTX.fontsize);
      o->callback(opt_message_save_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)msg_window);
    }

    msg_window->resizable(msg_browser);

    if(CTX.center_windows)
      msg_window->position(m_window->x()+m_window->w()/2-width/2,
			   m_window->y()+2*MH);
    msg_window->end();
  }
  else{
    if(msg_window->shown())
      msg_window->redraw();
    else
      msg_window->show();
  }

}

void GUI::add_message(char *msg){
  msg_browser->add(msg,0);
}

void GUI::save_message(char *name){
  FILE *fp;

  if(!(fp = fopen(name,"w"))) {
    Msg(WARNING, "Unable to Open File '%s'", name); 
    return;
  }
  for(int i = 1 ; i<=msg_browser->size() ; i++)
    fprintf(fp, "%s\n", msg_browser->text(i));

  Msg(INFO, "Log Creation Complete '%s'", name);
  Msg(STATUS2, "Wrote File '%s'", name);
  fclose(fp);
}

//***************************** Create the short help window ***************************

#include "Help.h"

void GUI::create_help_window(){
  static int init_help_window = 0;

  if(!init_help_window){
    init_help_window = 1 ;

    int width = 38*CTX.fontsize;
    int height = 34*CTX.fontsize ;
    
    help_window = new Fl_Window(width,height);
    help_window->box(FL_THIN_UP_BOX);
    help_window->label("Short Help");

    Fl_Scroll*o = new Fl_Scroll(WB, WB, width-2*WB, height-3*WB-BH);
    {
      Fl_Multiline_Output* o = new Fl_Multiline_Output(WB, WB, 2*width, 3*height);
      o->value(txt_help);
      o->textfont(FL_COURIER);
      o->textsize(CTX.fontsize);
    }
    o->end();
    
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)help_window);
    }

    help_window->resizable(o);

    if(CTX.center_windows)
      help_window->position(m_window->x()+m_window->w()/2-width/2,
			    m_window->y()+2*MH);
    help_window->end();
  }
  else{
    if(help_window->shown())
      help_window->redraw();
    else
      help_window->show();
    
  }

}

//******************************* Create the about window ******************************

void GUI::create_about_window(){
  static int init_about_window = 0;

  if(!init_about_window){
    init_about_window = 1 ;

    int width = 40*CTX.fontsize;
    int height = 20*CTX.fontsize;
    
    about_window = new Fl_Window(width,height);
    about_window->box(FL_THIN_UP_BOX);
    about_window->label("About Gmsh");

    Fl_Box *o = new Fl_Box(2*WB, WB, about_width, height-2*WB);
    about_bmp = new Fl_Bitmap(about_bits,about_width,about_height);
    about_bmp->label(o);

    Fl_Button *o2 = new Fl_Button(WB+80, WB, width-2*WB-80, height-2*WB);
    static char buffer[1024];
    sprintf(buffer, "%s\n\n%s%.2f\n%s\n%s\n%s\n%s\n%s\n%s\n\n%s"
	    "\n\nType 'gmsh -help' for command line options",
	    gmsh_progname, gmsh_version, GMSH_VERSION, 
	    gmsh_os, gmsh_date, gmsh_host, gmsh_packager, 
	    gmsh_url, gmsh_email, gmsh_copyright);
    o2->label(buffer);
    o2->box(FL_FLAT_BOX);
    o2->labelsize(CTX.fontsize);
    o2->labelfont(FL_COURIER);
    o2->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    o2->callback(cancel_cb, (void*)about_window);

    if(CTX.center_windows)
      about_window->position(m_window->x()+m_window->w()/2-width/2,
			     m_window->y()+2*MH);
    about_window->end();
  }
  else{
    if(about_window->shown())
      about_window->redraw();
    else
      about_window->show();
  }

}

//************************* Create the window for view options *************************

void GUI::create_view_window(int num){
  static int init_view_window = 0;
  int i;

  if(!init_view_window){
    init_view_window = 1 ;

    int width = 32*CTX.fontsize;
    int height = 5*WB+7*BH + 7*CTX.fontsize;
    
    view_window = new Fl_Window(width,height);
    view_window->box(FL_THIN_UP_BOX);

    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      // Colors
      { 
	view_colors = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Colors");
	view_colors->labelsize(CTX.fontsize);
        //view_colorbar->hide();
	view_colorbar_window = new Colorbar_Window(2*WB, 2*WB+1*BH,
						   width-4*WB, height-5*WB-2*BH);
	view_colorbar_window->end();
        view_colors->end();
      }
      // Color bar
      { 
	view_colorbar = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Color bar");
	view_colorbar->labelsize(CTX.fontsize);
        view_colorbar->hide();
        view_butt[0] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Show color bar");
        view_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Display time");
        view_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Transparent bar");
	for(i=0 ; i<3 ; i++){
	  view_butt[i]->type(FL_TOGGLE_BUTTON);
	  view_butt[i]->down_box(FL_DOWN_BOX);
	  view_butt[i]->labelsize(CTX.fontsize);
	  view_butt[i]->selection_color(FL_YELLOW);
	}
	view_input[0] = new Fl_Input(2*WB, 2*WB+4*BH, IW, BH, "Title");
	view_input[1] = new Fl_Input(2*WB, 2*WB+5*BH, IW, BH, "Format");
	for(i=0 ; i<2 ; i++){
	  view_input[i]->labelsize(CTX.fontsize);
	  view_input[i]->align(FL_ALIGN_RIGHT);
	}
        view_colorbar->end();
      }
      // Range
      { 
	view_range = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Range");
	view_range->labelsize(CTX.fontsize);
	view_range->hide();
        view_butt[3] = new Fl_Check_Button(2*WB, 2*WB+1*BH, BW, BH, "Custom Range");
	view_butt[3]->type(FL_TOGGLE_BUTTON);
	view_butt[3]->down_box(FL_DOWN_BOX);
	view_butt[3]->labelsize(CTX.fontsize);
	view_butt[3]->selection_color(FL_YELLOW);

        view_value[0] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Minimum");
        view_value[1] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Maximum");
	for(i=0 ; i<2 ; i++){
	  view_value[i]->labelsize(CTX.fontsize);
	  view_value[i]->type(FL_HORIZONTAL);
	  view_value[i]->align(FL_ALIGN_RIGHT);
	}
	view_butt[4] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW, BH, "Linear");
	view_butt[5] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW, BH, "Logarithmic");
	for(i=4 ; i<6 ; i++){
	  view_butt[i]->type(FL_RADIO_BUTTON);
	  view_butt[i]->labelsize(CTX.fontsize);
	  view_butt[i]->selection_color(FL_YELLOW);
	}
	view_range->end();
      }
      // Intervals
      {
	view_intervals = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Intervals");
	view_intervals->labelsize(CTX.fontsize);
	view_intervals->hide();
	view_value[2] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "Number of intervals");
	view_value[2]->labelsize(CTX.fontsize);
	view_value[2]->type(FL_HORIZONTAL);
	view_value[2]->align(FL_ALIGN_RIGHT);
	view_value[2]->minimum(1); 
	view_value[2]->maximum(256); 
	view_value[2]->step(1);

	view_butt[6] = new Fl_Check_Button(2*WB, 2*WB+2*BH, BW, BH, "Iso-values");
	view_butt[7] = new Fl_Check_Button(2*WB, 2*WB+3*BH, BW, BH, "Filled iso-values");
	view_butt[8] = new Fl_Check_Button(2*WB, 2*WB+4*BH, BW, BH, "Continuous map");
	view_butt[9] = new Fl_Check_Button(2*WB, 2*WB+5*BH, BW, BH, "Numeric values");
	for(i=6 ; i<10 ; i++){
	  view_butt[i]->type(FL_RADIO_BUTTON);
	  view_butt[i]->labelsize(CTX.fontsize);
	  view_butt[i]->selection_color(FL_YELLOW);
	}
        view_intervals->end();
      }
      // Offset and Raise
      { 
	view_offsetraise = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Offset");
	view_offsetraise->labelsize(CTX.fontsize);
        view_offsetraise->hide();
	view_value[3] = new Fl_Value_Input(2*WB, 2*WB+1*BH, IW, BH, "X offset");
        view_value[4] = new Fl_Value_Input(2*WB, 2*WB+2*BH, IW, BH, "Y offset");
	view_value[5] = new Fl_Value_Input(2*WB, 2*WB+3*BH, IW, BH, "Z offset");
	view_value[6] = new Fl_Value_Input(width/2, 2*WB+1*BH, IW, BH, "X raise");
        view_value[7] = new Fl_Value_Input(width/2, 2*WB+2*BH, IW, BH, "Y raise");
	view_value[8] = new Fl_Value_Input(width/2, 2*WB+3*BH, IW, BH, "Z raise");
	for(i=3 ; i<9 ; i++){
	  view_value[i]->labelsize(CTX.fontsize);
	  view_value[i]->type(FL_HORIZONTAL);
	  view_value[i]->align(FL_ALIGN_RIGHT);
	}	
	view_offsetraise->end();
      }
      // Time step
      { 
	view_timestep = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Time step");
	view_timestep->labelsize(CTX.fontsize);
        view_timestep->hide();
	view_value[9] = new Fl_Value_Input(2*WB, 2*WB+BH, IW, BH, "Time step number");
	view_value[9]->labelsize(CTX.fontsize);
	view_value[9]->type(FL_HORIZONTAL);
	view_value[9]->align(FL_ALIGN_RIGHT);
	view_value[9]->minimum(0); 
	view_value[9]->maximum(0); 
	view_value[9]->step(1);
	view_timestep->end();
      }
      // Vector display
      { 
	view_vector = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Vector");
	view_vector->labelsize(CTX.fontsize);
        view_vector->hide();

	{
	  Fl_Group *o = new Fl_Group(2*WB, WB+BH, width-4*WB, 2*BH, 0);
	  view_butt[10] = new Fl_Check_Button(2*WB, 2*WB+1*BH, IW, BH, "Line");
	  view_butt[11] = new Fl_Check_Button(2*WB, 2*WB+2*BH, IW, BH, "Arrow");
	  view_butt[12] = new Fl_Check_Button(width/2, 2*WB+1*BH, IW, BH, "Cone");
	  view_butt[13] = new Fl_Check_Button(width/2, 2*WB+2*BH, IW, BH, "Displacement");
	  for(i=10 ; i<14 ; i++){
	    view_butt[i]->type(FL_RADIO_BUTTON);
	    view_butt[i]->labelsize(CTX.fontsize);
	    view_butt[i]->selection_color(FL_YELLOW);
	  }
	  o->end();
	}

	{
	  Fl_Group *o = new Fl_Group(2*WB, WB+3*BH, width-4*WB, 2*BH, 0);
	  view_butt[14] = new Fl_Check_Button(2*WB, 2*WB+3*BH, IW, BH, "Cell centered");
	  view_butt[15] = new Fl_Check_Button(2*WB, 2*WB+4*BH, IW, BH, "Vertex centered");
	  for(i=14 ; i<16 ; i++){
	    view_butt[i]->type(FL_RADIO_BUTTON);
	    view_butt[i]->labelsize(CTX.fontsize);
	    view_butt[i]->selection_color(FL_YELLOW);
	  }
	  o->end();
	}

	view_value[10] = new Fl_Value_Input(2*WB, 2*WB+ 5*BH, IW, BH, "Vector scale");
	view_value[10]->labelsize(CTX.fontsize);
	view_value[10]->type(FL_HORIZONTAL);
	view_value[10]->align(FL_ALIGN_RIGHT);
	view_value[10]->minimum(0); 
	view_value[10]->maximum(1000); 
	view_value[10]->step(1);

	view_vector->end();
      }
      o->end();
    }

    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-2*BB-2*WB, height-BH-WB, BB, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }
    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)view_window);
    }

    if(CTX.center_windows)
      view_window->position(m_window->x()+m_window->w()/2-width/2,
			    m_window->y()+2*MH);

    view_window->resizable(view_colorbar_window);
    view_window->end();
  }

  update_view_window(num);
  
  if(view_window->shown())
    view_window->redraw();
  else
    view_window->show();

}

void GUI::update_view_window(int num){
  int i;
  double val;
  Post_View *v = (Post_View*)List_Pointer(Post_ViewList, num);

  static char buffer[1024];
  sprintf(buffer, "Options for \"%s\" (\"%s\")", v->Name, v->FileName);
  view_window->label(buffer);

  // colobar
  view_butt[0]->callback(view_options_show_scale_cb, (void*)num);
  view_butt[0]->value(v->ShowScale);
  view_butt[1]->callback(view_options_show_time_cb, (void*)num);
  view_butt[1]->value(v->ShowTime);
  view_butt[2]->callback(view_options_transparent_scale_cb, (void*)num);
  view_butt[2]->value(v->TransparentScale);
  view_input[0]->callback(view_options_name_cb, (void*)num);
  view_input[0]->value(v->Name);
  view_input[1]->callback(view_options_format_cb, (void*)num);
  view_input[1]->value(v->Format);
  view_colorbar_window->update(v->Name, v->Min, v->Max, &v->CT);

  // range
  if(v->RangeType==DRAW_POST_CUSTOM) activate_custom(1);
  else activate_custom(0);
  view_butt[3]->callback(view_options_custom_range_cb, (void*)num);
  view_butt[3]->value(v->RangeType==DRAW_POST_CUSTOM);
  view_value[0]->callback(view_options_custom_min_cb, (void*)num);
  view_value[0]->value(v->CustomMin);
  view_value[1]->callback(view_options_custom_max_cb, (void*)num);
  view_value[1]->value(v->CustomMax);
  val = v->CustomMax-v->CustomMin ;
  for(i=0 ; i<2 ; i++){
    view_value[i]->step(val,1000); 
    view_value[i]->minimum(v->CustomMin); 
    view_value[i]->maximum(v->CustomMax); 
  }
  view_butt[4]->callback(view_options_linear_range_cb, (void*)num);
  view_butt[4]->value(v->ScaleType==DRAW_POST_LINEAR);
  view_butt[5]->callback(view_options_logarithmic_range_cb, (void*)num);
  view_butt[5]->value(v->ScaleType==DRAW_POST_LOGARITHMIC);

  // intervals
  view_value[2]->callback(view_options_nbiso_cb, (void*)num);
  view_value[2]->value(v->NbIso);
  view_butt[6]->callback(view_options_iso_cb, (void*)num);
  view_butt[6]->value(v->IntervalsType==DRAW_POST_ISO);
  view_butt[7]->callback(view_options_fillediso_cb, (void*)num);
  view_butt[7]->value(v->IntervalsType==DRAW_POST_DISCRETE);
  view_butt[8]->callback(view_options_continuousiso_cb, (void*)num);
  view_butt[8]->value(v->IntervalsType==DRAW_POST_CONTINUOUS);
  view_butt[9]->callback(view_options_numericiso_cb, (void*)num);
  view_butt[9]->value(v->IntervalsType==DRAW_POST_NUMERIC);

  // offset/raise
  view_value[3]->callback(view_options_xoffset_cb, (void*)num);
  view_value[3]->value(v->Offset[0]);
  view_value[4]->callback(view_options_yoffset_cb, (void*)num);
  view_value[4]->value(v->Offset[1]);
  view_value[5]->callback(view_options_zoffset_cb, (void*)num);
  view_value[5]->value(v->Offset[2]);
  view_value[6]->callback(view_options_xraise_cb, (void*)num);
  view_value[6]->value(v->Raise[0]);
  view_value[7]->callback(view_options_yraise_cb, (void*)num);
  view_value[7]->value(v->Raise[1]);
  view_value[8]->callback(view_options_zraise_cb, (void*)num);
  view_value[8]->value(v->Raise[2]);
  val = 10.*CTX.lc ;
  for(i=3 ; i<9 ; i++){
    view_value[i]->step(val,1000); 
    view_value[i]->minimum(-val); 
    view_value[i]->maximum(val); 
  }

  // timestep
  if(v->NbTimeStep==1) view_timestep->deactivate();
  else view_timestep->activate();
  view_value[9]->callback(view_options_timestep_cb, (void*)num);
  view_value[9]->value(v->TimeStep);
  view_value[9]->maximum(v->NbTimeStep-1); 

  // vector
  if(v->ScalarOnly) view_vector->deactivate();
  else view_vector->activate();
  view_butt[10]->callback(view_options_vector_line_cb, (void*)num);
  view_butt[10]->value(v->ArrowType==DRAW_POST_SEGMENT);
  view_butt[11]->callback(view_options_vector_arrow_cb, (void*)num);
  view_butt[11]->value(v->ArrowType==DRAW_POST_ARROW);
  view_butt[12]->callback(view_options_vector_cone_cb, (void*)num);
  view_butt[12]->value(v->ArrowType==DRAW_POST_CONE);
  view_butt[13]->callback(view_options_vector_displacement_cb, (void*)num);
  view_butt[13]->value(v->ArrowType==DRAW_POST_DISPLACEMENT);
  view_value[10]->callback(view_options_vector_scale_cb, (void*)num);
  view_value[10]->value(v->ArrowScale);
  view_butt[14]->callback(view_options_vector_cog_cb, (void*)num);
  view_butt[14]->value(v->ArrowLocation==DRAW_POST_LOCATE_COG);
  view_butt[15]->callback(view_options_vector_vertex_cb, (void*)num);
  view_butt[15]->value(v->ArrowLocation==DRAW_POST_LOCATE_VERTEX);

}

// Handle activation of cutom min/max

void GUI::activate_custom(int val){
  if(val){
    view_value[0]->activate();
    view_value[1]->activate();
  }
  else{
    view_value[0]->deactivate();
    view_value[1]->deactivate();
  }
}

//*************** Create the window for geometry context dependant definitions *********

void GUI::create_geometry_context_window(int num){
  static int init_geometry_context_window = 0;
  static Fl_Group *g[10];
  int i;

  if(!init_geometry_context_window){
    init_geometry_context_window = 1 ;

    int width = 31*CTX.fontsize;
    int height = 5*WB+9*BH ;
    
    context_geometry_window = new Fl_Window(width,height);
    context_geometry_window->box(FL_THIN_UP_BOX);
    context_geometry_window->label("Contextual Geometry Definitions");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      // 0: Parameter
      { 
	g[0] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Parameter");
	g[0]->labelsize(CTX.fontsize);
	context_geometry_input[0] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Name");
	context_geometry_input[1] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Value");
	for(i=0 ; i<2 ; i++){
	  context_geometry_input[i]->labelsize(CTX.fontsize);
	  context_geometry_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "add");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_geometry_define_parameter_cb);
	}
        g[0]->end();
      }
      // 1: Point
      { 
	g[1] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Point");
	g[1]->labelsize(CTX.fontsize);
	context_geometry_input[2] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, 
						  "X coordinate");
	context_geometry_input[3] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, 
						  "Y coordinate");
	context_geometry_input[4] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, 
						  "Z coordinate");
	context_geometry_input[5] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, 
						  "Characteristic length");
	for(i=2 ; i<6 ; i++){
	  context_geometry_input[i]->labelsize(CTX.fontsize);
	  context_geometry_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "add");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_geometry_define_point_cb);
	}
        g[1]->end();
      }
      // 2: Translation
      { 
	g[2] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Translation");
	g[2]->labelsize(CTX.fontsize);
	context_geometry_input[6] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "X component");
	context_geometry_input[7] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Y component");
	context_geometry_input[8] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, "Z component");
	for(i=6 ; i<9 ; i++){
	  context_geometry_input[i]->labelsize(CTX.fontsize);
	  context_geometry_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_geometry_define_translation_cb);
	}
        g[2]->end();
      }
      // 3: Rotation
      { 
	g[3] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Rotation");
	g[3]->labelsize(CTX.fontsize);
	context_geometry_input[9]  = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, 
						   "X coordinate of an axis point");
	context_geometry_input[10] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, 
						   "Y coordinate of an axis point");
	context_geometry_input[11] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, 
						   "Z coordinate of an axis point");
	context_geometry_input[12] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, 
						   "X component of direction");
	context_geometry_input[13] = new Fl_Input (2*WB, 2*WB+5*BH, IW, BH, 
						   "Y component of direction");
	context_geometry_input[14] = new Fl_Input (2*WB, 2*WB+6*BH, IW, BH, 
						   "Z component of direction");
	context_geometry_input[15] = new Fl_Input (2*WB, 2*WB+7*BH, IW, BH, 
						   "Angle in radians");
	for(i=9 ; i<16 ; i++){
	  context_geometry_input[i]->labelsize(CTX.fontsize);
	  context_geometry_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_geometry_define_rotation_cb);
	}
        g[3]->end();
      }
      // 4: Scale
      { 
	g[4] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Scale");
	g[4]->labelsize(CTX.fontsize);
	context_geometry_input[16] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, 
						   "X component of direction");
	context_geometry_input[17] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, 
						   "Y component of direction");
	context_geometry_input[18] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH, 
						   "Z component of direction");
	context_geometry_input[19] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH, 
						   "Factor");
	for(i=16 ; i<20 ; i++){
	  context_geometry_input[i]->labelsize(CTX.fontsize);
	  context_geometry_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_geometry_define_scale_cb);
	}
        g[4]->end();
      }
      // 5: Symmetry
      { 
	g[5] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Symmetry");
	g[5]->labelsize(CTX.fontsize);
	context_geometry_input[20] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, 
						   "1st plane equation coefficient");
	context_geometry_input[21] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, 
						   "2nd plane equation coefficient");
	context_geometry_input[22] = new Fl_Input (2*WB, 2*WB+3*BH, IW, BH,
						   "3rd plane equation coefficient");
	context_geometry_input[23] = new Fl_Input (2*WB, 2*WB+4*BH, IW, BH,
						   "4th plane equation coefficient");
	for(i=20 ; i<24 ; i++){
	  context_geometry_input[i]->labelsize(CTX.fontsize);
	  context_geometry_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+7*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_geometry_define_symmetry_cb);
	}
        g[5]->end();
      }
      o->end();
    }

    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)context_geometry_window);
    }

    for(i=0 ; i<6 ; i++) g[i]->hide();
    g[num]->show();

    if(CTX.center_windows)
      context_geometry_window->position(m_window->x()+m_window->w()/2-width/2,
					m_window->y()+2*MH);
    context_geometry_window->end();
    context_geometry_window->show();
  }
  else{
    if(context_geometry_window->shown()){
      for(i=0 ; i<6 ; i++) g[i]->hide();
      g[num]->show();
    }
    else{
      for(i=0 ; i<6 ; i++) g[i]->hide();
      g[num]->show();
      context_geometry_window->show();
    }
    
  }

}

char *GUI::get_geometry_parameter(int num){//name, val
  return (char*)context_geometry_input[num]->value();
}

char *GUI::get_geometry_point(int num){//x, y, z, l
  return (char*)context_geometry_input[num+2]->value();
}

char *GUI::get_geometry_translation(int num){//x, y, z
  return (char*)context_geometry_input[num+6]->value();
}

char *GUI::get_geometry_rotation(int num){//px, py, pz, ax, ay, az, ang
  return (char*)context_geometry_input[num+9]->value();
}

char *GUI::get_geometry_scale(int num){//x, y, z, f
  return (char*)context_geometry_input[num+16]->value();
}

char *GUI::get_geometry_symmetry(int num){//a, b, c, d
  return (char*)context_geometry_input[num+20]->value();
}


//************** Create the window for mesh context dependant definitions **************

void GUI::create_mesh_context_window(int num){
  static int init_mesh_context_window = 0;
  static Fl_Group *g[10];
  int i;

  if(!init_mesh_context_window){
    init_mesh_context_window = 1 ;

    int width = 31*CTX.fontsize;
    int height = 5*WB+5*BH ;
    
    context_mesh_window = new Fl_Window(width,height);
    context_mesh_window->box(FL_THIN_UP_BOX);
    context_mesh_window->label("Contextual Mesh Definitions");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      // 0: Characteristic length
      { 
	g[0] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Characteristic length");
	g[0]->labelsize(CTX.fontsize);
	context_mesh_input[0] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Value");
	context_mesh_input[0]->labelsize(CTX.fontsize);
	context_mesh_input[0]->align(FL_ALIGN_RIGHT);
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+3*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_mesh_define_length_cb);
	}
        g[0]->end();
      }
      // 1: Transfinite line
      { 
	g[1] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Transfinite line");
	g[1]->labelsize(CTX.fontsize);
	context_mesh_input[1] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Number of points");
	context_mesh_input[2] = new Fl_Input (2*WB, 2*WB+2*BH, IW, BH, "Distribution");
	for(i=1 ; i<3 ; i++){
	  context_mesh_input[i]->labelsize(CTX.fontsize);
	  context_mesh_input[i]->align(FL_ALIGN_RIGHT);
	}
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+3*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_mesh_define_transfinite_line_cb);
	}
        g[1]->end();
      }
      // 2: Transfinite volume
      { 
	g[2] = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Transfinite volume");
	g[2]->labelsize(CTX.fontsize);
	context_mesh_input[3] = new Fl_Input (2*WB, 2*WB+1*BH, IW, BH, "Volume number");
	context_mesh_input[3]->labelsize(CTX.fontsize);
	context_mesh_input[3]->align(FL_ALIGN_RIGHT);
	{ 
	  Fl_Return_Button* o = new Fl_Return_Button(width-BB-2*WB, 2*WB+3*BH, BB, BH, "set");
	  o->labelsize(CTX.fontsize);
	  o->callback(con_mesh_define_transfinite_line_cb);
	}
        g[2]->end();
      }
      o->end();
    }

    { 
      Fl_Button* o = new Fl_Button(width-BB-WB, height-BH-WB, BB, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)context_mesh_window);
    }

    for(i=0 ; i<3 ; i++) g[i]->hide();
    g[num]->show();

    if(CTX.center_windows)
      context_mesh_window->position(m_window->x()+m_window->w()/2-width/2,
				    m_window->y()+2*MH);
    context_mesh_window->end();
    context_mesh_window->show();
  }
  else{
    if(context_mesh_window->shown()){
      for(i=0 ; i<3 ; i++) g[i]->hide();
      g[num]->show();
    }
    else{
      for(i=0 ; i<3 ; i++) g[i]->hide();
      g[num]->show();
      context_mesh_window->show();
    }
    
  }
}

char *GUI::get_mesh_length(){//val
  return (char*)context_mesh_input[0]->value();
}

char *GUI::get_mesh_transfinite_line(int num){//pts, distrib
  return (char*)context_mesh_input[num+1]->value();
}

char *GUI::get_mesh_transfinite_volume(){//numvol
  return (char*)context_mesh_input[3]->value();
}

