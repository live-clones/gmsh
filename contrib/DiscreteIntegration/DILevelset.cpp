#ifndef LEVELSET_CC
#define LEVELSET_CC

#include "DILevelset.h"
#include <queue>
#include <stack>
#include "fullMatrix.h"


inline double det3(double d11, double d12, double d13, double d21, double d22, double d23, double d31, double d32, double d33) {
  return d11 * (d22 * d33 - d23 * d32) - d21 * (d12 * d33 - d13 * d32) + d31 * (d12 * d23 - d13 * d22);
}

inline void norm(const double *vec, double *norm) {
  double n = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
  norm[0] = vec[0] / n;
  norm[1] = vec[1] / n;
  norm[2] = vec[2] / n;
}

inline void cross(const double *pt0, const double *pt1, const double *pt2, double *cross) {
  double v1[3] = {pt1[0] - pt0[0], pt1[1] - pt0[1], pt1[2] - pt0[2]};
  double v2[3] = {pt2[0] - pt0[0], pt2[1] - pt0[1], pt2[2] - pt0[2]};
  cross[0] = v1[1] * v2[2] - v2[1] * v1[2];
  cross[1] = v2[0] * v1[2] - v1[0] * v2[2];
  cross[2] = v1[0] * v2[1] - v2[0] * v1[1];
}

inline bool isPlanar(const double *pt1, const double *pt2, const double *pt3, const double *pt4) {
  double c1[3]; cross(pt1, pt2, pt3, c1);
  double c2[3]; cross(pt1, pt2, pt4, c2);
  double n1[3]; norm(c1, n1);
  double n2[3]; norm(c2, n2);
  return (n1[0] == n2[0] && n1[1] == n2[1] && n1[2] == n2[2]);
}

inline double evalRadialFnDer (int p, int index, double dx, double dy, double dz, double ep){
	
  double r2 = dx*dx+dy*dy+dz*dz; //r^2 
  switch (index) {
  case 0 : // GA
    switch (p) {
    case 0: return exp(-ep*ep*r2);
    case 1: return -2*ep*ep*dx*exp(-ep*ep*r2); // _x
    case 2: return -2*ep*ep*dy*exp(-ep*ep*r2); // _y
    case 3: return -2*ep*ep*dz*exp(-ep*ep*r2); // _z
    }
  case 1 : //MQ
    switch (p) {
    case 0: return sqrt(1+ep*ep*r2);
    case 1: return ep*ep*dx/sqrt(1+ep*ep*r2);
    case 2: return ep*ep*dy/sqrt(1+ep*ep*r2);
    case 3: return ep*ep*dz/sqrt(1+ep*ep*r2);
    }  
  }
}

inline void printNodes(fullMatrix<double> &myNodes, fullMatrix<double> &surf){
  FILE * xyz = fopen("myNodes.pos","w");
  fprintf(xyz,"View \"\"{\n");
  for(int itv = 1; itv !=myNodes.size1() ; ++itv){
    fprintf(xyz,"SP(%g,%g,%g){%g};\n", myNodes(itv,0),myNodes(itv,1),myNodes(itv,2),surf(itv,0));
 }
 fprintf(xyz,"};\n");
 fclose(xyz);
}

// extrude a list of the primitive levelsets with a "Level-order traversal sequence"
void gLevelset::getPrimitives(std::vector<const gLevelset *> &gLsPrimitives) const {
  std::queue<const gLevelset *> Q;
  Q.push(this);
  while(!Q.empty()){
    const gLevelset *p = Q.front();
    std::vector<const gLevelset *> pp;
    pp = p->getChildren();
    if(pp.empty())
      gLsPrimitives.push_back(p);
    Q.pop();
    if(!pp.empty()){
      for(int i = 0; i < (int)pp.size(); i++)
        Q.push(pp[i]);
    }
  }
}
// extrude a list of the primitive levelsets with a "post-order traversal sequence"
void gLevelset::getPrimitivesPO(std::vector<const gLevelset *> &gLsPrimitives) const {
  std::stack<const gLevelset *> S;
  std::stack<const gLevelset *> Sc; // levelset checked
  S.push(this);
  while(!S.empty()){
    const gLevelset *p = S.top();
    std::vector<const gLevelset *> pp;
    pp = p->getChildren();
    if(pp.empty()) {
      gLsPrimitives.push_back(p);
      S.pop();
    }
    else {
      if(Sc.empty() || p != Sc.top()) {
        for(int i = 1; i < (int)pp.size(); i++) Sc.push(p);
        for(int i = (int)pp.size() - 1; i >= 0; i--) {
          S.push(pp[i]);
          if(i > 1) S.push(p);
        }
      }
      else { // levelset has been checked
        S.pop();
        Sc.pop();
      }
    }
  }
}

// return a list with the levelsets in a "Reverse Polish Notation"
void gLevelset::getRPN(std::vector<const gLevelset *> &gLsRPN) const {
  std::stack<const gLevelset *> S;
  std::stack<const gLevelset *> Sc; // levelset checked
  S.push(this);
  while(!S.empty()){
    const gLevelset *p = S.top();
    std::vector<const gLevelset *> pp;
    pp = p->getChildren();
    if(pp.empty()) {
      gLsRPN.push_back(p);
      S.pop();
    }
    else {
      if(Sc.empty() || p != Sc.top()) {
        for(int i = 1; i < (int)pp.size(); i++) Sc.push(p);
        for(int i = (int)pp.size() - 1; i >= 0; i--) {
          S.push(pp[i]);
          if(i > 1) S.push(p);
        }
      }
      else { // levelset has been checked
        S.pop();
        Sc.pop();
        gLsRPN.push_back(p);
      }
    }
  }
}

gLevelset::gLevelset(const gLevelset &lv)
{
  tag_ = lv.tag_;
}

gLevelsetPlane::gLevelsetPlane(const double * pt, const double *norm, int &tag) : gLevelsetPrimitive(tag) {
  a = norm[0];
  b = norm[1];
  c = norm[2];
  d = -a * pt[0] - b * pt[1] - c * pt[2];
}
gLevelsetPlane::gLevelsetPlane(const double * pt1, const double *pt2, const double *pt3, int &tag) : gLevelsetPrimitive(tag) {
  a = det3(1., pt1[1], pt1[2], 1., pt2[1], pt2[2], 1., pt3[1], pt3[2]);
  b = det3(pt1[0], 1., pt1[2], pt2[0], 1., pt2[2], pt3[0], 1., pt3[2]);
  c = det3(pt1[0], pt1[1], 1., pt2[0], pt2[1], 1., pt3[0], pt3[1], 1.);
  d = -det3(pt1[0], pt1[1], pt1[2], pt2[0], pt2[1], pt2[2], pt3[0], pt3[1], pt3[2]);
}
gLevelsetPlane::gLevelsetPlane(const gLevelsetPlane &lv) : gLevelsetPrimitive(lv) {
  a = lv.a;
  b = lv.b;
  c = lv.c;
  d = lv.d;
}

//level set defined by points (RBF interpolation)

fullMatrix<double> gLevelsetPoints::generateRbfMat(int p, int index,
						   const fullMatrix<double> &nodes1,
						   const fullMatrix<double> &nodes2) const {
  int m = nodes2.size1();
  int n = nodes1.size1();
  fullMatrix<double> rbfMat(m,n);

  double eps =0.5/delta; 
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      double dx = nodes2(i,0)-nodes1(j,0);
      double dy = nodes2(i,1)-nodes1(j,1);
      double dz = nodes2(i,2)-nodes1(j,2);
      rbfMat(i,j) = evalRadialFnDer(p, index, dx,dy,dz,eps);
    }
  }
  return rbfMat;

}
void gLevelsetPoints::RbfOp(int p, int index, 
			    const fullMatrix<double> &cntrs,
			    const fullMatrix<double> &nodes, 
			    fullMatrix<double> &D, 
			    bool isLocal) const {

  fullMatrix<double> rbfMatB = generateRbfMat(p,index, cntrs,nodes);
  //printf("size=%d %d \n", rbfMatB.size1(), rbfMatB.size2());
  //rbfMatB.print("MatB");

  fullMatrix<double> rbfInvA;
  if (isLocal){
    rbfInvA = generateRbfMat(0,index, cntrs,cntrs);
    rbfInvA.invertInPlace();
    //printf("size=%d %d \n", rbfInvA.size1(), rbfInvA.size2());
    //rbfInvA.print("invA");
  }
  else {
    rbfInvA = matAInv;
  }

  D.resize(nodes.size1(), cntrs.size1());
  D.gemm(rbfMatB, rbfInvA, 1.0, 0.0);

}


void gLevelsetPoints::evalRbfDer(int p, int index,
		       const fullMatrix<double> &cntrs,
		       const fullMatrix<double> &nodes,
		       const fullMatrix<double> &fValues, 
		       fullMatrix<double> &fApprox, bool isLocal) const {
  
  fApprox.resize(nodes.size1(),fValues.size2());
  fullMatrix<double> D;
  RbfOp(p,index, cntrs,nodes,D,isLocal);
  //D.print("D");
  fApprox.gemm(D,fValues, 1.0, 0.0);

}


void gLevelsetPoints::setup_level_set(const fullMatrix<double> &cntrs,
				      fullMatrix<double> &level_set_nodes, 
				      fullMatrix<double> &level_set_funvals){

  int numNodes = cntrs.size1();
  int nTot = 3*numNodes;
  double normFactor;
  level_set_nodes.resize(nTot,3);
  level_set_funvals.resize(nTot,1);
  fullMatrix<double> ONES(numNodes+1,1),sx(numNodes,1),sy(numNodes,1),sz(numNodes,1),norms(numNodes,3), cntrsPlus(numNodes+1,3);

  //Computes the normal vectors to the surface at each node
  double dist_min = 1.e6;
  double dist_max = 1.e-6;
  for (int i=0;i<numNodes ; ++i){
    ONES(i,0)=1.0;
    cntrsPlus(i,0) = cntrs(i,0);
    cntrsPlus(i,1) = cntrs(i,1);
    cntrsPlus(i,2) = cntrs(i,2);
    for(int j = i+1; j < numNodes; j++){
      double dist = sqrt((cntrs(i,0)-cntrs(j,0))*(cntrs(i,0)-cntrs(j,0))+
    			 (cntrs(i,1)-cntrs(j,1))*(cntrs(i,1)-cntrs(j,1))+
			 (cntrs(i,2)-cntrs(j,2))*(cntrs(i,2)-cntrs(j,2)));
      if (dist<dist_min) dist_min = dist;
      if (dist>dist_max) dist_max = dist;
    }
  }
  ONES(numNodes,0) = -1.0;
  cntrsPlus(numNodes,0) = cntrs(0,0)+dist_max;
  cntrsPlus(numNodes,1) = cntrs(0,1)+dist_max;
  cntrsPlus(numNodes,2) = cntrs(0,2)+dist_max;

  delta =   0.23*dist_min;
  evalRbfDer(1, 1, cntrsPlus,cntrs,ONES,sx, true);
  evalRbfDer(2, 1, cntrsPlus,cntrs,ONES,sy, true);
  evalRbfDer(3, 1, cntrsPlus,cntrs,ONES,sz, true);
  for (int i=0;i<numNodes ; ++i){
    normFactor = sqrt(sx(i,0)*sx(i,0)+sy(i,0)*sy(i,0)+sz(i,0)*sz(i,0));
    sx(i,0) = sx(i,0)/normFactor;
    sy(i,0) = sy(i,0)/normFactor;
    sz(i,0) = sz(i,0)/normFactor;
    norms(i,0) = sx(i,0);norms(i,1) = sy(i,0);norms(i,2) = sz(i,0);
  }
 
  for (int i=0;i<numNodes ; ++i){
    for (int j=0;j<3 ; ++j){
      level_set_nodes(i,j) = cntrs(i,j);
      level_set_nodes(i+numNodes,j) = cntrs(i,j)-delta*norms(i,j);
      level_set_nodes(i+2*numNodes,j) = cntrs(i,j)+delta*norms(i,j);  
    }
    level_set_funvals(i,0) = 0.0;
    level_set_funvals(i+numNodes,0) = -1;
    level_set_funvals(i+2*numNodes,0) = 1;
  }
}


gLevelsetPoints::gLevelsetPoints(fullMatrix<double> &centers, int &tag) : gLevelsetPrimitive(tag) {
  int nbNodes = 3*centers.size1();

  setup_level_set(centers, points, surf);
  printNodes(points, surf);
 
  //build invA matrix for 3*n points
  int indexRBF = 1;
  matAInv.resize(nbNodes, nbNodes);
  matAInv = generateRbfMat(0, indexRBF, points,points);
  matAInv.invertInPlace();
  
  printf("End init levelset points %d \n", points.size1());

}

gLevelsetPoints::gLevelsetPoints(const gLevelsetPoints &lv) : gLevelsetPrimitive(lv) {
  points = lv.points;
}

double gLevelsetPoints::operator()(const double &x, const double &y, const double &z) const{

  if(mapP.empty()) printf("Levelset Points : call computeLS() before calling operator()\n");

  SPoint3 sp(x,y,z);
  std::map<SPoint3,double>::const_iterator it = mapP.find(sp);
  if(it != mapP.end())
    return it->second;
  printf("Levelset Points : Point not found\n");
  return 0;

  // fullMatrix<double> xyz_eval(1, 3), surf_eval(1,1);
  // xyz_eval(0,0) = x;
  // xyz_eval(0,1) = y;
  // xyz_eval(0,2) = z;
  // evalRbfDer(0, 1, points, xyz_eval, surf, surf_eval);
  // return surf_eval(0,0);

}

void gLevelsetPoints::computeLS(std::vector<MVertex*> &vert){

  fullMatrix<double> xyz_eval(vert.size(), 3), surf_eval(vert.size(), 1);
  for (int i = 0; i< vert.size(); i++){
    xyz_eval(i,0) = vert[i]->x();
    xyz_eval(i,1) = vert[i]->y();
    xyz_eval(i,2) = vert[i]->z();
  }
  evalRbfDer(0, 1, points, xyz_eval, surf, surf_eval);
  for (int i = 0; i< vert.size(); i++){
    mapP[SPoint3(vert[i]->x(), vert[i]->y(),vert[i]->z())] = surf_eval(i,0);
  }
}

/*
  assume a quadric 
  x^T A x + b^T x + c = 0

  typically, we add a rotation x -> R x 
  x^T (R^T A R) x + b^T R x + c = 0

  and a translation x -> x - t
  x^T A x + [b^T - 2 A t] x + [c - b^T t + t^T A t ] = 0
*/

gLevelsetQuadric::gLevelsetQuadric(const gLevelsetQuadric &lv) : gLevelsetPrimitive(lv){
  for(int i = 0; i < 3; i++){
    B[i] = lv.B[i];
    for(int j = 0; j < 3; j++)
      A[i][j] = lv.A[i][j];
  }
  C = lv.C;
}
void gLevelsetQuadric::Ax(const double x[3], double res[3], double fact){
  for(int i = 0; i < 3; i++){
    res[i] = 0.;
    for(int j = 0; j < 3; j++){
    res[i] += A[i][j] * x[j] * fact;
    }
  }
}

void gLevelsetQuadric::xAx(const double x[3], double &res, double fact){ 
  res= fact * (A[0][0] * x[0] * x[0] + A[1][1] * x[1] * x[1] + A[2][2] * x[2] * x[2] 
             + A[1][0] * x[1] * x[0] * 2. + A[2][0] * x[2] * x[0] * 2. + A[1][2] * x[1] * x[2] * 2.);
}

void gLevelsetQuadric::translate(const double transl[3]){
  double b;
  xAx(transl, b, 1.0);
  C += (-B[0] * transl[0] - B[1] * transl[1] - B[2] * transl[2] + b);

  double x[3];
  Ax(transl, x, 2.0);
  B[0] += -x[0];
  B[1] += -x[1];
  B[2] += -x[2];
}

void gLevelsetQuadric::rotate(const double rotate[3][3]){
  double a11 = 0., a12 = 0., a13 = 0., a22 = 0., a23 = 0., a33 = 0., b1 = 0., b2 = 0., b3 = 0.;
  for(int i = 0; i < 3; i++){
    b1 += B[i] * rotate[i][0];
    b2 += B[i] * rotate[i][1];
    b3 += B[i] * rotate[i][2];
    for(int j = 0; j < 3; j++){
      a11 += rotate[i][0] * A[i][j] * rotate[j][0];
      a12 += rotate[i][0] * A[i][j] * rotate[j][1];
      a13 += rotate[i][0] * A[i][j] * rotate[j][2];
      a22 += rotate[i][1] * A[i][j] * rotate[j][1];
      a23 += rotate[i][1] * A[i][j] * rotate[j][2];
      a33 += rotate[i][2] * A[i][j] * rotate[j][2];
    }
  }
  A[0][0] = a11;
  A[0][1] = A[1][0] = a12;
  A[0][2] = A[2][0] = a13;
  A[1][1] = a22;
  A[1][2] = A[2][1] = a23;
  A[2][2] = a33;
  B[0] = b1;
  B[1] = b2;
  B[2] = b3;
}

// computes the rotation matrix of the rotation of the vector (0,0,1) to dir
void gLevelsetQuadric::computeRotationMatrix(const double dir[3], double t[3][3]){
  double norm = sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
  double n[3] = {1., 0., 0.};
  double ct = 1., st = 0.;
  if(norm != 0.) {
    double theta = atan(norm / dir[2]);
    n[0] = dir[1] / norm; n[1] = -dir[0] / norm;
    ct = cos(theta);
    st = sin(theta);
  }
  t[0][0] = n[0] * n[0] * (1. - ct) + ct;
  t[0][1] = n[0] * n[1] * (1. - ct) - n[2] * st;
  t[0][2] = n[0] * n[2] * (1. - ct) + n[1] * st;
  t[1][0] = n[1] * n[0] * (1. - ct) + n[2] * st;
  t[1][1] = n[1] * n[1] * (1. - ct) + ct;
  t[1][2] = n[1] * n[2] * (1. - ct) - n[0] * st;
  t[2][0] = n[2] * n[0] * (1. - ct) - n[1] * st;
  t[2][1] = n[2] * n[1] * (1. - ct) + n[0] * st;
  t[2][2] = n[2] * n[2] * (1. - ct) + ct;
}

void gLevelsetQuadric::computeRotationMatrix(const double dir1[3], const double dir2[3], double t[3][3]){
  double norm = sqrt((dir1[1] * dir2[2] - dir1[2] * dir2[1]) * (dir1[1] * dir2[2] - dir1[2] * dir2[1]) 
                   + (dir1[2] * dir2[0] - dir1[0] * dir2[2]) * (dir1[2] * dir2[0] - dir1[0] * dir2[2]) 
                   + (dir1[0] * dir2[1] - dir1[1] * dir2[0]) * (dir1[0] * dir2[1] - dir1[1] * dir2[0]));
  double n[3] = {1., 0., 0.};
  double ct = 1., st = 0.;
  if(norm != 0.) {
    st = norm / ((dir1[0] * dir1[0] + dir1[1] * dir1[1] + dir1[2] * dir1[2]) *
                 (dir2[0] * dir2[0] + dir2[1] * dir2[1] + dir2[2] * dir2[2]));
    n[0] = (dir1[1] * dir2[2] - dir1[2] * dir2[1]) / norm;
    n[1] = (dir1[2] * dir2[0] - dir1[0] * dir2[2]) / norm;
    n[2] = (dir1[0] * dir2[1] - dir1[1] * dir2[0]) / norm;
    ct = cos(asin(st));
  }
  t[0][0] = n[0] * n[0] * (1. - ct) + ct;
  t[0][1] = n[0] * n[1] * (1. - ct) - n[2] * st;
  t[0][2] = n[0] * n[2] * (1. - ct) + n[1] * st;
  t[1][0] = n[1] * n[0] * (1. - ct) + n[2] * st;
  t[1][1] = n[1] * n[1] * (1. - ct) + ct;
  t[1][2] = n[1] * n[2] * (1. - ct) - n[0] * st;
  t[2][0] = n[2] * n[0] * (1. - ct) - n[1] * st;
  t[2][1] = n[2] * n[1] * (1. - ct) + n[0] * st;
  t[2][2] = n[2] * n[2] * (1. - ct) + ct;
}

void gLevelsetQuadric::init(){
  for(int i = 0; i < 3; i++){
    B[i] = 0.;
    for(int j = 0; j < 3; j++) A[i][j] = 0.;
  }
  C = 0.;
}

double gLevelsetQuadric::operator()(const double &x, const double &y, const double &z) const{
  return(A[0][0] * x * x + 2. * A[0][1] * x * y + 2. * A[0][2] * x * z + A[1][1] * y * y 
        + 2. * A[1][2] * y * z + A[2][2] * z * z + B[0] * x + B[1] * y + B[2] * z + C);
}

gLevelsetGenCylinder::gLevelsetGenCylinder(const double *pt, const double *dir, const double &R,
                                           int &tag) : gLevelsetQuadric(tag) {
  A[0][0] = 1.;
  A[1][1] = 1.;
  C = - R * R;
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}
gLevelsetGenCylinder::gLevelsetGenCylinder (const gLevelsetGenCylinder& lv) : gLevelsetQuadric(lv){}

gLevelsetEllipsoid::gLevelsetEllipsoid(const double *pt, const double *dir, const double &a, 
                                       const double &b, const double &c, int &tag) : gLevelsetQuadric(tag) {
  A[0][0] = 1. / (a * a);
  A[1][1] = 1. / (b * b);
  A[2][2] = 1. / (c * c);
  C = -1.;
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}
gLevelsetEllipsoid::gLevelsetEllipsoid (const gLevelsetEllipsoid& lv) : gLevelsetQuadric(lv){}

gLevelsetCone::gLevelsetCone(const double *pt, const double *dir, const double &angle, int &tag) : gLevelsetQuadric(tag) {
  A[0][0] = 1.;
  A[1][1] = 1.;
  A[2][2] = -tan(angle) * tan(angle);
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}

gLevelsetCone::gLevelsetCone (const gLevelsetCone& lv) : gLevelsetQuadric(lv)
{}
gLevelsetGeneralQuadric::gLevelsetGeneralQuadric(const double *pt, const double *dir, const double &x2, const double &y2, const double &z2,
                                                 const double &z, const double &c, int &tag) : gLevelsetQuadric(tag) {
  A[0][0] = x2;
  A[1][1] = y2;
  A[2][2] = z2;
  B[2] = z;
  C = c;
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}

gLevelsetGeneralQuadric::gLevelsetGeneralQuadric (const gLevelsetGeneralQuadric& lv) : gLevelsetQuadric(lv)
{}

gLevelsetTools::gLevelsetTools(const gLevelsetTools &lv) : gLevelset(lv)
{
  std::vector<const gLevelset *> _children=lv.getChildren();
  unsigned siz = _children.size();
  children.resize(siz);
  for(unsigned i = 0; i < siz; ++i)	
    children[i] = _children[i]->clone();
}
gLevelsetImproved::gLevelsetImproved(const gLevelsetImproved &lv) : gLevelset(lv){
  Ls = lv.Ls->clone();
}

gLevelsetBox::gLevelsetBox(const double *pt, const double *dir1, const double *dir2, const double *dir3,
                           const double &a, const double &b, const double &c, int &tag) : gLevelsetImproved() {
  double dir1m[3] = {-dir1[0], -dir1[1], -dir1[2]};
  double dir2m[3] = {-dir2[0], -dir2[1], -dir2[2]};
  double dir3m[3] = {-dir3[0], -dir3[1], -dir3[2]};
  double n1[3]; norm(dir1, n1);
  double n2[3]; norm(dir2, n2);
  double n3[3]; norm(dir3, n3);
  double pt2[3] = {pt[0] + a * n1[0] + b * n2[0] + c * n3[0], pt[1] + a * n1[1] + b * n2[1] + c * n3[1],
                   pt[2] + a * n1[2] + b * n2[2] + c * n3[2]};
  std::vector<const gLevelset *> p;
  p.push_back(new gLevelsetPlane(pt2, dir3, tag));
  p.push_back(new gLevelsetPlane(pt, dir3m, tag));
  p.push_back(new gLevelsetPlane(pt, dir2m, tag));
  p.push_back(new gLevelsetPlane(pt2, dir2, tag));
  p.push_back(new gLevelsetPlane(pt2, dir1, tag));
  p.push_back(new gLevelsetPlane(pt, dir1m, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetBox::gLevelsetBox(const double *pt1, const double *pt2, const double *pt3, const double *pt4,
                           const double *pt5, const double *pt6, const double *pt7, const double *pt8, int &tag) : gLevelsetImproved() {
  if(!isPlanar(pt1, pt2, pt3, pt4) || !isPlanar(pt5, pt6, pt7, pt8) || !isPlanar(pt1, pt2, pt5, pt6) ||
     !isPlanar(pt3, pt4, pt7, pt8) || !isPlanar(pt1, pt4, pt5, pt8) || !isPlanar(pt2, pt3, pt6, pt7))
    printf("WARNING : faces of the box are not planar! %d, %d, %d, %d, %d, %d\n",
           isPlanar(pt1, pt2, pt3, pt4), isPlanar(pt5, pt6, pt7, pt8), isPlanar(pt1, pt2, pt5, pt6),
           isPlanar(pt3, pt4, pt7, pt8), isPlanar(pt1, pt4, pt5, pt8), isPlanar(pt2, pt3, pt6, pt7));
  std::vector<const gLevelset *> p;
  p.push_back(new gLevelsetPlane(pt5, pt6, pt8, tag));
  p.push_back(new gLevelsetPlane(pt1, pt4, pt2, tag));
  p.push_back(new gLevelsetPlane(pt1, pt2, pt5, tag));
  p.push_back(new gLevelsetPlane(pt3, pt4, pt7, tag));
  p.push_back(new gLevelsetPlane(pt2, pt3, pt6, tag));
  p.push_back(new gLevelsetPlane(pt1, pt5, pt4, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetBox::gLevelsetBox(const gLevelsetBox &lv) : gLevelsetImproved(lv){}

gLevelsetCylinder::gLevelsetCylinder(const double *pt, const double *dir, const double &R, const double &H, int &tag) : gLevelsetImproved() {
  double dir2[3] = {-dir[0], -dir[1], -dir[2]};
  double n[3]; norm(dir, n);
  double pt2[3] = {pt[0] + H * n[0], pt[1] + H * n[1], pt[2] + H * n[2]};
  std::vector<const gLevelset *> p;
  p.push_back(new gLevelsetGenCylinder(pt, dir, R, tag));
  p.push_back(new gLevelsetPlane(pt, dir2, tag));
  p.push_back(new gLevelsetPlane(pt2, dir, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetCylinder::gLevelsetCylinder(const double * pt, const double *dir, const double &R, const double &r, const double &H, int &tag) : gLevelsetImproved() {
  double dir2[3] = {-dir[0], -dir[1], -dir[2]};
  double n[3]; norm(dir, n);
  double pt2[3] = {pt[0] + H * n[0], pt[1] + H * n[1], pt[2] + H * n[2]};
  std::vector<const gLevelset *> p1;
  p1.push_back(new gLevelsetGenCylinder(pt, dir, R, tag));
  p1.push_back(new gLevelsetPlane(pt, dir2, tag));
  p1.push_back(new gLevelsetPlane(pt2, dir, tag));
  std::vector<const gLevelset *> p2;
  p2.push_back(new gLevelsetIntersection(p1));
  p2.push_back(new gLevelsetGenCylinder(pt, dir, r, tag));
  Ls = new gLevelsetCut(p2);
}
gLevelsetCylinder::gLevelsetCylinder(const gLevelsetCylinder &lv) : gLevelsetImproved(lv){}

gLevelsetConrod::gLevelsetConrod(const double *pt, const double *dir1, const double *dir2,
                                 const double &H1, const double &H2, const double &H3,
                                 const double &R1, const double &r1, const double &R2, const double &r2,
                                 const double &L1, const double &L2, const double &E, int &tag) : gLevelsetImproved() {
  double n1[3]; norm(dir1, n1);
  double n2[3]; norm(dir2, n2);
  double pt1[3] = {pt[0] - n2[0] * H1 / 2., pt[1] - n2[1] * H1 / 2., pt[2] - n2[2] * H1 / 2.};
  double pt2[3] = {pt[0] + n1[0] * E - n2[0] * H2 / 2., pt[1] + n1[1] * E - n2[1] * H2 / 2.,
                   pt[2] + n1[2] * E - n2[2] * H2 / 2.};
  double dir3[3]; cross(pt1, pt2, pt, dir3);
  double n3[3]; norm(dir3, n3);
  double pt31[3] = {pt[0] - n2[0] * H3 / 2. + n3[0] * L1 / 2., pt[1] - n2[1] * H3 / 2. + n3[1] * L1 / 2.,
                    pt[2] - n2[2] * H3 / 2. + n3[2] * L1 / 2.};
  double pt32[3] = {pt31[0] - n3[0] * L1, pt31[1] - n3[1] * L1, pt31[2] - n3[2] * L1};
  double pt33[3] = {pt32[0] + n2[0] * H3, pt32[1] + n2[1] * H3, pt32[2] + n2[2] * H3};
  double pt34[3] = {pt33[0] + n3[0] * L1, pt33[1] + n3[1] * L1, pt33[2] + n3[2] * L1};
  double pt35[3] = {pt[0] + n1[0] * E - n2[0] * H3 / 2. + n3[0] * L2 / 2.,
                    pt[1] + n1[1] * E - n2[1] * H3 / 2. + n3[1] * L2 / 2.,
                    pt[2] + n1[2] * E - n2[2] * H3 / 2. + n3[2] * L2 / 2.};
  double pt36[3] = {pt35[0] - n3[0] * L2, pt35[1] - n3[1] * L2, pt35[2] - n3[2] * L2};
  double pt37[3] = {pt36[0] + n2[0] * H3, pt36[1] + n2[1] * H3, pt36[2] + n2[2] * H3};
  double pt38[3] = {pt37[0] + n3[0] * L2, pt37[1] + n3[1] * L2, pt37[2] + n3[2] * L2};
  std::vector<const gLevelset *> p1;
  p1.push_back(new gLevelsetBox(pt31, pt32, pt33, pt34, pt35, pt36, pt37, pt38, tag));
  p1.push_back(new gLevelsetCylinder(pt1, dir2, R1, H1, tag));
  p1.push_back(new gLevelsetCylinder(pt2, dir2, R2, H2, tag));
  std::vector<const gLevelset *> p2;
  p2.push_back(new gLevelsetUnion(p1));
  p2.push_back(new gLevelsetGenCylinder(pt1, dir2, r1, tag));
  p2.push_back(new gLevelsetGenCylinder(pt2, dir2, r2, tag));
  Ls = new gLevelsetCut(p2);
}

gLevelsetConrod::gLevelsetConrod(const gLevelsetConrod &lv) : gLevelsetImproved(lv){}
#endif
