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
class functionReplaceCache;

// An abstract interface to functions 
// more explanation at the head of this file
class function {
  static functionConstant *_timeFunction;
  static functionConstant *_dtFunction;  
  public :
  class argument {
    //iMap is the id of the dataCacheMap, e.g. on interfaces
    public:
    int iMap;
    const function *f;
    fullMatrix<double> *val;
    argument(fullMatrix<double> &v, int iMap_, const function *f_){
      val = &v;
      iMap = iMap_;
      f = f_;
    }
  };
  std::vector<functionReplace*> _functionReplaces;
  class substitutedFunction {
    public:
    int iMap;
    const function *f0, *f1; // f1 replaces f0
  };
  int _nbCol;
  bool _invalidatedOnElement;
  std::vector<int> _childrenCache;
  std::vector<substitutedFunction> _substitutedFunctions;
  virtual void call (dataCacheMap *m, fullMatrix<double> &res)=0;
  virtual void registerInDataCacheMap(dataCacheMap *m, dataCacheDouble *d) {}
  std::vector<argument> arguments;
  const void setArgument(fullMatrix<double> &v, const function *f, int iMap = 0) {
    if(f==NULL)
      throw;
    arguments.push_back(argument(v, iMap, f));
  }
  void addChildDataCacheMap(int parent) {
    _childrenCache.push_back(parent);
  }
  void substituteFunction( int iMap, const function *f0, const function *f1) {
    substitutedFunction s;
    s.iMap= iMap;
    s.f0 = f0;
    s.f1 = f1;
    _substitutedFunctions.push_back(s);
  }
  virtual ~function();
  static void registerBindings(binding *b);
  function(int nbCol, bool invalidatedOnElement = true);
  inline int getNbCol()const {return _nbCol;}
  inline bool isInvalitedOnElement() { return _invalidatedOnElement;}
  void addFunctionReplace(functionReplace &fr);
  
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
  public:
  // pointers to all of the dataCache depending on me
  std::set<dataCacheDouble*> _dependOnMe;
  std::set<dataCacheDouble*> _iDependOn;
protected :
  // invalidates all the cached data that depends on me
  inline void _invalidateDependencies()
  {
    // if this is too slow we can keep a C array cache of the _dependOnMe set
    for(std::set<dataCacheDouble*>::iterator it = _dependOnMe.begin();
      it!=_dependOnMe.end(); it++)
        (*it)->_valid=false;
  }
public :
  bool _valid;
  // dataCacheMap is the only one supposed to call this
  void addMeAsDependencyOf (dataCacheDouble *newDep);
  inline bool somethingDependOnMe() {
    return !_dependOnMe.empty();
  }
  inline bool doIDependOn(dataCacheDouble &other) {
    return (_iDependOn.find(&other)!=_iDependOn.end());
  }
  std::vector<dataCacheDouble*> _dependencies;
  std::vector<std::pair<dataCacheDouble*, dataCacheDouble*> > _substitutions;


  int _nRowByPoint;
  function *_function;
  dataCacheMap &_cacheMap;
  // do the actual computation and put the result into _value
  // still virtual because it is overrided by conservation law terms, as soon as conservation law terms will be regular functions, we will remove this
  virtual void _eval();
 public:
  fullMatrix<double> _value;
  //set the value (without computing it by _eval) and invalidate the dependencies
  // this function is needed to be able to pass the _value to functions like gemm or mult
  // but you cannot keep the reference to the _value, you should always use the set function 
  // to modify the _value
  // take care if you use this to set a proxy you must ensure that the value pointed to are not modified
  // without further call to set because the dependencies won't be invalidate
  inline fullMatrix<double> &set() {
    if(_valid)
      _invalidateDependencies();
    _valid = true;
    return _value;
  }
  std::vector<functionReplaceCache*> functionReplaceCaches;

  inline const double &operator () (int i, int j)
  {
    if(!_valid) {
      _eval();
      _valid = true;
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
  void resize();
  dataCacheDouble(dataCacheMap *,function *f);
  dataCacheDouble(dataCacheMap &m, int nRowByPoint, int nbCol);
  virtual ~dataCacheDouble();
};


class dgDataCacheMap;
// more explanation at the head of this file
class dataCacheMap {
  friend class dataCacheDouble;
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
  void printList() {
    for(std::set<dataCacheDouble*>::iterator it = _toInvalidateOnElement.begin(); it!= _toInvalidateOnElement.end(); it++)
      printf("%p\n",*it);
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
  dataCacheDouble &substitute(const function *f);
  virtual void setElement(MElement *element) {
    _element=element;
    for(std::set<dataCacheDouble*>::iterator it = _toInvalidateOnElement.begin(); it!= _toInvalidateOnElement.end(); it++) {
      (*it)->_valid=false;
    }
    for(std::list<dataCacheMap*>::iterator it = _children.begin(); it!= _children.end(); it++) {
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
  friend class functionReplaceCache;
  friend class dataCacheDouble;
  protected:
  functionReplaceCache *currentCache;
  std::vector <function::argument> _toReplace;
  std::vector <function::argument> _toCompute;
  public :
  void get(fullMatrix<double> &v, const function *, int iMap = 0);
  void replace(fullMatrix<double> &v, const function *, int iMap = 0);
  void compute ();
};

class functionReplaceCache {
  public :
  dataCacheMap *map;
  std::vector <dataCacheDouble*> toReplace;
  std::vector <dataCacheDouble*> toCompute;
  functionReplaceCache(dataCacheMap *m, functionReplace *rep, dataCacheDouble *from);
  ~functionReplaceCache();
};


functionConstant *functionConstantNew(const std::vector<double>&);
functionConstant *functionConstantNew(double);
function *functionSumNew (const function *f0, const function *f1);

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
#endif
