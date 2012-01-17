// Gmsh - Copyright (C) 1997-2011 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.
//
// Contributor(s):
//   Gaetan Bricteux
//

#include <queue>
#include <stack>
#include <math.h>
#include "gmshLevelset.h"
#include "fullMatrix.h"
#include "GModel.h"
#include "MElement.h"
#include "Numeric.h"
#include "cartesian.h"

void insertActiveCells(double x, double y, double z, double rmax,
                       cartesianBox<double> &box)
{
  int id1 = box.getCellContainingPoint(x - rmax, y - rmax, z - rmax);
  int id2 = box.getCellContainingPoint(x + rmax, y + rmax, z + rmax);
  int i1, j1 ,k1;
  box.getCellIJK(id1, i1, j1, k1);
  int i2, j2, k2;
  box.getCellIJK(id2, i2, j2, k2);
  for (int i = i1; i <= i2; i++)
    for (int j = j1; j <= j2; j++)
      for (int k = k1; k <= k2; k++)
        box.insertActiveCell(box.getCellIndex(i, j, k));
}
void fillPointCloud(GEdge *ge, double sampling, std::vector<SPoint3> &points)
{
  Range<double> t_bounds = ge->parBounds(0);
  double t_min = t_bounds.low();
  double t_max = t_bounds.high();
  double length = ge->length(t_min, t_max, 20);
  int N = length / sampling;
  for(int i = 0; i < N; i++) {
    double t = t_min + (double)i / (double)(N - 1) * (t_max - t_min);
    GPoint p = ge->point(t);
    points.push_back(SPoint3(p.x(), p.y(), p.z()));
  }
}

int removeBadChildCells(cartesianBox<double> *parent)
{
  cartesianBox<double> *child = parent->getChildBox();
  if(!child) return 0;
  int I = parent->getNxi();
  int J = parent->getNeta();
  int K = parent->getNzeta();
  for(int i = 0; i < I; i++)
    for(int j = 0; j < J; j++)
      for(int k = 0; k < K; k++){
        // remove children if they do not entirely fill parent, or if
        // there is no parent on the boundary
        int idx[8] = {child->getCellIndex(2 * i, 2 * j, 2 * k),
                      child->getCellIndex(2 * i, 2 * j, 2 * k + 1),
                      child->getCellIndex(2 * i, 2 * j + 1, 2 * k),
                      child->getCellIndex(2 * i, 2 * j + 1, 2 * k + 1),
                      child->getCellIndex(2 * i + 1, 2 * j, 2 * k),
                      child->getCellIndex(2 * i + 1, 2 * j, 2 * k + 1),
                      child->getCellIndex(2 * i + 1, 2 * j + 1, 2 * k),
                      child->getCellIndex(2 * i + 1, 2 * j + 1, 2 * k + 1)};
        bool exist[8], atLeastOne = false, butNotAll = false;
        for(int ii = 0; ii < 8; ii++){
          exist[ii] = child->activeCellExists(idx[ii]);
          if(exist[ii]) atLeastOne = true;
          if(!exist[ii]) butNotAll = true;
        }
        if(atLeastOne && 
           (butNotAll ||
            (i != 0 && !parent->activeCellExists(parent->getCellIndex(i - 1, j, k))) ||
            (i != I - 1 && !parent->activeCellExists(parent->getCellIndex(i + 1, j, k))) ||
            (j != 0 && !parent->activeCellExists(parent->getCellIndex(i, j - 1, k))) ||
            (j != J - 1 && !parent->activeCellExists(parent->getCellIndex(i, j + 1, k))) ||
            (k != 0 && !parent->activeCellExists(parent->getCellIndex(i, j, k - 1))) ||
            (k != K - 1 && !parent->activeCellExists(parent->getCellIndex(i, j, k + 1)))))
            for(int ii = 0; ii < 8; ii++) child->eraseActiveCell(idx[ii]);
      }
  return removeBadChildCells(child);
}

void removeParentCellsWithChildren(cartesianBox<double> *box)
{
  if(!box->getChildBox()) return;
  for(int i = 0; i < box->getNxi(); i++)
    for(int j = 0; j < box->getNeta(); j++)
      for(int k = 0; k < box->getNzeta(); k++){
        if(box->activeCellExists(box->getCellIndex(i, j, k))){
          cartesianBox<double> *parent = box, *child;
          int ii = i, jj = j, kk = k;
          while((child = parent->getChildBox())){
            ii *= 2; jj *= 2; kk *= 2;
            if(child->activeCellExists(child->getCellIndex(ii, jj, kk))){
              box->eraseActiveCell(box->getCellIndex(i, j, k));
              break;
            }
            parent = child;
          }
        }
      }
  removeParentCellsWithChildren(box->getChildBox());
}

void computeLevelset(GModel *gm, cartesianBox<double> &box)
{
  // tolerance for desambiguation
  const double tol = box.getLC() * 1.e-12;
  std::vector<SPoint3> nodes;
  std::vector<int> indices;
  for (cartesianBox<double>::valIter it = box.nodalValuesBegin(); 
       it != box.nodalValuesEnd(); ++it){
    nodes.push_back(box.getNodeCoordinates(it->first));
    indices.push_back(it->first);
  }
  //Msg::Info("  %d nodes in the grid at level %d", (int)nodes.size(), box.getLevel());
  std::vector<double> dist, localdist;
  std::vector<SPoint3> dummy;
  for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); fit++){
   if((*fit)->geomType() == GEntity::DiscreteSurface){
      for(unsigned int k = 0; k < (*fit)->getNumMeshElements(); k++){ 
	  std::vector<double> iDistances;
	  std::vector<SPoint3> iClosePts;
          std::vector<double> iDistancesE;
	  MElement *e = (*fit)->getMeshElement(k);
	  if(e->getType() == TYPE_TRI){
	    MVertex *v1 = e->getVertex(0);
	    MVertex *v2 = e->getVertex(1);
	    MVertex *v3 = e->getVertex(2);
	    SPoint3 p1(v1->x(),v1->y(),v1->z());
	    SPoint3 p2(v2->x(),v2->y(),v2->z());
	    SPoint3 p3(v3->x(),v3->y(),v3->z());
	    //sign plus if in the direction of the normal
	    signedDistancesPointsTriangle(localdist, dummy, nodes, p2, p1, p3);
	  }
	  if(dist.empty()) 
	    dist = localdist;
	  else{ 
	    for (unsigned int j = 0; j < localdist.size(); j++){
	      dist[j] = (fabs(dist[j]) < fabs(localdist[j])) ? dist[j] : localdist[j];
	    }
	  }
      }
    }
    else{
      printf(" CAD surface \n");
      //look in utils_api_demos maincartesian
      // for (GModel::fiter fit = _model->firstFace(); fit != _model->lastFace(); fit++){
      // for (int i = 0; i < (*fit)->stl_triangles.size(); i += 3){
    }
  }

  for (unsigned int j = 0; j < dist.size(); j++)
    box.setNodalValue(indices[j], dist[j]);

  if(box.getChildBox()) computeLevelset(gm, *box.getChildBox());
}




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
void gLevelset::getPrimitives(std::vector<gLevelset *> &gLsPrimitives)  {
  std::queue<gLevelset *> Q;
  Q.push(this);
  while(!Q.empty()){
    gLevelset *p = Q.front();
    std::vector<gLevelset *> pp;
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
void gLevelset::getPrimitivesPO(std::vector<gLevelset *> &gLsPrimitives)  {
  std::stack<gLevelset *> S;
  std::stack<gLevelset *> Sc; // levelset checked
  S.push(this);
  while(!S.empty()){
    gLevelset *p = S.top();
    std::vector<gLevelset *> pp;
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
void gLevelset::getRPN(std::vector<gLevelset *> &gLsRPN) {
  std::stack<gLevelset *> S;
  std::stack<gLevelset *> Sc; // levelset checked
  S.push(this);
  while(!S.empty()){
    gLevelset *p = S.top();
    std::vector<gLevelset *> pp;
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

gLevelsetPlane::gLevelsetPlane(const std::vector<double>  &pt, const std::vector<double> &norm, int tag) : gLevelsetPrimitive(tag) {
  a = norm[0];
  b = norm[1];
  c = norm[2];
  d = -a * pt[0] - b * pt[1] - c * pt[2];
}
gLevelsetPlane::gLevelsetPlane(const double * pt, const double *norm, int tag) : gLevelsetPrimitive(tag) {
  a = norm[0];
  b = norm[1];
  c = norm[2];
  d = -a * pt[0] - b * pt[1] - c * pt[2];
}
gLevelsetPlane::gLevelsetPlane(const double * pt1, const double *pt2, const double *pt3, int tag) : gLevelsetPrimitive(tag) {
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


gLevelsetPoints::gLevelsetPoints(fullMatrix<double> &centers, int tag) : gLevelsetPrimitive(tag) {
  int nbNodes = 3*centers.size1();

  setup_level_set(centers, points, surf);
  printNodes(points, surf);
 
  //build invA matrix for 3*n points
  int indexRBF = 1;
  matAInv.resize(nbNodes, nbNodes);
  matAInv = generateRbfMat(0, indexRBF, points,points);
  matAInv.invertInPlace();
  
  //printf("End init levelset points %d \n", points.size1());

}

gLevelsetPoints::gLevelsetPoints(const gLevelsetPoints &lv) : gLevelsetPrimitive(lv) {
  points = lv.points;
}

double gLevelsetPoints::operator()(const double x, const double y, const double z) const{

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

double gLevelsetQuadric::operator()(const double x, const double y, const double z) const{
  return(A[0][0] * x * x + 2. * A[0][1] * x * y + 2. * A[0][2] * x * z + A[1][1] * y * y 
        + 2. * A[1][2] * y * z + A[2][2] * z * z + B[0] * x + B[1] * y + B[2] * z + C);
}

gLevelsetPopcorn::gLevelsetPopcorn(double _xc, double _yc, double _zc, double _r0, double _A, double _sigma, int tag) : gLevelsetPrimitive(tag) {
  A = _A;
  sigma = _sigma;
  r0 = _r0;
  xc = _xc; 
  yc = _yc;
  zc = _zc;
}

double gLevelsetPopcorn::operator() (const double x, const double y, const double z) const {
  double s2 = (sigma)*(sigma);
  double r = sqrt((x-xc)*(x-xc)+(y-yc)*(y-yc)+(z-zc)*(z-zc));
  //printf("z=%g zc=%g r=%g \n", z, zc, r);
  double  val = r - r0;
  for (int k = 0; k< 5; k++){
    double xk = r0/sqrt(5.0)*(2.*cos(2*k*M_PI/5.0));
    double yk = r0/sqrt(5.0)*(2.*sin(2*k*M_PI/5.0));
    double zk = r0/sqrt(5.0);
    val -=  A*exp(-((x-xc-xk)*(x-xc-xk)+(y-yc-yk)*(y-yc-yk)+(z-zc-zk)*(z-zc-zk))/s2);
  }
  for (int k = 5; k< 10; k++){
    double xk = r0/sqrt(5.0)*(2.*cos((2.*(k-5.)-1.)*M_PI/5.0));
    double yk = r0/sqrt(5.0)*(2.*sin((2.*(k-5.)-1.)*M_PI/5.0));
    double zk = -r0/sqrt(5.0);
    val -= A*exp(-((x-xc-xk)*(x-xc-xk)+(y-yc-yk)*(y-yc-yk)+(z-zc-zk)*(z-zc-zk))/s2);
  }
  val  -= A*exp(-((x-xc)*(x-xc)+(y-yc)*(y-yc)+(z-zc-r0)*(z-zc-r0))/s2);
  val  -= A*exp(-((x-xc)*(x-xc)+(y-yc)*(y-yc)+(z-zc+r0)*(z-zc+r0))/s2);
  return val;
}

gLevelsetMathEval::gLevelsetMathEval(std::string f, int tag) : gLevelsetPrimitive(tag) {
    std::vector<std::string> expressions(1, f);
    std::vector<std::string> variables(3);
    variables[0] = "x";
    variables[1] = "y";
    variables[2] = "z";
    _expr = new mathEvaluator(expressions, variables);
}

double gLevelsetMathEval::operator() (const double x, const double y, const double z) const {
    std::vector<double> values(3), res(1);
    values[0] = x;
    values[1] = y;
    values[2] = z;
    if(_expr->eval(values, res)) return res[0];
    return 1.;
}

gLevelsetDistGeom::gLevelsetDistGeom(std::string box, std::string geom, int tag) : gLevelsetPrimitive(tag), _box(NULL) {
  
  modelBox = new GModel();
  modelBox->load(box+std::string(".msh"));
  modelGeom = new GModel();
  modelGeom->load(geom);
  
  //EMI FIXME THIS
  double lx = 0.5, ly = 0.5, lz = 0.5;
  int levels = 3;
  int refineCurvedSurfaces = 0;

  double rmax = 0.1;
  double sampling = std::min(rmax, std::min(lx, std::min(ly, lz)));
  double rtube = std::max(lx, std::max(ly, lz))*2.;

  //FILLING POINTS FROM GEOMBOX
  std::vector<SPoint3> points;
  std::vector<SPoint3> refinePoints;
  for(GModel::viter vit = modelBox->firstVertex(); vit != modelBox->lastVertex(); vit++){
    for(unsigned int k = 0; k < (*vit)->getNumMeshVertices(); k++){ 
      MVertex  *v = (*vit)->getMeshVertex(k);
       SPoint3 p(v->x(), v->y(), v->z());
      points.push_back(p);
    }
  }
  for (GModel::eiter eit = modelBox->firstEdge(); eit != modelBox->lastEdge(); eit++){
    for(unsigned int k = 0; k < (*eit)->getNumMeshVertices(); k++){ 
      MVertex  *ve = (*eit)->getMeshVertex(k);
      SPoint3 pe(ve->x(), ve->y(), ve->z());
      points.push_back(pe);
    }
  }

  //FILLING POINTS FROM STL
  for (GModel::fiter fit = modelGeom->firstFace(); fit != modelGeom->lastFace(); fit++){
    for(unsigned int k = 0; k < (*fit)->getNumMeshVertices(); k++){ 
      MVertex  *vf = (*fit)->getMeshVertex(k);
      SPoint3 pf(vf->x(), vf->y(), vf->z());
      points.push_back(pf);
    }
    for(unsigned int k = 0; k < (*fit)->getNumMeshElements(); k++){ 
      MElement *e =  (*fit)->getMeshElement(k);
      if (e->getType() == TYPE_TRI){
  	MVertex *v1 = e->getVertex(0);
  	MVertex *v2 = e->getVertex(1);
  	MVertex *v3 = e->getVertex(2);
  	SPoint3 cg( (v1->x()+v2->x()+v3->x())/3.,
  		    (v1->y()+v2->y()+v3->y())/3.,
  		    (v1->z()+v2->z()+v3->z())/3.);
  	refinePoints.push_back(cg);
      }
    }
  }
  //FOR CAD
  //for (GModel::fiter fit = modelGeom->firstFace(); fit != modelGeom->lastFace(); fit++)
  //   (*fit)->fillPointCloud(sampling, &points);

  if (points.size() == 0) {Msg::Fatal("No points on surfaces \n"); };

  SBoundingBox3d bb;
  for(unsigned int i = 0; i < points.size(); i++) bb += points[i]; 
  for(unsigned int i = 0; i < refinePoints.size(); i++) bb += refinePoints[i]; 
  //bb.scale(1.01, 1.01, 1.01);
  SVector3 range = bb.max() - bb.min(); 
  int NX = range.x() / lx; 
  int NY = range.y() / ly; 
  int NZ = range.z() / lz; 
  if(NX < 2) NX = 2;
  if(NY < 2) NY = 2;
  if(NZ < 2) NZ = 2;

  Msg::Info("  bounding box min: %g %g %g -- max: %g %g %g",
            bb.min().x(), bb.min().y(), bb.min().z(),
            bb.max().x(), bb.max().y(), bb.max().z());
  Msg::Info("  Nx=%d Ny=%d Nz=%d", NX, NY, NZ);
  
  _box = new cartesianBox<double>(bb.min().x(), bb.min().y(), bb.min().z(), 
  				 SVector3(range.x(), 0, 0),
  				 SVector3(0, range.y(), 0),
  				 SVector3(0, 0, range.z()),
  				 NX, NY, NZ, levels);
   for (int i = 0; i < NX; i++)
    for (int j = 0; j < NY; j++)
      for (int k = 0; k < NZ; k++)
        _box->insertActiveCell(_box->getCellIndex(i, j, k));

  cartesianBox<double> *parent = _box, *child;
  while((child = parent->getChildBox())){
    //Msg::Info("  level %d ", child->getLevel());
    for(unsigned int i = 0; i < refinePoints.size(); i++)
      insertActiveCells(refinePoints[i].x(), refinePoints[i].y(), refinePoints[i].z(), 
                         rtube / pow(2., (levels - child->getLevel())), *child);
    parent = child;
  }

  //Msg::Info("Removing cells to match mesh topology constraints");
  removeBadChildCells(_box);
  removeParentCellsWithChildren(_box);

  //Msg::Info("Initializing nodal values in the cartesian grid");
  _box->createNodalValues();

  //Msg::Info("Computing levelset on the cartesian grid");  
  computeLevelset(gm, *_box);

  //Msg::Info("Renumbering mesh vertices across levels");
  _box->renumberNodes();
  
  _box->writeMSH("yeah.msh", false);

  
}

double gLevelsetDistGeom::operator() (const double x, const double y, const double z) const {

  double dist = 0.0 ; //_box->getValueContainingPoint(x,y,z);
  return dist;
}

#if defined (HAVE_POST)
gLevelsetPostView::gLevelsetPostView(int index, int tag) : gLevelsetPrimitive(tag), _viewIndex(index){
  if(_viewIndex >= 0 && _viewIndex < (int)PView::list.size()){
    PView *view = PView::list[_viewIndex];
    _octree = new OctreePost(view);
  }
  else{
    Msg::Error("Unknown View[%d] in PostView levelset", _viewIndex);
    _octree = 0;
  }
}

double gLevelsetPostView::operator () (const double x, const double y, const double z) const  {
  if(!_octree) return 1.;
  double val = 1.;
  _octree->searchScalar(x, y, z, &val, 0);
  return val;
}
#endif

gLevelsetGenCylinder::gLevelsetGenCylinder(const double *pt, const double *dir, const double &R,
                                           int tag) : gLevelsetQuadric(tag) {
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
                                       const double &b, const double &c, int tag) : gLevelsetQuadric(tag) {
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

gLevelsetCone::gLevelsetCone(const double *pt, const double *dir, const double &angle, int tag) : gLevelsetQuadric(tag) {
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
                                                 const double &z, const double &c, int tag) : gLevelsetQuadric(tag) {
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
  std::vector<gLevelset *> _children=lv.getChildren();
  unsigned siz = _children.size();
  children.resize(siz);
  for(unsigned i = 0; i < siz; ++i)	
    children[i] = _children[i]->clone();
}
gLevelsetImproved::gLevelsetImproved(const gLevelsetImproved &lv) : gLevelset(lv){
  Ls = lv.Ls->clone();
}

gLevelsetBox::gLevelsetBox(const double *pt, const double *dir1, const double *dir2, const double *dir3,
                           const double &a, const double &b, const double &c, int tag) : gLevelsetImproved() {
  double dir1m[3] = {-dir1[0], -dir1[1], -dir1[2]};
  double dir2m[3] = {-dir2[0], -dir2[1], -dir2[2]};
  double dir3m[3] = {-dir3[0], -dir3[1], -dir3[2]};
  double n1[3]; norm(dir1, n1);
  double n2[3]; norm(dir2, n2);
  double n3[3]; norm(dir3, n3);
  double pt2[3] = {pt[0] + a * n1[0] + b * n2[0] + c * n3[0], pt[1] + a * n1[1] + b * n2[1] + c * n3[1],
                   pt[2] + a * n1[2] + b * n2[2] + c * n3[2]};
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetPlane(pt2, dir3, tag++));
  p.push_back(new gLevelsetPlane(pt, dir3m, tag++));
  p.push_back(new gLevelsetPlane(pt, dir2m, tag++));
  p.push_back(new gLevelsetPlane(pt2, dir2, tag++));
  p.push_back(new gLevelsetPlane(pt2, dir1, tag++));
  p.push_back(new gLevelsetPlane(pt, dir1m, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetBox::gLevelsetBox(const double *pt1, const double *pt2, const double *pt3, const double *pt4,
                           const double *pt5, const double *pt6, const double *pt7, const double *pt8, int tag) : gLevelsetImproved() {
  if(!isPlanar(pt1, pt2, pt3, pt4) || !isPlanar(pt5, pt6, pt7, pt8) || !isPlanar(pt1, pt2, pt5, pt6) ||
     !isPlanar(pt3, pt4, pt7, pt8) || !isPlanar(pt1, pt4, pt5, pt8) || !isPlanar(pt2, pt3, pt6, pt7))
    printf("WARNING : faces of the box are not planar! %d, %d, %d, %d, %d, %d\n",
           isPlanar(pt1, pt2, pt3, pt4), isPlanar(pt5, pt6, pt7, pt8), isPlanar(pt1, pt2, pt5, pt6),
           isPlanar(pt3, pt4, pt7, pt8), isPlanar(pt1, pt4, pt5, pt8), isPlanar(pt2, pt3, pt6, pt7));
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetPlane(pt5, pt6, pt8, tag++));
  p.push_back(new gLevelsetPlane(pt1, pt4, pt2, tag++));
  p.push_back(new gLevelsetPlane(pt1, pt2, pt5, tag++));
  p.push_back(new gLevelsetPlane(pt3, pt4, pt7, tag++));
  p.push_back(new gLevelsetPlane(pt2, pt3, pt6, tag++));
  p.push_back(new gLevelsetPlane(pt1, pt5, pt4, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetBox::gLevelsetBox(const gLevelsetBox &lv) : gLevelsetImproved(lv){}

gLevelsetCylinder::gLevelsetCylinder(const std::vector<double> &pt, const std::vector<double> &dir, const double &R, const double &H, int tag) : gLevelsetImproved() {
  double pt1[3]={pt[0], pt[1], pt[2]};
  double dir1[3] = {dir[0], dir[1], dir[2]};
  double dir2[3] = {-dir1[0], -dir1[1], -dir1[2]};
  double n[3]; norm(dir1, n);
  double pt2[3] = {pt1[0] + H * n[0], pt1[1] + H * n[1], pt1[2] + H * n[2]};
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetGenCylinder(pt1, dir1, R, tag++));
  p.push_back(new gLevelsetPlane(pt1, dir2, tag++));
  p.push_back(new gLevelsetPlane(pt2, dir1, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetCylinder::gLevelsetCylinder(const double *pt, const double *dir, const double &R, const double &H, int tag) : gLevelsetImproved() {
  double dir2[3] = {-dir[0], -dir[1], -dir[2]};
  double n[3]; norm(dir, n);
  double pt2[3] = {pt[0] + H * n[0], pt[1] + H * n[1], pt[2] + H * n[2]};
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetGenCylinder(pt, dir, R, tag++));
  p.push_back(new gLevelsetPlane(pt, dir2, tag++));
  p.push_back(new gLevelsetPlane(pt2, dir, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetCylinder::gLevelsetCylinder(const double * pt, const double *dir, const double &R, const double &r, const double &H, int tag) : gLevelsetImproved() {
  double dir2[3] = {-dir[0], -dir[1], -dir[2]};
  double n[3]; norm(dir, n);
  double pt2[3] = {pt[0] + H * n[0], pt[1] + H * n[1], pt[2] + H * n[2]};
  std::vector<gLevelset *> p1;
  p1.push_back(new gLevelsetGenCylinder(pt, dir, R, tag++));
  p1.push_back(new gLevelsetPlane(pt, dir2, tag++));
  p1.push_back(new gLevelsetPlane(pt2, dir, tag++));
  std::vector<gLevelset *> p2;
  p2.push_back(new gLevelsetIntersection(p1));
  p2.push_back(new gLevelsetGenCylinder(pt, dir, r, tag));
  Ls = new gLevelsetCut(p2);
}
gLevelsetCylinder::gLevelsetCylinder(const gLevelsetCylinder &lv) : gLevelsetImproved(lv){}

gLevelsetConrod::gLevelsetConrod(const double *pt, const double *dir1, const double *dir2,
                                 const double &H1, const double &H2, const double &H3,
                                 const double &R1, const double &r1, const double &R2, const double &r2,
                                 const double &L1, const double &L2, const double &E, int tag) : gLevelsetImproved() {
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
  std::vector<gLevelset *> p1;
  p1.push_back(new gLevelsetBox(pt31, pt32, pt33, pt34, pt35, pt36, pt37, pt38, tag));
  p1.push_back(new gLevelsetCylinder(pt1, dir2, R1, H1, tag+6));
  p1.push_back(new gLevelsetCylinder(pt2, dir2, R2, H2, tag+9));
  std::vector<gLevelset *> p2;
  p2.push_back(new gLevelsetUnion(p1));
  p2.push_back(new gLevelsetGenCylinder(pt1, dir2, r1, tag+12));
  p2.push_back(new gLevelsetGenCylinder(pt2, dir2, r2, tag+13));
  Ls = new gLevelsetCut(p2);
}

gLevelsetConrod::gLevelsetConrod(const gLevelsetConrod &lv) : gLevelsetImproved(lv){}
