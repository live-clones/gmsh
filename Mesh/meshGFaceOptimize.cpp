#include "meshGFaceOptimize.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "MVertex.h"
#include "MElement.h"

typedef std::map<MVertex*,std::vector<MTriangle*> > v2t_cont ;
typedef std::map<MEdge, std::pair<MTriangle*,MTriangle*> , Less_Edge>     e2t_cont ;

void buildVertexToTriangle ( GFace *gf ,  v2t_cont &adj )
{
  adj.clear();
  for (unsigned int i=0;i<gf->triangles.size();i++)
    {
      MTriangle *t = gf->triangles[i];
      for (unsigned int j=0;j<3;j++)
	{
	  MVertex *v = t->getVertex(j);
	  v2t_cont :: iterator it = adj.find ( v );      
	  if (it == adj.end())
	    {
	      std::vector<MTriangle*> one;
	      one.push_back(t);
	      adj[v] = one;
	    }
	  else
	    {
	      it->second.push_back(t);
	    }
	}
    }
}


void buildEdgeToTriangle ( GFace *gf ,  e2t_cont &adj )
{
  buildEdgeToTriangle(gf->triangles,adj);
}

void buildEdgeToTriangle ( std::vector<MTriangle*> &triangles ,  e2t_cont &adj )
{
  adj.clear();
  for (unsigned int i=0;i<triangles.size();i++)
    {
      MTriangle *t = triangles[i];
      for (unsigned int j=0;j<3;j++)
	{
	  MVertex *v1 = t->getVertex(j);
	  MVertex *v2 = t->getVertex((j+1)%3);
	  MEdge e(v1,v2);
	  e2t_cont :: iterator it = adj.find ( e );      
	  if (it == adj.end())
	    {
	      std::pair<MTriangle*,MTriangle*> one = std::make_pair (t,(MTriangle*)0);
	      adj[e] = one;
	    }
	  else
	    {
	      it->second.second = t;
	    }
	}
    }
}


void parametricCoordinates ( MTriangle *t , GFace *gf, double u[3], double v[3])
{
  for (unsigned int j=0;j<3;j++)
    {
      MVertex *ver = t->getVertex(j);
      parametricCoordinates ( ver , gf, u[j],  v[j]);
    }
}

void laplaceSmoothing (GFace *gf)
{
  v2t_cont adj;
  buildVertexToTriangle ( gf ,  adj );

   for (int i=0;i<5;i++)
    {
      v2t_cont :: iterator it = adj.begin();
      
      while (it != adj.end())
	{
	  MVertex *ver= it->first;
	  GEntity *ge = ver->onWhat();
	  // this vertex in internal to the face
	  if (ge->dim() == 2)
	    {
	      double initu,initv;
	      ver->getParameter ( 0,initu);
	      ver->getParameter ( 1,initv);
	      
	      const std::vector<MTriangle*> & lt = it->second;
	      
	      double fact = lt.size() ? 1./(3.*lt.size()):0;
	      
	      double cu=0,cv=0;
	      double pu[3],pv[3];
	      for (unsigned int i=0;i<lt.size();i++)
		{
		  parametricCoordinates ( lt[i] , gf, pu, pv);
		  cu += fact*(pu[0]+pu[1]+pu[2]);
		  cv += fact*(pv[0]+pv[1]+pv[2]);
		  // have to test validity !
		}
	      ver->setParameter(0,cu);
	      ver->setParameter(1,cv);
	      GPoint pt = gf->point(SPoint2(cu,cv));
	      ver->x() = pt.x();
	      ver->y() = pt.y();
	      ver->z() = pt.z();
	    }
	  ++it;
	}  
    }
}

extern void fourthPoint (double *p1, double *p2, double *p3, double *p4);

bool edgeSwap(e2t_cont &adj, e2t_cont::iterator &it, GFace *gf)
{  
  MVertex *v1 = it->first.getVertex(0);
  MVertex *v2 = it->first.getVertex(1);
  MVertex *o1,*o2 ;
  MTriangle *t1 = it->second.first;
  MTriangle *t2 = it->second.second;
  for (int i=0;i<3;i++)
    {
      if (t1->getVertex(i) != v1 &&
	  t1->getVertex(i) != v2)o1 = t1->getVertex(i);
      if (t2->getVertex(i) != v1 &&
	  t2->getVertex(i) != v2)o1 = t2->getVertex(i);
    }
  
}



bool edgeSwapTestDelaunay(e2t_cont::iterator &it,GFace *gf)
{  
  if(!it->second.second) return false;

  MVertex *v1 = it->first.getVertex(0);
  MVertex *v2 = it->first.getVertex(1);
  MVertex *o1,*o2 ;
  for (int i=0;i<3;i++)
    {
      if (it->second.first->getVertex(i) != v1 &&
	  it->second.first->getVertex(i) != v2)o1 = it->second.first->getVertex(i);
      if (it->second.second->getVertex(i) != v1 &&
	  it->second.second->getVertex(i) != v2)o2 = it->second.second->getVertex(i);
    }
  double p1[2];
  double p2[2];
  double op1[2];
  double op2[2];
  parametricCoordinates ( v1,gf,p1[0],p1[1] );
  parametricCoordinates ( v2,gf,p2[0],p2[1] );
  parametricCoordinates ( o1,gf,op1[0],op1[1] );
  parametricCoordinates ( o2,gf,op2[0],op2[1] );
  
  double ori_t1 = gmsh::orient2d(op1, p1, op2);
  double ori_t2 = gmsh::orient2d(op1,op2, p2);


  // the quad is concave in parametric coord, return false
  if ( ori_t1 * ori_t2 <= 0) return false;

  double p1x[3] =  {v1->x(),v1->y(),v1->z()};
  double p2x[3] =  {v2->x(),v2->y(),v2->z()};
  double op1x[3] =  {o1->x(),o1->y(),o1->z()};
  double op2x[3] =  {o2->x(),o2->y(),o2->z()};
  double fourth[3];
  fourthPoint(p1x,p2x,op1x,fourth);
  double result = gmsh::insphere(p1x, p2x, op1x, fourth, op2x) * gmsh::orient3d(p1x, p2x, op1x, fourth);  
  return result > 0.;
}

void edgeSwappingLawson (GFace *gf)
{

  e2t_cont adj;
  buildEdgeToTriangle ( gf ,  adj );

  e2t_cont :: iterator it = adj.begin();
  
  while (it != adj.end())
    {      
      bool evalSwapLawson = edgeSwapTestDelaunay(it,gf);
      if ( evalSwapLawson )
	{
	  edgeSwap  (adj, it ,gf );
	  e2t_cont :: iterator itb = it;
	  ++it;
	  adj.erase(itb);
	}
      else
	++it;
    }  
}

