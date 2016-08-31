%include "GmshConfig.h"
%fragment("fullMatrixConversionInit", "init") {
  %#ifdef HAVE_NUMPY
  import_array();
  %#endif
}

%fragment("fullMatrixConversion", "header", fragment="fullMatrixConversionInit") {
  %#undef HAVE_DLOPEN
  %#include "fullMatrix.h"
  %#include "GmshConfig.h"
  %#ifdef HAVE_NUMPY
  %#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
  %#include <numpy/arrayobject.h>
  %#if NPY_API_VERSION < 0x00000007
  %#define NPY_ARRAY_FARRAY NPY_FARRAY
  %#define NPY_ARRAY_ALIGNED NPY_ALIGNED
  %#define NPY_ARRAY_F_CONTIGUOUS NPY_F_CONTIGUOUS
  %#define NPY_ARRAY_WRITEABLE NPY_WRITEABLE
  %#define PyArray_SetBaseObject(a, b) PyArray_BASE(a) = b
  %#endif
  %#endif
  fullMatrix<double> *pySequenceToFullMatrixDouble(PyObject *o) {
    fullMatrix<double> *fm = NULL;
    if (!PySequence_Check(o))
      return NULL;
    long int nRow = PySequence_Length(o);
    for (int i = 0; i < PySequence_Length(o); ++i) {
      PyObject *l = PySequence_GetItem(o, i);
      if (!PySequence_Check(l)){
        if (fm != NULL)
          delete fm;
        return NULL;
      }
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
    if (PyArray_Check(array) && PyArray_ISFARRAY_RO(array) && PyArray_NDIM(array) == 2 && PyArray_DESCR(array)->kind == 'f') {
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
    if (PyArray_Check(array) && PyArray_ISFARRAY(array) && PyArray_NDIM(array) == 2 && PyArray_DESCR(array)->kind == 'f') {
      newMatrix = true;
      return new fullMatrix<double>((double*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    %#endif
    return NULL;
  }

  %#ifdef HAVE_NUMPY
  %#if PY_MAJOR_VERSION==2 && PY_MINOR_VERSION==6
  static void deleteCapsuleArray(void *capsule)
  {
    delete [](double*)(capsule);
  }
  %#else
  static void deleteCapsuleArray(PyObject *capsule)
  {
    delete [](double*)PyCapsule_GetPointer(capsule, NULL);
  }
  %#endif
  PyObject *fullMatrix2PyArray(fullMatrix<double> &fm)
  {
    npy_intp dims[2] = {fm.size1(), fm.size2()};
    double *data = &fm.operator()(0, 0);
    /*PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_DOUBLE, NULL, NULL, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    // copy data
    memcpy((void*)PyArray_DATA(array), data, dims[0] * dims[1] * sizeof(double));*/
    // do not copy data
    PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_DOUBLE, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED);
    if (fm.getOwnData()) {
      fm.setOwnData(false);
      %#if PY_MAJOR_VERSION==2 && PY_MINOR_VERSION==6
      PyObject *capsule = PyCObject_FromVoidPtr((void*)data, deleteCapsuleArray);
      %#else
      PyObject *capsule = PyCapsule_New((void*) data, NULL, deleteCapsuleArray);
      %#endif
      PyArray_SetBaseObject((PyArrayObject*)array, capsule);
    }
    return array;
  }
  PyObject *fullMatrix2PyArrayConst(const fullMatrix<double> &fm)
  {
    npy_intp dims[2] = {fm.size1(), fm.size2()};
    double *data = (double*)fm.getDataPtr();
    // do not copy data
    PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_DOUBLE, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED);
    return array;
  }
  PyObject *fullMatrix2PyArrayProxy(const fullMatrix<double> &fm)
  {
    npy_intp dims[2] = {fm.size1(), fm.size2()};
    double *data = (double*)fm.getDataPtr();
    PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_DOUBLE, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED |NPY_ARRAY_WRITEABLE);
    return array;
  }
  PyObject *fullVector2PyArrayProxy(fullVector<double> &fv)
  {
    npy_intp dims[1] = {fv.size()};
    double *data = &fv.operator()(0);
    PyObject *array = PyArray_New(&PyArray_Type, 1, dims, NPY_DOUBLE, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED | NPY_ARRAY_WRITEABLE);
    return array;
  }
  %#endif
}
%fragment("fullMatrixConversionInt", "header", fragment="fullMatrixConversionInit") {
  %#undef HAVE_DLOPEN
  %#include "fullMatrix.h"
  %#include "GmshConfig.h"
  %#ifdef HAVE_NUMPY
  %#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
  %#include <numpy/arrayobject.h>
  %#if NPY_API_VERSION < 0x00000007
  %#define NPY_ARRAY_FARRAY NPY_FARRAY
  %#define NPY_ARRAY_ALIGNED NPY_ALIGNED
  %#define NPY_ARRAY_F_CONTIGUOUS NPY_F_CONTIGUOUS
  %#define NPY_ARRAY_WRITEABLE NPY_WRITEABLE
  %#define PyArray_SetBaseObject(a, b) PyArray_BASE(a) = b
  %#endif
  %#endif
  fullMatrix<int> *pySequenceToFullMatrixInt(PyObject *o) {
    fullMatrix<int> *fm = NULL;
    if (!PySequence_Check(o))
      return NULL;
    long int nRow = PySequence_Length(o);
    for (int i = 0; i < PySequence_Length(o); ++i) {
      PyObject *l = PySequence_GetItem(o, i);
      if (!PySequence_Check(l)){
        if (fm != NULL)
          delete fm;
        return NULL;
      }
      long int nCol = PySequence_Length(l);
      if (i == 0)
        fm = new fullMatrix<int>(nRow, nCol);
      else if (nCol != fm->size2()) {
        delete fm;
        return NULL;
      }
      for (int j = 0; j < nCol; ++j) {
        PyObject *v = PySequence_GetItem(l, j);
        if (PyLong_Check(v)) {
          (*fm)(i, j) = (int) PyLong_AsLong(v);
        }
        else {
          delete fm;
          return NULL;
        }
      }
    }
    return fm;
  }

  fullMatrix<int> *objToFullMatrixIntRO(PyObject *obj, bool &newMatrix, PyObject *&tmpObject)
  {
    fullMatrix<int> *fm = NULL;
    SWIG_ConvertPtr(obj,(void **) &fm, SWIGTYPE_p_fullMatrixT_int_t, 1);
    if (fm)
      return fm;
    %#ifdef HAVE_NUMPY
    PyArrayObject *array = (PyArrayObject*)obj;
    if (PyArray_Check(array) && PyArray_ISFARRAY_RO(array) && PyArray_NDIM(array) == 2 && PyArray_DESCR(array)->kind == 'i') {
      newMatrix = true;
      return new fullMatrix<int>((int*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    if ((tmpObject = PyArray_FROMANY(obj, NPY_INT, 2, 2, NPY_ARRAY_FARRAY))) {
      array = (PyArrayObject*)tmpObject;
      newMatrix = true;
      return new fullMatrix<int>((int*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    %#endif
    if ((fm = pySequenceToFullMatrixInt(obj)))
      newMatrix = true;
    return fm;
  }

  fullMatrix<int> *objToFullMatrixIntRW(PyObject *obj, bool &newMatrix)
  {
    fullMatrix<int> *fm = NULL;
    SWIG_ConvertPtr(obj,(void **) &fm, SWIGTYPE_p_fullMatrixT_int_t, 1);
    if (fm)
      return fm;
    %#ifdef HAVE_NUMPY
    PyArrayObject *array = (PyArrayObject*)obj;
    if (PyArray_Check(array) && PyArray_ISFARRAY(array) && PyArray_NDIM(array) == 2 && PyArray_DESCR(array)->kind == 'i') {
      newMatrix = true;
      return new fullMatrix<int>((int*)PyArray_DATA(array), PyArray_DIM(array, 0), PyArray_DIM(array, 1));
    }
    %#endif
    return NULL;
  }

  %#ifdef HAVE_NUMPY
  %#if PY_MAJOR_VERSION==2 && PY_MINOR_VERSION==6
  static void deleteCapsuleArrayInt(void *capsule)
  {
    delete [](double*)(capsule);
  }
  %#else
  static void deleteCapsuleArrayInt(PyObject *capsule)
  {
    delete [](double*)PyCapsule_GetPointer(capsule, NULL);
  }
  %#endif

  PyObject *fullMatrix2PyArray(fullMatrix<int> &fm)
  {
    npy_intp dims[2] = {fm.size1(), fm.size2()};
    int *data = &fm.operator()(0, 0);
    /*PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_DOUBLE, NULL, NULL, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    // copy data
    memcpy((void*)PyArray_DATA(array), data, dims[0] * dims[1] * sizeof(int));*/
    // do not copy data
    PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_INT, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED);
    if (fm.getOwnData()) {
      fm.setOwnData(false);
      %#if PY_MAJOR_VERSION==2 && PY_MINOR_VERSION==6
      PyObject *capsule = PyCObject_FromVoidPtr((void*)data, deleteCapsuleArrayInt);
      %#else
      PyObject *capsule = PyCapsule_New((void*) data, NULL, deleteCapsuleArrayInt);
      %#endif
      PyArray_SetBaseObject((PyArrayObject*)array, capsule);
    }
    return array;
  }
  PyObject *fullMatrix2PyArrayConst(const fullMatrix<int> &fm)
  {
    npy_intp dims[2] = {fm.size1(), fm.size2()};
    int *data = (int*)fm.getDataPtr();
    // do not copy data
    PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_INT, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED);
    return array;
  }
  PyObject *fullMatrix2PyArrayProxy(const fullMatrix<int> &fm)
  {
    npy_intp dims[2] = {fm.size1(), fm.size2()};
    int *data = (int*)fm.getDataPtr();
    PyObject *array = PyArray_New(&PyArray_Type, 2, dims, NPY_INT, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED |NPY_ARRAY_WRITEABLE);
    return array;
  }
  PyObject *fullVector2PyArrayProxy(fullVector<int> &fv)
  {
    npy_intp dims[1] = {fv.size()};
    int *data = &fv.operator()(0);
    PyObject *array = PyArray_New(&PyArray_Type, 1, dims, NPY_INT, NULL, (void*)data, 0, NPY_ARRAY_F_CONTIGUOUS, NULL);
    PyArray_UpdateFlags((PyArrayObject*)array, NPY_ARRAY_ALIGNED | NPY_ARRAY_WRITEABLE);
    return array;
  }
  %#endif
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

%typemap(in, fragment="fullMatrixConversionInt") const fullMatrix<int> &(PyObject *tmpObject = NULL, bool newMatrix = false){
  $1 = objToFullMatrixIntRO($input, newMatrix, tmpObject);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a fullMatrix<int>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) const fullMatrix<int> &{
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

%typemap(in, fragment="fullMatrixConversionInt") fullMatrix<int> &(bool newMatrix = false){
  $1 = objToFullMatrixIntRW($input, newMatrix);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a writable fullMatrix<int>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) fullMatrix<int> &{
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

%typemap(in, fragment="fullMatrixConversionInt") const fullMatrix<int> *(PyObject *tmpObject = NULL, bool newMatrix = false){
  $1 = objToFullMatrixIntRO($input, newMatrix, tmpObject);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a fullMatrix<int>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) const fullMatrix<int> *{
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

%typemap(in, fragment="fullMatrixConversionInt") fullMatrix<int> *(bool newMatrix = false){
  $1 = objToFullMatrixIntRW($input, newMatrix);
  if (!$1) {
    PyErr_Format(PyExc_TypeError, "cannot convert argument %i to a writable fullMatrix<int>", $argnum);
    SWIG_fail;
  }
}
%typemap(freearg) fullMatrix<int> *{
  if (newMatrix$argnum && $1) delete $1;
}

#ifdef HAVE_NUMPY
%typemap(out, fragment="fullMatrixConversion") fullMatrix<double> {
  $result = fullMatrix2PyArray($1);
}

%typemap(out, fragment="fullMatrixConversion") const fullMatrix<double>& {
  $result = fullMatrix2PyArrayConst(*$1);
}

%typemap(out, fragment="fullMatrixConversion") fullMatrix<double>& {
  $result = fullMatrix2PyArrayProxy(*$1);
}

%typemap(out, fragment="fullMatrixConversion") fullVector<double>& {
  $result = fullVector2PyArrayProxy(*$1);
}

%typemap(out, fragment="fullMatrixConversionInt") fullMatrix<int> {
  $result = fullMatrix2PyArray($1);
}

%typemap(out, fragment="fullMatrixConversionInt") const fullMatrix<int>& {
  $result = fullMatrix2PyArrayConst(*$1);
}

%typemap(out, fragment="fullMatrixConversionInt") fullMatrix<int>& {
  $result = fullMatrix2PyArrayProxy(*$1);
}

#endif


