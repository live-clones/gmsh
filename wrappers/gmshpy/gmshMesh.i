%feature("autodoc", "1");
%module gmshMesh
%include std_string.i

%{
  #include "GmshConfig.h"

  #include "Generator.h"
  #include "highOrderTools.h"
  #include "meshGFaceLloyd.h"
  #include "meshGFaceOptimize.h"
  #include "meshPartitionOptions.h"
  #include "Levy3D.h"
  #include "meshPartition.h"
  #include "meshMetric.h"
  #include "Field.h"
  #include "CenterlineField.h"
%}

%include std_vector.i
namespace std {
 %template(DoubleVector) vector<double, std::allocator<double> >;
}

%include "GmshConfig.h"
%include "Generator.h"
%include "highOrderTools.h"
%include "meshGFaceLloyd.h"
%include "meshGFaceOptimize.h"
%include "meshPartitionOptions.h"
%include "Levy3D.h"
%include "meshPartition.h"
%include "meshMetric.h"
%include "Field.h"
%include "CenterlineField.h"
