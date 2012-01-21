// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _PLUGIN_MANAGER_H_
#define _PLUGIN_MANAGER_H_

#include <map>
#include <string>

class GMSH_Plugin;
class GMSH_SolverPlugin;

class PluginManager
{
 private:
  PluginManager(){}
  static PluginManager *_instance;
  std::map<std::string, GMSH_Plugin*> allPlugins;

 public :
  virtual ~PluginManager();
  
  // register all the plugins that are in $(GMSHPLUGINSHOME). (Note
  // that loading a .so is not what is usually called a 'plugin': we
  // should call the plugins 'modules'... A plugin is an executable,
  // but that can only be executed from inside another program.)
  void registerDefaultPlugins();
  static PluginManager *instance();

  // Dynamically add a plugin pluginName.so in dirName
  void addPlugin(std::string fileName);

  // Uninstall a given plugin
  void uninstallPlugin(std::string pluginName);

  // Set an option to a value in plugin named pluginName
  void setPluginOption(std::string pluginName, std::string option, 
                       double value);
  void setPluginOption(std::string pluginName, std::string option, 
                       std::string value);

  // Iterator on plugins
  std::map<std::string, GMSH_Plugin*>::iterator begin(){ return allPlugins.begin(); }
  std::map<std::string, GMSH_Plugin*>::iterator end(){ return allPlugins.end(); }

  // Find a plugin named pluginName
  GMSH_Plugin *find(std::string pluginName);

  // Get The ONLY Solver Plugin
  GMSH_SolverPlugin *findSolverPlugin();

  // Perform an action on the plugin. Default action are Run and
  // Save. Other plugins may perform other actions.
  void action(std::string pluginName, std::string action, void *data);
};

#endif
