#include "hxt_tetColor.h"
#include "hxt_tetFlag.h"
#include "hxt_sort.h"


/***************************************************
 *      Coloring the mesh                          *
 ***************************************************/
HXTStatus hxtColorMesh(HXTMesh* mesh, uint16_t *nbColors) {
  uint64_t *stack;
  HXT_CHECK(hxtMalloc(&stack,mesh->tetrahedra.num*sizeof(uint64_t))); 
  // now that tetrahedra are flaged, we can proceed to colorize the mesh
  memset(mesh->tetrahedra.colors, 0, mesh->tetrahedra.size*sizeof(uint16_t));

  uint16_t color = 1;
  uint16_t colorOut = 0;

  while (1){
    uint64_t stackSize = 0;
    uint64_t first = UINT64_MAX;

    for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
      if(mesh->tetrahedra.colors[i]==0){
        first = i;
        break;
      }
    }

    if(first==UINT64_MAX)
      break;

    stack[stackSize++] = first;
    mesh->tetrahedra.colors[first] = color;

    for (uint64_t i=0; i<stackSize; i++) {
      uint64_t t = stack[i];

      if (mesh->tetrahedra.node[4*t+3] == HXT_GHOST_VERTEX)
        colorOut = color;

      for (unsigned j=0; j<4; j++) {
        if(mesh->tetrahedra.neigh[4*t+j]!=HXT_NO_ADJACENT && getFacetConstraint(mesh, t, j)==0){ // the facet is not a boundary facet
          uint64_t neigh = mesh->tetrahedra.neigh[4*t+j]/4;
          if(mesh->tetrahedra.colors[neigh]==0){
            stack[stackSize++] = neigh;
            mesh->tetrahedra.colors[neigh] = color;
          }
        }
      }
    }
    color++;
  }
  *nbColors = color-2; // -2 because we began at one AND because colorout is not counted...

  HXT_CHECK( hxtFree(&stack) );

  #pragma omp parallel for
  for (uint64_t i=0;i<mesh->tetrahedra.num;i++){
    if (mesh->tetrahedra.colors[i] == colorOut){
      mesh->tetrahedra.colors[i] = UINT16_MAX;
    }
    else if(mesh->tetrahedra.colors[i] > colorOut){
      mesh->tetrahedra.colors[i]-=2;
    }
    else {
      mesh->tetrahedra.colors[i]--;
    }
  }

  return HXT_STATUS_OK;
}



HXTStatus hxtFillVolumeBrep(HXTMesh* mesh, uint64_t* tri2TetMap,
                            uint16_t numVolumes, uint16_t** numSurfacesPerVolume_ptr, uint16_t** surfacesPerVolume_ptr)
{
  int nbTriangleColor = 0;
  uint16_t colorTriMax = 0;
  char triangleColor[65536] = {0};

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->triangles.num; i++) {
    #pragma omp atomic write
    triangleColor[mesh->triangles.colors[i]] = 1;
  }

  #pragma omp parallel for reduction(+: nbTriangleColor) reduction(max: colorTriMax)
  for (unsigned i=0; i<65536; i++) {
    if(triangleColor[i]==1) {
      nbTriangleColor++;
      triangleColor[i] = 0;
      if(i>colorTriMax)
        colorTriMax = i;
    }
  }

  uint16_t* numSurfacesPerVolume;
  uint16_t* surfacesPerVolume;
  HXT_CHECK( hxtAlignedMalloc(&numSurfacesPerVolume, sizeof(uint16_t)*numVolumes) );

  // a surface can only appear in two volumes. (this allocate to much, but usually not by a lot)
  HXT_CHECK( hxtAlignedMalloc(&surfacesPerVolume, sizeof(uint16_t)*nbTriangleColor*2) );

  const int maxThreads = omp_get_max_threads();
  int *numColors;
  HXT_CHECK( hxtAlignedMalloc(&numColors, maxThreads*sizeof(int)) );

  int currentSurfaceIndex = 0;
  int totalCount = 0;
  
  #pragma omp parallel
  {
    // for every tet-color
    for (uint16_t color=0; color<numVolumes; color++) {
      #pragma omp for
      for (uint64_t tri=0; tri<mesh->triangles.num; tri++) {
        // the tetrahedra on both sides of the triangle
        uint64_t tet1 = tri2TetMap[tri];
        uint64_t tet2 = mesh->tetrahedra.neigh[tet1];
        tet1/=4;
        tet2/=4;

        // we do a xor because the surface is not a bounding if the same volume is on both its sides
        if((mesh->tetrahedra.colors[tet1]==color)^(mesh->tetrahedra.colors[tet2]==color)) {
          #pragma omp atomic write // this atomic should do nothing (it usually is already atomic)
          triangleColor[mesh->triangles.colors[tri]] = 1;
        }
      }

      int threadID = omp_get_thread_num();
      int localCount = 0;

      #pragma omp for schedule(static)
      for (uint16_t i=0; i<=colorTriMax; i++) {
        if(triangleColor[i]==1) {
          localCount++;
        }
      }

      numColors[threadID] = localCount;

      #pragma omp barrier
      #pragma omp single
      {
        int nthreads = omp_get_num_threads();
        currentSurfaceIndex+=totalCount;
        totalCount = 0;
        for (int thread=0; thread<nthreads; thread++) {
          int tsum = totalCount + numColors[thread];
          numColors[thread] = totalCount;
          totalCount = tsum;
        }

        numSurfacesPerVolume[color] = totalCount;
      }

      #pragma omp for schedule(static)
      for (uint16_t i=0; i<=colorTriMax; i++) {
        if(triangleColor[i]==1) {
          surfacesPerVolume[currentSurfaceIndex + numColors[threadID]] = i;
          numColors[threadID]++;
          triangleColor[i] = 0;
        }
      }
    }
  }

  *numSurfacesPerVolume_ptr = numSurfacesPerVolume;
  *surfacesPerVolume_ptr = surfacesPerVolume;
  
  HXT_CHECK( hxtAlignedFree(&numColors) );

  return HXT_STATUS_OK;
}


static int compareVolumes(uint16_t numSurfaces1,
                          uint16_t numSurfaces2,
                          uint16_t* surfaces1,
                          uint16_t* surfaces2)
{
  if(numSurfaces1<numSurfaces2)
    return -1;
  else if(numSurfaces1>numSurfaces2)
    return 1;

  int diff = 0;
  uint64_t* surface1Sorted;
  uint64_t* surface2Sorted;
  HXT_CHECK( hxtAlignedMalloc(&surface1Sorted, numSurfaces1*sizeof(uint64_t)) );
  HXT_CHECK( hxtAlignedMalloc(&surface2Sorted, numSurfaces1*sizeof(uint64_t)) );

  uint64_t max1 = 0;
  uint64_t max2 = 0;
  for (uint16_t i=0; i<numSurfaces1; i++) {
    surface1Sorted[i] = surfaces1[i];
    if(surfaces1[i]>max1)
      max1 = surfaces1[i];
    surface2Sorted[i] = surfaces2[i];
    if(surfaces2[i]>max2)
      max2 = surfaces2[i];
  }

  if(max1!=max2) {
    diff = max1 - max2;
    goto endGoto;
  }

  HXT_CHECK( group1_sort(surface1Sorted, numSurfaces1, max1) );
  HXT_CHECK( group1_sort(surface2Sorted, numSurfaces1, max1) );


  for (uint16_t i=0; i<numSurfaces1; i++) {
    if(surface1Sorted[i]!=surface2Sorted[i]) {
      diff = surface1Sorted[i]-surface2Sorted[i];
      goto endGoto;
    }
  }

endGoto:
  HXT_CHECK( hxtAlignedFree(&surface1Sorted) );
  HXT_CHECK( hxtAlignedFree(&surface2Sorted) );

  return diff;
}


static inline HXTStatus swapPairsIfNeeded(uint16_t numVolumes,
                                         uint16_t* numSurfacesPerVolume,
                                         uint16_t* surfacesPerVolume,
                                         HXTGroup2* pairs)
{
  int alreadySwapped = 0;
  for (int i=1; i<numVolumes; i++) {
    if(pairs[i-1].v[1]==pairs[i].v[1]){
      int vol1 = pairs[i-1].v[0];
      int vol2 = pairs[i].v[0];
      uint16_t start1 = numSurfacesPerVolume[vol1-1];
      uint16_t end1 = numSurfacesPerVolume[vol1];
      uint16_t start2 = numSurfacesPerVolume[vol2-1];
      uint16_t end2 = numSurfacesPerVolume[vol2];
      int comp = compareVolumes(end1-start1, end2-start2,
                                &surfacesPerVolume[start1],
                                &surfacesPerVolume[start2]);
      if(comp > 0) {
        if(alreadySwapped)
          return HXT_ERROR_MSG(HXT_STATUS_ERROR, "The minimum surface of volume %d and %d appears more than twice...", vol1, vol2);
        HXTGroup2 tmp = pairs[i-1];
        pairs[i-1] = pairs[i];
        pairs[i] = tmp;
        alreadySwapped = 1;
      }
      else if (comp==0) {
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "duplicated volume definition in the BREP");
      }
      else {
        alreadySwapped = 0;
      }
    }
  }
  return HXT_STATUS_OK;
}


static HXTStatus getVolumesHashes(uint16_t numVolumes,
                                  uint16_t* numSurfacesPerVolume,
                                  uint16_t* surfacesPerVolume,
                                  HXTGroup2* pairs)
{
  uint16_t maxMin = 0;

  #pragma omp parallel for reduction(max:maxMin)
  for (int vol=0; vol<numVolumes; vol++) {
    pairs[vol].v[0] = vol;
    uint16_t start = vol==0?0:numSurfacesPerVolume[vol-1];
    uint16_t end = numSurfacesPerVolume[vol];

    uint64_t hash = 0;
    uint16_t minimum = UINT16_MAX;
    while(start<end) {
      uint16_t s = surfacesPerVolume[start++];

      hash ^= (UINT64_C(1)<<(s & 31));
      if(s < minimum)
        minimum = s;
    }

    if(minimum > maxMin)
      maxMin = minimum;

    hash |= (uint64_t) minimum << 32;
    pairs[vol].v[1] = hash;
  }

  HXT_CHECK( group2_sort_v1(pairs, numVolumes, (uint64_t) maxMin << 32) );

  // it can happen that two volumes have the same hash. We must give them a unique order
  HXT_CHECK( swapPairsIfNeeded(numVolumes, numSurfacesPerVolume, surfacesPerVolume, pairs) );

  return HXT_STATUS_OK;
}


static HXTStatus matchVolumes(HXTMesh* mesh, uint16_t* numSurfacesPerVolume, uint16_t* surfacesPerVolume, uint16_t nbColors)
{
  HXTGroup2* ourPairs;
  const uint16_t ourNumVolumes = nbColors;
  const uint16_t theirNumVolumes = mesh->brep.numVolumes;
  HXT_CHECK( hxtAlignedMalloc(&ourPairs, 2*ourNumVolumes*sizeof(HXTGroup2) ) );
  HXTGroup2* theirPairs = ourPairs + ourNumVolumes;

  // we make a scan so that we can do things in parallel...
  int theirSum = 0;
  for (uint16_t vol=0; vol<theirNumVolumes; vol++) {
    theirSum+=mesh->brep.numSurfacesPerVolume[vol];
    mesh->brep.numSurfacesPerVolume[vol] = theirSum;
  }

  int ourSum = 0;
  for (uint16_t vol=0; vol<ourNumVolumes; vol++) {
    ourSum+=numSurfacesPerVolume[vol];
    numSurfacesPerVolume[vol] = ourSum;
  }

  HXT_CHECK( getVolumesHashes(ourNumVolumes,
                              numSurfacesPerVolume,
                              surfacesPerVolume, ourPairs) );
  HXT_CHECK( getVolumesHashes(theirNumVolumes,
                              mesh->brep.numSurfacesPerVolume,
                              mesh->brep.surfacesPerVolume, theirPairs) );

  // now that we sorted every volumes, see if they match
  // ourPair contains all volumes, while ourPairs can skip some volumes...
  int ourIndex = 0;
  int volNotCorresponding = theirNumVolumes;
  for (int theirIndex=0; theirIndex<theirNumVolumes; theirIndex++) {
    while (1) {

      if(ourIndex>=ourNumVolumes)
        return HXT_ERROR_MSG(HXT_STATUS_ERROR, "Volumes do not match the BREP");
      
      if(ourPairs[ourIndex].v[1]==theirPairs[theirIndex].v[1]){
        if(ourIndex<ourNumVolumes-1 && ourPairs[ourIndex+1].v[1]==ourPairs[ourIndex].v[1]) {
          // we have to check further because there was a collision in the hashes
          uint16_t ourVol = ourPairs[ourIndex].v[0];
          uint16_t theirVol = theirPairs[theirIndex].v[0];

          uint16_t ourStart = ourVol==0? 0:numSurfacesPerVolume[ourVol-1];
          uint16_t ourEnd = numSurfacesPerVolume[ourVol];
          uint16_t theirStart = theirVol==0? 0:mesh->brep.numSurfacesPerVolume[theirVol-1];
          uint16_t theirEnd = mesh->brep.numSurfacesPerVolume[theirVol];

          int cmp = compareVolumes(ourEnd - ourStart, theirEnd - theirStart, 
                                   &surfacesPerVolume[ourStart], &mesh->brep.surfacesPerVolume[theirStart]);

          if(cmp==0) {
            ourPairs[ourIndex++].v[1] = theirPairs[theirIndex].v[0];
            break;
          }
        }
        else {
          ourPairs[ourIndex++].v[1] = theirPairs[theirIndex].v[0];
          break;
        }
      }

      ourPairs[ourIndex++].v[1] = volNotCorresponding++;
    }
  }

  while(ourIndex<ourNumVolumes) {
    ourPairs[ourIndex++].v[1] = volNotCorresponding++;
  }

  #pragma omp parallel for
  for (int i=0; i<ourNumVolumes; i++) {
    uint16_t ourVol = ourPairs[i].v[0];
    uint16_t theirVol = ourPairs[i].v[1];

    theirPairs[ourVol].v[1] = theirVol;
  }

  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    uint16_t color = mesh->tetrahedra.colors[i];
    if(color!=UINT16_MAX) {
      mesh->tetrahedra.colors[i] = theirPairs[color].v[1];
    }
  }

  #pragma omp parallel for
  for (int vol=0; vol<theirNumVolumes; vol++) {
    uint16_t start = vol==0?0:mesh->brep.numSurfacesPerVolume[vol-1];
    uint16_t end = mesh->brep.numSurfacesPerVolume[vol];
    mesh->brep.numSurfacesPerVolume[vol] = end-start;
  }

  HXT_CHECK( hxtAlignedFree(&ourPairs) );

  return HXT_STATUS_OK;
}



HXTStatus hxtMapColorsToBrep(HXTMesh* mesh, uint16_t nbColors, uint64_t* tri2TetMap)
{
  if(mesh->brep.numVolumes==0) {
  #ifndef NDEBUG
    if(mesh->brep.numSurfacesPerVolume!=NULL) {
      HXT_WARNING("mesh->brep.numSurfacesPerVolume is not null but numVolumes=0\nAttempting to free it");
      HXT_CHECK( hxtFree(&mesh->brep.numSurfacesPerVolume) );
    }
    if(mesh->brep.surfacesPerVolume!=NULL) {
      HXT_WARNING("mesh->brep.surfacesPerVolume is not null but numVolumes=0\nAttempting to free it");
      HXT_CHECK( hxtFree(&mesh->brep.surfacesPerVolume) );
    }
  #endif
    mesh->brep.numVolumes = nbColors;
    
    HXT_CHECK( hxtFillVolumeBrep(mesh, tri2TetMap,
                              nbColors,
                              &mesh->brep.numSurfacesPerVolume,
                              &mesh->brep.surfacesPerVolume) );
  }
  else {
    if(mesh->brep.numVolumes>nbColors)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR, "brep contains more volumes than there really are !");

    if(mesh->brep.numVolumes<nbColors)
      HXT_INFO("%u out of %u volumes will be refined", mesh->brep.numVolumes, nbColors);
    

    // match our brep with the brep given...
    uint16_t* numSurfacesPerVolume;
    uint16_t* surfacesPerVolume;
    HXT_CHECK( hxtFillVolumeBrep(mesh, tri2TetMap,
                              nbColors,
                              &numSurfacesPerVolume,
                              &surfacesPerVolume) );

    HXT_CHECK( matchVolumes(mesh, numSurfacesPerVolume, surfacesPerVolume, nbColors) );


    HXT_CHECK( hxtAlignedFree( &numSurfacesPerVolume ) );
    HXT_CHECK( hxtAlignedFree( &surfacesPerVolume ) );
  }


  return HXT_STATUS_OK;
}


HXTStatus setFlagsToProcessOnlyVolumesInBrep(HXTMesh* mesh)
{
  #pragma omp parallel for
  for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    if(mesh->tetrahedra.colors[i]>=mesh->brep.numVolumes) {
      setProcessedFlag(mesh, i);
    }
  }

  return HXT_STATUS_OK;
}



// TODO: compute a boundinng box following some surface mesh colors !
// we should get this bbox from the triangles (and not the tetrahedra) to be quick
// we should thus have a function that receive a volume color and receive a list of surface colors !