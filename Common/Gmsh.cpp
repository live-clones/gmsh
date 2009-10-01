// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <time.h>
#include "GmshConfig.h"
#include "GmshDefines.h"
#include "GmshRemote.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "CommandLine.h"
#include "OS.h"
#include "Generator.h"
#include "Field.h"
#include "Context.h"
#include "robustPredicates.h"
#include "meshPartition.h"

#if !defined(HAVE_NO_POST)
#include "PluginManager.h"
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
  
#if !defined(HAVE_NO_POST)
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
  Msg::Info("Running '%s'", Msg::GetCommandLineArgs().c_str());
  Msg::Info("Started on %s", Msg::GetLaunchDate().c_str());

  OpenProject(GModel::current()->getFileName());
  for(unsigned int i = 1; i < CTX::instance()->files.size(); i++){
    if(CTX::instance()->files[i] == "-new")
      new GModel();
    else
      MergeFile(CTX::instance()->files[i]);
  }

#if !defined(HAVE_NO_POST)
  if(!CTX::instance()->bgmFileName.empty()) {
    MergeFile(CTX::instance()->bgmFileName);
    if(PView::list.size())
      GModel::current()->getFields()->setBackgroundMesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }
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
    if(CTX::instance()->batch < 4)
      GModel::current()->mesh(CTX::instance()->batch);
    else if(CTX::instance()->batch == 4)
      AdaptMesh(GModel::current());
    else if(CTX::instance()->batch == 5)
      RefineMesh(GModel::current(), CTX::instance()->mesh.secondOrderLinear);
#if defined(HAVE_CHACO) || defined(HAVE_METIS)
    if(CTX::instance()->batchAfterMesh == 1)
      PartitionMesh(GModel::current(), CTX::instance()->partitionOptions);
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
