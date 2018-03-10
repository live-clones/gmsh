#include "hxt_mesh.h"
#include <float.h>

#define POINTID 15
#define LINEID 1
#define TRIID 2
#define TETID 4
#define QUADID 3

HXTStatus  hxtMeshCreate ( HXTContext* ctx, HXTMesh** mesh) {
  HXT_CHECK( hxtMalloc (mesh, sizeof(HXTMesh)) );
  if (*mesh == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  (*mesh)->ctx = ctx;

  // vertices
  (*mesh)->vertices.coord = NULL;
  (*mesh)->vertices.num = 0;
  (*mesh)->vertices.size = 0;
  (*mesh)->typeStat = NULL;

  // tetrahedra
  (*mesh)->tetrahedra.node = NULL;
  (*mesh)->tetrahedra.colors = NULL;
  (*mesh)->tetrahedra.neigh = NULL;
  // (*mesh)->tetrahedra.subdet = NULL;
  (*mesh)->tetrahedra.num = 0;
  (*mesh)->tetrahedra.size = 0;

  // triangles
  (*mesh)->triangles.node = NULL;
  (*mesh)->triangles.colors = NULL;
  (*mesh)->triangles.num = 0;
  (*mesh)->triangles.size = 0;

  // lines
  (*mesh)->lines.node = NULL;
  (*mesh)->lines.colors = NULL;
  (*mesh)->lines.num = 0;
  (*mesh)->lines.size = 0;

  // (*mesh)->numHexahedra = 0; 
  return HXT_STATUS_OK;
}

HXTStatus hxtMeshDelete ( HXTMesh** mesh) {
  // free on NULL pointer is well defined (it does nothing)

  // vertices
  HXT_CHECK( hxtAlignedFree(&(*mesh)->vertices.coord) );

  // tetrahedra
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.colors) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.neigh) );
  // HXT_CHECK( hxtAlignedFree(&(*mesh)->tetrahedra.subdet) );

  // triangles
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->triangles.colors) );

  // lines
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.node) );
  HXT_CHECK( hxtAlignedFree(&(*mesh)->lines.colors) );

  HXT_CHECK( hxtFree(&(*mesh)->typeStat) );

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
  while( fgets(buf, BUFSIZ, fp )){
    
    if(strstr(buf, "$Nodes")){
      fgets(buf, BUFSIZ, fp );

      m->vertices.num = atoi(buf);
      HXT_CHECK( hxtAlignedMalloc(&m->vertices.coord, 4*m->vertices.num*sizeof( double )) );
      if (m->vertices.coord == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
      m->vertices.size = m->vertices.num;
      for(n=0;n<m->vertices.num;++n){
        fgets(buf, BUFSIZ, fp );
        sscanf(buf, "%*d %lf %lf %lf", &m->vertices.coord[4*n+0], &m->vertices.coord[4*n+1], &m->vertices.coord[4*n+2]);
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
  m->tetrahedra.num = 0;

  while(fgets(buf, BUFSIZ, fp )){    
    if(strstr(buf, "$Elements")){
      fgets(buf, BUFSIZ, fp );      
      int tmpK = atoi(buf);      
      for(k=0;k<tmpK;++k){
        int etype = 0;
        fgets(buf, BUFSIZ, fp );
        sscanf(buf, "%*d %d", &etype);
        if(etype==TETID){ // tets
          ++(m->tetrahedra.num);
        }
        else if(etype==TRIID){ // triangles
          ++(m->triangles.num);
        }
        else if(etype==LINEID){ // triangles
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
  if (m->triangles.num){
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.node, (m->triangles.num)*3*sizeof(uint32_t)) );
    if (m->triangles.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->triangles.colors, (m->triangles.num)*sizeof(uint16_t)) );
    if (m->triangles.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  }
  if (m->lines.num){
    HXT_CHECK( hxtAlignedMalloc(&m->lines.node, (m->lines.num)*2*sizeof(uint32_t)) );
    if (m->lines.node == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtAlignedMalloc(&m->lines.colors, (m->lines.num)*sizeof(uint16_t)) );
    if (m->lines.colors == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  }
        
  while( fgets(buf, BUFSIZ, fp )){

    if(strstr(buf, "$Elements")){
      fgets(buf, BUFSIZ, fp );
      
      int tmpK = atoi(buf);
      m->tetrahedra.num=m->triangles.num=m->lines.num=0;
      
      for(k=0;k<tmpK;++k){
        int etype = 0, ntags;
        fgets(buf, BUFSIZ, fp );
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

  // LINEID 1        typeStat[1] = lines.num
  // TRIID  2   typeStat[2] = triangles.num
  // TETID  4   typeStat[4] = tetrahedra.num
  // QUADID 3   typeStat[3] = quadangles.num
  HXT_CHECK( hxtMalloc (&m->typeStat, 5*sizeof(uint64_t)) );
  if (m->typeStat == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
  m->typeStat[0] = 0;
  m->typeStat[1] = m->lines.num;
  m->typeStat[2] = m->triangles.num;
  m->typeStat[4] = m->tetrahedra.num;
  m->typeStat[3] = 0;

  return HXT_STATUS_OK;
}

HXTStatus  hxtMeshReadGmsh  ( HXTMesh* m , const char *filename) {
  FILE *f = fopen (filename, "r");
  if (!f) return HXT_ERROR_MSG(HXT_STATUS_FILE_CANNOT_BE_OPENED, "mesh file '%s' cannot be opened",(filename==NULL)?"NULL":filename);

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
    HXT_ERROR_MSG(HXT_STATUS_FAILED, "Cannot open file %s",filename);

  /* format for gmsh */
  fprintf(file,"$MeshFormat\n"
               "2.2 0 %u\n"
               "$EndMeshFormat\n"
               "$Nodes\n"
               "%u\n",(unsigned) sizeof(double), mesh->vertices.num);
  
  { /* print the nodes */
    uint32_t i;
    for (i=0; i<mesh->vertices.num; i++)
      fprintf(file,"%u %.10E %.10E %.10E\n",i+1, mesh->vertices.coord[4*i+0], mesh->vertices.coord[4*i+1], mesh->vertices.coord[4*i+2]);
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
      if (myColor != UINT16_MAX)
        ++index;
    }
  }
  
  fprintf(file,"$EndNodes\n"
          "$Elements\n"
          "%lu\n",index+mesh->triangles.num+mesh->lines.num);

  { /* print the elements */
    
    index = 0;
    for (i=0; i<mesh->lines.num; i++){
      uint16_t myColor = mesh->lines.colors ? mesh->lines.colors[i] : 0;
      fprintf(file,"%llu %u 2 0 %u %u %u \n", ++index,LINEID,
              myColor,
              mesh->lines.node[i*2]+1,
              mesh->lines.node[i*2 + 1]+1);
    }
    for (i=0; i<mesh->triangles.num; i++){
      uint16_t myColor = mesh->triangles.colors ? mesh->triangles.colors[i] : 0;
      fprintf(file,"%llu %u 2 0 %u %u %u %u \n", ++index,TRIID,
              myColor,
              mesh->triangles.node[i*3]+1,
              mesh->triangles.node[i*3 + 1]+1,
              mesh->triangles.node[i*3 + 2]+1);
    }
    for (i=0; i<mesh->tetrahedra.num; i++){
      if(mesh->tetrahedra.node[i*4 + 3]!=UINT32_MAX){
        uint16_t myColor = mesh->tetrahedra.colors ? mesh->tetrahedra.colors[i] : 0;
	if (myColor != UINT16_MAX)
          fprintf(file,"%llu %u 2 0 %u %u %u %u %u\n", ++index,TETID,
                  myColor,
                  mesh->tetrahedra.node[i*4]+1,
                  mesh->tetrahedra.node[i*4 + 1]+1,
                  mesh->tetrahedra.node[i*4 + 2]+1,
                  mesh->tetrahedra.node[i*4 + 3]+1);
      }
    }
  }

  fputs("$EndElements\n",file);
  fclose(file);
  return HXT_STATUS_OK;
}


