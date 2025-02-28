// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#include "GmshMessage.h"
#include "MVertex.h"
#include "MElement.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZoneUnstruct.h"

#if defined(HAVE_LIBCGNS)

namespace {

  MElement *createElement(CGNS_ENUMT(ElementType_t) sectEltType,
                          std::size_t vertShift, int entity,
                          const std::vector<MVertex *> &allVert,
                          std::map<int, std::vector<MElement *> > *allElt,
                          const std::vector<cgsize_t> &sectData,
                          const ZoneEltNodeTransfo *eltNodeTransfo,
                          const std::vector<SPoint3> &rawNode,
                          std::size_t &iSectData)
  {
    // get element type
    CGNS_ENUMT(ElementType_t) eltType;
    if(sectEltType == CGNS_ENUMV(MIXED)) {
      eltType = static_cast<CGNS_ENUMT(ElementType_t)>(sectData[iSectData]);
      iSectData++;
    }
    else
      eltType = sectEltType;

    // get element vertices in Gmsh ordering
    int mshEltType = cgns2MshEltType(eltType);
    int nbEltNode = ElementType::getNumVertices(mshEltType);

    // element high-order node transformation if specified (CPEX0045), otherwise
    // use the classic CGNS order
    const std::vector<int> *nodeTransfo = nullptr;
    if((mshEltType != MSH_PNT) && (eltNodeTransfo != nullptr) &&
       (eltNodeTransfo->size() > 0)) {
      nodeTransfo = &((*eltNodeTransfo)[mshEltType]);
    }
    else
      nodeTransfo = &(cgns2MshNodeIndex(mshEltType));

    // get element vertices
    std::vector<MVertex *> eltVert(nbEltNode);
    for(int iEltNode = 0; iEltNode < nbEltNode; iEltNode++, iSectData++) {
      const int indNode = vertShift + sectData[iSectData] - 1;
      eltVert[(*nodeTransfo)[iEltNode]] = allVert[indNode];
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

    return e;
  }

} // namespace

CGNSZoneUnstruct::CGNSZoneUnstruct(
  int fileIndex, int baseIndex, int zoneIndex, int meshDim, cgsize_t startNode,
  const Family2EltNodeTransfo &allEltNodeTransfo, int &err)
  : CGNSZone(fileIndex, baseIndex, zoneIndex, CGNS_ENUMV(Unstructured), meshDim,
             startNode, allEltNodeTransfo, err)
{
  if(err == 0) return;

  // number of nodes and elements
  nbNode_ = size_[0];
  nbElt_ = size_[1];

  interfaceNode_.resize(nbNode());
}

int CGNSZoneUnstruct::readSection(
  int iSect, const std::vector<MVertex *> &allVert,
  const std::vector<SPoint3> &rawNode,
  std::map<int, std::vector<MElement *> > *allElt,
  std::vector<MElement *> &zoneElt)
{
  int cgnsErr;

  // read section information
  char sectName[CGNS_MAX_STR_LEN];
  CGNS_ENUMT(ElementType_t) sectEltType;
  cgsize_t startElt, endElt;
  int nbBnd, parentFlag;
  cgnsErr =
    cg_section_read(fileIndex(), baseIndex(), index(), iSect, sectName,
                    &sectEltType, &startElt, &endElt, &nbBnd, &parentFlag);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

    // check for compatibility with MIXED element sections
#if CGNS_VERSION < 4000
  if(sectEltType == CGNS_ENUMV(MIXED)) {
    Msg::Error("Reading 'MIXED' element sections requires CGNS library "
               "version >= 4");
    return 0;
  }
#endif

  // read connectivity data size
  cgsize_t dataSize;
  cgnsErr =
    cg_ElementDataSize(fileIndex(), baseIndex(), index(), iSect, &dataSize);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // read connectivity data
  std::vector<cgsize_t> sectData(dataSize), offsetData(endElt - startElt + 2);
  if(sectEltType == CGNS_ENUMV(MIXED)) {
#if CGNS_VERSION >= 4000
    cgnsErr =
      cg_poly_elements_read(fileIndex(), baseIndex(), index(), iSect,
                            sectData.data(), offsetData.data(), nullptr);
#endif
  }
  else {
    cgnsErr = cg_elements_read(fileIndex(), baseIndex(), index(), iSect,
                               sectData.data(), nullptr);
  }
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // create elements
  std::size_t iSectData = 0;
  if(endElt > (cgsize_t)zoneElt.size()) zoneElt.resize(endElt);
  const cgsize_t iStartElt = startElt - 1, iEndElt = endElt - 1;
  for(int iElt = iStartElt; iElt <= iEndElt; iElt++) {
    const auto it = elt2Geom().find(iElt);
    const int entity = (it == elt2Geom().end()) ? 1 : it->second;
    MElement *me =
      createElement(sectEltType, startNode(), entity, allVert, allElt, sectData,
                    eltNodeTransfo(), rawNode, iSectData);
    zoneElt[iElt] = me;
  }

  return 1;
}

int CGNSZoneUnstruct::readElements(
  std::vector<MVertex *> &allVert,
  std::map<int, std::vector<MElement *> > *allElt,
  std::vector<MElement *> &zoneElt, std::vector<std::string> &allGeomName)
{
  int cgnsErr;

  // data structures for node coordinate transformation (CPEX0045)
  // std::vector<bool> nodeUpdated;
  std::vector<SPoint3> rawNode;
  if(eltNodeTransfo() != nullptr) {
    // nodeUpdated = std::vector<bool>(nbNode(), false);
    rawNode.resize(nbNode());
    for(int iN = 0; iN < nbNode(); iN++) {
      rawNode[iN] = allVert[startNode() + iN]->point();
    }
  }

  // read number of sections of element-vertex connectivity
  int nbSect;
  cgnsErr = cg_nsections(fileIndex(), baseIndex(), index(), &nbSect);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex());

  // read sections of element-vertex connectivity
  zoneElt.reserve(nbElt());
  for(int iSect = 1; iSect <= nbSect; iSect++) {
    int err = readSection(iSect, allVert, rawNode, allElt, zoneElt);
    if(err == 0) return 0;
  }

  return 1;
}

#endif // HAVE_LIBCGNS
