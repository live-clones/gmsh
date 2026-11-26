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
#include <FL/Fl_Hold_Browser.H>
#include <FL/Fl_Value_Input.H>

// The mid-surface of a thin-walled solid, one stage of the pipeline of
// contrib/MatGmsh at a time:
//
//   1. skin        the surface mesh the medial axis is computed from
//   2. medial axis the raw MAT, with its certificate
//   3. filter      the MAT without its wings and its thin sheets
//   4. projection  (optional) onto the local mid-surface
//   5. extension   branch by branch: a flat branch in its plane, any branch
//                  by a ribbon along its free boundary
//
// Each stage has its parameters, a button that runs it, a line that says what
// it gave and a view of its result. A button also runs the earlier stages
// that are missing or out of date; the raw MAT is kept (see
// matgmsh_native::Session), so that the filter, the projection and the
// extension run again without a new tetrahedrization.
class midsurfacerWindow {
public:
  enum { Skin, Raw, Filter, Projection, Extension, NumStages };
  // more views: the raw MAT colored by the angle of its branches, the branch
  // selected, and what would extend it (the fragments of its plane, or its
  // ribbon before it is cut)
  enum { Angles = NumStages, Selected, Preview, NumViews };
  Fl_Window *win;
  Fl_Value_Input *thickness, *meshSize, *threshold, *length, *layers;
  Fl_Choice *method;
  // the branches of the MAT being extended, and how the selected one is
  Fl_Hold_Browser *browser;
  Fl_Choice *how;
  Fl_Button *preview, *all, *undo, *reset;
  // the filter removes the wing branches of the raw MAT whole: the branches
  // that touch its free boundary and are seen under less than the angle
  Fl_Check_Button *branches, *angles;
  Fl_Value_Input *angle;
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
  // a parameter of the filter changed: filters again if it was filtered
  void update();
  // shows the raw MAT colored by the angle of its branches, or the filtered
  // MAT again, as the box says
  void showAngles();
  // the branch chosen in the list is shown alone
  void selectBranch();
  // shows what would extend the selected branch, without changing the MAT
  void previewBranch();
  // extends the selected branch, or all of them (the flat ones in their
  // plane, largest first, then the others by ribbons)
  void extendBranch(bool all);
  // takes back the last extension, or all of them (the filtered MAT again)
  void undoExtension(bool everything);

private:
  struct State;
  State *_state;
  bool _skin();
  void _say(int stage, const std::string &text, const std::string &more = "");
  void _view(int stage);
  void _listBranches(bool reset);
  bool _extend(int branch, bool planar, bool apply, std::string &what);
  void _forget(int fromStage);
  void _showOnly(int stage);
};

void midsurfacer_cb(Fl_Widget *w, void *data);

#endif

#endif
