#include <math.h>
#include "hxt_message.h"
#include "hxt_api.h"
#include "hxt_mesh3d.h"
#include "hxt_tetrahedra.h"
#include "hxt_mesh.h"
#include "hxt_bbox.h"

HXTStatus mySize (double x[3], void* data, double* s){
  *s = .1;
  return HXT_STATUS_OK;
}

int main(int argc, char **argv) {
  if (argc != 3)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED,"usage: mesh3d input.msh output.msh");

  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(context, &mesh));
  HXT_CHECK(hxtMeshReadGmsh(mesh, argv[1]));

  // we must first update the bbox
  hxtBbox bbox;
  hxtBboxInit(&bbox);
  HXT_CHECK( hxtBboxAdd(&bbox, mesh->vertices.coord, mesh->vertices.num) );
  
  // impossible to put 0 !!!
  for (uint32_t i = 0;i< mesh->vertices.num;i++){
    mesh->vertices.coord[4*i  ] += 1.e-8*drand48();
    mesh->vertices.coord[4*i+1] += 1.e-8*drand48();
    mesh->vertices.coord[4*i+2] += 1.e-8*drand48();
  }
  
  printf("creating an empty mesh with %u vertices\n",mesh->vertices.num);
  HXT_CHECK(hxtEmptyMesh(mesh));
  puts("verifying consistency of the mesh");
  HXT_CHECK( hxtTetrahedraVerify(mesh) );

  uint32_t nbMissing;
  printf("verifying the boundary\n");
  HXT_CHECK(hxtVerifyBoundary(mesh,&nbMissing));
  printf("%7d missing faces\n",nbMissing);
  uint32_t nbColors;
  if (nbMissing == 0){
    double *sizes;
    HXT_CHECK(hxtComputeMeshSizeFromMesh (mesh, &sizes));
    HXT_CHECK(hxtColorMesh(mesh,&nbColors));
    HXTMeshSize *meshSize;
    HXT_CHECK(hxtMeshSizeCreate (context,&meshSize));
    HXT_CHECK(hxtMeshSizeCompute (meshSize, bbox.min, bbox.max, mySize, NULL));
    HXT_CHECK(hxtRefineTetrahedra(mesh, meshSize, &sizes));
    HXT_CHECK(hxtMeshSizeDelete (&meshSize));
    HXT_CHECK(hxtFree(&sizes));
    puts("verifying consistency of the mesh");
    HXT_CHECK( hxtTetrahedraVerify(mesh) );
  }
  
  HXT_CHECK(hxtMeshWriteGmsh(mesh, argv[2]));
  return HXT_STATUS_OK;
}
