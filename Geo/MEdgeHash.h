// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MEDGE_HASH_H
#define MEDGE_HASH_H

#include "MEdge.h"
#include "Hash.h"

struct MEdgeHash : public std::unary_function<MEdge, size_t> {
  size_t operator()(const MEdge &e) const
  {
    size_t v[2] = {e.getMinVertex()->getNum(), e.getMaxVertex()->getNum()};
    return HashFNV1a<sizeof(size_t[2])>::eval(v);
  }
};

#endif
