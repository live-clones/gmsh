// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <IffTools.hxx>

namespace IFF{
  namespace visu{
    int framefield(const std::map<Element *, std::vector<std::vector<double>>> &mapElemDir, const std::string & nameView="Frame field", int visible=0);
  }
}
