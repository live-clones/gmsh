// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef CGNS_CGNSZONEUNSTRUCT_H
#define CGNS_CGNSZONEUNSTRUCT_H

#include "CGNSZone.h"

#if defined(HAVE_LIBCGNS)


class CGNSZoneUnstruct : public CGNSZone
{
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
  std::size_t nb = range[1]-range[0]+1;
  elt.resize(nb);
  cgsize_t iMin = range[0]-1;
  for(std::size_t i = 0; i < nb; i++) elt[i] = iMin + i;
}

  
inline void CGNSZoneUnstruct::eltFromList(const std::vector<cgsize_t> &list,
                                          std::vector<cgsize_t> &elt) const
{
  std::size_t nb = list.size();
  elt.resize(nb);
  for(std::size_t i = 0; i < nb; i++) elt[i] = list[i] - 1;
}

  
inline void CGNSZoneUnstruct::nodeFromRange(const cgsize_t *range,
                                            std::vector<cgsize_t> &node) const
{
  std::size_t nb = range[1]-range[0]+1;
  node.resize(nb);
  cgsize_t iMin = range[0]-1;
  for(std::size_t i = 0; i < nb; i++) node[i] = iMin + i;
}

    
inline void CGNSZoneUnstruct::nodeFromList(const std::vector<cgsize_t> &list,
                                           std::vector<cgsize_t> &node) const
{
  std::size_t nb = list.size();
  node.resize(nb);
  for(std::size_t i = 0; i < nb; i++) node[i] = list[i] - 1;
}


#endif // HAVE_LIBCGNS

#endif // CGNS_CGNSZONEUNSTRUCT_H
