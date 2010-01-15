#ifndef _DG_LIMITER_H_
#define _DG_LIMITER_H_

#include "fullMatrix.h"
#include <vector>
struct dgDofContainer;
class dgGroupCollection;
class dgConservationLaw;

class dgLimiter{
protected:
  dgConservationLaw *_claw;
public:
  dgLimiter (dgConservationLaw *claw) : _claw(claw) {}
  virtual bool apply ( dgDofContainer &sol, dgGroupCollection &groups)=0;
};

class dgSlopeLimiter : public dgLimiter{
public :
  dgSlopeLimiter (dgConservationLaw *claw) : dgLimiter (claw) {}
  virtual bool apply ( dgDofContainer &solution, dgGroupCollection &groups);
};

#endif
