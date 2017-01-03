// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#ifndef _EXTRA_DIALOGS_H_
#define _EXTRA_DIALOGS_H_

#include <string>

int arrowEditor(const char *title, double &a, double &b, double &c);

std::string connectionChooser();
std::string patternChooser();

int cgnsImport();

#endif
