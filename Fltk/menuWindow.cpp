// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <FL/Fl_Box.H>
#include "GUI.h"
#include "menuWindow.h"
#include "shortcutWindow.h"
#include "Callbacks.h"
#include "Options.h"
#include "Solvers.h"
#include "GmshMessage.h"
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#include "Context.h"

extern Context_T CTX;

// The static menus (we cannot use the 'g', 'm' 's' and 'p' mnemonics
// since they are already defined as global shortcuts)
static Fl_Menu_Item bar_table[] = {
  {"&File", 0, 0, 0, FL_SUBMENU},
    {"&New...",     FL_CTRL+'n', (Fl_Callback *)file_new_cb, 0},
    {"&Open...",    FL_CTRL+'o', (Fl_Callback *)file_open_cb, 0},
    {"M&erge...",   FL_CTRL+FL_SHIFT+'o', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"&Rename...",  FL_CTRL+'r', (Fl_Callback *)file_rename_cb, 0},
    {"Save &As...", FL_CTRL+'s', (Fl_Callback *)file_save_as_cb, 0},
    {"Sa&ve Mesh",  FL_CTRL+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, 0, FL_MENU_DIVIDER},
    {"&Quit",       FL_CTRL+'q', (Fl_Callback *)file_quit_cb, 0},
    {0},
  {"&Tools", 0, 0, 0, FL_SUBMENU},
    {"&Options...",      FL_CTRL+FL_SHIFT+'n', (Fl_Callback *)options_cb, 0},
    {"Pl&ugins...",      FL_CTRL+FL_SHIFT+'u', (Fl_Callback *)view_plugin_cb, (void*)(-1)},
    {"&Visibility",      FL_CTRL+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, 0},
    {"&Clipping",        FL_CTRL+FL_SHIFT+'c', (Fl_Callback *)clip_cb, 0},
    {"&Manipulator",     FL_CTRL+FL_SHIFT+'m', (Fl_Callback *)manip_cb, 0, FL_MENU_DIVIDER},
    {"S&tatistics",      FL_CTRL+'i', (Fl_Callback *)statistics_cb, 0},
    {"M&essage Console", FL_CTRL+'l', (Fl_Callback *)message_cb, 0},
    {0},
  {"&Help", 0, 0, 0, FL_SUBMENU},
    {"On&line Documentation", 0, (Fl_Callback *)help_online_cb, 0, FL_MENU_DIVIDER},
    {"M&ouse Actions",        0, (Fl_Callback *)help_mouse_cb, 0},
    {"&Keyboard Shortcuts",   0, (Fl_Callback *)help_short_cb, 0},
    {"C&ommand Line Options", 0, (Fl_Callback *)help_command_line_cb, 0},
    {"&Current Options",      0, (Fl_Callback *)status_xyz1p_cb, (void*)"?", FL_MENU_DIVIDER},
    {"&About Gmsh...",        0, (Fl_Callback *)help_about_cb, 0},
    {0},
  {0}
};

#if defined(__APPLE__)

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 1) && (FL_PATCH_VERSION <= 6)
#undef FL_META
#define FL_META FL_CTRL
#endif

// Alternative items for the MacOS system menu bar (removed '&'
// shortcuts: they would cause spurious menu items to appear on the
// menu window; removed File->Quit)
static Fl_Menu_Item sysbar_table[] = {
  {"File", 0, 0, 0, FL_SUBMENU},
    {"New...",     FL_META+'n', (Fl_Callback *)file_new_cb, 0},
    {"Open...",    FL_META+'o', (Fl_Callback *)file_open_cb, 0},
    {"Merge...",   FL_META+FL_SHIFT+'o', (Fl_Callback *)file_merge_cb, 0, FL_MENU_DIVIDER},
    {"Rename...",  FL_META+'r', (Fl_Callback *)file_rename_cb, 0},
    {"Save As...", FL_META+'s', (Fl_Callback *)file_save_as_cb, 0},
    {"Save Mesh",  FL_META+FL_SHIFT+'s', (Fl_Callback *)mesh_save_cb, 0},
    {0},
  {"Tools", 0, 0, 0, FL_SUBMENU},
    {"Options...",      FL_META+FL_SHIFT+'n', (Fl_Callback *)options_cb, 0},
    {"Plugins...",      FL_META+FL_SHIFT+'u', (Fl_Callback *)view_plugin_cb, (void*)(-1)},
    {"Visibility",      FL_META+FL_SHIFT+'v', (Fl_Callback *)visibility_cb, 0},
    {"Clipping",        FL_META+FL_SHIFT+'c', (Fl_Callback *)clip_cb, 0},
    {"Manipulator",     FL_META+FL_SHIFT+'m', (Fl_Callback *)manip_cb, 0, FL_MENU_DIVIDER},
    {"Statistics",      FL_META+'i', (Fl_Callback *)statistics_cb, 0},
    {"Message Console", FL_META+'l', (Fl_Callback *)message_cb, 0},
    {0},
  {"Window", 0, 0, 0, FL_SUBMENU},
    {"Minimize",           FL_META+'m', (Fl_Callback *)window_cb, (void*)"minimize"},
    {"Zoom",               0, (Fl_Callback *)window_cb, (void*)"zoom", FL_MENU_DIVIDER},
    {"Bring All to Front", 0, (Fl_Callback *)window_cb, (void*)"front"},
    {0},
  {"Help", 0, 0, 0, FL_SUBMENU},
    {"Online Documentation", 0, (Fl_Callback *)help_online_cb, 0, FL_MENU_DIVIDER},
    {"Mouse Actions",        0, (Fl_Callback *)help_mouse_cb, 0},
    {"Keyboard Shortcuts",   0, (Fl_Callback *)help_short_cb, 0},
    {"Command Line Options", 0, (Fl_Callback *)help_command_line_cb, 0},
    {"Current Options",      0, (Fl_Callback *)status_xyz1p_cb, (void*)"?", FL_MENU_DIVIDER},
    {"About Gmsh...",        0, (Fl_Callback *)help_about_cb, 0},
    {0},
  {0}
};

#endif

static Fl_Menu_Item module_table[] = {
  {"Geometry",        'g', (Fl_Callback *)mod_geometry_cb, 0},
  {"Mesh",            'm', (Fl_Callback *)mod_mesh_cb, 0},
  {"Solver",          's', (Fl_Callback *)mod_solver_cb, 0},
  {"Post-processing", 'p', (Fl_Callback *)mod_post_cb, 0},
  {0}
};

// Dynamic menus contexts
contextItem menu_geometry[] = {
  {"0Geometry", NULL} ,
  {"Elementary entities", (Fl_Callback *)geometry_elementary_cb} ,
  {"Physical groups",     (Fl_Callback *)geometry_physical_cb} ,
  {"Edit",                (Fl_Callback *)geometry_edit_cb} , 
  {"Reload",              (Fl_Callback *)geometry_reload_cb} , 
  {0}
};  
  contextItem menu_geometry_elementary[] = {
    {"0Geometry>Elementary", NULL} ,
    {"Add",       (Fl_Callback *)geometry_elementary_add_cb} ,
    {"Delete",    (Fl_Callback *)geometry_elementary_delete_cb, (void*)0} ,
    {"Translate", (Fl_Callback *)geometry_elementary_translate_cb, (void*)0} ,
    {"Rotate",    (Fl_Callback *)geometry_elementary_rotate_cb, (void*)0} ,
    {"Split",     (Fl_Callback *)geometry_elementary_split_cb, (void*)0} ,
    {"Scale",     (Fl_Callback *)geometry_elementary_scale_cb, (void*)0} ,
    {"Symmetry",  (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)0} ,
    {"Extrude",   (Fl_Callback *)geometry_elementary_extrude_cb, (void*)0} ,
    {"Coherence", (Fl_Callback *)geometry_elementary_coherence_cb} ,
    {0} 
  };  
    contextItem menu_geometry_elementary_add[] = {
      {"0Geometry>Elementary>Add", NULL} ,
      {"New",       (Fl_Callback *)geometry_elementary_add_new_cb, (void*)0} ,
      {"Translate", (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)0} ,
      {"Rotate",    (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)0} ,
      {"Scale",     (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)0} ,
      {"Symmetry",  (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)0} ,
      {0} 
    };  
      contextItem menu_geometry_elementary_add_new[] = {
        {"0Geometry>Elementary>Add>New", NULL} ,
        {"Parameter",     (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Parameter"} ,
        {"Point",         (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Point"} ,
        {"Straight line", (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Line"} ,
        {"Spline",        (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Spline"} ,
        {"B-Spline",      (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"BSpline"} ,
        {"Circle arc",    (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Circle"} ,
        {"Ellipse arc",   (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Ellipse"} ,
        {"Plane surface", (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Plane Surface"} ,
        {"Ruled surface", (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Ruled Surface"} ,
        {"Volume",        (Fl_Callback *)geometry_elementary_add_new_cb, (void*)"Volume"} ,
        {0} 
      };  
      contextItem menu_geometry_elementary_add_translate[] = {
        {"0Geometry>Elementary>Add>Translate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_translate_cb, (void*)"Volume"} , 
        {0} 
      };  
      contextItem menu_geometry_elementary_add_rotate[] = {
        {"0Geometry>Elementary>Add>Rotate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_rotate_cb, (void*)"Volume"} , 
        {0} 
      };  
      contextItem menu_geometry_elementary_add_scale[] = {
        {"0Geometry>Elementary>Add>Scale", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_scale_cb, (void*)"Volume"} , 
        {0} 
      };  
      contextItem menu_geometry_elementary_add_symmetry[] = {
        {"0Geometry>Elementary>Add>Symmetry", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Point"} ,  
        {"Line",    (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Line"} ,	  
        {"Surface", (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Surface"} ,
        {"Volume",  (Fl_Callback *)geometry_elementary_add_symmetry_cb, (void*)"Volume"} , 
        {0} 
      };  
    contextItem menu_geometry_elementary_delete[] = {
      {"0Geometry>Elementary>Delete", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Point"} ,
      {"Line",    (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Line"} ,
      {"Surface", (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_delete_cb, (void*)"Volume"} ,
      {0} 
    };  
    contextItem menu_geometry_elementary_split[] = {
      {"0Geometry>Elementary>Split",NULL},
        {"Line",(Fl_Callback *)geometry_elementary_split_cb,(void*)"Line"},
        {0}
    };
    contextItem menu_geometry_elementary_translate[] = {
      {"0Geometry>Elementary>Translate", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_translate_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_rotate[] = {
      {"0Geometry>Elementary>Rotate", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_rotate_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_scale[] = {
      {"0Geometry>Elementary>Scale", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_scale_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_symmetry[] = {
      {"0Geometry>Elementary>Symmetry", NULL} ,
      {"Point",   (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Point"} ,  
      {"Line",    (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Line"} ,	  
      {"Surface", (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Surface"} ,
      {"Volume",  (Fl_Callback *)geometry_elementary_symmetry_cb, (void*)"Volume"} , 
      {0} 
    };  
    contextItem menu_geometry_elementary_extrude[] = {
      {"0Geometry>Elementary>Extrude", NULL} ,
      {"Translate", (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)0} ,
      {"Rotate",    (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)0} ,
      {0} 
    };  
      contextItem menu_geometry_elementary_extrude_translate[] = {
        {"0Geometry>Elementary>Extrude>Translate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_extrude_translate_cb, (void*)"Surface"} ,
        {0} 
      };  
      contextItem menu_geometry_elementary_extrude_rotate[] = {
        {"0Geometry>Elementary>Extrude>Rotate", NULL} ,
        {"Point",   (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Point"} ,
        {"Line",    (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Line"} ,
        {"Surface", (Fl_Callback *)geometry_elementary_extrude_rotate_cb, (void*)"Surface"} ,
        {0} 
      };  
  contextItem menu_geometry_physical[] = {
    {"0Geometry>Physical", NULL} ,
    {"Add",    (Fl_Callback *)geometry_physical_add_cb, (void*)0} ,
    {0} 
  };  
    contextItem menu_geometry_physical_add[] = {
      {"0Geometry>Physical>Add", NULL} ,
      {"Point",   (Fl_Callback *)geometry_physical_add_cb, (void*)"Point" } ,
      {"Line",    (Fl_Callback *)geometry_physical_add_cb, (void*)"Line" } ,
      {"Surface", (Fl_Callback *)geometry_physical_add_cb, (void*)"Surface" } ,
      {"Volume",  (Fl_Callback *)geometry_physical_add_cb, (void*)"Volume" } ,
      {0} 
    };  

contextItem menu_mesh[] = {
  {"1Mesh", NULL} ,
  {"Define",       (Fl_Callback *)mesh_define_cb} ,
  {"Inspect",      (Fl_Callback *)mesh_inspect_cb} , 
  {"Delete",       (Fl_Callback *)mesh_delete_cb} , 
  {"1D",           (Fl_Callback *)mesh_1d_cb} ,
  {"2D",           (Fl_Callback *)mesh_2d_cb} , 
  {"3D",           (Fl_Callback *)mesh_3d_cb} , 
  {"First order",  (Fl_Callback *)mesh_degree_cb, (void*)1 } , 
  {"Second order", (Fl_Callback *)mesh_degree_cb, (void*)2 } , 
  {"Refine",       (Fl_Callback *)mesh_refine_cb} ,
  {"Optimize",     (Fl_Callback *)mesh_optimize_cb} , 
#if defined(HAVE_NETGEN)
  {"Optimize (Netgen)", (Fl_Callback *)mesh_optimize_netgen_cb} , 
#endif
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  {"Partition", (Fl_Callback *)mesh_partition_cb} ,
#endif
#if defined(HAVE_FOURIER_MODEL)
  {"Reparameterize",   (Fl_Callback *)mesh_parameterize_cb} , 
#endif
  //{"Reclassify",   (Fl_Callback *)mesh_classify_cb} , 
  {"Save",         (Fl_Callback *)mesh_save_cb} ,
  {0} 
};  
  contextItem menu_mesh_define[] = {
    {"1Mesh>Define", NULL} ,
    {"Fields",      (Fl_Callback *)view_field_cb},
    {"Characteristic length", (Fl_Callback *)mesh_define_length_cb  } ,
    {"Recombine",   (Fl_Callback *)mesh_define_recombine_cb  } ,
    {"Transfinite", (Fl_Callback *)mesh_define_transfinite_cb  } , 
    {0} 
  };  
    contextItem menu_mesh_define_transfinite[] = {
      {"1Mesh>Define>Transfinite", NULL} ,
      {"Line",    (Fl_Callback *)mesh_define_transfinite_line_cb} ,
      {"Surface", (Fl_Callback *)mesh_define_transfinite_surface_cb} ,
      {"Volume",  (Fl_Callback *)mesh_define_transfinite_volume_cb} , 
      {0} 
    };  
  contextItem menu_mesh_delete[] = {
    {"1Mesh>Edit>Delete", NULL} ,
    {"Elements", (Fl_Callback *)mesh_delete_parts_cb, (void*)"elements"} ,
    {"Lines",    (Fl_Callback *)mesh_delete_parts_cb, (void*)"lines"} ,
    {"Surfaces", (Fl_Callback *)mesh_delete_parts_cb, (void*)"surfaces"} ,
    {"Volumes",  (Fl_Callback *)mesh_delete_parts_cb, (void*)"volumes"} ,
    {0} 
  };  

contextItem menu_solver[] = {
  {"2Solver", NULL} ,
  {"Solver 0", (Fl_Callback *)solver_cb , (void*)0} ,
  {"Solver 1", (Fl_Callback *)solver_cb , (void*)1} ,
  {"Solver 2", (Fl_Callback *)solver_cb , (void*)2} ,
  {"Solver 3", (Fl_Callback *)solver_cb , (void*)3} ,
  {"Solver 4", (Fl_Callback *)solver_cb , (void*)4} ,
  {0} 
};

contextItem menu_post[] = {
  {"3Post-processing", NULL} ,
  {0} 
};

menuWindow::menuWindow(int fontsize) : _fontsize(fontsize)
{
  int width = 14 * fontsize;

  // this is the initial height: no dynamic button is shown
#if defined(__APPLE__)
  if(CTX.system_menu_bar){
    _MH = BH + 6; // the menu bar is not in the application
  }
  else{
#endif
    _MH = BH + BH + 6;
#if defined(__APPLE__)
  }
#endif

  win = new mainWindow(width, _MH + NB_BUTT_SCROLL * BH, CTX.non_modal_windows, "Gmsh");
  win->box(GMSH_WINDOW_BOX);
  win->callback(file_quit_cb);

  int y;
#if defined(__APPLE__)
  if(CTX.system_menu_bar){
    // the system menubar is kind of a hack in fltk < 1.1.7: it still
    // creates a real (invisible) menubar. To avoid spurious mouse
    // click events we make it a 1x1 pixel rectangle, 1 pixel off the
    // edge (so it falls behind the navigation buttons)
    sysbar = new Fl_Sys_Menu_Bar(1, 1, 1, 1);
    sysbar->menu(sysbar_table);
    sysbar->global();
    Fl_Box *o = new Fl_Box(0, 0, width, BH + 6);
    o->box(FL_UP_BOX);
    y = 3;
  }
  else{
#endif
    bar = new Fl_Menu_Bar(0, 0, width, BH);
    bar->menu(bar_table);
    bar->box(FL_UP_BOX);
    bar->global();
    Fl_Box *o = new Fl_Box(0, BH, width, BH + 6);
    o->box(FL_UP_BOX);
    y = BH + 3;
#if defined(__APPLE__)
  }
#endif

  navig[0] = new Fl_Button(1, y, 18, BH / 2, "@#-1<");
  navig[0]->labeltype(FL_SYMBOL_LABEL);
  navig[0]->box(FL_FLAT_BOX);
  navig[0]->selection_color(FL_WHITE);
  navig[0]->callback(mod_back_cb);
  navig[0]->tooltip("Go back one in the menu history (<)");

  navig[1] = new Fl_Button(1, y + BH / 2, 18, BH / 2, "@#-1>");
  navig[1]->labeltype(FL_SYMBOL_LABEL);
  navig[1]->box(FL_FLAT_BOX);
  navig[1]->selection_color(FL_WHITE);
  navig[1]->callback(mod_forward_cb);
  navig[1]->tooltip("Go forward one in the menu history (>)");

  module = new Fl_Choice(19, y, width - 24, BH);
  module->menu(module_table);
  module->box(FL_THIN_DOWN_BOX);
  // force the executation of the callback even if we didn't change
  // the selection (we want to go back to the top-level menu every
  // time we select one of the categories, even if the category is not
  // changed):
  module->when(FL_WHEN_RELEASE_ALWAYS);

  // create an empty scroll area that will get populated dynamically
  // in set_context()
  scroll = new Fl_Scroll(0, _MH, width, NB_BUTT_SCROLL * BH); 
  scroll->type(Fl_Scroll::VERTICAL);
  scroll->end();

  win->size(width, _MH);
  win->position(CTX.position[0], CTX.position[1]);
  
  win->end();
}

void menuWindow::setContext(contextItem *menu_asked, int flag)
{
  static int nb_back = 0, nb_forward = 0, init_context = 0;
  static contextItem *menu_history[NB_HISTORY_MAX];
  contextItem *menu;

  if(!init_context) {
    init_context = 1;
    for(int i = 0; i < NB_HISTORY_MAX; i++) {
      menu_history[i] = NULL;
    }
  }

  if(nb_back > NB_HISTORY_MAX - 2)
    nb_back = 1; // we should do a circular list

  if(flag == -1) {
    if(nb_back > 1) {
      nb_back--;
      nb_forward++;
      menu = menu_history[nb_back - 1];
    }
    else
      return;
  }
  else if(flag == 1) {
    if(nb_forward > 0) {
      nb_back++;
      nb_forward--;
      menu = menu_history[nb_back - 1];
    }
    else
      return;
  }
  else {
    menu = menu_asked;
    if(!nb_back || menu_history[nb_back - 1] != menu) {
      menu_history[nb_back++] = menu;
    }
    nb_forward = 0;
  }

  if(menu[0].label[0] == '0'){
    module->value(0);
  }
  else if(menu[0].label[0] == '1'){
    module->value(1);
  }
  else if(menu[0].label[0] == '2'){
    module->value(2);
    menu[1].label = opt_solver_name0(0, GMSH_GET, 0);
    menu[2].label = opt_solver_name1(0, GMSH_GET, 0);
    menu[3].label = opt_solver_name2(0, GMSH_GET, 0);
    menu[4].label = opt_solver_name3(0, GMSH_GET, 0);
    menu[5].label = opt_solver_name4(0, GMSH_GET, 0);
    for(int i = 0; i < MAX_NUM_SOLVERS; i++) {
      if(!strlen(menu[i + 1].label))
        menu[i + 1].label = NULL;
    }
  }
  else if(menu[0].label[0] == '3'){
    module->value(3);
  }
  else {
    Msg::Warning("Something is wrong in your dynamic context definition");
    return;
  }

  Msg::StatusBar(1, false, menu[0].label + 1);

  // cannot use scroll->clear() in fltk 1.1 (should be fixed in 1.3)
  for(unsigned int i = 0; i < push.size(); i++){
    scroll->remove(push[i]);
    Fl::delete_widget(push[i]);
  }
  for(unsigned int i = 0; i < toggle.size(); i++){
    scroll->remove(toggle[i]);
    Fl::delete_widget(toggle[i]);
  }
  for(unsigned int i = 0; i < toggle2.size(); i++){
    scroll->remove(toggle2[i]);
    Fl::delete_widget(toggle2[i]);
  }
  for(unsigned int i = 0; i < popup.size(); i++){
    scroll->remove(popup[i]);
    Fl::delete_widget(popup[i]);
  }
  for(unsigned int i = 0; i < popup2.size(); i++){
    scroll->remove(popup2[i]);
    Fl::delete_widget(popup2[i]);
  }

  // reset the vectors
  push.clear();
  toggle.clear();
  toggle2.clear();
  popup.clear();
  popup2.clear();
  for(unsigned int i = 0; i < label.size(); i++)
    delete [] label[i];
  label.clear();

  int width = win->w();
  int popw = 4 * _fontsize + 3;

  // construct the dynamic menu
  int nb = 0;
  if(module->value() == 3){ // post-processing context
    for(nb = 0; nb < (int)PView::list.size(); nb++) {
      PViewData *data = PView::list[nb]->getData();
      PViewOptions *opt = PView::list[nb]->getOptions();
      
      Fl_Light_Button *b1 = new Fl_Light_Button(0, _MH + nb * BH, width - popw, BH);
      b1->callback(view_toggle_cb, (void *)nb);
      b1->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      b1->value(opt->Visible);
      b1->copy_label(data->getName().c_str());
      b1->tooltip(data->getFileName().c_str());
      
      char *tmp = new char[32];
      sprintf(tmp, "[%d]@#-1>", nb);
      Fl_Button *b2 = new Fl_Button(width - popw, _MH + nb * BH, popw, BH, tmp);
      label.push_back(tmp);
      b2->align(FL_ALIGN_RIGHT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
      b2->tooltip("Show view option menu (Shift+w)");
  
      popupButton *p[2];
      p[0] = new popupButton(width - popw, _MH + nb * BH, popw, BH);
      p[0]->type(Fl_Menu_Button::POPUP123);
      p[1] = new popupButton(0, _MH + nb * BH, width - popw, BH);
      p[1]->type(Fl_Menu_Button::POPUP3);
  
      for(int j = 0; j < 2; j++) {
        p[j]->add("Reload/View", 'r', 
                  (Fl_Callback *) view_reload_cb, (void *)nb, 0);
        p[j]->add("Reload/Visible Views", 0, 
                  (Fl_Callback *) view_reload_visible_cb, (void *)nb, 0);
        p[j]->add("Reload/All Views", 0, 
                  (Fl_Callback *) view_reload_all_cb, (void *)nb, 0);
        p[j]->add("Remove/View", FL_Delete, 
                  (Fl_Callback *) view_remove_cb, (void *)nb, 0);
        p[j]->add("Remove/Other Views", 0, 
                  (Fl_Callback *) view_remove_other_cb, (void *)nb, 0);
        p[j]->add("Remove/Visible Views", 0, 
                  (Fl_Callback *) view_remove_visible_cb, (void *)nb, 0);
        p[j]->add("Remove/Invisible Views", 0, 
                  (Fl_Callback *) view_remove_invisible_cb, (void *)nb, 0);
        p[j]->add("Remove/Empty Views", 0, 
                  (Fl_Callback *) view_remove_empty_cb, (void *)nb, 0);
        p[j]->add("Remove/All Views", 0, 
                  (Fl_Callback *) view_remove_all_cb, (void *)nb, 0);
        p[j]->add("Alias/View without Options", 0, 
                  (Fl_Callback *) view_alias_cb, (void *)nb, 0);
        p[j]->add("Alias/View with Options", 0, 
                  (Fl_Callback *) view_alias_with_options_cb, (void *)nb, 0);
        p[j]->add("Combine Elements/From Visible Views", 0, 
                  (Fl_Callback *) view_combine_space_visible_cb, (void *)nb, 0);
        p[j]->add("Combine Elements/From All Views", 0, 
                  (Fl_Callback *) view_combine_space_all_cb, (void *)nb, 0);
        p[j]->add("Combine Elements/By View Name", 0, 
                  (Fl_Callback *) view_combine_space_by_name_cb, (void *)nb, 0);
        p[j]->add("Combine Time Steps/From Visible Views", 0, 
                  (Fl_Callback *) view_combine_time_visible_cb, (void *)nb, 0);
        p[j]->add("Combine Time Steps/From All Views", 0, 
                  (Fl_Callback *) view_combine_time_all_cb, (void *)nb, 0);
        p[j]->add("Combine Time Steps/By View Name", 0, 
                 (Fl_Callback *) view_combine_time_by_name_cb, (void *)nb, 0);
        p[j]->add("Set Visibility/All On", 0, 
                  (Fl_Callback *) view_all_visible_cb, (void *)1, 0);
        p[j]->add("Set Visibility/All Off", 0, 
                  (Fl_Callback *) view_all_visible_cb, (void *)0, 0);
        p[j]->add("Set Visibility/Invert", 0, 
                  (Fl_Callback *) view_all_visible_cb, (void *)-1, 0);
        p[j]->add("Save As/Parsed View...", 0, 
                  (Fl_Callback *) view_save_parsed_cb, (void *)nb, 0);
        p[j]->add("Save As/ASCII View...", 0, 
                  (Fl_Callback *) view_save_ascii_cb, (void *)nb, 0);
        p[j]->add("Save As/Binary View...", 0, 
                  (Fl_Callback *) view_save_binary_cb, (void *)nb, 0);
        p[j]->add("Save As/STL Triangulation...", 0, 
                  (Fl_Callback *) view_save_stl_cb, (void *)nb, 0);
        p[j]->add("Save As/Raw Text...", 0, 
                  (Fl_Callback *) view_save_txt_cb, (void *)nb, 0);
        p[j]->add("Save As/Gmsh Mesh...", 0, 
                  (Fl_Callback *) view_save_msh_cb, (void *)nb, 0);
#if defined(HAVE_MED)
        p[j]->add("Save As/MED file...", 0, 
                  (Fl_Callback *) view_save_med_cb, (void *)nb, 0);
#endif
        p[j]->add("Apply As Background Mesh", 0, 
                  (Fl_Callback *) view_applybgmesh_cb, (void *)nb, FL_MENU_DIVIDER);
        p[j]->add("Options...", 'o', 
                  (Fl_Callback *) view_options_cb, (void *)nb, 0);
        p[j]->add("Plugins...", 'p', 
                  (Fl_Callback *) view_plugin_cb, (void *)nb, 0);
      }

      toggle.push_back(b1);
      toggle2.push_back(b2);
      popup.push_back(p[0]);
      popup2.push_back(p[1]);
      scroll->add(b1);
      scroll->add(b2);
      scroll->add(p[0]);
      scroll->add(p[1]);
    }
  }
  else{ // geometry, mesh and solver contexts
    while(menu[nb + 1].label) {
      Fl_Button *b = new Fl_Button(0, _MH + nb * BH, width, BH);
      b->copy_label(menu[nb + 1].label);
      b->callback(menu[nb + 1].callback, menu[nb + 1].arg);
      push.push_back(b);
      scroll->add(b);
      nb++;
    }
  }

  scroll->redraw();

  if(nb <= NB_BUTT_SCROLL)
    win->size(width, _MH + nb * BH);
  else
    win->size(width, _MH + NB_BUTT_SCROLL * BH);
}
