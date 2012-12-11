#ifndef _SIMPLE_FUNCTION_PYTHON_H_
#define _SIMPLE_FUNCTION_PYTHON_H_
#include "Python.h"
#include "simpleFunction.h"

class simpleFunctionPython : public simpleFunction<double> {
  PyObject *_pycallback;
 public:
  simpleFunctionPython(PyObject *callback):
    _pycallback(callback)
  {
    Py_INCREF(_pycallback);
  }
  ~simpleFunctionPython()
  {
    Py_DECREF(_pycallback);
  }
  double operator()(double x, double y, double z) const
  {
    PyObject *pyargs = Py_BuildValue("(ddd)", x, y, z);
    PyObject *result = PyEval_CallObject(_pycallback, pyargs);
    double r = 0;
    if (result) {
      int ok = PyArg_Parse(result, "d", &r);
      if (not ok)
        Msg::Error("The python function did not return a double.");
      Py_DECREF(result);
    }
    else {
      PyErr_Print();
      Msg::Error("An error occurs in the python simple function.");
    }
    Py_DECREF(pyargs);
    return r;
  }
};
#endif
