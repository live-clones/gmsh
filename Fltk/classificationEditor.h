// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CLASSIFICATION_EDITOR_H_
#define _CLASSIFICATION_EDITOR_H_

#include <vector>
#include <set>
#include <FL/Fl_Window.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include "GModel.h"
#include "MElement.h"
#include "meshGFaceOptimize.h"

#define CLASS_BUTTON_SELECT_ELEMENTS       0
#define CLASS_BUTTON_SELECT_ALL_ELEMENTS   1
#define CLASS_BUTTON_DELETE_FROM_SELECTION 2
#define CLASS_BUTTON_RESET_SELECTION       3
#define CLASS_BUTTON_SELECT_SURFACES       4
#define CLASS_BUTTON_SELECT_ALL_SURFACES   5
#define CLASS_BUTTON_CLASSIFY              6

#define CLASS_TOGGLE_HIDE                  0
#define CLASS_TOGGLE_BOUNDARY              1
#define CLASS_TOGGLE_SHOW_ONLY_EDGES       2

#define CLASS_VALUE_ANGLE                  0

class classificationEditor {
 public:
  std::vector<MTriangle*> elements;
  std::set<GFace*> faces;
  Fl_Window *window;
  Fl_Button *buttons[10];
  Fl_Check_Button *toggles[10];
  Fl_Value_Input *inputs[10];
  GEdge *selected;
  std::vector<edge_angle> edges_detected, edges_lonly;
  classificationEditor();
  void show(){ window->show(); }
};

void mesh_classify_cb(Fl_Widget* w, void* data);

#endif
