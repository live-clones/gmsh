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
#include <iosfwd>

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
  static GMSH_PluginManager *instance;
  std::map<const char*,GMSH_Plugin*,ltstrpg> allPlugins;
public :
  virtual ~GMSH_PluginManager();
  typedef std::map<const char*,GMSH_Plugin*,ltstrpg>::iterator iter;
/**
  Registering all default plugins that are in $(GMSHPLUGINSHOME)
  In fact, we will load all .so files in dir $(GMSHPLUGINSHOME)
*/
  void RegisterDefaultPlugins();
  static GMSH_PluginManager *Instance();
  /** Dynamically add a plugin pluginName.so in dirName*/
  void AddPlugin(char *dirName, char *pluginName);
  // uninstall a given plugin
  void UninstallPlugin (char *pluginName);
  // set an option to a value in plugin named pluginName
  void SetPluginOption (char *pluginName, char *option, double value);
  void SetPluginOption (char *pluginName, char *option, char * value);
  // iterator on plugins
  inline iter begin() {return allPlugins.begin();}
  inline iter end() {return allPlugins.end();}
  // find a plugin named pluginName
  GMSH_Plugin *find(char *pluginName);
  // perform an action on the plugin
  // default action are Run and Save
  // other plugins may perform other actions
  void Action (char *pluginMane , char *action , void *data); 
};
#endif








