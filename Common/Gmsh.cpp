// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <string>
#include <time.h>
#include "GmshDefines.h"
#include "GModel.h"
#include "GmshMessage.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "CommandLine.h"
#include "OS.h"
#include "Numeric.h"
#include "Generator.h"
#include "Field.h"
#include "Context.h"
#include "Partition.h"
#include "GmshDaemon.h"

#if !defined(HAVE_NO_POST)
#include "PluginManager.h"
#endif

extern Context_T CTX;

int GmshInitialize(int argc, char **argv)
{
  // Initialize messages (parallel stuff, etc.)
  Msg::Init(argc, argv);

  // Load default options
  Init_Options(0);

  // Read configuration files and command line options
  Get_Options(argc, argv);

  // Make sure we have enough resources (stack)
  CheckResources();
  
#if !defined(HAVE_NO_POST)
  // Initialize the default plugins
  GMSH_PluginManager::instance()->registerDefaultPlugins();
#endif

  // Check for buggy obsolete GSL versions
  check_gsl();
  return 1;
}

int GmshSetMessageHandler(GmshMessage *callback)
{
  Msg::SetCallback(callback);
  return 1;
}

int GmshSetOption(std::string category, std::string name, std::string value, int index)
{
  if(StringOption(GMSH_SET, category.c_str(), index, name.c_str(), value.c_str()))
    return 1;
  return 0;
}

int GmshSetOption(std::string category, std::string name, double value, int index)
{
  if(NumberOption(GMSH_SET, category.c_str(), index, name.c_str(), value))
    return 1;
  return 0;
}

int GmshMergeFile(std::string fileName)
{
  return MergeFile(fileName.c_str(), 1);
}

int GmshFinalize()
{
  return 1;
}

int GmshBatch()
{
  if(!GModel::current()) return 0;

  Msg::Info("Running '%s'", Msg::GetCommandLine().c_str());
  Msg::Info("Started on %s", Msg::GetLaunchDate().c_str());

  OpenProject(CTX.filename);
  for(unsigned int i = 1; i < CTX.files.size(); i++){
    if(CTX.files[i] == "-new")
      new GModel;
    else
      MergeFile(CTX.files[i].c_str());
  }

#if !defined(HAVE_NO_POST)
  if(CTX.bgm_filename) {
    MergeFile(CTX.bgm_filename);
    if(PView::list.size())
      GModel::current()->getFields()->set_background_mesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }
#endif

  if(CTX.batch == -3){
    GmshDaemon(CTX.solver.socket_name);
  }
  else if(CTX.batch == -2){
    GModel::current()->checkMeshCoherence(CTX.geom.tolerance);
  }
  else if(CTX.batch == -1){
    CreateOutputFile(CTX.output_filename, FORMAT_GEO);
  }
  else if(CTX.batch > 0){
    if(CTX.batch < 4)
      GModel::current()->mesh(CTX.batch);
    else if(CTX.batch == 4)
      AdaptMesh(GModel::current());
    else if(CTX.batch == 5)
      RefineMesh(GModel::current());
#if defined(HAVE_CHACO) || defined(HAVE_METIS)
    if(CTX.batch_after_mesh == 1)
      PartitionMesh(GModel::current(), CTX.mesh.partition_options);
#endif
    CreateOutputFile(CTX.output_filename, CTX.mesh.format);
  }

  time_t now;
  time(&now);
  std::string currtime = ctime(&now);
  currtime.resize(currtime.size() - 1);
  Msg::Info("Stopped on %s", currtime.c_str());

  return 1;
}
