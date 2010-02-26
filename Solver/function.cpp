#include <sstream>
#include <fstream>
#include "function.h"
#include "SPoint3.h"
#include "MElement.h"
#include "dgDofContainer.h"
#include "dgGroupOfElements.h"
#include "GModel.h"

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

dataCacheDouble &dataCacheMap::get(const std::string &functionName, dataCache *caller) 
{
  dataCacheDouble *&r= _cacheDoubleMap[functionName];
  if(r==NULL)
    r = function::get(functionName)->newDataCache(this);
  if(caller)
    r->addMeAsDependencyOf(caller);
  return *r;
}

dataCacheDouble &dataCacheMap::provideData(std::string name,int nRowByPoints, int nCol)
{
  if (_cacheDoubleMap[name] != NULL)
    throw;
  dataCacheDouble *r = new providedDataDouble(*this,nRowByPoints, nCol);
  _cacheDoubleMap[name] = r;
  return *r;
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
class functionXYZ : public function {
 private:
  class data : public dataCacheDouble{
   private:
    dataCacheElement &_element;
    dataCacheDouble &_uvw;
  int count;
   public:
    data(dataCacheMap *m) : 
      dataCacheDouble(*m, 1,3),
      _element(m->getElement(this)), _uvw(m->get("UVW", this))
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
 public:
  dataCacheDouble *newDataCache(dataCacheMap *m)
  {
    return new data(m);
  }
};

class functionStructuredGridFile : public function {
  public:
  class data;
  std::string _coordFunction;
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
  functionStructuredGridFile(const std::string filename, const std::string coordFunction){
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
    xyz(m.get("XYZ",this)),
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
void dataCacheMap::setNbEvaluationPoints(int nbEvaluationPoints) {
  _nbEvaluationPoints = nbEvaluationPoints;
  for(std::map<std::string, dataCacheDouble*>::iterator it = _cacheDoubleMap.begin(); it!= _cacheDoubleMap.end(); it++)
    it->second->resize();
}

dataCacheDouble *functionMesh2Mesh::newDataCache(dataCacheMap *m)
{
  return new data(*m,_dofContainer);
}


dataCacheDouble::dataCacheDouble(dataCacheMap &map,int nRowByPoint, int nCol):
  dataCache(&map),_cacheMap(map),_value(nRowByPoint==0?1:nRowByPoint*map.getNbEvaluationPoints(),nCol){
    _nRowByPoint=nRowByPoint;
};
void dataCacheDouble::resize() {
  _value = fullMatrix<double>(_nRowByPoint==0?1:_nRowByPoint*_cacheMap.getNbEvaluationPoints(),_value.size2());
}

#include "Bindings.h"

void function::registerDefaultFunctions()
{
  function::add("XYZ", new functionXYZ);
}
void function::registerBindings(binding *b){
  classBinding *cb = b->addClass<function>("function");
  cb->setDescription("A generic function that can be evaluated on a set of points. Functions can call other functions and their values are cached so that if two different functions call the same function f, f is only evaluated once.");
  methodBinding *mb;
  mb = cb->addMethod("getName",&function::getName);
  mb->setDescription("Return the string which identifies this function.");

  cb = b->addClass<functionConstant>("functionConstant");
  cb->setDescription("A constant (scalar or vector) function");
  mb = cb->setConstructor<functionConstant,fullMatrix<double>*>();
  mb->setArgNames("v",NULL);
  mb->setDescription("A new constant function wich values 'v' everywhere. v can be a row-vector.");
  cb->setParentClass<function>();

  cb = b->addClass<functionStructuredGridFile>("functionStructuredGridFile");
  cb->setParentClass<function>();
  cb->setDescription("A function to interpolate through data given on a structured grid");
  mb = cb->setConstructor<functionStructuredGridFile,std::string, std::string>();
  mb->setArgNames("fileName","coordinateFunction",NULL);
  mb->setDescription("Tri-linearly interpolate through data in file 'fileName' at coordinate given by 'coordinateFunction'.\nThe file format is :\nx0 y0 z0\ndx dy dz\nnx ny nz\nv(0,0,0) v(0,0,1) v(0 0 2) ..."); 

  cb = b->addClass<functionMesh2Mesh>("functionMesh2Mesh");
  cb->setDescription("A function that can be used to interpolate into a given mesh");
  mb = cb->setConstructor<functionMesh2Mesh,dgDofContainer*>();
  mb->setArgNames("solution",NULL);
  mb->setDescription("A solution.");
  cb->setParentClass<function>();


}

