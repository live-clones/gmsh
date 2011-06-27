// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <map>
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
#include "AnalyseCurvedMesh.h"
#include "MathEval.h"
#include "ExtractElements.h"
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
#include "ModifyComponent.h"
#include "Probe.h"
#include "GSHHS.h"
#include "HomologyComputation.h"
#include "ExtractEdges.h"
#include "FieldFromAmplitudePhase.h"
#include "Bubbles.h"
#include "NearToFarField.h"
#include "DiscretizationError.h"

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

PluginManager *PluginManager::_instance = 0;

PluginManager::~PluginManager()
{
  for(std::map<std::string, GMSH_Plugin*>::iterator it = allPlugins.begin();
      it != allPlugins.end(); ++it)
    delete it->second;
}

GMSH_Plugin *PluginManager::find(std::string pluginName)
{
  std::map<std::string, GMSH_Plugin*>::iterator it = allPlugins.find(pluginName);
  if(it == allPlugins.end())
    return 0;
  return it->second;
}

GMSH_SolverPlugin *PluginManager::findSolverPlugin()
{
  std::map<std::string, GMSH_Plugin*>::iterator it = allPlugins.begin();
  std::map<std::string, GMSH_Plugin*>::iterator ite = allPlugins.end();
  for (; it != ite; ++it) {
    GMSH_Plugin *p = it->second;
    if(p->getType() == GMSH_Plugin::GMSH_SOLVER_PLUGIN) {
      return (GMSH_SolverPlugin*)(p);
    }
  }
  return 0;
}

void PluginManager::action(std::string pluginName, std::string action, void *data)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw "Unknown plugin name";

  if(action == "Run")
    plugin->run();
  else
    throw "Unknown plugin action";
}

void PluginManager::setPluginOption(std::string pluginName, std::string option,
                                    std::string value)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw "Unknown plugin name";

  for(int i = 0; i < plugin->getNbOptionsStr(); i++) {
    StringXString *sxs = plugin->getOptionStr(i);
    if(option == std::string(sxs->str)) {
      sxs->def = value;
      return;
    }
  }
  throw "Unknown plugin option name";
}

void PluginManager::setPluginOption(std::string pluginName, std::string option,
                                    double value)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin) throw "Unknown plugin name";

  for(int i = 0; i < plugin->getNbOptions(); i++) {
    StringXNumber *sxn = plugin->getOption(i);
    if(option == std::string(sxn->str)) {
      sxn->def = value;
      return;
    }
  }
  throw "Unknown plugin option name";
}

PluginManager *PluginManager::instance()
{
  if(!_instance) _instance = new PluginManager;
  return _instance;
}

void PluginManager::registerDefaultPlugins()
{
  if(CTX::instance()->solver.plugins){
    // nothing here yet
  }

  if(CTX::instance()->post.plugins){
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("StreamLines", GMSH_RegisterStreamLinesPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Particles", GMSH_RegisterParticlesPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("CutGrid", GMSH_RegisterCutGridPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Isosurface", GMSH_RegisterIsosurfacePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("CutPlane", GMSH_RegisterCutPlanePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("CutSphere", GMSH_RegisterCutSpherePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("CutBox", GMSH_RegisterCutBoxPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Skin", GMSH_RegisterSkinPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("MathEval", GMSH_RegisterMathEvalPlugin()));
# if 0 // experimental (Amaury)
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("AnalyseCurvedMesh", GMSH_RegisterAnalyseCurvedMeshPlugin()));
#endif
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("ModifyComponent", GMSH_RegisterModifyComponentPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("ExtractElements", GMSH_RegisterExtractElementsPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("CutParametric", GMSH_RegisterCutParametricPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("MakeSimplex", GMSH_RegisterMakeSimplexPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Smooth", GMSH_RegisterSmoothPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Transform", GMSH_RegisterTransformPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("LongitudeLatitude",GMSH_RegisterLongituteLatitudePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Warp", GMSH_RegisterWarpPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("SphericalRaise", GMSH_RegisterSphericalRaisePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("HarmonicToTime", GMSH_RegisterHarmonicToTimePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("ModulusPhase", GMSH_RegisterModulusPhasePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Integrate", GMSH_RegisterIntegratePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("MinMax", GMSH_RegisterMinMaxPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Gradient", GMSH_RegisterGradientPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Curl", GMSH_RegisterCurlPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Divergence", GMSH_RegisterDivergencePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Annotate", GMSH_RegisterAnnotatePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Remove", GMSH_RegisterRemovePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Eigenvectors", GMSH_RegisterEigenvectorsPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Eigenvalues", GMSH_RegisterEigenvaluesPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Lambda2", GMSH_RegisterLambda2Plugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Probe", GMSH_RegisterProbePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Triangulate", GMSH_RegisterTriangulatePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("GSHHS", GMSH_RegisterGSHHSPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("ExtractEdges", GMSH_RegisterExtractEdgesPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("FieldFromAmplitudePhase", GMSH_RegisterFieldFromAmplitudePhasePlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("NearToFarField", GMSH_RegisterNearToFarFieldPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Bubbles", GMSH_RegisterBubblesPlugin()));
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("DiscretizationError", GMSH_RegisterDiscretizationErrorPlugin()));

#if defined(HAVE_TETGEN)
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Tetrahedralize", GMSH_RegisterTetrahedralizePlugin()));
#endif
#if defined(HAVE_KBIPACK)
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Homology", GMSH_RegisterHomologyComputationPlugin()));
#endif
#if defined(HAVE_SOLVER)
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("Distance", GMSH_RegisterDistancePlugin()));
#endif
#if defined(HAVE_ANN)
    allPlugins.insert(std::pair<std::string, GMSH_Plugin*>
                      ("NearestNeighbor", GMSH_RegisterNearestNeighborPlugin()));
#endif
  }

#if defined(HAVE_FLTK)
  char *pluginsHome = getenv("GMSHPLUGINSHOME");
  if(!pluginsHome) return;
  struct dirent **list;
  int nbFiles = fl_filename_list(pluginsHome, &list);
  if(nbFiles <= 0)
    return;
  for(int i = 0; i < nbFiles; i++) {
    std::string ext = SplitFileName(list[i]->d_name)[2];
    if(ext == ".so" || ext == ".dll")
      addPlugin(list[i]->d_name);
  }
  for(int i = 0; i < nbFiles; i++)
    free(list[i]);
  free(list);
#endif
}

void PluginManager::addPlugin(std::string fileName)
{
#if !defined(HAVE_DLOPEN) || !defined(HAVE_FLTK)
  Msg::Warning("No dynamic plugin loading on this platform");
#else
  Msg::Info("Opening Plugin '%s'", fileName.c_str());
  void *hlib = dlopen(fileName.c_str(), RTLD_NOW);
  const char *err = dlerror();
  if(!hlib){
    Msg::Warning("Could not open '%s' (dlerror = %s)", fileName.c_str(), err);
    return;
  }

  class GMSH_Plugin *(*registerPlugin) (void);
  registerPlugin = (class GMSH_Plugin * (*)(void))dlsym(hlib, GMSH_PluginEntry);
  err = dlerror();
  if(err){
    Msg::Warning("Symbol '%s' missing in '%s' (dlerror = %s)",
                 GMSH_PluginEntry, fileName.c_str(), err);
    return;
  }

  GMSH_Plugin *p = registerPlugin();
  p->hlib = hlib;
  if(allPlugins.find(p->getName()) != allPlugins.end()) {
    Msg::Warning("Plugin '%s' multiply defined", fileName.c_str());
    return;
  }

  allPlugins.insert(std::pair<std::string, GMSH_Plugin*>(p->getName(), p));
  Msg::Info("Loaded Plugin '%s' (%s)", p->getName().c_str(), p->getAuthor().c_str());
#endif
}

