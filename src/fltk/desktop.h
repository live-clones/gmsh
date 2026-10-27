// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DESKTOP_H
#define DESKTOP_H

#include <string>

// What the desktop says about itself, asked from the system

// the family of the font of the desktop interface, empty where the desktop
// does not say (on macOS and Windows the theme knows the font by name)
std::string desktopFont();

// 1 when the desktop is dark, 0 when light, -1 when it does not say
int desktopDark();

// calls back when the desktop switches between light and dark, where the
// system tells (macOS); elsewhere the switch is seen when a window gets the
// focus (see FlGui)
void watchDesktopAppearance(void (*changed)());

#endif
