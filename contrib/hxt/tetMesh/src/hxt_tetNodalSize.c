// Hxt - Copyright (C)
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_vertices.h"
#include "hxt_tetNodalSize.h"


HXTStatus hxtNodalSizesInit(HXTMesh* mesh, HXTNodalSizes* nodalSizes)
{
  HXT_CHECK(hxtAlignedMalloc(&nodalSizes->array,mesh->vertices.num*sizeof(double)));
  return HXT_STATUS_OK;
}

HXTStatus hxtComputeNodalSizesFromFunction(HXTMesh* mesh, HXTNodalSizes* nodalSizes)
{
  #pragma omp parallel for
  for (uint32_t i = 0; i<mesh->vertices.num; i++){
    mesh->vertices.coord[4 * i + 3] = -DBL_MAX;
  }

  HXT_CHECK( nodalSizes->callback(mesh->vertices.coord, mesh->vertices.num, nodalSizes->userData) );

  int failed = 0;
  #pragma omp parallel for reduction(||:failed)
  for (uint32_t i=0; i<mesh->vertices.num; i++) {
    if(mesh->vertices.coord[4 * i + 3] <= 0.)
      failed = 1;
    nodalSizes->array[i] = mesh->vertices.coord[4 * i + 3];
  }

  return failed==0 ? HXT_STATUS_OK : HXT_STATUS_FAILED;
}

HXTStatus hxtComputeNodalSizesFromTrianglesAndLines(HXTMesh* mesh, HXTNodalSizes* nodalSizes)
{
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;

  #pragma omp parallel for
  for (uint32_t i = 0; i<mesh->vertices.num; i++){
    nodalSizes->array[i] = 0;
    vertices[i].padding.hilbertDist = 0; // we use that as a counter to do the average...
  }

  // only do for triangles
  // we do not take into account hereafter nodalSizes = to DBL_MAX
  // could be changed in another fashion
  for (uint32_t i = 0; i<mesh->triangles.num; i++){
    for (uint32_t j = 0; j<2; j++){
      for (uint32_t k = j+1; k<3; k++){
        uint32_t n1 = mesh->triangles.node[3*i+j];
        uint32_t n2 = mesh->triangles.node[3*i+k];
        double *X1 = vertices[n1].coord;
        double *X2 = vertices[n2].coord;
        vertices[n1].padding.hilbertDist++;
        vertices[n2].padding.hilbertDist++;
        double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                         (X1[1]-X2[1])*(X1[1]-X2[1])+
                         (X1[2]-X2[2])*(X1[2]-X2[2]));
        nodalSizes->array[n1] += l;
        nodalSizes->array[n2] += l;
      }
    }
  }

  for (uint32_t i = 0; i<mesh->lines.num; i++){
      uint32_t n1 = mesh->lines.node[2*i+0];
      uint32_t n2 = mesh->lines.node[2*i+1];
      double *X1 = vertices[n1].coord;
      double *X2 = vertices[n2].coord;
      vertices[n1].padding.hilbertDist++;
      vertices[n2].padding.hilbertDist++;
      double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                       (X1[1]-X2[1])*(X1[1]-X2[1])+
                       (X1[2]-X2[2])*(X1[2]-X2[2]));
      nodalSizes->array[n1] += l;
      nodalSizes->array[n2] += l;
  }

  #pragma omp parallel for
  for (uint32_t i=0; i<mesh->vertices.num; i++)
  {
    if(vertices[i].padding.hilbertDist == 0) {
      nodalSizes->array[i] = DBL_MAX;
    }
    else {
      nodalSizes->array[i] /= (double) vertices[i].padding.hilbertDist;
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtComputeNodalSizesFromMesh(HXTMesh* mesh, HXTNodalSizes* nodalSizes)
{

  #pragma omp parallel for
  for (uint32_t i = 0; i<mesh->vertices.num; i++){
    nodalSizes->array[i] = DBL_MAX;
  }

  // we do not take into account hereafter nodalSizes->array = to DBL_MAX
  for (uint32_t i = 0; i<mesh->tetrahedra.num; i++){
    for (uint32_t j = 0; j<3; j++){
      for (uint32_t k = j+1; k<4; k++){
        uint32_t n1 = mesh->tetrahedra.node[4*i+j];
        uint32_t n2 = mesh->tetrahedra.node[4*i+k];
        if (n1 != HXT_GHOST_VERTEX && n2 != HXT_GHOST_VERTEX){
          double *X1 = mesh->vertices.coord + (size_t) 4*n1;
          double *X2 = mesh->vertices.coord + (size_t) 4*n2;
          double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                           (X1[1]-X2[1])*(X1[1]-X2[1])+
                           (X1[2]-X2[2])*(X1[2]-X2[2]));
          if(l<nodalSizes->array[n1]) nodalSizes->array[n1] = l;
          if(l<nodalSizes->array[n2]) nodalSizes->array[n2] = l;
        }
      }
    }
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtNodalSizesDestroy(HXTNodalSizes* nodalSizes)
{
  HXT_CHECK( hxtAlignedFree(&nodalSizes->array) );
  return HXT_STATUS_OK;
}
