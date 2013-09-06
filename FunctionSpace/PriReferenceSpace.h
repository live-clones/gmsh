#ifndef _PRIREFERENCESPACE_H_
#define _PRIREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class PriReferenceSpace
   @brief ReferenceSpace for Prisms

   This class implements a ReferenceSpace for a Prism.
 */

class PriReferenceSpace: public ReferenceSpace{
 public:
  PriReferenceSpace(void);
  virtual ~PriReferenceSpace(void);

  virtual std::string toLatex(void) const;
};

/**
   @fn PriReferenceSpace::PriReferenceSpace
   Instatiate a new ReferenceSpace for a Prism
   **

   @fn PriReferenceSpace::~PriReferenceSpace
   Deletes this PriReferenceSpace
*/

#endif
