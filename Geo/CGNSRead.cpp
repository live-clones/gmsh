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
                             std::vector<std::string> &allBCName,
                             std::map<int, int> &bc2Family,
                             std::vector<std::string> &allBCFamilyName,
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


int readElementsStructured2D(int cgIndexFile, int cgIndexBase, int iZone,
                             std::size_t vertShift, cgsize_t *zoneSize,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt,
                             std::vector<std::string> &allBCName,
                             std::map<int, int> &bc2Family,
                             std::vector<std::string> &allBCFamilyName,
                             const std::map<int, int> &elt2BC)
{
  // number of vertices and elements
  int err = 1;
  StructuredInd2D si(iZone, zoneSize, err);
  if(err == 0) return 0;

  // for(int i = 0; i < nbEltI; i++) {
  //   for(int j = 0; j < nbEltJ; j++) {
  //   }
  // }
  

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


int readElementsStructured3D(int cgIndexFile, int cgIndexBase, int iZone,
                             std::size_t vertShift, cgsize_t *zoneSize,
                             std::vector<MVertex *> &allVert,
                             std::map<int, std::vector<MElement *> > *allElt,
                             std::vector<std::string> &allBCName,
                             std::map<int, int> &bc2Family,
                             std::vector<std::string> &allBCFamilyName,
                             const std::map<int, int> &elt2BC)
{
  // number of vertices and elements (raw mesh)
  int err = 1;
  StructuredInd3D si(iZone, zoneSize, err);
  if(err == 0) return 0;

  // order of coarsened mesh and number of coarsened (HO) elements
  int order = CTX::instance()->mesh.cgnsImportOrder;
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
             std::vector<std::string> &allBCFamilyName)
{
  int cgnsErr;

  // read zone type
  // DBGTT: read only unstructured zone at the moment
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
  Msg::Info("DBGTT: Reading BC");
  int nbZoneBC;
  cgnsErr = cg_nbocos(cgIndexFile, cgIndexBase, iZone, &nbZoneBC);
  if(cgnsErr != CG_OK) return cgnsError();
  std::map<int, int> elt2BC;
  for(int iZoneBC = 1; iZoneBC <= nbZoneBC; iZoneBC++) {
    readBoundaryCondition(cgIndexFile, cgIndexBase, iZone, iZoneBC, dim,
                          elt2BC, allBCName, bc2Family, allBCFamilyName);
  }

  // read vertex coordinates
  Msg::Info("DBGTT: Reading vertices");
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
  Msg::Info("DBGTT: Creating vertices");
  const std::size_t vertShift = allVert.size();
  allVert.reserve(vertShift+nbNode);
  for(int i = 0; i < nbNode; i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    allVert.push_back(new MVertex(x, y, z));
  }

  Msg::Info("DBGTT: Creating elements");
  int err = 0;
  if (zoneType == Structured) {
    if(dim == 2) {
      err = readElementsStructured2D(cgIndexFile, cgIndexBase, iZone, vertShift,
                                     zoneSize, allVert, allElt, allBCName,
                                     bc2Family, allBCFamilyName, elt2BC);
    }
    else if(dim == 3) {
      err = readElementsStructured3D(cgIndexFile, cgIndexBase, iZone, vertShift,
                                     zoneSize, allVert, allElt, allBCName,
                                     bc2Family, allBCFamilyName, elt2BC);
    }
  }
  else {
    err = readElementsUnstructured(cgIndexFile, cgIndexBase, iZone, vertShift,
                                   allVert, allElt, allBCName, bc2Family,
                                   allBCFamilyName, elt2BC);
  }
  if(err == 0) return 0;

  return 1;
}


#endif // HAVE_LIBCGNS
