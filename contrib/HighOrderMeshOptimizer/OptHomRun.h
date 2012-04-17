#ifndef _OPTHOMRUN_H_
#define _OPTHOMRUN_H_

class GModel;

struct OptHomParameters {
  // INPUT ------> 
  double STOP ; // stop criterion
  double BARRIER ; // minimum scaled jcaobian
  double weightFixed ; // weight of the energy for fixed nodes
  double weightFree ; // weight of the energy for free nodes
  int nbLayers ; // number of layers taken around a bad element
  int dim ; // which dimension to optimize
  int itMax ; // max number of iterations in the optimization process
  double TMAX ; // max CPU time allowed
  bool onlyVisible ; // apply optimization to visible entities ONLY
  // OUTPUT ------> 
  int SUCCESS ; // 0 --> success , 1 --> Not converged
  double minJac, maxJac; // after optimization, range of jacobians
  double DT; // Time for optimization
  
  OptHomParameters () 
  // default values    
  : STOP (0.01) , BARRIER (0.1) , weightFixed (10.),  weightFree (1.e-3),
    nbLayers (6) , dim(3) , itMax(10000), onlyVisible(true)
  {
  }
};

void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p);


#endif
