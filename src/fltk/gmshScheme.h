// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_SCHEME_H
#define GMSH_SCHEME_H

#include <FL/Enumerations.H>

class Fl_Widget;

// The look of General.FltkTheme = "gmsh": the widgets of FLTK with the font
// of the desktop, a neutral palette, the buttons highlighted under the pointer,
// and no dashed rectangle on the focus
bool gmshScheme();
// the pixels the theme adds to the window border and to the button height
int gmshAir();
// the colours, light or dark
void applyGmshColors(bool dark);
// the colour of the accents the theme draws itself (the bar of the chosen tab,
// the markers of the dock): brighter than the selection of the lists, which
// stays muted (the selection colour of FLTK when the theme is off)
Fl_Color gmshAccent();
// the font, the boxes and the hover
void applyGmshScheme();
// the colour of a widget drawing itself: highlighted while the pointer is over
// it and the scheme is on (the boxes of the widgets of FLTK get this on their
// own); and the highlight alone, for a part of a widget under the pointer
Fl_Color hoverHighlight(Fl_Widget *w, Fl_Color c);
Fl_Color hoverHighlight(Fl_Color c);

#endif
