#include "hxt_mesh3d.h"
#include "hxt_tetDelaunay.h"
#include "hxt_tetRepair.h"
#include "hxt_tetUtils.h"
#include "hxt_tetFlag.h"
#include "hxt_tetColor.h"
#include "hxt_tetOpti.h"


HXTStatus hxtTetMesh3d(HXTMesh* mesh,
                      int defaulThreads,
                      int DelaunayThreads,
                      int optimizationThreads,
                      int reproducible,
                      int verbosity,
                      int displayStat,
                      int refine,
                      int optimize,
                      double qualityThreshold,
                      HXTStatus (*bnd_recovery)(HXTMesh* mesh),
                      double (*mesh_size)(double x, double y, double z, void* userData),
                      void* userData) {

  if(defaulThreads>0) {
    omp_set_num_threads(defaulThreads);
  }

  double t[8]={0};
  t[0] = omp_get_wtime();

  HXTBbox bbox;
  hxtBboxInit(&bbox);
  HXT_CHECK( hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num) );

  HXTDelaunayOptions delOptions = {&bbox, NULL, 0.0, 0.0, 0, verbosity, reproducible, DelaunayThreads};
  uint32_t numVerticesConstrained = mesh->vertices.num;
  
  HXT_INFO_COND(verbosity>0, "Creating an empty mesh with %u vertices", numVerticesConstrained);
  HXT_CHECK( hxtEmptyMesh(mesh, &delOptions) );

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
    if(bnd_recovery==NULL)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,
        "there are missing features but no boundary recovery function is given");

    if(nbMissingTriangles)
      HXT_INFO("Recovering %lu missing facet(s)", nbMissingTriangles);
    else if(nbMissingLines)
      HXT_INFO("Recovering %lu missing edge(s)", nbMissingLines);

    HXT_CHECK(bnd_recovery(mesh));

    if(delOptions.numVerticesInMesh < mesh->vertices.num) {
      HXT_INFO("Steiner(s) point(s) were inserted");
      delOptions.numVerticesInMesh = mesh->vertices.num;
    }

    t[3] = omp_get_wtime();

    HXT_CHECK( hxtGetTri2TetMap(mesh, tri2TetMap, &nbMissingTriangles) );
    if(nbMissingTriangles!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR,
        "%d boundary face%s still missing (after recovery step).",
        nbMissingTriangles, (nbMissingTriangles>1)?"s are":" is" );

    if(nbLinesNotInTriangles!=0)
      HXT_CHECK( hxtGetLines2TetMap(mesh, lines2TetMap, &nbMissingLines) );

    if(nbMissingLines!=0)
      return HXT_ERROR_MSG( HXT_STATUS_ERROR,
        "%d constrained edge%s still missing (after recovery step).",
        nbMissingLines, (nbMissingLines>1)?"s are":" is" );
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

  if(refine){
    // HXT_CHECK(hxtComputeMeshSizeFromMesh(mesh, &delOptions));
    if(mesh_size==NULL)
    	HXT_CHECK(hxtCreateNodalsizeFromTrianglesAndLines(mesh, &delOptions));
    else
    	HXT_CHECK(hxtCreateNodalSizeFromFunction(mesh, &delOptions, mesh_size, userData) );

    if(nbColors!=mesh->brep.numVolumes) {
      HXT_CHECK( setFlagsToProcessOnlyVolumesInBrep(mesh) );
    }

    HXT_CHECK(hxtRefineTetrahedra(mesh, &delOptions, mesh_size, userData));

    HXT_CHECK( hxtDestroyNodalsize(&delOptions) );
  }

  t[5] = omp_get_wtime();


  if(optimize)
    HXT_CHECK( hxtOptimizeTetrahedra(mesh, &bbox, optimizationThreads, delOptions.minSizeEnd, qualityThreshold, numVerticesConstrained) );

  t[6] = omp_get_wtime();

  
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

