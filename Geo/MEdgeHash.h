// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues

#ifndef _MEDGE_HASH_H_
#define _MEDGE_HASH_H_

#include "MEdge.h"
#include "Hash.h"

struct Hash_Edge : public std::unary_function<MEdge, size_t> {
  size_t operator()(const MEdge &e) const
  {
    const MVertex *v[2];
    v[0] = e.getMinVertex();
    v[1] = e.getMaxVertex();
    return HashFNV1a<sizeof(MVertex * [2])>::eval(v);
  }
};

#endif
