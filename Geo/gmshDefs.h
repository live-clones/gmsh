#ifndef _H_GMSH_DEFS_
#define _H_GMSH_DEFS_
#ifdef _HAVE_SGMODEL_
#include "SGModel.h"
#include "GVPoint.h"
#include "GEPoint.h"
#include "GFPoint.h"
#include "Pair.h"
#else
#include "SPoint2.h"
class GRegion;
class GFace;
class GEdge;
class GVertex;
class SGModel {
 public:
  SGModel ( const char * ){}
  void add(GRegion *r){}
  void add(GFace *f){}
  void add(GEdge *e){}
  void add(GVertex *v){}
};

class GeoRep {
};

struct GVPoint 
{
  double X,Y,Z;
  GVPoint (double _x, double _y, double _z, const GVertex *v):X(_x),Y(_y),Z(_z){};
};
struct GEPoint 
{
  double X,Y,Z;
  GEPoint (double _x, double _y, double _z, const GEdge *e, double par):X(_x),Y(_y),Z(_z){};
};
struct GFPoint 
{
  double X,Y,Z;
  GFPoint (double _x, double _y, double _z,
	   const GFace *e, const SPoint2 & par):X(_x),Y(_y),Z(_z){};
};


class Logical{
public:
  enum Value{
    False = 0,
    True,
    Unknown
    };
};

class GeomType{
public:
  enum Value{
    Unknown,
    Point,
    Line,
    Circle,
    Ellipse,
    ParametricCurve,
    Plane,
    Nurb,
    Cylinder,
    Sphere,
    Cone,
    Torus,
    ParametricSurface
    };
};
#endif
#endif
