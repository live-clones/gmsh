// $Id: Callbacks.cpp,v 1.64 2001-07-18 07:36:36 geuzaine Exp $

#include <sys/types.h>
#include <signal.h>
#include <map>
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Verif.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Timer.h"
#include "Visibility.h"
#include "CreateFile.h"
#include "OpenFile.h"
#include "GetOptions.h"
#include "Context.h"
#include "Options.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Plugin.h"

#include <FL/fl_file_chooser.H>
#include <errno.h>

extern GUI       *WID;
extern Mesh       M;
extern Context_T  CTX;

// Compatibility/local routines

int AddViewInUI(int i, char *Name, int Num){
  if(i > NB_BUTT_MAX -1) return 1;
  if(WID && (WID->get_context() == 3))
    WID->set_context(menu_post,0);
  return 0;
}

int SetGlobalShortcut(int event){
  return WID->global_shortcuts(event);
}

int SelectContour (int type, int num, List_T *Liste1){
  int      k,ip,i;
  List_T  *Liste2;

  Liste2 = List_Create(1,1,sizeof(int));

  if(!List_Nbr(Liste1)){
    switch(type){
    case ENT_LINE    : k = alledgeslinked (num, Liste1, (List_T*)NULL); break;
    case ENT_SURFACE : k = allfaceslinked (num, Liste1, (List_T*)NULL); break;
    }
  }
  else{
    List_Reset(Liste2);
    for(i=0;i<List_Nbr(Liste1);i++)
      List_Add(Liste2,List_Pointer(Liste1,i));
    List_Reset(Liste1);
    switch(type){
    case ENT_LINE    : k = alledgeslinked (num, Liste1, Liste2); break;
    case ENT_SURFACE : k = allfaceslinked (num, Liste1, Liste2); break;
    }
  }

  for(i=0;i<List_Nbr(Liste1);i++){
    List_Read(Liste1,i,&ip);
    switch(type){
    case ENT_LINE    : HighlightEntityNum(0,abs(ip),0,1); break ;
    case ENT_SURFACE : HighlightEntityNum(0,0,abs(ip),1); break ;
    }
  }

  Draw();//added July 18 2001 to overcome missing refreshes... Is this OK ?
  List_Delete(Liste2);
  return k;
}


// Common callbacks 

void cancel_cb(CALLBACK_ARGS){
  if(data) ((Fl_Window*)data)->hide();
}

void color_cb(CALLBACK_ARGS){
  unsigned int (*fct) (int, int, unsigned int);
  fct = (unsigned int (*) (int, int, unsigned int))data ;
  uchar r = UNPACK_RED(fct(0,GMSH_GET,0)) ; 
  uchar g = UNPACK_GREEN(fct(0,GMSH_GET,0)) ; 
  uchar b = UNPACK_BLUE(fct(0,GMSH_GET,0)) ; 
  if (fl_color_chooser("Color Chooser",r,g,b))
    fct(0,GMSH_SET|GMSH_GUI,PACK_COLOR(r,g,b,255));
  Draw();
}

// Graphical window 

void status_xyz1p_cb(CALLBACK_ARGS){

  extern void set_r(int i, double val);
  extern void set_t(int i, double val);
  extern void set_s(int i, double val);

  switch((int)data){
  case 0 : 
    if(CTX.useTrackball)
      CTX.setQuaternion(0.,-1./sqrt(2.),0.,1./sqrt(2.));
    set_r(0,0.);  set_r(1,90.);set_r(2,0.); 
    Draw(); 
    break;
  case 1 : 
    if(CTX.useTrackball)
      CTX.setQuaternion(1./sqrt(2.),0.,0.,1./sqrt(2.));
    set_r(0,-90.);set_r(1,0.); set_r(2,0.); 
    Draw(); 
    break;
  case 2 :
    if(CTX.useTrackball)
      CTX.setQuaternion(0.,0.,0.,1.);
    set_r(0,0.);  set_r(1,0.); set_r(2,0.); 
    Draw(); 
    break;
  case 3 : 
    set_t(0,0.);  set_t(1,0.); set_t(2,0.); 
    set_s(0,1.);  set_s(1,1.); set_s(2,1.); 
    Draw(); 
    break;
  case 4 :
    Print_Options(0,GMSH_FULLRC,NULL);
    WID->create_message_window();
    break ;
  }
}

static int stop_anim ;
void status_play_cb(CALLBACK_ARGS){
  static long anim_time ;
  int i;
  WID->set_anim(0);
  stop_anim = 0 ;
  anim_time = GetTime();
  while(1){
    if(stop_anim) break ;
    if(GetTime() - anim_time > 1.e6*CTX.post.anim_delay){
      anim_time = GetTime();
      for(i=0 ; i<List_Nbr(Post_ViewList) ; i++)
	opt_view_timestep(i, GMSH_SET|GMSH_GUI, opt_view_timestep(i, GMSH_GET, 0)+1);
      Draw();
    }
    WID->check();
  }
}

void status_pause_cb(CALLBACK_ARGS){
  stop_anim = 1;
  WID->set_anim(1);
}

void status_cancel_cb(CALLBACK_ARGS){
}

// File Menu

void file_open_cb(CALLBACK_ARGS) {
  char *newfile;
  int n = List_Nbr(Post_ViewList);
  newfile = fl_file_chooser("Open file", "*", NULL);
  if (newfile != NULL) {
    OpenProblem(newfile); 
    Draw(); 
  }
  if(n != List_Nbr(Post_ViewList))
    WID->set_context(menu_post, 0);
}

void file_merge_cb(CALLBACK_ARGS) {
  char *newfile;
  int n = List_Nbr(Post_ViewList);
  newfile = fl_file_chooser("Merge file", "*", NULL);
  if (newfile != NULL) {
    MergeProblem(newfile); 
    Draw(); 
  }
  if(n != List_Nbr(Post_ViewList))
    WID->set_context(menu_post, 0);
}

void file_save_as_auto_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save file by extension", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_AUTO); 
}

void file_save_as_geo_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GEO file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GEO); 
}

void file_save_as_geo_options_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save options file", "*", NULL)))
    Print_Options(0,GMSH_FULLRC, newfile); 
}

void file_save_as_msh_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save MSH file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_MSH); 
}
void file_save_as_unv_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save UNV file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_UNV); 
}
void file_save_as_gref_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GREF file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_GREF); 
}
void file_save_as_eps_simple_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save EPS file", "*", NULL))){
    CTX.print.eps_quality = 1; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_EPS); 
  }
}
void file_save_as_eps_accurate_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save EPS file", "*", NULL))){
    CTX.print.eps_quality = 2; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_EPS); 
  }
}
void file_save_as_jpeg_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save JPEG file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_JPEG); 
}

void file_save_as_gif_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF file", "*", NULL))){
    CTX.print.gif_dither = 0;
    CTX.print.gif_transparent = 0;
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GIF); 
  }
}
void file_save_as_gif_dithered_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF file", "*", NULL))){
    CTX.print.gif_dither = 1; 
    CTX.print.gif_transparent = 0; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GIF); 
  }
}
void file_save_as_gif_transparent_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF file", "*", NULL))){
    CTX.print.gif_dither = 0;
    CTX.print.gif_transparent = 1; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GIF);
  }
}
void file_save_as_ppm_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save PPM file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_PPM); 
}
void file_save_as_yuv_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save YUV file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_YUV); 
}

void file_quit_cb(CALLBACK_ARGS) {
  Exit(0);
}

// Option General Menu

void opt_general_cb(CALLBACK_ARGS) {
  WID->create_general_options_window();
}
void opt_general_color_scheme_cb(CALLBACK_ARGS){
  opt_general_color_scheme(0,GMSH_SET, WID->gen_value[0]->value());
  Draw();
}
void opt_general_ok_cb(CALLBACK_ARGS){
  opt_general_axes(0, GMSH_SET, WID->gen_butt[0]->value());
  opt_general_small_axes(0, GMSH_SET, WID->gen_butt[1]->value());
  opt_general_fast_redraw(0, GMSH_SET, WID->gen_butt[2]->value());
  if(opt_general_double_buffer(0, GMSH_GET, 0) != WID->gen_butt[3]->value())
    opt_general_double_buffer(0, GMSH_SET, WID->gen_butt[3]->value());
  opt_general_display_lists(0, GMSH_SET, WID->gen_butt[4]->value());
  opt_general_alpha_blending(0, GMSH_SET, WID->gen_butt[5]->value());
  opt_general_trackball(0, GMSH_SET, WID->gen_butt[6]->value());
  opt_general_terminal(0, GMSH_SET, WID->gen_butt[7]->value());
  double sessionrc = opt_general_session_save(0, GMSH_GET, 0);
  opt_general_session_save(0, GMSH_SET, WID->gen_butt[8]->value());
  if(sessionrc && !opt_general_session_save(0, GMSH_GET, 0))
    Print_Options(0, GMSH_SESSIONRC, CTX.sessionrc_filename);
  opt_general_options_save(0, GMSH_SET, WID->gen_butt[9]->value());
  opt_general_orthographic(0, GMSH_SET, WID->gen_butt[10]->value());
  opt_general_moving_light(0, GMSH_SET, WID->gen_butt[12]->value());

  opt_general_shine(0, GMSH_SET, WID->gen_value[1]->value());
  opt_general_light00(0, GMSH_SET, WID->gen_value[2]->value());
  opt_general_light01(0, GMSH_SET, WID->gen_value[3]->value());
  opt_general_light02(0, GMSH_SET, WID->gen_value[4]->value());
  opt_general_verbosity(0, GMSH_SET, WID->gen_value[5]->value());

  opt_general_default_filename(0, GMSH_SET, (char*)WID->gen_input[0]->value());
  opt_general_tmp_filename(0, GMSH_SET, (char*)WID->gen_input[1]->value());
  opt_general_error_filename(0, GMSH_SET, (char*)WID->gen_input[2]->value());
  opt_general_options_filename(0, GMSH_SET, (char*)WID->gen_input[3]->value());

  Draw();
}

// Option Geometry Menu

void opt_geometry_cb(CALLBACK_ARGS) {
  WID->create_geometry_options_window();
}
void opt_geometry_show_by_entity_num_cb(CALLBACK_ARGS) {
  char * c = (char*)((Fl_Input*)w)->value(); 
  if (!strcmp(c,"all") || !strcmp(c,"*")){
    if(SHOW_ALL_ENTITIES){ RemplirEntitesVisibles(0); SHOW_ALL_ENTITIES = 0; }
    else { RemplirEntitesVisibles(1); SHOW_ALL_ENTITIES = 1; }
  }
  else{ 
    int i = atoi(c);
    if(EntiteEstElleVisible(i)) ToutesLesEntitesRelatives(i,EntitesVisibles,0);
    else ToutesLesEntitesRelatives(i,EntitesVisibles,1);
  }
  Draw();
}
void opt_geometry_color_scheme_cb(CALLBACK_ARGS){
  opt_geometry_color_scheme(0,GMSH_SET, WID->geo_value[2]->value());
  Draw();
}
void opt_geometry_ok_cb(CALLBACK_ARGS) {
  opt_geometry_points(0, GMSH_SET, WID->geo_butt[0]->value());
  opt_geometry_lines(0, GMSH_SET, WID->geo_butt[1]->value());
  opt_geometry_surfaces(0, GMSH_SET, WID->geo_butt[2]->value());
  opt_geometry_volumes(0, GMSH_SET, WID->geo_butt[3]->value());
  opt_geometry_points_num(0, GMSH_SET, WID->geo_butt[4]->value());
  opt_geometry_lines_num(0, GMSH_SET, WID->geo_butt[5]->value());
  opt_geometry_surfaces_num(0, GMSH_SET, WID->geo_butt[6]->value());
  opt_geometry_volumes_num(0, GMSH_SET, WID->geo_butt[7]->value());

  opt_geometry_normals(0, GMSH_SET, WID->geo_value[0]->value());
  opt_geometry_tangents(0, GMSH_SET, WID->geo_value[1]->value());
  Draw();
}

// Option Mesh Menu

void opt_mesh_cb(CALLBACK_ARGS) {
  WID->create_mesh_options_window();
}
void opt_mesh_show_by_entity_num_cb(CALLBACK_ARGS) {
  opt_geometry_show_by_entity_num_cb(w,data);
}
void opt_mesh_color_scheme_cb(CALLBACK_ARGS){
  opt_mesh_color_scheme(0,GMSH_SET, WID->mesh_value[10]->value());
  Draw();
}
void opt_mesh_ok_cb(CALLBACK_ARGS) {
  opt_mesh_degree(0, GMSH_SET, WID->mesh_butt[0]->value()?2:1);
  opt_mesh_interactive(0, GMSH_SET, WID->mesh_butt[1]->value());
  opt_mesh_algo(0, GMSH_SET, WID->mesh_butt[2]->value()?DELAUNAY_NEWALGO:DELAUNAY_OLDALGO);
  opt_mesh_constrained_bgmesh(0, GMSH_SET, WID->mesh_butt[3]->value());
  opt_mesh_points(0, GMSH_SET, WID->mesh_butt[4]->value());
  opt_mesh_lines(0, GMSH_SET, WID->mesh_butt[5]->value());
  opt_mesh_surfaces(0, GMSH_SET, WID->mesh_butt[6]->value());
  opt_mesh_volumes(0, GMSH_SET, WID->mesh_butt[7]->value());
  opt_mesh_points_num(0, GMSH_SET, WID->mesh_butt[8]->value());
  opt_mesh_lines_num(0, GMSH_SET, WID->mesh_butt[9]->value());
  opt_mesh_surfaces_num(0, GMSH_SET, WID->mesh_butt[10]->value());
  opt_mesh_volumes_num(0, GMSH_SET, WID->mesh_butt[11]->value());
  opt_mesh_aspect(0, GMSH_SET, 
		  WID->mesh_butt[12]->value()?0:
		  WID->mesh_butt[13]->value()?1:
		  2);
  opt_mesh_color_carousel(0, GMSH_SET, WID->mesh_butt[15]->value());

  opt_mesh_nb_smoothing(0, GMSH_SET, WID->mesh_value[0]->value());
  opt_mesh_scaling_factor(0, GMSH_SET, WID->mesh_value[1]->value());
  opt_mesh_lc_factor(0, GMSH_SET, WID->mesh_value[2]->value());
  opt_mesh_rand_factor(0, GMSH_SET, WID->mesh_value[3]->value());
  opt_mesh_gamma_inf(0, GMSH_SET, WID->mesh_value[4]->value());
  opt_mesh_gamma_sup(0, GMSH_SET, WID->mesh_value[5]->value());
  opt_mesh_radius_inf(0, GMSH_SET, WID->mesh_value[6]->value());
  opt_mesh_radius_sup(0, GMSH_SET, WID->mesh_value[7]->value());
  opt_mesh_normals(0, GMSH_SET, WID->mesh_value[8]->value());
  opt_mesh_explode(0, GMSH_SET, WID->mesh_value[9]->value());

  Draw();
}

// Option Solver Menu

void opt_solver_cb(CALLBACK_ARGS) {
  WID->create_solver_options_window();
}
void opt_solver_ok_cb(CALLBACK_ARGS) {
}

// Option Post Menu

void opt_post_cb(CALLBACK_ARGS) {
  WID->create_post_options_window();
}
void opt_post_ok_cb(CALLBACK_ARGS) {
  opt_post_link(0, GMSH_SET, WID->post_butt[0]->value()?0:(WID->post_butt[1]->value()?1:2));
  opt_post_smooth(0, GMSH_SET, WID->post_butt[3]->value());

  opt_post_anim_delay(0, GMSH_SET, WID->post_value[0]->value());
  Draw();
}

// Option Statistics Menu

void opt_statistics_cb(CALLBACK_ARGS) {
  WID->create_statistics_window();
}
void opt_statistics_update_cb(CALLBACK_ARGS) {
  WID->set_statistics();
}
void opt_statistics_histogram_cb(CALLBACK_ARGS) {
  Print_Histogram(M.Histogram[(int)data]);
  WID->create_message_window();
}

// Option Messages Menu

void opt_message_cb(CALLBACK_ARGS) {
  WID->create_message_window();
}
void opt_message_clear_cb(CALLBACK_ARGS) {
  WID->msg_browser->clear();
}
void opt_message_save_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save messages", "*", NULL)))
    WID->save_message(newfile); 
}
void opt_save_cb(CALLBACK_ARGS) {
  Print_Options(0,GMSH_OPTIONSRC, CTX.optionsrc_filename); 
}

// Help Menu

void help_short_cb(CALLBACK_ARGS){
  Msg(DIRECT, "");
  Msg(DIRECT, "Mouse:");
  Msg(DIRECT, "");
  Msg(DIRECT, "  move          - highlight the elementary geometrical entity");
  Msg(DIRECT, "                  currently under the mouse pointer and display");
  Msg(DIRECT, "                  its properties in the status bar");
  Msg(DIRECT, "                - size a rubber zoom started with Ctrl+mouse1");
  Msg(DIRECT, "  mouse1        - rotate");
  Msg(DIRECT, "                - accept a rubber zoom started with Ctrl+mouse1"); 
  Msg(DIRECT, "  Ctrl+mouse1   start (anisotropic) rubber zoom"); 
  Msg(DIRECT, "  Shift+mouse1  - zoom (isotropic)");
  Msg(DIRECT, "                - cancel a rubber zoom");
  Msg(DIRECT, "  mouse2        same as Shift+mouse1");
  Msg(DIRECT, "  Ctrl+mouse2   orthogonalize display"); 
  Msg(DIRECT, "  mouse3        - pan");
  Msg(DIRECT, "                - cancel a rubber zoom");
  Msg(DIRECT, "                - pop up menu on post-processing view button");
  Msg(DIRECT, "  Ctrl+mouse3   reset to default viewpoint");   
  Msg(DIRECT, "");
  Msg(DIRECT, "Menu bar shortcuts:");
  Msg(DIRECT, "");
  Msg(DIRECT, "  b             go back to previous context");
  Msg(DIRECT, "  f             go forward to next context");
  Msg(DIRECT, "  g             go to geometry module");
  Msg(DIRECT, "  Shift+g       show geometry options");
  Msg(DIRECT, "  Shift+i       show statistics window"); 
  Msg(DIRECT, "  m             go to mesh module");
  Msg(DIRECT, "  Shift+m       show mesh options");
  Msg(DIRECT, "  Ctrl+m        merge file"); 
  Msg(DIRECT, "  Shift+o       show general options"); 
  Msg(DIRECT, "  Ctrl+o        open file"); 
  Msg(DIRECT, "  p             go to post-processor module");
  Msg(DIRECT, "  Shift+p       show post-processing general options");
  Msg(DIRECT, "  Ctrl+p        save file by extension");
  Msg(DIRECT, "  Ctrl+q        quit");
  Msg(DIRECT, "  Ctrl+s        save mesh in default format");
  Msg(DIRECT, "");
  Msg(DIRECT, "Other shortcuts");
  Msg(DIRECT, "");
  Msg(DIRECT, "  0 or Esc      reload geometry input file");
  Msg(DIRECT, "  1 or F1       mesh curves");
  Msg(DIRECT, "  2 or F2       mesh surfaces");
  Msg(DIRECT, "  3 or F3       mesh volumes");
  Msg(DIRECT, "  Alt+a         hide/show small axes"); 
  Msg(DIRECT, "  Alt+Shift+a   hide/show big moving axes"); 
  Msg(DIRECT, "  Alt+b         hide/show all post-processing scales");
  Msg(DIRECT, "  Alt+c         alternate between predefined color schemes");
  Msg(DIRECT, "  Alt+d         alternate between mesh wire frame, hidden lines and shading modes");
  Msg(DIRECT, "  Shift+d       decrease animation delay");
  Msg(DIRECT, "  Ctrl+Shift+d  increase animation delay");
  Msg(DIRECT, "  Alt+f         toggle redraw mode (fast/full)"); 
  Msg(DIRECT, "  Alt+h         toggle visibility for all post-processing views"); 
  Msg(DIRECT, "  Alt+l         hide/show geometry lines");
  Msg(DIRECT, "  Alt+Shift+l   hide/show mesh lines");
  Msg(DIRECT, "  Alt+m         toggle visibility of all mesh entities");
  Msg(DIRECT, "  Alt+o         change projection mode");
  Msg(DIRECT, "  Alt+p         hide/show geometry points");
  Msg(DIRECT, "  Alt+Shift+p   hide/show mesh points");
  Msg(DIRECT, "  Alt+s         hide/show geometry surfaces");
  Msg(DIRECT, "  Alt+Shift+s   hide/show mesh surfaces");
  Msg(DIRECT, "  Alt+t         alternate intervals mode for all post-processing views"); 
  Msg(DIRECT, "  Alt+v         hide/show geometry volumes");
  Msg(DIRECT, "  Alt+Shift+v   hide/show mesh volumes");
  Msg(DIRECT, "  Alt+x         set X view"); 
  Msg(DIRECT, "  Alt+y         set Y view"); 
  Msg(DIRECT, "  Alt+z         set Z view"); 
  Msg(DIRECT, "");
  WID->create_message_window();
}
void help_command_line_cb(CALLBACK_ARGS){
  Msg(DIRECT, "");
  Print_Usage("gmsh");
  WID->create_message_window();
}
void help_about_cb(CALLBACK_ARGS){
  WID->create_about_window();
}

// Module Menu

void mod_geometry_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry, 0);
}
void mod_mesh_cb(CALLBACK_ARGS){
  WID->set_context(menu_mesh, 0);
}
void mod_solver_cb(CALLBACK_ARGS){
  WID->set_context(menu_solver, 0);
}
void mod_post_cb(CALLBACK_ARGS){
  WID->set_context(menu_post, 0);
}
void mod_back_cb(CALLBACK_ARGS){
  WID->set_context(NULL, -1);
}
void mod_forward_cb(CALLBACK_ARGS){
  WID->set_context(NULL, 1);
}

// Dynamic Geomtry Menus

void geometry_elementary_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary, 0);
}
void geometry_physical_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_physical, 0);
}
void geometry_edit_cb(CALLBACK_ARGS){
  char cmd[1000];
  sprintf(cmd, CTX.editor, CTX.filename);
  Msg(INFO, "Starting text editor '%s'", cmd);
  system(cmd);
} 
void geometry_reload_cb(CALLBACK_ARGS){
  OpenProblem(CTX.filename);
  Draw();
} 
void geometry_elementary_add_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add, 0);
}
void geometry_elementary_add_new_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_new, 0);
}
void geometry_elementary_add_new_parameter_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(0);
}
void geometry_elementary_add_new_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(1);
}

static void _new_line_spline(int dim){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib;
  static int n, p[100];

  if(!opt_geometry_points(0,GMSH_GET,0)){
    opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
    Draw();
  }

  n = 0;
  while(1){
    Msg(STATUS3N,"Select Point ('e'=end, 'q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1){ /* left mouse butt */
      p[n++] = v->Num; 
    }
    if (ib == -1){ /* 'e' */
      if(n >= 2) {
	switch(dim){
	case 0 : add_multline(n,p,CTX.filename); break;
	case 1 : add_spline(n,p,CTX.filename); break;
	}
      }
      n=0;
      ZeroHighlight(&M);
      Draw();
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      Draw();
      break;
    }
  }
  Msg(STATUS3N,"Ready");
}

void geometry_elementary_add_new_line_cb(CALLBACK_ARGS){
  _new_line_spline(0);
}
void geometry_elementary_add_new_spline_cb(CALLBACK_ARGS){
  _new_line_spline(1);
}
void geometry_elementary_add_new_circle_cb(CALLBACK_ARGS){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib;
  static int n, p[100];

  if(!opt_geometry_points(0,GMSH_GET,0)){
    opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
    Draw();
  }

  n=0;
  while(1){
    if(n == 0) Msg(STATUS3N,"Select center Point ('q'=quit)");
    if(n == 1) Msg(STATUS3N,"Select start Point ('q'=quit)");
    if(n == 2) Msg(STATUS3N,"Select end Point ('q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1) { /* left mouse butt */
      p[n++] = v->Num; 
    }
    if(ib == 0) { /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      Draw();
      break;
    }
    if(n == 3){
      add_circ(p[1],p[0],p[2],CTX.filename); /* begin, center, end */
      ZeroHighlight(&M);
      Draw();
      n=0;
    }
  }
  Msg(STATUS3N,"Ready");
}
void geometry_elementary_add_new_ellipsis_cb(CALLBACK_ARGS){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib;
  static int n, p[100];

  if(!opt_geometry_points(0,GMSH_GET,0)){
    opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
    Draw();
  }

  n=0;
  while(1){
    if(n == 0) Msg(STATUS3N,"Select center Point ('q'=quit)");
    if(n == 1) Msg(STATUS3N,"Select axis Point ('q'=quit)");
    if(n == 2) Msg(STATUS3N,"Select start Point ('q'=quit)");
    if(n == 3) Msg(STATUS3N,"Select end Point ('q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1) { /* left mouse butt */
      p[n++] = v->Num; 
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      Draw();
      break;
    }
    if(n == 4){
      add_ell(p[3],p[2],p[0],p[1],CTX.filename);
      ZeroHighlight(&M);
      Draw();
      n=0;
    }
  }
  Msg(STATUS3N,"Ready");
}

static void _new_surface_volume(int mode){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib, type, zone;
  List_T  *Liste1, *Liste2;

  Liste1 = List_Create(10,10,sizeof(int));
  Liste2 = List_Create(10,10,sizeof(int));
  
  if(mode == 2){
    type = ENT_SURFACE;
    if(!opt_geometry_surfaces(0,GMSH_GET,0)){
      opt_geometry_surfaces(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  else{
    type = ENT_LINE;
    if(!opt_geometry_lines(0,GMSH_GET,0)){
      opt_geometry_lines(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  
  while(1){      
    List_Reset(Liste1);
    List_Reset(Liste2);
    
    while(1) {        
      Msg(STATUS3N,"Select boundary ('q'=quit)");
      ib = SelectEntity(type, &v,&c,&s);
      if(ib <= 0){
	ZeroHighlight(&M);
	Draw();
	goto stopall;
      }       
      if(SelectContour (type, (type==ENT_LINE)?c->Num:s->Num, Liste1)){
	if(type==ENT_LINE) 
	  add_loop(Liste1,CTX.filename,&zone);
	else
	  add_vol(Liste1,CTX.filename,&zone);
	List_Reset(Liste1);
	List_Add(Liste2,&zone);
	while(1){
	  Msg(STATUS3N,"Select holes ('q'=quit)");
	  ib = SelectEntity(type, &v,&c,&s); 
	  if(ib <= 0){
	    ZeroHighlight(&M);
	    Draw();
	    break;
	  }
	  if(SelectContour (type, (type==ENT_LINE)?c->Num:s->Num, Liste1)){
	    if(type==ENT_LINE) 
	      add_loop(Liste1,CTX.filename,&zone);
	    else
	      add_vol(Liste1,CTX.filename,&zone);
	    List_Reset(Liste1);
	    List_Add(Liste2,&zone);
	  }
	}
	if(List_Nbr(Liste2)){
	  switch(mode){
	  case 0 : add_surf(Liste2,CTX.filename,0,2); break;
	  case 1 : add_surf(Liste2,CTX.filename,0,1); break;
	  case 2 : add_multvol(Liste2,CTX.filename); break;
	  }
	  ZeroHighlight(&M);
	  Draw();
	  break;
	}
      }
    }
  }
  stopall : ;
  List_Delete(Liste1);
  List_Delete(Liste2);
  Msg(STATUS3N,"Ready");
}

void geometry_elementary_add_new_planesurface_cb(CALLBACK_ARGS){
  _new_surface_volume(0);
}
void geometry_elementary_add_new_ruledsurface_cb(CALLBACK_ARGS){
  _new_surface_volume(1);
}
void geometry_elementary_add_new_volume_cb(CALLBACK_ARGS){
  _new_surface_volume(2);
}

static void _transform_point_curve_surface(int transfo, int mode, char *what){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int type, num;

  if(!strcmp(what,"Point")) {
    type = ENT_POINT;
    if(!opt_geometry_points(0,GMSH_GET,0)){
      opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  else if(!strcmp(what,"Line")){
    type = ENT_LINE; 
    if(!opt_geometry_lines(0,GMSH_GET,0)){
      opt_geometry_lines(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  else{
    type = ENT_SURFACE;
    if(!opt_geometry_surfaces(0,GMSH_GET,0)){
      opt_geometry_surfaces(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }

  while(1){
    Msg(STATUS3N,"Select %s ('q'=quit)", what);
    if(!SelectEntity(type, &v,&c,&s)){
      ZeroHighlight(&M);
      Draw();
      break;
    }
    switch(type){
    case ENT_POINT: num = v->Num; break;
    case ENT_LINE: num = c->Num; break;
    case ENT_SURFACE: num = s->Num; break;
    }
    switch(transfo){
    case 0: translate(mode,num,CTX.filename,what); break;
    case 1: rotate(mode,num,CTX.filename,what); break;
    case 2: dilate(mode,num,CTX.filename,what); break;
    case 3: symmetry(mode,num,CTX.filename,what); break;
    case 4: extrude(num,CTX.filename,what); break;
    case 5: protude(num,CTX.filename,what); break;
    case 6: delet(num,CTX.filename,what); break;
    }
    ZeroHighlight(&M);
    Draw();
  }
  Msg(STATUS3N,"Ready");
}

void geometry_elementary_add_translate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_translate, 0);
}
void geometry_elementary_add_translate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(0,1,"Point");
}
void geometry_elementary_add_translate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(0,1,"Line");
}
void geometry_elementary_add_translate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(0,1,"Surface");
}
void geometry_elementary_translate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_translate, 0);
}
void geometry_elementary_translate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(0,0,"Point");
}
void geometry_elementary_translate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(0,0,"Line");
}
void geometry_elementary_translate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(0,0,"Surface");
}

void geometry_elementary_add_rotate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_rotate, 0);
}
void geometry_elementary_add_rotate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(1,1,"Point");
}
void geometry_elementary_add_rotate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(1,1,"Line");
}
void geometry_elementary_add_rotate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(1,1,"Surface");
}
void geometry_elementary_rotate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_rotate, 0);
}
void geometry_elementary_rotate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(1,0,"Point");
}
void geometry_elementary_rotate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(1,0,"Line");
}
void geometry_elementary_rotate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(1,0,"Surface");
}

void geometry_elementary_add_scale_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_scale, 0);
}
void geometry_elementary_add_scale_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  _transform_point_curve_surface(2,1,"Point");
}
void geometry_elementary_add_scale_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  _transform_point_curve_surface(2,1,"Line");
}
void geometry_elementary_add_scale_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  _transform_point_curve_surface(2,1,"Surface");
}
void geometry_elementary_scale_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_scale, 0);
}
void geometry_elementary_scale_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  _transform_point_curve_surface(2,0,"Point");
}
void geometry_elementary_scale_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  _transform_point_curve_surface(2,0,"Line");
}
void geometry_elementary_scale_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  _transform_point_curve_surface(2,0,"Surface");
}

void geometry_elementary_add_symmetry_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_symmetry, 0);
}
void geometry_elementary_add_symmetry_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  _transform_point_curve_surface(3,1,"Point");
}
void geometry_elementary_add_symmetry_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  _transform_point_curve_surface(3,1,"Line");
}
void geometry_elementary_add_symmetry_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  _transform_point_curve_surface(3,1,"Surface");
}
void geometry_elementary_symmetry_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_symmetry, 0);
}
void geometry_elementary_symmetry_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  _transform_point_curve_surface(3,0,"Point");
}
void geometry_elementary_symmetry_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  _transform_point_curve_surface(3,0,"Line");
}
void geometry_elementary_symmetry_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  _transform_point_curve_surface(3,0,"Surface");
}

void geometry_elementary_extrude_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_extrude, 0);
}
void geometry_elementary_extrude_translate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_extrude_translate, 0);
}
void geometry_elementary_extrude_translate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(4,0,"Point");
}
void geometry_elementary_extrude_translate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(4,0,"Line");
}
void geometry_elementary_extrude_translate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  _transform_point_curve_surface(4,0,"Surface");
}
void geometry_elementary_extrude_rotate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_extrude_rotate, 0);
}
void geometry_elementary_extrude_rotate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(5,0,"Point");
}
void geometry_elementary_extrude_rotate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(5,0,"Line");
}
void geometry_elementary_extrude_rotate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  _transform_point_curve_surface(5,0,"Surface");
}

void geometry_elementary_delete_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_delete, 0);
}
void geometry_elementary_delete_point_cb(CALLBACK_ARGS){
  _transform_point_curve_surface(6,0,"Point");
}
void geometry_elementary_delete_curve_cb(CALLBACK_ARGS){
  _transform_point_curve_surface(6,0,"Line");
}
void geometry_elementary_delete_surface_cb(CALLBACK_ARGS){
  _transform_point_curve_surface(6,0,"Surface");
}

static void _add_physical(char *what){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib, type, zone;
  List_T  *Liste1;

  if(!strcmp(what,"Point")){
    type = ENT_POINT;
    if(!opt_geometry_points(0,GMSH_GET,0)){
      opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  else if(!strcmp(what,"Line")){
    type = ENT_LINE; 
    if(!opt_geometry_lines(0,GMSH_GET,0)){
      opt_geometry_lines(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  else if(!strcmp(what,"Surface")){
    type = ENT_SURFACE;
    if(!opt_geometry_surfaces(0,GMSH_GET,0)){
      opt_geometry_surfaces(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
  }
  else{
    Msg(GERROR, "Interactive volume selection not done "
	"(you will have to edit the input file manually)");
    if(!opt_geometry_volumes(0,GMSH_GET,0)){
      opt_geometry_volumes(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
    return;
  }

  Liste1 = List_Create(5,5,sizeof(int));
  while(1){
    Msg(STATUS3N,"Select %s ('e'=end, 'q'=quit)", what); 
    ib = SelectEntity(type, &v,&c,&s);
    if(ib == 1){ /* left mouse */
      switch(type){
      case ENT_POINT: List_Add(Liste1, &v->Num); break;
      case ENT_LINE:  List_Add(Liste1, &c->Num); break;
      case ENT_SURFACE:  List_Add(Liste1, &s->Num); break;
      }
    }
    if(ib == -1){ /* end */
      if(List_Nbr(Liste1)){
	add_physical(Liste1,CTX.filename,type,&zone);
	List_Reset(Liste1);
	ZeroHighlight(&M);
	Draw();
      }
    }
    if(ib == 0){
      ZeroHighlight(&M);
      Draw();
      break;
    }
  }
  Msg(STATUS3N,"Ready");
}

void geometry_physical_add_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_physical_add, 0);
}
void geometry_physical_add_point_cb (CALLBACK_ARGS){
  _add_physical("Point");
}
void geometry_physical_add_curve_cb (CALLBACK_ARGS){
  _add_physical("Line");
}
void geometry_physical_add_surface_cb (CALLBACK_ARGS){
  _add_physical("Surface");
}
void geometry_physical_add_volume_cb (CALLBACK_ARGS){
  _add_physical("Volume");
}

// Dynamic Mesh Menus

void mesh_save_cb(CALLBACK_ARGS) {
  Print_Mesh(&M, CTX.output_filename, CTX.mesh.format);
}
void mesh_define_cb(CALLBACK_ARGS){
  WID->set_context(menu_mesh_define, 0);
}
void mesh_1d_cb(CALLBACK_ARGS){
  mai3d(&M, 1); 
  Draw();
  Msg(STATUS3N,"Ready");
}
void mesh_2d_cb(CALLBACK_ARGS){
  mai3d(&M, 2);
  Draw();
  Msg(STATUS3N,"Ready");
} 
void mesh_3d_cb(CALLBACK_ARGS){
  mai3d(&M, 3); 
  Draw();
  Msg(STATUS3N,"Ready");
} 
void mesh_define_length_cb (CALLBACK_ARGS){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int       ib;
  static int n=0, p[100];

  if(!opt_geometry_points(0,GMSH_GET,0)){
    opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
    Draw();
  }

  WID->create_mesh_context_window(0);

  while(1){
    Msg(STATUS3N,"Select Point ('e'=end, 'q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1){ /* left mouse butt */
      p[n++] = v->Num; 
    }
    if (ib == -1){ /* 'e' */
      if(n >= 1) {
	add_charlength(n,p,CTX.filename); 
	n=0;
	ZeroHighlight(&M);
	Draw();
	break;
      }
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      Draw();
      break;
    }
  }
  Msg(STATUS3N,"Ready");
}
void mesh_define_recombine_cb (CALLBACK_ARGS){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib;
  static int n, p[100];

  if(!opt_geometry_surfaces(0,GMSH_GET,0)){
    opt_geometry_surfaces(0,GMSH_SET|GMSH_GUI,1);
    Draw();
  }

  n=0;
  while(1){
    Msg(STATUS3N,"Select Surface ('e'=end, 'q'=quit)");
    ib = SelectEntity(ENT_SURFACE, &v,&c,&s);
    if(ib == 1){ /* left mouse butt */
      p[n++] = s->Num; 
    }
    if (ib == -1){ /* 'e' */
      if(n >= 1) {
	add_recosurf(n,p,CTX.filename); break;
      }
      n=0;
      ZeroHighlight(&M);
      Draw();
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      Draw();
      break;
    }
  }
  Msg(STATUS3N, "Ready");
}
void mesh_define_transfinite_cb (CALLBACK_ARGS){
  WID->set_context(menu_mesh_define_transfinite, 0);
} 

static void _add_transfinite(int dim){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int      ib;
  static int n, p[100];

  if(!opt_geometry_points(0,GMSH_GET,0)){
    opt_geometry_points(0,GMSH_SET|GMSH_GUI,1);
    Draw();
  }

  switch (dim) {
  case 1 :
    if(!opt_geometry_lines(0,GMSH_GET,0)){
      opt_geometry_lines(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
    break ;
  case 2 :
    if(!opt_geometry_surfaces(0,GMSH_GET,0)){
      opt_geometry_surfaces(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
    break;
  case 3 :
    if(!opt_geometry_volumes(0,GMSH_GET,0)){
      opt_geometry_volumes(0,GMSH_SET|GMSH_GUI,1);
      Draw();
    }
    break;
  }
  
  n=0;
  while(1){
    switch (dim) {
    case 1 :
      Msg(STATUS3N,"Select Line ('e'=end, 'q'=quit)");
      ib = SelectEntity(ENT_LINE, &v,&c,&s);
      break ;
    case 2 :
      Msg(STATUS3N,"Select Surface ('e'=end, 'q'=quit)");
      ib = SelectEntity(ENT_SURFACE, &v,&c,&s);
      break;
    case 3 :
      ib = 1;
      break;
    }
    if(ib == 1){ /* left mouse butt */
      switch (dim) {    
      case 1 : p[n++] = c->Num ; break ;
      case 2 : p[n++] = s->Num; // fall-through
      case 3 :
	while(1){
	  Msg(STATUS3N,"Select Point ('e'=end, 'q'=quit)");
	  ib = SelectEntity(ENT_POINT, &v,&c,&s);
	  if(ib == 1){ /* left mouse butt */
	    p[n++] = v->Num ;
	  }
	  if (ib == -1){ /* 'e' */
	    switch (dim) {    
	    case 2 :
	      if(n == 3+1 || n == 4+1)
		add_trsfsurf(n,p,CTX.filename); 
	      else
		Msg(STATUS2, "Wrong number of points for Transfinite Surface");
	      break;
	    case 3 :
	      if(n == 6 || n == 8)
		add_trsfvol(n,p,CTX.filename);
	      else
		Msg(STATUS2, "Wrong number of points for Transfinite Volume");
	      break;
	    }
	    n=0;
	    ZeroHighlight(&M);
	    Draw();
	    break;
	  }
	  if(ib == 0){ /* 'q' */
	    n=0 ;
	    ZeroHighlight(&M);
	    Draw();
	    break;
	  }
	}
	break ;
      }
    }
    if (ib == -1){ /* 'e' */
      if (dim == 1){ 
	if(n >= 1) add_trsfline(n,p,CTX.filename);
      }
      n=0;
      ZeroHighlight(&M);
      Draw();
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      Draw();
      break;
    }
  }
  Msg(STATUS3N, "Ready");
}

void mesh_define_transfinite_line_cb(CALLBACK_ARGS){
  WID->create_mesh_context_window(1);
  _add_transfinite(1);
}
void mesh_define_transfinite_surface_cb(CALLBACK_ARGS){
  _add_transfinite(2);
}
void mesh_define_transfinite_volume_cb(CALLBACK_ARGS){
  WID->create_mesh_context_window(2);
  _add_transfinite(3);
} 

// Dynamic Solver Menus

#include "Solvers.h"

void getdp_cb(CALLBACK_ARGS){
  char file[256];
  static int first=1;
  if(first){
    first = 0;
    strcpy(file,CTX.base_filename);
    strcat(file,".pro");
    WID->getdp_input[0]->value(file);
  }
  GetDP((char*)WID->getdp_input[0]->value());
  WID->create_getdp_window();
}
void getdp_file_open_cb(CALLBACK_ARGS){
  char *newfile;
  newfile = fl_file_chooser("Open problem definition file", "*.[Pp][Rr][Oo]", NULL);
  if (newfile != NULL){
    WID->getdp_input[0]->value(newfile);
    GetDP(newfile);
  }
}
void getdp_file_edit_cb(CALLBACK_ARGS){
  char cmd[1000];
  sprintf(cmd, CTX.editor, WID->getdp_input[0]->value());
  Msg(INFO, "Starting text editor '%s'", cmd);
  system(cmd);
}
void getdp_choose_mesh_cb(CALLBACK_ARGS){
  char *newfile;
  newfile = fl_file_chooser("Open mesh file", "*.[Mm][Ss][Hh]", NULL);
  if (newfile != NULL) WID->getdp_input[1]->value(newfile);
}
void getdp_pre_cb(CALLBACK_ARGS){
  char arg[256];
  if(GetDP_Info.popupmessages) WID->create_message_window();
  if(strlen(WID->getdp_input[1]->value()))
    sprintf(arg, "%s -msh %s -pre %s", 
	    WID->getdp_input[0]->value(),
	    WID->getdp_input[1]->value(),
	    GetDP_Info.res[WID->getdp_choice[0]->value()]);
  else
    sprintf(arg, "%s -pre %s", 
	    WID->getdp_input[0]->value(), 
	    GetDP_Info.res[WID->getdp_choice[0]->value()]);

  GetDP(arg);
}
void getdp_cal_cb(CALLBACK_ARGS){
  char arg[256];
  if(GetDP_Info.popupmessages) WID->create_message_window();
  if(strlen(WID->getdp_input[1]->value()))
    sprintf(arg, "%s -msh %s -cal", 
	    WID->getdp_input[0]->value(),
	    WID->getdp_input[1]->value());
  else
    sprintf(arg, "%s -cal", WID->getdp_input[0]->value());
  GetDP(arg);
}
void getdp_post_cb(CALLBACK_ARGS){
  char arg[256];
  if(GetDP_Info.popupmessages) WID->create_message_window();
  if(strlen(WID->getdp_input[1]->value()))
    sprintf(arg, "%s -msh %s -bin -pos %s",
	    WID->getdp_input[0]->value(),
	    WID->getdp_input[1]->value(),
	    GetDP_Info.postop[WID->getdp_choice[1]->value()]);
  else
    sprintf(arg, "%s -bin -pos %s",
	    WID->getdp_input[0]->value(),
	    GetDP_Info.postop[WID->getdp_choice[1]->value()]);
  GetDP(arg);
}
void getdp_kill_cb(CALLBACK_ARGS){
  if(GetDP_Info.pid > 0){
    kill(GetDP_Info.pid, 9);
    Msg(INFO, "Killed GetDP pid %d", GetDP_Info.pid);
  }
  GetDP_Info.pid = -1;
}
void getdp_choose_command_cb(CALLBACK_ARGS){
  char *newfile;
#if defined(WIN32)
  newfile = fl_file_chooser("Choose executable", "*.[Ee][Xx][Ee]", NULL);
#else
  newfile = fl_file_chooser("Choose executable", "*", NULL);
#endif
  if (newfile != NULL) WID->getdp_input[2]->value(newfile);
}
void getdp_ok_cb(CALLBACK_ARGS){
  opt_solver_getdp_popupmessages(0, GMSH_SET, WID->getdp_butt[0]->value());
  opt_solver_getdp_mergeviews(0, GMSH_SET, WID->getdp_butt[1]->value());

  int retry=0;
  if(strcmp(opt_solver_getdp_command(0, GMSH_GET, NULL), 
	    WID->getdp_input[2]->value())) retry=1;
  opt_solver_getdp_command(0, GMSH_SET, (char*)WID->getdp_input[2]->value());
  if(retry) getdp_cb(NULL,NULL);
}


// Dynamic Post Menus

void view_toggle_cb(CALLBACK_ARGS){
  opt_view_visible((int)data, GMSH_SET, WID->m_toggle_butt[(int)data]->value());
  Draw();
}

static int RELOAD_ALL_VIEWS = 0 ;

void view_reload_all_cb(CALLBACK_ARGS) {
  if(!Post_ViewList) return;
  RELOAD_ALL_VIEWS = 1;
  for(int i = 0 ; i<List_Nbr(Post_ViewList) ; i++)
    view_reload_cb(NULL, (void *)i);
  RELOAD_ALL_VIEWS = 0;
  Draw();
}

void view_reload_cb(CALLBACK_ARGS){
  Post_View tmp ;
  char filename[NAME_STR_L];

  if(!Post_ViewList) return;

  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  strcpy(filename, v->FileName);
  CopyViewOptions(v, &tmp);

  Post_ViewForceNumber = v->Num ;
  FreeView(v);
  MergeProblem(filename);
  Post_ViewForceNumber = 0 ;
  
  v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  CopyViewOptions(&tmp, v);

  // In case the reloaded view has a different number of time steps
  if(v->TimeStep > v->NbTimeStep-1) v->TimeStep = 0;

  if(!RELOAD_ALL_VIEWS)
    Draw();
}

static int REMOVE_ALL_VIEWS = 0 ;

void view_remove_all_cb(CALLBACK_ARGS) {
  if(!Post_ViewList) return;
  REMOVE_ALL_VIEWS = 1;
  while(List_Nbr(Post_ViewList))
    view_remove_cb(NULL, (void*)0);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_cb(CALLBACK_ARGS){
  int i, play=0;

  FreeView((int)data);

  for(i=0 ; i<List_Nbr(Post_ViewList) ; i++)
    if(((Post_View*)List_Pointer(Post_ViewList,i))->NbTimeStep > 1){
      play = 1 ; 
      break ;
    }
  if(!play) WID->g_status_butt[5]->deactivate();

  if(WID->get_context() == 3)
    WID->set_context(menu_post, 0);  

  if(!REMOVE_ALL_VIEWS)
    Draw();
}

void view_save_ascii_cb(CALLBACK_ARGS){
  char *newfile;
  if((newfile = fl_file_chooser("Save view in ASCII format", "*", NULL)))
    Write_View(0, (Post_View*)List_Pointer(Post_ViewList,(int)data), newfile); 
}

void view_save_binary_cb(CALLBACK_ARGS){
  char *newfile;
  if((newfile = fl_file_chooser("Save view in binary format", "*", NULL)))
    Write_View(1, (Post_View*)List_Pointer(Post_ViewList,(int)data), newfile); 
}

static void _duplicate_view(int num, int options){
  Post_View  v, *v1, *v2, *v3 ;

  if(!Post_ViewList) return;

  v1 = (Post_View*)List_Pointer(Post_ViewList,num);

  BeginView(0);
  EndView(0, v1->FileName, v1->Name);

  v2 = (Post_View*)List_Pointer(Post_ViewList,List_Nbr(Post_ViewList)-1);

  if(!v1->DuplicateOf){
    v2->DuplicateOf = v1->Num ;
    v1->Links++ ;
  }
  else{
    v.Num = v1->DuplicateOf ;
    if(!(v3 = (Post_View*)List_PQuery(Post_ViewList, &v, fcmpPostViewNum))){
      v2->DuplicateOf = v1->Num ;
      v1->Links++ ;
    }
    else{
      v2->DuplicateOf = v3->Num;
      v3->Links++ ;
    }
  }

  v2->Time = v1->Time;
  v2->NbSP = v1->NbSP; v2->SP = v1->SP; 
  v2->NbVP = v1->NbVP; v2->VP = v1->VP; 
  v2->NbTP = v1->NbTP; v2->TP = v1->TP;
  v2->NbSL = v1->NbSL; v2->SL = v1->SL; 
  v2->NbVL = v1->NbVL; v2->VL = v1->VL; 
  v2->NbTL = v1->NbTL; v2->TL = v1->TL;
  v2->NbST = v1->NbST; v2->ST = v1->ST; 
  v2->NbVT = v1->NbVT; v2->VT = v1->VT; 
  v2->NbTT = v1->NbTT; v2->TT = v1->TT;
  v2->NbSS = v1->NbSS; v2->SS = v1->SS; 
  v2->NbVS = v1->NbVS; v2->VS = v1->VS; 
  v2->NbTS = v1->NbTS; v2->TS = v1->TS;
  v2->ScalarOnly  = v1->ScalarOnly;
  v2->Min         = v1->Min;       
  v2->Max         = v1->Max;      
  v2->NbTimeStep  = v1->NbTimeStep;

  if(options) CopyViewOptions(v1, v2);
  AddViewInUI(List_Nbr(Post_ViewList), v2->Name, v2->Num);
  Draw();
}
void view_duplicate_cb(CALLBACK_ARGS){
  _duplicate_view((int)data,0);
}
void view_duplicate_with_options_cb(CALLBACK_ARGS){
  _duplicate_view((int)data,1);
}

void view_applybgmesh_cb(CALLBACK_ARGS){
  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  if(!v->ScalarOnly){
    Msg(GERROR, "Background mesh generation impossible with non-scalar view");
    return;
  }
  BGMWithView(v); 
}
void view_options_cb(CALLBACK_ARGS){
  WID->create_view_options_window((int)data);
}

void view_plugin_cb(CALLBACK_ARGS){
  char name[256];
  std::pair<int,GMSH_Plugin*> *pair =  (std::pair<int,GMSH_Plugin*>*)data;
  int iView = pair->first;
  GMSH_Post_Plugin *p = (GMSH_Post_Plugin*)pair->second;
  p->getName(name);
  // here we should perhaps launch 
  // a dialogbox for setting up Plugin 
  // properties
  try
    {
      Post_View *v = (Post_View*)List_Pointer(Post_ViewList,iView);
      p->execute(v);
      Msg(INFO,"Plugin %s was called win = %p",name,p->dialogBox);
    }
  catch (GMSH_Plugin *err)
    {
      p->CatchErrorMessage(name);
      Msg(WARNING,"%s",name);
    }
  //
}

void view_options_plugin_cb(CALLBACK_ARGS){
  std::pair<int,GMSH_Plugin*> *pair =  (std::pair<int,GMSH_Plugin*>*)data;
  int iView = pair->first;
  GMSH_Plugin *p = pair->second;

  if(!p->dialogBox)p->dialogBox = WID->create_plugin_window(p,iView);

  Fl_Window *pwindow = p->dialogBox->main_window;


  if(pwindow->shown())
    pwindow->redraw();
  else
    pwindow->show();    
}

void view_options_custom_cb(CALLBACK_ARGS){
  if(WID->view_butt[0]->value()){
    WID->view_value[0]->activate();
    WID->view_value[1]->activate();
  }
  else{
    WID->view_value[0]->deactivate();
    WID->view_value[1]->deactivate();
  }
}

void view_options_timestep_cb(CALLBACK_ARGS){
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i=0 ; i<List_Nbr(Post_ViewList) ; i++){
    if((links == 2) ||
       (links == 1 && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (int)data)){
      opt_view_timestep(i, GMSH_SET, (int)((Fl_Value_Input*)w)->value());
    }
  }
  Draw();
}

void view_options_ok_cb(CALLBACK_ARGS){
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i=0 ; i<List_Nbr(Post_ViewList) ; i++){
    if((links == 2) ||
       (links == 1 && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (int)data)){
      opt_view_range_type(i, GMSH_SET, 
			  WID->view_butt[0]->value()?DRAW_POST_CUSTOM:
			  DRAW_POST_DEFAULT);
      opt_view_scale_type(i, GMSH_SET, 
			  WID->view_butt[1]->value()?DRAW_POST_LINEAR:
			  DRAW_POST_LOGARITHMIC);
      opt_view_intervals_type(i, GMSH_SET, 
			      WID->view_butt[3]->value()?DRAW_POST_ISO:
			      WID->view_butt[4]->value()?DRAW_POST_DISCRETE:
			      WID->view_butt[5]->value()?DRAW_POST_CONTINUOUS:
			      DRAW_POST_NUMERIC);
      opt_view_arrow_type(i, GMSH_SET, 
			  WID->view_butt[7]->value()?DRAW_POST_SEGMENT:
			  WID->view_butt[8]->value()?DRAW_POST_ARROW:
			  WID->view_butt[9]->value()?DRAW_POST_CONE:
			  DRAW_POST_DISPLACEMENT);
      opt_view_arrow_location(i, GMSH_SET, 
			      WID->view_butt[11]->value()?DRAW_POST_LOCATE_COG:
			      DRAW_POST_LOCATE_VERTEX);
      opt_view_show_element(i, GMSH_SET, WID->view_butt[13]->value());
      opt_view_show_scale(i, GMSH_SET, WID->view_butt[14]->value());
      opt_view_show_time(i, GMSH_SET, WID->view_butt[15]->value());
      opt_view_transparent_scale(i, GMSH_SET, WID->view_butt[16]->value());
      opt_view_light(i,GMSH_SET,WID->view_butt[17]->value());
      opt_view_draw_points(i, GMSH_SET, WID->view_butt[18]->value());
      opt_view_draw_lines(i, GMSH_SET, WID->view_butt[19]->value());
      opt_view_draw_triangles(i, GMSH_SET, WID->view_butt[20]->value());
      opt_view_draw_tetrahedra(i, GMSH_SET, WID->view_butt[21]->value());
      opt_view_draw_scalars(i, GMSH_SET, WID->view_butt[22]->value());
      opt_view_draw_vectors(i, GMSH_SET, WID->view_butt[23]->value());
      opt_view_draw_tensors(i, GMSH_SET, WID->view_butt[24]->value());
      
      opt_view_custom_min(i, GMSH_SET, WID->view_value[0]->value());
      opt_view_custom_max(i, GMSH_SET, WID->view_value[1]->value());
      opt_view_nb_iso(i, GMSH_SET, WID->view_value[2]->value());
      opt_view_offset0(i, GMSH_SET, WID->view_value[3]->value());
      opt_view_offset1(i, GMSH_SET, WID->view_value[4]->value());
      opt_view_offset2(i, GMSH_SET, WID->view_value[5]->value());
      opt_view_raise0(i, GMSH_SET, WID->view_value[6]->value());
      opt_view_raise1(i, GMSH_SET, WID->view_value[7]->value());
      opt_view_raise2(i, GMSH_SET, WID->view_value[8]->value());
      opt_view_timestep(i, GMSH_SET, WID->view_value[9]->value());
      opt_view_arrow_scale(i, GMSH_SET, WID->view_value[10]->value());
      opt_view_boundary(i, GMSH_SET, WID->view_value[11]->value());
      
      opt_view_name(i, GMSH_SET, (char*)WID->view_input[0]->value());
      opt_view_format(i, GMSH_SET, (char*)WID->view_input[1]->value());
    }
  }
  Draw();
}

// Contextual windows for geometry

void con_geometry_define_parameter_cb(CALLBACK_ARGS){
  add_param((char*)WID->context_geometry_input[0]->value(),
	    (char*)WID->context_geometry_input[1]->value(),
	    CTX.filename);
}

void con_geometry_define_point_cb(CALLBACK_ARGS){
  strcpy(x_text, (char*)WID->context_geometry_input[2]->value());
  strcpy(y_text, WID->context_geometry_input[3]->value());
  strcpy(z_text, WID->context_geometry_input[4]->value());
  strcpy(l_text, WID->context_geometry_input[5]->value());
  add_point(CTX.filename);
  ZeroHighlight(&M);
  Replot();
}

void con_geometry_define_translation_cb(CALLBACK_ARGS){
  strcpy(tx_text, WID->context_geometry_input[6]->value());
  strcpy(ty_text, WID->context_geometry_input[7]->value());
  strcpy(tz_text, WID->context_geometry_input[8]->value());
}

void con_geometry_define_rotation_cb(CALLBACK_ARGS){
  strcpy(px_text, WID->context_geometry_input[9]->value());
  strcpy(py_text, WID->context_geometry_input[10]->value());
  strcpy(pz_text, WID->context_geometry_input[11]->value());
  strcpy(ax_text, WID->context_geometry_input[12]->value());
  strcpy(ay_text, WID->context_geometry_input[13]->value());
  strcpy(az_text, WID->context_geometry_input[14]->value());
  strcpy(angle_text, WID->context_geometry_input[15]->value());
}

void con_geometry_define_scale_cb(CALLBACK_ARGS){
  strcpy(dx_text, WID->context_geometry_input[16]->value());
  strcpy(dy_text, WID->context_geometry_input[17]->value());
  strcpy(dz_text, WID->context_geometry_input[18]->value());
  strcpy(df_text, WID->context_geometry_input[19]->value());
}

void con_geometry_define_symmetry_cb(CALLBACK_ARGS){
  strcpy(sa_text, WID->context_geometry_input[20]->value());
  strcpy(sb_text, WID->context_geometry_input[21]->value());
  strcpy(sc_text, WID->context_geometry_input[22]->value());
  strcpy(sd_text, WID->context_geometry_input[23]->value());
}


// Contextual windows for mesh

void con_mesh_define_length_cb(CALLBACK_ARGS){
  strcpy(char_length_text, WID->context_mesh_input[0]->value());
}

void con_mesh_define_transfinite_line_cb(CALLBACK_ARGS){
  strcpy(trsf_pts_text, WID->context_mesh_input[1]->value());
  strcpy(trsf_type_text, WID->context_mesh_input[2]->value());
}

void con_mesh_define_transfinite_volume_cb(CALLBACK_ARGS){
  strcpy(trsf_vol_text, WID->context_mesh_input[3]->value());
}

