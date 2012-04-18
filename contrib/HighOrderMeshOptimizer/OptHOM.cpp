#include <iostream>
#include <algorithm>
#include "OptHomMesh.h"
#include "OptHOM.h"
#include "GmshConfig.h"

#ifdef HAVE_BFGS

#include "ap.h"
#include "alglibinternal.h"
#include "alglibmisc.h"
#include "linalg.h"
#include "optimization.h"



// Constructor
OptHOM::OptHOM(GEntity *ge, std::set<MVertex*> & toFix, int method) :
       mesh(ge, toFix, method)
{
};

// Contribution of the element Jacobians to the objective function value and gradients (2D version)
bool OptHOM::addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj)
{

  minJac = 1.e300;
  maxJac = -1.e300;

  for (int iEl = 0; iEl < mesh.nEl(); iEl++) {
    std::vector<double> sJ(mesh.nBezEl(iEl));                   // Scaled Jacobians
    mesh.scaledJac(iEl,sJ);
    std::vector<double> gSJ(mesh.nBezEl(iEl)*mesh.nPCEl(iEl));  // Gradients of scaled Jacobians
    mesh.gradScaledJac(iEl,gSJ);
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

  if (minJac > barrier) printf("INFO: reached minimum Jacobian requirement, setting null gradient\n");
  else {
    addJacObjGrad(Obj, gradObj);
    addDistObjGrad(lambda, lambda2, Obj, gradObj);
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
    std::vector<double> sJ(mesh.nBezEl(iEl));                   // Scaled Jacobians
    mesh.scaledJac(iEl,sJ);
    for (int l = 0; l < mesh.nBezEl(iEl); l++) {
      minJac = std::min(minJac, sJ[l]);
      maxJac = std::max(maxJac, sJ[l]);
    }
  }

}



void OptHOM::printProgress(const alglib::real_1d_array &x, double Obj)
{

  iter++;
  if (iter % progressInterv == 0) printf("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E) -- minJ = %12.5E  maxJ = %12.5E Max D = %12.5E Avg D = %12.5E\n", iter, Obj, Obj/initObj, minJac, maxJac, maxDist, avgDist);

}



void printProgressFunc(const alglib::real_1d_array &x, double Obj, void *HOInst)
{
  ((OptHOM*)HOInst)->printProgress(x,Obj);
}



void OptHOM::OptimPass(alglib::real_1d_array &x, const alglib::real_1d_array &initGradObj, int itMax)
{

  static const double EPSG = 0.;
  static const double EPSF = 0.;
  static const double EPSX = 0.;

  std::cout << "--- Optimization pass with jacBar = " << jacBar << ", lambda = " << lambda << ", lambda2 = " << lambda2 << std::endl;

//  alglib::minlbfgsstate state;
//  alglib::minlbfgsreport rep;
  alglib::mincgstate state;
  alglib::mincgreport rep;

//  minlbfgscreate(3, x, state);
//  minlbfgssetcond(state, EPSG, EPSF, EPSX, itMax);
//  minlbfgssetxrep(state, true);
  mincgcreate(x, state);
  mincgsetcond(state, EPSG, EPSF, EPSX, itMax);
  mincgsetxrep(state, true);

  iter = 0;

//  alglib::minlbfgsoptimize(state, evalObjGradFunc, printProgressFunc, this);
  alglib::mincgoptimize(state, evalObjGradFunc, printProgressFunc, this);

//  minlbfgsresults(state, x, rep);
  mincgresults(state, x, rep);

  std::cout << "Optimization finalized after " << rep.iterationscount << " iterations (" << rep.nfev << " functions evaluations)";
  switch(int(rep.terminationtype)) {
//  case -2: std::cout << ", because rounding errors prevented further improvement"; break;
//  case -1: std::cout << ", because incorrect parameters were specified"; break;
  case 1: std::cout << ", because relative function improvement is no more than EpsF"; break;
  case 2: std::cout << ", because relative step is no more than EpsX"; break;
  case 4: std::cout << ", because gradient norm is no more than EpsG"; break;
  case 5: std::cout << ", because the maximum number of steps was taken"; break;
//  case 7: std::cout << ", because stopping conditions are too stringent, further improvement is impossible"; break;
  default: std::cout << " with code " << int(rep.terminationtype); break;
  }
  std::cout << "." << std::endl;

}



int OptHOM::optimize(double weightFixed, double weightFree, double barrier_, int pInt, int itMax)
{
  barrier = barrier_;
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

  std::cout << "Initial mesh: Obj = " << initObj << ", minJ = " << minJac << ", maxJ = " << maxJac << ", maxD = " << initMaxDist << ", avgD = " << initAvgDist << std::endl;

  std::cout << "Start optimizing " << mesh.nEl() << " elements (" << mesh.nVert() << " vertices, "
            << mesh.nFV() << " free vertices, " << mesh.nPC() << " variables) with barrier = " << barrier << std::endl;

  while (minJac < barrier) {
    OptimPass(x, gradObj, itMax);
    jacBar = (minJac > 0.) ? 0.9*minJac : 1.1*minJac;
    setBarrierTerm(jacBar);
  }

//  for (int i = 0; i<3; i++) {
//    lambda *= 10;
//    OptimPass(x, gradObj, itMax);
//  }

  double finalObj = 0.;
  evalObjGrad(x, finalObj, gradObj);
  std::cout << "Final mesh: Obj = " << finalObj << ", maxD = " << maxDist << ", avgD = " << avgDist << ", minJ = " << minJac << ", maxJ = " << maxJac << std::endl;

  return 0;

}



#endif
