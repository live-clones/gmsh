#ifndef _LEVELSETPLUGIN_H_
#define _LEVELSETPLUGIN_H_
#include "Plugin.h"

class GMSH_LevelsetPlugin : public GMSH_Post_Plugin
{
  virtual double levelset (double x, double y, double z) const = 0;
public:
  virtual Post_View *execute (Post_View *);
};
#endif
