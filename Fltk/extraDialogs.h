// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _EXTRA_DIALOGS_H_
#define _EXTRA_DIALOGS_H_

#include <string>

int arrowEditor(const char *title, double &a, double &b, double &c);
int perspectiveEditor();
int meshSizeEditor();

int modelChooser();
std::string connectionChooser();
std::string patternChooser();

#endif
