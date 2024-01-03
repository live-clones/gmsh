// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef TRANSFORM_H
#define TRANSFORM_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterTransformPlugin();
}

class GMSH_TransformPlugin : public GMSH_PostPlugin {
public:
  GMSH_TransformPlugin() {}
  std::string getName() const { return "Transform"; }
  std::string getShortHelp() const
  {
    return "Apply simple geometrical transformation";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
