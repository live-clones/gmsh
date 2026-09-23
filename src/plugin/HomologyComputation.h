// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s): Matti Pellikka (initial implementation)

#ifndef HOMOLOGY_COMPUTATION_H
#define HOMOLOGY_COMPUTATION_H

#include <string>
#include "Plugin.h"

class GMSH_HomologyComputationPlugin : public GMSH_PostPlugin {
public:
  GMSH_HomologyComputationPlugin();
  std::string getName() const { return "HomologyComputation"; }
  std::string getShortHelp() const
  {
    return "Compute relative (co)homology spaces";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "M. Pellikka"; }
  PView *execute(PView *);
};

#endif
