// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "CGNSConventions.h"

#if defined(HAVE_LIBCGNS)

// FIXME TT: cgnslib.h is not suited to namespaces as it is full of defines
// (hence the dirty redefine of csize_t). Namespace CGNS should be removed.
namespace CGNS {
#include <cgnslib.h>
#ifdef cgsize_t
#undef cgsize_t
  typedef int cgsize_t;
#endif
} // namespace CGNS


namespace {


int cgnsError(const int cgIndexFile = -1)
{
  Msg::Error("Error detected by CGNS library");
  Msg::Error(CGNS::cg_get_error());
  if(cgIndexFile != -1) {
    if(CGNS::cg_close(cgIndexFile)) {
      Msg::Error("Unable to close CGNS file");
    }
  }
  return 0;
}


// create a single zone for the whole partition; nodes and elements are
// referenced with per-zone index (starting at 1) inside a zone
int writeZone(GModel *model, bool saveAll, double scalingFactor,
              size_t numNodesTotal, size_t partition,
              const std::vector<GEntity *> &entities, int cgIndexFile,
              int cgIndexBase)
{
  int meshDim = model->getMeshDim();

  // build set of nodes first, use elements because nodes not all in
  // entities[i]->mesh_vertices if entities do not include partition interfaces
  std::set<MVertex *> nodeSet;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    std::vector<int> eleTypes;
    ge->getElementTypes(eleTypes);
    for(std::size_t eleType = 0; eleType < eleTypes.size(); eleType++) {
      int numEle = ge->getNumMeshElementsByType(eleTypes[eleType]);
      if(numEle && (saveAll || ge->physicals.size())) {
        for(int j = 0; j < numEle; j++) {
          MElement *me = ge->getMeshElementByType(eleTypes[eleType], j);
          for(std::size_t k = 0; k < me->getNumVertices(); k++) {
            nodeSet.insert(me->getVertex(k));
          }
        }
      }
    }
  }

  // build global <-> partition-local node index correspondence
  // note: cannot use cgsize_t for global indexing because global indices are
  // stored in DataArray_t CGNS structures
  typedef std::set<MVertex *>::iterator NodeSetIter;
  std::vector<CGNS::cgsize_t> g2LIndex(numNodesTotal+1, 0);
  std::vector<long> l2GIndex(nodeSet.size()+1, 0);
  CGNS::cgsize_t numNodes = 0;
  for(NodeSetIter it = nodeSet.begin(); it != nodeSet.end(); ++it) {
    const long gInd = (*it)->getIndex();
    if (gInd < 0) continue;
    numNodes++;
    g2LIndex[gInd] = numNodes;
    l2GIndex[numNodes] = gInd;
  }

  // build periodic node correspondence (global indices)
  // note: cannot use cgsize_t for periodic indexing because global indices are
  // stored in DataArray_t CGNS structures
  typedef std::set<GEntity *> EntSet;
  typedef std::map<MVertex *, MVertex *> VertVertMap;
  EntSet parentEnt;
  std::size_t maxNumPerNodes = 0;
  if (partition == 0) {
    parentEnt.insert(entities.begin(), entities.end());
    maxNumPerNodes = numNodes;
  }
  else {
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *pe = entities[i]->getParentEntity();
      if(pe != 0) {
        parentEnt.insert(pe);
        maxNumPerNodes += pe->correspondingVertices.size();
      }
    }
  }
  CGNS::cgsize_t numPerNodes = 0;
  std::vector<long> slaveGlobalIndex;
  std::vector<long> masterGlobalIndex;
  masterGlobalIndex.reserve(maxNumPerNodes);
  slaveGlobalIndex.reserve(maxNumPerNodes);
  for(EntSet::iterator it = parentEnt.begin(); it != parentEnt.end(); ++it) {
    GEntity *g_slave = *it;
    GEntity *g_master = g_slave->getMeshMaster();
    if (g_slave == g_master) continue;
    VertVertMap &vv = g_slave->correspondingVertices;
    // std::cout << "DBGTT: in partition " << partition << ", entity " << g_slave->tag() << " has " << vv.size() << " periodic vertices with master " << g_master->tag() << "\n";
    for(VertVertMap::iterator it = vv.begin(); it != vv.end(); it++) {
      const long slaveInd = it->first->getIndex();
      if(g2LIndex[slaveInd] != 0) {
        slaveGlobalIndex.push_back(slaveInd);
        masterGlobalIndex.push_back(it->second->getIndex());
        numPerNodes++;
      }
    }
  }
  // if (numPerNodes > 0) std::cout << "DBGTT: numPerNodes = " << numPerNodes << "\n";

  // number of elements for highest spatial dimension
  CGNS::cgsize_t numElementsMaxDim = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    if(ge->dim() == meshDim && (saveAll || ge->physicals.size())) {
      numElementsMaxDim += ge->getNumMeshElements();
    }
  }

  // write zone CGNS node
  int cgIndexZone = 0;
  CGNS::cgsize_t cgZoneSize[3] = {numNodes, numElementsMaxDim, 0};
  std::ostringstream ossPart;
  ossPart << "_Part" << partition;
  std::string partSuffix = ossPart.str();
  std::string modelName = cgnsString(model->getName(), 32-partSuffix.size());
  std::string zoneName = modelName + partSuffix;
  if(CGNS::cg_zone_write(cgIndexFile, cgIndexBase, zoneName.c_str(), cgZoneSize,
                         CGNS::Unstructured, &cgIndexZone))
    return cgnsError();

  // create a grid with x, y and z coordinates of all the nodes (that are
  // referenced by elements)
  int cgIndexGrid = 0;
  if(CGNS::cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                         "GridCoordinates", &cgIndexGrid))
    return cgnsError();

  // create lists of coordinates
  std::vector<double> xcoord(numNodes), ycoord(numNodes), zcoord(numNodes);
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
      MVertex *mv = ge->getMeshVertex(j);
      const int n = mv->getIndex();
      if(n < 0) continue;
      const int ln = g2LIndex[n];
      if(ln > numNodes) { // should never happen
        Msg::Error("Incoherent mesh node indexing in CGNS writer");
        return 0;
      }
      xcoord[ln - 1] = mv->x() * scalingFactor;
      ycoord[ln - 1] = mv->y() * scalingFactor;
      zcoord[ln - 1] = mv->z() * scalingFactor;
    }
  }

  // write list of coordinates
  int cgIndexCoord = 0;
  if(CGNS::cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                          CGNS::RealDouble, "CoordinateX", &xcoord[0],
                          &cgIndexCoord))
    return cgnsError();
  if(CGNS::cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                          CGNS::RealDouble, "CoordinateY", &ycoord[0],
                          &cgIndexCoord))
    return cgnsError();
  if(CGNS::cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                          CGNS::RealDouble, "CoordinateZ", &zcoord[0],
                          &cgIndexCoord))
    return cgnsError();

  // write list of global node indices and periodic nodes in a UserDefined_t
  // CGNS node 
  if(CGNS::cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone, "end"))
    return cgnsError();
  if(CGNS::cg_user_data_write("NodeInformation")) return cgnsError();
  // if(CGNS::cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone,
  //                  "NodeInformation", 0, "end"))
  //   return cgnsError();
  if(CGNS::cg_gorel(cgIndexFile, "NodeInformation", 0, "end"))
    return cgnsError();
  if(CGNS::cg_array_write("GlobalNodeIndices", CGNS::LongInteger, 1, &numNodes,
                          (void*)(l2GIndex.data()+1)))
    return cgnsError();
  if (numPerNodes > 0) {
    if(CGNS::cg_user_data_write("PeriodicNodeInformation")) return cgnsError();
    if(CGNS::cg_gorel(cgIndexFile, "PeriodicNodeInformation", 0, "end"))
      return cgnsError();
    if(CGNS::cg_array_write("SlaveGlobalIndices", CGNS::LongInteger, 1,
                            &numPerNodes, (void*)(slaveGlobalIndex.data())))
      return cgnsError();
    if(CGNS::cg_array_write("MasterGlobalIndices", CGNS::LongInteger, 1,
                            &numPerNodes, (void*)(masterGlobalIndex.data())))
      return cgnsError();
  }

  // write an element section for each entity, per element type (TODO: check if
  // using the actual element tag in case the numbering is dense and
  // saveAll==true would make sense/would be useful; maybe in the context of
  // partitioned meshes?)
  CGNS::cgsize_t eleStart = 0, eleEnd = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];

    // FIXME: use MIXED section? -> probably less efficient
    // 2) store physical information in a "family"?
    // get or create the name for the entity 
    std::string entityName = model->getElementaryName(ge->dim(), ge->tag());
    if(entityName.empty()) {
      std::ostringstream s;
      std::string entStr = (ge->dim() == 3) ? "Vol" :
                           (ge->dim() == 2) ? "Surf" :
                           (ge->dim() == 1) ? "Curve" :
                           (ge->dim() == 0) ? "Pnt" : ""; 
      s << "Gmsh_" << entStr << "_" << ge->tag();
      entityName = s.str();
    }
    entityName = cgnsString(entityName);

    // retrieve element types for this geometric entity
    std::vector<int> eleTypes;
    ge->getElementTypes(eleTypes);

    // build list of connectivities
    for(std::size_t eleType = 0; eleType < eleTypes.size(); eleType++) {
      int numEle = ge->getNumMeshElementsByType(eleTypes[eleType]);
      if(numEle && (saveAll || ge->physicals.size())) {
        eleStart = (eleEnd + 1);
        eleEnd += numEle;
        MElement *me = ge->getMeshElementByType(eleTypes[eleType], 0);
        int mshType = me->getTypeForMSH();
        CGNS::ElementType_t cgType = msh2CgnsEltType(mshType);
        if(cgType == CGNS::ElementTypeNull) {
          Msg::Error("Unhandled element type in CGNS ouput (%d)", mshType);
          break;
        }
        std::vector<int> mshNodeInd = cgns2MshNodeIndex(mshType);
        
        int numNodesPerEle = me->getNumVertices();
        std::vector<CGNS::cgsize_t> elemNodes(numEle * numNodesPerEle);
        std::size_t n = 0;
        for(int j = 0; j < numEle; j++) {
          me = ge->getMeshElementByType(eleTypes[eleType], j);
          for(int k = 0; k < numNodesPerEle; k++) {
            const int gInd = me->getVertex(mshNodeInd[k])->getIndex();
            elemNodes[n] = g2LIndex[gInd];
            n++;
          }
        }

        std::ostringstream ossSection(entityName);
        ossSection << "_" << eleTypes[eleType];
        int cgIndexSection = 0;
        if(CGNS::cg_section_write(cgIndexFile, cgIndexBase, cgIndexZone,
                                  ossSection.str().c_str(), cgType, eleStart,
                                  eleEnd, 0, &elemNodes[0], &cgIndexSection))
          return cgnsError();
      }
    }
  }

  return 0;
}


void getEntitiesInPartition(const std::vector<GEntity *> &entities,
                            std::size_t iPart,
                            std::vector<GEntity *> &entitiesPart)
{
  for(std::size_t j = 0; j < entities.size(); j++) {
    GEntity *ge = entities[j];
    switch(ge->geomType()) {
    case GEntity::PartitionVolume: {
      partitionRegion *pr = static_cast<partitionRegion *>(ge);
      if(std::find(pr->getPartitions().begin(), pr->getPartitions().end(),
                    iPart) != pr->getPartitions().end()) {
        entitiesPart.push_back(pr);
      }
    } break;
    case GEntity::PartitionSurface: {
      partitionFace *pf = static_cast<partitionFace *>(ge);
      if(std::find(pf->getPartitions().begin(), pf->getPartitions().end(),
                    iPart) != pf->getPartitions().end()) {
        entitiesPart.push_back(pf);
      }
    } break;
    case GEntity::PartitionCurve: {
      partitionEdge *pe = static_cast<partitionEdge *>(ge);
      if(std::find(pe->getPartitions().begin(), pe->getPartitions().end(),
                    iPart) != pe->getPartitions().end()) {
        entitiesPart.push_back(pe);
      }
    } break;
    case GEntity::PartitionPoint: {
      partitionVertex *pv = static_cast<partitionVertex *>(ge);
      if(std::find(pv->getPartitions().begin(), pv->getPartitions().end(),
                    iPart) != pv->getPartitions().end()) {
        entitiesPart.push_back(pv);
      }
    } break;
    default:
      break;
    }         // switch
  }           // loop on entities
}


} // anonymous namespace


int GModel::readCGNS(const std::string &name) { return 0; }

int GModel::writeCGNS(const std::string &name, bool saveAll,
                      double scalingFactor)
{
  int cgIndexFile = 0;
  if(CGNS::cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile))
    return cgnsError();

  // write the base node
  int meshDim = getMeshDim(), dim = getDim(), cgIndexBase = 0;
  size_t posStartName = name.find_last_of("/\\");
  if (posStartName == std::string::npos) posStartName = 0;
  else posStartName++;
  std::string baseName = cgnsString(name.substr(posStartName));
  if(CGNS::cg_base_write(cgIndexFile, baseName.c_str(), meshDim, dim,
                         &cgIndexBase))
    return cgnsError();

  // write information about who generated the mesh
  if(CGNS::cg_goto(cgIndexFile, cgIndexBase, "end")) return cgnsError();
  if(CGNS::cg_descriptor_write("About", "Created by Gmsh")) return cgnsError();

  // index mesh nodes, as CGNS does not store node tags
  if(noPhysicalGroups()) saveAll = true;
  const size_t numNodes = indexMeshVertices(saveAll);

  // get all entities from model
  std::vector<GEntity *> entities;
  getEntities(entities);

  // write one zone per partition
  if (getNumPartitions() == 0) {                        // mesh not partitioned
    int err = writeZone(this, saveAll, scalingFactor, numNodes, 0, entities,
                        cgIndexFile, cgIndexBase);
    if(err) return err;
  }
  else {                                                // partitioned mesh
    for(std::size_t iPart = 1; iPart <= getNumPartitions(); iPart++) {
      if(getNumPartitions() > 100) {
        if(iPart % 100 == 1) {
          Msg::Info("Writing partition %d/%d", iPart, getNumPartitions());
        }
      }
      else {
        Msg::Info("Writing partition %d", iPart);
      }
      std::vector<GEntity *> entitiesPart;
      getEntitiesInPartition(entities, iPart, entitiesPart);
      int err = writeZone(this, saveAll, scalingFactor, numNodes, iPart,
                          entitiesPart, cgIndexFile, cgIndexBase);
      if(err) return err;
    }             // loop on partitions
  }               // getNumPartitions()

  if(CGNS::cg_close(cgIndexFile)) return cgnsError();

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
