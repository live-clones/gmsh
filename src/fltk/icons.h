// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ICONS_H
#define ICONS_H

class Fl_Widget;

// Icons drawn as SVG strokes, in the style of the desktops, rendered at the
// size asked in the foreground colour: the status bar and the tools under the
// gmsh theme (the symbols of FLTK otherwise). A widget given one keeps it
// through the changes of colours. Names: sidebar, models, quick, rotate,
// query, measure, rewind, back, play, pause, forward, gear, search.
void gmshIcon(Fl_Widget *w, const char *name, int size);
// the icons drawn again in the colours in place
void gmshIconsRecolor();

#endif
