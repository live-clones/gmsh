#include <math.h>
#include <time.h>
#include "hxt_point_gen_3d.h"
#include "hxt_rtree_wrapper.h"

#include "predicates.h"
//#include "hxt_tetFlag.h"
#include "hxt_point_gen_orientation.h"
#include "hxt_orientation3d_tools.h"

#include "hxt_point_gen_numerics.h"

#include "hxt_post_debugging.h"

static double sign(double a){
  return a>=0 ? 1.:-1;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION TEST to find a point inside tetrahedron  
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtIsPointInsideTetrahedron(HXTMesh *mesh,
                                      HXTMesh *fmesh,
                                      uint32_t cv,
                                      uint64_t ct,
                                      double *cp)
{
  double uv[4];
  HXT_CHECK(hxtGetBarycentricTetra(mesh, ct, cp, uv));

  int isInside = 0;
  double tolerance = 10e-9;
  if (uv[0] >= -tolerance &&
      uv[1] >= -tolerance &&
      uv[2] >= -tolerance &&
      uv[3] >= -tolerance ) isInside = 1;
  if (isInside != 1) return HXT_STATUS_ERROR;

  const double *vt = fmesh->vertices.coord + 4*cv; 
  const double *a = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*ct+0];
  const double *b = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*ct+1];
  const double *c = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*ct+2];
  const double *d = mesh->vertices.coord + 4*mesh->tetrahedra.node[4*ct+3];
 
  if ( (orient3d(a,b,c,vt)>=0) +
       (orient3d(a,b,vt,d)>=0) +
       (orient3d(a,vt,c,d)>=0) +
       (orient3d(vt,b,c,d)>=0)>2)
  {
    return HXT_STATUS_ERROR;
  }

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get size for a point inside a tetrahedron
//
//*************************************************************************************************
//*************************************************************************************************
static inline double getSize(HXTMesh *mesh, const double *sizemap, double *uv, uint64_t ct){
  return uv[0] *sizemap[mesh->tetrahedra.node[4*ct+0]] + 
         uv[1] *sizemap[mesh->tetrahedra.node[4*ct+1]] + 
         uv[2] *sizemap[mesh->tetrahedra.node[4*ct+2]] + 
         uv[3] *sizemap[mesh->tetrahedra.node[4*ct+3]] ; 
}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get 3 coherent sizes for a point inside a tetrahedron
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetCoherentSizes3d(HXTMesh* mesh, 
                                const double* directions, 
                                const double* sizemap,
                                uint64_t tet, 
                                double *frame,
                                double *uv,
                                double *sizes)
{
  double tetSizes[4*3]={0.};
  const uint32_t* nodes = &(mesh->tetrahedra.node[4*tet]);
  /* Loop on the three other vertices */
  for (uint8_t lv = 0; lv < 4; ++lv) {
    /* Loop on the three branches of first vertex */
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
      tetSizes[3*lv+d] = sizemap[3*nodes[lv]+cb];
    }
  }

  sizes[0] = uv[0]*tetSizes[0] + uv[1]*tetSizes[3] + uv[2]*tetSizes[6] +uv[3]*tetSizes[9];
  sizes[1] = uv[0]*tetSizes[1] + uv[1]*tetSizes[4] + uv[2]*tetSizes[7] +uv[3]*tetSizes[10];
  sizes[2] = uv[0]*tetSizes[2] + uv[1]*tetSizes[5] + uv[2]*tetSizes[8] +uv[3]*tetSizes[11];
  
  sizes[3] = sizes[0];
  sizes[4] = sizes[1];
  sizes[5] = sizes[2];

  return HXT_STATUS_OK;
}


//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get coherent 3d scaled directions from 3d direction field 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetDirectionsScaled3d(HXTMesh *mesh, 
                                   const double *directions,
                                   const double *sizemap,
                                   uint64_t tet,
                                   double *uv,
                                   double *dir,
                                   double *sizes)
{

  // Check if vectors are 'smooth' 
  for (int i=0; i<4; i++){
    for (int j=0; j<3; j++){
      double vec[3];
      vec[0] = directions[9*mesh->tetrahedra.node[4*tet+i]+3*j+0];
      vec[1] = directions[9*mesh->tetrahedra.node[4*tet+i]+3*j+1];
      vec[2] = directions[9*mesh->tetrahedra.node[4*tet+i]+3*j+2];
      if (norm(vec) < 10e-12) return HXT_STATUS_OK;
    }
  }

  // Get coherent directions
  double tetVectors[4][9];
  HXT_CHECK(hxtGetCoherentDirectionsInTet(mesh,directions,tet,tetVectors));

  // Interpolate to current point
  for (int i=0; i<9; i++){
    dir[i] = uv[0] * tetVectors[0][i] + 
             uv[1] * tetVectors[1][i] + 
             uv[2] * tetVectors[2][i] + 
             uv[3] * tetVectors[3][i] ; 
  }

  // Opposite directions to construct all the frame 
  for (int i=9; i<18; i++)
    dir[i] = -dir[i-9];

  // Normalize directions
  for (int i=0; i<6; i++){
    normalize(&dir[3*i]);
  }

  HXT_CHECK(hxtGetCoherentSizes3d(mesh,directions,sizemap,tet,dir,uv,sizes));

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to interpolate 3d frames to a point 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtInterpolateFrame3d(HXTMesh *mesh, 
                                const double *directions,
                                const double *sizemap,
                                uint64_t tetra,
                                double *uv,
                                double *vectors,
                                double *sizes)
{
  // Check if vectors are 'smooth' 
  for (int i=0; i<4; i++){
    for (int j=0; j<3; j++){
      double vec[3];
      vec[0] = directions[9*mesh->tetrahedra.node[4*tetra+i]+3*j+0];
      vec[1] = directions[9*mesh->tetrahedra.node[4*tetra+i]+3*j+1];
      vec[2] = directions[9*mesh->tetrahedra.node[4*tetra+i]+3*j+2];
      if (norm(vec) < 10e-12) return HXT_STATUS_OK;
    }
  }

  // Assemble array with directions vectors for the triangle vertices
  // the fourth one is not taken into account 
  double triFrames[4*9];
  for (uint32_t i=0; i<4*9; i++) triFrames[i] = 0.;

  for (uint32_t i=0; i<4; i++){
    uint32_t v = mesh->tetrahedra.node[4*tetra+i];
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

  double frame[18];
  for (uint32_t i=0; i<18; i++) frame[i] = 0.;

  HXT_CHECK(hxtOr3DgetScaledCrossInTetFromDir(triFrames,uv,frame));
  sizes[0] = sizes[3] = norm(&frame[0]);
  sizes[1] = sizes[4] = norm(&frame[3]);
  sizes[2] = sizes[5] = norm(&frame[6]);
  normalize(&frame[0]);
  normalize(&frame[3]);
  normalize(&frame[6]);

  // Opposite directions to construct all the frame 
  for (int i=9; i<18; i++)
    frame[i] = -frame[i-9];

  // TODO return the frame  
  for (int i=0; i<18; i++)
    vectors[i] = frame[i];

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get coherent 3d directions from 3d direction field 
// Two ways: - InterpolateFrame slow but a bit more accurate
//           - GetDirectionsScaled faster
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetDirections3d(HXTMesh *mesh, 
                             const double *directions,
                             const double *sizemap,
                             uint64_t tetra,
                             double *uv,
                             double *vectors,
                             double *sizes)
{

  HXT_CHECK(hxtGetDirectionsScaled3d(mesh,directions,sizemap,tetra,uv,vectors,sizes));
  
  //HXT_CHECK(hxtInterpolateFrame3d(mesh,directions,sizemap,tetra,uv,vectors,sizes));

  return HXT_STATUS_OK; 
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to get the 'closest' direction to the input direction for a point
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtGetClosestDirection3d(HXTMesh *mesh, 
                                   const double *directions,
                                   const double *sizemap,
                                   uint64_t ct,
                                   double *uv,
                                   double *inDir,
                                   double *outDir,
                                   double *outSize)
{

  // Get frame at this point 
  double frame[6*3] = {0.};
  double sizes[6] = {0.};
  HXT_CHECK(hxtGetDirections3d(mesh,directions,sizemap,ct,uv,frame,sizes));
  //HXT_CHECK(hxtGetDirectionsScaled3d(mesh,directions,sizemap,ct,uv,frame,sizes));
  //HXT_CHECK(hxtInterpolateFrame3d(mesh,directions,sizemap,ct,uv,frame,sizes));

  // Find closest direction
  double dirMax[3] = {0.};
  double newDir[3] = {0.};
  double maxDot = 0;
  for (int k=0; k<6; k++){
    newDir[0] = frame[3*k+0];
    newDir[1] = frame[3*k+1];
    newDir[2] = frame[3*k+2];

    if (fabs(myDot(newDir,inDir))>maxDot){
      maxDot = fabs(myDot(newDir,inDir));
      double s = sign(myDot(newDir,inDir));
      dirMax[0] = s*newDir[0];
      dirMax[1] = s*newDir[1];
      dirMax[2] = s*newDir[2];
      *outSize = sizes[k];
    }
  } 

  outDir[0] = dirMax[0];
  outDir[1] = dirMax[1];
  outDir[2] = dirMax[2];
  normalize(outDir);

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find candidate point by walking inside volume 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtFindCandidatePoint3d(HXTMesh *mesh, 
                                  uint64_t startingTet,
                                  double *res,
                                  uint64_t *parent)
{

  uint64_t ct = startingTet;
  int walkIter = 0;
  int maxWalk = 100; // TODO 
  int walk = -100;
  *parent = UINT64_MAX;
  double uvl[4] = {0.,0.,0.,0.};

  while (walkIter < maxWalk){
    HXT_CHECK(hxtGetBarycentricTetra(mesh, ct, res, uvl));
    if      (uvl[0] < 0.) walk = 0;
    else if (uvl[1] < 0.) walk = 1;
    else if (uvl[2] < 0.) walk = 2;
    else if (uvl[3] < 0.) walk = 3;
    else walk = -1;

    if (walk == -1){
      *parent = ct;
      return HXT_STATUS_OK; 
    }
    else{
      if (walk < 0){
        *parent = UINT64_MAX;
        return HXT_STATUS_OK;
      }
      if (mesh->tetrahedra.neigh[4*ct+walk] == HXT_NO_ADJACENT){
        *parent = UINT64_MAX;
        return HXT_STATUS_OK;
        
      }
      ct = mesh->tetrahedra.neigh[4*ct+walk]/4; 
    }
    walkIter++;
  }

  return HXT_STATUS_OK;
}





//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find candidate point by walking inside volume 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePoint3d(HXTMesh *mesh, 
                                    double *originPoint,
                                    uint64_t originTet,
                                    double *dir,
                                    double size,
                                    double *res,
                                    uint64_t *parent)
{

  uint64_t ct = originTet;
  int walkIter = 0;
  int maxWalk = 100; // TODO 
  int walk = -100;
  *parent = UINT64_MAX;
  double uvl[4] = {0.,0.,0.,0.};

  res[0] = originPoint[0] + dir[0]*size; 
  res[1] = originPoint[1] + dir[1]*size; 
  res[2] = originPoint[2] + dir[2]*size; 

  while (walkIter < maxWalk){
    hxtGetBarycentricTetra(mesh, ct, res, uvl);
    if      (uvl[0] < 0.) walk = 0;
    else if (uvl[1] < 0.) walk = 1;
    else if (uvl[2] < 0.) walk = 2;
    else if (uvl[3] < 0.) walk = 3;
    else walk = -1;

    if (walk == -1){
      *parent = ct;
      return HXT_STATUS_OK; 
    }
    else{
      if (walk < 0){
        *parent = UINT64_MAX;
        return HXT_STATUS_OK;
      }
      if (mesh->tetrahedra.neigh[4*ct+walk] == HXT_NO_ADJACENT){
        *parent = UINT64_MAX;
        return HXT_STATUS_OK;
        
      }
      ct = mesh->tetrahedra.neigh[4*ct+walk]/4; 
    }
    walkIter++;
  }

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to find candidate point with a RungeKutta4 scheme
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtWalkToCandidatePoint3dRK4(HXTMesh *mesh, 
                                       const double *sizemap, 
                                       const double *directions,
                                       double *originPoint,
                                       uint64_t originTet,
                                       double *dir1,
                                       double size1,
                                       double *res,
                                       uint64_t *parent)
{
  // First
  double v1[3];
  v1[0] = size1*dir1[0];
  v1[1] = size1*dir1[1];
  v1[2] = size1*dir1[2];

  //-------------------------------------------------------------
  // Second
  
  double p2[3] = {0.,0.,0.};
  uint64_t tet2 = UINT64_MAX;
  HXT_CHECK(hxtWalkToCandidatePoint3d(mesh, originPoint, originTet, dir1, size1/2, p2, &tet2));

  if (tet2 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates
  double uv2[4];
  hxtGetBarycentricTetra(mesh, tet2, p2, uv2);

  // Get new frame and size
  double size2 = 0.;
  double dir2[3] = {0.,0.,0.,};
  HXT_CHECK(hxtGetClosestDirection3d(mesh, directions, sizemap, tet2, uv2, dir1, dir2, &size2));

  //-------------------------------------------------------------
  // Third
  
  double p3[3] = {0.,0.,0.};
  uint64_t tet3 = UINT64_MAX;
  HXT_CHECK(hxtWalkToCandidatePoint3d(mesh, originPoint, originTet, dir2, size2/2, p3, &tet3));

  if (tet3 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates
  double uv3[4];
  HXT_CHECK(hxtGetBarycentricTetra(mesh, tet3, p3, uv3));

  // Get new frame and size
  // Get size
  double size3 = 0.;
  double dir3[3] = {0.,0.,0.,};
  HXT_CHECK(hxtGetClosestDirection3d(mesh, directions, sizemap, tet3, uv3, dir2, dir3, &size3));

  //-------------------------------------------------------------
  // Fourth
  
  double p4[3] = {0.,0.,0.};
  uint64_t tet4 = UINT64_MAX;
  HXT_CHECK(hxtWalkToCandidatePoint3d(mesh, originPoint, originTet, dir3, size3, p4, &tet4));

  if (tet4 == UINT64_MAX) return HXT_STATUS_OK;

  // Get barycentric coordinates
  double uv4[4];
  HXT_CHECK(hxtGetBarycentricTetra(mesh, tet4, p4, uv4));

  // Get new frame and size
  // Get size
  double size4 = 0.;
  double dir4[3] = {0.,0.,0.,};
  HXT_CHECK(hxtGetClosestDirection3d(mesh, directions, sizemap, tet4, uv4, dir3, dir4, &size4));


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


  uint64_t tetFinal = UINT64_MAX;
  double pointFinal[3] = {0.,0.,0.};
  double sizeFinal = (size1+2*size2+2*size3+size4)/6.;

  double dirFinal[3] = {0.,0.,0.};
  dirFinal[0] = v1[0] + 2*v2[0] + 2*v3[0] + v4[0];
  dirFinal[1] = v1[1] + 2*v2[1] + 2*v3[1] + v4[1];
  dirFinal[2] = v1[2] + 2*v2[2] + 2*v3[2] + v4[2];
  normalize(dirFinal);

  HXT_CHECK(hxtWalkToCandidatePoint3d(mesh, originPoint, originTet, dirFinal, sizeFinal, pointFinal, &tetFinal));

  if (tetFinal == UINT64_MAX) return HXT_STATUS_OK;

 *parent = tetFinal;
  res[0] = pointFinal[0];
  res[1] = pointFinal[1];
  res[2] = pointFinal[2];

  return HXT_STATUS_OK;
}

//*************************************************************************************************
//*************************************************************************************************
//
// FUNCTION to filter aligned with the frame 3D 
//
//*************************************************************************************************
//*************************************************************************************************
HXTStatus hxtPointGenFilterAligned3d(HXTMesh *mesh,
                                     uint64_t ct,
                                     double *coords,
                                     double *pp, // candidate point
                                     double *frame,
                                     double *sizes,
                                     double threshold,
                                     void *data,
                                     void *dataTri,
                                     int *pass)
{
  //============================================================================
  // Define a box size to search from the maximum size
  double size =0;
  for (int i=0; i<3; i++)
    if (sizes[i]>size) size = sizes[i];

  double box = 1.5*size;

  double ppmin[3] = {pp[0] - box, pp[1] - box, pp[2] - box};
  double ppmax[3] = {pp[0] + box, pp[1] + box, pp[2] + box};
 

  //============================================================================
  // Find close surface triangles from RTree of triangles  
  // This is an addition for when sizemap inside of the domain differs 
  uint64_t numCloseTris = 0;
  uint64_t *idCloseTris = NULL;
  HXT_CHECK(hxtRTreeSearch64(ppmin,ppmax,&numCloseTris,&idCloseTris,dataTri));

  if (numCloseTris == 0){
  }
  else{
    for (uint64_t i=0; i<numCloseTris; i++){
      uint64_t tri = idCloseTris[i];
      double dist, closePt[3];
      int in = 0;
      HXT_CHECK(hxtSignedDistancePointTriangle(&mesh->vertices.coord[4*mesh->triangles.node[3*tri+0]],
                                               &mesh->vertices.coord[4*mesh->triangles.node[3*tri+1]],
                                               &mesh->vertices.coord[4*mesh->triangles.node[3*tri+2]],
                                               pp,
                                               &dist,
                                               &in,
                                               closePt));
      if (fabs(dist)<sizes[0]){
        *pass = 0;
        return HXT_STATUS_OK;
      }
    }
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
  double *dir3 = &frame[6];

  for (int i=0; i<numClose; i++){
    double *cp = coords + 4*idClose[i];

    // Project vector pp->cp to the two directions 
    double vec[3] = {cp[0]-pp[0],cp[1]-pp[1],cp[2]-pp[2]};

    double proj1 = myDot(vec,dir1);
    double proj2 = myDot(vec,dir2);
    double proj3 = myDot(vec,dir3);

    if (fabs(proj1)<threshold*sizes[0] && 
        fabs(proj2)<threshold*sizes[1] &&
        fabs(proj3)<threshold*sizes[2]){
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
HXTStatus hxtPointGenCorrection3d(HXTMesh *mesh,
                                  const double *sizemap,
                                  const double *directions,
                                  HXTPointGenParent *parent,   
                                  double *coords,
                                  uint32_t originPoint, 
                                  double *pp, // candidate point to be corrected
                                  uint64_t originTet,
                                  double *frame,
                                  double *sizes,
                                  void *data,
                                  double *cp, // corrected point
                                  uint64_t *parentNew)
  
{
  HXT_UNUSED(originPoint);

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
  double *dir3 = &frame[6];

  // Find close and aligned generated points
  double testBox = 1.2;
  uint32_t check = 0;
  uint32_t points[6] = {0};

  double correctionAngle = 0.98;
  double neighbourAngle = 0.98;

  FILE *oct;
  hxtPosInit("checkCorrectionPoints3d.pos","Neigh",&oct);
  hxtPosNewView(oct, "Candidate");
  hxtPosAddPoint(oct,pp,0);

  for (int i=0; i<numClose; i++){
    double *cp = coords + 4*idClose[i];

    // Project vector pp->cp to the two directions 
    double vec[3] = {cp[0]-pp[0],cp[1]-pp[1],cp[2]-pp[2]};

    double proj1 = myDot(vec,dir1);
    double proj2 = myDot(vec,dir2);
    double proj3 = myDot(vec,dir3);

    if (fabs(proj1)<testBox*sizes[0] && 
        fabs(proj2)<testBox*sizes[1] &&
        fabs(proj3)<testBox*sizes[2]){

      /*hxtPosNewView(oct, "Points %d", i );*/
      /*hxtPosAddPoint(oct,cp,0);*/
      /*hxtPosAddLine(oct,pp,cp,0);*/

      normalize(vec);

      if (fabs(myDot(vec,dir1)) > correctionAngle ||
          fabs(myDot(vec,dir2)) > correctionAngle ||
          fabs(myDot(vec,dir3)) > correctionAngle){
        points[check] = idClose[i];
        check++;
        if (check>6) break;
        hxtPosAddLine(oct,pp,cp,0);
      }

      // Check if we can construct vertices relationship
      if (fabs(myDot(vec,dir1)) > neighbourAngle || 
          fabs(myDot(vec,dir2)) > neighbourAngle ||
          fabs(myDot(vec,dir3)) > neighbourAngle){

        /*hxtPosNewView(oct, "Line %d", i );*/
        /*hxtPosAddLine(oct,pp,cp,0);*/

      }
    }
  }
  hxtPosFinish(oct);

  if (check == 0 || check>6){
    HXT_CHECK(hxtFree(&idClose));
    return HXT_STATUS_OK;
  }


  FILE *out;
  hxtPosInit("checkCorrectionPoints3dAligned.pos","Neigh",&out);
  hxtPosNewView(out, "Candidate");
  hxtPosAddPoint(out,pp,0);

  int count = 0;
  for (uint32_t i=0; i<check; i++){

    // Take aligned point 
    double *pn = coords + 4*points[i];

    // Take parent tetrahedron of origin point
    uint64_t tetn = UINT64_MAX;
    if (parent[points[i]].type != 4) continue;
    tetn = parent[points[i]].id;

    // Get barycentric coordinates 
    double uv[4];
    HXT_CHECK(hxtGetBarycentricTetra(mesh, tetn, pn, uv));

    // Get frame and sizes for point
    double sizes[6] = {0,};
    double frame[6*3] = {0.};
    HXT_CHECK(hxtGetDirections3d(mesh,directions,sizemap,tetn,uv,frame,sizes));
    //HXT_CHECK(hxtGetDirectionsScaled3d(mesh,directions,sizemap,tetn,uv,frame,sizes));
    //HXT_CHECK(hxtInterpolateFrame3d(mesh,directions,sizemap,tetn,uv,frame,sizes));

    double v[3] = {pp[0]-pn[0],pp[1]-pn[1],pp[2]-pn[2]};
    normalize(v);
    double dd[3] = {0.};
    double sizen = 0.;
    // Get new frame and size
    HXT_CHECK(hxtGetClosestDirection3d(mesh, directions, sizemap, tetn, uv, v, dd, &sizen));

    double candidaten[3] = {0.};
    uint64_t trin = UINT64_MAX;
    int walkCase = 0;
    if (walkCase == 0) 
      HXT_CHECK(hxtWalkToCandidatePoint3d(mesh, pn, tetn, dd, sizen, candidaten, &trin));
    if (walkCase == 1)
      HXT_CHECK(hxtWalkToCandidatePoint3dRK4(mesh, sizemap, directions, pn, tetn, dd, sizen, candidaten, &trin));

    if (trin == UINT64_MAX) continue;

    cp[0] += candidaten[0];
    cp[1] += candidaten[1];
    cp[2] += candidaten[2];
    count ++;

    hxtPosNewView(out, "Point %d",i);
    hxtPosAddPoint(out,candidaten,0);

  }

  if (count != 0){

    hxtPosNewView(out, "Corrected");
    cp[0] /= count;
    cp[1] /= count;
    cp[2] /= count;
    hxtPosAddPoint(out,cp,0);

    HXT_CHECK(hxtFindCandidatePoint3d(mesh,originTet,cp,parentNew));
  }


  hxtPosFinish(out);


  HXT_CHECK(hxtFree(&idClose));
  return HXT_STATUS_OK;
}








//*****************************************************************************************
//*****************************************************************************************
//
// FUNCTION to generate points on volumes 
//
//*****************************************************************************************
//*****************************************************************************************
HXTStatus hxtGeneratePointsOnVolumes(HXTMesh *mesh, 
                                     HXTPointGenOptions *opt,
                                     const double *sizemap, 
                                     const double *directions,
                                     HXTPointGenParent *parent,   
                                     HXTMesh *fmesh) 
{

  HXT_INFO("");
  HXT_INFO("========= Generating points on volumes ==========");
  HXT_INFO_COND(opt->verbosity>0,"");
  
  double threshold = 0.72; // TODO 

  // Points on surfaces are on fmesh
  // along with the parent information on parent 
  // that is either corner, line (boundary edge) or surface triangle
  
  clock_t time00 = clock();

  //********************************************************
  // Get tri2tet and lines2tet in order to find parent tetrahedra
  //********************************************************
  uint64_t *tri2tet;
  HXT_CHECK(hxtMalloc(&tri2tet,mesh->triangles.num*sizeof(uint64_t)));
  for (uint64_t i=0; i < mesh->triangles.num; i++) tri2tet[i] = UINT64_MAX;
  uint64_t *lines2tet;
  HXT_CHECK(hxtMalloc(&lines2tet,mesh->lines.num*sizeof(uint64_t)));
  for (uint64_t i=0; i < mesh->lines.num; i++) lines2tet[i] = UINT64_MAX;
  HXT_CHECK(hxtGetTrianglesToTetrahedra(mesh,tri2tet,lines2tet));

  clock_t time01 = clock();
  double time_estimate = (double)(time01-time00) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create tri2tet  %f", time_estimate); 

  

  // TODO two functions doing the same - check 

/*  clock_t time11 = clock();*/
  /*uint64_t *tri2tetTEST;*/
  /*HXT_CHECK(hxtMalloc(&tri2tetTEST,mesh->triangles.num*sizeof(uint64_t)));*/
  /*for (uint64_t i=0; i < mesh->triangles.num; i++) tri2tetTEST[i] = UINT64_MAX;*/
  /*uint64_t missing;*/
  /*HXT_CHECK(hxtGetTri2TetMap(mesh,tri2tet,&missing));*/
  /*HXT_INFO_COND(opt->verbosity>0,"Missing = %lu", missing);*/
  /*clock_t time12 = clock();*/
  /*time_estimate = (double)(time12-time11) / CLOCKS_PER_SEC;*/
  /*HXT_INFO_COND(opt->verbosity>0,"Time to create tri2tet TEST  %f", time_estimate); */

  /*for (uint64_t i=0; i<mesh->triangles.num; i++){*/
    /*tri2tet[i] = tri2tet[i]/4;*/
  /*}*/
  /*HXT_CHECK(hxtFree(&tri2tetTEST));*/


  //********************************************************
  // Create RTree for filtering 
  //********************************************************
  double tol = 10e-16; // TODO 
  void* data;
  HXT_CHECK(hxtRTreeCreate(&data));
  // Add line points in RTree
  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    double *cp = fmesh->vertices.coord + 4*i ; 
    HXT_CHECK(hxtAddPointInRTree(cp,tol,i,data));
  }

  clock_t time02 = clock();
  time_estimate = (double)(time02-time01) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create rtree          %f", time_estimate); 


  // A second auxillary rtree for surface triangles
  
  tol = 10e-16; // TODO 
  void *dataTri;
  HXT_CHECK(hxtRTreeCreate64(&dataTri));
  for (uint64_t i=0; i<mesh->triangles.num; i++){
    double *p0 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+0];
    double *p1 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+1];
    double *p2 = mesh->vertices.coord + 4*mesh->triangles.node[3*i+2];
    HXT_CHECK(hxtAddTriangleInRTree64(p0,p1,p2,tol,i,dataTri));
  }

  clock_t time02b = clock();
  time_estimate = (double)(time02b-time02) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to create rtree for tri  %f", time_estimate);


  //********************************************************
  // Queue-like loop to generate points
  //********************************************************
  HXT_INFO("");
  HXT_INFO_COND(opt->walkMethod3D==0,"Walking method to candidate point - simple");
  HXT_INFO_COND(opt->walkMethod3D==1,"Walking method to candidate point - RungeKutta4");


  uint32_t numGenPoints = 0;
  numGenPoints += fmesh->vertices.num;

  for (uint32_t i=0; i<fmesh->vertices.num; i++){
    
    // Take coordinates of origin point
    double *originPoint = fmesh->vertices.coord + 4*i;

    // Take parent tetrahedron of origin point
    uint64_t originTet = UINT64_MAX;
    if (parent[i].type == 2){
      uint64_t originTri = parent[i].id;
      originTet = tri2tet[originTri];
    }
    else if (parent[i].type == 1){
      uint64_t originLine = parent[i].id;
      originTet = lines2tet[originLine];
    }
    else if (parent[i].type == 15){
      originTet = 0;
    }
    else if (parent[i].type == 4){
      originTet = parent[i].id;
    }
    else 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Wrong parent type in volume point generation");
    if (originTet == UINT64_MAX) 
      return HXT_ERROR_MSG(HXT_STATUS_ERROR,"Could not get tetrahedron parent");
      

    // Get barycentric coordinates 
    double uv[4];
    HXT_CHECK(hxtGetBarycentricTetra(mesh, originTet, originPoint, uv));

    // Get frame and sizes for point
    double sizes[6] = {0,};
    double frame[6*3] = {0.};
    HXT_CHECK(hxtGetDirections3d(mesh,directions,sizemap,originTet,uv,frame,sizes));
    //HXT_CHECK(hxtGetDirectionsScaled3d(mesh,directions,sizemap,originTet,uv,frame,sizes));
    //HXT_CHECK(hxtInterpolateFrame3d(mesh,directions,sizemap,originTet,uv,frame,sizes));
    
    // Find new points for 6 directions
    for (int nb=0; nb < 6; nb++){

      double dir[3] = {frame[3*nb+0], frame[3*nb+1], frame[3*nb+2]};
      double size = sizes[nb];


      //*******************************************
      // Find point by walking in volume 
      //*******************************************
      
      double candidate[3] = {0.,0.,0.};
      uint64_t ct = UINT64_MAX;

      
      if (opt->walkMethod3D == 0) 
        HXT_CHECK(hxtWalkToCandidatePoint3d(mesh, originPoint, originTet, dir, size, candidate, &ct));

      if (opt->walkMethod3D == 1) 
        HXT_CHECK(hxtWalkToCandidatePoint3dRK4(mesh, sizemap, directions, originPoint, originTet, dir, size, candidate, &ct));

      if (ct == UINT64_MAX) continue;

      //********************
      // Filtering 
      //********************
      int insert = 1;


      // Get barycentric coordinates for candidate point 
      double uvCandidate[4];
      HXT_CHECK(hxtGetBarycentricTetra(mesh, ct, candidate, uvCandidate));

      // Get frame and sizes for point
      double sizesCandidate[6] = {0,};
      double frameCandidate[6*3] = {0.};
      HXT_CHECK(hxtGetDirections3d(mesh,directions,sizemap,ct,uvCandidate,frameCandidate,sizesCandidate));
      //HXT_CHECK(hxtGetDirectionsScaled3d(mesh,directions,sizemap,ct,uvCandidate,frameCandidate,sizesCandidate));
      //HXT_CHECK(hxtInterpolateFrame3d(mesh,directions,sizemap,ct,uvCandidate,frameCandidate,sizesCandidate));

      // FILTERING 
      //HXT_CHECK(hxtPointGenFilter(fmesh->vertices.coord,candidate,size,threshold,data,&insert));
      HXT_CHECK(hxtPointGenFilterAligned3d(mesh,
                                           ct,
                                           fmesh->vertices.coord,
                                           candidate,
                                           frameCandidate,
                                           sizesCandidate,
                                           threshold,
                                           data,
                                           dataTri,
                                           &insert));

      // (function of correction)
      // TODO 
      int flagCorrection = 0;
      if (insert && flagCorrection){

        double candidateNew[3] = {0.};
        uint64_t parentNew = UINT64_MAX;
        HXT_CHECK(hxtPointGenCorrection3d(mesh, sizemap, directions, parent, fmesh->vertices.coord,
                                          i, candidate, ct, frameCandidate, sizesCandidate, data, candidateNew, &parentNew));
  
        if (parentNew != UINT64_MAX){
          ct = parentNew;
          candidate[0] = candidateNew[0];
          candidate[1] = candidateNew[1];
          candidate[2] = candidateNew[2];
  
        }

        // Get barycentric coordinates for candidate point 
        double uvCandidate[4];
        HXT_CHECK(hxtGetBarycentricTetra(mesh, ct, candidate, uvCandidate));
  
        // Get frame and sizes for point
        double sizesCandidate[6] = {0,};
        double frameCandidate[6*3] = {0.};
        HXT_CHECK(hxtGetDirections3d(mesh,directions,sizemap,ct,uvCandidate,frameCandidate,sizesCandidate));
        //HXT_CHECK(hxtGetDirectionsScaled3d(mesh,directions,sizemap,ct,uvCandidate,frameCandidate,sizesCandidate));
        //HXT_CHECK(hxtInterpolateFrame3d(mesh,directions,sizemap,ct,uvCandidate,frameCandidate,sizesCandidate));
  
        // FILTERING corrected point 
        //HXT_CHECK(hxtPointGenFilter(fmesh->vertices.coord,candidate,size,threshold,data,&insert));
        HXT_CHECK(hxtPointGenFilterAligned3d(mesh,
                                             ct,
                                             fmesh->vertices.coord,
                                             candidate,
                                             frameCandidate,
                                             sizesCandidate,
                                             threshold,
                                             data,
                                             dataTri,
                                             &insert));

      }


      // If is not filtered, insert the point
      if(insert){
        fmesh->vertices.coord[4*numGenPoints+0] = candidate[0];
        fmesh->vertices.coord[4*numGenPoints+1] = candidate[1];
        fmesh->vertices.coord[4*numGenPoints+2] = candidate[2];
        parent[numGenPoints].type = 4; 
        parent[numGenPoints].id= ct;
        HXT_CHECK(hxtAddPointInRTree(candidate,tol,numGenPoints,data));
        fmesh->vertices.num++;
        numGenPoints++;
      }

    }
 
    // Terminating condition 
    if (i > numGenPoints-2) break;
  
  }

  clock_t time03 = clock();
  time_estimate = (double)(time03-time02) / CLOCKS_PER_SEC;
  HXT_INFO_COND(opt->verbosity>0,"Time to generate points  %f", time_estimate); 

  // Cleaning things 
  HXT_CHECK(hxtRTreeDelete(&data));
  HXT_CHECK(hxtRTreeDelete(&dataTri));
  HXT_CHECK(hxtFree(&tri2tet));
  HXT_CHECK(hxtFree(&lines2tet));

  


  return HXT_STATUS_OK;
}


