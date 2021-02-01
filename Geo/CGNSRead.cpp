// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#include <cstring>
#include "GmshMessage.h"
#include "GModel.h"
#include "MVertex.h"
#include "MElement.h"
#include "BergotBasis.h"
#include "BasisFactory.h"
#include "ElementType.h"
#include "GEntity.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZone.h"
#include "CGNSZoneStruct.h"
#include "CGNSZoneUnstruct.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)

namespace {

#ifdef HAVE_LIBCGNS_CPEX0045

  int readElementInterpolation(int fileIndex, int baseIndex, int familyIndex,
                               int interpIndex, ZoneEltNodeTransfo &nodeTransfo)
  {
    int cgnsErr;

    // read element interpolation tranformation info
    char interpName[CGNS_MAX_STR_LEN];
    CGNS_ENUMT(ElementType_t) cgnsType;
    cgnsErr = cg_element_interpolation_read(fileIndex, baseIndex, familyIndex,
                                            interpIndex, interpName, &cgnsType);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // get number of user interpolation points
    int nbPt;
    cgnsErr = cg_element_lagrange_interpolation_size(cgnsType, &nbPt);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // read user interpolation points (parametric coordinates)
    std::vector<double> u(nbPt), v(nbPt), w(nbPt);
    cgnsErr = cg_element_interpolation_points_read(
      fileIndex, baseIndex, familyIndex, interpIndex, u.data(), v.data(),
      w.data());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // get Gmsh interpolation points
    const int mshType = cgns2MshEltType(cgnsType);
    const nodalBasis *basis = BasisFactory::getNodalBasis(mshType);
    const fullMatrix<double> &mshPts = basis->getReferenceNodes();
    if(nbPt != mshPts.size1()) {
      Msg::Error("Internal error: number of interpolation points is different "
                 "between CGNS and Gmsh for Gmsh element %i (parent type %i)",
                 mshType, ElementType::getParentType(mshType));
      return 0;
    }
    std::vector<double> uMsh(nbPt), vMsh(nbPt), wMsh(nbPt);
    msh2CgnsReferenceElement(mshType, mshPts, uMsh, vMsh, wMsh);

    // copy user and Gmsh interpolation nodes  to matrices for comparison
    fullMatrix<double> uvw(nbPt, 3), uvwMsh(nbPt, 3);
    for(int i = 0; i < nbPt; i++) {
      uvw(i, 0) = u[i];
      uvw(i, 1) = v[i];
      uvw(i, 2) = w[i];
      uvwMsh(i, 0) = uMsh[i];
      uvwMsh(i, 1) = vMsh[i];
      uvwMsh(i, 2) = wMsh[i];
    }

    // compute node correspondence between user and Gmsh interpolation nodes
    std::vector<int> transfo(nbPt);
    if(!computeReordering(uvw, uvwMsh, transfo)) {
      Msg::Error("Interpolation points '%s' cannot be converted to Gmsh for "
                 "element %i (parent type %i)",
                 mshType, ElementType::getParentType(mshType));
      return 0;
    }
    nodeTransfo[mshType] = transfo;

    return 1;
  }

#endif

} // namespace

std::size_t nameIndex(const std::string &name,
                      std::vector<std::string> &allNames)
{
  for(std::size_t i = 0; i < allNames.size(); i++) {
    if(allNames[i] == name) return i;
  }

  allNames.push_back(name);
  return allNames.size() - 1;
}

int readScale(int fileIndex, int baseIndex, double &scale)
{
  int cgnsErr;

  scale = 1.;

  CGNS_ENUMT(MassUnits_t) mass;
  CGNS_ENUMT(LengthUnits_t) length;
  CGNS_ENUMT(TimeUnits_t) time;
  CGNS_ENUMT(TemperatureUnits_t) temperature;
  CGNS_ENUMT(AngleUnits_t) angle;
  cgnsErr = cg_goto(fileIndex, baseIndex, "end");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
  cgnsErr = cg_units_read(&mass, &length, &time, &temperature, &angle);
  if(cgnsErr == CG_NODE_NOT_FOUND) {
    Msg::Info("Length unit in CGNS file not defined, therefore not rescaling");
    return 1.;
  }
  else if(cgnsErr != CG_OK)
    return cgnsError(__FILE__, __LINE__, fileIndex);

  switch(length) {
  case CGNS_ENUMT(Centimeter):
    Msg::Info("Length unit in CGNS file is cm, rescaling");
    scale = 0.01;
    break;
  case CGNS_ENUMT(Millimeter):
    Msg::Info("Length unit in CGNS file is mm, rescaling");
    scale = 0.001;
    break;
  case CGNS_ENUMT(Foot):
    Msg::Info("Length unit in CGNS file is feet, rescaling");
    scale = 0.3048;
    break;
  case CGNS_ENUMT(Inch):
    Msg::Info("Length unit in CGNS file is inch, rescaling");
    scale = 0.0254;
    break;
  case CGNS_ENUMT(Meter):
    Msg::Info("Length unit in CGNS file is meter, not rescaling");
    break;
  case CG_Null:
  case CG_UserDefined:
  default:
    Msg::Info("Length unit in CGNS file not defined, therefore not rescaling");
    break;
  }

  return 1;
}

int readEltNodeTransfo(int fileIndex, int baseIndex,
                       Family2EltNodeTransfo &allEltNodeTransfo)
{
#ifdef HAVE_LIBCGNS_CPEX0045
  int cgnsErr;

  // read number of families
  int nbFam;
  cgnsErr = cg_nfamilies(fileIndex, baseIndex, &nbFam);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // loop over families
  for(int iFam = 1; iFam <= nbFam; iFam++) {
    // read number of element interpolation transformations
    int nbInterp;
    cgnsErr =
      cg_nelement_interpolation_read(fileIndex, baseIndex, iFam, &nbInterp);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    if(nbInterp == 0) continue;

    // read family name
    char famName[CGNS_MAX_STR_LEN];
    int nbFamBC, nbGeoRef;
    cgnsErr =
      cg_family_read(fileIndex, baseIndex, iFam, famName, &nbFamBC, &nbGeoRef);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // read element interpolation transformations
    ZoneEltNodeTransfo &nodeTransfo = allEltNodeTransfo[std::string(famName)];
    nodeTransfo.resize(NofValidElementTypes);
    for(int iInterp = 1; iInterp <= nbInterp; iInterp++) {
      int err = readElementInterpolation(fileIndex, baseIndex, iFam, iInterp,
                                         nodeTransfo);
      if(err == 0) return 0;
    }
  }

  return 1;
#else
  return 1;
#endif
}

int createZones(int fileIndex, int baseIndex, int meshDim,
                const Family2EltNodeTransfo &allEltNodeTransfo,
                std::vector<CGNSZone *> &allZones,
                std::map<std::string, int> &name2Zone, bool &postpro)
{
  const int nbZone = allZones.size() - 1;
  int cgnsErr;

  // loop over zones
  postpro = false;
  cgsize_t startNode = 0;
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    // read zone type
    CGNS_ENUMT(ZoneType_t) zoneType;
    cgnsErr = cg_zone_type(fileIndex, baseIndex, iZone, &zoneType);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

    // create zone
    int err = 1;
    if(zoneType == CGNS_ENUMV(Structured)) {
      if(meshDim == 2) {
        allZones[iZone] =
          new CGNSZoneStruct<2>(fileIndex, baseIndex, iZone, meshDim, startNode,
                                allEltNodeTransfo, err);
      }
      if(meshDim == 3) {
        allZones[iZone] =
          new CGNSZoneStruct<3>(fileIndex, baseIndex, iZone, meshDim, startNode,
                                allEltNodeTransfo, err);
      }
    }
    else if(zoneType == CGNS_ENUMV(Unstructured)) {
      allZones[iZone] =
        new CGNSZoneUnstruct(fileIndex, baseIndex, iZone, meshDim, startNode,
                             allEltNodeTransfo, err);
    }
    if(err == 0) return 0;

    // check if there are flow solutions
    int nbZoneSol;
    cgnsErr = cg_nsols(fileIndex, baseIndex, iZone, &nbZoneSol);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    postpro |= (nbZoneSol > 0);

    // helper variables
    startNode += allZones[iZone]->nbNode();
    name2Zone[allZones[iZone]->name()] = iZone;
  }

  // read interface and periodicity info
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    allZones[iZone]->readConnectivities(name2Zone, allZones);
  }

  return 1;
}

void setPeriodicityInEntities(const std::vector<CGNSZone *> &allZones)
{
  // data structure keeping track of connections between entities to avoid
  // two-way connections
  typedef std::map<GEntity *, GEntity *> EntConnect;
  typedef std::map<GEntity *, const std::vector<double> *> EntTransfo;
  EntConnect entCon;
  EntTransfo entTfo;

  // loop over zones
  for(std::size_t iZone = 1; iZone < allZones.size(); iZone++) {
    CGNSZone *zone = allZones[iZone];
    // loop over periodic connections
    for(int iPer = 0; iPer < zone->nbPerConnect(); iPer++) {
      // loop over slave and master vertices
      const std::vector<MVertex *> &slaveVert = zone->slaveVert(iPer);
      const std::vector<MVertex *> &masterVert = zone->masterVert(iPer);
      for(std::size_t iV = 0; iV < slaveVert.size(); iV++) {
        // get slave and master entities
        MVertex *sVert = slaveVert[iV], *mVert = masterVert[iV];
        GEntity *sEnt = sVert->onWhat(), *mEnt = mVert->onWhat();

        // skip if entities of different dimensions (can happen if a zone has
        // nodes on a boundary without elements on this boundary)
        if(sEnt->dim() != mEnt->dim()) continue;

        // skip if another connnection with the same slave entity already
        // exists, or if the inverse connection already exists
        if(entCon.find(sEnt) != entCon.end()) continue;
        auto itInv = entCon.find(mEnt);
        if((itInv != entCon.end()) && (itInv->second == sEnt)) continue;

        // store connection and transformation and update corresponding vertices
        entCon[sEnt] = mEnt;
        entTfo[sEnt] = &(zone->perTransfo(iPer));
        sEnt->correspondingVertices[sVert] = mVert;
      }
    }
  }

  // set mesh master and transformation between entities
  for(auto it = entCon.begin(); it != entCon.end(); ++it) {
    GEntity *sEnt = it->first, *mEnt = it->second;
    sEnt->setMeshMaster(mEnt, *(entTfo[sEnt]));
  }
}

int readPhysicals(int fileIndex, int baseIndex,
                  std::vector<std::string> &allPhysName,
                  std::multimap<std::string, int> &geomName2Phys)
{
  int cgnsErr;

  // read number of families
  int nbFam;
  cgnsErr = cg_nfamilies(fileIndex, baseIndex, &nbFam);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // loop over families
  for(int iFam = 1; iFam <= nbFam; iFam++) {
    // read family name (interpreted as name of geometrical entity)
    char rawFamName[CGNS_MAX_STR_LEN];
    int nbFamBC, nbGeoRef;
    cgnsErr = cg_family_read(fileIndex, baseIndex, iFam, rawFamName, &nbFamBC,
                             &nbGeoRef);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    const std::string geomName(rawFamName);

    // read number of sub-family names (interpreted as physical names)
    int nbFamName;
    cgnsErr = cg_nfamily_names(fileIndex, baseIndex, iFam, &nbFamName);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);
    if(nbFamName == 0) continue;

    // read sub-family names (interpreted as physical names)
    for(int iFamName = 1; iFamName <= nbFamName; iFamName++) {
      // read names
      char rawNodeName[CGNS_MAX_STR_LEN];
      cgnsErr = cg_family_name_read(fileIndex, baseIndex, iFam, iFamName,
                                    rawNodeName, rawFamName);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

      // set physical name as sub-family name or, if empty, to node name
      std::string physName;
      if(std::strcmp(rawFamName, "") == 0)
        physName = std::string(rawNodeName);
      else
        physName = std::string(rawFamName);

      // store physical name and tag
      int physTag = nameIndex(physName, allPhysName);
      geomName2Phys.insert(std::make_pair(geomName, physTag));
    }
  }

  return 1;
}

void setGeomAndPhysicalEntities(GModel *model, int meshDim,
                                std::vector<std::string> &allGeomName,
                                std::vector<std::string> &allPhysName,
                                std::multimap<std::string, int> &geomName2Phys)
{
  // loop over dimensions
  for(int d = 0; d <= meshDim; d++) {
    // get entities fo dimension d
    std::vector<GEntity *> ent;
    model->getEntities(ent, d);

    // loop over entities
    for(std::size_t iEnt = 0; iEnt < ent.size(); iEnt++) {
      // get entity tag and name
      int geomTag = ent[iEnt]->tag();
      if(geomTag >= (int)allGeomName.size()) continue;
      const std::string &geomName = allGeomName[geomTag];

      // set name of geometrical entity
      model->setElementaryName(d, geomTag, geomName);

      // associate physical tags to geometrical entity and store physical names
      auto range = geomName2Phys.equal_range(geomName);
      for(auto it = range.first; it != range.second; ++it) {
        const int physTag = it->second;
        std::vector<int> &entPhys = ent[iEnt]->physicals;
        if(std::find(entPhys.begin(), entPhys.end(), physTag) ==
           entPhys.end()) {
          entPhys.push_back(physTag);
        }
        model->setPhysicalName(allPhysName[physTag], d, physTag);
      }
    }
  }
}

#endif // HAVE_LIBCGNS
