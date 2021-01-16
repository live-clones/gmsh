// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MFACE_HASH_H
#define MFACE_HASH_H

#include "MFace.h"
#include "Hash.h"

struct MFaceHash : public std::unary_function<MFace, size_t> {
  size_t operator()(const MFace &f) const
  {
    size_t v[4] = {0, 0, 0, 0};
    for(size_t i = 0; i < f.getNumVertices(); i++) {
      v[i] = f.getSortedVertex(i)->getNum();
    }
    return HashFNV1a<sizeof(size_t[4])>::eval(v);
  }
};

#endif
