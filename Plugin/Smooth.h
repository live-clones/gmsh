#ifndef _SMOOTH_H_
#define _SMOOTH_H

extern "C"
{
  GMSH_Plugin *GMSH_RegisterSmoothPlugin ();
}

class GMSH_SmoothPlugin : public GMSH_Post_Plugin
{
  int iView;
public:
  GMSH_SmoothPlugin(int IVIEW);
  virtual void Run();
  virtual void Save();
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
