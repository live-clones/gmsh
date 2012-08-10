#ifndef _FUNCTIONSPACEEDGE_H_
#define _FUNCTIONSPACEEDGE_H_

#include "FunctionSpaceVector.h"

class FunctionSpaceEdge : public FunctionSpaceVector{
 public:
  FunctionSpaceEdge(const GroupOfElement& goe, int order);
    
  virtual ~FunctionSpaceEdge(void);

  virtual fullVector<double> 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const;
};

#endif
