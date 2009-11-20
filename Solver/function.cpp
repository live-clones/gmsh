#include "function.h"
#include "SPoint3.h"
#include "MElement.h"

// dataCache members

void dataCache::addMeAsDependencyOf (dataCache *newDep)
{
  _dependOnMe.insert(&newDep->_valid);
  newDep->_iDependOn.insert(this);
  for(std::set<dataCache*>::iterator it = _iDependOn.begin();
      it != _iDependOn.end(); it++) {
    (*it)->_dependOnMe.insert(&newDep->_valid);
    newDep->_iDependOn.insert(*it);
  }
}

// function static members

std::map<std::string,function*> function::_allFunctions;

bool function::add(const std::string functionName, function *f)
{
  if(_allFunctions.find(functionName)!=_allFunctions.end())
    return false;
  _allFunctions[functionName]=f;
  return true;
}

function *function::get(std::string functionName, bool acceptNull)
{
  std::map<std::string, function*>::iterator it=_allFunctions.find(functionName);
  if (it==_allFunctions.end()) {
    if (acceptNull)
      return NULL;
    else
      throw;
  }
  return it->second;
}

//dataCacheMap members

dataCacheElement &dataCacheMap::getElement(dataCache *caller) 
{
  if(caller)
    _cacheElement.addMeAsDependencyOf(caller);
  return _cacheElement;
}

dataCacheDouble &dataCacheMap::get(const std::string &functionName, dataCache *caller) 
{
  dataCacheDouble *&r= _cacheDoubleMap[functionName];
  if(r==NULL)
    r = function::get(functionName)->newDataCache(this);
  if(caller)
    r->addMeAsDependencyOf(caller);
  return *r;
}

dataCacheDouble &dataCacheMap::provideData(std::string name)
{
  dataCacheDouble *&r= _cacheDoubleMap[name];
  if(r!=NULL)
    throw;
  r = new providedDataDouble;
  return *r;
}

dataCacheMap::~dataCacheMap()
{
  for (std::map<std::string, dataCacheDouble*>::iterator it = _cacheDoubleMap.begin();
      it!=_cacheDoubleMap.end(); it++) {
    delete it->second;
  }
}

// now some example of functions

class functionXYZ : public function {
 private:
  class data : public dataCacheDouble{
   private:
    dataCacheElement &_element;
    dataCacheDouble &_uvw;
   public:
    data(dataCacheMap *m) :
      _element(m->getElement(this)), _uvw(m->get("UVW", this))
    {
      _value = fullMatrix<double> (_uvw().size1(), 3);
    }
    void _eval()
    {
      for(int i = 0; i < _uvw().size1(); i++){
        SPoint3 p;
        _element()->pnt(_uvw(i, 0), _uvw(i, 1), _uvw(i, 2), p);
        _value(i, 0) = p.x();
        _value(i, 1) = p.y();
        _value(i, 2) = p.z();
      }
    }
  };
 public:
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return new data(m);
  }
};


void function::registerAllFunctions()
{
  function::add("XYZ", new functionXYZ);
}

