#ifndef _FUNCTIONSPACENODE_H_
#define _FUNCTIONSPACENODE_H_

#include "FunctionSpaceScalar.h"

/**
    @class FunctionSpaceNode
    @brief A Nodal Function Space
    
    This class is a Nodal (0-Form) Function Space.
*/


class FunctionSpaceNode : public FunctionSpaceScalar{
 public:
  FunctionSpaceNode(const GroupOfElement& goe, int order);
    
  virtual ~FunctionSpaceNode(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const;
};


/**
   @fn FunctionSpaceNode::FunctionSpaceNode
   @param goe The GroupOfElement defining the 
   @em support of this FunctionSpace
   @param order The order of this FunctionSpace

   Instantiates a new Nodal Function Space
   (FunctionSpaceNode) with the given parameters
   **

   @fn FunctionSpaceNode::~FunctionSpaceNode
   Deletes this FunctionSpaceNode
   **
 */

#endif
