#ifndef _STEP_GEOM_DATABASE_H_
#define _STEP_GEOM_DATABASE_H_

typedef struct{
  double X, Y, Z;
} Step_Coord_t;

typedef struct{
  int Num;
  char *Name;
  Step_Coord_t Pos;
}Step_Direction_t;

typedef struct{
  int Num;
  char *Name;
  int Step_Direction;
  double Lenght;
}Step_Vector_t;

typedef struct{
  int Num;
  char *Name;
  int Cartesian_Point;
}Step_Vertex_Point_t;

typedef struct{
  int Num;
  char *Name;
  Step_Coord_t Pos;
}Step_Cartesian_Point_t;


#define STEP_LINE 1
#define STEP_CIRC 3
#define STEP_ELLP 6
#define STEP_PARA 7
#define STEP_HYPB 8

typedef struct{
  int Step_Cartesian_Point;
  int Step_Vector;
}Step_Line_t;

typedef struct{
  int Step_Axis2_Placement3D;
  double Radius1;
  double Radius2;
}Step_Circle_t;

typedef struct{
  int Order;
  List_T *ListOf_Cartesian_Points;
  List_T *ListOf_Knots;
  double Ubeg, Uend;
}Step_BSpline_Curve_With_Knots_t;

typedef struct{
  int Num;
  int Typ;
  char *Name;
  union{
    Step_BSpline_Curve_With_Knots_t BSpline;
    Step_Line_t Line;
    Step_Circle_t Circle;
  }Curve;
}Step_Curve_t;


#define STEP_PLAN 1
#define STEP_CYLD 2
#define STEP_TORD 3
#define STEP_CONE 4
#define STEP_BSPL 5

typedef struct{
  int Num;
  int Step_Cartesian_Point;
  int Step_Direction1;
  int Step_Direction2;
}Step_Axis2_Placement3D_t;

typedef struct{
  int Step_Axis2_Placement3D;
}Step_Plane_t;

typedef struct{
  int Step_Axis2_Placement3D;
  double Radius1;
  double Radius2;
}Step_Quadric_t;

typedef struct{
  int OrderU, OrderV;
  List_T *ListOf_Cartesian_Points;
  List_T *ListOf_KnotsU;
  List_T *ListOf_KnotsV;
  double Ubeg, Uend, Vbeg, Vend;
}Step_BSpline_Surface_With_Knots_t;

typedef struct{
  int Num;
  int Typ;
  char *Name;
  union{
    Step_BSpline_Surface_With_Knots_t BSpline;
    Step_Plane_t Plane;
    Step_Quadric_t Quadric;
  }Surface;
}Step_Surface_t;

typedef struct{
  int Num;
  char *Name;
  int Step_Vertex_Point_Begin;
  int Step_Vertex_Point_End;
  int Step_Curve;
}Step_Edge_Curve_t;

typedef struct{
  int Num;
  char Name;
  int Step_Edge_Curve;
  bool dir;
}Step_Oriented_Edge_t;

typedef struct{
  int Num;
  char Name;
  List_T *ListOf_Step_Oriented_Edge;
}Step_Edge_Loop_t;

typedef struct{
  int Num;
  char Name;
  int Step_Edge_Loop;
  bool dir;
  bool outer;
}Step_Face_Outer_Bound_t;

typedef struct{
  int Num;
  char Name;
  List_T *ListOf_Step_Face_Outer_Bound;
  int Step_Surface;
  bool dir;
}Step_Advanced_Face_t;

typedef struct{
  int Num;
  char Name;
  List_T *ListOf_Step_Advanced_Face;
}Step_Closed_Shell_t;

typedef struct{
  List_T *AllDirections;
  List_T *AllVectors;
  List_T *AllCartesian_Points;
  List_T *AllVertex_Points;
  List_T *AllCurves;
  List_T *AllEdge_Curves;
  List_T *AllSurfaces;
  List_T *AllAxis2_Placement3D;
  List_T *AllClosed_Shells;
  List_T *AllFaces_Outer_Bound;
  List_T *AllOriented_Edges;
  List_T *AllEdge_Loops;
  List_T *AllAdvanced_Faces;
}Step_Solid_BRep_t;

Step_Solid_BRep_t *Create_Step_Solid_BRep(void);

void Add_Direction (int Num, char *name, double x, double y, double z);
void Add_Vector (int Num, char *name, int Dir, double l);
void Add_Cartesian_Point (int Num, char *name, double x, double y, double z);
void Add_Vertex_Point (int Num, char *name, int cp);
void Add_Line (int Num, char *name, int begin, int dir);
void Add_Circle (int Num, char *name, int axis, double Radius);
void Add_Ellipsis (int Num, char *name, int axis, double Radius, double r2);
void Add_Cylinder (int Num, char *name, int axis, double Radius);
void Add_Torus (int Num, char *name, int axis, double radius1, double radius2);
void Add_Cone (int Num, char *name, int axis, double radius1, double radius2);
void Add_Edge_Curve (int Num, char *name, int beg, int end, int curve);
void Add_Vertex_Point (int num, char *name, int cp);
void Add_Oriented_Edge (int Num, char *name, int ec, bool dir);
void Add_Edge_Loop (int Num, char *name, List_T * list);
void Add_Face_Outer_Bound (int Num, char *name, int el, bool dir, bool outer);
void Add_Advanced_Face (int Num, char *name, List_T * lfob, int surf, bool dir);
void Add_Closed_Shell (int Num, char *name, List_T * laf);
void Add_BSpline_Curve_With_Knots (int Num, char *name, int Order, List_T * lcp,
                                   List_T * lm, List_T * lk, double udeb, double uend);
void Add_Plane (int Num, char *name, int axis);
void Add_Axis2_Placement3D (int Num, int cp, int dir1, int dir2);
void Add_Closed_Shell (int Num, char *name, List_T * list);
void Resolve_BREP (void);
void Add_BSpline_Surface_With_Knots (int Num,char *name,int OrderU,int OrderV,
                                     List_T * lcp, List_T * lmu, List_T * lmv,
                                     List_T * lku,List_T * lkv,
                                     double udeb,double uend,
                                     double vdeb,double vend);

#endif
