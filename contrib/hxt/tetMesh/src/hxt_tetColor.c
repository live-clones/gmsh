// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetColor.h"
#include "hxt_tetFlag.h"
#include "hxt_sort.h"

typedef struct {
  uint32_t* surfaces;
  uint32_t numSurfaces;
  uint32_t color;
  int isFromOriginalBREP;
} HXTBrepVolume;

static inline int compareSortedVolumes(const void* vv0, const void* vv1)
{
  HXTBrepVolume* v0 = (HXTBrepVolume*) vv0;
  HXTBrepVolume* v1 = (HXTBrepVolume*) vv1;

  if(v0->numSurfaces > v1->numSurfaces)
    return 1;
  else if(v0->numSurfaces < v1->numSurfaces)
    return -1;

  for(uint32_t i=0; i<v0->numSurfaces; i++) {
    if(v0->surfaces[i] > v1->surfaces[i])
      return 1;
    else if(v0->surfaces[i] < v1->surfaces[i])
      return -1;
  }

  return 0;
}


/***************************************************
 *      Coloring the mesh                          *
 ***************************************************/
static HXTStatus hxtColorMesh(HXTMesh* mesh, uint32_t* numVolumes)
{
  uint64_t *stack;
  HXT_CHECK( hxtMalloc(&stack, sizeof(uint64_t)*mesh->tetrahedra.num));

  HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.color, sizeof(uint32_t)*mesh->tetrahedra.size) );
  memset(mesh->tetrahedra.color, 0, sizeof(uint32_t) * mesh->tetrahedra.size);

  uint32_t color = 1;
  uint32_t colorOut = 0;

  while (1){
    uint64_t stackSize = 0;
    uint64_t first = UINT64_MAX;

    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(mesh->tetrahedra.color[i]==0){
        first = i;
        break;
      }
    }

    if(first==UINT64_MAX)
      break;

    stack[stackSize++] = first;
    mesh->tetrahedra.color[first] = color;

    for (uint64_t i=0; i<stackSize; i++) {
      uint64_t t = stack[i];

      if (mesh->tetrahedra.node[4*t+3] == HXT_GHOST_VERTEX)
        colorOut = color;

      for (unsigned j=0; j<4; j++) {
        if(mesh->tetrahedra.neigh[4*t+j]!=HXT_NO_ADJACENT && getFacetConstraint(mesh, t, j)==0) { // the facet is not a boundary facet
          uint64_t neigh = mesh->tetrahedra.neigh[4*t+j]/4;
          if(mesh->tetrahedra.color[neigh]==0){
            stack[stackSize++] = neigh;
            mesh->tetrahedra.color[neigh] = color;
          }
        }
      }
    }
    color++;
  }
  *numVolumes = color-2; // -2 because we began at one AND because colorout is not counted...

  HXT_CHECK( hxtFree(&stack) );

  #pragma omp parallel for
  for (uint64_t i=0;i<mesh->tetrahedra.num;i++){
    if (mesh->tetrahedra.color[i] == colorOut){
      mesh->tetrahedra.color[i] = HXT_COLOR_OUT;
    }
    else if(mesh->tetrahedra.color[i] > colorOut){
      mesh->tetrahedra.color[i]-=2;
    }
    else {
      mesh->tetrahedra.color[i]--;
    }
  }

  return HXT_STATUS_OK;
}


HXTStatus hxtMapColorsToBrep(HXTMesh* mesh, uint64_t* tri2TetMap)
{
  uint32_t numVolumes;
  HXT_CHECK( hxtColorMesh(mesh, &numVolumes) );

  if(mesh->triangles.color == NULL) {
    HXT_WARNING("No surface colors => cannot verify BRep !");
    return HXT_STATUS_OK;
  }

  uint64_t numPairs = 0;
  uint64_t maxPair = 0;
  uint64_t* pairs; // associate a volume and a surface color
  HXT_CHECK( hxtMalloc(&pairs, sizeof(uint64_t) * 2 * mesh->triangles.num) );

  uint64_t lastPair0 = UINT64_MAX;
  uint64_t lastPair1 = UINT64_MAX;

  for(uint64_t i=0; i<mesh->triangles.num; i++) {
    if(mesh->triangles.color[i]==HXT_COLOR_OUT)
      continue; // triangle is considered exterior

    HXT_ASSERT(tri2TetMap[i]!=HXT_NO_ADJACENT);

    uint64_t tet = tri2TetMap[i]/4;
    uint64_t neigh = mesh->tetrahedra.neigh[tri2TetMap[i]];
    

    uint64_t color1 = mesh->tetrahedra.color[tet];
    uint64_t color2 = neigh==HXT_NO_ADJACENT ? HXT_COLOR_OUT : mesh->tetrahedra.color[neigh/4];

    if(color1 != HXT_COLOR_OUT) {
      uint64_t pair = color1<<32 | mesh->triangles.color[i];
      if(pair != lastPair0 && pair != lastPair1) {
        pairs[numPairs++] = pair;
        if(pair > maxPair)
          maxPair = pair;
        lastPair1 = lastPair0;
        lastPair0 = pair;
      }
    }

    if(color2 != HXT_COLOR_OUT) {
      uint64_t pair = color2<<32 | mesh->triangles.color[i];
      if(pair != lastPair0 && pair != lastPair1) {
        pairs[numPairs++] = pair;
        if(pair > maxPair)
          maxPair = pair;
        lastPair1 = lastPair0;
        lastPair0 = pair;
      }
    }
  }

  HXT_CHECK( group1_sort(pairs, numPairs, maxPair) );

  // eliminate duplicates
  uint64_t index = 0;
  for(uint64_t i=1; i<numPairs; i++) {
    if(pairs[index] == pairs[i])
      continue;
    pairs[++index] = pairs[i];
  }
  numPairs = index + 1;

  uint32_t* numSurfacesPerVolume;
  uint32_t* surfacesPerVolume;
  HXT_CHECK( hxtAlignedMalloc(&numSurfacesPerVolume, sizeof(uint32_t) * numVolumes) );
  memset(numSurfacesPerVolume, 0, sizeof(uint32_t) * numVolumes);
  HXT_CHECK( hxtAlignedMalloc(&surfacesPerVolume, sizeof(uint32_t) * numPairs) );

  for(uint64_t i=0; i<numPairs; i++) {
    uint32_t volume = pairs[i] >> 32;
    numSurfacesPerVolume[volume]++;
    surfacesPerVolume[i] = pairs[i] & UINT32_MAX;
  }

  HXT_CHECK( hxtFree(&pairs) );

  /* at this point, we constructed or own volume BRep in:
   *  - numVolumes
   *  - numSurfacesPerVolume
   *  - surfacePerVolumes
   *
   * Now, either there is no existing BRep, in which case put our own one in mesh->brep
   * or there is an existing BRep.
   * In the latter case, we have to compare each volume of our reconstructed BRep against
   * the original BRep. If the two volumes have the same definition, the color of our volume
   * needs to correspond to the one of the original BRep.
   */ 

  if(mesh->brep.numVolumes == 0) { // no existing original BRep
  #ifndef NDEBUG
    if(mesh->brep.numSurfacesPerVolume!=NULL) {
      HXT_WARNING("mesh->brep.numSurfacesPerVolume is not null but numVolumes=0\nAttempting to free it");
      HXT_CHECK( hxtAlignedFree(&mesh->brep.numSurfacesPerVolume) );
    }
    if(mesh->brep.surfacesPerVolume!=NULL) {
      HXT_WARNING("mesh->brep.surfacesPerVolume is not null but numVolumes=0\nAttempting to free it");
      HXT_CHECK( hxtAlignedFree(&mesh->brep.surfacesPerVolume) );
    }
  #endif
    mesh->brep.numVolumes = numVolumes;
    mesh->brep.numSurfacesPerVolume = numSurfacesPerVolume;
    mesh->brep.surfacesPerVolume = surfacesPerVolume;
  }
  else { // there is an existing BRep
    // we have got to match the BREPs together...
    HXT_ASSERT(mesh->brep.numSurfacesPerVolume!=NULL);
    HXT_ASSERT(mesh->brep.surfacesPerVolume!=NULL);

    if(mesh->brep.numVolumes > numVolumes)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "BRep contains more volumes than there really are !");

    if(mesh->brep.numVolumes < numVolumes)
      HXT_INFO("%u out of %u volumes will be refined", mesh->brep.numVolumes, numVolumes);

    uint64_t* pairsFromBREP;
    uint64_t numPairsFromBREP = 0;
    uint64_t maxPairFromBREP = 0;
    for(uint32_t i=0; i<mesh->brep.numVolumes; i++) {
      numPairsFromBREP += mesh->brep.numSurfacesPerVolume[i];
    }

    HXT_CHECK( hxtMalloc(&pairsFromBREP, sizeof(uint64_t) * numPairsFromBREP) );

    numPairsFromBREP = 0;
    for(uint32_t i=0; i<mesh->brep.numVolumes; i++) {
      for(uint32_t j=0; j<mesh->brep.numSurfacesPerVolume[i]; j++) {
        uint64_t pair = (uint64_t) i << 32 | mesh->brep.surfacesPerVolume[numPairsFromBREP];
        pairsFromBREP[numPairsFromBREP] = pair;
        if(pair > maxPairFromBREP)
          maxPairFromBREP = pair;
        numPairsFromBREP++;
      }
    }

    HXT_CHECK( group1_sort(pairsFromBREP, numPairsFromBREP, maxPairFromBREP) );

    #ifndef NDEBUG
    // error on duplicates
    for(uint64_t i=1; i<numPairsFromBREP; i++) {
      if(pairsFromBREP[i-1] == pairsFromBREP[i])
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Duplicate surface in BRep volume definition");
    }
    #endif

    // all this was to sort the BREP:
    memset(mesh->brep.numSurfacesPerVolume, 0, sizeof(uint32_t) * mesh->brep.numVolumes);

    for(uint64_t i=0; i<numPairsFromBREP; i++) {
      uint32_t volume = pairsFromBREP[i] >> 32;
      mesh->brep.numSurfacesPerVolume[volume]++;
      mesh->brep.surfacesPerVolume[i] = pairsFromBREP[i] & UINT32_MAX;
    }

    HXT_CHECK( hxtFree(&pairsFromBREP) );

    // sort the volumes by the hash and compare them...
    HXTBrepVolume* volumes;
    HXT_CHECK( hxtMalloc(&volumes, sizeof(HXTBrepVolume) * (numVolumes + mesh->brep.numVolumes)) );

    uint64_t index = 0;
    for(uint32_t i=0; i<numVolumes; i++) {
      volumes[i].surfaces = &surfacesPerVolume[index];
      volumes[i].numSurfaces = numSurfacesPerVolume[i];
      volumes[i].color = i;
      volumes[i].isFromOriginalBREP = 0;

      index += numSurfacesPerVolume[i];
    }

    index = 0;
    for(uint32_t i=0; i<mesh->brep.numVolumes; i++) {
      volumes[numVolumes + i].surfaces = &mesh->brep.surfacesPerVolume[index];
      volumes[numVolumes + i].numSurfaces = mesh->brep.numSurfacesPerVolume[i];
      volumes[numVolumes + i].color = i;
      volumes[numVolumes + i].isFromOriginalBREP = 1;

      index += mesh->brep.numSurfacesPerVolume[i];
    }

    HXT_CHECK( hxtAlignedFree( &numSurfacesPerVolume ) );

    qsort(volumes, numVolumes + mesh->brep.numVolumes, sizeof(HXTBrepVolume), compareSortedVolumes);

    uint32_t* volumeMap;
    HXT_CHECK( hxtMalloc(&volumeMap, sizeof(uint32_t) * numVolumes) );
    for(uint32_t i=0; i<numVolumes; i++) {
      volumeMap[i] = HXT_COLOR_OUT;
    }

    uint32_t found = 0;
    for(uint32_t i=1; i<(numVolumes + mesh->brep.numVolumes); i++) {
      if(compareSortedVolumes(&volumes[i-1], &volumes[i]) == 0) { // volumes are the same
        if(volumes[i-1].isFromOriginalBREP == volumes[i].isFromOriginalBREP) {
          return HXT_ERROR_MSG(HXT_STATUS_ERROR, "duplicate volume %u and %u in %s Brep "
                                                 "(volumes should be uniquely defined by the color of "
                                                 "their bounding surfaces)", volumes[i-1].color, volumes[i].color,
                                                 volumes[i].isFromOriginalBREP ? "original" : "reconstructed");
        }
        uint32_t original      = volumes[volumes[i].isFromOriginalBREP ? i   : i-1].color;
        uint32_t reconstructed = volumes[volumes[i].isFromOriginalBREP ? i-1 : i  ].color;

        volumeMap[reconstructed] = original;

        found++;
      }
    }

    HXT_CHECK( hxtAlignedFree(&surfacesPerVolume) );
    HXT_CHECK( hxtFree(&volumes) );

    if(found != mesh->brep.numVolumes)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "some volumes of the BRep were not found");

    // we give new number to all the volumes that are not in the BREP.
    uint32_t notMeshedVolume = mesh->brep.numVolumes;
    for(uint32_t i=0; i<numVolumes; i++) {
      if(volumeMap[i] == HXT_COLOR_OUT) {
        volumeMap[i] = notMeshedVolume++;
      }
    }

    // detect changes in the mapping:
    int changes = 0;
    for(uint32_t i=0; i<numVolumes; i++) {
      if(volumeMap[i] != i) {
        changes = 1;
        break;
      }
    }

    if(changes) {
      #pragma omp parallel for
      for(uint64_t i=0; i<mesh->tetrahedra.num; i++) {
        if(mesh->tetrahedra.color[i] == HXT_COLOR_OUT)
          continue;
        mesh->tetrahedra.color[i] = volumeMap[mesh->tetrahedra.color[i]];
      }
    }

    HXT_CHECK( hxtFree(&volumeMap) );

    HXT_INFO("All volumes of the BRep were found and colorized accordingly");
  }

  return HXT_STATUS_OK;
}


HXTStatus setFlagsToProcessOnlyVolumesInBrep(HXTMesh* mesh)
{
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.color[i]>=mesh->brep.numVolumes) {
      setProcessedFlag(mesh, i);
    }
    else {
#ifndef NDEBUG
      if(mesh->tetrahedra.node[4*i+3]==HXT_GHOST_VERTEX)
        exit( HXT_ERROR_MSG(HXT_STATUS_ERROR, "ghost tetrahedra should have exterior color") );
#endif
      unsetProcessedFlag(mesh, i);
    }
  }

  return HXT_STATUS_OK;
}



// TODO: compute a boundinng box following some surface mesh colors !
// we should get this bbox from the triangles (and not the tetrahedra) to be quick
// we should thus have a function that receive a volume color and receive a list of surface colors !