// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LAMBDA2_H
#define LAMBDA2_H

#include "Plugin.h"

class GMSH_Lambda2Plugin : public GMSH_PostPlugin {
public:
  GMSH_Lambda2Plugin();
  std::string getName() const { return "Lambda2"; }
  std::string getShortHelp() const { return "Detect vortices"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "E. Marchandise"; }
  PView *execute(PView *);
};

#endif
