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
#include "SBoundingBox3d.h"
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


class StructuredInd2D
{
public:
  StructuredInd2D(int iZone, cgsize_t *size, int &err);

  int nbVertI() const {return nbVertI_; }
  int nbVertJ() const {return nbVertJ_; }
  int nbEltI() const {return nbEltI_; }
  int nbEltJ() const {return nbEltJ_; }
    
  int Elt(int i, int j) const { return j * nbEltI_ + i; }
  int Vert(int i, int j) const { return j * nbVertI_ + i; }

private:
  int nbVertI_, nbVertJ_;
  int nbEltI_, nbEltJ_;

};


StructuredInd2D::StructuredInd2D(int iZone, cgsize_t *size, int &err) :
  nbVertI_(size[0]), nbVertJ_(size[1]), nbEltI_(size[2]), nbEltJ_(size[3])
{
  if((nbVertI_ != nbEltI_+1) || (nbVertJ_ != nbEltJ_+1)) {
    Msg::Error("CGNS zone %i: number of vertices (%i, %i) is inconsistent with "
               "number of elements (%i, %i)", iZone, nbVertI_, nbVertJ_,
               nbEltI_, nbEltJ_);
    err = 0;
  }
  else err = 1;
}


class StructuredInd3D
{
public:
  StructuredInd3D(int iZone, cgsize_t *size, int &err);

  int nbVertI() const {return nbVertI_; }
  int nbVertJ() const {return nbVertJ_; }
  int nbVertK() const {return nbVertK_; }
  int nbEltI() const {return nbEltI_; }
  int nbEltJ() const {return nbEltJ_; }
  int nbEltK() const {return nbEltK_; }

  int Elt(int i, int j, int k) const {
    return (k * nbEltJ_ + j) * nbEltI_ + i;
  }
  int Vert(int i, int j, int k) const {
    return(k * nbVertJ_ + j) * nbVertI_ + i;
  }

private:
  int nbVertI_, nbVertJ_, nbVertK_;
  int nbEltI_, nbEltJ_, nbEltK_;

};


StructuredInd3D::StructuredInd3D(int iZone, cgsize_t *size, int &err) :
  nbVertI_(size[0]), nbVertJ_(size[1]), nbVertK_(size[2]), nbEltI_(size[3]),
  nbEltJ_(size[4]), nbEltK_(size[5])
{
  if((nbVertI_ != nbEltI_+1) || (nbVertJ_ != nbEltJ_+1) ||
     (nbVertK_ != nbEltK_+1)) {
    Msg::Error("CGNS zone %i: number of vertices (%i, %i, %i) is inconsistent "
               "with number of elements (%i, %i, %i)", iZone, nbVertI_,
               nbVertJ_, nbVertK_, nbEltI_, nbEltJ_, nbEltK_);
    err = 0;
  }
  else err = 1;
}


void createQuad(int i, int j, const StructuredInd2D &si, int order,
               std::size_t vertShift, std::vector<MVertex *> &allVert,
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
    const int ind = vertShift + si.Vert(i+s[3*iN], j+s[3*iN+1]);
    eltVert[iN] = allVert[ind];
  }

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  int entity = 1;
  allElt[3][entity].push_back(e);
}


int readElementsStructured2D(int cgIndexFile, int cgIndexBase, int iZone,
                             std::size_t vertShift, cgsize_t *zoneSize,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt,
                             const std::map<int, int> &elt2BC,
                             int firstDefaultBC)
{
  // number of vertices and elements (raw mesh)
  int err = 1;
  StructuredInd2D si(iZone, zoneSize, err);
  if(err == 0) return 0;

  // order of coarsened mesh and number of potentially coarsened (HO) elements
  int order = CTX::instance()->mesh.cgnsImportOrder;
  if(order > 2) {
    Msg::Warning("Cannot coarsen structured grid to order %i, creating linear "
                 "mesh in zone %i", order, iZone);
    order = 1;
  }
  else if((si.nbEltI() % order != 0) || (si.nbEltJ() % order != 0)) {
    Msg::Warning("Zone %i has (%i, %i) vertices which cannot be coarsened to "
                 "order %i, creating linear mesh", iZone, si.nbVertI(),
                 si.nbVertJ(), order);
    order = 1;
  }
  const int nbEltI = si.nbEltI() / order; 
  const int nbEltJ = si.nbEltJ() / order; 

  // create volume elements
  for(int j = 0; j < nbEltJ; j++) {
    for(int i = 0; i < nbEltI; i++) {
      createQuad(i*order, j*order, si, order, vertShift, allVert, allElt);
    }
  }

  return 1;
}


void createHex(int i, int j, int k, const StructuredInd3D &si, int order,
               std::size_t vertShift, std::vector<MVertex *> &allVert,
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
    const int ind = vertShift + si.Vert(i+s[3*iN], j+s[3*iN+1], k+s[3*iN+2]);
    eltVert[iN] = allVert[ind];
  }

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  int entity = 1;
  allElt[5][entity].push_back(e);
}


void createBndQuad(int i, int j, int k, const int ij2ijk[2],
                   const StructuredInd3D &si,
                   int order, int entity, std::size_t vertShift,
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
    int ijk[3] = {i, j, k};
    ijk[ij2ijk[0]] += s[2*iN];
    ijk[ij2ijk[1]] += s[2*iN+1];
    const int ind = vertShift + si.Vert(ijk[0], ijk[1], ijk[2]);
    eltVert[iN] = allVert[ind];
  }

  // create element
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert);

  // add element to data structure
  allElt[3][entity].push_back(e);
}


int readElementsStructured3D(int cgIndexFile, int cgIndexBase, int iZone,
                             std::size_t vertShift, cgsize_t *zoneSize,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt,
                             const std::map<int, int> &elt2BC,
                             int firstDefaultBC,
                             std::map<int, SBoundingBox3d> &blockBnd)
{
  // number of vertices and elements (raw mesh)
  int err = 1;
  StructuredInd3D si(iZone, zoneSize, err);
  if(err == 0) return 0;

  // order of coarsened mesh and number of potentially coarsened (HO) elements
  int order = CTX::instance()->mesh.cgnsImportOrder;
  if(order > 2) {
    Msg::Warning("Cannot coarsen structured grid to order %i, creating linear "
                 "mesh in zone %i", order, iZone);
    order = 1;
  }
  else if((si.nbEltI() % order != 0) || (si.nbEltJ() % order != 0) ||
          (si.nbEltK() % order != 0)) {
    Msg::Warning("Zone %i has (%i, %i, %i) vertices which cannot be coarsened "
                 "to order %i, creating linear mesh", iZone, si.nbVertI(),
                 si.nbVertJ(), si.nbVertK(), order);
    order = 1;
  }
  const int nbEltI = si.nbEltI() / order;
  const int nbEltJ = si.nbEltJ() / order;
  const int nbEltK = si.nbEltK() / order;

  // create volume elements
  for(int k = 0; k < nbEltK; k++) {
    for(int j = 0; j < nbEltJ; j++) {
      for(int i = 0; i < nbEltI; i++) {
        createHex(i*order, j*order, k*order, si, order, vertShift, allVert, 
                  allElt);
      }
    }
  }

  // boundary tags for block faces i-, i+, j-;j+, k- and k+
  const int bcIMin = firstDefaultBC, bcIMax = firstDefaultBC+1;
  const int bcJMin = firstDefaultBC+2, bcJMax = firstDefaultBC+3;
  const int bcKMin = firstDefaultBC+4, bcKMax = firstDefaultBC+5;

  // create boundary elements and bounding boxes for block faces i- and i+
  SBoundingBox3d &bBoxIMin = blockBnd[bcIMin], &bBoxIMax = blockBnd[bcIMax];
  for(int k = 0; k < nbEltK; k++) {
    for(int j = 0; j < nbEltJ; j++) {
        static const int ij2ijk[2] = {1, 2};
        const int iMax = si.nbVertI()-1, jj = j*order, kk = k*order;
        createBndQuad(0, jj, kk, ij2ijk, si, order, bcIMin, vertShift, allVert,
                      allElt);
        createBndQuad(iMax, jj, kk, ij2ijk, si, order, bcIMax,
                      vertShift, allVert, allElt);
        const int indMin = vertShift + si.Vert(0, jj, kk);
        const int indMax = vertShift + si.Vert(iMax, jj, kk);
        bBoxIMin += allVert[indMin]->point();
        bBoxIMax += allVert[indMax]->point();
    }
  }

  // create boundary elements for block faces j- and j+
  SBoundingBox3d &bBoxJMin = blockBnd[bcJMin], &bBoxJMax = blockBnd[bcJMax];
  for(int k = 0; k < nbEltK; k++) {
    for(int i = 0; i < nbEltI; i++) {
        static const int ij2ijk[2] = {0, 2};
        const int ii = i*order, jMax = si.nbVertJ()-1, kk = k*order;
        createBndQuad(ii, 0, kk, ij2ijk, si, order, bcJMin, vertShift, allVert,
                      allElt);
        createBndQuad(ii, jMax, kk, ij2ijk, si, order, bcJMax,
                      vertShift, allVert, allElt);
        const int indMin = vertShift + si.Vert(ii, 0, kk);
        const int indMax = vertShift + si.Vert(ii, jMax, kk);
        bBoxJMin += allVert[indMin]->point();
        bBoxJMax += allVert[indMax]->point();
    }
  }

  // create boundary elements for block faces k- and k+
  SBoundingBox3d &bBoxKMin = blockBnd[bcKMin], &bBoxKMax = blockBnd[bcKMax];
  for(int j = 0; j < nbEltJ; j++) {
    for(int i = 0; i < nbEltI; i++) {
        static const int ij2ijk[2] = {0, 1};
        const int ii = i*order, jj = j*order, kMax = si.nbVertK()-1;
        createBndQuad(ii, jj, 0, ij2ijk, si, order, bcKMin, vertShift, allVert,
                      allElt);
        createBndQuad(ii, jj, kMax, ij2ijk, si, order, bcKMax,
                      vertShift, allVert, allElt);
        const int indMin = vertShift + si.Vert(ii, jj, 0);
        const int indMax = vertShift + si.Vert(ii, jj, kMax);
        bBoxKMin += allVert[indMin]->point();
        bBoxKMax += allVert[indMax]->point();
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


int readZone(int cgIndexFile, int cgIndexBase, int iZone, int dim, double scale,
             std::vector<MVertex *> &allVert,
             std::map<int, std::vector<MElement *> > *allElt,
             std::vector<std::string> &allBCName, std::map<int, int> &bc2Family,
             std::vector<std::string> &allBCFamilyName,
             std::map<int, SBoundingBox3d> &blockBnd)
{
  int cgnsErr;

  // read zone type
  ZoneType_t zoneType;
  cgnsErr = cg_zone_type(cgIndexFile, cgIndexBase, iZone, &zoneType);
  if(cgnsErr != CG_OK) return cgnsError();

  // read zone size
  char zoneName[CGNS_MAX_STR_LEN];
  cgsize_t zoneSize[9];
  cgnsErr = cg_zone_read(cgIndexFile, cgIndexBase, iZone, zoneName, zoneSize);
  if(cgnsErr != CG_OK) return cgnsError();
  int nbNode = zoneSize[0];
  if (zoneType == Structured) {
    if(dim > 1) nbNode *= zoneSize[1];
    if(dim > 2) nbNode *= zoneSize[2];
  }

  // read dimension and check consistency with base node
  int dim2;
  cgnsErr = cg_ncoords(cgIndexFile, cgIndexBase, iZone, &dim2);
  if(cgnsErr != CG_OK) return cgnsError();
  if(dim2 > dim) {
    Msg::Warning("%i coordinates in CGNS zone %i, while base has dimension %i,"
                 " discarding upper dimensions", dim2, iZone, dim);
  }
  else if(dim2 < dim) {
    Msg::Error("%i coordinates in CGNS zone %i, while base has dimension %i",
               dim2, iZone, dim);
    return 0;
  }

  // read boundary conditions for classification of mesh on geometry
  int nbZoneBC;
  cgnsErr = cg_nbocos(cgIndexFile, cgIndexBase, iZone, &nbZoneBC);
  if(cgnsErr != CG_OK) return cgnsError();
  std::map<int, int> elt2BC;
  for(int iZoneBC = 1; iZoneBC <= nbZoneBC; iZoneBC++) {
    readBoundaryCondition(cgIndexFile, cgIndexBase, iZone, iZoneBC, dim,
                          elt2BC, allBCName, bc2Family, allBCFamilyName);
  }

  // read vertex coordinates
  std::vector<double> xyz[3];
  for(int iXYZ = 0; iXYZ < dim; iXYZ++) {
    char xyzName[CGNS_MAX_STR_LEN];
    DataType_t dataType;
    cgnsErr = cg_coord_info(cgIndexFile, cgIndexBase, iZone, iXYZ+1, &dataType,
                            xyzName);
    if(cgnsErr != CG_OK) return cgnsError();
    const int startInd[3] = {1, 1, 1};
    xyz[iXYZ].resize(nbNode);
    cgnsErr = cg_coord_read(cgIndexFile, cgIndexBase, iZone, xyzName,
                            RealDouble, startInd, zoneSize, xyz[iXYZ].data());
    if(cgnsErr != CG_OK) return cgnsError();
  }

  // create vertices
  const std::size_t vertShift = allVert.size();
  allVert.reserve(vertShift+nbNode);
  for(int i = 0; i < nbNode; i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    allVert.push_back(new MVertex(x, y, z));
  }

  // read and create elementss
  int err = 0;
  if (zoneType == Structured) {
    if(dim == 2) {
      const int firstDefaultBC = allBCName.size();
      allBCName.insert(allBCName.end(), 4, "");
      err = readElementsStructured2D(cgIndexFile, cgIndexBase, iZone, vertShift,
                                     zoneSize, allVert, allElt, elt2BC,
                                     firstDefaultBC);
    }
    else if(dim == 3) {
      const int firstDefaultBC = allBCName.size();
      allBCName.insert(allBCName.end(), 6, "");
      err = readElementsStructured3D(cgIndexFile, cgIndexBase, iZone, vertShift,
                                     zoneSize, allVert, allElt, elt2BC,
                                     firstDefaultBC, blockBnd);
    }
  }
  else {
    err = readElementsUnstructured(cgIndexFile, cgIndexBase, iZone, vertShift,
                                   allVert, allElt, elt2BC);
  }
  if(err == 0) return 0;

  return 1;
}


#endif // HAVE_LIBCGNS
