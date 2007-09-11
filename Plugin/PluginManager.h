#ifndef _PLUGIN_MANAGER_H_
#define _PLUGIN_MANAGER_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include "Plugin.h"

struct ltstrpg
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

class GMSH_PluginManager
{
 private:
  GMSH_PluginManager();
  static GMSH_PluginManager *_instance;
  std::map<const char*, GMSH_Plugin*, ltstrpg> allPlugins;

 public :
  virtual ~GMSH_PluginManager();
  typedef std::map<const char*, GMSH_Plugin*, ltstrpg>::iterator iter;
  
  // register all the plugins that are in $(GMSHPLUGINSHOME). (Note
  // that loading a .so is not what is usually called a 'plugin': we
  // should call the plugins 'modules'... A plugin is an executable,
  // but that can only be executed from inside another program.)
  void registerDefaultPlugins();
  static GMSH_PluginManager *instance();

  // Dynamically add a plugin pluginName.so in dirName
  void addPlugin(char *dirName, char *pluginName);

  // Uninstall a given plugin
  void uninstallPlugin(char *pluginName);

  // Set an option to a value in plugin named pluginName
  void setPluginOption(char *pluginName, char *option, double value);
  void setPluginOption(char *pluginName, char *option, char *value);

  // Iterator on plugins
  inline iter begin(){ return allPlugins.begin(); }
  inline iter end(){ return allPlugins.end(); }

  // Find a plugin named pluginName
  GMSH_Plugin *find(char *pluginName);

  // Get The ONLY Solver Plugin
  GMSH_Solve_Plugin *findSolverPlugin();

  // Perform an action on the plugin. Default action are Run and
  // Save. Other plugins may perform other actions.
  void action(char *pluginMane, char *action, void *data);
};

#endif
