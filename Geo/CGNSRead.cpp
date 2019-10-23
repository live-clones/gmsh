// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "MVertex.h"
#include "MElement.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


namespace {


void getElement(ElementType_t sectEltType, std::size_t vertShift, int entity,
                const std::vector<MVertex *> &allVert,
                std::map<int, std::vector<MElement *> > *allElt, int &nbEltTot,
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
  int nbEltNode = ElementType::getNumVertices(eltType);
  const std::vector<int> &cgns2Msh = cgns2MshNodeIndex(mshEltType);
  std::vector<MVertex *> eltVert(nbEltNode);
  for (int iEltNode = 0; iEltNode < nbEltNode; iEltNode++, iSectData++) {
    const int indNode = vertShift + sectData[iSectData];
    eltVert[cgns2Msh[iEltNode]] = allVert[indNode];
  }

  // create element
  nbEltTot++;
  MElementFactory factory;
  MElement *e = factory.create(mshEltType, eltVert, nbEltTot, 0, false, 0, 0,
                               0);

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
                std::size_t vertShift, int entity,
                const std::vector<MVertex *> &allVert,
                std::map<int, std::vector<MElement *> > *allElt, int &nbEltTot)
{
  // read section information
  char sectName[CGNS_MAX_STR_LEN];
  ElementType_t sectEltType;
  cgsize_t startElt, endElt;
  int nbBnd, parentFlag;
  if(cg_section_read(cgIndexFile, cgIndexBase, iZone, iSect, sectName,
                     &sectEltType, &startElt, &endElt, &nbBnd, &parentFlag))
    return cgnsError();
  const int nbElt = endElt - startElt + 1;

  // read connectivity data size
  cgsize_t dataSize;
  if(cg_ElementDataSize(cgIndexFile, cgIndexBase, iZone, iSect, &dataSize))
    return cgnsError();

  // read connectivity data
  std::vector<cgsize_t> sectData(dataSize);
  if(cg_elements_read(cgIndexFile, cgIndexBase, iZone, iSect,
                      sectData.data(), 0))
    return cgnsError();

  // create elements
  std::size_t iSectData = 0;
  for(int iElt = 0; iElt < nbElt; iElt++) {
    getElement(sectEltType, vertShift, entity, allVert, allElt, nbEltTot,
               sectData, iSectData);
  }

  return 0;
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
             std::map<int, std::vector<MElement *> > *allElt, int &nbEltTot)
{
  // read zone type
  // DBGTT: read only unstructured zone at the moment
  ZoneType_t zoneType;
  if(cg_zone_type(cgIndexFile, cgIndexBase, iZone, &zoneType))
    return cgnsError();
  if(zoneType != Unstructured) return 0;

  // read zone size
  char zoneName[CGNS_MAX_STR_LEN];
  cgsize_t cgsizes[3];
  if(cg_zone_read(cgIndexFile, cgIndexBase, iZone, zoneName, cgsizes))
    return cgnsError();
  const int nbNode = cgsizes[0];

  // read dimension and check consistency with base node
  int dim2;
  if(cg_ncoords(cgIndexFile, cgIndexBase, iZone, &dim2)) return cgnsError();
  if(dim2 != dim) {
    Msg::Error("%i coordinates in CGNS zone %i, while base has dimension %i",
               dim2, iZone, dim);
    return 0;
  }

  // read vertex coordinates
  std::vector<double> xyz[3];
  for(int iXYZ = 0; iXYZ < dim; iXYZ++) {
    char xyzName[CGNS_MAX_STR_LEN];
    DataType_t dataType;
    if(cg_coord_info(cgIndexFile, cgIndexBase, iZone, iXYZ+1, &dataType,
                     xyzName))
      return cgnsError();
    const int startInd = 1;
    xyz[iXYZ].resize(nbNode);
    if(cg_coord_read(cgIndexFile, cgIndexBase, iZone, xyzName, RealDouble,
                     &startInd, &nbNode, xyz[iXYZ].data()))
      return cgnsError();
  }

  // create vertices
  const std::size_t vertShift = allVert.size();
  allVert.reserve(vertShift+nbNode);
  for(int i = 0; i < nbNode; i++) {
    const double x = xyz[0][i] * scale;
    const double y = (dim > 1) ? xyz[1][i] * scale : 0.;
    const double z = (dim > 2) ? xyz[2][i] * scale : 0.;
    allVert.push_back(new MVertex(x, y, z, 0, allVert.size()+1));
  }

  // read number of sections of element-vertex connectivity
  int nbSect;
  if(cg_nsections(cgIndexFile, cgIndexBase, iZone, &nbSect))
    return cgnsError();

  // read sections of element-vertex connectivity
  const int entity = iZone; 
  for(int iSect = 1; iSect <= nbSect; iSect++) {
    readSection(cgIndexFile, cgIndexBase, iZone, iSect, vertShift, entity,
                allVert, allElt, nbEltTot);
  }

  return 0;
}


#endif // HAVE_LIBCGNS
