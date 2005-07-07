// This is a 2D version of the Bidirectional Data Structure (BDS)
// of shephard and beall
// points may know the normals to the surface they are classified on
// default values are 0,0,1

#include <string>
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
    virtual double signedDistanceTo ( double x, double y, double z ) const = 0;
    virtual void projection ( double xa, double ya, double za,
			      double &x, double &y, double &z) const =0;
    virtual std::string nameOf () const = 0;
//    virtual BDS_Vector Gradient ( double x, double y, double z ) const = 0;
    virtual double normalCurv ( double x, double y, double z ) const = 0;
};


class BDS_GeomEntity
{
public:
    int classif_tag;
    int classif_degree;

    std::list<BDS_Triangle *> t;
    std::list<BDS_Edge *>     e;
    BDS_Point   *p;
    BDS_Surface *surf;

    inline bool operator <  ( const BDS_GeomEntity & other ) const
	{
	    if (classif_degree < other.classif_degree)return true;
	    if (classif_degree > other.classif_degree)return false;
	    if (classif_tag < other.classif_tag)return true;
	    return false;
	}
    BDS_GeomEntity (int a, int b)
	: classif_tag (a),classif_degree(b),p(0),surf(0)
	{
	}
};


void print_face (BDS_Triangle *t);

class BDS_Vector
{
public:
  double x,y,z;
  bool operator<(const BDS_Vector &o) const
      {
	  if ( x - o.x  > t  ) return true;
	  if ( x - o.x  < -t ) return false;
	  if ( y - o.y  > t  ) return true;
	  if ( y - o.y  < -t ) return false;
	  if ( z - o.z  > t  ) return true;
	  return false;
      }
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
  BDS_Vector& operator *= (const  double &v)
  {
    x*=v;
    y*=v;
    z*=v;
    return *this;
  }
  BDS_Vector& operator /= (const  double &v)
  {
    x/=v;
    y/=v;
    z/=v;
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
  double angle (const  BDS_Vector &v) const
  {
    double a[3] = { x ,  y ,  z };
    double b[3] = { v.x ,  v.y ,  v.z };
    double c[3];
    c[2] = a[0] * b[1] - a[1] * b[0];
    c[1] = -a[0] * b[2] + a[2] * b[0];
    c[0] = a[1] * b[2] - a[2] * b[1];
    double cosa = a[0]*b[0] +a[1]*b[1] +a[2]*b[2];
    double sina = sqrt (c[0]*c[0] + c[1]*c[1] + c[2]*c[2]);
    double ag = atan2(sina,cosa);
    return ag;
  }
  double operator * (const  BDS_Vector &v) const
  {
    return (x*v.x+y*v.y+z*v.z);
  }
  BDS_Vector (const BDS_Point &p2,const BDS_Point &p1);

  BDS_Vector (const double X=0., const double Y=0., const double Z=0.)
        : x(X),y(Y),z(Z)
  {
  }
  static double t;
};


class BDS_Pos
{
 public:
    double X,Y,Z;    
    BDS_Pos(const double &x,const double &y, const double & z)
	: X(x),Y(y),Z(z)
	{
	}
};

class BDS_Point : public BDS_Pos
{
public:
    int iD;
    double radius_of_curvature;
    BDS_GeomEntity *g;
    std::list<BDS_Edge*> edges;

    BDS_Vector N() const;

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
    void getTriangles (std::list<BDS_Triangle *> &t) const; 	

    void compute_curvature ( );

    BDS_Point ( int id, double x=0, double y=0, double z=0 )
	: BDS_Pos(x,y,z),iD(id),radius_of_curvature(1.e22),g(0)
	{	    
	}
};

class BDS_Edge
{
    std::vector <BDS_Triangle *> _faces;
public:
    bool deleted;
    int status;
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
	: deleted(false), status(0),g(0)
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
    int status;
    BDS_Edge *e1,*e2,*e3;
    BDS_Vector N() const ;
    BDS_GeomEntity *g;

    inline BDS_Vector cog() const
	{
	    BDS_Point *n[3];
	    getNodes (n);
	    return BDS_Vector ((n[0]->X+n[1]->X+n[2]->X)/3.,
			       (n[0]->Y+n[1]->Y+n[2]->Y)/3.,
			       (n[0]->Z+n[1]->Z+n[2]->Z)/3.);
	}

    inline void getNodes (BDS_Point *n[3]) const
	{
	  n[0] = e1->commonvertex (e3);
	  n[1] = e1->commonvertex (e2);
	  n[2] = e2->commonvertex (e3);
	}
    BDS_Triangle ( BDS_Edge *A, BDS_Edge *B, BDS_Edge *C)
	: deleted (false) , status(0), e1(A),e2(B),e3(C),g(0)
	{	
	    e1->addface(this);
	    e2->addface(this);
	    e3->addface(this);
	}
};


class BDS_Plane : public  BDS_Surface
{
    double a,b,c,d;
public :
    BDS_Plane (const double &A, const double &B, const double &C)
	: a(A),b(B),c(C)
	{
	}
    virtual double signedDistanceTo (  double x, double y, double z ) const {return a*x + b*y + c*z + 1;}
    virtual void projection ( double xa, double ya, double za,
			      double &x, double &y, double &z) const 
	{
	    double k = - ( a * xa +  b * ya +  c * za + 1 ) / ( a * a + b * b + c * c ); 
	    x = xa + k * a;
	    y = ya + k * b;
	    z = za + k * c;
	}
    virtual std::string nameOf () const {return std::string("Plane");}
    virtual BDS_Vector Gradient ( double x, double y, double z ) const
	{
	    return BDS_Vector ( a , b , c );
	} 
    virtual double normalCurv ( double x, double y, double z ) const
	{
	    return 0.0;
	}
};

class BDS_Quadric : public  BDS_Surface
{
public :
    double a,b,c,d,e,f,g,h,i;
    BDS_Quadric (double A,double B,double C, double D, double E, double F, double G, double H, double I)
	: a(A),b(B),c(C),d(D),e(E),f(F),g(G),h(H),i(I)
	{
	}

    virtual BDS_Vector Gradient ( double x, double y, double z ) const 
	{
	    return BDS_Vector ( 2* ( a * x + d * y + e * z ) + g ,
				2* ( d * x + b * y + f * z ) + h ,
				2* ( e * x + f * y + c * z ) + i );
	}

    virtual double normalCurv ( double x, double y, double z ) const;

    virtual double signedDistanceTo (  double x, double y, double z ) const {
	const double q = 
	    a * x * x +  
	    b * y * y +  
	    c * z * z +  
	    2 * d * x * y + 
	    2 * e * x * z + 
	    2 * f * y * z +
	    g *  x +
	    h *  y +
	    i *  z - 1.0;
	return q;
    }
    virtual void projection ( double xa, double ya, double za,
			      double &x, double &y, double &z) const ;
    virtual std::string nameOf () const {return std::string("Quadric");}
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
    bool collapse_edge ( BDS_Edge *, BDS_Point*, const double eps, const double l);
    bool smooth_point   ( BDS_Point* , BDS_Mesh *geom = 0);
    bool smooth_point_b ( BDS_Point* );
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
void project_point_on_a_list_of_triangles ( BDS_Point *p , const std::list<BDS_Triangle*> &t,
					    double &X, double &Y, double &Z);	   
