// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MODULUS_PHASE_H
#define MODULUS_PHASE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterModulusPhasePlugin();
}

class GMSH_ModulusPhasePlugin : public GMSH_PostPlugin {
public:
  GMSH_ModulusPhasePlugin() {}
  std::string getName() const { return "ModulusPhase"; }
  std::string getShortHelp() const
  {
    return "Compute modulus/phase of a complex view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
