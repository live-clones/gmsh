// $Id: meshGFace.cpp,v 1.108 2008-01-18 22:23:03 geuzaine Exp $
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
#include "meshGFaceOptimize.h"
#include "DivideAndConquer.h"
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

static double SCALINGU=1,SCALINGV=1;

bool noseam (  GFace *gf  )
{
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*>::iterator it = edges.begin();
  while (it != edges.end())   
   {
     GEdge *ge = *it ;
     bool seam = ge->isSeam(gf);
     if (seam) return false;
     ++it;
   }
  return true;
}


void remeshUnrecoveredEdges ( std::set<EdgeToRecover> & edgesNotRecovered, std::list<GFace *> &facesToRemesh)
{
  facesToRemesh.clear();
  deMeshGFace dem;

  std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
  for ( ; itr != edgesNotRecovered.end() ; ++itr)
    {
      std::list<GFace*> l_faces = itr->ge->faces();
      // Un-mesh model faces adjacent to the model edge 
      for ( std::list<GFace*>::iterator it = l_faces.begin() ;it != l_faces.end();++it)
	{
	  if ((*it)->triangles.size() ||(*it)->quadrangles.size())
	    {
	      facesToRemesh.push_back(*it);
	      dem(*it);
	    } 
	}
      //-----------------------------------------------------

      
      // add a new point in the middle of the intersecting segment
      int p1 = itr->p1;
      int p2 = itr->p2;
      int index = 0;
      int N = itr->ge->lines.size();
      GVertex * g1 = itr->ge->getBeginVertex();
      GVertex * g2 = itr->ge->getEndVertex();
      Range<double> bb = itr->ge->parBounds(0);
  
      std::vector<MLine*> newLines;

      for (int i=0;i<N;i++){
	MVertex *v1 = itr->ge->lines[i]->getVertex(0);
	MVertex *v2 = itr->ge->lines[i]->getVertex(1);
	if (v1->getNum() == p1 && v2->getNum() == p2 ||
	    v1->getNum() == p2 && v2->getNum() == p1 )
	  {
	    double t1;
	    double lc1 = -1;
	    if (v1->onWhat() == g1)t1 = bb.low();  
	    else if (v1->onWhat() == g2)t1 = bb.high();  
	    else {
	      MEdgeVertex * ev1 = (MEdgeVertex*) v1;
	      lc1 = ev1->getLc();
	      v1->getParameter(0,t1);
	    }

	    double t2;
	    double lc2= -1;
	    if (v2->onWhat() == g1)t2 = bb.low();  
	    else if (v2->onWhat() == g2)t2 = bb.high();  
	    else {
	      MEdgeVertex * ev2 = (MEdgeVertex*) v2;
	      lc2 = ev2->getLc();
	      v2->getParameter(0,t2);
	    }

	    // periodic
	    if (v1->onWhat() == g1 && v1->onWhat() == g2)
		t1 = fabs(t2-bb.low()) < fabs(t2-bb.high()) ? bb.low() : bb.high();
	    if (v2->onWhat() == g1 && v2->onWhat() == g2)
		t2 = fabs(t1-bb.low()) < fabs(t1-bb.high()) ? bb.low() : bb.high();
	    

	    if (lc1 == -1)
	      lc1 = BGM_MeshSize(v1->onWhat(),0,0,v1->x(),v1->y(),v1->z());
	    if (lc2 == -1)
	      lc2 = BGM_MeshSize(v2->onWhat(),0,0,v2->x(),v2->y(),v2->z());
	    // should be better, i.e. equidistant
	    double t = 0.5*(t2+t1);
	    double lc = 0.5*(lc1+lc2);
	    GPoint V = itr->ge->point(t);
	    MEdgeVertex * newv = new MEdgeVertex(V.x(), V.y(), V.z(), itr->ge, t, lc);
	    newLines.push_back(new MLine(v1, newv));
	    newLines.push_back(new MLine(newv, v2));
	    delete itr->ge->lines[i];
	  }
	else {
	  newLines.push_back(itr->ge->lines[i]);
	}
      }
      itr->ge->lines = newLines;
      itr->ge->mesh_vertices.clear();
      N = itr->ge->lines.size();
      for (int i=1;i<N;i++){
	itr->ge->mesh_vertices.push_back(itr->ge->lines[i]->getVertex(0));
      }            
    }
}


bool AlgoDelaunay2D ( GFace *gf )
{ 
  if ( noseam(gf) && /*gf->getNativeType() == GEntity::GmshModel &&*/ CTX.mesh.algo2d == ALGO_2D_DELAUNAY /*&& gf->geomType() == GEntity::Plane*/)
    return true;
  return false;
}

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

double NewGetLc(BDS_Point *p)
{
  return Extend1dMeshIn2dSurfaces () ? std::min(p->lc(),p->lcBGM()) : p->lcBGM();
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

double NewGetLc(BDS_Point *p1,BDS_Point *p2, GFace *f)
{
  double linearLength = computeEdgeLinearLength(p1,p2,f);
  double l1 = NewGetLc(p1);
  double l2 = NewGetLc(p2);
  return 2*linearLength / (l1 + l2);
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

void OptimizeMesh(GFace *gf, BDS_Mesh &m, const int NIT)
{
  // optimize
  if (0)
    {
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
      }
    }

//   for(int i = 0 ; i < NIT ; i++){
//     std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
//     while (itp != m.points.end())
//       {
// 	optimize_vertex_position(gf,*itp,m.scalingU,m.scalingV);		
// 	++itp;
//       }
//   }


 for (int KK=0;KK<4;KK++){
   // swap edges that provide a better configuration
    int NN1 = m.edges.size();
    int NN2 = 0;
    std::list<BDS_Edge*>::iterator it = m.edges.begin();
    while (1)
      {
	if (NN2++ >= NN1)break;
	m.swap_edge ( *it , BDS_SwapEdgeTestQuality(true));
	++it;
      }
    m.cleanup();  
  }
}

void swapEdgePass ( GFace *gf, BDS_Mesh &m, int &nb_swap )
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1)
    {
      if (NN2++ >= NN1)break;
      // result = -1 => forbid swap because too badly shaped elements
      // result = 0  => whatever
      // result = 1  => oblige to swap because the quality is greatly improved
      if (!(*it)->deleted)
	{
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

int getTemplate (const BDS_Face *f, const std::map<BDS_Edge*,std::pair<BDS_Edge*,BDS_Edge*> >&splits,
		 BDS_Edge *edges[3][2]){
  int k = 0;
  std::map< BDS_Edge*,std::pair<BDS_Edge*,BDS_Edge* > > ::const_iterator it;
  it = splits.find ( f-> e1 );
  if (it == splits.end()){
    edges[0][0] = f->e1;
    edges[0][1] = 0;
  }
  else{
    edges[0][0] = it->second.first;
    edges[0][1] = it->second.second;
    k+=1;
  }
  it = splits.find ( f->e2 );
  if (it == splits.end()){
    edges[1][0] = f->e2;
    edges[1][1] = 0;
  }
  else{
    edges[1][0] = it->second.first;
    edges[1][1] = it->second.second;
    k+=10;
  }
  it = splits.find ( f->e3 );
  if (it == splits.end()){
    edges[2][0] = f->e3;
    edges[2][1] = 0;
  }
  else{
    edges[2][0] = it->second.first;
    edges[2][1] = it->second.second;
    k+=100;
  }
  return k;		     
}

void Template_1 ( BDS_Mesh &m , BDS_Face *f, BDS_Edge *e11, BDS_Edge *e12, BDS_Edge *e2, BDS_Edge *e3)
{
  BDS_Point *mid = e11->commonvertex(e12);
  BDS_Point *opposite = e2->commonvertex(e3);

  if (!mid || !opposite){
    printf("strange bazar in template 1 : edges %d %d , %d %d , %d %d and %d %d\n",
	   e11->p1->iD,e11->p2->iD,
	   e12->p1->iD,e12->p2->iD,
	   e2->p1->iD,e2->p2->iD,
	   e3->p1->iD,e3->p2->iD);
  }

  BDS_Edge *emid = new BDS_Edge (mid,opposite);

  if (!e11->commonvertex(e3)){
    BDS_Edge *temp = e3;
    e3 = e2; 
    e2 = temp;
  }

  BDS_Face* t1 = new BDS_Face(e11,emid,e3);
  BDS_Face* t2 = new BDS_Face(e12,e2,emid);
  t1->g = f->g;
  t2->g = t1->g;
  emid->g = t1->g;  
  m.triangles.push_back(t1);
  m.triangles.push_back(t2);
  m.edges.push_back(emid);
  m.del_face(f);
  e11->p1->config_modified = e11->p2->config_modified = true;
  e12->p1->config_modified = e12->p2->config_modified = true;
  e2->p1->config_modified = e2->p2->config_modified = true;
  e3->p1->config_modified = e3->p2->config_modified = true;
}

void Template_2 ( BDS_Mesh &m , BDS_Face *f, BDS_Edge *e11, BDS_Edge *e12, BDS_Edge *e21, BDS_Edge *e22, BDS_Edge *e3)
{
  BDS_Point *mid1 = e11->commonvertex(e12);
  BDS_Point *mid2 = e21->commonvertex(e22);

  BDS_Edge *emid1 = new BDS_Edge (mid1,mid2);

  if (!e11->commonvertex(e3)){
    BDS_Edge *temp = e11;
    e11 = e12; 
    e12 = temp;
  }
  if (!e22->commonvertex(e3)){
    BDS_Edge *temp = e22;
    e22 = e21; 
    e21 = temp;
  }
  BDS_Point *opposite1 = e3->commonvertex(e22);
  BDS_Point *opposite2 = e3->commonvertex(e11);

  //  if (!e12->commonvertex(e21))throw;

  // build the best possible template to avoid subsequent swap
  // first config, use and edge mid1->opposite1
  double config1Q = std::min(qmTriangle(opposite2,mid1,opposite1,QMTRI_RHO),qmTriangle(mid1,mid2,opposite1,QMTRI_RHO)); 
  // second config, use and edge mid2->opposite2
  double config2Q = std::min(qmTriangle(opposite2,mid2,opposite1,QMTRI_RHO),qmTriangle(mid1,mid2,opposite2,QMTRI_RHO)); 
  
  // if the first one is the best
  BDS_Face *t1,*t2,*t3;
  BDS_Edge *emid2;
  t1 = new BDS_Face(e12,e21,emid1);
  if (config1Q > config2Q) {
    emid2 = new BDS_Edge (mid1,opposite1);
    t2 = new BDS_Face(e11,emid2,e3);
    t3 = new BDS_Face(emid2,emid1,e22);
  }
  else{
    emid2 = new BDS_Edge (mid2,opposite2);
    t2 = new BDS_Face(e11,emid1,emid2);
    t3 = new BDS_Face(emid2,e22,e3);
  }
  t1->g = f->g;
  t2->g = t1->g;
  t3->g = t1->g;
  emid1->g = t1->g;  
  emid2->g = t1->g;  
  m.triangles.push_back(t1);
  m.triangles.push_back(t2);
  m.triangles.push_back(t3);
  m.edges.push_back(emid1);
  m.edges.push_back(emid2);
  m.del_face(f);
  e11->p1->config_modified = e11->p2->config_modified = true;
  e12->p1->config_modified = e12->p2->config_modified = true;
  e21->p1->config_modified = e21->p2->config_modified = true;
  e22->p1->config_modified = e22->p2->config_modified = true;
  e3->p1->config_modified = e3->p2->config_modified = true;
}
void Template_3 ( BDS_Mesh &m , BDS_Face *f, BDS_Edge *e11, BDS_Edge *e12, BDS_Edge *e21, BDS_Edge *e22, BDS_Edge *e31,BDS_Edge *e32)
{
  BDS_Point *mid1 = e11->commonvertex(e12);
  BDS_Point *mid2 = e21->commonvertex(e22);
  BDS_Point *mid3 = e31->commonvertex(e32);

  BDS_Edge *emid12 = new BDS_Edge (mid1,mid2);
  BDS_Edge *emid13 = new BDS_Edge (mid1,mid3);
  BDS_Edge *emid23 = new BDS_Edge (mid2,mid3);

  if (!e11->commonvertex(e31) && !e11->commonvertex(e32)){
    BDS_Edge *temp = e11;
    e11 = e12; 
    e12 = temp;
  }
  if (!e11->commonvertex(e31)){
    BDS_Edge *temp = e31;
    e31 = e32; 
    e32 = temp;
  }
  if (!e32->commonvertex(e22)){
    BDS_Edge *temp = e21;
    e21 = e22; 
    e22 = temp;
  }

//   if (!e11->commonvertex(e31))throw;
//   if (!e32->commonvertex(e22))throw;
//   if (!e12->commonvertex(e21))throw;

  BDS_Face *t1 = new BDS_Face(e11,emid13,e31);
  BDS_Face *t2 = new BDS_Face(e12,e21,emid12);
  BDS_Face *t3 = new BDS_Face(emid23,e22,e32);
  BDS_Face *t4 = new BDS_Face(emid12,emid23,emid13);

  t1->g = f->g;
  t2->g = t1->g;
  t3->g = t1->g;
  t4->g = t1->g;
  emid12->g = t1->g;  
  emid13->g = t1->g;  
  emid23->g = t1->g;  
  m.triangles.push_back(t1);
  m.triangles.push_back(t2);
  m.triangles.push_back(t3);
  m.triangles.push_back(t4);
  m.edges.push_back(emid12);
  m.edges.push_back(emid13);
  m.edges.push_back(emid23);
  m.del_face(f);
  e11->p1->config_modified = e11->p2->config_modified = true;
  e12->p1->config_modified = e12->p2->config_modified = true;
  e21->p1->config_modified = e21->p2->config_modified = true;
  e22->p1->config_modified = e22->p2->config_modified = true;
  e31->p1->config_modified = e31->p2->config_modified = true;
  e32->p1->config_modified = e32->p2->config_modified = true;
}


void splitEdgePass_templateRefine ( GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split)
{
  std::map<BDS_Edge*,std::pair<BDS_Edge*,BDS_Edge*> >splits;
  // build a list of edges to split with their new vertices
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1)
    {
      if (NN2++ >= NN1)break;
      if (!(*it)->deleted && (*it)->numfaces() == 2)
	{
	  double lone = NewGetLc ( *it,gf);
	  if (lone >  MAXE_){	    
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
	    BDS_Edge *e1 = new BDS_Edge ((*it)->p1,mid);
	    BDS_Edge *e2 = new BDS_Edge (mid, (*it)->p2);
	    e1->g = e2->g = (*it)->g;
	    m.del_edge((*it));
	    m.edges.push_back(e1);
	    m.edges.push_back(e2);


	    splits[*it] = std::make_pair<BDS_Edge*, BDS_Edge*> (e1,e2);
	    nb_split++;
	  }		  
	}
      ++it;
    }

  std::list<BDS_Face*>::iterator itt = m.triangles.begin();
  // build a list of edges to split with their new vertices
  while (itt != m.triangles.end())
    {
      if (!(*itt)->deleted)
	{
	  BDS_Edge *edges[3][2];
	  int K = getTemplate ((*itt),splits,edges);
	  switch(K){
	  case   0: // no edge is split 
	    break;
	  case   1: // first edge is split 
	    Template_1 ( m , *itt, edges[0][0],edges[0][1],edges[1][0],edges[2][0]);
	    break;
	  case  10: // second edge is split 
	    Template_1 ( m , *itt, edges[1][0],edges[1][1],edges[2][0],edges[0][0]);
	    break;
	  case 100: // third edge is split 
	    Template_1 ( m , *itt, edges[2][0],edges[2][1],edges[0][0],edges[1][0]);
	    break;
	  case  11: // fisrt and second
	    Template_2 ( m , *itt, edges[0][0],edges[0][1],edges[1][0],edges[1][1],edges[2][0]);
	    break;
	  case 101: // fisrt and third
	    Template_2 ( m , *itt, edges[2][0],edges[2][1],edges[0][0],edges[0][1],edges[1][0]);
	    break;
	  case 110: // second and third
	    Template_2 ( m , *itt, edges[1][0],edges[1][1],edges[2][0],edges[2][1],edges[0][0]);
	    break;
	  case 111: // all splitted
	    Template_3 ( m , *itt, edges[0][0],edges[0][1],edges[1][0],edges[1][1],edges[2][0],edges[2][1]);
	    break;
	  default :
	    printf("strange template %d\n",K);
	    throw;
	  }
	}
      ++itt;
    }
}

void splitEdgePass ( GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split, AttractorField_1DMesh *attr)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1)
    {
      if (NN2++ >= NN1)break;
      if (!(*it)->deleted)
	{
	  double lone = NewGetLc ( *it,gf);
	  if ((*it)->numfaces() == 2 && (lone >  MAXE_))
	    {

//  	      BDS_Point *op[2];
//  	      (*it)->oppositeof(op);
//  	      double lone1 = NewGetLc ( op[0],mid,gf);	      
//  	      double lone2 = NewGetLc ( op[1],mid,gf);	      
	      
	      const double coord = 0.5;
	      BDS_Point *mid ;
	      mid  = m.add_point(++m.MAXPOINTNUMBER,
				 coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u,
				 coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v,gf);

	      mid->lcBGM() = BGM_MeshSize(gf,
					  (coord * (*it)->p1->u + (1 - coord) * (*it)->p2->u)*m.scalingU,
					  (coord * (*it)->p1->v + (1 - coord) * (*it)->p2->v)*m.scalingV,
					  mid->X,mid->Y,mid->Z);
	      //mid->lc() = 2./ ( 1./(*it)->p1->lc() +  1./(*it)->p2->lc() );		  
	      if (!attr)
		mid->lc() = 0.5 * ( (*it)->p1->lc() +  (*it)->p2->lc() );		  
	      else{
		double lcmin,lcpt, dist;
		double FACT1 = 3, FACT2=25;
		attr->eval(mid->X,mid->Y,mid->Z,lcmin,lcpt, dist);

		if (dist < FACT1* lcmin) mid->lc() = lcmin;
 		else if (dist < FACT2 * lcmin) {
 		  double r = (dist - FACT1*lcmin) / ((FACT2-FACT1)*lcmin);
 		  mid->lc() = 1./(1./lcmin * r + 1./lcpt*(1-r));
 		}
		else mid->lc() = lcpt;
	      }
		
	      //	      printf("%g %g\n",mid->lc(),mid->lcBGM());

	      if(!m.split_edge ( *it, mid )) m.del_point(mid);
	      else nb_split++;
	    }
	}
      ++it;
    }
}

void saturateEdgePass ( GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1)
    {
      if (NN2++ >= NN1)break;
      if (!(*it)->deleted)
	{
	  double lone = NewGetLc ( *it,gf);
	  if ((*it)->numfaces() == 2 && (lone >  MAXE_))
	    {
	      int nbSub = (int) (lone/MAXE_) ;
	      //	      nbSub = std::min(nbSub,2);
	      //	      printf("%d %g\n",nbSub,lone/MAXE_);
	      std::vector<BDS_Point*> mids;
	      for (int i=0;i<nbSub;i++)
		{
		  const double coord = (double)(i+1)/(nbSub+1);
		  BDS_Point *mid ;
		  mid  = m.add_point(++m.MAXPOINTNUMBER,
				     (1.-coord) * (*it)->p1->u + coord * (*it)->p2->u,
				     (1.-coord) * (*it)->p1->v + coord * (*it)->p2->v,gf);
		  double l1;
		  //		  if (BGMExists())
		  mid->lcBGM() = BGM_MeshSize(gf,
					      ((1.-coord) * (*it)->p1->u + (coord) * (*it)->p2->u)*m.scalingU,
					      ((1.-coord) * (*it)->p1->v + (coord) * (*it)->p2->v)*m.scalingV,
					      mid->X,mid->Y,mid->Z);
		  //mid->lc() = 2./ ( 1./(*it)->p1->lc() +  1./(*it)->p2->lc() );		  
		  mid->lc() = ( (1.-coord)*(*it)->p1->lc() +  coord*(*it)->p2->lc() );		 
		  mids.push_back(mid);
		  //		  printf("new point %g %g lc %g\n",mid->X,mid->Y,mid->lc());
		}
	      //	      printf("saturating an edge with %d points %d triangles\n",mids.size(),m.triangles.size());
	      if(nbSub>0)m.saturate_edge ( *it, mids );
	      //	      printf("-> %d triangles\n",m.triangles.size());
	      nb_split++;
	      //	      if (nb_split == )break;
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
      double lone = NewGetLc(*it, gf);
      // if (lone < 1.e-10 && computeParametricEdgeLength((*it)->p1,(*it)->p2) > 1.e-5) 
      //   lone = 2;
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
  while (it!= m.edges.end())
    {
      if (!(*it)->deleted)
	{
	  double lone = NewGetLc ( *it,gf);
	  if (lone > oneoversqr2 && lone < sqr2 ) GS++;
	  
	  avg+=lone>1 ? (1./lone) - 1. : lone - 1.;
	  max_e = std::max(max_e,lone);
	  min_e = std::min(min_e,lone);
	  nE++;
	}
      ++it;
    }
}

void computeElementShapes (GFace *gf, BDS_Mesh &m, double &worst, double &avg, double &best, int &nT, int &nbGQ)
{
  std::list<BDS_Face*>::iterator it = m.triangles.begin();
  worst = 1.e22;
  avg = 0.0;
  best = 0.0;
  nT = 0;
  nbGQ = 0;
  while (it!= m.triangles.end())
    {
      if (!(*it)->deleted)
	{
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


void computeElementShapes (GFace *gf, double &worst, double &avg, double &best, int &nT, int &greaterThan )
{
  worst = 1.e22;
  avg = 0.0;
  best = 0.0;
  nT = 0;
  greaterThan = 0;
 for (int i=0;i<gf->triangles.size();i++)
    {
      double q  = qmTriangle(gf->triangles[i],QMTRI_RHO);
      if (q>.9)greaterThan++;
      avg+=q;
      worst = std::min(worst,q);
      best  = std::max(best,q);
      nT++;
    }
  avg /= nT;
}


void smoothVertexPass ( GFace *gf, BDS_Mesh &m, int &nb_smooth)
{
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while (itp != m.points.end())
    {      
      if(m.smooth_point_centroid(*itp,gf))
	nb_smooth ++;
      ++itp;
    }
}

void RefineMesh ( GFace *gf, BDS_Mesh &m , const int NIT)
{
  int IT =0;
  AttractorField_1DMesh *attr = 0;
//   if (CTX.mesh.lc_from_curvature){
//     // parameters are not important
//     attr = new AttractorField_1DMesh(gf,0.1,0,1);
//     attr->buildFastSearchStructures();
//   }

  //  printf("lc (1,1) = %g\n",Attractor::lc(1,1,0));

  int MAXNP = m.MAXPOINTNUMBER;

  if (NIT > 0)
    {
      std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
      while (itp != m.points.end())
	{
	  std::list<BDS_Edge*>::iterator it  = (*itp)->edges.begin();
	  std::list<BDS_Edge*>::iterator ite = (*itp)->edges.end();
	  double L=0;
	  int ne = 0;
	  while(it!=ite){
	    double l = (*it)->length();
	    if ((*it)->g && (*it)->g->classif_degree == 1){	      
	      L=ne?std::max(L,l):l;
	      //	      L=ne?std::min(L,l):l;
	      //	      L+=l;
	      ne++;
	    }
	    ++it;
	  }
	  if (!ne) L = 1.e22;
	  //	  else L/=ne;
	  if(!CTX.mesh.constrained_bgmesh)
	    (*itp)->lc() = L;
	  (*itp)->lcBGM() = L;
	  ++itp;
	}
    }

  double OLDminL=1.E22,OLDmaxL=0;

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
      double maxE = MAXE_;
      double minE = MINE_;
      double t1 = Cpu();
      //      splitEdgePass_templateRefine ( gf, m, maxE, nb_split);
      splitEdgePass ( gf, m, maxE, nb_split,attr);
      //splitEdgePass_templateRefine ( gf, m, maxE, nb_split);
      //saturateEdgePass ( gf, m, maxE, nb_split);
      double t2 = Cpu();
      swapEdgePass ( gf, m, nb_swap);
      swapEdgePass ( gf, m, nb_swap);
      swapEdgePass ( gf, m, nb_swap);
      double t3 = Cpu();
      collapseEdgePass ( gf, m, minE , MAXNP, nb_collaps);
      double t4 = Cpu();
      //      swapEdgePass ( gf, m, nb_swap); 
      double t5 = Cpu();
      smoothVertexPass ( gf, m, nb_smooth);
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

      double smallest, longest,  old_mesh_quality = mesh_quality;int nE,NG;
      computeMeshSizeFieldAccuracy (gf, m, mesh_quality, smallest, longest,nE,NG);
      double worst,avg,best; int nT,GT; computeElementShapes (gf, m, worst, avg,best,nT,GT);
      m.cleanup();  	
      IT++;
      Msg(DEBUG1," iter %3d minL %8.3f/%8.3f maxL %8.3f/%8.3f : %6d splits, %6d swaps, %6d collapses, %6d moves, accuracy %7.5f, shapes (worst %7.6f, avg %7.6f, best %7.6f) ",IT,minL,minE,maxL,maxE,nb_split,nb_swap,nb_collaps,nb_smooth, exp(mesh_quality/nE), worst,avg/nT,best);
      
      if (nb_split==0 && nb_collaps == 0)break;
      //      if (mesh_quality < old_mesh_quality && worst > 0.1 && maxL < 1.45) break;
      //      return;

    }  

  double t_total = t_spl + t_sw + t_col + t_sm;
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

  if (attr)delete attr;
}




bool recover_medge ( BDS_Mesh *m, GEdge *ge, std::set<EdgeToRecover> *e2r, std::set<EdgeToRecover> *not_recovered, int pass_)
{
  BDS_GeomEntity *g=0;
  if (pass_ == 2)
    {
      m->add_geom (ge->tag(), 1);
      g = m->get_geom(ge->tag(),1);
    }

  if (ge->mesh_vertices.size() == 0)
    {

      MVertex   *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
      MVertex   *vend   = *(ge->getEndVertex()->mesh_vertices.begin());
      if (pass_ == 1)
	{
	  e2r->insert (EdgeToRecover (vstart->getNum(), vend->getNum(),ge));
	  return true;
	}
      else
	{
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
	  BDS_Edge * e = m->recover_edge ( vstart->getNum(), vend->getNum(),e2r, not_recovered);
	  if (e)e->g = g;
	  else {
	    //	    Msg(GERROR,"The unrecoverable edge is on model edge %d",ge->tag());
	    return false;
	  }
	  return true;
	}
    }

  BDS_Edge * e;
  MVertex *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
  MVertex *vend   = *(ge->mesh_vertices.begin());

  if (pass_ == 1)e2r->insert (EdgeToRecover (vstart->getNum(), vend->getNum(),ge));
  else 
    {
      BDS_Point *pstart = m->find_point(vstart->getNum());
      if(!pstart->g)
	{
	  m->add_geom (vstart->getNum(), 0);
	  BDS_GeomEntity *g0 = m->get_geom(vstart->getNum(), 0);
	  pstart->g = g0;
	}
      e = m->recover_edge ( vstart->getNum(), vend->getNum(),e2r, not_recovered);
      if (e)e->g = g;
      else {
	//	Msg(GERROR,"The unrecoverable edge is on model edge %d",ge->tag());
	//	return false;
      }
    }

  for (unsigned int i=1;i<ge->mesh_vertices.size();i++)
    {
      vstart = ge->mesh_vertices[i-1];
      vend   = ge->mesh_vertices[i];
      if (pass_ == 1)e2r->insert (EdgeToRecover (vstart->getNum(), vend->getNum(),ge));
      else
	{
	  e = m->recover_edge ( vstart->getNum(), vend->getNum(),e2r, not_recovered);
	  if (e)e->g = g;
	  else {
	    //	    Msg(GERROR,"Unable to recover an edge %g %g && %g %g (%d/%d)",vstart->x(),vstart->y(), vend->x(),vend->y(),i,ge->mesh_vertices.size());
	    //	    return false;
	  }
	}
    }    
  vstart = vend;
  vend   = *(ge->getEndVertex()->mesh_vertices.begin());
  if (pass_ == 1)e2r->insert (EdgeToRecover (vstart->getNum(), vend->getNum(),ge));
  else
    {
      e = m->recover_edge ( vstart->getNum(), vend->getNum(),e2r, not_recovered);
      if (e)e->g = g;
      else {
	//	Msg(GERROR,"Unable to recover an edge %g %g && %g %g (%d/%d)",vstart->x(),vstart->y(), vend->x(),vend->y(),ge->mesh_vertices.size(),ge->mesh_vertices.size());
	//	return false;
      }
      BDS_Point *pend = m->find_point(vend->getNum());
      if(!pend->g)
	{
	  m->add_geom (vend->getNum(), 0);
	  BDS_GeomEntity *g0 = m->get_geom(vend->getNum(), 0);
	  pend->g = g0;
	}
    }
  return true;
}


// Builds An initial triangular mesh
// that respects the boundaries of the
// domain, including embedded points 
// and surfaces

bool gmsh2DMeshGenerator ( GFace *gf , int RECUR_ITER, bool debug = true)
{

  //  if (gf->tag() != 21) return true;
  typedef std::set<MVertex*> v_container ;
  v_container all_vertices;
  std::map<int, MVertex*>numbered_vertices;
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*> emb_edges = gf->emb_edges();
  std::list<GEdge*>::iterator it = edges.begin();

//   if (gf->geomType() == GEntity::Cylinder) 
//     {
//       Range<double> rangeU = gf->parBounds(0);
//       Range<double> rangeV = gf->parBounds(1);  
//       double du = rangeU.high() -rangeU.low();
//       double dv = rangeV.high() -rangeV.low();
//       surface_params params = gf->getSurfaceParams();
//       printf("radius of the cylinder %g\n",params.radius);
//   m->scalingU = fabs(du);
//   m->scalingV = fabs(dv);
//   SCALINGU = m->scalingU;
//   SCALINGV = m->scalingV;
//     }



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

  //char tmp[256]; sprintf(tmp, "surf%d.pos", gf->tag());
  //FILE *fdeb = fopen(tmp,"w");
  //fprintf(fdeb,"View \"surf%d\"{\n" ,gf->tag());

  int count = 0;
  SBoundingBox3d bbox;
  while(itv != all_vertices.end()){
    MVertex *here = *itv;
    SPoint2 param;
    if(here->onWhat()->geomType() == GEntity::DiscreteCurve ||
       here->onWhat()->geomType() == GEntity::BoundaryLayerCurve){
      param = gf->parFromPoint(SPoint3(here->x(), here->y(), here->z()));
    }
    else if(here->onWhat()->dim() == 0){
      GVertex *gv = (GVertex*)here->onWhat();
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
    //fprintf(fdeb,"SP(%g,%g,%g){%d};\n" ,here->x(),here->y(),here->z(),here->getNum());
    //fprintf(fdeb,"SP(%g,%g,0){%d};\n" ,param.x(),param.y(),here->getNum());
    U_[count] = param.x();
    V_[count] = param.y();
    (*itv)->setNum(count);
    numbered_vertices[(*itv)->getNum()] = *itv;
    bbox += SPoint3 ( param.x(), param.y() , 0);      
    count ++;
    ++itv;
  }
  
  //fprintf(fdeb,"};\n");
  //fclose(fdeb);

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

      // JFR : the fix was WRONG, I fixed the fix ;-)

      if(num< 0){ // fake bbox points 
	U = bb[-1-num]->x();
	V = bb[-1-num]->y();
      }
      else
      {
	U = U_[num];
	V = V_[num];
      }

      BDS_Point *pp = m->add_point ( num, U,V, gf);
      
      GEntity *ge       = here->onWhat();    
      if(ge->dim() == 0)
	{
	  pp->lcBGM() = BGM_MeshSize(ge,0,0,here->x(),here->y(),here->z());
	}
      else if(ge->dim() == 1)
	{
	 double u;
	 here->getParameter(0,u);	  
	 pp->lcBGM() = BGM_MeshSize(ge,u,0,here->x(),here->y(),here->z());
	  //	  MEdgeVertex *eve = (MEdgeVertex*) here;
	  //	  pp->lcBGM() = eve->getLc();
	}
      else
	  pp->lcBGM() = 1.e22;
	
      pp->lc() = pp->lcBGM();
      //      printf("dim %d lc = %12.5E\n",ge->dim(),pp->lc());


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
  if (debug)
    {
      char name[245];
      sprintf(name,"surface%d-initial-real.pos",gf->tag());
      outputScalarField(m->triangles, name,0);
      sprintf(name,"surface%d-initial-param.pos",gf->tag());
      outputScalarField(m->triangles, name,1);
    }
    
  Msg(DEBUG1,"Recovering %d model Edges",edges.size());
  
  // build a structure with all mesh edges that have to be
  // recovered. If two of these edges intersect, then the
  // 1D mesh have to be densified

  std::set<EdgeToRecover> edgesToRecover;
  std::set<EdgeToRecover> edgesNotRecovered;
  it = edges.begin();
  while(it != edges.end())
    {
      if(!(*it)->is_mesh_degenerated())
	recover_medge ( m, *it, &edgesToRecover, &edgesNotRecovered, 1);
      ++it;
    }
  it = emb_edges.begin();
  while(it != emb_edges.end())
    {
      recover_medge ( m, *it, &edgesToRecover, &edgesNotRecovered, 1);      
      ++it;
    }


  Msg(DEBUG1,"Recovering %d mesh Edges",edgesToRecover.size());
  // effectively recover the medge

  it = edges.begin();
  while(it != edges.end())
    {
      if(!(*it)->is_mesh_degenerated()){
	recover_medge ( m, *it, &edgesToRecover, &edgesNotRecovered, 2);	
      }
      ++it;
    }

  if (edgesNotRecovered.size())
  {
    Msg(WARNING,":-( There exists %d intersections in the 1d mesh",edgesNotRecovered.size());
    Msg(WARNING,"8-| Gmsh splits those edges and tries again");
    std::list<GFace *> facesToRemesh;
    remeshUnrecoveredEdges ( edgesNotRecovered, facesToRemesh);
    delete m;
    delete [] U_;
    delete [] V_;
    if (RECUR_ITER < 10 && facesToRemesh.size() == 0)
      return gmsh2DMeshGenerator (gf, RECUR_ITER+1, debug);    
    return false;
  }
  if (RECUR_ITER > 0)
    Msg(WARNING,":-) Gmsh was able to recover all edges after %d ITERATIONS",RECUR_ITER);

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
      recover_medge ( m, *it, &edgesToRecover, &edgesNotRecovered, 2);
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

  if (debug)
    {
      char name[245];
      sprintf(name,"surface%d-recovered-real.pos",gf->tag());
      outputScalarField(m->triangles, name,0);
      sprintf(name,"surface%d-recovered-param.pos",gf->tag());
      outputScalarField(m->triangles, name,1);
    }

  // start mesh generation
  if (!AlgoDelaunay2D ( gf ))
    {
      //      RefineMesh (gf,*m, 1);
      RefineMesh (gf,*m, CTX.mesh.refine_steps);
      OptimizeMesh(gf, *m, 2);
      RefineMesh (gf,*m, -CTX.mesh.refine_steps);
      OptimizeMesh(gf, *m, -2);

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

  computeMeshSizeFieldAccuracy (gf,*m, gf->meshStatistics.efficiency_index,gf->meshStatistics.longest_edge_length,gf->meshStatistics.smallest_edge_length,gf->meshStatistics.nbEdge,gf->meshStatistics.nbGoodLength);

  gf->meshStatistics.status = GFace::DONE;
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
  if (AlgoDelaunay2D ( gf ))
     {
       insertVerticesInFace (gf,m) ;
       laplaceSmoothing (gf);
     }
  else if (debug){
    char name[256];
    sprintf(name,"real%d.pos",gf->tag());
    outputScalarField(m->triangles, name,0);
    sprintf(name,"param%d.pos",gf->tag());
    outputScalarField(m->triangles, name,1);
  }

  // delete the mesh
  delete m;


  delete [] U_;
  delete [] V_;

  computeElementShapes (gf, gf->meshStatistics.worst_element_shape,gf->meshStatistics.average_element_shape,gf->meshStatistics.best_element_shape,gf->meshStatistics.nbTriangle,gf->meshStatistics.nbGoodQuality);

  return true;

}

// this function buils a list of vertices (BDS) that 
// are consecutive in one given edge loop. We take
// care of periodic surfaces. In the case of periodicty, some
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
				       int &count, double tol)
{

  // for each edge, we build a list of points that 
  // are the mapping of the edge points on the face
  // for seams, we build the list for every side
  // for closed loops, we build it on both senses

  //  printf("new edge loop\n");
  std::map<GEntity*,std::vector<SPoint2> > meshes;
  std::map<GEntity*,std::vector<SPoint2> > meshes_seam;  

  const int _DEBUG = false;

  result.clear();
  
  GEdgeLoop::iter it  = gel.begin();  


  if (_DEBUG)printf("face %d with %d edges\n",gf->tag(),gf->edges().size());

  while (it != gel.end())   
   {
     GEdgeSigned ges = *it ;
      
     std::vector<SPoint2> mesh1d;
     std::vector<SPoint2> mesh1d_seam;

     bool seam = ges.ge->isSeam(gf);
     
     if (_DEBUG)printf("face %d edge %d seam %d (%d %d)\n",gf->tag(),ges.ge->tag(),seam,ges.ge->getBeginVertex()->tag(),ges.ge->getEndVertex()->tag());
     
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
	     if (d < tol) 
	       {
		 if (_DEBUG)printf("d = %12.5E %d\n",d, coords.size());
		 coords.clear();
		 coords = mesh1d;
		 found = GEdgeSigned(1,ge);
		 unordered.erase(it);
		 goto Finalize;
	       }
	     SPoint2 first_coord_reversed = mesh1d_reversed[0];
	     double d_reversed = dist2(last_coord,first_coord_reversed);
	     if (_DEBUG)printf("d_r = %12.5E\n",d_reversed);
	     if (d_reversed < tol) 
	       {
		 if (_DEBUG)printf("d_r = %12.5E\n",d_reversed);
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
		 if (d_seam < tol)
		   {
		     if (_DEBUG)printf("d_seam = %12.5E\n",d_seam);
		     coords.clear();
		     coords = mesh1d_seam;
		     found = (GEdgeSigned(1,ge));
		     unordered.erase(it);
		     goto Finalize;
		   }
		 double d_seam_reversed = dist2(last_coord,first_coord_seam_reversed);
		 if (d_seam_reversed < tol)
		   {
		     if (_DEBUG)printf("d_seam_reversed = %12.5E\n",d_seam_reversed);
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

     if (_DEBUG)printf("Finalize\n");
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
     
     if (_DEBUG)printf("edge %d size %d size %d\n",found.ge->tag(),edgeLoop.size(), coords.size());
     
     std::vector<BDS_Point*>  edgeLoop_BDS;
     for (unsigned int i=0;i<edgeLoop.size();i++)	    
       {
	 MVertex *here     = edgeLoop[i];
	 GEntity *ge       = here->onWhat();    
	 double U,V;
	 SPoint2 param = coords [i];
	 U = param.x() / m->scalingU ;
	 V = param.y() / m->scalingV;	
	 BDS_Point *pp = m->add_point ( count, U,V,gf );
 	 if(ge->dim() == 0)
 	   {
	     pp->lcBGM() = BGM_MeshSize(ge,0,0,here->x(),here->y(),here->z());
 	   }
 	 else if (ge->dim() == 1)
 	   {
	     double u;
	     here->getParameter(0,u);	  
	     pp->lcBGM() = BGM_MeshSize(ge,u,0,here->x(),here->y(),here->z());
// 	     MEdgeVertex *eve = (MEdgeVertex*) here;
// 	     // 	     pp->lc() = BGM_MeshSize(ge,param.x(),param.y(),here->x(),here->y(),here->z());
// 	     pp->lcBGM() = eve->getLc();
 	   }
	 else
	     pp->lcBGM() = 1.e22;

	 pp->lc() = pp->lcBGM();

	 //	 printf("lc = %12.5E\n",pp->lc());

	 m->add_geom (ge->tag(), ge->dim());
	 BDS_GeomEntity *g = m->get_geom(ge->tag(),ge->dim());
	 pp->g = g;
	 if (_DEBUG)printf("point %3d (%8.5f %8.5f) (%2d,%2d)\n",count,pp->u,pp->v,pp->g->classif_tag,pp->g->classif_degree);
	 bbox += SPoint3(U,V,0);	  
	 edgeLoop_BDS.push_back(pp);
	 recover_map[pp] = here;	 
	 count++;
       }     
     last_coord = coords[coords.size()-1];
     if (_DEBUG)printf("last coord %g %g\n",last_coord.x(),last_coord.y());
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

  //  if (gf->tag() != 21) return true;
  std::map<BDS_Point*,MVertex*> recover_map;

  Range<double> rangeU = gf->parBounds(0);
  Range<double> rangeV = gf->parBounds(1);
  
  double du = rangeU.high() -rangeU.low();
  double dv = rangeV.high() -rangeV.low();
  
  const double LC2D = sqrt ( du*du + dv*dv ); 

  //  printf("LC2D %g du %g (%g %g) dv %g\n",LC2D,du,rangeU.high(),rangeU.low(),dv);

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
	if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsTotal, 1.e-7*LC2D))
	  if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsTotal, 1.e-5*LC2D))
	    if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsTotal, 1.e-3*LC2D))
	      {
		gf->meshStatistics.status = GFace::FAILED;
		Msg(GERROR,"The 1D Mesh seems not to be forming a closed loop");
		m->scalingU = m->scalingV = SCALINGU = SCALINGV = 1.0;
		SCALINGV = 1;
		return false;
	      }
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

  if (debug){
    char name[245];
    sprintf(name,"surface%d-initial-real.pos",gf->tag());
    outputScalarField(m->triangles, name,0);
    sprintf(name,"surface%d-initial-param.pos",gf->tag());
    outputScalarField(m->triangles, name,1);
  }


  // build a list of edges to recover
//   std::set<EdgeToRecover> e2r;
//   for (unsigned int i=0;i<edgeLoops_BDS.size();i++)
//     {
//       std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
//       for (unsigned int j=0;j<edgeLoop_BDS.size();j++)
// 	{
// 	  e2r.insert (EdgeToRecover (edgeLoop_BDS[j]->iD,edgeLoop_BDS[(j+1)%edgeLoop_BDS.size()]->iD,ge));
// 	}
//     }


  for (unsigned int i=0;i<edgeLoops_BDS.size();i++){
      std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
      for (unsigned int j=0;j<edgeLoop_BDS.size();j++){
	BDS_Edge * e = m->recover_edge ( edgeLoop_BDS[j]->iD,edgeLoop_BDS[(j+1)%edgeLoop_BDS.size()]->iD);	  
	if (!e){
	  Msg(GERROR,"impossible to recover the edge %d %d",edgeLoop_BDS[j]->iD,edgeLoop_BDS[(j+1)%edgeLoop_BDS.size()]->iD);
	  gf->meshStatistics.status = GFace::FAILED;
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
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if ( e->g  && e->numfaces () == 2){
	BDS_Point *oface[2];
	e->oppositeof(oface);
	if (oface[0]->iD < 0){
	  recur_tag ( e->faces(1) , &CLASS_F); 
	  break;
	}
	else if (oface[1]->iD < 0){
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
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if (!t->g){
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
  
  if (!AlgoDelaunay2D ( gf ))
    {
      RefineMesh (gf,*m,CTX.mesh.refine_steps);
      OptimizeMesh(gf, *m, 2);
      RefineMesh (gf,*m,-CTX.mesh.refine_steps);
      OptimizeMesh(gf, *m, -2);

      if (gf->meshAttributes.recombine)
	{
	  m->recombineIntoQuads (gf->meshAttributes.recombineAngle,gf);
	}
      // compute mesh statistics
      computeMeshSizeFieldAccuracy (gf,*m, gf->meshStatistics.efficiency_index,gf->meshStatistics.longest_edge_length,gf->meshStatistics.smallest_edge_length,gf->meshStatistics.nbEdge,gf->meshStatistics.nbGoodLength);
      gf->meshStatistics.status = GFace::DONE;
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

   if (AlgoDelaunay2D ( gf ))
     {
       insertVerticesInFace (gf,m) ;
       laplaceSmoothing (gf);
     }
 
  delete m; 
  SCALINGU = SCALINGV = 1;
  computeElementShapes (gf, gf->meshStatistics.worst_element_shape,gf->meshStatistics.average_element_shape,gf->meshStatistics.best_element_shape,gf->meshStatistics.nbTriangle,gf->meshStatistics.nbGoodQuality);
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
  gf->deleteVertexArrays();

  gf->meshStatistics.status = GFace::PENDING;
  gf->meshStatistics.nbTriangle = gf->meshStatistics.nbEdge = 0;

}

void meshGFace::operator() (GFace *gf) 
{  
  if(gf->geomType() == GEntity::DiscreteSurface) return;
  if(gf->geomType() == GEntity::BoundaryLayerSurface) return;
  if(gf->geomType() == GEntity::ProjectionFace) return;

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
    if(AlgoDelaunay2D(gf))
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
  if (1 || gf->tag() == 6)
    {
      Msg(DEBUG1, "Generating the mesh");
      if(noseam (gf) || gf->getNativeType() == GEntity::GmshModel || gf->edgeLoops.empty()){
	//gmsh2DMeshGenerator(gf,0, true);
	gmsh2DMeshGenerator(gf,0, false);
      }
      else{
	if(!gmsh2DMeshGeneratorPeriodic(gf,false))
	  Msg(GERROR, "Impossible to mesh face %d", gf->tag());
      }
    }
  else
    gf->meshStatistics.status = GFace::DONE;
  
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
  if(gf->geomType() == GEntity::ProjectionFace) return;

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
