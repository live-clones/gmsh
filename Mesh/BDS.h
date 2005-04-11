// This is a 2D version of the Bidirectional Data Structure (BDS)
// of shephard and beall
// points may know the normals to the surface they are classified on
// default values are 0,0,1

#include <set>
#include <list>

class BDS_GeomEntity
{
public:
    int classif_degree;
    int classif_tag;
    inline bool operator <  ( const BDS_GeomEntity & other ) const
	{
	    if (classif_degree < other.classif_degree)return true;
	    if (classif_degree > other.classif_degree)return false;
	    if (classif_tag < other.classif_tag)return true;
	    return false;
	}
    BDS_GeomEntity (int a, int b)
	: classif_degree (a),classif_tag(b)
	{
	}
};


class BDS_Edge;
class BDS_Triangle;

class BDS_Point
{
public:
  int iD;
  BDS_GeomEntity *g;
  double X,Y,Z;
  std::list<BDS_Edge*> edges;
  inline bool operator <  ( const BDS_Point & other ) const
  {
    return iD < other.iD;
  }
  BDS_Point ( int id, double x=0, double y=0, double z=0 )
    : iD(id),X(x),Y(y),Z(z),g(0)
  {	    
  }
};

class BDS_Edge
{
public:
    BDS_Point *p1,*p2;
    BDS_GeomEntity *g;
    BDS_Triangle*faces[2];
    inline int numfaces ( ) const 
	{
	    if (faces[1]) return 2;
	    if (faces[0]) return 1;
	    return 0;
	}
    inline void addface ( BDS_Triangle *f)
	{
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
    BDS_Edge ( BDS_Point *A, BDS_Point *B )
	: g(0)
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
    BDS_Edge *e1,*e2,*e3;
    BDS_GeomEntity *g;
    double NX,NY,NZ;
    inline bool operator <  ( const BDS_Triangle & other ) const
	{
	    if (*other.e1 < *e1) return true;
	    if (*e1 < *other.e1) return false;
	    if (*other.e2 < *e2) return true;
	    if (*e2 < *other.e2) return false;
	    if (*other.e3 < *e3) return true;
	    return false;
	}
    BDS_Triangle ( BDS_Edge *A, BDS_Edge *B, BDS_Edge *C , double nx=0, double ny=0, double nz=0)
	: NX(nx),NY(ny),NZ(nz),g(0)
	{	    
	    if (*A < *B && *A < *C) 
	    {
		if (*B < *C) 
		{
		    e1=A;
		    e2=B;
		    e3=C;
		}
		else
		{
		    e1=A;
		    e2=C;
		    e3=B;
		}
	    }
	    else if (*B < *A && *B < *C) 
	    {
		if (*A < *C) 
		{
		    e1=B;
		    e2=A;
		    e3=C;
		}
		else
		{
		    e1=B;
		    e2=C;
		    e3=A;
		}
	    }
	    else
	    {
		if (*A < *B) 
		{
		    e1=C;
		    e2=A;
		    e3=B;
		}
		else
		{
		    e1=C;
		    e2=B;
		    e3=A;
		}
	    }
	    e1->addface(this);
	    e2->addface(this);
	    e3->addface(this);
	}
};

class BDS_Mesh 
{
 public:
    std::set<BDS_GeomEntity> geom; 
    std::set<BDS_Point>      points; 
    std::set<BDS_Edge>       edges; 
    std::set<BDS_Triangle>   triangles; 
    void add_point (int num , double x, double y,double z);
    void add_edge  (int p1, int p2);
    void add_triangle  (int p1, int p2, int p3);
    void add_triangle  (int p1, int p2, int p3, double nx, double ny, double nz);
    void add_geom  (int degree, int tag);
    BDS_Point *find_point (int num);
    BDS_Edge  *find_edge (int p1, int p2);
  BDS_GeomEntity *get_geom  (int p1, int p2);
//    bool swap_edge ( BDS_Edge *);
//    bool collapse_edge ( BDS_Edge *);
//    bool split_edge ( BDS_Edge *, double coord);
    void save_gmsh_format (const char *filename);
    void classify ( double angle);
};
