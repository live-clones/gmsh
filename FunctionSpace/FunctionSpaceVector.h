#ifndef _FUNCTIONSPACEVECTOR_H_
#define _FUNCTIONSPACEVECTOR_H_

#include "fullMatrix.h"
#include "BasisVector.h"
#include "FunctionSpace.h"

class FunctionSpaceVector : public FunctionSpace{
 public:
  virtual ~FunctionSpaceVector(void);

  virtual fullVector<double> 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;

  const BasisVector& getBasis(const MElement& element) const;
};


//////////////////////
// Inline Functions //
//////////////////////

inline const BasisVector& FunctionSpaceVector::
getBasis(const MElement& element) const{
  return static_cast<const BasisVector&>(*basis);
}

#endif
