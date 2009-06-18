// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributed by Bastien Gorissen

#include "GeomMeshMatcher.h"
#include "discreteVertex.h"
#include "GmshMessage.h"
#include "SOrientedBoundingBox.h"

#include <cstdarg>
#include <algorithm>
#include <list>
#include <vector>
#include "Pair.h"

using namespace std;

 GeomMeshMatcher* GeomMeshMatcher::_gmm_instance = 0;

/*! \brief Takes a list and returns a new list containing the unique elements of
 *         the input list.
 *
 *  \param lst The list from which we want to extract the unique elements.
 *  \param res A list that's cleared and that will, after the execution of the
 *             the method, contain the elements of lst that only appear once in
 *             it. Previous contents of res is lost.
 */

template <class T> void removeDuplicates(list<T>& L, list<T>& res) {
  res.clear();
  for (typename list<T>::iterator it1 = L.begin(); it1 != L.end(); it1++) {
    bool keep = true;
    for (typename list<T>::iterator it2 = L.begin(); it2 != L.end(); it2++) {
      if (*it1 == *it2 && it1 != it2) {
         keep = false;
         break;
      }
    }
    if (keep) res.push_back(*it1);
  }
}

//-----------------------------------------------------------------------------

template <class T> void getIntersection(vector<T>& res, vector<list<T> >& lists) {
  res.clear();
  list<T> first_list = lists[0];

  for (typename list<T>::iterator item = first_list.begin(); item != first_list.end(); item++) {
    bool found = true;
    for (typename vector<list<T> >::iterator list_iter = lists.begin(); list_iter != lists.end(); list_iter++) {
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

//-----------------------------------------------------------------------------

template <class T> T findMatching(vector<Pair<T,T> >& matching, T& entity) {
  for (typename vector<Pair<T,T> >::iterator pair = matching.begin(); pair != matching.end(); pair++) {
    if ( (*pair).left() == entity) {
      return((*pair).right());
    }
  }
  return (0);
}




// Private
vector<Pair<GVertex*,GVertex*> >* GeomMeshMatcher::matchVertices(GModel* m1, GModel *m2) {

  // Vector that will be returned.
  vector<Pair<GVertex*,GVertex*> >* coresp_v = new vector<Pair<GVertex*,
                                                               GVertex*> >;

  // Building two vectors with the models' entities.
  vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  int num_matched_vertices = 0;
  int num_total_vertices = 0;

  int counter1 = 0;

  for (vector<GEntity*>::iterator entity1 = m1_entities.begin();
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

    for (vector<GEntity*>::iterator entity2 = m2_entities.begin();
         entity2 != m2_entities.end();
         entity2++)
    {
      if ((*entity2)->dim() != 0) continue;
      for (int ed = 0;
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
                    counter1,
                    counter2);

          // We assume that two mesh vertices can't match with the same
          // geometrical one.
          coresp_v->push_back(Pair<GVertex*,GVertex*>((GVertex*) *entity1,
                                                      (GVertex*) *entity2));
          ((GVertex*) *entity2)->setTag(((GVertex*) *entity1)->tag()); // TODO : Double-check this part...
          num_matched_vertices++;
          break;
        }
      }
      counter2++;
    }
    counter1++;
  }
  Msg::Info("Vertices matched : %i / %i", num_matched_vertices, num_total_vertices);
  return (coresp_v);
}

vector<Pair<GEdge*,GEdge*> >*  GeomMeshMatcher::matchEdges(GModel* m1, GModel* m2, vector<Pair<GVertex*,GVertex*> >* coresp_v) {

  int num_matched_edges = 0;
  int num_total_edges = 0;

  // Vector that will be returned.
  vector<Pair<GEdge*,GEdge*> >* coresp_e = new vector<Pair<GEdge*,GEdge*> >;

  // Building two vectors with the models' entities.
  vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  int counter1 = 0;

  for (vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    if ((*entity1)->dim() != 1) continue;
      num_total_edges++;



    GVertex* v1 = ((GEdge*)(*entity1))->getBeginVertex();
    GVertex* v2 = ((GEdge*)(*entity1))->getEndVertex();

    vector<GEdge*> common_edges;
    vector<list<GEdge*> > lists;
    lists.push_back((findMatching<GVertex*>(*coresp_v,v1))->edges());
    lists.push_back((findMatching<GVertex*>(*coresp_v,v2))->edges());
    getIntersection<GEdge*>(common_edges, lists);

    if (common_edges.size() == 1) {
      coresp_e->push_back( Pair<GEdge*,GEdge*> ((GEdge*) *entity1, common_edges[0]));
       Msg::Info("Edges %i (in m1) and %i (in m2) match.",
                   ((GEdge*)*entity1)->tag(),
                    common_edges[0]->tag());
      common_edges[0]->setTag(((GEdge*) *entity1)->tag());
      num_matched_edges++;
    } else {
      // More than one edge between the two points ? No worries, let us use those bounding boxes !
      Msg::Info("There are %i edges that could match.",common_edges.size());
      // So, first step is to build an array of points taken on the geo entity
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GEdge*)(*entity1))->getOBB();

     GEdge* choice = 0;
      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (vector<GEdge*>::iterator candidate = common_edges.begin(); candidate != common_edges.end(); candidate++) {
          SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
            Msg::Info("Comparing score : %f", SOrientedBoundingBox::compare(geo_obb,mesh_obb));

	    //if (geo_obb->intersects(mesh_obb)) {

            //double cen_dist1 = geo_obb->getCenter()[0]-mesh_obb->getCenter()[0];
            //double cen_dist2 = geo_obb->getCenter()[1]-mesh_obb->getCenter()[1];
            //double cen_dist3 = geo_obb->getCenter()[2]-mesh_obb->getCenter()[2];
            //double score1 = sqrt(   cen_dist1*cen_dist1
	    //                       + cen_dist2*cen_dist2
            //                      + cen_dist3*cen_dist3);

	    // double score2 = fabs(geo_obb->getSize()[0]-mesh_obb->getSize()[0]);
            //double score3 = fabs(geo_obb->getSize()[1]-mesh_obb->getSize()[1]);
            //double score4 = fabs(geo_obb->getSize()[2]-mesh_obb->getSize()[2]);
            double score = SOrientedBoundingBox::compare(geo_obb,mesh_obb);
              if (score < best_score) {

                best_score = score;
		choice = (*candidate);
	      }
	      //}
        }
       Msg::Info("Edges %i (in m1) and %i (in m2) match.",
                   ((GEdge*)*entity1)->tag(),
                    choice->tag());
       coresp_e->push_back(Pair<GEdge*,GEdge*>((GEdge*) *entity1 ,
                                             choice));
       choice->setTag(((GEdge*) *entity1)->tag());
       num_matched_edges++;
    }

  }

  Msg::Info("Edges matched : %i / %i", num_matched_edges, num_total_edges);
  return (coresp_e);

}

vector<Pair<GFace*,GFace*> >* GeomMeshMatcher:: matchFaces(GModel* m1, GModel* m2,  vector<Pair<GEdge*,GEdge*> >* coresp_e) {

  int num_matched_faces = 0;
  int num_total_faces = 0;

  vector<Pair<GFace*,GFace*> >* coresp_f = new vector<Pair<GFace*,GFace*> >;

  vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  int counter1 = 0;

  for (vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    if ((*entity1)->dim() != 2) continue;
    num_total_faces++;

   vector<list<GFace*> > lists;
    list<GEdge*> boundary_edges = ((GEdge*)(*entity1))->edges();
    for (list<GEdge*>::iterator boundary_edge = boundary_edges.begin(); boundary_edge != boundary_edges.end(); boundary_edge++) {
      lists.push_back(findMatching<GEdge*>(*coresp_e,*boundary_edge)->faces());
    }
    vector<GFace*> common_faces;
    getIntersection<GFace*>(common_faces, lists);
    //cout << "We found " << common_faces.size() << " common faces." << endl;
    if (common_faces.size() == 1) {
      coresp_f->push_back( Pair<GFace*,GFace*> ((GFace*) *entity1, common_faces[0]));
      common_faces[0]->setTag(((GFace*) *entity1)->tag());
      num_matched_faces++;
    } else if (common_faces.size() > 1) {

      int N;
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GFace*)(*entity1))->getOBB();


      GFace* choice = 0;
      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (vector<GFace*>::iterator candidate = common_faces.begin(); candidate != common_faces.end(); candidate++) {
          SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
          Msg::Info("Comparing score : %f", SOrientedBoundingBox::compare(geo_obb,mesh_obb));

          double cen_dist1 = geo_obb.getCenter()[0]-mesh_obb.getCenter()[0];
          double cen_dist2 = geo_obb.getCenter()[1]-mesh_obb.getCenter()[1];
          double cen_dist3 = geo_obb.getCenter()[2]-mesh_obb.getCenter()[2];
          double score1 = sqrt(   cen_dist1*cen_dist1
                                + cen_dist2*cen_dist2
                                + cen_dist3*cen_dist3);

          double score2 = fabs(geo_obb.getSize()[0]-mesh_obb.getSize()[0]);
          double score3 = fabs(geo_obb.getSize()[1]-mesh_obb.getSize()[1]);
          double score4 = fabs(geo_obb.getSize()[2]-mesh_obb.getSize()[2]);


          if (std::max(std::max(score1,score2),std::max(score3,score4)) < best_score) {
            best_score = std::max(std::max(score1,score2),std::max(score3,score4));
            choice = (*candidate);
          }
        }
       //cout << "And the winner is ... " << choice << endl;
       coresp_f->push_back(Pair<GFace*,GFace*>((GFace*) *entity1 ,
                                             choice));
       choice->setTag(((GFace*) *entity1)->tag());
       num_matched_faces++;
    }
  }

  Msg::Info("Faces matched : %i / %i", num_matched_faces, num_total_faces);
  return coresp_f;

}



vector<Pair<GRegion*,GRegion*> >* GeomMeshMatcher:: matchRegions(GModel* m1, GModel* m2, vector<Pair<GFace*,GFace*> >* coresp_f) {
  int num_matched_regions = 0;
  int num_total_regions = 0;

  vector<Pair<GRegion*,GRegion*> >* coresp_r = new vector<Pair<GRegion*,GRegion*> >;

  vector<GEntity*> m1_entities;
  m1->getEntities(m1_entities);
  vector<GEntity*> m2_entities;
  m2->getEntities(m2_entities);

  int counter1 = 0;

  for (vector<GEntity*>::iterator entity1 = m1_entities.begin();
       entity1 != m1_entities.end();
       entity1++)
  {
    if ((*entity1)->dim() != 3) continue;
    num_total_regions++;


    //vector<list<GRegion*> > lists;
    list<GFace*> boundary_faces = ((GFace*)(*entity1))->faces();
    list<GFace*> coresp_bound_faces;
    vector<GRegion*> common_regions;

    for (list<GFace*>::iterator boundary_face = boundary_faces.begin(); boundary_face != boundary_faces.end(); boundary_face++) {
      coresp_bound_faces.push_back(findMatching<GFace*>(*coresp_f,*boundary_face));
    }
    for (vector<GEntity*>::iterator entity2 = m2_entities.begin();
         entity2 != m2_entities.end();
         entity2++)
    {
      if((*entity2)->dim() != 3) continue;
      vector<list<GFace*> > lists;
      lists.push_back(coresp_bound_faces);
      lists.push_back(((GRegion*)*entity2)->faces());
      vector<GFace*> common_faces;
      getIntersection<GFace*>(common_faces, lists);
      if (common_faces.size() == coresp_bound_faces.size()) {
        common_regions.push_back((GRegion*)*entity2);
      }

    }

    if (common_regions.size() == 1) {
      coresp_r->push_back( Pair<GRegion*,GRegion*> ((GRegion*) *entity1, common_regions[0]));
      common_regions[0]->setTag(((GRegion*) *entity1)->tag());
      num_matched_regions++;
    } else if (common_regions.size() > 1) {

      // So, first step is to build an array of points taken on the geo entity

/*
   This is made in a backward fashion compared to the other entities...
*/
      list<GEdge*> boundaries = ((GRegion*) *entity1)->edges();

      const int N = 10;
      int count = 0;
      const int N_total = N*boundaries.size();
      double** vertices = new double*[N_total];

      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GRegion*) *entity1)->getOBB();


      GRegion* choice = 0;
      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for (vector<GRegion*>::iterator candidate = common_regions.begin(); candidate != common_regions.end(); candidate++) {
          // Again, build an array with the vertices.
          SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
          Msg::Info("Comparing score : %f", SOrientedBoundingBox::compare(geo_obb,mesh_obb));

          if (geo_obb.intersects(mesh_obb)) {
            double cen_dist1 = geo_obb.getCenter()[0]-mesh_obb.getCenter()[0];
            double cen_dist2 = geo_obb.getCenter()[1]-mesh_obb.getCenter()[1];
            double cen_dist3 = geo_obb.getCenter()[2]-mesh_obb.getCenter()[2];
            double score1 = sqrt(   cen_dist1*cen_dist1
                                  + cen_dist2*cen_dist2
                                  + cen_dist3*cen_dist3);

            double score2 = fabs(geo_obb.getSize()[0]-mesh_obb.getSize()[0]);
            double score3 = fabs(geo_obb.getSize()[1]-mesh_obb.getSize()[1]);
            double score4 = fabs(geo_obb.getSize()[2]-mesh_obb.getSize()[2]);


            if (std::max(std::max(score1,score2),std::max(score3,score4)) < best_score) {
              best_score = std::max(std::max(score1,score2),std::max(score3,score4));
              choice = (*candidate);
            }
          }
        }
       coresp_r->push_back(Pair<GRegion*,GRegion*>((GRegion*) *entity1 ,
                                             choice));
       choice->setTag(((GRegion*) *entity1)->tag());
       num_matched_regions++;
    }
  }

  Msg::Info("Regions matched : %i / %i", num_matched_regions, num_total_regions);
  return coresp_r;

}


// Public
GeomMeshMatcher*  GeomMeshMatcher::instance() {
  if (!GeomMeshMatcher::_gmm_instance) {
    GeomMeshMatcher::_gmm_instance = new GeomMeshMatcher();
  }
  return (GeomMeshMatcher::_gmm_instance);
}

 void GeomMeshMatcher::destroy() {
  if (GeomMeshMatcher::_gmm_instance)
    delete GeomMeshMatcher::_gmm_instance;
}

int GeomMeshMatcher:: match(GModel* geom, GModel* mesh) {
  mesh->createTopologyFromMesh();
  // This will match VERTICES
  vector<Pair<GVertex*,GVertex*> >* coresp_v = matchVertices(geom,mesh);

  // This will match EDGES
  vector<Pair<GEdge*,GEdge*> >* coresp_e = matchEdges(geom,mesh,coresp_v);

  // This will match SURFACES
  vector<Pair<GFace*,GFace*> >* coresp_f = matchFaces(geom,mesh,coresp_e);

  // This will match REGIONS
  vector<Pair<GRegion*,GRegion*> >* coresp_r = matchRegions(geom,mesh,coresp_f);

  mesh->writeMSH("out.msh",2.0,false,true);

  return (1);
}
