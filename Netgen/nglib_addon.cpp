// small addition(s) to the netgen interface library

#include <meshing.hpp>
#include "libsrc/interface/nglib.h"

using namespace netgen;

Ng_Result NgAddOn_OptimizeVolumeMesh (Ng_Mesh * mesh, Ng_Meshing_Parameters * mp)
{
  Mesh * m = (Mesh*)mesh;

  MeshingParameters mparam;
  mparam.maxh = mp->maxh;
  mparam.meshsizefilename = mp->meshsize_filename;

  m->CalcLocalH();

  //MeshVolume (mparam, *m);
  RemoveIllegalElements (*m);
  OptimizeVolume (mparam, *m, NULL);

  return NG_OK;
}
