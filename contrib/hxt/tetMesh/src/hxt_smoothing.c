// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_smoothing.h"
#include "hxt_tetFlag.h"

/**************************************************************************
                    smoothing related functions
 **************************************************************************/
/* create a cavity containing all tetrahedra around a vertex, with a BFS */
static inline HXTStatus buildSmoothingCavity(ThreadLocal* local,
                                             uint64_t startFace) {
  const uint64_t startDist = local->partition.startDist;
  const uint64_t rel = local->partition.lengthDist;
  HXTMesh* mesh = local->toSync->mesh;
  const uint32_t vertex = mesh->tetrahedra.node[startFace];
  HXTVertex* vertices = (HXTVertex*) mesh->vertices.coord;
  HXTDeleted* deleted = &local->deleted;

  
  if(vertex < local->numVerticesConstrained)
    return HXT_STATUS_CONSTRAINT;

  // the vertex we are moving should be in the partition or we don't even try...
  if(vertexOutOfPartition(vertices, vertex, rel, startDist)) {
    return HXT_STATUS_CONFLICT;
  }

  HXT_CHECK( askForDeleted(&local->deleted, 4) );
  deleted->array[deleted->num++] = startFace;
  setDeletedFlag(mesh, startFace/4);

  for (uint64_t start=deleted->num-1; start<deleted->num; start++) {
    HXT_CHECK( askForDeleted(deleted, 3) );

    uint64_t curFace = deleted->array[start];
    uint64_t curTet = curFace/4;
    unsigned face = curFace%4;

    for (unsigned j=1; j<4; j++) {
      unsigned f = (face+j)%4;
      uint64_t neigh = mesh->tetrahedra.neigh[4*curTet + f];
      uint64_t neighTet = neigh/4;
      unsigned neighF = neigh%4;

      // all the cases where this function will fail.
      if(neigh==HXT_NO_ADJACENT)
        return HXT_STATUS_CONSTRAINT;

      if(getDeletedFlag(mesh, neighTet))
        continue;

      if(getFacetConstraint(mesh, curTet, f))
        return HXT_STATUS_CONSTRAINT;

      // I have the two facet that defines my edge, so
      unsigned f1, f2;
      getOtherFacetFrom2(f, face, &f1, &f2);
      if(getEdgeConstraint(mesh, curTet, getEdgeFromFacets(f, f1))
      || getEdgeConstraint(mesh, curTet, getEdgeFromFacets(f, f2)))
        return HXT_STATUS_CONSTRAINT;

      // uint32_t a = mesh->tetrahedra.node[(face+j+3)%4];
      uint32_t b = mesh->tetrahedra.node[4*curTet + f1];
      uint32_t c = mesh->tetrahedra.node[4*curTet + f2];
      uint32_t d = mesh->tetrahedra.node[neigh];
      if(vertexOutOfPartition(vertices, b, rel, startDist)
       + vertexOutOfPartition(vertices, c, rel, startDist)
       + vertexOutOfPartition(vertices, d, rel, startDist)>1) {
        return HXT_STATUS_CONFLICT;
      }

      // we can add the face without any fears now, but we have to find where is the vertex
      for (unsigned k=1; k<4; k++) {
        if(mesh->tetrahedra.node[4*neighTet + (neighF+k)%4]==vertex) {
          deleted->array[local->deleted.num++] = 4*neighTet + (neighF+k)%4;
          break;
        }
      }

      setDeletedFlag(mesh, neighTet);
    }
  }

  return HXT_STATUS_OK;
}

static double compute_worst_quality(HXTMesh* mesh,
                                    HXTDeleted* deleted,
                                    HXTTetQualities* quality,
                                    uint64_t prevNumDeleted) {
  double worst = DBL_MAX;

  // compute worst quality
  for (uint64_t i=prevNumDeleted; i<deleted->num; i++) {
    uint64_t tet = deleted->array[i]/4;
    double qual = tetQuality(mesh, quality,
                             mesh->tetrahedra.node[4*tet + 0],
                             mesh->tetrahedra.node[4*tet + 1],
                             mesh->tetrahedra.node[4*tet + 2],
                             mesh->tetrahedra.node[4*tet + 3]);
    if(qual < worst)
      worst = qual;
  }

  return worst;
}

static inline void interpolate_coord(const double start[3], const double end[3], double coord[3], double alpha) {
  for (int i=0; i<3; i++) {
    coord[i] = alpha*(start[i])+(1-alpha)*end[i];
  }
}

static HXTStatus golden_section_search(ThreadLocal* local,
                                       uint64_t prevNumDeleted,
                                       double start[3],
                                       double end[3],
                                       uint32_t vertex)
{
  HXTMesh* mesh = local->toSync->mesh;
  HXTDeleted* deleted = &local->deleted;
  HXTTetQualities* quality = local->quality;

  double* coord = mesh->vertices.coord + 4*vertex;
  double tol = 0.00001;
  const double invPhi = 0.6180339887498949;

  double v[4] = {1, 0, invPhi, 1-invPhi};
  double fv[4];

  for (int i=0; i<4; i++) {
    interpolate_coord(start, end, coord, v[i]);
    fv[i] = compute_worst_quality(mesh, deleted, quality, prevNumDeleted);
  }

  double original_worst = fv[0];

  // double fstart = fv[0], fend = fv[1];
  // int iter = 0;
  while(fv[2]>fv[0] && fv[2]>fv[1] && fv[3]>fv[0] && fv[3]>fv[1] && fabs(fv[0]-fv[1])>tol) {
    int ind;
    if(fv[2]>=fv[3]) { // maximum is between v[0] & d, (v[1] <-- v[3] and v[3] <-- v[2], compute new position of v[2])
      fv[1] = fv[3];
      v[1] = v[3];
      fv[3] = fv[2];
      v[3] = v[2];
      v[2] = v[0] + invPhi*(v[1]-v[0]); // (1-invPhi)*v[0]+invPhi*v[1];
      ind = 2;
    }
    else { // maximum is between v[2] & v[1], (v[0] <-- v[2] and v[2] <-- v[3], compute new position of v[3])
      fv[0] = fv[2];
      v[0] = v[2];
      fv[2] = fv[3];
      v[2] = v[3];
      v[3] = v[1] + invPhi*(v[0]-v[1]); // invPhi*v[0]+(1-invPhi)*v[1];
      ind = 3;
    }
    interpolate_coord(start, end, coord, v[ind]);
    fv[ind] = compute_worst_quality(mesh, deleted, quality, prevNumDeleted);
    // iter++;
  }
  // printf("fv[0]:%f  fv[1]:%f  fv[2]:%f  fv[3]:%f  fstart:%f  fend:%f  iter:%d\n", fv[0], fv[1], fv[2], fv[3], fstart, fend, iter);

  // best of fv[0] fv[1]
  if(fv[1] > fv[0]) {
    v[0] = v[1];
  }

  if(v[0]>=0.99 || fv[0]<=original_worst) {
    coord[0] = start[0];
    coord[1] = start[1];
    coord[2] = start[2];
    return HXT_STATUS_INTERNAL;
  }

  interpolate_coord(start, end, coord, v[0]);

  // compute new qualities and set new dates and reset "unused" flags
  for (uint64_t i=prevNumDeleted; i<local->deleted.num; i++) {
    uint64_t tet = local->deleted.array[i]/4;
    quality->values[tet] = tetQuality(mesh, quality,
                                   mesh->tetrahedra.node[4*tet + 0],
                                   mesh->tetrahedra.node[4*tet + 1],
                                   mesh->tetrahedra.node[4*tet + 2],
                                   mesh->tetrahedra.node[4*tet + 3]);
    // unused flag should be set to zero
    resetUnusedFlags(mesh, tet);
    local->date->values[tet].creation = local->date->current;
  }

  return HXT_STATUS_OK;
}

/* curFace is the face opposite to the vertex we are going to move */
HXTStatus hxtSmoothing(ThreadLocal* local,
                       uint64_t curFace)
{
  HXTMesh* mesh = local->toSync->mesh;
  HXTDeleted* deleted = &local->deleted;
  uint64_t prevNumDeleted = deleted->num;

  HXTStatus status = buildSmoothingCavity(local, curFace);

  for (uint64_t i=prevNumDeleted; i<deleted->num; i++) {
    unsetDeletedFlag(mesh, deleted->array[i]/4);
  }

  if(status!=HXT_STATUS_OK){
    deleted->num = prevNumDeleted;
    HXT_CHECK(status);
  }

  const uint64_t numTetInCavity = deleted->num - prevNumDeleted;

  // move the point
  uint32_t vertex = mesh->tetrahedra.node[curFace];
  double oldCoord[3];
  double centerCoord[3] = {0};
  for (int j=0; j<3; j++) {
    oldCoord[j] = mesh->vertices.coord[4*vertex+j];
  }

  for (uint64_t i=prevNumDeleted; i<deleted->num; i++) {
    uint64_t tet = deleted->array[i]/4;
    unsigned face = deleted->array[i]%4;
    double* a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet + (face+1)%4];
    double* b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet + (face+2)%4];
    double* c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*tet + (face+3)%4];
    for (int j=0; j<3; j++) {
      centerCoord[j] += (a[j]+b[j]+c[j])/3.0;
    }
  }

  for (int j=0; j<3; j++) {
    centerCoord[j] /= (double) numTetInCavity ;
  }

  status = golden_section_search(local, prevNumDeleted, oldCoord, centerCoord, vertex);
  deleted->num = prevNumDeleted;

  if(status!=HXT_STATUS_OK)
    HXT_CHECK( status );

  return HXT_STATUS_OK;
}