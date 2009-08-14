# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Plugin.cpp PluginManager.cpp
  Levelset.cpp
    CutPlane.cpp CutSphere.cpp CutMap.cpp 
  Smooth.cpp CutParametric.cpp
  Lambda2.cpp
  Eigenvectors.cpp Eigenvalues.cpp
  StreamLines.cpp CutGrid.cpp
  Transform.cpp
    LongitudeLatitude.cpp
  Triangulate.cpp
  Warp.cpp SphericalRaise.cpp
  Skin.cpp GSHHS.cpp 
  Extract.cpp ExtractElements.cpp ExtractEdges.cpp
  MakeSimplex.cpp
  Evaluate.cpp FieldView.cpp 
  Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp
  Annotate.cpp Remove.cpp
  Probe.cpp
  HarmonicToTime.cpp ModulusPhase.cpp
  FiniteElement.cpp
  HomologyComputation.cpp
)

append_gmsh_src(Plugin "${SRC}")
