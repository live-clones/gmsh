// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef INVISIBLE_H
#define INVISIBLE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterInvisiblePlugin();
}

class GMSH_InvisiblePlugin : public GMSH_PostPlugin {
public:
  GMSH_InvisiblePlugin() {}
  std::string getName() const { return "Invisible"; }
  std::string getShortHelp() const
  {
    return "Act on invisible elements in the current model";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
