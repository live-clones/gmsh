#ifndef _CUTPLANE_H_
#define _CUTPLANE_H
#include "LevelsetPlugin.h"

extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutPlanePlugin ();
}

class GMSH_CutPlanePlugin : public GMSH_LevelsetPlugin
{
  /*Plane a x + b y + c z + d = 0*/
  double a,b,c,d;
  virtual double levelset (double x, double y, double z, double val) const;
public:
  GMSH_CutPlanePlugin(double A, double B, double C, double D);
  virtual void getName  (char *name) const;
  virtual void getInfos (char *author, 
			 char *copyright,
			 char *help_text) const;
  virtual void CatchErrorMessage (char *errorMessage) const;
  virtual int getNbOptions() const;
  virtual StringXNumber *GetOption (int iopt);  
};
#endif
