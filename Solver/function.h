#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "fullMatrix.h"
#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>
class dataCacheMap;
class MElement;
class binding;

class function;
class dataCacheDouble;

class functionConstant;
class functionReplace;
struct functionReplaceCache;

// An abstract interface to functions 
// more explanation at the head of this file
class function {
  public :
  int _nbCol;
  bool _invalidatedOnElement;
  std::vector<functionReplace*> _functionReplaces;
  class dependency {
    public : unsigned iMap; const function *f;
    dependency(int iMap_, const function *f_){iMap = iMap_; f = f_; }
    bool operator < (const dependency &d) const {
      return (d.iMap <iMap || d.f < f);
    }
  };
  void printDep() {
    for(std::set<dependency>::iterator it = dependencies.begin(); it != dependencies.end(); it++)
      printf("%i %p\n", it->iMap, it->f);
  }
  class argument {
    //iMap is the id of the dataCacheMap, e.g. on interfaces
    public:
    int iMap; const function *f; fullMatrix<double> *val;
    argument(fullMatrix<double> &v, int iMap_, const function *f_){ val = &v; iMap = iMap_; f = f_; }
  };
  std::vector<argument> arguments;
  std::set<dependency> dependencies;
  void setArgument(fullMatrix<double> &v, const function *f, int iMap = 0);
  void addFunctionReplace(functionReplace &fr);

  function(int nbCol, bool invalidatedOnElement = true);
  virtual ~function();
  virtual void call (dataCacheMap *m, fullMatrix<double> &res)=0;
  virtual void registerInDataCacheMap(dataCacheMap *m, dataCacheDouble *d) {}

  inline bool isInvalitedOnElement() { return _invalidatedOnElement;}
  inline int getNbCol()const {return _nbCol;}

  static void registerBindings(binding *b);

  private:
  static functionConstant *_timeFunction;
  static functionConstant *_dtFunction;  
  public:
  static function *getSolution();
  static function *getSolutionGradient();
  static function *getParametricCoordinates();
  static function *getNormals();
  static functionConstant *getTime();
  static functionConstant *getDT();
};

// dataCache when the value is a  matrix of double 
// the user should provide the number of rows by evaluating points and the number of columns
// then the size of the matrix is automatically adjusted
class dataCacheDouble {
  friend class dataCacheMap;
  friend class dgDataCacheMap;
  friend class functionReplace;
  std::vector<dataCacheDouble*> _directDependencies;
  function *_function;
  dataCacheMap &_cacheMap;
  std::vector<functionReplaceCache> functionReplaceCaches;
  protected:
  // pointers to all of the dataCache depending on me
  std::set<dataCacheDouble*> _dependOnMe;
  std::set<dataCacheDouble*> _iDependOn;
  fullMatrix<double> _value;
  bool _valid;
  dataCacheDouble(dataCacheMap *,function *f);

  // do the actual computation and put the result into _value
  void _eval();
  void resize(int nrow);
 public:
  //set the value (without computing it by _eval) and invalidate the dependencies
  // this function is needed to be able to pass the _value to functions like gemm or mult
  // but you cannot keep the reference to the _value, you should always use the set function 
  // to modify the _value
  // take care if you use this to set a proxy you must ensure that the value pointed to are not modified
  // without further call to set because the dependencies won't be invalidate
  inline fullMatrix<double> &set() {
    if(_valid) {
      for(std::set<dataCacheDouble*>::iterator it = _dependOnMe.begin();
          it!=_dependOnMe.end(); it++)
        (*it)->_valid=false;
    }
    _valid = true;
    return _value;
  }
  //access _value and compute it if necessary
  inline const fullMatrix<double> &get() {
    if(!_valid)
      _eval();
    return _value;
  }
  // dataCacheMap is the only one supposed to call this
  inline bool somethingDependOnMe() {
    return !_dependOnMe.empty();
  }
  inline bool doIDependOn(dataCacheDouble &other) {
    return (_iDependOn.find(&other)!=_iDependOn.end());
  }
};


class dgDataCacheMap;
// more explanation at the head of this file
class dataCacheMap {
 public:
  dataCacheMap  *_parent;
  std::list<dataCacheMap*> _children;
  std::vector<dataCacheMap*> _secondaryCaches;
  int _nbEvaluationPoints;
  std::map<const function*, dataCacheDouble*> _cacheDoubleMap;
  std::set<dataCacheDouble*> _allDataCaches;
  std::set<dataCacheDouble*> _toInvalidateOnElement;


  MElement *_element;
  void addDataCacheDouble(dataCacheDouble *data, bool invalidatedOnElement){
    _allDataCaches.insert(data);
    if(invalidatedOnElement)
      _toInvalidateOnElement.insert(data);
  }
  virtual dgDataCacheMap *asDgDataCacheMap() {
    Msg::Error("I'm not a dgDataCacheMap\n");
    return NULL;
  }
  dataCacheMap *getSecondaryCache(int i) {
    if (i==0)
      return this;
    return _secondaryCaches[i-1];
  }
  void addSecondaryCache(dataCacheMap *s) {
    _secondaryCaches.push_back(s);
  }
  dataCacheDouble &get(const function *f, dataCacheDouble *caller=0);
  virtual void setElement(MElement *element) {
    _element=element;
    for(std::set<dataCacheDouble*>::iterator it = _toInvalidateOnElement.begin(); it!= _toInvalidateOnElement.end(); it++) {
      (*it)->_valid=false;
    }
    for(std::list<dataCacheMap*>::iterator it = _children.begin(); it != _children.end(); it++) {
      (*it)->setElement(element);
    }
  }
  inline MElement *getElement() {return _element;}
  dataCacheMap() {
    _nbEvaluationPoints = 0;
    _parent=NULL;
  }
  virtual dataCacheMap *newChild() {
    dataCacheMap *m = new dataCacheMap();
    m->_parent = this;
    _children.push_back(m);
    m->_nbEvaluationPoints = 0;
    return m;
  }
  void setNbEvaluationPoints(int nbEvaluationPoints);

  inline int getNbEvaluationPoints(){return _nbEvaluationPoints;}
  ~dataCacheMap();
};
class functionReplace {
  friend class dataCacheMap;
  friend class dataCacheDouble;
  public :
  function *_master;
  int _nChildren;
  functionReplaceCache *currentCache;
  std::set <function::dependency> _replaced;
  std::set <function::dependency> _fromParent;
  std::vector <function::argument> _toReplace;
  std::vector <function::argument> _toCompute;
  void get(fullMatrix<double> &v, const function *, int iMap = 0);
  void replace(fullMatrix<double> &v, const function *, int iMap = 0);
  void compute ();
  functionReplace();
  void addChild();
};


functionConstant *functionConstantNew(const std::vector<double>&);
functionConstant *functionConstantNew(double);
function *functionSumNew (const function *f0, const function *f1);
function *functionProdNew (const function *f0, const function *f1);
function *functionScaleNew (const function *f0, const double s);
function *functionExtractCompNew (const function *f0, const int iComp);

class functionSolution : public function {
  static functionSolution *_instance;
  functionSolution():function(0){};// constructor is private only 1 instance can exists, call get to access the instance
 public:
  void call(dataCacheMap *m, fullMatrix<double> &sol) {
    Msg::Error("a function requires the solution but this algorithm does not provide the solution");
    throw;
  }
  void setNbFields( int nbFields) {
    _nbCol = nbFields;
  }
  static functionSolution *get() {
    if(!_instance)
      _instance = new functionSolution();
    return _instance;
  }
};

class functionConstant : public function {
  public:
  fullMatrix<double> _source;
  void call(dataCacheMap *m, fullMatrix<double> &val) {
    for(int i=0;i<val.size1();i++)
      for(int j=0;j<_source.size1();j++){
        val(i,j)=_source(j,0);
        }
  }
  functionConstant(std::vector<double> source):function(source.size()){
    _source = fullMatrix<double>(source.size(),1);
    for(size_t i=0; i<source.size(); i++){
      _source(i,0) = source[i];
    }
  }
  void set(double val); 
};
function *getFunctionCoordinates();
#endif
