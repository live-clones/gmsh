//
// C++ Interface: partDomain
//
// Description: Interface class to used solver. Your term ha to be store in a domain
//
// Author:  <Gauthier BECKER>, (C) 2010
//
// Copyright: See COPYING file that comes with this distribution
//
//
#include "partDomain.h"
partDomain::partDomain(const partDomain &source){
  _tag = source._tag;
  _phys = source._phys;
  _fullDg = source._fullDg;
  btermBulk = source.btermBulk;
  massterm = source.massterm;
  ltermBulk = source.ltermBulk;
  integBulk = source.integBulk;
  g = source.g;
  allDirichlet = source.allDirichlet;
  allNeumann = source.allNeumann;
  allInitial = source.allInitial;
  _bmbp = source._bmbp;
  _eps= source._eps;
  _wsp = source._wsp;
  setmaterial = source.setmaterial;
}

partDomain& partDomain::operator=(const partDomain &source)
{
  _tag = source._tag;
  _phys = source._phys;
  _fullDg = source._fullDg;
  btermBulk = source.btermBulk;
  massterm = source.massterm;
  ltermBulk = source.ltermBulk;
  integBulk = source.integBulk;
  g = source.g;
  allDirichlet = source.allDirichlet;
  allNeumann = source.allNeumann;
  allInitial = source.allInitial;
  _wsp = source._wsp;
  _bmbp = source._bmbp;
  _eps = source._eps;
  setmaterial = source.setmaterial;
  return *this;
}

dgPartDomain::dgPartDomain(const dgPartDomain &source) : partDomain(source){
  btermBound = source.btermBound;
  ltermBound = source.ltermBound;
  btermVirtBound = source.btermVirtBound;
  ltermVirtBound = source.ltermVirtBound;
  integBound = source.integBound;
  gi = source.gi;
  gib = source.gib;
  giv = source.giv;
  _interByPert = source._interByPert;
  _virtByPert = source._virtByPert;
}

dgPartDomain& dgPartDomain::operator=(dgPartDomain &source)
{
  this->partDomain::operator=(source);
  btermBound = source.btermBound;
  ltermBound = source.ltermBound;
  btermVirtBound = source.btermVirtBound;
  ltermVirtBound = source.ltermVirtBound;
  integBound = source.integBound;
  gi = source.gi;
  gib = source.gib;
  giv = source.giv;
  _interByPert = source._interByPert;
  _virtByPert = source._virtByPert;
  return *this;
}

void partDomain::setBulkMatrixByPerturbation(const int i, const double eps)
{
  i == 0 ? _bmbp = false : _bmbp = true;
  _eps = eps;
}
