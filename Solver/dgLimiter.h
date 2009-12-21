#ifndef _DG_LIMITER_H_
#define _DG_LIMITER_H_

#include "fullMatrix.h"
#include <vector>


class dgLimiter
{
public:
  dgLimiter ()  {}
  virtual ~dgLimiter() {}
  virtual bool apply ( dgDofContainer &sol ) =0;
};

class SlopeLimiter : public dgLimiter
{

 public :
  SlopeLimiter () : dgLimiter () {}
  ~SlopeLimiter() {}
  bool apply ( dgDofContainer &sol );

};

#endif
