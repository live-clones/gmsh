#ifndef _LOCALFUNCTIONSPACESCALAR_H_
#define _LOCALFUNCTIONSPACESCALAR_H_

#include <vector>
#include "Polynomial.h"
#include "Basis.h"
#include "LocalFunctionSpace.h"

class LocalFunctionSpaceScalar: LocalFunctionSpace{
 protected:
  const std::vector<Polynomial>* basis;

 public:
  LocalFunctionSpaceScalar(const Basis& basis);
  virtual ~LocalFunctionSpaceScalar(void);
};

#endif
