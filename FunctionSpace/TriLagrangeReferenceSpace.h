#ifndef _TRILAGRANGEREFERENCESPACE_H_
#define _TRILAGRANGEREFERENCESPACE_H_

#include "ReferenceSpaceLagrange.h"

/**
   @class TriLagrangeReferenceSpace
   @brief ReferenceSpaceLagrange for a Triangle

   This class implements a ReferenceSpaceLagrange
   for a Triangle.
 */

class TriLagrangeReferenceSpace: public ReferenceSpaceLagrange{
 public:
  TriLagrangeReferenceSpace(unsigned int order);
  virtual ~TriLagrangeReferenceSpace(void);
};

/**
   @fn TriLagrangeReferenceSpace::TriLagrangeReferenceSpace
   @param order A natural number

   Instatiate a new ReferenceLagrangeSpace for a Triangle
   of the given order
   **

   @fn TriReferenceLagrangeSpace::~TriReferenceLagrangeSpace
   Deletes this TriReferenceSpace
*/

#endif
