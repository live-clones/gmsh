// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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
#include "CurvedBndDist.h"
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
#include "CutMesh.h"
#include "SpanningTree.h"
#include "NewView.h"
#include "MeshSubEntities.h"
#include "MeshVolume.h"
#include "CVTRemesh.h"
#include "ShowNeighborElements.h"
#include "GaussPoints.h"
#include "VoroMetal.h"
#include "Summation.h"
#include "BoundaryAngles.h"
#include "MeshSizeFieldView.h"

// for testing purposes only :-)
#undef HAVE_DLOPEN

#if defined(HAVE_DLOPEN)
#include <dlfcn.h>
#endif

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#include <FL/filename.H>
#endif

const char *GMSH_PluginEntry = "GMSH_RegisterPlugin";

PluginManager *PluginManager::_instance = nullptr;

PluginManager::~PluginManager()
{
  for(auto it = allPlugins.begin(); it != allPlugins.end(); ++it)
    delete it->second;
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
  if(!plugin) throw std::runtime_error("Unknown plugin name");

  if(action == "Run") {
    Msg::Info("Running Plugin(%s)...", pluginName.c_str());
    int tag = plugin->run();
    Msg::Info("Done running Plugin(%s)", pluginName.c_str());
    return tag;
  }
  else
    throw std::runtime_error("Unknown plugin action");
}

void PluginManager::setPluginOption(const std::string &pluginName,
                                    const std::string &option,
                                    const std::string &value)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw std::runtime_error("Unknown plugin name");

  for(int i = 0; i < plugin->getNbOptionsStr(); i++) {
    StringXString *sxs = plugin->getOptionStr(i);
    if(option == std::string(sxs->str)) {
      sxs->def = value;
      return;
    }
  }
  throw std::runtime_error("Unknown plugin option name");
}

void PluginManager::setPluginOption(const std::string &pluginName,
                                    const std::string &option,
                                    double const value)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw std::runtime_error("Unknown plugin name");

  for(int i = 0; i < plugin->getNbOptions(); i++) {
    StringXNumber *sxn = plugin->getOption(i);
    if(option == std::string(sxn->str)) {
      sxn->def = value;
      return;
    }
  }
  throw std::runtime_error("Unknown plugin option name");
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
    allPlugins.insert(
      std::make_pair("CurvedBndDist", GMSH_RegisterCurvedBndDistPlugin()));
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
#if defined(HAVE_REVOROPT)
    allPlugins.insert(
      std::make_pair("CVTRemesh", GMSH_RegisterCVTRemeshPlugin()));
#endif
#if defined(HAVE_KBIPACK)
    allPlugins.insert(std::make_pair("HomologyComputation",
                                     GMSH_RegisterHomologyComputationPlugin()));
    allPlugins.insert(std::make_pair(
      "HomologyPostProcessing", GMSH_RegisterHomologyPostProcessingPlugin()));
#endif
#if defined(HAVE_SOLVER)
    allPlugins.insert(
      std::make_pair("Distance", GMSH_RegisterDistancePlugin()));
#endif
#if defined(HAVE_ANN)
    allPlugins.insert(
      std::make_pair("NearestNeighbor", GMSH_RegisterNearestNeighborPlugin()));
#endif
#if defined(HAVE_DINTEGRATION)
    allPlugins.insert(std::make_pair("CutMesh", GMSH_RegisterCutMeshPlugin()));
#endif
    allPlugins.insert(
      std::make_pair("SpanningTree", GMSH_RegisterSpanningTreePlugin()));
  }

#if defined(HAVE_FLTK)
  char *pluginsHome = getenv("GMSHPLUGINSHOME");
  if(!pluginsHome) return;
  struct dirent **list;
  int nbFiles = fl_filename_list(pluginsHome, &list);
  if(nbFiles <= 0) return;
  for(int i = 0; i < nbFiles; i++) {
    std::string ext = SplitFileName(list[i]->d_name)[2];
    if(ext == ".so" || ext == ".dll") addPlugin(list[i]->d_name);
  }
  for(int i = 0; i < nbFiles; i++) free(list[i]);
  free(list);
#endif
}

void PluginManager::addPlugin(const std::string &fileName)
{
#if !defined(HAVE_DLOPEN) || !defined(HAVE_FLTK)
  Msg::Warning("No dynamic plugin loading on this platform");
#else
  Msg::Info("Opening Plugin '%s'", fileName.c_str());
  void *hlib = dlopen(fileName.c_str(), RTLD_NOW);
  const char *err = dlerror();
  if(!hlib) {
    Msg::Warning("Could not open '%s' (dlerror = %s)", fileName.c_str(), err);
    return;
  }

  class GMSH_Plugin *(*registerPlugin)(void);
  registerPlugin =
    (class GMSH_Plugin * (*)(void)) dlsym(hlib, GMSH_PluginEntry);
  err = dlerror();
  if(err) {
    Msg::Warning("Symbol '%s' missing in '%s' (dlerror = %s)", GMSH_PluginEntry,
                 fileName.c_str(), err);
    return;
  }

  GMSH_Plugin *p = registerPlugin();
  p->hlib = hlib;
  if(allPlugins.find(p->getName()) != allPlugins.end()) {
    Msg::Warning("Plugin '%s' multiply defined", fileName.c_str());
    return;
  }

  allPlugins.insert(std::make_pair(p->getName(), p));
  Msg::Info("Loaded Plugin '%s' (%s)", p->getName().c_str(),
            p->getAuthor().c_str());
#endif
}
