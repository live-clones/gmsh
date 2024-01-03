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
#include "MElement.h"
#include "pointsGenerators.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZoneStruct.h"

#if defined(HAVE_LIBCGNS)

namespace {

  template <int DIM>
  MElement *createElement(const cgsize_t *ijk, const cgsize_t *nijk, int order,
                          std::size_t vertShift,
                          std::vector<MVertex *> &allVert,
                          std::map<int, std::vector<MElement *> > *allElt);

  void initLinShift(int order, int *shift)
  {
    fullMatrix<double> mono = gmshGenerateMonomialsLine(order, false);
    for(int i = 0; i < mono.size1(); i++) {
      shift[i] = mono(i, 0) + 0.5; // round double
    }
  }

  void initQuadShift(int order, int *shift)
  {
    fullMatrix<double> mono = gmshGenerateMonomialsQuadrangle(order, false);
    for(int i = 0; i < mono.size1(); i++) {
      for(int j = 0; j < 2; j++)
        shift[i * 2 + j] = mono(i, j) + 0.5; // round double
    }
  }

  void initHexShift(int order, int *shift)
  {
    fullMatrix<double> mono = gmshGenerateMonomialsHexahedron(order, false);
    for(int i = 0; i < mono.size1(); i++) {
      for(int j = 0; j < 3; j++)
        shift[i * 3 + j] = mono(i, j) + 0.5; // round double
    }
  }

  template <>
  MElement *createElement<2>(const cgsize_t *ijk, const cgsize_t *nijk,
                             int order, std::size_t vertShift,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt)
  {
    // node shift from (i, j, k) depending on order
    static int shiftP1[4][2] = {{0, 0}, {1, 0}, {1, 1}, {0, 1}};
    static int shiftP2[9][2] = {{0, 0}, {2, 0}, {2, 2}, {0, 2}, {1, 0},
                                {2, 1}, {1, 2}, {0, 1}, {1, 1}};

    // get element vertices
    int mshEltType;
    int *s;
    if(order == 2) {
      mshEltType = MSH_QUA_9;
      s = (int *)shiftP2;
    }
    else {
      mshEltType = MSH_QUA_4;
      s = (int *)shiftP1;
    }
    int nbEltNode = ElementType::getNumVertices(mshEltType);
    std::vector<MVertex *> eltVert(nbEltNode);
    for(int iN = 0; iN < nbEltNode; iN++) {
      const cgsize_t ijN[3] = {ijk[0] + s[2 * iN], ijk[1] + s[2 * iN + 1]};
      const int ind = vertShift + ijk2Ind<2>(ijN, nijk);
      eltVert[iN] = allVert[ind];
    }

    // create element
    MElementFactory factory;
    MElement *e = factory.create(mshEltType, eltVert);

    // add element to data structure
    int entity = 1;
    allElt[3][entity].push_back(e);

    return e;
  }

  template <>
  MElement *createElement<3>(const cgsize_t *ijk, const cgsize_t *nijk,
                             int order, std::size_t vertShift,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt)
  {
    // node shift from (i, j, k) depending on order
    static bool isShiftInit[4] = {false, false, false, false};
    static int shiftP1[8 * 3], shiftP2[27 * 3], shiftP3[64 * 3],
      shiftP4[125 * 3];

    // get element vertices
    int mshEltType;
    int *s;
    switch(order) {
    case 1:
      mshEltType = MSH_HEX_8;
      if(!isShiftInit[0]) {
        initHexShift(1, shiftP1);
        isShiftInit[0] = true;
      }
      s = (int *)shiftP1;
      break;
    case 2:
      mshEltType = MSH_HEX_27;
      if(!isShiftInit[1]) {
        initHexShift(2, shiftP2);
        isShiftInit[1] = true;
      }
      s = (int *)shiftP2;
      break;
    case 3:
      mshEltType = MSH_HEX_64;
      if(!isShiftInit[2]) {
        initHexShift(3, shiftP3);
        isShiftInit[2] = true;
      }
      s = (int *)shiftP3;
      break;
    case 4:
      mshEltType = MSH_HEX_125;
      if(!isShiftInit[3]) {
        initHexShift(4, shiftP4);
        isShiftInit[3] = true;
      }
      s = (int *)shiftP4;
      break;
    default:
      Msg::Error("Cannot coarsen structured zone to order %i, falling back to "
                 "linear",
                 order);
      mshEltType = MSH_HEX_8;
      if(!isShiftInit[0]) {
        initHexShift(1, shiftP1);
        isShiftInit[0] = true;
      }
      s = (int *)shiftP1;
      break;
    }
    int nbEltNode = ElementType::getNumVertices(mshEltType);
    std::vector<MVertex *> eltVert(nbEltNode);
    for(int iN = 0; iN < nbEltNode; iN++) {
      const cgsize_t ijkN[3] = {ijk[0] + s[3 * iN], ijk[1] + s[3 * iN + 1],
                                ijk[2] + s[3 * iN + 2]};
      const cgsize_t ind = vertShift + ijk2Ind<3>(ijkN, nijk);
      eltVert[iN] = allVert[ind];
    }

    // create element
    MElementFactory factory;
    MElement *e = factory.create(mshEltType, eltVert);

    // add element to data structure
    int entity = 1;
    allElt[5][entity].push_back(e);

    return e;
  }

  template <int DIM>
  MElement *createBndElement(const cgsize_t *ijk, const cgsize_t *nijk,
                             const int *dir, int order, int entity,
                             std::size_t vertShift,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt,
                             const std::vector<bool> &interfaceNode);

  template <>
  MElement *createBndElement<2>(const cgsize_t *ijk, const cgsize_t *nijk,
                                const int *dir, int order, int entity,
                                std::size_t vertShift,
                                std::vector<MVertex *> &allVert,
                                std::map<int, std::vector<MElement *> > *allElt,
                                const std::vector<bool> &interfaceNode)
  {
    // node shift from (i, j, k) depending on order
    static bool isShiftInit[4] = {false, false, false, false};
    static int shiftP1[2], shiftP2[3], shiftP3[4], shiftP4[5];

    // get element vertices
    int mshEltType;
    int *s;
    switch(order) {
    case 1:
      mshEltType = MSH_LIN_2;
      if(!isShiftInit[0]) {
        initLinShift(1, shiftP1);
        isShiftInit[0] = true;
      }
      s = (int *)shiftP1;
      break;
    case 2:
      mshEltType = MSH_LIN_3;
      if(!isShiftInit[1]) {
        initLinShift(2, shiftP2);
        isShiftInit[1] = true;
      }
      s = (int *)shiftP2;
      break;
    case 3:
      mshEltType = MSH_LIN_4;
      if(!isShiftInit[2]) {
        initLinShift(3, shiftP3);
        isShiftInit[2] = true;
      }
      s = (int *)shiftP3;
      break;
    case 4:
      mshEltType = MSH_LIN_5;
      if(!isShiftInit[3]) {
        initLinShift(4, shiftP4);
        isShiftInit[3] = true;
      }
      s = (int *)shiftP4;
      break;
    default:
      Msg::Error("Cannot coarsen structured zone to order %i, falling back to "
                 "linear",
                 order);
      mshEltType = MSH_LIN_2;
      if(!isShiftInit[0]) {
        initLinShift(1, shiftP1);
        isShiftInit[0] = true;
      }
      s = (int *)shiftP1;
      break;
    }
    int nbEltNode = ElementType::getNumVertices(mshEltType);
    std::vector<MVertex *> eltVert(nbEltNode);
    bool isInternalInterface = true;
    for(int iN = 0; iN < nbEltNode; iN++) {
      cgsize_t ijN[2] = {ijk[0], ijk[1]};
      ijN[dir[0]] += s[iN];
      const cgsize_t ind = ijk2Ind<2>(ijN, nijk);
      isInternalInterface &= interfaceNode[ind];
      eltVert[iN] = allVert[vertShift + ind];
    }

    // do no add element if it is part of an internal interface between blocks
    if(isInternalInterface) return nullptr;

    // create element
    MElementFactory factory;
    MElement *e = factory.create(mshEltType, eltVert);

    // add element to data structure
    allElt[1][entity].push_back(e);

    return e;
  }

  template <>
  MElement *createBndElement<3>(const cgsize_t *ijk, const cgsize_t *nijk,
                                const int *dir, int order, int entity,
                                std::size_t vertShift,
                                std::vector<MVertex *> &allVert,
                                std::map<int, std::vector<MElement *> > *allElt,
                                const std::vector<bool> &interfaceNode)
  {
    // node shift from (i, j, k) depending on order
    static bool isShiftInit[4] = {false, false, false, false};
    static int shiftP1[4 * 2], shiftP2[9 * 2], shiftP3[16 * 2], shiftP4[25 * 2];

    // get element vertices
    int mshEltType;
    int *s;
    switch(order) {
    case 1:
      mshEltType = MSH_QUA_4;
      if(!isShiftInit[0]) {
        initQuadShift(1, shiftP1);
        isShiftInit[0] = true;
      }
      s = (int *)shiftP1;
      break;
    case 2:
      mshEltType = MSH_QUA_9;
      if(!isShiftInit[1]) {
        initQuadShift(2, shiftP2);
        isShiftInit[1] = true;
      }
      s = (int *)shiftP2;
      break;
    case 3:
      mshEltType = MSH_QUA_16;
      if(!isShiftInit[2]) {
        initQuadShift(3, shiftP3);
        isShiftInit[2] = true;
      }
      s = (int *)shiftP3;
      break;
    case 4:
      mshEltType = MSH_QUA_25;
      if(!isShiftInit[3]) {
        initQuadShift(4, shiftP4);
        isShiftInit[3] = true;
      }
      s = (int *)shiftP4;
      break;
    default:
      Msg::Error("Cannot coarsen structured zone to order %i, falling back to "
                 "linear",
                 order);
      mshEltType = MSH_QUA_4;
      if(!isShiftInit[0]) {
        initQuadShift(1, shiftP1);
        isShiftInit[0] = true;
      }
      s = (int *)shiftP1;
      break;
    }
    int nbEltNode = ElementType::getNumVertices(mshEltType);
    std::vector<MVertex *> eltVert(nbEltNode);
    bool isInternalInterface = true;
    for(int iN = 0; iN < nbEltNode; iN++) {
      cgsize_t ijkN[3] = {ijk[0], ijk[1], ijk[2]};
      ijkN[dir[0]] += s[2 * iN];
      ijkN[dir[1]] += s[2 * iN + 1];
      const cgsize_t ind = ijk2Ind<3>(ijkN, nijk);
      isInternalInterface &= interfaceNode[ind];
      eltVert[iN] = allVert[vertShift + ind];
    }

    // do no add element if it is part of an internal interface between blocks
    if(isInternalInterface) return nullptr;

    // create element
    MElementFactory factory;
    MElement *e = factory.create(mshEltType, eltVert);

    // add element to data structure
    allElt[3][entity].push_back(e);

    return e;
  }

} // namespace

template <int DIM>
CGNSZoneStruct<DIM>::CGNSZoneStruct(
  int fileIndex, int baseIndex, int zoneIndex, int meshDim, cgsize_t startNode,
  const Family2EltNodeTransfo &allEltNodeTransfo, int &err)
  : CGNSZone(fileIndex, baseIndex, zoneIndex, CGNS_ENUMV(Structured), meshDim,
             startNode, allEltNodeTransfo, err)
{
  // Check consistency
  bool ok = true;
  for(int d = 0; d < DIM; d++) ok &= (nbNodeIJK(d) == nbEltIJK(d) + 1);
  if(ok)
    err = 1;
  else {
    Msg::Error("CGNS zone %i: number of vertices (%i, %i, %i) is inconsistent "
               "with number of elements (%i, %i, %i)",
               zoneIndex, nbNodeIJK(0), nbNodeIJK(1),
               (DIM == 3) ? nbNodeIJK(2) : 0, nbEltIJK(0), nbEltIJK(1),
               (DIM == 3) ? nbEltIJK(2) : 0);
    err = 0;
  }

  // number of nodes and elements
  nbNode_ = nbTotFromIJK<DIM>(nbNodeIJK());
  nbElt_ = nbTotFromIJK<DIM>(nbEltIJK());

  interfaceNode_.resize(nbNode());
}

template <int DIM>
int CGNSZoneStruct<DIM>::readElements(
  std::vector<MVertex *> &allVert,
  std::map<int, std::vector<MElement *> > *allElt,
  std::vector<MElement *> &zoneElt, std::vector<std::string> &allGeomName)
{
  // default BC (in case none specified)
  const int firstDefaultEnt = allGeomName.size();
  allGeomName.insert(allGeomName.end(), 2 * meshDim(), "");

  // order of coarsened mesh and number of potentially coarsened (HO) elements
  int order = CTX::instance()->mesh.cgnsImportOrder;
  if(order > 4) {
    Msg::Warning("Cannot coarsen structured grid to order %i, creating linear "
                 "mesh in zone %i",
                 order, index());
    order = 1;
  }
  else {
    bool orderOK = true;
    for(int d = 0; d < DIM; d++) orderOK &= (nbEltIJK(d) % order == 0);
    if(!orderOK) {
      Msg::Warning("Zone %i has (%i, %i, %i) vertices which cannot be coarsened"
                   " to order %i, creating linear mesh",
                   index(), nbNodeIJK(0), nbNodeIJK(1),
                   (DIM == 3) ? nbNodeIJK(2) : 0, order);
      order = 1;
    }
  }
  const int nbEltI = nbEltIJK(0) / order;
  const int nbEltJ = nbEltIJK(1) / order;
  const int nbEltK = (DIM == 3) ? nbEltIJK(2) / order : 1;

  // create domain elements
  for(int k = 0; k < nbEltK; k++) {
    for(int j = 0; j < nbEltJ; j++) {
      for(int i = 0; i < nbEltI; i++) {
        const cgsize_t ijk[3] = {i * order, j * order, k * order};
        MElement *me = createElement<DIM>(ijk, nbNodeIJK(), order, startNode(),
                                          allVert, allElt);
        zoneElt.push_back(me);
      }
    }
  }

  // create boundary elements for block faces i- and i+
  for(int k = 0; k < nbEltK; k++) {
    for(int j = 0; j < nbEltJ; j++) {
      static const int dir[2] = {1, 2};
      cgsize_t ijk[3] = {0, j * order, k * order};
      MElement *me;
      me = makeBndElement(ijk, dir, order, firstDefaultEnt, allVert, allElt);
      if(me != nullptr) zoneElt.push_back(me);
      ijk[0] = nbNodeIJK(0) - 1;
      me =
        makeBndElement(ijk, dir, order, firstDefaultEnt + 1, allVert, allElt);
      if(me != nullptr) zoneElt.push_back(me);
    }
  }

  // create boundary elements for block faces j- and j+
  for(int k = 0; k < nbEltK; k++) {
    for(int i = 0; i < nbEltI; i++) {
      static const int dir[2] = {0, 2};
      cgsize_t ijk[3] = {i * order, 0, k * order};
      MElement *me;
      me =
        makeBndElement(ijk, dir, order, firstDefaultEnt + 2, allVert, allElt);
      if(me != nullptr) zoneElt.push_back(me);
      ijk[1] = nbNodeIJK(1) - 1;
      me =
        makeBndElement(ijk, dir, order, firstDefaultEnt + 3, allVert, allElt);
      if(me != nullptr) zoneElt.push_back(me);
    }
  }

  // create boundary elements for block faces k- and k+ if 3D
  if(DIM == 3) {
    for(int j = 0; j < nbEltJ; j++) {
      for(int i = 0; i < nbEltI; i++) {
        static const int dir[2] = {0, 1};
        cgsize_t ijk[3] = {i * order, j * order, 0};
        MElement *me;
        me =
          makeBndElement(ijk, dir, order, firstDefaultEnt + 4, allVert, allElt);
        if(me != nullptr) zoneElt.push_back(me);
        ijk[2] = nbNodeIJK(2) - 1;
        me =
          makeBndElement(ijk, dir, order, firstDefaultEnt + 5, allVert, allElt);
        if(me != nullptr) zoneElt.push_back(me);
      }
    }
  }

  return 1;
}

template <int DIM>
MElement *CGNSZoneStruct<DIM>::makeBndElement(
  const cgsize_t *ijk, const int *dir, int order, int defaultEntity,
  std::vector<MVertex *> &allVert,
  std::map<int, std::vector<MElement *> > *allElt)
{
  cgsize_t iElt = ijk2Ind<DIM>(ijk, nbNodeIJK());
  const auto it = elt2Geom().find(iElt);
  const int entity = (it == elt2Geom().end()) ? defaultEntity : it->second;

  return createBndElement<DIM>(ijk, nbNodeIJK(), dir, order, entity,
                               startNode(), allVert, allElt, interfaceNode());
}

template <int DIM>
int CGNSZoneStruct<DIM>::readConnectivities(
  const std::map<std::string, int> &name2Zone,
  std::vector<CGNSZone *> &allZones)
{
  int cgnsErr;

  // read generic connectivities
  CGNSZone::readConnectivities(name2Zone, allZones);

  // read number of 1to1 interfaces
  int nbConnect;
  cgnsErr = cg_n1to1(fileIndex(), baseIndex(), index(), &nbConnect);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // sweep over interfaces
  for(int iConnect = 1; iConnect <= nbConnect; iConnect++) {
    int err;
    err = readOneInterface(iConnect, name2Zone, allZones);
    if(err == 0) return 0;
  }

  return 1;
}

template <int DIM>
int CGNSZoneStruct<DIM>::readOneInterface(
  int iConnect, const std::map<std::string, int> &name2Zone,
  std::vector<CGNSZone *> &allZones)
{
  int cgnsErr;

  // read connection
  char connectName[CGNS_MAX_STR_LEN], donorName[CGNS_MAX_STR_LEN];
  cgsize_t range[2 * DIM], rangeDonnor[2 * DIM];
  int indexTransfo[DIM];
  cgnsErr =
    cg_1to1_read(fileIndex(), baseIndex(), index(), iConnect, connectName,
                 donorName, range, rangeDonnor, indexTransfo);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // read periodic connection information
  bool periodic = false;
  float rotCenter[3], rotAngle[3], translat[3];
  cgnsErr = cg_1to1_periodic_read(fileIndex(), baseIndex(), index(), iConnect,
                                  rotCenter, rotAngle, translat);
  if(cgnsErr != CG_NODE_NOT_FOUND) {
    if(cgnsErr == CG_OK)
      periodic = true;
    else
      return cgnsError(__FILE__, __LINE__, fileIndex());
  }

  // if not periodic, mark as internal interface and return
  if(!periodic) {
    std::vector<cgsize_t> indNode;
    nodeFromRange(range, indNode);
    for(std::size_t i = 0; i < indNode.size(); i++) {
      interfaceNode_[indNode[i]] = true;
    }
    return 1;
  }

  // TODO: fix periodicity in structured zones
  // // range of IJK indices
  // const cgsize_t ijkMin[3] = {range[0]-1, range[1]-1,
  //                             (DIM == 3) ? range[2]-1 : 0};
  // const cgsize_t ijkMax[3] = {range[DIM]-1, range[DIM+1]-1,
  //                             (DIM == 3) ? range[5]-1 : 0};

  // // identify donnor (master) zone
  // auto itDN = name2Zone.find(donorName);
  // if(itDN == name2Zone.end()) {
  //   Msg::Error("Donnor zone '%s' not found in structured connectivity '%s' "
  //              "of zone %i ('%s')", donorName, connectName, zone.index,
  //              zone.name);
  //   return 0;
  // }
  // const int iZoneD = itDN->second;
  // zone.masterZone.push_back(iZoneD);

  // // periodic transformation
  // zone.perTransfo.push_back(std::vector<double>());
  // computeAffineTransformation(rotCenter, rotAngle, translat,
  //                             zone.perTransfo.back());

  // // number of nodes and origin of donnor (master) interface
  // cgsize_t nijk[3] = {0, 0, 0};
  // for(int d = 0; d < DIM; d++) nijk[d] = ijkMax[d]-ijkMin[d]+1;
  // const cgsize_t nbNode = nijk[0]*nijk[1]*nijk[2];

  // // indexation in donnor zone
  // ZoneInfo &zoneD = allZoneInfo[iZoneD];
  // int errD = 1;
  // StructuredInd<DIM> siD(iZoneD, zoneD.size, errD);
  // if(errD == 0) return 0;
  // const cgsize_t ijkMinD[3] = {rangeDonnor[0]-1, rangeDonnor[1]-1,
  //                              (DIM == 3) ? rangeDonnor[2]-1 : 1};

  // // IJK directions and sign for master-slave index transformation
  // int dir[3] = {-1, -1, 2};
  // for(int d = 0; d < DIM; d++) dir[d] = std::abs(indexTransfo[d])-1;
  // bool signDir[3] = {true, true, true};
  // for(int d = 0; d < DIM; d++) signDir[d] = (indexTransfo[d] > 0);

  // // allocate storage for node correspondence
  // zone.slaveNode.push_back(std::vector<cgsize_t>());
  // std::vector<cgsize_t> &slaveNode = zone.slaveNode.back();
  // slaveNode.reserve(nbNode);
  // zone.slaveVert.push_back(std::vector<MVertex *>());
  // zone.slaveVert.back().reserve(nbNode);
  // zone.masterNode.push_back(std::vector<cgsize_t>());
  // std::vector<cgsize_t> &masterNode = zone.masterNode.back();
  // masterNode.reserve(nbNode);
  // zone.masterVert.push_back(std::vector<MVertex *>());
  // zone.masterVert.back().reserve(nbNode);

  // // store periodic node correspondence
  // int ijk[3], ijkD[3];
  // for(int k = 0; k < nijk[2]; k++) {
  //   ijk[2] = ijkMin[2] + k;
  //   for(int j = 0; j < nijk[1]; j++) {
  //     ijk[1] = ijkMin[1] + j;
  //     for(int i = 0; i < nijk[0]; i++) {
  //       ijk[0] = ijkMin[0] + i;
  //       for(int d = 0; d < DIM; d++) ijkD[d] = ijkMinD[d];
  //       ijkD[dir[0]] += signDir[dir[0]] ? i : -i;
  //       ijkD[dir[1]] += signDir[dir[1]] ? j : -j;
  //       ijkD[dir[2]] += signDir[dir[2]] ? k : -k;
  //       slaveNode.push_back(si.Node(ijk));
  //       masterNode.push_back(siD.Node(ijkD));
  //     }
  //   }
  // }

  return 1;
}

// explicit instantiation

template class CGNSZoneStruct<2>;
template class CGNSZoneStruct<3>;

#endif // HAVE_LIBCGNS
