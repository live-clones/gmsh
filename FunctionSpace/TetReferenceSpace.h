#ifndef _TETREFERENCESPACE_H_
#define _TETREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class TetReferenceSpace
   @brief ReferenceSpace for Tetrahedron

   This class implements a ReferenceSpace for a Tetrahedron.
 */

class TetReferenceSpace: public ReferenceSpace{
 public:
  TetReferenceSpace(void);
  virtual ~TetReferenceSpace(void);

  virtual std::string toLatex(void) const;  
};

/**
   @fn TetReferenceSpace::TetReferenceSpace
   Instatiate a new ReferenceSpace for a Tetrahedron
   **

   @fn TetReferenceSpace::~TetReferenceSpace
   Deletes this TetReferenceSpace
*/

#endif
