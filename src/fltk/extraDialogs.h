// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRA_DIALOGS_H
#define EXTRA_DIALOGS_H

#include <string>

int arrowEditor(const char *title, double &a, double &b, double &c);

std::string connectionChooser();
std::string patternChooser();

int cgnsImport();

#endif
