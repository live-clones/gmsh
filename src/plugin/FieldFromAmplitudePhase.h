// Gmsh - Copyright (C) 1997-2025 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FIELD_FROM_AMPLITUDE_PHASE_H
#define FIELD_FROM_AMPLITUDE_PHASE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterFieldFromAmplitudePhasePlugin();
}

class GMSH_FieldFromAmplitudePhasePlugin : public GMSH_PostPlugin {
public:
  GMSH_FieldFromAmplitudePhasePlugin() {}
  std::string getName() const { return "FieldFromAmplitudePhase"; }
  std::string getShortHelp() const
  {
    return "Compute field from amplitude and phase";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
