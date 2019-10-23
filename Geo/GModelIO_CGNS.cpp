// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "GModel.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSWrite.h"

#if defined(HAVE_LIBCGNS)


int GModel::readCGNS(const std::string &name)
{
  return 0;
}


int GModel::writeCGNS(const std::string &name, bool saveAll,
                      double scalingFactor)
{
  int cgIndexFile = 0;
  if(cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile))
    return cgnsError();

  // write the base node
  int meshDim = getMeshDim(), dim = getDim(), cgIndexBase = 0;
  size_t posStartName = name.find_last_of("/\\");
  if (posStartName == std::string::npos) posStartName = 0;
  else posStartName++;
  std::string baseName = cgnsString(name.substr(posStartName));
  if(cg_base_write(cgIndexFile, baseName.c_str(), meshDim, dim,
                         &cgIndexBase))
    return cgnsError();

  // write information about who generated the mesh
  if(cg_goto(cgIndexFile, cgIndexBase, "end")) return cgnsError();
  if(cg_descriptor_write("About", "Created by Gmsh")) return cgnsError();

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
    if(err) return err;
    if (entitiesPer.size() > 0) {
      err = writePeriodic(entitiesPer, cgIndexFile, cgIndexBase, zoneName,
                          interfVert2Local);
      if(err) return err;
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
      if(err) return err;
    }             // loop on partitions
    if (entitiesPer.size() > 0) {
      int err = writePeriodic(entitiesPer, cgIndexFile, cgIndexBase, zoneName,
                              interfVert2Local);
      if(err) return err;
    }
    if (entitiesInterf.size() > 0) {
      int err = writeInterfaces(entitiesInterf, cgIndexFile, cgIndexBase,
                                zoneName, interfVert2Local);
      if(err) return err;
    }
  }   // numPart == 0

  if(cg_close(cgIndexFile)) return cgnsError();

  return 0;
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
