// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Bastien Gorissen
//

#include <cstdarg>
#include <algorithm>
#include <list>
#include <vector>
#include "GeomMeshMatcher.h"
#include "Pair.h"
#include "discreteVertex.h"
#include "GmshMessage.h"
#include "SOrientedBoundingBox.h"
#include "MElement.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MVertex.h"
#include "MLine.h"
#include "MPyramid.h"
#include "MPrism.h"
#include "MPoint.h"
#include "MHexahedron.h"
#include "MTetrahedron.h"

GeomMeshMatcher *GeomMeshMatcher::_gmm_instance = 0;

template <class T> void getIntersection(std::vector<T>& res,
                                        std::vector<std::list<T> >& lists)
{
  res.clear();
  std::list<T> first_list = lists[0];
  bool allsame = true;
  for (typename std::list<T>::iterator item = first_list.begin();
       item != first_list.end(); item++) {
    bool found = true;
    for (typename std::vector<std::list<T> >::iterator list_iter = lists.begin();
         list_iter != lists.end(); list_iter++) {
      if (*(list_iter)!=first_list) {
	allsame = false;
	if (find((*list_iter).begin(), (*list_iter).end(), (*item)) == (*list_iter).end()) {
	  found = false;
	} else { found = true; break;}
      }
    }
    if (found || allsame ) {
      res.push_back(*item);
    }
  }
}


template <class T> T findMatching(std::vector<Pair<T,T> >& matching, T& entity)
{
  for (typename std::vector<Pair<T,T> >::iterator pair = matching.begin();
       pair != matching.end(); pair++) {
    if ( (*pair).left() == entity) {
      return((*pair).right());
    }
  }
  return (0);
}


// Private

// ------------------------------------------------------------[ Matching vertices ]

std::vector<Pair<GVertex*,GVertex*> >*
GeomMeshMatcher::matchVertices(GModel* m1, GModel *m2, bool& ok)
{
  // Vector that will be returned.
  std::vector<Pair<GVertex*,GVertex*> >* coresp_v = new std::vector<Pair<GVertex*,
                                                               GVertex*> >;
  int num_matched_vertices = 0;
  int num_total_vertices = m1->getNumVertices();

  std::vector<GVertex*> vertices;

  for(GModel::viter vit = m1->firstVertex(); vit != m1->lastVertex(); vit++)   {

    GVertex* v1 = (GVertex*) *vit;

    // FIXME: need a *much* better way to fix the tolerance...
    double tol = 10e-8;

    discreteVertex* best_candidate;
    GEntity* best_candidate_ge = 0;
    double best_score = DBL_MAX;

    for(GModel::viter vit2 = m2->firstVertex(); vit2 != m2->lastVertex(); vit2++) {

      discreteVertex* v2 = (discreteVertex*) *vit2;

      // We match the vertices if their coordinates are the same under the
      // specified tolerance.
      double score = std::max(fabs(v1->x() - v2->x()),
			      std::max(fabs(v1->y() - v2->y()),
				       fabs(v1->z() - v2->z())));
      if (score < tol && score < best_score) {
	best_candidate = v2;
	best_candidate_ge = (*vit2);
	best_score = score;
      }
    }

    if (best_score != DBL_MAX) {
      Msg::Debug("Model Vertex %i (geom) and %i (mesh) match",
                v1->tag(),
                best_candidate_ge->tag());

      coresp_v->push_back(Pair<GVertex*,GVertex*>(v1, best_candidate));
      num_matched_vertices++;
    }
  }

  Msg::Info("Matched %i vertices out of %i.", num_matched_vertices, num_total_vertices);
  return (coresp_v);
}

// ------------------------------------------------------------[ Matching edges ]

std::vector<Pair<GEdge*,GEdge*> >*
GeomMeshMatcher::matchEdges(GModel* m1, GModel* m2,
                            std::vector<Pair<GVertex*,GVertex*> >* coresp_v, bool& ok)
{

  int num_matched_edges = 0;
  int num_total_edges = 0;

  // Vector that will be returned.
  std::vector<Pair<GEdge*,GEdge*> >* coresp_e = new std::vector<Pair<GEdge*,GEdge*> >;

  std::vector<GEdge*> closed_curves;

  for(GModel::eiter eit = m1->firstEdge(); eit != m1->lastEdge(); eit++)   {

    num_total_edges++;

    GEdge* e1 = (GEdge*) *eit;

    GVertex* v1 = e1->getBeginVertex();
    GVertex* v2 = e1->getEndVertex();

    std::vector<GEdge*> common_edges;
    std::vector<std::list<GEdge*> > lists;
    
    if (v1 == v2) {
      Msg::Debug("Found a closed curve");
      closed_curves.push_back(e1);
      
      for (GModel::eiter eit2 = m2->firstEdge(); eit2 != m2->lastEdge(); eit2++) {
	GEdge* e2 = (GEdge*)*eit2;
	GVertex* v3 = e2->getBeginVertex();
	GVertex* v4 = e2->getEndVertex();	
	if (v3 == v4) {
	  Msg::Debug("Found a loop (%i) in the mesh %i %i", e2->tag(), v3->tag(), v3->tag());
	  common_edges.push_back(e2);
	}
	
      }
    } else {
      //if (coresp_v->count(vfindMatching<GVertex*>(*coresp_v,v1)1) > 0 && coresp_v->count(v2) > 0) {
      bool ok1 = false;
      bool ok2 = false;
      if (findMatching<GVertex*>(*coresp_v,v1) != 0) {
	ok1 = true;
	lists.push_back((findMatching<GVertex*>(*coresp_v,v1))->edges());
      }
      if (findMatching<GVertex*>(*coresp_v,v2) != 0) {
	ok2 = true;
	lists.push_back((findMatching<GVertex*>(*coresp_v,v2))->edges());
      }
      if (ok1 && ok2)
	getIntersection<GEdge*>(common_edges, lists); 
    }

    GEdge* choice = 0;
    if (common_edges.size() == 0) continue;
    if (common_edges.size() == 1) {
      choice = common_edges[0];
    } else {
      // More than one edge between the two points ? No worries, let
      // us use those bounding boxes !
      // So, first step is to build an array of points taken on the geo entity
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = e1->getOBB();

      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (std::vector<GEdge*>::iterator candidate = common_edges.begin();
           candidate != common_edges.end(); candidate++) {
        SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();

        double score = SOrientedBoundingBox::compare(geo_obb,mesh_obb);
        if (score < best_score) {
          best_score = score;
          choice = (*candidate);
        }
      }
    }
    Msg::Debug("Edges %i (geom) and %i (mesh) match.",
              e1->tag(),
              choice->tag());
    coresp_e->push_back(Pair<GEdge*,GEdge*>(e1, choice));
    //choice->setTag(e1->tag());

    num_matched_edges++;
  }

  Msg::Info("Matched %i edges out of %i.", num_matched_edges, num_total_edges);
  if(num_matched_edges != num_total_edges) ok = false;
  return (coresp_e);
}

// ------------------------------------------------------------[ Matching faces ]


std::vector<Pair<GFace*,GFace*> >*
GeomMeshMatcher:: matchFaces(GModel* m1, GModel* m2,
                             std::vector<Pair<GEdge*,GEdge*> >* coresp_e, bool& ok)
{
  int num_matched_faces = 0;
  int num_total_faces = 0;

  std::vector<Pair<GFace*,GFace*> >* coresp_f = new std::vector<Pair<GFace*,GFace*> >;

  for(GModel::fiter fit = m1->firstFace(); fit != m1->lastFace(); fit++)   {

    GFace* f1 = (GFace*) *fit;
    num_total_faces++;
    
    std::vector<std::list<GFace*> > lists;

    std::list<GEdge*> boundary_edges = f1->edges();
    for (std::list<GEdge*>::iterator boundary_edge = boundary_edges.begin();
         boundary_edge != boundary_edges.end(); boundary_edge++) {
      //      if (boundary_edge->getBeginVertex() == boundary_edge->getEndVertex() && 
      if (!(*boundary_edge)->isSeam(f1))
	lists.push_back(findMatching<GEdge*>(*coresp_e,*boundary_edge)->faces());
    }
    std::vector<GFace*> common_faces;
    getIntersection<GFace*>(common_faces, lists);
    GFace* choice = 0;
    if (common_faces.size() == 1) {
      choice = common_faces[0];
    } else if (common_faces.size() > 1) {

      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = f1->getOBB();

      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (std::vector<GFace*>::iterator candidate = common_faces.begin();
           candidate != common_faces.end(); candidate++) {
          SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
          Msg::Info("Comparing score : %f", SOrientedBoundingBox::compare(geo_obb,mesh_obb));
          double score = SOrientedBoundingBox::compare(geo_obb,mesh_obb);

          if (score < best_score) {
            best_score = score;
            choice = (*candidate);
          }
        }
    }

    Msg::Debug("Faces %i (geom) and %i (mesh) match.",
              f1->tag(),
              choice->tag());

    coresp_f->push_back(Pair<GFace*,GFace*>(f1 ,
                                             choice));
    choice->setTag(f1->tag());
    num_matched_faces++;
  }

  Msg::Info("Matched %i faces out of %i.", num_matched_faces, num_total_faces);

  return coresp_f;

}

// ------------------------------------------------------------[ Matching regions ]  

std::vector<Pair<GRegion*,GRegion*> >*
GeomMeshMatcher::matchRegions(GModel* m1, GModel* m2,
                              std::vector<Pair<GFace*,GFace*> >* coresp_f, bool& ok)

{
  int num_matched_regions = 0;
  int num_total_regions = 0;

  std::vector<Pair<GRegion*,GRegion*> >* coresp_r = new std::vector<Pair<GRegion*,GRegion*> >;

  std::vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  std::vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  for (std::vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    if ((*entity1)->dim() != 3) continue;
    num_total_regions++;

    //std::vector<list<GRegion*> > lists;
    std::list<GFace*> boundary_faces = ((GFace*)(*entity1))->faces();
    std::list<GFace*> coresp_bound_faces;
    std::vector<GRegion*> common_regions;

    for (std::list<GFace*>::iterator boundary_face = boundary_faces.begin();
         boundary_face != boundary_faces.end(); boundary_face++) {
      coresp_bound_faces.push_back(findMatching<GFace*>(*coresp_f,*boundary_face));
    }
    for (std::vector<GEntity*>::iterator entity2 = m2_entities.begin();
         entity2 != m2_entities.end();
         entity2++)
    {
      if((*entity2)->dim() != 3) continue;
      std::vector<std::list<GFace*> > lists;
      lists.push_back(coresp_bound_faces);
      lists.push_back(((GRegion*)*entity2)->faces());
      std::vector<GFace*> common_faces;
      getIntersection<GFace*>(common_faces, lists);
      if (common_faces.size() == coresp_bound_faces.size()) {
        common_regions.push_back((GRegion*)*entity2);
      }

    }

    if (common_regions.size() == 1) {
      coresp_r->push_back(Pair<GRegion*,GRegion*> ((GRegion*) *entity1, common_regions[0]));
      common_regions[0]->setTag(((GRegion*) *entity1)->tag());
      num_matched_regions++;
    } else if (common_regions.size() > 1) {

      // So, first step is to build an array of points taken on the geo entity

/*
   This is made in a backward fashion compared to the other entities...
*/
      std::list<GEdge*> boundaries = ((GRegion*) *entity1)->edges();

      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GRegion*) *entity1)->getOBB();

      GRegion* choice = 0;
      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (std::vector<GRegion*>::iterator candidate = common_regions.begin();
           candidate != common_regions.end(); candidate++) {
          // Again, build an array with the vertices.
          SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
          Msg::Info("Comparing score : %f",
                    SOrientedBoundingBox::compare(geo_obb,mesh_obb));
          double score = SOrientedBoundingBox::compare(geo_obb,mesh_obb);


             if (score < best_score) {
              best_score = score;
              choice = (*candidate);
            }
        }
       coresp_r->push_back(Pair<GRegion*,GRegion*>((GRegion*) *entity1 ,
                                             choice));
       choice->setTag(((GRegion*) *entity1)->tag());

    //for (unsigned int v = 0; v < ((GRegion*) choice)->getNumMeshVertices(); v++) {
    //  if ( ((GRegion*) choice)->getMeshVertex(v)->onWhat()->dim() > 2)
    //    ((GRegion*) choice)->getMeshVertex(v)->setEntity((GRegion*) *entity1);
    //}
       num_matched_regions++;
    }
  }

  Msg::Info("Regions matched : %i / %i", num_matched_regions, num_total_regions);
  if(num_matched_regions != num_total_regions) ok = false;
  return coresp_r;

}


// Public
GeomMeshMatcher* GeomMeshMatcher::instance()
{
  if (!GeomMeshMatcher::_gmm_instance) {
    GeomMeshMatcher::_gmm_instance = new GeomMeshMatcher();
  }
  return (GeomMeshMatcher::_gmm_instance);
}

void GeomMeshMatcher::destroy()
{
  if (GeomMeshMatcher::_gmm_instance)
    delete GeomMeshMatcher::_gmm_instance;
}

static GVertex *getGVertex (MVertex *v1, GModel *gm, const double TOL){
  GVertex *best = 0;
  double bestScore = TOL;
  for (GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it){
    {
      GVertex *v2 = (*it)->getBeginVertex();
      double score = sqrt((v1->x() - v2->x())*(v1->x() - v2->x()) +
			  (v1->y() - v2->y())*(v1->y() - v2->y()) +
			  (v1->z() - v2->z())*(v1->z() - v2->z()));
      if (score < bestScore){
	bestScore = score;
	best =  v2;
      }
    }
    {
      GVertex *v2 = (*it)->getEndVertex();
      double score = sqrt((v1->x() - v2->x())*(v1->x() - v2->x()) +
			  (v1->y() - v2->y())*(v1->y() - v2->y()) +
			  (v1->z() - v2->z())*(v1->z() - v2->z()));
      if (score < bestScore){
	bestScore = score;
	best =  v2;
      }
    }
  }
  //  if (best)printf("getting point %g %g on vertices best score is %12.5E\n",v1->x(),v1->y(),bestScore);
  return best;
}

static GPoint getGEdge (MVertex *v1, GModel *gm, const double TOL){
  GPoint gpBest;
  double bestScore = TOL;


  for (GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it){
    GEdge *e = *it;
    double pp;
    GPoint gp = e->closestPoint(SPoint3(v1->x(),v1->y(),v1->z()), pp);
    double score = sqrt((v1->x() - gp.x())*(v1->x() - gp.x()) +
			(v1->y() - gp.y())*(v1->y() - gp.y()) +
			(v1->z() - gp.z())*(v1->z() - gp.z()));
    if (score < bestScore){
      bestScore = score;
      gpBest =  gp;
    }
  }

  //  printf("getting point %g %g (%g %g) on edges best score is %12.5E\n",v1->x(),v1->y(),gpBest.x(),gpBest.y(),bestScore);
  return gpBest;
}

static GPoint getGFace (MVertex *v1, GModel *gm, const double TOL){
  GPoint gpBest;
  double bestScore = TOL;
  for (GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it){
    GFace *gf = *it;
    SPoint2 pp;
    double guess[2] = {0,0};
    GPoint gp = gf->closestPoint(SPoint3(v1->x(),v1->y(),v1->z()), guess);
    double score = sqrt((v1->x() - gp.x())*(v1->x() - gp.x()) +
			(v1->y() - gp.y())*(v1->y() - gp.y()) +
			(v1->z() - gp.z())*(v1->z() - gp.z()));
    if (score < bestScore){
      bestScore = score;
      gpBest =  gp;
    }
  }
  //  printf("getting point %g %g (%g %g) on faces best score is %12.5E\n",v1->x(),v1->y(),gpBest.x(),gpBest.y(),bestScore);
  return gpBest;
}

int GeomMeshMatcher::forceTomatch(GModel *geom, GModel *mesh, const double TOL)
{
  // assume that the geometry is the right one

  std::vector<GEntity*> entities;
  mesh->getEntities(entities);
  for(unsigned int i = 0; i < entities.size(); i++){
    for(unsigned int j = 0; j < entities[i]->mesh_vertices.size(); j++){
      MVertex *v = entities[i]->mesh_vertices[j];
      GVertex *gv = getGVertex (v, geom, TOL);
      bool found = 0;
      if (gv){
	printf("vertex %d matches GVertex %d\n",v->getNum(),gv->tag());
	found=1;
	MVertex *vvv = new MVertex (v->x(),v->y(),v->z(),gv,v->getNum());
	gv->mesh_vertices.push_back(vvv);
	gv->points.push_back(new MPoint(vvv,v->getNum()));

      }
      else if (v->onWhat()->dim() == 1){
	GPoint gp = getGEdge (v, geom, 1.e22);
	if(gp.g()){
	  GEntity *gg = (GEntity*)gp.g();
	  found=1;
	  //	  printf("vertex %d matches GEdge %d on position %g\n",v->getNum(),gg->tag(),gp.u());
	  gg->mesh_vertices.push_back(new MEdgeVertex (gp.x(),gp.y(),gp.z(),
						       gg,gp.u(),-1.,v->getNum()));
	}
      }
      if (!found && v->onWhat()->dim() <= 2){
	GPoint gp = getGFace (v, geom, TOL);
	if(gp.g()){
	  GEntity *gg = (GEntity*)gp.g();
	  found = 1;
	  //	  printf("vertex %d matches GFace %d\n",v->getNum(),gg->tag());
	  gg->mesh_vertices.push_back(new MFaceVertex (gp.x(),gp.y(),gp.z(),
						       gg,gp.u(),gp.v(),v->getNum()));
	}
      }
      if (!found) Msg::Error("vertex %d classified on %d %d not matched",v->getNum(),v->onWhat()->dim(),v->onWhat()->tag());
    }
  }
  //  printf("creating edges\n");
  for (GModel::eiter it = mesh->firstEdge(); it != mesh->lastEdge(); ++it){
    //    printf("edge %d\n",(*it)->tag());
    for (int i=0;i<(*it)->lines.size();i++){
      //      printf("medge %d %d\n",(*it)->lines[i]->getVertex(0)->getNum(),(*it)->lines[i]->getVertex(1)->getNum());
      MVertex *v1 = geom->getMeshVertexByTag((*it)->lines[i]->getVertex(0)->getNum());
      MVertex *v2 = geom->getMeshVertexByTag((*it)->lines[i]->getVertex(1)->getNum());
      if (v1 && v2){
	GEdge *ge= 0;
	if (v1->onWhat()->dim() == 1)ge = (GEdge*)v1->onWhat();
	if (v2->onWhat()->dim() == 1)ge = (GEdge*)v2->onWhat();
	if (ge){
	  double u1,u2;
	  reparamMeshVertexOnEdge(v1, ge, u1);
	  reparamMeshVertexOnEdge(v2, ge, u2);
	  if (u1< u2)ge->lines.push_back(new MLine(v1,v2));
	  else ge->lines.push_back(new MLine(v2,v1));
	}
	else printf("argh !\n");
      }
      else{
	if (!v1)printf("Vertex %d has not been found\n", (*it)->lines[i]->getVertex(0)->getNum());
	if (!v2)printf("Vertex %d has not been found\n", (*it)->lines[i]->getVertex(1)->getNum());
      }
    }
  }
  //  printf("creating faces\n");
  for (GModel::fiter it = mesh->firstFace(); it != mesh->lastFace(); ++it){
    for (int i=0;i<(*it)->triangles.size();i++){
      MVertex *v1 = geom->getMeshVertexByTag((*it)->triangles[i]->getVertex(0)->getNum());
      MVertex *v2 = geom->getMeshVertexByTag((*it)->triangles[i]->getVertex(1)->getNum());
      MVertex *v3 = geom->getMeshVertexByTag((*it)->triangles[i]->getVertex(2)->getNum());
      if (v1->onWhat()->dim() == 2)((GFace*)v1->onWhat())->triangles.push_back(new MTriangle(v1,v2,v3));
      else if (v2->onWhat()->dim() == 2)((GFace*)v2->onWhat())->triangles.push_back(new MTriangle(v1,v2,v3));
      else if (v3->onWhat()->dim() == 2)((GFace*)v3->onWhat())->triangles.push_back(new MTriangle(v1,v2,v3));
    }
    for (int i=0;i<(*it)->quadrangles.size();i++){
      MVertex *v1 = geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(0)->getNum());
      MVertex *v2 = geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(1)->getNum());
      MVertex *v3 = geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(2)->getNum());
      MVertex *v4 = geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(3)->getNum());
      //      printf("quad %p %p %p %p\n",v1,v2,v3,v4);
      if (v1->onWhat()->dim() == 2)((GFace*)v1->onWhat())->quadrangles.push_back(new MQuadrangle(v1,v2,v3,v4));
      else if (v2->onWhat()->dim() == 2)((GFace*)v2->onWhat())->quadrangles.push_back(new MQuadrangle(v1,v2,v3,v4));
      else if (v3->onWhat()->dim() == 2)((GFace*)v3->onWhat())->quadrangles.push_back(new MQuadrangle(v1,v2,v3,v4));
      else if (v4->onWhat()->dim() == 2)((GFace*)v4->onWhat())->quadrangles.push_back(new MQuadrangle(v1,v2,v3,v4));
    }
  }
  geom->writeMSH("hopla.msh",2.2,false,false,true);
  return 0;
}

static void copy_vertices (GVertex *to, GVertex *from, std::map<MVertex*,MVertex*> &_mesh_to_geom){
  if (from) {
    to->deleteMesh();
    for (int i=0;i<from->mesh_vertices.size();i++){
      MVertex *v_from = from->mesh_vertices[i];
      MVertex *v_to = new MVertex (v_from->x(),v_from->y(),v_from->z(), to);
      to->mesh_vertices.push_back(v_to);
      _mesh_to_geom[v_from] = v_to;
    }
  }
}
static void copy_vertices (GRegion *to, GRegion *from, std::map<MVertex*,MVertex*> &_mesh_to_geom){
  to->deleteMesh();
  for (int i=0;i<from->mesh_vertices.size();i++){
    MVertex *v_from = from->mesh_vertices[i];
    MVertex *v_to = new MVertex (v_from->x(),v_from->y(),v_from->z(), to);
    to->mesh_vertices.push_back(v_to);
    _mesh_to_geom[v_from] = v_to;
  }
}
static void copy_vertices (GEdge* to, GEdge* from, std::map<MVertex*,MVertex*> &_mesh_to_geom){
  to->deleteMesh();
  if (!from){
    Msg::Warning("Edge %d in the mesh do not match any edge of the model",to->tag());
    return;
  }
  if (!to){
    Msg::Warning("Edge %d in the geometry do not match any edge of the mesh",from->tag());
    return;
  }

  if (from->getBeginVertex() == from->getEndVertex()) {
    MVertex *v_from = from->getBeginVertex()->mesh_vertices[0];
    double t;
    GPoint gp = to->closestPoint(SPoint3(v_from->x(),v_from->y(),v_from->z()), t );
    MEdgeVertex *v_to = new MEdgeVertex (gp.x(),gp.y(),gp.z(), to, gp.u() );
    to->mesh_vertices.push_back(v_to);
    _mesh_to_geom[v_from] = v_to;    
  }

  for (int i=0;i<from->mesh_vertices.size();i++){
    MVertex *v_from = from->mesh_vertices[i];
    double t;
    GPoint gp = to->closestPoint(SPoint3(v_from->x(),v_from->y(),v_from->z()), t );
    MEdgeVertex *v_to = new MEdgeVertex (gp.x(),gp.y(),gp.z(), to, gp.u() );
    to->mesh_vertices.push_back(v_to);
    _mesh_to_geom[v_from] = v_to;
    if (v_from->getNum() == 3646) {
      printf("FOUND IT!!\n");
    }
  }
  //  printf("Ending Edge %d %d vertices to match\n",from->tag(),from->mesh_vertices.size());
}
static void copy_vertices (GFace *geom, GFace *mesh, std::map<MVertex*,MVertex*> &_mesh_to_geom){
  //  printf("Starting Face %d, with %d vertices\n", geom->tag(),  mesh->mesh_vertices.size());
  for (int i=0;i<mesh->mesh_vertices.size();i++){
    MVertex *v_from = mesh->mesh_vertices[i];
    double uv[2];
    GPoint gp = geom->closestPoint ( SPoint3(v_from->x(),v_from->y(),v_from->z()), uv );
    //    printf("Original point %f %f %f\n", v_from->x(), v_from->y(), v_from->z());
    //    printf("New point %f %f %f\n", gp.x(), gp.y(), gp.z());
    double DDD = ( v_from->x() - gp.x()) * ( v_from->x() - gp.x()) +
      ( v_from->y() - gp.y()) * ( v_from->y() - gp.y()) +
      ( v_from->z() - gp.z()) * ( v_from->z() - gp.z()) ;
    if (sqrt(DDD) > 1.e-1)Msg::Error("Impossible to match one point Original point %f %f %f New point %f %f %f",
				     v_from->x(), v_from->y(), v_from->z(),gp.x(), gp.y(), gp.z());
    else if (sqrt(DDD) > 1.e-3)Msg::Warning("One mesh vertex %f %f %f of GFace %d \n is difficult to match : closest point %f %f %f",
						 v_from->x(), v_from->y(), v_from->z(),geom->tag(),gp.x(), gp.y(), gp.z());
    MFaceVertex *v_to = new MFaceVertex (v_from->x(),v_from->y(),v_from->z(), geom, gp.u(),gp.v() );
    geom->mesh_vertices.push_back(v_to);
    //SPoint2 param;
    //reparamMeshVertexOnFace(v_to, to, param, true);
    //printf("PARAMS : %g %g\n", param.x(), param.y());
    _mesh_to_geom[v_from] = v_to;
  }
  //  printf("Ending Face %d %d vertices to match\n",geom->tag(),geom->mesh_vertices.size());
}

template <class ELEMENT>
static void copy_elements (std::vector<ELEMENT*> &to, 
			   std::vector<ELEMENT*> &from, 
			   std::map<MVertex*,MVertex*> &_mesh_to_geom){
  MElementFactory toto;
  to.clear();
  for (int i=0;i < from.size();i++){
    ELEMENT *e = from[i];
    std::vector<MVertex*> nodes;
    for(int j=0;j<e->getNumVertices();j++) {
      nodes.push_back(_mesh_to_geom[e->getVertex(j)]);
      if (_mesh_to_geom[e->getVertex(j)] == 0) {
	printf("Error vertex %i\n", e->getVertex(j)->getNum());
      }
    }
    to.push_back( (ELEMENT*)(toto.create(e->getTypeForMSH(), nodes) ));
  }
}


void copy_vertices (GModel *geom, GModel *mesh, std::map<MVertex*,MVertex*> &_mesh_to_geom,
		    std::vector<Pair<GVertex*, GVertex*> > *coresp_v,
		    std::vector<Pair<GEdge*, GEdge*> > *coresp_e,
		    std::vector<Pair<GFace*, GFace*> > *coresp_f){
  
  // copy all elements
  for (int i=0;i<coresp_v->size();++i)
    copy_vertices((*coresp_v)[i].first(),(*coresp_v)[i].second(),_mesh_to_geom);
  for (int i=0;i<coresp_e->size();++i)
    copy_vertices((*coresp_e)[i].first(),(*coresp_e)[i].second(),_mesh_to_geom);
  for (int i=0;i<coresp_f->size();++i)
    copy_vertices((*coresp_f)[i].first(),(*coresp_f)[i].second(),_mesh_to_geom);
  for (GModel::riter rit = geom->firstRegion() ; rit != geom->lastRegion(); rit++)
  copy_vertices(*rit,mesh->getRegionByTag((*rit)->tag()),_mesh_to_geom);
}
void copy_elements (GModel *geom, GModel *mesh, std::map<MVertex*,MVertex*> &_mesh_to_geom,
		    std::vector<Pair<GVertex*, GVertex*> > *coresp_v,
		    std::vector<Pair<GEdge*, GEdge*> > *coresp_e,
		    std::vector<Pair<GFace*, GFace*> > *coresp_f){
  // copy all elements

  for (int i=0;i<coresp_v->size();++i)
    copy_elements<MPoint>((*coresp_v)[i].first()->points,(*coresp_v)[i].second()->points,_mesh_to_geom);

  for (int i=0;i<coresp_e->size();++i)
    copy_elements<MLine>((*coresp_e)[i].first()->lines,(*coresp_e)[i].second()->lines,_mesh_to_geom);
   
  for (int i=0;i<coresp_f->size();++i){
    copy_elements<MTriangle>((*coresp_f)[i].first()->triangles,(*coresp_f)[i].second()->triangles,_mesh_to_geom);
    copy_elements<MQuadrangle>((*coresp_f)[i].first()->quadrangles,(*coresp_f)[i].second()->quadrangles,_mesh_to_geom);
  }
  for (GModel::riter rit = geom->firstRegion() ; rit != geom->lastRegion(); ++rit) {
    copy_elements<MTetrahedron>((*rit)->tetrahedra,mesh->getRegionByTag((*rit)->tag())->tetrahedra,_mesh_to_geom);
    copy_elements<MHexahedron>((*rit)->hexahedra,mesh->getRegionByTag((*rit)->tag())->hexahedra,_mesh_to_geom);
    copy_elements<MPrism>((*rit)->prisms,mesh->getRegionByTag((*rit)->tag())->prisms,_mesh_to_geom);
    copy_elements<MPyramid>((*rit)->pyramids,mesh->getRegionByTag((*rit)->tag())->pyramids,_mesh_to_geom);
    }
}

int GeomMeshMatcher::match(GModel *geom, GModel *mesh)
{
  mesh->createTopologyFromMesh();
  GModel::setCurrent(geom);

  bool ok = true;

  // This will match VERTICES
  std::vector<Pair<GVertex*, GVertex*> > *coresp_v = matchVertices(geom, mesh,ok);

  // This will match EDGES
  std::vector<Pair<GEdge*, GEdge*> > *coresp_e = matchEdges(geom, mesh, coresp_v,ok);

  // This will match SURFACES
  std::vector<Pair<GFace*, GFace*> > *coresp_f = matchFaces(geom, mesh, coresp_e,ok);
  matchRegions(geom, mesh, coresp_f,ok);
  
  std::map<MVertex*,MVertex*> _mesh_to_geom;
  copy_vertices(geom, mesh, _mesh_to_geom,coresp_v,coresp_e,coresp_f);
  copy_elements(geom, mesh, _mesh_to_geom,coresp_v,coresp_e,coresp_f);

  geom->writeMSH("testing.msh", 2.2, false, true);

  return 1;

  return 0;
}
