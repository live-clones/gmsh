// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "GmshConfig.h"
#include "Plugin.h"
#include "PluginManager.h"
#include "CutMap.h"
#include "CutGrid.h"
#include "StreamLines.h"
#include "CutPlane.h"
#include "CutParametric.h"
#include "CutSphere.h"
#include "Skin.h"
#include "Extract.h"
#include "ExtractElements.h"
#include "ExtractEdges.h"
#include "HarmonicToTime.h"
#include "ModulusPhase.h"
#include "Integrate.h"
#include "Gradient.h"
#include "Curl.h"
#include "Divergence.h"
#include "Annotate.h"
#include "Remove.h"
#include "MakeSimplex.h"
#include "Smooth.h"
#include "Transform.h"
#include "LongitudeLatitude.h"
#include "Triangulate.h"
#include "Warp.h"
#include "SphericalRaise.h"
#include "Eigenvectors.h"
#include "Eigenvalues.h"
#include "Lambda2.h"
#include "Evaluate.h"
#include "Probe.h"
#include "FieldView.h"
#include "GSHHS.h"
#include "FiniteElement.h"
#include "Context.h"

#if !defined(HAVE_NO_DLL)
#include <dlfcn.h>
#endif

#if defined(HAVE_FLTK)
#include <FL/Fl.H>
#include <FL/filename.H>
#endif

const char *GMSH_PluginEntry = "GMSH_RegisterPlugin";

PluginManager *PluginManager::_instance = 0;

PluginManager::PluginManager()
{
}

PluginManager::~PluginManager()
{
  for(iter it = allPlugins.begin(); it != allPlugins.end(); ++it)
    delete(*it).second;
}

GMSH_Plugin *PluginManager::find(char *pluginName)
{
  iter it = allPlugins.find(pluginName);
  if(it == allPlugins.end())
    return 0;
  return (*it).second;
}

GMSH_SolverPlugin *PluginManager::findSolverPlugin()
{
  iter it  = allPlugins.begin();
  iter ite = allPlugins.end();
  for (; it != ite; ++it) {
    GMSH_Plugin *p = (*it).second;
    if(p->getType() == GMSH_Plugin::GMSH_SOLVER_PLUGIN) {
      return (GMSH_SolverPlugin*)(p);
    }      
  }
  return 0;
}

void PluginManager::action(char *pluginName, char *action, void *data)
{
  GMSH_Plugin *plugin = find(pluginName);
  if(!plugin)
    throw "Unknown plugin name";

  if(!strcmp(action, "Run"))
    plugin->run();
  else
    throw "Unknown plugin action";
}

void PluginManager::setPluginOption(char *pluginName, char *option,
                                    char *value)
{
  GMSH_Plugin *plugin = find(pluginName);

  if(!plugin)
    throw "Unknown plugin name";

  for(int i = 0; i < plugin->getNbOptionsStr(); i++) {
    StringXString *sxs;
    // get the ith option of the plugin
    sxs = plugin->getOptionStr(i);
    // look if it's the good option name
    if(!strcmp(sxs->str, option)) {
      sxs->def = value;
      return;
    }
  }

  throw "Unknown plugin option name";
}

void PluginManager::setPluginOption(char *pluginName, char *option,
                                    double value)
{
  GMSH_Plugin *plugin = find(pluginName);

  if(!plugin)
    throw "Unknown plugin name";

  for(int i = 0; i < plugin->getNbOptions(); i++) {
    StringXNumber *sxn;
    // get the ith option of the plugin
    sxn = plugin->getOption(i);
    // look if it's the good option name
    if(!strcmp(sxn->str, option)) {
      sxn->def = value;
      return;
    }
  }
  throw "Unknown plugin option name";
}

PluginManager *PluginManager::instance()
{
  if(!_instance) {
    _instance = new PluginManager;
  }
  return _instance;
}

void PluginManager::registerDefaultPlugins()
{
  if(CTX::instance()->solver.plugins){
    // nothing here yet
  }

  if(CTX::instance()->post.plugins){
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("StreamLines", GMSH_RegisterStreamLinesPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("CutGrid", GMSH_RegisterCutGridPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("CutMap", GMSH_RegisterCutMapPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("CutPlane", GMSH_RegisterCutPlanePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("CutSphere", GMSH_RegisterCutSpherePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Skin", GMSH_RegisterSkinPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Extract", GMSH_RegisterExtractPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("ExtractElements", GMSH_RegisterExtractElementsPlugin()));
#if 0 // waiting for BDS rewrite
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("ExtractEdges", GMSH_RegisterExtractEdgesPlugin()));
#endif
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("MakeSimplex", GMSH_RegisterMakeSimplexPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Smooth", GMSH_RegisterSmoothPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Transform", GMSH_RegisterTransformPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("LongitudeLatitude",GMSH_RegisterLongituteLatitudePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Warp", GMSH_RegisterWarpPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("SphericalRaise", GMSH_RegisterSphericalRaisePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("HarmonicToTime", GMSH_RegisterHarmonicToTimePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("ModulusPhase", GMSH_RegisterModulusPhasePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Integrate", GMSH_RegisterIntegratePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Gradient", GMSH_RegisterGradientPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Curl", GMSH_RegisterCurlPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Divergence", GMSH_RegisterDivergencePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Annotate", GMSH_RegisterAnnotatePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Remove", GMSH_RegisterRemovePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Eigenvectors", GMSH_RegisterEigenvectorsPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Eigenvalues", GMSH_RegisterEigenvaluesPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Lambda2", GMSH_RegisterLambda2Plugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Probe", GMSH_RegisterProbePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("FieldView", GMSH_RegisterFieldViewPlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Triangulate", GMSH_RegisterTriangulatePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("GSHHS", GMSH_RegisterGSHHSPlugin()));
#if defined(HAVE_MATH_EVAL)
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("Evaluate", GMSH_RegisterEvaluatePlugin()));
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("CutParametric", GMSH_RegisterCutParametricPlugin()));
#endif
    allPlugins.insert(std::pair<const char*, GMSH_Plugin*>
                      ("FiniteElement", GMSH_RegisterFiniteElementPlugin()));
  }

#if defined(HAVE_FLTK)
  char *homeplugins = getenv("GMSHPLUGINSHOME");
  if(!homeplugins) return;
  struct dirent **list;
  int nbFiles = fl_filename_list(homeplugins, &list);
  if(nbFiles <= 0)
    return;
  for(int i = 0; i < nbFiles; i++) {
    char *name = list[i]->d_name;
    if(strlen(name) > 3) {
      char ext[6];
      strcpy(ext, name + (strlen(name) - 3));
      if(!strcmp(ext, ".so") || !strcmp(ext, "dll")) {
        addPlugin(homeplugins, name);
      }
    }
  }
  for(int i = 0; i < nbFiles; i++)
    free(list[i]);
  free(list);
#endif
}

void PluginManager::addPlugin(char *dirName, char *pluginName)
{
#if defined(HAVE_NO_DLL) || !defined(HAVE_FLTK)
  Msg::Warning("No dynamic plugin loading on this platform");
#else
  char dynamic_lib[1024];
  char plugin_name[256];
  char plugin_author[256];
  char plugin_copyright[256];
  char plugin_help[1024];
  class GMSH_Plugin *(*registerPlugin) (void);
  sprintf(dynamic_lib, "%s/%s", dirName, pluginName);
  Msg::Info("Opening Plugin '%s'", dynamic_lib);
  void *hlib = dlopen(dynamic_lib, RTLD_NOW);
  const char *err = dlerror();
  if(!hlib){
    Msg::Warning("Error in opening %s (dlerror = %s)", dynamic_lib, err);
    return;
  }
  registerPlugin = (class GMSH_Plugin * (*)(void))dlsym(hlib, GMSH_PluginEntry);
  err = dlerror();
  if(err){
    Msg::Warning("Symbol '%s' missing in plugin '%s' (dlerror = %s)",
                 GMSH_PluginEntry, pluginName, err);
    return;
  }

  GMSH_Plugin *p = registerPlugin();
  p->hlib = hlib;
  p->getName(plugin_name);
  p->getInfos(plugin_author, plugin_copyright, plugin_help);
  if(allPlugins.find(plugin_name) != allPlugins.end()) {
    Msg::Warning("Plugin '%s' multiply defined", pluginName);
    return;
  }
  allPlugins.insert(std::pair<const char*, GMSH_Plugin*>(plugin_name, p));
  Msg::Info("Loaded Plugin '%s' (%s)", plugin_name, plugin_author);
#endif
}
