#include "hxt_tetDelaunayReshape.h"
#include "hxt_mesh.h"
#include "hxt_message.h"
#include "hxt_sort.h"
#include "hxt_tetFlag.h"
#include "predicates.h"
#include <stdint.h>

/* check if the cavity is star shaped
   This isn't usefull for pure Delaunay but when we constrain cavity with color,
   it is usefull */
static HXTStatus isStarShaped(TetLocal* local, HXTMesh* mesh, const uint32_t vta, uint64_t* blindFaceIndex)
{
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  double *vtaCoord = vertices[vta].coord;

  for (uint64_t i=0; i<local->ball.num; i++) {
    if(local->ball.array[i].node[2]!=HXT_GHOST_VERTEX){
      double* b = vertices[local->ball.array[i].node[0]].coord;
      double* c = vertices[local->ball.array[i].node[1]].coord;
      double* d = vertices[local->ball.array[i].node[2]].coord;
      if(orient3d(vtaCoord, b, c, d)>=0.0){
        *blindFaceIndex = i;
        return HXT_STATUS_INTERNAL;
      }
    }
  }
  return HXT_STATUS_OK;
}


static HXTStatus undeleteTetrahedron(TetLocal* local, HXTMesh* mesh, uint64_t tetToUndelete) {
  // the tetrahedra should not be deleted anymore
  for (uint64_t i=local->deleted.num; ; i--) {
    if(local->deleted.array[i-1]==tetToUndelete) {
      local->deleted.num--;
      local->deleted.array[i-1] = local->deleted.array[local->deleted.num];
      break;
    }
#ifdef DEBUG
    if(i==1)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "could not find the tetrahedra in the deleted array");
#endif
  }
  unsetDeletedFlag(mesh, tetToUndelete);

  uint64_t bndFaces[4] = {HXT_NO_ADJACENT, HXT_NO_ADJACENT, HXT_NO_ADJACENT, HXT_NO_ADJACENT};
  int nbndFace = 0;

  // we should update the boundary (that's the difficult part...)
  // first remove all the boundary faces that come from the tetrahedron we just removed from the cavity
  for (uint64_t i=local->ball.num; nbndFace<4 && i>0; i--) {
    if(mesh->tetrahedra.neigh[local->ball.array[i-1].neigh]/4==tetToUndelete) {
      bndFaces[nbndFace++] = local->ball.array[i-1].neigh;
      local->ball.num--;
      local->ball.array[i-1] = local->ball.array[local->ball.num];
    }
  }

  // we must replace them by all the other faces of the tetrahedron we just removed
  const uint64_t* __restrict__ curNeigh = mesh->tetrahedra.neigh + tetToUndelete*4;
  const uint32_t* __restrict__ curNode = mesh->tetrahedra.node + tetToUndelete*4;

#ifdef DEBUG
  int nbndFace2 = (getDeletedFlag(mesh, curNeigh[0]/4)==0 || getFacetConstraint(mesh, tetToUndelete, 0)) +
                  (getDeletedFlag(mesh, curNeigh[1]/4)==0 || getFacetConstraint(mesh, tetToUndelete, 1)) +
                  (getDeletedFlag(mesh, curNeigh[2]/4)==0 || getFacetConstraint(mesh, tetToUndelete, 2)) +
                  (getDeletedFlag(mesh, curNeigh[3]/4)==0 || getFacetConstraint(mesh, tetToUndelete, 3));
  if(nbndFace!=nbndFace2)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "found %d non-deleted tet adjacent to the tet we unremove but there should be %d %lu %lu %lu %lu", nbndFace, nbndFace2, bndFaces[0], bndFaces[1], bndFaces[2], bndFaces[3]);
#endif

  HXT_CHECK( askForBall(local, 3) );

  if(curNeigh[0]!=bndFaces[0] && curNeigh[0]!=bndFaces[1] && curNeigh[0]!=bndFaces[2] && curNeigh[0]!=bndFaces[3])
    bndPush(local, (getFacetConstraint(mesh, tetToUndelete, 0)   ) |
                   (getEdgeConstraint(mesh, tetToUndelete, 1)>>1) | // constraint on edge 1 (facet 0 2) goes on edge 0
                   (getEdgeConstraint(mesh, tetToUndelete, 0)<<1) | // constraint on edge 0 (facet 0 1) goes on edge 1
                   (getEdgeConstraint(mesh, tetToUndelete, 2)   ),  // constraint on edge 2 (facet 0 3) goes on edge 2
                   curNode[2], curNode[1], curNode[3], 4*tetToUndelete+0);

  if(curNeigh[1]!=bndFaces[0] && curNeigh[1]!=bndFaces[1] && curNeigh[1]!=bndFaces[2] && curNeigh[1]!=bndFaces[3])
    bndPush(local,  (getFacetConstraint(mesh, tetToUndelete, 1)>>1) |// constraint on facet 1 goes on facet 0
                    (getEdgeConstraint(mesh, tetToUndelete, 0)   ) | // constraint on edge 0 (facet 1 0) goes on edge 0
                    (getEdgeConstraint(mesh, tetToUndelete, 3)>>2) | // constraint on edge 3 (facet 1 2) goes on edge 1
                    (getEdgeConstraint(mesh, tetToUndelete, 4)>>2),  // constraint on edge 4 (facet 1 3) goes on edge 2
                    curNode[0], curNode[2], curNode[3], 4*tetToUndelete+1);

  if(curNeigh[2]!=bndFaces[0] && curNeigh[2]!=bndFaces[1] && curNeigh[2]!=bndFaces[2] && curNeigh[2]!=bndFaces[3])
    bndPush(local,  (getFacetConstraint(mesh, tetToUndelete, 2)>>2) |// constraint on facet 2 goes on facet 0
                    (getEdgeConstraint(mesh, tetToUndelete, 3)>>3) | // constraint on edge 3 (facet 2 1) goes on edge 0
                    (getEdgeConstraint(mesh, tetToUndelete, 1)   ) | // constraint on edge 1 (facet 2 0) goes on edge 1
                    (getEdgeConstraint(mesh, tetToUndelete, 5)>>3),  // constraint on edge 5 (facet 2 3) goes on edge 2
                     curNode[1], curNode[0], curNode[3], 4*tetToUndelete+2);

  if(curNeigh[3]!=bndFaces[0] && curNeigh[3]!=bndFaces[1] && curNeigh[3]!=bndFaces[2] && curNeigh[3]!=bndFaces[3])
    bndPush(local, (getFacetConstraint(mesh, tetToUndelete, 3)>>3) |// constraint on facet 3 goes on facet 0
                   (getEdgeConstraint(mesh, tetToUndelete, 2)>>2) | // constraint on edge 2 (facet 3 0) goes on edge 0
                   (getEdgeConstraint(mesh, tetToUndelete, 4)>>3) | // constraint on edge 4 (facet 3 1) goes on edge 1
                   (getEdgeConstraint(mesh, tetToUndelete, 5)>>3),  // constraint on edge 5 (facet 3 2) goes on edge 2
                   curNode[0], curNode[1], curNode[2], 4*tetToUndelete+3);

  return HXT_STATUS_OK;
}



HXTStatus respectEdgeConstraint(TetLocal* local, HXTMesh* mesh, const uint32_t vta, const uint32_t color, const uint64_t prevDeleted)
{
  // HXT_WARNING("a constrained edge was inside the cavity, recovering it");

  // all the tetrahedron have the same color 'color', we will use that color to flag them
  for (uint64_t i=prevDeleted; i<local->deleted.num; i++) {
    uint64_t delTet = local->deleted.array[i];
    mesh->tetrahedra.color[delTet] = 0;
  }

  for (uint64_t i=prevDeleted; i<local->deleted.num; i++) {
    uint64_t delTet = local->deleted.array[i];
    int exist = 1;
    for (int edge=0; exist && edge<6; edge++) {
      if(getEdgeConstraint(mesh, delTet, edge) && (mesh->tetrahedra.color[delTet] & (1U<<edge))==0) {
        unsigned in_facet;
        unsigned out_facet;

        getFacetsFromEdge(edge, &in_facet, &out_facet);

        int edgeIsSafe = 0;
        uint64_t curTet = delTet;

        // first turn
        do
        {
          uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

          // go into the neighbor through out_facet
          uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
          curTet = neigh/4;
          in_facet = neigh%4;

          uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
          for (out_facet=0; out_facet<3; out_facet++)
            if(nodes[out_facet]==newV)
              break;

          if(getDeletedFlag(mesh, curTet)!=0) {
            // mark that the edge as been treate
            #ifdef DEBUG
              if((mesh->tetrahedra.color[curTet] & (1U<<getEdgeFromFacets(in_facet, out_facet)))!=0)
                return HXT_ERROR_MSG(HXT_STATUS_ERROR, "the flag says that the tet has already been processed for this edge...");
            #endif
            mesh->tetrahedra.color[curTet] |= (1U<<getEdgeFromFacets(in_facet, out_facet));
          }
          else {
            edgeIsSafe=1;
          }

        } while (curTet!=delTet);

        if(!edgeIsSafe) { // we must find a tetrahedron on the opposite side of vta and delete it.
          getFacetsFromEdge(edge, &in_facet, &out_facet);
          curTet = delTet;

          uint64_t tetContainingVta = local->deleted.array[prevDeleted];
          uint64_t tetToUndelete = HXT_NO_ADJACENT;
          double distMax = 0.0;
          double* vtaCoord = mesh->vertices.coord + 4*vta;

        #ifdef DEBUG
          double* a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta];
          double* b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta+1];
          double* c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta+2];
          double* d = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tetContainingVta+3];

          if(orient3d(vtaCoord,b,c,d)>0.0 || orient3d(a,vtaCoord,c,d)>0.0 || orient3d(a,b,vtaCoord,d)>0.0 || orient3d(a,b,c,vtaCoord)>0.0) {
            return HXT_ERROR_MSG(HXT_STATUS_ERROR, "an edge part of a ghost tetrahedron is constrained");
          }
        #endif

          // second turn
          do
          {
            uint32_t newV = mesh->tetrahedra.node[4*curTet + in_facet];

            // go into the neighbor through out_facet
            uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + out_facet];
            curTet = neigh/4;
            in_facet = neigh%4;

            uint32_t* nodes = mesh->tetrahedra.node + 4*curTet;
            for (out_facet=0; out_facet<3; out_facet++)
              if(nodes[out_facet]==newV)
                break;

            double* coord1 = mesh->vertices.coord + newV;
            double* coord2 = mesh->vertices.coord + nodes[in_facet];

            if(curTet!=tetContainingVta) {
              double dist = 0.0;
              for (int l=0; l<3; l++) {
                double meanCoord = (coord1[l]+coord2[l])*0.5;
                double diff = meanCoord-vtaCoord[l];
                dist += diff*diff;
              }

              if(dist>distMax) {
                dist = distMax;
                tetToUndelete = curTet;
              }
            }
          } while (curTet!=delTet);

          if(tetToUndelete==delTet)
            exist = 0;

          // printf("undeleting tetrahedron %lu\n", tetToUndelete);
          mesh->tetrahedra.color[tetToUndelete] = color;
          HXT_CHECK( undeleteTetrahedron(local, mesh, tetToUndelete) );
        }
      }
    }
  }

  for (uint64_t i=prevDeleted; i<local->deleted.num; i++) {
    uint64_t delTet = local->deleted.array[i];
    mesh->tetrahedra.color[delTet] = color;
  }

  return HXT_STATUS_OK;
}


// search neighbors in an already initialized hash table. `key` must be unique, and cannot be UINT64_MAX
static inline void hashTablePut(HXTGroup2* pairs, uint64_t mask, uint64_t key, uint64_t value) {
  HXT_ASSERT(key != UINT64_MAX);

  uint64_t hash = hash64(key) & mask;
  while(pairs[hash].v[0] != UINT64_MAX) {
    HXT_ASSERT(pairs[hash].v[0] != key); // same key cannot already be there
    hash = (hash + 1) & mask;
  }

  pairs[hash].v[0] = key;
  pairs[hash].v[1] = value;
}

static inline uint64_t hashTableGet(HXTGroup2* pairs, uint64_t mask, uint64_t key) {
  uint64_t hash = hash64(key) & mask;
  while(pairs[hash].v[0] != key && pairs[hash].v[0] != UINT64_MAX) {
    hash = (hash + 1) & mask;
  }
  if(pairs[hash].v[0] == key) {
    return pairs[hash].v[1];
  }
  return HXT_NO_ADJACENT;
}




// remove the tetrahedra adjacent to the face that does not see the point, progressively, until the cavity is star shaped...
HXTStatus reshapeCavityIfNeeded(TetLocal* local, HXTMesh* mesh, const uint32_t vta, const uint64_t prevNumDeleted)
{

  uint64_t blindFace;
  if(isStarShaped(local, mesh, vta, &blindFace)==HXT_STATUS_OK)
    return HXT_STATUS_OK;

  // we need an array index for all faces that tells if the face is in the boundary or not, it should correspond to the deleted tet array
  // In he same array, we can store adjacencies between deleted tet !
  // => compute those adjacencies with a hash table.

  // 1. put all the deleted tet in a hash table : key = meshIndex, value = deletedIndex
  // 2. create the faces array
  // 3. iterate over all deleted tet, and fill the faces array using the hash table. A special bit is set for non deleted neighbors
  // 4. reshape the cavity

  // point 1 and 2 can take a lot of memory... can we recycle some ??

  const uint64_t numTet = local->deleted.num - prevNumDeleted;
  uint64_t* tets = &local->deleted.array[prevNumDeleted];

  uint64_t size = UINT64_C(1) << u64_log2(5*numTet/2);// we want a hash table of at least 2.5*numTet for a good load factor
  uint64_t mask = size - 1;

  uint64_t* faces;
  HXTGroup2* pairs;

  HXT_CHECK( hxtMalloc(&pairs, sizeof(HXTGroup2) * size));
  memset(pairs, -1, size * sizeof(HXTGroup2));

  // 1.
  for(uint64_t i=0; i<numTet; i++) {
    hashTablePut(pairs, mask, tets[i], i);
  }

  // 2.
  HXT_CHECK( hxtMalloc(&faces, sizeof(uint64_t) * 4 * numTet) );

  // 3.
  uint64_t curFace = 0;
  for(uint64_t i=0; i<numTet; i++) {
    uint64_t curTet = tets[i];

    for(int j=0; j<4; j++) {
      // search in the table, but without replacing...
      uint64_t neigh = mesh->tetrahedra.neigh[4 * curTet + j];
      
      if(neigh != HXT_NO_ADJACENT && getDeletedFlag(mesh, neigh / 4)) {
        uint64_t deletedIndex = hashTableGet(pairs, mask, neigh / 4);
        HXT_ASSERT(deletedIndex != HXT_NO_ADJACENT);

        faces[4 * i + j] = 4 * deletedIndex + neigh % 4;
      }
      else { // it should be the next one in the ball, (we didn't change the order since @diggingACavity)
        HXT_ASSERT(local->ball.array[curFace].neigh==neigh);
        local->ball.array[curFace].neigh = 4 * i + j;
        faces[4 * i + j] = curFace;
        curFace++;
      }
    }
  }

  #ifndef NDEBUG
  if(curFace != local->ball.num) {
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "DEBUG: Faces did not appear in the same order as deleted tet");
  }
  #endif

  HXT_CHECK( hxtFree(&pairs) );


  /* 4. iterate over all faces, and undelete (remove from the cavity) the associated tet when the face does not see vta
   * We have got to update the faces array and the boundary correctly
   * We also have to update the curFace index such that all faces below it are good
   * and all faces above or equal are unchecked.
   */
  double *vtaCoord = &mesh->vertices.coord[4 * vta];

  for (uint64_t curFace=blindFace; curFace<local->ball.num;) {
    if(local->ball.array[curFace].node[2]==HXT_GHOST_VERTEX){
      curFace++;
      continue;
    }

    double* b = &mesh->vertices.coord[4 * local->ball.array[curFace].node[0]];
    double* c = &mesh->vertices.coord[4 * local->ball.array[curFace].node[1]];
    double* d = &mesh->vertices.coord[4 * local->ball.array[curFace].node[2]];
    if(orient3d(vtaCoord, b, c, d)<0.0){
      curFace++;
      continue;
    }

    // 4.1: undelete the tetrahedron
    uint64_t in = local->ball.array[curFace].neigh;
    uint64_t tetToUndelete = tets[in / 4];
    // unsigned facet = in % 4;
    unsetDeletedFlag(mesh, tetToUndelete);
    tets[in / 4] = HXT_NO_ADJACENT;// correct deletion from the array is handled at point 6.

    askForBall(local, 3);
    for(int f=0; f<4; f++) {
      uint64_t neigh = mesh->tetrahedra.neigh[4 * tetToUndelete + f];
      if(!getDeletedFlag(mesh, neigh / 4)) { // it is an exterior facet, so we have to remove it from the ball !
        uint64_t face = faces[4 * (in / 4) + f];
        if(face < curFace) {
          curFace--;
          if(face != curFace) {
            local->ball.array[face] = local->ball.array[curFace];
            uint64_t inOther = local->ball.array[face].neigh;
            HXT_ASSERT(faces[inOther] == curFace);
            faces[inOther] = face;
          }
          face = curFace;
        }

        // put the last one in here, and change indices in the faces table too !
        local->ball.num--;
        if(face != local->ball.num) {
          local->ball.array[face] = local->ball.array[local->ball.num];
          uint64_t inOther = local->ball.array[face].neigh;
          HXT_ASSERT(faces[inOther] == local->ball.num);
          faces[inOther] = face;
        }
      }
      else { // we have to add a boundary facet at the end
        uint64_t out = faces[4 * (in / 4) + f];
        faces[out] = local->ball.num;


        uint64_t* curNeigh = mesh->tetrahedra.neigh + tetToUndelete*4;
        uint32_t* curNode = mesh->tetrahedra.node + tetToUndelete*4;
        if(f==0) {
          bndPush(local, (getFacetConstraint(mesh, tetToUndelete, 0)   ) |
                         (getEdgeConstraint(mesh, tetToUndelete, 1)>>1) | // constraint on edge 1 (facet 0 2) goes on edge 0
                         (getEdgeConstraint(mesh, tetToUndelete, 0)<<1) | // constraint on edge 0 (facet 0 1) goes on edge 1
                         (getEdgeConstraint(mesh, tetToUndelete, 2)   ),  // constraint on edge 2 (facet 0 3) goes on edge 2
                         curNode[2], curNode[1], curNode[3], out);
        }
        else if(f==1) {
          bndPush(local,  (getFacetConstraint(mesh, tetToUndelete, 1)>>1) |// constraint on facet 1 goes on facet 0
                          (getEdgeConstraint(mesh, tetToUndelete, 0)   ) | // constraint on edge 0 (facet 1 0) goes on edge 0
                          (getEdgeConstraint(mesh, tetToUndelete, 3)>>2) | // constraint on edge 3 (facet 1 2) goes on edge 1
                          (getEdgeConstraint(mesh, tetToUndelete, 4)>>2),  // constraint on edge 4 (facet 1 3) goes on edge 2
                          curNode[0], curNode[2], curNode[3], out);
        }
        else if(f==2) {
          bndPush(local,  (getFacetConstraint(mesh, tetToUndelete, 2)>>2) |// constraint on facet 2 goes on facet 0
                          (getEdgeConstraint(mesh, tetToUndelete, 3)>>3) | // constraint on edge 3 (facet 2 1) goes on edge 0
                          (getEdgeConstraint(mesh, tetToUndelete, 1)   ) | // constraint on edge 1 (facet 2 0) goes on edge 1
                          (getEdgeConstraint(mesh, tetToUndelete, 5)>>3),  // constraint on edge 5 (facet 2 3) goes on edge 2
                           curNode[1], curNode[0], curNode[3], out);
        }
        else {
          bndPush(local, (getFacetConstraint(mesh, tetToUndelete, 3)>>3) |// constraint on facet 3 goes on facet 0
                         (getEdgeConstraint(mesh, tetToUndelete, 2)>>2) | // constraint on edge 2 (facet 3 0) goes on edge 0
                         (getEdgeConstraint(mesh, tetToUndelete, 4)>>3) | // constraint on edge 4 (facet 3 1) goes on edge 1
                         (getEdgeConstraint(mesh, tetToUndelete, 5)>>3),  // constraint on edge 5 (facet 3 2) goes on edge 2
                         curNode[0], curNode[1], curNode[2], out);
        }
      }
    }
  }

  HXT_CHECK( hxtFree(&faces) );


  // 5. put back the correct values in ball neighbors
  for(uint64_t curFace=0; curFace<local->ball.num; curFace++) {
    uint64_t in = local->ball.array[curFace].neigh;
    local->ball.array[curFace].neigh = mesh->tetrahedra.neigh[4*tets[in/4] + in%4];
  }


  // 6. correctly delete the tetrahedra in the deleted array
  uint64_t shift = 0;
  for(uint64_t i=0; i<numTet; i++) {
    if(tets[i]==HXT_NO_ADJACENT)
      shift++;
    else if(shift)
      tets[i-shift] = tets[i];
  }
  local->deleted.num -= shift;

  // HXT_ASSERT( isStarShaped(local, mesh, vta, &blindFace)==HXT_STATUS_OK );

  return HXT_STATUS_OK;
}
