// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#ifndef HXT_TETDELAUNAY_RESHAPE_H
#define HXT_TETDELAUNAY_RESHAPE_H

#ifdef __cplusplus
extern "C" {
#endif

#include "hxt_mesh.h"
#include "hxt_tetSync.h"
#include "hxt_tetPartition.h"

typedef struct {
  uint64_t neigh; // the tet on the other side of the boundary
  uint32_t node[3];
  uint16_t flag;
} cavityBnd_t;


typedef struct {
  uint64_t hxtDeclareAligned Map[1024];

  struct {
    cavityBnd_t* array;
    uint64_t num;
    uint64_t size;
  } ball;

  HXTDeleted deleted;
  HXTPartition partition;
} TetLocal;

/* pushing cavity boundary information to local->ball */
static inline void bndPush( TetLocal* local, uint16_t flag,
              const uint32_t node1, const uint32_t node2,
              const uint32_t node3, const uint64_t neigh){
  uint64_t n = local->ball.num;
  local->ball.array[n].node[0] = node1;
  local->ball.array[n].node[1] = node2;
  local->ball.array[n].node[2] = node3;
  local->ball.array[n].flag = flag;
  local->ball.array[n].neigh = neigh;
  local->ball.num++;
}

static inline HXTStatus askForBall(TetLocal* local, uint64_t needed) {
  needed += local->ball.num;
  if(needed>local->ball.size) {
    HXT_CHECK( hxtAlignedRealloc(&local->ball.array, sizeof(cavityBnd_t)*2*needed) );
    local->ball.size = 2*needed;
  }
  return HXT_STATUS_OK;
}


// TODO: it only needs the ball and the deleted... no need to know about the whole tetLocal structure
HXTStatus reshapeCavityIfNeeded(TetLocal* local, HXTMesh* mesh, const uint32_t vta, uint64_t prevNumDeleted, int undeleteTet);
HXTStatus respectEdgeConstraint(TetLocal* local, HXTMesh* mesh, const uint32_t vta, const uint32_t color, const uint64_t prevDeleted, int* undeleteTet);



#ifdef __cplusplus
}
#endif

#endif
