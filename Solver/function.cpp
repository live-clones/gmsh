#include "GmshConfig.h"
#include <sstream>
#include <fstream>
#include "function.h"
#include "SPoint3.h"
#include "MElement.h"
#include "GModel.h"
#if defined(HAVE_DLOPEN)
  #include "dlfcn.h"
#endif
#include "Bindings.h"

function::~function() {
}

function::function(int nbCol, bool invalidatedOnElement):_nbCol(nbCol), _invalidatedOnElement(invalidatedOnElement){}

void function::addFunctionReplace(functionReplace &fr) {
  _functionReplaces.push_back(&fr);
}
dataCacheDouble::~dataCacheDouble()
{
  for(int i = 0; i< functionReplaceCaches.size(); i++) {
    delete functionReplaceCaches[i];
  }
};

void dataCacheDouble::addMeAsDependencyOf (dataCacheDouble *newDep)
{
  _dependOnMe.insert(newDep);
  newDep->_iDependOn.insert(this);
  for(std::set<dataCacheDouble*>::iterator it = _iDependOn.begin();
      it != _iDependOn.end(); it++) {
    (*it)->_dependOnMe.insert(newDep);
    newDep->_iDependOn.insert(*it);
  }
}

dataCacheDouble::dataCacheDouble(dataCacheMap &m, int nRowByPoint, int nbCol):
  _cacheMap(m),_value(m.getNbEvaluationPoints()*nRowByPoint,nbCol)
{
  _nRowByPoint=nRowByPoint;
  m.addDataCacheDouble(this,true);
  _function = NULL;
}

dataCacheDouble::dataCacheDouble(dataCacheMap *m, function *f):
  _cacheMap(*m),_value(m->getNbEvaluationPoints(),f->getNbCol())
{
  _nRowByPoint=1;
  m->addDataCacheDouble(this, f->isInvalitedOnElement());
  _function = f;
  for(int i=0; i<f->_childrenCache.size(); i++) {
    m->addSecondaryCache(m->newChild());
  }
  _substitutions.resize(f->_substitutedFunctions.size());
  for(int i=0; i<f->_substitutedFunctions.size(); i++) {
    function::substitutedFunction s = f->_substitutedFunctions[i];
    _substitutions[i].first = &m->getSecondaryCache(s.iMap)->substitute(s.f0);
    _substitutions[i].second = &m->get(s.f1,this);
  }
  _dependencies.resize ( _function->arguments.size());
  for (unsigned int i=0;i<_function->arguments.size();i++) {
    int iCache = _function->arguments[i].iMap;
    const function *f = _function->arguments[i].f;
    _dependencies[i] = &m->getSecondaryCache(iCache)->get(f,this);
  }
  for (int i = 0; i < f->_functionReplaces.size(); i++) {
    functionReplaceCaches.push_back (new functionReplaceCache(m, f->_functionReplaces[i], this)); 
  }
  f->registerInDataCacheMap(m, this);
}

void dataCacheDouble::resize() {
  _value = fullMatrix<double>(_nRowByPoint==0?1:_nRowByPoint*_cacheMap.getNbEvaluationPoints(),_value.size2());
}
void dataCacheDouble::_eval() {
  for(unsigned int i=0;i<_dependencies.size(); i++){
    _function->arguments[i].val->setAsProxy((*_dependencies[i])());
  }
  for (int i = 0; i < _function->_functionReplaces.size(); i++) {
    _function->_functionReplaces[i]->currentCache = functionReplaceCaches[i];
    for (int j = 0; j < functionReplaceCaches[i]->toReplace.size() ; j++){
      _function->_functionReplaces[i]->_toReplace[j].val->setAsProxy((*functionReplaceCaches[i]->toReplace[j])._value);
    }
  }
  _function->call(&_cacheMap, _value);
}

//dataCacheMap members
dataCacheDouble &dataCacheMap::get(const function *f, dataCacheDouble *caller) {
  dataCacheDouble *&r = _cacheDoubleMap[f];
  dataCacheMap *cParent = _parent;
  while (cParent && r==NULL) {
    std::map<const function *, dataCacheDouble *>::iterator it = cParent->_cacheDoubleMap.find(f);
    if (it != cParent->_cacheDoubleMap.end()) {
      r = it->second;
      for (std::set<dataCacheDouble*>::iterator dep = r->_iDependOn.begin(); dep != r->_iDependOn.end(); dep++) {
        //if (_cacheDoubleMap.find((*dep)->_function) != _cacheDoubleMap.end()) {
        if (&get((*dep)->_function) != *dep) {
          r = NULL;
          break;
        }
      }
    }
    cParent = cParent->_parent;
  }
  if (r==NULL)
    r = new dataCacheDouble(this, (function*)(f));
  if (caller)
    r->addMeAsDependencyOf(caller);
  return *r;
}

dataCacheDouble &dataCacheMap::substitute(const function *f) 
{
  dataCacheDouble *&r= _cacheDoubleMap[f];
  r = new dataCacheDouble(this, (function*)(f));
  return *r;
}

dataCacheMap::~dataCacheMap()
{
  for (std::set<dataCacheDouble*>::iterator it = _allDataCaches.begin();
      it!=_allDataCaches.end(); it++) {
    delete *it;
  }
}

// now some example of functions

// constant values copied over each line

functionConstant *functionConstantNew(double v) {
  std::vector<double> vec(1);
  vec[0]=v;
  return new functionConstant(vec);
}

functionConstant *functionConstantNew(const std::vector<double> &v) {
  return new functionConstant(v);
}

void functionConstant::set(double val) {
  if(getNbCol() != 1) {
    Msg::Error ("set scalar value on a vectorial constant function");
  }
  _source(0,0) = val;
}



class functionSum : public function {
  public:
  fullMatrix<double> _f0, _f1;
  void call(dataCacheMap *m, fullMatrix<double> &val) {
    for(int i=0;i<val.size1();i++)
      for(int j=0;j<val.size2();j++){
        val(i,j)= _f0(i,j) + _f1(i,j);
      }
  }
  functionSum(const function *f0, const function *f1):function(f0->getNbCol()){
    if (f0->getNbCol() != f1->getNbCol()) {
      Msg::Error("trying to sum 2 functions of different sizes\n");
      throw;
    }
    setArgument (_f0, f0);
    setArgument (_f1, f1);
  }
};

function *functionSumNew(const function *f0, const function *f1) {
  return new functionSum (f0, f1);
}




// get XYZ coordinates
class functionCoordinates : public function {
  static functionCoordinates *_instance;
  fullMatrix<double> uvw;
  void call (dataCacheMap *m, fullMatrix<double> &xyz){
    for(int i = 0; i < uvw.size1(); i++){
      SPoint3 p;
      m->getElement()->pnt(uvw(i, 0), uvw(i, 1), uvw(i, 2), p);
      xyz(i, 0) = p.x();
      xyz(i, 1) = p.y();
      xyz(i, 2) = p.z();
    }
  }
  functionCoordinates():function(3)
  {
    setArgument(uvw, function::getParametricCoordinates());
  };// constructor is private only 1 instance can exists, call get to access the instance
 public:
  static function *get() {
    if(!_instance)
      _instance = new functionCoordinates();
    return _instance;
  }
};
functionCoordinates *functionCoordinates::_instance = NULL;

functionSolution *functionSolution::_instance = NULL;
function *function::getSolution() {
  return functionSolution::get();
}

class functionSolutionGradient : public function {
  static functionSolutionGradient *_instance;
  functionSolutionGradient():function(0){} // constructor is private only 1 instance can exists, call get to access the instance
 public:
  void call(dataCacheMap *m, fullMatrix<double> &sol) {
    Msg::Error("a function requires the gradient of the solution but this algorithm does not provide the gradient of the solution");
    throw;
  }
  static function *get() {
    if(!_instance)
      _instance = new functionSolutionGradient();
    return _instance;
  }
};
functionSolutionGradient *functionSolutionGradient::_instance = NULL;
function *function::getSolutionGradient() {
  return functionSolutionGradient::get();
}

class functionParametricCoordinates : public function {
  static functionParametricCoordinates *_instance;
  functionParametricCoordinates():function(0, false){} // constructor is private only 1 instance can exists, call get to access the instance
 public:
  void call(dataCacheMap *m, fullMatrix<double> &sol) {
    Msg::Error("a function requires the parametric coordinates but this algorithm does not provide the parametric coordinates");
    throw;
  }
  static function *get() {
    if(!_instance)
      _instance = new functionParametricCoordinates();
    return _instance;
  }
};
functionParametricCoordinates *functionParametricCoordinates::_instance = NULL;
function *function::getParametricCoordinates() {
  return functionParametricCoordinates::get();
}

class functionNormals : public function {
  static functionNormals *_instance;
  functionNormals():function(0){} // constructor is private only 1 instance can exists, call get to access the instance
 public:
  void call(dataCacheMap *m, fullMatrix<double> &sol) {
    Msg::Error("a function requires the normals coordinates but this algorithm does not provide the normals");
    throw;
  }
  static function *get() {
    if(!_instance)
      _instance = new functionNormals();
    return _instance;
  }
};
functionNormals *functionNormals::_instance = NULL;
function *function::getNormals() {
  return functionNormals::get();
}

class functionStructuredGridFile : public function {
  fullMatrix<double> coord;
  public:
  int n[3];
  double d[3],o[3];
  double get(int i,int j, int k){
    return v[(i*n[1]+j)*n[2]+k];
  }
  double *v;
  void call(dataCacheMap *m, fullMatrix<double> &val){
    for(int pt=0;pt<val.size1();pt++){
      double xi[3];
      int id[3];
      for(int i=0;i<3;i++){
        id[i]=(int)((coord(pt,i)-o[i])/d[i]);
        int a=id[i];
        id[i]=std::max(0,std::min(n[i]-1,id[i]));
        xi[i]=(coord(pt,i)-o[i]-id[i]*d[i])/d[i];
        xi[i]=std::min(1.,std::max(0.,xi[i]));
      }
      val(pt,0) =
        get(id[0]   ,id[1]   ,id[2]   )*(1-xi[0])*(1-xi[1])*(1-xi[2])
        +get(id[0]   ,id[1]   ,id[2]+1 )*(1-xi[0])*(1-xi[1])*(  xi[2])
        +get(id[0]   ,id[1]+1 ,id[2]   )*(1-xi[0])*(  xi[1])*(1-xi[2])
        +get(id[0]   ,id[1]+1 ,id[2]+1 )*(1-xi[0])*(  xi[1])*(  xi[2])
        +get(id[0]+1 ,id[1]   ,id[2]   )*(  xi[0])*(1-xi[1])*(1-xi[2])
        +get(id[0]+1 ,id[1]   ,id[2]+1 )*(  xi[0])*(1-xi[1])*(  xi[2])
        +get(id[0]+1 ,id[1]+1 ,id[2]   )*(  xi[0])*(  xi[1])*(1-xi[2])
        +get(id[0]+1 ,id[1]+1 ,id[2]+1 )*(  xi[0])*(  xi[1])*(  xi[2]);
    }
  }
  functionStructuredGridFile(const std::string filename, const function *coordFunction): function(1) {
    setArgument(coord, coordFunction);
    std::ifstream input(filename.c_str());
    if(!input)
      Msg::Error("cannot open file : %s",filename.c_str());
    if(filename.substr(filename.size()-4,4)!=".bin") {
      input>>o[0]>>o[1]>>o[2]>>d[0]>>d[1]>>d[2]>>n[0]>>n[1]>>n[2];
      int nt = n[0]*n[1]*n[2];
      v = new double [nt];
      for (int i=0; i<nt; i++){
        input>>v[i];
      }
    } else {
      input.read((char *)o, 3 * sizeof(double));
      input.read((char *)d, 3 * sizeof(double));
      input.read((char *)n, 3 * sizeof(int));
      int nt = n[0] * n[1] * n[2];
      v = new double[nt];
      input.read((char *)v, nt * sizeof(double));
    }
  }
  ~functionStructuredGridFile(){
    delete []v;
  }
};

#ifdef HAVE_LUA
class functionLua : public function {
  lua_State *_L;
  std::string _luaFunctionName;
  std::vector<fullMatrix<double> > args;
 public:
  void call (dataCacheMap *m, fullMatrix<double> &res) {
    lua_getfield(_L, LUA_GLOBALSINDEX, _luaFunctionName.c_str());
    for (int i=0;i< arguments.size(); i++)
      luaStack<const fullMatrix<double>*>::push(_L, &args[i]);
    luaStack<const fullMatrix<double>*>::push(_L, &res);
    lua_call(_L, arguments.size()+1, 0);
  }
  functionLua (int nbCol, std::string luaFunctionName, std::vector<const function*> dependencies, lua_State *L)
    : function(nbCol), _luaFunctionName(luaFunctionName), _L(L)
  {
    args.resize(dependencies.size());
    for (int i = 0; i < dependencies.size(); i++) { setArgument(args[i], dependencies[i]);
    }
  }
};
#endif



void dataCacheMap::setNbEvaluationPoints(int nbEvaluationPoints) {
  _nbEvaluationPoints = nbEvaluationPoints;
  for(std::set<dataCacheDouble*>::iterator it = _allDataCaches.begin(); it!= _allDataCaches.end(); it++){
    (*it)->resize();
    (*it)->_valid = false;
  }
    for(std::list<dataCacheMap*>::iterator it = _children.begin(); it!= _children.end(); it++) {
      (*it)->setNbEvaluationPoints(nbEvaluationPoints);
    }
}

//functionC
class functionC : public function {
  std::vector<fullMatrix<double> > args;
  void (*callback)(void);
  public:
  static void buildLibrary(std::string code, std::string filename) {
    //todo use CMAKE_CXX_COMPILER
    //todo use clean temporary file names
    //todo work on windows :-)
    //todo if DG_BUILD_DIR is not defined, use the directory used at compilation time
    FILE *tmpSrc = fopen("_tmpSrc.cpp","w");
    fprintf(tmpSrc, "%s\n",code.c_str());
    fclose(tmpSrc);
    FILE *tmpMake = fopen("_tmpMake","w");
    fprintf(tmpMake, "include $(DG_BUILD_DIR)/CMakeFiles/dg.dir/flags.make\n"
        "%s : %s\n"
        "\tg++ -fPIC -shared -o $@ $(CXX_FLAGS) $(CXX_DEFINES) $<\n",
        filename.c_str(), "_tmpSrc.cpp");
    fclose(tmpMake);
    if(system("make -f _tmpMake"))
      Msg::Error("make command failed\n");
    unlink ("_tmpSrc.cpp");
    unlink ("_tmpMake.cpp");
  }
  void call (dataCacheMap *m, fullMatrix<double> &val) {
    switch (args.size()) {
      case 0 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &))(callback))(m, val);
        break;
      case 1 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &, const fullMatrix<double>&))
         (callback)) (m, val, args[0]);
        break;
      case 2 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double> &))
         (callback)) (m, val, args[0], args[1]);
        break;
      case 3 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&))
         (callback)) (m, val, args[0], args[1], args[2]);
        break;
      case 4 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&,
                   const fullMatrix<double>&))
         (callback)) (m, val, args[0], args[1], args[2], args[3]);
        break;
      case 5 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&,
                   const fullMatrix<double>&, const fullMatrix<double>&))
         (callback)) (m, val, args[0], args[1], args[2], args[3], args[4]);
        break;
      case 6 : 
        ((void (*)(dataCacheMap*, fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&,
                   const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&))
         (callback)) (m, val, args[0], args[1], args[2], args[3], args[4], args[5]);
        break;
      default :
        Msg::Error("C callback not implemented for %i argurments", args.size());
    }
  }
  functionC (std::string file, std::string symbol, int nbCol, std::vector<const function *> dependencies):
    function(nbCol)
  {
#if defined(HAVE_DLOPEN)
    args.resize(dependencies.size());
    for(int i=0; i < dependencies.size(); i++) {
      setArgument(args[i], dependencies[i]);
    }
    void *dlHandler;
    dlHandler = dlopen(file.c_str(),RTLD_NOW);
    callback = (void(*)(void))dlsym(dlHandler, symbol.c_str());
    if(!callback)
      Msg::Error("Cannot get the callback to the compiled C function");
#else
    Msg::Error("Cannot construct functionC without dlopen");
#endif
  }
};

void function::registerBindings(binding *b){
  classBinding *cb = b->addClass<function>("Function");
  cb->setDescription("A generic function that can be evaluated on a set of points. Functions can call other functions and their values are cached so that if two different functions call the same function f, f is only evaluated once.");
  methodBinding *mb;

  mb = cb->addMethod("getTime", &function::getTime);
  mb->setDescription("Return function constant in space which contains the time value");

  cb = b->addClass<functionConstant>("functionConstant");
  cb->setDescription("A constant (scalar or vector) function");
  mb = cb->setConstructor<functionConstant,std::vector <double> >();
  mb->setArgNames("v",NULL);
  mb->setDescription("A new constant function wich values 'v' everywhere. v can be a row-vector.");
  cb->setParentClass<function>();

  cb = b->addClass<functionCoordinates>("functionCoordinates");
  cb->setDescription("A function to access the coordinates (xyz). This is a single-instance class, use the 'get' member to access the instance.");
  mb = cb->addMethod("get",&functionCoordinates::get);
  mb->setDescription("return the unique instance of this class");
  cb->setParentClass<function>();

  cb = b->addClass<functionSolution>("functionSolution");
  cb->setDescription("A function to access the solution. This is a single-instance class, use the 'get' member to access the instance.");
  mb = cb->addMethod("get",&functionSolution::get);
  mb->setDescription("return the unique instance of this class");
  cb->setParentClass<function>();

  cb = b->addClass<functionNormals>("functionNormals");
  cb->setDescription("A function to access the face normals. This is a single-instance class, use the 'get' member to access the instance.");
  mb = cb->addMethod("get",&functionNormals::get);
  mb->setDescription("return the unique instance of this class");
  cb->setParentClass<function>();

  cb = b->addClass<functionSolutionGradient>("functionSolutionGradient");
  cb->setDescription("A function to access the gradient of the solution. This is a single-instance class, use the 'get' member to access the instance.");
  mb = cb->addMethod("get",&functionCoordinates::get);
  mb->setDescription("return the unique instance of this class");
  cb->setParentClass<function>();

  cb = b->addClass<functionStructuredGridFile>("functionStructuredGridFile");
  cb->setParentClass<function>();
  cb->setDescription("A function to interpolate through data given on a structured grid");
  mb = cb->setConstructor<functionStructuredGridFile,std::string, const function*>();
  mb->setArgNames("fileName","coordinateFunction",NULL);
  mb->setDescription("Tri-linearly interpolate through data in file 'fileName' at coordinate given by 'coordinateFunction'.\nThe file format is :\nx0 y0 z0\ndx dy dz\nnx ny nz\nv(0,0,0) v(0,0,1) v(0 0 2) ...");

#if defined(HAVE_DLOPEN)
  cb = b->addClass<functionC>("functionC");
  cb->setDescription("A function that compile a C code");
  mb = cb->setConstructor<functionC,std::string, std::string,int,std::vector<const function*> >();
  mb->setArgNames("file", "symbol", "nbCol", "arguments",NULL);
  mb->setDescription("  ");
  mb = cb->addMethod("buildLibrary", &functionC::buildLibrary);
  mb->setArgNames("code", "libraryFileName",NULL);
  mb->setDescription("build a dynamic library from the given code");
  cb->setParentClass<function>();
#endif

#if defined (HAVE_LUA)
  cb= b->addClass<functionLua>("functionLua");
  cb->setDescription("A function (see the 'function' documentation entry) defined in LUA.");
  mb = cb->setConstructor<functionLua,int,std::string,std::vector<const function*>,lua_State*>();
  mb->setArgNames("d", "f", "dep", NULL);
  mb->setDescription("A new functionLua which evaluates a vector of dimension 'd' using the lua function 'f'. This function can take other functions as arguments listed by the 'dep' vector.");
  cb->setParentClass<function>();
#endif
}

void functionReplace::replace(fullMatrix<double> &v, const function *f, int iMap) {
  _toReplace.push_back(function::argument(v, iMap, f));
}

void functionReplace::get(fullMatrix<double> &v, const function *f, int iMap) {
  _toCompute.push_back(function::argument(v, iMap, f));
}

void functionReplace::compute(){
  for (int i = 0; i < _toReplace.size(); i++){
    currentCache->toReplace[i]->set();
  }
  for (int i = 0; i < _toCompute.size(); i++) {
    currentCache->toCompute[i]->_valid =false;
    _toCompute[i].val->setAsProxy((*currentCache->toCompute[i])());
  }
};


functionReplaceCache::functionReplaceCache(dataCacheMap *m, functionReplace *rep, dataCacheDouble *from) {
  map = m->newChild();
  for (int i = 0; i < m->_secondaryCaches.size(); i ++) {
    map->addSecondaryCache (m->getSecondaryCache(i+1)->newChild());
  }
  for (int i = 0; i < rep->_toReplace.size(); i++) {
    toReplace.push_back (&map->getSecondaryCache(rep->_toReplace[i].iMap)->substitute(rep->_toReplace[i].f));
  }
  for (int i = 0; i < rep->_toCompute.size(); i++) {
    dataCacheMap *m2 = map->getSecondaryCache(rep->_toCompute[i].iMap);
    toCompute.push_back (&m2->get(rep->_toCompute[i].f, from));
  }
}
functionReplaceCache::~functionReplaceCache() {
  for (int i = 0; i< map->_secondaryCaches.size(); i++) {
    delete map->_secondaryCaches[i];
  }
  delete map;
}
functionConstant *function::_timeFunction = NULL;
functionConstant *function::getTime() {
  if (! _timeFunction)
    _timeFunction = functionConstantNew(0.);
  return _timeFunction;
}
functionConstant *function::_dtFunction = NULL;
functionConstant *function::getDT() {
  if (! _dtFunction)
    _dtFunction = functionConstantNew(0.);
  return _dtFunction;
}
