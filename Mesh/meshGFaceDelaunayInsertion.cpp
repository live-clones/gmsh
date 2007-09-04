// $Id: meshGFaceDelaunayInsertion.cpp,v 1.3 2007-09-04 13:47:02 remacle Exp $
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
#include "meshGFace.h"
#include "GFace.h"
#include "Numeric.h"
#include "Message.h"
#include <set>
#include <map>
#include <algorithm>

int III = 1;

// computes the center of the circum circle in the tangent plane
// the metric given by a b d is supposed to be constant
void MTri3::Center_Circum_Aniso(double a, double b, double d, double &x, double &y, double &r) const
{
  throw;
}


// find a common basis for 2 metrics in 2D 
void simultaneousMetricReduction( const gmsh2dMetric &M1,  const gmsh2dMetric &M2,
				  double & l1,double & l2, double V[2][2]) 
{
  throw;
}

gmsh2dMetric metricIntersection(const gmsh2dMetric &Ma,const gmsh2dMetric &Mb) 
{
  throw;
}

gmsh2dMetric metricInterpolationTriangle(const gmsh2dMetric &M1,
					 const gmsh2dMetric &M2,
					 const gmsh2dMetric &M3, 
					 const double u, 
					 const double v) 
{
  throw;
}

gmsh2dMetric :: gmsh2dMetric ( double lc )
  : a11 ( 1./(lc*lc) ) ,a21 ( 0.0 ) ,a22 ( 1./(lc*lc) )
{  
  throw;
}


MTri3::MTri3 ( MTriangle * t, double lc) : deleted(false), base (t)
{
  neigh[0] = neigh[1] = neigh[2] = 0;

  // compute the circumradius of the triangle
  double pa[3] = {base->getVertex(0)->x(),base->getVertex(0)->y(),base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(),base->getVertex(1)->y(),base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(),base->getVertex(2)->y(),base->getVertex(2)->z()};
  double center[3];
  base->circumcenterXYZ(pa,pb,pc,center);
  const double dx = base->getVertex(0)->x() - center[0];
  const double dy = base->getVertex(0)->y() - center[1];
  const double dz = base->getVertex(0)->z() - center[2];
  
  circum_radius = sqrt ( dx*dx + dy*dy + dz*dz);
  circum_radius /= lc;
}


int MTri3::inCircumCircle ( const double *p ) const
{
  double pa[3] = {base->getVertex(0)->x(),base->getVertex(0)->y(),base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(),base->getVertex(1)->y(),base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(),base->getVertex(2)->y(),base->getVertex(2)->z()};
  double fourth[3];
  fourthPoint ( pa,pb,pc,fourth);

  double result = gmsh::insphere(pa, pb, pc, fourth, (double*)p) * gmsh::orient3d(pa, pb, pc,fourth);  
  return (result > 0) ? 1 : 0;  
}


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

void connectTriangles ( std::list<MTri3*> & l)
{
  connectTris(l.begin(),l.end());
}

void recurFindCavity (std::list<edgeXface> & shell, 
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
	  int circ =  neigh->inCircumCircle ( v );
	  if (circ)
	    recurFindCavity ( shell, cavity,v , neigh);
	  else
	    shell.push_back ( edgeXface ( t, i ) );
	}
    }
}

bool circUV ( MTriangle   *t , 
	      std::vector<double> & Us,
	      std::vector<double> & Vs , double *res)
{
  double p1 [2] = {Us[t->getVertex(0)->getNum()],Vs[t->getVertex(0)->getNum()]};
  double p2 [2] = {Us[t->getVertex(1)->getNum()],Vs[t->getVertex(1)->getNum()]};
  double p3 [2] = {Us[t->getVertex(2)->getNum()],Vs[t->getVertex(2)->getNum()]};
  t->circumcenterXY ( p1, p2 , p3, res);
}

bool invMapUV ( MTriangle   *t , 
		double *p,
		std::vector<double> & Us,
		std::vector<double> & Vs , double *uv, double tol)
{
  double mat[2][2];
  double b[2];

  double u0 = Us[t->getVertex(0)->getNum()];
  double v0 = Vs[t->getVertex(0)->getNum()];
  double u1 = Us[t->getVertex(1)->getNum()];
  double v1 = Vs[t->getVertex(1)->getNum()];
  double u2 = Us[t->getVertex(2)->getNum()];
  double v2 = Vs[t->getVertex(2)->getNum()];

  mat[0][0] = u1 - u0;
  mat[0][1] = u2 - u0;
  mat[1][0] = v1 - v0;
  mat[1][1] = v2 - v0;

  b[0] = p[0] - u0;
  b[1] = p[1] - v0;
  sys2x2(mat, b, uv);

  if(uv[0] >= -tol && 
     uv[1] >= -tol && 
     uv[0] <= 1. + tol && 
     uv[1] <= 1. + tol && 
     1. - uv[0] - uv[1] > -tol) {
    return true;
  }
  return false; 
}


double getSurfUV ( MTriangle   *t , 
		 std::vector<double> & Us,
		 std::vector<double> & Vs )
{
  double u1 = Us[t->getVertex(0)->getNum()];
  double v1 = Vs[t->getVertex(0)->getNum()];
  double u2 = Us[t->getVertex(1)->getNum()];
  double v2 = Vs[t->getVertex(1)->getNum()];
  double u3 = Us[t->getVertex(2)->getNum()];
  double v3 = Vs[t->getVertex(2)->getNum()];
  const double vv1 [2] = {u2 - u1, v2 - v1};
  const double vv2 [2] = {u3 - u1, v3 - v1};
  double s = vv1[0] * vv2[1] - vv1[1] * vv2[0]; 
  return s * 0.5;

}

bool insertVertex (MVertex *v , 
		   MTri3   *t ,
		   std::set<MTri3*,compareTri3Ptr> &allTets,
		   std::vector<double> & vSizes,
		   std::vector<double> & vSizesBGM,
		   std::vector<double> & Us,
		   std::vector<double> & Vs)
{
  std::list<edgeXface>  shell;
  std::list<MTri3*>  cavity; 
  std::list<MTri3*>  new_cavity;

  double p[3] = {v->x(),v->y(),v->z()};

  recurFindCavity ( shell,  cavity, p , t);  

  // check that volume is conserved
  double newVolume = 0;
  double oldVolume = 0;


  std::list<MTri3*>::iterator ittet = cavity.begin();
  std::list<MTri3*>::iterator ittete = cavity.end();
  while ( ittet != ittete )
    {
      oldVolume += fabs(getSurfUV((*ittet)->tri(),Us,Vs));
      ++ittet;
    }

//   fprintf(ff,"};\n");
//   fclose (ff);
//   sprintf(name,"test%d.pos",III++);
//   ff = fopen (name,"w");
//   fprintf(ff,"View\"test\"{\n");


  MTri3** newTris = new MTri3*[shell.size()];;
  int k = 0;
  std::list<edgeXface>::iterator it =   shell.begin();

  while (it != shell.end())
    {
      MTriangle *t = new MTriangle ( it->v[0],
				     it->v[1],
				     v);

      double lc    = 0.3333333333*(vSizes [t->getVertex(0)->getNum()]+
				   vSizes [t->getVertex(1)->getNum()]+
				   vSizes [t->getVertex(2)->getNum()]);
      double lcBGM = 0.3333333333*(vSizesBGM [t->getVertex(0)->getNum()]+
				   vSizesBGM [t->getVertex(1)->getNum()]+
				   vSizesBGM [t->getVertex(2)->getNum()]);
      
      MTri3 *t4 = new MTri3 ( t , std::min(lc,lcBGM)); 
//        fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0};\n",
// 	       Us [t->getVertex(0)->getNum()],
// 	       Vs [t->getVertex(0)->getNum()],
// 	       0.0,
// 	       Us [t->getVertex(1)->getNum()],
// 	       Vs [t->getVertex(1)->getNum()],
// 	       0.0,
// 	       Us [t->getVertex(2)->getNum()],
// 	       Vs [t->getVertex(2)->getNum()],
// 	       0.0);
      newTris[k++]=t4;
      // all new triangles are pushed front in order to
      // ba able to destroy them if the cavity is not
      // star shaped around the new vertex.
      new_cavity.push_back (t4);
      MTri3 *otherSide = it->t1->getNeigh(it->i1);

      if (otherSide)
      	new_cavity.push_back (otherSide);
      //      if (!it->t1->isDeleted())throw;
      double ss = fabs(getSurfUV(t4->tri(),Us,Vs));
      if (ss < 1.e-12)ss = 1256172121;
      newVolume += ss;
      ++it;
    }
//     fprintf(ff,"};\n");
//     fclose (ff);
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
      printf("the cavity (%d members) is not star shaped %g vs %g\n",shell.size(),oldVolume,newVolume);

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

static void setLcsMax ( MTriangle *t, std::map<MVertex*,double> &vSizes)
{
  for (int i=0;i<3;i++)
    {
      for (int j=i+1;j<3;j++)
	{
	  MVertex *vi = t->getVertex(i);
	  MVertex *vj = t->getVertex(j);
	  vSizes[vi] = 1.e12;
	  vSizes[vj] = 1.e12;
	}
    }
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
	  if (iti->second > l)iti->second = l;
	  if (itj->second > l)itj->second = l;
	}
    }
}

void insertVerticesInFace (GFace *gf, BDS_Mesh *bds)
{

  std::set<MTri3*,compareTri3Ptr> AllTris;
  std::map<MVertex*,double> vSizesMap;
  std::vector<double> vSizes, vSizesBGM,Us,Vs;

  for (unsigned int i=0;i<gf->triangles.size();i++)setLcsMax ( gf->triangles[i] , vSizesMap);

  // compute edge sizes on the contour and propagate thos sizes inside the surface
  for (unsigned int i=0;i<gf->triangles.size();i++)setLcs ( gf->triangles[i] , vSizesMap);

  int NUM=0;
  for (std::map<MVertex*,double>::iterator it = vSizesMap.begin();it!=vSizesMap.end();++it)
    {
      it->first->setNum(NUM++);      
      vSizes.push_back(it->second); 
      vSizesBGM.push_back(it->second); 
      double u0,v0;
      parametricCoordinates ( it->first, gf, u0, v0);
      Us.push_back(u0);
      Vs.push_back(v0);
    }
  for (unsigned int i=0;i<gf->triangles.size();i++)
    {
      double lc    = 0.3333333333*(vSizes [gf->triangles[i]->getVertex(0)->getNum()]+
				   vSizes [gf->triangles[i]->getVertex(1)->getNum()]+
				   vSizes [gf->triangles[i]->getVertex(2)->getNum()]);
      AllTris.insert ( new MTri3 ( gf->triangles[i] ,lc ) );
    }

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
	  double center[2],uv[2];
	  if (worst->getRadius() < 0.5 * sqrt(2.0)) break;	  
	  circUV(worst->tri(),Us,Vs,center);
	  bool inside = invMapUV(worst->tri(),center,Us,Vs,uv,1.e-8);

	  if (1 || inside)
	    {
	      // we use here local coordinates as real coordinates
	      // x,y and z will be computed hereafter
	      //	      Msg(INFO,"Point is inside");
	      GPoint p = gf->point (center[0],center[1]);
	      MVertex *v = new MFaceVertex (p.x(),p.y(),p.z(),gf,center[0],center[1]);
	      v->setNum(NUM++);
	      double lc1 = ((1.-uv[0]-uv[1]) * vSizes [worst->tri()->getVertex(0)->getNum()] + 
			       uv[0] * vSizes [worst->tri()->getVertex(1)->getNum()] + 
			       uv[1] * vSizes [worst->tri()->getVertex(2)->getNum()] ); 
	      //	      double eigMetricSurface = gf->getMetricEigenvalue(SPoint2(center[0],center[1]));
	      double lc = BGM_MeshSize(gf,center[0],center[1],p.x(),p.y(),p.z());
	      //	      printf("lc1 %12.5E lc %12.5E\n",lc1,lc);
	      
	      vSizesBGM.push_back( lc );
	      vSizes.push_back   ( lc1);
	      Us.push_back( center[0] );
	      Vs.push_back( center[1] );
	      
	      if (!insertVertex ( v , worst, AllTris,vSizes,vSizesBGM,Us,Vs))
		{
		  Msg(INFO,"cavity is invalid");
		  AllTris.erase(AllTris.begin());
		  worst->forceRadius(-1);
		  AllTris.insert(worst);		  
		  delete v;
		}
	      else 
		gf->mesh_vertices.push_back(v);
	    }
 	  else
 	    {
	      Msg(INFO,"Point %g %g is outside %g %g - %g %g - %g %g (%g %g)",
		  center[0],center[1],		  
		  Us [(worst)->tri()->getVertex(0)->getNum()],
		  Vs [(worst)->tri()->getVertex(0)->getNum()],
		  Us [(worst)->tri()->getVertex(1)->getNum()],
		  Vs [(worst)->tri()->getVertex(1)->getNum()],
		  Us [(worst)->tri()->getVertex(2)->getNum()],
		  Vs [(worst)->tri()->getVertex(2)->getNum()],
		  uv[0],uv[1]);
 	      AllTris.erase(AllTris.begin());
 	      worst->forceRadius(0);
 	      AllTris.insert(worst);		  
	    }
	}
    }

  // optimize the mesh

  // fill new gmsh structures with triangles
   char name[245];
   sprintf(name,"param%d.pos",gf->tag());
   FILE *ff = fopen (name,"w");
   fprintf(ff,"View\"test\"{\n");
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
	  fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0};\n",
		  Us [(worst)->tri()->getVertex(0)->getNum()],
		  Vs [(worst)->tri()->getVertex(0)->getNum()],
		  0.0,
		  Us [(worst)->tri()->getVertex(1)->getNum()],
		  Vs [(worst)->tri()->getVertex(1)->getNum()],
		  0.0,
		  Us [(worst)->tri()->getVertex(2)->getNum()],
		  Vs [(worst)->tri()->getVertex(2)->getNum()],
		  0.0);
	}
      delete worst;
      AllTris.erase(AllTris.begin());      
    }
  fprintf(ff,"};\n");
  fclose (ff);
}
