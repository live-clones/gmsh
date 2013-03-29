#ifndef _TRIREFERENCESPACE_H_
#define _TRIREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class TriReferenceSpace
   @brief ReferenceSpace for a Triangle

   This class implements a ReferenceSpace for a Triangle.
 */

class TriReferenceSpace: public ReferenceSpace{
 public:
  TriReferenceSpace(void);
  virtual ~TriReferenceSpace(void);

  virtual std::string toLatex(void) const;
};

/**
   @fn TriReferenceSpace::TriReferenceSpace
   Instatiate a new ReferenceSpace for a Triangle
   **

   @fn TriReferenceSpace::~TriReferenceSpace
   Deletes this TriReferenceSpace
*/

#endif
