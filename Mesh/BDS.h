// This is a 2D version of the Bidirectional Data Structure (BDS)
// of shephard and beall
// points may know the normals to the surface they are classified on
// default values are 0,0,1

#include <set>
#include <map>
#include <list>
#include <math.h>

class BDS_GeomEntity
{
public:
    int classif_tag;
    int classif_degree;
    inline bool operator <  ( const BDS_GeomEntity & other ) const
	{
	    if (classif_degree < other.classif_degree)return true;
	    if (classif_degree > other.classif_degree)return false;
	    if (classif_tag < other.classif_tag)return true;
	    return false;
	}
    BDS_GeomEntity (int a, int b)
	: classif_tag (a),classif_degree(b)
	{
	}
};


class BDS_Edge;
class BDS_Triangle;
class BDS_Mesh;

class BDS_Vector
{
public:
  double x,y,z;
  BDS_Vector operator + (const  BDS_Vector &v)
  {
    return BDS_Vector (x+v.x,y+v.y,z+v.z);
  }
  BDS_Vector& operator += (const  BDS_Vector &v)
  {
    x+=v.x;
    y+=v.y;
    z+=v.z;
    return *this;
  }
  BDS_Vector operator / (const  double &v)
  {
    return BDS_Vector (x/v,y/v,z/v);
  }
  BDS_Vector operator * (const  double &v)
  {
    return BDS_Vector (x*v,y*v,z*v);
  }
  BDS_Vector (double ix=0, double iy=0, double iz=0)
    //    : x(ix),(iy),z(iz)
  {
    x=ix;
    y=iy;
    z=iz;
  }
};

class BDS_Point
{
public:
    int iD;
    double X,Y,Z;
    BDS_GeomEntity *g;
    std::list<BDS_Edge*> edges;
    inline bool operator <  ( const BDS_Point & other ) const
	{
	    return iD < other.iD;
	}
    inline void del (BDS_Edge *e)
	{
	    std::list<BDS_Edge*>::iterator it  = edges.begin();
	    std::list<BDS_Edge*>::iterator ite = edges.end();
	    while(it!=ite)
	    {
		if (*it == e) 
		{
		    edges.erase(it);
		    break;
		}
		++it;
	    }
	}
    void getTriangles (std::list<BDS_Triangle *> &t); 	

    BDS_Point ( int id, double x=0, double y=0, double z=0 )
    : iD(id),X(x),Y(y),Z(z),g(0)
	{	    
	}
};

class BDS_Edge
{
public:
    bool deleted;
    BDS_Point *p1,*p2;
    BDS_GeomEntity *g;
    BDS_Triangle*faces[2];
    inline double length () const
	{
	    return sqrt ((p1->X-p2->X)*(p1->X-p2->X)+(p1->Y-p2->Y)*(p1->Y-p2->Y)+(p1->Z-p2->Z)*(p1->Z-p2->Z));
	}
    inline int numfaces ( ) const 
	{
	    if (faces[1]) return 2;
	    if (faces[0]) return 1;
	    return 0;
	}
    inline void addface ( BDS_Triangle *f)
	{
	    if (faces[1])
	    {
		printf("Non Manifold model not done yet\n");
		throw 1;
	    }
	    if(faces [0])faces[1] = f;
	    else faces[0] = f;
	}
    inline bool operator <  ( const BDS_Edge & other ) const
	{
	    if (*other.p1 < *p1) return true;
	    if (*p1 < *other.p1) return false;
	    if (*other.p2 < *p2) return true;
	    return false;
	}
    inline BDS_Triangle * otherFace ( BDS_Triangle *f)
      {
	if (f == faces[0]) return faces[1];
	if (f == faces[1]) return faces[0];
	throw;
      }
    inline void del (BDS_Triangle *t)
	{
	    if (faces[0] == t)
	    {
		faces[0] = faces[1];
	    }
	    else if (faces[1]!=t)
	    {
		printf("edge with faces %p %p : cannot delete %p\n",faces[0],faces[1],t);
		throw;
	    }
	    faces [1] = 0;
	}

    inline void oppositeof (BDS_Point * oface[2]) const; 

    BDS_Edge ( BDS_Point *A, BDS_Point *B )
	: deleted(false), g(0)
	{	    
	    faces[0] = faces[1] = 0;
	    if (*A < *B) 
	    {
		p1=A;
		p2=B;
	    }
	    else
	    {
		p1=B;
		p2=A;
	    }
	    p1->edges.push_back(this);
	    p2->edges.push_back(this);
	}
};

class BDS_Triangle
{
public:
    bool deleted;
    int ori_first_edge;
    BDS_Edge *e1,*e2,*e3;
    BDS_Vector N() const ;
    BDS_GeomEntity *g;
    inline void getNodes (BDS_Point *n[3]) const
	{
	    if (ori_first_edge == 1)
	    {
		n[0] = e1->p1;
		n[1] = e1->p2;
	    }
	    else
	    {
		n[0] = e1->p2;
		n[1] = e1->p1;
	    }
	    if (e2->p1 != n[0] && e2->p1 != n[1])n[2] = e2->p1;
	    else n[2] = e2->p2;
	}
    BDS_Triangle ( BDS_Edge *A, BDS_Edge *B, BDS_Edge *C, BDS_Point *first_vertex)
	: deleted (false) , e1(A),e2(B),e3(C),g(0)
	{	
	    if (first_vertex == A->p1) 
		ori_first_edge = 1;
	    else  if (first_vertex == A->p2) 
		ori_first_edge = -1;
	    else
		throw;
	    e1->addface(this);
	    e2->addface(this);
	    e3->addface(this);
	}
};
class GeomLessThan
{
 public:
    bool operator()(const BDS_GeomEntity* ent1, const BDS_GeomEntity* ent2) const
	{
	    return *ent1 < *ent2;
	}
};
class PointLessThan
{
 public:
    bool operator()(const BDS_Point* ent1, const BDS_Point* ent2) const
	{
	    return *ent1 < *ent2;
	}
};
class EdgeLessThan
{
 public:
    bool operator()(const BDS_Edge* ent1, const BDS_Edge* ent2) const
	{
	    return *ent1 < *ent2;
	}
};

class BDS_Projector 
{
 public:
    virtual bool project ( const double &X, const double &Y, const double &Z, const BDS_Vector & n,
			   double &Xp, double &Yp, double &Zp ) const = 0;
};

class BDS_NoProjector : public  BDS_Projector
{
 public:
    bool project ( const double &X, const double &Y, const double &Z, const BDS_Vector & n,
		   double &Xp, double &Yp, double &Zp ) const
	{
	    Xp = X;
	    Yp = Y;
	    Zp = Z;
	    return true;
	}
};

class BDS_BDSProjector : public  BDS_Projector
{
    BDS_Mesh &m;
 public:
    BDS_BDSProjector (BDS_Mesh &_m) : m(_m){}
    bool project ( const double &X, const double &Y, const double &Z, const BDS_Vector & n,
		   double &Xp, double &Yp, double &Zp ) const;
};

class BDS_Mesh 
{
    int MAXPOINTNUMBER;
 public:
    std::set<BDS_GeomEntity*,GeomLessThan> geom; 
    std::set<BDS_Point*,PointLessThan>     points; 
    std::set<BDS_Edge*, EdgeLessThan>      edges; 
    std::set<BDS_Edge*>                    edges_to_delete; 
    std::list<BDS_Triangle*>   triangles; 
    BDS_Point * add_point (int num , double x, double y,double z);
    BDS_Edge  * add_edge  (int p1, int p2);
    void del_edge  (BDS_Edge *e);
    void add_triangle  (int p1, int p2, int p3);
    void del_triangle  (BDS_Triangle *t);
    void add_triangle  (int p1, int p2, int p3, double nx, double ny, double nz);
    void add_geom  (int degree, int tag);
    BDS_Point *find_point (int num);
    BDS_Edge  *find_edge (int p1, int p2);
    BDS_Edge  *find_edge (BDS_Point *p1, BDS_Point *p2, BDS_Triangle *t)const;
    BDS_GeomEntity *get_geom  (int p1, int p2);
    bool swap_edge ( BDS_Edge *);
    bool collapse_edge ( BDS_Edge *, BDS_Point*, const BDS_Projector &);
    bool smooth_point ( BDS_Point*, const BDS_Projector &);
    bool split_edge ( BDS_Edge *, double coord, const BDS_Projector &);
    void save_gmsh_format (const char *filename);
    void classify ( double angle);
    BDS_Mesh() :  MAXPOINTNUMBER (0){}
    virtual ~BDS_Mesh ();
    void adapt_mesh(double, const BDS_Projector &);
    void cleanup();
};
