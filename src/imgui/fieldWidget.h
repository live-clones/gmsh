// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMGUI_FIELD_WIDGET_H
#define IMGUI_FIELD_WIDGET_H

#include "Form.h"

// one described field, drawn where the cursor is: for the panes and for the
// lines of the tree

void drawField(const Ui::Field &f, float width);

#endif
