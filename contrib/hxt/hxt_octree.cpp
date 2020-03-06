#include <iostream>
#include <queue>
#include <vector>

#include "SPoint3.h"
#include "SVector3.h"

#include "hxt_octree.h"
#include "hxt_boundary_recovery.h"
#include "hxt_tools.h"

#ifdef HAVE_P4EST
#include <p4est_to_p8est.h>
#include <p8est_iterate.h>
#include <p8est_extended.h>
#include <p8est_search.h>
#endif

#define P8EST_QMAXLEVEL 20
#define P4EST_QMAXLEVEL 20

#ifdef HAVE_P4EST

/* Create a p4est connectivity structure for the given bounding box. */
static p4est_connectivity_t * p8est_connectivity_new_cube(HXTForestOptions *forestOptions){
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0]+forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1]+forestOptions->bbox[4]) / 2.0;
  double centreZ = (forestOptions->bbox[2]+forestOptions->bbox[5]) / 2.0;
  double cX      = (forestOptions->bbox[3]-forestOptions->bbox[0]) / 2.0;
  double cY      = (forestOptions->bbox[4]-forestOptions->bbox[1]) / 2.0;
  double cZ      = (forestOptions->bbox[5]-forestOptions->bbox[2]) / 2.0;

  double scalingFactor = 1.5; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(fmax(cX,cY),cZ);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX-c, centreY-c, centreZ-c,
    centreX+c, centreY-c, centreZ-c,
    centreX-c, centreY+c, centreZ-c,
    centreX+c, centreY+c, centreZ-c,
    centreX-c, centreY-c, centreZ+c,
    centreX+c, centreY-c, centreZ+c,
    centreX-c, centreY+c, centreZ+c,
    centreX+c, centreY+c, centreZ+c,
  };
  const p4est_topidx_t tree_to_vertex[1 * 8] = {0, 1, 2, 3, 4, 5, 6, 7};
  const p4est_topidx_t tree_to_tree[1 * 6] = {0, 0, 0, 0, 0, 0};
  const int8_t         tree_to_face[1 * 6] = {0, 1, 2, 3, 4, 5};

  return p4est_connectivity_new_copy (num_vertices, num_trees, 0, 0,
              vertices, tree_to_vertex,
              tree_to_tree, tree_to_face,
              NULL, &num_ett, NULL, NULL,
              NULL, &num_ctt, NULL, NULL);
}

/* Dummy callback to return the bulk size. */
static inline double bulkSize(double x, double y, double z, double hBulk){
  return hBulk;
}

/* Fills xyz[] with the coordinates of the center of the given tree cell. */
static inline void getCellCenter(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double xyz[3]){
  p4est_qcoord_t      half_length = P4EST_QUADRANT_LEN (q->level) / 2;
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree,
                          q->x + half_length, q->y + half_length,
  #ifdef P4_TO_P8
                          q->z + half_length,
  #endif
                          xyz);
}

/* Fills min[] & max[] with the coordinates of the cell viewed as a bounding box. */
static inline void getCellBBox(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double min[3], double max[3]){
  p4est_qcoord_t      length = P4EST_QUADRANT_LEN (q->level);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree,
                          q->x, q->y,
  #ifdef P4_TO_P8
                          q->z,
  #endif
                          min);

  p4est_qcoord_to_vertex (p4est->connectivity, which_tree,
                          q->x + length, q->y + length,
  #ifdef P4_TO_P8
                          q->z + length,
  #endif
                          max);
}

/* Fills h with the dimension of the given cell (length of a cell edge). */
static void getCellSize(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double *h)
{
  double min[3], max[3];
  p4est_qcoord_t      length = P4EST_QUADRANT_LEN (q->level);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree,
                          q->x, q->y,
  #ifdef P4_TO_P8
                          q->z,
  #endif
                          min);

  p4est_qcoord_to_vertex (p4est->connectivity, which_tree,
                          q->x + length, q->y + length,
  #ifdef P4_TO_P8
                          q->z + length,
  #endif
                          max);
  
  // All cell edges are supposed to be the same length h (-:
  *h = fmax(max[0] - min[0],fmax(max[1] - min[1],max[2] - min[2]));
}

/* Callback used by p4est to initialize the user_data on each tree cell. */
static inline void initializeCell(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  HXTForestOptions  *forestOptions = (HXTForestOptions *) p4est->user_pointer;
  size_data_t       *data = (size_data_t *) q->p.user_data;

  double center[3]; 
  getCellCenter(p4est, which_tree, q, center);

  // Set cell size 
  data->size = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
  // Set size gradient to zero
  for(int i = 0; i < P4EST_DIM; ++i) data->ds[i] = 0.0;
  // Set half lengths used for finite differences
  getCellSize(p4est, which_tree, q, &(data->h));

  data->h_xL = data->h / 2.0; // Left
  data->h_xR = data->h / 2.0; // Right
  data->h_yD = data->h / 2.0; // Down
  data->h_yU = data->h / 2.0; // Up
  data->h_zB = data->h / 2.0; // Bottom
  data->h_zT = data->h / 2.0; // Top

  data->isBoundary = false;
}

/* Creates (allocates) the forestOptions structure. */
HXTStatus hxtForestOptionsCreate(HXTForestOptions **forestOptions){
  HXT_CHECK( hxtMalloc (forestOptions, sizeof(HXTForestOptions)) );
    if(*forestOptions == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}

/* Destroys forestOptions. */
HXTStatus hxtForestOptionsDelete(HXTForestOptions **forestOptions){
  HXT_CHECK(hxtFree(forestOptions));
  return HXT_STATUS_OK;
} 

/* Creates a (sequential) forest structure by loading a p4est file. */
HXTStatus hxtForestLoad(HXTForest **forest, const char* filename, HXTForestOptions *forestOptions){
  if(filename == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  HXT_CHECK( hxtMalloc(forest, sizeof(HXTForest)) );
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  p4est_connectivity_t *connect;
  sc_MPI_Comm mpicomm = sc_MPI_COMM_WORLD;
  int load_data = true;
  int autopartition = true;
  int broadcasthead = true;

  (*forest)->p4est = p4est_load_ext(filename, mpicomm, sizeof(size_data_t), load_data, autopartition, broadcasthead, (void*) forestOptions, &connect);

  HXTForestOptions *fO = (HXTForestOptions*) (*forest)->p4est->user_pointer;

  assert(fO != NULL);

  return HXT_STATUS_OK;
}

static bool rtreeCallback(uint64_t id, void *ctx) {
  std::vector<uint64_t>* vec = reinterpret_cast< std::vector<uint64_t>* >(ctx);
  vec->push_back(id);
  return true;
}

/* Creates a (sequential) forest structure from the forestOptions information. 
   The forest is not refined; it consists of the root octant.                   */
HXTStatus hxtForestCreate(int argc, char **argv, HXTForest **forest, const char* filename, HXTForestOptions *forestOptions){

    HXT_CHECK( hxtMalloc (forest, sizeof(HXTForest)) );
    if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

    int mpiret;
    int balance;
    sc_MPI_Comm mpicomm;
    p4est_connectivity_t *connect;

    /* Initialize MPI; see sc_mpi.h.
     * If configure --enable-mpi is given these are true MPI calls.
     * Else these are dummy functions that simulate a single-processor run. */
    mpiret = sc_MPI_Init (&argc, &argv);
    SC_CHECK_MPI(mpiret);
    mpicomm = sc_MPI_COMM_WORLD;

    /* These functions are optional.  If called they store the MPI rank as a
     * static variable so subsequent global p4est log messages are only issued
     * from processor zero.  Here we turn off most of the logging; see sc.h. */
    sc_init(mpicomm, 1, 1, NULL, SC_LP_ESSENTIAL);
    p4est_init(NULL, SC_LP_PRODUCTION);

    /* Create a connectivity from the bounding box */
    connect = p8est_connectivity_new_cube(forestOptions);

    if(connect == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

    #ifdef P4EST_WITH_METIS
    //  Use metis (if p4est is compiled with the flag '--with-metis') to
    //  * reorder the connectivity for better parititioning of the forest
    //  * across processors. 
    p4est_connectivity_reorder(mpicomm, 0, conn, P4EST_CONNECT_FACE);
    #endif /* P4EST_WITH_METIS */

    // Assign bulkSize callback if no sizeFunction is specified.
    if(forestOptions->sizeFunction == NULL) forestOptions->sizeFunction = &bulkSize;

    (*forest)->p4est = p4est_new(mpicomm, connect, sizeof(size_data_t), initializeCell, (void*) forestOptions);
    (*forest)->forestOptions = forestOptions;

    return HXT_STATUS_OK;
}

/* Deletes the forest structure. */
HXTStatus hxtForestDelete(HXTForest **forest){
    /* Destroy the p4est structure. */
    p4est_connectivity_destroy((*forest)->p4est->connectivity);
    p4est_destroy((*forest)->p4est);
    /* Verify that allocations internal to p4est and sc do not leak memory.
     * This should be called if sc_init () has been called earlier. */
    sc_finalize();
    /* This is standard MPI programs.  Without --enable-mpi, this is a dummy. */
    int mpiret = sc_MPI_Finalize();
    SC_CHECK_MPI(mpiret);

    HXT_CHECK(hxtFree(forest));

    return HXT_STATUS_OK;
}

/* ========================================================================================================
   FOREST REFINEMENT
   ======================================================================================================== */

/* Callback used by hxtOctreeRefineToBulkSize; returns 1 if the cells need refinement, 0 otherwise. */
static inline int refineToBulkSizeCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  HXTForestOptions *forestOptions = (HXTForestOptions *) p4est->user_pointer;
  size_data_t *data = (size_data_t *) q->p.user_data;
  return data->h > forestOptions->hbulk;
}

/* Used by curvatureRefine; returns 1 if the cell should be
   refined according to the surface mesh curvature, 0 otherwise. */
static int curvatureRefineCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  size_data_t        *data = (size_data_t *) q->p.user_data;
  HXTForestOptions   *forestOptions = (HXTForestOptions *) p4est->user_pointer;

  double min[3], max[3];
  getCellBBox(p4est, which_tree, q, min, max);

  std::vector<uint64_t> candidates;  
  forestOptions->triRTree->Search(min, max, rtreeCallback, &candidates);

  if(!candidates.empty()){
    double kmax = -1.e22;
    double kmin =  1.e22;
    for(std::vector<uint64_t>::iterator tri = candidates.begin(); tri != candidates.end(); ++tri){
      for(int i = 0; i < 3; ++i){
        int node = forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+i];

        double *v1 = forestOptions->nodalCurvature + 6*node;
        double *v2 = forestOptions->nodalCurvature + 6*node + 3;

        double k1, k2;
        hxtNorm2V3(v1, &k1);
        hxtNorm2V3(v2, &k2);

        kmax = fmax(kmax,fmax(k1,k2));
        kmin = fmin(kmin,fmin(k1,k2));
      }
    }

    double h;
    getCellSize(p4est, which_tree, q, &h);

    // No curvature : should be OK because of refineToBulk ?
    if(fabs(kmax) < 1e-3){
        return 0;
    } else{
      // There is curvature : the cell size should accurately represent the surface
      // Cell is refined according to the chosen density of nodes
      double hc = 2*M_PI/(forestOptions->nodePerTwoPi * kmax);
      int nElemPerCell = 2;

      if(h > hc/nElemPerCell){
        return 1;
      } else{
        return 0;
      }
    }
  } else{ // candidates.empty()
    // If the cell has no intersection with any triangle of the surface mesh, it is not refined.
    return 0;
  }
}

static int coarsenCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *children[]){
  HXTForestOptions *forestOptions = (HXTForestOptions *) p4est->user_pointer;

  for(int n = 0; n < P4EST_CHILDREN; ++n){
    size_data_t *data = (size_data_t *) children[n]->p.user_data;
    
    double min[3], max[3];
    getCellBBox(p4est, which_tree, children[n], min, max);

    std::vector<uint64_t> candidates;  
    forestOptions->triRTree->Search(min, max, rtreeCallback, &candidates);

    // Cells are not merged if any one of them touches the surface mesh.
    if(!candidates.empty()) return 0;
    // Cells are not merged if the resulting cell size is > than hbulk.
    if(2.0*data->h > forestOptions->hbulk) return 0;
  }

  return 1;
}

static void assignSizeAfterRefinement(p4est_iter_volume_info_t * info, void *user_data){
  p4est_t            *p4est = info->p4est;
  p4est_quadrant_t   *q = info->quad;
  p4est_topidx_t      which_tree = info->treeid;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  HXTForestOptions   *forestOptions = (HXTForestOptions *) user_data;

  double min[3], max[3];
  getCellBBox(p4est, which_tree, q, min, max);

  std::vector<uint64_t> candidates;  
  forestOptions->triRTree->Search(min, max, rtreeCallback, &candidates);

  if(!candidates.empty()){
    double kmax = -1.0e22;
    for(std::vector<uint64_t>::iterator tri = candidates.begin(); tri != candidates.end(); ++tri){
      for(int i = 0; i < 3; ++i){
        int node = forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+i];

        double *v1 = forestOptions->nodalCurvature + 6*node;
        double *v2 = forestOptions->nodalCurvature + 6*node + 3;

        double k1, k2;
        hxtNorm2V3(v1, &k1);
        hxtNorm2V3(v2, &k2);

        kmax = fmax(kmax,fmax(k1,k2));
      }
    }
    data->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * kmax)));
  }
  else{
    data->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, data->size));
  }

  // double center[3];
  // getCellCenter(p4est, which_tree, q, center);
  // data->size = 5.0*(center[0]+center[1]+center[2]);
}

HXTStatus hxtForestRefine(HXTForest *forest){
  /* Refine recursively the tree until all cells' size is at most hbulk. */
  p4est_refine_ext(forest->p4est, 1, P4EST_QMAXLEVEL, refineToBulkSizeCallback, initializeCell, NULL);
  // Refine recursively with respect to the curvature
  p4est_refine_ext(forest->p4est, 1, P4EST_QMAXLEVEL, curvatureRefineCallback, initializeCell, NULL);
  // Coarsen
  p4est_coarsen_ext(forest->p4est, 1, 0, coarsenCallback, initializeCell, NULL);
  // Balance the octree to get 2:1 ratio between adjacent cells
  p4est_balance_ext(forest->p4est, P4EST_CONNECT_FACE, initializeCell, NULL);
  // Assign size on the new cells
  p4est_iterate(forest->p4est, NULL, forest->forestOptions, assignSizeAfterRefinement, NULL, NULL, NULL);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   SIZE GRADIENT COMPUTATION & SMOOTHING
   ======================================================================================================== */
static inline void resetCell(p4est_iter_volume_info_t * info, void *user_data){
    size_data_t *data = (size_data_t *) info->quad->p.user_data;
    // Reset gradient to zero.
    for(int i = 0; i < P4EST_DIM; ++i) data->ds[i] = 0.0;
    // Reset half lengths
    data->h_xL = data->h / 2.0;
    data->h_xR = data->h / 2.0;
    data->h_yU = data->h / 2.0;
    data->h_yD = data->h / 2.0;
#ifdef P4_TO_P8
    data->h_zB = data->h / 2.0;
    data->h_zT = data->h / 2.0;
#endif
}

// static inline void setHalfLengths(p4est_iter_face_info_t * info, void *user_data){
//   p4est_iter_face_side_t *side[2];
//   sc_array_t             *sides = &(info->sides);
//   size_data_t            *ghost_data = (size_data_t *) user_data;
//   size_data_t            *data;
//   size_data_t            *data_opp;
//   p4est_quadrant_t       *quad;
//   p4est_quadrant_t       *quadOpp;
//   int                     which_face;
//   int                     which_face_opp;
//   // Index of current face on the opposite cell (0 if current is 1 and vice versa).
//   int                     iOpp; 

//   side[0] = p4est_iter_fside_array_index_int (sides, 0);
//   side[1] = p4est_iter_fside_array_index_int (sides, 1);

//   if(sides->elem_count == 2){ // Not on a boundary of the octree (the face has two neighbours)

//     for(int i = 0; i < 2; i++) {

//       iOpp = 1 - i; // Index in array side[] of the opposite face
//       which_face_opp = side[iOpp]->face;     /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */

//       // Current cells are hanging
//       // There are 2^(dim-1) (P4EST_HALF) subfaces
//       if (side[i]->is_hanging){
//         quad = side[i]->is.hanging.quad[0]; // Both hanging cells have the same size, so we take quad[0] to compute the lengths (either is fine)
//         data = (size_data_t *) quad->p.user_data;
//         // Current cells are hanging (split), so we assume that the opposite cell
//         // is full. Otherwise we would just be on a full-full new face.
//         data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
//         // We add the current cell half lengths as contribution to the opposite cell
//         switch(which_face_opp){
//           case 0 : data_opp->h_xL += data->h / 2.0 ; break;
//           case 1 : data_opp->h_xR += data->h / 2.0 ; break;
//           case 2 : data_opp->h_yD += data->h / 2.0 ; break;
//           case 3 : data_opp->h_yU += data->h / 2.0 ; break;
//         #ifdef P4_TO_P8
//           case 4 : data_opp->h_zB += data->h / 2.0 ; break;
//           case 5 : data_opp->h_zT += data->h / 2.0 ; break;
//         #endif
//           default :
//             std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
//             // return HXT_STATUS_RANGE_ERROR;
//         }
//       }
//       // Current cell is full
//       else{
//         quad = side[i]->is.full.quad;
//         data = (size_data_t *) quad->p.user_data;
//         // We add the current cell half lengths as contribution to the opposite cell(s)

//         if(side[iOpp]->is_hanging){
//           // Current is full - Opposite are hanging
//           for(int j = 0; j < P4EST_HALF; ++j){
//             data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
//             switch(which_face_opp){
//               case 0 : data_opp->h_xL += data->h / 2.0 ; break;
//               case 1 : data_opp->h_xR += data->h / 2.0 ; break;
//               case 2 : data_opp->h_yD += data->h / 2.0 ; break;
//               case 3 : data_opp->h_yU += data->h / 2.0 ; break;
//             #ifdef P4_TO_P8
//               case 4 : data_opp->h_zB += data->h / 2.0 ; break;
//               case 5 : data_opp->h_zT += data->h / 2.0 ; break;
//             #endif
//               default :
//                 std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
//                 // return HXT_STATUS_RANGE_ERROR;
//             }
//           }
//         } 
//         else{
//           // Current is full - Opposite is Full
//           data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
//           switch(which_face_opp){
//             case 0 : data_opp->h_xL += data->h / 2.0 ; break;
//             case 1 : data_opp->h_xR += data->h / 2.0 ; break;
//             case 2 : data_opp->h_yD += data->h / 2.0 ; break;
//             case 3 : data_opp->h_yU += data->h / 2.0 ; break;
//           #ifdef P4_TO_P8
//             case 4 : data_opp->h_zB += data->h / 2.0 ; break;
//             case 5 : data_opp->h_zT += data->h / 2.0 ; break;
//           #endif
//             default :
//               std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
//               // return HXT_STATUS_RANGE_ERROR;
//           }  
//         }
//       }
//     } // for side[i]
//   }
//   else{ // On the boundaries
//     data = (size_data_t *) side[0]->is.full.quad->p.user_data;
//     data->isBoundary = true;
//     which_face = side[0]->face;
//     switch(which_face){
//       case 0 : data->h_xL += data->h / 2.0; break;
//       case 1 : data->h_xR += data->h / 2.0; break;
//       case 2 : data->h_yD += data->h / 2.0; break;
//       case 3 : data->h_yU += data->h / 2.0; break;
//     #ifdef P4_TO_P8
//       case 4 : data->h_zB += data->h / 2.0; break;
//       case 5 : data->h_zT += data->h / 2.0; break;
//     #endif
//       default :
//         std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
//         // return HXT_STATUS_RANGE_ERROR;
//     }
//   }
// }

static void computeGradientCenter(p4est_iter_face_info_t * info, void *user_data){
    p4est_iter_face_side_t *side[2];
    sc_array_t             *sides = &(info->sides);
    size_data_t            *data;
    size_data_t            *data_opp;
    double                  s_avg, s[4], s_sum;
    int                     which_face;
    int                     which_face_opp;
    // Index of current face on the opposite cell (0 if current is 1 and vice versa).
    int                     iOpp; 

    side[0] = p4est_iter_fside_array_index_int (sides, 0);
    side[1] = p4est_iter_fside_array_index_int (sides, 1);

    if(sides->elem_count == 2){

      for(int i = 0; i < 2; i++){
        iOpp = 1 - i;
        which_face_opp = side[iOpp]->face; /* 0,1 == -+x, 2,3 == -+y, 4,5 == -+z */
        // s_avg is the average size on the P4EST_HALF opposite cells
        s_avg = s_sum = 0;
        // Current cells are hanging
        if (side[i]->is_hanging){
          for(int j = 0; j < P4EST_HALF; j++){
            data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;
            s_avg += data->size;
            s[j]   = data->size; 
          }
          s_sum = s_avg;
          s_avg /= P4EST_HALF;

          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

          switch(which_face_opp){
            // case 0 : data_opp->ds[0] -= 0.5 * (s_avg - data_opp->size)/(data_opp->h_xL + data->h_xR); break;
            // case 1 : data_opp->ds[0] += 0.5 * (s_avg - data_opp->size)/(data_opp->h_xR + data->h_xL); break;

            case 0 : data_opp->ds[0] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_xL + data->h_xR); break;
            case 1 : data_opp->ds[0] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_xR + data->h_xL); break;

            case 2 : data_opp->ds[1] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_yD + data->h_yU); break;
            case 3 : data_opp->ds[1] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_yU + data->h_yD); break;
          #ifdef P4_TO_P8
            case 4 : data_opp->ds[2] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_zB + data->h_zT); break;
            case 5 : data_opp->ds[2] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_zT + data->h_zB); break;
          #endif
            default :
              std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
          }
          // switch(which_face_opp){
          //   case 0 : data_opp->ds[0] -= 0.5 * s_avg/(data_opp->h_xL + data->h_xR); break;
          //   case 1 : data_opp->ds[0] += 0.5 * s_avg/(data_opp->h_xR + data->h_xL); break;
          //   case 2 : data_opp->ds[1] -= 0.5 * s_avg/(data_opp->h_yD + data->h_yU); break;
          //   case 3 : data_opp->ds[1] += 0.5 * s_avg/(data_opp->h_yU + data->h_yD); break;
          // #ifdef P4_TO_P8
          //   case 4 : data_opp->ds[2] -= 0.5 * s_avg/(data_opp->h_zB + data->h_zT); break;
          //   case 5 : data_opp->ds[2] += 0.5 * s_avg/(data_opp->h_zT + data->h_zB); break;
          // #endif
          //   default :
          //     std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
          // }
        }
        // Current cell is full
        else{
          data = (size_data_t *) side[i]->is.full.quad->p.user_data;
          s_avg = data->size;
          s_sum = 4.0*s_avg;
          if(side[iOpp]->is_hanging){
            // Current full - Opposite hanging
            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;

              switch(which_face_opp){
                case 0 : data_opp->ds[0] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_xL + data->h_xR); break;
                case 1 : data_opp->ds[0] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_xR + data->h_xL); break;
                case 2 : data_opp->ds[1] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_yD + data->h_yU); break;
                case 3 : data_opp->ds[1] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_yU + data->h_yD); break;
              #ifdef P4_TO_P8
                case 4 : data_opp->ds[2] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_zB + data->h_zT); break;
                case 5 : data_opp->ds[2] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_zT + data->h_zB); break;
              #endif
                default :
                  std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
              }
              // switch(which_face_opp){
              //   case 0 : data_opp->ds[0] -= 0.5 * s_avg/(data_opp->h_xL + data->h_xR); break;
              //   case 1 : data_opp->ds[0] += 0.5 * s_avg/(data_opp->h_xR + data->h_xL); break;
              //   case 2 : data_opp->ds[1] -= 0.5 * s_avg/(data_opp->h_yD + data->h_yU); break;
              //   case 3 : data_opp->ds[1] += 0.5 * s_avg/(data_opp->h_yU + data->h_yD); break;
              // #ifdef P4_TO_P8
              //   case 4 : data_opp->ds[2] -= 0.5 * s_avg/(data_opp->h_zB + data->h_zT); break;
              //   case 5 : data_opp->ds[2] += 0.5 * s_avg/(data_opp->h_zT + data->h_zB); break;
              // #endif
              //   default :
              //     std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
              // }
            }
          }
          else{
            // Current full - Opposite full
            data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
            switch(which_face_opp){
              case 0 : data_opp->ds[0] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_xL + data->h_xR); break;
              case 1 : data_opp->ds[0] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_xR + data->h_xL); break;
              case 2 : data_opp->ds[1] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_yD + data->h_yU); break;
              case 3 : data_opp->ds[1] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_yU + data->h_yD); break;
            #ifdef P4_TO_P8
              case 4 : data_opp->ds[2] -= 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_zB + data->h_zT); break;
              case 5 : data_opp->ds[2] += 0.125 * (s_sum - 4.0*data_opp->size)/(data_opp->h_zT + data->h_zB); break;
            #endif
              default :
                std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
            }
            // switch(which_face_opp){
            //   case 0 : data_opp->ds[0] -= 0.5 * s_avg/(data_opp->h_xL + data->h_xR); break;
            //   case 1 : data_opp->ds[0] += 0.5 * s_avg/(data_opp->h_xR + data->h_xL); break;
            //   case 2 : data_opp->ds[1] -= 0.5 * s_avg/(data_opp->h_yD + data->h_yU); break;
            //   case 3 : data_opp->ds[1] += 0.5 * s_avg/(data_opp->h_yU + data->h_yD); break;
            // #ifdef P4_TO_P8
            //   case 4 : data_opp->ds[2] -= 0.5 * s_avg/(data_opp->h_zB + data->h_zT); break;
            //   case 5 : data_opp->ds[2] += 0.5 * s_avg/(data_opp->h_zT + data->h_zB); break;
            // #endif
            //   default :
            //     std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
            // }
          }
        }
      }
    }
    else{ // On the boundaries
        data = (size_data_t *) side[0]->is.full.quad->p.user_data;
        data->isBoundary = true;
        which_face = side[0]->face;

        // double center[3];

        // get_center(info->p4est, side[0]->treeid, side[0]->is.full.quad, center);

        // h = (double) P4EST_QUADRANT_LEN (side[0]->is.full.quad->level) / (double) P4EST_ROOT_LEN /2;

        // double s_out;

        // switch(which_face){
        //     case 0 :
        //         s_out = myFunction(center[0] - h, center[1], center[2]);
        //         data->ds[0] -= s_out;
        //         break;
        //     case 1 :
        //         s_out = myFunction(center[0] + h, center[1], center[2]);
        //         data->ds[0] += s_out;
        //         break;
        //     case 2 : 
        //         s_out = myFunction(center[0], center[1] - h, center[2]);
        //         data->ds[1] -= s_out;
        //         break;
        //     case 3 : 
        //         s_out = myFunction(center[0], center[1] + h, center[2]);
        //         data->ds[1] += s_out;
        //         break;
        //     default :
        //         std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
        //         exit(-1);
        // }

        // Differences finies aux faces (decentrees) si le quadrant est a la frontiere
        switch(which_face){
          case 0 : data->ds[0] = NAN; break; //-= data->size; break;
          case 1 : data->ds[0] = NAN; break; //+= data->size; break;
          case 2 : data->ds[1] = NAN; break; //-= data->size; break;
          case 3 : data->ds[1] = NAN; break; //+= data->size; break;
        #ifdef P4_TO_P8
          case 4 : data->ds[2] = NAN; break; //-= data->size; break;
          case 5 : data->ds[2] = NAN; break; //+= data->size; break;
        #endif
            default :
                std::cout<<"Valeur inattendue : "<<which_face_opp<<std::endl;
        }
    }
}

static inline void printGradient(p4est_iter_volume_info_t * info, void *user_data){
    size_data_t *data = (size_data_t *) info->quad->p.user_data;
    printf("grad = (%f \t %f \t %f) isBoundary = %d\n", data->ds[0], data->ds[1], data->ds[2], data->isBoundary);
}

static inline void printLengths(p4est_iter_volume_info_t * info, void *user_data){
    size_data_t *data = (size_data_t *) info->quad->p.user_data;
    printf("lengths = (%f \t %f \t, %f \t %f \t, %f \t %f \t) isBoundary = %d\n", data->h_xL, data->h_xR, data->h_yU, data->h_yD, data->h_zT, data->h_zB, data->isBoundary);
}

HXTStatus hxtForestComputeGradient(HXTForest *forest){
  // Iterate on each cell to reset size gradient and half lengths.
    p4est_iterate(forest->p4est, NULL, NULL, resetCell, NULL,
            #ifdef P4_TO_P8
                        NULL,
            #endif
                        NULL);

    // // Set half lengths
    // p4est_iterate(forest->p4est, NULL, NULL, NULL, setHalfLengths,
    //     #ifdef P4_TO_P8
    //                 NULL,
    //     #endif
    //                 NULL);

    // Compute gradient at cell center using finite differences
    p4est_iterate(forest->p4est, NULL, NULL, NULL, computeGradientCenter,
        #ifdef P4_TO_P8
                    NULL,
        #endif
                    NULL);

    return HXT_STATUS_OK;
}

static inline void getMaxGradient(p4est_iter_volume_info_t * info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double           *gradMax = static_cast<double*>(user_data);
  gradMax[0] = SC_MAX (fabs(data->ds[0]), gradMax[0]);
  gradMax[1] = SC_MAX (fabs(data->ds[1]), gradMax[1]);
#ifdef P4_TO_P8
  gradMax[2] = SC_MAX (fabs(data->ds[2]), gradMax[2]);
#endif
}

HXTStatus hxtForestGetMaxGradient(HXTForest *forest, double *gradMax){
  p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradient, NULL,
            #ifdef P4_TO_P8
                       NULL,
            #endif
                       NULL);
  return HXT_STATUS_OK;
}

void smoothSize(p4est_iter_face_info_t * info, void *user_data){
    p4est_iter_face_side_t *side[2];
    sc_array_t        *sides = &(info->sides);
    size_data_t       *ghost_data = (size_data_t *) user_data;
    size_data_t       *data;
    size_data_t       *data_opp1;
    size_data_t       *data_opp2;
    p4est_quadrant_t  *quad;
    double             s_avg;
    int                which_dir;
    int                which_face;
    int                which_face_opp;
    int                iOpp;

    HXTForestOptions  *forestOptions = (HXTForestOptions*) user_data;
    double             alpha = forestOptions->gradMax;

    side[0] = p4est_iter_fside_array_index_int (sides, 0);
    side[1] = p4est_iter_fside_array_index_int (sides, 1);

    if(sides->elem_count==2){

      for(int i = 0; i < 2; ++i){

        iOpp = 1 - i;
        which_dir = side[i]->face / 2; // Direction x (0), y (1) ou z(2)
        which_face_opp = side[iOpp]->face;

        if(side[i]->is_hanging){

          data_opp1 = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

          for(int j = 0; j < P4EST_HALF; ++j){

            data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;

            if(fabs(data->ds[which_dir]) > alpha-1){

              if(data->size > data_opp1->size){
                  // data->size = fmin(data->size, data_opp1->size + (alpha-1) * data_opp1->hMin);
                switch(which_face_opp){
                  case 0 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_xL + data->h_xR)); break;
                  case 1 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_xR + data->h_xL)); break;
                  case 2 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_yD + data->h_yU)); break;
                  case 3 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_yU + data->h_yD)); break;
                  case 4 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_zB + data->h_zT)); break;
                  case 5 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_zT + data->h_zB)); break;
                }
              }else{
                  // data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * data->hMin);
                switch(which_face_opp){
                  case 0 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_xL + data->h_xR)); break;
                  case 1 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_xR + data->h_xL)); break;
                  case 2 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_yD + data->h_yU)); break;
                  case 3 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_yU + data->h_yD)); break;
                  case 4 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_zB + data->h_zT)); break;
                  case 5 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_zT + data->h_zB)); break;
                }
              }
            } // if ds > alpha-1
          } // for j hanging
        } // if hanging
        else{

          data = (size_data_t *) side[i]->is.full.quad->p.user_data;

          if(fabs(data->ds[which_dir]) > alpha-1){
            if(side[iOpp]->is_hanging){
                // Full - Oppose hanging
              for(int j = 0; j < P4EST_HALF; ++j){
                data_opp1 = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
                // size_data_opp2 = (size_data_t *) side[iOpp]->is.hanging.quad[1]->p.user_data;

                // if(data->size > fmin(data_opp1->size, size_data_opp2->size) ){
                if(data->size > data_opp1->size){
                    // data->size = fmin(data->size, data_opp1->size + (alpha-1) * data_opp1->hMin);
                    // data->size = fmin(data->size, size_data_opp2->size + (alpha-1) * size_data_opp2->hMin);
                  switch(which_face_opp){
                    case 0 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_xL + data->h_xR)); break;
                    case 1 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_xR + data->h_xL)); break;
                    case 2 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_yD + data->h_yU)); break;
                    case 3 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_yU + data->h_yD)); break;
                    case 4 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_zB + data->h_zT)); break;
                    case 5 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_zT + data->h_zB)); break;
                  }
                }
                else{
                    // data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * data->hMin);
                    // size_data_opp2->size = fmin(size_data_opp2->size, data->size + (alpha-1) * data->hMin);
                  switch(which_face_opp){
                    case 0 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_xL + data->h_xR)); break;
                    case 1 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_xR + data->h_xL)); break;
                    case 2 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_yD + data->h_yU)); break;
                    case 3 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_yU + data->h_yD)); break;
                    case 4 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_zB + data->h_zT)); break;
                    case 5 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_zT + data->h_zB)); break;
                  }
                }
              }
            }
            else{
                // Full - Oppose full
                data_opp1 = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

                if(data->size > data_opp1->size){
                    // data->size = fmin(data->size, data_opp1->size + (alpha-1) * data_opp1->hMin);
                  switch(which_face_opp){
                    case 0 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_xL + data->h_xR)); break;
                    case 1 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_xR + data->h_xL)); break;
                    case 2 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_yD + data->h_yU)); break;
                    case 3 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_yU + data->h_yD)); break;
                    case 4 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_zB + data->h_zT)); break;
                    case 5 : data->size = fmin(data->size, data_opp1->size + (alpha-1) * (data_opp1->h_zT + data->h_zB)); break;
                  }
                }
                else{
                    // data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * data->hMin);
                  switch(which_face_opp){
                    case 0 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_xL + data->h_xR)); break;
                    case 1 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_xR + data->h_xL)); break;
                    case 2 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_yD + data->h_yU)); break;
                    case 3 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_yU + data->h_yD)); break;
                    case 4 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_zB + data->h_zT)); break;
                    case 5 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha-1) * (data_opp1->h_zT + data->h_zB)); break;
                  }
                }
            }  
          } // if gradient trop grand
        } // else
      }
    }
    else{
        // size_data = (size_data_t *) side[0]->is.full.quad->p.user_data;

        // which_dir = side[0]->face / 2;

        // if(fabs(data->ds[which_dir]) > alpha-1){
        //     data->ds[which_dir] = fmin(data->ds[which_dir], alpha-1);
        //     data->ds[which_dir] = nan("");

        // }
    }
}

HXTStatus hxtForestSetMaxGradient(HXTForest *forest){
  p4est_iterate (forest->p4est, NULL, (void*) forest->forestOptions, NULL, smoothSize,
            #ifdef P4_TO_P8
                       NULL,
            #endif
                       NULL);
  return HXT_STATUS_OK;
}

HXTStatus hxtForestSizeSmoothing(HXTForest *forest){
  double gradMax[3], tol = 1e-2, gradLinf = 1e22;
  int iter = 0;
  while(iter++ < forest->forestOptions->nRefine && gradLinf > tol + forest->forestOptions->gradMax-1.0){
    for(int i = 0; i < 3; ++i) gradMax[i] = 0.0;
    // Compute gradient
    HXT_CHECK( hxtForestComputeGradient(forest) );
    // Smooth large sizes to limit gradient to foresOptions->gradMax-1
    HXT_CHECK( hxtForestSetMaxGradient(forest) );
    // Gradient needs to be recomputed after size is smoothed
    HXT_CHECK( hxtForestComputeGradient(forest) );
    // Stopping criterion
    HXT_CHECK( hxtForestGetMaxGradient(forest, gradMax) );
    gradLinf = fmax( gradMax[0], fmax( gradMax[1], gradMax[2]) );
  }
  Msg::Info("Max gradient after smoothing : (%f - %f - %f)", gradMax[0], gradMax[1], gradMax[2]);
  printf("Max gradient after smoothing : (%f - %f - %f)\n", gradMax[0], gradMax[1], gradMax[2]);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   SEARCH AND REPLACE
   ======================================================================================================== */

inline static bool isPoint(double x, double y, double z, size_point_t *p, double tol){
  return (fabs(p->x - x) < tol && fabs(p->y - y) < tol && fabs(p->z - z) < tol);
}

static int searchAndAssignConstant(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){

    bool in_box;
    int is_match;
    int is_leaf = local_num >= 0;
    
    size_data_t  *data = (size_data_t *) q->p.user_data;
    size_point_t *p    = (size_point_t *) point;

    HXTForestOptions *forestOptions = (HXTForestOptions *) p4est->user_pointer;

    // We have to recompute the cell dimension h for the root (non leaves) octants 
    // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
    double h;
    if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
    else h = data->h;

    double center[3];
    getCellCenter(p4est, which_tree, q, center);

    double epsilon = 1e-8;
    in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. - epsilon);
    in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y > center[1] - h/2. - epsilon);
#ifdef P4_TO_P8
    in_box &= (p->z < center[2] + h/2. + epsilon) && (p->z > center[2] - h/2. - epsilon);
#endif

    // A point can be on the exact boundary of two cells, hence we take the min.
    if(in_box && is_leaf){
      p->size = fmin(p->size, data->size);
      // p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
      assert(p->size >= 0);
      p->isFound = true;
    }

    return in_box;
}

static int searchAndAssignLinear(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){

    bool in_box;
    int is_match;
    int is_leaf = local_num >= 0;
    
    size_data_t  *data = (size_data_t *) q->p.user_data;
    size_point_t *p    = (size_point_t *) point;

    HXTForestOptions *forestOptions = (HXTForestOptions *) p4est->user_pointer;

    // We have to recompute the cell dimension h for the root (non leaves) octants 
    // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
    double h;
    if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
    else h = data->h;

    double center[3];
    getCellCenter(p4est, which_tree, q, center);

    double epsilon = 1e-8;
    in_box  = (p->x < center[0] + h/2. + epsilon) && (p->x > center[0] - h/2. - epsilon);
    in_box &= (p->y < center[1] + h/2. + epsilon) && (p->y > center[1] - h/2. - epsilon);
#ifdef P4_TO_P8
    in_box &= (p->z < center[2] + h/2. + epsilon) && (p->z > center[2] - h/2. - epsilon);
#endif

    // A point can be on the exact boundary of two cells, hence we take the min.
    if(in_box && is_leaf){
        // Approximation lineaire a partir du gradient au centre
      p->size = fmin(p->size, data->size + data->ds[0]*(p->x - center[0]) + data->ds[1]*(p->y - center[1]) + data->ds[2]*(p->z - center[2]) );
      // p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
      assert(p->size >= 0);
      p->isFound = true;
    }

    return in_box;
}

/* Search for a single point in the tree structure and returns its size.
   See searchAndAssign for the detailed comments. */
HXTStatus hxtForestSearchOne(HXTForest *forest, double x, double y, double z, double *size, int linear){
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);

  size_point_t *p = (size_point_t *) sc_array_index(points, 0);
  p->x = x;
  p->y = y;
  p->z = z;
  p->size = 1.0e22;
  p->isFound = false;
  
  if(linear){
    p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);
  }else{
    p4est_search(forest->p4est, NULL, searchAndAssignConstant, points);
  }

  if(!p->isFound) Msg::Info("Point (%f,%f,%f) n'a pas été trouvé dans l'octree 8-|", x,y,z);
  *size = p->size;

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

static int hxtOctreeReplaceCallback(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){

    bool in_box;
    int is_match;
    int is_leaf = local_num >= 0;
    
    size_data_t  *data = (size_data_t *) q->p.user_data;
    size_point_t *p    = (size_point_t *) point;

    // We have to recompute the cell dimension h for the root (non leaves) octants 
    // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
    double h;
    if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
    else h = data->h;
    

    double center[3];
    getCellCenter(p4est, which_tree, q, center);

    double epsilon = 1e-8;
    in_box  = (p->x < center[0] + h/2 + epsilon) && (p->x > center[0] - h/2 - epsilon);
    in_box &= (p->y < center[1] + h/2 + epsilon) && (p->y > center[1] - h/2 - epsilon);
#ifdef P4_TO_P8
    in_box &= (p->z < center[2] + h/2 + epsilon) && (p->z > center[2] - h/2 - epsilon);
#endif

    if(in_box && is_leaf){
        data->size = fmin(data->size, p->size);
        // printf("Taille remplacée dans l'octree à la position %f - %f - %f \n",p->x,p->y,p->z);
        // printf("dans le quadrant centré en %f - %f - %f de côté %f \n", center[0], center[1], center[2], h);
    }

    return in_box;
}

HXTStatus hxtForestSearch(HXTForest *forest, std::vector<double> *x, std::vector<double> *y, std::vector<double> *z, std::vector<double> *size){
  
  // Array of size_point_t to search in the tree
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), (*x).size());
  size_point_t *p;

  for(int i = 0; i < (*x).size(); ++i){
    p = (size_point_t *) sc_array_index(points, i);
    p->x = (*x)[i];
    p->y = (*y)[i];
    p->z = (*z)[i];
    p->size = -1.0;
  }
  
  // Search on all cells
  p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);

  // Get the sizes
  for(int i = 0; i < (*x).size(); ++i){ 
    p = (size_point_t *) sc_array_index(points, i);
    (*size)[i] = p->size;
  }

  // Clean up
  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

// static HXTStatus recoveryFun(HXTMesh* mesh, void* userData) {
//   HXT_UNUSED(userData);
//   HXT_CHECK( hxt_boundary_recovery(mesh) );
//   return HXT_STATUS_OK;
// }

// static double meshSize(double x, double y, double z, void *user_data){
//   HXTForest *forest = (HXTForest *) user_data;
//   double val = 1.e22;
//   HXTStatus s = hxtForestSearchOne(forest, x, y, z, &val, true);
//   if (s == HXT_STATUS_OK){
//     return val;
//   }
//   else Msg::Error ("Cannot find point %g %g %g in the octree",x,y,z);
//   return val;
// }

/* ========================================================================================================
   CLOSE SURFACES DETECTION
   ======================================================================================================== */

/*
 distance to triangle

 P(p) = p1 + t1 xi + t2 eta

 t1 = (p2-p1) ; t2 = (p3-p1) ;

 (P(p) - p) = d n

 (p1 + t1 xi + t2 eta - p) = d n
 t1 xi + t2 eta - d n = p - p1

 | t1x t2x -nx | |xi  |   |px-p1x|
 | t1y t2y -ny | |eta | = |py-p1y|
 | t1z t2z -nz | |d   |   |pz-p1z|

 distance to segment

 P(p) = p1 + t (p2-p1)

 (p - P(p)) * (p2-p1) = 0
 (p - p1 - t (p2-p1) ) * (p2-p1) = 0
 - t ||p2-p1||^2 + (p-p1)(p2-p1) = 0

 t = (p-p1)*(p2-p1)/||p2-p1||^2
*/
void signedDistancePointTriangle2(const SPoint3 &p1, const SPoint3 &p2, const SPoint3 &p3, const SPoint3 &p, double &d, SPoint3 &closePt){
 SVector3 t1 = p2 - p1;
 SVector3 t2 = p3 - p1;
 SVector3 t3 = p3 - p2;
 SVector3 n = crossprod(t1, t2);
 n.normalize();
 const double n2t1 = dot(t1, t1);
 const double n2t2 = dot(t2, t2);
 const double n2t3 = dot(t3, t3);
 double mat[3][3] = {{t1.x(), t2.x(), -n.x()},
                     {t1.y(), t2.y(), -n.y()},
                     {t1.z(), t2.z(), -n.z()}};
 double inv[3][3];
 double det;
 hxtInv3x3(mat, inv, &det);
 if(det == 0.0) return;

 double u, v;
 SVector3 pp1 = p - p1;
 u = (inv[0][0] * pp1.x() + inv[0][1] * pp1.y() + inv[0][2] * pp1.z());
 v = (inv[1][0] * pp1.x() + inv[1][1] * pp1.y() + inv[1][2] * pp1.z());
 d = (inv[2][0] * pp1.x() + inv[2][1] * pp1.y() + inv[2][2] * pp1.z());
 double sign = (d > 0) ? 1. : -1.;
 if(d == 0.) sign = 1.;
 if(u >= 0. && v >= 0. && 1. - u - v >= 0.0) { // P(p) inside triangle
   closePt = p1 + (p2 - p1) * u + (p3 - p1) * v;
 }
 else {
   const double t12 = dot(pp1, t1) / n2t1;
   const double t13 = dot(pp1, t2) / n2t2;
   SVector3 pp2 = p - p2;
   const double t23 = dot(pp2, t3) / n2t3;
   d = 1.e10;
   if(t12 >= 0 && t12 <= 1.) {
     d = sign * std::min(fabs(d), p.distance(p1 + (p2 - p1) * t12));
     closePt = p1 + (p2 - p1) * t12;
   }
   if(t13 >= 0 && t13 <= 1.) {
     if(p.distance(p1 + (p3 - p1) * t13) < fabs(d))
       closePt = p1 + (p3 - p1) * t13;
     d = sign * std::min(fabs(d), p.distance(p1 + (p3 - p1) * t13));
   }
   if(t23 >= 0 && t23 <= 1.) {
     if(p.distance(p2 + (p3 - p2) * t23) < fabs(d))
       closePt = p2 + (p3 - p2) * t23;
     d = sign * std::min(fabs(d), p.distance(p2 + (p3 - p2) * t23));
   }
   if(p.distance(p1) < fabs(d)) {
     closePt = p1;
     d = sign * std::min(fabs(d), p.distance(p1));
   }
   if(p.distance(p2) < fabs(d)) {
     closePt = p2;
     d = sign * std::min(fabs(d), p.distance(p2));
   }
   if(p.distance(p3) < fabs(d)) {
     closePt = p3;
     d = sign * std::min(fabs(d), p.distance(p3));
   }
 }
}

HXTStatus hxtDistanceToTriangles(HXTForest *forest, std::vector<uint64_t> *candidates, const SPoint3 &p, double &d, uint64_t &closestTri){
  SPoint3 p1 = SPoint3();
  SPoint3 p2 = SPoint3();
  SPoint3 p3 = SPoint3();
  SPoint3 closePt = SPoint3();

  d = DBL_MAX;

  double x,y,z;

  for(std::vector<uint64_t>::iterator tri = candidates->begin(); tri != candidates->end(); ++tri){
    // Coordonnees des points du triangle
    int node1 = forest->forestOptions->mesh->triangles.node[(size_t) 3*(*tri)  ];
    int node2 = forest->forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+1];
    int node3 = forest->forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+2];
      
    x = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node1  ];
    y = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node1+1];
    z = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node1+2];
    p1.setPosition(x,y,z);
    x = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node2  ];
    y = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node2+1];
    z = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node2+2];
    p2.setPosition(x,y,z);
    x = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node3  ];
    y = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node3+1];
    z = forest->forestOptions->mesh->vertices.coord[(size_t) 4*node3+2];
    p3.setPosition(x,y,z);

    double d_tmp;
    signedDistancePointTriangle2(p1, p2, p3, p, d_tmp, closePt);
    if(d_tmp <= d) closestTri = *tri;
    d = fmin(d, fabs(d_tmp));
  }

  return HXT_STATUS_OK;

}

// Algorithme breadth first search pour eliminer les triangles de candidates 
// qui sont proches de node par rapport a la topologie de la triangulation (!= distance euclidienne)
// In : - candidates, le vecteur des triangles qui intersectent la boite de cote h autour de node
//      - node, le noeud courant dans SurfacesProches
void eliminateTriangles(HXTForest *forest, std::vector<uint64_t> *candidates, int node){

  double *n = forest->forestOptions->nodeNormals + 3*node;
  // printf("Normale au noeud : (%f, %f, %f)\n", n[0], n[1], n[2]);
  // Contient des noeuds (il faut partir de node)
  std::queue<int> q; 
  // Determiner toutes les couleurs du noeud
  int currentColor;
  std::vector<int> nodeColors, allColors;
  for(std::vector<uint64_t>::iterator tri = candidates->begin(); tri != candidates->end(); ++tri){
    currentColor = forest->forestOptions->mesh->triangles.colors[(size_t)(*tri)];
    if(std::find(allColors.begin(), allColors.end(), currentColor) == allColors.end())
      allColors.push_back(currentColor);
    for(int i = 0; i < 3; ++i){
      if(forest->forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+i] == node){
        if(std::find(nodeColors.begin(), nodeColors.end(), currentColor) == nodeColors.end()){
          nodeColors.push_back(currentColor);
        }
      }
    }
  }
  // printf("Nombre de couleurs pour le noeud %d : %d\n", node, nodeColors.size());
  std::vector<uint64_t> savedCandidates;
  // Partir de node (ajouter dans la file)
  q.push(node);
  while(!q.empty()){
    // Prendre tous les triangles de candidates qui contiennent node, puis les retirer de candidates. 
    // Prendre tous les noeuds de ces triangles et les ajouter dans la file
    for(std::vector<uint64_t>::iterator tri = candidates->begin(); tri != candidates->end(); ){

      // std::cout << "Couleur = " << forest->forestOptions->mesh->triangles.colors[(size_t) (*tri)] << std::endl;
      currentColor = forest->forestOptions->mesh->triangles.colors[(size_t)(*tri)];

      bool flag = false;
      for(int i = 0; i < 3; ++i){
        int local_node = forest->forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+i];
        if(local_node == q.front()) flag = true;
      }

      // Si q.front() est dans le triangle courant, on ajoute les deux autres sommets et on retire le triangle de la liste
      if(flag){
        for(int i = 0; i < 3; ++i){
          int local_node = forest->forestOptions->mesh->triangles.node[(size_t) 3*(*tri)+i];
          if(local_node != q.front()) q.push(local_node);
        }

        if(std::count(nodeColors.begin(), nodeColors.end(), currentColor) == 0){
          savedCandidates.push_back(*tri);
        }
        
        tri = candidates->erase(tri);

      } else{
        ++tri;
      }
    }
    q.pop();
  }

  if(allColors.size() > 2){
    for(std::vector<uint64_t>::iterator it = savedCandidates.begin(); it < savedCandidates.end(); ++it){
      candidates->push_back(*it);
    }
  }

  for(std::vector<uint64_t>::iterator it = candidates->begin(); it < candidates->end(); ){
    double *v0 = &forest->forestOptions->nodeNormals[3*forest->forestOptions->mesh->triangles.node[3*(*it)+0]];
    double *v1 = &forest->forestOptions->nodeNormals[3*forest->forestOptions->mesh->triangles.node[3*(*it)+1]];
    double *v2 = &forest->forestOptions->nodeNormals[3*forest->forestOptions->mesh->triangles.node[3*(*it)+2]];

    double cos0 = v0[0]*n[0] + v0[1]*n[1] + v0[2]*n[2]; // Les normales sont censees etre unitaires
    double cos1 = v1[0]*n[0] + v1[1]*n[1] + v1[2]*n[2]; // Les normales sont censees etre unitaires
    double cos2 = v2[0]*n[0] + v2[1]*n[1] + v2[2]*n[2]; // Les normales sont censees etre unitaires

    double cosMin = 0.7; // Plus grand que sqrt(2)/2 pour les coins à 45° ?
    int areNormalsNotAligned = (fabs(cos0) < cosMin) + (fabs(cos1) < cosMin) + (fabs(cos2) < cosMin);
    int areNormalsInRightDirection = (cos0 > 0) + (cos1 > 0) + (cos2 > 0);

    if(areNormalsNotAligned >= 1 || areNormalsInRightDirection >= 1){
      it = candidates->erase(it);
    }else{
      ++it;
    }
  }

  // if(!candidates->empty()){
  //   globCount++;
  // }


   // std::cout<<"Elements restants"<<std::endl;
   // for(auto &val : *candidates)
     // std::cout<<val<<std::endl;
}

HXTStatus hxtForestCloseSurfaces(HXTForest *forest){

  // Pour chaque noeud : recuperer sa taille dans l'octree et prendre les triangles dans la boule de rayon h
  SPoint3 p = SPoint3();
  // sc_array_t *points = sc_array_new_size(sizeof(size_point_t), forest->forestOptions->mesh->vertices.num);
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);
  size_point_t *p_tmp;

  // La taille du noeud courant
  double size, x, y, z; 
  double min[3], max[3];

  bool debug = true;
  FILE* file = fopen("pointsConnectesAvecAngles.pos", "w");
    if(file==NULL)
      return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  if(debug){
    fprintf(file, "View \"pointsConnectesAvecAngles\" {\n");
  }

  // int percents = 10, steps = forest->forestOptions->mesh->vertices.num / 10;
  for(uint64_t i = 0; i < forest->forestOptions->mesh->vertices.num; ++i){
    p_tmp = (size_point_t *) sc_array_index(points, 0);

    p_tmp->x = x = forest->forestOptions->mesh->vertices.coord[(size_t) 4*i  ];
    p_tmp->y = y = forest->forestOptions->mesh->vertices.coord[(size_t) 4*i+1];
    p_tmp->z = z = forest->forestOptions->mesh->vertices.coord[(size_t) 4*i+2];

    HXT_CHECK(hxtForestSearchOne(forest, x, y, z, &size, false));

    // Boite autour du point de taille h
    min[0] = x - size; max[0] = x + size;
    min[1] = y - size; max[1] = y + size;
    min[2] = z - size; max[2] = z + size;
    std::vector<uint64_t> candidates;  
    forest->forestOptions->triRTree->Search(min, max, rtreeCallback, &candidates);

    if(!candidates.empty()){

      eliminateTriangles(forest, &candidates, i);

      if(!candidates.empty()){
        uint64_t closestTri;
        p.setPosition(x,y,z);
        hxtDistanceToTriangles(forest, &candidates, p, size, closestTri);

        if(debug){
          double x_avg, y_avg, z_avg;
          // for(std::vector<uint64_t>::iterator it = candidates.begin(); it < candidates.end(); ++it){
            x_avg = y_avg = z_avg = 0.0;
            for(int i = 0; i < 3; ++i){
              // uint64_t node = forest->forestOptions->mesh->triangles.node[(size_t) 3*(*it)+i];
              uint64_t node = forest->forestOptions->mesh->triangles.node[(size_t) 3*closestTri+i];
              x_avg += 1.0/3.0 * forest->forestOptions->mesh->vertices.coord[(size_t) 4*node];
              y_avg += 1.0/3.0 * forest->forestOptions->mesh->vertices.coord[(size_t) 4*node+1];
              z_avg += 1.0/3.0 * forest->forestOptions->mesh->vertices.coord[(size_t) 4*node+2];
            }
            fprintf(file, "SL(%f,%f,%f,%f,%f,%f){%f,%f};\n", x, y, z, x_avg, y_avg, z_avg, size, size);
          // }
        }

        size = fmin(size, size/forest->forestOptions->nodePerGap);
        size = fmax(size, forest->forestOptions->hmin);
        // printf("Taille corrigée au noeud %d = %f \n", i+1, size);
        p_tmp->size = size;

        // On cherche dans l'octree et on remplace dans les quadrants associes aux noeuds
        p4est_search(forest->p4est, NULL, hxtOctreeReplaceCallback, points);
      }
    }

    // if(i%steps==0){
    //   printf("[%d%]\n", percents);
    //   percents += 10;
    // }

  }

  if(debug){
    fprintf(file, "};");
    fclose(file);
  }

  // printf("%d listes non vides\n", globCount);

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   ESTIMATE NUMBER OF TETRAHEDRA IN THE VOLUME MESH
   ======================================================================================================== */

void elementEstimateCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;

  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  double center[3];
  getCellCenter(p4est, which_tree, q, center);

  double octantVolume = data->h * data->h * data->h;
  double tetVolume = data->size * data->size * data->size * sqrt(2) / 12.0;

  *((double *) user_data) += octantVolume/tetVolume;
}

HXTStatus hxtOctreeElementEstimation(HXTForest *forest, double *elemEstimate){
  p4est_iterate (forest->p4est, NULL, (void *) elemEstimate, elementEstimateCallback, NULL,
            #ifdef P4_TO_P8
                       NULL,
            #endif
                       NULL);
  return HXT_STATUS_OK;
}

/* ========================================================================================================
   EXPORT
   ======================================================================================================== */

void exportToTetraCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;

  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  HXTForestOptions   *forestOptions = (HXTForestOptions *) p4est->user_pointer;

  FILE* f = (FILE*) user_data;

  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);

  double h = data->h, s = data->size, epsilon = 1e-12;
  x[0] = x[1] = x[4] = x[5] = center[0]-h - epsilon;
  x[2] = x[3] = x[6] = x[7] = center[0]+h + epsilon;
  y[0] = y[3] = y[4] = y[7] = center[1]-h - epsilon;
  y[1] = y[2] = y[5] = y[6] = center[1]+h + epsilon;
  z[0] = z[1] = z[2] = z[3] = center[2]-h - epsilon;
  z[4] = z[5] = z[6] = z[7] = center[2]+h + epsilon;
  
  fprintf(f, "SS(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
                 x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[4], y[4], z[4], s, s, s, s);
  fprintf(f, "SS(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
                 x[0], y[0], z[0], x[2], y[2], z[2], x[3], y[3], z[3], x[4], y[4], z[4], s, s, s, s);
  fprintf(f, "SS(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
                 x[1], y[1], z[1], x[2], y[2], z[2], x[4], y[4], z[4], x[5], y[5], z[5], s, s, s, s);
  fprintf(f, "SS(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
                 x[2], y[2], z[2], x[3], y[3], z[3], x[4], y[4], z[4], x[6], y[6], z[6], s, s, s, s);
  fprintf(f, "SS(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
                 x[2], y[2], z[2], x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], s, s, s, s);
  fprintf(f, "SS(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
                 x[3], y[3], z[3], x[4], y[4], z[4], x[6], y[6], z[6], x[7], y[7], z[7], s, s, s, s);
}

void exportToHexCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;

  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  HXTForestOptions   *forestOptions = (HXTForestOptions *) p4est->user_pointer;

  FILE* f = (FILE*) user_data;

  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);

  double h = data->h/2.0, s = data->size, epsilon = 1e-12;
  x[0] = x[3] = x[4] = x[7] = center[0]-h - epsilon;
  x[1] = x[2] = x[5] = x[6] = center[0]+h + epsilon;
  y[0] = y[1] = y[4] = y[5] = center[1]-h - epsilon;
  y[2] = y[3] = y[6] = y[7] = center[1]+h + epsilon;
  z[0] = z[1] = z[2] = z[3] = center[2]-h - epsilon;
  z[4] = z[5] = z[6] = z[7] = center[2]+h + epsilon;
  
  fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f,%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n", 
    x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3], 
    x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7], 
    s, s, s, s, s, s, s, s);
}

HXTStatus hxtForestExport(HXTForest *forest){
  std::string fFile = std::string(forest->forestOptions->forestFile) + ".pos";
  FILE* f = fopen(fFile.c_str(), "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  fprintf(f, "View \"sizeField\" {\n");
  p4est_iterate(forest->p4est, NULL, (void*) f, exportToHexCallback, NULL,
            #ifdef P4_TO_P8
                        NULL,
            #endif
                        NULL);
  fprintf(f, "};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus hxtForestSave(HXTForest *forest){
  // int memUsage = p4est_memory_used(forest->p4est);
  // Msg::Info("Memory used by the forest : %d bytes", memUsage);
  std::string fFile = std::string(forest->forestOptions->forestFile) + ".p4est";
  p4est_save_ext(fFile.c_str(), forest->p4est, true, false);
  return HXT_STATUS_OK;
}

#else // HAVE_P4EST
HXTStatus hxtForestSearchOne(HXTForest *forest, double x, double y, double z, double *size, int linear) {

  *size = 1.e22;
  static int count = 0;
  if (count ++ < 20)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"HXT needs P4EST to compute automatic size fields");
  return HXT_STATUS_ERROR;
}

#endif // HAVE_P4EST