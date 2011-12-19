#ifndef _MESH_METRIC_H_
#define _MESH_METRIC_H_
#include <map>
#include "STensor3.h"
#include "Field.h"
#include "meshGFaceOptimize.h"
template <class scalar> class simpleFunction;
class MVertex;
class gLevelset;
class MElementOctree;

/**Anisotropic mesh size field based on a metric */
class meshMetric: public Field {
 public:
  typedef enum {LEVELSET=1,HESSIAN=2, FREY=3} MetricComputationTechnique;
 private:
  int _dim;
  double _epsilon, _E;
  meshMetric::MetricComputationTechnique _technique;
  double hmin, hmax;
  simpleFunction<double> *_fct;

  std::vector<MElement*> _elements;
  MElementOctree *_octree;
  std::map<int, MVertex*> _vertexMap;

  std::map<MVertex*,double> vals;
  std::map<MVertex*,SVector3> grads,dgrads[3];

  std::map<MVertex*,SMetric3> _nodalMetrics;
  std::map<MVertex*,double> _nodalSizes, _detMetric;
  std::map<MVertex*,fullMatrix<double> > _hessian;
 public:
  meshMetric(std::vector<MElement*> elements,  int technique, 
	     simpleFunction<double> *fct, std::vector<double> parameters);
  meshMetric(GModel *gm, int technique, 
	     simpleFunction<double> *fct, std::vector<double> parameters);
  ~meshMetric();
  inline SMetric3 metricAtVertex (MVertex* v) {return _nodalMetrics[v];}
  void computeMetric() ;
  void computeValues( v2t_cont adj);
  void computeHessian( v2t_cont adj);
  void setAsBackgroundMesh (GModel *gm);

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
  virtual double operator() (double x, double y, double z, GEntity *ge=0) ;
  virtual void operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge=0);
  
  void printMetric(const char* n) const;
};
#endif
