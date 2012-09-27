%feature("autodoc", "1");
%module gmshMesh
%include std_string.i
%include std_list.i

%{
  #include "GmshConfig.h"
#if defined(HAVE_MESH)
  #include "Generator.h"
  #include "DivideAndConquer.h"
  #include "highOrderTools.h"
#if defined(HAVE_BFGS)
  #include "meshGFaceLloyd.h"
#endif
  #include "meshGFaceOptimize.h"
  #include "meshPartitionOptions.h"
#if defined(HAVE_OPTHOM)
  #include "OptHomRun.h"
#endif
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  #include "meshPartition.h"
#endif
  #include "Field.h"
  #include "meshMetric.h"
#if defined(HAVE_ANN)
  #include "CenterlineField.h"
#endif
  #include "simple3D.h"
  #include "Voronoi3D.h"
  #include "Levy3D.h"
  #include "periodical.h"
  #include "directions3D.h"
  #include "yamakawa.h"
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
%include "DivideAndConquer.h"
%include "highOrderTools.h"
#if defined(HAVE_BFGS)
%include "meshGFaceLloyd.h"
#endif
%include "meshGFaceOptimize.h"
%include "meshPartitionOptions.h"
#if defined(HAVE_OPTHOM)
%include "OptHomRun.h"
#endif
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
%include "meshPartition.h"
#endif
%include "Field.h"
%include "meshMetric.h"
#if defined(HAVE_ANN)
%include "CenterlineField.h"
#endif
%include "simple3D.h"
%include "Voronoi3D.h"
%include "Levy3D.h"
%include "periodical.h"
%include "directions3D.h"
%include "yamakawa.h"
#endif
