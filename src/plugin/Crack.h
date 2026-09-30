// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CRACK_H
#define CRACK_H

#include "Plugin.h"

class GMSH_CrackPlugin : public GMSH_PostPlugin {
public:
  GMSH_CrackPlugin();
  std::string getName() const { return "Crack"; }
  std::string getShortHelp() const { return "Crack generator"; }
  std::string getHelp() const;
  PView *execute(PView *);
};

#endif
