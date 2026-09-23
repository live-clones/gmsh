// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include <filesystem>
#include <map>
#include <stdexcept>
#include <stdlib.h>
#include "GmshConfig.h"
#include "StringUtils.h"
#include "Context.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "Isosurface.h"
#include "CutGrid.h"
#include "StreamLines.h"
#include "Particles.h"
#include "CutPlane.h"
#include "CutParametric.h"
#include "CutSphere.h"
#include "CutBox.h"
#include "Skin.h"
#include "AnalyseMeshQuality.h"
#include "Invisible.h"
#include "MathEval.h"
#include "ExtractElements.h"
#include "SimplePartition.h"
#include "Crack.h"
#include "HarmonicToTime.h"
#include "ModulusPhase.h"
#include "Integrate.h"
#include "MinMax.h"
#include "Gradient.h"
#include "Curl.h"
#include "Divergence.h"
#include "Annotate.h"
#include "Distance.h"
#include "NearestNeighbor.h"
#include "Remove.h"
#include "MakeSimplex.h"
#include "Smooth.h"
#include "Transform.h"
#include "LongitudeLatitude.h"
#include "Triangulate.h"
#include "Tetrahedralize.h"
#include "Warp.h"
#include "SphericalRaise.h"
#include "Eigenvectors.h"
#include "Eigenvalues.h"
#include "Lambda2.h"
#include "ModifyComponents.h"
#include "Probe.h"
#include "HomologyComputation.h"
#include "HomologyPostProcessing.h"
#include "ExtractEdges.h"
#include "FieldFromAmplitudePhase.h"
#include "Bubbles.h"
#include "NearToFarField.h"
#include "DiscretizationError.h"
#include "Scal2Tens.h"
#include "Scal2Vec.h"
#include "SpanningTree.h"
#include "NewView.h"
#include "MeshSubEntities.h"
#include "MeshVolume.h"
#include "ShowNeighborElements.h"
#include "GaussPoints.h"
#include "VoroMetal.h"
#include "Summation.h"
#include "BoundaryAngles.h"
#include "MeshSizeFieldView.h"
#include "DuplicateNodes.h"

#if defined(HAVE_BOUNDARY_LAYERS)
#include "BoundaryLayer.h"
#endif

// HAVE_PLUGIN_LOADING is only defined when compiling the shared library with
// the private API (which exports what plugins need) on a system with dlopen
#if defined(HAVE_PLUGIN_LOADING)
#include <dlfcn.h>
#endif

PluginManager *PluginManager::_instance = nullptr;

PluginManager::~PluginManager()
{
  // the plugins first: their code is in the libraries
  for(auto it = allPlugins.begin(); it != allPlugins.end(); ++it)
    delete it->second;
#if defined(HAVE_PLUGIN_LOADING)
  for(auto lib : _libraries) dlclose(lib);
#endif
  _instance = nullptr;
}

GMSH_Plugin *PluginManager::find(const std::string &pluginName)
{
  auto it = allPlugins.find(pluginName);
  if(it == allPlugins.end()) return nullptr;
  return it->second;
}

GMSH_SolverPlugin *PluginManager::findSolverPlugin()
{
  auto it = allPlugins.begin();
  auto ite = allPlugins.end();
  for(; it != ite; ++it) {
    GMSH_Plugin *p = it->second;
    if(p->getType() == GMSH_Plugin::GMSH_SOLVER_PLUGIN) {
      return (GMSH_SolverPlugin *)(p);
    }
  }
  return nullptr;
}

int PluginManager::action(const std::string &pluginName,
                          const std::string &action, void *data)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw std::runtime_error("Unknown plugin '" + pluginName + "'");

  if(action == "Run") {
    Msg::Info("Running Plugin(%s)...", pluginName.c_str());
    int tag = plugin->run();
    Msg::Info("Done running Plugin(%s)", pluginName.c_str());
    return tag;
  }
  else
    throw std::runtime_error("Unknown action '" + action + "' of Plugin(" +
                             pluginName + ")");
}

void PluginManager::setPluginOption(const std::string &pluginName,
                                    const std::string &option,
                                    const std::string &value)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw std::runtime_error("Unknown plugin '" + pluginName + "'");

  StringXString *sxs = plugin->findOptionStr(option);
  if(sxs) {
    sxs->def = value;
    return;
  }
  throw std::runtime_error("Unknown option '" + option + "' of Plugin(" +
                           pluginName + ")");
}

void PluginManager::setPluginOption(const std::string &pluginName,
                                    const std::string &option,
                                    double const value)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw std::runtime_error("Unknown plugin '" + pluginName + "'");

  StringXNumber *sxn = plugin->findOption(option);
  if(sxn) {
    sxn->def = value;
    return;
  }
  throw std::runtime_error("Unknown option '" + option + "' of Plugin(" +
                           pluginName + ")");
}

PluginManager *PluginManager::instance()
{
  if(!_instance) _instance = new PluginManager;
  return _instance;
}

void PluginManager::add(GMSH_Plugin *p) { allPlugins[p->getName()] = p; }

void PluginManager::registerDefaultPlugins()
{
  if(CTX::instance()->solver.plugins) {
    // nothing here yet
  }

  if(CTX::instance()->post.plugins) {
    add(new GMSH_StreamLinesPlugin());
    add(new GMSH_ParticlesPlugin());
    add(new GMSH_CutGridPlugin());
    add(new GMSH_IsosurfacePlugin());
    add(new GMSH_CutPlanePlugin());
    add(new GMSH_CutSpherePlugin());
    add(new GMSH_CutBoxPlugin());
    add(new GMSH_SkinPlugin());
    add(new GMSH_MathEvalPlugin());
    add(new GMSH_ModifyComponentsPlugin());
    add(new GMSH_ExtractElementsPlugin());
    add(new GMSH_CutParametricPlugin());
    add(new GMSH_MakeSimplexPlugin());
    add(new GMSH_SmoothPlugin());
    add(new GMSH_TransformPlugin());
    add(new GMSH_LongitudeLatitudePlugin());
    add(new GMSH_WarpPlugin());
    add(new GMSH_SphericalRaisePlugin());
    add(new GMSH_HarmonicToTimePlugin());
    add(new GMSH_ModulusPhasePlugin());
    add(new GMSH_IntegratePlugin());
    add(new GMSH_MinMaxPlugin());
    add(new GMSH_GradientPlugin());
    add(new GMSH_CurlPlugin());
    add(new GMSH_DivergencePlugin());
    add(new GMSH_AnnotatePlugin());
    add(new GMSH_RemovePlugin());
    add(new GMSH_EigenvectorsPlugin());
    add(new GMSH_EigenvaluesPlugin());
    add(new GMSH_Lambda2Plugin());
    add(new GMSH_ProbePlugin());
    add(new GMSH_TriangulatePlugin());
    add(new GMSH_ExtractEdgesPlugin());
    add(new GMSH_FieldFromAmplitudePhasePlugin());
    add(new GMSH_NearToFarFieldPlugin());
    add(new GMSH_BubblesPlugin());
    add(new GMSH_DiscretizationErrorPlugin());
    add(new GMSH_Scal2TensPlugin());
    add(new GMSH_Scal2VecPlugin());
    add(new GMSH_NewViewPlugin());
    add(new GMSH_SimplePartitionPlugin());
    add(new GMSH_CrackPlugin());
    add(new GMSH_DuplicateNodesPlugin());
    add(new GMSH_ShowNeighborElementsPlugin());
    add(new GMSH_MeshSubEntitiesPlugin());
    add(new GMSH_MeshVolumePlugin());
    add(new GMSH_GaussPointsPlugin());
    add(new GMSH_SummationPlugin());
    add(new GMSH_BoundaryAnglesPlugin());
    add(new GMSH_InvisiblePlugin());
    add(new GMSH_HomologyComputationPlugin());
    add(new GMSH_HomologyPostProcessingPlugin());
#if defined(HAVE_MESH)
    add(new GMSH_AnalyseMeshQualityPlugin());
    add(new GMSH_VoroMetalPlugin());
    add(new GMSH_TetrahedralizePlugin());
    add(new GMSH_MeshSizeFieldViewPlugin());

#endif
#if defined(HAVE_SOLVER)
    add(new GMSH_DistancePlugin());
#endif
#if defined(HAVE_ANN)
    add(new GMSH_NearestNeighborPlugin());
#endif
    add(new GMSH_SpanningTreePlugin());
#if defined(HAVE_BOUNDARY_LAYERS)
    add(GMSH_RegisterBoundaryLayerPlugin());
#endif
  }

  // the plugins in the directories of $GMSHPLUGINSHOME
  const char *home = getenv("GMSHPLUGINSHOME");
  if(home) addPlugins(home);
}

void PluginManager::addPlugins(const std::string &dirs)
{
  // directories separated like in PATH
#if defined(_WIN32)
  const char sep = ';';
#else
  const char sep = ':';
#endif
  std::size_t beg = 0;
  while(beg <= dirs.size()) {
    std::size_t end = dirs.find(sep, beg);
    if(end == std::string::npos) end = dirs.size();
    std::string dir = dirs.substr(beg, end - beg);
    beg = end + 1;
    if(dir.empty()) continue;
    std::error_code ec;
    std::vector<std::string> files;
    for(auto &f : std::filesystem::directory_iterator(dir, ec)) {
      std::string ext = f.path().extension().string();
      if(ext == ".so" || ext == ".dylib" || ext == ".dll")
        files.push_back(f.path().string());
    }
    if(ec) {
      Msg::Warning("Could not read plugin directory '%s'", dir.c_str());
      continue;
    }
    std::sort(files.begin(), files.end()); // in the same order everywhere
    for(auto &f : files) addPlugin(f);
  }
}

bool PluginManager::addPlugin(const std::string &fileName)
{
#if !defined(HAVE_PLUGIN_LOADING)
  Msg::Error("Cannot load plugin '%s': loading plugins requires Gmsh to be "
             "built as a shared library with the private API "
             "(ENABLE_BUILD_DYNAMIC or ENABLE_BUILD_SHARED, and "
             "ENABLE_PRIVATE_API), on a system with dlopen",
             fileName.c_str());
  return false;
#else
  void *lib = dlopen(fileName.c_str(), RTLD_NOW | RTLD_LOCAL);
  if(!lib) {
    Msg::Error("Could not load plugin '%s' (%s)", fileName.c_str(), dlerror());
    return false;
  }
  // the functions defined by GMSH_PLUGIN() in Plugin.h
  auto version = (int (*)())dlsym(lib, "GMSH_PluginApiVersion");
  auto create = (GMSH_Plugin * (*)()) dlsym(lib, "GMSH_RegisterPlugin");
  if(!version || !create) {
    Msg::Error("'%s' is not a Gmsh plugin (it does not define "
               "GMSH_PluginApiVersion() and GMSH_RegisterPlugin(), which "
               "GMSH_PLUGIN() in Plugin.h defines)", fileName.c_str());
    dlclose(lib);
    return false;
  }
  if(version() != GMSH_PLUGIN_API_VERSION) {
    Msg::Error("Plugin '%s' was built for version %d of the plugin interface, "
               "this Gmsh has version %d: rebuild it", fileName.c_str(),
               version(), GMSH_PLUGIN_API_VERSION);
    dlclose(lib);
    return false;
  }
  GMSH_Plugin *p = create();
  if(!p) {
    Msg::Error("Plugin '%s' could not be created", fileName.c_str());
    dlclose(lib);
    return false;
  }
  std::string name = p->getName();
  if(allPlugins.count(name)) {
    Msg::Error("Plugin '%s' in '%s' is already defined", name.c_str(),
               fileName.c_str());
    delete p;
    dlclose(lib);
    return false;
  }
  allPlugins[name] = p;
  _libraries.push_back(lib);
  Msg::Info("Loaded Plugin(%s) from '%s'", name.c_str(), fileName.c_str());
  return true;
#endif
}
