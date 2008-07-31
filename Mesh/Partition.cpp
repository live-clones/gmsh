// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Partition.cpp - Copyright (C) 2008 S. Guzik, C. Geuzaine, J.-F. Remacle

#include "ElementTraits.h"
#include "GModel.h"
#include "Partition.h"
#include "PartitionOptions.h"

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

template <unsigned DIM, unsigned N = DimTr<DIM>::numElemTypes>
struct MakeGraphFromEntity;
template <unsigned DIM, unsigned N = DimTr<DIM-1>::numElemTypes>
struct MatchBoElemToGrVertex;
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

int PartitionMesh(GModel *const model, PartitionOptions &options)
{

  Graph graph;
  BoElemGrVec boElemGrVec;
  if(MakeGraph(model, graph, &boElemGrVec)) return 1;
  if(PartitionGraph(graph, options)) return 1;

  // Assign partitions to internal elements
  const int n = graph.getNumVertex();
  for(int i = 0; i != n; ++i) {
    graph.element[i]->setPartition(graph.partition[i]);
  }

  // Assign partitions to boundary elements
  const int nb = boElemGrVec.size();
  for(int i = 0; i != nb; ++i) {
    boElemGrVec[i].elem->setPartition(graph.partition[boElemGrVec[i].grVert]);
  }

  model->recomputeMeshPartitions();
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

int PartitionGraph(Graph &graph, PartitionOptions &options)
{

  int ier = 0;

#if HAVE_PARTITION==1
#define HAVE_CHACO
#elif HAVE_PARTITION==2
#define HAVE_METIS
#elif HAVE_PARTITION==3
#define HAVE_CHACO
#define HAVE_METIS
#endif

  switch(options.partitioner){
  case 1:  // Chacho
#ifdef HAVE_CHACO
    {
      Msg::Info("Running Chaco graph partitioner");
      // Some setup (similar to that of Chaco/input/input.c)
      if(options.global_method != 2) options.rqi_flag = 0;
      if(options.global_method == 1 || options.rqi_flag) {
	if (options.vmax < 2*(1 << options.ndims)) {
          options.vmax = 2*(1 << options.ndims);
	}
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
      return ier;
    }
#endif
  case 2:  // Metis
#ifdef HAVE_METIS
    {
      Msg::Info("Running METIS graph partitioner");
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
        }
      }
      catch(...) {
        Msg::Error("METIS threw an exception");
        ier = 2;
      }
      // Number partitions from 1
      {
        int *p = &graph.partition[0];  //**Sections
        for(int n = graph.getNumVertex(); n--;) ++(*p++);
      }
      return ier;
    }
#endif
  }

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

int MakeGraph(GModel *const model, Graph &graph, BoElemGrVec *const boElemGrVec)
{

  enum {
    ElemTypeTetra = 0,
    ElemTypeHexa = 1,
    ElemTypePrism = 2,
    ElemTypePyramid = 3
  };
  enum {
    ElemTypeTri = 0,
    ElemTypeQuad = 1,
  };

  int ier = 0;  
//   switch(partitionScope) {
//   case PartitionEntireDomain:

/*--------------------------------------------------------------------*
 * Make a graph for the entire domain
 *--------------------------------------------------------------------*/

    {

//--Get the dimension of the mesh and count the numbers of elements

      int numElem[4];
      int meshDim = 3;
      for(int i = 0; i != 4; ++i) numElem[i] = 0;
      for(GModel::riter it = model->firstRegion(); it != model->lastRegion();
          ++it) {
        numElem[ElemTypeTetra] += (*it)->tetrahedra.size();
        numElem[ElemTypeHexa] += (*it)->hexahedra.size();
        numElem[ElemTypePrism] += (*it)->prisms.size();
        numElem[ElemTypePyramid] += (*it)->pyramids.size();
      }
      if(numElem[ElemTypeTetra] + numElem[ElemTypeHexa] +
         numElem[ElemTypePrism] + numElem[ElemTypePyramid] == 0) {
        for(GModel::fiter it = model->firstFace(); it != model->lastFace();
            ++it) {
          numElem[ElemTypeTri] += (*it)->triangles.size();
          numElem[ElemTypeQuad] += (*it)->quadrangles.size();
        }
        if(numElem[ElemTypeTri] + numElem[ElemTypeQuad] == 0) {
          Msg::Error("No mesh elements were found");
          return 1;
        }
        meshDim = 2;
      }

//--Make the graph

      switch(meshDim) {
      case 2:
        {
          try {
            // Allocate memory for the graph
            const int numGrVert = numElem[ElemTypeTri] + numElem[ElemTypeQuad];
            const int maxGrEdge =
              (numElem[ElemTypeTri]*3 + numElem[ElemTypeQuad]*4)/2;
            graph.allocate(numGrVert, maxGrEdge);
            // Make the graph
            MakeGraphDIM<2>(model->firstFace(), model->lastFace(),
                            model->firstEdge(), model->lastEdge(), graph,
                            boElemGrVec);
          }
          catch(...) {
            Message::Error("Exception thrown during graph generation");
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
              numElem[ElemTypePrism] + numElem[ElemTypePyramid];
            const int maxGrEdge =
              (numElem[ElemTypeTetra]*4 + numElem[ElemTypeHexa]*6 +
               (numElem[ElemTypePrism] + numElem[ElemTypePyramid])*5)/2;
            graph.allocate(numGrVert, maxGrEdge);
            // Make the graph
            MakeGraphDIM<3>(model->firstRegion(), model->lastRegion(),
                            model->firstFace(), model->lastFace(), graph,
                            boElemGrVec);
          }
          catch(...) {
            Message::Error("Exception thrown during graph generation");
            ier = 2;
          }
        }
        break;
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
//             Message::Error("No mesh elements were found");
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
//             Message::Error("No mesh elements were found");
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
//             Message::Error("No mesh elements were found");
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
  typedef typename DimTr<DIM>::EntityT Ent;
  typedef typename DimTr<DIM-1>::EntityT EntBE;
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;

  graph.markSection();

  FaceMap faceMap;
  GrVertexMap grVertMap;

  for(EntIter entIt = begin; entIt != end; ++entIt) {
    MakeGraphFromEntity<DIM>::eval
       (static_cast<Ent*>(*entIt), faceMap, grVertMap, graph);
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
        (static_cast<EntBE*>(*entIt), faceMap, grVertMap, graph, *boElemGrVec);
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
 * Notes
 * =====
 *
 *   - template meta-programming is used to iterate over the various types of
 *     elements in an entity
 *
 ******************************************************************************/

//--Entry point

template <unsigned DIM, unsigned N>
struct MakeGraphFromEntity
{

  typedef typename DimTr<DIM>::EntityT Ent;  // The type of entity
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;  // The corresponding map
  typedef typename DimElemTr<DIM, N>::Elem Elem; // The type of primary element
  typedef typename DimElemTr<DIM, N>::ConstElementIterator ConstElementIterator;
      
  static void eval(const Ent *const entity, FaceMap &faceMap,
                   GrVertexMap &grVertMap, Graph &graph)
  {
    // Loop over all elements in the entity
    ConstElementIterator elemEnd = DimElemTr<DIM, N>::end(entity);
    for(ConstElementIterator elemIt = DimElemTr<DIM, N>::begin(entity);
        elemIt != elemEnd; ++elemIt) {
      // Insert this element into the map of graph vertices
      std::pair<typename GrVertexMap::iterator, bool> insGrVertMap =
        grVertMap.insert
        (std::pair<MElement*, GrVertex>
         (*elemIt, GrVertex(graph.getNextIndex(),
                            ElemFaceTr<DIM, Elem>::numFaceT)));
      // Loop over all faces in the element
      for(int iFace = 0; iFace != ElemFaceTr<DIM, Elem>::numFaceT; ++iFace) {
        FaceT face = FaceTr<FaceT>::template getFace<Elem>(*elemIt, iFace);
        std::pair<typename FaceMap::iterator, bool> insFaceMap =
          faceMap.insert(std::pair<FaceT, MElement*>(face, *elemIt));
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
            // This graph vertex has complete connectivity.  Write and delete.
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
    // Next element type in the entity
    MakeGraphFromEntity<DIM, N-1>::eval(entity, faceMap, grVertMap, graph);
  }

};

//--Terminate loop when N = 1

template <unsigned DIM>
struct MakeGraphFromEntity<DIM, 1>
{

  typedef typename DimTr<DIM>::EntityT Ent;  // The type of entity
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;  // The corresponding map
  typedef typename DimElemTr<DIM, 1>::Elem Elem; // The type of primary element
  typedef typename DimElemTr<DIM, 1>::ConstElementIterator ConstElementIterator;
      
  static void eval(const Ent *const entity, FaceMap &faceMap,
                   GrVertexMap &grVertMap, Graph &graph)
  {
    // Loop over all elements in the entity
    ConstElementIterator elemEnd = DimElemTr<DIM, 1>::end(entity);
    for(ConstElementIterator elemIt = DimElemTr<DIM, 1>::begin(entity);
        elemIt != elemEnd; ++elemIt) {
      // Insert this element into the map of graph vertices
      std::pair<typename GrVertexMap::iterator, bool> insGrVertMap =
        grVertMap.insert
        (std::pair<MElement*, GrVertex>
         (*elemIt, GrVertex(graph.getNextIndex(),
                            ElemFaceTr<DIM, Elem>::numFaceT)));
      // Loop over all faces in the element
      for(int iFace = 0; iFace != ElemFaceTr<DIM, Elem>::numFaceT; ++iFace) {
        FaceT face = FaceTr<FaceT>::template getFace<Elem>(*elemIt, iFace);
        std::pair<typename FaceMap::iterator, bool> insFaceMap =
          faceMap.insert(std::pair<FaceT, MElement*>(face, *elemIt));
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
            // This graph vertex has complete connectivity.  Write and delete.
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

//--Entry point

template <unsigned DIM, unsigned N>
struct MatchBoElemToGrVertex
{

  typedef typename DimTr<DIM-1>::EntityT Ent;  // The type of entity
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;  // The corresponding map
  typedef typename DimElemTr<DIM-1, N>::Elem Elem; // The type of primary Elem.
  typedef typename DimElemTr<DIM-1, N>::ConstElementIterator
    ConstElementIterator;
      
  static void eval(const Ent *const entity, const FaceMap &faceMap,
                   const GrVertexMap &grVertMap, const Graph &graph,
                   std::vector<BoElemGr> &boElemGrVec)
  {
    // Loop over all elements in the entity
    const ConstElementIterator elemEnd = DimElemTr<DIM-1, N>::end(entity);
    for(ConstElementIterator elemIt = DimElemTr<DIM-1, N>::begin(entity);
        elemIt != elemEnd; ++elemIt) {
      FaceT face = FaceTr<FaceT>::template getFace<Elem>(*elemIt, 0);
      const typename FaceMap::const_iterator faceMapIt = faceMap.find(face);
      if(faceMapIt != faceMap.end()) {
        const typename GrVertexMap::const_iterator grVertMapIt =
          grVertMap.find(faceMapIt->second);
        boElemGrVec.push_back
          (BoElemGr(*elemIt, graph.convertC2W(grVertMapIt->second.index) - 1));
      }
    }
    // Next element type in the entity
    MatchBoElemToGrVertex<DIM, N-1>::eval(entity, faceMap, grVertMap, graph,
                                          boElemGrVec);
  }

};

//--Terminate loop when N = 1

template <unsigned DIM>
struct MatchBoElemToGrVertex<DIM, 1>
{

  typedef typename DimTr<DIM-1>::EntityT Ent;  // The type of entity
  typedef typename DimTr<DIM>::FaceT FaceT;  // The type/dimension of face
  typedef typename LFaceTr<FaceT>::FaceMap FaceMap;  // The corresponding map
  typedef typename DimElemTr<DIM-1, 1>::Elem Elem; // The type of primary Elem.
  typedef typename DimElemTr<DIM-1, 1>::ConstElementIterator
    ConstElementIterator;
      
  static void eval(const Ent *const entity, const FaceMap &faceMap,
                   const GrVertexMap &grVertMap, const Graph &graph,
                   std::vector<BoElemGr> &boElemGrVec)
  {
    // Loop over all elements in the entity
    const ConstElementIterator elemEnd = DimElemTr<DIM-1, 1>::end(entity);
    for(ConstElementIterator elemIt = DimElemTr<DIM-1, 1>::begin(entity);
        elemIt != elemEnd; ++elemIt) {
      FaceT face = FaceTr<FaceT>::template getFace<Elem>(*elemIt, 0);
      const typename FaceMap::const_iterator faceMapIt = faceMap.find(face);
      if(faceMapIt != faceMap.end()) {
        const typename GrVertexMap::const_iterator grVertMapIt =
          grVertMap.find(faceMapIt->second);
        boElemGrVec.push_back
          (BoElemGr(*elemIt, graph.convertC2W(grVertMapIt->second.index) - 1));
      }
    }
  }

};


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
