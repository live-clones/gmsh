// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
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
#include "MPoint.h"

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
std::vector<Pair<GVertex*,GVertex*> >* 
GeomMeshMatcher::matchVertices(GModel* m1, GModel *m2, bool& ok)
{
  // Vector that will be returned.
  std::vector<Pair<GVertex*,GVertex*> >* coresp_v = new std::vector<Pair<GVertex*,
                                                               GVertex*> >;

  // Building two vectors with the models' entities.
  std::vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  std::vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  int num_matched_vertices = 0;
  int num_total_vertices = 0;
  int num_mesh_vertices = 0;

  int counter1 = 0;

  std::vector<GVertex*> vertices;
  
  for (std::vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    // If the entity isn't a vertex, don't bother.
    if ((*entity1)->dim() != 0) continue;
    num_total_vertices++;
    GVertex* v1 = (GVertex*) *entity1;

    // FIXME: need a *much* better way to fix the tolerance...
    double tol = 10e-8;
    int counter2 = 0;

    discreteVertex* best_candidate;
    GEntity* best_candidate_ge = 0;
    double best_score = DBL_MAX;

    for (std::vector<GEntity*>::iterator entity2 = m2_entities.begin();
         entity2 != m2_entities.end();
         entity2++)
    {
      if ((*entity2)->dim() != 0) continue;
      num_mesh_vertices++;
      for (unsigned int ed = 0;
           ed < ((discreteVertex*) *entity2)->getNumMeshElements();
           ed++)
      {
        discreteVertex* v2 = (discreteVertex*) *entity2;

        // We match the vertices if their coordinates are the same under the
        // specified tolerance.
                                double score = std::max(fabs(v1->x() - v2->x()),
                             std::max(fabs(v1->y() - v2->y()),
                                  fabs(v1->z() - v2->z())));
        if (score < tol && score < best_score) {
          best_candidate = v2;
          best_candidate_ge = (*entity2);
          best_score = score;
        }
      }
      counter2++;
    }

    if (best_score != DBL_MAX) {
      Msg::Info("Vertices %i (geom) and %i (mesh) match.\n",
                (*entity1)->tag(),
                best_candidate_ge->tag());

      coresp_v->push_back(Pair<GVertex*,GVertex*>((GVertex*) *entity1,
                                                  (GVertex*) best_candidate_ge));
      ((GVertex*) best_candidate_ge)->setTag(((GVertex*) *entity1)->tag());
      //m2->remove((GVertex*) best_candidate_ge);
      //vertices.push_back((GVertex*) best_candidate_ge);
      for (unsigned int v = 0; v < ((GVertex*) best_candidate_ge)->getNumMeshVertices(); v++) {
	((GVertex*) best_candidate_ge)->getMeshVertex(v)->setEntity((GVertex*) *entity1);
      }
      num_matched_vertices++;
    }
    counter1++;
  }

  //for (std::vector<GVertex*>::iterator vert = vertices.begin();
  //vert != vertices.end();
  //vert++)
    //m2->add(*vert); 

  Msg::Info("Vertices matched : %i / %i (%i)\n", num_matched_vertices, num_total_vertices, num_mesh_vertices);
  if(num_matched_vertices != num_total_vertices) ok = false;
  return (coresp_v);
}


std::vector<Pair<GEdge*,GEdge*> >* 
GeomMeshMatcher::matchEdges(GModel* m1, GModel* m2, 
                            std::vector<Pair<GVertex*,GVertex*> >* coresp_v, bool& ok)
{

  int num_matched_edges = 0;
  int num_total_edges = 0;

  // Vector that will be returned.
  std::vector<Pair<GEdge*,GEdge*> >* coresp_e = new std::vector<Pair<GEdge*,GEdge*> >;

  // Building two vectors with the models' entities.
  std::vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  std::vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  for (std::vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    if ((*entity1)->dim() != 1) continue;
    num_total_edges++;

    GVertex* v1 = ((GEdge*)(*entity1))->getBeginVertex();
    GVertex* v2 = ((GEdge*)(*entity1))->getEndVertex();

    std::vector<GEdge*> common_edges;
    std::vector<std::list<GEdge*> > lists;
    lists.push_back((findMatching<GVertex*>(*coresp_v,v1))->edges());
    lists.push_back((findMatching<GVertex*>(*coresp_v,v2))->edges());
    getIntersection<GEdge*>(common_edges, lists);

    GEdge* choice = 0;
    if (common_edges.size() == 0) continue;
    if (common_edges.size() == 1) {
      choice = common_edges[0];
    } else {
      // More than one edge between the two points ? No worries, let
      // us use those bounding boxes !
      // So, first step is to build an array of points taken on the geo entity
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GEdge*)(*entity1))->getOBB();

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
    Msg::Info("Edges %i (geom) and %i (mesh) match.",
              ((GEdge*)*entity1)->tag(),
              choice->tag());
    coresp_e->push_back(Pair<GEdge*,GEdge*>((GEdge*) *entity1 ,
                                             choice));
    choice->setTag(((GEdge*) *entity1)->tag());

    // This reverses the edge if it's not parametrized in the right direction
    if (choice->getBeginVertex() == findMatching<GVertex*>(*coresp_v,v2) &&
        choice->getEndVertex() == findMatching<GVertex*>(*coresp_v,v1)) {
      Msg::Info("Wrong parametrization direction, reversing.");
      choice->reverse();
    }

    for (unsigned int v = 0; v < ((GEdge*) choice)->getNumMeshVertices(); v++) {
      if (((GEdge*) choice)->getMeshVertex(v)->onWhat()->dim() > 0)
	((GEdge*) choice)->getMeshVertex(v)->setEntity((GEdge*) *entity1);
    }
    num_matched_edges++;
  }

  Msg::Info("Edges matched : %i / %i", num_matched_edges, num_total_edges);
  if(num_matched_edges != num_total_edges) ok = false;
  return (coresp_e); 
}

//-----------------------------------------------------------------------------

std::vector<Pair<GFace*,GFace*> >* 
GeomMeshMatcher:: matchFaces(GModel* m1, GModel* m2,  
                             std::vector<Pair<GEdge*,GEdge*> >* coresp_e, bool& ok) 
{
  int num_matched_faces = 0;
  int num_total_faces = 0;

  std::vector<Pair<GFace*,GFace*> >* coresp_f = new std::vector<Pair<GFace*,GFace*> >;

  std::vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  std::vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  for (std::vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    if ((*entity1)->dim() != 2) continue;
    num_total_faces++;

    std::vector<std::list<GFace*> > lists;
    std::list<GEdge*> boundary_edges = ((GEdge*)(*entity1))->edges();
    for (std::list<GEdge*>::iterator boundary_edge = boundary_edges.begin();
         boundary_edge != boundary_edges.end(); boundary_edge++) {
      lists.push_back(findMatching<GEdge*>(*coresp_e,*boundary_edge)->faces());
    }
    std::vector<GFace*> common_faces;
    getIntersection<GFace*>(common_faces, lists);
    GFace* choice = 0;
    if (common_faces.size() == 1) {
      choice = common_faces[0];
    } else if (common_faces.size() > 1) {

      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GFace*)(*entity1))->getOBB();

      //GFace* choice = 0;
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

    coresp_f->push_back(Pair<GFace*,GFace*>((GFace*) *entity1 ,
                                             choice));
    choice->setTag(((GFace*) *entity1)->tag());
    for (unsigned int v = 0; v < ((GFace*) choice)->getNumMeshVertices(); v++) {
      if(((GFace*) choice)->getMeshVertex(v)->onWhat()->dim() > 1)
	((GFace*) choice)->getMeshVertex(v)->setEntity((GFace*) *entity1);
    }

    num_matched_faces++;
  }

  Msg::Info("Faces matched : %i / %i", num_matched_faces, num_total_faces);
  if(num_matched_faces != num_total_faces) ok = false;

  return coresp_f;

}

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

    for (unsigned int v = 0; v < ((GRegion*) choice)->getNumMeshVertices(); v++) {
      if ( ((GRegion*) choice)->getMeshVertex(v)->onWhat()->dim() > 2)
	((GRegion*) choice)->getMeshVertex(v)->setEntity((GRegion*) *entity1);
    }
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
  printf("creating faces\n");
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
}



int GeomMeshMatcher::match(GModel *geom, GModel *mesh)
{
  mesh->createTopologyFromMesh();
  bool ok = true;
  // This will match VERTICES
  std::vector<Pair<GVertex*, GVertex*> > *coresp_v = matchVertices(geom, mesh,ok);
  if (ok) {
    // This will match EDGES
    std::vector<Pair<GEdge*, GEdge*> > *coresp_e = matchEdges(geom, mesh, coresp_v,ok);
    if (ok) {
      // This will match SURFACES
      std::vector<Pair<GFace*, GFace*> > *coresp_f = matchFaces(geom, mesh, coresp_e,ok);
      if (ok) {
        // This will match REGIONS
        //std::vector<Pair<GRegion*, GRegion*> >* coresp_r =
        matchRegions(geom, mesh, coresp_f,ok);
        if (ok) {
          mesh->writeMSH("out.msh",2.0,false,true);
          return 1;
        } else {
          Msg::Error("Could not match every region !");
          return 0;
        }
      } else {
        Msg::Error("Could not match every surface !");
        return 0;
      }
    } else {
      Msg::Error("Could not match every edge !");
      return 0;
    }
  } else {
    Msg::Error("Could not match every vertex !");
    return 0;
  }
  return 0;
}
