// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.

#include "linearSystemFull.h"
#include "linearSystemCSR.h"
#include "linearSystemGMM.h"

void linearSystemBase::setParameter (std::string key, std::string value)
{
  if (isAllocated())
    Msg::Error("this system is already allocated, parameters cannot be set");
  _parameters[key] = value;
}

std::string linearSystemBase::getParameter(std::string key) const
{
  std::map<std::string, std::string>::const_iterator it;
  it = this->_parameters.find(key);
  if(it == this->_parameters.end()) return "";
  else return it->second;
}
