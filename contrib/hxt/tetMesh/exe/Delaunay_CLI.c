// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetDelaunay.h"
#include "hxt_opt.h"
#include "hxt_omp.h"


int main(int argc, char** argv) {

  const char* input = NULL;
  const char* output = NULL;
  int nthreads = 0;
  int reproducible = 0;
  int verbosity = 1;
  int stat = 0;
  int preserve_order = 0;
  uint32_t nvert = 0;


  HXT_CHECK( hxtAddOption('i', "input", "Input file in the MSH ASCII file format", HXT_EXISTING_FILENAME, NULL, &input));
  HXT_CHECK( hxtAddOption('G', "generate",
                          "Generate N random points following a uniform\n"
                          "distribution inside the unit cube.\n"
                          "This option is ignored if an input file is given", HXT_U32, NULL, &nvert) );
  HXT_CHECK( hxtAddOption('t', "threads",
                          "Number of threads to use.\n"
                          " * NUM=0 use OMP_NUM_THREADS\n"
                          " * NUM<0 use OMP_NUM_PROCS", HXT_INT, NULL, &nthreads) );
  HXT_CHECK( hxtAddOption('r', "reproducible",
                          "Delaunay will always produce the same tetrahedra\n"
                          "given the same points in the same order.\n"
                          "However, the order in which tetrahedra end up\n"
                          "can differ when using multiple threads.\n"
                          "This option re-order tetrahedra to obtain\n"
                          "a reproducible ouput mesh", HXT_FLAG, NULL, &reproducible) );
  HXT_CHECK( hxtAddOption('v', "verbosity",
                          "Verbosity level of output messages\n"
                          " * NUM=0            : print no information\n"
                          " * NUM=1            : print some information\n"
                          " * NUM=2 or ommited : print all information", HXT_INT, &HXT_0_2_RANGE, &verbosity));
  HXT_CHECK( hxtAddOption('s', "stat",
                          "Print timing for each portion of the program", HXT_FLAG, NULL, &stat) );
  HXT_CHECK( hxtAddOption('p', "preserve-pts-order",
                          "Do not optimize points ordering\n"
                          "The initial ordering of points is preserved\nbut the program is slower", HXT_FLAG, NULL, &preserve_order) );

  HXT_CHECK( hxtAddTrailingOption("OUTPUT_FILE", HXT_STRING, NULL, &output));

  HXT_PARSE_COMMAND_LINE(argc, argv,
                         "hxtDelaunay",
                         "Compute the Delaunay of a set of points. The tetrahedral mesh OUTPUT_FILE is written in the MSH ASCII format",
                         "Example:\n\thxtDelaunay -st4 input.msh output.msh\n--\nContact: celestin.marot@uclouvain.be");

  if(input==NULL && nvert<=0){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR ,"No point to triangulate (use -h or --help for help message)");
  }

  /*******************************************************************************
   * All options were verified, we can do the Delaunay now...
   ******************************************************************************/

  double t0=0,t1=0,t2=0,t3=0;

  if(stat)
    t0 = omp_get_wtime();

  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(&mesh));

  if(input!=NULL) {
    HXT_INFO_COND(verbosity>0, "Reading \"%s\"", input);
    HXT_CHECK(hxtMeshReadGmsh(mesh, input) );

    if(mesh->tetrahedra.num!=0){
      HXT_WARNING("Mesh file \"%s\" already contains volumes. We delete them",input);

      //tetrahedra
      HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.color) );
      HXT_CHECK( hxtAlignedFree(&mesh->tetrahedra.node) );
      mesh->tetrahedra.num = 0;
      mesh->tetrahedra.size = 0;
    }
    if((mesh->lines.num!=0 || mesh->triangles.num!=0) && !preserve_order) {
      HXT_WARNING("Mesh file \"%s\" contains triangles and/or lines.\n"
                  "\tWe delete them unless the -p/--preserve-pts-order option is specified", input);
      // triangles
      HXT_CHECK( hxtAlignedFree(&mesh->triangles.node) );
      HXT_CHECK( hxtAlignedFree(&mesh->triangles.color) );
      mesh->triangles.num = 0;
      mesh->triangles.size = 0;

      // lines
      HXT_CHECK( hxtAlignedFree(&mesh->lines.node) );
      HXT_CHECK( hxtAlignedFree(&mesh->lines.color) );
      mesh->lines.num = 0;
      mesh->lines.size = 0;
    }
  }
  else {
    HXT_INFO_COND(verbosity>0, "Creating %d random vertices", nvert);
    HXT_CHECK( hxtAlignedMalloc(&mesh->vertices.coord, nvert*4*sizeof(double)) );

    for (uint32_t i=0; i<nvert; i++) {
      for (int j=0; j<3; j++) {
        mesh->vertices.coord[4*i+j] = (double) rand()/RAND_MAX;
      }
    }

    mesh->vertices.num = nvert;
    mesh->vertices.size = nvert;
  }

  if(stat)
      t1 = omp_get_wtime();

  HXTDelaunayOptions delOptions = {
    .bbox = NULL,
    .nodalSizes = NULL,
    .numVerticesInMesh = 0,
    .insertionFirst = 0,
    .partitionability = 0,
    .perfectDelaunay = 1,
    .verbosity = verbosity,
    .reproducible = reproducible,
    .delaunayThreads = nthreads
  };

  if(preserve_order) {
    HXTNodeInfo* nodeInfo;
    HXT_CHECK( hxtAlignedMalloc(&nodeInfo, sizeof(HXTNodeInfo)*mesh->vertices.num) );

    #pragma omp parallel for simd aligned(nodeInfo:SIMD_ALIGN)
    for (uint32_t i=0; i<mesh->vertices.num; i++) {
      nodeInfo[i].node = i;
      nodeInfo[i].status = HXT_STATUS_TRYAGAIN;
    }
    HXT_CHECK( hxtDelaunaySteadyVertices(mesh, &delOptions, nodeInfo, mesh->vertices.num) );
    HXT_CHECK( hxtAlignedFree(&nodeInfo) );
  }
  else
    HXT_CHECK( hxtDelaunay(mesh, &delOptions) );

  if(stat)
      t2 = omp_get_wtime();

  if(output!=NULL){
    HXT_INFO_COND(verbosity>0, "Writing result to \"%s\"", output);
    HXT_CHECK( hxtMeshWriteGmsh(mesh, output) );
  }

  if(stat){
    t3 = omp_get_wtime();
    HXT_INFO("\n\t========== Statistics ==========");
    HXT_INFO("Mesh contains %" HXTu64 " tetrahedra and %u vertices",
             mesh->tetrahedra.num,
             mesh->vertices.num);
    if(input)
      HXT_INFO("Reading file \"%s\" took %.2f seconds", input, t1-t0);
    else
      HXT_INFO("Creating random points took %.2f seconds", t1-t0);
    HXT_INFO("Init + BRIO + Delaunay took %.2f seconds (%.2f Mtet/s)", t2-t1, 0.000001*mesh->tetrahedra.num/(t2-t1));
    if(output)
      HXT_INFO("Writing file \"%s\" took %.2f seconds",output, t3-t2);
  }


  putchar('\n');

  HXT_CHECK( hxtMeshDelete(&mesh) );

  return 0;
}