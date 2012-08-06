#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "FunctionSpace.h"

class FunctionSpaceScalar: public FunctionSpace{
 public:
  FunctionSpaceScalar(const GroupOfElement& goe, 
		      int basisType, int order);

  virtual ~FunctionSpaceScalar(void);

  virtual void interpolateAtNodes(const MElement& element, 
				  const std::vector<double>& coef,
				  std::vector<double>& nodeValue) const = 0;
};

#endif
