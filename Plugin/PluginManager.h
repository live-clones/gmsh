#ifndef _PLUGINMANAGER_H_
#define _PLUGINMANAGER_H_

// Copyright (C) 1997 - 2002 C. Geuzaine, J.-F. Remacle
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
// Please report all bugs and problems to "gmsh@geuz.org".

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

  
  // Registering all default plugins that are in
  // $(GMSHPLUGINSHOME). In fact, we will load all .so files in dir
  // $(GMSHPLUGINSHOME). Note that loading a .so (or a .o) is not what
  // is usually called a 'plugin'. We should call the plugins
  // 'modules'. A plugin is an _executable_, but that can only be
  // executed from inside another program...
  void RegisterDefaultPlugins();
  static GMSH_PluginManager *Instance();

  // Dynamically add a plugin pluginName.so in dirName
  void AddPlugin(char *dirName, char *pluginName);

  // Uninstall a given plugin
  void UninstallPlugin (char *pluginName);

  // Set an option to a value in plugin named pluginName
  void SetPluginOption (char *pluginName, char *option, double value);
  void SetPluginOption (char *pluginName, char *option, char * value);

  // Iterator on plugins
  inline iter begin() {return allPlugins.begin();}
  inline iter end() {return allPlugins.end();}

  // Find a plugin named pluginName
  GMSH_Plugin *find(char *pluginName);

  // Perform an action on the plugin. Default action are Run and
  // Save. Other plugins may perform other actions.
  void Action (char *pluginMane , char *action , void *data); 
};
#endif








