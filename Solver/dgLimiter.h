#ifndef _DG_LIMITER_H_
#define _DG_LIMITER_H_

#include "fullMatrix.h"
#include <vector>
struct dgDofContainer;
class dgGroupOfElements;
class dgGroupOfFaces;
class dgConservationLaw;

class dgLimiter{
protected:
  dgConservationLaw *_claw;
public:
  dgLimiter (dgConservationLaw *claw) : _claw(claw) {}
  virtual bool apply ( dgDofContainer &sol, std::vector<dgGroupOfElements*> &eGroups, 
		       std::vector<dgGroupOfFaces*> &fGroup ) = 0;
};

class dgSlopeLimiter : public dgLimiter{
public :
  dgSlopeLimiter (dgConservationLaw *claw) : dgLimiter (claw) {}
  virtual bool apply ( dgDofContainer &solution,  
		       std::vector<dgGroupOfElements*> &eGroups, 
		       std::vector<dgGroupOfFaces*> &fGroup);
};

#endif
