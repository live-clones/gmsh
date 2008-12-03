// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/Fl.H>
#include <FL/Fl_Tooltip.H>
#include <FL/Fl_Shared_Image.H>
#include <FL/Fl_File_Icon.H>
#include <FL/x.H>
#include "GUI.h"
#include "graphicWindow.h"
#include "menuWindow.h"
#include "optionWindow.h"
#include "fieldWindow.h"
#include "pluginWindow.h"
#include "statisticsWindow.h"
#include "visibilityWindow.h"
#include "clippingWindow.h"
#include "messageWindow.h"
#include "manipWindow.h"
#include "contextWindow.h"
#include "solverWindow.h"
#include "aboutWindow.h"
#include "colorbarWindow.h"
#include "fileDialogs.h"
#include "Draw.h"
#include "GmshDefines.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "MElement.h"
#include "PView.h"
#include "Solvers.h"
#include "Field.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "OpenFile.h"
#include "Win32Icon.h"
#include "Options.h"
#include "Context.h"

extern Context_T CTX;

static int globalShortcut(int event)
{
  if(!GUI::available()) return 0;
  return GUI::instance()->testGlobalShortcuts(event);
}

GUI::GUI(int argc, char **argv)
{
  // set X display
  if(strlen(CTX.display))
    Fl::display(CTX.display);

  // add global shortcuts
  Fl::add_handler(globalShortcut);

  // store fontsize now: we don't want any subsequent change
  // (e.g. when doing a 'restore options') to be taken into account
  // in the dynamic GUI features
  _fontsize = GetFontSize();

  // set default font size
  FL_NORMAL_SIZE = _fontsize;

  // handle themes and tooltip font size
  if(strlen(CTX.gui_theme))
    Fl::scheme(CTX.gui_theme);
  Fl_Tooltip::size(_fontsize);

  // register image formats not in core fltk library (jpeg/png)
  fl_register_images();

  // load default system icons (for file browser)
  Fl_File_Icon::load_system_icons();
  
  // add callback to respond to the Mac Finder (when you click on a
  // document)
#if defined(__APPLE__)
  fl_open_callback(OpenProjectMacFinder);
#endif

  // all the windows are contructed (even if some are not displayed)
  // since the shortcuts should be valid even for hidden windows, and
  // we don't want to test for widget existence every time
  menu = new menuWindow(_fontsize);
  graph.push_back(new graphicWindow(_fontsize));

#if defined(WIN32)
  graph[0]->win->icon
    ((const char*)LoadImage(fl_display, MAKEINTRESOURCE(IDI_ICON),
                            IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR));
#elif defined(__APPLE__)
  // nothing to do here
#else
  fl_open_display();
  static char gmsh32x32[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x01, 0x00, 0x00, 0x40, 0x03, 0x00,
    0x00, 0x40, 0x03, 0x00, 0x00, 0x20, 0x07, 0x00, 0x00, 0x20, 0x07, 0x00,
    0x00, 0x10, 0x0f, 0x00, 0x00, 0x10, 0x0f, 0x00, 0x00, 0x08, 0x1f, 0x00,
    0x00, 0x08, 0x1f, 0x00, 0x00, 0x04, 0x3f, 0x00, 0x00, 0x04, 0x3f, 0x00,
    0x00, 0x02, 0x7f, 0x00, 0x00, 0x02, 0x7f, 0x00, 0x00, 0x01, 0xff, 0x00,
    0x00, 0x01, 0xff, 0x00, 0x80, 0x00, 0xff, 0x01, 0x80, 0x00, 0xff, 0x01,
    0x40, 0x00, 0xff, 0x03, 0x40, 0x00, 0xff, 0x03, 0x20, 0x00, 0xff, 0x07,
    0x20, 0x00, 0xff, 0x07, 0x10, 0x00, 0xff, 0x0f, 0x10, 0x00, 0xff, 0x0f,
    0x08, 0x00, 0xff, 0x1f, 0x08, 0x00, 0xff, 0x1f, 0x04, 0x40, 0xfd, 0x3f,
    0x04, 0xa8, 0xea, 0x3f, 0x02, 0x55, 0x55, 0x7f, 0xa2, 0xaa, 0xaa, 0x7a,
    0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00};
  graph[0]->win->icon
    ((const char*)XCreateBitmapFromData(fl_display, DefaultRootWindow(fl_display),
                                        gmsh32x32, 32, 32));
  menu->win->icon
    ((const char*)XCreateBitmapFromData(fl_display, DefaultRootWindow(fl_display),
                                        gmsh32x32, 32, 32));
#endif

  // open graphic window first for correct non-modal behaviour on
  // Win32
  graph[0]->win->show(1, argv);
  menu->win->show();

  // graphic window should have the initial focus (so we can
  // e.g. directly loop through time steps with the keyboard)
  graph[0]->gl->take_focus();

  // test: create another graphic window with a coordinate transform
  //graph.push_back(new graphicWindow(_fontsize));
  //drawTransform *tr = new drawTransformScaled(2,0,0, 0,1,0, 0,0,1);
  //graph.back()->gl->getDrawContext()->setTransform(tr);
  //graph.back()->win->show();

  options = new optionWindow(_fontsize);
  fields = new fieldWindow(_fontsize);
  plugins = new pluginWindow(_fontsize);
  stats = new statisticsWindow(_fontsize);
  visibility = new visibilityWindow(_fontsize);
  clipping = new clippingWindow(_fontsize);
  messages = new messageWindow(_fontsize);
  manip = new manipWindow(_fontsize);
  geoContext = new geometryContextWindow(_fontsize);
  meshContext = new meshContextWindow(_fontsize);
  about = new aboutWindow(_fontsize);
  for(int i = 0; i < MAX_NUM_SOLVERS; i++)
    solver.push_back(new solverWindow(i, _fontsize));

  // init solver plugin stuff
  callForSolverPlugin(-1);

  // draw the scene
  for(unsigned int i = 0; i < graph.size(); i++)
    graph[i]->gl->redraw();
}

GUI *GUI::_instance = 0;

GUI *GUI::instance(int argc, char **argv)
{
  if(!_instance) _instance = new GUI(argc, argv);
  return _instance;
}

int GUI::testGlobalShortcuts(int event)
{
  // we only handle shortcuts here
  if(event != FL_SHORTCUT) return 0;

  int status = 0;

  if(Fl::test_shortcut('0')) {
    geometry_reload_cb(0, 0);
    mod_geometry_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('1') || Fl::test_shortcut(FL_F + 1)) {
    mesh_1d_cb(0, 0);
    mod_mesh_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('2') || Fl::test_shortcut(FL_F + 2)) {
    mesh_2d_cb(0, 0);
    mod_mesh_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('3') || Fl::test_shortcut(FL_F + 3)) {
    mesh_3d_cb(0, 0);
    mod_mesh_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_CTRL + 'q') || Fl::test_shortcut(FL_META + 'q')){
    // only necessary when using the system menu bar, but hey, it
    // cannot hurt...
    file_quit_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('g')) {
    mod_geometry_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('m')) {
    mod_mesh_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('s')) {
    mod_solver_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('p')) {
    mod_post_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('<')) {
    mod_back_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('>')) {
    mod_forward_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut('e')) {
    for(unsigned int i = 0; i < graph.size(); i++)
      graph[i]->gl->endSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('u')) {
    for(unsigned int i = 0; i < graph.size(); i++)
      graph[i]->gl->undoSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('i')) {
    for(unsigned int i = 0; i < graph.size(); i++)
      graph[i]->gl->invertSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('q')) {
    for(unsigned int i = 0; i < graph.size(); i++)
      graph[i]->gl->quitSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut('-')) {
    for(unsigned int i = 0; i < graph.size(); i++)
      graph[i]->gl->invertSelection = 1;
    status = 0; // trick: do as if we didn't use it
  }
  else if(Fl::test_shortcut(FL_Escape) ||
          Fl::test_shortcut(FL_META + FL_Escape) ||
          Fl::test_shortcut(FL_SHIFT + FL_Escape) ||
          Fl::test_shortcut(FL_CTRL + FL_Escape) ||
          Fl::test_shortcut(FL_ALT + FL_Escape)) {
    bool lasso = false;
    for(unsigned int i = 0; i < graph.size(); i++)
      if(graph[i]->gl->lassoMode) lasso = true;
    if(lasso){
      for(unsigned int i = 0; i < graph.size(); i++)
        graph[i]->gl->lassoMode = false;
      status = 2;
    }
    else{
      status_xyz1p_cb(0, (void *)"S");
      status = 1;
    }
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'a')) { 
    window_cb(0, (void*)"front");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'o')) {
    general_options_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'g')) {
    geometry_options_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'm')) {
    mesh_options_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 's')) {
    solver_options_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'p')) {
    post_options_cb(0, 0);
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'w')) {
    if(PView::list.size()){
      if(options->view.index >= 0 && options->view.index < (int)PView::list.size())
        options->showGroup(options->view.index + 6);
      else
        options->showGroup(6);
    }
    status = 1;
  }
  else if(Fl::test_shortcut(FL_SHIFT + 'u')) {
    if(PView::list.size()){
      if(options->view.index >= 0 && options->view.index < (int)PView::list.size())
        plugins->show(options->view.index);
      else
        plugins->show(0);
    }
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'f')) {
    opt_general_fast_redraw(0, GMSH_SET | GMSH_GUI,
                            !opt_general_fast_redraw(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'b')) {
    opt_general_draw_bounding_box(0, GMSH_SET | GMSH_GUI,
                                  !opt_general_draw_bounding_box(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'i')) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_scale(i, GMSH_SET | GMSH_GUI,
                            !opt_view_show_scale(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'c')) {
    opt_general_color_scheme(0, GMSH_SET | GMSH_GUI,
                             opt_general_color_scheme(0, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'w')) {
    opt_geometry_light(0, GMSH_SET | GMSH_GUI,
                       !opt_geometry_light(0, GMSH_GET, 0));
    opt_mesh_light(0, GMSH_SET | GMSH_GUI,
                   !opt_mesh_light(0, GMSH_GET, 0));
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_light(i, GMSH_SET | GMSH_GUI,
                       !opt_view_light(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'w')) {
    opt_mesh_reverse_all_normals(0, GMSH_SET | GMSH_GUI,
                                 !opt_mesh_reverse_all_normals(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'x') || 
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'x')) {
    status_xyz1p_cb(0, (void *)"x");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'y') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'y')) {
    status_xyz1p_cb(0, (void *)"y");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'z') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'z')) {
    status_xyz1p_cb(0, (void *)"z");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'o') ||
          Fl::test_shortcut(FL_ALT + FL_SHIFT + 'o')) {
    status_xyz1p_cb(0, (void *)"p");
    status = 1;
  }
  else if(Fl::test_shortcut(FL_ALT + 'a')) {
    opt_general_axes(0, GMSH_SET | GMSH_GUI, 
                     opt_general_axes(0, GMSH_GET, 0) + 1);
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_axes(i, GMSH_SET | GMSH_GUI, opt_view_axes(i, GMSH_GET, 0)+1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'a')) {
    opt_general_small_axes(0, GMSH_SET | GMSH_GUI,
                           !opt_general_small_axes(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'p')) {
    opt_geometry_points(0, GMSH_SET | GMSH_GUI,
                        !opt_geometry_points(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'l')) {
    opt_geometry_lines(0, GMSH_SET | GMSH_GUI,
                       !opt_geometry_lines(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 's')) {
    opt_geometry_surfaces(0, GMSH_SET | GMSH_GUI,
                          !opt_geometry_surfaces(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'v')) {
    opt_geometry_volumes(0, GMSH_SET | GMSH_GUI,
                         !opt_geometry_volumes(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'p')) {
    opt_mesh_points(0, GMSH_SET | GMSH_GUI, !opt_mesh_points(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'l')) {
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 
                   !opt_mesh_lines(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 's')) {
    opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI,
                            !opt_mesh_surfaces_edges(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'v')) {
    opt_mesh_volumes_edges(0, GMSH_SET | GMSH_GUI,
                           !opt_mesh_volumes_edges(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'd')){
    opt_geometry_surface_type(0, GMSH_SET | GMSH_GUI,
                              opt_geometry_surface_type(0, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'd')) {
    opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI,
                            !opt_mesh_surfaces_faces(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + FL_SHIFT + 'b')) {
    opt_mesh_volumes_faces(0, GMSH_SET | GMSH_GUI,
                           !opt_mesh_volumes_faces(0, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'm')) {
    int old = opt_mesh_points(0, GMSH_GET, 0) || 
      opt_mesh_lines(0, GMSH_GET, 0) ||
      opt_mesh_surfaces_edges(0, GMSH_GET, 0) ||
      opt_mesh_surfaces_faces(0, GMSH_GET, 0);
    opt_mesh_points(0, GMSH_SET | GMSH_GUI, !old);
    opt_mesh_lines(0, GMSH_SET | GMSH_GUI, !old);
    opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, !old);
    opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, !old);
    opt_mesh_volumes_edges(0, GMSH_SET | GMSH_GUI, !old);
    opt_mesh_volumes_faces(0, GMSH_SET | GMSH_GUI, !old);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 't')) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0)){
	double t = opt_view_intervals_type(i, GMSH_GET, 0) + 1;
	if(t == 4) t++; // skip numeric
        opt_view_intervals_type(i, GMSH_SET | GMSH_GUI, t);
      }
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'r')) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_range_type(i, GMSH_SET | GMSH_GUI,
                            opt_view_range_type(i, GMSH_GET, 0) + 1);
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'n')) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_draw_strings(i, GMSH_SET | GMSH_GUI,
                              !opt_view_draw_strings(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'e')) {
    for(unsigned int i = 0; i < PView::list.size(); i++)
      if(opt_view_visible(i, GMSH_GET, 0))
        opt_view_show_element(i, GMSH_SET | GMSH_GUI,
                              !opt_view_show_element(i, GMSH_GET, 0));
    status = 2;
  }
  else if(Fl::test_shortcut(FL_ALT + 'h')) {
    static int show = 0;
    for(unsigned int i = 0; i < PView::list.size(); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, show);
    show = !show;
    status = 2;
  }
  else if(testArrowShortcuts()) {
    status = 1;
  }
  
  if(status == 2){
    Draw();
    return 1;
  }
  else if(status == 1)
    return 1;
  else
    return 0;
}

int GUI::testArrowShortcuts()
{
  if(Fl::test_shortcut(FL_Left)) {
    status_play_manual(1, -1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Right)) {
    status_play_manual(1, 1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Up)) {
    status_play_manual(0, -1);
    return 1;
  }
  else if(Fl::test_shortcut(FL_Down)) {
    status_play_manual(0, 1);
    return 1;
  }
  return 0;
}

void GUI::setGraphicSize(int w, int h)
{
  graph[0]->win->size(w, h + graph[0]->win->h() - graph[0]->gl->h());
}

void GUI::setGraphicTitle(const char *str)
{
  // FIXME should use copy_label, but it is broken for Fl_Windows in
  // fltk 1.1.7
  for(unsigned int i = 0; i < graph.size(); i++)
    graph[i]->win->label(str);
}

void GUI::updateViews()
{
  for(unsigned int i = 0; i < graph.size(); i++)
    graph[i]->checkAnimButtons();
  if(menu->module->value() == 3)
    menu->setContext(menu_post, 0);
  options->resetBrowser();
  options->resetExternalViewList();
  fields->loadFieldViewList();
  plugins->resetViewBrowser();
  clipping->resetBrowser();
}

void GUI::updateFields()
{
  fields->editField(GModel::current()->getFields()->get(fields->selected_id));
}

void GUI::resetVisibility()
{
  visibility->browser->clear();
  if(visibility->win->shown())
    visibility_cb(NULL, NULL);
}

int GUI::getLastGraphIndex()
{
  unsigned int index = 0;
  if(graph.size() > 1)
    for(Fl_Window *w = Fl::first_window(); w; w = Fl::next_window(w))
      for(index = 0; index < GUI::instance()->graph.size(); index++)
        if(w == graph[index]->win || w == graph[index]->gl)
          return index;
  return 0;
}

char GUI::selectEntity(int type)
{
  return graph[getLastGraphIndex()]->gl->selectEntity
    (type, selectedVertices, selectedEdges, selectedFaces, selectedRegions,
     selectedElements);
}

void GUI::setStatus(const char *msg, int num)
{
  if(num == 0 || num == 1){
    static char buff[2][1024];
    strncpy(buff[num], msg, sizeof(buff[num]) - 1);
    buff[num][sizeof(buff[num]) - 1] = '\0';
    for(unsigned int i = 0; i < graph.size(); i++){
      graph[i]->label[num]->label(buff[num]);
      graph[i]->label[num]->redraw();
    }
  }
  else if(num == 2){
    int index = getLastGraphIndex();
    int n = strlen(msg);
    int i = 0;
    while(i < n) if(msg[i++] == '\n') break;
    graph[index]->gl->screenMessage[0] = std::string(msg);
    if(i)
      graph[index]->gl->screenMessage[0].resize(i - 1);
    if(i < n) 
      graph[index]->gl->screenMessage[1] = std::string(&msg[i]);
    else
      graph[index]->gl->screenMessage[1].clear();
    Draw();
  }
}

void GUI::storeCurrentWindowsInfo()
{
  CTX.position[0] = menu->win->x();
  CTX.position[1] = menu->win->y();
  CTX.gl_position[0] = graph[0]->win->x();
  CTX.gl_position[1] = graph[0]->win->y();
  CTX.msg_position[0] = messages->win->x();
  CTX.msg_position[1] = messages->win->y();
  CTX.msg_size[0] = messages->win->w();
  CTX.msg_size[1] = messages->win->h();
  CTX.opt_position[0] = options->win->x();
  CTX.opt_position[1] = options->win->y();
  CTX.plugin_position[0] = plugins->win->x();
  CTX.plugin_position[1] = plugins->win->y();
  CTX.plugin_size[0] = plugins->win->w();
  CTX.plugin_size[1] = plugins->win->h();
  CTX.field_position[0] = fields->win->x();
  CTX.field_position[1] = fields->win->y();
  CTX.field_size[0] = fields->win->w();
  CTX.field_size[1] = fields->win->h();
  CTX.stat_position[0] = stats->win->x();
  CTX.stat_position[1] = stats->win->y();
  CTX.vis_position[0] = visibility->win->x();
  CTX.vis_position[1] = visibility->win->y();
  CTX.clip_position[0] = clipping->win->x();
  CTX.clip_position[1] = clipping->win->y();
  CTX.manip_position[0] = manip->win->x();
  CTX.manip_position[1] = manip->win->y();
  CTX.ctx_position[0] = geoContext->win->x();
  CTX.ctx_position[1] = meshContext->win->y();
  CTX.solver_position[0] = solver[0]->win->x();
  CTX.solver_position[1] = solver[0]->win->y();
  file_chooser_get_position(&CTX.file_chooser_position[0],
                            &CTX.file_chooser_position[1]);
}

void GUI::callForSolverPlugin(int dim)
{ 
  GMSH_Solve_Plugin *sp = GMSH_PluginManager::instance()->findSolverPlugin();   
  if(sp) sp->popupPropertiesForPhysicalEntity(dim);
}

// Callbacks

void hide_cb(Fl_Widget *w, void *data)
{
  if(data) ((Fl_Window*)data)->hide();
}

void redraw_cb(Fl_Widget *w, void *data)
{
  Draw();
}

void window_cb(Fl_Widget *w, void *data)
{
  static int oldx = 0, oldy = 0, oldw = 0, oldh = 0, zoom = 1;
  const char *str = (const char*)data;

  if(!strcmp(str, "minimize")){
    for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++)
      GUI::instance()->graph[i]->win->iconize();
    GUI::instance()->options->win->iconize();
    GUI::instance()->plugins->win->iconize();
    GUI::instance()->fields->win->iconize();
    GUI::instance()->visibility->win->iconize();
    GUI::instance()->clipping->win->iconize();
    GUI::instance()->manip->win->iconize();
    GUI::instance()->stats->win->iconize();
    GUI::instance()->messages->win->iconize();
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
    for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++)
      GUI::instance()->graph[i]->win->show();
    if(GUI::instance()->options->win->shown()) 
      GUI::instance()->options->win->show();
    if(GUI::instance()->plugins->win->shown())
      GUI::instance()->plugins->win->show();
    if(GUI::instance()->fields->win->shown())
      GUI::instance()->fields->win->show();
    if(GUI::instance()->geoContext->win->shown())
      GUI::instance()->geoContext->win->show();
    if(GUI::instance()->meshContext->win->shown())
      GUI::instance()->meshContext->win->show();
    for(unsigned int i = 0; i < GUI::instance()->solver.size(); i++) {
      if(GUI::instance()->solver[i]->win->shown())
        GUI::instance()->solver[i]->win->show();
    }
    if(GUI::instance()->visibility->win->shown())
      GUI::instance()->visibility->win->show();
    if(GUI::instance()->clipping->win->shown())
      GUI::instance()->clipping->win->show();
    if(GUI::instance()->manip->win->shown())
      GUI::instance()->manip->win->show();
    if(GUI::instance()->stats->win->shown())
      GUI::instance()->stats->win->show();
    if(GUI::instance()->messages->win->shown())
      GUI::instance()->messages->win->show();
    GUI::instance()->menu->win->show();
  }
}

// Utility routines

int GetFontIndex(const char *fontname)
{
  if(fontname){
    for(int i = 0; i < NUM_FONTS; i++)
      if(!strcmp(menu_font_names[i].label(), fontname))
        return i;
  }
  Msg::Error("Unknown font \"%s\" (using \"Helvetica\" instead)", fontname);
  Msg::Info("Available fonts:");
  for(int i = 0; i < NUM_FONTS; i++)
    Msg::Info("  \"%s\"", menu_font_names[i].label());
  return 4;
}

int GetFontEnum(int index)
{
  if(index >= 0 && index < NUM_FONTS)
    return (long)menu_font_names[index].user_data();
  return FL_HELVETICA;
}

const char *GetFontName(int index)
{
  if(index >= 0 && index < NUM_FONTS)
    return menu_font_names[index].label();
  return "Helvetica";
}

int GetFontAlign(const char *alignstr)
{
  if(alignstr){
    if(!strcmp(alignstr, "BottomLeft") || !strcmp(alignstr, "Left") ||
       !strcmp(alignstr, "left"))
      return 0;
    else if(!strcmp(alignstr, "BottomCenter") || !strcmp(alignstr, "Center") ||
            !strcmp(alignstr, "center"))
      return 1;
    else if(!strcmp(alignstr, "BottomRight") || !strcmp(alignstr, "Right") ||
            !strcmp(alignstr, "right"))
      return 2;
    else if(!strcmp(alignstr, "TopLeft"))
      return 3;
    else if(!strcmp(alignstr, "TopCenter"))
      return 4;
    else if(!strcmp(alignstr, "TopRight"))
      return 5;
    else if(!strcmp(alignstr, "CenterLeft"))
      return 6;
    else if(!strcmp(alignstr, "CenterCenter"))
      return 7;
    else if(!strcmp(alignstr, "CenterRight"))
      return 8;
  }
  Msg::Error("Unknown font alignment \"%s\" (using \"Left\" instead)", alignstr);
  Msg::Info("Available font alignments:");
  Msg::Info("  \"Left\" (or \"BottomLeft\")");
  Msg::Info("  \"Center\" (or \"BottomCenter\")");
  Msg::Info("  \"Right\" (or \"BottomRight\")");
  Msg::Info("  \"TopLeft\"");
  Msg::Info("  \"TopCenter\"");
  Msg::Info("  \"TopRight\"");
  Msg::Info("  \"CenterLeft\"");
  Msg::Info("  \"CenterCenter\"");
  Msg::Info("  \"CenterRight\"");
  return 0;
}

int GetFontSize()
{
  if(CTX.fontsize > 0){
    return CTX.fontsize;
  }
  else{
    int w = Fl::w();
    if(w <= 1024)      return 11;
    else if(w <= 1280) return 12;
    else if(w <= 1680) return 13;
    else if(w <= 1920) return 14;
    else               return 15;
  }
}

void add_multiline_in_browser(Fl_Browser *o, const char *prefix, 
                              const char *str, int wrap)
{
  int start = 0, len;
  if(!str || !strlen(str) || !strcmp(str, "\n")) {
    o->add(" ");
    return;
  }
  for(int i = 0; i < (int)strlen(str); i++) {
    if(i == (int)strlen(str) - 1 || str[i] == '\n' || 
       (wrap > 0 && i - start == wrap)) {
      if(wrap > 0 && i - start == wrap){ //line is longer than wrap
        while(str[i] != ' ' && i > start) //go back to the previous space
          i--;
        if(i == start) //no space in this line, cut the word
          i += wrap;
      }
      len = i - start + (str[i] == '\n' ? 0 : 1);
      char *buff = new char[len + strlen(prefix) + 2];
      strcpy(buff, prefix);
      strncat(buff, &str[start], len);
      buff[len + strlen(prefix)] = '\0';
      o->add(buff);
      start = i + 1;
      delete [] buff;
    }
  }
}
