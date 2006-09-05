// $Id: meshGFace.cpp,v 1.11 2006-09-05 21:37:59 remacle Exp $
//
// Copyright (C) 1997-2006 C. Geuzaine, J.-F. Remacle
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
#include "GVertex.h"
#include "2D_Mesh.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "Utils.h"
#include "GPoint.h"
#include "Message.h"
#include "Numeric.h"
#include "BDS.h"

extern Context_T CTX;

int Orientation (std::vector<MVertex*> &cu)
{
  int N, i, a, b, c;
  double cosa, sina, sum, v[3], w[3], u[3];
  MVertex *ver[3];
  double n[3] = {0,0,1};

  N = cu.size();

  sum = 0.0;
  for(i = 0; i < N; i++) {
    if(i == N - 1) {
      a = N - 1;
      b = 1;
      c = 2;
    }
    else if(i == N - 2) {
      a = N - 2;
      b = N - 1;
      c = 1;
    }
    else {
      a = i;
      b = i + 1;
      c = i + 2;
    }
    ver[0] = cu[a];
    ver[1] = cu[b];
    ver[2] = cu[c];

    u[0] = ver[1]->x() - ver[0]->x();
    u[1] = ver[1]->y() - ver[0]->y();
    u[2] = ver[1]->z() - ver[0]->z();

    v[0] = ver[2]->x() - ver[1]->x();
    v[1] = ver[2]->y() - ver[1]->y();
    v[2] = ver[2]->z() - ver[1]->z();
    norme(u);
    norme(v);
    prodve(u, v, w);
    prosca(w, n, &sina);
    prosca(u, v, &cosa);
    sum += myatan2(sina, cosa);
  }

  if(sum < 0)
    return (1);
  else
    return (0);
}



class fromCartesianToParametric
{
  GFace *gf;
public :
  fromCartesianToParametric ( GFace *_gf )  
    : gf(_gf){}
  void operator () (MVertex * v)
  {
    SPoint2 param =  gf->parFromPoint (SPoint3(v->x(),v->y(),v->z()));
    v->x() = param.x();  
    v->y() = param.y();
    v->z() = 0.0;
  }
};

fromParametricToCartesian::fromParametricToCartesian ( GFace *_gf )  
  : gf(_gf)
{
}

void fromParametricToCartesian::operator () (MVertex * v)
{
  GPoint coords =  gf->point (SPoint2(v->x(),v->y()));
  v->x() = coords.x();  
  v->y() = coords.y();
  v->z() = coords.z();
} 

void computeEdgeLoops (const GFace *gf,
		       std::vector<MVertex*> & all_mvertices,
		       std::vector<int> &indices)
{
  {
    std::list<GEdge*> edges = gf->edges();
    std::list<int> ori   = gf->orientations();
    std::list<GEdge*>::iterator it = edges.begin();
    std::list<int>::iterator ito    = ori.begin();
    
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
    while(1)
      {		
	++it;
	++ito;
	if (v_end == start)
	  {
	    indices.push_back(all_mvertices.size());
	    if (it == edges.end ())break;
	    start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	    v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	    v_start = start;
	  }
	else
	  {	
	    if (it == edges.end ())throw;
	    v_start = ((*ito) == 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	    if(v_start != v_end)throw;
	    v_end = ((*ito) != 1) ? (*it)->getBeginVertex() : (*it)->getEndVertex();
	  }
	all_mvertices.push_back(v_start->mesh_vertices[0]);
	if (*ito == 1)
	  for (unsigned int i=0;i<(*it)->mesh_vertices.size();i++)
	    all_mvertices.push_back((*it)->mesh_vertices[i]);
	else
	  for (int i=(*it)->mesh_vertices.size()-1;i>=0;i--)
	    all_mvertices.push_back((*it)->mesh_vertices[i]);
      }
  }  

}

extern double F_LC_ANALY (double xx, double yy, double zz);

double NewGetLc ( BDS_Point *p  )
{
  //  const double curv = p->radius();
  //  if (curv == 0.0)
    return p->lc();
    //  else
    //    return std::min(p->lc(),1./(2*curv));
  return  F_LC_ANALY(p->X,p->Y,p->Z);
  if(BGMExists())
    {	    
      double l_bgm = BGMXYZ(p->X,p->Y,p->Z);
      return l_bgm;
    }
}

inline double computeEdgeLinearLength ( BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->X-p2->X;
  const double dy = p1->Y-p2->Y;
  const double dz = p1->Z-p2->Z;
  const double l = sqrt (dx*dx+dy*dy+dz*dz);
  return l;
}

double NewGetLc ( BDS_Edge *e  )
{
  double linearLength = e->length();
  double l1 = NewGetLc ( e->p1  );
  double l2 = NewGetLc ( e->p2  );
  return 2*linearLength / (l1 + l2);
}


bool edgeSwapTest(BDS_Edge *e)
{
   BDS_Point *op[2];

   if (!e->p1->config_modified && ! e->p2->config_modified) return false;   

  if (e->numfaces() != 2)return false;

  e->oppositeof (op);
  
  double edgeLength1, edgeLength2;

  edgeLength1 = e->length();
  edgeLength2 = computeEdgeLinearLength ( op[0],op[1]);
  double lp1 =  NewGetLc ( e->p1 );
  double lp2 =  NewGetLc ( e->p1 );
  double lo1 =  NewGetLc ( op[0] );
  double lo2 =  NewGetLc ( op[1] );


  double el1 = 2*edgeLength1 / ( lp1 + lp2 );
  double el2 = 2*edgeLength2 / ( lo1 + lo2 );

  double q1  = fabs (1-el1);
  double q2  = fabs (1-el2);

  return q2 < 0.5*q1;
//  BDS_Point *op[2];

//   if (e->numfaces() != 2)return false;

//   e->oppositeof (op);

//   double qa1 = quality_triangle ( e->p1 , e->p2 , op[0] );
//   double qa2 = quality_triangle ( e->p1 , e->p2 , op[1] );
//   double qb1 = quality_triangle ( e->p1 , op[0] , op[1] );
//   double qb2 = quality_triangle ( e->p2 , op[0] , op[1] );
//   double qa = (qa1<qa2)?qa1:qa2; 
//   double qb = (qb1<qb2)?qb1:qb2; 
  
//   return (qb > 1.1*qa);
}


void OptimizeMesh ( GFace *gf, BDS_Mesh &m , const int NIT)
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
	  if ((t.size()==3 && (*itp)->edges.size() == 3)||
	      (t.size()==4 && (*itp)->edges.size() == 4))
	    m.collapse_edge_parametric ( *(*itp)->edges.begin(), (*itp));
	  else
	    m.smooth_point_parametric(*itp,gf);
	  ++itp;
	}
    }
    {
      // swap edges that provide a better configuration
      int NN1 = m.edges.size();
      int NN2 = 0;
      std::list<BDS_Edge*>::iterator it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (!(*it)->deleted && (*it)->numfaces() == 2)
	    {
	      BDS_Point *op[2];
	      (*it)->oppositeof(op);
	      
	      bool c1 = (op[0]-> edges.size() == 5 &&  op[1]-> edges.size() == 5 );
	      bool c2 =  ((*it)->p1-> edges.size() == 7 &&  (*it)->p2-> edges.size() == 7); 
	      if ( c1 &&  c2 ) 
		m.swap_edge ( *it , BDS_SwapEdgeTestParametric());
	    }	
	  ++it;
	}
    }
    m.cleanup();  
  }
}

void RefineMesh ( GFace *gf, BDS_Mesh &m , const int NIT)
{
  int NUMP = 0;
  int IT =0;

  int MAXNP = m.MAXPOINTNUMBER;

  clock_t t1 = clock();

  // computecharacteristic lengths using mesh edge spacing
  
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while (itp != m.points.end())
    {
      std::list<BDS_Edge*>::iterator it  = (*itp)->edges.begin();
      std::list<BDS_Edge*>::iterator ite = (*itp)->edges.end();
      double L = 1.e245;
      while(it!=ite){
	double l = (*it)->length();
	if (l<L && (*it)->g && (*it)->g->classif_degree == 1)L=l;
	++it;
      }
      (*itp)->lc() = L;
      ++itp;
    }


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
	      double lone = NewGetLc ( *it);
	      maxL = std::max(maxL,lone);
	      minL = std::min(minL,lone);
	    }
	  ++it;
	}

      //      Msg(STATUS2," %d triangles : conv %g -> %g (%g sec)",m.triangles.size(),maxL,1.5,(double)(clock()-t1)/CLOCKS_PER_SEC);
      if ((minL > 0.4 && maxL < 1.5) || IT > NIT)break;


      NN1 = m.edges.size();
      NN2 = 0;
      it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (!(*it)->deleted)
	    {
	      double lone = NewGetLc ( *it);
	      if ((*it)->numfaces() == 2 && (lone >  1.3))
		{
		  BDS_Point *mid ;
		  double coord = 0.5;
		  mid  = m.add_point(++m.MAXPOINTNUMBER,
				     coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u,
				     coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v,gf);
		  mid->lc() = 0.5 * ( (*it)->p1->lc() +  (*it)->p2->lc() );
		  m.split_edge ( *it, mid );
		  nb_split++;
		} 
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
	  if (!(*it)->deleted && edgeSwapTest(*it))
	    if (m.swap_edge ( *it , BDS_SwapEdgeTestParametric()))
	      nb_swap++;
	  ++it;
	}

      // collapse short edges
      NN1 = m.edges.size();
      NN2 = 0;
      it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  double lone = NewGetLc ( *it);
	  if (!(*it)->deleted && (*it)->numfaces() == 2 && lone < 0.6 )
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
	  if (!(*it)->deleted && edgeSwapTest(*it))
	    if (m.swap_edge ( *it , BDS_SwapEdgeTestParametric()))
	      nb_swap++;
	  ++it;
	}
      // smooth resulting mesh
      //if (IT % 4 == 0 )
	{
	  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
	  while (itp != m.points.end())
	    {

	      if(m.smooth_point_parametric(*itp,gf))
		nb_smooth ++;
	      ++itp;
	    }
	}
	IT++;
	//	Msg(INFO," %d split %d swap %d collapse %d smooth",nb_split,nb_swap,nb_collaps,nb_smooth);
	m.cleanup();  
    }  
}

void OldMeshGenerator ( GFace *gf,
			std::vector<MVertex*> &points,
			std::vector<int> &indices, int initialOnly)
{


  // put the loops on the right sense, cause this stupid cannot
  // handle non oriented loops
  int nbEdgeLoops = indices.size()-1;

  for(int i = 0; i < nbEdgeLoops; i++) {
    int nbPtsOnEdgeLoop = indices[i+1] -indices[i];
    std::vector<MVertex*> loop;
    for(int j = indices[i]; j < indices[i+1]; j++)loop.push_back(points[j]);
    //    Msg(INFO, " %d %d %d %d",i,indices[i],indices[i+1],Orientation(loop));
    int k = 0;
    int ori = Orientation(loop);
    if (i == 0 && !ori)
      for(int j = indices[i]; j < indices[i+1]; j++)points[j] = loop [nbPtsOnEdgeLoop-k++-1];
    else if (i != 0 && ori)
      for(int j = indices[i]; j < indices[i+1]; j++)points[j] = loop [nbPtsOnEdgeLoop-k++-1];
  }

  extern PointRecord *gPointArray;

  // FIX THAT !!
  double LC2D = 1;
  if (gf->geomType () == GEntity::Plane)
    {
      SBoundingBox3d bb = gf->bounds();
      SPoint3 _min = bb.min();
      SPoint3 _max = bb.max();
      
      SVector3 diam (_min,_max);
      LC2D = norm(diam);
    }

  //  Msg(INFO, "LC = %g",LC2D);

  maillage M;
  ContourRecord *cp, **liste;
  liste = (ContourPeek *) malloc(nbEdgeLoops * sizeof(ContourPeek));
  for(int i = 0; i < nbEdgeLoops; i++) {
    cp = (ContourRecord *) malloc(sizeof(ContourRecord));
    int nbPtsOnEdgeLoop = indices[i+1] -indices[i];
    cp->oriented_points =
      (PointRecord *) malloc(nbPtsOnEdgeLoop * sizeof(PointRecord));
    cp->perturbations = (MPoint *) malloc( nbPtsOnEdgeLoop * sizeof(MPoint));
    cp->numerocontour = i;
    int k=0;
    //    Msg(INFO, " %d %d %d ",i,indices[i],indices[i+1]);
    for(int j = indices[i]; j < indices[i+1]; j++) {
      MVertex *here     = points[j];
      cp->oriented_points[k].where.h = here->x();
      cp->oriented_points[k].where.v = here->y();
      cp->perturbations[k].h = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;
      cp->perturbations[k].v = CTX.mesh.rand_factor * LC2D *
        (double)rand() / (double)RAND_MAX;      
      cp->oriented_points[k].numcontour = i;

      MVertex *previous = (j == indices[i])?points[indices[i+1]-1] : points[j-1]; 
      MVertex *next     = (j == indices[i+1]-1)?points[indices[i]] : points[j+1];

      double lc = 0.5 * ( sqrt ( (here->x() - previous->x())*(here->x() - previous->x()) +
				 (here->y() - previous->y())*(here->y() - previous->y()) ) +
			  sqrt ( (here->x() - next->x())*(here->x() - next->x()) +
				 (here->y() - next->y())*(here->y() - next->y()) ) );		   
      
      //            Msg(INFO, " %g %g %g ",here->x(),here->y(),lc);
      cp->oriented_points[k].quality = lc;
      cp->oriented_points[k].permu = j;
      cp->oriented_points[k].initial = j;
      k++;
    }
    cp->numpoints = nbPtsOnEdgeLoop;
    liste[i] = cp;
  }

  int N;
  int res_mesh_domain = mesh_domain(liste, nbEdgeLoops, &M, &N,initialOnly);

  //  Msg(INFO, "result is %d",res_mesh_domain);
    
  MVertex ** verts_ = new MVertex* [M.numpoints];
  for(int i = 0; i < M.numpoints; i++) {
    //    Msg(INFO, "gpa[%d] = %g %g",i,gPointArray[i].where.h,gPointArray[i].where.v);
    if(gPointArray[i].initial < 0) {
   
      verts_[i]  = new MFaceVertex ( gPointArray[i].where.h,
				     gPointArray[i].where.v, 0.0, gf, 
				     0,0);           
      gf->mesh_vertices.push_back(verts_[i]);
    }
    else
      {
	verts_[i]  = points[gPointArray[i].initial];
      }
  }  
  
  for(int i = 0; i < M.numtriangles; i++) 
    {
      int a = M.listdel[i]->t.a;
      int b = M.listdel[i]->t.b;
      int c = M.listdel[i]->t.c;
      //      Msg(INFO, "tri[%d] = %d %d %d",i,a,b,c);
      gf->triangles.push_back(new MTriangle(verts_[a], verts_[b], verts_[c]));
    }
  
  delete [] verts_;
  if(res_mesh_domain >= 0)
    free(M.listdel);
  free(gPointArray);
  
  for(int i = 0; i < nbEdgeLoops; i++) {
    free(liste[i]->perturbations);
    free(liste[i]->oriented_points);
    free(liste[i]);
  }
  free(liste);
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
  else throw;

  for (int i=1;i<ge->mesh_vertices.size();i++)
    {
      vstart = ge->mesh_vertices[i-1];
      vend   = ge->mesh_vertices[i];
      e = m->recover_edge ( vstart->getNum(), vend->getNum());
      if (e)e->g = g;
      else {
	Msg(GERROR,"Unable to recover an edge %g %g && %g %g (%d/*d)",vstart->x(),vstart->y(), vend->x(),vend->y(),i,ge->mesh_vertices.size());
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
void gmsh2DMeshGenerator ( GFace *gf )
{

  std::set<MVertex*>all_vertices;
  std::map<int, MVertex*>numbered_vertices;
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> emb_edges = gf->emb_edges();
  std::list<GEdge*>::iterator it = edges.begin();
  
  // build a set with all points of the boundaries
  while(it != edges.end())
    {
      all_vertices.insert ( (*it)->mesh_vertices.begin() , (*it)->mesh_vertices.end() );
      all_vertices.insert ( (*it)->getBeginVertex()->mesh_vertices.begin() , (*it)->getBeginVertex()->mesh_vertices.end() );
//       GVertex *v1 = (*it)->getBeginVertex();
//       GVertex *v2 = (*it)->getEndVertex();
//       MVertex *mv1 = *(v1->mesh_vertices.begin());
//       MVertex *mv2 = *(v2->mesh_vertices.begin());
//       Msg(INFO,"%d -> %d = %g %g %g -- %g %g %g",v1->tag(),v2->tag(),v1->x(),v1->y(),v1->z(),v2->x(),v2->y(),v2->z());
//       Msg(INFO,"%g %g %g -- %g %g %g",mv1->x(),mv1->y(),mv1->z(),mv2->x(),mv2->y(),mv2->z());
      all_vertices.insert ( (*it)->getEndVertex()->mesh_vertices.begin() , (*it)->getEndVertex()->mesh_vertices.end() );
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


  double * X_ = new double [all_vertices.size()];
  double * Y_ = new double [all_vertices.size()];
  double * Z_ = new double [all_vertices.size()];

  std::set<MVertex*>::iterator itv = all_vertices.begin();

  //  FILE *fdeb = fopen("debug.dat","w");
  //  fprintf(fdeb,"surface %d\n" ,gf->tag());
  int count = 0;
  while(itv != all_vertices.end())
    {
      MVertex *here     = *itv;
      //    fprintf(fdeb,"%d %g %g %g\n" ,here->getNum(),here->x(),here->y(),here->z());
      X_[count] = here->x();
      Y_[count] = here->y();
      Z_[count] = here->z();
      count ++;
      ++itv;
    }

  //  fclose (fdeb);


  // mesh the domain in the parametric space -> 
  // project all points in their parametric space
  fromCartesianToParametric c2p ( gf );
  std::for_each (all_vertices.begin(),all_vertices.end(),c2p);    

  // compute the bounding box in parametric space
  // I do not have SBoundingBox, so I use a 3D one...
  // At the same time, number the vertices locally
  SBoundingBox3d bbox;
  itv = all_vertices.begin();
  int NUM = 0;
  while(itv != all_vertices.end())
    {
      bbox += SPoint3 ( (*itv)->x() , (*itv)->y() , 0);      
      (*itv)->setNum(NUM++);
      numbered_vertices[(*itv)->getNum()] = *itv;
      ++itv;
    }
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
      doc.points[j].where.h = here->x() + XX;
      doc.points[j].where.v = here->y() + YY;
      doc.points[j].adjacent = NULL;
      doc.points[j].data = here;      
      j++;
      ++itv;
    }


  /// Increase the size of the bounding box by 20 %
  bbox *= 1.5;
  /// add 4 points than encloses the domain
  /// Use negative number to distinguish thos fake vertices
  MVertex *bb[4];
  bb[0] = new MVertex ( bbox.min().x(), bbox.min().y(), 0,0,-1);
  bb[1] = new MVertex ( bbox.min().x(), bbox.max().y(), 0,0,-2);
  bb[2] = new MVertex ( bbox.max().x(), bbox.min().y(), 0,0,-3);
  bb[3] = new MVertex ( bbox.max().x(), bbox.max().y(), 0,0,-4);
    
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
  Make_Mesh_With_Points(&doc,doc.points,all_vertices.size()+4);

  // Buid a BDS_Mesh structure that is convenient for doing the actual meshing procedure

  BDS_Mesh *m = new BDS_Mesh;

  for(int i = 0; i < doc.numPoints; i++) 
    {
      MVertex *here = (MVertex*)doc.points[i].data;      
      BDS_Point *bds_p = m->add_point ( here->getNum(), here->x(), here->y(), gf);
    }
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

  // Recover the boundary edges
  // and compute characteristic lenghts using mesh edge spacing

  BDS_GeomEntity CLASS_F (1,2);
   
  it = edges.begin();
  while(it != edges.end())
    {
      recover_medge ( m, *it);
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

  // goto hhh;
   // start mesh generation

  RefineMesh (gf,*m,20);
  //  OptimizeMesh (gf,*m,2);


  if (gf->meshAttributes.recombine)
    {
      m->recombineIntoQuads (gf->meshAttributes.recombineAngle,gf);
    }

  // fill the small gmsh structures

  {
    std::set<BDS_Point*,PointLessThan>::iterator itp =  m->points.begin(); 
    while (itp != m->points.end())
      {
	BDS_Point *p = *itp;
	if (numbered_vertices.find(p->iD)  == numbered_vertices.end())
	  {
	    MVertex *v = new MFaceVertex (p->X,p->Y,p->Z,gf,p->u,p->v);
	    //MVertex *v = new MFaceVertex (p->u,p->v,0,gf,p->u,p->v);
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


  // delete the mesh

  //  char name[245];
  //  sprintf(name,"s%d.pos",gf->tag());
  //  outputScalarField(m->triangles, name);
  delete m;


  itv = all_vertices.begin();
  count = 0;
  while(itv != all_vertices.end())
    {
      MVertex *here     = *itv;
      here->x() = X_[count]  ;
      here->y() = Y_[count]  ;
      here->z() = Z_[count]  ;
      count ++;
      ++itv;
    }
  delete [] X_;
  delete [] Y_;
  delete [] Z_;

  //  fromParametricToCartesian p2c ( gf );
  //  std::for_each(all_vertices.begin(),all_vertices.end(),p2c);    
  //  std::for_each(gf->mesh_vertices.begin(),gf->mesh_vertices.end(),p2c);    
}
 




void deMeshGFace :: operator() (GFace *gf) 
{
  for (unsigned int i=0;i<gf->mesh_vertices.size();i++) delete gf->mesh_vertices[i];
  gf->mesh_vertices.clear();
  for (unsigned int i=0;i<gf->triangles.size();i++) delete gf->triangles[i];
  gf->triangles.clear();
  for (unsigned int i=0;i<gf->quadrangles.size();i++) delete gf->quadrangles[i];
  gf->quadrangles.clear();
}


void meshGFace :: operator() (GFace *gf) 
{  
  if(gf->geomType() == GEntity::DiscreteSurface) return;

  // Send a messsage to the GMSH environment
  Msg(STATUS2, "Meshing surface %d", gf->tag());

  // destroy the mesh if it exists
  deMeshGFace dem;
  dem(gf);

  // Only apply this technique to unknown surfaces or planar surfaces
  // when it is unknown, try your best ...

  if (MeshTransfiniteSurface(gf))return;


  std::vector<MVertex*> points;
  std::vector<int> indices;
  // compute loops on the fly
  // indices indicate start and end points of a loop
  // loops are not yet oriented
  computeEdgeLoops(gf, points, indices);

  // compute the mean plane, this is sometimes useful 
  gf->computeMeanPlane(points);

  // mesh the face
  gmsh2DMeshGenerator ( gf ) ;

  Msg(DEBUG1, "type %d %d triangles generated, %d internal vertices",
      gf->geomType(),gf->triangles.size(),gf->mesh_vertices.size());

}  
