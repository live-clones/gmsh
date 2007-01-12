// $Id: meshGFaceDelaunayInsertion.cpp,v 1.1 2007-01-12 13:16:59 remacle Exp $
//
// Copyright (C) 1997-2007 C. Geuzaine, J.-F. Remacle
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
// 
// Please report all bugs and problems to <gmsh@geuz.org>.

#include "BDS.h"
#include "BackgroundMesh.h"
#include "meshGFaceDelaunayInsertion.h"
#include "GFace.h"
#include "Numeric.h"
#include "Message.h"
#include <set>
#include <map>
#include <algorithm>

// computes the center of the circum circle in the tangent plane
// the metric given by a b d is supposed to be constant
void MTri3::Center_Circum_Aniso(double a, double b, double d, double &x, double &y, double &r) const
{
  double sys[2][2], X[2];
  double rhs[2];
  double x1, y1, x2, y2, x3, y3;

  x1 = base->getVertex(0)->x();
  y1 = base->getVertex(0)->y();
  x2 = base->getVertex(1)->x();
  y2 = base->getVertex(1)->y();
  x3 = base->getVertex(2)->x();
  y3 = base->getVertex(2)->y();

  sys[0][0] = 2. * a * (x1 - x2) + 2. * b * (y1 - y2);
  sys[0][1] = 2. * d * (y1 - y2) + 2. * b * (x1 - x2);
  sys[1][0] = 2. * a * (x1 - x3) + 2. * b * (y1 - y3);
  sys[1][1] = 2. * d * (y1 - y3) + 2. * b * (x1 - x3);

  rhs[0] =
    a * (x1 * x1 - x2 * x2) + d * (y1 * y1 - y2 * y2) + 2. * b * (x1 * y1 -
                                                                  x2 * y2);
  rhs[1] =
    a * (x1 * x1 - x3 * x3) + d * (y1 * y1 - y3 * y3) + 2. * b * (x1 * y1 -
                                                                  x3 * y3);
  sys2x2(sys, rhs, X);
  
  x = X[0];
  y = X[1];
  
  r = sqrt((X[0] - x1) * (X[0] - x1) * a
	   + (X[1] - y1) * (X[1] - y1) * d
	   + 2. * (X[0] - x1) * (X[1] - y1) * b);
}


// find a common basis for 2 metrics in 2D 
void simultaneousMetricReduction( const gmsh2dMetric &M1,  const gmsh2dMetric &M2,
				  double & l1,double & l2, double V[2][2]) 
{
  double a11=M1.a11,a21=M1.a21,a22=M1.a22;
  double b11=M2.a11,b21=M2.a21,b22=M2.a22;
  const double /*c11 = a11*a11,*/ c21= a21*a21;
  const double /*d11 = b11*b11,*/ d21= b21*b21;
  const double a=b11*b22 - d21;
  const double b=-a11*b22-a22*b11+2*a21*b21;
  const double c=-c21+a11*a22;
  const double bb = b*b,ac= a*c;
  const double delta = bb - 4 * ac;
  if (bb + fabs(ac) < 1.0e-20 || (delta< 1.0E-4 * bb ) )
    {
      if (fabs(a) < 1.e-30 )
	l1 = l2 = 0;
      else 
	l1=l2=-b/(2*a); 
      V[0][0] = 1.;
      V[1][0] = 0.;
      V[0][1] = 0.;
      V[1][1] = 1.;
    }
  else {
    const double delta2 = sqrt(delta);
    l1= (-b - delta2)/(2*a);
    l2= (-b + delta2)/(2*a);
    double v0 = a11-l1*b11, v1 = a21-l1*b21,v2 = a22 - l1*b22;
    double s0 = v0*v0 + v1*v1, s1 = v1*v1 +v2*v2;
    double vp1x,vp1y,vp2x,vp2y;   
    if(s1 < s0)
      s0=sqrt(s0),vp1x=v1/s0,vp1y=-v0/s0;
    else
      s1=sqrt(s1),vp1x=v2/s1,vp1y=-v1/s1;
    
    v0 = a11-l2*b11, v1 = a21-l2*b21,v2 = a22 - l2*b22;
    s0 = v0*v0 + v1*v1, s1 = v1*v1 +v2*v2;
    if(s1 < s0)
      s0=sqrt(s0),vp2x=v1/s0,vp2y=-v0/s0;
    else
      s1=sqrt(s1),vp2x=v2/s1,vp2y=-v1/s1;
      V[0][0] = vp1x;
      V[0][1] = vp2x;
      V[1][0] = vp1y;
      V[1][1] = vp2y;
  }
}

gmsh2dMetric metricIntersection(const gmsh2dMetric &Ma,const gmsh2dMetric &Mb) 
{
  double M[2][2],M1[2][2];
  double l1,l2;
  simultaneousMetricReduction(Ma,Mb,l1,l2,M);
  inv2x2 ( M, M1 );
  const double M1ev1 = Ma.eval(M[0][0],M[0][1]);
  const double M1ev2 = Ma.eval(M[0][0],M[0][1]);
  const double M2ev1 = Mb.eval(M[1][0],M[1][1]);
  const double M2ev2 = Mb.eval(M[1][0],M[1][1]);

  const double D0 = std::max( M1ev1,M1ev2);
  const double D1 = std::max( M2ev1,M2ev2);

  return gmsh2dMetric(M1[0][0] * D0 * M1[0][0] + M1[0][1] * D1 * M1[0][1] ,
		      0.5 * ( M1[0][0] * D0 * M1[1][0] + M1[0][1] * D1 * M1[1][1] +
			      M1[1][0] * D0 * M1[0][0] + M1[1][1] * D1 * M1[0][1] ), 
		      M1[1][0] * D0 * M1[1][0] + M1[1][1] * D1 * M1[1][1] );		            
}

gmsh2dMetric metricInterpolationTriangle(const gmsh2dMetric &M1,
					 const gmsh2dMetric &M2,
					 const gmsh2dMetric &M3, 
					 const double u, 
					 const double v) 
{
  double m1[2][2] = {{M1.a11,0.5*M1.a21},{0.5*M1.a21,M1.a22}};
  double m2[2][2] = {{M2.a11,0.5*M2.a21},{0.5*M2.a21,M2.a22}};
  double m3[2][2] = {{M3.a11,0.5*M3.a21},{0.5*M3.a21,M3.a22}};
  double invm1 [2][2]; inv2x2 ( m1, invm1 );
  double invm2 [2][2]; inv2x2 ( m2, invm2 );
  double invm3 [2][2]; inv2x2 ( m3, invm3 ); 
  double invm [2][2] ;
  for (int i=0;i<2;i++)
    for (int j=0;j<2;j++)
      invm[i][j] = (1.-u-v) * invm1[i][j] + u * invm2[i][j] + v * invm3[i][j];
  double m [2][2]; inv2x2 ( invm, m );
  return gmsh2dMetric ( m[0][0] , m[0][1] , m[1][1] );
}

gmsh2dMetric :: gmsh2dMetric ( double lc )
  : a11 ( 1./(lc*lc) ) ,a21 ( 0.0 ) ,a22 ( 1./(lc*lc) )
{  
}


MTri3::MTri3 ( MTriangle * t, std::vector<gmsh2dMetric> & sizes) : deleted(false), base (t)
{
  neigh[0] = neigh[1] = neigh[2] = 0;
  // compute the metric at the centroid
  metric = metricInterpolationTriangle(sizes [base->getVertex(0)->getNum()] , 
				       sizes [base->getVertex(1)->getNum()] , 
				       sizes [base->getVertex(2)->getNum()] ,
				       1./3., 1./3.); 
  Center_Circum_Aniso(metric.a11,metric.a21,metric.a22, xc, yc, circum_radius);
  //  printf("metric %g %g %g circum_radius = %g\n",metric.a11,metric.a21,metric.a22,circum_radius);
}

int inCircumCircle ( MTri3 *t , const double *p , const gmsh2dMetric &metric ) 
{
  double xc, yc;
  double eps, d1, d2, x[2];
  t->Center_Circum_Aniso(metric.a11,metric.a21,metric.a22,xc, yc, d1);

  x[0] = xc - p[0];
  x[1] = yc - p[1];

  d2 = sqrt(fabs(metric.eval(x[0],x[1])));

  eps = fabs(d1 - d2) / (d1 + d2);
  if(eps < 1.e-12) {
    return 0; 
  }
  if(d2 < d1)
    return 1;
  return 0;

}

int MTri3::inCircumCircle ( const double *p ) const
{

//    double pa[2] = {base->getVertex(0)->x(),base->getVertex(0)->y()};
//    double pb[2] = {base->getVertex(1)->x(),base->getVertex(1)->y()};
//    double pc[2] = {base->getVertex(2)->x(),base->getVertex(2)->y()};
//    double result = gmsh::incircle(pa, pb, pc, (double*)p) * gmsh::orient2d(pa, pb, pc);  
//    return (result > 0) ? 1 : 0;


  double eps, d1, d2, x[2];

  x[0] = xc - p[0];
  x[1] = yc - p[1];

  d1 = circum_radius;
  d2 = sqrt(fabs(metric.eval(x[0],x[1])));

  eps = fabs(d1 - d2) / (d1 + d2);
  if(eps < 1.e-12) {
    return 0; 
  }
  if(d2 < d1)
    return 1;
  return 0;
}

struct edgeXface
{
  MVertex *v[2];
  MTri3 * t1;
  int i1;
  edgeXface ( MTri3 *_t, int iFac)
    : t1(_t),i1(iFac)
  {
    v[0] = t1->tri()->getVertex ( iFac == 0 ? 2 : iFac-1 );
    v[1] = t1->tri()->getVertex ( iFac );
    std::sort ( v, v+2 );
  }
  inline bool operator < ( const edgeXface & other) const
  {
    if (v[0] < other.v[0])return true;
    if (v[0] > other.v[0])return false;
    if (v[1] < other.v[1])return true;
    return false;
  }
};

template <class ITER>
void connectTris ( ITER beg, ITER end)
{
  std::set<edgeXface> conn;
  {
    while (beg != end)
      {
	if (!(*beg)->isDeleted())
	  {
	    for (int i=0;i<3;i++)
	      {
		edgeXface fxt ( *beg ,  i );
		std::set<edgeXface>::iterator found = conn.find (fxt);
		if (found == conn.end())
		  conn.insert ( fxt );
		else if (found->t1 != *beg)
		  {
		    found->t1->setNeigh(found->i1,*beg);
		    (*beg)->setNeigh ( i, found->t1);
		  }
	      }
	  }
	++beg;
      }
  }
}


void recurFindCavity (const gmsh2dMetric &metric, 
		      std::list<edgeXface> & shell, 
		      std::list<MTri3*> & cavity, 
		      double *v, 
		      MTri3 *t)
{
  t->setDeleted(true);
  // the cavity that has to be removed
  // because it violates delaunay criterion
  cavity.push_back(t);

  for (int i=0;i<3;i++)
    {
      MTri3 *neigh =  t->getNeigh(i) ;
      if (!neigh)
	  shell.push_back ( edgeXface ( t, i ) );
      else  if (!neigh->isDeleted())
	{
	  int circ =  inCircumCircle ( neigh, v, metric );
	  if (circ)
	    recurFindCavity ( metric,shell, cavity,v , neigh);
	  else
	    shell.push_back ( edgeXface ( t, i ) );
	}
    }
}

bool insertVertex (MVertex *v , 
		   MTri3   *t ,
		   std::set<MTri3*,compareTri3Ptr> &allTets,
		   std::vector<gmsh2dMetric> & vSizes,
		   const gmsh2dMetric &metric)
{
  std::list<edgeXface>  shell;
  std::list<MTri3*>  cavity; 
  std::list<MTri3*>  new_cavity;

  double p[2] = {v->x(),v->y()};

  recurFindCavity ( metric,shell,  cavity, p , t);  

  // check that volume is conserved
  double newVolume = 0;
  double oldVolume = 0;

  std::list<MTri3*>::iterator ittet = cavity.begin();
  std::list<MTri3*>::iterator ittete = cavity.end();
  while ( ittet != ittete )
    {
      oldVolume += fabs((*ittet)->getSurfaceXY());
      ++ittet;
    }

//    char name[245];
//    int III = 1;
//    sprintf(name,"test%d.pos",III);
//    FILE *ff = fopen (name,"w");
//    fprintf(ff,"View\"test\"{\n");


  MTri3** newTris = new MTri3*[shell.size()];;
  int k = 0;
  std::list<edgeXface>::iterator it =   shell.begin();

  while (it != shell.end())
    {
      MTriangle *t = new MTriangle ( it->v[0],
				     it->v[1],
				     v);
      MTri3 *t4 = new MTri3 ( t , vSizes); 
//       fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0};\n",
// 	      it->v[0]->x(),
// 	      it->v[0]->y(),
// 	      it->v[0]->z(),
// 	      it->v[1]->x(),
// 	      it->v[1]->y(),
// 	      it->v[1]->z(),
// 	      v->x(),
// 	      v->y(),
// 	      v->z());
      newTris[k++]=t4;
      // all new triangles are pushed front in order to
      // ba able to destroy them if the cavity is not
      // star shaped around the new vertex.
      new_cavity.push_back (t4);
      MTri3 *otherSide = it->t1->getNeigh(it->i1);

      if (otherSide)
      	new_cavity.push_back (otherSide);
      //      if (!it->t1->isDeleted())throw;
      double ss = fabs(t4->getSurfaceXY());
      if (ss < 1.e-12)ss = 1256172121;
      newVolume += ss;
      ++it;
    }
//    fprintf(ff,"};\n");
//    fclose (ff);
//   printf("%d %d newVolume %g oldVolume %g\n",cavity.size(),new_cavity.size(),newVolume,oldVolume);
//    getchar();


  if (fabs(oldVolume - newVolume) < 1.e-10 * oldVolume )
    {      
      connectTris ( new_cavity.begin(),new_cavity.end() );      
      allTets.insert(newTris,newTris+shell.size());
      delete [] newTris;
      return true;
    }
  // The cavity is NOT star shaped
  else
    {      
      for (unsigned int i=0;i<shell.size();i++)delete newTris[i];
      delete [] newTris;      
      ittet = cavity.begin();
      ittete = cavity.end();  
      while ( ittet != ittete )
	{
	  (*ittet)->setDeleted(false);
	  ++ittet;
	}
      return false;
    }
}

static gmsh2dMetric evalMetricTensor ( GFace *gf , MVertex *mv , double lc )
{
  Pair<SVector3,SVector3> der = gf->firstDer(SPoint2(mv->x(),mv->y())) ;
  const double oneoverlc2 = 1./(lc*lc);
  const double a11 = dot(der.first() ,der.first() ) * oneoverlc2; 
  const double a21 = dot(der.second(),der.first() ) * oneoverlc2; 
  const double a22 = dot(der.second(),der.second()) * oneoverlc2; 

  //  printf("metric : %g %g %g - %g %g\n",a11,a21,a22,oneoverlc2,lc);

  return gmsh2dMetric ( a11, a21 , a22);
}

static void setLcs ( MTriangle *t, std::map<MVertex*,double> &vSizes)
{
  for (int i=0;i<3;i++)
    {
      for (int j=i+1;j<3;j++)
	{
	  MVertex *vi = t->getVertex(i);
	  MVertex *vj = t->getVertex(j);
	  double dx = vi->x()-vj->x();
	  double dy = vi->y()-vj->y();
	  double dz = vi->z()-vj->z();
	  double l = sqrt(dx*dx+dy*dy+dz*dz);
	  std::map<MVertex*,double>::iterator iti = vSizes.find(vi);	  
	  std::map<MVertex*,double>::iterator itj = vSizes.find(vj);	  
	  if (iti==vSizes.end() || iti->second > l)vSizes[vi] = l;
	  if (itj==vSizes.end() || itj->second > l)vSizes[vj] = l;
	}
    }
}

void insertVerticesInFace (GFace *gf, BDS_Mesh *bds)
{

  std::set<MTri3*,compareTri3Ptr> AllTris;
  std::map<MVertex*,double> vSizesMap;
  std::map<const BDS_Point*,MVertex*> recoverMap;
  std::vector<gmsh2dMetric> vMetrics;
  std::vector<double> vSizes;


  // compute edge sizes on the contour and propagate thos sizes inside the surface
  for (unsigned int i=0;i<gf->triangles.size();i++)setLcs ( gf->triangles[i] , vSizesMap);

  // set vertex positions to local coordinates of the face  
  // compute metric tensors of the surface
  int NUM=0;
  for (std::map<MVertex*,double>::iterator it = vSizesMap.begin();it!=vSizesMap.end();++it)
    {
      BDS_Point *p;
      p = bds->find_point(it->first->getNum());
      it->first->x() = p->u;
      it->first->y() = p->v;
      it->first->z() = 0;
      it->first->setNum(NUM++);      
      vSizes.push_back(it->second);
      recoverMap[p]= (it->first);
      vMetrics.push_back(evalMetricTensor ( gf , it->first, it->second));
    }
  
  for (unsigned int i=0;i<gf->triangles.size();i++)
    AllTris.insert ( new MTri3 ( gf->triangles[i] ,vMetrics ) );

  gf->triangles.clear();
  connectTris ( AllTris.begin(), AllTris.end() );      
  
  Msg(DEBUG,"All %d tris were connected",AllTris.size());

  // here the classification should be done

  int ITER = 0;

  while (1)
    {
      MTri3 *worst = *AllTris.begin();

      if (worst->isDeleted())
	{
	  delete worst->tri();
	  delete worst;
	  AllTris.erase(AllTris.begin());
	  //	  Msg(INFO,"Worst tet is deleted");
	}
      else
	{
	  if(ITER++%5000 ==0)
	    Msg(DEBUG,"%7d points created -- Worst tri radius is %8.3f",vSizes.size(),worst->getRadius());
	  if (worst->getRadius() < 0.5 * sqrt(2.0)) break;
	  double center[2],uv[2];
	  worst->getCenter(center);
	  //	  worst->tri()->circumcenterXY(center);
	  bool inside = worst->tri()->invertmappingXY(center,uv);
	  if (inside || 1)
	    {
	      // we use here local coordinates as real coordinates
	      // x,y and z will be computed hereafter
	      //	      Msg(INFO,"Point is inside");
	      MVertex *v = new MFaceVertex (center[0],center[1],0.0,gf,center[0],center[1]);
	      v->setNum(NUM++);
	      double lc1 = (1.-uv[0]-uv[1]) * vSizes [worst->tri()->getVertex(0)->getNum()] + 
		uv[0] * vSizes [worst->tri()->getVertex(1)->getNum()] + 
		uv[1] * vSizes [worst->tri()->getVertex(2)->getNum()] ; 
	      GPoint p = gf->point (center[0],center[1]);
	      double lc = std::min(lc1,BGM_MeshSize(gf,center[0],center[1],p.x(),p.y(),p.z()));
	      vSizes.push_back(lc);
	      gmsh2dMetric metr = evalMetricTensor ( gf , v, lc); 
	      vMetrics.push_back(metr);
	      
	      // compute mesh spacing there
	      if (!insertVertex ( v  , worst, AllTris,vMetrics,metr))
		{
		  AllTris.erase(AllTris.begin());
		  worst->forceRadius(0);
		  AllTris.insert(worst);		  
		  delete v;
		}
	      else 
		{
		  gf->mesh_vertices.push_back(v);
		}
	    }
 	  else
 	    {
 	      //	      Msg(INFO,"Point is outside");
 	      AllTris.erase(AllTris.begin());
 	      worst->forceRadius(0);
 	      AllTris.insert(worst);		  
	    }
	}
    }

  // restore real coordinates of vertices
  if (1){
    std::map<const BDS_Point*,MVertex*>::const_iterator itx =  recoverMap.begin();
    while (itx != recoverMap.end())
      {
	MVertex *v = (itx->second);
	const BDS_Point *p = (itx->first);
	v->x() = p->X;
	v->y() = p->Y;
	v->z() = p->Z;
	++itx;
      }
    for (unsigned int i=0;i<gf->mesh_vertices.size();i++)
      {
	double u = gf->mesh_vertices[i]->x();
	double v = gf->mesh_vertices[i]->y();
	GPoint p = gf->point(u,v);
	gf->mesh_vertices[i]->x() = p.x();
	gf->mesh_vertices[i]->y() = p.y();
	gf->mesh_vertices[i]->z() = p.z();
      }
  }

  // fill new gmsh structures with triangles
  while (1)
    {
      if (AllTris.begin() == AllTris.end() ) break;
      MTri3 *worst = *AllTris.begin();
      if (worst->isDeleted())
	{
	  delete worst->tri();
	}
      else
	{
	  gf->triangles.push_back(worst->tri());
	}
      delete worst;
      AllTris.erase(AllTris.begin());      
    }
}
