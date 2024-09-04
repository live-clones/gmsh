// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Bastien Gorissen, Koen Hillewaert
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
#include "MTrihedron.h"
#include "MPrism.h"
#include "MPoint.h"
#include "MHexahedron.h"
#include "MTetrahedron.h"
#include "OS.h"
#include "Context.h"

#include "closestVertex.h"

GeomMeshMatcher *GeomMeshMatcher::_gmm_instance = nullptr;

template <class T, class container>
void getIntersection(std::vector<T> &res, std::vector<container> &lists)
{
  res.clear();
  if(lists.empty()) return;
  container const &first_list = lists[0];
  bool allsame = true;
  for(auto item = first_list.begin(); item != first_list.end(); item++) {
    bool found = true;

    for(auto list_iter = lists.begin(); list_iter != lists.end(); list_iter++) {
      if(*(list_iter) != first_list) {
        allsame = false;
        if(std::find((*list_iter).begin(), (*list_iter).end(), (*item)) ==
           (*list_iter).end()) {
          found = false;
        }
        else {
          found = true;
          break;
        }
      }
    }
    if(found || allsame) { res.push_back(*item); }
  }
}

template <class T> T findMatching(std::vector<Pair<T, T> > &matching, T &entity)
{
  for(auto pair = matching.begin(); pair != matching.end(); pair++) {
    if((*pair).left() == entity) return ((*pair).right());
  }
  return (0);
}

// Matching vertices

std::vector<Pair<GVertex *, GVertex *> > *
GeomMeshMatcher::matchVertices(GModel *m1, GModel *m2, bool &ok)
{
  // Vector that will be returned.
  std::vector<Pair<GVertex *, GVertex *> > *coresp_v =
    new std::vector<Pair<GVertex *, GVertex *> >;
  int num_matched_vertices = 0;
  int num_total_vertices = m2->getNumVertices();

  std::vector<GVertex *> vertices;

  for(auto vit = m1->firstVertex(); vit != m1->lastVertex(); vit++) {
    GVertex *v1 = (GVertex *)*vit;

    // FIXME: need a *much* better way to fix the tolerance...
    double tol = CTX::instance()->geom.matchMeshTolerance;

    discreteVertex *choice = nullptr;
    double best_score = DBL_MAX;

    for(auto vit2 = m2->firstVertex(); vit2 != m2->lastVertex(); vit2++) {
      discreteVertex *v2 = (discreteVertex *)*vit2;

      // We match the vertices if their coordinates are the same under the
      // specified tolerance.
      double score =
        std::max(fabs(v1->x() - v2->x()),
                 std::max(fabs(v1->y() - v2->y()), fabs(v1->z() - v2->z())));
      if(score < tol && score < best_score) {
        choice = v2;
        best_score = score;
      }
    }

    if(choice && best_score != DBL_MAX) {
      choice->physicals = v1->physicals;
      coresp_v->push_back(Pair<GVertex *, GVertex *>(v1, choice));
      num_matched_vertices++;
    }
  }

  if(num_matched_vertices != num_total_vertices) ok = false;
  Msg::Info("Matched %i nodes out of %i", num_matched_vertices,
            num_total_vertices);
  return (coresp_v);
}

// Matching edges

std::vector<Pair<GEdge *, GEdge *> > *
GeomMeshMatcher::matchEdges(GModel *m1, GModel *m2,
                            std::vector<Pair<GVertex *, GVertex *> > *coresp_v,
                            bool &ok)
{
  int num_matched_edges = 0;
  int num_total_edges = m2->getNumEdges();

  // Vector that will be returned.
  std::vector<Pair<GEdge *, GEdge *> > *coresp_e =
    new std::vector<Pair<GEdge *, GEdge *> >;

  std::vector<GEdge *> closed_curves;

  for(auto eit = m1->firstEdge(); eit != m1->lastEdge(); eit++) {
    GEdge *e1 = (GEdge *)*eit;

    GVertex *v1 = e1->getBeginVertex();
    GVertex *v2 = e1->getEndVertex();

    std::vector<GEdge *> common_edges;
    std::vector<std::vector<GEdge *> > lists;

    if(v1 == v2) {
      Msg::Debug("Found a closed curve");
      closed_curves.push_back(e1);

      for(auto eit2 = m2->firstEdge(); eit2 != m2->lastEdge(); eit2++) {
        GEdge *e2 = (GEdge *)*eit2;
        GVertex *v3 = e2->getBeginVertex();
        GVertex *v4 = e2->getEndVertex();
        if(v3 == v4) {
          Msg::Debug("Found a loop (%i) in the mesh %i %i", e2->tag(),
                     v3->tag(), v3->tag());
          common_edges.push_back(e2);
        }
      }
    }
    else {
      bool ok1 = false;
      bool ok2 = false;
      if(findMatching<GVertex *>(*coresp_v, v1) != 0) {
        ok1 = true;
        lists.push_back((findMatching<GVertex *>(*coresp_v, v1))->edges());
      }
      if(findMatching<GVertex *>(*coresp_v, v2) != 0) {
        ok2 = true;
        lists.push_back((findMatching<GVertex *>(*coresp_v, v2))->edges());
      }
      if(ok1 && ok2) getIntersection<GEdge *>(common_edges, lists);
    }

    GEdge *choice = nullptr;
    if(common_edges.size() == 0) continue;
    if(common_edges.size() == 1) { choice = common_edges[0]; }
    else {
      // More than one edge between the two points ? No worries, let
      // us use those bounding boxes !
      // So, first step is to build an array of points taken on the geo entity
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = e1->getOBB();

      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for(auto candidate = common_edges.begin();
          candidate != common_edges.end(); candidate++) {
        SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();

        double score = SOrientedBoundingBox::compare(geo_obb, mesh_obb);
        if(score < best_score) {
          best_score = score;
          choice = (*candidate);
        }
      }
    }
    coresp_e->push_back(Pair<GEdge *, GEdge *>(e1, choice));

    // copy topological information
    if(choice) {
      // choice->setTag(e1->tag());
      choice->physicals = e1->physicals;
    }

    num_matched_edges++;
  }

  Msg::Info("Matched %i curves out of %i", num_matched_edges, num_total_edges);
  if(num_matched_edges != num_total_edges) ok = false;
  return (coresp_e);
}

// Matching faces

std::vector<Pair<GFace *, GFace *> > *
GeomMeshMatcher::matchFaces(GModel *m1, GModel *m2,
                            std::vector<Pair<GEdge *, GEdge *> > *coresp_e,
                            bool &ok)
{
  int num_matched_faces = 0;
  int num_total_faces = m2->getNumFaces();

  std::vector<Pair<GFace *, GFace *> > *coresp_f =
    new std::vector<Pair<GFace *, GFace *> >;

  for(auto fit = m1->firstFace(); fit != m1->lastFace(); fit++) {
    GFace *f1 = (GFace *)*fit;

    std::vector<std::vector<GFace *> > lists;

    std::vector<GEdge *> boundary_edges = f1->edges();

    for(auto boundary_edge = boundary_edges.begin();
        boundary_edge != boundary_edges.end(); boundary_edge++) {
      //      if (boundary_edge->getBeginVertex() ==
      //      boundary_edge->getEndVertex() &&
      if(!(*boundary_edge)->isSeam(f1)) {
        GEdge *ge = findMatching<GEdge *>(*coresp_e, *boundary_edge);
        if(!ge)
          Msg::Error("Could not find curve %i in surface %i during matching",
                     (*boundary_edge)->tag(), f1->tag());
        else
          lists.push_back(ge->faces());
      }
    }
    std::vector<GFace *> common_faces;
    getIntersection<GFace *>(common_faces, lists);
    GFace *choice = nullptr;

    if(common_faces.size() == 0) {
      Msg::Debug("Could not match surface %i", f1->tag());
      continue;
    }

    if(common_faces.size() == 1) { choice = common_faces[0]; }
    else {
      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = f1->getOBB();

      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for(auto candidate = common_faces.begin();
          candidate != common_faces.end(); candidate++) {
        SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
        Msg::Info("Comparing score : %g",
                  SOrientedBoundingBox::compare(geo_obb, mesh_obb));
        double score = SOrientedBoundingBox::compare(geo_obb, mesh_obb);

        if(score < best_score) {
          best_score = score;
          choice = (*candidate);
        }
      }
    }

    if(choice) {
      Msg::Debug("Surfaces %i and %i match", f1->tag(), choice->tag());
      coresp_f->push_back(Pair<GFace *, GFace *>(f1, choice));
      // copy topological information
      choice->setTag(f1->tag());
      f1->physicals = choice->physicals;
      num_matched_faces++;
    }
  }

  Msg::Info("Matched %i surfaces out of %i", num_matched_faces,
            num_total_faces);

  return coresp_f;
}

// Matching regions

std::vector<Pair<GRegion *, GRegion *> > *
GeomMeshMatcher::matchRegions(GModel *m1, GModel *m2,
                              std::vector<Pair<GFace *, GFace *> > *coresp_f,
                              bool &ok)

{
  int num_matched_regions = 0;
  int num_total_regions = 0;

  std::vector<Pair<GRegion *, GRegion *> > *coresp_r =
    new std::vector<Pair<GRegion *, GRegion *> >;

  std::vector<GEntity *> m1_entities;
  m1->getEntities(m1_entities, 3);
  std::vector<GEntity *> m2_entities;
  m2->getEntities(m2_entities, 3);

  if(m1_entities.empty() || m2_entities.empty()) {
    Msg::Info("No volumes could be matched since one of the models does "
              "not have any");
    return coresp_r;
  }

  for(auto entity1 = m1_entities.begin(); entity1 != m1_entities.end();
      entity1++) {
    // if ((*entity1)->dim() != 3) continue;
    num_total_regions++;

    // std::vector<list<GRegion*> > lists;
    std::vector<GFace *> boundary_faces = ((GFace *)(*entity1))->faces();
    std::vector<GFace *> coresp_bound_faces;
    std::vector<GRegion *> common_regions;

    for(auto boundary_face = boundary_faces.begin();
        boundary_face != boundary_faces.end(); boundary_face++) {
      coresp_bound_faces.push_back(
        findMatching<GFace *>(*coresp_f, *boundary_face));
    }
    for(auto entity2 = m2_entities.begin(); entity2 != m2_entities.end();
        entity2++) {
      if((*entity2)->dim() != 3) continue;
      std::vector<std::vector<GFace *> > lists;
      lists.push_back(coresp_bound_faces);
      lists.push_back(((GRegion *)*entity2)->faces());
      std::vector<GFace *> common_faces;
      getIntersection<GFace *>(common_faces, lists);
      if(common_faces.size() == coresp_bound_faces.size()) {
        common_regions.push_back((GRegion *)*entity2);
      }
    }

    if(common_regions.size() == 1) {
      coresp_r->push_back(
        Pair<GRegion *, GRegion *>((GRegion *)*entity1, common_regions[0]));
      common_regions[0]->setTag(((GRegion *)*entity1)->tag());
      (*entity1)->physicals = common_regions[0]->physicals;
      num_matched_regions++;
    }
    else if(common_regions.size() > 1) {
      // So, first step is to build an array of points taken on the geo entity

      /*
        This is made in a backward fashion compared to the other entities...
      */
      std::vector<GEdge *> boundaries = ((GRegion *)*entity1)->edges();

      // Then, compute the minimal bounding box
      SOrientedBoundingBox geo_obb = ((GRegion *)*entity1)->getOBB();

      GRegion *choice = nullptr;
      double best_score = DBL_MAX;
      // Next, let's iterate over the mesh entities.
      for(auto candidate = common_regions.begin();
          candidate != common_regions.end(); candidate++) {
        // Again, build an array with the vertices.
        SOrientedBoundingBox mesh_obb = (*candidate)->getOBB();
        Msg::Info("Comparing score: %g",
                  SOrientedBoundingBox::compare(geo_obb, mesh_obb));
        double score = SOrientedBoundingBox::compare(geo_obb, mesh_obb);

        if(score < best_score) {
          best_score = score;
          choice = (*candidate);
        }
      }
      coresp_r->push_back(
        Pair<GRegion *, GRegion *>((GRegion *)*entity1, choice));
      if(choice) {
        choice->setTag(((GRegion *)*entity1)->tag());
        (*entity1)->physicals = choice->physicals;
      }
      num_matched_regions++;
    }
  }

  Msg::Info("Volumes matched: %i / %i", num_matched_regions,
            num_total_regions);
  if(num_matched_regions != num_total_regions) ok = false;
  return coresp_r;
}

// Public
GeomMeshMatcher *GeomMeshMatcher::instance()
{
  if(!GeomMeshMatcher::_gmm_instance) {
    GeomMeshMatcher::_gmm_instance = new GeomMeshMatcher();
  }
  return (GeomMeshMatcher::_gmm_instance);
}

void GeomMeshMatcher::destroy()
{
  if(GeomMeshMatcher::_gmm_instance) delete GeomMeshMatcher::_gmm_instance;
}

static GVertex *getGVertex(MVertex *v1, GModel *gm, const double TOL)
{
  GVertex *best = nullptr;
  double bestScore = TOL;
  for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    {
      GVertex *v2 = (*it)->getBeginVertex();
      double score = sqrt((v1->x() - v2->x()) * (v1->x() - v2->x()) +
                          (v1->y() - v2->y()) * (v1->y() - v2->y()) +
                          (v1->z() - v2->z()) * (v1->z() - v2->z()));
      if(score < bestScore) {
        bestScore = score;
        best = v2;
      }
    }
    {
      GVertex *v2 = (*it)->getEndVertex();
      double score = sqrt((v1->x() - v2->x()) * (v1->x() - v2->x()) +
                          (v1->y() - v2->y()) * (v1->y() - v2->y()) +
                          (v1->z() - v2->z()) * (v1->z() - v2->z()));
      if(score < bestScore) {
        bestScore = score;
        best = v2;
      }
    }
  }
  return best;
}

static GPoint getGEdge(MVertex *v1, GModel *gm, const double TOL)
{
  GPoint gpBest;
  double bestScore = TOL;

  for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    GEdge *e = *it;
    double pp;
    GPoint gp = e->closestPoint(SPoint3(v1->x(), v1->y(), v1->z()), pp);
    double score = sqrt((v1->x() - gp.x()) * (v1->x() - gp.x()) +
                        (v1->y() - gp.y()) * (v1->y() - gp.y()) +
                        (v1->z() - gp.z()) * (v1->z() - gp.z()));
    if(score < bestScore) {
      bestScore = score;
      gpBest = gp;
    }
  }

  return gpBest;
}

static GPoint getGFace(MVertex *v1, GModel *gm, const double TOL)
{
  GPoint gpBest;
  double bestScore = TOL;
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    GFace *gf = *it;
    SPoint2 pp;
    double guess[2] = {0, 0};
    GPoint gp = gf->closestPoint(SPoint3(v1->x(), v1->y(), v1->z()), guess);
    double score = sqrt((v1->x() - gp.x()) * (v1->x() - gp.x()) +
                        (v1->y() - gp.y()) * (v1->y() - gp.y()) +
                        (v1->z() - gp.z()) * (v1->z() - gp.z()));
    if(score < bestScore) {
      bestScore = score;
      gpBest = gp;
    }
  }
  return gpBest;
}

int GeomMeshMatcher::forceTomatch(GModel *geom, GModel *mesh, const double TOL)
{
  // assume that the geometry is the right one

  std::vector<GEntity *> entities;
  mesh->getEntities(entities);
  for(std::size_t i = 0; i < entities.size(); i++) {
    for(std::size_t j = 0; j < entities[i]->mesh_vertices.size(); j++) {
      MVertex *v = entities[i]->mesh_vertices[j];
      GVertex *gv = getGVertex(v, geom, TOL);
      bool found = 0;
      if(gv) {
        found = 1;
        MVertex *vvv = new MVertex(v->x(), v->y(), v->z(), gv, v->getNum());
        gv->mesh_vertices.push_back(vvv);
        gv->points.push_back(new MPoint(vvv, v->getNum()));
      }
      else if(v->onWhat()->dim() == 1) {
        GPoint gp = getGEdge(v, geom, 1.e22);
        if(gp.g()) {
          GEntity *gg = (GEntity *)gp.g();
          found = 1;
          gg->mesh_vertices.push_back(
            new MEdgeVertex(gp.x(), gp.y(), gp.z(), gg, gp.u(), v->getNum()));
        }
      }
      if(!found && v->onWhat()->dim() <= 2) {
        GPoint gp = getGFace(v, geom, TOL);
        if(gp.g()) {
          GEntity *gg = (GEntity *)gp.g();
          found = 1;
          gg->mesh_vertices.push_back(new MFaceVertex(
            gp.x(), gp.y(), gp.z(), gg, gp.u(), gp.v(), v->getNum()));
        }
      }
      if(!found)
        Msg::Error("Node %d classified on entity of dimension %d and tag %d "
                   "not matched", v->getNum(), v->onWhat()->dim(),
                   v->onWhat()->tag());
    }
  }
  for(auto it = mesh->firstEdge(); it != mesh->lastEdge(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      MVertex *v1 =
        geom->getMeshVertexByTag((*it)->lines[i]->getVertex(0)->getNum());
      MVertex *v2 =
        geom->getMeshVertexByTag((*it)->lines[i]->getVertex(1)->getNum());
      if(v1 && v2) {
        GEdge *ge = nullptr;
        if(v1->onWhat()->dim() == 1) ge = (GEdge *)v1->onWhat();
        if(v2->onWhat()->dim() == 1) ge = (GEdge *)v2->onWhat();
        if(ge) {
          double u1, u2;
          reparamMeshVertexOnEdge(v1, ge, u1);
          reparamMeshVertexOnEdge(v2, ge, u2);
          if(u1 < u2)
            ge->lines.push_back(new MLine(v1, v2));
          else
            ge->lines.push_back(new MLine(v2, v1));
        }
        else
          Msg::Error("Could not find curve");
      }
      else {
        if(!v1)
          Msg::Error("Could not find node %lu",
                     (*it)->lines[i]->getVertex(0)->getNum());
        if(!v2)
          Msg::Error("Could not find node %lu",
                     (*it)->lines[i]->getVertex(1)->getNum());
      }
    }
  }
  for(auto it = mesh->firstFace(); it != mesh->lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      MVertex *v1 =
        geom->getMeshVertexByTag((*it)->triangles[i]->getVertex(0)->getNum());
      MVertex *v2 =
        geom->getMeshVertexByTag((*it)->triangles[i]->getVertex(1)->getNum());
      MVertex *v3 =
        geom->getMeshVertexByTag((*it)->triangles[i]->getVertex(2)->getNum());
      if(v1->onWhat()->dim() == 2)
        ((GFace *)v1->onWhat())->triangles.push_back(new MTriangle(v1, v2, v3));
      else if(v2->onWhat()->dim() == 2)
        ((GFace *)v2->onWhat())->triangles.push_back(new MTriangle(v1, v2, v3));
      else if(v3->onWhat()->dim() == 2)
        ((GFace *)v3->onWhat())->triangles.push_back(new MTriangle(v1, v2, v3));
    }
    for(std::size_t i = 0; i < (*it)->quadrangles.size(); i++) {
      MVertex *v1 =
        geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(0)->getNum());
      MVertex *v2 =
        geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(1)->getNum());
      MVertex *v3 =
        geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(2)->getNum());
      MVertex *v4 =
        geom->getMeshVertexByTag((*it)->quadrangles[i]->getVertex(3)->getNum());

      if(v1->onWhat()->dim() == 2)
        ((GFace *)v1->onWhat())
          ->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
      else if(v2->onWhat()->dim() == 2)
        ((GFace *)v2->onWhat())
          ->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
      else if(v3->onWhat()->dim() == 2)
        ((GFace *)v3->onWhat())
          ->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
      else if(v4->onWhat()->dim() == 2)
        ((GFace *)v4->onWhat())
          ->quadrangles.push_back(new MQuadrangle(v1, v2, v3, v4));
    }
  }
  geom->writeMSH("hopla.msh", 2.2, false, false, true);
  return 0;
}

template <class GEType>
static void copy_periodicity(std::vector<Pair<GEType *, GEType *> > &eCor,
                             std::map<MVertex *, MVertex *> &mesh_to_geom)
{
  typename std::multimap<GEType *, GEType *> eMap; // (eCor.begin(),eCor.end());
  auto eIter = eCor.begin();
  for(; eIter != eCor.end(); ++eIter) {
    eMap.insert(std::make_pair(eIter->second(), eIter->first()));
  }

  auto srcIter = eMap.begin();

  for(; srcIter != eMap.end(); ++srcIter) {
    GEType *oldTgt = srcIter->first;
    GEType *oldSrc = dynamic_cast<GEType *>(oldTgt->getMeshMaster());

    if(oldSrc != nullptr && oldSrc != oldTgt) {
      GEType *newTgt = srcIter->second;
      auto tgtIter = eMap.find(oldSrc);
      if(tgtIter == eMap.end()) {
        Msg::Error("Could not find matched entity for %d, which has a matched "
                   "periodic counterpart %d", oldSrc->tag(), oldTgt->tag());
        continue;
      }
      GEType *newSrc = tgtIter->second;
      newTgt->setMeshMaster(newSrc, oldTgt->affineTransform);

      std::map<MVertex *, MVertex *> &oldV2v = oldTgt->correspondingVertices;
      std::map<MVertex *, MVertex *> &newV2v = newTgt->correspondingVertices;

      auto vIter = oldV2v.begin();
      for(; vIter != oldV2v.end(); ++vIter) {
        MVertex *oldTgtV = vIter->first;
        MVertex *oldSrcV = vIter->second;

        auto newTvIter = mesh_to_geom.find(oldTgtV);
        auto newSvIter = mesh_to_geom.find(oldSrcV);

        if(newTvIter == mesh_to_geom.end()) {
          Msg::Error("Could not find copy of target node %d in entity %d "
                     "of dim %d", oldTgtV->getIndex(), oldTgt->tag(),
                     oldTgt->dim());
          continue;
        }

        if(newSvIter == mesh_to_geom.end()) {
          Msg::Error("Could not find copy of source node %d in entity %d "
                     "of dim %d", oldSrcV->getIndex(), oldSrc->tag(),
                     oldSrc->dim());
          continue;
        }
        newV2v[newTvIter->second] = newSvIter->second;
      }
    }
  }
}

template <class GEType>
static bool apply_periodicity(std::vector<Pair<GEType *, GEType *> > &eCor)
{
  typename std::multimap<GEType *, GEType *> eMap; // (eCor.begin(),eCor.end());
  auto eIter = eCor.begin();
  for(; eIter != eCor.end(); ++eIter) {
    eMap.insert(std::make_pair(eIter->second(), eIter->first()));
  }

  auto srcIter = eMap.begin();

  int dim = -1;

  for(; srcIter != eMap.end(); ++srcIter) {
    GEType *newTgt = srcIter->second;
    newTgt->updateCorrespondingVertices();
    newTgt->alignElementsWithMaster();
    if(dim == -1) dim = newTgt->dim();
  }

  if(dim < 2) { // required for multiple periodic directions
    for(srcIter = eMap.begin(); srcIter != eMap.end(); ++srcIter) {
      GEType *newTgt = srcIter->second;
      newTgt->copyMasterCoordinates();
      newTgt->alignElementsWithMaster();
    }
  }

  return false;
}

static void copy_vertices(GVertex *to, GVertex *from,
                          std::map<MVertex *, MVertex *> &_mesh_to_geom)
{
  to->deleteMesh();
  if(from) {
    for(std::size_t i = 0; i < 1; i++) {
      MVertex *v_from = from->mesh_vertices[i];
      MVertex *v_to = new MVertex(v_from->x(), v_from->y(), v_from->z(), to);
      to->mesh_vertices.push_back(v_to);
      _mesh_to_geom[v_from] = v_to;
    }
  }
}
static void copy_vertices(GRegion *to, GRegion *from,
                          std::map<MVertex *, MVertex *> &_mesh_to_geom)
{
  to->deleteMesh();
  if(from) {
    for(std::size_t i = 0; i < from->mesh_vertices.size(); i++) {
      MVertex *v_from = from->mesh_vertices[i];
      MVertex *v_to = new MVertex(v_from->x(), v_from->y(), v_from->z(), to);
      to->mesh_vertices.push_back(v_to);
      _mesh_to_geom[v_from] = v_to;
    }
  }
}
static void copy_vertices(GEdge *to, GEdge *from,
                          std::map<MVertex *, MVertex *> &_mesh_to_geom)
{
  to->deleteMesh();
  if(!from) {
    Msg::Warning("Curve %d in the mesh do not match any curve in the model",
                 to->tag());
    return;
  }
  if(!to) {
    Msg::Warning("Curve %d in the geometry do not match any curve in the mesh",
                 from->tag());
    return;
  }

  for(std::size_t i = 0; i < from->mesh_vertices.size(); i++) {
    MVertex *v_from = from->mesh_vertices[i];
    double t;
    GPoint gp =
      to->closestPoint(SPoint3(v_from->x(), v_from->y(), v_from->z()), t);
    MEdgeVertex *v_to = new MEdgeVertex(gp.x(), gp.y(), gp.z(), to, gp.u());
    to->mesh_vertices.push_back(v_to);
    _mesh_to_geom[v_from] = v_to;
  }
}

static void copy_vertices(GFace *to, GFace *from,
                          std::map<MVertex *, MVertex *> &_mesh_to_geom)
{
  for(std::size_t i = 0; i < from->mesh_vertices.size(); i++) {
    MVertex *v_from = from->mesh_vertices[i];
    double uv[2];
    GPoint gp =
      to->closestPoint(SPoint3(v_from->x(), v_from->y(), v_from->z()), uv);
    double DDD = (v_from->x() - gp.x()) * (v_from->x() - gp.x()) +
                 (v_from->y() - gp.y()) * (v_from->y() - gp.y()) +
                 (v_from->z() - gp.z()) * (v_from->z() - gp.z());

    if(sqrt(DDD) > 1.e-1)
      Msg::Error("Impossible to match node: original (%g,%g,%g), new (%g,%g,%g)",
                 v_from->x(), v_from->y(), v_from->z(), gp.x(), gp.y(), gp.z());

    else if(sqrt(DDD) > 1.e-3)
      Msg::Warning("One mesh node (%g,%g,%g) of surface %d is difficult to match: "
                   "closest point (%g,%g,%g)", v_from->x(), v_from->y(), v_from->z(),
                   to->tag(), gp.x(), gp.y(), gp.z());

    MFaceVertex *v_to = new MFaceVertex(v_from->x(), v_from->y(), v_from->z(),
                                        to, gp.u(), gp.v());
    to->mesh_vertices.push_back(v_to);
    _mesh_to_geom[v_from] = v_to;
  }
}

template <class ELEMENT>
static void copy_elements(std::vector<ELEMENT *> &to,
                          std::vector<ELEMENT *> &from,
                          std::map<MVertex *, MVertex *> &_mesh_to_geom)
{
  MElementFactory toto;
  to.clear();
  for(std::size_t i = 0; i < from.size(); i++) {
    ELEMENT *e = from[i];
    std::vector<MVertex *> nodes;
    for(std::size_t j = 0; j < e->getNumVertices(); j++) {
      auto vIter = _mesh_to_geom.find(e->getVertex(j));
      if(vIter == _mesh_to_geom.end()) {
        Msg::Error("Could not find match for node %i during element copy",
                   e->getVertex(j)->getNum());
      }
      else
        nodes.push_back(vIter->second);
    }
    if(nodes.size() == e->getNumVertices())
      to.push_back((ELEMENT *)(toto.create(e->getTypeForMSH(), nodes)));
  }
}

void copy_vertices(GModel *geom, GModel *mesh,
                   std::map<MVertex *, MVertex *> &_mesh_to_geom,
                   std::vector<Pair<GVertex *, GVertex *> > *coresp_v,
                   std::vector<Pair<GEdge *, GEdge *> > *coresp_e,
                   std::vector<Pair<GFace *, GFace *> > *coresp_f,
                   std::vector<Pair<GRegion *, GRegion *> > *coresp_r)
{
  // copy all elements
  for(std::size_t i = 0; i < coresp_v->size(); ++i)
    copy_vertices((*coresp_v)[i].first(), (*coresp_v)[i].second(),
                  _mesh_to_geom);
  for(std::size_t i = 0; i < coresp_e->size(); ++i)
    copy_vertices((*coresp_e)[i].first(), (*coresp_e)[i].second(),
                  _mesh_to_geom);
  for(std::size_t i = 0; i < coresp_f->size(); ++i)
    copy_vertices((*coresp_f)[i].first(), (*coresp_f)[i].second(),
                  _mesh_to_geom);
  for(std::size_t i = 0; i < coresp_r->size(); ++i)
    copy_vertices((*coresp_r)[i].first(), (*coresp_r)[i].second(),
                  _mesh_to_geom);
}
void copy_elements(GModel *geom, GModel *mesh,
                   std::map<MVertex *, MVertex *> &_mesh_to_geom,
                   std::vector<Pair<GVertex *, GVertex *> > *coresp_v,
                   std::vector<Pair<GEdge *, GEdge *> > *coresp_e,
                   std::vector<Pair<GFace *, GFace *> > *coresp_f,
                   std::vector<Pair<GRegion *, GRegion *> > *coresp_r)
{
  // copy all elements

  for(std::size_t i = 0; i < coresp_v->size(); ++i) {
    GVertex *dest = (*coresp_v)[i].first();
    GVertex *orig = (*coresp_v)[i].second();
    copy_elements<MPoint>(dest->points, orig->points, _mesh_to_geom);
  }

  for(std::size_t i = 0; i < coresp_e->size(); ++i) {
    GEdge *dest = (*coresp_e)[i].first();
    GEdge *orig = (*coresp_e)[i].second();
    copy_elements<MLine>(dest->lines, orig->lines, _mesh_to_geom);
  }

  for(std::size_t i = 0; i < coresp_f->size(); ++i) {
    GFace *dest = (*coresp_f)[i].first();
    GFace *orig = (*coresp_f)[i].second();
    copy_elements<MTriangle>(dest->triangles, orig->triangles, _mesh_to_geom);
    copy_elements<MQuadrangle>(dest->quadrangles, orig->quadrangles,
                               _mesh_to_geom);
  }

  for(std::size_t i = 0; i < coresp_r->size(); ++i) {
    GRegion *dest = (*coresp_r)[i].first();
    GRegion *orig = (*coresp_r)[i].second();
    copy_elements<MTetrahedron>(dest->tetrahedra, orig->tetrahedra,
                                _mesh_to_geom);
    copy_elements<MHexahedron>(dest->hexahedra, orig->hexahedra, _mesh_to_geom);
    copy_elements<MPrism>(dest->prisms, orig->prisms, _mesh_to_geom);
    copy_elements<MPyramid>(dest->pyramids, orig->pyramids, _mesh_to_geom);
    copy_elements<MTrihedron>(dest->trihedra, orig->trihedra, _mesh_to_geom);
  }
}

int GeomMeshMatcher::match(GModel *geom, GModel *mesh)
{
  Msg::StatusBar(true, "Matching discrete mesh to CAD model...");
  double t1 = Cpu(), w1 = TimeOfDay();

  GModel::setCurrent(geom);
  geom->setPhysicalNames(mesh->getPhysicalNames());

  bool ok = true;

  std::vector<Pair<GVertex *, GVertex *> > *coresp_v(nullptr);
  std::vector<Pair<GEdge *, GEdge *> > *coresp_e(nullptr);
  std::vector<Pair<GFace *, GFace *> > *coresp_f(nullptr);
  std::vector<Pair<GRegion *, GRegion *> > *coresp_r(nullptr);

  coresp_v = matchVertices(geom, mesh, ok);
  if(ok) {
    coresp_e = matchEdges(geom, mesh, coresp_v, ok);
    if(ok) {
      coresp_f = matchFaces(geom, mesh, coresp_e, ok);
      if(ok) { coresp_r = matchRegions(geom, mesh, coresp_f, ok); }
      else
        Msg::Error("Could only match %i surfaces out of %i: stopping match",
                   coresp_f->size(), mesh->getNumFaces());
    }
    else
      Msg::Error("Could only match %i curves out of %i: stopping match",
                 coresp_e->size(), mesh->getNumEdges());
  }
  else
    Msg::Error("Could only match %i points out of %i: check mesh/CAD or "
               "increase Geom.MatchMeshTolerance (currently %g)",
               coresp_v->size(), mesh->getNumVertices(),
               CTX::instance()->geom.matchMeshTolerance);

  std::map<MVertex *, MVertex *> _mesh_to_geom;

  if(ok) {
    Msg::Info("Copying mesh nodes and elements to CAD model entities...");
    copy_vertices(geom, mesh, _mesh_to_geom, coresp_v, coresp_e, coresp_f,
                  coresp_r);
    copy_elements(geom, mesh, _mesh_to_geom, coresp_v, coresp_e, coresp_f,
                  coresp_r);
    Msg::Info("Applying periodicity to CAD model entities...");
    if(!apply_periodicity(*coresp_v))
      copy_periodicity(*coresp_v, _mesh_to_geom);
    if(!apply_periodicity(*coresp_e))
      copy_periodicity(*coresp_e, _mesh_to_geom);
    if(!apply_periodicity(*coresp_f))
      copy_periodicity(*coresp_f, _mesh_to_geom);
  }

  if(coresp_v) delete coresp_v;
  if(coresp_e) delete coresp_e;
  if(coresp_f) delete coresp_f;
  if(coresp_r) delete coresp_r;

  if(ok)
    Msg::StatusBar(true, "Successfully matched mesh to CAD (Wall %gs, CPU %gs)",
                   TimeOfDay() - w1, Cpu() - t1);
  else
    Msg::Error("Failed to match mesh to CAD");

  return ok ? 1 : 0;
}
