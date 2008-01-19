#ifndef _MFACE_HASH_H_
#define _MFACE_HASH_H_

#include "MFace.h"
#include "Hash.h"

struct Hash_Face : public std::unary_function<MFace, size_t> {
  size_t operator()(const MFace &f) const
  {
    const MVertex *v[4];
    f.getOrderedVertices(v);
    return HashFNV1a<sizeof(MVertex*[4])>::eval(v);
  }
};

#endif
