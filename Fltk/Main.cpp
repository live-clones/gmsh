// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <time.h>
#include "GUI.h"
#include "menuWindow.h"
#include "Gmsh.h"
#include "GmshMessage.h"
#include "Draw.h"
#include "Context.h"
#include "Options.h"
#include "Parser.h"
#include "OpenFile.h"
#include "CommandLine.h"
#include "Solvers.h"
#include "PluginManager.h"
#include "GModel.h"
#include "Field.h"
#include "BackgroundMesh.h"
#include "PView.h"

extern Context_T CTX;

int main(int argc, char *argv[])
{
  // Log some info
  time_t now;
  time(&now);
  std::string currtime(ctime(&now));
  currtime[currtime.size() - 1] = '\0';
  std::string cmdline;
  for(int i = 0; i < argc; i++){
    if(i) cmdline += " ";
    cmdline += argv[i];
  }

  // Hack to generate automatic documentation (before getting
  // user-defined options)
  if(argc == 2 && std::string(argv[1]) == "-doc"){
    Init_Options(0);
    GMSH_PluginManager::instance()->registerDefaultPlugins();
    GModel *dummy = new GModel;
    Print_OptionsDoc();
    delete dummy;
    exit(0);
  }

  // Initialize static stuff (parser symbols, options)
  GmshInitialize(argc, argv);

  // Always print info on terminal for non-interactive execution
  if(CTX.batch) CTX.terminal = 1;

  // Create a new model
  new GModel;

  // Non-interactive Gmsh
  if(CTX.batch) {
    Msg::Info("Running '%s'", cmdline.c_str());
    Msg::Info("Started on %s", currtime.c_str());
    GmshBatch();
    GmshFinalize();
    time(&now);
    currtime = ctime(&now);
    currtime[currtime.size() - 1] = '\0';
    Msg::Info("Stopped on %s", currtime.c_str());
    Msg::Exit(0);
  }

  // Create the GUI
  GUI::instance(argc, argv);

  // Set all previously defined options in the GUI
  Init_Options_GUI(0);

  // Say welcome!
  Msg::StatusBar(1, false, "Geometry");
  Msg::StatusBar(2, false, "Gmsh %s", Get_GmshVersion());

  // Log the following for bug reports
  Msg::Info("-------------------------------------------------------");
  Msg::Info("Gmsh version   : %s", Get_GmshVersion());
  Msg::Info("Build OS       : %s", Get_GmshBuildOS());
  Msg::Info("Build options  : %s", Get_GmshBuildOptions().c_str());
  Msg::Info("Build date     : %s", Get_GmshBuildDate());
  Msg::Info("Build host     : %s", Get_GmshBuildHost());
  Msg::Info("Packager       : %s", Get_GmshPackager());
  Msg::Info("Home directory : %s", CTX.home_dir);
  Msg::Info("Launch date    : %s", currtime.c_str());
  Msg::Info("Command line   : %s", cmdline.c_str());
  Msg::Info("-------------------------------------------------------");

  // Display the GUI immediately to have a quick "a la Windows" launch time
  GUI::instance()->check();

  // Open project file and merge all other input files
  OpenProject(CTX.filename);
  for(unsigned int i = 1; i < CTX.files.size(); i++){
    if(CTX.files[i] == "-new")
      new GModel;
    else
      MergeFile(CTX.files[i].c_str());
  }
  
  if(CTX.post.combine_time){
    PView::combine(true, 2, CTX.post.combine_remove_orig);
    GUI::instance()->updateViews();
  }

  // Init first context
  switch (CTX.initial_context) {
  case 1: GUI::instance()->menu->setContext(menu_geometry, 0); break;
  case 2: GUI::instance()->menu->setContext(menu_mesh, 0); break;
  case 3: GUI::instance()->menu->setContext(menu_solver, 0); break;
  case 4: GUI::instance()->menu->setContext(menu_post, 0); break;
  default: // automatic
    if(PView::list.size())
      GUI::instance()->menu->setContext(menu_post, 0);
    else
      GUI::instance()->menu->setContext(menu_geometry, 0);
    break;
  }

  // Read background mesh on disk
  if(CTX.bgm_filename) {
    MergeFile(CTX.bgm_filename);
    if(PView::list.size())
      GModel::current()->getFields()->set_background_mesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }

  // Draw the scene
  Draw();

  // Listen to external solvers
  if(CTX.solver.listen) Solver(-1, NULL);

  // loop
  return GUI::instance()->run();
}
