// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// meshPartition.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <stack>
#include <cstdlib>

#include "Context.h"
#include "GmshConfig.h"
#include "meshPartition.h"
#include "OS.h"

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
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "discreteRegion.h"

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

int PartitionMesh(GModel *const model)
{
  Graph graph;
  Msg::StatusBar(true, "Building mesh graph...");
  int ier = MakeGraph(model, graph);
  graph.nparts(CTX::instance()->mesh.num_partitions);
  if(graph.nparts() > 0){
    Msg::StatusBar(true, "Partitioning graph...");
    if(!ier) ier = PartitionGraph(graph);
    if(ier) return 1;
  }
  else{
    return 0;
  }
    
  // Assign partitions to elements
#ifdef HAVE_CXX11
  std::unordered_map<MElement*, unsigned int> elmToPartition;
#else
  std::map<MElement*, unsigned int> elmToPartition;
#endif
  for(unsigned int i = 0; i < graph.ne(); i++){
    if(graph.element(i) != NULL){
      if(graph.nparts() > 1){
        elmToPartition.insert(std::pair<MElement*, unsigned int>(graph.element(i), graph.partition(i)+1));
        //Should be removed
        graph.element(i)->setPartition(graph.partition(i)+1);
      }
      else{
        elmToPartition.insert(std::pair<MElement*, unsigned int>(graph.element(i), 1));
        //Should be removed
        graph.element(i)->setPartition(1);
      }
    }
  }
  std::vector< std::set<MElement*> > boundaryElements = graph.getBoundaryElements();
  graph.clear();
  model->recomputeMeshPartitions();
  
  Msg::StatusBar(true, "Create new entities...");
  CreateNewEntities(model, elmToPartition);
  elmToPartition.clear();
  
  if(CTX::instance()->mesh.createPartitionBoundaries){
    Msg::StatusBar(true, "Create boundaries...");
    CreatePartitionBoundaries(model, boundaryElements);
    boundaryElements.clear();
    
    Msg::StatusBar(true, "Build the topology...");
    BuildTopology(model);
  }
 
  AssignMeshVertices(model);
  
  Msg::StatusBar(true, "Done partitioning");
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
  for(GModel::viter it = vertices.begin(); it != vertices.end(); ++it){
    GVertex *vertex = *it;
    
    if(vertex->geomType() == GEntity::PartitionVertex){
      partitionVertex* pvertex = static_cast<partitionVertex*>(vertex);
      if(pvertex->getParentEntity() != NULL){
        assignToParent(verts, pvertex, pvertex->points.begin(), pvertex->points.end());
      }
      else{
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
  for(GModel::eiter it = edges.begin(); it != edges.end(); ++it){
    GEdge *edge = *it;
    
    if(edge->geomType() == GEntity::PartitionCurve){
      partitionEdge* pedge = static_cast<partitionEdge*>(edge);
      if(pedge->getParentEntity() != NULL){
        assignToParent(verts, pedge, pedge->lines.begin(), pedge->lines.end());
      }
      else{
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
    
    if(face->geomType() == GEntity::PartitionSurface){
      partitionFace* pface = static_cast<partitionFace*>(face);
      if(pface->getParentEntity() != NULL){
        assignToParent(verts, pface, pface->triangles.begin(), pface->triangles.end());
        assignToParent(verts, pface, pface->quadrangles.begin(), pface->quadrangles.end());
      }
      else{
        for(unsigned int j = 0; j < pface->triangles.size(); j++)
          delete pface->triangles[j];
        
        for(unsigned int j = 0; j < pface->quadrangles.size(); j++)
          delete pface->quadrangles[j];
      }
      pface->triangles.clear();
      pface->quadrangles.clear();
      pface->mesh_vertices.clear();
      
      model->remove(pface);
      delete pface;
    }
  }
  
  //Loop over regions
  for(GModel::riter it = regions.begin(); it != regions.end(); ++it){
    GRegion *region = *it;
    
    if(region->geomType() == GEntity::PartitionVolume){
      partitionRegion* pregion = static_cast<partitionRegion*>(region);
      if(pregion->getParentEntity() != NULL){
        assignToParent(verts, pregion, pregion->tetrahedra.begin(), pregion->tetrahedra.end());
        assignToParent(verts, pregion, pregion->hexahedra.begin(), pregion->hexahedra.end());
        assignToParent(verts, pregion, pregion->prisms.begin(), pregion->prisms.end());
        assignToParent(verts, pregion, pregion->pyramids.begin(), pregion->pyramids.end());
        assignToParent(verts, pregion, pregion->trihedra.begin(), pregion->trihedra.end());
      }
      else{
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
      }
      pregion->tetrahedra.clear();
      pregion->hexahedra.clear();
      pregion->prisms.clear();
      pregion->pyramids.clear();
      pregion->trihedra.clear();
      pregion->mesh_vertices.clear();
      
      model->remove(pregion);
      delete pregion;
    }
  }
  
  model->recomputeMeshPartitions();
  
  std::map<std::pair<int, int>, std::string> physicalNames = model->getAllPhysical();
  for(GModel::piter it = physicalNames.begin(); it != physicalNames.end(); ++it){
    std::string name = it->second;
    
    if(name[0] == '_'){
      model->erasePhysicalGroup(it->first.first, it->first.second);
    }
  }
  
  return 0;
}

template <class ITERATOR>
void assignToParent(std::set<MVertex*> &verts, partitionRegion *region, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    region->getParentEntity()->addElement((*it)->getType(), *it);
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++){
      if(verts.find((*it)->getVertex(i)) == verts.end()){
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
  for(ITERATOR it = it_beg; it != it_end; ++it){
    face->getParentEntity()->addElement((*it)->getType(), *it);
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++){
      if(verts.find((*it)->getVertex(i)) == verts.end()){
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
  for(ITERATOR it = it_beg; it != it_end; ++it){
    edge->getParentEntity()->addLine(reinterpret_cast<MLine*>(*it));
    (*it)->setPartition(0);
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++){
      if(verts.find((*it)->getVertex(i)) == verts.end()){
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
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++){
      if(verts.find((*it)->getVertex(i)) == verts.end()){
        (*it)->getVertex(i)->setEntity(vertex->getParentEntity());
        vertex->getParentEntity()->addMeshVertex((*it)->getVertex(i));
        verts.insert((*it)->getVertex(i));
      }
    }
  }
}

/*******************************************************************************
 *
 * Routine ConvertOldPartitioningToNewOne
 *
 * Purpose
 * =======
 *
 *   Import a mesh partitionned by a tag given to the element en create the
 *   topology (omega, sigma, bndSigma, ...).
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        0 = success
 *                        1 = no elements found
 *
 *
 ******************************************************************************/

int ConvertOldPartitioningToNewOne(GModel *const model)
{
#ifdef HAVE_CXX11
  std::unordered_map<MElement*, unsigned int> elmToPartition;
#else
  std::map<MElement*, unsigned int> elmToPartition;
#endif
  std::set<unsigned int> partitions;
  
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
    for(std::vector<MTetrahedron*>::iterator itElm = (*it)->tetrahedra.begin(); itElm != (*it)->tetrahedra.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
    for(std::vector<MHexahedron*>::iterator itElm = (*it)->hexahedra.begin(); itElm != (*it)->hexahedra.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
    for(std::vector<MPrism*>::iterator itElm = (*it)->prisms.begin(); itElm != (*it)->prisms.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
    for(std::vector<MPyramid*>::iterator itElm = (*it)->pyramids.begin(); itElm != (*it)->pyramids.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
    for(std::vector<MTrihedron*>::iterator itElm = (*it)->trihedra.begin(); itElm != (*it)->trihedra.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
    for(std::vector<MTriangle*>::iterator itElm = (*it)->triangles.begin(); itElm != (*it)->triangles.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
    for(std::vector<MQuadrangle*>::iterator itElm = (*it)->quadrangles.begin(); itElm != (*it)->quadrangles.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    for(std::vector<MLine*>::iterator itElm = (*it)->lines.begin(); itElm != (*it)->lines.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
    for(std::vector<MPoint*>::iterator itElm = (*it)->points.begin(); itElm != (*it)->points.end(); ++itElm){
      elmToPartition.insert(std::pair<MElement*, unsigned int>(*itElm, (*itElm)->getPartition()));
      partitions.insert((*itElm)->getPartition());
    }
  }
  
  Graph graph;
  Msg::StatusBar(true, "Building mesh graph...");
  int ier = MakeGraph(model, graph);
  if(ier) return 1;
  createDualGraph(graph);
  graph.nparts(partitions.size());
  
  unsigned int *part = new unsigned int[graph.ne()];
  for(unsigned int i = 0; i < graph.ne(); i++){
    if(graph.element(i) != NULL){
      part[i] = graph.element(i)->getPartition()-1;
      Msg::Info("%d", part[i]);
      if(graph.element(i)->getPartition() == 0){
        Msg::Error("All elements are not partitioned.");
        return 1;
      }
    }
  }
  graph.partition(part);
  
  std::vector< std::set<MElement*> > boundaryElements = graph.getBoundaryElements();
  graph.clear();
  model->recomputeMeshPartitions();
  
  Msg::StatusBar(true, "Create new entities...");
  CreateNewEntities(model, elmToPartition);
  elmToPartition.clear();
  
  if(CTX::instance()->mesh.createPartitionBoundaries){
    Msg::StatusBar(true, "Create boundaries...");
    CreatePartitionBoundaries(model, boundaryElements);
    boundaryElements.clear();
    
    Msg::StatusBar(true, "Build the topology...");
    BuildTopology(model);
  }
  
  AssignMeshVertices(model);
  
  return 0;
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
  graph.ne(model->getNumMeshElements());
  graph.nn(model->getNumMeshVertices());
  graph.dim(model->getDim());
  graph.elementResize(graph.ne());
  graph.vertexResize(model->getMaxVertexNumber());
  graph.eptrResize(graph.ne()+1);
  graph.eptr(0,0);
  const int eindSize = getSizeOfEind(model);
  graph.eindResize(eindSize);
  
  int eptrIndex = 0;
  int eindIndex = 0;
  int numVertex = 0;
  
  if(graph.ne() == 0){
    Msg::Error("No mesh elements were found");
    return 1;
  }
  if(graph.dim() == 0){
    Msg::Error("Cannot partition a point");
    return 1;
  }
  
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
    const GRegion *r = *it;
    
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->tetrahedra.begin(), r->tetrahedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->hexahedra.begin(), r->hexahedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->prisms.begin(), r->prisms.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->pyramids.begin(), r->pyramids.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->trihedra.begin(), r->trihedra.end());
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
    const GFace *f = *it;
    
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex, f->triangles.begin(), f->triangles.end());
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex, f->quadrangles.begin(), f->quadrangles.end());
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    const GEdge *e = *it;
    
    fillElementsToNodesMap(graph, e, eptrIndex, eindIndex, numVertex, e->lines.begin(), e->lines.end());
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
    GVertex *v = *it;
    
    fillElementsToNodesMap(graph, v, eptrIndex, eindIndex, numVertex, v->points.begin(), v->points.end());
  }
  
  //Taking into account the periodicity
  if(isPeriodic(model)){
    std::map<int,int> correspondingVertices;
    std::vector<GEntity*> entities;
    model->getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++){
      for(std::map<MVertex*,MVertex*>::iterator it = entities[i]->correspondingVertices.begin(); it != entities[i]->correspondingVertices.end(); ++it){
        correspondingVertices.insert(std::pair<int,int>(graph.vertex(it->first->getNum()-1), graph.vertex(it->second->getNum()-1)));
      }
    }
        
    for(unsigned int i = 0; i < eindSize; i++){
      std::map<int,int>::iterator it = correspondingVertices.find(graph.eind(i));
      if(it != correspondingVertices.end()){
        graph.eind(i,it->second);
      }
    }
  }
  
  return 0;
}

template <class ITERATOR>
void fillElementsToNodesMap(Graph &graph, const GEntity *const entity, int &eptrIndex, int &eindIndex, int &numVertex, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    const int numVertices = (*it)->getNumPrimaryVertices();
    graph.element(eptrIndex, *it);
    eptrIndex++;
    graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + numVertices);
    for(int i = 0; i < numVertices; i++){
      if(graph.vertex((*it)->getVertex(i)->getNum()-1) == -1){
        graph.vertex((*it)->getVertex(i)->getNum()-1, numVertex);
        numVertex++;
      }
      graph.eind(eindIndex, graph.vertex((*it)->getVertex(i)->getNum()-1));
      eindIndex++;
    }
  }
}

int getSizeOfEind(const GModel *const model)
{
  int size = 0;
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
    size += 4*(*it)->tetrahedra.size();
    size += 8*(*it)->hexahedra.size();
    size += 6*(*it)->prisms.size();
    size += 5*(*it)->pyramids.size();
    size += 4*(*it)->trihedra.size();
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
    size += 3*(*it)->triangles.size();
    size += 4*(*it)->quadrangles.size();
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    size += 2*(*it)->lines.size();
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
    size += 1*(*it)->points.size();
  }
  
  return size;
}

int getSizeOfEind(const GEntity *const entity)
{
  int size = 0;
  //Loop over regions
  if(entity->dim() == 3){
    size += 4*static_cast<const GRegion*>(entity)->tetrahedra.size();
    size += 8*static_cast<const GRegion*>(entity)->hexahedra.size();
    size += 6*static_cast<const GRegion*>(entity)->prisms.size();
    size += 5*static_cast<const GRegion*>(entity)->pyramids.size();
    size += 4*static_cast<const GRegion*>(entity)->trihedra.size();
  }
  else if(entity->dim() == 2){
    size += 3*static_cast<const GFace*>(entity)->triangles.size();
    size += 4*static_cast<const GFace*>(entity)->quadrangles.size();
  }
  else if(entity->dim() == 1){
    size += 2*static_cast<const GEdge*>(entity)->lines.size();
  }
  else if(entity->dim() == 0){
    size += 1*static_cast<const GVertex*>(entity)->points.size();
  }
  
  return size;
}

bool isPeriodic(const GModel *const model)
{
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  
  for(unsigned int i = 0; i < entities.size(); i++){
    if(entities[i]->correspondingVertices.size() != 0) return true;
  }
  
  return false;
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

int PartitionGraph(Graph &graph)
{
#ifdef HAVE_METIS
  Msg::Info("Launching METIS graph partitioner");
      
  try {
    int metisOptions[METIS_NOPTIONS];
    METIS_SetDefaultOptions((idx_t *)metisOptions);
        
    switch(CTX::instance()->mesh.metis_algorithm){
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
        
    switch(CTX::instance()->mesh.metis_edge_matching){
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
        
    switch(CTX::instance()->mesh.metis_refine_algorithm){
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

    int objval;
    unsigned int *epart = new unsigned int[graph.ne()];
    const unsigned int ne = graph.ne();
    const int numPart = graph.nparts();
    int ncon = 1;
        
    graph.fillDefaultWeights();
    
    int metisError = 0;
    createDualGraph(graph);
    
    if (metisOptions[METIS_OPTION_PTYPE] == METIS_PTYPE_KWAY){
      metisError = METIS_PartGraphKway((idx_t *)&ne, (idx_t *)&ncon, (idx_t *)graph.xadj(), (idx_t *)graph.adjncy(), (idx_t *)graph.vwgt(), (idx_t *)NULL, NULL, (idx_t *)&numPart, NULL, NULL, (idx_t *)metisOptions, (idx_t *)&objval, (idx_t *)epart);
    }
    else{
      metisError = METIS_PartGraphRecursive((idx_t *)&ne, (idx_t *)&ncon, (idx_t *)graph.xadj(), (idx_t *)graph.adjncy(), (idx_t *)graph.vwgt(), (idx_t *)NULL, NULL, (idx_t *)&numPart, NULL, NULL, (idx_t *)metisOptions, (idx_t *)&objval, (idx_t *)epart);
    }

    switch(metisError){
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
    
    //Check and correct the topology
    for(unsigned int i = 0; i < graph.ne(); i++){
      if(graph.element(i)->getDim() == graph.dim()) continue;
      
      for(unsigned int j = graph.xadj(i); j < graph.xadj(i+1); j++){
        if(graph.element(graph.adjncy(j))->getDim() == graph.element(i)->getDim()+1){
          if(epart[i] != epart[graph.adjncy(j)]){
            epart[i] = epart[graph.adjncy(j)];
            break;
          }
        }
        
        if(graph.element(graph.adjncy(j))->getDim() == graph.element(i)->getDim()+2){
          if(epart[i] != epart[graph.adjncy(j)]){
            epart[i] = epart[graph.adjncy(j)];
            break;
          }
        }
        
        if(graph.element(graph.adjncy(j))->getDim() == graph.element(i)->getDim()+3){
          if(epart[i] != epart[graph.adjncy(j)]){
            epart[i] = epart[graph.adjncy(j)];
            break;
          }
        }
      }
    }
    graph.partition(epart);
        
    Msg::Info("Total edge-cut : %d", objval);
  }
  catch(...) {
    Msg::Error("METIS threw an exception");
    return 2;
  }
#endif
  
  return 0;
}

void createDualGraph(Graph &graph)
{
  int *nptr = new int[graph.nn()+1];
  for(unsigned int i = 0; i < graph.nn()+1; i++) nptr[i] = 0;
  int *nind = new int[graph.eptr(graph.ne())];
  for(unsigned int i = 0; i < graph.eptr(graph.ne()); i++) nind[i] = 0;
  
  for(unsigned int i = 0; i < graph.ne(); i++){
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++){
      nptr[graph.eind(j)]++;
    }
  }
  
  for(unsigned int i = 1; i < graph.nn(); i++) nptr[i] += nptr[i-1];
  for(unsigned int i = graph.nn(); i > 0; i--) nptr[i] = nptr[i-1];
  nptr[0] = 0;
  
  for(unsigned int i = 0; i < graph.ne(); i++){
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++){
      nind[nptr[graph.eind(j)]++] = i;
    }
  }
  
  for(unsigned int i = graph.nn(); i > 0; i--) nptr[i] = nptr[i-1];
  nptr[0] = 0;
  
  graph.xadjResize(graph.ne()+1);
  int *nbrs = new int[graph.ne()];
  int *marker = new int[graph.ne()];
  for(unsigned int i = 0; i < graph.ne(); i++){
    nbrs[i] = 0;
    marker[i] = 0;
  }
  
  for(unsigned int i = 0; i < graph.ne(); i++){
    unsigned int l = 0;
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++){
      for(unsigned int k = nptr[graph.eind(j)]; k < nptr[graph.eind(j)+1]; k++){
        if(nind[k] != i){
          if(marker[nind[k]] == 0) nbrs[l++] = nind[k];
          marker[nind[k]]++;
        }
      }
    }
    
    unsigned int nbrsNeighbors = 0;
    for(unsigned int j = 0; j < l; j++){
      if(marker[nbrs[j]] >= graph.element(i)->numCommonNodesInDualGraph(graph.element(nbrs[j]))) nbrsNeighbors++;
      marker[nbrs[j]] = 0;
      nbrs[j] = 0;
    }
    
    graph.xadj(i, nbrsNeighbors);
  }
  
  for(unsigned int i = 1; i < graph.ne(); i++) graph.xadj(i,graph.xadj(i)+graph.xadj(i-1));
  for(unsigned int i = graph.ne(); i > 0; i--) graph.xadj(i,graph.xadj(i-1));
  graph.xadj(0,0);
  
  graph.adjncyResize(graph.xadj(graph.ne()));
  for(unsigned int i = 0; i < graph.ne(); i++){
    unsigned int l = 0;
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++){
      for(unsigned int k = nptr[graph.eind(j)]; k < nptr[graph.eind(j)+1]; k++){
        if(nind[k] != i){
          if (marker[nind[k]] == 0) nbrs[l++] = nind[k];
          marker[nind[k]]++;
        }
      }
    }
    
    for(unsigned int j = 0; j < l; j++){
      if(marker[nbrs[j]] >= graph.element(i)->numCommonNodesInDualGraph(graph.element(nbrs[j]))){
        graph.adjncy(graph.xadj(i), nbrs[j]);
        graph.xadj(i, graph.xadj(i)+1);
      }
      marker[nbrs[j]] = 0;
      nbrs[j] = 0;
    }
  }
  delete[] nbrs;
  delete[] marker;
  
  for(unsigned int i = graph.ne(); i > 0; i--) graph.xadj(i, graph.xadj(i-1));
  graph.xadj(0, 0);
  
  delete[] nptr;
  delete[] nind;
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

#ifdef HAVE_CXX11
void CreateNewEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition)
#else
void CreateNewEntities(GModel *const model, std::map<MElement*, unsigned int> &elmToPartition)
#endif
{
  std::set<GRegion*, GEntityLessThan> regions = model->getGRegions();
  std::set<GFace*, GEntityLessThan> faces = model->getGFaces();
  std::set<GEdge*, GEntityLessThan> edges = model->getGEdges();
  std::set<GVertex*, GEntityLessThan> vertices = model->getGVertices();
  
  for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it){
    std::vector<GRegion *> newRegions(model->getNumPartitions(), NULL);
    
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->prisms.begin(), (*it)->prisms.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->pyramids.begin(), (*it)->pyramids.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->trihedra.begin(), (*it)->trihedra.end());
    
    for(unsigned int i = 0; i < model->getNumPartitions(); i++){
      if(newRegions[i] != NULL){
        static_cast<partitionRegion*>(newRegions[i])->setParentEntity(*it);
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++)
        {
          newRegions[i]->addPhysicalEntity(physicalEntities[j]);
        }
      }
    }
    
    (*it)->mesh_vertices.clear();
    
    (*it)->tetrahedra.clear();
    (*it)->hexahedra.clear();
    (*it)->prisms.clear();
    (*it)->pyramids.clear();
    (*it)->trihedra.clear();
  }
  
  
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it){
    std::vector<GFace *> newFaces(model->getNumPartitions(), NULL);
    
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->triangles.begin(), (*it)->triangles.end());
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
    
    for(unsigned int i = 0; i < model->getNumPartitions(); i++){
      if(newFaces[i] != NULL){
        static_cast<partitionFace*>(newFaces[i])->setParentEntity(*it);
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++){
          newFaces[i]->addPhysicalEntity(physicalEntities[j]);
        }
      }
    }

    (*it)->mesh_vertices.clear();
    
    (*it)->triangles.clear();
    (*it)->quadrangles.clear();
  }
  
  
  for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it){
    std::vector<GEdge *> newEdges(model->getNumPartitions(), NULL);
    
    assignElementsToEntities(model, elmToPartition, newEdges, (*it)->lines.begin(), (*it)->lines.end());
    
    for(unsigned int i = 0; i < model->getNumPartitions(); i++){
      if(newEdges[i] != NULL){
        static_cast<partitionEdge*>(newEdges[i])->setParentEntity(*it);
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++){
          newEdges[i]->addPhysicalEntity(physicalEntities[j]);
        }
      }
    }

    (*it)->mesh_vertices.clear();
    
    (*it)->lines.clear();
  }
  
  
  for(GModel::const_viter it = vertices.begin(); it != vertices.end(); ++it){
    std::vector<GVertex *> newVertices(model->getNumPartitions(), NULL);
    
    assignElementsToEntities(model, elmToPartition, newVertices, (*it)->points.begin(), (*it)->points.end());
    
    for(unsigned int i = 0; i < model->getNumPartitions(); i++){
      if(newVertices[i] != NULL){
        static_cast<partitionVertex*>(newVertices[i])->setParentEntity((*it));
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++){
          newVertices[i]->addPhysicalEntity(physicalEntities[j]);
        }
      }
    }

    (*it)->mesh_vertices.clear();
    
    (*it)->points.clear();
  }
  
  /*********
   *
   *   Divided the non connected entities
   *
   *********/
  regions = model->getGRegions();
  faces = model->getGFaces();
  edges = model->getGEdges();
  vertices = model->getGVertices();
  
  //Loop over vertices
  for(GModel::const_viter it = vertices.begin(); it != vertices.end(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionVertex){
      partitionVertex* vertex = static_cast<partitionVertex*>(*it);
      
      if(vertex->getNumMeshElements() > 1){
        for(unsigned int i = 0; i < vertex->getNumMeshElements(); i++){
          //Create the new partitionVertex
          partitionVertex *pvertex = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, vertex->getPartitions());
          //Assign physicals and parent entity
          std::vector<int> physicalTags = vertex->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++){
            pvertex->addPhysicalEntity(physicalTags[j]);
          }
          pvertex->setParentEntity(vertex->getParentEntity());
          //Add to model
          model->add(pvertex);
          //Add elements
          pvertex->addElement(vertex->getMeshElement(i)->getType(), vertex->getMeshElement(i));
        }
        
        model->remove(vertex);
        vertex->points.clear();
        vertex->mesh_vertices.clear();
        delete vertex;
      }
    }
  }
  
  //Loop over edges
  for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionCurve){
      partitionEdge* edge = static_cast<partitionEdge*>(*it);
      AssignMeshVerticesToEntity(edge, false);
      
      //We build a graph
      Graph graph;
      graph.ne(edge->getNumMeshElements());
      graph.nn(edge->getNumMeshVertices());
      graph.dim(1);
      graph.elementResize(graph.ne());
      graph.vertexResize(model->getMaxVertexNumber());
      graph.eptrResize(graph.ne()+1);
      graph.eptr(0,0);
      const int eindSize = getSizeOfEind(edge);
      graph.eindResize(eindSize);
      
      int eptrIndex = 0;
      int eindIndex = 0;
      int numVertex = 0;
      
      fillElementsToNodesMap(graph, edge, eptrIndex, eindIndex, numVertex, edge->lines.begin(), edge->lines.end());
      createDualGraph(graph);
      
      std::vector< std::set<MElement*> > connectedElements;
      fillConnectedElements(connectedElements, graph);
      graph.clear();
      
      if(connectedElements.size() > 1){
        for(unsigned int i = 0; i < connectedElements.size(); i++){
          //Create the new partitionEdge
          partitionEdge *pedge = new partitionEdge(model, model->getMaxElementaryNumber(1)+1, NULL, NULL, edge->getPartitions());
          //Assign physicals and parent entity
          std::vector<int> physicalTags = edge->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++){
            pedge->addPhysicalEntity(physicalTags[j]);
          }
          pedge->setParentEntity(edge->getParentEntity());
          //Add to model
          model->add(pedge);
          for(std::set<MElement*>::iterator itSet = connectedElements[i].begin(); itSet != connectedElements[i].end(); ++itSet){
            //Add elements
            pedge->addElement((*itSet)->getType() ,(*itSet));
          }
        }
        
        model->remove(edge);
        edge->lines.clear();
        edge->mesh_vertices.clear();
        delete edge;
      }
      
      connectedElements.clear();
    }
  }
  
  //Loop over faces
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionSurface){
      partitionFace* face = static_cast<partitionFace*>(*it);
      AssignMeshVerticesToEntity(face, false);
      
      //We build a graph
      Graph graph;
      graph.ne(face->getNumMeshElements());
      graph.nn(face->getNumMeshVertices());
      graph.dim(1);
      graph.elementResize(graph.ne());
      graph.vertexResize(model->getMaxVertexNumber());
      graph.eptrResize(graph.ne()+1);
      graph.eptr(0,0);
      const int eindSize = getSizeOfEind(face);
      graph.eindResize(eindSize);
      
      int eptrIndex = 0;
      int eindIndex = 0;
      int numVertex = 0;
      
      fillElementsToNodesMap(graph, face, eptrIndex, eindIndex, numVertex, face->triangles.begin(), face->triangles.end());
      fillElementsToNodesMap(graph, face, eptrIndex, eindIndex, numVertex, face->quadrangles.begin(), face->quadrangles.end());
      createDualGraph(graph);
      
      std::vector< std::set<MElement*> > connectedElements;
      fillConnectedElements(connectedElements, graph);
      graph.clear();
      
      if(connectedElements.size() > 1){
        for(unsigned int i = 0; i < connectedElements.size(); i++){
          //Create the new partitionFace
          partitionFace *pface = new partitionFace(model, model->getMaxElementaryNumber(2)+1, face->getPartitions());
          //Assign physicals and parent entity
          std::vector<int> physicalTags = face->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++){
            pface->addPhysicalEntity(physicalTags[j]);
          }
          pface->setParentEntity(face->getParentEntity());
          //Add to model
          model->add(pface);
          for(std::set<MElement*>::iterator itSet = connectedElements[i].begin(); itSet != connectedElements[i].end(); ++itSet){
            //Add elements
            pface->addElement((*itSet)->getType() ,(*itSet));
          }
        }
        
        model->remove(face);
        face->triangles.clear();
        face->quadrangles.clear();
        face->mesh_vertices.clear();
        delete face;
      }
      
      connectedElements.clear();
    }
  }
  
  //Loop over regions
  for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionVolume){
      partitionRegion* region = static_cast<partitionRegion*>(*it);
      AssignMeshVerticesToEntity(region, false);
      
      //We build a graph
      Graph graph;
      graph.ne(region->getNumMeshElements());
      graph.nn(region->getNumMeshVertices());
      graph.dim(1);
      graph.elementResize(graph.ne());
      graph.vertexResize(model->getMaxVertexNumber());
      graph.eptrResize(graph.ne()+1);
      graph.eptr(0,0);
      const int eindSize = getSizeOfEind(region);
      graph.eindResize(eindSize);
      
      int eptrIndex = 0;
      int eindIndex = 0;
      int numVertex = 0;
      
      fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex, region->tetrahedra.begin(), region->tetrahedra.end());
      fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex, region->hexahedra.begin(), region->hexahedra.end());
      fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex, region->prisms.begin(), region->prisms.end());
      fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex, region->pyramids.begin(), region->pyramids.end());
      fillElementsToNodesMap(graph, region, eptrIndex, eindIndex, numVertex, region->trihedra.begin(), region->trihedra.end());
      createDualGraph(graph);
      
      std::vector< std::set<MElement*> > connectedElements;
      fillConnectedElements(connectedElements, graph);
      graph.clear();
      
      if(connectedElements.size() > 1){
        for(unsigned int i = 0; i < connectedElements.size(); i++){
          //Create the new partitionRegion
          partitionRegion *pregion = new partitionRegion(model, model->getMaxElementaryNumber(3)+1, region->getPartitions());
          //Assign physicals and parent entity
          std::vector<int> physicalTags = (*it)->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++){
            pregion->addPhysicalEntity(physicalTags[j]);
          }
          pregion->setParentEntity(region->getParentEntity());
          //Add to model
          model->add(pregion);
          for(std::set<MElement*>::iterator itSet = connectedElements[i].begin(); itSet != connectedElements[i].end(); ++itSet){
            //Add elements
            pregion->addElement((*itSet)->getType() ,(*itSet));
          }
        }
        
        model->remove(region);
        region->tetrahedra.clear();
        region->hexahedra.clear();
        region->prisms.clear();
        region->pyramids.clear();
        region->trihedra.clear();
        region->mesh_vertices.clear();
        delete region;
      }
      
      connectedElements.clear();
    }
  }
}

template <class ITERATOR>
#ifdef HAVE_CXX11
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GRegion *> &newRegions, ITERATOR it_beg, ITERATOR it_end)
#else
void assignElementsToEntities(GModel *const model, std::map<MElement*, unsigned int> &elmToPartition, std::vector<GRegion *> &newRegions, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    const unsigned int partition = elmToPartition[(*it)]-1;
    
    if(newRegions[partition] == NULL){
      std::vector<unsigned int> partitions;
      partitions.push_back(partition);
      partitionRegion *dr = new partitionRegion(model, model->getMaxElementaryNumber(3)+1, partitions);
      model->add(dr);
      newRegions[partition] = dr;
    }
    
    newRegions[partition]->addElement((*it)->getType(), *it);
  }
}

template <class ITERATOR>
#ifdef HAVE_CXX11
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GFace *> &newFaces, ITERATOR it_beg, ITERATOR it_end)
#else
void assignElementsToEntities(GModel *const model, std::map<MElement*, unsigned int> &elmToPartition, std::vector<GFace *> &newFaces, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    const unsigned int partition = elmToPartition[(*it)]-1;
    
    if(newFaces[partition] == NULL){
      std::vector<unsigned int> partitions;
      partitions.push_back(partition);
      partitionFace *df = new partitionFace(model, model->getMaxElementaryNumber(2)+1, partitions);
      model->add(df);
      newFaces[partition] = df;
    }
    
    newFaces[partition]->addElement((*it)->getType(), *it);
  }
}

template <class ITERATOR>
#ifdef HAVE_CXX11
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GEdge *> &newEdges, ITERATOR it_beg, ITERATOR it_end)
#else
void assignElementsToEntities(GModel *const model, std::map<MElement*, unsigned int> &elmToPartition, std::vector<GEdge *> &newEdges, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    const unsigned int partition = elmToPartition[(*it)]-1;
    
    if(newEdges[partition] == NULL){
      std::vector<unsigned int> partitions;
      partitions.push_back(partition);
      partitionEdge *de = new partitionEdge(model, model->getMaxElementaryNumber(1)+1, NULL, NULL, partitions);
      model->add(de);
      newEdges[partition] = de;
    }
    
    newEdges[partition]->addLine(reinterpret_cast<MLine*>(*it));
  }
}

template <class ITERATOR>
#ifdef HAVE_CXX11
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned int> &elmToPartition, std::vector<GVertex *> &newVertices, ITERATOR it_beg, ITERATOR it_end)
#else
void assignElementsToEntities(GModel *const model, std::map<MElement*, unsigned int> &elmToPartition, std::vector<GVertex *> &newVertices, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    const unsigned int partition = elmToPartition[(*it)]-1;
    
    if(newVertices[partition] == NULL){
      std::vector<unsigned int> partitions;
      partitions.push_back(partition);
      partitionVertex *dv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
      model->add(dv);
      newVertices[partition] = dv;
    }
    
    newVertices[partition]->addPoint(reinterpret_cast<MPoint*>(*it));
  }
}

void fillConnectedElements(std::vector< std::set<MElement*> > &connectedElements, Graph &graph)
{
  std::stack<unsigned int> elementStack;
  std::set<MElement*> elements;
  int startElement = 0;
  bool stop = true;
  
  do {
    //Inititalization
    elementStack.push(startElement);
    elements.insert(graph.element(startElement));
    
    while(elementStack.size() != 0){
      unsigned int top = elementStack.top();
      elementStack.pop();
      
      for(unsigned int i = graph.xadj(top); i < graph.xadj(top+1); i++){
        if(graph.adjncy(i) != 0){
          elementStack.push(graph.adjncy(i));
          elements.insert(graph.element(graph.adjncy(i)));
          graph.adjncy(i,0);
        }
      }
    }
    connectedElements.push_back(elements);
    elements.clear();
    
    stop = true;
    for(unsigned int i = 0; i < graph.ne(); i++){
      for(unsigned int j = graph.xadj(i); j < graph.xadj(i+1); j++){
        if(graph.adjncy(j) != 0){
          startElement = i;
          stop = false;
          break;
        }
      }
      if(!stop) break;
    }
    break;
  } while(!stop);
}


/*******************************************************************************
 *
 * Routines CreatePartitionBoundaries
 *
 * Purpose
 * =======
 *
 *   Create the new entities between each partitions (sigma and bndSigma).
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

void CreatePartitionBoundaries(GModel *const model, const std::vector< std::set<MElement*> > &boundaryElements)
{
  const int meshDim = model->getDim();
  std::map<MElement*, GEntity*> elementToEntity;
  fillElementToEntity(model, elementToEntity);
    
  std::multimap<partitionFace*, GEntity*, Less_partitionFace> pfaces;
  std::multimap<partitionEdge*, GEntity*, Less_partitionEdge> pedges;
  std::multimap<partitionVertex*, GEntity*, Less_partitionVertex> pvertices;

#ifdef HAVE_CXX11
  std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Face, Equal_Face> faceToElement;
  std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Edge, Equal_Edge> edgeToElement;
  std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > > vertexToElement;
#else
  std::map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Less_Face> faceToElement;
  std::map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Less_Edge> edgeToElement;
  std::map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > > vertexToElement;
#endif
  
  if (meshDim >= 3){//Create partition faces
    Msg::Info("Creating partition faces... ");

    for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
      if((*it)->geomType() == GEntity::PartitionVolume){
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->getPartitions(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->getPartitions(), (*it)->hexahedra.begin(), (*it)->hexahedra.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->getPartitions(), (*it)->prisms.begin(), (*it)->prisms.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->getPartitions(), (*it)->pyramids.begin(), (*it)->pyramids.end());
        fillit_(faceToElement, static_cast<partitionRegion*>(*it)->getPartitions(), (*it)->trihedra.begin(), (*it)->trihedra.end());
      }
    }

#ifdef HAVE_CXX11
    for(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Face, Equal_Face>::const_iterator it = faceToElement.begin(); it != faceToElement.end(); ++it){
#else
    for(std::map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Less_Face>::const_iterator it = faceToElement.begin(); it != faceToElement.end(); ++it){
#endif
      MFace f = it->first;

      std::vector<unsigned int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second);
      if(reference == NULL) continue;
      
      assignPartitionBoundary(model, f, reference, partitions, pfaces, elementToEntity);
    }
    faceToElement.clear();
  }
  
  if (meshDim >= 2){//Create partition edges
    Msg::Info("Creating partition edges... ");
   
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
      if((*it)->geomType() == GEntity::PartitionSurface){
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->getPartitions(), (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(edgeToElement, static_cast<partitionFace*>(*it)->getPartitions(), (*it)->quadrangles.begin(), (*it)->quadrangles.end());
      }
    }
#ifdef HAVE_CXX11
    for(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it){
#else
    for(std::map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Less_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it){
#endif
      MEdge e = it->first;
      
      std::vector<unsigned int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second);
      if(reference == NULL) continue;
      
      assignPartitionBoundary(model, e, reference, partitions, pedges, elementToEntity);
    }
    edgeToElement.clear();
  }
  
  if (meshDim >= 1){//Create partition vertices
    Msg::Info("Creating partition vertices... ");
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
      if((*it)->geomType() == GEntity::PartitionCurve){
        fillit_(vertexToElement, static_cast<partitionEdge*>(*it)->getPartitions(), (*it)->lines.begin(), (*it)->lines.end());
      }
    }
#ifdef HAVE_CXX11
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it){
#else
    for(std::map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it){
#endif
      MVertex *v = it->first;
      
      std::vector<unsigned int> partitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second);//it->second[0].first; //getReferenceElement(it->second);
      if(reference == NULL) continue;
      
      assignPartitionBoundary(model, v, reference, partitions, pvertices, elementToEntity);
    }
    vertexToElement.clear();
  }
}

void fillElementToEntity(GModel *const model, std::map<MElement*, GEntity*> &elmToEntity)
{
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
    for(std::vector<MTetrahedron*>::iterator itElm = (*it)->tetrahedra.begin(); itElm != (*it)->tetrahedra.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
    for(std::vector<MHexahedron*>::iterator itElm = (*it)->hexahedra.begin(); itElm != (*it)->hexahedra.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
    for(std::vector<MPrism*>::iterator itElm = (*it)->prisms.begin(); itElm != (*it)->prisms.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
    for(std::vector<MPyramid*>::iterator itElm = (*it)->pyramids.begin(); itElm != (*it)->pyramids.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
    for(std::vector<MTrihedron*>::iterator itElm = (*it)->trihedra.begin(); itElm != (*it)->trihedra.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
    for(std::vector<MTriangle*>::iterator itElm = (*it)->triangles.begin(); itElm != (*it)->triangles.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
    for(std::vector<MQuadrangle*>::iterator itElm = (*it)->quadrangles.begin(); itElm != (*it)->quadrangles.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    for(std::vector<MLine*>::iterator itElm = (*it)->lines.begin(); itElm != (*it)->lines.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
    for(std::vector<MPoint*>::iterator itElm = (*it)->points.begin(); itElm != (*it)->points.end(); ++itElm)
      elmToEntity.insert(std::pair<MElement*, GEntity*>(*itElm, *it));
  }
}

MElement* getReferenceElement(const std::vector< std::pair<MElement*, std::vector<unsigned int> > > &elementPairs)
{
  unsigned int min = std::numeric_limits<unsigned int>::max();
  std::vector< std::pair<MElement*, std::vector<unsigned int> > > minSizeElementPairs;
  std::vector< std::pair<MElement*, std::vector<unsigned int> > > minSizeElementPairsTmp;
  
  //Take only the elements having the less partition in commun.
  //For exemple we take (1,2) and (3,8) but not (2,5,9) or (1,4,5,7)
  for(unsigned int i = 0; i < elementPairs.size(); i++){
    if(min > elementPairs[i].second.size()){
      minSizeElementPairs.clear();
      min = elementPairs[i].second.size();
      minSizeElementPairs.push_back(elementPairs[i]);
    }
    else if(min == elementPairs[i].second.size()){
      minSizeElementPairs.push_back(elementPairs[i]);
    }
  }
  
  //Check if the element separated different partitions
  if(minSizeElementPairs.size() == elementPairs.size()){
    bool isEqual = true;
    for(unsigned int i = 1; i < minSizeElementPairs.size(); i++){
      if(minSizeElementPairs[i].second != minSizeElementPairs[0].second){
        isEqual = false;
        break;
      }
    }
    if(isEqual) return NULL;
  }
  
  while(minSizeElementPairs.size() > 1){
    min = std::numeric_limits<unsigned int>::max();
    for(unsigned int i = 0; i < minSizeElementPairs.size(); i++){
      //The partition vector is sorted thus we can check only the first element
      if(minSizeElementPairs[i].second.size() == 0) return minSizeElementPairs[0].first;
      if(min > minSizeElementPairs[i].second[0]){
        min = minSizeElementPairs[i].second[0];
      }
    }
    
    for(unsigned int i = 0; i < minSizeElementPairs.size(); i++){
      if(min == minSizeElementPairs[i].second[0]){
        minSizeElementPairs[i].second.erase(minSizeElementPairs[i].second.begin());
        minSizeElementPairsTmp.push_back(minSizeElementPairs[i]);
      }
    }
    minSizeElementPairs.clear();
#ifdef HAVE_CXX11
    minSizeElementPairs = std::move(minSizeElementPairsTmp);
#else
    minSizeElementPairs = minSizeElementPairsTmp;
#endif
  }
  
  return minSizeElementPairs[0].first;
}

void getPartitionInVector(std::vector<unsigned int> &partitions, const std::vector< std::pair<MElement*, std::vector<unsigned int> > > &boundaryPair)
{
  for(unsigned int i = 0; i < boundaryPair.size(); i++){
    for(unsigned int j = 0; j < boundaryPair[i].second.size(); j++){
      if(std::find(partitions.begin(), partitions.end(), boundaryPair[i].second[j]) == partitions.end()){
        partitions.push_back(boundaryPair[i].second[j]);
      }
    }
  }
  
  std::sort(partitions.begin(), partitions.end());
}

#ifdef HAVE_CXX11
template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Hash_Face, Equal_Face> &faceToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end)
#else
template <class ITERATOR>
void fillit_(std::map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned int> > >, Less_Face> &faceToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for (ITERATOR it = it_beg; it != it_end ; ++it){
    for(unsigned int i = 0; i < (*it)->getNumFaces(); i++){
      faceToElement[(*it)->getFace(i)].push_back(std::pair<MElement*, std::vector<unsigned int> >(*it,partitions));
    }
  }
}


#ifdef HAVE_CXX11
template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > > , Hash_Edge, Equal_Edge> &edgeToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end)
#else
template <class ITERATOR>
void fillit_(std::map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned int> > > , Less_Edge> &edgeToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for (ITERATOR it = it_beg; it != it_end; ++it){
    for(unsigned int i = 0; i < (*it)->getNumEdges(); i++){
      edgeToElement[(*it)->getEdge(i)].push_back(std::pair<MElement*, std::vector<unsigned int> >(*it,partitions));
    }
  }
}

#ifdef HAVE_CXX11
template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > > &vertexToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end)
#else
template <class ITERATOR>
void fillit_(std::map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned int> > > > &vertexToElement, const std::vector<unsigned int> &partitions, ITERATOR it_beg, ITERATOR it_end)
#endif
{
  for (ITERATOR it = it_beg; it != it_end ; ++it){
    for(unsigned int i = 0; i < (*it)->getNumPrimaryVertices(); i++){
      vertexToElement[(*it)->getVertex(i)].push_back(std::pair<MElement*, std::vector<unsigned int> >(*it,partitions));
    }
  }
}

void assignPartitionBoundary(GModel *const model, MFace &me, MElement* reference, std::vector<unsigned int> partitions, std::multimap<partitionFace*, GEntity*, Less_partitionFace> &pfaces, std::map<MElement*, GEntity*> &elementToEntity)
{
  partitionFace pf(model, 1, partitions);
  std::pair< std::multimap<partitionFace*, GEntity*, Less_partitionFace>::iterator , std::multimap<partitionFace*, GEntity*, Less_partitionFace>::iterator> ret = pfaces.equal_range(&pf);
  
  partitionFace *ppf = NULL;
  //Create the new partition entity for the mesh
  if(ret.first == ret.second){
    //Create new entity and add them to the model
    ppf = new partitionFace(model, model->getMaxElementaryNumber(2)+1, partitions);
    pfaces.insert(std::pair<partitionFace*, GEntity*>(ppf, elementToEntity[reference]));
    model->add(ppf);
  }
  else{
    for(std::multimap<partitionFace*, GEntity*, Less_partitionFace>::iterator it = ret.first; it != ret.second; ++it){
      if(elementToEntity[reference] == (*it).second){
        ppf = (*it).first;
      }
    }
    if(ppf == NULL){
      //Create new entity and add them to the model
      ppf = new partitionFace(model, model->getMaxElementaryNumber(2)+1, partitions);
      pfaces.insert(std::pair<partitionFace*, GEntity*>(ppf, elementToEntity[reference]));
      model->add(ppf);
    }
  }
  
  int numFace = 0;
  for(unsigned int i = 0; i < reference->getNumFaces(); i++){
    if(reference->getFace(i) == me){
      numFace = i;
      break;
    }
  }
  
  if(me.getNumVertices() == 3){
    std::vector<MVertex*> verts;
    reference->getFaceVertices(numFace, verts);
    
    if(verts.size() == 3){
      MTriangle *element = new MTriangle(verts);
      static_cast<GFace*>(ppf)->addTriangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    else if(verts.size() == 6){
      MTriangle6 *element = new MTriangle6(verts);
      static_cast<GFace*>(ppf)->addTriangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    else{
      MTriangleN *element = new MTriangleN(verts, verts[0]->getPolynomialOrder());
      static_cast<GFace*>(ppf)->addTriangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    
    for(unsigned int i = 0; i < verts.size(); i++) ppf->addMeshVertex(verts[i]);
  }
  else if(me.getNumVertices() == 4){
    std::vector<MVertex*> verts;
    reference->getFaceVertices(numFace, verts);
    
    if(verts.size() == 4){
      MQuadrangle *element = new MQuadrangle(verts);
      ppf->addQuadrangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    else if(verts.size() == 8){
      MQuadrangle8 *element = new MQuadrangle8(verts);
      ppf->addQuadrangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    else if(verts.size() == 9){
      MQuadrangle9 *element = new MQuadrangle9(verts);
      ppf->addQuadrangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    else{
      MQuadrangleN *element = new MQuadrangleN(verts, verts[0]->getPolynomialOrder());
      ppf->addQuadrangle(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppf));
    }
    
    for(unsigned int i = 0; i < verts.size(); i++) ppf->addMeshVertex(verts[i]);
  }
}

void assignPartitionBoundary(GModel *const model, MEdge &me, MElement* reference, std::vector<unsigned int> partitions, std::multimap<partitionEdge*, GEntity*, Less_partitionEdge> &pedges, std::map<MElement*, GEntity*> &elementToEntity)
{
  partitionEdge pe(model, 1, NULL, NULL, partitions);
  std::pair< std::multimap<partitionEdge*, GEntity*, Less_partitionEdge>::iterator , std::multimap<partitionEdge*, GEntity*, Less_partitionEdge>::iterator> ret = pedges.equal_range(&pe);
  
  partitionEdge *ppe = NULL;
  //Create the new partition entity for the mesh
  if(ret.first == ret.second){
    //Create new entity and add them to the model
    ppe = new partitionEdge(model, model->getMaxElementaryNumber(1)+1, 0, 0, partitions);
    pedges.insert(std::pair<partitionEdge*, GEntity*>(ppe, elementToEntity[reference]));
    model->add(ppe);
  }
  else{
    for(std::multimap<partitionEdge*, GEntity*, Less_partitionEdge>::iterator it = ret.first; it != ret.second; ++it){
      if(elementToEntity[reference] == (*it).second){
        ppe = (*it).first;
      }
    }
    if(ppe == NULL){
      //Create new entity and add them to the model
      ppe = new partitionEdge(model, model->getMaxElementaryNumber(1)+1, 0, 0, partitions);
      pedges.insert(std::pair<partitionEdge*, GEntity*>(ppe, elementToEntity[reference]));
      model->add(ppe);
    }
  }
  
  int numEdge = 0;
  for(unsigned int i = 0; i < reference->getNumEdges(); i++){
    if(reference->getEdge(i) == me){
      numEdge = i;
      break;
    }
  }
  
  if(me.getNumVertices() == 2){
    std::vector<MVertex*> verts;
    reference->getEdgeVertices(numEdge, verts);
    
    if(verts.size() == 2){
      MLine *element = new MLine(verts);
      ppe->addLine(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppe));
    }
    else if(verts.size() == 3){
      MLine3 *element = new MLine3(verts);
      ppe->addLine(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppe));
    }
    else{
      MLineN *element = new MLineN(verts);
      ppe->addLine(element);
      elementToEntity.insert(std::pair<MElement*, GEntity*>(element, ppe));
    }
    
    for(unsigned int i = 0; i < verts.size(); i++) ppe->addMeshVertex(verts[i]);
  }
}

void assignPartitionBoundary(GModel *const model, MVertex *ve, MElement* reference, std::vector<unsigned int> partitions, std::multimap<partitionVertex*, GEntity*, Less_partitionVertex> &pvertices, std::map<MElement*, GEntity*> &elementToEntity)
{
  partitionVertex pv(model, 1, partitions);
  std::pair< std::multimap<partitionVertex*, GEntity*, Less_partitionVertex>::iterator , std::multimap<partitionVertex*, GEntity*, Less_partitionVertex>::iterator > ret = pvertices.equal_range(&pv);
  
  partitionVertex *ppv = NULL;
  //Create the new partition entity for the mesh
  if(ret.first == ret.second){
    ppv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
    pvertices.insert(std::pair<partitionVertex*, GEntity*>(ppv, elementToEntity[reference]));
    model->add(ppv);
  }
  else{
    for(std::multimap<partitionVertex*, GEntity*, Less_partitionVertex>::iterator it = ret.first; it != ret.second; ++it){
      if(elementToEntity[reference] == (*it).second){
        ppv = (*it).first;
      }
    }
    if(ppv == NULL){
      //Create new entity and add them to the model
      ppv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
      pvertices.insert(std::pair<partitionVertex*, GEntity*>(ppv, elementToEntity[reference]));
      model->add(ppv);
    }
  }
  
  ppv->addPoint(new MPoint(ve));
  ppv->addMeshVertex(ve);
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

void AssignMeshVertices(GModel *model, int dim, bool inAllDim)
{
  //Loop over vertices
  if(dim == 0 || dim == -1){
    for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++){
        for(unsigned int j = 0; j < (*it)->getMeshElement(i)->getNumVertices(); j++){
          (*it)->getMeshElement(i)->getVertex(j)->setEntity(NULL);
        }
      }
      (*it)->mesh_vertices.clear();
    }
  }
  
  //Loop over edges
  if(dim == 1 || dim == -1){
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++){
        for(unsigned int j = 0; j < (*it)->getMeshElement(i)->getNumVertices(); j++){
          (*it)->getMeshElement(i)->getVertex(j)->setEntity(NULL);
        }
      }
      (*it)->mesh_vertices.clear();
    }
  }
  
  //Loop over faces
  if(dim == 2 || dim == -1){
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++){
        for(unsigned int j = 0; j < (*it)->getMeshElement(i)->getNumVertices(); j++){
          (*it)->getMeshElement(i)->getVertex(j)->setEntity(NULL);
        }
      }
      (*it)->mesh_vertices.clear();
    }
  }
  
  //Loop over regions
  if(dim == 3 || dim == -1){
    for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
      for(unsigned int i = 0; i < (*it)->getNumMeshElements(); i++){
        for(unsigned int j = 0; j < (*it)->getMeshElement(i)->getNumVertices(); j++){
          (*it)->getMeshElement(i)->getVertex(j)->setEntity(NULL);
        }
      }
      (*it)->mesh_vertices.clear();
    }
  }
  
  //*********************************
  
  //Loop over vertices
  if(dim == 0 || dim == -1){
    for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
      setVerticesToEntity(*it, (*it)->points.begin(), (*it)->points.end(), inAllDim);
    }
  }
  
  //Loop over edges
  if(dim == 1 || dim == -1){
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
      setVerticesToEntity(*it, (*it)->lines.begin(), (*it)->lines.end(), inAllDim);
    }
  }
  
  //Loop over faces
  if(dim == 2 || dim == -1){
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
      setVerticesToEntity(*it, (*it)->triangles.begin(), (*it)->triangles.end(), inAllDim);
      setVerticesToEntity(*it, (*it)->quadrangles.begin(), (*it)->quadrangles.end(), inAllDim);
    }
  }
    
  //Loop over regions
  if(dim == 3 || dim == -1){
    for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
      setVerticesToEntity(*it, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end(), inAllDim);
      setVerticesToEntity(*it, (*it)->hexahedra.begin(), (*it)->hexahedra.end(), inAllDim);
      setVerticesToEntity(*it, (*it)->prisms.begin(), (*it)->prisms.end(), inAllDim);
      setVerticesToEntity(*it, (*it)->pyramids.begin(), (*it)->pyramids.end(), inAllDim);
      setVerticesToEntity(*it, (*it)->trihedra.begin(), (*it)->trihedra.end(), inAllDim);
    }
  }
}

void AssignMeshVerticesToEntity(GEntity *entity, bool inAllDim)
{
  for(unsigned int i = 0; i < entity->getNumMeshElements(); i++){
    for(unsigned int j = 0; j < entity->getMeshElement(i)->getNumVertices(); j++){
      entity->getMeshElement(i)->getVertex(j)->setEntity(NULL);
    }
  }
  entity->mesh_vertices.clear();
  
  switch (entity->dim()) {
    case 0:
      setVerticesToEntity(entity, static_cast<GVertex*>(entity)->points.begin(), static_cast<GVertex*>(entity)->points.end(), inAllDim);
      break;
    case 1:
      setVerticesToEntity(entity, static_cast<GEdge*>(entity)->lines.begin(), static_cast<GEdge*>(entity)->lines.end(), inAllDim);
      break;
    case 2:
      setVerticesToEntity(entity, static_cast<GFace*>(entity)->triangles.begin(), static_cast<GFace*>(entity)->triangles.end(), inAllDim);
      setVerticesToEntity(entity, static_cast<GFace*>(entity)->quadrangles.begin(), static_cast<GFace*>(entity)->quadrangles.end(), inAllDim);
      break;
    case 3:
      setVerticesToEntity(entity, static_cast<GRegion*>(entity)->tetrahedra.begin(), static_cast<GRegion*>(entity)->tetrahedra.end(), inAllDim);
      setVerticesToEntity(entity, static_cast<GRegion*>(entity)->hexahedra.begin(), static_cast<GRegion*>(entity)->hexahedra.end(), inAllDim);
      setVerticesToEntity(entity, static_cast<GRegion*>(entity)->prisms.begin(), static_cast<GRegion*>(entity)->prisms.end(), inAllDim);
      setVerticesToEntity(entity, static_cast<GRegion*>(entity)->pyramids.begin(), static_cast<GRegion*>(entity)->pyramids.end(), inAllDim);
      setVerticesToEntity(entity, static_cast<GRegion*>(entity)->trihedra.begin(), static_cast<GRegion*>(entity)->trihedra.end(), inAllDim);
      break;
    default:
      break;
  }
}

template <class ITERATOR>
void setVerticesToEntity(GEntity *const entity, ITERATOR it_beg, ITERATOR it_end, bool inAllDim)
{
  for(ITERATOR it = it_beg; it != it_end; ++it){
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++){
      if((*it)->getVertex(i)->onWhat() == NULL){
        (*it)->getVertex(i)->setEntity(entity);
        entity->addMeshVertex((*it)->getVertex(i));
      }
      else{
        if(inAllDim) entity->addMeshVertex((*it)->getVertex(i));
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
 *                        0 = success
 *                        1 = error
 *
 *
 ******************************************************************************/

// Todo : Adapt the output file to Omega, Sigma, Tau, Upsilon, ...

int CreateTopologyFile(GModel* model, std::string name)
{
  std::multimap<unsigned int, GEntity*> omega;
  std::multimap<unsigned int, GEntity*> sigma;
  std::multimap<unsigned int, GEntity*> tau;
  std::multimap<unsigned int, GEntity*> upsilon;
  std::multimap<unsigned int, GEntity*> omicron;
  std::multimap<unsigned int, GEntity*> omicronSigma;
  std::multimap<unsigned int, GEntity*> omicronTau;
  
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    switch(entities[i]->geomType()){
      case GEntity::PartitionVolume: {
        std::string substr  = getSubstr(model, entities[i]);
        if(substr == "_omega"){
          for(unsigned int j = 0; j < static_cast<partitionRegion*>(entities[i])->numPartitions(); j++){
            omega.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionRegion*>(entities[i])->getPartition(j), entities[i]));
          }
        }
      }
        break;
      case GEntity::PartitionSurface: {
        std::string substr  = getSubstr(model, entities[i]);
        if(substr == "_omega"){
          for(unsigned int j = 0; j < static_cast<partitionFace*>(entities[i])->numPartitions(); j++){
            omega.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionFace*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_sigma"){
          for(unsigned int j = 0; j < static_cast<partitionFace*>(entities[i])->numPartitions(); j++){
            sigma.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionFace*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_omicron"){
          for(unsigned int j = 0; j < static_cast<partitionFace*>(entities[i])->numPartitions(); j++){
            omicron.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionFace*>(entities[i])->getPartition(j), entities[i]));
          }
        }
      }
        break;
      case GEntity::PartitionCurve: {
        std::string substr  = getSubstr(model, entities[i]);
        if(substr == "_omega"){
          for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->numPartitions(); j++){
            omega.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionEdge*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_sigma"){
          for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->numPartitions(); j++){
            sigma.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionEdge*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_tau"){
          for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->numPartitions(); j++){
            tau.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionEdge*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_omicron"){
          for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->numPartitions(); j++){
            omicron.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionEdge*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_omicronSigma"){
          for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->numPartitions(); j++){
            omicronSigma.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionEdge*>(entities[i])->getPartition(j), entities[i]));
          }
        }
      }
        break;
      case GEntity::PartitionVertex: {
        std::string substr  = getSubstr(model, entities[i]);
        if(substr == "_omega"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            omega.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_sigma"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            sigma.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_tau"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            tau.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_upsilon"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            upsilon.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_omicron"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            omicron.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_omicronSigma"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            omicronSigma.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
        else if(substr == "_omicronTau"){
          for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->numPartitions(); j++){
            omicronTau.insert(std::pair<unsigned int, GEntity*>(static_cast<partitionVertex*>(entities[i])->getPartition(j), entities[i]));
          }
        }
      }
        break;
      default:
        break;
    }
  }
  
  const unsigned int npart = model->getNumPartitions();
  FILE *fp = Fopen(name.c_str(), "w");
  
  if(fp == NULL) return 1;
  
  //-----------Group-----------
  fprintf(fp, "Group{\n");
  
  //Omega_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = omega.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tOmega_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //Sigma_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = sigma.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tSigma_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //Sigma_i_j  
  for(std::multimap<unsigned int, GEntity*>::iterator it1 = sigma.begin(); it1 != sigma.end(); ++it1){
    for(std::multimap<unsigned int, GEntity*>::iterator it2 = sigma.begin(); it2 != sigma.end(); ++it2){
      if(it2->second == it1->second && *it2 != *it1){
        fprintf(fp, "\tSigma_%d_%d = Region[{%d}];\n", it1->first, it2->first, getTag(model, it1->second));
      }
    }
  }
  fprintf(fp, "\n");
  
  //Tau_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = tau.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tTau_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //Tau_i_j
  for(std::multimap<unsigned int, GEntity*>::iterator it1 = tau.begin(); it1 != tau.end(); ++it1){
    for(std::multimap<unsigned int, GEntity*>::iterator it2 = tau.begin(); it2 != tau.end(); ++it2){
      if(it2->second == it1->second && it2 != it1){
        fprintf(fp, "\tTau_%d_%d = Region[{%d}];\n", it1->first, it2->first, getTag(model, it1->second));
      }
    }
  }
  fprintf(fp, "\n");
  
  //Upsilon_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = upsilon.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tUpsilon_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //Upsilon_i_j
  for(std::multimap<unsigned int, GEntity*>::iterator it1 = upsilon.begin(); it1 != upsilon.end(); ++it1){
    for(std::multimap<unsigned int, GEntity*>::iterator it2 = upsilon.begin(); it2 != upsilon.end(); ++it2){
      if(it2->second == it1->second && it2 != it1){
        fprintf(fp, "\tUpsilon_%d_%d = Region[{%d}];\n", it1->first, it2->first, getTag(model, it1->second));
      }
    }
  }
  fprintf(fp, "\n");
  
  //Omicron_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = omicron.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tOmicron_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //Omicron_i_j
  for(std::multimap<unsigned int, GEntity*>::iterator it1 = omicron.begin(); it1 != omicron.end(); ++it1){
    for(std::multimap<unsigned int, GEntity*>::iterator it2 = omicron.begin(); it2 != omicron.end(); ++it2){
      if(it2->second == it1->second && it2 != it1){
        fprintf(fp, "\tOmicron_%d_%d = Region[{%d}];\n", it1->first, it2->first, getTag(model, it1->second));
      }
    }
  }
  fprintf(fp, "\n");
  
  //OmicronSigma_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = omicronSigma.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tOmicronSigma_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //OmicronSigma_i_j
  for(std::multimap<unsigned int, GEntity*>::iterator it1 = omicronSigma.begin(); it1 != omicronSigma.end(); ++it1){
    for(std::multimap<unsigned int, GEntity*>::iterator it2 = omicronSigma.begin(); it2 != omicronSigma.end(); ++it2){
      if(it2->second == it1->second && it2 != it1){
        fprintf(fp, "\tOmicronSigma_%d_%d = Region[{%d}];\n", it1->first, it2->first, getTag(model, it1->second));
      }
    }
  }
  fprintf(fp, "\n");
  
  //OmicronTau_i
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, GEntity*>::iterator, std::multimap<unsigned int, GEntity*>::iterator> range;
    range = omicronTau.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned int, GEntity*>::iterator it = range.first; it != range.second; ++it){
      physicalTags.insert(getTag(model, it->second));
    }
    
    fprintf(fp, "\tOmicronTau_%d = Region[{", i);
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it){
      if(it != physicalTags.begin()) fprintf(fp, ", ");
      fprintf(fp, "%d", *it);
    }
    fprintf(fp, "}];\n");
  }
  fprintf(fp, "\n");
  
  //OmicronTau_i_j
  for(std::multimap<unsigned int, GEntity*>::iterator it1 = omicronTau.begin(); it1 != omicronTau.end(); ++it1){
    for(std::multimap<unsigned int, GEntity*>::iterator it2 = omicronTau.begin(); it2 != omicronTau.end(); ++it2){
      if(it2->second == it1->second && it2 != it1){
        fprintf(fp, "\tOmicronTau_%d_%d = Region[{%d}];\n", it1->first, it2->first, getTag(model, it1->second));
      }
    }
  }
  fprintf(fp, "\n");
  
  //D
  fprintf(fp, "\tD() = {");
  for(unsigned int i = 0; i < npart; i++){
    if(i != 0) fprintf(fp, ", ");
    fprintf(fp, "%d", i);
  }
  fprintf(fp, "};\n");
  
  //D_i
  std::multimap<unsigned int, unsigned int> neighbors;
  for(std::multimap<unsigned int, GEntity*>::iterator it = sigma.begin(); it != sigma.end(); ++it){
    if(it->second->geomType() == GEntity::PartitionSurface){
      for(unsigned int i = 0; i < static_cast<partitionFace*>(it->second)->numPartitions(); i++){
        neighbors.insert(std::pair<unsigned int, unsigned int>(it->first, static_cast<partitionFace*>(it->second)->getPartition(i)));
      }
    }
    else if(it->second->geomType() == GEntity::PartitionCurve){
      for(unsigned int i = 0; i < static_cast<partitionEdge*>(it->second)->numPartitions(); i++){
        neighbors.insert(std::pair<unsigned int, unsigned int>(it->first, static_cast<partitionEdge*>(it->second)->getPartition(i)));
      }
    }
    else if(it->second->geomType() == GEntity::PartitionVertex){
      for(unsigned int i = 0; i < static_cast<partitionVertex*>(it->second)->numPartitions(); i++){
        neighbors.insert(std::pair<unsigned int, unsigned int>(it->first, static_cast<partitionVertex*>(it->second)->getPartition(i)));
      }
    }
  }
  
  for(unsigned int i = 0; i < npart; i++){
    std::pair <std::multimap<unsigned int, unsigned int>::iterator, std::multimap<unsigned int, unsigned int>::iterator> range;
    range = neighbors.equal_range(i);
    std::vector<unsigned int> writeNeighbors;
    fprintf(fp, "\tD_%d() = {", i);
    int j = 0;
    for(std::multimap<unsigned int, unsigned int>::iterator it = range.first; it != range.second; ++it){
      if(std::find(writeNeighbors.begin(), writeNeighbors.end(), it->second) == writeNeighbors.end() && i != it->second){
        if(j != 0) fprintf(fp, ", ");
        fprintf(fp, "%d", it->second);
        writeNeighbors.push_back(it->second);
        j++;
      }
    }
    fprintf(fp, "};\n");
  }
  
  fprintf(fp, "}\n\n");
  
  fclose(fp);
  
  return 0;
}

int getTag(GModel* model, GEntity* entity)
{
  std::vector<int> tags = entity->getPhysicalEntities();
  for(unsigned int i = 0; i < tags.size(); i++){
    std::string name = model->getPhysicalName(entity->dim(),tags[i]);
    
    if(name[0] != '_') continue;
    else return tags[i];
  }
  
  return -1;
}

std::string getSubstr(GModel* model, GEntity* entity)
{
  std::string substr;
  std::vector<int> tags = entity->getPhysicalEntities();
  for(unsigned int i = 0; i < tags.size(); i++){
    std::string name = model->getPhysicalName(entity->dim(),tags[i]);
    
    std::string str;
    if(name[0] == '_'){
      for(unsigned int j = 0; j < name.length(); j++){
        if(name[j] == '{'){
          substr = str;
          break;
        }
        else if(name[j] == ' ') continue;
        else if(name[j] == '}') break;
        else{
          str += name[j];
        }
      }
    }
    
  }
  
  return substr;
}

std::vector<unsigned int> getPartition(GModel* model, GEntity* entity)
{
  std::vector<int> tags = entity->getPhysicalEntities();
  std::vector<unsigned int> partitions;
  for(unsigned int i = 0; i < tags.size(); i++){
    std::string name = model->getPhysicalName(entity->dim(),tags[i]);
    
    std::string integer;
    if(name[0] == '_'){
      for(unsigned int j = 0; j < name.length(); j++){
        if(name[j] == '{'){
          integer.clear();
        }
        else if(name[j] == ','){
#ifdef HAVE_CXX11
          partitions.push_back(stoi(integer));
#else
          partitions.push_back(atoi(integer.c_str()));
#endif
          integer.clear();
        }
        else if(name[j] == ' ') continue;
        else if(name[j] == '}'){
#ifdef HAVE_CXX11
          partitions.push_back(stoi(integer));
#else
          partitions.push_back(atoi(integer.c_str()));
#endif
          break;
        }
        else{
          integer += name[j];
        }
      }
    }
  }
  
  return partitions;
}

/*******************************************************************************
 *
 * Routine BuildTopology
 *
 * Purpose
 * =======
 *
 *   Build the topology
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

void BuildTopology(GModel *model)
{
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it){
    if((*it)->geomType() == GEntity::PartitionVolume){
      AssignMeshVertices(model, 2, true);
      AssignMeshVerticesToEntity(*it, false);
      std::set<GFace*> boundaryFace;
      fillBoundaryFace(model, boundaryFace, static_cast<partitionRegion*>(*it), true);
      
      std::list<GFace*> faces;
      std::list<int> facesOrientation;
      for(std::set<GFace*>::const_iterator itSet = boundaryFace.begin(); itSet != boundaryFace.end(); ++itSet){
        if((*itSet)->geomType() == GEntity::PartitionSurface){
          (*itSet)->addRegion(*it);
          faces.push_back((*itSet));
          facesOrientation.push_back(computeOrientation(*it, *itSet));
          addPhysical(model, static_cast<partitionRegion*>(*it), static_cast<partitionFace*>(*itSet));
        }
      }
      (*it)->set(faces);
      (*it)->setOrientations(facesOrientation);
    }
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
    if((*it)->geomType() == GEntity::PartitionSurface){
      AssignMeshVertices(model, 1, true);
      AssignMeshVerticesToEntity(*it, false);
      
      std::set<GEdge*> boundaryEdge;
      fillBoundaryEdge(model, boundaryEdge, static_cast<partitionFace*>(*it), true);
      
      std::list<GEdge*> edges;
      std::list<int> edgesOrientation;
      for(std::set<GEdge*>::const_iterator itSet = boundaryEdge.begin(); itSet != boundaryEdge.end(); ++itSet){
        if((*itSet)->geomType() == GEntity::PartitionCurve){
          (*itSet)->addFace(*it);
          edges.push_back((*itSet));
          edgesOrientation.push_back(computeOrientation(*it, *itSet));
          addPhysical(model, static_cast<partitionFace*>(*it), static_cast<partitionEdge*>(*itSet));
        }
      }
      (*it)->set(edges);
      (*it)->setOrientations(edgesOrientation);
    }
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    if((*it)->geomType() == GEntity::PartitionCurve){
      AssignMeshVertices(model, 0, true);
      AssignMeshVerticesToEntity(*it, false);
      
      std::set<GVertex*> boundaryVertex;
      fillBoundaryVertex(model, boundaryVertex, static_cast<partitionEdge*>(*it), true);
      
      std::vector<GVertex*> vertices;
      std::list<int> verticesOrientation;
      for(std::set<GVertex*>::const_iterator itSet = boundaryVertex.begin(); itSet != boundaryVertex.end(); ++itSet){
        if((*itSet)->geomType() == GEntity::PartitionVertex){
          (*itSet)->addEdge(*it);
          vertices.push_back((*itSet));
          verticesOrientation.push_back(computeOrientation(*it, *itSet));
          addPhysical(model, static_cast<partitionEdge*>(*it), static_cast<partitionVertex*>(*itSet));
        }
      }
      
      if(vertices.size() == 2){
        if(verticesOrientation.front() == 1){
          (*it)->setBeginVertex(vertices[0]);
          (*it)->setEndVertex(vertices[1]);
        }
        else{
          (*it)->setBeginVertex(vertices[1]);
          (*it)->setEndVertex(vertices[0]);
        }
      }
      else if(vertices.size() == 1){
        if(verticesOrientation.front() == 1){
          (*it)->setBeginVertex(vertices[0]);
        }
        else{
          (*it)->setEndVertex(vertices[0]);
        }
      }
    }
  }
}

void fillBoundaryFace(const GModel *const model, std::set<GFace*> &boundaryFace, partitionRegion* entity, bool full)
{
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it){
    bool isABoundary = true;
    for(std::vector<MVertex*>::const_iterator itVec = (*it)->mesh_vertices.begin(); itVec != (*it)->mesh_vertices.end(); ++itVec){
      if(full && (*itVec)->onWhat() != entity){
        isABoundary = false;
        break;
      }
      if(!full && (*itVec)->onWhat() == entity){
        boundaryFace.insert(*it);
        break;
      }
    }
    if(isABoundary && full){
      boundaryFace.insert(*it);
    }
  }
}

void fillBoundaryEdge(const GModel *const model, std::set<GEdge*> &boundaryEdge, partitionFace* entity, bool full)
{
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it){
    bool isABoundary = true;
    for(std::vector<MVertex*>::const_iterator itVec = (*it)->mesh_vertices.begin(); itVec != (*it)->mesh_vertices.end(); ++itVec){
      if(full && (*itVec)->onWhat() != entity){
        isABoundary = false;
        break;
      }
      if(!full && (*itVec)->onWhat() == entity){
        boundaryEdge.insert(*it);
        break;
      }
    }
    if(isABoundary && full){
      boundaryEdge.insert(*it);
    }
  }
}

void fillBoundaryVertex(const GModel *const model, std::set<GVertex*> &boundaryVertex, partitionEdge* entity, bool full)
{
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it){
    bool isABoundary = true;
    for(std::vector<MVertex*>::const_iterator itVec = (*it)->mesh_vertices.begin(); itVec != (*it)->mesh_vertices.end(); ++itVec){
      if(full && (*itVec)->onWhat() != entity){
        isABoundary = false;
        break;
      }
      if(!full && (*itVec)->onWhat() == entity){
        boundaryVertex.insert(*it);
        break;
      }
    }
    if(isABoundary && full){
      boundaryVertex.insert(*it);
    }
  }
}

void addPhysical(GModel *const model, partitionRegion *parentEntity, partitionFace *childEntity)
{
  std::string name;
  std::string parentSubStr = getSubstr(model, parentEntity);
  if(parentSubStr.empty()){
    name = "_omega{";
    
    for(unsigned int i = 0; i < parentEntity->numPartitions(); i++){
      if(i > 0) name += ",";
#ifdef HAVE_CXX11
      name += std::to_string(parentEntity->getPartition(i));
#else
      char intToChar[20];
      sprintf(intToChar, "%d", parentEntity->getPartition(i));
      name += intToChar;
#endif
    }
    name += "}";
    
    int number = model->getPhysicalNumber(parentEntity->dim(), name);
    if(number == -1) number = model->numPhysicalNames()+1;
    model->setPhysicalName(name, parentEntity->dim(), number);
    parentEntity->addPhysicalEntity(number);
    
    parentSubStr = "_omega";
    name.clear();
  }
  
  std::string childSubStr = getSubstr(model, childEntity);

  if(childEntity->numPartitions() == 1){
    name = "_omicron";
  }
  
  else{
    if(parentSubStr == "_omega"){
      name = "_sigma";
    }
    else if(parentSubStr == "_sigma"){
      name = "_tau";
    }
    else if(parentSubStr == "_tau"){
      name = "_upsilon";
    }
    else if(parentSubStr == "_upsilon"){
      return;
    }
    else if(parentSubStr == "_omicron"){
      name = "_omicronSigma";
    }
    else if(parentSubStr == "_omicronSigma"){
      name = "_omicronTau";
    }
    else if(parentSubStr == "_omicronTau"){
      return;
    }
  }
  
  if(childSubStr == name) return;
  name += "{";
  
  for(unsigned int i = 0; i < childEntity->numPartitions(); i++){
    if(i > 0) name += ",";
#ifdef HAVE_CXX11
    name += std::to_string(childEntity->getPartition(i));
#else
    char intToChar[20];
    sprintf(intToChar, "%d", childEntity->getPartition(i));
    name += intToChar;
#endif
  }
  name += "}";
  
  int number = model->getPhysicalNumber(childEntity->dim(), name);
  if(number == -1) number = model->numPhysicalNames()+1;
  model->setPhysicalName(name, childEntity->dim(), number);
  childEntity->addPhysicalEntity(number);
}

void addPhysical(GModel *const model, partitionFace *parentEntity, partitionEdge *childEntity)
{
  std::string name;
  std::string parentSubStr = getSubstr(model, parentEntity);
  if(parentSubStr.empty()){
    name = "_omega{";
    
    for(unsigned int j = 0; j < parentEntity->numPartitions(); j++){
      if(j > 0) name += ",";
#ifdef HAVE_CXX11
      name += std::to_string(parentEntity->getPartition(j));
#else
      char intToChar[20];
      sprintf(intToChar, "%d", parentEntity->getPartition(j));
      name += intToChar;
#endif
    }
    name += "}";
    
    int number = model->getPhysicalNumber(parentEntity->dim(), name);
    if(number == -1) number = model->numPhysicalNames()+1;
    model->setPhysicalName(name, parentEntity->dim(), number);
    parentEntity->addPhysicalEntity(number);
    
    parentSubStr = "_omega";
    name.clear();
  }
  
  std::string childSubStr = getSubstr(model, childEntity);
  
  if(childEntity->numPartitions() == 1){
    name = "_omicron";
  }
  else{
    if(parentSubStr == "_omega"){
      name = "_sigma";
    }
    else if(parentSubStr == "_sigma"){
      name = "_tau";
    }
    else if(parentSubStr == "_tau"){
      name = "_upsilon";
    }
    else if(parentSubStr == "_upsilon"){
      return;
    }
    else if(parentSubStr == "_omicron"){
      name = "_omicronSigma";
    }
    else if(parentSubStr == "_omicronSigma"){
      name = "_omicronTau";
    }
    else if(parentSubStr == "_omicronTau"){
      return;
    }
  }
  
  if(childSubStr == name) return;
  name += "{";
  
  for(unsigned int j = 0; j < childEntity->numPartitions(); j++){
    if(j > 0) name += ",";
#ifdef HAVE_CXX11
    name += std::to_string(childEntity->getPartition(j));
#else
    char intToChar[20];
    sprintf(intToChar, "%d", childEntity->getPartition(j));
    name += intToChar;
#endif
  }
  name += "}";
  
  int number = model->getPhysicalNumber(childEntity->dim(), name);
  if(number == -1) number = model->numPhysicalNames()+1;
  model->setPhysicalName(name, childEntity->dim(), number);
  childEntity->addPhysicalEntity(number);
}

void addPhysical(GModel *const model, partitionEdge *parentEntity, partitionVertex *childEntity)
{
  std::string name;
  std::string parentSubStr = getSubstr(model, parentEntity);
  if(parentSubStr.empty()){
    name = "_omega{";
    
    for(unsigned int j = 0; j < parentEntity->numPartitions(); j++){
      if(j > 0) name += ",";
#ifdef HAVE_CXX11
      name += std::to_string(childEntity->getPartition(j));
#else
      char intToChar[20];
      sprintf(intToChar, "%d", childEntity->getPartition(j));
      name += intToChar;
#endif
    }
    name += "}";
    
    int number = model->getPhysicalNumber(parentEntity->dim(), name);
    if(number == -1) number = model->numPhysicalNames()+1;
    model->setPhysicalName(name, parentEntity->dim(), number);
    parentEntity->addPhysicalEntity(number);
    
    parentSubStr = "_omega";
    name.clear();
  }
  
  std::string childSubStr = getSubstr(model, childEntity);
  
  if(childEntity->numPartitions() == 1){
    name = "_omicron";
  }
  else{
    if(parentSubStr == "_omega"){
      name = "_sigma";
    }
    else if(parentSubStr == "_sigma"){
      name = "_tau";
    }
    else if(parentSubStr == "_tau"){
      name = "_upsilon";
    }
    else if(parentSubStr == "_upsilon"){
      return;
    }
    else if(parentSubStr == "_omicron"){
      name = "_omicronSigma";
    }
    else if(parentSubStr == "_omicronSigma"){
      name = "_omicronTau";
    }
    else if(parentSubStr == "_omicronTau"){
      return;
    }
  }
  
  if(childSubStr == name) return;
  name += "{";
  
  for(unsigned int j = 0; j < childEntity->numPartitions(); j++){
    if(j > 0) name += ",";
#ifdef HAVE_CXX11
    name += std::to_string(childEntity->getPartition(j));
#else
    char intToChar[20];
    sprintf(intToChar, "%d", childEntity->getPartition(j));
    name += intToChar;
#endif
  }
  name += "}";
  
  int number = model->getPhysicalNumber(childEntity->dim(), name);
  if(number == -1) number = model->numPhysicalNames()+1;
  model->setPhysicalName(name, childEntity->dim(), number);
  childEntity->addPhysicalEntity(number);
}

int computeOrientation(GEntity *parent, GEntity *child)
{
  std::vector<MVertex*> vertices;
  child->getMeshElement(0)->getVertices(vertices);
  
  for(unsigned int i = 0; i < parent->getNumMeshElements(); i++){
    std::vector<MVertex*> parentVertices;
    MElement* element = parent->getMeshElement(i);
    element->getVertices(parentVertices);
    bool haveBreak = false;
    for(unsigned int j = 0; j < vertices.size(); j++){
      std::vector<MVertex*>::iterator it = std::find(parentVertices.begin(), parentVertices.end(), vertices[j]);
      if(it == parentVertices.end()){
        haveBreak = true;
        break;
      }
    }
    
    if(!haveBreak){
      if(parent->dim() == 3){
        int numFace = 0;
        MFace me = child->getMeshElement(0)->getFace(0);
        
        for(unsigned int j = 0; j < element->getNumFaces(); j++){
          if(element->getFace(j) == me){
            numFace = j;
            break;
          }
        }
        
        std::vector<MVertex*> verts;
        element->getFaceVertices(numFace, verts);
        
        return (verts == vertices) ? 1 : -1;
      }
      else if(parent->dim() == 2){
        int numEdge = 0;
        MEdge me = child->getMeshElement(0)->getEdge(0);
        
        for(unsigned int j = 0; j < element->getNumEdges(); j++){
          if(element->getEdge(j) == me){
            numEdge = j;
            break;
          }
        }
        
        std::vector<MVertex*> verts;
        element->getEdgeVertices(numEdge, verts);
        
        return (verts == vertices) ? 1 : -1;
      }
      else if(parent->dim() == 1){
        return (vertices[0] == element->getVertex(0)) ? 1 : -1;
      }
    }
  }
  
  return 1;
}




















int PartitionMeshFace(std::list<GFace*> &cFaces)
{
  GModel *tmp_model = new GModel();
  for(std::list<GFace*>::iterator it = cFaces.begin(); it != cFaces.end(); it++)
    tmp_model->add(*it);
  
  PartitionMesh(tmp_model);
  
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

int PartitionMeshElements(std::vector<MElement*> &elements)
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
  
  PartitionMesh(tmp_model);
  
  tmp_model->remove(gf);
  delete tmp_model;
  
  return 1;
}

#else

int PartitionMesh(GModel *const model)
{
  Msg::Error("Gmsh must be compiled with METIS support to partition meshes");
  return 0;
}


#endif
