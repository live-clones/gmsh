// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include <stdlib.h>
#include "GmshMessage.h"
#include "robustPredicates.h"
#include "meshGFace.h"
#include "meshGFaceOptimize.h"
#include "BackgroundMesh.h"
#include "GVertex.h"
#include "GEdge.h"
#include "GFace.h"
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

double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2)
{
  const double dx = p1->X - p2->X;
  const double dy = p1->Y - p2->Y;
  const double dz = p1->Z - p2->Z;
  const double l = sqrt(dx * dx + dy * dy + dz * dz);
  return l;
}

inline double computeEdgeLinearLength(BDS_Point *p1, BDS_Point *p2, GFace *f,
                                      double SCALINGU, double SCALINGV)
{
  GPoint GP = f->point(SPoint2(0.5 * (p1->u + p2->u) * SCALINGU,
                               0.5 * (p1->v + p2->v) * SCALINGV));

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

inline double computeEdgeLinearLength_new(BDS_Point *p1, BDS_Point *p2,  GFace *f,
                                          double SCALINGU, double SCALINGV)
{
  const int nbSb = 10;
  GPoint GP[nbSb-1];

  for (int i = 1; i < nbSb; i++){
    double xi = (double)i / nbSb;
    GP[i-1] = f->point(SPoint2(((1-xi) * p1->u + xi * p2->u) * SCALINGU,
                               ((1-xi) * p1->v + xi * p2->v) * SCALINGV));
    if (!GP[i-1].succeeded())
      return computeEdgeLinearLength(p1,p2);
  }
  double l = 0;
  for (int i = 0; i < nbSb; i++){
    if (i == 0){
      const double dx1 = p1->X - GP[0].x();
      const double dy1 = p1->Y - GP[0].y();
      const double dz1 = p1->Z - GP[0].z();
      l+= sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
    }
    else if (i == nbSb-1){
      const double dx1 = p2->X - GP[nbSb-1].x();
      const double dy1 = p2->Y - GP[nbSb-1].y();
      const double dz1 = p2->Z - GP[nbSb-1].z();
      l+= sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
    }
    else{
      const double dx1 = GP[i].x() - GP[i-1].x();
      const double dy1 = GP[i].y() - GP[i-1].y();
      const double dz1 = GP[i].z() - GP[i-1].z();
      l+= sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
    }
  }
  return l;
}

inline double computeEdgeMiddleCoord_new(BDS_Point *p1, BDS_Point *p2, GFace *f,
                                         double SCALINGU, double SCALINGV)
{
  const int nbSb = 3;
  double L = computeEdgeLinearLength(p1,p2);
  GPoint GP[nbSb];
  for (int i = 1; i < nbSb; i++){
    double xi = (double)i / nbSb;
    GP[i-1] = f->point(SPoint2(((1-xi) * p1->u + xi * p2->u) * SCALINGU,
                               ((1-xi) * p1->v + xi * p2->v) * SCALINGV));
    if (!GP[i-1].succeeded())
      return 0.5;
    const double dx1 = p1->X - GP[i-1].x();
    const double dy1 = p1->Y - GP[i-1].y();
    const double dz1 = p1->Z - GP[i-1].z();
    double LPLUS = sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
    if (LPLUS > L*.5){
      double XIMINUS, LPLUS, LMINUS;
      if (i==1){
        XIMINUS=0;
      }
      return  XIMINUS +  (LPLUS - L*.5)/(LPLUS-LMINUS)/(nbSb-1);
    }
  }
  return 0.5;
}

inline double computeEdgeMiddleCoord(BDS_Point *p1, BDS_Point *p2, GFace *f,
                                     double SCALINGU, double SCALINGV)
{
  if (f->geomType() == GEntity::Plane)
    return 0.5;

  GPoint GP = f->point(SPoint2(0.5 * (p1->u + p2->u) * SCALINGU,
                               0.5 * (p1->v + p2->v) * SCALINGV));

  const double dx1 = p1->X - GP.x();
  const double dy1 = p1->Y - GP.y();
  const double dz1 = p1->Z - GP.z();
  const double l1 = sqrt(dx1 * dx1 + dy1 * dy1 + dz1 * dz1);
  const double dx2 = p2->X - GP.x();
  const double dy2 = p2->Y - GP.y();
  const double dz2 = p2->Z - GP.z();
  const double l2 = sqrt(dx2 * dx2 + dy2 * dy2 + dz2 * dz2);

  if (l1 > l2)
    return 0.25 * (l1 + l2) / l1;
  else
    return 0.25 * (3 * l2 - l1) / l2;
}

inline double computeEdgeLinearLength(BDS_Edge *e, GFace *f, 
                                      double SCALINGU, double SCALINGV)
{
  if (f->geomType() == GEntity::Plane)
    return e->length();
  else
    return computeEdgeLinearLength(e->p1, e->p2, f, SCALINGU, SCALINGV);
}

double NewGetLc(BDS_Point *p)
{
  return Extend1dMeshIn2dSurfaces() ? 
    std::min(p->lc(), p->lcBGM()) : p->lcBGM();
}

static double correctLC_(BDS_Point *p1,BDS_Point *p2, GFace *f,
                         double SCALINGU, double SCALINGV)
{
  double l1 = NewGetLc(p1);
  double l2 = NewGetLc(p2);  
  double l = 0.5 * (l1 + l2);

  if(CTX::instance()->mesh.lcFromCurvature){
    //      GPoint GP = f->point(SPoint2(0.5 * (p1->u + p2->u) * SCALINGU,
    //                                   0.5 * (p1->v + p2->v) * SCALINGV));
    //      double l3 = BGM_MeshSize(f,GP.u(),GP.v(),GP.x(),GP.y(),GP.z());
    double l3 = l2;
    double lcmin = std::min(std::min(l1, l2), l3);
    l1 = std::min(lcmin*1.2,l1);
    l2 = std::min(lcmin*1.2,l2);
    l3 = std::min(lcmin*1.2,l3);
    l = (l1+l2+l3)/3.0;
  }
  return l;
}

double NewGetLc(BDS_Edge *e, GFace *f, double SCALINGU, double SCALINGV)
{
  double linearLength = computeEdgeLinearLength(e, f, SCALINGU, SCALINGV);
  double l = correctLC_ (e->p1,e->p2,f, SCALINGU, SCALINGV); 
  return linearLength / l;
}

double NewGetLc(BDS_Point *p1, BDS_Point *p2, GFace *f, double su, double sv)
{
  double linearLength = computeEdgeLinearLength(p1, p2, f, su, sv);
  double l = correctLC_ (p1,p2,f, su, sv); 
  return linearLength / l;
}

void computeMeshSizeFieldAccuracy(GFace *gf, BDS_Mesh &m, double &avg, 
                                  double &max_e, double &min_e, int &nE, int &GS)
{
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  avg = 0;
  min_e = 1.e22;
  max_e = 0;
  nE = 0;
  GS = 0;
  double oneoversqr2 = 1. / sqrt(2.);
  double sqr2 = sqrt(2.);
  while (it != m.edges.end()){
    if (!(*it)->deleted){
      double lone = NewGetLc(*it, gf, m.scalingU, m.scalingV);
      if (lone > oneoversqr2 && lone < sqr2) GS++;
      avg += lone >1 ? (1. / lone) - 1. : lone - 1.;
      max_e = std::max(max_e, lone);
      min_e = std::min(min_e, lone);
      nE++;
    }
    ++it;
  }
}

// SWAP TESTS i.e. tell if swap should be done

bool edgeSwapTestAngle(BDS_Edge *e, double min_cos)
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

bool evalSwapForOptimize(BDS_Edge *e, GFace *gf, BDS_Mesh &m)
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
  double qa1 = qmTriangle(p11, p12, p13, QMTRI_RHO);
  double qa2 = qmTriangle(p21, p22, p23, QMTRI_RHO);
  double qb1 = qmTriangle(p31, p32, p33, QMTRI_RHO);
  double qb2 = qmTriangle(p41, p42, p43, QMTRI_RHO);
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
  double la_ = computeEdgeLinearLength(p11, p12, gf, m.scalingU, m.scalingV);
  double lb  = computeEdgeLinearLength(p13, p23);
  double lb_ = computeEdgeLinearLength(p13, p23, gf, m.scalingU, m.scalingV);

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
  if (distanceIndicator > 0 && qualIndicator > 0) return true;
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

bool edgeSwapTestDelaunay(BDS_Edge *e, GFace *gf)
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
  double result = robustPredicates::insphere(p1x, p2x, op1x, fourth, op2x) * 
    robustPredicates::orient3d(p1x, p2x, op1x, fourth);  
  return result > 0.;
}

bool edgeSwapTestHighOrder(BDS_Edge *e,GFace *gf)
{
  // must evaluate the swap with the perspectve of 
  // the generation of 2 high order elements 
  // The rationale is to consider the edges as
  // exactly matching curves and surfaces 
  return false;
}

bool edgeSwapTestDelaunayAniso(BDS_Edge *e, GFace *gf, std::set<swapquad> &configs)
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

bool evalSwap(BDS_Edge *e, double &qa, double &qb)
{
  BDS_Point *op[2];
  
  if(e->numfaces() != 2) return false;  
  e->oppositeof (op);
  double qa1 = qmTriangle(e->p1, e->p2, op[0], QMTRI_RHO);
  double qa2 = qmTriangle(e->p1, e->p2, op[1], QMTRI_RHO);
  double qb1 = qmTriangle(e->p1, op[0], op[1], QMTRI_RHO);
  double qb2 = qmTriangle(e->p2, op[0], op[1], QMTRI_RHO);
  qa = std::min(qa1, qa2);
  qb = std::min(qb1, qb2);
  return true;
}

int edgeSwapTestQuality(BDS_Edge *e, double fact=1.1, bool force=false)
{
  BDS_Point *op[2];
  
  if (!force)
    if(!e->p1->config_modified && ! e->p2->config_modified) return 0;
  
  if(e->numfaces() != 2) return 0;
  
  e->oppositeof (op);

  if (!force)
    if (!edgeSwapTestAngle(e, cos(CTX::instance()->mesh.allowSwapEdgeAngle * M_PI / 180.)))
      return -1;
  
  double qa1 = qmTriangle(e->p1, e->p2, op[0], QMTRI_RHO);
  double qa2 = qmTriangle(e->p1, e->p2, op[1], QMTRI_RHO);
  double qb1 = qmTriangle(e->p1, op[0], op[1], QMTRI_RHO);
  double qb2 = qmTriangle(e->p2, op[0], op[1], QMTRI_RHO);
  double qa = std::min(qa1, qa2);
  double qb = std::min(qb1, qb2);
  if(qb > fact * qa) return 1;
  if(qb < qa / fact) return -1;
  return 0;
}

void swapEdgePass(GFace *gf, BDS_Mesh &m, int &nb_swap)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  while (1){
    if (NN2++ >= NN1) break;
    // result = -1 => forbid swap because too badly shaped elements
    // result = 0  => whatever
    // result = 1  => oblige to swap because the quality is greatly improved
    if (!(*it)->deleted){
      double qual = (CTX::instance()->mesh.algo2d == ALGO_2D_MESHADAPT_OLD) ? 1 : 5;
      int result = edgeSwapTestQuality(*it, qual);
      if (CTX::instance()->mesh.algo2d == ALGO_2D_MESHADAPT_OLD){
        if (m.swap_edge(*it, BDS_SwapEdgeTestQuality(true))) nb_swap++; 
      }
      else if (result >= 0 && edgeSwapTestDelaunay(*it, gf)){
        if (m.swap_edge(*it, BDS_SwapEdgeTestQuality(false))) nb_swap++;
      }
    }
    ++it;
  }  
}

void delaunayizeBDS(GFace *gf, BDS_Mesh &m, int &nb_swap)
{
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

// A test for spheres
static void midpointsphere(GFace *gf, 
			   double u1, 
			   double v1, 
			   double u2, 
                           double v2, 
			   double &u12, 
			   double &v12, 
			   SPoint3 &center,
			   double r)
{
  GPoint p1 = gf->point(u1, v1);
  GPoint p2 = gf->point(u2, v2);
  
  SVector3 DIR ((p1.x()+p2.x())/2.0 - center.x(),
		(p1.y()+p2.y())/2.0 - center.y(),
		(p1.z()+p2.z())/2.0 - center.z());
  DIR.normalize();
  
  double X,Y,Z;

  double guess [2] = {0.5 * (u1 + u2), 0.5 * (v1 + v2)};
  u12 = guess[0];
  v12 = guess[1];
  if ( (v1 > 0.7*M_PI/2 && v2  > 0.7*M_PI/2) ||
       (v1 < -0.7*M_PI/2 && v2 < -0.7*M_PI/2) ){
    //    printf("coucou\n");
    X = center.x() + DIR.x() * r;
    Y = center.y() + DIR.y() * r;
    Z = center.z() + DIR.z() * r;
  }
  else{
    return;
    X = center.x() - DIR.x() * r;
    Y = center.y() - DIR.y() * r;
    Z = center.z() - DIR.z() * r;
  }

  GPoint proj = gf->closestPoint(SPoint3(X, Y, Z), guess);
  if (proj.succeeded()){
    u12 = proj.u();
    v12 = proj.v();
  }
  //  printf("%g %g %g -- %g\n",center.x(),center.y(),center.z(),r);
  //  printf("%g %g -- %g %g -- %g %g -- %g %g\n",
  //         u1, v1, u2, v2, u12, v12, 0.5 * (u1 + u2), 0.5 * (v1 + v2));
  return;
}

void splitEdgePass(GFace *gf, BDS_Mesh &m, double MAXE_, int &nb_split)
{ 
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  std::vector<std::pair<double, BDS_Edge*> > edges;

  while (it != m.edges.end()){
    if(!(*it)->deleted && (*it)->numfaces() == 2){
      double lone = NewGetLc(*it, gf, m.scalingU, m.scalingV);
      if(lone > MAXE_){
        edges.push_back(std::make_pair(-lone, *it));
      }
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end());

  double RADIUS;
  SPoint3 CENTER;
  bool isSphere = gf->isSphere(RADIUS,CENTER);

  for (unsigned int i = 0; i < edges.size(); ++i){
    BDS_Edge *e = edges[i].second;
    if (!e->deleted){
      const double coord = 0.5;
      //const double coord = computeEdgeMiddleCoord((*it)->p1, (*it)->p2, gf,
      //                                          m.scalingU, m.scalingV);
      BDS_Point *mid ;

      double U, V;
      if (0 && isSphere){	
        midpointsphere(gf,e->p1->u,e->p1->v,e->p2->u,e->p2->v,U,V,
                       CENTER,RADIUS);
      }
      else{
        U = coord * e->p1->u + (1 - coord) * e->p2->u;
        V = coord * e->p1->v + (1 - coord) * e->p2->v;
      }

      GPoint gpp = gf->point(m.scalingU*U,m.scalingV*V);
      if (gpp.succeeded()){  
        mid  = m.add_point(++m.MAXPOINTNUMBER, gpp.x(),gpp.y(),gpp.z());
        mid->u = U;
        mid->v = V;
        if (backgroundMesh::current()){
          mid->lc() = mid->lcBGM() = 
            backgroundMesh::current()->operator()
            ((coord * e->p1->u + (1 - coord) * e->p2->u)*m.scalingU,
             (coord * e->p1->v + (1 - coord) * e->p2->v)*m.scalingV,
             0.0);
        }
        else {
          mid->lcBGM() = BGM_MeshSize
            (gf,
             (coord * e->p1->u + (1 - coord) * e->p2->u)*m.scalingU,
             (coord * e->p1->v + (1 - coord) * e->p2->v)*m.scalingV,
             mid->X,mid->Y,mid->Z);
          mid->lc() = 0.5 * (e->p1->lc() +  e->p2->lc());
        }
        if(!m.split_edge(e, mid)) m.del_point(mid);
        else nb_split++;
      }
    }
  }
}

void collapseEdgePass(GFace *gf, BDS_Mesh &m, double MINE_, int MAXNP, int &nb_collaps)
{
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  std::vector<std::pair<double, BDS_Edge*> > edges;

  while (it != m.edges.end()){
    if(!(*it)->deleted && (*it)->numfaces() == 2){
      double lone = NewGetLc(*it, gf,m.scalingU,m.scalingV);
      if(lone < MINE_){
        edges.push_back (std::make_pair(lone, *it));
      }
    }
    ++it;
  }

  std::sort(edges.begin(), edges.end());

  for (unsigned int i = 0; i < edges.size(); i++){
    BDS_Edge *e = edges[i].second;
    if(!e->deleted){
      bool res = false;
      if(e->p1->iD > MAXNP)
        res = m.collapse_edge_parametric(e, e->p1);
      else if(e->p2->iD > MAXNP)
        res = m.collapse_edge_parametric(e, e->p2);
      if(res)
        nb_collaps++;
    }
  }
}

void collapseEdgePassUnSorted(GFace *gf, BDS_Mesh &m, double MINE_, int MAXNP, 
                              int &nb_collaps)
{
  int NN1 = m.edges.size();
  int NN2 = 0;
  std::list<BDS_Edge*>::iterator it = m.edges.begin();

  while (1){
    if(NN2++ >= NN1) break;
    
    if(!(*it)->deleted){
      double lone = NewGetLc(*it, gf, m.scalingU, m.scalingV);
      if(!(*it)->deleted && (*it)->numfaces() == 2 && lone < MINE_){
        bool res = false;
        if((*it)->p1->iD > MAXNP)
          res = m.collapse_edge_parametric(*it, (*it)->p1);
        else if((*it)->p2->iD > MAXNP)
          res = m.collapse_edge_parametric(*it, (*it)->p2);
        if(res)
          nb_collaps++;
      }
    }
    ++it;
  }
}

void smoothVertexPass(GFace *gf, BDS_Mesh &m, int &nb_smooth, bool q)
{
  //  return;
  std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
  while(itp != m.points.end()){      
    if(m.smooth_point_centroid(*itp, gf,q))
      nb_smooth ++;
    ++itp;
  }
}

void refineMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT, 
                   const bool computeNodalSizeField,
                   std::map<MVertex*, BDS_Point*> *recoverMapInv)
{
  int IT = 0;
  int MAXNP = m.MAXPOINTNUMBER;

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
        p->lc() = (*itvx)->prescribedMeshSizeAtVertex();
        p->lcBGM() = (*itvx)->prescribedMeshSizeAtVertex();
        ++itvx;
      }
    }
  }

  // If asked, compute nodal size field using 1D Mesh
  if (computeNodalSizeField){
    std::set<BDS_Point*,PointLessThan>::iterator itp = m.points.begin();
    while (itp != m.points.end()){
      std::list<BDS_Edge*>::iterator it  = (*itp)->edges.begin();
      std::list<BDS_Edge*>::iterator ite = (*itp)->edges.end();
      double L = 0;
      int ne = 0;
      while(it != ite){
        double l = (*it)->length();
        if ((*it)->g && (*it)->g->classif_degree == 1){       
          L = ne ? std::max(L, l) : l;
          ne++;
        }
        ++it;
      }
      if ((*itp)->g && (*itp)->g->classif_tag > 0){
        if (!ne) L = MAX_LC;
        if(CTX::instance()->mesh.lcFromPoints)
          (*itp)->lc() = L;
        (*itp)->lcBGM() = L;
      }
      ++itp;
    }
  }

  double t_spl = 0, t_sw = 0,t_col = 0,t_sm = 0;

  const double MINE_ = 0.67, MAXE_ = 1.4;

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
        double lone = NewGetLc(*it, gf, m.scalingU, m.scalingV);              
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
    swapEdgePass(gf, m, nb_swap);
    swapEdgePass(gf, m, nb_swap);

    //    if (computeNodalSizeField){
    //      char name[256]; sprintf(name,"iter%d_SPLIT.pos",IT);
    //      outputScalarField(m.triangles, name, 0);
    //    }
    double t3 = Cpu();
    collapseEdgePass(gf, m, minE, MAXNP, nb_collaps);

    double t4 = Cpu();
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

void allowAppearanceofEdge (BDS_Point *p1, BDS_Point *p2)
{
}

void invalidEdgesPeriodic(BDS_Mesh &m, std::map<BDS_Point*, MVertex*> *recoverMap,
                          std::set<BDS_Edge*> &toSplit)
{
  // first look for degenerated vertices
  std::list<BDS_Edge*>::iterator it = m.edges.begin();
  std::set<MVertex *> degenerated;
  while (it != m.edges.end()){
    BDS_Edge *e = *it;
    if (!e->deleted && e->numfaces() == 1){
      std::map<BDS_Point*, MVertex*>::iterator itp1 = recoverMap->find(e->p1);
      std::map<BDS_Point*, MVertex*>::iterator itp2 = recoverMap->find(e->p2);    
      if (itp1 != recoverMap->end() && itp2 != recoverMap->end() && 
          itp1->second == itp2->second){
        degenerated.insert(itp1->second);
      }
    }
    ++it;
  }

  toSplit.clear();
  it = m.edges.begin();
  std::map<std::pair<MVertex*, BDS_Point*>, BDS_Edge *> touchPeriodic;
  while (it != m.edges.end()){
    BDS_Edge *e = *it;
    if (!e->deleted && e->numfaces() == 2){
      std::map<BDS_Point*, MVertex*>::iterator itp1 = recoverMap->find(e->p1);
      std::map<BDS_Point*, MVertex*>::iterator itp2 = recoverMap->find(e->p2);    
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
}

// consider p1 and p2, 2 vertices that are different in the parametric
// plane BUT are the same in the real plane
// consider a vertex v that is internal
// if p1 is the start and the end of a degenerated edge, then allow edges p1 v and p2 v
// if not do not allow p1 v and p2 v, split them
// if p1 p2 exists and it is internal, split it

int solveInvalidPeriodic(GFace *gf, BDS_Mesh &m, 
                         std::map<BDS_Point*, MVertex*> *recoverMap)
{
  std::set<BDS_Edge*> toSplit;
  invalidEdgesPeriodic(m, recoverMap, toSplit);
  std::set<BDS_Edge*>::iterator ite = toSplit.begin();

  for (;ite !=toSplit.end(); ++ite){
    BDS_Edge *e = *ite;
    if (!e->deleted && e->numfaces() == 2){
      const double coord = 0.5;
      BDS_Point *mid ;
      mid = m.add_point(++m.MAXPOINTNUMBER,
                        coord * e->p1->u + (1 - coord) * e->p2->u,
                        coord * e->p1->v + (1 - coord) * e->p2->v, gf); 
      mid->lcBGM() = BGM_MeshSize(gf,
                                  (coord * e->p1->u + (1 - coord) * e->p2->u) * m.scalingU,
                                  (coord * e->p1->v + (1 - coord) * e->p2->v) * m.scalingV,
                                  mid->X, mid->Y, mid->Z);
      mid->lc() = 0.5 * (e->p1->lc() + e->p2->lc());
      if(!m.split_edge(e, mid)) m.del_point(mid);
    }
  }
  int nb_smooth;
  if(toSplit.size()) smoothVertexPass(gf, m, nb_smooth, true);
  m.cleanup();
  return toSplit.size();
}

void optimizeMeshBDS(GFace *gf, BDS_Mesh &m, const int NIT, 
                     std::map<BDS_Point*,MVertex*> *recoverMap=0)
{
  int nb_swap;
  delaunayizeBDS(gf, m, nb_swap);

  for (int ITER = 0; ITER < 3; ITER++){
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
      smoothVertexPass(gf, m, nb_smooth, true);
    }
  }
  
  if (recoverMap){
    while(solveInvalidPeriodic(gf, m, recoverMap)){
    }  
  }
}

// DELAUNAY BDS

void delaunayPointInsertionBDS(GFace *gf, BDS_Mesh &m, BDS_Point *v, BDS_Face *f)
{
  m.split_face(f, v);
  int nb_swap = 0;
  delaunayizeBDS(gf, m, nb_swap);
}

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

void collapseSmallEdges(GModel &gm)
{
  return;
  // gm.renumberMeshVertices(true);
  std::list<GFace*> faces;
  for (GModel::fiter fit = gm.firstFace(); fit != gm.lastFace(); fit++){
    faces.push_back(*fit);
  }
  BDS_Mesh *pm = gmsh2BDS(faces);
  outputScalarField(pm->triangles, "all.pos", 0);
  
  for (GModel::eiter eit = gm.firstEdge(); eit != gm.lastEdge(); eit++){
  } 

  delete pm;
}
