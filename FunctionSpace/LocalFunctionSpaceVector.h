#ifndef _LOCALFUNCTIONSPACEVECTOR_H_
#define _LOCALFUNCTIONSPACEVECTOR_H_

#include <vector>
#include "Polynomial.h"
#include "Basis.h"
#include "LocalFunctionSpace.h"

class LocalFunctionSpaceVector: LocalFunctionSpace{
 protected:
  const std::vector<std::vector<Polynomial> >* basis;

 public:
  LocalFunctionSpaceVector(const Basis& basis);
  virtual ~LocalFunctionSpaceVector(void);
};

#endif
