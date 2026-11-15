// Gmsh Discrete CAD Modeler - Copyright (C) 2026 C. Geuzaine and J.-F. Remacle
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

#ifndef DISCRETE_CAD_WINDING_PLUGIN_H
#define DISCRETE_CAD_WINDING_PLUGIN_H

#include "Plugin.h"

// Plugin(WindingNumber): the inside and the outside of the triangles of
// surfaces (a soup, with holes, gaps and overlaps), or of one of their
// connected pieces, seen through their generalized winding number (see
// DiscreteCADWinding.h): its maps on planes, and the surface where it is 1/2
class GMSH_WindingNumberPlugin : public GMSH_PostPlugin {
public:
  GMSH_WindingNumberPlugin();
  std::string getName() const { return "WindingNumber"; }
  std::string getShortHelp() const
  {
    return "Inside and outside of triangles through their winding number";
  }
  std::string getHelp() const;
  std::string getAuthor() const { return "J.-F. Remacle"; }
  std::string getCopyright() const
  {
    return "C. Geuzaine, J.-F. Remacle (GNU Affero General Public License)";
  }
  PView *execute(PView *);
};

#endif
