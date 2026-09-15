// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FLTK_UI_SOURCES_H
#define FLTK_UI_SOURCES_H

#include "Backend.h"

// What this interface is given: the descriptions it builds from, handed
// to it once as it comes up. It is the only way anything here reaches the
// application. Named after the interface it belongs to, since every
// interface that was built is in the library at once and only one of them
// is running.

const Ui::Backend::Sources &fltkSources();
// and what the interface may call back
const Ui::Backend::Host &fltkHost();

#endif
