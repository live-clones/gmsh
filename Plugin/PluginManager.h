#ifndef _PLUGINMANAGER_H_
#define _PLUGINMANAGER_H_
/*
  The one who intend to create a plugin for gmsh have to 
    -) Create a dynamin lib (.so) containing 1 symbols
       GMSH_Plugin * GMSH_RegisterPlugin ();
    -) When there is an unacceptable error in the plugin,
    just throw this, the plugin manager will be able to 
    catch the exception.
*/

#include <map>

class GMSH_Plugin;
struct ltstrpg
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

class GMSH_PluginManager
{
  GMSH_PluginManager();
  virtual ~GMSH_PluginManager();
  static GMSH_PluginManager *instance;
  std::map<char*,GMSH_Plugin*,ltstrpg> allPlugins;
public :
  typedef std::map<char*,GMSH_Plugin*,ltstrpg>::iterator iter;
/**
  Registering all default plugins that are in $(GMSHPLUGINSHOME)
  In fact, we will load all .so files in dir $(GMSHPLUGINSHOME)
*/
  void RegisterDefaultPlugins();
  static GMSH_PluginManager *Instance();
  /** Dynamically add a plugin pluginName.so in dirName*/
  void AddPlugin(char *dirName, char *pluginName);
  void CallPlugin (char *name);
  void DestroyPlugin (char *name);
  void StPluginOption (char *pluginName, char *option, void *value);
  iter begin() {return allPlugins.begin();}
  iter end() {return allPlugins.end();}
  iter find(char *c) {return allPlugins.find(c);}
};
#endif








