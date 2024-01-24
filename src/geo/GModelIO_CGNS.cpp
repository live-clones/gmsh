// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include "Context.h"
#include "GModel.h"
#include "CGNSCommon.h"
#include "CGNSConventions.h"
#include "CGNSWrite.h"
#include "CGNSWriteStruct.h"
#include "CGNSZone.h"
#include "CGNSZoneStruct.h"
#include "CGNSZoneUnstruct.h"
#include "CGNSRead.h"

// The CGNS specifications are by design very flexible, which means that the
// same information can be represented in many different ways in a CGNS file. As
// a consequence, different CGNS-compatible software packages often interpret
// CGNS files based on different conventions.

// Unstructured meshes (CGNS{Read,Write}.cpp)
// ==========================================

// With this in mind and considering the constraints of CGNS, the unstructured
// CGNS writer in Gmsh is designed to export as much information from Gmsh as
// possible, without perverting the original purpose of the various CGNS data
// structures. The most difficult point is the classification of mesh entities
// on geometrical (CAD) entities. This is the convention used for the
// unstructured CGNS writer:
//
// - One family per geometrical entity, with the name [Letter]_[Number], where
//   the letter refers to the dimension of the geometrical entity (P for a
//   point, L for a line/curve, S for a surface and V for a volume), and the
//   number is the ID identifying uniquely the geometrical entity. If the
//   geometrical entity has a name ("elementary name"), it is appended:
//   [Letter]_[Number]_[Name]

// - If physical groups are defined, a nested family name identifies the
//   physical group: by name if a name is given, or by the physical tag
//   otherwise. If physical groups are defined, only those geometrical entities
//   belonging to physical groups are saved, unless Mesh.SaveAll is set.
//
// - One BC for each geometrical entity, with the same name as the corresponding
//   family.
//
// - One "Elements" structure for each type of element in each geometric entity.
//
// - One zone per mesh partition. Interfaces between partitions are defined by
//   point lists.
//
// Using these conventions we can convey a certain level of topological
// information across a CGNS-based simulation chain, and we manage in most cases
// to re-open with Gmsh a CGNS file that it created and find the same
// information.

// Structured meshes (CGNSWriteStruct.cpp)
// =======================================

// The structured CGNS writer follows ICEM-like conventions, which are
// significantly different from those used in the unstructured CGNS writer:
//
// - Structured 3D (resp. 2D) meshes contain one zone per volume (resp.
//   surface) and no zones are created for lower dimensional entities.
//
// - All structured volumes (3D) or surfaces (2D) are saved; it is not possible
//   to only save those belonging to physical groups.
//
// - Interfaces between structured zones are defined by point ranges.
//
// - Elementary entity tags are encoded in the zone name.
//
// - Physical groups for the highest dimensional entities are directly encoded
//   at the begining of the zone name.
//
// - Boundary conditions are created for all zone boundaries, and if physical
//   groups are defined on boundaries they are also saved as families.

#if defined(HAVE_LIBCGNS)

int GModel::readCGNS(const std::string &name,
                     std::vector<std::vector<MVertex *> > &vertPerZone,
                     std::vector<std::vector<MElement *> > &eltPerZone)
{
  int cgnsErr;

  // open CGNS file and read scale
  int fileIndex = 0;
  cgnsErr = cg_open(name.c_str(), CG_MODE_READ, &fileIndex);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read base node
  const int baseIndex = 1;
  int dim = 0, meshDim = 0;
  char baseName[CGNS_MAX_STR_LEN];
  cgnsErr = cg_base_read(fileIndex, baseIndex, baseName, &meshDim, &dim);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // read scale
  double scale;
  int scaleErr = readScale(fileIndex, baseIndex, scale);
  if(scaleErr == 0) return 0;

  // per-element node transformation for CPEX0045
  Family2EltNodeTransfo allEltNodeTransfo;
  readEltNodeTransfo(fileIndex, baseIndex, allEltNodeTransfo);

  // define names of geometrical entities
  // index start at 1 with empty name to account for unclassified elements
  std::vector<std::string> allGeomName(2, "");

  // read number of zones (allZones[0] is dummy because index starts at 1)
  int nbZone = 0;
  cgnsErr = cg_nzones(fileIndex, baseIndex, &nbZone);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, fileIndex);

  // create all zones by reading basic info
  std::vector<CGNSZone *> allZones(nbZone + 1);
  std::map<std::string, int> name2Zone;
  bool postpro;
  createZones(fileIndex, baseIndex, meshDim, allEltNodeTransfo, allZones,
              name2Zone, postpro);

  // data structures for element and vertices
  std::vector<MVertex *> allVert; // all vertices
  std::map<int, std::vector<MElement *> > allElt[10]; // all elements by type

  // vertex and element (global) tags per zone for postpro
  vertPerZone.resize(nbZone + 1);
  eltPerZone.resize(nbZone + 1);

  // read mesh in zones
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    CGNSZone *zone = allZones[iZone];
    int err =
      zone->readMesh(dim, scale, allZones, allVert, allElt, vertPerZone[iZone],
                     eltPerZone[iZone], allGeomName);
    if((!postpro) || (CTX::instance()->mesh.cgnsImportIgnoreSolution != 0)) {
      vertPerZone[iZone].clear();
      eltPerZone[iZone].clear();
    }
    if(err == 0) return 0;
  }

  // set periodic vertices in each zone
  for(int iZone = 1; iZone <= nbZone; iZone++) {
    allZones[iZone]->setPeriodicVertices(allZones, allVert);
  }

  // get physical names, index start at 1
  std::multimap<std::string, int> geomName2Phys;
  std::vector<std::string> allPhysName(1, "");
  int errPhys = readPhysicals(fileIndex, baseIndex, allPhysName, geomName2Phys);
  if(errPhys == 0) return 0;

  // close file
  cgnsErr = cg_close(fileIndex);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

  // populate data structures with elements and vertices
  for(int i = 0; i < 10; i++) _storeElementsInEntities(allElt[i]);
  _associateEntityWithMeshVertices();
  _storeVerticesInEntities(allVert);

  // add periodic vertex correspondence and affine transformation
  setPeriodicityInEntities(allZones);

  // remove potential duplicate vertices if several zones (keeping vertices
  // classified on entities of lowest dimension)
  // TODO: disable this through option ?
  if(nbZone > 1) removeDuplicateMeshVertices(CTX::instance()->geom.tolerance);

  // set names of geometric entities and physical names
  setGeomAndPhysicalEntities(this, meshDim, allGeomName, allPhysName,
                             geomName2Phys);
  // destroy all zones
  for(std::size_t iZone = 0; iZone < allZones.size(); iZone++) {
    if(allZones[iZone] != nullptr) delete allZones[iZone];
  }

  // reconstruct geometrical topology if required
  if(CTX::instance()->mesh.cgnsConstructTopology) createTopologyFromMesh();

  return postpro ? 2 : 1;
}

int GModel::writeCGNS(const std::string &name, bool saveAll,
                      double scalingFactor, bool structured)
{
  int cgnsErr;

  int cgIndexFile = 0;
  cgnsErr = cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // write the base node
  int meshDim = getMeshDim(), dim = 3, cgIndexBase = 0;
  size_t posStartName = name.find_last_of("/\\");
  if(posStartName == std::string::npos)
    posStartName = 0;
  else
    posStartName++;
  std::string baseName = cgnsString(name.substr(posStartName));
  cgnsErr =
    cg_base_write(cgIndexFile, baseName.c_str(), meshDim, dim, &cgIndexBase);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // write information about who generated the mesh
  cgnsErr = cg_goto(cgIndexFile, cgIndexBase, "end");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);
  cgnsErr = cg_descriptor_write("About", "Created by Gmsh");
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__, cgIndexFile);

  // try to write as structured grid (if it fails, write as unstructured)
  if(structured &&
     writeZonesStruct(this, scalingFactor, cgIndexFile, cgIndexBase)) {
    cgnsErr = cg_close(cgIndexFile);
    if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);
    return 1;
  }

  // zone names
  const size_t numPart = getNumPartitions();
  std::vector<std::string> zoneName(numPart + 1);

  // index mesh nodes, as CGNS does not store node tags
  if(noPhysicalGroups()) saveAll = true;
  const size_t numNodes = indexMeshVertices(saveAll);

  // get entities from model
  std::vector<GEntity *> allEntities, entities, entitiesPer, entitiesInterf;
  getEntities(allEntities);
  getEntitiesToSave(allEntities, saveAll, entities);
  getPeriodicEntities(allEntities, entitiesPer);
  if(numPart > 0) {
    getPartitionInterfaceEntities(allEntities, saveAll, entitiesInterf);
    if(entitiesInterf.size() == 0) {
      Msg::Warning("Partitioned entities not detected");
    }
  }

  // initialize vertex -> (partition, local node index) for periodic and
  // interface entities
  Vertex2LocalData interfVert2Local;
  initInterfVertex2LocalData(entitiesPer, entitiesInterf, interfVert2Local);
  Msg::Info("%lu periodic/interface nodes", interfVert2Local.size());

  // write partitions and periodic/partition connectivities
  std::set<int> eleMshTypes;
  std::map<GEntity *, std::string> geomEntities;
  if(numPart == 0) { // mesh not partitioned
    int err = writeZone(this, saveAll, scalingFactor, meshDim, numNodes, 0,
                        entities, cgIndexFile, cgIndexBase, zoneName,
                        interfVert2Local, eleMshTypes, geomEntities);
    if(err == 0) return 0;
    if(entitiesPer.size() > 0) {
      err = writePeriodic(entitiesPer, cgIndexFile, cgIndexBase, zoneName,
                          interfVert2Local);
      if(err == 0) return 0;
    }
  }
  else { // partitioned mesh
    std::vector<std::vector<GEntity *> > entitiesPart;
    entitiesPart.resize(numPart + 1);
    getEntitiesInPartitions(entities, entitiesPart);
    for(std::size_t iPart = 1; iPart <= numPart; iPart++) {
      printProgress("Writing partition", iPart, numPart);
      int err =
        writeZone(this, saveAll, scalingFactor, meshDim, numNodes, iPart,
                  entitiesPart[iPart], cgIndexFile, cgIndexBase, zoneName,
                  interfVert2Local, eleMshTypes, geomEntities);
      if(err == 0) return 0;
    } // loop on partitions
    if(entitiesPer.size() > 0) {
      int err = writePeriodic(entitiesPer, cgIndexFile, cgIndexBase, zoneName,
                              interfVert2Local);
      if(err == 0) return 0;
    }
    if(entitiesInterf.size() > 0) {
      int err = writeInterfaces(entitiesInterf, cgIndexFile, cgIndexBase,
                                zoneName, interfVert2Local);
      if(err == 0) return 0;
    }
  } // numPart == 0

  // write geometric entities in families
  if(geomEntities.size() > 0) {
    writeGeomEntities(geomEntities, cgIndexFile, cgIndexBase);
  }

  // write element high-orper point info for CPEX0045 if required
  if(CTX::instance()->mesh.cgnsExportCPEX0045) {
    int err = writeHOPointInfo(eleMshTypes, cgIndexFile, cgIndexBase);
    if(err == 0) return 0;
  }

  cgnsErr = cg_close(cgIndexFile);
  if(cgnsErr != CG_OK) return cgnsError(__FILE__, __LINE__);

  return 1;
}

#else

int GModel::readCGNS(const std::string &name,
                     std::vector<std::vector<MVertex *> > &vertPerZone,
                     std::vector<std::vector<MElement *> > &eltPerZone)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

int GModel::writeCGNS(const std::string &name, bool saveAll,
                      double scalingFactor, bool structured)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

#endif
