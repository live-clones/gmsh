// Hxt - Copyright (C) 
// 2016 - 2020 UCLouvain
//
// See the LICENSE.txt file for license information.
//
// Contributor(s):
//   Célestin Marot

#include "hxt_tetMesh.h"
#include "hxt_opt.h"
#include "hxt_tools.h"
#include "hxt_omp.h"


int main(int argc, char** argv) {

  const char* input = NULL;
  const char* output = NULL;
  const char* geoFile = NULL;

  HXTTetMeshOptions options = {.refine=1, .optimize=1, .verbosity=1, .quality.min=0.35, .nodalSizes.factor=1.0};

  HXT_CHECK( hxtAddOption('t', "omp_num_threads",
                          "Number of threads used for parallel work.\n"
                          "If NUM<=0, use OMP_NUM_THREADS environment variable", HXT_INT, NULL, &options.defaultThreads));
  HXT_CHECK( hxtAddOption('d', "delaunay_threads",
                              "Overrides the maximum number of threads for Delaunay insertion\n"
                              " * NUM>0: use NUM threads\n"
                              " * NUM=0: use the default nbr. of threads (see `-t` option)\n"
                              " * NUM<0: use OMP_NUM_PROCS", HXT_INT, NULL, &options.delaunayThreads));
  HXT_CHECK( hxtAddOption('o', "opti_threads",
                              "Overrides the maximum number of threads for mesh optimizations\n"
                              " * NUM>0: use NUM threads\n"
                              " * NUM=0: use the default nbr. of threads (see `-t` option)\n"
                              " * NUM<0: use OMP_NUM_PROCS", HXT_INT, NULL, &options.improveThreads));
  HXT_CHECK( hxtAddOption('r', "reproducible",
                          "Reproducible mesh:\n"
                          "The output mesh will be identical with this option\n"
                          "if given\n"
                          " - the same vertices in the same order\n"
                          " - the same number of threads\n"
                          "and if compiled with the same compiler on the same machine.\n"
                          "WARNING: This option slows down the mesh generation\n"
                          "except with 1 thread", HXT_FLAG, NULL, &options.reproducible));

  const HXTOptionArgumentConstraints geoSuffix = {.stringSuffix=".geo"};
  HXT_CHECK( hxtAddOption('g', "generate-geo", "Write a .geo file that describe the volumes from the input surface mesh", HXT_ASK_TO_ERASE_FILENAME, &geoSuffix, &geoFile));
  HXT_CHECK( hxtAddOption('n', "no-refinement", "Do not refine the mesh => no vertices are added", HXT_NO_FLAG, NULL, &options.refine));
  HXT_CHECK( hxtAddOption('N', "no-improvement", "Do not optimize the mesh quality", HXT_NO_FLAG, NULL, &options.optimize) );


  HXT_CHECK( hxtAddOption('L', "clmin", "minimum mesh size", HXT_DOUBLE, &HXT_POSITIVE_RANGE, &options.nodalSizes.min));
  HXT_CHECK( hxtAddOption('H', "clmax", "maximum mesh size", HXT_DOUBLE, &HXT_POSITIVE_RANGE, &options.nodalSizes.max));
  // HXT_CHECK( hxtAddOption('S', "clscale", "scale mesh size by a factor of VAL", HXT_DOUBLE, &HXT_POSITIVE_RANGE, &options.nodalSizes.factor)); (no effect with interpolated nodalSizes)
  HXT_CHECK( hxtAddOption('A', "aspect-ratio-min", "The threshold on the aspect-ratio used during the optimization", HXT_DOUBLE, &HXT_0_1_RANGE, &options.quality.min));

  HXT_CHECK( hxtAddOption('v', "verbosity",
                          "Verbosity level of output messages\n"
                          " * NUM=0: print no information\n"
                          " * NUM=1: print some information\n"
                          " * NUM=2: print all information", HXT_INT, &HXT_0_2_RANGE, &options.verbosity));
  HXT_CHECK( hxtAddOption('s', "stat", "Print timing for each portion of the program", HXT_FLAG, NULL, &options.stat));

  HXT_CHECK( hxtAddTrailingOption("INPUT_FILE", HXT_EXISTING_FILENAME, NULL, &input));
  HXT_CHECK( hxtAddTrailingOption("OUTPUT_FILE", HXT_STRING, NULL, &output));

  HXT_PARSE_COMMAND_LINE(argc, argv,
                         "hxtMesh3d",
                         "Compute a mesh from the surface mesh in INPUT_FILE",
                         "--\nContact: celestin.marot@uclouvain.be");

  if(options.verbosity)
  {
    const char* T = "true";
    const char* F = "false";
    printf("\ninput:             %s\noutput:            %s\n"
             "Number of threads: %d\nDelaunay threads:  %d\nOptim. threads:    %d\n"
             "reproducible:      %s\nverbosity level:   %d\nshow statistics:   %s\n"
             "refine:            %s\noptimize :         %s\nmin aspect ratio:  %.3f\n"
             "min. nodalSize:    %g\nmax. nodalSize:    %g\nnodalSize scaling: %g\n\n",
           input?input:"-", output?output:"-", options.defaultThreads<=0?omp_get_max_threads():options.defaultThreads,
           options.delaunayThreads, options.improveThreads,
           options.reproducible?T:F, (int) options.verbosity, options.stat?T:F, options.refine?T:F, options.optimize?T:F, options.quality.min,
           options.nodalSizes.min, options.nodalSizes.max, options.nodalSizes.factor);
  }


  /*******************  ^ all argument were processed *********************/
  HXTMesh *mesh;
  HXT_CHECK( hxtMeshCreate(&mesh) );

  HXT_INFO_COND(options.verbosity>0, "Reading \"%s\"\n", input);
  HXT_CHECK( hxtMeshReadGmsh(mesh, input) );
  
  HXT_CHECK( hxtTetMesh(mesh, &options) );
  
  if(output){
    HXT_INFO_COND(options.verbosity>0, "Writing result to \"%s\"", output);
    HXT_CHECK(hxtMeshWriteGmsh(mesh, output));
  }

  if(geoFile) {
    // generate a .geo file
    HXT_INFO_COND(options.verbosity>0, "Writing .geo file to \"%s\"", geoFile);
    FILE* fp = fopen(geoFile, "w");
    fprintf(fp, "Merge \"%s\"; // loads the 2d mesh of the volume\n", input);

    uint32_t surf = 0;
    for(uint32_t i=0; i<mesh->brep.numVolumes; i++) {
      fprintf(fp, "Surface Loop(%u) = {%u", i+1, mesh->brep.surfacesPerVolume[surf++]);
      for(uint32_t j=1; j<mesh->brep.numSurfacesPerVolume[i]; j++) {
        fprintf(fp, ",%u", mesh->brep.surfacesPerVolume[surf++]);
      }
      fprintf(fp, "};\nVolume(%u) = {%u};\n", i+1, i+1);
    }
    fclose(fp);
  }

  HXT_CHECK( hxtMeshDelete(&mesh) );
  return HXT_STATUS_OK;
}
