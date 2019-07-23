// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <stdlib.h>
#include "GmshMessage.h"
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
#include "robustPredicates.h"

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
        degenerated_edges.push_back(e);
      }
    }
    ++it;
  }
}

static double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->X - p2->X;
  const double dy = p1->Y - p2->Y;
  const double dz = p1->Z - p2->Z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

static inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2,
                                             GFace *f)
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

static double computeEdgeLinearLength(BDS_Edge *e, GFace *f)
{
  // FIXME !!!
  return f->geomType() == GEntity::Plane ?
           e->length() :
           computeEdgeLinearLength(e->p1, e->p2, f);
}

static double NewGetLc(BDS_Point *point)
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

static double NewGetLc(BDS_Edge *const edge, GFace *const face)
{
  return computeEdgeLinearLength(edge, face) /
         correctLC_(edge->p1, edge->p2, face);
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

static bool neighboringModified(BDS_Point *p)
{
  if(p->config_modified) return true;
  std::vector<BDS_Edge *>::iterator it = p->edges.begin();
  std::vector<BDS_Edge *>::iterator ite = p->edges.end();
  while(it != ite) {
    BDS_Point *o = (*it)->othervertex(p);
    if(o->config_modified) return true;
    ++it;
  }
  return false;
}

static void swapEdgePass(GFace *gf, BDS_Mesh &m, int &nb_swap, double &t,
                         int FINALIZE = 0, double orientation = 1.0)
{
  double t1 = Cpu();
  BDS_SwapEdgeTest *qual;
  if(FINALIZE && gf->getNativeType() != GEntity::GmshModel)
    qual = new BDS_SwapEdgeTestNormals(gf, orientation);
  else
    qual = new BDS_SwapEdgeTestQuality(true, true);

  typedef std::vector<BDS_Edge *>::size_type size_type;
  size_type origSize = m.edges.size();
  for(size_type index = 0; index < 2 * origSize && index < m.edges.size();
      ++index) {
    if(neighboringModified(m.edges.at(index)->p1) ||
       neighboringModified(m.edges.at(index)->p2)) {
      if(!m.edges.at(index)->deleted && m.edges.at(index)->numfaces() == 2) {
        int const result = FINALIZE ? 1 : edgeSwapTest(gf, m.edges.at(index));
        if(result >= 0) {
          if(m.swap_edge(m.edges.at(index), *qual)) { ++nb_swap; }
        }
      }
    }
  }
  m.cleanup();
  delete qual;
  t += (Cpu() - t1);
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
  if(!inCircumCircleAniso(gf, p1, p2, p3, p4, metric)) { return false; }
  return true;
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

static bool edges_sort(std::pair<double, BDS_Edge *> a,
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

  SPoint3 pp(0.5 * (X1 + X2), 0.5 * (Y1 + Y2), 0.5 * (Z1 + Z2));
  double guess[2] = {0.5 * (u1 + u2), 0.5 * (v1 + v2)};
  GPoint gp = gf->closestPoint(pp, guess);
  if(0 && gp.succeeded()) {
    SPoint3 XX1(X1, Y1, Z1);
    SPoint3 XX2(X2, Y2, Z2);
    SPoint3 MID = (XX1 + XX2) * 0.5;
    SPoint3 PRJ(gp.x(), gp.y(), gp.z());
    ;
    double d1 = PRJ.distance(MID);
    double d2 = XX1.distance(XX2);
    // projection is close to mid...
    if(d1 < .3 * d2) {
      BDS_Point *op[2];
      BDS_Point *p1 = e->p1;
      BDS_Point *p2 = e->p2;
      e->oppositeof(op);
      double _p1[2] = {p1->u, p1->v};
      double _p2[2] = {p2->u, p2->v};
      double _op1[2] = {op[0]->u, op[0]->v};
      double _op2[2] = {op[1]->u, op[1]->v};
      double _ss[2] = {gp.u(), gp.v()};
      double oris_[4] = {robustPredicates::orient2d(_p1, _op2, _ss),
                         robustPredicates::orient2d(_op2, _p2, _ss),
                         robustPredicates::orient2d(_p2, _op1, _ss),
                         robustPredicates::orient2d(_op1, _p1, _ss)};
      if(oris_[0] * oris_[1] > 0 && oris_[0] * oris_[2] > 0 &&
         oris_[0] * oris_[3] > 0 && oris_[1] * oris_[2] > 0 &&
         oris_[1] * oris_[3] > 0 && oris_[2] * oris_[3] > 0) {
        u = gp.u();
        v = gp.v();
        return true;
      }
    }
  }

  int iter = 0;
  while(1) {
    u = 0.5 * (u1 + u2);
    v = 0.5 * (v1 + v2);
    GPoint gpp = gf->point(u, v);
    if(gpp.succeeded()) {
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
    }
    if(iter++ > 4) {
      u = 0.5 * (e->p1->u + e->p2->u);
      v = 0.5 * (e->p1->v + e->p2->v);
      return false;
    }
  }
  return true;
}

// create a valid initial mesh when degeneracies are present

static void getDegeneracy(BDS_Mesh &m, std::vector<BDS_Point *> &deg)
{
  deg.clear();
  std::set<BDS_Point *, PointLessThan>::iterator itp = m.points.begin();
  while(itp != m.points.end()) {
    if((*itp)->degenerated) deg.push_back(*itp);
    itp++;
  }
}

static void setDegeneracy(std::vector<BDS_Point *> &deg, short d)
{
  for(size_t i = 0; i < deg.size(); i++) deg[i]->degenerated = d;
}

static int validitiyOfGeodesics(GFace *gf, BDS_Mesh &m)
{
  std::vector<BDS_Edge *> degenerated;
  for(size_t i = 0; i < m.edges.size(); i++) {
    BDS_Edge *e = m.edges[i];
    if(!e->deleted && ((!e->p1->degenerated && e->p2->degenerated) ||
                       (e->p1->degenerated && !e->p2->degenerated)))
      degenerated.push_back(e);
  }
  std::vector<BDS_Edge *> toSplit;
  for(size_t i = 0; i < degenerated.size(); i++) {
    BDS_Edge *ed = degenerated[i];
    double u3[2] = {ed->p1->degenerated == 1 ? ed->p2->u : ed->p1->u,
                    ed->p1->degenerated == 2 ? ed->p2->v : ed->p1->v};
    double u4[2] = {ed->p2->degenerated == 1 ? ed->p1->u : ed->p2->u,
                    ed->p2->degenerated == 2 ? ed->p1->v : ed->p2->v};
    for(size_t j = 0; j < m.edges.size(); j++) {
      BDS_Edge *e = m.edges[j];
      if(e->deleted || e->p1 == ed->p1 || e->p1 == ed->p2 || e->p2 == ed->p1 ||
         e->p2 == ed->p2)
        continue;
      if(e->p1->degenerated + e->p2->degenerated == 0) {
        double u1[2] = {e->p1->u, e->p1->v};
        double u2[2] = {e->p2->u, e->p2->v};
        double rp1 = robustPredicates::orient2d(u1, u2, u3);
        double rp2 = robustPredicates::orient2d(u1, u2, u4);
        double rq1 = robustPredicates::orient2d(u3, u4, u1);
        double rq2 = robustPredicates::orient2d(u3, u4, u2);
        if(rp1 * rp2 < 0 && rq1 * rq2 < 0) {
          toSplit.push_back(ed);
          break;
        }
      }
    }
  }
  return toSplit.size();
}

static void splitEdgePass(GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split,
                          std::vector<SPoint2> *true_boundary, double &t)
{
  double t1 = Cpu();
  std::vector<std::pair<double, BDS_Edge *> > edges;

  SPoint2 out(10.21982512, 10.8635436432);

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
    if(!(*it)->deleted && (*it)->numfaces() == 2 && (*it)->g &&
       (*it)->g->classif_degree == 2) {
      double lone = NewGetLc(*it, gf);
      if(lone > MAXE_) edges.push_back(std::make_pair(-lone, *it));
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end(), edges_sort);

  std::vector<BDS_Point *> mids(edges.size());

  bool faceDiscrete = gf->geomType() == GEntity::DiscreteSurface;

  for(std::size_t i = 0; i < edges.size(); ++i) {
    BDS_Edge *e = edges[i].second;
    BDS_Point *mid = NULL;
    if(!e->deleted &&
       (neighboringModified(e->p1) || neighboringModified(e->p2))) {
      double U1 = e->p1->u;
      double U2 = e->p2->u;
      double V1 = e->p1->v;
      double V2 = e->p2->v;
      if(e->p1->degenerated == 1) U1 = U2;
      if(e->p2->degenerated == 1) U2 = U1;
      if(e->p1->degenerated == 2) V1 = V2;
      if(e->p2->degenerated == 2) V2 = V1;
      double U = 0.5 * (U1 + U2);
      double V = 0.5 * (V1 + V2);
      if(faceDiscrete)
        if(!middlePoint(gf, e, U, V)) continue;

      GPoint gpp = gf->point(U, V);
      bool inside = true;
      if(true_boundary) {
        SPoint2 pp(U, V);
        int N;
        if(!pointInsideParametricDomain(*true_boundary, pp, out, N)) {
          inside = false;
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

  for(std::size_t i = 0; i < edges.size(); ++i) {
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
  t += (Cpu() - t1);
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

void collapseEdgePass(GFace *gf, BDS_Mesh &m, double MINE_, int MAXNP,
                      int &nb_collaps, double &t)
{
  double t1 = Cpu();
  std::vector<BDS_Edge *>::const_iterator it = m.edges.begin();
  std::vector<std::pair<double, BDS_Edge *> > edges;

  while(it != m.edges.end()) {
    if(!(*it)->deleted && (*it)->numfaces() == 2 && (*it)->g &&
       (*it)->g->classif_degree == 2) {
      double lone = NewGetLc(*it, gf);
      if(lone < MINE_) edges.push_back(std::make_pair(lone, *it));
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end(), edges_sort);

  int count = 0;
  double mink = MINE_;
  for(std::size_t i = 0; i < edges.size(); i++) {
    BDS_Edge *e = edges[i].second;
    if(!e->deleted &&
       (neighboringModified(e->p1) || neighboringModified(e->p2))) {
      count++;
      double lone1 = 0.;
      bool collapseP1Allowed = true;

      double lone2 = 0.;
      bool collapseP2Allowed = false;
      if(e->p2->iD > MAXNP) {
        // lone2 = getMaxLcWhenCollapsingEdge(gf, m, e, e->p2);
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
      if(p) {
        res = m.collapse_edge_parametric(e, p);
        if(!res && collapseP1Allowed && collapseP2Allowed) {
          res = m.collapse_edge_parametric(e, p == e->p1 ? e->p2 : e->p1);
        }
      }
      if(res)
        nb_collaps++;
      else if(!e->p1->degenerated || !e->p2->degenerated)
        mink = std::min(mink, edges[i].first);
    }
  }
  t += (Cpu() - t1);
}

void smoothVertexPass(GFace *gf, BDS_Mesh &m, int &nb_smooth, bool q,
                      double threshold, double &t)
{
  double t1 = Cpu();
  for(int i = 0; i < 1; i++) {
    std::set<BDS_Point *, PointLessThan>::iterator itp = m.points.begin();
    while(itp != m.points.end()) {
      if(neighboringModified(*itp)) {
        // if ((*itp)->iD ==  616){
        //  outputScalarField(m.triangles, "BEF.pos", 1, gf);
        // }
        if(m.smooth_point_centroid(*itp, gf, threshold)) nb_smooth++;
        // if ((*itp)->iD ==  616){
        //   outputScalarField(m.triangles, "AFT.pos", 1, gf);
        //   getchar();
        // }
      }
      ++itp;
    }
  }
  t += (Cpu() - t1);
}

static void
computeNodalSizes(GFace *gf, BDS_Mesh &m,
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
      for(size_t K = 0; K < degenerated_edges.size(); K++) {
        if(degenerated_edges[K]->p1 == it->first ||
           degenerated_edges[K]->p2 == it->first) {
          if(degenerated_edges[K]->p1->u == degenerated_edges[K]->p2->u) {
            Msg::Debug("Degenerated edge on u = cst axis: treated as well now!");
            it->first->degenerated = 2;
          }
          else {
            it->first->degenerated = 1;
          }
        }
      }
    }
  }
  for(size_t i = 0; i < degenerated_edges.size(); i++) {
    m.collapse_edge_parametric(degenerated_edges[i], degenerated_edges[i]->p1,
                               true);
    recoverMap->erase(degenerated_edges[i]->p1);
  }
}

//#define superdebug 1

void refineMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT,
                   const bool computeNodalSizeField,
                   std::map<MVertex *, BDS_Point *> *recoverMapInv,
                   std::map<BDS_Point *, MVertex *, PointLessThan> *recoverMap,
                   std::vector<SPoint2> *true_boundary)
{
  //  getchar();
  //  return;
  int IT = 0;
  int MAXNP = m.MAXPOINTNUMBER;

  // classify correctly the embedded vertices use a negative model
  // face number to avoid mesh motion
  if(recoverMapInv) {
    std::vector<GVertex *> emb_vertx = gf->getEmbeddedVertices();
    std::vector<GVertex *>::iterator itvx = emb_vertx.begin();
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

  {
    std::vector<BDS_Edge *>::iterator it = m.edges.begin();
    while(it != m.edges.end()) {
      if(!(*it)->deleted) {
        (*it)->p1->config_modified = true;
        (*it)->p2->config_modified = true;
      }
      ++it;
    }
  }

  std::vector<BDS_Point *> deg;
  getDegeneracy(m, deg);
  short degType = 1;
  if(deg.size()) degType = deg[0]->degenerated;
  //  printf("%d degenerate points\n",deg.size());
  int nbSplit = 1;
  while(1) {
    if(nbSplit) nbSplit = validitiyOfGeodesics(gf, m);

    if(nbSplit) {
      Msg::Info(
        "Splits are now done to allow geodesics close to singular points");
      setDegeneracy(deg, degType);
    }
    else
      setDegeneracy(deg, degType);

    // we count the number of local mesh modifs.
    int nb_split = 0;
    int nb_smooth = 0;
    int nb_collaps = 0;
    int nb_swap = 0;

    // split long edges

    double maxE = MAXE_;
    double minE = MINE_;
    // outputScalarField(m.triangles, "initial.pos", 1, gf);
    // getchar();
    splitEdgePass(gf, m, maxE, nb_split, true_boundary, t_spl);
    if(IT == 0) {
#ifdef superdebug
      outputScalarField(m.triangles, "split0.pos", 1, gf);
#endif
      splitEdgePass(gf, m, maxE, nb_split, true_boundary, t_spl);
    }
#ifdef superdebug
    outputScalarField(m.triangles, "split0.pos", 0, gf);
    outputScalarField(m.triangles, "split1.pos", 1, gf);
#endif
    smoothVertexPass(gf, m, nb_smooth, false, .5, t_sm);
#ifdef superdebug
    outputScalarField(m.triangles, "splitsmooth0.pos", 0, gf);
    outputScalarField(m.triangles, "splitsmooth1.pos", 1, gf);
#endif

    swapEdgePass(gf, m, nb_swap, t_sw);
    smoothVertexPass(gf, m, nb_smooth, false, .5, t_sm);

#ifdef superdebug
    outputScalarField(m.triangles, "swapsmooth1.pos", 1, gf);
    outputScalarField(m.triangles, "swapsmooth0.pos", 0, gf);
#endif

    collapseEdgePass(gf, m, minE, MAXNP, nb_collaps, t_col);
#ifdef superdebug
    outputScalarField(m.triangles, "collapse0.pos", 0, gf);
    outputScalarField(m.triangles, "collapse1.pos", 1, gf);
#endif
    smoothVertexPass(gf, m, nb_smooth, false, .5, t_sm);
#ifdef superdebug
    outputScalarField(m.triangles, "collapsemooth.pos", 1, gf);
#endif

    swapEdgePass(gf, m, nb_swap, t_sw);
#ifdef superdebug
    outputScalarField(m.triangles, "d1.pos", 1, gf);
#endif
    smoothVertexPass(gf, m, nb_smooth, false, .5, t_sm);
#ifdef superdebug
    outputScalarField(m.triangles, "temp0.pos", 0, gf);
    outputScalarField(m.triangles, "temp1.pos", 1, gf);
    printf("IN FULL DEBUG MODE AT ITER %d/%d : press enter\n", IT, NIT);
    getchar();
    printf("THANKS .. continuing\n");
#endif

    // remove small edges
    if(IT == abs(NIT)) {
      collapseEdgePass(gf, m, .45, MAXNP, nb_collaps, t_col);
      smoothVertexPass(gf, m, nb_smooth, false, .5, t_sm);
    }

    // CHECK_STRANGE("smmooth", m);

    m.cleanup();

    double minL = 1.e22, maxL = 0;
    std::vector<BDS_Edge *>::iterator it = m.edges.begin();
    int LARGE = 0, SMALL = 0, TOTAL = 0;
    while(it != m.edges.end()) {
      if(!(*it)->deleted) {
        double lone =
          2 * (*it)->length() / (NewGetLc((*it)->p1) + NewGetLc((*it)->p2));
        if(lone > maxE) LARGE++;
        if(lone < minE) SMALL++;
        TOTAL++;
        maxL = std::max(maxL, lone);
        minL = std::min(minL, lone);
      }
      ++it;
    }
    if((minL > MINE_ && maxL < MAXE_) || IT > (abs(NIT))) break;

    IT++;
    Msg::Debug(" iter %3d minL %8.3f/%8.3f maxL %8.3f/%8.3f -- "
               "Small/Large/Total (%6d/%6d/%6d): "
               "%6d splits, %6d swaps, %6d collapses, %6d moves",
               IT, minL, minE, maxL, maxE, SMALL, LARGE, TOTAL, nb_split,
               nb_swap, nb_collaps, nb_smooth);
    // getchar();
    if(nb_split == 0 && nb_collaps == 0) break;
  }

#ifdef superdebug
  printf("FULL DEBUG MODE : cleaning bad triangles\n");
  outputScalarField(m.triangles, "before0.pos", 0, gf);
  outputScalarField(m.triangles, "before1.pos", 1, gf);
#endif

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

#ifdef superdebug
    printf("NOW FIXING BAD ELEMENTS\n");
#endif

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
        // if (pts[0]->degenerated + pts[1]->degenerated + pts[2]->degenerated <
        // 2){
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
        if(invalid && !computeNodalSizeField) {
          gf->meshStatistics.status = GFace::FAILED;
          Msg::Warning("Meshing surface %d : %d elements remain invalid",
                       gf->tag(), invalid);
        }
        break;
      }

      if(bad != 0) {
        int nb_swap = 0;
        int nb_smooth = 0;
        swapEdgePass(gf, m, nb_swap, t_sw, 1, orientation);
        smoothVertexPass(gf, m, nb_smooth, true, .5, t_sm);
      }
      else {
        // Msg::Info("Meshing surface %d : all elements are oriented
        //            properly\n", gf->tag());
        break;
      }
    }
  }

  setDegeneracy(deg, degType);

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
