// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"

#if defined(HAVE_LIBCGNS)

#include <string>
#include "GmshMessage.h"
#include "GModel.h"

namespace CGNS {
#include <cgnslib.h>
}

#if CGNS_VERSION < 3100
#warning "OOOOOLDDD!"
#define cgsize_t int
#endif

#ifndef CGNSTYPES_H
#warning "we don't have CGNSTYPES_H"
#define CGNS::cgsize_t int
#endif
#ifndef CGNS_ENUMT
#defome CGNS_ENUMT(e) e
#defome CGNS_ENUMV(e) e
#endif

static int cgnsError(const int cgIndexFile = -1)
{
  Msg::Error("Error detected by CGNS library");
  Msg::Error(CGNS::cg_get_error());
  if(cgIndexFile != -1) {
    if(CGNS::cg_close(cgIndexFile)) { Msg::Error("Unable to close CGNS file"); }
  }
  return 0;
}

static const CGNS::ElementType_t msh2cgns[] = {
  CGNS::BAR_2,    CGNS::TRI_3,   CGNS::QUAD_4,   CGNS::TETRA_4, CGNS::HEXA_8,
  CGNS::PENTA_6,  CGNS::PYRA_5,  CGNS::BAR_3,    CGNS::TRI_6,   CGNS::QUAD_9,
  CGNS::TETRA_10, CGNS::HEXA_27, CGNS::PENTA_18, CGNS::PYRA_14, CGNS::NODE,
  CGNS::QUAD_8,   CGNS::HEXA_20, CGNS::PENTA_15};

int GModel::readCGNS(const std::string &name) { return 0; }

int GModel::writeCGNS(const std::string &name, bool saveAll, double scalingFactor)
{
  int cgIndexFile = 0;
  if(CGNS::cg_open(name.c_str(), CG_MODE_WRITE, &cgIndexFile))
    return cgnsError();

  // write the base node
  int meshDim = getMeshDim(), dim = getDim(), cgIndexBase = 0;
  if(CGNS::cg_base_write(cgIndexFile, name.c_str(), meshDim, dim, &cgIndexBase))
    return cgnsError();

  // write information about who generated the mesh
  if(CGNS::cg_goto(cgIndexFile, cgIndexBase, "end")) return cgnsError();

  if(CGNS::cg_descriptor_write("About", "Created by Gmsh")) return cgnsError();

  // index mesh nodes, as CGNS does not store node tags
  if(noPhysicalGroups()) saveAll = true;
  CGNS::cgsize_t numNodes = indexMeshVertices(saveAll);

  // get all entities from model
  std::vector<GEntity *> entities;
  getEntities(entities);

  // create a single zone for the whole unstructured mesh; nodes and elements
  // are referenced with per-zone index (starting at 1) inside a zone
  int cgIndexZone = 0;
  CGNS::cgsize_t numElementsMaxDim = 0;
  for(std::size_t i = 0; i < entities.size(); i++){
    GEntity *ge = entities[i];
    if(ge->dim() == meshDim && (saveAll || ge->physicals.size())) {
      numElementsMaxDim += ge->getNumMeshElements();
    }
  }
  CGNS::cgsize_t cgZoneSize[3] = {numNodes, numElementsMaxDim, 0};
  if(CGNS::cg_zone_write(cgIndexFile, cgIndexBase, getName().c_str(),
                         cgZoneSize, CGNS::Unstructured, &cgIndexZone))
    return cgnsError();

  // create a grid with x, y and z coordinates of all nodes (that are reference
  // by elements)
  int cgIndexGrid = 0;
  if(CGNS::cg_grid_write(cgIndexFile, cgIndexBase, cgIndexZone,
                         "GridCoordinates", &cgIndexGrid))
    return cgnsError();

  std::vector<double> xcoord(numNodes), ycoord(numNodes), zcoord(numNodes);
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];
    for(std::size_t j = 0; j < ge->getNumMeshVertices(); j++) {
      MVertex *mv = ge->getMeshVertex(j);
      if(mv->getIndex() < 0) continue;
      std::size_t n = mv->getIndex();
      if(n > numNodes) {
        Msg::Error("Incoherent mesh node indexing in CGNS output");
        return 0;
      }
      xcoord[n - 1] = mv->x() * scalingFactor;
      ycoord[n - 1] = mv->y() * scalingFactor;
      zcoord[n - 1] = mv->z() * scalingFactor;
    }
  }

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

  // write an element section for each entity, per element type (TODO? check if
  // using the actual element tag in case the numbering is dense and
  // saveAll==true would make sense/would be useful - think in the context of
  // partitioned meshes)
  CGNS::cgsize_t eleStart = 0, eleEnd = 0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *ge = entities[i];

    // FIXME:
    // 1) find better name (and investigate if using MIXED sections for
    //    hybrid meshes would be a good idea)
    // 2) store physical information in Family_t?
    std::string name = getElementaryName(ge->dim(), ge->tag());
    if(name.empty()) {
      std::ostringstream s;
      s << "Gmsh entity (" << ge->dim() << "," << ge->tag() << ")";
      name = s.str();
    }

    std::vector<int> eleTypes;
    ge->getElementTypes(eleTypes);

    for(std::size_t eleType = 0; eleType < eleTypes.size(); eleType++) {
      int numEle = ge->getNumMeshElementsByType(eleTypes[eleType]);
      if(numEle && (saveAll || ge->physicals.size())) {
        eleStart = (eleEnd + 1);
        eleEnd += numEle;
        MElement *me = ge->getMeshElementByType(eleTypes[eleType], 0);
        int mshType = me->getTypeForMSH();
        if(mshType - 1 < sizeof(msh2cgns) / sizeof(msh2cgns[0])) {
          CGNS::ElementType_t cgType = msh2cgns[mshType - 1];
          int numNodesPerEle = me->getNumVertices();
          std::vector<CGNS::cgsize_t> elemNodes(numEle * numNodesPerEle);
          std::size_t n = 0;
          for(std::size_t j = 0; j < numEle; j++) {
            me = ge->getMeshElementByType(eleTypes[eleType], j);
            for(std::size_t k = 0; k < numNodesPerEle; k++) {
              elemNodes[n++] = me->getVertex(k)->getIndex();
            }
          }
          int cgIndexSection = 0;
          if(CGNS::cg_section_write(cgIndexFile, cgIndexBase, cgIndexZone,
                                    name.c_str(), cgType, eleStart, eleEnd, 0,
                                    &elemNodes[0], &cgIndexSection))
            return cgnsError();
        }
        else{
          Msg::Error("Unhandled element type in CGNS ouput (%d)", mshType);
          break;
        }
      }
    }
  }

  if(CGNS::cg_close(cgIndexFile)) return cgnsError();

  return 0;
}

#else

int GModel::readCGNS(const std::string &name)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

int GModel::writeCGNS(const std::string &name, double scalingFactor)
{
  Msg::Error("This version of Gmsh was compiled without CGNS support");
  return 0;
}

#endif
