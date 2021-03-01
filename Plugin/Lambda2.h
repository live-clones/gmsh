// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LAMBDA2_H
#define LAMBDA2_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterLambda2Plugin();
}

class GMSH_Lambda2Plugin : public GMSH_PostPlugin {
public:
  GMSH_Lambda2Plugin() {}
  std::string getName() const { return "Lambda2"; }
  std::string getShortHelp() const { return "Detect vortices"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "E. Marchandise"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
