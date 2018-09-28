// Gmsh - Copyright (C) 1997-2018 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include <stdlib.h>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "BackgroundMesh.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
#include "discreteFace.h"
#include "MVertex.h"
#include "MElement.h"
#include "Context.h"
#include "GPoint.h"
#include "GModel.h"
#include "Numeric.h"
#include "BDS.h"
#include "qualityMeasures.h"
#include "Field.h"
#include "OS.h"

static void getDegeneratedVertices(
  BDS_Mesh &m, std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap,
  std::set<MVertex *, MVertexLessThanNum> &degenerated,
  std::vector<BDS_Edge *> &degenerated_edges)
{
  degenerated.clear();

  std::vector<BDS_Edge *>::iterator it = m.edges.begin();

  while(it != m.edges.end()) {
    BDS_Edge *e = *it;
    if(!e->deleted && e->numfaces() == 1) {
      std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp1 =
        recoverMap->find(e->p1);
      std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp2 =
        recoverMap->find(e->p2);
      if(itp1 != recoverMap->end() && itp2 != recoverMap->end() &&
         itp1->second == itp2->second) {
        degenerated.insert(itp1->second);
        //	itp1->first->_degeneratedTo = itp2->first;
        //	itp2->first->_degeneratedTo = itp1->first;
        degenerated_edges.push_back(e);
      }
    }
    ++it;
  }
}

double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->X - p2->X;
  const double dy = p1->Y - p2->Y;
  const double dz = p1->Z - p2->Z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2, GFace *f)
{
  GPoint GP = f->point(SPoint2(0.5 * (p1->u + p2->u), 0.5 * (p1->v + p2->v)));

  if(!GP.succeeded()) return computeEdgeLinearLength(p1, p2);

  const double dx1 = p1->X - GP.x();
  const double dy1 = p1->Y - GP.y();
  const double dz1 = p1->Z - GP.z();
  const double l1 = std::sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);

  const double dx2 = p2->X - GP.x();
  const double dy2 = p2->Y - GP.y();
  const double dz2 = p2->Z - GP.z();
  const double l2 = std::sqrt(dx2 * dx2 + dy2 * dy2 + dz2 * dz2);

  return l1 + l2;
}

double computeEdgeLinearLength(BDS_Edge *e, GFace *f)
{
  // FIXME !!!
  return f->geomType() == GEntity::Plane ?
           e->length() :
           computeEdgeLinearLength(e->p1, e->p2, f);
}

double NewGetLc(BDS_Point *point)
{
  return Extend1dMeshIn2dSurfaces() ? std::min(point->lc(), point->lcBGM()) :
                                      point->lcBGM();
}

static double correctLC_(BDS_Point *p1, BDS_Point *p2, GFace *f)
{
  double l1 = NewGetLc(p1);
  double l2 = NewGetLc(p2);
  double l = .5 * (l1 + l2);

  const double coord = 0.5;
  double U = coord * p1->u + (1 - coord) * p2->u;
  double V = coord * p1->v + (1 - coord) * p2->v;

  GPoint gpp = f->point(U, V);
  double lmid = BGM_MeshSize(f, U, V, gpp.x(), gpp.y(), gpp.z());
  l = std::min(l, lmid);

  if(CTX::instance()->mesh.lcFromCurvature) {
    double l3 = l;
    double const lcmin = std::min(std::min(l1, l2), l3);
    l1 = std::min(lcmin * 1.2, l1);
    l2 = std::min(lcmin * 1.2, l2);
    l3 = std::min(lcmin * 1.2, l3);
    l = (l1 + l2 + l3) / 3.0;
  }
  return l;
}

double NewGetLc(BDS_Edge *const edge, GFace *const face)
{
  return computeEdgeLinearLength(edge, face) /
         correctLC_(edge->p1, edge->p2, face);
}

double NewGetLc(BDS_Point *p1, BDS_Point *p2, GFace *f)
{
  double linearLength = computeEdgeLinearLength(p1, p2, f);
  double l = correctLC_(p1, p2, f);
  return linearLength / l;
}

void computeMeshSizeFieldAccuracy(GFace *gf, BDS_Mesh &m, double &avg,
                                  double &max_e, double &min_e, int &nE,
                                  int &GS)
{
  std::vector<BDS_Edge *>::const_iterator it = m.edges.begin();
  avg = 0.0;
  min_e = 1.e22;
  max_e = 0;
  nE = 0;
  GS = 0;
  while(it != m.edges.end()) {
    if(!(*it)->deleted) {
      double const lone = NewGetLc(*it, gf);
      if(lone > 1.0 / std::sqrt(2.0) && lone < std::sqrt(2.0)) GS++;
      avg += lone > 1 ? (1. / lone) - 1. : lone - 1.;
      max_e = std::max(max_e, lone);
      min_e = std::min(min_e, lone);
      nE++;
    }
    ++it;
  }
  avg = 100 * std::exp(1.0 / nE * avg);
}

// SWAP TESTS i.e. tell if swap should be done

static bool edgeSwapTestAngle(BDS_Edge *e, double min_cos)
{
  BDS_Face *f1 = e->faces(0);
  BDS_Face *f2 = e->faces(1);
  BDS_Point *n1[4];
  BDS_Point *n2[4];
  f1->getNodes(n1);
  f2->getNodes(n2);
  double norm1[3];
  double norm2[3];
  normal_triangle(n1[0], n1[1], n1[2], norm1);
  normal_triangle(n2[0], n2[1], n2[2], norm2);

  return prosca(norm1, norm2) > min_cos;
}

static bool edgeSwapTestDelaunayAniso(BDS_Edge *e, GFace *gf,
                                      std::set<swapquad> &configs)
{
  BDS_Point *op[2];

  if(!e->p1->config_modified && !e->p2->config_modified) return false;

  if(e->numfaces() != 2) return false;

  e->oppositeof(op);

  swapquad sq(e->p1->iD, e->p2->iD, op[0]->iD, op[1]->iD);
  if(configs.find(sq) != configs.end()) return false;
  configs.insert(sq);

  double edgeCenter[2] = {0.5 * (e->p1->u + e->p2->u),
                          0.5 * (e->p1->v + e->p2->v)};

  double p1[2] = {e->p1->u, e->p1->v};
  double p2[2] = {e->p2->u, e->p2->v};
  double p3[2] = {op[0]->u, op[0]->v};
  double p4[2] = {op[1]->u, op[1]->v};
  double metric[3];
  buildMetric(gf, edgeCenter, metric);
  if(!inCircumCircleAniso(gf, p1, p2, p3, p4, metric)) {
    return false;
  }
  return true;
}

static int edgeSwapTest(GFace *gf, BDS_Edge *e)
{
  BDS_Point *op[2];

  const double THRESH =
    cos(CTX::instance()->mesh.allowSwapEdgeAngle * M_PI / 180.);

  e->oppositeof(op);

  double qa1 = qmTriangle::gamma(e->p1, e->p2, op[0]);
  double qa2 = qmTriangle::gamma(e->p1, e->p2, op[1]);
  double qb1 = qmTriangle::gamma(e->p1, op[0], op[1]);
  double qb2 = qmTriangle::gamma(e->p2, op[0], op[1]);
  double qa = std::min(qa1, qa2);
  double qb = std::min(qb1, qb2);

  //  if(qb > 15*qa) return 1;

  if(!edgeSwapTestAngle(e, THRESH)) return -1;

  if(qb > qa)
    return 1;
  else
    return -1;
}

static void swapEdgePass(GFace *gf, BDS_Mesh &m, int &nb_swap, int FINALIZE = 0,
                         double orientation = 1.0)
{
  BDS_SwapEdgeTest *qual;
  if(FINALIZE && gf->getNativeType() != GEntity::GmshModel)
    qual = new BDS_SwapEdgeTestNormals(gf, orientation);
  else
    qual = new BDS_SwapEdgeTestQuality(true, true);
  //    qual = new BDS_SwapEdgeTestQuality (true,true);
  typedef std::vector<BDS_Edge *>::size_type size_type;
  size_type origSize = m.edges.size();
  for(size_type index = 0; index < 2 * origSize && index < m.edges.size();
      ++index) {
    if(!m.edges.at(index)->deleted && m.edges.at(index)->numfaces() == 2) {
      int const result = FINALIZE ? 1 : edgeSwapTest(gf, m.edges.at(index));
      if(result >= 0) {
        if(m.swap_edge(m.edges.at(index), *qual)) {
          ++nb_swap;
        }
      }
    }
  }
  m.cleanup();
  delete qual;
}

void delaunayizeBDS(GFace *gf, BDS_Mesh &m, int &nb_swap)
{
  typedef std::vector<BDS_Edge *>::size_type size_type;

  nb_swap = 0;
  std::set<swapquad> configs;
  while(1) {
    size_type NSW = 0;

    for(size_type index = 0; index < m.edges.size(); ++index) {
      if(!m.edges.at(index)->deleted) {
        if(edgeSwapTestDelaunayAniso(m.edges.at(index), gf, configs)) {
          if(m.swap_edge(m.edges.at(index), BDS_SwapEdgeTestQuality(false))) {
            ++NSW;
          }
        }
      }
    }
    nb_swap += NSW;
    if(!NSW) return;
  }
}

bool edges_sort(std::pair<double, BDS_Edge *> a,
                std::pair<double, BDS_Edge *> b)
{
  // don't compare pointers: it leads to non-deterministic behavior
  // if (a.first == b.first){
  //   return ((*a.second) < (*b.second));
  // }
  if(std::abs(a.first - b.first) < 1e-10) {
    if(a.second->p1->iD == b.second->p1->iD)
      return (a.second->p2->iD < b.second->p2->iD);
    else
      return (a.second->p1->iD < b.second->p1->iD);
  }
  else
    return (a.first < b.first);
}

static bool middlePoint(GFace *gf, BDS_Edge *e, double &u, double &v)
{
  double u1 = e->p1->u;
  double u2 = e->p2->u;
  double v1 = e->p1->v;
  double v2 = e->p2->v;
  double X1 = e->p1->X;
  double X2 = e->p2->X;
  double Y1 = e->p1->Y;
  double Y2 = e->p2->Y;
  double Z1 = e->p1->Z;
  double Z2 = e->p2->Z;

  int iter = 0;
  while(1) {
    u = 0.5 * (u1 + u2);
    v = 0.5 * (v1 + v2);
    GPoint gpp = gf->point(u, v);
    double X = gpp.x();
    double Y = gpp.y();
    double Z = gpp.z();
    double l1 = std::sqrt((X - X1) * (X - X1) + (Y - Y1) * (Y - Y1) +
                          (Z - Z1) * (Z - Z1));
    double l2 = std::sqrt((X - X2) * (X - X2) + (Y - Y2) * (Y - Y2) +
                          (Z - Z2) * (Z - Z2));
    // 1 ------ p -- 2
    if(l1 > 1.2 * l2) {
      u2 = u;
      v2 = v;
    }
    else if(l2 > 1.2 * l1) {
      u1 = u;
      v1 = v;
    }
    else
      break;
    if(iter++ > 10) {
      u = 0.5 * (e->p1->u + e->p2->u);
      v = 0.5 * (e->p1->v + e->p2->v);
      return false;
    }
  }
  return true;
}

static void splitEdgePass(GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split,
                          std::vector<SPoint2> *true_boundary)
{
  std::vector<std::pair<double, BDS_Edge *> > edges;

  SPoint2 out(10, 10);

  for(std::set<BDS_Point *, PointLessThan>::iterator it = m.points.begin();
      it != m.points.end(); ++it) {
    BDS_Point *p = *it;
    if(!p->_periodicCounterpart && (p->g && p->g->classif_degree == 2)) {
      for(size_t i = 0; i < p->edges.size(); i++) {
        BDS_Point *p1 =
          p->edges[i]->p1 == p ? p->edges[i]->p2 : p->edges[i]->p1;
        for(size_t j = 0; j < i; j++) {
          BDS_Point *p2 =
            p->edges[j]->p1 == p ? p->edges[j]->p2 : p->edges[j]->p1;
          if(!p1->degenerated && !p2->degenerated && p1->_periodicCounterpart &&
             p1->_periodicCounterpart == p2) {
            edges.push_back(std::make_pair(-10.0, p->edges[i]));
            edges.push_back(std::make_pair(-10.0, p->edges[j]));
          }
        }
      }
    }
  }

  std::vector<BDS_Edge *>::const_iterator it = m.edges.begin();
  while(it != m.edges.end()) {
    if(!(*it)->deleted && (*it)->numfaces() == 2 &&
       (*it)->g->classif_degree == 2) {
      double lone = NewGetLc(*it, gf);
      if(lone > MAXE_) edges.push_back(std::make_pair(-lone, *it));
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end(), edges_sort);

  std::vector<BDS_Point *> mids(edges.size());

  bool faceDiscrete = gf->geomType() == GEntity::DiscreteSurface;

  for(unsigned int i = 0; i < edges.size(); ++i) {
    BDS_Edge *e = edges[i].second;
    BDS_Point *mid = NULL;
    if(!e->deleted) {
      double U1 = e->p1->u;
      double U2 = e->p2->u;
      if(e->p1->degenerated) U1 = U2;
      if(e->p2->degenerated) U2 = U1;
      double U = 0.5 * (U1 + U2);
      double V = 0.5 * (e->p1->v + e->p2->v);
      if(faceDiscrete) middlePoint(gf, e, U, V);

      GPoint gpp = gf->point(U, V);
      bool inside = true;
      if(true_boundary) {
        SPoint2 pp(U, V);
        int N;
        if(!pointInsideParametricDomain(*true_boundary, pp, out, N)) {
          inside = false;
          // printf("%d %d %g %g\n",e->p1->iD,e->p2->iD,U1,U2);
          // printf("%g %g OUTSIDE ??\n",pp.x(),pp.y());
          // FILE *f = fopen("TOTO.pos","a");
          // fprintf(f,"SP(%g,%g,0){%d};\n",pp.x(),pp.y(),N);
          // fclose(f);
        }
      }
      if(inside && gpp.succeeded()) {
        mid = m.add_point(++m.MAXPOINTNUMBER, gpp.x(), gpp.y(), gpp.z());
        mid->u = U;
        mid->v = V;
        mid->lc() = 0.5 * (e->p1->lc() + e->p2->lc());
        mid->lcBGM() = BGM_MeshSize(gf, U, V, mid->X, mid->Y, mid->Z);
      }
    }
    mids[i] = mid;
  }

  for(unsigned int i = 0; i < edges.size(); ++i) {
    BDS_Edge *e = edges[i].second;
    if(!e->deleted) {
      BDS_Point *mid = mids[i];
      if(mid) {
        if(!m.split_edge(e, mid))
          m.del_point(mid);
        else {
          nb_split++;
        }
      }
    }
  }
}

double getMaxLcWhenCollapsingEdge(GFace *gf, BDS_Mesh &m, BDS_Edge *e,
                                  BDS_Point *p)
{
  BDS_Point *o = e->othervertex(p);

  double maxLc = 0.0;
  std::vector<BDS_Edge *> edges(p->edges);
  std::vector<BDS_Edge *>::iterator eit = edges.begin();
  while(eit != edges.end()) {
    BDS_Point *newP1 = 0, *newP2 = 0;
    if((*eit)->p1 == p) {
      newP1 = o;
      newP2 = (*eit)->p2;
    }
    else if((*eit)->p2 == p) {
      newP1 = (*eit)->p1;
      newP2 = o;
    }
    if(!newP1 || !newP2) break; // error
    BDS_Edge collapsedEdge = BDS_Edge(newP1, newP2);
    maxLc = std::max(maxLc, NewGetLc(&collapsedEdge, gf));
    newP1->del(&collapsedEdge);
    newP2->del(&collapsedEdge);
    ++eit;
  }

  return maxLc;
}

/*static bool revertTriangleSphere(SPoint3 &center, BDS_Point *p, BDS_Point *o)
{
  std::vector<BDS_Face*> t = p->getTriangles();

  std::vector<BDS_Face*>::const_iterator it = t.begin();
  while(it != t.end()) {
    BDS_Face *t = *it;
    BDS_Point *pts[4];
    t->getNodes(pts);
    pts[0] = (pts[0] == p) ? o : pts[0];
    pts[1] = (pts[1] == p) ? o : pts[1];
    pts[2] = (pts[2] == p) ? o : pts[2];
    double norm[3];
    normal_triangle(pts[0], pts[1], pts[2], norm);
    double dx = center.x() - o->X;
    double dy = center.y() - o->Y;
    double dz = center.z() - o->Z;
    double ps = dx*norm[0]+dy*norm[1]+dz*norm[2];
    if (ps < 0){
      // printf("FLIIIP\n");
      return true;
    }
    ++it;
  }
  return false;
}
*/

void collapseEdgePass(GFace *gf, BDS_Mesh &m, double MINE_, int MAXNP,
                      int &nb_collaps)
{
  //  return;
  std::vector<BDS_Edge *>::const_iterator it = m.edges.begin();
  std::vector<std::pair<double, BDS_Edge *> > edges;

  while(it != m.edges.end()) {
    if(!(*it)->deleted && (*it)->numfaces() == 2 &&
       (*it)->g->classif_degree == 2) {
      double lone = NewGetLc(*it, gf);
      if(lone < MINE_) edges.push_back(std::make_pair(lone, *it));
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end(), edges_sort);

  for(unsigned int i = 0; i < edges.size(); i++) {
    BDS_Edge *e = edges[i].second;
    if(!e->deleted) {
      double lone1 = 0.;
      bool collapseP1Allowed = false;
      //      lone1 = getMaxLcWhenCollapsingEdge(gf, m, e, e->p1);
      collapseP1Allowed =
        true; // std::abs(lone1-1.0) < std::abs(edges[i].first - 1.0);

      double lone2 = 0.;
      bool collapseP2Allowed = false;
      if(e->p2->iD > MAXNP) {
        //        lone2 = getMaxLcWhenCollapsingEdge(gf, m, e, e->p2);
        collapseP2Allowed =
          true; // std::abs(lone2-1.0) < std::abs(edges[i].first - 1.0);
      }

      BDS_Point *p = 0;
      if(collapseP1Allowed && collapseP2Allowed) {
        if(std::abs(lone1 - lone2) < 1e-12)
          p = e->p1->iD < e->p2->iD ? e->p1 : e->p2;
        else
          p = std::abs(lone1 - 1.0) < std::abs(lone2 - 1.0) ? e->p1 : e->p2;
      }
      else if(collapseP1Allowed && !collapseP2Allowed)
        p = e->p1;
      else if(collapseP1Allowed && !collapseP2Allowed)
        p = e->p2;

      bool res = false;
      if(p) res = m.collapse_edge_parametric(e, p);
      if(res) nb_collaps++;
    }
  }
}

void smoothVertexPass(GFace *gf, BDS_Mesh &m, int &nb_smooth, bool q)
{
  // FIXME SUPER HACK
  std::set<BDS_Point *, PointLessThan>::iterator itp = m.points.begin();
  while(itp != m.points.end()) {
    if(m.smooth_point_centroid(*itp, gf, q)) nb_smooth++;
    ++itp;
  }
}

void CHECK_STRANGE(const char *c, BDS_Mesh &m)
{
  return;
#if 0
  int strange = 0;
  for (size_t i=0;i<m.triangles.size();++i){
    BDS_Point *pts[4];
    m.triangles[i]->getNodes(pts);
    double surface_triangle_param(BDS_Point *p1, BDS_Point *p2, BDS_Point *p3);
    if (pts[0]->degenerated+pts[1]->degenerated+pts[2]->degenerated <= 1){
      if (fabs(surface_triangle_param(pts[0],pts[1],pts[2]))<1.e-8){
	strange ++;
      }
    }
  }
  if (strange) printf("strange(%s) = %d\n",c,strange);

  return;
  for (size_t int i=0;i<m.triangles.size();++i){
    BDS_Point *pts[4];
    m.triangles[i]->getNodes(pts);
    if (pts[0] == pts[1] ||
	pts[0] == pts[2] ||
	pts[1] == pts[2]){
      strange ++;
    }
  }

  return;
  strange = 0;
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while (itp != m.points.end()){
    if ((*itp)->g && (*itp)->g->classif_degree == 2){
      std::vector<BDS_Face*> t = (*itp)->getTriangles();
      if (t.size() == 2)strange++;//printf("vertex %d \n",(*itp)->iD);
    }
    ++itp;
  }
  printf("strange(%s) = %d\n",c,strange);
#endif
}

void computeNodalSizes(
  GFace *gf, BDS_Mesh &m,
  std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap)
{
  std::set<BDS_Point *, PointLessThan>::iterator itp = m.points.begin();
  while(itp != m.points.end()) {
    std::vector<BDS_Edge *>::iterator it = (*itp)->edges.begin();
    std::vector<BDS_Edge *>::iterator ite = (*itp)->edges.end();
    double L = 0;
    int ne = 0;
    while(it != ite) {
      double l = (*it)->length();
      if((*it)->g && (*it)->g->classif_degree == 1) {
        L = ne ? std::max(L, l) : l;
        ne++;
      }
      ++it;
    }
    if((*itp)->g && (*itp)->g->classif_tag > 0) {
      if(!ne) L = MAX_LC;
      if(CTX::instance()->mesh.lcFromPoints) (*itp)->lc() = L;
      (*itp)->lcBGM() = L;
    }
    ++itp;
  }
  return;
  {
    std::set<BDS_Point *, PointLessThan>::iterator itp = m.points.begin();
    while(itp != m.points.end()) {
      (*itp)->lc() = MAX_LC;
      ++itp;
    }
    std::vector<BDS_Edge *>::const_iterator it = m.edges.begin();
    while(it != m.edges.end()) {
      bool degenerated = false;

      if(recoverMap) {
        std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp1 =
          recoverMap->find((*it)->p1);
        std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp2 =
          recoverMap->find((*it)->p2);
        if(itp1 != recoverMap->end() && itp2 != recoverMap->end() &&
           itp1->second == itp2->second) {
          degenerated = true;
        }
      }
      if(!degenerated && (*it)->g && (*it)->g->classif_degree == 1) {
        double L = (*it)->length();
        if((*it)->p1->lc() == MAX_LC)
          (*it)->p1->lc() = L;
        else
          (*it)->p1->lc() = std::max(L, (*it)->p1->lc());
        if((*it)->p2->lc() == MAX_LC)
          (*it)->p2->lc() = L;
        else
          (*it)->p2->lc() = std::max(L, (*it)->p2->lc());
      }
      ++it;
    }

    itp = m.points.begin();
    std::vector<BDS_Point *> pts;
    while(itp != m.points.end()) {
      if((*itp)->lc() == MAX_LC) pts.push_back(*itp);
      ++itp;
    }
    int iter = 0;
    while(1) {
      bool allTouched = true;
      for(size_t i = 0; i < pts.size(); i++) {
        std::vector<BDS_Edge *>::const_iterator it = pts[i]->edges.begin();
        std::vector<BDS_Edge *>::const_iterator ite = pts[i]->edges.end();
        while(it != ite) {
          BDS_Point *p = (*it)->othervertex(pts[i]);
          if(p->lc() != MAX_LC) {
            if(pts[i]->lc() == MAX_LC)
              pts[i]->lc() = p->lc();
            else
              pts[i]->lc() = 0.5 * (p->lc() + pts[i]->lc());
          }
          ++it;
        }
        if(pts[i]->lc() == MAX_LC) allTouched = false;
      }
      if(iter++ >= 5 || allTouched) break;
    }
  }
}

void modifyInitialMeshToRemoveDegeneracies(
  GFace *gf, BDS_Mesh &m,
  std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap)
{
  std::set<MVertex *, MVertexLessThanNum> degenerated;
  std::vector<BDS_Edge *> degenerated_edges;
  getDegeneratedVertices(m, recoverMap, degenerated, degenerated_edges);
  for(std::map<BDS_Point *, MVertex *, PointLessThan>::iterator it =
        recoverMap->begin();
      it != recoverMap->end(); ++it) {
    std::set<MVertex *, MVertexLessThanNum>::iterator it2 =
      degenerated.find(it->second);
    if(it2 != degenerated.end()) {
      it->first->degenerated = true;
    }
  }
  for(size_t i = 0; i < degenerated_edges.size(); i++) {
    m.collapse_edge_parametric(degenerated_edges[i], degenerated_edges[i]->p1,
                               true);
    recoverMap->erase(degenerated_edges[i]->p1);
  }
}

void refineMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT,
                   const bool computeNodalSizeField,
                   std::map<MVertex *, BDS_Point *> *recoverMapInv,
                   std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap,
                   std::vector<SPoint2> *true_boundary)
{
  //  return;
  int IT = 0;
  int MAXNP = m.MAXPOINTNUMBER;

  // classify correctly the embedded vertices use a negative model
  // face number to avoid mesh motion
  if(recoverMapInv) {
    std::set<GVertex *> emb_vertx = gf->embeddedVertices();
    std::set<GVertex *>::iterator itvx = emb_vertx.begin();
    while(itvx != emb_vertx.end()) {
      MVertex *v = *((*itvx)->mesh_vertices.begin());
      std::map<MVertex *, BDS_Point *>::iterator itp = recoverMapInv->find(v);
      if(itp != recoverMapInv->end()) {
        BDS_Point *p = itp->second;
        m.add_geom(-1, 2);
        p->g = m.get_geom(-1, 2);
        ++itvx;
      }
    }
  }

  //  if (recoverMap)outputScalarField(m.triangles, "init.pos", 1, gf);

  // If asked, compute nodal size field using 1D Mesh
  if(computeNodalSizeField) computeNodalSizes(gf, m, recoverMap);

  double t_spl = 0, t_sw = 0, t_col = 0, t_sm = 0;

  const double MINE_ = 0.7, MAXE_ = 1.4;

  while(1) {
    CHECK_STRANGE("start", m);

    // we count the number of local mesh modifs.
    int nb_split = 0;
    int nb_smooth = 0;
    int nb_collaps = 0;
    int nb_swap = 0;

    // split long edges
    double minL = 1.e22, maxL = 0;
    int NN1 = m.edges.size();
    int NN2 = 0;
    std::vector<BDS_Edge *>::iterator it = m.edges.begin();

    while(1) {
      if(NN2++ >= NN1) break;
      if(!(*it)->deleted) {
        (*it)->p1->config_modified = false;
        (*it)->p2->config_modified = false;
        double lone = NewGetLc(*it, gf);
        maxL = std::max(maxL, lone);
        minL = std::min(minL, lone);
      }
      ++it;
    }

    if((minL > MINE_ && maxL < MAXE_) || IT > (abs(NIT))) break;
    double maxE = MAXE_;
    double minE = MINE_;
    double t1 = Cpu();
    // outputScalarField(m.triangles, "0.pos", 1, gf);
    splitEdgePass(gf, m, maxE, nb_split, true_boundary);
    // outputScalarField(m.triangles, "a.pos", 1, gf);
    CHECK_STRANGE("split", m);

    double t2 = Cpu();
    swapEdgePass(gf, m, nb_swap);
    CHECK_STRANGE("swap", m);
    // outputScalarField(m.triangles, "b.pos", 1, gf);

    double t3 = Cpu();
    collapseEdgePass(gf, m, minE, MAXNP, nb_collaps);
    CHECK_STRANGE("collapse", m);
    // outputScalarField(m.triangles, "c.pos", 1, gf);
    double t4 = Cpu();
    swapEdgePass(gf, m, nb_swap);
    CHECK_STRANGE("swap", m);
    double t5 = Cpu();
    smoothVertexPass(gf, m, nb_smooth, false);
    double t6 = Cpu();
    CHECK_STRANGE("smmooth", m);
    swapEdgePass(gf, m, nb_swap);
    CHECK_STRANGE("swap", m);
    double t7 = Cpu();
    // char name[256]; sprintf(name,"iter%d.pos",IT);
    // outputScalarField(m.triangles, name, 1, gf);
    // getchar();

    // clean up the mesh
    t_spl += t2 - t1;
    t_sw += t3 - t2;
    t_sw += t5 - t4;
    t_sw += t7 - t6;
    t_col += t4 - t3;
    t_sm += t6 - t5;
    m.cleanup();
    // char nn[256];
    // sprintf(nn,"ITER%d.pos",IT);
    // outputScalarField(m.triangles, nn, 1, gf);
    // getchar();

    IT++;
    Msg::Debug(" iter %3d minL %8.3f/%8.3f maxL %8.3f/%8.3f : "
               "%6d splits, %6d swaps, %6d collapses, %6d moves",
               IT, minL, minE, maxL, maxE, nb_split, nb_swap, nb_collaps,
               nb_smooth);
    // getchar();
    if(nb_split == 0 && nb_collaps == 0) break;
  }

  // outputScalarField(m.triangles, "before.pos", 1, gf);

  int ITER = 0;
  int bad = 0;
  int invalid = 0;

  if(gf->getNativeType() != GEntity::GmshModel) {
    for(size_t i = 0; i < m.triangles.size(); i++) {
      BDS_Point *pts[4];
      m.triangles[i]->getNodes(pts);
      double val = BDS_Face_Validity(gf, m.triangles[i]);
      invalid += val < 0 ? 1 : 0;
    }
    double orientation = invalid > (int)m.triangles.size() / 2 ? -1.0 : 1.0;

    // printf("NOW FIXING BAD ELEMENTS\n");

    while(1) {
      // printf("ITERATION %d\n",ITER);
      bad = 0;
      invalid = 0;
      for(size_t i = 0; i < m.triangles.size(); i++) {
        if(!m.triangles[i]->deleted) {
          BDS_Point *pts[4];
          m.triangles[i]->getNodes(pts);
          pts[0]->config_modified = false;
          pts[1]->config_modified = false;
          pts[2]->config_modified = false;
        }
      }
      for(size_t i = 0; i < m.triangles.size(); i++) {
        BDS_Point *pts[4];
        m.triangles[i]->getNodes(pts);
        // if (pts[0]->degenerated + pts[1]->degenerated + pts[2]->degenerated < 2){
        double val = orientation * BDS_Face_Validity(gf, m.triangles[i]);
        if(val <= 0.2) {
          if(!m.triangles[i]->deleted && val <= 0) invalid++;
          pts[0]->config_modified = true;
          pts[1]->config_modified = true;
          pts[2]->config_modified = true;
          bad++;
          if(val < 0) {
            // printf("%d %d %d invalid\n",pts[0]->iD,pts[1]->iD,pts[2]->iD);
            invalid++;
          }
        }
        // }
      }
      if(++ITER == 10) {
        if(invalid && !computeNodalSizeField)
          Msg::Warning("Meshing surface %d : %d elements remain invalid\n",
                       gf->tag(), invalid);
        break;
      }

      if(bad != 0) {
        int nb_swap = 0;
        // int nb_smooth = 0;
        swapEdgePass(gf, m, nb_swap, 1, orientation);
        // smoothVertexPass(gf, m, nb_smooth, true);
      }
      else {
        // Msg::Info("Meshing surface %d : all elements are oriented
        //            properly\n", gf->tag());
        break;
      }
    }
  }
  //  printf("NITER %d \n",ITER);
  //  outputScalarField(m.triangles, "after.pos", 1, gf);
  //  getchar();
  //  for (size_t i=0;i<m.edges.size();i++){
  //    if (!m.edges[i]->deleted){
  //      m.edges[i]->p1->config_modified = true;
  //      m.edges[i]->p2->config_modified = true;
  //    }
  //  }

  // Remove all small edges ...
  //  int  nb_collaps, nb_swap, nb_smooth;
  //  collapseEdgePass(gf, m, MINE_, MAXNP, nb_collaps);
  //  collapseEdgePass(gf, m, MINE_, MAXNP, nb_collaps);
  //  swapEdgePass ( gf, m, nb_swap, 1);
  //  swapEdgePass ( gf, m, nb_swap, 1);
  //  swapEdgePass ( gf, m, nb_swap);
  //  swapEdgePass ( gf, m, nb_swap);

  double t_total = t_spl + t_sw + t_col + t_sm;
  if(!t_total) t_total = 1.e-6;
  Msg::Debug(" ---------------------------------------");
  Msg::Debug(" CPU Report ");
  Msg::Debug(" ---------------------------------------");
  Msg::Debug(" CPU SWAP    %12.5E sec (%3.0f %%)", t_sw, 100 * t_sw / t_total);
  Msg::Debug(" CPU SPLIT   %12.5E sec (%3.0f %%) ", t_spl,
             100 * t_spl / t_total);
  Msg::Debug(" CPU COLLAPS %12.5E sec (%3.0f %%) ", t_col,
             100 * t_col / t_total);
  Msg::Debug(" CPU SMOOTH  %12.5E sec (%3.0f %%) ", t_sm, 100 * t_sm / t_total);
  Msg::Debug(" ---------------------------------------");
  Msg::Debug(" CPU TOTAL   %12.5E sec ", t_total);
  Msg::Debug(" ---------------------------------------");
}

bool degeneratedTriangle(
  BDS_Face *f, std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap)
{
  MVertex *v[3] = {0, 0, 0};
  BDS_Point *n[4];
  f->getNodes(n);
  for(int i = 0; i < 3; i++) {
    std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp1 =
      recoverMap->find(n[i]);
    if(itp1 != recoverMap->end()) v[i] = itp1->second;
  }
  if(v[0] && (v[0] == v[1] || v[0] == v[2])) return true;
  if(v[1] && (v[1] == v[2] || v[0] == v[1])) return true;
  if(v[2] && (v[1] == v[2] || v[0] == v[2])) return true;
  return false;
}

void invalidEdgesPeriodic(
  BDS_Mesh &m, std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap,
  std::set<BDS_Edge *, EdgeLessThan> &toSplit)
{
  // first look for degenerated vertices
  std::set<MVertex *, MVertexLessThanNum> degenerated;
  std::vector<BDS_Edge *> degenerated_edges;
  getDegeneratedVertices(m, recoverMap, degenerated, degenerated_edges);
  Msg::Debug("Found %d degenerated vertices", degenerated.size());

  toSplit.clear();
  std::vector<BDS_Edge *>::const_iterator it = m.edges.begin();
  std::map<std::pair<MVertex *, BDS_Point *>, BDS_Edge *> touchPeriodic;
  while(it != m.edges.end()) {
    BDS_Edge *e = *it;
    if(!e->deleted && e->numfaces() == 2) {
      std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp1 =
        recoverMap->find(e->p1);
      std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp2 =
        recoverMap->find(e->p2);
      if(itp1 != recoverMap->end() && itp2 != recoverMap->end() &&
         itp1->second == itp2->second)
        toSplit.insert(e);
      else if(itp1 != recoverMap->end() && itp2 == recoverMap->end()) {
        std::pair<MVertex *, BDS_Point *> a(itp1->second, e->p2);
        std::map<std::pair<MVertex *, BDS_Point *>, BDS_Edge *>::iterator itf =
          touchPeriodic.find(a);
        if(itf == touchPeriodic.end())
          touchPeriodic[a] = e;
        else if(degenerated.find(itp1->second) == degenerated.end()) {
          toSplit.insert(e);
          toSplit.insert(itf->second);
        }
      }
      else if(itp1 == recoverMap->end() && itp2 != recoverMap->end()) {
        std::pair<MVertex *, BDS_Point *> a(itp2->second, e->p1);
        std::map<std::pair<MVertex *, BDS_Point *>, BDS_Edge *>::iterator itf =
          touchPeriodic.find(a);
        if(itf == touchPeriodic.end())
          touchPeriodic[a] = e;
        else if(degenerated.find(itp2->second) == degenerated.end()) {
          toSplit.insert(e);
          toSplit.insert(itf->second);
        }
      }
    }
    ++it;
  }
  // return;
  Msg::Debug("%d degenerated edges should be split", toSplit.size());
  size_t aa = toSplit.size();
  // same edges should be split
  {
    std::set<BDS_Point *, PointLessThan>::iterator it = m.points.begin();
    while(it != m.points.end()) {
      std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp2 =
        recoverMap->find(*it);
      if(itp2 == recoverMap->end()) {
        std::vector<BDS_Edge *>::const_iterator ite = (*it)->edges.begin();
        std::map<MVertex *, BDS_Edge *> mp;
        while(ite != (*it)->edges.end()) {
          if(!(*ite)->deleted && (*ite)->numfaces() == 2) {
            if(!degeneratedTriangle((*ite)->faces(0), recoverMap) &&
               !degeneratedTriangle((*ite)->faces(1), recoverMap)) {
              BDS_Point *other = (*it) == (*ite)->p1 ? (*ite)->p2 : (*ite)->p1;
              std::map<BDS_Point *, MVertex *, PointLessThan>::iterator itp1 =
                recoverMap->find(other);
              if(itp1 != recoverMap->end()) {
                if(mp.find(itp1->second) != mp.end()) {
                  toSplit.insert(*ite);
                  toSplit.insert(mp[itp1->second]);
                }
                mp[itp1->second] = *ite;
              }
            }
          }
          ++ite;
        }
      }
      ++it;
    }
  }
  Msg::Debug("%d similar edges should be split", toSplit.size() - aa);
}

// consider p1 and p2, 2 vertices that are different in the parametric
// plane BUT are the same in the real plane
// consider a vertex v that is internal
// if p1 is the start and the end of a degenerated edge, then allow edges p1 v
// and p2 v if not do not allow p1 v and p2 v, split them if p1 p2 exists and it
// is internal, split it

int solveInvalidPeriodic(
  GFace *gf, BDS_Mesh &m,
  std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap)
{
  if(!recoverMap) return 0;

  BDS_GeomEntity *g = m.get_geom(gf->tag(), 2);

  //  return 0;
  Msg::Debug(
    "Solving invalid edges/triangles in initial meshes of periodic face %d",
    gf->tag());

  std::set<BDS_Edge *, EdgeLessThan> toSplit;
  invalidEdgesPeriodic(m, recoverMap, toSplit);
  std::set<BDS_Edge *>::iterator ite = toSplit.begin();

  Msg::Debug("%d edges of the initial mesh are going to be split",
             toSplit.size());

  for(; ite != toSplit.end(); ++ite) {
    BDS_Edge *e = *ite;
    if(!e->deleted && e->numfaces() == 2) {
      const double coord = 0.5;
      BDS_Point *mid;
      mid = m.add_point(++m.MAXPOINTNUMBER,
                        coord * e->p1->u + (1 - coord) * e->p2->u,
                        coord * e->p1->v + (1 - coord) * e->p2->v, gf);
      mid->lcBGM() = BGM_MeshSize(
        gf, (coord * e->p1->u + (1 - coord) * e->p2->u),
        (coord * e->p1->v + (1 - coord) * e->p2->v), mid->X, mid->Y, mid->Z);
      mid->lc() = 0.5 * (e->p1->lc() + e->p2->lc());
      mid->u = coord * e->p1->u + (1 - coord) * e->p2->u;
      mid->v = coord * e->p1->v + (1 - coord) * e->p2->v;
      mid->g = g;

      if(!m.split_edge(e, mid)) m.del_point(mid);
    }
  }
  //  int nb_smooth;
  //  if(toSplit.size()) smoothVertexPass(gf, m, nb_smooth, true);
  m.cleanup();
  return toSplit.size();
}

void optimizeMeshBDS(
  GFace *gf, BDS_Mesh &m, const int NIT,
  std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap = 0)
{
  return;
}

// DELAUNAY BDS

// build the BDS from a list of GFace
// This is a TRUE copy
BDS_Mesh *gmsh2BDS(std::list<GFace *> &l)
{
  BDS_Mesh *m = new BDS_Mesh;
  for(std::list<GFace *>::iterator it = l.begin(); it != l.end(); ++it) {
    GFace *gf = *it;
    m->add_geom(gf->tag(), 2);
    BDS_GeomEntity *g2 = m->get_geom(gf->tag(), 2);
    for(unsigned int i = 0; i < gf->triangles.size(); i++) {
      MTriangle *e = gf->triangles[i];
      BDS_Point *p[3];
      for(int j = 0; j < 3; j++) {
        p[j] = m->find_point(e->getVertex(j)->getNum());
        if(!p[j]) {
          p[j] = m->add_point(e->getVertex(j)->getNum(), e->getVertex(j)->x(),
                              e->getVertex(j)->y(), e->getVertex(j)->z());
          SPoint2 param;
          reparamMeshVertexOnFace(e->getVertex(j), gf, param);
          p[j]->u = param[0];
          p[j]->v = param[1];
          m->add_geom(e->getVertex(j)->onWhat()->tag(),
                      e->getVertex(j)->onWhat()->dim());
          BDS_GeomEntity *g = m->get_geom(e->getVertex(j)->onWhat()->tag(),
                                          e->getVertex(j)->onWhat()->dim());
          p[j]->g = g;
        }
      }
      BDS_Face *f = m->add_triangle(p[0]->iD, p[1]->iD, p[2]->iD);
      f->g = g2;
    }
  }
  return m;
}
