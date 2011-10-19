// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include "Gmsh.h"
#include "GmshMessage.h"
#include "Context.h"
#include "Options.h"
#include "PluginManager.h"
#include "GModel.h"

int main(int argc, char *argv[])
{
  // Create a new model
  new GModel();

  // Hack to generate automatic documentation (before getting
  // user-defined options)
  if(argc == 2 && std::string(argv[1]) == "-doc"){
    InitOptions(0);
    PluginManager::instance()->registerDefaultPlugins();
    PrintOptionsDoc();
    exit(0);
  }

  // Initialize static stuff (parser symbols, options)
  GmshInitialize(argc, argv);

  // Non-interactive Gmsh
  if(CTX::instance()->batch) {
    if(!Msg::GetGmshClient()) CTX::instance()->terminal = 1;
    GmshBatch();
    GmshFinalize();
    Msg::Exit(0);
  }

  // Interactive Gmsh with FLTK GUI
  return GmshFLTK(argc, argv);
}
