// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetOpti.h"
#include "hxt_tetRepair.h"
#include "hxt_tetFlag.h"
#include "hxt_opt.h"
#include "hxt_tools.h"
#include "hxt_omp.h"

int main(int argc, char** argv) {

  const char* input = NULL;
  const char* output = NULL;

  int maxThreads = 0;

  HXTOptimizeOptions options = {.qualityMin=0.35, .reproducible=1, .verbosity=2};

  HXT_CHECK( hxtAddOption('t', "omp_num_threads",
                          "Number of threads used for parallel work.\n"
                          "If NUM<=0, use OMP_NUM_THREADS environment variable", HXT_INT, NULL, &maxThreads));
  HXT_CHECK( hxtAddOption('o', "opti_threads",
                              "Overrides the maximum number of threads for mesh improvement\n"
                              " * NUM>0: use NUM threads\n"
                              " * NUM=0: use the default nbr. of threads (see `-t` option)\n"
                              " * NUM<0: use OMP_NUM_PROCS", HXT_INT, NULL, &options.numThreads));
  HXT_CHECK( hxtAddOption('v', "verbosity",
                       "Verbosity level of output messages\n"
                       " * NUM=0: print no information\n"
                       " * NUM=1: print some information\n"
                       " * NUM=2: print all information", HXT_INT, &HXT_0_2_RANGE, &options.verbosity));
  HXT_CHECK( hxtAddOption('a', "aspect-ratio-min", "The threshold on the aspect-ratio used during the optimization", HXT_DOUBLE, &HXT_0_1_RANGE, &options.qualityMin));

  HXT_CHECK( hxtAddTrailingOption("INPUT_FILE", HXT_EXISTING_FILENAME, NULL, &input));
  HXT_CHECK( hxtAddTrailingOption("OUTPUT_FILE", HXT_STRING, NULL, &output));

  HXT_PARSE_COMMAND_LINE(argc, argv,
                         "hxtTetOpti",
                         "Improve an existing tet mesh",
                         "--\nContact: celestin.marot@uclouvain.be");

  if(maxThreads>0) {
    omp_set_num_threads(maxThreads);
  }

  /*******************  ^ all argument were processed *********************/
  HXTMesh *mesh;
  HXT_CHECK( hxtMeshCreate(&mesh) );

  HXT_INFO_COND(options.verbosity>0, "Reading \"%s\"\n", input);
  HXT_CHECK( hxtMeshReadGmsh(mesh, input) );
  HXT_INFO("%u points, %" HXTu64 " tets", mesh->vertices.num, mesh->tetrahedra.num);

  if(mesh->tetrahedra.num==0)
    return HXT_ERROR_MSG(HXT_STATUS_ERROR, "No tetrahedron to optimize");

  HXT_INFO("Computing adjacencies");
  HXT_CHECK( hxtTetAdjacencies(mesh) );

#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );
#endif

  HXT_INFO("Creating mesh->tetrahedra.flag");
  HXT_CHECK( hxtAlignedMalloc(&mesh->tetrahedra.flag, sizeof(uint16_t) * mesh->tetrahedra.size) );

  HXT_INFO("Initializing flags and setting constraint");
  #pragma omp parallel for
  for(uint64_t i=0; i<mesh->tetrahedra.num; i++) {
    mesh->tetrahedra.flag[i] = 0;
    for(int j=0; j<4; j++) {
      if(mesh->tetrahedra.neigh[4*i+j]==HXT_NO_ADJACENT)
        setFacetConstraint(mesh, i, j);
    }
  }

#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );
#endif


  HXT_INFO("Improving the quality of bad tet.");
  HXT_CHECK( hxtOptimizeTetrahedra(mesh, &options) );

#ifdef DEBUG
  HXT_CHECK( hxtTetVerify(mesh) );
#endif
  
  
  if(output){
    HXT_INFO_COND(options.verbosity>0, "Writing result to \"%s\"", output);
    HXT_CHECK(hxtMeshWriteGmsh(mesh, output));
  }

  HXT_CHECK( hxtMeshDelete(&mesh) );
  return HXT_STATUS_OK;
}
