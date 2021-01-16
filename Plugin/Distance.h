// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef DISTANCE_H
#define DISTANCE_H

#include <string>
#include "Plugin.h"
#include "MVertex.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterDistancePlugin();
}

class GMSH_DistancePlugin : public GMSH_PostPlugin {
private:
  int _maxDim;
  PViewDataList *_data;

public:
  GMSH_DistancePlugin();
  std::string getName() const { return "Distance"; }
  std::string getShortHelp() const { return "Compute distance to boundaries"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "E. Marchandise"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
  void printView(std::vector<GEntity *> &entities,
                 std::map<MVertex *, double> &distance_map);
};

#endif
