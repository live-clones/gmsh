// $Id: Callbacks.cpp,v 1.110 2002-02-22 16:44:09 geuzaine Exp $

#include <sys/types.h>
#include <signal.h>
#include <map>
#include "Gmsh.h"
#include "GmshUI.h"
#include "Geo.h"
#include "CAD.h"
#include "Verif.h"
#include "Mesh.h"
#include "Draw.h"
#include "Views.h"
#include "Timer.h"
#include "CreateFile.h"
#include "OpenFile.h"
#include "GetOptions.h"
#include "Context.h"
#include "Options.h"
#include "GUI.h"
#include "Callbacks.h"
#include "Plugin.h"
#include "Visibility.h"

using namespace std;

#if (FL_MAJOR_VERSION == 1) && (FL_MINOR_VERSION == 1)
#include <FL/Fl_File_Chooser.H>
#else
#include <FL/fl_file_chooser.H>
#endif

#include <errno.h>

extern GUI       *WID;
extern Mesh      *THEM;
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

void set_changed_cb(CALLBACK_ARGS){
  w->set_changed();
}

// Graphical window 

void status_xyz1p_cb(CALLBACK_ARGS){

  extern void set_r(int i, double val);
  extern void set_t(int i, double val);
  extern void set_s(int i, double val);

  switch((long int)data){
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

static int stop_anim, view_in_cycle=-1 ;
void ManualPlay(int time, int step){
  int i;
  if(time){
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++)
      if(opt_view_visible(i, GMSH_GET, 0))
	opt_view_timestep(i, GMSH_SET|GMSH_GUI, opt_view_timestep(i, GMSH_GET, 0)+step);
  }
  else{//hide all views except view_in_cycle
    if(step>0){
      if((view_in_cycle+=step)>=List_Nbr(CTX.post.list)) view_in_cycle=0;
      for(i=0 ; i<List_Nbr(CTX.post.list) ; i+=step)
	opt_view_visible(i, GMSH_SET|GMSH_GUI, (i==view_in_cycle));
    }
    else{
      if((view_in_cycle+=step)<0) view_in_cycle=List_Nbr(CTX.post.list)-1;
      for(i=List_Nbr(CTX.post.list)-1 ; i>=0 ; i+=step)
	opt_view_visible(i, GMSH_SET|GMSH_GUI, (i==view_in_cycle));
    }
  }
  Draw();
}
void status_play_cb(CALLBACK_ARGS){
  static long anim_time ;
  WID->set_anim_buttons(0);
  stop_anim = 0 ;
  anim_time = GetTime();
  while(1){
    if(stop_anim) break ;
    if(GetTime() - anim_time > 1.e6*CTX.post.anim_delay){
      anim_time = GetTime();
      ManualPlay(!CTX.post.anim_cycle,1);
    }
    WID->check();
  }
}

void status_pause_cb(CALLBACK_ARGS){
  stop_anim = 1;
  WID->set_anim_buttons(1);
}

void status_rewind_cb(CALLBACK_ARGS){
  int i;
  if(!CTX.post.anim_cycle){
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++)
      opt_view_timestep(i, GMSH_SET|GMSH_GUI, 0);
  }
  else{
    view_in_cycle = 0;
    for(i=0 ; i<List_Nbr(CTX.post.list) ; i++)
      opt_view_visible(i, GMSH_SET|GMSH_GUI, !i);
  }
  Draw();
}

void status_cancel_cb(CALLBACK_ARGS){
}

// File Menu

void file_open_cb(CALLBACK_ARGS) {
  char *newfile;
  int n = List_Nbr(CTX.post.list);
  newfile = fl_file_chooser("Open file", "*", NULL);
  if (newfile != NULL) {
    OpenProblem(newfile); 
    Draw(); 
  }
  if(n != List_Nbr(CTX.post.list))
    WID->set_context(menu_post, 0);
}

void file_merge_cb(CALLBACK_ARGS) {
  char *newfile;
  int n = List_Nbr(CTX.post.list);
  newfile = fl_file_chooser("Merge file", "*", NULL);
  if (newfile != NULL) {
    MergeProblem(newfile); 
    Draw(); 
  }
  if(n != List_Nbr(CTX.post.list))
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
  if((newfile = fl_file_chooser("Save option file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_OPT); 
}

void file_save_as_msh_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save MSH file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_MSH); 
}
void file_save_as_msh_all_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save MSH file (no physicals)", "*", NULL))){
    int all = CTX.mesh.save_all;
    CTX.mesh.save_all = 1;
    CreateOutputFile(newfile, CTX.print.format = CTX.mesh.format = FORMAT_MSH); 
    CTX.mesh.save_all = all;
  }
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
void file_save_as_ps_simple_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save PS file", "*", NULL))){
    int old = CTX.print.eps_quality;
    CTX.print.eps_quality = 1; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_PS); 
    CTX.print.eps_quality = old; 
  }
}
void file_save_as_ps_accurate_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save PS file", "*", NULL))){
    int old = CTX.print.eps_quality;
    CTX.print.eps_quality = 2; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_PS); 
    CTX.print.eps_quality = old; 
  }
}
void file_save_as_pstex_simple_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save LaTeX file (PS part)", "*", NULL))){
    int old = CTX.print.eps_quality;
    CTX.print.eps_quality = 1; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_PSTEX); 
    CTX.print.eps_quality = old; 
  }
}
void file_save_as_pstex_accurate_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save LaTeX file (PS part)", "*", NULL))){
    int old = CTX.print.eps_quality;
    CTX.print.eps_quality = 2; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_PSTEX); 
    CTX.print.eps_quality = old; 
  }
}
void file_save_as_jpegtex_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save LaTeX file (Jpeg part)", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_JPEGTEX); 
}
void file_save_as_tex_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save LaTeX file (TeX part)", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_TEX); 
}
void file_save_as_jpeg_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save JPEG file", "*", NULL)))
    CreateOutputFile(newfile, CTX.print.format = FORMAT_JPEG); 
}
void file_save_as_gif_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF file", "*", NULL))){
    int dither = CTX.print.gif_dither;
    int transp = CTX.print.gif_transparent;
    CTX.print.gif_dither = 0;
    CTX.print.gif_transparent = 0;
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GIF); 
    CTX.print.gif_dither = dither;
    CTX.print.gif_transparent = transp;
  }
}
void file_save_as_gif_dithered_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF file", "*", NULL))){
    int dither = CTX.print.gif_dither;
    int transp = CTX.print.gif_transparent;
    CTX.print.gif_dither = 1; 
    CTX.print.gif_transparent = 0; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GIF); 
    CTX.print.gif_dither = dither;
    CTX.print.gif_transparent = transp;
  }
}
void file_save_as_gif_transparent_cb(CALLBACK_ARGS) {
  char *newfile;
  if((newfile = fl_file_chooser("Save GIF file", "*", NULL))){
    int dither = CTX.print.gif_dither;
    int transp = CTX.print.gif_transparent;
    CTX.print.gif_dither = 0;
    CTX.print.gif_transparent = 1; 
    CreateOutputFile(newfile, CTX.print.format = FORMAT_GIF);
    CTX.print.gif_dither = dither;
    CTX.print.gif_transparent = transp;
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
  opt_general_point_size(0, GMSH_SET, WID->gen_value[6]->value());
  opt_general_line_width(0, GMSH_SET, WID->gen_value[7]->value());

  opt_general_default_filename(0, GMSH_SET, (char*)WID->gen_input[0]->value());
  opt_general_tmp_filename(0, GMSH_SET, (char*)WID->gen_input[1]->value());
  opt_general_error_filename(0, GMSH_SET, (char*)WID->gen_input[2]->value());
  opt_general_options_filename(0, GMSH_SET, (char*)WID->gen_input[3]->value());
  opt_general_editor(0, GMSH_SET, (char*)WID->gen_input[4]->value());

  Draw();
}

// Option Geometry Menu

void opt_geometry_cb(CALLBACK_ARGS) {
  WID->create_geometry_options_window();
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
  opt_geometry_auto_coherence(0, GMSH_SET, WID->geo_butt[8]->value());

  opt_geometry_normals(0, GMSH_SET, WID->geo_value[0]->value());
  opt_geometry_tangents(0, GMSH_SET, WID->geo_value[1]->value());
  opt_geometry_point_size(0, GMSH_SET, WID->geo_value[3]->value());
  opt_geometry_line_width(0, GMSH_SET, WID->geo_value[4]->value());
  Draw();
}

// Option Mesh Menu

void opt_mesh_cb(CALLBACK_ARGS) {
  WID->create_mesh_options_window();
}
void opt_mesh_color_scheme_cb(CALLBACK_ARGS){
  opt_mesh_color_scheme(0,GMSH_SET, WID->mesh_value[12]->value());
  Draw();
}
void opt_mesh_ok_cb(CALLBACK_ARGS) {
  opt_mesh_algo(0, GMSH_SET, 
		WID->mesh_butt[0]->value()?DELAUNAY_ISO:
		WID->mesh_butt[1]->value()?DELAUNAY_SHEWCHUK:
		DELAUNAY_ANISO);
  opt_mesh_degree(0, GMSH_SET, WID->mesh_butt[3]->value()?2:1);
  opt_mesh_interactive(0, GMSH_SET, WID->mesh_butt[4]->value());
  opt_mesh_constrained_bgmesh(0, GMSH_SET, WID->mesh_butt[5]->value());
  opt_mesh_points(0, GMSH_SET, WID->mesh_butt[6]->value());
  opt_mesh_lines(0, GMSH_SET, WID->mesh_butt[7]->value());
  opt_mesh_surfaces(0, GMSH_SET, WID->mesh_butt[8]->value());
  opt_mesh_volumes(0, GMSH_SET, WID->mesh_butt[9]->value());
  opt_mesh_points_num(0, GMSH_SET, WID->mesh_butt[10]->value());
  opt_mesh_lines_num(0, GMSH_SET, WID->mesh_butt[11]->value());
  opt_mesh_surfaces_num(0, GMSH_SET, WID->mesh_butt[12]->value());
  opt_mesh_volumes_num(0, GMSH_SET, WID->mesh_butt[13]->value());
  opt_mesh_aspect(0, GMSH_SET, 
		  WID->mesh_butt[14]->value()?0:
		  WID->mesh_butt[15]->value()?1:
		  2);
  opt_mesh_color_carousel(0, GMSH_SET, WID->mesh_butt[17]->value());

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
  opt_mesh_tangents(0, GMSH_SET, WID->mesh_value[13]->value());
  opt_mesh_point_size(0, GMSH_SET, WID->mesh_value[10]->value());
  opt_mesh_line_width(0, GMSH_SET, WID->mesh_value[11]->value());

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
  opt_post_link(0, GMSH_SET, 
		WID->post_butt[0]->value()?0:
		WID->post_butt[1]->value()?1:
		WID->post_butt[2]->value()?2:
		WID->post_butt[3]->value()?3:
		4);
  opt_post_smooth(0, GMSH_SET, WID->post_butt[5]->value());
  opt_post_anim_cycle(0, GMSH_SET, WID->post_butt[6]->value());

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
  int i, type=(long int)data;

  Print_Histogram(THEM->Histogram[type]);

  double *x=(double*)Malloc(NB_HISTOGRAM*sizeof(double));
  double *y=(double*)Malloc(NB_HISTOGRAM*sizeof(double));
  for(i=0;i<NB_HISTOGRAM;i++){
    x[i]=(double)(i+1)/(double)NB_HISTOGRAM;
    y[i]=(double)THEM->Histogram[type][i];
  }
  char *name;
  if(type==0) name = "Gamma";
  else if(type==1) name = "Eta";
  else name = "Rho";
  Create2DGraph(name,"Elements",NB_HISTOGRAM,x,y);
  Draw(); 
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

// Option Visibility Menu

#if (FL_MAJOR_VERSION == 2) //disabled for fltk 2 at the moment
void select_vis_browser(int mode){}
void opt_visibility_cb(CALLBACK_ARGS) {}
void opt_visibility_ok_cb(CALLBACK_ARGS) {}
void opt_visibility_sort_cb(CALLBACK_ARGS){}
void opt_visibility_number_cb(CALLBACK_ARGS){}
#else
void select_vis_browser(int mode){
  int i;
  Entity *e;
  for(i=1 ; i<=WID->vis_browser->size(); i++){
    e = (Entity*)WID->vis_browser->data(i);
    if((mode == VIS_GEOM|VIS_MESH && e->Visible() == mode) ||
       (mode == VIS_GEOM          && e->Visible() & VIS_GEOM) ||
       (mode == VIS_MESH          && e->Visible() & VIS_MESH)) 
      WID->vis_browser->select(i);
  }
}

void opt_visibility_cb(CALLBACK_ARGS) {
  int i, type, mode;
  List_T *list;
  Entity *e;

  WID->create_visibility_window();
  WID->vis_browser->clear();

  switch(WID->vis_type->value()){
  case 0 : type = ELEMENTARY; break;
  default: type = PHYSICAL; break;
  }
  switch(WID->vis_browser_mode->value()){
  case 0 : mode = VIS_GEOM|VIS_MESH; break;
  case 1 : mode = VIS_GEOM; break;
  default: mode = VIS_MESH; break;
  }

  list = GetVisibilityList(type);

  for(i=0 ; i<List_Nbr(list); i++){
    e = (Entity*)List_Pointer(list,i);
    WID->vis_browser->add(e->BrowserLine(),e);
  }
  select_vis_browser(mode);
}

void opt_visibility_ok_cb(CALLBACK_ARGS) {
  int i, mode;
  Entity *e;

  InitVisibilityThroughPhysical();

  switch(WID->vis_type->value()){
  case 0 : ClearVisibilityList(PHYSICAL); break;
  default: ClearVisibilityList(ELEMENTARY); break;
  }
  switch(WID->vis_browser_mode->value()){
  case 0 : mode = VIS_GEOM|VIS_MESH; break;
  case 1 : mode = VIS_GEOM; break;
  default: mode = VIS_MESH; break;
  }

  for(i=1 ; i<=WID->vis_browser->size(); i++){
    e = (Entity*)WID->vis_browser->data(i);
    if(WID->vis_browser->selected(i)){
      e->Visible(e->Visible()|mode);
    }
    else{
      switch(WID->vis_browser_mode->value()){
      case 0 : 
	e->Visible(0);
	break;
      case 1 :
	if(e->Visible() & VIS_MESH) e->Visible(VIS_MESH);
	else e->Visible(0);
	break;
      default :
	if(e->Visible() & VIS_GEOM) e->Visible(VIS_GEOM);
	else e->Visible(0);
	break;
      }
    }
  }

  if(WID->vis_butt[0]->value()){
    for(i=1 ; i<=WID->vis_browser->size(); i++){
      e = (Entity*)WID->vis_browser->data(i);
      e->RecurVisible();
    }
    select_vis_browser(mode);
  }

  Draw();
}

void opt_visibility_sort_cb(CALLBACK_ARGS){
  int i, val = (long int)data, selectall;

  if(!val){
    selectall=0;
    for(i=1 ; i<=WID->vis_browser->size(); i++)
      if(!WID->vis_browser->selected(i)){
	selectall=1;
	break;
      }
    if(selectall)
      for(i=1 ; i<=WID->vis_browser->size(); i++)
	WID->vis_browser->select(i);
    else
      WID->vis_browser->deselect();
  }
  else{
    SetVisibilitySort(val);
    opt_visibility_cb(NULL,NULL);
  }
}

void opt_visibility_number_cb(CALLBACK_ARGS){
  int pos, mode, type = WID->vis_input_mode->value();
  char *str = (char*)((Fl_Input*)w)->value(); 

  switch(WID->vis_browser_mode->value()){
  case 0 : mode = VIS_GEOM|VIS_MESH; break;
  case 1 : mode = VIS_GEOM; break;
  default: mode = VIS_MESH; break;
  }

  SetVisibilityByNumber(str, type, mode);
  pos = WID->vis_browser->position();
  opt_visibility_cb(NULL,NULL);
  WID->vis_browser->position(pos);

  Draw();
}
#endif

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
  Msg(DIRECT, "  Alt+h         hide/show all post-processing views"); 
  Msg(DIRECT, "  Alt+l         hide/show geometry lines");
  Msg(DIRECT, "  Alt+Shift+l   hide/show mesh lines");
  Msg(DIRECT, "  Alt+m         toggle visibility of all mesh entities");
  Msg(DIRECT, "  Alt+o         change projection mode");
  Msg(DIRECT, "  Alt+p         hide/show geometry points");
  Msg(DIRECT, "  Alt+Shift+p   hide/show mesh points");
  Msg(DIRECT, "  Alt+s         hide/show geometry surfaces");
  Msg(DIRECT, "  Alt+Shift+s   hide/show mesh surfaces");
  Msg(DIRECT, "  Alt+t         alternate intervals mode for visible post-processing views"); 
  Msg(DIRECT, "  Alt+v         hide/show geometry volumes");
  Msg(DIRECT, "  Alt+Shift+v   hide/show mesh volumes");
  Msg(DIRECT, "  Alt+x         set X view"); 
  Msg(DIRECT, "  Alt+y         set Y view"); 
  Msg(DIRECT, "  Alt+z         set Z view"); 
  Msg(DIRECT, "  Left arrow    previous time step"); 
  Msg(DIRECT, "  Right arrow   next time step"); 
  Msg(DIRECT, "  Up arrow      previous view"); 
  Msg(DIRECT, "  Down arrow    next view"); 
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

static void _new_multiline(int type){
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
	switch(type){
	case 0 : add_multline(n,p,CTX.filename); break;
	case 1 : add_spline(n,p,CTX.filename); break;
	case 2 : add_bspline(n,p,CTX.filename); break;
	case 3 : add_bezier(n,p,CTX.filename); break;
	}
      }
      n=0;
      ZeroHighlight(THEM);
      Draw();
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
      Draw();
      break;
    }
  }
  Msg(STATUS3N,"Ready");
}

void geometry_elementary_add_new_line_cb(CALLBACK_ARGS){
  // Disallow multiline selection at the moment, since multilines
  // dont't work so well...
  //
  //_new_multiline(0);
  //
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
    if(n == 0) Msg(STATUS3N,"Select start Point ('q'=quit)");
    if(n == 1) Msg(STATUS3N,"Select end Point ('q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1) { /* left mouse butt */
      p[n++] = v->Num; 
    }
    if(ib == 0) { /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(n == 2){
      add_multline(2,p,CTX.filename);
      ZeroHighlight(THEM);
      Draw();
      n=0;
    }
  }
  Msg(STATUS3N,"Ready");
}
void geometry_elementary_add_new_spline_cb(CALLBACK_ARGS){
  _new_multiline(1);
}
void geometry_elementary_add_new_bspline_cb(CALLBACK_ARGS){
  _new_multiline(2);
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
    if(n == 0) Msg(STATUS3N,"Select start Point ('q'=quit)");
    if(n == 1) Msg(STATUS3N,"Select center Point ('q'=quit)");
    if(n == 2) Msg(STATUS3N,"Select end Point ('q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1) { /* left mouse butt */
      p[n++] = v->Num; 
    }
    if(ib == 0) { /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(n == 3){
      add_circ(p[0],p[1],p[2],CTX.filename); /* begin, center, end */
      ZeroHighlight(THEM);
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
    if(n == 0) Msg(STATUS3N,"Select start Point ('q'=quit)");
    if(n == 1) Msg(STATUS3N,"Select center Point ('q'=quit)");
    if(n == 2) Msg(STATUS3N,"Select major axis Point ('q'=quit)");
    if(n == 3) Msg(STATUS3N,"Select end Point ('q'=quit)");
    ib = SelectEntity(ENT_POINT, &v,&c,&s);
    if(ib == 1) { /* left mouse butt */
      p[n++] = v->Num; 
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
      Draw();
      break;
    }
    if(n == 4){
      add_ell(p[0],p[1],p[2],p[3],CTX.filename);
      ZeroHighlight(THEM);
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
	ZeroHighlight(THEM);
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
	    ZeroHighlight(THEM);
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
	  ZeroHighlight(THEM);
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
      ZeroHighlight(THEM);
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
    ZeroHighlight(THEM);
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
	ZeroHighlight(THEM);
	Draw();
      }
    }
    if(ib == 0){
      ZeroHighlight(THEM);
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
  Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
}
void mesh_save_all_cb(CALLBACK_ARGS) {
  int all = CTX.mesh.save_all;
  CTX.mesh.save_all = 1;
  Print_Mesh(THEM, CTX.output_filename, CTX.mesh.format);
  CTX.mesh.save_all = all;
}
void mesh_define_cb(CALLBACK_ARGS){
  WID->set_context(menu_mesh_define, 0);
}
void mesh_1d_cb(CALLBACK_ARGS){
  mai3d(THEM, 1); 
  Draw();
  Msg(STATUS3N,"Ready");
}
void mesh_2d_cb(CALLBACK_ARGS){
  mai3d(THEM, 2);
  Draw();
  Msg(STATUS3N,"Ready");
} 
void mesh_3d_cb(CALLBACK_ARGS){
  mai3d(THEM, 3); 
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
	ZeroHighlight(THEM);
	Draw();
	break;
      }
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
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
      ZeroHighlight(THEM);
      Draw();
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
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
	    ZeroHighlight(THEM);
	    Draw();
	    break;
	  }
	  if(ib == 0){ /* 'q' */
	    n=0 ;
	    ZeroHighlight(THEM);
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
      ZeroHighlight(THEM);
      Draw();
    }
    if(ib == 0){ /* 'q' */
      n=0 ;
      ZeroHighlight(THEM);
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

void solver_cb(CALLBACK_ARGS){
  char file[256], tmp[256];
  static int first[5]={1,1,1,1,1};
  int num = (int)data;

  if(first[num]){
    first[num] = 0;
    strcpy(file,CTX.base_filename);
    strcat(file,SINFO[num].extension);
    WID->solver[num].input[0]->value(file);
  }
  if(SINFO[num].nboptions){
    sprintf(tmp, "%s %s", SINFO[num].option_command,
	    (char*)WID->solver[num].input[0]->value());
    Solver(num, tmp);
  }
  WID->create_solver_window(num);
}
void solver_file_open_cb(CALLBACK_ARGS){
  char *newfile, tmp[256];
  int num = (int)data;
  sprintf(tmp, "*%s", SINFO[num].extension);
  newfile = fl_file_chooser("Open problem definition file", tmp, NULL);
  if (newfile != NULL){
    WID->solver[num].input[0]->value(newfile);
    if(SINFO[num].nboptions){
      sprintf(tmp, "%s %s", SINFO[num].option_command, newfile);
      Solver(num, tmp);
    }
  }
}
void solver_file_edit_cb(CALLBACK_ARGS){
  char cmd[1000];
  int num = (int)data;
  sprintf(cmd, CTX.editor, WID->solver[num].input[0]->value());
  Msg(INFO, "Starting text editor '%s'", cmd);
  system(cmd);
}
void solver_choose_mesh_cb(CALLBACK_ARGS){
  char *newfile;
  int num = (int)data;
  newfile = fl_file_chooser("Open mesh file", "*.[Mm][Ss][Hh]", NULL);
  if (newfile != NULL) WID->solver[num].input[1]->value(newfile);
}
int nbs(char *str){
  int i, nb=0;
  for(i=0; i<(int)strlen(str)-1; i++){
    if(str[i]=='%' && str[i+1]=='s'){
      nb++; i++;
    }
  }
  return nb;
}
void solver_command_cb(CALLBACK_ARGS){
  char arg[512], mesh[256], command[256];
  int num = ((int*)data)[0];
  int idx = ((int*)data)[1];
  int i, usedopts = 0;

  if(SINFO[num].popup_messages) WID->create_message_window();

  if(strlen(WID->solver[num].input[1]->value()))
    sprintf(mesh, SINFO[num].mesh_command, WID->solver[num].input[1]->value());
  else 
    strcpy(mesh, "");

  //printf("num%d idx%d %s -> %d\n", 
  //	 num, idx, SINFO[num].button_command[idx], nbs(SINFO[num].button_command[idx]));

  if(nbs(SINFO[num].button_command[idx])){
    for(i=0; i<idx; i++) usedopts += nbs(SINFO[num].button_command[i]);
    if(usedopts > SINFO[num].nboptions){
      Msg(GERROR, "Missing options to execute command");
      return;
    }
    sprintf(command, SINFO[num].button_command[idx], 
	    SINFO[num].option[usedopts][WID->solver[num].choice[usedopts]->value()]);
  }
  else{
    strcpy(command, SINFO[num].button_command[idx]);
  }

  sprintf(arg, "%s %s %s", WID->solver[num].input[0]->value(), mesh, command);

  Solver(num, arg);
}
void solver_kill_cb(CALLBACK_ARGS){
  int num = (int)data;
  if(SINFO[num].pid > 0){
    kill(SINFO[num].pid, 9);
    Msg(INFO, "Killed %s pid %d", SINFO[num].name, SINFO[num].pid);
  }
  SINFO[num].pid = -1;
}
void solver_choose_executable_cb(CALLBACK_ARGS){
  char *newfile;
  int num = (int)data;
#if defined(WIN32)
  newfile = fl_file_chooser("Choose executable", "*.[Ee][Xx][Ee]", NULL);
#else
  newfile = fl_file_chooser("Choose executable", "*", NULL);
#endif
  if (newfile != NULL) WID->solver[num].input[2]->value(newfile);
}
void solver_ok_cb(CALLBACK_ARGS){
  int num = (int)data;
  int retry=0;
  opt_solver_popup_messages(num, GMSH_SET, WID->solver[num].butt[0]->value());
  opt_solver_merge_views(num, GMSH_SET, WID->solver[num].butt[1]->value());
  opt_solver_client_server(num, GMSH_SET, WID->solver[num].butt[2]->value());
  if(strcmp(opt_solver_executable(num, GMSH_GET, NULL),
	    WID->solver[num].input[2]->value())) retry=1;
  opt_solver_executable(num, GMSH_SET, (char*)WID->solver[num].input[2]->value());
  if(retry) solver_cb(NULL,data);
}

// Dynamic Post Menus

void view_toggle_cb(CALLBACK_ARGS){
  opt_view_visible((long int)data, GMSH_SET, WID->m_toggle_butt[(long int)data]->value());
  Draw();
}

static int RELOAD_ALL_VIEWS = 0 ;

void view_reload_all_cb(CALLBACK_ARGS) {
  if(!CTX.post.list) return;
  RELOAD_ALL_VIEWS = 1;
  for(int i = 0 ; i<List_Nbr(CTX.post.list) ; i++)
    view_reload_cb(NULL, (void *)i);
  RELOAD_ALL_VIEWS = 0;
  Draw();
}

void view_reload_visible_cb(CALLBACK_ARGS) {
  if(!CTX.post.list) return;
  RELOAD_ALL_VIEWS = 1;
  for(int i = 0 ; i<List_Nbr(CTX.post.list) ; i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_reload_cb(NULL, (void *)i);
  RELOAD_ALL_VIEWS = 0;
  Draw();
}

void view_reload_cb(CALLBACK_ARGS){
  Post_View tmp ;
  char filename[256];

  if(!CTX.post.list) return;

  Post_View *v = (Post_View*)List_Pointer(CTX.post.list,(long int)data);
  strcpy(filename, v->FileName);
  CopyViewOptions(v, &tmp);

  CTX.post.force_num = v->Num ;
  FreeView(v);
  MergeProblem(filename);
  CTX.post.force_num = 0 ;
  
  v = (Post_View*)List_Pointer(CTX.post.list,(long int)data);
  CopyViewOptions(&tmp, v);

  // In case the reloaded view has a different number of time steps
  if(v->TimeStep > v->NbTimeStep-1) v->TimeStep = 0;

  if(!RELOAD_ALL_VIEWS)
    Draw();
}

static int REMOVE_ALL_VIEWS = 0 ;

void view_remove_all_cb(CALLBACK_ARGS) {
  if(!CTX.post.list) return;
  REMOVE_ALL_VIEWS = 1;
  while(List_Nbr(CTX.post.list))
    view_remove_cb(NULL, (void*)0);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_visible_cb(CALLBACK_ARGS) {
  int i;
  if(!CTX.post.list) return;
  REMOVE_ALL_VIEWS = 1;
  for(i=List_Nbr(CTX.post.list)-1 ; i>=0 ; i--)
    if(opt_view_visible(i, GMSH_GET, 0))
      view_remove_cb(NULL, (void*)i);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_invisible_cb(CALLBACK_ARGS) {
  int i;
  if(!CTX.post.list) return;
  REMOVE_ALL_VIEWS = 1;
  for(i=List_Nbr(CTX.post.list)-1 ; i>=0 ; i--)
    if(!opt_view_visible(i, GMSH_GET, 0))
      view_remove_cb(NULL, (void*)i);
  REMOVE_ALL_VIEWS = 0;
  Draw();
}

void view_remove_cb(CALLBACK_ARGS){
  FreeView((long int)data);

  WID->check_anim_buttons();

  if(WID->get_context() == 3)
    WID->set_context(menu_post, 0);  

  if(!REMOVE_ALL_VIEWS)
    Draw();
}

void view_save_ascii_cb(CALLBACK_ARGS){
  char *newfile;
  if((newfile = fl_file_chooser("Save view in ASCII format", "*", NULL)))
    Write_View(0, (Post_View*)List_Pointer(CTX.post.list,(long int)data), newfile); 
}

void view_save_binary_cb(CALLBACK_ARGS){
  char *newfile;
  if((newfile = fl_file_chooser("Save view in binary format", "*", NULL)))
    Write_View(1, (Post_View*)List_Pointer(CTX.post.list,(long int)data), newfile); 
}

static void _duplicate_view(int num, int options){
  Post_View  v, *v1, *v2, *v3 ;

  if(!CTX.post.list) return;

  v1 = (Post_View*)List_Pointer(CTX.post.list,num);

  v2 = BeginView(0);
  EndView(v2, 0, v1->FileName, v1->Name);

  if(!v1->DuplicateOf){
    v2->DuplicateOf = v1->Num ;
    v1->Links++ ;
  }
  else{
    v.Num = v1->DuplicateOf ;
    if(!(v3 = (Post_View*)List_PQuery(CTX.post.list, &v, fcmpPostViewNum))){
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
  v2->NbT2 = v1->NbT2; v2->T2D = v1->T2D; v2->T2C = v1->T2C;
  v2->NbT3 = v1->NbT3; v2->T3D = v1->T3D; v2->T3C = v1->T3C;
  v2->ScalarOnly  = v1->ScalarOnly;
  v2->TextOnly    = v1->TextOnly;
  v2->Min         = v1->Min;       
  v2->Max         = v1->Max;      
  v2->NbTimeStep  = v1->NbTimeStep;

  if(options) CopyViewOptions(v1, v2);
  AddViewInUI(List_Nbr(CTX.post.list), v2->Name, v2->Num);
  Draw();
}
void view_duplicate_cb(CALLBACK_ARGS){
  _duplicate_view((long int)data,0);
}
void view_duplicate_with_options_cb(CALLBACK_ARGS){
  _duplicate_view((long int)data,1);
}

void view_applybgmesh_cb(CALLBACK_ARGS){
  Post_View *v = (Post_View*)List_Pointer(CTX.post.list,(long int)data);
  if(!v->ScalarOnly || v->TextOnly){
    Msg(GERROR, "Background mesh generation impossible with non-scalar view");
    return;
  }
  BGMWithView(v); 
}
void view_options_cb(CALLBACK_ARGS){
  WID->create_view_options_window((long int)data);
}

void view_plugin_cb(CALLBACK_ARGS){
  char name[256];
  std::pair<int,GMSH_Plugin*> *pair = (std::pair<int,GMSH_Plugin*>*)data;
  int iView = pair->first;
  GMSH_Post_Plugin *p = (GMSH_Post_Plugin*)pair->second;
  p->getName(name);

  if(p->dialogBox){//Get the values from the GUI
    int n = p->getNbOptions();
    if(n > 20)Msg(GERROR,"Plugin has too much parameters");
    for(int i=0;i<n;i++){
      StringXNumber *sxn;
      sxn = p->GetOption(i);
      sxn->def = p->dialogBox->view_value[i]->value();
    }
  }

  try{
    Post_View *v = (Post_View*)List_Pointer(CTX.post.list,iView);
    p->execute(v);
    Draw();
  }
  catch (GMSH_Plugin *err){
    p->CatchErrorMessage(name);
    Msg(WARNING,"%s",name);
  }
}

void view_options_plugin_cb(CALLBACK_ARGS){
  std::pair<int,GMSH_Plugin*> *pair =  (std::pair<int,GMSH_Plugin*>*)data;
  GMSH_Plugin *p = pair->second;

  if(!p->dialogBox) p->dialogBox = WID->create_plugin_window(p);

  p->dialogBox->run_button->callback(view_plugin_cb, (void*)pair);
  p->dialogBox->main_window->show();    
}

void view_options_custom_cb(CALLBACK_ARGS){
  if(WID->view_butt[34]->value()){
    WID->view_value[31]->activate();
    WID->view_value[32]->activate();
  }
  else{
    WID->view_value[31]->deactivate();
    WID->view_value[32]->deactivate();
  }
}

void view_options_timestep_cb(CALLBACK_ARGS){
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i=0 ; i<List_Nbr(CTX.post.list) ; i++){
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (long int)data)){
      opt_view_timestep(i, GMSH_SET, (int)((Fl_Value_Input*)w)->value());
    }
  }
  Draw();
}

void view_options_timestep_decr_cb(CALLBACK_ARGS){
  int i=(long int)data;
  opt_view_timestep(i, GMSH_SET|GMSH_GUI, opt_view_timestep(i,GMSH_GET,0)-1);
  Draw();
}
void view_options_timestep_incr_cb(CALLBACK_ARGS){
  int i=(long int)data;
  opt_view_timestep(i, GMSH_SET|GMSH_GUI, opt_view_timestep(i,GMSH_GET,0)+1);
  Draw();
}

void view_options_ok_cb(CALLBACK_ARGS){
  int i, links, force=0;

  links = (int)opt_post_link(0, GMSH_GET, 0);

  for(i=0 ; i<List_Nbr(CTX.post.list) ; i++){
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == (long int)data)){

      if(links == 3 || links == 4) force = 1;

      // view_butts

      //not this one. if(WID->view_butt[34]->changed())
      opt_view_range_type(i, GMSH_SET, 
			  WID->view_butt[34]->value()?DRAW_POST_CUSTOM:
			  DRAW_POST_DEFAULT);

      if(force || WID->view_butt[1]->changed() ||
	 WID->view_butt[2]->changed() ||
	 WID->view_butt[3]->changed())
	opt_view_type(i, GMSH_SET, 
		      WID->view_butt[1]->value()?DRAW_POST_3D:
		      WID->view_butt[2]->value()?DRAW_POST_2D_SPACE:
		      DRAW_POST_2D_TIME);

      if(force || WID->view_butt[35]->changed() ||
	 WID->view_butt[36]->changed() ||
	 WID->view_butt[37]->changed())
	opt_view_scale_type(i, GMSH_SET, 
			    WID->view_butt[35]->value()?DRAW_POST_LINEAR:
			    WID->view_butt[36]->value()?DRAW_POST_LOGARITHMIC:
			    DRAW_POST_DOUBLELOGARITHMIC);

      if(force || WID->view_butt[38]->changed())
	opt_view_saturate_values(i, GMSH_SET, 
				 WID->view_butt[38]->value());
      
      if(force || WID->view_butt[30]->changed() ||
	 WID->view_butt[31]->changed() ||
	 WID->view_butt[32]->changed() ||
	 WID->view_butt[33]->changed())
	opt_view_intervals_type(i, GMSH_SET, 
				WID->view_butt[30]->value()?DRAW_POST_ISO:
				WID->view_butt[31]->value()?DRAW_POST_DISCRETE:
				WID->view_butt[32]->value()?DRAW_POST_CONTINUOUS:
				DRAW_POST_NUMERIC);

      if(force || WID->view_butt[60]->changed() ||
	 WID->view_butt[61]->changed() ||
	 WID->view_butt[62]->changed() ||
	 WID->view_butt[63]->changed())
	opt_view_arrow_type(i, GMSH_SET, 
			    WID->view_butt[60]->value()?DRAW_POST_SEGMENT:
			    WID->view_butt[61]->value()?DRAW_POST_ARROW:
			    WID->view_butt[62]->value()?DRAW_POST_CONE:
			    DRAW_POST_DISPLACEMENT);

      if(force || WID->view_butt[64]->changed() ||
	 WID->view_butt[65]->changed())
	opt_view_arrow_location(i, GMSH_SET, 
				WID->view_butt[64]->value()?DRAW_POST_LOCATE_COG:
				DRAW_POST_LOCATE_VERTEX);

      if(force || WID->view_butt[10]->changed())
	opt_view_show_element(i, GMSH_SET, WID->view_butt[10]->value());

      if(force || WID->view_butt[4]->changed())
	opt_view_show_scale(i, GMSH_SET, WID->view_butt[4]->value());

      if(force || WID->view_butt[7]->changed())
	opt_view_auto_position(i, GMSH_SET, 
			       WID->view_butt[7]->value());

      if(force || WID->view_butt[8]->changed())
	opt_view_show_time(i, GMSH_SET, WID->view_butt[8]->value());

      if(force || WID->view_butt[5]->changed())
	opt_view_draw_strings(i, GMSH_SET, WID->view_butt[5]->value());

      if(force || WID->view_butt[6]->changed())
	opt_view_transparent_scale(i, GMSH_SET, WID->view_butt[6]->value());

      if(force || WID->view_butt[11]->changed())
	opt_view_light(i,GMSH_SET,WID->view_butt[11]->value());

      if(force || WID->view_butt[12]->changed())
	opt_view_smooth_normals(i,GMSH_SET,WID->view_butt[12]->value());
      
      if(force || WID->view_butt[13]->changed())
	opt_view_draw_points(i, GMSH_SET, WID->view_butt[13]->value());

      if(force || WID->view_butt[14]->changed())
	opt_view_draw_lines(i, GMSH_SET, WID->view_butt[14]->value());

      if(force || WID->view_butt[15]->changed())
	opt_view_draw_triangles(i, GMSH_SET, WID->view_butt[15]->value());

      if(force || WID->view_butt[16]->changed())
	opt_view_draw_tetrahedra(i, GMSH_SET, WID->view_butt[16]->value());

      if(force || WID->view_butt[17]->changed())
	opt_view_draw_scalars(i, GMSH_SET, WID->view_butt[17]->value());

      if(force || WID->view_butt[18]->changed())
	opt_view_draw_vectors(i, GMSH_SET, WID->view_butt[18]->value());

      if(force || WID->view_butt[19]->changed())
	opt_view_draw_tensors(i, GMSH_SET, WID->view_butt[19]->value());

      // view_values

      if(force || WID->view_value[31]->changed())
	opt_view_custom_min(i, GMSH_SET, WID->view_value[31]->value());
      
      if(force || WID->view_value[32]->changed())
	opt_view_custom_max(i, GMSH_SET, WID->view_value[32]->value());

      if(force || WID->view_value[30]->changed())
	opt_view_nb_iso(i, GMSH_SET, WID->view_value[30]->value());

      if(force || WID->view_value[40]->changed())
	opt_view_offset0(i, GMSH_SET, WID->view_value[40]->value());

      if(force || WID->view_value[41]->changed())
	opt_view_offset1(i, GMSH_SET, WID->view_value[41]->value());

      if(force || WID->view_value[42]->changed())
	opt_view_offset2(i, GMSH_SET, WID->view_value[42]->value());

      if(force || WID->view_value[43]->changed())
	opt_view_raise0(i, GMSH_SET, WID->view_value[43]->value());

      if(force || WID->view_value[44]->changed())
	opt_view_raise1(i, GMSH_SET, WID->view_value[44]->value());

      if(force || WID->view_value[45]->changed())
	opt_view_raise2(i, GMSH_SET, WID->view_value[45]->value());

      if(force || WID->view_value[50]->changed())
	opt_view_timestep(i, GMSH_SET, WID->view_value[50]->value());

      if(force || WID->view_value[60]->changed())
	opt_view_arrow_scale(i, GMSH_SET, WID->view_value[60]->value());

      if(force || WID->view_value[61]->changed())
	opt_view_point_size(i, GMSH_SET, WID->view_value[61]->value());

      if(force || WID->view_value[62]->changed())
	opt_view_line_width(i, GMSH_SET, WID->view_value[62]->value());

      if(force || WID->view_value[11]->changed())
	opt_view_boundary(i, GMSH_SET, WID->view_value[11]->value());

      if(force || WID->view_value[12]->changed())
	opt_view_explode(i, GMSH_SET, WID->view_value[12]->value());

      if(force || WID->view_value[10]->changed())
	opt_view_angle_smooth_normals(i,GMSH_SET,WID->view_value[10]->value());

      if(force || WID->view_value[20]->changed())
	opt_view_position0(i,GMSH_SET,WID->view_value[20]->value());

      if(force || WID->view_value[21]->changed())
	opt_view_position1(i,GMSH_SET,WID->view_value[21]->value());

      if(force || WID->view_value[22]->changed())
	opt_view_size0(i,GMSH_SET,WID->view_value[22]->value());

      if(force || WID->view_value[23]->changed())
	opt_view_size1(i,GMSH_SET,WID->view_value[23]->value());

      if(force || WID->view_value[25]->changed())
	opt_view_nb_abscissa(i,GMSH_SET,WID->view_value[25]->value());

      if(force || WID->view_value[26]->changed())
	opt_view_grid(i,GMSH_SET,WID->view_value[26]->value());

      // view_inputs

      if(force || WID->view_input[0]->changed())      
	opt_view_name(i, GMSH_SET, (char*)WID->view_input[0]->value());

      if(force || WID->view_input[1]->changed())
	opt_view_format(i, GMSH_SET, (char*)WID->view_input[1]->value());

      if(force || WID->view_input[2]->changed())
	opt_view_abscissa_name(i, GMSH_SET, (char*)WID->view_input[2]->value());

      // colorbar window

      if(force || (WID->view_colorbar_window->changed() && i!=(long int)data)){
	ColorTable_Copy(&((Post_View*)List_Pointer(CTX.post.list,(long int)data))->CT);
	ColorTable_Paste(&((Post_View*)List_Pointer(CTX.post.list,i))->CT);
      }
    }
  }

  // we clear all the flags
  for(i=0; i<VIEW_OPT_BUTT; i++){  
    if(WID->view_butt[i]) WID->view_butt[i]->clear_changed();
    if(WID->view_value[i]) WID->view_value[i]->clear_changed();
    if(WID->view_input[i]) WID->view_input[i]->clear_changed();
    WID->view_colorbar_window->clear_changed();
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
  ZeroHighlight(THEM);
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

