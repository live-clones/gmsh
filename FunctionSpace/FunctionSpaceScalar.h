#ifndef _FUNCTIONSPACESCALAR_H_
#define _FUNCTIONSPACESCALAR_H_

#include "fullMatrix.h"
#include "FunctionSpace.h"

class FunctionSpaceScalar : public FunctionSpace{
 public:
  virtual ~FunctionSpaceScalar(void);

  virtual double 
    interpolate(const MElement& element, 
		const std::vector<double>& coef,
		const fullVector<double>& xyz) const = 0;
};

#endif
