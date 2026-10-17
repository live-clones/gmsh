// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MEDGE_HASH_H
#define MEDGE_HASH_H

#include "MEdge.h"
#include "Hash.h"

struct MEdgeHash {
  size_t operator()(const MEdge &e) const
  {
    std::size_t h = e.getMinVertex()->getNum() * 0x9e3779b97f4a7c15ull +
                    e.getMaxVertex()->getNum();
    return HashMix(h);
  }
};

#endif
