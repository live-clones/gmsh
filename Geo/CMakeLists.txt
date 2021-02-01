# Gmsh - Copyright (C) 1997-2021 C. Geuzaine, J.-F. Remacle
#
# See the LICENSE.txt file for license information. Please report all
# issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

set(SRC
  boundaryLayersData.cpp
    affineTransformation.cpp
  closestPoint.cpp
    closestVertex.cpp
  intersectCurveSurface.cpp
  GEntity.cpp STensor3.cpp
    GVertex.cpp GEdge.cpp GFace.cpp GRegion.cpp
    GEdgeLoop.cpp
    gmshVertex.cpp gmshEdge.cpp gmshFace.cpp gmshRegion.cpp
    gmshSurface.cpp
    OCCVertex.cpp OCCEdge.cpp OCCFace.cpp OCCRegion.cpp
    discreteVertex.cpp discreteEdge.cpp discreteFace.cpp discreteRegion.cpp
  GModel.cpp
    GModelCreateTopologyFromMesh.cpp
    GModelVertexArrays.cpp
    GModelParametrize.cpp
    GModelIO_GEO.cpp GModelIO_OCC.cpp
    GModelIO_MSH.cpp GModelIO_MSH2.cpp GModelIO_MSH3.cpp GModelIO_MSH4.cpp
    GModelIO_VTK.cpp GModelIO_CGNS.cpp GModelIO_MED.cpp GModelIO_MESH.cpp
    GModelIO_STL.cpp  GModelIO_TOCHNOG.cpp GModelIO_PLY.cpp GModelIO_VRML.cpp
    GModelIO_UNV.cpp GModelIO_BDF.cpp GModelIO_IR3.cpp GModelIO_DIFF.cpp
    GModelIO_GEOM.cpp GModelIO_INP.cpp GModelIO_KEY.cpp GModelIO_MAIL.cpp GModelIO_P3D.cpp
    GModelIO_CELUM.cpp GModelIO_NEU.cpp GModelIO_ACTRAN.cpp GModelIO_SU2.cpp
    GModelIO_SAMCEF.cpp GModelIO_MATLAB.cpp GModelIO_POS.cpp GModelIO_X3D.cpp
  ExtrudeParams.cpp
  Geo.cpp GeoInterpolation.cpp
  scriptStringInterface.cpp
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
  Cell.cpp CellComplex.cpp ChainComplex.cpp Homology.cpp Chain.cpp
  MVertexBoundaryLayerData.cpp
  CGNSCommon.cpp
  CGNSConventions.cpp
  CGNSZone.cpp
    CGNSZoneStruct.cpp CGNSZoneUnstruct.cpp
  CGNSRead.cpp CGNSWrite.cpp CGNSWriteStruct.cpp
)

file(GLOB HDR RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.h)
append_gmsh_src(Geo "${SRC};${HDR}")
