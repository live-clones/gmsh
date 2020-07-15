#include <math.h>
#include <time.h>
#include "hxt_point_gen_2d.h"
#include "hxt_rtree_wrapper.h"
#include "hxt_pqueue_wrapper.h"

#include "hxt_point_gen_io.h"
#include "hxt_point_gen_orientation.h"
#include "hxt_orientation3d_tools.h"

#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"

//FILE *out; // output pointsClean
//FILE *fil; // output pointsFiltered

static double sign(double a){
  return a>=0 ? 1.:-1;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to estimate the number of points to be generated for a colored surface 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtEstimateNumOfVerticesForColoredSurface(HXTMesh *mesh,
                                                    uint16_t color,
                                                    const double *sizemap,
                                                    uint32_t *estNumVert)
{

  // Count the number of triangles of this color
  uint64_t countColorTriangles=0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] == color) countColorTriangles++;
  }

  // Store triangles barycenters and sizes
  double *colorCoords;
  HXT_CHECK(hxtMalloc(&colorCoords,countColorTriangles*4*sizeof(double)));
  double *colorSizes;
  HXT_CHECK(hxtMalloc(&colorSizes,countColorTriangles*sizeof(double)));

  uint64_t counter = 0;
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    if (mesh->triangles.colors[i] != color) continue;
    double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    colorCoords[4*counter+0] = 1./3.*v0[0]+1./3.*v1[0]+1./3.*v2[0];
    colorCoords[4*counter+1] = 1./3.*v0[1]+1./3.*v1[1]+1./3.*v2[1];
    colorCoords[4*counter+2] = 1./3.*v0[2]+1./3.*v1[2]+1./3.*v2[2];
    colorSizes[counter] = 1./3.*sizemap[mesh->triangles.node[3*i+0]] +
                          1./3.*sizemap[mesh->triangles.node[3*i+1]] + 
                          1./3.*sizemap[mesh->triangles.node[3*i+2]] ; 
    counter++;
  }

  HXT_CHECK(hxtEstimateNumOfVerticesWithPoints(colorCoords,
                                               colorSizes,
                                               countColorTriangles,
                                               estNumVert));

  HXT_CHECK(hxtFree(&colorCoords));
  HXT_CHECK(hxtFree(&colorSizes));



  return HXT_STATUS_OK;
      
}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get all the points on lines for a colored surface  
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetLineVerticesForColor(HXTMesh *mesh, 
                                     uint64_t maxNumTriToLine,
                                     uint64_t *lines2triangles,
                                     HXTMesh *fmesh, 
                                     HXTPointGenParent *parent,
                                     uint16_t color, 
                                     uint32_t *numPoints,
                                     uint32_t *points,
                                     uint64_t *point2tri)
{
  uint32_t count = 0;

  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    if (parent[i].type == 15){
      uint32_t cp = parent[i].id;
      // TODO slow 
      for (uint64_t j=0; j<mesh->triangles.num; j++){
        if (mesh->triangles.colors[j] != color) continue;
        uint32_t *triV = mesh->triangles.node + 3*j;
        if (cp == triV[0] || cp == triV[1] || cp == triV[2]){
          points[count] = i;
          point2tri[count] = j;
          count++;
          break;
        }
      }
    }
    else if (parent[i].type == 1){
      uint64_t cl = parent[i].id;
      for (uint64_t j=0; j<maxNumTriToLine; j++){
        uint64_t ct = lines2triangles[maxNumTriToLine*cl+j];
        if (ct == UINT64_MAX) continue;
        if (mesh->triangles.colors[ct] == color){
          points[count] = i;
          point2tri[count] = ct;
          count++;
          break;
        }
      }
    }
    else if (parent[i].type == 2){
      if (mesh->triangles.colors[parent[i].id] == color){
        points[count] = i;
        point2tri[count] = parent[i].id;
        count++;
        continue;
      }
    }
  }

  *numPoints = count;
  return HXT_STATUS_OK; 
}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to intersect a circle with the triangulation and find a candidate point 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtIntersectTriangleWithCircle(HXTMesh *mesh,   
                                         double *p,   // origin point coordinates 
                                         uint64_t ct, // triangle to be searched
                                         double R,    // radius, i.e. mesh size at origin point
                                         double *n1,  // normal to triangle ct 
                                         double *n2,  // search direction
                                         double *uv,  // output: barycentric coordinates of new point 
                                         int *walk,   // ouput: -1 if found, otherwise next edge
                                         double *res) // output: coordinates of new point
{
  // Compute normal direction to the plane of the intersection circle 
  double n[3] = {0.};
  HXT_CHECK(myNormalizedCrossprod(n1,n2,n));

  double *v0 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+0];
  double *v1 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+1];
  double *v2 = mesh->vertices.coord + 4*mesh->triangles.node[3*ct+2];

  // Compute normal to the plane of current triangle ct 
  double t1[3] = {v1[0]-v0[0], v1[1]-v0[1], v1[2]-v0[2]};// first edge vector
  double t2[3] = {v2[0]-v0[0], v2[1]-v0[1], v2[2]-v0[2]};// reversed last edge vector
  double t[3] = {0.};
  HXT_CHECK(myNormalizedCrossprod(t1,t2,t));

  // Compute direction of intersection line of the two planes
  double d[3] = {0.};
  HXT_CHECK(myNormalizedCrossprod(n,t,d));
  if (norm(d) < 1.e-12){
    // The two planes are parallel
    //printf("norm(d) small - return \n");
    *walk = - 100;
    return HXT_STATUS_OK; //TODO return warning? 
  }

  // Find a point on the intersection line of the two planes
  //    n_x*x+n_y*y+n_z*z = dot(n,p)
  //    t_x*x+t_y*y+t_z*z = dot(v0,t)
  // by fixing one of the 3 variables 
  // and solving the corresponding 2x2 system 
  double rhs[2] = {myDot(n,p), myDot(v0,t)};
  double r[2];
  double m[2][2];
  double x0[3] = {0};
  m[0][0] = n[1];
  m[0][1] = n[2];
  m[1][0] = t[1];
  m[1][1] = t[2];      

  if (fabs(hxtGetDet2x2(m)) > 1.e-12){
    hxtGetSys2x2(m,rhs,r);
    x0[0] = 0; x0[1]=r[0]; x0[2]=r[1];
  }
  else {
    m[0][0] = n[0];
    m[0][1] = n[2];
    m[1][0] = t[0];
    m[1][1] = t[2];      
    if (fabs(hxtGetDet2x2(m)) > 1.e-12){
      hxtGetSys2x2(m,rhs,r); 
      x0[0] = r[0]; x0[1]=0; x0[2]=r[1];
    }
    else {
      m[0][0] = n[0];
      m[0][1] = n[1];
      m[1][0] = t[0];
      m[1][1] = t[1];      
      if (hxtGetSys2x2(m,rhs,r)) {  
        x0[0] = r[0]; x0[1]=r[1]; x0[2]=0;
      }
      else{
        //printf("mauvaise pioche - return \n");
        *walk = -100;
        return HXT_STATUS_OK; //TODO  return warning?
      }
    }
  }    

  // The intersection line is now defined
  //    x = x0 + t*d
  // To find the intersection we compute the intersection 
  // of this line with the sphere defined 
  // from center point p with radius R (=size)
  const double a = 1.0;
  double temp[3] = {p[0]-x0[0],p[1]-x0[1],p[2]-x0[2]};
  const double b = -2*myDot(d,temp);
  const double c = myDot(temp,temp) - R*R;
  const double delta = b*b-4*a*c;
    
  // If a solution is found, we check whether the point 
  // is inside our current triangle ct and on the direction n2
  if (delta >= 0){
    double sign = (myDot(n2,d) > 0)? 1.0:-1.0;
    const double ta = (-b + sign*sqrt(delta)) / (2.*a);
    const double tb = (-b - sign*sqrt(delta)) / (2.*a);

    double s[2][3];
    s[0][0]=x0[0]+d[0]*ta; s[0][1]=x0[1]+d[1]*ta; s[0][2]=x0[2]+d[2]*ta;
    s[1][0]=x0[0]+d[0]*tb; s[1][1]=x0[1]+d[1]*tb; s[1][2]=x0[2]+d[2]*tb;
    
    for (int IT=0;IT<2;IT++){
      double mat[2][2], bb[2];
      mat[0][0] = myDot(t1,t1);
      mat[1][1] = myDot(t2,t2);
      mat[0][1] = mat[1][0] = myDot(t1,t2);
      double tmp[3] = {s[IT][0]-v0[0],s[IT][1]-v0[1],s[IT][2]-v0[2]};
      bb[0] = myDot(tmp,t1) ;
      bb[1] = myDot(tmp,t2) ;

      hxtGetSys2x2(mat,bb,uv);

      double vr[3] = {s[IT][0],s[IT][1],s[IT][2]};
      double dD[3] = {vr[0]-p[0],vr[1]-p[1],vr[2]-p[2]};
      normalize(dD);

      double uvlim = -1.e-12; //TODO 

      res[0] = s[IT][0];  res[1] = s[IT][1];  res[2] = s[IT][2];
      if (uv[0] >= uvlim && uv[1] >= uvlim && 1.-uv[0]-uv[1] >= uvlim && myDot(dD,n2) > 0.0) {
        *walk=-1;
        res[0] = s[IT][0];  res[1] = s[IT][1];  res[2] = s[IT][2];
        return HXT_STATUS_OK;
      }

      // If point is not on the triangle
      // return the side of the triangle to continue search 
      if(myDot(dD,n2)>0.0){
        if (uv[0] < 0 ){
          *walk=2;
        }else if (uv[1]<0){
          *walk=0;
        }else{
          *walk=1;
        }
      }
    }
  }
  else{
    *walk =-100;
    return HXT_STATUS_OK; 
  }

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get size for a point inside a triangle
//
//*************************************************************************************************
//*************************************************************************************************
double getSize(HXTMesh *mesh, const double *sizemap, double *uv, uint64_t ct, uint32_t ind){
  return (1.-uv[0]-uv[1])*sizemap[3*mesh->triangles.node[3*ct+0]+ind] + 
                   uv[0] *sizemap[3*mesh->triangles.node[3*ct+1]+ind] + 
                   uv[1] *sizemap[3*mesh->triangles.node[3*ct+2]+ind] ; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get 3 coherent size for a point inside a triangle
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetCoherentSizes(HXTMesh *mesh,
                              const double *directions,
                              const double *sizemap, 
                              uint64_t ct,
                              double *frame,
                              double *uv,
                              double *sizes)
{
  double triSizes[3*3]={0.,0.,0.,0.,0.,0.,0.,0.,0.};
  const uint32_t* nodes = &(mesh->triangles.node[3*ct]);
  /* Loop on the vertices */
  for (uint8_t lv = 0; lv < 3; ++lv) {
    /* Loop on the three branches of each vertex */
    for (uint8_t d = 0; d < 3; ++d) {
      double* ref = &frame[3*d];
      /* Loop on the 3 branches of the lv cross */
      double maxDot = 0;
      uint8_t cb = UINT8_MAX;
      for (uint8_t b = 0; b < 3; ++b) {
        double B[3];
        B[0] = directions[9*nodes[lv]+3*b+0];
        B[1] = directions[9*nodes[lv]+3*b+1];
        B[2] = directions[9*nodes[lv]+3*b+2];
        normalize(B);
        double cdot = myDot(ref, B);
        if (fabs(cdot) > fabs(maxDot)) {
          maxDot = cdot;
          cb = b;
        }
      }
      HXT_ASSERT(cb != UINT8_MAX);
      triSizes[3*lv+d] = sizemap[3*nodes[lv]+cb];
    }
  }

  sizes[0] = (1.-uv[0]-uv[1])*triSizes[0] + uv[0]*triSizes[3] + uv[1]*triSizes[6];
  sizes[1] = (1.-uv[0]-uv[1])*triSizes[1] + uv[0]*triSizes[4] + uv[1]*triSizes[7];
  sizes[4] = (1.-uv[0]-uv[1])*triSizes[2] + uv[0]*triSizes[5] + uv[1]*triSizes[8];

  sizes[2] = sizes[0];
  sizes[3] = sizes[1];
  sizes[5] = sizes[4];

  return HXT_STATUS_OK;
}



//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get valid 2d directions from 3d direction field 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetDirectionsScaled(HXTMesh *mesh, 
                                 const double *directions,
                                 const double *sizemap,
                                 uint64_t tri,
                                 double *normal,
                                 double *uv,
                                 double *vectors,
                                 double *sizes)
{
  // Check if vectors are 'smooth' 
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      double vec[3];
      vec[0] = directions[9*mesh->triangles.node[3*tri+i]+3*j+0];
      vec[1] = directions[9*mesh->triangles.node[3*tri+i]+3*j+1];
      vec[2] = directions[9*mesh->triangles.node[3*tri+i]+3*j+2];
      if (norm(vec) < 10e-12) return HXT_STATUS_OK;
    }
  }

  // Get coherent directions
  double triangleVectors[3][9];
  HXT_CHECK(hxtGetCoherentDirectionsInTri(mesh,directions,tri,triangleVectors));

  // Interpolate to current point
  double tempvector[9] = {0.};
  for (int i=0; i<9; i++){
    tempvector[i] = (1-uv[0]-uv[1])*triangleVectors[0][i] + 
                             uv[0] *triangleVectors[1][i] + 
                             uv[1] *triangleVectors[2][i] ; 
  }

  // Filter out normal to triangle direction
  uint32_t normalIndex = UINT32_MAX;
  double maxDot = 0.;
  for (int i=0; i<3; i++){
    double *vec = tempvector + 3*i;
    if (fabs(myDot(vec,normal))>=maxDot){
      maxDot = fabs(myDot(vec,normal));
      normalIndex = i;
    }
  }
  if (normalIndex == UINT32_MAX){
    printf("%f %f %f %f\n", normal[0], normal[1], normal[2], norm(normal));
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Did not find normal vector");
  }

  // Assemble array with direction vectors 
  // and equivalent sizes
  int count = 0;
  for (uint32_t i=0; i<3; i++){
    if (i != normalIndex){
      vectors[3*count+0] = tempvector[3*i+0];
      vectors[3*count+1] = tempvector[3*i+1];
      vectors[3*count+2] = tempvector[3*i+2];
      vectors[3*(count+2)+0] = -tempvector[3*i+0];
      vectors[3*(count+2)+1] = -tempvector[3*i+1];
      vectors[3*(count+2)+2] = -tempvector[3*i+2];
      count ++;
    }
    else{
      vectors[3*4+0] =  tempvector[3*i+0];
      vectors[3*4+1] =  tempvector[3*i+1];
      vectors[3*4+2] =  tempvector[3*i+2];
      vectors[3*5+0] = -tempvector[3*i+0];
      vectors[3*5+1] = -tempvector[3*i+1];
      vectors[3*5+2] = -tempvector[3*i+2];
    }
  }

  tempvector[0] = vectors[0];
  tempvector[1] = vectors[1];
  tempvector[2] = vectors[2];
  tempvector[3] = vectors[3];
  tempvector[4] = vectors[4];
  tempvector[5] = vectors[5];
  tempvector[6] = vectors[12];
  tempvector[7] = vectors[13];
  tempvector[8] = vectors[14];

  HXT_CHECK(hxtGetCoherentSizes(mesh,directions,sizemap,tri,tempvector,uv,sizes));

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get valid 2d directions from 3d direction field 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtInterpolateFrame(HXTMesh *mesh, 
                              const double *directions,
                              const double *sizemap,
                              uint64_t tri,
                              double *normal,
                              double *uv,
                              double *vectors,
                              double *sizes)
{
  // Check if vectors are 'smooth' 
  for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
      double vec[3];
      vec[0] = directions[9*mesh->triangles.node[3*tri+i]+3*j+0];
      vec[1] = directions[9*mesh->triangles.node[3*tri+i]+3*j+1];
      vec[2] = directions[9*mesh->triangles.node[3*tri+i]+3*j+2];
      if (norm(vec) < 10e-12) return HXT_STATUS_OK;
    }
  }

  // Assemble array with directions vectors for the triangle vertices
  // the fourth one is not taken into account 
  double triFrames[4*9];
  for (uint32_t i=0; i<4*9; i++) triFrames[i] = 1.;

  for (uint32_t i=0; i<3; i++){
    uint32_t v = mesh->triangles.node[3*tri+i];
    for (uint32_t j=0; j<9; j++){
      triFrames[9*i+j] = directions[9*v+j]; 
    }

    // Scale according to sizes 
    for (uint32_t j=0; j<3; j++){
      for (uint32_t k=0; k<3; k++){
        triFrames[9*i+3*j+k] = triFrames[9*i+3*j+k] * sizemap[3*v+j];
      }
    }
  }

  double uvt[3];  uvt[0] = uv[0];   uvt[1] = uv[1];   uvt[2] = 0; 

  double frame[9];
  for (uint32_t i=0; i<9; i++) frame[i] = 0.;

  int flagTrusted[3];
  double crossQuality;
  HXT_CHECK(hxtOr3DgetScaledCrossInTetFromDir(triFrames,uvt,frame,&crossQuality,flagTrusted));
  double sizesTemp[3];
  sizesTemp[0] = norm(&frame[0]);
  sizesTemp[1] = norm(&frame[3]);
  sizesTemp[2] = norm(&frame[6]);
  normalize(&frame[0]);
  normalize(&frame[3]);
  normalize(&frame[6]);

  // TODO PUT THIS ON DIFFERENT FUNCTION 
  // Filter out normal to triangle direction
  uint32_t normalIndex = UINT32_MAX;
  double maxDot = 0.;
  for (int i=0; i<3; i++){
    double *vec = frame + 3*i;
    if (fabs(myDot(vec,normal))>=maxDot){
      maxDot = fabs(myDot(vec,normal));
      normalIndex = i;
    }
  }
  if (normalIndex == UINT32_MAX) 
    return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Did not find normal vector");

  // Assemble array with direction vectors 
  // and equivalent sizes
  int count = 0;
  for (uint32_t i=0; i<3; i++){
    if (i != normalIndex){
      vectors[3*count+0] = frame[3*i+0];
      vectors[3*count+1] = frame[3*i+1];
      vectors[3*count+2] = frame[3*i+2];
      vectors[3*(count+2)+0] = -frame[3*i+0];
      vectors[3*(count+2)+1] = -frame[3*i+1];
      vectors[3*(count+2)+2] = -frame[3*i+2];
      sizes[count] = sizesTemp[i];
      count ++;
    }
    else{
      vectors[3*4+0] =  frame[3*i+0];
      vectors[3*4+1] =  frame[3*i+1];
      vectors[3*4+2] =  frame[3*i+2];
      vectors[3*5+0] = -frame[3*i+0];
      vectors[3*5+1] = -frame[3*i+1];
      vectors[3*5+2] = -frame[3*i+2];
      sizes[4] = sizesTemp[i];
      sizes[5] = sizesTemp[i];
    }
  }
  sizes[2] = sizes[0];
  sizes[3] = sizes[1];
 

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get valid 2d directions from 3d direction field 
// Two ways: - InterpolateFrame slow but a bit more accurate
//           - GetDirectionsScaled faster
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetDirections(HXTMesh *mesh, 
                           const double *directions,
                           const double *sizemap,
                           uint64_t tri,
                           double *normal,
                           double *uv,
                           double *frame,
                           double *sizes)
{
  
  HXT_CHECK(hxtGetDirectionsScaled(mesh,directions,sizemap,tri,normal,uv,frame,sizes));
  
  //HXT_CHECK(hxtInterpolateFrame(mesh,directions,sizemap,tri,normal,uv,frame,sizes));
  

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get the 'closest' direction to the input for a point
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetClosestDirection(HXTMesh *mesh, 
                                 const double *directions,
                                 const double *sizemap,
                                 uint64_t ct,
                                 double *normal,
                                 double *uv,
                                 double *inDir,
                                 double *outDir,
                                 double *outSize)
{

  // Get direction from 3d direction field
  double sizes[6] = {0.};
  double frame[6*3] = {0.,0.,0.};
  //HXT_CHECK(hxtGetDirectionsScaled(mesh,directions,sizemap,ct,normal,uv,frame,sizes));
  //HXT_CHECK(hxtInterpolateFrame(mesh,directions,sizemap,ct,normal,uv,frame,sizes));
  HXT_CHECK(hxtGetDirections(mesh,directions,sizemap,ct,normal,uv,frame,sizes));

  // Find the 'most parallel' direction
  double dirMax[3] = {0.,0.,0.};
  double maxDot = 0;
  for (int nb=0; nb<4; nb++){

    double dir[3] = {frame[3*nb+0],frame[3*nb+1],frame[3*nb+2]};

    if (fabs(myDot(dir,inDir))>maxDot){
      maxDot = fabs(myDot(dir,inDir));
      double s = sign(myDot(dir,inDir));
      dirMax[0] = s*dir[0];
      dirMax[1] = s*dir[1];
      dirMax[2] = s*dir[2];
      *outSize = sizes[nb];
    }
  } 
  outDir[0] = dirMax[0];
  outDir[1] = dirMax[1];
  outDir[2] = dirMax[2];

  return HXT_STATUS_OK;
}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find a candidate point by walking in a planar triangulation
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePointPlanarGiven(HXTEdges *edges, 
                                             uint64_t *edges2lines,
                                             double *op, //origin point
                                             uint64_t ot, // origin triangle 
                                             double *dir, // direction
                                             double *res, // output point
                                             uint64_t *parentFlag)
{

  HXTMesh *mesh = edges->edg2mesh;
      
  uint64_t ct = ot;
  int walkIter = 0;
  int maxWalk = 100; // TODO
  int walk = -100;
  *parentFlag = UINT64_MAX;

  double uvlim = -1.e-12; //TODO 

  while (walkIter < maxWalk){
    double uvp[2]={0.};
    HXT_CHECK(hxtGetBarycentric(edges->edg2mesh,ct,res,uvp));

    double dD[3] = {res[0]-op[0],res[1]-op[1],res[2]-op[2]};
    normalize(dD);

    if (uvp[0] >= uvlim && uvp[1] >= uvlim && 1.-uvp[0]-uvp[1] >= uvlim && myDot(dD,dir) > 0.0) {
      walk=-1;
    }
    else{
    // If point is not on the triangle
    // return the side of the triangle to continue search 
    if(myDot(dD,dir)>0.0){
      if (uvp[0] < 0 ){
        walk=2;
      }else if (uvp[1]<0){
        walk=0;
      }else{
        walk=1;
      }
    }
    }
    // Intersection point was found 
    if (walk == -1) {
      
      // Check if intersection point is very close to mesh line - added 19/03/2019
      for (uint32_t i=0; i<3; i++){
        uint32_t ce = edges->tri2edg[3*ct+i];
        if (edges2lines[ce] != UINT64_MAX){
          double *p0 = mesh->vertices.coord + 4*edges->node[2*ce+0];
          double *p1 = mesh->vertices.coord + 4*edges->node[2*ce+1];
          double dist = -1;
          double alpha = -1;
          double closePt[3] = {0,0,0};
          HXT_CHECK(hxtSignedDistancePointEdge(p0,p1,res,&dist,&alpha,closePt));
          if (dist<10e-6){ // TODO tolerance here !!!
            *parentFlag = UINT64_MAX ;
            res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
            return HXT_STATUS_OK; 
          }
        }
      }

      *parentFlag = ct;
      return HXT_STATUS_OK; 
    }

    // Intersection with circle failed
    // we cannot continue walking
    if (walk == -100){
      *parentFlag = UINT64_MAX ;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }

    // If we arrive to a mesh line break
    // we don't want to generate point on a different color
    if (edges2lines[edges->tri2edg[3*ct+walk]] != UINT64_MAX){
      *parentFlag = UINT64_MAX ;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }

    // Find next triangle to search 
    uint64_t neigh;
    hxtGetNeighbourTriangle(edges, ct, walk, &neigh);
    if (neigh == UINT64_MAX || mesh->triangles.colors[neigh] != mesh->triangles.colors[ot]){
      *parentFlag = UINT64_MAX;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }
    else{
      ct = neigh;
    }
    walkIter ++;
  }

  // Last resort - search all triangles
  
  /*for (uint64_t i=0; i<mesh->triangles.num; i++){*/
    /*if (mesh->triangles.colors[i] != mesh->triangles.colors[ot]) continue;*/

    /*HXT_CHECK(hxtIntersectTriangleWithCircle(mesh, op, i, size, normal, dir, uvp, &walk, res));*/

    /*// Intersection point was found */
    /*if (walk == -1) {*/
      /**parentFlag = i;*/
      /*return HXT_STATUS_OK; */
    /*}*/
  /*}*/

  return HXT_STATUS_OK; 
}




//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find a candidate point by walking in a planar triangulation
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePointPlanar(HXTEdges *edges, 
                                        uint64_t *edges2lines,
                                        double *op, //origin point
                                        uint64_t ot, // origin triangle 
                                        double *dir, // direction
                                        double size, // size
                                        double *res, // output point
                                        uint64_t *parentFlag)
{

  HXTMesh *mesh = edges->edg2mesh;
      
  uint64_t ct = ot;
  int walkIter = 0;
  int maxWalk = 100; // TODO
  int walk = -100;
  *parentFlag = UINT64_MAX;

  double uvlim = -1.e-12; //TODO 

  res[0] = op[0] + size*dir[0];
  res[1] = op[1] + size*dir[1];
  res[2] = op[2] + size*dir[2];

  while (walkIter < maxWalk){
    double uvp[2]={0.};
    HXT_CHECK(hxtGetBarycentric(edges->edg2mesh,ct,res,uvp));

    double dD[3] = {res[0]-op[0],res[1]-op[1],res[2]-op[2]};
    normalize(dD);

    if (uvp[0] >= uvlim && uvp[1] >= uvlim && 1.-uvp[0]-uvp[1] >= uvlim && myDot(dD,dir) > 0.0) {
      walk=-1;
    }
    else{
      // If point is not on the triangle
      // return the side of the triangle to continue search 
      if(myDot(dD,dir)>0.0){
        if (uvp[0] < 0 ){
          walk=2;
        }else if (uvp[1]<0){
          walk=0;
        }else{
          walk=1;
        }
      }
    }
    // Intersection point was found 
    if (walk == -1) {
      
      // Check if intersection point is very close to mesh line - added 19/03/2019
      for (uint32_t i=0; i<3; i++){
        uint32_t ce = edges->tri2edg[3*ct+i];
        if (edges2lines[ce] != UINT64_MAX){
          double *p0 = mesh->vertices.coord + 4*edges->node[2*ce+0];
          double *p1 = mesh->vertices.coord + 4*edges->node[2*ce+1];
          double dist = -1;
          double alpha = -1;
          double closePt[3] = {0,0,0};
          HXT_CHECK(hxtSignedDistancePointEdge(p0,p1,res,&dist,&alpha,closePt));
          if (dist<10e-6){ // TODO tolerance here !!!
            *parentFlag = UINT64_MAX ;
            res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
            return HXT_STATUS_OK; 
          }
        }
      }

      *parentFlag = ct;
      return HXT_STATUS_OK; 
    }

    // Intersection with circle failed
    // we cannot continue walking
    if (walk == -100){
      *parentFlag = UINT64_MAX ;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }

    // If we arrive to a mesh line break
    // we don't want to generate point on a different color
    if (edges2lines[edges->tri2edg[3*ct+walk]] != UINT64_MAX){
      *parentFlag = UINT64_MAX ;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }

    // Find next triangle to search 
    uint64_t neigh;
    hxtGetNeighbourTriangle(edges, ct, walk, &neigh);
    if (neigh == UINT64_MAX || mesh->triangles.colors[neigh] != mesh->triangles.colors[ot]){
      *parentFlag = UINT64_MAX;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }
    else{
      ct = neigh;
    }
    walkIter ++;
  }

  // Last resort - search all triangles
  
  /*for (uint64_t i=0; i<mesh->triangles.num; i++){*/
    /*if (mesh->triangles.colors[i] != mesh->triangles.colors[ot]) continue;*/

    /*HXT_CHECK(hxtIntersectTriangleWithCircle(mesh, op, i, size, normal, dir, uvp, &walk, res));*/

    /*// Intersection point was found */
    /*if (walk == -1) {*/
      /**parentFlag = i;*/
      /*return HXT_STATUS_OK; */
    /*}*/
  /*}*/

  return HXT_STATUS_OK; 
}




//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find a candidate point by walking in the triangulation with intersections 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePoint(HXTEdges *edges, 
                                  uint64_t *edges2lines,
                                  double *op,
                                  uint64_t ot,
                                  double *dir,
                                  double *normal,
                                  double size,

                                  double *res,
                                  uint64_t *parentFlag)
{

  HXTMesh *mesh = edges->edg2mesh;
      
  uint64_t ct = ot;
  int walkIter = 0;
  int maxWalk = 100; // TODO
  int walk = -100;
  *parentFlag = UINT64_MAX;
  double uvp[2]={0.};

  while (walkIter < maxWalk){
    res[0] = op[0]; res[1] = op[1]; res[2] = op[2];

    HXT_CHECK(hxtIntersectTriangleWithCircle(mesh, op, ct, size, normal, dir, uvp, &walk, res));     

    // Intersection point was found 
    if (walk == -1) {
      
      // Check if intersection point is very close to mesh line - added 19/03/2019
      for (uint32_t i=0; i<3; i++){
        uint32_t ce = edges->tri2edg[3*ct+i];
        if (edges2lines[ce] != UINT64_MAX){
          double *p0 = mesh->vertices.coord + 4*edges->node[2*ce+0];
          double *p1 = mesh->vertices.coord + 4*edges->node[2*ce+1];
          double dist = -1;
          double alpha = -1;
          double closePt[3] = {0,0,0};
          HXT_CHECK(hxtSignedDistancePointEdge(p0,p1,res,&dist,&alpha,closePt));
          if (dist<10e-6){ // TODO tolerance here !!!
            *parentFlag = UINT64_MAX ;
            res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
            return HXT_STATUS_OK; 
          }
        }
      }
      *parentFlag = ct;
      return HXT_STATUS_OK; 
    }

    // Intersection with circle failed
    // we cannot continue walking
    if (walk == -100){
      *parentFlag = UINT64_MAX ;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }

    // If we arrive to a mesh line break
    // we don't want to generate point on a different color
    if (edges2lines[edges->tri2edg[3*ct+walk]] != UINT64_MAX){
      *parentFlag = UINT64_MAX ;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }

    // Find next triangle to search 
    uint64_t neigh;
    hxtGetNeighbourTriangle(edges, ct, walk, &neigh);
    if (neigh == UINT64_MAX || mesh->triangles.colors[neigh] != mesh->triangles.colors[ot]){
      *parentFlag = UINT64_MAX;
      res[0] = op[0]; res[1] = op[1]; res[2] = op[2];
      return HXT_STATUS_OK; 
    }
    else{
      ct = neigh;
    }
    walkIter ++;
  }

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find a candidate point with a RungeKutta4 scheme - planar
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePointPlanarRK4(HXTEdges *edges, 
                                           uint64_t *edges2lines,
                                           double *originPoint, 
                                           uint64_t originTri,
                                           double *dir1,
                                           double size1,
                                           const double *sizemap,
                                           const double *directions,
                                           double *res, // output point
                                           uint64_t *parent)
{

  HXTMesh *mesh = edges->edg2mesh;

  // Compute normal to triangle
  double normal[3];
  HXT_CHECK(normal2triangle(mesh,originTri,normal));

  // First
  double v1[3];
  v1[0] = size1*dir1[0];
  v1[1] = size1*dir1[1];
  v1[2] = size1*dir1[2];

  //------------------------------------------------------------------------
  // Second
  double p2[3];
  uint64_t tri2;
  HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,
                                          edges2lines,
                                          originPoint,
                                          originTri,
                                          dir1,
                                          size1/2,
                                          p2,
                                          &tri2)); 

  if (tri2 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates 
  double uv2[2];
  HXT_CHECK(hxtGetBarycentric(mesh,tri2,p2,uv2));

  // Compute normal to triangle
  HXT_CHECK(normal2triangle(mesh,tri2,normal));

  // Get new direction and size
  double size2 = 0.;
  double dir2[3] = {0.,0.,0.};
  HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,tri2,normal,uv2,dir1,dir2,&size2));

  //------------------------------------------------------------------------
  // Third
  double p3[3];
  uint64_t tri3;
  HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,
                                          edges2lines,
                                          originPoint,
                                          originTri,
                                          dir2,
                                          size2/2,
                                          p3,
                                          &tri3)); 

  if (tri3 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates 
  double uv3[2];
  HXT_CHECK(hxtGetBarycentric(mesh,tri3,p3,uv3));

  // Compute normal to triangle
  HXT_CHECK(normal2triangle(mesh,tri3,normal));

  // Get new direction and size
  double size3 = 0.;
  double dir3[3] = {0.,0.,0.};
  HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,tri3,normal,uv3,dir2,dir3,&size3));


  //------------------------------------------------------------------------
  // Fourth
  double p4[3];
  uint64_t tri4;
  HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,
                                          edges2lines,
                                          originPoint,
                                          originTri,
                                          dir3,
                                          size3,
                                          p4,
                                          &tri4)); 

  if (tri4 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates 
  double uv4[2];
  HXT_CHECK(hxtGetBarycentric(mesh,tri4,p4,uv4));

  // Compute normal to triangle
  HXT_CHECK(normal2triangle(mesh,tri4,normal));

  // Get new direction and size
  double size4 = 0.;
  double dir4[3] = {0.,0.,0.};
  HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,tri4,normal,uv4,dir3,dir4,&size4));

  //------------------------------------------------------------------------
  
  double v2[3];
  v2[0] = size2*dir2[0];
  v2[1] = size2*dir2[1];
  v2[2] = size2*dir2[2];

  double v3[3];
  v3[0] = size3*dir3[0];
  v3[1] = size3*dir3[1];
  v3[2] = size3*dir3[2];

  double v4[3];
  v4[0] = size4*dir4[0];
  v4[1] = size4*dir4[1];
  v4[2] = size4*dir4[2];

  uint64_t triFinal = UINT64_MAX;
  double pointFinal[3] = {0.,0.,0.};
  double sizeFinal = (size1+2*size2+2*size3+size4)/6.;

  double dirFinal[3] = {0.,0.,0.};
  dirFinal[0] = v1[0] + 2*v2[0] + 2*v3[0] + v4[0];
  dirFinal[1] = v1[1] + 2*v2[1] + 2*v3[1] + v4[1];
  dirFinal[2] = v1[2] + 2*v2[2] + 2*v3[2] + v4[2];
  normalize(dirFinal);

  HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,
                                          edges2lines,
                                          originPoint,
                                          originTri,
                                          dirFinal,
                                          sizeFinal,
                                          pointFinal,
                                          &triFinal)); 


  if (triFinal == UINT64_MAX) return HXT_STATUS_OK;

 *parent = triFinal;
  res[0] = pointFinal[0];
  res[1] = pointFinal[1];
  res[2] = pointFinal[2];


  return HXT_STATUS_OK; 

}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find a candidate point with a RungeKutta4 scheme
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePointRK4(HXTEdges *edges, 
                                     uint64_t *edges2lines,
                                     double *originPoint, 
                                     uint64_t originTri,
                                     double *dir1,
                                     double size1,
                                     const double *sizemap,
                                     const double *directions,
                                     double *res, // output point
                                     uint64_t *parent)
{

  HXTMesh *mesh = edges->edg2mesh;
  
  // Compute normal to triangle
  double normal1[3];
  HXT_CHECK(normal2triangle(mesh,originTri,normal1));

  // First
  double v1[3];
  v1[0] = size1*dir1[0];
  v1[1] = size1*dir1[1];
  v1[2] = size1*dir1[2];

  //------------------------------------------------------------------------
  // Second
  double p2[3];
  uint64_t tri2;
  HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                    edges2lines,
                                    originPoint,
                                    originTri,
                                    dir1,
                                    normal1,
                                    size1/2,
                                    p2,
                                    &tri2)); 

  if (tri2 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates 
  double uv2[2];
  HXT_CHECK(hxtGetBarycentric(mesh,tri2,p2,uv2));

  // Compute normal to triangle
  double normal2[3];
  HXT_CHECK(normal2triangle(mesh,originTri,normal2));

  // Get new direction and size
  double size2 = 0.;
  double dir2[3] = {0.};
  HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,tri2,normal2,uv2,dir1,dir2,&size2));

  //------------------------------------------------------------------------
  // Third
  double p3[3];
  uint64_t tri3;
  HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                    edges2lines,
                                    originPoint,
                                    originTri,
                                    dir2,
                                    normal2,
                                    size2/2,
                                    p3,
                                    &tri3)); 

  if (tri3 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates 
  double uv3[2];
  HXT_CHECK(hxtGetBarycentric(mesh,tri3,p3,uv3));

  // Compute normal to triangle
  double normal3[3];
  HXT_CHECK(normal2triangle(mesh,tri3,normal3));

  // Get new direction and size
  double size3 = 0.;
  double dir3[3] = {0.,0.,0.};
  HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,tri3,normal3,uv3,dir2,dir3,&size3));

  //------------------------------------------------------------------------
  // Fourth
  double p4[3];
  uint64_t tri4;
  HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                    edges2lines,
                                    originPoint,
                                    originTri,
                                    dir3,
                                    normal3,
                                    size3,
                                    p4,
                                    &tri4)); 

  if (tri4 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates 
  double uv4[2];
  HXT_CHECK(hxtGetBarycentric(mesh,tri4,p4,uv4));

  // Compute normal to triangle
  double normal4[3];
  HXT_CHECK(normal2triangle(mesh,tri4,normal4));

  // Get new direction and size
  double size4 = 0.;
  double dir4[3] = {0.,0.,0.};
  HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,tri4,normal4,uv4,dir3,dir4,&size4));

  //------------------------------------------------------------------------
  // Final Point

  double v2[3];
  v2[0] = size2*dir2[0];
  v2[1] = size2*dir2[1];
  v2[2] = size2*dir2[2];

  double v3[3];
  v3[0] = size3*dir3[0];
  v3[1] = size3*dir3[1];
  v3[2] = size3*dir3[2];

  double v4[3];
  v4[0] = size4*dir4[0];
  v4[1] = size4*dir4[1];
  v4[2] = size4*dir4[2];

  uint64_t triFinal = UINT64_MAX;
  double pointFinal[3] = {0.,0.,0.};
  double sizeFinal = (size1+2*size2+2*size3+size4)/6.;

  double dirFinal[3] = {0.,0.,0.};
  dirFinal[0] = v1[0] + 2*v2[0] + 2*v3[0] + v4[0];
  dirFinal[1] = v1[1] + 2*v2[1] + 2*v3[1] + v4[1];
  dirFinal[2] = v1[2] + 2*v2[2] + 2*v3[2] + v4[2];
  normalize(dirFinal);

  HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                    edges2lines,
                                    originPoint,
                                    originTri,
                                    dirFinal,
                                    normal4,
                                    sizeFinal,
                                    pointFinal,
                                    &triFinal)); 


  if (triFinal == UINT64_MAX) return HXT_STATUS_OK;


 *parent = triFinal;
  res[0] = pointFinal[0];
  res[1] = pointFinal[1];
  res[2] = pointFinal[2];


  return HXT_STATUS_OK; 

}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find a candidate point with a RungeKutta4 scheme
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtPointGenCreatePoint(HXTEdges *edges, 
                                 uint64_t *edges2lines,
                                 double *originPoint, 
                                 uint64_t originTri,
                                 double *normal,
                                 double *dir,
                                 double size,
                                 const double *sizemap,
                                 const double *directions,
                                 int walkMethod2D,
                                 double *candidate, // output point
                                 uint64_t *parent)
{

  if (walkMethod2D == 0)
    HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                      edges2lines,
                                      originPoint,
                                      originTri,
                                      dir,
                                      normal,
                                      size,
                                      candidate,
                                      parent)); 


  if (walkMethod2D == 1)
    HXT_CHECK(hxtWalkToCandidatePointRK4(edges, 
                                         edges2lines,
                                         originPoint,
                                         originTri,
                                         dir,
                                         size,
                                         sizemap,
                                         directions,
                                         candidate, 
                                         parent));



  if (walkMethod2D == 2)
    HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,
                                            edges2lines,
                                            originPoint,
                                            originTri,
                                            dir,
                                            size,
                                            candidate,
                                            parent)); 


  if (walkMethod2D == 3)
    HXT_CHECK(hxtWalkToCandidatePointPlanarRK4(edges, 
                                               edges2lines,
                                               originPoint,
                                               originTri,
                                               dir,
                                               size,
                                               sizemap,
                                               directions,
                                               candidate, 
                                               parent));

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to filter aligned with the frame 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtPointGenFilterAligned(HXTMesh *mesh,
                                   double *coords,
                                   double *pp, // candidate point
                                   double *frame,
                                   double *sizes,
                                   double threshold,
                                   void *data,
                                   void *dataLine,
                                   int *pass)
{
  //============================================================================
  // Define a box size to search from the maximum size
  double size = sizes[0] < sizes[1] ? sizes[1] : sizes[0];

  double box = 1.5*size;

  double ppmin[3] = {pp[0] - box, pp[1] - box, pp[2] - box};
  double ppmax[3] = {pp[0] + box, pp[1] + box, pp[2] + box};
 
  //============================================================================
  // Find close boundary lines from RTree of lines  
  // This is an addition for when sizemap inside of the domain differs 
  uint64_t numCloseLines = 0;
  uint64_t *idCloseLines = NULL;
  HXT_CHECK(hxtRTreeSearch64(ppmin,ppmax,&numCloseLines,&idCloseLines,dataLine));

  if (numCloseLines == 0){
  }
  else{
    for (uint64_t i=0; i<numCloseLines; i++){
      uint64_t line = idCloseLines[i];

      double *p0 = mesh->vertices.coord + 4*mesh->lines.node[2*line+0];
      double *p1 = mesh->vertices.coord + 4*mesh->lines.node[2*line+1];
      double dist = -1;
      double alpha = -1;
      double closePt[3] = {0,0,0};
      HXT_CHECK(hxtSignedDistancePointEdge(p0,p1,pp,&dist,&alpha,closePt));

      if (fabs(dist)<threshold*size){
        *pass = 0;
        HXT_CHECK(hxtFree(&idCloseLines));
        return HXT_STATUS_OK;
      }
    }

    HXT_CHECK(hxtFree(&idCloseLines));
  }


   //============================================================================
  // Find nearby generated points from RTree
 
  int numClose = 0;
  int *idClose = NULL;
  HXT_CHECK(hxtRTreeSearch(ppmin,ppmax,&numClose,&idClose,data));

  if (numClose == 0){
    *pass = 1 ;
    return HXT_STATUS_OK;
  }

  double *dir1 = &frame[0];
  double *dir2 = &frame[3];


// TODO delete, just to visualize aligned filtering 
if(0){

  // Scaled direction vectors
  double dirs1[3], dirs2[3];
  for (int i=0; i<3; i++){
    dirs1[i] = sizes[0]*dir1[i];
    dirs2[i] = sizes[1]*dir2[i];
  }

  FILE *oct;
  hxtPosInit("checkBoxFilter.pos","Candidate",&oct);
  hxtPosAddPoint(oct,pp,0);

  hxtPosNewView(oct, "Frame");
  hxtPosAddVector(oct, pp, dir1);
  hxtPosAddVector(oct, pp, dir2);

  hxtPosNewView(oct, "Box");

  double a[3], b[3], c[3], d[3];
  double dd[3];
  double sizt = sqrt(sizes[0]*sizes[0]+sizes[1]*sizes[1]);

  dd[0] = (dirs1[0] + dirs2[0] ) /2.;
  dd[1] = (dirs1[1] + dirs2[1] ) /2.;
  dd[2] = (dirs1[2] + dirs2[2] ) /2.;
  normalize(dd);
  
  a[0] = pp[0] + sizt*dd[0];
  a[1] = pp[1] + sizt*dd[1];
  a[2] = pp[2] + sizt*dd[2];

  dd[0] = (dirs1[0] - dirs2[0] ) /2.;
  dd[1] = (dirs1[1] - dirs2[1] ) /2.;
  dd[2] = (dirs1[2] - dirs2[2] ) /2.;
  normalize(dd);
 
  b[0] = pp[0] + sizt*dd[0];
  b[1] = pp[1] + sizt*dd[1];
  b[2] = pp[2] + sizt*dd[2];

  dd[0] = (-dirs1[0] - dirs2[0] ) /2.;
  dd[1] = (-dirs1[1] - dirs2[1] ) /2.;
  dd[2] = (-dirs1[2] - dirs2[2] ) /2.;
 
  normalize(dd);
  c[0] = pp[0] + sizt*dd[0];
  c[1] = pp[1] + sizt*dd[1];
  c[2] = pp[2] + sizt*dd[2];


  dd[0] = (-dirs1[0] + dirs2[0] ) /2.;
  dd[1] = (-dirs1[1] + dirs2[1] ) /2.;
  dd[2] = (-dirs1[2] + dirs2[2] ) /2.;
  normalize(dd);
 
  d[0] = pp[0] + sizt*dd[0];
  d[1] = pp[1] + sizt*dd[1];
  d[2] = pp[2] + sizt*dd[2];


  hxtPosAddLine(oct, a, b, 1);
  hxtPosAddLine(oct, b, c, 1);
  hxtPosAddLine(oct, c, d, 1);
  hxtPosAddLine(oct, d, a, 1);



  hxtPosNewView(oct, "Box Small");

  sizt = sizt*threshold;

  dd[0] = (dirs1[0] + dirs2[0] ) /2.;
  dd[1] = (dirs1[1] + dirs2[1] ) /2.;
  dd[2] = (dirs1[2] + dirs2[2] ) /2.;
  normalize(dd);
  
  a[0] = pp[0] + sizt*dd[0];
  a[1] = pp[1] + sizt*dd[1];
  a[2] = pp[2] + sizt*dd[2];

  dd[0] = (dirs1[0] - dirs2[0] ) /2.;
  dd[1] = (dirs1[1] - dirs2[1] ) /2.;
  dd[2] = (dirs1[2] - dirs2[2] ) /2.;
  normalize(dd);
 
  b[0] = pp[0] + sizt*dd[0];
  b[1] = pp[1] + sizt*dd[1];
  b[2] = pp[2] + sizt*dd[2];

  dd[0] = (-dirs1[0] - dirs2[0] ) /2.;
  dd[1] = (-dirs1[1] - dirs2[1] ) /2.;
  dd[2] = (-dirs1[2] - dirs2[2] ) /2.;
 
  normalize(dd);
  c[0] = pp[0] + sizt*dd[0];
  c[1] = pp[1] + sizt*dd[1];
  c[2] = pp[2] + sizt*dd[2];


  dd[0] = (-dirs1[0] + dirs2[0] ) /2.;
  dd[1] = (-dirs1[1] + dirs2[1] ) /2.;
  dd[2] = (-dirs1[2] + dirs2[2] ) /2.;
  normalize(dd);
 
  d[0] = pp[0] + sizt*dd[0];
  d[1] = pp[1] + sizt*dd[1];
  d[2] = pp[2] + sizt*dd[2];

  hxtPosAddLine(oct, a, b, 1);
  hxtPosAddLine(oct, b, c, 1);
  hxtPosAddLine(oct, c, d, 1);
  hxtPosAddLine(oct, d, a, 1);

  hxtPosFinish(oct);
}

  for (int i=0; i<numClose; i++){
    double *cp = coords + 4*idClose[i];

    // Project vector pp->cp to the two directions 
    double vec[3] = {cp[0]-pp[0],cp[1]-pp[1],cp[2]-pp[2]};

    double proj1 = myDot(vec,dir1);
    double proj2 = myDot(vec,dir2);

    if (fabs(proj1)<threshold*sizes[0] && 
        fabs(proj2)<threshold*sizes[1]){
      *pass = 0;
      HXT_CHECK(hxtFree(&idClose));
      return HXT_STATUS_OK; 
    }
  }

  HXT_CHECK(hxtFree(&idClose));
  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to correct position of point  
//
// NOT USED - TODO 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtPointGenCorrection(HXTEdges *edges,
                                uint64_t *edges2lines,
                                const double *sizemap,
                                const double *directions,
                                uint64_t *parentTri, // array with parent triangles
                                double *coords,
                                uint32_t originPoint, 
                                double *pp, // candidate point to be corrected
                                uint64_t parent,
                                double *frame,
                                double *sizes,
                                double *normal,
                                void *data,
                                double *cp, // corrected point
                                uint64_t *parentNew)
  
{
  HXT_UNUSED(originPoint);
  HXT_UNUSED(parent);
  HXT_UNUSED(normal);


  HXTMesh *mesh = edges->edg2mesh;

  //===================================================================
  // Find points from RTree
  //===================================================================
  // Find biggest size 
  double size =0;
  for (int i=0; i<3; i++)
    if (sizes[i]>size) size = sizes[i];

  // Take a big enough box to find all nearby generated vertices
  double box = 3*size;

  double ppmin[3] = {pp[0] - box, pp[1] - box, pp[2] - box};
  double ppmax[3] = {pp[0] + box, pp[1] + box, pp[2] + box};
 
  int numClose = 0;
  int *idClose = NULL;
  HXT_CHECK(hxtRTreeSearch(ppmin,ppmax,&numClose,&idClose,data));

  if (numClose == 0 || numClose == 1){
    return HXT_STATUS_OK;
  }

  double *dir1 = &frame[0];
  double *dir2 = &frame[3];

  // Find close and aligned generated points
  double testBox = 1.2;
  int check = 0;
  int points[8];

  double correctionAngle = 0.98;
  double neighbourAngle = 0.99;

  FILE *oct;
  hxtPosInit("checkCorrectionPoints.pos","Neigh",&oct);
  hxtPosNewView(oct, "Candidate");
  hxtPosAddPoint(oct,pp,0);
 
  for (int i=0; i<numClose; i++){

    double *cp = coords + 4*idClose[i]; 

    // Project vector pp->cp to the two directions 
    double vec[3] = {cp[0]-pp[0],cp[1]-pp[1],cp[2]-pp[2]};

    double proj1 = myDot(vec,dir1);
    double proj2 = myDot(vec,dir2);

    if (fabs(proj1)<testBox*sizes[0] && fabs(proj2)<testBox*sizes[1]){
      hxtPosNewView(oct, "Points %d", i );
      hxtPosAddPoint(oct,cp,0);
      hxtPosAddLine(oct,pp,cp,0);

      normalize(vec);

      if (fabs(myDot(vec,dir1)) > correctionAngle || fabs(myDot(vec,dir2)) > correctionAngle){
        points[check] = i;
        check++;
        hxtPosAddLine(oct,pp,cp,0);
      }

      // Check if we can construct vertices relationship
      if (fabs(myDot(vec,dir1)) > neighbourAngle || fabs(myDot(vec,dir2))>neighbourAngle){

        //hxtPosNewView(out, "Line %d", i );
        //hxtPosAddLine(out,pp,cp,0);

      }
    }
  }

  /*hxtPosFinish(oct);*/
  /*if (check>2) return HXT_STATUS_ERROR;*/

  if (check>=0){
    HXT_CHECK(hxtFree(&idClose));
    hxtPosFinish(oct);
    return HXT_STATUS_OK;
  }


  /*FILE *oct;*/
  /*hxtPosInit("checkCorrectionNew.pos","Neigh",&oct);*/


  // TODO DO NOT RECOMPUTE IF ONE OF THE POINTS IS THE originPoint

  if (check == 2){
    
    double *p0 = coords + 4*idClose[points[0]];
    double *p1 = coords + 4*idClose[points[1]];

    uint64_t t0 = parentTri[idClose[points[0]]];
    uint64_t t1 = parentTri[idClose[points[1]]];

 
    // Get barycentric coordinates 
    double uv0[2];
    HXT_CHECK(hxtGetBarycentric(mesh,t0,p0,uv0));
    // Compute normal to triangle
    double normal0[3];
    HXT_CHECK(normal2triangle(mesh,t0,normal0));
    // Compute size
    double size0 = getSize(mesh,sizemap,uv0,t0,0);


    double v0[3] = {pp[0]-p0[0],pp[1]-p0[1],pp[2]-p0[2]};
    normalize(v0);
    double d0[3] = {0.,0.,0.};
    HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t0,normal0,uv0,v0,d0,&size0));
    normalize(d0);

    double pp0[3];
    uint64_t tri0 = UINT64_MAX;

    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p0,*/
                                            /*t0,*/
                                            /*d0,*/
                                            /*size0,*/
                                            /*pp0,*/
                                            /*&tri0)); */

    HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                      edges2lines,
                                      p0,
                                      t0,
                                      d0,
                                      normal0,
                                      size0,
                                      pp0,
                                      &tri0)); 




    
    // Get barycentric coordinates 
    double uv1[2];
    HXT_CHECK(hxtGetBarycentric(mesh,t1,p1,uv1));
    // Compute normal to triangle
    double normal1[3];
    HXT_CHECK(normal2triangle(mesh,t1,normal1));
    // Compute size
    double size1 = getSize(mesh,sizemap,uv1,t1,0);


    double v1[3] = {pp[0]-p1[0],pp[1]-p1[1],pp[2]-p1[2]};
    normalize(v1);
    double d1[3] = {0.,0.,0.};
    HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t1,normal1,uv1,v1,d1,&size1));
    normalize(d1);

    double pp1[3];
    uint64_t tri1 = UINT64_MAX;

    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p1,*/
                                            /*t1,*/
                                            /*d1,*/
                                            /*size1,*/
                                            /*pp1,*/
                                            /*&tri1)); */


    HXT_CHECK(hxtWalkToCandidatePoint(edges,
                                      edges2lines,
                                      p1,
                                      t1,
                                      d1,
                                      normal0,
                                      size1,
                                      pp1,
                                      &tri1)); 

    if (tri0 == UINT64_MAX || tri1 == UINT64_MAX) return HXT_STATUS_OK;



    // New point is calculated as the average 

    cp[0] = (pp0[0] + pp1[0])/2.;
    cp[1] = (pp0[1] + pp1[1])/2.;
    cp[2] = (pp0[2] + pp1[2])/2.;
    

    // TODO 
    // For 3D general case
    // one extra step before hand
    // project point on triangles plane
    // check barycentric
    // if it's inside return the projected 
    // https://stackoverflow.com/questions/9605556/how-to-project-a-point-onto-a-plane-in-3d
    //
    

    FILE *t;
    hxtPosInit("checkPointTriangle.pos","Point",&t);
    hxtPosAddPoint(t,cp,0);
    hxtPosNewView(t,"Point 0");
    hxtPosAddPoint(t,pp0,0);
    hxtPosNewView(t,"Point 1");
    hxtPosAddPoint(t,pp1,0);
    hxtPosNewView(t,"Triangle 0");
    hxtPosAddTriangle(t,&mesh->vertices.coord[4*mesh->triangles.node[3*tri0+0]],
                        &mesh->vertices.coord[4*mesh->triangles.node[3*tri0+1]],
                        &mesh->vertices.coord[4*mesh->triangles.node[3*tri0+2]],0);
    hxtPosNewView(t,"Triangle 1");
    hxtPosAddTriangle(t,&mesh->vertices.coord[4*mesh->triangles.node[3*tri1+0]],
                        &mesh->vertices.coord[4*mesh->triangles.node[3*tri1+1]],
                        &mesh->vertices.coord[4*mesh->triangles.node[3*tri1+2]],0);
    
    

    double dist0, closePt0[3];
    int in0 = 0;
    HXT_CHECK(hxtSignedDistancePointTriangle(&mesh->vertices.coord[4*mesh->triangles.node[3*tri0+0]],
                                             &mesh->vertices.coord[4*mesh->triangles.node[3*tri0+1]],
                                             &mesh->vertices.coord[4*mesh->triangles.node[3*tri0+2]],
                                             cp,
                                             &dist0,
                                             &in0,
                                             closePt0));


    double dist1, closePt1[3];
    int in1 = 0;
    HXT_CHECK(hxtSignedDistancePointTriangle(&mesh->vertices.coord[4*mesh->triangles.node[3*tri1+0]],
                                             &mesh->vertices.coord[4*mesh->triangles.node[3*tri1+1]],
                                             &mesh->vertices.coord[4*mesh->triangles.node[3*tri1+2]],
                                             cp,
                                             &dist1,
                                             &in1,
                                             closePt1));

    hxtPosNewView(t,"PointCloseTri0");
    hxtPosAddPoint(t,closePt0,1);
    hxtPosNewView(t,"PointCloseTri1");
    hxtPosAddPoint(t,closePt1,1);

    // Project point on plane of each triangle
    HXT_CHECK(normal2triangle(mesh,tri0,normal0));
    double vv0[3] = {0.};
    vv0[0] = cp[0] - mesh->vertices.coord[4*mesh->triangles.node[3*tri0+0]+0];
    vv0[1] = cp[1] - mesh->vertices.coord[4*mesh->triangles.node[3*tri0+0]+1];
    vv0[2] = cp[2] - mesh->vertices.coord[4*mesh->triangles.node[3*tri0+0]+2];
    double dd0 = myDot(vv0,normal0);
    double proj0[3];
    proj0[0] = cp[0]-dd0*normal0[0];
    proj0[1] = cp[1]-dd0*normal0[1];
    proj0[2] = cp[2]-dd0*normal0[2];

    HXT_CHECK(normal2triangle(mesh,tri1,normal1));
    double vv1[3] = {0.};
    vv1[0] = cp[0] - mesh->vertices.coord[4*mesh->triangles.node[3*tri1+0]+0];
    vv1[1] = cp[1] - mesh->vertices.coord[4*mesh->triangles.node[3*tri1+0]+1];
    vv1[2] = cp[2] - mesh->vertices.coord[4*mesh->triangles.node[3*tri1+0]+2];
    double dd1 = myDot(vv1,normal1);
    double proj1[3];
    proj1[0] = cp[0]-dd1*normal1[0];
    proj1[1] = cp[1]-dd1*normal1[1];
    proj1[2] = cp[2]-dd1*normal1[2];

    hxtPosNewView(t,"PointProjTri0");
    hxtPosAddPoint(t,proj0,1);
    hxtPosNewView(t,"PointProjTri1");
    hxtPosAddPoint(t,proj1,1);
    hxtPosFinish(t);



    if (in0 != 1 && in1 != 1){
      return HXT_STATUS_ERROR;
    }

    if (tri0 != tri1){
      printf("%d %d \n", in0, in1);
      return HXT_STATUS_OK;
    }


    /*if (fabs(dist0) > 10e-6 && fabs(dist1) > 10e-6){*/
      /*printf("%d %d \n", in0, in1);*/
      /*return HXT_STATUS_ERROR;*/
    /*}*/


 
    HXT_CHECK(hxtWalkToCandidatePointPlanarGiven(edges,
                                                 edges2lines,
                                                 p0,
                                                 t0,
                                                 d0,
                                                 cp,
                                                 parentNew)); 



  }


  /*if (check == 3){*/
    
    /*double *p0 = coords + 4*idClose[points[0]];*/
    /*double *p1 = coords + 4*idClose[points[1]];*/
    /*double *p2 = coords + 4*idClose[points[2]];*/

    /*uint64_t t0 = parentTri[idClose[points[0]]];*/
    /*uint64_t t1 = parentTri[idClose[points[1]]];*/
    /*uint64_t t2 = parentTri[idClose[points[2]]];*/

 
    /*// Get barycentric coordinates */
    /*double uv0[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t0,p0,uv0));*/
    /*// Compute normal to triangle*/
    /*double normal0[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t0,normal0));*/
    /*// Compute size*/
    /*double size0 = getSize(mesh,sizemap,uv0,t0,0);*/


    /*double v0[3] = {pp[0]-p0[0],pp[1]-p0[1],pp[2]-p0[2]};*/
    /*normalize(v0);*/
    /*double d0[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t0,normal0,uv0,v0,d0,&size0));*/
    /*normalize(d0);*/

    /*double pp0[3];*/
    /*uint64_t tri0;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p0,*/
                                            /*t0,*/
                                            /*d0,*/
                                            /*size0,*/
                                            /*pp0,*/
                                            /*&tri0)); */


    
    /*// Get barycentric coordinates */
    /*double uv1[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t1,p1,uv1));*/
    /*// Compute normal to triangle*/
    /*double normal1[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t1,normal1));*/
    /*// Compute size*/
    /*double size1 = getSize(mesh,sizemap,uv1,t1,0);*/

    /*double v1[3] = {pp[0]-p1[0],pp[1]-p1[1],pp[2]-p1[2]};*/
    /*normalize(v1);*/
    /*double d1[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t1,normal1,uv1,v1,d1,&size1));*/
    /*normalize(d1);*/

    /*double pp1[3];*/
    /*uint64_t tri1;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p1,*/
                                            /*t1,*/
                                            /*d1,*/
                                            /*size1,*/
                                            /*pp1,*/
                                            /*&tri1)); */

    /*// Get barycentric coordinates */
    /*double uv2[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t2,p2,uv2));*/
    /*// Compute normal to triangle*/
    /*double normal2[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t2,normal2));*/
    /*// Compute size*/
    /*double size2 = getSize(mesh,sizemap,uv2,t2,0);*/

    /*double v2[3] = {pp[0]-p2[0],pp[1]-p2[1],pp[2]-p2[2]};*/
    /*normalize(v2);*/
    /*double d2[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t2,normal2,uv2,v2,d2,&size2));*/
    /*normalize(d2);*/

    /*double pp2[3];*/
    /*uint64_t tri2;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p2,*/
                                            /*t2,*/
                                            /*d2,*/
                                            /*size2,*/
                                            /*pp2,*/
                                            /*&tri2)); */




    /*hxtPosNewView(oct,"CHECK");*/
    /*hxtPosAddPoint(oct,pp0,0);*/
    /*hxtPosAddPoint(oct,pp1,0);*/
    /*hxtPosAddPoint(oct,pp2,0);*/

    /*cp[0] = (pp0[0] + pp1[0] + pp2[0])/3.;*/
    /*cp[1] = (pp0[1] + pp1[1] + pp2[1])/3.;*/
    /*cp[2] = (pp0[2] + pp1[2] + pp2[2])/3.;*/
    

    /*HXT_CHECK(hxtWalkToCandidatePointPlanarGiven(edges,*/
                                            /*edges2lines,*/
                                            /*p0,*/
                                            /*t0,*/
                                            /*d0,*/
                                            /*cp,*/
                                            /*parentNew)); */




  /*}*/


  /*if (check == 4){*/
    
    /*double *p0 = coords + 4*idClose[points[0]];*/
    /*double *p1 = coords + 4*idClose[points[1]];*/
    /*double *p2 = coords + 4*idClose[points[2]];*/
    /*double *p3 = coords + 4*idClose[points[3]];*/

    /*uint64_t t0 = parentTri[idClose[points[0]]];*/
    /*uint64_t t1 = parentTri[idClose[points[1]]];*/
    /*uint64_t t2 = parentTri[idClose[points[2]]];*/
    /*uint64_t t3 = parentTri[idClose[points[3]]];*/

 
    /*// Get barycentric coordinates */
    /*double uv0[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t0,p0,uv0));*/
    /*// Compute normal to triangle*/
    /*double normal0[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t0,normal0));*/
    /*// Compute size*/
    /*double size0 = getSize(mesh,sizemap,uv0,t0,0);*/


    /*double v0[3] = {pp[0]-p0[0],pp[1]-p0[1],pp[2]-p0[2]};*/
    /*normalize(v0);*/
    /*double d0[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t0,normal0,uv0,v0,d0,&size0));*/
    /*normalize(d0);*/

    /*double pp0[3];*/
    /*uint64_t tri0;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p0,*/
                                            /*t0,*/
                                            /*d0,*/
                                            /*size0,*/
                                            /*pp0,*/
                                            /*&tri0)); */


    
    /*// Get barycentric coordinates */
    /*double uv1[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t1,p1,uv1));*/
    /*// Compute normal to triangle*/
    /*double normal1[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t1,normal1));*/
    /*// Compute size*/
    /*double size1 = getSize(mesh,sizemap,uv1,t1,0);*/

    /*double v1[3] = {pp[0]-p1[0],pp[1]-p1[1],pp[2]-p1[2]};*/
    /*normalize(v1);*/
    /*double d1[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t1,normal1,uv1,v1,d1,&size1));*/
    /*normalize(d1);*/

    /*double pp1[3];*/
    /*uint64_t tri1;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p1,*/
                                            /*t1,*/
                                            /*d1,*/
                                            /*size1,*/
                                            /*pp1,*/
                                            /*&tri1)); */

    /*// Get barycentric coordinates */
    /*double uv2[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t2,p2,uv2));*/
    /*// Compute normal to triangle*/
    /*double normal2[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t2,normal2));*/
    /*// Compute size*/
    /*double size2 = getSize(mesh,sizemap,uv2,t2,0);*/

    /*double v2[3] = {pp[0]-p2[0],pp[1]-p2[1],pp[2]-p2[2]};*/
    /*normalize(v2);*/
    /*double d2[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t2,normal2,uv2,v2,d2,&size2));*/
    /*normalize(d2);*/

    /*double pp2[3];*/
    /*uint64_t tri2;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p2,*/
                                            /*t2,*/
                                            /*d2,*/
                                            /*size2,*/
                                            /*pp2,*/
                                            /*&tri2)); */


    /*// Get barycentric coordinates */
    /*double uv3[2];*/
    /*HXT_CHECK(hxtGetBarycentric(mesh,t3,p3,uv3));*/
    /*// Compute normal to triangle*/
    /*double normal3[3];*/
    /*HXT_CHECK(normal2triangle(mesh,t3,normal3));*/
    /*// Compute size*/
    /*double size3 = getSize(mesh,sizemap,uv3,t3,0);*/

    /*double v3[3] = {pp[0]-p3[0],pp[1]-p3[1],pp[2]-p3[2]};*/
    /*normalize(v3);*/
    /*double d3[3] = {0.,0.,0.};*/
    /*HXT_CHECK(hxtGetClosestDirection(mesh,directions,sizemap,t3,normal3,uv3,v3,d3,&size3));*/
    /*normalize(d3);*/

    /*double pp3[3];*/
    /*uint64_t tri3;*/
    /*HXT_CHECK(hxtWalkToCandidatePointPlanar(edges,*/
                                            /*edges2lines,*/
                                            /*p3,*/
                                            /*t3,*/
                                            /*d3,*/
                                            /*size3,*/
                                            /*pp3,*/
                                            /*&tri3)); */






    /*hxtPosNewView(oct,"CHECK");*/
    /*hxtPosAddPoint(oct,pp0,0);*/
    /*hxtPosAddPoint(oct,pp1,0);*/
    /*hxtPosAddPoint(oct,pp2,0);*/
    /*hxtPosAddPoint(oct,pp3,0);*/

    /*cp[0] = (pp0[0] + pp1[0] + pp2[0] + pp3[0])/4.;*/
    /*cp[1] = (pp0[1] + pp1[1] + pp2[1] + pp3[1])/4.;*/
    /*cp[2] = (pp0[2] + pp1[2] + pp2[2] + pp3[2])/4.;*/
    

    /*HXT_CHECK(hxtWalkToCandidatePointPlanarGiven(edges,*/
                                            /*edges2lines,*/
                                            /*p0,*/
                                            /*t0,*/
                                            /*d0,*/
                                            /*cp,*/
                                            /*parentNew)); */




  /*}*/

  hxtPosFinish(oct);

  /*printf("%d \n", check);*/
  //if (check > 4) printf("OPA = %d \n", check);

  //if (check == 7) return HXT_STATUS_ERROR;

  HXT_CHECK(hxtFree(&idClose));
  return HXT_STATUS_OK;
}






//*************************************************************************************************
//*************************************************************************************************
//
//
// FUNCTION to generate points on a single colored surface
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGeneratePointsColoredSurface(HXTPointGenOptions *opt,
                                          HXTMesh *mesh,
                                          HXTMesh *fmesh,
                                          HXTEdges      *edges,
                                          uint64_t      *edges2lines,
                                          const double  *sizemap,
                                          const double  *directions,
                                          uint16_t      color,
                                          uint32_t      numLinePoints,
                                          uint32_t      numMaxPoints,

                                          uint32_t  *numGeneratedPoints,
                                          double    *coords,
                                          uint64_t  *parentTri,
                                          uint32_t  *bin)
{

  HXT_UNUSED(opt);
  double tol = 10e-16; // TODO put in options 
  double threshold = 0.72; // TODO put in options 


  //********************************************************
  // Create RTree for filtering 
  //********************************************************
  void* data;
  HXT_CHECK(hxtRTreeCreate(&data));
  // Add line points in RTree
  for (uint32_t i=0; i<numLinePoints; i++){
    // Check if parent triangle has in fact the correct color
    if (mesh->triangles.colors[parentTri[i]] != color){ 
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Parent triangle of point %d has different color",i);
    }
    double *cp = coords + 4*i ; 
    HXT_CHECK(hxtAddPointInRTree(cp,tol,i,data));

    //hxtPosAddPoint(out,cp,mesh->triangles.colors[parentTri[i]]); // output pointsClean
    //hxtPosAddText(out,cp,"%d",i); // output pointsClean

  }

  // A second auxillary rtree for surface triangles
  void *dataLine;
  HXT_CHECK(hxtRTreeCreate64(&dataLine));
  if (opt->generateLines == 0){
    for (uint64_t i=0; i<mesh->lines.num; i++){
      double *p0 = mesh->vertices.coord + 4*mesh->lines.node[2*i+0];
      double *p1 = mesh->vertices.coord + 4*mesh->lines.node[2*i+1];
      HXT_CHECK(hxtAddLineInRTree64(p0,p1,tol,i,dataLine));
    }
  }


  //********************************************************
  // Create node connectivity during point generation 
  //********************************************************
  // TODO 
  uint32_t *node2node;
  HXT_CHECK(hxtMalloc(&node2node, numMaxPoints*4*sizeof(uint32_t)));

  for (uint64_t i=0; i<fmesh->lines.num; i++){
    //double *p0 = fmesh->vertices.coord + 4*fmesh->lines.node[2*i+0];
    //double *p1 = fmesh->vertices.coord + 4*fmesh->lines.node[2*i+1];
    //hxtPosAddLine(out,p0,p1,0);
    uint32_t v0 = fmesh->lines.node[2*i+0];
    uint32_t v1 = fmesh->lines.node[2*i+1];
    node2node[4*v0+0] = v1;
    node2node[4*v1+2] = v0;
  }
  HXT_CHECK(hxtFree(&node2node));

  

  //********************************************************
  // Queue-like loop to generate points
  //********************************************************
  
  uint32_t numGenPoints = 0;
  numGenPoints += numLinePoints;

  for (uint32_t i=0; i<numMaxPoints; i++){

    // Take origin point
    double *originPoint = coords + 4*i;
    
    // Take parent triangle of origin point
    uint64_t originTri = parentTri[i];

    // Check if parent triangle has same color
    if (mesh->triangles.colors[originTri] != color){
      printf("%d %d \n", color, mesh->triangles.colors[originTri]);
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Parent triangle does not have same color");
    }

    // Get barycentric coordinates 
    double uv[2];
    HXT_CHECK(hxtGetBarycentric(mesh,originTri,originPoint,uv));

    // Compute normal to triangle
    double normal[3];
    HXT_CHECK(normal2triangle(mesh,originTri,normal));

    // Get frame and sizes for candidate point 
    double sizes[6] = {0.};
    double frame[6*3] = {0.};
    HXT_CHECK(hxtGetDirections(mesh,directions,sizemap,originTri,normal,uv,frame,sizes));


    // Find new points for 4 directions
    for(int nb = 0; nb<4; nb++){

      double dir[3] = {frame[3*nb+0],frame[3*nb+1],frame[3*nb+2]};
      double size = sizes[nb];

      //==================================================
      // Find if possible a candidate point
      //==================================================
      double candidate[3] = {0.,0.,0.};
      uint64_t parent = UINT64_MAX;

      HXT_CHECK(hxtPointGenCreatePoint(edges,
                                       edges2lines,
                                       originPoint,
                                       originTri,
                                       normal,
                                       dir,
                                       size,
                                       sizemap,
                                       directions,
                                       opt->walkMethod2D,
                                       candidate,
                                       &parent));


      if (parent == UINT64_MAX){
        continue; // No point was found 
      }


      //==================================================
      //  Filtering of point 
      //==================================================
      // A candidate point with its parent triangle was found from intersection
      // we check now if we can insert this point
      int insert = 1;

      // Get barycentric coordinates for candidate point 
      double uvCandidate[2];
      HXT_CHECK(hxtGetBarycentric(mesh,parent,candidate,uvCandidate));

      // Get frame and sizes for candidate point 
      double sizesCandidate[6] = {0.};
      double frameCandidate[6*3] = {0.};
      HXT_CHECK(hxtGetDirections(mesh,directions,sizemap,parent,normal,uvCandidate,frameCandidate,sizesCandidate));

      HXT_CHECK(hxtPointGenFilterAligned(mesh,
                                         coords,
                                         candidate, 
                                         frameCandidate, 
                                         sizesCandidate, 
                                         threshold, 
                                         data, 
                                         dataLine,
                                         &insert));

      if (insert == 0 ){
        //hxtPosAddPoint(fil,candidate,0); // output pointsFilter
        //hxtPosAddText(fil,candidate,"%d_%d",i,nb); // output pointsFilter
      }




      //==================================================
      // (function of correction)
      // TODO 
      //==================================================
      int flagCorrection = 0;
      if (insert && flagCorrection ){

        double candidateNew[3] = {0};
        uint64_t parentNew = UINT64_MAX;
        HXT_CHECK(hxtPointGenCorrection(edges,
                                        edges2lines,
                                        sizemap,
                                        directions,
                                        parentTri,
                                        coords,
                                        i,
                                        candidate,
                                        parent,
                                        frameCandidate,
                                        sizesCandidate,
                                        normal,
                                        data,
                                        candidateNew, 
                                        &parentNew));

        if (parentNew != UINT64_MAX){
          parent = parentNew;
          candidate[0] = candidateNew[0];
          candidate[1] = candidateNew[1];
          candidate[2] = candidateNew[2];
         }
 
        // Get barycentric coordinates for candidate point 
        double uvCandidate[2];
        HXT_CHECK(hxtGetBarycentric(mesh,parent,candidate,uvCandidate));
  
        // Get frame and sizes for candidate point 
        double sizesCandidate[6] = {0.};
        double frameCandidate[6*3] = {0.};
        //HXT_CHECK(hxtGetDirectionsScaled(mesh,directions,sizemap,parent,normal,uv,frameCandidate,sizesCandidate));
        //HXT_CHECK(hxtInterpolateFrame(mesh,directions,sizemap,parent,normal,uvCandidate,frameCandidate,sizesCandidate));
        HXT_CHECK(hxtGetDirections(mesh,directions,sizemap,parent,normal,uvCandidate,frameCandidate,sizesCandidate));

        // FILTERING corrected point 
        //HXT_CHECK(hxtPointGenFilter(coords,candidate,size,threshold,data,&insert));
        HXT_CHECK(hxtPointGenFilterAligned(mesh,
                                           coords,
                                           candidate, 
                                           frameCandidate, 
                                           sizesCandidate, 
                                           threshold, 
                                           data, 
                                           dataLine,
                                           &insert));

      }

      //==================================================
      // If is not filtered, insert the point
      //==================================================
      if(insert){

        coords[4*numGenPoints+0] = candidate[0];
        coords[4*numGenPoints+1] = candidate[1];
        coords[4*numGenPoints+2] = candidate[2];
        parentTri[numGenPoints] = parent;
        HXT_CHECK(hxtAddPointInRTree(candidate,tol,numGenPoints,data));

        if (bin[i] == 0) bin[numGenPoints] = 1;
        if (bin[i] == 1) bin[numGenPoints] = 0;
        if (bin[i] == UINT32_MAX) return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Problem in binary index");

        numGenPoints++;

        //hxtPosAddPoint(out,candidate,mesh->triangles.colors[parent]); // output pointsClean
        //hxtPosAddText(out,candidate,"%d",numGenPoints-1); // output pointsClean
        //hxtPosAddLine(out,originPoint,candidate,0);
        //hxtPosAddVector(out, originPoint, dir);
        //hxtPosAddText(out,candidate,"%d\n", numGenPoints);
        
      }
    }

 
    // Terminating condition 
    if (i > numGenPoints-2) break;
  
  }

  *numGeneratedPoints = numGenPoints;

  HXT_CHECK(hxtRTreeDelete(&data));
  HXT_CHECK(hxtRTreeDelete(&dataLine));

  return HXT_STATUS_OK;
}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to generate points on surfaces 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGeneratePointsOnSurface(HXTPointGenOptions *opt,
                                     HXTMesh *mesh,
                                     HXTEdges *edges,
                                     const double *sizemap, 
                                     const double *directions,
                                     HXTPointGenParent *pointParent,   
                                     HXTMesh *fmesh, uint32_t *bin) 
{

  HXT_INFO("");
  HXT_INFO("========= Generating points on surfaces ==========");
  HXT_INFO("");
  
  clock_t time00 = clock();
  // Create list of colors of triangles
  uint16_t *triColors;
  uint16_t numTriColors;
  HXT_CHECK(hxtGetTrianglesColorsList(mesh,&numTriColors,&triColors));
  HXT_INFO("Number of input mesh colors          %d", numTriColors);
  clock_t time01 = clock();
  double time_estimate = (double)(time01 - time00) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create tricolors    %f", time_estimate);


  // Create lines to edges array;
  uint32_t *lines2edges;
  HXT_CHECK(hxtMalloc(&lines2edges,mesh->lines.num*sizeof(uint32_t)));
  HXT_CHECK(hxtGetLinesToEdges(edges,lines2edges));
  clock_t time02 = clock();
  time_estimate = (double)(time02 - time01) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create lines2edges    %f", time_estimate);


  // Create edges to lines array;
  uint64_t *edges2lines;
  HXT_CHECK(hxtMalloc(&edges2lines,edges->numEdges*sizeof(uint64_t)));
  for (uint32_t i=0; i<edges->numEdges; i++) edges2lines[i] = UINT64_MAX;
  HXT_CHECK(hxtGetEdgesToLines(edges,lines2edges,edges2lines));
  clock_t time03 = clock();
  time_estimate = (double)(time03 - time02) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create edges2lines    %f", time_estimate);


  // Create lines to triangles array
  // This is used to handle non-manifold triangulations
  // where mesh lines can have more than 2 triangles
  uint64_t maxNumTriToLine = 0; // maximum number of triangles adjacent to a line
  HXT_CHECK(hxtCountMaxNumberOfTrianglesToEdges(edges,&maxNumTriToLine));
  clock_t time04 = clock();
  time_estimate = (double)(time04 - time03) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create tri2line    %f", time_estimate);

  uint64_t *lines2triangles;
  HXT_CHECK(hxtMalloc(&lines2triangles,maxNumTriToLine*mesh->lines.num*sizeof(uint64_t)));
  for (uint64_t i=0; i<maxNumTriToLine*mesh->lines.num; i++) lines2triangles[i] = UINT64_MAX;
  HXT_CHECK(hxtGetLinesToTriangles(edges,maxNumTriToLine,edges2lines,lines2triangles));
  clock_t time05 = clock();
  time_estimate = (double)(time05 - time04) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create lines2triangles    %f", time_estimate);


  HXT_INFO("Number of max triangles per line     %lu", maxNumTriToLine);
  if (maxNumTriToLine>2){
    HXT_INFO("***** non-manifold input mesh *****");

  }


  //hxtPosInit("pointsClean.pos","points",&out);
  

  // *********************************************************************************
  // *********************************************************************************
  // Iterate per color 
  
  HXT_INFO_COND(opt->walkMethod2D==0,"Walking method to candidate point - simple");
  HXT_INFO_COND(opt->walkMethod2D==1,"Walking method to candidate point - RungeKutta4");
  HXT_INFO_COND(opt->walkMethod2D==2,"Walking method to candidate point - planar simple");
  HXT_INFO_COND(opt->walkMethod2D==3,"Walking method to candidate point - planar RungeKutta4");


  HXT_INFO_COND(opt->verbosity>0,"");
  HXT_INFO_COND(opt->verbosity>0,"Generating points per discrete colored surface");

  
  //uint32_t numTotalPointsOnLines = fmesh->vertices.num; // Image TODO delete
  for (uint16_t c=0; c<numTriColors; c++){

    uint16_t color = triColors[c];

    if (color == opt->skipColor) continue; // QUADTRI 

    // Get points on lines for current color 
    clock_t time0 = clock();
    uint32_t numPointsOnLines;
    uint32_t *pointsOnLines;
    uint64_t *pointsOnLines2tri;
    HXT_CHECK(hxtMalloc(&pointsOnLines,fmesh->vertices.num*sizeof(uint32_t)));
    HXT_CHECK(hxtMalloc(&pointsOnLines2tri,fmesh->vertices.num*sizeof(uint64_t)));
    
    HXT_CHECK(hxtGetLineVerticesForColor(mesh, 
                                         maxNumTriToLine,
                                         lines2triangles,
                                         fmesh,
                                         pointParent,
                                         color,
                                         &numPointsOnLines,
                                         pointsOnLines,
                                         pointsOnLines2tri));
    if (numPointsOnLines == 0){
      return HXT_ERROR_MSG(HXT_STATUS_FAILED,"Cannot find line points for this color - wrong topology???");
    }

    // Realloc to downsize - from fmesh->vertices.num TO numPointsOnLines
    HXT_CHECK(hxtRealloc(&pointsOnLines,numPointsOnLines*sizeof(uint32_t)));
    HXT_CHECK(hxtRealloc(&pointsOnLines2tri,numPointsOnLines*sizeof(uint64_t)));

    clock_t time1 = clock();
    double time_linepoints = (double)(time1 - time0) / CLOCKS_PER_SEC;
    HXT_INFO_COND(opt->verbosity>0,"Color %2d Time for line points   %f", color, time_linepoints);




    // Estimate number of vertices for this colored surface
    // by using the bounding box of triangles
    clock_t time2 = clock();
    uint32_t estNumVert;
    HXT_CHECK(hxtEstimateNumOfVerticesForColoredSurface(mesh,
                                                        color,
                                                        sizemap,
                                                        &estNumVert));


    estNumVert = fmesh->vertices.size; // TODO TODO TODO ATTENTION estimate number of vertices function not working problem with sanitizer 

    // To store coordinates of generated points for this colored surface
    double *generatedPointsCoords;
    HXT_CHECK(hxtMalloc(&generatedPointsCoords,4*estNumVert*sizeof(double)));

    // To store parent triangles of generated points
    uint64_t *generatedPoints2tri;
    HXT_CHECK(hxtMalloc(&generatedPoints2tri,estNumVert*sizeof(uint64_t)));

    // To store binary index of generated points
    uint32_t *generatedPointsBin;
    HXT_CHECK(hxtMalloc(&generatedPointsBin,estNumVert*sizeof(uint32_t)));
    for (uint32_t i=0; i<estNumVert; i++) generatedPointsBin[i] = UINT32_MAX;



    // Insert line points to coordinates and points2tri arrays
    for (uint32_t i=0; i<numPointsOnLines; i++){
      generatedPointsCoords[4*i+0] = fmesh->vertices.coord[4*pointsOnLines[i]+0];
      generatedPointsCoords[4*i+1] = fmesh->vertices.coord[4*pointsOnLines[i]+1];
      generatedPointsCoords[4*i+2] = fmesh->vertices.coord[4*pointsOnLines[i]+2];
      generatedPoints2tri[i] = pointsOnLines2tri[i];
      generatedPointsBin[i] = bin[pointsOnLines[i]];
    }
    HXT_CHECK(hxtFree(&pointsOnLines));
    HXT_CHECK(hxtFree(&pointsOnLines2tri));


    clock_t time3 = clock();
    double time_estimate = (double)(time3 - time2) / CLOCKS_PER_SEC;
    HXT_INFO_COND(opt->verbosity>0,"Color %d Time estimate numvert  %f", color, time_estimate);

   
    // Generate points on this colored surface
    clock_t time4 = clock();
    uint32_t numGeneratedPoints=0;
    HXT_CHECK(hxtGeneratePointsColoredSurface(opt,
                                              mesh,
                                              fmesh,
                                              edges,
                                              edges2lines,
                                              sizemap,
                                              directions,
                                              color,

                                              numPointsOnLines,
                                              estNumVert,
                                              
                                              &numGeneratedPoints,
                                              generatedPointsCoords,
                                              generatedPoints2tri,
                                              generatedPointsBin));
 
    // Returns:
    //  numGeneratedPoints:    number of generated points + number of points on lines
    //  generatedPointsCoords: array of coordinates of points for this surface 
    //  generatedPoints2tri:   array of parent triangles for generated points      
    //  
    
    clock_t time5 = clock();
    double time_generate = (double)(time5 - time4) / CLOCKS_PER_SEC;

    HXT_INFO_COND(opt->verbosity>0,"Color %d Time generate points   %f", color, time_generate);
    HXT_INFO_COND(opt->verbosity>0,
        "Color %2d  ||  Line points %5d  ||  Generated points %5d",color,numPointsOnLines,numGeneratedPoints);

    
    // Insert new coords as vertices in fmesh 
    // Check of course if numGeneratedPoints > fmesh->vertices.size
    if (fmesh->vertices.num+(numGeneratedPoints-numPointsOnLines)>fmesh->vertices.size){
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Not enough allocated size for generated points");
    }

    // The first numPointsOnLines points on those arrays will not inserted in fmesh (already there!)
    for (uint32_t j=numPointsOnLines; j<numGeneratedPoints; j++){
      fmesh->vertices.coord[4*fmesh->vertices.num+0] = generatedPointsCoords[4*j+0];
      fmesh->vertices.coord[4*fmesh->vertices.num+1] = generatedPointsCoords[4*j+1];
      fmesh->vertices.coord[4*fmesh->vertices.num+2] = generatedPointsCoords[4*j+2];

      /*if (generatedPointsCoords[4*j+3] <0 ) bin[fmesh->vertices.num] = 0;*/
      /*if (generatedPointsCoords[4*j+3] >0 ) bin[fmesh->vertices.num] = 1;*/
      bin[fmesh->vertices.num ] = generatedPointsBin[j];
 

      pointParent[fmesh->vertices.num].type = 2;
      pointParent[fmesh->vertices.num].id = generatedPoints2tri[j];

      fmesh->vertices.num++;
    }

    HXT_CHECK(hxtFree(&generatedPointsCoords));
    HXT_CHECK(hxtFree(&generatedPoints2tri));
    HXT_CHECK(hxtFree(&generatedPointsBin));

  }

  //hxtPosFinish(out); // output pointsClean
  //hxtPosFinish(fil); // output pointsClean


  // TODO delete  
  // Image for presentation 
  /*uint32_t counterAnim = 0;*/
  /*uint32_t currentNum = numTotalPointsOnLines;*/
  /*while (currentNum <= fmesh->vertices.num){*/
    /*FILE *pp;*/
    /*char buffer[32];*/
    /*snprintf(buffer,sizeof(char)*32,"resanimgen/screens/file%i.txt",(int)counterAnim);*/
    /*hxtPosInit(buffer, "Points", &pp); */
    /*for (uint64_t l=0; l<currentNum; l++){*/
     /*double v0[3];*/
      /*v0[0] = fmesh->vertices.coord[4*l+0];*/
      /*v0[1] = fmesh->vertices.coord[4*l+1];*/
      /*v0[2] = fmesh->vertices.coord[4*l+2];*/
      /*hxtPosAddPoint(pp,v0,0);*/
    /*}*/
    /*hxtPosFinish(pp);*/
    /*currentNum++;*/
    /*counterAnim++;*/
  /*}*/

  HXT_CHECK(hxtFree(&lines2edges));
  HXT_CHECK(hxtFree(&edges2lines));
  HXT_CHECK(hxtFree(&lines2triangles));
  HXT_CHECK(hxtFree(&triColors));

  return HXT_STATUS_OK;
}


//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to get line vertices and lines/points from input mesh
//  
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGetPointsOnSurfacesFromInputMesh(HXTMesh *mesh, 
                                              HXTPointGenOptions *opt,
                                              HXTMesh *fmesh, 
                                              HXTPointGenParent *parent)
{
  HXT_UNUSED(opt);

  HXT_INFO("");
  HXT_INFO("========= Get points on surfaces from input mesh ==========");

  // We already have points on lines plus lines/points in fmesh 
  // so we need to add points from triangles plus the parent triangle
  
  uint8_t *isOnBoundary;
  HXT_CHECK(hxtMalloc(&isOnBoundary,mesh->vertices.num*sizeof(uint8_t)));
  for (uint32_t i=0; i<mesh->vertices.num; i++) isOnBoundary[i] = 0;
  

  for (uint64_t i=0; i<mesh->lines.num; i++){
    isOnBoundary[mesh->lines.node[2*i+0]] = 1;
    isOnBoundary[mesh->lines.node[2*i+1]] = 1;
  }
  
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    for (uint32_t j=0; j<3; j++){
      uint32_t v = mesh->triangles.node[3*i+j];
      if (isOnBoundary[v] == 1) continue;
      uint32_t cnt = fmesh->vertices.num;
      fmesh->vertices.coord[4*cnt+0] = mesh->vertices.coord[4*v+0];
      fmesh->vertices.coord[4*cnt+1] = mesh->vertices.coord[4*v+1];
      fmesh->vertices.coord[4*cnt+2] = mesh->vertices.coord[4*v+2];
      parent[cnt].type = 2;
      parent[cnt].id = i;
      isOnBoundary[v] = 1;
      fmesh->vertices.num++;
    }
  }

  HXT_CHECK(hxtFree(&isOnBoundary));
  
  return HXT_STATUS_OK;
}
