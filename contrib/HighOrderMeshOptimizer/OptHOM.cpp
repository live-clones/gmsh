#include <iostream>
#include <algorithm>
#include "OptHomMesh.h"
#include "OptHOM.h"
#include "OptHomRun.h"
#include "GmshMessage.h"
#include "GmshConfig.h"

#ifdef HAVE_BFGS

#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"



// Constructor
OptHOM::OptHOM(GEntity *ge, const std::set<MElement*> &els, std::set<MVertex*> & toFix, int method) :
       mesh(ge, els, toFix, method)
{
};



// Contribution of the element Jacobians to the objective function value and gradients (2D version)
bool OptHOM::addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj)
{

  minJac = 1.e300;
  maxJac = -1.e300;

  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
    std::vector<double> sJ(mesh.nBezEl(iEl));                   // Scaled Jacobians
    std::vector<double> gSJ(mesh.nBezEl(iEl)*mesh.nPCEl(iEl));  // Gradients of scaled Jacobians
    mesh.scaledJacAndGradients (iEl,sJ,gSJ);
    
    for (int l = 0; l < mesh.nBezEl(iEl); l++) {
      Obj += compute_f(sJ[l]);
      const double f1 = compute_f1(sJ[l]);
      for (int iPC = 0; iPC < mesh.nPCEl(iEl); iPC++)
        gradObj[mesh.indPCEl(iEl,iPC)] += f1*gSJ[mesh.indGSJ(iEl,l,iPC)];
      minJac = std::min(minJac,sJ[l]);
      maxJac = std::max(maxJac,sJ[l]);
    }
  }

  return true;

}



// Contribution of the vertex distance to the objective function value and gradients (2D version)
bool OptHOM::addDistObjGrad(double Fact, double Fact2, double &Obj, alglib::real_1d_array &gradObj)
{

  maxDist = 0;
  avgDist = 0;
  int nbBnd = 0;

  for (int iFV = 0; iFV < mesh.nFV(); iFV++) {
    const double Factor = invLengthScaleSq*(mesh.forced(iFV) ? Fact : Fact2);
    const double dSq = mesh.distSq(iFV), dist = sqrt(dSq);
    Obj += Factor * dSq;
    std::vector<double> gDSq(mesh.nPCFV(iFV));
    mesh.gradDistSq(iFV,gDSq);
    for (int iPC = 0; iPC < mesh.nPCFV(iFV); iPC++) gradObj[mesh.indPCFV(iFV,iPC)] += Factor*gDSq[iPC];
    maxDist = std::max(maxDist, dist);
    avgDist += dist;
    nbBnd++;
  }
  if (nbBnd != 0) avgDist /= nbBnd;

  return true;

}



void OptHOM::evalObjGrad(const alglib::real_1d_array &x, double &Obj, alglib::real_1d_array &gradObj)
{

  mesh.updateMesh(x.getcontent());

  Obj = 0.;
  for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;

  addJacObjGrad(Obj, gradObj);
  addDistObjGrad(lambda, lambda2, Obj, gradObj);

  if ((minJac > barrier_min) && (maxJac < barrier_max)) {
    printf("INFO: reached Jacobian requirements, setting null gradient\n");
    Obj = 0.;
    for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;
  }

}



void evalObjGradFunc(const alglib::real_1d_array &x, double &Obj, alglib::real_1d_array &gradObj, void *HOInst)
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
    std::vector<double> sJ(mesh.nBezEl(iEl));                       // Scaled Jacobians
    std::vector<double> dumGSJ(mesh.nBezEl(iEl)*mesh.nPCEl(iEl));   // (Dummy) gradients of scaled Jacobians
    mesh.scaledJacAndGradients (iEl,sJ,dumGSJ);
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
    printf("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E) -- minJ = %12.5E  maxJ = %12.5E Max D = %12.5E Avg D = %12.5E\n", iter, Obj, Obj/initObj, minJac, maxJac, maxDist, avgDist);
    Msg::Debug("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E) -- minJ = %12.5E  maxJ = %12.5E Max D = %12.5E Avg D = %12.5E", iter, Obj, Obj/initObj, minJac, maxJac, maxDist, avgDist);
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
    for (int iPC = 0; iPC < mesh.nPCFV(iFV); iPC++) scale[mesh.indPCFV(iFV,iPC)] = scaleFV[iPC];
  }

}



void OptHOM::OptimPass(alglib::real_1d_array &x, const alglib::real_1d_array &initGradObj, int itMax)
{

  static const double EPSG = 0.;
  static const double EPSF = 0.;
  static const double EPSX = 0.;
  static int OPTMETHOD = 1;

  Msg::Debug("--- Optimization pass with jacBar = %12.5E",jacBar);

  iter = 0;

  alglib::real_1d_array scale;
  calcScale(scale);

  int iterationscount = 0, nfev = 0, terminationtype = -1;
  if (OPTMETHOD == 1) {
    alglib::mincgstate state;
    alglib::mincgreport rep;
    mincgcreate(x, state);
    mincgsetscale(state,scale);
    mincgsetprecscale(state);
    mincgsetcond(state, EPSG, EPSF, EPSX, itMax);
    mincgsetxrep(state, true);
    alglib::mincgoptimize(state, evalObjGradFunc, printProgressFunc, this);
    mincgresults(state, x, rep);
    iterationscount = rep.iterationscount;
    nfev = rep.nfev;
    terminationtype = rep.terminationtype;
  }
  else {
    alglib::minlbfgsstate state;
    alglib::minlbfgsreport rep;
    minlbfgscreate(3, x, state);
    minlbfgssetscale(state,scale);
    minlbfgssetprecscale(state);
    minlbfgssetcond(state, EPSG, EPSF, EPSX, itMax);
    minlbfgssetxrep(state, true);
    alglib::minlbfgsoptimize(state, evalObjGradFunc, printProgressFunc, this);
    minlbfgsresults(state, x, rep);
    iterationscount = rep.iterationscount;
    nfev = rep.nfev;
    terminationtype = rep.terminationtype;
  }

  std::cout << "Optimization finalized after " << iterationscount << " iterations (" << nfev << " functions evaluations)";
  switch(int(terminationtype)) {
  case 1: std::cout << ", because relative function improvement is no more than EpsF"; break;
  case 2: std::cout << ", because relative step is no more than EpsX"; break;
  case 4: std::cout << ", because gradient norm is no more than EpsG"; break;
  case 5: std::cout << ", because the maximum number of steps was taken"; break;
  default: std::cout << " with code " << int(terminationtype); break;
  }
  std::cout << "." << std::endl;

}



int OptHOM::optimize(double weightFixed, double weightFree, double b_min, double b_max, int pInt, int itMax)
{

  barrier_min = b_min;
  barrier_max = b_max;
  progressInterv = pInt;
//  powM = 4;
//  powP = 3;

  // Set weights & length scale for non-dimensionalization
  lambda = weightFixed;
  lambda2 = weightFree;
  std::vector<double> dSq(mesh.nVert());
  mesh.distSqToStraight(dSq);
  const double maxDSq = *max_element(dSq.begin(),dSq.end());
  invLengthScaleSq = 1./maxDSq;  // Length scale for non-dimensional distance

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
  setBarrierTerm(jacBarStart);

  // Calculate initial objective function value and gradient
  initObj = 0.;
  alglib::real_1d_array gradObj;
  gradObj.setlength(mesh.nPC());
  for (int i = 0; i < mesh.nPC(); i++) gradObj[i] = 0.;
  evalObjGrad(x, initObj, gradObj);


  std::cout << "Start optimizing " << mesh.nEl() << " elements (" << mesh.nVert() << " vertices, "
            << mesh.nFV() << " free vertices, " << mesh.nPC() << " variables) with min. barrier = " << barrier_min
            << " and max. barrier = " << barrier_max << std::endl;

  int ITER = 0;
  while (minJac < barrier_min || maxJac > barrier_max ) {
    OptimPass(x, gradObj, itMax);
    recalcJacDist();
    jacBar = (minJac > 0.) ? 0.9*minJac : 1.1*minJac;
    setBarrierTerm(jacBar);
    if (ITER ++ > 50) break;
  }

  //  for (int i = 0; i<3; i++) {
  //    lambda *= 100;
  //    OptimPass(x, gradObj, itMax);
  //  }

  OptHomMessage("Optimization done Range (%g,%g)",minJac,maxJac);

  if (minJac > barrier_min && maxJac < barrier_max) return 1;
  if (minJac > 0.0) return 0;
  return -1;

}



#endif
