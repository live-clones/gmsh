// MeshOptimizer - Copyright (C) 2013-2019 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#include <sstream>
#include <iostream>
#include <iomanip>
#include "ObjContrib.h"
#include "ObjectiveFunction.h"

void ObjectiveFunction::initialize(Patch *mesh)
{
  for(auto it = begin(); it != end(); it++) (*it)->initialize(mesh);
}

std::string ObjectiveFunction::contribNames()
{
  auto it = begin();
  std::string str = (*it)->getName();
  for(it++; it != end(); it++) str += " " + (*it)->getName();
  return str;
}

std::string ObjectiveFunction::minMaxStr()
{
  std::string str;
  for(auto it = begin(); it != end(); it++) {
    std::ostringstream oss;
    if(it != begin()) oss << "  |  ";
    oss << std::scientific << std::setw(13) << (*it)->getMin()
        << " <= " << (*it)->getMeasureName() << " <= " << std::setw(13)
        << (*it)->getMax();
    str += oss.str();
  }
  return str;
}

std::vector<std::pair<double, double> > ObjectiveFunction::minMax()
{
  std::vector<std::pair<double, double> > range;
  for(auto it = begin(); it != end(); it++) {
    std::pair<double, double> oneRange =
      std::make_pair((*it)->getMin(), (*it)->getMax());
    range.push_back(oneRange);
  }
  return range;
}

std::vector<std::string> ObjectiveFunction::names()
{
  std::vector<std::string> namesStr;
  for(auto it = begin(); it != end(); it++) {
    std::string name = (*it)->getMeasureName();
    namesStr.push_back(name);
  }
  return namesStr;
}

void ObjectiveFunction::updateMinMax()
{
  for(auto it = begin(); it != end(); it++) (*it)->updateMinMax();
}

void ObjectiveFunction::updateParameters()
{
  for(auto it = begin(); it != end(); it++) (*it)->updateParameters();
}

void ObjectiveFunction::updateResults()
{
  for(auto it = begin(); it != end(); it++) (*it)->updateResults();
}

bool ObjectiveFunction::stagnated()
{
  bool stagnated = true;
  for(auto it = begin(); it != end(); it++) stagnated &= (*it)->stagnated();
  return stagnated;
}

bool ObjectiveFunction::targetReached()
{
  bool targetReached = true;
  for(auto it = begin(); it != end(); it++)
    targetReached &= (*it)->targetReached();
  return targetReached;
}

std::string ObjectiveFunction::failMeasures()
{
  std::string fail;
  for(auto it = begin(); it != end(); it++)
    if((*it)->fail()) {
      if(fail.empty())
        fail = (*it)->getMeasureName();
      else
        fail += " " + (*it)->getMeasureName();
    }
  return fail;
}

std::string ObjectiveFunction::targetsNotReached()
{
  std::string fail;
  for(auto it = begin(); it != end(); it++)
    if((*it)->fail()) {
      if(fail.empty())
        fail = (*it)->getName();
      else
        fail += " " + (*it)->getName();
    }
  return fail;
}

bool ObjectiveFunction::compute(double &obj, std::vector<double> &gradObj)
{
  obj = 0.;
  for(std::size_t i = 0; i < gradObj.size(); i++) gradObj[i] = 0.;
  bool ok = true;
  for(auto it = begin(); it != end(); it++)
    ok &= (*it)->addContrib(obj, gradObj);
  return ok;
}
