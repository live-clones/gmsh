// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef IMGUI_UI_SOURCES_H
#define IMGUI_UI_SOURCES_H

#include "Backend.h"

// the descriptions this interface builds from, handed to it once; named after
// the interface, since every one built is in the library at once

const Ui::Backend::Sources &imguiSources();

#endif
