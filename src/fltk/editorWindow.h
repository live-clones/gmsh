// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

#include <string>

// A file edited: in the editor of the FLTK graphical user interface if
// General.TextEditor is empty (the words of the .geo and .pro languages in
// color), with the command it gives otherwise
void editFile(const std::string &fileName);

#endif
