// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PROJECTION_EDITOR_H_
#define _PROJECTION_EDITOR_H_

#include <vector>
#include <complex>
#include <FL/Fl_Window.H>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Hold_Browser.H>
#include "GmshConfig.h"
#include "fourierProjectionFace.h"
#include "GModel.h"
#include "ColorTable.h"

#if defined(HAVE_FOURIER_MODEL)

#include "FM_FPatch.h"
#include "FM_WFPatch.h"

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
  fourierProjectionFace *face;
  Fl_Group *group;
  std::vector<Fl_Value_Input*> parameters;
  projection(fourierProjectionFace *f, int x, int y, int w, int h, 
             int bb, int bh, projectionEditor *e);
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
  void load(fourierProjectionFace *face, std::string tag="");
  void show();
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

void mesh_parameterize_cb(Fl_Widget* w, void* data);

#endif
