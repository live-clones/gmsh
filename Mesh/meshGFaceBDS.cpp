// $Id: meshGFaceBDS.cpp,v 1.1 2008-01-24 09:35:41 remacle Exp $
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
#include "meshGFaceOptimize.h"
#include "BackgroundMesh.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "GPoint.h"
#include "Message.h"
#include "Numeric.h"
#include "BDS.h"
#include "qualityMeasures.h"
#include "Field.h"
#include "OS.h"

extern Context_T CTX;

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->X-p2->X;
  const double dy = p1->Y-p2->Y;
  const double dz = p1->Z-p2->Z;
  const double l = sqrt(dx*dx+dy*dy+dz*dz);
  return l;
}

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2, GFace *f,
				      double SCALINGU, double SCALINGV)
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

inline double computeEdgeLinearLength(BDS_Edge *e, GFace *f, double SCALINGU, double SCALINGV)
{
  if (f->geomType() == GEntity::Plane)
    return e->length();
  else
    return computeEdgeLinearLength(e->p1, e->p2,f,SCALINGU,SCALINGV); 
}

double NewGetLc(BDS_Point *p){
  return Extend1dMeshIn2dSurfaces () ? std::min(p->lc(),p->lcBGM()) : p->lcBGM();
}

double NewGetLc(BDS_Edge *e, GFace *f, double SCALINGU, double SCALINGV)
{
  double linearLength = computeEdgeLinearLength(e,f,SCALINGU,SCALINGV);
  double l1 = NewGetLc(e->p1);
  double l2 = NewGetLc(e->p2);
  return 2*linearLength / (l1 + l2);
}

double NewGetLc(BDS_Point *p1,BDS_Point *p2, GFace *f, double su, double sv)
{
  double linearLength = computeEdgeLinearLength(p1,p2,f,su,sv);
  double l1 = NewGetLc(p1);
  double l2 = NewGetLc(p2);
  return 2*linearLength / (l1 + l2);
}

/*Size field accuracy*/
void computeMeshSizeFieldAccuracy (GFace *gf, BDS_Mesh &m, double &avg, double &max_e, double &min_e, int &nE, int &GS)
{
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  avg=0;
  min_e = 1.e22;
  max_e = 0;
  nE = 0;
  GS = 0;
  double oneoversqr2 = 1./sqrt(2.);
  double sqr2 = sqrt(2.);
  while (it!= m.edges.end()){
    if (!(*it)->deleted){
      double lone = NewGetLc ( *it,gf,m.scalingU,m.scalingV);
      if (lone > oneoversqr2 && lone < sqr2 ) GS++;      
      avg+=lone>1 ? (1./lone) - 1. : lone - 1.;
      max_e = std::max(max_e,lone);
      min_e = std::min(min_e,lone);
      nE++;
    }
    ++it;
  }
}
/*Element shapes*/
void computeElementShapes (GFace *gf, BDS_Mesh &m, double &worst, double &avg, double &best, int &nT, int &nbGQ)
{
  std::list<BDS_Face*>::iterator it = m.triangles.begin();
  worst = 1.e22;
  avg = 0.0;
  best = 0.0;
  nT = 0;
  nbGQ = 0;
  while (it!= m.triangles.end()){
    if (!(*it)->deleted){
      double q  = qmTriangle(*it,QMTRI_RHO);
      if (q>.9) nbGQ++;
      avg+=q;
      worst = std::min(worst,q);
      best  = std::max(best,q);
      nT++;
    }
    ++it;
  }
  avg /= nT;
}

/*
  SWAP TESTS i.e. tell if swap should be done
*/

bool edgeSwapTestAngle(BDS_Edge *e, double min_cos)
{
  BDS_Face *f1 = e->faces(0);
  BDS_Face *f2 = e->faces(1);
  BDS_Point *n1[4];
  BDS_Point *n2[4];
  f1->getNodes(n1);
  f2->getNodes(n2);
  double norm1[3];
  double norm2[3];
  normal_triangle(n1[0],n1[1],n1[2],norm1);
  normal_triangle(n2[0],n2[1],n2[2],norm2);
  double cosa;prosca (norm1,norm2,&cosa);
  return cosa > min_cos; 
}

bool evalSwapForOptimize(BDS_Edge *e, GFace *gf, BDS_Mesh &m)
{
  if(e->numfaces() != 2) return false;  

  BDS_Point *p11,*p12,*p13;
  BDS_Point *p21,*p22,*p23;
  BDS_Point *p31,*p32,*p33;
  BDS_Point *p41,*p42,*p43;
  swap_config(e,&p11,&p12,&p13,&p21,&p22,&p23,&p31,&p32,&p33,&p41,&p42,&p43);

  // First, evaluate what we gain in element quality if the
  // swap is performed
  double qa1 = qmTriangle(p11, p12, p13,QMTRI_RHO);
  double qa2 = qmTriangle(p21, p22, p23,QMTRI_RHO);
  double qb1 = qmTriangle(p31, p32, p33,QMTRI_RHO);
  double qb2 = qmTriangle(p41, p42, p43,QMTRI_RHO);
  double qa = std::min(qa1,qa2);
  double qb = std::min(qb1,qb2);
  double qualIndicator = qb - qa;
  bool qualShouldSwap = qb > 2*qa;
  bool qualCouldSwap  = !(qb < qa*.5) && qb > .05;

  // then evaluate if swap produces smoother surfaces 
  double norm11[3];
  double norm12[3];
  double norm21[3];
  double norm22[3];
  normal_triangle(p11,p12,p13,norm11);
  normal_triangle(p21,p22,p23,norm12);
  normal_triangle(p31,p32,p33,norm21);
  normal_triangle(p41,p42,p43,norm22);
  double cosa;prosca (norm11,norm12,&cosa);
  double cosb;prosca (norm21,norm22,&cosb);
  double smoothIndicator = cosb - cosa;
  bool smoothShouldSwap =  (cosa < 0.1 && cosb > 0.3); 
  bool smoothCouldSwap =  !(cosb < cosa*.5); 

  double la  = computeEdgeLinearLength ( p11 , p12 );
  double la_ = computeEdgeLinearLength ( p11 , p12 , gf , m.scalingU , m.scalingV);
  double lb  = computeEdgeLinearLength ( p13 , p23 );
  double lb_ = computeEdgeLinearLength ( p13 , p23 , gf , m.scalingU , m.scalingV);

  double LA = (la_-la)/la_;
  double LB = (lb_-lb)/lb_;

  double distanceIndicator = LA - LB;
  bool distanceShouldSwap =  (LB < .5*LA) && LA > 1.e-2;
  bool distanceCouldSwap =  !(LB > 2*LA) || LB < 1.e-2; 
  
  if (20*qa < qb)return true;
//   if (LB > .025 && distanceIndicator > 0 && qb > .25)return true;
//   if (LB > .05 && distanceIndicator > 0 && qb > .15)return true;
//   if (LB > .1 && distanceIndicator > 0 && qb > .1)return true;
//   if (LB > .2 && distanceIndicator > 0 && qb > .05)return true;
//   if (LB > .3 && distanceIndicator > 0 && qb > .025)return true;

  // if swap enhances both criterion, the do it !
  if (distanceIndicator > 0 && qualIndicator > 0)return true;
  if (distanceShouldSwap && qualCouldSwap)return true;
  if (distanceCouldSwap && qualShouldSwap)return true;
//   if (smoothIndicator > 0 && qualIndicator > 0)return true;
//   if (smoothShouldSwap && qualCouldSwap)return true;
//   if (smoothCouldSwap && qualShouldSwap)return true;
  //  if (distanceShouldSwap && qualCouldSwap)return true;
  //  if (distanceCouldSwap && qualShouldSwap)return true;
  if (cosa < 0 && cosb > 0 && qb > 0.0)
    return true;
  return false;  
}

bool edgeSwapTestDelaunay(BDS_Edge *e,GFace *gf)
{

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
    //double result = gmsh::incircle(p1u, p2u, op1u, op2u) * gmsh::orient2d(p1u, p2u, op1u);    
  //  printf("result = a%12.5E\n",result);
  return result > 0.;
}

bool edgeSwapTestDelaunayAniso(BDS_Edge *e,GFace *gf,std::set<swapquad> & configs)
{
  BDS_Point *op[2];
  
  if(!e->p1->config_modified && ! e->p2->config_modified) return false;

  if(e->numfaces() != 2) return false;

  e->oppositeof (op);

  swapquad sq (e->p1->iD,e->p2->iD,op[0]->iD,op[1]->iD);
  if (configs.find(sq) != configs.end())return false;
  configs.insert(sq);
  
  double edgeCenter[2] ={0.5*(e->p1->u+e->p2->u),
			 0.5*(e->p1->v+e->p2->v)};
			 
  double p1[2] ={e->p1->u,e->p1->v};
  double p2[2] ={e->p2->u,e->p2->v};
  double p3[2] ={op[0]->u,op[0]->v};
  double p4[2] ={op[1]->u,op[1]->v};
  double metric[3];
  buildMetric ( gf , edgeCenter , metric);
  //  printf("%22.15E %22.15E %22.15E\n",metric[0],metric[1],metric[2]);
  if (!inCircumCircleAniso (gf,p1,p2,p3,p4,metric)){
    return false;
  } 
  return true;
}


bool evalSwap(BDS_Edge *e, double &qa, double &qb)
{
  BDS_Point *op[2];
  
  if(e->numfaces() != 2) return false;  
  e->oppositeof (op);
  double qa1 = qmTriangle(e->p1, e->p2, op[0],QMTRI_RHO);
  double qa2 = qmTriangle(e->p1, e->p2, op[1],QMTRI_RHO);
  double qb1 = qmTriangle(e->p1, op[0], op[1],QMTRI_RHO);
  double qb2 = qmTriangle(e->p2, op[0], op[1],QMTRI_RHO);
  qa = std::min(qa1,qa2);
  qb = std::min(qb1,qb2);
  return true;
}

int edgeSwapTestQuality(BDS_Edge *e, double fact = 1.1, bool force = false)
{
  BDS_Point *op[2];
  
  if (!force)
    if(!e->p1->config_modified && ! e->p2->config_modified) return 0;
  
  if(e->numfaces() != 2) return 0;
  
  e->oppositeof (op);

  if (!force)
    if (! edgeSwapTestAngle(e, cos(CTX.mesh.allow_swap_edge_angle*M_PI/180.)) ) return -1;
    
  double qa1 = qmTriangle(e->p1, e->p2, op[0],QMTRI_RHO);
  double qa2 = qmTriangle(e->p1, e->p2, op[1],QMTRI_RHO);
  double qb1 = qmTriangle(e->p1, op[0], op[1],QMTRI_RHO);
  double qb2 = qmTriangle(e->p2, op[0], op[1],QMTRI_RHO);
  double qa = std::min(qa1,qa2);
  double qb = std::min(qb1,qb2);
  if(qb > fact*qa) return 1;
  if(qb < qa/fact) return -1;
  return 0;
}





void swapEdgePass ( GFace *gf, BDS_Mesh &m, int &nb_swap )
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1){
    if (NN2++ >= NN1)break;
    // result = -1 => forbid swap because too badly shaped elements
    // result = 0  => whatever
    // result = 1  => oblige to swap because the quality is greatly improved
    if (!(*it)->deleted){
      const double qual = CTX.mesh.algo2d == ALGO_2D_MESHADAPT ? 1 : 5;
      int result = edgeSwapTestQuality(*it,qual);
      if (CTX.mesh.algo2d == ALGO_2D_MESHADAPT )
	{ if (m.swap_edge ( *it , BDS_SwapEdgeTestQuality(true)))nb_swap++; }
      else if ( result >= 0 && edgeSwapTestDelaunay(*it,gf))
	{ if (m.swap_edge ( *it , BDS_SwapEdgeTestQuality(false))) nb_swap++; }
    }
    ++it;
  }  
}

void gmshDelaunayizeBDS ( GFace *gf, BDS_Mesh &m, int &nb_swap )
{
  nb_swap = 0;
  std::set<swapquad>  configs;
  while(1){
    int NN1 = m.edges.size();
    int NN2 = 0;
    int NSW = 0;
    std::list<BDS_Edge*>::iterator it = m.edges.begin();
    while (1){
      if (NN2++ >= NN1)break;
      if (!(*it)->deleted){
	if (edgeSwapTestDelaunayAniso(*it,gf,configs)){	
	  if (m.swap_edge ( *it , BDS_SwapEdgeTestQuality(false))){
	    NSW++;
	  }
	}
      }
      ++it;
    }
    nb_swap += NSW;
    if (!NSW)return;
  }
}

void splitEdgePass ( GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1){
    if (NN2++ >= NN1)break;
    if (!(*it)->deleted){
      double lone = NewGetLc ( *it,gf,m.scalingU,m.scalingV);
      if ((*it)->numfaces() == 2 && (lone >  MAXE_)){
	
	const double coord = 0.5;
	BDS_Point *mid ;
	mid  = m.add_point(++m.MAXPOINTNUMBER,
			   coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u,
			   coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v,gf);
	
	mid->lcBGM() = BGM_MeshSize(gf,
				    (coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u)*m.scalingU,
				    (coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v)*m.scalingV,
				    mid->X,mid->Y,mid->Z);
	mid->lc() = 0.5 * ( (*it)->p1->lc() +  (*it)->p2->lc() );		  
	if(!m.split_edge ( *it, mid )) m.del_point(mid);
	else nb_split++;
      }
    }
    ++it;
  }
}

void collapseEdgePass(GFace *gf, BDS_Mesh &m, double MINE_, int MAXNP, int &nb_collaps)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1){
    if(NN2++ >= NN1) break;
    
    if(!(*it)->deleted){
      double lone = NewGetLc(*it, gf,m.scalingU,m.scalingV);
      if(!(*it)->deleted && (*it)->numfaces() == 2 && lone < MINE_){
	bool res = false;
	if((*it)->p1->iD > MAXNP)
	  res = m.collapse_edge_parametric(*it, (*it)->p1);
	else if((*it)->p2->iD > MAXNP)
	  res = m.collapse_edge_parametric(*it, (*it)->p2);
	if(res)
	  nb_collaps++;
      }
    }
    ++it;
  }
}

void smoothVertexPass(GFace *gf, BDS_Mesh &m, int &nb_smooth, bool q)
{
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while(itp != m.points.end()){      
    if(m.smooth_point_centroid(*itp, gf,q))
      nb_smooth ++;
    ++itp;
  }
}


void gmshRefineMeshBDS (GFace *gf, 
			BDS_Mesh &m, 
			const int NIT, 
			const bool computeNodalSizeField)
{
  int IT = 0;

  int MAXNP = m.MAXPOINTNUMBER;

  // IF ASKED , compute nodal size field using 1D Mesh
  if (computeNodalSizeField){
    std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
    while (itp != m.points.end()){
      std::list<BDS_Edge*>::iterator it  = (*itp)->edges.begin();
      std::list<BDS_Edge*>::iterator ite = (*itp)->edges.end();
      double L=0;
      int ne = 0;
      while(it!=ite){
	double l = (*it)->length();
	if ((*it)->g && (*it)->g->classif_degree == 1){	      
	  L=ne?std::max(L,l):l;
	  ne++;
	}
	++it;
      }
      if (!ne) L = 1.e22;
      if(!CTX.mesh.constrained_bgmesh)
	(*itp)->lc() = L;
      (*itp)->lcBGM() = L;
      ++itp;
    }
  }

  double t_spl=0, t_sw=0,t_col=0,t_sm=0;

  const double MINE_ = 0.67, MAXE_=1.4;

  double mesh_quality = 0;
  while (1)
    {
      // we count the number of local mesh modifs.

      int nb_split=0;
      int nb_smooth=0;
      int nb_collaps=0;
      int nb_swap=0;

      // split long edges

      double minL=1.E22,maxL=0;

      int NN1 = m.edges.size();
      int NN2 = 0;
      std::list<BDS_Edge*>::iterator it = m.edges.begin();
      while (1){
	if (NN2++ >= NN1)break;
	if (!(*it)->deleted)
	  {
	    (*it)->p1->config_modified = false;
	    (*it)->p2->config_modified = false;
	    double lone = NewGetLc ( *it,gf,m.scalingU,m.scalingV);	      
	    maxL = std::max(maxL,lone);
	    minL = std::min(minL,lone);
	  }
	++it;
      }

      if ((minL > MINE_ && maxL < MAXE_) || IT > (abs(NIT)))break;
      double maxE = MAXE_;
      double minE = MINE_;
      double t1 = Cpu();
      splitEdgePass ( gf, m, maxE, nb_split);
      double t2 = Cpu();
      swapEdgePass ( gf, m, nb_swap);
      swapEdgePass ( gf, m, nb_swap);
      swapEdgePass ( gf, m, nb_swap);
      double t3 = Cpu();
      collapseEdgePass ( gf, m, minE , MAXNP, nb_collaps);
      double t4 = Cpu();
      //      swapEdgePass ( gf, m, nb_swap); 
      double t5 = Cpu();
      smoothVertexPass ( gf, m, nb_smooth,false);
      double t6 = Cpu();
      //      swapEdgePass ( gf, m, nb_swap);
      double t7 = Cpu();
      // clean up the mesh

      t_spl += t2 - t1;
      t_sw  += t3 - t2;
      t_sw  += t5 - t4;
      t_sw  += t7 - t6;
      t_col += t4 - t3;
      t_sm  += t6 - t5;

      m.cleanup();  	
      IT++;
      Msg(DEBUG1," iter %3d minL %8.3f/%8.3f maxL %8.3f/%8.3f : %6d splits, %6d swaps, %6d collapses, %6d moves",IT,minL,minE,maxL,maxE,nb_split,nb_swap,nb_collaps,nb_smooth);
      
      if (nb_split==0 && nb_collaps == 0)break;
    }  

  double t_total = t_spl + t_sw + t_col + t_sm;
  if(!t_total) t_total = 1.e-6;
  Msg(DEBUG1," ---------------------------------------");
  Msg(DEBUG1," CPU Report ");
  Msg(DEBUG1," ---------------------------------------");
  Msg(DEBUG1," CPU SWAP    %12.5E sec (%3.0f %%)",t_sw,100 * t_sw/t_total);
  Msg(DEBUG1," CPU SPLIT   %12.5E sec (%3.0f %%) ",t_spl,100 * t_spl/t_total);
  Msg(DEBUG1," CPU COLLAPS %12.5E sec (%3.0f %%) ",t_col,100 * t_col/t_total);
  Msg(DEBUG1," CPU SMOOTH  %12.5E sec (%3.0f %%) ",t_sm,100 * t_sm/t_total);
  Msg(DEBUG1," ---------------------------------------");
  Msg(DEBUG1," CPU TOTAL   %12.5E sec ",t_total);
  Msg(DEBUG1," ---------------------------------------");
}

void gmshOptimizeMeshBDS(GFace *gf, 
			 BDS_Mesh &m, 
			 const int NIT, 
			 std::map<BDS_Point*,MVertex*> *recover_map = 0)
{
  int nb_swap;
  gmshDelaunayizeBDS ( gf, m, nb_swap );


  for (int ITER = 0;ITER < 3;ITER++){
    int nb_smooth;
    smoothVertexPass ( gf,m,nb_smooth,true);

    double LIMIT = .1;
    for (int KK=0;KK<4;KK++){
      // swap edges that provide a better configuration
      int NN1 = m.edges.size();
      int NN2 = 0;
      std::list<BDS_Edge*>::iterator it = m.edges.begin();
      while (1)
	{
	  if (NN2++ >= NN1)break;
	  if (evalSwapForOptimize(*it,gf,m))	
	    m.swap_edge ( *it , BDS_SwapEdgeTestQuality(false));
	  ++it;
	}
      m.cleanup();  
    }
    

    // then collapse small edges (take care not to create overlapping triangles)
    
    // in case of periodic surfaces, split all edges that are problematic
    for (int KK=0;KK<1;KK++){
      int NN1 = m.edges.size();
      int NN2 = 0;
      std::list<BDS_Edge*>::iterator it = m.edges.begin();
      std::vector<BDS_Edge *> toSplit;
      while (1){
	if (NN2++ >= NN1)break;
	if((*it)->numfaces() == 2){
	  if (recover_map){
	    std::map<BDS_Point*,MVertex*>::iterator itp1 = recover_map->find((*it)->p1);
	    std::map<BDS_Point*,MVertex*>::iterator itp2 = recover_map->find((*it)->p2);
	    BDS_Point *op[2];
	    (*it)->oppositeof (op);
	    std::map<BDS_Point*,MVertex*>::iterator itp3 = recover_map->find(op[0]);
	    std::map<BDS_Point*,MVertex*>::iterator itp4 = recover_map->find(op[1]);
	    
	    // this edge goes from one side to the other of the periodic parametric space !
	    if (itp1 != recover_map->end() && itp2 != recover_map->end() && itp1->second == itp2->second)
	      toSplit.push_back(*it);
	    // this edge is internal but the 2 adjacent triangles are the same in the real space
	    if (itp3 != recover_map->end() && itp4 != recover_map->end() && itp3->second == itp4->second)
	      {
		// the first point is internal, split both edges that go from this one to the two opposites (that are the same)
		BDS_Edge *e1 , *e2 ;
		//		  printf ("edge prob %d %d\n",(*it)->p1->iD,(*it)->p2->iD);
		if (itp1 == recover_map->end()){
		  e1 = m.find_edge ((*it)->p1,itp3->first);
		  e2 = m.find_edge ((*it)->p1,itp4->first);
		  if (e1 && e1->numfaces() == 2)
		    toSplit.push_back(e1);
		  if (e2 && e2->numfaces() == 2)
		    toSplit.push_back(e2);
		}
		else if (itp2 == recover_map->end()){
		  e1 = m.find_edge ((*it)->p2,itp3->first);
		  e2 = m.find_edge ((*it)->p2,itp4->first);
		  if (e1 && e1->numfaces() == 2)
		    toSplit.push_back(e1);				      
		  if (e2 && e2->numfaces() == 2)
		    toSplit.push_back(e2);
		}
		else{
		  printf("zarbi\n");
		}
	      }
	    //	      toSplit.push_back(*it);	    
	  }
	}
	++it;
      }
      //	printf("%d edges to split\n",toSplit.size());
      for (int i=0;i<toSplit.size();i++){
	BDS_Edge *e = toSplit[i];
	if (!e->deleted){
	  const double coord = 0.5;
	  BDS_Point *mid ;
	  mid  = m.add_point(++m.MAXPOINTNUMBER,
			     coord * e->p1->u + (1 - coord) * e->p2->u,
			     coord * e->p1->v + (1 - coord) * e->p2->v,gf);	
	  //	    printf("%d %d %d\n",e->p1->iD,e->p2->iD,mid->iD);
	  mid->lcBGM() = BGM_MeshSize(gf,
				      (coord * e->p1->u + (1 - coord) * e->p2->u)*m.scalingU,
				      (coord * e->p1->v + (1 - coord) * e->p2->v)*m.scalingV,
				      mid->X,mid->Y,mid->Z);
	  mid->lc() = 0.5 * ( e->p1->lc() +  e->p2->lc() );		  
	  if(!m.split_edge ( e, mid )) m.del_point(mid);
	}
      }
      m.cleanup();  
    }
  }
}

