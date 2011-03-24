//
//
//
// Description: Define material law
//
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "mlaw.h"
materialLaw::materialLaw(const int num, const bool init): _num(num), _initialized(init){}

materialLaw::materialLaw(const materialLaw &source)
{
  _num = source._num;
  _initialized = source._initialized;
}

materialLaw& materialLaw::operator=(const materialLaw &source)
{
  _num = source._num;
  _initialized = source._initialized;
  return *this;
}
