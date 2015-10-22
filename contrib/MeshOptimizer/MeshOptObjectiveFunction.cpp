// TODO: Copyright

#include <sstream>
#include <iostream>
#include <iomanip>
#include "MeshOptObjContrib.h"
#include "MeshOptObjectiveFunction.h"


void ObjectiveFunction::initialize(Patch *mesh)
{
   for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
     (*it)->initialize(mesh);
}


std::string ObjectiveFunction::contribNames()
{
  std::vector<ObjContrib*>::iterator it=begin();
  std::string str = (*it)->getName();
  for (it++; it!=end(); it++) str += " " + (*it)->getName();
  return str;
}


std::string ObjectiveFunction::minMaxStr()
{
  std::string str;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++) {
    std::ostringstream oss;
    if (it != begin())
      oss << "  |  ";
    oss <<  std::scientific << std::setw(13) << (*it)->getMin() << " <= " << (*it)->getMeasureName() << " <= " << std::setw(13) << (*it)->getMax();
    str += oss.str();
  }
  return str;
}

std::vector<std::pair<double,double> > ObjectiveFunction::minMax() {
  std::vector<std::pair<double,double> > range;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++) {
    std::pair<double,double> oneRange = std::make_pair((*it)->getMin(),(*it)->getMax());
    range.push_back(oneRange);
  }
  return range;
}

std::vector<std::string> ObjectiveFunction::names(){
  std::vector<std::string > namesStr;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++) {
    std::string name = (*it)->getMeasureName();
    namesStr.push_back(name);
  }
  return namesStr;
}

void ObjectiveFunction::updateMinMax()
{
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    (*it)->updateMinMax();
}


void ObjectiveFunction::updateParameters()
{
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    (*it)->updateParameters();
}


void ObjectiveFunction::updateResults()
{
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    (*it)->updateResults();
}


bool ObjectiveFunction::stagnated()
{
  bool stagnated = true;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    stagnated &= (*it)->stagnated();
  return stagnated;
}


bool ObjectiveFunction::targetReached()
{
  bool targetReached = true;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    targetReached &= (*it)->targetReached();
  return targetReached;
}


std::string ObjectiveFunction::failMeasures()
{
  std::string fail;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    if ((*it)->fail()) {
      if (fail.empty()) fail = (*it)->getMeasureName();
      else fail += " " + (*it)->getMeasureName();
    }
  return fail;
}


std::string ObjectiveFunction::targetsNotReached()
{
  std::string fail;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    if ((*it)->fail()) {
      if (fail.empty()) fail = (*it)->getName();
      else fail += " " + (*it)->getName();
    }
  return fail;
}


bool ObjectiveFunction::compute(double &obj, alglib::real_1d_array &gradObj)
{
  obj = 0.;
  for (int i = 0; i < gradObj.length(); i++) gradObj[i] = 0.;
  bool ok = true;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    ok &= (*it)->addContrib(obj, gradObj);
  return ok;
}
