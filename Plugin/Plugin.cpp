#include <stdio.h>
#include <dlfcn.h>
#include <map>
#include "Plugin.h"
#include "Message.h"
#include <FL/filename.H>
using namespace std;

const char *GMSH_PluginEntry = "GMSH_RegisterPlugin";

#if defined(WIN32) && !defined(__CYGWIN__)
#define SLASH "\\"
#else
#define SLASH "/"
#endif

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
  struct dirent **list;
  char ext[6];

  char *homeplugins = getenv ("GMSHPLUGINSHOME");
  if(!homeplugins)
    homeplugins = "./Plugin/lib";
  int nbFiles = filename_list(homeplugins,&list);
  if(nbFiles <= 0)  return;
  for(int i=0;i<nbFiles;i++)
    {
      char *name = list[i]->d_name;
      if(strlen(name) > 3)
	{
	  strcpy(ext,name+(strlen(name)-3));
	  if(!strcmp(ext,".so"))
	  {
	    AddPlugin(homeplugins,name);
	  }
	}
    }
  for(int i=0;i<nbFiles;i++)free(list[i]);
  free (list);
}

void GMSH_PluginManager::AddPlugin( char *dirName, char *pluginName)
{
#if defined(WIN32) && !defined(__CYGWIN__)
  Msg(WARNING,"Plugins not yet implemented for WIN32 native compiler");
  return;
#else
  char dynamic_lib[1024];
  char plugin_name[256];
  char plugin_author[256];
  char plugin_copyright[256];
  char plugin_help[256];
  class GMSH_Plugin* (*RegisterPlugin)(void);
  sprintf(dynamic_lib,"%s%s%s",dirName,SLASH,pluginName);
  Msg(INFO,"Opening Plugin %s",dynamic_lib);
  void *hlib = dlopen (dynamic_lib,RTLD_NOW);
  char *err = dlerror();
  if(hlib == NULL)
    {
      Msg(WARNING,"Error in opening %s (dlerror = %s)",dynamic_lib,err);
      return;
    }
  RegisterPlugin = (class GMSH_Plugin* (*)(void)) dlsym(hlib,GMSH_PluginEntry);
  err = dlerror();
  if(err != NULL)
    {
      Msg(WARNING,"Symbol %s missing in Plugin %s (dlerror = %s)",GMSH_PluginEntry,pluginName,err);
      return;
    }

  GMSH_Plugin *p = RegisterPlugin();
  p->hlib = hlib;
  p->getName(plugin_name);
  p->getInfos(plugin_author,plugin_copyright,plugin_help);
  if(allPlugins->find(plugin_name) != allPlugins->end())
    {
      Msg(WARNING,"Plugin %s Multiply defined",pluginName);
      return;
    }
  allPlugins->m[plugin_name] = p;
  Msg(INFO,"Plugin name : %s",plugin_name);
  Msg(INFO,"Plugin author : %s",plugin_author);
  Msg(INFO,"Plugin copyright : %s",plugin_copyright);
  Msg(INFO,"Plugin help : %s",plugin_help);
#endif
}



