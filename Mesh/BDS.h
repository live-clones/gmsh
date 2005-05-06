// This is a 2D version of the Bidirectional Data Structure (BDS)
// of shephard and beall
// points may know the normals to the surface they are classified on
// default values are 0,0,1

#include <set>
#include <map>
#include <vector>
#include <list>
#include <math.h>
#include <algorithm>

class BDS_Edge;
class BDS_Triangle;
class BDS_Mesh;
class BDS_Point;

class BDS_Surface
{
public :
    virtual double signedDistanceTo ( BDS_Point * ) const = 0;
    virtual void projection ( double xa, double ya, double za,
			      double &x, double &y, double &z) const =0;
};


class BDS_GeomEntity
{
public:
    int classif_tag;
    int classif_degree;

    BDS_Surface *surf;

    inline bool operator <  ( const BDS_GeomEntity & other ) const
	{
	    if (classif_degree < other.classif_degree)return true;
	    if (classif_degree > other.classif_degree)return false;
	    if (classif_tag < other.classif_tag)return true;
	    return false;
	}
    BDS_GeomEntity (int a, int b)
	: classif_tag (a),classif_degree(b),surf(0)
	{
	}
};


void print_face (BDS_Triangle *t);

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

class BDS_Vector
{
public:
  double x,y,z;
  BDS_Vector operator + (const  BDS_Vector &v)
  {
    return BDS_Vector (x+v.x,y+v.y,z+v.z);
  }
  inline BDS_Vector operator % (const BDS_Vector &other) const
      {
	  return BDS_Vector(y*other.z-z*other.y,
			    z*other.x-x*other.z,
			    x*other.y-y*other.x);
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
  double operator * (const  BDS_Vector &v) const
  {
    return (x*v.x+y*v.y+z*v.z);
  }
  BDS_Vector (const BDS_Point &p2,const BDS_Point &p1)
      : x(p2.X-p1.X),y(p2.Y-p1.Y),z(p2.Z-p1.Z)
      {
	  
      }
  BDS_Vector (double ix=0, double iy=0, double iz=0)
    //    : x(ix),(iy),z(iz)
  {
    x=ix;
    y=iy;
    z=iz;
  }
};


class BDS_Edge
{
    std::vector <BDS_Triangle *> _faces;
public:
    bool deleted;
    BDS_Point *p1,*p2;
    BDS_GeomEntity *g;
    inline BDS_Triangle* faces(int i) const
	{
	    return _faces [i];
	}

    inline double length () const
	{
	    return sqrt ((p1->X-p2->X)*(p1->X-p2->X)+(p1->Y-p2->Y)*(p1->Y-p2->Y)+(p1->Z-p2->Z)*(p1->Z-p2->Z));
	}
    inline int numfaces ( ) const 
	{
	    return _faces.size();
	}
    inline BDS_Point * commonvertex ( const BDS_Edge *other ) const
      {
	if (p1 == other->p1 || p1 == other->p2) return p1;
	if (p2 == other->p1 || p2 == other->p2) return p2;
	return 0;
      }

    inline BDS_Point * othervertex ( const BDS_Point *p ) const
      {
	if (p1 == p) return p2;
	if (p2 == p) return p1;
	return 0;
      }

    inline void addface ( BDS_Triangle *f)
	{
	    _faces.push_back(f);
	}
    inline bool operator <  ( const BDS_Edge & other ) const
	{
	    if (*other.p1 < *p1) return true;
	    if (*p1 < *other.p1) return false;
	    if (*other.p2 < *p2) return true;
	    return false;
	}
    inline BDS_Triangle * otherFace ( const BDS_Triangle *f) const
      {
	  if (numfaces()!=2) throw;
	  if (f == _faces[0]) return _faces[1];
	  if (f == _faces[1]) return _faces[0];
	  throw;
      }
    inline void del (BDS_Triangle *t)
	{
	    _faces.erase ( std::remove_if (_faces.begin(),_faces.end() , std::bind2nd(std::equal_to<BDS_Triangle*> (), t)) , 
			   _faces.end () );
	}

    inline void oppositeof (BDS_Point * oface[2]) const; 

    BDS_Edge ( BDS_Point *A, BDS_Point *B )
	: deleted(false), g(0)
	{	    
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
    BDS_Edge *e1,*e2,*e3;
    BDS_Vector N() const ;
    BDS_GeomEntity *g;

    inline void getNodes (BDS_Point *n[3]) const
	{
	  n[0] = e1->commonvertex (e3);
	  n[1] = e1->commonvertex (e2);
	  n[2] = e2->commonvertex (e3);
	}
    BDS_Triangle ( BDS_Edge *A, BDS_Edge *B, BDS_Edge *C)
	: deleted (false) , e1(A),e2(B),e3(C),g(0)
	{	
	    e1->addface(this);
	    e2->addface(this);
	    e3->addface(this);
	}
};


class BDS_Plane : public  BDS_Surface
{
    double a,b,c;
public :
    BDS_Plane (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3);
    virtual double signedDistanceTo ( BDS_Point * p) const {return a*p->X + b*p->Y + c*p->Z + 1;}
    virtual void projection ( double xa, double ya, double za,
			      double &x, double &y, double &z) const 
	{
	    double k = - ( a * xa +  b * ya +  c * za + 1 ) / ( a * a + b * b + c * c ); 
	    x = xa + k * a;
	    y = ya + k * b;
	    z = za + k * c;
	}
};

class BDS_Sphere : public  BDS_Surface
{
public :
    double xc,yc,zc,R;
    BDS_Sphere (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, BDS_Point *p4);
    virtual double signedDistanceTo ( BDS_Point * p) const {
	return sqrt((p->X-xc)*(p->X-xc)+
		    (p->Y-yc)*(p->Y-yc)+
		    (p->Z-zc)*(p->Z-zc)) - R;
    }
    virtual void projection ( double xa, double ya, double za,
			      double &x, double &y, double &z) const 
	{
	    double k =  ( R * R )/((xa-xc)*(xa-xc)+(ya-yc)*(ya-yc)+(za-zc)*(za-zc)) ; 
	    x = xc + k * (xa-xc);
	    y = yc + k * (ya-yc);
	    z = zc + k * (za-zc);
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
class PointLessThanLexicographic
{
 public:
    static double t;
    bool operator()(const BDS_Point* ent1, const BDS_Point* ent2) const
	{
	    if ( ent1->X - ent2->X  >  t ) return true;
	    if ( ent1->X - ent2->X  < -t ) return false;
	    if ( ent1->Y - ent2->Y  >  t ) return true;
	    if ( ent1->Y - ent2->Y  < -t ) return false;
	    if ( ent1->Z - ent2->Z  >  t ) return true;
	    return false;
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

class BDS_Mesh 
{    
    int MAXPOINTNUMBER;
 public:
    double Min[3],Max[3],LC;

    void projection ( double &x, double &y, double &z );

    BDS_Mesh(int _MAXX = 0) :  MAXPOINTNUMBER (_MAXX){}
    virtual ~BDS_Mesh ();
    BDS_Mesh (const BDS_Mesh &other);
    std::set<BDS_GeomEntity*,GeomLessThan> geom; 
    std::set<BDS_Point*,PointLessThan>     points; 
    std::set<BDS_Edge*, EdgeLessThan>      edges; 
    std::set<BDS_Edge*>                    edges_to_delete; 
    std::list<BDS_Triangle*>   triangles; 
    BDS_Point * add_point (int num , double x, double y,double z);
    BDS_Edge  * add_edge  (int p1, int p2);
    void del_point  (BDS_Point *p);
    void del_edge  (BDS_Edge *e);
    BDS_Triangle *add_triangle  (int p1, int p2, int p3);
    void del_triangle  (BDS_Triangle *t);
    void add_geom  (int degree, int tag);
    BDS_Point *find_point (int num);
    BDS_Edge  *find_edge (int p1, int p2);
    BDS_Edge  *find_edge (BDS_Point *p1, BDS_Point *p2, BDS_Triangle *t)const;
    BDS_GeomEntity *get_geom  (int p1, int p2);
    bool swap_edge ( BDS_Edge *);
    bool collapse_edge ( BDS_Edge *, BDS_Point*, const double eps);
    bool smooth_point ( BDS_Point* , BDS_Mesh *geom = 0);
    bool split_edge ( BDS_Edge *, double coord);
    void classify ( double angle);
    void reverseEngineerCAD ( ) ;
    int adapt_mesh(double,bool smooth = false,BDS_Mesh *geom = 0);
    void cleanup();
    // io's 
    // STL
    bool read_stl  ( const char *filename, const double tolerance);
    // INRIA MESH
    bool read_mesh  ( const char *filename);
    bool read_vrml ( const char *filename);
    void save_gmsh_format (const char *filename);
};
void normal_triangle (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3]);
