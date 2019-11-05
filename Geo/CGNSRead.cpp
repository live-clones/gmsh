// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "MVertex.h"
#include "MElement.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSZone.h"
#include "CGNSZoneStruct.h"
#include "CGNSZoneUnstruct.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


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


int createZones(int fileIndex, int baseIndex, int meshDim,
                std::vector<CGNSZone *> &allZones,
                std::map<std::string, int> &name2Zone)
{
  const int nbZone = allZones.size() - 1;
  int cgnsErr;

  // sweep over zones
  cgsize_t startNode = 0;
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    // read zone type
    ZoneType_t zoneType;
    cgnsErr = cg_zone_type(fileIndex, baseIndex, iZone, &zoneType);
    if(cgnsErr != CG_OK) return cgnsError();
    
    // create zone
    int err;
    if (zoneType == Structured) {
      if(meshDim == 2) {
        allZones[iZone] = new CGNSZoneStruct<2>(fileIndex, baseIndex, iZone,
                                                meshDim, startNode, err);
      }
      if(meshDim == 3) {
        allZones[iZone] = new CGNSZoneStruct<3>(fileIndex, baseIndex, iZone,
                                                meshDim, startNode, err);
      }
    }
    else if (zoneType == Unstructured) {
      allZones[iZone] = new CGNSZoneUnstruct(fileIndex, baseIndex, iZone,
                                             meshDim, startNode, err);
    }
    if(err == 0) return 0;

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


#endif // HAVE_LIBCGNS
