#ifndef _EXTRUDE_PARAMS_H_
#define _EXTRUDE_PARAMS_H_

//geo.Mode
#define EXTRUDED_ENTITY 1
#define COPIED_ENTITY 2

//geo.Type
#define TRANSLATE 1
#define ROTATE 2
#define TRANSLATE_ROTATE 3

class ExtrudeParams{
  
public :
  ExtrudeParams(int Mode = EXTRUDED_ENTITY);
  void fill(int type,
	    double T0, double T1, double T2,
	    double A0, double A1, double A2,
	    double X0, double X1, double X2, double angle);
  void Extrude(int iLayer, int iElemLayer,
	       double &dx, double &dy, double &dz);
  void Extrude(double t, double &x, double &y, double &z);
  void Rotate(double matr[3][3]);
  struct{
    bool    ExtrudeMesh;
    bool    Recombine;
    int     NbLayer;
    int     *NbElmLayer;
    int     *ZonLayer;
    double  *hLayer;
  }mesh;
  struct{
    int Mode;
    int Type;
    int Source;
    double trans[3];
    double axe[3], pt[3], angle;
  }geo;
  
};

#endif
