#ifndef _LINEREFERENCESPACE_H_
#define _LINEREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class LineReferenceSpace
   @brief ReferenceSpace for a Line

   This class implements a ReferenceSpace for a Line.
 */

class LineReferenceSpace: public ReferenceSpace{
 public:
  LineReferenceSpace(void);
  virtual ~LineReferenceSpace(void);

  virtual std::string toLatex(void) const;  
};

/**
   @fn LineReferenceSpace::LineReferenceSpace
   Instatiate a new ReferenceSpace for a Line
   **

   @fn LineReferenceSpace::~LineReferenceSpace
   Deletes this LineReferenceSpace
*/

#endif
