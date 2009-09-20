// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _SELEMENT_H_
#define _SELEMENT_H_

#include "MElement.h"

// A solver element.

class SElement
{
 private:
  // the underlying mesh element
  MElement *_e;
  // store discrete function space and other data here
  // ...
 public:
  SElement(MElement *e) : _e(e) {}
  ~SElement(){}
  MElement *getMeshElement() const { return _e; }
};

#endif
