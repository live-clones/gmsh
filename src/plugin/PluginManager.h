// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <map>
#include <string>

class GMSH_Plugin;
class GMSH_SolverPlugin;

class PluginManager {
private:
  PluginManager() {}
  static PluginManager *_instance;
  std::map<std::string, GMSH_Plugin *> allPlugins;

public:
  virtual ~PluginManager();

  // register all the plugins that are in $(GMSHPLUGINSHOME). (Note
  // that loading a .so is not what is usually called a 'plugin': we
  // should call the plugins 'modules'... A plugin is an executable,
  // but that can only be executed from inside another program.)
  void registerDefaultPlugins();
  static PluginManager *instance();

  // Dynamically add a plugin pluginName.so in dirName
  void addPlugin(const std::string &fileName);

  // Uninstall a given plugin
  void uninstallPlugin(const std::string &pluginName) {}

  // Set an option to a value in plugin named pluginName
  void setPluginOption(const std::string &pluginName, const std::string &option,
                       double value);
  void setPluginOption(const std::string &pluginName, const std::string &option,
                       const std::string &value);

  // Iterator on plugins
  std::map<std::string, GMSH_Plugin *>::iterator begin()
  {
    return allPlugins.begin();
  }
  std::map<std::string, GMSH_Plugin *>::iterator end()
  {
    return allPlugins.end();
  }

  // Find a plugin named pluginName
  GMSH_Plugin *find(const std::string &pluginName);

  // Get The ONLY Solver Plugin
  GMSH_SolverPlugin *findSolverPlugin();

  // Perform an action on the plugin. Default action are Run and
  // Save. Other plugins may perform other actions.
  int action(const std::string &pluginName, const std::string &action,
             void *data);
};

#endif
