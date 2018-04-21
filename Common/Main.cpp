// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include "GmshGlobal.h"

int main(int argc, char *argv[])
{
#if defined(HAVE_FLTK)
  return GmshMainFLTK(argc, argv);
#else
  return GmshMain(argc, argv);
#endif
}
