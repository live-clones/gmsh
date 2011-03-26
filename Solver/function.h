#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include "fullMatrix.h"
#include <map>
#include <set>
#include <list>
#include <string>
#include <vector>

class dataCacheDouble;
class dataCacheMap;
class dgDataCacheMap;
class function;
class functionConstant;
class functionReplace;
class functionReplaceCache;
class MElement;

// An abstract interface to functions
class function {
 public:
  // additionnal types
  class dependency {
   public:
    unsigned iMap;
    const function *f;
    dependency(int iMap_, const function *f_) {
       iMap = iMap_;
       f = f_;
    }
    bool operator < (const dependency &d) const {
      return (d.iMap <iMap || d.f < f);
    }
  };
  class argument {
   public:
    int iMap; // id of the dataCacheMap, e.g. on interfaces
    const function *f;
    fullMatrix<double> *val;
    argument(fullMatrix<double> &v, int iMap_, const function *f_) {
      val = &v;
      iMap = iMap_;
      f = f_;
    }
  };

  // data
  int _nbCol;
  bool _invalidatedOnElement;
  std::vector<functionReplace*> _functionReplaces;
  std::vector<argument> arguments;
  std::set<dependency> dependencies;

 private:
  static functionConstant *_timeFunction;
  static functionConstant *_dtFunction;  

 public:
  function(int nbCol, bool invalidatedOnElement = true)
    : _nbCol(nbCol), _invalidatedOnElement(invalidatedOnElement) {}
  virtual ~function(){}

  void addFunctionReplace(functionReplace &fr);
  void setArgument(fullMatrix<double> &v, const function *f, int iMap = 0);
  virtual void call(dataCacheMap *m, fullMatrix<double> &res) = 0;
  virtual void registerInDataCacheMap(dataCacheMap *m, dataCacheDouble *d) {}

  // get or print information
  inline bool isInvalitedOnElement() { return _invalidatedOnElement; }
  inline int getNbCol() const        { return _nbCol; }
  static functionConstant *getTime();
  static functionConstant *getDT();
  static function *getSolution();
  static function *getSolutionGradient();
  static function *getParametricCoordinates();
  static function *getNormals();
  void printDep()
  {
    for (std::set<dependency>::iterator it = dependencies.begin();
         it != dependencies.end(); it++)
      printf("%i %p\n", it->iMap, it->f);
  }
};


// Additionnal class to get solution
class functionSolution : public function {
  static functionSolution *_instance;
  // constructor is private only 1 instance can exists, call get to
  // access the instance
  functionSolution() : function(0) {}; 
 public:
  void call(dataCacheMap *m, fullMatrix<double> &sol)
  {
    Msg::Error("A function requires the solution but this algorithm does "
               "not provide the solution");
    throw;
  }
  void setNbFields(int nbFields){ _nbCol = nbFields; }
  static functionSolution *get()
  {
    if(!_instance)
      _instance = new functionSolution();
    return _instance;
  }
};

class functionSolutionGradient : public function {
  static functionSolutionGradient *_instance;
  // constructor is private only 1 instance can exists, call get to
  // access the instance
  functionSolutionGradient();
 public:
  void call(dataCacheMap *m, fullMatrix<double> &sol);
  static function *get();
};

class functionReplaceCache {
  public:
  dataCacheMap *map;
  std::vector <dataCacheDouble*> toReplace;
  std::vector <dataCacheDouble*> toCompute;
};

class functionReplace {
  friend class dataCacheMap;
  friend class dataCacheDouble;

 public:
  int _nChildren;
  function *_master;
  functionReplaceCache *currentCache;
  std::set <function::dependency> _replaced;
  std::set <function::dependency> _fromParent;
  std::vector <function::argument> _toReplace;
  std::vector <function::argument> _toCompute;
  functionReplace();
  void get(fullMatrix<double> &v, const function *, int iMap = 0);
  void replace(fullMatrix<double> &v, const function *, int iMap = 0);
  void compute();
  void addChild();
};

// A dataCache when the value is a matrix of double. The user should
// provide the number of rows by evaluating points and the number of
// columns; then the size of the matrix is automatically adjusted
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
  //set the value (without computing it by _eval) and invalidate the
  // dependencies this function is needed to be able to pass the
  // _value to functions like gemm or mult but you cannot keep the
  // reference to the _value, you should always use the set function
  // to modify the _value take care if you use this to set a proxy you
  // must ensure that the value pointed to are not modified without
  // further call to set because the dependencies won't be invalidate
  inline fullMatrix<double> &set()
  {
    if(_valid) {
      for(std::set<dataCacheDouble*>::iterator it = _dependOnMe.begin();
          it!=_dependOnMe.end(); it++)
        (*it)->_valid=false;
    }
    _valid = true;
    return _value;
  }
  // access _value and compute it if necessary
  inline const fullMatrix<double> &get()
  {
    if(!_valid)
      _eval();
    return _value;
  }
  // dataCacheMap is the only one supposed to call this
  inline bool somethingDependOnMe() { return !_dependOnMe.empty(); }
  inline bool doIDependOn(dataCacheDouble &other)
  {
    return (_iDependOn.find(&other)!=_iDependOn.end());
  }
  inline std::vector<dataCacheDouble*> & getDirectDependencies() { return _directDependencies; }
};

class dataCacheMap {
  const function *_functionSolution, *_functionSolutionGradient;
  //handle function solution and funciton solution gradient
  //we should get rid of them
  const function * _translate (const function *) const;
 public:
  dataCacheMap  *_parent;
  std::list<dataCacheMap*> _children;
  std::vector<dataCacheMap*> _secondaryCaches;
  int _nbEvaluationPoints;
  std::map<const function*, dataCacheDouble*> _cacheDoubleMap;
  std::set<dataCacheDouble*> _allDataCaches;
  std::vector<dataCacheDouble*> _toInvalidateOnElement;
  MElement *_element;
  dataCacheMap() {
    _functionSolution = _functionSolutionGradient = NULL;
    _nbEvaluationPoints = 0;
    _parent=NULL;
  }
  ~dataCacheMap();
  void addDataCacheDouble(dataCacheDouble *data, bool invalidatedOnElement)
  {
    _allDataCaches.insert(data);
    if(invalidatedOnElement)
      _toInvalidateOnElement.push_back(data);
  }
  virtual dgDataCacheMap *asDgDataCacheMap() 
  {
    Msg::Error("I'm not a dgDataCacheMap");
    return NULL;
  }
  dataCacheMap *getSecondaryCache(int i)
  {
    if (i==0)
      return this;
    return _secondaryCaches[i-1];
  }
  void addSecondaryCache(dataCacheMap *s)
  {
    _secondaryCaches.push_back(s);
  }
  dataCacheDouble *get(const function *f, dataCacheDouble *caller=0, bool createIfNotPresent = true);
  virtual void setElement(MElement *element)
  {
    _element=element;
    for(std::vector<dataCacheDouble*>::iterator it=_toInvalidateOnElement.begin(); 
        it!= _toInvalidateOnElement.end(); it++) {
      (*it)->_valid=false;
    }
    for(std::list<dataCacheMap*>::iterator it=_children.begin(); it!=_children.end(); it++) {
      (*it)->setElement(element);
    }
  }
  inline MElement *getElement() { return _element; }
  virtual dataCacheMap *newChild()
  {
    dataCacheMap *m = new dataCacheMap();
    m->_parent = this;
    _children.push_back(m);
    m->_nbEvaluationPoints = 0;
    return m;
  }
  inline void setSolutionFunction(const function *functionSolution, const function *functionSolutionGradient) {
    _functionSolution = functionSolution;
    _functionSolutionGradient = functionSolutionGradient;
  }
  void setNbEvaluationPoints(int nbEvaluationPoints);
  inline int getNbEvaluationPoints() { return _nbEvaluationPoints; }
};

// functionConstant (constant values copied over each line)
class functionConstant : public function {
 public:
  fullMatrix<double> _source;
  void call(dataCacheMap *m, fullMatrix<double> &val);
  functionConstant(std::vector<double> source);
  functionConstant(double source);
  void set(double val); 
};

class functionC : public function {
  std::vector<fullMatrix<double> > args;
  void (*callback)(void);
  public:
  static void buildLibrary(std::string code, std::string filename) ;
	static void buildLibraryFromFile(const std::string cfilename, const std::string libfilename);
  void call (dataCacheMap *m, fullMatrix<double> &val) ;
  functionC (std::string file, std::string symbol, int nbCol, 
             std::vector<const function *> dependencies);
};
function *functionLevelsetNew (const function *f0, const double valMin, const double valPlus);
function *functionLevelsetSmoothNew (const function *f0, const double valMin, const double valPlus, const double E);
function *functionSumNew (const function *f0, const function *f1);
function *functionProdNew (const function *f0, const function *f1);
function *functionScaleNew (const function *f0, const double s);
function *functionExtractCompNew (const function *f0, const int iComp);
function *functionCatCompNew(std::vector<const function *> fArray);
function *functionMeanNew(const function *f0);

function *getFunctionCoordinates();

#endif
