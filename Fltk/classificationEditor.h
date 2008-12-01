// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _CLASSIFICATION_EDITOR_H_
#define _CLASSIFICATION_EDITOR_H_

#include <vector>
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include "shortcutWindow.h"
#include "GModel.h"
#include "MElement.h"
#include "ColorTable.h"

#define CLASSBUTTON_SELECT   0
#define CLASSBUTTON_DEL      1
#define CLASSBUTTON_ADD      2
#define CLASSBUTTON_CLEAR    3
#define CLASSBUTTON_OK       4
#define CLASSBUTTON_COLOR    5
#define CLASSBUTTON_SELFAC   6
#define CLASSTOGBUTTON_HIDE  0
#define CLASSTOGBUTTON_CLOS  1
#define CLASSVALUE_ANGLE     0

class edge_angle
{
 public :
  MVertex *v1, *v2;
  double angle;
  edge_angle ( MVertex *_v1, MVertex *_v2, MElement *t1, MElement *t2);
  bool operator < (const edge_angle & other) const
  {
    return other.angle < angle;
  }  
};

class classificationEditor {
 public:
  double op[10];
  std::vector<MTriangle*> _elements;
  std::set<GFace*> _faces;
  Fl_Window *_window;
  Fl_Button *_buttons[10];
  Fl_Toggle_Button *_togbuttons[10];
  Fl_Value_Input *_inputs[10];
  GEdge *temporary;
  GEdge *saved;
  std::list<GFace *> tempFaces;
  std::vector<edge_angle> edges_detected;
  std::vector<edge_angle> edges_lonly;
  classificationEditor();
  void show(){ _window->show();}
  std::vector<MTriangle*> &getElements() { return _elements; }
  Fl_Group *edge_detec, *face_color, *reverse_eng;
};

void mesh_classify_cb(Fl_Widget* w, void* data);

#endif
