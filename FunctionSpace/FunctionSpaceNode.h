#ifndef _FUNCTIONSPACENODE_H_
#define _FUNCTIONSPACENODE_H_

#include "FunctionSpace.h"

class FunctionSpaceNode: public FunctionSpace{
  FunctionSpaceNode(const GroupOfElement& goe, int order);

  virtual ~FunctionSpaceNode(void);

  std::vector<double> interpolateAtNodes(const MElement& element, 
					 const std::vector<double>& coef) const;
};

#endif
