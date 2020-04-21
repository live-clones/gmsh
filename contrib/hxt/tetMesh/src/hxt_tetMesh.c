// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetRefine.h"
#include "hxt_tetNodalSize.h"
#include "hxt_tetRepair.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_tetColor.h"
#include "hxt_tetOpti.h"

#include "hxt_tetMesh.h"
#include "hxt_tetQuality.h"
#include "hxt_omp.h"

// void aspect_ratio_graph(HXTMesh* mesh) {
//     // make a count of aspect ratio...
//   unsigned bins[21] = {0};

//   for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
//     if(mesh->tetrahedra.node[4*i+3]==HXT_GHOST_VERTEX)
//       continue;
//     if(mesh->tetrahedra.colors[i]==UINT16_MAX)
//       continue;
//     double* a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+0];
//     double* b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+1];
//     double* c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+2];
//     double* d = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*i+3];
//     int aspect = 20.0*sqrt(24.0*hxtTetAspectFastRatio(a,b,c,d));
//     bins[aspect]++;
//   }

//   puts("aspect ratio per 5%%");
//   for (int i=0; i<21; i++) {
//     printf("%.2f %u \\\\\n", (double) i/20, bins[i]);
//   }

//   printf("a<0.15 %u\n", bins[0]+bins[1]+bins[2]);
//   printf("0.15<a<0.35 %u\n", bins[3]+bins[4]+bins[5]+bins[6]);
//   printf("0.35<a<0.65 %u\n", bins[7]+bins[8]+bins[9]+bins[10]+bins[11]+bins[12]);
//   printf("0.65<a %u\n", bins[13]+bins[14]+bins[15]+bins[16]+bins[17]+bins[18]+bins[19]+bins[20]);
// }


HXTStatus hxtTetMesh(HXTMesh* mesh,
                     HXTTetMeshOptions* options) {

  if(options->defaultThreads>0) {
    omp_set_num_threads(options->defaultThreads);
  }

  double t[8]={0};
  t[0] = omp_get_wtime();

  HXTBbox bbox;
  hxtBboxInit(&bbox);
  hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num);

  HXTDelaunayOptions delOptions = {.bbox = &bbox,
                                   .verbosity = options->verbosity,
                                   .reproducible = options->reproducible,
                                   .delaunayThreads = options->delaunayThreads};

  uint32_t numVerticesConstrained = mesh->vertices.num;
  
  HXT_INFO_COND(options->verbosity>0, "Creating an empty mesh with %u vertices", numVerticesConstrained);
  HXT_CHECK( hxtEmptyMesh(mesh, &delOptions) );
  HXT_INFO_COND(options->verbosity>1, "Empty mesh finished\n");

  t[1] = omp_get_wtime();

  uint64_t nbMissingTriangles, nbLinesNotInTriangles, nbMissingLines=0;
  uint16_t nbColors;
  uint64_t* tri2TetMap = NULL;
  uint64_t* lines2TriMap = NULL;
  uint64_t* lines2TetMap = NULL;

  HXT_CHECK( hxtAlignedMalloc(&tri2TetMap, mesh->triangles.num*sizeof(uint64_t)) );
  HXT_CHECK( hxtAlignedMalloc(&lines2TriMap, mesh->lines.num*sizeof(uint64_t)) );
  
  HXT_CHECK( hxtGetTri2TetMap(mesh, tri2TetMap, &nbMissingTriangles) );
  HXT_CHECK( hxtGetLines2TriMap(mesh, lines2TriMap, &nbLinesNotInTriangles) );

  if(nbLinesNotInTriangles!=0) {
    HXT_CHECK( hxtAlignedMalloc(&lines2TetMap, mesh->lines.num*sizeof(uint64_t)) );
    if(nbMissingTriangles==0) {
      HXT_CHECK( hxtGetLines2TetMap(mesh, lines2TetMap, &nbMissingLines) );
    }
  }


  t[2] = omp_get_wtime();

  if (nbMissingTriangles!=0 || nbMissingLines!=0){
    if(options->recoveryFun==NULL)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,
        "there are missing features but no boundary recovery function is given");

    if(nbMissingTriangles)
      HXT_INFO("Recovering %" HXTu64 " missing facet(s)",
               nbMissingTriangles);
    else if(nbMissingLines)
      HXT_INFO("Recovering %" HXTu64 " missing edge(s)",
               nbMissingLines);

    HXT_CHECK(options->recoveryFun(mesh, options->recoveryData));

    if(delOptions.numVerticesInMesh < mesh->vertices.num) {
      HXT_INFO("Steiner(s) point(s) were inserted");
      delOptions.numVerticesInMesh = mesh->vertices.num;
    } 

    t[3] = omp_get_wtime();

    HXT_CHECK( hxtGetTri2TetMap(mesh, tri2TetMap, &nbMissingTriangles) );
    if(nbMissingTriangles!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR,
        "%" HXTu64 " boundary face%s still missing (after recovery step).",
        nbMissingTriangles, (nbMissingTriangles>1)?"s are":" is" );

    if(nbLinesNotInTriangles!=0)
      HXT_CHECK( hxtGetLines2TetMap(mesh, lines2TetMap, &nbMissingLines) );

    if(nbMissingLines!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR,
        "%" HXTu64 " constrained edge%s still missing (after recovery step).",
        nbMissingLines, (nbMissingLines>1)?"s are":" is" );

    HXT_INFO_COND(options->verbosity>1,"Constrained lines and triangles recovered\n");
  }

  HXT_CHECK( hxtConstrainTriangles(mesh, tri2TetMap) );
  
  if(nbLinesNotInTriangles!=0)
    HXT_CHECK( hxtConstrainLinesNotInTriangles(mesh, lines2TetMap, lines2TriMap) );

  HXT_CHECK( hxtColorMesh(mesh, &nbColors) );

  HXT_CHECK( hxtMapColorsToBrep(mesh, nbColors, tri2TetMap) );

  HXT_CHECK( hxtAlignedFree(&tri2TetMap) );
  HXT_CHECK( hxtAlignedFree(&lines2TetMap) );
  HXT_CHECK( hxtAlignedFree(&lines2TriMap) );

  t[4] = omp_get_wtime();

  if(options->refine){
    // HXT_CHECK(hxtComputeMeshSizeFromMesh(mesh, &delOptions));
    if(options->meshSizeFun==NULL)
      HXT_CHECK(hxtCreateNodalsizeFromTrianglesAndLines(mesh, &delOptions.nodalSizes));
    else
      HXT_CHECK(hxtCreateNodalSizeFromFunction(mesh, &delOptions.nodalSizes, options->meshSizeFun, options->meshSizeData) );

    HXT_CHECK( setFlagsToProcessOnlyVolumesInBrep(mesh) );

    HXT_CHECK(hxtRefineTetrahedra(mesh, &delOptions, options->meshSizeFun, options->meshSizeData));

    HXT_CHECK( hxtDestroyNodalsize(&delOptions.nodalSizes) );

    HXT_INFO_COND(options->verbosity>1, "Mesh refinement finished\n");
  }

  t[5] = omp_get_wtime();

  // aspect_ratio_graph(mesh);

  if(options->optimize) {
    HXT_CHECK( setFlagsToProcessOnlyVolumesInBrep(mesh) );

    HXT_CHECK( hxtOptimizeTetrahedra(mesh,
                                     &(HXTOptimizeOptions) {
                                       .bbox = &bbox,
                                       .qualityFun = options->qualityFun,
                                       .qualityData = options->qualityData,
                                       .qualityMin = options->qualityMin,
                                       .numThreads = options->improveThreads,
                                       .numVerticesConstrained = numVerticesConstrained,
                                       .verbosity = options->verbosity,
                                       .reproducible = options->reproducible
                                     } ) );
    HXT_INFO_COND(options->verbosity>1, "Mesh improvement finished\n");
  }

  // aspect_ratio_graph(mesh);
  t[6] = omp_get_wtime();

  
  if(options->stat){
    HXT_INFO(" \tFinal tet. mesh contains %" HXTu64 " tetrahedra", mesh->tetrahedra.num);
    HXT_INFO(" \tFinal tet. mesh contains %u vertices", mesh->vertices.num);
    HXT_INFO("tEmptyMesh  \t = \t %8.3f", t[1]-t[0]);
    HXT_INFO("tVerifyBnd  \t = \t %8.3f", t[2]-t[1]);
    if(t[3]){
      HXT_INFO("tBndRecovery\t = \t %8.3f", t[3]-t[2]);
      HXT_INFO("tConvertMesh\t = \t %8.3f", t[4]-t[3]);
      if(options->refine)
        HXT_INFO("tRefine     \t = \t %8.3f", t[5]-t[4]);
    }
    else{
      HXT_INFO("tBndRecovery\t = \t    0.000 (boundary not altered)");
      HXT_INFO("tConvertMesh\t = \t    0.000 (nothing to convert)");
      if(options->refine)
        HXT_INFO("tRefine     \t = \t %8.3f", t[5]-t[2]);
    }

    if(options->optimize)
      HXT_INFO("tOptimize   \t = \t %8.3f", t[6]-t[5]);
    else
      HXT_INFO("tOptimize   \t = \t    0.000 (mesh optimization disabled)");
  }

  HXT_INFO_COND(options->verbosity>1, "Mesh generated\n");

  return HXT_STATUS_OK;
}

