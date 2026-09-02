// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMGUI_UI_SOURCES_H
#define IMGUI_UI_SOURCES_H

#include "Backend.h"

// What this interface is given: the descriptions it builds from, handed to it
// once as it comes up. It is the only way anything here reaches the
// application, and it is why no file of this directory has to include a
// header of Gmsh to know what a form or a menu says.
//
// Named after the interface it belongs to, since every interface that was
// built is in the library at once now and only one of them is running.

const Ui::Backend::Sources &imguiSources();

#endif
