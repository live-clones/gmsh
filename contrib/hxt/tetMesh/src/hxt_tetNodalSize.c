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
  HXT_CHECK(hxtAlignedMalloc(&nodalSizes->array, mesh->vertices.num*sizeof(double)));

  /*********************************************************************
   first step: compute the missing nodalSizes from triangles and lines *
   *********************************************************************/
  #pragma omp parallel for simd
  for (uint32_t i = 0; i<mesh->vertices.num; i++) {
    if(mesh->vertices.coord[4 * i + 3] <= 0.0) {
      mesh->vertices.coord[4 * i + 3] = 0.0; // we use that as a counter to do the average...
      nodalSizes->array[i] = 0.0;            // this will store the sum
    }
    else {
      nodalSizes->array[i] = mesh->vertices.coord[4 * i + 3];
      mesh->vertices.coord[4 * i + 3] = DBL_MAX;
    }
  }

  HXT_ASSERT(mesh->triangles.num == 0 || mesh->triangles.node != NULL);
  HXT_ASSERT(mesh->triangles.num == 0 || mesh->vertices.num > 0);

  for (uint32_t i = 0; i<mesh->triangles.num; i++){
    for (uint32_t j = 0; j<2; j++){
      for (uint32_t k = j+1; k<3; k++){
        uint32_t n1 = mesh->triangles.node[3*i+j];
        uint32_t n2 = mesh->triangles.node[3*i+k];

        double *X1 = &mesh->vertices.coord[4 * n1];
        double *X2 = &mesh->vertices.coord[4 * n2];
        if(X1[3] == DBL_MAX &&
           X2[3] == DBL_MAX)
          continue;

        double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                         (X1[1]-X2[1])*(X1[1]-X2[1])+
                         (X1[2]-X2[2])*(X1[2]-X2[2]));
        if(X1[3] != DBL_MAX) {
          X1[3]++;
          nodalSizes->array[n1] += l;
        }

        if(X2[3] != DBL_MAX) {
          X2[3]++;
          nodalSizes->array[n2] += l;
        }
      }
    }
  }

  HXT_ASSERT(mesh->lines.num == 0 || mesh->lines.node != NULL);
  HXT_ASSERT(mesh->lines.num == 0 || mesh->vertices.num > 0);

  for (uint32_t i = 0; i<mesh->lines.num; i++){
      uint32_t n1 = mesh->lines.node[2*i+0];
      uint32_t n2 = mesh->lines.node[2*i+1];

      double *X1 = &mesh->vertices.coord[4 * n1];
      double *X2 = &mesh->vertices.coord[4 * n2];
      if(X1[3] == DBL_MAX &&
         X2[3] == DBL_MAX)
        continue;

      double l = sqrt ((X1[0]-X2[0])*(X1[0]-X2[0])+
                       (X1[1]-X2[1])*(X1[1]-X2[1])+
                       (X1[2]-X2[2])*(X1[2]-X2[2]));
      if(X1[3] != DBL_MAX) {
        X1[3]++;
        nodalSizes->array[n1] += l;
      }

      if(X2[3] != DBL_MAX) {
        X2[3]++;
        nodalSizes->array[n2] += l;
      }
  }

  #pragma omp parallel for simd
  for (uint32_t i=0; i<mesh->vertices.num; i++)
  {
    if(mesh->vertices.coord[4 * i + 3] == DBL_MAX)
      continue;
    nodalSizes->array[i] /= mesh->vertices.coord[4 * i + 3] * nodalSizes->factor;
  }

  return HXT_STATUS_OK;
}


HXTStatus hxtNodalSizesDestroy(HXTNodalSizes* nodalSizes)
{
  HXT_CHECK( hxtAlignedFree(&nodalSizes->array) );
  return HXT_STATUS_OK;
}
