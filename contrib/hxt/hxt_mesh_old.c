#include "hxt_mesh.h"
#include <float.h>

/* Compatible with HXT_ELT_TYPE enum exposed in header */
#define POINTID 15
#define LINEID 1
#define TRIID 2
#define QUADID 3
#define TETID 4
#define HEXID 5
#define PRIID 6
#define PYRID 7

HXTStatus  hxtMeshCreate ( HXTContext* ctx, HXTMesh** mesh) {
  HXT_CHECK( hxtMalloc (mesh, sizeof(HXTMesh)) );
  if (*mesh == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  (*mesh)->ctx = ctx;

  // vertices
  (*mesh)->vertices.coord = NULL;
  (*mesh)->vertices.num = 0;
  (*mesh)->vertices.size = 0;

  // tetrahedra
  (*mesh)->tetrahedra.node = NULL;
  (*mesh)->tetrahedra.colors = NULL;
  (*mesh)->tetrahedra.flag = NULL;
  (*mesh)->tetrahedra.neigh = NULL;
  (*mesh)->tetrahedra.neighType = NULL;
  // (*mesh)->tetrahedra.subdet = NULL;
  (*mesh)->tetrahedra.num = 0;
  (*mesh)->tetrahedra.size = 0;

  // hexahedra
  (*mesh)->hexahedra.node = NULL;
  (*mesh)->hexahedra.colors = NULL;
  (*mesh)->hexahedra.flag = NULL;
  (*mesh)->hexahedra.neigh = NULL;
  (*mesh)->hexahedra.neighType = NULL;
  (*mesh)->hexahedra.num = 0;
  (*mesh)->hexahedra.size = 0;

  // prisms
  (*mesh)->prisms.node = NULL;
  (*mesh)->prisms.colors = NULL;
  (*mesh)->prisms.flag = NULL;
  (*mesh)->prisms.neigh = NULL;
  (*mesh)->prisms.neighType = NULL;
  (*mesh)->prisms.num = 0;
  (*mesh)->prisms.size = 0;

  // pyramids
  (*mesh)->pyramids.node = NULL;
  (*mesh)->pyramids.colors = NULL;
  (*mesh)->pyramids.flag = NULL;
  (*mesh)->pyramids.neigh = NULL;
  (*mesh)->pyramids.neighType = NULL;
  (*mesh)->pyramids.num = 0;
  (*mesh)->pyramids.size = 0;

  // triangles
  (*mesh)->triangles.node = NULL;
  (*mesh)->triangles.neigh = NULL;
  (*mesh)->triangles.colors = NULL;
  (*mesh)->triangles.num = 0;
  (*mesh)->triangles.size = 0;

  // quads
  (*mesh)->quads.node = NULL;
  (*mesh)->quads.colors = NULL;
  (*mesh)->quads.num = 0;
  (*mesh)->quads.size = 0;

  // lines
  (*mesh)->lines.node = NULL;
  (*mesh)->lines.colors = NULL;
  (*mesh)->lines.num = 0;
  (*mesh)->lines.size = 0;

  // boundary representation
  (*mesh)->brep.numVolumes = 0;
  (*mesh)->brep.numSurfacesPerVolume = NULL;
  (*mesh)->brep.surfacesPerVolume = NULL;
  (*mesh)->brep.numSurfaces = 0;
  (*mesh)->brep.numCurvesPerSurface = NULL;
  (*mesh)->brep.curvesPerSurface = NULL;
  (*mesh)->brep.numCurves = 0;
  (*mesh)->brep.endPointsOfCurves = NULL;
  (*mesh)->brep.numPoints = 0;
  (*mesh)->brep.points = NULL;

  return HXT_STATUS_OK;
}

HXTStatus hxtMeshDelete ( HXTMesh** mesh) {
  // free on NULL pointer is well defined (it does nothing)

  // vertices
  HXT_CHECK( hxtAlignedFree(&(*mesh)->vertices.coord) );

  // tetrahedra
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.colors) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.neigh) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.neighType) );
  // HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.subdet) );
  
  // hexahedra
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.colors) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.neigh) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.neighType) );

  // prisms
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.colors) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.neigh) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.neighType) );

  // pyramids
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.colors) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.neigh) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.neighType) );

  // triangles
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.colors) );

  // quads
  HXT_CHECK( hxtAlignedFree(&(*mesh)->quads.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->quads.colors) );

  // lines
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.colors) );

  // boundary representation
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.numSurfacesPerVolume) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.surfacesPerVolume) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.numCurvesPerSurface) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.curvesPerSurface) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.endPointsOfCurves) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.points) );


  HXT_CHECK( hxtFree(mesh) );
  return HXT_STATUS_OK;
}

// TODO: more checking of fgets
HXTStatus ReadNodesFromGmsh(FILE *fp,  HXTMesh* m){
  rewind (fp);
  size_t n;
  char buf[BUFSIZ]={""};
  // scan for Nodes
  m->vertices.num = 0;
  while( fgets(buf, BUFSIZ, fp )!=NULL){
    
    if(strstr(buf, "$Nodes")){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");

      m->vertices.num = atoi(buf);
      HXT_CHECK( hxtAlignedMalloc(&m->vertices.coord, sizeof( double )*4*m->vertices.num) );
      if (m->vertices.coord == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
      m->vertices.size = m->vertices.num;
      for(n=0;n<m->vertices.num;++n){
        if(fgets(buf, BUFSIZ, fp )==NULL)
          return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
        sscanf(buf, "%*d %lf %lf %lf", &m->vertices.coord[(size_t) 4*n+0], &m->vertices.coord[(size_t) 4*n+1], &m->vertices.coord[(size_t) 4*n+2]);
      }
      break;
    }
  }  
  return HXT_STATUS_OK;
}
  

// TODO: add possibility to read the elements from an array

// TODO: more checking of fgets
// TODO: compute other stuffs, like the subdets...
HXTStatus ReadElementsFromGmsh(FILE *fp, HXTMesh* m){
  int k;
  char buf[BUFSIZ]={""};
  
  rewind (fp);

  m->lines.num = 0;
  m->triangles.num = 0;
  m->quads.num = 0;
  m->tetrahedra.num = 0;
  m->hexahedra.num = 0;
  m->prisms.num = 0;
  m->pyramids.num = 0;

  while(fgets(buf, BUFSIZ, fp )){    
    if(strstr(buf, "$Elements")){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");    
      int tmpK = atoi(buf);      
      for(k=0;k<tmpK;++k){
        int etype = 0;
        if(fgets(buf, BUFSIZ, fp )==NULL)
          return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
        sscanf(buf, "%*d %d", &etype);
        if(etype==TETID){ // tets
          ++(m->tetrahedra.num);
        }
        else if(etype==HEXID){ // hexahedra
          ++(m->hexahedra.num);
        }
        else if(etype==PRIID){ // prisms
          ++(m->prisms.num);
        }
        else if(etype==PYRID){ // pyramids
          ++(m->pyramids.num);
        }
        else if(etype==TRIID){ // triangles
          ++(m->triangles.num);
        }
        else if(etype==QUADID){ // quads
          ++(m->quads.num);
        }
        else if(etype==LINEID){ // lines
          ++(m->lines.num);
        }
        else if(etype==POINTID){ // points
          //          ++(m->lines.num);
        }
      }      
      break;
    }
  }
  
  rewind (fp);

  
  // prescan for elements
  if (m->tetrahedra.num){
    HXT_CHECK( hxtAlignedMalloc(&m->tetrahedra.node, (m->tetrahedra.num)*4*sizeof(uint32_t)) );
    if (m->tetrahedra.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->tetrahedra.colors, (m->tetrahedra.num)*sizeof(uint16_t)) );
    if (m->tetrahedra.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->tetrahedra.size = m->tetrahedra.num;
  }
  if (m->hexahedra.num){
    HXT_CHECK( hxtAlignedMalloc(&m->hexahedra.node, (m->hexahedra.num)*8*sizeof(uint32_t)) );
    if (m->hexahedra.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->hexahedra.colors, (m->hexahedra.num)*sizeof(uint16_t)) );
    if (m->hexahedra.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->hexahedra.size = m->hexahedra.num;
  }
  if (m->prisms.num){
    HXT_CHECK( hxtAlignedMalloc(&m->prisms.node, (m->prisms.num)*6*sizeof(uint32_t)) );
    if (m->prisms.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->prisms.colors, (m->prisms.num)*sizeof(uint16_t)) );
    if (m->prisms.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->prisms.size = m->prisms.num;
  }
  if (m->pyramids.num){
    HXT_CHECK( hxtAlignedMalloc(&m->pyramids.node, (m->pyramids.num)*5*sizeof(uint32_t)) );
    if (m->pyramids.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->pyramids.colors, (m->pyramids.num)*sizeof(uint16_t)) );
    if (m->pyramids.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->pyramids.size = m->pyramids.num;
  }
  if (m->triangles.num){
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.node, (m->triangles.num)*3*sizeof(uint32_t)) );
    if (m->triangles.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.colors, (m->triangles.num)*sizeof(uint16_t)) );
    if (m->triangles.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->triangles.size = m->triangles.num;
  }
  if (m->quads.num){
    HXT_CHECK( hxtAlignedMalloc(&m->quads.node, (m->quads.num)*4*sizeof(uint32_t)) );
    if (m->quads.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->quads.colors, (m->quads.num)*sizeof(uint16_t)) );
    if (m->quads.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->quads.size = m->quads.num;
  }
  if (m->lines.num){
    HXT_CHECK( hxtAlignedMalloc(&m->lines.node, (m->lines.num)*2*sizeof(uint32_t)) );
    if (m->lines.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->lines.colors, (m->lines.num)*sizeof(uint16_t)) );
    if (m->lines.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->lines.size = m->lines.num;
  }
        
  while( fgets(buf, BUFSIZ, fp )){

    if(strstr(buf, "$Elements")){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
      
      int tmpK = atoi(buf);
      m->tetrahedra.num=0;
      m->hexahedra.num=0;
      m->prisms.num=0;
      m->pyramids.num=0;
      m->triangles.num=0;
      m->quads.num=0;
      m->lines.num=0;
      
      for(k=0;k<tmpK;++k){
        int etype = 0, ntags;
        if(fgets(buf, BUFSIZ, fp )==NULL)
          return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
        sscanf(buf, "%*d %d %d", &etype, &ntags);
        if(etype==TETID){ // tets
          if(ntags==2){ // 
            int a, b, c, d, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d %d %d", 
                   &color,&a, &b, &c, &d);
            m->tetrahedra.node[4*m->tetrahedra.num+0] = a-1;
            m->tetrahedra.node[4*m->tetrahedra.num+1] = b-1;
            m->tetrahedra.node[4*m->tetrahedra.num+2] = c-1;
            m->tetrahedra.node[4*m->tetrahedra.num+3] = d-1;
            m->tetrahedra.colors[m->tetrahedra.num] = color;
          }
          ++m->tetrahedra.num;
        }
        else if(etype==HEXID){ // hexahedra
          if(ntags==2){ // 
            int a, b, c, d, e, f, g, h, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d %d %d %d %d %d %d", 
                   &color,&a, &b, &c, &d, &e, &f, &g, &h);
            m->hexahedra.node[8*m->hexahedra.num+0] = a-1;
            m->hexahedra.node[8*m->hexahedra.num+1] = b-1;
            m->hexahedra.node[8*m->hexahedra.num+2] = c-1;
            m->hexahedra.node[8*m->hexahedra.num+3] = d-1;
            m->hexahedra.node[8*m->hexahedra.num+4] = e-1;
            m->hexahedra.node[8*m->hexahedra.num+5] = f-1;
            m->hexahedra.node[8*m->hexahedra.num+6] = g-1;
            m->hexahedra.node[8*m->hexahedra.num+7] = h-1;
            m->hexahedra.colors[m->hexahedra.num] = color;
          }
          ++m->hexahedra.num;
        }
        else if(etype==PRIID){ // prisms
          if(ntags==2){ // 
            int a, b, c, d, e, f, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d %d %d %d %d", 
                   &color,&a, &b, &c, &d, &e, &f);
            m->prisms.node[6*m->prisms.num+0] = a-1;
            m->prisms.node[6*m->prisms.num+1] = b-1;
            m->prisms.node[6*m->prisms.num+2] = c-1;
            m->prisms.node[6*m->prisms.num+3] = d-1;
            m->prisms.node[6*m->prisms.num+4] = e-1;
            m->prisms.node[6*m->prisms.num+5] = f-1;
            m->prisms.colors[m->prisms.num] = color;
          }
          ++m->prisms.num;
        }
        else if(etype==PYRID){ // pyramids
          if(ntags==2){ // 
            int a, b, c, d, e, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d %d %d %d", 
                   &color,&a, &b, &c, &d, &e);
            m->pyramids.node[5*m->pyramids.num+0] = a-1;
            m->pyramids.node[5*m->pyramids.num+1] = b-1;
            m->pyramids.node[5*m->pyramids.num+2] = c-1;
            m->pyramids.node[5*m->pyramids.num+3] = d-1;
            m->pyramids.node[5*m->pyramids.num+4] = e-1;
            m->pyramids.colors[m->pyramids.num] = color;
          }
          ++m->pyramids.num;
        }
        else if(etype==TRIID){ // triangles
          if(ntags==2){ // 
            int a, b, c, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d %d", 
                   &color,&a, &b, &c);
            m->triangles.node[3*m->triangles.num+0] = a-1;
            m->triangles.node[3*m->triangles.num+1] = b-1;
            m->triangles.node[3*m->triangles.num+2] = c-1;
            m->triangles.colors[m->triangles.num] = color;
          }
          ++m->triangles.num;
        }
        else if(etype==QUADID){ // quads
          if(ntags==2){ // 
            int a, b, c, d, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d %d %d", 
                   &color,&a, &b, &c, &d);
            m->quads.node[4*m->quads.num+0] = a-1;
            m->quads.node[4*m->quads.num+1] = b-1;
            m->quads.node[4*m->quads.num+2] = c-1;
            m->quads.node[4*m->quads.num+3] = d-1;
            m->quads.colors[m->quads.num] = color;
          }
          ++m->quads.num;
        }
        else if(etype==POINTID){ // lines
          if(ntags==2){ // 
            int a;
            sscanf(buf, "%*d %*d %*d %*d %*d  %d",&a);
            //            m->lines.node[2*m->lines.num+0] = a-1;
            //            m->lines.node[2*m->lines.num+1] = b-1;
          }
        }
        if(etype==LINEID){ // lines
          if(ntags==2){ // 
            int a, b, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d", 
            &color, &a, &b);
            m->lines.node[2*m->lines.num+0] = a-1;
            m->lines.node[2*m->lines.num+1] = b-1;
            m->lines.colors[m->lines.num] = color;
          }
          ++m->lines.num;
        }
      }      
      break;
    }
  }

  return HXT_STATUS_OK;
}

HXTStatus  hxtMeshReadGmsh  ( HXTMesh* m , const char *filename) {
  FILE *f = fopen (filename, "r");
  if (f==NULL)
    return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED,
      "Cannot open mesh file \"%s\"",(filename==NULL)?"(null)":filename);

  HXT_CHECK(
    ReadNodesFromGmsh(f,m));

  HXT_CHECK(
    ReadElementsFromGmsh(f, m));
  
  fclose (f);
  return HXT_STATUS_OK;
}



// writes the gmsh stuff
HXTStatus  hxtMeshWriteGmsh  ( HXTMesh* mesh , const char *filename) {
  FILE* file = fopen(filename,"w");
  if(file==NULL)
    return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED,
      "Cannot open mesh file \"%s\"",(filename==NULL)?"(null)":filename);

  /* format for gmsh */
  fprintf(file,"$MeshFormat\n"
               "2.2 0 %u\n"
               "$EndMeshFormat\n"
               "$Nodes\n"
               "%u\n",(unsigned) sizeof(double), mesh->vertices.num);
  
  { /* print the nodes */
    uint32_t i;
    for (i=0; i<mesh->vertices.num; i++)
      fprintf(file,"%u %.10E %.10E %.10E\n",i+1, mesh->vertices.coord[(size_t) 4*i+0], mesh->vertices.coord[(size_t) 4*i+1], mesh->vertices.coord[(size_t) 4*i+2]);
  }

  // count non-ghost vertex:
  uint64_t index = 0;
  uint64_t i;
  #pragma omp parallel for reduction(+:index)
  for (i=0; i<mesh->tetrahedra.num; i++)
  {
    if(mesh->tetrahedra.node[i*4 + 3]!=UINT32_MAX){
      uint16_t myColor = mesh->tetrahedra.colors ? mesh->tetrahedra.colors[i] : 0;
      // color = UINT16_MAX --> outside the domain
      //      if (myColor != UINT16_MAX)
        ++index;
    }
  }
  
  fprintf(file,"$EndNodes\n"
          "$Elements\n"
          "%lu\n",
          index
          + mesh->lines.num
          + mesh->triangles.num
          + mesh->quads.num
          + mesh->hexahedra.num
          + mesh->prisms.num
          + mesh->pyramids.num
          );

  { /* print the elements */
    
    index = 0;
    for (i=0; i<mesh->lines.num; i++){
      uint16_t myColor = mesh->lines.colors ? mesh->lines.colors[i] : 0;
      fprintf(file,"%lu %u 2 0 %u %u %u\n", ++index,LINEID,
              myColor,
              mesh->lines.node[i*2]+1,
              mesh->lines.node[i*2 + 1]+1);
    }
    for (i=0; i<mesh->triangles.num; i++){
      uint16_t myColor = mesh->triangles.colors ? mesh->triangles.colors[i] : 0;
      fprintf(file,"%lu %u 2 0 %u %u %u %u\n", ++index,TRIID,
              myColor,
              mesh->triangles.node[i*3]+1,
              mesh->triangles.node[i*3 + 1]+1,
              mesh->triangles.node[i*3 + 2]+1);
    }
    for (i=0; i<mesh->quads.num; i++){
      uint16_t myColor = mesh->quads.colors ? mesh->quads.colors[i] : 0;
      fprintf(file,"%lu %u 2 0 %u %u %u %u %u\n", ++index,QUADID,
              myColor,
              mesh->quads.node[i*4]+1,
              mesh->quads.node[i*4 + 1]+1,
              mesh->quads.node[i*4 + 2]+1,
              mesh->quads.node[i*4 + 3]+1
              );
    }
    for (i=0; i<mesh->tetrahedra.num; i++){
      if(mesh->tetrahedra.node[i*4 + 3]!=UINT32_MAX){
        uint16_t myColor = mesh->tetrahedra.colors ? mesh->tetrahedra.colors[i] : 0;
	//        if (myColor != UINT16_MAX)
          fprintf(file,"%lu %u 2 0 %u %u %u %u %u\n", ++index,TETID,
              myColor,
              mesh->tetrahedra.node[i*4]+1,
              mesh->tetrahedra.node[i*4 + 1]+1,
              mesh->tetrahedra.node[i*4 + 2]+1,
              mesh->tetrahedra.node[i*4 + 3]+1);
      }
    }
    for (i=0; i<mesh->hexahedra.num; i++){
      if(mesh->hexahedra.node[i*8 + 7]!=UINT32_MAX){
        uint16_t myColor = mesh->hexahedra.colors ? mesh->hexahedra.colors[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file,"%lu %u 2 0 %u %u %u %u %u %u %u %u %u\n", ++index,HEXID,
              myColor,
              mesh->hexahedra.node[i*8]+1,
              mesh->hexahedra.node[i*8 + 1]+1,
              mesh->hexahedra.node[i*8 + 2]+1,
              mesh->hexahedra.node[i*8 + 3]+1,
              mesh->hexahedra.node[i*8 + 4]+1,
              mesh->hexahedra.node[i*8 + 5]+1,
              mesh->hexahedra.node[i*8 + 6]+1,
              mesh->hexahedra.node[i*8 + 7]+1);
      }
    }
    for (i=0; i<mesh->prisms.num; i++){
      if(mesh->prisms.node[i*6 + 5]!=UINT32_MAX){
        uint16_t myColor = mesh->prisms.colors ? mesh->prisms.colors[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file,"%lu %u 2 0 %u %u %u %u %u %u %u\n", ++index,PRIID,
              myColor,
              mesh->prisms.node[i*6]+1,
              mesh->prisms.node[i*6 + 1]+1,
              mesh->prisms.node[i*6 + 2]+1,
              mesh->prisms.node[i*6 + 3]+1,
              mesh->prisms.node[i*6 + 4]+1,
              mesh->prisms.node[i*6 + 5]+1);
      }
    }
    for (i=0; i<mesh->pyramids.num; i++){
      if(mesh->pyramids.node[i*5 + 4]!=UINT32_MAX){
        uint16_t myColor = mesh->pyramids.colors ? mesh->pyramids.colors[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file,"%lu %u 2 0 %u %u %u %u %u %u\n", ++index,PYRID,
              myColor,
              mesh->pyramids.node[i*5]+1,
              mesh->pyramids.node[i*5 + 1]+1,
              mesh->pyramids.node[i*5 + 2]+1,
              mesh->pyramids.node[i*5 + 3]+1,
              mesh->pyramids.node[i*5 + 4]+1);
      }
    }
  }

  fputs("$EndElements\n",file);
  fclose(file);
  return HXT_STATUS_OK;
}


