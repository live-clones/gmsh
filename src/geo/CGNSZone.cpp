// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#include "Context.h"
#include "GmshMessage.h"
#include "MVertex.h"
#include "affineTransformation.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSRead.h"
#include "CGNSZone.h"

#if defined(HAVE_LIBCGNS)

CGNSZone::CGNSZone(int fileIndex, int baseIndex, int zoneIndex,
                   CGNS_ENUMT(ZoneType_t) type, int meshDim, cgsize_t startNode,
                   const Family2EltNodeTransfo &allEltNodeTransfo, int &err)
  : fileIndex_(fileIndex), baseIndex_(baseIndex), meshDim_(meshDim),
    zoneIndex_(zoneIndex), type_(type), startNode_(startNode),
    eltNodeTransfo_(nullptr), nbPerConnect_(0)
{
  int cgnsErr;

  // read zone name & size
  char name[CGNS_MAX_STR_LEN];
  cgnsErr = cg_zone_read(fileIndex, baseIndex, zoneIndex, name, size_);
  if(cgnsErr != CG_OK) err = cgnsError(__FILE__, __LINE__, fileIndex);
  name_ = std::string(name);

  // read family name and retrieve element node tranformations (CPEX0045)
  cgnsErr = cg_goto(fileIndex, baseIndex, "Zone_t", zoneIndex, "end");
  if(cgnsErr != CG_OK) err = cgnsError(__FILE__, __LINE__, fileIndex);
  char famName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_famname_read(famName);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK) {
      auto it = allEltNodeTransfo.find(std::string(famName));
      if(it != allEltNodeTransfo.end()) eltNodeTransfo_ = &(it->second);
    }
    else
      err = cgnsError(__FILE__, __LINE__, fileIndex);
  }

  err = 1;
}

// read a boundary condition in a zone
int CGNSZone::readBoundaryCondition(int iZoneBC,
                                    const std::vector<CGNSZone *> &allZones,
                                    std::vector<std::string> &allGeomName)
{
  int cgnsErr;

  // read general information on boundary condition
  char rawBCName[CGNS_MAX_STR_LEN];
  CGNS_ENUMT(BCType_t) bcType;
  CGNS_ENUMT(PointSetType_t) ptSetType;
  cgsize_t nbVal, normalSize;
  CGNS_ENUMT(DataType_t) normalType;
  int nbDataSet;
  int normalIndex;
  cgnsErr = cg_boco_info(fileIndex(), baseIndex(), index(), iZoneBC, rawBCName,
                         &bcType, &ptSetType, &nbVal, &normalIndex, &normalSize,
                         &normalType, &nbDataSet);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // get BC name from family linked to BC, use original BC name if not present,
  // then retrieve BC index
  std::string geomName;
  cgnsErr = cg_goto(fileIndex(), baseIndex(), "Zone_t", index(), "ZoneBC_t", 1,
                    "BC_t", iZoneBC, "end");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  char rawFamilyName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_famname_read(rawFamilyName);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK)
      geomName = std::string(rawFamilyName);
    else
      return cgnsError(__FILE__, __LINE__, fileIndex());
  }
  else
    geomName = std::string(rawBCName);
  const int indGeom = nameIndex(geomName, allGeomName);

  // read location of bnd. condition (type of mesh entity on which it applies)
  CGNS_ENUMT(GridLocation_t) location;
  cgnsErr = cg_boco_gridlocation_read(fileIndex(), baseIndex(), index(),
                                      iZoneBC, &location);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // check that boundary condition is imposed on face elements
  if((type() == CGNS_ENUMV(Unstructured)) && (meshDim() == 2) &&
     (location != CGNS_ENUMV(CellCenter)) &&
     (location != CGNS_ENUMV(EdgeCenter))) {
    Msg::Warning("Boundary condition %s is specified on %s instead of "
                 "CellCenter/EdgeCenter in a 2D zone, skipping",
                 geomName.c_str(), cg_GridLocationName(location));
    return 1;
  }
  else if((type() == CGNS_ENUMV(Unstructured)) && (meshDim() == 3) &&
          (location != CGNS_ENUMV(CellCenter)) &&
          (location != CGNS_ENUMV(FaceCenter))) {
    Msg::Warning("Boundary condition %s is specified on %s instead of "
                 "CellCenter/FaceCenter in a 3D zone, skipping",
                 geomName.c_str(), cg_GridLocationName(location));
    return 1;
  }

  // read and store elements on which the BC is imposed
  std::vector<cgsize_t> bcElt;
  switch(ptSetType) {
  case CGNS_ENUMV(ElementRange):
  case CGNS_ENUMV(PointRange):
    readBoundaryConditionRange(iZoneBC, bcElt);
    break;
  case CGNS_ENUMV(ElementList):
  case CGNS_ENUMV(PointList):
    readBoundaryConditionList(iZoneBC, nbVal, bcElt);
    break;
  default:
    Msg::Error("Wrong point set type %s is for boundary condition %s",
               cg_PointSetTypeName(ptSetType), geomName.c_str());
    return 0;
    break;
  }
  for(std::size_t iElt = 0; iElt < bcElt.size(); iElt++) {
    elt2Geom()[bcElt[iElt]] = indGeom;
  }

  return 1;
}

int CGNSZone::readVertices(int dim, double scale,
                           std::vector<CGNSZone *> &allZones,
                           std::vector<MVertex *> &zoneVert)
{
  int cgnsErr;

  // read dimension of coordinates and check consistency with base node
  int dimZone;
  cgnsErr = cg_ncoords(fileIndex(), baseIndex(), index(), &dimZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  if(dimZone > dim) {
    Msg::Warning("%i coordinates in CGNS zone %i, while base has dimension %i,"
                 " discarding upper dimensions",
                 dimZone, index(), dim);
  }
  else if(dimZone < dim) {
    Msg::Error("%i coordinates in CGNS zone %i, while base has dimension %i",
               dimZone, index(), dim);
    return 0;
  }

  // read vertex coordinates
  std::vector<double> xyz[3];
  for(int iXYZ = 0; iXYZ < dim; iXYZ++) {
    char xyzName[CGNS_MAX_STR_LEN];
    CGNS_ENUMT(DataType_t) dataType;
    cgnsErr = cg_coord_info(fileIndex(), baseIndex(), index(), iXYZ + 1,
                            &dataType, xyzName);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
    const cgsize_t startInd[3] = {1, 1, 1};
    xyz[iXYZ].resize(nbNode());
    cgnsErr =
      cg_coord_read(fileIndex(), baseIndex(), index(), xyzName,
                    CGNS_ENUMV(RealDouble), startInd, size(), xyz[iXYZ].data());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  }

  // create vertices
  zoneVert.reserve(nbNode());
  for(int i = 0; i < nbNode(); i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    zoneVert.push_back(new MVertex(x, y, z));
  }

  return 1;
}

int CGNSZone::readConnectivities(const std::map<std::string, int> &name2Zone,
                                 std::vector<CGNSZone *> &allZones)
{
  int cgnsErr;

  // read number of connectivities
  int nbConnect;
  cgnsErr = cg_nconns(fileIndex(), baseIndex(), index(), &nbConnect);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // reserve memory for data containers
  perTransfo_.reserve(nbConnect);
  slaveNode_.reserve(nbConnect);
  slaveVert_.reserve(nbConnect);
  masterZone_.reserve(nbConnect);
  masterNode_.reserve(nbConnect);
  masterVert_.reserve(nbConnect);

  for(int iConnect = 1; iConnect <= nbConnect; iConnect++) {
    // read connection info
    char connectName[CGNS_MAX_STR_LEN], donorName[CGNS_MAX_STR_LEN];
    CGNS_ENUMT(GridLocation_t) location;
    CGNS_ENUMT(GridConnectivityType_t) connectType;
    CGNS_ENUMT(PointSetType_t) ptSetType, ptSetTypeDonor;
    cgsize_t connectSize, connectSizeDonor;
    CGNS_ENUMT(ZoneType_t) zoneTypeDonor;
    CGNS_ENUMT(DataType_t) dataTypeDonor;
    cgnsErr = cg_conn_info(fileIndex(), baseIndex(), index(), iConnect,
                           connectName, &location, &connectType, &ptSetType,
                           &connectSize, donorName, &zoneTypeDonor,
                           &ptSetTypeDonor, &dataTypeDonor, &connectSizeDonor);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

    // read periodic info, skip if not periodic
    float rotCenter[3], rotAngle[3], trans[3];
    cgnsErr = cg_conn_periodic_read(fileIndex(), baseIndex(), index(), iConnect,
                                    rotCenter, rotAngle, trans);
    if(cgnsErr == CG_NODE_NOT_FOUND) continue;
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

    // invert transformation because CGNS transformation is from current zone
    // to donor zone, while Gmsh transformation is from master to slave
    for(int d = 0; d < 3; d++) {
      rotAngle[d] = -rotAngle[d];
      trans[d] = -trans[d];
    }

    // check if connection type is OK
    if(connectType != CGNS_ENUMV(Abutting1to1)) {
      Msg::Warning("Non-conformal connection not supported in CGNS reader");
      continue;
    }
    if(location != CGNS_ENUMV(Vertex)) {
      Msg::Warning("Only vertex connections are supported in CGNS reader");
      continue;
    }

    // get and check data on master zone
    const std::string masterName(donorName);
    const auto itMasterName = name2Zone.find(masterName);
    if(itMasterName == name2Zone.end()) {
      Msg::Error("Zone name '%s' in not found in connection %i of zone %i",
                 masterName.c_str(), iConnect, index());
      return 0;
    }
    const int masterZoneIndex = itMasterName->second;
    CGNSZone *mZone = allZones[masterZoneIndex];
    if(mZone->type() != zoneTypeDonor) {
      Msg::Error("Inconsistent type for zone '%s' in connection %i of zone %i",
                 masterName.c_str(), iConnect, index());
      return 0;
    }

    // read connectivity data
    std::vector<cgsize_t> slaveData(indexDataSize(connectSize));
    std::vector<cgsize_t> masterData(mZone->indexDataSize(connectSizeDonor));
    cgnsErr = cg_conn_read(fileIndex(), baseIndex(), index(), iConnect,
                           slaveData.data(), dataTypeDonor, masterData.data());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

    // get slave and master nodes
    std::vector<cgsize_t> sNode, mNode;
    if(ptSetType == CGNS_ENUMV(PointRange))
      nodeFromRange(slaveData, sNode);
    else if(ptSetType == CGNS_ENUMV(PointList))
      nodeFromList(slaveData, sNode);
    if(ptSetTypeDonor != CGNS_ENUMV(PointListDonor)) {
      Msg::Error("Only PointListDonor sets are supported for donnor points for "
                 "general connections in CGNS reader");
      return 0;
    }
    mZone->nodeFromList(masterData, mNode);

    // add periodic connection
    nbPerConnect_++;
    perTransfo_.push_back(std::vector<double>());
    computeAffineTransformation(rotCenter, rotAngle, trans, perTransfo_.back());
    masterZone_.push_back(masterZoneIndex);
    slaveNode_.push_back(sNode);
    slaveVert_.push_back(std::vector<MVertex *>());
    masterNode_.push_back(mNode);
    masterVert_.push_back(std::vector<MVertex *>());
  }

  return 1;
}

int CGNSZone::readMesh(int dim, double scale, std::vector<CGNSZone *> &allZones,
                       std::vector<MVertex *> &allVert,
                       std::map<int, std::vector<MElement *> > *allElt,
                       std::vector<MVertex *> &zoneVert,
                       std::vector<MElement *> &zoneElt,
                       std::vector<std::string> &allGeomName)
{
  // read boundary conditions for classification of mesh on geometry
  if(CTX::instance()->mesh.cgnsImportIgnoreBC == 0) {
    int cgnsErr;
    int nbZoneBC;
    cgnsErr = cg_nbocos(fileIndex(), baseIndex(), index(), &nbZoneBC);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
    for(int iZoneBC = 1; iZoneBC <= nbZoneBC; iZoneBC++) {
      int errBC = readBoundaryCondition(iZoneBC, allZones, allGeomName);
      if(errBC == 0) return 0;
    }
  }

  // read and create vertices
  int errVert = readVertices(dim, scale, allZones, zoneVert);
  if(errVert == 0) return 0;
  allVert.insert(allVert.end(), zoneVert.begin(), zoneVert.end());

  // read and create elements
  int err = readElements(allVert, allElt, zoneElt, allGeomName);
  if(err == 0) return 0;

  // cleanup unncessary memory
  elt2Geom().clear();

  return 1;
}

void CGNSZone::setPeriodicVertices(const std::vector<CGNSZone *> &allZones,
                                   const std::vector<MVertex *> &allVert)
{
  for(int iPer = 0; iPer < nbPerConnect(); iPer++) {
    const std::vector<cgsize_t> &sNode = slaveNode(iPer);
    const std::vector<cgsize_t> &mNode = masterNode(iPer);
    std::vector<MVertex *> &sVert = slaveVert(iPer);
    std::vector<MVertex *> &mVert = masterVert(iPer);
    CGNSZone *mZone = allZones[masterZone(iPer)];
    for(std::size_t iN = 0; iN < sNode.size(); iN++) {
      const cgsize_t sInd = startNode() + sNode[iN];
      const cgsize_t mInd = mZone->startNode() + mNode[iN];
      sVert.push_back(allVert[sInd]);
      mVert.push_back(allVert[mInd]);
    }
  }
}

int CGNSZone::readBoundaryConditionRange(int iZoneBC,
                                         std::vector<cgsize_t> &bcElt)
{
  int cgnsErr;

  std::vector<cgsize_t> bcData(indexDataSize(2));
  cgnsErr = cg_boco_read(fileIndex(), baseIndex(), index(), iZoneBC,
                         bcData.data(), nullptr);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // get list of elements from range data
  eltFromRange(bcData, bcElt);

  return 1;
}

int CGNSZone::readBoundaryConditionList(int iZoneBC, cgsize_t nbVal,
                                        std::vector<cgsize_t> &bcElt)
{
  int cgnsErr;

  // read data
  std::vector<cgsize_t> bcData(indexDataSize(nbVal));
  cgnsErr = cg_boco_read(fileIndex(), baseIndex(), index(), iZoneBC,
                         bcData.data(), nullptr);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // get list of elements from list data
  eltFromList(bcData, bcElt);

  return 1;
}

#endif // HAVE_LIBCGNS
