
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

//int strtok_r(char *, char const *, char **){return 0;}

extern Context_T  CTX;
extern List_T    *Post_ViewList;

// Definition of the static menus

Fl_Menu_Item m_menubar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"Open...",          FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"Merge...",         FL_CTRL+'m', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"Save",             FL_CTRL+'s', (Fl_Callback *)file_save_cb, 0},
    {"Save As...",       FL_CTRL+'p', (Fl_Callback *)file_save_as_cb, 0, FL_MENU_DIVIDER},
    {"Reload All Views", FL_CTRL+'l', (Fl_Callback *)file_reload_all_views_cb, 0},
    {"Remove All Views", FL_CTRL+'r', (Fl_Callback *)file_remove_all_views_cb, 0, FL_MENU_DIVIDER},
    {"Quit",             FL_CTRL+'q', (Fl_Callback *)file_quit_cb, 0},
    {0},
  {"Options",0,0,0,FL_SUBMENU},
    {"Geometry...",        FL_SHIFT+'g', (Fl_Callback *)opt_geometry_cb, 0},
    {"Mesh...",            FL_SHIFT+'m', (Fl_Callback *)opt_mesh_cb, 0},
    {"Post-Processing...", FL_SHIFT+'p', (Fl_Callback *)opt_post_cb, 0, FL_MENU_DIVIDER},
    {"General...",         FL_SHIFT+'o', (Fl_Callback *)opt_general_cb, 0},
    {"Statistics...",      FL_SHIFT+'i', (Fl_Callback *)opt_stat_cb, 0},
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

Context_Item menu_geom[] = 
{ { "0", NULL } ,
  { "Elementary", NULL } ,
  { "Physical", NULL } ,
  { "Reload", NULL } , 
  { NULL }
};  
    Context_Item menu_geom_elementary[] = 
    { { "0", NULL } ,
      { "Add", NULL } ,
      { "Translate", NULL } ,
      { "Rotate", NULL } ,
      { "Dilate", NULL } ,
      { "Symmetry", NULL } ,
      { "Extrude", NULL } ,
      { "Delete", NULL } ,
      { NULL } 
    };  
        Context_Item menu_geom_elementary_add[] = 
	{ { "0", NULL } ,
          { "New", NULL } ,
	  { "Translate", NULL } ,
	  { "Rotate", NULL } ,
	  { "Dilate", NULL } ,
	  { "Symmetry", NULL } ,
	  { NULL } 
	};  
            Context_Item menu_geom_elementary_add_new[] = 
	    { { "0", NULL } ,
              { "Parameter", NULL } ,
	      { "Point", NULL } ,
	      { "Line", NULL } ,
	      { "Spline", NULL } ,
	      { "Circle", NULL } ,
	      { "Ellipsis", NULL } ,
	      { "Plane Surface", NULL } ,
	      { "Ruled Surface", NULL } ,
	      { "Volume", NULL } ,
	      { NULL } 
	    };  
            Context_Item menu_geom_elementary_add_translate[] = 
	    { { "0", NULL } ,
              { "Point", NULL } ,
	      { "Curve", NULL } ,
	      { "Surface", NULL } ,
	      { NULL } 
	    };  
            Context_Item menu_geom_elementary_add_rotate[] = 
	    { { "0", NULL } ,
              { "Point", NULL } ,
	      { "Curve", NULL } ,
	      { "Surface", NULL } ,
	      { NULL } 
	    };  
            Context_Item menu_geom_elementary_add_dilate[] = 
	    { { "0", NULL } ,
	      { "Point", NULL } ,
	      { "Curve", NULL } ,
	      { "Surface", NULL } ,
	      { NULL } 
	    };  
            Context_Item menu_geom_elementary_add_symmetry[] = 
	    { { "0", NULL } ,
	      { "Point", NULL } ,
	      { "Curve", NULL } ,
	      { "Surface", NULL } ,
	      { NULL } 
	    };  
        Context_Item menu_geom_elementary_translate[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Curve", NULL } ,
	  { "Surface", NULL } ,
	  { NULL } 
	};  
        Context_Item menu_geom_elementary_rotate[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Curve", NULL } ,
	  { "Surface", NULL } ,
	  { NULL } 
	};  
        Context_Item menu_geom_elementary_dilate[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Curve", NULL } ,
	  { "Surface", NULL } ,
	  { NULL } 
	};  
        Context_Item menu_geom_elementary_symmetry[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Curve", NULL } ,
	  { "Surface", NULL } ,
	  { NULL } 
	};  
        Context_Item menu_geom_elementary_extrude[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Curve", NULL } ,
	  { "Surface", NULL } ,
	  { NULL } 
	};  
        Context_Item menu_geom_elementary_delete[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Curve", NULL } ,
	  { "Surface", NULL } ,
	  { NULL } 
	};  
    Context_Item menu_geom_physical[] = 
    { { "0", NULL } ,
      { "Add", NULL } ,
      { "Delete", NULL } ,
      { NULL } 
    };  
        Context_Item menu_geom_physical_add[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Line", NULL } ,
	  { "Surface", NULL } ,
	  { "Volume", NULL } ,
	  { NULL } 
	};  
        Context_Item menu_geom_physical_delete[] = 
	{ { "0", NULL } ,
	  { "Point", NULL } ,
	  { "Line", NULL } ,
	  { "Surface", NULL } ,
	  { "Volume", NULL } ,
	  { NULL } 
	};  

Context_Item menu_mesh[] = 
{ { "1", NULL } ,
  { "Define", NULL } ,
  { "1D", NULL } ,
  { "2D", NULL } , 
  { "3D", NULL } , 
  { NULL } 
};  
    Context_Item menu_mesh_define[] = 
    { { "1", NULL } ,
      { "Length", NULL } ,
      { "Recombine", NULL } ,
      { "Transfinite", NULL } , 
      { NULL } 
    };  
        Context_Item menu_mesh_define_transfinite[] = 
	{ { "1", NULL } ,
	  { "Line", NULL } ,
	  { "Surface", NULL } ,
	  { "Volume", NULL } , 
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

  // Menu Window

  {
    int width = 155 ;
    MH = 2*BH+6 ; // this is the initial height: no dynamic button is shown!

    m_window = new Fl_Window(width,MH);
    m_window->box(FL_THIN_UP_BOX);

    {
      Fl_Menu_Bar *o = new Fl_Menu_Bar(0,0,width,BH); 
      o->menu(m_menubar_table);
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
    m_navig_butt[1] = new Fl_Button(2,y+BH/2,20,BH/2,"@>");
    m_navig_butt[1]->labeltype(FL_SYMBOL_LABEL);
    m_navig_butt[1]->box(FL_FLAT_BOX);
    m_navig_butt[1]->selection_color(FL_WHITE);
    
    m_module_butt = new Fl_Choice(22,y,width-29,BH);
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
      if(i>5)m_toggle_butt[i]->hide();
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
      m_popup_butt[i]->add("Time Step...", 0,
			   (Fl_Callback *)view_timestep_cb, (void*)i, 0);
      m_popup_butt[i]->add("Options...", 0,
			   (Fl_Callback *)view_options_cb, (void*)i, 0);
      m_popup_butt[i]->textsize(CTX.fontsize);
      if(i>5)m_popup_butt[i]->hide();
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
      //g_status_butt[0]->tooltip("Set X view");
      g_status_butt[1] = new Fl_Button(x,502,15,16,"Y"); x+=15;
      g_status_butt[2] = new Fl_Button(x,502,15,16,"Z"); x+=15;
      g_status_butt[3] = new Fl_Button(x,502,16,16,"1:1"); x+=16;
      g_status_butt[4] = new Fl_Button(x,502,15,16,"?"); x+=15;
      g_status_butt[5] = new Fl_Button(x,502,15,16,">>"); x+=15;
      g_status_butt[6] = new Fl_Button(x,502,15,16,"0"); x+=15;
      for(i = 0 ; i<7 ; i++){
	g_status_butt[i]->box(FL_FLAT_BOX);
	g_status_butt[i]->selection_color(FL_WHITE);
	g_status_butt[i]->labelsize(CTX.fontsize);
	g_status_butt[i]->align(FL_ALIGN_CENTER|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
      }

      g_status_box[0] = new Fl_Box(x,502,(700-x)/3,16);
      g_status_box[1] = new Fl_Box(x+(700-x)/3,5022,(700-x)/3,16);
      g_status_box[2] = new Fl_Box(x+2*(700-x)/3,5022,(700-x)/3-2,16);
      for(i = 0 ; i<3 ; i++){
	g_status_box[i]->box(FL_FLAT_BOX);
	g_status_box[i]->labelsize(CTX.fontsize);
	g_status_box[i]->align(FL_ALIGN_LEFT|FL_ALIGN_INSIDE|FL_ALIGN_CLIP);
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

void GUI::set_size(int w, int h){
  static int initw, inith, init=0;
  if(!init){
    init = 1;
    initw = w;
    inith = h;
  }
  if(w == initw && h == inith) return;
  initw = w;
  inith = h;
  int hh = g_window->h()-g_opengl_window->h();
  g_window->size(w,h+hh);
}

// Dymanically set the height of the menu window

void GUI::set_menu_size(int nb_butt){
  m_window->size(m_window->w(), MH + nb_butt*BH);
}

// Dymanically set the context

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
	//m_push_butt[i]->callback(menu[i+1].callback);
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

// Create the window for general options

void GUI::opt_general(){
  static int init_opt_general = 0;

  if(!init_opt_general){
    init_opt_general = 1 ;

    int width = 280;
    int height = 5*WB+8*BH ;
    
    gen_window = new Fl_Window(width,height);
    gen_window->box(FL_THIN_UP_BOX);
    { 
      Fl_Tabs* o = new Fl_Tabs(WB, WB, width-2*WB, height-3*WB-BH);
      { 
	Fl_Group* o = new Fl_Group(WB, WB+BH, width-2*WB, height-3*WB-2*BH, "Miscellaneous");
	o->labelsize(CTX.fontsize);
        gen_butt[0] = new Fl_Check_Button(2*WB, 2*WB+BH, 150, BH, "Show moving axes");
        gen_butt[1] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 150, BH, "Show small axes");
        gen_butt[2] = new Fl_Check_Button(2*WB, 2*WB+3*BH, 150, BH, "Enable fast redraw");
        gen_butt[3] = new Fl_Check_Button(2*WB, 2*WB+4*BH, 150, BH, "Use Display lists");
        gen_butt[4] = new Fl_Check_Button(2*WB, 2*WB+5*BH, 150, BH, "Enable alpha blending");
        gen_butt[5] = new Fl_Check_Button(2*WB, 2*WB+6*BH, 150, BH, "Trackball rotation mode");
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
        gen_butt[7] = new Fl_Check_Button(2*WB, 2*WB+2*BH, 150, BH, "Perspective");
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
	gen_value[0]->minimum(1); gen_value[0]->maximum(3); gen_value[0]->step(1);
	gen_value[1] = new Fl_Value_Input(2*WB, 2*WB+2*BH, 100, BH, "Shininess");
	gen_value[1]->minimum(0); gen_value[1]->maximum(100); gen_value[1]->step(1);
        gen_value[2] = new Fl_Value_Input(2*WB, 2*WB+3*BH, 100, BH, "Light Position X");
	gen_value[2]->minimum(0); gen_value[2]->maximum(100); gen_value[2]->step(1);
        gen_value[3] = new Fl_Value_Input(2*WB, 2*WB+4*BH, 100, BH, "Light Position Y");
	gen_value[3]->minimum(0); gen_value[3]->maximum(100); gen_value[3]->step(1);
        gen_value[4] = new Fl_Value_Input(2*WB, 2*WB+5*BH, 100, BH, "Light Position Z");
	gen_value[4]->minimum(0); gen_value[4]->maximum(100); gen_value[4]->step(1);
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
    }
    { 
      Fl_Return_Button* o = new Fl_Return_Button(width-60-WB, height-BH-WB, 60, BH, "OK");
      o->labelsize(CTX.fontsize);
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
