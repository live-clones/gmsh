#ifndef _TRANSFORM_H_
#define _TRANSFORM_H

extern "C"
{
  GMSH_Plugin *GMSH_RegisterTransformPlugin ();
}

class GMSH_TransformPlugin : public GMSH_Post_Plugin
{
  int iView;
  double mat[3][3];
public:
  GMSH_TransformPlugin(double a11, double a12, double a13,
		       double a21, double a22, double a23,
		       double a31, double a32, double a33, int IVIEW);
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
