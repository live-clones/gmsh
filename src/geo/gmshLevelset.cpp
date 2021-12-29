// Gmsh - Copyright (C) 1997-2022 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Contributor(s):
//   Gaetan Bricteux
//

#include <queue>
#include <stack>
#include <cmath>
#include "gmshLevelset.h"
#include "fullMatrix.h"
#include "GModel.h"
#include "OS.h"
#include "MElement.h"
#include "Numeric.h"
#include "cartesian.h"
#include "GmshConfig.h"
#include "mathEvaluator.h"

#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif

std::set<gLevelset *, gLevelsetLessThan> gLevelset::all_;
int gLevelset::maxTag_ = 0;

bool gLevelsetLessThan::operator()(const gLevelset *l1,
                                   const gLevelset *l2) const
{
  return l1->getTag() < l2->getTag();
}

gLevelset *gLevelset::find(int tag)
{
  gLevelset l(tag);
  auto it = all_.find(&l);
  if(it == all_.end()) return nullptr;
  return *it;
}

void gLevelset::add(gLevelset *l) { all_.insert(l); }

void insertActiveCells(double x, double y, double z, double rmax,
                       cartesianBox<double> &box)
{
  int id1 = box.getCellContainingPoint(x - rmax, y - rmax, z - rmax);
  int id2 = box.getCellContainingPoint(x + rmax, y + rmax, z + rmax);
  int i1, j1, k1;
  box.getCellIJK(id1, i1, j1, k1);
  int i2, j2, k2;
  box.getCellIJK(id2, i2, j2, k2);
  for(int i = i1; i <= i2; i++)
    for(int j = j1; j <= j2; j++)
      for(int k = k1; k <= k2; k++)
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
      for(int k = 0; k < K; k++) {
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
        for(int ii = 0; ii < 8; ii++) {
          exist[ii] = child->activeCellExists(idx[ii]);
          if(exist[ii]) atLeastOne = true;
          if(!exist[ii]) butNotAll = true;
        }
        if(atLeastOne &&
           (butNotAll ||
            (i != 0 &&
             !parent->activeCellExists(parent->getCellIndex(i - 1, j, k))) ||
            (i != I - 1 &&
             !parent->activeCellExists(parent->getCellIndex(i + 1, j, k))) ||
            (j != 0 &&
             !parent->activeCellExists(parent->getCellIndex(i, j - 1, k))) ||
            (j != J - 1 &&
             !parent->activeCellExists(parent->getCellIndex(i, j + 1, k))) ||
            (k != 0 &&
             !parent->activeCellExists(parent->getCellIndex(i, j, k - 1))) ||
            (k != K - 1 &&
             !parent->activeCellExists(parent->getCellIndex(i, j, k + 1)))))
          for(int ii = 0; ii < 8; ii++) child->eraseActiveCell(idx[ii]);
      }
  return removeBadChildCells(child);
}

void removeParentCellsWithChildren(cartesianBox<double> *box)
{
  if(!box->getChildBox()) return;
  for(int i = 0; i < box->getNxi(); i++)
    for(int j = 0; j < box->getNeta(); j++)
      for(int k = 0; k < box->getNzeta(); k++) {
        if(box->activeCellExists(box->getCellIndex(i, j, k))) {
          cartesianBox<double> *parent = box, *child;
          int ii = i, jj = j, kk = k;
          while((child = parent->getChildBox())) {
            ii *= 2;
            jj *= 2;
            kk *= 2;
            if(child->activeCellExists(child->getCellIndex(ii, jj, kk))) {
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
  std::vector<SPoint3> nodes;
  std::vector<int> indices;
  for(auto it = box.nodalValuesBegin(); it != box.nodalValuesEnd(); ++it) {
    nodes.push_back(box.getNodeCoordinates(it->first));
    indices.push_back(it->first);
  }
  // Msg::Info("  %d nodes in the grid at level %d", (int)nodes.size(),
  // box.getLevel());
  std::vector<double> dist, localdist;
  std::vector<SPoint3> dummy;
  for(auto fit = gm->firstFace(); fit != gm->lastFace(); fit++) {
    if((*fit)->geomType() == GEntity::DiscreteSurface) {
      for(std::size_t k = 0; k < (*fit)->getNumMeshElements(); k++) {
        std::vector<double> iDistances;
        std::vector<SPoint3> iClosePts;
        std::vector<double> iDistancesE;
        MElement *e = (*fit)->getMeshElement(k);
        if(e->getType() == TYPE_TRI) {
          MVertex *v1 = e->getVertex(0);
          MVertex *v2 = e->getVertex(1);
          MVertex *v3 = e->getVertex(2);
          SPoint3 p1(v1->x(), v1->y(), v1->z());
          SPoint3 p2(v2->x(), v2->y(), v2->z());
          SPoint3 p3(v3->x(), v3->y(), v3->z());
          // sign plus if in the direction of the normal
          signedDistancesPointsTriangle(localdist, dummy, nodes, p2, p1, p3);
        }
        if(dist.empty())
          dist = localdist;
        else {
          for(std::size_t j = 0; j < localdist.size(); j++) {
            dist[j] =
              (fabs(dist[j]) < fabs(localdist[j])) ? dist[j] : localdist[j];
          }
        }
      }
    }
    else {
      // we should use the STL here
      Msg::Info("Levelset computation on CAD surface not implemented");
    }
  }

  for(std::size_t j = 0; j < dist.size(); j++)
    box.setNodalValue(indices[j], dist[j]);

  if(box.getChildBox()) computeLevelset(gm, *box.getChildBox());
}

inline double det3(double d11, double d12, double d13, double d21, double d22,
                   double d23, double d31, double d32, double d33)
{
  return d11 * (d22 * d33 - d23 * d32) - d21 * (d12 * d33 - d13 * d32) +
         d31 * (d12 * d23 - d13 * d22);
}

inline void norm(const double *vec, double *norm)
{
  double n = sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
  norm[0] = vec[0] / n;
  norm[1] = vec[1] / n;
  norm[2] = vec[2] / n;
}

inline void cross(const double *pt0, const double *pt1, const double *pt2,
                  double *cross)
{
  double v1[3] = {pt1[0] - pt0[0], pt1[1] - pt0[1], pt1[2] - pt0[2]};
  double v2[3] = {pt2[0] - pt0[0], pt2[1] - pt0[1], pt2[2] - pt0[2]};
  cross[0] = v1[1] * v2[2] - v2[1] * v1[2];
  cross[1] = v2[0] * v1[2] - v1[0] * v2[2];
  cross[2] = v1[0] * v2[1] - v2[0] * v1[1];
}

inline bool isPlanar(const double *pt1, const double *pt2, const double *pt3,
                     const double *pt4)
{
  double c1[3];
  cross(pt1, pt2, pt3, c1);
  double c2[3];
  cross(pt1, pt2, pt4, c2);
  double n1[3];
  norm(c1, n1);
  double n2[3];
  norm(c2, n2);
  return (n1[0] == n2[0] && n1[1] == n2[1] && n1[2] == n2[2]);
}

inline double evalRadialFnDer(int p, int index, double dx, double dy, double dz,
                              double ep)
{
  double r2 = dx * dx + dy * dy + dz * dz; // r^2
  switch(index) {
  case 0: // GA
    switch(p) {
    case 0: return exp(-ep * ep * r2);
    case 1: return -2 * ep * ep * dx * exp(-ep * ep * r2); // _x
    case 2: return -2 * ep * ep * dy * exp(-ep * ep * r2); // _y
    case 3: return -2 * ep * ep * dz * exp(-ep * ep * r2); // _z
    }
  case 1: // MQ
    switch(p) {
    case 0: return sqrt(1 + ep * ep * r2);
    case 1: return ep * ep * dx / sqrt(1 + ep * ep * r2);
    case 2: return ep * ep * dy / sqrt(1 + ep * ep * r2);
    case 3: return ep * ep * dz / sqrt(1 + ep * ep * r2);
    }
  }
  return 0.;
}

inline void printNodes(fullMatrix<double> &myNodes, fullMatrix<double> &surf)
{
  FILE *xyz = Fopen("myNodes.pos", "w");
  if(xyz) {
    fprintf(xyz, "View \"\"{\n");
    for(int itv = 1; itv != myNodes.size1(); ++itv) {
      fprintf(xyz, "SP(%g,%g,%g){%g};\n", myNodes(itv, 0), myNodes(itv, 1),
              myNodes(itv, 2), surf(itv, 0));
    }
    fprintf(xyz, "};\n");
    fclose(xyz);
  }
}

// extrude a list of the primitive levelsets with a "Level-order traversal
// sequence"
void gLevelset::getPrimitives(std::vector<gLevelset *> &gLsPrimitives)
{
  std::queue<gLevelset *> Q;
  Q.push(this);
  while(!Q.empty()) {
    gLevelset *p = Q.front();
    std::vector<gLevelset *> pp;
    pp = p->getChildren();
    if(pp.empty()) gLsPrimitives.push_back(p);
    Q.pop();
    if(!pp.empty()) {
      for(int i = 0; i < (int)pp.size(); i++) Q.push(pp[i]);
    }
  }
}

// extrude a list of the primitive levelsets with a "post-order traversal
// sequence"
void gLevelset::getPrimitivesPO(std::vector<gLevelset *> &gLsPrimitives)
{
  std::stack<gLevelset *> S;
  std::stack<gLevelset *> Sc; // levelset checked
  S.push(this);
  while(!S.empty()) {
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
void gLevelset::getRPN(std::vector<gLevelset *> &gLsRPN)
{
  std::stack<gLevelset *> S;
  std::stack<gLevelset *> Sc; // levelset checked
  S.push(this);
  while(!S.empty()) {
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

gLevelset::gLevelset(const gLevelset &lv) { tag_ = lv.tag_; }

gLevelsetSphere::gLevelsetSphere(const double &x, const double &y,
                                 const double &z, const double &R, int tag)
  : gLevelsetPrimitive(tag), xc(x), yc(y), zc(z), r(R)
{
  _hasDerivatives = true;
}

void gLevelsetSphere::gradient(double x, double y, double z, double &dfdx,
                               double &dfdy, double &dfdz) const
{
  const double xx = x - xc, yy = y - yc, zz = z - zc,
               dist = sqrt(xx * xx + yy * yy + zz * zz);

  dfdx = xx / dist;
  dfdy = yy / dist;
  dfdz = zz / dist;
}

void gLevelsetSphere::hessian(double x, double y, double z, double &dfdxx,
                              double &dfdxy, double &dfdxz, double &dfdyx,
                              double &dfdyy, double &dfdyz, double &dfdzx,
                              double &dfdzy, double &dfdzz) const
{
  const double xx = x - xc, yy = y - yc, zz = z - zc;
  const double distSq = xx * xx + yy * yy, fact = 1. / (distSq * sqrt(distSq));

  dfdxx = (zz * zz + yy * yy) * fact;
  dfdxy = -xx * yy * fact;
  dfdxz = -xx * zz * fact;
  dfdyx = dfdxy;
  dfdyy = (xx * xx + zz * zz) * fact;
  dfdyz = -yy * zz * fact;
  dfdzx = dfdxz;
  dfdzy = dfdyz;
  dfdzz = (xx * xx + yy * yy) * fact;
}

gLevelsetPlane::gLevelsetPlane(const std::vector<double> &pt,
                               const std::vector<double> &norm, int tag)
  : gLevelsetPrimitive(tag)
{
  a = norm[0];
  b = norm[1];
  c = norm[2];
  d = -a * pt[0] - b * pt[1] - c * pt[2];
}

gLevelsetPlane::gLevelsetPlane(const double *pt, const double *norm, int tag)
  : gLevelsetPrimitive(tag)
{
  a = norm[0];
  b = norm[1];
  c = norm[2];
  d = -a * pt[0] - b * pt[1] - c * pt[2];
}

gLevelsetPlane::gLevelsetPlane(const double *pt1, const double *pt2,
                               const double *pt3, int tag)
  : gLevelsetPrimitive(tag)
{
  a = det3(1., pt1[1], pt1[2], 1., pt2[1], pt2[2], 1., pt3[1], pt3[2]);
  b = det3(pt1[0], 1., pt1[2], pt2[0], 1., pt2[2], pt3[0], 1., pt3[2]);
  c = det3(pt1[0], pt1[1], 1., pt2[0], pt2[1], 1., pt3[0], pt3[1], 1.);
  d = -det3(pt1[0], pt1[1], pt1[2], pt2[0], pt2[1], pt2[2], pt3[0], pt3[1],
            pt3[2]);
}

gLevelsetPlane::gLevelsetPlane(const gLevelsetPlane &lv)
  : gLevelsetPrimitive(lv)
{
  a = lv.a;
  b = lv.b;
  c = lv.c;
  d = lv.d;
}

// level set defined by points (RBF interpolation)
fullMatrix<double>
gLevelsetPoints::generateRbfMat(int p, int index,
                                const fullMatrix<double> &nodes1,
                                const fullMatrix<double> &nodes2) const
{
  int m = nodes2.size1();
  int n = nodes1.size1();
  fullMatrix<double> rbfMat(m, n);

  double eps = 0.5 / delta;
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      double dx = nodes2(i, 0) - nodes1(j, 0);
      double dy = nodes2(i, 1) - nodes1(j, 1);
      double dz = nodes2(i, 2) - nodes1(j, 2);
      rbfMat(i, j) = evalRadialFnDer(p, index, dx, dy, dz, eps);
    }
  }
  return rbfMat;
}

void gLevelsetPoints::RbfOp(int p, int index, const fullMatrix<double> &cntrs,
                            const fullMatrix<double> &nodes,
                            fullMatrix<double> &D, bool isLocal) const
{
  fullMatrix<double> rbfMatB = generateRbfMat(p, index, cntrs, nodes);

  fullMatrix<double> rbfInvA;
  if(isLocal) {
    rbfInvA = generateRbfMat(0, index, cntrs, cntrs);
    rbfInvA.invertInPlace();
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
                                 fullMatrix<double> &fApprox,
                                 bool isLocal) const
{
  fApprox.resize(nodes.size1(), fValues.size2());
  fullMatrix<double> D;
  RbfOp(p, index, cntrs, nodes, D, isLocal);
  fApprox.gemm(D, fValues, 1.0, 0.0);
}

void gLevelsetPoints::setup_level_set(const fullMatrix<double> &cntrs,
                                      fullMatrix<double> &level_set_nodes,
                                      fullMatrix<double> &level_set_funvals)
{
  int numNodes = cntrs.size1();
  int nTot = 3 * numNodes;
  double normFactor;
  level_set_nodes.resize(nTot, 3);
  level_set_funvals.resize(nTot, 1);
  fullMatrix<double> ONES(numNodes + 1, 1), sx(numNodes, 1), sy(numNodes, 1);
  fullMatrix<double> sz(numNodes, 1), norms(numNodes, 3),
    cntrsPlus(numNodes + 1, 3);

  // Computes the normal vectors to the surface at each node
  double dist_min = 1.e6;
  double dist_max = 1.e-6;
  for(int i = 0; i < numNodes; ++i) {
    ONES(i, 0) = 1.0;
    cntrsPlus(i, 0) = cntrs(i, 0);
    cntrsPlus(i, 1) = cntrs(i, 1);
    cntrsPlus(i, 2) = cntrs(i, 2);
    for(int j = i + 1; j < numNodes; j++) {
      double dist =
        sqrt((cntrs(i, 0) - cntrs(j, 0)) * (cntrs(i, 0) - cntrs(j, 0)) +
             (cntrs(i, 1) - cntrs(j, 1)) * (cntrs(i, 1) - cntrs(j, 1)) +
             (cntrs(i, 2) - cntrs(j, 2)) * (cntrs(i, 2) - cntrs(j, 2)));
      if(dist < dist_min) dist_min = dist;
      if(dist > dist_max) dist_max = dist;
    }
  }
  ONES(numNodes, 0) = -1.0;
  cntrsPlus(numNodes, 0) = cntrs(0, 0) + dist_max;
  cntrsPlus(numNodes, 1) = cntrs(0, 1) + dist_max;
  cntrsPlus(numNodes, 2) = cntrs(0, 2) + dist_max;

  delta = 0.23 * dist_min;
  evalRbfDer(1, 1, cntrsPlus, cntrs, ONES, sx, true);
  evalRbfDer(2, 1, cntrsPlus, cntrs, ONES, sy, true);
  evalRbfDer(3, 1, cntrsPlus, cntrs, ONES, sz, true);
  for(int i = 0; i < numNodes; ++i) {
    normFactor =
      sqrt(sx(i, 0) * sx(i, 0) + sy(i, 0) * sy(i, 0) + sz(i, 0) * sz(i, 0));
    sx(i, 0) = sx(i, 0) / normFactor;
    sy(i, 0) = sy(i, 0) / normFactor;
    sz(i, 0) = sz(i, 0) / normFactor;
    norms(i, 0) = sx(i, 0);
    norms(i, 1) = sy(i, 0);
    norms(i, 2) = sz(i, 0);
  }

  for(int i = 0; i < numNodes; ++i) {
    for(int j = 0; j < 3; ++j) {
      level_set_nodes(i, j) = cntrs(i, j);
      level_set_nodes(i + numNodes, j) = cntrs(i, j) - delta * norms(i, j);
      level_set_nodes(i + 2 * numNodes, j) = cntrs(i, j) + delta * norms(i, j);
    }
    level_set_funvals(i, 0) = 0.0;
    level_set_funvals(i + numNodes, 0) = -1;
    level_set_funvals(i + 2 * numNodes, 0) = 1;
  }
}

gLevelsetPoints::gLevelsetPoints(fullMatrix<double> &centers, int tag)
  : gLevelsetPrimitive(tag)
{
  int nbNodes = 3 * centers.size1();

  setup_level_set(centers, points, surf);
  printNodes(points, surf);

  // build invA matrix for 3*n points
  int indexRBF = 1;
  matAInv.resize(nbNodes, nbNodes);
  matAInv = generateRbfMat(0, indexRBF, points, points);
  matAInv.invertInPlace();
}

gLevelsetPoints::gLevelsetPoints(const gLevelsetPoints &lv)
  : gLevelsetPrimitive(lv)
{
  points = lv.points;
}

double gLevelsetPoints::operator()(double x, double y, double z) const
{
  if(mapP.empty())
    Msg::Info("Levelset Points : call computeLS() before calling operator()\n");

  SPoint3 sp(x, y, z);
  auto it = mapP.find(sp);
  if(it != mapP.end()) return it->second;
  printf("Levelset Points : Point not found\n");
  return 0;

  // fullMatrix<double> xyz_eval(1, 3), surf_eval(1,1);
  // xyz_eval(0,0) = x;
  // xyz_eval(0,1) = y;
  // xyz_eval(0,2) = z;
  // evalRbfDer(0, 1, points, xyz_eval, surf, surf_eval);
  // return surf_eval(0,0);
}

void gLevelsetPoints::computeLS(std::vector<MVertex *> &vert)
{
  fullMatrix<double> xyz_eval(vert.size(), 3), surf_eval(vert.size(), 1);
  for(std::size_t i = 0; i < vert.size(); i++) {
    xyz_eval(i, 0) = vert[i]->x();
    xyz_eval(i, 1) = vert[i]->y();
    xyz_eval(i, 2) = vert[i]->z();
  }
  evalRbfDer(0, 1, points, xyz_eval, surf, surf_eval);
  for(std::size_t i = 0; i < vert.size(); i++) {
    mapP[SPoint3(vert[i]->x(), vert[i]->y(), vert[i]->z())] = surf_eval(i, 0);
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

gLevelsetQuadric::gLevelsetQuadric(const gLevelsetQuadric &lv)
  : gLevelsetPrimitive(lv)
{
  for(int i = 0; i < 3; i++) {
    B[i] = lv.B[i];
    for(int j = 0; j < 3; j++) A[i][j] = lv.A[i][j];
  }
  C = lv.C;
}

void gLevelsetQuadric::Ax(const double x[3], double res[3], double fact)
{
  for(int i = 0; i < 3; i++) {
    res[i] = 0.;
    for(int j = 0; j < 3; j++) { res[i] += A[i][j] * x[j] * fact; }
  }
}

void gLevelsetQuadric::xAx(const double x[3], double &res, double fact)
{
  res = fact * (A[0][0] * x[0] * x[0] + A[1][1] * x[1] * x[1] +
                A[2][2] * x[2] * x[2] + A[1][0] * x[1] * x[0] * 2. +
                A[2][0] * x[2] * x[0] * 2. + A[1][2] * x[1] * x[2] * 2.);
}

void gLevelsetQuadric::translate(const double transl[3])
{
  double b;
  xAx(transl, b, 1.0);
  C += (-B[0] * transl[0] - B[1] * transl[1] - B[2] * transl[2] + b);

  double x[3];
  Ax(transl, x, 2.0);
  B[0] += -x[0];
  B[1] += -x[1];
  B[2] += -x[2];
}

void gLevelsetQuadric::rotate(const double rotate[3][3])
{
  double a11 = 0., a12 = 0., a13 = 0., a22 = 0., a23 = 0., a33 = 0.;
  double b1 = 0., b2 = 0., b3 = 0.;
  for(int i = 0; i < 3; i++) {
    b1 += B[i] * rotate[i][0];
    b2 += B[i] * rotate[i][1];
    b3 += B[i] * rotate[i][2];
    for(int j = 0; j < 3; j++) {
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
void gLevelsetQuadric::computeRotationMatrix(const double dir[3],
                                             double t[3][3])
{
  double norm = sqrt(dir[0] * dir[0] + dir[1] * dir[1]);
  double n[3] = {1., 0., 0.};
  double ct = 1., st = 0.;
  if(norm != 0.) {
    double theta = atan(norm / dir[2]);
    n[0] = dir[1] / norm;
    n[1] = -dir[0] / norm;
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

void gLevelsetQuadric::computeRotationMatrix(const double dir1[3],
                                             const double dir2[3],
                                             double t[3][3])
{
  double norm = sqrt((dir1[1] * dir2[2] - dir1[2] * dir2[1]) *
                       (dir1[1] * dir2[2] - dir1[2] * dir2[1]) +
                     (dir1[2] * dir2[0] - dir1[0] * dir2[2]) *
                       (dir1[2] * dir2[0] - dir1[0] * dir2[2]) +
                     (dir1[0] * dir2[1] - dir1[1] * dir2[0]) *
                       (dir1[0] * dir2[1] - dir1[1] * dir2[0]));
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

void gLevelsetQuadric::init()
{
  for(int i = 0; i < 3; i++) {
    B[i] = 0.;
    for(int j = 0; j < 3; j++) A[i][j] = 0.;
  }
  C = 0.;
}

double gLevelsetQuadric::operator()(double x, double y, double z) const
{
  return (A[0][0] * x * x + 2. * A[0][1] * x * y + 2. * A[0][2] * x * z +
          A[1][1] * y * y + 2. * A[1][2] * y * z + A[2][2] * z * z + B[0] * x +
          B[1] * y + B[2] * z + C);
}

gLevelsetShamrock::gLevelsetShamrock(double _xmid, double _ymid, double _zmid,
                                     double _a, double _b, int _c, int tag)
  : gLevelsetPrimitive(tag), xmid(_xmid), a(_a), b(_b), c(_c)
{
  // creating the iso-zero
  double angle = 0.;
  double r;
  while(angle <= 2. * M_PI) {
    r = a + b * sin(c * angle);
    iso_x.push_back(r * sin(angle) + xmid);
    iso_y.push_back(r * cos(angle) + xmid);
    angle += 2. * M_PI / 1000.;
  }
}

double gLevelsetShamrock::operator()(double x, double y, double z) const
{
  // computing distance to pre-defined (sampled) iso-zero
  double dx, dy, xi, yi, d;
  dx = x - iso_x[0];
  dy = y - iso_y[0];
  double distance = sqrt(dx * dx + dy * dy);
  auto itx = iso_x.begin();
  auto itxen = iso_x.end();
  auto ity = iso_y.begin();
  auto itminx = iso_x.begin();
  auto itminy = iso_y.begin();
  itx++;
  ity++;
  for(; itx != itxen; itx++, ity++) {
    xi = *itx;
    yi = *ity;
    dx = x - xi;
    dy = y - yi;
    d = sqrt(dx * dx + dy * dy);
    if(distance > d) {
      distance = d;
      itminx = itx;
      itminy = ity;
    }
  }
  // still need to find the LS sign... using vectorial prod with tangent vector
  // if not, the LS gradient is discontinuous on iso-zero... oups !
  SVector3 t, p;
  p(0) = (*itminx) - x;
  p(1) = (*itminy) - y;
  if(itminx == (itxen - 1)) {
    t(0) = iso_x[0] - (*itminx);
    t(1) = iso_y[0] - (*itminy);
  }
  else {
    t(0) = (*(itminx + 1)) - (*itminx);
    t(1) = (*(itminy + 1)) - (*itminy);
  }
  double vectprod = (p(0) * t(1) - p(1) * t(0));
  double sign = (vectprod < 0.) ? -1. : 1.;

  return sign * distance;
}

gLevelsetPopcorn::gLevelsetPopcorn(double myxc, double myyc, double myzc,
                                   double myr0, double myA, double mysigma,
                                   int tag)
  : gLevelsetPrimitive(tag)
{
  A = myA;
  sigma = mysigma;
  r0 = myr0;
  xc = myxc;
  yc = myyc;
  zc = myzc;
}

double gLevelsetPopcorn::operator()(double x, double y, double z) const
{
  double s2 = sigma * sigma;
  double r =
    sqrt((x - xc) * (x - xc) + (y - yc) * (y - yc) + (z - zc) * (z - zc));
  // printf("z=%g zc=%g r=%g \n", z, zc, r);
  double val = r - r0;
  for(int k = 0; k < 5; k++) {
    double xk = r0 / sqrt(5.0) * (2. * cos(2 * k * M_PI / 5.0));
    double yk = r0 / sqrt(5.0) * (2. * sin(2 * k * M_PI / 5.0));
    double zk = r0 / sqrt(5.0);
    val -=
      A * exp(-((x - xc - xk) * (x - xc - xk) + (y - yc - yk) * (y - yc - yk) +
                (z - zc - zk) * (z - zc - zk)) /
              s2);
  }
  for(int k = 5; k < 10; k++) {
    double xk = r0 / sqrt(5.0) * (2. * cos((2. * (k - 5.) - 1.) * M_PI / 5.0));
    double yk = r0 / sqrt(5.0) * (2. * sin((2. * (k - 5.) - 1.) * M_PI / 5.0));
    double zk = -r0 / sqrt(5.0);
    val -=
      A * exp(-((x - xc - xk) * (x - xc - xk) + (y - yc - yk) * (y - yc - yk) +
                (z - zc - zk) * (z - zc - zk)) /
              s2);
  }
  val -= A * exp(-((x - xc) * (x - xc) + (y - yc) * (y - yc) +
                   (z - zc - r0) * (z - zc - r0)) /
                 s2);
  val -= A * exp(-((x - xc) * (x - xc) + (y - yc) * (y - yc) +
                   (z - zc + r0) * (z - zc + r0)) /
                 s2);
  return val;
}

gLevelsetMathEval::gLevelsetMathEval(const std::string &f, int tag)
  : gLevelsetPrimitive(tag)
{
  std::vector<std::string> expressions(1, f);
  std::vector<std::string> variables(3);
  variables[0] = "x";
  variables[1] = "y";
  variables[2] = "z";
  _expr = new mathEvaluator(expressions, variables);
}

gLevelsetMathEval::~gLevelsetMathEval()
{
  if(_expr) delete _expr;
}

double gLevelsetMathEval::operator()(double x, double y, double z) const
{
  std::vector<double> values(3), res(1);
  values[0] = x;
  values[1] = y;
  values[2] = z;
  if(_expr->eval(values, res)) return res[0];
  return 1.;
}

gLevelsetMathEvalAll::gLevelsetMathEvalAll(std::vector<std::string> expressions,
                                           int tag)
  : gLevelsetPrimitive(tag)
{
  _hasDerivatives = true;
  std::vector<std::string> variables(3);
  variables[0] = "x";
  variables[1] = "y";
  variables[2] = "z";
  _expr = new mathEvaluator(expressions, variables);
}

gLevelsetMathEvalAll::~gLevelsetMathEvalAll()
{
  if(_expr) delete _expr;
}

double gLevelsetMathEvalAll::operator()(double x, double y, double z) const
{
  std::vector<double> values(3), res(13);
  values[0] = x;
  values[1] = y;
  values[2] = z;
  if(_expr->eval(values, res)) return res[0];
  return 1.;
}

void gLevelsetMathEvalAll::gradient(double x, double y, double z, double &dfdx,
                                    double &dfdy, double &dfdz) const
{
  std::vector<double> values(3), res(13);
  values[0] = x;
  values[1] = y;
  values[2] = z;
  if(_expr->eval(values, res)) {
    dfdx = res[1];
    dfdy = res[2];
    dfdz = res[3];
  }
}

void gLevelsetMathEvalAll::hessian(double x, double y, double z, double &dfdxx,
                                   double &dfdxy, double &dfdxz, double &dfdyx,
                                   double &dfdyy, double &dfdyz, double &dfdzx,
                                   double &dfdzy, double &dfdzz) const
{
  std::vector<double> values(3), res(13);
  values[0] = x;
  values[1] = y;
  values[2] = z;
  if(_expr->eval(values, res)) {
    dfdxx = res[4];
    dfdxy = res[5];
    dfdxz = res[6];
    dfdyx = res[7];
    dfdyy = res[8];
    dfdyz = res[9];
    dfdzx = res[10];
    dfdzy = res[11];
    dfdzz = res[12];
  }
}

#if defined(HAVE_ANN)
gLevelsetDistMesh::gLevelsetDistMesh(GModel *gm, const std::string &physical,
                                     int nbClose, int tag)
  : gLevelsetPrimitive(tag), _nbClose(nbClose)
{
  std::map<int, std::vector<GEntity *> > groups[4];
  gm->getPhysicalGroups(groups);
  for(auto it = gm->firstPhysicalName(); it != gm->lastPhysicalName(); ++it) {
    if(it->second == physical) {
      _entities = groups[it->first.first][it->first.second];
    }
  }
  if(_entities.size() == 0) {
    Msg::Error(
      "distanceToMesh: the physical name '%s' does not exist in the GModel",
      physical.c_str());
  }

  // setup
  std::set<MVertex *> _all;
  for(std::size_t i = 0; i < _entities.size(); i++) {
    for(std::size_t k = 0; k < _entities[i]->getNumMeshElements(); k++) {
      MElement *e = _entities[i]->getMeshElement(k);
      for(std::size_t j = 0; j < e->getNumVertices(); j++) {
        MVertex *v = _entities[i]->getMeshElement(k)->getVertex(j);
        _all.insert(v);
        _v2e.insert(std::make_pair(v, e));
      }
    }
  }
  ANNpointArray nodes;
  nodes = annAllocPts(_all.size(), 3);
  auto itp = _all.begin();
  int ind = 0;
  while(itp != _all.end()) {
    MVertex *pt = *itp;
    nodes[ind][0] = pt->x();
    nodes[ind][1] = pt->y();
    nodes[ind][2] = pt->z();
    _vertices.push_back(pt);
    itp++;
    ind++;
  }
  _kdtree = new ANNkd_tree(nodes, _all.size(), 3);
}

gLevelsetDistMesh::~gLevelsetDistMesh()
{
  if(_kdtree) {
    ANNpointArray nodes = _kdtree->thePoints();
    annDeallocPts(nodes);
    delete _kdtree;
  }
}

double gLevelsetDistMesh::operator()(double x, double y, double z) const
{
  std::vector<ANNidx> index(_nbClose);
  std::vector<ANNdist> dist(_nbClose);
  double point[3] = {x, y, z};
  SPoint3 pt(x, y, z);
  _kdtree->annkSearch(point, _nbClose, &index[0],
                      &dist[0]); // squared distances
  std::set<MElement *> elements;
  int dimE = 1;
  for(int i = 0; i < _nbClose; i++) {
    int iVertex = index[i];
    MVertex *v = _vertices[iVertex];
    for(auto itm = _v2e.lower_bound(v); itm != _v2e.upper_bound(v); ++itm) {
      elements.insert(itm->second);
      dimE = itm->second->getDim();
    }
  }
  double minDistance = 1.e22;
  SPoint3 closestPoint;
  std::vector<MElement *> closestElements;
  for(auto it = elements.begin(); it != elements.end(); ++it) {
    double distance = 0.;
    MVertex *v1 = (*it)->getVertex(0);
    MVertex *v2 = (*it)->getVertex(1);
    SPoint3 p1(v1->x(), v1->y(), v1->z());
    SPoint3 p2(v2->x(), v2->y(), v2->z());
    SPoint3 closePt;
    if(dimE == 1) {
      signedDistancePointLine(p1, p2, pt, distance, closePt); // !! > 0
    }
    else if(dimE == 2) {
      MVertex *v3 = (*it)->getVertex(2);
      SPoint3 p3(v3->x(), v3->y(), v3->z());
      if(p1 == p2 || p1 == p3 || p2 == p3)
        distance = 1.e22;
      else
        signedDistancePointTriangle(p1, p2, p3, pt, distance, closePt);
    }
    else {
      Msg::Error("Cannot compute a distance to an entity of dimension %d\n",
                 dimE);
    }
    if(dimE == 1 && fabs(distance) < fabs(minDistance)) {
      minDistance = distance;
    }
    else if(dimE == 2) {
      if(fabs(distance) - fabs(minDistance) < 1.e-9) {
        closestElements.push_back(*it);
      }
      else if(fabs(distance) < fabs(minDistance)) {
        closestPoint = closePt;
        minDistance = distance;
        closestElements.clear();
        closestElements.push_back(*it);
      }
    }
  }
  if(closestElements.size() > 1) {
    SVector3 vd(closestPoint, pt);
    SVector3 meanNorm(0., 0., 0.); // angle weighted mean normal
    if(closestElements.size() == 2) { // closestPoint on edge
      meanNorm = closestElements[0]->getFace(0).normal() +
                 closestElements[1]->getFace(0).normal();
    }
    else { // closestPoint on vertex
      for(std::size_t i = 0; i < closestElements.size(); i++) {
        double alpha = 0.;
        SPoint3 p1;
        bool found = false;
        for(int j = 0; j < closestElements[i]->getNumEdges(); j++) {
          SPoint3 ep0 = closestElements[i]->getEdge(j).getVertex(0)->point();
          SPoint3 ep1 = closestElements[i]->getEdge(j).getVertex(1)->point();
          if(closestPoint == ep0) {
            if(!found) {
              p1 = ep1;
              found = true;
            }
            else {
              alpha =
                angle(SVector3(closestPoint, p1), SVector3(closestPoint, ep1));
              break;
            }
          }
          if(closestPoint == ep1) {
            if(!found) {
              p1 = ep0;
              found = true;
            }
            else {
              alpha =
                angle(SVector3(closestPoint, p1), SVector3(closestPoint, ep0));
              break;
            }
          }
        }
        meanNorm = meanNorm + alpha * closestElements[i]->getFace(0).normal();
      }
    }
    double dotDN = dot(vd, closestElements[0]->getFace(0).normal());
    double dotDE = dot(vd, meanNorm);
    if(dotDN * dotDE < 0.) minDistance *= -1.;
  }

  return -1.0 * minDistance;
}
#endif

#if defined(HAVE_POST)
gLevelsetPostView::gLevelsetPostView(int index, int tag)
  : gLevelsetPrimitive(tag), _viewIndex(index)
{
  if(_viewIndex >= 0 && _viewIndex < (int)PView::list.size()) {
    PView *view = PView::list[_viewIndex];
    _octree = new OctreePost(view);
  }
  else {
    Msg::Error("Unknown View[%d] in PostView levelset", _viewIndex);
    _octree = nullptr;
  }
}

double gLevelsetPostView::operator()(double x, double y, double z) const
{
  if(!_octree) return 1.;
  double val = 1.;
  _octree->searchScalar(x, y, z, &val, 0);
  return val;
}
#endif

gLevelsetGenCylinder::gLevelsetGenCylinder(const double *pt, const double *dir,
                                           const double &R, int tag)
  : gLevelsetQuadric(tag)
{
  A[0][0] = 1.;
  A[1][1] = 1.;
  C = -R * R;
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}

gLevelsetGenCylinder::gLevelsetGenCylinder(const gLevelsetGenCylinder &lv)
  : gLevelsetQuadric(lv)
{
}

gLevelsetEllipsoid::gLevelsetEllipsoid(const double *pt, const double *dir,
                                       const double &a, const double &b,
                                       const double &c, int tag)
  : gLevelsetQuadric(tag)
{
  A[0][0] = 1. / (a * a);
  A[1][1] = 1. / (b * b);
  A[2][2] = 1. / (c * c);
  C = -1.;
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}

gLevelsetEllipsoid::gLevelsetEllipsoid(const gLevelsetEllipsoid &lv)
  : gLevelsetQuadric(lv)
{
}

gLevelsetCone::gLevelsetCone(const double *pt, const double *dir,
                             const double &angle, int tag)
  : gLevelsetQuadric(tag)
{
  A[0][0] = 1.;
  A[1][1] = 1.;
  A[2][2] = -tan(angle) * tan(angle);
  double rot[3][3];
  computeRotationMatrix(dir, rot);
  rotate(rot);
  translate(pt);
}

gLevelsetCone::gLevelsetCone(const gLevelsetCone &lv) : gLevelsetQuadric(lv) {}

gLevelsetGeneralQuadric::gLevelsetGeneralQuadric(
  const double *pt, const double *dir, const double &x2, const double &y2,
  const double &z2, const double &z, const double &c, int tag)
  : gLevelsetQuadric(tag)
{
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

gLevelsetGeneralQuadric::gLevelsetGeneralQuadric(
  const gLevelsetGeneralQuadric &lv)
  : gLevelsetQuadric(lv)
{
}

gLevelsetTools::gLevelsetTools(const gLevelsetTools &lv) : gLevelset(lv)
{
  std::vector<gLevelset *> _children = lv.getChildren();
  unsigned siz = _children.size();
  children.resize(siz);
  for(unsigned i = 0; i < siz; ++i) children[i] = _children[i]->clone();
}

gLevelsetYarn::gLevelsetYarn(int dim, int phys, double minA, double majA,
                             int type, int tag)
  : gLevelsetPrimitive(tag) //, minorAxis(minA), majorAxis(majA), typeLs(type)
{
  std::map<int, std::vector<GEntity *> > groups;
  GModel::current()->getPhysicalGroups(dim, groups);
  entities = groups[phys];
  if(!entities.size())
    printf("No physical %d found for levelset yarn!\n", phys);
}

double gLevelsetYarn::operator()(double x, double y, double z) const
{
  double dist = 0.0;
  for(std::size_t i = 0; i < entities.size(); i++) {
    GEntity *g = entities[i];
    for(std::size_t j = 0; j < g->getNumMeshElements(); j++) {
      MElement *e = g->getMeshElement(j);
      MVertex *v1 = e->getVertex(0);
      MVertex *v2 = e->getVertex(1);
      SPoint3 p1(v1->x(), v1->y(), v1->z());
      SPoint3 p2(v2->x(), v2->y(), v2->z());
      /*if(e->getType() == TYPE_LIN){
        signedDistancesPointsEllipseLine(iDistances, iDistancesE, iIsInYarn,
      iClosePts, pts, p1, p2, majorAxis, minorAxis, majorAxis, minorAxis,
      typeLs);
      }
      else if(e->getType() == TYPE_TRI){
        MVertex *v3 = e->getVertex(2);
        SPoint3 p3(v3->x(),v3->y(),v3->z());
        signedDistancesPointsTriangle(iDistances, iClosePts, pts, p1, p2, p3);
      }*/
    }
  }
  return dist;
}

gLevelsetImproved::gLevelsetImproved(const gLevelsetImproved &lv)
  : gLevelset(lv)
{
  Ls = lv.Ls->clone();
}

gLevelsetBox::gLevelsetBox(const double *pt, const double *dir1,
                           const double *dir2, const double *dir3,
                           const double &a, const double &b, const double &c,
                           int tag)
  : gLevelsetImproved()
{
  double dir1m[3] = {-dir1[0], -dir1[1], -dir1[2]};
  double dir2m[3] = {-dir2[0], -dir2[1], -dir2[2]};
  double dir3m[3] = {-dir3[0], -dir3[1], -dir3[2]};
  double n1[3];
  norm(dir1, n1);
  double n2[3];
  norm(dir2, n2);
  double n3[3];
  norm(dir3, n3);
  double pt2[3] = {pt[0] + a * n1[0] + b * n2[0] + c * n3[0],
                   pt[1] + a * n1[1] + b * n2[1] + c * n3[1],
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

gLevelsetBox::gLevelsetBox(const double *pt1, const double *pt2,
                           const double *pt3, const double *pt4,
                           const double *pt5, const double *pt6,
                           const double *pt7, const double *pt8, int tag)
  : gLevelsetImproved()
{
  if(!isPlanar(pt1, pt2, pt3, pt4) || !isPlanar(pt5, pt6, pt7, pt8) ||
     !isPlanar(pt1, pt2, pt5, pt6) || !isPlanar(pt3, pt4, pt7, pt8) ||
     !isPlanar(pt1, pt4, pt5, pt8) || !isPlanar(pt2, pt3, pt6, pt7))
    printf(
      "WARNING : faces of the box are not planar! %d, %d, %d, %d, %d, %d\n",
      isPlanar(pt1, pt2, pt3, pt4), isPlanar(pt5, pt6, pt7, pt8),
      isPlanar(pt1, pt2, pt5, pt6), isPlanar(pt3, pt4, pt7, pt8),
      isPlanar(pt1, pt4, pt5, pt8), isPlanar(pt2, pt3, pt6, pt7));
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetPlane(pt5, pt6, pt8, tag++));
  p.push_back(new gLevelsetPlane(pt1, pt4, pt2, tag++));
  p.push_back(new gLevelsetPlane(pt1, pt2, pt5, tag++));
  p.push_back(new gLevelsetPlane(pt3, pt4, pt7, tag++));
  p.push_back(new gLevelsetPlane(pt2, pt3, pt6, tag++));
  p.push_back(new gLevelsetPlane(pt1, pt5, pt4, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetBox::gLevelsetBox(const gLevelsetBox &lv) : gLevelsetImproved(lv) {}

gLevelsetCylinder::gLevelsetCylinder(const std::vector<double> &pt,
                                     const std::vector<double> &dir,
                                     const double &R, const double &H, int tag)
  : gLevelsetImproved()
{
  double pt1[3] = {pt[0], pt[1], pt[2]};
  double dir1[3] = {dir[0], dir[1], dir[2]};
  double dir2[3] = {-dir1[0], -dir1[1], -dir1[2]};
  double n[3];
  norm(dir1, n);
  double pt2[3] = {pt1[0] + H * n[0], pt1[1] + H * n[1], pt1[2] + H * n[2]};
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetGenCylinder(pt1, dir1, R, tag++));
  p.push_back(new gLevelsetPlane(pt1, dir2, tag++));
  p.push_back(new gLevelsetPlane(pt2, dir1, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetCylinder::gLevelsetCylinder(const double *pt, const double *dir,
                                     const double &R, const double &H, int tag)
  : gLevelsetImproved()
{
  double dir2[3] = {-dir[0], -dir[1], -dir[2]};
  double n[3];
  norm(dir, n);
  double pt2[3] = {pt[0] + H * n[0], pt[1] + H * n[1], pt[2] + H * n[2]};
  std::vector<gLevelset *> p;
  p.push_back(new gLevelsetGenCylinder(pt, dir, R, tag++));
  p.push_back(new gLevelsetPlane(pt, dir2, tag++));
  p.push_back(new gLevelsetPlane(pt2, dir, tag));
  Ls = new gLevelsetIntersection(p);
}

gLevelsetCylinder::gLevelsetCylinder(const double *pt, const double *dir,
                                     const double &R, const double &r,
                                     const double &H, int tag)
  : gLevelsetImproved()
{
  double dir2[3] = {-dir[0], -dir[1], -dir[2]};
  double n[3];
  norm(dir, n);
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

gLevelsetCylinder::gLevelsetCylinder(const gLevelsetCylinder &lv)
  : gLevelsetImproved(lv)
{
}

gLevelsetConrod::gLevelsetConrod(const double *pt, const double *dir1,
                                 const double *dir2, const double &H1,
                                 const double &H2, const double &H3,
                                 const double &R1, const double &r1,
                                 const double &R2, const double &r2,
                                 const double &L1, const double &L2,
                                 const double &E, int tag)
  : gLevelsetImproved()
{
  double n1[3];
  norm(dir1, n1);
  double n2[3];
  norm(dir2, n2);
  double pt1[3] = {pt[0] - n2[0] * H1 / 2., pt[1] - n2[1] * H1 / 2.,
                   pt[2] - n2[2] * H1 / 2.};
  double pt2[3] = {pt[0] + n1[0] * E - n2[0] * H2 / 2.,
                   pt[1] + n1[1] * E - n2[1] * H2 / 2.,
                   pt[2] + n1[2] * E - n2[2] * H2 / 2.};
  double dir3[3];
  cross(pt1, pt2, pt, dir3);
  double n3[3];
  norm(dir3, n3);
  double pt31[3] = {pt[0] - n2[0] * H3 / 2. + n3[0] * L1 / 2.,
                    pt[1] - n2[1] * H3 / 2. + n3[1] * L1 / 2.,
                    pt[2] - n2[2] * H3 / 2. + n3[2] * L1 / 2.};
  double pt32[3] = {pt31[0] - n3[0] * L1, pt31[1] - n3[1] * L1,
                    pt31[2] - n3[2] * L1};
  double pt33[3] = {pt32[0] + n2[0] * H3, pt32[1] + n2[1] * H3,
                    pt32[2] + n2[2] * H3};
  double pt34[3] = {pt33[0] + n3[0] * L1, pt33[1] + n3[1] * L1,
                    pt33[2] + n3[2] * L1};
  double pt35[3] = {pt[0] + n1[0] * E - n2[0] * H3 / 2. + n3[0] * L2 / 2.,
                    pt[1] + n1[1] * E - n2[1] * H3 / 2. + n3[1] * L2 / 2.,
                    pt[2] + n1[2] * E - n2[2] * H3 / 2. + n3[2] * L2 / 2.};
  double pt36[3] = {pt35[0] - n3[0] * L2, pt35[1] - n3[1] * L2,
                    pt35[2] - n3[2] * L2};
  double pt37[3] = {pt36[0] + n2[0] * H3, pt36[1] + n2[1] * H3,
                    pt36[2] + n2[2] * H3};
  double pt38[3] = {pt37[0] + n3[0] * L2, pt37[1] + n3[1] * L2,
                    pt37[2] + n3[2] * L2};
  std::vector<gLevelset *> p1;
  p1.push_back(
    new gLevelsetBox(pt31, pt32, pt33, pt34, pt35, pt36, pt37, pt38, tag));
  p1.push_back(new gLevelsetCylinder(pt1, dir2, R1, H1, tag + 6));
  p1.push_back(new gLevelsetCylinder(pt2, dir2, R2, H2, tag + 9));
  std::vector<gLevelset *> p2;
  p2.push_back(new gLevelsetUnion(p1));
  p2.push_back(new gLevelsetGenCylinder(pt1, dir2, r1, tag + 12));
  p2.push_back(new gLevelsetGenCylinder(pt2, dir2, r2, tag + 13));
  Ls = new gLevelsetCut(p2);
}

gLevelsetConrod::gLevelsetConrod(const gLevelsetConrod &lv)
  : gLevelsetImproved(lv)
{
}

// Level-set for NACA0012 airfoil, last coeff. modified for zero-thickness
// trailing edge cf. http://en.wikipedia.org/wiki/NACA_airfoil
gLevelsetNACA00::gLevelsetNACA00(double x0, double y0, double c, double t)
  : _x0(x0), _y0(y0), _c(c), _t(t)
{
  _hasDerivatives = true;
}

void gLevelsetNACA00::getClosestBndPoint(double x, double y, double z,
                                         double &xb, double &yb,
                                         double &curvRad, bool &in) const
{
  static const int maxIter = 100;
  static const double tol = 1.e-10;

  const double tolr = tol / _c; // Tolerance (scaled bu chord)
  in = false; // Whether the point is inside the airfoil

  // Point translated according to airfoil origin and symmetry
  const double xt = x - _x0, yt = fabs(y - _y0);

  if(xt - _c > 1.21125 * _t * yt) {
    // Behind line normal to airfoil at trailing edge, closest boundary point is
    // trailing edge...
    xb = _x0 + _c;
    yb = _y0;
    curvRad = 0.;
  }
  else { // ...otherwise Newton-Raphson to find closest boundary point
    const double fact = 5. * _t * _c;
    double xtb = std::max(xt, tolr), ytb;
    double dyb, ddyb;
    for(int it = 0; it < maxIter; it++) {
      const double xbr = xtb / _c, sxbr = sqrt(xbr), xbr32 = xbr * sxbr,
                   xbr2 = xbr * xbr, xbr3 = xbr2 * xbr, xbr4 = xbr2 * xbr2;
      ytb = fact * (0.2969 * sxbr - 0.1260 * xbr - 0.3516 * xbr2 +
                    0.2843 * xbr3 - 0.1036 * xbr4);
      dyb = fact *
            (0.14845 / sxbr - 0.4144 * xbr3 + 0.8529 * xbr2 - 0.7032 * xbr -
             0.126) /
            _c;
      ddyb = fact *
             (-0.074225 / xbr32 - 1.2432 * xbr2 + 1.7058 * xbr - 0.7032) /
             (_c * _c);
      const double xx = xt - xtb, yy = yt - ytb;
      in = (xt > 0) && (yy < 0);
      const double dDistSq = -2. * (xx + dyb * yy);
      const double ddDistSq = 2. * (1. - ddyb * yy + dyb * dyb);
      const double mIncr = dDistSq / ddDistSq;
      if(fabs(mIncr) < tolr)
        break;
      else
        xtb -= mIncr;
      if(xtb < tolr) xtb = tolr;
      if(xtb > _c - tolr) xtb = _c - tolr;
    }
    xb = _x0 + xtb;
    yb = (y >= _y0) ? _y0 + ytb : _y0 - ytb;
    const double norm = sqrt(1. + dyb * dyb);
    curvRad = norm * norm * norm / fabs(ddyb);
  }
}

double gLevelsetNACA00::operator()(double x, double y, double z) const
{
  double xb, yb, curvRadb;
  bool in;

  getClosestBndPoint(x, y, z, xb, yb, curvRadb, in);
  const double xx = x - xb, yy = y - yb, distSq = xx * xx + yy * yy;

  return in ? -sqrt(distSq) : sqrt(distSq);
}

void gLevelsetNACA00::gradient(double x, double y, double z, double &dfdx,
                               double &dfdy, double &dfdz) const
{
  double xb, yb, curvRadb;
  bool in;

  getClosestBndPoint(x, y, z, xb, yb, curvRadb, in);
  const double xx = x - xb, yy = y - yb, distSq = xx * xx + yy * yy;
  const double dist = in ? -sqrt(distSq) : sqrt(distSq);

  dfdx = xx / dist;
  dfdy = yy / dist;
  dfdz = 0.;
}

void gLevelsetNACA00::hessian(double x, double y, double z, double &dfdxx,
                              double &dfdxy, double &dfdxz, double &dfdyx,
                              double &dfdyy, double &dfdyz, double &dfdzx,
                              double &dfdzy, double &dfdzz) const
{
  double xb, yb, curvRadb;
  bool in;

  getClosestBndPoint(x, y, z, xb, yb, curvRadb, in);

  const double xx = x - xb, yy = y - yb, distSq = xx * xx + yy * yy;
  const double dist = in ? -sqrt(distSq) : sqrt(distSq);
  const double curvRad = curvRadb + dist,
               fact = 1. / (curvRad * curvRad * curvRad);

  dfdxx = yy * yy * fact;
  dfdxy = -xx * yy * fact;
  dfdxz = 0.;
  dfdyx = dfdxy;
  dfdyy = xx * xx * fact;
  dfdyz = 0.;
  dfdzx = 0.;
  dfdzy = 0.;
  dfdzz = 0.;
}
