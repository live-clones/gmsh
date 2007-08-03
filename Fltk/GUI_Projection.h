#ifndef _GUI_PROJECTION_H_
#define _GUI_PROJECTION_H_

#include "Gmsh.h"
#include "GmshUI.h"
#include "GModel.h"
#include "GUI.h"
#include "Shortcut_Window.h"
#include "ColorTable.h"
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>

#if defined(HAVE_FOURIER_MODEL)

#include "Utils.h"
#include <vector>
#include <complex>
#include "FVertex.h"
#include "FEdge.h"
#include "FFace.h"
#include "FPatch.h"
#include "FCurve.h"
#include "FProjectionFace.h"
#include "FM_Vertex.h"
#include "FM_Edge.h"
#include "FM_Face.h"

void select_cb(Fl_Widget *w, void *data);
void browse_cb(Fl_Widget *w, void *data);
void update_cb(Fl_Widget *w, void *data);
void close_cb(Fl_Widget *w, void *data);
void hide_cb(Fl_Widget *w, void *data);
void save_cb(Fl_Widget *w, void *data);
void compute_cb(Fl_Widget *w, void *data);

class uvPlot : public Fl_Window {
 private:
  std::vector<double> _u, _v, _f;
  GmshColorTable _colorTable;
  double _dmin, _dmax;
  void color(double d);
  void draw();
 public:
  uvPlot(int x, int y, int w, int h, const char *l=0);
  void fill(std::vector<double> &u, std::vector<double> &v, std::vector<double> &f);
};

class projectionEditor;

class projection {
 public:
  FProjectionFace *face;
  Fl_Group *group;
  double *currentParams;
  std::vector<Fl_Value_Input*> parameters;
  projection(FProjectionFace *f, int x, int y, int w, int h, int BB, int BH,
	     projectionEditor *e);
};

class projectionEditor {
 private:
  std::vector<projection*> _projections;
  std::vector<MElement*> _elements;
  std::vector<GEntity*> _entities;
  Fl_Window *_window;
  Fl_Hold_Browser *_browser;
  Fl_Round_Button *_select[3];
  uvPlot *_uvPlot;
 public:
  projectionEditor(std::vector<FProjectionFace*> &faces);
  void show(){ _window->show(); select_cb(0, this); }
  uvPlot *uv() { return _uvPlot; }
  Fl_Value_Input* modes[4];
  std::vector<MElement*> &getElements() { return _elements; }
  std::vector<GEntity*> &getEntities() { return _entities; }
  std::vector<projection*> &getProjections() { return _projections; }
  projection *getCurrentProjection();
  int getSelectionMode();
};

#endif

#endif
