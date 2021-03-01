// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef BUBBLES_H
#define BUBBLES_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterBubblesPlugin();
}

class GMSH_BubblesPlugin : public GMSH_PostPlugin {
public:
  GMSH_BubblesPlugin() {}
  std::string getName() const { return "Bubbles"; }
  std::string getShortHelp() const
  {
    return "Create bubbles from triangulation";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
