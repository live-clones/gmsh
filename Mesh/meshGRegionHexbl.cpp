// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshConfig.h"
#include "meshGRegionHexbl.h"
#include "Context.h"
#include "MVertex.h"
#include "GRegion.h"
#include "discreteRegion.h"
#include "GmshMessage.h"
#include "OS.h"

#if defined(HAVE_HEXMESHINGTOOLS)
#include "hblMain.h"
#endif

#if defined(HAVE_HEXMESHINGTOOLS)
int meshGModelHexbl(GModel* gm) {
  int status = hbl::generateAllHexBoundaryLayerMesh(gm);
  return status;
}
#else
int meshGModelHexbl(GModel* gm) {
  Msg::Error("Algo hexbl (Full Hex Boundary Layer) requires the HexMeshingTools module");
  return -1;
}
#endif


