// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <sstream>
#include <stdlib.h>
#include "meshGFace.h"
#include "meshGFaceBDS.h"
#include "meshGFaceDelaunayInsertion.h"
#include "meshGFaceQuadrilateralize.h"
#include "meshGFaceOptimize.h"
#include "DivideAndConquer.h"
#include "BackgroundMesh.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GEdgeCompound.h"
#include "GFace.h"
#include "GModel.h"
#include "MVertex.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "Context.h"
#include "GPoint.h"
#include "GmshMessage.h"
#include "Numeric.h"
#include "BDS.h"
#include "qualityMeasures.h"
#include "Field.h"
#include "OS.h"
#include "HighOrder.h"
#include "meshGEdge.h"
#include "meshPartitionOptions.h"
#include "meshPartition.h"
#include "CreateFile.h"
#include "Context.h"
#include "multiscalePartition.h"
#include "meshGFaceLloyd.h"

static void copyMesh (GFace *source, GFace *target)
{
  std::map<MVertex*,MVertex*> vs2vt;
  
  std::list<GEdge*> edges = target->edges();
  for (std::list<GEdge*>::iterator it = edges.begin(); it!=edges.end(); ++it){
    GEdge *te = *it;
    int master = te->meshMaster();
    if (master == te->tag()){
      Msg::Error("Periodic face %d does not have periodic edges (master %d -- edge %d)",
                 target->tag(), master, te->tag());      
    }
    GEdge *se  = source->model()->getEdgeByTag(abs(master));
    if (master > 0){
      vs2vt[se->getBeginVertex()->mesh_vertices[0]] = te->getBeginVertex()->mesh_vertices[0];
      vs2vt[se->getEndVertex()->mesh_vertices[0]] = te->getEndVertex()->mesh_vertices[0];
      for (unsigned i=0;i<se->mesh_vertices.size();i++){
	MVertex *vs = se->mesh_vertices[i];
	MVertex *vt = te->mesh_vertices[i];
	vs2vt[vs] = vt;
      }
    }
    else {
      vs2vt[se->getEndVertex()->mesh_vertices[0]] = te->getBeginVertex()->mesh_vertices[0];
      vs2vt[se->getBeginVertex()->mesh_vertices[0]] = te->getEndVertex()->mesh_vertices[0];
      for (unsigned i=0;i<se->mesh_vertices.size();i++){
	MVertex *vs = se->mesh_vertices[i];
	MVertex *vt = te->mesh_vertices[se->mesh_vertices.size()-i-1];
	vs2vt[vs] = vt;
      }
    }
  }

  std::map<MVertex*,MVertex*>::iterator it = vs2vt.begin();
  
  SPoint2 param_source[2],param_target[2];
  int count = 0;
  for (; it != vs2vt.end() ; ++it){
    MVertex *vs = it->first;
    MVertex *vt = it->second;
    if (vs->onWhat()->dim() == 1){
      bool success1 = reparamMeshVertexOnFace(vs, source, param_source[count]);
      bool success2 = reparamMeshVertexOnFace(vt, target, param_target[count++]);
      if (count == 2) break;
    }
  }

  if (count < 2) return;
  
  const double t1u = param_target[0].x();
  const double t1v = param_target[0].y();
  const double t2u = param_target[1].x();
  const double t2v = param_target[1].y();
  const double s1u = param_source[0].x();
  const double s1v = param_source[0].y();
  const double s2u = param_source[1].x();
  const double s2v = param_source[1].y();

  SVector3 _a(s2u-s1u,s2v-s1v,0);
  SVector3 _b(t2u-t1u,t2v-t1v,0);
  SVector3 _c = crossprod(_a,_b);
  double sinA = _c.z();
  double cosA = dot(_a,_b);
  const double theta = atan2(sinA, cosA);
  const double c = cos(theta);
  const double s = sin(theta);

  for(unsigned int i = 0; i < source->mesh_vertices.size(); i++){
    MVertex *vs = source->mesh_vertices[i];
    double u,v;
    vs->getParameter(0,u);
    vs->getParameter(1,v);
    // apply transformation
    const double U =   c * (u-s1u) + s * (v-s1v) + t1u;
    const double V =  -s * (u-s1u) + c * (v-s1v) + t1v;
    GPoint gp = target->point(SPoint2(U,V));
    MVertex *vt = new MFaceVertex(gp.x(), gp.y(), gp.z(), target,U,V);
    target->mesh_vertices.push_back(vt);
    vs2vt[vs] = vt;    
  }

  for (unsigned i=0;i<source->triangles.size();i++){
    MVertex *v1 = vs2vt[source->triangles[i]->getVertex(0)];
    MVertex *v2 = vs2vt[source->triangles[i]->getVertex(1)];
    MVertex *v3 = vs2vt[source->triangles[i]->getVertex(2)];
    target->triangles.push_back(new MTriangle(v1,v2,v3));
  }
  for (unsigned i=0;i<source->quadrangles.size();i++){
    MVertex *v1 = vs2vt[source->quadrangles[i]->getVertex(0)];
    MVertex *v2 = vs2vt[source->quadrangles[i]->getVertex(1)];
    MVertex *v3 = vs2vt[source->quadrangles[i]->getVertex(2)];
    MVertex *v4 = vs2vt[source->quadrangles[i]->getVertex(3)];
    target->quadrangles.push_back(new MQuadrangle(v1,v2,v3,v4));
  }
}

void fourthPoint(double *p1, double *p2, double *p3, double *p4)
{
  double c[3];
  circumCenterXYZ(p1, p2, p3, c);
  double vx[3] = {p2[0] - p1[0], p2[1] - p1[1], p2[2] - p1[2]};
  double vy[3] = {p3[0] - p1[0], p3[1] - p1[1], p3[2] - p1[2]};
  double vz[3]; prodve(vx, vy, vz);
  norme(vz);
  double R = sqrt((p1[0] - c[0]) * (p1[0] - c[0]) +
                  (p1[1] - c[1]) * (p1[1] - c[1]) +
                  (p1[2] - c[2]) * (p1[2] - c[2]));
  p4[0] = c[0] + R * vz[0];
  p4[1] = c[1] + R * vz[1];
  p4[2] = c[2] + R * vz[2];
}

static bool noSeam(GFace *gf)
{
  std::list<GEdge*> edges = gf->edges();
  std::list<GEdge*>::iterator it = edges.begin();
  while (it != edges.end()){
    GEdge *ge = *it ;
    bool seam = ge->isSeam(gf);
    if(seam) return false;
    ++it;
  }
  return true;
}

static void remeshUnrecoveredEdges(std::map<MVertex*, BDS_Point*> &recoverMapInv,
                                   std::set<EdgeToRecover> &edgesNotRecovered, 
                                   std::list<GFace*> &facesToRemesh)
{
  facesToRemesh.clear();
  deMeshGFace dem;

  std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
  for(; itr != edgesNotRecovered.end(); ++itr){
    std::list<GFace*> l_faces = itr->ge->faces();
    // un-mesh model faces adjacent to the model edge
    for(std::list<GFace*>::iterator it = l_faces.begin(); it != l_faces.end(); ++it){
      if((*it)->triangles.size() || (*it)->quadrangles.size()){
        facesToRemesh.push_back(*it);
        dem(*it);
      }
    }
    
    // add a new point in the middle of the intersecting segment
    int p1 = itr->p1;
    int p2 = itr->p2;
    int N = itr->ge->lines.size();
    GVertex *g1 = itr->ge->getBeginVertex();
    GVertex *g2 = itr->ge->getEndVertex();
    Range<double> bb = itr->ge->parBounds(0);

    std::vector<MLine*> newLines;

    for(int i = 0; i < N; i++){
      MVertex *v1 = itr->ge->lines[i]->getVertex(0);
      MVertex *v2 = itr->ge->lines[i]->getVertex(1);
      std::map<MVertex*, BDS_Point*>::iterator itp1 = recoverMapInv.find(v1);
      std::map<MVertex*, BDS_Point*>::iterator itp2 = recoverMapInv.find(v2);
      if(itp1 != recoverMapInv.end() && itp2 != recoverMapInv.end()){
        BDS_Point *pp1 = itp1->second;
        BDS_Point *pp2 = itp2->second;
        if((pp1->iD == p1 && pp2->iD == p2) || (pp1->iD == p2 && pp2->iD == p1)){
          double t1;
          double lc1 = -1;
          if(v1->onWhat() == g1) t1 = bb.low();
          else if(v1->onWhat() == g2) t1 = bb.high();
          else {
            MEdgeVertex *ev1 = (MEdgeVertex*)v1;
            lc1 = ev1->getLc();
            v1->getParameter(0, t1);
          }
          double t2;
          double lc2 = -1;
          if(v2->onWhat() == g1) t2 = bb.low();
          else if(v2->onWhat() == g2) t2 = bb.high();
          else {
            MEdgeVertex *ev2 = (MEdgeVertex*)v2;
            lc2 = ev2->getLc();
            v2->getParameter(0, t2);
          }
          
          // periodic
          if(v1->onWhat() == g1 && v1->onWhat() == g2)
            t1 = fabs(t2-bb.low()) < fabs(t2-bb.high()) ? bb.low() : bb.high();
          if(v2->onWhat() == g1 && v2->onWhat() == g2)
            t2 = fabs(t1-bb.low()) < fabs(t1-bb.high()) ? bb.low() : bb.high();
          
          if(lc1 == -1)
            lc1 = BGM_MeshSize(v1->onWhat(), 0, 0, v1->x(), v1->y(), v1->z());
          if(lc2 == -1)
            lc2 = BGM_MeshSize(v2->onWhat(), 0, 0, v2->x(), v2->y(), v2->z());
          // should be better, i.e. equidistant
          double t = 0.5 * (t2 + t1);
          double lc = 0.5 * (lc1 + lc2);
          GPoint V = itr->ge->point(t);
          MEdgeVertex * newv = new MEdgeVertex(V.x(), V.y(), V.z(), itr->ge, t, lc);
          newLines.push_back(new MLine(v1, newv));
          newLines.push_back(new MLine(newv, v2));
          delete itr->ge->lines[i];
        }
        else{
          newLines.push_back(itr->ge->lines[i]);
        }
      }
      else {
        newLines.push_back(itr->ge->lines[i]);
      }
    }

    itr->ge->lines = newLines;
    itr->ge->mesh_vertices.clear();
    N = itr->ge->lines.size();
    for(int i = 1; i < N; i++){
      itr->ge->mesh_vertices.push_back(itr->ge->lines[i]->getVertex(0));
    }
  }
}

static bool algoDelaunay2D(GFace *gf)
{
  if(noSeam(gf) && (CTX::instance()->mesh.algo2d == ALGO_2D_DELAUNAY || 
                    CTX::instance()->mesh.algo2d == ALGO_2D_FRONTAL))
    return true;
  return false;
}

static void computeElementShapes(GFace *gf, double &worst, double &avg, 
                                 double &best, int &nT, int &greaterThan)
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

static bool recoverEdge(BDS_Mesh *m, GEdge *ge, 
                        std::map<MVertex*, BDS_Point*> &recoverMapInv,
                        std::set<EdgeToRecover> *e2r,
                        std::set<EdgeToRecover> *notRecovered, int pass)
{
  BDS_GeomEntity *g = 0;
  if(pass == 2){
    m->add_geom(ge->tag(), 1);
    g = m->get_geom(ge->tag(), 1);
  }
  
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MVertex *vstart = ge->lines[i]->getVertex(0);
    MVertex *vend = ge->lines[i]->getVertex(1);
    std::map<MVertex*, BDS_Point*>::iterator itpstart = recoverMapInv.find(vstart);
    std::map<MVertex*, BDS_Point*>::iterator itpend = recoverMapInv.find(vend);
    if(itpstart != recoverMapInv.end() && itpend != recoverMapInv.end()){
      BDS_Point *pstart = itpstart->second;
      BDS_Point *pend = itpend->second;
      if(pass == 1) 
        e2r->insert(EdgeToRecover(pstart->iD, pend->iD, ge));
      else{
        BDS_Edge *e = m->recover_edge(pstart->iD, pend->iD, e2r, notRecovered);
        if(e) e->g = g;
        // else {
        //   Msg::Error("Unable to recover an edge %g %g && %g %g (%d/%d)",
        //              vstart->x(), vstart->y(), vend->x(), vend->y(), i, 
        //              ge->mesh_vertices.size());
        //   return false;
        // }
      }
    }
  }

  if(pass == 2 && ge->getBeginVertex()){
    MVertex *vstart = *(ge->getBeginVertex()->mesh_vertices.begin());
    MVertex *vend = *(ge->getEndVertex()->mesh_vertices.begin());    
    std::map<MVertex*, BDS_Point*>::iterator itpstart = recoverMapInv.find(vstart);
    std::map<MVertex*, BDS_Point*>::iterator itpend = recoverMapInv.find(vend);
    if(itpstart != recoverMapInv.end() && itpend != recoverMapInv.end()){
      BDS_Point *pstart = itpstart->second;
      BDS_Point *pend = itpend->second;
      if(!pstart->g){
        m->add_geom(pstart->iD, 0);
        BDS_GeomEntity *g0 = m->get_geom(pstart->iD, 0);
        pstart->g = g0;
      }
      if(!pend->g){
        m->add_geom(pend->iD, 0);
        BDS_GeomEntity *g0 = m->get_geom(pend->iD, 0);
        pend->g = g0;
      }
    }
  }

  return true;
}

// Builds An initial triangular mesh that respects the boundaries of
// the domain, including embedded points and surfaces
static bool meshGenerator(GFace *gf, int RECUR_ITER, 
                          bool repairSelfIntersecting1dMesh,
                          bool debug = true)
{
  BDS_GeomEntity CLASS_F(1, 2);
  std::map<BDS_Point*, MVertex*> recoverMap;
  std::map<MVertex*, BDS_Point*> recoverMapInv;
  std::list<GEdge*> edges = gf->edges();

  // replace edges by their compounds
  // if necessary split compound and remesh parts
  bool isMeshed = false;
  if(gf->geomType() == GEntity::CompoundSurface){
    isMeshed = checkMeshCompound((GFaceCompound*) gf, edges);
    if (isMeshed) return true;
  }
 
  // build a set with all points of the boundaries
  std::set<MVertex*> all_vertices;

  std::list<GEdge*>::iterator it = edges.begin();
  while(it != edges.end()){
    if((*it)->isSeam(gf)) return false;
    if(!(*it)->isMeshDegenerated()){
      for(unsigned int i = 0; i< (*it)->lines.size(); i++){
        all_vertices.insert((*it)->lines[i]->getVertex(0));
        all_vertices.insert((*it)->lines[i]->getVertex(1));
      }
    }
    else
      printf("edge %d degenerated mesh \n", (*it)->tag());
    ++it;
  }

  std::list<GEdge*> emb_edges = gf->embeddedEdges();
  it = emb_edges.begin();
  while(it != emb_edges.end()){
    if(!(*it)->isMeshDegenerated()){
      all_vertices.insert((*it)->mesh_vertices.begin(),
                          (*it)->mesh_vertices.end() );      
      all_vertices.insert((*it)->getBeginVertex()->mesh_vertices.begin(),
                          (*it)->getBeginVertex()->mesh_vertices.end());
      all_vertices.insert((*it)->getEndVertex()->mesh_vertices.begin(),
                          (*it)->getEndVertex()->mesh_vertices.end());
    }
    ++it;
  }
 
  // add embedded vertices
  std::list<GVertex*> emb_vertx = gf->embeddedVertices();
  std::list<GVertex*>::iterator itvx = emb_vertx.begin();
  while(itvx != emb_vertx.end()){
    all_vertices.insert((*itvx)->mesh_vertices.begin(),
                        (*itvx)->mesh_vertices.end());
    ++itvx;
  }
 
  // add _additional_vertices 
  all_vertices.insert(gf->_additional_vertices.begin(),
                      gf->_additional_vertices.end());


  if(all_vertices.size() < 3){
    Msg::Warning("Mesh Generation of Model Face %d Skipped: "
                 "Only %d Mesh Vertices on The Contours",
                 gf->tag(), all_vertices.size());
    gf->meshStatistics.status = GFace::DONE;
    return true;
  }

  // Buid a BDS_Mesh structure that is convenient for doing the actual
  // meshing procedure
  BDS_Mesh *m = new BDS_Mesh;
  m->scalingU = 1;
  m->scalingV = 1;

  std::vector<BDS_Point*> points(all_vertices.size());
  SBoundingBox3d bbox;
  int count = 0;
  for(std::set<MVertex*>::iterator it = all_vertices.begin(); 
      it != all_vertices.end(); it++){
    MVertex *here = *it;
    GEntity *ge = here->onWhat();
    SPoint2 param;
    reparamMeshVertexOnFace(here, gf, param);
    BDS_Point *pp = m->add_point(count, param[0], param[1], gf);
    m->add_geom(ge->tag(), ge->dim());
    BDS_GeomEntity *g = m->get_geom(ge->tag(), ge->dim());
    pp->g = g;
    recoverMap[pp] = here;
    recoverMapInv[here] = pp;
    points[count] = pp;
    bbox += SPoint3(param[0], param[1], 0);
    count++;
  }
  all_vertices.clear();

  // compute the bounding box in parametric space
  SVector3 dd(bbox.max(), bbox.min());
  double LC2D = norm(dd);

  // use a divide & conquer type algorithm to create a triangulation.
  // We add to the triangulation a box with 4 points that encloses the
  // domain.
  {
    DocRecord doc(points.size() + 4);
    for(unsigned int i = 0; i < points.size(); i++){
      double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
        (double)RAND_MAX;
      double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
        (double)RAND_MAX;
      doc.points[i].where.h = points[i]->u + XX;
      doc.points[i].where.v = points[i]->v + YY;
      doc.points[i].data = points[i];
      doc.points[i].adjacent = NULL;
    }
    
    // increase the size of the bounding box
    bbox *= 2.5;

    // add 4 points than encloses the domain (use negative number to
    // distinguish those fake vertices)
    double bb[4][2] = {{bbox.min().x(), bbox.min().y()},
                       {bbox.min().x(), bbox.max().y()},
                       {bbox.max().x(), bbox.min().y()},
                       {bbox.max().x(), bbox.max().y()}};
    for(int ip = 0; ip < 4; ip++){
      BDS_Point *pp = m->add_point(-ip - 1, bb[ip][0], bb[ip][1], gf);
      m->add_geom(gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
      doc.points[points.size() + ip].where.h = bb[ip][0];
      doc.points[points.size() + ip].where.v = bb[ip][1];
      doc.points[points.size() + ip].adjacent = 0;
      doc.points[points.size() + ip].data = pp;
    }
    
    // Use "fast" inhouse recursive algo to generate the triangulation.
    // At this stage the triangulation is not what we need
    //   -) It does not necessary recover the boundaries
    //   -) It contains triangles outside the domain (the first edge
    //      loop is the outer one)
    Msg::Debug("Meshing of the convex hull (%d points)", points.size());
    doc.MakeMeshWithPoints();
    Msg::Debug("Meshing of the convex hull (%d points) done", points.size());
    
    for(int i = 0; i < doc.numTriangles; i++) {
      BDS_Point *p1 = (BDS_Point*)doc.points[doc.triangles[i].a].data;
      BDS_Point *p2 = (BDS_Point*)doc.points[doc.triangles[i].b].data;
      BDS_Point *p3 = (BDS_Point*)doc.points[doc.triangles[i].c].data;
      m->add_triangle(p1->iD, p2->iD, p3->iD);
    }

    if(debug && RECUR_ITER == 0){
      char name[245];
      sprintf(name, "surface%d-initial-real.pos", gf->tag());
      outputScalarField(m->triangles, name, 0);
      sprintf(name, "surface%d-initial-param.pos", gf->tag());
      outputScalarField(m->triangles, name, 1);
    }

    // Recover the boundary edges and compute characteristic lenghts
    // using mesh edge spacing. If two of these edges intersect, then
    // the 1D mesh have to be densified
    Msg::Debug("Recovering %d model Edges", edges.size());
    std::set<EdgeToRecover> edgesToRecover;
    std::set<EdgeToRecover> edgesNotRecovered;
    it = edges.begin();
    while(it != edges.end()){
      if(!(*it)->isMeshDegenerated())
        recoverEdge
          (m, *it, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 1);
      ++it;
    }
    it = emb_edges.begin();
    while(it != emb_edges.end()){
      if(!(*it)->isMeshDegenerated())
        recoverEdge
          (m, *it, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 1);
      ++it;
    }
    
    Msg::Debug("Recovering %d mesh Edges", edgesToRecover.size());
    
    // effectively recover the medge
    it = edges.begin();
    while(it != edges.end()){
      if(!(*it)->isMeshDegenerated()){
        recoverEdge
          (m, *it, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 2);
      }
      ++it;
    }
    
    if(edgesNotRecovered.size()){
      std::ostringstream sstream;
      for(std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
          itr != edgesNotRecovered.end(); ++itr)
        sstream << " " << itr->ge->tag();
      Msg::Warning(":-( There are %d intersections in the 1D mesh (curves%s)",
                   edgesNotRecovered.size(), sstream.str().c_str());
      Msg::Warning("8-| Gmsh splits those edges and tries again");
    
      if(debug){
        char name[245];
        sprintf(name, "surface%d-not_yet_recovered-real-%d.msh", gf->tag(), 
                RECUR_ITER);
        gf->model()->writeMSH(name);
      }
      
      std::list<GFace *> facesToRemesh;
      if(repairSelfIntersecting1dMesh) 
        remeshUnrecoveredEdges(recoverMapInv, edgesNotRecovered, facesToRemesh);
      else{
        std::set<EdgeToRecover>::iterator itr = edgesNotRecovered.begin();
        int *_error = new int[3 * edgesNotRecovered.size()];
        int I = 0;
        for(; itr != edgesNotRecovered.end(); ++itr){
          int p1 = itr->p1;
          int p2 = itr->p2;
          int tag = itr->ge->tag();
          _error[3 * I + 0] = p1;
          _error[3 * I + 1] = p2;
          _error[3 * I + 2] = tag;
          I++;
        }
        throw _error;
      }

      // delete the mesh
      delete m;
      if(RECUR_ITER < 10 && facesToRemesh.size() == 0)
        return meshGenerator
          (gf, RECUR_ITER + 1, repairSelfIntersecting1dMesh, debug);
      return false;
    }

    if(RECUR_ITER > 0)
      Msg::Warning(":-) Gmsh was able to recover all edges after %d iterations",
                   RECUR_ITER);    
    
    Msg::Debug("Boundary Edges recovered for surface %d", gf->tag());
     
    // Look for an edge that is on the boundary for which one of the
    // two neighbors has a negative number node. The other triangle is
    // inside the domain and, because all edges were recovered,
    // triangles inside the domain can be recovered using a simple
    // recursive algorithm
    {
      std::list<BDS_Edge*>::iterator ite = m->edges.begin();
      while (ite != m->edges.end()){
        BDS_Edge *e = *ite;
        if(e->g  && e->numfaces() == 2){
          BDS_Point *oface[2];
          e->oppositeof(oface);
          if(oface[0]->iD < 0){
            recur_tag(e->faces(1), &CLASS_F);
            break;
          }
          else if(oface[1]->iD < 0){
            recur_tag(e->faces(0), &CLASS_F);
            break;
          }
        }
        ++ite;
      }
    }
    
    it = emb_edges.begin();
    while(it != emb_edges.end()){
      if(!(*it)->isMeshDegenerated())
        recoverEdge
          (m, *it, recoverMapInv, &edgesToRecover, &edgesNotRecovered, 2);
      ++it;
    }

    // compute characteristic lengths at vertices    
    Msg::Debug("Computing mesh size field at mesh vertices %d", 
               edgesToRecover.size());
    for(int i = 0; i < doc.numPoints; i++){
      BDS_Point *pp = (BDS_Point*)doc.points[i].data;
      std::map<BDS_Point*, MVertex*>::iterator itv = recoverMap.find(pp);
      if(itv != recoverMap.end()){
        MVertex *here = itv->second;
        GEntity *ge = here->onWhat();
        if(ge->dim() == 0){
          pp->lcBGM() = BGM_MeshSize(ge, 0, 0, here->x(), here->y(), here->z());
        }
        else if(ge->dim() == 1){
          double u;
          here->getParameter(0, u);
          pp->lcBGM() = BGM_MeshSize(ge, u, 0, here->x(), here->y(), here->z());
        }
        else
          pp->lcBGM() = MAX_LC;      
        pp->lc() = pp->lcBGM();
      }
    }
  }

  // delete useless stuff
  std::list<BDS_Face*>::iterator itt = m->triangles.begin();
  while (itt != m->triangles.end()){
    BDS_Face *t = *itt;
    if(!t->g) m->del_face(t);
    ++itt;
  }
  m->cleanup();

  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->numfaces() == 0)
        m->del_edge(e);
      else{
        if(!e->g) 
          e->g = &CLASS_F;
        if(!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree) 
          e->p1->g = e->g;
        if(!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree) 
          e->p2->g = e->g;
      }
      ++ite;
    }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  if(debug){
    char name[245];
    sprintf(name, "surface%d-recovered-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-recovered-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  int nb_swap;
  //outputScalarField(m->triangles, "beforeswop.pos",1);
  Msg::Debug("Delaunizing the initial mesh");
  delaunayizeBDS(gf, *m, nb_swap);
  //outputScalarField(m->triangles, "afterswop.pos",0);
  Msg::Debug("Starting to add internal points");

  // start mesh generation
  if(!algoDelaunay2D(gf)){
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, true,
                  &recoverMapInv);
    optimizeMeshBDS(gf, *m, 2);
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, false,
                  &recoverMapInv);
    optimizeMeshBDS(gf, *m, 2);
  }
  computeMeshSizeFieldAccuracy(gf, *m, gf->meshStatistics.efficiency_index,
                               gf->meshStatistics.longest_edge_length,
                               gf->meshStatistics.smallest_edge_length,
                               gf->meshStatistics.nbEdge,
                               gf->meshStatistics.nbGoodLength);
  gf->meshStatistics.status = GFace::DONE;

  // fill the small gmsh structures
  {
    std::set<BDS_Point*,PointLessThan>::iterator itp = m->points.begin();
    while (itp != m->points.end()){
      BDS_Point *p = *itp;
      if(recoverMap.find(p) == recoverMap.end()){
        MVertex *v = new MFaceVertex
          (p->X, p->Y, p->Z, gf, m->scalingU * p->u, m->scalingV * p->v);
        recoverMap[p] = v;
        gf->mesh_vertices.push_back(v);
      }
      ++itp;
    }
  }
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if(!t->deleted){
        BDS_Point *n[4];
        t->getNodes(n);
        MVertex *v1 = recoverMap[n[0]];
        MVertex *v2 = recoverMap[n[1]];
        MVertex *v3 = recoverMap[n[2]];
        if(!n[3]){
          // when a singular point is present, degenerated triangles
          // may be created, for example on a sphere that contains one
          // pole
          if(v1 != v2 && v1 != v3 && v2 != v3)
            gf->triangles.push_back(new MTriangle(v1, v2, v3));
        }
        else{
          MVertex *v4 = recoverMap[n[3]];
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        }
      }
      ++itt;
    }
  }

  // the delaunay algo is based directly on internal gmsh structures
  // BDS mesh is passed in order not to recompute local coordinates of
  // vertices
  if(algoDelaunay2D(gf)){
    if(CTX::instance()->mesh.algo2d == ALGO_2D_FRONTAL)
      bowyerWatsonFrontal(gf);
    else
      bowyerWatson(gf);
    for(int i = 0; i < CTX::instance()->mesh.nbSmoothing; i++) 
      laplaceSmoothing(gf);
  }
  else if(debug){
    char name[256];
    sprintf(name, "real%d.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "param%d.pos", gf->tag());
    outputScalarField(m->triangles, name,1);
  }
  if(CTX::instance()->mesh.remove4triangles)
    removeFourTrianglesNodes(gf,false); 

  // delete the mesh
  delete m;

  if(gf->meshAttributes.recombine && !CTX::instance()->mesh.optimizeLloyd)
    recombineIntoQuads(gf);

  computeElementShapes(gf, gf->meshStatistics.worst_element_shape,
                       gf->meshStatistics.average_element_shape,
                       gf->meshStatistics.best_element_shape,
                       gf->meshStatistics.nbTriangle,
                       gf->meshStatistics.nbGoodQuality);

  return true;
}

// this function buils a list of vertices (BDS) that are consecutive
// in one given edge loop. We take care of periodic surfaces. In the
// case of periodicty, some curves are present 2 times in the wire
// (seams). Those must be meshed separately

static inline double dist2(const SPoint2 &p1, const SPoint2 &p2)
{
  const double dx = p1.x() - p2.x();
  const double dy = p1.y() - p2.y();
  return dx * dx + dy * dy;
}

static void printMesh1d(int iEdge, int seam, std::vector<SPoint2> &m)
{
  printf("Mesh1D for edge %d seam %d\n", iEdge, seam);
  for(unsigned int i = 0; i < m.size(); i++){
    printf("%12.5E %12.5E\n", m[i].x(), m[i].y());
  }
}

static bool buildConsecutiveListOfVertices(GFace *gf, GEdgeLoop &gel,
                                           std::vector<BDS_Point*> &result,
                                           SBoundingBox3d &bbox, BDS_Mesh *m,
                                           std::map<BDS_Point*, MVertex*> &recoverMap,
                                           int &count, int countTot, double tol,
                                           bool seam_the_first = false)
{
  // for each edge, we build a list of points that are the mapping of
  // the edge points on the face for seams, we build the list for
  // every side for closed loops, we build it on both senses

  std::map<GEntity*, std::vector<SPoint2> > meshes;
  std::map<GEntity*, std::vector<SPoint2> > meshes_seam;

  const int MYDEBUG = false;

  std::map<BDS_Point*, MVertex*> recoverMapLocal;

  result.clear();
  count = 0;

  GEdgeLoop::iter it = gel.begin();

  if(MYDEBUG) 
    printf("face %d with %d edges case %d\n", gf->tag(), 
           (int)gf->edges().size(), seam_the_first);

  while (it != gel.end()){
    GEdgeSigned ges = *it ;
    std::vector<SPoint2> mesh1d;
    std::vector<SPoint2> mesh1d_seam;
    
    bool seam = ges.ge->isSeam(gf);
    
    Range<double> range = ges.ge->parBounds(0);
    
    MVertex *here = ges.ge->getBeginVertex()->mesh_vertices[0];
    mesh1d.push_back(ges.ge->reparamOnFace(gf, range.low(), 1));
    if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, range.low(), -1));
    for(unsigned int i = 0; i < ges.ge->mesh_vertices.size(); i++){
      double u;
      here = ges.ge->mesh_vertices[i];
      here->getParameter(0, u);
      mesh1d.push_back(ges.ge->reparamOnFace(gf, u, 1));
      if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, u, -1));
    }
    here = ges.ge->getEndVertex()->mesh_vertices[0];
    mesh1d.push_back(ges.ge->reparamOnFace(gf, range.high(), 1));
    if(seam) mesh1d_seam.push_back(ges.ge->reparamOnFace(gf, range.high(), -1));
    meshes.insert(std::pair<GEntity*,std::vector<SPoint2> >(ges.ge, mesh1d));
    if(seam) meshes_seam.insert(std::pair<GEntity*,std::vector<SPoint2> > 
                                (ges.ge, mesh1d_seam));
    // printMesh1d(ges.ge->tag(), seam, mesh1d);
    // if(seam) printMesh1d (ges.ge->tag(), seam, mesh1d_seam);
    it++;
  }

  std::list<GEdgeSigned> unordered;
  unordered.insert(unordered.begin(), gel.begin(), gel.end());

  GEdgeSigned found(0, 0);
  SPoint2 last_coord(0, 0);
  int counter = 0;

  while (unordered.size()){
    if(MYDEBUG)
      printf("unordered.size() = %d\n", (int)unordered.size());
    std::list<GEdgeSigned>::iterator it = unordered.begin();
    std::vector<SPoint2>  coords;

    while (it != unordered.end()){
      std::vector<SPoint2> mesh1d;
      std::vector<SPoint2> mesh1d_seam;
      std::vector<SPoint2> mesh1d_reversed;
      std::vector<SPoint2> mesh1d_seam_reversed;
      GEdge *ge = (*it).ge;
      bool seam = ge->isSeam(gf);
      mesh1d = meshes[ge];
      if(seam){ mesh1d_seam = meshes_seam[ge]; }
      mesh1d_reversed.insert(mesh1d_reversed.begin(), mesh1d.rbegin(), mesh1d.rend());
      if(seam) mesh1d_seam_reversed.insert(mesh1d_seam_reversed.begin(),
                                           mesh1d_seam.rbegin(),mesh1d_seam.rend());
      if(!counter){
        counter++;
        if(seam && seam_the_first){
          coords = ((*it)._sign == 1) ? mesh1d_seam : mesh1d_seam_reversed;
          found = (*it);
          Msg::Info("This test case would have failed in previous Gmsh versions ;-)");
        }
        else{
          coords = ((*it)._sign == 1) ? mesh1d : mesh1d_reversed;
          found = (*it);
        }
        unordered.erase(it);
        if(MYDEBUG)
          printf("Starting with edge = %d seam %d\n", (*it).ge->tag(), seam);
        break;
      }
      else{
        if(MYDEBUG)
          printf("Followed by edge = %d\n", (*it).ge->tag());
        SPoint2 first_coord = mesh1d[0];
        double d = -1, d_reversed = -1, d_seam = -1, d_seam_reversed = -1;
        d = dist2(last_coord, first_coord);
        if(MYDEBUG)
          printf("%g %g dist = %12.5E\n", first_coord.x(), first_coord.y(), d);
        if(d < tol){
          coords.clear();
          coords = mesh1d;
          found = GEdgeSigned(1,ge);
          unordered.erase(it);
          goto Finalize;
        }
        SPoint2 first_coord_reversed = mesh1d_reversed[0];
        d_reversed = dist2(last_coord, first_coord_reversed);
        if(MYDEBUG)
          printf("%g %g dist_reversed = %12.5E\n", 
                 first_coord_reversed.x(), first_coord_reversed.y(), d_reversed);
        if(d_reversed < tol){
          coords.clear();
          coords = mesh1d_reversed;
          found = (GEdgeSigned(-1,ge));
          unordered.erase(it);
          goto Finalize;
        }
        if(seam){
          SPoint2 first_coord_seam = mesh1d_seam[0];
          SPoint2 first_coord_seam_reversed = mesh1d_seam_reversed[0];
          d_seam = dist2(last_coord,first_coord_seam);
          if(MYDEBUG) printf("dist_seam = %12.5E\n", d_seam);
          if(d_seam < tol){
            coords.clear();
            coords = mesh1d_seam;
            found = (GEdgeSigned(1,ge));
            unordered.erase(it);
            goto Finalize;
          }
          d_seam_reversed = dist2(last_coord, first_coord_seam_reversed);
          if(MYDEBUG) printf("dist_seam_reversed = %12.5E\n", d_seam_reversed);
          if(d_seam_reversed < tol){
            coords.clear();
            coords = mesh1d_seam_reversed;
            found = GEdgeSigned(-1, ge);
            unordered.erase(it);
            break;
            goto Finalize;
          }
        }
      }
      ++it;
    }
  Finalize:
    if(MYDEBUG) printf("Finalize, found %d points\n", (int)coords.size());
    if(coords.size() == 0){
      // It has not worked : either tolerance is wrong or the first seam edge
      // has to be taken with the other parametric coordinates (because it is
      // only present once in the closure of the domain).
      for(std::map<BDS_Point*, MVertex*>::iterator it = recoverMapLocal.begin();
          it != recoverMapLocal.end(); ++it){
        m->del_point(it->first);
      }
      return false;
    }
     
    std::vector<MVertex*> edgeLoop;
    if(found._sign == 1){
      edgeLoop.push_back(found.ge->getBeginVertex()->mesh_vertices[0]);
      for(unsigned int i = 0; i <found.ge->mesh_vertices.size(); i++)
        edgeLoop.push_back(found.ge->mesh_vertices[i]);
    }
    else{
      edgeLoop.push_back(found.ge->getEndVertex()->mesh_vertices[0]);
      for(int i = found.ge->mesh_vertices.size() - 1; i >= 0; i--)
        edgeLoop.push_back(found.ge->mesh_vertices[i]);
    }
     
    if(MYDEBUG)
      printf("edge %d size %d size %d\n",
             found.ge->tag(), (int)edgeLoop.size(), (int)coords.size());
     
    std::vector<BDS_Point*> edgeLoop_BDS;
    for(unsigned int i = 0; i < edgeLoop.size(); i++){
      MVertex *here = edgeLoop[i];
      GEntity *ge = here->onWhat();
      double U, V;
      SPoint2 param = coords[i];
      U = param.x() / m->scalingU ;
      V = param.y() / m->scalingV;
      BDS_Point *pp = m->add_point(count + countTot, U, V, gf);
      if(ge->dim() == 0){
        pp->lcBGM() = BGM_MeshSize(ge, 0, 0, here->x(), here->y(), here->z());
      }
      else if(ge->dim() == 1){
        double u;
        here->getParameter(0, u);
        pp->lcBGM() = BGM_MeshSize(ge, u, 0,here->x(), here->y(), here->z());
      }
      else
        pp->lcBGM() = MAX_LC;
       
      pp->lc() = pp->lcBGM();
      m->add_geom (ge->tag(), ge->dim());
      BDS_GeomEntity *g = m->get_geom(ge->tag(), ge->dim());
      pp->g = g;
      if(MYDEBUG)
        printf("point %3d (%8.5f %8.5f : %8.5f %8.5f) (%2d,%2d)\n",
               count, pp->u, pp->v, param.x(), param.y(), pp->g->classif_tag,
               pp->g->classif_degree);
      bbox += SPoint3(U, V, 0);
      edgeLoop_BDS.push_back(pp);
      recoverMapLocal[pp] = here;
      count++;
    }
    last_coord = coords[coords.size() - 1];
    if(MYDEBUG) printf("last coord %g %g\n", last_coord.x(), last_coord.y());
    result.insert(result.end(), edgeLoop_BDS.begin(), edgeLoop_BDS.end());
  }
  
  // It has worked, so we add all the points to the recover map
  recoverMap.insert(recoverMapLocal.begin(), recoverMapLocal.end());

  return true;
}

static bool meshGeneratorPeriodic(GFace *gf, bool debug = true)
{
  std::map<BDS_Point*, MVertex*> recoverMap;

  Range<double> rangeU = gf->parBounds(0);
  Range<double> rangeV = gf->parBounds(1);

  double du = rangeU.high() - rangeU.low();
  double dv = rangeV.high() - rangeV.low();

  const double LC2D = sqrt(du * du + dv * dv);

  // Buid a BDS_Mesh structure that is convenient for doing the actual
  // meshing procedure
  BDS_Mesh *m = new BDS_Mesh;
  m->scalingU = 1;
  m->scalingV = 1;

  std::vector<std::vector<BDS_Point*> > edgeLoops_BDS;
  SBoundingBox3d bbox;
  int nbPointsTotal = 0;
  {
    for(std::list<GEdgeLoop>::iterator it = gf->edgeLoops.begin(); 
        it != gf->edgeLoops.end(); it++){
      std::vector<BDS_Point* > edgeLoop_BDS;
      int nbPointsLocal;
      const double fact[4] = {1.e-12, 1.e-7, 1.e-5, 1.e-3};
      bool ok = false;
      for(int i = 0; i < 4; i++){
        if(buildConsecutiveListOfVertices(gf, *it, edgeLoop_BDS, bbox, m, 
                                          recoverMap, nbPointsLocal, 
                                          nbPointsTotal, fact[i] * LC2D)){
          ok = true;
          break;
        }
        if(buildConsecutiveListOfVertices(gf, *it, edgeLoop_BDS, bbox, m, 
                                          recoverMap, nbPointsLocal,
                                          nbPointsTotal, fact[i] * LC2D, true)){
          ok = true;
          break;
        }
      }
      if(!ok){
        gf->meshStatistics.status = GFace::FAILED;
        Msg::Error("The 1D Mesh seems not to be forming a closed loop");
        m->scalingU = m->scalingV = 1.0;
        return false;
      }
      nbPointsTotal += nbPointsLocal;
      edgeLoops_BDS.push_back(edgeLoop_BDS);
    }
  }

  // Use a divide & conquer type algorithm to create a triangulation.
  // We add to the triangulation a box with 4 points that encloses the
  // domain.
  {
    DocRecord doc(nbPointsTotal + 4);
    int count = 0;
    for(unsigned int i = 0; i < edgeLoops_BDS.size(); i++){
      std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
      for(unsigned int j = 0; j < edgeLoop_BDS.size(); j++){
        BDS_Point *pp = edgeLoop_BDS[j];
        double XX = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
          (double)RAND_MAX;
        double YY = CTX::instance()->mesh.randFactor * LC2D * (double)rand() / 
          (double)RAND_MAX;
        doc.points[count].where.h = pp->u + XX;
        doc.points[count].where.v = pp->v + YY;
        doc.points[count].adjacent = NULL;
        doc.points[count].data = pp;
        count++;
      }
    }

    // Increase the size of the bounding box, add 4 points that enclose
    // the domain, use negative number to distinguish those fake
    // vertices
    bbox *= 3.5;
    MVertex *bb[4];
    bb[0] = new MVertex(bbox.min().x(), bbox.min().y(), 0, 0, -1);
    bb[1] = new MVertex(bbox.min().x(), bbox.max().y(), 0, 0, -2);
    bb[2] = new MVertex(bbox.max().x(), bbox.min().y(), 0, 0, -3);
    bb[3] = new MVertex(bbox.max().x(), bbox.max().y(), 0, 0, -4);    
    for(int ip = 0; ip < 4; ip++){
      BDS_Point *pp = m->add_point(-ip - 1, bb[ip]->x(), bb[ip]->y(), gf);
      m->add_geom(gf->tag(), 2);
      BDS_GeomEntity *g = m->get_geom(gf->tag(), 2);
      pp->g = g;
      doc.points[nbPointsTotal+ip].where.h = bb[ip]->x();
      doc.points[nbPointsTotal+ip].where.v = bb[ip]->y();
      doc.points[nbPointsTotal+ip].adjacent = 0;
      doc.points[nbPointsTotal+ip].data = pp;
    }
    for(int ip = 0; ip < 4; ip++) delete bb[ip];
    
    // Use "fast" inhouse recursive algo to generate the triangulation
    // At this stage the triangulation is not what we need
    //   -) It does not necessary recover the boundaries
    //   -) It contains triangles outside the domain (the first edge
    //      loop is the outer one)
    Msg::Debug("Meshing of the convex hull (%d points)", nbPointsTotal);
    doc.MakeMeshWithPoints();
    
    for(int i = 0; i < doc.numTriangles; i++){
      BDS_Point *p1 = (BDS_Point*)doc.points[doc.triangles[i].a].data;
      BDS_Point *p2 = (BDS_Point*)doc.points[doc.triangles[i].b].data;
      BDS_Point *p3 = (BDS_Point*)doc.points[doc.triangles[i].c].data;
      m->add_triangle(p1->iD, p2->iD, p3->iD);
    }
  }

  // Recover the boundary edges and compute characteristic lenghts
  // using mesh edge spacing
  BDS_GeomEntity CLASS_F(1, 2);
  BDS_GeomEntity CLASS_E(1, 1);

  if(debug){
    char name[245];
    sprintf(name, "surface%d-initial-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-initial-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  for(unsigned int i = 0; i < edgeLoops_BDS.size(); i++){
    std::vector<BDS_Point*> &edgeLoop_BDS = edgeLoops_BDS[i];
    for(unsigned int j = 0; j < edgeLoop_BDS.size(); j++){
      BDS_Edge * e = m->recover_edge
        (edgeLoop_BDS[j]->iD, edgeLoop_BDS[(j + 1) % edgeLoop_BDS.size()]->iD);
      if(!e){
        Msg::Error("Impossible to recover the edge %d %d", edgeLoop_BDS[j]->iD,
                   edgeLoop_BDS[(j + 1) % edgeLoop_BDS.size()]->iD);
        gf->meshStatistics.status = GFace::FAILED;
        return false;
      }
      else e->g = &CLASS_E;
    }
  }

  // Msg::Info("Boundary Edges recovered for surface %d",gf->tag());
  // Look for an edge that is on the boundary for which one of the two
  // neighbors has a negative number node. The other triangle is
  // inside the domain and, because all edges were recovered,
  // triangles inside the domain can be recovered using a simple
  // recursive algorithm
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->g  && e->numfaces () == 2){
        BDS_Point *oface[2];
        e->oppositeof(oface);
        if(oface[0]->iD < 0){
          recur_tag(e->faces(1), &CLASS_F);
          break;
        }
        else if(oface[1]->iD < 0){
          recur_tag(e->faces(0), &CLASS_F);
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
      if(!t->g){
        m->del_face (t);
      }
      ++itt;
    }
  }
  
  m->cleanup();
  
  {
    std::list<BDS_Edge*>::iterator ite = m->edges.begin();
    while (ite != m->edges.end()){
      BDS_Edge *e = *ite;
      if(e->numfaces() == 0)
        m->del_edge(e);
      else{
        if(!e->g)
          e->g = &CLASS_F;
        if(!e->p1->g || e->p1->g->classif_degree > e->g->classif_degree)
          e->p1->g = e->g;
        if(!e->p2->g || e->p2->g->classif_degree > e->g->classif_degree)
          e->p2->g = e->g;
      }
      ++ite;
    }
  }
  m->cleanup();
  m->del_point(m->find_point(-1));
  m->del_point(m->find_point(-2));
  m->del_point(m->find_point(-3));
  m->del_point(m->find_point(-4));

  if(debug){
    char name[245];
    sprintf(name, "surface%d-recovered-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0);
    sprintf(name, "surface%d-recovered-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }

  // start mesh generation
  if(!algoDelaunay2D(gf)){
    refineMeshBDS(gf, *m, CTX::instance()->mesh.refineSteps, true);
    optimizeMeshBDS(gf, *m, 2);
    refineMeshBDS(gf, *m, -CTX::instance()->mesh.refineSteps, false);
    optimizeMeshBDS(gf, *m, 2, &recoverMap);
    // compute mesh statistics
    computeMeshSizeFieldAccuracy(gf, *m, gf->meshStatistics.efficiency_index,
                                 gf->meshStatistics.longest_edge_length,
                                 gf->meshStatistics.smallest_edge_length,
                                 gf->meshStatistics.nbEdge,
                                 gf->meshStatistics.nbGoodLength);
    gf->meshStatistics.status = GFace::DONE;
  }
  
  // fill the small gmsh structures
  {
    std::set<BDS_Point*, PointLessThan>::iterator itp = m->points.begin();
    while (itp != m->points.end()){
      BDS_Point *p = *itp;
      if(recoverMap.find(p) == recoverMap.end()){
        MVertex *v = new MFaceVertex
          (p->X, p->Y, p->Z, gf, m->scalingU * p->u, m->scalingV * p->v);
        recoverMap[p] = v;
        gf->mesh_vertices.push_back(v);
      }
      ++itp;
    }
  }
  
  {
    std::list<BDS_Face*>::iterator itt = m->triangles.begin();
    while (itt != m->triangles.end()){
      BDS_Face *t = *itt;
      if(!t->deleted){
        BDS_Point *n[4];
        t->getNodes(n);
        MVertex *v1 = recoverMap[n[0]];
        MVertex *v2 = recoverMap[n[1]];
        MVertex *v3 = recoverMap[n[2]];
        if(!n[3]){
          // when a singular point is present, degenerated triangles
          // may be created, for example on a sphere that contains one
          // pole
          if(v1 != v2 && v1 != v3 && v2 != v3)
            gf->triangles.push_back(new MTriangle(v1, v2, v3));
        }
        else{
          MVertex *v4 = recoverMap[n[3]];
          gf->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
        }
      }
      ++itt;
    }
  }
  
  if(debug){
    char name[245];
    sprintf(name, "surface%d-final-real.pos", gf->tag());
    outputScalarField(m->triangles, name, 0, gf);
    sprintf(name, "surface%d-final-param.pos", gf->tag());
    outputScalarField(m->triangles, name, 1);
  }
  
  if(algoDelaunay2D(gf)){
    if(CTX::instance()->mesh.algo2d == ALGO_2D_FRONTAL)
      bowyerWatsonFrontal(gf);
    else
      bowyerWatson(gf);
    for(int i = 0; i < CTX::instance()->mesh.nbSmoothing; i++) 
      laplaceSmoothing(gf);
  }
  
  // delete the mesh  
  delete m;

 if(gf->meshAttributes.recombine && !CTX::instance()->mesh.optimizeLloyd)
    recombineIntoQuads(gf);
 
  computeElementShapes(gf, gf->meshStatistics.worst_element_shape,
                       gf->meshStatistics.average_element_shape,
                       gf->meshStatistics.best_element_shape,
                       gf->meshStatistics.nbTriangle,
                       gf->meshStatistics.nbGoodQuality);
  return true;
}

void deMeshGFace::operator() (GFace *gf)
{
  if(gf->geomType() == GEntity::DiscreteSurface) return;
  gf->deleteMesh();
  gf->meshStatistics.status = GFace::PENDING;
  gf->meshStatistics.nbTriangle = gf->meshStatistics.nbEdge = 0;
}

int debugSurface = -1;

void meshGFace::operator() (GFace *gf)
{
  gf->model()->setCurrentMeshEntity(gf);

  if(debugSurface >= 0 && gf->tag() != debugSurface){
    gf->meshStatistics.status = GFace::DONE;
    return;
  }

  if(gf->geomType() == GEntity::DiscreteSurface) return;
  if(gf->geomType() == GEntity::BoundaryLayerSurface) return;
  if(gf->geomType() == GEntity::ProjectionFace) return;
  if(gf->meshAttributes.Method == MESH_NONE) return;
  if(CTX::instance()->mesh.meshOnlyVisible && !gf->getVisibility()) return;

  // destroy the mesh if it exists
  deMeshGFace dem;
  dem(gf);

  if(MeshTransfiniteSurface(gf)) return;
  if(MeshExtrudedSurface(gf)) return;
  if(gf->meshMaster() != gf->tag()){
    GFace *gff = gf->model()->getFaceByTag(abs(gf->meshMaster()));
    if (gff->meshStatistics.status != GFace::DONE){
      gf->meshStatistics.status = GFace::PENDING;
      return;
    }
    Msg::Info("Meshing face %d (%s) as a copy of %d", gf->tag(), 
              gf->getTypeString().c_str(), gf->meshMaster());
    copyMesh(gff, gf);
    gf->meshStatistics.status = GFace::DONE;
    return;    
  }

  const char *algo = "Unknown";
  if(algoDelaunay2D(gf))
    algo = (CTX::instance()->mesh.algo2d == ALGO_2D_FRONTAL) ? 
      "Frontal" : "Delaunay";
  else if(CTX::instance()->mesh.algo2d == ALGO_2D_MESHADAPT_OLD)
    algo = "MeshAdapt (old)";
  else 
    algo = "MeshAdapt";

  Msg::StatusBar(2, true, "Meshing surface %d (%s, %s)", 
                 gf->tag(), gf->getTypeString().c_str(), algo);

  // compute loops on the fly (indices indicate start and end points
  // of a loop; loops are not yet oriented)
  Msg::Debug("Computing edge loops");

  Msg::Debug("Generating the mesh");
  if(noSeam(gf) || gf->getNativeType() == GEntity::GmshModel || 
     gf->edgeLoops.empty()){
    meshGenerator(gf, 0, repairSelfIntersecting1dMesh,
                  debugSurface >= 0 || debugSurface == -100);
  }
  else {
    if(!meshGeneratorPeriodic
       (gf, debugSurface >= 0 || debugSurface == -100))
      Msg::Error("Impossible to mesh face %d", gf->tag());
  }

  Msg::Debug("Type %d %d triangles generated, %d internal vertices",
             gf->geomType(), gf->triangles.size(), gf->mesh_vertices.size());

  // test : recompute the background mesh using a PDE
  /*
    if (backgroundMesh::current()){
    backgroundMesh::unset();
    }    
    else{
    backgroundMesh::set(gf);
    char name[256];
    sprintf(name,"bgm-%d.pos",gf->tag());
    backgroundMesh::current()->print(name,gf);
    (*this)(gf);
    }
  */
}

bool checkMeshCompound(GFaceCompound *gf, std::list<GEdge*> &edges)
{
  bool isMeshed = false;
#if defined(HAVE_SOLVER)  

  bool correctTopo = gf->checkTopology();
  if (!correctTopo && gf->allowPartition()){
    partitionAndRemesh((GFaceCompound*) gf);
    isMeshed = true;
    return isMeshed;
  }
  
  bool correctParam = gf->parametrize();
  
  if (!correctParam &&  gf->allowPartition()){
   partitionAndRemesh((GFaceCompound*) gf);
   isMeshed = true;
   return isMeshed;
  }
  
  //Replace edges by their compounds
  std::set<GEdge*> mySet;
  std::list<GEdge*>::iterator it = edges.begin();
  while(it != edges.end()){
    if((*it)->getCompound()){
      mySet.insert((*it)->getCompound());
    }
    else{ 
      mySet.insert(*it);
    }
    ++it;
  }
  edges.clear();
  edges.insert(edges.begin(), mySet.begin(), mySet.end());
#endif
  return isMeshed;
}

void partitionAndRemesh(GFaceCompound *gf)
{
#if defined(HAVE_SOLVER) && (defined(HAVE_CHACO) || defined(HAVE_METIS))

  //Partition the mesh and createTopology for new faces
  //-----------------------------------------------------
  
  std::list<GFace*> cFaces = gf->getCompounds();
  std::vector<MElement *> elements;
  for (std::list<GFace*>::iterator it = cFaces.begin(); it != cFaces.end(); it++)
    for(unsigned int j = 0; j < (*it)->getNumMeshElements(); j++)
      elements.push_back((*it)->getMeshElement(j));

  typeOfPartition method;
  if(gf->nbSplit > 0) method = MULTILEVEL;
  else method = LAPLACIAN;
 
  multiscalePartition *msp = new multiscalePartition(elements, abs(gf->nbSplit), method);

  //gf->partitionFaceCM(); 

  int NF = msp->getNumberOfParts();
  int numv = gf->model()->maxVertexNum() + 1;
  int nume = gf->model()->maxEdgeNum() + 1;
  int numf = gf->model()->maxFaceNum() + 1;
  std::vector<discreteFace*> pFaces;
  createPartitionFaces(gf->model(), gf, NF, pFaces); 
  
  gf->model()->createTopologyFromFaces(pFaces);
   
  Msg::Info("Multiscale Partition SUCCESSFULLY PERFORMED : %d parts", NF );
  gf->model()->writeMSH("multiscalePARTS.msh", 2.2, false, true);
 
  //Remesh new faces (Compound Lines and Compound Surfaces)
  //-----------------------------------------------------
  Msg::Info("--- Parametrize Compounds:");
 
  //Parametrize Compound Lines
  int NE = gf->model()->maxEdgeNum() - nume + 1;
  for (int i=0; i < NE; i++){
    std::vector<GEdge*>e_compound;
    GEdge *pe = gf->model()->getEdgeByTag(nume+i);//partition edge
    e_compound.push_back(pe); 
    int num_gec = nume + NE + i ;
    Msg::Info("Parametrize Compound Line (%d) = %d discrete edge", 
              num_gec, pe->tag());
    GEdgeCompound *gec = new GEdgeCompound(gf->model(), num_gec, e_compound);
    gf->model()->add(gec);

    gec->parametrize();
  }

  //Parametrize Compound surfaces
  std::list<GEdge*> b[4];
  std::set<MVertex*> allNod; 
  for (int i=0; i < NF; i++){
    std::list<GFace*> f_compound;
    GFace *pf =  gf->model()->getFaceByTag(numf+i);//partition face 
    int num_gfc = numf + NF + i ;
    f_compound.push_back(pf);     
    Msg::Info("Parametrize Compound Surface (%d) = %d discrete face",
              num_gfc, pf->tag());
    GFaceCompound *gfc = new GFaceCompound(gf->model(), num_gfc, f_compound,
                                           b[0], b[1], b[2], b[3], 0,
                                           gf->getTypeOfMapping());
    gfc->meshAttributes.recombine =  gf->meshAttributes.recombine;
    gf->model()->add(gfc);

    gfc->parametrize();
  }

  Msg::Info("*** Mesh Compounds:");

  for (int i = 0; i < NE; i++){
    GEdge *gec = gf->model()->getEdgeByTag(nume + NE + i);
     meshGEdge mge;
     mge(gec);
  }

  Msg::Info("*** Starting Mesh of surface %d ...", gf->tag());

  //lloydAlgorithm
  for (int i=0; i < NF; i++){
    GFace *gfc =  gf->model()->getFaceByTag(numf + NF + i );
    meshGFace mgf;
    mgf(gfc);
    //gfc->lloyd(20,0);

    for(unsigned int j = 0; j < gfc->triangles.size(); ++j){
      MTriangle *t = gfc->triangles[j];
      std::vector<MVertex *> v(3);
      for(int k = 0; k < 3; k++){
        v[k] = t->getVertex(k); 
        allNod.insert(v[k]);
      }
      gf->triangles.push_back(new MTriangle(v[0], v[1], v[2]));
    }  
 
  }

  //Removing discrete Vertices - Edges - Faces
  int NV = gf->model()->maxVertexNum() - numv + 1;
  for (int i=0; i < NV; i++){
    GVertex *pv = gf->model()->getVertexByTag(numv+i);
    gf->model()->remove(pv);
  }
  for (int i=0; i < NE; i++){
    GEdge *gec = gf->model()->getEdgeByTag(nume+NE+i);
    GEdge *pe = gf->model()->getEdgeByTag(nume+i);
    gf->model()->remove(pe); 
    gf->model()->remove(gec);
  }
  for (int i=0; i < NF; i++){
    GFace *gfc = gf->model()->getFaceByTag(numf+NF+i);
    GFace *pf  = gf->model()->getFaceByTag(numf+i);
    gf->model()->remove(pf); 
    gf->model()->remove(gfc);
  }

  //Put new mesh in a new discreteFace
  //-----------------------------------------------------
  for(std::set<MVertex*>::iterator it = allNod.begin(); it != allNod.end(); ++it){
    gf->mesh_vertices.push_back(*it);
  }

  //Remove mesh_vertices that belong to l_edges
  //-----------------------------------------------------
  std::list<GEdge*> l_edges = gf->edges();
  for( std::list<GEdge*>::iterator it = l_edges.begin(); it != l_edges.end(); it++){
    //printf("boundary edge of face %d =%d size=%d\n", gf->tag(),(*it)->tag(), l_edges.size());
    std::vector<MVertex*> edge_vertices = (*it)->mesh_vertices;
    std::vector<MVertex*>::const_iterator itv = edge_vertices.begin();
    for(; itv != edge_vertices.end(); itv++){
      std::vector<MVertex*>::iterator itve = std::find
        (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), *itv);
      if (itve != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itve);
    }
    MVertex *vB = (*it)->getBeginVertex()->mesh_vertices[0];
    std::vector<MVertex*>::iterator itvB = std::find
      (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vB);
    if (itvB != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvB);
    MVertex *vE = (*it)->getEndVertex()->mesh_vertices[0];
    std::vector<MVertex*>::iterator itvE = std::find
      (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vE);
    if (itvE != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvE);

    //if l_edge is a compond
    if((*it)->getCompound()){
      GEdgeCompound *gec = (*it)->getCompound();
      std::vector<MVertex*> edge_vertices = gec->mesh_vertices;
      std::vector<MVertex*>::const_iterator itv = edge_vertices.begin();
      for(; itv != edge_vertices.end(); itv++){
        std::vector<MVertex*>::iterator itve = std::find
          (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), *itv);
        if (itve != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itve);
      }
      MVertex *vB = (*it)->getBeginVertex()->mesh_vertices[0];
      std::vector<MVertex*>::iterator itvB = std::find
        (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vB);
      if (itvB != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvB);
      MVertex *vE = (*it)->getEndVertex()->mesh_vertices[0];
      std::vector<MVertex*>::iterator itvE = std::find
        (gf->mesh_vertices.begin(), gf->mesh_vertices.end(), vE);
      if (itvE != gf->mesh_vertices.end()) gf->mesh_vertices.erase(itvE);
    }
  }

  Msg::Info("*** Mesh of surface %d done by assembly remeshed faces", gf->tag());
  Msg::Info("-----------------------------------------------------------");
 
  gf->coherenceNormals();
  gf->meshStatistics.status = GFace::DONE; 

  //CreateOutputFile("toto.msh", CTX::instance()->mesh.format);
  //Msg::Exit(1);
#endif
}

template<class T>
static bool shouldRevert(MEdge &reference, std::vector<T*> &elements)
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
  gf->model()->setCurrentMeshEntity(gf);

  if(gf->geomType() == GEntity::ProjectionFace) return;
  if(gf->geomType() == GEntity::CompoundSurface)return;
  // in old versions we did not reorient transfinite surface meshes;
  // we could add the following to provide backward compatibility:
  // if(gf->meshAttributes.Method == MESH_TRANSFINITE) return;

  if(gf->getNativeType() == GEntity::OpenCascadeModel){
    // surface orientions in OCC do not seem to be consistent with the
    // orientation of the bounding edges, so we compare the normals
    // pointwise in an element
    for(unsigned int i = 0; i < gf->getNumMeshElements(); i++){
      MElement *e = gf->getMeshElement(i);
      for(int j = 0; j < e->getNumVertices(); j++){
        MVertex *v = e->getVertex(j);
        SPoint2 param;
        if(reparamMeshVertexOnFace(v, gf, param)){
          SVector3 ne = e->getFace(0).normal();
          SVector3 nf = gf->normal(param); 
          if(dot(ne, nf) < 0){
            Msg::Debug("Reverting orientation of mesh in face %d", gf->tag());
            for(unsigned int k = 0; k < gf->getNumMeshElements(); k++)
              gf->getMeshElement(k)->revert();
          }
          return;
        }
      }
    }
    Msg::Warning("Could not orient mesh in face %d", gf->tag());
  }
  else{
    // orient the mesh to match the orientation of the first edge
    std::list<GEdge*> edges = gf->edges();
    std::list<int> ori = gf->orientations();
    if(edges.empty() || ori.empty()) return;
    GEdge *ge = *edges.begin();
    GVertex *beg = ge->getBeginVertex();
    GVertex *end = ge->getEndVertex();
    if(!beg || beg->mesh_vertices.empty() || !end || end->mesh_vertices.empty())
      return;
    MVertex *v1 = beg->mesh_vertices[0];
    MVertex *v2 = ge->mesh_vertices.empty() ? end->mesh_vertices[0] : 
      ge->mesh_vertices[0];
    int sign = *ori.begin();
    MEdge ref(sign > 0 ? v1 : v2, sign > 0 ? v2 : v1);
    if(shouldRevert(ref, gf->triangles) || shouldRevert(ref, gf->quadrangles)){
      Msg::Debug("Reverting orientation of mesh in face %d", gf->tag());
      for(unsigned int i = 0; i < gf->triangles.size(); i++)
        gf->triangles[i]->revert();
      for(unsigned int i = 0; i < gf->quadrangles.size(); i++)
        gf->quadrangles[i]->revert();
    }
  }
}
