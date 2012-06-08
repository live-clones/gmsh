// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _MESH_METRIC_H_
#define _MESH_METRIC_H_

#include <map>
#include <algorithm>
#include "STensor3.h"
#include "Field.h"
#include "meshGFaceOptimize.h"

template <class scalar> class simpleFunction;
class MVertex;
class gLevelset;
class MElementOctree;
class STensor3;

/**Anisotropic mesh size field based on a metric */
class meshMetric: public Field {
 public:
  typedef enum {LEVELSET=1,HESSIAN=2, FREY=3, EIGENDIRECTIONS=4, EIGENDIRECTIONS_LINEARINTERP_H=5, ISOTROPIC_LINEARINTERP_H=6} MetricComputationTechnique;
 private:
  // intersect all metrics added in "setOfMetrics", preserve eigendirections of the "most anisotropic" metric
  void intersectMetrics();
  int _dim;
  double _epsilon, _E, _E_moins, _Np;
  bool needMetricUpdate;
  meshMetric::MetricComputationTechnique _technique;
  double hmin, hmax;
  simpleFunction<double> *_fct;

  std::vector<MElement*> _elements;
  v2t_cont _adj;
  MElementOctree *_octree;
  std::map<int, MVertex*> _vertexMap;

  std::map<MVertex*,double> vals;
  std::map<MVertex*,SVector3> grads,dgrads[3];

  typedef std::map<MVertex*,SMetric3> nodalMetricTensor;
  typedef std::map<MVertex*,double> nodalField;

  nodalMetricTensor _nodalMetrics,_hessian;
  nodalField _nodalSizes, _detMetric;

  std::map<int,nodalMetricTensor> setOfMetrics;
  std::map<int,nodalField> setOfSizes;
  std::map<int,nodalField> setOfDetMetric;

 public:
  meshMetric(std::vector<MElement*> elements);
  meshMetric(GModel *gm);

  ~meshMetric();

  // compute a new metric and add it to the set of metrics
  // parameters[1] = lcmin (default : in global gmsh options CTX::instance()->mesh.lcMin)
  // parameters[2] = lcmax (default : in global gmsh options CTX::instance()->mesh.lcMax)
  // Available algorithms ("techniques"):
  // 1: fct is a LS, metric based on Coupez technique
  //    parameters[0] = thickness of the interface (mandatory)
  // 2: metric based on the hessian of fct
  //    parameters[0] = the final number of elements
  // 3: fct is a LS, variant of (1) based on Frey technique (combines Coupez and curvature)
  //    parameters[0] = thickness of the interface (mandatory)
  //    parameters[3] = the required minimum number of elements to represent a circle - used for curvature-based metric (default: = 15)
  // 4: fct is a LS, variant of (3), metric computed in LS eigendirections
  //    parameters[0] = thickness of the interface in the positive ls direction (mandatory)
  //    parameters[4] = thickness of the interface in the negative ls direction (default: =parameters[0] if not specified)
  //    parameters[3] = the required minimum number of elements to represent a circle - used for curvature-based metric (default: = 15)
  // 5: same as 4, except that the transition in band E uses linear interpolation of h, instead of linear interpolation of metric
  // 6: fct is a LS, metric is isotropic with linear interpolation of h in band E
  void addMetric(int technique, simpleFunction<double> *fct, std::vector<double> parameters);

  inline SMetric3 metricAtVertex (MVertex* v) {
    if (needMetricUpdate) intersectMetrics();
    return _nodalMetrics[v];
  }
  void computeMetric() ;
  void computeValues();
  void computeHessian_LS();
  void computeHessian_LS2();
  void computeHessian_LS3();
  void computeHessian_FE();

  double getLaplacian (MVertex *v);
  virtual bool isotropic () const {return false;}
  virtual const char *getName()
  {
    return "metricField";
  }
  virtual std::string getDescription()
  {
    return "Anisotropic size field based on hessian of a given function";
  }

  // get metric at point(x,y,z)  (previously computes intersection of metrics if not done yet)
  virtual double operator() (double x, double y, double z, GEntity *ge=0) ;
  virtual void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);

  // export pos files of fct, fct gradients (fct is the lattest fct passed to meshMetric !!) and resulting metric (intersection of all computed metrics)
  void exportInfo(const char *fileendname);
};

#endif
