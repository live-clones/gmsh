// Copyright (C) 2013 ULg-UCL
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.
//
// Please report all bugs and problems to the public mailing list
// <gmsh@onelab.info>.
//
// Contributors: Thomas Toulorge, Jonathan Lambrechts

static int NEVAL = 0;

#include <iostream>
#include <algorithm>
#include "OptHomMesh.h"
#include "OptHOM.h"
#include "OptHomRun.h"
#include "GmshMessage.h"
#include "GmshConfig.h"
#include "OptHomCADDist.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "GModel.h"

#if defined(HAVE_BFGS)

#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"

static inline double compute_f(double v, double barrier)
{
  if ((v > barrier && barrier < 1) || (v < barrier && barrier > 1)) {
    const double l = log((v - barrier) / (1 - barrier));
    const double m = (v - 1);
    return l * l + m * m;
  }
  else return 1.e300;
  // if (v < 1.) return pow(1.-v,powM);
  // if (v < 1.) return exp((long double)pow(1.-v,3));
  // else return pow(v-1.,powP);
}

static inline double compute_f1(double v, double barrier)
{
  if ((v > barrier && barrier < 1) || (v < barrier && barrier > 1)) {
    return 2 * (v - 1) + 2 * log((v - barrier) / (1 - barrier)) / (v - barrier);
  }
  else return barrier < 1 ? -1.e300 : 1e300;
  // if (v < 1.) return -powM*pow(1.-v,powM-1.);
  // if (v < 1.) return -3.*pow(1.-v,2)*exp((long double)pow(1.-v,3));
  // else return powP*pow(v-1.,powP-1.);
}

OptHOM::OptHOM(const std::map<MElement*,GEntity*> &element2entity,
               const std::set<MElement*, Less_ElementPtr> &els, std::set<MVertex*> & toFix,
               bool fixBndNodes, bool fastJacEval) :
  mesh(element2entity, els, toFix, fixBndNodes, fastJacEval)
{
  _optimizeMetricMin = false;
}

// Contribution of the element Jacobians to the objective function value and
// gradients (2D version)
bool OptHOM::addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj)
{
  minJac = 1.e300;
  maxJac = -1.e300;

  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
    // Scaled Jacobians
    std::vector<double> sJ(mesh.nBezEl(iEl));
    // Gradients of scaled Jacobians
    std::vector<double> gSJ(mesh.nBezEl(iEl)*mesh.nPCEl(iEl));
    mesh.scaledJacAndGradients (iEl,sJ,gSJ);

    for (int l = 0; l < mesh.nBezEl(iEl); l++) {
      double f1 = compute_f1(sJ[l], jacBar);
      Obj += compute_f(sJ[l], jacBar);
      if (_optimizeBarrierMax) {
        Obj += compute_f(sJ[l], barrier_min);
        f1 += compute_f1(sJ[l], barrier_min);
      }
      for (int iPC = 0; iPC < mesh.nPCEl(iEl); iPC++)
        gradObj[mesh.indPCEl(iEl,iPC)] += f1*gSJ[mesh.indGSJ(iEl,l,iPC)];
      minJac = std::min(minJac, sJ[l]);
      maxJac = std::max(maxJac, sJ[l]);
    }
  }

  return true;
}


bool OptHOM::addApproximationErrorObjGrad(double factor, double &Obj, alglib::real_1d_array &gradObj, simpleFunction<double>& fct)
{
  std::vector<double> gradF;
  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
    double f;
    mesh.approximationErrorAndGradients(iEl, f, gradF, 1.e-6, fct);
    Obj += f * factor;
    for (size_t i = 0; i < mesh.nPCEl(iEl); ++i){
      gradObj[mesh.indPCEl(iEl, i)] += gradF[i] * factor;
    }
  }
  //  printf("DIST = %12.5E\n",DISTANCE);
  return true;

}

static void computeGradSFAtNodes (MElement *e, std::vector<std::vector<SVector3> > &gsf)
{
  const nodalBasis &elbasis = *e->getFunctionSpace();
  double s[256][3];
  for (int j=0;j<e->getNumVertices();j++){
    std::vector<SVector3> g(e->getNumVertices());
    double u_mesh = elbasis.points(j,0);
    double v_mesh = elbasis.points(j,1);
    e->getGradShapeFunctions ( u_mesh , v_mesh , 0,  s);
    for (int k=0;k<e->getNumVertices();k++)
      g[k] = SVector3(s[k][0],s[k][1],s[k][2]);
    gsf.push_back(g);
  }
}


bool OptHOM::addBndObjGrad(double factor, double &Obj, alglib::real_1d_array &gradObj)
{
  // set the mesh to its present position
  std::vector<SPoint3> xyz,uvw;
  mesh.getGEntityPositions(xyz,uvw);
  mesh.updateGEntityPositions();

  //could be better (e.g. store the model in the Mesh:: datastrucure)

  GModel *gm = GModel::current();

  // for all model edges, compute the error between the geometry and the mesh

  maxDistCAD = 0.0;
  double distCAD = 0.0;

  for (GModel::eiter it = gm->firstEdge(); it != gm->lastEdge(); ++it){
    // do not do straight lines
    if ((*it)->geomType() == GEntity::Line)continue;
    // look at all mesh lines

    std::vector<bool> doWeCompute((*it)->lines.size());
    for (unsigned int i=0;i<(*it)->lines.size(); i++){
      doWeCompute[i] = false;
      for (unsigned int j=0;j<(*it)->lines[i]->getNumVertices(); j++){
        int index = mesh.getFreeVertexStartIndex((*it)->lines[i]->getVertex(j));
        if (index >=0){
          doWeCompute[i] = true;
          continue;
        }
      }
    }

    std::vector<double> dist((*it)->lines.size());
    for (unsigned int i=0;i<(*it)->lines.size(); i++){
      if (doWeCompute[i]){
        // compute the distance from the geometry to the mesh
        dist[i] = MLineGEdgeDistance ( (*it)->lines[i] , *it );
        maxDistCAD = std::max(maxDistCAD,dist[i]);
        distCAD += dist [i] * factor;
      }
    }
    // be clever to compute the derivative : iterate on all
    // Distance = \sum_{lines} Distance (line, GEdge)
    // For a high order vertex, we compute the derivative only by
    // recomputing the distance to one only line
    const double eps = 1.e-6;
    for (unsigned int i=0;i<(*it)->lines.size(); i++){
      if (doWeCompute[i]){
        for (int j=2 ; j<(*it)->lines[i]->getNumVertices()  ; j++){
          MVertex *v = (*it)->lines[i]->getVertex(j);
          int index = mesh.getFreeVertexStartIndex(v);
          //	printf("%d %d (%d %d)\n",v->getNum(),index,v->onWhat()->tag(),v->onWhat()->dim());
          if (index >= 0){
            double t;
            v->getParameter(0,t);
            SPoint3 pp (v->x(),v->y(),v->z());
            GPoint gp = (*it)->point(t+eps);
            v->setParameter(0,t+eps);
            v->setXYZ(gp.x(),gp.y(),gp.z());
            double dist2 = MLineGEdgeDistance ( (*it)->lines[i] , *it );
            double deriv = (dist2 - dist[i])/eps;
            v->setXYZ(pp.x(),pp.y(),pp.z());
            v->setParameter(0,t);
            //	  printf("%g %g %g\n",dist[i],dist2, MLineGEdgeDistance ( (*it)->lines[i] , *it ));
            // get the index of the vertex
            gradObj[index] += deriv * factor;
          }
        }
      }
      //    printf("done\n");
      // For a low order vertex classified on the GEdge, we recompute
    // two distances for the two MLines connected to the vertex
      for (unsigned int i=0;i<(*it)->lines.size()-1; i++){
        MVertex *v =  (*it)->lines[i]->getVertex(1);
        int index = mesh.getFreeVertexStartIndex(v);
        if (index >= 0){
          double t;
          v->getParameter(0,t);
          SPoint3 pp (v->x(),v->y(),v->z());
          GPoint gp = (*it)->point(t+eps);
          v->setParameter(0,t+eps);
          v->setXYZ(gp.x(),gp.y(),gp.z());
          MLine *l1 = (*it)->lines[i];
          MLine *l2 = (*it)->lines[i+1];
          //	printf("%d %d -- %d %d\n",l1->getVertex(0)->getNum(),l1->getVertex(1)->getNum(),l2->getVertex(0)->getNum(),l2->getVertex(1)->getNum());
          double deriv =
            (MLineGEdgeDistance ( l1 , *it ) - dist[i])  /eps +
            (MLineGEdgeDistance ( l2 , *it ) - dist[i+1])/eps;
          v->setXYZ(pp.x(),pp.y(),pp.z());
          v->setParameter(0,t);
          gradObj[index] += deriv * factor;
        }
      }
    }
  }
  //  printf("computing distance : 1D part %12.5E\n",distCAD);

  // now the 3D part !

  std::vector<std::vector<SVector3> > gsfT;
  computeGradSFAtNodes ( (*gm->firstFace())->triangles[0],gsfT);

  std::map<MVertex*,SVector3> normalsToCAD;


  for(GModel::fiter it = gm->firstFace(); it != gm->lastFace(); ++it){
    // do not do plane surfaces
    if ((*it)->geomType() == GEntity::Plane)continue;
    std::map<MTriangle*,double> dist;

    std::vector<bool> doWeCompute((*it)->triangles.size());
    for (unsigned int i=0;i<(*it)->triangles.size(); i++){
      doWeCompute[i] = false;
      for (unsigned int j=0;j<(*it)->triangles[i]->getNumVertices(); j++){
        int index = mesh.getFreeVertexStartIndex((*it)->triangles[i]->getVertex(j));
        if (index >=0){
          doWeCompute[i] = true;
        }
      }
      if (doWeCompute[i]){
        for (unsigned int j=0;j<(*it)->triangles[i]->getNumVertices(); j++){
          MVertex *v = (*it)->triangles[i]->getVertex(j);
          if (normalsToCAD.find(v) == normalsToCAD.end()){
            SPoint2 p_cad;
            reparamMeshVertexOnFace(v, *it, p_cad);
            SVector3 tg_cad = (*it)->normal(p_cad);
            tg_cad.normalize();
            normalsToCAD[v] = tg_cad;
          }
        }
      }
    }

    for (unsigned int i=0;i<(*it)->triangles.size(); i++){
      // compute the distance from the geometry to the mesh
      if(doWeCompute[i]){
        const double d = MFaceGFaceDistanceOld((*it)->triangles[i], *it, &gsfT, &normalsToCAD);
        dist[(*it)->triangles[i]] = d;
        maxDistCAD = std::max(maxDistCAD,d);
        distCAD += d * factor;
      }
    }

    // be clever again to compute the derivatives
    const double eps = 1.e-6;
    for (unsigned int i=0;i<(*it)->triangles.size(); i++){
      if(doWeCompute[i]){
        for (unsigned int j=0;j<(*it)->triangles[i]->getNumVertices(); j++){
          //    for (; itm !=v2t.end(); ++itm){
          MVertex   *v = (*it)->triangles[i]->getVertex(j);
          if(v->onWhat()->dim() == 1){
            int index = mesh.getFreeVertexStartIndex(v);
            if (index >= 0){
              MTriangle *t = (*it)->triangles[i];
              GEdge *ge = v->onWhat()->cast2Edge();
              double t_;
              v->getParameter(0,t_);
              SPoint3 pp (v->x(),v->y(),v->z());
              GPoint gp = ge->point(t_+eps);
              v->setParameter(0,t_+eps);
              v->setXYZ(gp.x(),gp.y(),gp.z());
              const double distT = dist[t];
              double deriv =  (MFaceGFaceDistanceOld(t, *it, &gsfT, &normalsToCAD) - distT) /eps;
              v->setXYZ(pp.x(),pp.y(),pp.z());
              v->setParameter(0,t_);
              gradObj[index] += deriv * factor;
            }
          }

          if(v->onWhat() == *it){
            int index = mesh.getFreeVertexStartIndex(v);
            if (index >= 0){
              MTriangle *t = (*it)->triangles[i];
              double uu,vv;
              v->getParameter(0,uu);
              v->getParameter(1,vv);
              SPoint3 pp (v->x(),v->y(),v->z());

              const double distT = dist[t];

              GPoint gp = (*it)->point(uu+eps,vv);
              v->setParameter(0,uu+eps);
              v->setXYZ(gp.x(),gp.y(),gp.z());
              double deriv = (MFaceGFaceDistanceOld(t, *it, &gsfT, &normalsToCAD) - distT) /eps;
              v->setXYZ(pp.x(),pp.y(),pp.z());
              v->setParameter(0,uu);
              gradObj[index] += deriv * factor;

              gp = (*it)->point(uu,vv+eps);
              v->setParameter(1,vv+eps);
              v->setXYZ(gp.x(),gp.y(),gp.z());
              deriv = (MFaceGFaceDistanceOld(t, *it, &gsfT, &normalsToCAD) - distT) /eps;
              v->setXYZ(pp.x(),pp.y(),pp.z());
              v->setParameter(1,vv);
              gradObj[index+1] += deriv * factor;
            }
          }
        }
      }
    }
  }
  mesh.updateGEntityPositions(xyz,uvw);
  Obj +=distCAD;
  //  printf("computing distance : 2D part %12.5E\n",distCAD);
  //  printf("%22.15E\n",distCAD);
  return true;
}



bool OptHOM::addMetricMinObjGrad(double &Obj, alglib::real_1d_array &gradObj)
{

  minJac = 1.e300;
  maxJac = -1.e300;

  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
    // Scaled Jacobians
    std::vector<double> sJ(mesh.nBezEl(iEl));
    // Gradients of scaled Jacobians
    std::vector<double> gSJ(mesh.nBezEl(iEl)*mesh.nPCEl(iEl));
    mesh.metricMinAndGradients (iEl,sJ,gSJ);

    for (int l = 0; l < mesh.nBezEl(iEl); l++) {
      Obj += compute_f(sJ[l], jacBar);
      const double f1 = compute_f1(sJ[l], jacBar);
      for (int iPC = 0; iPC < mesh.nPCEl(iEl); iPC++)
        gradObj[mesh.indPCEl(iEl,iPC)] += f1*gSJ[mesh.indGSJ(iEl,l,iPC)];
      minJac = std::min(minJac, sJ[l]);
      maxJac = std::max(maxJac, sJ[l]);
    }
  }
  return true;
}

// Contribution of the vertex distance to the objective function value and
// gradients
bool OptHOM::addDistObjGrad(double Fact, double &Obj,
                            alglib::real_1d_array &gradObj)
{
  maxDist = 0;
  avgDist = 0;
  int nbBnd = 0;

  for (int iFV = 0; iFV < mesh.nFV(); iFV++) {
    const double dSq = mesh.distSq(iFV), dist = sqrt(dSq);
    Obj += Fact * dSq;
    std::vector<double> gDSq(mesh.nPCFV(iFV));
    mesh.gradDistSq(iFV,gDSq);
    for (int iPC = 0; iPC < mesh.nPCFV(iFV); iPC++)
      gradObj[mesh.indPCFV(iFV,iPC)] += Fact*gDSq[iPC];
    maxDist = std::max(maxDist, dist);
    avgDist += dist;
    nbBnd++;
  }
  if (nbBnd != 0) avgDist /= nbBnd;

  //  printf("DISTANCE %22.15E\n",avgDist);

  return true;
}

// FIXME TEST
// Assume a unit square centered on 0,0
// fct is
//class toto : public simpleFunction<double>
//{
//public :
//  double operator () (double x, double y, double z) const{
//    const double r = sqrt(x*x+y*y);
//    const double r0 = .3;
//  const double f = atan(20*(x));
//    return f;
//  }
//};


void OptHOM::evalObjGrad(const alglib::real_1d_array &x, double &Obj,
                         alglib::real_1d_array &gradObj)
{
  NEVAL++;
  mesh.updateMesh(x.getcontent());

  Obj = 0.;
  for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;

  //  printf("Computing Obj : ");
  /// control Jacobians
  addJacObjGrad(Obj, gradObj);
  /// Control distance to the straight sided mesh
  addDistObjGrad(lambda, Obj, gradObj);

  if(_optimizeMetricMin)
    addMetricMinObjGrad(Obj, gradObj);
  if(_optimizeCAD)
    addBndObjGrad(lambda3, Obj, gradObj);

  //  printf("Obj = %12.5E\n",Obj);

  if ((minJac > barrier_min) && (maxJac < barrier_max || !_optimizeBarrierMax) && (maxDistCAD < distance_max|| !_optimizeCAD) ) {
    Msg::Info("Reached %s (%g %g) requirements, setting null gradient",
              _optimizeMetricMin ? "svd" : "jacobian", minJac, maxJac);
    Obj = 0.;
    for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;
  }
}

void evalObjGradFunc(const alglib::real_1d_array &x, double &Obj,
                     alglib::real_1d_array &gradObj, void *HOInst)
{
  (static_cast<OptHOM*>(HOInst))->evalObjGrad(x, Obj, gradObj);
}


void OptHOM::recalcJacDist()
{
  maxDist = 0;
  avgDist = 0;
  int nbBnd = 0;

  for (int iFV = 0; iFV < mesh.nFV(); iFV++) {
    if (mesh.forced(iFV)) {
      double dSq = mesh.distSq(iFV);
      maxDist = std::max(maxDist, sqrt(dSq));
      avgDist += sqrt(dSq);
      nbBnd++;
    }
  }
  if (nbBnd != 0) avgDist /= nbBnd;

  minJac = 1.e300;
  maxJac = -1.e300;
  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
    // Scaled Jacobians
    std::vector<double> sJ(mesh.nBezEl(iEl));
    // (Dummy) gradients of scaled Jacobians
    std::vector<double> dumGSJ(mesh.nBezEl(iEl)*mesh.nPCEl(iEl));
    mesh.scaledJacAndGradients (iEl,sJ,dumGSJ);
    if(_optimizeMetricMin)
      mesh.metricMinAndGradients (iEl,sJ,dumGSJ);
    for (int l = 0; l < mesh.nBezEl(iEl); l++) {
      minJac = std::min(minJac, sJ[l]);
      maxJac = std::max(maxJac, sJ[l]);
    }
  }
}

void OptHOM::printProgress(const alglib::real_1d_array &x, double Obj)
{
  iter++;

  if (iter % progressInterv == 0) {
    Msg::Info("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E) "
              "-- minJ = %12.5E  maxJ = %12.5E Max D = %12.5E Avg D = %12.5E",
              iter, Obj, Obj/initObj, minJac, maxJac, maxDist, avgDist);
  }
}

void printProgressFunc(const alglib::real_1d_array &x, double Obj, void *HOInst)
{
  ((OptHOM*)HOInst)->printProgress(x,Obj);
}

void OptHOM::calcScale(alglib::real_1d_array &scale)
{
  scale.setlength(mesh.nPC());

  // Calculate scale
  for (int iFV = 0; iFV < mesh.nFV(); iFV++) {
    std::vector<double> scaleFV(mesh.nPCFV(iFV),1.);
    mesh.pcScale(iFV,scaleFV);
    for (int iPC = 0; iPC < mesh.nPCFV(iFV); iPC++)
      scale[mesh.indPCFV(iFV,iPC)] = scaleFV[iPC];
  }
}


void OptHOM::OptimPass(alglib::real_1d_array &x, int itMax)
{

  static const double EPSG = 0.;
  static const double EPSF = 0.;
  static const double EPSX = 0.;
  static int OPTMETHOD = 1;

  Msg::Info("--- Optimization pass with initial jac. range (%g, %g), jacBar = %g",
            minJac, maxJac, jacBar);

  iter = 0;

  alglib::real_1d_array scale;
  calcScale(scale);

  int iterationscount = 0, nfev = 0, terminationtype = -1;
  if (OPTMETHOD == 1) {
    alglib::mincgstate state;
    alglib::mincgreport rep;
    try{
      mincgcreate(x, state);
      mincgsetscale(state,scale);
      mincgsetprecscale(state);
      mincgsetcond(state, EPSG, EPSF, EPSX, itMax);
      mincgsetxrep(state, true);
      alglib::mincgoptimize(state, evalObjGradFunc, printProgressFunc, this);
      mincgresults(state, x, rep);
    }
    catch(alglib::ap_error e){
      Msg::Error("%s", e.msg.c_str());
    }
    iterationscount = rep.iterationscount;
    nfev = rep.nfev;
    terminationtype = rep.terminationtype;
  }
  else {
    alglib::minlbfgsstate state;
    alglib::minlbfgsreport rep;
    try{
      minlbfgscreate(3, x, state);
      minlbfgssetscale(state,scale);
      minlbfgssetprecscale(state);
      minlbfgssetcond(state, EPSG, EPSF, EPSX, itMax);
      minlbfgssetxrep(state, true);
      alglib::minlbfgsoptimize(state, evalObjGradFunc, printProgressFunc, this);
      minlbfgsresults(state, x, rep);
    }
    catch(alglib::ap_error e){
      Msg::Error("%s", e.msg.c_str());
    }
    iterationscount = rep.iterationscount;
    nfev = rep.nfev;
    terminationtype = rep.terminationtype;
  }

  Msg::Info("Optimization finalized after %d iterations (%d function evaluations),",
            iterationscount, nfev);
  switch(int(terminationtype)) {
  case 1: Msg::Info("because relative function improvement is no more than EpsF"); break;
  case 2: Msg::Info("because relative step is no more than EpsX"); break;
  case 4: Msg::Info("because gradient norm is no more than EpsG"); break;
  case 5: Msg::Info("because the maximum number of steps was taken"); break;
  default: Msg::Info("with code %d", int(terminationtype)); break;
  }
}


int OptHOM::optimize(double weight, double weightCAD, double b_min,
                     double b_max, bool optimizeMetricMin, int pInt,
                     int itMax, int optPassMax, int optCAD, double distanceMax, double tolerance)
{
  barrier_min = b_min;
  barrier_max = b_max;
  distance_max = distanceMax;
  progressInterv = pInt;
//  powM = 4;
//  powP = 3;

  _optimizeMetricMin = optimizeMetricMin;
  _optimizeCAD = optCAD;
  // Set weights & length scale for non-dimensionalization
  lambda = weight;
  lambda3 = weightCAD;
  geomTol = tolerance;
  std::vector<double> dSq(mesh.nEl());
  mesh.distSqToStraight(dSq);
  const double maxDSq = *max_element(dSq.begin(),dSq.end());
  if (maxDSq < 1.e-10) {                                        // Length scale for non-dim. distance
    std::vector<double> sSq(mesh.nEl());
    mesh.elSizeSq(sSq);
    const double maxSSq = *max_element(sSq.begin(),sSq.end());
    invLengthScaleSq = 1./maxSSq;
  }
  else invLengthScaleSq = 1./maxDSq;

  // Set initial guess
  alglib::real_1d_array x;
  x.setlength(mesh.nPC());
  mesh.getUvw(x.getcontent());

  // Calculate initial performance
  recalcJacDist();
  initMaxDist = maxDist;
  initAvgDist = avgDist;

  const double jacBarStart = (minJac > 0.) ? 0.9*minJac : 1.1*minJac;
  jacBar = jacBarStart;

  _optimizeBarrierMax = false;
  // Calculate initial objective function value and gradient
  initObj = 0.;
  alglib::real_1d_array gradObj;
  gradObj.setlength(mesh.nPC());
  for (int i = 0; i < mesh.nPC(); i++) gradObj[i] = 0.;
  evalObjGrad(x, initObj, gradObj);

  Msg::Info("Start optimizing %d elements (%d vertices, %d free vertices, %d variables) "
            "with min barrier %g and max. barrier %g", mesh.nEl(), mesh.nVert(),
            mesh.nFV(), mesh.nPC(), barrier_min, barrier_max);

  int ITER = 0;
  bool minJacOK = true;

  while (minJac < barrier_min || (maxDistCAD > distance_max && _optimizeCAD)) {
    const double startMinJac = minJac;
    NEVAL = 0;
    OptimPass(x, itMax);
    printf("######  NEVAL = %d\n",NEVAL);
    recalcJacDist();
    jacBar = (minJac > 0.) ? 0.9*minJac : 1.1*minJac;
    if (_optimizeCAD)   jacBar = std::min(jacBar,barrier_min);
    if (ITER ++ > optPassMax) {
      minJacOK = (minJac > barrier_min && (maxDistCAD < distance_max || !_optimizeCAD));
      break;
    }
    if (fabs((minJac-startMinJac)/startMinJac) < 0.01) {
      Msg::Info("Stagnation in minJac detected, stopping optimization");
      minJacOK = false;
      break;
    }
  }

  ITER = 0;
  if (minJacOK && (!_optimizeMetricMin)) {
    _optimizeBarrierMax = true;
    jacBar =  1.1 * maxJac;
    while (maxJac > barrier_max ) {
      const double startMaxJac = maxJac;
      OptimPass(x, itMax);
      recalcJacDist();
      jacBar =  1.1 * maxJac;
      if (ITER ++ > optPassMax) break;
      if (fabs((maxJac-startMaxJac)/startMaxJac) < 0.01) {
        Msg::Info("Stagnation in maxJac detected, stopping optimization");
        break;
      }
    }
  }

  Msg::Info("Optimization done Range (%g,%g)", minJac, maxJac);

  if (minJac > barrier_min && maxJac < barrier_max) return 1;
  if (minJac > 0.0) return 0;
  return -1;
}

#endif
