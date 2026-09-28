// Gmsh - Copyright (C) 1997-2026 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef PLUGIN_MANAGER_H
#define PLUGIN_MANAGER_H

#include <map>
#include <string>
#include <vector>

class GMSH_Plugin;

class PluginManager {
private:
  PluginManager() {}
  static PluginManager *_instance;
  std::map<std::string, GMSH_Plugin *> allPlugins;
  // the shared libraries plugins were loaded from
  std::vector<void *> _libraries;
  void add(GMSH_Plugin *p);

public:
  virtual ~PluginManager();

  // register the plugins built into Gmsh, and the plugins in the directories
  // listed in $GMSHPLUGINSHOME
  void registerDefaultPlugins();
  static PluginManager *instance();

  // load a plugin from a shared library, or all the plugins (.so, .dylib,
  // .dll) in directories separated like in PATH
  bool addPlugin(const std::string &fileName);
  void addPlugins(const std::string &dirs);

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

  // Perform an action on the plugin. Default action are Run and
  // Save. Other plugins may perform other actions.
  int action(const std::string &pluginName, const std::string &action,
             void *data);
};

#endif
