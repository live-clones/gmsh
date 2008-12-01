// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <signal.h>
#include <time.h>
#include <map>
#include <string>
#include <sstream>
#include <FL/fl_ask.H>
#include <FL/Fl_Color_Chooser.H>
#include "GUI.h"
#include "menuWindow.h"
#include "graphicWindow.h"
#include "optionWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "statisticsWindow.h"
#include "solverWindow.h"
#include "manipWindow.h"
#include "messageWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "contextWindow.h"
#include "aboutWindow.h"
#include "partitionDialog.h"
#include "extraDialogs.h"
#include "fileDialogs.h"
#include "GmshMessage.h"
#include "MallocUtils.h"
#include "ListUtils.h"
#include "StringUtils.h"
#include "GModel.h"
#include "MElement.h"
#include "GeoStringInterface.h"
#include "findLinks.h"
#include "Generator.h"
#include "HighOrder.h"
#include "Draw.h"
#include "SelectBuffer.h"
#include "PView.h"
#include "PViewOptions.h"
#include "PViewData.h"
#include "CreateFile.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Context.h"
#include "Options.h"
#include "Callbacks.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "Visibility.h"
#include "Numeric.h"
#include "Solvers.h"
#include "OS.h"
#include "Field.h"
#include "BackgroundMesh.h"

extern Context_T CTX;

// Helper routines

int SelectContour(int type, int num, List_T * List)
{
  int k = 0, ip;

  switch (type) {
  case ENT_LINE:
    k = allEdgesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      List_Read(List, i, &ip);
      HighlightEntityNum(0, abs(ip), 0, 0);
    }
    break;
  case ENT_SURFACE:
    k = allFacesLinked(num, List);
    for(int i = 0; i < List_Nbr(List); i++) {
      List_Read(List, i, &ip);
      HighlightEntityNum(0, 0, abs(ip), 0);
    }
    break;
  }

  Draw();
  return k;
}


// Common callbacks 

void cancel_cb(CALLBACK_ARGS)
{
  if(data)
    ((Fl_Window *) data)->hide();
}

void color_cb(CALLBACK_ARGS)
{
  unsigned int (*fct) (int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = CTX.UNPACK_RED(fct(0, GMSH_GET, 0));
  uchar g = CTX.UNPACK_GREEN(fct(0, GMSH_GET, 0));
  uchar b = CTX.UNPACK_BLUE(fct(0, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(0, GMSH_SET | GMSH_GUI, CTX.PACK_COLOR(r, g, b, 255));
  Draw();
}

void view_color_cb(CALLBACK_ARGS)
{
  unsigned int (*fct) (int, int, unsigned int);
  fct = (unsigned int (*)(int, int, unsigned int))data;
  uchar r = CTX.UNPACK_RED(fct(GUI::instance()->options->view.index, GMSH_GET, 0));
  uchar g = CTX.UNPACK_GREEN(fct(GUI::instance()->options->view.index, GMSH_GET, 0));
  uchar b = CTX.UNPACK_BLUE(fct(GUI::instance()->options->view.index, GMSH_GET, 0));
  if(fl_color_chooser("Color Chooser", r, g, b))
    fct(GUI::instance()->options->view.index, GMSH_SET | GMSH_GUI, CTX.PACK_COLOR(r, g, b, 255));
  Draw();
}

void redraw_cb(CALLBACK_ARGS)
{
  Draw();
}

void window_cb(CALLBACK_ARGS)
{
  static int oldx = 0, oldy = 0, oldw = 0, oldh = 0, zoom = 1;
  const char *str = (const char*)data;

  if(!strcmp(str, "minimize")){
    GUI::instance()->graph[0]->win->iconize();
    if(GUI::instance()->options->win->shown()) GUI::instance()->options->win->iconize();
    if(GUI::instance()->plugins->win->shown()) GUI::instance()->plugins->win->iconize();
    if(GUI::instance()->fields->win->shown()) GUI::instance()->fields->win->iconize();
    if(GUI::instance()->visibility->win->shown()) GUI::instance()->visibility->win->iconize();
    if(GUI::instance()->clipping->win->shown()) GUI::instance()->clipping->win->iconize();
    if(GUI::instance()->manip->win->shown()) GUI::instance()->manip->win->iconize();
    if(GUI::instance()->stats->win->shown()) GUI::instance()->stats->win->iconize();
    if(GUI::instance()->messages->win->shown()) GUI::instance()->messages->win->iconize();
    GUI::instance()->menu->win->iconize();
  }
  else if(!strcmp(str, "zoom")){
    if(zoom){
      oldx = GUI::instance()->graph[0]->win->x();
      oldy = GUI::instance()->graph[0]->win->y();
      oldw = GUI::instance()->graph[0]->win->w();
      oldh = GUI::instance()->graph[0]->win->h();
      GUI::instance()->graph[0]->win->resize(Fl::x(), Fl::y(), Fl::w(), Fl::h());
      zoom = 0;
    }
    else{
      GUI::instance()->graph[0]->win->resize(oldx, oldy, oldw, oldh);
      zoom = 1;
    }
    GUI::instance()->graph[0]->win->show();
    GUI::instance()->menu->win->show();
  }
  else if(!strcmp(str, "front")){
    // the order is important!
    GUI::instance()->graph[0]->win->show();
    if(GUI::instance()->options->win->shown()) GUI::instance()->options->win->show();
    if(GUI::instance()->plugins->win->shown()) GUI::instance()->plugins->win->show();
    if(GUI::instance()->fields->win->shown()) GUI::instance()->fields->win->show();
    if(GUI::instance()->geoContext->win->shown()) GUI::instance()->geoContext->win->show();
    if(GUI::instance()->meshContext->win->shown()) GUI::instance()->meshContext->win->show();
    for(unsigned int i = 0; i < GUI::instance()->solver.size(); i++) {
      if(GUI::instance()->solver[i]->win->shown()) GUI::instance()->solver[i]->win->show();
    }
    if(GUI::instance()->visibility->win->shown()) GUI::instance()->visibility->win->show();
    if(GUI::instance()->clipping->win->shown()) GUI::instance()->clipping->win->show();
    if(GUI::instance()->manip->win->shown()) GUI::instance()->manip->win->show();
    if(GUI::instance()->stats->win->shown()) GUI::instance()->stats->win->show();
    if(GUI::instance()->messages->win->shown()) GUI::instance()->messages->win->show();
    GUI::instance()->menu->win->show();
  }
}

void activate_cb(CALLBACK_ARGS)
{
  // this is a central callback to activate/deactivate parts of the
  // GUI depending on the user's choices (or the option settings)

  if(!data) return;

  optionWindow *o = GUI::instance()->options;

  const char *str = (const char*)data;

  if(!strcmp(str, "fast_redraw")){
    if(o->general.butt[2]->value())
      GUI::instance()->options->redraw->show();
    else
      GUI::instance()->options->redraw->hide();
  }
  else if(!strcmp(str, "rotation_center")){
    if(o->general.butt[15]->value()) {
      o->general.push[0]->deactivate();
      o->general.value[8]->deactivate();
      o->general.value[9]->deactivate();
      o->general.value[10]->deactivate();
    }
    else {
      o->general.push[0]->activate();
      o->general.value[8]->activate();
      o->general.value[9]->activate();
      o->general.value[10]->activate();
    }
  }
  else if(!strcmp(str, "general_axes")){
    if(o->general.choice[4]->value()){
      o->general.value[17]->activate();
      o->general.value[18]->activate();
      o->general.value[19]->activate();
      o->general.input[3]->activate();
      o->general.input[4]->activate();
      o->general.input[5]->activate();
      o->general.input[6]->activate();
      o->general.input[7]->activate();
      o->general.input[8]->activate();
    }
    else{
      o->general.value[17]->deactivate();
      o->general.value[18]->deactivate();
      o->general.value[19]->deactivate();
      o->general.input[3]->deactivate();
      o->general.input[4]->deactivate();
      o->general.input[5]->deactivate();
      o->general.input[6]->deactivate();
      o->general.input[7]->deactivate();
      o->general.input[8]->deactivate();
    }
  }
  else if(!strcmp(str, "general_axes_auto")){
    if(o->general.butt[0]->value()){
      o->general.value[20]->deactivate();
      o->general.value[21]->deactivate();
      o->general.value[22]->deactivate();
      o->general.value[23]->deactivate();
      o->general.value[24]->deactivate();
      o->general.value[25]->deactivate();
    }
    else{
      o->general.value[20]->activate();
      o->general.value[21]->activate();
      o->general.value[22]->activate();
      o->general.value[23]->activate();
      o->general.value[24]->activate();
      o->general.value[25]->activate();
    }
  }
  else if(!strcmp(str, "general_small_axes")){
    if(o->general.butt[1]->value()){
      o->general.value[26]->activate();
      o->general.value[27]->activate();
    }
    else{
      o->general.value[26]->deactivate();
      o->general.value[27]->deactivate();
    }
  }
  else if(!strcmp(str, "custom_range")){
    if(o->view.choice[7]->value() == 1){
      o->view.value[31]->activate();
      o->view.value[32]->activate();
      o->view.push[1]->activate();
      o->view.push[2]->activate();
    }
    else {
      o->view.value[31]->deactivate();
      o->view.value[32]->deactivate();
      o->view.push[1]->deactivate();
      o->view.push[2]->deactivate();
    }
  }
  else if(!strcmp(str, "general_transform")){
    if(o->view.butt[6]->value()){
      o->view.choice[11]->activate();
      o->view.value[2]->activate();
      o->view.input[4]->activate();
      o->view.input[5]->activate();
      o->view.input[6]->activate();
    }
    else{
      o->view.choice[11]->deactivate();
      o->view.value[2]->deactivate();
      o->view.input[4]->deactivate();
      o->view.input[5]->deactivate();
      o->view.input[6]->deactivate();
    }
  }
  else if(!strcmp(str, "mesh_light")){
    if(o->mesh.butt[17]->value()){
      o->mesh.butt[18]->activate();
      o->mesh.butt[19]->activate();
      o->mesh.butt[20]->activate();
      o->mesh.butt[0]->activate();
      o->mesh.value[18]->activate();
    }
    else{
      o->mesh.butt[18]->deactivate();
      o->mesh.butt[19]->deactivate();
      o->mesh.butt[20]->deactivate();
      o->mesh.butt[0]->deactivate();
      o->mesh.value[18]->deactivate();
    }
  }
  else if(!strcmp(str, "view_light")){
    if(o->view.butt[11]->value()){
      o->view.butt[8]->activate();
      o->view.butt[9]->activate();
      o->view.butt[12]->activate();
      o->view.value[10]->activate();
    }
    else{
      o->view.butt[8]->deactivate();
      o->view.butt[9]->deactivate();
      o->view.butt[12]->deactivate();
      o->view.value[10]->deactivate();
    }
  }
  else if(!strcmp(str, "view_axes")){
    if(o->view.choice[8]->value()){
      o->view.value[3]->activate();
      o->view.value[4]->activate();
      o->view.value[5]->activate();
      o->view.input[7]->activate();
      o->view.input[8]->activate();
      o->view.input[9]->activate();
      o->view.input[10]->activate();
      o->view.input[11]->activate();
      o->view.input[12]->activate();
    }
    else{
      o->view.value[3]->deactivate();
      o->view.value[4]->deactivate();
      o->view.value[5]->deactivate();
      o->view.input[7]->deactivate();
      o->view.input[8]->deactivate();
      o->view.input[9]->deactivate();
      o->view.input[10]->deactivate();
      o->view.input[11]->deactivate();
      o->view.input[12]->deactivate();
    }
  }
  else if(!strcmp(str, "view_axes_auto_3d")){
    if(o->view.butt[25]->value()){
      o->view.value[13]->deactivate();
      o->view.value[14]->deactivate();
      o->view.value[15]->deactivate();
      o->view.value[16]->deactivate();
      o->view.value[17]->deactivate();
      o->view.value[18]->deactivate();
    }
    else{
      o->view.value[13]->activate();
      o->view.value[14]->activate();
      o->view.value[15]->activate();
      o->view.value[16]->activate();
      o->view.value[17]->activate();
      o->view.value[18]->activate();
    }
  }
  else if(!strcmp(str, "view_axes_auto_2d")){
    if(o->view.butt[7]->value()){
      o->view.value[20]->deactivate();
      o->view.value[21]->deactivate();
      o->view.value[22]->deactivate();
      o->view.value[23]->deactivate();
    }
    else{
      o->view.value[20]->activate();
      o->view.value[21]->activate();
      o->view.value[22]->activate();
      o->view.value[23]->activate();
    }
  }
}

// Graphical window 

void status_xyz1p_cb(CALLBACK_ARGS)
{
  const char *str = (const char*)data;

  drawContext *ctx = GUI::instance()->graph[0]->gl->getDrawContext();

  if(!strcmp(str, "r")){ // rotate 90 degress around axis perp to the screen
    double axis[3] = {0., 0., 1.};
    if(!Fl::event_state(FL_SHIFT))
      ctx->addQuaternionFromAxisAndAngle(axis, -90.);
    else
      ctx->addQuaternionFromAxisAndAngle(axis, 90.);
    Draw();
  }
  else if(!strcmp(str, "x")){ // X pointing out or into the screen
    if(!Fl::event_state(FL_SHIFT)){
      ctx->r[0] = -90.;
      ctx->r[1] = 0.;
      ctx->r[2] = -90.;
    }
    else{
      ctx->r[0] = -90.;
      ctx->r[1] = 0.;
      ctx->r[2] = 90.;
    }
    ctx->setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "y")){ // Y pointing out or into the screen
    if(!Fl::event_state(FL_SHIFT)){
      ctx->r[0] = -90.;
      ctx->r[1] = 0.;
      ctx->r[2] = 180.;
    }
    else{
      ctx->r[0] = -90.;
      ctx->r[1] = 0.;
      ctx->r[2] = 0.;
    }
    ctx->setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "z")){ // Z pointing out or into the screen
    if(!Fl::event_state(FL_SHIFT)){
      ctx->r[0] = 0.;
      ctx->r[1] = 0.;
      ctx->r[2] = 0.;
    }
    else{
      ctx->r[0] = 0.;
      ctx->r[1] = 180.;
      ctx->r[2] = 0.;
    }
    ctx->setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "1:1")){ // reset translation and scaling
    ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
    ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
    Draw();
  }
  else if(!strcmp(str, "reset")){ // reset everything
    ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
    ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
    ctx->r[0] = 0.;
    ctx->r[1] = 0.;
    ctx->r[2] = 0.;
    ctx->setQuaternionFromEulerAngles();
    Draw();
  }
  else if(!strcmp(str, "p")){ // toggle projection mode
    if(!Fl::event_state(FL_SHIFT)){
      opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 
                               !opt_general_orthographic(0, GMSH_GET, 0));
    }
    else{
      perspective_editor();
    }
    Draw();
  }
  else if(!strcmp(str, "model")){ // toggle projection mode
    model_chooser();
  }
  else if(!strcmp(str, "?")){ // display options
    Print_Options(0, GMSH_FULLRC, 0, 1, NULL);
    GUI::instance()->messages->show();
  }
  else if(!strcmp(str, "S")){ // mouse selection
    if(CTX.mouse_selection){
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
      GUI::instance()->graph[0]->gl->cursor(FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
    }
    else
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  }
  GUI::instance()->manip->update();
}

static int stop_anim, view_in_cycle = -1;

void ManualPlay(int time, int step)
{
  // avoid firing ManualPlay recursively (can happen e.g when keeping
  // the finger down on the arrow key: if the system generates too
  // many events, we can overflow the stack--that happened on my
  // powerbook with the new, optimzed FLTK event handler)
  static bool busy = false;
  if(busy) return;
  busy = true;
  if(time) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                          opt_view_timestep(i, GMSH_GET, 0) + step);
  }
  else { // hide all views except view_in_cycle
    if(step > 0) {
      if((view_in_cycle += step) >= (int)PView::list.size())
        view_in_cycle = 0;
      for(int i = 0; i < (int)PView::list.size(); i += step)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else {
      if((view_in_cycle += step) < 0)
        view_in_cycle = PView::list.size() - 1;
      for(int i = PView::list.size() - 1; i >= 0; i += step)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
  }
  Draw();
  busy = false;
}

void status_play_cb(CALLBACK_ARGS)
{
  static double anim_time;
  GUI::instance()->graph[0]->setAnimButtons(0);
  stop_anim = 0;
  anim_time = GetTimeInSeconds();
  while(1) {
    if(stop_anim)
      break;
    if(GetTimeInSeconds() - anim_time > CTX.post.anim_delay) {
      anim_time = GetTimeInSeconds();
      ManualPlay(!CTX.post.anim_cycle, 1);
    }
    GUI::instance()->check();
  }
}

void status_pause_cb(CALLBACK_ARGS)
{
  stop_anim = 1;
  GUI::instance()->graph[0]->setAnimButtons(1);
}

void status_rewind_cb(CALLBACK_ARGS)
{
  if(!CTX.post.anim_cycle) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      opt_view_timestep(i, GMSH_SET | GMSH_GUI, 0);
  }
  else {
    view_in_cycle = 0;
    for(unsigned int i = 0; i < PView::list.size(); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, !i);
  }
  Draw();
}

void status_stepbackward_cb(CALLBACK_ARGS)
{
  ManualPlay(!CTX.post.anim_cycle, -1);
}

void status_stepforward_cb(CALLBACK_ARGS)
{
  ManualPlay(!CTX.post.anim_cycle, 1);
}

// File Menu

void file_new_cb(CALLBACK_ARGS)
{
 test:
  if(file_chooser(0, 1, "New", "*")) {
    std::string name = file_chooser_get_name(1);
    if(!StatFile(name.c_str())){
      if(fl_choice("File '%s' already exists.\n\nDo you want to erase it?",
                   "Cancel", "Erase", NULL, name.c_str()))
        UnlinkFile(name.c_str());
      else
        goto test;
    }
    FILE *fp = fopen(name.c_str(), "w");
    if(!fp){
      Msg::Error("Unable to open file '%s'", name.c_str());
      return;
    }
    time_t now;
    time(&now);
    fprintf(fp, "// Gmsh project created on %s", ctime(&now));
    fclose(fp);
    OpenProject(name.c_str());
    Draw();
  }
}

#if defined(HAVE_NATIVE_FILE_CHOOSER)
#  define TT "\t"
#  define NN "\n"
#else
#  define TT " ("
#  define NN ")\t"
#endif

static const char *input_formats =
  "All files" TT "*" NN
  "Gmsh geometry" TT "*.geo" NN
  "Gmsh mesh" TT "*.msh" NN
  "Gmsh post-processing view" TT "*.pos" NN
#if defined(HAVE_OCC)
  "STEP model" TT "*.{stp,step}" NN
  "IGES model" TT "*.{igs,iges}" NN
  "BRep model" TT "*.brep" NN
#endif
  "I-deas universal mesh" TT "*.unv" NN
  "Diffpack 3D mesh" TT "*.diff" NN
  "VTK mesh" TT "*.vtk" NN
#if defined(HAVE_MED)
  "MED file" TT "*.{med,mmed,rmed}" NN
#endif
  "Medit mesh" TT "*.mesh" NN
  "Nastran bulk data file" TT "*.{bdf,nas}" NN
  "Plot3D structured mesh" TT "*.p3d" NN
  "STL surface mesh" TT "*.stl" NN
  "VRML surface mesh" TT "*.{wrl,vrml}" NN
#if defined(HAVE_LIBJPEG)
  "JPEG" TT "*.{jpg,jpeg}" NN
#endif
#if defined(HAVE_LIBPNG)
  "PNG" TT "*.png" NN
#endif
  "BMP" TT "*.bmp" NN
  "PPM" TT "*.ppm" NN
  "PGM" TT "*.pgm" NN
  "PBM" TT "*.pbm" NN
  "PNM" TT "*.pnm" NN;

#undef TT
#undef NN


void file_open_cb(CALLBACK_ARGS)
{
  int n = PView::list.size();
  if(file_chooser(0, 0, "Open", input_formats)) {
    OpenProject(file_chooser_get_name(1).c_str());
    Draw();
  }
  if(n != (int)PView::list.size())
    GUI::instance()->menu->setContext(menu_post, 0);
}

void file_merge_cb(CALLBACK_ARGS)
{
  int n = PView::list.size();
  int f = file_chooser(1, 0, "Merge", input_formats);
  if(f) {
    for(int i = 1; i <= f; i++)
      MergeFile(file_chooser_get_name(i).c_str());
    Draw();
  }
  if(n != (int)PView::list.size())
    GUI::instance()->menu->setContext(menu_post, 0);
}

int _save_msh(const char *name){ return msh_dialog(name); }
int _save_pos(const char *name){ return pos_dialog(name); }
int _save_options(const char *name){ return options_dialog(name); }
int _save_geo(const char *name){ return geo_dialog(name); }
int _save_cgns(const char *name){ return cgns_write_dialog(name); }
int _save_unv(const char *name){ return unv_dialog(name); }
int _save_vtk(const char *name){ return generic_mesh_dialog(name, "VTK Options", FORMAT_VTK, true); }
int _save_diff(const char *name){ return generic_mesh_dialog(name, "Diffpack Options", FORMAT_DIFF, true); }
int _save_med(const char *name){ return generic_mesh_dialog(name, "MED Options", FORMAT_MED, false); }
int _save_mesh(const char *name){ return generic_mesh_dialog(name, "MESH Options", FORMAT_MESH, false); }
int _save_bdf(const char *name){ return bdf_dialog(name); }
int _save_p3d(const char *name){ return generic_mesh_dialog(name, "P3D Options", FORMAT_P3D, false); }
int _save_stl(const char *name){ return generic_mesh_dialog(name, "STL Options", FORMAT_STL, true); }
int _save_vrml(const char *name){ return generic_mesh_dialog(name, "VRML Options", FORMAT_VRML, false); }
int _save_eps(const char *name){ return gl2ps_dialog(name, "EPS Options", FORMAT_EPS); }
int _save_gif(const char *name){ return gif_dialog(name); }
int _save_jpeg(const char *name){ return jpeg_dialog(name); }
int _save_tex(const char *name){ return latex_dialog(name); }
int _save_pdf(const char *name){ return gl2ps_dialog(name, "PDF Options", FORMAT_PDF); }
int _save_png(const char *name){ return generic_bitmap_dialog(name, "PNG Options", FORMAT_PNG); }
int _save_ps(const char *name){ return gl2ps_dialog(name, "PS Options", FORMAT_PS); }
int _save_ppm(const char *name){ return generic_bitmap_dialog(name, "PPM Options", FORMAT_PPM); }
int _save_svg(const char *name){ return gl2ps_dialog(name, "SVG Options", FORMAT_SVG); }
int _save_yuv(const char *name){ return generic_bitmap_dialog(name, "YUV Options", FORMAT_YUV); }

int _save_auto(const char *name)
{
  switch(GuessFileFormatFromFileName(name)){
  case FORMAT_MSH  : return _save_msh(name);
  case FORMAT_POS  : return _save_pos(name);
  case FORMAT_OPT  : return _save_options(name);
  case FORMAT_GEO  : return _save_geo(name);
  case FORMAT_CGNS : return _save_cgns(name);
  case FORMAT_UNV  : return _save_unv(name);
  case FORMAT_VTK  : return _save_vtk(name);
  case FORMAT_MED  : return _save_med(name);
  case FORMAT_MESH : return _save_mesh(name);
  case FORMAT_BDF  : return _save_bdf(name);
  case FORMAT_DIFF : return _save_diff(name);
  case FORMAT_P3D  : return _save_p3d(name);
  case FORMAT_STL  : return _save_stl(name);
  case FORMAT_VRML : return _save_vrml(name);
  case FORMAT_EPS  : return _save_eps(name);
  case FORMAT_GIF  : return _save_gif(name);
  case FORMAT_JPEG : return _save_jpeg(name);
  case FORMAT_TEX  : return _save_tex(name);
  case FORMAT_PDF  : return _save_pdf(name);
  case FORMAT_PNG  : return _save_png(name);
  case FORMAT_PS   : return _save_ps(name);
  case FORMAT_PPM  : return _save_ppm(name);
  case FORMAT_SVG  : return _save_svg(name);
  case FORMAT_YUV  : return _save_yuv(name);
  default :
    CreateOutputFile(name, FORMAT_AUTO); 
    return 1;
  }
}

typedef struct{
  const char *pat;
  int (*func) (const char *name);
} patXfunc;

void file_save_as_cb(CALLBACK_ARGS)
{
#if defined(HAVE_NATIVE_FILE_CHOOSER)
#  define TT "\t"
#  define NN "\n"
#else
#  define TT " ("
#  define NN ")\t"
#endif

  static patXfunc formats[] = {
    {"Guess from extension" TT "*.*", _save_auto},
    {"Gmsh mesh" TT "*.msh", _save_msh},
    {"Gmsh mesh statistics" TT "*.pos", _save_pos},
    {"Gmsh options" TT "*.opt", _save_options},
    {"Gmsh unrolled geometry" TT "*.geo", _save_geo},
#if defined(HAVE_LIBCGNS)
    {"CGNS" TT "*.cgns", _save_cgns},
#endif
    {"I-deas universal mesh" TT "*.unv", _save_unv},
    {"Diffpack 3D mesh" TT "*.diff", _save_diff},
    {"VTK mesh" TT "*.vtk", _save_vtk},
#if defined(HAVE_MED)
    {"MED file" TT "*.med", _save_med},
#endif
    {"Medit mesh" TT "*.mesh", _save_mesh},
    {"Nastran bulk data file" TT "*.bdf", _save_bdf},
    {"Plot3D structured mesh" TT "*.p3d", _save_p3d},
    {"STL surface mesh" TT "*.stl", _save_stl},
    {"VRML surface mesh" TT "*.wrl", _save_vrml},
    {"Encapsulated PostScript" TT "*.eps", _save_eps},
    {"GIF" TT "*.gif", _save_gif},
#if defined(HAVE_LIBJPEG)
    {"JPEG" TT "*.jpg", _save_jpeg},
#endif
    {"LaTeX" TT "*.tex", _save_tex},
    {"PDF" TT "*.pdf", _save_pdf},
#if defined(HAVE_LIBPNG)
    {"PNG" TT "*.png", _save_png},
#endif
    {"PostScript" TT "*.ps", _save_ps},
    {"PPM" TT "*.ppm", _save_ppm},
    {"SVG" TT "*.svg", _save_svg},
    {"YUV" TT "*.yuv", _save_yuv},
  };

  int nbformats = sizeof(formats) / sizeof(formats[0]);
  static char *pat = NULL;
  if(!pat) {
    pat = (char *)Malloc(nbformats * 256 * sizeof(char));
    strcpy(pat, formats[0].pat);
    for(int i = 1; i < nbformats; i++) {
      strcat(pat, NN);
      strcat(pat, formats[i].pat);
    }
  }

#undef TT
#undef NN

 test:
  if(file_chooser(0, 1, "Save As", pat)) {
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    int i = file_chooser_get_filter();
    if(i >= 0 && i < nbformats){
      if(!formats[i].func(name.c_str())) goto test;
    }
    else{ // handle any additional automatic fltk filter
      if(!_save_auto(name.c_str())) goto test;
    }
  }
}

void file_rename_cb(CALLBACK_ARGS)
{
 test:
  if(file_chooser(0, 1, "Rename", "*", CTX.filename)) {
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    rename(CTX.filename, name.c_str());
    OpenProject(name.c_str());
    Draw();
  }
}

void file_quit_cb(CALLBACK_ARGS)
{
  Msg::Exit(0);
}

// Option Menu

void options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->win->show();
}

void options_browser_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup(GUI::instance()->options->browser->value());
}

void options_save_cb(CALLBACK_ARGS)
{
  Msg::StatusBar(2, true, "Writing '%s'", CTX.options_filename_fullpath);
  Print_Options(0, GMSH_OPTIONSRC, 1, 1, CTX.options_filename_fullpath);
  Msg::StatusBar(2, true, "Wrote '%s'", CTX.options_filename_fullpath);
}

void options_restore_defaults_cb(CALLBACK_ARGS)
{
  // not sure if we have to remove the file...
  UnlinkFile(CTX.session_filename_fullpath);
  UnlinkFile(CTX.options_filename_fullpath);
  ReInit_Options(0);
  Init_Options_GUI(0);
  if(GUI::instance()->menu->module->value() == 3) // hack to refresh the buttons
    GUI::instance()->menu->setContext(menu_post, 0);
  Draw();
}

// General options

void general_options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup(1);
}

void general_options_color_scheme_cb(CALLBACK_ARGS)
{
  opt_general_color_scheme(0, GMSH_SET, GUI::instance()->options->general.choice[3]->value());
  Draw();
}

void general_options_rotation_center_select_cb(CALLBACK_ARGS)
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;

  Msg::StatusBar(3, false, "Select entity\n[Press 'q' to abort]");
  char ib = SelectEntity(ENT_ALL, vertices, edges, faces, regions, elements);
  if(ib == 'l') {
    SPoint3 pc(0., 0., 0.);
    if(vertices.size())
      pc.setPosition(vertices[0]->x(), vertices[0]->y(), vertices[0]->z());
    else if(edges.size())
      pc = edges[0]->bounds().center();
    else if(faces.size())
      pc = faces[0]->bounds().center();
    else if(regions.size())
      pc = regions[0]->bounds().center();
    else if(elements.size())
      pc = elements[0]->barycenter();
    opt_general_rotation_center_cg(0, GMSH_SET, GUI::instance()->options->general.butt[15]->value());
    opt_general_rotation_center0(0, GMSH_SET|GMSH_GUI, pc.x());
    opt_general_rotation_center1(0, GMSH_SET|GMSH_GUI, pc.y());
    opt_general_rotation_center2(0, GMSH_SET|GMSH_GUI, pc.z());
  }
  ZeroHighlight();
  Draw();
  Msg::StatusBar(3, false, "");
}

void general_options_ok_cb(CALLBACK_ARGS)
{
  activate_cb(NULL, data);

  optionWindow *o = GUI::instance()->options;

  static double lc = 0.;
  if(lc != CTX.lc){
    lc = CTX.lc;
    for(int i = 2; i < 5; i++){
      o->general.value[i]->minimum(-5 * CTX.lc);
      o->general.value[i]->maximum(5 * CTX.lc);
    }
  }
  if(data){
    const char *name = (const char*)data;
    if(!strcmp(name, "rotation_center_coord")){
      CTX.draw_rotation_center = 1;
    }
    else if(!strcmp(name, "light_value")){
      double x, y, z;
      x = o->general.value[2]->value();
      y = o->general.value[3]->value();
      z = o->general.value[4]->value();
      o->general.sphere->setValue(x, y, z);    
    }
    else if(!strcmp(name, "light_sphere")){
      double x, y, z;
      o->general.sphere->getValue(x, y, z);
      o->general.value[2]->value(x);
      o->general.value[3]->value(y);
      o->general.value[4]->value(z);
    }
  }

  opt_general_axes_auto_position(0, GMSH_SET, o->general.butt[0]->value());
  opt_general_small_axes(0, GMSH_SET, o->general.butt[1]->value());
  opt_general_fast_redraw(0, GMSH_SET, o->general.butt[2]->value());
  opt_general_mouse_hover_meshes(0, GMSH_SET, o->general.butt[11]->value());
  if(opt_general_double_buffer(0, GMSH_GET, 0) != o->general.butt[3]->value())
    opt_general_double_buffer(0, GMSH_SET, o->general.butt[3]->value());
  if(opt_general_antialiasing(0, GMSH_GET, 0) != o->general.butt[12]->value())
    opt_general_antialiasing(0, GMSH_SET, o->general.butt[12]->value());
  opt_general_trackball(0, GMSH_SET, o->general.butt[5]->value());
  opt_general_terminal(0, GMSH_SET, o->general.butt[7]->value());
  double sessionrc = opt_general_session_save(0, GMSH_GET, 0);
  opt_general_session_save(0, GMSH_SET, o->general.butt[8]->value());
  if(sessionrc && !opt_general_session_save(0, GMSH_GET, 0))
    Print_Options(0, GMSH_SESSIONRC, 1, 1, CTX.session_filename_fullpath);
  opt_general_options_save(0, GMSH_SET, o->general.butt[9]->value());
  opt_general_expert_mode(0, GMSH_SET, o->general.butt[10]->value());
  opt_general_tooltips(0, GMSH_SET, o->general.butt[13]->value());
  opt_general_confirm_overwrite(0, GMSH_SET, o->general.butt[14]->value());
  opt_general_rotation_center_cg(0, GMSH_SET, o->general.butt[15]->value());
  opt_general_draw_bounding_box(0, GMSH_SET, o->general.butt[6]->value());
  opt_general_polygon_offset_always(0, GMSH_SET, o->general.butt[4]->value());
  opt_general_axes_mikado(0, GMSH_SET, o->general.butt[16]->value());

  opt_general_shine_exponent(0, GMSH_SET, o->general.value[0]->value());  
  opt_general_shine(0, GMSH_SET, o->general.value[1]->value());
  opt_general_light00(0, GMSH_SET, o->general.value[2]->value());
  opt_general_light01(0, GMSH_SET, o->general.value[3]->value());
  opt_general_light02(0, GMSH_SET, o->general.value[4]->value());
  opt_general_light03(0, GMSH_SET, o->general.value[13]->value());
  opt_general_verbosity(0, GMSH_SET, o->general.value[5]->value());
  opt_general_point_size(0, GMSH_SET, o->general.value[6]->value());
  opt_general_line_width(0, GMSH_SET, o->general.value[7]->value());
  opt_general_rotation_center0(0, GMSH_SET, o->general.value[8]->value());
  opt_general_rotation_center1(0, GMSH_SET, o->general.value[9]->value());
  opt_general_rotation_center2(0, GMSH_SET, o->general.value[10]->value());
  opt_general_quadric_subdivisions(0, GMSH_SET, o->general.value[11]->value());
  opt_general_graphics_fontsize(0, GMSH_SET, o->general.value[12]->value());
  opt_general_clip_factor(0, GMSH_SET, o->general.value[14]->value());
  opt_general_polygon_offset_factor(0, GMSH_SET, o->general.value[15]->value());
  opt_general_polygon_offset_units(0, GMSH_SET, o->general.value[16]->value());
  opt_general_axes_tics0(0, GMSH_SET, o->general.value[17]->value());
  opt_general_axes_tics1(0, GMSH_SET, o->general.value[18]->value());
  opt_general_axes_tics2(0, GMSH_SET, o->general.value[19]->value());
  opt_general_axes_xmin(0, GMSH_SET, o->general.value[20]->value());
  opt_general_axes_ymin(0, GMSH_SET, o->general.value[21]->value());
  opt_general_axes_zmin(0, GMSH_SET, o->general.value[22]->value());
  opt_general_axes_xmax(0, GMSH_SET, o->general.value[23]->value());
  opt_general_axes_ymax(0, GMSH_SET, o->general.value[24]->value());
  opt_general_axes_zmax(0, GMSH_SET, o->general.value[25]->value());
  opt_general_small_axes_position0(0, GMSH_SET, o->general.value[26]->value());
  opt_general_small_axes_position1(0, GMSH_SET, o->general.value[27]->value());

  opt_general_default_filename(0, GMSH_SET, o->general.input[0]->value());
  opt_general_editor(0, GMSH_SET, o->general.input[1]->value());
  opt_general_web_browser(0, GMSH_SET, o->general.input[2]->value());
  opt_general_axes_format0(0, GMSH_SET, o->general.input[3]->value());
  opt_general_axes_format1(0, GMSH_SET, o->general.input[4]->value());
  opt_general_axes_format2(0, GMSH_SET, o->general.input[5]->value());
  opt_general_axes_label0(0, GMSH_SET, o->general.input[6]->value());
  opt_general_axes_label1(0, GMSH_SET, o->general.input[7]->value());
  opt_general_axes_label2(0, GMSH_SET, o->general.input[8]->value());

  opt_general_vector_type(0, GMSH_SET, o->general.choice[0]->value() + 1);
  opt_general_graphics_font(0, GMSH_SET, o->general.choice[1]->text());
  opt_general_orthographic(0, GMSH_SET, !o->general.choice[2]->value());
  opt_general_axes(0, GMSH_SET, o->general.choice[4]->value());
  opt_general_background_gradient(0, GMSH_SET, o->general.choice[5]->value());

  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.post.draw = CTX.mesh.draw = 1;
  CTX.draw_rotation_center = 0;
}

void general_arrow_param_cb(CALLBACK_ARGS)
{
  double a = opt_general_arrow_head_radius(0, GMSH_GET, 0);
  double b = opt_general_arrow_stem_length(0, GMSH_GET, 0);
  double c = opt_general_arrow_stem_radius(0, GMSH_GET, 0);
  while(arrow_editor("Arrow Editor", a, b, c)){
    opt_general_arrow_head_radius(0, GMSH_SET, a);
    opt_general_arrow_stem_length(0, GMSH_SET, b);
    opt_general_arrow_stem_radius(0, GMSH_SET, c);
    Draw();
  }
}

// Geometry options

void geometry_options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup(2);
}

void geometry_options_ok_cb(CALLBACK_ARGS)
{
  activate_cb(NULL, data);

  optionWindow *o = GUI::instance()->options;

  opt_geometry_points(0, GMSH_SET, o->geo.butt[0]->value());
  opt_geometry_lines(0, GMSH_SET, o->geo.butt[1]->value());
  opt_geometry_surfaces(0, GMSH_SET, o->geo.butt[2]->value());
  opt_geometry_volumes(0, GMSH_SET, o->geo.butt[3]->value());
  opt_geometry_points_num(0, GMSH_SET, o->geo.butt[4]->value());
  opt_geometry_lines_num(0, GMSH_SET, o->geo.butt[5]->value());
  opt_geometry_surfaces_num(0, GMSH_SET, o->geo.butt[6]->value());
  opt_geometry_volumes_num(0, GMSH_SET, o->geo.butt[7]->value());
  opt_geometry_auto_coherence(0, GMSH_SET, o->geo.butt[8]->value());
  opt_geometry_light(0, GMSH_SET, o->geo.butt[9]->value());
  opt_geometry_highlight_orphans(0, GMSH_SET, o->geo.butt[10]->value());
  opt_geometry_occ_fix_small_edges(0, GMSH_SET, o->geo.butt[11]->value());
  opt_geometry_occ_fix_small_faces(0, GMSH_SET, o->geo.butt[12]->value());
  opt_geometry_occ_sew_faces(0, GMSH_SET, o->geo.butt[13]->value());
  opt_geometry_light_two_side(0, GMSH_SET, o->geo.butt[14]->value());

  opt_geometry_normals(0, GMSH_SET, o->geo.value[0]->value());
  opt_geometry_tangents(0, GMSH_SET, o->geo.value[1]->value());
  opt_geometry_tolerance(0, GMSH_SET, o->geo.value[2]->value());
  opt_geometry_point_size(0, GMSH_SET, o->geo.value[3]->value());
  opt_geometry_line_width(0, GMSH_SET, o->geo.value[4]->value());
  opt_geometry_point_sel_size(0, GMSH_SET, o->geo.value[5]->value());
  opt_geometry_line_sel_width(0, GMSH_SET, o->geo.value[6]->value());

  opt_geometry_point_type(0, GMSH_SET, o->geo.choice[0]->value());
  opt_geometry_line_type(0, GMSH_SET, o->geo.choice[1]->value());
  opt_geometry_surface_type(0, GMSH_SET, o->geo.choice[2]->value());

  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.post.draw = CTX.mesh.draw = 1;
}

// Mesh options

void mesh_options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup(3);
}

void mesh_options_ok_cb(CALLBACK_ARGS)
{
  activate_cb(NULL, data);

  optionWindow *o = GUI::instance()->options;

  opt_mesh_reverse_all_normals(0, GMSH_SET, o->mesh.butt[0]->value());
  opt_mesh_lc_from_curvature(0, GMSH_SET, o->mesh.butt[1]->value());
  opt_mesh_lc_from_points(0, GMSH_SET, o->mesh.butt[5]->value());
  opt_mesh_lc_extend_from_boundary(0, GMSH_SET, o->mesh.butt[16]->value());
  opt_mesh_optimize(0, GMSH_SET, o->mesh.butt[2]->value());
  opt_mesh_optimize_netgen(0, GMSH_SET, o->mesh.butt[24]->value());
  opt_mesh_order(0, GMSH_SET, o->mesh.value[3]->value());
  opt_mesh_smooth_internal_edges(0, GMSH_SET, o->mesh.butt[3]->value());
  opt_mesh_second_order_incomplete(0, GMSH_SET, o->mesh.butt[4]->value());
  opt_mesh_c1(0, GMSH_SET, o->mesh.butt[21]->value());
  opt_mesh_points(0, GMSH_SET, o->mesh.butt[6]->value());
  opt_mesh_lines(0, GMSH_SET, o->mesh.butt[7]->value());
  opt_mesh_triangles(0, GMSH_SET, o->mesh.menu->menu()[0].value() ? 1 : 0);
  opt_mesh_quadrangles(0, GMSH_SET, o->mesh.menu->menu()[1].value() ? 1 : 0);
  opt_mesh_tetrahedra(0, GMSH_SET, o->mesh.menu->menu()[2].value() ? 1 : 0);
  opt_mesh_hexahedra(0, GMSH_SET, o->mesh.menu->menu()[3].value() ? 1 : 0);
  opt_mesh_prisms(0, GMSH_SET, o->mesh.menu->menu()[4].value() ? 1 : 0);
  opt_mesh_pyramids(0, GMSH_SET, o->mesh.menu->menu()[5].value() ? 1 : 0);
  opt_mesh_surfaces_edges(0, GMSH_SET, o->mesh.butt[8]->value());
  opt_mesh_surfaces_faces(0, GMSH_SET, o->mesh.butt[9]->value());
  opt_mesh_volumes_edges(0, GMSH_SET, o->mesh.butt[10]->value());
  opt_mesh_volumes_faces(0, GMSH_SET, o->mesh.butt[11]->value());
  opt_mesh_points_num(0, GMSH_SET, o->mesh.butt[12]->value());
  opt_mesh_lines_num(0, GMSH_SET, o->mesh.butt[13]->value());
  opt_mesh_surfaces_num(0, GMSH_SET, o->mesh.butt[14]->value());
  opt_mesh_volumes_num(0, GMSH_SET, o->mesh.butt[15]->value());
  opt_mesh_light(0, GMSH_SET, o->mesh.butt[17]->value());
  opt_mesh_light_two_side(0, GMSH_SET, o->mesh.butt[18]->value());
  opt_mesh_smooth_normals(0, GMSH_SET, o->mesh.butt[19]->value());
  opt_mesh_light_lines(0, GMSH_SET, o->mesh.butt[20]->value());
  opt_mesh_nb_smoothing(0, GMSH_SET, o->mesh.value[0]->value());
  opt_mesh_lc_factor(0, GMSH_SET, o->mesh.value[2]->value());
  opt_mesh_lc_min(0, GMSH_SET, o->mesh.value[25]->value());
  opt_mesh_lc_max(0, GMSH_SET, o->mesh.value[26]->value());
  opt_mesh_quality_inf(0, GMSH_SET, o->mesh.value[4]->value());
  opt_mesh_quality_sup(0, GMSH_SET, o->mesh.value[5]->value());
  opt_mesh_radius_inf(0, GMSH_SET, o->mesh.value[6]->value());
  opt_mesh_radius_sup(0, GMSH_SET, o->mesh.value[7]->value());
  opt_mesh_normals(0, GMSH_SET, o->mesh.value[8]->value());
  opt_mesh_explode(0, GMSH_SET, o->mesh.value[9]->value());
  opt_mesh_tangents(0, GMSH_SET, o->mesh.value[13]->value());
  opt_mesh_point_size(0, GMSH_SET, o->mesh.value[10]->value());
  opt_mesh_line_width(0, GMSH_SET, o->mesh.value[11]->value());
  opt_mesh_label_frequency(0, GMSH_SET, o->mesh.value[12]->value());
  opt_mesh_angle_smooth_normals(0, GMSH_SET, o->mesh.value[18]->value());

  opt_mesh_point_type(0, GMSH_SET, o->mesh.choice[0]->value());
  opt_mesh_algo2d(0, GMSH_SET,
                  (o->mesh.choice[2]->value() == 0) ? ALGO_2D_FRONTAL : 
                  (o->mesh.choice[2]->value() == 1) ? ALGO_2D_DELAUNAY :
                  ALGO_2D_MESHADAPT_DELAUNAY);
  opt_mesh_algo3d(0, GMSH_SET,
                  (o->mesh.choice[3]->value() == 0) ? ALGO_3D_TETGEN_DELAUNAY : 
                  ALGO_3D_NETGEN);
  opt_mesh_recombine_algo(0, GMSH_SET,
                  (o->mesh.choice[5]->value() == 0) ? 1 : 2);
  opt_mesh_color_carousel(0, GMSH_SET, o->mesh.choice[4]->value());
  opt_mesh_quality_type(0, GMSH_SET, o->mesh.choice[6]->value());
  opt_mesh_label_type(0, GMSH_SET, o->mesh.choice[7]->value());

  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.post.draw = CTX.mesh.draw = 1;
}

// Solver options

void solver_options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup(4);
}

void solver_options_ok_cb(CALLBACK_ARGS)
{
  activate_cb(NULL, data);

  optionWindow *o = GUI::instance()->options;

  int old_listen = (int)opt_solver_listen(0, GMSH_GET, o->solver.butt[0]->value());
  opt_solver_listen(0, GMSH_SET, o->solver.butt[0]->value());
  if(!old_listen && o->solver.butt[0]->value())
    Solver(-1, NULL);

  opt_solver_max_delay(0, GMSH_SET, o->solver.value[0]->value());

  opt_solver_socket_name(0, GMSH_SET, o->solver.input[0]->value());

  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.post.draw = CTX.mesh.draw = 1;
}

// Post options

void post_options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup(5);
}

void post_options_ok_cb(CALLBACK_ARGS)
{
  activate_cb(NULL, data);

  optionWindow *o = GUI::instance()->options;

  opt_post_anim_cycle(0, GMSH_SET, o->post.butt[0]->value());
  opt_post_combine_remove_orig(0, GMSH_SET, o->post.butt[1]->value());
  opt_post_horizontal_scales(0, GMSH_SET, o->post.butt[2]->value());

  opt_post_anim_delay(0, GMSH_SET, o->post.value[0]->value());

  opt_post_link(0, GMSH_SET, o->post.choice[0]->value());

  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.post.draw = CTX.mesh.draw = 1;
}

// View options

void view_options_cb(CALLBACK_ARGS)
{
  GUI::instance()->options->showGroup((int)(long)data + 6);
}

void view_options_timestep_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == GUI::instance()->options->view.index)) {
      opt_view_timestep(i, GMSH_SET, ((Fl_Value_Input *) w)->value());
    }
  }
  Draw();
}

void view_options_timestep_decr_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == GUI::instance()->options->view.index)) {
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) - 1);
    }
  }
  Draw();
}

void view_options_timestep_incr_cb(CALLBACK_ARGS)
{
  int links = (int)opt_post_link(0, GMSH_GET, 0);
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == GUI::instance()->options->view.index)) {
      opt_view_timestep(i, GMSH_SET | GMSH_GUI,
                        opt_view_timestep(i, GMSH_GET, 0) + 1);
    }
  }
  Draw();
}

void view_arrow_param_cb(CALLBACK_ARGS)
{
  double a = opt_view_arrow_head_radius(GUI::instance()->options->view.index, GMSH_GET, 0);
  double b = opt_view_arrow_stem_length(GUI::instance()->options->view.index, GMSH_GET, 0);
  double c = opt_view_arrow_stem_radius(GUI::instance()->options->view.index, GMSH_GET, 0);
  while(arrow_editor("Arrow Editor", a, b, c)){
    opt_view_arrow_head_radius(GUI::instance()->options->view.index, GMSH_SET, a);
    opt_view_arrow_stem_length(GUI::instance()->options->view.index, GMSH_SET, b);
    opt_view_arrow_stem_radius(GUI::instance()->options->view.index, GMSH_SET, c);
    Draw();
  }
}

void view_options_ok_cb(CALLBACK_ARGS)
{
  int current = GUI::instance()->options->view.index;

  if(current < 0)
    return;

  activate_cb(NULL, data);

  optionWindow *o = GUI::instance()->options;

  if(data){
    const char *str = (const char*)data;
    if(!strcmp(str, "range_min")){
      o->view.value[31]->value(opt_view_min(o->view.index, GMSH_GET, 0));
    }
    else if(!strcmp(str, "range_max")){
      o->view.value[32]->value(opt_view_max(o->view.index, GMSH_GET, 0));
    }
  }
  
  int force = 0, links = (int)opt_post_link(0, GMSH_GET, 0);

  // get the old values for the current view

  double scale_type = opt_view_scale_type(current, GMSH_GET, 0);
  double intervals_type = opt_view_intervals_type(current, GMSH_GET, 0);
  double point_type = opt_view_point_type(current, GMSH_GET, 0);
  double line_type = opt_view_line_type(current, GMSH_GET, 0);
  double vector_type = opt_view_vector_type(current, GMSH_GET, 0);
  double glyph_location = opt_view_glyph_location(current, GMSH_GET, 0);
  double tensor_type = opt_view_tensor_type(current, GMSH_GET, 0);
  double range_type = opt_view_range_type(current, GMSH_GET, 0);
  double axes = opt_view_axes(current, GMSH_GET, 0);
  double mikado = opt_view_axes_mikado(current, GMSH_GET, 0);
  double boundary = opt_view_boundary(current, GMSH_GET, 0);
  double external_view = opt_view_external_view(current, GMSH_GET, 0);
  double gen_raise_view = opt_view_gen_raise_view(current, GMSH_GET, 0);
  double show_time = opt_view_show_time(current, GMSH_GET, 0);

  double type = opt_view_type(current, GMSH_GET, 0);
  double saturate_values = opt_view_saturate_values(current, GMSH_GET, 0);
  double max_recursion_level = opt_view_max_recursion_level(current, GMSH_GET, 0);
  double target_error = opt_view_target_error(current, GMSH_GET, 0);
  double show_element = opt_view_show_element(current, GMSH_GET, 0);
  double draw_skin_only = opt_view_draw_skin_only(current, GMSH_GET, 0);
  double show_scale = opt_view_show_scale(current, GMSH_GET, 0);
  double auto_position = opt_view_auto_position(current, GMSH_GET, 0);
  double axes_auto_position = opt_view_axes_auto_position(current, GMSH_GET, 0);
  double draw_strings = opt_view_draw_strings(current, GMSH_GET, 0);
  double light = opt_view_light(current, GMSH_GET, 0);
  double light_two_side = opt_view_light_two_side(current, GMSH_GET, 0);
  double light_lines = opt_view_light_lines(current, GMSH_GET, 0);
  double smooth_normals = opt_view_smooth_normals(current, GMSH_GET, 0);
  double draw_points = opt_view_draw_points(current, GMSH_GET, 0);
  double draw_lines = opt_view_draw_lines(current, GMSH_GET, 0);
  double draw_triangles = opt_view_draw_triangles(current, GMSH_GET, 0);
  double draw_quadrangles = opt_view_draw_quadrangles(current, GMSH_GET, 0);
  double draw_tetrahedra = opt_view_draw_tetrahedra(current, GMSH_GET, 0);
  double draw_hexahedra = opt_view_draw_hexahedra(current, GMSH_GET, 0);
  double draw_prisms = opt_view_draw_prisms(current, GMSH_GET, 0);
  double draw_pyramids = opt_view_draw_pyramids(current, GMSH_GET, 0);
  double draw_scalars = opt_view_draw_scalars(current, GMSH_GET, 0);
  double draw_vectors = opt_view_draw_vectors(current, GMSH_GET, 0);
  double draw_tensors = opt_view_draw_tensors(current, GMSH_GET, 0);
  double use_gen_raise = opt_view_use_gen_raise(current, GMSH_GET, 0);
  double fake_transparency = opt_view_fake_transparency(current, GMSH_GET, 0);
  double use_stipple = opt_view_use_stipple(current, GMSH_GET, 0);
  double center_glyphs = opt_view_center_glyphs(current, GMSH_GET, 0);

  double normals = opt_view_normals(current, GMSH_GET, 0);
  double tangents = opt_view_tangents(current, GMSH_GET, 0);
  double custom_min = opt_view_custom_min(current, GMSH_GET, 0);
  double custom_max = opt_view_custom_max(current, GMSH_GET, 0);
  double nb_iso = opt_view_nb_iso(current, GMSH_GET, 0);
  double offset0 = opt_view_offset0(current, GMSH_GET, 0);
  double offset1 = opt_view_offset1(current, GMSH_GET, 0);
  double offset2 = opt_view_offset2(current, GMSH_GET, 0);
  double transform00 = opt_view_transform00(current, GMSH_GET, 0);
  double transform01 = opt_view_transform01(current, GMSH_GET, 0);
  double transform02 = opt_view_transform02(current, GMSH_GET, 0);
  double transform10 = opt_view_transform10(current, GMSH_GET, 0);
  double transform11 = opt_view_transform11(current, GMSH_GET, 0);
  double transform12 = opt_view_transform12(current, GMSH_GET, 0);
  double transform20 = opt_view_transform20(current, GMSH_GET, 0);
  double transform21 = opt_view_transform21(current, GMSH_GET, 0);
  double transform22 = opt_view_transform22(current, GMSH_GET, 0);
  double raise0 = opt_view_raise0(current, GMSH_GET, 0);
  double raise1 = opt_view_raise1(current, GMSH_GET, 0);
  double raise2 = opt_view_raise2(current, GMSH_GET, 0);
  double normal_raise = opt_view_normal_raise(current, GMSH_GET, 0);
  double timestep = opt_view_timestep(current, GMSH_GET, 0);
  double arrow_size = opt_view_arrow_size(current, GMSH_GET, 0);
  double arrow_size_proportional = opt_view_arrow_size_proportional(current, GMSH_GET, 0);
  double displacement_factor = opt_view_displacement_factor(current, GMSH_GET, 0);
  double point_size = opt_view_point_size(current, GMSH_GET, 0);
  double line_width = opt_view_line_width(current, GMSH_GET, 0);
  double explode = opt_view_explode(current, GMSH_GET, 0);
  double angle_smooth_normals = opt_view_angle_smooth_normals(current, GMSH_GET, 0);
  double position0 = opt_view_position0(current, GMSH_GET, 0);
  double position1 = opt_view_position1(current, GMSH_GET, 0);
  double size0 = opt_view_size0(current, GMSH_GET, 0);
  double size1 = opt_view_size1(current, GMSH_GET, 0);
  double axes_tics0 = opt_view_axes_tics0(current, GMSH_GET, 0);
  double axes_tics1 = opt_view_axes_tics1(current, GMSH_GET, 0);
  double axes_tics2 = opt_view_axes_tics2(current, GMSH_GET, 0);
  double axes_xmin = opt_view_axes_xmin(current, GMSH_GET, 0);
  double axes_ymin = opt_view_axes_ymin(current, GMSH_GET, 0);
  double axes_zmin = opt_view_axes_zmin(current, GMSH_GET, 0);
  double axes_xmax = opt_view_axes_xmax(current, GMSH_GET, 0);
  double axes_ymax = opt_view_axes_ymax(current, GMSH_GET, 0);
  double axes_zmax = opt_view_axes_zmax(current, GMSH_GET, 0);
  double gen_raise_factor = opt_view_gen_raise_factor(current, GMSH_GET, 0);

  char name[256]; strcpy(name, opt_view_name(current, GMSH_GET, NULL));
  char format[256]; strcpy(format, opt_view_format(current, GMSH_GET, NULL));
  char axes_label0[256]; strcpy(axes_label0, opt_view_axes_label0(current, GMSH_GET, NULL));
  char axes_label1[256]; strcpy(axes_label1, opt_view_axes_label1(current, GMSH_GET, NULL));
  char axes_label2[256]; strcpy(axes_label2, opt_view_axes_label2(current, GMSH_GET, NULL));
  char axes_format0[256]; strcpy(axes_format0, opt_view_axes_format0(current, GMSH_GET, NULL));
  char axes_format1[256]; strcpy(axes_format1, opt_view_axes_format1(current, GMSH_GET, NULL));
  char axes_format2[256]; strcpy(axes_format2, opt_view_axes_format2(current, GMSH_GET, NULL));
  char gen_raise0[256]; strcpy(gen_raise0, opt_view_gen_raise0(current, GMSH_GET, NULL));
  char gen_raise1[256]; strcpy(gen_raise1, opt_view_gen_raise1(current, GMSH_GET, NULL));
  char gen_raise2[256]; strcpy(gen_raise2, opt_view_gen_raise2(current, GMSH_GET, NULL));

  // modify only the views that need to be updated
  for(int i = 0; i < (int)PView::list.size(); i++) {
    if((links == 2 || links == 4) ||
       ((links == 1 || links == 3) && opt_view_visible(i, GMSH_GET, 0)) ||
       (links == 0 && i == current)) {

      if(links == 3 || links == 4)
        force = 1;

      double val;

      // view_choice

      val = o->view.choice[1]->value() + 1;
      if(force || (val != scale_type))
        opt_view_scale_type(i, GMSH_SET, val);

      val = o->view.choice[0]->value() + 1;
      if(force || (val != intervals_type))
        opt_view_intervals_type(i, GMSH_SET, val);
      
      val = o->view.choice[5]->value();
      if(force || (val != point_type))
        opt_view_point_type(i, GMSH_SET, val);
      
      val = o->view.choice[6]->value();
      if(force || (val != line_type))
        opt_view_line_type(i, GMSH_SET, val);

      val = o->view.choice[2]->value() + 1;
      if(force || (val != vector_type))
        opt_view_vector_type(i, GMSH_SET, val);

      val = o->view.choice[3]->value() + 1;
      if(force || (val != glyph_location))
        opt_view_glyph_location(i, GMSH_SET, val);

      val = o->view.choice[4]->value() + 1;
      if(force || (val != tensor_type))
        opt_view_tensor_type(i, GMSH_SET, val);
      
      val = o->view.choice[7]->value() + 1;
      if(force || (val != range_type))
        opt_view_range_type(i, GMSH_SET, val);

      val = o->view.choice[8]->value();
      if(force || (val != axes))
        opt_view_axes(i, GMSH_SET, val);

      val = o->view.choice[9]->value();
      if(force || (val != boundary))
        opt_view_boundary(i, GMSH_SET, val);

      val = o->view.choice[10]->value() - 1;
      if(force || (val != external_view))
        opt_view_external_view(i, GMSH_SET, val);

      val = o->view.choice[11]->value() - 1;
      if(force || (val != gen_raise_view))
        opt_view_gen_raise_view(i, GMSH_SET, val);

      val = o->view.choice[12]->value();
      if(force || (val != show_time))
        opt_view_show_time(i, GMSH_SET, val);
      
      val = o->view.choice[13]->value() + 1;
      if(force || (val != type))
        opt_view_type(i, GMSH_SET, val);

      // view_butts

      val = o->view.butt[0]->value();
      if(force || (val != arrow_size_proportional))
        opt_view_arrow_size_proportional(i, GMSH_SET, val);

      val = o->view.butt[38]->value();
      if(force || (val != saturate_values))
        opt_view_saturate_values(i, GMSH_SET, val);

      val = o->view.butt[10]->value();
      if(force || (val != show_element))
        opt_view_show_element(i, GMSH_SET, val);

      val = o->view.butt[2]->value();
      if(force || (val != draw_skin_only))
        opt_view_draw_skin_only(i, GMSH_SET, val);

      val = o->view.butt[4]->value();
      if(force || (val != show_scale))
        opt_view_show_scale(i, GMSH_SET, val);

      val = o->view.butt[3]->value();
      if(force || (val != mikado))
        opt_view_axes_mikado(i, GMSH_SET, val);

      val = o->view.butt[7]->value();
      if(force || (val != auto_position))
        opt_view_auto_position(i, GMSH_SET, val);

      val = o->view.butt[25]->value();
      if(force || (val != axes_auto_position))
        opt_view_axes_auto_position(i, GMSH_SET, val);

      val = o->view.butt[5]->value();
      if(force || (val != draw_strings))
        opt_view_draw_strings(i, GMSH_SET, val);

      val = o->view.butt[11]->value();
      if(force || (val != light))
        opt_view_light(i, GMSH_SET, val);

      val = o->view.butt[8]->value();
      if(force || (val != light_lines))
        opt_view_light_lines(i, GMSH_SET, val);

      val = o->view.butt[9]->value();
      if(force || (val != light_two_side))
        opt_view_light_two_side(i, GMSH_SET, val);

      val = o->view.butt[12]->value();
      if(force || (val != smooth_normals))
        opt_view_smooth_normals(i, GMSH_SET, val);

      val = o->view.menu[0]->menu()[0].value() ? 1 : 0;
      if(force || (val != draw_scalars))
        opt_view_draw_scalars(i, GMSH_SET, val);

      val = o->view.menu[0]->menu()[1].value() ? 1 : 0;
      if(force || (val != draw_vectors))
        opt_view_draw_vectors(i, GMSH_SET, val);

      val = o->view.menu[0]->menu()[2].value() ? 1 : 0;
      if(force || (val != draw_tensors))
        opt_view_draw_tensors(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[0].value() ? 1 : 0;
      if(force || (val != draw_points))
        opt_view_draw_points(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[1].value() ? 1 : 0;
      if(force || (val != draw_lines))
        opt_view_draw_lines(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[2].value() ? 1 : 0;
      if(force || (val != draw_triangles))
        opt_view_draw_triangles(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[3].value() ? 1 : 0;
      if(force || (val != draw_quadrangles))
        opt_view_draw_quadrangles(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[4].value() ? 1 : 0;
      if(force || (val != draw_tetrahedra))
        opt_view_draw_tetrahedra(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[5].value() ? 1 : 0;
      if(force || (val != draw_hexahedra))
        opt_view_draw_hexahedra(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[6].value() ? 1 : 0;
      if(force || (val != draw_prisms))
        opt_view_draw_prisms(i, GMSH_SET, val);

      val = o->view.menu[1]->menu()[7].value() ? 1 : 0;
      if(force || (val != draw_pyramids))
        opt_view_draw_pyramids(i, GMSH_SET, val);

      val = o->view.butt[6]->value();
      if(force || (val != use_gen_raise))
        opt_view_use_gen_raise(i, GMSH_SET, val);

      val = o->view.butt[24]->value();
      if(force || (val != fake_transparency))
        opt_view_fake_transparency(i, GMSH_SET, val);

      val = o->view.butt[26]->value();
      if(force || (val != use_stipple))
        opt_view_use_stipple(i, GMSH_SET, val);

      val = o->view.butt[1]->value();
      if(force || (val != center_glyphs))
        opt_view_center_glyphs(i, GMSH_SET, val);

      // view_values
      
      val = o->view.value[0]->value();
      if(force || (val != normals))
        opt_view_normals(i, GMSH_SET, val);

      val = o->view.value[1]->value();
      if(force || (val != tangents))
        opt_view_tangents(i, GMSH_SET, val);

      val = o->view.value[31]->value();
      if(force || (val != custom_min))
        opt_view_custom_min(i, GMSH_SET, val);

      val = o->view.value[32]->value();
      if(force || (val != custom_max))
        opt_view_custom_max(i, GMSH_SET, val);

      val = o->view.value[33]->value();
      if(force || (val != max_recursion_level))
        opt_view_max_recursion_level(i, GMSH_SET, val);

      val = o->view.value[34]->value();
      if(force || (val != target_error))
        opt_view_target_error(i, GMSH_SET, val);

      val = o->view.value[30]->value();
      if(force || (val != nb_iso))
        opt_view_nb_iso(i, GMSH_SET, val);

      val = o->view.value[40]->value();
      if(force || (val != offset0))
        opt_view_offset0(i, GMSH_SET, val);

      val = o->view.value[41]->value();
      if(force || (val != offset1))
        opt_view_offset1(i, GMSH_SET, val);

      val = o->view.value[42]->value();
      if(force || (val != offset2))
        opt_view_offset2(i, GMSH_SET, val);

      val = o->view.value[51]->value();
      if(force || (val != transform00))
        opt_view_transform00(i, GMSH_SET, val);

      val = o->view.value[52]->value();
      if(force || (val != transform01))
        opt_view_transform01(i, GMSH_SET, val);

      val = o->view.value[53]->value();
      if(force || (val != transform02))
        opt_view_transform02(i, GMSH_SET, val);

      val = o->view.value[54]->value();
      if(force || (val != transform10))
        opt_view_transform10(i, GMSH_SET, val);

      val = o->view.value[55]->value();
      if(force || (val != transform11))
        opt_view_transform11(i, GMSH_SET, val);

      val = o->view.value[56]->value();
      if(force || (val != transform12))
        opt_view_transform12(i, GMSH_SET, val);

      val = o->view.value[57]->value();
      if(force || (val != transform20))
        opt_view_transform20(i, GMSH_SET, val);

      val = o->view.value[58]->value();
      if(force || (val != transform21))
        opt_view_transform21(i, GMSH_SET, val);

      val = o->view.value[59]->value();
      if(force || (val != transform22))
        opt_view_transform22(i, GMSH_SET, val);

      val = o->view.value[43]->value();
      if(force || (val != raise0))
        opt_view_raise0(i, GMSH_SET, val);

      val = o->view.value[44]->value();
      if(force || (val != raise1))
        opt_view_raise1(i, GMSH_SET, val);

      val = o->view.value[45]->value();
      if(force || (val != raise2))
        opt_view_raise2(i, GMSH_SET, val);

      val = o->view.value[46]->value();
      if(force || (val != normal_raise))
        opt_view_normal_raise(i, GMSH_SET, val);

      val = o->view.value[50]->value();
      if(force || (val != timestep))
        opt_view_timestep(i, GMSH_SET, val);

      val = o->view.value[60]->value();
      if(force || (val != arrow_size))
        opt_view_arrow_size(i, GMSH_SET, val);

      val = o->view.value[63]->value();
      if(force || (val != displacement_factor))
        opt_view_displacement_factor(i, GMSH_SET, val);

      val = o->view.value[61]->value();
      if(force || (val != point_size))
        opt_view_point_size(i, GMSH_SET, val);

      val = o->view.value[62]->value();
      if(force || (val != line_width))
        opt_view_line_width(i, GMSH_SET, val);

      val = o->view.value[12]->value();
      if(force || (val != explode))
        opt_view_explode(i, GMSH_SET, val);

      val = o->view.value[10]->value();
      if(force || (val != angle_smooth_normals))
        opt_view_angle_smooth_normals(i, GMSH_SET, val);

      val = o->view.value[20]->value();
      if(force || (val != position0))
        opt_view_position0(i, GMSH_SET, val);

      val = o->view.value[21]->value();
      if(force || (val != position1))
        opt_view_position1(i, GMSH_SET, val);

      val = o->view.value[22]->value();
      if(force || (val != size0))
        opt_view_size0(i, GMSH_SET, val);
      
      val = o->view.value[23]->value();
      if(force || (val != size1))
        opt_view_size1(i, GMSH_SET, val);

      val = o->view.value[13]->value();
      if(force || (val != axes_xmin))
        opt_view_axes_xmin(i, GMSH_SET, val);

      val = o->view.value[14]->value();
      if(force || (val != axes_ymin))
        opt_view_axes_ymin(i, GMSH_SET, val);

      val = o->view.value[15]->value();
      if(force || (val != axes_zmin))
        opt_view_axes_zmin(i, GMSH_SET, val);

      val = o->view.value[16]->value();
      if(force || (val != axes_xmax))
        opt_view_axes_xmax(i, GMSH_SET, val);

      val = o->view.value[17]->value();
      if(force || (val != axes_ymax))
        opt_view_axes_ymax(i, GMSH_SET, val);

      val = o->view.value[18]->value();
      if(force || (val != axes_zmax))
        opt_view_axes_zmax(i, GMSH_SET, val);

      val = o->view.value[2]->value();
      if(force || (val != gen_raise_factor))
        opt_view_gen_raise_factor(i, GMSH_SET, val);

      val = o->view.value[3]->value();
      if(force || (val != axes_tics0))
        opt_view_axes_tics0(i, GMSH_SET, val);

      val = o->view.value[4]->value();
      if(force || (val != axes_tics1))
        opt_view_axes_tics1(i, GMSH_SET, val);

      val = o->view.value[5]->value();
      if(force || (val != axes_tics2))
        opt_view_axes_tics2(i, GMSH_SET, val);

      // view_inputs

      const char *str;

      str = o->view.input[0]->value();
      if(force || strcmp(str, name))
        opt_view_name(i, GMSH_SET, str);

      str = o->view.input[1]->value();
      if(force || strcmp(str, format))
        opt_view_format(i, GMSH_SET, str);

      str = o->view.input[10]->value();
      if(force || strcmp(str, axes_label0))
        opt_view_axes_label0(i, GMSH_SET, str);

      str = o->view.input[11]->value();
      if(force || strcmp(str, axes_label1))
        opt_view_axes_label1(i, GMSH_SET, str);

      str = o->view.input[12]->value();
      if(force || strcmp(str, axes_label2))
        opt_view_axes_label2(i, GMSH_SET, str);

      str = o->view.input[7]->value();
      if(force || strcmp(str, axes_format0))
        opt_view_axes_format0(i, GMSH_SET, str);

      str = o->view.input[8]->value();
      if(force || strcmp(str, axes_format1))
        opt_view_axes_format1(i, GMSH_SET, str);

      str = o->view.input[9]->value();
      if(force || strcmp(str, axes_format2))
        opt_view_axes_format2(i, GMSH_SET, str);

      str = o->view.input[4]->value();
      if(force || strcmp(str, gen_raise0))
        opt_view_gen_raise0(i, GMSH_SET, str);

      str = o->view.input[5]->value();
      if(force || strcmp(str, gen_raise1))
        opt_view_gen_raise1(i, GMSH_SET, str);

      str = o->view.input[6]->value();
      if(force || strcmp(str, gen_raise2))
        opt_view_gen_raise2(i, GMSH_SET, str);

      // colors (since the color buttons modify the values directly
      // through callbacks, we can use the opt_XXX routines directly)
      if(force || (i != current)){
        opt_view_color_points(i, GMSH_SET, opt_view_color_points(current, GMSH_GET, 0));
        opt_view_color_lines(i, GMSH_SET, opt_view_color_lines(current, GMSH_GET, 0));
        opt_view_color_triangles(i, GMSH_SET, opt_view_color_triangles(current, GMSH_GET, 0));
        opt_view_color_quadrangles(i, GMSH_SET, opt_view_color_quadrangles(current, GMSH_GET, 0));
        opt_view_color_tetrahedra(i, GMSH_SET, opt_view_color_tetrahedra(current, GMSH_GET, 0));
        opt_view_color_hexahedra(i, GMSH_SET, opt_view_color_hexahedra(current, GMSH_GET, 0));
        opt_view_color_prisms(i, GMSH_SET, opt_view_color_prisms(current, GMSH_GET, 0));
        opt_view_color_pyramids(i, GMSH_SET, opt_view_color_pyramids(current, GMSH_GET, 0));
        opt_view_color_tangents(i, GMSH_SET, opt_view_color_tangents(current, GMSH_GET, 0));
        opt_view_color_normals(i, GMSH_SET, opt_view_color_normals(current, GMSH_GET, 0));
        opt_view_color_text2d(i, GMSH_SET, opt_view_color_text2d(current, GMSH_GET, 0));
        opt_view_color_text3d(i, GMSH_SET, opt_view_color_text3d(current, GMSH_GET, 0));
        opt_view_color_axes(i, GMSH_SET, opt_view_color_axes(current, GMSH_GET, 0));
      }

      // colorbar window

      if(force || (i != current)) {
        ColorTable_Copy(&PView::list[current]->getOptions()->CT);
        ColorTable_Paste(&PView::list[i]->getOptions()->CT);
        PView::list[i]->setChanged(true);
      }
    }
  }

  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.post.draw = CTX.mesh.draw = 1;
}

// Statistics Menu

void statistics_cb(CALLBACK_ARGS)
{
  GUI::instance()->stats->show();
}

void statistics_update_cb(CALLBACK_ARGS)
{
  GUI::instance()->stats->compute(true);
}

void statistics_histogram_cb(CALLBACK_ARGS)
{
  std::string name((const char*)data);

  std::vector<double> x, y;

  if(name == "Gamma2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[0][i]);
    new PView("Gamma", "# Elements", x, y);
  }
  else if(name == "Eta2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[1][i]);
    new PView("Eta", "# Elements", x, y);
  }
  else if(name == "Rho2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[2][i]);
    new PView("Rho", "# Elements", x, y);
  }
  else if(name == "Disto2D"){
    for(int i = 0; i < 100; i++) y.push_back(GUI::instance()->stats->quality[3][i]);
    new PView("Disto", "# Elements", x, y);
  }
  else{
    std::vector<GEntity*> entities;
    GModel::current()->getEntities(entities);
    std::map<int, std::vector<double> > d;
    for(unsigned int i = 0; i < entities.size(); i++){
      if(entities[i]->dim() < 2) continue;
      for(unsigned int j = 0; j < entities[i]->getNumMeshElements(); j++){
        MElement *e = entities[i]->getMeshElement(j);
        if(name == "Gamma3D")
          d[e->getNum()].push_back(e->gammaShapeMeasure());
        else if(name == "Eta3D")
          d[e->getNum()].push_back(e->etaShapeMeasure());
        else if(name == "Rho3D")
          d[e->getNum()].push_back(e->rhoShapeMeasure());
        else
          d[e->getNum()].push_back(e->distoShapeMeasure());
      }
    }
    name.resize(name.size() - 2);
    new PView(name, "ElementData", GModel::current(), d);
  }

  GUI::instance()->updateViews();
  Draw();
}

// Messages Menu

void message_cb(CALLBACK_ARGS)
{
  GUI::instance()->messages->show();
}

void message_auto_scroll_cb(CALLBACK_ARGS)
{
  CTX.msg_auto_scroll = GUI::instance()->messages->butt->value();
}

void message_copy_cb(CALLBACK_ARGS)
{
#define BUFFL 50000
  static char buff[BUFFL];
  strcpy(buff, "");
  for(int i = 1; i <= GUI::instance()->messages->browser->size(); i++) {
    if(GUI::instance()->messages->browser->selected(i)) {
      const char *c = GUI::instance()->messages->browser->text(i);
      if(strlen(buff) + strlen(c) > BUFFL - 2) {
        Msg::Error("Text selection too large to copy");
        break;
      }
      if(c[0] == '@')
        strcat(buff, &c[5]);
      else
        strcat(buff, c);
      strcat(buff, "\n");
    }
  }
  // bof bof bof
  Fl::copy(buff, strlen(buff), 0);
  Fl::copy(buff, strlen(buff), 1);
}

void message_clear_cb(CALLBACK_ARGS)
{
  GUI::instance()->messages->browser->clear();
}

void message_save_cb(CALLBACK_ARGS)
{
 test:
  if(file_chooser(0, 1, "Save", "*")) {
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?", 
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    GUI::instance()->messages->save(name.c_str());
  }
}

// Visibility Menu

void visibility_cb(CALLBACK_ARGS)
{
  // get the visibility info from the model, and update the browser accordingly

  const char *str = (const char*)data;
  if(str && !strcmp(str, "redraw_only"))
    GUI::instance()->visibility->show(true);
  else
    GUI::instance()->visibility->show(false);

  GUI::instance()->visibility->browser->clear();

  int type = GUI::instance()->visibility->type->value();

  VisibilityManager::instance()->update(type);
  for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
    GUI::instance()->visibility->browser->add(VisibilityManager::instance()->getBrowserLine(i).c_str());
    if(VisibilityManager::instance()->getVisibility(i))
      GUI::instance()->visibility->browser->select(i + 1);
  }

  // activate the delete button for physicals only!
  if(type == 1)
    GUI::instance()->visibility->push[0]->activate();
  else
    GUI::instance()->visibility->push[0]->deactivate();

  // disable numeric and interactive selection for partitions
  if(type == 2){
    GUI::instance()->visibility->group[1]->deactivate();
    GUI::instance()->visibility->group[2]->deactivate();
  }
  else{
    GUI::instance()->visibility->group[1]->activate();
    GUI::instance()->visibility->group[2]->activate();
  }
}

void visibility_ok_cb(CALLBACK_ARGS)
{
  // if the browser is not empty, get the selections made in the
  // browser and apply them into the model
  if(VisibilityManager::instance()->getNumEntities()){
    CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    bool recursive = GUI::instance()->visibility->butt[0]->value() ? true : false;
    int type = GUI::instance()->visibility->type->value();
    VisibilityManager::instance()->setAllInvisible(type);
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++)
      if(GUI::instance()->visibility->browser->selected(i + 1))
        VisibilityManager::instance()->setVisibility(i, 1, recursive);
    // then refresh the browser to account for recursive selections
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++)
      if(VisibilityManager::instance()->getVisibility(i))
        GUI::instance()->visibility->browser->select(i + 1);
    Draw();
  }
}

void visibility_save_cb(CALLBACK_ARGS)
{
  std::string str = VisibilityManager::instance()->getStringForGEO();
  add_infile(str.c_str(), CTX.filename);
}

void visibility_delete_cb(CALLBACK_ARGS)
{
  int type = GUI::instance()->visibility->type->value();
  if(type != 1) return; // delete only available for physicals

  bool all = true;
  for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
    if(!GUI::instance()->visibility->browser->selected(i + 1)){
      all = false;
      break;
    }
  }
  if(all){
    GModel::current()->deletePhysicalGroups();
  }
  else{
    for(int i = 0; i < VisibilityManager::instance()->getNumEntities(); i++){
      if(GUI::instance()->visibility->browser->selected(i + 1)){
        Vis *v = VisibilityManager::instance()->getEntity(i);
        GModel::current()->deletePhysicalGroup(v->getDim(), v->getTag());
      }
    }
  }

  visibility_cb(NULL, (void*)"redraw_only");
}

void visibility_sort_cb(CALLBACK_ARGS)
{
  const char *str = (const char*)data;
  int val;
  if(!strcmp(str, "type"))
    val = 1;
  else if(!strcmp(str, "number"))
    val = 2;
  else if(!strcmp(str, "name"))
    val = 3;
  else if(!strcmp(str, "-"))
    val = -1;
  else if(!strcmp(str, "+"))
    val = -2;
  else
    val = 0;

  if(val == 0) { // select or deselect everything
    int selectall = 0;
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
      if(!GUI::instance()->visibility->browser->selected(i + 1)) {
        selectall = 1;
        break;
      }
    if(selectall)
      for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
        GUI::instance()->visibility->browser->select(i + 1);
    else
      GUI::instance()->visibility->browser->deselect();
  }
  else if(val == -1){ // invert the selection
    int *state = new int[GUI::instance()->visibility->browser->size()];
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
      state[i] = GUI::instance()->visibility->browser->selected(i + 1);
    GUI::instance()->visibility->browser->deselect();
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++)
      if(!state[i]) GUI::instance()->visibility->browser->select(i + 1);
    delete [] state;
  }
  else if(val == -2){ // create new parameter name for selection
    for(int i = 0; i < GUI::instance()->visibility->browser->size(); i++){
      if(GUI::instance()->visibility->browser->selected(i + 1)){
        static char tmpstr[256];
        sprintf(tmpstr, "%d", VisibilityManager::instance()->getTag(i));
        GUI::instance()->geoContext->input[1]->value(tmpstr);
        break;
      }
    }
    GUI::instance()->geoContext->input[0]->value("NewName");
    GUI::instance()->geoContext->show(0);
  }
  else { // set new sorting mode
    VisibilityManager::instance()->setSortMode(val);
    visibility_cb(NULL, (void*)"redraw_only");
  }
}

void visibility_number_cb(CALLBACK_ARGS)
{
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);

  // type = 0 for elementary, 1 for physical and 2 for partitions
  int type = GUI::instance()->visibility->type->value();
  if(type != 0 && type != 1) return;

  // what = 0 for nodes, 1 for elements, 2 for points, 3 for lines, 4
  // for surfaces, 5 for volumes, 6 for physical points, 7 for
  // physical lines, 8 for physical surfaces and 9 for physical
  // volumes
  int what = (int)(long)data;
  char val;
  if(what >= 100){ // show
    val = 1;
    what -= 100;
  }
  else{ // hide
    val = 0;
  }
  const char *str = GUI::instance()->visibility->input[what]->value();
  if(type == 1 && what >= 2 && what <= 5) what += 4;

  int num = (!strcmp(str, "all") || !strcmp(str, "*")) ? -1 : atoi(str);
  bool recursive = GUI::instance()->visibility->butt[0]->value() ? true : false;
  
  VisibilityManager::instance()->setVisibilityByNumber(what, num, val, recursive);

  int pos = GUI::instance()->visibility->browser->position();
  visibility_cb(NULL, (void*)"redraw_only");
  GUI::instance()->visibility->browser->position(pos);
  Draw();
}

static void _apply_visibility(char mode,
                              std::vector<GVertex*> &vertices,
                              std::vector<GEdge*> &edges,
                              std::vector<GFace*> &faces,
                              std::vector<GRegion*> &regions,
                              std::vector<MElement*> &elements)
{
  // type = 0 for elementary, 1 for physical and 2 for partitions
  int type = GUI::instance()->visibility->type->value();
  if(type != 0 && type != 1) return;
  bool recursive = GUI::instance()->visibility->butt[0]->value() ? true : false;

  if(mode == 1){ // when showing a single entity, first hide everything
    if(CTX.pick_elements)
      VisibilityManager::instance()->setVisibilityByNumber(1, -1, 0, false);
    else
      for(int i = 2; i <= 5; i++)
        VisibilityManager::instance()->setVisibilityByNumber(i, -1, 0, false);
  }

  if(mode == 2) mode = 1;
  
  if(CTX.pick_elements){
    for(unsigned int i = 0; i < elements.size(); i++)
      elements[i]->setVisibility(mode);
  }
  else{
    for(unsigned int i = 0; i < vertices.size(); i++){
      if(type == 0)
        vertices[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < vertices[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (6, vertices[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < edges.size(); i++){
      if(type == 0)
        edges[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < edges[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (7, edges[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < faces.size(); i++){
      if(type == 0)
        faces[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < faces[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (8, faces[i]->physicals[j], mode, recursive);
    }
    for(unsigned int i = 0; i < regions.size(); i++){
      if(type == 0)
        regions[i]->setVisibility(mode, recursive);
      else
        for(unsigned int j = 0; j < regions[i]->physicals.size(); j++)
          VisibilityManager::instance()->setVisibilityByNumber
            (9, regions[i]->physicals[j], mode, recursive);
    }
  }
  int pos = GUI::instance()->visibility->browser->position();
  visibility_cb(NULL, (void*)"redraw_only");
  GUI::instance()->visibility->browser->position(pos);
}

void visibility_interactive_cb(CALLBACK_ARGS)
{
  const char *str = (const char*)data;
  const char *help;
  int what;
  char mode;

  if(!strcmp(str, "hide_elements")){
    CTX.pick_elements = 1;
    what = ENT_ALL;
    mode = 0;
    help = "elements to hide";
  }
  else if(!strcmp(str, "hide_points")){
    CTX.pick_elements = 0;
    what = ENT_POINT;
    mode = 0;
    help = "points to hide";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "hide_lines")){
    CTX.pick_elements = 0;
    what = ENT_LINE;
    mode = 0;
    help = "lines to hide";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "hide_surfaces")){
    CTX.pick_elements = 0;
    what = ENT_SURFACE;
    mode = 0;
    help = "surfaces to hide";
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "hide_volumes")){
    CTX.pick_elements = 0;
    what = ENT_VOLUME;
    mode = 0;
    help = "volumes to hide";
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_elements")){
    CTX.pick_elements = 1;
    what = ENT_ALL;
    mode = 1;
    help = "elements to show";
  }
  else if(!strcmp(str, "show_points")){
    CTX.pick_elements = 0;
    what = ENT_POINT;
    mode = 1;
    help = "points to show";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_lines")){
    CTX.pick_elements = 0;
    what = ENT_LINE;
    mode = 1;
    help = "lines to show";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_surfaces")){
    CTX.pick_elements = 0;
    what = ENT_SURFACE;
    mode = 1;
    help = "surfaces to show";
    if(GModel::current()->getMeshStatus() < 2)
      opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_volumes")){
    CTX.pick_elements = 0;
    what = ENT_VOLUME;
    mode = 1;
    help = "volumes to show";
    if(GModel::current()->getMeshStatus() < 3)
      opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(str, "show_all")){
    for(int i = 1; i <= 5; i++) // elements, points, lines, surfaces, volumes
      VisibilityManager::instance()->setVisibilityByNumber(i, -1, 1, false);
    CTX.mesh.changed = ENT_ALL;
    Draw();  
    return;
  }
  else
    return;

  std::vector<GVertex*> vertices, vertices_old;
  std::vector<GEdge*> edges, edges_old;
  std::vector<GFace*> faces, faces_old;
  std::vector<GRegion*> regions, regions_old;
  std::vector<MElement*> elements, elements_old;

  while(1) {
    if(what == ENT_ALL) 
      CTX.mesh.changed = ENT_ALL;
    Draw();
    Msg::StatusBar(3, false, "Select %s\n[Press %s'q' to abort]", 
        help, mode ? "" : "'u' to undo or ");

    char ib = SelectEntity(what, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      _apply_visibility(mode, vertices, edges, faces, regions, elements);
      // store for possible undo later
      vertices_old = vertices;
      edges_old = edges;
      faces_old = faces;
      regions_old = regions;
      elements_old = elements;
    }
    if(ib == 'u' && !mode){ // undo only in hide mode
      _apply_visibility(2, vertices_old, edges_old, faces_old, 
                        regions_old, elements_old);
    }
    if(ib == 'q'){
      break;
    }
  }

  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Draw();  
  Msg::StatusBar(3, false, "");
}

// Clipping planes menu

void clip_cb(CALLBACK_ARGS)
{
  GUI::instance()->clipping->show();
}

void clip_num_cb(CALLBACK_ARGS)
{
  GUI::instance()->clipping->resetBrowser();
}

void clip_update_cb(CALLBACK_ARGS)
{
  if(GUI::instance()->clipping->group[0]->visible()){ // clipping planes
    int idx = GUI::instance()->clipping->choice->value();
    CTX.geom.clip &= ~(1 << idx);
    CTX.mesh.clip &= ~(1 << idx);
    for(unsigned int i = 0; i < PView::list.size(); i++)
      PView::list[i]->getOptions()->Clip &= ~(1 << idx);
    for(int i = 0; i < GUI::instance()->clipping->browser->size(); i++){
      if(GUI::instance()->clipping->browser->selected(i + 1)){
        if(i == 0)
          CTX.geom.clip |= (1 << idx);
        else if(i == 1)
          CTX.mesh.clip |= (1 << idx);
        else if(i - 2 < PView::list.size())
          PView::list[i - 2]->getOptions()->Clip |= (1 << idx);
      }
    }
    for(int i = 0; i < 4; i++)
      CTX.clip_plane[idx][i] = GUI::instance()->clipping->value[i]->value();
  }
  else{ // clipping box
    CTX.geom.clip = 0;
    CTX.mesh.clip = 0;
    for(unsigned int i = 0; i < PView::list.size(); i++)
      PView::list[i]->getOptions()->Clip = 0;
    for(int i = 0; i < GUI::instance()->clipping->browser->size(); i++){
      if(GUI::instance()->clipping->browser->selected(i + 1)){
        for(int idx = 0; idx < 6; idx++){
          if(i == 0)
            CTX.geom.clip |= (1 << idx);
          else if(i == 1)
            CTX.mesh.clip |= (1 << idx);
          else if(i - 2 < PView::list.size())
            PView::list[i - 2]->getOptions()->Clip |= (1 << idx);
        }
      }
    }
    double c[3] = {GUI::instance()->clipping->value[4]->value(),
                   GUI::instance()->clipping->value[5]->value(),
                   GUI::instance()->clipping->value[6]->value()};
    double d[3] = {GUI::instance()->clipping->value[7]->value(),
                   GUI::instance()->clipping->value[8]->value(),
                   GUI::instance()->clipping->value[9]->value()};
    // left
    CTX.clip_plane[0][0] = 1.;  CTX.clip_plane[0][1] = 0.;  CTX.clip_plane[0][2] = 0.;
    CTX.clip_plane[0][3] = -(c[0] - d[0] / 2.);
    // right
    CTX.clip_plane[1][0] = -1.; CTX.clip_plane[1][1] = 0.; CTX.clip_plane[1][2] = 0.;
    CTX.clip_plane[1][3] = (c[0] + d[0] / 2.);
    // top
    CTX.clip_plane[2][0] = 0.; CTX.clip_plane[2][1] = 1.; CTX.clip_plane[2][2] = 0.;
    CTX.clip_plane[2][3] = -(c[1] - d[1] / 2.);
    // bottom
    CTX.clip_plane[3][0] = 0.; CTX.clip_plane[3][1] = -1.; CTX.clip_plane[3][2] = 0.;
    CTX.clip_plane[3][3] = (c[1] + d[1] / 2.);
    // near
    CTX.clip_plane[4][0] = 0.; CTX.clip_plane[4][1] = 0.; CTX.clip_plane[4][2] = 1.;
    CTX.clip_plane[4][3] = -(c[2] - d[2] / 2.);
    // far
    CTX.clip_plane[5][0] = 0.; CTX.clip_plane[5][1] = 0.; CTX.clip_plane[5][2] = -1.;
    CTX.clip_plane[5][3] = (c[2] + d[2] / 2.);
  }

  if(CTX.clip_whole_elements || 
     CTX.clip_whole_elements != GUI::instance()->clipping->butt[0]->value()){
    for(int clip = 0; clip < 6; clip++){
      if(CTX.mesh.clip)
	CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
      for(unsigned int index = 0; index < PView::list.size(); index++)
	if(PView::list[index]->getOptions()->Clip)
	  PView::list[index]->setChanged(true);
    }
  }
  
  CTX.clip_whole_elements = GUI::instance()->clipping->butt[0]->value();
  CTX.clip_only_draw_intersecting_volume = GUI::instance()->clipping->butt[1]->value();
  CTX.clip_only_volume = GUI::instance()->clipping->butt[2]->value();
  
  int old = CTX.draw_bbox;
  CTX.draw_bbox = 1;
  if(CTX.fast_redraw)
    CTX.post.draw = CTX.mesh.draw = 0;
  Draw();
  CTX.draw_bbox = old;
  CTX.post.draw = CTX.mesh.draw = 1;
}

void clip_invert_cb(CALLBACK_ARGS)
{
  for(int i = 0; i < 4; i++)
    GUI::instance()->clipping->value[i]->value(-GUI::instance()->clipping->value[i]->value());
  clip_update_cb(NULL, NULL);
}

void clip_reset_cb(CALLBACK_ARGS)
{
  CTX.geom.clip = 0;
  CTX.mesh.clip = 0;
  for(unsigned int index = 0; index < PView::list.size(); index++)
    PView::list[index]->getOptions()->Clip = 0;

  for(int i = 0; i < 6; i++){
    CTX.clip_plane[i][0] = 1.;
    for(int j = 1; j < 4; j++)
      CTX.clip_plane[i][j] = 0.;
  }

  if(CTX.clip_whole_elements){
    CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
    for(unsigned int index = 0; index < PView::list.size(); index++)
      PView::list[index]->setChanged(true);
  }

  GUI::instance()->clipping->resetBrowser();
  Draw();
}

// Manipulator menu

void manip_cb(CALLBACK_ARGS)
{
  GUI::instance()->manip->show();
}

void manip_update_cb(CALLBACK_ARGS)
{
  drawContext *ctx = GUI::instance()->graph[0]->gl->getDrawContext();
  ctx->r[0] = GUI::instance()->manip->value[0]->value();
  ctx->r[1] = GUI::instance()->manip->value[1]->value();
  ctx->r[2] = GUI::instance()->manip->value[2]->value();
  ctx->t[0] = GUI::instance()->manip->value[3]->value();
  ctx->t[1] = GUI::instance()->manip->value[4]->value();
  ctx->t[2] = GUI::instance()->manip->value[5]->value();
  ctx->s[0] = GUI::instance()->manip->value[6]->value();
  ctx->s[1] = GUI::instance()->manip->value[7]->value();
  ctx->s[2] = GUI::instance()->manip->value[8]->value();
  ctx->setQuaternionFromEulerAngles();
  Draw();
}

// Help Menu (if you change the following, please also change the
// texinfo documentation in doc/texinfo/shortcuts.texi)

#if defined(__APPLE__)
#  define CC(str) "Cmd+" str " "
#else
#  define CC(str) "Ctrl+" str
#endif

void help_short_cb(CALLBACK_ARGS)
{
  Msg::Direct(" ");
  Msg::Direct("Keyboard shortcuts:");
  Msg::Direct(" ");
  Msg::Direct("  Left arrow    Go to previous time step"); 
  Msg::Direct("  Right arrow   Go to next time step"); 
  Msg::Direct("  Up arrow      Make previous view visible"); 
  Msg::Direct("  Down arrow    Make next view visible"); 
  Msg::Direct(" ");
  Msg::Direct("  <             Go back to previous context");
  Msg::Direct("  >             Go forward to next context");
  Msg::Direct("  0             Reload project file");
  Msg::Direct("  1 or F1       Mesh lines");
  Msg::Direct("  2 or F2       Mesh surfaces");
  Msg::Direct("  3 or F3       Mesh volumes");
  Msg::Direct("  Escape        Cancel lasso zoom/selection, toggle mouse selection ON/OFF");
  Msg::Direct(" ");
  Msg::Direct("  g             Go to geometry module");
  Msg::Direct("  m             Go to mesh module");
  Msg::Direct("  p             Go to post-processing module");
  Msg::Direct("  s             Go to solver module");
  Msg::Direct(" ");
  Msg::Direct("  Shift+a       Bring all windows to front");
  Msg::Direct("  Shift+g       Show geometry options");
  Msg::Direct("  Shift+m       Show mesh options");
  Msg::Direct("  Shift+o       Show general options"); 
  Msg::Direct("  Shift+p       Show post-processing options");
  Msg::Direct("  Shift+s       Show solver options"); 
  Msg::Direct("  Shift+u       Show post-processing view plugins");
  Msg::Direct("  Shift+w       Show post-processing view options");
  Msg::Direct("  Shift+Escape  Enable full mouse selection");
  Msg::Direct(" ");
  Msg::Direct("  " CC("i") "        Show statistics window"); 
  Msg::Direct("  " CC("l") "        Show message console");
#if defined(__APPLE__)
  Msg::Direct("  " CC("m") "        Minimize window"); 
#endif
  Msg::Direct("  " CC("n") "        Create new project file"); 
  Msg::Direct("  " CC("o") "        Open project file"); 
  Msg::Direct("  " CC("q") "        Quit");
  Msg::Direct("  " CC("r") "        Rename project file");
  Msg::Direct("  " CC("s") "        Save file as");
  Msg::Direct(" ");
  Msg::Direct("  Shift+" CC("c") "  Show clipping plane window");
  Msg::Direct("  Shift+" CC("m") "  Show manipulator window"); 
  Msg::Direct("  Shift+" CC("n") "  Show option window"); 
  Msg::Direct("  Shift+" CC("o") "  Merge file(s)"); 
  Msg::Direct("  Shift+" CC("s") "  Save mesh in default format");
  Msg::Direct("  Shift+" CC("u") "  Show plugin window");
  Msg::Direct("  Shift+" CC("v") "  Show visibility window");
  Msg::Direct(" ");
  Msg::Direct("  Alt+a         Loop through axes modes"); 
  Msg::Direct("  Alt+b         Hide/show bounding boxes");
  Msg::Direct("  Alt+c         Loop through predefined color schemes");
  Msg::Direct("  Alt+e         Hide/Show element outlines for visible post-processing views");
  Msg::Direct("  Alt+f         Change redraw mode (fast/full)"); 
  Msg::Direct("  Alt+h         Hide/show all post-processing views"); 
  Msg::Direct("  Alt+i         Hide/show all post-processing view scales");
  Msg::Direct("  Alt+l         Hide/show geometry lines");
  Msg::Direct("  Alt+m         Toggle visibility of all mesh entities");
  Msg::Direct("  Alt+n         Hide/show all post-processing view annotations");
  Msg::Direct("  Alt+o         Change projection mode (orthographic/perspective)");
  Msg::Direct("  Alt+p         Hide/show geometry points");
  Msg::Direct("  Alt+r         Loop through range modes for visible post-processing views"); 
  Msg::Direct("  Alt+s         Hide/show geometry surfaces");
  Msg::Direct("  Alt+t         Loop through interval modes for visible post-processing views"); 
  Msg::Direct("  Alt+v         Hide/show geometry volumes");
  Msg::Direct("  Alt+w         Enable/disable all lighting");
  Msg::Direct("  Alt+x         Set X view"); 
  Msg::Direct("  Alt+y         Set Y view"); 
  Msg::Direct("  Alt+z         Set Z view"); 
  Msg::Direct(" ");
  Msg::Direct("  Alt+Shift+a   Hide/show small axes"); 
  Msg::Direct("  Alt+Shift+b   Hide/show mesh volume faces");
  Msg::Direct("  Alt+Shift+d   Hide/show mesh surface faces");
  Msg::Direct("  Alt+Shift+l   Hide/show mesh lines");
  Msg::Direct("  Alt+Shift+o   Adjust projection parameters");
  Msg::Direct("  Alt+Shift+p   Hide/show mesh points");
  Msg::Direct("  Alt+Shift+s   Hide/show mesh surface edges");
  Msg::Direct("  Alt+Shift+v   Hide/show mesh volume edges");
  Msg::Direct("  Alt+Shift+w   Reverse all mesh normals");
  Msg::Direct("  Alt+Shift+x   Set -X view"); 
  Msg::Direct("  Alt+Shift+y   Set -Y view"); 
  Msg::Direct("  Alt+Shift+z   Set -Z view"); 
  Msg::Direct(" ");
  GUI::instance()->messages->show();
}

void help_mouse_cb(CALLBACK_ARGS)
{
  Msg::Direct(" ");
  Msg::Direct("Mouse actions:");
  Msg::Direct(" ");
  Msg::Direct("  Move                - Highlight the entity under the mouse pointer");
  Msg::Direct("                        and display its properties in the status bar");
  Msg::Direct("                      - Resize a lasso zoom or a lasso (un)selection");
  Msg::Direct("  Left button         - Rotate");
  Msg::Direct("                      - Select an entity");
  Msg::Direct("                      - Accept a lasso zoom or a lasso selection"); 
  Msg::Direct("  Ctrl+Left button    Start a lasso zoom or a lasso (un)selection"); 
  Msg::Direct("  Middle button       - Zoom");
  Msg::Direct("                      - Unselect an entity");
  Msg::Direct("                      - Accept a lasso zoom or a lasso unselection");
  Msg::Direct("  Ctrl+Middle button  Orthogonalize display"); 
  Msg::Direct("  Right button        - Pan");
  Msg::Direct("                      - Cancel a lasso zoom or a lasso (un)selection");
  Msg::Direct("                      - Pop-up menu on post-processing view button");
  Msg::Direct("  Ctrl+Right button   Reset to default viewpoint");   
  Msg::Direct(" ");   
  Msg::Direct("  For a 2 button mouse, Middle button = Shift+Left button");
  Msg::Direct("  For a 1 button mouse, Middle button = Shift+Left button, Right button = Alt+Left button");
  Msg::Direct(" ");
  GUI::instance()->messages->show();
}

void help_command_line_cb(CALLBACK_ARGS)
{
  Msg::Direct(" ");
  Print_Usage("gmsh");
  GUI::instance()->messages->show();
}

void _replace_multi_format(const char *in, const char *val, char *out)
{
  unsigned int i = 0, j = 0;

  out[0] = '\0';
  while(i < strlen(in)){
    if(in[i] == '%' && i != strlen(in) - 1){
      if(in[i + 1] == 's'){
        strcat(out, val);
        i += 2;
        j += strlen(val);
      }
      else{
        Msg::Warning("Skipping unknown format '%%%c' in '%s'", in[i + 1], in);
        i += 2;
      }
    }
    else{
      out[j] = in[i];
      out[j + 1] = '\0';
      i++;
      j++;
    }
  }
  out[j] = '\0';
}

void help_online_cb(CALLBACK_ARGS)
{
  std::string prog = FixWindowsPath(CTX.web_browser);
  char cmd[1024];
  _replace_multi_format(prog.c_str(), "http://geuz.org/gmsh/doc/texinfo/", cmd);
  SystemCall(cmd);
}

void help_license_cb(CALLBACK_ARGS)
{
  std::string prog = FixWindowsPath(CTX.web_browser);
  char cmd[1024];
  _replace_multi_format(prog.c_str(), "http://geuz.org/gmsh/doc/LICENSE.txt", cmd);
  SystemCall(cmd);
}

void help_credits_cb(CALLBACK_ARGS)
{
  std::string prog = FixWindowsPath(CTX.web_browser);
  char cmd[1024];
  _replace_multi_format(prog.c_str(), "http://geuz.org/gmsh/doc/CREDITS.txt", cmd);
  SystemCall(cmd);
}

void help_about_cb(CALLBACK_ARGS)
{
  GUI::instance()->about->win->show();
}

// Module Menu

void mod_geometry_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_geometry, 0);
}

void mod_mesh_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_mesh, 0);
}

void mod_solver_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_solver, 0);
}

void mod_post_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_post, 0);
}

void mod_back_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(NULL, -1);
}

void mod_forward_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(NULL, 1);
}

// Dynamic Geomtry Menus

void geometry_elementary_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_geometry_elementary, 0);
}

void geometry_physical_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_geometry_physical, 0);
}

void geometry_edit_cb(CALLBACK_ARGS)
{
  std::string prog = FixWindowsPath(CTX.editor);
  std::string file = FixWindowsPath(CTX.filename);
  char cmd[1024];
  _replace_multi_format(prog.c_str(), file.c_str(), cmd);
  SystemCall(cmd);
}

void geometry_reload_cb(CALLBACK_ARGS)
{
  OpenProject(CTX.filename);
  Draw();
}

void geometry_elementary_add_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_geometry_elementary_add, 0);
}

static void _add_new_point()
{
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  GUI::instance()->geoContext->show(1);

  while(1) {
    GUI::instance()->graph[0]->gl->addPointMode = true;
    Msg::StatusBar(3, false, "Move mouse and/or enter coordinates\n"
        "[Press 'Shift' to hold position, 'e' to add point or 'q' to abort]");
    std::vector<GVertex*> vertices;
    std::vector<GEdge*> edges;
    std::vector<GFace*> faces;
    std::vector<GRegion*> regions;
    std::vector<MElement*> elements;
    char ib = SelectEntity(ENT_NONE, vertices, edges, faces, regions, elements);
    if(ib == 'e'){
      add_point(CTX.filename,
                GUI::instance()->geoContext->input[2]->value(),
                GUI::instance()->geoContext->input[3]->value(),
                GUI::instance()->geoContext->input[4]->value(),
                GUI::instance()->geoContext->input[5]->value());
      GUI::instance()->resetVisibility();
      Draw();
    }
    if(ib == 'q'){
      GUI::instance()->graph[0]->gl->addPointMode = false;
      break;
    }
  }

  Msg::StatusBar(3, false, "");
}

static void _add_new_multiline(std::string type)
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  std::vector<int> p;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select control points\n"
          "[Press 'e' to end selection or 'q' to abort]");
    else
      Msg::StatusBar(3, false, "Select control points\n"
          "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      for(unsigned int i = 0; i < vertices.size(); i++){
        HighlightEntity(vertices[i]);
        p.push_back(vertices[i]->tag());
      }
      Draw();
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during multi-line creation");
    }
    if(ib == 'e') {
      if(p.size() >= 2)
	add_multline(type, p, CTX.filename);
      GUI::instance()->resetVisibility();
      ZeroHighlight();
      Draw();
      p.clear();
    }
    if(ib == 'u') {
      if(p.size()){
        ZeroHighlightEntityNum(p.back(), 0, 0, 0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
  }

  Msg::StatusBar(3, false, "");
}

static void _add_new_line()
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  std::vector<int> p;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
          "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select end point\n"
          "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      HighlightEntity(vertices[0]);
      Draw();
      p.push_back(vertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during line creation");
    }
    if(ib == 'u') {
      if(p.size()){
        ZeroHighlightEntityNum(p.back(), 0, 0, 0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(p.size() == 2) {
      add_multline("Line", p, CTX.filename);
      GUI::instance()->resetVisibility();
      ZeroHighlight();
      Draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void _add_new_circle()
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  std::vector<int> p;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
          "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select center point\n"
          "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 2)
      Msg::StatusBar(3, false, "Select end point\n"
          "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      HighlightEntity(vertices[0]);
      Draw();
      p.push_back(vertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during circle creation");
    }
    if(ib == 'u') {
      if(p.size()){
        ZeroHighlightEntityNum(p.back(), 0, 0, 0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(p.size() == 3) {
      add_circ(p[0], p[1], p[2], CTX.filename); // begin, center, end
      GUI::instance()->resetVisibility();
      ZeroHighlight();
      Draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void _add_new_ellipse()
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  std::vector<int> p;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();

  while(1) {
    if(p.empty())
      Msg::StatusBar(3, false, "Select start point\n"
          "[Press 'q' to abort]");
    if(p.size() == 1)
      Msg::StatusBar(3, false, "Select center point\n"
          "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 2)
      Msg::StatusBar(3, false, "Select major axis point\n"
          "[Press 'u' to undo last selection or 'q' to abort]");
    if(p.size() == 3)
      Msg::StatusBar(3, false, "Select end point\n"
          "[Press 'u' to undo last selection or 'q' to abort]");
    char ib = SelectEntity(ENT_POINT, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      HighlightEntity(vertices[0]);
      Draw();
      p.push_back(vertices[0]->tag());
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during ellipse creation");
    }
    if(ib == 'u') {
      if(p.size()){
        ZeroHighlightEntityNum(p.back(), 0, 0, 0);
        Draw();
        p.pop_back();
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(p.size() == 4) {
      add_ell(p[0], p[1], p[2], p[3], CTX.filename);
      GUI::instance()->resetVisibility();
      ZeroHighlight();
      Draw();
      p.clear();
    }
  }

  Msg::StatusBar(3, false, "");
}

static void _add_new_surface_volume(int mode)
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  int type, num;

  List_T *List1 = List_Create(10, 10, sizeof(int));
  List_T *List2 = List_Create(10, 10, sizeof(int));

  if(mode == 2) {
    type = ENT_SURFACE;
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else {
    type = ENT_LINE;
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  Draw();

  while(1) {
    List_Reset(List1);
    List_Reset(List2);

    while(1) {
      if(type == ENT_LINE){
        if(!List_Nbr(List1))
          Msg::StatusBar(3, false, "Select surface boundary\n"
              "[Press 'q' to abort]");
        else
          Msg::StatusBar(3, false, "Select surface boundary\n"
              "[Press 'u' to undo last selection or 'q' to abort]");
      }
      else{
        if(!List_Nbr(List1))
          Msg::StatusBar(3, false, "Select volume boundary\n"
              "[Press 'q' to abort]");
        else
          Msg::StatusBar(3, false, "Select volume boundary\n"
              "[Press 'u' to undo last selection or 'q' to abort]");
      }

      char ib = SelectEntity(type, vertices, edges, faces, regions, elements);
      if(ib == 'q') {
        ZeroHighlight();
        Draw();
        goto stopall;
      }
      if(ib == 'u') {
        if(List_Nbr(List1) > 0){
          List_Read(List1, List_Nbr(List1)-1, &num);
          ZeroHighlightEntityNum(0,
                                 (type == ENT_LINE) ? abs(num) : 0, 
                                 (type != ENT_LINE) ? abs(num) : 0,
                                 0);
          List_Pop(List1);
          Draw();
        }
      }
      if(ib == 'r') {
        Msg::Warning("Entity de-selection not supported yet during surface/volume creation");
      }
      if(ib == 'l') {
        int num = (type == ENT_LINE) ? edges[0]->tag() : faces[0]->tag();
        if(SelectContour(type, num, List1)) {
          if(type == ENT_LINE)
            add_lineloop(List1, CTX.filename, &num);
          else
            add_surfloop(List1, CTX.filename, &num);
          List_Reset(List1);
          List_Add(List2, &num);
          while(1) {
            if(!List_Nbr(List1))
              Msg::StatusBar(3, false, "Select hole boundaries (if none, press 'e')\n"
                  "[Press 'e' to end selection or 'q' to abort]");
            else
              Msg::StatusBar(3, false, "Select hole boundaries\n"
                  "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
            ib = SelectEntity(type, vertices, edges, faces, regions, elements);
            if(ib == 'q') {
              ZeroHighlight();
              Draw();
              goto stopall;
            }
            if(ib == 'e') {
              ZeroHighlight();
              Draw();
              List_Reset(List1);
              break;
            }
            if(ib == 'u') {
              if(List_Nbr(List1) > 0){
                List_Read(List1, List_Nbr(List1)-1, &num);
                ZeroHighlightEntityNum(0,
                                       (type == ENT_LINE) ? abs(num) : 0, 
                                       (type != ENT_LINE) ? abs(num) : 0,
                                       0);
                List_Pop(List1);
                Draw();
              }
            }
            if(ib == 'l') {
              num = (type == ENT_LINE) ? edges[0]->tag() : faces[0]->tag();
              if(SelectContour(type, num, List1)) {
                if(type == ENT_LINE)
                  add_lineloop(List1, CTX.filename, &num);
                else
                  add_surfloop(List1, CTX.filename, &num);
                List_Reset(List1);
                List_Add(List2, &num);
              }
            }
            if(ib == 'r') {
              Msg::Warning("Entity de-selection not supported yet during surface/volume creation");
            }
          }
          if(List_Nbr(List2)) {
            switch (mode) {
            case 0: add_surf("Plane Surface", List2, CTX.filename); break;
            case 1: add_surf("Ruled Surface", List2, CTX.filename); break;
            case 2: add_vol(List2, CTX.filename); break;
            }
            GUI::instance()->resetVisibility();
            ZeroHighlight();
            Draw();
            break;
          }
        } // if SelectContour
      }
    }
  }

stopall:;
  List_Delete(List1);
  List_Delete(List2);

  Msg::StatusBar(3, false, "");
}

void geometry_elementary_add_new_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_new, 0);
    return;
  }

  std::string str((const char*)data);
  if(str == "Parameter")
    GUI::instance()->geoContext->show(0);
  else if(str == "Point")
    _add_new_point();
  else if(str == "Line")
    _add_new_line();
  else if(str == "Spline")
    _add_new_multiline(str);
  else if(str == "BSpline")
    _add_new_multiline(str);
  else if(str == "Circle")
    _add_new_circle();
  else if(str == "Ellipse")
    _add_new_ellipse();
  else if(str == "Plane Surface")
    _add_new_surface_volume(0);
  else if(str == "Ruled Surface")
    _add_new_surface_volume(1);
  else if(str == "Volume")
    _add_new_surface_volume(2);
  else
    Msg::Error("Unknown entity to create: %s", str.c_str());
}

static void _split_selection()
{
  opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  Draw();
  Msg::StatusBar(3, false, "Select a line to split\n"
          "[Press 'q' to abort]");
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  GEdge* edge_to_split = NULL;
  while(1){
    char ib = SelectEntity(2, vertices, edges, faces, regions, elements);
    if(ib == 'q')
      break;
    if(!edges.empty()){
      edge_to_split = edges[0];
      HighlightEntity(edges[0]);
      break;
    }
  }
  Msg::StatusBar(3, false, "");
  if(edges.empty())
    return;
  List_T *List1 = List_Create(5, 5, sizeof(int));
  Msg::StatusBar(3, false, "Select break points\n"
                 "[Press 'e' to end selection or 'q' to abort]");
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  Draw();
  while(1){
    char ib = SelectEntity(1, vertices, edges, faces, regions, elements);
    if(ib == 'q')
      break;
    if(ib == 'e'){
      split_edge(edge_to_split->tag(), List1, CTX.filename);
      break;
    }
    if(!vertices.empty()){
      for(unsigned int i = 0; i < vertices.size(); i++){
        int tag = vertices[i]->tag();
        int index = List_ISearchSeq(List1, &tag, fcmp_int); 
        if(index < 0) List_Add(List1, &tag);
        HighlightEntity(vertices[i]);
      }
    }
  }
  Msg::StatusBar(3, false, "");
  GUI::instance()->resetVisibility();
  ZeroHighlight();
  Draw();
}

static void _action_point_line_surface_volume(int action, int mode, const char *what)
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  int type;
  const char *str;

  if(!strcmp(what, "Point")) {
    type = ENT_POINT;
    str = "points";
    opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Line")) {
    type = ENT_LINE;
    str = "lines";
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Surface")) {
    type = ENT_SURFACE;
    str = "surfaces";
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1);
  }
  else if(!strcmp(what, "Volume")) {
    type = ENT_VOLUME;
    str = "volumes";
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1);
  }
  else{
    Msg::Error("Unknown entity to select");
    return;
  }

  if(action == 8){
    GUI::instance()->meshContext->show(0);
  }

  Draw();
    
  List_T *List1 = List_Create(5, 5, sizeof(int));
  while(1) {
    if(!List_Nbr(List1))
      Msg::StatusBar(3, false, "Select %s\n"
          "[Press 'e' to end selection or 'q' to abort]", str);
    else
      Msg::StatusBar(3, false, "Select %s\n"
          "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]", str);

    char ib = SelectEntity(type, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      // we don't use List_Insert in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      int tag;
      switch (type) {
      case ENT_POINT: 
        for(unsigned int i = 0; i < vertices.size(); i++){
          HighlightEntity(vertices[i]);
          tag = vertices[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_LINE:
        for(unsigned int i = 0; i < edges.size(); i++){
          HighlightEntity(edges[i]);
          tag = edges[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_SURFACE:
        for(unsigned int i = 0; i < faces.size(); i++){
          HighlightEntity(faces[i]);
          tag = faces[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      case ENT_VOLUME:
        for(unsigned int i = 0; i < regions.size(); i++){
          HighlightEntity(regions[i]);
          tag = regions[i]->tag();
          if(List_ISearchSeq(List1, &tag, fcmp_int) < 0)
            List_Add(List1, &tag);
        }
        break;
      }
      Draw();
    }
    if(ib == 'r') {
      // we don't use List_Suppress in order to keep the original
      // ordering (this is slower, but this way undo works as
      // expected)
      int index, tag;
      switch (type) {
      case ENT_POINT:
        for(unsigned int i = 0; i < vertices.size(); i++){
          tag = vertices[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          ZeroHighlightEntityNum(tag, 0, 0, 0);
        }
        break;
      case ENT_LINE:
        for(unsigned int i = 0; i < edges.size(); i++){
          tag = edges[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          ZeroHighlightEntityNum(0, tag, 0, 0);
        }
        break;
      case ENT_SURFACE:
        for(unsigned int i = 0; i < faces.size(); i++){
          tag = faces[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          ZeroHighlightEntityNum(0, 0, tag, 0);
        }
        break;
      case ENT_VOLUME:
        for(unsigned int i = 0; i < regions.size(); i++){
          tag = regions[i]->tag();
          index = List_ISearchSeq(List1, &tag, fcmp_int); 
          if(index >= 0) List_PSuppress(List1, index);
          ZeroHighlightEntityNum(0, 0, 0, tag);
        }
        break;
      }
      Draw();
    }
    if(ib == 'u') {
      if(List_Nbr(List1)) {
        int num;
        List_Read(List1, List_Nbr(List1) - 1, &num);
        ZeroHighlightEntityNum((type == ENT_POINT) ? num : 0,
                               (type == ENT_LINE) ? num : 0,
                               (type == ENT_SURFACE) ? num : 0,
                               (type == ENT_VOLUME) ? num : 0);
        Draw();
        List_Pop(List1);
      }
    }
    if(ib == 'i') {
      Msg::Error("Inverting selection!");
    }
    if(ib == 'e') {
      if(List_Nbr(List1)){
        switch (action) {
        case 0:
          translate(mode, List1, CTX.filename, what,
                    GUI::instance()->geoContext->input[6]->value(),
                    GUI::instance()->geoContext->input[7]->value(),
                    GUI::instance()->geoContext->input[8]->value());
          break;
        case 1:
          rotate(mode, List1, CTX.filename, what,
                 GUI::instance()->geoContext->input[12]->value(),
                 GUI::instance()->geoContext->input[13]->value(),
                 GUI::instance()->geoContext->input[14]->value(),
                 GUI::instance()->geoContext->input[9]->value(),
                 GUI::instance()->geoContext->input[10]->value(),
                 GUI::instance()->geoContext->input[11]->value(),
                 GUI::instance()->geoContext->input[15]->value());
          break;
        case 2:
          dilate(mode, List1, CTX.filename, what,
                 GUI::instance()->geoContext->input[16]->value(),
                 GUI::instance()->geoContext->input[17]->value(),
                 GUI::instance()->geoContext->input[18]->value(),
                 GUI::instance()->geoContext->input[19]->value());
          break;
        case 3:
          symmetry(mode, List1, CTX.filename, what,
                   GUI::instance()->geoContext->input[20]->value(),
                   GUI::instance()->geoContext->input[21]->value(),
                   GUI::instance()->geoContext->input[22]->value(),
                   GUI::instance()->geoContext->input[23]->value());
          break;
        case 4:
          extrude(List1, CTX.filename, what,
                  GUI::instance()->geoContext->input[6]->value(),
                  GUI::instance()->geoContext->input[7]->value(),
                  GUI::instance()->geoContext->input[8]->value());
          break;
        case 5:
          protude(List1, CTX.filename, what,
                  GUI::instance()->geoContext->input[12]->value(),
                  GUI::instance()->geoContext->input[13]->value(),
                  GUI::instance()->geoContext->input[14]->value(),
                  GUI::instance()->geoContext->input[9]->value(),
                  GUI::instance()->geoContext->input[10]->value(),
                  GUI::instance()->geoContext->input[11]->value(),
                  GUI::instance()->geoContext->input[15]->value());
          break;
        case 6:
          delet(List1, CTX.filename, what);
          break;
        case 7:
          add_physical(what, List1, CTX.filename);
          break;
        case 8:
          add_charlength(List1, CTX.filename, GUI::instance()->meshContext->input[0]->value());
          break;
        case 9:
          add_recosurf(List1, CTX.filename);
          break;

        default:
          Msg::Error("Unknown action on selected entities");
          break;
        }
        List_Reset(List1);
        GUI::instance()->resetVisibility();
        ZeroHighlight();
        if(action <= 6) SetBoundingBox();
        Draw();
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
  }
  List_Delete(List1);

  Msg::StatusBar(3, false, "");
}
  
void geometry_elementary_add_translate_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_translate, 0);
    return;
  }
  GUI::instance()->geoContext->show(2);
  _action_point_line_surface_volume(0, 1, (const char*)data);
}

void geometry_elementary_add_rotate_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_rotate, 0);
    return;
  }
  GUI::instance()->geoContext->show(3);
  _action_point_line_surface_volume(1, 1, (const char*)data);
}

void geometry_elementary_add_scale_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_scale, 0);
    return;
  }
  GUI::instance()->geoContext->show(4);
  _action_point_line_surface_volume(2, 1, (const char*)data);
}

void geometry_elementary_add_symmetry_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_add_symmetry, 0);
    return;
  }
  GUI::instance()->geoContext->show(5);
  _action_point_line_surface_volume(3, 1, (const char*)data);
}

void geometry_elementary_translate_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_translate, 0);
    return;
  }
  GUI::instance()->geoContext->show(2);
  _action_point_line_surface_volume(0, 0, (const char*)data);
}

void geometry_elementary_rotate_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_rotate, 0);
    return;
  }
  GUI::instance()->geoContext->show(3);
  _action_point_line_surface_volume(1, 0, (const char*)data);
}

void geometry_elementary_scale_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_scale, 0);
    return;
  }
  GUI::instance()->geoContext->show(4);
  _action_point_line_surface_volume(2, 0, (const char*)data);
}

void geometry_elementary_symmetry_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_symmetry, 0);
    return;
  }
  GUI::instance()->geoContext->show(5);
  _action_point_line_surface_volume(3, 0, (const char*)data);
}

void geometry_elementary_extrude_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_geometry_elementary_extrude, 0);
}

void geometry_elementary_extrude_translate_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_extrude_translate, 0);
    return;
  }
  GUI::instance()->geoContext->show(2);
  _action_point_line_surface_volume(4, 0, (const char*)data);
}

void geometry_elementary_extrude_rotate_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_extrude_rotate, 0);
    return;
  }
  GUI::instance()->geoContext->show(3);
  _action_point_line_surface_volume(5, 0, (const char*)data);
}

void geometry_elementary_delete_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_delete, 0);
    return;
  }
  _action_point_line_surface_volume(6, 0, (const char*)data);
}

void geometry_elementary_split_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_elementary_split, 0);
    return;
  }
  _split_selection();
}

void geometry_elementary_coherence_cb(CALLBACK_ARGS)
{
  coherence(CTX.filename);
}

void geometry_physical_add_cb(CALLBACK_ARGS)
{
  if(!data){
    GUI::instance()->menu->setContext(menu_geometry_physical_add, 0);
    return;
  }
  std::string str((const char*)data);
  if(str == "Point")
    GUI::instance()->callForSolverPlugin(0);
  else if(str == "Line")
    GUI::instance()->callForSolverPlugin(1);

  _action_point_line_surface_volume(7, 0, str.c_str());
}

// Dynamic Mesh Menus

void mesh_save_cb(CALLBACK_ARGS)
{
  char name[256];
  if(CTX.output_filename)
    strcpy(name, CTX.output_filename);
  else
    GetDefaultFileName(CTX.mesh.format, name);
  if(CTX.confirm_overwrite) {
    if(!StatFile(name))
      if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                    "Cancel", "Replace", NULL, name))
        return;
  }
  CreateOutputFile(name, CTX.mesh.format);
}

void mesh_define_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_mesh_define, 0);
}

void mesh_1d_cb(CALLBACK_ARGS)
{
  GModel::current()->mesh(1);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_2d_cb(CALLBACK_ARGS)
{
  GModel::current()->mesh(2);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_3d_cb(CALLBACK_ARGS)
{
  GModel::current()->mesh(3);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_delete_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_mesh_delete, 0);
}

void mesh_delete_parts_cb(CALLBACK_ARGS)
{
  const char *str = (const char*)data;
  int what;

  if(!strcmp(str, "elements")){
    CTX.pick_elements = 1;
    what = ENT_ALL;
  }
  else if(!strcmp(str, "lines")){
    CTX.pick_elements = 0;
    what = ENT_LINE;
  }
  else if(!strcmp(str, "surfaces")){
    CTX.pick_elements = 0;
    what = ENT_SURFACE;
  }
  else if(!strcmp(str, "volumes")){
    CTX.pick_elements = 0;
    what = ENT_VOLUME;
  }
  else
    return;

  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;

  std::vector<MElement*> ele;
  std::vector<GEntity*> ent;

  while(1) {
    CTX.mesh.changed = ENT_ALL;
    Draw();

    if(ele.size() || ent.size())
      Msg::StatusBar(3, false, "Select %s\n"
          "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]", str);
    else
      Msg::StatusBar(3, false, "Select %s\n"
          "[Press 'e' to end selection or 'q' to abort]", str);

    char ib = SelectEntity(what, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      if(CTX.pick_elements){
        for(unsigned int i = 0; i < elements.size(); i++){
          if(elements[i]->getVisibility() != 2){
            elements[i]->setVisibility(2); ele.push_back(elements[i]);
          }
        }
      }
      else{
        for(unsigned int i = 0; i < edges.size(); i++){
          if(edges[i]->getSelection() != 1){
            edges[i]->setSelection(1); ent.push_back(edges[i]);
          }
        }
        for(unsigned int i = 0; i < faces.size(); i++){
          if(faces[i]->getSelection() != 1){
            faces[i]->setSelection(1); ent.push_back(faces[i]);
          }
        }
        for(unsigned int i = 0; i < regions.size(); i++){
          if(regions[i]->getSelection() != 1){
            regions[i]->setSelection(1); ent.push_back(regions[i]);
          }
        }
      }
    }
    if(ib == 'r') {
      if(CTX.pick_elements){
        for(unsigned int i = 0; i < elements.size(); i++)
          elements[i]->setVisibility(1);
      }
      else{
        for(unsigned int i = 0; i < edges.size(); i++)
          edges[i]->setSelection(0);
        for(unsigned int i = 0; i < faces.size(); i++)
          faces[i]->setSelection(0);
        for(unsigned int i = 0; i < regions.size(); i++)
          regions[i]->setSelection(0);
      }
    }
    if(ib == 'u') {
      if(CTX.pick_elements){
        if(ele.size()){
          ele[ele.size() - 1]->setVisibility(1);
          ele.pop_back();
        }
      }
      else{
        if(ent.size()){
          ent[ent.size() - 1]->setSelection(0);
          ent.pop_back();
        }
      }
    }
    if(ib == 'e') {
      if(CTX.pick_elements){
        for(unsigned int i = 0; i < ele.size(); i++)
          if(ele[i]->getVisibility() == 2) ele[i]->setVisibility(0);
      }
      else{
        for(unsigned int i = 0; i < ent.size(); i++)
          if(ent[i]->getSelection() == 1) ent[i]->setVisibility(0);
      }
      GModel::current()->removeInvisibleElements();
      ele.clear();
      ent.clear();
    }
    if(ib == 'q') {
      ZeroHighlight();
      break;
    }
  }

  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Draw();  
  Msg::StatusBar(3, false, "");
}

void mesh_update_edges_cb(CALLBACK_ARGS)
{
  Msg::Error("Update edges not implemented yet");
}

void mesh_remesh_cb(CALLBACK_ARGS)
{
  Msg::Error("Remesh not implemented yet");
}

void mesh_inspect_cb(CALLBACK_ARGS)
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;

  CTX.pick_elements = 1;
  CTX.mesh.changed = ENT_ALL;
  Draw();

  while(1) {
    Msg::StatusBar(3, false, "Select element\n[Press 'q' to abort]");
    char ib = SelectEntity(ENT_ALL, vertices, edges, faces, regions, elements);
    if(ib == 'l') {
      if(elements.size()){
        ZeroHighlight();
        elements[0]->setVisibility(2);
        Msg::Direct("Element %d:", elements[0]->getNum());
	int type = elements[0]->getTypeForMSH();
	const char *name;
	MElement::getInfoMSH(type, &name);
        Msg::Direct("  Type: %d ('%s')", type, name); 
        Msg::Direct("  Dimension: %d", elements[0]->getDim());
        Msg::Direct("  Order: %d", elements[0]->getPolynomialOrder()); 
        Msg::Direct("  Partition: %d", elements[0]->getPartition()); 
        char tmp1[32], tmp2[512];
        sprintf(tmp2, "  Vertices:");
        for(int i = 0; i < elements[0]->getNumVertices(); i++){
          sprintf(tmp1, " %d", elements[0]->getVertex(i)->getNum());
          strcat(tmp2, tmp1);
        }
        Msg::Direct(tmp2);
        SPoint3 pt = elements[0]->barycenter();
        Msg::Direct("  Barycenter: (%g,%g,%g)", pt[0], pt[1], pt[2]);
        Msg::Direct("  Rho: %g", elements[0]->rhoShapeMeasure());
        Msg::Direct("  Gamma: %g", elements[0]->gammaShapeMeasure());
        Msg::Direct("  Eta: %g", elements[0]->etaShapeMeasure());
        Msg::Direct("  Disto: %g", elements[0]->distoShapeMeasure());
        CTX.mesh.changed = ENT_ALL;
        Draw();
        GUI::instance()->messages->show();
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      break;
    }
  }

  CTX.pick_elements = 0;
  CTX.mesh.changed = ENT_ALL;
  Draw();
  Msg::StatusBar(3, false, "");
}

void mesh_degree_cb(CALLBACK_ARGS)
{
  if((long)data == 2)
    SetOrderN(GModel::current(), 2, CTX.mesh.second_order_linear, 
              CTX.mesh.second_order_incomplete);
  else
    SetOrder1(GModel::current());
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_optimize_cb(CALLBACK_ARGS)
{
  if(CTX.threads_lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;
  OptimizeMesh(GModel::current());
  CTX.threads_lock = 0;
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_refine_cb(CALLBACK_ARGS)
{
  RefineMesh(GModel::current(), CTX.mesh.second_order_linear);
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_optimize_netgen_cb(CALLBACK_ARGS)
{
  if(CTX.threads_lock) {
    Msg::Info("I'm busy! Ask me that later...");
    return;
  }
  CTX.threads_lock = 1;
  OptimizeMeshNetgen(GModel::current());
  CTX.threads_lock = 0;
  CTX.mesh.changed |= (ENT_LINE | ENT_SURFACE | ENT_VOLUME);
  Draw();
  Msg::StatusBar(2, false, " ");
}

void mesh_partition_cb(CALLBACK_ARGS)
{
  partition_dialog();
}

void mesh_define_length_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(8, 0, "Point");
}

void mesh_define_recombine_cb(CALLBACK_ARGS)
{
  _action_point_line_surface_volume(9, 0, "Surface");
}

void mesh_define_transfinite_cb(CALLBACK_ARGS)
{
  GUI::instance()->menu->setContext(menu_mesh_define_transfinite, 0);
}

static void _add_transfinite(int dim)
{
  std::vector<GVertex*> vertices;
  std::vector<GEdge*> edges;
  std::vector<GFace*> faces;
  std::vector<GRegion*> regions;
  std::vector<MElement*> elements;
  std::vector<int> p;
  char ib;

  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  switch (dim) {
  case 1: opt_geometry_lines(0, GMSH_SET | GMSH_GUI, 1); break;
  case 2: opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI, 1); break;
  case 3: opt_geometry_volumes(0, GMSH_SET | GMSH_GUI, 1); break;
  }
  Draw();

  while(1) {
    switch (dim) {
    case 1:
      if(p.empty())
        Msg::StatusBar(3, false, "Select lines\n"
            "[Press 'e' to end selection or 'q' to abort]");
      else
        Msg::StatusBar(3, false, "Select lines\n"
            "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
      ib = SelectEntity(ENT_LINE, vertices, edges, faces, regions, elements);
      break;
    case 2:
      Msg::StatusBar(3, false, "Select surface\n[Press 'q' to abort]");
      ib = SelectEntity(ENT_SURFACE, vertices, edges, faces, regions, elements);
      break;
    case 3:
      Msg::StatusBar(3, false, "Select volume\n[Press 'q' to abort]");
      ib = SelectEntity(ENT_VOLUME, vertices, edges, faces, regions, elements);
      break;
    default:
      ib = 'l';
      break;
    }

    if(ib == 'e') {
      if(dim == 1) {
        if(p.size())
          add_trsfline(p, CTX.filename,
                       GUI::instance()->meshContext->choice[0]->text(),
                       GUI::instance()->meshContext->input[2]->value(),
                       GUI::instance()->meshContext->input[1]->value());
      }
      ZeroHighlight();
      Draw();
      p.clear();
    }
    if(ib == 'u') {
      if(dim == 1) {
        if(p.size()){
          ZeroHighlightEntityNum(0, p.back(), 0, 0);
          Draw();
          p.pop_back();
        }
      }
    }
    if(ib == 'q') {
      ZeroHighlight();
      Draw();
      break;
    }
    if(ib == 'r') {
      Msg::Warning("Entity de-selection not supported yet during transfinite definition");
    }
    if(ib == 'l') {
      switch (dim) {
      case 1:
        for(unsigned int i = 0; i < edges.size(); i++){
          HighlightEntity(edges[i]);
          p.push_back(edges[i]->tag());
        }
        Draw();
        break;
      case 2:
      case 3:
        if(dim == 2){
          HighlightEntity(faces[0]);
          Draw();
          p.push_back(faces[0]->tag());
        }
        else{
          HighlightEntity(regions[0]);
          Draw();
          p.push_back(regions[0]->tag());
        }
        while(1) {
          if(p.size() == 1)
            Msg::StatusBar(3, false, "Select (ordered) boundary points\n"
                "[Press 'e' to end selection or 'q' to abort]");
          else
            Msg::StatusBar(3, false, "Select (ordered) boundary points\n"
                "[Press 'e' to end selection, 'u' to undo last selection or 'q' to abort]");
          ib = SelectEntity(ENT_POINT, vertices, edges, faces, regions, elements);
          if(ib == 'l') {
            HighlightEntity(vertices[0]);
            Draw();
            p.push_back(vertices[0]->tag());
          }
          if(ib == 'u') {
            if(p.size() > 1){
              ZeroHighlightEntityNum(p.back(), 0, 0, 0);
              Draw();
              p.pop_back();
            }
          }
          if(ib == 'r') {
            Msg::Warning("Entity de-selection not supported yet during transfinite definition");
          }
          if(ib == 'e') {
            switch (dim) {
            case 2:
              if(p.size() == 0 + 1 || p.size() == 3 + 1 || p.size() == 4 + 1)
                add_trsfsurf(p, CTX.filename,
                             GUI::instance()->meshContext->choice[1]->text());
              else
                Msg::Error("Wrong number of points for transfinite surface");
              break;
            case 3:
              if(p.size() == 6 + 1 || p.size() == 8 + 1)
                add_trsfvol(p, CTX.filename);
              else
                Msg::Error("Wrong number of points for transfinite volume");
              break;
            }
            ZeroHighlight();
            Draw();
            p.clear();
            break;
          }
          if(ib == 'q') {
            ZeroHighlight();
            Draw();
            goto stopall;
          }
        }
        break;
      }
    }
  }

stopall:
  Msg::StatusBar(3, false, "");
}

void mesh_define_transfinite_line_cb(CALLBACK_ARGS)
{
  GUI::instance()->meshContext->show(1);
  _add_transfinite(1);
}

void mesh_define_transfinite_surface_cb(CALLBACK_ARGS)
{
  GUI::instance()->meshContext->show(2);
  _add_transfinite(2);
}

void mesh_define_transfinite_volume_cb(CALLBACK_ARGS)
{
  _add_transfinite(3);
}

// Dynamic Solver Menus

void solver_cb(CALLBACK_ARGS)
{
  static int init = 0, first[MAX_NUM_SOLVERS];
  int num = (int)(long)data;

  if(!init) {
    for(int i = 0; i < MAX_NUM_SOLVERS; i++)
      first[i] = 1;
    init = 1;
  }

  if(first[num]) {
    char file[256];
    first[num] = 0;
    strcpy(file, CTX.no_ext_filename);
    strcat(file, SINFO[num].extension);
    GUI::instance()->solver[num]->input[0]->value(file);
  }
  if(SINFO[num].nboptions) {
    std::string file = FixWindowsPath(GUI::instance()->solver[num]->input[0]->value());
    char tmp[256], tmp2[256];
    sprintf(tmp, "\"%s\"", file.c_str());
    sprintf(tmp2, SINFO[num].name_command, tmp);
    sprintf(tmp, "%s %s", SINFO[num].option_command, tmp2);
    Solver(num, tmp);
  }
  GUI::instance()->solver[num]->win->show();
}

void solver_file_open_cb(CALLBACK_ARGS)
{
  char tmp[256], tmp2[256];
  int num = (int)(long)data;
  sprintf(tmp, "*%s", SINFO[num].extension);

  // We allow to create the .pro file... Or should we add a "New file"
  // button?
  if(file_chooser(0, 0, "Choose", tmp)) {
    GUI::instance()->solver[num]->input[0]->value(file_chooser_get_name(1).c_str());
    if(SINFO[num].nboptions) {
      std::string file = FixWindowsPath(file_chooser_get_name(1).c_str());
      sprintf(tmp, "\"%s\"", file.c_str());
      sprintf(tmp2, SINFO[num].name_command, tmp);
      sprintf(tmp, "%s %s", SINFO[num].option_command, tmp2);
      Solver(num, tmp);
    }
  }
}

void solver_file_edit_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  std::string prog = FixWindowsPath(CTX.editor);
  std::string file = FixWindowsPath(GUI::instance()->solver[num]->input[0]->value());
  char cmd[1024];
  _replace_multi_format(prog.c_str(), file.c_str(), cmd);
  SystemCall(cmd);
}

void solver_choose_mesh_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose", "*"))
    GUI::instance()->solver[num]->input[1]->value(file_chooser_get_name(1).c_str());
}

int nbs(char *str)
{
  int i, nb = 0;
  for(i = 0; i < (int)strlen(str) - 1; i++) {
    if(str[i] == '%' && str[i + 1] == 's') {
      nb++;
      i++;
    }
  }
  return nb;
}

void solver_command_cb(CALLBACK_ARGS)
{
  char tmp[256], mesh[256], arg[512], command[256];
  int num = ((int *)data)[0];
  int idx = ((int *)data)[1];
  int i, usedopts = 0;

  if(SINFO[num].popup_messages)
    GUI::instance()->messages->show(true);

  if(strlen(GUI::instance()->solver[num]->input[1]->value())) {
    std::string m = FixWindowsPath(GUI::instance()->solver[num]->input[1]->value());
    sprintf(tmp, "\"%s\"", m.c_str());
    sprintf(mesh, SINFO[num].mesh_command, tmp);
  }
  else {
    strcpy(mesh, "");
  }

  if(nbs(SINFO[num].button_command[idx])) {
    for(i = 0; i < idx; i++)
      usedopts += nbs(SINFO[num].button_command[i]);
    if(usedopts > SINFO[num].nboptions) {
      Msg::Error("Missing options to execute command");
      return;
    }
    sprintf(command, SINFO[num].button_command[idx],
            SINFO[num].option[usedopts][GUI::instance()->solver[num]->choice[usedopts]->value()]);
  }
  else {
    strcpy(command, SINFO[num].button_command[idx]);
  }

  std::string c = FixWindowsPath(GUI::instance()->solver[num]->input[0]->value());
  sprintf(arg, "\"%s\"", c.c_str());
  sprintf(tmp, SINFO[num].name_command, arg);
  sprintf(arg, "%s %s %s", tmp, mesh, command);
  Solver(num, arg);
}

void solver_kill_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  if(SINFO[num].pid > 0) {
    if(KillProcess(SINFO[num].pid))
      Msg::Info("Killed %s pid %d", SINFO[num].name, SINFO[num].pid);
  }
  SINFO[num].pid = -1;
}

void solver_choose_executable_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  if(file_chooser(0, 0, "Choose",
#if defined(WIN32)
                  "*.exe"
#else
                  "*"
#endif
                  )){
    GUI::instance()->solver[num]->input[2]->value(file_chooser_get_name(1).c_str());
    solver_ok_cb(w, data);
  }
}

void solver_ok_cb(CALLBACK_ARGS)
{
  int retry = 0, num = (int)(long)data;
  opt_solver_popup_messages(num, GMSH_SET, GUI::instance()->solver[num]->butt[0]->value());
  opt_solver_merge_views(num, GMSH_SET, GUI::instance()->solver[num]->butt[1]->value());
  opt_solver_client_server(num, GMSH_SET, GUI::instance()->solver[num]->butt[2]->value());
  if(strcmp(opt_solver_executable(num, GMSH_GET, NULL), GUI::instance()->solver[num]->input[2]->value()))
    retry = 1;
  opt_solver_executable(num, GMSH_SET, GUI::instance()->solver[num]->input[2]->value());
  if(retry)
    solver_cb(NULL, data);
}

// Dynamic Post Menus

void view_toggle_cb(CALLBACK_ARGS)
{
  int num = (int)(long)data;
  opt_view_visible(num, GMSH_SET,
                   GUI::instance()->menu->toggle[num]->value());
  Draw();
}

static void _view_reload(int index)
{
  if(index >= 0 && index < (int)PView::list.size()){
    PView *p = PView::list[index];

    if(StatFile(p->getData()->getFileName().c_str())){
      Msg::Error("File '%s' does not exist", p->getData()->getFileName().c_str());
      return;
    }

    int n = PView::list.size();

    // FIXME: use fileIndex
    MergeFile(p->getData()->getFileName().c_str());

    if((int)PView::list.size() > n){ // we loaded a new view
      // delete old data and replace with new
      delete p->getData();
      p->setData(PView::list.back()->getData());
      PView::list.back()->setData(0);
      // delete new view
      delete PView::list.back();
      // in case the reloaded view has a different number of time steps
      if(p->getOptions()->TimeStep > p->getData()->getNumTimeSteps() - 1)
        p->getOptions()->TimeStep = 0;
      p->setChanged(true);
      GUI::instance()->updateViews();
    }
  }
}

void view_reload_cb(CALLBACK_ARGS)
{
  _view_reload((int)(long)data);
  Draw();
}

void view_reload_all_cb(CALLBACK_ARGS)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    _view_reload(i);
  Draw();
}

void view_reload_visible_cb(CALLBACK_ARGS)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    if(opt_view_visible(i, GMSH_GET, 0))
      _view_reload(i);
  Draw();
}

void view_remove_other_cb(CALLBACK_ARGS)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(i != (long)data) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

void view_remove_all_cb(CALLBACK_ARGS)
{
  if(PView::list.empty()) return;
  while(PView::list.size()) delete PView::list[0];
  GUI::instance()->updateViews();
  Draw();
}

void view_remove_visible_cb(CALLBACK_ARGS)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

void view_remove_invisible_cb(CALLBACK_ARGS)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(!opt_view_visible(i, GMSH_GET, 0)) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

void view_remove_empty_cb(CALLBACK_ARGS)
{
  if(PView::list.empty()) return;
  for(int i = PView::list.size() - 1; i >= 0; i--)
    if(PView::list[i]->getData()->empty()) delete PView::list[i];
  GUI::instance()->updateViews();
  Draw();
}

void view_remove_cb(CALLBACK_ARGS)
{
  delete PView::list[(int)(long)data];
  GUI::instance()->updateViews();
  Draw();
}

static void _view_save_as(int index, const char *title, int format)
{
  PView *view = PView::list[index];
  
 test:
  if(file_chooser(0, 1, title, "*", view->getData()->getFileName().c_str())){
    std::string name = file_chooser_get_name(1);
    if(CTX.confirm_overwrite) {
      if(!StatFile(name.c_str()))
        if(!fl_choice("File '%s' already exists.\n\nDo you want to replace it?",
                      "Cancel", "Replace", NULL, name.c_str()))
          goto test;
    }
    view->write(name.c_str(), format);
  }
}

void view_save_ascii_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As ASCII View", 0);
}

void view_save_binary_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Binary View", 1);
}

void view_save_parsed_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Parsed View", 2);
}

void view_save_stl_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As STL Triangulation", 3);
}

void view_save_txt_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Raw Text", 4);
}

void view_save_msh_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As Gmsh Mesh", 5);
}

void view_save_med_cb(CALLBACK_ARGS)
{
  _view_save_as((int)(long)data, "Save As MED file", 6);
}

void view_alias_cb(CALLBACK_ARGS)
{
  new PView(PView::list[(int)(long)data], false);
  GUI::instance()->updateViews();
  Draw();
}

void view_alias_with_options_cb(CALLBACK_ARGS)
{
  new PView(PView::list[(int)(long)data], true);
  GUI::instance()->updateViews();
  Draw();
}

void view_combine_space_all_cb(CALLBACK_ARGS)
{
  PView::combine(false, 1, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

void view_combine_space_visible_cb(CALLBACK_ARGS)
{
  PView::combine(false, 0, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

void view_combine_space_by_name_cb(CALLBACK_ARGS)
{
  PView::combine(false, 2, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

void view_combine_time_all_cb(CALLBACK_ARGS)
{
  PView::combine(true, 1, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

void view_combine_time_visible_cb(CALLBACK_ARGS)
{
  PView::combine(true, 0, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

void view_combine_time_by_name_cb(CALLBACK_ARGS)
{
  PView::combine(true, 2, CTX.post.combine_remove_orig);
  GUI::instance()->updateViews();
  Draw();
}

void view_all_visible_cb(CALLBACK_ARGS)
{
  for(unsigned int i = 0; i < PView::list.size(); i++)
    opt_view_visible(i, GMSH_SET | GMSH_GUI, 
                     (long)data < 0 ? !opt_view_visible(i, GMSH_GET, 0) :
                     (long)data > 0 ? 1 : 0);
  Draw();
}

void view_applybgmesh_cb(CALLBACK_ARGS)
{
  int index =  (int)(long)data;
  if(index >= 0 && index < (int)PView::list.size()){
    GModel::current()->getFields()->set_background_mesh(index);
  }
}

void view_plugin_cb(CALLBACK_ARGS)
{
  GUI::instance()->plugins->show((int)(long)data);
}

void view_field_cb(CALLBACK_ARGS)
{
  GUI::instance()->fields->win->show();
  GUI::instance()->fields->editField(NULL);
}

void view_field_delete_cb(CALLBACK_ARGS)
{
  Field *f = (Field*)GUI::instance()->fields->editor_group->user_data();
  delete_field(f->id, CTX.filename);
  GUI::instance()->fields->editField(NULL);
}

void view_field_new_cb(CALLBACK_ARGS)
{
  Fl_Menu_Button* mb = ((Fl_Menu_Button*)w);
  FieldManager *fields = GModel::current()->getFields();
  int id = fields->new_id();
  add_field(id, mb->text(), CTX.filename);
  GUI::instance()->fields->editField((*fields)[id]);
}

void view_field_apply_cb(CALLBACK_ARGS)
{
  GUI::instance()->fields->saveFieldOptions();
}

void view_field_revert_cb(CALLBACK_ARGS)
{
  GUI::instance()->fields->loadFieldOptions();
}

void view_field_browser_cb(CALLBACK_ARGS)
{
  int selected = GUI::instance()->fields->browser->value();
  if(!selected){
    GUI::instance()->fields->editField(NULL);
  }
  Field *f = (Field*)GUI::instance()->fields->browser->data(selected);
  GUI::instance()->fields->editField(f);
}

void view_field_put_on_view_cb(CALLBACK_ARGS)
{
  Fl_Menu_Button* mb = ((Fl_Menu_Button*)w);
  Field *field = (Field*)GUI::instance()->fields->editor_group->user_data();
  int iView;
  if(sscanf(mb->text(), "View [%i]", &iView)){
    if(iView < (int)PView::list.size()){
      field->put_on_view(PView::list[iView]);
    }
  }
  else{
    field->put_on_new_view();
    GUI::instance()->updateViews();
  }
  Draw();
}

void view_field_select_file_cb(CALLBACK_ARGS)
{
  Fl_Input *input = (Fl_Input*)data;
  int ret = file_chooser(0, 0, "File selection", "", input->value());
  if(ret){
    input->value(file_chooser_get_name(0).c_str());
    input->set_changed();
  }
}

void view_field_select_node_cb(CALLBACK_ARGS)
{
  const char *mode = "select";
  const char *help = "vertices";
  CTX.pick_elements = 1;
  Draw();  
  std::vector<GVertex*> vertices, vertices_old;
  std::vector<GEdge*> edges, edges_old;
  std::vector<GFace*> faces, faces_old;
  std::vector<GRegion*> regions, regions_old;
  std::vector<MElement*> elements, elements_old;
  opt_geometry_points(0, GMSH_SET | GMSH_GUI, 1);
  while(1) {
    Msg::StatusBar(3, false, "Select %s\n[Press %s'q' to abort]", 
        help, mode ? "" : "'u' to undo or ");
    
    char ib = SelectEntity(ENT_POINT, vertices, edges, faces, regions, elements);
    printf("char = %c\n", ib);
    if(ib == 'q'){
      for(std::vector<GVertex*>::iterator it = vertices.begin(); it != vertices.end(); it++){
	printf("%p\n", *it);
      }
      break;
    }
  }
  CTX.mesh.changed = ENT_ALL;
  CTX.pick_elements = 0;
  Msg::StatusBar(3, false, "");
  Draw();  
}

void view_plugin_input_value_cb(CALLBACK_ARGS)
{
  double (*f)(int, int, double) = (double (*)(int, int, double)) data;
  Fl_Value_Input *input = (Fl_Value_Input*) w;
  f(-1, 0, input->value());
}

void view_plugin_input_cb(CALLBACK_ARGS)
{
  const char* (*f)(int, int, const char*) = (const char* (*)(int, int, const char*)) data;
  Fl_Input *input = (Fl_Input*) w;
  f(-1, 0, input->value());
}

void view_plugin_browser_cb(CALLBACK_ARGS)
{
  // get selected plugin
  GMSH_Plugin *p = 0;
  for(int i = 1; i <= GUI::instance()->plugins->browser->size(); i++) {
    if(GUI::instance()->plugins->browser->selected(i)) {
      p = (GMSH_Plugin*)GUI::instance()->plugins->browser->data(i);
      break;
    }
  }
  if(!p) return;

  // get first first selected view
  int iView = -1;
  for(int i = 1; i <= GUI::instance()->plugins->view_browser->size(); i++) {
    if(GUI::instance()->plugins->view_browser->selected(i)) {
      iView = i - 1;
      break;
    }
  }

  // set the Fl_Value_Input callbacks and configure the input value
  // fields (we get step, min and max by calling the option function
  // with action==1, 2 and 3, respectively)
  int n = p->getNbOptions();
  if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;
  for(int i = 0; i < n; i++) {
    StringXNumber *sxn = p->getOption(i);
    if(sxn->function){
      p->dialogBox->value[i]->callback(view_plugin_input_value_cb, (void*)sxn->function);
      if(iView >= 0){
        p->dialogBox->value[i]->step(sxn->function(iView, 1, 0.));
        p->dialogBox->value[i]->minimum(sxn->function(iView, 2, 0.));
        p->dialogBox->value[i]->maximum(sxn->function(iView, 3, 0.));
      }
    }
  }

  // set the Fl_Input callbacks
  int m = p->getNbOptionsStr();
  if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;
  for(int i = 0; i < m; i++) {
    StringXString *sxs = p->getOptionStr(i);
    if(sxs->function){
      p->dialogBox->input[i]->callback(view_plugin_input_cb, (void*)sxs->function);
    }
  }

  // hide all plugin groups except the selected one
  for(int i = 1; i <= GUI::instance()->plugins->browser->size(); i++)
    ((GMSH_Plugin*)GUI::instance()->plugins->browser->data(i))->dialogBox->group->hide();
  p->dialogBox->group->show();
}

void view_plugin_run_cb(CALLBACK_ARGS)
{
  // get selected plugin
  GMSH_Post_Plugin *p = 0;
  for(int i = 1; i <= GUI::instance()->plugins->browser->size(); i++) {
    if(GUI::instance()->plugins->browser->selected(i)) {
      p = (GMSH_Post_Plugin*)GUI::instance()->plugins->browser->data(i);
      break;
    }
  }
  if(!p) return;

  if(p->dialogBox) { // get the values from the GUI
    int m = p->getNbOptionsStr();
    int n = p->getNbOptions();
    if(m > MAX_PLUGIN_OPTIONS) m = MAX_PLUGIN_OPTIONS;
    if(n > MAX_PLUGIN_OPTIONS) n = MAX_PLUGIN_OPTIONS;
    for(int i = 0; i < m; i++) {
      StringXString *sxs = p->getOptionStr(i);
      sxs->def = p->dialogBox->input[i]->value();
    }
    for(int i = 0; i < n; i++) {
      StringXNumber *sxn = p->getOption(i);
      sxn->def = p->dialogBox->value[i]->value();
    }
  }

  // run on all selected views
  bool no_view_selected = true;
  for(int i = 1; i <= GUI::instance()->plugins->view_browser->size(); i++) {
    if(GUI::instance()->plugins->view_browser->selected(i)) {
      no_view_selected = false;
      try{
        if(i - 1 >= 0 && i - 1 < (int)PView::list.size())
          p->execute(PView::list[i - 1]);
        else
          p->execute(0);
      }
      catch(GMSH_Plugin * err) {
        char tmp[256];
        p->catchErrorMessage(tmp);
        Msg::Warning("%s", tmp);
      }
    }
  }
  if(no_view_selected){
    p->execute(0);
  }

  GUI::instance()->updateViews();
  CTX.post.plugin_draw_function = NULL;
  Draw();
}

void view_plugin_cancel_cb(CALLBACK_ARGS)
{
  GUI::instance()->plugins->win->hide();
  CTX.post.plugin_draw_function = NULL;
  Draw();
}

// Contextual windows for geometry

void con_geometry_define_parameter_cb(CALLBACK_ARGS)
{
  add_param(GUI::instance()->geoContext->input[0]->value(),
            GUI::instance()->geoContext->input[1]->value(), CTX.filename);
  GUI::instance()->resetVisibility();
}

void con_geometry_define_point_cb(CALLBACK_ARGS)
{
  add_point(CTX.filename,
            GUI::instance()->geoContext->input[2]->value(),
            GUI::instance()->geoContext->input[3]->value(),
            GUI::instance()->geoContext->input[4]->value(),
            GUI::instance()->geoContext->input[5]->value());
  GUI::instance()->resetVisibility();
  ZeroHighlight();
  SetBoundingBox();
  Draw();
}

void con_geometry_snap_cb(CALLBACK_ARGS)
{
  CTX.geom.snap[0] = GUI::instance()->geoContext->value[0]->value();
  CTX.geom.snap[1] = GUI::instance()->geoContext->value[1]->value();
  CTX.geom.snap[2] = GUI::instance()->geoContext->value[2]->value();
}
