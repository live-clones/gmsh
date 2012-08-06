#ifndef _FUNCTIONSPACENODE_H_
#define _FUNCTIONSPACENODE_H_

#include "FunctionSpaceScalar.h"

class FunctionSpaceNode: public FunctionSpaceScalar{
 public:
  FunctionSpaceNode(const GroupOfElement& goe, int order);
  
  virtual ~FunctionSpaceNode(void);
  
  virtual void interpolateAtNodes(const MElement& element, 
				  const std::vector<double>& coef,
				  std::vector<double>& nodeValue) const;
};

#endif
