#ifndef _OPTHOMRUN_H_
#define _OPTHOMRUN_H_

class GModel;

struct OptHomParameters {
  // INPUT ------>
  double BARRIER_MIN_METRIC ; // minimum scaled jcaobian
  double BARRIER_MIN ; // minimum scaled jcaobian
  double BARRIER_MAX ; // maximum scaled jcaobian
  double weightFixed ; // weight of the energy for fixed nodes
  double weightFree ; // weight of the energy for free nodes
  int nbLayers ; // number of layers taken around a bad element
  int dim ; // which dimension to optimize
  int itMax ; // max number of iterations in the optimization process
  int optPassMax ; // max number of optimization passes
  double TMAX ; // max CPU time allowed
  bool onlyVisible ; // apply optimization to visible entities ONLY
  double distanceFactor; // filter elements such that no elements further away than
                         // DistanceFactor times the max distance to straight sided version of an element are optimized
  bool fixBndNodes;  // how jacobians are computed and if points can move on boundaries
  int strategy;       // 0 = connected blobs, 1 = adaptive one-by-one
  int maxAdaptBlob;   // Max. nb. of blob adaptation interations
  int adaptBlobLayerFact;   // Growth factor in number of layers for blob adaptation
  double adaptBlobDistFact; // Growth factor in distance factor for blob adaptation

  // OUTPUT ------>
  int SUCCESS ; // 0 --> success , 1 --> Not converged
  double minJac, maxJac; // after optimization, range of jacobians
  double CPU; // Time for optimization

  // is called by the optimizer at every stage of the
  //  virtual void progressCallback (int percetageDone) const {}

  OptHomParameters ()
  // default values
  : BARRIER_MIN_METRIC(-1.), BARRIER_MIN(0.1), BARRIER_MAX(2.0), weightFixed(1.e6), weightFree (1.e2),
    nbLayers (6) , dim(3) , itMax(300), onlyVisible(true), distanceFactor(12), fixBndNodes(false),
    strategy(0), maxAdaptBlob(3), adaptBlobLayerFact(2.), adaptBlobDistFact(2.)
  {
  }
};

void HighOrderMeshOptimizer (GModel *gm, OptHomParameters &p);
void OptHomMessage (const char *s, ...);


#endif
