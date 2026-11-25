// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
// See LICENSE.txt in the Gmsh root directory for license information.

#ifndef GMSH_MAT_GMSH_PLUGIN_H
#define GMSH_MAT_GMSH_PLUGIN_H

#include "Plugin.h"

class GMSH_MatGmshPlugin : public GMSH_PostPlugin {
public:
  GMSH_MatGmshPlugin();
  std::string getName() const { return "MatGmsh"; }
  std::string getShortHelp() const
  {
    return "Filtered MAT, optional projection and free-boundary extension";
  }
  std::string getHelp() const;
  PView *execute(PView *);
};

#endif
