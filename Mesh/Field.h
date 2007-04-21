#ifndef _FIELD_H_
#define _FIELD_H_

// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include <map>
#include <list>
#include "Views.h"
#ifdef HAVE_ANN_
#include "ANN/ANN.h"
#endif
#include "Geo.h"
#include "GEdge.h"
#include "OctreePost.h"

class Field{
public:
  virtual double operator()(double x, double y, double z) = 0;
  virtual ~Field(){}
};

class FieldManager{
  std::map<int, Field*> id_map;
public:
  void reset();
  int insert(Field *field, int id=-1 /* -1 = automatic id */); /* returns the id */
  Field *get(int id);
};

extern FieldManager fields;

class StructuredField : public Field{
  double o[3], d[3];
  int n[3];
  double *data;
public :
  StructuredField(const char *filename);
  virtual ~StructuredField();
  double operator()(double x, double y, double z);
};

class LatLonField : public Field{
  Field *field;
public:
  LatLonField(Field *_field) : field(_field){};
  double operator()(double x, double y, double z);
};

class ParametricField : public Field{
  void *evalX, *evalY, *evalZ;
  Field *field;
public:
  ParametricField(Field *_field, const char *strX, const char *strY, const char *strZ);
  double operator()(double x, double y, double z);
  virtual ~ParametricField();
};

class ThresholdField : public Field{
  Field *field;
  double dmin, dmax, lcmin, lcmax;
public:
  ThresholdField(Field *field, double dmin, double dmax, double lcmin, double lcmax);
  double operator()(double x, double y, double z);
};

class GradField : public Field{
  Field *field;
  int kind; /* 0 x, 1 y, 2 z, 3 max */
  double delta;
public:
  GradField(Field *field, int _kind=2, double _delta=-1);
  double operator()(double x, double y, double z);
};

class FunctionField : public Field{
  std::list<Field*> *list;
  char **names;
  double *values;
  void *eval;
public:
  FunctionField(std::list<Field*> *_list, const char *fct);
  double operator()(double x, double y, double z);
  virtual ~FunctionField();
};

class PostViewField : public Field{
  OctreePost *octree;
  int view_index;
public:
  PostViewField(Post_View *view);
  double operator()(double x, double y, double z);
  virtual ~PostViewField();
};

class MinField : public Field, public std::list<Field*>{
public:
  MinField(){}
  double operator()(double x, double y, double z);
};

class AttractorField : public Field{
protected :
#ifdef HAVE_ANN_
  ANNkd_tree* kdtree;
  ANNpointArray zeronodes;
  ANNidxArray index;
  ANNdistArray dist;
#endif
  std::list<SPoint3> attractorPoints;  
public :
  AttractorField();
  virtual ~AttractorField();
  void addPoint(double X, double Y, double Z, double lc = -1.0);
  void buildFastSearchStructures() ;
  void addGEdge(GEdge*, int);
  void addCurve(Curve*, int);
  double operator()(double X, double Y, double Z) ;
};

#endif
