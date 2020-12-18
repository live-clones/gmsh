// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PHYSICAL_CONTEXT_WINDOW_H
#define PHYSICAL_CONTEXT_WINDOW_H

#include <string>
#include <map>
#include <set>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input_Choice.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Value_Input.H>
#include <FL/Fl_Choice.H>

struct widgetPtrLessThan {
  bool operator()(const Fl_Widget *w1, const Fl_Widget *w2) const
  {
    return strcmp(w1->label(), w2->label()) < 0;
  }
};

class physicalContextWindow {
private:
  int _width, _height;
  std::vector<char *> _toFree;
  std::vector<Fl_Widget *> _onelabWidgets;
  template <class T>
  void _addOnelabWidget(T &p, const std::string &pattern,
                        std::set<Fl_Widget *, widgetPtrLessThan> &widgets);

public:
  Fl_Window *win;
  Fl_Tabs *tab;
  Fl_Group *group[3];
  Fl_Box *box[3];
  Fl_Input_Choice *input[1];
  Fl_Check_Button *butt[1];
  Fl_Value_Input *value[1];
  Fl_Choice *choice[1];
  int selectedTag;
  std::string type, mode, selectedName;
  bool append;
  std::map<int, std::string> physicalTags;
  std::map<std::string, int> physicalNames;

public:
  physicalContextWindow(int deltaFontSize = 0);
  ~physicalContextWindow() { Fl::delete_widget(win); }
  void show(const std::string &what, bool remove);
  void hide() { win->hide(); }
  void updateOnelabWidgets(bool deleteWidgets);
};

#endif
