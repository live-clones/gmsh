// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "MVertex.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZone.h"

#if defined(HAVE_LIBCGNS)


namespace {


std::size_t nameIndex(const std::string &name,
                      std::vector<std::string> &allNames)
{
  for(std::size_t i = 0; i < allNames.size(); i++) {
    if (allNames[i] == name) return i;
  }
  
  allNames.push_back(name);
  return allNames.size()-1;
}


void periodicVertFromNode(std::size_t vertShift,
                          const std::vector<MVertex *> &allVert,
                          const std::vector<cgsize_t> &node,
                          std::vector<MVertex *> &vert)
{
  for(std::size_t iN = 0; iN < node.size(); iN++) {
    cgsize_t indN = node[iN];
    vert.push_back(allVert[vertShift+indN]);
  }
}


}


CGNSZone::CGNSZone(int fileIndex, int baseIndex, int zoneIndex, int meshDim,
                   cgsize_t startNode,
                   const Family2EltNodeTransfo &allEltNodeTransfo, int &err) :
  fileIndex_(fileIndex), baseIndex_(baseIndex), meshDim_(meshDim),
  zoneIndex_(zoneIndex), startNode_(startNode), eltNodeTransfo_(0)
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
      Family2EltNodeTransfo::const_iterator it =
        allEltNodeTransfo.find(std::string(famName));
      if(it != allEltNodeTransfo.end()) eltNodeTransfo_ = &(it->second);
    }
    else err = cgnsError(__FILE__, __LINE__, fileIndex);
  }
}


// read a boundary condition in a zone
int CGNSZone::readBoundaryCondition(int iZoneBC,
                                    const std::vector<CGNSZone *> &allZones,
                                    std::vector<std::string> &allBCName,
                                    std::map<int, int> &bc2Family,
                                    std::vector<std::string> &allBCFamilyName)
{
  int cgnsErr;

  // read general information on boundary condition
  char bcName[CGNS_MAX_STR_LEN];
  BCType_t bcType;
  PointSetType_t ptSetType;
  cgsize_t nbVal, normalSize;
  DataType_t normalType;
  int nbDataSet;
  int normalIndex;
  cgnsErr = cg_boco_info(fileIndex(), baseIndex(), index(), iZoneBC, bcName,
                         &bcType, &ptSetType, &nbVal, &normalIndex,
                         &normalSize, &normalType, &nbDataSet);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // read family linked to BC, use BC name if not present
  std::string familyName;
  cgnsErr = cg_goto(fileIndex(), baseIndex(), "Zone_t", index(), "ZoneBC_t",
                    1, "BC_t", iZoneBC, "end");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  char tmpFamilyName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_famname_read(tmpFamilyName);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK) familyName = std::string(tmpFamilyName);
    else return cgnsError(__FILE__, __LINE__, fileIndex());
  }

  // read location of bnd. condition (type of mesh entity on which it applies)
  GridLocation_t location;
  cgnsErr = cg_boco_gridlocation_read(fileIndex(), baseIndex(), index(), iZoneBC,
                                      &location);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // check that boundary condition is imposed on face elements 
  if((meshDim() == 2) && (location != CellCenter) && (location != EdgeCenter)) {
    Msg::Warning("Boundary condition %s is specified on %s instead of "
                 "CellCenter/EdgeCenter in a 2D zone, skipping", bcName,
                 cg_GridLocationName(location));
    return 1;
  }
  else if((meshDim() == 3) && (location != CellCenter) &&
          (location != FaceCenter)) {
    Msg::Warning("Boundary condition %s is specified on %s instead of "
                 "CellCenter/FaceCenter in a 3D zone, skipping", bcName,
                 cg_GridLocationName(location));
    return 1;
  }

  // associate BC name and family name with indices
  const int indBC = nameIndex(bcName, allBCName);
  if(familyName.length() > 0) {
    const int indBCFamily = nameIndex(familyName, allBCFamilyName);
    bc2Family[indBC] = indBCFamily;
  }

  // read and store elements on which the BC is imposed
  std::vector<cgsize_t> bcElt;
  switch(ptSetType) {
  case ElementRange:
  case PointRange:
    readBoundaryConditionRange(iZoneBC, bcElt);
    break;
  case ElementList:
  case PointList:
    readBoundaryConditionList(iZoneBC, nbVal, bcElt);
    break;
  default:
    Msg::Error("Wrong point set type %s is for boundary condition %s",
               cg_PointSetTypeName(ptSetType), bcName);
    return 0;
    break;
  }
  for(std::size_t iElt = 0; iElt < bcElt.size(); iElt++) {
    elt2BC_[bcElt[iElt]] = indBC;
  }

  return 1;
}


int CGNSZone::readVertices(int dim, double scale,
                           std::vector<CGNSZone *> &allZones,
                           std::vector<MVertex *> &allVert)
{
  int cgnsErr;

  // read dimension of coordinates and check consistency with base node
  int dimZone;
  cgnsErr = cg_ncoords(fileIndex(), baseIndex(), index(), &dimZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  if(dimZone > dim) {
    Msg::Warning("%i coordinates in CGNS zone %i, while base has dimension %i,"
                 " discarding upper dimensions", dimZone, index(), dim);
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
    DataType_t dataType;
    cgnsErr = cg_coord_info(fileIndex(), baseIndex(), index(), iXYZ+1,
                            &dataType, xyzName);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
    const int startInd[3] = {1, 1, 1};
    xyz[iXYZ].resize(nbNode());
    cgnsErr = cg_coord_read(fileIndex(), baseIndex(), index(), xyzName,
                            RealDouble, startInd, size(), xyz[iXYZ].data());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  }

  // create vertices
  allVert.reserve(startNode()+nbNode());
  for(int i = 0; i < nbNode(); i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    allVert.push_back(new MVertex(x, y, z));
  }

  // fill periodic slave nodes
  for(std::size_t iPer = 0; iPer < slaveNode().size(); iPer++) {
    std::vector<cgsize_t> &sNode = slaveNode_[iPer];
    std::vector<MVertex *> &sVert = slaveVert_[iPer];
    periodicVertFromNode(startNode(), allVert, sNode, sVert);
  }

  // fill periodic master nodes in all zones
  for(std::size_t iZone2 = 1; iZone2 < allZones.size(); iZone2++) {
    CGNSZone *zone2 = allZones[iZone2];
    for(std::size_t iPer = 0; iPer < zone2->masterZone().size(); iPer++) {
      if (zone2->masterZone()[iPer] != index()) continue;
      const std::vector<cgsize_t> &masterNode = zone2->masterNode()[iPer];
      std::vector<MVertex *> &masterVert = zone2->masterVert()[iPer];
      periodicVertFromNode(startNode(), allVert, masterNode, masterVert);
    }
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

  for(int iConnect = 1; iConnect <= nbConnect; iConnect++) {
    // read connection info
    char connectName[CGNS_MAX_STR_LEN], donorName[CGNS_MAX_STR_LEN];
    GridLocation_t location;
    GridConnectivityType_t connectType;
    PointSetType_t ptSetType, ptSetTypeDonor;
    cgsize_t connectSize, connectSizeDonor;
    ZoneType_t zoneTypeDonor;
    DataType_t dataTypeDonor;
    cgnsErr = cg_conn_info(fileIndex(), baseIndex(), index(), iConnect,
                           connectName, &location, &connectType, &ptSetType,
                           &connectSize, donorName, &zoneTypeDonor,
                           &ptSetTypeDonor, &dataTypeDonor, &connectSizeDonor);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

    // check if connection type is OK
    if(connectType != Abutting1to1) {
      Msg::Error("Non-conformal connection not supported in CGNS reader");
      return 0;
    }

    // read connectivity data
    // cg_conn_read(cgIndexFile, cgIndexBase, iZone, iConnect, tgtPts,
    //              dataTypeDonor, srcPts);
  }

  return 1;
}


int CGNSZone::readMesh(int dim, double scale, std::vector<CGNSZone *> &allZones,
                       std::vector<MVertex *> &allVert,
                       std::map<int, std::vector<MElement *> > *allElt,
                       std::vector<std::string> &allBCName,
                       std::map<int, int> &bc2Family,
                       std::vector<std::string> &allBCFamilyName)
{
  int cgnsErr;

  // read boundary conditions for classification of mesh on geometry
  int nbZoneBC;
  cgnsErr = cg_nbocos(fileIndex(), baseIndex(), index(), &nbZoneBC);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());
  for(int iZoneBC = 1; iZoneBC <= nbZoneBC; iZoneBC++) {
    int errBC = readBoundaryCondition(iZoneBC, allZones, allBCName, bc2Family,
                                      allBCFamilyName);
    if(errBC == 0) return 0;
  }

  // read and create vertices
  int errVert = readVertices(dim, scale, allZones, allVert);
  if(errVert == 0) return 0;

  // read and create elements
  int err = readElements(allVert, allElt, allBCName);
  if(err == 0) return 0;

  // cleanup unncessary memory
  elt2BC_.clear();

  return 1;
}


int CGNSZone::readBoundaryConditionRange(int iZoneBC,
                                         std::vector<cgsize_t> &bcElt)
{
  int cgnsErr;

  std::vector<cgsize_t> bcData(indexDataSize(2));
  cgnsErr = cg_boco_read(fileIndex(), baseIndex(), index(), iZoneBC,
                         bcData.data(), 0);
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
                         bcData.data(), 0);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // get list of elements from list data
  eltFromList(bcData, bcElt);

  return 1;
}


#endif // HAVE_LIBCGNS
