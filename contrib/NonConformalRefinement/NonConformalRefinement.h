// Gmsh Non-Conformal Refinement Plugin - Copyright (C) 2026 C. Geuzaine and
// J.-F. Remacle
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
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

#ifndef NON_CONFORMAL_REFINEMENT_H
#define NON_CONFORMAL_REFINEMENT_H

#include <string>
#include "Plugin.h"

class GMSH_NonConformalRefinementPlugin : public GMSH_MeshPlugin {
public:
  GMSH_NonConformalRefinementPlugin();
  std::string getName() const { return "NonConformalRefinement"; }
  std::string getShortHelp() const
  { return "Refine the mesh non-conformally, with polytopes at hanging nodes"; }
  std::string getHelp() const;
  int run();
};

#endif
