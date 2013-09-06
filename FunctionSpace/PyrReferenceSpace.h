#ifndef _PYRREFERENCESPACE_H_
#define _PYRREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class PyrReferenceSpace
   @brief ReferenceSpace for Pyramids

   This class implements a ReferenceSpace for a Pyramid.
 */

class PyrReferenceSpace: public ReferenceSpace{
 public:
  PyrReferenceSpace(void);
  virtual ~PyrReferenceSpace(void);

  virtual std::string toLatex(void) const;
};

/**
   @fn PyrReferenceSpace::PyrReferenceSpace
   Instatiate a new ReferenceSpace for a Pyramid
   **

   @fn PyrReferenceSpace::~PyrReferenceSpace
   Deletes this PyrReferenceSpace
*/

#endif
