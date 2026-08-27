// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef ONELAB_WIDGETS_H
#define ONELAB_WIDGETS_H

#include "GmshConfig.h"

#if defined(HAVE_IMGUI) && defined(HAVE_ONELAB)

#include <map>
#include <string>

#include "onelab.h"

// The widget for one ONELAB parameter, shared by the module tree and by the
// per-entity context panel. Returns true when the user changed the value; the
// caller is responsible for pushing it back to the server.
//
// The kind of widget follows what the parameter declares: an enumeration with
// named values becomes a combo, a 0/1 choice a check box, a bounded number a
// slider, anything else a numeric field.
bool drawOnelabNumber(onelab::number &p);

// edits holds the text being typed, keyed by parameter name, so that the value
// read back from the server does not fight the keyboard
bool drawOnelabString(onelab::string &p,
                      std::map<std::string, std::string> &edits);

// the label of a parameter, without its path and without the digits ONELAB uses
// to order things
std::string onelabLabel(const onelab::parameter &p);

#endif

#endif
