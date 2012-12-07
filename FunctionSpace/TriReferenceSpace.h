#ifndef _TRIREFERENCESPACE_H_
#define _TRIREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

class TriReferenceSpace: public ReferenceSpace{
 public:
  TriReferenceSpace(void);
  virtual ~TriReferenceSpace(void);

  std::string toLatex(void) const;  
};

#endif
