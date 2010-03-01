#ifndef _DG_LIMITER_H_
#define _DG_LIMITER_H_

#include "fullMatrix.h"
#include <vector>
class dgDofContainer;
class dgGroupCollection;
class dgConservationLaw;
class binding;

class dgLimiter{
protected:
  dgConservationLaw *_claw;
public:
  dgLimiter (dgConservationLaw *claw) : _claw(claw) {}
  virtual int apply ( dgDofContainer *sol)=0;
  static void registerBindings(binding *b);
};

class dgSlopeLimiter : public dgLimiter{
public :
  dgSlopeLimiter (dgConservationLaw *claw) : dgLimiter (claw) {}
  virtual int apply ( dgDofContainer *solution);
};
void dgSlopeLimiterRegisterBindings(binding *b);

#endif
