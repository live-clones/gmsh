#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "fullMatrix.h"
#include "BasisScalar.h"
#include "FunctionSpace.h"

class FunctionSpaceScalar : public FunctionSpace{
 public:
  virtual ~FunctionSpaceScalar(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;

  const BasisScalar& getBasis(const MElement& element) const;
};


//////////////////////
// Inline Functions //
//////////////////////

inline const BasisScalar& FunctionSpaceScalar::
getBasis(const MElement& element) const{
  return static_cast<const BasisScalar&>(*basis);
}

#endif
