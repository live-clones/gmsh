// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRA_DIALOGS_H
#define EXTRA_DIALOGS_H

#include <string>

// ask for one option in a window of its own: the toolbar of the graphic window
// opens it on the buttons that take a value
double numberOrStringOptionChooser(const std::string &category, int index,
                                   const std::string &name, bool isNumber,
                                   const std::string &title = "",
                                   bool isInteractive = false,
                                   double minimum = 0., double maximum = 0.,
                                   double step = 0.);

int arrowEditor(const char *title, double &a, double &b, double &c);

std::string connectionChooser();
std::string patternChooser();

int cgnsImport();

int simpleTextDisplay(const char *title, const std::string &text);
int simpleTextEditor(const char *title, const std::string &help,
                     std::string &text);

#endif
