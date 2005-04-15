#include "BDS.h"
#include <map>
#include <math.h>
#include "Numeric.h"

void proj_point_plane ( double xa, double ya, double za,
			BDS_Point *p1, BDS_Point *p2, BDS_Point *p3 ,
			double &x, double &y, double &z)
{
    /// plane ax+by+cz+1 = 0;

    double mat[3][3];
    mat[0][0] = p1->X; mat[0][1] = p1->Y; mat[0][2] = p1->Z;
    mat[1][0] = p2->X; mat[1][1] = p2->Y; mat[1][2] = p2->Z;
    mat[2][0] = p3->X; mat[2][1] = p3->Y; mat[2][2] = p3->Z;
    double b[3] = {-1,-1,-1};
    double pl[3] , det ;
    sys3x3 (mat,b,pl,&det);
    double n[3] = {pl[0],pl[1],pl[2]}; 
//    norme(n);
    // pp(x,y,z) = p + k n
    // pp belongs to the plane
    // a x + b y + c z + 1 = 0
    // x = xa + k nx
    // y = ya + k ny
    // z = za + k nz
    // a (xa + k nx) + b ( ya + k ny ) + c (  za + k nz ) + 1 = 0
    // k = - ( a xa + b ya + c za + 1) / (a nx + b ny + c nz )
    double k = - ( pl[0] * xa +  pl[1] * ya +  pl[2] * za + 1 ) / ( pl[0] * n[0] + pl[1] * n[1] + pl[2] * n[2] ); 
    x = xa + k * n[0];
    y = ya + k * n[1];
    z = za + k * n[2];
}

void print_face (BDS_Triangle *t)
{
    BDS_Point *pts[3];
    t->getNodes (pts); 
    printf("face %p with nodes %d %d %d and edges %p (%d %d) %p (%d %d) %p (%d %d)\n",t,pts[0]->iD,pts[1]->iD,pts[2]->iD,
	   t->e1,t->e1->p1->iD,t->e1->p2->iD,t->e2,t->e2->p1->iD,t->e2->p2->iD,t->e3,t->e3->p1->iD,t->e3->p2->iD);
}

void vector_triangle (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3]) 
{
    double a[3] = { p1->X - p2->X,p1->Y - p2->Y,p1->Z - p2->Z};
    double b[3] = { p1->X - p3->X,p1->Y - p3->Y,p1->Z - p3->Z};
    c[2] = a[0] * b[1] - a[1] * b[0];
    c[1] = -a[0] * b[2] + a[2] * b[0];
    c[0] = a[1] * b[2] - a[2] * b[1];
}

void normal_triangle (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3, double c[3]) 
{
    vector_triangle (p1,p2,p3,c);
    double l = sqrt (c[0]*c[0]+c[1]*c[1]+c[2]*c[2]);
    if (l==0)return;
    c[0]/=l;
    c[1]/=l;
    c[2]/=l;
}

double surface_triangle (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3) 
{
    double c[3];
    vector_triangle (p1,p2,p3,c);
    return 0.5*sqrt (c[0]*c[0]+c[1]*c[1]+c[2]*c[2]);
}
double quality_triangle  (BDS_Point *p1, BDS_Point *p2, BDS_Point *p3)
{
    double e12 =  ((p1->X - p2->X)*(p1->X - p2->X)+
		   (p1->Y - p2->Y)*(p1->Y - p2->Y)+
		   (p1->Z - p2->Z)*(p1->Z - p2->Z));
    double e22 =  ((p1->X - p3->X)*(p1->X - p3->X)+
		   (p1->Y - p3->Y)*(p1->Y - p3->Y)+
		   (p1->Z - p3->Z)*(p1->Z - p3->Z));
    double e32 =  ((p3->X - p2->X)*(p3->X - p2->X)+
		   (p3->Y - p2->Y)*(p3->Y - p2->Y)+
		   (p3->Z - p2->Z)*(p3->Z - p2->Z));
    double a =  surface_triangle ( p1,p2,p3);
    return a / (e12+e22+e32);
}


void BDS_Point::getTriangles (std::list<BDS_Triangle *> &t)
{
  t.clear ();
  std::list<BDS_Edge*>::iterator it  = edges.begin();
  std::list<BDS_Edge*>::iterator ite = edges.end();
  while(it!=ite)
    {
      for (int i=0;i<2;++i)
	{
	  BDS_Triangle *tt = (*it)->faces[i];
	  if (tt)
	    {
	      std::list<BDS_Triangle*>::iterator tit  = t.begin();
	      std::list<BDS_Triangle*>::iterator tite = t.end();
	      int found = 0;
	      while (tit!=tite) 
		{
		  if (tt == *tit)found = 1;
		  ++tit;
		}
	      if (!found) t.push_back (tt);
	    }		    
	}
      ++it;
    }
}

BDS_Point* BDS_Mesh :: add_point (int num , double x, double y,double z)
{
    BDS_Point *pp = new BDS_Point ( num, x, y, z);
    points.insert ( pp );    
    MAXPOINTNUMBER = ( MAXPOINTNUMBER < num )? num : MAXPOINTNUMBER;
    return pp;
}

BDS_Point *BDS_Mesh :: find_point  (int p)
{
    BDS_Point P ( p ) ;
    std::set<BDS_Point*,PointLessThan>::iterator it = points.find(&P);
    if (it != points.end()) return (BDS_Point*) (*it);
    else return 0;
}

BDS_Edge *BDS_Mesh :: find_edge  (int num1, int num2)
{
    BDS_Point P1 ( num1 ) ;
    BDS_Point P2 ( num2 ) ;
    BDS_Edge  E (&P1, &P2);
    std::set<BDS_Edge*, EdgeLessThan>::iterator it = edges.find(&E);
    if (it != edges.end()) return (BDS_Edge*) (*it);
    else return 0;
}

BDS_Edge *BDS_Mesh :: find_edge  (BDS_Point *p1, BDS_Point *p2, BDS_Triangle *t) const
{
    BDS_Point P1 ( p1->iD ) ;
    BDS_Point P2 ( p2->iD ) ;
    BDS_Edge  E (&P1, &P2);
    if (t->e1->p1->iD == E.p1->iD && t->e1->p2->iD == E.p2->iD)return t->e1;
    if (t->e2->p1->iD == E.p1->iD && t->e2->p2->iD == E.p2->iD)return t->e2;
    if (t->e3->p1->iD == E.p1->iD && t->e3->p2->iD == E.p2->iD)return t->e3;
    return 0;
}

BDS_Edge *BDS_Mesh :: add_edge  (int p1, int p2)
{
    BDS_Edge *efound = find_edge (p1,p2);
    if (efound)return efound;

    BDS_Point *pp1=find_point(p1);
    BDS_Point *pp2=find_point(p2);
    if (!pp1 || !pp2)throw;
    BDS_Edge *e = new BDS_Edge ( pp1, pp2 );
    edges.insert ( e );
    return e;
}

void BDS_Mesh :: add_triangle  (int p1, int p2, int p3, double nx, double ny, double nz)
{
    add_edge (p1,p2);
    add_edge (p2,p3);
    add_edge (p3,p1);
    BDS_Edge *e1 = find_edge (p1,p2); 
    BDS_Edge *e2 = find_edge (p2,p3); 
    BDS_Edge *e3 = find_edge (p3,p1); 
    BDS_Triangle *t  = new BDS_Triangle ( e1, e2, e3 ,find_point(p1));    
    triangles.push_back ( t );        
}
void  BDS_Mesh :: del_triangle  (BDS_Triangle *t)
{
    t->e1->del ( t );
    t->e2->del ( t );
    t->e3->del ( t );
    t->deleted = true;
}
void  BDS_Mesh :: del_edge  (BDS_Edge *e)
{
    edges.erase ( e );
    e->p1->del ( e );
    e->p2->del ( e );
    e->deleted = true;
    edges_to_delete.insert (e);
}
void BDS_Mesh :: add_geom  (int p1, int p2)
{
    geom.insert ( new BDS_GeomEntity ( p1,p2 ) ) ;        
}

void BDS_Edge::oppositeof (BDS_Point * oface[2]) const
{
  oface[0] = oface[1] = 0;
  if (faces[0])
    {
      BDS_Point *pts[3];
      faces[0]->getNodes (pts); 
      if (pts[0] != p1 && pts[0] != p2)oface[0] = pts[0];
      else if (pts[1] != p1 && pts[1] != p2)oface[0] = pts[1];
      else oface[0] = pts[2];
    }
  if (faces[1])
    {
      BDS_Point *pts[3];
      faces[1]->getNodes (pts); 
      if (pts[0] != p1 && pts[0] != p2)oface[1] = pts[0];
      else if (pts[1] != p1 && pts[1] != p2)oface[1] = pts[1];
      else oface[1] = pts[2];
    }
}



BDS_GeomEntity * BDS_Mesh :: get_geom  (int p1, int p2)
{
    BDS_GeomEntity ge ( p1,p2 );
    std::set<BDS_GeomEntity*,GeomLessThan>::iterator it = geom.find(&ge);
    if (it == geom.end())return 0;
    return (BDS_GeomEntity*) (*it);
}


void recur_tag ( BDS_Triangle *t , BDS_GeomEntity *g )
{
  if (!t->g)
    {
      t->g = g;
      if ( ! t->e1->g && t->e1->numfaces() == 2)
	{
	  recur_tag (t->e1->otherFace (t) , g);
	}
      if ( ! t->e2->g && t->e2->numfaces() == 2)
	{
	  recur_tag (t->e2->otherFace (t) , g);
	}
      if ( ! t->e3->g && t->e3->numfaces() == 2)
	{
	  recur_tag (t->e3->otherFace (t) , g);
	}
    }
}

BDS_Vector BDS_Triangle :: N () const 
{
    BDS_Point *pts[3];
    getNodes (pts); 
    double c[3];
    normal_triangle (pts[0],pts[1],pts[2],c); 
    return BDS_Vector ( c[0], c[1], c[2] );
}


void BDS_Mesh :: classify ( double angle )
{
 
    static BDS_GeomEntity EDGE_CLAS (0,1);
    {
	std::set<BDS_Edge*, EdgeLessThan>::iterator it  = edges.begin();
	std::set<BDS_Edge*, EdgeLessThan>::iterator ite = edges.end();
	while (it!=ite)
	{
	    BDS_Edge &e = *((BDS_Edge *) *it);
	    if ( e.numfaces() == 1) e.g = &EDGE_CLAS;
	    else if (e.numfaces() == 2)
	    {
		BDS_Vector N0 = e.faces[0]->N();
		BDS_Vector N1 = e.faces[1]->N();
		double a[3] = { N0.x ,  N0.y ,  N0.z };
		double b[3] = { N1.x ,  N1.y ,  N1.z };
		double c[3];
		c[2] = a[0] * b[1] - a[1] * b[0];
		c[1] = -a[0] * b[2] + a[2] * b[0];
		c[0] = a[1] * b[2] - a[2] * b[1];
		double cosa = a[0]*b[0] +a[1]*b[1] +a[2]*b[2];
		double sina = sqrt (c[0]*c[0] + c[1]*c[1] + c[2]*c[2]);
		double ag = atan2(sina,cosa);
//		printf("edge with angle = %g sin %g cos %g n1 %g %g %g n2 %g %g %g\n",
//		       ag,sina,cosa,a[0],a[1],a[2],b[0],b[1],b[2]);
		if (fabs(ag) > angle)e.g = &EDGE_CLAS;
	    }
	    ++it;
	}
    }
    {
	int tag = 1;
	while (1)
	{
	    printf("tag %d\n",tag);
	    std::list<BDS_Triangle*>::iterator it  = triangles.begin();
	    std::list<BDS_Triangle*>::iterator ite = triangles.end();
	    BDS_Triangle *start = 0;
	    while (it!=ite)
	    {
		if (!(*it)->deleted && !(*it)->g)
		{
		    start = (BDS_Triangle*) (*it);
		}
		if (start)break;
		++it;
	    }
	    if (!start)break;	  
	    add_geom (tag, 2);
	    BDS_GeomEntity *g = get_geom (tag,2);
	    recur_tag ( start , g );
	    tag++;
	}
    }
//    return;
    {
	std::map< std::pair<int,int> , int > edgetags;
	std::set<BDS_Edge*, EdgeLessThan>::iterator it  = edges.begin();
	std::set<BDS_Edge*, EdgeLessThan>::iterator ite = edges.end();	
	int edgetag = 1;
	while (it!=ite)
	{
	    BDS_Edge &e = *((BDS_Edge *) *it);
	    
	    if (e.g)
	    {	    
		std::map< std::pair<int,int> , int >::iterator found;
		BDS_GeomEntity *g;
		if ( e.numfaces() == 1)
		{
		    found = edgetags.find (std::make_pair ( e.faces[0]->g->classif_tag,-1));
		}
		else if (e.numfaces() == 2 && e.faces[0]->g->classif_tag != e.faces[1]->g->classif_tag)
		{
		    if (e.faces[0]->g->classif_tag > e.faces[1]->g->classif_tag)
			found = edgetags.find (std::make_pair ( e.faces[1]->g->classif_tag,e.faces[0]->g->classif_tag));
		    else
			found = edgetags.find (std::make_pair ( e.faces[0]->g->classif_tag,e.faces[1]->g->classif_tag));
		}
		if (e.g)
		{
		    if (found == edgetags.end())
		    {
			add_geom (edgetag, 1);
			g = get_geom (edgetag,1);
			if ( e.numfaces() == 1)
			{
			    edgetags[std::make_pair ( e.faces[0]->g->classif_tag,-1)] = edgetag;
			}
			else if (e.numfaces() == 2)
			{
			    if (e.faces[0]->g->classif_tag > e.faces[1]->g->classif_tag)
				edgetags[std::make_pair ( e.faces[1]->g->classif_tag,e.faces[0]->g->classif_tag)]
				    = edgetag;
			    else
				edgetags[std::make_pair ( e.faces[0]->g->classif_tag,e.faces[1]->g->classif_tag)] 
				    = edgetag;
			}
			edgetag++;
		    }
		    else
		    {
			g = get_geom(found->second,1);
		    }
		    e.g = g;
		}
	    }
	    ++it;
	}
    }
}

void BDS_Mesh :: save_gmsh_format ( const char *filename )
{
    cleanup();
    FILE *f = fopen ( filename, "w");
    {
	std::set<BDS_Point*,PointLessThan>::iterator it  = points.begin();
	std::set<BDS_Point*,PointLessThan>::iterator ite = points.end();
	
	fprintf(f,"$NOD\n");
	fprintf(f,"%d\n",points.size());
	while(it!=ite)
	{
	    fprintf(f,"%d %g %g %g\n",(*it)->iD,(*it)->X,(*it)->Y,(*it)->Z);
	    ++it;
	}
	fprintf(f,"$ENDNOD\n");
    }
    {
	fprintf(f,"$ELM\n");
	
	int nbClasEdges = 0;
	{
	    std::set<BDS_Edge*, EdgeLessThan>::iterator it  = edges.begin();
	    std::set<BDS_Edge*, EdgeLessThan>::iterator ite = edges.end();
	    while(it!=ite)
	    {
		if ((*it)->g)nbClasEdges++;
		++it;
	    }
	}
	
	fprintf(f,"%d\n",nbClasEdges+triangles.size());
	
	int k=1;
	{
	    std::set<BDS_Edge*, EdgeLessThan>::iterator it  = edges.begin();
	    std::set<BDS_Edge*, EdgeLessThan>::iterator ite = edges.end();
	    while(it!=ite)
	    {
		if ((*it)->g)
		    fprintf(f,"%d %d %d %d %d %d %d\n",
			    k++,1,(*it)->g->classif_tag,(*it)->g->classif_tag,2,
			    (*it)->p1->iD, (*it)->p2->iD);
		++it;
		
	    }
	}
	{
	    std::list<BDS_Triangle*>::iterator it  = triangles.begin();
	    std::list<BDS_Triangle*>::iterator ite = triangles.end();
	    while(it!=ite)
	    {
		if ((*it)->deleted)
		{
		    printf("aahg\n");
		    throw;
		}
		BDS_Point *nod[3];
		(*it)->getNodes (nod);
		if ((*it)->g)
		    fprintf(f,"%d %d %d %d %d %d %d %d\n",
			    k++,2,(*it)->g->classif_tag,(*it)->g->classif_tag,3,
			nod[0]->iD,nod[1]->iD,nod[2]->iD);
		else
		    fprintf(f,"%d %d %d %d %d %d %d %d\n",
			    k++,2,1,1,3,
			    nod[0]->iD,nod[1]->iD,nod[2]->iD);
		++it;
		
	    }
	}
	fprintf(f,"$ENDELM\n");
    }
    fclose (f);
}

template <class IT>
void DESTROOOY ( IT beg , IT end)
{
    while (beg != end)
    {
	delete *beg;
	beg ++;
    }
}
void BDS_Mesh :: cleanup()
{
    for (std::list<BDS_Triangle*> :: iterator it = triangles.begin();
	 it != triangles.end();
	 it++)
    {
	while (it != triangles.end() && (*it)->deleted)
	{
	    delete *it;
	    it = triangles.erase (it);
	}
    }	    
    DESTROOOY ( edges_to_delete.begin(),edges_to_delete.end());
    edges_to_delete.clear();
}

BDS_Mesh ::~ BDS_Mesh ()
{
    DESTROOOY ( geom.begin(),geom.end());
    DESTROOOY ( points.begin(),points.end());
    DESTROOOY ( edges.begin(),edges.end());
    cleanup();
    DESTROOOY ( triangles.begin(),triangles.end());
}

bool BDS_Mesh ::split_edge ( BDS_Edge *e, double coord, const BDS_Projector &)
{

//    printf("split start %d\n",e->deleted);

    int nbFaces = e->numfaces();

    if (nbFaces == 1)return false;

    BDS_Point *op[2];
    BDS_Point *p1 = e->p1;
    BDS_Point *p2 = e->p2;
    MAXPOINTNUMBER++;
    BDS_Point *mid = add_point (MAXPOINTNUMBER , 
				coord * p1->X + (1-coord) * p2->X, 
				coord * p1->Y + (1-coord) * p2->Y, 
				coord * p1->Z + (1-coord) * p2->Z);

    // we should project 
    e->oppositeof (op);
    BDS_GeomEntity *g1=0,*g2=0,*ge=e->g;


    BDS_Edge *p1_op1 = find_edge ( p1, op[0], e->faces[0] );
    BDS_Edge *op1_p2 = find_edge ( op[0],p2,e->faces[0]  );
    BDS_Edge *p1_op2 = find_edge ( p1, op[1],e->faces[1] );
    BDS_Edge *op2_p2 = find_edge ( op[1],p2,e->faces[1]   );

//    BDS_Edge *p1_op1 = find_edge ( p1->iD, op[0]->iD );
//    BDS_Edge *op1_p2 = find_edge ( op[0]->iD,p2->iD  );
//    BDS_Edge *p1_op2 = find_edge ( p1->iD, op[1]->iD );
//    BDS_Edge *op2_p2 = find_edge ( op[1]->iD,p2->iD   );

//    printf("%p %p %p %p\n",p1_op1,op1_p2,p1_op2,op2_p2);

/*    printf("edge %p (%d %d) with %d neighbors\n",p1_op1,p1->iD, op[0]->iD,p1_op1->numfaces());
    print_face(p1_op1->faces[0]);
    print_face(p1_op1->faces[1]);
    printf("edge %p (%d %d) with %d neighbors\n",e,p1->iD, p2->iD,e->numfaces());
    print_face(e->faces[0]);
    print_face(e->faces[1]);
*/
    if (e->faces[0])
    {
	g1 = e->faces[0]->g;
	del_triangle (e->faces[0]);
    }
// not a bug !!!
    if (e->faces[0])
    {
	g2 = e->faces[0]->g;
	del_triangle (e->faces[0]);
    } 
    

    del_edge (e);


    BDS_Edge *p1_mid = new BDS_Edge ( p1, mid );
    edges.insert ( p1_mid );
    BDS_Edge *mid_p2 = new BDS_Edge ( mid, p2 );
    edges.insert ( mid_p2 );
    BDS_Edge *op1_mid = new BDS_Edge ( op[0], mid );
    edges.insert ( op1_mid );
    BDS_Edge *mid_op2 = new BDS_Edge ( mid, op[1] );
    edges.insert ( mid_op2 );

//    printf("split ends 1 %d (%d %d) %d %d \n",p1_op1->numfaces(), p1->iD, op[0]->iD, op1_mid->numfaces(),p1_mid->numfaces());
    BDS_Triangle*t1 =  new BDS_Triangle ( p1_op1, op1_mid, p1_mid ,op[0] );
    BDS_Triangle*t2 =  new BDS_Triangle ( op2_p2, mid_op2, mid_p2 ,op[1] );
    BDS_Triangle*t3 =  new BDS_Triangle ( op1_p2, op1_mid, mid_p2 ,p2);
    BDS_Triangle*t4 =  new BDS_Triangle ( p1_op2, mid_op2, p1_mid ,p1);
    
    t1->g = g1;
    t2->g = g2;
    t3->g = g1;
    t4->g = g2;

    p1_mid->g = ge;
    mid_p2->g = ge;

    triangles.push_back(t1); 
    triangles.push_back (t2); 
    triangles.push_back (t3); 
    triangles.push_back (t4); 

    return true;
}

bool BDS_Mesh ::swap_edge ( BDS_Edge *e)
{
    if (e->deleted)return false;

    int nbFaces = e->numfaces();


    BDS_Point *pts1[3];
    e->faces[0]->getNodes (pts1); 
    BDS_Point *pts2[3];
    e->faces[1]->getNodes (pts2); 


    if (nbFaces != 2)return false;
    if (e->g && e->g->classif_degree != 2)return false;

    BDS_Point *op[2];
    BDS_Point *p1 = e->p1;
    BDS_Point *p2 = e->p2;
    e->oppositeof (op);
    BDS_GeomEntity *g1=0,*g2=0,*ge=e->g;

    BDS_Edge *p1_op1 = find_edge ( p1, op[0], e->faces[0] );
    BDS_Edge *op1_p2 = find_edge ( op[0],p2,e->faces[0]  );
    BDS_Edge *p1_op2 = find_edge ( p1, op[1],e->faces[1] );
    BDS_Edge *op2_p2 = find_edge ( op[1],p2,e->faces[1]   );

    if (e->faces[0])
    {
	g1 = e->faces[0]->g;
	del_triangle (e->faces[0]);
    }
// not a bug !!!
    if (e->faces[0])
    {
	g2 = e->faces[0]->g;
	del_triangle (e->faces[0]);
    } 
    del_edge (e);

    BDS_Edge *op1_op2 = new BDS_Edge ( op[0], op[1] );
    edges.insert ( op1_op2 );

    BDS_Point *first_in_0 = 0;
    for (int k=0;k<3;k++)
	if (pts1[k] == p1)
	{
	    if (pts1[(k+1)%3] == op[0])first_in_0 = p1;
	    else first_in_0 = op[0];
	}
    BDS_Point *first_in_1 = 0;
    for (int k=0;k<3;k++)
	if (pts2[k] == p2)
	{
	    if (pts2[(k+1)%3] == op[1])first_in_1 = p2;
	    else first_in_1 = op[1];
	}

    BDS_Triangle*t1 =  new BDS_Triangle ( p1_op1, p1_op2, op1_op2 , first_in_0 );
    BDS_Triangle*t2 =  new BDS_Triangle ( op2_p2, op1_op2, op1_p2 , first_in_1 );
    
    t1->g = g1;
    t2->g = g2;

    op1_op2->g = ge;

    triangles.push_back(t1); 
    triangles.push_back(t2); 
    return true;
}


bool BDS_Mesh ::collapse_edge ( BDS_Edge *e, BDS_Point *p, const BDS_Projector &)
{

}

bool BDS_Mesh ::smooth_point ( BDS_Point *p, const BDS_Projector &)
{
    std::list<BDS_Edge *>::iterator eit  = p->edges.begin(); 	
    std::list<BDS_Edge *>::iterator eite = p->edges.end();
    while (eit!=eite)
    {
	if ((*eit)->g)
	    if((*eit)->g->classif_degree == 1)return false;
	++eit;
    }
    double X = 0;
    double Y = 0;
    double Z = 0;

    eit  = p->edges.begin(); 
    while (eit!=eite)
    {
	BDS_Point *op = ((*eit)->p1 == p)?(*eit)->p2:(*eit)->p1; 	
	X+=op->X;
	Y+=op->Y;
	Z+=op->Z;
	++eit;
    }

    X /= p->edges.size();
    Y /= p->edges.size();
    Z /= p->edges.size();

    std::list<BDS_Triangle *> t; 	
    p->getTriangles (t); 	
    {
	std::list<BDS_Triangle *>::iterator it = t.begin();
	std::list<BDS_Triangle *>::iterator ite = t.end();
	double dist = 1.e22;
	double XX = X,YY=Y,ZZ=Z;
	while (it != ite)
	{ 
	    BDS_Point *pts[3];
	    (*it)->getNodes (pts); 
	    double xp,yp,zp;
	    proj_point_plane ( X,Y,Z,pts[0],pts[1],pts[2],xp,yp,zp);
	    double d = sqrt ((xp-X)*(xp-X)+(yp-Y)*(yp-Y)+(zp-Z)*(zp-Z));
	    if (d < dist)
	    {
		XX = xp; YY = yp; ZZ = zp;
		dist = d;
	    }
	    ++it;
	}
	X = XX;
	Y = YY;
	Z = ZZ;
    }

    p->X = X;
    p->Y = Y;
    p->Z = Z;

    return true;
}

void BDS_Mesh :: adapt_mesh ( double l, const BDS_Projector &proj) 
{
    std::set<BDS_Edge*, EdgeLessThan> small_to_long;
    {
	std::set<BDS_Edge*, EdgeLessThan>::iterator it = edges.begin();
	std::set<BDS_Edge*, EdgeLessThan>::iterator ite  = edges.end();
	while (it != ite)
	{
	    if ((*it)->numfaces()==1)printf("one face\n");
	    small_to_long.insert (*it);  
	    ++it;
	}
    }
    {
	std::set<BDS_Edge*, EdgeLessThan>::iterator it = small_to_long.begin();
	std::set<BDS_Edge*, EdgeLessThan>::iterator ite  = small_to_long.end();
	
	int nbspl = 0;
	
	while (it != ite)
	{
	    BDS_Point *op[2];
	    (*it)->oppositeof (op);
	    double ll = sqrt((op[0]->X-op[1]->X)*(op[0]->X-op[1]->X)+
			     (op[0]->Y-op[1]->Y)*(op[0]->Y-op[1]->Y)+
			     (op[0]->Z-op[1]->Z)*(op[0]->Z-op[1]->Z));
	    if (!(*it)->deleted && (*it)->length() > l && ll > 0.5 * l){
		split_edge (*it, 0.5 ,proj);
		nbspl++;
	    }
	    ++it;
	}
	printf("nbspl = %d\n",nbspl);
    }
//  return;
    cleanup();
    
    {
	small_to_long.clear();
	std::set<BDS_Edge*, EdgeLessThan>::iterator it = edges.begin();
	std::set<BDS_Edge*, EdgeLessThan>::iterator ite  = edges.end();
	while (it != ite)
	{
	    small_to_long.insert (*it);  
	    ++it;
	}
    }
    {    
	std::set<BDS_Edge*, EdgeLessThan>::iterator it = small_to_long.begin();
	std::set<BDS_Edge*, EdgeLessThan>::iterator ite  = small_to_long.end();
	while (it != ite)
	{
	    if (!(*it)->deleted && (*it)->numfaces()==2)
	    {
		BDS_Point *op[2];
		(*it)->oppositeof (op);
		
		double a1 = surface_triangle ( (*it)->p1 , (*it)->p2 , op[0] );
		double a2 = surface_triangle ( (*it)->p1 , (*it)->p2 , op[1] );
		double b1 = surface_triangle ( (*it)->p1 , op[0] , op[1] );
		double b2 = surface_triangle ( (*it)->p2 , op[0] , op[1] );
		
		double cb1[3],cb2[3];
		normal_triangle ( (*it)->p1 , op[0] , op[1],cb1 );
		normal_triangle ( (*it)->p2 , op[0] , op[1],cb2 );
		
		double prosc = cb1[0]*cb2[0]+cb1[1]*cb2[1]+cb1[2]*cb2[2];
		
		if (fabs(a1+a2-b1-b2) < 0.1 * (a1+a2) && prosc < 0 && fabs (prosc) > 0.7)
		{
		    double qa1 = quality_triangle ( (*it)->p1 , (*it)->p2 , op[0] );
		    double qa2 = quality_triangle ( (*it)->p1 , (*it)->p2 , op[1] );
		    double qb1 = quality_triangle ( (*it)->p1 , op[0] , op[1] );
		    double qb2 = quality_triangle ( (*it)->p2 , op[0] , op[1] );
		    
		    double qa = (qa1<qa2)?qa1:qa2; 
		    double qb = (qb1<qb2)?qb1:qb2; 
//		  printf("qa %g qb %g ..\n",qa,qb);
		    if (qb > qa)
		    {
//		      printf("swop ..\n");
			swap_edge ( *it );
		    }
		}
	    }
	    ++it;
	}
    }
    cleanup();  
    {    
	for (int i=0;i<4;++i)
	{
	    std::set<BDS_Point*, PointLessThan>::iterator it   = points.begin();
	    std::set<BDS_Point*, PointLessThan>::iterator ite  = points.end();
	    while (it != ite)
	    {
		smooth_point(*it,proj);
		++it;
	    }
	}
    }
}
