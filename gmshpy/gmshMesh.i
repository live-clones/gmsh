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
  #include "simple3D.h"
  #include "Voronoi3D.h"
  #include "Levy3D.h"
  #include "periodical.h"
%}

%include "GmshConfig.h"
%include "Generator.h"
%include "highOrderTools.h"
%include "meshGFaceLloyd.h"
%include "meshGFaceOptimize.h"
%include "meshPartitionOptions.h"
%include "simple3D.h"
%include "Voronoi3D.h"
%include "Levy3D.h"
%include "periodical.h"

