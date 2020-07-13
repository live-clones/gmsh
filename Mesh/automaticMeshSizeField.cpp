#include "automaticMeshSizeField.h"
#include "GModel.h"
#include "GRegion.h"
#include "GFace.h"
#include "GEntity.h"
#include "MVertex.h"
#include "MTetrahedron.h"
#include "SBoundingBox3d.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "curvature.h"
#include "robustPredicates.h"

#include <queue>
#include <inttypes.h>

#ifdef HAVE_HXT
extern "C" {
#include "hxt_tools.h"
#include "hxt_edge.h"
#include "hxt_curvature.h"
#include "hxt_bbox.h"
#include "hxt_tetMesh.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetRefine.h"
}
#endif

#if defined(HAVE_P4EST)
#include <p8est_search.h>
#endif

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
static inline void norme2(double v[3], double* norme2){
  *norme2 = sqrt(v[0]*v[0]+v[1]*v[1]+v[2]*v[2]);
}

static inline bool isPoint(double x1, double y1, double z1, double x2, double y2, double z2, double tol){
  return (fabs(x2 - x1) < tol && fabs(y2 - y1) < tol && fabs(z2 - z1) < tol);
}

void writeNodalCurvature(double *nodalCurvature, int size, const char *filename){
  FILE* f = fopen(filename, "w");
  if(f==NULL){
  printf("Erreur : fileOutput == NULL\n");
    exit(-1);
  }

  for(int i = 0; i < size; ++i){
    fprintf(f, "%f %f %f - %d\n",
      nodalCurvature[6 * i + 0],
      nodalCurvature[6 * i + 1],
      nodalCurvature[6 * i + 2],i);
    fprintf(f, "%f %f %f\n",
      nodalCurvature[6 * i + 3],
      nodalCurvature[6 * i + 4],
      nodalCurvature[6 * i + 5]);
  }
  fclose(f);
}

static HXTStatus getAllFacesOfAllRegions(std::vector<GRegion *> &regions, HXTMesh *m, std::vector<GFace *> &allFaces){
  std::set<GFace *, GEntityPtrLessThan> allFacesSet;
  if(m) {
    m->brep.numVolumes = regions.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numSurfacesPerVolume,
                               m->brep.numVolumes * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    if(m) {
      m->brep.numSurfacesPerVolume[i] = f.size() + f_e.size();
      to_alloc += m->brep.numSurfacesPerVolume[i];
    }
    allFacesSet.insert(f.begin(), f.end());
    allFacesSet.insert(f_e.begin(), f_e.end());
  }
  allFaces.insert(allFaces.begin(), allFacesSet.begin(), allFacesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.surfacesPerVolume, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < regions.size(); i++) {
    std::vector<GFace *> const &f = regions[i]->faces();
    std::vector<GFace *> const &f_e = regions[i]->embeddedFaces();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.surfacesPerVolume[counter++] = f_e[j]->tag();
  }

   printf("volume 0 has %d faces\n",m->brep.numSurfacesPerVolume[0]);
   for (int i=0;i<m->brep.numSurfacesPerVolume[0];i++)printf("%d",m->brep.surfacesPerVolume[i]); printf("\n");

  return HXT_STATUS_OK;
}

static HXTStatus getAllEdgesOfAllFaces(std::vector<GFace *> &faces, HXTMesh *m, std::vector<GEdge *> &allEdges){
  if(m) {
    m->brep.numSurfaces = faces.size();
    HXT_CHECK(hxtAlignedMalloc(&m->brep.numCurvesPerSurface,
                               m->brep.numSurfaces * sizeof(uint32_t)));
  }
  uint32_t to_alloc = 0;

  std::set<GEdge *, GEntityPtrLessThan> allEdgesSet;
  for(std::size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> const &f = faces[i]->edges();
    std::vector<GEdge *> const &f_e = faces[i]->embeddedEdges();
    if(m) {
      m->brep.numCurvesPerSurface[i] = f.size() + f_e.size();
      to_alloc += m->brep.numCurvesPerSurface[i];
    }
    allEdgesSet.insert(f.begin(), f.end());
    allEdgesSet.insert(f_e.begin(), f_e.end());
  }
  allEdges.insert(allEdges.begin(), allEdgesSet.begin(), allEdgesSet.end());

  if(!m) return HXT_STATUS_OK;

  HXT_CHECK(
    hxtAlignedMalloc(&m->brep.curvesPerSurface, to_alloc * sizeof(uint32_t)));

  uint32_t counter = 0;
  for(std::size_t i = 0; i < faces.size(); i++) {
    std::vector<GEdge *> const &f = faces[i]->edges();
    std::vector<GEdge *> const &f_e = faces[i]->embeddedEdges();
    for(size_t j = 0; j < f.size(); j++)
      m->brep.curvesPerSurface[counter++] = f[j]->tag();
    for(size_t j = 0; j < f_e.size(); j++)
      m->brep.curvesPerSurface[counter++] = f_e[j]->tag();
  }
  return HXT_STATUS_OK;
}

HXTStatus Gmsh2Hxt(std::vector<GRegion *> &regions, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v);

HXTStatus Gmsh2Hxt(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v);

HXTStatus Gmsh2HxtLocal(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v){
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t ntri = 0;
  uint64_t nedg = 0;

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    nedg += ge->lines.size();
    // for(size_t i = 0; i < ge->lines.size(); i++) {
    //   all.insert(ge->lines[i]->getVertex(0));
    //   all.insert(ge->lines[i]->getVertex(1));
    // }
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    ntri += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  // printf("%d vertices %d triangles\n",all.size(),ntri);

  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  size_t count = 0;
  c2v.resize(all.size());
  for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
    m->vertices.coord[4 * count + 0] = (*it)->x();
    m->vertices.coord[4 * count + 1] = (*it)->y();
    m->vertices.coord[4 * count + 2] = (*it)->z();
    m->vertices.coord[4 * count + 3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->lines.num = m->lines.size = nedg;
  uint64_t index = 0;

  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.node, (m->lines.num) * 2 * sizeof(uint32_t)));
  HXT_CHECK(
    hxtAlignedMalloc(&m->lines.colors, (m->lines.num) * sizeof(uint16_t)));

  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    for(size_t i = 0; i < ge->lines.size(); i++) {
      m->lines.node[2 * index + 0] = v2c[ge->lines[i]->getVertex(0)];
      m->lines.node[2 * index + 1] = v2c[ge->lines[i]->getVertex(1)];
      m->lines.colors[index] = ge->tag();
      index++;
    }
  }

  m->triangles.num = m->triangles.size = ntri;
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.colors,
                             (m->triangles.num) * sizeof(uint16_t)));

  index = 0;
  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      m->triangles.node[3 * index + 0] = v2c[gf->triangles[i]->getVertex(0)];
      m->triangles.node[3 * index + 1] = v2c[gf->triangles[i]->getVertex(1)];
      m->triangles.node[3 * index + 2] = v2c[gf->triangles[i]->getVertex(2)];
      m->triangles.colors[index] = gf->tag();
      index++;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus Gmsh2HxtGlobal(std::vector<GFace *> &faces, HXTMesh *m, std::map<MVertex *, uint32_t> &v2c, std::vector<MVertex *> &c2v){
  std::vector<GEdge *> edges;
  HXT_CHECK(getAllEdgesOfAllFaces(faces, m, edges));
  std::set<MVertex *> all;

  uint64_t cumsum = 0;
  uint64_t cumsumNoEdges = 0;
  for(size_t j = 0; j < edges.size(); j++) {
    GEdge *ge = edges[j];
    cumsum += ge->lines.size();
    for(size_t i = 0; i < ge->lines.size(); i++) {
      all.insert(ge->lines[i]->getVertex(0));
      all.insert(ge->lines[i]->getVertex(1));
    }
  }

  for(size_t j = 0; j < faces.size(); j++) {
    GFace *gf = faces[j];
    cumsum += gf->triangles.size();
    cumsumNoEdges += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
  }

  c2v.resize(cumsum);
  all.clear();
  
  cumsum = 0;
  size_t count_c2v2 = 0;
  for(size_t j = 0; j < faces.size(); ++j){
    // all propre à la face
    GFace *gf = faces[j];
    cumsum += gf->triangles.size();
    for(size_t i = 0; i < gf->triangles.size(); i++) {
      all.insert(gf->triangles[i]->getVertex(0));
      all.insert(gf->triangles[i]->getVertex(1));
      all.insert(gf->triangles[i]->getVertex(2));
    }
    size_t count = 0;
    for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
      v2c[*it] = count++;
      c2v[count_c2v2++] = *it;
    }
    all.clear();
  }

  return HXT_STATUS_OK;
}

/* ======================================================================================
   Functions from hxt_octree
   ====================================================================================== */

static bool rtreeCallback(uint64_t id, void *ctx) {
  std::vector<uint64_t>* vec = reinterpret_cast< std::vector<uint64_t>* >(ctx);
  vec->push_back(id);
  return true;
}

/* Create a p4est connectivity structure for the given bounding box. */
static p4est_connectivity_t * p8est_connectivity_new_cube(ForestOptions *forestOptions){
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

static p4est_connectivity_t * p8est_connectivity_new_square(ForestOptions *forestOptions){
  const p4est_topidx_t num_vertices = 8;
  const p4est_topidx_t num_trees = 1;
  const p4est_topidx_t num_ett = 0;
  const p4est_topidx_t num_ctt = 0;

  double centreX = (forestOptions->bbox[0]+forestOptions->bbox[3]) / 2.0;
  double centreY = (forestOptions->bbox[1]+forestOptions->bbox[4]) / 2.0;
  double cX      = (forestOptions->bbox[3]-forestOptions->bbox[0]) / 2.0;
  double cY      = (forestOptions->bbox[4]-forestOptions->bbox[1]) / 2.0;

  double scalingFactor = 1.5; // The octree is this times bigger than the surface mesh's bounding box
  double c = scalingFactor * fmax(cX,cY);

  // TODO : Compute any bounding box, not necessarily aligned with the axes
  const double vertices[8 * 3] = {
    centreX-c, centreY-c, 0.0,
    centreX+c, centreY-c, 0.0,
    centreX-c, centreY+c, 0.0,
    centreX+c, centreY+c, 0.0,
    centreX-c, centreY-c, 0.0,
    centreX+c, centreY-c, 0.0,
    centreX-c, centreY+c, 0.0,
    centreX+c, centreY+c, 0.0,
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
static inline double bulkSize(double x, double y, double z, double hBulk){
  return hBulk;
}

/* Fills xyz[] with the coordinates of the center of the given tree cell. */
static inline void getCellCenter(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double xyz[3]){
  p4est_qcoord_t      half_length = P4EST_QUADRANT_LEN (q->level) / 2;
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x + half_length, q->y + half_length, q->z + half_length, xyz);
}

/* Fills min[] & max[] with the coordinates of the cell viewed as a bounding box. */
static inline void getCellBBox(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double min[3], double max[3]){
  p4est_qcoord_t      length = P4EST_QUADRANT_LEN (q->level);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x, q->y, q->z, min);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x + length, q->y + length, q->z + length, max);
}

/* Fills h with the dimension of the given cell (length of a cell edge). */
static void getCellSize(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q, double *h)
{
  double min[3], max[3];
  p4est_qcoord_t      length = P4EST_QUADRANT_LEN (q->level);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x, q->y, q->z, min);
  p4est_qcoord_to_vertex (p4est->connectivity, which_tree, q->x + length, q->y + length, q->z + length, max);
  // All cell edges are supposed to be the same length h (-:
  *h = fmax(max[0] - min[0],fmax(max[1] - min[1],max[2] - min[2]));
}

/* Callback used by p4est to initialize the user_data on each tree cell. */
static inline void initializeCell(p4est_t* p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions  *forestOptions = (ForestOptions *) p4est->user_pointer;
  size_data_t       *data = (size_data_t *) q->p.user_data;

  double center[3]; 
  getCellCenter(p4est, which_tree, q, center);

  // Set cell size 
  data->size = forestOptions->sizeFunction(center[0], center[1], center[2], forestOptions->hbulk);
  // Set size gradient to zero
  for(int i = 0; i < P4EST_DIM; ++i) data->ds[i] = 0.0;
  // Set cell dimension (edge length)
  getCellSize(p4est, which_tree, q, &(data->h));
}

/* Creates (allocates) the forestOptions structure. */
HXTStatus forestOptionsCreate(ForestOptions **forestOptions){
  HXT_CHECK( hxtAlignedMalloc (forestOptions, sizeof(ForestOptions)) );
    if(*forestOptions == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  return HXT_STATUS_OK;
}

/* Destroys forestOptions. */
HXTStatus forestOptionsDelete(ForestOptions **forestOptions){
  HXT_CHECK(hxtFree(forestOptions));
  return HXT_STATUS_OK;
}

HXTStatus loadGlobalData(ForestOptions *forestOptions, const char *filename){
  FILE* f = fopen(filename,"r");
  char buf[BUFSIZ]={""};
  if(fgets(buf,BUFSIZ,f) == NULL){
    return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  }
  sscanf(buf, "%lf %lf", &forestOptions->hmin, &forestOptions->hmax);
  fclose(f);
  Msg::Info("Loaded global data from %s",filename);
  Msg::Info("Min size = %f", forestOptions->hmin);
  Msg::Info("Max size = %f", forestOptions->hmax);
  return HXT_STATUS_OK;
}

/* Creates a (sequential) forest structure by loading a p4est file. */
HXTStatus forestLoad(Forest **forest, const char* forestFile, const char *dataFile, ForestOptions *forestOptions){
  if(forestFile == NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  HXT_CHECK( hxtMalloc(forest, sizeof(Forest)) );
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  HXT_CHECK(loadGlobalData(forestOptions, dataFile));
  p4est_connectivity_t *connect;
  sc_MPI_Comm mpicomm = sc_MPI_COMM_WORLD;
  int load_data = true;
  int autopartition = true;
  int broadcasthead = true;

  (*forest)->p4est = p4est_load_ext(forestFile, mpicomm, sizeof(size_data_t), load_data, autopartition, broadcasthead, (void*) forestOptions, &connect);

  ForestOptions *fO = (ForestOptions*) (*forest)->p4est->user_pointer;
  if(fO == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  return HXT_STATUS_OK;
}

/* Creates a (sequential) forest structure from the forestOptions information. 
   The forest is not refined; it consists of the root octant.                   */
HXTStatus forestCreate(int argc, char **argv, Forest **forest, const char* filename, ForestOptions *forestOptions){

  HXT_CHECK( hxtMalloc (forest, sizeof(Forest)) );
  if(*forest == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  int mpiret;
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
  // sc_init(mpicomm, 1, 1, NULL, SC_LP_ESSENTIAL);
  // p4est_init(NULL, SC_LP_PRODUCTION);

  /* Create a connectivity from the bounding box */
  if(forestOptions->dim == 3){ connect = p8est_connectivity_new_cube(forestOptions); }
  else{ connect = p8est_connectivity_new_square(forestOptions); }

  if(connect == NULL) return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  // #ifdef P4EST_WITH_METIS
  //   //  Use metis (if p4est is compiled with the flag '--with-metis') to
  //   //  * reorder the connectivity for better parititioning of the forest
  //   //  * across processors. 
  //   p4est_connectivity_reorder(mpicomm, 0, conn, P4EST_CONNECT_FACE);
  // #endif /* P4EST_WITH_METIS */

  // Assign bulkSize callback if no sizeFunction is specified.
  if(forestOptions->sizeFunction == NULL) forestOptions->sizeFunction = &bulkSize;

  (*forest)->p4est = p4est_new(mpicomm, connect, sizeof(size_data_t), initializeCell, (void*) forestOptions);
  (*forest)->forestOptions = forestOptions;

  return HXT_STATUS_OK;
}

/* Deletes the forest structure. */
HXTStatus forestDelete(Forest **forest){
    /* Destroy the p4est structure. */
    p4est_connectivity_destroy((*forest)->p4est->connectivity);
    p4est_destroy((*forest)->p4est);
    /* Verify that allocations internal to p4est and sc do not leak memory.
     * This should be called if sc_init () has been called earlier. */
    // sc_finalize();
    /* This is standard MPI programs.  Without --enable-mpi, this is a dummy. */
    int mpiret = sc_MPI_Finalize();
    SC_CHECK_MPI(mpiret);

    HXT_CHECK(hxtFree(forest));

    return HXT_STATUS_OK;
}

/* ========================================================================================================
   FOREST REFINEMENT
   ======================================================================================================== */

/* Callback used by octreeRefineToBulkSize; returns 1 if the cells need refinement, 0 otherwise. */
static inline int refineToBulkSizeCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  size_data_t *data = (size_data_t *) q->p.user_data;
  return data->h > forestOptions->hbulk;
}

/* Used by curvatureRefine; returns 1 if the cell should be
   refined according to the surface mesh curvature, 0 otherwise. */
static int curvatureRefineCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *q){
  ForestOptions   *forestOptions = (ForestOptions *) p4est->user_pointer;
  double h;
  getCellSize(p4est, which_tree, q, &h);
  double center[3]; 
  getCellCenter(p4est, which_tree, q, center);

  if(forestOptions->dim == 3){
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
          norme2(v1, &k1);
          norme2(v2, &k2);

          kmax = fmax(kmax,fmax(k1,k2));
          kmin = fmin(kmin,fmin(k1,k2));
        }
      }

      // No curvature : the cell is not refined
      if(fabs(kmax) < 1e-3){
          return 0;
      } else{
        // There is curvature : the cell size should accurately represent the surface
        // Cell is refined according to the chosen density of nodes
        double hc = 2*M_PI/(forestOptions->nodePerTwoPi * kmax);
        double nElemPerCell = 2;

        if(h > hc/nElemPerCell && h >= forestOptions->hmin){
          return 1;
        } else{
          return 0;
        }
      }
    } else{ // candidates.empty()
      // If the cell has no intersection with any triangle of the surface mesh, it is not refined.
      return 0;
    }
  } else{
    // 2D curvature refinement is still a work in progress
    double kmax = -1.e22;
    double x, y;
    bool inbox;

    // Calculer kmax sur toutes les courbes
    int n = 10;
    double par[n];
    for(uint16_t i = 0; i < n; ++i) par[i] = i*2.*M_PI/n; 

    for(uint16_t i = 0; i < (*forestOptions->curvFunctions).size(); ++i){
      for(uint16_t j = 0; j < n; ++j){
        x = (*forestOptions->xFunctions)[i](par[j]);
        y = (*forestOptions->yFunctions)[i](par[j]);
        inbox  = (x <= center[0] + h/2.) && (x >= center[0] - h/2.);
        inbox &= (y <= center[1] + h/2.) && (y >= center[1] - h/2.);
        if(inbox) kmax = fmax(kmax, fabs((*forestOptions->curvFunctions)[i](par[j])));
      }
    }
    
    if(kmax > 0){
      if(kmax < 1e-3){
        return 0;
      } else{
        double hc = 2*M_PI/(forestOptions->nodePerTwoPi * kmax);
        int nElemPerCell = 1;
         if(h > hc/nElemPerCell && h >= forestOptions->hmin){
          return 1;
        } else{
          return 0;
        }
      }
    } else{
      return 0;
    }  
  }
}

static int coarsenCallback(p4est_t *p4est, p4est_topidx_t which_tree, p4est_quadrant_t *children[]){
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;

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
  ForestOptions   *forestOptions = (ForestOptions *) user_data;

  double h;
  getCellSize(p4est, which_tree, q, &h);
  double center[3]; 
  getCellCenter(p4est, which_tree, q, center);

  if(forestOptions->dim == 3){
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
          norme2(v1, &k1);
          norme2(v2, &k2);
          kmax = fmax(kmax,fmax(k1,k2));
        }
      }
      data->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, 2*M_PI/(forestOptions->nodePerTwoPi * kmax)));
      // data->size = kmax;
    }
    else{
      data->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, data->size));
    }
  } else{
    // 2D
    double kmax = -1.e22;
    double x, y;
    bool inbox;

    // Calculer kmax sur toutes les courbes
    int n = 10;
    double par[n];
    for(uint16_t i = 0; i < n; ++i) par[i] = i*2.*M_PI/n; 

    for(uint16_t i = 0; i < (*forestOptions->curvFunctions).size(); ++i){
      for(uint16_t j = 0; j < n; ++j){
        x = (*forestOptions->xFunctions)[i](par[j]);
        y = (*forestOptions->yFunctions)[i](par[j]);
        inbox  = (x <= center[0] + h/2.) && (x >= center[0] - h/2.);
        inbox &= (y <= center[1] + h/2.) && (y >= center[1] - h/2.);
        if(inbox) kmax = fmax(kmax, fabs((*forestOptions->curvFunctions)[i](par[j])));
      }
    }
    
    if(kmax > 0){
      double hc = 2*M_PI/(forestOptions->nodePerTwoPi * kmax);
      data->size = fmin(data->size, hc);
    }
  }
}

HXTStatus forestRefine(Forest *forest){
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
    // Reset gradient.
    data->ds[0] = 0.0;
    data->ds[1] = 0.0;
    data->ds[2] = 0.0;
}

static void computeGradientCenter(p4est_iter_face_info_t * info, void *user_data){
    p4est_iter_face_side_t *side[2];
    sc_array_t             *sides = &(info->sides);
    size_data_t            *data;
    size_data_t            *data_opp;
    double                  s_avg, s_sum;
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
          }
          s_sum = s_avg;
          s_avg /= P4EST_HALF;

          data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

          switch(which_face_opp){
            case 0 : data_opp->ds[0] -= 0.5 * (s_avg - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
            case 1 : data_opp->ds[0] += 0.5 * (s_avg - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
            case 2 : data_opp->ds[1] -= 0.5 * (s_avg - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
            case 3 : data_opp->ds[1] += 0.5 * (s_avg - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
            case 4 : data_opp->ds[2] -= 0.5 * (s_avg - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
            case 5 : data_opp->ds[2] += 0.5 * (s_avg - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
          }
        }
        // Current cell is full
        else{
          data = (size_data_t *) side[i]->is.full.quad->p.user_data;
          if(side[iOpp]->is_hanging){

            // Current full - Opposite hanging
            double s_avg_opp = 0;
            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              s_avg_opp += data_opp->size;
            }
            s_avg_opp /= P4EST_HALF;

            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              switch(which_face_opp){
                case 0 : data_opp->ds[0] -= 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
                case 1 : data_opp->ds[0] += 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
                case 2 : data_opp->ds[1] -= 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
                case 3 : data_opp->ds[1] += 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
                case 4 : data_opp->ds[2] -= 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
                case 5 : data_opp->ds[2] += 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
              }
            }
          }
          else{
            // Current full - Opposite full
            data_opp = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
            switch(which_face_opp){
              case 0 : data_opp->ds[0] -= 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
              case 1 : data_opp->ds[0] += 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
              case 2 : data_opp->ds[1] -= 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
              case 3 : data_opp->ds[1] += 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
              case 4 : data_opp->ds[2] -= 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
              case 5 : data_opp->ds[2] += 0.5 * (data->size - data_opp->size)/(data_opp->h/2. + data->h/2.); break;
            }
          }
        }
      }
    }
    // Nothing to do on the boundaries (0 flux)
}

HXTStatus forestComputeGradient(Forest *forest){
  // Iterate on each cell to reset size gradient and half lengths.
  p4est_iterate(forest->p4est, NULL, NULL, resetCell, NULL, NULL, NULL);
  // Compute gradient at cell center using finite differences
  p4est_iterate(forest->p4est, NULL, NULL, NULL, computeGradientCenter, NULL, NULL);

  return HXT_STATUS_OK;
}

static inline void getMaxGradient(p4est_iter_volume_info_t * info, void *user_data)
{
  p4est_quadrant_t *q = info->quad;
  size_data_t      *data = (size_data_t *) q->p.user_data;
  double           *gradMax = static_cast<double*>(user_data);
  gradMax[0] = SC_MAX (fabs(data->ds[0]), gradMax[0]);
  gradMax[1] = SC_MAX (fabs(data->ds[1]), gradMax[1]);
  gradMax[2] = SC_MAX (fabs(data->ds[2]), gradMax[2]);
}

HXTStatus forestGetMaxGradient(Forest *forest, double *gradMax){
  p4est_iterate (forest->p4est, NULL, (void *) gradMax, getMaxGradient, NULL, NULL, NULL);
  return HXT_STATUS_OK;
}

static void limitSize(p4est_iter_face_info_t * info, void *user_data){
  p4est_iter_face_side_t *side[2];
  sc_array_t        *sides = &(info->sides);
  size_data_t       *data;
  size_data_t       *data_opp1;
  int                which_dir;
  int                which_face_opp;
  int                iOpp;

  ForestOptions  *forestOptions = (ForestOptions*) user_data;
  double             alpha = forestOptions->gradation - 1.0;
  double             tol = 1e-3;

  side[0] = p4est_iter_fside_array_index_int (sides, 0);
  side[1] = p4est_iter_fside_array_index_int (sides, 1);

  if(sides->elem_count==2){

    for(int i = 0; i < 2; ++i){

      iOpp = 1 - i;
      which_dir = side[i]->face / 2; // Direction x (0), y (1) ou z(2)
      which_face_opp = side[iOpp]->face;

      if(side[i]->is_hanging){

        // Current hanging - Opposes full
        data_opp1 = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;

        for(int j = 0; j < P4EST_HALF; ++j){

          data = (size_data_t *) side[i]->is.hanging.quad[j]->p.user_data;

          if(fabs(data->ds[which_dir]) > alpha + tol){

            if(data->size > data_opp1->size){
              switch(which_face_opp){
                case 0 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 1 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 2 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 3 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 4 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 5 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
              }
            }else{
              switch(which_face_opp){
                case 0 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 1 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 2 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 3 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 4 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 5 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
              }
            }
          } // if ds > alpha-1
        } // for j hanging
      } // if hanging
      else{

        data = (size_data_t *) side[i]->is.full.quad->p.user_data;

        if(fabs(data->ds[which_dir]) > alpha + tol){
          if(side[iOpp]->is_hanging){
              // Current full - Oppose hanging
            for(int j = 0; j < P4EST_HALF; ++j){
              data_opp1 = (size_data_t *) side[iOpp]->is.hanging.quad[j]->p.user_data;
              if(data->size > data_opp1->size){
                switch(which_face_opp){
                  case 0 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 1 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 2 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 3 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 4 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 5 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                }
              }
              else{
                switch(which_face_opp){
                  case 0 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 1 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 2 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 3 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 4 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                  case 5 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                }
              }
            }
          }
          else{
            // Current full - Oppose full
            data_opp1 = (size_data_t *) side[iOpp]->is.full.quad->p.user_data;
            if(data->size > data_opp1->size){
              switch(which_face_opp){
                case 0 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 1 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 2 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 3 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 4 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 5 : data->size = fmin(data->size, data_opp1->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
              }
            }
            else{
              switch(which_face_opp){
                case 0 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 1 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 2 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 3 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 4 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
                case 5 : data_opp1->size = fmin(data_opp1->size, data->size + (alpha) * (data_opp1->h/2. + data->h/2.)); break;
              }
            }
          }  
        } // if gradient trop grand
      } // else
    }
  }
}

HXTStatus forestLimitSize(Forest *forest){
  p4est_iterate (forest->p4est, NULL, (void*) forest->forestOptions, NULL, limitSize, NULL, NULL);
  return HXT_STATUS_OK;
}

HXTStatus forestSizeSmoothing(Forest *forest){
  double gradMax[3], tol = 1e-3, gradLinf = 1e22;
  int iter = 0, nmax = 100;
  while(iter++ < nmax && gradLinf > tol + forest->forestOptions->gradation - 1.0){
    HXT_CHECK( forestComputeGradient(forest) );    // Compute gradient
    HXT_CHECK( forestLimitSize(forest) );          // Smooth large sizes to limit gradient to foresOptions->gradMax
    for(int i = 0; i < 3; ++i) gradMax[i] = -1e22; // Stopping criterion
    HXT_CHECK( forestGetMaxGradient(forest, gradMax) );
    gradLinf = fmax( fabs(gradMax[0]), fmax( fabs(gradMax[1]), fabs(gradMax[2])) );
  }
  Msg::Info("Max gradient after smoothing : (%f - %f - %f)", fabs(gradMax[0]), fabs(gradMax[1]), fabs(gradMax[2]));
  return HXT_STATUS_OK;
}

/* ========================================================================================================
   SEARCH AND REPLACE
   ======================================================================================================== */

inline static bool isPoint(double x, double y, double z, size_point_t *p, double tol){
  return (fabs(p->x - x) < tol && fabs(p->y - y) < tol && fabs(p->z - z) < tol);
}

static int searchAndAssignConstant(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
  bool in_box, is_leaf = local_num >= 0;
  size_data_t   *data = (size_data_t *) q->p.user_data;
  size_point_t  *p    = (size_point_t *) point;
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants 
  // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
  double h, center[3];
  if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
  else h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  // A point can be on the exact boundary of two cells, hence we take the min.
  if(in_box && is_leaf){
    p->size = fmin(p->size, data->size);
    p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->isFound = true;
  }

  return in_box;
}

static int searchAndAssignLinear(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
  bool in_box, is_leaf = local_num >= 0;
  size_data_t   *data = (size_data_t *) q->p.user_data;
  size_point_t  *p    = (size_point_t *) point;
  ForestOptions *forestOptions = (ForestOptions *) p4est->user_pointer;
  // We have to recompute the cell dimension h for the root (non leaves) octants 
  // because it seems to be undefined. Otherwise it's contained in q->p.user_data.
  double h, center[3];
  if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
  else h = data->h;
  getCellCenter(p4est, which_tree, q, center);

  in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
  in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
  in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

  // A point can be on the exact boundary of two cells, hence we take the min.
  if(in_box && is_leaf){
    p->size = fmin(p->size, data->size + data->ds[0]*(p->x - center[0]) + data->ds[1]*(p->y - center[1]) + data->ds[2]*(p->z - center[2]) );
    p->size = fmax(forestOptions->hmin, fmin(forestOptions->hmax, p->size) );
    p->isFound = true;
  }

  return in_box;
}

static int replace(p4est_t * p4est, p4est_topidx_t which_tree, p4est_quadrant_t * q, p4est_locidx_t local_num, void *point){
    bool in_box, is_leaf = local_num >= 0;
    size_data_t  *data = (size_data_t *) q->p.user_data;
    size_point_t *p    = (size_point_t *) point;
    double h, center[3];
    if(!is_leaf) getCellSize(p4est, which_tree, q, &h);
    else h = data->h;
    getCellCenter(p4est, which_tree, q, center);

    in_box  = (p->x <= center[0] + h/2.) && (p->x >= center[0] - h/2.);
    in_box &= (p->y <= center[1] + h/2.) && (p->y >= center[1] - h/2.);
    in_box &= (p->z <= center[2] + h/2.) && (p->z >= center[2] - h/2.);

    if(in_box && is_leaf){
        data->size = fmin(data->size, p->size);
    }

    return in_box;
}

/* Search for a single point in the tree structure and returns its size.
   See searchAndAssign for the detailed comments. */
HXTStatus forestSearchOne(Forest *forest, double x, double y, double z, double *size, int linear){
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), 1);

  size_point_t *p = (size_point_t *) sc_array_index(points, 0);
  p->x = x;
  p->y = y;
  p->z = z;
  p->size = 1.0e22;
  p->isFound = false;
  
  if(linear){
    p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);
  } else{
    p4est_search(forest->p4est, NULL, searchAndAssignConstant, points);
  }

  if(!p->isFound) Msg::Info("Point (%f,%f,%f) n'a pas été trouvé dans l'octree 8-|", x,y,z);
  *size = p->size;

  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

// Not finished
HXTStatus hxtForestSearch(Forest *forest, std::vector<double> *x, std::vector<double> *y, std::vector<double> *z, std::vector<double> *size){
  // Array of size_point_t to search in the tree
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), (*x).size());
  size_point_t *p;

  for(size_t i = 0; i < (*x).size(); ++i){
    p = (size_point_t *) sc_array_index(points, i);
    p->x = (*x)[i];
    p->y = (*y)[i];
    p->z = (*z)[i];
    p->size = -1.0;
  }
  
  // Search on all cells
  p4est_search(forest->p4est, NULL, searchAndAssignLinear, points);

  // Get the sizes
  for(size_t i = 0; i < (*x).size(); ++i){ 
    p = (size_point_t *) sc_array_index(points, i);
    (*size)[i] = p->size;
  }

  // Clean up
  sc_array_destroy(points);

  return HXT_STATUS_OK;
}

/* ========================================================================================================
   CLOSE SURFACES DETECTION
   ======================================================================================================== */

// To quickly sort 4 integers
static void sort4(int *d){
#define SWAP(x,y) if (d[y] < d[x]) { int tmp = d[x]; d[x] = d[y]; d[y] = tmp; }
  SWAP(0, 1);
  SWAP(2, 3);
  SWAP(0, 2);
  SWAP(1, 3);
  SWAP(1, 2);
#undef SWAP
}

// Checks whether two MTetrahedra have a common face without creating MFaces (slow)
// Returns the index of the common face in t1 if any, -1 otherwise
static int commonFaceTetFast(MTetrahedron *t1, MTetrahedron *t2){
  int t10 = t1->getVertex(0)->getNum();
  int t11 = t1->getVertex(1)->getNum();
  int t12 = t1->getVertex(2)->getNum();
  int t13 = t1->getVertex(3)->getNum();
  int t20 = t2->getVertex(0)->getNum();
  int t21 = t2->getVertex(1)->getNum();
  int t22 = t2->getVertex(2)->getNum();
  int t23 = t2->getVertex(3)->getNum();

  bool b0 = (t10 == t20) || (t10 == t21) || (t10 == t22) || (t10 == t23);
  bool b1 = (t11 == t20) || (t11 == t21) || (t11 == t22) || (t11 == t23);
  bool b2 = (t12 == t20) || (t12 == t21) || (t12 == t22) || (t12 == t23);
  bool b3 = (t13 == t20) || (t13 == t21) || (t13 == t22) || (t13 == t23);

  if(b0+b1+b2+b3 < 3){
    return -1;
  } else{
    int v1[4]    = {t10, t11, t12, t13};
    int v1cpy[4] = {t10, t11, t12, t13};
    int v2[4]    = {t20, t21, t22, t23};
    sort4(v1);
    sort4(v2);
    t10 = v1[0]; t11 = v1[1]; t12 = v1[2]; t13 = v1[3];
    t20 = v2[0]; t21 = v2[1]; t22 = v2[2]; t23 = v2[3];

    bool b00 = (t11==t21) && (t12==t22) && (t13==t23);
    bool b01 = (t11==t20) && (t12==t22) && (t13==t23);
    bool b02 = (t11==t20) && (t12==t21) && (t13==t23);
    bool b03 = (t11==t20) && (t12==t21) && (t13==t22);

    bool b10 = (t10==t21) && (t12==t22) && (t13==t23);
    bool b11 = (t10==t20) && (t12==t22) && (t13==t23);
    bool b12 = (t10==t20) && (t12==t21) && (t13==t23);
    bool b13 = (t10==t20) && (t12==t21) && (t13==t22);

    bool b20 = (t10==t21) && (t11==t22) && (t12==t23);
    bool b21 = (t10==t20) && (t11==t22) && (t12==t23);
    bool b22 = (t10==t20) && (t11==t21) && (t12==t23);
    bool b23 = (t10==t20) && (t11==t21) && (t12==t22);

    bool b30 = (t10==t21) && (t11==t22) && (t13==t23);
    bool b31 = (t10==t20) && (t11==t22) && (t13==t23);
    bool b32 = (t10==t20) && (t11==t21) && (t13==t23);
    bool b33 = (t10==t20) && (t11==t21) && (t13==t22);

    int missing = -1; // The vertex that is missing from the common face
    if      (b00 || b01 || b02 || b03) missing = 0; //return 3;
    else if (b10 || b11 || b12 || b13) missing = 1; //return 2;
    else if (b20 || b21 || b22 || b23) missing = 3; //return 0;
    else if (b30 || b31 || b32 || b33) missing = 2; //return 1;

    if(missing >= 0){
      if      (v1cpy[0] == v1[missing]) return 3;
      else if (v1cpy[1] == v1[missing]) return 2;
      else if (v1cpy[2] == v1[missing]) return 1;
      else if (v1cpy[3] == v1[missing]) return 0;
    }

    return -1;
  }
}

// Only used to draw facets of the medial axis
static bool sortClockwise(SPoint3 a, SPoint3 b, SPoint3 center, SVector3 normal){
  // If dot(n, cross(A-C, B-C)) is positive, B is counterclockwise from A; if it's negative, B is clockwise from A.
  SVector3 tmp = crossprod(SVector3(center,a),SVector3(center,b));
  return dot(normal, tmp) <= 0;
}

// Computes the medial axis of the geometry and assign the feature size at vertices
HXTStatus featureSize(Forest* forest){

  HXTMesh *mesh     = forest->forestOptions->mesh;
  int nLayersPerGap = forest->forestOptions->nodePerGap;
  double hmin       = forest->forestOptions->hmin;
  double hmax       = forest->forestOptions->hmax;

  std::vector<MVertex*> allVertices;
  std::vector<double> sizeAtVertices(mesh->vertices.num, DBL_MAX);
  for(size_t i = 0; i < mesh->vertices.num; ++i){
    allVertices.push_back(new MVertex(mesh->vertices.coord[4*i+0],
                                      mesh->vertices.coord[4*i+1],
                                      mesh->vertices.coord[4*i+2]));
  }

  int firstVertex = allVertices[0]->getNum();

  // All tets
  uint64_t count = 0;
  std::vector<MTetrahedron*> allTets;
  std::vector<std::vector<uint64_t>> tetIncidents;
  std::vector<std::vector<MEdge>> edgIncidents;
  for(uint32_t i = 0; i < mesh->vertices.num; ++i){
    std::vector<uint64_t> vTet;
    tetIncidents.push_back(vTet);
    std::vector<MEdge> vEdg;
    edgIncidents.push_back(vEdg);
  }

  for(size_t i = 0; i < mesh->tetrahedra.num; ++i){
    if(mesh->tetrahedra.node[4*i+3] != HXT_GHOST_VERTEX){
      allTets.push_back(new MTetrahedron(allVertices[ mesh->tetrahedra.node[4*i+0] ],
                                         allVertices[ mesh->tetrahedra.node[4*i+1] ],
                                         allVertices[ mesh->tetrahedra.node[4*i+2] ],
                                         allVertices[ mesh->tetrahedra.node[4*i+3] ]) );

      for(size_t j = 0; j < 4; ++j){
        tetIncidents[ mesh->tetrahedra.node[4*i+j] ].push_back(count);
      }
      for(size_t j = 0; j < 6; ++j){
        MEdge e = allTets[count]->getEdge(j);
        edgIncidents[ allTets[count]->getEdge(j).getVertex(0)->getNum() - firstVertex ].push_back(e);
        edgIncidents[ allTets[count]->getEdge(j).getVertex(1)->getNum() - firstVertex ].push_back(e);
      }
      ++count;
    }
  }

  std::set<MEdge,MEdgeLessThan> axis;
  int elemDrawn = 0;
 
  FILE* file = fopen("medialAxis.pos", "w");
  if(file==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  bool draw = true;
  if(draw){
    fprintf(file, "View \"medialAxis\" {\n");
  }

  int indFace;

  for(size_t i = 0; i < mesh->vertices.num; ++i){
    // Pôle de p : circumcenter le plus loin parmi les tets incidents à p
    SPoint3 pole(0.,0.,0.),
             tmp(0.,0.,0.),
               p(mesh->vertices.coord[4*i+0], mesh->vertices.coord[4*i+1], mesh->vertices.coord[4*i+2]);
    double d = 0.;

    for(size_t j = 0; j < tetIncidents[i].size(); ++j){
      tmp = allTets[ tetIncidents[i][j] ]->circumcenter();
      if(p.distance(tmp) > d) pole = tmp;
      d = fmax(d, p.distance(tmp));
    }

    // Pole vector
    SPoint3 vp = pole - p;
    double D = -(vp[0]*p[0] + vp[1]*p[1] + vp[2]*p[2]);
    SPoint3 p1(0., 0., -D/vp[2]); // 2 points sur le plan qui passe par p et de normale vp
    SPoint3 p2(0., -D/vp[1], 0.);

    std::vector<MFace> up; // umbrella
    // Boucle sur les voronoi edges (paires de centres)
    double orientj, orientk;
    for(size_t j = 0; j < tetIncidents[i].size(); ++j){
      uint64_t tetj = tetIncidents[i][j];
      SPoint3 cj = allTets[tetj]->circumcenter();  
      for(size_t k = j; k < tetIncidents[i].size(); ++k){
        uint64_t tetk = tetIncidents[i][k];
        if( tetj != tetk ){
          indFace = commonFaceTetFast(allTets[tetj], allTets[tetk]);
          if(indFace >= 0){
            SPoint3 ck = allTets[tetk]->circumcenter();
            orientj = robustPredicates::orient3d((double*) p, (double*) p1, (double*) p2, (double*) cj);
            orientk = robustPredicates::orient3d((double*) p, (double*) p1, (double*) p2, (double*) ck);
            if(orientj*orientk < 0){
              up.push_back(allTets[tetj]->getFace(indFace));
              // break; ?
            }
          } 
        }
      }
    }

    double theta = M_PI/8., rho = 8., maxAngle, minRatio, localAngle, alpha0, alpha1;
    std::vector<MEdge> checkedEdges;
    bool checked;
    for(size_t j = 0; j < edgIncidents[i].size(); ++j){ // boucler sur les aretes incidentes à p

      MEdge e = edgIncidents[i][j];
      checked = false;
      for(size_t k = 0; k < checkedEdges.size(); ++k){
        if(e == checkedEdges[k]){
          checked = true;
          break;
        }
      }

      if(checked){ continue; }
      else{ checkedEdges.push_back(e); }

      maxAngle = 0.0;
      minRatio = DBL_MAX;

      uint32_t v0 = e.getVertex(0)->getNum() - firstVertex;
      uint32_t v1 = e.getVertex(1)->getNum() - firstVertex;
      if(v0 == i || v1 == i){
        for(size_t l = 0; l < up.size(); ++l){
          // Angle condition
          localAngle = angle( e.tangent(), up[l].normal() );
          localAngle = fmin(localAngle, fabs(M_PI - localAngle));
          maxAngle = fmax(maxAngle, localAngle);

          // Ratio condition
          MTriangle tri(up[l].getVertex(0),up[l].getVertex(1),up[l].getVertex(2));
          minRatio = fmin(minRatio, e.length() / tri.getOuterRadius());
        }

        if(maxAngle < M_PI/2. - theta || minRatio > rho){
          double *n0 = forest->forestOptions->nodeNormals + 3*v0;
          double *n1 = forest->forestOptions->nodeNormals + 3*v1;
          alpha0 = angle(SVector3(n0), e.tangent());
          alpha1 = angle(SVector3(n1), e.tangent());

          if( fmin(alpha0, fabs(M_PI-alpha0)) < M_PI/8. && fmin(alpha1, fabs(M_PI-alpha1)) < M_PI/8.){
            // Add edge to the set (axis, though actually unused), modifiy size at its extrmities and draw the dual facet
            std::pair<std::set<MEdge, MEdgeLessThan>::iterator,bool> ret = axis.insert(e);

            if(ret.second){
              double h = e.length()/nLayersPerGap;
              h = fmax(h, hmin);
              h = fmin(h, hmax);
              sizeAtVertices[ v0 ] = fmin(h, sizeAtVertices[ v0 ]);
              sizeAtVertices[ v1 ] = fmin(h, sizeAtVertices[ v1 ]);

              if(draw){
                // Turning around the edge to draw the facet
                std::vector<SPoint3> centers;
                for(size_t jj = 0; jj < tetIncidents[i].size(); ++jj){
                  uint64_t tetj = tetIncidents[i][jj];
                  for(size_t b = 0; b < 6; ++b){
                    if(allTets[tetj]->getEdge(b) == e) centers.push_back(allTets[tetj]->circumcenter());
                  }
                }
                if(centers.size() > 2){
                  // Center of the face
                  SPoint3 c(0.,0.,0.);
                  for(size_t a = 0; a < centers.size(); ++a){
                    c += centers[a];
                  }
                  c /= centers.size();
                  SVector3 normal = crossprod(SVector3(c,centers[0]),SVector3(c,centers[1]));
                  normal.normalize();
                  // Sort clockwise around center
                  sort(centers.begin(), centers.end(), [c,normal](SPoint3 a, SPoint3 b) { return sortClockwise(a,b,c,normal); });
                  // Draw
                  for(size_t a = 1; a < centers.size()-1; ++a){
                    fprintf(file, "ST(%f,%f,%f, %f,%f,%f, %f,%f,%f){%d,%d,%d};\n",
                      centers[0][0],centers[0][1],centers[0][2],
                      centers[a][0],centers[a][1],centers[a][2],
                      centers[a+1][0],centers[a+1][1],centers[a+1][2],
                      1,1,1);
                  }
                  fprintf(file, "ST(%f,%f,%f, %f,%f,%f, %f,%f,%f){%d,%d,%d};\n",
                      centers[0][0],centers[0][1],centers[0][2],
                      centers[centers.size()-1][0],centers[centers.size()-1][1],centers[centers.size()-1][2],
                      centers[1][0],centers[1][1],centers[1][2],
                      1,1,1);
                  ++elemDrawn;
                } 
              }
            } // if edge was inserted
          } // if edges does not have a too large angle with normals to its extremities
        } // if edge passes conditions
      } // if i is an edge vertex
    } // for incident edges
  } // for vertices.num

  if(draw){
    fprintf(file, "};");
    fclose(file);
  }

  // Assign feature size in the octree cells
  sc_array_t *points = sc_array_new_size(sizeof(size_point_t), mesh->vertices.num);
  size_point_t *p_tmp;
  for(size_t i = 0; i < mesh->vertices.num; ++i){
    p_tmp = (size_point_t *) sc_array_index(points, i);
    p_tmp->x = mesh->vertices.coord[(size_t) 4*i+0];
    p_tmp->y = mesh->vertices.coord[(size_t) 4*i+1];
    p_tmp->z = mesh->vertices.coord[(size_t) 4*i+2];
    p_tmp->size = sizeAtVertices[i];
  }
  p4est_search(forest->p4est, NULL, replace, points);

  return HXT_STATUS_OK;

}

/* ========================================================================================================
   ESTIMATE NUMBER OF TETRAHEDRA IN THE VOLUME MESH
   ======================================================================================================== */

static void elementEstimate(p4est_iter_volume_info_t * info, void *user_data){
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

HXTStatus hxtOctreeElementEstimation(Forest *forest, double *elemEstimate){
  p4est_iterate (forest->p4est, NULL, (void *) elemEstimate, elementEstimate, NULL, NULL, NULL);
  return HXT_STATUS_OK;
}

/* ========================================================================================================
   EXPORT
   ======================================================================================================== */

HXTStatus saveGlobalData(Forest *forest, const char *filename){
  FILE* f = fopen(filename, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);
  fprintf(f, "%f %f\n", forest->forestOptions->hmin, forest->forestOptions->hmax);
  fclose(f);
  Msg::Info("Saved global size field data to %s", filename);
  return HXT_STATUS_OK;
}

static void exportToHexCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;
  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

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

static void exportToQuadCallback(p4est_iter_volume_info_t * info, void *user_data){
  p4est_quadrant_t   *q = info->quad;
  size_data_t        *data = (size_data_t *) q->p.user_data;

  p4est_t            *p4est = info->p4est;
  p4est_topidx_t      which_tree = info->treeid;

  FILE* f = (FILE*) user_data;

  double center[3], x[8], y[8], z[8];
  getCellCenter(p4est, which_tree, q, center);

  double h = data->h/2.0, s = data->size, epsilon = 1e-12;
  x[0] = x[3] = center[0]-h - epsilon;
  x[1] = x[2] = center[0]+h + epsilon;
  y[0] = y[1] = center[1]-h - epsilon;
  y[2] = y[3] = center[1]+h + epsilon;
  z[0] = z[1] = 0.0;
  z[2] = z[3] = 0.0;
  
  fprintf(f, "SQ(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f};\n", 
    x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3],
    s, s, s, s);
}

HXTStatus forestExport(Forest *forest, const char *forestFile){
  FILE* f = fopen(forestFile, "w");
  if(f==NULL) return HXT_ERROR(HXT_STATUS_FILE_CANNOT_BE_OPENED);

  fprintf(f, "View \"sizeField\" {\n");
  if      (forest->forestOptions->dim == 3){ p4est_iterate(forest->p4est, NULL, (void*) f, exportToHexCallback, NULL, NULL, NULL);  }
  else if (forest->forestOptions->dim == 2){ p4est_iterate(forest->p4est, NULL, (void*) f, exportToQuadCallback, NULL, NULL, NULL); }
  fprintf(f, "};");
  fclose(f);
  return HXT_STATUS_OK;
}

HXTStatus forestSave(Forest *forest, const char *forestFile, const char *dataFile){
  HXT_CHECK( saveGlobalData(forest, dataFile) );
  p4est_save_ext(forestFile, forest->p4est, true, false);
  return HXT_STATUS_OK;
}

#endif

/* ======================================================================================
   End functions from hxt_octree
   ====================================================================================== */

double automaticMeshSizeField::operator()(double X, double Y, double Z, GEntity *ge) {  
  double val = 1.e17;
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = forestSearchOne(forest, X, Y, Z, &val, true);
  if (s == HXT_STATUS_OK){
    return val;
  }
  else Msg::Error ("Cannot find point %g %g %g in the octree",X,Y,Z);
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST for using automaticMeshSizeField");
#endif
  return val;
}

automaticMeshSizeField::~automaticMeshSizeField(){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  if (forest) forestDelete(&forest);
  if (forestOptions) forestOptionsDelete(&forestOptions);
#endif
}

#if defined(HAVE_HXT) && defined(HAVE_P4EST)
HXTStatus automaticMeshSizeField::updateHXT(){

  if(!update_needed)
    return HXT_STATUS_OK;
  
  if (forestOptions) HXT_CHECK(forestOptionsDelete(&forestOptions));
  if (forest)        HXT_CHECK(forestDelete(&forest));  

  update_needed = false;

  if(!_forestFile.empty()){
    // Load .p4est file if given a valid file name
    Msg::Info("Loading size field from %s", _forestFile.c_str());
    HXT_CHECK(forestOptionsCreate(&forestOptions));
    size_t lastindex = _forestFile.find_last_of("."); 
    std::string root = _forestFile.substr(0, lastindex); 
    std::string forestFile = root + ".p4est";
    std::string dataFile   = root + ".data";
    HXT_CHECK( forestLoad(&forest, forestFile.c_str(), dataFile.c_str(), forestOptions) );
  } else{
    // Compute the size field otherwise
    int dim = GModel::current()->getDim();

    HXT_CHECK(forestOptionsCreate(&forestOptions));
  
    Msg::Info("Gradation = %f\n", _gradation);
    Msg::Info("Node density = %d\n", _nPointsPerCircle);
    if(dim == 3){
      if(_nPointsPerGap > 0){
        Msg::Info("Layers per gap = %d\n", _nPointsPerGap); }
      else{ 
        Msg::Info("Layers per gap = %d : not detecting features.\n", _nPointsPerGap);}
    }

    // The bounding box of the mesh/model
    double bbox_vertices[6];

    RTree<uint64_t, double, 3> triRTree;
    HXTMesh *mesh;
    double *nodalCurvature;
    double *nodeNormals;
    std::vector<std::function<double(double)>> curvFunctions;
    std::vector<std::function<double(double)>> xFunctions;
    std::vector<std::function<double(double)>> yFunctions;

    int debug = true;

    GModel* gm = GModel::current();

    size_t numVertices = gm->getNumMeshVertices();
    HXT_CHECK(hxtMalloc(&nodalCurvature,6*numVertices*sizeof(double))); 
    for(size_t i = 0; i < 6*numVertices; ++i){ nodalCurvature[i] = NAN; }

    if(dim == 3){
      // Get all faces of the model
      std::vector<GFace*> faces;
      std::vector<GRegion*> regions;
      for(std::set<GRegion*, GEntityPtrLessThan>::iterator it = GModel::current()->firstRegion(); it != GModel::current()->lastRegion(); ++it){
        regions.push_back(*it);
      }
      if(!regions.empty()){
        HXT_CHECK( getAllFacesOfAllRegions(regions, NULL, faces) );
      } else{
        Msg::Info("No volume in the model : looping over faces instead.");
        for(std::set<GFace*, GEntityPtrLessThan>::iterator it = GModel::current()->firstFace(); it != GModel::current()->lastFace(); ++it){
          faces.push_back(*it);
        }
      }

      // Create global HXT mesh structure
      HXT_CHECK(hxtMeshCreate(&mesh));
      std::map<MVertex *, uint32_t> v2c;
      std::vector<MVertex *> c2v;  
      Gmsh2Hxt(faces, mesh, v2c, c2v);

      if(mesh->vertices.num == 0){
        Msg::Error("Surface mesh is empty");
        HXT_CHECK(hxtMeshDelete(&mesh));
        Msg::Exit(1);
      }

      // HXT_CHECK(hxtMalloc(&nodalCurvature,6*mesh->vertices.num*sizeof(double))); 
      // for(uint64_t i = 0; i < 6*mesh->vertices.num; ++i){ nodalCurvature[i] = NAN; printf("%d\n",i);}

      // Create HXT mesh structure for each GFace
      std::vector<HXTMesh *> faceMeshes;
      for(size_t i = 0; i < faces.size(); ++i){
        HXTMesh *meshFace;
        HXT_CHECK(hxtMeshCreate(&meshFace));
        std::vector<GFace*> oneFace;
        oneFace.push_back(faces[i]);
        std::map<MVertex *, uint32_t> v2cLoc;
        std::vector<MVertex *> c2vLoc;  
        Gmsh2HxtLocal(oneFace, meshFace, v2cLoc, c2vLoc);
        faceMeshes.push_back(meshFace);
      }

      std::map<MVertex *, uint32_t> v2c2;
      std::vector<MVertex *> c2v2;  
      Gmsh2HxtGlobal(faces, NULL, v2c2, c2v2);

      size_t nVertices = 0;

      assert(faces.size() == faceMeshes.size());

      bool usenewcurvature = true;
      // Compute curvature on the faces
      // for(size_t j = 0; j < faces.size(); j++) {
      int counter = 0;
      for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
        // HXTMesh *meshFace = faceMeshes[j];
        HXTMesh *meshFace = faceMeshes[counter++];

        if(meshFace==NULL){
          Msg::Error("meshFace == NULL");
        }

        GFace *gf = *it;
        std::map<MVertex *, int> nodeIndex;
        std::vector<SPoint3> nodes;
        std::vector<int> tris;
        std::vector<std::pair<SVector3, SVector3> > curv;
        for(std::size_t i = 0; i < gf->triangles.size(); i++) {
          MTriangle *t = gf->triangles[i];
          for(int j = 0; j < 3; j++) {
            MVertex *v = t->getVertex(j);
            if(nodeIndex.find(v) == nodeIndex.end()) {
              int idx = nodes.size();
              nodeIndex[v] = idx;
              nodes.push_back(v->point());
              tris.push_back(idx);
            }
            else {
              tris.push_back(nodeIndex[v]);
            }
          }
        }

        for(size_t i = 0; i < meshFace->vertices.num; ++i){
          nodes[i] = SPoint3(meshFace->vertices.coord[(size_t) 4*i+0],
                             meshFace->vertices.coord[(size_t) 4*i+1],
                             meshFace->vertices.coord[(size_t) 4*i+2]);
          // nodes[i] = gm->getMeshVertexByTag(i)
        }

        for(size_t i = 0; i < meshFace->triangles.num; ++i){
          tris[3*i+0] = meshFace->triangles.node[3*i+0];
          tris[3*i+1] = meshFace->triangles.node[3*i+1];
          tris[3*i+2] = meshFace->triangles.node[3*i+2];
        }

        if(gf->triangles.empty()){
          Msg::Info("Skipping curvature computation on face %d with 0 element", counter-1);
        } else{
          double   *curvatureCrossfieldFace;
          double   *nodalCurvatureFace;
          HXTEdges *edgesFace;
          HXT_CHECK(hxtEdgesCreate(meshFace,&edgesFace));
          if(usenewcurvature){
            CurvatureRusinkiewicz(tris, nodes, curv);
          } else{
            HXT_CHECK(hxtCurvatureRusinkiewicz(meshFace,&nodalCurvatureFace,&curvatureCrossfieldFace,edgesFace,debug));
          }

          debug = false;
          if(debug){

            for(uint64_t i = 0; i < meshFace->vertices.num; ++i){
              double norme, v1[3];
              v1[0] = nodalCurvatureFace[6*i];
              v1[1] = nodalCurvatureFace[6*i+1];
              v1[2] = nodalCurvatureFace[6*i+2];
              norme2(v1, &norme);
              if(norme > 100){
                // printf("%u vertices on face %lu \n", meshFace->vertices.num, j);
                printf(" v1 = %f \t %f \t %f - norme = %f\n", 
                  nodalCurvatureFace[6*i],
                  nodalCurvatureFace[6*i+1],
                  nodalCurvatureFace[6*i+2],
                  norme);
                nodalCurvatureFace[6*i]   = 100.0;
                nodalCurvatureFace[6*i+1] = 0.0;
                nodalCurvatureFace[6*i+2] = 0.0;
              }
              double v2[3];
              v2[0] = nodalCurvatureFace[6*i+3];
              v2[1] = nodalCurvatureFace[6*i+4];
              v2[2] = nodalCurvatureFace[6*i+5];
              norme2(v2, &norme);
              if(norme > 100){
                // printf("%u vertices on face %lu \n", meshFace->vertices.num, j);
                printf(" v2 = %f \t %f \t %f - norme = %f\n\n", 
                  nodalCurvatureFace[6*i+3],
                  nodalCurvatureFace[6*i+4],
                  nodalCurvatureFace[6*i+5],
                  norme);
                nodalCurvatureFace[6*i+3] = 100.0;
                nodalCurvatureFace[6*i+4] = 0.0;
                nodalCurvatureFace[6*i+5] = 0.0;
              }
            }
          }

          debug = true;
          // Assemble curvature vectors on the face in global nodalCurvature structure
          for (uint64_t i = 0; i<meshFace->vertices.num; ++i){
            uint64_t nodeGlobal = v2c[ c2v2[nVertices+i] ];
            if(debug){
              double x1,y1,z1,x2,y2,z2;
              x1 = meshFace->vertices.coord[(size_t) 4*i+0];
              y1 = meshFace->vertices.coord[(size_t) 4*i+1];
              z1 = meshFace->vertices.coord[(size_t) 4*i+2];
              x2 = mesh->vertices.coord[(size_t) 4*nodeGlobal+0];
              y2 = mesh->vertices.coord[(size_t) 4*nodeGlobal+1];
              z2 = mesh->vertices.coord[(size_t) 4*nodeGlobal+2];
              if(!isPoint(x1,y1,z1,x2,y2,z2,1e-12)){
                printf("Mismatch : (%10.12e,%10.12e,%10.12e) - (%10.12e,%10.12e,%10.12e)\n",x1,y1,z1,x2,y2,z2);
              }
              assert(isPoint(x1,y1,z1,x2,y2,z2,1e-15));
            }

            if(usenewcurvature){
              nodalCurvature[6 * nodeGlobal + 0] = curv[i].first[0];
              nodalCurvature[6 * nodeGlobal + 1] = curv[i].first[1];
              nodalCurvature[6 * nodeGlobal + 2] = curv[i].first[2];
              nodalCurvature[6 * nodeGlobal + 3] = curv[i].second[0];
              nodalCurvature[6 * nodeGlobal + 4] = curv[i].second[1];
              nodalCurvature[6 * nodeGlobal + 5] = curv[i].second[2]; 
            } else{
              nodalCurvature[6 * nodeGlobal + 0] = nodalCurvatureFace[6 * i + 0];
              nodalCurvature[6 * nodeGlobal + 1] = nodalCurvatureFace[6 * i + 1];
              nodalCurvature[6 * nodeGlobal + 2] = nodalCurvatureFace[6 * i + 2];
              nodalCurvature[6 * nodeGlobal + 3] = nodalCurvatureFace[6 * i + 3];
              nodalCurvature[6 * nodeGlobal + 4] = nodalCurvatureFace[6 * i + 4];
              nodalCurvature[6 * nodeGlobal + 5] = nodalCurvatureFace[6 * i + 5]; 
            }
          }

          nVertices += meshFace->vertices.num;

          // HXT_CHECK(hxtEdgesDelete(&edgesFace)       );
          if(!usenewcurvature){
            HXT_CHECK(hxtFree(&curvatureCrossfieldFace));
            HXT_CHECK(hxtFree(&nodalCurvatureFace)     );
          }
        }
      } // for faces.size()

      debug = true;
      if(usenewcurvature){
        if(debug) writeNodalCurvature(nodalCurvature, mesh->vertices.num, "nodalCurvature2.txt");
      }else{
        if(debug) writeNodalCurvature(nodalCurvature, mesh->vertices.num, "nodalCurvature.txt");
      }

      // Delaunay
      HXTDelaunayOptions delaunayOptions = {NULL, NULL, 0, 0, 0, 2, 1, 0};
      HXT_CHECK(hxtEmptyMesh(mesh, &delaunayOptions));
      for(size_t i = 0; i < mesh->tetrahedra.num; ++i){
        mesh->tetrahedra.colors[i] = 0;
      }

      HXT_CHECK(hxtCurvatureNormals(mesh, &nodeNormals, 0));

      // Add bboxes of the surface mesh to rtree
      // RTree<uint64_t, double, 3> triRTree;
      HXTBbox bbox_triangle;
      for(uint64_t i = 0; i < mesh->triangles.num; ++i){
        hxtBboxInit(&bbox_triangle);
        for(uint64_t j = 0; j < 3; ++j){
          double coord[3];
          uint32_t node = mesh->triangles.node[3*i+j];
          for(uint32_t k = 0; k < 3; ++k){ coord[k] = mesh->vertices.coord[(size_t) 4*node+k]; }
          hxtBboxAddOne(&bbox_triangle, coord);
        }
        SBoundingBox3d cube_bbox(bbox_triangle.min[0], bbox_triangle.min[1], bbox_triangle.min[2],
                                 bbox_triangle.max[0], bbox_triangle.max[1], bbox_triangle.max[2]);
        // cube_bbox.makeCube();
        triRTree.Insert((double*)(cube_bbox.min()), (double*)(cube_bbox.max()), i);
      }

      // Compute bbox of the mesh
      HXTBbox bbox_mesh;
      hxtBboxInit(&bbox_mesh);
      hxtBboxAdd(&bbox_mesh, mesh->vertices.coord, mesh->vertices.num);
      for(int i = 0; i < 3; ++i){
        bbox_vertices[i  ] = bbox_mesh.min[i];
        bbox_vertices[i+3] = bbox_mesh.max[i];
      }

      // Export RTree in .pos file
      bool exportRTree = false;
      if(exportRTree){
        RTree<uint64_t, double, 3>::Iterator it;
        FILE* f = fopen("rtree.pos", "w");
        fprintf(f, "View \"sizeField\" {\n");
        int itIndex = 0;
        double s = 1.0;
        double x[8], y[8], z[8];
        // Using custom GetNext2 to display intermediary rectangles
        for( triRTree.GetFirst(it); !triRTree.IsNull(it); triRTree.GetNext2(it) )
        {
          int value = triRTree.GetAt(it);
          double boundsMin[3] = {0,0,0};
          double boundsMax[3] = {0,0,0};
          it.GetBounds(boundsMin, boundsMax);
          std::cout << "it[" << itIndex++ << "] " << value << " = (" << boundsMin[0] << "," << boundsMin[1] << "," << boundsMin[2] << "," << boundsMax[0] << "," << boundsMax[1] << "," << boundsMax[2] << ")\n";
          x[0] = x[3] = x[4] = x[7] = boundsMin[0];
          x[1] = x[2] = x[5] = x[6] = boundsMax[0];
          y[0] = y[1] = y[4] = y[5] = boundsMin[1];
          y[2] = y[3] = y[6] = y[7] = boundsMax[1];
          z[0] = z[1] = z[2] = z[3] = boundsMin[2];
          z[4] = z[5] = z[6] = z[7] = boundsMax[2];
          fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n", 
            x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3], 
            x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7], 
            s, s, s, s, s, s, s, s);
        }
        // Adding the root rectangle (the bbox)
        x[0] = x[3] = x[4] = x[7] = bbox_mesh.min[0];
        x[1] = x[2] = x[5] = x[6] = bbox_mesh.max[0];
        y[0] = y[1] = y[4] = y[5] = bbox_mesh.min[1];
        y[2] = y[3] = y[6] = y[7] = bbox_mesh.max[1];
        z[0] = z[1] = z[2] = z[3] = bbox_mesh.min[2];
        z[4] = z[5] = z[6] = z[7] = bbox_mesh.max[2];
        fprintf(f, "SH(%f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f, %f,%f,%f){%f,%f,%f,%f,%f,%f,%f,%f};\n", 
            x[0], y[0], z[0], x[1], y[1], z[1], x[2], y[2], z[2], x[3], y[3], z[3], 
            x[4], y[4], z[4], x[5], y[5], z[5], x[6], y[6], z[6], x[7], y[7], z[7], 
            s, s, s, s, s, s, s, s);
        fprintf(f, "};");
        fclose(f);
      }
    }

    if(dim == 2){
      SBoundingBox3d bbox = GModel::current()->bounds();
      for(int i = 0; i < 3; ++i){
        bbox_vertices[i  ] = bbox.min()[i];
        bbox_vertices[i+3] = bbox.max()[i];
      }

      mesh = NULL;
      // nodalCurvature = NULL;
      nodeNormals = NULL;

      for(std::set<GEdge*, GEntityPtrLessThan>::iterator it = GModel::current()->firstEdge(); it != GModel::current()->lastEdge(); ++it){
        GEdge *e = *it;
        curvFunctions.push_back([e](double par){ return e->curvature(par); });
        xFunctions.push_back([e](double par){ return e->point(par).x(); });
        yFunctions.push_back([e](double par){ return e->point(par).y(); });
      }

      forestOptions->curvFunctions = &curvFunctions;
      forestOptions->xFunctions = &xFunctions;
      forestOptions->yFunctions = &yFunctions;

      printf("test : %f\n", (*forestOptions->xFunctions)[0](0.2));
      printf("test : %f\n", (*forestOptions->yFunctions)[0](0.2));
    }

    // Set the bulk size and the min size from the bbox
    if(_hbulk < 0 || _hmin < 0){
      double L = -1.0;
      for(int i = 0; i < 3; ++i){
        L = fmax(L, bbox_vertices[i+3] - bbox_vertices[i] );
      }
      _hbulk < 0 ? _hbulk = L/20.   : _hbulk;
      _hmin  < 0 ? _hmin  = L/1000. : _hmin;
      Msg::Info("Bulk size is set to %f", _hbulk);
      Msg::Info("Min  size is set to %f", _hmin);
    }

    if(_hmax < 0)
      _hmax = _hbulk;

    forestOptions->dim = dim;
    forestOptions->hmax = _hmax;  
    forestOptions->hmin = _hmin;
    forestOptions->hbulk = _hbulk;  
    forestOptions->gradation = _gradation;
    forestOptions->nodePerTwoPi = _nPointsPerCircle;
    forestOptions->nodePerGap = _nPointsPerGap;
    forestOptions->bbox = bbox_vertices;
    forestOptions->sizeFunction = NULL;
    forestOptions->nodalCurvature = nodalCurvature;
    forestOptions->nodeNormals = nodeNormals;
    forestOptions->triRTree = (dim == 3) ? &triRTree : NULL;
    forestOptions->mesh = mesh;

    HXT_CHECK(forestCreate(0, NULL, &forest, NULL, forestOptions));

    if(dim == 3){
      if(_nPointsPerCircle > 0){
        Msg::Info("Refining octree...");
        HXT_CHECK(forestRefine(forest));
      }
      
      if(_nPointsPerGap > 0){
        Msg::Info("Detecting features...");
        HXT_CHECK(featureSize(forest));
      }

      if(_smoothing){
        Msg::Info("Smoothing size gradient...");
        HXT_CHECK(forestSizeSmoothing(forest));
      }

      double elemEstimation;
      HXT_CHECK(hxtOctreeElementEstimation(forest, &elemEstimation));
      Msg::Info("Estimated number of tetrahedra in the bounding box : %ld", (uint64_t) ceil(elemEstimation));
    }
    else{
      HXT_CHECK(forestRefine(forest));
      if(_smoothing){
        Msg::Info("Smoothing size gradient..."); 
        HXT_CHECK( forestSizeSmoothing(forest));
      }
    }

    // Save forest in .p4est file
    std::string forestFile = GModel::current()->getName() + ".p4est";
    std::string dataFile   = GModel::current()->getName() + ".data";
    Msg::Info("Saving size field in %s", forestFile.c_str());
    HXT_CHECK(forestSave(forest, forestFile.c_str(), dataFile.c_str()));

    debug = false;
    if(debug){
      // Export size field in .pos file
      forestFile = GModel::current()->getName() + ".pos";
      HXT_CHECK(forestExport(forest, forestFile.c_str()));
    }

    if(dim == 3){
      if(nodalCurvature) HXT_CHECK(hxtFree(&nodalCurvature));
      if(nodeNormals)    HXT_CHECK(hxtFree(&nodeNormals));
      HXT_CHECK(hxtMeshDelete(&mesh));
    }
  }

  return HXT_STATUS_OK;
}

#endif

void automaticMeshSizeField::update(){
#if defined(HAVE_HXT) && defined(HAVE_P4EST)
  HXTStatus s = updateHXT();
  if (s != HXT_STATUS_OK) Msg::Error ("Something went wrong when computing the octree");
#else
  Msg::Error ("Gmsh has to be compiled with HXT and P4EST to use automaticMeshSizeField");
#endif
};

