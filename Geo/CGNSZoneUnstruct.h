// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_ZONE_UNSTRUCT_H
#define CGNS_ZONE_UNSTRUCT_H

#include "CGNSZone.h"

#if defined(HAVE_LIBCGNS)

class CGNSZoneUnstruct : public CGNSZone {
public:
  CGNSZoneUnstruct(int fileIndex, int baseIndex, int zoneIndex, int meshDim,
                   cgsize_t startNode,
                   const Family2EltNodeTransfo &allEltNodeTransfo, int &err);

  virtual cgsize_t indexDataSize(cgsize_t nbVal) { return nbVal; }

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

protected:
  int readSection(int iSect, const std::vector<MVertex *> &allVert,
                  const std::vector<SPoint3> &rawNode,
                  std::map<int, std::vector<MElement *> > *allElt,
                  std::vector<MElement *> &zoneElt);
};

inline void CGNSZoneUnstruct::eltFromRange(const cgsize_t *range,
                                           std::vector<cgsize_t> &elt) const
{
  UnstructuredIndexing::entFromRange(range, elt);
}

inline void CGNSZoneUnstruct::eltFromList(const std::vector<cgsize_t> &list,
                                          std::vector<cgsize_t> &elt) const
{
  UnstructuredIndexing::entFromList(list, elt);
}

inline void CGNSZoneUnstruct::nodeFromRange(const cgsize_t *range,
                                            std::vector<cgsize_t> &node) const
{
  UnstructuredIndexing::entFromRange(range, node);
}

inline void CGNSZoneUnstruct::nodeFromList(const std::vector<cgsize_t> &list,
                                           std::vector<cgsize_t> &node) const
{
  UnstructuredIndexing::entFromList(list, node);
}

#endif // HAVE_LIBCGNS

#endif // CGNS_ZONE_UNSTRUCT_H
