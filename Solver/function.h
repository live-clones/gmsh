#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <map>
#include <string>

// An abstract interface to functions
class function{
 private:
  static std::map<std::string, function*> _allFunctions;
  std::string _name;
 public:
  virtual dataCache &getDataCache(dataCacheMap *m) = 0;
  static bool add(std::string functionName, function *f);
};

// A class to store function data and cache it intelligently (by
// computing dependencies)
class dataCache{
 protected:
  bool _valid;
  std::set<dataCache*> _iDependOnThem, _theyDependOnMe;
  // validates all the dependencies
  void _validate();
  void _invalidateDependencies();
};

// A node in the dependency tree for which all the leafs depend on the
// given double value
class dataCacheDouble : public dataCache {
 private:
  fullMatrix<double> _value;
 public:
  void set(const fullMatrix<double> &mat);
  void set(int i, int j, double val);
  inline const fullMatrix<double> &operator () ()
  {
    if(!_valid) _validate();
    return _value;
  }
  virtual void eval() = 0;
};

// A special node in the dependency tree for which all the leafs
// depend on the given element
class dataCacheElement : public dataCache {
 private:
  MElement *_element;
 public:
  void set(const MElement *ele);
  inline const MElement *operator () () { return _element; }
};

class dataCacheMap{
 private:
  // keep track of the current element and all the dataCaches that
  // depend on it
  dataCacheElement *_dependOnElement;
 public:
  dataCacheDouble &get(const std::string &functionName,
                       dataCache *caller=0);
  dataCacheElement &getElement(dataCache *caller=0);

};

#endif
