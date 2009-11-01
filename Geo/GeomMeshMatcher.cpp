// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
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
#include "MVertex.h"
#include "MLine.h"

GeomMeshMatcher *GeomMeshMatcher::_gmm_instance = 0;

/*! \brief Takes a list and returns a new list containing the unique elements of
 *         the input list.
 *
 *  \param lst The list from which we want to extract the unique elements.
 *  \param res A list that's cleared and that will, after the execution of the
 *             the method, contain the elements of lst that only appear once in
 *             it. Previous contents of res is lost.
 */

template <class T> void removeDuplicates(std::list<T>& L, std::list<T>& res)
{
  res.clear();
  for (typename std::list<T>::iterator it1 = L.begin(); it1 != L.end(); it1++) {
    bool keep = true;
    for (typename std::list<T>::iterator it2 = L.begin(); it2 != L.end(); it2++) {
      if (*it1 == *it2 && it1 != it2) {
         keep = false;
         break;
      }
    }
    if (keep) res.push_back(*it1);
  }
}

template <class T> void getIntersection(std::vector<T>& res, 
                                        std::vector<std::list<T> >& lists)
{
  res.clear();
  std::list<T> first_list = lists[0];

  for (typename std::list<T>::iterator item = first_list.begin();
       item != first_list.end(); item++) {
    bool found = true;
    for (typename std::vector<std::list<T> >::iterator list_iter = lists.begin();
         list_iter != lists.end(); list_iter++) {
      if (find((*list_iter).begin(), (*list_iter).end(), (*item)) == (*list_iter).end()) {
        found = false;
        break;
      }
    }
    if (found) {
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

  int counter1 = 0;

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

    for (std::vector<GEntity*>::iterator entity2 = m2_entities.begin();
         entity2 != m2_entities.end();
         entity2++)
    {
      if ((*entity2)->dim() != 0) continue;
      for (unsigned int ed = 0;
           ed < ((discreteVertex*) *entity2)->getNumMeshElements();
           ed++)
      {
        discreteVertex* v2 = (discreteVertex*) *entity2;
        // We match the vertices if their coordinates are the same under the
        // specified tolerance.
        if (fabs(v1->x() - v2->x()) < tol &&
            fabs(v1->y() - v2->y()) < tol &&
            fabs(v1->z() - v2->z()) < tol )
        {
          Msg::Info("Vertices %i (in m1) and %i (in m2) match.",
                    (*entity1)->tag(),
                    (*entity2)->tag());

	  // ToDo : Relax this assumption...
          // We assume that two mesh vertices can't match with the same
          // geometrical one.
          coresp_v->push_back(Pair<GVertex*,GVertex*>((GVertex*) *entity1,
                                                      (GVertex*) *entity2));
          ((GVertex*) *entity2)->setTag(((GVertex*) *entity1)->tag()); 
          num_matched_vertices++;
          break;
        }
      }
      counter2++;
    }
    counter1++;
  }
  printf("Vertices matched : %i / %i", num_matched_vertices, num_total_vertices);
  Msg::Info("Vertices matched : %i / %i", num_matched_vertices, num_total_vertices);
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

    if (common_edges.size() == 1) {
      Msg::Info("There's only one edge !");
      choice = common_edges[0];
    } else {
      // More than one edge between the two points ? No worries, let
      // us use those bounding boxes !
      Msg::Info("There are %i edges that could match.",common_edges.size());
      // So, first step is to build an array of points taken on the geo entity
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GEdge*)(*entity1))->getOBB();

      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (std::vector<GEdge*>::iterator candidate = common_edges.begin(); 
           candidate != common_edges.end(); candidate++) {
        SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
        Msg::Info("Comparing score : %f", 
                  SOrientedBoundingBox::compare(geo_obb,mesh_obb));


        double score = SOrientedBoundingBox::compare(geo_obb,mesh_obb);
        if (score < best_score) {
          best_score = score;
          choice = (*candidate);
        }
              //}
      }
    }
      Msg::Info("Edges %i (in m1) and %i (in m2) match.",
                  ((GEdge*)*entity1)->tag(),
                  choice->tag());
      coresp_e->push_back(Pair<GEdge*,GEdge*>((GEdge*) *entity1 ,
                                             choice));
      choice->setTag(((GEdge*) *entity1)->tag());
      num_matched_edges++;


      for (std::vector<MLine*>::iterator mline =  choice->lines.begin(); mline != choice->lines.end(); mline++) {
        if (((GEdge*)*entity1)->parFromPoint(((MLine*) *mline)->getVertex(0)->point()) > ((GEdge*)*entity1)->parFromPoint(  ((MLine*) *mline)->getVertex(1)->point()) )
          ((MLine*) *mline)->revert();
      }


      for (unsigned int i = 0; i < choice->getNumMeshElements(); i++) {
        for (int j = 0; j < choice->getMeshElement(i)->getNumVertices(); j++) {
	  MVertex* v = choice->getMeshElement(i)->getVertex(j);
          double param = ((GEdge*) *entity1)->parFromPoint(v->point());
	  Msg::Info("Param %f",param);
	  Msg::Info("Par bounds %f %f",((GEdge*) *entity1)->parBounds(0).low(),((GEdge*) *entity1)->parBounds(0).high());
          if (v->onWhat()->dim() == 1)
            reparamMeshVertexOnEdge(v,(GEdge*)*entity1,param);
        }
      }
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
    //cout << "We found " << common_faces.size() << " common faces." << endl;
    GFace* choice = 0;
    if (common_faces.size() == 1) {
      // SOrientedBoundingBox mesh_obb = (common_faces[0])->getOBB();
      choice = common_faces[0];
      //coresp_f->push_back( Pair<GFace*,GFace*> ((GFace*) *entity1, common_faces[0]));
      //common_faces[0]->setTag(((GFace*) *entity1)->tag());
      //num_matched_faces++;
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
       //cout << "And the winner is ... " << choice << endl;
    }

    coresp_f->push_back(Pair<GFace*,GFace*>((GFace*) *entity1 ,
                                             choice));
    choice->setTag(((GFace*) *entity1)->tag());
    num_matched_faces++;
    
    for (unsigned int i = 0; i < choice->getNumMeshElements(); i++) {
      MVertex* v1 = choice->getMeshElement(i)->getVertex(0);
      MVertex* v2 = choice->getMeshElement(i)->getVertex(1);
      SPoint2 param1 = ((GFace*) *entity1)->parFromPoint(v1->point());
      SPoint2 param2 = ((GFace*) *entity1)->parFromPoint(v2->point());
      reparamMeshEdgeOnFace(v1,v2,(GFace*) *entity1,param1,param2);
      if (v1->onWhat()->dim() == 2)
	reparamMeshVertexOnFace(v1,(GFace*)*entity1,param1);
      if (v2->onWhat()->dim() == 2)
	reparamMeshVertexOnFace(v2,(GFace*)*entity1,param2);
    }
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

int GeomMeshMatcher:: match(GModel *geom, GModel *mesh)
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
	std::vector<Pair<GRegion*, GRegion*> >* coresp_r = matchRegions(geom, mesh, coresp_f,ok);
	if (ok) {
	  mesh->writeMSH("out.msh",2.0,false,true,true);
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
