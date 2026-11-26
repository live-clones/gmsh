// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MIDSURFACER_WINDOW_H
#define MIDSURFACER_WINDOW_H

#include "GmshConfig.h"

#if defined(HAVE_MATGMSH) && defined(HAVE_POST)
#define HAVE_MIDSURFACER

#include <string>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Value_Input.H>

// The mid-surface of a thin-walled solid, one stage of the pipeline of
// contrib/MatGmsh at a time:
//
//   1. skin        the surface mesh the medial axis is computed from
//   2. medial axis the raw MAT, with its certificate
//   3. filter      the MAT without its wings and its thin sheets
//   4. projection  (optional) onto the local mid-surface
//   5. extension   of the free boundaries to the skin
//
// Each stage has its parameters, a button that runs it, a line that says what
// it gave and a view of its result. A button also runs the earlier stages
// that are missing or out of date; the raw MAT is kept (see
// matgmsh_native::Session), so that the filter, the projection and the
// extension run again without a new tetrahedrization.
class midsurfacerWindow {
public:
  enum { Skin, Raw, Filter, Projection, Extension, NumStages };
  Fl_Window *win;
  Fl_Value_Input *thickness, *meshSize, *threshold, *length, *layers;
  Fl_Choice *method;
  // the filter removes the wing branches of the raw MAT whole
  Fl_Check_Button *branches;
  Fl_Button *push[NumStages];
  Fl_Box *status[NumStages];
  Fl_Check_Button *visible[NumStages];

  midsurfacerWindow(int deltaFontSize = 0);
  ~midsurfacerWindow();
  void show();
  // runs the stage, after the earlier ones that are missing or out of date
  void run(int stage);
  // shows or hides the skin mesh or the view of a stage, as its box says
  void display(int stage, bool draw = true);

private:
  struct State;
  State *_state;
  bool _skin();
  void _say(int stage, const std::string &text, const std::string &more = "");
  void _view(int stage);
  void _forget(int fromStage);
  void _showOnly(int stage);
};

void midsurfacer_cb(Fl_Widget *w, void *data);

#endif

#endif
