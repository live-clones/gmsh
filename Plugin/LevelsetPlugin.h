#ifndef _LEVELSETPLUGIN_H_
#define _LEVELSETPLUGIN_H_
#include "Plugin.h"

#define ORIENT_NONE   0
#define ORIENT_MAP    1
#define ORIENT_PLANE  2
#define ORIENT_SPHERE 3

class GMSH_LevelsetPlugin : public GMSH_Post_Plugin
{
protected:
  int _ith_field_to_draw_on_the_iso;
  int _orientation;
  double _ref[3];
private:
  virtual double levelset     (double x, double y, double z, double val) const = 0;
  virtual double what_to_draw (double x, double y, double z, 
			       int p1, int p2, double coef, double *val) const;
public:
  GMSH_LevelsetPlugin();
  virtual Post_View *execute (Post_View *);
  virtual void Run();
  virtual void Save();
};
#endif
