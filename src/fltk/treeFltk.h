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

// The widget one line of the modules tree carries, made from what the
// description says the line holds: the value itself, then the little buttons
// hung after it -- the range of a number, its loop, the plots it is reported
// in, the menu of a file. It is the same shape the window this reproduces
// gives them, an input followed by three narrow buttons, said once instead of
// built into a widget of its own.
//
// The field is copied and kept: FLTK hands a widget a pointer when it calls
// back, and what it points at has to outlive the line.

Fl_Group *fltkTreeField(const Ui::Field &f, int x, int y, int w, int h,
                        double labelRatio, unsigned int highlight,
                        Fl_Color background);

// the tree is being built again: what was kept for the old lines may go
void fltkTreeForget();

#endif

#endif
