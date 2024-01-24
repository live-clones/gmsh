// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRACT_EDGES_H
#define EXTRACT_EDGES_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterExtractEdgesPlugin();
}

class GMSH_ExtractEdgesPlugin : public GMSH_PostPlugin {
public:
  GMSH_ExtractEdgesPlugin() {}
  std::string getName() const { return "ExtractEdges"; }
  std::string getShortHelp() const
  {
    return "Extract sharp edges from triangular mesh";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
