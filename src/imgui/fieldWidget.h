// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMGUI_FIELD_WIDGET_H
#define IMGUI_FIELD_WIDGET_H

#include "Form.h"

// One described field, drawn where the cursor is. It is what a pane of a form
// is made of, and it is also what a line of the tree carries when the line
// stands for a value rather than for a command -- one routine, so that a
// parameter looks the same wherever it is shown.

void drawField(const Ui::Field &f, float width);

#endif
