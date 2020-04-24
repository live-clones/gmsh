#include "hxt_point_gen_realloc.h"

HXTStatus hxtVerticesReserve(HXTMesh* mesh, uint32_t nbNewVertices){
  nbNewVertices += mesh->vertices.num;
  if(nbNewVertices > mesh->vertices.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord,   nbNewVertices*4*sizeof(double)) );
    mesh->vertices.size = nbNewVertices;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtPointsReserve(HXTMesh* mesh, uint64_t nbNewElements) {
  nbNewElements += mesh->points.num;
  if(nbNewElements > mesh->points.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->points.node,   nbNewElements*sizeof(uint32_t)) );
    mesh->points.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinesReserve(HXTMesh* mesh, uint64_t nbNewElements) {
  nbNewElements += mesh->lines.num;
  if(nbNewElements > mesh->lines.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->lines.node,   nbNewElements*2*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->lines.colors, nbNewElements*sizeof(uint16_t)) );
    mesh->lines.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtTrianglesReserve(HXTMesh* mesh, uint64_t nbNewTriangles) {
  nbNewTriangles += mesh->triangles.num;
  if(nbNewTriangles > mesh->triangles.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.node,   nbNewTriangles*3*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.colors, nbNewTriangles*sizeof(uint16_t)) );
    mesh->triangles.size = nbNewTriangles;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtQuadsReserve(HXTMesh* mesh, uint64_t nbNewElements) {
  nbNewElements += mesh->quads.num;
  if(nbNewElements > mesh->quads.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->quads.node,   nbNewElements*4*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->quads.colors, nbNewElements*sizeof(uint16_t)) );
    mesh->quads.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtTetsReserve(HXTMesh* mesh, uint64_t nbNewElements) {
  nbNewElements += mesh->tetrahedra.num;
  if(nbNewElements > mesh->tetrahedra.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.flag,   nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.colors, nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.node,   nbNewElements*4*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.neigh,  nbNewElements*4*sizeof(uint64_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->tetrahedra.neighType,  nbNewElements*4*sizeof(uint8_t)) );
    mesh->tetrahedra.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtHexahedraReserve(HXTMesh* mesh, uint64_t nbNewElements){
  nbNewElements += mesh->hexahedra.num;
  if(nbNewElements > mesh->hexahedra.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->hexahedra.flag,   nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->hexahedra.colors, nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->hexahedra.node,   nbNewElements*8*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->hexahedra.neigh,  nbNewElements*6*sizeof(uint64_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->hexahedra.neighType,  nbNewElements*6*sizeof(uint8_t)) );
    mesh->hexahedra.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtPrismsReserve(HXTMesh* mesh, uint64_t nbNewElements){
  nbNewElements += mesh->prisms.num;
  if(nbNewElements > mesh->prisms.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->prisms.flag,   nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->prisms.colors, nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->prisms.node,   nbNewElements*6*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->prisms.neigh,  nbNewElements*5*sizeof(uint64_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->prisms.neighType,  nbNewElements*5*sizeof(uint8_t)) );
    mesh->prisms.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtPyramidsReserve(HXTMesh* mesh, uint64_t nbNewElements){
  nbNewElements += mesh->pyramids.num;
  if(nbNewElements > mesh->pyramids.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->pyramids.flag,   nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->pyramids.colors, nbNewElements*sizeof(uint16_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->pyramids.node,   nbNewElements*5*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->pyramids.neigh,  nbNewElements*5*sizeof(uint64_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->pyramids.neighType,  nbNewElements*5*sizeof(uint8_t)) );

    mesh->pyramids.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}






HXTStatus hxtVerticesResize(HXTMesh* mesh, uint32_t nbNewVertices){
  if(nbNewVertices > mesh->vertices.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->vertices.coord,   nbNewVertices*4*sizeof(double)) );
    mesh->vertices.size = nbNewVertices;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtPointsResize(HXTMesh* mesh, uint64_t nbNewElements) {
  if(nbNewElements > mesh->points.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->points.node,   nbNewElements*2*sizeof(uint32_t)) );
    mesh->points.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtLinesResize(HXTMesh* mesh, uint64_t nbNewElements) {
  if(nbNewElements > mesh->lines.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->lines.node,   nbNewElements*2*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->lines.colors, nbNewElements*sizeof(uint16_t)) );
    mesh->lines.size = nbNewElements;
  }
  return HXT_STATUS_OK;
}

HXTStatus hxtTrianglesResize(HXTMesh* mesh, uint64_t nbNewTriangles) {
  if(nbNewTriangles > mesh->triangles.size){
    HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.node,   nbNewTriangles*3*sizeof(uint32_t)) );
    HXT_CHECK( hxtAlignedRealloc(&mesh->triangles.colors, nbNewTriangles*sizeof(uint16_t)) );
    mesh->triangles.size = nbNewTriangles;
  }
  return HXT_STATUS_OK;
}
