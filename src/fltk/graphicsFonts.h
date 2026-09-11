// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GRAPHICS_FONTS_H
#define GRAPHICS_FONTS_H

#include <FL/Fl_Menu_Item.H>

// The fonts the scene can be drawn in, by the name an option gives them and by
// the FLTK enum that draws them. The names are the ones General.GraphicsFont
// takes, and the option window offers the same list.

#define NUM_FONTS 15
extern Fl_Menu_Item menu_font_names[];

#endif
