// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRA_DIALOGS_H
#define EXTRA_DIALOGS_H

#include <functional>
#include <string>

class Fl_Widget;
class Fl_Window;

// A modal dialog shown until OK, which calls apply() and returns 1, or Cancel
// or the close button, which return 0 (ok and cancel may be null); other(o)
// is told first of every widget whose callback ran
int runDialog(Fl_Window *window, Fl_Widget *ok, Fl_Widget *cancel,
              const std::function<void()> &apply,
              const std::function<void(Fl_Widget *)> &other = nullptr);

int arrowEditor(const char *title, double &a, double &b, double &c);

std::string connectionChooser();
std::string patternChooser();

int simpleTextDisplay(const char *title, const std::string &text);
int simpleTextEditor(const char *title, const std::string &help,
                     std::string &text);

#endif
