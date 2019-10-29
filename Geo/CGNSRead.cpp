// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
  if(zoneType != Unstructured) return 0;

  // read zone size
  char zoneName[CGNS_MAX_STR_LEN];
  cgsize_t cgsizes[3];
  cgnsErr = cg_zone_read(cgIndexFile, cgIndexBase, iZone, zoneName, cgsizes);
  if(cgnsErr != CG_OK) return cgnsError();
  const int nbNode = cgsizes[0];

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
    const int startInd = 1;
    xyz[iXYZ].resize(nbNode);
    cgnsErr = cg_coord_read(cgIndexFile, cgIndexBase, iZone, xyzName,
                            RealDouble, &startInd, &nbNode, xyz[iXYZ].data());
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


#endif // HAVE_LIBCGNS
