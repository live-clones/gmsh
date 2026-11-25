// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_PARAMETERS_H
#define ONELAB_PARAMETERS_H

#include <list>
#include <string>
#include <FL/Fl.H>
#include "onelab.h"

// The widgets of the ONELAB parameters, in the tree of the FLTK graphical user
// interface and in the context window of an entity (onelabContextWindow.cpp):
// a number as a check box, a choice, a range or an output, a string as an
// input, a choice, a button or a file. Each sets its parameter and does what
// the parameter asks for next (see onelabUtils::setParameter()).

// the colour a parameter is highlighted in ("Highlight" attribute: 1, or a
// colour by name or value); false if none
bool getParameterColor(const std::string &str, Fl_Color &c);
// the widget of a parameter, of width ww and height hh at (xx, yy), its
// label taking labelRatio of the width, highlighted in c on bgc or not; the
// strings the widget shows are kept in strings
Fl_Widget *addParameterWidget(onelab::number &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings);
Fl_Widget *addParameterWidget(onelab::string &p, int xx, int yy, int ww, int hh,
                              double labelRatio, const std::string &ppath,
                              bool highlight, Fl_Color c, Fl_Color bgc,
                              std::list<std::string> &strings);

#endif
