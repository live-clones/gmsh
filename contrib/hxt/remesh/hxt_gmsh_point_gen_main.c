#include "hxt_gmsh_point_gen_main.h"

#include "hxt_point_gen_options.h"
#include "hxt_point_gen_io.h"


HXTStatus hxtGmshPointGenMain(HXTMesh *mesh, 
                              HXTPointGenOptions *opt,
                              double *data,
                              HXTMesh *fmesh)
{

  double uniformSize = 0.1;

  double *directions;
  HXT_CHECK(hxtMalloc(&directions,9*mesh->vertices.num*sizeof(double)));
  for (uint32_t i=0; i<9*mesh->vertices.num; i++) directions[i] = 0.0;

  double *h_function;
  HXT_CHECK(hxtMalloc(&h_function,mesh->vertices.num*sizeof(double)));
  double *sizemap;
  HXT_CHECK(hxtMalloc(&sizemap,mesh->vertices.num*sizeof(double)));

  for (uint32_t i=0; i<mesh->vertices.num; i++) h_function[i] = 0.0;

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    for (uint32_t j=0; j<6; j++){
      directions[9*i+j] = data[7*i+j];
    }
    h_function[i] = data[7*i+6];
    sizemap[i] = (1./exp(data[7*i+6]))*uniformSize;
  }

  HXT_CHECK(hxtPointGenWriteDirections(mesh,directions,"GMSH_TEST_directionsPoints.pos"));
  HXT_CHECK(hxtPointGenWriteScalarTriangles(mesh,h_function,"GMSH_TEST_hfunction.pos"));
  
  HXT_CHECK(hxtGeneratePointsMain(mesh,opt,sizemap,directions,fmesh));


  HXT_CHECK(hxtFree(&directions));
  HXT_CHECK(hxtFree(&h_function));
  HXT_CHECK(hxtFree(&sizemap));

  return HXT_STATUS_OK;
}


