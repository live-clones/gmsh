#include <stdio.h>
#include <dlfcn.h>
#include <map>
#include "Plugin.h"
using namespace std;

struct ltstr
{
  bool operator()(const char* s1, const char* s2) const
  {
    return strcmp(s1, s2) < 0;
  }
};

class PluginContainer
{
public :
  typedef map<char*,GMSH_Plugin*,ltstr>::iterator iter;
  map<char*,GMSH_Plugin*,ltstr> m;
  iter begin() {return m.begin();}
  iter end() {return m.end();}
  iter find(char *c) {return m.find(c);}
};

GMSH_PluginManager *GMSH_PluginManager::instance = 0;

GMSH_PluginManager::GMSH_PluginManager()
{
  allPlugins = new PluginContainer;
}

GMSH_PluginManager::~GMSH_PluginManager()
{
  for(PluginContainer::iter it = allPlugins->begin();
      it != allPlugins->end();
      ++it)delete (*it).second;
  delete allPlugins;
}

GMSH_PluginManager* GMSH_PluginManager::Instance()
{
  if(!instance)
    {
      instance = new GMSH_PluginManager;
    }
  return instance;
}

void GMSH_PluginManager::RegisterDefaultPlugins()
{
  char *homeplugins = getenv ("GMSHPLUGINSHOME");
  if(!homeplugins)return;
  
}

void GMSH_PluginManager::AddPlugin( char *dirName, char *pluginName)
{
  char dynamic_lib[1024];
  char plugin_name[256];
  class GMSH_Plugin* (*RegisterPlugin)(void);
  sprintf(dynamic_lib,"%s/%s.so",dirName,pluginName);
  void *hlib = dlopen (dynamic_lib,RTLD_NOW);
  if(hlib == NULL)
    {
      throw dynamic_lib;
    }
  RegisterPlugin = (class GMSH_Plugin* (*)(void)) dlsym(hlib,GMSH_PluginEntry);
  char *err = dlerror();
  if(err != NULL)
    {
      return;
    }

  GMSH_Plugin *p = RegisterPlugin();
  p->hlib = hlib;
  p->getName(plugin_name);
  if(allPlugins->find(plugin_name) != allPlugins->end())
    {
      return;
    }
  allPlugins->m[plugin_name] = p;
}



