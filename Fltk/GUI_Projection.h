#ifndef _GUI_PROJECTION_H_
#define _GUI_PROJECTION_H_

#include "GmshUI.h"
#include "GModel.h"
#include "FProjectionFace.h"
#include "GUI.h"
#include "Shortcut_Window.h"
#include "ColorTable.h"
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <vector>
#include <complex>

#if defined(HAVE_FOURIER_MODEL)

void select_cb(Fl_Widget *w, void *data);
void filter_cb(Fl_Widget *w, void *data);
void browse_cb(Fl_Widget *w, void *data);
void set_position_cb(Fl_Widget *w, void *data);
void invert_normal_cb(Fl_Widget *w, void *data);
void translate_p0_cb(Fl_Widget *w, void *data);
void translate_p1_cb(Fl_Widget *w, void *data);
void translate_p2_cb(Fl_Widget *w, void *data);
void translate_m0_cb(Fl_Widget *w, void *data);
void translate_m1_cb(Fl_Widget *w, void *data);
void translate_m2_cb(Fl_Widget *w, void *data);
void update_cb(Fl_Widget *w, void *data);
void close_cb(Fl_Widget *w, void *data);
void hide_cb(Fl_Widget *w, void *data);
void save_selection_cb(Fl_Widget *w, void *data);
void load_projection_cb(Fl_Widget *w, void *data);
void save_projection_cb(Fl_Widget *w, void *data);
void compute_cb(Fl_Widget *w, void *data);
void action_cb(Fl_Widget *w, void *data);

class uvPlot : public Fl_Window {
 private:
  std::vector<double> _u, _v, _dist;
  std::vector<std::complex<double> > _f; // "signed" distance
  GmshColorTable _colorTable;
  double _dmin, _dmax;
  void color(double d);
  void draw();
 public:
  uvPlot(int x, int y, int w, int h, const char *l=0);
  void set(std::vector<double> &u, std::vector<double> &v, std::vector<double> &dist, 
	   std::vector<std::complex<double> > &f);
  void get(std::vector<double> &u, std::vector<double> &v, std::vector<double> &dist,
	   std::vector<std::complex<double> > &f)
  { u = _u; v = _v; dist = _dist; f = _f; }
};

class projectionEditor;

class projection {
 public:
  FProjectionFace *face;
  Fl_Group *group;
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
  int _paramWin[6];
  Fl_Round_Button *_select[2], *_pselect[2];
  uvPlot *_uvPlot;
  Fl_Value_Input *_modes[4];
  Fl_Toggle_Button *_hardEdges[4], *_orientation;
  Fl_Slider *_slider;
 public:
  projectionEditor();
  void load(FProjectionFace *face, std::string tag="");
  void show(){ _window->show(); select_cb(0, this); }
  uvPlot *uv() { return _uvPlot; }
  std::vector<MElement*> &getElements() { return _elements; }
  std::vector<GEntity*> &getEntities() { return _entities; }
  std::vector<projection*> &getProjections() { return _projections; }
  projection *getCurrentProjection();
  projection *getLastProjection();
  int getSelectionMode();
  int getPatchType();
  int getMode(int i){ return (int)_modes[i]->value(); }
  int getHardEdge(int i){ return (int)_hardEdges[i]->value(); }
  int getOrientation(){ return (int)_orientation->value(); }
  double getThreshold(){ return _slider->value(); }
};

#endif

#endif
