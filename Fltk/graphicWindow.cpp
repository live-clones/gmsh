// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
 
#include <string.h>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include "FlGui.h"
#include "graphicWindow.h"
#include "paletteWindow.h"
#include "mainWindow.h"
#include "menuWindow.h"
#include "messageWindow.h"
#include "manipWindow.h"
#include "extraDialogs.h"
#include "PView.h"
#include "PViewData.h"
#include "OS.h"
#include "OpenFile.h"
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
  bl; vv(-0.8,-0.7); vv(0.8,-0.7); el;
  bl; vv(-0.8,-0.2); vv(0.8,-0.2); el;
  bl; vv(-0.8,0.3); vv(0.8,0.3); el;
  bl; vv(-0.8,0.8); vv(0.8,0.8); el;
}

static void gmsh_clscale(Fl_Color c)
{
  fl_color(c);
  bl; vv(-0.8,0.8); vv(-0.1,0.8); vv(-0.8,0.1); el;
  bl; vv(-0.2,0.2); vv(0.9,0.2); vv(-0.2,-0.9); el;
}

#undef vv
#undef bl
#undef el

static graphicWindow *getGraphicWindow(Fl_Widget *w)
{
  if(!w || !w->parent()) return FlGui::instance()->graph[0];
  for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
    if(FlGui::instance()->graph[i]->win == w->parent())
      return FlGui::instance()->graph[i];
  return FlGui::instance()->graph[0];
}

void status_xyz1p_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;

  std::vector<openglWindow*> gls;
  if(w)
    gls = getGraphicWindow(w)->gl;
  else
    gls.push_back(FlGui::instance()->getCurrentOpenglWindow());

  for(unsigned int i = 0; i < gls.size(); i++){
    drawContext *ctx = gls[i]->getDrawContext();
    if(!strcmp(str, "r")){
      // rotate +90 or -90 (shift) degress around axis perp to the
      // screen, or sync rotation with first window (alt)
      double axis[3] = {0., 0., 1.};
      if(Fl::event_state(FL_ALT)){
        if(i != 0){
          drawContext *ctx0 = gls[0]->getDrawContext();
          ctx->setQuaternion(ctx0->quaternion[0], ctx0->quaternion[1], 
                             ctx0->quaternion[2], ctx0->quaternion[3]);
        }
      }
      else if(!Fl::event_state(FL_SHIFT)){
        ctx->addQuaternionFromAxisAndAngle(axis, -90.);
	if (CTX::instance()->camera) ctx->camera.tiltHeadRight();
      }
      else{
        ctx->addQuaternionFromAxisAndAngle(axis, 90.);
	if (CTX::instance()->camera) ctx->camera.tiltHeadLeft();
      }
    }
    else if(!strcmp(str, "x")){
      // set X-axis pointing out or into (shift) the screen
      if (CTX::instance()->camera) {
	ctx->camera.alongX();}
      else{
	if(!Fl::event_state(FL_SHIFT)){
	  ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = -90.;
	}
	else{
	  ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = 90.;
	}
	ctx->setQuaternionFromEulerAngles();
      }
    }
    else if(!strcmp(str, "y")){
      // set Y-axis pointing out or into (shift) the screen
      if (CTX::instance()->camera) {
	ctx->camera.alongY();}
      else{
	if(!Fl::event_state(FL_SHIFT)){
	  ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = 180.;
	}
	else{
	  ctx->r[0] = -90.; ctx->r[1] = 0.; ctx->r[2] = 0.;
	}
	ctx->setQuaternionFromEulerAngles();
      }
    }
    else if(!strcmp(str, "z")){ 
      // set Z-axis pointing out or into (shift) the screen
      if (CTX::instance()->camera) {
	ctx->camera.alongZ();}
      else{
	if(!Fl::event_state(FL_SHIFT)){
	  ctx->r[0] = 0.; ctx->r[1] = 0.; ctx->r[2] = 0.;
	}
	else{
	  ctx->r[0] = 0.; ctx->r[1] = 180.; ctx->r[2] = 0.;
	}
	ctx->setQuaternionFromEulerAngles();
      }
    }
    else if(!strcmp(str, "1:1")){
      // if Shift is pressed, reset bounding box around visible
      // entities
      if(Fl::event_state(FL_SHIFT))
        SetBoundingBox(true);
      // reset translation and scaling, or sync translation and
      // scaling with the first window (alt)
      if (CTX::instance()->camera) {
	ctx->camera.lookAtCg();
      }
      else{
	if(Fl::event_state(FL_ALT)){
	  if(i != 0){
	    drawContext *ctx0 = gls[0]->getDrawContext();
	    for(int j = 0; j < 3; j++){
	      ctx->t[j] = ctx0->t[j];
	      ctx->s[j] = ctx0->s[j];
	    }
	  }
	}
	else{
	  ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
	  ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
	}
      }
    }
    else if(!strcmp(str, "reset")){
      if (CTX::instance()->camera) {
	ctx->camera.init();
      }
      else{
	// reset everything
	ctx->t[0] = ctx->t[1] = ctx->t[2] = 0.;
	ctx->s[0] = ctx->s[1] = ctx->s[2] = 1.;
	ctx->r[0] = ctx->r[1] = ctx->r[2] = 0.;
	ctx->setQuaternionFromEulerAngles();
      }
    }
  }
  drawContext::global()->draw();
  FlGui::instance()->manip->update();
}

void status_options_cb(Fl_Widget *w, void *data)
{
  const char *str = (const char*)data;
  if(!strcmp(str, "model")){ // model selection
    modelChooser();
  }
  else if(!strcmp(str, "?")){ // display options
    PrintOptions(0, GMSH_FULLRC, 0, 1, NULL);
    FlGui::instance()->messages->show();
  }
  else if(!strcmp(str, "p")){ // toggle projection mode
    if(!Fl::event_state(FL_SHIFT)){
      opt_general_orthographic(0, GMSH_SET | GMSH_GUI, 
                               !opt_general_orthographic(0, GMSH_GET, 0));
    }
    else{
      perspectiveEditor();
    }
    drawContext::global()->draw();
  }
  else if(!strcmp(str, "M")){ // toggle mesh display
    static int value = 1;
    static int old_p = (int)opt_mesh_points(0, GMSH_GET, 0.);
    static int old_l = (int)opt_mesh_lines(0, GMSH_GET, 0.);
    static int old_se = (int)opt_mesh_surfaces_edges(0, GMSH_GET, 0.);
    static int old_sf = (int)opt_mesh_surfaces_faces(0, GMSH_GET, 0.);
    static int old_ve = (int)opt_mesh_volumes_edges(0, GMSH_GET, 0.);
    static int old_vf = (int)opt_mesh_volumes_faces(0, GMSH_GET, 0.);
    if(!value){ // retore visibility
      Msg::StatusBar(2, false, "Mesh display restored");
      value = 1;
      opt_mesh_points(0, GMSH_SET | GMSH_GUI, old_p);
      opt_mesh_lines(0, GMSH_SET | GMSH_GUI, old_l);
      opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, old_se);
      opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, old_sf);
      opt_mesh_volumes_edges(0, GMSH_SET | GMSH_GUI, old_ve);
      opt_mesh_volumes_faces(0, GMSH_SET | GMSH_GUI, old_vf);
    }
    else{
      Msg::StatusBar(2, false, "Mesh display OFF");
      value = 0;
      old_p = (int)opt_mesh_points(0, GMSH_GET, 0.);
      old_l = (int)opt_mesh_lines(0, GMSH_GET, 0.);
      old_se = (int)opt_mesh_surfaces_edges(0, GMSH_GET, 0.);
      old_sf = (int)opt_mesh_surfaces_faces(0, GMSH_GET, 0.);
      old_ve = (int)opt_mesh_volumes_edges(0, GMSH_GET, 0.);
      old_vf = (int)opt_mesh_volumes_faces(0, GMSH_GET, 0.);
      opt_mesh_points(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_lines(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_surfaces_edges(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_surfaces_faces(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_volumes_edges(0, GMSH_SET | GMSH_GUI, 0);
      opt_mesh_volumes_faces(0, GMSH_SET | GMSH_GUI, 0);
    }
    drawContext::global()->draw();
  }
  else if(!strcmp(str, "clscale")){
    meshSizeEditor();
  }
  else if(!strcmp(str, "S")){ // mouse selection
    if(CTX::instance()->mouseSelection){
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 0);
      for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++)
        for(unsigned int j = 0; j < FlGui::instance()->graph[i]->gl.size(); j++)
          FlGui::instance()->graph[i]->gl[j]->cursor
            (FL_CURSOR_DEFAULT, FL_BLACK, FL_WHITE);
    }
    else
      opt_general_mouse_selection(0, GMSH_SET | GMSH_GUI, 1);
  }
}

static int stop_anim = 0, view_in_cycle = -1;

void status_play_manual(int time, int incr)
{
  // avoid firing this routine recursively (can happen e.g when
  // keeping the finger down on the arrow key: if the system generates
  // too many events, we can overflow the stack--that happened on my
  // powerbook with the new, optimzed FLTK event handler)
  static bool busy = false;
  if(busy) return;
  busy = true;

  // if we watch some files this is a good time to check for new data
  file_watch_cb(0, 0);

  if(time) {
    for(unsigned int i = 0; i < PView::list.size(); i++){
      if(opt_view_visible(i, GMSH_GET, 0)){
        // skip empty steps
        int step = (int)opt_view_timestep(i, GMSH_GET, 0) + incr;
        int numSteps = (int)opt_view_nb_timestep(i, GMSH_GET, 0);
        for(int j = 0; j < numSteps; j++){
          if(PView::list[i]->getData()->hasTimeStep(step))
            break;
          else
            step += incr;
          if(step < 0) step = numSteps - 1;
          if(step > numSteps - 1) step = 0;
        }
        opt_view_timestep(i, GMSH_SET | GMSH_GUI, step);
      }
    }
  }
  else { // hide all views except view_in_cycle
    if(incr == 0) {
      view_in_cycle = 0;
      for(int i = 0; i < (int)PView::list.size(); i++)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else if(incr > 0) {
      if((view_in_cycle += incr) >= (int)PView::list.size())
        view_in_cycle = 0;
      for(int i = 0; i < (int)PView::list.size(); i += incr)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
    else {
      if((view_in_cycle += incr) < 0)
        view_in_cycle = PView::list.size() - 1;
      for(int i = PView::list.size() - 1; i >= 0; i += incr)
        opt_view_visible(i, GMSH_SET | GMSH_GUI, (i == view_in_cycle));
    }
  }
  drawContext::global()->draw();
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
    FlGui::instance()->check();
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
    for(unsigned int i = 0; i < PView::list.size(); i++) {
      int step = PView::list[i]->getData()->getFirstNonEmptyTimeStep();
      opt_view_timestep(i, GMSH_SET | GMSH_GUI, step);
    }
  }
  else {
    view_in_cycle = 0;
    for(unsigned int i = 0; i < PView::list.size(); i++)
      opt_view_visible(i, GMSH_SET | GMSH_GUI, !i);
  }
  drawContext::global()->draw();
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
  for(unsigned int i = 0; i < FlGui::instance()->graph.size(); i++){
    if(FlGui::instance()->graph[i]->win == w)
      deleteMe = FlGui::instance()->graph[i];
    else
      graph2.push_back(FlGui::instance()->graph[i]);
  }
  if(deleteMe){  
    openglWindow::setLastHandled(0);
    FlGui::instance()->graph = graph2;
    delete deleteMe;
  }
}

static void message_copy_cb(Fl_Widget *w, void *data)
{
  std::string buff;
  for(int i = 1; i <= FlGui::instance()->graph[0]->browser->size(); i++) {
    if(FlGui::instance()->graph[0]->browser->selected(i)) {
      const char *c = FlGui::instance()->graph[0]->browser->text(i);
      if(strlen(c) > 5 && c[0] == '@')
        buff += std::string(&c[5]);
      else
        buff += std::string(c);
      buff += "\n";
    }
  }
  // bof bof bof
  Fl::copy(buff.c_str(), buff.size(), 0);
  Fl::copy(buff.c_str(), buff.size(), 1);
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
    fl_add_symbol("gmsh_clscale", gmsh_clscale, 1);
    first = false;
  }
  
  int sh = 2 * FL_NORMAL_SIZE - 4; // status bar height
  int sw = FL_NORMAL_SIZE + 3; // status button width
  int width = CTX::instance()->glSize[0];
  int glheight = CTX::instance()->glSize[1];
  int mheight = glheight / 4;
  int height = glheight + mheight + sh;
  
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
  bottom = new Fl_Box(0, glheight + mheight, width, sh);
  bottom->box(FL_FLAT_BOX);
  
  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom
  
  butt[5] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_models");
  butt[5]->callback(status_options_cb, (void *)"model");
  butt[5]->tooltip("Select active model");
  x += sw;
  butt[0] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "X");
  butt[0]->callback(status_xyz1p_cb, (void *)"x");
  butt[0]->tooltip("Set +X or -X view (Alt+x or Alt+Shift+x)");
  x += sw;  
  butt[1] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "Y");
  butt[1]->callback(status_xyz1p_cb, (void *)"y");
  butt[1]->tooltip("Set +Y or -Y view (Alt+y or Alt+Shift+y)");
  x += sw;  
  butt[2] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "Z");
  butt[2]->callback(status_xyz1p_cb, (void *)"z");
  butt[2]->tooltip("Set +Z or -Z view (Alt+z or Alt+Shift+z)");
  x += sw;  
  butt[4] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_rotate");
  butt[4]->callback(status_xyz1p_cb, (void *)"r");
  butt[4]->tooltip("Rotate +90 or -90 (Shift) degrees, or sync rotations (Alt)");
  x += sw;  
  butt[3] = new Fl_Button(x, glheight + mheight + 2, 2 * FL_NORMAL_SIZE, sht, "1:1");
  butt[3]->callback(status_xyz1p_cb, (void *)"1:1");
  butt[3]->tooltip("Set unit scale, sync scale between viewports (Alt), "
                   "or reset bounding box around visible entities (Shift)");
  x += 2 * FL_NORMAL_SIZE;  
  butt[8] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_ortho");
  butt[8]->callback(status_options_cb, (void *)"p");
  butt[8]->tooltip("Toggle projection mode (Alt+o or Alt+Shift+o)");
  x += sw;  
  butt[12] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "M");
  butt[12]->callback(status_options_cb, (void *)"M");
  butt[12]->tooltip("Toggle mesh visibility (Alt+m)");
  x += sw;  
  butt[13] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_clscale");
  butt[13]->callback(status_options_cb, (void *)"clscale");
  butt[13]->tooltip("Change mesh element size factor");
  x += sw;  
  butt[9] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "S");
  butt[9]->callback(status_options_cb, (void *)"S");
  butt[9]->tooltip("Toggle mouse selection ON/OFF (Escape)");
  x += sw;  
  butt[6] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_rewind");
  butt[6]->callback(status_rewind_cb);
  butt[6]->tooltip("Rewind animation");
  butt[6]->deactivate();
  x += sw;  
  butt[10] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_back");
  butt[10]->callback(status_stepbackward_cb);
  butt[10]->tooltip("Step backward");
  butt[10]->deactivate();
  x += sw;  
  butt[7] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_play");
  butt[7]->callback(status_play_cb);
  butt[7]->tooltip("Play/pause animation");
  butt[7]->deactivate();
  x += sw;  
  butt[11] = new Fl_Button(x, glheight + mheight + 2, sw, sht, "@-1gmsh_forward");
  butt[11]->callback(status_stepforward_cb);
  butt[11]->tooltip("Step forward");
  butt[11]->deactivate();
  x += sw;
  
  for(int i = 0; i < 14; i++) {
    butt[i]->box(FL_FLAT_BOX);
    butt[i]->selection_color(FL_WHITE);
    butt[i]->align(FL_ALIGN_CENTER | FL_ALIGN_INSIDE | FL_ALIGN_CLIP);
  }
  
  x += 2;
  int wleft = (width - x) / 3 - 1;
  int wright = (width - x) - (width - x) / 3 - 1;
  
  label[0] = new Fl_Box(x, glheight + mheight + 2, wleft, sht);
  label[1] = new Fl_Box(x + (width - x) / 3, glheight + mheight + 2, wright, sht);
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
  tile = new Fl_Tile(0, 0, width, glheight + mheight);

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
  if(CTX::instance()->stereo) { 
    mode |= FL_DOUBLE;
    mode |= FL_STEREO;
  }
  for(unsigned int i = 0; i < gl.size(); i++) gl[i]->mode(mode);

  browser = new Fl_Browser(0, glheight, width, mheight);
  browser->box(FL_THIN_DOWN_BOX);
  browser->textfont(FL_COURIER);
  browser->textsize(FL_NORMAL_SIZE - 1);
  browser->type(FL_MULTI_BROWSER);
  browser->callback(message_copy_cb);
  browser->has_scrollbar(Fl_Browser_::VERTICAL);

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
    tile->clear(); // this really deletes the child opengl windows
    gl.clear();
    openglWindow *g2 = new openglWindow(0, 0, tile->w(), tile->h());
    g2->end();
    g2->mode(mode);
    gl.push_back(g2);
    tile->add(g2);
    g2->show();
  }
  else{
    int x1 = g->x();
    int y1 = g->y();
    int w1 = (how == 'h') ? g->w() / 2 : g->w();
    int h1 = (how == 'h') ? g->h() : g->h() / 2;
    
    int x2 = (how == 'h') ? (g->x() + w1) : g->x();
    int y2 = (how == 'h') ? g->y() : (g->y() + h1);
    int w2 = (how == 'h') ? (g->w() - w1) : g->w();
    int h2 = (how == 'h') ? g->h() : (g->h() - h1);
    
    openglWindow *g2 = new openglWindow(0, 0, w2, h2);
    g2->end();
    g2->mode(g->mode());
    
    gl.push_back(g2);
    tile->add(g2);
    g2->show();
    
    g->resize(x1, y1, w1, h1);
    g2->resize(x2, y2, w2, h2);
  }
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

void graphicWindow::showMessages(int numLines)
{
  // change tile "live" by changing the position of a tile intersection
  if(browser->h() == 0)
    tile->position(0, win->h() - bottom->h(),
                   0, win->h() - bottom->h() - 300);
  if(numLines && CTX::instance()->msgAutoScroll)
    browser->bottomline(browser->size());
  //tile->show();
  //printf("msg height = %d\n", msg->h());
}

void graphicWindow::addMessage(const char *msg)
{
  browser->add(msg, 0);
  if(win->shown() && browser->h() > 10 && CTX::instance()->msgAutoScroll)
    browser->bottomline(browser->size());
}

void graphicWindow::saveMessages(const char *filename)
{
  FILE *fp = fopen(filename, "w");

  if(!fp) {
    Msg::Error("Unable to open file '%s'", filename);
    return;
  }

  Msg::StatusBar(2, true, "Writing '%s'...", filename);
  for(int i = 1; i <= browser->size(); i++) {
    const char *c = browser->text(i);
    if(c[0] == '@')
      fprintf(fp, "%s\n", &c[5]);
    else
      fprintf(fp, "%s\n", c);
  }
  Msg::StatusBar(2, true, "Done writing '%s'", filename);
  fclose(fp);
}
