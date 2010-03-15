#include "GmshConfig.h"
#include <sstream>
#include <fstream>
#include "function.h"
#include "SPoint3.h"
#include "MElement.h"
#include "dgDofContainer.h"
#include "dgGroupOfElements.h"
#include "GModel.h"

#if defined(HAVE_DLOPEN)
  #include "dlfcn.h"
#endif

// dataCache members
dataCache::dataCache(dataCacheMap *cacheMap) : _valid(false) {
  cacheMap->addDataCache(this); //this dataCache can be deleted when the dataCacheMap is deleted
}

void dataCache::addMeAsDependencyOf (dataCache *newDep)
{
  _dependOnMe.insert(newDep);
  newDep->_iDependOn.insert(this);
  for(std::set<dataCache*>::iterator it = _iDependOn.begin();
      it != _iDependOn.end(); it++) {
    (*it)->_dependOnMe.insert(newDep);
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
    else{
      Msg::Error("unknown function : '%s'\n",functionName.c_str());
      throw;
    }
  }
  return it->second;
}
//dataCacheMap members

dataCacheElement &dataCacheMap::getElement(dataCache *caller) 
{
  if(caller)
    _cacheElement->addMeAsDependencyOf(caller);
  return *_cacheElement;
}

static dataCacheDouble &returnDataCacheDouble(dataCacheDouble *data, dataCache *caller)
{
  if(data==NULL) throw;
  if(caller)
    data->addMeAsDependencyOf(caller);
  return *data;
}
dataCacheDouble &dataCacheMap::get(const function *f, dataCache *caller) 
{
  dataCacheDouble *&r= _cacheDoubleMap[f];
  if(r==NULL)
    r = const_cast<function*>(f)->newDataCache(this);
  return returnDataCacheDouble(r,caller);
}
dataCacheDouble &dataCacheMap::getSolution(dataCacheDouble *caller) 
{
  return returnDataCacheDouble(_solution,caller);
}
dataCacheDouble &dataCacheMap::getSolutionGradient(dataCacheDouble *caller)
{
  return returnDataCacheDouble(_solutionGradient,caller);
}
dataCacheDouble &dataCacheMap::getParametricCoordinates(dataCacheDouble *caller) 
{
  return returnDataCacheDouble(_parametricCoordinates,caller);
}
dataCacheDouble &dataCacheMap::getNormals(dataCacheDouble *caller)
{
  returnDataCacheDouble(_normals,caller);
  return *_normals;
}





dataCacheDouble &dataCacheMap::provideSolution(int nbFields)
{
  _solution = new providedDataDouble(*this,1, nbFields);
  return *_solution;
}
dataCacheDouble &dataCacheMap::provideSolutionGradient(int nbFields){
  _solutionGradient =  new providedDataDouble(*this,3, nbFields);
  return *_solutionGradient;
}
dataCacheDouble &dataCacheMap::provideParametricCoordinates()
{
  _parametricCoordinates = new providedDataDouble(*this,1, 3);
  return *_parametricCoordinates;
}
dataCacheDouble &dataCacheMap::provideNormals()
{
  _normals = new providedDataDouble(*this,1, 3);
  return *_normals;
}

dataCacheMap::~dataCacheMap()
{
  for (std::set<dataCache*>::iterator it = _toDelete.begin();
      it!=_toDelete.end(); it++) {
    delete *it;
  }
}

// now some example of functions

// get XYZ coordinates
class functionCoordinates : public function {
  static functionCoordinates *_instance;
  class data : public dataCacheDouble{
    dataCacheElement &_element;
    dataCacheDouble &_uvw;
    int count;
    public:
    data(dataCacheMap *m) : 
      dataCacheDouble(*m, 1,3),
      _element(m->getElement(this)), _uvw(m->getParametricCoordinates(this))
    {
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
    ~data(){
    }
  };
  functionCoordinates(){};// constructor is private only 1 instance can exists, call get to access the instance
 public:
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return new data(m);
  }
  static function *get() {
    if(!_instance)
      _instance = new functionCoordinates();
    return _instance;
  }
};
functionCoordinates *functionCoordinates::_instance = NULL;

class functionSolution : public function {
  static functionSolution *_instance;
  functionSolution(){};// constructor is private only 1 instance can exists, call get to access the instance
 public:
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return &m->getSolution(NULL);
  }
  static function *get() {
    if(!_instance)
      _instance = new functionSolution();
    return _instance;
  }
};
functionSolution *functionSolution::_instance = NULL;

class functionSolutionGradient : public function {
  static functionSolutionGradient *_instance;
  functionSolutionGradient(){};// constructor is private only 1 instance can exists, call get to access the instance
 public:
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return &m->getSolutionGradient(NULL);
  }
  static function *get() {
    if(!_instance)
      _instance = new functionSolutionGradient();
    return _instance;
  }
};
functionSolutionGradient *functionSolutionGradient::_instance = NULL;

class functionStructuredGridFile : public function {
  public:
  class data;
  const function *_coordFunction;
  int n[3];
  double d[3],o[3];
  double get(int i,int j, int k){
    return v[(i*n[1]+j)*n[2]+k];
  }
  double *v;
  class data : public dataCacheDouble{
    dataCacheDouble &coord;
    functionStructuredGridFile *_fun;
    public:
    data(functionStructuredGridFile *fun, dataCacheMap *m):
      dataCacheDouble(*m,1,1),
      coord(m->get(fun->_coordFunction,this))
    {
      _fun=fun;
    }
    void _eval(){
      for(int pt=0;pt<_value.size1();pt++){
        double xi[3];
        int id[3];
        for(int i=0;i<3;i++){
          id[i]=(int)((coord(pt,i)-_fun->o[i])/_fun->d[i]);
	int a=id[i];
          id[i]=std::max(0,std::min(_fun->n[i]-1,id[i]));
          xi[i]=(coord(pt,i)-_fun->o[i]-id[i]*_fun->d[i])/_fun->d[i];
          xi[i]=std::min(1.,std::max(0.,xi[i]));
        }
        _value(pt,0) =
           _fun->get(id[0]   ,id[1]   ,id[2]   )*(1-xi[0])*(1-xi[1])*(1-xi[2])
          +_fun->get(id[0]   ,id[1]   ,id[2]+1 )*(1-xi[0])*(1-xi[1])*(  xi[2])
          +_fun->get(id[0]   ,id[1]+1 ,id[2]   )*(1-xi[0])*(  xi[1])*(1-xi[2])
          +_fun->get(id[0]   ,id[1]+1 ,id[2]+1 )*(1-xi[0])*(  xi[1])*(  xi[2])
          +_fun->get(id[0]+1 ,id[1]   ,id[2]   )*(  xi[0])*(1-xi[1])*(1-xi[2])
          +_fun->get(id[0]+1 ,id[1]   ,id[2]+1 )*(  xi[0])*(1-xi[1])*(  xi[2])
          +_fun->get(id[0]+1 ,id[1]+1 ,id[2]   )*(  xi[0])*(  xi[1])*(1-xi[2])
          +_fun->get(id[0]+1 ,id[1]+1 ,id[2]+1 )*(  xi[0])*(  xi[1])*(  xi[2]);
      }
    }
  };
  dataCacheDouble *newDataCache(dataCacheMap* m) {
    return new data(this,m);
  }
  functionStructuredGridFile(const std::string filename, const function *coordFunction){
    _coordFunction=coordFunction;
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
    static int c=0;
    std::ostringstream oss;
    oss<<"FunctionStructured"<<c++;
    _name = oss.str();
    function::add(_name,this);
  }
  ~functionStructuredGridFile(){
    delete []v;
  }
};


// constant values copied over each line
class functionConstant::data : public dataCacheDouble {
 const functionConstant *_function;
 public:
 data(const functionConstant * function,dataCacheMap *m):
   dataCacheDouble(*m,1,function->_source.size1()){
     _function = function;
   }
 void _eval() {
   for(int i=0;i<_value.size1();i++)
     for(int j=0;j<_function->_source.size1();j++)
       _value(i,j)=_function->_source(j,0);
 }
};
dataCacheDouble *functionConstant::newDataCache(dataCacheMap *m)
{
 return new data(this,m);
}

functionConstant::functionConstant(const fullMatrix<double> *source){
 _source = *source;
  static int c=0;
  std::ostringstream oss;
  oss<<"FunctionConstant_"<<c++;
  _name = oss.str();
  function::add(_name,this);
}

functionConstant::functionConstant(std::vector<double> source){
  _source = fullMatrix<double>(source.size(),1);
  for(size_t i=0; i<source.size(); i++){
    _source(i,0) = source[i];
  }
  static int c=0;
  std::ostringstream oss;
  oss<<"FunctionConstant_"<<c++;
  _name = oss.str();
  function::add(_name,this);
}


// function that enables to interpolate a DG solution using
// geometrical search in a mesh 

functionMesh2Mesh::functionMesh2Mesh(dgDofContainer *dofc) 
  : _dofContainer(dofc) 
{
  static int c=0;
  std::ostringstream oss;
  oss<<"FunctionMesh2Mesh_"<<c++;
  _name = oss.str();
  function::add(_name,this);
}

class functionMesh2Mesh::data : public dataCacheDouble {
  dgDofContainer  *_dofContainer;
  dataCacheDouble &xyz;
public:
  data(dataCacheMap &m, dgDofContainer *sys) :
    _dofContainer(sys), 
    xyz(m.get(functionCoordinates::get(),this)),
    dataCacheDouble(m,1, sys->getNbFields())
  {
  }
  void _eval() {
    int nP =xyz().size1();
    _value.setAll(0.0);
    double fs[256];
    fullMatrix<double> solEl;
    GModel *m = _dofContainer->getGroups()->getModel();
    for (int i=0;i<_value.size1();i++){
      const double x = xyz(i,0);
      const double y = xyz(i,1);
      const double z = xyz(i,2);
      SPoint3 p(x,y,z);
      MElement *e = m->getMeshElementByCoord(p);
      int ig,index;
      _dofContainer->getGroups()->find (e,ig,index);
      dgGroupOfElements *group =  _dofContainer->getGroups()->getElementGroup(ig);      
      double U[3],X[3]={x,y,z};
      e->xyz2uvw (X,U);
      group->getFunctionSpace().f(U[0],U[1],U[2],fs);      
      fullMatrix<double> &sol = _dofContainer->getGroupProxy(ig);
      solEl.setAsProxy(sol,index*_dofContainer->getNbFields(),_dofContainer->getNbFields());
      int fSize = group->getNbNodes();
      for (int k=0;k<_dofContainer->getNbFields();k++){
	_value(i,k) = 0.0; 	
	for (int j=0;j<fSize;j++){
	  _value(i,k) += solEl(j,k)*fs[j];
	}
      }
    }
  }
};

dataCacheDouble *functionMesh2Mesh::newDataCache(dataCacheMap *m)
{
  return new data(*m,_dofContainer);
}

void dataCacheMap::setNbEvaluationPoints(int nbEvaluationPoints) {
  _nbEvaluationPoints = nbEvaluationPoints;
  for(std::set<dataCacheDouble*>::iterator it = _toResize.begin(); it!= _toResize.end(); it++){
    (*it)->resize();
    (*it)->_valid = false;
  }
}

dataCacheDouble::dataCacheDouble(dataCacheMap &map,int nRowByPoint, int nCol):
  dataCache(&map),_cacheMap(map),_value(nRowByPoint==0?1:nRowByPoint*map.getNbEvaluationPoints(),nCol){
    _nRowByPoint=nRowByPoint;
    map.addDataCacheDouble(this);
};
void dataCacheDouble::resize() {
  _value = fullMatrix<double>(_nRowByPoint==0?1:_nRowByPoint*_cacheMap.getNbEvaluationPoints(),_value.size2());
}

#if defined(HAVE_DLOPEN)
//functionC
class functionC : public function {
  void (*callback)(void);
  std::vector<const function*> _dependenciesF;
  int _nbCol;
  class data : public dataCacheDouble{
    const functionC *_function;
    std::vector<dataCacheDouble *> _dependencies;
    public:
    data(const functionC *f, dataCacheMap *m):
      dataCacheDouble(*m,1,f->_nbCol)
    {
      _function = f;
      _dependencies.resize ( _function->_dependenciesF.size());
      for (int i=0;i<_function->_dependenciesF.size();i++)
        _dependencies[i] = &m->get(_function->_dependenciesF[i],this);

    }
    void _eval()
    {
      switch (_dependencies.size()) {
        case 0 : 
          ((void (*)(fullMatrix<double> &))(_function->callback))(_value);
          break;
        case 1 : 
          ((void (*)(fullMatrix<double> &, const fullMatrix<double>&))
            (_function->callback)) (_value,(*_dependencies[0])());
          break;
        case 2 : 
          ((void (*)(fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double> &))
            (_function->callback)) (_value,(*_dependencies[0])(), (*_dependencies[1])());
          break;
        case 3 : 
          ((void (*)(fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&))
            (_function->callback)) (_value,(*_dependencies[0])(),(*_dependencies[1])(),(*_dependencies[2])());
          break;
        case 4 : 
          ((void (*)(fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&,
              const fullMatrix<double>&))
            (_function->callback)) (_value,(*_dependencies[0])(),(*_dependencies[1])(),(*_dependencies[2])(),(*_dependencies[3])());
          break;
        case 5 : 
          ((void (*)(fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&,
              const fullMatrix<double>&, const fullMatrix<double>&))
            (_function->callback)) (_value,(*_dependencies[0])(),(*_dependencies[1])(),(*_dependencies[2])(),(*_dependencies[3])(),
              (*_dependencies[4])());
          break;
        case 6 : 
          ((void (*)(fullMatrix<double> &, const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&,
              const fullMatrix<double>&, const fullMatrix<double>&, const fullMatrix<double>&))
            (_function->callback)) (_value,(*_dependencies[0])(),(*_dependencies[1])(),(*_dependencies[2])(),(*_dependencies[3])(),
              (*_dependencies[4])(), (*_dependencies[5])());
          break;
        default :
          Msg::Error("C callback not implemented for %i argurments", _dependencies.size());
      }
    }
  };
  public:
  functionC (std::string file, std::string symbol, int nbCol, std::vector<const function *> dependencies):
      _dependenciesF(dependencies),_nbCol(nbCol)
  {
    void *dlHandler;
    dlHandler = dlopen(file.c_str(),RTLD_NOW);
    callback = (void(*)(void))dlsym(dlHandler, symbol.c_str());
    if(!callback) 
      Msg::Error("cannot get the callback to the compiled C function");

    static int c=0;
    std::ostringstream oss;
    oss<<"cFunction_"<<c++;
    _name = oss.str();
    function::add(_name,this);
  }
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return new data(this,m);
  }
};
#endif


#include "Bindings.h"

void function::registerBindings(binding *b){
  classBinding *cb = b->addClass<function>("function");
  cb->setDescription("A generic function that can be evaluated on a set of points. Functions can call other functions and their values are cached so that if two different functions call the same function f, f is only evaluated once.");
  methodBinding *mb;
  mb = cb->addMethod("getName",&function::getName);
  mb->setDescription("Return the string which identifies this function.");

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
  mb = cb->addMethod("get",&functionCoordinates::get);
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

  cb = b->addClass<functionMesh2Mesh>("functionMesh2Mesh");
  cb->setDescription("A function that can be used to interpolate into a given mesh");
  mb = cb->setConstructor<functionMesh2Mesh,dgDofContainer*>();
  mb->setArgNames("solution",NULL);
  mb->setDescription("A solution.");
  cb->setParentClass<function>();

#if defined(HAVE_DLOPEN)
  cb = b->addClass<functionC>("functionC");
  cb->setDescription("A function that compile a C code");
  mb = cb->setConstructor<functionC,std::string, std::string,int,std::vector<const function*> >();
  mb->setArgNames("file", "symbol", "nbCol", "arguments",NULL);
  mb->setDescription("  ");
  cb->setParentClass<function>();
#endif
}

