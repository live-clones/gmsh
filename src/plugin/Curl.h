// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CURL_H
#define CURL_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterCurlPlugin();
}

class GMSH_CurlPlugin : public GMSH_PostPlugin {
public:
  GMSH_CurlPlugin() {}
  std::string getName() const { return "Curl"; }
  std::string getShortHelp() const
  {
    return "Compute the curl of a vector view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
