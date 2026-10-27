// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_SCHEME_H
#define GMSH_SCHEME_H

// The look of General.FltkTheme = "gmsh": the widgets of FLTK with the font
// of the desktop, a neutral palette, the buttons highlighted under the pointer,
// and no dashed rectangle on the focus
bool gmshScheme();
// the colours, light or dark
void applyGmshColors(bool dark);
// the font, the boxes and the hover
void applyGmshScheme();
// the colour of a widget drawing itself: highlighted while the pointer is over
// it and the scheme is on (the boxes of the widgets of FLTK get this on their
// own); and the highlight alone, for a part of a widget under the pointer
Fl_Color hoverHighlight(Fl_Widget *w, Fl_Color c);
Fl_Color hoverHighlight(Fl_Color c);

#endif
