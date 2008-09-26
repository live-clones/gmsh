// Gmsh - Copyright (C) 1997-2008 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "HighOrder.h"
#include "meshGFaceOptimize.h"
#include "MElement.h"
#include "Message.h"
#include "OS.h"
#include "Numeric.h"
#include "Context.h"
#include "GmshMatrix.h"
#include "FunctionSpace.h"

#define SQU(a)      ((a)*(a))

extern Context_T CTX;

// for each pair of vertices (an edge), we build a list of vertices
// that are the high order representation of the edge. The ordering of
// vertices in the list is supposed to be (by construction) consistent
// with the ordering of the pair.
typedef std::map<std::pair<MVertex*,MVertex*>, std::vector<MVertex*> > edgeContainer;

// for each face (a list of vertices) we build a list of vertices that
// are the high order representation of the face
// typedef std::map<std::vector<MVertex*>, std::vector<MVertex*>> faceContainer;
typedef std::map<MFace, std::vector<MVertex*>,Less_Face>       faceContainer;

bool mappingIsInvertible (MTetrahedron *e)
{
  if (e->getPolynomialOrder() == 1)return 1.0;
  
  double mat[3][3];
  e->getPrimaryJacobian(0.,0.,0., mat);  
  double det0 = det3x3(mat);

  IntPt *pts;
  int npts;

  e->getIntegrationPoints(e->getPolynomialOrder(),&npts, &pts);
  
  for (int i=0;i<npts;i++){
    
    const double u = pts[i].pt[0];
    const double v = pts[i].pt[1];
    const double w = pts[i].pt[2];
    
    e->getJacobian(u, v, w, mat);

    double detN = det3x3(mat);
    
    if (det0 * detN <= 0.) return false;
  }

  const Double_Matrix& points = e->getFunctionSpace()->points;

  for (int i=0;i<e->getNumPrimaryVertices();i++) {

    const double u = points(i,0);
    const double v = points(i,1);
    const double w = points(i,2);

    e->getJacobian(u,v,w,mat);

    double detN = det3x3(mat);

    if (det0 * detN <= 0.) return false;
  }
  
  return true;
}

bool deformElement(MElement *ele,GEntity* ge,const std::set<MVertex*>& blocked) {
  
  int nbNodes = ele->getNumVertices();  

  double _E = 1.;
  double _nu = 0.1;
  
  double FACT = _E / (1. + _nu) / (1. - 2. * _nu);  
  double C11 = FACT * (1. - _nu);
  double C12 = FACT * _nu;
  double C44 = (C11 - C12) / 2; 
  
  Double_Matrix stiffness(3*nbNodes,3*nbNodes);
  Double_Vector rhs(3*nbNodes);

  int npts;
  IntPt *pts;
  ele->getIntegrationPoints(2*ele->getPolynomialOrder(),&npts, &pts);
  double d0;

  const gmshFunctionSpace* fs = ele->getFunctionSpace();

  const Double_Matrix& points = fs->points;
  

  double jac[3][3];
  ele->getPrimaryJacobian(0,0,0,jac);
  double invjac[3][3];
  inv3x3(jac,invjac);

  double gsf[256][3];


  // cheaper version : quadrature only used for parametric stiffness
  // paramGrads should be stored in functionspace.
  
//   for (int j=0;j<nbNodes;j++) {
//     for (int k=0;k<nbNodes;k++) {

//       double xx = 0;
//       double xy = 0;
//       double xz = 0;
//       double yx = 0;
//       double yy = 0;
//       double yz = 0;
//       double zx = 0;
//       double zy = 0;
//       double zz = 0;
      

//       for (int m=0;m<3;m++) {
//         for (int n=0;n<3;n++) {

//           double dd = paramGrads[m][n](j,k);
          
//           xx += dd * invJac[0][m] * invJac[0][n];
//           xy += dd * invJac[0][m] * invJac[1][n];
//           xz += dd * invJac[0][m] * invJac[2][n];
//           yx += dd * invJac[1][m] * invJac[0][n];
//           yy += dd * invJac[1][m] * invJac[1][n];
//           yz += dd * invJac[1][m] * invJac[2][n];
//           zx += dd * invJac[2][m] * invJac[0][n];
//           zy += dd * invJac[2][m] * invJac[1][n];
//           zz += dd * invJac[2][m] * invJac[2][n];
//         }
//       }

//       stiffness(3*j,3*k)     += (C11 * xx +  // dphidx . tauxx
//                                  C44 * yy +  // dphidy . tauxy
//                                  C44 * zz);  // dphidz . tauxz
      
//       stiffness(3*j,3*k+1)   += (C12 * xy +  // dphidx . tauxx 
//                                  C44 * yx);  // dphidy . tauxy
      
//       stiffness(3*j,3*k+2)   += (C12 * xz +  // dphidx . tauxx
//                                  C44 * zx);  // dphidz . tauxz
      
//       stiffness(3*j+1,3*k)   += (C44 * xy +  // dphidx . tauxy
//                                  C12 * yx);  // dphidy . tauyy
      
//       stiffness(3*j+1,3*k+1) += (C44 * xx +  // dphidx . tauxy 
//                                  C11 * yy +  // dphidy . tauyy
//                                  C44 * zz ); // dphidz . tauzy
      
//       stiffness(3*j+1,3*k+2) += (C12 * yz +  // dphidy . tauyy
//                                  C44 * zy);  // dphidz . tauzy
      
//       stiffness(3*j+2,3*k)   += (C44 * xz +  // dphidx . tauxz
//                                  C12 * zx);  // dphidz . tauzz
      
//       stiffness(3*j+2,3*k+1) += (C44 * yz +  // dphidy . tauyz
//                                  C12 * zy);  // dphidz . tauzz
      
//       stiffness(3*j+2,3*k+2) += (C44 * xx +  // dphidx . tauxz
//                                  C44 * yy +  // dphidy . tauyz
//                                  C11 * zz);  // dphidz . tauzz
//     }
//   }
  
      
  // more expensive version

  double Grads[256][3];

  stiffness.scale(0.);
  
  for (int i=0;i<npts;i++){
    
    const double u = pts[i].pt[0];
    const double v = pts[i].pt[1];
    const double w = pts[i].pt[2];

    const double weight = pts[i].weight;
    
    fs->df(u,v,w,gsf);

    for (int j=0;j<nbNodes;j++) {
      Grads[j][0] = invjac[0][0] * gsf[j][0] + invjac[0][1] * gsf[j][1] + invjac[0][2] * gsf[j][2];
      Grads[j][1] = invjac[1][0] * gsf[j][0] + invjac[1][1] * gsf[j][1] + invjac[1][2] * gsf[j][2];
      Grads[j][2] = invjac[2][0] * gsf[j][0] + invjac[2][1] * gsf[j][1] + invjac[2][2] * gsf[j][2];
    }
    
    for (int j=0;j<nbNodes;j++) {
      for (int k=0;k<nbNodes;k++) {

        // R_x = dphidx . tauxx + dphidy . tauxy + dphidz . tauxz
        // tau_xx = C11 . e_xx + C12 . (e_yy + e_zz)
        // tau_xy = C44 . e_xy 
        // e_xy = 0.5 * (dX/dx + dY/dy)

        double xx = Grads[j][0] * Grads[k][0];
        double xy = Grads[j][0] * Grads[k][1];
        double xz = Grads[j][0] * Grads[k][2];
        
        double yx = Grads[j][1] * Grads[k][0];
        double yy = Grads[j][1] * Grads[k][1];
        double yz = Grads[j][1] * Grads[k][2];
        
        double zx = Grads[j][2] * Grads[k][0];
        double zy = Grads[j][2] * Grads[k][1];
        double zz = Grads[j][2] * Grads[k][2];


        // Poisson
        
        stiffness(3*j,3*k)     += weight * (xx + yy + zz);
        stiffness(3*j+1,3*k+1) += weight * (xx + yy + zz);
        stiffness(3*j+2,3*k+2) += weight * (xx + yy + zz);
        

        // Elasticity

        // stiffness(3*j  ,3*k  ) += weight * (C11 * xx + C44 * yy + C44 * zz);
//         stiffness(3*j  ,3*k+1) += weight * (C12 * xy + C44 * yx);
//         stiffness(3*j  ,3*k+2) += weight * (C12 * xz + C44 * zx);

//         stiffness(3*j+1,3*k  ) += weight * (C12 * yx + C44 * xy);
//         stiffness(3*j+1,3*k+1) += weight * (C44 * xx + C11 * yy + C44 * zz);
//         stiffness(3*j+1,3*k+2) += weight * (C12 * yz + C44 * zy);
        
//         stiffness(3*j+2,3*k  ) += weight * (C12 * zx + C44 * xz);
//         stiffness(3*j+2,3*k+1) += weight * (C12 * zy + C44 * yz);
//         stiffness(3*j+2,3*k+2) += weight * (C44 * xx + C44 * yy + C11 * zz);
        
      }
    }
  }

  int nbDirichlet = 0;
  
  Double_Vector original(nbNodes*3);
  
  for (int i=0;i<nbNodes;i++) {

    MVertex* v = ele->getVertex(i);
      
    SPoint3 primary;
    ele->primaryPnt(points(i,0),points(i,1),points(i,2),primary);
    original(3*i  ) = primary.x();
    original(3*i+1) = primary.y();
    original(3*i+2) = primary.z();
    
    MFaceVertex* vf = dynamic_cast<MFaceVertex*> (v);
    MFaceVertex* ve = dynamic_cast<MFaceVertex*> (v);

    if (v->onWhat() != ge || blocked.find(v) != blocked.end()) {

      nbDirichlet++;
        
      double dx = v->x() - original(3*i  );
      double dy = v->y() - original(3*i+1);
      double dz = v->z() - original(3*i+2);

      for (int j=0;j<3*nbNodes;j++) {
        stiffness(3*i  ,j) = 0;
        stiffness(3*i+1,j) = 0;
        stiffness(3*i+2,j) = 0;
      }
      
      for (int k=0;k<3;k++) stiffness(i*3+k,i*3+k) = 1.;
      
      rhs(i*3  ) = dx;
      rhs(i*3+1) = dy;
      rhs(i*3+2) = dz;
    }
    else {
      rhs(i*3  ) = 0.;
      rhs(i*3+1) = 0.;
      rhs(i*3+2) = 0.;
    }
  }

  if (nbDirichlet < 3) {
    Msg::Warning("Could not deform element due to lack of constraints\n");
    return false;
  }

  if (nbDirichlet == nbNodes) {
    Msg::Warning("Could not deform element because fully constrained\n");
    return false;
  }

  
  Msg::Warning("Deforming element - have %d constrained points of which %d from previous positioning",nbDirichlet,(int) blocked.size());
  

  Double_Vector displacement(nbNodes*3);

  
  stiffness.lu_solve(rhs,displacement);

  for (int i=0;i<nbNodes;i++) {
    MVertex* v = ele->getVertex(i);
    
    v->x() = original(3*i)   + displacement(3*i  );
    v->y() = original(3*i+1) + displacement(3*i+1);
    v->z() = original(3*i+2) + displacement(3*i+2);
    
  }
  
  return true;
}


bool reparamOnFace(MVertex *v, GFace *gf, SPoint2 &param)
{
  if(v->onWhat()->dim() == 0){
    GVertex *gv = (GVertex*)v->onWhat();

    // abort if we could be on a seam
    /*
    std::list<GEdge*> ed = gv->edges();
    for(std::list<GEdge*>::iterator it = ed.begin(); it != ed.end(); it++)
      if((*it)->isSeam(gf)) return false;
    */
    param = gv->reparamOnFace(gf, 1);
  }
  else if(v->onWhat()->dim() == 1){
    GEdge *ge = (GEdge*)v->onWhat();

    // abort if we are on a seam (todo: try dir=-1 and compare)
    //    if(ge->isSeam(gf)){
    //      printf("oops : %d %d\n",ge->tag(),gf->tag());
      //    }

    double UU;
    v->getParameter(0, UU);
    param = ge->reparamOnFace(gf, UU, 1);
  }
  else{
    double UU, VV;
    if(v->onWhat() == gf && v->getParameter(0, UU) && v->getParameter(1, VV))
      param = SPoint2(UU, VV);
    else 
      return false;
    //      param = gf->parFromPoint(SPoint3(v->x(), v->y(), v->z()));
  }
  return true;
}

// The aim here is to build a polynomial representation that consist
// in polynomial segments of equal length

static double mylength(GEdge *ge, int i, double *u)
{
  return ge->length(u[i], u[i+1], 10);
}

static void myresid(int N, GEdge *ge, double *u, Double_Vector &r)
{
  double L[100];
  for (int i = 0; i < N - 1; i++) L[i] = mylength(ge, i, u);
  for (int i = 0; i < N - 2; i++) r(i) = L[i + 1] - L[i];
}

bool computeEquidistantParameters(GEdge *ge, double u0, double uN, int N, double *u, double underRelax)
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
  for (int i = 1 ; i < N ; i++){
    u[i] = u[i - 1] + du;
  }

  // create the tangent matrix
  const int M = N - 2;
  Double_Matrix J(M, M);
  Double_Vector DU(M);
  Double_Vector R(M);
  Double_Vector Rp(M);
  
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
      J.lu_solve(R, DU);
    
    for (int i = 0; i < M; i++){
      u[i+1] -= underRelax*DU(i);
    }
    // printf("N %d M %d u1 = %g u0 = %g uN1 = %22.15E uN = %22.15E\n",
    //        N, M, u[1], u0, u[N - 1], uN);

    if (u[1] < u0) break;
    if (u[N - 2] > uN) break;

    double newt_norm = DU.norm();      
    // printf("%22.15E\n",newt_norm);
    if (newt_norm < PRECISION) { /*printf("ok %g\n",underRelax);*/ return true; }
  }
  // FAILED, use equidistant in param space
  // printf("failed %g\n",underRelax);
  // for (int i = 1; i < N; i++){
  //   u[i] = u[i - 1] + du;
  // }
  return false;
}

static double mylength(GFace *gf, int i, double *u, double *v)
{
  return gf->length(SPoint2(u[i], v[i]), SPoint2(u[i + 1], v[i + 1]), 10);
}

static void myresid(int N, GFace *gf, double *u, double *v, Double_Vector &r)
{
  double L[100];
  for (int i = 0; i < N - 1; i++) L[i] = mylength(gf, i, u, v);  
  for (int i = 0; i < N - 2; i++) r(i) = L[i + 1] - L[i];
}

bool computeEquidistantParameters(GFace *gf, double u0, double uN, double v0, double vN, 
                                  int N, double *u, double *v)
{
  const double PRECISION = 1.e-6;
  const int MAX_ITER = 50;
  const double eps = 1.e-4;

  double t[100];

  // initialize the points by equal subdivision of geodesics
  u[0] = u0;
  v[0] = v0;
  t[0] = 0;
  for (int i = 1; i < N ; i++){
    t[i] = (double)i / (N - 1);
    SPoint2 p = gf->geodesic(SPoint2(u0, v0), SPoint2(uN, vN), t[i]);
    u[i] = p.x();
    v[i] = p.y();
  }
  u[N] = uN;
  v[N] = vN;
  t[N] = 1.0;

  return true;

  // create the tangent matrix
  const int M = N - 2;
  Double_Matrix J(M, M);
  Double_Vector DU(M);
  Double_Vector R(M);
  Double_Vector Rp(M);
  
  int iter = 1 ;

  while (iter < MAX_ITER){
    iter++ ;
    myresid(N, gf, u, v, R); 

    for (int i = 0; i < M; i++){
      t[i + 1] += eps;
      double tempu = u[i + 1];
      double tempv = v[i + 1];
      SPoint2 p = gf->geodesic(SPoint2(u0, v0), SPoint2(uN, vN), t[i + 1]);
      u[i + 1] = p.x();
      v[i + 1] = p.y();
      myresid(N, gf, u, v, Rp);
      for (int j = 0; j < M; j++){
        J(i, j) = (Rp(j) - R(j)) / eps;
      }
      t[i + 1] -= eps;
      u[i + 1] = tempu;
      v[i + 1] = tempv;
    }

    if (M == 1)
      DU(0) = R(0) / J(0, 0);
    else
      J.lu_solve(R, DU);
    
    for (int i = 0; i < M; i++){
      t[i + 1] -= DU(i);
      SPoint2 p = gf->geodesic(SPoint2(u0, v0), SPoint2(uN, vN), t[i + 1]);
      u[i + 1] = p.x();
      v[i + 1] = p.y();
    }
    double newt_norm = DU.norm();      
    if (newt_norm < PRECISION) return true;
  }
  // FAILED, use equidistant in param space
   for (int i = 1; i < N; i++){
     t[i] = (double)i / (N - 1);
     SPoint2 p = gf->geodesic(SPoint2(u0, v0), SPoint2(uN, vN), t[i]);
     u[i] = p.x();
     v[i] = p.y();
   }
  return false;
}

bool reparamOnEdge(MVertex *v, GEdge *ge, double &param)
{
  param = 1.e6;
  Range<double> bounds = ge->parBounds(0);
  if(ge->getBeginVertex() && ge->getBeginVertex()->mesh_vertices[0] == v) 
    param = bounds.low();
  else if(ge->getEndVertex() && ge->getEndVertex()->mesh_vertices[0] == v) 
    param = bounds.high();
  else 
    v->getParameter(0, param);

  if(param < 1.e6) return true;
  return false;
}

void getEdgeVertices(GEdge *ge, MElement *ele, std::vector<MVertex*> &ve,
                     edgeContainer &edgeVertices, bool linear, int nPts = 1, 
		     std::map<MVertex*,SVector3> *disp = 0)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      if(edge.getVertex(0) == edge.getMinVertex())
        ve.insert(ve.end(), edgeVertices[p].begin(), edgeVertices[p].end());
      else
        ve.insert(ve.end(), edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else{
      MVertex *v0 = edge.getVertex(0), *v1 = edge.getVertex(1);            

      double u0 = 0., u1 = 0.;
      bool reparamOK = true;
      if(!linear && ge->geomType() != GEntity::DiscreteCurve &&
         ge->geomType() != GEntity::BoundaryLayerCurve){
        reparamOK &= reparamOnEdge(v0, ge, u0);

        if (ge->periodic(0) &&  v1 == ge->getEndVertex()->mesh_vertices[0]){
          Range<double> par = ge->parBounds(0);
          u1 = par.high();
        }         
        else
          reparamOK &= reparamOnEdge(v1, ge, u1);
      }
      double US[100];
      if(reparamOK && !linear && ge->geomType() != GEntity::DiscreteCurve){
        double relax = 1.;
        while (1){
          if (computeEquidistantParameters(ge, u0, u1, nPts + 2, US,relax))break;
          relax /= 2.0;
          if (relax < 1.e-2)break;
        } 
        if (relax < 1.e-2)Msg::Warning("failure in computing equidistant parameters %g",relax);
      }
      std::vector<MVertex*> temp;      
      for(int j = 0; j < nPts; j++){
        const double t = (double)(j + 1)/(nPts + 1);
        double uc = (1. - t) * u0 + t * u1;
        MVertex *v;
        if(!reparamOK || linear || ge->geomType() == GEntity::DiscreteCurve || 
           uc < u0 || uc > u1){ // need to treat periodic curves properly!
          SPoint3 pc = edge.interpolate(t);
          v = new MVertex(pc.x(), pc.y(), pc.z(), ge);
          v->setParameter (0,t);
        }
        else {
          GPoint pc = ge->point(US[j+1]);
	  v = new MEdgeVertex(pc.x(), pc.y(), pc.z(), ge, US[j+1]);
	  if (disp){
	    SPoint3 pc2 = edge.interpolate(t);          
	    (*disp)[v] = SVector3(pc2.x(),pc2.y(),pc2.z());
	  }
        }
        temp.push_back(v);
        ge->mesh_vertices.push_back(v);
        ve.push_back(v);
      }
      if(edge.getVertex(0) == edge.getMinVertex())
        edgeVertices[p].insert(edgeVertices[p].end(), temp.begin(), temp.end());
      else
        edgeVertices[p].insert(edgeVertices[p].end(), temp.rbegin(), temp.rend());
    }
  }
}

void getEdgeVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &ve,
                     edgeContainer &edgeVertices, bool linear, int nPts = 1, 
		     std::map<MVertex*,SVector3> *disp = 0)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);    
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      if(edge.getVertex(0) == edge.getMinVertex())
        ve.insert(ve.end(), edgeVertices[p].begin(), edgeVertices[p].end());
      else
        ve.insert(ve.end(), edgeVertices[p].rbegin(), edgeVertices[p].rend());
    }
    else{
      MVertex *v0 = edge.getVertex(0), *v1 = edge.getVertex(1);
      SPoint2 p0, p1;
      bool reparamOK = true;
      if(!linear && 
         gf->geomType() != GEntity::DiscreteSurface &&
         gf->geomType() != GEntity::BoundaryLayerSurface){
        reparamOK &= reparamOnFace(v0, gf, p0);
        reparamOK &= reparamOnFace(v1, gf, p1);
      }
      double US[100], VS[100];
      if(reparamOK && !linear && gf->geomType() != GEntity::DiscreteCurve){
        computeEquidistantParameters(gf, p0[0], p1[0], p0[1], p1[1], nPts + 2, US, VS);
      }
      std::vector<MVertex*> temp;
      for(int j = 0; j < nPts; j++){
        const double t = (double)(j + 1) / (nPts + 1);
        MVertex *v;
        if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
          SPoint3 pc = edge.interpolate(t);
          v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
        }
        else{
          GPoint pc = gf->point(US[j+1], VS[j+1]);
	  v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, US[j+1], VS[j+1]);
	  if (disp){
	    SPoint3 pc2 = edge.interpolate(t);          
	    (*disp)[v] = SVector3(pc2.x(),pc2.y(),pc2.z());
	  }
        }
        temp.push_back(v);
        gf->mesh_vertices.push_back(v);
        ve.push_back(v);
      }
      if(edge.getVertex(0) == edge.getMinVertex())
        edgeVertices[p].insert(edgeVertices[p].end(), temp.begin(), temp.end());
      else
        edgeVertices[p].insert(edgeVertices[p].end(), temp.rbegin(), temp.rend());
    }
  }
}

void getEdgeVertices(GRegion *gr, MElement *ele, 
		     std::vector<MVertex*> &ve,
                     std::set<MVertex*>& blocked,
                     edgeContainer &edgeVertices, 
		     bool linear, 
		     int nPts = 1,
		     std::map<MVertex*,SVector3> *displ = 0)
{
  for(int i = 0; i < ele->getNumEdges(); i++){
    MEdge edge = ele->getEdge(i);
    std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
    if(edgeVertices.count(p)){
      if(edge.getVertex(0) == edge.getMinVertex())
        ve.insert(ve.end(), edgeVertices[p].begin(), edgeVertices[p].end());
      else
        ve.insert(ve.end(), edgeVertices[p].rbegin(), edgeVertices[p].rend());
      blocked.insert(edgeVertices[p].begin(),edgeVertices[p].end());
      blocked.insert(edge.getMinVertex());
      blocked.insert(edge.getMaxVertex());
    }
    else{
      std::vector<MVertex*> temp;
      for(int j = 0; j < nPts; j++){
        double t = (double)(j + 1) / (nPts + 1);
        SPoint3 pc = edge.interpolate(t);
        MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
        temp.push_back(v);
        gr->mesh_vertices.push_back(v);
        ve.push_back(v);
      }
      if(edge.getVertex(0) == edge.getMinVertex())
        edgeVertices[p].insert(edgeVertices[p].end(), temp.begin(), temp.end());
      else
        edgeVertices[p].insert(edgeVertices[p].end(), temp.rbegin(), temp.rend());
    }
  }
}

void getFaceVertices(GFace *gf, 
		     MElement *incomplete, 
		     MElement *ele, 
		     std::vector<MVertex*> &vf,
                     faceContainer &faceVertices, 
		     bool linear, int nPts = 1,
		     std::map<MVertex*,SVector3> *displ = 0) {
  
  Double_Matrix points;
  int start = 0;
  

  switch (nPts){
  case 2 :
    points = gmshFunctionSpaces::find(MSH_TRI_10).points;
    start = 9;
    break;
  case 3 :
    points = gmshFunctionSpaces::find(MSH_TRI_15).points;
    start = 12;
    break;
  case 4 :
    points = gmshFunctionSpaces::find(MSH_TRI_21).points;
    start = 15;
    break;
  default :  
    // do nothing (e.g. for quad faces)
    break;
  }

  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);
    //std::vector<MVertex*> p;
    // face.getOrderedVertices(p);
    //if(faceVertices.count(p)){
    //       vf.insert(vf.end(), faceVertices[p].begin(), faceVertices[p].end());
    //     }

    faceContainer::iterator fIter = faceVertices.find(face);
    
    if(fIter!=faceVertices.end()){
      vf.insert(vf.end(), fIter->second.begin(), fIter->second.end());
    }
    else{
      SPoint2 pts[20];
      bool reparamOK = true;
      if(!linear && 
         gf->geomType() != GEntity::DiscreteSurface &&
         gf->geomType() != GEntity::BoundaryLayerSurface){
	for (int k=0;k<incomplete->getNumVertices(); k++){
	  reparamOK &= reparamOnFace(incomplete->getVertex(k), gf, pts[k]);
	}
      }
      if(face.getNumVertices() == 3){ // triangles

        std::vector<MVertex*>& vtcs = faceVertices[face];
          
        for(int k = start ; k < points.size1() ; k++){
          MVertex *v;
          const double t1 = points(k, 0);
          const double t2 = points(k, 1);
          if(linear || gf->geomType() == GEntity::DiscreteSurface){
            SPoint3 pc = face.interpolate(t1, t2);
            v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
          }
          else{

            //             SPoint3 pos;
            //             incomplete->pnt(t1,t2,0.,pos);
            //             double X(pos.x());
            //             double Y(pos.y());
            //             double Z(pos.z());
            
            
	    double X(0),Y(0),Z(0),GUESS[2]={0,0};

	    for (int j=0; j<incomplete->getNumVertices(); j++){
              
	      double sf ; incomplete->getShapeFunction(j,t1,t2,0,sf);
	      MVertex *vt = incomplete->getVertex(j);
              
	      X += sf * vt->x();
	      Y += sf * vt->y();
	      Z += sf * vt->z();
	      if (reparamOK){
		GUESS[0] += sf * pts[j][0];
		GUESS[1] += sf * pts[j][1];
	      }
	    }
	    if (reparamOK){
	      GPoint gp = gf->closestPoint(SPoint3(X,Y,Z),GUESS);
	      if (gp.g()){
		v = new MFaceVertex(gp.x(), gp.y(), gp.z(), gf, gp.u(), gp.v());
	      }
	      else{
		v = new MVertex(X,Y,Z, gf);
	      }
	    }
	    else{
	      v = new MVertex(X,Y,Z, gf);
	    }
	    if (displ){
	      SPoint3 pc2 = face.interpolate(t1, t2);
	      (*displ)[v] = SVector3(pc2.x(),pc2.y(),pc2.z());
	    }	    
          }
          // should be expensive -> induces a new search each time
          // faceVertices[p].push_back(v);
          vtcs.push_back(v);
          gf->mesh_vertices.push_back(v);
          vf.push_back(v);
        }
      }
      else if(face.getNumVertices() == 4){ // quadrangles

        std::vector<MVertex*>& vtcs = faceVertices[face];
        
        for(int j = 0; j < nPts; j++){
          for(int k = 0; k < nPts; k++){
            MVertex *v;
            // parameters are between -1 and 1
            double t1 = 2. * (double)(j + 1) / (nPts + 1) - 1.;
            double t2 = 2. * (double)(k + 1) / (nPts + 1) - 1.;
            if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
              SPoint3 pc = face.interpolate(t1, t2);
              v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
            }
            else{
              double uc = 0.25 * ((1 - t1) * (1 - t2) * pts[0][0] + 
                                  (1 + t1) * (1 - t2) * pts[1][0] + 
                                  (1 + t1) * (1 + t2) * pts[2][0] + 
                                  (1 - t1) * (1 + t2) * pts[3][0]); 
              double vc = 0.25 * ((1 - t1) * (1 - t2) * pts[0][1] + 
                                  (1 + t1) * (1 - t2) * pts[1][1] + 
                                  (1 + t1) * (1 + t2) * pts[2][1] + 
                                  (1 - t1) * (1 + t2) * pts[3][1]); 
              GPoint pc = gf->point(uc, vc);
              v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
            }
            // faceVertices[p].push_back(v);
            vtcs.push_back(v);
            gf->mesh_vertices.push_back(v);
            vf.push_back(v);
          }
        }
      }
    }
  }  
}


void getFaceVertices(GFace *gf, MElement *ele, std::vector<MVertex*> &vf,
                     faceContainer &faceVertices, bool linear, int nPts = 1)
{
  
  Double_Matrix points;
  int start = 0;

  switch (nPts){
  case 2 :
    points = gmshFunctionSpaces::find(MSH_TRI_10).points;
    start = 9;
    break;
  case 3 :
    points = gmshFunctionSpaces::find(MSH_TRI_15).points;
    start = 12;
    break;
  case 4 :
    points = gmshFunctionSpaces::find(MSH_TRI_21).points;
    start = 15;
    break;
  default :  
    // do nothing (e.g. for quad faces)
    break;
  }

  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);
    // std::vector<MVertex*> p;
//     face.getOrderedVertices(p);
//     if(faceVertices.count(p)){
//       vf.insert(vf.end(), faceVertices[p].begin(), faceVertices[p].end());
//     }

    faceContainer::iterator fIter = faceVertices.find(face);

    if (fIter!=faceVertices.end()) {
      vf.insert(vf.end(), fIter->second.begin(), fIter->second.end());
    }
    else{

      std::vector<MVertex*>& vtcs = faceVertices[face];
      
      SPoint2 p0, p1, p2, p3;
      bool reparamOK = true;
      if(!linear && 
         gf->geomType() != GEntity::DiscreteSurface &&
         gf->geomType() != GEntity::BoundaryLayerSurface){
        reparamOK &= reparamOnFace(ele->getVertex(0), gf, p0);
        reparamOK &= reparamOnFace(ele->getVertex(1), gf, p1);
        reparamOK &= reparamOnFace(ele->getVertex(2), gf, p2);
        if(face.getNumVertices() == 4)
          reparamOK &= reparamOnFace(ele->getVertex(3), gf, p3);
      }
      if(face.getNumVertices() == 3){ // triangles
        for(int k = start ; k < points.size1() ; k++){
          MVertex *v;
          const double t1 = points(k, 0);
          const double t2 = points(k, 1);
          if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
            SPoint3 pc = face.interpolate(t1, t2);
            v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
          }
          else{
            double uc = (1. - t1 - t2) * p0[0] + t1 * p1[0] + t2 * p2[0];
            double vc = (1. - t1 - t2) * p0[1] + t1 * p1[1] + t2 * p2[1];
            GPoint pc = gf->point(uc, vc);
            v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
            v->setParameter (0,uc);
            v->setParameter (1,vc);
          }
          // faceVertices[p].push_back(v);
          vtcs.push_back(v);
          gf->mesh_vertices.push_back(v);
          vf.push_back(v);
        }
      }
      else if(face.getNumVertices() == 4){ // quadrangles
        for(int j = 0; j < nPts; j++){
          for(int k = 0; k < nPts; k++){
            MVertex *v;
            // parameters are between -1 and 1
            double t1 = 2. * (double)(j + 1) / (nPts + 1) - 1.;
            double t2 = 2. * (double)(k + 1) / (nPts + 1) - 1.;
            if(!reparamOK || linear || gf->geomType() == GEntity::DiscreteSurface){
              SPoint3 pc = face.interpolate(t1, t2);
              v = new MVertex(pc.x(), pc.y(), pc.z(), gf);
            }
            else{
              double uc = 0.25 * ((1 - t1) * (1 - t2) * p0[0] + 
                                  (1 + t1) * (1 - t2) * p1[0] + 
                                  (1 + t1) * (1 + t2) * p2[0] + 
                                  (1 - t1) * (1 + t2) * p3[0]); 
              double vc = 0.25 * ((1 - t1) * (1 - t2) * p0[1] + 
                                  (1 + t1) * (1 - t2) * p1[1] + 
                                  (1 + t1) * (1 + t2) * p2[1] + 
                                  (1 - t1) * (1 + t2) * p3[1]); 
              GPoint pc = gf->point(uc, vc);
              v = new MFaceVertex(pc.x(), pc.y(), pc.z(), gf, uc, vc);
            }
            // faceVertices[p].push_back(v);
            vtcs.push_back(v);
            gf->mesh_vertices.push_back(v);
            vf.push_back(v);
          }
        }
      }
    }
  }
}

void reorientTrianglePoints(std::vector<MVertex*>& vtcs,int orientation,bool swap) {

  if (vtcs.size() == 1) return;
  
  size_t nbPts = vtcs.size();

  if (nbPts > 3) Msg::Error("Interior face nodes reorientation not supported for order > 4");
  std::vector<MVertex*> tmp(nbPts);

  // rotation
  // --------

  // --- interior "principal vertices"
  
  // for (int i=0;i<3;i++) tmp[(i+orientation)%3] = vtcs[i];
  
  for (int i=0;i<3;i++) tmp[(i+orientation)%3] = vtcs[i];

  
  // normal swap
  // -----------
  
  if (swap) {
    // --- interior "principal vertices"


    vtcs[orientation]           = tmp[orientation];
    vtcs[(orientation + 1) % 3] = tmp[(orientation+2)%3];
    vtcs[(orientation + 2) % 3] = tmp[(orientation+1)%3];
    
    // for (int i=0;i<2;i++) for (int j=0;j<2-i;j++) vtcs[i*2+j] = tmp[i+j*2];
  }
  
  // no swap
  // -------
  
  else vtcs = tmp;
} 


// KH: check face orientation wrt element ... 

void getFaceVertices(GRegion *gr, MElement *ele,
                     std::vector<MVertex*> &vf,
                     std::set<MVertex*>& blocked,
                     faceContainer &faceVertices,
                     edgeContainer& edgeVertices,
                     bool linear, int nPts = 1)
{
  
  
  Double_Matrix points;
  int start = 0;
  
  switch (nPts){
  case 2 :
    points = gmshFunctionSpaces::find(MSH_TRI_10).points;
    start = 9;
    break;
  case 3 :
    points = gmshFunctionSpaces::find(MSH_TRI_15).points;
    start = 12;
    break;
  case 4 :
    points = gmshFunctionSpaces::find(MSH_TRI_21).points;
    start = 15;
    break;
  default :  
    // do nothing (e.g. for quad faces)
    break;
  }
  
  
  for(int i = 0; i < ele->getNumFaces(); i++){
    MFace face = ele->getFace(i);

    faceContainer::iterator fIter = faceVertices.find(face);

    if (fIter!=faceVertices.end()) {

      int orientation;
      bool swap;
      
      std::vector<MVertex*> vtcs = fIter->second;
      if (fIter->first.computeCorrespondence(face,orientation,swap)) {
        reorientTrianglePoints(vtcs,orientation,swap);
      }
      else Msg::Error("Error in face lookup for recuperation of high order face nodes");
      vf.insert(vf.end(), vtcs.begin(), vtcs.end());

      blocked.insert(vtcs.begin(),vtcs.end());
      blocked.insert(face.getVertex(0));
      blocked.insert(face.getVertex(1));
      blocked.insert(face.getVertex(2));
    }
    else{
      std::vector<MVertex*>& vtcs = faceVertices[face];        
      
      if(face.getNumVertices() == 3){ // triangles

        // construct incomplete element to take into account curved edges on surface boundaries

        std::vector<MVertex*> hoEdgeNodes;
        
        for (int i=0;i<3;i++) {

          MVertex* v0 = face.getVertex(i);
          MVertex* v1 = face.getVertex((i+1)%3);
          
          edgeContainer::iterator eIter = edgeVertices.find(std::pair<MVertex*,MVertex*>(std::min(v0,v1),std::max(v0,v1)));

          if (eIter == edgeVertices.end()) {
            printf("Could not find ho nodes for an edge");
          }

          if (v0 == eIter->first.first) hoEdgeNodes.insert(hoEdgeNodes.end(),eIter->second.begin(),eIter->second.end());
          else                          hoEdgeNodes.insert(hoEdgeNodes.end(),eIter->second.rbegin(),eIter->second.rend());
        }

        MTriangleN incomplete(face.getVertex(0),
                              face.getVertex(1),
                              face.getVertex(2),
                              hoEdgeNodes,nPts+1);

        double X(0),Y(0),Z(0);
        
        for (int k=start;k<points.size1();k++) {
          
          double t1 = points(k,0);
          double t2 = points(k,1);

          SPoint3 pos;
          incomplete.pnt(t1,t2,0,pos);
          MVertex* v = new MVertex(pos.x(),pos.y(),pos.z(),gr);
          
          
          // for (int j=0; j<incomplete.getNumVertices(); j++){
            
//             double sf ; incomplete.getShapeFunction(j,t1,t2,0,sf);
//             MVertex *vt = incomplete.getVertex(j);
            
//             X += sf * vt->x();
//             Y += sf * vt->y();
//             Z += sf * vt->z();
//           }

//           MVertex* v = new MVertex(X,Y,Z,gr);
  
          
//           SPoint3 pc = face.interpolate(t1, t2);
//           MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
          // faceVertices[p].push_back(v);
          vtcs.push_back(v);
          gr->mesh_vertices.push_back(v);
          vf.push_back(v);
        } 
        
//         for(int j = 0; j < nPts; j++){
//           for(int k = 0 ; k < nPts - j - 1; k++){
            
//             // KH: inverted direction to stick with triangle vertex numbering
//             // is not consistent with function space definitions for p>4
//             // 
//             // 2
//             // | \
//             // 0 - 1
//             // 
//             // double t1 = (double)(j + 1) / (nPts + 1);
//             // double t2 = (double)(k + 1) / (nPts + 1);
//             double t1 = (double)(k + 1) / (nPts + 1);
//             double t2 = (double)(j + 1) / (nPts + 1);

//             SPoint3 pc = face.interpolate(t1, t2);
//             MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
//             // faceVertices[p].push_back(v);
//             vtcs.push_back(v);
//             gr->mesh_vertices.push_back(v);
//             vf.push_back(v);
//           }
//         }
      }
      else if(face.getNumVertices() == 4){ // quadrangles
        for(int j = 0; j < nPts; j++){
          for(int k = 0; k < nPts; k++){
            // parameters are between -1 and 1
            double t1 = 2. * (double)(j + 1) / (nPts + 1) - 1.;
            double t2 = 2. * (double)(k + 1) / (nPts + 1) - 1.;
            SPoint3 pc = face.interpolate(t1, t2);
            MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
            // faceVertices[p].push_back(v);
            vtcs.push_back(v);
            gr->mesh_vertices.push_back(v);
            vf.push_back(v);
          }
        }
      }
    }
  }
}


void getRegionVertices(GRegion *gr, 
		       MElement *incomplete, 
		       MElement *ele, 
		       std::vector<MVertex*> &vr,
		       bool linear, int nPts = 1)
{

  Double_Matrix points;
  int start = 0;

  switch (nPts){
  case 3 :
    points = gmshFunctionSpaces::find(MSH_TET_35).points;
    start = 34;
    break;
  case 4 :
    points = gmshFunctionSpaces::find(MSH_TET_56).points;
    start = 52;
    break;
  default :  
    return;
    break;
  }

  for(int k = start ; k < points.size1() ; k++){
    MVertex *v;
    const double t1 = points(k, 0);
    const double t2 = points(k, 1);
    const double t3 = points(k, 2);
    
    SPoint3 pos;
    incomplete->pnt(t1,t2,t3,pos);
    v = new MVertex(pos.x(),pos.y(),pos.z(),gr);
    
    // FIXME: KOEN - I had to comment this out (MElement does not have
    // pnt() member) -- CG

    // SPoint3 pos;
    // incomplete->pnt(t1,t2,t3,pos);
    // v = new MVertex(pos.x(),pos.y(),pos.z(),gr);
    
    //     double X(0),Y(0),Z(0);
    //     for (int j=0; j<incomplete->getNumVertices(); j++){
    //       double sf ; incomplete->getShapeFunction(j,t1,t2,t3,sf);
    //       MVertex *vt = incomplete->getVertex(j);
    //       X += sf * vt->x();
    //       Y += sf * vt->y();
    //       Z += sf * vt->z();
    //     }
    //    v = new MVertex(X,Y,Z, gr);
    
    gr->mesh_vertices.push_back(v);
    vr.push_back(v);
  }
}


void setHighOrder(GEdge *ge, edgeContainer &edgeVertices, bool linear, 
                  int nbPts = 1, std::map<MVertex*,SVector3> *displ = 0)
{
  std::vector<MLine*> lines2;
  for(unsigned int i = 0; i < ge->lines.size(); i++){
    MLine *l = ge->lines[i];
    std::vector<MVertex*> ve;
    getEdgeVertices(ge, l, ve, edgeVertices, linear, nbPts, displ);
    if(nbPts == 1)
      lines2.push_back(new MLine3(l->getVertex(0), l->getVertex(1), ve[0]));
    else
      lines2.push_back(new MLineN(l->getVertex(0), l->getVertex(1), ve));      
    delete l;
  }
  ge->lines = lines2;
  ge->deleteVertexArrays();
}

void setHighOrder(GFace *gf, edgeContainer &edgeVertices, 
                  faceContainer &faceVertices, bool linear, bool incomplete,
                  int nPts = 1, std::map<MVertex*,SVector3> *displ = 0)
{
  std::vector<MTriangle*> triangles2;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gf, t, ve, edgeVertices, linear, nPts,displ);
    if(nPts == 1){
      triangles2.push_back
        (new MTriangle6(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                        ve[0], ve[1], ve[2]));
    }
    else{
      if(incomplete){
        triangles2.push_back
          (new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          ve, nPts + 1));
      }
      else{
	if (0 && gf->geomType() == GEntity::Plane){
	  getFaceVertices(gf, t, vf, faceVertices, linear, nPts);
	}
	else{
	  MTriangleN incpl (t->getVertex(0), t->getVertex(1), t->getVertex(2),
			    ve, nPts + 1);
	  getFaceVertices(gf, &incpl, t, vf, faceVertices, linear, nPts,displ);
	}
        ve.insert(ve.end(), vf.begin(), vf.end());
        triangles2.push_back
          (new MTriangleN(t->getVertex(0), t->getVertex(1), t->getVertex(2),
                          ve, nPts + 1));
      }
    }
    delete t;
  }
  gf->triangles = triangles2;
  
  std::vector<MQuadrangle*> quadrangles2;
  for(unsigned int i = 0; i < gf->quadrangles.size(); i++){
    MQuadrangle *q = gf->quadrangles[i];
    std::vector<MVertex*> ve, vf;
    getEdgeVertices(gf, q, ve, edgeVertices, linear, nPts,displ);
    if(incomplete){
      quadrangles2.push_back
        (new MQuadrangle8(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                          q->getVertex(3), ve[0], ve[1], ve[2], ve[3]));
    }
    else{
      getFaceVertices(gf, q, vf, faceVertices, linear, nPts);
      quadrangles2.push_back
        (new MQuadrangle9(q->getVertex(0), q->getVertex(1), q->getVertex(2),
                          q->getVertex(3), ve[0], ve[1], ve[2], ve[3], vf[0]));
    }
    delete q;
  }
  gf->quadrangles = quadrangles2;
  gf->deleteVertexArrays();
}

void setHighOrder(GRegion *gr, edgeContainer &edgeVertices, 
                  faceContainer &faceVertices, bool linear, bool incomplete,
                  int nPts = 1, std::map<MVertex*,SVector3> *displ = 0)
{
  int nbCorr = 0;
  
  std::vector<MTetrahedron*> tetrahedra2;
  for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
    MTetrahedron *t = gr->tetrahedra[i];

    std::set<MVertex*> blocked;
    
    std::vector<MVertex*> ve,vf,vr;
    getEdgeVertices(gr, t, ve, blocked,edgeVertices, linear, nPts,displ);
    if (nPts == 1){
      tetrahedra2.push_back
	(new MTetrahedron10(t->getVertex(0), t->getVertex(1), t->getVertex(2), 
			    t->getVertex(3), ve[0], ve[1], ve[2], ve[3], ve[4], ve[5]));
    }
    else{
      getFaceVertices(gr, t, vf, blocked, faceVertices, edgeVertices, linear, nPts);
      ve.insert(ve.end(), vf.begin(), vf.end());     
      MTetrahedronN incpl (t->getVertex(0), t->getVertex(1), t->getVertex(2), t->getVertex(3),
			   ve, nPts + 1);
      getRegionVertices(gr, &incpl, t, vr, linear, nPts); 
      ve.insert(ve.end(), vr.begin(), vr.end());

      MTetrahedron* n = new MTetrahedronN(t->getVertex(0), t->getVertex(1), t->getVertex(2), t->getVertex(3),ve, nPts + 1);

      if (!mappingIsInvertible(n)) {
        Msg::Warning("Found invalid curved volume element (# %d in list) ",i);
        
        // if (deformElement(n,gr,blocked)) {
//           if (mappingIsInvertible(n)) printf(" - corrected using Poisson smoothing\n");
//           else                        printf(" - could not correct the mapping\n");
//           nbCorr++;
//         }
      }
      tetrahedra2.push_back (n);
    }
    delete t;
  }
  gr->tetrahedra = tetrahedra2;

  std::vector<int> invalid;
  
  if (nbCorr != 0) {
    for(unsigned int i = 0; i < gr->tetrahedra.size(); i++){
      if (!mappingIsInvertible(gr->tetrahedra[i])) invalid.push_back(i);
    }

    if (invalid.size()!=0) {
      Msg::Warning("We have %d invalid elements remaining\n",(int) invalid.size());
      std::vector<int>::iterator iIter = invalid.begin();
      for (;iIter!=invalid.end();++iIter) printf("%d ",*iIter);
      printf("\n");
    }
  }
  

  std::vector<MHexahedron*> hexahedra2;
  for(unsigned int i = 0; i < gr->hexahedra.size(); i++){
    MHexahedron *h = gr->hexahedra[i];
    std::vector<MVertex*> ve, vf;
    std::set<MVertex*> blocked;
    getEdgeVertices(gr, h, ve, blocked, edgeVertices, linear, nPts,displ);
    if(incomplete){
      hexahedra2.push_back
        (new MHexahedron20(h->getVertex(0), h->getVertex(1), h->getVertex(2), 
                           h->getVertex(3), h->getVertex(4), h->getVertex(5), 
                           h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2], 
                           ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10], 
                           ve[11]));
    }
    else{
      getFaceVertices(gr, h, vf, blocked, faceVertices, edgeVertices, linear, nPts);
      SPoint3 pc = h->barycenter();
      MVertex *v = new MVertex(pc.x(), pc.y(), pc.z(), gr);
      gr->mesh_vertices.push_back(v);
      hexahedra2.push_back
        (new MHexahedron27(h->getVertex(0), h->getVertex(1), h->getVertex(2), 
                           h->getVertex(3), h->getVertex(4), h->getVertex(5), 
                           h->getVertex(6), h->getVertex(7), ve[0], ve[1], ve[2], 
                           ve[3], ve[4], ve[5], ve[6], ve[7], ve[8], ve[9], ve[10], 
                           ve[11], vf[0], vf[1], vf[2], vf[3], vf[4], vf[5], v));
    }
    delete h;
  }
  gr->hexahedra = hexahedra2;

  std::vector<MPrism*> prisms2;
  for(unsigned int i = 0; i < gr->prisms.size(); i++){
    MPrism *p = gr->prisms[i];
    std::vector<MVertex*> ve, vf;
    std::set<MVertex*> blocked;
    getEdgeVertices(gr, p, ve, blocked, edgeVertices, linear, nPts,displ);
    if(incomplete){
      prisms2.push_back
        (new MPrism15(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
                      p->getVertex(3), p->getVertex(4), p->getVertex(5), 
                      ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8]));
    }
    else{
      getFaceVertices(gr, p, vf, blocked, faceVertices, edgeVertices, linear, nPts);
      prisms2.push_back
        (new MPrism18(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
                      p->getVertex(3), p->getVertex(4), p->getVertex(5), 
                      ve[0], ve[1], ve[2], ve[3], ve[4], ve[5], ve[6], ve[7], ve[8],
                      vf[0], vf[1], vf[2]));
    }
    delete p;
  }
  gr->prisms = prisms2;

  std::vector<MPyramid*> pyramids2;
  for(unsigned int i = 0; i < gr->pyramids.size(); i++){
    MPyramid *p = gr->pyramids[i];
    std::vector<MVertex*> ve, vf;
    std::set<MVertex*> blocked;
    getEdgeVertices(gr, p, ve, blocked, edgeVertices, linear, nPts,displ);
    if(incomplete){
      pyramids2.push_back
        (new MPyramid13(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
                        p->getVertex(3), p->getVertex(4), ve[0], ve[1], ve[2], 
                        ve[3], ve[4], ve[5], ve[6], ve[7]));
    }
    else{
      getFaceVertices(gr, p, vf, blocked, faceVertices, edgeVertices, linear, nPts);
      pyramids2.push_back
        (new MPyramid14(p->getVertex(0), p->getVertex(1), p->getVertex(2), 
                        p->getVertex(3), p->getVertex(4), ve[0], ve[1], ve[2], 
                        ve[3], ve[4], ve[5], ve[6], ve[7], vf[0]));
    }
    delete p;
  }
  gr->pyramids = pyramids2;
  gr->deleteVertexArrays();
}

template<class T>
void setFirstOrder(GEntity *e, std::vector<T*> &elements)
{
  std::vector<T*> elements1;
  for(unsigned int i = 0; i < elements.size(); i++){
    T *ele = elements[i];
    int n = ele->getNumPrimaryVertices();
    std::vector<MVertex*> v1;
    for(int j = 0; j < n; j++)
      v1.push_back(ele->getVertex(j));
    for(int j = n; j < ele->getNumVertices(); j++)
      ele->getVertex(j)->setVisibility(-1);
    elements1.push_back(new T(v1));
    delete ele;
  }
  elements = elements1;
  e->deleteVertexArrays();
}

void removeHighOrderVertices(GEntity *e)
{
  std::vector<MVertex*> v1;
  for(unsigned int i = 0; i < e->mesh_vertices.size(); i++){
    if(e->mesh_vertices[i]->getVisibility() < 0)
      delete e->mesh_vertices[i];
    else
      v1.push_back(e->mesh_vertices[i]);
  }
  e->mesh_vertices = v1;
}

void SetOrder1(GModel *m)
{
  // replace all elements with first order elements and mark all
  // unused vertices with a -1 visibility flag
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it){
    setFirstOrder(*it, (*it)->lines);
  }
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    setFirstOrder(*it, (*it)->triangles);
    setFirstOrder(*it, (*it)->quadrangles);
  }
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it){
    setFirstOrder(*it, (*it)->tetrahedra);
    setFirstOrder(*it, (*it)->hexahedra);
    setFirstOrder(*it, (*it)->prisms);
    setFirstOrder(*it, (*it)->pyramids);
  }

  // remove all vertices with a -1 visibility flag
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    removeHighOrderVertices(*it);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    removeHighOrderVertices(*it);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    removeHighOrderVertices(*it);
}

bool straightLine(std::vector<MVertex*> &l, MVertex *n1, MVertex *n2)
{
  // x = a * t + b
  // x1 = b
  // x2 = a + b
  for(unsigned int i = 0; i < l.size(); i++){
    MVertex *v = l[i];
    double b = n1->x();
    double a = n2->x() - b;
    double t = (v->x() - b) / a;
    double by = n1->y();
    double ay = n2->y() - by;
    double y = ay * t + by;
    if(fabs(y-v->y()) > 1.e-07 * CTX.lc){
      return false;      
    }
  }
  return true;
}

static double mesh_functional_distorsion(MTriangle *t, double u, double v)
{
  // compute uncurved element jacobian d_u x and d_v x
  double mat[2][3];  
  // t->getPrimaryJacobian(0, 0, 0, mat);
  t->getJacobian(0, 0, 0, mat);
  
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal1[3];
  prodve(v1, v2, normal1);
  double nn = sqrt(SQU(normal1[0]) + SQU(normal1[1]) + SQU(normal1[2]));
  
  // compute uncurved element jacobian d_u x and d_v x
  t->getJacobian(u, v, 0, mat);
  double v1b[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2b[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal[3];
  prodve(v1b, v2b, normal);
  
  double sign;
  prosca(normal1, normal, &sign);
  double det = norm3(normal) * (sign > 0 ? 1. : -1.) / nn;  

  // compute distorsion
  double dist = std::min(1. / det, det); 
  return dist;
}

void getMinMaxJac (MTriangle *t, double &minJ, double &maxJ)
{
  double mat[2][3];  
  int n = 3;
  // t->getPrimaryJacobian(0, 0, 0, mat);
  t->getJacobian(0, 0, 0, mat);
  double v1[3] = {mat[0][0], mat[0][1], mat[0][2]};
  double v2[3] = {mat[1][0], mat[1][1], mat[1][2]};
  double normal1[3], normal[3];
  prodve(v1, v2, normal1);
  double nn = sqrt(SQU(normal1[0]) + SQU(normal1[1]) + SQU(normal1[2]));
  for(int i = 0; i < n; i++){
    for(int k = 0; k < n - i; k++){
      t->getJacobian((double)i / (n - 1), (double)k / (n - 1), 0, mat);
      double v1b[3] = {mat[0][0], mat[0][1], mat[0][2]};
      double v2b[3] = {mat[1][0], mat[1][1], mat[1][2]};
      prodve(v1b, v2b, normal);
      double sign; 
      prosca(normal1, normal, &sign);
      double det = norm3(normal) * (sign > 0 ? 1. : -1.) / nn;
      minJ = std::min(1. / det, std::min(det, minJ));
      maxJ = std::max(det, maxJ);
    }
  }
}

struct smoothVertexDataHO{
  MVertex *v;
  GFace *gf;
  std::vector<MTriangle*> ts;
}; 

struct smoothVertexDataHON{
  std::vector<MVertex*> v;
  GFace *gf;
  std::vector<MTriangle*> ts;
}; 

double smoothing_objective_function_HighOrder(double U, double V, MVertex *v, 
                                              std::vector<MTriangle*> &ts, GFace *gf)
{
  GPoint gp = gf->point(U, V);
  const double oldX = v->x();
  const double oldY = v->y();
  const double oldZ = v->z();

  v->x() = gp.x();
  v->y() = gp.y();
  v->z() = gp.z();

  double minJ =  1.e22;
  double maxJ = -1.e22;
  for (unsigned int i = 0; i < ts.size(); i++){
    getMinMaxJac (ts[i], minJ, maxJ);
  }
  v->x() = oldX;
  v->y() = oldY;
  v->z() = oldZ;
  
  return -minJ;
}

void deriv_smoothing_objective_function_HighOrder(double U, double V, 
                                                  double &F, double &dFdU,
                                                  double &dFdV, void *data)
{
  smoothVertexDataHO *svd = (smoothVertexDataHO*)data;
  MVertex *v = svd->v;
  const double LARGE = -1.e5;
  const double SMALL = 1./LARGE;
  F   = smoothing_objective_function_HighOrder(U, V, v, svd->ts, svd->gf);
  double F_U = smoothing_objective_function_HighOrder(U + SMALL, V, v, svd->ts, svd->gf);
  double F_V = smoothing_objective_function_HighOrder(U, V + SMALL, v, svd->ts, svd->gf);
  dFdU = (F_U - F) * LARGE;
  dFdV = (F_V - F) * LARGE;
}

double smooth_obj_HighOrder(double U, double V, void *data)
{
  smoothVertexDataHO *svd = (smoothVertexDataHO*)data;
  return  smoothing_objective_function_HighOrder(U, V, svd->v, svd->ts, svd->gf); 
}

double smooth_obj_HighOrderN(double *uv, void *data)
{
  smoothVertexDataHON *svd = (smoothVertexDataHON*)data;
  double oldX[10],oldY[10],oldZ[10];
  for (unsigned int i = 0; i < svd->v.size(); i++){
    GPoint gp = svd->gf->point(uv[2 * i], uv[2 * i + 1]);
    oldX[i] = svd->v[i]->x();
    oldY[i] = svd->v[i]->y();
    oldZ[i] = svd->v[i]->z();
    svd->v[i]->x() = gp.x();
    svd->v[i]->y() = gp.y();
    svd->v[i]->z() = gp.z();
  }
  double minJ =  1.e22;
  double maxJ = -1.e22;
  for(unsigned int i = 0; i < svd->ts.size(); i++){
    getMinMaxJac (svd->ts[i], minJ, maxJ);
  }
  for(unsigned int i = 0; i < svd->v.size(); i++){
    svd->v[i]->x() = oldX[i];
    svd->v[i]->y() = oldY[i];
    svd->v[i]->z() = oldZ[i];
  }
  return -minJ;
}

void deriv_smoothing_objective_function_HighOrderN(double *uv, double *dF, 
                                                   double &F, void *data)
{
  const double LARGE = -1.e2;
  const double SMALL = 1. / LARGE;
  smoothVertexDataHON *svd = (smoothVertexDataHON*)data;
  F = smooth_obj_HighOrderN(uv, data);
  for (unsigned int i = 0; i < svd->v.size(); i++){
    uv[i] += SMALL;
    dF[i] = (smooth_obj_HighOrderN(uv, data) - F) * LARGE;
    uv[i] -= SMALL;
  }
}

void optimizeNodeLocations(GFace *gf, smoothVertexDataHON &vdN, double eps = .2)
{
  if(!vdN.v.size()) return;
  double uv[20];
  for (unsigned int i = 0; i < vdN.v.size(); i++){
    if (!vdN.v[i]->getParameter(0, uv[2 * i])){
      Msg::Error("Node location optimization failed");
      return;
    }
    if (!vdN.v[i]->getParameter(1, uv[2 * i + 1])){
      Msg::Error("Node location optimization failed");
      return;
    }
  }

  double F = -smooth_obj_HighOrderN(uv, &vdN);
  if (F < eps){
    double val;
    minimize_N(2 * vdN.v.size(), 
               smooth_obj_HighOrderN, 
               deriv_smoothing_objective_function_HighOrderN, 
               &vdN, 1, uv,val);
    double Fafter = -smooth_obj_HighOrderN(uv, &vdN);
    printf("%12.5E %12.5E\n", F, Fafter);
    if (F < Fafter){
      for (unsigned int i = 0; i < vdN.v.size(); i++){
        vdN.v[i]->setParameter(0, uv[2 * i]);
        vdN.v[i]->setParameter(1, uv[2 * i + 1]);
        GPoint gp = gf->point(uv[2 * i], uv[2 * i + 1]);
        vdN.v[i]->x() = gp.x();
        vdN.v[i]->y() = gp.y();
        vdN.v[i]->z() = gp.z();
      }
    }     
  }
}

void optimizeHighOrderMeshInternalNodes(GFace *gf)
{
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    smoothVertexDataHON vdN;
    int start = t->getNumVertices() - t->getNumFaceVertices();
    for (int j=start;j<t->getNumVertices();j++)
      vdN.v.push_back(t->getVertex(j));
    vdN.gf = gf;
    vdN.ts.push_back(t);
    optimizeNodeLocations(gf, vdN, .9);
  }
}

bool optimizeHighOrderMesh(GFace *gf, edgeContainer &edgeVertices)
{
  v2t_cont adjv;
  buildVertexToTriangle(gf->triangles, adjv);

  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }
  /*
  v2t_cont :: iterator it = adjv.begin();      
  while (it != adjv.end()){
    MVertex *ver= it->first;
    GEntity *ge = ver->onWhat();
    if (ge->dim() == 2){
      double initu,initv;
      ver->getParameter(0, initu);
      ver->getParameter(1, initv);        

      smoothVertexDataHON vdN;
      vdN.ts = it->second;
      for (int i=0;i<vdN.ts.size();i++){
        MTriangle *t = vdN.ts[i];
      }

      vdN.v = e;
      vdN.gf = gf;

      double val;      
      double F = -smooth_obj_HighOrder(initu,initv, &vd);
      if (F < .2){
        minimize_2(smooth_obj_HighOrder, 
             deriv_smoothing_objective_function_HighOrder, &vd, 1, initu,initv,val);
        double Fafter = -smooth_obj_HighOrder(initu,initv, &vd);
        if (F < Fafter){
          success = true;
          ver->setParameter(0,initu);
          ver->setParameter(1,initv);
          GPoint gp = gf->point(initu,initv);
          ver->x() = gp.x();
          ver->y() = gp.y();
          ver->z() = gp.z();  
        }
      }                         
    }
    ++it;
  }
  */
  bool success = false;
  
  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      if(n2 < n4)
        e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n2, n4)];
      else
        e = edgeVertices[std::make_pair<MVertex*, MVertex*> (n4, n2)];

      if (e.size() < 5){
        smoothVertexDataHON vdN;
        vdN.v = e;
        vdN.gf = gf;
        vdN.ts.clear();
        vdN.ts.push_back(t1);
        vdN.ts.push_back(t2);   
        optimizeNodeLocations(gf, vdN);
      }
    }
  }

  return success;
}

double angle3Points ( MVertex *p1, MVertex *p2, MVertex *p3 ){
  SVector3 a(p1->x()-p2->x(),p1->y()-p2->y(),p1->z()-p2->z());
  SVector3 b(p3->x()-p2->x(),p3->y()-p2->y(),p3->z()-p2->z());
  SVector3 c = crossprod(a,b);
  double sinA = c.norm();
  double cosA = dot(a,b);
  //  printf("%d %d %d -> %g %g\n",p1->iD,p2->iD,p3->iD,cosA,sinA);
  return atan2 (sinA,cosA);  
}

bool smoothInternalEdges(GFace *gf, edgeContainer &edgeVertices)
{
  typedef std::map<std::pair<MVertex*, MVertex*>, std::vector<MElement*> > edge2tris;
  edge2tris e2t;
  for(unsigned int i = 0; i < gf->triangles.size(); i++){
    MTriangle *t = gf->triangles[i];
    for(int j = 0; j < t->getNumEdges(); j++){
      MEdge edge = t->getEdge(j);
      std::pair<MVertex*, MVertex*> p(edge.getMinVertex(), edge.getMaxVertex());
      e2t[p].push_back(t);
    }
  }

  bool success = false;

  const int NBST = 10;

  for(edge2tris::iterator it = e2t.begin(); it != e2t.end(); ++it){
    std::pair<MVertex*, MVertex*> edge = it->first;
    std::vector<MVertex*> e1, e2, e3, e4, e;
    std::vector<MElement*> triangles = it->second;
    if(triangles.size() == 2){
      MVertex *n2 = edge.first; 
      MVertex *n4 = edge.second;
      MTriangle *t1 = (MTriangle*)triangles[0];
      MTriangle *t2 = (MTriangle*)triangles[1];
      MVertex *n1 = t1->getOtherVertex(n2, n4);
      MVertex *n3 = t2->getOtherVertex(n2, n4);
      
      double ang1 = angle3Points(n1,n2,n3);
      double ang2 = angle3Points(n2,n3,n4);
      double ang3 = angle3Points(n3,n4,n1);
      double ang4 = angle3Points(n4,n1,n2);
      const double angleLimit = 3*M_PI/4.;

      if (ang1 < angleLimit && ang2 < angleLimit && ang3 < angleLimit && ang4 < angleLimit){
	if(n1 < n2)
	  e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n1, n2)];
	else
	  e1 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n1)];
	if(n2 < n3)
	  e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n3)];
	else
	  e2 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n3, n2)];
	if(n3 < n4)
	  e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n3, n4)];
	else
	  e3 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n3)];
	if(n4 < n1)
	  e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n1)];
	else
	  e4 = edgeVertices[std::make_pair<MVertex*, MVertex*>(n1, n4)];
	if(n2 < n4)
	  e = edgeVertices[std::make_pair<MVertex*, MVertex*>(n2, n4)];
	else
	  e = edgeVertices[std::make_pair<MVertex*, MVertex*>(n4, n2)];
	
	if((!straightLine(e1, n1, n2) || !straightLine(e2, n2, n3) ||
	    !straightLine(e3, n3, n4) || !straightLine(e4, n4, n1))){
	  
	  double Unew[NBST][10],Vnew[NBST][10];
	  double Xold[10],Yold[10],Zold[10];
	  
	  for(unsigned int i = 0; i < e.size(); i++){
	    Xold[i] = e[i]->x();
	    Yold[i] = e[i]->y();
	    Zold[i] = e[i]->z();
	  }
	  
	  double minJ = 1.e22;
	  double maxJ = -1.e22;       
	  getMinMaxJac (t1, minJ, maxJ);
	  getMinMaxJac (t2, minJ, maxJ);
	  int kopt = -1; 
	  for (int k=0;k<NBST;k++){
	    double relax = (k+1)/(double)NBST;
	    for(unsigned int i = 0; i < e.size(); i++){
	      double v = (double)(i + 1) / (e.size() + 1);
	      double u = 1. - v;
	      MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	      MVertex *vert1 = (n1 < n2) ? e1[e1.size() - i - 1] : e1[i];
	      MVertex *vert3 = (n3 < n4) ? e3[i] : e3[e3.size() - i - 1];
	      MVertex *vert4 = (n4 < n1) ? e4[e4.size() - i - 1] : e4[i];
	      MVertex *vert2 = (n2 < n3) ? e2[i] : e2[e2.size() - i - 1];	    
	      double U1,V1,U2,V2,U3,V3,U4,V4,U,V,nU1,nV1,nU2,nV2,nU3,nV3,nU4,nV4;
	      parametricCoordinates(vert , gf, U, V);
	      parametricCoordinates(vert1, gf, U1, V1);
	      parametricCoordinates(vert2, gf, U2, V2);
	      parametricCoordinates(vert3, gf, U3, V3);
	      parametricCoordinates(vert4, gf, U4, V4);
	      parametricCoordinates(n1, gf, nU1, nV1);
	      parametricCoordinates(n2, gf, nU2, nV2);
	      parametricCoordinates(n3, gf, nU3, nV3);
	      parametricCoordinates(n4, gf, nU4, nV4);
	      
	      Unew[k][i] = U + relax * ((1.-u) * U4 + u * U2 +
					(1.-v) * U1 + v * U3 -
					((1.-u)*(1.-v) * nU1 
					 + u * (1.-v) * nU2 
					 + u * v * nU3 
					 + (1.-u) * v * nU4) - U);
	      Vnew[k][i] = V + relax * ((1.-u) * V4 + u * V2 +
					(1.-v) * V1 + v * V3 -
					((1.-u)*(1.-v) * nV1 
					 + u * (1.-v) * nV2 
					 + u * v * nV3 
					 + (1.-u) * v * nV4) - V);
	      GPoint gp = gf->point(Unew[k][i],Vnew[k][i]);
	      vert->x() = gp.x();
	      vert->y() = gp.y();
	      vert->z() = gp.z();
	    }
	    double minJloc = 1.e22;
	    double maxJloc = -1.e22;          
	    getMinMaxJac(t1, minJloc, maxJloc);
	    getMinMaxJac(t2, minJloc, maxJloc);
	    //	  printf("relax = %g min %g max %g\n",relax,minJloc,maxJloc);
	    
	    if (minJloc > minJ){
	      kopt = k;
	      minJ = minJloc;
	    }
	  }
	  //	kopt = 1;
	  if (kopt == -1){
	    for(unsigned int i = 0; i < e.size(); i++){
	      e[i]->x() = Xold[i];
	      e[i]->y() = Yold[i];
	      e[i]->z() = Zold[i];
	    }      
	  }
	  else{
	    success = true;
	    for(unsigned int i = 0; i < e.size(); i++){
	      MVertex *vert  = (n2 < n4) ? e[i] : e[e.size() - i - 1];
	      vert->setParameter(0,Unew[kopt][i]);
	      vert->setParameter(1,Vnew[kopt][i]);
	      GPoint gp = gf->point(Unew[kopt][i],Vnew[kopt][i]);
	      vert->x() = gp.x();
	      vert->y() = gp.y();
	      vert->z() = gp.z();
	    }      
	  }
	}
      }
    }
  }    
  return success;
}

void checkHighOrderTriangles(GModel *m)
{
  double minJGlob = 1.e22;
  double maxJGlob = -1.e22;
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    double minJ = 1.e22;
    double maxJ = -1.e22;
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
      double minJloc = 1.e22;
      double maxJloc = -1.e22;      
      MTriangle *t = (*it)->triangles[i];
      if(t->getPolynomialOrder() > 1 && t->getPolynomialOrder() < 6){
        getMinMaxJac (t, minJloc, maxJloc);
        minJ = std::min(minJ, minJloc);
        maxJ = std::max(maxJ, maxJloc);
      }
    }
    minJGlob = std::min(minJGlob,minJ);
    maxJGlob = std::max(maxJGlob,maxJ);
  }
  if (minJGlob >= 0) Msg::Info("Jacobian Range (%12.5E,%12.5E)", minJGlob, maxJGlob);
  else Msg::Warning("Jacobian Range (%12.5E,%12.5E)", minJGlob, maxJGlob);
}  

void printJacobians(GModel *m, const char *nm)
{
  return;

  const int n = 15;
  double D[n][n];
  double X[n][n];
  double Y[n][n];
  double Z[n][n];

  FILE *f = fopen(nm,"w");
  fprintf(f,"View \"\"{\n");
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++){
      MTriangle *t = (*it)->triangles[i];
      for(int i = 0; i < n; i++){
        for(int k = 0; k < n - i; k++){
          SPoint3 pt;
          double u = (double)i / (n - 1);
          double v = (double)k / (n - 1);         
          t->pnt(u, v, 0, pt);
          D[i][k] = mesh_functional_distorsion(t, u, v);
          X[i][k] = pt.x();
          Y[i][k] = pt.y();
          Z[i][k] = pt.z();
        }
      }
      for(int i = 0; i < n -1; i++){
        for(int k = 0; k < n - i -1; k++){
          fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%22.15E,%22.15E,%22.15E};\n",
                  X[i][k],Y[i][k],Z[i][k],
                  X[i+1][k],Y[i+1][k],Z[i+1][k],
                  X[i][k+1],Y[i][k+1],Z[i][k+1],
                  D[i][k],
                  D[i+1][k],
                  D[i][k+1]);
          if (i != n-2 && k != n - i -2)
            fprintf(f,"ST(%g,%g,%g,%g,%g,%g,%g,%g,%g){%22.15E,%22.15E,%22.15E};\n",
                    X[i+1][k],Y[i+1][k],Z[i+1][k],
                    X[i+1][k+1],Y[i+1][k+1],Z[i+1][k+1],
                    X[i][k+1],Y[i][k+1],Z[i][k+1],
                    D[i+1][k],
                    D[i+1][k+1],
                    D[i][k+1]);
        }
      }
    }
  }
  fprintf(f,"};\n");
  fclose(f);
}

void SetOrderN(GModel *m, int order, bool linear, bool incomplete)
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

#if !defined(HAVE_GSL)
  Msg::Error("High order mesh generation requires the GSL");
  return;
#endif

  int nPts = order - 1;

  Msg::StatusBar(1, true, "Generating High Order Nodes (q = %d) ...",order);
  double t1 = Cpu();

  // first, make sure to remove any existsing second order vertices/elements
  SetOrder1(m);    

  std::map<MVertex*,SVector3> *displ = 0; 
  if(CTX.mesh.smooth_internal_edges){
    displ = new std::map<MVertex*,SVector3>;
  }

  // then create new second order vertices/elements
  edgeContainer edgeVertices;
  faceContainer faceVertices;
  for(GModel::eiter it = m->firstEdge(); it != m->lastEdge(); ++it)
    setHighOrder(*it, edgeVertices, linear, nPts,displ);
  for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it)
    setHighOrder(*it, edgeVertices, faceVertices, linear, incomplete, nPts,displ);
  for(GModel::riter it = m->firstRegion(); it != m->lastRegion(); ++it)
    setHighOrder(*it, edgeVertices, faceVertices, linear, incomplete, nPts,displ);

  printJacobians(m, "detjIni.pos");  

  if(CTX.mesh.smooth_internal_edges){
    FILE *fl = fopen("displ.dat","w");
    std::map<MVertex*,SVector3>::iterator it = displ->begin();
    fprintf(fl,"%d\n",displ->size());
    for ( ; it!=displ->end();++it){
      fprintf(fl,"%6d %22.15E %22.15E %22.15E %22.15E %22.15E %22.15E\n",(it->first)->getNum(),(it->first)->x(),(it->first)->y(),(it->first)->z(),
	      it->second.x(),it->second.y(),it->second.z());
    }
    fclose(fl);
    delete displ;
  }


  if(0 && CTX.mesh.smooth_internal_edges){
    checkHighOrderTriangles(m);
    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){      
      Msg::Info("Smoothing internal Edges in Surface %d",(*it)->tag());
      for (int i = 0; i < 10; i++) {
        if (!smoothInternalEdges(*it, edgeVertices))break;
        checkHighOrderTriangles(m);
      }
      //      optimizeHighOrderMeshInternalNodes(*it);
    }
    //    for(GModel::fiter it = m->firstFace(); it != m->lastFace(); ++it){      
    //      for (int i=0;i<CTX.mesh.nb_smoothing;i++){
    //        if(!optimizeHighOrderMesh(*it, edgeVertices))break;
    //        checkHighOrderTriangles(m);
    //      }
    //    }
    printJacobians(m, "detjOpt.pos");  
  }


  checkHighOrderTriangles(m);

  double t2 = Cpu();
  Msg::Info("Meshing order %d complete (%g s)", order, t2 - t1);
  Msg::StatusBar(1, true, "Mesh");
}
