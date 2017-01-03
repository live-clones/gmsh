// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <string>
#include <time.h>
#include "GmshConfig.h"
#if !defined(HAVE_NO_STDINT_H)
#include <stdint.h>
#elif defined(HAVE_NO_INTPTR_T)
typedef unsigned long intptr_t;
#endif
#include "GmshVersion.h"
#include "GmshMessage.h"
#include "GmshDefines.h"
#include "GmshRemote.h"
#include "GModel.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#if defined(HAVE_PARSER)
#include "Parser.h"
#endif
#include "CommandLine.h"
#include "OS.h"
#include "Context.h"
#include "robustPredicates.h"
#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_ONELAB)
#include "gmshLocalNetworkClient.h"
#endif

#if defined(HAVE_MESH)
#include "Generator.h"
#include "Field.h"
#include "meshPartition.h"
#endif

#if defined(HAVE_PLUGINS)
#include "PluginManager.h"
#endif

#if defined(HAVE_FLTK)
#include "FlGui.h"
#include "graphicWindow.h"
#include "drawContext.h"
#include "onelabGroup.h"
#endif

int GmshInitialize(int argc, char **argv)
{
  static bool isInitialized = false;
  if(isInitialized) return 1;
  isInitialized = true;

#if defined(HAVE_FLTK)
  RedirectIOToConsole();
#endif

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

#if defined(HAVE_PLUGINS)
  // Initialize the default plugins
  PluginManager::instance()->registerDefaultPlugins();
#endif

  // Initialize robust predicates (no static filter for now, we do not know the
  // size of the domain)
  robustPredicates::exactinit(0, 1.0, 1.0, 1.0);

  if(dummy) delete dummy;
  return 1;
}

int GmshSetMessageHandler(GmshMessage *callback)
{
  Msg::SetCallback(callback);
  return 1;
}

GmshMessage *GmshGetMessageHandler()
{
  return Msg::GetCallback();
}

int GmshSetBoundingBox(double xmin, double xmax,
                       double ymin, double ymax,
                       double zmin, double zmax)
{
  SetBoundingBox(xmin, xmax, ymin, ymax, zmin, zmax);
  return 1;
}

int GmshSetOption(const std::string &category, const std::string &name,
                  std::string value, int index)
{
  return StringOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(),
                      value, false);
}

int GmshSetOption(const std::string &category, const std::string &name,
                  double value, int index)
{
  return NumberOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(),
                      value, false);
}

int GmshSetOption(const std::string &category, const std::string &name,
                  unsigned int value, int index)
{
  return ColorOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(),
                     value, false);
}

void GmshSetStringOption(const std::string &category, const std::string &name,
                         std::string value, int index)
{
  StringOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(),
               value, false);
}

void GmshSetNumberOption(const std::string &category, const std::string &name,
                         double value, int index)
{
  NumberOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(),
               value, false);
}

void GmshSetColorOption(const std::string &category, const std::string &name,
                        unsigned int value, int index)
{
  ColorOption(GMSH_SET|GMSH_GUI, category.c_str(), index, name.c_str(),
              value, false);
}

int GmshGetOption(const std::string &category, const std::string &name,
                  std::string &value, int index)
{
  return StringOption(GMSH_GET, category.c_str(), index, name.c_str(), value,
                      false);
}

int GmshGetOption(const std::string &category, const std::string &name,
                  double &value, int index)
{
  return NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), value,
                      false);
}

int GmshGetOption(const std::string &category, const std::string &name,
                  unsigned int &value, int index)
{
  return ColorOption(GMSH_GET, category.c_str(), index, name.c_str(), value,
                     false);
}

std::string GmshGetStringOption(const std::string &category, const std::string &name,
                                int index)
{
  std::string value;
  StringOption(GMSH_GET, category.c_str(), index, name.c_str(), value, false);
  return value;
}

double GmshGetNumberOption(const std::string &category, const std::string &name,
                           int index)
{
  double value;
  NumberOption(GMSH_GET, category.c_str(), index, name.c_str(), value, false);
  return value;
}

unsigned int GmshGetColorOption(const std::string &category, const std::string &name,
                       int index)
{
  unsigned int value;
  ColorOption(GMSH_GET, category.c_str(), index, name.c_str(), value, false);
  return value;
}

int GmshRestoreDefaultOptions()
{
  ReInitOptions(0);
  InitOptionsGUI(0);
  return 1;
}

int GmshOpenProject(const std::string &fileName)
{
  OpenProject(fileName);
  return 1;
}

int GmshClearProject()
{
  ClearProject();
  return 1;
}

int GmshMergeFile(const std::string &fileName)
{
  return MergeFile(fileName, true);
}

int GmshMergePostProcessingFile(const std::string &fileName)
{
  return MergePostProcessingFile(fileName, CTX::instance()->solver.autoShowViews,
                                 CTX::instance()->solver.autoShowLastStep, true);
}

int GmshWriteFile(const std::string &fileName)
{
  CreateOutputFile(fileName, FORMAT_AUTO);
  return 1;
}

int GmshFinalize()
{
#if defined(HAVE_POST)
  // Delete all PViewData stored in static list of PView class
  for(unsigned int i = 0; i < PView::list.size(); i++) {
    delete PView::list[i];
  }
  PView::list.clear();

  // Delete static _interpolationSchemes of PViewData class
  PViewData::removeAllInterpolationSchemes();
#endif
  // Delete all Gmodels
  for(unsigned int i = 0; i < GModel::list.size(); i++)
    delete GModel::list[i];
  GModel::list.clear();

  return 1;
}

int GmshBatch()
{
  Msg::Info("Running '%s' [Gmsh %s, %d node%s, max. %d thread%s]",
            Msg::GetCommandLineArgs().c_str(), GMSH_VERSION,
            Msg::GetCommSize(), Msg::GetCommSize() > 1 ? "s" : "",
            Msg::GetMaxThreads(), Msg::GetMaxThreads() > 1 ? "s" : "");
  Msg::Info("Started on %s", Msg::GetLaunchDate().c_str());

  OpenProject(GModel::current()->getFileName());
  bool open = false;
  for(unsigned int i = 0; i < CTX::instance()->files.size(); i++){
    if(i == 0 && CTX::instance()->files[0][0] != '-') continue;
    if(CTX::instance()->files[i] == "-new")
      new GModel();
    else if(CTX::instance()->files[i] == "-merge")
      open = false;
    else if(CTX::instance()->files[i] == "-open")
      open = true;
    else if(open)
      OpenProject(CTX::instance()->files[i]);
    else
      MergeFile(CTX::instance()->files[i]);
  }


#if defined(HAVE_POST) && defined(HAVE_MESH)
  if(!CTX::instance()->bgmFileName.empty()) {
    MergePostProcessingFile(CTX::instance()->bgmFileName);
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
#if defined(HAVE_PARSER)
    std::vector<std::string> s;
    PrintParserSymbols(0, s);
    for(unsigned int i = 0; i < s.size(); i++)
      Msg::Direct("%s", s[i].c_str());
#endif
  }
  else if(CTX::instance()->batch == -1){
    CreateOutputFile(CTX::instance()->outputFileName,
                     CTX::instance()->outputFileName.empty() ? FORMAT_GEO :
                     FORMAT_AUTO);
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
    std::string name = CTX::instance()->outputFileName;
    if(name.empty()){
      if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
        name = GetDefaultFileName(FORMAT_MSH);
      else
        name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
    }
    CreateOutputFile(name, CTX::instance()->mesh.fileFormat);
  }

  // launch solver (if requested)
#if defined(HAVE_ONELAB)
  solver_batch_cb((void*)(intptr_t)CTX::instance()->launchSolverAtStartup);
#endif

  time_t now;
  time(&now);
  std::string currtime = ctime(&now);
  currtime.resize(currtime.size() - 1);
  Msg::Info("Stopped on %s", currtime.c_str());

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
  if(FlGui::getOpenedThroughMacFinder().empty()){
    OpenProject(GModel::current()->getFileName());
    bool open = false;
    for(unsigned int i = 0; i < CTX::instance()->files.size(); i++){
      if(i == 0 && CTX::instance()->files[0][0] != '-') continue;
      if(CTX::instance()->files[i] == "-new"){
        GModel::current()->setVisibility(0);
        new GModel();
      }
      else if(CTX::instance()->files[i] == "-merge")
        open = false;
      else if(CTX::instance()->files[i] == "-open")
        open = true;
      else if(open)
        OpenProject(CTX::instance()->files[i]);
      else
        MergeFile(CTX::instance()->files[i]);
    }
  }
  else{
    OpenProject(FlGui::getOpenedThroughMacFinder());
  }

  if(CTX::instance()->post.combineTime){
    PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig);
    FlGui::instance()->updateViews(true, true);
  }

  // init first context
  switch (CTX::instance()->initialContext) {
  case 1: FlGui::instance()->openModule("Geometry"); break;
  case 2: FlGui::instance()->openModule("Mesh"); break;
  case 3: FlGui::instance()->openModule("Solver"); break;
  case 4: FlGui::instance()->openModule("Post-processing"); break;
  default: // automatic
    if(PView::list.size()) FlGui::instance()->openModule("Post-processing");
    break;
  }

  // read background mesh if any
  if(!CTX::instance()->bgmFileName.empty()) {
    MergePostProcessingFile(CTX::instance()->bgmFileName);
    if(PView::list.size())
      GModel::current()->getFields()->setBackgroundMesh(PView::list.size() - 1);
    else
      Msg::Error("Invalid background mesh (no view)");
  }

  // listen to external solvers
  if(CTX::instance()->solver.listen){
    gmshLocalNetworkClient *c = new gmshLocalNetworkClient("Listen", "");
    c->run();
  }

  // launch solver (if requested) and fill onelab tree
  solver_cb(0, (void*)(intptr_t)CTX::instance()->launchSolverAtStartup);

  // loop
  return FlGui::instance()->run();
#else
  Msg::Error("GmshFLTK unavailable: please recompile with FLTK support");
  return 0;
#endif
}
