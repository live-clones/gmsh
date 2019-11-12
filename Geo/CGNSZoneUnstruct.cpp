// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "MVertex.h"
#include "MElement.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZoneUnstruct.h"

#if defined(HAVE_LIBCGNS)


namespace {


void createElement(ElementType_t sectEltType, std::size_t vertShift, int entity,
                   const std::vector<MVertex *> &allVert,
                   std::map<int, std::vector<MElement *> > *allElt,
                   const std::vector<cgsize_t> &sectData,
                   const ZoneEltNodeTransfo *eltNodeTransfo,
                   const std::vector<SPoint3> &rawNode, std::size_t &iSectData)
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

  // element node transformation if specified (CPEX0045) 
  const fullMatrix<double> *transfoMat = 0;
  if((eltNodeTransfo != 0) || (eltNodeTransfo->size() > 0)) {
    transfoMat = &((*eltNodeTransfo)[mshEltType]);
  }

  // get element vertices
  std::vector<MVertex *> eltVert(nbEltNode);
  if(transfoMat == 0) {
    // get element vertices in Gmsh ordering from CGNS ordering
    const std::vector<int> &cgns2Msh = cgns2MshNodeIndex(mshEltType);
    for(int iEltNode = 0; iEltNode < nbEltNode; iEltNode++, iSectData++) {
      const int indNode = vertShift + sectData[iSectData] - 1;
      eltVert[cgns2Msh[iEltNode]] = allVert[indNode];
    }
  }
  else {
    // get element vertices and retrieve original node coordinates
    fullMatrix<double> oldEltNode(nbEltNode, 3);
    for(int iEltNode = 0; iEltNode < nbEltNode; iEltNode++, iSectData++) {
      const int indNode = vertShift + sectData[iSectData] - 1;
      eltVert[iEltNode] = allVert[indNode];
      oldEltNode(iEltNode, 0) = rawNode[indNode].x();
      oldEltNode(iEltNode, 1) = rawNode[indNode].y();
      oldEltNode(iEltNode, 2) = rawNode[indNode].z();
    }

    // transform original into Gmsh node coordinates
    fullMatrix<double> newEltNode(nbEltNode, 3);
    newEltNode.gemm(*transfoMat, oldEltNode);
    
    // update vertices
    for(int iEltNode = 0; iEltNode < nbEltNode; iEltNode++) {
      const double &xNew = newEltNode(iEltNode, 0);
      const double &yNew = newEltNode(iEltNode, 1);
      const double &zNew = newEltNode(iEltNode, 2);
      eltVert[iEltNode]->setXYZ(xNew, yNew, zNew);
    }
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


} // namespace


CGNSZoneUnstruct::CGNSZoneUnstruct(int fileIndex, int baseIndex, int zoneIndex,
                                int meshDim, cgsize_t startNode,
                                const Family2EltNodeTransfo &allEltNodeTransfo,
                                int &err) :
  CGNSZone(fileIndex, baseIndex, zoneIndex, meshDim, startNode,
           allEltNodeTransfo, err)
{
  // number of nodes and elements
  nbNode_ = size_[0];
  nbElt_ = size_[1];

  interfaceNode_.resize(nbNode());
}


int CGNSZoneUnstruct::readSection(int iSect,
                                  const std::vector<MVertex *> &allVert,
                                  const std::vector<SPoint3> &rawNode,
                                  std::map<int,
                                           std::vector<MElement *> > *allElt)
{
  int cgnsErr;

  // read section information
  char sectName[CGNS_MAX_STR_LEN];
  ElementType_t sectEltType;
  cgsize_t startElt, endElt;
  int nbBnd, parentFlag;
  cgnsErr = cg_section_read(fileIndex(), baseIndex(), index(), iSect, sectName,
                            &sectEltType, &startElt, &endElt, &nbBnd,
                            &parentFlag);
  if(cgnsErr != CG_OK) return cgnsError();

  // read connectivity data size
  cgsize_t dataSize;
  cgnsErr = cg_ElementDataSize(fileIndex(), baseIndex(), index(), iSect,
                               &dataSize);
  if(cgnsErr != CG_OK) return cgnsError();

  // read connectivity data
  std::vector<cgsize_t> sectData(dataSize);
  cgnsErr = cg_elements_read(fileIndex(), baseIndex(), index(), iSect,
                             sectData.data(), 0);
  if(cgnsErr != CG_OK) return cgnsError();

  // create elements
  std::size_t iSectData = 0;
  const cgsize_t iStartElt = startElt-1, iEndElt = endElt-1;
  for(int iElt = iStartElt; iElt <= iEndElt; iElt++) {
    const std::map<int, int>::const_iterator itBC = elt2BC_.find(iElt);
    const int entity = (itBC == elt2BC_.end()) ? 1 : itBC->second;
    createElement(sectEltType, startNode(), entity, allVert, allElt, sectData,
                  eltNodeTransfo(), rawNode, iSectData);
  }

  return 1;
}


int CGNSZoneUnstruct::readElements(std::vector<MVertex *> &allVert,
                                std::map<int, std::vector<MElement *> > *allElt,
                                std::vector<std::string> &allBCName)
{
  int cgnsErr;

  // data structures for node coordinate transformation (CPEX0045)
  // std::vector<bool> nodeUpdated;
  std::vector<SPoint3> rawNode;
  if(eltNodeTransfo() != 0) {
    // nodeUpdated = std::vector<bool>(nbNode(), false);
    rawNode.resize(nbNode());
    for(int iN = 0; iN < nbNode(); iN++) {
      rawNode[iN] = allVert[startNode()+iN]->point();
    } 
  }

  // read number of sections of element-vertex connectivity
  int nbSect;
  cgnsErr = cg_nsections(fileIndex(), baseIndex(), index(), &nbSect);
  if(cgnsErr != CG_OK) return cgnsError();

  // read sections of element-vertex connectivity
  for(int iSect = 1; iSect <= nbSect; iSect++) {
    int err = readSection(iSect, allVert, rawNode, allElt);
    if(err == 0) return 0;
  }

  return 1;
}


#endif // HAVE_LIBCGNS
