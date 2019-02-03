// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshGlobal.h"
#include "GmshMessage.h"

int main(int argc, char *argv[])
{
  // by default run the app with a single OpenMP thread?
  //Msg::SetNumThreads(1);

#if defined(HAVE_FLTK)
  return GmshMainFLTK(argc, argv);
#else
  return GmshMainBatch(argc, argv);
#endif
}
