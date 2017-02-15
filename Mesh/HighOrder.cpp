// Gmsh - Copyright (C) 1997-2017 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@onelab.info>.
//
// Contributor(s):
//   Koen Hillewaert
//

#include "HighOrder.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "MTetrahedron.h"
#include "MHexahedron.h"
#include "MPrism.h"
#include "MPyramid.h"
#include "GmshMessage.h"
#include "OS.h"
#include "Numeric.h"
#include "Context.h"
#include "fullMatrix.h"
#include "BasisFactory.h"
#include "MVertexRTree.h"

#include <sstream>

// --------- Functions that help optimizing placement of points on geometry -----------

// The aim here is to build a polynomial representation that consist
// in polynomial segments of equal length

static double mylength(GEdge *ge, int i, double *u)
{
  return ge->length(u[i], u[i+1], 10);
}

static void myresid(int N, GEdge *ge, double *u, fullVector<double> &r)
{
  double L[100];
  for (int i = 0; i < N - 1; i++) L[i] = mylength(ge, i, u);
  for (int i = 0; i < N - 2; i++) r(i) = L[i + 1] - L[i];
}

static bool computeEquidistantParameters(GEdge *ge, double u0, double uN, int N,
                                         double *u, double underRelax)
{
  const double PRECISION = 1.e-6;
  const int MAX_ITER = 50;
  const double eps = (uN - u0) * 1.e-5;

  // newton algorithm
  // N is the total number of points (3 for quadratic, 4 for cubic ...)
  // u[0] = u0;
  // u[N-1] = uN;
  // initialize as equidistant in parameter space
  u[0] = u0;
  double du = (uN - u0) / (N - 1);
  for (int i = 1; i < N; i++){
    u[i] = u[i - 1] + du;
  }

  //return true;

  // create the tangent matrix
  const int M = N - 2;
  fullMatrix<double> J(M, M);
  fullVector<double> DU(M);
  fullVector<double> R(M);
  fullVector<double> Rp(M);

  int iter = 1;

  while (iter < MAX_ITER){
    iter++;
    myresid(N, ge, u, R);

    for (int i = 0; i < M; i++){
      u[i + 1] += eps;
      myresid(N, ge, u, Rp);
      for (int j = 0; j < M; j++){
        J(i, j) = (Rp(j) - R(j)) / eps;
      }
      u[i+1] -= eps;
    }

    if (M == 1)
      DU(0) = R(0) / J(0, 0);
    else
      J.luSolve(R, DU);

    for (int i = 0; i < M; i++){
      u[i+1] -= underRelax*DU(i);
    }

    if (u[1] < u0) break;
    if (u[N - 2] > uN) break;

    double newt_norm = DU.norm();
    if (newt_norm < PRECISION) {
      return true;
    }
  }
  return false;
}

static bool computeEquidistantParameters(GFace *gf, double u0, double uN,
                                         double v0, double vN, SPoint3 &p0,
                                         SPoint3 &pN, int N, bool geodesic,
                                         double *u, double *v)
{
  const int NI = N-1;
  u[0] = u0; v[0] = v0;
  u[NI] = uN; v[NI] = vN;
  const double fact = 1./(double)NI;
  for (int i = 1; i < NI; i++){
    const double t = i*fact;
    u[i] = u0 + (uN-u0)*t;
    v[i] = v0 + (vN-v0)*t;
    if (geodesic) {
      SPoint3 pc(t*pN + (1.-t)*p0);
      double guess[2] = {u[i], v[i]};
      GPoint gp = gf->closestPoint(pc, guess);
      if(gp.succeeded()){
        u[i] = gp.u();
        v[i] = gp.v();
      }
    }
  }
  return true;
}

// --------- Creation of high-order edge vertices -----------

static bool getEdgeVerticesonGeo(GEdge *ge, MVertex *v0, MVertex *v1,
                                 std::vector<MVertex*> &ve, int nPts = 1)
{
  static const double relaxFail = 1e-2;
  double u0 = 0., u1 = 0., US[100];
  bool reparamOK = reparamMeshVertexOnEdge(v0, ge, u0);
  if(ge->periodic(0) && ge->getEndVertex()->getNumMeshVertices() > 0 &&
     v1 == ge->getEndVertex()->mesh_vertices[0])
    u1 = ge->parBounds(0).high();
  else
    reparamOK &= reparamMeshVertexOnEdge(v1, ge, u1);

  if (reparamOK) {
    double uMin = std::min(u0, u1), uMax = std::max(u0, u1);
    bool failed = true;
    double relax = 1.;
    while (failed && (relax > relaxFail)) {
      failed = !computeEquidistantParameters(ge, uMin, uMax, nPts + 2, US, relax);
      relax *= 0.5;
    }
    if (failed) {
      Msg::Warning
        ("Failed to compute equidistant parameters (relax = %g, value = %g) "
         "for edge %d-%d parametrized with %g %g on GEdge %d",
         relax, US[1], v0->getNum(), v1->getNum(),u0,u1,ge->tag());
      US[0] = uMin;
      const double du = (uMax - uMin) / (nPts+1);
      for (int i = 1; i <= nPts; i++) US[i] = US[i - 1] + du;
    }
  }
  else
    Msg::Error("Cannot reparam a mesh Vertex in high order meshing");
  if (!reparamOK) return false;

  for(int j = 0; j < nPts; j++) {
    MVertex *v;
    int count = u0<u1? j + 1 : nPts + 1  - (j + 1);
    GPoint pc = ge->point(US[count]);
    v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge,US[count]);
    // this destroys the ordering of the mesh vertices on the edge
    ve.push_back(v);
  }

  return true;
}

static bool getEdgeVerticesonGeo(GFace *gf, MVertex *v0, MVertex *v1,
                                 std::vector<MVertex*> &ve, int nPts = 1)
{
  SPoint2 p0, p1;
  double US[100], VS[100];
  bool reparamOK = reparamMeshEdgeOnFace(v0, v1, gf, p0, p1);
  if(reparamOK) {
    SPoint3 pnt0, pnt1;
    if (nPts >= 30)
      computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1],
                                   pnt0, pnt1, nPts + 2, false, US, VS);
    else {
      pnt0 = v0->point();
      pnt1 = v1->point();
      // FIXME: using the geodesic is sometimes a bad idea when the edge is "far
      // away" from the surface (e.g. on the diameter of a circle!)
      computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1],
                                   pnt0, pnt1, nPts + 2, true, US, VS);
    }
  }
  else {
    Msg::Error("Cannot reparam a mesh Vertex in high order meshing");
    return false;
  }

  for(int j = 0; j < nPts; j++){
    GPoint pc = gf->point(US[j + 1], VS[j + 1]);
    MVertex *v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, US[j + 1], VS[j + 1]);
    ve.push_back(v);
  }

  return true;
}

static void interpVerticesInExistingEdge(GEntity *ge, const MElement *edgeEl,
                                         std::vector<MVertex*> &veEdge, int nPts)
{
  fullMatrix<double> points;
  points = edgeEl->getFunctionSpace(nPts+1)->points;
  for(int k = 2; k < nPts+2; k++) {
    SPoint3 pos;
    edgeEl->pnt(points(k, 0), 0., 0., pos);
    MVertex* v = new MVertex(pos.x(), pos.y(), pos.z(), ge);
    veEdge.push_back(v);
  }
}

inline static bool getMinMaxVert(MVertex *v0, MVertex *v1, MVertex *&vMin, MVertex *&vMax)
{
  const bool increasing = (v0->getNum() < v1->getNum());
  if (increasing) {
    vMin = v0; vMax = v1;
  }
  else {
    vMin = v1; vMax = v0;
  }
  return increasing;
}

// Get new interior vertices for a 1D element
static void getEdgeVertices(GEdge *ge, MElement *ele, std::vector<MVertex*> &ve,
                            std::vector<MVertex*> &newHOVert, edgeContainer &edgeVertices,
                            bool linear, int nPts = 1)
{
  if(ge->geomType() == GEntity::DiscreteCurve ||
     ge->geomType() == GEntity::BoundaryLayerCurve ||
     ge->geomType() == GEntity::CompoundCurve)
    linear = true;

  std::vector<MVertex*> veOld;
  ele->getVertices(veOld);
  MVertex *vMin, *vMax;
  const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
  std::pair<MVertex*, MVertex*> p(vMin, vMax);
  std::vector<MVertex*> veEdge;
  // Get vertices on geometry if asked
  bool gotVertOnGeo = linear ? false :
    getEdgeVerticesonGeo(ge, veOld[0], veOld[1], veEdge, nPts);
  // If not on geometry, create from mesh interpolation
  if (!gotVertOnGeo)
    interpVerticesInExistingEdge(ge, ele, veEdge, nPts);
  newHOVert.insert(newHOVert.end(), veEdge.begin(), veEdge.end());
  if (edgeVertices.count(p) == 0) {
    if (increasing) // Add newly created vertices to list
      edgeVertices[p].insert(edgeVertices[p].end(), veEdge.begin(), veEdge.end());
    else
      edgeVertices[p].insert(edgeVertices[p].end(), veEdge.rbegin(), veEdge.rend());
  }
  else {  // Vertices already exist
    Msg::Error("Edges from different entities share vertices: create a finer mesh");
  }
  ve.insert(ve.end(), veEdge.begin(), veEdge.end());
}

// Get new interior vertices for an edge in a 2D element
static void getEdgeVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &ve,
                            std::vector<MVertex*> &newHOVert, edgeContainer &edgeVertices,
                            bool linear, int nPts = 1)
{
  if(gf->geomType() == GEntity::DiscreteSurface ||
     gf->geomType() == GEntity::BoundaryLayerSurface ||
     gf->geomType() == GEntity::CompoundSurface)
    linear = true;

  for(int i = 0; i < ele->getNumEdges(); i++) {
    std::vector<MVertex*> veOld;
    ele->getEdgeVertices(i,veOld);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
    std::pair<MVertex*, MVertex*> p(vMin, vMax);
    std::vector<MVertex*> veEdge;
    if(edgeVertices.count(p)) { // Vertices already exist
      if(increasing)
        veEdge.assign(edgeVertices[p].begin(), edgeVertices[p].end());
      else
        veEdge.assign(edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else { // Vertices do not exist, create them
      // Get vertices on geometry if asked
      bool gotVertOnGeo = linear ? false :
        getEdgeVerticesonGeo(gf, veOld[0], veOld[1], veEdge, nPts);
      if (!gotVertOnGeo) {
        // If not on geometry, create from mesh interpolation
        const MLineN edgeEl(veOld, ele->getPolynomialOrder());
        interpVerticesInExistingEdge(gf, &edgeEl, veEdge, nPts);
      }
      newHOVert.insert(newHOVert.end(), veEdge.begin(), veEdge.end());
      if(increasing) // Add newly created vertices to list
        edgeVertices[p].insert(edgeVertices[p].end(), veEdge.begin(), veEdge.end());
      else
        edgeVertices[p].insert(edgeVertices[p].end(), veEdge.rbegin(), veEdge.rend());
    }
    ve.insert(ve.end(), veEdge.begin(), veEdge.end());
  }
}

// Get new interior vertices for an edge in a 3D element
static void getEdgeVertices(GRegion *gr, MElement *ele, std::vector<MVertex*> &ve,
                            std::vector<MVertex*> &newHOVert,
                            edgeContainer &edgeVertices,
                            bool linear, int nPts = 1)
{
  for(int i = 0; i < ele->getNumEdges(); i++) {
    std::vector<MVertex*> veOld;
    ele->getEdgeVertices(i,veOld);
    MVertex *vMin, *vMax;
    const bool increasing = getMinMaxVert(veOld[0], veOld[1], vMin, vMax);
    std::pair<MVertex*, MVertex*> p(vMin, vMax);
    std::vector<MVertex*> veEdge;
    if(edgeVertices.count(p)) { // Vertices already exist
      if(increasing)
        veEdge.assign(edgeVertices[p].begin(), edgeVertices[p].end());
      else
        veEdge.assign(edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else { // Vertices do not exist, create them
      const MLineN edgeEl(veOld, ele->getPolynomialOrder());
      interpVerticesInExistingEdge(gr, &edgeEl, veEdge, nPts);
      newHOVert.insert(newHOVert.end(), veEdge.begin(), veEdge.end());
      if(increasing) // Add newly created vertices to list
        edgeVertices[p].insert(edgeVertices[p].end(), veEdge.begin(), veEdge.end());
      else
        edgeVertices[p].insert(edgeVertices[p].end(), veEdge.rbegin(), veEdge.rend());
    }
    ve.insert(ve.end(), veEdge.begin(), veEdge.end());
  }
}

// --------- Creation of high-order face vertices -----------

static void reorientTrianglePoints(std::vector<MVertex*> &vtcs, int orientation,
                                   bool swap)
{
  int nbPts = vtcs.size();
  if (nbPts <= 1) return;
  std::vector<MVertex*> tmp(nbPts);
  int interiorOrder = (int)((sqrt(1. + 8. * nbPts) - 3) / 2);
  int pos = 0;
  for (int o = interiorOrder; o>0; o-=3) {
    if (swap) {
      tmp[pos] = vtcs[pos];
      tmp[pos+1] = vtcs[pos+2];
      tmp[pos+2] = vtcs[pos+1];
      for (int i = 0; i < 3*(o-1); i++)
        tmp[pos+3+i] = vtcs[pos+3*o-i-1];
    }
    else {
      for (int i = 0; i < 3*o; i++)
        tmp[pos+i] = vtcs[pos+i];
    }
    for (int i = 0; i < 3; i++) {
      int ri = (i+orientation)%3;
      vtcs[pos+ri] = tmp[pos+i];
      for (int j = 0; j < o-1; j++)
        vtcs[pos+3+(o-1)*ri+j] = tmp[pos+3+(o-1)*i+j];
    }
    pos += 3*o;
  }
}

static void reorientQuadPoints(std::vector<MVertex*> &vtcs, int orientation,
                               bool swap, int order)
{
  int nbPts = vtcs.size();
  if (nbPts <= 1) return;
  std::vector<MVertex*> tmp(nbPts);

  int start = 0;
  while (1){
    // CORNERS
    int index = 0;
    if (order == 0){
      start++;
    }
    else{
      int i1(0),i2(0),i3(0),i4(0);
      if (!swap){
        if      (orientation == 0){ i1 = 0; i2 = 1; i3 = 2; i4 = 3; }
        else if (orientation == 1){ i1 = 3; i2 = 0; i3 = 1; i4 = 2; }
        else if (orientation == 2){ i1 = 2; i2 = 3; i3 = 0; i4 = 1; }
        else if (orientation == 3){ i1 = 1; i2 = 2; i3 = 3; i4 = 0; }
      }
      else{
        if      (orientation == 0){ i1 = 0; i2 = 3; i3 = 2; i4 = 1; }
        else if (orientation == 3){ i1 = 3; i2 = 2; i3 = 1; i4 = 0; }
        else if (orientation == 2){ i1 = 2; i2 = 1; i3 = 0; i4 = 3; }
        else if (orientation == 1){ i1 = 1; i2 = 0; i3 = 3; i4 = 2; }
      }

      int indices[4] = {i1, i2, i3, i4};
      for (int i = 0; i < 4; i++) tmp[i] = vtcs[start + indices[i]];
      for (int i = 0; i < 4; i++) vtcs[start + i] = tmp[i];

      // EDGES
      for (int iEdge=0;iEdge<4;iEdge++){
        int p1 = indices[iEdge];
        int p2 = indices[(iEdge+1)%4];
        int nbP = order-1;
        if      (p1 == 0 && p2 == 1){
          for (int i = 4+0*nbP; i < 4+1*nbP; i++) tmp[index++] = vtcs[i];
        }
        else if (p1 == 1 && p2 == 2){
          for (int i = 4+1*nbP; i< 4+2*nbP; i++) tmp[index++] = vtcs[i];
        }
        else if (p1 == 2 && p2 == 3){
          for (int i = 4+2*nbP; i< 4+3*nbP; i++) tmp[index++] = vtcs[i];
        }
        else if (p1 == 3 && p2 == 0){
          for (int i = 4+3*nbP; i< 4+4*nbP; i++) tmp[index++] = vtcs[i];
        }
        else if (p1 == 1 && p2 == 0){
          for (int i = 4+1*nbP-1; i >= 4+0*nbP; i--) tmp[index++] = vtcs[i];
        }
        else if (p1 == 2 && p2 == 1){
          for (int i = 4+2*nbP-1; i >= 4+1*nbP; i--) tmp[index++] = vtcs[i];
        }
        else if (p1 == 3 && p2 == 2){
          for (int i = 4+3*nbP-1; i >= 4+2*nbP; i--) tmp[index++] = vtcs[i];
        }
        else if (p1 == 0 && p2 == 3){
          for (int i = 4+4*nbP-1; i >= 4+3*nbP; i--) tmp[index++] = vtcs[i];
        }
        else Msg::Error("Something wrong in reorientQuadPoints");
      }
      for (int i = 0; i < index; i++)vtcs[start+4+i] = tmp[i];
      start += (4 + index);
    }

    order -= 2;
    if (start >= (int) vtcs.size()) break;
  }
}

static int getNewFacePointsInVolume(MElement *incomplete, int nPts,
                                    fullMatrix<double> &points)
{
  int startFace = 0;

  switch (incomplete->getType()){
  case TYPE_TET :
    switch (nPts){
    case 0:
    case 1: return -1;
    case 2: points = BasisFactory::getNodalBasis(MSH_TET_20)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_TET_35)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_TET_56)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_TET_84)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_TET_120)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_TET_165)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_TET_220)->points; break;
    case 9: points = BasisFactory::getNodalBasis(MSH_TET_286)->points; break;
    default:
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startFace = 4 + nPts*6;
    break;
  case TYPE_HEX :
    switch (nPts){
    case 0: return -1;
    case 1: points = BasisFactory::getNodalBasis(MSH_HEX_27)->points; break;
    case 2: points = BasisFactory::getNodalBasis(MSH_HEX_64)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_HEX_125)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_HEX_216)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_HEX_343)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_HEX_512)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_HEX_729)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_HEX_1000)->points; break;
    default :
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startFace = 8 + nPts*12 ;
    break;
  case TYPE_PRI :
    switch (nPts){
    case 0: return -1;
    case 1: points = BasisFactory::getNodalBasis(MSH_PRI_18)->points; break;
    case 2: points = BasisFactory::getNodalBasis(MSH_PRI_40)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_PRI_75)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_PRI_126)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_PRI_196)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_PRI_288)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_PRI_405)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_PRI_550)->points; break;
    default:
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startFace = 6 + nPts*9;
    break;
  case TYPE_PYR:
    switch (nPts){
    case 0:
    case 1: return -1;
    case 2: points = BasisFactory::getNodalBasis(MSH_PYR_30)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_PYR_55)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_PYR_91)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_PYR_140)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_PYR_204)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_PYR_285)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_PYR_385)->points; break;
    default :
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startFace = 5 + nPts*8;
    break;

  }

  return startFace;
}

static void getFaceVerticesOnGeo(GFace *gf, MElement *incomplete, const MElement *faceEl,
                                 std::vector<MVertex*> &vf, int nPts = 1)
{
  SPoint2 pts[1000];
  bool reparamOK = true;
  for(int k = 0; k < incomplete->getNumVertices(); k++)
    reparamOK &= reparamMeshVertexOnFace(incomplete->getVertex(k), gf, pts[k]);
  fullMatrix<double> points;
  int start = (faceEl->getType() == 3) ? 3 * (1 + nPts) : 4 * (1 + nPts);
  points = faceEl->getFunctionSpace(nPts+1)->points;
  for(int k = start; k < points.size1(); k++) {
    MVertex *v;
    const double t1 = points(k, 0);
    const double t2 = points(k, 1);
    double X(0), Y(0), Z(0), GUESS[2] = {0, 0};
    double sf[1256];
    incomplete->getShapeFunctions(t1, t2, 0, sf);
    for (int j = 0; j < incomplete->getNumShapeFunctions(); j++){
      MVertex *vt = incomplete->getShapeFunctionNode(j);
      X += sf[j] * vt->x();
      Y += sf[j] * vt->y();
      Z += sf[j] * vt->z();
      if (reparamOK){
        GUESS[0] += sf[j] * pts[j][0];
        GUESS[1] += sf[j] * pts[j][1];
      }
    }
    if(reparamOK){
      GPoint gp = gf->point(SPoint2(GUESS[0], GUESS[1]));
      // closest point is not necessary (slow and for high quality HO
      // meshes it should be optimized anyway afterwards + closest point
      // is still buggy (e.g. BFGS for a plane "Ruled Surface")
      // GPoint gp = gf->closestPoint(SPoint3(X, Y, Z), GUESS);
      if (gp.g()){
        v = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
      }
      else{
        v = new MVertex(X, Y, Z, gf);
      }
    }
    else{
      GPoint gp = gf->closestPoint(SPoint3(X, Y, Z), GUESS);
      if(gp.succeeded())
        v = new MVertex(gp.x(), gp.y(), gp.z(), gf);
      else
        v = new MVertex(X, Y, Z, gf);
    }
    vf.push_back(v);
  }
}

static void interpVerticesInExistingFace(GEntity *ge, const MElement *faceEl,
                                         std::vector<MVertex*> &veFace, int nPts)
{
  fullMatrix<double> points;
  int start = (faceEl->getType() == 3) ? 3 * (1 + nPts) : 4 * (1 + nPts);
  points = faceEl->getFunctionSpace(nPts+1)->points;
  for (int k = start; k < points.size1(); k++) {
    double t1 = points(k, 0);
    double t2 = points(k, 1);
    SPoint3 pos;
    faceEl->pnt(t1, t2, 0, pos);
    MVertex* v = new MVertex(pos.x(), pos.y(), pos.z(), ge);
    veFace.push_back(v);
  }
}

// Get new interior vertices for a 2D element
static void getFaceVertices(GFace *gf, MElement *incomplete, MElement *ele,
                            std::vector<MVertex*> &vf, std::vector<MVertex*> &newHOVert,
                            faceContainer &faceVertices, bool linear, int nPts = 1)
{
  if(gf->geomType() == GEntity::DiscreteSurface ||
     gf->geomType() == GEntity::BoundaryLayerSurface ||
     gf->geomType() == GEntity::CompoundSurface)
    linear = true;

  MFace face = ele->getFace(0);
  std::vector<MVertex*> veFace;
  if (!linear) // Get vertices on geometry if asked...
    getFaceVerticesOnGeo(gf, incomplete, ele, veFace, nPts);
  else // ... otherwise, create from mesh interpolation
    interpVerticesInExistingFace(gf, ele, veFace, nPts);
  newHOVert.insert(newHOVert.end(), veFace.begin(), veFace.end());
  faceVertices[face].insert(faceVertices[face].end(), veFace.begin(), veFace.end());
  vf.insert(vf.end(), veFace.begin(), veFace.end());
}

// Get new face (excluding edge) vertices for a face of a 3D element
static void getFaceVertices(GRegion *gr, MElement *incomplete, MElement *ele,
                            std::vector<MVertex*> &vf, std::vector<MVertex*> &newHOVert,
                            faceContainer &faceVertices, edgeContainer &edgeVertices,
                            bool linear, int nPts = 1)
{
  fullMatrix<double> points;
  int startFace = incomplete ? getNewFacePointsInVolume(incomplete, nPts, points) : 0;
  int index = startFace;
  for(int i = 0; i < ele->getNumFaces(); i++) {
    MFace face = ele->getFace(i);
    int numVert = (face.getNumVertices() == 3) ? nPts * (nPts-1) / 2 : nPts * nPts;
    std::vector<MVertex*> veFace;
    faceContainer::iterator fIter = faceVertices.find(face);
    if(fIter != faceVertices.end()){ // Vertices already exist
      std::vector<MVertex*> vtcs = fIter->second;
      int orientation;
      bool swap;
      if (fIter->first.computeCorrespondence(face, orientation, swap)) {
        // Check correspondence and apply permutation if needed
        if(face.getNumVertices() == 3 && nPts > 1)
          reorientTrianglePoints(vtcs, orientation, swap);
        else if(face.getNumVertices() == 4)
          reorientQuadPoints(vtcs, orientation, swap, nPts-1);
      }
      else
        Msg::Error("Error in face lookup for recuperation of high order face nodes");
      veFace.assign(vtcs.begin(), vtcs.end());
    }
    else { // Vertices do not exist, create them by interpolation
      if (linear) { // Interpolate on existing mesh
        std::vector<MVertex*> vfOld;
        ele->getFaceVertices(i,vfOld);
        MElement *faceEl;
        if (face.getNumVertices() == 3)
          faceEl = new MTriangleN(vfOld, ele->getPolynomialOrder());
        else
          faceEl = new MQuadrangleN(vfOld, ele->getPolynomialOrder());
        interpVerticesInExistingFace(gr, faceEl, veFace, nPts);
        delete faceEl;
      }
      else {
        if (incomplete) { // Interpolate in incomplete 3D element if given
          for(int k = index; k < index + numVert; k++){
            MVertex *v;
            const double t1 = points(k, 0);
            const double t2 = points(k, 1);
            const double t3 = points(k, 2);
            SPoint3 pos;
            incomplete->pnt(t1, t2, t3, pos);
            v = new MVertex(pos.x(), pos.y(), pos.z(), gr);
            veFace.push_back(v);
          }
        }
        else { // TODO: Interpolate in incomplete face constructed on the fly
//          std::vector<MVertex*> &vtcs = faceVertices[face];
//          fullMatrix<double> points;
//          int start = getNewFacePointsInFace(face.getNumVertices(), nPts, points);
//          if(face.getNumVertices() == 3 && nPts > 1){ // tri face
//            // construct incomplete element to take into account curved
//            // edges on surface boundaries
//            std::vector<MVertex*> hoEdgeNodes;
//            for (int i = 0; i < 3; i++) {
//              MVertex* v0 = face.getVertex(i);
//              MVertex* v1 = face.getVertex((i + 1) % 3);
//              edgeContainer::iterator eIter = edgeVertices.find
//                (std::pair<MVertex*,MVertex*>(std::min(v0, v1), std::max(v0, v1)));
//              if (eIter == edgeVertices.end())
//                Msg::Error("Could not find ho nodes for an edge");
//              if (v0 == eIter->first.first)
//                hoEdgeNodes.insert(hoEdgeNodes.end(), eIter->second.begin(),
//                                   eIter->second.end());
//              else
//                hoEdgeNodes.insert(hoEdgeNodes.end(), eIter->second.rbegin(),
//                                   eIter->second.rend());
//            }
//            MTriangleN incomplete(face.getVertex(0), face.getVertex(1),
//                                  face.getVertex(2), hoEdgeNodes, nPts + 1);
//            for (int k = start; k < points.size1(); k++) {
//              double t1 = points(k, 0);
//              double t2 = points(k, 1);
//              SPoint3 pos;
//              incomplete.pnt(t1, t2, 0, pos);
//              MVertex* v = new MVertex(pos.x(), pos.y(), pos.z(), gr);
//              veFace.push_back(v);
//            }
//          }
//          else if(face.getNumVertices() == 4){ // quad face
//            for (int k = start; k < points.size1(); k++) {
//              double t1 = points(k, 0);
//              double t2 = points(k, 1);
//              SPoint3 pc = face.interpolate(t1, t2);
//              MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
//              veFace.push_back(v);
//            }
//          }
          std::vector<MVertex*> vfOld;
          ele->getFaceVertices(i,vfOld);
          MElement *faceEl;
          if (face.getNumVertices() == 3)
            faceEl = new MTriangleN(vfOld, nPts+1);
          else
            faceEl = new MQuadrangleN(vfOld, nPts+1);
          interpVerticesInExistingFace(gr, faceEl, veFace, nPts);
          delete faceEl;
        }
      }
      newHOVert.insert(newHOVert.end(), veFace.begin(), veFace.end());
      faceVertices[face].insert(faceVertices[face].end(), veFace.begin(), veFace.end());
    }
    vf.insert(vf.end(), veFace.begin(), veFace.end());
    index += numVert;
  }
}

// --------- Creation of high-order volume vertices -----------

static int getNewVolumePoints(MElement *incomplete, int nPts, fullMatrix<double> &points)
{
  int startInter = 0;

  switch (incomplete->getType()){
  case TYPE_TET :
    switch (nPts){
    case 0:
    case 1: return -1;
    case 2: points = BasisFactory::getNodalBasis(MSH_TET_20)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_TET_35)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_TET_56)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_TET_84)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_TET_120)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_TET_165)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_TET_220)->points; break;
    case 9: points = BasisFactory::getNodalBasis(MSH_TET_286)->points; break;
    default:
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startInter = ((nPts+2)*(nPts+3)*(nPts+4)-(nPts-2)*(nPts-1)*(nPts))/6;
    // = 4+6*(p-1)+4*(p-2)*(p-1)/2 = 4*(p+1)*(p+2)/2-6*(p-1)-2*4 = 2*p*p+2
    break;
  case TYPE_HEX :
    switch (nPts){
    case 0: return -1;
    case 1: points = BasisFactory::getNodalBasis(MSH_HEX_27)->points; break;
    case 2: points = BasisFactory::getNodalBasis(MSH_HEX_64)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_HEX_125)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_HEX_216)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_HEX_343)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_HEX_512)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_HEX_729)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_HEX_1000)->points; break;
    default :
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startInter = (nPts+2)*(nPts+2)*(nPts+2) - (nPts)*(nPts)*(nPts) ;
    // = 6*(p-1)*(p-1)+12*(p-1)+8 = 6*(p+1)*(p+1)-12*(p-1)-2*8 = 6*p*p+2
    break;
  case TYPE_PRI :
    switch (nPts){
    case 0: return -1;
    case 1: points = BasisFactory::getNodalBasis(MSH_PRI_18)->points; break;
    case 2: points = BasisFactory::getNodalBasis(MSH_PRI_40)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_PRI_75)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_PRI_126)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_PRI_196)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_PRI_288)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_PRI_405)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_PRI_550)->points; break;
    default:
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startInter = 4*(nPts+1)*(nPts+1)+2;
    // = 4*p*p+2 = 6+9*(p-1)+2*(p-2)*(p-1)/2+3*(p-1)*(p-1)
    // = 2*(p+1)*(p+2)/2+3*(p+1)*(p+1)-9*(p-1)-2*6
    break;
  case TYPE_PYR:
    switch (nPts){
    case 0:
    case 1: return -1;
    case 2: points = BasisFactory::getNodalBasis(MSH_PYR_30)->points; break;
    case 3: points = BasisFactory::getNodalBasis(MSH_PYR_55)->points; break;
    case 4: points = BasisFactory::getNodalBasis(MSH_PYR_91)->points; break;
    case 5: points = BasisFactory::getNodalBasis(MSH_PYR_140)->points; break;
    case 6: points = BasisFactory::getNodalBasis(MSH_PYR_204)->points; break;
    case 7: points = BasisFactory::getNodalBasis(MSH_PYR_285)->points; break;
    case 8: points = BasisFactory::getNodalBasis(MSH_PYR_385)->points; break;
    default :
      Msg::Error("getFaceAndInteriorVertices not implemented for order %i", nPts+1);
      break;
    }
    startInter = ( nPts+2) * ( (nPts+2) + 1) * (2*(nPts+2) + 1) / 6  -
      (nPts-1) * ( (nPts-1) + 1) * (2*(nPts-1) + 1) / 6;
    break;

  }

  return startInter;
}

// Get new interior vertices for a 3D element (except pyramid)
static void getVolumeVertices(GRegion *gr, MElement *incomplete, MElement *ele,
                              std::vector<MVertex*> &vr,
                              std::vector<MVertex*> &newHOVert,
                              bool linear, int nPts = 1)
{
  fullMatrix<double> points;
  int startInter = getNewVolumePoints(incomplete, nPts, points);
  const MElement *interpEl = linear ? ele : incomplete;
  for(int k = startInter; k < points.size1(); k++){
    MVertex *v;
    const double t1 = points(k, 0);
    const double t2 = points(k, 1);
    const double t3 = points(k, 2);
    SPoint3 pos;
    interpEl->pnt(t1, t2, t3, pos);
    v = new MVertex(pos.x(), pos.y(), pos.z(), gr);
    newHOVert.push_back(v);
    vr.push_back(v);
  }
}

// Get new interior vertices for a pyramid
static void getVolumeVerticesPyramid(GRegion *gr, MElement *ele,
                                     const std::vector<MVertex*> &ve,
                                     std::vector<MVertex*> &vr,
                                     std::vector<MVertex*> &newHOVert,
                                     bool linear, int nPts = 1)
{
  vr.reserve((nPts-1)*(nPts)*(2*(nPts-1)+1)/6);
  int verts_lvl3[12] = {37,40,38,43,46,44,49,52,50,55,58,56};
  int verts_lvl2[8];
  if (nPts == 4) {
    verts_lvl2[0] = 42; verts_lvl2[1] = 41;
    verts_lvl2[2] = 48; verts_lvl2[3] = 47;
    verts_lvl2[4] = 54; verts_lvl2[5] = 53;
    verts_lvl2[6] = 60; verts_lvl2[7] = 59;
  }
  else {
    verts_lvl2[0] = 29; verts_lvl2[1] = 30;
    verts_lvl2[2] = 35; verts_lvl2[3] = 36;
    verts_lvl2[4] = 38; verts_lvl2[5] = 39;
    verts_lvl2[6] = 32; verts_lvl2[7] = 33;
  }
  int verts_lvl1[4];
  switch(nPts) {
  case(4):
    verts_lvl1[0] = 39;
    verts_lvl1[1] = 45;
    verts_lvl1[2] = 51;
    verts_lvl1[3] = 57;
    break;
  case(3):
    verts_lvl1[0] = 31;
    verts_lvl1[1] = 37;
    verts_lvl1[2] = 40;
    verts_lvl1[3] = 34;
    break;
  case(2):
    verts_lvl1[0] = 21;
    verts_lvl1[1] = 23;
    verts_lvl1[2] = 24;
    verts_lvl1[3] = 22;
    break;
  }
  for (int q = 0; q < nPts - 1; q++) {
    std::vector<MVertex*> vq, veq;
    vq.push_back(ve[2*nPts + q]);
    vq.push_back(ve[4*nPts + q]);
    vq.push_back(ve[6*nPts + q]);
    vq.push_back(ve[7*nPts + q]);

    if (nPts-q == 4)
      for (int f = 0; f < 12; f++)
        veq.push_back(ve[verts_lvl3[f]-5]);
    else if (nPts-q == 3)
      for (int f = 0; f < 8; f++)
        veq.push_back(ve[verts_lvl2[f]-5]);
    else if (nPts-q == 2)
      for (int f = 0; f < 4; f++)
        veq.push_back(ve[verts_lvl1[f]-5]);

    if (nPts-q == 2) {
      MQuadrangle8 incpl2(vq[0], vq[1], vq[2], vq[3],
                          veq[0], veq[1], veq[2], veq[3]);
      SPoint3 pointz;
      incpl2.pnt(0,0,0,pointz);
      MVertex *v = new MVertex(pointz.x(), pointz.y(), pointz.z(), gr);
      newHOVert.push_back(v);
      std::vector<MVertex*>::iterator cursor = vr.begin();
      cursor += nPts == 2 ? 0 : 4;
      vr.insert(cursor, v);
    }
    else if (nPts-q == 3) {
      MQuadrangleN incpl2(vq[0], vq[1], vq[2], vq[3], veq, 3);
      int offsets[4] = {nPts == 4 ? 7 : 0,
                        nPts == 4 ? 9 : 1,
                        nPts == 4 ? 11 : 2,
                        nPts == 4 ? 12 : 3};
      double quad_v [4][2] = {{-1.0/3.0, -1.0/3.0},
                              { 1.0/3.0, -1.0/3.0},
                              { 1.0/3.0,  1.0/3.0},
                              {-1.0/3.0,  1.0/3.0}};
      SPoint3 pointz;
      for (int k = 0; k<4; k++) {
        incpl2.pnt(quad_v[k][0], quad_v[k][1], 0, pointz);
        MVertex *v = new MVertex(pointz.x(), pointz.y(), pointz.z(), gr);
        newHOVert.push_back(v);
        std::vector<MVertex*>::iterator cursor = vr.begin();
        cursor += offsets[k];
        vr.insert(cursor, v);
      }
    }
    else if (nPts-q == 4) {
      MQuadrangleN incpl2(vq[0], vq[1], vq[2], vq[3], veq, 4);
      int offsets[9] = {0, 1, 2, 3, 5, 8, 10, 6, 13};
      double quad_v [9][2] = {
        { -0.5, -0.5},
        {  0.5, -0.5},
        {  0.5,  0.5},
        { -0.5,  0.5},
        {  0.0, -0.5},
        {  0.5,  0.0},
        {  0.0,  0.5},
        { -0.5,  0.0},
        {  0.0,  0.0}
      };
      SPoint3 pointz;
      for (int k = 0; k<9; k++) {
        incpl2.pnt(quad_v[k][0], quad_v[k][1], 0, pointz);
        MVertex *v = new MVertex(pointz.x(), pointz.y(), pointz.z(), gr);
        newHOVert.push_back(v);
        std::vector<MVertex*>::iterator cursor = vr.begin();
        cursor += offsets[k];
        vr.insert(cursor, v);
      }
    }
  }
}


// --------- Creation of high-order elements -----------

static void setHighOrder(GEdge *ge, std::vector<MVertex*> &newHOVert,
                         edgeContainer &edgeVertices, bool linear, int nbPts = 1)
{
  std::vector<MLine*> lines2;
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MLine *l = ge->lines[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(ge, l, ve, newHOVert, edgeVertices, linear, nbPts);
    if(nbPts == 1)
      lines2.push_back(new MLine3(l->getVertex(0), l->getVertex(1),
                                  ve[0], l->getPartition()));
    else
      lines2.push_back(new MLineN(l->getVertex(0), l->getVertex(1),
                                  ve, l->getPartition()));
    delete l;
  }
  ge->lines = lines2;
  ge->deleteVertexArrays();
}

static MTriangle *setHighOrder(MTriangle *t, GFace *gf,
                               std::vector<MVertex*> &newHOVert,
                               edgeContainer &edgeVertices,
                               faceContainer &faceVertices,
                               bool linear, bool incomplete, int nPts)
{
  std::vector<MVertex*> ve, vf;
  getEdgeVertices(gf, t, ve, newHOVert, edgeVertices, linear, nPts);
  if(nPts == 1){
    return new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          ve[0], ve[1], ve[2], 0, t->getPartition());
  }
  else{
    if(!incomplete){
      MTriangleN incpl(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                       ve, nPts + 1, 0, t->getPartition());
      getFaceVertices(gf, &incpl, t, vf, newHOVert, faceVertices, linear, nPts);
      ve.insert(ve.end(), vf.begin(), vf.end());
    }
    return new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          ve, nPts + 1, 0, t->getPartition());
  }
}

static MQuadrangle *setHighOrder(MQuadrangle *q, GFace *gf,
                                 std::vector<MVertex*> &newHOVert,
                                 edgeContainer &edgeVertices,
                                 faceContainer &faceVertices,
                                 bool linear, bool incomplete, int nPts)
{
  std::vector<MVertex*> ve, vf;
  getEdgeVertices(gf, q, ve, newHOVert, edgeVertices, linear, nPts);
  if(incomplete){
    if(nPts == 1){
      return new MQuadrangle8(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), ve[0], ve[1], ve[2], ve[3],
                              0, q->getPartition());
    }
    else{
      return new MQuadrangleN(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), ve, nPts + 1,
                              0, q->getPartition());
    }
  }
  else {
    MQuadrangleN incpl(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                       q->getVertex(3), ve, nPts + 1, 0, q->getPartition());
    getFaceVertices(gf, &incpl, q, vf, newHOVert, faceVertices, linear, nPts);
    ve.insert(ve.end(), vf.begin(), vf.end());
    if(nPts == 1){
      return new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), ve[0], ve[1], ve[2], ve[3], vf[0],
                              0, q->getPartition());
    }
    else{
      return new MQuadrangleN(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                              q->getVertex(3), ve, nPts + 1,
                              0, q->getPartition());
    }
  }
}

static void setHighOrder(GFace *gf, std::vector<MVertex*> &newHOVert,
                         edgeContainer &edgeVertices, faceContainer &faceVertices,
                         bool linear, bool incomplete, int nPts = 1)
{
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    MTriangle *tNew = setHighOrder(t, gf, newHOVert, edgeVertices,
                                   faceVertices, linear, incomplete, nPts);
    triangles2.push_back(tNew);
    delete t;
  }
  gf->triangles = triangles2;
  std::vector<MQuadrangle*> quadrangles2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    MQuadrangle *qNew = setHighOrder(q, gf, newHOVert, edgeVertices,
                                     faceVertices, linear, incomplete, nPts);
    quadrangles2.push_back(qNew);
    delete q;
  }
  gf->quadrangles = quadrangles2;
  gf->deleteVertexArrays();
}

static MTetrahedron *setHighOrder(MTetrahedron *t, GRegion *gr,
                                  std::vector<MVertex*> &newHOVert,
                                  edgeContainer &edgeVertices,
                                  faceContainer &faceVertices,
                                  bool linear, bool incomplete, int nPts)
{
  std::vector<MVertex*> ve, vf, vr;
  getEdgeVertices(gr, t, ve, newHOVert, edgeVertices, linear, nPts);
  if(nPts == 1){
    return new MTetrahedron10(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                              t->getVertex(3), ve[0], ve[1], ve[2], ve[3], ve[4], ve[5],
                              0, t->getPartition());
  }
  else{
    if(!incomplete){
      // create serendipity element to place internal vertices (we used to
      // saturate face vertices also, but the corresponding function spaces do
      // not exist anymore, and there is no theoretical justification for doing
      // it either way)
      MTetrahedronN incpl(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          t->getVertex(3), ve, nPts + 1, 0, t->getPartition());
      getFaceVertices(gr, &incpl, t, vf, newHOVert, faceVertices, edgeVertices, linear, nPts);
      ve.insert(ve.end(), vf.begin(), vf.end());
      getVolumeVertices(gr, &incpl, t, vr, newHOVert, linear, nPts);
      ve.insert(ve.end(), vr.begin(), vr.end());
    }
    return new MTetrahedronN(t->getVertex(0), t->getVertex(1),
                             t->getVertex(2), t->getVertex(3), ve, nPts + 1,
                             0, t->getPartition());
  }
}

static MHexahedron *setHighOrder(MHexahedron *h, GRegion *gr,
                                 std::vector<MVertex*> &newHOVert,
                                 edgeContainer &edgeVertices,
                                 faceContainer &faceVertices,
                                 bool linear, bool incomplete, int nPts)
{
  std::vector<MVertex*> ve, vf, vr;
  getEdgeVertices(gr, h, ve, newHOVert, edgeVertices, linear, nPts);
  if(incomplete){
    if(nPts == 1){
      return new MHexahedron20(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                               h->getVertex(3), h->getVertex(4), h->getVertex(5),
                               h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2],
                               ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10],
                               ve[11], 0, h->getPartition());
    }
    else{
      return new MHexahedronN(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                              h->getVertex(3), h->getVertex(4), h->getVertex(5),
                              h->getVertex(6), h->getVertex(7), ve, nPts + 1, 0,
                              h->getPartition());
    }
  }
  else{
    // create serendipity element to place internal vertices (we used to
    // saturate face vertices also, but the corresponding function spaces do
    // not exist anymore, and there is no theoretical justification for doing
    // it either way)
    if(nPts == 1){
      MHexahedron20 incpl(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                          h->getVertex(3), h->getVertex(4), h->getVertex(5),
                          h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2],
                          ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10],
                          ve[11], 0, h->getPartition());
      getFaceVertices(gr, &incpl, h, vf, newHOVert, faceVertices, edgeVertices, linear, nPts);
      getVolumeVertices(gr, &incpl, h, vr, newHOVert, linear, nPts);
      return new MHexahedron27(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                               h->getVertex(3), h->getVertex(4), h->getVertex(5),
                               h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2],
                               ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10],
                               ve[11], vf[0], vf[1], vf[2], vf[3], vf[4], vf[5], vr[0],
                               0, h->getPartition());
    }
    else {
      MHexahedronN incpl(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                         h->getVertex(3), h->getVertex(4), h->getVertex(5),
                         h->getVertex(6), h->getVertex(7), ve, nPts + 1, 0,
                         h->getPartition());
      getFaceVertices(gr, &incpl, h, vf, newHOVert, faceVertices, edgeVertices, linear, nPts);
      ve.insert(ve.end(), vf.begin(), vf.end());
      getVolumeVertices(gr, &incpl, h, vr, newHOVert, linear, nPts);
      ve.insert(ve.end(), vr.begin(), vr.end());
      return new MHexahedronN(h->getVertex(0), h->getVertex(1), h->getVertex(2),
                              h->getVertex(3), h->getVertex(4), h->getVertex(5),
                              h->getVertex(6), h->getVertex(7), ve, nPts + 1,
                              0, h->getPartition());
    }
  }
}

static MPrism *setHighOrder(MPrism *p, GRegion *gr,
                            std::vector<MVertex*> &newHOVert,
                            edgeContainer &edgeVertices,
                            faceContainer &faceVertices,
                            bool linear, bool incomplete, int nPts)
{
  std::vector<MVertex*> ve, vf, vr;
  getEdgeVertices(gr, p, ve, newHOVert, edgeVertices, linear, nPts);
  if(incomplete){
    if(nPts == 1){
      return new MPrism15(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                          p->getVertex(3), p->getVertex(4), p->getVertex(5),
                          ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8],
                          0, p->getPartition());
    }
    else{
      return new MPrismN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                         p->getVertex(3), p->getVertex(4), p->getVertex(5),
                         ve, nPts + 1, 0, p->getPartition());
    }
  }
  else{
    // create serendipity element to place internal vertices (we used to
    // saturate face vertices also, but the corresponding function spaces do
    // not exist anymore, and there is no theoretical justification for doing
    // it either way)
    MPrismN incpl(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                  p->getVertex(3), p->getVertex(4), p->getVertex(5),
                  ve, nPts + 1, 0, p->getPartition());
    getFaceVertices(gr, &incpl, p, vf, newHOVert, faceVertices, edgeVertices, linear, nPts);
    if (nPts == 1) {
      return new MPrism18(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                          p->getVertex(3), p->getVertex(4), p->getVertex(5),
                          ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8],
                          vf[0], vf[1], vf[2],
                          0, p->getPartition());
    }
    else {
      ve.insert(ve.end(), vf.begin(), vf.end());
      getVolumeVertices(gr, &incpl, p, vr, newHOVert, linear, nPts);
      ve.insert(ve.end(), vr.begin(), vr.end());
      return new MPrismN(p->getVertex(0), p->getVertex(1), p->getVertex(2),
                         p->getVertex(3), p->getVertex(4), p->getVertex(5),
                         ve, nPts + 1, 0, p->getPartition());
    }
  }
}

static MPyramid *setHighOrder(MPyramid *p, GRegion *gr,
                              std::vector<MVertex*> &newHOVert,
                              edgeContainer &edgeVertices,
                              faceContainer &faceVertices,
                              bool linear, bool incomplete, int nPts)
{
  std::vector<MVertex*> ve, vf, vr;
  getEdgeVertices(gr, p, ve, newHOVert, edgeVertices, linear, nPts);
//  MPyramidN incpl(p->getVertex(0), p->getVertex(1), p->getVertex(2),
//                  p->getVertex(3), p->getVertex(4), ve, nPts + 1, 0, p->getPartition());
//  getFaceVertices(gr, &incpl, p, vf, faceVertices, edgeVertices, linear, nPts);
  getFaceVertices(gr, 0, p, vf, newHOVert, faceVertices, edgeVertices, linear, nPts);
  ve.insert(ve.end(), vf.begin(), vf.end());
  getVolumeVerticesPyramid(gr, p, ve, vr, newHOVert, linear, nPts);
  ve.insert(ve.end(), vr.begin(), vr.end());
  return new MPyramidN(p->getVertex(0), p->getVertex(1),
                       p->getVertex(2), p->getVertex(3),
                       p->getVertex(4), ve, nPts + 1,
                       0, p->getPartition());
}

static void setHighOrder(GRegion *gr, std::vector<MVertex*> &newHOVert,
                         edgeContainer &edgeVertices, faceContainer &faceVertices,
                         bool linear, bool incomplete, int nPts = 1)
{
  std::vector<MTetrahedron*> tetrahedra2;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTetrahedron *t = gr->tetrahedra[i];
    MTetrahedron *tNew = setHighOrder(t, gr, newHOVert, edgeVertices,
                                      faceVertices, linear, incomplete, nPts);
    tetrahedra2.push_back(tNew);
    delete t;
  }
  gr->tetrahedra = tetrahedra2;

  std::vector<MHexahedron*> hexahedra2;
  for(unsigned int i = 0; i < gr->hexahedra.size(); i++){
    MHexahedron *h = gr->hexahedra[i];
    MHexahedron *hNew = setHighOrder(h, gr, newHOVert, edgeVertices,
                                     faceVertices, linear, incomplete, nPts);
    hexahedra2.push_back(hNew);
    delete h;
  }
  gr->hexahedra = hexahedra2;

  std::vector<MPrism*> prisms2;
  for(unsigned int i = 0; i < gr->prisms.size(); i++){
    MPrism *p = gr->prisms[i];
    MPrism *pNew = setHighOrder(p, gr, newHOVert, edgeVertices,
                                faceVertices, linear, incomplete, nPts);
    prisms2.push_back(pNew);
    delete p;
  }
  gr->prisms = prisms2;

  std::vector<MPyramid*> pyramids2;
  for(unsigned int i = 0; i < gr->pyramids.size(); i++) {
    MPyramid *p = gr->pyramids[i];
    MPyramid *pNew = setHighOrder(p, gr, newHOVert, edgeVertices,
                                  faceVertices, linear, incomplete, nPts);
    pyramids2.push_back(pNew);
    delete p;
  }
  gr->pyramids = pyramids2;

  gr->deleteVertexArrays();
}


// --------- High-level functions -----------

template<class T>
static void setFirstOrder(GEntity *e, std::vector<T*> &elements, bool onlyVisible)
{
  if (onlyVisible && !e->getVisibility()) return;
  std::vector<T*> elements1;
  for(unsigned int i = 0; i < elements.size(); i++){
    T *ele = elements[i];
    int n = ele->getNumPrimaryVertices();
    std::vector<MVertex*> v1;
    for(int j = 0; j < n; j++)
      v1.push_back(ele->getVertex(j));
    elements1.push_back(new T(v1, 0, ele->getPartition()));
    delete ele;
  }
  elements = elements1;
  e->deleteVertexArrays();
}

static void updateHighOrderVertices(GEntity *e,
                                    const std::vector<MVertex*> &newHOVert,
                                    bool onlyVisible)
{
  if (onlyVisible && !e->getVisibility()) return;
  std::vector<MVertex*> v1;
  for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
    if(e->mesh_vertices[i]->getPolynomialOrder() > 1)
      delete e->mesh_vertices[i];
    else
      v1.push_back(e->mesh_vertices[i]);
  }
  v1.insert(v1.end(), newHOVert.begin(), newHOVert.end());
  e->mesh_vertices = v1;
  e->deleteVertexArrays();
}

static void updatePeriodicEdgesAndFaces(GModel *m)
{

  // Edges

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {

    GEdge *tgt = *it;
    GEdge *src = dynamic_cast<GEdge*>(tgt->meshMaster());

    if (src != NULL && src != tgt) {

      std::map<MVertex*,MVertex*> &v2v = tgt->correspondingVertices;
      std::map<MVertex*,MVertex*> &p2p = tgt->correspondingHOPoints;
      p2p.clear();

      Msg::Info("Constructing high order periodicity for edge connection %d - %d",
                tgt->tag(),src->tag());

      std::map<MEdge,MLine*,Less_Edge> srcEdges;
      for (unsigned int i=0;i<src->getNumMeshElements();i++)  {
        MLine* srcLine = dynamic_cast<MLine*>(src->getMeshElement(i));
        if (!srcLine) Msg::Error("Master element %d is not an edge ",
                                 src->getMeshElement(i)->getNum());
        srcEdges[MEdge(srcLine->getVertex(0),
                       srcLine->getVertex(1))] = srcLine;
      }

      for (unsigned int i = 0; i < tgt->getNumMeshElements(); ++i) {

        MLine* tgtLine = dynamic_cast<MLine*> (tgt->getMeshElement(i));
        MVertex* vtcs[2];

        if (!tgtLine) Msg::Error("Slave element %d is not an edge ",
                            tgt->getMeshElement(i)->getNum());

        for (int iVtx=0;iVtx<2;iVtx++) {
          MVertex* vtx = tgtLine->getVertex(iVtx);
          std::map<MVertex*,MVertex*>::iterator tIter = v2v.find(vtx);
          if (tIter == v2v.end()) {
            Msg::Error("Cannot find periodic counterpart of vertex %d"
                       " of edge %d on edge %d",
                       vtx->getNum(),tgt->tag(),src->tag());
          }
          else vtcs[iVtx] = tIter->second;
        }

        std::map<MEdge,MLine*,Less_Edge>::iterator srcIter = srcEdges.find(MEdge(vtcs[0],vtcs[1]));
        if (srcIter==srcEdges.end()) {
          Msg::Error("Can't find periodic counterpart of edge %d-%d on edge %d"
                     ", connected to edge %d-%d on %d",
                     tgtLine->getVertex(0)->getNum(),
                     tgtLine->getVertex(1)->getNum(),
                     tgt->tag(),
                     vtcs[0]->getNum(),
                     vtcs[1]->getNum(),
                     src->tag());
        }
        else {
          MLine* srcLine = srcIter->second;
          if (tgtLine->getNumVertices() != srcLine->getNumVertices()) throw;
          for (int i=2;i<tgtLine->getNumVertices();i++) p2p[tgtLine->getVertex(i)] = srcLine->getVertex(i);
        }
      }
    }
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    GFace *tgt = *it;
    GFace *src = dynamic_cast<GFace*>(tgt->meshMaster());
    if (src != NULL && src != tgt) {

      Msg::Info("Constructing high order periodicity for face connection %d - %d",
                tgt->tag(),src->tag());

      std::map<MVertex*,MVertex*> &v2v = tgt->correspondingVertices;
      std::map<MVertex*,MVertex*> &p2p = tgt->correspondingHOPoints;
      p2p.clear();

      std::map<MFace,MElement*,Less_Face> srcFaces;

      for (unsigned int i=0;i<src->getNumMeshElements();++i) {
        MElement* srcElmt  = src->getMeshElement(i);
        int nbVtcs = 0;
        if (dynamic_cast<MTriangle*>   (srcElmt)) nbVtcs = 3;
        if (dynamic_cast<MQuadrangle*> (srcElmt)) nbVtcs = 4;
        std::vector<MVertex*> vtcs;
        for (int iVtx=0;iVtx<nbVtcs;iVtx++) {
          vtcs.push_back(srcElmt->getVertex(iVtx));
        }
        srcFaces[MFace(vtcs)] = srcElmt;
      }

      for (unsigned int i=0;i<tgt->getNumMeshElements();++i) {

        MElement* tgtElmt = tgt->getMeshElement(i);
        Msg::Info("Checking element %d in face %d",i,tgt->tag());

        int nbVtcs = 0;
        if (dynamic_cast<MTriangle*>   (tgtElmt)) nbVtcs = 3;
        if (dynamic_cast<MQuadrangle*> (tgtElmt)) nbVtcs = 4;
        std::vector<MVertex*> vtcs;
        for (int iVtx=0;iVtx<nbVtcs;iVtx++) {
          MVertex* vtx = tgtElmt->getVertex(iVtx);

          std::map<MVertex*,MVertex*>::iterator tIter = v2v.find(vtx);
          if (tIter == v2v.end()) {
            Msg::Error("Cannot find periodic counterpart of vertex %d"
                       " of surface %d on surface %d",
                       vtx->getNum(),tgt->tag(),src->tag());
          }
          else vtcs.push_back(tIter->second);
          // GEntity* ge = vtx->onWhat();
          // if (ge->meshMaster() == ge) throw;
          // std::map<MVertex*,MVertex*>& v2v = ge->correspondingVertices;
          //vtcs.push_back(v2v[vtx]);
        }

        std::map<MFace,MElement*>::iterator srcIter = srcFaces.find(MFace(vtcs));
        if (srcIter == srcFaces.end()) {
          std::ostringstream faceDef;
          for (int iVtx=0;iVtx<nbVtcs;iVtx++) faceDef << vtcs[iVtx]->getNum() << " ";
          Msg::Error("Cannot find periodic counterpart of face %s in face %d "
                     "connected to %d",faceDef.str().c_str(),
                     tgt->tag(),src->tag());
        }
        else {
          MElement* srcElmt = srcIter->second;
          for (int i=nbVtcs;i<srcElmt->getNumVertices();i++) {
            p2p[tgtElmt->getVertex(i)] = srcElmt->getVertex(i);
          }
        }
      }
    }
  }
  Msg::Info("Finalized high order topology of periodic connections");
}

void SetOrder1(GModel *m, bool onlyVisible)
{
  m->destroyMeshCaches();

  // replace all elements with first order elements
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    setFirstOrder(*it, (*it)->lines, onlyVisible);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    setFirstOrder(*it, (*it)->triangles, onlyVisible);
    setFirstOrder(*it, (*it)->quadrangles, onlyVisible);
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    setFirstOrder(*it, (*it)->tetrahedra, onlyVisible);
    setFirstOrder(*it, (*it)->hexahedra, onlyVisible);
    setFirstOrder(*it, (*it)->prisms, onlyVisible);
    setFirstOrder(*it, (*it)->pyramids, onlyVisible);
  }

  // remove all high order vertices
  std::vector<MVertex*> newHOVert;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    updateHighOrderVertices(*it, newHOVert, onlyVisible);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    updateHighOrderVertices(*it, newHOVert, onlyVisible);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    updateHighOrderVertices(*it, newHOVert, onlyVisible);

  updatePeriodicEdgesAndFaces(m);
}

void checkHighOrderTriangles(const char* cc, GModel *m,
                             std::vector<MElement*> &bad, double &minJGlob)
{
  bad.clear();
  minJGlob = 1.0;
  double minGGlob = 1.0;
  double avg = 0.0;
  int count = 0, nbfair = 0;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
      MTriangle *t = (*it)->triangles[i];
      double disto_ = t->distoShapeMeasure();
      double gamma_ = t->gammaShapeMeasure();
      double disto = disto_;
      minJGlob = std::min(minJGlob, disto);
      minGGlob = std::min(minGGlob, gamma_);
      avg += disto; count++;
      if (disto < 0) bad.push_back(t);
      else if (disto < 0.2) nbfair++;
    }
    /*
    for(unsigned int i = 0; i < (*it)->quadrangles.size(); i++){
      MQuadrangle *t = (*it)->quadrangles[i];
      double disto_ = t->distoShapeMeasure();
      double gamma_ = t->gammaShapeMeasure();
      double disto = disto_;
      minJGlob = std::min(minJGlob, disto);
      minGGlob = std::min(minGGlob, gamma_);
      avg += disto; count++;
      if (disto < 0) bad.push_back(t);
      else if (disto < 0.2) nbfair++;
    }
    */
  }
  if(!count) return;
  if (minJGlob > 0)
    Msg::Info("%s: worst distortion = %g (%d elements in ]0, 0.2]); worst gamma = %g",
              cc, minJGlob, nbfair, minGGlob);
  else
    Msg::Warning("%s: worst distortion = %g (avg = %g, %d elements with jac. < 0); "
                 "worst gamma = %g", cc, minJGlob, avg / (count ? count : 1),
                 bad.size(), minGGlob);
}

void checkHighOrderTetrahedron(const char* cc, GModel *m,
                               std::vector<MElement*> &bad, double &minJGlob)
{
  bad.clear();
  minJGlob = 1.0;
  double avg = 0.0;
  int count = 0, nbfair = 0;
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    for(unsigned int i = 0; i < (*it)->tetrahedra.size(); i++){
      MTetrahedron *t = (*it)->tetrahedra[i];
      double disto_ = t->distoShapeMeasure();
      minJGlob = std::min(minJGlob, disto_);
      avg += disto_; count++;
      if (disto_ < 0) bad.push_back(t);
      else if (disto_ < 0.2) nbfair++;
    }
  }
  if(!count) return;

  if (minJGlob > 0)
    Msg::Info("%s: worst distortion = %g (%d elements in ]0, 0.2])",
              cc, minJGlob, nbfair);
  else
    Msg::Warning("%s: worst distortion = %g (avg = %g, %d elements with jac. < 0)",
                 cc, minJGlob, avg / (count ? count : 1), bad.size());
}

void getMeshInfoForHighOrder(GModel *gm, int &meshOrder, bool &complete,
                             bool &CAD)
{
  meshOrder = -1;
  CAD = true;
  complete = 1;
  for (GModel::riter itr = gm->firstRegion(); itr != gm->lastRegion(); ++itr) {
    if ((*itr)->getNumMeshElements()){
      meshOrder = (*itr)->getMeshElement(0)->getPolynomialOrder();
      complete = (meshOrder <= 2) ? 1 :  (*itr)->getMeshElement(0)->getNumVolumeVertices();
      break;
    }
  }
  for (GModel::fiter itf = gm->firstFace(); itf != gm->lastFace(); ++itf) {
    if ((*itf)->getNumMeshElements()){
      if (meshOrder == -1) {
        meshOrder = (*itf)->getMeshElement(0)->getPolynomialOrder();
        complete = (meshOrder <= 2) ? 1 :  (*itf)->getMeshElement(0)->getNumFaceVertices();
        if ((*itf)->geomType() == GEntity::DiscreteSurface)CAD = false;
        break;
      }
    }
  }
}

void SetOrderN(GModel *m, int order, bool linear, bool incomplete, bool onlyVisible)
{
  // replace all the elements in the mesh with second order elements
  // by creating unique vertices on the edges/faces of the mesh:
  //
  // - if linear is set to true, new vertices are created by linear
  //   interpolation between existing ones. If not, new vertices are
  //   created on the exact geometry, provided that the geometrical
  //   edges/faces are discretized with 1D/2D elements. (I.e., if
  //   there are only 3D elements in the mesh then any new vertices on
  //   the boundary will always be created by linear interpolation,
  //   whether linear is set or not.)
  //
  // - if incomplete is set to true, we only create new vertices on
  //   edges (creating 8-node quads, 20-node hexas, etc., instead of
  //   9-node quads, 27-node hexas, etc.)

  // - if onlyVisible is true, then only the visible entities will be curved.

  int nPts = order - 1;

  char msg[256];
  sprintf(msg, "Meshing order %d (curvilinear %s)...", order, linear ? "off" : "on");

  Msg::StatusBar(true, msg);

  double t1 = Cpu();

  m->destroyMeshCaches();

  // Keep track of vertex/entities created
  edgeContainer edgeVertices;
  faceContainer faceVertices;
  std::map<GEntity*,std::vector<MVertex*> > newHOVert;

  Msg::ResetProgressMeter();

  int counter = 0, nTot = m->getNumEdges() + m->getNumFaces() + m->getNumRegions();

  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it) {
    Msg::Info("Meshing curve %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, nTot, false, msg);
    if (onlyVisible && !(*it)->getVisibility()) continue;
    setHighOrder(*it, newHOVert[*it], edgeVertices, linear, nPts);
  }

  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    Msg::Info("Meshing surface %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, nTot, false, msg);
    if (onlyVisible && !(*it)->getVisibility()) continue;
    setHighOrder(*it, newHOVert[*it], edgeVertices, faceVertices, linear, incomplete, nPts);
  }

  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it) {
    Msg::Info("Meshing volume %d order %d", (*it)->tag(), order);
    Msg::ProgressMeter(++counter, nTot, false, msg);
    if (onlyVisible && !(*it)->getVisibility())continue;
    setHighOrder(*it, newHOVert[*it], edgeVertices, faceVertices, linear, incomplete, nPts);
  }

  // Update all high order vertices
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    updateHighOrderVertices(*it, newHOVert[*it], onlyVisible);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    updateHighOrderVertices(*it, newHOVert[*it], onlyVisible);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    updateHighOrderVertices(*it, newHOVert[*it], onlyVisible);

  updatePeriodicEdgesAndFaces(m);

  double t2 = Cpu();

  std::vector<MElement*> bad;
  double worst;
  checkHighOrderTriangles("Surface mesh", m, bad, worst);
  checkHighOrderTetrahedron("Volume Mesh", m, bad, worst);
  // FIXME : add other element check

  Msg::StatusBar(true, "Done meshing order %d (%g s)", order, t2 - t1);
}

void SetHighOrderComplete(GModel *m, bool onlyVisible)
{
  faceContainer faceVertices;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    if (onlyVisible && !(*it)->getVisibility()) continue;
    std::vector<MVertex*> dumNewHOVert;
    std::vector<MTriangle*> newT;
    std::vector<MQuadrangle*> newQ;
    for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
      MTriangle *t = (*it)->triangles[i];
      std::vector<MVertex*> vf, vt;
      int nPts = t->getPolynomialOrder() - 1;
      MTriangle TEMP (t->getVertex(0), t->getVertex(1), t->getVertex(2), 0, t->getPartition());
      getFaceVertices (*it, t, t, vf, dumNewHOVert, faceVertices, false, nPts);
      for (int j=3;j<t->getNumVertices();j++)vt.push_back(t->getVertex(j));
      vt.insert(vt.end(), vf.begin(), vf.end());
      MTriangleN *newTr = new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                                         vt, nPts + 1, 0, t->getPartition());
      newT.push_back(newTr);

      delete t;
    }
    (*it)->triangles = newT;

    for (unsigned int i = 0; i < (*it)->quadrangles.size(); i++){
      MQuadrangle *t = (*it)->quadrangles[i];
      std::vector<MVertex*> vf, vt;
      int nPts = t->getPolynomialOrder() - 1;
      MQuadrangle TEMP (t->getVertex(0), t->getVertex(1), t->getVertex(2),
                        t->getVertex(3), 0, t->getPartition());
      getFaceVertices (*it, t, &TEMP, vf, dumNewHOVert, faceVertices, false, nPts);
      for (int j=4;j<t->getNumVertices();j++)vt.push_back(t->getVertex(j));
      vt.insert(vt.end(), vf.begin(), vf.end());
      newQ.push_back(new MQuadrangleN(t->getVertex(0), t->getVertex(1),
                                      t->getVertex(2), t->getVertex(3),
                                      vt, nPts + 1, 0, t->getPartition()));
      delete t;
    }
    (*it)->quadrangles = newQ;

    std::set<MVertex*> newV;
    for (unsigned int i = 0; i < (*it)->getNumMeshElements(); ++i){
      MElement *e = (*it)->getMeshElement(i);
      for (int j=0;j<e->getNumVertices();j++)newV.insert(e->getVertex(j));
    }
    (*it)->mesh_vertices.clear();
    (*it)->mesh_vertices.insert((*it)->mesh_vertices.begin(), newV.begin(), newV.end());
  }

  updatePeriodicEdgesAndFaces(m);
}

void SetHighOrderInComplete (GModel *m, bool onlyVisible)
{
  std::set<MVertex*> toDelete;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it) {
    if (onlyVisible && !(*it)->getVisibility()) continue;
    std::vector<MTriangle*> newT;

    for (unsigned int i = 0; i < (*it)->triangles.size(); i++){
      MTriangle *t = (*it)->triangles[i];
      std::vector<MVertex*> vt;
      int order = t->getPolynomialOrder();
      for (int j=3;j<t->getNumVertices()-t->getNumFaceVertices();j++)
        vt.push_back(t->getVertex(j));
      for (int j = t->getNumVertices()-t->getNumFaceVertices();
           j < t->getNumVertices(); j++)
        toDelete.insert(t->getVertex(j));
      newT.push_back(new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                                    vt, order, 0, t->getPartition()));
      delete t;
    }
    (*it)->triangles = newT;

    std::vector<MQuadrangle*> newQ;
    for (unsigned int i = 0; i < (*it)->quadrangles.size(); i++){
      MQuadrangle *t = (*it)->quadrangles[i];
      std::vector<MVertex*> vt;
      int nPts = t->getPolynomialOrder() - 1;
      for (int j = 4; j < t->getNumVertices()-t->getNumFaceVertices(); j++)
        vt.push_back(t->getVertex(j));
      newQ.push_back(new MQuadrangleN(t->getVertex(0), t->getVertex(1),
                                      t->getVertex(2), t->getVertex(3),
                                      vt, nPts + 1, 0, t->getPartition()));
      delete t;
    }
    (*it)->quadrangles = newQ;

    std::vector<MVertex*> newV;
    int numd = 0;
    for (unsigned int i = 0; i < (*it)->mesh_vertices.size(); ++i){
      if (toDelete.find((*it)->mesh_vertices[i]) == toDelete.end())
        newV.push_back((*it)->mesh_vertices[i]);
      else{
        delete (*it)->mesh_vertices[i];
        numd++;
      }
    }
    (*it)->mesh_vertices = newV;
  }

  updatePeriodicEdgesAndFaces(m);
}
