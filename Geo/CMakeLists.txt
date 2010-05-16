# Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
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
  ACISVertex.cpp
  ACISEdge.cpp
  ACISFace.cpp
  GModel.cpp
  GModelFactory.cpp
    GModelIO_Geo.cpp
    GModelIO_Mesh.cpp
    GModelIO_OCC.cpp
    GModelIO_ACIS.cpp
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
  MElementOctree.cpp
    MLine.cpp MTriangle.cpp MQuadrangle.cpp MTetrahedron.cpp
    MHexahedron.cpp MPrism.cpp MPyramid.cpp MElementCut.cpp
  MZone.cpp MZoneBoundary.cpp
  Cell.cpp CellComplex.cpp ChainComplex.cpp Homology.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Geo "${SRC};${HDR}")
