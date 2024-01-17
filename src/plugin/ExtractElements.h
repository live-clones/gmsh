// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef EXTRACT_ELEMENTS_H
#define EXTRACT_ELEMENTS_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterExtractElementsPlugin();
}

class GMSH_ExtractElementsPlugin : public GMSH_PostPlugin {
public:
  GMSH_ExtractElementsPlugin() {}
  std::string getName() const { return "ExtractElements"; }
  std::string getShortHelp() const
  {
    return "Extract elements in given value range";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
