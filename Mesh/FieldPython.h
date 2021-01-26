// Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef FIELD_PYTHON_H
#define FIELD_PYTHON_H

#include "Field.h"
#include "Python.h"

class FieldPython : public Field {
  PyObject *_callback;

public:
  const char *getName() { return "Python"; }

  std::string getDescription() { return "simple call to a python function"; }

  FieldPython(PyObject *cb, PyObject *arg = NULL)
  {
    _callback = cb;
    Py_INCREF(_callback);
  }

  ~FieldPython() { Py_DECREF(_callback); }

  double operator()(double x, double y, double z, GEntity *ge = 0)
  {
    PyObject *pyge = SWIG_NewPointerObj((void *)ge, SWIGTYPE_p_GEntity, 0);
    PyObject *args = Py_BuildValue("(dddO)", x, y, z, pyge);
    PyObject *result = PyEval_CallObject(_callback, args);
    Py_DECREF(args);
    if(result) {
      double r = PyFloat_AsDouble(result);
      if(PyErr_Occurred()) {
        PyErr_Print();
        PyErr_Clear();
        Msg::Error("Result of python function of field %i cannot be "
                   "interpreted as a float.",
                   id);
        r = MAX_LC;
      }
      Py_DECREF(result);
      return r;
    }
    else {
      if(PyErr_Occurred()) {
        PyErr_Print();
        PyErr_Clear();
      }
      Msg::Error(
        "An error occurs while evaluating python function of field %i.", id);
      return MAX_LC;
    }
  }
};

#endif
