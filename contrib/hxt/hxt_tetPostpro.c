#include "predicates.h"
#include "hxt_tetPostpro.h"
#include "hxt_tetFlag.h"
#include "hxt_tetUtils.h"
#include "hxt_vertices.h"


static void verticesPlaneOrient(HXTMesh* mesh, double* __restrict__ p0, double* __restrict__ p1, double* __restrict__ p2){
  #pragma omp parallel for
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    mesh->vertices.coord[4*i+3] = orient3d(p0, p1, p2, mesh->vertices.coord + 4*i);
  }
}

/** keep only tetrahedra whose intersection with a plane is not empty.
The plane is defined by 3 points. */
HXTStatus hxtTetPlaneIntersection(HXTMesh* mesh, double* p0, double* p1, double* p2){
  verticesPlaneOrient(mesh, p0, p1, p2);

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[4*i+3] == HXT_GHOST_VERTEX) {
      setDeletedFlag(mesh, i);
    }
    else {
      double firstOrient = mesh->vertices.coord[4*mesh->tetrahedra.node[4*i]+3];
      for (int j=1; j<4; j++) {
        double secondOrient = mesh->vertices.coord[4*mesh->tetrahedra.node[4*i+j]+3];
        if(firstOrient*secondOrient<=0.0){
          firstOrient = 0.0;
          break;
        }
      }

      if(firstOrient!=0.0)
        setDeletedFlag(mesh, i);
    }
  }

  HXT_CHECK( hxtRemoveDeleted(mesh) );

  return HXT_STATUS_OK;
}

/** keep only tetrahedra with at least two vertices on the positive side of the plane {p0,p1,p2}.
(p is on the positive side <=> orient3d(p0,p1,p2, p) > 0)
When seen from the negative side, p0,p1,p2 is counter-clockwise  */
HXTStatus hxtTetPlaneOrient(HXTMesh* mesh, double* p0, double* p1, double* p2){
  verticesPlaneOrient(mesh, p0, p1, p2);

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.node[4*i+3] == HXT_GHOST_VERTEX) {
      setDeletedFlag(mesh, i);
    }
    else {
      for (int j=0; j<4; j++) {
        if(mesh->vertices.coord[4*mesh->tetrahedra.node[4*i+j]+3]<0.0){
          setDeletedFlag(mesh, i);
          break;
        }
      }
    }
  }

  HXT_CHECK( hxtRemoveDeleted(mesh) );

  return HXT_STATUS_OK;
}


/** keep only vertices that are either in the surface mesh or in the tetrahedra mesh */
HXTStatus hxtFilterVertices(HXTMesh* mesh, double* nodalSizes){
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  #pragma omp parallel for
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    vertices[i].padding.status = HXT_STATUS_FALSE;
  }

  if(mesh->tetrahedra.node!=NULL){
    #pragma omp parallel for
    for (uint32_t i=0; i<mesh->tetrahedra.num; i++) {
      vertices[mesh->tetrahedra.node[4*i+0]].padding.status = HXT_STATUS_TRUE;
      vertices[mesh->tetrahedra.node[4*i+1]].padding.status = HXT_STATUS_TRUE;
      vertices[mesh->tetrahedra.node[4*i+2]].padding.status = HXT_STATUS_TRUE;
      vertices[mesh->tetrahedra.node[4*i+3]].padding.status = HXT_STATUS_TRUE;
    }
  }

  if(mesh->triangles.node!=NULL){
    #pragma omp parallel for
    for (uint32_t i=0; i<mesh->triangles.num; i++) {
      vertices[mesh->triangles.node[3*i+0]].padding.status = HXT_STATUS_TRUE;
      vertices[mesh->triangles.node[3*i+1]].padding.status = HXT_STATUS_TRUE;
      vertices[mesh->triangles.node[3*i+2]].padding.status = HXT_STATUS_TRUE;
    }
  }

  if(mesh->lines.node!=NULL){
    #pragma omp parallel for
    for (uint32_t i=0; i<mesh->lines.num; i++) {
      vertices[mesh->lines.node[2*i+0]].padding.status = HXT_STATUS_TRUE;
      vertices[mesh->lines.node[2*i+1]].padding.status = HXT_STATUS_TRUE;
    }
  }

  /* remove deleted vertices and change tetrahedra.node triangles.node and lines.nodes accordingly */
  uint32_t* numInserted;
  HXT_CHECK( hxtAlignedMalloc(&numInserted, omp_get_max_threads()*sizeof(uint32_t)) );
  const uint32_t n = mesh->vertices.num;

  // when a vertex was skipped, nodeInfo[i].status = HXT_STATUS_FALSE
  #pragma omp parallel
  {
    uint32_t start = 0;
    int threadID = omp_get_thread_num();
    numInserted[threadID] = 0;

    #pragma omp for schedule(static)
    for (uint32_t i=0; i<n; i++) {
      if(vertices[i].padding.status==HXT_STATUS_TRUE)
        numInserted[threadID]++;
    }// implicit barrier here

    for (int i=0; i<threadID; i++) {
      start+=numInserted[i];
    }

    // 3rd: compute where each vertices will be
    #pragma omp for schedule(static)
    for (uint32_t i=0; i<n; i++) {
      uint32_t oldStart = start;

      if(vertices[i].padding.status==HXT_STATUS_TRUE)
        start++;

      // index and status are at the same location (it's a union) we cannot put this above the "if" !
      vertices[i].padding.index = oldStart;
    }

    // 4th: update tetrahedra.node accordingly
    if(mesh->tetrahedra.node!=NULL){
      #pragma omp for
      for (uint64_t i=0; i<4*mesh->tetrahedra.num; i++) {
        uint32_t index = mesh->tetrahedra.node[i];
        if(index!=HXT_GHOST_VERTEX)
          mesh->tetrahedra.node[i] = vertices[index].padding.index;
      }
    }

    if(mesh->triangles.node!=NULL){
      #pragma omp for
      for (uint64_t i=0; i<3*mesh->triangles.num; i++) {
        uint32_t index = mesh->triangles.node[i];
        mesh->triangles.node[i] = vertices[index].padding.index;
      }
    }

    if(mesh->lines.node!=NULL){
      #pragma omp for
      for (uint64_t i=0; i<2*mesh->lines.num; i++) {
        uint32_t index = mesh->lines.node[i];
        mesh->lines.node[i] = vertices[index].padding.index;
      }
    }
  }

  HXT_CHECK( hxtAlignedFree(&numInserted) );

  // 5th: put vertices at the right indices
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    if(nodalSizes!=NULL){
      nodalSizes[vertices[i].padding.index] = nodalSizes[i];
    }
    vertices[vertices[i].padding.index] = vertices[i];
  }

  mesh->vertices.num = vertices[mesh->vertices.num-1].padding.index + 1;

  return HXT_STATUS_OK;
}
