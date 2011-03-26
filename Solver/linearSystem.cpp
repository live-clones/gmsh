// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "linearSystemFull.h"
#include "linearSystemCSR.h"
#include "linearSystemGMM.h"

void linearSystemBase::setParameter (std::string key, std::string value) 
{
  if (isAllocated())
    Msg::Error("this system is already allocated, parameters cannot be set");
  _parameters[key] = value;
}
