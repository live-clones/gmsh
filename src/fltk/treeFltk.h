// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TREE_FLTK_H
#define TREE_FLTK_H

#include "GmshConfig.h"

#if defined(HAVE_FLTK)

#include <FL/Fl_Group.H>

#include "Form.h"

// The widget one line of the modules tree carries: the value itself, then
// the little buttons hung after it. The field is copied and kept: FLTK
// hands a widget a pointer when it calls back, and what it points at has
// to outlive the line.

Fl_Group *fltkTreeField(const Ui::Field &f, int x, int y, int w, int h,
                        double labelRatio, const Ui::Colour &highlight,
                        Fl_Color background);

// the tree is being built again: what was kept for the old lines may go
void fltkTreeForget();

#endif

#endif
