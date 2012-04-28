#ifndef _OPTHOM_H_
#define _OPTHOM_H_

#include <string>
#include <math.h>



#ifdef HAVE_BFGS

#include "ap.h"



class Mesh;

class OptHOM
{

public:


  Mesh mesh;

  OptHOM(GEntity *gf, std::set<MVertex*> & toFix, int method);
  // returns 1 if the mesh has been optimized with success i.e. all jacobians are in the range
  // returns 0 if the mesh is valid (all jacobians positive, JMIN > 0) but JMIN < barrier_min || JMAX > barrier_max
  // returns -1 if the mesh is invalid : some jacobians cannot be made positive
  int optimize(double lambda, double lambda2, double barrier_min, double barrier_max, int pInt, int itMax);  // optimize one list of elements
  void getDistances(double &distMaxBND, double &distAvgBND, double &minJac, double &maxJac);
  //  void recalcJacDist();
  //  inline void getJacDist(double &minJ, double &maxJ, double &maxD, double &avgD);
  void updateMesh(const alglib::real_1d_array &x);
  void evalObjGrad(const alglib::real_1d_array &x, double &Obj, alglib::real_1d_array &gradObj);
  void printProgress(const alglib::real_1d_array &x, double Obj);

  double barrier_min, barrier_max;

private:

//  double lambda, lambda2, powM, powP, invLengthScaleSq;
  double lambda, lambda2, jacBar, bTerm, invLengthScaleSq;
  int iter, progressInterv;            // Current iteration, interval of iterations for reporting
  double initObj, initMaxDist, initAvgDist;  // Values for reporting
  double minJac, maxJac, maxDist, avgDist;  // Values for reporting

  inline void setBarrierTerm(double jacBarrier) { bTerm = jacBarrier/(1.-jacBarrier); }
  inline double compute_f(double v);
  inline double compute_f1(double v);
  bool addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj);
  bool addDistObjGrad(double Fact, double Fact2, double &Obj, alglib::real_1d_array &gradObj);
  void calcScale(alglib::real_1d_array &scale);
  void OptimPass(alglib::real_1d_array &x, const alglib::real_1d_array &initGradObj, int itMax);

};



inline double OptHOM::compute_f(double v)
{
  if (v > jacBar) {
    const double l = log((1 + bTerm) * v - bTerm);
    const double m = (v - 1);
    return l * l + m * m;
  }
  else return 1.e300;
//  if (v < 1.) return pow(1.-v,powM);
//  if (v < 1.) return exp((long double)pow(1.-v,3));
//  else return pow(v-1.,powP);
}



inline double OptHOM::compute_f1(double v)
{
  if (v > jacBar) {
    const double veps = (1 + bTerm) * v - bTerm;
    const double m = 2 * (v - 1);
    return m + 2 * log(veps) / veps * (1 + bTerm);
  }
  else return -1.e300;
//  if (v < 1.) return -powM*pow(1.-v,powM-1.);
//  if (v < 1.) return -3.*pow(1.-v,2)*exp((long double)pow(1.-v,3));
//  else return powP*pow(v-1.,powP-1.);
}



//void OptHOM::getJacDist(double &minJ, double &maxJ, double &maxD, double &avgD)
//{
//  minJ = minJac; maxJ = maxJac; maxD = maxDist; avgD = avgDist;
//}



#endif



#endif
