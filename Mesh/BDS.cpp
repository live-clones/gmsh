#include "BDS.h"
#include <math.h>

void BDS_Mesh :: add_point (int num , double x, double y,double z)
{
    points.insert ( BDS_Point ( num, x, y, z) );
}

BDS_Point *BDS_Mesh :: find_point  (int p)
{
    BDS_Point P ( p ) ;
    std::set<BDS_Point>::iterator it = points.find(P);
    if (it != points.end()) return (BDS_Point*) & (*it);
    else return 0;
}

BDS_Edge *BDS_Mesh :: find_edge  (int num1, int num2)
{
    BDS_Point P1 ( num1 ) ;
    BDS_Point P2 ( num2 ) ;
    BDS_Edge  E (&P1, &P2);
    std::set<BDS_Edge>::iterator it = edges.find(E);
    if (it != edges.end()) return (BDS_Edge*) & (*it);
    else return 0;
}

void BDS_Mesh :: add_edge  (int p1, int p2)
{
    BDS_Edge *efound = find_edge (p1,p2);
    if (efound)return;

    BDS_Point *pp1=find_point(p1);
    BDS_Point *pp2=find_point(p2);
    if (!pp1 || !pp2)throw;
    edges.insert ( BDS_Edge ( pp1, pp2 ) );    
}

void BDS_Mesh :: add_triangle  (int p1, int p2, int p3, double nx, double ny, double nz)
{
    add_edge (p1,p2);
    add_edge (p2,p3);
    add_edge (p3,p1);
    BDS_Edge *e1 = find_edge (p1,p2); 
    BDS_Edge *e2 = find_edge (p2,p3); 
    BDS_Edge *e3 = find_edge (p3,p1); 
    triangles.insert ( BDS_Triangle ( e1, e2, e3 ,nx,ny,nz) );        
}

void BDS_Mesh :: add_geom  (int p1, int p2)
{
    geom.insert ( BDS_GeomEntity ( p1,p2 ) ) ;        
}
BDS_GeomEntity * BDS_Mesh :: get_geom  (int p1, int p2)
{
  std::set<BDS_GeomEntity>::iterator it = geom.find(BDS_GeomEntity ( p1,p2 ));
  if (it == geom.end())return 0;
  return (BDS_GeomEntity*) & (*it);
}

void BDS_Mesh :: save_gmsh_format ( const char *filename )
{
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

void BDS_Mesh :: classify ( double angle )
{
    BDS_GeomEntity EDGE_CLAS (1,0);
    std::set<BDS_Edge>::iterator it  = edges.begin();
    std::set<BDS_Edge>::iterator ite = edges.end();
    while (it!=ite)
    {
	BDS_Edge &e = (BDS_Edge &) *it;
	if ( e.numfaces() == 1) e.g = &EDGE_CLAS;
	else if (e.numfaces() == 2)
	  {
	    double a[3] = { e.faces[0]->NX ,  e.faces[0]->NY ,  e.faces[0]->NZ };
	    double b[3] = { e.faces[1]->NX ,  e.faces[1]->NY ,  e.faces[1]->NZ };
	    double c[3];
	    c[2] = a[0] * b[1] - a[1] * b[0];
	    c[1] = -a[0] * b[2] + a[2] * b[0];
	    c[0] = a[1] * b[2] - a[2] * b[1];
	    double cosa = a[0]*b[0] +a[1]*b[1] +a[2]*b[2];
	    double sina = sqrt (c[0]*c[0] + c[1]*c[1] + c[2]*c[2]);
	    double ag = atan2(sina,cosa);
	    if (fabs(ag) > angle)e.g = &EDGE_CLAS;
	  }
	++it;
    }
    {
      int tag = 1;
      while (1)
	{
	  std::set<BDS_Triangle>::iterator it  = triangles.begin();
	  std::set<BDS_Triangle>::iterator ite = triangles.end();
	  BDS_Triangle *start = 0;
	  while (it!=ite)
	    {
	      if (!it->g)
		{
		  start = (BDS_Triangle*)& (*it);
		}
	      ++it;
	    }
	  if (!start)break;	  
	  add_geom (tag, 2);
	  BDS_GeomEntity *g = get_geom (tag,2);
	  recur_tag ( start , g );
	  tag++;
	}
    }

}
