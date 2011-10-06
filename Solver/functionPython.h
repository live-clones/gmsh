#ifndef _FUNCTION_PYTHON_H_
#define _FUNCTION_PYTHON_H_
#include "Python.h"
class functionPythonReturnMatrix : public fullMatrix<double> {
  dataCacheMap *_cacheMap;
  public:
  void setDataCacheMap(dataCacheMap *cacheMap) {_cacheMap = cacheMap;}
  dataCacheMap *getDataCacheMap() const {return _cacheMap;}
};

class functionPython : public function {
  PyObject *_pycallback, *_pyargs;
  PyObject *_swigR, *_swigCacheMap;
  std::vector<PyObject*> _swigA;
  std::string _luaFunctionName;
  std::vector<fullMatrix<double> > args;
  functionPythonReturnMatrix R;
  void _init() {
    _swigA.resize(args.size());
    _swigR = SWIG_NewPointerObj((void*)&R,SWIGTYPE_p_functionPythonReturnMatrix, 0);
    for (int i = 0; i < args.size(); i++) {
      _swigA[i] = SWIG_NewPointerObj((void*)&args[i],SWIGTYPE_p_fullMatrixT_double_t, 0);
    }
    switch(args.size()) {
      case 0 : _pyargs = Py_BuildValue("(O)", _swigR); break;
      case 1 : _pyargs = Py_BuildValue("(OO)", _swigR, _swigA[0]); break;
      case 2 : _pyargs = Py_BuildValue("(OOO)", _swigR, _swigA[0], _swigA[1]); break;
      case 3 : _pyargs = Py_BuildValue("(OOOO)", _swigR, _swigA[0], _swigA[1], _swigA[2]); break;
      case 4 : _pyargs = Py_BuildValue("(OOOOO)", _swigR, _swigA[0], _swigA[1], _swigA[2], _swigA[3]); break;
      case 5 : _pyargs = Py_BuildValue("(OOOOOO)", _swigR, _swigA[0], _swigA[1], _swigA[2], _swigA[3], _swigA[4]); break;
      case 6 : _pyargs = Py_BuildValue("(OOOOOOO)", _swigR, _swigA[0], _swigA[1], _swigA[2], _swigA[3], _swigA[4], _swigA[5]); break;
      case 7 : _pyargs = Py_BuildValue("(OOOOOOOO)", _swigR, _swigA[0], _swigA[1], _swigA[2], _swigA[3], _swigA[4], _swigA[5], _swigA[6]); break;
      case 8 : _pyargs = Py_BuildValue("(OOOOOOOOO)", _swigR, _swigA[0], _swigA[1], _swigA[2], _swigA[3], _swigA[4], _swigA[5], _swigA[6], _swigA[7]); break;
      default:Msg::Error("python function not implemented for more than 8 arguments");
    }
    
  }
 public:
  void call (dataCacheMap *m, fullMatrix<double> &res) 
  {
    R.setAsProxy(res); 
    R.setDataCacheMap(m);
    PyObject *result = PyEval_CallObject(_pycallback, _pyargs);
    if (result) {
      Py_DECREF(result);
    }
    else {
      PyErr_Print();
      Msg::Fatal("An error occurs in the python function.");
    }
  }
  functionPython (int nbCol, PyObject *callback, std::vector<const function*> dependencies)
    : function(nbCol), _pycallback(callback)
  {
    args.resize(dependencies.size());
    _swigA.resize(args.size());
    for (int i = 0; i < dependencies.size(); i++) {
      setArgument(args[i], dependencies[i]);
    }
    _init();
  }
  functionPython (int nbCol, PyObject *callback, std::vector<std::pair<const function*, int> > dependencies)
    : function(nbCol), _pycallback(callback)
  {
    args.resize(dependencies.size());
    _swigA.resize(args.size());
    for (int i = 0; i < dependencies.size(); i++) {
      printf("%p %i\n", dependencies[i].first, dependencies[i].second);
      setArgument(args[i], dependencies[i].first, dependencies[i].second);
    }
    _init();
  }
};
#endif
