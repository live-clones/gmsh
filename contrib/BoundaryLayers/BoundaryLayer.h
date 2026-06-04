// Gmsh Boundary Layer Plugin - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
//
// This program is free software: you can redistribute it and/or modify it under
// the terms of the GNU Affero General Public License as published by the Free
// Software Foundation, either version 3 of the License, or (at your option) any
// later version.
//
// This program is distributed in the hope that it will be useful, but WITHOUT
// ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
// FOR A PARTICULAR PURPOSE.  See the GNU Affero General Public License for more
// details.
//
// You should have received a copy of the GNU Affero General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef BOUNDARY_LAYER_H
#define BOUNDARY_LAYER_H

#include <list>
#include <string>
#include "Plugin.h"

extern "C" {
GMSH_Plugin *GMSH_RegisterBoundaryLayerPlugin();
}

class GMSH_BoundaryLayerPlugin : public GMSH_PostPlugin {
  std::string parse(std::string str, std::list<int> &physical);
public:
  GMSH_BoundaryLayerPlugin() {}
  std::string getName() const { return "BoundaryLayer"; }
  std::string getShortHelp() const { return "Create boundary layer meshes"; }
  std::string getHelp() const;
  int getNbOptions() const;
  StringXNumber *getOption(int iopt);
  int getNbOptionsStr() const;
  StringXString *getOptionStr(int iopt);
  PView *execute(PView *);
};

#endif
