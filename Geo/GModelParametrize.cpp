// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

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

#if defined(HAVE_MESH)
#include "meshPartition.h"
#include "meshGFaceOptimize.h"
#endif

#if defined(HAVE_HXT)
extern "C" {
#include "hxt_mesh.h"
#include "hxt_edge.h"
#include "hxt_curvature.h"
#include "hxt_linear_system.h"
#include "hxt_mean_values.h"
}
#endif

#if defined(HAVE_MESH)

static GEdge *getNewModelEdge(GFace *gf1, GFace *gf2,
                              std::map<std::pair<int, int>, GEdge *> &newEdges)
{
  int t1 = gf1 ? gf1->tag() : -1;
  int t2 = gf2 ? gf2->tag() : -1;
  int i1 = std::min(t1, t2);
  int i2 = std::max(t1, t2);

  // FIXME remove internal edges!
  if(i1 == i2) return 0;

  GModel *gm = gf1->model();

  std::map<std::pair<int, int>, GEdge *>::iterator it =
    newEdges.find(std::make_pair(i1, i2));
  if(it == newEdges.end()) {
    discreteEdge *ge =
      new discreteEdge(gm, gm->getMaxElementaryNumber(1) + 1, 0, 0);
    gm->add(ge);
    newEdges[std::make_pair(i1, i2)] = ge;
    return ge;
  }
  else
    return it->second;
}

static void classify(MTri3 *t, std::map<MTriangle *, GFace *> &reverse,
                     std::map<MLine *, GEdge *, compareMLinePtr> &lines,
                     std::set<MLine *> &touched, std::set<MTri3 *> &trisTouched,
                     std::map<std::pair<int, int>, GEdge *> &newEdges)
{
  std::stack<MTri3 *> _stack;
  _stack.push(t);
  while(!_stack.empty()) {
    t = _stack.top();
    _stack.pop();
    if(!t->isDeleted()) {
      trisTouched.erase(t);
      t->setDeleted(true);
      GFace *gf1 = reverse[t->tri()];
      for(int i = 0; i < 3; i++) {
        GFace *gf2 = 0;
        MTri3 *tn = t->getNeigh(i);
        if(tn) gf2 = reverse[tn->tri()];
        edgeXface exf(t, i);
        MLine ml(exf._v(0), exf._v(1));
        std::map<MLine *, GEdge *, compareMLinePtr>::iterator it =
          lines.find(&ml);
        if(it != lines.end()) {
          if(touched.find(it->first) == touched.end()) {
            GEdge *ge = getNewModelEdge(gf1, gf2, newEdges);
            if(ge) ge->lines.push_back(it->first);
            touched.insert(it->first);
          }
        }
        if(tn) { _stack.push(tn); }
      }
    }
  }
}

static void classify(MTri3 *t, GFace *gf,
                     std::map<MLine *, GEdge *, compareMLinePtr> &lines,
                     std::map<MTriangle *, GFace *> &reverse)
{
  std::stack<MTri3 *> _stack;
  _stack.push(t);
  while(!_stack.empty()) {
    t = _stack.top();
    _stack.pop();
    if(!t->isDeleted()) {
      gf->triangles.push_back(t->tri());
      reverse[t->tri()] = gf;
      t->setDeleted(true);
      for(int i = 0; i < 3; i++) {
        MTri3 *tn = t->getNeigh(i);
        if(tn) {
          edgeXface exf(t, i);
          MLine ml(exf._v(0), exf._v(1));
          std::map<MLine *, GEdge *, compareMLinePtr>::iterator it =
            lines.find(&ml);
          if(it == lines.end()) { _stack.push(tn); }
        }
      }
    }
  }
}

#endif

void classifyFaces(GModel *gm)
{
#if defined(HAVE_MESH)

  // create a structure from mesh edges to geometrical curves, and remove curves
  // from the model (FIXME: memory leak)
  std::map<MLine *, GEdge *, compareMLinePtr> lines;
  std::vector<GEdge *> edgesToRemove;
  for(GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    for(std::size_t i = 0; i < (*it)->lines.size(); i++) {
      lines[(*it)->lines[i]] = *it;
    }
    edgesToRemove.push_back(*it);
  }
  for(std::size_t i = 0; i < edgesToRemove.size(); ++i) {
    gm->remove(edgesToRemove[i]);
  }

  // remove points from model (FIXME: memory leak)
  std::vector<GVertex *> pointsToRemove;
  for(GModel::viter it = gm->firstVertex(); it != gm->lastVertex(); ++it) {
    pointsToRemove.push_back(*it);
  }
  for(std::size_t i = 0; i < pointsToRemove.size(); ++i) {
    gm->remove(pointsToRemove[i]);
  }

  // create triangle-triangle connections
  std::map<MTriangle *, GFace *> reverse_old;
  std::list<MTri3 *> tris;
  {
    GModel::fiter it = gm->firstFace();
    while(it != gm->lastFace()) {
      GFace *gf = *it;
      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        tris.push_back(new MTri3(gf->triangles[i], 0));
        reverse_old[gf->triangles[i]] = gf;
      }
      gf->triangles.clear();
      gf->mesh_vertices.clear();
      ++it;
    }
  }
  if(tris.empty()) return;
  connectTriangles(tris);

  // color all triangles
  std::map<MTriangle *, GFace *> reverse;
  std::multimap<GFace *, GFace *> replacedBy;
  std::list<MTri3 *>::iterator it = tris.begin();
  std::list<GFace *> newf;
  while(it != tris.end()) {
    if(!(*it)->isDeleted()) {
      discreteFace *gf =
        new discreteFace(gm, gm->getMaxElementaryNumber(2) + 1);
      classify(*it, gf, lines, reverse);
      gm->add(gf);
      newf.push_back(gf);
      for(std::size_t i = 0; i < gf->triangles.size(); i++) {
        replacedBy.insert(std::make_pair(reverse_old[gf->triangles[i]], gf));
      }
    }
    ++it;
  }

  // now we have all faces coloured. If some regions were existing, replace
  // their faces by the new ones
  for(GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
    std::vector<GFace *> _xfaces = (*rit)->faces();
    std::set<GFace *> _newFaces;
    for(std::vector<GFace *>::iterator itf = _xfaces.begin();
        itf != _xfaces.end(); ++itf) {
      std::multimap<GFace *, GFace *>::iterator itLow =
        replacedBy.lower_bound(*itf);
      std::multimap<GFace *, GFace *>::iterator itUp =
        replacedBy.upper_bound(*itf);

      for(; itLow != itUp; ++itLow) _newFaces.insert(itLow->second);
    }
    (*rit)->set(std::vector<GFace *>(_newFaces.begin(), _newFaces.end()));
  }

  it = tris.begin();
  while(it != tris.end()) {
    (*it)->setDeleted(false);
    ++it;
  }

  // color lines that are bound by different GFaces
  std::map<std::pair<int, int>, GEdge *> newEdges;
  std::set<MLine *> touched;
  std::set<MTri3 *> trisTouched;
  trisTouched.insert(tris.begin(), tris.end());
  while(!trisTouched.empty())
    classify(*trisTouched.begin(), reverse, lines, touched, trisTouched,
             newEdges);

  // check if new edges should not be split;
  std::map<discreteFace *, std::vector<int> > newFaceTopology;
  std::map<MVertex *, GVertex *> modelVertices;

  for(std::map<std::pair<int, int>, GEdge *>::iterator ite = newEdges.begin();
      ite != newEdges.end(); ++ite) {
    std::list<MLine *> allSegments;
    for(std::size_t i = 0; i < ite->second->lines.size(); i++)
      allSegments.push_back(ite->second->lines[i]);
    while(!allSegments.empty()) {
      std::list<MLine *> segmentsForThisDiscreteEdge;
      MVertex *vB = (*allSegments.begin())->getVertex(0);
      MVertex *vE = (*allSegments.begin())->getVertex(1);
      segmentsForThisDiscreteEdge.push_back(*allSegments.begin());
      allSegments.erase(allSegments.begin());
      while(1) {
        bool found = false;
        for(std::list<MLine *>::iterator it = allSegments.begin();
            it != allSegments.end(); ++it) {
          MVertex *v1 = (*it)->getVertex(0);
          MVertex *v2 = (*it)->getVertex(1);
          if(v1 == vE || v2 == vE) {
            segmentsForThisDiscreteEdge.push_back(*it);
            if(v2 == vE) (*it)->reverse();
            vE = (v1 == vE) ? v2 : v1;
            found = true;
            allSegments.erase(it);
            break;
          }
          if(v1 == vB || v2 == vB) {
            segmentsForThisDiscreteEdge.push_front(*it);
            if(v1 == vB) (*it)->reverse();
            vB = (v1 == vB) ? v2 : v1;
            found = true;
            allSegments.erase(it);
            break;
          }
        }
        if(vE == vB) break;
        if(!found) break;
      }

      std::map<MVertex *, GVertex *>::iterator itMV = modelVertices.find(vB);
      if(itMV == modelVertices.end()) {
        GVertex *newGv = new discreteVertex(
          gm, gm->getMaxElementaryNumber(0) + 1, vB->x(), vB->y(), vB->z());
        newGv->mesh_vertices.push_back(vB);
        vB->setEntity(newGv);
        newGv->points.push_back(new MPoint(vB));
        gm->add(newGv);
        modelVertices[vB] = newGv;
      }
      itMV = modelVertices.find(vE);
      if(itMV == modelVertices.end()) {
        GVertex *newGv = new discreteVertex(
          gm, gm->getMaxElementaryNumber(0) + 1, vE->x(), vE->y(), vE->z());
        newGv->mesh_vertices.push_back(vE);
        newGv->points.push_back(new MPoint(vE));
        vE->setEntity(newGv);
        gm->add(newGv);
        modelVertices[vE] = newGv;
      }

      GEdge *newGe = new discreteEdge(gm, gm->getMaxElementaryNumber(1) + 1,
                                      modelVertices[vB], modelVertices[vE]);
      newGe->lines.insert(newGe->lines.end(),
                          segmentsForThisDiscreteEdge.begin(),
                          segmentsForThisDiscreteEdge.end());

      for(std::list<MLine *>::iterator itL =
            segmentsForThisDiscreteEdge.begin();
          itL != segmentsForThisDiscreteEdge.end(); ++itL) {
        if((*itL)->getVertex(0)->onWhat()->dim() != 0) {
          newGe->mesh_vertices.push_back((*itL)->getVertex(0));
          (*itL)->getVertex(0)->setEntity(newGe);
        }
      }

      gm->add(newGe);
      discreteFace *gf1 =
        dynamic_cast<discreteFace *>(gm->getFaceByTag(ite->first.first));
      discreteFace *gf2 =
        dynamic_cast<discreteFace *>(gm->getFaceByTag(ite->first.second));
      if(gf1) newFaceTopology[gf1].push_back(newGe->tag());
      if(gf2) newFaceTopology[gf2].push_back(newGe->tag());
    }
  }

  std::map<discreteFace *, std::vector<int> >::iterator itFT =
    newFaceTopology.begin();
  for(; itFT != newFaceTopology.end(); ++itFT) {
    itFT->first->setBoundEdges(itFT->second);
  }

  for(std::map<std::pair<int, int>, GEdge *>::iterator it = newEdges.begin();
      it != newEdges.end(); ++it) {
    GEdge *ge = it->second;
    gm->remove(ge);
    // delete ge;
  }

  it = tris.begin();
  while(it != tris.end()) {
    delete *it;
    ++it;
  }

  // remove empty mesh faces
  std::set<GFace *, GEntityLessThan> fac = gm->getFaces();
  for(std::set<GFace *, GEntityLessThan>::iterator fit = fac.begin();
      fit != fac.end(); ++fit) {
    if((*fit)->triangles.empty())
      gm->remove(*fit);
  }
#endif
}

void classifyFaces(GModel *gm, double angleThreshold, bool includeBoundary,
                   bool forParametrization)
{
#if defined(HAVE_MESH)
  Msg::StatusBar(true, "Classifying surfaces (angle: %g)...",
                 angleThreshold * 180. / M_PI);
  double t1 = Cpu();

  std::set<GFace *> faces;
  std::vector<MElement *> elements;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    faces.insert(*it);
    elements.insert(elements.end(), (*it)->triangles.begin(),
                    (*it)->triangles.end());
    elements.insert(elements.end(), (*it)->quadrangles.begin(),
                    (*it)->quadrangles.end());
  }

  discreteEdge *edge =
    new discreteEdge(gm, gm->getMaxElementaryNumber(1) + 1, 0, 0);
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
    computeEdgeCut(gm, edge->lines, 100000);
  computeNonManifoldEdges(gm, edge->lines, true);
  classifyFaces(gm);

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

  double t2 = Cpu();
  Msg::StatusBar(true, "Done classifying surfaces (%g s)", t2 - t1);

#else
  Msg::Error("Surface classification requires the mesh module");
#endif
}

#if defined(HAVE_HXT)

static HXTStatus gmsh2hxt(int tag, const std::vector<MTriangle *> &t,
                          HXTMesh **pm, std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  HXTContext *context;
  hxtContextCreate(&context);
  HXTMesh *m;
  HXT_CHECK(hxtMeshCreate(context, &m));
  std::set<MVertex *> all;
  for(std::size_t i = 0; i < t.size(); i++) {
    all.insert(t[i]->getVertex(0));
    all.insert(t[i]->getVertex(1));
    all.insert(t[i]->getVertex(2));
  }
  m->vertices.num = m->vertices.size = all.size();
  HXT_CHECK(
    hxtAlignedMalloc(&m->vertices.coord, 4 * m->vertices.num * sizeof(double)));

  std::size_t count = 0;
  c2v.resize(all.size());
  for(std::set<MVertex *>::iterator it = all.begin(); it != all.end(); it++) {
    m->vertices.coord[4 * count + 0] = (*it)->x();
    m->vertices.coord[4 * count + 1] = (*it)->y();
    m->vertices.coord[4 * count + 2] = (*it)->z();
    m->vertices.coord[4 * count + 3] = 0.0;
    v2c[*it] = count;
    c2v[count++] = *it;
  }
  all.clear();

  m->triangles.num = m->triangles.size = t.size();
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.node,
                             (m->triangles.num) * 3 * sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&m->triangles.colors,
                             (m->triangles.num) * sizeof(uint16_t)));
  for(std::size_t i = 0; i < t.size(); i++) {
    m->triangles.node[3 * i + 0] = v2c[t[i]->getVertex(0)];
    m->triangles.node[3 * i + 1] = v2c[t[i]->getVertex(1)];
    m->triangles.node[3 * i + 2] = v2c[t[i]->getVertex(2)];
    m->triangles.colors[i] = tag;
  }

  m->lines.num = m->lines.size = 0;

  *pm = m;
  return HXT_STATUS_OK;
}

static HXTStatus gmsh2hxt(GFace *gf, HXTMesh **pm,
                          std::map<MVertex *, int> &v2c,
                          std::vector<MVertex *> &c2v)
{
  return gmsh2hxt(gf->tag(), gf->triangles, pm, v2c, c2v);
}

#endif

int computeDiscreteCurvatures(GModel *gm)
{
#if defined(HAVE_HXT)
  std::map<MVertex *, std::pair<SVector3, SVector3> > &C = gm->getCurvatures();
  C.clear();
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    HXTMesh *m;
    HXTEdges *edges;
    double *nodalCurvatures;
    double *crossField;
    std::map<MVertex *, int> v2c;
    std::vector<MVertex *> c2v;
    gmsh2hxt(*it, &m, v2c, c2v);
    HXT_CHECK(hxtEdgesCreate(m, &edges));
    HXT_CHECK(
      hxtCurvatureRusinkiewicz(m, &nodalCurvatures, &crossField, edges, false));
    const double ratioMax = 1.3;
    const bool debug = false;
    if(debug) {
      char name[256];
      sprintf(name, "nodalCurvatures%d.pos", (*it)->tag());
      saveNodalField(m, nodalCurvatures, 6, name);
    }
    while(0) {
      int touched = 0;
      for(std::size_t i = 0; i < m->triangles.num; i++) {
        for(int j = 0; j < 3; j++) {
          uint32_t v0 = m->triangles.node[3 * i + (j + 0) % 3];
          uint32_t v1 = m->triangles.node[3 * i + (j + 1) % 3];
          double *c0 = &nodalCurvatures[6 * v0];
          double *c1 = &nodalCurvatures[6 * v1];
          SVector3 cMax0(c0[0], c0[1], c0[2]);
          SVector3 cMin0(c0[3], c0[4], c0[5]);
          SVector3 cMax1(c1[0], c1[1], c1[2]);
          SVector3 cMin1(c1[3], c1[4], c1[5]);
          SPoint3 p0(m->vertices.coord[4 * v0 + 0],
                     m->vertices.coord[4 * v0 + 1],
                     m->vertices.coord[4 * v0 + 2]);
          SPoint3 p1(m->vertices.coord[4 * v1 + 0],
                     m->vertices.coord[4 * v1 + 1],
                     m->vertices.coord[4 * v1 + 2]);
          double d01 = p0.distance(p1);
          double M0 = cMax0.norm();
          double M1 = cMax1.norm();
          // change M0
          if(d01 > 0 && M0 > 0 && M1 > 0 && M0 > M1) {
            // the largest size is at node 0
            double size0 = 2 * M_PI * M0 / (15);
            double size1 = 2 * M_PI * M1 / (15);
            double gradSize = (size0 - size1) / d01;
            if(gradSize > ratioMax) {
              touched++;
              size0 = size1 - ratioMax * d01;
              M0 = size0 * 15 / (2 * M_PI);
              cMax0.normalize();
              cMax0 *= M0;
              nodalCurvatures[6 * v0 + 0] = cMax0.x();
              nodalCurvatures[6 * v0 + 1] = cMax0.y();
              nodalCurvatures[6 * v0 + 2] = cMax0.z();
            }
          }
          else if(d01 > 0 && M0 > 0 && M1 > 0 && M1 > M0) {
            // the largest size is at node 0
            double size0 = 2 * M_PI * M0 / (15);
            double size1 = 2 * M_PI * M1 / (15);
            double gradSize = (size1 - size0) / d01;
            if(gradSize > ratioMax) {
              touched++;
              size1 = size0 - ratioMax * d01;
              M1 = size1 * 15 / (2 * M_PI);
              cMax1.normalize();
              cMax1 *= M0;
              nodalCurvatures[6 * v1 + 0] = cMax0.x();
              nodalCurvatures[6 * v1 + 1] = cMax0.y();
              nodalCurvatures[6 * v1 + 2] = cMax0.z();
            }
          }
        }
      }
      if(!touched) break;
    }

    if(debug) {
      char name[256];
      sprintf(name, "nodalCurvaturesCorrected%d.pos", (*it)->tag());
      saveNodalField(m, nodalCurvatures, 6, name);
    }

    for(std::size_t i = 0; i < m->vertices.num; i++) {
      MVertex *v = c2v[i];
      double *c = &nodalCurvatures[6 * i];
      SVector3 cMax(c[0], c[1], c[2]);
      SVector3 cMin(c[3], c[4], c[5]);
      std::pair<SVector3, SVector3> out = std::make_pair(cMax, cMin);
      C.insert(std::make_pair(v, out));
    }
    HXT_CHECK(hxtEdgesDelete(&edges));
    HXT_CHECK(hxtFree(&nodalCurvatures));
    HXT_CHECK(hxtFree(&crossField));
    HXT_CHECK(hxtMeshDelete(&m));
  }
#endif
  return 0;
}

int isTriangulationParametrizable(const std::vector<MTriangle *> &t, int Nmax,
                                  double ar, std::ostringstream &why)
{
#if defined(HAVE_HXT)
  int XX = (int)t.size();
  if(XX > Nmax) {
    why << "too many triangles (" << XX << " vs. " << Nmax << ")";
    return XX / Nmax + 1;
  }
  std::set<MVertex *> v;
  std::map<MEdge, int, Less_Edge> e;
  double surf = 0;
  for(std::size_t i = 0; i < t.size(); ++i) {
    surf += t[i]->getVolume();
    for(int j = 0; j < 3; j++) {
      v.insert(t[i]->getVertex(j));
      std::map<MEdge, int, Less_Edge>::iterator it = e.find(t[i]->getEdge(j));
      if(it == e.end())
        e[t[i]->getEdge(j)] = 1;
      else
        it->second++;
    }
  }
  std::map<MEdge, int, Less_Edge>::iterator it = e.begin();
  std::vector<MEdge> _bnd;
  for(; it != e.end(); ++it) {
    if(it->second == 1) _bnd.push_back(it->first);
  }

  std::vector<std::vector<MVertex *> > vs;
  if(!SortEdgeConsecutive(_bnd, vs)) {
    // we have vertices adjacent to more than 2 model edges
#if 0
    FILE *f = fopen("bug.pos","w");
    fprintf(f,"View\"\"{\n");
    for (std::size_t i = 0; i < t.size(); i++){
      fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
              t[i]->getVertex(0)->x(), t[i]->getVertex(0)->y(),
              t[i]->getVertex(0)->z(), t[i]->getVertex(1)->x(),
              t[i]->getVertex(1)->y(), t[i]->getVertex(1)->z(),
              t[i]->getVertex(2)->x(), t[i]->getVertex(2)->y(),
              t[i]->getVertex(2)->z(), t[i]->getVertex(0)->getNum(),
              t[i]->getVertex(1)->getNum(), t[i]->getVertex(2)->getNum());
    }
    fprintf(f,"};\n");
    fclose(f);
    getchar();
#endif
    why << "boundary not manifold";
    return 2;
  }

  double lmax = 0;
  for(std::size_t i = 0; i < vs.size(); i++) {
    double li = 0;
    for(std::size_t j = 1; j < vs[i].size(); j++) {
      li += distance(vs[i][j], vs[i][j - 1]);
    }
    lmax = std::max(li, lmax);
  }

  double poincare =
    t.size() - (2 * (v.size() - 1) - _bnd.size() + 2 * (vs.size() - 1));

  if(_bnd.empty()) {
    why << "poincare characteristic 2 is not 0";
    return 2;
  }

  // if(ar * lmax * lmax < 2 * M_PI * surf) {
  //   why << "aspect ratio " << surf *2 * M_PI/(ar * lmax * lmax) << " is too
  //   large"; return 2;
  // }

  if(poincare != 0) {
    why << "poincare characteristic " << poincare << " is not 0";
    return 2;
  }

  int n = 1;
  HXT_CHECK(hxtInitializeLinearSystems(&n, NULL));

#if 0
  FILE *f = fopen("bug.pos","w");
  fprintf(f,"View\"\"{\n");
  for (std:: size_t i = 0; i < t.size(); i++){
    fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%d,%d,%d};\n",
            t[i]->getVertex(0)->x(), t[i]->getVertex(0)->y(),
            t[i]->getVertex(0)->z(), t[i]->getVertex(1)->x(),
            t[i]->getVertex(1)->y(), t[i]->getVertex(1)->z(),
            t[i]->getVertex(2)->x(), t[i]->getVertex(2)->y(),
            t[i]->getVertex(2)->z(), t[i]->getVertex(0)->getNum(),
            t[i]->getVertex(1)->getNum(), t[i]->getVertex(2)->getNum());
  }
  fprintf(f,"};\n");
  fclose(f);
#endif

  HXTMesh *m;
  HXTMeanValues *param;
  HXTEdges *edges;
  std::map<MVertex *, int> v2c;
  std::vector<MVertex *> c2v;
  gmsh2hxt(1, t, &m, v2c, c2v);
  HXT_CHECK(hxtEdgesCreate(m, &edges));
  HXT_CHECK(hxtMeanValuesCreate(edges, &param));
  HXT_CHECK(hxtMeanValuesCompute(param));
  double *uvc = NULL;
  int nv, ne;
  HXT_CHECK(hxtMeanValuesGetData(param, NULL, NULL, &uvc, &nv, &ne, 1));

  for(int ie = 0; ie < ne; ie++) {
    double u0 = uvc[2 * m->triangles.node[3 * ie + 0] + 0];
    double v0 = uvc[2 * m->triangles.node[3 * ie + 0] + 1];
    double u1 = uvc[2 * m->triangles.node[3 * ie + 1] + 0];
    double v1 = uvc[2 * m->triangles.node[3 * ie + 1] + 1];
    double u2 = uvc[2 * m->triangles.node[3 * ie + 2] + 0];
    double v2 = uvc[2 * m->triangles.node[3 * ie + 2] + 1];
    double det = fabs((u1 - u0) * (v2 - v0) - (v1 - v0) * (u2 - u0));

    if(det < 1.e-5) {
      HXT_CHECK(hxtMeshDelete(&m));
      HXT_CHECK(hxtEdgesDelete(&edges));
      HXT_CHECK(hxtFree(&uvc));
      why << "parametrized triangles are too small (" << det << ")";
      return 2;
    }
  }

  HXT_CHECK(hxtMeshDelete(&m));
  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtFree(&uvc));
#endif
  return 1;
}

void makeMLinesUnique(std::vector<MLine *> &v)
{
  std::sort(v.begin(), v.end(), compareMLinePtr());
  v.erase(std::unique(v.begin(), v.end(), equalMLinePtr()), v.end());
}

class twoT {
public:
  MTriangle *_t1, *_t2;
  twoT(MTriangle *t1) : _t1(t1), _t2(NULL) {}
  MTriangle *other(MTriangle *t) const
  {
    if(t == _t1) return _t2;
    if(t == _t2) return _t1;
    Msg::Error("Non-manifold triangulation not supported yet");
    return NULL;
  }
};

static bool
makePartitionSimplyConnected(std::vector<MTriangle *> &t,
                             std::vector<std::vector<MTriangle *> > &ts)
{
  std::map<MEdge, twoT, Less_Edge> conn;
  for(std::size_t i = 0; i < t.size(); i++) {
    for(int j = 0; j < 3; j++) {
      MEdge e = t[i]->getEdge(j);
      std::map<MEdge, twoT, Less_Edge>::iterator it = conn.find(e);
      twoT twt(t[i]);
      if(it == conn.end())
        conn.insert(std::make_pair(e, twt));
      else
        it->second._t2 = t[i];
    }
  }

  while(!t.empty()) {
    std::stack<MTriangle *> _s;
    _s.push(t[0]);
    std::set<MTriangle *> _touch;
    while(!_s.empty()) {
      MTriangle *x = _s.top();
      _touch.insert(x);
      _s.pop();
      for(int j = 0; j < 3; j++) {
        MEdge e = x->getEdge(j);
        std::map<MEdge, twoT, Less_Edge>::iterator it = conn.find(e);
        if(it->second._t2) {
          MTriangle *tt = it->second.other(x);
          if(!tt) return false; // FIXME
          if(_touch.find(tt) == _touch.end()) _s.push(tt);
        }
      }
    }
    std::vector<MTriangle *> _part;
    _part.insert(_part.begin(), _touch.begin(), _touch.end());
    ts.push_back(_part);
    std::vector<MTriangle *> _update;
    for(std::size_t i = 0; i < t.size(); i++)
      if(_touch.find(t[i]) == _touch.end()) _update.push_back(t[i]);
    t = _update;
  }
  return true;
}

void computeEdgeCut(GModel *gm, std::vector<MLine *> &cut,
                    int max_elems_per_cut)
{
  GModel m;

  Msg::Info("Splitting triangulations to make them parametrizable:");

#if 0 // this is now done in the STL reader
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    std::vector<MTriangle *> aa;
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      if((*it)->triangles[i]->getVertex(0) ==
         (*it)->triangles[i]->getVertex(1) ||
         (*it)->triangles[i]->getVertex(0) ==
         (*it)->triangles[i]->getVertex(2) ||
         (*it)->triangles[i]->getVertex(1) ==
         (*it)->triangles[i]->getVertex(2)) {
      }
      else
        aa.push_back((*it)->triangles[i]);
    }
    (*it)->triangles = aa;
  }
#endif

  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    int part = 0;
    if((*it)->triangles.empty()) continue;
    std::vector<MVertex *> verts = (*it)->mesh_vertices;
    std::map<MTriangle *, int> global;
    std::map<MEdge, int, Less_Edge> cuts;
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
      std::set<MVertex *> vs;
      for(std::size_t i = 0; i < (*it)->triangles.size(); ++i) {
        for(std::size_t j = 0; j < 3; ++j)
          vs.insert((*it)->triangles[i]->getVertex(j));
      }
      (*it)->mesh_vertices.insert((*it)->mesh_vertices.begin(), vs.begin(),
                                  vs.end());
      partitions.pop();
      std::ostringstream why;
      int np = isTriangulationParametrizable((*it)->triangles,
                                             max_elems_per_cut, 5.0, why);
      if(np > 1) {
        Msg::Info(" - Level %d partition with %d triangles split in %d "
                  "parts because %s", level, (*it)->triangles.size(), np,
                  why.str().c_str());
      }
      if(np == 1) {
        for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
          global[(*it)->triangles[i]] = part;
        part++;
      }
      else {
#if defined(HAVE_MESH)
        int *p = new int[(*it)->triangles.size()];
        if(!PartitionFace(*it, np, p)) {
          std::vector<MTriangle *> t[1000];
          for(std::size_t i = 0; i < (*it)->triangles.size(); i++)
            t[(*it)->triangles[i]->getPartition()].push_back(
              (*it)->triangles[i]);
          for(int i = 0; i < np; i++) {
            std::vector<std::vector<MTriangle *> > ts;
            if(!makePartitionSimplyConnected(t[i], ts)){
              break; // FIXME
            }
            for(std::size_t j = 0; j < ts.size(); j++) {
              _levels.push(level + 1);
              partitions.push(ts[j]);
            }
          }
        }
        delete[] p;
#else
        Msg::Error("Partitioning surface requires Mesh module");
#endif
      }
    }
    (*it)->triangles.clear();
    std::map<MTriangle *, int>::iterator it2 = global.begin();
    for(; it2 != global.end(); ++it2) {
      MTriangle *t = it2->first;
      (*it)->triangles.push_back(t);
      for(int i = 0; i < 3; i++) {
        MEdge ed = t->getEdge(i);
        std::map<MEdge, int, Less_Edge>::iterator it3 = cuts.find(ed);
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
  std::map<MEdge, int, Less_Edge> m;
  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it) {
    for(std::size_t i = 0; i < (*it)->triangles.size(); i++) {
      for(int j = 0; j < 3; j++) {
        std::map<MEdge, int, Less_Edge>::iterator it2 =
          m.find((*it)->triangles[i]->getEdge(j));
        if(it2 == m.end())
          m[(*it)->triangles[i]->getEdge(j)] = 1;
        else
          it2->second++;
      }
    }
  }
  {
    int countNM = 0, countBND = 0;
    std::map<MEdge, int, Less_Edge>::iterator it = m.begin();
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
