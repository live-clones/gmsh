// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <vector>
#include <set>
#include <map>
#include <stack>
#include <sstream>
#include <string.h>
#include "GmshConfig.h"
#include "GModel.h"
#include "GFace.h"
#include "discreteFace.h"
#include "discreteEdge.h"
#include "discreteVertex.h"
#include "MTriangle.h"
#include "MEdge.h"
#include "GEdge.h"
#include "MLine.h"
#include "MPoint.h"
#include "Context.h"
#include "OS.h"
#include "GmshMessage.h"
#include "GModelParametrize.h"
#include "Context.h"
#include "curvature.h"

#if defined(HAVE_MESH)
#include "meshPartition.h"
#include "meshGFaceOptimize.h"
#endif

#if defined(HAVE_SOLVER)
#include "linearSystemPETSc.h"
#include "linearSystemCSR.h"
#include "linearSystemFull.h"
#endif

#if defined(HAVE_MESH)

static GEdge *
getModelEdge(GModel *gm, std::vector<GFace *> &gfs,
             std::vector<std::pair<GEdge *, std::vector<GFace *> > > &newEdges,
             size_t &MAX1)
{
  if(gfs.size() == 2 && gfs[0] == gfs[1]) return nullptr;
  for(size_t i = 0; i < newEdges.size(); i++) {
    if(gfs.size() == newEdges[i].second.size()) {
      bool found = true;
      for(size_t j = 0; j < newEdges[i].second.size(); j++)
        if(std::find(gfs.begin(), gfs.end(), newEdges[i].second[j]) ==
           gfs.end()) {
          found = false;
          break;
        }
      if(found) return newEdges[i].first;
    }
  }

  discreteEdge *ge = new discreteEdge(gm, (MAX1++) + 1, nullptr, nullptr);
  newEdges.push_back(std::make_pair(ge, gfs));
  return ge;
}

static void
addTriangle(MTriangle *t,
            std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> &tris)
{
  for(int i = 0; i < 3; i++) {
    MEdge e = t->getEdge(i);
    auto it = tris.find(e);
    if(it == tris.end()) {
      std::vector<MTriangle *> v;
      v.push_back(t);
      tris[e] = v;
    }
    else {
      it->second.push_back(t);
    }
  }
}

static bool breakForLargeAngle(MVertex *vprev, MVertex *vmid, MVertex *vpos,
                               double threshold)
{
  if(threshold >= M_PI - 1e-12) return false;
  if(threshold <= 0) return true;
  SVector3 v1(vprev->point(), vmid->point());
  SVector3 v2(vmid->point(), vpos->point());
  double a = angle(v1, v2);
  if((a > threshold && a < M_PI - threshold) ||
     (a > M_PI + threshold && a < 2 * M_PI - threshold)) {
    Msg::Debug("Breaking curve for angle = %g", a);
    return true;
  }
  return false;
}

#endif

void classifyFaces(GModel *gm, double curveAngleThreshold)
{
#if defined(HAVE_MESH)
  size_t MAX0 = gm->getMaxElementaryNumber(0);
  size_t MAX1 = gm->getMaxElementaryNumber(1);
  size_t MAX2 = gm->getMaxElementaryNumber(2);

  // check if mesh is high-order
  bool ho = false;
  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) {
    GFace *gf = *it;
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      if(gf->triangles[i]->getPolynomialOrder() > 1) {
        ho = true;
        break;
      }
    }
    if(ho) break;
  }
  if(ho) {
    Msg::Warning("Reverting to first order mesh for classification");
    gm->setOrderN(1, 0, 0, 0);
  }

  // create a structure from mesh edges to geometrical curves, and remove curves
  // from the model
  std::set<MLine *, MLinePtrLessThan> lines;
  std::vector<GEdge *> edgesToRemove;
  for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      lines.insert((*it)->lines[i]);
    }
    edgesToRemove.push_back(*it);
  }
  for(std::size_t i = 0; i < edgesToRemove.size(); ++i) {
    gm->remove(edgesToRemove[i]);
  }

  // remove points from model
  std::vector<GVertex *> pointsToRemove;
  for(auto it = gm->firstVertex(); it != gm->lastVertex(); ++it) {
    pointsToRemove.push_back(*it);
  }
  for(std::size_t i = 0; i < pointsToRemove.size(); ++i) {
    gm->remove(pointsToRemove[i]);
  }

  // create triangle-triangle connections
  std::map<MTriangle *, GFace *> reverse_old;
  std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> tris;
  std::set<MTriangle *, MElementPtrLessThan> touched;
  for(auto it = gm->firstFace(); it != gm->lastFace(); it++) {
    GFace *gf = *it;
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      touched.insert(gf->triangles[i]);
      reverse_old[gf->triangles[i]] = gf;
      addTriangle(gf->triangles[i], tris);
    }
    gf->triangles.clear();
    gf->mesh_vertices.clear();
  }

  if(touched.empty()) {
    Msg::Warning("No triangles to reclassify in surface mesh");
    return;
  }

  // reset classification of all mesh nodes
  for(auto it = touched.begin(); it != touched.end(); it++) {
    for(std::size_t j = 0; j < (*it)->getNumVertices(); j++)
      (*it)->getVertex(j)->setEntity(nullptr);
  }

  std::map<MTriangle *, GFace *> reverse;
  std::multimap<GFace *, GFace *> replacedBy;
  std::list<GFace *> newf;

  {
    while(!touched.empty()) {
      std::stack<MTriangle *> st;
      st.push(*(touched.begin()));
      touched.erase(touched.begin());
      discreteFace *gf = new discreteFace(gm, (MAX2++) + 1);
      while(!st.empty()) {
        MTriangle *t = st.top();
        gf->triangles.push_back(t);
        reverse[t] = gf;
        st.pop();
        for(int i = 0; i < 3; i++) {
          MEdge e = t->getEdge(i);
          auto it = tris.find(e);
          if(it == tris.end()) {
            Msg::Error("Could not find triangle linked to edge");
            break;
          }
          MLine ll(e.getVertex(0), e.getVertex(1));
          auto itl = lines.find(&ll);
          if(itl == lines.end()) {
            MTriangle *tt = it->second[0] == t ? it->second[1] : it->second[0];
            auto it2 = touched.find(tt);
            if(it2 != touched.end()) {
              st.push(tt);
              touched.erase(it2);
            }
          }
        }
      }
      gm->add(gf);
      newf.push_back(gf);

      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        replacedBy.insert(std::make_pair(reverse_old[gf->triangles[i]], gf));
      }
    }
  }
  Msg::Info("Found %d model surfaces", newf.size());

  // now we have all faces coloured. If some regions were existing, replace
  // their faces by the new ones
  for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    std::vector<GFace *> _xfaces = (*rit)->faces();
    std::set<GFace *, GEntityPtrLessThan> _newFaces;
    for(auto itf = _xfaces.begin(); itf != _xfaces.end(); ++itf) {
      auto itLow = replacedBy.lower_bound(*itf);
      auto itUp = replacedBy.upper_bound(*itf);

      for(; itLow != itUp; ++itLow) _newFaces.insert(itLow->second);
    }
    (*rit)->set(std::vector<GFace *>(_newFaces.begin(), _newFaces.end()));
  }

  std::vector<std::pair<GEdge *, std::vector<GFace *> > > newEdges;
  {
    auto it = tris.begin();
    for(; it != tris.end(); ++it) {
      MLine ml(it->first.getVertex(0), it->first.getVertex(1));
      auto itl = lines.find(&ml);
      if(itl != lines.end()) {
        std::vector<GFace *> faces;
        for(size_t i = 0; i < it->second.size(); ++i)
          faces.push_back(reverse[it->second[i]]);
        GEdge *ge = getModelEdge(gm, faces, newEdges, MAX1);
        if(ge) ge->lines.push_back(*itl);
      }
    }
  }
  Msg::Info("Found %d model curves", newEdges.size());

  // check if new curves should not be split;

  std::map<discreteFace *, std::vector<int>, GEntityPtrLessThan>
    newFaceTopology;
  std::map<MVertex *, GVertex *> modelVertices;

  for(auto ite = newEdges.begin(); ite != newEdges.end(); ++ite) {
    std::vector<MEdge> allEdges;

    for(std::size_t i = 0; i < ite->first->lines.size(); i++) {
      allEdges.push_back(MEdge(ite->first->lines[i]->getVertex(0),
                               ite->first->lines[i]->getVertex(1)));
      delete ite->first->lines[i];
    }
    ite->first->lines.clear();
    std::vector<std::vector<MVertex *> > vs_;

    SortEdgeConsecutive(allEdges, vs_);

    std::vector<std::vector<MVertex *> > vs;
    for(size_t i = 0; i < vs_.size(); i++) {
      bool periodic = (vs_[i][vs_[i].size() - 1] == vs_[i][0]);
      if(periodic) {
        for(size_t j = 0; j < vs_[i].size() - 1; j++) {
          MVertex *v0 = vs_[i][j == 0 ? (vs_[i].size() - 2) : (j - 1)];
          MVertex *v1 = vs_[i][j];
          MVertex *v2 = vs_[i][j + 1];
          if(breakForLargeAngle(v0, v1, v2, curveAngleThreshold)) {
            std::vector<MVertex *> temp;
            for(size_t k = j; k < vs_[i].size() + j; k++) {
              temp.push_back(vs_[i][k % vs_[i].size()]);
            }
            vs_[i] = temp;
            break;
          }
        }
      }

      std::vector<size_t> cuts_;
      cuts_.push_back(0);
      for(size_t j = 1; j < vs_[i].size() - 1; j++) {
        MVertex *v0 = vs_[i][j - 1];
        MVertex *v1 = vs_[i][j];
        MVertex *v2 = vs_[i][j + 1];
        if(breakForLargeAngle(v0, v1, v2, curveAngleThreshold))
          cuts_.push_back(j);
      }
      cuts_.push_back(vs_[i].size() - 1);

      MVertex *first = vs_[i][cuts_[0]];
      for(size_t k = 1; k < cuts_.size(); k++) {
        std::vector<MVertex *> vv_;
        for(size_t j = cuts_[k - 1]; j <= cuts_[k]; j++) {
          if(j == cuts_[k - 1] || vs_[i][j] != vs_[i][j - 1]) {
            vv_.push_back(vs_[i][j]);
          }
        }
        if(periodic && k == cuts_.size() - 1 && cuts_.size() > 2) {
          vv_.push_back(first);
        }
        vs.push_back(vv_);
      }
    }

    for(size_t i = 0; i < vs.size(); i++) {
      MVertex *vB = vs[i][0];
      MVertex *vE = vs[i][vs[i].size() - 1];

      auto itMV = modelVertices.find(vB);
      if(itMV == modelVertices.end()) {
        GVertex *newGv =
          new discreteVertex(gm, (MAX0++) + 1, vB->x(), vB->y(), vB->z());
        newGv->mesh_vertices.push_back(vB);
        vB->setEntity(newGv);
        newGv->points.push_back(new MPoint(vB));
        gm->add(newGv);
        modelVertices[vB] = newGv;
      }
      itMV = modelVertices.find(vE);
      if(itMV == modelVertices.end()) {
        GVertex *newGv =
          new discreteVertex(gm, (MAX0++) + 1, vE->x(), vE->y(), vE->z());
        newGv->mesh_vertices.push_back(vE);
        newGv->points.push_back(new MPoint(vE));
        vE->setEntity(newGv);
        gm->add(newGv);
        modelVertices[vE] = newGv;
      }

      GEdge *newGe = new discreteEdge(gm, (MAX1++) + 1, modelVertices[vB],
                                      modelVertices[vE]);

      for(size_t j = 1; j < vs[i].size(); j++) {
        MVertex *v1 = vs[i][j - 1];
        MVertex *v2 = vs[i][j];
        newGe->lines.push_back(new MLine(v1, v2));
      }

      for(size_t j = 0; j < newGe->lines.size(); j++) {
        MLine *l = newGe->lines[j];
        if(l->getVertex(0)->onWhat()) {
          newGe->mesh_vertices.push_back(l->getVertex(0));
          l->getVertex(0)->setEntity(newGe);
        }
      }

      gm->add(newGe);
      for(size_t K = 0; K < ite->second.size(); K++) {
        discreteFace *gf1 = dynamic_cast<discreteFace *>(ite->second[K]);
        if(gf1) newFaceTopology[gf1].push_back(newGe->tag());
      }
    }
  }

  for(auto itFT = newFaceTopology.begin(); itFT != newFaceTopology.end();
      ++itFT) {
    itFT->first->setBoundEdges(itFT->second);
  }

  for(auto ite = newEdges.begin(); ite != newEdges.end(); ++ite) {
    GEdge *ge = ite->first;
    gm->remove(ge);
    // delete ge;
  }

  // delete empty mesh faces and reclasssify
  std::set<GFace *, GEntityPtrLessThan> fac = gm->getFaces();
  for(auto fit = fac.begin(); fit != fac.end(); ++fit) {
    std::set<MVertex *, MVertexPtrLessThan> verts;
    (*fit)->mesh_vertices.clear();
    for(std::size_t i = 0; i < (*fit)->triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        if(!(*fit)->triangles[i]->getVertex(j)->onWhat()) {
          (*fit)->triangles[i]->getVertex(j)->setEntity(*fit);
          verts.insert((*fit)->triangles[i]->getVertex(j));
        }
      }
    }
    if((*fit)->triangles.size())
      (*fit)->mesh_vertices.insert((*fit)->mesh_vertices.begin(), verts.begin(),
                                   verts.end());
    else
      gm->remove(*fit);
  }
#endif
}

void classifyFaces(GModel *gm, double angleThreshold, bool includeBoundary,
                   bool forParametrization, double curveAngleThreshold)
{
#if defined(HAVE_MESH)
  size_t MAX1 = gm->getMaxElementaryNumber(1);

  Msg::StatusBar(true, "Classifying surfaces (angle: %g)...",
                 angleThreshold * 180. / M_PI);
  double t1 = Cpu(), w1 = TimeOfDay();

  std::vector<MElement *> elements;
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    elements.insert(elements.end(), (*it)->triangles.begin(),
                    (*it)->triangles.end());
    elements.insert(elements.end(), (*it)->quadrangles.begin(),
                    (*it)->quadrangles.end());
  }

  discreteEdge *edge = new discreteEdge(gm, (MAX1++) + 1, nullptr, nullptr);
  gm->add(edge);

  e2t_cont adj;
  buildEdgeToElements(elements, adj);
  std::vector<edge_angle> edges_detected, edges_lonely;
  buildListOfEdgeAngle(adj, edges_detected, edges_lonely);
  for(std::size_t i = 0; i < edges_detected.size(); i++) {
    edge_angle ea = edges_detected[i];
    if(ea.angle <= angleThreshold) break;
    edge->lines.push_back(new MLine(ea.v1, ea.v2));
  }
  if(includeBoundary) {
    for(std::size_t i = 0; i < edges_lonely.size(); i++) {
      edge_angle ea = edges_lonely[i];
      edge->lines.push_back(new MLine(ea.v1, ea.v2));
    }
  }

  computeDiscreteCurvatures(gm);
  if(forParametrization)
    computeEdgeCut(gm, edge->lines, CTX::instance()->mesh.reparamMaxTriangles);
  computeNonManifoldEdges(gm, edge->lines, true);
  classifyFaces(gm, curveAngleThreshold);

  gm->remove(edge);
  edge->lines.clear();
  delete edge;

  gm->pruneMeshVertexAssociations();
  gm->destroyMeshCaches();
  gm->deleteVertexArrays();

  // we have created and deleted discrete entities; call this to reset the
  // handles in the old GEO database (without this, empty discrete entities will
  // show up at the next sync between the GEO database and the GModel).
  gm->exportDiscreteGEOInternals();

  double t2 = Cpu(), w2 = TimeOfDay();
  Msg::StatusBar(true, "Done classifying surfaces (Wall %gs, CPU %gs)", w2 - w1,
                 t2 - t1);
#else
  Msg::Error("Surface classification requires the mesh module");
#endif
}

int computeDiscreteCurvatures(GModel *gm)
{
  std::map<MVertex *, std::pair<SVector3, SVector3> > &C = gm->getCurvatures();
  C.clear();
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    GFace *gf = *it;
    std::map<MVertex *, int> nodeIndex;
    std::vector<SPoint3> nodes;
    std::vector<int> tris;
    std::vector<std::pair<SVector3, SVector3> > curv;
    for(std::size_t i = 0; i < gf->triangles.size(); i++) {
      MTriangle *t = gf->triangles[i];
      for(int j = 0; j < 3; j++) {
        MVertex *v = t->getVertex(j);
        if(nodeIndex.find(v) == nodeIndex.end()) {
          int idx = nodes.size();
          nodeIndex[v] = idx;
          nodes.push_back(v->point());
          tris.push_back(idx);
        }
        else {
          tris.push_back(nodeIndex[v]);
        }
      }
    }
    CurvatureRusinkiewicz(tris, nodes, curv);
    for(auto itv = nodeIndex.begin(); itv != nodeIndex.end(); itv++) {
      C[itv->first] = curv[itv->second];
    }
  }
  return 0;
}

bool computeParametrization(const std::vector<MTriangle *> &triangles,
                            std::vector<MVertex *> &nodes,
                            std::vector<SPoint2> &stl_vertices_uv,
                            std::vector<SPoint3> &stl_vertices_xyz,
                            std::vector<int> &stl_triangles)
{
  stl_vertices_uv.clear();
  stl_vertices_xyz.clear();
  stl_triangles.clear();
  nodes.clear();

  if(triangles.empty()) return false;

  // get nodes and edges
  std::map<MVertex *, int> nodeIndex;
  std::map<MEdge, std::vector<MTriangle *>, MEdgeLessThan> edges;
  for(std::size_t i = 0; i < triangles.size(); i++) {
    MTriangle *t = triangles[i];
    for(int j = 0; j < 3; j++) {
      MVertex *v = t->getVertex(j);
      if(nodeIndex.find(v) == nodeIndex.end()) {
        nodeIndex[v] = nodes.size();
        nodes.push_back(v);
      }
      edges[t->getEdge(j)].push_back(t);
    }
  }

  // compute edge loops
  std::vector<MEdge> es;
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    if(it->second.size() == 1) { // on boundary
      es.push_back(it->first);
    }
    else if(it->second.size() == 2) { // inside
    }
    else { // non-manifold: not supported
      Msg::Error("Wrong topology of triangulation for parametrization: one "
                 "edge is incident to %d triangles",
                 it->second.size());
      return false;
    }
  }
  std::vector<std::vector<MVertex *> > vs;
  if(!SortEdgeConsecutive(es, vs)) {
    Msg::Error("Wrong topology of boundary mesh for parametrization");
    return false;
  }
  if(vs.empty() || vs[0].size() < 2) {
    Msg::Error("Invalid exterior boundary mesh for parametrization");
    return false;
  }

  Msg::Debug("Parametrisation of surface with %lu triangles, %lu edges and "
             "%lu holes",
             triangles.size(), edges.size(), vs.size() - 1);

  // find longest loop and use it as the "exterior" loop
  int loop = 0;
  double longest = 0.;
  for(std::size_t i = 0; i < vs.size(); i++) {
    double l = 0.;
    for(std::size_t j = 1; j < vs[i].size(); j++) {
      l += vs[i][j]->point().distance(vs[i][j - 1]->point());
    }
    if(l > longest) {
      longest = l;
      loop = i;
    }
  }

  // check orientation of the loop and reverse if necessary
  bool reverse = true;
  MEdge ref(vs[loop][0], vs[loop][1]);
  for(std::size_t i = 0; i < triangles.size(); i++) {
    MTriangle *t = triangles[i];
    for(int j = 0; j < 3; j++) {
      MEdge e = t->getEdge(j);
      if(e.getVertex(0) == ref.getVertex(0) &&
         e.getVertex(1) == ref.getVertex(1)) {
        reverse = false;
        break;
      }
    }
    if(!reverse) break;
  }
  if(reverse) { std::reverse(vs[0].begin(), vs[0].end()); }

  std::vector<double> u(nodes.size(), 0.), v(nodes.size(), 0.);

  // boundary conditions
  std::vector<bool> bc(nodes.size(), false);
  double currentLength = 0;
  int index = nodeIndex[vs[loop][0]];
  bc[index] = true;
  u[index] = 1.;
  v[index] = 0.;
  for(std::size_t i = 1; i < vs[loop].size() - 1; i++) {
    currentLength += vs[loop][i]->point().distance(vs[loop][i - 1]->point());
    double angle = 2 * M_PI * currentLength / longest;
    index = nodeIndex[vs[loop][i]];
    bc[index] = true;
    u[index] = cos(angle);
    v[index] = sin(angle);
  }

  // assemble matrix
#if defined(HAVE_SOLVER)
#if defined(HAVE_PETSC)
  linearSystemPETSc<double> *lsys = new linearSystemPETSc<double>;
  std::string options = "-ksp_type preonly -pc_type lu ";
#if defined(PETSC_HAVE_MUMPS)
  options += "-pc_factor_mat_solver_type mumps";
#elif defined(PETSC_HAVE_MKL_PARDISO)
  options += "-pc_factor_mat_solver_type mkl_pardiso";
#elif defined(PETSC_HAVE_UMFPACK) || defined(PETSC_HAVE_SUITESPARSE)
  options += "-pc_factor_mat_solver_type umfpack";
#endif
  lsys->setParameter("petsc_solver_options", options);
  lsys->setParameter("matrix_reuse", "same_matrix");
#elif defined(HAVE_GMM)
  linearSystemCSRGmm<double> *lsys = new linearSystemCSRGmm<double>;
#else
  linearSystemFull<double> *lsys = new linearSystemFull<double>;
#endif

  lsys->allocate(nodes.size());

#if defined(HAVE_PETSC)
  for(auto it = edges.begin(); it != edges.end(); ++it) {
    for(int i = 0; i < 2; i++) {
      for(int j = 0; j < 2; j++) {
        lsys->insertInSparsityPattern(nodeIndex[it->first.getVertex(i)],
                                      nodeIndex[it->first.getVertex(j)]);
      }
    }
  }
#endif

  for(auto it = edges.begin(); it != edges.end(); ++it) {
    for(int ij = 0; ij < 2; ij++) {
      MVertex *v0 = it->first.getVertex(ij);
      int index0 = nodeIndex[v0];
      if(bc[index0]) continue; // boundary condition
      MVertex *v1 = it->first.getVertex(1 - ij);
      int index1 = nodeIndex[v1];
      MTriangle *tLeft = it->second[0];
      MVertex *vLeft = tLeft->getVertex(0);
      if(vLeft == v0 || vLeft == v1) vLeft = tLeft->getVertex(1);
      if(vLeft == v0 || vLeft == v1) vLeft = tLeft->getVertex(2);
      double e[3] = {v1->x() - v0->x(), v1->y() - v0->y(), v1->z() - v0->z()};
      double ne = sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
      double a[3] = {vLeft->x() - v0->x(), vLeft->y() - v0->y(),
                     vLeft->z() - v0->z()};
      double na = sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
      double thetaL =
        acos((a[0] * e[0] + a[1] * e[1] + a[2] * e[2]) / (na * ne));
      double thetaR = 0.;
      if(it->second.size() == 2) {
        MTriangle *tRight = it->second[1];
        MVertex *vRight = tRight->getVertex(0);
        if(vRight == v0 || vRight == v1) vRight = tRight->getVertex(1);
        if(vRight == v0 || vRight == v1) vRight = tRight->getVertex(2);
        double b[3] = {vRight->x() - v0->x(), vRight->y() - v0->y(),
                       vRight->z() - v0->z()};
        double nb = sqrt(b[0] * b[0] + b[1] * b[1] + b[2] * b[2]);
        thetaR = acos((b[0] * e[0] + b[1] * e[1] + b[2] * e[2]) / (nb * ne));
      }
      double c = (tan(.5 * thetaL) + tan(.5 * thetaR)) / ne;
      lsys->addToMatrix(index0, index1, -c);
      lsys->addToMatrix(index0, index0, c);
    }
  }
  for(std::size_t i = 0; i < vs[loop].size() - 1; i++) {
    int row = nodeIndex[vs[loop][i]];
    lsys->addToMatrix(row, row, 1);
  }

  lsys->zeroRightHandSide();
  for(std::size_t i = 0; i < vs[loop].size() - 1; i++) {
    int row = nodeIndex[vs[loop][i]];
    lsys->addToRightHandSide(row, u[row]);
  }
  lsys->systemSolve();
  for(std::size_t i = 0; i < nodes.size(); i++) lsys->getFromSolution(i, u[i]);

  lsys->zeroRightHandSide();
  for(std::size_t i = 0; i < vs[loop].size() - 1; i++) {
    int row = nodeIndex[vs[loop][i]];
    lsys->addToRightHandSide(row, v[row]);
  }
  lsys->systemSolve();
  for(std::size_t i = 0; i < nodes.size(); i++) lsys->getFromSolution(i, v[i]);

  delete lsys;
#endif

  stl_vertices_uv.resize(nodes.size());
  stl_vertices_xyz.resize(nodes.size());
  for(std::size_t i = 0; i < nodes.size(); i++) {
    stl_vertices_uv[i] = SPoint2(u[i], v[i]);
    stl_vertices_xyz[i] = nodes[i]->point();
  }
  stl_triangles.resize(3 * triangles.size());
  for(std::size_t i = 0; i < triangles.size(); i++) {
    stl_triangles[3 * i + 0] = nodeIndex[triangles[i]->getVertex(0)];
    stl_triangles[3 * i + 1] = nodeIndex[triangles[i]->getVertex(1)];
    stl_triangles[3 * i + 2] = nodeIndex[triangles[i]->getVertex(2)];
  }

  return true;
}

#if 0
static void debugTriangulation(const std::vector<MTriangle *> &triangles,
                               const std::string &label)
{
  FILE *fp = Fopen("debug.pos", "w");
  if(!fp) return;
  fprintf(fp, "View\"%s\"{\n", label.c_str());
  for(auto t : triangles) t->writePOS(fp, false, true, false, false, false, false);
  fprintf(fp, "};\n");
  fclose(fp);
  exit(1);
}
#endif

static int isTriangulationParametrizable(const std::vector<MTriangle *> &t,
                                         int Nmax, std::ostringstream &why)
{
  if(Nmax > 1 && (int)t.size() > Nmax) {
    int np = t.size() / (Nmax - 1) + 1;
    if(np > 1) {
      why << "too many triangles (" << t.size() << " vs. " << Nmax << ")";
      return np;
    }
  }

  std::set<MVertex *> v;
  std::map<MEdge, int, MEdgeLessThan> e;
  for(std::size_t i = 0; i < t.size(); ++i) {
    for(int j = 0; j < 3; j++) {
      v.insert(t[i]->getVertex(j));
      auto it = e.find(t[i]->getEdge(j));
      if(it == e.end())
        e[t[i]->getEdge(j)] = 1;
      else
        it->second++;
    }
  }
  std::vector<MEdge> bnd;
  for(auto it = e.begin(); it != e.end(); ++it) {
    if(it->second == 1) bnd.push_back(it->first);
  }
  if(bnd.empty()) {
    why << "poincare characteristic 2 is not 0";
    //debugTriangulation(t, why.str());
    return 2;
  }

  std::vector<std::vector<MVertex *> > vs;
  if(!SortEdgeConsecutive(bnd, vs)) {
    why << "boundary not manifold";
    return 2;
  }

  std::size_t poincare =
    t.size() - (2 * (v.size() - 1) - bnd.size() + 2 * (vs.size() - 1));
  if(poincare != 0) {
    why << "poincare characteristic " << poincare << " is not 0";
    return 2;
  }

  std::vector<MVertex *> nodes;
  std::vector<SPoint2> stl_nodes_uv;
  std::vector<SPoint3> stl_nodes_xyz;
  std::vector<int> stl_triangles;
  computeParametrization(t, nodes, stl_nodes_uv, stl_nodes_xyz, stl_triangles);
  for(std::size_t i = 0; i < stl_triangles.size(); i += 3) {
    double u0 = stl_nodes_uv[stl_triangles[i + 0]].x();
    double v0 = stl_nodes_uv[stl_triangles[i + 0]].y();
    double u1 = stl_nodes_uv[stl_triangles[i + 1]].x();
    double v1 = stl_nodes_uv[stl_triangles[i + 1]].y();
    double u2 = stl_nodes_uv[stl_triangles[i + 2]].x();
    double v2 = stl_nodes_uv[stl_triangles[i + 2]].y();
    double det = fabs((u1 - u0) * (v2 - v0) - (v1 - v0) * (u2 - u0));
    if(det < 1.e-8) {
      why << "parametrized triangles are too small (" << det << ")";
      return 2;
    }
  }
  return 1;
}

void makeMLinesUnique(std::vector<MLine *> &v)
{
  std::sort(v.begin(), v.end(), MLinePtrLessThan());
  v.erase(std::unique(v.begin(), v.end(), MLinePtrEqual()), v.end());
}

class twoT {
public:
  MTriangle *t1, *t2;
  twoT(MTriangle *t) : t1(t), t2(nullptr) {}
  MTriangle *other(MTriangle *t) const
  {
    if(t == t1) return t2;
    if(t == t2) return t1;
    return nullptr;
  }
};

bool
makePartitionSimplyConnected(std::vector<MTriangle *> &t,
                             std::vector<std::vector<MTriangle *> > &ts)
{
  std::map<MEdge, twoT, MEdgeLessThan> conn;
  for(std::size_t i = 0; i < t.size(); i++) {
    for(int j = 0; j < 3; j++) {
      MEdge e = t[i]->getEdge(j);
      auto it = conn.find(e);
      twoT twt(t[i]);
      if(it == conn.end())
        conn.insert(std::make_pair(e, twt));
      else
        it->second.t2 = t[i];
    }
  }

  while(!t.empty()) {
    std::stack<MTriangle *> _s;
    _s.push(t[0]);
    std::set<MTriangle *, MElementPtrLessThan> touch;
    while(!_s.empty()) {
      MTriangle *x = _s.top();
      touch.insert(x);
      _s.pop();
      for(int j = 0; j < 3; j++) {
        MEdge e = x->getEdge(j);
        auto it = conn.find(e);
        if(it->second.t2) {
          MTriangle *tt = it->second.other(x);
          if(tt && touch.find(tt) == touch.end()) _s.push(tt);
        }
      }
    }
    std::vector<MTriangle *> _part;
    _part.insert(_part.begin(), touch.begin(), touch.end());
    ts.push_back(_part);
    std::vector<MTriangle *> update;
    for(std::size_t i = 0; i < t.size(); i++)
      if(touch.find(t[i]) == touch.end()) update.push_back(t[i]);
    t = update;
  }
  return true;
}

void computeEdgeCut(GModel *gm, std::vector<MLine *> &cut,
                    int max_elems_per_cut)
{
  Msg::Info("Splitting triangulations to make them parametrizable:");

  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    int part = 0;
    if((*it)->triangles.empty()) continue;
    std::vector<MVertex *> verts = (*it)->mesh_vertices;
    std::map<MTriangle *, int, MElementPtrLessThan> global;
    std::map<MEdge, int, MEdgeLessThan> cuts;
    std::stack<std::vector<MTriangle *> > partitions;
    std::stack<int> _levels;
    partitions.push((*it)->triangles);
    _levels.push(0);
    (*it)->triangles.clear();

    while(!partitions.empty()) {
      int level = _levels.top();
      _levels.pop();
      (*it)->triangles = partitions.top();
      (*it)->mesh_vertices.clear();
      std::set<MVertex *, MVertexPtrLessThan> vs;
      for(std::size_t i = 0; i < (*it)->triangles.size(); ++i) {
        for(std::size_t j = 0; j < 3; ++j)
          vs.insert((*it)->triangles[i]->getVertex(j));
      }
      (*it)->mesh_vertices.insert((*it)->mesh_vertices.begin(), vs.begin(),
                                  vs.end());
      partitions.pop();
      std::ostringstream why;
      int np =
        isTriangulationParametrizable((*it)->triangles, max_elems_per_cut, why);
      if(np > 1) {
        Msg::Info(" - Level %d partition with %d triangles split in %d "
                  "parts because %s",
                  level, (*it)->triangles.size(), np, why.str().c_str());
      }
      else if(np < 0) {
        Msg::Error("Could not create parametrization (check orientation of "
                   "input triangulations)");
        break;
      }
      if(np == 1) {
        for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
          global[(*it)->triangles[i]] = part;
        part++;
      }
      else {
#if defined(HAVE_MESH)
        if(!PartitionFaceMinEdgeLength(*it, np)) {
          std::vector<std::vector<MTriangle *> > t(np);
          for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
            int p = (*it)->triangles[i]->getPartition();
            if(p >= 0 && p < np)
              t[p].push_back((*it)->triangles[i]);
            else
              Msg::Error("Invalid partition index");
          }
          for(std::size_t i = 0; i < t.size(); i++) {
            std::vector<std::vector<MTriangle *> > ts;
            if(!makePartitionSimplyConnected(t[i], ts)) {
              Msg::Warning("Could not make partition simply connected");
              break;
            }
            for(std::size_t j = 0; j < ts.size(); j++) {
              _levels.push(level + 1);
              partitions.push(ts[j]);
            }
          }
        }
#else
        Msg::Error("Partitioning surface requires Mesh module");
#endif
      }
    }
    (*it)->triangles.clear();
    for(auto it2 = global.begin(); it2 != global.end(); ++it2) {
      MTriangle *t = it2->first;
      (*it)->triangles.push_back(t);
      for(int i = 0; i < 3; i++) {
        MEdge ed = t->getEdge(i);
        auto it3 = cuts.find(ed);
        if(it3 == cuts.end())
          cuts[ed] = it2->second;
        else {
          if(it3->second != it2->second)
            cut.push_back(new MLine(ed.getVertex(0), ed.getVertex(1)));
        }
      }
    }
    (*it)->mesh_vertices = verts;
  }
  makeMLinesUnique(cut);
}

void computeNonManifoldEdges(GModel *gm, std::vector<MLine *> &cut,
                             bool addBoundary)
{
  std::map<MEdge, int, MEdgeLessThan> m;
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        auto it2 = m.find((*it)->triangles[i]->getEdge(j));
        if(it2 == m.end())
          m[(*it)->triangles[i]->getEdge(j)] = 1;
        else
          it2->second++;
      }
    }
  }
  {
    int countNM = 0, countBND = 0;
    auto it = m.begin();
    for(; it != m.end(); ++it) {
      if(it->second > 2) {
        cut.push_back(
          new MLine(it->first.getVertex(0), it->first.getVertex(1)));
        countNM++;
      }
      if(addBoundary && it->second == 1) {
        cut.push_back(
          new MLine(it->first.getVertex(0), it->first.getVertex(1)));
        countBND++;
      }
    }
    if(countNM + countBND > 0)
      Msg::Info(
        "Model has %d non manifold mesh edges and %d boundary mesh edges",
        countNM, countBND);
  }
  makeMLinesUnique(cut);
}
