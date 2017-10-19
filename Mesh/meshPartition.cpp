// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Partition.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>

#include "GmshConfig.h"
#include "meshPartition.h"
#include "meshPartitionOptions.h"

#if defined(HAVE_METIS)

#include "GModel.h"
#include "meshPartitionObjects.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MTrihedron.h"
#include "MElementCut.h"
#include "MPoint.h"
#include "GFaceCompound.h"

//--Prototypes for METIS

extern "C" {
#include <metis.h>
}

/*******************************************************************************
 *
 * Routine PartitionMesh
 *
 * Purpose
 * =======
 *
 *   Partition a mesh into n parts.
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        0 = success
 *                        1 = error
 *
 *
 ******************************************************************************/

int PartitionMesh(GModel *const model, meshPartitionOptions &options)
{
  clock_t t;
  t = clock();
  
  Graph graph;
  Msg::StatusBar(true, "Building mesh graph...");
  int ier = MakeGraph(model, graph);
  Msg::StatusBar(true, "Partitioning graph...");
  if(!ier) ier = PartitionGraph(graph, options);
  if(ier) return 1;
  
  // Assign partitions to elements
  std::unordered_map<MElement*, short> elmToPartition;
  for(unsigned int i = 0; i < graph.ne(); i++)
  {
    if(graph.element(i) != NULL)
    {
      elmToPartition.insert(std::pair<MElement*, short>(graph.element(i), graph.partition(i)+1));
      graph.element(i)->setPartition(graph.partition(i)+1);
    }
  }
  graph.clear();
  model->recomputeMeshPartitions();
  
  Msg::StatusBar(true, "Create new entities...");
  std::multimap<int, GEntity*> newPartitionEntities;
  CreateNewEntities(model, elmToPartition, newPartitionEntities, options);
  elmToPartition.clear();
  
  std::multimap<int, GEntity*> newPartitionBoundaries;
  if(options.createPartitionBoundaries || options.createGhostCells)
  {
    Msg::StatusBar(true, "Create boundaries...");
    CreatePartitionBoundaries(model, newPartitionBoundaries, options.createGhostCells);
  }
  
  if(options.writeTopologyFile)
  {
    Msg::StatusBar(true, "Write the topology file...");
    CreateTopologyFile(model, options.num_partitions);
  }
  
  if(options.writePartitionMeshes)
  {
    Msg::StatusBar(true, "Write partition meshes...");
    for(int i = 0; i < options.num_partitions; i++)
    {
      GModel *tmp = new GModel();
      for(GModel::piter it = model->firstPhysicalName(); it != model->lastPhysicalName(); ++it)
      {
        tmp->setPhysicalName(it->second, it->first.first, it->first.second);
      }
    
      std::vector<GEntity*> entities;
      model->getEntities(entities);
      for(unsigned int i = 0; i < entities.size(); i++)
      {
        if(entities[i]->geomType() != GEntity::PartitionVolume && entities[i]->geomType() != GEntity::PartitionSurface && entities[i]->geomType() != GEntity::PartitionCurve && entities[i]->geomType() != GEntity::PartitionVertex)
        {
          switch(entities[i]->dim())
          {
            case 0:
            tmp->add(static_cast<GVertex*>(entities[i]));
            break;
            case 1:
            tmp->add(static_cast<GEdge*>(entities[i]));
            break;
            case 2:
            tmp->add(static_cast<GFace*>(entities[i]));
            break;
            case 3:
            tmp->add(static_cast<GRegion*>(entities[i]));
            break;
          }
        }
      }
    
      for(std::multimap<int, GEntity*>::const_iterator it = newPartitionEntities.begin(); it != newPartitionEntities.end(); ++it)
      {
        if(it->first == i)
        {
          switch(it->second->dim())
          {
            case 0:
              tmp->add(static_cast<GVertex*>(it->second));
              break;
            case 1:
              tmp->add(static_cast<GEdge*>(it->second));
              break;
            case 2:
              tmp->add(static_cast<GFace*>(it->second));
              break;
            case 3:
              tmp->add(static_cast<GRegion*>(it->second));
              break;
          }
        }
      }
    
      for(std::multimap<int, GEntity*>::const_iterator it = newPartitionBoundaries.begin(); it != newPartitionBoundaries.end(); ++it)
      {
        if(it->first == i)
        {
          switch(it->second->dim())
          {
            case 0:
              tmp->add(static_cast<GVertex*>(it->second));
              break;
            case 1:
              tmp->add(static_cast<GEdge*>(it->second));
              break;
            case 2:
              tmp->add(static_cast<GFace*>(it->second));
              break;
          }
        }
      }
    
      AssignMeshVertices(tmp);
        
      std::ostringstream name;
      name << "mesh_" << i << ".msh";
      tmp->writeMSH(name.str().c_str(), 3, false, true);
    
      tmp->remove();
      delete tmp;
    }
  }
  
  AssignMeshVertices(model);
  t = clock() - t;
  Msg::StatusBar(true, "Done partitioning graph in %f seconds", ((float)t)/CLOCKS_PER_SEC);
  return 0;
}

/*******************************************************************************
 *
 * Routine UnpartitionMesh
 *
 * Purpose
 * =======
 *
 *   Un partition a mesh and return to the initial mesh geomerty
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        0 = success
 *                        1 = error
 *
 *
 ******************************************************************************/

int UnpartitionMesh(GModel *const model)
{
  std::set<GRegion*, GEntityLessThan> regions = model->getGRegions();
  std::set<GFace*, GEntityLessThan> faces = model->getGFaces();
  std::set<GEdge*, GEntityLessThan> edges = model->getGEdges();
  std::set<GVertex*, GEntityLessThan> vertices = model->getGVertices();
  
  std::set<MVertex*> verts;
  
  //Loop over vertices
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    GVertex *vertex = *it;
    
    if(vertex->geomType() == GEntity::PartitionVertex)
    {
      partitionVertex* pvertex = static_cast<partitionVertex*>(vertex);
      if(pvertex->getParentEntity() != NULL)
      {
        assignToParent(verts, pvertex, pvertex->points.begin(), pvertex->points.end());
      }
      else
      {
        for(unsigned int j = 0; j < pvertex->points.size(); j++)
          delete pvertex->points[j];
      }
      pvertex->points.clear();
      pvertex->mesh_vertices.clear();
      
      model->remove(pvertex);
      delete pvertex;
    }
  }
  
  //Loop over edges
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it)
  {
    GEdge *edge = *it;
    
    if(edge->geomType() == GEntity::PartitionCurve)
    {
      partitionEdge* pedge = static_cast<partitionEdge*>(edge);
      if(pedge->getParentEntity() != NULL)
      {
        assignToParent(verts, pedge, pedge->lines.begin(), pedge->lines.end());
      }
      else
      {
        for(unsigned int j = 0; j < pedge->lines.size(); j++)
          delete pedge->lines[j];
      }
      pedge->lines.clear();
      pedge->mesh_vertices.clear();
      
      model->remove(pedge);
      delete pedge;
    }
  }
  
  //Loop over faces
  for(GModel::fiter it = faces.begin(); it != faces.end(); ++it)
  {
    GFace *face = *it;
    
    if(face->geomType() == GEntity::PartitionSurface)
    {
      partitionFace* pface = static_cast<partitionFace*>(face);
      if(pface->getParentEntity() != NULL)
      {
        assignToParent(verts, pface, pface->triangles.begin(), pface->triangles.end());
        assignToParent(verts, pface, pface->quadrangles.begin(), pface->quadrangles.end());
        assignToParent(verts, pface, pface->polygons.begin(), pface->polygons.end());
      }
      else
      {
        for(unsigned int j = 0; j < pface->triangles.size(); j++)
          delete pface->triangles[j];
        
        for(unsigned int j = 0; j < pface->quadrangles.size(); j++)
          delete pface->quadrangles[j];
        
        for(unsigned int j = 0; j < pface->polygons.size(); j++)
          delete pface->polygons[j];
      }
      pface->triangles.clear();
      pface->quadrangles.clear();
      pface->polygons.clear();
      pface->mesh_vertices.clear();
      
      model->remove(pface);
      delete pface;
    }
  }
  
  //Loop over regions
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it)
  {
    GRegion *region = *it;
    
    if(region->geomType() == GEntity::PartitionVolume)
    {
      partitionRegion* pregion = static_cast<partitionRegion*>(region);
      if(pregion->getParentEntity() != NULL)
      {
        assignToParent(verts, pregion, pregion->tetrahedra.begin(), pregion->tetrahedra.end());
        assignToParent(verts, pregion, pregion->hexahedra.begin(), pregion->hexahedra.end());
        assignToParent(verts, pregion, pregion->prisms.begin(), pregion->prisms.end());
        assignToParent(verts, pregion, pregion->pyramids.begin(), pregion->pyramids.end());
        assignToParent(verts, pregion, pregion->trihedra.begin(), pregion->trihedra.end());
        assignToParent(verts, pregion, pregion->polyhedra.begin(), pregion->polyhedra.end());
      }
      else
      {
        for(unsigned int j = 0; j < pregion->tetrahedra.size(); j++)
          delete pregion->tetrahedra[j];
        
        for(unsigned int j = 0; j < pregion->hexahedra.size(); j++)
          delete pregion->hexahedra[j];
        
        for(unsigned int j = 0; j < pregion->prisms.size(); j++)
          delete pregion->prisms[j];
        
        for(unsigned int j = 0; j < pregion->pyramids.size(); j++)
          delete pregion->pyramids[j];
        
        for(unsigned int j = 0; j < pregion->trihedra.size(); j++)
          delete pregion->trihedra[j];
        
        for(unsigned int j = 0; j < pregion->polyhedra.size(); j++)
          delete pregion->polyhedra[j];
      }
      pregion->tetrahedra.clear();
      pregion->hexahedra.clear();
      pregion->prisms.clear();
      pregion->pyramids.clear();
      pregion->trihedra.clear();
      pregion->polyhedra.clear();
      pregion->mesh_vertices.clear();
      
      model->remove(pregion);
      delete pregion;
    }
  }
  
  model->recomputeMeshPartitions();
  
  std::map<std::pair<int, int>, std::string> physicalNames = model->getAllPhysical();
  for(GModel::piter it = physicalNames.begin(); it != physicalNames.end(); ++it)
  {
    std::string name = it->second;
    
    if(name[0] == '_')
    {
      model->erasePhysicalGroup(it->first.first, it->first.second);
    }
  }
  
  return 0;
}

template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionRegion *region, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    region->getParentEntity()->addElement((*it)->getType(), *it);
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      if(verts.find((*it)->getVertex(i)) == verts.end())
      {
        (*it)->getVertex(i)->setEntity(region->getParentEntity());
        region->getParentEntity()->addMeshVertex((*it)->getVertex(i));
        verts.insert((*it)->getVertex(i));
      }
    }
  }
}

template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionFace *face, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    face->getParentEntity()->addElement((*it)->getType(), *it);
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      if(verts.find((*it)->getVertex(i)) == verts.end())
      {
        (*it)->getVertex(i)->setEntity(face->getParentEntity());
        face->getParentEntity()->addMeshVertex((*it)->getVertex(i));
        verts.insert((*it)->getVertex(i));
      }
    }
  }
}

template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionEdge *edge, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    edge->getParentEntity()->addLine(reinterpret_cast<MLine*>(*it));
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      if(verts.find((*it)->getVertex(i)) == verts.end())
      {
        (*it)->getVertex(i)->setEntity(edge->getParentEntity());
        edge->getParentEntity()->addMeshVertex((*it)->getVertex(i));
        verts.insert((*it)->getVertex(i));
      }
    }
  }
}

template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionVertex *vertex, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    vertex->getParentEntity()->addPoint(reinterpret_cast<MPoint*>(*it));
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      if(verts.find((*it)->getVertex(i)) == verts.end())
      {
        (*it)->getVertex(i)->setEntity(vertex->getParentEntity());
        vertex->getParentEntity()->addMeshVertex((*it)->getVertex(i));
        verts.insert((*it)->getVertex(i));
      }
    }
  }
}

/*******************************************************************************
 *
 * Routine MakeGraph
 *
 * Purpose
 * =======
 *
 *   Creates a mesh data structure used by Metis routines.
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        0 = success
 *                        1 = no elements found
 *                        2 = error
 *
 ******************************************************************************/

int MakeGraph(GModel *const model, Graph &graph)
{
  const int numOfPeriodicLink = getNumPeriodicLink(model);
  graph.ne(model->getNumMeshElements() + numOfPeriodicLink);
  graph.nn(model->getNumMeshVertices());
  graph.dim(model->getDim());
  graph.elementResize(graph.ne());
  graph.eptrResize(graph.ne()+1);
  graph.eptr(0,0);
  graph.eindResize(getSizeOfEind(model) + 2*numOfPeriodicLink);
  
  int eptrIndex = 0;
  int eindIndex = 0;
  
  if(graph.ne() == 0)
  {
    Msg::Error("No mesh elements were found");
    return 1;
  }
  if(graph.dim() == 0)
  {
    Msg::Error("Cannot partition a point");
    return 1;
  }
  
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    const GRegion *r = *it;
    
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, r->tetrahedra.begin(), r->tetrahedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, r->hexahedra.begin(), r->hexahedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, r->prisms.begin(), r->prisms.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, r->pyramids.begin(), r->pyramids.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, r->trihedra.begin(), r->trihedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, r->polyhedra.begin(), r->polyhedra.end());
    
    //Take into account the periodic node in the graph
    if(r->correspondingVertices.size() != 0)
    {
      for(std::map<MVertex*, MVertex*>::const_iterator itP = r->correspondingVertices.begin(); itP != r->correspondingVertices.end(); ++itP)
      {
        graph.element(eptrIndex, NULL);
        eptrIndex++;
        graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + 2);
        graph.eind(eindIndex, itP->first->getNum()-1);
        graph.eind(eindIndex+1, itP->second->getNum()-1);
        eindIndex += 2;
      }
    }
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    const GFace *f = *it;
    
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, f->triangles.begin(), f->triangles.end());
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, f->quadrangles.begin(), f->quadrangles.end());
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, f->polygons.begin(), f->polygons.end());
    
    //Take into account the periodic node in the graph
    if(f->correspondingVertices.size() != 0)
    {
      for(std::map<MVertex*, MVertex*>::const_iterator itP = f->correspondingVertices.begin(); itP != f->correspondingVertices.end(); ++itP)
      {
        graph.element(eptrIndex, NULL);
        eptrIndex++;
        graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + 2);
        graph.eind(eindIndex, itP->first->getNum()-1);
        graph.eind(eindIndex+1, itP->second->getNum()-1);
        eindIndex += 2;
      }
    }
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    const GEdge *e = *it;
    
    fillElementsToNodesMap(graph, e, eptrIndex, eindIndex, e->lines.begin(), e->lines.end());
    
    //Take into account the periodic node in the graph
    if(e->correspondingVertices.size() != 0)
    {
      for(std::map<MVertex*, MVertex*>::const_iterator itP = e->correspondingVertices.begin(); itP != e->correspondingVertices.end(); ++itP)
      {
        graph.element(eptrIndex, NULL);
        eptrIndex++;
        graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + 2);
        graph.eind(eindIndex, itP->first->getNum()-1);
        graph.eind(eindIndex+1, itP->second->getNum()-1);
        eindIndex += 2;
      }
    }
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    GVertex *v = *it;
    
    fillElementsToNodesMap(graph, v, eptrIndex, eindIndex, v->points.begin(), v->points.end());
    
    //Take into account the periodic node in the graph
    if(v->correspondingVertices.size() != 0)
    {
      for(std::map<MVertex*, MVertex*>::const_iterator itP = v->correspondingVertices.begin(); itP != v->correspondingVertices.end(); ++itP)
      {
        graph.element(eptrIndex, NULL);
        eptrIndex++;
        graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + 2);
        graph.eind(eindIndex, itP->first->getNum()-1);
        graph.eind(eindIndex+1, itP->second->getNum()-1);
        eindIndex += 2;
      }
    }
  }
  
  return 0;
}

template <class ITERATOR>
void fillElementsToNodesMap(Graph &graph, const GEntity *const entity, int &eptrIndex, int &eindIndex, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int numVertices = getNumVertices(*it);
    graph.element(eptrIndex, *it);
    eptrIndex++;
    graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + numVertices);
    for(int i = 0; i < numVertices; i++)
    {
      graph.eind(eindIndex, (*it)->getVertex(i)->getNum()-1);
      eindIndex++;
    }
  }
}

int getSizeOfEind(const GModel *const model)
{
  int size = 0;
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    size += 4*(*it)->tetrahedra.size();
    size += 8*(*it)->hexahedra.size();
    size += 6*(*it)->prisms.size();
    size += 5*(*it)->pyramids.size();
    size += 4*(*it)->trihedra.size();
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    size += 3*(*it)->triangles.size();
    size += 4*(*it)->quadrangles.size();
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    size += 2*(*it)->lines.size();
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    size += 1*(*it)->points.size();
  }
  
  return size;
}

int getNumVertices(const MElement *const element)
{
  switch(element->getType())
  {
    case TYPE_PNT : return 1;
    case TYPE_LIN : return 2;
    case TYPE_TRI : return 3;
    case TYPE_QUA : return 4;
    case TYPE_TET : return 4;
    case TYPE_PYR : return 5;
    case TYPE_PRI : return 6;
    case TYPE_HEX : return 8;
    case TYPE_TRIH : return 4;
    default : return element->getNumVertices();
  }
}

int getNumPeriodicLink(const GModel *const model)
{
  int numOfPeriodicLink = 0;
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  
  for(unsigned int i = 0; i < entities.size(); i++)
  {
    numOfPeriodicLink += entities[i]->correspondingVertices.size();
  }
  
  return numOfPeriodicLink;
}

/*******************************************************************************
 *
 * Routine PartitionGraph
 *
 * Purpose
 * =======
 *
 *   Partition a graph created by MakeGraph using Metis library
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        0 = success
 *                        1 = error
 *                        2 = exception thrown
 *
 ******************************************************************************/

int PartitionGraph(Graph &graph, meshPartitionOptions &options)
{
#ifdef HAVE_METIS
  Msg::Info("Launching METIS graph partitioner");
      
  try {
    int metisOptions[METIS_NOPTIONS];
    METIS_SetDefaultOptions((idx_t *)metisOptions);
        
    switch(options.algorithm)
    {
      case 1: //Recursive
        metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_RB;
        break;
      case 2: //K-way
        metisOptions[METIS_OPTION_PTYPE] = METIS_PTYPE_KWAY;
        break;
      default:
        Msg::Info("Unknown partition algorithm");
        break;
    }
        
    switch(options.edge_matching)
    {
      case 1: //Random matching
        metisOptions[METIS_OPTION_CTYPE] = METIS_CTYPE_RM;
        break;
      case 2: //Sorted heavy-edge matching
        metisOptions[METIS_OPTION_CTYPE] = METIS_CTYPE_SHEM;
        break;
      default:
        Msg::Info("Unknown partition edge matching");
        break;
    }
        
    switch(options.refine_algorithm)
    {
      case 1: //FM-based cut refinement
        metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_FM;
        break;
      case 2: //Greedy boundary refinement
        metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_GREEDY;
        break;
      case 3: //Two-sided node FM refinement
        metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_SEP2SIDED;
        break;
      case 4: //One-sided node FM refinement
        metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_SEP1SIDED;
        break;
      default:
        Msg::Info("Unknown partition refine algorithm");
        break;
    }
    
    metisOptions[METIS_OPTION_NUMBERING] = 0; //C numbering
    metisOptions[METIS_OPTION_OBJTYPE] = METIS_OBJTYPE_CUT; //Specifies the type of objective.

    const unsigned int nCommon = graph.dim();
    int objval;
    unsigned int *epart = new unsigned int[graph.ne()];
    unsigned int *npart = new unsigned int[graph.nn()];
    const unsigned int ne = graph.ne();
    const unsigned int nn = graph.nn();
        
    graph.fillDefaultWeights();
      
    const int metisError = METIS_PartMeshDual((idx_t *)&ne, (idx_t *)&nn, (idx_t *)graph.eptr(), (idx_t *)graph.eind(), (idx_t *)graph.vwgt(), (idx_t *)NULL, (idx_t *)&nCommon, (idx_t *)&options.num_partitions, (real_t *)NULL, (idx_t *)metisOptions, (idx_t *)&objval, (idx_t *)epart, (idx_t *)npart);
        
    switch(metisError)
    {
      case METIS_OK:
        break;
      case METIS_ERROR_INPUT:
        Msg::Error("Metis error (input)!");
        return 1;
        break;
      case METIS_ERROR_MEMORY:
        Msg::Error("Metis error (memory)!");
        return 1;
        break;
      case METIS_ERROR:
        Msg::Error("Metis error!");
        return 1;
        break;
      default:
        Msg::Error("Error!");
        return 1;
        break;
    }
        
    graph.partition(epart);
    delete[] npart;
        
    Msg::Info("Total edge-cut : %d", objval);
  }
  catch(...) {
    Msg::Error("METIS threw an exception");
    return 2;
  }
#endif
  
  return 0;
}

/******************************************************************************
 *
 * Routine CreateNewEntities
 *
 * Purpose
 * =======
 *
 *   Create the new volume entities (omega)
 *
 * I/O
 * ===
 *
 *   returns            //
 *
 *
 *
 *
 ******************************************************************************/

void CreateNewEntities(GModel *const model, std::unordered_map<MElement*, short> &elmToPartition, std::multimap<int, GEntity*> &newPartitionEntities, meshPartitionOptions &options)
{
  std::set<GRegion*, GEntityLessThan> regions = model->getGRegions();
  std::set<GFace*, GEntityLessThan> faces = model->getGFaces();
  std::set<GEdge*, GEntityLessThan> edges = model->getGEdges();
  std::set<GVertex*, GEntityLessThan> vertices = model->getGVertices();
  
  for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it)
  {
    std::vector<GRegion *> newRegions(options.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->prisms.begin(), (*it)->prisms.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->pyramids.begin(), (*it)->pyramids.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->trihedra.begin(), (*it)->trihedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
    
    for(unsigned int i = 0; i < options.num_partitions; i++)
    {
      if(newRegions[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<int, GEntity*>(i, newRegions[i]));
        static_cast<partitionRegion*>(newRegions[i])->setParentEntity(*it);
      }
    }
  }
  for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it)
  {
    (*it)->mesh_vertices.clear();
    
    (*it)->tetrahedra.clear();
    (*it)->hexahedra.clear();
    (*it)->prisms.clear();
    (*it)->pyramids.clear();
    (*it)->trihedra.clear();
    (*it)->polyhedra.clear();
  }
  
  
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it)
  {
    std::vector<GFace *> newFaces(options.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->triangles.begin(), (*it)->triangles.end());
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->polygons.begin(), (*it)->polygons.end());
    
    for(unsigned int i = 0; i < options.num_partitions; i++)
    {
      if(newFaces[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<int, GEntity*>(i, newFaces[i]));
        static_cast<partitionFace*>(newFaces[i])->setParentEntity(*it);
      }
    }
  }
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it)
  {
    (*it)->mesh_vertices.clear();
    
    (*it)->triangles.clear();
    (*it)->quadrangles.clear();
    (*it)->polygons.clear();
  }
  
  
  for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it)
  {
    std::vector<GEdge *> newEdges(options.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newEdges, (*it)->lines.begin(), (*it)->lines.end());
    
    for(unsigned int i = 0; i < options.num_partitions; i++)
    {
      if(newEdges[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<int, GEntity*>(i, newEdges[i]));
        static_cast<partitionEdge*>(newEdges[i])->setParentEntity(*it);
      }
    }
  }
  for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it)
  {
    (*it)->mesh_vertices.clear();
    
    (*it)->lines.clear();
  }
  
  
  for(GModel::const_viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    std::vector<GVertex *> newVertices(options.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newVertices, (*it)->points.begin(), (*it)->points.end());
    
    for(unsigned int i = 0; i < options.num_partitions; i++)
    {
      if(newVertices[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<int, GEntity*>(i, newVertices[i]));
        static_cast<partitionVertex*>(newVertices[i])->setParentEntity((*it));
      }
    }
  }
  for(GModel::const_viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    (*it)->mesh_vertices.clear();
    
    (*it)->points.clear();
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, short> &elmToPartition, std::vector<GRegion *> &newRegions, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = elmToPartition[(*it)]-1;
    
    if(newRegions[partition] == NULL)
    {
      std::vector<int> partitions;
      partitions.push_back(partition);
      partitionRegion *dr = new partitionRegion(model, model->getMaxElementaryNumber(3)+1, partitions);
      model->add(dr);
      newRegions[partition] = dr;
      
      addPhysical(model, dr, partition);
    }
    
    newRegions[partition]->addElement((*it)->getType(), *it);
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, short> &elmToPartition, std::vector<GFace *> &newFaces, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = elmToPartition[(*it)]-1;
    
    if(newFaces[partition] == NULL)
    {
      std::vector<int> partitions;
      partitions.push_back(partition);
      partitionFace *df = new partitionFace(model, model->getMaxElementaryNumber(2)+1, partitions);
      model->add(df);
      newFaces[partition] = df;
      
      addPhysical(model, df, partition);
    }
    
    newFaces[partition]->addElement((*it)->getType(), *it);
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, short> &elmToPartition, std::vector<GEdge *> &newEdges, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = elmToPartition[(*it)]-1;
    
    if(newEdges[partition] == NULL)
    {
      std::vector<int> partitions;
      partitions.push_back(partition);
      partitionEdge *de = new partitionEdge(model, model->getMaxElementaryNumber(1)+1, NULL, NULL, partitions);
      model->add(de);
      newEdges[partition] = de;
      
      addPhysical(model, de, partition);
    }
    
    newEdges[partition]->addLine(reinterpret_cast<MLine*>(*it));
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, short> &elmToPartition, std::vector<GVertex *> &newVertices, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = elmToPartition[(*it)]-1;
    
    if(newVertices[partition] == NULL)
    {
      std::vector<int> partitions;
      partitions.push_back(partition);
      partitionVertex *dv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
      model->add(dv);
      newVertices[partition] = dv;
      
      addPhysical(model, dv, partition);
    }
    
    newVertices[partition]->addPoint(reinterpret_cast<MPoint*>(*it));
  }
}

void addPhysical(GModel *const model, GEntity *const entity, const int partition)
{
  std::string name = "_omega{";
  name += std::to_string(partition);
  name += "}";
        
  const int number = model->setPhysicalName(name, entity->dim(), 0);
  entity->addPhysicalEntity(number);
}


/*******************************************************************************
 *
 * Routines CreatePartitionBoundaries
 *
 * Purpose
 * =======
 *
 *   Create the new entities between each partitions.
 *
 * I/O
 * ===
 *
 *   returns            //
 *
 *
 *
 *
 ******************************************************************************/

void CreatePartitionBoundaries(GModel *const model, std::multimap<int, GEntity*> &newPartitionBoundaries, bool createGhostCells)
{
  const int meshDim = model->getDim();
    
  std::set<partitionFace*, Less_partitionFace> pfaces;
  std::set<partitionEdge*, Less_partitionEdge> pedges;
  std::set<partitionVertex*, Less_partitionVertex> pvertices;
  
  std::set<partitionEdge*, Less_partitionEdge> bndedges;
  std::set<partitionVertex*, Less_partitionVertex> bndvertices;
    
  std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<int> > >, Hash_Face, Equal_Face> faceToElement;
  std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<int> > >, Hash_Edge, Equal_Edge> edgeToElement;
  std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<int> > > > vertexToElement;
  
  if (meshDim == 3)//Create partition faces
  {
    Msg::Info("Creating partition faces... ");
    for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionVolume)
      {
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->_partitions, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->_partitions, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->_partitions, (*it)->prisms.begin(), (*it)->prisms.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->_partitions, (*it)->pyramids.begin(), (*it)->pyramids.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->_partitions, (*it)->trihedra.begin(), (*it)->trihedra.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->_partitions, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
      }
    }
    for(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<int> > >, Hash_Face, Equal_Face>::const_iterator it = faceToElement.begin(); it != faceToElement.end(); ++it)
    {
      MFace f = it->first;

      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = it->second[0].first;
      
      assignPartitionBoundary(model, f, reference, partitions, pfaces);
    }
    faceToElement.clear();
    
    
    Msg::Info("Creating partition edges... ");
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionSurface)
      {
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
    for(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<int> > >, Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it)
    {
      MEdge e = it->first;
      
      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = it->second[0].first;
      
      assignPartitionBoundary(model, e, reference, partitions, pedges, pfaces, bndedges);
    }
    edgeToElement.clear();
    
    
    Msg::Info("Creating partition vertices... ");
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionSurface)
      {
        fillit_(vertexToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(vertexToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(vertexToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionCurve)
      {
        fillit_(vertexToElement, static_cast<partitionEdge*>(*it)->_partitions, (*it)->lines.begin(), (*it)->lines.end());
      }
    }
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<int> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      
      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = it->second[0].first;
      
      assignPartitionBoundary(model, v, reference, partitions, pvertices, pedges, pfaces, bndedges, bndvertices);
    }
    vertexToElement.clear();
  }
  else if (meshDim == 2)//Create partition edges
  {
    Msg::Info("Creating partition edges... ");
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionSurface)
      {
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->_partitions, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
    for(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<int> > >, Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it)
    {
      MEdge e = it->first;
      
      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = it->second[0].first;
      
      assignPartitionBoundary(model, e, reference, partitions, pedges, pfaces, bndedges);
    }
    edgeToElement.clear();
    
    
    Msg::Info("Creating partition vertices... ");
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionCurve)
      {
        fillit_(vertexToElement, static_cast<partitionEdge*>(*it)->_partitions, (*it)->lines.begin(), (*it)->lines.end());
      }
    }
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<int> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      
      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = it->second[0].first;
      
      assignPartitionBoundary(model, v, reference, partitions, pvertices, pedges, pfaces, bndedges, bndvertices);
    }
    vertexToElement.clear();
  }
  else if (meshDim == 1)//Create partition vertices
  {
    Msg::Info("Creating partition vertices... ");
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
    {
      if((*it)->geomType() == GEntity::PartitionCurve)
      {
        fillit_(vertexToElement, static_cast<partitionEdge*>(*it)->_partitions, (*it)->lines.begin(), (*it)->lines.end());
      }
    }
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<int> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      
      std::vector<int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = it->second[0].first;
      
      assignPartitionBoundary(model, v, reference, partitions, pvertices, pedges, pfaces, bndedges, bndvertices);
    }
    vertexToElement.clear();
  }
  
  
  for(std::set<partitionFace*, Less_partitionFace>::const_iterator it = pfaces.begin(); it != pfaces.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<int, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionEdge*, Less_partitionEdge>::const_iterator it = pedges.begin(); it != pedges.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<int, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionVertex*, Less_partitionVertex>::const_iterator it = pvertices.begin(); it != pvertices.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<int, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionEdge*, Less_partitionEdge>::const_iterator it = bndedges.begin(); it != bndedges.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<int, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionVertex*, Less_partitionVertex>::const_iterator it = bndvertices.begin(); it != bndvertices.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<int, GEntity*>((*it)->_partitions[i], *it));
    }
  }
}

void getPartitionInVector(std::vector<int> &partitions, const std::vector< std::pair<MElement*, std::vector<int> > > &boundaryPair)
{
  for(unsigned int i = 0; i < boundaryPair.size(); i++)
  {
    for(unsigned int j = 0; j < boundaryPair[i].second.size(); j++)
    {
      if(std::find(partitions.begin(), partitions.end(), boundaryPair[i].second[j]) == partitions.end())
      {
        partitions.push_back(boundaryPair[i].second[j]);
      }
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<int> > >, Hash_Face, Equal_Face> &faceToElement, std::vector<int> &partitions, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumFaces(); i++)
    {
      faceToElement[(*it)->getFace(i)].push_back(std::pair<MElement*, std::vector<int> >(*it,partitions));
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<int> > > , Hash_Edge, Equal_Edge> &edgeToElement, std::vector<int> &partitions, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumEdges(); i++)
    {
      edgeToElement[(*it)->getEdge(i)].push_back(std::pair<MElement*, std::vector<int> >(*it,partitions));
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<int> > > > &vertexToElement, std::vector<int> &partitions, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      vertexToElement[(*it)->getVertex(i)].push_back(std::pair<MElement*, std::vector<int> >(*it,partitions));
    }
  }
}

void assignPartitionBoundary(GModel *const model, MFace &me, MElement* reference, std::vector<int> partitions, std::set<partitionFace*, Less_partitionFace> &pfaces)
{
  const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
  
  partitionFace pf(model, 1, partitions);
  std::set<partitionFace*, Less_partitionFace>::iterator it = pfaces.find(&pf);
  
  partitionFace *ppf;
  //Create the new partition entity for the mesh
  if (it == pfaces.end())
  {
    //Create new entity and add them to the model
    ppf = new partitionFace(model, model->getMaxElementaryNumber(2)+1, partitions);
    pfaces.insert(ppf);
    model->add(ppf);
    
    //Create its new physical name
    ppf->addPhysicalEntity(numPhysical);
    
    std::string name = "_sigma{";
    for(unsigned int j = 0; j < ppf->_partitions.size(); j++)
    {
      if(j > 0)
      {
        name += ",";
      }
      name += std::to_string(ppf->_partitions[j]);
    }
    name += "}";
    
    model->setPhysicalName(name, ppf->dim(), numPhysical);
  }
  else
  {
    ppf = *it;
  }
  
  int numFace = 0;
  for(unsigned int i = 0; i < reference->getNumFaces(); i++)
  {
    if(reference->getFace(i) == me)
    {
      numFace = i;
      break;
    }
  }

  
  if(me.getNumVertices() == 3)
  {
    std::vector<MVertex*> verts;
    reference->getFaceVertices(numFace, verts);
    
    if(verts.size() == 3)
    {
      static_cast<GFace*>(ppf)->addTriangle(new MTriangle(verts));
    }
    else if(verts.size() == 6)
    {
      static_cast<GFace*>(ppf)->addTriangle(new MTriangle6(verts));
    }
    else
    {
      static_cast<GFace*>(ppf)->addTriangle(new MTriangleN(verts, verts[0]->getPolynomialOrder()));
    }
  }
  else if(me.getNumVertices() == 4)
  {
    std::vector<MVertex*> verts;
    reference->getFaceVertices(numFace, verts);
    
    if(verts.size() == 4)
    {
      ppf->addQuadrangle(new MQuadrangle(verts));
    }
    else if(verts.size() == 8)
    {
      ppf->addQuadrangle(new MQuadrangle8(verts));
    }
    else if(verts.size() == 9)
    {
      ppf->addQuadrangle(new MQuadrangle9(verts));
    }
    else
    {
      ppf->addQuadrangle(new MQuadrangleN(verts, verts[0]->getPolynomialOrder()));
    }
  }
}

void assignPartitionBoundary(GModel *const model, MEdge &me, MElement* reference, std::vector<int> partitions, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::set<partitionEdge*, Less_partitionEdge> &bndedges)
{
  bool boundariesOfPartition = partitions.size() > 2 ? true : false;
  if(!boundariesOfPartition)
  {
    partitionFace pf(model, 1, partitions);
    std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
  
    //If the edge is on a partitionFace
    if (itf != pfaces.end())
    {
      return;
    }
  }
  
  const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
  partitionEdge *ppe;
  partitionEdge pe(model, 1, NULL, NULL, partitions);
  
  if(boundariesOfPartition)
  {
    std::set<partitionEdge*, Less_partitionEdge>::iterator it = bndedges.find(&pe);
    
    //Create the new partition entity for the mesh
    if (it == bndedges.end())
    {
      //Create new entity and add them to the model
      ppe = new  partitionEdge(model, model->getMaxElementaryNumber(1)+1, 0, 0, partitions);
      bndedges.insert(ppe);
      model->add(ppe);
      
      //Create its new physical name
      ppe->addPhysicalEntity(numPhysical);
      
      std::string name = "_bndSigma{";
      
      for(unsigned int j = 0; j < ppe->_partitions.size(); j++)
      {
        if(j > 0)
        {
          name += ",";
        }
        name += std::to_string(ppe->_partitions[j]);
      }
      name += "}";
      
      model->setPhysicalName(name, ppe->dim(), numPhysical);
    }
    else
    {
      ppe = *it;
    }
  }
  else
  {
    std::set<partitionEdge*, Less_partitionEdge>::iterator it = pedges.find(&pe);
  
    //Create the new partition entity for the mesh
    if (it == pedges.end())
    {
      //Create new entity and add them to the model
      ppe = new  partitionEdge(model, model->getMaxElementaryNumber(1)+1, 0, 0, partitions);
      pedges.insert(ppe);
      model->add(ppe);
    
      //Create its new physical name
      ppe->addPhysicalEntity(numPhysical);
    
      std::string name = "_sigma{";
    
      for(unsigned int j = 0; j < ppe->_partitions.size(); j++)
      {
        if(j > 0)
        {
          name += ",";
        }
        name += std::to_string(ppe->_partitions[j]);
      }
      name += "}";
    
      model->setPhysicalName(name, ppe->dim(), numPhysical);
    }
    else
    {
      ppe = *it;
    }
  }
  
  int numEdge = 0;
  for(unsigned int i = 0; i < reference->getNumEdges(); i++)
  {
    if(reference->getEdge(i) == me)
    {
      numEdge = i;
      break;
    }
  }
  
  if(me.getNumVertices() == 2)
  {
    std::vector<MVertex*> verts;
    reference->getEdgeVertices(numEdge, verts);
    
    if(verts.size() == 2)
    {
      ppe->addLine(new MLine(verts));
    }
    else if(verts.size() == 3)
    {
      ppe->addLine(new MLine3(verts));
    }
    else
    {
      ppe->addLine(new MLineN(verts));
    }
  }
}

void assignPartitionBoundary(GModel *const model, MVertex *ve, MElement* reference, std::vector<int> partitions, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::set<partitionEdge*, Less_partitionEdge> &bndedges, std::set<partitionVertex*, Less_partitionVertex> &bndvertices)
{
  bool boundariesOfPartition = partitions.size() > 2 ? true : false;
  if(!boundariesOfPartition)
  {
    partitionFace pf(model, 1, partitions);
    std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
  
    //If the vertex is on a partitionFace
    if (itf != pfaces.end())
    {
      return;
    }
  
    partitionEdge pe(model, 1, 0, 0, partitions);
    std::set<partitionEdge*, Less_partitionEdge>::iterator ite = pedges.find(&pe);
  
    //If the vertex is on a partitionEdge
    if (ite != pedges.end())
    {
      return;
    }
  }
  else
  {
    partitionEdge pe(model, 1, 0, 0, partitions);
    std::set<partitionEdge*, Less_partitionEdge>::iterator ite = bndedges.find(&pe);
    
    //If the vertex is on a partitionEdge
    if (ite != bndedges.end())
    {
      return;
    }
  }
  
  const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
  partitionVertex *ppv;
  partitionVertex pv(model, 1, partitions);
  
  if(boundariesOfPartition)
  {
    std::set<partitionVertex*, Less_partitionVertex>::iterator it = bndvertices.find(&pv);
    
    //Create the new partition entity for the mesh
    if (it == bndvertices.end())
    {
      ppv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
      bndvertices.insert(ppv);
      model->add(ppv);
      
      //Create its new physical name
      ppv->addPhysicalEntity(numPhysical);
      
      std::string name = "_bndSigma{";
      for(unsigned int j = 0; j < ppv->_partitions.size(); j++)
      {
        if(j > 0)
        {
          name += ",";
        }
        name += std::to_string(ppv->_partitions[j]);
      }
      name += "}";
      
      model->setPhysicalName(name, ppv->dim(), numPhysical);
    }
    else
    {
      ppv = *it;
    }
  }
  else
  {
    std::set<partitionVertex*, Less_partitionVertex>::iterator it = pvertices.find(&pv);
  
    //Create the new partition entity for the mesh
    if (it == pvertices.end())
    {
      ppv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
      pvertices.insert(ppv);
      model->add(ppv);
    
      //Create its new physical name
      ppv->addPhysicalEntity(numPhysical);
    
      std::string name = "_sigma{";
      for(unsigned int j = 0; j < ppv->_partitions.size(); j++)
      {
        if(j > 0)
        {
          name += ",";
        }
        name += std::to_string(ppv->_partitions[j]);
      }
      name += "}";
    
      model->setPhysicalName(name, ppv->dim(), numPhysical);
    }
    else
    {
      ppv = *it;
    }
  }
  
  ppv->addPoint(new MPoint(ve));
}

/*******************************************************************************
 *
 * Routine AssignMeshVertices
 *
 * Purpose
 * =======
 *
 *   Assign the vertices to its corresponding entity
 *
 * I/O
 * ===
 *
 *   returns            - status
 *
 *
 *
 *
 ******************************************************************************/

void AssignMeshVertices(GModel *model)
{
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
  {
    entities[i]->mesh_vertices.clear();
  }
  
  std::set<MVertex *> verts;
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    setVerticesToEntity(verts, *it, (*it)->points.begin(), (*it)->points.end());
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    setVerticesToEntity(verts, *it, (*it)->lines.begin(), (*it)->lines.end());
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    setVerticesToEntity(verts, *it, (*it)->triangles.begin(), (*it)->triangles.end());
    setVerticesToEntity(verts, *it, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
    setVerticesToEntity(verts, *it, (*it)->polygons.begin(), (*it)->polygons.end());
  }
  
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    setVerticesToEntity(verts, *it, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
    setVerticesToEntity(verts, *it, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
    setVerticesToEntity(verts, *it, (*it)->prisms.begin(), (*it)->prisms.end());
    setVerticesToEntity(verts, *it, (*it)->pyramids.begin(), (*it)->pyramids.end());
    setVerticesToEntity(verts, *it, (*it)->trihedra.begin(), (*it)->trihedra.end());
    setVerticesToEntity(verts, *it, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
  }
}

template <class ITERATOR>
void setVerticesToEntity(std::set<MVertex *> &verts, GEntity *const entity, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    for(unsigned int j = 0; j < (*it)->getNumVertices(); j++)
    {
      if(verts.find((*it)->getVertex(j)) == verts.end())
      {
        entity->addMeshVertex((*it)->getVertex(j));
        (*it)->getVertex(j)->setEntity(entity);
        
        verts.insert((*it)->getVertex(j));
      }
    }
  }
}

/*******************************************************************************
 *
 * Routine CreateTopologyFile
 *
 * Purpose
 * =======
 *
 *   Create the topology file.
 *
 * I/O
 * ===
 *
 *   returns            - status
 *
 *
 *
 *
 ******************************************************************************/

void CreateTopologyFile(GModel* model, const int npart)
{
  std::ofstream file("topology.pro", std::ofstream::trunc);
  
  //-----------Group-----------
  file << "Group{" << std::endl;
  
  //Omega
  std::unordered_map<int, std::vector<int> > listOfOmega;//map between tag of omega and the physical's numbers that corresponds
  for(GModel::piter it = model->firstPhysicalName(); it != model->lastPhysicalName(); ++it)
  {
    std::string name = it->second;
    
    if(name[0] == '_' && name[1] == 'o')
    {
      std::vector<int> num = getNumFromString(name);
      listOfOmega[num[0]].push_back(it->first.second);
    }
  }
  //Omega_i
  for(std::unordered_map<int, std::vector<int> >::iterator it = listOfOmega.begin(); it != listOfOmega.end(); ++it)
  {
    std::vector<int> vec = it->second;
    file << "\tOmega_" << it->first << " = Region[{";
    
    for(int i = 0; i < vec.size(); i++)
    {
      if(i != 0)
      {
        file << ", ";
      }
      file << vec[i];
    }
    file << "}];" << std::endl;
  }
  file << std::endl;
  
  //Sigma
  if(npart == 1)
  {
    file << "\tSigma_0_0 = Region[{}];" << std::endl;
    file << "\tBndSigma_0_0 =  Region[{}];" << std::endl;
    file << "\tSigma_0 =  Region[{}];" << std::endl;
    file << "\tBndGammaInf_0_0 = Region[{}];" << std::endl;
    file << "\tBndGammaD_0_0 = Region[{}];" << std::endl;
    file << "\tBndGammaInf_0 = Region[{}];" << std::endl;
    file << "\tBndGammaD_0 = Region[{}];" << std::endl;
    file << "\tD_0() = {0};" << std::endl;
  }
  std::unordered_map<int, std::vector<int> > listOfSigma;//map between tag of sigma and the physical's numbers that corresponds
  std::unordered_map<int, std::vector<int> > listOfBndSigma;//map between tag of sigma's boundary and the physical's numbers that corresponds
  for(GModel::piter it = model->firstPhysicalName(); it != model->lastPhysicalName(); ++it)
  {
    std::string name = it->second;
    
    if(name[0] == '_' && name[1] == 's')
    {
      std::vector<int> num = getNumFromString(name);
      
      if(num.size() < 3)
      {
        for(unsigned int i = 0; i < num.size(); i++)
        {
          listOfSigma[num[i]].push_back(it->first.second);
        }
      }
      else
      {
        for(unsigned int i = 0; i < num.size(); i++)
        {
          listOfBndSigma[num[i]].push_back(it->first.second);
        }
      }
    }
  }
  file << std::endl;
  //Sigma_i_j and BndSigma_i_j
  std::unordered_map<int, std::vector<int> > listOfNeighbour;//map between tag of omega and tag of neighbours
  for(std::unordered_map<int, std::vector<int> >::iterator it = listOfSigma.begin(); it != listOfSigma.end(); ++it)
  {
    for(std::unordered_map<int, std::vector<int> >::iterator it2 = it; it2 != listOfSigma.end(); ++it2)
    {
      if(it != it2)
      {
        std::vector<int> vec1 = it->second;
        std::vector<int> vec2 = it2->second;
        std::vector<int>* vecCommun =  new std::vector<int>;
        
        if(commonPhysicals(vec1, vec2, vecCommun))
        {
          listOfNeighbour[it->first].push_back(it2->first);
          listOfNeighbour[it2->first].push_back(it->first);
          
          file << "\tSigma_" << it->first << "_" << it2->first << " = Region[{";
          for(unsigned int i = 0; i < vecCommun->size(); i++)
          {
            if(i != 0)
            {
              file << ", ";
            }
            file << (*vecCommun)[i];
          }
          file << "}];" << std::endl;
          
          file << "\tSigma_" << it2->first << "_" << it->first << " = Region[{";
          for(unsigned int i = 0; i < vecCommun->size(); i++)
          {
            if(i != 0)
            {
              file << ", ";
            }
            file << (*vecCommun)[i];
          }
          file << "}];" << std::endl;
          
          if(listOfBndSigma.count(it->first) > 0)
          {
            std::vector<int> vec1 = listOfBndSigma[it->first];
            std::vector<int> vec2 = listOfBndSigma[it2->first];
            std::vector<int>* vecCommun =  new std::vector<int>;
            
            if(commonPhysicals(vec1, vec2, vecCommun))
            {
              file << "\tBndSigma_" << it->first << "_" << it2->first << " = Region[{";
              for(unsigned int i = 0; i < vecCommun->size(); i++)
              {
                if(i != 0)
                {
                  file << ", ";
                }
                file << (*vecCommun)[i];
              }
              file << "}];" << std::endl;
              
              file << "\tBndSigma_" << it2->first << "_" << it->first << " = Region[{";
              for(unsigned int i = 0; i < vecCommun->size(); i++)
              {
                if(i != 0)
                {
                  file << ", ";
                }
                file << (*vecCommun)[i];
              }
              file << "}];" << std::endl;
            }
            else
            {
              file << "\tBndSigma_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
              file << "\tBndSigma_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
            }
          }
          else
          {
            file << "\tBndSigma_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
            file << "\tBndSigma_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
          }
          
          file << "\tBndGammaInf_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
          file << "\tBndGammaInf_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
          
          file << "\tBndGammaD_" << it->first << "_" << it2->first << " = Region[{}];" << std::endl;
          file << "\tBndGammaD_" << it2->first << "_" << it->first << " = Region[{}];" << std::endl;
          
          file << "\tBndGammaInf_" << it->first << " = Region[{}];" << std::endl;
          file << "\tBndGammaInf_" << it2->first << " = Region[{}];" << std::endl;
          
          file << "\tBndGammaD_" << it->first << " = Region[{}];" << std::endl;
          file << "\tBndGammaD_" << it2->first << " = Region[{}];" << std::endl;
        }
        delete vecCommun;
      }
    }
  }
  file << std::endl;
  //Sigma_i
  for(std::unordered_map<int, std::vector<int> >::iterator it = listOfSigma.begin(); it != listOfSigma.end(); ++it)
  {
    std::vector<int> vec = it->second;
    file << "\tSigma_" << it->first << " = Region[{";
    
    for(int i = 0; i < vec.size(); i++)
    {
      if(i != 0)
      {
        file << ", ";
      }
      file << vec[i];
    }
    file << "}];" << std::endl;
  }
  file << std::endl;
  //BndSigma_i
  for(std::unordered_map<int, std::vector<int> >::iterator it = listOfBndSigma.begin(); it != listOfBndSigma.end(); ++it)
  {
    std::vector<int> vec = it->second;
    file << "\tBndSigma_" << it->first << " = Region[{";
    
    for(int i = 0; i < vec.size(); i++)
    {
      if(i != 0)
      {
        file << ", ";
      }
      file << vec[i];
    }
    file << "}];" << std::endl;
  }
  file << std::endl << std::endl;
  
  //D
  file << "\tD() = {";
  for(int i = 0; i < listOfOmega.size(); i++)
  {
    if(i != 0)
    {
      file << ", ";
    }
    file << i;
  }
  file << "};" << std::endl;
  file << "\tN_DOM = #D();" << std::endl;
  
  //D_i
  for(std::unordered_map<int, std::vector<int> >::iterator it = listOfNeighbour.begin(); it != listOfNeighbour.end(); ++it)
  {
    file << "\tD_" << it->first << " = {";
    for(unsigned int i = 0; i < it->second.size(); i++)
    {
      if(i != 0)
      {
        file << ", ";
      }
      file << it->second[i];
    }
    file << "};" << std::endl;
  }
  
  
  file << "}" << std::endl << std::endl;
}

std::vector<int> getNumFromString(std::string name)
{
  std::vector<int> num;
  std::string currentNum;
  
  for(unsigned int i = 0; i < name.size(); i++)
  {
    if(name[i] == '0' || name[i] == '1' || name[i] == '2'|| name[i] == '3'|| name[i] == '4'|| name[i] == '5'|| name[i] == '6'|| name[i] == '7'|| name[i] == '8'|| name[i] == '9')
    {
      currentNum += name[i];
    }
    
    if(name[i] == ',' || name[i] == '}')
    {
      num.push_back(stoi(currentNum));
      currentNum.clear();
    }
  }
  
  return num;
}

bool commonPhysicals(const std::vector<int> vec1, const std::vector<int> vec2, std::vector<int>* vecCommon)
{
  for(unsigned int i = 0; i < vec1.size(); i++)
  {
    for(unsigned int j = 0; j < vec2.size(); j++)
    {
      if(vec1[i] == vec2[j])
      {
        vecCommon->push_back(vec1[i]);
      }
    }
  }
  
  if(vecCommon->size() > 0)
  {
    return true;
  }
  return false;
}

int PartitionMeshFace(std::list<GFace*> &cFaces, meshPartitionOptions &options)
{
  GModel *tmp_model = new GModel();
  for(std::list<GFace*>::iterator it = cFaces.begin(); it != cFaces.end(); it++)
    tmp_model->add(*it);
  
  PartitionMesh(tmp_model,options);
  
  for(std::list<GFace*>::iterator it = cFaces.begin(); it != cFaces.end(); it++)
    tmp_model->remove(*it);
  delete tmp_model;
  return 1;
}

void createPartitionFaces(GModel *model,  std::vector<MElement *> &elements, int N, std::vector<discreteFace*> &discreteFaces)
{
#if defined(HAVE_SOLVER)
  // Compound is partitioned in N discrete faces
  //--------------------------------------------
  std::vector<std::set<MVertex*> > allNodes;
  int numMax = model->getMaxElementaryNumber(2) + 1;
  for(int i = 0; i < N; i++){
    discreteFace *face = new discreteFace(model, numMax+i);
    discreteFaces.push_back(face);
    model->add(face); //delete this
    std::set<MVertex*> mySet;
    allNodes.push_back(mySet);
  }
  
  for(int i = 0; i < elements.size(); ++i){
    MElement *e = elements[i];
    int part = e->getPartition()-1;
    for(int j = 0; j < 3; j++){
      allNodes[part].insert(e->getVertex(j));
    }
    discreteFaces[part]->triangles.push_back(new MTriangle(e->getVertex(0),e->getVertex(1),e->getVertex(2))) ;
  }
  
  for(int i = 0; i < N; i++){
    for (std::set<MVertex*>::iterator it = allNodes[i].begin(); it != allNodes[i].end(); it++){
      discreteFaces[i]->mesh_vertices.push_back(*it);
    }
  }
  
#endif
}

int PartitionMeshElements(std::vector<MElement*> &elements, meshPartitionOptions &options)
{
  GModel *tmp_model = new GModel();
  GFace *gf = new discreteFace(tmp_model, 1);
  std::set<MVertex *> setv;
  for (unsigned i=0;i<elements.size();++i)
    for (int j=0;j<elements[i]->getNumVertices();j++)
      setv.insert(elements[i]->getVertex(j));
  
  for (std::set<MVertex* >::iterator it = setv.begin(); it != setv.end(); it++)
    gf->mesh_vertices.push_back(*it);
  
  for (std::vector<MElement* >::iterator it = elements.begin(); it != elements.end(); it++){
    if ((*it)->getType() == TYPE_TRI)
      gf->triangles.push_back((MTriangle*)(*it));
    else if  ((*it)->getType() == TYPE_QUA)
      gf->quadrangles.push_back((MQuadrangle*)(*it));
  }
  tmp_model->add(gf);
  
  PartitionMesh(tmp_model,options);
  
  tmp_model->remove(gf);
  delete tmp_model;
  
  return 1;
}

#else

int PartitionMesh(GModel *const model, meshPartitionOptions &options)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}


#endif
