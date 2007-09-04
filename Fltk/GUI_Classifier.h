#ifndef _GUI_CLASSIFIER_H_
#define _GUI_CLASSIFIER_H_

#include "GmshUI.h"
#include "GModel.h"
#include "MElement.h"
#include "GUI.h"
#include "Shortcut_Window.h"
#include "ColorTable.h"
#include <FL/Fl_Toggle_Button.H>
#include <FL/Fl_Round_Button.H>
#include <vector>

void class_select_cb(Fl_Widget *w, void *data);
void class_selectgface_cb(Fl_Widget *w, void *data);
void class_save_cb(Fl_Widget *w, void *data);
void class_clear_cb(Fl_Widget *w, void *data);
void class_deleteedge_cb(Fl_Widget *w, void *data);
void class_color_cb(Fl_Widget *w, void *data);

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
  edge_angle ( MVertex *_v1, MVertex *_v2, MTriangle *t1, MTriangle *t2);
  bool operator < (const edge_angle & other) const
  {
    return other.angle < angle;
  }  
};

class classificationEditor {
 public:
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
};
#endif
