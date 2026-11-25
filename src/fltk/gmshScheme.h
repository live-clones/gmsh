// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef GMSH_SCHEME_H
#define GMSH_SCHEME_H

#include <FL/Enumerations.H>

class Fl_Widget;
class Fl_Window;
class Fl_Menu_;

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
// the font, the boxes, the scrollbars and the hover
void applyGmshScheme();
// the width of the scrollbars of the theme: under 7 pixels, FLTK neither draws
// nor handles the arrow buttons at their ends, which nobody uses
const int gmshScrollbarSize = 6;
// the scrollbars and the menus of a window in the theme, called by the windows
// of Gmsh before they draw: Windows paints a new window as soon as it is shown,
// before the check callback that styles the others
void gmshStyleWidgets(Fl_Widget *w);
// an event handled with the hover of the scheme: the widget the pointer leaves
// and the one it enters are drawn again (see FlGui::_dispatch())
int gmshSchemeHandle(int event, Fl_Window *win);
// the colour of a widget drawing itself: highlighted while the pointer is over
// it and the scheme is on (the boxes of the widgets of FLTK get this on their
// own); and the highlight alone, for a part of a widget under the pointer
Fl_Color hoverHighlight(Fl_Widget *w, Fl_Color c);
Fl_Color hoverHighlight(Fl_Color c);
// the item under the pointer in a menu or a pull-down, and what a shortcut
// menu is shown with to get it (pass it to Fl_Menu_Item::popup())
Fl_Color gmshMenuHighlight();
const Fl_Menu_ *gmshPopupStyle();
// a colour chosen by the user, e.g. the highlight of a ONELAB parameter, often
// that of entities in the model: the background of a field (the colour itself,
// no brighter than the text in dark mode), or a text (as is in light mode, light
// in dark mode, in both cases changed as much as needed to read)
Fl_Color adaptedFill(Fl_Color c);
Fl_Color adaptedText(Fl_Color c);
// the colours of Gmsh itself, for a button that is on (the levels of a loop, a
// graph drawn, the mouse selection off, a query, a measurement), for the theme
enum GmshIndicator {
  IndicatorGreen,
  IndicatorBlue,
  IndicatorRed,
  IndicatorYellow
};
Fl_Color gmshIndicator(GmshIndicator i);

#endif
