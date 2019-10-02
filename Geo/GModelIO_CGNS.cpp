// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <string>
#include <map>
#include <utility>
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


// Type for periodic node correpondence (global indices)
typedef std::map<MVertex *, MVertex *> VertVertMap;

// Type for global node index -> (partition, local node index) correspondence
struct LocalData { unsigned int partition = 0; CGNS::cgsize_t index = 0; };
// typedef std::vector<LocalData> Global2LocalData;
typedef std::map<MVertex *, std::vector<LocalData> > Vertex2LocalData;


// Types for periodic and interface connectivities
typedef std::pair<unsigned int, unsigned int> PartitionInterface;
typedef std::pair<GEntity *, GEntity *> EntityInterface;
typedef std::pair<PartitionInterface, EntityInterface> PeriodicInterface;
// struct PeriodicInterface {
//   GEntity *slaveEnt;        // Slave (parent) entity
//   unsigned int slavePart;
//   GEntity *masterEnt;       // Master (parent) entity
//   unsigned int masterPart;
// };
// struct Less_PeriodicInterface :
//   public std::binary_function<PeriodicInterface, PeriodicInterface, bool> {
//   bool operator()(const PeriodicInterface &i1, const PeriodicInterface &i2)
//     const
//   {
//     if (i1.slaveEnt < i2.slaveEnt) return true;
//     if (i1.slaveEnt > i2.slaveEnt) return false;
//     if (i1.masterEnt < i2.masterEnt) return true;
//     if (i1.masterEnt > i2.masterEnt) return false;
//     if (i1.slavePart < i2.slavePart) return true;
//     if (i1.slavePart > i2.slavePart) return false;
//     if (i1.masterPart < i2.masterPart) return true;
//     if (i1.masterPart > i2.masterPart) return false;
//     return false;
//   }
// };
typedef std::pair<std::vector<CGNS::cgsize_t>, std::vector<CGNS::cgsize_t> >
  NodeCorrespondence;
typedef std::map<PeriodicInterface, NodeCorrespondence> PeriodicConnection;
typedef std::map<PartitionInterface, NodeCorrespondence> PartitionConnection;


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


void printProgress(const char *cstr, size_t i, size_t num)
{
  if(num > 100) {
    if(i % 100 == 1) {
      Msg::Info("%s %d/%d", cstr, i, num);
    }
  }
  else {
    Msg::Info("%s %d/%d", cstr, i, num);
  }
}


void initInterfVertex2LocalData(const std::vector<GEntity *> &entitiesPer,
                                const std::vector<GEntity *> &entitiesInterf,
                                Vertex2LocalData &interfVert2Local)
{
  // Periodic entities
  for(std::size_t i = 0; i < entitiesPer.size(); i++) {
    VertVertMap &vv = entitiesPer[i]->correspondingVertices;
    for(VertVertMap::iterator itV = vv.begin(); itV != vv.end(); itV++) {
      interfVert2Local[itV->first] = std::vector<LocalData>();
      interfVert2Local[itV->second] = std::vector<LocalData>();
    }
  }

  // Partition interface boundaries
  for(std::size_t i = 0; i < entitiesInterf.size(); i++) {
    GEntity *ge = entitiesInterf[i];
    for(std::size_t iV = 0; iV < ge->getNumMeshVertices(); iV++) {
      interfVert2Local[ge->getMeshVertex(iV)] = std::vector<LocalData>();
    }
  }
}


// create periodic connections for all entities in all partitions
int writePeriodic(const std::vector<GEntity *> &entitiesPer, int cgIndexFile,
                   int cgIndexBase, const std::vector<std::string> &zoneName,
                   Vertex2LocalData &interfVert2Local)
{
  // Construct interfaces [slave (entity, part.) <-> master (entity, part.)] with
  // corresponding nodes
  PeriodicConnection connect;
  typedef std::map<MVertex *, MVertex *> VertVertMap;
  for(std::size_t iEnt = 0; iEnt < entitiesPer.size(); iEnt++) {
    GEntity *slaveEnt = entitiesPer[iEnt];
    GEntity *masterEnt = slaveEnt->getMeshMaster();
    Msg::Info("Constructing periodic connectivities for slave entity %i and "
              "master entity %i", slaveEnt->tag(), masterEnt->tag());
    VertVertMap &vv = slaveEnt->correspondingVertices;
    for(VertVertMap::iterator itV = vv.begin(); itV != vv.end(); itV++) {
      const std::vector<LocalData> &allSlaveData = interfVert2Local[itV->first];
      const std::vector<LocalData> &allMasterData = interfVert2Local[itV->second];
      for (std::size_t iS = 0; iS < allSlaveData.size(); iS++) {
        const LocalData &slaveData = allSlaveData[iS];
        for (std::size_t iM = 0; iM < allMasterData.size(); iM++) {
          const LocalData &masterData = allMasterData[iM];
          PartitionInterface partInt = std::make_pair(slaveData.partition,
                                                      masterData.partition);
          EntityInterface entInt = std::make_pair(slaveEnt, masterEnt);
          PeriodicInterface perInt = std::make_pair(partInt, entInt);
          NodeCorrespondence &nc = connect[perInt];
          nc.first.push_back(slaveData.index);
          nc.second.push_back(masterData.index);
        }
      }
    }
  }

  // write periodic interfaces
  typedef PeriodicConnection::iterator PerConnectIter;
  for(PerConnectIter it = connect.begin(); it != connect.end(); ++it) {
    printProgress("Writing periodic interface",
                  std::distance(connect.begin(), it)+1, connect.size());
    const PeriodicInterface &perInt = it->first;
    const PartitionInterface &partInt = perInt.first;
    const EntityInterface &entInt = perInt.second;
    const std::size_t &slavePart = partInt.first;
    const int slaveEntTag = entInt.first->tag();
    const std::size_t &masterPart = partInt.second;
    const int masterEntTag = entInt.second->tag();
    const NodeCorrespondence &nc = it->second;
    const std::vector<CGNS::cgsize_t> &slaveNodes = nc.first;
    const std::vector<CGNS::cgsize_t> &masterNodes = nc.second;
    int slaveZone = (slavePart == 0) ? 1 : slavePart;
    const std::string &masterZoneName = zoneName[masterPart]; 
    std::ostringstream ossInt;
    ossInt << "Part" << slavePart << "_Ent" << slaveEntTag
           << "_Part" << masterPart << "_Ent" << masterEntTag;
    const std::string interfaceName = cgnsString(ossInt.str()); 
    int dum;
    CGNS::cg_conn_write(cgIndexFile, cgIndexBase, slaveZone,
                        interfaceName.c_str(), CGNS::Vertex, CGNS::Abutting1to1,
                        CGNS::PointList, slaveNodes.size(), slaveNodes.data(),
                        masterZoneName.c_str(), CGNS::Unstructured,
                        CGNS::PointListDonor, CGNS::DataTypeNull,
                        masterNodes.size(), masterNodes.data(), &dum);
  }

  return 0;
}


// const std::vector<unsigned int> &getPartitions(const GEntity *ge)
// {
//   switch(ge->geomType()) {
//   case GEntity::PartitionVolume: {
//     return static_cast<const partitionRegion *>(ge)->getPartitions();
//   } break;
//   case GEntity::PartitionSurface: {
//     return static_cast<const partitionFace *>(ge)->getPartitions();
//   } break;
//   case GEntity::PartitionCurve: {
//     return static_cast<const partitionEdge *>(ge)->getPartitions();
//   } break;
//   case GEntity::PartitionPoint: {
//     return static_cast<const partitionVertex *>(ge)->getPartitions();
//   } break;
//   default: {  // should not happen
//     Msg::Error("Entity %i is not a partitioned entity", ge->tag());
//     return std::vector<unsigned int>();
//   } break;
//   }
// }


// create partition interfaces
int writeInterfaces(const std::vector<GEntity *> &entitiesInterf,
                    int cgIndexFile, int cgIndexBase,
                    const std::vector<std::string> &zoneName,
                    Vertex2LocalData &interfVert2Local)
{
  // Construct interfaces with corresponding nodes (in both directions)
  Msg::Info("Constructing connectivities for %i partition interface entities",
            entitiesInterf.size());
  PartitionConnection connect;
  for(std::size_t iEnt = 0; iEnt < entitiesInterf.size(); iEnt++) {
    GEntity *ge = entitiesInterf[iEnt];
    for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
      MVertex *mv = ge->getMeshVertex(j);
      const std::vector<LocalData> &allLocalData = interfVert2Local[mv];
      for (std::size_t iS = 0; iS < allLocalData.size(); iS++) {
        const LocalData &slaveData = allLocalData[iS];
        for (std::size_t iM = 0; iM < allLocalData.size(); iM++) {
          if (iM == iS) continue;
          const LocalData &masterData = allLocalData[iM];
          std::pair<unsigned int, unsigned int> partInt(slaveData.partition,
                                                        masterData.partition);
          NodeCorrespondence &nc = connect[partInt];
          nc.first.push_back(slaveData.index);
          nc.second.push_back(masterData.index);
        }
      }
    }
  }

  // write periodic interfaces
  typedef PartitionConnection::iterator PartConnectIter;
  std::size_t iPartConnect = 0;
  for(PartConnectIter it = connect.begin(); it != connect.end(); ++it) {
    iPartConnect++;
    printProgress("Writing partition interface", iPartConnect, connect.size());
    const std::pair<unsigned int, unsigned int> &partInt = it->first;
    const std::size_t &slavePart = partInt.first;
    const std::size_t &masterPart = partInt.second;
    const NodeCorrespondence &nc = it->second;
    const std::string &masterZoneName = zoneName[masterPart]; 
    std::ostringstream ossInt;
    ossInt << "Part" << slavePart << "_Part" << masterPart;
    const std::string interfaceName = cgnsString(ossInt.str()); 
    int dum;
    CGNS::cg_conn_write(cgIndexFile, cgIndexBase, slavePart,
                        interfaceName.c_str(), CGNS::Vertex, CGNS::Abutting1to1,
                        CGNS::PointList, nc.first.size(), nc.first.data(),
                        masterZoneName.c_str(), CGNS::Unstructured,
                        CGNS::PointListDonor, CGNS::DataTypeNull,
                        nc.second.size(), nc.second.data(), &dum);
  }

  return 0;
}


// create a single zone for a whole partition; nodes and elements are
// referenced with per-zone index (starting at 1) inside a zone
int writeZone(GModel *model, bool saveAll, double scalingFactor,
              int meshDim, size_t numNodesTotal, size_t partition,
              const std::vector<GEntity *> &entities, int cgIndexFile,
              int cgIndexBase, std::vector<std::string> &zoneName,
              Vertex2LocalData &interfVert2Local)
{
  // build set of nodes first, use elements because nodes not all in
  // GEntity::mesh_vertices if entities do not include partition interfaces
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

  // build global -> partition-local node index correspondence and
  // store local data correspondence for periodic/interface nodes
  typedef std::set<MVertex *>::iterator NodeSetIter;
  std::vector<LocalData> global2Local(numNodesTotal+1);
  // std::vector<long> local2GlobalInd(nodeSet.size()+1, 0);
  CGNS::cgsize_t numNodes = 0;
  for(NodeSetIter itN = nodeSet.begin(); itN != nodeSet.end(); ++itN) {
    const long gInd = (*itN)->getIndex();
    if (gInd < 0) continue;
    numNodes++;
    // local2GlobalInd[numNodes] = gInd;
    LocalData &ld = global2Local[gInd];
    ld.partition = partition;
    ld.index = numNodes;
    Vertex2LocalData::iterator itPN = interfVert2Local.find(*itN);
    if (itPN != interfVert2Local.end()) itPN->second.push_back(ld);
  }

  // // build periodic node correspondence (global indices)
  // // note: cannot use cgsize_t for periodic indexing because global indices are
  // // stored in DataArray_t CGNS structures
  // // FIXME: periodic node correspondence will be moved from parent entities to
  // // partitioned entities
  // typedef std::set<GEntity *> EntSet;
  // typedef std::map<MVertex *, MVertex *> VertVertMap;
  // EntSet parentEnt;
  // std::size_t maxNumPerNodes = 0;
  // if (partition == 0) {
  //   parentEnt.insert(entities.begin(), entities.end());
  //   maxNumPerNodes = numNodes;
  // }
  // else {
  //   for(std::size_t i = 0; i < entities.size(); i++) {
  //     GEntity *pe = entities[i]->getParentEntity();
  //     if(pe != 0) {
  //       parentEnt.insert(pe);
  //       maxNumPerNodes += pe->correspondingVertices.size();
  //     }
  //   }
  // }
  // CGNS::cgsize_t numPerNodes = 0;
  // std::vector<long> slaveGlobalIndex;
  // std::vector<long> masterGlobalIndex;
  // masterGlobalIndex.reserve(maxNumPerNodes);
  // slaveGlobalIndex.reserve(maxNumPerNodes);
  // for(EntSet::iterator it = parentEnt.begin(); it != parentEnt.end(); ++it) {
  //   GEntity *g_slave = *it;
  //   GEntity *g_master = g_slave->getMeshMaster();
  //   if (g_slave == g_master) continue;
  //   VertVertMap &vv = g_slave->correspondingVertices;
  //   for(VertVertMap::iterator it = vv.begin(); it != vv.end(); it++) {
  //     const long slaveInd = it->first->getIndex();
  //     std::pair<size_t, CGNS::cgsize_t> &locData = global2Local[slaveInd];
  //     if((locData.first == partition) && (locData.second != 0)) {
  //       slaveGlobalIndex.push_back(slaveInd);
  //       masterGlobalIndex.push_back(it->second->getIndex());
  //       numPerNodes++;
  //     }
  //   }
  // }

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
  zoneName[partition] = modelName + partSuffix;
  if(CGNS::cg_zone_write(cgIndexFile, cgIndexBase, zoneName[partition].c_str(),
                         cgZoneSize, CGNS::Unstructured, &cgIndexZone))
    return cgnsError();

  // create a CGNS grid with x, y and z coordinates of all the nodes (that are
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
      const int ln = global2Local[n].index;
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

  // // write list of global node indices and periodic nodes in a UserDefined_t
  // // CGNS node 
  // if(CGNS::cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone, "end"))
  //   return cgnsError();
  // if(CGNS::cg_user_data_write("NodeInformation")) return cgnsError();
  // if(CGNS::cg_gorel(cgIndexFile, "NodeInformation", 0, "end"))
  //   return cgnsError();
  // if(CGNS::cg_array_write("GlobalNodeIndices", CGNS::LongInteger, 1, &numNodes,
  //                         (void*)(local2GlobalInd.data()+1)))
  //   return cgnsError();
  // if (numPerNodes > 0) {
  //   if(CGNS::cg_user_data_write("PeriodicNodeInformation")) return cgnsError();
  //   if(CGNS::cg_gorel(cgIndexFile, "PeriodicNodeInformation", 0, "end"))
  //     return cgnsError();
  //   if(CGNS::cg_array_write("SlaveGlobalIndices", CGNS::LongInteger, 1,
  //                           &numPerNodes, (void*)(slaveGlobalIndex.data())))
  //     return cgnsError();
  //   if(CGNS::cg_array_write("MasterGlobalIndices", CGNS::LongInteger, 1,
  //                           &numPerNodes, (void*)(masterGlobalIndex.data())))
  //     return cgnsError();
  // }

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
            elemNodes[n] = global2Local[gInd].index;
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


// Get all partition interface entities
void getPeriodicEntities(const std::vector<GEntity *> &entities,
                         std::vector<GEntity *> &entitiesPer)
{
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *slaveEnt = entities[i];
    GEntity *masterEnt = slaveEnt->getMeshMaster();
    if (slaveEnt != masterEnt) entitiesPer.push_back(slaveEnt);
  }
}


// Get all partition interface entities
void getPartitionInterfaceEntities(const std::vector<GEntity *> &entities,
                                   std::vector<GEntity *> &entitiesInt)
{
  for(std::size_t j = 0; j < entities.size(); j++) {
    GEntity *ge = entities[j];
    switch(ge->geomType()) {
    case GEntity::PartitionVolume: {
      partitionRegion *pr = static_cast<partitionRegion *>(ge);
      if (pr->getParentEntity()->dim() != pr->dim()) entitiesInt.push_back(ge);
    } break;
    case GEntity::PartitionSurface: {
      partitionFace *pf = static_cast<partitionFace *>(ge);
      if (pf->getParentEntity()->dim() != pf->dim()) entitiesInt.push_back(ge);
    } break;
    case GEntity::PartitionCurve: {
      partitionEdge *pe = static_cast<partitionEdge *>(ge);
      if (pe->getParentEntity()->dim() != pe->dim()) entitiesInt.push_back(ge);
    } break;
    case GEntity::PartitionPoint: {
      partitionVertex *pv = static_cast<partitionVertex *>(ge);
      if (pv->getParentEntity()->dim() != pv->dim()) entitiesInt.push_back(ge);
    } break;
    default:
      break;
    }         // switch
  }           // loop on entities
}


// Get entities in each partition, except partition interfaces
void getEntitiesInPartitions(const std::vector<GEntity *> &entities,
                             std::vector<std::vector<GEntity *> > &entitiesPart)
{
  for(std::size_t j = 0; j < entities.size(); j++) {
    GEntity *ge = entities[j];
    const std::vector<unsigned int> *parts = 0;
    switch(ge->geomType()) {
    case GEntity::PartitionVolume: {
      partitionRegion *pr = static_cast<partitionRegion *>(ge);
      if (pr->getParentEntity()->dim() != pr->dim()) continue;  // Skip partition interfaces
      parts = &(pr->getPartitions());
    } break;
    case GEntity::PartitionSurface: {
      partitionFace *pf = static_cast<partitionFace *>(ge);
      if (pf->getParentEntity()->dim() != pf->dim()) continue;  // Skip partition interfaces
      parts = &(pf->getPartitions());
    } break;
    case GEntity::PartitionCurve: {
      partitionEdge *pe = static_cast<partitionEdge *>(ge);
      if (pe->getParentEntity()->dim() != pe->dim()) continue;  // Skip partition interfaces
      parts = &(pe->getPartitions());
    } break;
    case GEntity::PartitionPoint: {
      partitionVertex *pv = static_cast<partitionVertex *>(ge);
      if (pv->getParentEntity()->dim() != pv->dim()) continue;  // Skip partition interfaces
      parts = &(pv->getPartitions());
    } break;
    default:
      break;
    }         // switch
    if (parts != 0) {
      for (std::size_t iPart = 0; iPart < parts->size(); iPart++) {
        entitiesPart[(*parts)[iPart]].push_back(ge);
      }
    }
  }           // loop on entities
}


// // Get all entities in a partition, except partition interfaces
// void getEntitiesInPartition(const std::vector<GEntity *> &entities,
//                             std::size_t iPart,
//                             std::vector<GEntity *> &entitiesPart)
// {
//   for(std::size_t j = 0; j < entities.size(); j++) {
//     GEntity *ge = entities[j];
//     switch(ge->geomType()) {
//     case GEntity::PartitionVolume: {
//       partitionRegion *pr = static_cast<partitionRegion *>(ge);
//       if (pr->getParentEntity()->dim() != pr->dim()) continue;  // Skip partition interfaces
//       if (std::find(pr->getPartitions().begin(), pr->getPartitions().end(),
//                     iPart) != pr->getPartitions().end()) {
//         entitiesPart.push_back(pr);
//       }
//     } break;
//     case GEntity::PartitionSurface: {
//       partitionFace *pf = static_cast<partitionFace *>(ge);
//       if (pf->getParentEntity()->dim() != pf->dim()) continue;  // Skip partition interfaces
//       if (std::find(pf->getPartitions().begin(), pf->getPartitions().end(),
//                     iPart) != pf->getPartitions().end()) {
//         entitiesPart.push_back(pf);
//       }
//     } break;
//     case GEntity::PartitionCurve: {
//       partitionEdge *pe = static_cast<partitionEdge *>(ge);
//       if (pe->getParentEntity()->dim() != pe->dim()) continue;  // Skip partition interfaces
//       if (std::find(pe->getPartitions().begin(), pe->getPartitions().end(),
//                     iPart) != pe->getPartitions().end()) {
//         entitiesPart.push_back(pe);
//       }
//     } break;
//     case GEntity::PartitionPoint: {
//       partitionVertex *pv = static_cast<partitionVertex *>(ge);
//       if (pv->getParentEntity()->dim() != pv->dim()) continue;  // Skip partition interfaces
//       if (std::find(pv->getPartitions().begin(), pv->getPartitions().end(),
//                     iPart) != pv->getPartitions().end()) {
//         entitiesPart.push_back(pv);
//       }
//     } break;
//     default:
//       break;
//     }         // switch
//   }           // loop on entities
// }


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
//      getEntitiesInPartition(entities, iPart, entitiesPart[iPart]);
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
