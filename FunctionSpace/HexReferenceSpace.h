#ifndef _HEXREFERENCESPACE_H_
#define _HEXREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

/**
   @class HexReferenceSpace
   @brief ReferenceSpace for Hexahedron

   This class implements a ReferenceSpace for a Hexahedron.
 */

class HexReferenceSpace: public ReferenceSpace{
 public:
  HexReferenceSpace(void);
  virtual ~HexReferenceSpace(void);

  virtual std::string toLatex(void) const;

 private:
  void initHex(void);
};

/**
   @fn HexReferenceSpace::HexReferenceSpace
   Instatiate a new ReferenceSpace for a Hexahedron
   **

   @fn HexReferenceSpace::~HexReferenceSpace
   Deletes this HexReferenceSpace
*/

#endif
