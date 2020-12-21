// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_CONTEXT_WINDOW_H
#define ONELAB_CONTEXT_WINDOW_H

#include <vector>
#include <string>
#include <set>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Choice.H>

class onelabContextWindow {
private:
  int _width, _height;
  std::vector<char *> _toFree;
  std::vector<Fl_Widget *> _onelabWidgets;
  template <class T>
  void _addOnelabWidget(T &p, const std::string &pattern,
                        std::set<std::pair<std::string, Fl_Widget *>> &widgets);
  Fl_Choice *_choice;
  int _dim, _tag;
  std::string _name;
  std::vector<std::pair<int, std::string> > _physicals;

public:
  Fl_Window *win;

public:
  onelabContextWindow(int deltaFontSize = 0);
  ~onelabContextWindow() { Fl::delete_widget(win); }
  void show(int dim, int tag);
  void hide() { win->hide(); }
  void rebuild(bool deleteWidgets);
};


#endif
