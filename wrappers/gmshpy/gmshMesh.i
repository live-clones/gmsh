%feature("autodoc", "1");
%module gmshMesh
%include std_string.i

%{
  #include "GmshConfig.h"
#if defined(HAVE_MESH)
  #include "Generator.h"
  #include "highOrderTools.h"
  #include "meshGFaceLloyd.h"
  #include "meshGFaceOptimize.h"
  #include "meshPartitionOptions.h"
  #include "Levy3D.h"
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
  #include "meshPartition.h"
#endif
  #include "meshMetric.h"
  #include "Field.h"
  #include "CenterlineField.h"
#endif
%}

%include std_vector.i
namespace std {
 %template(DoubleVector) vector<double, std::allocator<double> >;
}

%include "GmshConfig.h"
#if defined(HAVE_MESH)
%include "Generator.h"
%include "highOrderTools.h"
%include "meshGFaceLloyd.h"
%include "meshGFaceOptimize.h"
%include "meshPartitionOptions.h"
%include "Levy3D.h"
#if defined(HAVE_METIS) || defined(HAVE_CHACO)
%include "meshPartition.h"
#endif
%include "meshMetric.h"
%include "Field.h"
%include "CenterlineField.h"
#endif
