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
OptHOM::OptHOM(GEntity *ge, std::set<MVertex*> & toFix, int method) :
       mesh(ge, toFix, method)
{
};

// Contribution of the element Jacobians to the objective function value and gradients (2D version)
bool OptHOM::addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj)
{

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
    }
  }

  return true;

}



// Contribution of the vertex distance to the objective function value and gradients (2D version)
bool OptHOM::addDistObjGrad(double Fact, double Fact2, double &Obj, alglib::real_1d_array &gradObj)
{

  for (int iFV = 0; iFV < mesh.nFV(); iFV++) {
    const double Factor = invLengthScaleSq*(mesh.forced(iFV) ? Fact : Fact2);
    Obj += Factor * mesh.distSq(iFV);
    std::vector<double> gDSq(mesh.nPCFV(iFV));
    mesh.gradDistSq(iFV,gDSq);
    for (int iPC = 0; iPC < mesh.nPCFV(iFV); iPC++) gradObj[mesh.indPCFV(iFV,iPC)] += Factor*gDSq[iPC];
  }

  return true;

}



void OptHOM::evalObjGrad(const alglib::real_1d_array &x, double &Obj, alglib::real_1d_array &gradObj)
{

  mesh.updateMesh(x.getcontent());

  Obj = 0.;
  for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;

  addJacObjGrad(Obj, gradObj);
  addDistObjGrad(lambda, lambda2, Obj, gradObj);

  //  if ((minJac > barrier_min) && (maxJac < barrier_max)) {
  //    printf("INFO: reached Jacobian requirements, setting null gradient\n");
  //    Obj = 0.;
  //    for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;
  //  }
}



void evalObjGradFunc(const alglib::real_1d_array &x, double &Obj, alglib::real_1d_array &gradObj, void *HOInst)
{
  OptHOM &HO = *static_cast<OptHOM*> (HOInst);
  HO.evalObjGrad(x, Obj, gradObj);
  double distMaxBnd, distAvgBnd, minJac, maxJac;
  HO.getDistances(distMaxBnd, distAvgBnd, minJac, maxJac);
  if (minJac > HO.barrier_min && maxJac < HO.barrier_max) {
   for (int i = 0; i < gradObj.length(); ++i) {
      gradObj[i] = 0;
    }
  }
}



void OptHOM::getDistances(double &distMaxBND, double &distAvgBND, double &minJac, double &maxJac)
{

  distMaxBND = 0;
  distAvgBND = 0;
  int nbBnd = 0;

  for (int iFV = 0; iFV < mesh.nFV(); iFV++) {
    if (mesh.forced(iFV)) {
      double dSq = mesh.distSq(iFV);
      distMaxBND = std::max(distMaxBND, sqrt(dSq));
      distAvgBND += sqrt(dSq);
      nbBnd++;
    }
  }
  if (nbBnd != 0) distAvgBND /= nbBnd;

  minJac = 1000;
  maxJac = -1000;
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

  if (iter % progressInterv == 0) {
    double maxD, avgD, minJ, maxJ;
    getDistances(maxD, avgD, minJ, maxJ);

        printf("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E) -- minJ = %12.5E  maxJ = %12.5E Max D = %12.5E Avg D = %12.5E\n", iter, Obj, Obj/initObj, minJ, maxJ, maxD, avgD);
    Msg::Debug("--> Iteration %3d --- OBJ %12.5E (relative decrease = %12.5E) -- minJ = %12.5E  maxJ = %12.5E Max D = %12.5E Avg D = %12.5E", iter, Obj, Obj/initObj, minJ, maxJ, maxD, avgD);
  }

}



void printProgressFunc(const alglib::real_1d_array &x, double Obj, void *HOInst)
{
  ((OptHOM*)HOInst)->printProgress(x,Obj);
}



void OptHOM::OptimPass(alglib::real_1d_array &x, const alglib::real_1d_array &initGradObj, int itMax)
{
  static const double EPSG = 0.;
  static const double EPSF = 1.e-8;
//  static const double EPSF = 0.;
  static const double EPSX = 0.;
//  const double EPSX = x.length()*1.e-4/sqrt(invLengthScaleSq);
//  std::cout << "DEBUG: EPSX = " << EPSX << ", EPSX/x.length() = " << EPSX/x.length() << std::endl;

//  double iGONorm = 0;
//  for (int i=0; i<initGradObj.length(); i++) iGONorm += initGradObj[i]*initGradObj[i];
//  const double EPSG = 1.e-2*sqrt(iGONorm);

  Msg::Debug("--- Optimization pass with jacBar = %12.5E",jacBar);

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

  //  std::cout << "Optimization finalized after " << rep.iterationscount << " iterations (" << rep.nfev << " functions evaluations)";
  //    switch(int(rep.terminationtype)) {
//  case -2: std::cout << ", because rounding errors prevented further improvement"; break;
//  case -1: std::cout << ", because incorrect parameters were specified"; break;
//  case 1: std::cout << ", because relative function improvement is no more than EpsF"; break;
//  case 2: std::cout << ", because relative step is no more than EpsX"; break;
//  case 4: std::cout << ", because gradient norm is no more than EpsG"; break;
//  case 5: std::cout << ", because the maximum number of steps was taken"; break;
//  case 7: std::cout << ", because stopping conditions are too stringent, further improvement is impossible"; break;
//  default: std::cout << " with code " << int(rep.terminationtype); break;
//  }
//  std::cout << "." << std::endl;

}



int OptHOM::optimize(double weightFixed, double weightFree, double b_min, double b_max, int pInt, int itMax)
{
  double minJ,maxJ;
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
  //  printf("DISTANCE TO STRAIGHT = %12.5E\n",maxDSq);


  // Set initial guess
  alglib::real_1d_array x;
  x.setlength(mesh.nPC());
  mesh.getUvw(x.getcontent());

  // Calculate initial performance
  //  double minJ, maxJ;
  double initMaxD, initAvgD;
  getDistances(initMaxD, initAvgD, minJ, maxJ);

  const double jacBarStart = (minJ > 0.) ? 0.9*minJ : 1.1*minJ;
  jacBar = jacBarStart;
  setBarrierTerm(jacBarStart);
  //  std::cout << "DEBUG: jacBarStart = " << jacBarStart << std::endl;

  // Calculate initial objective function value and gradient
  initObj = 0.;
  alglib::real_1d_array gradObj;
  gradObj.setlength(mesh.nPC());
  //  printf("mesh.npc = %d\n",mesh.nPC());
  for (int i = 0; i < mesh.nPC(); i++) gradObj[i] = 0.;
  evalObjGrad(x, initObj, gradObj);


  //  std::cout << "Start optimizing with barrier = " << barrier_min << std::endl;

  int ITER = 0;
  while (minJ < barrier_min || maxJ > barrier_max ) {
    OptimPass(x, gradObj, itMax);
    double dumMaxD, dumAvgD;
    getDistances(dumMaxD, dumAvgD, minJ, maxJ);
    jacBar = (minJ > 0.) ? 0.9*minJ : 1.1*minJ;
    setBarrierTerm(jacBar);
    if (ITER ++ > 15) break;
  }

  //  for (int i = 0; i<3; i++) {
  //    lambda *= 100;
  //    OptimPass(x, gradObj, itMax);
  //  }

  double finalObj = 0., finalMaxD, finalAvgD;
  evalObjGrad(x, finalObj, gradObj);
  getDistances(finalMaxD, finalAvgD, minJ, maxJ);
  OptHomMessage("Optimization done Range (%g,%g)",minJ,maxJ);

  if (minJ < barrier_min && maxJ > barrier_max) return 0;
  if (minJ > 0.0) return 1;
  return -1;
}



#endif
