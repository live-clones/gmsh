
// To make the interface as visually consistent as possible, please:
// - use the BH and WB values for button heights and window borders
// - use CTX.fontsize for font sizes
// - examine what's already done before adding something new...

#include "Gmsh.h"
#include "GmshUI.h"
#include "Context.h"
#include "Const.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Version.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Bitmaps.h"
#include "GetOptions.h"

extern Context_T  CTX;

// Definition of the static menus

Fl_Menu_Item m_menubar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"Open...",          FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"Merge...",         FL_CTRL+'m', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"Save",             FL_CTRL+'s', (Fl_Callback *)file_save_cb, 0},
    {"Save As",          0, 0, 0, FL_MENU_DIVIDER|FL_SUBMENU},
      {"By extension...",      0, (Fl_Callback *)file_save_as_auto_cb, 0},
      {"GEO...",               0, (Fl_Callback *)file_save_as_geo_cb, 0},
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
    {"Geometry...",        FL_SHIFT+'g', (Fl_Callback *)opt_geometry_cb, 0},
    {"Mesh...",            FL_SHIFT+'m', (Fl_Callback *)opt_mesh_cb, 0},
    {"Post-Processing...", FL_SHIFT+'p', (Fl_Callback *)opt_post_cb, 0, FL_MENU_DIVIDER},
    {"General...",         FL_SHIFT+'o', (Fl_Callback *)opt_general_cb, 0},
    {"Statistics...",      FL_SHIFT+'i', (Fl_Callback *)opt_statistics_cb, 0},
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

// Definition of the dynamic contexts

Context_Item menu_geometry[] = 
{ { "0", NULL } ,
  { "Elementary", (Fl_Callback *)geometry_elementary_cb } ,
  { "Physical",   (Fl_Callback *)geometry_physical_cb } ,
  { "Reload",     (Fl_Callback *)geometry_reload_cb } , 
  { NULL }
};  
    Context_Item menu_geometry_elementary[] = 
    { { "0", NULL } ,
      { "Add",       (Fl_Callback *)geometry_elementary_add_cb } ,
      { "Translate", (Fl_Callback *)geometry_elementary_translate_cb } ,
      { "Rotate",    (Fl_Callback *)geometry_elementary_rotate_cb } ,
      { "Dilate",    (Fl_Callback *)geometry_elementary_dilate_cb } ,
      { "Symmetry",  (Fl_Callback *)geometry_elementary_symmetry_cb } ,
      { "Extrude",   (Fl_Callback *)geometry_elementary_extrude_cb } ,
      { "Delete",    (Fl_Callback *)geometry_elementary_delete_cb } ,
      { NULL } 
    };  
        Context_Item menu_geometry_elementary_add[] = 
	{ { "0", NULL } ,
          { "New",       (Fl_Callback *)geometry_elementary_add_new_cb } ,
	  { "Translate", (Fl_Callback *)geometry_elementary_add_translate_cb } ,
	  { "Rotate",    (Fl_Callback *)geometry_elementary_add_rotate_cb } ,
	  { "Dilate",    (Fl_Callback *)geometry_elementary_add_dilate_cb } ,
	  { "Symmetry",  (Fl_Callback *)geometry_elementary_add_symmetry_cb } ,
	  { NULL } 
	};  
            Context_Item menu_geometry_elementary_add_new[] = 
	    { { "0", NULL } ,
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
	    { { "0", NULL } ,
              { "Point",   (Fl_Callback *)geometry_elementary_add_translate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_translate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_translate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_rotate[] = 
	    { { "0", NULL } ,
              { "Point",   (Fl_Callback *)geometry_elementary_add_rotate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_rotate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_rotate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_dilate[] = 
	    { { "0", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_add_dilate_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_dilate_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_dilate_surface_cb } ,
	      { NULL } 
	    };  
            Context_Item menu_geometry_elementary_add_symmetry[] = 
	    { { "0", NULL } ,
	      { "Point",   (Fl_Callback *)geometry_elementary_add_symmetry_point_cb } ,
	      { "Curve",   (Fl_Callback *)geometry_elementary_add_symmetry_curve_cb } ,
	      { "Surface", (Fl_Callback *)geometry_elementary_add_symmetry_surface_cb } ,
	      { NULL } 
	    };  
        Context_Item menu_geometry_elementary_translate[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_translate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_translate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_translate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_rotate[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_rotate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_rotate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_rotate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_dilate[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_dilate_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_dilate_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_dilate_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_symmetry[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_symmetry_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_symmetry_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_symmetry_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_extrude[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_extrude_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_extrude_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_extrude_surface_cb } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_elementary_delete[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_elementary_delete_point_cb } ,
	  { "Curve",   (Fl_Callback *)geometry_elementary_delete_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_elementary_delete_surface_cb } ,
	  { NULL } 
	};  
    Context_Item menu_geometry_physical[] = 
    { { "0", NULL } ,
      { "Add",    (Fl_Callback *)geometry_physical_add_cb } ,
      { "Delete", (Fl_Callback *)geometry_physical_delete_cb } ,
      { NULL } 
    };  
        Context_Item menu_geometry_physical_add[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_physical_add_point_cb  } ,
	  { "Curve",   (Fl_Callback *)geometry_physical_add_curve_cb  } ,
	  { "Surface", (Fl_Callback *)geometry_physical_add_surface_cb  } ,
	  { "Volume",  (Fl_Callback *)geometry_physical_add_volume_cb  } ,
	  { NULL } 
	};  
        Context_Item menu_geometry_physical_delete[] = 
	{ { "0", NULL } ,
	  { "Point",   (Fl_Callback *)geometry_physical_delete_point_cb } ,
	  { "Line",    (Fl_Callback *)geometry_physical_delete_curve_cb } ,
	  { "Surface", (Fl_Callback *)geometry_physical_delete_surface_cb } ,
	  { "Volume",  (Fl_Callback *)geometry_physical_delete_volume_cb } ,
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
    { { "1", NULL } ,
      { "Length",      (Fl_Callback *)mesh_define_length_cb  } ,
      { "Recombine",   (Fl_Callback *)mesh_define_recombine_cb  } ,
      { "Transfinite", (Fl_Callback *)mesh_define_transfinite_cb  } , 
      { NULL } 
    };  
        Context_Item menu_mesh_define_transfinite[] = 
	{ { "1", NULL } ,
	  { "Line",    (Fl_Callback *)mesh_define_transfinite_line_cb } ,
	  { "Surface", (Fl_Callback *)mesh_define_transfinite_surface_cb } ,
	  { "Volume",  (Fl_Callback *)mesh_define_transfinite_volume_cb } , 
	  { NULL } 
	};  

Context_Item menu_post[] = 
{ { "2", NULL } ,
  { NULL } };

// The GUI constructor creates ONLY the widgets that always exist (we
// want the lowest memory footprint for the interface and the fastest
// startup time). All optional dialogs are also created only once, but
// on demand.

GUI::GUI() {
  int i, x, y;

  BH = 2*CTX.fontsize+2;
  WB = CTX.fontsize-6;

  if(strlen(CTX.display)) Fl::display(CTX.display);

  // Icons

  icon1_bmp = new Fl_Bitmap(g1_bits,g1_width,g1_height);
  icon2_bmp = new Fl_Bitmap(g2_bits,g2_width,g2_height);
  icon3_bmp = new Fl_Bitmap(g3_bits,g3_width,g3_height);

  // Menu Window

  {
    int width = 155 ;
    MH = 2*BH+6 ; // this is the initial height: no dynamic button is shown!

    m_window = new Fl_Window(width,MH);
    m_window->box(FL_THIN_UP_BOX);
    m_window->label("Gmsh");

    {
      Fl_Menu_Bar *o = new Fl_Menu_Bar(0,0,width,BH); 
      o->menu(m_menubar_table);
      o->global();
      o->textsize(CTX.fontsize);
      o->box(FL_UP_BOX);
    }

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
      m_toggle_butt[i] = new Fl_Light_Button(0,y+i*BH,width,BH,"test"); 
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
			   (Fl_Callback *)view_duplicate_cb, (void*)i, 0);
      m_popup_butt[i]->add("Lightning", 0,
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
    
    m_window->position(800,50);
    m_window->end();
    m_window->show();

  }
    
  // Graphic Window

  {
    g_window = new Fl_Window(700,520);
    g_opengl_window = new Opengl_Window(0,0,700,500);
    
    {
      Fl_Group *o = new Fl_Group(0,500,700,20);
      o->box(FL_THIN_UP_BOX);

      x = 2;
      
      g_status_butt[0] = new Fl_Button(x,502,15,16,"X"); x+=15;
      g_status_butt[0]->callback(status_xyz1p_cb, (void*)0);
      //g_status_butt[0]->tooltip("Set X view");
      g_status_butt[1] = new Fl_Button(x,502,15,16,"Y"); x+=15;
      g_status_butt[1]->callback(status_xyz1p_cb, (void*)1);
      g_status_butt[2] = new Fl_Button(x,502,15,16,"Z"); x+=15;
      g_status_butt[2]->callback(status_xyz1p_cb, (void*)2);
      g_status_butt[3] = new Fl_Button(x,502,20,16,"1:1"); x+=20;
      g_status_butt[3]->callback(status_xyz1p_cb, (void*)3);
      g_status_butt[4] = new Fl_Button(x,502,15,16,"?"); x+=15;
      g_status_butt[4]->callback(status_xyz1p_cb, (void*)4);

      g_status_butt[5] = new Fl_Button(x,502,15,16,">>"); x+=15;
      g_status_butt[5]->callback(status_play_cb);
      start_bmp = new Fl_Bitmap(start_bits,start_width,start_height);
      start_bmp->label(g_status_butt[5]);
      stop_bmp = new Fl_Bitmap(stop_bits,stop_width,stop_height);

      g_status_butt[6] = new Fl_Button(x,502,15,16,"0"); x+=15;
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

      g_status_label[0] = new Fl_Box(x,502,(700-x)/3,16);
      g_status_label[1] = new Fl_Box(x+(700-x)/3,502,(700-x)/3,16);
      g_status_label[2] = new Fl_Box(x+2*(700-x)/3,502,(700-x)/3-2,16);
      for(i = 0 ; i<3 ; i++){
	g_status_label[i]->box(FL_FLAT_BOX);
	g_status_label[i]->labelsize(CTX.fontsize);
	g_status_label[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
      }
      
      o->end();
    }

    g_window->resizable(g_opengl_window);
    g_window->position(20,30);
    g_window->end();
    g_window->show();
    
  }

  // Draw the actual scene

  g_opengl_window->redraw();

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

// Set the statistics
void GUI::set_statistics(){
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

  sprintf(label[15], "%.4g (%.4g->%.4g)", s[17], s[19], s[18]); stat_value[15]->value(label[15]);
  sprintf(label[16], "%.4g (%.4g->%.4g)", s[20], s[22], s[21]); stat_value[16]->value(label[16]);
  sprintf(label[17], "%.4g (%.4g->%.4g)", s[23], s[25], s[24]); stat_value[17]->value(label[17]);

  // post
  
  s[15] = List_Nbr(Post_ViewList) ;
  sprintf(label[18], "%g", s[15]);   stat_value[18]->value(label[18]);

  s[16] = s[17] = s[18] = s[19] = 0 ;
  for(int i=0 ; i<List_Nbr(Post_ViewList) ; i++){
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

  for(int i=0 ; i<23 ; i++)
    stat_value[16]->redraw();

}

// set the current drawing context to the main opengl window

void GUI::make_gl_current(){
  g_opengl_window->make_current();
}

// Draw the opengl window

void GUI::draw_gl(){
  g_opengl_window->redraw();
}

// Draw the opengl overlay window

void GUI::draw_gl_overlay(){
  g_opengl_window->redraw_overlay();
}

// Run the GUI until no window is left

void GUI::run(){
  Fl::run();
}

// Check if any pending events and run them

void GUI::check(){
  Fl::check();
}

// Set the size of the graphical window

void GUI::set_gl_size(int new_w, int new_h){
  g_window->size(new_w,new_h+g_window->h()-g_opengl_window->h());
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

  m_module_butt->value(atoi(menu[0].label));

  if(m_module_butt->value() == 2){ // post-processing contexts
    for(i = 0 ; i < List_Nbr(Post_ViewList) ; i++) {
      if(i == NB_BUTT_MAX) break;
      nb++ ;
      v = (Post_View*)List_Pointer(Post_ViewList,i);
      m_push_butt[i]->hide();
      m_toggle_butt[i]->show();
      m_toggle_butt[i]->value(v->Visible);
      m_popup_butt[i]->show();
      // v->NbTimeStep>1 : sensitive timestep
      // v->ScalarOnly : sensitive vector, apply bgmesh
    }
    for(i = List_Nbr(Post_ViewList) ; i < NB_BUTT_MAX ; i++) {
      m_push_butt[i]->hide();
      m_toggle_butt[i]->hide();
      m_popup_butt[i]->hide();
    }
  }
  else{ // geometry and mesh contexts
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

// Create the window for general options

void GUI::create_general_options_window(){
  static int init_opt_general = 0;

  if(!init_opt_general){
    init_opt_general = 1 ;

    int width = 280;
    int height = 5*WB+8*BH ;
    
    gen_window = new Fl_Window(width,height);
    gen_window->box(FL_THIN_UP_BOX);
    gen_window->label("General Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Miscellaneous");
	o->labelsize(CTX.fontsize);
        gen_butt[0] = new Fl_Check_Button(2*WB, 2*WB+BH, 150, BH, "Show moving axes");
	gen_butt[0]->callback(opt_general_moving_axes_cb);
	gen_butt[0]->value(CTX.axes);
        gen_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 150, BH, "Show small axes");
	gen_butt[1]->callback(opt_general_small_axes_cb);
	gen_butt[1]->value(CTX.small_axes);
        gen_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 150, BH, "Enable fast redraw");
	gen_butt[2]->callback(opt_general_fast_redraw_cb);
	gen_butt[2]->value(CTX.fast);
        gen_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, 150, BH, "Use Display lists");
	gen_butt[3]->callback(opt_general_display_lists_cb);
	gen_butt[3]->value(CTX.display_lists);
        gen_butt[4] = new Fl_Check_Button(2*WB, 2*WB+5*BH, 150, BH, "Enable alpha blending");
	gen_butt[4]->callback(opt_general_alpha_blending_cb);
	gen_butt[4]->value(CTX.alpha);
        gen_butt[5] = new Fl_Check_Button(2*WB, 2*WB+6*BH, 150, BH, "Trackball rotation mode");
	gen_butt[5]->callback(opt_general_trackball_cb);
	gen_butt[5]->value(CTX.useTrackball);
	for(int i=0 ; i<6 ; i++){
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
        gen_butt[6] = new Fl_Check_Button(2*WB, 2*WB+BH, 150, BH, "Orthographic");
	gen_butt[6]->callback(opt_general_orthographic_cb, (void*)1);
	gen_butt[6]->value(CTX.ortho);
        gen_butt[7] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 150, BH, "Perspective");
	gen_butt[7]->callback(opt_general_orthographic_cb, (void*)0);
	gen_butt[7]->value(!CTX.ortho);
	for(int i=6 ; i<8 ; i++){
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
        gen_value[0] = new Fl_Value_Input(2*WB, 2*WB+BH, 100, BH, "Color Scheme");
	gen_value[0]->minimum(1); 
	gen_value[0]->maximum(3); 
	gen_value[0]->step(1);
	gen_value[0]->value(0);
	gen_value[0]->callback(opt_general_color_cb);
	gen_value[1] = new Fl_Value_Input(2*WB, 2*WB+2*BH, 100, BH, "Shininess");
	gen_value[1]->minimum(0); 
	gen_value[1]->maximum(10);
	gen_value[1]->step(0.1);
	gen_value[1]->value(CTX.shine);
	gen_value[1]->callback(opt_general_shininess_cb);
        gen_value[2] = new Fl_Value_Input(2*WB, 2*WB+3*BH, 100, BH, "Light Position X");
	gen_value[2]->minimum(-1); 
	gen_value[2]->maximum(1);
	gen_value[2]->step(0.01);
	gen_value[2]->value(CTX.light_position[0][0]);
	gen_value[2]->callback(opt_general_light_cb, (void*)0);
        gen_value[3] = new Fl_Value_Input(2*WB, 2*WB+4*BH, 100, BH, "Light Position Y");
	gen_value[3]->minimum(-1); 
	gen_value[3]->maximum(1); 
	gen_value[3]->step(0.01);
	gen_value[3]->value(CTX.light_position[0][1]);
	gen_value[3]->callback(opt_general_light_cb, (void*)1);
        gen_value[4] = new Fl_Value_Input(2*WB, 2*WB+5*BH, 100, BH, "Light Position Z");
	gen_value[4]->minimum(-1); 
	gen_value[4]->maximum(1); 
	gen_value[4]->step(0.01);
	gen_value[4]->value(CTX.light_position[0][2]);
	gen_value[4]->callback(opt_general_light_cb, (void*)2);
	for(int i=0 ; i<5 ; i++){
	  gen_value[i]->labelsize(CTX.fontsize);
	  gen_value[i]->type(FL_HORIZONTAL);
	  gen_value[i]->align(FL_ALIGN_RIGHT);
	}
        o->end();
      }
      o->end();

    }

    { 
      Fl_Button* o = new Fl_Button(width-2*60-2*WB, height-BH-WB, 60, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)gen_window);
    }
    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }

    gen_window->end();
    gen_window->show();
  }
  else{
    if(gen_window->shown())
      gen_window->hide();
    else
      gen_window->show();
    
  }

}

// Create the window for geometry options

void GUI::create_geometry_options_window(){
  static int init_opt_geometry = 0;

  if(!init_opt_geometry){
    init_opt_geometry = 1 ;

    int width = 280;
    int height = 5*WB+9*BH ;
    
    geo_window = new Fl_Window(width,height);
    geo_window->box(FL_THIN_UP_BOX);
    geo_window->label("Geometry Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Visibility");
	o->labelsize(CTX.fontsize);
        geo_butt[0] = new Fl_Check_Button(2*WB, 2*WB+BH, 100, BH, "Points");
	geo_butt[0]->callback(opt_geometry_entity_cb, (void*)0);
	geo_butt[0]->value(CTX.geom.points);
        geo_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 100, BH, "Curves");
	geo_butt[1]->callback(opt_geometry_entity_cb, (void*)1);
	geo_butt[1]->value(CTX.geom.lines);
        geo_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 100, BH, "Surfaces");
	geo_butt[2]->callback(opt_geometry_entity_cb, (void*)2);
	geo_butt[2]->value(CTX.geom.surfaces);
        geo_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, 100, BH, "Volumes");
	geo_butt[3]->callback(opt_geometry_entity_cb, (void*)3);
	geo_butt[3]->value(CTX.geom.volumes);
        geo_butt[4] = new Fl_Check_Button(2*WB+120, 2*WB+BH, 100, BH, "Point Numbers");
	geo_butt[4]->callback(opt_geometry_num_cb, (void*)0);
	geo_butt[4]->value(CTX.geom.points_num);
        geo_butt[5] = new Fl_Check_Button(2*WB+120, 2*WB+2*BH, 100, BH, "Curve Numbers");
	geo_butt[5]->callback(opt_geometry_num_cb, (void*)1);
	geo_butt[5]->value(CTX.geom.lines_num);
        geo_butt[6] = new Fl_Check_Button(2*WB+120, 2*WB+3*BH, 100, BH, "Surface Numbers");
	geo_butt[6]->callback(opt_geometry_num_cb, (void*)2);
	geo_butt[6]->value(CTX.geom.surfaces_num);
        geo_butt[7] = new Fl_Check_Button(2*WB+120, 2*WB+4*BH, 100, BH, "Volume Numbers");
	geo_butt[7]->callback(opt_geometry_num_cb, (void*)3);
	geo_butt[7]->value(CTX.geom.volumes_num);
	for(int i=0 ; i<8 ; i++){
	  geo_butt[i]->type(FL_TOGGLE_BUTTON);
	  geo_butt[i]->down_box(FL_DOWN_BOX);
	  geo_butt[i]->labelsize(CTX.fontsize);
	  geo_butt[i]->selection_color(FL_YELLOW);
	}
        geo_input = new Fl_Input(2*WB, 2*WB+5*BH, 100, BH, "Entity Number (or *)");
	geo_input->callback(opt_geometry_show_by_entity_num_cb);
	geo_input->labelsize(CTX.fontsize);
	geo_input->type(FL_HORIZONTAL);
	geo_input->align(FL_ALIGN_RIGHT);

	geo_value[0] = new Fl_Value_Input(2*WB, 2*WB+6*BH, 100, BH, "Normals");
	geo_value[0]->minimum(0); 
	geo_value[0]->maximum(100);
	geo_value[0]->step(0.1);
	geo_value[0]->callback(opt_geometry_normals_cb);
	geo_value[0]->value(CTX.geom.normals);

        geo_value[1] = new Fl_Value_Input(2*WB, 2*WB+7*BH, 100, BH, "Tangents");
	geo_value[1]->minimum(0);
	geo_value[1]->maximum(100);
	geo_value[1]->step(0.1);
	geo_value[1]->callback(opt_geometry_tangents_cb);
	geo_value[1]->value(CTX.mesh.tangents);
	for(int i=0 ; i<2 ; i++){
	  geo_value[i]->labelsize(CTX.fontsize);
	  geo_value[i]->type(FL_HORIZONTAL);
	  geo_value[i]->align(FL_ALIGN_RIGHT);
	}
        o->end();
      }
      o->end();
    }

    { 
      Fl_Button* o = new Fl_Button(width-2*60-2*WB, height-BH-WB, 60, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)geo_window);
    }
    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }

    geo_window->end();
    geo_window->show();
  }
  else{
    if(geo_window->shown())
      geo_window->hide();
    else
      geo_window->show();
    
  }

}

// Create the window for mesh options

void GUI::create_mesh_options_window(){
  static int init_opt_mesh = 0;

  if(!init_opt_mesh){
    init_opt_mesh = 1 ;

    int width = 280;
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
        mesh_butt[0] = new Fl_Check_Button(2*WB, 2*WB+BH, 100, BH, "Second Order");
	mesh_butt[0]->callback(opt_mesh_degree_cb, (void*)0);
	mesh_butt[0]->value(CTX.mesh.degree==2);
        mesh_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 100, BH, "Interactive");
	mesh_butt[1]->callback(opt_mesh_interactive_cb, (void*)0);
	mesh_butt[1]->value(CTX.mesh.interactive);
        mesh_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 100, BH, "Anisotropic");
	mesh_butt[2]->callback(opt_mesh_algo_cb, (void*)0);
	mesh_butt[2]->value(CTX.mesh.algo==DELAUNAY_NEWALGO);
	for(int i=0 ; i<3 ; i++){
	  mesh_butt[i]->type(FL_TOGGLE_BUTTON);
	  mesh_butt[i]->down_box(FL_DOWN_BOX);
	  mesh_butt[i]->labelsize(CTX.fontsize);
	  mesh_butt[i]->selection_color(FL_YELLOW);
	}
        mesh_value[0] = new Fl_Value_Input(2*WB, 2*WB+4*BH, 40, BH, "Smoothing Steps");
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
        mesh_butt[3] = new Fl_Check_Button(2*WB, 2*WB+BH, 100, BH, "Points");
	mesh_butt[3]->callback(opt_mesh_entity_cb, (void*)0);
	mesh_butt[3]->value(CTX.mesh.points);
        mesh_butt[4] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 100, BH, "Curves");
	mesh_butt[4]->callback(opt_mesh_entity_cb, (void*)1);
	mesh_butt[4]->value(CTX.mesh.lines);
        mesh_butt[5] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 100, BH, "Surfaces");
	mesh_butt[5]->callback(opt_mesh_entity_cb, (void*)2);
	mesh_butt[5]->value(CTX.mesh.surfaces);
        mesh_butt[6] = new Fl_Check_Button(2*WB, 2*WB+4*BH, 100, BH, "Volumes");
	mesh_butt[6]->callback(opt_mesh_entity_cb, (void*)3);
	mesh_butt[6]->value(CTX.mesh.volumes);
        mesh_butt[7] = new Fl_Check_Button(2*WB+120, 2*WB+BH, 100, BH, "Point Numbers");
	mesh_butt[7]->callback(opt_mesh_entity_cb, (void*)0);
	mesh_butt[7]->value(CTX.mesh.points_num);
        mesh_butt[8] = new Fl_Check_Button(2*WB+120, 2*WB+2*BH, 100, BH, "Curve Numbers");
	mesh_butt[8]->callback(opt_mesh_entity_cb, (void*)1);
	mesh_butt[8]->value(CTX.mesh.lines_num);
        mesh_butt[9] = new Fl_Check_Button(2*WB+120, 2*WB+3*BH, 100, BH, "Surface Numbers");
	mesh_butt[9]->callback(opt_mesh_entity_cb, (void*)2);
	mesh_butt[9]->value(CTX.mesh.surfaces_num);
        mesh_butt[10] = new Fl_Check_Button(2*WB+120, 2*WB+4*BH, 100, BH, "Volume Numbers");
	mesh_butt[10]->callback(opt_mesh_entity_cb, (void*)3);
	mesh_butt[10]->value(CTX.mesh.volumes_num);
	for(int i=3 ; i<11 ; i++){
	  mesh_butt[i]->type(FL_TOGGLE_BUTTON);
	  mesh_butt[i]->down_box(FL_DOWN_BOX);
	  mesh_butt[i]->labelsize(CTX.fontsize);
	  mesh_butt[i]->selection_color(FL_YELLOW);
	}
        mesh_input = new Fl_Input(2*WB, 2*WB+5*BH, 100, BH, "Entity Number");
	mesh_input->callback(opt_mesh_show_by_entity_num_cb);
	mesh_input->labelsize(CTX.fontsize);
	mesh_input->type(FL_HORIZONTAL);
	mesh_input->align(FL_ALIGN_RIGHT);

        mesh_value[1] = new Fl_Value_Input(2*WB, 2*WB+6*BH, 100, BH, "Element Quality");
	mesh_value[1]->minimum(0); 
	mesh_value[1]->maximum(1);
	mesh_value[1]->step(0.001);
	mesh_value[1]->callback(opt_mesh_show_by_quality_cb);
	mesh_value[1]->value(CTX.mesh.limit_gamma);
	mesh_value[2] = new Fl_Value_Input(2*WB, 2*WB+7*BH, 100, BH, "Normals");
	mesh_value[2]->minimum(0); 
	mesh_value[2]->maximum(100);
	mesh_value[2]->step(1);
	mesh_value[2]->callback(opt_mesh_normals_cb);
	mesh_value[2]->value(CTX.mesh.normals);
	for(int i=1 ; i<3 ; i++){
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
        mesh_butt[11] = new Fl_Check_Button(2*WB, 2*WB+BH, 100, BH, "Wireframe");
	mesh_butt[11]->callback(opt_mesh_aspect_cb, (void*)0);
	mesh_butt[11]->value(!CTX.mesh.hidden);
        mesh_butt[12] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 100, BH, "Hidden lines");
	mesh_butt[12]->callback(opt_mesh_aspect_cb, (void*)1);
	mesh_butt[12]->value(CTX.mesh.hidden);
        mesh_butt[13] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 100, BH, "Solid");
	mesh_butt[13]->callback(opt_mesh_aspect_cb, (void*)2);
	mesh_butt[13]->value(CTX.mesh.shade);
	for(int i=11 ; i<14 ; i++){
	  mesh_butt[i]->type(FL_RADIO_BUTTON);
	  mesh_butt[i]->down_box(FL_DOWN_BOX);
	  mesh_butt[i]->labelsize(CTX.fontsize);
	  mesh_butt[i]->selection_color(FL_YELLOW);
	}
        mesh_value[4] = new Fl_Value_Input(2*WB, 2*WB+4*BH, 40, BH, "Explode");
	mesh_value[4]->minimum(0);
	mesh_value[4]->maximum(100);
	mesh_value[4]->step(1);
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
      Fl_Button* o = new Fl_Button(width-2*60-2*WB, height-BH-WB, 60, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)mesh_window);
    }
    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }

    mesh_window->end();
    mesh_window->show();
  }
  else{
    if(mesh_window->shown())
      mesh_window->hide();
    else
      mesh_window->show();
    
  }

}


// Create the window for post-processing options

void GUI::create_post_options_window(){
  static int init_opt_post = 0;

  if(!init_opt_post){
    init_opt_post = 1 ;

    int width = 200;
    int height = 5*WB+5*BH ;
    
    post_window = new Fl_Window(width,height);
    post_window->box(FL_THIN_UP_BOX);
    post_window->label("Post Processing Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Links");
	o->labelsize(CTX.fontsize);
        post_butt[0] = new Fl_Check_Button(2*WB, 2*WB+BH, 150, BH, "No link between views");
	post_butt[0]->callback(opt_post_link_cb, (void*)0);
	post_butt[0]->value(CTX.post.link==0);
        post_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 150, BH, "Link visible views");
	post_butt[1]->callback(opt_post_link_cb, (void*)1);
	post_butt[1]->value(CTX.post.link==1);
        post_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 150, BH, "Link all views");
	post_butt[2]->callback(opt_post_link_cb, (void*)2);
	post_butt[2]->value(CTX.post.link==2);
	for(int i=0 ; i<3 ; i++){
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
        post_value[0] = new Fl_Value_Input(2*WB, 2*WB+BH, 40, BH, "Animation delay");
	post_value[0]->minimum(0);
	post_value[0]->maximum(10); 
	post_value[0]->step(0.1);
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
      Fl_Button* o = new Fl_Button(width-2*60-2*WB, height-BH-WB, 60, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)post_window);
    }
    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }

    post_window->end();
    post_window->show();
  }
  else{
    if(post_window->shown())
      post_window->hide();
    else
      post_window->show();
    
  }

}

// Create the window for the statistics

void GUI::create_statistics_window(){
  static int init_opt_statistics = 0;

  if(!init_opt_statistics){
    init_opt_statistics = 1 ;

    int width = 234;
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
        stat_value[0] = new Fl_Output(110+2*WB, 2*WB+BH, 100, BH, "Number of points");
        stat_value[1] = new Fl_Output(110+2*WB, 2*WB+2*BH, 100, BH, "Number of curves");
        stat_value[2] = new Fl_Output(110+2*WB, 2*WB+3*BH, 100, BH, "Number of surfaces");
        stat_value[3] = new Fl_Output(110+2*WB, 2*WB+4*BH, 100, BH, "Number of volumes");
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Mesh");
	o->labelsize(CTX.fontsize);
        stat_value[4] = new Fl_Output(110+2*WB, 2*WB+BH, 100, BH, "Nodes on curves");
        stat_value[5] = new Fl_Output(110+2*WB, 2*WB+2*BH, 100, BH, "Nodes on surfaces");
        stat_value[6] = new Fl_Output(110+2*WB, 2*WB+3*BH, 100, BH, "Nodes in Volumes");
        stat_value[7] = new Fl_Output(110+2*WB, 2*WB+4*BH, 100, BH, "Triangles");
        stat_value[8] = new Fl_Output(110+2*WB, 2*WB+5*BH, 100, BH, "Quadrangles");
        stat_value[9] = new Fl_Output(110+2*WB, 2*WB+6*BH, 100, BH, "Tetrahedra");
        stat_value[10] = new Fl_Output(110+2*WB, 2*WB+7*BH, 100, BH, "Hexahedra");
        stat_value[11] = new Fl_Output(110+2*WB, 2*WB+8*BH, 100, BH, "Prisms");
        stat_value[12] = new Fl_Output(110+2*WB, 2*WB+9*BH, 100, BH, "Time for 1D mesh");
        stat_value[13] = new Fl_Output(110+2*WB, 2*WB+10*BH, 100, BH, "Time for 2D mesh");
        stat_value[14] = new Fl_Output(110+2*WB, 2*WB+11*BH, 100, BH, "Time for 3D mesh");
        stat_value[15] = new Fl_Output(110+2*WB, 2*WB+12*BH, 100, BH, "Gamma factor");
        stat_value[16] = new Fl_Output(110+2*WB, 2*WB+13*BH, 100, BH, "Eta factor");
        stat_value[17] = new Fl_Output(110+2*WB, 2*WB+14*BH, 100, BH, "Rho factor");
        o->end();
      }
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Post-processing");
	o->labelsize(CTX.fontsize);
	o->hide();
        stat_value[18] = new Fl_Output(110+2*WB, 2*WB+BH, 100, BH, "Views loaded");
        stat_value[19] = new Fl_Output(110+2*WB, 2*WB+2*BH, 100, BH, "Visible Points");
        stat_value[20] = new Fl_Output(110+2*WB, 2*WB+3*BH, 100, BH, "Visible Lines");
        stat_value[21] = new Fl_Output(110+2*WB, 2*WB+4*BH, 100, BH, "Visible Triangles");
        stat_value[22] = new Fl_Output(110+2*WB, 2*WB+5*BH, 100, BH, "Visible Tetrahedra");
        o->end();
      }
      o->end();
    }

    for(int i=0 ; i<23 ; i++){
      stat_value[i]->labelsize(CTX.fontsize);
      stat_value[i]->type(FL_HORIZONTAL);
      stat_value[i]->align(FL_ALIGN_LEFT);
      stat_value[i]->value(0);
    }

    { 
      Fl_Button* o = new Fl_Button(width-2*60-2*WB, height-BH-WB, 60, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)stat_window);
    }
    { 
      Fl_Button* o = new Fl_Button(width-60-WB, height-BH-WB, 60, BH, "update");
      o->labelsize(CTX.fontsize);
      o->callback(opt_statistics_update_cb);
    }

    stat_window->end();
    set_statistics();
    stat_window->show();
  }
  else{
    if(stat_window->shown())
      stat_window->hide();
    else{
      set_statistics();
      stat_window->show();     
    }
  }

}

// Create the short help window

#include "Help.h"

void GUI::create_help_window(){
  static int init_help_short = 0;

  if(!init_help_short){
    init_help_short = 1 ;

    int width = 450;
    int height = 400 ;
    
    help_window = new Fl_Window(width,height);
    help_window->box(FL_THIN_UP_BOX);
    help_window->label("Short Help");

    Fl_Scroll*o = new Fl_Scroll(WB, WB, width-2*WB, height-3*WB-BH);
    {
      Fl_Multiline_Output* o = new Fl_Multiline_Output(WB, WB, 600, 1200);
      o->value(txt_help);
      o->textfont(FL_COURIER);
      o->textsize(CTX.fontsize);
    }
    o->end();
    
    { 
      Fl_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)help_window);
    }

    help_window->resizable(o);
    help_window->end();
    help_window->show();
  }
  else{
    if(help_window->shown())
      help_window->hide();
    else
      help_window->show();
    
  }

}

// Create the about window

void GUI::create_about_window(){
  static int init_help_about = 0;

  if(!init_help_about){
    init_help_about = 1 ;

    int width = 470;
    int height = 220;
    
    about_window = new Fl_Window(width,height);
    about_window->box(FL_THIN_UP_BOX);
    about_window->label("About Gmsh");

    Fl_Box *o = new Fl_Box(2*WB, WB, about_width, height-2*WB);
    about_bmp = new Fl_Bitmap(about_bits,about_width,about_height);
    about_bmp->label(o);

    Fl_Button *o2 = new Fl_Button(WB+80, WB, width-2*WB-80, height-2*WB);

  // Text for about window
    static char buffer[1024];
    sprintf(buffer, " %s\n \n %s%.2f\n %s\n %s\n %s\n %s\n %s\n %s\n \n %s"
	    "\n \n Type 'gmsh -help' for command line options",
	    gmsh_progname, gmsh_version, GMSH_VERSION, 
	    gmsh_os, gmsh_date, gmsh_host, gmsh_packager, 
	    gmsh_url, gmsh_email, gmsh_copyright);
    o2->label(buffer);
    o2->box(FL_THIN_UP_BOX);
    o2->labelsize(CTX.fontsize);
    o2->labelfont(FL_COURIER);
    o2->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE);
    o2->callback(cancel_cb, (void*)about_window);

    about_window->end();
    about_window->show();
  }
  else{
    if(about_window->shown())
      about_window->hide();
    else
      about_window->show();
  }

}

// Create the window for view options

void GUI::create_view_window(){
  static int init_opt_view = 0;

  if(!init_opt_view){
    init_opt_view = 1 ;

    int width = 280;
    int height = 5*WB+9*BH ;
    
    view_window = new Fl_Window(width,height);
    view_window->box(FL_THIN_UP_BOX);
    view_window->label("View Options");
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      // Color bar
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Color bar");
	o->labelsize(CTX.fontsize);
        o->hide();
        view_butt[0] = new Fl_Check_Button(2*WB, 2*WB+BH, 100, BH, "Show color bar");
        view_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 100, BH, "Display time");
        view_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 100, BH, "Transparent bar");
	for(int i=0 ; i<3 ; i++){
	  view_butt[i]->type(FL_TOGGLE_BUTTON);
	  view_butt[i]->down_box(FL_DOWN_BOX);
	  view_butt[i]->labelsize(CTX.fontsize);
	  view_butt[i]->selection_color(FL_YELLOW);
	}
	view_input[0] = new Fl_Input (2*WB, 2*WB+4*BH, 100, BH, "Title");
	view_input[1] = new Fl_Input (2*WB, 2*WB+5*BH, 100, BH, "Number format");
	for(int i=0 ; i<2 ; i++){
	  view_input[i]->labelsize(CTX.fontsize);
	  view_input[i]->type(FL_HORIZONTAL);
	  view_input[i]->align(FL_ALIGN_RIGHT);
	}
        o->end();
      }
      // Range
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Range");
	o->labelsize(CTX.fontsize);
	{
	  Fl_Group* o = new Fl_Group(WB, 2*WB+BH, width-2*WB, 2*BH, 0);
	  view_butt[4] = new Fl_Check_Button(2*WB, 2*WB+  BH, 100, BH, "Linear");
	  view_butt[5] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 100, BH, "Logarithmic");
	  for(int i=4 ; i<6 ; i++){
	    view_butt[i]->type(FL_RADIO_BUTTON);
	    view_butt[i]->labelsize(CTX.fontsize);
	    view_butt[i]->selection_color(FL_YELLOW);
	  }
	  o->end();
	}
        view_butt[3] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 100, BH, "Custom");
	view_butt[3]->type(FL_TOGGLE_BUTTON);
	view_butt[3]->down_box(FL_DOWN_BOX);
	view_butt[3]->labelsize(CTX.fontsize);
	view_butt[3]->selection_color(FL_YELLOW);

        view_value[0] = new Fl_Value_Input(2*WB+120, 2*WB+3*BH, 100, BH, "minimum");
        view_value[1] = new Fl_Value_Input(2*WB+120, 2*WB+4*BH, 100, BH, "maximum");
	for(int i=0 ; i<2 ; i++){
	  view_value[i]->labelsize(CTX.fontsize);
	  view_value[i]->type(FL_HORIZONTAL);
	  view_value[i]->align(FL_ALIGN_LEFT);
	}
	{
	  Fl_Group* o =  new Fl_Group       (WB,       2*WB+6*BH, width-2*WB, 2*BH, 0);
	  view_butt[6] = new Fl_Check_Button(2*WB,     2*WB+6*BH, 100, BH, "Iso");
	  view_butt[7] = new Fl_Check_Button(2*WB,     2*WB+7*BH, 100, BH, "Filled iso");
	  view_butt[8] = new Fl_Check_Button(2*WB+120, 2*WB+6*BH, 100, BH, "Continuous");
	  view_butt[9] = new Fl_Check_Button(2*WB+120, 2*WB+7*BH, 100, BH, "Numeric");
	  for(int i=6 ; i<10 ; i++){
	    view_butt[i]->type(FL_RADIO_BUTTON);
	    view_butt[i]->labelsize(CTX.fontsize);
	    view_butt[i]->selection_color(FL_YELLOW);
	  }
	  o->end();
	}
	view_value[2] = new Fl_Value_Input(2*WB, 2*WB+5*BH, 40, BH, "Intervals");
	view_value[2]->labelsize(CTX.fontsize);
	view_value[2]->type(FL_HORIZONTAL);
	view_value[2]->align(FL_ALIGN_RIGHT);
	view_value[2]->minimum(1); 
	view_value[2]->maximum(256); 
	view_value[2]->step(1);
        o->end();
      }
      // Offset and Raise
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Offset and raise");
	o->labelsize(CTX.fontsize);
        o->hide();
	view_value[3] = new Fl_Value_Input(2*WB, 2*WB+ BH, 100, BH, "X");
        view_value[4] = new Fl_Value_Input(2*WB, 2*WB+2*BH, 100, BH, "Y");
	view_value[5] = new Fl_Value_Input(2*WB, 2*WB+3*BH, 100, BH, "Z");
	view_value[6] = new Fl_Value_Input(2*WB, 2*WB+ BH, 100, BH, "X");
        view_value[7] = new Fl_Value_Input(2*WB, 2*WB+2*BH, 100, BH, "Y");
	view_value[8] = new Fl_Value_Input(2*WB, 2*WB+3*BH, 100, BH, "Z");
	for(int i=3 ; i<9 ; i++){
	  view_value[i]->labelsize(CTX.fontsize);
	  view_value[i]->type(FL_HORIZONTAL);
	  view_value[i]->align(FL_ALIGN_RIGHT);
	}	
	o->end();
      }
      // Time step
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Time step");
	o->labelsize(CTX.fontsize);
        o->hide();
	view_value[9] = new Fl_Value_Input(2*WB, 2*WB+ BH, 100, BH, "Time step");
	view_value[9]->labelsize(CTX.fontsize);
	view_value[9]->type(FL_HORIZONTAL);
	view_value[9]->align(FL_ALIGN_RIGHT);
	o->end();
      }
      o->end();
    }

    { 
      Fl_Button* o = new Fl_Button(width-2*60-2*WB, height-BH-WB, 60, BH, "cancel");
      o->labelsize(CTX.fontsize);
      o->callback(cancel_cb, (void*)view_window);
    }
    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
      o->callback(ok_cb);
    }

    view_window->end();
    view_window->show();
  }
  else{
    if(view_window->shown())
      view_window->hide();
    else
      view_window->show();
    
  }

}

