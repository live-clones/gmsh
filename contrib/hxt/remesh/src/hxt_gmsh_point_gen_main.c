#include "hxt_gmsh_point_gen_main.h"

#include "hxt_point_gen_options.h"
#include "hxt_point_gen_io.h"
#include "hxt_point_gen_numerics.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen.h"

#include "hxt_tetRepair.h"


HXTStatus hxtGmshPointGenMain(HXTMesh *mesh, 
                              HXTPointGenOptions *opt,
                              double *data,
                              HXTMesh *fmesh)
{

  HXT_INFO("");
  HXT_INFO("=============================================================");
  HXT_INFO("           POINT GENERATION MAIN"); 

  // Do not remesh anything if points are not generated
  if (opt->generateLines==0 && opt->generateSurfaces==0) opt->remeshSurfaces = 0;

  HXT_INFO("");
  HXT_INFO("Verbosity level                           %d",  opt->verbosity);
  HXT_INFO("Generate points on lines                  %d",  opt->generateLines);
  HXT_INFO("Generate points on surfaces               %d",  opt->generateSurfaces);
  HXT_INFO("Generate points on volumes                %d",  opt->generateVolumes);
  HXT_INFO("Remesh triangulation                      %d",  opt->remeshSurfaces);
  HXT_INFO("Convert to quad mesh                      %d",  opt->quadSurfaces);
  HXT_INFO("Walk method 2D                            %d",  opt->walkMethod2D);
  HXT_INFO("Walk method 3D                            %d",  opt->walkMethod3D);
  HXT_INFO("Compute directions                        %d",  opt->dirType);
  HXT_INFO("Uniform background size                   %f",  opt->uniformSize);
  HXT_INFO("Desired number of output triangles        %lu", opt->numTris);
  HXT_INFO("");

  if (mesh->tetrahedra.num == 0 && (opt->generateVolumes || opt->dirType))
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Input mesh does not have tetrahedra");

  if (mesh->tetrahedra.num != 0 && opt->generateVolumes){
    HXT_INFO("Computing Adjacencies of Tetrahedral input mesh");
    HXT_CHECK(hxtTetAdjacencies(mesh));
  }
 
  //**********************************************************
  // Create and read directions and sizemap arrays from input 
  //**********************************************************

  double *directions;
  HXT_CHECK(hxtMalloc(&directions,9*mesh->vertices.num*sizeof(double)));
  for (uint32_t i=0; i<9*mesh->vertices.num; i++) directions[i] = 0.0;

  double *h_function;
  HXT_CHECK(hxtMalloc(&h_function,mesh->vertices.num*sizeof(double)));
  double *sizemap;
  HXT_CHECK(hxtMalloc(&sizemap,3*mesh->vertices.num*sizeof(double)));
  for (uint32_t i=0; i<3*mesh->vertices.num; i++) sizemap[i] = 0.0;

  for (uint32_t i=0; i<mesh->vertices.num; i++) h_function[i] = 0.0;

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    for (uint32_t j=0; j<6; j++){
      directions[9*i+j] = data[7*i+j];
    }
    // dummy third direction (normal to the surface) 
    HXT_CHECK(myNormalizedCrossprod(&directions[9*i+0],&directions[9*i+3],&directions[9*i+6]));

    h_function[i] = data[7*i+6];
    sizemap[3*i+0] = (1./exp(data[7*i+6]))*opt->uniformSize;
    sizemap[3*i+1] = (1./exp(data[7*i+6]))*opt->uniformSize;
    sizemap[3*i+2] = (1./exp(data[7*i+6]))*opt->uniformSize;

    /*sizemap[3*i+0] = opt->uniformSize;*/
    /*sizemap[3*i+1] = opt->uniformSize;*/
    /*sizemap[3*i+2] = opt->uniformSize;*/
 
  }
  HXT_CHECK(hxtPointGenWriteDirections(mesh,directions,"GMSH_TEST_directionsPoints.pos"));
  HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,h_function,"GMSH_TEST_hfunction.pos"));

  //**********************************************************
  // If there is specified number of output triangles
  // scale the input sizemap
  //**********************************************************
  if (opt->numTris){
    HXT_INFO("Scaling sizemap for estimated %lu final triangles",opt->numTris);
    HXT_CHECK(hxtPointGenSizemapFromNelements(mesh,opt->numTris,sizemap));
  }
  HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,sizemap,"GMSH_TEST_sizemap.pos"));
  
  //**********************************************************
  // Point Generation Main Program 
  //**********************************************************
  HXT_CHECK(hxtGeneratePointsMain(mesh,opt,sizemap,directions,fmesh));

  //**********************************************************
  // Output
  //**********************************************************
  const char *meshoutput = "finalmesh.msh";
  if (meshoutput){
    HXT_INFO("Writing final mesh to \"%s\"", meshoutput);
    HXT_CHECK(hxtMeshWriteGmsh(fmesh,meshoutput));
  }


  HXT_CHECK(hxtFree(&directions));
  HXT_CHECK(hxtFree(&h_function));
  HXT_CHECK(hxtFree(&sizemap));

  return HXT_STATUS_OK;
}


