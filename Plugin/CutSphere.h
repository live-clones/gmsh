#ifndef _CUTSPHERE_H_
#define _CUTSPHERE_H
#include "LevelsetPlugin.h"
extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutSpherePlugin ();
}

class GMSH_CutSpherePlugin : public GMSH_LevelsetPlugin
{
  /*Sphere (x-a)^2 + (y-b)^2 + (z-c)^2 - r^2 = 0*/
  double a,b,c,r;
  virtual double levelset (double x, double y, double z, double val) const;
public:
  GMSH_CutSpherePlugin(double A, double B, double C, double R);
  virtual void getName  (char *name) const;
  virtual void getInfos (char *author, 
			 char *copyright,
			 char *help_text) const;
  virtual void CatchErrorMessage (char *errorMessage) const;
  virtual int getNbOptions() const;
  virtual StringXNumber* GetOption (int iopt);  
};
#endif
