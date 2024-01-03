// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CURVEDBNDDIST_H
#define CURVEDBNDDIST_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterCurvedBndDistPlugin();
}

class GMSH_CurvedBndDistPlugin : public GMSH_PostPlugin {
public:
  GMSH_CurvedBndDistPlugin() {}
  std::string getName() const { return "CurvedBndDist"; }
  std::string getShortHelp() const
  {
    return "Compute distance to curved boundary";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Jonathan Lambrechts"; }
  PView *execute(PView *);
};
#endif
