// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FILE_DIALOGS_H
#define FILE_DIALOGS_H

#include <string>

typedef enum {
  FILE_CHOOSER_SINGLE,
  FILE_CHOOSER_MULTI,
  FILE_CHOOSER_CREATE,
  FILE_CHOOSER_DIRECTORY
} FILE_CHOOSER_TYPE;

int fileChooser(FILE_CHOOSER_TYPE type, const char *message, const char *pat,
                const char *fname = nullptr);
std::string fileChooserGetName(int num);
int fileChooserGetFilter();
void fileChooserGetPosition(int *x, int *y);

#endif
