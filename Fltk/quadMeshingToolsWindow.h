// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef QUADMESHINGTOOLS_WINDOW_H
#define QUADMESHINGTOOLS_WINDOW_H

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Choice.H>
#include <FL/Fl_Browser.H>
#include <FL/Fl_Multi_Browser.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Output.H>

class quadMeshingToolsWindow {
public:
  bool CAD, mesh, crossfield, H, uv, layout, quad;
  Fl_Window *win;
  Fl_Box *box;
  Fl_Check_Button *butt[4];
  Fl_Value_Input *value[12];
  Fl_Choice *choice[4];
  Fl_Button *push[2];
  Fl_Button *push_crossfield_gen;
  Fl_Button *push_crossfield_show;
  Fl_Button *push_compute_uv;
  Fl_Button *push_build_layout;
  Fl_Button *push_quad_generate;
  Fl_Button *push_quad_simplify;
  Fl_Button *push_quad_smooth;

public:
  quadMeshingToolsWindow(int deltaFontSize = 0);
  ~quadMeshingToolsWindow() { Fl::delete_widget(win); }
  void show(bool redrawOnly);
};

void quadmeshingtools_cb(Fl_Widget *w, void *data);

#endif
