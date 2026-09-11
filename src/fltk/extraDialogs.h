// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRA_DIALOGS_H
#define EXTRA_DIALOGS_H

#include <string>

// What is left of the little windows this file used to hold: the ones that
// belong to a widget rather than to the application. The chooser of one
// option, the arrow editor and the two command choosers are described once in
// src/common/GuiPrompts.cpp now and built by both interfaces; these two are
// opened by the ONELAB range widgets of the FLTK module tree, which is FLTK's
// own and has no counterpart to share them with.

int simpleTextDisplay(const char *title, const std::string &text);
int simpleTextEditor(const char *title, const std::string &help,
                     std::string &text);

#endif
