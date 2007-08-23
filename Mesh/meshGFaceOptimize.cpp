#include "meshGFaceOptimize.h"
#include "GFace.h"
#include "GEdge.h"
#include "GVertex.h"
#include "MVertex.h"
#include "MElement.h"
#include <map>
#include <vector>

typedef std::map<MVertex*,std::vector<MTriangle*> > v2t_cont ;

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


void parametricCoordinates ( MTriangle *t , GFace *gf, double u[3], double v[3])
{
  for (unsigned int j=0;j<3;j++)
    {
      MVertex *ver = t->getVertex(j);
      GEntity *ge = ver->onWhat();
      if (ge->dim() == 2)
	{
	  ver->getParameter ( 0,u[j]);
	  ver->getParameter ( 1,v[j]);	  
	}
      else if (ge->dim() == 1)
	{
	  double t;
	  ver->getParameter ( 0,t);
	  GEdge *ged = dynamic_cast<GEdge*> (ge);
	  SPoint2 p = ged->reparamOnFace ( gf , t , 1);
	  u[j] =p.x(); 
	  v[j] =p.y(); 
	}
      else
	{
	  GVertex *gver = dynamic_cast<GVertex*> (ge);
	  SPoint2 p = gver->reparamOnFace ( gf , 1);
	  u[j] =p.x(); 
	  v[j] =p.y(); 
	}      
    }
}

void laplaceSmoothing (GFace *gf)
{
  v2t_cont adj;
  buildVertexToTriangle ( gf ,  adj );

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
    }
  

}


