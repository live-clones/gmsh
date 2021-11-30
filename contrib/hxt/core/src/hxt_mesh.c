#include "hxt_mesh.h"
#include "hxt_tools.h"
#include <stdio.h>
#include <float.h>

/* Element types, same as Gmsh */
#define POINTID 15
#define LINEID 1
#define TRIID 2
#define QUADID 3
#define TETID 4
#define HEXID 5
#define PRIID 6
#define PYRID 7
#define TRIID2 9

HXTStatus  hxtMeshCreate ( HXTMesh** mesh) {
  HXT_CHECK( hxtMalloc (mesh, sizeof(HXTMesh)) );
  if (*mesh == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);

  // This line, using a compound literal, will initialize everything
  // to zero (and pointers to NULL)
  **mesh = (HXTMesh) {0};

  return HXT_STATUS_OK;
}

HXTStatus hxtMeshDelete ( HXTMesh** mesh) {
  // free on NULL pointer is well defined (it does nothing)

  // vertices
  HXT_CHECK( hxtAlignedFree(&(*mesh)->vertices.coord) );

  // tetrahedra
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.color) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.neigh) );
  //  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.neighType) );
  // HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.subdet) );
  
  // hexahedra
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.color) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.neigh) );
  //  HXT_CHECK( hxtAlignedFree(&(*mesh)->hexahedra.neighType) );

  // prisms
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.color) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.neigh) );
  //  HXT_CHECK( hxtAlignedFree(&(*mesh)->prisms.neighType) );

  // pyramids
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.color) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.flag) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.neigh) );
  //  HXT_CHECK( hxtAlignedFree(&(*mesh)->pyramids.neighType) );

  // triangles
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.color) );

  // triangles2
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles2.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles2.color) );

  // quads
  HXT_CHECK( hxtAlignedFree(&(*mesh)->quads.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->quads.color) );

  // lines
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.color) );

  // points
  HXT_CHECK( hxtAlignedFree(&(*mesh)->points.node) );


  // boundary representation
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.numSurfacesPerVolume) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.surfacesPerVolume) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.numCurvesPerSurface) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.curvesPerSurface) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.endPointsOfCurves) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->brep.points) );

  // reset every fields to zero
  **mesh = (HXTMesh) {0};

  HXT_CHECK( hxtFree(mesh) );
  return HXT_STATUS_OK;
}


// TODO: more checking of fgets
static HXTStatus ReadNodesFromGmsh(FILE *fp,  HXTMesh* m)
{
  rewind (fp);
  size_t n;
  char buf[BUFSIZ];
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
// TODO: why set to zero AND use malloc ? => either set to zero and use realloc, either trust it is zero and malloc
HXTStatus ReadElementsFromGmsh(FILE *fp, HXTMesh* m){
  int k;
  char buf[BUFSIZ]={""};
  
  rewind (fp);

  m->lines.num = 0;
  m->points.num = 0;
  m->triangles.num = 0;
  m->triangles2.num = 0;
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
        else if(etype==TRIID2){ // triangles p2
          ++(m->triangles2.num);
        }
        else if(etype==QUADID){ // quads
          ++(m->quads.num);
        }
        else if(etype==LINEID){ // lines
          ++(m->lines.num);
        }
        else if(etype==POINTID){ // points
          //          ++(m->lines.num);
          ++(m->points.num);
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
    HXT_CHECK( hxtAlignedMalloc(&m->tetrahedra.color, (m->tetrahedra.num)*sizeof(uint16_t)) );
    if (m->tetrahedra.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->tetrahedra.size = m->tetrahedra.num;
  }
  if (m->hexahedra.num){
    HXT_CHECK( hxtAlignedMalloc(&m->hexahedra.node, (m->hexahedra.num)*8*sizeof(uint32_t)) );
    if (m->hexahedra.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->hexahedra.color, (m->hexahedra.num)*sizeof(uint16_t)) );
    if (m->hexahedra.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->hexahedra.size = m->hexahedra.num;
  }
  if (m->prisms.num){
    HXT_CHECK( hxtAlignedMalloc(&m->prisms.node, (m->prisms.num)*6*sizeof(uint32_t)) );
    if (m->prisms.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->prisms.color, (m->prisms.num)*sizeof(uint16_t)) );
    if (m->prisms.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->prisms.size = m->prisms.num;
  }
  if (m->pyramids.num){
    HXT_CHECK( hxtAlignedMalloc(&m->pyramids.node, (m->pyramids.num)*5*sizeof(uint32_t)) );
    if (m->pyramids.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->pyramids.color, (m->pyramids.num)*sizeof(uint16_t)) );
    if (m->pyramids.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->pyramids.size = m->pyramids.num;
  }
  if (m->triangles.num){
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.node, (m->triangles.num)*3*sizeof(uint32_t)) );
    if (m->triangles.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.color, (m->triangles.num)*sizeof(uint16_t)) );
    if (m->triangles.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->triangles.size = m->triangles.num;
  }
  if (m->triangles2.num){
    HXT_CHECK( hxtAlignedMalloc(&m->triangles2.node, (m->triangles2.num)*6*sizeof(uint32_t)) );
    if (m->triangles2.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->triangles2.color, (m->triangles2.num)*sizeof(uint16_t)) );
    if (m->triangles2.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->triangles2.size = m->triangles2.num;
  }
  if (m->quads.num){
    HXT_CHECK( hxtAlignedMalloc(&m->quads.node, (m->quads.num)*4*sizeof(uint32_t)) );
    if (m->quads.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->quads.color, (m->quads.num)*sizeof(uint16_t)) );
    if (m->quads.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->quads.size = m->quads.num;
  }
  if (m->lines.num){
    HXT_CHECK( hxtAlignedMalloc(&m->lines.node, (m->lines.num)*2*sizeof(uint32_t)) );
    if (m->lines.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->lines.color, (m->lines.num)*sizeof(uint16_t)) );
    if (m->lines.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->lines.size = m->lines.num;
  }
  if (m->points.num){
    HXT_CHECK( hxtAlignedMalloc(&m->points.node, (m->points.num)*sizeof(uint32_t)) );
    if (m->points.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->points.size = m->points.num;
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
      m->triangles2.num=0;
      m->quads.num=0;
      m->lines.num=0;
      m->points.num=0;
      
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
            m->tetrahedra.color[m->tetrahedra.num] = color;
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
            m->hexahedra.color[m->hexahedra.num] = color;
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
            m->prisms.color[m->prisms.num] = color;
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
            m->pyramids.color[m->pyramids.num] = color;
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
            m->triangles.color[m->triangles.num] = color;
          }
          ++m->triangles.num;
        }
        else if(etype==TRIID2){ // triangles
          if(ntags==2){ // 
            int a, b, c, d, e, f, color;
            sscanf(buf, "%*d %*d %*d %*d %d   %d %d %d %d %d %d", 
                   &color,&a, &b, &c, &d, &e, &f);
            m->triangles2.node[6*m->triangles.num+0] = a-1;
            m->triangles2.node[6*m->triangles.num+1] = b-1;
            m->triangles2.node[6*m->triangles.num+2] = c-1;
            m->triangles2.node[6*m->triangles.num+3] = d-1;
            m->triangles2.node[6*m->triangles.num+4] = e-1;
            m->triangles2.node[6*m->triangles.num+5] = f-1;
            m->triangles2.color[m->triangles.num] = color;
          }
          ++m->triangles2.num;
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
            m->quads.color[m->quads.num] = color;
          }
          ++m->quads.num;
        }
        else if(etype==POINTID){ // lines
          if(ntags==2){ // 
            int a;
            sscanf(buf, "%*d %*d %*d %*d %*d  %d",&a);
            m->points.node[m->points.num] = a-1;
            //            m->lines.node[2*m->lines.num+0] = a-1;
            //            m->lines.node[2*m->lines.num+1] = b-1;
          }
          ++m->points.num;
        }
        if(etype==LINEID){ // lines
          if(ntags==2){ // 
            int a, b, color;
            sscanf(buf, "%*d %*d %*d %*d %d  %d %d", 
            &color, &a, &b);
            m->lines.node[2*m->lines.num+0] = a-1;
            m->lines.node[2*m->lines.num+1] = b-1;
            m->lines.color[m->lines.num] = color;
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

  //  HXT_CHECK(
  //    ReadMeshFormatFromGmsh(f));

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
      uint16_t myColor = mesh->tetrahedra.color ? mesh->tetrahedra.color[i] : 0;
      // color = UINT16_MAX --> outside the domain
      if (myColor != UINT16_MAX)
        ++index;
    }
  }
  
  fprintf(file,"$EndNodes\n"
          "$Elements\n"
          "%" HXTu64 "\n",
          index
          + mesh->points.num
          + mesh->lines.num
          + mesh->triangles.num
          + mesh->triangles2.num
          + mesh->quads.num
          + mesh->hexahedra.num
          + mesh->prisms.num
          + mesh->pyramids.num
          );

  { /* print the elements */
    
    index = 0;
    for (i=0; i<mesh->points.num; i++){
      fprintf(file,"%lu %u 2 0 %u %u\n", ++index,POINTID,
              mesh->points.node[i]+1,
              mesh->points.node[i]+1);
    }
    for (i=0; i<mesh->lines.num; i++){
      uint16_t myColor = mesh->lines.color ? mesh->lines.color[i] : 0;
      fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u\n", ++index,LINEID,
              myColor,
              mesh->lines.node[i*2]+1,
              mesh->lines.node[i*2 + 1]+1);
    }
    for (i=0; i<mesh->triangles.num; i++){
      uint16_t myColor = mesh->triangles.color ? mesh->triangles.color[i] : 0;
      fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u\n", ++index,TRIID,
              myColor,
              mesh->triangles.node[i*3]+1,
              mesh->triangles.node[i*3 + 1]+1,
              mesh->triangles.node[i*3 + 2]+1);
    }
    for (i=0; i<mesh->triangles2.num; i++){
      uint16_t myColor = mesh->triangles2.color ? mesh->triangles2.color[i] : 0;
      fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u %u %u\n", ++index,TRIID2,
              myColor,
              mesh->triangles2.node[i*6 + 0]+1,
              mesh->triangles2.node[i*6 + 1]+1,
              mesh->triangles2.node[i*6 + 2]+1,
	      mesh->triangles2.node[i*6 + 3]+1,
	      mesh->triangles2.node[i*6 + 4]+1,
	      mesh->triangles2.node[i*6 + 5]+1);
    }
    for (i=0; i<mesh->quads.num; i++){
      uint16_t myColor = mesh->quads.color ? mesh->quads.color[i] : 0;
      fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u\n", ++index,QUADID,
              myColor,
              mesh->quads.node[i*4]+1,
              mesh->quads.node[i*4 + 1]+1,
              mesh->quads.node[i*4 + 2]+1,
              mesh->quads.node[i*4 + 3]+1
              );
    }
    for (i=0; i<mesh->tetrahedra.num; i++){
      if(mesh->tetrahedra.node[i*4 + 3]!=UINT32_MAX){
        uint16_t myColor = mesh->tetrahedra.color ? mesh->tetrahedra.color[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u\n", ++index,TETID,
              myColor,
              mesh->tetrahedra.node[i*4]+1,
              mesh->tetrahedra.node[i*4 + 1]+1,
              mesh->tetrahedra.node[i*4 + 2]+1,
              mesh->tetrahedra.node[i*4 + 3]+1);
      }
    }
    for (i=0; i<mesh->hexahedra.num; i++){
      if(mesh->hexahedra.node[i*8 + 7]!=UINT32_MAX){
        uint16_t myColor = mesh->hexahedra.color ? mesh->hexahedra.color[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u %u %u %u %u\n", ++index,HEXID,
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
        uint16_t myColor = mesh->prisms.color ? mesh->prisms.color[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u %u %u\n", ++index,PRIID,
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
        uint16_t myColor = mesh->pyramids.color ? mesh->pyramids.color[i] : 0;
        if (myColor != UINT16_MAX)
          fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u %u\n", ++index,PYRID,
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

