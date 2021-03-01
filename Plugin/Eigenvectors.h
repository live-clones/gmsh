// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EIGENVECTORS_H
#define EIGENVECTORS_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterEigenvectorsPlugin();
}

class GMSH_EigenvectorsPlugin : public GMSH_PostPlugin {
public:
  GMSH_EigenvectorsPlugin() {}
  std::string getName() const { return "Eigenvectors"; }
  std::string getShortHelp() const
  {
    return "Compute eigenvectors of a tensor view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
