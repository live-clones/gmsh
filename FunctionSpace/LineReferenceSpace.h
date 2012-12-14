#ifndef _LINEREFERENCESPACE_H_
#define _LINEREFERENCESPACE_H_

#include <string>
#include "ReferenceSpace.h"

class LineReferenceSpace: public ReferenceSpace{
 public:
  LineReferenceSpace(void);
  virtual ~LineReferenceSpace(void);

  std::string toLatex(void) const;  
};

#endif
