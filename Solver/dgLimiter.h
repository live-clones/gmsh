#ifndef _DG_LIMITER_H_
#define _DG_LIMITER_H_

#include "fullMatrix.h"
#include <vector>
struct dgDofContainer;
class dgGroupOfElements;
class dgGroupOfFaces;

class dgLimiter{
public:
  dgLimiter ()  {}
  virtual bool apply ( dgDofContainer &sol, std::vector<dgGroupOfElements*> &eGroups, 
		       std::vector<dgGroupOfFaces*> &fGroup ) = 0;
};

class SlopeLimiter : public dgLimiter{
public :
  SlopeLimiter () : dgLimiter () {}
  virtual bool apply ( dgDofContainer &solution,  
		       std::vector<dgGroupOfElements*> &eGroups, 
		       std::vector<dgGroupOfFaces*> &fGroup);
};

#endif
