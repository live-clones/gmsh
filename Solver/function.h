#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <map>
#include <set>
#include <string>
#include <fullMatrix.h>
class dataCacheMap;
class MElement;

// those classes manage complex function dependencies and keep their values in cache so that they are not recomputed when it is not necessary. To do this, we use three classes : function, dataCache and dataCacheMap. The workflow is :
//
// a) before parsing the input file : a few general function that are always available are created (xyz for example).
//
// b) while parsing the input file and during the initialisation of the conservationLaw : all user-defined instance of function are inserted in the function map. (for example an user can create a function named "wind" of the class functionMathex with parameter "0.1*sin(xyz(0)/1e6); 0"  and then give the string "wind" as parameter to it's conservation law to let the law know that this is the function to use as wind forcing)
//
// c) before starting to iterate over the element :
// c1) the algorithm create a new dataCacheMap instance.
// c2) The algo insert in the dataCacheMap the dataCache it will provide (ie the quadrature points, the solution value,...) 
// c3) Then the algo give this dataCacheMap to the law and ask the source term of the law. This source term will be given as a dataCache, i.e. a cached value, a function to update it and a node in the dependency tree. In this example, to create this datacache two new dataCache will be required : one for the "wind" and one for "xyz". So, the source dataCache will ask the dataCacheMap for the dataCache called "wind". If this one does not already exist, the dataCacheMap will ask the function called "wind" to create it. In turn, the constructor of the dataCache associated with the "wind" will ask for the for the dataCache "xyz" wich will be created by the function "xyz" if it does not already exist and so on. The dataCacheMap contain also a special dataCache associated with the current element. During it's construction it's dataCache keep references to all the dataCache needed to compute it. When they request for the dataCache they need, the dataCacheMap is informed and the dependency tree is built. 
//
// d) When iterating over elements, for each element : the Algo will change the dataCache element so that it point to the current element. This will invalidate everything that depend on the current on the current element (in this case, xyz, wind (because it depends on xyz) and the source dataCache (because it depends on wind). So, in this case everything (exept the current element dataCache) is marked as invalid. Now the algo want to access the value of the 'source' dataCache this one is invalid, so it is recomputed. To recompute it, the value of the wind is accessed and it's value is recomputed, and so on. Now, if some other function access the wind or the position (xyz), they are already marked as valid and are not re-computed.
//
// e) after the loop over the elements the dataCacheMap is deleted and it delete all its dataCaches.
//
// NB) in the case of integration over faces, there is two dataCacheMap : one for the Right side and one for the left side i.e. two sets of cached values and two dependency trees. Some dataCache (ie the value of the flux) have dependencies in both tree. This is not a problem, the only difference with other dataCaches is that they are not owned by the dataCacheMap and have to be deleted manually.
// 

// a node in the dependency tree. The usefull field is _dependOnMe which is the set of every other nodes that depend on me. When the value of this node change all nodes depending on this one are marked as "invalid" and will be recomputed the next time their data are accessed. To be able to maintain _dependOnMe up to date when a new node is inserted in the tree, we need _iDependOn list. So we do not really store a tree but instead each node contain a complete list of all it's parents and all it's children (and the parents of the parents of ... of its parents and the children of the children of ... of it's children). This way invalidate all the dependencies of a node is really fast and does not involve a complex walk accross the tree structure.
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
  dataCache() : _valid(false) {}
  virtual ~dataCache(){};
public :
  // dataCacheMap is the only one supposed to call this
  void addMeAsDependencyOf (dataCache *newDep);
  inline bool somethingDependOnMe() {
    return !_dependOnMe.empty();
  }
};

// dataCache when the value is a double 
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
  // take care if you use this you must ensure that the value pointed to are not modified
  // without further call to setAsProxy because the dependencies won't be invalidate
  inline void setAsProxy(fullMatrix<double> &mat, int cShift, int c) {
    _invalidateDependencies();
    _value.setAsProxy(mat,cShift,c);
    _valid=true;
  }
  // take care if you use this you must ensure that the value pointed to are not modified
  // without further call to setAsProxy because the dependencies won't be invalidate
  inline void setAsProxy(fullMatrix<double> &mat) {
    _invalidateDependencies();
    _value.setAsProxy(mat,0,mat.size2());
    _valid=true;
  }
  // this function is needed to be able to pass the _value to functions like gemm or mult
  // but you cannot keep the reference to the _value, you should always use the set function 
  // to modify the _value
  inline fullMatrix<double> &set() {
    _invalidateDependencies();
    _valid=true;
    return _value;
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
  dataCacheDouble(){};
  dataCacheDouble(int size1, int size2):_value(size1,size2){};
  virtual ~dataCacheDouble(){};
};

// An abstract interface to functions 
// more explanation at the head of this file
class function {
 private:
  static std::map<std::string, function*> _allFunctions;
 protected:
  std::string _name;
 public:
  static void registerDefaultFunctions();
  static bool add(const std::string functionName, function *f);
  static function *get(std::string functionName, bool acceptNull=false);

  virtual dataCacheDouble *newDataCache(dataCacheMap *m) =0;

  inline  std::string getName()const {return _name;}

  static const char *className;
  static const char *parentClassName;
  static methodBinding *methods[];
  static constructorBinding *constructorMethod;
  virtual ~function(){};
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

// more explanation at the head of this file
class dataCacheMap {
 private:
  int _nbEvaluationPoints;
  // keep track of the current element and all the dataCaches that
  // depend on it
  dataCacheElement _cacheElement;
  std::map<std::string, dataCacheDouble*> _cacheDoubleMap;
  class providedDataDouble : public dataCacheDouble
  // for data provided by the algorithm and that does not have an _eval function
  // (typically "UVW")
  {
    void _eval() {throw;};
    public:
    providedDataDouble() {
      _valid=true;
    }
  };
 public:
  dataCacheDouble &get(const std::string &functionName, dataCache *caller=0);
  dataCacheElement &getElement(dataCache *caller=0);
  dataCacheDouble &provideData(std::string name);
  dataCacheMap(int nbEvaluationPoints):_nbEvaluationPoints(nbEvaluationPoints){}
  inline int getNbEvaluationPoints(){return _nbEvaluationPoints;}
  ~dataCacheMap();
};
class functionConstant : public function {
  public:
  class data ;
  fullMatrix<double> _source;
  dataCacheDouble *newDataCache(dataCacheMap *m);
  functionConstant(const fullMatrix<double> *source);
  static const char *className;
  static const char *parentClassName;
  static methodBinding *methods[];
  static constructorBinding *constructorMethod;
  ~functionConstant(){
    printf("delete fc\n");
  }
};
#endif
