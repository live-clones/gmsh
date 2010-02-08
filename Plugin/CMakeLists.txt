# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  Plugin.cpp PluginManager.cpp
  Levelset.cpp
    CutPlane.cpp CutSphere.cpp Isosurface.cpp 
  Smooth.cpp CutParametric.cpp
  Lambda2.cpp
  Eigenvectors.cpp Eigenvalues.cpp
  StreamLines.cpp Particles.cpp CutGrid.cpp
  Transform.cpp
    LongitudeLatitude.cpp
  Triangulate.cpp Tetrahedralize.cpp
  Warp.cpp SphericalRaise.cpp
  Skin.cpp GSHHS.cpp 
  MathEval.cpp ModifyComponent.cpp ExtractElements.cpp
  MakeSimplex.cpp
  FieldView.cpp 
  Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp
  Annotate.cpp Remove.cpp
  Probe.cpp
  HarmonicToTime.cpp ModulusPhase.cpp
  HomologyComputation.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_SOURCE_DIR}/Plugin *.h) 
append_gmsh_src(Plugin "${SRC};${HDR}")
