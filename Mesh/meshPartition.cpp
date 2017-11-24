// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// meshPartition.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <limits>
#include <stack>

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

int PartitionMesh(GModel *const model)
{
  Graph graph;
  Msg::StatusBar(true, "Building mesh graph...");
  int ier = MakeGraph(model, graph);
  if(CTX::instance()->mesh.num_partitions > 1)
  {
    Msg::StatusBar(true, "Partitioning graph...");
    if(!ier) ier = PartitionGraph(graph);
    if(ier) return 1;
  }
    
  // Assign partitions to elements
  std::unordered_map<MElement*, unsigned short> elmToPartition;
  for(unsigned int i = 0; i < graph.ne(); i++)
  {
    if(graph.element(i) != NULL)
    {
      if(CTX::instance()->mesh.num_partitions > 1)
      {
        elmToPartition.insert(std::pair<MElement*, unsigned short>(graph.element(i), graph.partition(i)+1));
        //Should be removed
        graph.element(i)->setPartition(graph.partition(i)+1);
      }
      else
      {
        elmToPartition.insert(std::pair<MElement*, unsigned short>(graph.element(i), 1));
        //Should be removed
        graph.element(i)->setPartition(1);
      }
    }
  }
  graph.clear();
  model->recomputeMeshPartitions();
  
  Msg::StatusBar(true, "Create new entities...");
  std::multimap<unsigned short, GEntity*> newPartitionEntities;
  CreateNewEntities(model, elmToPartition, newPartitionEntities);
  elmToPartition.clear();
  
  std::multimap<unsigned short, GEntity*> newPartitionBoundaries;
  std::multimap<unsigned short, GEntity*> newBoundariesOfPartitionBoundaries;
  if(CTX::instance()->mesh.createPartitionBoundaries)
  {
    Msg::StatusBar(true, "Create boundaries...");
    CreatePartitionBoundaries(model, newPartitionBoundaries, newBoundariesOfPartitionBoundaries);
  }
 
  Msg::StatusBar(true, "Divide non connected entities...");
  DivideNonConnectedEntities(model);
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
      }
      else
      {
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
 * Routine CreatePartitionTopology
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

int CreatePartitionTopology(GModel *const model)
{
  std::unordered_map<MElement*, unsigned short> elmToPartition;
  
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    for(std::vector<MTetrahedron*>::iterator itElm = (*it)->tetrahedra.begin(); itElm != (*it)->tetrahedra.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
    for(std::vector<MHexahedron*>::iterator itElm = (*it)->hexahedra.begin(); itElm != (*it)->hexahedra.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
    for(std::vector<MPrism*>::iterator itElm = (*it)->prisms.begin(); itElm != (*it)->prisms.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
    for(std::vector<MPyramid*>::iterator itElm = (*it)->pyramids.begin(); itElm != (*it)->pyramids.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
    for(std::vector<MTrihedron*>::iterator itElm = (*it)->trihedra.begin(); itElm != (*it)->trihedra.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    for(std::vector<MTriangle*>::iterator itElm = (*it)->triangles.begin(); itElm != (*it)->triangles.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
    for(std::vector<MQuadrangle*>::iterator itElm = (*it)->quadrangles.begin(); itElm != (*it)->quadrangles.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    for(std::vector<MLine*>::iterator itElm = (*it)->lines.begin(); itElm != (*it)->lines.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    for(std::vector<MPoint*>::iterator itElm = (*it)->points.begin(); itElm != (*it)->points.end(); ++itElm)
      elmToPartition.insert(std::pair<MElement*, unsigned short>(*itElm, (*itElm)->getPartition()));
  }
  
  for(std::unordered_map<MElement*, unsigned short>::iterator it = elmToPartition.begin(); it != elmToPartition.end(); ++it)
    Msg::Info("%d", (*it).second);
    
  Msg::StatusBar(true, "Create new entities...");
  std::multimap<unsigned short, GEntity*> newPartitionEntities;
  CreateNewEntities(model, elmToPartition, newPartitionEntities);
  elmToPartition.clear();
  
  std::multimap<unsigned short, GEntity*> newPartitionBoundaries;
  std::multimap<unsigned short, GEntity*> newBoundariesOfPartitionBoundaries;
  if(CTX::instance()->mesh.createPartitionBoundaries)
  {
    Msg::StatusBar(true, "Create boundaries...");
    CreatePartitionBoundaries(model, newPartitionBoundaries, newBoundariesOfPartitionBoundaries);
  }
  
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
    
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->tetrahedra.begin(), r->tetrahedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->hexahedra.begin(), r->hexahedra.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->prisms.begin(), r->prisms.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->pyramids.begin(), r->pyramids.end());
    fillElementsToNodesMap(graph, r, eptrIndex, eindIndex, numVertex, r->trihedra.begin(), r->trihedra.end());
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    const GFace *f = *it;
    
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex, f->triangles.begin(), f->triangles.end());
    fillElementsToNodesMap(graph, f, eptrIndex, eindIndex, numVertex, f->quadrangles.begin(), f->quadrangles.end());
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    const GEdge *e = *it;
    
    fillElementsToNodesMap(graph, e, eptrIndex, eindIndex, numVertex, e->lines.begin(), e->lines.end());
  }
  
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    GVertex *v = *it;
    
    fillElementsToNodesMap(graph, v, eptrIndex, eindIndex, numVertex, v->points.begin(), v->points.end());
  }
  
  //Taking into account the periodicity
  if(isPeriodic(model))
  {
    std::map<int,int> correspondingVertices;
    std::vector<GEntity*> entities;
    model->getEntities(entities);
    for(unsigned int i = 0; i < entities.size(); i++)
    {
      for(std::map<MVertex*,MVertex*>::iterator it = entities[i]->correspondingVertices.begin(); it != entities[i]->correspondingVertices.end(); ++it)
      {
        correspondingVertices.insert(std::pair<int,int>(graph.vertex(it->first->getNum()-1), graph.vertex(it->second->getNum()-1)));
      }
    }
        
    for(unsigned int i = 0; i < eindSize; i++)
    {
      std::map<int,int>::iterator it = correspondingVertices.find(graph.eind(i));
      if(it != correspondingVertices.end())
      {
        graph.eind(i,it->second);
      }
    }
  }
  
  return 0;
}

template <class ITERATOR>
void fillElementsToNodesMap(Graph &graph, const GEntity *const entity, int &eptrIndex, int &eindIndex, int &numVertex, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int numVertices = getNumVertices(*it);
    graph.element(eptrIndex, *it);
    eptrIndex++;
    graph.eptr(eptrIndex, graph.eptr(eptrIndex-1) + numVertices);
    for(int i = 0; i < numVertices; i++)
    {
      if(graph.vertex((*it)->getVertex(i)->getNum()-1) == -1)
      {
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

bool isPeriodic(const GModel *const model)
{
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  
  for(unsigned int i = 0; i < entities.size(); i++)
  {
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
        
    switch(CTX::instance()->mesh.metis_algorithm)
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
        
    switch(CTX::instance()->mesh.metis_edge_matching)
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
        
    switch(CTX::instance()->mesh.metis_refine_algorithm)
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

    int objval;
    unsigned int *epart = new unsigned int[graph.ne()];
    const unsigned int ne = graph.ne();
    const int numPart = CTX::instance()->mesh.num_partitions;
    int ncon = 1;
        
    graph.fillDefaultWeights();
    
    int metisError = 0;
    createDualGraph(graph);
    
    if (metisOptions[METIS_OPTION_PTYPE] == METIS_PTYPE_KWAY)
    {
      metisError = METIS_PartGraphKway((idx_t *)&ne, (idx_t *)&ncon, (idx_t *)graph.xadj(), (idx_t *)graph.adjncy(), (idx_t *)graph.vwgt(), (idx_t *)NULL, NULL, (idx_t *)&numPart, NULL, NULL, (idx_t *)metisOptions, (idx_t *)&objval, (idx_t *)epart);
    }
    else
    {
      metisError = METIS_PartGraphRecursive((idx_t *)&ne, (idx_t *)&ncon, (idx_t *)graph.xadj(), (idx_t *)graph.adjncy(), (idx_t *)graph.vwgt(), (idx_t *)NULL, NULL, (idx_t *)&numPart, NULL, NULL, (idx_t *)metisOptions, (idx_t *)&objval, (idx_t *)epart);
    }

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
    
    //Check and correct the topology
    for(unsigned int i = 0; i < graph.ne(); i++)
    {
      if(graph.element(i)->getDim() == graph.dim()) continue;
      
      for(unsigned int j = graph.xadj(i); j < graph.xadj(i+1); j++)
      {
        if(graph.element(graph.adjncy(j))->getDim() == graph.element(i)->getDim()+1)
        {
          if(epart[i] != epart[graph.adjncy(j)])
          {
            epart[i] = epart[graph.adjncy(j)];
            break;
          }
        }
        
        if(graph.element(graph.adjncy(j))->getDim() == graph.element(i)->getDim()+2)
        {
          if(epart[i] != epart[graph.adjncy(j)])
          {
            epart[i] = epart[graph.adjncy(j)];
            break;
          }
        }
        
        if(graph.element(graph.adjncy(j))->getDim() == graph.element(i)->getDim()+3)
        {
          if(epart[i] != epart[graph.adjncy(j)])
          {
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
  
  for(unsigned int i = 0; i < graph.ne(); i++)
  {
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++)
    {
      nptr[graph.eind(j)]++;
    }
  }
  
  for(unsigned int i = 1; i < graph.nn(); i++) nptr[i] += nptr[i-1];
  for(unsigned int i = graph.nn(); i > 0; i--) nptr[i] = nptr[i-1];
  nptr[0] = 0;
  
  for(unsigned int i = 0; i < graph.ne()-1; i++)
  {
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++)
    {
      nind[nptr[graph.eind(j)]++] = i;
    }
  }
  
  for(unsigned int i = graph.nn(); i > 0; i--) nptr[i] = nptr[i-1];
  nptr[0] = 0;
  
  graph.xadjResize(graph.ne()+1);
  int *nbrs = new int[graph.ne()];
  int *marker = new int[graph.ne()];
  for(unsigned int i = 0; i < graph.ne(); i++)
  {
    nbrs[i] = 0;
    marker[i] = 0;
  }
  
  for(unsigned int i = 0; i < graph.ne(); i++)
  {
    unsigned int l = 0;
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++)
    {
      for(unsigned int k = nptr[graph.eind(j)]; k < nptr[graph.eind(j)+1]; k++)
      {
        if(nind[k] != i)
        {
          if(marker[nind[k]] == 0) nbrs[l++] = nind[k];
          marker[nind[k]]++;
        }
      }
    }
    
    unsigned int nbrsNeighbors = 0;
    for(unsigned int j = 0; j < l; j++)
    {
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
  for(unsigned int i = 0; i < graph.ne(); i++)
  {
    unsigned int l = 0;
    for(unsigned int j = graph.eptr(i); j < graph.eptr(i+1); j++)
    {
      for(unsigned int k = nptr[graph.eind(j)]; k < nptr[graph.eind(j)+1]; k++)
      {
        if(nind[k] != i)
        {
          if (marker[nind[k]] == 0) nbrs[l++] = nind[k];
          marker[nind[k]]++;
        }
      }
    }
    
    for(unsigned int j = 0; j < l; j++)
    {
      if(marker[nbrs[j]] >= graph.element(i)->numCommonNodesInDualGraph(graph.element(nbrs[j])))
      {
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

void CreateNewEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::multimap<unsigned short, GEntity*> &newPartitionEntities)
{
  std::set<GRegion*, GEntityLessThan> regions = model->getGRegions();
  std::set<GFace*, GEntityLessThan> faces = model->getGFaces();
  std::set<GEdge*, GEntityLessThan> edges = model->getGEdges();
  std::set<GVertex*, GEntityLessThan> vertices = model->getGVertices();
  
  for(GModel::const_riter it = regions.begin(); it != regions.end(); ++it)
  {
    std::vector<GRegion *> newRegions(CTX::instance()->mesh.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->prisms.begin(), (*it)->prisms.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->pyramids.begin(), (*it)->pyramids.end());
    assignElementsToEntities(model, elmToPartition, newRegions, (*it)->trihedra.begin(), (*it)->trihedra.end());
    
    for(unsigned int i = 0; i < CTX::instance()->mesh.num_partitions; i++)
    {
      if(newRegions[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(i, newRegions[i]));
        static_cast<partitionRegion*>(newRegions[i])->setParentEntity(*it);
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++)
        {
          newRegions[i]->addPhysicalEntity(physicalEntities[j]);
        }
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
  }
  
  
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it)
  {
    std::vector<GFace *> newFaces(CTX::instance()->mesh.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->triangles.begin(), (*it)->triangles.end());
    assignElementsToEntities(model, elmToPartition, newFaces, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
    
    for(unsigned int i = 0; i < CTX::instance()->mesh.num_partitions; i++)
    {
      if(newFaces[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(i, newFaces[i]));
        static_cast<partitionFace*>(newFaces[i])->setParentEntity(*it);
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++)
        {
          newFaces[i]->addPhysicalEntity(physicalEntities[j]);
        }
      }
    }
  }
  for(GModel::const_fiter it = faces.begin(); it != faces.end(); ++it)
  {
    (*it)->mesh_vertices.clear();
    
    (*it)->triangles.clear();
    (*it)->quadrangles.clear();
  }
  
  
  for(GModel::const_eiter it = edges.begin(); it != edges.end(); ++it)
  {
    std::vector<GEdge *> newEdges(CTX::instance()->mesh.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newEdges, (*it)->lines.begin(), (*it)->lines.end());
    
    for(unsigned int i = 0; i < CTX::instance()->mesh.num_partitions; i++)
    {
      if(newEdges[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(i, newEdges[i]));
        static_cast<partitionEdge*>(newEdges[i])->setParentEntity(*it);
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++)
        {
          newEdges[i]->addPhysicalEntity(physicalEntities[j]);
        }
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
    std::vector<GVertex *> newVertices(CTX::instance()->mesh.num_partitions, NULL);
    
    assignElementsToEntities(model, elmToPartition, newVertices, (*it)->points.begin(), (*it)->points.end());
    
    for(unsigned int i = 0; i < CTX::instance()->mesh.num_partitions; i++)
    {
      if(newVertices[i] != NULL)
      {
        newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(i, newVertices[i]));
        static_cast<partitionVertex*>(newVertices[i])->setParentEntity((*it));
        std::vector<int> physicalEntities = (*it)->getPhysicalEntities();
        for(unsigned int j = 0; j < physicalEntities.size(); j++)
        {
          newVertices[i]->addPhysicalEntity(physicalEntities[j]);
        }
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
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GRegion *> &newRegions, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const unsigned short partition = elmToPartition[(*it)]-1;
    
    if(newRegions[partition] == NULL)
    {
      std::vector<unsigned short> partitions;
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
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GFace *> &newFaces, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const unsigned short partition = elmToPartition[(*it)]-1;
    
    if(newFaces[partition] == NULL)
    {
      std::vector<unsigned short> partitions;
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
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GEdge *> &newEdges, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const unsigned short partition = elmToPartition[(*it)]-1;
    
    if(newEdges[partition] == NULL)
    {
      std::vector<unsigned short> partitions;
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
void assignElementsToEntities(GModel *const model, std::unordered_map<MElement*, unsigned short> &elmToPartition, std::vector<GVertex *> &newVertices, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const unsigned short partition = elmToPartition[(*it)]-1;
    
    if(newVertices[partition] == NULL)
    {
      std::vector<unsigned short> partitions;
      partitions.push_back(partition);
      partitionVertex *dv = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, partitions);
      model->add(dv);
      newVertices[partition] = dv;
      
      addPhysical(model, dv, partition);
    }
    
    newVertices[partition]->addPoint(reinterpret_cast<MPoint*>(*it));
  }
}

void addPhysical(GModel *const model, GEntity *const entity, const unsigned short partition)
{
  std::string name = "_omega{";
  name += std::to_string(partition);
  name += "}";
  
  int number = model->getPhysicalNumber(entity->dim(), name);
  if(number == -1) number = model->numPhysicalNames()+1;
  model->setPhysicalName(name, entity->dim(), number);
  entity->addPhysicalEntity(number);
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

void CreatePartitionBoundaries(GModel *const model, std::multimap<unsigned short, GEntity*> &newPartitionBoundaries, std::multimap<unsigned short, GEntity*> &newBoundariesOfPartitionBoundaries)
{
  const int meshDim = model->getDim();
    
  std::set<partitionFace*, Less_partitionFace> pfaces;
  std::set<partitionEdge*, Less_partitionEdge> pedges;
  std::set<partitionVertex*, Less_partitionVertex> pvertices;
  
  std::set<partitionEdge*, Less_partitionEdge> bndedges;
  std::set<partitionVertex*, Less_partitionVertex> bndvertices;
    
  std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Face, Equal_Face> faceToElement;
  std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Edge, Equal_Edge> edgeToElement;
  std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned short> > > > vertexToElement;
  
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
      }
    }
    for(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Face, Equal_Face>::const_iterator it = faceToElement.begin(); it != faceToElement.end(); ++it)
    {
      MFace f = it->first;

      std::vector<unsigned short> partitions;
      std::vector<unsigned short> referencePartitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second, referencePartitions);
      if(reference == NULL) continue;
      
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
      }
    }
    for(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it)
    {
      MEdge e = it->first;
      
      std::vector<unsigned short> partitions;
      std::vector<unsigned short> referencePartitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second, referencePartitions);
      if(reference == NULL) continue;
      
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
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned short> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      
      std::vector<unsigned short> partitions;
      std::vector<unsigned short> referencePartitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second, referencePartitions);
      if(reference == NULL) continue;
      
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
      }
    }
    for(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it)
    {
      MEdge e = it->first;
      
      std::vector<unsigned short> partitions;
      std::vector<unsigned short> referencePartitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second, referencePartitions);
      if(reference == NULL) continue;
      
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
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned short> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      
      std::vector<unsigned short> partitions;
      std::vector<unsigned short> referencePartitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second, referencePartitions);
      if(reference == NULL) continue;
      
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
    for(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned short> > > >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      
      std::vector<unsigned short> partitions;
      std::vector<unsigned short> referencePartitions;
      getPartitionInVector(partitions, it->second);
      if(partitions.size() < 2) continue;
      
      MElement* reference = getReferenceElement(it->second, referencePartitions);
      if(reference == NULL) continue;
      
      assignPartitionBoundary(model, v, reference, partitions, pvertices, pedges, pfaces, bndedges, bndvertices);
    }
    vertexToElement.clear();
  }
  
  
  for(std::set<partitionFace*, Less_partitionFace>::const_iterator it = pfaces.begin(); it != pfaces.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionEdge*, Less_partitionEdge>::const_iterator it = pedges.begin(); it != pedges.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionVertex*, Less_partitionVertex>::const_iterator it = pvertices.begin(); it != pvertices.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionEdge*, Less_partitionEdge>::const_iterator it = bndedges.begin(); it != bndedges.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newBoundariesOfPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>((*it)->_partitions[i], *it));
    }
  }
  
  for(std::set<partitionVertex*, Less_partitionVertex>::const_iterator it = bndvertices.begin(); it != bndvertices.end(); ++it)
  {
    for(unsigned int i = 0; i < (*it)->_partitions.size(); i++)
    {
      newBoundariesOfPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>((*it)->_partitions[i], *it));
    }
  }
}

MElement* getReferenceElement(const std::vector< std::pair<MElement*, std::vector<unsigned short> > > &elementPairs, std::vector<unsigned short> &referencePartitions)
{
  unsigned short min = std::numeric_limits<unsigned short>::max();
  std::vector< std::pair<MElement*, std::vector<unsigned short> > > minSizeElementPairs;
  std::vector< std::pair<MElement*, std::vector<unsigned short> > > minSizeElementPairsTmp;
  
  //Take only the elements having the less partition in commun
  for(unsigned int i = 0; i < elementPairs.size(); i++)
  {
    if(min > elementPairs[i].second.size())
    {
      min = elementPairs[i].second.size();
    }
  }
  
  for(unsigned int i = 0; i < elementPairs.size(); i++)
  {
    if(min == elementPairs[i].second.size())
    {
      minSizeElementPairs.push_back(elementPairs[i]);
    }
  }
  
  if(minSizeElementPairs.size() == elementPairs.size())
  {
    bool isEqual = true;
    for(unsigned int i = 0; i < minSizeElementPairs.size(); i++)
    {
      if(minSizeElementPairs[i].second != minSizeElementPairs[0].second)
      {
        isEqual = false;
        break;
      }
    }
    if(isEqual) return NULL;
  }
  
  while(minSizeElementPairs.size() > 1)
  {
    min = std::numeric_limits<unsigned short>::max();
    for(unsigned int i = 0; i < minSizeElementPairs.size(); i++)
    {
      for(unsigned int j = 0; j < minSizeElementPairs[i].second.size(); j++)
      {
        if(min > minSizeElementPairs[i].second[j])
        {
          min = minSizeElementPairs[i].second[j];
        }
      }
    }
    for(unsigned int i = 0; i < minSizeElementPairs.size(); i++)
    {
      for(unsigned int j = 0; j < minSizeElementPairs[i].second.size(); j++)
      {
        if(min == minSizeElementPairs[i].second[j])
        {
          minSizeElementPairs[i].second.erase(minSizeElementPairs[i].second.begin()+j);
          minSizeElementPairsTmp.push_back(minSizeElementPairs[i]);
          break;
        }
      }
    }
    minSizeElementPairs.clear();
    for(unsigned int i = 0; i < minSizeElementPairsTmp.size(); i++)
    {
      minSizeElementPairs.push_back(minSizeElementPairsTmp[i]);
    }
    minSizeElementPairsTmp.clear();
  }

  for(unsigned int i = 0; i < elementPairs.size(); i++)
  {
    if(elementPairs[i].first == minSizeElementPairs[0].first)
    {
      referencePartitions = elementPairs[i].second;
      break;
    }
  }
  
  return minSizeElementPairs[0].first;
}

void getPartitionInVector(std::vector<unsigned short> &partitions, const std::vector< std::pair<MElement*, std::vector<unsigned short> > > &boundaryPair)
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
  
  std::sort(partitions.begin(), partitions.end());
}

template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector< std::pair<MElement*, std::vector<unsigned short> > >, Hash_Face, Equal_Face> &faceToElement, std::vector<unsigned short> &partitions, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumFaces(); i++)
    {
      faceToElement[(*it)->getFace(i)].push_back(std::pair<MElement*, std::vector<unsigned short> >(*it,partitions));
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector< std::pair<MElement*, std::vector<unsigned short> > > , Hash_Edge, Equal_Edge> &edgeToElement, std::vector<unsigned short> &partitions, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumEdges(); i++)
    {
      edgeToElement[(*it)->getEdge(i)].push_back(std::pair<MElement*, std::vector<unsigned short> >(*it,partitions));
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector< std::pair<MElement*, std::vector<unsigned short> > > > &vertexToElement, std::vector<unsigned short> &partitions, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < getNumVertices(*it); i++)
    {
      vertexToElement[(*it)->getVertex(i)].push_back(std::pair<MElement*, std::vector<unsigned short> >(*it,partitions));
    }
  }
}

void assignPartitionBoundary(GModel *const model, MFace &me, MElement* reference, std::vector<unsigned short> partitions, std::set<partitionFace*, Less_partitionFace> &pfaces)
{
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
    std::string name = "_sigma{";
    for(unsigned int j = 0; j < ppf->_partitions.size(); j++)
    {
      if(j > 0) name += ",";
      name += std::to_string(ppf->_partitions[j]);
    }
    name += "}";
    
    int number = model->getPhysicalNumber(ppf->dim(), name);
    if(number == -1) number = model->numPhysicalNames()+1;
    model->setPhysicalName(name, ppf->dim(), number);
    ppf->addPhysicalEntity(number);
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
    
    for(unsigned int i = 0; i < verts.size(); i++) ppf->addMeshVertex(verts[i]);
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
    
    for(unsigned int i = 0; i < verts.size(); i++) ppf->addMeshVertex(verts[i]);
  }
}

void assignPartitionBoundary(GModel *const model, MEdge &me, MElement* reference, std::vector<unsigned short> partitions, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::set<partitionEdge*, Less_partitionEdge> &bndedges)
{
  bool boundariesOfPartition = partitions.size() > 2 ? true : false;
  
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
      std::string name = "_bndSigma{";
      for(unsigned int j = 0; j < ppe->_partitions.size(); j++)
      {
        if(j > 0) name += ",";
        name += std::to_string(ppe->_partitions[j]);
      }
      name += "}";
      
      int number = model->getPhysicalNumber(ppe->dim(), name);
      if(number == -1) number = model->numPhysicalNames()+1;
      model->setPhysicalName(name, ppe->dim(), number);
      ppe->addPhysicalEntity(number);
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
      std::string name = "_sigma{";
      for(unsigned int j = 0; j < ppe->_partitions.size(); j++)
      {
        if(j > 0) name += ",";
        name += std::to_string(ppe->_partitions[j]);
      }
      name += "}";
      
      int number = model->getPhysicalNumber(ppe->dim(), name);
      if(number == -1) number = model->numPhysicalNames()+1;
      model->setPhysicalName(name, ppe->dim(), number);
      ppe->addPhysicalEntity(number);
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
    
    for(unsigned int i = 0; i < verts.size(); i++) ppe->addMeshVertex(verts[i]);
  }
}

void assignPartitionBoundary(GModel *const model, MVertex *ve, MElement* reference, std::vector<unsigned short> partitions, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces, std::set<partitionEdge*, Less_partitionEdge> &bndedges, std::set<partitionVertex*, Less_partitionVertex> &bndvertices)
{
  bool boundariesOfPartition = partitions.size() > 2 ? true : false;
  
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
      std::string name = "_bndSigma{";
      for(unsigned int j = 0; j < ppv->_partitions.size(); j++)
      {
        if(j > 0) name += ",";
        name += std::to_string(ppv->_partitions[j]);
      }
      name += "}";
      
      int number = model->getPhysicalNumber(ppv->dim(), name);
      if(number == -1) number = model->numPhysicalNames()+1;
      model->setPhysicalName(name, ppv->dim(), number);
      ppv->addPhysicalEntity(number);
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
      std::string name = "_sigma{";
      for(unsigned int j = 0; j < ppv->_partitions.size(); j++)
      {
        if(j > 0) name += ",";
        name += std::to_string(ppv->_partitions[j]);
      }
      name += "}";
      
      int number = model->getPhysicalNumber(ppv->dim(), name);
      if(number == -1) number = model->numPhysicalNames()+1;
      model->setPhysicalName(name, ppv->dim(), number);
      ppv->addPhysicalEntity(number);
    }
    else
    {
      ppv = *it;
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

void AssignMeshVertices(GModel *model, int dim)
{
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
  {
    if(entities[i]->dim() == dim || dim == -1) entities[i]->mesh_vertices.clear();
  }
  
  std::set<MVertex *> verts;
  
  //Loop over vertices
  if(dim == 0 || dim == -1)
  {
    for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
    {
      setVerticesToEntity(verts, *it, (*it)->points.begin(), (*it)->points.end());
    }
  }
  
  //Loop over edges
  if(dim == 1 || dim == -1)
  {
    for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
    {
      setVerticesToEntity(verts, *it, (*it)->lines.begin(), (*it)->lines.end());
    }
  }
  
  //Loop over faces
  if(dim == 2 || dim == -1)
  {
    for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
    {
      setVerticesToEntity(verts, *it, (*it)->triangles.begin(), (*it)->triangles.end());
      setVerticesToEntity(verts, *it, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
    }
  }
  
  //Loop over regions
  if(dim == 3 || dim == -1)
  {
    for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
    {
      setVerticesToEntity(verts, *it, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      setVerticesToEntity(verts, *it, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      setVerticesToEntity(verts, *it, (*it)->prisms.begin(), (*it)->prisms.end());
      setVerticesToEntity(verts, *it, (*it)->pyramids.begin(), (*it)->pyramids.end());
      setVerticesToEntity(verts, *it, (*it)->trihedra.begin(), (*it)->trihedra.end());
    }
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
 *                        0 = success
 *                        1 = error
 *
 *
 ******************************************************************************/

int CreateTopologyFile(GModel* model, std::string name)
{
  std::multimap<unsigned short, GEntity*> newPartitionEntities;
  std::multimap<unsigned short, GEntity*> newPartitionBoundaries;
  std::multimap<unsigned short, GEntity*> newBoundariesOfPartitionBoundaries;
  
  std::vector<GEntity*> entities;
  model->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++)
  {
    switch(entities[i]->geomType())
    {
      case GEntity::PartitionVolume:
        if(static_cast<partitionRegion*>(entities[i])->_partitions.size() == 0)
        {
          continue;
        }
        else if(static_cast<partitionRegion*>(entities[i])->_partitions.size() == 1)
        {
          newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionRegion*>(entities[i])->_partitions[0], entities[i]));
        }
        else
        {
          std::string substr  = getSubstr(model, entities[i]);
          if(substr == "_sigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionRegion*>(entities[i])->_partitions.size(); j++)
            {
              newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionRegion*>(entities[i])->_partitions[j], entities[i]));
            }
          }
          else if(substr == "_bndSigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionRegion*>(entities[i])->_partitions.size(); j++)
            {
              newBoundariesOfPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionRegion*>(entities[i])->_partitions[j], entities[i]));
            }
          }
        }
        break;
      case GEntity::PartitionSurface:
        if(static_cast<partitionFace*>(entities[i])->_partitions.size() == 0)
        {
          continue;
        }
        else if(static_cast<partitionFace*>(entities[i])->_partitions.size() == 1)
        {
          newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionFace*>(entities[i])->_partitions[0], entities[i]));
        }
        else
        {
          std::string substr  = getSubstr(model, entities[i]);
          if(substr == "_sigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionFace*>(entities[i])->_partitions.size(); j++)
            {
              newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionFace*>(entities[i])->_partitions[j], entities[i]));
            }
          }
          else if(substr == "_bndSigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionFace*>(entities[i])->_partitions.size(); j++)
            {
              newBoundariesOfPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionFace*>(entities[i])->_partitions[j], entities[i]));
            }
          }
        }
        break;
      case GEntity::PartitionCurve:
        if(static_cast<partitionEdge*>(entities[i])->_partitions.size() == 0)
        {
          continue;
        }
        else if(static_cast<partitionEdge*>(entities[i])->_partitions.size() == 1)
        {
          newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionEdge*>(entities[i])->_partitions[0], entities[i]));
        }
        else
        {
          std::string substr  = getSubstr(model, entities[i]);
          if(substr == "_sigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->_partitions.size(); j++)
            {
              newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionEdge*>(entities[i])->_partitions[j], entities[i]));
            }
          }
          else if(substr == "_bndSigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionEdge*>(entities[i])->_partitions.size(); j++)
            {
              newBoundariesOfPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionEdge*>(entities[i])->_partitions[j], entities[i]));
            }
          }
        }
        break;
      case GEntity::PartitionVertex:
        if(static_cast<partitionVertex*>(entities[i])->_partitions.size() == 0)
        {
          continue;
        }
        else if(static_cast<partitionVertex*>(entities[i])->_partitions.size() == 1)
        {
          newPartitionEntities.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionVertex*>(entities[i])->_partitions[0], entities[i]));
        }
        else
        {
          std::string substr  = getSubstr(model, entities[i]);
          if(substr == "_sigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->_partitions.size(); j++)
            {
              newPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionVertex*>(entities[i])->_partitions[j], entities[i]));
            }
          }
          else if(substr == "_bndSigma")
          {
            for(unsigned int j = 0; j < static_cast<partitionVertex*>(entities[i])->_partitions.size(); j++)
            {
              newBoundariesOfPartitionBoundaries.insert(std::pair<unsigned short, GEntity*>(static_cast<partitionVertex*>(entities[i])->_partitions[j], entities[i]));
            }
          }
        }
        break;
      default:
        break;
    }
  }
  
  const unsigned short npart = CTX::instance()->mesh.num_partitions;
  std::ofstream file(name, std::ofstream::trunc);
  
  if(!file.is_open()) return 1;
  
  //-----------Group-----------
  file << "Group{" << std::endl;
  
  //Omega_i
  for(unsigned short i = 0; i < npart; i++)
  {
    std::pair <std::multimap<unsigned short, GEntity*>::iterator, std::multimap<unsigned short, GEntity*>::iterator> range;
    range = newPartitionEntities.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned short, GEntity*>::iterator it = range.first; it != range.second; ++it)
    {
      physicalTags.insert(getTag(model, it->second));
    }
    
    file << "\tOmega_" << i << " = Region[{";
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it)
    {
      if(it != physicalTags.begin()) file << ", ";
      file << *it;
    }
    file << "}];" << std::endl;
  }
  file << std::endl;
  
  //Sigma_i
  for(unsigned short i = 0; i < npart; i++)
  {
    std::pair <std::multimap<unsigned short, GEntity*>::iterator, std::multimap<unsigned short, GEntity*>::iterator> range;
    range = newPartitionBoundaries.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned short, GEntity*>::iterator it = range.first; it != range.second; ++it)
    {
      physicalTags.insert(getTag(model, it->second));
    }
    
    file << "\tSigma_" << i << " = Region[{";
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it)
    {
      if(it != physicalTags.begin()) file << ", ";
      file << *it;
    }
    file << "}];" << std::endl;
  }
  file << std::endl;
  
  //Sigma_i_j  
  for(std::multimap<unsigned short, GEntity*>::iterator it1 = newPartitionBoundaries.begin(); it1 != newPartitionBoundaries.end(); ++it1)
  {
    for(std::multimap<unsigned short, GEntity*>::iterator it2 = newPartitionBoundaries.begin(); it2 != newPartitionBoundaries.end(); ++it2)
    {
      if(it2->second == it1->second && *it2 != *it1)
      {
        file << "\tSigma_" << it1->first << "_" << it2->first << " = Region[{" << getTag(model, it1->second) << "}];" << std::endl;
      }
    }
  }
  file << std::endl;
  
  //BndSigma_i
  for(unsigned short i = 0; i < npart; i++)
  {
    std::pair <std::multimap<unsigned short, GEntity*>::iterator, std::multimap<unsigned short, GEntity*>::iterator> range;
    range = newBoundariesOfPartitionBoundaries.equal_range(i);
    
    std::set<int> physicalTags;
    for(std::multimap<unsigned short, GEntity*>::iterator it = range.first; it != range.second; ++it)
    {
      physicalTags.insert(getTag(model, it->second));
    }
    
    file << "\tBndSigma_" << i << " = Region[{";
    for(std::set<int>::iterator it = physicalTags.begin(); it != physicalTags.end(); ++it)
    {
      if(it != physicalTags.begin()) file << ", ";
      file << *it;
    }
    file << "}];" << std::endl;
  }
  file << std::endl;
  
  //BndSigma_i_j
  for(std::multimap<unsigned short, GEntity*>::iterator it1 = newBoundariesOfPartitionBoundaries.begin(); it1 != newBoundariesOfPartitionBoundaries.end(); ++it1)
  {
    for(std::multimap<unsigned short, GEntity*>::iterator it2 = newBoundariesOfPartitionBoundaries.begin(); it2 != newBoundariesOfPartitionBoundaries.end(); ++it2)
    {
      if(it2->second == it1->second && it2 != it1)
      {
        file << "\tBndSigma_" << it1->first << "_" << it2->first << " = Region[{" << getTag(model, it1->second) << "}];" << std::endl;
      }
    }
  }
  file << std::endl;
  
  //D
  file << "\tD() = {";
  for(unsigned int i = 0; i < npart; i++)
  {
    if(i != 0) file << ", ";
    file << i;
  }
  file << "};" << std::endl;
  
  //D_i
  std::multimap<unsigned short, unsigned short> neighbors;
  for(std::multimap<unsigned short, GEntity*>::iterator it = newPartitionBoundaries.begin(); it != newPartitionBoundaries.end(); ++it)
  {
    if(it->second->geomType() == GEntity::PartitionSurface)
    {
      for(unsigned int i = 0; i < static_cast<partitionFace*>(it->second)->_partitions.size(); i++)
      {
        neighbors.insert(std::pair<unsigned short, unsigned short>(it->first, static_cast<partitionFace*>(it->second)->_partitions[i]));
      }
    }
    else if(it->second->geomType() == GEntity::PartitionCurve)
    {
      for(unsigned int i = 0; i < static_cast<partitionEdge*>(it->second)->_partitions.size(); i++)
      {
        neighbors.insert(std::pair<unsigned short, unsigned short>(it->first, static_cast<partitionEdge*>(it->second)->_partitions[i]));
      }
    }
    else if(it->second->geomType() == GEntity::PartitionVertex)
    {
      for(unsigned int i = 0; i < static_cast<partitionVertex*>(it->second)->_partitions.size(); i++)
      {
        neighbors.insert(std::pair<unsigned short, unsigned short>(it->first, static_cast<partitionVertex*>(it->second)->_partitions[i]));
      }
    }
  }
  for(std::multimap<unsigned short, GEntity*>::iterator it = newBoundariesOfPartitionBoundaries.begin(); it != newBoundariesOfPartitionBoundaries.end(); ++it)
  {
    if(it->second->geomType() == GEntity::PartitionCurve)
    {
      for(unsigned int i = 0; i < static_cast<partitionEdge*>(it->second)->_partitions.size(); i++)
      {
        neighbors.insert(std::pair<unsigned short, unsigned short>(it->first, static_cast<partitionEdge*>(it->second)->_partitions[i]));
      }
    }
    else if(it->second->geomType() == GEntity::PartitionVertex)
    {
      for(unsigned int i = 0; i < static_cast<partitionVertex*>(it->second)->_partitions.size(); i++)
      {
        neighbors.insert(std::pair<unsigned short, unsigned short>(it->first, static_cast<partitionVertex*>(it->second)->_partitions[i]));
      }
    }
  }
  
  for(unsigned int i = 0; i < npart; i++)
  {
    std::pair <std::multimap<unsigned short, unsigned short>::iterator, std::multimap<unsigned short, unsigned short>::iterator> range;
    range = neighbors.equal_range(i);
    std::vector<unsigned short> writeNeighbors;
    file << "\tD_" << i << "() = {";
    int j = 0;
    for(std::multimap<unsigned short, unsigned short>::iterator it = range.first; it != range.second; ++it)
    {
      if(std::find(writeNeighbors.begin(), writeNeighbors.end(), it->second) == writeNeighbors.end() && i != it->second)
      {
        if(j != 0) file << ", ";
        file << it->second;
        writeNeighbors.push_back(it->second);
        j++;
      }
    }
    file << "};" << std::endl;
  }
  
  file << "}" << std::endl << std::endl;
  
  return 0;
}

int getTag(GModel* model, GEntity* entity)
{
  std::vector<int> tags = entity->getPhysicalEntities();
  for(unsigned int i = 0; i < tags.size(); i++)
  {
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
  for(unsigned int i = 0; i < tags.size(); i++)
  {
    std::string name = model->getPhysicalName(entity->dim(),tags[i]);
    
    std::string str;
    if(name[0] != '_') continue;
    for(unsigned int j = 0; j < name.length(); j++)
    {
      if(name[j] == '{')
      {
        substr += str;
        break;
      }
      else if(name[j] == ' ') continue;
      else if(name[j] == '}') break;
      else
      {
        str += name[j];
      }
    }
  }
  
  return substr;
}

std::vector<unsigned short> getPartition(GModel* model, GEntity* entity)
{
  std::vector<int> tags = entity->getPhysicalEntities();
  std::vector<unsigned short> partitions;
  for(unsigned int i = 0; i < tags.size(); i++)
  {
    std::string name = model->getPhysicalName(entity->dim(),tags[i]);
    
    std::string integer;
    if(name[0] != '_') continue;
    for(unsigned int j = 0; j < name.length(); j++)
    {
      if(name[j] == '{')
      {
        integer.clear();
      }
      else if(name[j] == ',')
      {
        partitions.push_back(stoi(integer));
        integer.clear();
      }
      else if(name[j] == ' ') continue;
      else if(name[j] == '}')
      {
        partitions.push_back(stoi(integer));
        break;
      }
      else
      {
        integer += name[j];
      }
    }
  }
  
  return partitions;
}

/*******************************************************************************
 *
 * Routine DividedNonConnectedEntities
 *
 * Purpose
 * =======
 *
 *   Divide non connected entities
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

void DivideNonConnectedEntities(GModel *model)
{
  //Loop over vertices
  for(GModel::const_viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionVertex)
    {
      if((*it)->getNumMeshElements() > 1)
      {
        for(unsigned int i = 1; i < (*it)->getNumMeshElements(); i++)
        {
          //Create the new partitionVertex
          partitionVertex *pvertex = new partitionVertex(model, model->getMaxElementaryNumber(0)+1, static_cast<partitionVertex*>(*it)->_partitions);
          //Assign physicals
          std::vector<int> physicalTags = (*it)->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++)
          {
            pvertex->addPhysicalEntity(physicalTags[j]);
          }
          //Add to model
          model->add(pvertex);
          //Add elements
          pvertex->addElement((*it)->getMeshElement(i)->getType() ,(*it)->getMeshElement(i));
          //Remove elements
          std::vector<MPoint*>::iterator iter = std::find((*it)->points.begin(), (*it)->points.end(), static_cast<MPoint*>((*it)->getMeshElement(i)));
          if(iter != (*it)->points.end()) (*it)->points.erase(iter);
        }
      }
    }
  }
  
  //Loop over edges
  for(GModel::const_eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionCurve)
    {
      std::unordered_map<MVertex*, std::vector<MElement*> > vertexToElement;
      fillVertexToElement(vertexToElement, (*it)->lines.begin(), (*it)->lines.end());
      
      std::set<MElement*> connectedElements;
      while(1)
      {
        fillConnectedElements(connectedElements, vertexToElement, (*it)->getMeshElement(0));
        
        if((*it)->getNumMeshElements() != connectedElements.size())
        {
          //Create the new partitionEdge
          partitionEdge *pedge = new partitionEdge(model, model->getMaxElementaryNumber(1)+1, NULL, NULL, static_cast<partitionEdge*>(*it)->_partitions);
          //Assign physicals
          std::vector<int> physicalTags = (*it)->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++)
          {
            pedge->addPhysicalEntity(physicalTags[j]);
          }
          //Add to model
          model->add(pedge);
          for(std::set<MElement*>::iterator itSet = connectedElements.begin(); itSet != connectedElements.end(); ++itSet)
          {
            //Add elements
            pedge->addElement((*itSet)->getType() ,(*itSet));
            //Remove elements
            std::vector<MLine*>::iterator iter = std::find((*it)->lines.begin(), (*it)->lines.end(), static_cast<MLine*>(*itSet));
            if(iter != (*it)->lines.end()) (*it)->lines.erase(iter);
          }
        }
        else
        {
          break;
        }
      
        connectedElements.clear();
      }
    }
  }
  
  //Loop over faces
  for(GModel::const_fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionSurface)
    {
      std::unordered_map<MEdge, std::vector<MElement*>, Hash_Edge, Equal_Edge> edgeToElement;
      fillEdgeToElement(edgeToElement, (*it)->triangles.begin(), (*it)->triangles.end());
      fillEdgeToElement(edgeToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
      
      std::set<MElement*> connectedElements;
      while(1)
      {
        fillConnectedElements(connectedElements, edgeToElement, (*it)->getMeshElement(0));
        
        if((*it)->getNumMeshElements() != connectedElements.size())
        {
          //Create the new partitionFace
          partitionFace *pface = new partitionFace(model, model->getMaxElementaryNumber(2)+1, static_cast<partitionFace*>(*it)->_partitions);
          //Assign physicals
          std::vector<int> physicalTags = (*it)->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++)
          {
            pface->addPhysicalEntity(physicalTags[j]);
          }
          //Add to model
          model->add(pface);
          for(std::set<MElement*>::iterator itSet = connectedElements.begin(); itSet != connectedElements.end(); ++itSet)
          {
            //Add elements
            pface->addElement((*itSet)->getType() ,(*itSet));
            //Remove elements
            switch ((*itSet)->getType())
            {
              case TYPE_TRI:
              {
                std::vector<MTriangle*>::iterator iter = std::find((*it)->triangles.begin(), (*it)->triangles.end(), static_cast<MTriangle*>(*itSet));
                if(iter != (*it)->triangles.end()) (*it)->triangles.erase(iter);
              }
                break;
              case TYPE_QUA:
              {
                std::vector<MQuadrangle*>::iterator iter = std::find((*it)->quadrangles.begin(), (*it)->quadrangles.end(), static_cast<MQuadrangle*>(*itSet));
                if(iter != (*it)->quadrangles.end()) (*it)->quadrangles.erase(iter);
              }
                break;
              default:
                break;
            }
          }
        }
        else
        {
          break;
        }
        
        connectedElements.clear();
      }
    }
  }
  
  //Loop over regions
  for(GModel::const_riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    if((*it)->geomType() == GEntity::PartitionVolume)
    {
      std::unordered_map<MEdge, std::vector<MElement*>, Hash_Edge, Equal_Edge> faceToElement;
      fillEdgeToElement(faceToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      fillEdgeToElement(faceToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      fillEdgeToElement(faceToElement, (*it)->prisms.begin(), (*it)->prisms.end());
      fillEdgeToElement(faceToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
      fillEdgeToElement(faceToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
      
      std::set<MElement*> connectedElements;
      while(1)
      {
        fillConnectedElements(connectedElements, faceToElement, (*it)->getMeshElement(0));
        
        if((*it)->getNumMeshElements() != connectedElements.size())
        {
          //Create the new partitionRegion
          partitionRegion *pregion = new partitionRegion(model, model->getMaxElementaryNumber(3)+1, static_cast<partitionRegion*>(*it)->_partitions);
          //Assign physicals
          std::vector<int> physicalTags = (*it)->getPhysicalEntities();
          for(unsigned int j = 0; j < physicalTags.size(); j++)
          {
            pregion->addPhysicalEntity(physicalTags[j]);
          }
          //Add to model
          model->add(pregion);
          for(std::set<MElement*>::iterator itSet = connectedElements.begin(); itSet != connectedElements.end(); ++itSet)
          {
            //Add elements
            pregion->addElement((*itSet)->getType() ,(*itSet));
            //Remove elements
            switch ((*itSet)->getType())
            {
              case TYPE_TET:
              {
                std::vector<MTetrahedron*>::iterator iter = std::find((*it)->tetrahedra.begin(), (*it)->tetrahedra.end(), static_cast<MTetrahedron*>(*itSet));
                if(iter != (*it)->tetrahedra.end()) (*it)->tetrahedra.erase(iter);
              }
                break;
              case TYPE_HEX:
              {
                std::vector<MHexahedron*>::iterator iter = std::find((*it)->hexahedra.begin(), (*it)->hexahedra.end(), static_cast<MHexahedron*>(*itSet));
                if(iter != (*it)->hexahedra.end()) (*it)->hexahedra.erase(iter);
              }
                break;
              case TYPE_PRI:
              {
                std::vector<MPrism*>::iterator iter = std::find((*it)->prisms.begin(), (*it)->prisms.end(), static_cast<MPrism*>(*itSet));
                if(iter != (*it)->prisms.end()) (*it)->prisms.erase(iter);
              }
                break;
              case TYPE_PYR:
              {
                std::vector<MPyramid*>::iterator iter = std::find((*it)->pyramids.begin(), (*it)->pyramids.end(), static_cast<MPyramid*>(*itSet));
                if(iter != (*it)->pyramids.end()) (*it)->pyramids.erase(iter);
              }
                break;
              case TYPE_TRIH:
              {
                std::vector<MTrihedron*>::iterator iter = std::find((*it)->trihedra.begin(), (*it)->trihedra.end(), static_cast<MTrihedron*>(*itSet));
                if(iter != (*it)->trihedra.end()) (*it)->trihedra.erase(iter);
              }
                break;
              default:
                break;
            }
          }
        }
        else
        {
          break;
        }
        
        connectedElements.clear();
      }
    }
  }
}

template <class ITERATOR>
void fillVertexToElement(std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < getNumVertices(*it); i++)
    {
      vertexToElement[(*it)->getVertex(i)].push_back(*it);
    }
  }
}

void fillConnectedElements(std::set<MElement*> &connectedElements, std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, MElement *element)
{
  std::stack<MElement*> elements;
  elements.push(element);
  while(elements.size() != 0)
  {
    MElement* top = elements.top();
    elements.pop();
    
    if(connectedElements.find(top) == connectedElements.end())
    {
      connectedElements.insert(top);
    }
    else
    {
      return;
    }
    
    for(unsigned int i = 0; i < getNumVertices(top); i++)
    {
      for(unsigned int j = 0; j < vertexToElement[top->getVertex(i)].size(); j++)
      {
        elements.push(vertexToElement[top->getVertex(i)][j]);
      }
    }
  }
}

template <class ITERATOR>
void fillEdgeToElement(std::unordered_map<MEdge, std::vector<MElement*>, Hash_Edge, Equal_Edge> &edgeToElement, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumEdges(); i++)
    {
      edgeToElement[(*it)->getEdge(i)].push_back(*it);
    }
  }
}

void fillConnectedElements(std::set<MElement*> &connectedElements, std::unordered_map<MEdge, std::vector<MElement*>, Hash_Edge, Equal_Edge> &edgeToElement, MElement *element)
{
  std::stack<MElement*> elements;
  elements.push(element);
  while(elements.size() != 0)
  {
    MElement* top = elements.top();
    elements.pop();
    
    if(connectedElements.find(top) == connectedElements.end())
    {
      connectedElements.insert(top);
    }
    else
    {
      return;
    }
    
    for(unsigned int i = 0; i < top->getNumEdges(); i++)
    {
      for(unsigned int j = 0; j < edgeToElement[top->getEdge(i)].size(); j++)
      {
        elements.push(edgeToElement[top->getEdge(i)][j]);
      }
    }
  }
}

template <class ITERATOR>
void fillFaceToElement(std::unordered_map<MFace, std::vector<MElement*>, Hash_Face, Equal_Face> &faceToElement, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR it = it_beg; it != it_end ; ++it)
  {
    for(unsigned int i = 0; i < (*it)->getNumFaces(); i++)
    {
      faceToElement[(*it)->getFace(i)].push_back(*it);
    }
  }
}

void fillConnectedElements(std::set<MElement*> &connectedElements, std::unordered_map<MFace, std::vector<MElement*>, Hash_Face, Equal_Face> &faceToElement, MElement *element)
{
  std::stack<MElement*> elements;
  elements.push(element);
  while(elements.size() != 0)
  {
    MElement* top = elements.top();
    elements.pop();
    
    if(connectedElements.find(top) == connectedElements.end())
    {
      connectedElements.insert(top);
    }
    else
    {
      return;
    }
    
    for(unsigned int i = 0; i < top->getNumFaces(); i++)
    {
      for(unsigned int j = 0; j < faceToElement[top->getFace(i)].size(); j++)
      {
        elements.push(faceToElement[top->getFace(i)][j]);
      }
    }
  }
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
