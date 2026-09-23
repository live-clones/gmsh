// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef LONGITUDELATITUDE_H
#define LONGITUDELATITUDE_H

#include "Plugin.h"

class GMSH_LongitudeLatitudePlugin : public GMSH_PostPlugin {
public:
  GMSH_LongitudeLatitudePlugin();
  std::string getName() const { return "LongitudeLatitude"; }
  std::string getShortHelp() const { return "Project in longitude-latitude"; }
  std::string getHelp() const;
  std::string getAuthor() const { return "J. Lambrechts"; }
  PView *execute(PView *);
};

#endif
