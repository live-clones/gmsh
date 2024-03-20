// HighOrderMeshOptimizer - Copyright (C) 2013-2024 UCLouvain-ULiege
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use, copy,
// modify, merge, publish, distribute, and/or sell copies of the
// Software, and to permit persons to whom the Software is furnished
// to do so, provided that the above copyright notice(s) and this
// permission notice appear in all copies of the Software and that
// both the above copyright notice(s) and this permission notice
// appear in supporting documentation.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR HOLDERS INCLUDED IN THIS NOTICE BE LIABLE FOR
// ANY CLAIM, OR ANY SPECIAL INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY
// DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS,
// WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS
// ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE
// OF THIS SOFTWARE.

#include "SPoint3.h"
#include "SVector3.h"
#include "nodalBasis.h"
#include "GEdge.h"
#include "GFace.h"
#include "MElement.h"
#include "MLine.h"
#include "MTriangle.h"
#include "MQuadrangle.h"
#include "BasisFactory.h"
#include "JacobianBasis.h"
#include "GModel.h"
#if defined(HAVE_ANN)
#include "ANN/ANN.h"
#endif
#include "CADDistances.h"

namespace {

  // ---------------------------------- Discretization of curves
  // ----------------------------------

  class parametricLine {
    void recurDiscretize(const double &t1, const double &t2, const SPoint3 &p1,
                         const SPoint3 &p2, std::vector<SPoint3> &dpts,
                         std::vector<double> &ts, double Prec, int minDepth,
                         int maxDepth, int depth) const;

  public:
    virtual ~parametricLine() {}
    virtual SPoint3 operator()(double xi) const = 0;
    virtual SVector3 derivative(double xi) const = 0;
    virtual SVector3 secondDerivative(double xi) const = 0;
    SVector3 curvature(double xi) const;
    void discretize(std::vector<SPoint3> &dpts, std::vector<double> &ts,
                    double Prec, int minDepth, int maxDepth, double t0 = 0.,
                    double t1 = 1.) const;
  };

  class parametricLineNodalBasis : public parametricLine {
    const nodalBasis &_basis;
    const std::vector<SPoint3> &_xyz;

  public:
    parametricLineNodalBasis(const nodalBasis &basis,
                             const std::vector<SPoint3> &xyz);
    virtual SPoint3 operator()(double xi) const;
    virtual SVector3 derivative(double xi) const;
    virtual SVector3 secondDerivative(double xi) const;
  };

  class parametricLineGEdge : public parametricLine {
    const GEdge *_edge;
    double _t0, _t1;

  public:
    parametricLineGEdge(const GEdge *edge, double t0, double t1);
    virtual SPoint3 operator()(double xi) const;
    virtual SVector3 derivative(double xi) const;
    virtual SVector3 secondDerivative(double xi) const;
  };

  void parametricLine::recurDiscretize(const double &t1, const double &t2,
                                       const SPoint3 &p1, const SPoint3 &p2,
                                       std::vector<SPoint3> &dpts,
                                       std::vector<double> &ts, double Prec,
                                       int minDepth, int maxDepth,
                                       int depth) const
  {
    double t = 0.5 * (t2 + t1);
    SPoint3 p = (*this)(t);
    SVector3 dx(p, (p1 + p2) * 0.5);
    if(((depth >= minDepth) && (dx.norm() < Prec)) || (depth >= maxDepth)) {
      dpts.push_back(p);
      ts.push_back(t);
      dpts.push_back(p2);
      ts.push_back(t2);
    }
    else {
      recurDiscretize(t1, t, p1, p, dpts, ts, Prec, minDepth, maxDepth,
                      depth + 1);
      recurDiscretize(t, t2, p, p2, dpts, ts, Prec, minDepth, maxDepth,
                      depth + 1);
    }
  }

  void parametricLine::discretize(std::vector<SPoint3> &dpts,
                                  std::vector<double> &ts, double Prec,
                                  int minDepth, int maxDepth, double t0,
                                  double t1) const
  {
    dpts.push_back((*this)(t0));
    ts.push_back(t0);
    recurDiscretize(t0, t1, dpts[0], (*this)(t1), dpts, ts, Prec, minDepth,
                    maxDepth, 0);
  }

  SVector3 parametricLine::curvature(double xi) const
  {
    SVector3 xp = derivative(xi);
    SVector3 xpp = secondDerivative(xi);
    const double nxp = xp.norm(), onxp = 1. / nxp;
    SVector3 c = (onxp * onxp * onxp) * (xpp * nxp - xp * dot(xp, xpp) * onxp);
    return c;
  }

  parametricLineNodalBasis::parametricLineNodalBasis(
    const nodalBasis &basis, const std::vector<SPoint3> &xyz)
    : _basis(basis), _xyz(xyz)
  {
  }

  SPoint3 parametricLineNodalBasis::operator()(double xi) const
  {
    double *psi = new double[_xyz.size()];
    SPoint3 p(0., 0., 0.);
    _basis.f(-1 + 2 * xi, 0., 0., psi);
    for(size_t j = 0; j < _xyz.size(); ++j) {
      p[0] += psi[j] * _xyz[j].x();
      p[1] += psi[j] * _xyz[j].y();
      p[2] += psi[j] * _xyz[j].z();
    }
    delete[] psi;
    return p;
  }

  SVector3 parametricLineNodalBasis::derivative(double xi) const
  {
    double(*dpsi)[3] = new double[_xyz.size()][3];
    SVector3 p(0., 0., 0.);
    _basis.df(-1 + 2 * xi, 0., 0., dpsi);
    for(size_t j = 0; j < _xyz.size(); ++j) {
      p[0] += dpsi[j][0] * _xyz[j].x();
      p[1] += dpsi[j][0] * _xyz[j].y();
      p[2] += dpsi[j][0] * _xyz[j].z();
    }
    delete[] dpsi;
    return p;
  }

  SVector3 parametricLineNodalBasis::secondDerivative(double xi) const
  {
    double(*ddpsi)[3][3] = new double[_xyz.size()][3][3];
    SVector3 p(0, 0, 0);
    _basis.ddf(-1 + 2 * xi, 0, 0, ddpsi);
    for(size_t j = 0; j < _xyz.size(); ++j) {
      p[0] += ddpsi[j][0][0] * _xyz[j].x();
      p[1] += ddpsi[j][0][0] * _xyz[j].y();
      p[2] += ddpsi[j][0][0] * _xyz[j].z();
    }
    delete[] ddpsi;
    return p;
  }

  parametricLineGEdge::parametricLineGEdge(const GEdge *edge, double t0,
                                           double t1)
    : _edge(edge), _t0(t0), _t1(t1)
  {
  }

  SPoint3 parametricLineGEdge::operator()(double xi) const
  {
    GPoint gp = _edge->point(_t0 + (_t1 - _t0) * xi);
    return SPoint3(gp.x(), gp.y(), gp.z());
  }

  SVector3 parametricLineGEdge::derivative(double xi) const
  {
    return _edge->firstDer(_t0 + (_t1 - _t0) * xi);
  }

  SVector3 parametricLineGEdge::secondDerivative(double xi) const
  {
    return _edge->secondDer(_t0 + (_t1 - _t0) * xi);
  }

  void oversample(std::vector<SPoint3> &s, double tol)
  {
    std::vector<SPoint3> t;
    for(unsigned int i = 1; i < s.size(); i++) {
      SPoint3 p0 = s[i - 1];
      SPoint3 p1 = s[i];
      double d = p0.distance(p1);
      int N = (int)(d / tol);
      t.push_back(p0);
      for(int j = 1; j < N; j++) {
        const double xi = (double)j / N;
        t.push_back(p0 + (p1 - p0) * xi);
      }
    }
    t.push_back(s[s.size() - 1]);
    s = t;
  }

  // ---------------------------------- Discrete Fréchet distance
  // ----------------------------------

  double recurMinMax(int i, int j, fullMatrix<double> &CA,
                     const std::vector<SPoint3> &P,
                     const std::vector<SPoint3> &Q)
  {
    double CAij;
    if(CA(i, j) > -1.) { CAij = CA(i, j); }
    else if(i == 0 && j == 0) {
      CA(i, j) = P[0].distance(Q[0]); // update the CA permanent
      CAij = CA(i, j); // set the current relevant value
    }
    else if(i > 0 && j == 0) {
      CA(i, j) = std::max(recurMinMax(i - 1, 0, CA, P, Q), P[i].distance(Q[1]));
      CAij = CA(i, j);
    }
    else if(i == 0 && j > 0) {
      CA(i, j) = std::max(recurMinMax(0, j - 1, CA, P, Q), P[0].distance(Q[j]));
      CAij = CA(i, j);
    }
    else if(i > 0 && j > 0) {
      double temp = std::min(std::min(recurMinMax(i - 1, j, CA, P, Q),
                                      recurMinMax(i - 1, j - 1, CA, P, Q)),
                             recurMinMax(i, j - 1, CA, P, Q));
      CA(i, j) = std::max(temp, P[i].distance(Q[j]));
      CAij = CA(i, j);
    }
    else {
      CA(i, j) = 1.e22;
      CAij = CA(i, j);
    }
    return CAij;
  }

  double discreteFrechetDistanceBrute(const std::vector<SPoint3> &P,
                                      const std::vector<SPoint3> &Q)
  {
    const int sP = P.size();
    const int sQ = Q.size();
    fullMatrix<double> CA(sP, sQ);
    CA.setAll(-1.);
    double cm = recurMinMax(sP - 1, sQ - 1, CA, P, Q);
    return cm;
  }

  // ---------------------------------- Discrete Hausdorff distance
  // ----------------------------------

  double oneSidedMaxDist(const std::vector<SPoint3> &dpts1,
                         const std::vector<SPoint3> &dpts2, int &iMaxDist,
                         int &jMaxDist)
  {
    double maxDist = 0.;
    for(unsigned int i = 0; i < dpts1.size(); i++) {
      double dist = 1.e22;
      int jDist = 0;
      for(unsigned int j = 0; j < dpts2.size(); j++) {
        double h = dpts1[i].distance(dpts2[j]);
        if(h < dist) {
          dist = h;
          jDist = j;
        }
      }
      if(dist > maxDist) {
        maxDist = dist;
        jMaxDist = jDist;
        iMaxDist = i;
      }
    }
    return maxDist;
  }

#if defined(HAVE_ANN)
  double oneSidedMaxDistFast(const std::vector<SPoint3> &dptsA,
                             const ANNpointArray &ptsB, ANNkd_tree *treeB,
                             double tol)
  {
    ANNidx idx[1];
    ANNdist distSq[1];
    ANNdist maxDistSq = 0.;
    for(unsigned int i = 0; i < dptsA.size(); i++) {
      ANNcoord xyz[3] = {dptsA[i].x(), dptsA[i].y(), dptsA[i].z()};
      treeB->annkSearch(xyz, 1, idx, distSq);
      if(distSq[0] > maxDistSq) maxDistSq = distSq[0];
    }
    return sqrt(maxDistSq);
  }
#endif

  double discreteHausdorffDistanceBrute(const std::vector<SPoint3> &dpts1,
                                        const std::vector<SPoint3> &dpts2)
  {
    int i1, j1, i2, j2;
    double d1 = oneSidedMaxDist(dpts1, dpts2, i1, j1);
    double d2 = oneSidedMaxDist(dpts2, dpts1, i2, j2);
    return (d1 > d2) ? d1 : d2;
  }

  double discreteHausdorffDistanceFast(const std::vector<SPoint3> &dpts1,
                                       const std::vector<SPoint3> &dpts2,
                                       double tol)
  {
#if defined(HAVE_ANN)
    ANNpointArray pts1 = annAllocPts(dpts1.size(), 3);
    for(unsigned int k = 0; k < dpts1.size(); k++) {
      pts1[k][0] = dpts1[k].x();
      pts1[k][1] = dpts1[k].y();
      pts1[k][2] = dpts1[k].z();
    }
    ANNkd_tree *tree1 = new ANNkd_tree(pts1, dpts1.size(), 3);

    ANNpointArray pts2 = annAllocPts(dpts2.size(), 3);
    for(unsigned int k = 0; k < dpts2.size(); k++) {
      pts2[k][0] = dpts2[k].x();
      pts2[k][1] = dpts2[k].y();
      pts2[k][2] = dpts2[k].z();
    }
    ANNkd_tree *tree2 = new ANNkd_tree(pts2, dpts2.size(), 3);

    double d1 = oneSidedMaxDistFast(dpts1, pts2, tree2, tol);
    double d2 = oneSidedMaxDistFast(dpts2, pts1, tree1, tol);

    delete tree1, tree2;
    annDeallocPts(pts1);
    annDeallocPts(pts2);

    return (d1 > d2) ? d1 : d2;
#else
    Msg::Error(
      "Gmsh should be compiled using ANN to compute Hausdorff distance");
    return 0.;
#endif
  }

  template <int distDef>
  double discreteDistance(MLine *l, GEdge *ed, double tol, int meshDiscr,
                          int geomDiscr)
  {
    if(ed->geomType() == GEntity::Line) return 0.;

    std::vector<SPoint3> dpts1, dpts2;
    std::vector<double> ts1, ts2;

    if(geomDiscr == CADDIST_DECASTELJAU)
      ed->discretize(tol, dpts1, ts1);
    else {
      double t0, t1;
      reparamMeshVertexOnEdge(l->getVertex(0), ed, t0);
      reparamMeshVertexOnEdge(l->getVertex(1), ed, t1);
      Range<double> uBounds = ed->parBounds(0);
      if(t1 == uBounds.low())
        t1 = uBounds.high(); // Avoid problem with closed curves, assuming nodes
                             // are always ordered with increasing u
      parametricLineGEdge l1(ed, t0, t1);
      l1.discretize(dpts1, ts1, tol, 5, 45);
    }
    oversample(dpts1, tol);

    if(meshDiscr == CADDIST_DECASTELJAU)
      l->discretize(tol, dpts2, ts2);
    else {
      const nodalBasis &basis = *(l->getFunctionSpace());
      std::vector<SPoint3> xyz;
      const int nV = l->getNumVertices();
      xyz.reserve(nV);
      for(int i = 0; i < nV; ++i) xyz.push_back(l->getVertex(i)->point());
      parametricLineNodalBasis l2(basis, xyz);
      int minDepth = std::ceil(std::log(nV) / std::log(2));
      l2.discretize(dpts2, ts2, tol, minDepth, 10 * minDepth);
    }
    oversample(dpts2, tol);

    switch(distDef) {
    case 1: return discreteHausdorffDistanceBrute(dpts1, dpts2);
    case 2: return discreteHausdorffDistanceFast(dpts1, dpts2, tol);
    case 3: return discreteFrechetDistanceBrute(dpts1, dpts2);
    }
    return -1.;
  }

} // namespace

double discreteHausdorffDistanceBruteEdge(MLine *l, GEdge *ed, double tol,
                                          int meshDiscr, int geomDiscr)
{
  return discreteDistance<1>(l, ed, tol, meshDiscr, geomDiscr);
}

double discreteHausdorffDistanceFastEdge(MLine *l, GEdge *ed, double tol,
                                         int meshDiscr, int geomDiscr)
{
  return discreteDistance<2>(l, ed, tol, meshDiscr, geomDiscr);
}

double discreteFrechetDistanceEdge(MLine *l, GEdge *ed, double tol,
                                   int meshDiscr, int geomDiscr)
{
  return discreteDistance<3>(l, ed, tol, meshDiscr, geomDiscr);
}

// ---------------------------------- Taylor-based distance
// ----------------------------------

double taylorDistanceSq1D(const GradientBasis *gb,
                          const fullMatrix<double> &nodesXYZ,
                          const std::vector<SVector3> &tanCAD)
{
  const int nV = nodesXYZ.size1();
  fullMatrix<double> dxyzdX(nV, 3);
  gb->getGradientsFromNodes(nodesXYZ, &dxyzdX, nullptr, nullptr);
  //  const double dx = nodesXYZ(1, 0) - nodesXYZ(0, 0), dy = nodesXYZ(1, 1) -
  //  nodesXYZ(0, 1),
  //               dz = nodesXYZ(1, 2) - nodesXYZ(0, 2), h =
  //               0.5*sqrt(dx*dx+dy*dy+dz*dz)/double(nV-1);
  double distSq = 0.;
  for(int i = 0; i < nV; i++) {
    SVector3 tanMesh(dxyzdX(i, 0), dxyzdX(i, 1), dxyzdX(i, 2));
    const double h = 0.25 * tanMesh.normalize(); // Half of "local edge length"
    SVector3 diff =
      (dot(tanCAD[i], tanMesh) > 0) ? tanCAD[i] - tanMesh : tanCAD[i] + tanMesh;
    distSq += h * h * diff.normSq();
  }
  return distSq;
}

double taylorDistanceSq2D(const GradientBasis *gb,
                          const fullMatrix<double> &nodesXYZ,
                          const std::vector<SVector3> &normCAD)
{
  const int nV = nodesXYZ.size1();
  fullMatrix<double> dxyzdX(nV, 3), dxyzdY(nV, 3);
  gb->getGradientsFromNodes(nodesXYZ, &dxyzdX, &dxyzdY, nullptr);
  double distSq = 0.;
  for(int i = 0; i < nV; i++) {
    const double nz = dxyzdX(i, 0) * dxyzdY(i, 1) - dxyzdX(i, 1) * dxyzdY(i, 0);
    const double ny =
      -dxyzdX(i, 0) * dxyzdY(i, 2) + dxyzdX(i, 2) * dxyzdY(i, 0);
    const double nx = dxyzdX(i, 1) * dxyzdY(i, 2) - dxyzdX(i, 2) * dxyzdY(i, 1);
    SVector3 normMesh(nx, ny, nz);
    const double h =
      0.25 * sqrt(normMesh.normalize()); // Half of sqrt of "local area", to be
                                         // adjusted w.r.t. el. type?
    SVector3 diff = (dot(normCAD[i], normMesh) > 0) ? normCAD[i] - normMesh :
                                                      normCAD[i] + normMesh;
    distSq += h * h * diff.normSq();
  }
  return distSq;
}

double taylorDistanceEdge(MLine *l, GEdge *ge)
{
  const int nV = l->getNumVertices();
  const GradientBasis *gb;
  gb = BasisFactory::getGradientBasis(l->getTypeForMSH(), FuncSpaceData(l));

  // Coordinates of vertices
  fullMatrix<double> nodesXYZ(nV, 3);
  l->getNodesCoord(nodesXYZ);

  // Tangent to CAD at vertices
  std::vector<SVector3> tanCAD(nV);
  for(int i = 0; i < nV; i++) {
    double tCAD;
    reparamMeshVertexOnEdge(l->getVertex(i), ge, tCAD);
    tanCAD[i] = ge->firstDer(tCAD);
    tanCAD[i].normalize();
  }

  // Compute distance
  return sqrt(taylorDistanceSq1D(gb, nodesXYZ, tanCAD));
}

double taylorDistanceFace(MElement *el, GFace *gf)
{
  const int nV = el->getNumVertices();
  const GradientBasis *gb;
  gb = BasisFactory::getGradientBasis(el->getTypeForMSH(), FuncSpaceData(el));

  // Coordinates of vertices
  fullMatrix<double> nodesXYZ(nV, 3);
  el->getNodesCoord(nodesXYZ);

  // Normal to CAD at vertices
  std::vector<SVector3> normCAD(nV);
  for(int i = 0; i < nV; i++) {
    SPoint2 pCAD;
    reparamMeshVertexOnFace(el->getVertex(i), gf, pCAD);
    normCAD[i] = gf->normal(pCAD);
    normCAD[i].normalize();
  }

  // Compute distance
  return sqrt(taylorDistanceSq2D(gb, nodesXYZ, normCAD));
}

// ---------------------------------- General functions
// ----------------------------------

void distanceFromElementsToGeometry(GModel *gm, int dim,
                                    std::map<MElement *, double> &distances)
{
  std::map<MEdge, double, MEdgeLessThan> dist2Edge;
  for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
    if((*it)->geomType() == GEntity::Line) continue;
    for(unsigned int i = 0; i < (*it)->lines.size(); i++) {
      double d = taylorDistanceEdge((*it)->lines[i], *it);
      MEdge e = (*it)->lines[i]->getEdge(0);
      dist2Edge[e] = d;
    }
  }

  std::map<MFace, double, MFaceLessThan> dist2Face;
  for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
    if((*it)->geomType() == GEntity::Plane) continue;
    for(unsigned int i = 0; i < (*it)->triangles.size(); i++) {
      double d = taylorDistanceFace((*it)->triangles[i], *it);
      MFace f = (*it)->triangles[i]->getFace(0);
      dist2Face[f] = d;
    }
  }

  std::vector<GEntity *> entities;
  gm->getEntities(entities);
  for(int iEnt = 0; iEnt < entities.size(); ++iEnt) {
    GEntity *&entity = entities[iEnt];
    if(entity->dim() != dim) continue;
    for(int iEl = 0; iEl < entity->getNumMeshElements();
        iEl++) { // Detect bad elements
      MElement *element = entity->getMeshElement(iEl);
      double d = 0.;
      for(int iEdge = 0; iEdge < element->getNumEdges(); ++iEdge) {
        MEdge e = element->getEdge(iEdge);
        auto it = dist2Edge.find(e);
        if(it != dist2Edge.end()) d += it->second;
      }
      for(int iFace = 0; iFace < element->getNumFaces(); ++iFace) {
        MFace f = element->getFace(iFace);
        auto it = dist2Face.find(f);
        if(it != dist2Face.end()) d += it->second;
      }
      distances[element] = d;
    }
  }
}

double distanceToGeometry(GModel *gm, int distType, double tol, int meshDiscr,
                          int geomDiscr)
{
  const int dim = gm->getDim();
  double maxDist = 0.;

  if(dim == 2) {
    for(auto it = gm->firstEdge(); it != gm->lastEdge(); ++it) {
      if((*it)->geomType() == GEntity::Line) continue;
      for(unsigned int i = 0; i < (*it)->lines.size(); i++) {
        double dist;
        switch(distType) {
        case CADDIST_TAYLOR:
          dist = taylorDistanceEdge((*it)->lines[i], *it);
          break;
        case CADDIST_FRECHET:
          dist = discreteFrechetDistanceEdge((*it)->lines[i], *it, tol,
                                             meshDiscr, geomDiscr);
          break;
        case CADDIST_HAUSFAST:
          dist = discreteHausdorffDistanceFastEdge((*it)->lines[i], *it, tol,
                                                   meshDiscr, geomDiscr);
          break;
        case CADDIST_HAUSBRUTE:
          dist = discreteHausdorffDistanceBruteEdge((*it)->lines[i], *it, tol,
                                                    meshDiscr, geomDiscr);
          break;
        default:
          Msg::Error("Wrong CAD distance type in distanceToGeometry");
          break;
        }
        maxDist = std::max(dist, maxDist);
      }
    }
  }
  else if(dim == 3) {
    if(distType == CADDIST_TAYLOR) {
      for(auto it = gm->firstFace(); it != gm->lastFace(); ++it) {
        if((*it)->geomType() == GEntity::Plane) continue;
        for(unsigned int i = 0; i < (*it)->triangles.size(); i++) {
          maxDist =
            std::max(taylorDistanceFace((*it)->triangles[i], *it), maxDist);
        }
      }
    }
    else {
      Msg::Error("CAD distance type %i not implemented for surfaces", distType);
      return -1.;
    }
  }
  else {
    Msg::Error("CAD distance cannot be computed for dimension %i", dim);
    return -1.;
  }

  return maxDist;
}

double distanceToGeometry(GModel *gm, int dim, int tag, int distType,
                          double tol, int meshDiscr, int geomDiscr)
{
  double maxDist = 0.;

  if(dim == 2) {
    GEdge *ge = gm->getEdgeByTag(tag);
    if(ge->geomType() == GEntity::Line) return 0.;
    for(unsigned int i = 0; i < ge->lines.size(); i++) {
      double dist;
      switch(distType) {
      case CADDIST_TAYLOR: dist = taylorDistanceEdge(ge->lines[i], ge); break;
      case CADDIST_FRECHET:
        dist = discreteFrechetDistanceEdge(ge->lines[i], ge, tol, meshDiscr,
                                           geomDiscr);
        break;
      case CADDIST_HAUSFAST:
        dist = discreteHausdorffDistanceFastEdge(ge->lines[i], ge, tol,
                                                 meshDiscr, geomDiscr);
        break;
      case CADDIST_HAUSBRUTE:
        dist = discreteHausdorffDistanceBruteEdge(ge->lines[i], ge, tol,
                                                  meshDiscr, geomDiscr);
        break;
      default:
        Msg::Error("Wrong CAD distance type in distanceToGeometry");
        return -1.;
        break;
      }
      maxDist = std::max(dist, maxDist);
    }
  }
  else if(dim == 3) {
    if(distType == CADDIST_TAYLOR) {
      GFace *gf = gm->getFaceByTag(tag);
      if(gf->geomType() == GEntity::Plane) return 0.;
      for(unsigned int i = 0; i < gf->triangles.size(); i++)
        maxDist = std::max(taylorDistanceFace(gf->triangles[i], gf), maxDist);
      for(unsigned int i = 0; i < gf->quadrangles.size(); i++)
        maxDist = std::max(taylorDistanceFace(gf->quadrangles[i], gf), maxDist);
    }
    else {
      Msg::Error("CAD distance type %i not implemented for surfaces", distType);
      return -1.;
    }
  }
  else {
    Msg::Error("CAD distance cannot be computed for dimension %i", dim);
    return -1.;
  }

  return maxDist;
}
