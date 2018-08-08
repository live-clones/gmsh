#include "hxt_mesh3d.h"
#include "hxt_tetrahedra.h"
#include "hxt_tetRepair.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_tetOpti.h"

HXTStatus hxtTetMesh3d(HXTMesh* mesh,
                      int nthreads,
                      int reproducible,
                      int verbosity,
                      int displayStat,
                      int refine,  // refine if !=0
                      int optimize,// optimize quality if !=0
                      double qualityThreshold,
                      HXTStatus (*bnd_recovery)(HXTMesh* mesh)) {
  double t[8]={0};
  t[0] = omp_get_wtime();

  HXTBbox bbox;
  hxtBboxInit(&bbox);
  HXT_CHECK( hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num) );

  HXTDelaunayOptions delOptions = {&bbox, NULL, 0.0, 0.0, 0, verbosity, reproducible, nthreads};
  uint32_t numVerticesConstrained = mesh->vertices.num;
  
  HXT_INFO_COND(verbosity>0, "Creating an empty mesh with %u vertices", numVerticesConstrained);
  HXT_CHECK( hxtEmptyMesh(mesh, &delOptions) );

  t[1] = omp_get_wtime();

  uint64_t nbMissingFacets, nbMissingEdges=0;
  uint16_t nbColors;
  HXT_CHECK( hxtConstrainTriangles(mesh, &nbMissingFacets) );
  if(nbMissingFacets==0) // TODO: differentiating missing triangles and missing edges ??
    HXT_CHECK( hxtConstrainEdgesNotInTriangles(mesh, &nbMissingEdges) );

  t[2] = omp_get_wtime();

  if (nbMissingFacets != 0 || nbMissingEdges!=0){
    if(bnd_recovery==NULL)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,
        "there are missing features but no boundary recovery function is given");
    if(nbMissingFacets)
      HXT_INFO("Recovering %lu missing facet(s)", nbMissingFacets);
    else if(nbMissingEdges)
      HXT_INFO("Recovering %lu missing edge(s)", nbMissingEdges);
    HXT_CHECK(bnd_recovery(mesh));

    if(delOptions.numVerticesInMesh < mesh->vertices.num) {
      HXT_INFO("Steiner(s) point(s) were inserted");
      delOptions.numVerticesInMesh = mesh->vertices.num;
    }

    t[3] = omp_get_wtime();

    memset(mesh->tetrahedra.flag, 0, mesh->tetrahedra.num*sizeof(uint16_t));
    HXT_CHECK(hxtTetOrientNodes(mesh));
    HXT_CHECK(hxtTetAdjacencies(mesh));
    HXT_CHECK(hxtAddGhosts(mesh));
    // HXT_CHECK( hxtTetVerify(mesh) );

    HXT_CHECK( hxtConstrainTriangles(mesh, &nbMissingFacets) );
    if(nbMissingFacets!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR,
        "%d boundary face%s still missing (after recovery step).",
        nbMissingFacets, (nbMissingFacets>1)?"s are":" is" );

    HXT_CHECK( hxtConstrainEdgesNotInTriangles(mesh, &nbMissingEdges) );
    if(nbMissingEdges!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR,
        "%d constrained edge%s still missing (after recovery step).",
        nbMissingEdges, (nbMissingEdges>1)?"s are":" is" );
  }

  HXT_CHECK(hxtColorMesh(mesh, &nbColors));

#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );

  memset(mesh->tetrahedra.flag, 0, mesh->tetrahedra.num*sizeof(uint16_t));
  HXT_CHECK( hxtConstrainTriangles(mesh, &nbMissingFacets) );
  if(nbMissingFacets!=0)
    return HXT_ERROR_MSG( HXT_STATUS_ERROR,
      "%d boundary face%s still missing (after refine).",
      nbMissingFacets, (nbMissingFacets>1)?"s are":" is" );

  HXT_CHECK( hxtConstrainEdgesNotInTriangles(mesh, &nbMissingEdges) );
  if(nbMissingEdges!=0)
    return HXT_ERROR_MSG( HXT_STATUS_ERROR,
      "%d constrained edge%s still missing (after refine).",
      nbMissingEdges, (nbMissingEdges>1)?"s are":" is" );
#endif

  t[4] = omp_get_wtime();

  if(refine){
    // HXT_CHECK(hxtComputeMeshSizeFromMesh(mesh, &delOptions));
    HXT_CHECK(hxtComputeMeshSizeFromTrianglesAndLines(mesh, &delOptions));

    // // triangulate only one color
    // if(color>=0) {
    //   #pragma omp parallel for simd
    //   for (uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    //     if(mesh->tetrahedra.colors[i]!=theColor){
    //       markTetAsProcessed(mesh,i) = 1;
    //     }
    //   }
    // }

    
    HXTMeshSize *meshSize = NULL;
    // HXT_CHECK(hxtMeshSizeCreate (context,&meshSize));
    // HXT_CHECK(hxtMeshSizeCompute (meshSize, bbox.min, bbox.max, mySize, NULL));
    //    printf("time from empty mesh to first insertion: %f second\n", omp_get_wtime() - time);
    HXT_CHECK(hxtRefineTetrahedra(mesh, &delOptions, meshSize));
    // HXT_CHECK(hxtMeshSizeDelete (&meshSize));
    HXT_CHECK(hxtAlignedFree(&delOptions.nodalSizes));
    // #endif
  }

  t[5] = omp_get_wtime();

#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );

  memset(mesh->tetrahedra.flag, 0, mesh->tetrahedra.num*sizeof(uint16_t));
  HXT_CHECK( hxtConstrainTriangles(mesh, &nbMissingFacets) );
  if(nbMissingFacets!=0)
    return HXT_ERROR_MSG( HXT_STATUS_ERROR,
      "%d boundary face%s still missing (after refine).",
      nbMissingFacets, (nbMissingFacets>1)?"s are":" is" );

  HXT_CHECK( hxtConstrainEdgesNotInTriangles(mesh, &nbMissingEdges) );
  if(nbMissingEdges!=0)
    return HXT_ERROR_MSG( HXT_STATUS_ERROR,
      "%d constrained edge%s still missing (after refine).",
      nbMissingEdges, (nbMissingEdges>1)?"s are":" is" );
#endif

  if(optimize)
    HXT_CHECK( hxtOptimizeTetrahedra(mesh, &bbox, delOptions.minSizeEnd, qualityThreshold, numVerticesConstrained) );

  t[6] = omp_get_wtime();


#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );

  memset(mesh->tetrahedra.flag, 0, mesh->tetrahedra.num*sizeof(uint16_t));
  HXT_CHECK( hxtConstrainTriangles(mesh, &nbMissingFacets) );
  if(nbMissingFacets!=0)
    return HXT_ERROR_MSG( HXT_STATUS_ERROR,
      "%d boundary face%s still missing (after refine).",
      nbMissingFacets, (nbMissingFacets>1)?"s are":" is" );

  HXT_CHECK( hxtConstrainEdgesNotInTriangles(mesh, &nbMissingEdges) );
  if(nbMissingEdges!=0)
    return HXT_ERROR_MSG( HXT_STATUS_ERROR,
      "%d constrained edge%s still missing (after refine).",
      nbMissingEdges, (nbMissingEdges>1)?"s are":" is" );
#endif

  
  if(displayStat){
    HXT_INFO("\n\t\tFinal tet. mesh contains %lu tetrahedra"
             "\n\t\tand                      %u vertices", mesh->tetrahedra.num, mesh->vertices.num);

    HXT_INFO("tEmptyMesh  \t = \t %8.3f", t[1]-t[0]);
    HXT_INFO("tVerifyBnd  \t = \t %8.3f", t[2]-t[1]);
    if(t[3]){
      HXT_INFO("tBndRecovery\t = \t %8.3f", t[3]-t[2]);
      HXT_INFO("tConvertMesh\t = \t %8.3f", t[4]-t[3]);
      if(refine)
        HXT_INFO("tRefine     \t = \t %8.3f", t[5]-t[4]);
    }
    else{
      HXT_INFO("tBndRecovery\t = \t    0.000 (boundary not altered)");
      HXT_INFO("tConvertMesh\t = \t    0.000 (nothing to convert)");
      if(refine)
        HXT_INFO("tRefine     \t = \t %8.3f", t[5]-t[2]);
    }

    if(!optimize)
      HXT_INFO("tOptimize   \t = \t    0.000 (mesh optimization disabled)");
    else
      HXT_INFO("tOptimize   \t = \t %8.3f", t[6]-t[5]);
  }

  return HXT_STATUS_OK;
}

