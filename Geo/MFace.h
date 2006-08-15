#ifndef _MFACE_H_
#define _MFACE_H_

#include "MVertex.h"
#include "SVector3.h"
#include "Numeric.h"

class MFace {
 private:
  MVertex *_v[4];
 public:
  MFace(MVertex *v0, MVertex *v1, MVertex *v2, MVertex *v3=0) 
  {
    _v[0] = v0; _v[1] = v1; _v[2] = v2; _v[3] = v3;
  }
  inline int getNumVertices() const { return _v[3] ? 4 : 3; }
  inline MVertex *getVertex(int i) const { return _v[i]; }
  SVector3 normal()
  {
    double n[3];
    normal3points(_v[0]->x(), _v[0]->y(), _v[0]->z(),
		  _v[1]->x(), _v[1]->y(), _v[1]->z(),
		  _v[2]->x(), _v[2]->y(), _v[2]->z(), n);
    return SVector3(n[0], n[1], n[2]);
  }
};

#endif
