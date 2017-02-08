# Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# bugs and problems to the public mailing list <gmsh@onelab.info>.

set(SRC
  boundaryLayersData.cpp
  closestPoint.cpp
  intersectCurveSurface.cpp
  GEntity.cpp STensor3.cpp
    GVertex.cpp GEdge.cpp GFace.cpp GRegion.cpp
    GEdgeLoop.cpp GEdgeCompound.cpp GFaceCompound.cpp
  GRegionCompound.cpp GRbf.cpp
    gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp
   gmshSurface.cpp
   OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp
   GenericVertex.cpp GenericEdge.cpp GenericFace.cpp GenericRegion.cpp
    discreteEdge.cpp discreteFace.cpp discreteDiskFace.cpp discreteRegion.cpp 
    fourierEdge.cpp fourierFace.cpp fourierProjectionFace.cpp
  ACISVertex.cpp
  ACISEdge.cpp
  ACISFace.cpp
  GModel.cpp
  GModelCreateTopologyFromMesh.cpp
    GModelVertexArrays.cpp
    GModelFactory.cpp
    GModelIO_GEO.cpp GModelIO_ACIS.cpp GModelIO_OCC.cpp GModelIO_TOCHNOG.cpp
      GModelIO_Fourier.cpp 
    GModelIO_MSH.cpp GModelIO_MSH2.cpp GModelIO_VTK.cpp GModelIO_POS.cpp 
      GModelIO_CGNS.cpp GModelIO_MED.cpp GModelIO_MESH.cpp GModelIO_STL.cpp 
      GModelIO_PLY.cpp GModelIO_VRML.cpp GModelIO_UNV.cpp GModelIO_BDF.cpp 
      GModelIO_IR3.cpp GModelIO_DIFF.cpp GModelIO_GEOM.cpp GModelIO_INP.cpp
      GModelIO_MAIL.cpp GModelIO_P3D.cpp GModelIO_CELUM.cpp
      GModelIO_ACTRAN.cpp GModelIO_SU2.cpp
  ExtrudeParams.cpp
  Geo.cpp
  GeoStringInterface.cpp GeoInterpolation.cpp
  gmshLevelset.cpp
  findLinks.cpp
  SOrientedBoundingBox.cpp
  GeomMeshMatcher.cpp
  MVertex.cpp
  MEdge.cpp
  MFace.cpp
  MElement.cpp MElementOctree.cpp
    MLine.cpp MTriangle.cpp MQuadrangle.cpp MTetrahedron.cpp
    MHexahedron.cpp MPrism.cpp MPyramid.cpp MTrihedron.cpp MElementCut.cpp MSubElement.cpp
  MZone.cpp MZoneBoundary.cpp
  Cell.cpp CellComplex.cpp ChainComplex.cpp Homology.cpp Chain.cpp
  Curvature.cpp
  MVertexBoundaryLayerData.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h) 
append_gmsh_src(Geo "${SRC};${HDR}")
