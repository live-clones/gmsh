// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "Context.h"
#include "GModel.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSWrite.h"
#include "CGNSZone.h"
#include "CGNSZoneStruct.h"
#include "CGNSZoneUnstruct.h"
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


int GModel::readCGNS(const std::string &name)
{
  int cgnsErr;

  // open CGNS file and read scale
  int fileIndex = 0;
  cgnsErr = cg_open(name.c_str(), CG_MODE_READ, &fileIndex);
  if(cgnsErr != CG_OK) return cgnsError();
  const double scale = readScale();

  // read base node
  const int baseIndex = 1;
  int dim = 0, meshDim = 0;
  char baseName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_base_read(fileIndex, baseIndex, baseName, &dim, &meshDim);
  if(cgnsErr != CG_OK) return cgnsError();

  // define BC names and families, used for elementary and physical names resp.
  // Index start at 1 with empty name to account for unclassified elements
  std::vector<std::string> allBCName(2, "");
  std::vector<std::string> allBCFamilyName(2, "");

  // read number of zones (allZones[0] is dummy because index starts at 1) 
  int nbZone = 0;
  cgnsErr = cg_nzones(fileIndex, baseIndex, &nbZone);
  if(cgnsErr != CG_OK) return cgnsError();

  // create all zones by reading basic info
  std::vector<CGNSZone *> allZones(nbZone+1);
  std::map<std::string, int> name2Zone;
  createZones(fileIndex, baseIndex, meshDim, allZones, name2Zone);

  // read mesh in zones
  std::vector<MVertex *> allVert;                     // all vertices
  std::map<int, std::vector<MElement *> > allElt[10]; // all elements by type
  std::map<int, int> bc2Family;                       // bc tag -> family
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    CGNSZone *zone = allZones[iZone];
    int err = zone->readMesh(dim, scale, allZones, allVert, allElt, allBCName,
                             bc2Family, allBCFamilyName);
    if(err == 0) return 0;
  }

  // close file
  cgnsErr = cg_close(fileIndex);
  if(cgnsErr != CG_OK) return cgnsError();

  // populate data structures with elements and vertices
  for(int i = 0; i < 10; i++) _storeElementsInEntities(allElt[i]);
  if(CTX::instance()->mesh.cgnsConstructTopology) createTopologyFromMeshNew();
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(allVert);

  // add periodic vertex correspondence
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    CGNSZone *zone = allZones[iZone];
    for(std::size_t iPer = 0; iPer < zone->slaveVert().size(); iPer++) {
      const std::vector<MVertex *> &slaveVert = zone->slaveVert()[iPer];
      const std::vector<MVertex *> &masterVert = zone->masterVert()[iPer];
      for(std::size_t iV = 0; iV < slaveVert.size(); iV++) {
        MVertex *sVert = slaveVert[iV], *mVert = masterVert[iV];
        GEntity *sEnt = sVert->onWhat(), *mEnt = mVert->onWhat();
        sEnt->correspondingVertices[sVert] = mVert;
        if(sEnt->getMeshMaster() == sEnt) {
          sEnt->setMeshMaster(mEnt, zone->perTransfo()[iPer]);
        }
      }
    }
  }

  // remove potential duplicate vertices if several zones
  // TODO: disable this through option ?
  if(nbZone > 1) removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);

  // set names of geometric entities from BC names
  for (int d = 0; d <= meshDim; d++) {
    std::vector<GEntity *> ent;
    getEntities(ent, d);
    std::map<int, std::map<int, std::string> > physicalBnd;
    for(std::size_t iEnt = 0; iEnt < ent.size(); iEnt++) {
      int tag = ent[iEnt]->tag();
      const std::string &entName = allBCName[tag];
      if(entName.length() > 0) setElementaryName(d, tag, entName);
      const std::map<int, int>::iterator itFam = bc2Family.find(tag);
      if(itFam != bc2Family.end()) {
        const int family = itFam->second;
        const std::string &familyName = allBCFamilyName[family];
        physicalBnd[tag][tag] = familyName;
        _physicalNames[std::make_pair(d, tag)] = familyName;
      }
    }
    _storePhysicalTagsInEntities(d, physicalBnd);
  }

  // destroy all zones
  for(std::size_t iZone = 0; iZone < allZones.size(); iZone++) {
    if(allZones[iZone] != 0) delete allZones[iZone];
  }

  return 1;
}


int GModel::writeCGNS(const std::string &name, bool saveAll,
                      double scalingFactor)
{
  int cgnsErr;

  int cgIndexFile = 0;
  cgnsErr = cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile);
  if(cgnsErr != CG_OK) return cgnsError();

  // write the base node
  int meshDim = getMeshDim(), dim = getDim(), cgIndexBase = 0;
  size_t posStartName = name.find_last_of("/\\");
  if (posStartName == std::string::npos) posStartName = 0;
  else posStartName++;
  std::string baseName = cgnsString(name.substr(posStartName));
  cgnsErr = cg_base_write(cgIndexFile, baseName.c_str(), meshDim, dim,
                          &cgIndexBase);
  if(cgnsErr != CG_OK) return cgnsError();

  // write information about who generated the mesh
  cgnsErr = cg_goto(cgIndexFile, cgIndexBase, "end");
  if(cgnsErr != CG_OK) return cgnsError();
  cgnsErr = cg_descriptor_write("About", "Created by Gmsh");
  if(cgnsErr != CG_OK) return cgnsError();

  // Zone names
  const size_t numPart = getNumPartitions();
  std::vector<std::string> zoneName(numPart+1);

  // index mesh nodes, as CGNS does not store node tags
  if(noPhysicalGroups()) saveAll = true;
  const size_t numNodes = indexMeshVertices(saveAll);

  // get entities from model
  std::vector<GEntity *> entities, entitiesPer, entitiesInterf;
  getEntities(entities);
  getPeriodicEntities(entities, entitiesPer);
  if (numPart > 0) {
    getPartitionInterfaceEntities(entities, entitiesInterf);
    if (entitiesInterf.size() == 0) {
      Msg::Error("Partitioned entities not detected");
    }
  }

  // initialize vertex -> (partition, local node index) for periodic and
  // interface entities
  Msg::Info("Looking for periodic/interface vertices");
  Vertex2LocalData interfVert2Local;
  initInterfVertex2LocalData(entitiesPer, entitiesInterf, interfVert2Local);
  Msg::Info("%i periodic/interface vertices found", interfVert2Local.size());

  // write partitions and periodic/partition connectivities
  if (numPart == 0) {                                   // mesh not partitioned
    int err = writeZone(this, saveAll, scalingFactor, meshDim, numNodes, 0,
                        entities, cgIndexFile, cgIndexBase, zoneName,
                        interfVert2Local);
    if(err == 0) return 0;
    if (entitiesPer.size() > 0) {
      err = writePeriodic(entitiesPer, cgIndexFile, cgIndexBase, zoneName,
                          interfVert2Local);
      if(err == 0) return 0;
    }
  }
  else {                                                // partitioned mesh
    std::vector<std::vector<GEntity *> > entitiesPart;
    entitiesPart.resize(numPart+1);
    getEntitiesInPartitions(entities, entitiesPart);
    for(std::size_t iPart = 1; iPart <= numPart; iPart++) {
      printProgress("Writing partition", iPart, numPart);
      int err = writeZone(this, saveAll, scalingFactor, meshDim, numNodes,
                          iPart, entitiesPart[iPart], cgIndexFile, cgIndexBase,
                          zoneName, interfVert2Local);
      if(err == 0) return 0;
    }             // loop on partitions
    if (entitiesPer.size() > 0) {
      int err = writePeriodic(entitiesPer, cgIndexFile, cgIndexBase, zoneName,
                              interfVert2Local);
      if(err == 0) return 0;
    }
    if (entitiesInterf.size() > 0) {
      int err = writeInterfaces(entitiesInterf, cgIndexFile, cgIndexBase,
                                zoneName, interfVert2Local);
      if(err == 0) return 0;
    }
  }   // numPart == 0

  cgnsErr = cg_close(cgIndexFile);
  if(cgnsErr != CG_OK) return cgnsError();

  return 1;
}


#else


int GModel::readCGNS(const std::string &name)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}


int GModel::writeCGNS(const std::string &name, bool saveAll,
                      double scalingFactor)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}


#endif
