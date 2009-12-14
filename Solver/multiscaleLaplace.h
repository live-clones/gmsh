#ifndef _MULTISCALE_LAPLACE_H_
#define _MULTISCALE_LAPLACE_H_

#include <vector>
#include <map>
#include <set>
#include "SPoint2.h"
#include "linearSystem.h"

class MElement;
class MVertex;

struct multiscaleLaplaceLevel {
  SPoint2 center;
  double  scale;
  double radius;
  int recur,region;
  std::vector<multiscaleLaplaceLevel*> children;
  std::vector<MElement *> elements;
  std::map<MVertex*,SPoint2> coordinates;
  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > cut;
};

class multiscaleLaplace{
public:
  multiscaleLaplace (std::vector<MElement *> &elements, int iPart=0); 
  void cut (std::vector<MElement *> &elements,int iPart=0);  
  typedef enum {HARMONIC=1,CONFORMAL=2, CONVEXCOMBINATION=3} typeOfMapping;

  linearSystem<double> *_lsys;
  multiscaleLaplaceLevel* root;
  void parametrize (multiscaleLaplaceLevel &); 
  void parametrize_method (multiscaleLaplaceLevel & level, 
			   std::set<MVertex*> &allNodes,
			   std::map<MVertex*,SPoint2> &solution, 
			   typeOfMapping tom);

  
};
#endif
