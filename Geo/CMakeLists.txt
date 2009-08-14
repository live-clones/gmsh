# Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to <gmsh@geuz.org>.

set(SRC
  GEntity.cpp STensor3.cpp
    GVertex.cpp GEdge.cpp GFace.cpp GRegion.cpp
    GEdgeLoop.cpp GEdgeCompound.cpp GFaceCompound.cpp GRegionCompound.cpp
    gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp gmshSurface.cpp
    OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp
    discreteEdge.cpp discreteFace.cpp discreteRegion.cpp
    fourierEdge.cpp fourierFace.cpp fourierProjectionFace.cpp
  GModel.cpp
    GModelIO_Geo.cpp
    GModelIO_Mesh.cpp
    GModelIO_OCC.cpp
      OCC_Connect.cpp
    GModelIO_Fourier.cpp
    GModelIO_CGNS.cpp
    GModelIO_MED.cpp
  ExtrudeParams.cpp
  Geo.cpp
  GeoStringInterface.cpp GeoInterpolation.cpp
  findLinks.cpp
  SOrientedBoundingBox.cpp
  GeomMeshMatcher.cpp
  MVertex.cpp
  MFace.cpp
  MElement.cpp
    MLine.cpp MTriangle.cpp MQuadrangle.cpp MTetrahedron.cpp
    MHexahedron.cpp MPrism.cpp MPyramid.cpp MElementCut.cpp
  MZone.cpp MZoneBoundary.cpp
  CellComplex.cpp ChainComplex.cpp Homology.cpp
)

append_gmsh_src(Geo "${SRC}")
