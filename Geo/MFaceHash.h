// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MFACE_HASH_H
#define MFACE_HASH_H

#include "MFace.h"
#include "Hash.h"

struct Hash_Face : public std::unary_function<MFace, size_t> {
  size_t operator()(const MFace &f) const
  {
    const MVertex *v[4] = {0, 0, 0, 0};
    f.getOrderedVertices(v);
    return HashFNV1a<sizeof(MVertex * [4])>::eval(v);
  }
};

#endif
