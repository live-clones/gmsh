# Gmsh - Copyright (C) 1997-2014 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@geuz.org>.

set(SRC
  Plugin.cpp PluginManager.cpp
  Levelset.cpp
    CutPlane.cpp CutSphere.cpp Isosurface.cpp
  Smooth.cpp CutParametric.cpp
  Lambda2.cpp
  Eigenvectors.cpp Eigenvalues.cpp
  StreamLines.cpp Particles.cpp CutGrid.cpp CutBox.cpp
  Transform.cpp
    LongitudeLatitude.cpp
  Triangulate.cpp Tetrahedralize.cpp
  Warp.cpp SphericalRaise.cpp
  Skin.cpp
  MathEval.cpp ModifyComponent.cpp ExtractElements.cpp
  MakeSimplex.cpp
  Integrate.cpp Gradient.cpp Curl.cpp Divergence.cpp
  Annotate.cpp Remove.cpp
  Probe.cpp MinMax.cpp
  HarmonicToTime.cpp ModulusPhase.cpp
  HomologyComputation.cpp HomologyPostProcessing.cpp
  Distance.cpp ExtractEdges.cpp NearestNeighbor.cpp
  AnalyseCurvedMesh.cpp
  CurvedBndDist.cpp
  FieldFromAmplitudePhase.cpp
  Bubbles.cpp NearToFarField.cpp
  DiscretizationError.cpp
  Scal2Vec.cpp
  CutMesh.cpp
  NewView.cpp
  SimplePartition.cpp Crack.cpp
  FaultZone.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(Plugin "${SRC};${HDR}")
