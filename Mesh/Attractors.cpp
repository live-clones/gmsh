#include "Attractors.h"
#include "GeoInterpolation.h"
#define maxpts  1

std::list <Attractor *>  Attractor::allAttractors;  

void Attractor::addPoint ( double X, double Y, double Z)
{
  attractorPoints.push_back(SPoint3(X,Y,Z));
}


Attractor::~Attractor ()
{
#ifdef HAVE_ANN_
  if (kdtree) delete kdtree;
  if (zeronodes) annDeallocPts(zeronodes);
  delete [] index;
  delete [] dist;
#endif
}

Attractor::Attractor ()
#ifdef HAVE_ANN_
  : kdtree (0) , zeronodes(0)
#endif
{
#ifdef HAVE_ANN_
  index   = new ANNidx[maxpts];
  dist   = new ANNdist[maxpts];
#endif
}

void Attractor::reset () 
{  
  for (std::list <Attractor *>::iterator it = allAttractors.begin();it !=allAttractors.end();++it)
    delete *it;
  allAttractors.clear();
}

void Attractor :: buildFastSearchStructures() 
{
#ifdef HAVE_ANN_
  if (zeronodes)
    {
      annDeallocPts(zeronodes);
      delete kdtree;
    }
  int totpoints = 0;
  for (std::list <Attractor *>::iterator it = allAttractors.begin();it !=allAttractors.end();++it)
    totpoints += (*it)->attractorPoints.size();
  if (totpoints)
    zeronodes = annAllocPts(totpoints, 3);
  int k = 0;
  for (std::list <Attractor *>::iterator it = allAttractors.begin();it !=allAttractors.end();++it)
    {
      for (std::list <SPoint3>::iterator it2 = (*it)->attractorPoints.begin();it2 !=(*it)->attractorPoints.end();++it2)
	{
	  zeronodes[k][0]=it2->x();
	  zeronodes[k][1]=it2->y();
	  zeronodes[k++][2]=it2->z();
	}
    }
  kdtree = new ANNkd_tree(zeronodes, totpoints, 3);
#endif
}

double Attractor::lc ( double X, double Y, double Z) 
{
  if (!allAttractors.size())return 1.e22;
  double xyz[3] = {X,Y,Z};

  double minLc = 1.e22;

  for (std::list <Attractor *>::iterator it = allAttractors.begin();it !=allAttractors.end();++it)
    {
      if ((*it)->attractorPoints.size() == 1)
	{
	  SPoint3 p = *((*it)->attractorPoints.begin());
	  double dist = sqrt((p.x()-X)*(p.x()-X)+(p.y()-Y)*(p.y()-Y)+(p.z()-Z)*(p.z()-Z));
	  Attractor *a = (*it);
	  minLc = std::min((*a)(dist),minLc);	  
	}
      else{
#ifdef HAVE_ANN_
	(*it)->kdtree->annkSearch(xyz, maxpts, (*it)->index,(*it)->dist);
	double distHere = sqrt((*it)->dist[0]);
	Attractor *a = (*it);
	minLc = std::min((*a)(distHere),minLc);
#else
	Msg(GERROR,"GMSH should be compiled with ANN in order to enable attractors !");
#endif
      }
    }
  return minLc;  
}
void buildListOfPoints ( Attractor * a, Curve *c, int N)
{
  for (int i=0;i<N;i++)
    {
      double u = (double)i/(N-1);
      Vertex V = InterpolateCurve (c,u,0);
      a->addPoint(V.Pos.X,V.Pos.Y,V.Pos.Z);
    }
}
void buildListOfPoints ( Attractor * a, GEdge *c, int N)
{
  for (int i=0;i<N;i++)
    {
      double u = (double)i/(N-1);
      Range<double> b = c->parBounds(0);
      double t = b.low() + u*(b.high()-b.low());
      GPoint gp = c->point(t);
      a->addPoint(gp.x(),gp.y(),gp.z());
    }
}
double tresholdAttractor::operator () ( const double & distance ) 
{
  double l ;
  if (distance>  factor * treshold) l = meshSizeOut;
  else if (distance > treshold) {
    const double t = (factor/(factor- 1.)) * (1. - treshold/distance);
    l =  1./((1./meshSizeIn) * (1.-t) + (1./meshSizeOut) * t);
  }  
  else l =  meshSizeIn;

  //  printf ("f(%g) = %g (%g %g %g %g)\n",distance,l,treshold, factor,meshSizeIn,meshSizeOut);

  return l;

}
