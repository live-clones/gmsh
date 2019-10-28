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
#include "CGNSRead.h"

#if defined(HAVE_LIBCGNS)


int GModel::readCGNS(const std::string &name)
{
  int cgnsErr;

  // open CGNS file and read scale
  int cgIndexFile = 0;
  cgnsErr = cg_open(name.c_str(), CG_MODE_READ, &cgIndexFile);
  if(cgnsErr != CG_OK) return cgnsError();
  const double scale = readScale();

  // read base node
  const int cgIndexBase = 1;
  int dim = 0, meshDim = 0;
  char baseName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_base_read(cgIndexFile, cgIndexBase, baseName, &dim, &meshDim);
  if(cgnsErr != CG_OK) return cgnsError();

  // read mesh zones
  std::vector<MVertex *> allVert;
  std::map<int, std::vector<MElement *> > allElt[10];
  std::vector<std::string> allBCName, allBCFamilyName;
  std::map<int, int> bc2Family;
  int nbZones = 0;
  cgnsErr = cg_nzones(cgIndexFile, cgIndexBase, &nbZones);
  if(cgnsErr != CG_OK) return cgnsError();
  for(int iZone = 1; iZone <= nbZones; iZone++) {
    int err = readZone(cgIndexFile, cgIndexBase, iZone, dim, scale, allVert,
                       allElt, allBCName, bc2Family, allBCFamilyName);
    if(err == 0) return 0;
  }

  cgnsErr = cg_close(cgIndexFile);
  if(cgnsErr != CG_OK) return cgnsError();

  // remove duplicate vertices
  removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);

  // populate data structures with elements and vertices
  for(int i = 0; i < 10; i++) _storeElementsInEntities(allElt[i]);
  if(CTX::instance()->mesh.cgnsConstructTopology) createTopologyFromMeshNew();
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(allVert);

  // add physical tags (BC family names)
  typedef std::map<int, int>::iterator BC2FamilyIter;
  std::map<int, std::map<int, std::string> > physicalBnd;
  for(BC2FamilyIter it = bc2Family.begin(); it != bc2Family.end(); it++) {
    const int entity = it->first;
    const std::string &familyName = allBCFamilyName[it->second];
    physicalBnd[entity][entity] = familyName;
    _physicalNames[std::make_pair(meshDim-1, entity)] = familyName;
  }
  _storePhysicalTagsInEntities(meshDim-1, physicalBnd);

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
