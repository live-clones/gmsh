// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FLTK_METRICS_H
#define FLTK_METRICS_H

#include <FL/Enumerations.H>

// What the windows of this interface are measured in: the width of an input,
// of a button, the height of a line, the border of a window, all from the
// size of the type. And the box types the windows draw themselves with.

#define GMSH_WINDOW_BOX FL_FLAT_BOX
#define GMSH_SIMPLE_RIGHT_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 1)
#define GMSH_SIMPLE_TOP_BOX (Fl_Boxtype)(FL_FREE_BOXTYPE + 2)

#define IW (10 * FL_NORMAL_SIZE) // input field width
#define BB (7 * FL_NORMAL_SIZE) // width of a button with internal label
#define BH (2 * FL_NORMAL_SIZE + 1) // button height
#define WB (5) // window border

#endif
