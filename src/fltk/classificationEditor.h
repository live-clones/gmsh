// Gmsh - Copyright (C) 1997-2023 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CLASSIFICATION_EDITOR_H
#define CLASSIFICATION_EDITOR_H

#include <vector>
#include <set>
#include <FL/Fl_Window.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include "GmshConfig.h"
#include "GModel.h"
#include "MElement.h"

#if defined(HAVE_MESH)
#include "meshGFaceOptimize.h"
#endif

#define CLASS_BUTTON_SELECT_ELEMENTS 0
#define CLASS_BUTTON_SELECT_ALL_ELEMENTS 1
#define CLASS_BUTTON_DELETE_FROM_SELECTION 2
#define CLASS_BUTTON_RESET_SELECTION 3
#define CLASS_BUTTON_SELECT_SURFACES 4
#define CLASS_BUTTON_SELECT_ALL_SURFACES 5
#define CLASS_BUTTON_CLASSIFY 6

#define CLASS_TOGGLE_HIDE 0
#define CLASS_TOGGLE_BOUNDARY 1
#define CLASS_TOGGLE_SHOW_ONLY_EDGES 2
#define CLASS_TOGGLE_ENSURE_PARAMETRIZABLE_SURFACES 3

#define CLASS_VALUE_ANGLE 0

class classificationEditor {
public:
  std::vector<MElement *> elements;
  Fl_Window *window;
  Fl_Button *buttons[7];
  Fl_Check_Button *toggles[4];
  Fl_Value_Input *inputs[1];
  GEdge *selected;
#if defined(HAVE_MESH)
  std::vector<edge_angle> edges_detected, edges_lonly;
#else
  std::vector<double> edges_detected, edges_lonly;
#endif
  classificationEditor();
  void show() { window->show(); }
};

void mesh_classify_cb(Fl_Widget *w, void *data);

#endif
