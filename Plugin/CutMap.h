#ifndef _CUTMAP_H_
#define _CUTMAP_H
#include "LevelsetPlugin.h"
extern "C"
{
  GMSH_Plugin *GMSH_RegisterCutMapPlugin ();
}

class GMSH_CutMapPlugin : public GMSH_LevelsetPlugin
{
  virtual double levelset (double x, double y, double z, double val) const;
public:
  GMSH_CutMapPlugin();
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
