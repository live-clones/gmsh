// $Id: Callbacks.cpp,v 1.14 2001-01-11 12:25:23 geuzaine Exp $

#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Timer.h"
#include "Visibility.h"
#include "CreateFile.h"
#include "OpenFile.h"
#include "Context.h"
#include "GUI.h"
#include "Callbacks.h"

#include <FL/fl_file_chooser.H>

extern GUI       *WID;
extern Mesh       M;
extern Context_T  CTX;

// Compatibility routines

int AddViewInUI(int i, char *Name, int Num){
  if(i > NB_BUTT_MAX -1) return 1;
  if(WID->get_context() == 2)
    WID->set_context(menu_post,0);
  return 0;
}

void MarkAllViewsChanged(int action){
  int i;
  Post_View *v;

  for(i = 0 ; i< List_Nbr(Post_ViewList) ; i++){
    v = (Post_View*)List_Pointer(Post_ViewList, i);
    switch(action){
    case 1: // toggle drawing mode
      if(v->IntervalsType == DRAW_POST_ISO) 
        v->IntervalsType = DRAW_POST_DISCRETE ;
      else if(v->IntervalsType == DRAW_POST_DISCRETE) 
        v->IntervalsType = DRAW_POST_CONTINUOUS ;
      else 
        v->IntervalsType = DRAW_POST_ISO ;
      break;
    case 2: // time step++
      if(v->TimeStep < v->NbTimeStep-1)
        v->TimeStep++ ;
      else
        v->TimeStep = 0 ;
      break;
    case 3: // time step--
      if(v->TimeStep > 0)
        v->TimeStep-- ;
      else
        v->TimeStep = v->NbTimeStep-1 ;
    }
    v->Changed = 1 ;
  }
}

#ifdef _USETHREADS

#include <pthread.h>

int        MeshDim ;
pthread_t  MeshThread ;

void* StartMeshThread(void * data){
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONOUS, NULL);
  mai3d(&M,MeshDim);
  Msg(STATUS,"Ready");
  CTX.mesh.draw = 1;
  CTX.threads_lock = 0;
  XtSetSensitive(WID.G.Butt[6], 0);
  Init();
  Draw();
  pthread_exit(NULL);
  return NULL ;
}

void CancelMeshThread(void){
  if(CTX.threads){
    pthread_cancel(MeshThread);
    CTX.mesh.draw = 1;
    CTX.threads_lock = 0;
    XtSetSensitive(WID.G.Butt[6], 0);    
    Msg(INFO,"Mesh Aborted");
    mesh_event_handler(MESH_DELETE);
    Msg(STATUS,"Ready");
    Init();
    Draw();
  }
}

#else

void CancelMeshThread(void){
  
}

#endif

int SetGlobalShortcut(int event){
  return WID->global_shortcuts(event);
}

// Common callbacks 

void cancel_cb(CALLBACK_ARGS){
  if(data) ((Fl_Window*)data)->hide();
}

void ok_cb(CALLBACK_ARGS){
  Init();
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
    Init(); Draw(); 
    break;
  case 1 : 
    if(CTX.useTrackball)
      CTX.setQuaternion(1./sqrt(2.),0.,0.,1./sqrt(2.));
    set_r(0,-90.);set_r(1,0.); set_r(2,0.); 
    Init(); Draw(); 
    break;
  case 2 :
    if(CTX.useTrackball)
      CTX.setQuaternion(0.,0.,0.,1.);
    set_r(0,0.);  set_r(1,0.); set_r(2,0.); 
    Init(); Draw(); 
    break;
  case 3 : 
    set_t(0,0.);  set_t(1,0.); set_t(2,0.); 
    set_s(0,1.);  set_s(1,1.); set_s(2,1.); 
    Init(); Draw(); 
    break;
  case 4 :
    Print_Context(NULL);
    break ;
  }
}

static int stop_anim ;
void status_play_cb(CALLBACK_ARGS){
  static long anim_time ;
  WID->set_anim(0);
  stop_anim = 0 ;
  anim_time = GetTime();
  while(1){
    if(stop_anim) break ;
    WID->check();
    if(GetTime() - anim_time > CTX.post.anim_delay){
      anim_time = GetTime();
      MarkAllViewsChanged(2);
      Init(); Draw();
    }
  }
}

void status_pause_cb(CALLBACK_ARGS){
  stop_anim = 1;
  WID->set_anim(1);
}

void status_cancel_cb(CALLBACK_ARGS){
  CancelMeshThread();
}

// File Menu

void file_open_cb(CALLBACK_ARGS) {
  char *newfile;
  newfile = fl_file_chooser("Open File", "*.geo", NULL);
  if (newfile != NULL) {
    OpenProblem(newfile); 
    Init();
    Draw(); 
  }
}

void file_merge_cb(CALLBACK_ARGS) {
  char *newfile;
  newfile = fl_file_chooser("Merge File", "*", NULL);
  if (newfile != NULL) {
    MergeProblem(newfile); 
    Init();
    Draw(); 
  }
}

void file_save_cb(CALLBACK_ARGS) {
  Print_Mesh(&M, NULL, CTX.mesh.format);
}


void file_save_as_auto_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save File by Extension", "*", NULL)))
    CreateFile(newfile, CTX.print.format = FORMAT_AUTO); 
}

void file_save_as_geo_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GEO File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = FORMAT_GEO); 
}

void file_save_as_geo_options_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save Options File", "*", NULL)))
    Print_Context(newfile); 
}

void file_save_as_msh_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save MSH File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_MSH); 
}
void file_save_as_unv_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save UNV File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_UNV); 
}
void file_save_as_gref_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GREF File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_GREF); 
}
void file_save_as_eps_simple_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save EPS File", "*", NULL))){
    CTX.print.eps_quality = 1; 
    CreateFile(newfile, CTX.print.format = FORMAT_EPS); 
  }
}
void file_save_as_eps_accurate_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save EPS File", "*", NULL))){
    CTX.print.eps_quality = 2; 
    CreateFile(newfile, CTX.print.format = FORMAT_EPS); 
  }
}
void file_save_as_jpeg_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save JPEG File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = FORMAT_JPEG); 
}

void file_save_as_gif_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF File", "*", NULL))){
    CTX.print.gif_dither = 0;
    CTX.print.gif_transparent = 0;
    CreateFile(newfile, CTX.print.format = FORMAT_GIF); 
  }
}
void file_save_as_gif_dithered_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF File", "*", NULL))){
    CTX.print.gif_dither = 1; 
    CTX.print.gif_transparent = 0; 
    CreateFile(newfile, CTX.print.format = FORMAT_GIF); 
  }
}
void file_save_as_gif_transparent_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF File", "*", NULL))){
    CTX.print.gif_dither = 0;
    CTX.print.gif_transparent = 1; 
    CreateFile(newfile, CTX.print.format = FORMAT_GIF);
  }
}
void file_save_as_ppm_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save PPM File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = FORMAT_PPM); 
}
void file_save_as_yuv_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save YUV File", "*", NULL)))
    CreateFile(newfile, CTX.print.format = FORMAT_YUV); 
}

static int RELOAD_ALL_VIEWS = 0 ;

void file_reload_all_views_cb(CALLBACK_ARGS) {
  if(!Post_ViewList) return;
  RELOAD_ALL_VIEWS = 1;
  for(int i = 0 ; i<List_Nbr(Post_ViewList) ; i++)
    view_reload_cb(NULL, (void *)i);
  RELOAD_ALL_VIEWS = 0;
  Init();
  Draw();
}

static int REMOVE_ALL_VIEWS = 0 ;

void file_remove_all_views_cb(CALLBACK_ARGS) {
  if(!Post_ViewList) return;
  REMOVE_ALL_VIEWS = 1;
  while(List_Nbr(Post_ViewList))
    view_remove_cb(NULL, (void*)0);
  REMOVE_ALL_VIEWS = 0;
  Init();
  Draw();
}

void file_quit_cb(CALLBACK_ARGS) {
  exit(0);
}

// Option General Menu

void opt_general_cb(CALLBACK_ARGS) {
  WID->create_general_options_window();
}
void opt_general_moving_axes_cb(CALLBACK_ARGS){
  CTX.axes = !CTX.axes ;
}
void opt_general_small_axes_cb(CALLBACK_ARGS){
  CTX.small_axes = !CTX.small_axes ;
}
void opt_general_fast_redraw_cb(CALLBACK_ARGS){
  CTX.fast = !CTX.fast ;
}
void opt_general_display_lists_cb(CALLBACK_ARGS){
  CTX.display_lists = !CTX.display_lists ;
}
void opt_general_alpha_blending_cb(CALLBACK_ARGS){
  CTX.alpha = !CTX.alpha ;
}
void opt_general_trackball_cb(CALLBACK_ARGS){
  CTX.useTrackball = !CTX.useTrackball ;
}
void opt_general_orthographic_cb(CALLBACK_ARGS){
  if((int)data) CTX.ortho = 1;
  else CTX.ortho = 0;
}
void opt_general_color_cb(CALLBACK_ARGS){
  Init_Colors((int)((Fl_Value_Input*)w)->value()-1);
  Init();
  Draw();
}
void opt_general_shininess_cb(CALLBACK_ARGS){
  CTX.shine = ((Fl_Value_Input*)w)->value();
}
void opt_general_light_cb(CALLBACK_ARGS){
  CTX.light_position[0][(int)data] = ((Fl_Value_Input*)w)->value();
}

// Option Geometry Menu

void opt_geometry_cb(CALLBACK_ARGS) {
  WID->create_geometry_options_window();
}
void opt_geometry_entity_cb(CALLBACK_ARGS) {
  switch((int)data){
  case 0: CTX.geom.points = !CTX.geom.points; break;
  case 1: CTX.geom.lines = !CTX.geom.lines; break;
  case 2: CTX.geom.surfaces = !CTX.geom.surfaces; break;
  case 3: CTX.geom.volumes = !CTX.geom.volumes; break;
  }
}
void opt_geometry_num_cb(CALLBACK_ARGS) {
  switch((int)data){
  case 0: CTX.geom.points_num = !CTX.geom.points_num; break;
  case 1: CTX.geom.lines_num = !CTX.geom.lines_num; break;
  case 2: CTX.geom.surfaces_num = !CTX.geom.surfaces_num; break;
  case 3: CTX.geom.volumes_num = !CTX.geom.volumes_num; break;
  }
}
void opt_geometry_show_by_entity_num_cb(CALLBACK_ARGS) {
  const char * c = ((Fl_Input*)w)->value(); 
  if (!strcmp(c,"all") || !strcmp(c,"*")){
    if(SHOW_ALL_ENTITIES){ RemplirEntitesVisibles(0); SHOW_ALL_ENTITIES = 0; }
    else { RemplirEntitesVisibles(1); SHOW_ALL_ENTITIES = 1; }
  }
  else{ 
    int i = atoi(c);
    if(EntiteEstElleVisible(i)) ToutesLesEntitesRelatives(i,EntitesVisibles,0);
    else ToutesLesEntitesRelatives(i,EntitesVisibles,1);
  }
}

void opt_geometry_normals_cb(CALLBACK_ARGS) {
  CTX.geom.normals = ((Fl_Value_Input*)w)->value();
}
void opt_geometry_tangents_cb(CALLBACK_ARGS) {
  CTX.geom.tangents = ((Fl_Value_Input*)w)->value();
}

// Option Mesh Menu

void opt_mesh_cb(CALLBACK_ARGS) {
  WID->create_mesh_options_window();
}
void opt_mesh_entity_cb(CALLBACK_ARGS) {
  switch((int)data){
  case 0: CTX.mesh.points = !CTX.mesh.points; break;
  case 1: CTX.mesh.lines = !CTX.mesh.lines; break;
  case 2: CTX.mesh.surfaces = !CTX.mesh.surfaces; break;
  case 3: CTX.mesh.volumes = !CTX.mesh.volumes; break;
  }
}
void opt_mesh_num_cb(CALLBACK_ARGS) {
  switch((int)data){
  case 0: CTX.mesh.points_num = !CTX.mesh.points_num; break;
  case 1: CTX.mesh.lines_num = !CTX.mesh.lines_num; break;
  case 2: CTX.mesh.surfaces_num = !CTX.mesh.surfaces_num; break;
  case 3: CTX.mesh.volumes_num = !CTX.mesh.volumes_num; break;
  }
}
void opt_mesh_show_by_entity_num_cb(CALLBACK_ARGS) {
  opt_geometry_show_by_entity_num_cb(w,data);
}
void opt_mesh_show_by_quality_cb(CALLBACK_ARGS) {
  CTX.mesh.limit_gamma = ((Fl_Value_Input*)w)->value();
}
void opt_mesh_normals_cb(CALLBACK_ARGS) {
  CTX.mesh.normals = ((Fl_Value_Input*)w)->value();
}
void opt_mesh_degree_cb(CALLBACK_ARGS){
  if(CTX.mesh.degree==2) CTX.mesh.degree = 1;
  else CTX.mesh.degree = 2;
}
void opt_mesh_algo_cb(CALLBACK_ARGS){
  if(CTX.mesh.algo==DELAUNAY_OLDALGO) CTX.mesh.algo = DELAUNAY_NEWALGO;
  else CTX.mesh.algo = DELAUNAY_OLDALGO;
}
void opt_mesh_smoothing_cb(CALLBACK_ARGS){
  CTX.mesh.nb_smoothing = (int)((Fl_Value_Input*)w)->value();
}
void opt_mesh_interactive_cb(CALLBACK_ARGS){
  CTX.mesh.interactive = !CTX.mesh.interactive;
}
void opt_mesh_explode_cb(CALLBACK_ARGS){
  CTX.mesh.explode = ((Fl_Value_Input*)w)->value();
}
void opt_mesh_aspect_cb(CALLBACK_ARGS){
  switch((int)data){
  case 0 : CTX.mesh.hidden = 0; CTX.mesh.shade = 0; break; 
  case 1 : CTX.mesh.hidden = 1; CTX.mesh.shade = 0; break; 
  case 2 : CTX.mesh.hidden = 1; CTX.mesh.shade = 1; break; 
  }
}

// Option Post Menu

void opt_post_cb(CALLBACK_ARGS) {
  WID->create_post_options_window();
}
void opt_post_link_cb(CALLBACK_ARGS) {
  CTX.post.link = (int)data;
}
void opt_post_anim_delay_cb(CALLBACK_ARGS) {
  CTX.post.anim_delay = (long)(1.e6*((Fl_Value_Input*)w)->value());
}

// Option Statistics Menu

void opt_statistics_cb(CALLBACK_ARGS) {
  WID->create_statistics_window();
}
void opt_statistics_update_cb(CALLBACK_ARGS) {
  WID->set_statistics();
}

// Help Menu

void help_short_cb(CALLBACK_ARGS){
  WID->create_help_window();
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
void mod_post_cb(CALLBACK_ARGS){
  WID->set_context(menu_post, 0);
}
void mod_back_cb(CALLBACK_ARGS){
  WID->set_context(NULL, -1);
}
void mod_forward_cb(CALLBACK_ARGS){
  WID->set_context(NULL, 1);
}

// Dynamic Menus

void geometry_elementary_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary, 0);
}
void geometry_physical_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_physical, 0);
}
void geometry_reload_cb(CALLBACK_ARGS){
  OpenProblem(CTX.filename);
  Init();
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
void geometry_elementary_add_new_line_cb(CALLBACK_ARGS){
  printf("new line\n");
}
void geometry_elementary_add_new_spline_cb(CALLBACK_ARGS){
  printf("new spline\n");
}
void geometry_elementary_add_new_circle_cb(CALLBACK_ARGS){
  printf("new circle\n");
}
void geometry_elementary_add_new_ellipsis_cb(CALLBACK_ARGS){
  printf("new ellipsis\n");
}
void geometry_elementary_add_new_planesurface_cb(CALLBACK_ARGS){
  printf("new plane surf\n");
}
void geometry_elementary_add_new_ruledsurface_cb(CALLBACK_ARGS){
  printf("new rules surf\n");
}
void geometry_elementary_add_new_volume_cb(CALLBACK_ARGS){
  printf("new vol\n");
}
void geometry_elementary_add_translate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_translate, 0);
}
void geometry_elementary_add_translate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("translate point\n");
}
void geometry_elementary_add_translate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("translate curve\n");
}
void geometry_elementary_add_translate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("translate surface\n");
}
void geometry_elementary_add_rotate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_rotate, 0);
}
void geometry_elementary_add_rotate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("rotate point\n");
}
void geometry_elementary_add_rotate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("rotate curve\n");
}
void geometry_elementary_add_rotate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("rotate surf\n");
}
void geometry_elementary_add_scale_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_scale, 0);
}
void geometry_elementary_add_scale_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  printf("scale point\n");
}
void geometry_elementary_add_scale_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  printf("scale curve\n");
}
void geometry_elementary_add_scale_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  printf("scale surface\n");
}
void geometry_elementary_add_symmetry_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_add_symmetry, 0);
}
void geometry_elementary_add_symmetry_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  printf("symm point\n");
}
void geometry_elementary_add_symmetry_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  printf("symm curve\n");
}
void geometry_elementary_add_symmetry_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  printf("symm surf\n");
}
void geometry_elementary_translate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_translate, 0);
}
void geometry_elementary_translate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("translate point\n");
}
void geometry_elementary_translate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("translate curve\n");
}
void geometry_elementary_translate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("translate surf\n");
}
void geometry_elementary_rotate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_rotate, 0);
}
void geometry_elementary_rotate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("rot point\n");
}
void geometry_elementary_rotate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("rot curve\n");
}
void geometry_elementary_rotate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("rot surf\n");
}
void geometry_elementary_scale_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_scale, 0);
}
void geometry_elementary_scale_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  printf("scale point\n");
}
void geometry_elementary_scale_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  printf("scale curve\n");
}
void geometry_elementary_scale_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(4);
  printf("scale surf\n");
}
void geometry_elementary_symmetry_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_symmetry, 0);
}
void geometry_elementary_symmetry_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  printf("symm point\n");
}
void geometry_elementary_symmetry_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  printf("symm curve\n");
}
void geometry_elementary_symmetry_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(5);
  printf("symm surf\n");
}
void geometry_elementary_extrude_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_extrude, 0);
}
void geometry_elementary_extrude_translate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_extrude_translate, 0);
}
void geometry_elementary_extrude_translate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("extr point\n");
}
void geometry_elementary_extrude_translate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("extr curve\n");
}
void geometry_elementary_extrude_translate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(2);
  printf("extr surf\n");
}
void geometry_elementary_extrude_rotate_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_extrude_rotate, 0);
}
void geometry_elementary_extrude_rotate_point_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("extr point\n");
}
void geometry_elementary_extrude_rotate_curve_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("extr curve\n");
}
void geometry_elementary_extrude_rotate_surface_cb(CALLBACK_ARGS){
  WID->create_geometry_context_window(3);
  printf("extr surf\n");
}
void geometry_elementary_delete_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_elementary_delete, 0);
}
void geometry_elementary_delete_point_cb(CALLBACK_ARGS){
  printf("del point\n");
}
void geometry_elementary_delete_curve_cb(CALLBACK_ARGS){
  printf("del curve\n");
}
void geometry_elementary_delete_surface_cb(CALLBACK_ARGS){
  printf("del surf\n");
}
void geometry_physical_add_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_physical_add, 0);
}
void geometry_physical_add_point_cb (CALLBACK_ARGS){
  printf("phys add point\n");
}
void geometry_physical_add_curve_cb (CALLBACK_ARGS){
  printf("phys add curve\n");
}
void geometry_physical_add_surface_cb (CALLBACK_ARGS){
  printf("phys add surf\n");
}
void geometry_physical_add_volume_cb (CALLBACK_ARGS){
  printf("phys add vol\n");
}
void geometry_physical_delete_cb(CALLBACK_ARGS){
  WID->set_context(menu_geometry_physical_delete, 0);
}
void geometry_physical_delete_point_cb(CALLBACK_ARGS){
  printf("phys delpoint\n");
}
void geometry_physical_delete_curve_cb(CALLBACK_ARGS){
  printf("phys del curve\n");
}
void geometry_physical_delete_surface_cb(CALLBACK_ARGS){
  printf("phys adel surf\n");
}
void geometry_physical_delete_volume_cb(CALLBACK_ARGS){
  printf("phys del vol\n");
}
void mesh_define_cb(CALLBACK_ARGS){
  WID->set_context(menu_mesh_define, 0);
}
void mesh_1d_cb(CALLBACK_ARGS){
#ifdef _USETHREADS
  if(CTX.threads){
    XtSetSensitive(WID.G.Butt[6], 1);
    CTX.mesh.draw = 0; CTX.threads_lock = 1 ; MeshDim = 1 ; 
    pthread_create(&MeshThread, NULL, StartMeshThread, NULL);
  }
  else
#endif
    mai3d(&M, 1); 
  Init(); 
  Draw();
}
void mesh_2d_cb(CALLBACK_ARGS){
#ifdef _USETHREADS
  if(CTX.threads){
    XtSetSensitive(WID.G.Butt[6], 1);
    CTX.mesh.draw = 0; CTX.threads_lock = 1 ; MeshDim = 2 ; 
    pthread_create(&MeshThread, NULL, StartMeshThread, NULL);
  }
  else
#endif
    mai3d(&M, 2);
  Init(); 
  Draw();
} 
void mesh_3d_cb(CALLBACK_ARGS){
#ifdef _USETHREADS
  if(CTX.threads){
    XtSetSensitive(WID.G.Butt[6], 1);
    CTX.mesh.draw = 0; CTX.threads_lock = 1 ; MeshDim = 3 ; 
    pthread_create(&MeshThread, NULL, StartMeshThread, NULL);
  }
  else
#endif
    mai3d(&M, 3); 
  Init(); 
  Draw();
} 
void mesh_define_length_cb (CALLBACK_ARGS){
  Vertex   *v;
  Curve    *c;
  Surface  *s;
  int       ib;
  static int n=0, p[100];

  WID->create_mesh_context_window(0);

  while(1){
    Msg(STATUS,"Select Point ('e'=end, 'q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1){ /* left mouse butt */
      p[n++] = v->Num; 
    }
    if (ib == -1){ /* 'e' */
      if(n >= 1) {
	add_charlength(n,p,CTX.filename); 
	n=0;
	ZeroHighlight(&M);
	DrawUpdate();
	break;
      }
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(&M);
      DrawUpdate();
      break;
    }
  }
  Msg(STATUS,"Ready");
}
void mesh_define_recombine_cb (CALLBACK_ARGS){
  printf("mesh define reco\n");
}
void mesh_define_transfinite_cb (CALLBACK_ARGS){
  WID->set_context(menu_mesh_define_transfinite, 0);
} 
void mesh_define_transfinite_line_cb(CALLBACK_ARGS){
  WID->create_mesh_context_window(1);
  printf("mesh define tr line\n");
}
void mesh_define_transfinite_surface_cb(CALLBACK_ARGS){
  printf("mesh define tr su\n");
}
void mesh_define_transfinite_volume_cb(CALLBACK_ARGS){
  WID->create_mesh_context_window(3);
  printf("mesh define tr vol\n");
} 

void view_toggle_cb(CALLBACK_ARGS){
  if(!Post_ViewList) return;

  Post_View  *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);

  Msg(DEBUG,    "View %d\n"
      DEBUG_NIL "  -> Name '%s'\n"
      DEBUG_NIL "  -> FileName '%s'\n"
      DEBUG_NIL "  -> DuplicateOf %d\n"
      DEBUG_NIL "  -> Links %d",
      v->Num, v->Name, v->FileName, v->DuplicateOf, v->Links);

  v->Visible = !v->Visible;

  Init();
  Draw();
}

void view_reload_cb(CALLBACK_ARGS){
  Post_View tmp ;
  char filename[NAME_STR_L];
  extern int Force_ViewNumber;

  if(!Post_ViewList) return;

  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  strcpy(filename, v->FileName);
  CopyViewOptions(v, &tmp);

  Force_ViewNumber = v->Num ;
  FreeView(v);
  MergeProblem(filename);
  Force_ViewNumber = 0 ;
  
  v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  CopyViewOptions(&tmp, v);

  if(!RELOAD_ALL_VIEWS){
    Init();
    Draw();
  }
}

void view_remove_cb(CALLBACK_ARGS){
  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  FreeView(v);

  if(!List_Suppress(Post_ViewList, v, fcmpPostViewNum))
    Msg(GERROR, "Could Not Suppress View from List");

  CTX.post.nb_views = List_Nbr(Post_ViewList);

  if(WID->get_context() == 2)
    WID->set_context(menu_post, 0);  

  if(!REMOVE_ALL_VIEWS){
    Init();
    Draw();
  }
}

void view_duplicate_cb(CALLBACK_ARGS){
  Post_View  v, *v1, *v2, *v3 ;

  if(!Post_ViewList) return;

  v1 = (Post_View*)List_Pointer(Post_ViewList,(int)data);

  BeginView(0);
  EndView(0, 0, v1->FileName, v1->Name, 0., 0., 0.);

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

  CopyViewOptions(v1, v2);

  AddViewInUI(List_Nbr(Post_ViewList), v2->Name, v2->Num);
  Init();
  Draw();
}

void view_lighting_cb(CALLBACK_ARGS){
  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  v->Light = !v->Light;
  v->Changed = 1;
  Init() ;
  Draw() ;
}
void view_elements_cb(CALLBACK_ARGS){
  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  v->ShowElement = !v->ShowElement;
  v->Changed = 1;
  Init() ;
  Draw() ;
}
void view_applybgmesh_cb(CALLBACK_ARGS){
  Post_View *v = (Post_View*)List_Pointer(Post_ViewList,(int)data);
  BGMWithView(v); 
}
void view_options_cb(CALLBACK_ARGS){
  WID->create_view_window((int)data);
}

#define STARTVIEWMOD					\
  Post_View *v;						\
  int i;						\
  for(i=0 ; i<List_Nbr(Post_ViewList) ; i++){		\
    v = (Post_View*)List_Pointer(Post_ViewList, i);	\
    if(CTX.post.link == 2 ||				\
       (CTX.post.link == 1 && v->Visible) ||		\
       (CTX.post.link == 0 && i == (int)data)){

#define ENDVIEWMOD				\
    }						\
  }

void view_options_show_scale_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->ShowScale = ((Fl_Check_Button*)w)->value() ;
  ENDVIEWMOD
}
void view_options_show_time_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->ShowTime = ((Fl_Check_Button*)w)->value() ;
  ENDVIEWMOD
}
void view_options_transparent_scale_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->TransparentScale = ((Fl_Check_Button*)w)->value() ;
  ENDVIEWMOD
}
void view_options_name_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    strcpy(v->Name, ((Fl_Input*)w)->value()) ;
  ENDVIEWMOD
}
void view_options_format_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    strcpy(v->Format, ((Fl_Input*)w)->value()) ;
  ENDVIEWMOD
}
void view_options_custom_range_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      WID->activate_custom(1);
      v->RangeType = DRAW_POST_CUSTOM;
    }
    else{
      WID->activate_custom(0);
      v->RangeType = DRAW_POST_DEFAULT;
    }
  ENDVIEWMOD
}
void view_options_custom_min_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    //printf("set cust min %d %d %g\n", v->Num, i, ((Fl_Value_Input*)w)->value());
    v->CustomMin = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_custom_max_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    //printf("set cust max %d %d %g\n", v->Num, i, ((Fl_Value_Input*)w)->value());
    v->CustomMax = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_linear_range_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ScaleType = DRAW_POST_LINEAR;
    }
    else{
      v->ScaleType = DRAW_POST_LOGARITHMIC;
    }
  ENDVIEWMOD
}
void view_options_logarithmic_range_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->RangeType = DRAW_POST_LOGARITHMIC;
    }
    else{
      v->RangeType = DRAW_POST_LINEAR;
    }
  ENDVIEWMOD
}
void view_options_nbiso_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->NbIso = (int)((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_iso_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->IntervalsType = DRAW_POST_ISO;
    }
  ENDVIEWMOD
}
void view_options_fillediso_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->IntervalsType = DRAW_POST_DISCRETE;
    }
  ENDVIEWMOD
}
void view_options_continuousiso_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->IntervalsType = DRAW_POST_CONTINUOUS;
    }
  ENDVIEWMOD
}
void view_options_numericiso_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->IntervalsType = DRAW_POST_NUMERIC;
    }
  ENDVIEWMOD
}
void view_options_xoffset_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->Offset[0] = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_yoffset_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->Offset[1] = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_zoffset_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->Offset[2] = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_xraise_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->Raise[0] = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_yraise_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->Raise[1] = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_zraise_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->Raise[2] = ((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
}
void view_options_timestep_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    v->TimeStep = (int)((Fl_Value_Input*)w)->value() ;
  ENDVIEWMOD
  Init();
  Draw();
}
void view_options_vector_line_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ArrowType = DRAW_POST_SEGMENT;
    }
  ENDVIEWMOD
}
void view_options_vector_arrow_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ArrowType = DRAW_POST_ARROW;
    }
  ENDVIEWMOD
}
void view_options_vector_cone_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ArrowType = DRAW_POST_CONE;
    }
  ENDVIEWMOD
}
void view_options_vector_displacement_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ArrowType = DRAW_POST_DISPLACEMENT;
    }
  ENDVIEWMOD
}
void view_options_vector_scale_cb(CALLBACK_ARGS){
}
void view_options_vector_cog_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ArrowType = DRAW_POST_LOCATE_COG;
    }
  ENDVIEWMOD
}
void view_options_vector_vertex_cb(CALLBACK_ARGS){
  STARTVIEWMOD
    if(((Fl_Check_Button*)w)->value()){
      v->ArrowType = DRAW_POST_LOCATE_VERTEX;
    }
  ENDVIEWMOD
}

#undef STARTVIEWMOD
#undef ENDVIEWMOD

// Context geometry

void con_geometry_define_parameter_cb(CALLBACK_ARGS){
  add_param(WID->get_geometry_parameter(0),
	    WID->get_geometry_parameter(1),
	    CTX.filename);
}

void con_geometry_define_point_cb(CALLBACK_ARGS){
 strcpy(x_text, WID->get_geometry_point(0));
 strcpy(y_text, WID->get_geometry_point(1));
 strcpy(z_text, WID->get_geometry_point(2));
 strcpy(l_text, WID->get_geometry_point(3));
 add_point(CTX.filename);
 ZeroHighlight(&M);
 Replot();
}

void con_geometry_define_translation_cb(CALLBACK_ARGS){
  strcpy(tx_text, WID->get_geometry_translation(0));
  strcpy(ty_text, WID->get_geometry_translation(1));
  strcpy(tz_text, WID->get_geometry_translation(2));
}

void con_geometry_define_rotation_cb(CALLBACK_ARGS){
  strcpy(px_text, WID->get_geometry_rotation(0));
  strcpy(py_text, WID->get_geometry_rotation(1));
  strcpy(pz_text, WID->get_geometry_rotation(2));
  strcpy(ax_text, WID->get_geometry_rotation(3));
  strcpy(ay_text, WID->get_geometry_rotation(4));
  strcpy(az_text, WID->get_geometry_rotation(5));
  strcpy(angle_text, WID->get_geometry_rotation(6));
}

void con_geometry_define_scale_cb(CALLBACK_ARGS){
  strcpy(dx_text, WID->get_geometry_scale(0));
  strcpy(dy_text, WID->get_geometry_scale(1));
  strcpy(dz_text, WID->get_geometry_scale(2));
  strcpy(df_text, WID->get_geometry_scale(3));
}

void con_geometry_define_symmetry_cb(CALLBACK_ARGS){
  strcpy(sa_text, WID->get_geometry_symmetry(0));
  strcpy(sb_text, WID->get_geometry_symmetry(1));
  strcpy(sc_text, WID->get_geometry_symmetry(2));
  strcpy(sd_text, WID->get_geometry_symmetry(3));
}


// Context mesh

void con_mesh_define_transfinite_line_cb(CALLBACK_ARGS){
  strcpy(trsf_pts_text, WID->get_mesh_transfinite(0));
  strcpy(trsf_type_text, WID->get_mesh_transfinite(1));
}

void con_mesh_define_transfinite_volume_cb(CALLBACK_ARGS){
  strcpy(trsf_vol_text, WID->get_mesh_transfinite(2));
}

void con_mesh_define_length_cb(CALLBACK_ARGS){
  strcpy(char_length_text, WID->get_mesh_length(0));
}

void con_mesh_define_attractor_cb(CALLBACK_ARGS){
  strcpy(attrx_text, WID->get_mesh_attractor(0));
  strcpy(attry_text, WID->get_mesh_attractor(1));
  strcpy(attrz_text, WID->get_mesh_attractor(2));
}
