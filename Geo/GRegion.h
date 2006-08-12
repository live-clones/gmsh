#ifndef _GREGION_H_
#define _GREGION_H_

#include "GEntity.h"
#include "MElement.h"

// A model region.
class GRegion : public GEntity {
 protected:
  std::list<GFace *> l_faces;
  std::list<int> l_dirs;
 public:
  GRegion(GModel *model, int tag) : GEntity (model, tag) {}
  virtual ~GRegion();
  virtual int dim() const {return 3;}
  virtual GeomType geomType() const {return Volume;}
  virtual void setVisibility(char val, bool recursive=false);

  // recompute the mesh partitions defined on this region.
  void recomputeMeshPartitions();

  std::vector<MTetrahedron*> tetrahedra;
  std::vector<MHexahedron*> hexahedra;
  std::vector<MPrism*> prisms;
  std::vector<MPyramid*> pyramids;
};

#endif
