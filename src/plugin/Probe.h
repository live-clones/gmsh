// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PROBE_H
#define PROBE_H

#include "Plugin.h"

class GMSH_ProbePlugin : public GMSH_PostPlugin {
  int _iview = 0; // the view of the preview

public:
  GMSH_ProbePlugin();
  std::string getName() const { return "Probe"; }
  std::string getShortHelp() const { return "Get value at point (X, Y, Z)"; }
  std::string getHelp() const;
  PView *execute(PView *);

  bool optionCallback(int iopt, int num, int action, double &value);
  void drawPreview(void *context);
};

#endif
