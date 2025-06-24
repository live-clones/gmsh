// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "GmshGlobal.h"
#include "GmshRemote.h"
#include "GModel.h"
#include "OpenFile.h"
#include "CreateFile.h"
#include "Options.h"
#include "CommandLine.h"
#include "OS.h"
#include "Context.h"
#include "robustPredicates.h"
#include "BasisFactory.h"

#if defined(HAVE_PARSER)
#include "Parser.h"
#endif

#if defined(HAVE_POST)
#include "PView.h"
#include "PViewData.h"
#include "PViewOptions.h"
#endif

#if defined(HAVE_ONELAB)
#include "onelabUtils.h"
#include "gmshLocalNetworkClient.h"
#endif

#if defined(HAVE_MESH)
#include "Field.h"
#include "meshPartition.h"
#include "gmshCrossFields.h"
#include "automaticMeshSizeField.h"
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

static bool isInitialized = false;

int GmshInitialize(int argc, char **argv, bool readConfigFiles,
                   bool exitOnCommandLineError)
{
  if(isInitialized) return 1;
  isInitialized = true;

#if defined(HAVE_FLTK)
  RedirectIOToConsole();
#endif

  // we need at least one model during option parsing
  GModel *dummy = nullptr;
  if(GModel::list.empty()) dummy = new GModel();

  // Initialize messages (parallel stuff, etc.)
  Msg::Initialize(argc, argv);

  // Load default options
  InitOptions(0);

  // Read configuration files and command line options
  GetOptions(readConfigFiles, exitOnCommandLineError);

  // Make sure we have enough resources (stack)
  CheckResources();

#if defined(HAVE_PLUGINS)
  // Initialize the default plugins
  PluginManager::instance()->registerDefaultPlugins();
#endif

  // Initialize robust predicates (no static filter for now, we do not know the
  // size of the domain)
  robustPredicates::exactinit(1.0, 1.0, 1.0);

  if(dummy) delete dummy;
  return 1;
}

int GmshSetMessageHandler(GmshMessage *callback)
{
  Msg::SetCallback(callback);
  return 1;
}

GmshMessage *GmshGetMessageHandler() { return Msg::GetCallback(); }

int GmshSetBoundingBox(double xmin, double xmax, double ymin, double ymax,
                       double zmin, double zmax)
{
  SetBoundingBox(xmin, xmax, ymin, ymax, zmin, zmax);
  return 1;
}

int GmshSetOption(const std::string &category, const std::string &name,
                  std::string value, int index)
{
  return StringOption(GMSH_SET | GMSH_GUI, category.c_str(), index,
                      name.c_str(), value, false);
}

int GmshSetOption(const std::string &category, const std::string &name,
                  double value, int index)
{
  return NumberOption(GMSH_SET | GMSH_GUI, category.c_str(), index,
                      name.c_str(), value, false);
}

int GmshSetOption(const std::string &category, const std::string &name,
                  unsigned int value, int index)
{
  return ColorOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
                     value, false);
}

void GmshSetStringOption(const std::string &category, const std::string &name,
                         std::string value, int index)
{
  StringOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
               value, false);
}

void GmshSetNumberOption(const std::string &category, const std::string &name,
                         double value, int index)
{
  NumberOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(),
               value, false);
}

void GmshSetColorOption(const std::string &category, const std::string &name,
                        unsigned int value, int index)
{
  ColorOption(GMSH_SET | GMSH_GUI, category.c_str(), index, name.c_str(), value,
              false);
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

std::string GmshGetStringOption(const std::string &category,
                                const std::string &name, int index)
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

unsigned int GmshGetColorOption(const std::string &category,
                                const std::string &name, int index)
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
  OpenProject(fileName, true);
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
  return MergePostProcessingFile(
    fileName, CTX::instance()->solver.autoShowViews,
    CTX::instance()->solver.autoShowLastStep, true);
}

int GmshWriteFile(const std::string &fileName)
{
  CreateOutputFile(fileName, FORMAT_AUTO);
  return 1;
}

int GmshFinalize()
{
  // delete all models and views
  DeleteAllModelsAndViews();

  // clear remaining static data
#if defined(HAVE_PLUGINS)
  delete PluginManager::instance();
#endif
  BasisFactory::clearAll();
  Msg::Finalize();
  isInitialized = false;
  return 1;
}

static void StartupMessage()
{
  int nt = CTX::instance()->numThreads;
  if(!nt) nt = Msg::GetMaxThreads();
  Msg::Info("Running '%s' [Gmsh %s, %d node%s, max. %d thread%s]",
            Msg::GetCommandLineFull().c_str(), GMSH_VERSION, Msg::GetCommSize(),
            Msg::GetCommSize() > 1 ? "s" : "", nt, nt > 1 ? "s" : "");
  Msg::Info("Started on %s", Msg::GetLaunchDate().c_str());
}

static void GoodbyeMessage()
{
  time_t now;
  time(&now);
  std::string currtime = ctime(&now);
  currtime.resize(currtime.size() - 1);
  Msg::SetInfoCpu(true); // always print cpu info at the end
  Msg::Info("Stopped on %s", currtime.c_str());
}

int GmshBatch()
{
  StartupMessage();

  OpenProject(GModel::current()->getFileName(), true); // warn if file missing
  bool open = false;
  for(std::size_t i = 0; i < CTX::instance()->files.size(); i++) {
    if(i == 0 && CTX::instance()->files[0][0] != '-') continue;
    if(CTX::instance()->files[i] == "-new")
      new GModel();
    else if(CTX::instance()->files[i] == "-merge")
      open = false;
    else if(CTX::instance()->files[i] == "-open")
      open = true;
    else if(open)
      OpenProject(CTX::instance()->files[i], true); // warn if file missing
    else
      MergeFile(CTX::instance()->files[i]);
  }

#if defined(HAVE_POST) && defined(HAVE_MESH)
  if(!CTX::instance()->bgmFileName.empty()) {
    if(CTX::instance()->bgmFileName.substr(
         CTX::instance()->bgmFileName.find_last_of(".") + 1) == "p4est") {
      automaticMeshSizeField *a =
        new automaticMeshSizeField(CTX::instance()->bgmFileName);
      GModel::current()->getFields()->setBackgroundField(a);
    }
    else {
      MergePostProcessingFile(CTX::instance()->bgmFileName);
      if(PView::list.size())
        GModel::current()->getFields()->setBackgroundMesh(PView::list.size() -
                                                          1);
      else
        Msg::Error("Invalid background mesh (no view)");
    }
  }
#endif

  if(CTX::instance()->batch == -3) { GmshRemote(); }
  else if(CTX::instance()->batch == -2) {
    GModel::current()->checkMeshCoherence(CTX::instance()->geom.tolerance);
#if defined(HAVE_PARSER)
    std::vector<std::string> s;
    PrintParserSymbols(0, s);
    for(std::size_t i = 0; i < s.size(); i++) Msg::Direct("%s", s[i].c_str());
#endif
  }
  else if(CTX::instance()->batch == -1) {
    CreateOutputFile(CTX::instance()->outputFileName,
                     CTX::instance()->outputFileName.empty() ? FORMAT_GEO :
                                                               FORMAT_AUTO);
  }
  else if(CTX::instance()->batch > 0) {
#if defined(HAVE_MESH)
    if(CTX::instance()->batch < 4)
      GModel::current()->mesh(CTX::instance()->batch);
    else if(CTX::instance()->batch == 4)
      GModel::current()->adaptMesh();
    else if(CTX::instance()->batch == 5)
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear);
    else if(CTX::instance()->batch == 6)
      GModel::current()->refineMesh(CTX::instance()->mesh.secondOrderLinear,
                                    false, false, true);
    else if(CTX::instance()->batch == 7)
      GModel::current()->classifySurfaces(
        CTX::instance()->batchSomeValue * M_PI / 180., true, false, M_PI);
    else if(CTX::instance()->batch == 8) {
      GModel::current()->classifySurfaces(
        CTX::instance()->batchSomeValue * M_PI / 180., true, true, M_PI);
      GModel::current()->createGeometryOfDiscreteEntities();
    }
    else if(CTX::instance()->batch == 9) {
      GModel::current()->computeSizeField();
    }
    else if(CTX::instance()->batch == 69) {

      //      void testRelaying();
      //      testRelaying() ;
      //      
      //
      
      std::vector<int> tags;
      computeCrossField(GModel::current(), tags);
      GoodbyeMessage();
      CTX::instance()->batch = 0;
      // still a bug in allocation somewhere
      exit(0);
      
    }
#endif
  }

  if(CTX::instance()->batchAfterMesh == 1 &&
     CTX::instance()->mesh.numPartitions > 1)
    GModel::current()->partitionMesh(CTX::instance()->mesh.numPartitions);

  if(CTX::instance()->batch > 0 || CTX::instance()->batchAfterMesh) {
    std::string name = CTX::instance()->outputFileName;
    if(name.empty()) {
      if(CTX::instance()->mesh.fileFormat == FORMAT_AUTO)
        name = GetDefaultFileName(FORMAT_MSH);
      else
        name = GetDefaultFileName(CTX::instance()->mesh.fileFormat);
    }
    CreateOutputFile(name, CTX::instance()->mesh.fileFormat);
  }

  // launch solver (if requested)
#if defined(HAVE_ONELAB)
  onelabUtils::runClient();
#endif

  GoodbyeMessage();
  return 1;
}

int GmshFLTK(int argc, char **argv)
{
#if defined(HAVE_FLTK) && defined(HAVE_POST)
  // create the GUI
  FlGui::instance(argc, argv);

  StartupMessage();

  // display GUI immediately for quick launch time
  FlGui::check();

  if(FlGui::getOpenedThroughMacFinder().size() &&
     CTX::instance()->files.empty()) {
    OpenProject(FlGui::getOpenedThroughMacFinder());
  }
  else {
    OpenProject(GModel::current()->getFileName());
    bool open = false;
    for(std::size_t i = 0; i < CTX::instance()->files.size(); i++) {
      if(i == 0 && CTX::instance()->files[0][0] != '-') continue;
      if(CTX::instance()->files[i] == "-new") {
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

  FlGui::instance()->setFinishedProcessingCommandLine();

  if(CTX::instance()->post.combineTime) {
    PView::combine(true, 2, CTX::instance()->post.combineRemoveOrig,
                   CTX::instance()->post.combineCopyOptions);
    FlGui::instance()->updateViews(true, true);
  }

  // init first context
  switch(CTX::instance()->initialContext) {
  case 1: FlGui::instance()->openModule("Geometry"); break;
  case 2: FlGui::instance()->openModule("Mesh"); break;
  case 3: FlGui::instance()->openModule("Solver"); break;
  case 4: FlGui::instance()->openModule("Post-processing"); break;
  default: // automatic
    if(PView::list.size()) FlGui::instance()->openModule("Post-processing");
    break;
  }

#if defined(HAVE_POST) && defined(HAVE_MESH)
  // read background mesh if any
  if(!CTX::instance()->bgmFileName.empty()) {
    // If the background mesh is an octree (we us p4est), then we load the
    // background mesh as an automaticMeshSizeField
    if(CTX::instance()->bgmFileName.substr(
         CTX::instance()->bgmFileName.find_last_of(".") + 1) == "p4est") {
      automaticMeshSizeField *a =
        new automaticMeshSizeField(CTX::instance()->bgmFileName);
      //      int newId = GModel::current()->getFields()->newId();
      //      (*GModel::current()->getFields())[newId] = a;
      //      printf("loading %s\n",CTX::instance()->bgmFileName.c_str());
      GModel::current()->getFields()->setBackgroundField(a);
    }
    else {
      MergePostProcessingFile(CTX::instance()->bgmFileName);
      if(PView::list.size())
        GModel::current()->getFields()->setBackgroundMesh(PView::list.size() -
                                                          1);
      else
        Msg::Error("Invalid background mesh (no view)");
    }
  }
#endif

  // listen to external solvers
  if(CTX::instance()->solver.listen) {
    gmshLocalNetworkClient *c = new gmshLocalNetworkClient("Listen", "");
    c->run();
  }

  // launch solver (if requested) and fill onelab tree
  solver_cb(nullptr, (void *)(intptr_t)CTX::instance()->launchSolverAtStartup);

  // loop
  return FlGui::instance()->run();

#else
  Msg::Error("GmshFLTK unavailable: please recompile with FLTK support");
  return 0;
#endif
}

GMSH_API int GmshMainBatch(int argc, char **argv)
{
  if(argc < 2) {
    CTX::instance()->terminal = 1;
    PrintUsage(argv[0]);
    exit(0);
  }

  new GModel();
  GmshInitialize(argc, argv, true);

  if(!Msg::GetGmshClient()) CTX::instance()->terminal = 1;
  CTX::instance()->noPopup = 1;

  GmshBatch();
  GmshFinalize();
  Msg::Exit(0);
  return 1;
}

GMSH_API int GmshMainFLTK(int argc, char **argv)
{
  // Create a new model
  new GModel();

  // Hack to generate automatic documentation (before getting
  // user-defined options)
  if(argc == 2 && std::string(argv[1]) == "-doc") {
    InitOptions(0);
#if defined(HAVE_PLUGINS)
    PluginManager::instance()->registerDefaultPlugins();
#endif
    PrintOptionsDoc();
    exit(0);
  }

  // Initialize static stuff (parser symbols, options)
  GmshInitialize(argc, argv, true);

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
