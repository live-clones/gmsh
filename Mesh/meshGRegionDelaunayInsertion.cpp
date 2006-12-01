// $Id: meshGRegionDelaunayInsertion.cpp,v 1.9 2006-12-01 16:16:50 remacle Exp $
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

#include "BackgroundMesh.h"
#include "meshGRegionDelaunayInsertion.h"
#include "GRegion.h"
#include "Numeric.h"
#include "Message.h"
#include <set>
#include <map>
#include <algorithm>

int MTet4::inCircumSphere ( const double *p ) const
{
  double pa[3] = {base->getVertex(0)->x(),base->getVertex(0)->y(),base->getVertex(0)->z()};
  double pb[3] = {base->getVertex(1)->x(),base->getVertex(1)->y(),base->getVertex(1)->z()};
  double pc[3] = {base->getVertex(2)->x(),base->getVertex(2)->y(),base->getVertex(2)->z()};
  double pd[3] = {base->getVertex(3)->x(),base->getVertex(3)->y(),base->getVertex(3)->z()};
  double result = gmsh::insphere(pa, pb, pc, pd, (double*)p) * gmsh::orient3d(pa, pb, pc, pd);  
  return (result > 0) ? 1 : 0;
}

int faces[4][3] = {{0,1,2},{0,2,3},{0,1,3},{1,2,3}};

struct faceXtet
{
  MVertex *v[3];
  MTet4 * t1;
  int i1;
  faceXtet ( MTet4 *_t, int iFac)
    : t1(_t),i1(iFac)
  {
    v[0] = t1->tet()->getVertex ( faces [iFac][0] );
    v[1] = t1->tet()->getVertex ( faces [iFac][1] );
    v[2] = t1->tet()->getVertex ( faces [iFac][2] );
    std::sort ( v, v+3 );
  }
  inline bool operator < ( const faceXtet & other) const
  {
    if (v[0] < other.v[0])return true;
    if (v[0] > other.v[0])return false;
    if (v[1] < other.v[1])return true;
    if (v[1] > other.v[1])return false;
    if (v[2] < other.v[2])return true;
    return false;
  }
};


template <class ITER>
void connectTets ( ITER beg, ITER end)
{
  std::set<faceXtet> conn;
  {
    while (beg != end)
      {
	if (!(*beg)->isDeleted())
	  {
	    for (int i=0;i<4;i++)
	      {
		faceXtet fxt ( *beg ,  i );
		std::set<faceXtet>::iterator found = conn.find (fxt);
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


void recurFindCavity ( std::list<faceXtet> & shell, 
		       std::list<MTet4*> & cavity, 
		       MVertex *v , 
		       MTet4 *t)
{
//   Msg(INFO,"tet %d %d %d %d",t->tet()->getVertex(0)->getNum(),
//       t->tet()->getVertex(1)->getNum(),
//       t->tet()->getVertex(2)->getNum(),
//       t->tet()->getVertex(3)->getNum());

  // invariant : this one has to be inserted in the cavity
  // consider this tet deleted 
  // remove its reference to its neighbors
  t->setDeleted(true);
  // the cavity that has to be removed
  // because it violates delaunay criterion
  cavity.push_back(t);

  for (int i=0;i<4;i++)
    {
      MTet4 *neigh =  t->getNeigh(i) ;
      if (!neigh)
	  shell.push_back ( faceXtet ( t, i ) );
      else  if (!neigh->isDeleted())
	{
	  int circ =  neigh->inCircumSphere ( v );
	  if (circ)
	    recurFindCavity ( shell, cavity,v , neigh);
	  else
	    shell.push_back ( faceXtet ( t, i ) );
	}
    }
}

bool insertVertex (MVertex *v , 
		   MTet4   *t ,
		   std::set<MTet4*,compareTet4Ptr> &allTets,
		   std::vector<double> & vSizes)
{
  std::list<faceXtet>  shell;
  std::list<MTet4*>  cavity; 
  std::list<MTet4*>  new_cavity;

//   int NC = 0;
//   {
//     for (std::set<MTet4*,compareTet4Ptr>::iterator it = allTets.begin();it!=allTets.end();++it)
//       {
// 	if (!((*it)->isDeleted()) && (*it)->inCircumSphere ( v ))NC++;	
//       }
//   }

  recurFindCavity ( shell,  cavity, v , t);  

//     Msg(INFO,"%d %d",cavity.size(),NC);
//     if (NC != cavity.size())throw;

  // check that volume is conserved
  double newVolume = 0;
  double oldVolume = 0;

  //  char name2[245];
  //  FILE *ff2 = fopen (name2,"w");
  //  fprintf(ff2,"View\"test\"{\n");


  std::list<MTet4*>::iterator ittet = cavity.begin();
  std::list<MTet4*>::iterator ittete = cavity.end();
  while ( ittet != ittete )
    {
      oldVolume += fabs((*ittet)->getVolume());
//       fprintf(ff2,"SS(%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0,0};\n",
// 	      (*ittet)->tet()->getVertex(0)->x(),
// 	      (*ittet)->tet()->getVertex(0)->y(),
// 	      (*ittet)->tet()->getVertex(0)->z(),
// 	      (*ittet)->tet()->getVertex(1)->x(),
// 	      (*ittet)->tet()->getVertex(1)->y(),
// 	      (*ittet)->tet()->getVertex(1)->z(),
// 	      (*ittet)->tet()->getVertex(2)->x(),
// 	      (*ittet)->tet()->getVertex(2)->y(),
// 	      (*ittet)->tet()->getVertex(2)->z(),
// 	      (*ittet)->tet()->getVertex(3)->x(),
// 	      (*ittet)->tet()->getVertex(3)->y(),
// 	      (*ittet)->tet()->getVertex(3)->z());
//       if(!(*ittet)->inCircumSphere ( v ))throw;
      ++ittet;
    }
//   fprintf(ff2,"};\n");
//   fclose (ff2);
//  Msg(INFO,"cavity of size %d volume %g",cavity.size(),oldVolume);
  // create new tetrahedron using faces that are
  // on the border of the cavity
  // add those to a list
  // add also tets that are on the other side of the face
  // in order to perform the connexions afterwards

//   char name[245];
//   sprintf(name,"test%d.pos",III);

//   FILE *ff = fopen (name,"w");
//   fprintf(ff,"View\"test\"{\n");

  MTet4** newTets = new MTet4*[shell.size()];;
  int k = 0;

  std::list<faceXtet>::iterator it =   shell.begin();



  while (it != shell.end())
    {
      MTetrahedron *t = new MTetrahedron ( it->v[0],
					   it->v[1],
					   it->v[2],
					   v);
      //      Msg(INFO,"shell %d %d %d",it->v[0]->getNum(),it->v[1]->getNum(),it->v[2]->getNum());
//            fprintf(ff,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g) {0,0,0};\n",
// 		   it->v[0]->x(),
// 		   it->v[0]->y(),
// 		   it->v[0]->z(),
// 		   it->v[1]->x(),
// 		   it->v[1]->y(),
// 		   it->v[1]->z(),
// 		   it->v[2]->x(),
// 		   it->v[2]->y(),
// 		   it->v[2]->z());
      
      MTet4 *t4 = new MTet4 ( t , vSizes); 
      newTets[k++]=t4;
      // all new tets are pushed front in order to
      // ba able to destroy them if the cavity is not
      // star shaped around the new vertex.
      // here, we better use robust perdicates
      // that implies to orient all faces and
      // ensure that the tets are all oriented the same.
      new_cavity.push_back (t4);
      MTet4 *otherSide = it->t1->getNeigh(it->i1);

      if (otherSide)
      	new_cavity.push_back (otherSide);
      //      if (!it->t1->isDeleted())throw;
      newVolume += fabs(t4->getVolume());
      ++it;
    }
//   fprintf(ff,"};\n");
//   fclose (ff);
//  Msg(INFO,"new cavity of vol %g (%d boundaries)",newVolume,shell.size());
  // OK, the cavity is star shaped
  if (fabs(oldVolume - newVolume) < 1.e-10 * oldVolume )
    {      
      connectTets ( new_cavity.begin(),new_cavity.end() );      
      allTets.insert(newTets,newTets+shell.size());
      //connectTets ( allTets.begin(),allTets.end() );      
      delete [] newTets;
      return true;
    }
  // The cavity is NOT star shaped
  else
    {      
      for (unsigned int i=0;i<shell.size();i++)delete newTets[i];
      delete [] newTets;      
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

static void setLcs ( MTetrahedron *t, std::map<MVertex*,double> &vSizes)
{
  for (int i=0;i<4;i++)
    {
      for (int j=i+1;j<4;j++)
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

// void recover_volumes( GRegion *gr , std::set<MTet4*,compareTet4Ptr> & allTets )
// {
//   std::set<MTet4*,compareTet4Ptr>::iterator it = allTets.begin();
//   for ( ; it != allTets.end() ; ++it )
//     {
//       MTet4 *t = *allTets.begin();
//       if (!t->isDeleted())
// 	{
// 	}
//     }
// }


void insertVerticesInRegion (GRegion *gr) 
{

  std::set<MTet4*,compareTet4Ptr> allTets;
  std::map<MVertex*,double> vSizesMap;
  std::vector<double> vSizes;

  for (unsigned int i=0;i<gr->tetrahedra.size();i++)setLcs ( gr->tetrahedra[i] , vSizesMap);
  
  int NUM=0;
  for (std::map<MVertex*,double>::iterator it = vSizesMap.begin();it!=vSizesMap.end();++it)
    {
      it->first->setNum(NUM++);
      vSizes.push_back(it->second);
    }

  for (unsigned int i=0;i<gr->tetrahedra.size();i++)
    allTets.insert ( new MTet4 ( gr->tetrahedra[i] ,vSizes ) );

  gr->tetrahedra.clear();
  connectTets ( allTets.begin(), allTets.end() );      

  Msg(INFO,"All %d tets were connected",allTets.size());

  // here the classification should be done

  int ITER = 0;

  while (1)
    {
      MTet4 *worst = *allTets.begin();

      if (worst->isDeleted())
	{
	  delete worst->tet();
	  delete worst;
	  allTets.erase(allTets.begin());
	  //	  Msg(INFO,"Worst tet is deleted");
	}
      else
	{
	  if(ITER++%5000 ==0)
	    Msg(INFO,"%d points created -- Worst tet radius is %g",vSizes.size(),worst->getRadius());
	  if (worst->getRadius() < 1) break;
	  double center[3];
	  worst->tet()->circumcenter(center);
	  double uvw[3];
	  bool inside = worst->tet()->invertmapping(center,uvw);
	  if (inside)
	    {
	      MVertex *v = new MVertex (center[0],center[1],center[2]);
	      v->setNum(NUM++);
 	      double lc1 = 
 		(1-uvw[0]-uvw[1]-uvw[2])*vSizes[worst->tet()->getVertex(0)->getNum()] +
 		(uvw[0])*vSizes[worst->tet()->getVertex(1)->getNum()] +
 		(uvw[1])*vSizes[worst->tet()->getVertex(2)->getNum()] +
 		(uvw[2])*vSizes[worst->tet()->getVertex(3)->getNum()];
	      double lc = std::min(lc1,BGM_MeshSize(gr,0,0,center[0],center[1],center[2]));
	      vSizes.push_back(lc);
	      // compute mesh spacing there
	      if (!insertVertex ( v  , worst, allTets,vSizes))
		{
		  allTets.erase(allTets.begin());
		  worst->forceRadius(0);
		  allTets.insert(worst);		  
		  delete v;
		}
	      else 
		{
		  gr->mesh_vertices.push_back(v);
		}
	    }
	  else
	    {
	      //      Msg(INFO,"Point is outside");
	      allTets.erase(allTets.begin());
	      worst->forceRadius(0);
	      allTets.insert(worst);		  
	    }
	}
    }

  while (1)
    {
      if (allTets.begin() == allTets.end() ) break;
      MTet4 *worst = *allTets.begin();
      if (worst->isDeleted())
	{
	  delete worst->tet();
	}
      else
	{
	  gr->tetrahedra.push_back(worst->tet());
	}
      delete worst;
      allTets.erase(allTets.begin());      
    }
}
