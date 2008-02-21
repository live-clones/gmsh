// $Id: meshGFace.cpp,v 1.118 2008-02-21 13:34:40 geuzaine Exp $
//
// Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
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
#include "meshGFaceBDS.h"
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

void computeElementShapes(GFace *gf, double &worst, double &avg, double &best,
			  int &nT, int &greaterThan)
{
  worst = 1.e22;
  avg = 0.0;
  best = 0.0;
  nT = 0;
  greaterThan = 0;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    double q = qmTriangle(gf->triangles[i], QMTRI_RHO);
    if(q > .9) greaterThan++;
    avg += q;
    worst = std::min(worst, q);
    best  = std::max(best, q);
    nT++;
  }
  avg /= nT;
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
  std::list<GEdge*> emb_edges = gf->embeddedEdges();
  std::list<GEdge*>::iterator it = edges.begin();

  // build a set with all points of the boundaries
  it = edges.begin();
  while(it != edges.end())
    {
      if ((*it)->isSeam(gf))return false;
      if(!(*it)->isMeshDegenerated()){
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

  for(int i = 0; i < doc.numTriangles; i++) {
    MVertex *V1 = (MVertex*)doc.points[doc.delaunay[i].t.a].data;
    MVertex *V2 = (MVertex*)doc.points[doc.delaunay[i].t.b].data;
    MVertex *V3 = (MVertex*)doc.points[doc.delaunay[i].t.c].data;
    m->add_triangle ( V1->getNum(), V2->getNum(), V3->getNum() );
  }
  free (doc.points);
  free (doc.delaunay);
  for ( int ip = 0 ; ip<4 ; ip++ ) delete bb[ip];


  // Free stuff


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
      if(!(*it)->isMeshDegenerated())
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
      if(!(*it)->isMeshDegenerated()){
	recover_medge(m, *it, &edgesToRecover, &edgesNotRecovered, 2);
      }
      ++it;
    }

  if (edgesNotRecovered.size())
  {
    Msg(WARNING,":-( There exists %d intersections in the 1d mesh",edgesNotRecovered.size());
    Msg(WARNING,"8-| Gmsh splits those edges and tries again");
    std::list<GFace *> facesToRemesh;
    remeshUnrecoveredEdges ( edgesNotRecovered, facesToRemesh);
    std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
    for ( ; itr != edgesNotRecovered.end() ; ++itr)
    {
      int p1 = itr->p1;
      int p2 = itr->p2;
      int tag = itr->ge->tag();
      Msg(WARNING,"MEdge %d %d in GEdge %d",p1,p2,tag);
    }


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

  int nb_swap;
  //  outputScalarField(m->triangles, "beforeswop.pos",1);

  gmshDelaunayizeBDS ( gf, *m, nb_swap );

  //  outputScalarField(m->triangles, "afterswop.pos",0);

  // start mesh generation
  if (!AlgoDelaunay2D ( gf ))
    {
      //      RefineMesh (gf,*m, 1);
      gmshRefineMeshBDS (gf,*m, CTX.mesh.refine_steps,true);
      gmshOptimizeMeshBDS(gf, *m, 2);
      gmshRefineMeshBDS (gf,*m, CTX.mesh.refine_steps,false);
      gmshOptimizeMeshBDS(gf, *m, 2);

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
    outputScalarField(m->triangles, name,0,gf);
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

// bool buildConsecutiveListOfVertices_b (  GFace *gf,
// 					 GEdgeLoop  &gel ,
// 					 std::vector<BDS_Point*> &result,
// 					 SBoundingBox3d &bbox,
// 					 BDS_Mesh *m,
// 					 std::map<BDS_Point*,MVertex*> &recover_map,
// 					 int &count, double tol){
//   std::map<GEntity*,std::vector<SPoint2> > meshes;
//   std::map<GEntity*,std::vector<SPoint2> > meshes_seam;

//   result.clear();

//   GEdgeLoop::iter it  = gel.begin();

//   while (it != gel.end())
//    {
//      // I get the signed edge
//      GEdgeSigned ges = *it ;
//      std::vector<SPoint2> mesh1d;
//      // I look if it is a seam
//      bool seam = ges.ge->isSeam(gf);
//      // I get parameter bounds
//      Range<double> range = ges.ge->parBounds(0);
//      // I Get the first vertex
//      MVertex *here = ges.ge->getBeginVertex()->mesh_vertices[0];
//      if ( seam && ges._sign == 0 )mesh1d.push_back(ges.ge->reparamOnFace(gf,range.low(),-1));
//      else mesh1d.push_back(ges.ge->reparamOnFace(gf,range.low(),1));
//      for (unsigned int i=0;i<ges.ge->mesh_vertices.size();i++)
//        {
// 	 double u;
// 	 here = ges.ge->mesh_vertices[i];
// 	 here->getParameter(0,u);
// 	 if ( seam && ges._sign == 0) mesh1d.push_back(ges.ge->reparamOnFace(gf,u,-1));
// 	 else mesh1d.push_back(ges.ge->reparamOnFace(gf,u,1));
//        }
//      here = ges.ge->getEndVertex()->mesh_vertices[0];
//      if ( seam && ges._sign == 0) mesh1d.push_back(ges.ge->reparamOnFace(gf,range.high(),-1));
//      else mesh1d.push_back(ges.ge->reparamOnFace(gf,range.high(),1));
//      it++;
//    }
// }


void printMesh1d (int iEdge, int seam, std::vector<SPoint2> &m){
  printf("Mesh1D for edge %d seam %d\n",iEdge,seam);
  for (unsigned int i = 0; i < m.size(); i++){
    printf("%12.5E %12.5E\n",m[i].x(),m[i].y());
  }
}

bool buildConsecutiveListOfVertices (  GFace *gf,
				       GEdgeLoop  &gel ,
				       std::vector<BDS_Point*> &result,
				       SBoundingBox3d &bbox,
				       BDS_Mesh *m,
				       std::map<BDS_Point*,MVertex*> &recover_map_global,
				       int &count, int countTot, double tol, bool seam_the_first = false)
{

  // for each edge, we build a list of points that
  // are the mapping of the edge points on the face
  // for seams, we build the list for every side
  // for closed loops, we build it on both senses

  std::map<GEntity*,std::vector<SPoint2> > meshes;
  std::map<GEntity*,std::vector<SPoint2> > meshes_seam;

  const int MYDEBUG = false;

  std::map<BDS_Point*,MVertex*> recover_map;

  result.clear();
  count = 0;

  GEdgeLoop::iter it  = gel.begin();

  if (MYDEBUG)printf("face %d with %d edges case %d\n",gf->tag(), (int)gf->edges().size(),seam_the_first);

  while (it != gel.end())
   {
     GEdgeSigned ges = *it ;

     std::vector<SPoint2> mesh1d;
     std::vector<SPoint2> mesh1d_seam;

     bool seam = ges.ge->isSeam(gf);

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

     //     printMesh1d (ges.ge->tag(), seam, mesh1d);
     //     if (seam)printMesh1d (ges.ge->tag(), seam, mesh1d_seam);

     it++;
   }


  std::list<GEdgeSigned> unordered;
  unordered.insert(unordered.begin(),gel.begin(),gel.end());

  GEdgeSigned found(0,0);

  SPoint2 last_coord(0,0);
  int counter = 0;

  while (unordered.size())
   {
     if (MYDEBUG)printf("unordered.size() = %d\n", (int)unordered.size());
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
	     if (seam && seam_the_first){
	       coords = ((*it)._sign == 1)?mesh1d_seam:mesh1d_seam_reversed;
	       found = (*it);
	       Msg(INFO,"This test case would have failed in Previous Gmsh Version ;-)");
	     }
	     else{
	       coords = ((*it)._sign == 1)?mesh1d:mesh1d_reversed;
	       found = (*it);
	     }
	     unordered.erase(it);
	     if (MYDEBUG)printf("Starting with edge = %d seam %d\n",(*it).ge->tag(),seam);
	     break;
	   }
	 else
	   {
	     if (MYDEBUG)printf("Followed by edge = %d\n",(*it).ge->tag());
	     SPoint2 first_coord         = mesh1d[0];
	     double d=-1,d_reversed=-1,d_seam=-1,d_seam_reversed=-1;
	     d = dist2(last_coord,first_coord);
	     if (MYDEBUG)printf("%g %g dist = %12.5E\n",first_coord.x(),first_coord.y(),d);
	     if (d < tol)
	       {
		 //		 if (MYDEBUG)printf("d = %12.5E %d\n",d, (int)coords.size());
		 coords.clear();
		 coords = mesh1d;
		 found = GEdgeSigned(1,ge);
		 unordered.erase(it);
		 goto Finalize;
	       }
	     SPoint2 first_coord_reversed = mesh1d_reversed[0];
	     d_reversed = dist2(last_coord,first_coord_reversed);
	     if (MYDEBUG)printf("%g %g dist_reversed = %12.5E\n",first_coord_reversed.x(),first_coord_reversed.y(),d_reversed);
	     if (d_reversed < tol)
	       {
		 //		 if (MYDEBUG)printf("d_r = %12.5E\n",d_reversed);
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
		 d_seam = dist2(last_coord,first_coord_seam);
		 if (MYDEBUG)printf("dist_seam = %12.5E\n",d_seam);
		 if (d_seam < tol)
		   {
		     coords.clear();
		     coords = mesh1d_seam;
		     found = (GEdgeSigned(1,ge));
		     unordered.erase(it);
		     goto Finalize;
		   }
		 d_seam_reversed = dist2(last_coord,first_coord_seam_reversed);
		 if (MYDEBUG)printf("dist_seam_reversed = %12.5E\n",d_seam_reversed);
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

     if (MYDEBUG) printf("Finalize, found %d points\n", (int)coords.size());
     if (coords.size() == 0){
       // It has not worked : either tolerance is wrong or the first seam edge
       // has to be taken with the other parametric coordinates (because it is
       // only present once in the closure of the domain).
       for (std::map<BDS_Point*,MVertex*> :: iterator it = recover_map.begin();
	    it != recover_map.end(); ++it){
	 m->del_point(it->first);
       }
       return false;
     }

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

     if (MYDEBUG)
       printf("edge %d size %d size %d\n",
	      found.ge->tag(), (int)edgeLoop.size(), (int)coords.size());

     std::vector<BDS_Point*>  edgeLoop_BDS;
     for (unsigned int i=0;i<edgeLoop.size();i++)
       {
	 MVertex *here     = edgeLoop[i];
	 GEntity *ge       = here->onWhat();
	 double U,V;
	 SPoint2 param = coords [i];
	 U = param.x() / m->scalingU ;
	 V = param.y() / m->scalingV;
	 BDS_Point *pp = m->add_point ( count+countTot, U,V,gf );
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
	 if (MYDEBUG)
	   printf("point %3d (%8.5f %8.5f : %8.5f %8.5f) (%2d,%2d)\n",
		  count,pp->u,pp->v,param.x(),param.y(),pp->g->classif_tag,
		  pp->g->classif_degree);
	 bbox += SPoint3(U,V,0);
	 edgeLoop_BDS.push_back(pp);
	 recover_map[pp] = here;
	 count++;
       }
     last_coord = coords[coords.size()-1];
     if (MYDEBUG)printf("last coord %g %g\n",last_coord.x(),last_coord.y());
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
  // It has worked, so we add all the points to the recover map
  recover_map_global.insert(recover_map.begin(),recover_map.end());

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
  std::vector< std::vector<BDS_Point* > > edgeLoops_BDS;
  SBoundingBox3d bbox;
  int nbPointsTotal = 0;
  {
    for (std::list<GEdgeLoop>::iterator it = gf->edgeLoops.begin() ; it != gf->edgeLoops.end() ; it++)
      {
	std::vector<BDS_Point* > edgeLoop_BDS;
	int nbPointsLocal;
	if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsLocal, nbPointsTotal, 1.e-7*LC2D))
	  if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsLocal, nbPointsTotal, 1.e-7*LC2D,true))
	    if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsLocal, nbPointsTotal, 1.e-5*LC2D))
	      if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsLocal, nbPointsTotal, 1.e-5*LC2D,true))
		if(!buildConsecutiveListOfVertices ( gf, *it , edgeLoop_BDS, bbox, m, recover_map , nbPointsLocal, nbPointsTotal, 1.e-3*LC2D))
		  {
		    gf->meshStatistics.status = GFace::FAILED;
		    Msg(GERROR,"The 1D Mesh seems not to be forming a closed loop");
		    m->scalingU = m->scalingV = 1.0;
		    return false;
		  }
	nbPointsTotal += nbPointsLocal;
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
      gmshRefineMeshBDS (gf,*m,CTX.mesh.refine_steps,true);
      gmshOptimizeMeshBDS(gf, *m, 2);
      gmshRefineMeshBDS (gf,*m,-CTX.mesh.refine_steps,false);
      gmshOptimizeMeshBDS(gf, *m, 2,&recover_map);

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
	    MVertex *v = new MFaceVertex (p->X,p->Y,p->Z,gf,m->scalingU*p->u,m->scalingV*p->v);
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
      outputScalarField(m->triangles, name,0,gf);
      sprintf(name,"surface%d-final-param.pos",gf->tag());
      outputScalarField(m->triangles, name,1);
    }

   if (AlgoDelaunay2D ( gf ))
     {
       insertVerticesInFace (gf,m) ;
       laplaceSmoothing (gf);
     }

  delete m;
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
  if (1 || gf->tag() == 46)
    {
      Msg(DEBUG1, "Generating the mesh");
      if(noseam (gf) || gf->getNativeType() == GEntity::GmshModel || gf->edgeLoops.empty()){
	//	gmsh2DMeshGenerator(gf,0, true);
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
