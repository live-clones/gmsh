#ifndef _CUTPLANE_H_
#define _CUTPLANE_H
#include "Plugin.h"
class GMSH_CutPlanePlugin : public GMSH_Post_Plugin
{
  /*Plane a x + b y + c z + d = 0*/
  double a,b,c,d;
  double levelset (double x, double y, double z);
public:
  GMSH_CutPlanePlugin(double A, double B, double C, double D);
  virtual void getName  (char *name) const;
  virtual void getInfos (char *author, 
			 char *copyright,
			 char *help_text) const;
  virtual void CatchErrorMessage (char *errorMessage) const;
  virtual void SetOption (char *optionName, void *optionValue);
  virtual int getNbOptions() const;
  virtual void GetOption (int iopt, char *optionName, void *optionValue) const;  
  virtual Post_View *execute (Post_View *);
};
#endif
