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

  for(int i = 0; i < plugin->getNbOptionsStr(); i++) {
    StringXString *sxs = plugin->getOptionStr(i);
    if(option == std::string(sxs->str)) {
      sxs->def = value;
      return;
    }
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

  for(int i = 0; i < plugin->getNbOptions(); i++) {
    StringXNumber *sxn = plugin->getOption(i);
    if(option == std::string(sxn->str)) {
      sxn->def = value;
      return;
    }
  }
  throw std::runtime_error("Unknown option '" + option + "' of Plugin(" +
                           pluginName + ")");
}

PluginManager *PluginManager::instance()
{
  if(!_instance) _instance = new PluginManager;
  return _instance;
}

void PluginManager::registerDefaultPlugins()
{
  if(CTX::instance()->solver.plugins) {
    // nothing here yet
  }

  if(CTX::instance()->post.plugins) {
    allPlugins.insert(
      std::make_pair("StreamLines", GMSH_RegisterStreamLinesPlugin()));
    allPlugins.insert(
      std::make_pair("Particles", GMSH_RegisterParticlesPlugin()));
    allPlugins.insert(std::make_pair("CutGrid", GMSH_RegisterCutGridPlugin()));
    allPlugins.insert(
      std::make_pair("Isosurface", GMSH_RegisterIsosurfacePlugin()));
    allPlugins.insert(
      std::make_pair("CutPlane", GMSH_RegisterCutPlanePlugin()));
    allPlugins.insert(
      std::make_pair("CutSphere", GMSH_RegisterCutSpherePlugin()));
    allPlugins.insert(std::make_pair("CutBox", GMSH_RegisterCutBoxPlugin()));
    allPlugins.insert(std::make_pair("Skin", GMSH_RegisterSkinPlugin()));
    allPlugins.insert(
      std::make_pair("MathEval", GMSH_RegisterMathEvalPlugin()));
    allPlugins.insert(std::make_pair("ModifyComponents",
                                     GMSH_RegisterModifyComponentsPlugin()));
    allPlugins.insert(
      std::make_pair("ExtractElements", GMSH_RegisterExtractElementsPlugin()));
    allPlugins.insert(
      std::make_pair("CutParametric", GMSH_RegisterCutParametricPlugin()));
    allPlugins.insert(
      std::make_pair("MakeSimplex", GMSH_RegisterMakeSimplexPlugin()));
    allPlugins.insert(std::make_pair("Smooth", GMSH_RegisterSmoothPlugin()));
    allPlugins.insert(
      std::make_pair("Transform", GMSH_RegisterTransformPlugin()));
    allPlugins.insert(std::make_pair("LongitudeLatitude",
                                     GMSH_RegisterLongituteLatitudePlugin()));
    allPlugins.insert(std::make_pair("Warp", GMSH_RegisterWarpPlugin()));
    allPlugins.insert(
      std::make_pair("SphericalRaise", GMSH_RegisterSphericalRaisePlugin()));
    allPlugins.insert(
      std::make_pair("HarmonicToTime", GMSH_RegisterHarmonicToTimePlugin()));
    allPlugins.insert(
      std::make_pair("ModulusPhase", GMSH_RegisterModulusPhasePlugin()));
    allPlugins.insert(
      std::make_pair("Integrate", GMSH_RegisterIntegratePlugin()));
    allPlugins.insert(std::make_pair("MinMax", GMSH_RegisterMinMaxPlugin()));
    allPlugins.insert(
      std::make_pair("Gradient", GMSH_RegisterGradientPlugin()));
    allPlugins.insert(std::make_pair("Curl", GMSH_RegisterCurlPlugin()));
    allPlugins.insert(
      std::make_pair("Divergence", GMSH_RegisterDivergencePlugin()));
    allPlugins.insert(
      std::make_pair("Annotate", GMSH_RegisterAnnotatePlugin()));
    allPlugins.insert(std::make_pair("Remove", GMSH_RegisterRemovePlugin()));
    allPlugins.insert(
      std::make_pair("Eigenvectors", GMSH_RegisterEigenvectorsPlugin()));
    allPlugins.insert(
      std::make_pair("Eigenvalues", GMSH_RegisterEigenvaluesPlugin()));
    allPlugins.insert(std::make_pair("Lambda2", GMSH_RegisterLambda2Plugin()));
    allPlugins.insert(std::make_pair("Probe", GMSH_RegisterProbePlugin()));
    allPlugins.insert(
      std::make_pair("Triangulate", GMSH_RegisterTriangulatePlugin()));
    allPlugins.insert(
      std::make_pair("ExtractEdges", GMSH_RegisterExtractEdgesPlugin()));
    allPlugins.insert(std::make_pair(
      "FieldFromAmplitudePhase", GMSH_RegisterFieldFromAmplitudePhasePlugin()));
    allPlugins.insert(
      std::make_pair("NearToFarField", GMSH_RegisterNearToFarFieldPlugin()));
    allPlugins.insert(std::make_pair("Bubbles", GMSH_RegisterBubblesPlugin()));
    allPlugins.insert(std::make_pair("DiscretizationError",
                                     GMSH_RegisterDiscretizationErrorPlugin()));
    allPlugins.insert(
      std::make_pair("Scal2Tens", GMSH_RegisterScal2TensPlugin()));
    allPlugins.insert(
      std::make_pair("Scal2Vec", GMSH_RegisterScal2VecPlugin()));
    allPlugins.insert(std::make_pair("NewView", GMSH_RegisterNewViewPlugin()));
    allPlugins.insert(
      std::make_pair("SimplePartition", GMSH_RegisterSimplePartitionPlugin()));
    allPlugins.insert(std::make_pair("Crack", GMSH_RegisterCrackPlugin()));
    allPlugins.insert(std::make_pair("DuplicateNodes", GMSH_RegisterDuplicateNodesPlugin()));
    allPlugins.insert(std::make_pair(
      "ShowNeighborElements", GMSH_RegisterShowNeighborElementsPlugin()));
    allPlugins.insert(
      std::make_pair("MeshSubEntities", GMSH_RegisterMeshSubEntitiesPlugin()));
    allPlugins.insert(
      std::make_pair("MeshVolume", GMSH_RegisterMeshVolumePlugin()));
    allPlugins.insert(
      std::make_pair("GaussPoints", GMSH_RegisterGaussPointsPlugin()));
    allPlugins.insert(
      std::make_pair("Summation", GMSH_RegisterSummationPlugin()));
    allPlugins.insert(
      std::make_pair("BoundaryAngles", GMSH_RegisterBoundaryAnglesPlugin()));
    allPlugins.insert(
      std::make_pair("Invisible", GMSH_RegisterInvisiblePlugin()));
    allPlugins.insert(std::make_pair("HomologyComputation",
                                     GMSH_RegisterHomologyComputationPlugin()));
    allPlugins.insert(std::make_pair(
      "HomologyPostProcessing", GMSH_RegisterHomologyPostProcessingPlugin()));
#if defined(HAVE_MESH)
    allPlugins.insert(std::make_pair("AnalyseMeshQuality",
                                     GMSH_RegisterAnalyseMeshQualityPlugin()));
    allPlugins.insert(
      std::make_pair("VoroMetal", GMSH_RegisterVoroMetalPlugin()));
    allPlugins.insert(
      std::make_pair("Tetrahedralize", GMSH_RegisterTetrahedralizePlugin()));
    allPlugins.insert(std::make_pair("MeshSizeFieldView",
                                     GMSH_RegisterMeshSizeFieldViewPlugin()));

#endif
#if defined(HAVE_SOLVER)
    allPlugins.insert(
      std::make_pair("Distance", GMSH_RegisterDistancePlugin()));
#endif
#if defined(HAVE_ANN)
    allPlugins.insert(
      std::make_pair("NearestNeighbor", GMSH_RegisterNearestNeighborPlugin()));
#endif
    allPlugins.insert(
      std::make_pair("SpanningTree", GMSH_RegisterSpanningTreePlugin()));
#if defined(HAVE_BOUNDARY_LAYERS)
    allPlugins.insert(
      std::make_pair("BoundaryLayer", GMSH_RegisterBoundaryLayerPlugin()));
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
