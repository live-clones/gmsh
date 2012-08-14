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

  OptHOM(GEntity *gf, const std::set<MElement*> &els, std::set<MVertex*> & toFix, int method);
  // returns 1 if the mesh has been optimized with success i.e. all jacobians are in the range
  // returns 0 if the mesh is valid (all jacobians positive, JMIN > 0) but JMIN < barrier_min || JMAX > barrier_max
  // returns -1 if the mesh is invalid : some jacobians cannot be made positive
  int optimize(double lambda, double lambda2, double barrier_min, double barrier_max, bool optimizeMetricMin, int pInt, int itMax);  // optimize one list of elements
  void recalcJacDist();
  inline void getJacDist(double &minJ, double &maxJ, double &maxD, double &avgD);
  void updateMesh(const alglib::real_1d_array &x);
  void evalObjGrad(const alglib::real_1d_array &x, double &Obj, alglib::real_1d_array &gradObj);
  void printProgress(const alglib::real_1d_array &x, double Obj);

  double barrier_min, barrier_max;

private:

//  double lambda, lambda2, powM, powP, invLengthScaleSq;
  double lambda, lambda2, jacBar, invLengthScaleSq;
  int iter, progressInterv;            // Current iteration, interval of iterations for reporting
  bool _optimizeMetricMin;
  double initObj, initMaxDist, initAvgDist;  // Values for reporting
  double minJac, maxJac, maxDist, avgDist;  // Values for reporting

  bool _optimizeBarrierMax; // false : only moving barrier min; true : fixed barrier min + moving barrier max

  inline void setBarrierTerm(double jacBarrier) {jacBar = jacBarrier;}
  bool addJacObjGrad(double &Obj, alglib::real_1d_array &gradObj);
  bool addMetricMinObjGrad(double &Obj, alglib::real_1d_array &gradObj);
  bool addDistObjGrad(double Fact, double Fact2, double &Obj, alglib::real_1d_array &gradObj);
  void calcScale(alglib::real_1d_array &scale);
  void OptimPass(alglib::real_1d_array &x, const alglib::real_1d_array &initGradObj, int itMax);
};




void OptHOM::getJacDist(double &minJ, double &maxJ, double &maxD, double &avgD)
{
  minJ = minJac; maxJ = maxJac; maxD = maxDist; avgD = avgDist;
}



#endif



#endif
