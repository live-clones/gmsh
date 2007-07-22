// $Id: meshGFace.cpp,v 1.81 2007-07-22 15:47:46 geuzaine Exp $
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

#include "meshGFace.h"
#include "meshGFaceDelaunayInsertion.h"
#include "DivideAndConquer.h"
#include "BackgroundMesh.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "MRep.h"
#include "Context.h"
#include "GPoint.h"
#include "Message.h"
#include "Numeric.h"
#include "BDS.h"

extern Context_T CTX;

static double SCALINGU=1,SCALINGV=1;

void computeEdgeLoops(const GFace *gf,
		      std::vector<MVertex*> &all_mvertices,
		      std::vector<int> &indices)
{
  std::list<GEdge*> edges = gf->edges();
  std::list<int> ori = gf->orientations();
  std::list<GEdge*>::iterator it = edges.begin();
  std::list<int>::iterator ito = ori.begin();
    
  indices.push_back(0);
  GVertex *start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
  GVertex *v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
  all_mvertices.push_back(start->mesh_vertices[0]);
  if (*ito == 1)
    for (unsigned int i=0;i<(*it)->mesh_vertices.size();i++)
      all_mvertices.push_back((*it)->mesh_vertices[i]);
  else
    for (int i=(*it)->mesh_vertices.size()-1;i>=0;i--)
      all_mvertices.push_back((*it)->mesh_vertices[i]);
  
  GVertex *v_start = start;
  while(1){		
    ++it;
    ++ito;
    if(v_end == start){
      indices.push_back(all_mvertices.size());
      if(it == edges.end ()) break;
      start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
      v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
      v_start = start;
    }
    else{	
      if(it == edges.end ()) throw;
      v_start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
      if(v_start != v_end) throw;
      v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
    }
    all_mvertices.push_back(v_start->mesh_vertices[0]);
    if(*ito == 1)
      for(unsigned int i = 0; i < (*it)->mesh_vertices.size(); i++)
	all_mvertices.push_back((*it)->mesh_vertices[i]);
    else
      for (int i = (*it)->mesh_vertices.size()-1; i >= 0; i--)
	all_mvertices.push_back((*it)->mesh_vertices[i]);
  }
}

double F_LC_ANALY(double xx, double yy, double zz)
{
  //  return 0.005 + 0.05*fabs (sin(5*xx) + sin(15*yy) + sin(15*zz));
  //  return 0.02;
  //  return 0.002 + 0.04*fabs (sin(6*xx) + sin(6*yy) + sin(6*zz));
  return 0.003 + 0.05*fabs(sin(8*xx) + sin(8*yy) + sin(8*zz));
  return 0.02 + 0.1*fabs(sin(3*xx) + sin(3*yy) + sin(3*zz));
  return 0.01 + 0.1*fabs(sin((xx*xx+(zz-0.7)*(zz-0.7)-.25))); 
  return 0.05 + 0.1*fabs(xx*yy);
}

double NewGetLc(BDS_Point *p)
{
  //  double l = Attractor::lc (p->X,p->Y,p->Z);
  return p->lc();
}

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->X-p2->X;
  const double dy = p1->Y-p2->Y;
  const double dz = p1->Z-p2->Z;
  const double l = sqrt(dx*dx+dy*dy+dz*dz);
  return l;
}

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2, GFace *f)
{

  GPoint GP = f->point (SPoint2(0.5*(p1->u+p2->u)*SCALINGU,0.5*(p1->v+p2->v)*SCALINGV));

  const double dx1 = p1->X-GP.x();
  const double dy1 = p1->Y-GP.y();
  const double dz1 = p1->Z-GP.z();
  const double l1 = sqrt(dx1*dx1+dy1*dy1+dz1*dz1);
  const double dx2 = p2->X-GP.x();
  const double dy2 = p2->Y-GP.y();
  const double dz2 = p2->Z-GP.z();
  const double l2 = sqrt(dx2*dx2+dy2*dy2+dz2*dz2);
  //  printf("%g %g\n",l1,l2);
  return l1+l2;
}

inline double computeEdgeLinearLength(BDS_Edge *e, GFace *f)
{
  if (f->geomType() == GEntity::Plane)
    return e->length();
  else
    {
      double l = computeEdgeLinearLength(e->p1, e->p2,f); 
      //      printf ("%g %g \n",e->length(),l);
      return l;
    } 
}

inline double computeParametricEdgeLength(BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->u-p2->u;
  const double dy = p1->v-p2->v;
  const double l = sqrt (dx*dx+dy*dy);
  return l;
}

double NewGetLc(BDS_Edge *e, GFace *f)
{
  double linearLength = computeEdgeLinearLength(e,f);
  double l1 = NewGetLc(e->p1);
  double l2 = NewGetLc(e->p2);
  return 2*linearLength / (l1 + l2);
}

bool edgeSwapTest(BDS_Edge *e,GFace *gf)
{
  BDS_Point *op[2];
  
  if(!e->p1->config_modified && ! e->p2->config_modified) return false;

  if(e->numfaces() != 2) return false;

  e->oppositeof (op);
  
  double edgeLength1, edgeLength2;

  edgeLength1 = computeEdgeLinearLength(e,gf);
  edgeLength2 = computeEdgeLinearLength(op[0], op[1],gf);
  double lp1 = NewGetLc(e->p1);
  double lp2 = NewGetLc(e->p1);
  double lo1 = NewGetLc(op[0]);
  double lo2 = NewGetLc(op[1]);


  double el1 = 2*edgeLength1 / (lp1 + lp2);
  double el2 = 2*edgeLength2 / (lo1 + lo2);

  double q1 = fabs(1-el1);
  double q2 = fabs(1-el2);

  return q2 < 0.5*q1;
}

void fourthPoint (double *p1, double *p2, double *p3, double *p4)
{
  double c[3];
  MTriangle::circumcenterXYZ(p1,p2,p3,c);
  double vx[3] = {p2[0]-p1[0],p2[1]-p1[1],p2[2]-p1[2]};
  double vy[3] = {p3[0]-p1[0],p3[1]-p1[1],p3[2]-p1[2]};
  double vz[3]; prodve (vx,vy,vz);
  norme(vz);
  double R = sqrt((p1[0]-c[0])*(p1[0]-c[0])+
 		  (p1[1]-c[1])*(p1[1]-c[1])+
 		  (p1[2]-c[2])*(p1[2]-c[2]));
  p4[0] = c[0] + R * vz[0];
  p4[1] = c[1] + R * vz[1];
  p4[2] = c[2] + R * vz[2];
}

bool edgeSwapTestDelaunay(BDS_Edge *e,GFace *gf)
{

  if (CTX.mesh.algo2d == ALGO_2D_MESHADAPT)
    return edgeSwapTest (e,gf);

  BDS_Point *op[2];
  
  if(!e->p1->config_modified && ! e->p2->config_modified) return false;

  if(e->numfaces() != 2) return false;

  e->oppositeof (op);
  
  double p1x[3] =  {e->p1->X,e->p1->Y,e->p1->Z};
  double p2x[3] =  {e->p2->X,e->p2->Y,e->p2->Z};
  double op1x[3] = {op[0]->X,op[0]->Y,op[0]->Z};
  double op2x[3] = {op[1]->X,op[1]->Y,op[1]->Z};
  double fourth[3];
  fourthPoint(p1x,p2x,op1x,fourth);
  double result = gmsh::insphere(p1x, p2x, op1x, fourth, op2x) * gmsh::orient3d(p1x, p2x, op1x, fourth);  
  return result > 0.;
}


int edgeSwapTestQuality(BDS_Edge *e, double fact = 1.1)
{
  BDS_Point *op[2];
  
  if(!e->p1->config_modified && ! e->p2->config_modified) return false;
  
  if(e->numfaces() != 2) return false;
  
  e->oppositeof (op);
  
  double qa1 = quality_triangle(e->p1, e->p2, op[0]);
  double qa2 = quality_triangle(e->p1, e->p2, op[1]);
  double qb1 = quality_triangle(e->p1, op[0], op[1]);
  double qb2 = quality_triangle(e->p2, op[0], op[1]);
  double qa = (qa1<qa2) ? qa1 : qa2;
  double qb = (qb1<qb2) ? qb1 : qb2;
  if(qb > fact*qa) return 1;
  if(qb < qa/fact) return -1;
  return 0;
}

void OptimizeMesh(GFace *gf, BDS_Mesh &m, const int NIT)
{
  // optimize
  for(int i = 0 ; i < NIT ; i++){
    {
      std::set<BDS_Point*,PointLessThan> PTS (m.points);
      std::set<BDS_Point*,PointLessThan>::iterator itp = PTS.begin();
      while (itp != PTS.end())
	{
	  std::list < BDS_Face * >t;
	  (*itp)->getTriangles(t);
	  if (t.size()==(*itp)->edges.size()  &&  t.size() < 5)
	    for (std::list<BDS_Edge*>::iterator ite = (*itp)->edges.begin();ite!=(*itp)->edges.end();++ite)
	      {
		if(m.collapse_edge_parametric ( (*ite), (*itp)))break;
	      }
	  else
	    m.smooth_point_centroid(*itp,gf);		
	  ++itp;
	}
    }
    for (int KK=0;KK<4;KK++){
      // swap edges that provide a better configuration
      int NN1 = m.edges.size();
      int NN2 = 0;
      std::list<BDS_Edge*>::iterator it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (!(*it)->deleted)
	    {
	      int result = edgeSwapTestQuality(*it,5);
	      if (result >= 0)
		if(edgeSwapTestDelaunay(*it,gf) || result > 0)
		  m.swap_edge ( *it , BDS_SwapEdgeTestParametric());
	    }
	  ++it;
	}
      m.cleanup();  
    }
  }
}

void RefineMesh ( GFace *gf, BDS_Mesh &m , const int NIT)
{
  int IT =0;

  //printf("lc (1,1) = %g\n",Attractor::lc(1,1,0));

  int MAXNP = m.MAXPOINTNUMBER;

  // computecharacteristic lengths using mesh edge spacing
  // separate attractors & 
  if (NIT > 0 && !BGMExists())
    {
      std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
      while (itp != m.points.end())
	{
	  std::list<BDS_Edge*>::iterator it  = (*itp)->edges.begin();
	  std::list<BDS_Edge*>::iterator ite = (*itp)->edges.end();
	  double L = 1.e22;
	  while(it!=ite){
	    double l = (*it)->length();
	    if (l<L && (*it)->g && (*it)->g->classif_degree == 1)L=l;
	    ++it;
	  }
	  (*itp)->lc() = std::min(L,(*itp)->lc());
	  ++itp;
	}
    }

  double OLDminL=1.E22,OLDmaxL=0;

  const double MINE_ = 0.7, MAXE_=1.4;
  while (1)
    {
    //   double stot = 0;
//       std::list<BDS_Face *>::iterator ittt = m.triangles.begin();
//       while (ittt!= m.triangles.end())
// 	{
// 	  if (!(*ittt)->deleted)
// 	    {
// 	      BDS_Point *pts[4];
// 	      (*ittt)->getNodes(pts);
// 	      stot += fabs( surface_triangle_param(pts[0], pts[1], pts[2]));
// 	    }
// 	  ++ittt;
// 	}
      
      int nb_split=0;
      int nb_smooth=0;
      int nb_collaps=0;
      int nb_swap=0;

      // split long edges

      double minL=1.E22,maxL=0;
      int NN1 = m.edges.size();
      int NN2 = 0;
      std::list<BDS_Edge*>::iterator it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (!(*it)->deleted)
	    {
	      (*it)->p1->config_modified = false;
	      (*it)->p2->config_modified = false;
	      double lone = NewGetLc ( *it,gf);	      
	      maxL = std::max(maxL,lone);
	      minL = std::min(minL,lone);
	    }
	  ++it;
	}

      if (OLDminL == minL && OLDmaxL == maxL)break;
      OLDminL = minL;OLDmaxL = maxL;
      
      if ((minL > MINE_ && maxL < MAXE_) || IT > (abs(NIT)))break;


      NN1 = m.edges.size();
      NN2 = 0;
      it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (!(*it)->deleted)
	    {
	      double lone = NewGetLc ( *it,gf);

	      // take care with seams :
	      //	      if (lone < 1.e-10 && computeParametricEdgeLength((*it)->p1,(*it)->p2) > 1.e-5) lone = 2;
	      if ((*it)->numfaces() == 2 && (lone >  MAXE_))
		{

		  const double coord = 0.5;

		  BDS_Point *mid ;
		  mid  = m.add_point(++m.MAXPOINTNUMBER,
				     coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u,
				     coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v,gf);
  		  double l1;
		  if (!BGMExists())
		    l1 = BGM_MeshSize(gf,
				      (coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u)*m.scalingU,
				      (coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v)*m.scalingV,
				      mid->X,mid->Y,mid->Z);
		  else l1 = 0.5 * ( (*it)->p1->lc() +  (*it)->p2->lc() );

		  mid->lc() = l1;
		  m.split_edge ( *it, mid );
		  nb_split++;
		} 
	    }
	  ++it;
	}

      // swap edges that provide a better configuration
//       NN1 = m.edges.size();
      NN2 = 0;
      it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  // result = -1 => forbid swap because too badly shaped elements
	  // result = 0  => whatever
	  // result = 1  => oblige to swap because the quality is greatly improved
	  if (!(*it)->deleted)
	    {
	      int result = edgeSwapTestQuality(*it,5);
	      if (result >= 0)
		if(edgeSwapTestDelaunay(*it,gf) || result > 0)
		  if (m.swap_edge ( *it , BDS_SwapEdgeTestParametric()))
		    nb_swap++;
	      ++it;
	    }
	}

      // collapse short edges
      NN1 = m.edges.size();
      NN2 = 0;
      it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  double lone = NewGetLc ( *it,gf);
	  //	  if (lone < 1.e-10 && computeParametricEdgeLength((*it)->p1,(*it)->p2) > 1.e-5) lone = 2;

	  if (!(*it)->deleted && (*it)->numfaces() == 2 && lone < MINE_ )
	    {
	      bool res = false;
	      if ( (*it)->p1->iD > MAXNP )
		res =m.collapse_edge_parametric ( *it, (*it)->p1);
	      else if ( (*it)->p2->iD > MAXNP )
		res =m.collapse_edge_parametric ( *it, (*it)->p2);
	      if (res)
		nb_collaps ++;
	    }
	  ++it;
	}

      // swap edges that provide a better configuration
      NN1 = m.edges.size();
      NN2 = 0;
      it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (!(*it)->deleted)
	    {
	      int result = edgeSwapTestQuality(*it,5);
	      if (result >= 0)
		if(edgeSwapTestDelaunay(*it,gf) || result > 0)
		  if (m.swap_edge ( *it , BDS_SwapEdgeTestParametric()))
		    nb_swap++;
	      ++it;
	    }
	}
      // smooth resulting mesh
      //if (IT % 4 == 0 )
	{
	  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
	  while (itp != m.points.end())
	    {

	      if(m.smooth_point_centroid(*itp,gf))
		nb_smooth ++;
	      ++itp;
	    }
	}
	// recompute mesh sizes takin into account curvature , BGMESH & co
	m.cleanup();  
	if (0 && IT % 5 == 0)
	{
	  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
	  while (itp != m.points.end())
	    {
	      BDS_Point *p = *itp;
	      if(p->g->classif_degree == 2)
		{
		  double l2 = BGM_MeshSize(gf,p->u*m.scalingU,p->v*m.scalingV,p->X,p->Y,p->Z);
		  p->config_modified = true;
		  p->lc() = std::min(p->lc(),l2);
		}
	      ++itp;
	    }
	  for (int ITERA = 0;ITERA< 0; ITERA++);
	  {
	    it = m.edges.begin();
	    while (it != m.edges.end())
	      {
		BDS_Edge *e = *it;
		if (!e->deleted)
		  {
		    double l1 = e->p1->lc();
		    double l2 = e->p2->lc();
		    if (l1 > 1.3 *l2) e->p1->lc() = 1.5*l2;
		    if (l2 > 1.3 *l1) e->p2->lc() = 1.5*l1;
		  }
		++it;
	      }
	  }
	}
	IT++;
	Msg(DEBUG1," iter %3d minL %8.3f maxL %8.3f : %6d splits, %6d swaps, %6d collapses, %6d moves",IT,minL,maxL,nb_split,nb_swap,nb_collaps,nb_smooth);

	if (nb_split==0 && nb_collaps == 0)break;
    }  
}




bool recover_medge ( BDS_Mesh *m, GEdge *ge)
{

  m->add_geom (ge->tag(), 1);
  BDS_GeomEntity *g = m->get_geom(ge->tag(),1);

  if (ge->mesh_vertices.size() == 0)
    {

      MVertex   *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
      MVertex   *vend   = *(ge->getEndVertex()->mesh_vertices.begin());
      BDS_Point *pstart = m->find_point(vstart->getNum());
      BDS_Point *pend   = m->find_point(vend->getNum());

      if(!pstart->g)
	{
	  m->add_geom (vstart->getNum(), 0);
	  BDS_GeomEntity *g0 = m->get_geom(vstart->getNum(), 0);
	  pstart->g = g0;
	}
      if(!pend->g)
	{
	  m->add_geom (vend->getNum(), 0);
	  BDS_GeomEntity *g0 = m->get_geom(vend->getNum(), 0);
	  pend->g = g0;
	}
      BDS_Edge * e = m->recover_edge ( vstart->getNum(), vend->getNum());
      if (e)e->g = g;
      else {
	Msg(GERROR,"Unable to recover an edge %g %g && %g %g (size 0)",vstart->x(),vstart->y(), vend->x(),vend->y());
	Msg(GERROR,"Mesh with %d triangles",m->triangles.size());
	return false;
      }
      return true;
    }


  MVertex *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
  MVertex *vend   = *(ge->mesh_vertices.begin());

  BDS_Point *pstart = m->find_point(vstart->getNum());
  if(!pstart->g)
    {
      m->add_geom (vstart->getNum(), 0);
      BDS_GeomEntity *g0 = m->get_geom(vstart->getNum(), 0);
      pstart->g = g0;
    }

  BDS_Edge * e = m->recover_edge ( vstart->getNum(), vend->getNum());
  if (e)e->g = g;
  else return false;

  for (unsigned int i=1;i<ge->mesh_vertices.size();i++)
    {
      vstart = ge->mesh_vertices[i-1];
      vend   = ge->mesh_vertices[i];
      e = m->recover_edge ( vstart->getNum(), vend->getNum());
      if (e)e->g = g;
      else {
	Msg(GERROR,"Unable to recover an edge %g %g && %g %g (%d/%d)",vstart->x(),vstart->y(), vend->x(),vend->y(),i,ge->mesh_vertices.size());
	return false;
      }
    }    
  vstart = vend;
  vend   = *(ge->getEndVertex()->mesh_vertices.begin());
  e = m->recover_edge ( vstart->getNum(), vend->getNum());
  if (e)e->g = g;
  else {
    Msg(GERROR,"Unable to recover an edge %g %g && %g %g",vstart->x(),vstart->y(), vend->x(),vend->y());
    return false;
  }

  BDS_Point *pend = m->find_point(vend->getNum());
  if(!pend->g)
    {
      m->add_geom (vend->getNum(), 0);
      BDS_GeomEntity *g0 = m->get_geom(vend->getNum(), 0);
      pend->g = g0;
    }
  return true;
}


// Builds An initial triangular mesh
// that respects the boundaries of the
// domain, including embedded points 
// and surfaces

bool gmsh2DMeshGenerator ( GFace *gf , bool debug = true)
{

  //if (gf->tag() != 16)return true;

  typedef std::set<MVertex*> v_container ;
  v_container all_vertices;
  std::map<int, MVertex*>numbered_vertices;
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> emb_edges = gf->emb_edges();
  std::list<GEdge*>::iterator it = edges.begin();

  // build a set with all points of the boundaries
  it = edges.begin();
  while(it != edges.end())
    {
      if ((*it)->isSeam(gf))return false;
      if(!(*it)->is_mesh_degenerated()){
        all_vertices.insert ( (*it)->mesh_vertices.begin() , (*it)->mesh_vertices.end() );
        all_vertices.insert ( (*it)->getBeginVertex()->mesh_vertices.begin() , (*it)->getBeginVertex()->mesh_vertices.end() );
        all_vertices.insert ( (*it)->getEndVertex()->mesh_vertices.begin() , (*it)->getEndVertex()->mesh_vertices.end() );
      }
      ++it;
    }

  it = emb_edges.begin();
  while(it != emb_edges.end())
    {
      all_vertices.insert ( (*it)->mesh_vertices.begin() , (*it)->mesh_vertices.end() );
      all_vertices.insert ( (*it)->getBeginVertex()->mesh_vertices.begin() , (*it)->getBeginVertex()->mesh_vertices.end() );
      all_vertices.insert ( (*it)->getEndVertex()->mesh_vertices.begin() , (*it)->getEndVertex()->mesh_vertices.end() );
      ++it;
    }

  double * U_     = new double [all_vertices.size()];
  double * V_     = new double [all_vertices.size()];

  v_container::iterator itv = all_vertices.begin();

  //  FILE *fdeb = fopen("debug.dat","w");
  //  fprintf(fdeb,"surface %d\n" ,gf->tag());
  int count = 0;
  SBoundingBox3d bbox;
  while(itv != all_vertices.end()){
    MVertex *here = *itv;
    SPoint2 param;
    if(here->onWhat()->dim() == 0){
      GVertex *gv = (GVertex*)here->onWhat();
      if (gv->edges().size() == 1)
	{
	  GEdge *ge = *(gv->edges().begin());
	  Range<double> bb = ge->parBounds(0);
	  param = ge->reparamOnFace(gf, bb.low(), 1);	  
	}
      else
	param = gv->reparamOnFace(gf,1);
      
    }
    else if(here->onWhat()->dim() == 1){
      GEdge *ge = (GEdge*)here->onWhat();
      double UU;
      here->getParameter(0, UU);
      param = ge->reparamOnFace(gf, UU, 1);
    }
    else{
      double UU, VV;
      if(here->onWhat() == gf && here->getParameter(0, UU) && here->getParameter(1, VV))
	param = SPoint2(UU, VV);
      else
	param = gf->parFromPoint(SPoint3(here->x(), here->y(), here->z()));
    }
    // fprintf(fdeb,"%d %g %g %g\n" ,here->getNum(),here->x(),here->y(),here->z());
    U_[count] = param.x();
    V_[count] = param.y();
    (*itv)->setNum(count);
    numbered_vertices[(*itv)->getNum()] = *itv;
    bbox += SPoint3 ( param.x(), param.y() , 0);      
    count ++;
    ++itv;
  }
  
  //  fclose (fdeb);

  // compute the bounding box in parametric space
  // I do not have SBoundingBox, so I use a 3D one...
  // At the same time, number the vertices locally

  SVector3 dd (bbox.max() ,bbox.min());
  double LC2D = norm(dd);

  // Use a divide & conquer type algorithm to create a triangulation
  // We add to the triangulation a box with 4 points that encoses
  // the domain.

  /// Fill the DocRecord Data Structure with the points
  DocRecord doc;


  doc.points =  (PointRecord*)malloc((all_vertices.size()+4) * sizeof(PointRecord));
  itv = all_vertices.begin();
  int j = 0;
  while(itv != all_vertices.end())
    {
      MVertex *here     = *itv;
      double XX = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;
      double YY = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;
      doc.points[j].where.h = U_[j] + XX;
      doc.points[j].where.v = V_[j] + YY;
      doc.points[j].adjacent = NULL;
      doc.points[j].data = here;      
      j++;
      ++itv;
    }


  /// Increase the size of the bounding box
  bbox *= 2.5;
  /// add 4 points than encloses the domain
  /// Use negative number to distinguish thos fake vertices
  MVertex *bb[4];
  bb[0] = new MVertex ( bbox.min().x(), bbox.min().y(), 0,gf,-1);
  bb[1] = new MVertex ( bbox.min().x(), bbox.max().y(), 0,gf,-2);
  bb[2] = new MVertex ( bbox.max().x(), bbox.min().y(), 0,gf,-3);
  bb[3] = new MVertex ( bbox.max().x(), bbox.max().y(), 0,gf,-4);
    
  for ( int ip = 0 ; ip<4 ; ip++ )
    {
      doc.points[all_vertices.size()+ip].where.h  = bb[ip]->x();
      doc.points[all_vertices.size()+ip].where.v  = bb[ip]->y();
      doc.points[all_vertices.size()+ip].adjacent = 0;
      doc.points[all_vertices.size()+ip].data = bb[ip];
    }

  /// Use "fast" inhouse recursive algo to generate the triangulation
  /// At this stage the triangulation is not what we need
  ///   -) It does not necessary recover the boundaries 
  ///   -) It contains triangles outside the domain (the first edge loop is the outer one)
  Msg(DEBUG1,"Meshing of the convex hull (%d points)",all_vertices.size());
  Make_Mesh_With_Points(&doc,doc.points,all_vertices.size()+4);

  // Buid a BDS_Mesh structure that is convenient for doing the actual meshing procedure

  BDS_Mesh *m = new BDS_Mesh;
  m->scalingU = 1;
  m->scalingV = 1;

  for(int i = 0; i < doc.numPoints; i++) 
    {
      MVertex *here = (MVertex *)doc.points[i].data;
      int num = here->getNum();

      double U, V;
      // This test was missing in 2.0.0 and led to the seemingly
      // random Windows/Mac slowdowns (we were passing random numbers
      // to curve interpolation, and straight line interpol does
      // "while(not in bounds) i--" which would take forever to get
      // back into a reasonnable interval)
      if(num < 0){ // fake bbox points 
	U = V = 0;
      }
      else{
	U = U_[num];
	V = V_[num];
      }

      BDS_Point *pp = m->add_point ( num, U,V, gf);
      //      printf("here->onWhat = %p dim = %d\n",here->onWhat(),here->onWhat()->dim());

       if (here->onWhat()->dim() == 1)
 	{
 	  double t;
 	  here->getParameter(0,t);
 	  pp->lc() = BGM_MeshSize ( here->onWhat(), t, 0, here->x(),here->y(),here->z());
 	}
       else
	 pp->lc() = BGM_MeshSize ( here->onWhat(), U, V, here->x(),here->y(),here->z());
    }

  Msg(DEBUG1,"Meshing of the convex hull (%d points) done",all_vertices.size());

  for(int i = 0; i < doc.numTriangles; i++) 
    {
      MVertex *V1 = (MVertex*)doc.points[doc.delaunay[i].t.a].data;
      MVertex *V2 = (MVertex*)doc.points[doc.delaunay[i].t.b].data;
      MVertex *V3 = (MVertex*)doc.points[doc.delaunay[i].t.c].data;
      m->add_triangle ( V1->getNum(), V2->getNum(), V3->getNum() );
    }  
  // Free stuff
  free (doc.points);
  free (doc.delaunay);
  for ( int ip = 0 ; ip<4 ; ip++ ) delete bb[ip];


//   sprintf(name,"real%d.pos",gf->tag());
//   outputScalarField(m->triangles, name,0);

  // Recover the boundary edges
  // and compute characteristic lenghts using mesh edge spacing

  BDS_GeomEntity CLASS_F (1,2);
   
  it = edges.begin();
  while(it != edges.end())
    {
    if(!(*it)->is_mesh_degenerated()){
      if (!recover_medge ( m, *it))
	{
	  Msg(GERROR,"Face not meshed");
	  return false;
	}
    }
      ++it;
    }
  //  Msg(INFO,"Boundary Edges recovered for surface %d",gf->tag());
  // Look for an edge that is on the boundary for which one of the
  // two neighbors has a negative number node. The other triangle
  // is inside the domain and, because all edges were recovered, 
  // triangles inside the domain can be recovered using a  simple
  // recursive algorithm
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end())
      {
	BDS_Edge *e = *ite;
	if ( e->g  && e->numfaces () == 2)
	  {
	    BDS_Point *oface[2];
	    e->oppositeof(oface);
	    if (oface[0]->iD < 0) 
	      {
		recur_tag ( e->faces(1) , &CLASS_F); 
		break;
	      }
	    else if (oface[1]->iD < 0) 
	      {
		recur_tag ( e->faces(0) , &CLASS_F); 
		break;
	      }
	  }
	++ite;
      }
  }


  it = emb_edges.begin();
  while(it != emb_edges.end())
    {
      recover_medge ( m, *it);
      ++it;
    }


  // delete useless stuff
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end())
      {
	BDS_Face *t = *itt;
	if (!t->g)
	  m->del_face (t);
	++itt;
      }
  }
  m->cleanup();
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end())
      {
	BDS_Edge *e = *ite;
	if (e->numfaces() == 0)
	  m->del_edge(e);
	else
	  { 
	    if (!e->g)
	      e->g = &CLASS_F;
	    if (!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree)e->p1->g = e->g;
	    if (!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree)e->p2->g = e->g;
	  }
	++ite;
      }
  }

  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  // start mesh generation
  if (CTX.mesh.algo2d != ALGO_2D_DELAUNAY || gf->geomType() != GEntity::Plane)
    {
      RefineMesh (gf,*m,10);
      OptimizeMesh(gf, *m, 2);
      RefineMesh (gf,*m,-10);
      OptimizeMesh(gf, *m, 2);
      if (gf->meshAttributes.recombine)
	{
	  m->recombineIntoQuads (gf->meshAttributes.recombineAngle,gf);
	}
    }
  //     char name[245];
  //     sprintf(name,"param%d.pos",gf->tag());
  //     outputScalarField(m->triangles, name,1);
  //     sprintf(name,"real%d.pos",gf->tag());
  //     outputScalarField(m->triangles, name,0);
  // fill the small gmsh structures

  {
    std::set<BDS_Point*,PointLessThan>::iterator itp =  m->points.begin(); 
    while (itp != m->points.end())
      {
	BDS_Point *p = *itp;
	if (numbered_vertices.find(p->iD)  == numbered_vertices.end())
	  {
	    MVertex *v = new MFaceVertex (p->X,p->Y,p->Z,gf,p->u,p->v);
	    numbered_vertices[p->iD]=v;
	    gf->mesh_vertices.push_back(v);
	  }
	++itp;
      }
  }

  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end())
      {
	BDS_Face *t = *itt;
	if (!t->deleted)
	  {
	    BDS_Point *n[4];
	    t->getNodes(n);
	    MVertex *v1 = numbered_vertices[n[0]->iD];
	    MVertex *v2 = numbered_vertices[n[1]->iD];
	    MVertex *v3 = numbered_vertices[n[2]->iD];
	    if (!n[3])
	      gf->triangles.push_back(new MTriangle (v1,v2,v3) );	
	    else
	      {
		MVertex *v4 = numbered_vertices[n[3]->iD];
		gf->quadrangles.push_back(new MQuadrangle (v1,v2,v3,v4) );	
	      }
	  }
	++itt;
      }
  }

  // the delaunay algo is based directly on internal gmsh structures
  // BDS mesh is passed in order not to recompute local coordinates
  // of vertices
  if (CTX.mesh.algo2d == ALGO_2D_DELAUNAY && gf->geomType() == GEntity::Plane)
     {
       insertVerticesInFace (gf,m) ;
     }

  // delete the mesh

  if (debug){
    char name[256];
    sprintf(name,"real%d.pos",gf->tag());
    outputScalarField(m->triangles, name,0);
    sprintf(name,"param%d.pos",gf->tag());
    outputScalarField(m->triangles, name,1);
  }
  delete m;


  delete [] U_;
  delete [] V_;

  return true;

}

// this function buils a list of vertices (BDS) that 
// are consecutive in one given edge loop. We take
// care of periodic surfaces. In the case of periodicity, some
// curves are present 2 times in the wire (seams). Those
// must be meshed separately

inline double dist2 (const SPoint2 &p1,const SPoint2 &p2)
{
  const double dx = p1.x() - p2.x(); 
  const double dy = p1.y() - p2.y(); 
  return dx*dx+dy*dy;
}

bool buildConsecutiveListOfVertices (  GFace *gf,
				       GEdgeLoop  &gel , 
				       std::vector<BDS_Point*> &result,
				       SBoundingBox3d &bbox,
				       BDS_Mesh *m,
				       std::map<BDS_Point*,MVertex*> &recover_map, 
				       int &count)
{

  // for each edge, we build a list of points that 
  // are the mapping of the edge points on the face
  // for seams, we build the list for every side
  // for closed loops, we build it on both senses

  //  printf("new edge loop\n");
  std::map<GEntity*,std::vector<SPoint2> > meshes;
  std::map<GEntity*,std::vector<SPoint2> > meshes_seam;
  
  GEdgeLoop::iter it  = gel.begin();  

  while (it != gel.end())   
   {
     GEdgeSigned ges = *it ;
      
     std::vector<SPoint2> mesh1d;
     std::vector<SPoint2> mesh1d_seam;

     bool seam = ges.ge->isSeam(gf);
     
     //     printf("face %d edge %d seam %d (%d %d)\n",gf->tag(),ges.ge->tag(),seam,ges.ge->getBeginVertex()->tag(),ges.ge->getEndVertex()->tag());
     
     Range<double> range = ges.ge->parBounds(0);

     MVertex *here = ges.ge->getBeginVertex()->mesh_vertices[0];
     mesh1d.push_back(ges.ge->reparamOnFace(gf,range.low(),1));
     if ( seam ) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf,range.low(),-1));
     for (unsigned int i=0;i<ges.ge->mesh_vertices.size();i++)
       {
	 double u;
	 here = ges.ge->mesh_vertices[i];
	 here->getParameter(0,u);
	 mesh1d.push_back(ges.ge->reparamOnFace(gf,u,1));
	 if ( seam ) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf,u,-1));
       }
     here = ges.ge->getEndVertex()->mesh_vertices[0];
     mesh1d.push_back(ges.ge->reparamOnFace(gf,range.high(),1));
     if ( seam ) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf,range.high(),-1));
     meshes.insert(std::pair<GEntity*,std::vector<SPoint2> > (ges.ge,mesh1d) );
     if(seam)meshes_seam.insert(std::pair<GEntity*,std::vector<SPoint2> > (ges.ge,mesh1d_seam) );     
     it++;
   }


  std::list<GEdgeSigned> unordered;
  unordered.insert(unordered.begin(),gel.begin(),gel.end());
  
  GEdgeSigned found(0,0);

  SPoint2 last_coord(0,0);  
  int counter = 0;

  double tol = 1.e-7;

  while (unordered.size())
   {
     std::list<GEdgeSigned>::iterator it = unordered.begin();     
     std::vector<SPoint2>  coords;

     while (it != unordered.end())   
       {
	 std::vector<SPoint2>  mesh1d;
	 std::vector<SPoint2>  mesh1d_seam;
	 std::vector<SPoint2>  mesh1d_reversed;
	 std::vector<SPoint2>  mesh1d_seam_reversed;
	 GEdge *ge = (*it).ge;
	 bool seam = ge->isSeam(gf);
	 mesh1d = meshes[ge];
	 if (seam){mesh1d_seam = meshes_seam[ge];}
	 mesh1d_reversed.insert(mesh1d_reversed.begin(),mesh1d.rbegin(),mesh1d.rend());
	 if (seam)mesh1d_seam_reversed.insert(mesh1d_seam_reversed.begin(),mesh1d_seam.rbegin(),mesh1d_seam.rend());
	 if (!counter)
	   {
	     counter++;
	     coords = ((*it)._sign == 1)?mesh1d:mesh1d_reversed;	 
	     found = (*it);
	     unordered.erase(it);
	     break;
	   }
	 else
	   {
	     SPoint2 first_coord         = mesh1d[0];
	     double d = dist2(last_coord,first_coord);
	     //	     printf("d = %12.5E %d\n",d, coords.size());
	     if (d < tol) 
	       {
		 coords.clear();
		 coords = mesh1d;
		 found = GEdgeSigned(1,ge);
		 unordered.erase(it);
		 goto Finalize;
	       }
	     SPoint2 first_coord_reversed = mesh1d_reversed[0];
	     double d_reversed = dist2(last_coord,first_coord_reversed);
	     //	     printf("d_r = %12.5E\n",d_reversed);
	     if (d_reversed < tol) 
	       {
		 //		 printf("d_r = %12.5E\n",d_reversed);
		 coords.clear();
		 coords = mesh1d_reversed;
		 found = (GEdgeSigned(-1,ge));
		 unordered.erase(it);
		 goto Finalize;
	       }
	     if (seam)
	       {
		 SPoint2 first_coord_seam         = mesh1d_seam[0];
		 SPoint2 first_coord_seam_reversed = mesh1d_seam_reversed[0];
		 double d_seam = dist2(last_coord,first_coord_seam);
		 //		 printf("d_seam = %12.5E\n",d_seam);
		 if (d_seam < tol)
		   {
		     coords.clear();
		     coords = mesh1d_seam;
		     found = (GEdgeSigned(1,ge));
		     unordered.erase(it);
		     goto Finalize;
		   }
		 double d_seam_reversed = dist2(last_coord,first_coord_seam_reversed);
		 //		 printf("d_seam_reversed = %12.5E\n",d_seam_reversed);
		 if (d_seam_reversed < tol)
		   {
		     coords.clear();
		     coords = mesh1d_seam_reversed;
		     found = (GEdgeSigned(-1,ge));
		     unordered.erase(it);
		     break;
		     goto Finalize;
		   }
	       }
	   }
	 ++it;
       }
   Finalize:



     if (coords.size() == 0)return false;
     
     std::vector<MVertex*>    edgeLoop;
     if ( found._sign == 1)
       {
	 edgeLoop.push_back(found.ge->getBeginVertex()->mesh_vertices[0]);
	 for (unsigned int i=0;i<found.ge->mesh_vertices.size();i++)
	   edgeLoop.push_back(found.ge->mesh_vertices[i]);
       }
     else
       {
	 edgeLoop.push_back(found.ge->getEndVertex()->mesh_vertices[0]);
	 for (int i=found.ge->mesh_vertices.size()-1;i>=0;i--)	    
	   edgeLoop.push_back(found.ge->mesh_vertices[i]);
       }
     
     //     printf("edge %d size %d size %d\n",found.ge->tag(),edgeLoop.size(), coords.size());
     
     std::vector<BDS_Point*>  edgeLoop_BDS;
     for (unsigned int i=0;i<edgeLoop.size();i++)	    
       {
	 MVertex *here     = edgeLoop[i];
	 GEntity *ge       = here->onWhat();    
	 double U,V;
	 SPoint2 param = coords [i];
	 U = param.x() / m->scalingU ;
	 V = param.y() / m->scalingV;
	 BDS_Point *pp;
	 pp = m->add_point ( count, U,V,gf );
	 if(ge->dim() == 1)
	   {
	     double t;
	     here->getParameter(0,t);
	     pp->lc() = BGM_MeshSize(ge,t,-12,here->x(),here->y(),here->z());
	   }
	 else
	   {
	     pp->lc() = BGM_MeshSize(ge,param.x(),param.y(),here->x(),here->y(),here->z());
	   }

	 m->add_geom (ge->tag(), ge->dim());
	 BDS_GeomEntity *g = m->get_geom(ge->tag(),ge->dim());
	 pp->g = g;
	 //	 printf("point %3d (%8.5f %8.5f) (%2d,%2d)\n",count,pp->u,pp->v,pp->g->classif_tag,pp->g->classif_degree);
	 bbox += SPoint3(U,V,0);	  
	 edgeLoop_BDS.push_back(pp);
	 recover_map[pp] = here;	 
	 count++;
       }     
     last_coord = coords[coords.size()-1];
     //     printf("last coord %g %g\n",last_coord.x(),last_coord.y());
     result.insert(result.end(),edgeLoop_BDS.begin(),edgeLoop_BDS.end());	         
//    for (unsigned int i=0;i<result.size();i++)
//      {
//        printf("point %3d (%8.5f %8.5f) (%2d,%2d)\n",i,result[i]->u,result[i]->v,result[i]->g->classif_tag,result[i]->g->classif_degree);
//      }

   }

//   if (gf->tag() == 280)
//     for (unsigned int i=0;i<result.size();i++)
//       {
//         printf("point %3d (%8.5f %8.5f) (%2d,%2d)\n",i,result[i]->u,result[i]->v,result[i]->g->classif_tag,result[i]->g->classif_degree);
//       }

  return true;
}




bool gmsh2DMeshGeneratorPeriodic ( GFace *gf , bool debug = true)
{
  //  if(gf->tag() != 6)return true;


  std::map<BDS_Point*,MVertex*> recover_map;

  Range<double> rangeU = gf->parBounds(0);
  Range<double> rangeV = gf->parBounds(1);
  
  const double du = rangeU.high() -rangeU.low();
  const double dv = rangeV.high() -rangeV.low();
  
  const double LC2D = sqrt ( du*du + dv*dv ); 

  //  printf("LC2D %g (%g,%g), (%g,%g)\n",LC2D,rangeU.high(),rangeU.low(),rangeV.high(),rangeV.low());

  // Buid a BDS_Mesh structure that is convenient for doing the actual meshing procedure    
  BDS_Mesh *m = new BDS_Mesh;
   m->scalingU = fabs(du);
   m->scalingV = fabs(dv);
   SCALINGU = m->scalingU;
   SCALINGV = m->scalingV;
  std::vector< std::vector<BDS_Point* > > edgeLoops_BDS;
  SBoundingBox3d bbox;
  int nbPointsTotal = 0;
  {
    for (std::list<GEdgeLoop>::iterator it = gf->edgeLoops.begin() ; it != gf->edgeLoops.end() ; it++)
      {
	std::vector<BDS_Point* > edgeLoop_BDS;
	if(buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsTotal)==false)return false;
	edgeLoops_BDS.push_back(edgeLoop_BDS);
      }
  }

  // build a point record structure to create the initial mesh
  DocRecord doc;  
  doc.points =  (PointRecord*)malloc((nbPointsTotal+4) * sizeof(PointRecord));
  int count = 0;
  for (unsigned int i=0;i<edgeLoops_BDS.size();i++)
    {
      std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
      for (unsigned int j=0;j<edgeLoop_BDS.size();j++)
	{
	  BDS_Point *pp = edgeLoop_BDS[j];
	  const double U = pp->u;
	  const double V = pp->v;
	  double XX = CTX.mesh.rand_factor * LC2D *
	    (double)rand() / (double)RAND_MAX;
	  double YY = CTX.mesh.rand_factor * LC2D *
	    (double)rand() / (double)RAND_MAX;
	  doc.points[count].where.h = U + XX;
	  doc.points[count].where.v = V + YY;
	  doc.points[count].adjacent = NULL;
	  doc.points[count].data = pp;      
	  count++;	  
	}
    }
  /// Increase the size of the bounding box by 20 %
  /// add 4 points than encloses the domain
  /// Use negative number to distinguish thos fake vertices
  bbox *= 3.5;

  MVertex *bb[4];
  bb[0] = new MVertex ( bbox.min().x(), bbox.min().y(), 0,0,-1);
  bb[1] = new MVertex ( bbox.min().x(), bbox.max().y(), 0,0,-2);
  bb[2] = new MVertex ( bbox.max().x(), bbox.min().y(), 0,0,-3);
  bb[3] = new MVertex ( bbox.max().x(), bbox.max().y(), 0,0,-4);
  
  for ( int ip = 0 ; ip<4 ; ip++ )
    {
      BDS_Point *pp = m->add_point ( -ip-1, bb[ip]->x(),bb[ip]->y(), gf);
      m->add_geom (gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(),2);
      pp->g = g;
      doc.points[nbPointsTotal+ip].where.h  = bb[ip]->x();
      doc.points[nbPointsTotal+ip].where.v  = bb[ip]->y();
      doc.points[nbPointsTotal+ip].adjacent = 0;
      doc.points[nbPointsTotal+ip].data = pp;
    }

  for ( int ip = 0 ; ip<4 ; ip++ ) delete bb[ip];
  
  /// Use "fast" inhouse recursive algo to generate the triangulation
  /// At this stage the triangulation is not what we need
  ///   -) It does not necessary recover the boundaries 
  ///   -) It contains triangles outside the domain (the first edge loop is the outer one)
  Msg(DEBUG1,"Meshing of the convex hull (%d points)",nbPointsTotal);
  Make_Mesh_With_Points(&doc,doc.points,nbPointsTotal+4);
  for(int i = 0; i < doc.numTriangles; i++) 
    {
      BDS_Point *p1 = (BDS_Point*)doc.points[doc.delaunay[i].t.a].data;
      BDS_Point *p2 = (BDS_Point*)doc.points[doc.delaunay[i].t.b].data;
      BDS_Point *p3 = (BDS_Point*)doc.points[doc.delaunay[i].t.c].data;
      m->add_triangle ( p1->iD,p2->iD,p3->iD);
    }  
  // Free stuff
  free (doc.points);
  free (doc.delaunay);


 
  // Recover the boundary edges
  // and compute characteristic lenghts using mesh edge spacing
    
  BDS_GeomEntity CLASS_F (1,2);
  BDS_GeomEntity CLASS_E (1,1);
  

  if (debug)
    {
      char name[245];
      sprintf(name,"surface%d-initial-real.pos",gf->tag());
      outputScalarField(m->triangles, name,0);
      sprintf(name,"surface%d-initial-param.pos",gf->tag());
      outputScalarField(m->triangles, name,1);
    }


  for (unsigned int i=0;i<edgeLoops_BDS.size();i++)
    {
      std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
      for (unsigned int j=0;j<edgeLoop_BDS.size();j++)
	{
	  BDS_Edge * e = m->recover_edge ( edgeLoop_BDS[j]->iD,edgeLoop_BDS[(j+1)%edgeLoop_BDS.size()]->iD);	  
	  if (!e)
	    {
	      Msg(GERROR,"impossible to recover the edge %d %d",edgeLoop_BDS[j]->iD,edgeLoop_BDS[(j+1)%edgeLoop_BDS.size()]->iD);
	      SCALINGU = SCALINGV = 1;
	      return false;
	    }
	  else e->g = &CLASS_E;
	}
    }	  
  
  //  Msg(INFO,"Boundary Edges recovered for surface %d",gf->tag());
  // Look for an edge that is on the boundary for which one of the
  // two neighbors has a negative number node. The other triangle
  // is inside the domain and, because all edges were recovered, 
  // triangles inside the domain can be recovered using a  simple
  // recursive algorithm
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end())
      {
	BDS_Edge *e = *ite;
	if ( e->g  && e->numfaces () == 2)
	  {
	    BDS_Point *oface[2];
	    e->oppositeof(oface);
	    if (oface[0]->iD < 0) 
	      {
		recur_tag ( e->faces(1) , &CLASS_F); 
		break;
	      }
	    else if (oface[1]->iD < 0) 
	      {
		recur_tag ( e->faces(0) , &CLASS_F); 
		break;
	      }
	    }
	++ite;
      }
  }

  // delete useless stuff
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end())
      {
	BDS_Face *t = *itt;
	if (!t->g)
	  {
	    m->del_face (t);
	  }
	++itt;
      }
  }

  m->cleanup();

  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end())
      {
	BDS_Edge *e = *ite;
	if (e->numfaces() == 0)
	  m->del_edge(e);
	else
	  { 
	    if (!e->g)
	      e->g = &CLASS_F;
	    if (!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree)e->p1->g = e->g;
	    if (!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree)e->p2->g = e->g;
	  }
	++ite;
      }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));
    

  if (debug)
    {
      char name[245];
      sprintf(name,"surface%d-recovered-real.pos",gf->tag());
      outputScalarField(m->triangles, name,0);
      sprintf(name,"surface%d-recovered-param.pos",gf->tag());
      outputScalarField(m->triangles, name,1);
    }

  // goto hhh;
  // start mesh generation
  
  //  if (CTX.mesh.algo2d == ALGO_2D_MESHADAPT)
    {
      RefineMesh (gf,*m,10);
      OptimizeMesh(gf, *m, 2);
      RefineMesh (gf,*m,-10);
      OptimizeMesh(gf, *m, 2);

      if (gf->meshAttributes.recombine)
	{
	  m->recombineIntoQuads (gf->meshAttributes.recombineAngle,gf);
	}
    }
  // fill the small gmsh structures
  

  {
    std::set<BDS_Point*,PointLessThan>::iterator itp =  m->points.begin(); 
    while (itp != m->points.end())
      {
	BDS_Point *p = *itp;
	if (recover_map.find(p) == recover_map.end())
	  {
	    MVertex *v = new MFaceVertex (p->X,p->Y,p->Z,gf,SCALINGU*p->u,SCALINGV*p->v);
	    recover_map[p] = v;
	    gf->mesh_vertices.push_back(v);
	  }
	++itp;
      }
  }
  
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end())
      {
	BDS_Face *t = *itt;
	if (!t->deleted)
	  {
	    BDS_Point *n[4];
	    t->getNodes(n);
	    MVertex *v1 = recover_map[n[0]];
	    MVertex *v2 = recover_map[n[1]];
	    MVertex *v3 = recover_map[n[2]];
	    if (!n[3])
	      {
		// when a singular point is present, degenerated triangles may be created,
		// for example on a sphere that contains one pole 
		if (v1 != v2 && v1 != v3 && v2 != v3)
		  gf->triangles.push_back(new MTriangle (v1,v2,v3) );	
	      }
	    else
	      {
		MVertex *v4 = recover_map[n[3]];
		gf->quadrangles.push_back(new MQuadrangle (v1,v2,v3,v4) );	
	      }
	  }
	++itt;
      }
  }
  
  
  // delete the mesh
  if (debug)
    {
      char name[245];
      sprintf(name,"surface%d-final-real.pos",gf->tag());
      outputScalarField(m->triangles, name,0);
      sprintf(name,"surface%d-final-param.pos",gf->tag());
      outputScalarField(m->triangles, name,1);
    }

//   if (CTX.mesh.algo2d == ALGO_2D_DELAUNAY)
//     {
//       insertVerticesInFace (gf,m) ;
//     }

  
  delete m; 
  SCALINGU = SCALINGV = 1;
  return true;
}

void deMeshGFace::operator() (GFace *gf) 
{
  if(gf->geomType() == GEntity::DiscreteSurface) return;

  for (unsigned int i=0;i<gf->mesh_vertices.size();i++) delete gf->mesh_vertices[i];
  gf->mesh_vertices.clear();
  gf->transfinite_vertices.clear();
  for (unsigned int i=0;i<gf->triangles.size();i++) delete gf->triangles[i];
  gf->triangles.clear();
  for (unsigned int i=0;i<gf->quadrangles.size();i++) delete gf->quadrangles[i];
  gf->quadrangles.clear();
  if(gf->meshRep) gf->meshRep->destroy();
}

void meshGFace::operator() (GFace *gf) 
{  
  if(gf->geomType() == GEntity::DiscreteSurface) return;
  if(gf->geomType() == GEntity::BoundaryLayerSurface) return;
  if(gf->geomType() == GEntity::ProjectionSurface) return;

  // destroy the mesh if it exists
  deMeshGFace dem;
  dem(gf);

  if(MeshTransfiniteSurface(gf)) return;
  if(MeshExtrudedSurface(gf)) return;

  char *algo = "Unknown";
  switch(CTX.mesh.algo2d){
  case ALGO_2D_MESHADAPT: 
    algo = "MeshAdapt";
    break;
  case ALGO_2D_DELAUNAY: 
    // FIXME: Delaunay not available in all cases at the moment
    if(gf->geomType() == GEntity::Plane && 
       (gf->getNativeType() == GEntity::GmshModel || gf->edgeLoops.empty()))
      algo = "Delaunay";
    else
      algo = "MeshAdapt+Delaunay";
    break;
  case ALGO_2D_MESHADAPT_DELAUNAY: 
    algo = "MeshAdapt+Delaunay"; 
    break;
  }
  
  Msg(STATUS2, "Meshing surface %d (%s, %s)", gf->tag(),
      gf->getTypeString().c_str(), algo);

  // compute loops on the fly (indices indicate start and end points
  // of a loop; loops are not yet oriented)
  Msg(DEBUG1, "Computing edge loops");
  std::vector<MVertex*> points;
  std::vector<int> indices;
  computeEdgeLoops(gf, points, indices);

  // temp fix until we create MEdgeLoops in gmshFace
  Msg(DEBUG1, "Generating the mesh");
  if(gf->getNativeType() == GEntity::GmshModel || gf->edgeLoops.empty()){
    gmsh2DMeshGenerator(gf,false);
  }
  else{
    if(!gmsh2DMeshGeneratorPeriodic(gf,false))
      Msg(GERROR, "Impossible to mesh face %d", gf->tag());
  }
  
  Msg(DEBUG1, "type %d %d triangles generated, %d internal vertices",
      gf->geomType(), gf->triangles.size(), gf->mesh_vertices.size());
}  

template<class T>
bool shouldRevert(MEdge &reference, std::vector<T*> &elements)
{
  for(unsigned int i = 0; i < elements.size(); i++){
    for(int j = 0; j < elements[i]->getNumEdges(); j++){
      MEdge e = elements[i]->getEdge(j);
      if(e.getVertex(0) == reference.getVertex(0) &&
	 e.getVertex(1) == reference.getVertex(1)){
	return false;
      }
      else if(e.getVertex(1) == reference.getVertex(0) && 
	      e.getVertex(0) == reference.getVertex(1)){
	return true;
      }
    }
  }
  return false;
}

void orientMeshGFace::operator()(GFace *gf)
{
  if(gf->geomType() == GEntity::ProjectionSurface) return;

  // surface orientions in OCC are not consistent with the orientation
  // of the bounding edges, so just leave them unchanged:
  if(gf->getNativeType() == GEntity::OpenCascadeModel) return;

  // in old versions we did not reorient transfinite surface meshes;
  // we could add the following to provide backward compatibility:
  // if(gf->meshAttributes.Method == TRANSFINI) return;

  // orients the mesh to match the orientation of the first edge
  std::list<GEdge*> edges = gf->edges();
  std::list<int> ori = gf->orientations();
  if(edges.empty() || ori.empty()) return;
  GEdge *ge = *edges.begin();
  GVertex *beg = ge->getBeginVertex();
  GVertex *end = ge->getEndVertex();
  if(!beg || beg->mesh_vertices.empty() || !end || end->mesh_vertices.empty()) return;
  MVertex *v1 = beg->mesh_vertices[0];
  MVertex *v2 = ge->mesh_vertices.empty() ? end->mesh_vertices[0] : ge->mesh_vertices[0];
  int sign = *ori.begin();
  MEdge ref(sign > 0 ? v1 : v2, sign > 0 ? v2 : v1);
  if(shouldRevert(ref, gf->triangles) || shouldRevert(ref, gf->quadrangles)){
    Msg(DEBUG1, "Reverting orientation of mesh in face %d", gf->tag());
    for(unsigned int i = 0; i < gf->triangles.size(); i++)
      gf->triangles[i]->revert();
    for(unsigned int i = 0; i < gf->quadrangles.size(); i++)
      gf->quadrangles[i]->revert();
  }
}
