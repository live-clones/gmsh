#ifndef _FUNCTIONSPACEEDGE_H_
#define _FUNCTIONSPACEEDGE_H_

#include "FunctionSpaceVector.h"

/**
    @class FunctionSpaceEdge
    @brief An Edge based Function Space
    
    This class is an Edge based (1-Form) Function Space.
*/


class FunctionSpaceEdge : public FunctionSpaceVector{
 public:
  FunctionSpaceEdge(const GroupOfElement& goe, int order);
    
  virtual ~FunctionSpaceEdge(void);

  virtual fullVector<double> 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const;
};


/**
   @fn FunctionSpaceEdge::FunctionSpaceEdge
   @param goe The GroupOfElement defining the 
   @em support of this FunctionSpace
   @param order The order of this FunctionSpace

   Instantiates a new Edge based Function Space
   (FunctionSpaceEdge) with the given parameters
   **

   @fn FunctionSpaceEdge::~FunctionSpaceEdge
   Deletes this FunctionSpaceEdge
   **
 */

#endif
