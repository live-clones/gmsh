// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Partition.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include "GmshConfig.h"

#if defined(HAVE_CHACO) || defined(HAVE_METIS)

#include "GModel.h"
#include "meshPartition.h"
#include "meshPartitionObjects.h"
#include "meshPartitionOptions.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "MElementCut.h"
#include "MPoint.h"
#include "partitionVertex.h"
#include "partitionEdge.h"
#include "partitionFace.h"
#include "discreteEdge.h"
#include "discreteFace.h"
#include "GFaceCompound.h"
#include "Context.h"
#include "ExtrudeParams.h"


//--Prototype for Chaco interface

extern "C" int interface
(int nvtxs, int *start, int *adjacency, int *vwgts, float *ewgts,
 float *x, float *y, float *z,
 char *outassignname, char *outfilename,
 short *assignment,
 int architecture, int ndims_tot, int mesh_dims[3], double *goal,
 int global_method, int local_method, int rqi_flag, int vmax, int ndims,
 double eigtol, long seed,
 int refine_partition, int internal_vertices,
 int refine_map, int terminal_propogation);

//--Prototypes for METIS

typedef int idxtype;
extern "C" void METIS_PartGraphRecursive
(int *, idxtype *, idxtype *, idxtype *, idxtype *, int *, int *, int *, int *,
 int *, idxtype *);
extern "C" void METIS_PartGraphKway
(int *, idxtype *, idxtype *, idxtype *, idxtype *, int *, int *, int *, int *,
 int *, idxtype *);
extern "C" void METIS_NodeND(int *n,int *xadj,int *adjncy,int *numflag,int *options,int *perm,int *iperm);


/*==============================================================================
 * Traits classes - that return information about a type
 *============================================================================*/

template <typename FaceT> struct LFaceTr;
template <> struct LFaceTr<MEdge> 
{
  typedef std::map<MEdge, MElement*, Less_Edge> FaceMap;
};
template <> struct LFaceTr<MFace> 
{
  typedef std::map<MFace, MElement*, Less_Face> FaceMap;
};


/*==============================================================================
 * Forward declarations
 *============================================================================*/

template <unsigned DIM>
struct MakeGraphFromEntity;

template <unsigned DIM>
struct MatchBoElemToGrVertex;

struct BoElemGr;
typedef std::vector<BoElemGr> BoElemGrVec;

int MakeGraph(GModel *const model, Graph &graph,
              meshPartitionOptions &options, BoElemGrVec *const boElemGrVec = 0);

template <unsigned DIM, typename EntIter, typename EntIterBE>
void MakeGraphDIM(const EntIter begin, const EntIter end,
                  const EntIterBE beginBE, const EntIterBE endBE,
                  Graph &graph, BoElemGrVec *const boElemGrVec);

                  
/*******************************************************************************
 *
 * Routine partitionMesh
 *
 * Purpose
 * =======
 *
 *   Partitions the mesh.  This involves generating a graph, partitioning the
 *   graph, and then writing the partitions back to the mesh.
 *
 * Notes
 * =====
 *
 *   - The graph only consists of elements of the same dimension as the mesh.
 *   However, the graph making algorithm will also record boundary elements
 *   (elements with DIM-1) on the boundary and write a partition index to them.
 *
 ******************************************************************************/



int RenumberMesh(GModel *const model, meshPartitionOptions &options, 
                 std::vector<MElement*> &numbered)
{
  Graph graph;
  BoElemGrVec boElemGrVec;
  int ier;
  Msg::StatusBar(2, true, "Building graph...");
  ier = MakeGraph(model, graph, options, &boElemGrVec);
  Msg::StatusBar(2, true, "Renumbering graph...");
  if(!ier) ier = RenumberGraph(graph, options);
  if(ier) return 1;

  // create the numbering
  numbered.clear();
  const int n = graph.getNumVertex();
  numbered.resize(n);
  for(int i = 0; i != n; ++i) {
    numbered[graph.partition[i]-1] = graph.element[i];
  }

  Msg::StatusBar(2, true, "Done renumbering graph");
  return 0;
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
int RenumberMeshElements( std::vector<MElement*> &elements, meshPartitionOptions &options ){
  if (elements.size() < 3)return 1;
  GModel *tmp_model = new GModel();
  std::set<MVertex *> setv;
  for (unsigned i=0;i<elements.size();++i)
    for (int j=0;j<elements[i]->getNumVertices();j++)
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
    RenumberMesh(tmp_model,options,elements);    
    tmp_model->remove(gf);
  }
  else if (elements[0]->getDim() == 3){
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
  }
  delete tmp_model;
  return 1;
}

int RenumberMesh(GModel *const model, meshPartitionOptions &options)  
{
  for (GModel::fiter it = model->firstFace() ; it != model->lastFace() ; ++it){
    std::vector<MElement *> temp;

    temp.insert(temp.begin(), (*it)->triangles.begin(), (*it)->triangles.end());
    RenumberMeshElements(temp, options);
    (*it)->triangles.clear();
    for(unsigned int i = 0; i <temp.size(); i++)
      (*it)->triangles.push_back((MTriangle*)temp[i]);
    temp.clear();

    temp.insert(temp.begin(),(*it)->quadrangles.begin(),(*it)->quadrangles.end());
    RenumberMeshElements (temp,options);
    (*it)->quadrangles.clear();
    for(unsigned int i = 0; i < temp.size(); i++)
      (*it)->quadrangles.push_back((MQuadrangle*)temp[i]);
  }
  for (GModel::riter it = model->firstRegion() ; it != model->lastRegion() ; ++it){
    std::vector<MElement *> temp;

    temp.insert(temp.begin(), (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
    RenumberMeshElements(temp, options);
    (*it)->tetrahedra.clear();
    for (unsigned int i = 0; i < temp.size(); i++) 
      (*it)->tetrahedra.push_back((MTetrahedron*)temp[i]);
    temp.clear();

    temp.insert(temp.begin(),(*it)->hexahedra.begin(),(*it)->hexahedra.end());
    RenumberMeshElements (temp,options);
    (*it)->hexahedra.clear();
    for (unsigned int i = 0; i < temp.size(); i++) 
      (*it)->hexahedra.push_back((MHexahedron*)temp[i]);
  }
  return 1;
}

int PartitionMesh(GModel *const model, meshPartitionOptions &options)
{
  Graph graph;
  BoElemGrVec boElemGrVec;
  int ier;
  Msg::StatusBar(2, true, "Building graph...");
  ier = MakeGraph(model, graph, options, &boElemGrVec);
  Msg::StatusBar(2, true, "Partitioning graph...");
  if(!ier) ier = PartitionGraph(graph, options);
  if(ier) return 1;
    
  // Count partition sizes and assign partitions to internal elements
  std::vector<int> ssize(options.num_partitions, 0);
  const int n = graph.getNumVertex();
  for(int i = 0; i != n; ++i) {
    if (!options.partitionByExtrusion)
      ++ssize[graph.partition[i] - 1];
    graph.element[i]->setPartition(graph.partition[i]);
  }
  // Assign partitions to boundary elements
  const int nb = boElemGrVec.size();
  for(int i = 0; i != nb; ++i) {
    boElemGrVec[i].elem->setPartition(graph.partition[boElemGrVec[i].grVert]);
  }
  // propagate partition information to extruded elements
  if (options.partitionByExtrusion) {
    unsigned numElem[5];
    const int meshDim = model->getNumMeshElements(numElem);
    switch(meshDim) {
      case 2:
      // assing partitions for 2D faces and count number of elems in each partition
      for (GModel:: fiter fit = model->firstFace(); fit != model->lastFace(); fit++) {
        ExtrudeParams* epFace = (*fit)->meshAttributes.extrude;
        GEdge *sourceEdge = model->getEdgeByTag(std::abs(epFace->geo.Source));
        epFace->elementMap.propagatePartitionInformation(&ssize);
        // loop over extruded edges to set partitions
        std::list<GEdge*> regionEdges = (*fit)->edges();
        for (std::list<GEdge*>::iterator eit = regionEdges.begin(); eit != regionEdges.end(); eit++) {
          ExtrudeParams* epEdge = (*eit)->meshAttributes.extrude;
          if((*eit)!=sourceEdge && epEdge && !epEdge->elementMap.empty())
            epEdge->elementMap.propagatePartitionInformation();
        }
      }
        break;
      case 3:
      // assing partitions for 3D volumes and count number of elems in each partition
      for (GModel:: riter rit = model->firstRegion(); rit != model->lastRegion(); rit++) {
        ExtrudeParams* epRegion = (*rit)->meshAttributes.extrude;
        GFace *sourceFace = model->getFaceByTag(std::abs(epRegion->geo.Source));
        epRegion->elementMap.propagatePartitionInformation(&ssize);
        // loop over extruded faces to set partitions
        std::list<GFace*> regionFaces = (*rit)->faces();
        for (std::list<GFace*>::iterator fit = regionFaces.begin(); fit != regionFaces.end(); fit++) {
          if ((*fit) == sourceFace)
            continue;
          ExtrudeParams* epFace = (*fit)->meshAttributes.extrude;
          epFace->elementMap.propagatePartitionInformation();
          // loop over bounding edges to set partitions
          std::list<GEdge*> edges = (*fit)->edges();
          GEdge *sourceEdge = model->getEdgeByTag(std::abs(epFace->geo.Source));
          for (std::list<GEdge*>::iterator eit = edges.begin(); eit != edges.end(); eit++) {
            ExtrudeParams* epEdge = (*eit)->meshAttributes.extrude;
            if((*eit)!=sourceEdge && epEdge && epEdge->geo.Mode == COPIED_ENTITY)
              // extruded edges have no source elements (extruded from vertex)
              epEdge->elementMap.propagatePartitionInformation();
          }
        }
      } // TODO: generalize to 2D too
      break;
    }
  }
  int sMin = graph.getNumVertex();
  int sMax = 0;
  for(int i = 0; i != options.num_partitions; ++i) {
    sMin = std::min(sMin, ssize[i]);
    sMax = std::max(sMax, ssize[i]);
  }
  model->setMinPartitionSize(sMin);
  model->setMaxPartitionSize(sMax);

  model->recomputeMeshPartitions();

  if (options.createPartitionBoundaries || options.createGhostCells)
    CreatePartitionBoundaries (model, options.createGhostCells);

  Msg::StatusBar(2, true, "Done partitioning graph");
  return 0;
}


/*******************************************************************************
 *
 * Routine partitionGraph
 *
 * Purpose
 * =======
 *
 *   Partitions a graph.
 *
 ******************************************************************************/

int PartitionGraph(Graph &graph, meshPartitionOptions &options)
{

  int ier = 0;

  switch(options.partitioner){
  case 1:  // Chaco
#ifdef HAVE_CHACO
    {
      Msg::Info("Launching Chaco graph partitioner");
      // Some setup (similar to that of Chaco/input/input.c)
      if(options.global_method != 2) options.rqi_flag = 0;
      if(options.global_method == 1 || options.rqi_flag) {
        if (options.vmax < 2*(1 << options.ndims)) {
          options.vmax = 2*(1 << options.ndims);
        }
      }
      // Ensure num_partitions reflects values used by Chaco
      switch(options.architecture) {
      case 0:
        options.num_partitions = 1 << options.ndims_tot;
        break;
      case 1:
        options.num_partitions = options.mesh_dims[0];
        break;
      case 2:
        options.num_partitions = options.mesh_dims[0]*options.mesh_dims[1];
        break;
      case 3:
        options.num_partitions =
          options.mesh_dims[0]*options.mesh_dims[1]*options.mesh_dims[2];
        break;
      }
      try {
        const int iSec = 0;
        ier = interface
          (graph.getNumVertex(), &graph.xadj[graph.section[iSec]],
           &graph.adjncy[graph.section[iSec]], NULL, NULL,
           NULL, NULL, NULL,
           NULL, NULL,
           reinterpret_cast<short*>(&graph.partition[0]) + graph.section[iSec],
           options.architecture, options.ndims_tot, options.mesh_dims, NULL,
           options.global_method, options.local_method, options.rqi_flag,
           options.vmax, options.ndims, options.eigtol, options.seed,
           options.refine_partition, options.internal_vertices,
           options.refine_map, options.terminal_propogation);
        if(ier) Msg::Error("Chaco failed to partition the graph");
      }
      catch(...) {
        // A reason should be already written
        ier = 2;
      }
      if(!ier) graph.short2int();
    }
#endif
    break;
  case 2:  // Metis
#ifdef HAVE_METIS
    {
      Msg::Info("Launching METIS graph partitioner");
      // "C" numbering for Metis
      {
        int *p = &graph.adjncy[0];  //**Sections
        for(int n = graph.adjncy.size(); n--;) --(*p++);
      }
      try {
        int n = graph.getNumVertex();
        int wgtflag = 0;
        int numflag = 0;
        int metisOptions[5];
        int edgeCut;
        const int iSec = 0;
        switch(options.algorithm) {
        case 1:  // Recursive
          metisOptions[0] = 1;
          metisOptions[1] = options.edge_matching;
          metisOptions[2] = 1;
          metisOptions[3] = 1;
          metisOptions[4] = 0;
          METIS_PartGraphRecursive
            (&n, &graph.xadj[graph.section[iSec]],
             &graph.adjncy[graph.section[iSec]], NULL, NULL, &wgtflag, &numflag,
             &options.num_partitions, metisOptions, &edgeCut,
             &graph.partition[graph.section[iSec]]);
          break;
        case 2:  // K-way
          metisOptions[0] = 1;
          metisOptions[1] = options.edge_matching;
          metisOptions[2] = 1;
          metisOptions[3] = options.refine_algorithm;
          metisOptions[4] = 0;
          METIS_PartGraphKway
            (&n, &graph.xadj[graph.section[iSec]],
             &graph.adjncy[graph.section[iSec]], NULL, NULL, &wgtflag, &numflag,
             &options.num_partitions, metisOptions, &edgeCut,
             &graph.partition[graph.section[iSec]]);
          break;
        case 3:  // Nodal weight
          printf("METIS with weights\n");
          metisOptions[0] = 1;
          metisOptions[1] = options.edge_matching;
          metisOptions[2] = 1;
          metisOptions[3] = 1;
          metisOptions[4] = 0;
          wgtflag = 2;
          graph.fillWeights(options.nodalWeights);
          METIS_PartGraphKway
            (&n, &graph.xadj[graph.section[iSec]],
             &graph.adjncy[graph.section[iSec]], &graph.vwgts[graph.section[iSec]], NULL, &wgtflag, &numflag,
             &options.num_partitions, metisOptions, &edgeCut,
             &graph.partition[graph.section[iSec]]);
          break;
        }
      }
      catch(...) {
        Msg::Error("METIS threw an exception");
        ier = 2;
      }
      // Number partitions from 1
      if(!ier) {
        int *p = &graph.partition[0];  //**Sections
        for(int n = graph.getNumVertex(); n--;) ++(*p++);
      }
    }
#endif
    break;
  }
  return ier;
}

int RenumberGraph(Graph &graph, meshPartitionOptions &options)
{
  int ier = 0;
#ifdef HAVE_METIS
  {
    Msg::Info("Launching METIS graph renumberer");
    // "C" numbering for Metis
    {
      int *p = &graph.adjncy[0];  //**Sections
      for(int n = graph.adjncy.size(); n--;) --(*p++);
    }
    try {
      int n = graph.getNumVertex();
      int numflag = 0;
      const int iSec = 0;
      int options = 0;
      int *perm = new int[n];
      METIS_NodeND(&n, 
                   &graph.xadj[graph.section[iSec]],
                   &graph.adjncy[graph.section[iSec]], &numflag,&options,perm,&graph.partition[graph.section[iSec]]);
      delete [] perm;
    }
    catch(...) {
      Msg::Error("METIS threw an exception");
      ier = 2;
    }
    // Number elements from 1
    if(!ier) {
      int *p = &graph.partition[0];  //**Sections
      for(int n = graph.getNumVertex(); n--;) ++(*p++);
    }
  }
#endif
  return ier;
}

/*******************************************************************************
 *
 * Routine MakeGraph
 *
 * Purpose
 * =======
 *
 *   Creates a graph from the mesh with elements as the graph vertices and
 *   the faces between elements as the graph edges
 *
 * I/O
 * ===
 *
 *   returns            - status
 *                        0 = success
 *                        1 = no elements found
 *                        2 = exception thrown
 *
 ******************************************************************************/

int MakeGraph(GModel *const model, Graph &graph, meshPartitionOptions &options, BoElemGrVec *const boElemGrVec)
{

  enum {
    ElemTypeTetra = 0,
    ElemTypeHexa = 1,
    ElemTypePrism = 2,
    ElemTypePyramid = 3,
    ElemTypePolyh = 4
  };
  enum {
    ElemTypeTri = 0,
    ElemTypeQuad = 1,
    ElemTypePolyg = 2
  };

  int ier = 0;
//   switch(partitionScope) {
//   case PartitionEntireDomain:
  if(!options.partitionByExtrusion){
/*--------------------------------------------------------------------*
 * Make a graph for the entire domain
 *--------------------------------------------------------------------*/

    

//--Get the dimension of the mesh and count the numbers of elements

      unsigned numElem[5];
      const int meshDim = model->getNumMeshElements(numElem);
      if(meshDim < 2) {
        Msg::Error("No mesh elements were found");
        return 1;
      }

//--Make the graph

      switch(meshDim) {
      case 2:
        {
          try {
            // Allocate memory for the graph
            const int numGrVert = numElem[ElemTypeTri] + numElem[ElemTypeQuad]
                                  + numElem[ElemTypePolyg];
            const int maxGrEdge = (numElem[ElemTypeTri]*3 + numElem[ElemTypeQuad]*4
                                   + numElem[ElemTypePolyg]*4)/2;
            graph.allocate(numGrVert, maxGrEdge);
            // Make the graph
            MakeGraphDIM<2>(model->firstFace(), model->lastFace(),
                            model->firstEdge(), model->lastEdge(), graph,
                            boElemGrVec);
          }
          catch(...) {
            Msg::Error("Exception thrown during graph generation");
            ier = 2;
          }
        }
        break;
      case 3:
        {
          try {
            // Allocate memory for the graph
            const int numGrVert =
              numElem[ElemTypeTetra] + numElem[ElemTypeHexa] +
              numElem[ElemTypePrism] + numElem[ElemTypePyramid] +
              numElem[ElemTypePolyh];
            const int maxGrEdge =
              (numElem[ElemTypeTetra]*4 + numElem[ElemTypeHexa]*6 +
               numElem[ElemTypePrism]*5 + numElem[ElemTypePyramid]*5 +
               numElem[ElemTypePolyh]*5)/2;
            graph.allocate(numGrVert, maxGrEdge);
            // Make the graph
            MakeGraphDIM<3>(model->firstRegion(), model->lastRegion(),
                            model->firstFace(), model->lastFace(), graph,
                            boElemGrVec);
          }
          catch(...) {
            Msg::Error("Exception thrown during graph generation");
            ier = 2;
          }
        }
        break;
      }
    }
    else {
/*--------------------------------------------------------------------*
 * Create graph for extrusion source entity (propagate group ids later)
 *--------------------------------------------------------------------*/
      unsigned tmp[5];
      const int meshDim = model->getNumMeshElements(tmp);
      if(meshDim < 2) {
        Msg::Error("No mesh elements were found");
        return 1;
      }
      std::vector<const GEntity*> sourceEntities;
      std::set<const GEntity*> bannedEntities;
      unsigned numElem[5] = {0,0,0,0,0};
      switch(meshDim) {
        case 2:
          for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it){
            ExtrudeParams* ep = (*it)->meshAttributes.extrude;
            const GEdge *edge = model->getEdgeByTag(std::abs(ep->geo.Source));
            if(!edge){
              Msg::Error("Unknown source edge %d for extrusion", ep->geo.Source);
              continue;
            }
            // mark face for partitioning if not associated to already processed face
            if (bannedEntities.find(edge) == bannedEntities.end()) {
              sourceEntities.push_back(edge);
              edge->getNumMeshElements(numElem);
            }
            // do not allow partitioning of the extruded edges
            std::list<GEdge*> edges = (*it)->edges();
            for(std::list<GEdge*>::iterator eit = edges.begin(); eit != edges.end(); eit++) {
              bannedEntities.insert((*eit));
            }
          }
          break;
        case 3:
          for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it){
            ExtrudeParams* ep = (*it)->meshAttributes.extrude;
            const GFace *face = model->getFaceByTag(std::abs(ep->geo.Source));
            if(!face){
              Msg::Error("Unknown source surface %d for extrusion", ep->geo.Source);
              continue;
            }
            // mark face for partitioning if not associated to already processed region
            if (bannedEntities.find(face) == bannedEntities.end()) {
              sourceEntities.push_back(face);
              face->getNumMeshElements(numElem);
            }
            // do not allow partitioning of the extruded faces
            std::list<GFace*> faces = (*it)->faces();
            for(std::list<GFace*>::iterator fit = faces.begin(); fit != faces.end(); fit++) {
              bannedEntities.insert((*fit));
            }
          }
          break;
      }
      // build a graph only on the source entities
      try {
        // Allocate memory for the graph
        const int numGrVert = numElem[ElemTypeTri] + numElem[ElemTypeQuad]
                              + numElem[ElemTypePolyg];
        const int maxGrEdge = (numElem[ElemTypeTri]*3 + numElem[ElemTypeQuad]*4
                                + numElem[ElemTypePolyg]*4)/2;
        graph.allocate(numGrVert, maxGrEdge);
        // Make the graph
        MakeGraphDIM<2>(sourceEntities.begin(), sourceEntities.end(),
                        model->firstEdge(), model->lastEdge(), graph,
                        boElemGrVec);
      }
      catch (...){
        Msg::Error("Exception thrown during graph generation");
        ier = 2;
      }
    }
//     break;
    
//   case PartitionByPhysical:
//     {

// /*--------------------------------------------------------------------*
//  * Isolate each physical into a separate section of the graph
//  *--------------------------------------------------------------------*/

//       PhysGroupMap groups[4];           // vector of entities that belong to
//                                         // each physical group (in each
//                                         // dimension)

// //--Get a list of groups in each dimension and each of the entities in that
// //--group.  If no 2D or 3D physicals exist, dump all entities in one physical.

//       getPhysicalGroups(groups);
//       if(groups[face].size() + groups[region].size() == 0) {
//         // If no 2D or 3D physicals exist, pretend that there is one physical
//         // group ecompassing all the elements.
//         for(riter it = firstRegion(); it != lastRegion(); ++it)
//           if((*it)->tetrahedra.size() + (*it)->hexahedra.size() +
//              (*it)->prisms.size() + (*it)->pyramids.size() > 0)
//             groups[region][1].push_back(*it);
//         if(groups[region].size() == 0) {
//           // No 3D elements were found.  Look for 2D elements.
//           for(fiter it = firstFace(); it != lastFace(); ++it)
//             if((*it)->triangles.size() + (*it)->quadrangles.size() > 0)
//               groups[face][1].push_back(*it);
//           if(groups[face].size() == 0) {
//             Msg::Error("No mesh elements were found");
//             return;
//           }
//         }
//       }

//       const int meshDim = (groups[region].size()) ? 3 : 2;
//       switch(meshDim) {
//       case 2:
//         {
//           // Allocate memory for the graph
//           for(PhysGroupMap::iterator itPhys = groups[face].begin();
//               itPhys != groups[face].end(); ++itPhys) {
//             for(std::vector<GEntity*>::const_iterator entIt =
//                   physIt->second.begin(); entIt != physIt->second.end();
//                 ++entIt) {
//               const GFace *ent = static_cast<const GFace*>(*entIt);
//               numElem[ElemTypeTri] += ent->triangles.size();
//               numElem[ElemTypeQuad] += ent->quadrangles.size();
//             }
//           }
//           const int numGrVert = numElem[ElemTypeTri] + numElem[ElemTypeQuad];
//           if(numGrVert == 0) {
//             Msg::Error("No mesh elements were found");
//             return;
//           }
//           const int maxGrEdge =
//             (numElem[ElemTypeTri]*3 + numElem[ElemTypeQuad]*4)/2;
//           graph.allocate(numGrVert, maxGrEdge);

//           // Make the graph
//           for(PhysGroupMap::iterator itPhys = groups[face].begin();
//               itPhys != groups[face].end(); ++itPhys) {
//             MakeGraphDIM<2>(itPhys->second.begin(), itPhys->second.end(), graph);
//           }
//         }
//         break;
//       case 3:
//         {
//           // Allocate memory for the graph
//           for(PhysGroupMap::iterator itPhys = groups[region].begin();
//               itPhys != groups[region].end(); ++itPhys) {
//             for(std::vector<GEntity*>::const_iterator entIt =
//                   physIt->second.begin(); entIt != physIt->second.end();
//                 ++entIt) {
//               const GFace *ent = static_cast<const GFace*>(*entIt);
//               numElem[ElemTypeTetra] += ent->tetrahedra.size();
//               numElem[ElemTypeHexa] += ent->hexahedra.size();
//               numElem[ElemTypePrism] += ent->prisms.size();
//               numElem[ElemTypePyramid] += ent->pyramids.size();
//             }
//           }
//           const int numGrVert = numElem[ElemTypeTetra] + numElem[ElemTypeHexa] +
//             numElem[ElemTypePrism] + numElem[ElemTypePyramid];
//           if(numGrVert == 0) {
//             Msg::Error("No mesh elements were found");
//             return;
//           }
//           const int maxGrEdge =
//             (numElem[ElemTypeTetra]*4 + numElem[ElemTypeHexa]*6 +
//              (numElem[ElemTypePrism] + numElem[ElemTypePyramid])*5)/2;
//           graph.allocate(numGrVert, maxGrEdge);
          
//           // Make the graph
//           for(PhysGroupMap::iterator itPhys = groups[region].begin();
//               itPhys != groups[region].end(); ++itPhys) {
//             MakeGraphDIM<3>(itPhys->second.begin(), itPhys->second.end(), graph);
//           }
//         }
//         break;
//       }
//     }
//     break;
//   }

  // Close the adjacency arrays
  if(!ier) graph.close();
  return ier;

}


/*******************************************************************************
 *
 * Routine MakeGraphDIM
 *
 * Purpose
 * =======
 *
 *   Helps generate a graph - operates over a container of entities
 *
 ******************************************************************************/

template<unsigned DIM, typename EntIter, typename EntIterBE>
void MakeGraphDIM(const EntIter begin, const EntIter end,
                  const EntIterBE beginBE, const EntIterBE endBE,
                  Graph &graph, BoElemGrVec *const boElemGrVec)
{

  typedef typename DimTr<DIM>::FaceT FaceT;
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;

  graph.markSection();

  FaceMap faceMap;
  GrVertexMap grVertMap;

  for(EntIter entIt = begin; entIt != end; ++entIt) {
    MakeGraphFromEntity<DIM>::eval(*entIt, faceMap, grVertMap, graph);
  }

  // Write any graph vertices remaining in 'grVertMap'.  These are boundary
  // elements.
  const GrVertexMap::const_iterator grVertEnd = grVertMap.end();
  for(GrVertexMap::const_iterator grVertIt = grVertMap.begin();
      grVertIt != grVertEnd; ++grVertIt) {
    graph.add(grVertIt);
  }

  // Record the graph vertices the belong to the interior neighbour elements of
  // the boundary elements
  if(boElemGrVec) {
    boElemGrVec->reserve(faceMap.size());
    for(EntIterBE entIt = beginBE; entIt != endBE; ++entIt) {
      MatchBoElemToGrVertex<DIM>::eval
        (*entIt, faceMap, grVertMap, graph, *boElemGrVec);
    }
  }

}


/*******************************************************************************
 *
 * Struct MakeGraphFromEntity
 *
 * Purpose
 * =======
 *
 *   Helps generate a graph - operates on a single entity
 *
 ******************************************************************************/

template <unsigned DIM>
struct MakeGraphFromEntity
{
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;  // The corresponding map

  static void eval(const GEntity *const entity, FaceMap &faceMap,
                   GrVertexMap &grVertMap, Graph &graph)
  {
    unsigned numElem[5];
    numElem[0] = 0; numElem[1] = 0; numElem[2] = 0; numElem[3] = 0; numElem[4] = 0;
    entity->getNumMeshElements(numElem);
    // Loop over all types of elements
    int nType = entity->getNumElementTypes();
    for(int iType = 0; iType != nType; ++iType) {
      // Loop over all elements in a type
      const int nElem = numElem[iType];
      if(!nElem) continue;
      MElement *const *element = entity->getStartElementType(iType);
      for(int iElem = 0; iElem != nElem; ++iElem) {
        const int nFace = DimTr<DIM>::getNumFace(element[iElem]);
        // Insert this element into the map of graph vertices
        std::pair<typename GrVertexMap::iterator, bool> insGrVertMap =
          grVertMap.insert
          (std::pair<MElement*, GrVertex>
           (element[iElem], GrVertex(graph.getNextIndex(), nFace)));
        // Loop over all faces in the element
        for(int iFace = 0; iFace != nFace; ++iFace) {
          FaceT face = DimTr<DIM>::getFace(element[iElem], iFace);
          std::pair<typename FaceMap::iterator, bool> insFaceMap =
             faceMap.insert(std::pair<FaceT, MElement*>(face, element[iElem]));
          if(!insFaceMap.second) {
             // The face already exists
             typename GrVertexMap::iterator grVertIt2 =
                grVertMap.find(insFaceMap.first->second);
                                        // Iterator to the second graph vertex
                                        // that connects to this face
             // Update edges in both graph vertices
             grVertIt2->second.add(insGrVertMap.first->second.index);
             insGrVertMap.first->second.add(grVertIt2->second.index);
             if(grVertIt2->second.complete()) {
                // This graph vertex has complete connectivity.  Write and
                // delete.
                graph.add(grVertIt2);
                grVertMap.erase(grVertIt2);
             }
             // The face is no longer required
             faceMap.erase(insFaceMap.first);
          }
        }
        if(insGrVertMap.first->second.complete()) {
           // This graph vertex already has complete connectivity.  Write and
           // delete.
           graph.add(insGrVertMap.first);
           grVertMap.erase(insGrVertMap.first);
        }
      }
    }
  }
};


/*******************************************************************************
 *
 * Struct MatchBoElemToGrVertex
 *
 * Purpose
 * =======
 *
 *   Matches a boundary element (dimension DIM-1) to a vertex already in the
 *   graph.  This is used to update boundary elements with a partition number
 *
 ******************************************************************************/

template <unsigned DIM>
struct MatchBoElemToGrVertex
{
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;  // The corresponding map
      
  static void eval(const GEntity *const entity, const FaceMap &faceMap,
                   const GrVertexMap &grVertMap, const Graph &graph,
                   std::vector<BoElemGr> &boElemGrVec)
  {
    unsigned numElem[5];
    numElem[0] = 0; numElem[1] = 0; numElem[2] = 0; numElem[3] = 0; numElem[4] = 0;
    entity->getNumMeshElements(numElem);
    // Loop over all types of elements
    int nType = entity->getNumElementTypes();
    for(int iType = 0; iType != nType; ++iType) {
      // Loop over all elements in a type
      const int nElem = numElem[iType];
      if(!nElem) continue;
      MElement *const *element = entity->getStartElementType(iType);
      for(int iElem = 0; iElem != nElem; ++iElem) {
        FaceT face = DimTr<DIM>::getFace(element[iElem], 0);
        const typename FaceMap::const_iterator faceMapIt = faceMap.find(face);
        if(faceMapIt != faceMap.end()) {
          const typename GrVertexMap::const_iterator grVertMapIt =
            grVertMap.find(faceMapIt->second);
          boElemGrVec.push_back
            (BoElemGr(element[iElem],
                      graph.convertC2W(grVertMapIt->second.index) - 1));
        }
      }
    }
  }
};

template <class ITERATOR>
void fillit_(std::multimap<MFace, MElement*, Less_Face> &faceToElement,
             ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end ; ++IT){
    MElement *el = *IT;
    for(int j = 0; j < el->getNumFaces(); j++) {
      MFace e = el->getFace(j);
      faceToElement.insert(std::make_pair(e, el));
    }
  }
}

template <class ITERATOR>
void fillit_(std::multimap<MEdge, MElement*, Less_Edge> &edgeToElement,
             ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end; ++IT){
    MElement *el = *IT;
    for(int j = 0; j < el->getNumEdges(); j++) {
      MEdge e = el->getEdge(j);
      edgeToElement.insert(std::make_pair(e, el));
    }
  }
}

template <class ITERATOR>
void fillit_(std::multimap<MVertex*, MElement*> &vertexToElement,
             ITERATOR it_beg, ITERATOR it_end)
{
  for (ITERATOR IT = it_beg; IT != it_end ; ++IT){
    MElement *el = *IT;
    for(int j = 0; j < el->getNumVertices(); j++) {
      MVertex* e = el->getVertex(j);
      vertexToElement.insert(std::make_pair(e, el));
    }
  }
}

void assignPartitionBoundary(GModel *model, MFace &me,
                             std::set<partitionFace*, Less_partitionFace> &pfaces,
                             std::vector<MElement*> &v)
{
  std::vector<int> v2;
  v2.push_back(v[0]->getPartition());
  for (unsigned int i = 1; i < v.size(); i++){
    bool found = false;
    for (unsigned int j = 0; j < v2.size(); j++){
      if (v[i]->getPartition() == v2[j]){
        found = true;
        break;
      }
    }
    if (!found)v2.push_back(v[i]->getPartition());
  }
  if (v2.size() < 2)return;
  
  partitionFace pe(model, 1, v2);
  std::set<partitionFace*, Less_partitionFace>::iterator it = pfaces.find(&pe);
  partitionFace *ppe;
  if (it == pfaces.end()){
    ppe = new  partitionFace(model, -(int)pfaces.size()-1, v2);
    pfaces.insert (ppe);
    model->add(ppe);
    printf("*** Created partitionFace %d (", ppe->tag());
    for (unsigned int i = 0; i < v2.size(); ++i) printf("%d ", v2[i]);
    printf(")\n");
  }
  else ppe = *it;
  // to finish !!
  ppe->triangles.push_back(new MTriangle (me.getVertex(0),me.getVertex(1),
                                          me.getVertex(2)));
}

void assignPartitionBoundary(GModel *model,
                             MEdge &me,
                             std::set<partitionEdge*, Less_partitionEdge> &pedges,
                             std::vector<MElement*> &v,
                             std::set<partitionFace*, Less_partitionFace> &pfaces)
{
  std::vector<int> v2;
  v2.push_back(v[0]->getPartition());
  for (unsigned int i = 1; i < v.size(); i++){
    bool found = false;
    for (unsigned int j = 0; j < v2.size(); j++){
      if (v[i]->getPartition() == v2[j]){
        found = true;
        break;
      }
    }
    if (!found)v2.push_back(v[i]->getPartition());
  }
  if (v2.size() < 2)return;

  partitionFace pf(model, 1, v2);
  std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
  if (itf != pfaces.end())return;
  
  partitionEdge pe  (model, 1, 0, 0, v2);
  std::set<partitionEdge*, Less_partitionEdge>::iterator it = pedges.find(&pe);
  partitionEdge *ppe;
  if (it == pedges.end()){
    ppe = new  partitionEdge(model, -(int)pedges.size()-1, 0, 0, v2);
    pedges.insert (ppe);
    model->add(ppe);
  }
  else ppe = *it;
  ppe->lines.push_back(new MLine (me.getVertex(0),me.getVertex(1)));
}

void  splitBoundaryEdges(GModel *model,  std::set<partitionEdge*, Less_partitionEdge> &newEdges)
{

  for (std::set<partitionEdge*, Less_partitionEdge>::iterator it = newEdges.begin() ; it != newEdges.end() ; ++it){

    int nbSplit = 0;
    partitionEdge *ge = *it;
    std::list<MLine*> segments;
    for (unsigned int i = 0; i < ge->lines.size(); i++){
      segments.push_back(ge->lines[i]);
    }
    
    while (!segments.empty()) {
      std::vector<MLine*> myLines;
      std::list<MLine*>::iterator it = segments.begin();
      MVertex *vB = (*it)->getVertex(0);
      MVertex *vE = (*it)->getVertex(1);
      myLines.push_back(*it);
      segments.erase(it);
      it++;
      for (int i=0; i<2; i++) {
        for (std::list<MLine*>::iterator it = segments.begin() ; it != segments.end(); ++it){ 
          MVertex *v1 = (*it)->getVertex(0);
          MVertex *v2 = (*it)->getVertex(1);
          std::list<MLine*>::iterator itp;
          if (v1 == vE){
            myLines.push_back(*it);
            itp = it;
            it++;
            segments.erase(itp);
            vE = v2;
            i = -1;
          }
          else if (v2 == vE){
            myLines.push_back(*it);
            itp = it;
            it++;
            segments.erase(itp);
            vE = v1;
            i=-1;
          }
          if (it == segments.end()) break;
        }
        if (vB == vE) break;
        if (segments.empty()) break;
        MVertex *temp = vB;
        vB = vE;
        vE = temp;
      }
      if (nbSplit == 0 && segments.empty()) break; 
      int numEdge = model->getMaxElementaryNumber(1) + 1;
      discreteEdge *newGe = new discreteEdge(model, numEdge, 0, 0);
      newGe->lines.insert(newGe->lines.end(), myLines.begin(), myLines.end());
      model->add(newGe);
      newGe->orderMLines(); //this creates also mesh_vertices

      nbSplit++;
      printf("*** split partitionEdge with tag =%d\n", numEdge);      
    }
    if (nbSplit > 0) model->remove(ge);
  }
  
  return;

}

void assignPartitionBoundary(GModel *model,
                             MVertex *ve,
                             std::set<partitionVertex*, Less_partitionVertex> &pvertices,
                             std::vector<MElement*> &v,
                             std::set<partitionEdge*, Less_partitionEdge> &pedges,
                             std::set<partitionFace*, Less_partitionFace> &pfaces)
{
  std::vector<int> v2;
  v2.push_back(v[0]->getPartition());
  for (unsigned int i = 1; i < v.size(); i++){
    bool found = false;
    for (unsigned int j = 0; j < v2.size(); j++){
      if (v[i]->getPartition() == v2[j]){
        found = true;
        break;
      }
    }
    if (!found)v2.push_back(v[i]->getPartition());
  }
  if (v2.size() < 2)return;
  
  partitionFace pf(model, 1, v2);
  std::set<partitionFace*, Less_partitionFace>::iterator itf = pfaces.find(&pf);
  if (itf != pfaces.end()) return;

  partitionEdge pe(model, 1, 0, 0, v2);
  std::set<partitionEdge*, Less_partitionEdge>::iterator ite = pedges.find(&pe);
  if (ite != pedges.end()) return;

  partitionVertex pv(model, 1, v2);
  std::set<partitionVertex*, Less_partitionVertex>::iterator it = pvertices.find(&pv);
  partitionVertex *ppv;
  if (it == pvertices.end()){
    ppv = new  partitionVertex(model, -(int)pvertices.size()-1,v2);
    pvertices.insert (ppv);
    model->add(ppv);
  }
  else ppv = *it;
  ppv->points.push_back(new MPoint (ve));
}

static void addGhostCells(GEntity *ge, 
                          std::multimap<MVertex*, MElement*> &vertexToElement, 
                          std::multimap<MElement*, short> &ghosts)
{
  // get all the nodes on the partition boundary (we need to recompute
  // them, as they are not owned by the entity)
  std::set<MVertex*> verts;
  for(unsigned int i = 0; i < ge->getNumMeshElements(); i++){
    MElement *e = ge->getMeshElement(i);
    for(int j = 0; j < e->getNumVertices(); j++)
      verts.insert(e->getVertex(j));
  }
  
  // get all the elements that touch these nodes
  for(std::set<MVertex*>::iterator it = verts.begin(); it != verts.end(); it++){
    std::pair<std::multimap<MVertex*, MElement*>::iterator,
              std::multimap<MVertex*, MElement*>::iterator> pve =
      vertexToElement.equal_range(*it);
    // get all the partitions that touch this node
    std::set<short> parts;
    for(std::multimap<MVertex*, MElement*>::iterator ite = pve.first;
        ite != pve.second; ite++)
      parts.insert(ite->second->getPartition());
    // update the partition info for each element touching the node
    for(std::multimap<MVertex*, MElement*>::iterator ite = pve.first;
        ite != pve.second; ite++){
      MElement *e = ite->second;
      std::pair<std::multimap<MElement*, short>::iterator,
                std::multimap<MElement*, short>::iterator> peg =
        ghosts.equal_range(e);
      for(std::set<short>::iterator its = parts.begin(); its != parts.end(); its++){
        short partition = *its;
        bool skip = false;
        // insert the partition in the ghost map if 1) it's not
        // already there and 2) it's not the same as the partition the
        // element actually belongs to
        for(std::multimap<MElement*, short>::iterator itg = peg.first;
            itg != peg.second; itg++){
          if(partition == itg->second){
            skip = true;
            break;
          }
        }
        if(!skip && partition != e->getPartition())
          ghosts.insert(std::pair<MElement*, short>(e, partition));
      }
    }
  }
}

int CreatePartitionBoundaries(GModel *model, bool createGhostCells)
{
  unsigned numElem[5];
  const int meshDim = model->getNumMeshElements(numElem);
  std::set<partitionFace*, Less_partitionFace> pfaces;
  std::set<partitionEdge*, Less_partitionEdge> pedges;
  std::set<partitionVertex*, Less_partitionVertex> pvertices;

  std::multimap<MFace, MElement*, Less_Face> faceToElement;
  std::multimap<MEdge, MElement*, Less_Edge> edgeToElement;
  std::multimap<MVertex*, MElement*> vertexToElement;
  
  // create partition faces
  if (meshDim == 3){
    for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it){
      fillit_(faceToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
      fillit_(faceToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
      fillit_(faceToElement, (*it)->prisms.begin(), (*it)->prisms.end());
      fillit_(faceToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
      fillit_(faceToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
    }    
    std::multimap<MFace, MElement*, Less_Face>::iterator it = faceToElement.begin();
    Equal_Face oper;
    while (it != faceToElement.end()){
      MFace e = it->first;
      std::vector<MElement*> voe;
      do {
        voe.push_back(it->second);
        ++it;
        if (it ==  faceToElement.end()) break;
      } while (oper (e,it->first));
      assignPartitionBoundary(model, e, pfaces, voe);
    }
  }
  
  // create partition edges
  if (meshDim > 1){
    if (meshDim == 2){
      for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it){
        fillit_(edgeToElement, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(edgeToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(edgeToElement, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
    else if (meshDim == 3){
      for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it){
        fillit_(edgeToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
        fillit_(edgeToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
        fillit_(edgeToElement, (*it)->prisms.begin(), (*it)->prisms.end());
        fillit_(edgeToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
        fillit_(edgeToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
      }    
    }
    std::multimap<MEdge, MElement*, Less_Edge>::iterator it = edgeToElement.begin();
    Equal_Edge oper;
    while (it != edgeToElement.end()){
      MEdge e = it->first;
      std::vector<MElement*> voe;
      do {
        voe.push_back(it->second);
        ++it;
        if (it ==  edgeToElement.end()) break;
      }while (oper (e,it->first));
      assignPartitionBoundary(model, e, pedges, voe, pfaces);
    }
    //splitBoundaryEdges(model,pedges);
  }

  // create partition vertices
  if (meshDim > 1){
    if (meshDim == 2){
      for(GModel::fiter it = model->firstFace(); it != model->lastFace(); ++it){
        fillit_(vertexToElement, (*it)->triangles.begin(), (*it)->triangles.end());
        fillit_(vertexToElement, (*it)->quadrangles.begin(), (*it)->quadrangles.end());
        fillit_(vertexToElement, (*it)->polygons.begin(), (*it)->polygons.end());
      }
    }
    else if (meshDim == 3){
      for(GModel::riter it = model->firstRegion(); it != model->lastRegion(); ++it){
        fillit_(vertexToElement, (*it)->tetrahedra.begin(), (*it)->tetrahedra.end());
        fillit_(vertexToElement, (*it)->hexahedra.begin(), (*it)->hexahedra.end());
        fillit_(vertexToElement, (*it)->prisms.begin(), (*it)->prisms.end());
        fillit_(vertexToElement, (*it)->pyramids.begin(), (*it)->pyramids.end());
        fillit_(vertexToElement, (*it)->polyhedra.begin(), (*it)->polyhedra.end());
      }
    }    
    std::multimap<MVertex*, MElement*>::iterator it = vertexToElement.begin();
    while (it != vertexToElement.end()){
      MVertex *v = it->first;
      std::vector<MElement*> voe;
      do {
        voe.push_back(it->second);
        ++it;
        if (it ==  vertexToElement.end()) break;
      }while (v == it->first);
      assignPartitionBoundary(model, v, pvertices, voe, pedges, pfaces);
    }
  }

  // create vertex-based ghost cells (i.e., elements that touch the
  // partition boundaries by at least one vertex)
  if(createGhostCells){
    std::multimap<MElement*, short> &ghosts(model->getGhostCells());
    ghosts.clear();
    if(meshDim == 2)
      for(std::set<partitionEdge*, Less_partitionEdge>::iterator it = pedges.begin();
          it != pedges.end(); it++)
        addGhostCells(*it, vertexToElement, ghosts);
    else if(meshDim == 3)
      for(std::set<partitionFace*, Less_partitionFace>::iterator it = pfaces.begin();
          it != pfaces.end(); it++)
        addGhostCells(*it, vertexToElement, ghosts);
  }

  return 1;
}

void createPartitionFaces(GModel *model, GFaceCompound *gf, int N, 
                          std::vector<discreteFace*> &discreteFaces)
{
#if defined(HAVE_SOLVER)
  // Compound is partitioned in N discrete faces
  //--------------------------------------------
  std::vector<std::set<MVertex*> > allNodes;
  int numMax = model->getMaxElementaryNumber(2) + 1;
  for(int i = 0; i < N; i++){
    //printf("*** Created discreteFace %d \n", numMax+i);
    discreteFace *face = new discreteFace(model, numMax+i);
    discreteFaces.push_back(face);
    model->add(face);//delete this    
    std::set<MVertex*> mySet;
    allNodes.push_back(mySet);
  }

  std::list<GFace*> _compound =  gf->getCompounds();
  std::list<GFace*>::iterator it = _compound.begin();

  for( ; it != _compound.end(); ++it){
    //printf("tag compound =%d \n", (*it)->tag());
    for(unsigned int i = 0; i < (*it)->triangles.size(); ++i){
      MTriangle *e = (*it)->triangles[i];
      int part = e->getPartition();
      for(int j = 0; j < 3; j++){
        MVertex *v0 = e->getVertex(j);
        //printf("v0=%d part=%d\n", v0->getNum(), part); //returns part 0 ???
        allNodes[part-1].insert(v0);
      }
      discreteFaces[part-1]->triangles.push_back(new MTriangle(e->getVertex(0),e->getVertex(1),e->getVertex(2)));     
    }
  }

  for(int i = 0; i < N; i++){
    for (std::set<MVertex*>::iterator it = allNodes[i].begin(); it != allNodes[i].end(); it++){ 
      discreteFaces[i]->mesh_vertices.push_back(*it);
    }
 }
#endif
}
  
/*******************************************************************************
 *
 * Explicit instantiations of routine MakeGraphDIM
 *
 ******************************************************************************/

//--Explicit instantiations of the routine for adding elements from a
//--container of entities

template void MakeGraphDIM<2, GModel::fiter, GModel::eiter>
(const GModel::fiter begin, const GModel::fiter end,
 const GModel::eiter beginBE, const GModel::eiter endBE,
 Graph &graph, BoElemGrVec *const boElemGrVec);
template void MakeGraphDIM<3, GModel::riter, GModel::fiter>
(const GModel::riter begin, const GModel::riter end,
 const GModel::fiter beginBE, const GModel::fiter endBE,
 Graph &graph, BoElemGrVec *const boElemGrVec);


#endif
