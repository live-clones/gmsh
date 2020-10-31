#include <stdio.h>
#include "hxt_point_gen_io.h"

HXTStatus hxtPrintVec(const double *vec)
{
  printf("%f %f %f \n", vec[0], vec[1], vec[2]);

  return HXT_STATUS_OK;
}

HXTStatus hxtPointGenExportPointsToPos(HXTMesh* m, 
                                       const char* posFile) 
{
  if (posFile == NULL) return HXT_STATUS_WRITE_ERROR;
  printf("\nWriting %u points to \"%s\"\n", m->vertices.num, posFile);
  FILE* fp = fopen(posFile, "w");
  if (fp == NULL) return HXT_STATUS_WRITE_ERROR;
  fprintf(fp, "View \"%s\" {\n", "points");
  for (uint32_t v = 0; v < m->vertices.num; ++v) {
    const double* p = &(m->vertices.coord[4*v]);
    if (fprintf(fp, "  SP(%.6f,%.6f,%.6f){%i};\n", p[0], p[1], p[2], 0) < 0) {
      return HXT_STATUS_WRITE_ERROR;
    };
  }
  fprintf(fp, "};\n\n");
  fclose(fp);
  return HXT_STATUS_OK;
}


HXTStatus hxtPointGenWriteScalarPoints(HXTMesh *mesh, 
                                       const double *values,
                                       const char *filename)
{
  FILE* file = fopen(filename, "w");
  if (file == NULL) return HXT_STATUS_WRITE_ERROR;
  fprintf(file, "View \"%s\" {\n", "points");
  for (uint32_t i = 0; i<mesh->vertices.num; i++){
    double x = mesh->vertices.coord[4*i+0]; 
    double y = mesh->vertices.coord[4*i+1];
    double z = mesh->vertices.coord[4*i+2];
    fprintf(file, "  SP(%.6f,%.6f,%.6f){%f};\n", x,y,z,values[i]);
  }
  fprintf(file, "};\n\n");
  fclose(file);
  return HXT_STATUS_OK;
}

HXTStatus hxtPointGenWriteScalarTriangles(HXTMesh *mesh, 
                                          const double *values,
                                          const char *filename)
{
  FILE *file = fopen(filename,"w");
  if (file == NULL) return HXT_STATUS_WRITE_ERROR;
  fprintf(file,"View \"Sizes\"{\n");
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(file,"ST(");
    for (uint32_t j=0; j<3; j++){
      uint32_t vv = mesh->triangles.node[3*i+j];
      fprintf(file,"%f,%f,%f", mesh->vertices.coord[4*vv+0], mesh->vertices.coord[4*vv+1], mesh->vertices.coord[4*vv+2]);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,")");
    fprintf(file,"{");
    for ( uint32_t j=0; j<3; j++){
      uint32_t vv = mesh->triangles.node[3*i+j];
      fprintf(file,"%f", values[vv]);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,"};\n");
  }
  fprintf(file,"};");
  fclose(file);
  
  return HXT_STATUS_OK;
}

HXTStatus hxtPointGenWriteSizemapTriangles(HXTMesh *mesh, 
                                           const double *values,
                                           const char *filename)
{
  FILE *file = fopen(filename,"w");
  if (file == NULL) return HXT_STATUS_WRITE_ERROR;
  fprintf(file,"View \"Sizes\"{\n");
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    fprintf(file,"ST(");
    for (uint32_t j=0; j<3; j++){
      uint32_t vv = mesh->triangles.node[3*i+j];
      fprintf(file,"%f,%f,%f", mesh->vertices.coord[4*vv+0], mesh->vertices.coord[4*vv+1], mesh->vertices.coord[4*vv+2]);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,")");
    fprintf(file,"{");
    for ( uint32_t j=0; j<3; j++){
      uint32_t vv = mesh->triangles.node[3*i+j];
      fprintf(file,"%f", values[3*vv+0]);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,"};\n");
  }
  fprintf(file,"};");
  fclose(file);
  
  return HXT_STATUS_OK;
}



HXTStatus hxtPointGenWriteDirections(HXTMesh *mesh, 
                                     const double *directions,
                                     const char *filename)
{
  FILE *file = fopen(filename,"w");
  fprintf(file,"View \"Directions\"{\n");
  for (uint64_t i=0; i<mesh->vertices.num; i++){
    for (uint32_t j=0; j<3; j++){
      fprintf(file,"VT(");
      double x = mesh->vertices.coord[4*i+0]; 
      double y = mesh->vertices.coord[4*i+1]; 
      double z = mesh->vertices.coord[4*i+2]; 
  
      for (uint32_t j=0; j<3; j++){
        fprintf(file,"%f,%f,%f", x, y, z);
        if (j<2)
          fprintf(file,",");
      }
      fprintf(file,")");
      fprintf(file,"{");
      double tempx = directions[9*i+3*j+0];
      double tempy = directions[9*i+3*j+1];
      double tempz = directions[9*i+3*j+2];
  
      for ( uint32_t j=0; j<3; j++){
        fprintf(file,"%f,%f,%f", tempx,tempy,tempz);
        if (j<2)
          fprintf(file,",");
      }
      fprintf(file,"};\n");
    }
  }
  fprintf(file,"};");
  fclose(file);
  
  return HXT_STATUS_OK;
}

HXTStatus hxtPointGenWriteDirectionsEdges(HXTEdges *edges,
                                          const double *directions,
                                          const char *filename)
{
  HXTMesh *mesh = edges->edg2mesh;

  // WRITE DIRECTIONS IN FILE 
  FILE *file = fopen(filename,"w");
  fprintf(file,"View \"Directions\"{\n");
  for (uint64_t i=0; i<edges->numEdges; i++){
    fprintf(file,"VT(");
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    double x = (mesh->vertices.coord[4*v0+0] + mesh->vertices.coord[4*v1+0] ) / 2.;
    double y = (mesh->vertices.coord[4*v0+1] + mesh->vertices.coord[4*v1+1] ) / 2.;
    double z = (mesh->vertices.coord[4*v0+2] + mesh->vertices.coord[4*v1+2] ) / 2.;

    for (uint32_t j=0; j<3; j++){
      fprintf(file,"%f,%f,%f", x, y, z);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,")");
    fprintf(file,"{");
    double tempx = directions[9*i+0];
    double tempy = directions[9*i+1];
    double tempz = directions[9*i+2];
    for ( uint32_t j=0; j<3; j++){
      fprintf(file,"%f,%f,%f", tempx,tempy,tempz);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,"};\n");

    fprintf(file,"VT(");
     v0 = edges->node[2*i+0];
     v1 = edges->node[2*i+1];
     x = (mesh->vertices.coord[4*v0+0] + mesh->vertices.coord[4*v1+0] ) / 2.;
     y = (mesh->vertices.coord[4*v0+1] + mesh->vertices.coord[4*v1+1] ) / 2.;
     z = (mesh->vertices.coord[4*v0+2] + mesh->vertices.coord[4*v1+2] ) / 2.;

    for (uint32_t j=0; j<3; j++){
      fprintf(file,"%f,%f,%f", x, y, z);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,")");
    fprintf(file,"{");
    tempx = directions[9*i+3];
    tempy = directions[9*i+4];
    tempz = directions[9*i+5];
    for ( uint32_t j=0; j<3; j++){
      fprintf(file,"%f,%f,%f", tempx,tempy,tempz);
      if (j<2)
        fprintf(file,",");
    }
    fprintf(file,"};\n");
  }
  fprintf(file,"};");
  fclose(file);

  return HXT_STATUS_OK;
}


HXTStatus hxtPointGenWriteScaledDirections3d(HXTMesh *mesh, 
                                             const double *directions,
                                             const char *filename)
{

  FILE *file = fopen(filename,"w");
  for (uint64_t i=0; i<mesh->vertices.num; i++){
    for (uint32_t j=0; j<3; j++){

      double tempx = directions[9*i+3*j+0];
      double tempy = directions[9*i+3*j+1];
      double tempz = directions[9*i+3*j+2];
      fprintf(file,"%.16g %.16g %.16g ", tempx,tempy,tempz);
    }
    fprintf(file,"\n");
  }
  fprintf(file,"\n");
  fclose(file);
  
  return HXT_STATUS_OK;
}

HXTStatus hxtPointGenReadScaledDirections3d(HXTMesh *mesh, 
                                            double *d,
                                            const char *filename)
{

  FILE *fp = fopen(filename,"r");
  if (fp == NULL)
    return HXT_STATUS_ERROR;

  rewind (fp);
  size_t n;
  char buf[BUFSIZ]={""};
  while( fgets(buf, BUFSIZ, fp )!=NULL){
    for(uint32_t i=0; i<mesh->vertices.num; i++){
      sscanf(buf, "%lf %lf %lf %lf %lf %lf %lf %lf %lf", &d[9*i+0], &d[9*i+1], &d[9*i+2], &d[9*i+3], &d[9*i+4], &d[9*i+5], &d[9*i+6], &d[9*i+7], &d[9*i+8]);
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
    }
  }


  
  return HXT_STATUS_OK;
}





HXTStatus hxtPointGenReadSizesFile2D(const char *filename, 
                                     double** sizes, 
                                     int *numSings,
                                     uint32_t **sings,
                                     uint32_t *numEdges, 
                                     uint32_t **edg, 
                                     double **dirs)
{
 
  FILE *fp = fopen(filename,"r");
  if (fp == NULL)
    return HXT_STATUS_ERROR;

  rewind (fp);
  size_t n;
  char buf[BUFSIZ]={""};
  while( fgets(buf, BUFSIZ, fp )!=NULL){
    // Read sizes on vertices
    uint32_t temp = atoi(buf);
    HXT_CHECK( hxtMalloc(sizes, sizeof( double )*temp) );
    if (dirs == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    for(n=0;n<temp;++n){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
      sscanf(buf, "%*d %lf", &(*sizes)[(size_t) n] );
    }

    // Read indices of singular vertices
    if(fgets(buf, BUFSIZ, fp )==NULL)
      return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
    int nums = atoi(buf);
    *numSings = nums;
    HXT_CHECK(hxtMalloc(sings, sizeof( int )*nums) );
    if (sings == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    printf("ok\n");
    printf("%d \n", nums);
    for(n=0;n<(size_t)nums;++n){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
      sscanf(buf, "%d", &(*sings)[(size_t) n] );
    }

    // Read direction vectors on edges
    if(fgets(buf, BUFSIZ, fp )==NULL)
      return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
    temp = atoi(buf);
    *numEdges = temp;
    HXT_CHECK( hxtMalloc(dirs, sizeof( double )*3*temp) );
    if (dirs == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    HXT_CHECK( hxtMalloc(edg, sizeof( uint32_t )*2*temp) );
    if (edg == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    for(n=0;n<temp;++n){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
      sscanf(buf, "%d %d %*f %*f %*f %lf %lf %lf", &(*edg)[(size_t) 2*n+0], 
                                                   &(*edg)[(size_t) 2*n+1], 
                                                   &(*dirs)[(size_t) 3*n+0], 
                                                   &(*dirs)[(size_t) 3*n+1], 
                                                   &(*dirs)[(size_t) 3*n+2] );
    }
 
    break;
  }  

  fclose(fp);
  return HXT_STATUS_OK;
}


HXTStatus hxtPointGenReadSingularities(const char *filename, 
                                       uint32_t *numSings,
                                       uint32_t **sings)
{

  FILE *fp = fopen(filename,"r");
  if (fp == NULL)
    return HXT_STATUS_ERROR;

  rewind (fp);
  size_t n;
  char buf[BUFSIZ]={""};
  while( fgets(buf, BUFSIZ, fp )!=NULL){

    uint32_t nums = atoi(buf);
    *numSings = nums;
    HXT_CHECK(hxtMalloc(sings, sizeof( int )*nums) );
    if (sings == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    for(n=0;n<(size_t)nums;++n){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
      sscanf(buf, "%d", &(*sings)[(size_t) n] );
    }
 
    break;
  }  

  fclose(fp);
 



  return HXT_STATUS_OK;
}


HXTStatus hxtPointGenReadBinIndices(const char *filename, 
                                    uint32_t sizeVert,
                                    uint32_t *numVert,
                                    uint32_t **bin)
{

  FILE *fp = fopen(filename,"r");
  if (fp == NULL)
    return HXT_STATUS_ERROR;

  rewind (fp);
  size_t n;
  char buf[BUFSIZ]={""};
  while( fgets(buf, BUFSIZ, fp )!=NULL){

    uint32_t nums = atoi(buf);
    *numVert = nums;
    HXT_CHECK(hxtMalloc(bin, sizeof( int )*sizeVert) );
    if (bin == NULL)return HXT_ERROR(HXT_STATUS_OUT_OF_MEMORY);
    for(n=0;n<(size_t)nums;++n){
      if(fgets(buf, BUFSIZ, fp )==NULL)
        return HXT_ERROR_MSG(HXT_STATUS_READ_ERROR, "Failed to read line");
      sscanf(buf, "%d", &(*bin)[(size_t) n] );
    }
 
    break;
  }  

  fclose(fp);
 



  return HXT_STATUS_OK;
}




