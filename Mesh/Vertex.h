#ifndef _VERTEX_H_
#define _VERTEX_H_

#include "List.h"

typedef struct {
  double X,Y,Z;
}Coord;

class Vertex {
  public :
  int     Num;
  char    Visible;
  int     Frozen;
  double  lc,u,us[3],w;
  Coord   Pos;
  Coord  *Mov;
  Coord   Freeze;
  List_T *ListSurf;
  List_T *ListCurves;
  List_T *Extruded_Points;
  Vertex ();
  Vertex (double x,double y,double z =0.0, double lc = 1.0, double w = 1.0);
  Vertex operator + ( const Vertex &other);
  Vertex operator - ( const Vertex &other);
  double operator * ( const Vertex &other);
  Vertex operator * ( double d );
  Vertex operator / ( double d );
  Vertex operator % (Vertex &autre); // cross product
  void norme();
};

int compareVertex (const void *a, const void *b);
int comparePosition (const void *a, const void *b);

Vertex *Create_Vertex (int Num, double X, double Y, double Z, double lc, double u);
void Delete_Vertex ( Vertex *pV );
void Free_Vertex (void *a, void *b);
void Free_ExtrudedPoints(List_T* Extruded_Points);

#endif
