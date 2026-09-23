// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef HARMONIC_TO_TIME_H
#define HARMONIC_TO_TIME_H

#include "Plugin.h"

class GMSH_HarmonicToTimePlugin : public GMSH_PostPlugin {
public:
  GMSH_HarmonicToTimePlugin();
  std::string getName() const { return "HarmonicToTime"; }
  std::string getShortHelp() const
  {
    return "Transform harmonic data into time domain data";
  }
  std::string getHelp() const;
  PView *execute(PView *);
};

#endif
