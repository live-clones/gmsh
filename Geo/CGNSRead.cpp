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
#include "affineTransformation.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


namespace {


// ------------------ Helper functions for unstructured zones ------------------


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


// ------------------- Helper functions for structured zones -------------------


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
  cgsize_t Node(const cgsize_t *ijk) const {
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
                                  int iConnect,
                                  const std::map<std::string, int> &name2Zone,
                                  std::vector<ZoneInfo> &allZoneInfo)
{
  int cgnsErr;
  ZoneInfo &zone = allZoneInfo[iZone];
 
  // read connection
  char connectName[CGNS_MAX_STR_LEN], donorName[CGNS_MAX_STR_LEN];
  cgsize_t range[2*DIM], rangeDonnor[2*DIM];
  int indexTransfo[DIM];
  cgnsErr = cg_1to1_read(cgIndexFile, cgIndexBase, iZone, iConnect, connectName,
                         donorName, range, rangeDonnor, indexTransfo);
  if(cgnsErr != CG_OK) return cgnsError();

  bool periodic = false;
  float rotCenter[3], rotAngle[3], translat[3];
  cgnsErr = cg_1to1_periodic_read(cgIndexFile, cgIndexBase, iZone, iConnect,
                                  rotCenter, rotAngle, translat);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK) periodic = true;
    else return cgnsError();
  }

  // indexing in zone
  int err = 1;
  StructuredInd<DIM> si(iZone, zone.size, err);
  if(err == 0) return 0;

  // range of IJK indices
  const cgsize_t ijkMin[3] = {range[0]-1, range[1]-1,
                              (DIM == 3) ? range[2]-1 : 1};
  const cgsize_t ijkMax[3] = {range[DIM]-1, range[DIM+1]-1,
                              (DIM == 3) ? range[5]-1 : 1};

  // If not periodic, mark as internal interface and return
  if(!periodic) {
    int ijk[3], &i = ijk[0], &j = ijk[1], &k = ijk[2];
    for(k = ijkMin[2]; k <= ijkMax[2]; k++) {
      for(j = ijkMin[1]; j <= ijkMax[1]; j++) {
        for(i = ijkMin[0]; i <= ijkMax[0]; i++) {
          zone.interfaceNode[si.Node(ijk)] = true;
        }
      }
    }
    return 1;
  }

  // identify donnor (master) zone
  std::map<std::string, int>::const_iterator itDN = name2Zone.find(donorName);
  if(itDN == name2Zone.end()) {
    Msg::Error("Donnor zone '%s' not found in structured connectivity '%s' "
               "of zone %i ('%s')", donorName, connectName, zone.index,
               zone.name);
    return 0;
  }
  const int iZoneD = itDN->second;
  zone.masterZone.push_back(iZoneD);

  // periodic transformation
  zone.perTransfo.push_back(std::vector<double>());
  computeAffineTransformation(rotCenter, rotAngle, translat,
                              zone.perTransfo.back());

  // number of nodes and origin of donnor (master) interface
  cgsize_t nijk[3] = {0, 0, 1};
  for(int d = 0; d < DIM; d++) nijk[d] = ijkMax[d]-ijkMin[d]+1;
  const cgsize_t nbNode = nijk[0]*nijk[1]*nijk[2];

  // indexation in donnor zone
  ZoneInfo &zoneD = allZoneInfo[iZoneD];
  int errD = 1;
  StructuredInd<DIM> siD(iZoneD, zoneD.size, errD);
  if(errD == 0) return 0;
  const cgsize_t ijkMinD[3] = {rangeDonnor[0]-1, rangeDonnor[1]-1,
                               (DIM == 3) ? rangeDonnor[2]-1 : 1};

  // IJK directions and sign for master-slave index transformation
  int dir[3] = {-1, -1, 2};
  for(int d = 0; d < DIM; d++) dir[d] = std::abs(indexTransfo[d])-1;
  bool signDir[3] = {true, true, true};
  for(int d = 0; d < DIM; d++) signDir[d] = (indexTransfo[d] > 0);

  // allocate storage for node correspondence
  zone.slaveNode.push_back(std::vector<cgsize_t>());
  std::vector<cgsize_t> &slaveNode = zone.slaveNode.back();
  slaveNode.reserve(nbNode);
  zone.slaveVert.push_back(std::vector<MVertex *>());
  zone.slaveVert.back().reserve(nbNode);
  zone.masterNode.push_back(std::vector<cgsize_t>());
  std::vector<cgsize_t> &masterNode = zone.masterNode.back();
  masterNode.reserve(nbNode);
  zone.masterVert.push_back(std::vector<MVertex *>());
  zone.masterVert.back().reserve(nbNode);

  // store periodic node correspondance
  int ijk[3], ijkD[3];
  for(int k = 0; k < nijk[2]; k++) {
    ijk[2] = ijkMin[2] + k;
    for(int j = 0; j < nijk[1]; j++) {
      ijk[1] = ijkMin[1] + j;
      for(int i = 0; i < nijk[0]; i++) {
        ijk[0] = ijkMin[0] + i;
        for(int d = 0; d < DIM; d++) ijkD[d] = ijkMinD[d];
        ijkD[dir[0]] += signDir[dir[0]] ? i : -i;
        ijkD[dir[1]] += signDir[dir[1]] ? j : -j;
        ijkD[dir[2]] += signDir[dir[2]] ? k : -k;
        slaveNode.push_back(si.Node(ijk));
        masterNode.push_back(siD.Node(ijkD));
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
                                             iConnect, name2Zone, allZoneInfo);
    }
    else if(meshDim == 3) {
      err = readOneConnectivityStructured<3>(cgIndexFile, cgIndexBase, iZone,
                                             iConnect, name2Zone, allZoneInfo);
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
    const int ind = vertShift + si.Node(ijN);
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
    const cgsize_t ind = vertShift + si.Node(ijkN);
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
    const cgsize_t localInd = si.Node(ijkN);
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


// ------------------------- Generic helper functions --------------------------


std::size_t nameIndex(const std::string &name,
                      std::vector<std::string> &allNames)
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
                          int iZoneBC, int meshDim, std::map<int, int> &elt2BC,
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
  // if((meshDim == 2) && (location != EdgeCenter) && (location != Vertex)) {
  //   Msg::Warning("Boundary condition %s is specified on %s instead of edges or "
  //                "vertices in a 2D zone, skipping", bcName,
  //                cg_GridLocationName(location));
  //   return 1;
  // }
  // else if((meshDim == 3) && (location != FaceCenter) && (location != EdgeCenter) &&
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


int readVertices(int cgIndexFile, int cgIndexBase, int iZone,
                 int dim, double scale, std::vector<ZoneInfo> &allZoneInfo,
                 std::vector<MVertex *> &allVert, std::size_t vertShift)
{
  int cgnsErr;
  ZoneInfo &zone = allZoneInfo[iZone];

  // read vertex coordinates
  std::vector<double> xyz[3];
  for(int iXYZ = 0; iXYZ < dim; iXYZ++) {
    char xyzName[CGNS_MAX_STR_LEN];
    DataType_t dataType;
    cgnsErr = cg_coord_info(cgIndexFile, cgIndexBase, iZone, iXYZ+1, &dataType,
                            xyzName);
    if(cgnsErr != CG_OK) return cgnsError();
    const int startInd[3] = {1, 1, 1};
    xyz[iXYZ].resize(zone.nbNode);
    cgnsErr = cg_coord_read(cgIndexFile, cgIndexBase, iZone, xyzName,
                            RealDouble, startInd, zone.size, xyz[iXYZ].data());
    if(cgnsErr != CG_OK) return cgnsError();
  }

  // create vertices
  allVert.reserve(vertShift+zone.nbNode);
  for(int i = 0; i < zone.nbNode; i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    allVert.push_back(new MVertex(x, y, z));
  }

  // fill periodic slave nodes
  for(std::size_t iPer = 0; iPer < zone.slaveNode.size(); iPer++) {
    Msg::Info("DBGTT: add slave vert. for per. connect %i in zone %i", iPer, iZone);
    std::vector<cgsize_t> &slaveNode = zone.slaveNode[iPer];
    std::vector<MVertex *> &slaveVert = zone.slaveVert[iPer];
    periodicVertFromNode(vertShift, allVert, slaveNode, slaveVert);
  }

  // fill periodic master nodes in all zones
  for(std::size_t iZone2 = 1; iZone2 < allZoneInfo.size(); iZone2++) {
    ZoneInfo &zone2 = allZoneInfo[iZone2];
    for(std::size_t iPer = 0; iPer < zone2.masterZone.size(); iPer++) {
      if (zone2.masterZone[iPer] != iZone) continue;
      Msg::Info("DBGTT: add master vert. from zone %i for per. connect %i in master zone %i", iZone, iPer, iZone2);
      std::vector<cgsize_t> &masterNode = zone2.masterNode[iPer];
      std::vector<MVertex *> &masterVert = zone2.masterVert[iPer];
      periodicVertFromNode(vertShift, allVert, masterNode, masterVert);
    }
  }

  return 1;
}


}   // namespace


// ---------------------------- Generic functions ------------------------------


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
    zone.index = iZone;

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
    name2Zone[std::string(zone.name)] = iZone;
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


int readZone(int cgIndexFile, int cgIndexBase, int iZone, int dim,
             int meshDim, double scale, std::vector<ZoneInfo> &allZoneInfo,
             std::vector<MVertex *> &allVert,
             std::map<int, std::vector<MElement *> > *allElt,
             std::vector<std::string> &allBCName, std::map<int, int> &bc2Family,
             std::vector<std::string> &allBCFamilyName)
{
  int cgnsErr;
  ZoneInfo &zone = allZoneInfo[iZone];

  // read dimension of coordinates and check consistency with base node
  int dimZone;
  cgnsErr = cg_ncoords(cgIndexFile, cgIndexBase, iZone, &dimZone);
  if(cgnsErr != CG_OK) return cgnsError();
  if(dimZone > dim) {
    Msg::Warning("%i coordinates in CGNS zone %i, while base has dimension %i,"
                 " discarding upper dimensions", dimZone, iZone, dim);
  }
  else if(dimZone < dim) {
    Msg::Error("%i coordinates in CGNS zone %i, while base has dimension %i",
               dimZone, iZone, dim);
    return 0;
  }

  // read boundary conditions for classification of mesh on geometry
  int nbZoneBC;
  std::map<int, int> elt2BC;
  cgnsErr = cg_nbocos(cgIndexFile, cgIndexBase, iZone, &nbZoneBC);
  if(cgnsErr != CG_OK) return cgnsError();
  for(int iZoneBC = 1; iZoneBC <= nbZoneBC; iZoneBC++) {
    int errBC = readBoundaryCondition(cgIndexFile, cgIndexBase, iZone,
                                      iZoneBC, meshDim, elt2BC, allBCName,
                                      bc2Family, allBCFamilyName);
    if(errBC == 0) return 0;
  }

  // read and create vertices
  const std::size_t vertShift = allVert.size();
  int errVert = readVertices(cgIndexFile, cgIndexBase, iZone, dim, scale,
                             allZoneInfo, allVert, vertShift);
  if(errVert == 0) return 0;

  // read and create elementss
  int err = 0;
  if (zone.type == Structured) {
    const int firstDefaultBC = allBCName.size();
    allBCName.insert(allBCName.end(), 2*meshDim, "");
    if(meshDim == 2) {
      err = readElementsStructured<2>(cgIndexFile, cgIndexBase, iZone,
                                      vertShift, zone.size, allVert, allElt,
                                      elt2BC, zone.interfaceNode,
                                      firstDefaultBC);
    }
    else if(meshDim == 3) {
      err = readElementsStructured<3>(cgIndexFile, cgIndexBase, iZone,
                                      vertShift, zone.size, allVert, allElt,
                                      elt2BC, zone.interfaceNode,
                                      firstDefaultBC);
    }
  }
  else {
    err = readElementsUnstructured(cgIndexFile, cgIndexBase, iZone,
                                   vertShift, allVert, allElt, elt2BC);
  }
  if(err == 0) return 0;

  return 1;
}


#endif // HAVE_LIBCGNS
