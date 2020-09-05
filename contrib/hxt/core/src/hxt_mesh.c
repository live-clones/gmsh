#include "hxt_mesh.h"
#include "hxt_tools.h"
#include <stdio.h>
#include <float.h>

/* Element types, same as Gmsh */
#define POINTID 15
#define LINEID 1
#define TRIID 2
#define TETID 4

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
  // HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.subdet) );

  // triangles
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.color) );

  // lines
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.color) );

  // points
  HXT_CHECK( hxtAlignedFree(&(*mesh)->points.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->points.color) );

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


static HXTStatus ReadMeshFormatFromGmsh(FILE *fp)
{
  char buf[BUFSIZ];
  int found = 0;
  while(fgets(buf, BUFSIZ, fp )){    
    if(strstr(buf, "$MeshFormat")){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to format");
      float version;
      int match = sscanf(buf, " %f 0 8 ", &version);
      if(match!=1 || version!=2.2f) {
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "HXT only support Gmsh's MSH2 ASCII file format %f %d", version, match);
      }
      found = 1;
      break;
    }
  }

  if(!found)
    return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Unrecognized format. HXT only support Gmsh's MSH2 ASCII file format");

  return HXT_STATUS_OK;
}
  

// TODO: add possibility to read the elements from an array

// TODO: more checking of fgets
// TODO: why set to zero AND use malloc ? => either set to zero and use realloc, either trust it is zero and malloc
static HXTStatus ReadElementsFromGmsh(FILE *fp, HXTMesh* m)
{
  int k;
  char buf[BUFSIZ];
  
  rewind (fp);

  m->lines.num = 0;
  m->points.num = 0;
  m->triangles.num = 0;
  m->tetrahedra.num = 0;

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
        else if(etype==TRIID){ // triangles
          ++(m->triangles.num);
        }
        else if(etype==LINEID){ // lines
          ++(m->lines.num);
        }
        else if(etype==POINTID){ // points
          //          ++(m->lines.num);
          ++(m->points.num);
        }
        else {
          return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "unsupported element. HXT only support points, lines, triangles and tetrahedra.");
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
    HXT_CHECK( hxtAlignedMalloc(&m->tetrahedra.color, (m->tetrahedra.num)*sizeof(uint32_t)) );
    if (m->tetrahedra.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->tetrahedra.size = m->tetrahedra.num;
  }
  if (m->triangles.num){
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.node, (m->triangles.num)*3*sizeof(uint32_t)) );
    if (m->triangles.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.color, (m->triangles.num)*sizeof(uint32_t)) );
    if (m->triangles.color == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    m->triangles.size = m->triangles.num;
  }
  if (m->lines.num){
    HXT_CHECK( hxtAlignedMalloc(&m->lines.node, (m->lines.num)*2*sizeof(uint32_t)) );
    if (m->lines.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->lines.color, (m->lines.num)*sizeof(uint32_t)) );
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
      m->triangles.num=0;
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
        else if(etype==LINEID){ // lines
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
        else if(etype==POINTID){ // points
          if(ntags==2){ // 
            int a;
            sscanf(buf, "%*d %*d %*d %*d %*d  %d",&a);
            m->points.node[m->points.num] = a-1;
            //            m->lines.node[2*m->lines.num+0] = a-1;
            //            m->lines.node[2*m->lines.num+1] = b-1;
          }
          ++m->points.num;
        }
        else return HXT_STATUS_READ_ERROR;
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
    ReadMeshFormatFromGmsh(f));

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

  // count non-ghost tetrahedra:
  uint64_t numRealTet = 0;
  uint64_t i;
  #pragma omp parallel for reduction(+:numRealTet)
  for (i=0; i<mesh->tetrahedra.num; i++)
  {
    if(mesh->tetrahedra.node[i*4 + 3]!=UINT32_MAX){
      uint32_t myColor = mesh->tetrahedra.color!=NULL ? mesh->tetrahedra.color[i] : 0;
      // color = HXT_COLOR_OUT --> outside the domain
      if (myColor != HXT_COLOR_OUT)
        ++numRealTet;
    }
  }
  
  fprintf(file,"$EndNodes\n"
          "$Elements\n"
          "%" HXTu64 "\n",
          numRealTet
          + mesh->points.num
          + mesh->lines.num
          + mesh->triangles.num
          );

  { /* print the elements */
    
    uint64_t index = 0;
    for (i=0; i<mesh->points.num; i++){
      fprintf(file,"%lu %u 2 0 %u %u\n", ++index,POINTID,
              mesh->points.node[i]+1,
              mesh->points.node[i]+1);
    }
    for (i=0; i<mesh->lines.num; i++){
      uint32_t myColor = mesh->lines.color ? mesh->lines.color[i] : 0;
      if (myColor != HXT_COLOR_OUT) {
        fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u\n", ++index,LINEID,
                myColor,
                mesh->lines.node[i*2]+1,
                mesh->lines.node[i*2 + 1]+1);
      }
    }
    for (i=0; i<mesh->triangles.num; i++){
      uint32_t myColor = mesh->triangles.color ? mesh->triangles.color[i] : 0;
      if (myColor != HXT_COLOR_OUT) {
        fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u\n", ++index,TRIID,
                myColor,
                mesh->triangles.node[i*3]+1,
                mesh->triangles.node[i*3 + 1]+1,
                mesh->triangles.node[i*3 + 2]+1);
      }
    }
    for (i=0; i<mesh->tetrahedra.num; i++){
      if(mesh->tetrahedra.node[i*4 + 3]!=UINT32_MAX){
        uint32_t myColor = mesh->tetrahedra.color ? mesh->tetrahedra.color[i] : 0;
        if (myColor != HXT_COLOR_OUT) {
          fprintf(file, "%" HXTu64 " %u 2 0 %u %u %u %u %u\n", ++index,TETID,
              myColor,
              mesh->tetrahedra.node[i*4]+1,
              mesh->tetrahedra.node[i*4 + 1]+1,
              mesh->tetrahedra.node[i*4 + 2]+1,
              mesh->tetrahedra.node[i*4 + 3]+1);
        }
      }
    }
  }

  fputs("$EndElements\n",file);
  fclose(file);
  return HXT_STATUS_OK;
}

