// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ICON_STROKES_H
#define ICON_STROKES_H

#include <string>

// The icons of the interfaces, by name: the strokes of each, in a 24 by 24
// box, two units wide with round ends, as the inside of an SVG (the colour
// put in when rendered, see icons.cpp for the FLTK interface, statusbar.mjs
// for the web page). The buttons of the status bar name theirs in the action
// registry (see Actions.h).
const char *IconStrokes(const std::string &name);

#endif
