#ifndef _QUADREFERENCESPACE_H_
#define _QUADREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class QuadReferenceSpace
   @brief ReferenceSpace for a Quadrangle

   This class implements a ReferenceSpace for a Quadrangle.
 */

class QuadReferenceSpace: public ReferenceSpace{
 public:
  QuadReferenceSpace(void);
  virtual ~QuadReferenceSpace(void);

  virtual std::string toLatex(void) const;
};

/**
   @fn QuadReferenceSpace::QuadReferenceSpace
   Instatiate a new ReferenceSpace for a Quadrangle
   **

   @fn QuadReferenceSpace::~QuadReferenceSpace
   Deletes this QuadReferenceSpace
*/

#endif
