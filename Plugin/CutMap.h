#ifndef _CUTMAP_H_
#define _CUTMAP_H
#include "LevelsetPlugin.h"
extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMapPlugin ();
}

class GMSH_CutMapPlugin : public GMSH_LevelsetPlugin
{
  /*we cut the othe map by the iso A of the View iView */
  double A;
  int iView;
  virtual double levelset (double x, double y, double z, double val) const;
public:
  GMSH_CutMapPlugin(double A, int IVIEW);
  virtual void getName  (char *name) const;
  virtual void getInfos (char *author, 
			 char *copyright,
			 char *help_text) const;
  virtual void CatchErrorMessage (char *errorMessage) const;
  virtual int getNbOptions() const;
  virtual StringXNumber* GetOption (int iopt);  
  virtual Post_View *execute (Post_View *);
};
#endif
