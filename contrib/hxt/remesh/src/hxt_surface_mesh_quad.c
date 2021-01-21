#include "hxt_surface_mesh_quad.h"

#include "hxt_tools.h"
#include "hxt_edge.h"
#include "hxt_point_gen_utils.h"
#include "hxt_point_gen_realloc.h"

#include "hxt_point_gen_numerics.h"

#include "hxt_split_edge.h"

#include "hxt_surface_mesh_processing.h"

#include "hxt_rtree_wrapper.h"


#include "hxt_point_gen_options.h"


#include "hxt_post_debugging.h"


//*****************************************************************************************
//*****************************************************************************************
//
//*****************************************************************************************
//*****************************************************************************************
uint32_t hamming(uint32_t n1, uint32_t n2)
{
  uint32_t x = n1^n2;
  int setBits = 0;
  
  while (x>0){
    setBits += x&1;
    x >>= 1;
  }
  return setBits;
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to print 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtPointGenQuadPrintInfo(HXTMesh *mesh, 
                                   uint32_t *bin, 
                                   uint16_t *flagTris,
                                   const char *fmesh,
                                   const char *fpos)
{

  hxtMeshWriteGmsh(mesh,fmesh);
  FILE *test;
  hxtPosInit(fpos,"edges",&test);
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (flagTris[i] == UINT16_MAX) continue;
    uint32_t *v = mesh->triangles.node + 3*i;
    hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
  }
  hxtPosNewView(test,"bin");
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (flagTris[i] == UINT16_MAX) continue;
    uint32_t *v = mesh->triangles.node + 3*i;
    //hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
    hxtPosAddPoint(test,&mesh->vertices.coord[4*v[0]],bin[v[0]]);
    hxtPosAddPoint(test,&mesh->vertices.coord[4*v[1]],bin[v[1]]);
    hxtPosAddPoint(test,&mesh->vertices.coord[4*v[2]],bin[v[2]]);
  }
  hxtPosNewView(test,"binText");
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (flagTris[i] == UINT16_MAX) continue;
    uint32_t *v = mesh->triangles.node + 3*i;
    //hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
    hxtPosAddText(test,&mesh->vertices.coord[4*v[0]],"%d",bin[v[0]]);
    hxtPosAddText(test,&mesh->vertices.coord[4*v[1]],"%d",bin[v[1]]);
    hxtPosAddText(test,&mesh->vertices.coord[4*v[2]],"%d",bin[v[2]]);
  }
  hxtPosNewView(test,"binAll");
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    hxtPosAddPoint(test,&mesh->vertices.coord[4*i],bin[i]);
  }
  hxtPosFinish(test);


  return HXT_STATUS_OK; 
}

//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to output singularities of a quad mesh 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtSurfaceQuadSingularitiesOutput(HXTPointGenOptions *opt, HXTMesh *mesh)
{

  uint32_t *isBoundary;
  HXT_CHECK(hxtMalloc(&isBoundary,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) isBoundary[i] = UINT32_MAX;
  for (uint64_t i=0; i<mesh->lines.num; i++){
    isBoundary[mesh->lines.node[2*i+0]] = 1;
    isBoundary[mesh->lines.node[2*i+1]] = 1;
  }

  uint32_t *isFeature;
  HXT_CHECK(hxtMalloc(&isFeature,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) isFeature[i] = UINT32_MAX;
  for (uint64_t i=0; i<mesh->points.num; i++){
    isFeature[mesh->points.node[i]] = 1;
  }

  uint64_t *counter;
  HXT_CHECK(hxtMalloc(&counter,mesh->vertices.num*sizeof(uint64_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) counter[i] = 0;

  for (uint64_t i=0; i<mesh->quads.num; i++){
    uint32_t *v = mesh->quads.node + 4*i;

    for (uint32_t j=0; j<4; j++){
      counter[v[j]]++;
    }
  }

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    //if (counter[i] > 5) printf("PROBLEM - did not expect this\n");
    if (counter[i] == 1 && isBoundary[i] != 1){
    
      return HXT_ERROR_MSG(HXT_STATUS_ERROR," !!! Huge error - vertex with only one quad");
    }

  }

  uint32_t c1 = 0;
  uint32_t c2 = 0;
  uint32_t c3 = 0;
  uint32_t c5 = 0;
  uint32_t c6 = 0;

  uint32_t c1b = 0;
  uint32_t c2b = 0;
  uint32_t c3b = 0;
  uint32_t c5b = 0;
  uint32_t c6b = 0;


  if (opt->verbosity>=1){
    FILE *test;
    hxtPosInit("checkSing.pos","featurePoints",&test);
    for (uint32_t i=0; i<mesh->points.num; i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*mesh->points.node[i]],0);
    }
    hxtPosNewView(test,"sing1");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (counter[i]==1){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c1++;
      }
    }
    hxtPosNewView(test,"sing2");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (counter[i]==2){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c2++;
      }
    }
    hxtPosNewView(test,"sing3");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (counter[i]==3){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c3++;
      }
    }
    hxtPosNewView(test,"sing5");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (counter[i]==5){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c5++;
      }
    }

    hxtPosNewView(test,"sing6");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (counter[i]>5){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c6++;
      }
    }


    hxtPosNewView(test,"sing1boundary");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] != 1) continue;
      if (isFeature[i] == 1) continue;
      if (counter[i]==1){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c1b++;
      }
    }
    hxtPosNewView(test,"sing2boundary");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] != 1) continue;
      if (isFeature[i] == 1) continue;
      if (counter[i]==2){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c2b++;
      }
    }
    hxtPosNewView(test,"sing3boundary");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] != 1) continue;
      if (isFeature[i] == 1) continue;
      if (counter[i]==3){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c3b++;
      }
    }
    hxtPosNewView(test,"sing5boundary");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] != 1) continue;
      if (isFeature[i] == 1) continue;
      if (counter[i]==5){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c5b++;
      }
    }

    hxtPosNewView(test,"sing6boundary");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] != 1) continue;
      if (isFeature[i] == 1) continue;
      if (counter[i]>5){
        hxtPosAddPoint(test,&mesh->vertices.coord[4*i],0);
        c6b++;
      }
    }
    hxtPosFinish(test);
  }


  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"========= Singular points info =========");
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"     valence 1      : %d", c1);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 2      : %d", c2);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 3      : %d", c3);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 5      : %d", c5);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 6+     : %d", c6);
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"     valence 1  bnd : %d", c1b);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 3  bnd : %d", c3b);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 5  bnd : %d", c5b);
  HXT_INFO_COND(opt->verbosity>=1,"     valence 6+ bnd : %d", c6b);
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"--- Feature points      = %d ", mesh->points.num);
  HXT_INFO_COND(opt->verbosity>=1,"--- Singular bnd points = %d ", c1b+c3b+c5b+c6b);



  // PRINT OUT FILE 

  // Count interior singularities
  int countInterior=0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (isBoundary[i] == 1) continue;

    if (counter[i] != 3 && counter[i] !=5) continue;

    countInterior++;

  }


  if(opt->verbosity>=1){
    FILE *f=fopen("singularities.txt","w");
    fprintf(f,"%d \n",countInterior);

    for (uint32_t i=0; i<mesh->vertices.num; i++){
      if (isBoundary[i] == 1) continue;

      if (counter[i] != 3 && counter[i] !=5) continue;

      fprintf(f,"%f %f %f \n", mesh->vertices.coord[4*i+0], mesh->vertices.coord[4*i+1], mesh->vertices.coord[4*i+2]);

    }
    fclose(f);
  }



  HXT_CHECK(hxtFree(&isBoundary));
  HXT_CHECK(hxtFree(&isFeature));
  HXT_CHECK(hxtFree(&counter));

  return HXT_STATUS_OK;
}



//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION: find closest triangle from rtree 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenProjectCloseRTree(HXTMesh *omesh, 
                                      void *dataTri,
                                      uint64_t ot,   // assigned triangle
                                      double *pp,
                                      uint64_t *nt,
                                      double *np)
{
  //============================================================================
  // Define a box size to search 
  // taking into account the lenghts of the original triangle
  double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*ot+0];
  double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*ot+1];
  double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*ot+2];
  double size = distance(p0,p1);

  size = 0;
  double s[3] = {0,0,0};
  s[0] = distance(pp,p0);
  s[1] = distance(pp,p1);
  s[2] = distance(pp,p2);

  for (uint32_t i=0; i<3; i++)
    if (s[i]>size) size = s[i];

  double box = 1*size;
  

  double ppmin[3] = {pp[0] - box, pp[1] - box, pp[2] - box};
  double ppmax[3] = {pp[0] + box, pp[1] + box, pp[2] + box};
 
  //============================================================================
  // Find close triangles from RTree of triangles  
  uint64_t numCloseTris = 0;
  uint64_t *idCloseTris = NULL;
  HXT_CHECK(hxtRTreeSearch64(ppmin,ppmax,&numCloseTris,&idCloseTris,dataTri));

  //printf("%lu %f %f \n", numCloseTris, size, distance(p0,pp));

  if (numCloseTris == 0){
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Did not find close triangle, fix it !!!");
    // SEARCH ALL TRIANGLES
    //double tol = 10e-7;
    //double dist,t,closePt[3];
    double dist,closePt[3];
    double minDist = 10e12;
    for (uint32_t i=0; i<omesh->triangles.num; i++){
  
      if (omesh->triangles.color[i] != omesh->triangles.color[ot]) continue;
  
        double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+0];
        double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+1];
        double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+2];
        int inside = 0;
        HXT_CHECK(hxtSignedDistancePointTriangle(p0,p1,p2,pp,&dist,&inside,closePt));
  
        if (fabs(dist)<minDist && omesh->triangles.color[ot] == omesh->triangles.color[i]){
          minDist = fabs(dist);
          *nt = i;
          np[0] = closePt[0];
          np[1] = closePt[1];
          np[2] = closePt[2];
        }
    }
  }
  else{

    double minDist = 10e12;

    for (uint64_t i=0; i<numCloseTris; i++){
      uint64_t tri = idCloseTris[i];
      double dist, closePt[3];
      int in = 0;
      HXT_CHECK(hxtSignedDistancePointTriangle(&omesh->vertices.coord[4*omesh->triangles.node[3*tri+0]],
                                               &omesh->vertices.coord[4*omesh->triangles.node[3*tri+1]],
                                               &omesh->vertices.coord[4*omesh->triangles.node[3*tri+2]],
                                               pp,
                                               &dist,
                                               &in,
                                               closePt));

      if (fabs(dist)<minDist && omesh->triangles.color[ot] == omesh->triangles.color[tri]){
        minDist = fabs(dist);
        *nt = tri;
        np[0] = closePt[0];
        np[1] = closePt[1];
        np[2] = closePt[2];
      }

    }

  }

  HXT_CHECK(hxtFree(&idCloseTris));

  return HXT_STATUS_OK;
}

//**********************************************************************************************************
//**********************************************************************************************************
//
// SIMPLE SMOOTHING
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadSmoothing(HXTMesh *omesh,
                                   HXTMesh *mesh,
                                   void *dataTri,
                                   uint32_t *isBoundary,
                                   uint64_t *p2t,
                                   uint32_t *v2v,
                                   uint32_t nIter)
{

  for (uint32_t ii=0; ii<nIter; ii++){
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      uint32_t cv = i;
      if (isBoundary[cv] == 1) continue;

      // ATTENTION 
      // TODO 
      // just for now for new points that were not correctly projected and assigned with a parent triangle
      if (p2t[i] == UINT64_MAX){
        printf("no parent for point %d \n", i);
        return HXT_STATUS_ERROR;
      }
  
      double x = 0;
      double y = 0;
      double z = 0;
      int vertNum = 0;
      for (uint32_t kk =0 ;kk<5; kk++){
        uint32_t v0 = v2v[5*cv+kk];
        if (v0 == UINT32_MAX) continue;
  
        x += mesh->vertices.coord[4*v0+0];
        y += mesh->vertices.coord[4*v0+1];
        z += mesh->vertices.coord[4*v0+2];
  
        vertNum++;
      }
      if (vertNum == 0) continue;
      mesh->vertices.coord[4*cv+0] = x/vertNum;
      mesh->vertices.coord[4*cv+1] = y/vertNum;
      mesh->vertices.coord[4*cv+2] = z/vertNum;



      // Project point back to initial triangulation 
      uint64_t nt = p2t[i];
      if (p2t[i] == UINT64_MAX) printf("ERROR %d %d \n", ii, i);
      if (p2t[i] == UINT64_MAX) return HXT_STATUS_ERROR;
      double np[3] = {mesh->vertices.coord[4*cv+0],mesh->vertices.coord[4*cv+1],mesh->vertices.coord[4*cv+2]};

      HXT_CHECK(hxtPointGenProjectCloseRTree(omesh,dataTri,p2t[i],&mesh->vertices.coord[4*cv],&nt,np));

      p2t[i] = nt;
      mesh->vertices.coord[4*cv+0] = np[0];
      mesh->vertices.coord[4*cv+1] = np[1];
      mesh->vertices.coord[4*cv+2] = np[2];
  
    }
  }




  return HXT_STATUS_OK; 
}

//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadBuildV2V(HXTEdges *edges,
                              uint32_t *bin,
                              uint32_t *v2v)
{

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    if (bin[v0] == bin[v1]) continue;

    int insert0 = 1;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*v0+j] == v1) insert0 = 0;
    }

    /*int full = 1;*/
    /*for (uint32_t j=0; j<5; j++){*/
      /*if (v2v[5*v0+j] == UINT32_MAX) full = 0;*/
    /*}*/
    /*if (full == 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"v2v is full for %d", v0);*/

    if (insert0 == 1){
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*v0+j] == UINT32_MAX){
          v2v[5*v0+j] = v1;
          break;
        }
      }
    }

    int insert1 = 1;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*v1+j] == v0) insert1 = 0;
    }
    if(insert1 == 1){
      for (uint32_t j=0; j<5; j++){
        if (v2v[5*v1+j] == UINT32_MAX){
          v2v[5*v1+j] = v0;
          break;
        }
      }
    }
  }

  return HXT_STATUS_OK;
}

//**********************************************************************************************************
//**********************************************************************************************************
//
//**********************************************************************************************************
//**********************************************************************************************************
double hxtPointGenQuadQuality(double *p0, double *p1, double *p2, double *p3)
{

  double const a0 = 180 * hxtAngle3Vertices(p3,p0,p1) / M_PI;
  double const a1 = 180 * hxtAngle3Vertices(p2,p1,p0) / M_PI;
  double const a2 = 180 * hxtAngle3Vertices(p3,p2,p1) / M_PI;
  double const a3 = 180 * hxtAngle3Vertices(p0,p3,p2) / M_PI;

  double quality = fabs(90. - a0);
  quality = fmax(fabs(90. - a1), quality);
  quality = fmax(fabs(90. - a2), quality);
  quality = fmax(fabs(90. - a3), quality);

  quality = fmax( (1-2*quality/180),0);

  /*printf("%f %f %f %f \n", a0,a1,a2,a3);*/
  /*printf("%f %f %f \n", quality, 2/M_PI, 1-2*quality/180);*/
  /*printf("%f \n", quality);*/

  return quality;
}

//**********************************************************************************************************
//**********************************************************************************************************
//
//**********************************************************************************************************
//**********************************************************************************************************
double hxtPointGenQuadScaledJacobian(double *p0, double *p1, double *p2, double *p3)
{

  double L0[3] = {p1[0]-p0[0],p1[1]-p0[1],p1[2]-p0[2]};
  double L1[3] = {p2[0]-p1[0],p2[1]-p1[1],p2[2]-p1[2]};
  double L2[3] = {p3[0]-p2[0],p3[1]-p2[1],p3[2]-p2[2]};
  double L3[3] = {p0[0]-p3[0],p0[1]-p3[1],p0[2]-p3[2]};

  double X1[3] = {(p1[0]-p0[0]) + (p2[0]-p3[0]), 
                  (p1[1]-p0[1]) + (p2[1]-p3[1]), 
                  (p1[2]-p0[2]) + (p2[2]-p3[2])}; 

  double X2[3] = {(p2[0]-p1[0]) + (p3[0]-p0[0]), 
                  (p2[1]-p1[1]) + (p3[1]-p0[1]), 
                  (p2[2]-p1[2]) + (p3[2]-p0[2])}; 

  double N0[3];
  HXT_CHECK(myCrossprod(L3,L0,N0));
  double N1[3];
  HXT_CHECK(myCrossprod(L0,L1,N1));
  double N2[3];
  HXT_CHECK(myCrossprod(L1,L2,N2));
  double N3[3];
  HXT_CHECK(myCrossprod(L2,L3,N3));
  double Nc[3];
  HXT_CHECK(myCrossprod(X1,X2,Nc));
  if (norm(Nc) < 1.e-10){
    return 0.;
  }


  HXT_CHECK(normalize(Nc));
  double a0 = myDot(Nc,N0);
  double a1 = myDot(Nc,N1);
  double a2 = myDot(Nc,N2);
  double a3 = myDot(Nc,N3);
  double len0 = norm(L0);
  double len1 = norm(L1);
  double len2 = norm(L2);
  double len3 = norm(L3);

  double sjac = a0/(len0*len3) < a1/(len0*len1) ? a0/(len0*len3) : a1/(len0*len1);

  sjac = sjac < a2/(len1*len2) ? sjac : a2/(len1*len2) ;
  sjac = sjac < a3/(len2*len3) ? sjac : a3/(len2*len3) ;

  return sjac;

  /*double quad_scaled_jacobian(const std::array<vec3,4>& pts) {*/
    /*//  Based on Sandia Verdict document */
    /*const vec3 L0 = pts[1] - pts[0];*/
    /*const vec3 L1 = pts[2] - pts[1];*/
    /*const vec3 L2 = pts[3] - pts[2];*/
    /*const vec3 L3 = pts[0] - pts[3];*/
    /*const vec3 X1 = (pts[1]-pts[0]) + (pts[2] - pts[3]);*/
    /*const vec3 X2 = (pts[2]-pts[1]) + (pts[3] - pts[0]);*/
    /*const vec3 N0 = cross(L3,L0);*/
    /*const vec3 N1 = cross(L0,L1);*/
    /*const vec3 N2 = cross(L1,L2);*/
    /*const vec3 N3 = cross(L2,L3);*/
    /*const vec3 Nc = cross(X1,X2);*/
    /*if (length(Nc) < 1.e-10) {*/
      /*return 0.;*/
    /*}*/
    /*const vec3 nc = normalize(Nc);*/
    /*const double a0 = dot(nc,N0);*/
    /*const double a1 = dot(nc,N1);*/
    /*const double a2 = dot(nc,N2);*/
    /*const double a3 = dot(nc,N3);*/
    /*const double len0 = length(L0);*/
    /*const double len1 = length(L1);*/
    /*const double len2 = length(L2);*/
    /*const double len3 = length(L3);*/
    /*double sjac = std::min(a0/(len0*len3),a1/(len0*len1));*/
    /*sjac = std::min(sjac,a2/(len1*len2));*/
    /*sjac = std::min(sjac,a3/(len2*len3));*/
    /*return sjac;*/
  /*}*/

}



//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION to remove invalid quads (vertices with only two quad neighbours) 
//          adding points instead of collapsing 
//          this is to have a robust implementation
//          but it will create small elements (quad inside quad type)
//
//          TODO: not used 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadRemoveInvalidQuadsRobust(HXTPointGenOptions *opt,
                                                  HXTMesh *omesh,
                                                  HXTMesh *mesh,
                                                  HXTEdges *edges,
                                                  void *dataTri,
                                                  uint32_t *isBoundary,
                                                  uint64_t *p2t,
                                                  uint32_t *bin)
{
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"--- Removing interior vertices contained in only two (invalid) quads");
  HXT_INFO_COND(opt->verbosity>=1,"");

  // Create v2v array 
  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*5));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;
  HXT_CHECK(hxtPointGenQuadBuildV2V(edges,bin,v2v));


  // Count adjacent opposite indexed points for each one 
  uint32_t *adj;
  HXT_CHECK(hxtMalloc(&adj,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) adj[i] = 0;

  for (uint32_t i=0; i<mesh->vertices.num;i++){
    int count = 0;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*i+j] != UINT32_MAX) count++;
    }
    adj[i] = count;
    if (adj[i] < 2 && isBoundary[i] != 1) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"One quad only for vertex %d",i); 
  }

  // Create vertices 2 edges array
  uint16_t *numEdgesPerVert;
  HXT_CHECK(hxtMalloc(&numEdgesPerVert,mesh->vertices.num*sizeof(uint16_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) numEdgesPerVert[i] = 0;

  uint32_t maxNum = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    numEdgesPerVert[v0] ++;
    numEdgesPerVert[v1] ++;
    if (numEdgesPerVert[v0] > maxNum) maxNum = numEdgesPerVert[v0];
    if (numEdgesPerVert[v1] > maxNum) maxNum = numEdgesPerVert[v1];
  }

  HXT_CHECK(hxtFree(&numEdgesPerVert));

 
  uint32_t *v2e;
  HXT_CHECK(hxtMalloc(&v2e,mesh->vertices.num*maxNum*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num*maxNum; i++) v2e[i] = UINT32_MAX;

  for (uint32_t i=0; i<edges->numEdges; i++){

    uint32_t v0 = edges->node[2*i+0];
    int insert0 = 1;
    for (uint32_t j=0; j<maxNum; j++){
      if (v2e[maxNum*v0+j]==i) insert0 = 0;
    }
    int full0 = 1;
    for (uint32_t j=0; j<maxNum; j++){
      if (v2e[maxNum*v0+j] == UINT32_MAX) full0 = 0;
    }
    if (full0 == 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"v2e is full for %d", v0);

    if (insert0==1){
      for (uint32_t j=0; j<maxNum; j++){
        if(v2e[maxNum*v0+j] == UINT32_MAX){
          v2e[maxNum*v0+j] = i;
          break;
        }
      }
    }


    uint32_t v1 = edges->node[2*i+1];
    int insert1 = 1;
    for (uint32_t j=0; j<maxNum; j++){
      if (v2e[maxNum*v1+j]==i) insert1 = 0;
    }
    int full1 = 1;
    for (uint32_t j=0; j<maxNum; j++){
      if (v2e[maxNum*v1+j] == UINT32_MAX) full1 = 0;
    }
    if (full1 == 1) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"v2e is full for %d", v0);


    if (insert1==1){
      for (uint32_t j=0; j<maxNum; j++){
        if(v2e[maxNum*v1+j] == UINT32_MAX){
          v2e[maxNum*v1+j] = i;
          break;
        }
      }
    }
  }



  uint16_t *flagEdg;
  HXT_CHECK(hxtMalloc(&flagEdg,2*edges->numEdges*sizeof(uint16_t)));
  for (uint64_t i=0; i<2*edges->numEdges; i++) flagEdg[i] = UINT16_MAX;

  for (uint32_t i=0; i<mesh->vertices.num; i++){

    if (isBoundary[i] == 1) continue;
    if (adj[i] != 2) continue;

    int onlyOne = 1;
    for (uint32_t j=0; j<maxNum; j++){
      uint32_t ce = v2e[maxNum*i+j];
      if (ce == UINT32_MAX) continue;

      uint32_t ov = i == edges->node[2*ce+0] ? edges->node[2*ce+1] : edges->node[2*ce+0];

      if (bin[ov] == bin[i]) flagEdg[ce] = 1;

      if (bin[ov] != bin[i] && onlyOne){
        flagEdg[ce] = bin[i];
        onlyOne = 0;
      }
    }

  }

  HXT_CHECK(hxtFree(&v2e));


  //============================================================
  // Split the edges the were flagged
  //============================================================
  for (uint32_t i=0; i<edges->numEdges; i++){

    if (flagEdg[i] == UINT16_MAX) continue;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    uint32_t ov0 = edges->node[2*i+0];
    uint32_t ov1 = edges->node[2*i+1];

    if (t1 == UINT64_MAX) continue;
    if (mesh->triangles.color[t0] != mesh->triangles.color[t1]) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,i,&newEdge));

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.color[t0];
    if (omesh->triangles.color[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else{
      // Search all triangles 
      // TODO search with distance to triangle to find the true parent  
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.color[j] == color) p2t[v0] = j;
      }
    }

    if (bin[ov0] == bin[ov1]){
      bin[v0] = bin[ov0] == 1 ? 0: 1;
    }
    else{
      bin[v0] = flagEdg[i];
    }
  }


  //==================================================================================
  // Split the rest of the triangles (split longest edge) 
  //==================================================================================
  for (uint64_t i=0; i<mesh->triangles.num; i++){

    uint32_t *v = mesh->triangles.node + 3*i;
    int fl = 0;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]) fl = 1;
    if (fl != 1) continue;

    uint32_t split[3] = {0,0,0};
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];

      uint32_t v0 = edges->node[2*ce+0];
      uint32_t v1 = edges->node[2*ce+1];
      
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      if (t1 == UINT64_MAX) continue;
      if (mesh->triangles.color[t0] != mesh->triangles.color[t1]) continue;

      //uint64_t ot = t0 == i ? t1:t0;
      //if (flagTris[ot] == 0) continue;

      uint32_t ov0 = UINT32_MAX;
      uint32_t ov1 = UINT32_MAX;

      for (uint32_t k=0; k<3; k++){
        uint32_t vt1 = mesh->triangles.node[3*t0+k];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
        uint32_t vt2 = mesh->triangles.node[3*t1+k];
        if (vt2 != v0 && vt2 != v1) ov1 = vt2;
      }

      if (bin[v0] == bin[v1] && (bin[ov0] == bin[v0] || bin[ov1] == bin[v0])){
        split[j] = 1;
      }
    }

    // Choose the longest edge 
    double distMax = -1;
    uint32_t indexEdge = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      if (split[j] == 0) continue;
      uint32_t ce = edges->tri2edg[3*i+j];
      double dist = distance(&mesh->vertices.coord[4*edges->node[2*ce+0]],&mesh->vertices.coord[4*edges->node[2*ce+1]]);
      if (dist > distMax){
        distMax = dist;
        indexEdge = ce;
      }
    }

    if (indexEdge == UINT32_MAX) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,indexEdge,&newEdge));

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.color[i];
    if (omesh->triangles.color[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else{
      // Search all triangles 
      // TODO search with distance to triangle to find the true parent  
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.color[j] == color) p2t[v0] = j;
      }
    }


    if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
    if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;

  }


  // Check for remaining topologically invalid triangle (3 indices same)
  for (uint32_t i=0; i<mesh->triangles.num;i++){

    uint32_t *v = mesh->triangles.node + 3*i;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]] && bin[v[0]] == bin[v[2]]){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
  }


  //==================================================================================
  // Create vertex 2 vertex connectivity of opposites  
  //==================================================================================

  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2vN;
  HXT_CHECK(hxtMalloc(&v2vN,mesh->vertices.num*sizeof(uint32_t)*5));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2vN[i] = UINT32_MAX;

  HXT_CHECK(hxtPointGenQuadBuildV2V(edges,bin,v2vN));

  //==================================================================================
  // Smoothing
  //==================================================================================
  
  HXT_CHECK(hxtPointGenQuadSmoothing(omesh,mesh,dataTri,isBoundary,p2t,v2vN,10));

  HXT_CHECK(hxtFree(&flagEdg));
  HXT_CHECK(hxtFree(&v2v));
  HXT_CHECK(hxtFree(&v2vN));
  HXT_CHECK(hxtFree(&adj));
  return HXT_STATUS_OK;
}






//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION to remove invalid quads (vertices with only two quad neighbours) 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadRemoveInvalidQuads(HXTPointGenOptions *opt,
                                            HXTMesh *mesh,
                                            HXTEdges *edges,
                                            uint64_t *p2t,
                                            uint32_t *bin,
                                            uint32_t *isBoundary)
{
  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"--- Removing interior vertices contained in only two (invalid) quads");
  HXT_INFO_COND(opt->verbosity>=1,"");

  typedef struct vert{
    double v[3];
    uint64_t p2t;
    uint32_t bin;
    uint32_t newInd;
  }Vert;

  // Filling structure of vertices
  Vert *vInfo;
  HXT_CHECK(hxtMalloc(&vInfo,sizeof(Vert)*mesh->vertices.num));
  
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    vInfo[i].v[0] = mesh->vertices.coord[4*i+0];
    vInfo[i].v[1] = mesh->vertices.coord[4*i+1];
    vInfo[i].v[2] = mesh->vertices.coord[4*i+2];
    vInfo[i].p2t = p2t[i];
    vInfo[i].bin = bin[i];
    vInfo[i].newInd = i;
  }


  // Create v2v array 
  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*5));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;
  HXT_CHECK(hxtPointGenQuadBuildV2V(edges,bin,v2v));

  // Count adjacent opposite indexed points for each one 
  uint32_t *adj;
  HXT_CHECK(hxtMalloc(&adj,mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) adj[i] = 0;

  for (uint32_t i=0; i<mesh->vertices.num;i++){
    int count = 0;
    for (uint32_t j=0; j<5; j++){
      if (v2v[5*i+j] != UINT32_MAX) count++;
    }
    adj[i] = count;
    if (adj[i] < 2 && isBoundary[i] != 1) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"One quad only for vertex %d",i); 
  }


  // Find and delete invalid quads
  uint64_t countDeletedTriangles = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (bin[v0] != bin[v1]) continue;

    if ( (adj[v0] == 2 && isBoundary[v0] != 1) ||
         (adj[v1] == 2 && isBoundary[v1] != 1) ){

        mesh->triangles.color[t0] = UINT16_MAX;
        mesh->triangles.color[t1] = UINT16_MAX;

        if (adj[v0]==2 && isBoundary[v0]!=1){
          adj[v0]=UINT32_MAX;
          vInfo[v0].newInd = v1;
        }
        if (adj[v1]==2 && isBoundary[v1]!=1){
          adj[v1]=UINT32_MAX;
          vInfo[v1].newInd = v0;
        }
        countDeletedTriangles+=2;
    }
  }

  HXT_INFO_COND(opt->verbosity>=1,"    Deleting %lu triangles", countDeletedTriangles);

  uint64_t count=0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.color[i] == UINT16_MAX) count++;
  }
  
  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtMeshWriteGmsh(mesh,"splitted8.msh");
    FILE *test;
    hxtPosInit("splitQuad8.pos","edges",&test);

    hxtPosNewView(test,"triangles");
    for (uint64_t i=0; i<mesh->triangles.num; i++){
      uint32_t *v = mesh->triangles.node + 3*i;
  
      if (mesh->triangles.color[i] == UINT16_MAX){
        hxtPosAddTriangle(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],&mesh->vertices.coord[4*v[2]],0);
      }

    }
    hxtPosNewView(test,"bin");
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],bin[i]);
    }
    hxtPosFinish(test);
  }


  // New index of vertices on triangles
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    v[0] = vInfo[v[0]].newInd;
    v[1] = vInfo[v[1]].newInd;
    v[2] = vInfo[v[2]].newInd;
  }




  //*************************************************************
  // Triangles
  //*************************************************************
  uint32_t *tris;
  uint16_t *col;
  HXT_CHECK(hxtAlignedMalloc(&tris,(3*mesh->triangles.size)*sizeof(uint32_t)));
  HXT_CHECK(hxtAlignedMalloc(&col,(mesh->triangles.size)*sizeof(uint16_t)));
  uint64_t cT = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.color[i] == UINT16_MAX) continue;
    tris[3*cT+0] = mesh->triangles.node[3*i+0];
    tris[3*cT+1] = mesh->triangles.node[3*i+1];
    tris[3*cT+2] = mesh->triangles.node[3*i+2];
    col[cT] = mesh->triangles.color[i];
    cT++;
  }

  for (uint64_t i=0; i<cT; i++){
    mesh->triangles.node[3*i+0] = tris[3*i+0];
    mesh->triangles.node[3*i+1] = tris[3*i+1];
    mesh->triangles.node[3*i+2] = tris[3*i+2];
    mesh->triangles.color[i] = col[i];
  }
  mesh->triangles.num = mesh->triangles.num - countDeletedTriangles;
  HXT_CHECK(hxtAlignedFree(&tris));
  HXT_CHECK(hxtAlignedFree(&col));


  // New vertices
  uint32_t countVertices = 0;
  for (uint32_t i=0; i<mesh->vertices.num; i++){
    if (adj[i] == UINT32_MAX) continue;

    mesh->vertices.coord[4*countVertices+0] = vInfo[i].v[0];
    mesh->vertices.coord[4*countVertices+1] = vInfo[i].v[1];
    mesh->vertices.coord[4*countVertices+2] = vInfo[i].v[2];
    bin[countVertices] = vInfo[i].bin;
    p2t[countVertices] = vInfo[i].p2t;
    vInfo[i].newInd = countVertices;

    countVertices++;

  }

  mesh->vertices.num = countVertices;


  // Relabel triangle vertices
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    v[0] = vInfo[v[0]].newInd;
    v[1] = vInfo[v[1]].newInd;
    v[2] = vInfo[v[2]].newInd;
  }


  // Relabel lines vertices
  for (uint64_t i=0; i<mesh->lines.num; i++){
    uint32_t *v = mesh->lines.node + 2*i;
    v[0] = vInfo[v[0]].newInd;
    v[1] = vInfo[v[1]].newInd;
  }

  // Relabel points vertices
  for (uint64_t i=0; i<mesh->points.num; i++){
    mesh->points.node[i] = vInfo[mesh->points.node[i]].newInd;
  }


  HXT_CHECK(hxtFree(&vInfo));
  HXT_CHECK(hxtFree(&v2v));
  HXT_CHECK(hxtFree(&adj));
  return HXT_STATUS_OK;
}

//**********************************************************************************************************
//**********************************************************************************************************
//
// FUNCTION to remove degenerate quads on the boundary
//
// After smoothing 'flat' triangles on the boundary can remain since we cannot move 
// the boundary vertices
// 
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadRemoveBadBoundary(HXTPointGenOptions *opt,
                                           HXTMesh *omesh,
                                           HXTMesh *mesh,
                                           HXTEdges *edges,
                                           void *dataTri,
                                           uint32_t *isBoundary,
                                           uint64_t *p2t,
                                           uint32_t *bin)
{

  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"--- Removing flat quads on the boundary by pushing singularity to interior");
  HXT_INFO_COND(opt->verbosity>=1,"");

  //============================================================
  // Flag edges to be splitted
  //============================================================
  uint16_t *flagEdg;
  HXT_CHECK(hxtMalloc(&flagEdg,2*edges->numEdges*sizeof(uint16_t)));
  for (uint64_t i=0; i<2*edges->numEdges; i++) flagEdg[i] = UINT16_MAX;

  for (uint32_t i=0; i<edges->numEdges; i++){

    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    if (bin[v0] != bin[v1]) continue;
    if (isBoundary[v0] != 1 && isBoundary[v1] != 1) continue;

    uint32_t ov0 = UINT32_MAX;
    uint32_t ov1 = UINT32_MAX;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];
  
    for (uint32_t k=0; k<3; k++){
      uint32_t vt1 = mesh->triangles.node[3*t0+k];
      if (vt1 != v0 && vt1 != v1) ov0 = vt1;
      uint32_t vt2 = mesh->triangles.node[3*t1+k];
      if (vt2 != v0 && vt2 != v1) ov1 = vt2;
    }

    double *p0 = mesh->vertices.coord + 4 * v0;
    double *p1 = mesh->vertices.coord + 4 *ov0;
    double *p2 = mesh->vertices.coord + 4 * v1;
    double *p3 = mesh->vertices.coord + 4 *ov1;

    double const a0 = 180 * hxtAngle3Vertices(p3,p0,p1) / M_PI;
    double const a1 = 180 * hxtAngle3Vertices(p3,p2,p1) / M_PI;

    //TODO correct way to do it is to choose the edge that 
    //are not boundary edges (lines) 
    //ENSURE THAT WE CAN CORRECTLY BUILD EDGES2LINES
    double lim = 170;
    if (isBoundary[v0] == 1 && a0>lim){
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.color[tt0] != mesh->triangles.color[tt1]) continue;

        flagEdg[edges->tri2edg[3*t0+j]] = bin[v0];
      }
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.color[tt0] != mesh->triangles.color[tt1]) continue;

        flagEdg[edges->tri2edg[3*t1+j]] = bin[v0];
      }
    }
    else if(isBoundary[v1] == 1 && a1 > lim){
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t0+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.color[tt0] != mesh->triangles.color[tt1]) continue;

        flagEdg[edges->tri2edg[3*t0+j]] = bin[v1];
      }
      for (uint32_t j=0; j<3; j++){

        uint64_t tt0 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+0];
        uint64_t tt1 = edges->edg2tri[2*edges->tri2edg[3*t1+j]+1];

        if (tt1 == UINT64_MAX) continue;
        if (mesh->triangles.color[tt0] != mesh->triangles.color[tt1]) continue;

        flagEdg[edges->tri2edg[3*t1+j]] = bin[v1];
      }
    }
  }


  uint32_t count = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){
    if (flagEdg[i] == 1) count++;
  }
  HXT_INFO_COND(opt->verbosity>=1,"    A. Splitting %d edges", count);

  //Realloc
  HXT_CHECK(hxtVerticesReserve(mesh,mesh->vertices.size+count));
  HXT_CHECK(hxtTrianglesReserve(mesh,mesh->triangles.size+count*4));



  // Print out edges to be splitted
  // TODO delete
  if(opt->verbosity>=2){
    FILE *test;
    hxtPosInit("splitQuad4_.pos","edges",&test);
    for (uint32_t i=0; i<edges->numEdges; i++){

      if (flagEdg[i] == 1){

        uint32_t *v = edges->node + 2*i;
        hxtPosAddLine(test,&mesh->vertices.coord[4*v[0]],&mesh->vertices.coord[4*v[1]],0);
      }
    }
    hxtPosFinish(test);
  }

  //============================================================
  // Split the edges the were flagged
  //============================================================
  for (uint32_t i=0; i<edges->numEdges; i++){

    if (flagEdg[i] == UINT16_MAX) continue;

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    uint32_t ov0 = edges->node[2*i+0];
    uint32_t ov1 = edges->node[2*i+1];

    if (t1 == UINT64_MAX) continue;
    if (mesh->triangles.color[t0] != mesh->triangles.color[t1]) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,i,&newEdge));

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.color[t0];
    if (omesh->triangles.color[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else{
      // Search all triangles 
      // TODO search with distance to triangle to find the true parent  
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.color[j] == color) p2t[v0] = j;
      }
    }

    if (bin[ov0] == bin[ov1]){
      bin[v0] = bin[ov0] == 1 ? 0: 1;
    }
    else{
      bin[v0] = flagEdg[i];
    }
  }


 
  uint16_t *flagTris;
  HXT_CHECK(hxtMalloc(&flagTris,3*mesh->triangles.num*sizeof(uint16_t)));
  for (uint64_t i=0; i<3*mesh->triangles.num; i++) flagTris[i] = UINT16_MAX;

  uint64_t countRemaining = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
      flagTris[i] = 1;
      countRemaining++;
    }
  }
  HXT_INFO_COND(opt->verbosity>=1,"    B. %lu topologically invalid triangles remaining",countRemaining);

  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){

    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted5.msh","splitQuad5.pos");
  }


  //==================================================================================
  // Split the rest of the triangles (split longest edge) 
  //==================================================================================
  for (uint64_t i=0; i<mesh->triangles.num; i++){

    uint32_t *v = mesh->triangles.node + 3*i;
    int fl = 0;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]) fl = 1;
    if (fl != 1) continue;

    uint32_t split[3] = {0,0,0};
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];

      uint32_t v0 = edges->node[2*ce+0];
      uint32_t v1 = edges->node[2*ce+1];
      
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      if (t1 == UINT64_MAX) continue;
      if (mesh->triangles.color[t0] != mesh->triangles.color[t1]) continue;

      //uint64_t ot = t0 == i ? t1:t0;
      //if (flagTris[ot] == 0) continue;

      uint32_t ov0 = UINT32_MAX;
      uint32_t ov1 = UINT32_MAX;

      for (uint32_t k=0; k<3; k++){
        uint32_t vt1 = mesh->triangles.node[3*t0+k];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
        uint32_t vt2 = mesh->triangles.node[3*t1+k];
        if (vt2 != v0 && vt2 != v1) ov1 = vt2;
      }

      if (bin[v0] == bin[v1] && (bin[ov0] == bin[v0] || bin[ov1] == bin[v0])){
        split[j] = 1;
      }
    }

    // Choose the longest edge 
    double distMax = -1;
    uint32_t indexEdge = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      if (split[j] == 0) continue;
      uint32_t ce = edges->tri2edg[3*i+j];
      double dist = distance(&mesh->vertices.coord[4*edges->node[2*ce+0]],&mesh->vertices.coord[4*edges->node[2*ce+1]]);
      if (dist > distMax){
        distMax = dist;
        indexEdge = ce;
      }
    }

    if (indexEdge == UINT32_MAX) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,indexEdge,&newEdge));

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.color[i];
    if (omesh->triangles.color[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else{
      // Search all triangles 
      // TODO search with distance to triangle to find the true parent  
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.color[j] == color) p2t[v0] = j;
      }
    }


    if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
    if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;

    flagTris[i] = 0;
  }

  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted6.msh","splitQuad6.pos");
  }

  // Check for remaining topologically invalid triangle (3 indices same)
  for (uint32_t i=0; i<mesh->triangles.num;i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]] && bin[v[0]] == bin[v[2]]){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
  }


  //==================================================================================
  // Create vertex 2 vertex connectivity of opposites  
  //==================================================================================

  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*5));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;

  HXT_CHECK(hxtPointGenQuadBuildV2V(edges,bin,v2v));


  //==================================================================================
  // Smoothing 
  //==================================================================================
  
  HXT_CHECK(hxtPointGenQuadSmoothing(omesh,mesh,dataTri,isBoundary,p2t,v2v,1));
  
  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted7.msh","splitQuad7.pos");
  }




  HXT_CHECK(hxtFree(&flagTris));
  HXT_CHECK(hxtFree(&flagEdg));
  HXT_CHECK(hxtFree(&v2v));

  return HXT_STATUS_OK;
}



//**********************************************************************************************************
//**********************************************************************************************************
//
// Create final quad mesh 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadFinal(HXTMesh *mesh,
                               HXTEdges *edges,
                               uint32_t *isBoundary,
                               uint32_t *v2v,
                               uint32_t *bin,
                               HXTMesh *qmesh)
{
  HXT_UNUSED(isBoundary);
  HXT_UNUSED(v2v);

  HXT_CHECK(hxtVerticesReserve(qmesh, mesh->vertices.num));
  qmesh->vertices.num = mesh->vertices.num;
  qmesh->quads.num = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    if (bin[v0] == bin[v1]) qmesh->quads.num++;
  }
  HXT_CHECK(hxtQuadsReserve(qmesh,qmesh->quads.num));

  for (uint32_t i=0; i<mesh->vertices.num; i++){
    qmesh->vertices.coord[4*i+0] = mesh->vertices.coord[4*i+0];
    qmesh->vertices.coord[4*i+1] = mesh->vertices.coord[4*i+1];
    qmesh->vertices.coord[4*i+2] = mesh->vertices.coord[4*i+2];
  }

  // Insert quads
  uint64_t cq = 0;
  for (uint32_t i=0; i<edges->numEdges; i++){

    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];
    if (bin[v0] != bin[v1]) continue;


    uint32_t ov0 = UINT32_MAX;
    uint32_t ov1 = UINT32_MAX;
    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];
  
    for (uint32_t k=0; k<3; k++){
      uint32_t vt1 = mesh->triangles.node[3*t0+k];
      if (vt1 != v0 && vt1 != v1) ov0 = vt1;
      uint32_t vt2 = mesh->triangles.node[3*t1+k];
      if (vt2 != v0 && vt2 != v1) ov1 = vt2;
    }

    if (mesh->triangles.color[t0] == UINT16_MAX ||
        mesh->triangles.color[t1] == UINT16_MAX)
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Deleted triangle in final quad formation");

    qmesh->quads.node[4*cq+0] = v0;
    qmesh->quads.node[4*cq+1] = ov0;
    qmesh->quads.node[4*cq+2] = v1;
    qmesh->quads.node[4*cq+3] = ov1;
    qmesh->quads.color[cq] = mesh->triangles.color[t0];
    cq++;

  }

  // Transfer lines and points from mesh to qmesh
  HXT_CHECK(hxtLinesReserve(qmesh,mesh->lines.num));
  qmesh->lines.num = mesh->lines.num;
  HXT_CHECK(hxtPointsReserve(qmesh,mesh->points.num));
  qmesh->points.num = mesh->points.num;

  for (uint64_t i=0; i<mesh->lines.num; i++){
    qmesh->lines.node[2*i+0] = mesh->lines.node[2*i+0];
    qmesh->lines.node[2*i+1] = mesh->lines.node[2*i+1];
    qmesh->lines.color[i] = mesh->lines.color[i];
  }
  for (uint64_t i=0; i<mesh->points.num; i++){
    qmesh->points.node[i] = mesh->points.node[i];
  }



  return HXT_STATUS_OK;
}
 
//**********************************************************************************************************
//**********************************************************************************************************
//
// Create and smooth a quad mesh template 
// 
// Input:
// 
//  - omesh: initial mesh (used for projection)
//  - mesh:  final mesh to be transformed to quad mesh
//  - p2t:   parent triangle on initial mesh for every vertex of mesh
//  - bin:   binary indices 
//
//**********************************************************************************************************
//**********************************************************************************************************
HXTStatus hxtPointGenQuadConvert(HXTPointGenOptions *opt,
                                 HXTMesh *omesh,
                                 HXTMesh *mesh, 
                                 uint64_t *p2t,
                                 uint32_t *bin)
{

  HXT_INFO_COND(opt->verbosity>=1,"");
  HXT_INFO_COND(opt->verbosity>=1,"========= Generation of bipartite quad mesh  ==========");
  HXT_INFO_COND(opt->verbosity>=1,"");

  HXT_INFO_COND(opt->verbosity>=2,"");
  HXT_INFO_COND(opt->verbosity>=2,"--- List of output files");
  HXT_INFO_COND(opt->verbosity>=2,"");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted1.msh     - before (same as finalmeshTriangles.msh)");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted2.msh     - after splitting common edges (1st pass)");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted3.msh     - after splitting remaining isolated triangles");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted4.msh     - after smoothing");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted5.msh     - in RemoveBadBoundary, after removing flat boundary quads");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted6.msh     - in RemoveBadBoundary, after removing remaining invalid triangles");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted7.msh     - in RemoveBadBoundary, after smoothing in BadBoundary");
  HXT_INFO_COND(opt->verbosity>=2,"    splitted8.msh     - in RemoveInvalidQuads");
  HXT_INFO_COND(opt->verbosity>=2,"");


  // Create rtree with triangles of original mesh 
  double tol = 10e-16;
  void *dataTri;
  HXT_CHECK(hxtRTreeCreate64(&dataTri));
  for (uint64_t i=0; i<omesh->triangles.num; i++){
    double *p0 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+0];
    double *p1 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+1];
    double *p2 = omesh->vertices.coord + 4*omesh->triangles.node[3*i+2];
    HXT_CHECK(hxtAddTriangleInRTree64(p0,p1,p2,tol,i,dataTri));
  }

  //Realloc
  HXT_CHECK(hxtVerticesReserve(mesh,mesh->vertices.num));
  HXT_CHECK(hxtTrianglesReserve(mesh,mesh->triangles.num));


  // Create edges structure
  HXTEdges* edges;
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));


  //==================================================================================
  // Flag boundary vertices
  //==================================================================================
  uint32_t *isBoundary;
  HXT_CHECK(hxtMalloc(&isBoundary,2*mesh->vertices.num*sizeof(uint32_t)));
  for (uint32_t i=0; i<2*mesh->vertices.num; i++) isBoundary[i] = UINT32_MAX;

  for (uint32_t i=0; i<edges->numEdges; i++){
    uint32_t v0 = edges->node[2*i+0];
    uint32_t v1 = edges->node[2*i+1];

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (t0 == UINT64_MAX || t1 == UINT64_MAX){
      isBoundary[v0] = 1;
      isBoundary[v1] = 1;
      continue;
    }
    if (mesh->triangles.color[t0] != mesh->triangles.color[t1]){
      isBoundary[v0] = 1;
      isBoundary[v1] = 1;
      continue;
    }
  }

  for (uint64_t i=0; i<mesh->lines.num; i++){
    isBoundary[mesh->lines.node[2*i+0]] = 1;
    isBoundary[mesh->lines.node[2*i+1]] = 1;
  }


  //==================================================================================
  // Flag triangles to be splitted (3 same indices) 
  //==================================================================================
 
  uint16_t *flagTris;
  HXT_CHECK(hxtMalloc(&flagTris,3*mesh->triangles.num*sizeof(uint16_t)));
  for (uint64_t i=0; i<3*mesh->triangles.num; i++) flagTris[i] = UINT16_MAX;

  uint64_t countSplitTri=0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]]){
      flagTris[i] = 1;
      countSplitTri++;
    }
  }

  HXT_INFO_COND(opt->verbosity>=1,"    A. %lu topologically invalid triangles to be splitted",countSplitTri);

  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted1.msh","splitQuad1.pos");
  }


  //==================================================================================
  // Split edges with two flagged triangles 
  //==================================================================================
  for (uint32_t i=0; i<edges->numEdges; i++){

    uint64_t t0 = edges->edg2tri[2*i+0];
    uint64_t t1 = edges->edg2tri[2*i+1];

    if (t1 == UINT64_MAX) continue;
    if (mesh->triangles.color[t0] != mesh->triangles.color[t1]) continue;

    if (flagTris[t0] == 1 && flagTris[t1] == 1){

      uint32_t newEdge = UINT32_MAX;
      HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,i,&newEdge));

      flagTris[t0] = 0;
      flagTris[t1] = 0;
      flagTris[edges->edg2tri[2*newEdge+0]] = 0;
      flagTris[edges->edg2tri[2*newEdge+1]] = 0;

      uint32_t v0 = edges->node[2*newEdge+0];
      uint32_t v1 = edges->node[2*newEdge+1];

      uint32_t v2 = edges->node[2*i+0] == v0 ? edges->node[2*i+1] : edges->node[2*i+0];

      // Find parent triangle on initial mesh for new point
      p2t[v0] = UINT64_MAX;
      uint16_t color = mesh->triangles.color[t0];
      if (omesh->triangles.color[p2t[v1]] == color){
        p2t[v0] = p2t[v1];
      }
      else if(omesh->triangles.color[p2t[v2]]==color){
        p2t[v0] = p2t[v2];
      }
      else{
        // Search all triangles 
        // TODO search with distance to triangle to find the true parent  
        for (uint64_t j=0; j<omesh->triangles.num; j++){
          if (omesh->triangles.color[j] == color) p2t[v0] = j;
        }
      }

      if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
      if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;
    }
  }

  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted2.msh","splitQuad2.pos");
  }


  uint64_t countSplitTrisIsolated=0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (flagTris[i] == 1) countSplitTrisIsolated++;
  }
  HXT_INFO_COND(opt->verbosity>=1,"    B. %lu topologically invalid triangles after common edge pass",countSplitTrisIsolated);



  //==================================================================================
  // Split the rest of the triangles (split longest edge)
  //==================================================================================
  for (uint64_t i=0; i<mesh->triangles.num; i++){

    if (flagTris[i] != 1) continue;

    uint32_t split[3] = {0,0,0};
    for (uint32_t j=0; j<3; j++){
      uint32_t ce = edges->tri2edg[3*i+j];

      uint32_t v0 = edges->node[2*ce+0];
      uint32_t v1 = edges->node[2*ce+1];
      
      uint64_t t0 = edges->edg2tri[2*ce+0];
      uint64_t t1 = edges->edg2tri[2*ce+1];
      if (t1 == UINT64_MAX) continue;
      if (mesh->triangles.color[t0] != mesh->triangles.color[t1]) continue;

      //uint64_t ot = t0 == i ? t1:t0;
      //if (flagTris[ot] == 0) continue;

      uint32_t ov0 = UINT32_MAX;
      uint32_t ov1 = UINT32_MAX;

      for (uint32_t k=0; k<3; k++){
        uint32_t vt1 = mesh->triangles.node[3*t0+k];
        if (vt1 != v0 && vt1 != v1) ov0 = vt1;
        uint32_t vt2 = mesh->triangles.node[3*t1+k];
        if (vt2 != v0 && vt2 != v1) ov1 = vt2;
      }

      if (bin[v0] == bin[v1] && (bin[ov0] == bin[v0] || bin[ov1] == bin[v0])){
        split[j] = 1;
      }
    }

    // Choose the longest edge 
    double distMax = -1;
    uint32_t indexEdge = UINT32_MAX;
    for (uint32_t j=0; j<3; j++){
      if (split[j] == 0) continue;
      uint32_t ce = edges->tri2edg[3*i+j];
      double dist = distance(&mesh->vertices.coord[4*edges->node[2*ce+0]],
                             &mesh->vertices.coord[4*edges->node[2*ce+1]]);
      if (dist > distMax){
        distMax = dist;
        indexEdge = ce;
      }
    }

    if (indexEdge == UINT32_MAX) continue;

    uint32_t newEdge = UINT32_MAX;
    HXT_CHECK(hxtSplitEdgeIndex(mesh,edges,NULL,NULL,indexEdge,&newEdge));

    flagTris[i] = 0;

    uint32_t v0 = edges->node[2*newEdge+0];
    uint32_t v1 = edges->node[2*newEdge+1];

    uint32_t v2 = edges->node[2*i+0] == v0 ? edges->node[2*i+1] : edges->node[2*i+0];

    // Find parent triangle on initial mesh for new point
    p2t[v0] = UINT64_MAX;
    uint16_t color = mesh->triangles.color[i];
    if (omesh->triangles.color[p2t[v1]] == color){
      p2t[v0] = p2t[v1];
    }
    else if(omesh->triangles.color[p2t[v2]]==color){
      p2t[v0] = p2t[v2];
    }
    else{
      // Search all triangles 
      // TODO search with distance to triangle to find the true parent  
      for (uint64_t j=0; j<omesh->triangles.num; j++){
        if (omesh->triangles.color[j] == color) p2t[v0] = j;
      }
    }


    if (bin[v0] == UINT32_MAX) bin[v0] = bin[v1]==1?0:1;
    if (bin[v1] == UINT32_MAX) bin[v1] = bin[v0]==1?0:1;

  }


  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted3.msh","splitQuad3.pos");
  }


  // Check for remaining topologically invalid triangle (3 indices same)
  for (uint32_t i=0; i<mesh->triangles.num;i++){
    uint32_t *v = mesh->triangles.node + 3*i;
    if (flagTris[i] == 1){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
    if (bin[v[0]] == bin[v[1]] && bin[v[1]] == bin[v[2]] && bin[v[0]] == bin[v[2]]){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Remaining triangle with same indices !!! ");
    }
  }

  //==================================================================================
  // Create vertex 2 vertex connectivity of opposites  
  //==================================================================================

  // Supposing maximum valence of 5 !!! TODO  
  uint32_t *v2v;
  HXT_CHECK(hxtMalloc(&v2v,mesh->vertices.num*sizeof(uint32_t)*5));
  for (uint32_t i=0; i<5*mesh->vertices.num; i++) v2v[i] = UINT32_MAX;

  HXT_CHECK(hxtPointGenQuadBuildV2V(edges,bin,v2v));


  //==================================================================================
  // Smoothing 
  //==================================================================================
  
  HXT_CHECK(hxtPointGenQuadSmoothing(omesh,mesh,dataTri,isBoundary,p2t,v2v,1));


  // Printing out 
  // TODO delete
  if(opt->verbosity>=2){
    hxtPointGenQuadPrintInfo(mesh,bin,flagTris,"splitted4.msh","splitQuad4.pos");
  }

  //==================================================================================
  // Remove remaining bad triangles on the boundary
  //==================================================================================
  
  HXT_CHECK(hxtPointGenQuadRemoveBadBoundary(opt,omesh,mesh,edges,dataTri,isBoundary,p2t,bin));


  //==================================================================================
  // Remove invalid quads and diamonds TODO 
  //==================================================================================
  
  //HXT_CHECK(hxtPointGenQuadRemoveInvalidQuadsRobust(opt,omesh,mesh,edges,dataTri,isBoundary,p2t,bin));
  HXT_CHECK(hxtPointGenQuadRemoveInvalidQuads(opt,mesh,edges,p2t,bin,isBoundary));

  if(opt->verbosity>=2) HXT_CHECK(hxtMeshWriteGmsh(mesh,"finalmeshInvalidQuads.msh"));

  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtEdgesCreateNonManifold(mesh,&edges));




  //==================================================================================
  // Create final quad mesh
  //==================================================================================
  HXTMesh *qmesh;
  hxtMeshCreate(&qmesh);
  
  HXT_CHECK(hxtPointGenQuadFinal(mesh,edges,isBoundary,v2v,bin,qmesh));

  if(opt->verbosity>=2){
    FILE *test;
    hxtPosInit("binFinal.pos","points",&test);
    for (uint32_t i=0; i<mesh->vertices.num;i++){
      hxtPosAddPoint(test,&mesh->vertices.coord[4*i],bin[i]);
    }
    hxtPosFinish(test);
  }

  if(opt->verbosity>=2){
    FILE *test;
    hxtPosInit("binFinalPerfectMatching.pos","points",&test);
    for (uint32_t i=0; i<edges->numEdges; i++){
      uint32_t v0 = edges->node[2*i+0];
      uint32_t v1 = edges->node[2*i+1];
      if (bin[v0] != bin[v1]) continue;

      hxtPosAddLine(test,&mesh->vertices.coord[4*v0],&mesh->vertices.coord[4*v1],0);
    }


    hxtPosFinish(test);
  }



  //==================================================================================
  // Rewrite qmesh into nmesh
  //==================================================================================
  {
    HXT_CHECK(hxtMeshClear(&mesh));
    HXT_CHECK(hxtVerticesReserve(mesh, qmesh->vertices.num));
    mesh->vertices.num = qmesh->vertices.num;
    for (uint32_t i=0; i<mesh->vertices.num; i++){
      mesh->vertices.coord[4*i+0] = qmesh->vertices.coord[4*i+0];
      mesh->vertices.coord[4*i+1] = qmesh->vertices.coord[4*i+1];
      mesh->vertices.coord[4*i+2] = qmesh->vertices.coord[4*i+2];
    }
    HXT_CHECK(hxtQuadsReserve(mesh,qmesh->quads.num));
    mesh->quads.num = qmesh->quads.num;
    for (uint64_t i=0; i<qmesh->quads.num; i++){
      mesh->quads.node[4*i+0] = qmesh->quads.node[4*i+0]; 
      mesh->quads.node[4*i+1] = qmesh->quads.node[4*i+1]; 
      mesh->quads.node[4*i+2] = qmesh->quads.node[4*i+2]; 
      mesh->quads.node[4*i+3] = qmesh->quads.node[4*i+3]; 
      mesh->quads.color[i] = qmesh->quads.color[i];
    }
    HXT_CHECK(hxtLinesReserve(mesh,qmesh->lines.num));
    mesh->lines.num = qmesh->lines.num;
    for (uint64_t i=0; i<qmesh->lines.num; i++){
      mesh->lines.node[2*i+0] = qmesh->lines.node[2*i+0]; 
      mesh->lines.node[2*i+1] = qmesh->lines.node[2*i+1]; 
      mesh->lines.color[i] = qmesh->lines.color[i];
    }
    HXT_CHECK(hxtPointsReserve(mesh,qmesh->points.num));
    mesh->points.num = qmesh->points.num;
    for (uint64_t i=0; i<qmesh->points.num; i++){
      mesh->points.node[i] = qmesh->points.node[i]; 
    }
  }


  //==================================================================================
  // Output quality and bad vertices
  //==================================================================================
  if(opt->verbosity>=1){
    FILE *q;
    hxtPosInit("quadQuality.pos","scaledJacobian",&q);
    FILE *out = fopen("quadHistogram.txt","w");

    for (uint64_t i=0; i<mesh->quads.num; i++){
      double *p0 = mesh->vertices.coord + 4*mesh->quads.node[4*i+0];
      double *p1 = mesh->vertices.coord + 4*mesh->quads.node[4*i+1];
      double *p2 = mesh->vertices.coord + 4*mesh->quads.node[4*i+2];
      double *p3 = mesh->vertices.coord + 4*mesh->quads.node[4*i+3];
      double qual = hxtPointGenQuadScaledJacobian(p0,p1,p2,p3);
      hxtPosAddQuad(q,p0,p1,p2,p3,qual);
      fprintf(out,"%f\n",qual);
    }
    fclose(out);
    hxtPosFinish(q);
  }

  if(opt->verbosity>=1){

    int countInvalid = 0;
    double total = 0.0;
    double min = 1;
    double max = -1;
    FILE *q;
    hxtPosInit("quadQualityINVALID.pos","scaledJacobian",&q);
    for (uint64_t i=0; i<mesh->quads.num; i++){
      double *p0 = mesh->vertices.coord + 4*mesh->quads.node[4*i+0];
      double *p1 = mesh->vertices.coord + 4*mesh->quads.node[4*i+1];
      double *p2 = mesh->vertices.coord + 4*mesh->quads.node[4*i+2];
      double *p3 = mesh->vertices.coord + 4*mesh->quads.node[4*i+3];
      double qual = hxtPointGenQuadScaledJacobian(p0,p1,p2,p3);
      total+= qual;
      if(qual>max) max=qual;
      if(qual<min) min = qual;
      if (qual<=0.0){
        hxtPosAddQuad(q,p0,p1,p2,p3,qual);
        countInvalid++;
      }
    }
    hxtPosFinish(q);
    
    double avg = total/(float)mesh->quads.num;


    HXT_INFO_COND(opt->verbosity>=1,"    %d quads with negative quality", countInvalid);
    HXT_INFO_COND(opt->verbosity>=1,"");
    if(opt->quadSurfaces) 
      HXT_INFO_COND(opt->verbosity>=0, "PointGen | Quad quality min/avg/max: %f, %f, %f", min,avg,max);
    HXT_INFO_COND(opt->verbosity>=1,"");
  }



  //==================================================================================
  // Output singular vertices
  //==================================================================================
  HXT_CHECK(hxtSurfaceQuadSingularitiesOutput(opt,mesh));

  if(opt->verbosity>=2) HXT_CHECK(hxtMeshWriteGmsh(qmesh,"quads.msh"));
  HXT_CHECK(hxtMeshDelete(&qmesh));


  //==================================================================================
  // Clear things 
  //==================================================================================

  HXT_CHECK(hxtRTreeDelete(&dataTri));

  HXT_CHECK(hxtFree(&flagTris));
  HXT_CHECK(hxtEdgesDelete(&edges));
  HXT_CHECK(hxtFree(&v2v));
  HXT_CHECK(hxtFree(&isBoundary));

  return HXT_STATUS_OK; 
}
 
