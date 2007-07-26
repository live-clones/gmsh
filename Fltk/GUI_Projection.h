#ifndef _GUI_PROJECTION_H_
#define _GUI_PROJECTION_H_

#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "projectionFace.h"

#include <vector>

#include "GUI.h"
#include "Shortcut_Window.h"
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>

void select_cb(Fl_Widget *w, void *data);
void browse_cb(Fl_Widget *w, void *data);
void update_cb(Fl_Widget *w, void *data);
void close_cb(Fl_Widget *w, void *data);
void hide_cb(Fl_Widget *w, void *data);
void save_cb(Fl_Widget *w, void *data);
void compute_cb(Fl_Widget *w, void *data);

class uvPlot : public Fl_Window {
 private:
  std::vector<double> _u, _v;
  void draw();
 public:
  uvPlot(int x, int y, int w, int h, const char *l=0) : Fl_Window(x, y, w, h, l){}
  void fill(std::vector<double> &u, std::vector<double> &v){ _u = u; _v = v; redraw(); }
};

class projectionEditor {
 private:
  std::vector<projectionFace*> _faces;
  std::vector<MElement*> _elements;
  std::vector<GEntity*> _entities;
  Fl_Window *_window;
  Fl_Value_Input *_input[20];
  Fl_Hold_Browser *_browser;
  Fl_Round_Button *_select[3];
  uvPlot *_uvPlot;
 public:
  projectionEditor(std::vector<projectionFace*> &faces);
  void show(){ _window->show(); select_cb(0, this); }
  uvPlot *uv() { return _uvPlot; }
  std::vector<MElement*> &getElements() { return _elements; }
  std::vector<GEntity*> &getEntities() { return _entities; }
  std::vector<projectionFace*> &getProjectionFaces() { return _faces; }
  int getSelectionMode();
};

#endif
