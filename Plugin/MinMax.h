// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MIN_MAX_H
#define MIN_MAX_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterMinMaxPlugin();
}

class GMSH_MinMaxPlugin : public GMSH_PostPlugin {
public:
  GMSH_MinMaxPlugin() {}
  std::string getName() const { return "MinMax"; }
  std::string getShortHelp() const { return "Get the min/max of a dataset"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
