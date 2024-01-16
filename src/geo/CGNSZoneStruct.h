// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_ZONE_STRUCT_H
#define CGNS_ZONE_STRUCT_H

#include "CGNSZone.h"

#if defined(HAVE_LIBCGNS)

template <int DIM> class CGNSZoneStruct : public CGNSZone {
public:
  CGNSZoneStruct(int fileIndex, int baseIndex, int zoneIndex, int meshDim,
                 cgsize_t startNode,
                 const Family2EltNodeTransfo &allEltNodeTransfo, int &err);

  cgsize_t nbNodeIJK(int d) const { return size_[d]; }
  cgsize_t nbEltIJK(int d) const { return size_[DIM + d]; }
  const cgsize_t *nbNodeIJK() const { return size_; }
  const cgsize_t *nbEltIJK() const { return size_ + DIM; }
  cgsize_t nbNodeInRange(const cgsize_t *range) const;
  cgsize_t nbEltInRange(const cgsize_t *range) const;

  virtual cgsize_t indexDataSize(cgsize_t nbVal) { return DIM * nbVal; }

  virtual void eltFromRange(const cgsize_t *range,
                            std::vector<cgsize_t> &elt) const;
  virtual void eltFromList(const std::vector<cgsize_t> &list,
                           std::vector<cgsize_t> &elt) const;
  virtual void nodeFromRange(const cgsize_t *range,
                             std::vector<cgsize_t> &node) const;
  virtual void nodeFromList(const std::vector<cgsize_t> &range,
                            std::vector<cgsize_t> &node) const;

  virtual int readElements(std::vector<MVertex *> &allVert,
                           std::map<int, std::vector<MElement *> > *allElt,
                           std::vector<MElement *> &zoneElt,
                           std::vector<std::string> &allGeomName);

  virtual int readConnectivities(const std::map<std::string, int> &name2Zone,
                                 std::vector<CGNSZone *> &allZones);

protected:
  int readOneInterface(int iConnect,
                       const std::map<std::string, int> &name2Zone,
                       std::vector<CGNSZone *> &allZones);
  MElement *makeBndElement(const cgsize_t *ijk, const int *dir, int order,
                           int defaultEntity, std::vector<MVertex *> &allVert,
                           std::map<int, std::vector<MElement *> > *allElt);
};

template <int DIM>
inline cgsize_t CGNSZoneStruct<DIM>::nbNodeInRange(const cgsize_t *range) const
{
  return StructuredIndexing<DIM>::nbEntInRange(range);
}

template <int DIM>
inline cgsize_t CGNSZoneStruct<DIM>::nbEltInRange(const cgsize_t *range) const
{
  return StructuredIndexing<DIM>::nbEntInRange(range);
}

template <int DIM>
inline void CGNSZoneStruct<DIM>::eltFromRange(const cgsize_t *range,
                                              std::vector<cgsize_t> &elt) const
{
  StructuredIndexing<DIM>::entFromRange(range, nbEltIJK(), elt);
}

template <int DIM>
inline void CGNSZoneStruct<DIM>::eltFromList(const std::vector<cgsize_t> &list,
                                             std::vector<cgsize_t> &elt) const
{
  StructuredIndexing<DIM>::entFromList(list, nbEltIJK(), elt);
}

template <int DIM>
inline void
CGNSZoneStruct<DIM>::nodeFromRange(const cgsize_t *range,
                                   std::vector<cgsize_t> &node) const
{
  StructuredIndexing<DIM>::entFromRange(range, nbNodeIJK(), node);
}

template <int DIM>
inline void CGNSZoneStruct<DIM>::nodeFromList(const std::vector<cgsize_t> &list,
                                              std::vector<cgsize_t> &node) const
{
  StructuredIndexing<DIM>::entFromList(list, nbNodeIJK(), node);
}

#endif // HAVE_LIBCGNS

#endif // CGNS_ZONE_STRUCT_H
