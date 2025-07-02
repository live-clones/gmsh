// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"

#if defined(HAVE_MED)

#include <string.h>
#include <map>
#include <sstream>
#include <vector>
#include "MVertex.h"
#include "MPoint.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "discreteVertex.h"
#include "Context.h"

#include <med.h>

#if(MED_MAJOR_NUM >= 3)
// To avoid too many ifdefs below we use defines for the bits of the
// API that did not change too much between MED2 and MED3. If we remove
// MED2 support at some point, please remove these defines and replace
// the symbols accordingly.
#define med_geometrie_element med_geometry_type
#define med_maillage med_mesh_type
#define MED_TAILLE_NOM MED_NAME_SIZE
#define MED_TAILLE_LNOM MED_LNAME_SIZE
#define MED_TAILLE_DESC MED_COMMENT_SIZE
#define MED_NON_STRUCTURE MED_UNSTRUCTURED_MESH
#define MED_LECTURE MED_ACC_RDONLY
#define MED_CREATION MED_ACC_CREAT
#define MEDouvrir MEDfileOpen
#define MEDversionDonner MEDlibraryNumVersion
#define MEDversionLire MEDfileNumVersionRd
#define MEDnMaa MEDnMesh
#define MEDfermer MEDfileClose
#define MEDnFam MEDnFamily
#define MEDfichDesEcr MEDfileCommentWr
#endif

med_geometrie_element msh2medElementType(int msh)
{
  switch(msh) {
  case MSH_LIN_2: return MED_SEG2;
  case MSH_TRI_3: return MED_TRIA3;
  case MSH_QUA_4: return MED_QUAD4;
  case MSH_TET_4: return MED_TETRA4;
  case MSH_HEX_8: return MED_HEXA8;
  case MSH_PRI_6: return MED_PENTA6;
  case MSH_PYR_5: return MED_PYRA5;
  case MSH_LIN_3: return MED_SEG3;
  case MSH_TRI_6: return MED_TRIA6;
  case MSH_TET_10: return MED_TETRA10;
  case MSH_PNT: return MED_POINT1;
  case MSH_QUA_8: return MED_QUAD8;
  case MSH_HEX_20: return MED_HEXA20;
  case MSH_PRI_15: return MED_PENTA15;
#if(MED_MAJOR_NUM >= 4)
  case MSH_PRI_18: return MED_PENTA18;
#endif
  case MSH_PYR_13: return MED_PYRA13;
#if(MED_MAJOR_NUM >= 3)
  case MSH_QUA_9: return MED_QUAD9;
  case MSH_HEX_27: return MED_HEXA27;
#endif
  default: return MED_NONE;
  }
}

int med2mshElementType(med_geometrie_element med)
{
  switch(med) {
  case MED_SEG2: return MSH_LIN_2;
  case MED_TRIA3: return MSH_TRI_3;
  case MED_QUAD4: return MSH_QUA_4;
  case MED_TETRA4: return MSH_TET_4;
  case MED_HEXA8: return MSH_HEX_8;
  case MED_PENTA6: return MSH_PRI_6;
  case MED_PYRA5: return MSH_PYR_5;
  case MED_SEG3: return MSH_LIN_3;
  case MED_TRIA6: return MSH_TRI_6;
  case MED_TETRA10: return MSH_TET_10;
  case MED_POINT1: return MSH_PNT;
  case MED_QUAD8: return MSH_QUA_8;
  case MED_HEXA20: return MSH_HEX_20;
  case MED_PENTA15: return MSH_PRI_15;
#if(MED_MAJOR_NUM >= 4)
  case MED_PENTA18: return MSH_PRI_18;
#endif
  case MED_PYRA13: return MSH_PYR_13;
#if(MED_MAJOR_NUM >= 3)
  case MED_QUAD9: return MSH_QUA_9;
  case MED_HEXA27: return MSH_HEX_27;
#endif
  default: return 0;
  }
}

int msh2medNodeIndex(int msh, int k)
{
  med_geometrie_element med = msh2medElementType(msh);
  switch(med) {
  case MED_POINT1:
  case MED_SEG2:
  case MED_SEG3:
  case MED_TRIA3:
  case MED_TRIA6:
  case MED_QUAD4:
  case MED_QUAD8:
#if(MED_MAJOR_NUM >= 3)
  case MED_QUAD9:
#endif
    return k; // same node numbering as in Gmsh
  case MED_TETRA4: {
    static const int map[4] = {0, 2, 1, 3};
    return map[k];
  }
  case MED_TETRA10: {
    static const int map[10] = {0, 2, 1, 3, 6, 5, 4, 7, 8, 9};
    return map[k];
  }
  case MED_HEXA8: {
    static const int map[8] = {0, 3, 2, 1, 4, 7, 6, 5};
    return map[k];
  }
  case MED_HEXA20: {
    static const int map[20] = {0,  3, 2,  1,  4,  7,  6,  5,  9,  13,
                                11, 8, 17, 19, 18, 16, 10, 15, 14, 12};

    return map[k];
  }
#if(MED_MAJOR_NUM >= 3)
  case MED_HEXA27: {
    static const int map[27] = {0,  3,  2,  1,  4,  7,  6,  5,  9,
                                13, 11, 8,  17, 19, 18, 16, 10, 15,
                                14, 12, 20, 22, 24, 23, 21, 25, 26};
    return map[k];
  }
#endif
  case MED_PENTA6: {
    static const int map[6] = {0, 2, 1, 3, 5, 4};
    return map[k];
  }
  case MED_PENTA15: {
    static const int map[15] = {0, 2,  1,  3,  5, 4,  7, 9,
                                6, 13, 14, 12, 8, 11, 10};
    return map[k];
  }
#if(MED_MAJOR_NUM >= 4)
  case MED_PENTA18: {
    static const int map[18] = {0,  2,  1,  3, 5,  4,  7,  9,  6,
                                13, 14, 12, 8, 11, 10, 16, 17, 15};
    return map[k];
  }
#endif
  case MED_PYRA5: {
    static const int map[5] = {0, 3, 2, 1, 4};
    return map[k];
  }
  case MED_PYRA13: {
    static const int map[13] = {0, 3, 2, 1, 4, 6, 10, 8, 5, 7, 12, 11, 9};
    return map[k];
  }
  default: Msg::Error("Unknown MED element type"); return k;
  }
}

int med2mshNodeIndex(med_geometrie_element med, int k)
{
  switch(med) {
  case MED_POINT1:
  case MED_SEG2:
  case MED_SEG3:
  case MED_TRIA3:
  case MED_TRIA6:
  case MED_QUAD4:
  case MED_QUAD8:
#if(MED_MAJOR_NUM >= 3)
  case MED_QUAD9:
#endif
    return k; // same node numbering as in Gmsh
  case MED_TETRA4:
  case MED_TETRA10:
  case MED_HEXA8:
  case MED_PENTA6:
  case MED_PYRA5:
    return msh2medNodeIndex(med2mshElementType(med), k); // symmetric
  case MED_HEXA20: {
    static const int map[20] = {0,  3,  2,  1, 4,  7,  6,  5,  11, 8,
                                16, 10, 19, 9, 18, 17, 15, 12, 14, 13};
    return map[k];
  }
#if(MED_MAJOR_NUM >= 3)
  case MED_HEXA27: {
    static const int map[27] = {0,  3,  2,  1,  4,  7,  6,  5,  11,
                                8,  16, 10, 19, 9,  18, 17, 15, 12,
                                14, 13, 20, 24, 21, 23, 22, 25, 26};
    return map[k];
  }
#endif
  case MED_PENTA15: {
    static const int map[15] = {0,  2, 1,  3,  5,  4, 8, 6,
                                12, 7, 14, 13, 11, 9, 10};
    return map[k];
  }
#if(MED_MAJOR_NUM >= 4)
  case MED_PENTA18: {
    static const int map[18] = {0, 2,  1,  3,  5, 4,  8,  6,  12,
                                7, 14, 13, 11, 9, 10, 17, 15, 16};
    return map[k];
  }
#endif
  case MED_PYRA13: {
    static const int map[13] = {0, 3, 2, 1, 4, 8, 5, 9, 7, 12, 6, 11, 10};
    return map[k];
  }
  default: Msg::Error("Unknown MED element type"); return k;
  }
}

int GModel::readMED(const std::string &name)
{
  med_idt fid = MEDouvrir((char *)name.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  med_int v[3], vf[3];
  MEDversionDonner(&v[0], &v[1], &v[2]);
  MEDversionLire(fid, &vf[0], &vf[1], &vf[2]);
  Msg::Info("Reading MED file V%d.%d.%d using MED library V%d.%d.%d", vf[0],
            vf[1], vf[2], v[0], v[1], v[2]);
  if(vf[0] < 2 || (vf[0] == 2 && vf[1] < 2)) {
    Msg::Error("Cannot read MED file older than V2.2");
    return 0;
  }

  std::vector<std::string> meshNames;
  for(int i = 0; i < MEDnMaa(fid); i++) {
    char meshName[MED_TAILLE_NOM + 1], meshDesc[MED_TAILLE_DESC + 1];
    med_int spaceDim;
    med_maillage meshType;
#if(MED_MAJOR_NUM >= 3)
    med_int meshDim, nStep;
    char dtUnit[MED_SNAME_SIZE + 1];
    char axisName[3 * MED_SNAME_SIZE + 1], axisUnit[3 * MED_SNAME_SIZE + 1];
    med_sorting_type sortingType;
    med_axis_type axisType;
    if(MEDmeshInfo(fid, i + 1, meshName, &spaceDim, &meshDim, &meshType,
                   meshDesc, dtUnit, &sortingType, &nStep, &axisType, axisName,
                   axisUnit) < 0) {
#else
    if(MEDmaaInfo(fid, i + 1, meshName, &spaceDim, &meshType, meshDesc) < 0) {
#endif
      Msg::Error("Unable to read mesh information");
      return 0;
    }
    meshNames.push_back(meshName);
  }

  if(MEDfermer(fid) < 0) {
    Msg::Error("Unable to close file '%s'", name.c_str());
    return 0;
  }

  int ret = 1;
  for(std::size_t i = 0; i < meshNames.size(); i++) {
    // we use the filename as a kind of "partition" indicator, allowing to
    // complete a model part by part (used e.g. in DDM, since MED does not store
    // a partition index)
    GModel *m = findByName(meshNames[i], name);
    if(!m) m = new GModel(meshNames[i]);
    ret = m->readMED(name, i);
    if(!ret) return 0;
  }
  return ret;
}

int GModel::readMED(const std::string &name, int meshIndex)
{
  med_idt fid = MEDouvrir((char *)name.c_str(), MED_LECTURE);
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  int numMeshes = MEDnMaa(fid);
  if(meshIndex >= numMeshes) {
    Msg::Info("Could not find mesh %d in MED file", meshIndex);
    return 0;
  }

  checkPointMaxNumbers();
  GModel::setCurrent(this); // make sure we increment max nums in this model

  // read mesh info
  char meshName[MED_TAILLE_NOM + 1], meshDesc[MED_TAILLE_DESC + 1];
  med_int spaceDim, nStep = 1;
  med_maillage meshType;
#if(MED_MAJOR_NUM >= 3)
  med_int meshDim;
  char dtUnit[MED_SNAME_SIZE + 1];
  char axisName[3 * MED_SNAME_SIZE + 1], axisUnit[3 * MED_SNAME_SIZE + 1];
  med_sorting_type sortingType;
  med_axis_type axisType;
  if(MEDmeshInfo(fid, meshIndex + 1, meshName, &spaceDim, &meshDim, &meshType,
                 meshDesc, dtUnit, &sortingType, &nStep, &axisType, axisName,
                 axisUnit) < 0) {
#else
  if(MEDmaaInfo(fid, meshIndex + 1, meshName, &spaceDim, &meshType, meshDesc) <
     0) {
#endif
    Msg::Error("Unable to read mesh information");
    return 0;
  }

  // FIXME: we should support multi-step MED3 meshes (probably by
  // storing each mesh as a separate model, with a naming convention
  // e.g. meshName_step%d). This way we could also handle multi-mesh
  // time sequences in MED3.
  if(nStep > 1)
    Msg::Warning("Discarding %d last meshes in multi-step MED mesh", nStep - 1);

  setName(meshName);
  setFileName(name);
  if(meshType == MED_NON_STRUCTURE) {
    Msg::Info("Reading %d-D unstructured mesh '%s'", spaceDim, meshName);
  }
  else {
    Msg::Error("Reading structured MED meshes is not supported");
    return 0;
  }
  med_int vf[3];
  MEDversionLire(fid, &vf[0], &vf[1], &vf[2]);

  // read nodes
#if(MED_MAJOR_NUM >= 3)
  med_bool changeOfCoord, geoTransform;
  med_int numNodes = MEDmeshnEntity(
    fid, meshName, MED_NO_DT, MED_NO_IT, MED_NODE, MED_NO_GEOTYPE,
    MED_COORDINATE, MED_NO_CMODE, &changeOfCoord, &geoTransform);
#else
  med_int numNodes =
    MEDnEntMaa(fid, meshName, MED_COOR, MED_NOEUD, MED_NONE, MED_NOD);
#endif
  if(numNodes < 0) {
    Msg::Error("Could not read number of MED nodes");
    return 0;
  }
  if(numNodes == 0) {
    Msg::Error("No nodes in MED mesh");
    return 0;
  }
  std::vector<MVertex *> verts(numNodes);
  std::vector<med_float> coord(spaceDim * numNodes);
#if(MED_MAJOR_NUM >= 3)
  if(MEDmeshNodeCoordinateRd(fid, meshName, MED_NO_DT, MED_NO_IT,
                             MED_FULL_INTERLACE, &coord[0]) < 0) {
#else
  std::vector<char> coordName(spaceDim * MED_TAILLE_PNOM + 1);
  std::vector<char> coordUnit(spaceDim * MED_TAILLE_PNOM + 1);
  med_repere rep;
  if(MEDcoordLire(fid, meshName, spaceDim, &coord[0], MED_FULL_INTERLACE,
                  MED_ALL, 0, 0, &rep, &coordName[0], &coordUnit[0]) < 0) {
#endif
    Msg::Error("Could not read MED node coordinates");
    return 0;
  }

  std::vector<med_int> nodeTags(numNodes);
#if(MED_MAJOR_NUM >= 3)
  if(MEDmeshEntityNumberRd(fid, meshName, MED_NO_DT, MED_NO_IT, MED_NODE,
                           MED_NO_GEOTYPE, &nodeTags[0]) < 0)
#else
  if(MEDnumLire(fid, meshName, &nodeTags[0], numNodes, MED_NOEUD, MED_NONE) < 0)
#endif
    nodeTags.clear();

  for(int i = 0; i < numNodes; i++)
    verts[i] = new MVertex(coord[spaceDim * i],
                           (spaceDim > 1) ? coord[spaceDim * i + 1] : 0.,
                           (spaceDim > 2) ? coord[spaceDim * i + 2] : 0.,
                           nullptr, nodeTags.empty() ? 0 : nodeTags[i]);

  std::vector<med_int> nodeFamily(numNodes, 0);
#if(MED_MAJOR_NUM >= 3)
  MEDmeshEntityFamilyNumberRd(fid, meshName, MED_NO_DT, MED_NO_IT, MED_NODE,
                              MED_NONE, &nodeFamily[0]);
#else
  MEDfamLire(fid, meshName, &nodeFamily[0], numEle, MED_NOEUD, MED_NONE);
#endif

  // read elements (loop over all possible MSH element types)
  for(int mshType = 0; mshType < MSH_MAX_NUM + 1; mshType++) {
    med_geometrie_element type = msh2medElementType(mshType);
    if(type == MED_NONE) continue;
#if(MED_MAJOR_NUM >= 3)
    med_bool changeOfCoord;
    med_bool geoTransform;
    med_int numEle = MEDmeshnEntity(fid, meshName, MED_NO_DT, MED_NO_IT,
                                    MED_CELL, type, MED_CONNECTIVITY, MED_NODAL,
                                    &changeOfCoord, &geoTransform);
#else
    med_int numEle =
      MEDnEntMaa(fid, meshName, MED_CONN, MED_MAILLE, type, MED_NOD);
#endif
    if(numEle <= 0) continue;
    int numNodPerEle = type % 100;
    std::vector<med_int> conn(numEle * numNodPerEle);
#if(MED_MAJOR_NUM >= 3)
    if(MEDmeshElementConnectivityRd(fid, meshName, MED_NO_DT, MED_NO_IT,
                                    MED_CELL, type, MED_NODAL,
                                    MED_FULL_INTERLACE, &conn[0]) < 0) {
#else
    if(MEDconnLire(fid, meshName, spaceDim, &conn[0], MED_FULL_INTERLACE, 0,
                   MED_ALL, MED_MAILLE, type, MED_NOD) < 0) {
#endif
      Msg::Error("Could not read MED elements");
      return 0;
    }
    std::vector<med_int> elementFamily(numEle, 0);
#if(MED_MAJOR_NUM >= 3)
    if(MEDmeshEntityFamilyNumberRd(fid, meshName, MED_NO_DT, MED_NO_IT,
                                   MED_CELL, type, &elementFamily[0]) < 0) {
#else
    if(MEDfamLire(fid, meshName, &elementFamily[0], numEle, MED_MAILLE, type) <
       0) {
#endif
      Msg::Info(
        "No family number for elements: using 0 as default family number");
    }
    std::vector<med_int> eleTags(numEle);
#if(MED_MAJOR_NUM >= 3)
    if(MEDmeshEntityNumberRd(fid, meshName, MED_NO_DT, MED_NO_IT, MED_CELL,
                             type, &eleTags[0]) < 0)
#else
    if(MEDnumLire(fid, meshName, &eleTags[0], numEle, MED_MAILLE, type) < 0)
#endif
      eleTags.clear();
    std::map<int, std::vector<MElement *> > elements;
    MElementFactory factory;
    for(int j = 0; j < numEle; j++) {
      std::vector<MVertex *> v(numNodPerEle);
      bool ok = true;
      for(int k = 0; k < numNodPerEle; k++) {
        int idx = conn[numNodPerEle * j + med2mshNodeIndex(type, k)] - 1;
        if(idx < 0 || idx > (int)verts.size() - 1) {
          Msg::Error("Wrong node index %d in MED file", idx);
          ok = false;
        }
        else {
          v[k] = verts[idx];
        }
      }
      if(ok) {
        MElement *e =
          factory.create(mshType, v, eleTags.empty() ? 0 : eleTags[j]);
        // according to the MED documentation, elementFamily[j] should be
        // negative (positive families are reserved for node families); still,
        // accept all family ids, even positive, as some codes do not export
        // valid MED files
        if(e) elements[std::abs(elementFamily[j])].push_back(e);
      }
    }
    _storeElementsInEntities(elements);
  }
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(verts);

  // read family info
  med_int numFamilies = MEDnFam(fid, meshName);
  if(numFamilies < 0) {
    Msg::Error("Could not read MED families");
    return 0;
  }
  for(int i = 0; i < numFamilies; i++) {
#if(MED_MAJOR_NUM >= 3)
    med_int numAttrib =
      (vf[0] == 2) ? MEDnFamily23Attribute(fid, meshName, i + 1) : 0;
    med_int numGroups = MEDnFamilyGroup(fid, meshName, i + 1);
#else
    med_int numAttrib = MEDnAttribut(fid, meshName, i + 1);
    med_int numGroups = MEDnGroupe(fid, meshName, i + 1);
#endif
    if(numAttrib < 0 || numGroups < 0) {
      Msg::Error("Could not read MED groups or attributes");
      return 0;
    }
    std::vector<med_int> attribId(numAttrib + 1);
    std::vector<med_int> attribVal(numAttrib + 1);
    std::vector<char> attribDes(MED_TAILLE_DESC * numAttrib + 1);
    std::vector<char> groupNames(MED_TAILLE_LNOM * numGroups + 1);
    char familyName[MED_TAILLE_NOM + 1];
    med_int familyNum;
#if(MED_MAJOR_NUM >= 3)
    if(vf[0] == 2) { // MED2 file
      if(MEDfamily23Info(fid, meshName, i + 1, familyName, &attribId[0],
                         &attribVal[0], &attribDes[0], &familyNum,
                         &groupNames[0]) < 0) {
        Msg::Error("Could not read info for MED2 family %d", i + 1);
        continue;
      }
    }
    else {
      if(MEDfamilyInfo(fid, meshName, i + 1, familyName, &familyNum,
                       &groupNames[0]) < 0) {
        Msg::Error("Could not read info for MED3 family %d", i + 1);
        continue;
      }
    }
#else
    if(MEDfamInfo(fid, meshName, i + 1, familyName, &familyNum, &attribId[0],
                  &attribVal[0], &attribDes[0], &numAttrib, &groupNames[0],
                  &numGroups) < 0) {
      Msg::Error("Could not read info for MED family %d", i + 1);
      continue;
    }
#endif

    // element family tags are unique (for all dimensions!) and <= 0
    GEntity *ge = getRegionByTag(-familyNum);
    if(!ge) ge = getFaceByTag(-familyNum);
    if(!ge) ge = getEdgeByTag(-familyNum);
    if(!ge) ge = getVertexByTag(-familyNum);
    if(ge) {
      setElementaryName(ge->dim(), -familyNum, familyName);
      if(numGroups > 0) {
        for(int j = 0; j < numGroups; j++) {
          char tmp[MED_TAILLE_LNOM + 1];
          strncpy(tmp, &groupNames[j * MED_TAILLE_LNOM], MED_TAILLE_LNOM);
          tmp[MED_TAILLE_LNOM] = '\0';
          // don't use same physical number across dimensions, as e.g. getdp
          // does not support this
          int pnum =
            setPhysicalName(tmp, ge->dim(), getMaxPhysicalNumber(-1) + 1);
          if(std::find(ge->physicals.begin(), ge->physicals.end(), pnum) ==
             ge->physicals.end())
            ge->physicals.push_back(pnum);
        }
      }
    }
    else if(familyNum > 0 && CTX::instance()->mesh.medImportGroupsOfNodes) {
      // the concept of node family does not exist in Gmsh, so we simply create
      // a geometrical point for each node (with a single point element); and we
      // classify the node on the geometrical point if the node is not already
      // classified on another entity. This is expensive, and should be disabled
      // for large groups of nodes.
      std::vector<GVertex *> newPoints;
      for(int j = 0; j < numNodes; j++) {
        if(nodeFamily[j] == familyNum) {
          discreteVertex *gv =
            new discreteVertex(this, getMaxElementaryNumber(0) + 1,
                               verts[j]->x(), verts[j]->y(), verts[j]->z());
          add(gv);
          if(!verts[j]->onWhat()) {
            verts[j]->setEntity(gv);
            gv->mesh_vertices.push_back(verts[j]);
          }
          gv->points.push_back(new MPoint(verts[j]));
          setElementaryName(0, gv->tag(), familyName);
          newPoints.push_back(gv);
        }
      }
      if(numGroups > 0) {
        for(int j = 0; j < numGroups; j++) {
          char tmp[MED_TAILLE_LNOM + 1];
          strncpy(tmp, &groupNames[j * MED_TAILLE_LNOM], MED_TAILLE_LNOM);
          tmp[MED_TAILLE_LNOM] = '\0';
          // don't use same physical number across dimensions, as e.g. getdp
          // does not support this
          int pnum = setPhysicalName(tmp, 0, getMaxPhysicalNumber(-1) + 1);
          for(std::size_t k = 0; k < newPoints.size(); k++)
            newPoints[k]->physicals.push_back(pnum);
        }
      }
    }
  }

  // check if we need to read some post-processing data later
#if(MED_MAJOR_NUM >= 3)
  bool postpro = (MEDnField(fid) > 0) ? true : false;
#else
  bool postpro = (MEDnChamp(fid, 0) > 0) ? true : false;
#endif

  if(MEDfermer(fid) < 0) {
    Msg::Error("Unable to close file '%s'", name.c_str());
    return 0;
  }

  return postpro ? 2 : 1;
}

template <class T>
static void
fillElementsMED(med_int family, std::vector<T *> &elements,
                std::vector<med_int> &conn, std::vector<med_int> &fam,
                std::vector<med_int> &tags, med_geometrie_element &type)
{
  if(elements.empty()) return;
  int msh = elements[0]->getTypeForMSH();
  type = msh2medElementType(msh);
  if(type == MED_NONE) {
    Msg::Warning("Unsupported element type in MED format");
    return;
  }
  for(std::size_t i = 0; i < elements.size(); i++) {
    elements[i]->setVolumePositive();
    for(std::size_t j = 0; j < elements[i]->getNumVertices(); j++)
      conn.push_back(
        elements[i]->getVertex(msh2medNodeIndex(msh, j))->getIndex());
    fam.push_back(family);
    tags.push_back(elements[i]->getNum());
  }
}

static void writeElementsMED(med_idt &fid, const char *meshName,
                             std::vector<med_int> &conn,
                             std::vector<med_int> &fam,
                             std::vector<med_int> &tags,
                             med_geometrie_element type)
{
  if(fam.empty()) return;
#if(MED_MAJOR_NUM >= 3)
  if(MEDmeshElementWr(fid, meshName, MED_NO_DT, MED_NO_IT, 0., MED_CELL, type,
                      MED_NODAL, MED_FULL_INTERLACE, (med_int)fam.size(),
                      &conn[0], MED_FALSE, nullptr, MED_TRUE, &tags[0],
                      MED_TRUE, &fam[0]) < 0)
#else
  if(MEDelementsEcr(fid, meshName, (med_int)3, &conn[0], MED_FULL_INTERLACE, 0,
                    MED_FAUX, &tags[0], MED_VRAI, &fam[0], (med_int)fam.size(),
                    MED_MAILLE, type, MED_NOD) < 0)
#endif
    Msg::Error("Could not write MED elements");
}

int GModel::writeMED(const std::string &name, bool saveAll,
                     double scalingFactor)
{
#if (MED_MAJOR_NUM >= 4) || ((MED_MAJOR_NUM >= 3) && (MED_MINOR_NUM >= 3))
  // MEDfileVersionOpen actually appeared in MED 3.2.1
  med_int major = MED_MAJOR_NUM, minor = MED_MINOR_NUM,
          release = MED_RELEASE_NUM;
  if(CTX::instance()->mesh.medFileMinorVersion >= 0) {
    minor = (int)CTX::instance()->mesh.medFileMinorVersion;
    Msg::Info("Forcing MED file version to %d.%d", major, minor);
  }
  med_idt fid = MEDfileVersionOpen((char *)name.c_str(), MED_ACC_CREAT, major,
                                   minor, release);
#else
  med_idt fid = MEDouvrir((char *)name.c_str(), MED_CREATION);
#endif
  if(fid < 0) {
    Msg::Error("Unable to open file '%s'", name.c_str());
    return 0;
  }

  // write header
  if(MEDfichDesEcr(fid, (char *)"MED file generated by Gmsh") < 0) {
    Msg::Error("Unable to write MED descriptor");
    return 0;
  }

  std::string strMeshName = getName();
  if(strMeshName.empty())
    strMeshName = "untitled";
  const char *meshName = (char *)strMeshName.c_str();

  // Gmsh always writes 3D unstructured meshes
#if(MED_MAJOR_NUM >= 3)
  char dtUnit[MED_SNAME_SIZE + 1] = "";
  char axisName[3 * MED_SNAME_SIZE + 1] = "";
  char axisUnit[3 * MED_SNAME_SIZE + 1] = "";
  if(MEDmeshCr(fid, meshName, 3, 3, MED_UNSTRUCTURED_MESH,
               "Mesh created with Gmsh", dtUnit, MED_SORT_DTIT, MED_CARTESIAN,
               axisName, axisUnit) < 0) {
#else
  if(MEDmaaCr(fid, meshName, 3, MED_NON_STRUCTURE,
              (char *)"Mesh created with Gmsh") < 0) {
#endif
    Msg::Error("Could not create MED mesh");
    return 0;
  }

  // if there are no physicals we save all the elements
  if(noPhysicalGroups()) saveAll = true;

  // index the vertices we save in a continuous sequence (MED
  // connectivity is given in terms of vertex indices)
  indexMeshVertices(saveAll);

  // get a vector containing all the geometrical entities in the
  // model (the ordering of the entities must be the same as the one
  // used during the indexing of the vertices)
  std::vector<GEntity *> entities;
  getEntities(entities);

  std::map<GEntity *, int> families;
  // write the families
  {
    // always create a "0" family, with no groups or attributes
#if(MED_MAJOR_NUM >= 3)
    if(MEDfamilyCr(fid, meshName, "F_0", 0, 0, "") < 0)
#else
    if(MEDfamCr(fid, meshName, (char *)"F_0", 0, 0, 0, 0, 0, 0, 0) < 0)
#endif
      Msg::Error("Could not create MED family 0");

    // create one family per elementary entity, with one group per
    // physical entity and no attributes
    for(std::size_t i = 0; i < entities.size(); i++) {
      if(saveAll || entities[i]->physicals.size()) {
        int num = -((int)families.size() + 1);
        families[entities[i]] = num;
        std::ostringstream fs;
        fs << entities[i]->dim() << "D_" << entities[i]->tag();
        std::string familyName = "F_" + fs.str();
        std::string groupName;
        for(unsigned j = 0; j < entities[i]->physicals.size(); j++) {
          std::string tmp =
            getPhysicalName(entities[i]->dim(), entities[i]->physicals[j]);
          if(tmp.empty()) { // create unique name
            std::ostringstream gs;
            gs << entities[i]->dim() << "D_" << entities[i]->physicals[j];
            groupName += "G_" + gs.str();
          }
          else
            groupName += tmp;
          // this is not ideal (cf. #2427), as the group names are all 80 char
          // long, but I don't know how to associate multiple group names to a
          // family otherwise
          groupName.resize((j + 1) * MED_TAILLE_LNOM, ' ');
        }
#if(MED_MAJOR_NUM >= 3)
        if(MEDfamilyCr(fid, meshName, familyName.c_str(), (med_int)num,
                       (med_int)entities[i]->physicals.size(),
                       groupName.c_str()) < 0)
#else
        if(MEDfamCr(fid, meshName, (char *)familyName.c_str(), (med_int)num, 0,
                    0, 0, 0, (char *)groupName.c_str(),
                    (med_int)entities[i]->physicals.size()) < 0)
#endif
          Msg::Error("Could not create MED family %d", num);
      }
    }
  }

  // write the nodes
  {
    std::vector<med_float> coord;
    std::vector<med_int> fam;
    std::vector<med_int> tags;
    for(std::size_t i = 0; i < entities.size(); i++) {
      for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
        MVertex *v = entities[i]->mesh_vertices[j];
        if(v->getIndex() >= 0) {
          coord.push_back(v->x() * scalingFactor);
          coord.push_back(v->y() * scalingFactor);
          coord.push_back(v->z() * scalingFactor);
          fam.push_back(0); // we never create node families
          tags.push_back(v->getNum());
        }
      }
    }
    if(fam.empty()) {
      Msg::Error("No nodes to write in MED mesh");
      return 0;
    }
#if(MED_MAJOR_NUM >= 3)
    if(MEDmeshNodeWr(fid, meshName, MED_NO_DT, MED_NO_IT, 0.,
                     MED_FULL_INTERLACE, (med_int)fam.size(), &coord[0],
                     MED_FALSE, "", MED_TRUE, &tags[0], MED_TRUE, &fam[0]) < 0)
#else
    char coordName[3 * MED_TAILLE_PNOM + 1] =
      "x               y               z               ";
    char coordUnit[3 * MED_TAILLE_PNOM + 1] =
      "unknown         unknown         unknown         ";
    if(MEDnoeudsEcr(fid, meshName, (med_int)3, &coord[0], MED_FULL_INTERLACE,
                    MED_CART, coordName, coordUnit, 0, MED_FAUX, &tags[0],
                    MED_VRAI, &fam[0], (med_int)fam.size()) < 0)
#endif
      Msg::Error("Could not write nodes");
  }

  // write the elements
  {
    { // points
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstVertex(); it != lastVertex(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->points, conn, fam, tags, typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // lines
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstEdge(); it != lastEdge(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->lines, conn, fam, tags, typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // triangles
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstFace(); it != lastFace(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->triangles, conn, fam, tags,
                          typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // quads
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstFace(); it != lastFace(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->quadrangles, conn, fam, tags,
                          typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // tets
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstRegion(); it != lastRegion(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->tetrahedra, conn, fam, tags,
                          typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // hexas
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstRegion(); it != lastRegion(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->hexahedra, conn, fam, tags,
                          typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // prisms
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstRegion(); it != lastRegion(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->prisms, conn, fam, tags, typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
    { // pyramids
      med_geometrie_element typ = MED_NONE;
      std::vector<med_int> conn, fam, tags;
      for(auto it = firstRegion(); it != lastRegion(); it++)
        if(saveAll || (*it)->physicals.size())
          fillElementsMED(families[*it], (*it)->pyramids, conn, fam, tags, typ);
      writeElementsMED(fid, meshName, conn, fam, tags, typ);
    }
  }

  if(MEDfermer(fid) < 0) {
    Msg::Error("Unable to close file '%s'", name.c_str());
    return 0;
  }

  return 1;
}

#else

int GModel::readMED(const std::string &name)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'",
             name.c_str());
  return 0;
}

int GModel::readMED(const std::string &name, int meshIndex)
{
  Msg::Error("Gmsh must be compiled with MED support to read '%s'",
             name.c_str());
  return 0;
}

int GModel::writeMED(const std::string &name, bool saveAll,
                     double scalingFactor)
{
  Msg::Error("Gmsh must be compiled with MED support to write '%s'",
             name.c_str());
  return 0;
}

#endif
