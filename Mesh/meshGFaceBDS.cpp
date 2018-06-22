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


void getDegeneratedVertices (BDS_Mesh &m,
			     std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap,
			     std::set<MVertex *, MVertexLessThanNum> &degenerated){
  degenerated.clear();
  
  std::list<BDS_Edge*>::iterator it = m.edges.begin();

  while (it != m.edges.end()){
    BDS_Edge *e = *it;
    if (!e->deleted && e->numfaces() == 1){
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp1 = recoverMap->find(e->p1);
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp2 = recoverMap->find(e->p2);
      if (itp1 != recoverMap->end() && itp2 != recoverMap->end() &&
          itp1->second == itp2->second){
        degenerated.insert(itp1->second);
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
  const double l = sqrt(dx * dx + dy * dy + dz * dz);
  return l;
}

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2, GFace *f)
{
  GPoint GP = f->point(SPoint2(0.5 * (p1->u + p2->u),
                               0.5 * (p1->v + p2->v)));

  if (!GP.succeeded())
    return computeEdgeLinearLength(p1,p2);

  const double dx1 = p1->X - GP.x();
  const double dy1 = p1->Y - GP.y();
  const double dz1 = p1->Z - GP.z();
  const double l1 = sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
  const double dx2 = p2->X - GP.x();
  const double dy2 = p2->Y - GP.y();
  const double dz2 = p2->Z - GP.z();
  const double l2 = sqrt(dx2 * dx2 + dy2 * dy2 + dz2 * dz2);
  return l1 + l2;
}

inline double computeEdgeLinearLength(BDS_Edge *e, GFace *f)
{
  // FIXME !!!
  if (f->geomType() == GEntity::Plane)
    return e->length();
  else
    return computeEdgeLinearLength(e->p1, e->p2, f);
}

double NewGetLc(BDS_Point *p)
{

  return Extend1dMeshIn2dSurfaces() ?
    std::min(p->lc(), p->lcBGM()) : p->lcBGM();
}

static double correctLC_(BDS_Point *p1,BDS_Point *p2, GFace *f)
{
  double l1 = NewGetLc(p1);
  double l2 = NewGetLc(p2);
  double l = .5*(l1+l2);

  const double coord = 0.5;
  double U = coord * p1->u + (1 - coord) * p2->u;
  double V = coord * p1->v + (1 - coord) * p2->v;

  GPoint gpp = f->point(U, V);
  double lmid = BGM_MeshSize(f, U, V, gpp.x(), gpp.y(), gpp.z());
  l = std::min(l, lmid);

  if(CTX::instance()->mesh.lcFromCurvature){
    double l3 = l;
    double lcmin = std::min(std::min(l1, l2), l3);
    l1 = std::min(lcmin*1.2,l1);
    l2 = std::min(lcmin*1.2,l2);
    l3 = std::min(lcmin*1.2,l3);
    l = (l1+l2+l3)/3.0;
  }
  return l;
}

double NewGetLc(BDS_Edge *e, GFace *f)
{
  double linearLength = computeEdgeLinearLength(e, f);
  double l = correctLC_ (e->p1,e->p2,f);
  //  printf("BDS %d %d %g %g correct lc =%g lreal=%g \n",e->p1->iD, e->p2->iD,e->p1->lc(),e->p2->lc(),l,linearLength);
  return linearLength / l;
}

double NewGetLc(BDS_Point *p1, BDS_Point *p2, GFace *f)
{
  double linearLength = computeEdgeLinearLength(p1, p2, f);
  double l = correctLC_ (p1,p2,f);
  return linearLength / l;
}

void computeMeshSizeFieldAccuracy(GFace *gf, BDS_Mesh &m, double &avg,
                                  double &max_e, double &min_e, int &nE, int &GS)
{

  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  avg = 0.0;
  min_e = 1.e22;
  max_e = 0;
  nE = 0;
  GS = 0;
  double oneoversqr2 = 1. / sqrt(2.);
  double sqr2 = sqrt(2.);
  while (it != m.edges.end()){
    if (!(*it)->deleted){
      double lone = NewGetLc(*it, gf);
      if (lone > oneoversqr2 && lone < sqr2) GS++;
      avg += lone >1 ? (1. / lone) - 1. : lone - 1.;
      max_e = std::max(max_e, lone);
      min_e = std::min(min_e, lone);
      nE++;
    }
    ++it;
  }
  avg = 100*exp(1./nE*avg);
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
  double cosa;prosca (norm1, norm2, &cosa);
  return cosa > min_cos;
}

static bool evalSwapForOptimize(BDS_Edge *e, GFace *gf, BDS_Mesh &m)
{
  if(e->numfaces() != 2) return false;

  BDS_Point *p11, *p12, *p13;
  BDS_Point *p21, *p22, *p23;
  BDS_Point *p31, *p32, *p33;
  BDS_Point *p41, *p42, *p43;
  swap_config(e, &p11, &p12, &p13, &p21, &p22, &p23, &p31, &p32, &p33, &p41,
              &p42, &p43);

  // First, evaluate what we gain in element quality if the
  // swap is performed
  double qa1 = qmTriangle::gamma(p11, p12, p13);
  double qa2 = qmTriangle::gamma(p21, p22, p23);
  double qb1 = qmTriangle::gamma(p31, p32, p33);
  double qb2 = qmTriangle::gamma(p41, p42, p43);
  double qa = std::min(qa1, qa2);
  double qb = std::min(qb1, qb2);
  double qualIndicator = qb - qa;
  bool qualShouldSwap = qb > 2*qa;
  bool qualCouldSwap  = !(qb < qa * .5) && qb > .05;

  // then evaluate if swap produces smoother surfaces
  double norm11[3];
  double norm12[3];
  double norm21[3];
  double norm22[3];
  normal_triangle(p11, p12, p13, norm11);
  normal_triangle(p21, p22, p23, norm12);
  normal_triangle(p31, p32, p33, norm21);
  normal_triangle(p41, p42, p43, norm22);
  double cosa; prosca(norm11, norm12, &cosa);
  double cosb; prosca(norm21, norm22, &cosb);
  // double smoothIndicator = cosb - cosa;
  // bool smoothShouldSwap = (cosa < 0.1 && cosb > 0.3);
  // bool smoothCouldSwap = !(cosb < cosa * .5);

  double la  = computeEdgeLinearLength(p11, p12);
  double la_ = computeEdgeLinearLength(p11, p12, gf);
  double lb  = computeEdgeLinearLength(p13, p23);
  double lb_ = computeEdgeLinearLength(p13, p23, gf);

  double LA = (la_ -la) / la_;
  double LB = (lb_ -lb) / lb_;

  double distanceIndicator = LA - LB;
  bool distanceShouldSwap = (LB < .5 * LA) && LA > 1.e-2;
  bool distanceCouldSwap = !(LB > 2 * LA) || LB < 1.e-2;

  if (20 * qa < qb) return true;
  // if (LB > .025 && distanceIndicator > 0 && qb > .25) return true;
  // if (LB > .05 && distanceIndicator > 0 && qb > .15) return true;
  // if (LB > .1 && distanceIndicator > 0 && qb > .1) return true;
  // if (LB > .2 && distanceIndicator > 0 && qb > .05) return true;
  // if (LB > .3 && distanceIndicator > 0 && qb > .025) return true;

  // if swap enhances both criterion, the do it!
  if (distanceIndicator > 1e-12 && qualIndicator > 1e-12) return true;
  if (distanceShouldSwap && qualCouldSwap) return true;
  if (distanceCouldSwap && qualShouldSwap) return true;
  // if (smoothIndicator > 0 && qualIndicator > 0) return true;
  // if (smoothShouldSwap && qualCouldSwap) return true;
  // if (smoothCouldSwap && qualShouldSwap) return true;
  // if (distanceShouldSwap && qualCouldSwap) return true;
  // if (distanceCouldSwap && qualShouldSwap) return true;
  if (cosa < 0 && cosb > 0 && qb > 0.0)
    return true;
  return false;
}

/*
static bool edgeSwapTestDelaunay(BDS_Edge *e, GFace *gf)
{
  BDS_Point *op[2];

  if(!e->p1->config_modified && !e->p2->config_modified) return false;

  if(e->numfaces() != 2) return false;

  e->oppositeof(op);

  double p1x[3] = {e->p1->X, e->p1->Y, e->p1->Z};
  double p2x[3] = {e->p2->X, e->p2->Y, e->p2->Z};
  double op1x[3] = {op[0]->X, op[0]->Y, op[0]->Z};
  double op2x[3] = {op[1]->X, op[1]->Y, op[1]->Z};
  double fourth[3];
  fourthPoint(p1x, p2x, op1x, fourth);
  const double inSphere = robustPredicates::insphere(p1x, p2x, op1x, fourth, op2x);
  if (std::abs(inSphere) < 1e-12){
    return false;
  }
  double result = inSphere * robustPredicates::orient3d(p1x, p2x, op1x, fourth);
  return result > 1e-12;
}
*/
static bool edgeSwapTestDelaunayAniso(BDS_Edge *e, GFace *gf, std::set<swapquad> &configs)
{
  BDS_Point *op[2];

  if(!e->p1->config_modified && ! e->p2->config_modified) return false;

  if(e->numfaces() != 2) return false;

  e->oppositeof(op);

  swapquad sq(e->p1->iD, e->p2->iD, op[0]->iD, op[1]->iD);
  if (configs.find(sq) != configs.end()) return false;
  configs.insert(sq);

  double edgeCenter[2] = {0.5 * (e->p1->u + e->p2->u),
                          0.5 * (e->p1->v + e->p2->v)};

  double p1[2] = {e->p1->u, e->p1->v};
  double p2[2] = {e->p2->u, e->p2->v};
  double p3[2] = {op[0]->u, op[0]->v};
  double p4[2] = {op[1]->u, op[1]->v};
  double metric[3];
  buildMetric(gf, edgeCenter, metric);
  if (!inCircumCircleAniso(gf, p1, p2, p3, p4, metric)){
    return false;
  }
  return true;
}

static int edgeSwapTest(GFace *gf, BDS_Edge *e)
{
  BDS_Point *op[2];

  const double THRESH = cos(CTX::instance()->mesh.allowSwapEdgeAngle * M_PI / 180.);
  
  if(e->numfaces() != 2) return 0;

  e->oppositeof (op);


  double qa1 = qmTriangle::gamma(e->p1, e->p2, op[0]);
  double qa2 = qmTriangle::gamma(e->p1, e->p2, op[1]);
  double qb1 = qmTriangle::gamma(e->p1, op[0], op[1]);
  double qb2 = qmTriangle::gamma(e->p2, op[0], op[1]);
  double qa = std::min(qa1, qa2);
  double qb = std::min(qb1, qb2);
  if(qb > 15*qa) return 1;

  if (!edgeSwapTestAngle(e, THRESH))
    return -1;

  if(qb > qa) return 1;
  if(qb < qa) return -1;
  return 0;
}

static void swapEdgePass(GFace *gf, BDS_Mesh &m, int &nb_swap)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  BDS_SwapEdgeTestQuality qual (false,false);
  while (1){
    if (NN2++ >= NN1) break;
    if (!(*it)->deleted){
      if (CTX::instance()->mesh.algo2d == ALGO_2D_MESHADAPT_OLD){
        if (m.swap_edge(*it, BDS_SwapEdgeTestQuality(true))) nb_swap++;
      }
      else{
	int result = edgeSwapTest(gf,*it);	
	if (result >= 0)
	  if (m.swap_edge(*it,qual )) nb_swap++;
      }
    }
    ++it;
  }
}

void delaunayizeBDS(GFace *gf, BDS_Mesh &m, int &nb_swap)
{
  //  return;
  nb_swap = 0;
  std::set<swapquad> configs;
  while(1){
    int NN1 = m.edges.size();
    int NN2 = 0;
    int NSW = 0;
    std::list<BDS_Edge*>::iterator it = m.edges.begin();
    while (1){
      if (NN2++ >= NN1)break;
      if (!(*it)->deleted){
        if (edgeSwapTestDelaunayAniso(*it, gf, configs)){
          if (m.swap_edge(*it , BDS_SwapEdgeTestQuality(false))){
            NSW++;
          }
        }
      }
      ++it;
    }
    nb_swap += NSW;
    if (!NSW) return;
  }
}


bool edges_sort(std::pair<double, BDS_Edge*> a, std::pair<double, BDS_Edge*> b)
{
  // don't compare pointers: it leads to non-deterministic behavior
  // if (a.first == b.first){
  //   return ((*a.second) < (*b.second));
  // }
  if (std::abs(a.first - b.first) < 1e-10){
    if (a.second->p1->iD == b.second->p1->iD)
      return (a.second->p2->iD < b.second->p2->iD);
    else
      return (a.second->p1->iD < b.second->p1->iD);
  }
  else
    return (a.first < b.first);
}


/*static bool middlePoint2 (GFace *gf, BDS_Edge *e, double &u, double &v)
{
  discreteFace *df = static_cast<discreteFace*> (gf);
  if (df){
    double X1 = e->p1->X;
    double X2 = e->p2->X;
    double Y1 = e->p1->Y;
    double Y2 = e->p2->Y;
    double Z1 = e->p1->Z;
    double Z2 = e->p2->Z;
    double XX = 0.5*(X1+X2);
    double YY = 0.5*(Y1+Y2);
    double ZZ = 0.5*(Z1+Z2);
    double uv[2];
    GPoint gp = gf->closestPoint(SPoint3(XX, YY, ZZ), uv);
    u = gp.u();
    v = gp.v();

    BDS_Point *op[2];
    BDS_Point *p1 = e->p1;
    BDS_Point *p2 = e->p2;

    e->oppositeof(op);

    double _p1 [2] = {p1->u,p1->v};
    double _p2 [2] = {p2->u,p2->v};
    double _op1[2] = {op[0]->u,op[0]->v};
    double _op2[2] = {op[1]->u,op[1]->v};
    double _mid[2] = {u,v};
    
    double ori1 = robustPredicates::orient2d(_mid, _p1, _op2);
    double ori2 = robustPredicates::orient2d(_mid, _op2, _p2);
    double ori3 = robustPredicates::orient2d(_mid, _p2, _op1);
    double ori4 = robustPredicates::orient2d(_mid, _op1, _p1);
    
    if (ori1 * ori2 < 0 || ori1 * ori3 < 0 || ori1 * ori4 < 0) {
      return false;
    }        
  }
  return true;
}
*/
static bool middlePoint (GFace *gf, BDS_Edge *e, double &u, double &v)
{
  // try that
  
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
  while (1){
    u = 0.5*(u1+u2);
    v = 0.5*(v1+v2);
    GPoint gpp = gf->point(u,v);
    double X = gpp.x();
    double Y = gpp.y();
    double Z = gpp.z();
    double l1 = sqrt((X-X1)*(X-X1)+(Y-Y1)*(Y-Y1)+(Z-Z1)*(Z-Z1));
    double l2 = sqrt((X-X2)*(X-X2)+(Y-Y2)*(Y-Y2)+(Z-Z2)*(Z-Z2));
    // 1 ------ p -- 2
    if (l1 > 1.2*l2){
      //      printf("1 %g 2 %g \n",l1,l2);
      u2 = u; v2 = v;  
    }
    else if (l2 > 1.2*l1){
      //      printf("1 %g 2 %g \n",l1,l2);
      u1 = u; v1 = v;  
    }
    else break;
    if (iter++ > 10){
      u = 0.5*(e->p1->u+e->p2->u);
      v = 0.5*(e->p1->v+e->p2->v);
      return false;
    }
  }  
  return true;
}

static void splitEdgePass(GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split)
{
  std::vector<std::pair<double, BDS_Edge*> > edges;
  
  std::list<BDS_Edge*>::iterator it = m.edges.begin();

  while (it != m.edges.end()){
    if(!(*it)->deleted && (*it)->numfaces() == 2 && (*it)->g->classif_degree == 2){
      double lone = NewGetLc(*it, gf);
      if(lone > MAXE_)edges.push_back(std::make_pair(-lone, *it));
    }
    ++it;
  }
  
  std::sort(edges.begin(), edges.end(), edges_sort);
  
  std::vector<BDS_Point*> mids(edges.size());
  
  bool isPeriodic = gf->periodic(0) || gf->periodic(1) ;
  bool faceDiscrete = gf->geomType() == GEntity::DiscreteSurface;

  int MAXX = m.MAXPOINTNUMBER;
  
  for (unsigned int i = 0; i < edges.size(); ++i){
    BDS_Edge *e = edges[i].second;
    BDS_Point *mid = NULL;
    if (!e->deleted){
      double U = 0.5*(e->p1->u+e->p2->u);
      double V = 0.5*(e->p1->v+e->p2->v);
      if (faceDiscrete)middlePoint (gf, e, U, V);
      
      GPoint gpp = gf->point(U,V);
      
      if ((!isPeriodic || gf->containsParam(SPoint2(U,V))) && gpp.succeeded()){
	mid  = m.add_point(++m.MAXPOINTNUMBER, gpp.x(),gpp.y(),gpp.z());
        mid->u = U;
        mid->v = V;
	mid->lcBGM() = BGM_MeshSize (gf,U,V, mid->X,mid->Y,mid->Z);
	mid->lc() = 0.5 * (e->p1->lc() +  e->p2->lc());
      }
    }
    mids[i] = mid;
  }
  
  for (unsigned int i = 0; i < edges.size(); ++i){
    BDS_Edge *e = edges[i].second;
    if (!e->deleted){
      BDS_Point *mid = mids[i];      
      if (mid){
	if(!m.split_edge(e, mid)) m.del_point(mid);
	else nb_split++;
      }
    }
  }

}

double getMaxLcWhenCollapsingEdge(GFace *gf, BDS_Mesh &m, BDS_Edge *e, BDS_Point *p)
{
  BDS_Point *o = e->othervertex(p);

  double maxLc = 0.0;
  std::list<BDS_Edge*> edges(p->edges);
  std::list<BDS_Edge*>::iterator eit = edges.begin();
  std::list<BDS_Edge*>::iterator eite = edges.end();
  while (eit != eite) {
    BDS_Point *newP1 = 0, *newP2 = 0;
    if ((*eit)->p1 == p){
      newP1 = o;
      newP2 = (*eit)->p2;
    }
    else if ((*eit)->p2 == p){
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
  std::list<BDS_Face*> t;
  p->getTriangles(t);
  std::list<BDS_Face*>::iterator it = t.begin();
  std::list<BDS_Face*>::iterator ite = t.end();
  while(it != ite) {
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
      //      printf("FLIIIP\n");
      return true;
    }
    ++it;
  }
  return false;
}
*/
void collapseEdgePass(GFace *gf, BDS_Mesh &m, double MINE_, int MAXNP, int &nb_collaps)
{
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  std::vector<std::pair<double, BDS_Edge*> > edges;

  while (it != m.edges.end()){
    if(!(*it)->deleted && (*it)->numfaces() == 2 && (*it)->g->classif_degree == 2){
      double lone = NewGetLc(*it, gf);
      if(lone < MINE_) edges.push_back (std::make_pair(lone, *it));
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end(), edges_sort);

  for (unsigned int i = 0; i < edges.size(); i++){
    BDS_Edge *e = edges[i].second;
    if(!e->deleted){
      double lone1 = 0.;
      bool collapseP1Allowed = false;
      lone1 = getMaxLcWhenCollapsingEdge(gf, m, e, e->p1);
      collapseP1Allowed = std::abs(lone1-1.0) < std::abs(edges[i].first - 1.0);

      double lone2 = 0.;
      bool collapseP2Allowed = false;
      if (e->p2->iD > MAXNP){
        lone2 = getMaxLcWhenCollapsingEdge(gf, m, e, e->p2);
        collapseP2Allowed = std::abs(lone2-1.0) < std::abs(edges[i].first - 1.0);
      }

      BDS_Point *p = 0;
      if (collapseP1Allowed && collapseP2Allowed){
        if (std::abs(lone1 - lone2) < 1e-12)
          p = e->p1->iD < e->p2->iD ? e->p1 : e->p2;
        else
          p = std::abs(lone1 - 1.0) < std::abs(lone2 - 1.0) ? e->p1 : e->p2;
      }
      else if (collapseP1Allowed && !collapseP2Allowed)
        p = e->p1;
      else if (collapseP1Allowed && !collapseP2Allowed)
        p = e->p2;

      bool res = false;
      if(p)
        res = m.collapse_edge_parametric(e, p);
      if(res)
        nb_collaps++;
    }
  }
}

void smoothVertexPass(GFace *gf, BDS_Mesh &m, int &nb_smooth, bool q)
{
  // FIXME SUPER HACK
  //  return;
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while(itp != m.points.end()){
    if(m.smooth_point_centroid(*itp, gf,q))
      nb_smooth ++;
    ++itp;
  }
}


void computeNodalSizes(GFace *gf, BDS_Mesh &m, 
		       std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap){
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while (itp != m.points.end()){
    (*itp)->lc() = MAX_LC;
    ++itp;
  }
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (it != m.edges.end()){
    bool degenerated = false;
    if (recoverMap){
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp1 = recoverMap->find((*it)->p1);
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp2 = recoverMap->find((*it)->p2);
      if (itp1 != recoverMap->end() && itp2 != recoverMap->end() &&
	  itp1->second == itp2->second){
	degenerated = true;
      }
    }	

    if (!degenerated && (*it)->g && (*it)->g->classif_degree == 1){
      double L = (*it)->length();
      if ((*it)->p1->lc() == MAX_LC)(*it)->p1->lc() = L;
      else (*it)->p1->lc() = std::max (L, (*it)->p1->lc());
      if ((*it)->p2->lc() == MAX_LC)(*it)->p2->lc() = L;
      else (*it)->p2->lc() = std::max (L, (*it)->p2->lc());
    }
    ++it;
  }

  itp = m.points.begin();
  std::vector<BDS_Point*> pts;
  while (itp != m.points.end()){
    if ((*itp)->lc() == MAX_LC)pts.push_back(*itp);
    ++itp;
  }
  int iter = 0; 
  while (1){
    bool allTouched = true;
    for (size_t i=0; i< pts.size(); i++){
      std::list<BDS_Edge*>::iterator it  = pts[i]->edges.begin();
      std::list<BDS_Edge*>::iterator ite = pts[i]->edges.end();
      while(it != ite){
	BDS_Point *p = (*it)->othervertex (pts[i]);
	if (p->lc() != MAX_LC){
	  if (pts[i]->lc() == MAX_LC)pts[i]->lc() = p->lc();
	  else pts[i]->lc() = 0.5*(p->lc()+pts[i]->lc());
	}
	++it;
      }
      if (pts[i]->lc() == MAX_LC) allTouched = false;
    }
    if (allTouched && iter++ == 5)break;
  }
}


void computeNodalSizes2(GFace *gf, BDS_Mesh &m, 
		       std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap)
{
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while (itp != m.points.end()){
    std::list<BDS_Edge*>::iterator it  = (*itp)->edges.begin();
    std::list<BDS_Edge*>::iterator ite = (*itp)->edges.end();
    double L = MAX_LC;
    int ne = 0;
    while(it != ite){
      double l = (*it)->length();
      if (recoverMap){
	std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp1 = recoverMap->find((*it)->p1);
	std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp2 = recoverMap->find((*it)->p2);
	if (itp1 != recoverMap->end() && itp2 != recoverMap->end() &&
	    itp1->second == itp2->second){
	  l = 0.0;
	}
      }	
      if (l > 1.e-22){
	if ((*itp)->g->classif_degree == 2)
	  L = ne ? std::min(L, l) : l;
	else
	  L = ne ? std::min(L, l) : l;

	ne++;
      }
      ++it;
    }
    
    if ((*itp)->g && (*itp)->g->classif_tag > 0 && (*itp)->g->classif_degree < 2){
      if (!ne) L = MAX_LC;
      if(CTX::instance()->mesh.lcFromPoints)
	(*itp)->lc() = L;
      (*itp)->lcBGM() = L;
    }
  ++itp;
  }
}

void refineMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT,
                   const bool computeNodalSizeField,
                   std::map<MVertex*, BDS_Point*> *recoverMapInv,
		   std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap)
{
  //  return;
  int IT = 0;
  int MAXNP = m.MAXPOINTNUMBER;

  //  std::set<MVertex *, MVertexLessThanNum> degenerated;
  //  if (recoverMap){
  //    getDegeneratedVertices (m,recoverMap,degenerated);
  //  }
  //  printf("%d degenerated vertices\n",degenerated.size());
  
  // classify correctly the embedded vertices use a negative model
  // face number to avoid mesh motion
  if(recoverMapInv){
    std::list<GVertex*> emb_vertx = gf->embeddedVertices();
    std::list<GVertex*>::iterator itvx = emb_vertx.begin();
    while(itvx != emb_vertx.end()){
      MVertex *v = *((*itvx)->mesh_vertices.begin());
      std::map<MVertex*, BDS_Point*>::iterator itp = recoverMapInv->find(v);
      if(itp != recoverMapInv->end()){
        BDS_Point *p = itp->second;
        m.add_geom(-1, 2);
        p->g = m.get_geom(-1, 2);
        ++itvx;
      }
    }
  }

  // If asked, compute nodal size field using 1D Mesh
  if (computeNodalSizeField)computeNodalSizes(gf, m,recoverMap);

  double t_spl = 0, t_sw = 0,t_col = 0,t_sm = 0;

  const double MINE_ = 0.7, MAXE_ = 1.4;

  while (1){

    // we count the number of local mesh modifs.
    int nb_split = 0;
    int nb_smooth = 0;
    int nb_collaps = 0;
    int nb_swap = 0;

    // split long edges
    double minL = 1.e22, maxL = 0;
    int NN1 = m.edges.size();
    int NN2 = 0;
    std::list<BDS_Edge*>::iterator it = m.edges.begin();

    while (1){
      if (NN2++ >= NN1)break;
      if (!(*it)->deleted){
        (*it)->p1->config_modified = false;
        (*it)->p2->config_modified = false;
        double lone = NewGetLc(*it, gf);
        maxL = std::max(maxL, lone);
        minL = std::min(minL, lone);
      }
      ++it;
    }

    if ((minL > MINE_ && maxL < MAXE_) || IT > (abs(NIT))) break;
    double maxE = MAXE_;
    double minE = MINE_;
    double t1 = Cpu();
    splitEdgePass(gf, m, maxE, nb_split);

    double t2 = Cpu();
    swapEdgePass(gf, m, nb_swap);

    double t3 = Cpu();
    collapseEdgePass(gf, m, minE, MAXNP, nb_collaps);
    double t4 = Cpu();
    swapEdgePass ( gf, m, nb_swap);
    double t5 = Cpu();
    smoothVertexPass(gf, m, nb_smooth, false);
    double t6 = Cpu();
    swapEdgePass ( gf, m, nb_swap);
    double t7 = Cpu();
    //    if (computeNodalSizeField){
    //      char name[256]; sprintf(name,"iter%d_COLLAPSE.pos",IT);
    //      outputScalarField(m.triangles, name, 0);
    //    }
    // clean up the mesh
    t_spl += t2 - t1;
    t_sw  += t3 - t2;
    t_sw  += t5 - t4;
    t_sw  += t7 - t6;
    t_col += t4 - t3;
    t_sm  += t6 - t5;
    m.cleanup();

    IT++;
    Msg::Debug(" iter %3d minL %8.3f/%8.3f maxL %8.3f/%8.3f : "
               "%6d splits, %6d swaps, %6d collapses, %6d moves",
               IT, minL, minE, maxL, maxE, nb_split, nb_swap, nb_collaps, nb_smooth);
    if (nb_split == 0 && nb_collaps == 0) break;

  }
  // Remove all small edges ...
  int  nb_collaps, nb_swap;
  collapseEdgePass(gf, m, MINE_, MAXNP, nb_collaps);
  swapEdgePass ( gf, m, nb_swap);
  collapseEdgePass(gf, m, MINE_, MAXNP, nb_collaps);
  swapEdgePass ( gf, m, nb_swap);
  swapEdgePass ( gf, m, nb_swap);
  
  double t_total = t_spl + t_sw + t_col + t_sm;
  if(!t_total) t_total = 1.e-6;
  Msg::Debug(" ---------------------------------------");
  Msg::Debug(" CPU Report ");
  Msg::Debug(" ---------------------------------------");
  Msg::Debug(" CPU SWAP    %12.5E sec (%3.0f %%)", t_sw,100 * t_sw / t_total);
  Msg::Debug(" CPU SPLIT   %12.5E sec (%3.0f %%) ", t_spl,100 * t_spl / t_total);
  Msg::Debug(" CPU COLLAPS %12.5E sec (%3.0f %%) ", t_col,100 * t_col / t_total);
  Msg::Debug(" CPU SMOOTH  %12.5E sec (%3.0f %%) ", t_sm,100 * t_sm / t_total);
  Msg::Debug(" ---------------------------------------");
  Msg::Debug(" CPU TOTAL   %12.5E sec ",t_total);
  Msg::Debug(" ---------------------------------------");
}

bool degeneratedTriangle (BDS_Face *f, std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap){

  MVertex *v[3] = {0,0,0};
  BDS_Point *n[4];
  f->getNodes(n);
  for (int i=0;i<3;i++){
    std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp1 = recoverMap->find(n[i]);
    if (itp1 != recoverMap->end())v[i] = itp1->second;
  }
  if (v[0] && (v[0] == v[1] || v[0] == v[2]))return true;
  if (v[1] && (v[1] == v[2] || v[0] == v[1]))return true;
  if (v[2] && (v[1] == v[2] || v[0] == v[2]))return true;
  return false;
}


void invalidEdgesPeriodic(BDS_Mesh &m,
                          std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap,
                          std::set<BDS_Edge*, EdgeLessThan> &toSplit)
{

  // first look for degenerated vertices
  std::set<MVertex *, MVertexLessThanNum> degenerated;
  getDegeneratedVertices (m,recoverMap,degenerated);
  Msg::Debug("Found %d degenerated vertices",degenerated.size());

  
  toSplit.clear();
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  std::map<std::pair<MVertex*, BDS_Point*>, BDS_Edge *> touchPeriodic;
  while (it != m.edges.end()){
    BDS_Edge *e = *it;
    if (!e->deleted && e->numfaces() == 2){
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp1 = recoverMap->find(e->p1);
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp2 = recoverMap->find(e->p2);
      if (itp1 != recoverMap->end() &&
          itp2 != recoverMap->end() &&
          itp1->second == itp2->second) toSplit.insert(e);
      else if (itp1 != recoverMap->end() && itp2 == recoverMap->end()){
        std::pair<MVertex*, BDS_Point*> a(itp1->second, e->p2);
        std::map<std::pair<MVertex*, BDS_Point*>, BDS_Edge*>::iterator itf =
          touchPeriodic.find(a);
        if (itf == touchPeriodic.end()) touchPeriodic[a] = e;
        else if (degenerated.find(itp1->second) == degenerated.end()){
          toSplit.insert(e); toSplit.insert(itf->second);
        }
      }
      else if (itp1 == recoverMap->end() && itp2 != recoverMap->end()){
        std::pair<MVertex*, BDS_Point*> a(itp2->second, e->p1);
        std::map<std::pair<MVertex*, BDS_Point*>, BDS_Edge*>::iterator itf =
          touchPeriodic.find(a);
        if (itf == touchPeriodic.end()) touchPeriodic[a] = e;
        else if (degenerated.find(itp2->second) == degenerated.end()){
          toSplit.insert(e); toSplit.insert(itf->second);
        }
      }
    }
    ++it;
  }
  //return;
  Msg::Debug("%d degenerated edges should be split",toSplit.size());
  size_t aa = toSplit.size();
  // same edges should be split
  {
    std::set<BDS_Point*, PointLessThan>::iterator it = m.points.begin();
    while (it != m.points.end()){
      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp2 = recoverMap->find(*it);
      if (itp2 == recoverMap->end()){      
	std::list<BDS_Edge*>::iterator ite = (*it)->edges.begin();
	std::map<MVertex*,BDS_Edge*> mp;
	while (ite != (*it)->edges.end()){
	  if (!(*ite)->deleted && (*ite)->numfaces() == 2){
	    if (!degeneratedTriangle ((*ite)->faces(0),recoverMap) &&
		!degeneratedTriangle ((*ite)->faces(1),recoverMap)){			      
	      BDS_Point *other = (*it) == (*ite)->p1 ? (*ite)->p2 : (*ite)->p1;	  
	      std::map<BDS_Point*, MVertex*,PointLessThan>::iterator itp1 = recoverMap->find(other);
	      if (itp1 != recoverMap->end()){
		if (mp.find(itp1->second) != mp.end()){
		  toSplit.insert(*ite); toSplit.insert(mp[itp1->second]);
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
  Msg::Debug("%d similar edges should be split",toSplit.size()-aa);
  //  printf("%d splits\n",toSplit.size());


}

// consider p1 and p2, 2 vertices that are different in the parametric
// plane BUT are the same in the real plane
// consider a vertex v that is internal
// if p1 is the start and the end of a degenerated edge, then allow edges p1 v and p2 v
// if not do not allow p1 v and p2 v, split them
// if p1 p2 exists and it is internal, split it

int solveInvalidPeriodic(GFace *gf, BDS_Mesh &m,
                         std::map<BDS_Point*, MVertex*,PointLessThan> *recoverMap)
{
  if (!recoverMap) return 0;

  BDS_GeomEntity *g = m.get_geom(gf->tag(),2); 
  
  //  return 0;
  Msg::Debug("Solving invalid edges/triangles in initial meshes of periodic face %d",gf->tag());

  std::set<BDS_Edge*, EdgeLessThan> toSplit;
  invalidEdgesPeriodic(m, recoverMap, toSplit);
  std::set<BDS_Edge*>::iterator ite = toSplit.begin();

  Msg::Debug("%d edges of the initial mesh are going to be split",toSplit.size());
  
  for (;ite !=toSplit.end(); ++ite){
    BDS_Edge *e = *ite;
    if (!e->deleted && e->numfaces() == 2){
      const double coord = 0.5;
      BDS_Point *mid ;
      mid = m.add_point(++m.MAXPOINTNUMBER,
                        coord * e->p1->u + (1 - coord) * e->p2->u,
                        coord * e->p1->v + (1 - coord) * e->p2->v, gf);
      mid->lcBGM() = BGM_MeshSize(gf,
				  (coord * e->p1->u + (1 - coord) * e->p2->u),
				  (coord * e->p1->v + (1 - coord) * e->p2->v),
				  mid->X, mid->Y, mid->Z);
      mid->lc() = 0.5 * (e->p1->lc() + e->p2->lc());
      mid->u = coord * e->p1->u + (1 - coord) * e->p2->u;
      mid->v = coord * e->p1->v + (1 - coord) * e->p2->v;
      mid->g = g;

      if(!m.split_edge(e, mid)) m.del_point(mid);
    }
  }
  int nb_smooth;
  //  if(toSplit.size()) smoothVertexPass(gf, m, nb_smooth, true);
  m.cleanup();
  return toSplit.size();
}


void optimizeMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT,
                     std::map<BDS_Point*,MVertex*,PointLessThan> *recoverMap=0)
{
  
  int nb_swap;
  delaunayizeBDS(gf, m, nb_swap);
  //  return;
  
  while(solveInvalidPeriodic(gf, m, recoverMap)){
    for (int ITER = 0; ITER < 4; ITER++){
      for (int KK = 0; KK < 4; KK++){
	// swap edges that provide a better configuration
	int NN1 = m.edges.size();
	int NN2 = 0;
	std::list<BDS_Edge*>::iterator it = m.edges.begin();
	while (1){
	  if (NN2++ >= NN1)break;
	  if (evalSwapForOptimize(*it, gf, m))
	    m.swap_edge(*it, BDS_SwapEdgeTestQuality(false));
	  ++it;
	}
	m.cleanup();
	int nb_smooth;
	//	smoothVertexPass(gf, m, nb_smooth, true);
      }
    }
    //    TRYTOFIXSPHERES(gf,m,recoverMap);
  }  
}

// DELAUNAY BDS

// build the BDS from a list of GFace
// This is a TRUE copy
BDS_Mesh *gmsh2BDS(std::list<GFace*> &l)
{
  BDS_Mesh *m = new BDS_Mesh;
  for (std::list<GFace*>::iterator it = l.begin(); it != l.end(); ++it){
    GFace *gf = *it;
    m->add_geom(gf->tag(), 2);
    BDS_GeomEntity *g2 = m->get_geom(gf->tag(), 2);
    for (unsigned int i = 0; i < gf->triangles.size(); i++){
      MTriangle *e = gf->triangles[i];
      BDS_Point *p[3];
      for (int j = 0; j < 3; j++){
        p[j] = m->find_point(e->getVertex(j)->getNum());
        if (!p[j]) {
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
