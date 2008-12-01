// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <FL/fl_draw.H>
#include "graphicWindow.h"
#include "shortcutWindow.h"
#include "PView.h"
#include "PViewData.h"
#include "Callbacks.h"
#include "Context.h"

extern Context_T CTX;

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

graphicWindow::graphicWindow(int fontsize)
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
  
  int sh = 2 * fontsize - 4; // status bar height
  int sw = fontsize + 3; // status button width
  int width = CTX.tmp_viewport[2] - CTX.tmp_viewport[0];
  int glheight = CTX.tmp_viewport[3] - CTX.tmp_viewport[1];
  int height = glheight + sh;
  
  // the graphic window is a "main" window: it should be a normal
  // window (neither modal nor non-modal)
  win = new mainWindow(width, height, false);
  win->callback(file_quit_cb);
  
  // bottom button bar
  Fl_Box *bottom = new Fl_Box(0, glheight, width, sh);
  bottom->box(FL_FLAT_BOX);
  
  int x = 2;
  int sht = sh - 4; // leave a 2 pixel border at the bottom
  
  butt[5] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_models");
  x += sw;
  butt[5]->callback(status_xyz1p_cb, (void *)"model");
  butt[5]->tooltip("Change current model");
  
  butt[0] = new Fl_Button(x, glheight + 2, sw, sht, "X");
  x += sw;
  butt[0]->callback(status_xyz1p_cb, (void *)"x");
  butt[0]->tooltip("Set +X or -X view (Alt+x or Alt+Shift+x)");
  
  butt[1] = new Fl_Button(x, glheight + 2, sw, sht, "Y");
  x += sw;
  butt[1]->callback(status_xyz1p_cb, (void *)"y");
  butt[1]->tooltip("Set +Y or -Y view (Alt+y or Alt+Shift+y)");
  
  butt[2] = new Fl_Button(x, glheight + 2, sw, sht, "Z");
  x += sw;
  butt[2]->callback(status_xyz1p_cb, (void *)"z");
  butt[2]->tooltip("Set +Z or -Z view (Alt+z or Alt+Shift+z)");
  
  butt[4] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_rotate");
  x += sw;
  butt[4]->callback(status_xyz1p_cb, (void *)"r");
  butt[4]->tooltip("Rotate +90 or -90 degrees");
  
  butt[3] = new Fl_Button(x, glheight + 2, 2 * fontsize, sht, "1:1");
  x += 2 * fontsize;
  butt[3]->callback(status_xyz1p_cb, (void *)"1:1");
  butt[3]->tooltip("Set unit scale");
  
  butt[8] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_ortho");
  x += sw;
  butt[8]->callback(status_xyz1p_cb, (void *)"p");
  butt[8]->tooltip("Toggle projection mode (Alt+o or Alt+Shift+o)");
  
  butt[9] = new Fl_Button(x, glheight + 2, sw, sht, "S");
  x += sw;
  butt[9]->callback(status_xyz1p_cb, (void *)"S");
  butt[9]->tooltip("Toggle mouse selection ON/OFF (Escape)");
  
  butt[6] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_rewind");
  x += sw;
  butt[6]->callback(status_rewind_cb);
  butt[6]->tooltip("Rewind animation");
  butt[6]->deactivate();
  
  butt[10] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_back");
  x += sw;
  butt[10]->callback(status_stepbackward_cb);
  butt[10]->tooltip("Step backward");
  butt[10]->deactivate();
  
  butt[7] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_play");
  x += sw;
  butt[7]->callback(status_play_cb);
  butt[7]->tooltip("Play/pause animation");
  butt[7]->deactivate();
  
  butt[11] = new Fl_Button(x, glheight + 2, sw, sht, "@-1gmsh_forward");
  x += sw;
  butt[11]->callback(status_stepforward_cb);
  butt[11]->tooltip("Step forward");
  butt[11]->deactivate();
  
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
  
  // opengl window
  gl = new openglWindow(0, 0, width, glheight);
  int mode = FL_RGB | FL_DEPTH | (CTX.db ? FL_DOUBLE : FL_SINGLE);
  if(CTX.antialiasing) mode |= FL_MULTISAMPLE;
  gl->mode(mode);
  gl->end();
  
  win->position(CTX.gl_position[0], CTX.gl_position[1]);
  win->end();
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
  if(CTX.post.anim_cycle){
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
