// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "Gmsh.h"
#include "GModel.h"
#include "CommandLine.h"
#include "GmshMessage.h"
#include "Context.h"

int main(int argc, char *argv[])
{
  CTX::instance()->terminal = CTX::instance()->noPopup = 1;

  if(argc < 2){
    PrintUsage(argv[0]);
    exit(0);
  }

  new GModel();
  GmshInitialize(argc, argv);
  GmshBatch();
  GmshFinalize();

  Msg::Exit(0);
  return 1;
}
