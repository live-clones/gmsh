#ifndef _FUNCTION_NUMPY_H_
#define _FUNCTION_NUMPY_H_
#include "GmshConfig.h"
#ifdef HAVE_NUMPY
#include "Python.h"
#include "numpy/arrayobject.h"

class functionNumpy : public function {
  PyObject *_pycallback;
  std::vector<fullMatrix<double> > args;
public:
  static PyObject *pyArrayFromFullMatrix(fullMatrix<double> &m) {
    long int n[2] = {m.size1(), m.size2()};
    return PyArray_New(&PyArray_Type, 2, n, NPY_DOUBLE, NULL, &m(0, 0), 0, NPY_FARRAY, NULL);
  }
  void call (dataCacheMap *m, fullMatrix<double> &res) 
  {
    PyObject *swigR;
    PyObject *pyargs;
    std::vector<PyObject*> swigA(args.size());
    swigR = pyArrayFromFullMatrix(res);
    for (int i = 0; i < args.size(); i++) {
      swigA[i] = pyArrayFromFullMatrix(args[i]);
    }
    switch(args.size()) {
      case 0 : pyargs = Py_BuildValue("(N)", swigR); break;
      case 1 : pyargs = Py_BuildValue("(NN)", swigR, swigA[0]); break;
      case 2 : pyargs = Py_BuildValue("(NNN)", swigR, swigA[0], swigA[1]); break;
      case 3 : pyargs = Py_BuildValue("(NNNN)", swigR, swigA[0], swigA[1], swigA[2]); break;
      case 4 : pyargs = Py_BuildValue("(NNNNN)", swigR, swigA[0], swigA[1], swigA[2], swigA[3]); break;
      case 5 : pyargs = Py_BuildValue("(NNNNNN)", swigR, swigA[0], swigA[1], swigA[2], swigA[3], swigA[4]); break;
      case 6 : pyargs = Py_BuildValue("(NNNNNNN)", swigR, swigA[0], swigA[1], swigA[2], swigA[3], swigA[4], swigA[5]); break;
      case 7 : pyargs = Py_BuildValue("(NNNNNNNN)", swigR, swigA[0], swigA[1], swigA[2], swigA[3], swigA[4], swigA[5], swigA[6]); break;
      case 8 : pyargs = Py_BuildValue("(NNNNNNNNN)", swigR, swigA[0], swigA[1], swigA[2], swigA[3], swigA[4], swigA[5], swigA[6], swigA[7]); break;
      default:Msg::Error("python function not implemented for more than 8 arguments");
    }
    PyObject *result = PyEval_CallObject(_pycallback, pyargs);
    if (result) {
      Py_DECREF(result);
    }
    else {
      PyErr_Print();
      Msg::Fatal("An error occurs in the python function.");
    }
/*    for (int i = 0; i < args.size(); i++) {
      Py_DECREF(swigA[i]);
    }
    Py_DECREF(swigR);*/
  }
  functionNumpy (int nbCol, PyObject *callback, std::vector<const function*> dependencies)
    : function(nbCol), _pycallback(callback)
  {
    args.resize(dependencies.size());
    for (int i = 0; i < dependencies.size(); i++) {
      setArgument(args[i], dependencies[i]);
    }
    static bool _arrayImported = false;
    if (! _arrayImported){
      _import_array();
      _arrayImported = true;
    }
  }
  functionNumpy (int nbCol, PyObject *callback, std::vector<std::pair<const function*, int> > dependencies)
    : function(nbCol), _pycallback(callback)
  {
    args.resize(dependencies.size());
    for (int i = 0; i < dependencies.size(); i++) {
      setArgument(args[i], dependencies[i].first, dependencies[i].second);
    }
    printf("import array !!!\n");
    static bool _arrayImported = false;
    if (! _arrayImported) {
      printf("import array !!!\n");
      _import_array();
      _arrayImported = true;
    }
  }
};
#endif
#endif
