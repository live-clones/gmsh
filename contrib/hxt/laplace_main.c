#include "hxt_api.h"
#include "hxt_laplace.h"
#include "hxt_linear_system.h"
int main(int argc, char **argv) {
  if (argc != 2)
    return HXT_ERROR_MSG(HXT_STATUS_FAILED,"usage: laplace input.msh");
  HXT_CHECK(hxtInitializeLinearSystems(&argc, &argv));

  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *mesh;
  HXT_CHECK(hxtMeshCreate(context, &mesh));
  HXT_CHECK(hxtMeshReadGmsh(mesh, argv[1]));
  HXT_CHECK(hxtLaplace(mesh));  
  return HXT_STATUS_OK;
}
