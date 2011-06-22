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
%}

%include "GmshConfig.h"
%include "Generator.h"
%include "highOrderTools.h"
%include "meshGFaceLloyd.h"
%include "meshGFaceOptimize.h"
%include "meshPartitionOptions.h"
