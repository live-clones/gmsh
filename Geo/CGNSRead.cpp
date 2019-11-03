// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "Context.h"
#include "GmshMessage.h"
#include "MVertex.h"
#include "MElement.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


namespace {


void getElement(ElementType_t sectEltType, std::size_t vertShift, int entity,
                const std::vector<MVertex *> &allVert,
                std::map<int, std::vector<MElement *> > *allElt,
                const std::vector<cgsize_t> &sectData, std::size_t &iSectData)
{
  // get element type
  ElementType_t eltType;
  if(sectEltType == MIXED) {
    eltType = static_cast<ElementType_t>(sectData[iSectData]);
    iSectData++;
  }
  else eltType = sectEltType;

  // get element vertices in Gmsh ordering
  int mshEltType = cgns2MshEltType(eltType);
  int nbEltNode = ElementType::getNumVertices(mshEltType);
  const std::vector<int> &cgns2Msh = cgns2MshNodeIndex(mshEltType);
  std::vector<MVertex *> eltVert(nbEltNode);
  for (int iEltNode = 0; iEltNode < nbEltNode; iEltNode++, iSectData++) {
    const int indNode = vertShift + sectData[iSectData] - 1;
    eltVert[cgns2Msh[iEltNode]] = allVert[indNode];
  }

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  switch(e->getType()) {
  case TYPE_PNT: allElt[0][entity].push_back(e); break;
  case TYPE_LIN: allElt[1][entity].push_back(e); break;
  case TYPE_TRI: allElt[2][entity].push_back(e); break;
  case TYPE_QUA: allElt[3][entity].push_back(e); break;
  case TYPE_TET: allElt[4][entity].push_back(e); break;
  case TYPE_HEX: allElt[5][entity].push_back(e); break;
  case TYPE_PRI: allElt[6][entity].push_back(e); break;
  case TYPE_PYR: allElt[7][entity].push_back(e); break;
  case TYPE_POLYG: allElt[8][entity].push_back(e); break;
  case TYPE_POLYH: allElt[9][entity].push_back(e); break;
  default: Msg::Error("Wrong type of element");
  }
}


std::size_t nameIndex(const std::string &name, std::vector<std::string> &allNames)
{
  for(std::size_t i = 0; i < allNames.size(); i++) {
    if (allNames[i] == name) return i;
  }
  
  allNames.push_back(name);
  return allNames.size()-1;
}


// read a boundary condition in a zone
// DBGTT: \todo: only for unstructured zone for the moment
int readBoundaryCondition(int cgIndexFile, int cgIndexBase, int iZone,
                          int iZoneBC, int dim, std::map<int, int> &elt2BC,
                          std::vector<std::string> &allBCName,
                          std::map<int, int> &bc2Family,
                          std::vector<std::string> &allBCFamilyName)
{
  int cgnsErr;

  // read general information on boundary condition
  char bcName[CGNS_MAX_STR_LEN];
  BCType_t bcType;
  PointSetType_t ptSetType;
  cgsize_t nbElts, normalSize;
  DataType_t normalType;
  int nbDataSet;
  int normalIndex;
  cgnsErr = cg_boco_info(cgIndexFile, cgIndexBase, iZone, iZoneBC, bcName,
                         &bcType, &ptSetType, &nbElts, &normalIndex,
                         &normalSize, &normalType, &nbDataSet);
  if(cgnsErr != CG_OK) return cgnsError();

  // read family linked to BC, use BC name if not present
  std::string familyName;
  cgnsErr = cg_goto(cgIndexFile, cgIndexBase, "Zone_t", iZone, "ZoneBC_t",
                    1, "BC_t", iZoneBC, "end");
  if(cgnsErr != CG_OK) return cgnsError();
  char tmpFamilyName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_famname_read(tmpFamilyName);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK) familyName = std::string(tmpFamilyName);
    else return cgnsError();
  }

  // read location of bnd. condition (type of mesh entity on which it applies)
  GridLocation_t location;
  cgnsErr = cg_boco_gridlocation_read(cgIndexFile, cgIndexBase, iZone, iZoneBC,
                                      &location);
  if(cgnsErr != CG_OK) return cgnsError();

  // // check that boundary condition is imposed at the correct location
  // if((dim == 2) && (location != EdgeCenter) && (location != Vertex)) {
  //   Msg::Warning("Boundary condition %s is specified on %s instead of edges or "
  //                "vertices in a 2D zone, skipping", bcName,
  //                cg_GridLocationName(location));
  //   return 1;
  // }
  // else if((dim == 3) && (location != FaceCenter) && (location != EdgeCenter) &&
  //         (location != Vertex)) {
  //   Msg::Error("Boundary condition %s is specified on %s instead of faces, "
  //              "edges or vertices for a 3D zone, skipping", bcName,
  //              cg_GridLocationName(location));
  //   return 1;
  // }

  // Associate BC name and family name with indices
  const int indBC = nameIndex(bcName, allBCName);
  if(familyName.length() > 0) {
    const int indBCFamily = nameIndex(familyName, allBCFamilyName);
    bc2Family[indBC] = indBCFamily;
  }

  // Read elements on which the BC is imposed
  std::vector<cgsize_t> elt(nbElts);
  cgnsErr = cg_boco_read(cgIndexFile, cgIndexBase, iZone, iZoneBC, elt.data(),
                         0);
  if(cgnsErr != CG_OK) return cgnsError();

  switch(ptSetType) {
  case ElementRange:
  case PointRange:
  case PointRangeDonor:
    for(cgsize_t i = elt[0]; i <= elt[1]; i++) elt2BC[i] = indBC;
    break;
  case ElementList:
  case PointList:
  case PointListDonor:
    for(cgsize_t i = 0; i < nbElts; i++) elt2BC[elt[i]] = indBC;
    break;
  default:
    Msg::Error("Point set type %s is currently not supported "
                "for boundary conditions",
                cg_PointSetTypeName(ptSetType));
    break;
  }

  return 1;
}


int readSection(int cgIndexFile, int cgIndexBase, int iZone, int iSect,
                std::size_t vertShift, const std::vector<MVertex *> &allVert,
                std::map<int, std::vector<MElement *> > *allElt,
                const std::map<int, int> &elt2BC)
{
  int cgnsErr;

  // read section information
  char sectName[CGNS_MAX_STR_LEN];
  ElementType_t sectEltType;
  cgsize_t startElt, endElt;
  int nbBnd, parentFlag;
  cgnsErr = cg_section_read(cgIndexFile, cgIndexBase, iZone, iSect, sectName,
                            &sectEltType, &startElt, &endElt, &nbBnd,
                            &parentFlag);
  if(cgnsErr != CG_OK) return cgnsError();

  // read connectivity data size
  cgsize_t dataSize;
  cgnsErr = cg_ElementDataSize(cgIndexFile, cgIndexBase, iZone, iSect,
                               &dataSize);
  if(cgnsErr != CG_OK) return cgnsError();

  // read connectivity data
  std::vector<cgsize_t> sectData(dataSize);
  cgnsErr = cg_elements_read(cgIndexFile, cgIndexBase, iZone, iSect,
                             sectData.data(), 0);
  if(cgnsErr != CG_OK) return cgnsError();

  // create elements
  std::size_t iSectData = 0;
  for(int iElt = startElt; iElt <= endElt; iElt++) {
    const std::map<int, int>::const_iterator itBC = elt2BC.find(iElt);
    const int entity = (itBC == elt2BC.end()) ? 1 : itBC->second;
    getElement(sectEltType, vertShift, entity, allVert, allElt, sectData,
               iSectData);
  }

  return 1;
}


int readElementsUnstructured(int cgIndexFile, int cgIndexBase, int iZone,
                             std::size_t vertShift,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt,
                             const std::map<int, int> &elt2BC)
{
  int cgnsErr;

  // read number of sections of element-vertex connectivity
  int nbSect;
  cgnsErr = cg_nsections(cgIndexFile, cgIndexBase, iZone, &nbSect);
  if(cgnsErr != CG_OK) return cgnsError();

  // read sections of element-vertex connectivity
  for(int iSect = 1; iSect <= nbSect; iSect++) {
    int err = readSection(cgIndexFile, cgIndexBase, iZone, iSect, vertShift,
                          allVert, allElt, elt2BC);
    if(err == 0) return 0;
  }

  return 1;
}


template<int DIM>
cgsize_t ijk2Ind(const cgsize_t *ijk, const cgsize_t *nijk);


template<>
cgsize_t ijk2Ind<2>(const cgsize_t *ijk, const cgsize_t *nijk)
{
  return ijk[1] * nijk[0] + ijk[0];
}


template<>
cgsize_t ijk2Ind<3>(const cgsize_t *ijk, const cgsize_t *nijk)
{
  return (ijk[2] * nijk[1] + ijk[1]) * nijk[0] + ijk[0];
}


// template<int DIM>
// cgsize_t nbTotFromIJK(const cgsize_t *nijk);


// template<>
// cgsize_t nbTotFromIJK<2>(const cgsize_t *nijk)
// {
//   return nijk[0] * nijk[1];
// }


// template<>
// cgsize_t nbTotFromIJK<3>(const cgsize_t *nijk)
// {
//   return nijk[0] * nijk[1] * nijk[2];
// }


template<int DIM>
class StructuredInd
{
public:
  StructuredInd(int iZone, const cgsize_t *size, int &err);

  cgsize_t nbNode(int iDim) const { return nbNode_[iDim]; }
  // cgsize_t nbNode() const { return nbTotFromIJK<DIM>(nbNode_); }
  cgsize_t nbElt(int iDim) const { return nbElt_[iDim]; }
  // cgsize_t nbElt() const { return nbTotFromIJK<DIM>(nbElt_); }
    
  cgsize_t Elt(const cgsize_t *ijk) const { return ijk2Ind<DIM>(ijk, nbElt_); }
  cgsize_t Vert(const cgsize_t *ijk) const {
    return ijk2Ind<DIM>(ijk, nbNode_);
  }

private:
  cgsize_t nbNode_[DIM], nbElt_[DIM];
};


template<int DIM>
StructuredInd<DIM>::StructuredInd(int iZone, const cgsize_t *size, int &err)
{
  // Store number of elements and nodes
  for(int d = 0; d < DIM; d++) nbNode_[d] = size[d];
  for(int d = 0; d < DIM; d++) nbElt_[d] = size[DIM+d];

  // Check consistency
  bool ok = true;
  for(int d = 0; d < DIM; d++) ok &= (nbNode_[d] == nbElt_[d]+1);
  if (ok) err = 1;
  else {
    Msg::Error("CGNS zone %i: number of vertices (%i, %i, %i) is inconsistent "
               "with number of elements (%i, %i, %i)", iZone, nbNode_[0],
               nbNode_[1], (DIM == 3) ? nbNode_[2] : 0, nbElt_[0], nbElt_[1],
               (DIM == 3) ? nbElt_[2] : 0);
    err = 0;
  }
}


template<int DIM>
int readOneConnectivityStructured(int cgIndexFile, int cgIndexBase, int iZone,
                                  int iConnect, ZoneInfo &zone)
{
  int cgnsErr; 
 
  // read connection
  char connectName[CGNS_MAX_STR_LEN], donorName[CGNS_MAX_STR_LEN];
  cgsize_t range[2*DIM], donor_range[2*DIM];
  int transform[DIM];
  cgnsErr = cg_1to1_read(cgIndexFile, cgIndexBase, iZone, iConnect,
                         connectName, donorName, range, donor_range, transform);
  if(cgnsErr != CG_OK) return cgnsError();

  float rotationCenter[3], rotationAngle[3], translation[3];
  cgnsErr = cg_1to1_periodic_read(cgIndexFile, cgIndexBase, iZone, iConnect,
                                  rotationCenter, rotationAngle, translation);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK) return 1;
    else return cgnsError();
  }

  // // store connection info in zone info structure
  // storeConnectionInZoneInfo<DIM>(iZone, range, zone);

  // number of vertices and elements (raw mesh)
  int err = 1;
  StructuredInd<DIM> si(iZone, zone.size, err);
  if(err == 0) return 0;

  // range of IJK indices
  const cgsize_t iMin = range[0]-1, iMax = range[DIM]-1;
  const cgsize_t jMin = range[1]-1, jMax = range[DIM+1]-1;
  const cgsize_t kMin = (DIM == 3) ? range[2]-1 : 1;
  const cgsize_t kMax = (DIM == 3) ? range[5]-1 : 1;
  
  // Mark nodes as interface
  int ijk[3];
  for(ijk[2] = kMin; ijk[2] <= kMax; ijk[2]++) {
    for(ijk[1] = jMin; ijk[1] <= jMax; ijk[1]++) {
      for(ijk[0] = iMin; ijk[0] <= iMax; ijk[0]++) {
        zone.interfaceNode[si.Vert(ijk)] = true;
      }
    }
  }

  return 1;
}


int readConnectivitiesStructured(int cgIndexFile, int cgIndexBase, int meshDim,
                                 int iZone,
                                 const std::map<std::string, int> &name2Zone,
                                 std::vector<ZoneInfo> &allZoneInfo)
{
  int cgnsErr;

  // read number of connectivities
  int nbConnect;
  cgnsErr = cg_n1to1(cgIndexFile, cgIndexBase, iZone, &nbConnect);
  
  if(cgnsErr != CG_OK) return cgnsError();
  for(int iConnect = 1; iConnect <= nbConnect; iConnect++) {
    int err;
    if (meshDim == 2) {
      err = readOneConnectivityStructured<2>(cgIndexFile, cgIndexBase, iZone,
                                             iConnect, allZoneInfo[iZone]);
    }
    else if(meshDim == 3) {
      err = readOneConnectivityStructured<3>(cgIndexFile, cgIndexBase, iZone,
                                             iConnect, allZoneInfo[iZone]);
    }
    if(err == 0) return 0;
  }

  return 1;
}


template<int DIM>
void createElement(const cgsize_t *ijk, const StructuredInd<DIM> &si,
                   int order, std::size_t vertShift,
                   std::vector<MVertex *> &allVert,
                   std::map<int, std::vector<MElement *> > *allElt);


template<>
void createElement<2>(const cgsize_t *ijk, const StructuredInd<2> &si,
                      int order, std::size_t vertShift,
                      std::vector<MVertex *> &allVert,
                      std::map<int, std::vector<MElement *> > *allElt)
{
  // node shift from (i, j, k) depending on order
  static int shiftP1[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
  static int shiftP2[9][2] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 0}, {2, 1},
                              {1, 2}, {0, 1}, {1, 1}};

  // get element vertices
  int mshEltType;
  int *s;
  if(order == 2) {
    mshEltType = MSH_QUA_9;
    s = (int*)shiftP2;
  }
  else {
    mshEltType = MSH_QUA_4;
    s = (int*)shiftP1;
  }
  int nbEltNode = ElementType::getNumVertices(mshEltType);
  std::vector<MVertex *> eltVert(nbEltNode);
  for(int iN = 0; iN < nbEltNode; iN++) {
    const cgsize_t ijN[3] = {ijk[0]+s[2*iN], ijk[1]+s[2*iN+1]};
    const int ind = vertShift + si.Vert(ijN);
    eltVert[iN] = allVert[ind];
  }

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  int entity = 1;
  allElt[3][entity].push_back(e);
}


template<>
void createElement<3>(const cgsize_t *ijk, const StructuredInd<3> &si,
                      int order, std::size_t vertShift,
                      std::vector<MVertex *> &allVert,
                      std::map<int, std::vector<MElement *> > *allElt)
{
  // node shift from (i, j, k) depending on order
  static int shiftP1[8][3] = {{0, 0, 0}, {1, 0, 0}, {1, 1, 0}, {0, 1, 0},
                              {0, 0, 1}, {1, 0, 1}, {1, 1, 1}, {0, 1, 1}};
  static int shiftP2[27][3] = {{0, 0, 0}, {2, 0, 0}, {2, 2, 0}, {0, 2, 0},
                               {0, 0, 2}, {2, 0, 2}, {2, 2, 2}, {0, 2, 2},
                               {1, 0, 0}, {0, 1, 0}, {0, 0, 1}, {2, 1, 0},
                               {2, 0, 1}, {1, 2, 0}, {2, 2, 1}, {0, 2, 1},
                               {1, 0, 2}, {0, 1, 2}, {2, 1, 2}, {1, 2, 2},
                               {1, 1, 0}, {1, 0, 1}, {0, 1, 1}, {2, 1, 1},
                               {1, 2, 1}, {1, 1, 2}, {1, 1, 1}};

  // get element vertices
  int mshEltType;
  int *s;
  if(order == 2) {
    mshEltType = MSH_HEX_27;
    s = (int*)shiftP2;
  }
  else {
    mshEltType = MSH_HEX_8;
    s = (int*)shiftP1;
  }
  int nbEltNode = ElementType::getNumVertices(mshEltType);
  std::vector<MVertex *> eltVert(nbEltNode);
  for(int iN = 0; iN < nbEltNode; iN++) {
    const cgsize_t ijkN[3] = {ijk[0]+s[3*iN], ijk[1]+s[3*iN+1],
                              ijk[2]+s[3*iN+2]};
    const cgsize_t ind = vertShift + si.Vert(ijkN);
    eltVert[iN] = allVert[ind];
  }

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  int entity = 1;
  allElt[5][entity].push_back(e);
}


template<int DIM>
void createBndElement(const cgsize_t *ijk, const int *dir,
                      const StructuredInd<DIM> &si,
                      int order, int entity, std::size_t vertShift,
                      std::vector<MVertex *> &allVert,
                      std::map<int, std::vector<MElement *> > *allElt,
                      const std::vector<bool> &interfaceNode);


template<>
void createBndElement<2>(const cgsize_t *ijk, const int *dir,
                         const StructuredInd<2> &si,
                         int order, int entity, std::size_t vertShift,
                         std::vector<MVertex *> &allVert,
                         std::map<int, std::vector<MElement *> > *allElt,
                         const std::vector<bool> &interfaceNode)
{
  // TODO: to be implemented
  Msg::Error("Creation of boundary elements for 2D structured blocks not "
             "implemented");
}


template<>
void createBndElement<3>(const cgsize_t *ijk, const int *dir,
                         const StructuredInd<3> &si,
                         int order, int entity, std::size_t vertShift,
                         std::vector<MVertex *> &allVert,
                         std::map<int, std::vector<MElement *> > *allElt,
                         const std::vector<bool> &interfaceNode)
{
  // node shift from (i, j, k) depending on order
  static int shiftP1[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
  static int shiftP2[9][2] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 0}, {2, 1},
                              {1, 2}, {0, 1}, {1, 1}};

  // get element vertices
  int mshEltType;
  int *s;
  if(order == 2) {
    mshEltType = MSH_QUA_9;
    s = (int*)shiftP2;
  }
  else {
    mshEltType = MSH_QUA_4;
    s = (int*)shiftP1;
  }
  int nbEltNode = ElementType::getNumVertices(mshEltType);
  std::vector<MVertex *> eltVert(nbEltNode);
  bool isInternalInterface = true;
  for(int iN = 0; iN < nbEltNode; iN++) {
    cgsize_t ijkN[3] = {ijk[0], ijk[1], ijk[2]};
    ijkN[dir[0]] += s[2*iN];
    ijkN[dir[1]] += s[2*iN+1];
    const cgsize_t localInd = si.Vert(ijkN);
    isInternalInterface &= interfaceNode[localInd];
    eltVert[iN] = allVert[vertShift+localInd];
  }

  // do no add element if it is part of an internal interface between blocks
  if(isInternalInterface) return;

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  allElt[3][entity].push_back(e);
}


template<int DIM>
int readElementsStructured(int cgIndexFile, int cgIndexBase, int iZone,
                           std::size_t vertShift, const cgsize_t *zoneSize,
                           std::vector<MVertex *> &allVert,
                           std::map<int, std::vector<MElement *> > *allElt,
                           const std::map<int, int> &elt2BC,
                           const std::vector<bool> &interfaceNode,
                           int firstDefaultBC)
{
  // number of vertices and elements (raw mesh)
  int err = 1;
  StructuredInd<DIM> si(iZone, zoneSize, err);
  if(err == 0) return 0;

  // order of coarsened mesh and number of potentially coarsened (HO) elements
  int order = CTX::instance()->mesh.cgnsImportOrder;
  if(order > 2) {
    Msg::Warning("Cannot coarsen structured grid to order %i, creating linear "
                 "mesh in zone %i", order, iZone);
    order = 1;
  }
  else {
    bool orderOK = true;
    for(int d = 0; d < DIM; d++) orderOK &= (si.nbElt(d) % order == 0);
    if(!orderOK) {
      Msg::Warning("Zone %i has (%i, %i, %i) vertices which cannot be coarsened"
                   " to order %i, creating linear mesh", iZone, si.nbNode(0),
                   si.nbNode(1), (DIM == 3) ? si.nbNode(2) : 0, order);
      order = 1;
    }
  }
  const int nbEltI = si.nbElt(0) / order;
  const int nbEltJ = si.nbElt(1) / order;
  const int nbEltK = (DIM == 3) ? si.nbElt(2) / order : 1;

  // create domain elements
  for(int k = 0; k < nbEltK; k++) {
    for(int j = 0; j < nbEltJ; j++) {
      for(int i = 0; i < nbEltI; i++) {
        const cgsize_t ijk[3] = {i*order, j*order, k*order};
        createElement<DIM>(ijk, si, order, vertShift, allVert, allElt);
      }
    }
  }

  // create boundary elements for block faces i- and i+
  const int bcIMin = firstDefaultBC, bcIMax = firstDefaultBC+1;
  for(int k = 0; k < nbEltK; k++) {
    for(int j = 0; j < nbEltJ; j++) {
        static const int dir[2] = {1, 2};
        cgsize_t ijk[3] = {0, j*order, k*order};
        createBndElement<DIM>(ijk, dir, si, order, bcIMin, vertShift, allVert,
                              allElt, interfaceNode);
        ijk[0] = si.nbNode(0)-1;
        createBndElement<DIM>(ijk, dir, si, order, bcIMax, vertShift, allVert,
                              allElt, interfaceNode);
    }
  }

  // create boundary elements for block faces j- and j+
  const int bcJMin = firstDefaultBC+2, bcJMax = firstDefaultBC+3;
  for(int k = 0; k < nbEltK; k++) {
    for(int i = 0; i < nbEltI; i++) {
        static const int dir[2] = {0, 2};
        cgsize_t ijk[3] = {i*order, 0, k*order};
        createBndElement<DIM>(ijk, dir, si, order, bcJMin, vertShift, allVert,
                              allElt, interfaceNode);
        ijk[1] = si.nbNode(1)-1;
        createBndElement<DIM>(ijk, dir, si, order, bcJMax, vertShift, allVert,
                              allElt, interfaceNode);
    }
  }

  // create boundary elements for block faces k- and k+ if 3D
  if (DIM == 3) {
    const int bcKMin = firstDefaultBC+4, bcKMax = firstDefaultBC+5;
    for(int j = 0; j < nbEltJ; j++) {
      for(int i = 0; i < nbEltI; i++) {
          static const int dir[2] = {0, 1};
          cgsize_t ijk[3] = {i*order, j*order, 0};
          createBndElement<DIM>(ijk, dir, si, order, bcKMin, vertShift, allVert,
                                allElt, interfaceNode);
          ijk[2] = si.nbNode(2)-1;
          createBndElement<DIM>(ijk, dir, si, order, bcKMax, vertShift, allVert,
                                allElt, interfaceNode);
      }
    }
  }

  return 1;
}


}


double readScale()
{
  double scale = 1.;

  MassUnits_t mass;
  LengthUnits_t length;
  TimeUnits_t time;
  TemperatureUnits_t temperature;
  AngleUnits_t angle;
  cg_units_read(&mass, &length, &time, &temperature, &angle);

  switch(length) {
  case Centimeter:
    Msg::Info("Length unit in CGNS file is cm, rescaling");
    scale = 0.01;
    break;
  case Millimeter:
    Msg::Info("Length unit in CGNS file is mm, rescaling");
    scale = 0.001;
    break;
  case Foot:
    Msg::Info("Length unit in CGNS file is feet, rescaling");
    scale = 0.3048;
    break;
  case Inch:
    Msg::Info("Length unit in CGNS file is inch, rescaling");
    scale = 0.0254;
    break;
  case Meter:
    Msg::Info("Length unit in CGNS file is meter, not rescaling");
    break;
  case CG_Null:
  case CG_UserDefined:
  default:
    Msg::Info("Length unit in CGNS file not defined, therefore not rescaling");
    break;
  }

  return scale;
}


int readAllZoneInfo(int cgIndexFile, int cgIndexBase, int meshDim,
                    std::vector<ZoneInfo> &allZoneInfo)
{
  int cgnsErr;

  // read number of zones (allZoneInfo[0] is dummy because index starts at 1) 
  int nbZones = 0;
  cgnsErr = cg_nzones(cgIndexFile, cgIndexBase, &nbZones);
  if(cgnsErr != CG_OK) return cgnsError();
  allZoneInfo.resize(nbZones+1);

  // read zone type and size
  cgsize_t offset = 0;
  std::map<std::string, int> name2Zone;
  for(int iZone = 1; iZone <= nbZones; iZone++) {
    // index
    ZoneInfo &zone = allZoneInfo[iZone];
    zone.index= iZone;

    // read zone type
    cgnsErr = cg_zone_type(cgIndexFile, cgIndexBase, iZone, &(zone.type));
    if(cgnsErr != CG_OK) return cgnsError();

    // read zone size
    cgnsErr = cg_zone_read(cgIndexFile, cgIndexBase, iZone, zone.name, zone.size);
    if(cgnsErr != CG_OK) return cgnsError();
    
    // Compute info about node size
    zone.startNode = offset; 
    zone.nbNode = zone.size[0];
    if (zone.type == Structured) {
      if(meshDim > 1) zone.nbNode *= zone.size[1];
      if(meshDim > 2) zone.nbNode *= zone.size[2];
    }
    zone.interfaceNode.resize(zone.nbNode);

    // helper variables
    offset += zone.nbNode;
    name2Zone[std::string(zone.name)] = iZone-1;
  }

  // read interface and periodicity info
  for(int iZone = 1; iZone <= nbZones; iZone++) {
    if(allZoneInfo[iZone].type == Structured) {
      readConnectivitiesStructured(cgIndexFile, cgIndexBase, meshDim, iZone,
                                   name2Zone, allZoneInfo);
    }
  }

  return 1;
}


int readZone(int cgIndexFile, int cgIndexBase, const ZoneInfo &zone, int dim,
             double scale, std::vector<MVertex *> &allVert,
             std::map<int, std::vector<MElement *> > *allElt,
             std::vector<std::string> &allBCName, std::map<int, int> &bc2Family,
             std::vector<std::string> &allBCFamilyName)
{
  int cgnsErr;

  // read dimension of coordinates and check consistency with base node
  int dim2;
  cgnsErr = cg_ncoords(cgIndexFile, cgIndexBase, zone.index, &dim2);
  if(cgnsErr != CG_OK) return cgnsError();
  if(dim2 > dim) {
    Msg::Warning("%i coordinates in CGNS zone %i, while base has dimension %i,"
                 " discarding upper dimensions", dim2, zone.index, dim);
  }
  else if(dim2 < dim) {
    Msg::Error("%i coordinates in CGNS zone %i, while base has dimension %i",
               dim2, zone.index, dim);
    return 0;
  }

  // read boundary conditions for classification of mesh on geometry
  int nbZoneBC;
  std::map<int, int> elt2BC;
  cgnsErr = cg_nbocos(cgIndexFile, cgIndexBase, zone.index, &nbZoneBC);
  if(cgnsErr != CG_OK) return cgnsError();
  for(int iZoneBC = 1; iZoneBC <= nbZoneBC; iZoneBC++) {
    readBoundaryCondition(cgIndexFile, cgIndexBase, zone.index, iZoneBC, dim,
                          elt2BC, allBCName, bc2Family, allBCFamilyName);
  }

  // read vertex coordinates
  std::vector<double> xyz[3];
  for(int iXYZ = 0; iXYZ < dim; iXYZ++) {
    char xyzName[CGNS_MAX_STR_LEN];
    DataType_t dataType;
    cgnsErr = cg_coord_info(cgIndexFile, cgIndexBase, zone.index, iXYZ+1,
                            &dataType, xyzName);
    if(cgnsErr != CG_OK) return cgnsError();
    const int startInd[3] = {1, 1, 1};
    xyz[iXYZ].resize(zone.nbNode);
    cgnsErr = cg_coord_read(cgIndexFile, cgIndexBase, zone.index, xyzName,
                            RealDouble, startInd, zone.size, xyz[iXYZ].data());
    if(cgnsErr != CG_OK) return cgnsError();
  }

  // create vertices
  const std::size_t vertShift = allVert.size();
  allVert.reserve(vertShift+zone.nbNode);
  for(int i = 0; i < zone.nbNode; i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    allVert.push_back(new MVertex(x, y, z));
  }

  // read and create elementss
  int err = 0;
  if (zone.type == Structured) {
    const int firstDefaultBC = allBCName.size();
    allBCName.insert(allBCName.end(), 2*dim, "");
    if(dim == 2) {
      err = readElementsStructured<2>(cgIndexFile, cgIndexBase, zone.index,
                                      vertShift, zone.size, allVert, allElt,
                                      elt2BC, zone.interfaceNode,
                                      firstDefaultBC);
    }
    else if(dim == 3) {
      err = readElementsStructured<3>(cgIndexFile, cgIndexBase, zone.index,
                                      vertShift, zone.size, allVert, allElt,
                                      elt2BC, zone.interfaceNode,
                                      firstDefaultBC);
    }
  }
  else {
    err = readElementsUnstructured(cgIndexFile, cgIndexBase, zone.index,
                                   vertShift, allVert, allElt, elt2BC);
  }
  if(err == 0) return 0;

  return 1;
}


#endif // HAVE_LIBCGNS
