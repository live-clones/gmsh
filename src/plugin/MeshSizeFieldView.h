// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FIELD_VIEW_H
#define FIELD_VIEW_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterMeshSizeFieldViewPlugin();
}

class GMSH_MeshSizeFieldViewPlugin : public GMSH_PostPlugin {
public:
  GMSH_MeshSizeFieldViewPlugin() {}
  std::string getName() const { return "MeshSizeFieldView"; }
  std::string getShortHelp() const
  {
    return "Evalue mesh size field on a view";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
