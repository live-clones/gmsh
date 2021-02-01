// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef SUMMATION_H
#define SUMMATION_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterSummationPlugin();
}

class GMSH_SummationPlugin : public GMSH_PostPlugin {
public:
  GMSH_SummationPlugin() {}
  std::string getName() const { return "Summation"; }
  std::string getShortHelp() const
  {
    return "Create a view by summing different views (TimeStep per TimeStep "
           "and Component by Component)";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
