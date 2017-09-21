// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Partition.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include <fstream>

#include "GmshConfig.h"
#include "meshPartition.h"
#include "meshPartitionOptions.h"

#if defined(HAVE_CHACO) || defined(HAVE_METIS)

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
  Graph graph;
  Msg::StatusBar(true, "IN DEVELOPEMENT");
  Msg::StatusBar(true, "Building mesh graph...");
  int ier = MakeGraph(model, graph);
  Msg::StatusBar(true, "Partitioning graph...");
  if(!ier) ier = PartitionGraph(graph, options);
  if(ier) return 1;

  // Assign partitions to internal elements
  int *partition = graph.partition;

  for(unsigned int i = 0; i < graph.ne; i++)
  {
    graph.element[i]->setPartition(partition[i]+1);
  }

  model->recomputeMeshPartitions();
  
  if(options.createPartitionEntities)
  {
    CreateNewEntities(model, options);
  }
  
  if (options.createPartitionBoundaries || options.createGhostCells)
  {
    CreatePartitionBoundaries(model, options.createGhostCells);
  }
  
  if (options.createTopologyFile && options.createPartitionEntities && (options.createPartitionBoundaries || options.createGhostCells))
  {
    CreateTopologyFile(model, options.num_partitions);
  }
  
  AssignMeshVertices(model);
  model->writePartitionedMSH("mesh");
  
  Msg::StatusBar(true, "Done partitioning graph");
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
  std::multimap<MElement*, int> elementsToNodes;
  
  //Loop over regions
  for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    const GRegion *r = *it;
    
    fillElementsToNodesMap(elementsToNodes, r->tetrahedra.begin(), r->tetrahedra.end());
    fillElementsToNodesMap(elementsToNodes, r->hexahedra.begin(), r->hexahedra.end());
    fillElementsToNodesMap(elementsToNodes, r->prisms.begin(), r->prisms.end());
    fillElementsToNodesMap(elementsToNodes, r->pyramids.begin(), r->pyramids.end());
    fillElementsToNodesMap(elementsToNodes, r->trihedra.begin(), r->trihedra.end());
  }
  
  //Loop over faces
  for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    const GFace *f = *it;
    
    fillElementsToNodesMap(elementsToNodes, f->triangles.begin(), f->triangles.end());
    fillElementsToNodesMap(elementsToNodes, f->quadrangles.begin(), f->quadrangles.end());
  }
  
  //Loop over edges
  for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    const GEdge *e = *it;
    
    fillElementsToNodesMap(elementsToNodes, e->lines.begin(), e->lines.end());
  }
  
  if(elementsToNodes.size() == 0)
  {
    Msg::Error("No mesh elements were found");
    return 1;
  }
  
  //Loop over vertices
  for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    GVertex *v = *it;
    
    fillElementsToNodesMap(elementsToNodes, v->points.begin(), v->points.end());
  }
  
  //Mesh data structure (eptr and eind)
  int *eptr = new int[model->getNumMeshElements()+1];
  graph.element.resize(model->getNumMeshElements());
  eptr[0] = 0;
  unsigned int eindPosition = 0;
  unsigned int eptrIndex = 0;
  MElement* currentElement;
  
  for(std::multimap<MElement*, int>::const_iterator it = elementsToNodes.begin(); it != elementsToNodes.end(); ++it)
  {
    if(currentElement != it->first)
    {
      graph.element[eptrIndex] = it->first;
      eindPosition += elementsToNodes.count(it->first);
      eptr[eptrIndex+1] = eindPosition;
      eptrIndex++;
      currentElement = it->first;
    }
  }
  
  int *eind = new int[eindPosition];
  unsigned int eindIndex = 0;
  
  for(std::multimap<MElement*, int>::const_iterator it = elementsToNodes.begin(); it != elementsToNodes.end(); ++it)
  {
    eind[eindIndex] = it->second;
    eindIndex++;
  }
  
  graph.ne = model->getNumMeshElements();
  graph.nn = model->getNumMeshVertices();
  graph.dim = model->getDim();
  graph.eptr = eptr;
  graph.eind = eind;
  
  return 0;
}

template <class ITERATOR>
void fillElementsToNodesMap(std::multimap<MElement*, int> &elementsToNodes, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    for(unsigned int j = 0; j < (*it)->getNumVertices(); j++)
    {
      elementsToNodes.insert(std::pair<MElement*, int>((*it),(*it)->getVertex(j)->getNum()-1));
    }
  }
}

/*******************************************************************************
 *
 * Routine PartitionGraph
 *
 * Purpose
 * =======
 *
 *   Partition a graph created by MakeGraph using Chaco or Metis library
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
  switch(options.partitioner){
    case 1:  // Chaco
#ifdef HAVE_CHACO
    {
      Msg::Info("Chaco not yet implemented");
    }
#endif
      break;
    case 2:  // Metis
#ifdef HAVE_METIS
    {
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
          case 3: //Sorted heavy-edge matching
            metisOptions[METIS_OPTION_CTYPE] = METIS_CTYPE_SHEM;
            break;
          default:
            Msg::Info("Unknown partition edge matching");
            break;
        }
        
        switch(options.refine_algorithm)
        {
          case 2: //Greedy boundary refinement
            metisOptions[METIS_OPTION_RTYPE] = METIS_RTYPE_GREEDY;
            break;
          default:
            Msg::Info("Unknown partition refine algorithm");
            break;
        }
        
        metisOptions[METIS_OPTION_NUMBERING] = 0; //C numbering

        const int nCommon = graph.dim;
        int objval;
        int *epart = new int[graph.ne];
        int *npart = new int[graph.nn];
        
        graph.fillDefaultWeights();
      
        const int metisError = METIS_PartMeshDual((idx_t *)&graph.ne, (idx_t *)&graph.nn, (idx_t *)graph.eptr, (idx_t *)graph.eind, (idx_t *)graph.vwgt, (idx_t *)NULL, (idx_t *)&nCommon, (idx_t *)&options.num_partitions, (real_t *)NULL, (idx_t *)metisOptions, (idx_t *)&objval, (idx_t *)epart, (idx_t *)npart);
        
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
        
        graph.partition = epart;
        delete[] npart;
        
        Msg::Info("Total communication volume : %d", objval);
      }
      catch(...) {
        Msg::Error("METIS threw an exception");
        return 2;
      }
    }
#endif
      break;
  }
  return 0;
}

/*******************************************************************************
 *
 * Routine RenumberMesh
 *
 * Purpose
 * =======
 *
 *   Renumber the elements into a mesh
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        1 = success
 *
 *
 *
 ******************************************************************************/

int RenumberMesh(GModel *const model, meshPartitionOptions &options)
{
  for (GModel::fiter it = model->firstFace() ; it != model->lastFace() ; ++it)
  {
    std::vector<MElement *> temp;
    
    temp.insert(temp.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
    RenumberMeshElements(temp, options);
    (*it)->triangles.clear();
    for(unsigned int i = 0; i <temp.size(); i++)
    {
      (*it)->triangles.push_back((MTriangle*)temp[i]);
    }
    temp.clear();
    
    temp.insert(temp.begin(),(*it)->quadrangles.begin(),(*it)->quadrangles.end());
    RenumberMeshElements (temp, options);
    (*it)->quadrangles.clear();
    for(unsigned int i = 0; i < temp.size(); i++)
    {
      (*it)->quadrangles.push_back((MQuadrangle*)temp[i]);
    }
  }
  
  for (GModel::riter it = model->firstRegion() ; it != model->lastRegion() ; ++it)
  {
    std::vector<MElement *> temp;
    
    temp.insert(temp.begin(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
    RenumberMeshElements(temp, options);
    (*it)->tetrahedra.clear();
    for (unsigned int i = 0; i < temp.size(); i++)
    {
      (*it)->tetrahedra.push_back((MTetrahedron*)temp[i]);
    }
    temp.clear();
    
    temp.insert(temp.begin(),(*it)->hexahedra.begin(),(*it)->hexahedra.end());
    RenumberMeshElements(temp, options);
    (*it)->hexahedra.clear();
    for (unsigned int i = 0; i < temp.size(); i++)
    {
      (*it)->hexahedra.push_back((MHexahedron*)temp[i]);
    }
  }
  
  return 1;
}

int RenumberMeshElements(std::vector<MElement*> &elements, meshPartitionOptions &options)
{
  Msg::Warning("Mesh renumbering is still experimental...");
  if (elements.size() < 3) return 1;
  GModel *tmp_model = new GModel();
  std::set<MVertex *> setv;
  for (unsigned i = 0; i < elements.size(); ++i)
    for(int j = 0; j < elements[i]->getNumVertices(); j++)
      setv.insert(elements[i]->getVertex(j));
  
  if (elements[0]->getDim() == 2){
    GFace *gf = new discreteFace(tmp_model, 1);
    for (std::set<MVertex* >::iterator it = setv.begin(); it != setv.end(); it++)
      gf->mesh_vertices.push_back(*it);
    for (std::vector<MElement* >::iterator it = elements.begin(); it != elements.end(); it++){
      if ((*it)->getType() == TYPE_TRI)
        gf->triangles.push_back((MTriangle*)(*it));
      else if  ((*it)->getType() == TYPE_QUA)
        gf->quadrangles.push_back((MQuadrangle*)(*it));
    }
    tmp_model->add(gf);
    RenumberMesh(tmp_model, options, elements);
    tmp_model->remove(gf);
  }
  else if (elements[0]->getDim() == 3){
    GRegion *gr = new discreteRegion(tmp_model, 1);
    for (std::set<MVertex* >::iterator it = setv.begin(); it != setv.end(); it++)
      gr->mesh_vertices.push_back(*it);
    for (std::vector<MElement* >::iterator it = elements.begin(); it != elements.end(); it++){
      if ((*it)->getType() == TYPE_TET)
        gr->tetrahedra.push_back((MTetrahedron*)(*it));
      else if  ((*it)->getType() == TYPE_HEX)
        gr->hexahedra.push_back((MHexahedron*)(*it));
      else if  ((*it)->getType() == TYPE_PRI)
        gr->prisms.push_back((MPrism*)(*it));
      else if  ((*it)->getType() == TYPE_PYR)
        gr->pyramids.push_back((MPyramid*)(*it));
      else if  ((*it)->getType() == TYPE_TRIH)
        gr->trihedra.push_back((MTrihedron*)(*it));
    }
    tmp_model->add(gr);
    RenumberMesh(tmp_model, options, elements);
    tmp_model->remove(gr);
  }
  delete tmp_model;
  return 1;
}

int RenumberMesh(GModel *const model, meshPartitionOptions &options, std::vector<MElement*> &numbered)
{
  Graph graph;
  int ier;
  Msg::StatusBar(true, "Building graph...");
  ier = MakeGraph(model, graph);
  Msg::StatusBar(true, "Renumbering graph...");
  if(!ier) ier = RenumberGraph(graph, options);
  if(ier) return 1;
  
  // create the numbering
  numbered.clear();
  const int n = graph.nn;
  numbered.resize(n);
  for(int i = 0; i != n; ++i) {
    numbered[graph.partition[i]-1] = graph.element[i];
  }
  
  Msg::StatusBar(true, "Done renumbering graph");
  return 0;
}

int RenumberGraph(Graph &graph, meshPartitionOptions &options)
{
  int ier = 0;
#ifdef HAVE_METIS
  {
    Msg::Info("Launching METIS graph renumberer");
    try {
      int numFlag = 0;
      int nCommon = graph.dim;
      int metisError = METIS_MeshToDual((idx_t *)&graph.ne, (idx_t *)&graph.nn, (idx_t *)graph.eptr, (idx_t *)graph.eind, (idx_t *)&nCommon, (idx_t *)&numFlag, (idx_t **)&graph.xadj, (idx_t **)&graph.adjncy);
      
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
      
      int options = 0;
      int *perm = new int[graph.ne];
      metisError = METIS_NodeND((idx_t *)&graph.ne, (idx_t *)graph.xadj, (idx_t *)graph.adjncy, (idx_t *)graph.vwgt, (idx_t *)&options, (idx_t *)perm, (idx_t *)graph.partition);
      
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
      
      delete [] perm;
    }
    catch(...) {
      Msg::Error("METIS threw an exception");
      ier = 2;
    }
  }
#endif
  return ier;
}

/*******************************************************************************
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
 *   returns            - status
 *                        1 = success
 *
 *
 *
 ******************************************************************************/

int CreateNewEntities(GModel *model, meshPartitionOptions &options)
{
  std::vector<discreteRegion *> dRegions;
  std::vector<GRegion *> oldRegions;
  for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    GRegion *region = *it;
    std::vector<GRegion *> newRegions(options.num_partitions, NULL);
    
    assignElementsToEntities(model, newRegions, region, dRegions, region->tetrahedra.begin(), region->tetrahedra.end());
    assignElementsToEntities(model, newRegions, region, dRegions, region->hexahedra.begin(), region->hexahedra.end());
    assignElementsToEntities(model, newRegions, region, dRegions, region->prisms.begin(), region->prisms.end());
    assignElementsToEntities(model, newRegions, region, dRegions, region->pyramids.begin(), region->pyramids.end());
    assignElementsToEntities(model, newRegions, region, dRegions, region->trihedra.begin(), region->trihedra.end());
    
    oldRegions.push_back(region);
  }
  for(unsigned int i = 0; i < oldRegions.size(); i++)
  {
    model->remove(oldRegions[i]);
  }
  for(unsigned int i = 0; i < dRegions.size(); i++)
  {
    model->add(dRegions[i]);
  }
  
  std::vector<discreteFace *> dFaces;
  std::vector<GFace *> oldFaces;
  for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    GFace *face = *it;
    std::vector<GFace *> newFaces(options.num_partitions, NULL);
    
    assignElementsToEntities(model, newFaces, face, dFaces, face->triangles.begin(), face->triangles.end());
    assignElementsToEntities(model, newFaces, face, dFaces, face->quadrangles.begin(), face->quadrangles.end());
    
    oldFaces.push_back(face);
  }
  for(unsigned int i = 0; i < oldFaces.size(); i++)
  {
    model->remove(oldFaces[i]);
  }
  for(unsigned int i = 0; i < dFaces.size(); i++)
  {
    model->add(dFaces[i]);
  }
  
  std::vector<discreteEdge *> dEdges;
  std::vector<GEdge *> oldEdges;
  for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    GEdge *edge = *it;
    std::vector<GEdge *> newEdges(options.num_partitions, NULL);
    
    assignElementsToEntities(model, newEdges, edge, dEdges, edge->lines.begin(), edge->lines.end());
    
    oldEdges.push_back(edge);
  }
  for(unsigned int i = 0; i < oldEdges.size(); i++)
  {
    model->remove(oldEdges[i]);
  }
  for(unsigned int i = 0; i < dEdges.size(); i++)
  {
    model->add(dEdges[i]);
  }
  
  std::vector<discreteVertex *> dVertices;
  std::vector<GVertex *> oldVertices;
  for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    GVertex *vertex = *it;
    std::vector<GVertex *> newVertices(options.num_partitions, NULL);
    
    assignElementsToEntities(model, newVertices, vertex, dVertices, vertex->points.begin(), vertex->points.end());
    
    oldVertices.push_back(vertex);
  }
  for(unsigned int i = 0; i < oldVertices.size(); i++)
  {
    model->remove(oldVertices[i]);
  }
  for(unsigned int i = 0; i < dVertices.size(); i++)
  {
    model->add(dVertices[i]);
  }
  
  return 1;
}

template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GRegion *> &newRegions, GRegion *region, std::vector<discreteRegion *> &dRegions, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = (*it)->getPartition()-1;
    
    if(newRegions[partition] == NULL)
    {
      discreteRegion *dr = new discreteRegion(model, model->getNumRegions()+1+dRegions.size());
      dRegions.push_back(dr);
      newRegions[partition] = dr;
      
      addPhysical(model, dr, region, partition);
    }
    
    switch((*it)->getType())
    {
      case TYPE_TET:
        newRegions[partition]->addTetrahedron((MTetrahedron*)(*it));
        break;
      case TYPE_PYR:
        newRegions[partition]->addPyramid((MPyramid*)(*it));
        break;
      case TYPE_PRI:
        newRegions[partition]->addPrism((MPrism*)(*it));
        break;
      case TYPE_HEX:
        newRegions[partition]->addHexahedron((MHexahedron*)(*it));
        break;
      default:
        break;
    }
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      (*it)->getVertex(i)->setEntity(newRegions[partition]);
    }
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GFace *> &newFaces, GFace *face, std::vector<discreteFace *> &dFaces, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = (*it)->getPartition()-1;
    
    if(newFaces[partition] == NULL)
    {
      discreteFace *df = new discreteFace(model, model->getNumFaces()+1+dFaces.size());
      dFaces.push_back(df);
      newFaces[partition] = df;
      
      addPhysical(model, df, face, partition);
    }
    
    switch((*it)->getType())
    {
      case TYPE_TRI:
        newFaces[partition]->addTriangle((MTriangle*)(*it));
        break;
      case TYPE_QUA:
        newFaces[partition]->addQuadrangle((MQuadrangle*)(*it));
        break;
      default:
        break;
    }
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      (*it)->getVertex(i)->setEntity(newFaces[partition]);
    }
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GEdge *> &newEdges, GEdge *edge, std::vector<discreteEdge *> &dEdges, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = (*it)->getPartition()-1;
    
    if(newEdges[partition] == NULL)
    {
      discreteEdge *de = new discreteEdge(model, model->getNumEdges()+1+dEdges.size(), NULL, NULL);
      dEdges.push_back(de);
      newEdges[partition] = de;
      
      addPhysical(model, de, edge, partition);
    }
    
    newEdges[partition]->addLine((MLine*)(*it));
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      (*it)->getVertex(i)->setEntity(newEdges[partition]);
    }
  }
}

template <class ITERATOR>
void assignElementsToEntities(GModel *model, std::vector<GVertex *> &newVertices, GVertex *vertex, std::vector<discreteVertex *> &dVertices, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    const int partition = (*it)->getPartition()-1;
    
    if(newVertices[partition] == NULL)
    {
      discreteVertex *dv = new discreteVertex(model, model->getNumVertices()+1+dVertices.size());
      dVertices.push_back(dv);
      newVertices[partition] = dv;
      
      addPhysical(model, dv, vertex, partition);
    }
    
    newVertices[partition]->addPoint((MPoint*)(*it));
    
    for(unsigned int i = 0; i < (*it)->getNumVertices(); i++)
    {
      (*it)->getVertex(i)->setEntity(newVertices[partition]);
    }
  }
}

void addPhysical(GModel *model, GEntity *newEntity, GEntity *oldEntity, int partition)
{
  std::vector<int> oldPhysical = oldEntity->getPhysicalEntities();
  std::string name;
  
  if(model->getDim() == newEntity->dim())
  {
    name = "_omega{";
    name += std::to_string(partition);
    name += "}";
        
    const int number = model->getMaxPhysicalNumber(-1)+partition+1;
    model->setPhysicalName(name, newEntity->dim(), number);
    newEntity->addPhysicalEntity(number);
  }
  
  for(unsigned int i = 0; i < oldPhysical.size(); i++)
  {
    name = model->getPhysicalName(oldEntity->dim(), oldPhysical[i]);
    
    if(name[0] != '_')
    {
      newEntity->addPhysicalEntity(oldPhysical[i]);
    }
  }
}


/*******************************************************************************
 *
 * Routine CreatePartitionBoundaries
 *
 * Purpose
 * =======
 *
 *   Create the new entities between each partitions
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        1 = success
 *
 *
 *
 ******************************************************************************/

int CreatePartitionBoundaries(GModel *model, bool createGhostCells)
{
  unsigned int numElem[6];
  const int meshDim = model->getNumMeshElements(numElem);
    
  std::set<partitionFace*, Less_partitionFace> pfaces;
  std::set<partitionEdge*, Less_partitionEdge> pedges;
  std::set<partitionVertex*, Less_partitionVertex> pvertices;
    
  std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face> faceToElement;
  std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge> edgeToElement;
  std::unordered_map<MVertex*, std::vector<MElement*> > vertexToElement;
    
  //Create partition faces
  Msg::Info("Creating partition faces... ");
  if (meshDim == 3)
  {
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
    {
      fillit_(faceToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      fillit_(faceToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      fillit_(faceToElement, (*it)->prisms.begin(), (*it)->prisms.end());
      fillit_(faceToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
      fillit_(faceToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
      fillit_(faceToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
    }
      
    for(std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face>::const_iterator it = faceToElement.begin(); it != faceToElement.end(); ++it)
    {
      MFace f = it->first;
      std::vector<MElement*> voe = it->second;
        
      assignPartitionBoundary(model, f, pfaces, voe);
    }
  }
  
  //Create partition edges
  Msg::Info("Creating partition edges... ");
  if (meshDim >= 2)
  {
    if (meshDim == 2)
    {
      for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      {
        fillit_(edgeToElement, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(edgeToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(edgeToElement, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
      
    if (meshDim == 3)
    {
      for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      {
        fillit_(edgeToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
        fillit_(edgeToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
        fillit_(edgeToElement, (*it)->prisms.begin(), (*it)->prisms.end());
        fillit_(edgeToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
        fillit_(edgeToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
        fillit_(edgeToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
      }
    }
      
    for(std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge>::const_iterator it = edgeToElement.begin(); it != edgeToElement.end(); ++it)
    {
      MEdge e = it->first;
      
      std::vector<MElement*> voe = it->second;
      
      assignPartitionBoundary(model, e, pedges, voe, pfaces);
    }
  }
  
  //Create partition vertices
  Msg::Info("Creating partition vertices... ");
  if (meshDim >= 1)
  {
    if (meshDim == 1)
    {
      for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
      {
        fillit_(vertexToElement, (*it)->lines.begin(), (*it)->lines.end());
      }
    }
    
    if (meshDim == 2)
    {
      for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
      {
        fillit_(vertexToElement, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(vertexToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(vertexToElement, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
      
    if (meshDim == 3)
    {
      for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
      {
        fillit_(vertexToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
        fillit_(vertexToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
        fillit_(vertexToElement, (*it)->prisms.begin(), (*it)->prisms.end());
        fillit_(vertexToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
        fillit_(vertexToElement, (*it)->trihedra.begin(), (*it)->trihedra.end());
        fillit_(vertexToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
      }
    }
      
    for(std::unordered_map<MVertex*, std::vector<MElement*> >::const_iterator it = vertexToElement.begin(); it != vertexToElement.end(); ++it)
    {
      MVertex *v = it->first;
      std::vector<MElement*> voe = it->second;
        
      assignPartitionBoundary(model, v, pvertices, voe, pedges, pfaces);
    }
  }
    
  return 1;
}

template <class ITERATOR>
void fillit_(std::unordered_map<MFace, std::vector<MElement*> , Hash_Face, Equal_Face> &faceToElement, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end ; ++IT)
  {
    MElement *el = *IT;
    for(unsigned int j = 0; j < el->getNumFaces(); j++)
    {
      faceToElement[el->getFace(j)].push_back(el);
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MEdge, std::vector<MElement*> , Hash_Edge, Equal_Edge> &edgeToElement, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end; ++IT)
  {
    MElement *el = *IT;
    for(unsigned int j = 0; j < el->getNumEdges(); j++)
    {
      edgeToElement[el->getEdge(j)].push_back(el);
    }
  }
}

template <class ITERATOR>
void fillit_(std::unordered_map<MVertex*, std::vector<MElement*> > &vertexToElement, ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end ; ++IT)
  {
    MElement *el = *IT;
    for(unsigned int j = 0; j < el->getNumVertices(); j++)
    {
      vertexToElement[el->getVertex(j)].push_back(el);
    }
  }
}

void assignPartitionBoundary(GModel *model, MFace &me, std::set<partitionFace*, Less_partitionFace> &pfaces, std::vector<MElement*> &v)
{
  std::vector<int> v2;
  v2.push_back(v[0]->getPartition());
  
  for (unsigned int i = 1; i < v.size(); i++)
  {
    bool found = false;
    for (unsigned int j = 0; j < v2.size(); j++)
    {
      if (v[i]->getPartition() == v2[j])
      {
        found = true;
        break;
      }
    }
    
    if (!found)
    {
      v2.push_back(v[i]->getPartition());
    }
  }
  
  //If there is less than two partitions touching the face: stop
  if (v2.size() < 2)
  {
    return;
  }
  
  const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
  
  partitionFace pf(model, 1, v2);
  std::set<partitionFace*, Less_partitionFace>::iterator it = pfaces.find(&pf);
  
  partitionFace *ppf;
  //Create the new partition entity for the mesh
  if (it == pfaces.end())
  {
    //Create new entity and add them to the model
    ppf = new  partitionFace(model, -(int)pfaces.size()-1, v2);
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
  for(unsigned int i = 0; i < v[0]->getNumFaces(); i++)
  {
    const MFace e = v[0]->getFace(i);
    if(e == me)
    {
      numFace = i;
      break;
    }
  }
  
  if(me.getNumVertices() == 3)
  {
    std::vector<MVertex*> verts;
    v[0]->getFaceVertices(numFace, verts);
    
    if(verts.size() == 3)
    {
      ppf->triangles.push_back(new MTriangle(verts));
    }
    else if(verts.size() == 6)
    {
      ppf->triangles.push_back(new MTriangle6(verts));
    }
    else
    {
      ppf->triangles.push_back(new MTriangleN(verts, verts[0]->getPolynomialOrder()));
    }
    
    for(unsigned int i = 0; i < verts.size(); i++)
    {
      ppf->addMeshVertex(verts[i]);
    }
  }
  else if(me.getNumVertices() == 4)
  {
    std::vector<MVertex*> verts;
    v[0]->getFaceVertices(numFace, verts);
    
    if(verts.size() == 4)
    {
      ppf->quadrangles.push_back(new MQuadrangle(verts));
    }
    else if(verts.size() == 8)
    {
      ppf->quadrangles.push_back(new MQuadrangle8(verts));
    }
    else if(verts.size() == 9)
    {
      ppf->quadrangles.push_back(new MQuadrangle9(verts));
    }
    else
    {
      ppf->quadrangles.push_back(new MQuadrangleN(verts, verts[0]->getPolynomialOrder()));
    }
    
    for(unsigned int i = 0; i < verts.size(); i++)
    {
      verts[i]->setEntity(ppf);
    }
  }
}

void assignPartitionBoundary(GModel *model, MEdge &me, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::vector<MElement*> &v, std::set<partitionFace*, Less_partitionFace> &pfaces)
{
  std::vector<int> v2;
  v2.push_back(v[0]->getPartition());
  
  for (unsigned int i = 1; i < v.size(); i++)
  {
    bool found = false;
    for (unsigned int j = 0; j < v2.size(); j++)
    {
      if (v[i]->getPartition() == v2[j])
      {
        found = true;
        break;
      }
    }
    
    if (!found)
    {
      v2.push_back(v[i]->getPartition());
    }
  }
  
  //If there is less than two partitions touching the edge: stop
  if (v2.size() < 2)
  {
    return;
  }
  
  partitionFace pf(model, 1, v2);
  std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
  
  //If the edge is on a partitionFace
  if (itf != pfaces.end())
  {
    return;
  }
  
  const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
  
  partitionEdge pe(model, 1, nullptr, nullptr, v2);
  std::set<partitionEdge*, Less_partitionEdge>::iterator it = pedges.find(&pe);
  
  partitionEdge *ppe;
  //Create the new partition entity for the mesh
  if (it == pedges.end())
  {
    //Create new entity and add them to the model
    ppe = new  partitionEdge(model, -(int)pedges.size()-1, 0, 0, v2);
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
  
  int numEdge = 0;
  for(unsigned int i = 0; i < v[0]->getNumEdges(); i++)
  {
    const MEdge e = v[0]->getEdge(i);
    if(e == me)
    {
      numEdge = i;
      break;
    }
  }
  
  if(me.getNumVertices() == 2)
  {
    std::vector<MVertex*> verts;
    v[0]->getEdgeVertices(numEdge, verts);
    
    if(verts.size() == 2)
    {
      ppe->lines.push_back(new MLine(verts));
    }
    else if(verts.size() == 3)
    {
      ppe->lines.push_back(new MLine3(verts));
    }
    else
    {
      ppe->lines.push_back(new MLineN(verts));
    }
    
    for(unsigned int i = 0; i < verts.size(); i++)
    {
      verts[i]->setEntity(ppe);
    }
  }
}

void assignPartitionBoundary(GModel *model, MVertex *ve, std::set<partitionVertex*, Less_partitionVertex> &pvertices, std::vector<MElement*> &v, std::set<partitionEdge*, Less_partitionEdge> &pedges, std::set<partitionFace*, Less_partitionFace> &pfaces)
{
  std::vector<int> v2;
  v2.push_back(v[0]->getPartition());
  
  for (unsigned int i = 1; i < v.size(); i++)
  {
    bool found = false;
    for (unsigned int j = 0; j < v2.size(); j++)
    {
      if (v[i]->getPartition() == v2[j])
      {
        found = true;
        break;
      }
    }
    
    if (!found)
    {
      v2.push_back(v[i]->getPartition());
    }
  }
  
  //If there is less than two partitions touching the vertex: stop
  if (v2.size() < 2)
  {
    return;
  }
  
  partitionFace pf(model, 1, v2);
  std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
  
  //If the vertex is on a partitionFace
  if (itf != pfaces.end())
  {
    return;
  }
  
  partitionEdge pe(model, 1, 0, 0, v2);
  std::set<partitionEdge*, Less_partitionEdge>::iterator ite = pedges.find(&pe);
  
  //If the vertex is on a partitionEdge
  if (ite != pedges.end())
  {
    return;
  }
  
  const int numPhysical = model->getMaxPhysicalNumber(-1)+1;
  
  partitionVertex pv(model, 1, v2);
  std::set<partitionVertex*, Less_partitionVertex>::iterator it = pvertices.find(&pv);
  
  partitionVertex *ppv;
  //Create the new partition entity for the mesh
  if (it == pvertices.end())
  {
    ppv = new partitionVertex(model, -(int)pvertices.size()-1,v2);
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
  
  ppv->points.push_back(new MPoint(ve));
  ve->setEntity(ppv);
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
  std::set<MVertex *> verts;
  
  //Loop over vertices
  for(GModel::viter it = model->firstVertex(); it != model->lastVertex(); ++it)
  {
    GVertex *v = *it;
    
    setVerticesToEntity(verts, v->points.begin(), v->points.end());
  }
  
  //Loop over edges
  for(GModel::eiter it = model->firstEdge(); it != model->lastEdge(); ++it)
  {
    const GEdge *e = *it;
    
    setVerticesToEntity(verts, e->lines.begin(), e->lines.end());
  }
  
  //Loop over faces
  for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it)
  {
    const GFace *f = *it;
    
    setVerticesToEntity(verts, f->triangles.begin(), f->triangles.end());
    setVerticesToEntity(verts, f->quadrangles.begin(), f->quadrangles.end());
  }
  
  //Loop over regions
  for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it)
  {
    const GRegion *r = *it;
    
    setVerticesToEntity(verts, r->tetrahedra.begin(), r->tetrahedra.end());
    setVerticesToEntity(verts, r->hexahedra.begin(), r->hexahedra.end());
    setVerticesToEntity(verts, r->prisms.begin(), r->prisms.end());
    setVerticesToEntity(verts, r->pyramids.begin(), r->pyramids.end());
    setVerticesToEntity(verts, r->trihedra.begin(), r->trihedra.end());
  }
}

template <class ITERATOR>
void setVerticesToEntity(std::set<MVertex *> &verts, ITERATOR it_beg, ITERATOR it_end)
{
  for(ITERATOR it = it_beg; it != it_end; ++it)
  {
    for(unsigned int j = 0; j < (*it)->getNumVertices(); j++)
    {
      if(verts.find((*it)->getVertex(j)) == verts.end())
      {
        (*it)->getVertex(j)->onWhat()->addMeshVertex((*it)->getVertex(j));
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
      
      std::vector<int> vec = listOfOmega[num[0]];
      vec.push_back(it->first.second);
      listOfOmega[num[0]] = vec;
    }
  }
  //Omega_i
  for(std::unordered_map<int, std::vector<int> >::iterator it = listOfOmega.begin(); it != listOfOmega.end(); ++it)
  {
    std::vector<int> vec = it->second;
    file << "\tOmega_" << it->first << " = Region[{";
    
    for(unsigned int i = 0; i < vec.size(); i++)
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
          std::vector<int> vec = listOfSigma[num[i]];
          vec.push_back(it->first.second);
          listOfSigma[num[i]] = vec;
        }
      }
      else
      {
        for(unsigned int i = 0; i < num.size(); i++)
        {
          std::vector<int> vec = listOfBndSigma[num[i]];
          vec.push_back(it->first.second);
          listOfBndSigma[num[i]] = vec;
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
    
    for(unsigned int i = 0; i < vec.size(); i++)
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
    
    for(unsigned int i = 0; i < vec.size(); i++)
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
  for(unsigned int i = 0; i < listOfOmega.size(); i++)
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
  
  for(unsigned int i = 0; i < elements.size(); ++i){
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
  Msg::Error("Gmsh must be compiled with METIS or Chaco support to partition meshes");
  return 0;
}


#endif
