#ifndef FIELD_H_
#define FIELD_H_
#include<map>
#include<list>
#include "Views.h"
#ifdef HAVE_ANN_
#include "ANN/ANN.h"
#endif
#include "Geo.h"
#include "GEdge.h"
#include "OctreePost.h"
class Field{
	public:
	virtual double operator()(double x,double y,double z)=0;
};
class FieldManager{
	std::map<int,Field*> id_map;
  public:
	void reset();
  int insert(Field *field,int id=-1 /* -1= automatic id */); /* return the id */
  Field *get(int id);
};
extern FieldManager fields;

class StructuredField:public Field{
	double o[3],d[3];
	int n[3];
	double *data;
	public :
	StructuredField(const char *filename);
	virtual ~StructuredField();
	double operator()(double x,double y,double z);
};
class LatLonField:public Field{
	Field *field;
	public:
	LatLonField(Field *_field):field(_field){};
	double operator()(double x,double y,double z);
};
class ParametricField:public Field{
	void *evalX,*evalY,*evalZ;
	Field *field;
	public:
	ParametricField(Field *_field,const char *strX,const char *strY,const char *strZ);
	double operator()(double x,double y,double z);
	~ParametricField();
};
class ThresholdField:public Field{
	Field *field;
	double dmin,dmax,lcmin,lcmax;
	public:
	ThresholdField(Field *field,double dmin,double dmax,double lcmin,double lcmax);
	double operator()(double x,double y,double z);
};
class GradField:public Field{
	Field *field;
	int kind;/*0 x, 1 y, 2 z, 3 max */
	double delta;
	public:
	GradField(Field *field,int _kind=2,double _delta=-1);
	double operator()(double x,double y,double z);
};
class FunctionField:public Field{
	std::list<Field*> *list;
	char **names;
	double *values;
	void *eval;
	public:
	FunctionField(std::list<Field*> *_list,const char *fct);
	double operator()(double x,double y,double z);
	~FunctionField();
};
class PostViewField:public Field{
	OctreePost *octree;
	int view_num;
	public:
	PostViewField(Post_View *view);
	double operator()(double x,double y,double z);
};
class MinField:public Field,public std::list<Field*>{
  public:
  MinField();
	double operator()(double x,double y,double z);
};

class AttractorField:public Field{
 protected :
#ifdef HAVE_ANN_
  ANNkd_tree* kdtree;
  ANNpointArray zeronodes;
  ANNidxArray index;
  ANNdistArray dist;
#endif
  std::list <SPoint3> attractorPoints;  
public :
  AttractorField();
  virtual ~AttractorField();
  void addPoint ( double X, double Y, double Z, double lc = -1.0);
  void buildFastSearchStructures() ;
  void addGEdge(GEdge*, int);
  void addCurve(Curve*, int);
  double operator()(double X, double Y, double Z) ;
};

#endif
