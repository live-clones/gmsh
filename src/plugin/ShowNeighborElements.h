// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SHOWNEIGHBORELEMENTS_H
#define SHOWNEIGHBORELEMENTS_H

#include "Plugin.h"
#include <set>

class MVertex;

class GMSH_ShowNeighborElementsPlugin : public GMSH_PostPlugin {
public:
  GMSH_ShowNeighborElementsPlugin();
  std::string getName() const { return "ShowNeighborElements"; }
  std::string getShortHelp() const
  {
    return "Show some elements and the layers of elements around them";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "Amaury Johnen"; }
  PView *execute(PView *);
};

#endif
