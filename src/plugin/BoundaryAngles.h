// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BOUNDARY_ANGLES_H
#define BOUNDARY_ANGLES_H

#include "Plugin.h"

class GMSH_BoundaryAnglesPlugin : public GMSH_PostPlugin {
public:
  GMSH_BoundaryAnglesPlugin();
  std::string getName() const { return "BoundaryAngles"; }
  std::string getShortHelp() const
  {
    return "Compute angles on boundaries of 2D surface meshes";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Bertrand Thierry"; }
  PView *execute(PView *);
};

#endif
