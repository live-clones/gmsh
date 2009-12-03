#ifndef _MULTISCALE_LAPLACE_H_
#define _MULTISCALE_LAPLACE_H_

#include <vector>
#include <map>
#include "SPoint2.h"
#include "linearSystem.h"

class MElement;
class MVertex;

struct multiscaleLaplaceLevel {
  SPoint2 center;
  double  scale;
  double radius;
  int recur,region;
  std::vector<multiscaleLaplaceLevel*> childeren;
  std::vector<MElement *> elements;
  std::map<MVertex*,SPoint2> coordinates;
  std::vector<std::pair<SPoint2,multiscaleLaplaceLevel*> > cut;
};

class multiscaleLaplace{
  linearSystem<double> *_lsys;
  multiscaleLaplaceLevel* root;
  void parametrize (multiscaleLaplaceLevel &);  
public:
  multiscaleLaplace (std::vector<MElement *> &elements,
		     std::vector<MVertex*> &boundaryNodes,
		     std::vector<double> &linearAbscissa) ;
  void cut (std::vector<MElement *> &left, 
	    std::vector<MElement *> &right);  
};
#endif
