// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <time.h>
#include "GmshConfig.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "GmshRemote.h"
#include "GModel.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "CommandLine.h"
#include "OS.h"
#include "Context.h"
#include "ConnectionManager.h"
#include "robustPredicates.h"

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#include "meshPartition.h"
#endif

#if defined(HAVE_POST)
#include "PluginManager.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#include "menuWindow.h"
#include "drawContext.h"
#endif

#if defined(HAVE_LUA)
#include "LuaBindings.h"
#endif

int GmshInitialize(int argc, char **argv)
{
  // we need at least one model during option parsing
  GModel *dummy = 0;
  if(GModel::list.empty()) dummy = new GModel();

  // Initialize messages (parallel stuff, etc.)
  Msg::Init(argc, argv);

  // Load default options
  InitOptions(0);

  // Read configuration files and command line options
  GetOptions(argc, argv);

  // Make sure we have enough resources (stack)
  CheckResources();
  
#if defined(HAVE_POST)
  // Initialize the default plugins
  PluginManager::instance()->registerDefaultPlugins();
#endif

  // Initialize robust predicates
  robustPredicates::exactinit();

  if(dummy) delete dummy;
  return 1;
}

int GmshSetMessageHandler(GmshMessage *callback)
{
  Msg::SetCallback(callback);
  return 1;
}

int GmshSetBoundingBox(double xmin, double xmax,
                       double ymin, double ymax, 
                       double zmin, double zmax)
{
  SetBoundingBox(xmin, xmax, ymin, ymax, zmin, zmax);
  return 1;
}

int GmshSetOption(std::string category, std::string name, std::string value, int index)
{
  return StringOption(GMSH_SET, category.c_str(), index, name.c_str(), value);
}

int GmshSetOption(std::string category, std::string name, double value, int index)
{
  return NumberOption(GMSH_SET, category.c_str(), index, name.c_str(), value);
}

int GmshSetOption(std::string category, std::string name, unsigned int value, int index)
{
  return ColorOption(GMSH_SET, category.c_str(), index, name.c_str(), value);
}

int GmshGetOption(std::string category, std::string name, std::string &value, int index)
{
  return StringOption(GMSH_GET, category.c_str(), index, name.c_str(), value);
}

int GmshGetOption(std::string category, std::string name, double &value, int index)
{
  return NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), value);
}

int GmshGetOption(std::string category, std::string name, unsigned int &value, int index)
{
  return ColorOption(GMSH_GET, category.c_str(), index, name.c_str(), value);
}

int GmshMergeFile(std::string fileName)
{
  return MergeFile(fileName, true);
}

int GmshWriteFile(std::string fileName)
{
  CreateOutputFile(fileName, FORMAT_AUTO);
  return 1;
}

int GmshFinalize()
{
  return 1;
}

int GmshBatch()
{
  Msg::Info("Running '%s' [%d node(s), max. %d thread(s)]", 
            Msg::GetCommandLineArgs().c_str(),
            Msg::GetCommSize(), Msg::GetMaxThreads());
  Msg::Info("Started on %s", Msg::GetLaunchDate().c_str());

  OpenProject(GModel::current()->getFileName());
  for(unsigned int i = 1; i < CTX::instance()->files.size(); i++){
    if(CTX::instance()->files[i] == "-new")
      new GModel();
    else
      MergeFile(CTX::instance()->files[i]);
  }

#if defined(HAVE_POST) && defined(HAVE_MESH)
  if(!CTX::instance()->bgmFileName.empty()) {
    MergeFile(CTX::instance()->bgmFileName);
    if(PView::list.size())
      GModel::current()->getFields()->setBackgroundMesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }
#endif

#if defined(HAVE_LUA)
  if(CTX::instance()->batch == -4){
    binding::instance()->interactiveSession();
  }
  else 
#endif 
  if(CTX::instance()->batch == -3){
    GmshRemote();
  }
  else if(CTX::instance()->batch == -2){
    GModel::current()->checkMeshCoherence(CTX::instance()->geom.tolerance);
  }
  else if(CTX::instance()->batch == -1){
    CreateOutputFile(CTX::instance()->outputFileName, FORMAT_GEO);
  }
  else if(CTX::instance()->batch > 0){
#if defined(HAVE_MESH)
    if(CTX::instance()->batch < 4)
      GModel::current()->mesh(CTX::instance()->batch);
    else if(CTX::instance()->batch == 4)
      AdaptMesh(GModel::current());
    else if(CTX::instance()->batch == 5)
      RefineMesh(GModel::current(), CTX::instance()->mesh.secondOrderLinear);
#if defined(HAVE_CHACO) || defined(HAVE_METIS)
    if(CTX::instance()->batchAfterMesh == 1){
      if (CTX::instance()->partitionOptions.num_partitions > 1)
        PartitionMesh(GModel::current(), CTX::instance()->partitionOptions);
      if (CTX::instance()->partitionOptions.renumber)
        RenumberMesh(GModel::current(), CTX::instance()->partitionOptions);
    }
#endif
#endif
    CreateOutputFile(CTX::instance()->outputFileName, CTX::instance()->mesh.format);
  }

  time_t now;
  time(&now);
  std::string currtime = ctime(&now);
  currtime.resize(currtime.size() - 1);
  Msg::Info("Stopped on %s", currtime.c_str());

  Msg::FinalizeClient();

  return 1;
}

int GmshFLTK(int argc, char **argv)
{
#if defined(HAVE_FLTK) && defined(HAVE_POST)
  // create the GUI
  FlGui::instance(argc, argv);

  // display GUI immediately for quick launch time
  FlGui::instance()->check();

  // open project file and merge all other input files
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

  // init first context
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

  // read background mesh if any
  if(!CTX::instance()->bgmFileName.empty()) {
    MergeFile(CTX::instance()->bgmFileName);
    if(PView::list.size())
      GModel::current()->getFields()->setBackgroundMesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }

  // draw the scene
  drawContext::global()->draw();

  // listen to external solvers
  if(CTX::instance()->solver.listen){
    ConnectionManager::get(-1)->name = "unknown";
    ConnectionManager::get(-1)->run("");
  }

  // loop
  return FlGui::instance()->run();
#else
  Msg::Error("GmshFLTK unavailable: please recompile with FLTK support");
  return 0;
#endif
}
