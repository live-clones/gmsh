// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Thomas Toulorge

#include <sstream>
#include <string>
#include <map>
#include <utility>
#include "Context.h"
#include "GmshMessage.h"
#include "GModel.h"
#include "partitionRegion.h"
#include "partitionFace.h"
#include "partitionEdge.h"
#include "partitionVertex.h"
#include "nodalBasis.h"
#include "BasisFactory.h"
#include "affineTransformation.h"
#include "CGNSWrite.h"
#include "CGNSConventions.h"

#if defined(HAVE_LIBCGNS)

namespace {

  // Types for periodic and interface connectivities
  typedef std::pair<unsigned int, unsigned int> PartitionInterface;
  typedef std::pair<std::vector<cgsize_t>, std::vector<cgsize_t> >
    NodeCorrespondence;

  static const char INTERPOLATION_ZONE_NAME[] = "ElementHighOrderNodes";

  // Retrieve all nodes (possibly including high-order ones) in the elements
  // contained in the given entities
  template <bool INCLUDE_HO_NODES>
  void getNodesInEntities(const std::vector<GEntity *> &entities,
                          bool allElements, std::set<MVertex *> &nodeSet)
  {
    for(std::size_t i = 0; i < entities.size(); i++) {
      GEntity *ge = entities[i];
      std::vector<int> eleTypes;
      ge->getElementTypes(eleTypes);
      for(std::size_t eleType = 0; eleType < eleTypes.size(); eleType++) {
        int numEle = ge->getNumMeshElementsByType(eleTypes[eleType]);
        if(numEle && (allElements || ge->physicals.size())) {
          for(int j = 0; j < numEle; j++) {
            MElement *me = ge->getMeshElementByType(eleTypes[eleType], j);
            int numEltVert = INCLUDE_HO_NODES ? me->getNumVertices() :
                                                me->getNumPrimaryVertices();
            for(int k = 0; k < numEltVert; k++) {
              nodeSet.insert(me->getVertex(k));
            }
          }
        }
      }
    }
  }

  std::string entTypeShortStr(int dim)
  {
    switch(dim) {
    case 0: return "P"; break;
    case 1: return "L"; break;
    case 2: return "S"; break;
    case 3: return "V"; break;
    }

    return "";
  }

  void getNameFromEntity(GEntity *ge, std::string &entityName)
  {
    // convention: start name with letter identifying dimension
    const std::string entTypeStr = entTypeShortStr(ge->dim());

    // get parent entity and model
    GEntity *geParent = ge->getParentEntity();
    GModel *model = ge->model();

    // name for section: use given (potentially partitioned) entity in addition
    // to the parent entity (if it exists) in order to avoid duplicate CGNS
    // names
    std::ostringstream ossEnt;
    ossEnt << entTypeStr;
    if(geParent != nullptr) ossEnt << "_" << geParent->tag();
    ossEnt << "_" << ge->tag();
    entityName = model->getElementaryName(ge->dim(), ge->tag());
    if(!entityName.empty()) ossEnt << "_" << entityName;
    entityName = cgnsString(ossEnt.str());
  }

} // anonymous namespace

// Get all partition interface entities
void getEntitiesToSave(const std::vector<GEntity *> &allEntities, bool saveAll,
                       std::vector<GEntity *> &entities)
{
  entities.clear();
  entities.reserve(allEntities.size());
  for(std::size_t i = 0; i < allEntities.size(); i++) {
    GEntity *ge = allEntities[i];
    if(ge->getNumMeshElements() == 0) continue;
    if(saveAll || (ge->physicals.size() > 0)) entities.push_back(ge);
  }
}

// Get all periodic entities
void getPeriodicEntities(const std::vector<GEntity *> &allEntities,
                         std::vector<GEntity *> &entitiesPer)
{
  entitiesPer.clear();
  for(std::size_t i = 0; i < allEntities.size(); i++) {
    GEntity *slaveEnt = allEntities[i];
    GEntity *masterEnt = slaveEnt->getMeshMaster();
    if(slaveEnt != masterEnt) entitiesPer.push_back(slaveEnt);
  }
}

// Get all partition interface entities
void getPartitionInterfaceEntities(const std::vector<GEntity *> &entities,
                                   bool saveAll,
                                   std::vector<GEntity *> &entitiesInt)
{
  for(std::size_t j = 0; j < entities.size(); j++) {
    GEntity *ge = entities[j];
    switch(ge->geomType()) {
    case GEntity::PartitionVolume: {
      partitionRegion *pr = static_cast<partitionRegion *>(ge);
      const GEntity *pge = pr->getParentEntity();
      if((pge->dim() != pr->dim()) && (saveAll || (pge->physicals.size() > 0)))
        entitiesInt.push_back(ge);
    } break;
    case GEntity::PartitionSurface: {
      partitionFace *pf = static_cast<partitionFace *>(ge);
      const GEntity *pge = pf->getParentEntity();
      if(pf->getParentEntity()->dim() != pf->dim()) entitiesInt.push_back(ge);
      if((pge->dim() != pf->dim()) && (saveAll || (pge->physicals.size() > 0)))
        entitiesInt.push_back(ge);
    } break;
    case GEntity::PartitionCurve: {
      partitionEdge *pe = static_cast<partitionEdge *>(ge);
      const GEntity *pge = pe->getParentEntity();
      if((pge->dim() != pe->dim()) && (saveAll || (pge->physicals.size() > 0)))
        entitiesInt.push_back(ge);
    } break;
    case GEntity::PartitionPoint: {
      partitionVertex *pv = static_cast<partitionVertex *>(ge);
      const GEntity *pge = pv->getParentEntity();
      if((pge->dim() != pv->dim()) && (saveAll || (pge->physicals.size() > 0)))
        entitiesInt.push_back(ge);
    } break;
    default: break;
    } // switch
  } // loop on entities
}

// Initialize MVertex -> local data correspondence (only for primary vertices)
void initInterfVertex2LocalData(const std::vector<GEntity *> &entitiesPer,
                                const std::vector<GEntity *> &entitiesInterf,
                                Vertex2LocalData &interfVert2Local)
{
  // Periodic entities
  for(std::size_t i = 0; i < entitiesPer.size(); i++) {
    auto &vv = entitiesPer[i]->correspondingVertices;
    for(auto itV = vv.begin(); itV != vv.end(); itV++) {
      interfVert2Local[itV->first] = std::vector<LocalData>();
      interfVert2Local[itV->second] = std::vector<LocalData>();
    }
  }

  // Partition interface boundaries
  std::set<MVertex *> nodeSet;
  getNodesInEntities<false>(entitiesInterf, true, nodeSet);
  for(auto itN = nodeSet.begin(); itN != nodeSet.end(); ++itN) {
    interfVert2Local[*itN] = std::vector<LocalData>();
  }
}

// create a single zone for a whole partition; nodes and elements are
// referenced with per-zone index (starting at 1) inside a zone
int writeZone(GModel *model, bool saveAll, double scalingFactor, int meshDim,
              std::size_t numNodesTotal, std::size_t partition,
              const std::vector<GEntity *> &entities, int cgIndexFile,
              int cgIndexBase, std::vector<std::string> &zoneName,
              Vertex2LocalData &interfVert2Local, std::set<int> &eleMshTypes,
              std::map<GEntity *, std::string> &geomEntities)
{
#ifdef HAVE_LIBCGNS_CPEX0045
  const bool useCPEX0045 = CTX::instance()->mesh.cgnsExportCPEX0045;
#else
  static const bool useCPEX0045 = false;
#endif

  // build set of nodes first, use elements because nodes not all in
  // GEntity::mesh_vertices if entities do not include partition interfaces
  std::set<MVertex *> nodeSet;
  getNodesInEntities<true>(entities, saveAll, nodeSet);

  // build global -> partition-local node index correspondence and
  // store local data correspondence for periodic/interface nodes
  std::vector<LocalData> global2Local(numNodesTotal + 1);
  cgsize_t numNodes = 0;
  for(auto itN = nodeSet.begin(); itN != nodeSet.end(); ++itN) {
    const long gInd = (*itN)->getIndex();
    if(gInd < 0) continue;
    numNodes++;
    LocalData &ld = global2Local[gInd];
    ld.partition = partition;
    ld.index = numNodes;
    auto itPN = interfVert2Local.find(*itN);
    if(itPN != interfVert2Local.end()) itPN->second.push_back(ld);
  }

  // create lists of coordinates
  std::vector<double> xcoord(numNodes), ycoord(numNodes), zcoord(numNodes);
  for(auto itN = nodeSet.begin(); itN != nodeSet.end(); ++itN) {
    const long gInd = (*itN)->getIndex();
    if(gInd < 0) continue;
    const int ln = global2Local[gInd].index;
    xcoord[ln - 1] = (*itN)->x() * scalingFactor;
    ycoord[ln - 1] = (*itN)->y() * scalingFactor;
    zcoord[ln - 1] = (*itN)->z() * scalingFactor;
  }

  // number of elements for highest spatial dimension
  cgsize_t numElementsMaxDim = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    if(ge->dim() == meshDim && (saveAll || ge->physicals.size())) {
      numElementsMaxDim += ge->getNumMeshElements();
    }
  }

  // write zone CGNS node
  int cgnsErr;
  int cgIndexZone = 0;
  cgsize_t cgZoneSize[3] = {numNodes, numElementsMaxDim, 0};
  std::ostringstream ossPart;
  ossPart << "_Part" << partition;
  std::string partSuffix = ossPart.str();
  std::string modelName = cgnsString(model->getName(), 32 - partSuffix.size());
  zoneName[partition] = modelName + partSuffix;
  cgnsErr = cg_zone_write(cgIndexFile, cgIndexBase, zoneName[partition].c_str(),
                          cgZoneSize, CGNS_ENUMV(Unstructured), &cgIndexZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // write ordinal (zone number) and family name for CPEX0045
  cgnsErr = cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone, "end");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  cgnsErr = cg_ordinal_write(cgIndexZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  if(useCPEX0045) {
    cgnsErr = cg_famname_write(INTERPOLATION_ZONE_NAME);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }

  // create a CGNS grid with x, y and z coordinates of all the nodes (that are
  // referenced by elements)
  int cgIndexGrid = 0;
  cgnsErr = cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                          "GridCoordinates", &cgIndexGrid);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // write list of coordinates
  int cgIndexCoord = 0;
  cgnsErr = cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                           CGNS_ENUMV(RealDouble), "CoordinateX", &xcoord[0],
                           &cgIndexCoord);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  cgnsErr = cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                           CGNS_ENUMV(RealDouble), "CoordinateY", &ycoord[0],
                           &cgIndexCoord);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  cgnsErr = cg_coord_write(cgIndexFile, cgIndexBase, cgIndexZone,
                           CGNS_ENUMV(RealDouble), "CoordinateZ", &zcoord[0],
                           &cgIndexCoord);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // write an element section for each entity, per element type
  cgsize_t eleStart = 0, eleEnd = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    // get entities
    GEntity *ge = entities[i];
    GEntity *geGeom = ge->getParentEntity();
    if(geGeom == nullptr) geGeom = ge;

    // get or create the names for the entity
    std::string entityName, geomEntityName;
    getNameFromEntity(ge, entityName);
    getNameFromEntity(geGeom, geomEntityName);
    geomEntities[geGeom] = geomEntityName;

    // retrieve element types for this geometric entity
    std::vector<int> eleTypes;
    ge->getElementTypes(eleTypes);

    // Range of element indices in entity (for BC)
    cgsize_t eleEntRange[2] = {eleEnd + 1, 0};

    // build list of connectivities
    for(std::size_t eleType = 0; eleType < eleTypes.size(); eleType++) {
      int numEle = ge->getNumMeshElementsByType(eleTypes[eleType]);
      if((numEle == 0) || ((ge->physicals.size() == 0) && (!saveAll))) continue;
      eleStart = eleEnd + 1;
      eleEnd += numEle;
      MElement *me = ge->getMeshElementByType(eleTypes[eleType], 0);
      int mshType = me->getTypeForMSH();
      CGNS_ENUMT(ElementType_t) cgType = msh2CgnsEltType(mshType);
      if(cgType == CGNS_ENUMV(ElementTypeNull)) {
        Msg::Error("Unhandled element type in CGNS ouput (%d)", mshType);
        break;
      }
      if(useCPEX0045) eleMshTypes.insert(mshType);
      std::vector<int> mshNodeInd = cgns2MshNodeIndex(mshType);

      // build connectivity for each element
      int numNodesPerEle = me->getNumVertices();
      std::vector<cgsize_t> elemNodes(numEle * numNodesPerEle);
      std::size_t n = 0;
      for(int j = 0; j < numEle; j++) {
        me = ge->getMeshElementByType(eleTypes[eleType], j);
        for(int k = 0; k < numNodesPerEle; k++) {
          const int kk = useCPEX0045 ? k : mshNodeInd[k];
          const int gInd = me->getVertex(kk)->getIndex();
          elemNodes[n] = global2Local[gInd].index;
          n++;
        }
      }

      // write section
      std::ostringstream ossSection;
      ossSection << eleTypes[eleType] << "_" << entityName;
      int cgIndexSection = 0;
      cgnsErr = cg_section_write(cgIndexFile, cgIndexBase, cgIndexZone,
                                 ossSection.str().c_str(), cgType, eleStart,
                                 eleEnd, 0, &elemNodes[0], &cgIndexSection);
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }

    // write elementary entity as BC and geometrical entity as BC family name
    eleEntRange[1] = eleEnd;
    int iZoneBC;
    cgnsErr = cg_boco_write(cgIndexFile, cgIndexBase, cgIndexZone,
                            entityName.c_str(), CGNS_ENUMV(FamilySpecified),
                            CGNS_ENUMV(PointRange), 2, eleEntRange, &iZoneBC);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    // GridLocation not clear: can "Vertex" be understood as "point" elements?
    // const CGNS_ENUMT(GridLocation_t) loc =
    //    (entDim == 2) ? CGNS_ENUMV(FaceCenter) :
    //    (entDim == 1) ? CGNS_ENUMV(EdgeCenter) :
    //    (entDim == 0) ? CGNS_ENUMV(Vertex) : CGNS_ENUMV(CellCenter);
    const CGNS_ENUMT(GridLocation_t) loc = CGNS_ENUMV(CellCenter);
    cgnsErr = cg_boco_gridlocation_write(cgIndexFile, cgIndexBase, cgIndexZone,
                                         iZoneBC, loc);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    cgnsErr = cg_goto(cgIndexFile, cgIndexBase, "Zone_t", cgIndexZone,
                      "ZoneBC_t", 1, "BC_t", iZoneBC, "end");
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    cgnsErr = cg_famname_write(geomEntityName.c_str());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }

  return 1;
}

// create periodic connections for all entities in all partitions
int writePeriodic(const std::vector<GEntity *> &entitiesPer, int cgIndexFile,
                  int cgIndexBase, const std::vector<std::string> &zoneName,
                  Vertex2LocalData &interfVert2Local)
{
  // Types for periodic connectivity
  typedef std::pair<GEntity *, GEntity *> EntityInterface;
  typedef std::pair<PartitionInterface, EntityInterface> PeriodicInterface;
  typedef std::map<PeriodicInterface, NodeCorrespondence> PeriodicConnection;

  // Construct interfaces [slave (entity, part.) <-> master (entity, part.)]
  // with corresponding nodes
  Msg::Info("Constructing connectivities for %i periodic entities",
            entitiesPer.size());
  PeriodicConnection connect;
  for(std::size_t iEnt = 0; iEnt < entitiesPer.size(); iEnt++) {
    GEntity *slaveEnt = entitiesPer[iEnt];
    GEntity *masterEnt = slaveEnt->getMeshMaster();
    auto &vv = slaveEnt->correspondingVertices;
    for(auto itV = vv.begin(); itV != vv.end(); itV++) {
      const std::vector<LocalData> &allSlaveData = interfVert2Local[itV->first];
      const std::vector<LocalData> &allMasterData =
        interfVert2Local[itV->second];
      for(std::size_t iS = 0; iS < allSlaveData.size(); iS++) {
        const LocalData &slaveData = allSlaveData[iS];
        for(std::size_t iM = 0; iM < allMasterData.size(); iM++) {
          const LocalData &masterData = allMasterData[iM];
          PartitionInterface partInt =
            std::make_pair(slaveData.partition, masterData.partition);
          EntityInterface entInt = std::make_pair(slaveEnt, masterEnt);
          PeriodicInterface perInt = std::make_pair(partInt, entInt);
          NodeCorrespondence &nc = connect[perInt];
          nc.first.push_back(slaveData.index);
          nc.second.push_back(masterData.index);
          PartitionInterface partInt2 =
            std::make_pair(masterData.partition, slaveData.partition);
          EntityInterface entInt2 = std::make_pair(masterEnt, slaveEnt);
          PeriodicInterface perInt2 = std::make_pair(partInt2, entInt2);
          NodeCorrespondence &nc2 = connect[perInt2];
          nc2.first.push_back(masterData.index);
          nc2.second.push_back(slaveData.index);
        }
      }
    }
  }

  // write periodic interfaces
  int cgnsErr;
  for(auto it = connect.begin(); it != connect.end(); ++it) {
    printProgress("Writing periodic interface",
                  std::distance(connect.begin(), it) + 1, connect.size());
    const PeriodicInterface &perInt = it->first;
    const PartitionInterface &partInt = perInt.first;
    const EntityInterface &entInt = perInt.second;
    const std::size_t &part1 = partInt.first;
    const GEntity *ent1 = entInt.first;
    const std::size_t &part2 = partInt.second;
    const GEntity *ent2 = entInt.second;
    const NodeCorrespondence &nc = it->second;
    const std::vector<cgsize_t> &nodes1 = nc.first;
    const std::vector<cgsize_t> &nodes2 = nc.second;
    int slaveZone = (part1 == 0) ? 1 : part1;
    const std::string &masterZoneName = zoneName[part2];
    std::ostringstream ossInt;
    ossInt << "Per_" << part1 << "-" << entTypeShortStr(ent1->dim())
           << ent1->tag() << "_" << part2 << "-" << entTypeShortStr(ent2->dim())
           << ent2->tag();
    const std::string interfaceName = cgnsString(ossInt.str());
    int connIdx;
    cgnsErr = cg_conn_write(
      cgIndexFile, cgIndexBase, slaveZone, interfaceName.c_str(),
      CGNS_ENUMV(Vertex), CGNS_ENUMV(Abutting1to1), CGNS_ENUMV(PointList),
      nodes1.size(), nodes1.data(), masterZoneName.c_str(),
      CGNS_ENUMV(Unstructured), CGNS_ENUMV(PointListDonor),
      CGNS_ENUMV(DataTypeNull), nodes2.size(), nodes2.data(), &connIdx);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    // get parameters from transformation (CGNS transfo = inverse Gmsh transfo)
    float rotCenter[3], rotAngle[3], trans[3];
    if(ent1->getMeshMaster() == ent2) {
      const std::vector<double> &perTransfo = ent1->affineTransform;
      getAffineTransformationParameters(perTransfo, rotCenter, rotAngle, trans);
      for(int i = 0; i < 3; i++) {
        rotAngle[i] = -rotAngle[i];
        trans[i] = -trans[i];
      }
    }
    else if(ent2->getMeshMaster() == ent1) {
      const std::vector<double> &perTransfo = ent2->affineTransform;
      getAffineTransformationParameters(perTransfo, rotCenter, rotAngle, trans);
    }
    else {
      Msg::Error("Error in periodic connection between entities %i (dim %i) "
                 "and %i (dim %i)",
                 ent1->tag(), ent1->dim(), ent2->tag(), ent2->dim());
      for(int i = 0; i < 3; i++) rotCenter[i] = 0.;
      for(int i = 0; i < 3; i++) rotAngle[i] = 0.;
      for(int i = 0; i < 3; i++) trans[i] = 0.;
    }
    cgnsErr = cg_conn_periodic_write(cgIndexFile, cgIndexBase, slaveZone,
                                     connIdx, rotCenter, rotAngle, trans);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }

  return 1;
}

// Get entities in each partition, except partition interfaces
void getEntitiesInPartitions(const std::vector<GEntity *> &entities,
                             std::vector<std::vector<GEntity *> > &entitiesPart)
{
  for(std::size_t j = 0; j < entities.size(); j++) {
    GEntity *ge = entities[j];
    const std::vector<int> *parts = nullptr;
    switch(ge->geomType()) {
    case GEntity::PartitionVolume: {
      partitionRegion *pr = static_cast<partitionRegion *>(ge);
      if(pr->getParentEntity()->dim() != pr->dim())
        continue; // Skip partition interfaces
      parts = &(pr->getPartitions());
    } break;
    case GEntity::PartitionSurface: {
      partitionFace *pf = static_cast<partitionFace *>(ge);
      if(pf->getParentEntity()->dim() != pf->dim())
        continue; // Skip partition interfaces
      parts = &(pf->getPartitions());
    } break;
    case GEntity::PartitionCurve: {
      partitionEdge *pe = static_cast<partitionEdge *>(ge);
      if(pe->getParentEntity()->dim() != pe->dim())
        continue; // Skip partition interfaces
      parts = &(pe->getPartitions());
    } break;
    case GEntity::PartitionPoint: {
      partitionVertex *pv = static_cast<partitionVertex *>(ge);
      if(pv->getParentEntity()->dim() != pv->dim())
        continue; // Skip partition interfaces
      parts = &(pv->getPartitions());
    } break;
    default: break;
    } // switch
    if(parts != nullptr) {
      for(std::size_t iPart = 0; iPart < parts->size(); iPart++) {
        entitiesPart[(*parts)[iPart]].push_back(ge);
      }
    }
  } // loop on entities
}

// create partition interfaces
int writeInterfaces(const std::vector<GEntity *> &entitiesInterf,
                    int cgIndexFile, int cgIndexBase,
                    const std::vector<std::string> &zoneName,
                    Vertex2LocalData &interfVert2Local)
{
  // type for partition connectivity
  typedef std::map<PartitionInterface, NodeCorrespondence> PartitionConnection;

  // get nodes in partition interface entities
  std::set<MVertex *> nodeSet;
  getNodesInEntities<false>(entitiesInterf, true, nodeSet);

  // construct (two-way) partition connectivities with corresponding nodes
  Msg::Info("Constructing connectivities for %i partition interface entities",
            entitiesInterf.size());
  PartitionConnection connect;
  for(auto itN = nodeSet.begin(); itN != nodeSet.end(); ++itN) {
    const std::vector<LocalData> &allLocalData = interfVert2Local[*itN];
    for(std::size_t iLD1 = 0; iLD1 < allLocalData.size(); iLD1++) {
      const LocalData &localData1 = allLocalData[iLD1];
      for(std::size_t iLD2 = 0; iLD2 < allLocalData.size(); iLD2++) {
        if(iLD2 == iLD1) continue;
        const LocalData &localData2 = allLocalData[iLD2];
        std::pair<unsigned int, unsigned int> partInt(localData1.partition,
                                                      localData2.partition);
        NodeCorrespondence &nc = connect[partInt];
        nc.first.push_back(localData1.index);
        nc.second.push_back(localData2.index);
      }
    }
  }

  // write partition interfaces
  int cgnsErr;
  std::size_t iPartConnect = 0;
  for(auto it = connect.begin(); it != connect.end(); ++it) {
    iPartConnect++;
    printProgress("Writing partition interface", iPartConnect, connect.size());
    const std::pair<unsigned int, unsigned int> &partInt = it->first;
    const std::size_t &part1 = partInt.first;
    const std::size_t &part2 = partInt.second;
    const NodeCorrespondence &nc = it->second;
    const std::string &masterZoneName = zoneName[part2];
    std::ostringstream ossInt;
    ossInt << "Part" << part1 << "_Part" << part2;
    const std::string interfaceName = cgnsString(ossInt.str());
    int dum;
    cgnsErr = cg_conn_write(
      cgIndexFile, cgIndexBase, part1, interfaceName.c_str(),
      CGNS_ENUMV(Vertex), CGNS_ENUMV(Abutting1to1), CGNS_ENUMV(PointList),
      nc.first.size(), nc.first.data(), masterZoneName.c_str(),
      CGNS_ENUMV(Unstructured), CGNS_ENUMV(PointListDonor),
      CGNS_ENUMV(DataTypeNull), nc.second.size(), nc.second.data(), &dum);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }

  return 1;
}

// write element high-orper point info according to CPEX0045 convention
int writeHOPointInfo(const std::set<int> &eleMshTypes, int cgIndexFile,
                     int cgIndexBase)
{
#ifdef HAVE_LIBCGNS_CPEX0045
  int cgnsErr;

  // Write family containing all node sets
  int cgIndexFam;
  cgnsErr = cg_family_write(cgIndexFile, cgIndexBase, INTERPOLATION_ZONE_NAME,
                            &cgIndexFam);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // write node sets for each element type
  for(auto it = eleMshTypes.begin(); it != eleMshTypes.end(); ++it) {
    // get node set
    const int mshType = *it;
    const nodalBasis *basis = BasisFactory::getNodalBasis(mshType);
    const fullMatrix<double> &mshPts = basis->getReferenceNodes();
    if(mshType == MSH_PNT) continue;

    // convert nodes to CGNS reference element if needed
    std::size_t nbPts = mshPts.size1();
    std::vector<double> u(nbPts), v(nbPts), w(nbPts);
    msh2CgnsReferenceElement(mshType, mshPts, u, v, w);

    // write nodal set
    CGNS_ENUMT(ElementType_t) cgnsType = msh2CgnsEltType(mshType);
    std::ostringstream ossInterp;
    ossInterp << "Element_" << cgnsType;
    std::string interpName = ossInterp.str();
    int indexInterp;
    cgnsErr = cg_element_interpolation_write(cgIndexFile, cgIndexBase,
                                             cgIndexFam, interpName.c_str(),
                                             cgnsType, &indexInterp);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    cgnsErr = cg_element_interpolation_points_write(
      cgIndexFile, cgIndexBase, cgIndexFam, indexInterp, u.data(), v.data(),
      w.data());
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  }

  return 1;
#else
  Msg::Error("Gmsh is not compiled with CGNS CPEX0045 capability");
  return 0;
#endif
}

int writeGeomEntities(std::map<GEntity *, std::string> &geomEntities,
                      int cgIndexFile, int cgIndexBase)
{
  int cgnsErr;

  for(auto it = geomEntities.begin(); it != geomEntities.end(); ++it) {
    // get geometric entity
    GEntity *ge = it->first;
    std::string &geomName = it->second;
    GModel *model = ge->model();

    // Write family containing all node sets
    int cgIndexFam;
    cgnsErr =
      cg_family_write(cgIndexFile, cgIndexBase, geomName.c_str(), &cgIndexFam);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

    // write physical tags or names
    std::vector<int> phys = ge->getPhysicalEntities();
    for(std::size_t iPhys = 0; iPhys < phys.size(); iPhys++) {
      // get name if exists, otherwise tag
      const int physTag = phys[iPhys];
      std::string physName = model->getPhysicalName(ge->dim(), physTag);
      if(physName == "") {
        std::ostringstream oss;
        oss << physTag;
        physName = cgnsString(oss.str());
      }

      // write to family name
      cgnsErr = cg_family_name_write(cgIndexFile, cgIndexBase, cgIndexFam,
                                     physName.c_str(), physName.c_str());
      if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
    }
  }

  return 1;
}

#endif // HAVE_LIBCGNS
