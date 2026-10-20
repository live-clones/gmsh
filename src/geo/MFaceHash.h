// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef MFACE_HASH_H
#define MFACE_HASH_H

#include "MFace.h"
#include "Hash.h"

struct MFaceHash {
  size_t operator()(const MFace &f) const
  {
    std::size_t h = f.getNumVertices();
    for(std::size_t i = 0; i < f.getNumVertices(); i++)
      h = HashCombine(h, f.getSortedVertex(i)->getNum());
    return HashMix(h);
  }
};

#endif
