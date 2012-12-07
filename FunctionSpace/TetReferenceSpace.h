#ifndef _TETREFERENCESPACE_H_
#define _TETREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

class TetReferenceSpace: public ReferenceSpace{
 public:
  TetReferenceSpace(void);
  virtual ~TetReferenceSpace(void);

  std::string toLatex(void) const;  
};

#endif
