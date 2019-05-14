%feature("autodoc", "1");
%module gmshMesh
%include std_string.i
%include std_list.i
%import "gmshtypemaps.i"

%{
  #undef HAVE_DLOPEN
  #include "GmshConfig.h"
#if defined(HAVE_MESH)
  #include "Generator.h"
  #include "DivideAndConquer.h"
  #include "meshGFaceOptimize.h"
#if defined(HAVE_OPTHOM)
  #include "HighOrderMeshOptimizer.h"
  #include "HighOrderMeshElasticAnalogy.h"
  #include "HighOrderMeshFastCurving.h"
  #include "MeshQualityOptimizer.h"
  #include "CADDistances.h"
#endif
#if defined(HAVE_METIS)
  #include "meshPartition.h"
#endif
  #include "Field.h"
  #include "FieldPython.h"
  #include "meshMetric.h"
#if defined(HAVE_DOMHEX)
  #include "simple3D.h"
  #include "directions3D.h"
  #include "yamakawa.h"
#endif
#endif
%}

%include std_vector.i
%include std_map.i
namespace std {
 %template(DoubleVector) vector<double, std::allocator<double> >;
 %template(IntList) list<int>;
}

%include "GmshConfig.h"
#if defined(HAVE_MESH)
%include "Generator.h"
#pragma SWIG nowarn=314
%include "DivideAndConquer.h"
%include "meshGFaceOptimize.h"
#if defined(HAVE_OPTHOM)
%include "HighOrderMeshOptimizer.h"
%include "HighOrderMeshElasticAnalogy.h"
%include "HighOrderMeshFastCurving.h"
%include "MeshQualityOptimizer.h"
%include "CADDistances.h"
#endif
#if defined(HAVE_METIS)
%include "meshPartition.h"
#endif
%warnfilter(401) FieldManager;
%include "Field.h"
%extend FieldManager {
  int addPythonField(PyObject *callback, int id = -1) {
    if (id == -1) {
      id = $self->newId();
    }
    if($self->find(id) != $self->end()) {
      Msg::Error("Field id %i is already defined", id);
      return -1;
    }
    Field *f = new FieldPython(callback);
    f->id = id;
    $self->operator[](id) = f;
    return id;
  }
}
%include "meshMetric.h"
#if defined(HAVE_DOMHEX)
%include "simple3D.h"
%include "directions3D.h"
%include "yamakawa.h"
#endif
#endif
