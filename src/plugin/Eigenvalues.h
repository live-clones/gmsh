// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EIGENVALUES_H
#define EIGENVALUES_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterEigenvaluesPlugin();
}

class GMSH_EigenvaluesPlugin : public GMSH_PostPlugin {
public:
  GMSH_EigenvaluesPlugin() {}
  std::string getName() const { return "Eigenvalues"; }
  std::string getShortHelp() const
  {
    return "Compute eigenvalues of a tensor view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
