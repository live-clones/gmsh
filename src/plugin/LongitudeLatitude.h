// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LONGITUDELATITUDE_H
#define LONGITUDELATITUDE_H

#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterLongituteLatitudePlugin();
}

class GMSH_LongituteLatitudePlugin : public GMSH_PostPlugin {
public:
  std::string getName() const { return "LongitudeLatitude"; }
  std::string getShortHelp() const { return "Project in longitude-latitude"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "J. Lambrechts"; }
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  PView *execute(PView *);
};

#endif
