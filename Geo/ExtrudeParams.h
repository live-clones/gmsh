#ifndef _EXTRUDE_PARAMS_H_
#define _EXTRUDE_PARAMS_H_

#define NB_LAYER_MAX 30

#define EXTRUDED_ENTITY 1
#define COPIED_ENTITY 2

class ExtrudeParams{

public :
  ExtrudeParams(int Mode = EXTRUDED_ENTITY);
  void fill (int ep,double A, double B, double C,
             double X, double Y, double Z, double angle);
  void Extrude (  int iLayer, int iElemLayer,
                  double &dx, double &dy, double &dz);
  void Extrude (double t, double &x, double &y, double &z);
  void Rotate(double matr[3][3]);
  struct{
    bool    ExtrudeMesh;
    bool    Recombine;
    int     NbLayer;
    int     NbElmLayer [NB_LAYER_MAX];
    int     ZonLayer   [NB_LAYER_MAX];
    double  hLayer     [NB_LAYER_MAX];
  }mesh;
  struct{
    int Mode;
    int Type;
    int Source;
    double axe[3];
    double pt[3];
    double angle;
  }geo;

};

#endif
