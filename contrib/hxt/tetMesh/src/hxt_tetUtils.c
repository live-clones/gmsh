// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_sort.h"

/***********************************
 * remove deleted tetrahedra of mesh
 ***********************************/
// TODO: a parallel technique
HXTStatus hxtRemoveDeleted(HXTMesh* mesh)
{
  if(mesh->tetrahedra.num==0)
    return HXT_STATUS_OK;
  
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(getDeletedFlag(mesh, i)){
      for (unsigned j=0; j<4; j++) {
        size_t index = 4*i+j;
        uint64_t neigh = mesh->tetrahedra.neigh[index]; // neighbor of the deleted tet
        if(neigh!=HXT_NO_ADJACENT && mesh->tetrahedra.neigh[neigh]==index) // the deleted tet had a neighbor pointing to him...
          mesh->tetrahedra.neigh[neigh] = HXT_NO_ADJACENT;
      }
    }
  }

  uint64_t right = mesh->tetrahedra.num-1;
  uint64_t left = 0;

  while(1) {
    while(left < right && getDeletedFlag(mesh, right)) right--;
    while(left < right && getDeletedFlag(mesh, left)==0) left++;

    if(left >= right)
      break;

    if(mesh->tetrahedra.color != NULL)
      mesh->tetrahedra.color[left] = mesh->tetrahedra.color[right];
    mesh->tetrahedra.flag[left] = mesh->tetrahedra.flag[right];

    // swap the two tetrahedra
    for (unsigned j=0; j<4; j++) {
      uint64_t neighR = mesh->tetrahedra.neigh[4*right+j]; // neighbor of the tet that will be moved (not deleted)
      if(neighR!=HXT_NO_ADJACENT)
        mesh->tetrahedra.neigh[neighR] = 4*left+j;

      mesh->tetrahedra.node[4*left+j] = mesh->tetrahedra.node[4*right+j];
      mesh->tetrahedra.neigh[4*left+j] = neighR;
    }

    left++; right--;
  }

  if(left==right && getDeletedFlag(mesh, left)==0) left++;

  mesh->tetrahedra.num = left;

  return HXT_STATUS_OK;
}