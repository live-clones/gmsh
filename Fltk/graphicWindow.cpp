// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string.h>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include "GUI.h"
#include "graphicWindow.h"
#include "paletteWindow.h"
#include "mainWindow.h"
#include "menuWindow.h"
#include "messageWindow.h"
#include "manipWindow.h"
#include "extraDialogs.h"
#include "Draw.h"
#include "PView.h"
#include "PViewData.h"
#include "OS.h"
#include "Options.h"
#include "Context.h"

// Icons for the satus bar
#define vv(x,y) fl_vertex(x,y)
#define bl fl_begin_loop()
#define el fl_end_loop()

static void gmsh_play(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.3,0.8); vv(0.5,0.0); vv(-0.3,-0.8); el;
}

static void gmsh_pause(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.8,-0.8); vv(-0.3,-0.8); vv(-0.3,0.8); vv(-0.8,0.8); el;
  bl; vv(0.0,-0.8); vv(0.5,-0.8); vv(0.5,0.8); vv(0.0,0.8); el;
}

static void gmsh_rewind(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.8,-0.8); vv(-0.3,-0.8); vv(-0.3,0.8); vv(-0.8,0.8); el;
  bl; vv(-0.3,0.0); vv(0.5,-0.8); vv(0.5,0.8); el;
}

static void gmsh_forward(Fl_Color c)
{
  fl_color(c);
  bl; vv(0.0,0.8); vv(0.8,0.0); vv(0.0,-0.8); el;
  bl; vv(-0.8,0.8); vv(-0.3,0.8); vv(-0.3,-0.8); vv(-0.8,-0.8); el;
}

static void gmsh_back(Fl_Color c)
{
  fl_rotate(180);  
  gmsh_forward(c);
}

static void gmsh_ortho(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.8,0.8); vv(0.3,0.8); vv(0.3,-0.3); vv(-0.8,-0.3); el;
  bl; vv(-0.3,0.3); vv(0.8,0.3); vv(0.8,-0.8); vv(-0.3,-0.8); el;
  fl_begin_line(); vv(-0.8,0.8); vv(-0.3,0.3); fl_end_line();
  fl_begin_line(); vv(0.3,0.8); vv(0.8,0.3); fl_end_line();
  fl_begin_line(); vv(0.3,-0.3); vv(0.8,-0.8); fl_end_line();
  fl_begin_line(); vv(-0.8,-0.3); vv(-0.3,-0.8); fl_end_line();
}

static void gmsh_rotate(Fl_Color c)
{
  fl_color(c);
  fl_begin_line(); fl_arc(0.0, -0.1, 0.7, 0.0, 270.0); fl_end_line();
  fl_begin_polygon(); vv(0.5,0.6); vv(-0.1,0.9); vv(-0.1,0.3); fl_end_polygon();
}

static void gmsh_models(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.8,-0.8); vv(-0.3,-0.8); vv(-0.3,-0.3); vv(-0.8,-0.3); el;
  bl; vv(0.3,-0.8); vv(0.8,-0.8); vv(0.8,-0.3); vv(0.3,-0.3); el;
  bl; vv(-0.8,0.3); vv(-0.3,0.3); vv(-0.3,0.8); vv(-0.8,0.8); el;
  bl; vv(0.3,0.3); vv(0.8,0.3); vv(0.8,0.8); vv(0.3,0.8); el;
}

#undef vv
#undef bl
#undef el

static graphicWindow *getGraphicWindow(Fl_Widget *w)
{
  if(!w || !w->parent()) return GUI::instance()->graph[0];
  for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++)
    if(GUI::instance()->graph[i]->win == w->parent())
      return GUI::instance()->graph[i];
  return GUI::instance()->graph[0];
}

void status_xyz1p_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;

  std::vector<openglWindow*> gls;
  if(w)
    gls = getGraphicWindow(w)->gl;
  else
    gls.push_back(GUI::instance()->getCurrentOpenglWindow());

  for(unsigned int i = 0; i < gls.size(); i++){
    drawContext *ctx = gls[i]->getDrawContext();
    if(!strcmp(str, "r")){ // rotate 90 degress around axis perp to the screen
      double axis[3] = {0., 0., 1.};
      if(!Fl::event_state(FL_SHIFT))
        ctx->addQuaternionFromAxisAndAngle(axis, -90.);
      else
        ctx->addQuaternionFromAxisAndAngle(axis, 90.);
    }
    else if(!strcmp(str, "x")){ // X pointing out or into the screen
      if(!Fl::event_state(FL_SHIFT)){
        ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = -90.;
      }
      else{
        ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = 90.;
      }
      ctx->setQuaternionFromEulerAngles();
    }
    else if(!strcmp(str, "y")){ // Y pointing out or into the screen
      if(!Fl::event_state(FL_SHIFT)){
        ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = 180.;
      }
      else{
        ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = 0.;
      }
      ctx->setQuaternionFromEulerAngles();
    }
    else if(!strcmp(str, "z")){ // Z pointing out or into the screen
      if(!Fl::event_state(FL_SHIFT)){
        ctx->r[0] = 0.; ctx->r[1] = 0.; ctx->r[2] = 0.;
      }
      else{
        ctx->r[0] = 0.; ctx->r[1] = 180.; ctx->r[2] = 0.;
      }
      ctx->setQuaternionFromEulerAngles();
    }
    else if(!strcmp(str, "1:1")){ // reset translation and scaling
      ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
      ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
    }
    else if(!strcmp(str, "reset")){ // reset everything
      ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
      ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
      ctx->r[0] = ctx->r[1] = ctx->r[2] = 0.;
      ctx->setQuaternionFromEulerAngles();
    }
  }
  Draw();
  GUI::instance()->manip->update();
}

void status_options_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
  if(!strcmp(str, "model")){ // model selection
    model_chooser();
  }
  else if(!strcmp(str, "?")){ // display options
    PrintOptions(0, GMSH_FULLRC, 0, 1, NULL);
    GUI::instance()->messages->show();
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
  else if(!strcmp(str, "S")){ // mouse selection
    if(CTX::instance()->mouseSelection){
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
      for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++)
        for(unsigned int j = 0; j < GUI::instance()->graph[i]->gl.size(); j++)
          GUI::instance()->graph[i]->gl[j]->cursor
            (FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
    }
    else
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  }
}

static int stop_anim = 0, view_in_cycle = -1;

void status_play_manual(int time, int step)
{
  // avoid firing this routine recursively (can happen e.g when
  // keeping the finger down on the arrow key: if the system generates
  // too many events, we can overflow the stack--that happened on my
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

static void status_play_cb(Fl_Widget *w, void *data)
{
  static double anim_time;
  getGraphicWindow(w)->setAnimButtons(0);
  stop_anim = 0;
  anim_time = GetTimeInSeconds();
  while(1) {
    if(stop_anim)
      break;
    if(GetTimeInSeconds() - anim_time > CTX::instance()->post.animDelay) {
      anim_time = GetTimeInSeconds();
      status_play_manual(!CTX::instance()->post.animCycle, 1);
    }
    GUI::instance()->check();
  }
}

static void status_pause_cb(Fl_Widget *w, void *data)
{
  stop_anim = 1;
  getGraphicWindow(w)->setAnimButtons(1);
}

static void status_rewind_cb(Fl_Widget *w, void *data)
{
  if(!CTX::instance()->post.animCycle) {
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

static void status_stepbackward_cb(Fl_Widget *w, void *data)
{
  status_play_manual(!CTX::instance()->post.animCycle, -1);
}

static void status_stepforward_cb(Fl_Widget *w, void *data)
{
  status_play_manual(!CTX::instance()->post.animCycle, 1);
}

static void remove_graphic_window_cb(Fl_Widget *w, void *data)
{
  std::vector<graphicWindow*> graph2;
  graphicWindow *deleteMe = 0;
  for(unsigned int i = 0; i < GUI::instance()->graph.size(); i++){
    if(GUI::instance()->graph[i]->win == w)
      deleteMe = GUI::instance()->graph[i];
    else
      graph2.push_back(GUI::instance()->graph[i]);
  }
  if(deleteMe){  
    openglWindow::setLastHandled(0);
    GUI::instance()->graph = graph2;
    delete deleteMe;
  }
}

// This dummy box class permits to define a box widget that will not
// eat the FL_ENTER/FL_LEAVE events (the new Box widget in fltk > 1.1
// does that, so that gl->handle() was not called when the mouse
// moved)
class dummyBox : public Fl_Box {
 private:
  int handle(int){ return 0; } // always!
 public:
  dummyBox(int x, int y, int w, int h, const char *l=0) : Fl_Box(x, y, w, h, l) {}
};

graphicWindow::graphicWindow(bool main, int numTiles)
{
  static bool first = true;
  if(first){
    fl_add_symbol("gmsh_rewind", gmsh_rewind, 1);
    fl_add_symbol("gmsh_back", gmsh_back, 1);
    fl_add_symbol("gmsh_play", gmsh_play, 1);
    fl_add_symbol("gmsh_pause", gmsh_pause, 1);
    fl_add_symbol("gmsh_forward", gmsh_forward, 1);
    fl_add_symbol("gmsh_ortho", gmsh_ortho, 1);
    fl_add_symbol("gmsh_rotate", gmsh_rotate, 1);
    fl_add_symbol("gmsh_models", gmsh_models, 1);
    first = false;
  }
  
  int sh = 2 * FL_NORMAL_SIZE - 4; // status bar height
  int sw = FL_NORMAL_SIZE + 3; // status button width
  int width = CTX::instance()->glSize[0];
  int glheight = CTX::instance()->glSize[1];
  int height = glheight + sh;
  
  // the graphic window should be a "normal" window (neither modal nor
  // non-modal)
  if(main){
    win = new mainWindow(width, height, false);
    win->callback(file_quit_cb);
  }
  else{
    win = new paletteWindow(width, height, false);
    win->callback(remove_graphic_window_cb);
  }

  // bottom button bar
  bottom = new Fl_Box(0, glheight, width, sh);
  bottom->box(FL_FLAT_BOX);
  
  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom
  
  butt[5] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_models");
  butt[5]->callback(status_options_cb, (void *)"model");
  butt[5]->tooltip("Select active model");
  x += sw;
  butt[0] = new Fl_Button(x, glheight + 2, sw, sht, "X");
  butt[0]->callback(status_xyz1p_cb, (void *)"x");
  butt[0]->tooltip("Set +X or -X view (Alt+x or Alt+Shift+x)");
  x += sw;  
  butt[1] = new Fl_Button(x, glheight + 2, sw, sht, "Y");
  butt[1]->callback(status_xyz1p_cb, (void *)"y");
  butt[1]->tooltip("Set +Y or -Y view (Alt+y or Alt+Shift+y)");
  x += sw;  
  butt[2] = new Fl_Button(x, glheight + 2, sw, sht, "Z");
  butt[2]->callback(status_xyz1p_cb, (void *)"z");
  butt[2]->tooltip("Set +Z or -Z view (Alt+z or Alt+Shift+z)");
  x += sw;  
  butt[4] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_rotate");
  butt[4]->callback(status_xyz1p_cb, (void *)"r");
  butt[4]->tooltip("Rotate +90 or -90 degrees");
  x += sw;  
  butt[3] = new Fl_Button(x, glheight + 2, 2 * FL_NORMAL_SIZE, sht, "1:1");
  butt[3]->callback(status_xyz1p_cb, (void *)"1:1");
  butt[3]->tooltip("Set unit scale");
  x += 2 * FL_NORMAL_SIZE;  
  butt[8] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_ortho");
  butt[8]->callback(status_options_cb, (void *)"p");
  butt[8]->tooltip("Toggle projection mode (Alt+o or Alt+Shift+o)");
  x += sw;  
  butt[9] = new Fl_Button(x, glheight + 2, sw, sht, "S");
  butt[9]->callback(status_options_cb, (void *)"S");
  butt[9]->tooltip("Toggle mouse selection ON/OFF (Escape)");
  x += sw;  
  butt[6] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_rewind");
  butt[6]->callback(status_rewind_cb);
  butt[6]->tooltip("Rewind animation");
  butt[6]->deactivate();
  x += sw;  
  butt[10] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_back");
  butt[10]->callback(status_stepbackward_cb);
  butt[10]->tooltip("Step backward");
  butt[10]->deactivate();
  x += sw;  
  butt[7] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_play");
  butt[7]->callback(status_play_cb);
  butt[7]->tooltip("Play/pause animation");
  butt[7]->deactivate();
  x += sw;  
  butt[11] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_forward");
  butt[11]->callback(status_stepforward_cb);
  butt[11]->tooltip("Step forward");
  butt[11]->deactivate();
  x += sw;
  
  for(int i = 0; i < 12; i++) {
    butt[i]->box(FL_FLAT_BOX);
    butt[i]->selection_color(FL_WHITE);
    butt[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  }
  
  x += 2;
  int wleft = (width - x) / 3 - 1;
  int wright = (width - x) - (width - x) / 3 - 1;
  
  label[0] = new Fl_Box(x, glheight + 2, wleft, sht);
  label[1] = new Fl_Box(x + (width - x) / 3, glheight + 2, wright, sht);
  for(int i = 0; i < 2; i++) {
    label[i]->box(FL_THIN_DOWN_BOX);
    label[i]->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  }
  
  // dummy resizable box
  dummyBox *resbox = new dummyBox(x, 0, width - x, glheight);
  win->resizable(resbox);

  // set mininum window size
  minWidth = x;
  minHeight = 100;
  win->size_range(minWidth, minHeight);

  // tiled opengl windows
  tile = new Fl_Tile(0, 0, width, glheight);

  int w2 = width / 2, h2 = glheight / 2;
  if(numTiles == 2){
    gl.push_back(new openglWindow(0, 0, w2, glheight));
    gl.back()->end();
    gl.push_back(new openglWindow(w2, 0, width - w2, glheight));
    gl.back()->end();
  }
  else if(numTiles == 3){
    gl.push_back(new openglWindow(0, 0, w2, glheight));
    gl.back()->end();
    gl.push_back(new openglWindow(w2, 0, width - w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(w2, h2, width - w2, glheight - h2));
    gl.back()->end();
  }
  else if(numTiles == 4){
    gl.push_back(new openglWindow(0, 0, w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(w2, 0, width - w2, h2));
    gl.back()->end();
    gl.push_back(new openglWindow(0, h2, width - w2, glheight - h2));
    gl.back()->end();
    gl.push_back(new openglWindow(w2, h2, width - w2, glheight - h2));
    gl.back()->end();
  }
  else{
    gl.push_back(new openglWindow(0, 0, width, glheight));
    gl.back()->end();
  }

  int mode = FL_RGB | FL_DEPTH | (CTX::instance()->db ? FL_DOUBLE : FL_SINGLE);
  if(CTX::instance()->antialiasing) mode |= FL_MULTISAMPLE;
  for(unsigned int i = 0; i < gl.size(); i++) gl[i]->mode(mode);

  tile->end();

  win->position(CTX::instance()->glPosition[0], CTX::instance()->glPosition[1]);
  win->end();
}

graphicWindow::~graphicWindow()
{
  openglWindow::setLastHandled(0);
  tile->clear();
  win->clear();
  Fl::delete_widget(win);
}

void graphicWindow::setTitle(std::string str)
{
  _title = str;
  win->label(_title.c_str());
}

void graphicWindow::split(openglWindow *g, char how)
{
  if(tile->find(g) == tile->children()) return;

  if(how == 'u'){
    // after many tries I cannot figure out how to do this cleanly, so
    // let's be brutal :-)
    int mode = g->mode();
    openglWindow::setLastHandled(0);
    tile->clear();
    gl.clear();
    openglWindow *g2 = new openglWindow(0, 0, tile->w(), tile->h());
    g2->mode(mode);
    g2->end();
    gl.push_back(g2);
    tile->add(g2);
    g2->show();
    return;
  }

  int x1 = g->x();
  int y1 = g->y();
  int w1 = (how == 'h') ? g->w() / 2 : g->w();
  int h1 = (how == 'h') ? g->h() : g->h() / 2;

  int x2 = (how == 'h') ? (g->x() + w1) : g->x();
  int y2 = (how == 'h') ? g->y() : (g->y() + h1);
  int w2 = (how == 'h') ? (g->w() - w1) : g->w();
  int h2 = (how == 'h') ? g->h() : (g->h() - h1);

  openglWindow *g2 = new openglWindow(0, 0, w2, h2);
  g2->mode(g->mode());
  g2->end();

  gl.push_back(g2);
  tile->add(g2);
  g2->show();

  g->resize(x1, y1, w1, h1);
  g2->resize(x2, y2, w2, h2);
}

void graphicWindow::setAnimButtons(int mode)
{
  if(mode) {
    butt[7]->callback(status_play_cb);
    butt[7]->label("@-1gmsh_play");
  }
  else {
    butt[7]->callback(status_pause_cb);
    butt[7]->label("@-1gmsh_pause");
  }
}

void graphicWindow::checkAnimButtons()
{
  bool play = false;
  if(CTX::instance()->post.animCycle){
    play = true;
  }
  else{
    for(unsigned int i = 0; i < PView::list.size(); i++){
      if(PView::list[i]->getData()->getNumTimeSteps() > 1){
        play = true;
        break;
      }
    }
  }
  if(play){
    butt[6]->activate();
    butt[7]->activate();
    butt[10]->activate();
    butt[11]->activate();
  }
  else{
    butt[6]->deactivate();
    butt[7]->deactivate();
    butt[10]->deactivate();
    butt[11]->deactivate();
  }
}
