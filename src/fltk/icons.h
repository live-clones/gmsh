// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ICONS_H
#define ICONS_H

class Fl_Widget;

// Icons drawn as SVG strokes, in the style of the desktop
// environments, rendered at the
// size asked in the label colour of the widget, in every theme. A widget given
// one keeps it through the changes of colours; a null name takes it off.
// Names: sidebar, models, quick, cube, rotate, loop, query, measure, rewind,
// back, play, pause, forward, gear, search, graph, eye.
void gmshIcon(Fl_Widget *w, const char *name, int size);
// the icon of a widget drawn again, after a change of its label colour
void gmshIconRecolor(Fl_Widget *w);
// the icons drawn again in the colours in place
void gmshIconsRecolor();

#endif
