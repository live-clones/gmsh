#ifndef _FUNCTIONSPACENODE_H_
#define _FUNCTIONSPACENODE_H_

#include "FunctionSpaceScalar.h"

class FunctionSpaceNode : public FunctionSpaceScalar{
 public:
  FunctionSpaceNode(const GroupOfElement& goe, int order);
    
  virtual ~FunctionSpaceNode(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const;
};

#endif
