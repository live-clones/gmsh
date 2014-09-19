// TODO: Copyright

#include <sstream>
#include "MeshOptObjContrib.h"
#include "MeshOptObjectiveFunction.h"


ObjectiveFunction::ObjectiveFunction(const std::vector<ObjContrib*> &allContrib,
                                              const std::vector<int> &contribInd)
{
  resize(contribInd.size());
  for (int i=0; i<contribInd.size(); i++) operator[](i) = allContrib[contribInd[i]];
}


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
    oss << " -- Min. " + (*it)->getMeasureName() + " = " << (*it)->getMin();
    oss << " -- Max. " + (*it)->getMeasureName() + " = " << (*it)->getMax();
    str += oss.str();
  }
  return str;
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


void ObjectiveFunction::updateResults(MeshOptResults &res)
{
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    (*it)->updateResults(res);
}


bool ObjectiveFunction::stagnated()
{
  bool stagnated = false;
  for (std::vector<ObjContrib*>::iterator it=begin(); it!=end(); it++)
    stagnated |= (*it)->stagnated();
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
