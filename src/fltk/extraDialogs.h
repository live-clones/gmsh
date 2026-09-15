// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRA_DIALOGS_H
#define EXTRA_DIALOGS_H

#include <string>

// the two little windows the ONELAB range widgets of the module tree
// open

int simpleTextDisplay(const char *title, const std::string &text);
int simpleTextEditor(const char *title, const std::string &help,
                     std::string &text);

#endif
