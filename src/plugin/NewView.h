// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef NEWVIEW_H
#define NEWVIEW_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterNewViewPlugin();
}

class GMSH_NewViewPlugin : public GMSH_PostPlugin {
public:
  GMSH_NewViewPlugin() {}
  std::string getName() const { return "NewView"; }
  std::string getShortHelp() const
  {
    return "Create an empty new view from a mesh";
  }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);

private:
  void nodeData(int numComp, double value,
                std::map<int, std::vector<double> > &d);
  void elementData(int numComp, double value,
                   std::map<int, std::vector<double> > &d, int phys);
};

#endif
