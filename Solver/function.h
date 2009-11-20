#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <map>
#include <set>
#include <string>
#include <fullMatrix.h>
class dataCacheMap;
class MElement;

// A class to store function data and cache it (by computing dependencies)
class dataCache {
  friend class dataCacheMap;
  // pointers to the "_valid" flag of all dataCache depending on me
  std::set<bool*> _dependOnMe;
  std::set<dataCache*> _iDependOn;
protected :
  bool _valid;
  // invalidates all the cached data that depends on me
  inline void _invalidateDependencies()
  {
    // if this is too slow we can keep a C array cache of the _dependOnMe set
    for(std::set<bool*>::iterator it = _dependOnMe.begin();
      it!=_dependOnMe.end(); it++)
        **it=false;
  }
  // dataCacheMap is the only one supposed to call this
  void addMeAsDependencyOf (dataCache *newDep);
  dataCache() : _valid(false) {}
  virtual ~dataCache(){};
};

// A node in the dependency tree for which all the leafs depend on the
// given double value
class dataCacheDouble : public dataCache {
 protected:
  fullMatrix<double> _value;
  // do the actual computation and put the result into _value
  virtual void _eval()=0;
 public:
  //set the value (without computing it by _eval) and invalidate the dependencies
  inline void set(const fullMatrix<double> &mat) {
    _invalidateDependencies();
    _value=mat;
    _valid=true;
  }
  inline const double &operator () (int i, int j)
  {
    if(!_valid) {
      _eval();
      _valid=true;
    }
    return _value(i,j);
  }
  //access _value and compute it if necessary
  inline const fullMatrix<double> &operator () ()
  {
    if(!_valid) {
      _eval();
      _valid=true;
    }
    return _value;
  }
  virtual ~dataCacheDouble(){};
};

// An abstract interface to functions
class function {
 private:
  static std::map<std::string, function*> _allFunctions;
  std::string _name;
 public:
  static void registerAllFunctions();
  static bool add(const std::string functionName, function *f);
  static function *get(std::string functionName, bool acceptNull=false);

  virtual dataCacheDouble *newDataCache(dataCacheMap *m) =0;
};

// A special node in the dependency tree for which all the leafs
// depend on the given element
class dataCacheElement : public dataCache {
 private:
  MElement *_element;
 public:
  void set(MElement *ele){
    _invalidateDependencies();
    _element=ele;
  };
  inline MElement *operator () () { return _element; }
};

class dataCacheMap {
 private:
  // keep track of the current element and all the dataCaches that
  // depend on it
  dataCacheElement _cacheElement;
  std::map<std::string, dataCacheDouble*> _cacheDoubleMap;
  class providedDataDouble : public dataCacheDouble
  {
    void _eval() {throw;};
  };
 public:
  dataCacheDouble &get(const std::string &functionName, dataCache *caller=0);
  dataCacheElement &getElement(dataCache *caller=0);
  // for data provided by the user and that does not have an _eval function
  // (typically "UVW") this class is not stricly necessary, we could write
  // a function for each case but I think it's more practical like this
  dataCacheDouble &provideData(std::string name);
  ~dataCacheMap();
};
#endif
