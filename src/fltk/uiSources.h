// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FLTK_UI_SOURCES_H
#define FLTK_UI_SOURCES_H

#include "Backend.h"

// What this interface is given: the descriptions it builds from, handed to it
// once as it comes up. It is the only way anything here reaches the
// application, and it is why no file of this directory has to include a
// header of Gmsh to know what a form or a menu says.
//
// Named after the interface it belongs to, since every interface that was
// built is in the library at once now and only one of them is running.

const Ui::Backend::Sources &fltkSources();

// What a form is made of, by the FormRef the backend handed out for it: the
// description is read again every time it is asked, as the contract says.
// An empty function for a form nobody handed out.
const std::function<Ui::Form()> &fltkFormDescription(Ui::FormRef form);

#endif
