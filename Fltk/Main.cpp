// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include "Gmsh.h"
#include "GmshMessage.h"
#include "ConnectionManager.h"
#include "FlGui.h"
#include "menuWindow.h"
#include "drawContext.h"
#include "Context.h"
#include "Options.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "PluginManager.h"
#include "GModel.h"
#include "Field.h"
#include "BackgroundMesh.h"
#include "PView.h"

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
    if(!Msg::GetClient()) CTX::instance()->terminal = 1;
    GmshBatch();
    GmshFinalize();
    Msg::Exit(0);
  }

  // Create the GUI
  FlGui::instance(argc, argv);

  // Set all previously defined options in the GUI
  InitOptionsGUI(0);

  // Say welcome!
  Msg::StatusBar(1, false, "Geometry");
  Msg::StatusBar(2, false, "Gmsh %s", GetGmshVersion());

  // Log the following for bug reports
  Msg::Info("-------------------------------------------------------");
  Msg::Info("Gmsh version   : %s", GetGmshVersion());
  Msg::Info("Build OS       : %s", GetGmshBuildOS());
  Msg::Info("Build options  :%s", GetGmshBuildOptions());
  Msg::Info("Build date     : %s", GetGmshBuildDate());
  Msg::Info("Build host     : %s", GetGmshBuildHost());
  Msg::Info("Packager       : %s", GetGmshPackager());
  Msg::Info("Home directory : %s", CTX::instance()->homeDir.c_str());
  Msg::Info("Launch date    : %s", Msg::GetLaunchDate().c_str());
  Msg::Info("Command line   : %s", Msg::GetCommandLineArgs().c_str());
  Msg::Info("-------------------------------------------------------");

  // Display the GUI immediately to have a quick "a la Windows" launch time
  FlGui::instance()->check();

  // Open project file and merge all other input files
  OpenProject(GModel::current()->getFileName());
  for(unsigned int i = 1; i < CTX::instance()->files.size(); i++){
    if(CTX::instance()->files[i] == "-new"){
      GModel::current()->setVisibility(0);
      new GModel();
    }
    else
      MergeFile(CTX::instance()->files[i]);
  }
  
  if(CTX::instance()->post.combineTime){
    PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
    FlGui::instance()->updateViews();
  }

  // Init first context
  switch (CTX::instance()->initialContext) {
  case 1: FlGui::instance()->menu->setContext(menu_geometry, 0); break;
  case 2: FlGui::instance()->menu->setContext(menu_mesh, 0); break;
  case 3: FlGui::instance()->menu->setContext(menu_solver, 0); break;
  case 4: FlGui::instance()->menu->setContext(menu_post, 0); break;
  default: // automatic
    if(PView::list.size())
      FlGui::instance()->menu->setContext(menu_post, 0);
    else
      FlGui::instance()->menu->setContext(menu_geometry, 0);
    break;
  }

  // Read background mesh if any
  if(!CTX::instance()->bgmFileName.empty()) {
    MergeFile(CTX::instance()->bgmFileName);
    if(PView::list.size())
      GModel::current()->getFields()->setBackgroundMesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }

  // Draw the scene
  drawContext::global()->draw();

  // Listen to external solvers
  if(CTX::instance()->solver.listen)
    ConnectionManager::get(-1)->run("");

  // loop
  return FlGui::instance()->run();
}
