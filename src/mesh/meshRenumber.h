// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef _MESH_RENUMBER_
#define _MESH_RENUMBER_

#include <map>
#include <vector>

int meshRenumber_Vertices_RCMK(const std::vector<std::size_t> &elements,
                               std::map<std::size_t, std::size_t> &permutations);

int meshRenumber_Vertices_Hilbert(const std::vector<std::size_t> &elements,
                                  std::map<std::size_t, std::size_t> &permutations);

int meshRenumber_Vertices_Metis(const std::vector<std::size_t> &elementTags,
                                std::map<std::size_t, std::size_t> &permutations);

#endif
