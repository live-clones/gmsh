#ifndef _TRIANGULATE_H_
#define _TRIANGULATE_H_

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTriangulatePlugin ();
}

class GMSH_TriangulatePlugin : public GMSH_Post_Plugin
{
public:
  GMSH_TriangulatePlugin();
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
