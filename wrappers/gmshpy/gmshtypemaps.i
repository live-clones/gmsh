%fragment("fullMatrixConversionInit", "init") {
  %#ifdef HAVE_NUMPY
  import_array();
  %#endif
}

%fragment("fullMatrixConversion", "header", fragment="fullMatrixConversionInit") {
  %#include "fullMatrix.h"
  %#include "GmshConfig.h"
  %#ifdef HAVE_NUMPY
  %#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
  %#include <numpy/arrayobject.h>
  %#if NPY_API_VERSION < 0x00000007
  %#define NPY_ARRAY_FARRAY NPY_FARRAY
  %#endif
  %#endif
  fullMatrix<double> *pySequenceToFullMatrixDouble(PyObject *o) {
    fullMatrix<double> *fm;
    if (!PySequence_Check(o))
      return NULL;
    long int nRow = PySequence_Length(o);
    for (int i = 0; i < PySequence_Length(o); ++i) {
      PyObject *l = PySequence_GetItem(o, i);
      long int nCol = PySequence_Length(l);
      if (i == 0)
        fm = new fullMatrix<double>(nRow, nCol);
      else if (nCol != fm->size2()) {
        delete fm;
        return NULL;
      }
      for (int j = 0; j < nCol; ++j) {
        PyObject *v = PySequence_GetItem(l, j);
        if (PyNumber_Check(v)) {
          (*fm)(i, j) = (float) PyFloat_AsDouble(v);
        }
        else {
          delete fm;
          return NULL;
        }
      }
    }
    return fm;
  }

  fullMatrix<double> *objToFullMatrixRO(PyObject *obj, bool &newMatrix, PyObject *&tmpObject)
  {
    fullMatrix<double> *fm = NULL;
    SWIG_ConvertPtr(obj,(void **) &fm, SWIGTYPE_p_fullMatrixT_double_t, 1);
    if (fm)
      return fm;
    %#ifdef HAVE_NUMPY
    PyArrayObject *array = (PyArrayObject*)obj;
    if (PyArray_Check(array) && PyArray_ISFARRAY_RO(array) && PyArray_NDIM(array) == 2) {
      newMatrix = true;
      return new fullMatrix<double>((double*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    if ((tmpObject = PyArray_FROMANY(obj, NPY_DOUBLE, 2, 2, NPY_ARRAY_FARRAY))) {
      array = (PyArrayObject*)tmpObject;
      newMatrix = true;
      return new fullMatrix<double>((double*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    %#endif
    if ((fm = pySequenceToFullMatrixDouble(obj)))
      newMatrix = true;
    return fm;
  }

  fullMatrix<double> *objToFullMatrixRW(PyObject *obj, bool &newMatrix)
  {
    fullMatrix<double> *fm = NULL;
    SWIG_ConvertPtr(obj,(void **) &fm, SWIGTYPE_p_fullMatrixT_double_t, 1);
    if (fm)
      return fm;
    %#ifdef HAVE_NUMPY
    PyArrayObject *array = (PyArrayObject*)obj;
    if (PyArray_Check(array) && PyArray_ISFARRAY(array) && PyArray_NDIM(array) == 2) {
      newMatrix = true;
      return new fullMatrix<double>((double*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    %#endif
    return NULL;
  }
}

%typemap(in, fragment="fullMatrixConversion") const fullMatrix<double> &(PyObject *tmpObject = NULL, bool newMatrix = false){
  $1 = objToFullMatrixRO($input, newMatrix, tmpObject);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a fullMatrix<double>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) const fullMatrix<double> &{
  if (tmpObject$argnum) Py_DECREF(tmpObject$argnum);
  if (newMatrix$argnum && $1) delete $1;
}

%typemap(in, fragment="fullMatrixConversion") fullMatrix<double> &(bool newMatrix = false){
  $1 = objToFullMatrixRW($input, newMatrix);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a writable fullMatrix<double>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) fullMatrix<double> &{
  if (newMatrix$argnum && $1) delete $1;
}

%typemap(in, fragment="fullMatrixConversion") const fullMatrix<double> *(PyObject *tmpObject = NULL, bool newMatrix = false){
  $1 = objToFullMatrixRO($input, newMatrix, tmpObject);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a fullMatrix<double>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) const fullMatrix<double> *{
  if (tmpObject$argnum) Py_DECREF(tmpObject$argnum);
  if (newMatrix$argnum && $1) delete $1;
}

%typemap(in, fragment="fullMatrixConversion") fullMatrix<double> *(bool newMatrix = false){
  $1 = objToFullMatrixRW($input, newMatrix);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a writable fullMatrix<double>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) fullMatrix<double> *{
  if (newMatrix$argnum && $1) delete $1;
}
