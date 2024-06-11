// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#ifndef CGNS_ZONE_H
#define CGNS_ZONE_H

#include <string>
#include <vector>
#include <map>
#include "GmshConfig.h"
#include "CGNSCommon.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)

class MVertex;
class MElement;

class CGNSZone {
public:
  CGNSZone() {}
  CGNSZone(int fileIndex, int baseIndex, int zoneIndex,
           CGNS_ENUMT(ZoneType_t) type, int meshDim, cgsize_t startNode,
           const Family2EltNodeTransfo &allEltNodeTransfo, int &err);
  virtual ~CGNSZone() {}

  int index() const { return zoneIndex_; }
  std::string name() const { return name_; }
  CGNS_ENUMT(ZoneType_t) type() const { return type_; }
  cgsize_t startNode() const { return startNode_; }
  cgsize_t nbNode() const { return nbNode_; }
  cgsize_t nbElt() const { return nbElt_; }
  const cgsize_t *size() const { return size_; }

  virtual cgsize_t indexDataSize(cgsize_t nbVal) = 0;
  virtual void eltFromRange(const cgsize_t *range,
                            std::vector<cgsize_t> &elt) const = 0;
  void eltFromRange(const std::vector<cgsize_t> &range,
                    std::vector<cgsize_t> &elt) const
  {
    eltFromRange(range.data(), elt);
  }
  virtual void eltFromList(const std::vector<cgsize_t> &list,
                           std::vector<cgsize_t> &elt) const = 0;
  virtual void nodeFromRange(const cgsize_t *range,
                             std::vector<cgsize_t> &node) const = 0;
  void nodeFromRange(const std::vector<cgsize_t> &range,
                     std::vector<cgsize_t> &node) const
  {
    nodeFromRange(range.data(), node);
  }
  virtual void nodeFromList(const std::vector<cgsize_t> &range,
                            std::vector<cgsize_t> &node) const = 0;

  std::map<cgsize_t, int> &elt2Geom() { return elt2Geom_; }
  const ZoneEltNodeTransfo *eltNodeTransfo() const { return eltNodeTransfo_; }
  const std::vector<bool> &interfaceNode() const { return interfaceNode_; }
  int nbPerConnect() const { return nbPerConnect_; }
  int masterZone(int iPer) const { return masterZone_[iPer]; }
  const std::vector<double> &perTransfo(int iPer) const
  {
    return perTransfo_[iPer];
  }
  const std::vector<cgsize_t> &masterNode(int iPer) const
  {
    return masterNode_[iPer];
  }
  const std::vector<cgsize_t> &slaveNode(int iPer) const
  {
    return slaveNode_[iPer];
  }
  std::vector<MVertex *> &masterVert(int iPer) { return masterVert_[iPer]; }
  std::vector<MVertex *> &slaveVert(int iPer) { return slaveVert_[iPer]; }

  int readBoundaryCondition(int iZoneBC,
                            const std::vector<CGNSZone *> &allZones,
                            std::vector<std::string> &allGeomName);

  int readVertices(int dim, double scale, std::vector<CGNSZone *> &allZones,
                   std::vector<MVertex *> &zoneVert);

  virtual int readElements(std::vector<MVertex *> &allVert,
                           std::map<int, std::vector<MElement *> > *allElt,
                           std::vector<MElement *> &zoneElt,
                           std::vector<std::string> &allGeomName) = 0;

  virtual int readConnectivities(const std::map<std::string, int> &name2Zone,
                                 std::vector<CGNSZone *> &allZones);

  int readMesh(int dim, double scale, std::vector<CGNSZone *> &allZones,
               std::vector<MVertex *> &allVert,
               std::map<int, std::vector<MElement *> > *allElt,
               std::vector<MVertex *> &zoneVert,
               std::vector<MElement *> &zoneElt,
               std::vector<std::string> &allGeomName);

  void setPeriodicVertices(const std::vector<CGNSZone *> &allZones,
                           const std::vector<MVertex *> &allVert);

protected:
  // basic zone information
  int fileIndex_, baseIndex_, meshDim_, zoneIndex_;
  std::string name_;
  cgsize_t size_[9];
  CGNS_ENUMT(ZoneType_t) type_;
  cgsize_t startNode_, nbNode_, nbElt_;

  // BC information
  std::map<cgsize_t, int> elt2Geom_;

  // transformations of high-order points per element (CPEX0045)
  const ZoneEltNodeTransfo *eltNodeTransfo_;

  // internal interface information
  std::vector<bool> interfaceNode_;

  // periodic information
  int nbPerConnect_;
  std::vector<int> masterZone_;
  std::vector<std::vector<double> > perTransfo_;
  std::vector<std::vector<cgsize_t> > masterNode_, slaveNode_;
  std::vector<std::vector<MVertex *> > masterVert_, slaveVert_;

  int fileIndex() const { return fileIndex_; }
  int baseIndex() const { return baseIndex_; }
  int meshDim() const { return meshDim_; }

  int readBoundaryConditionList(int indBC, cgsize_t nbVal,
                                std::vector<cgsize_t> &bcElt);
  int readBoundaryConditionRange(int indBC, std::vector<cgsize_t> &bcElt);
};

#endif // HAVE_LIBCGNS

#endif // CGNS_ZONE_H
