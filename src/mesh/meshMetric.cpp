// Gmsh - Copyright (C) 1997-2024 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include <algorithm>
#include "meshMetric.h"
#include "meshGFaceOptimize.h"
#include "Context.h"
#include "GEntity.h"
#include "GModel.h"
#include "gmshLevelset.h"
#include "MElementOctree.h"
#include "OS.h"
#include "Context.h"

meshMetric::meshMetric(GModel *gm)
{
  hasAnalyticalMetric = false;
  _dim = gm->getDim();
  std::map<MElement *, MElement *> newP;
  std::map<MElement *, MElement *> newD;

  if(_dim == 2) {
    for(auto fit = gm->firstFace(); fit != gm->lastFace(); ++fit) {
      for(std::size_t i = 0; i < (*fit)->getNumMeshElements(); i++) {
        MElement *e = (*fit)->getMeshElement(i);
        MElement *copy = e->copy(_vertexMap, newP, newD);
        _elements.push_back(copy);
      }
    }
  }
  else if(_dim == 3) {
    for(auto rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit) {
      for(std::size_t i = 0; i < (*rit)->getNumMeshElements(); i++) {
        MElement *e = (*rit)->getMeshElement(i);
        MElement *copy = e->copy(_vertexMap, newP, newD);
        _elements.push_back(copy);
      }
    }
  }
  _octree = new MElementOctree(_elements);
  buildVertexToElement(_elements, _adj);
}

meshMetric::meshMetric(std::vector<MElement *> elements)
{
  hasAnalyticalMetric = false;

  _dim = elements[0]->getDim();
  std::map<MElement *, MElement *> newP;
  std::map<MElement *, MElement *> newD;

  for(std::size_t i = 0; i < elements.size(); i++) {
    MElement *e = elements[i];
    MElement *copy = e->copy(_vertexMap, newP, newD);
    _elements.push_back(copy);
  }

  _octree = new MElementOctree(_elements);
  buildVertexToElement(_elements, _adj);
}

void meshMetric::addMetric(int technique, simpleFunction<double> *fct,
                           const std::vector<double> &parameters)
{
  needMetricUpdate = true;

  int metricNumber = setOfMetrics.size();
  setOfFcts[metricNumber] = fct;
  setOfParameters[metricNumber] = parameters;
  setOfTechniques[metricNumber] = technique;

  if(fct->hasDerivatives()) hasAnalyticalMetric = true;

  computeMetric(metricNumber);
}

void meshMetric::updateMetrics()
{
  if(!setOfMetrics.size()) {
    Msg::Error("Can't intersect metrics, no metric registered");
    return;
  }

  auto it = _adj.begin();
  for(; it != _adj.end(); it++) {
    MVertex *ver = it->first;
    _nodalMetrics[ver] = setOfMetrics[0][ver];
    _nodalSizes[ver] = setOfSizes[0][ver];

    if(setOfMetrics.size() > 1)
      for(std::size_t i = 1; i < setOfMetrics.size(); i++) {
        _nodalMetrics[ver] =
          (_dim == 3) ? intersection_conserve_mostaniso(_nodalMetrics[ver],
                                                        setOfMetrics[i][ver]) :
                        intersection_conserve_mostaniso_2d(
                          _nodalMetrics[ver], setOfMetrics[i][ver]);
        _nodalSizes[ver] = std::min(_nodalSizes[ver], setOfSizes[i][ver]);
      }
  }
  needMetricUpdate = false;
}

void meshMetric::exportInfo(const char *fileendname)
{
  if(needMetricUpdate) updateMetrics();
  std::stringstream sg, sm, sl, sh, shm;
  sg << "meshmetric_gradients_" << fileendname;
  sm << "meshmetric_metric_" << fileendname;
  sl << "meshmetric_levelset_" << fileendname;
  sh << "meshmetric_hessian_" << fileendname;
  shm << "meshmetric_hessianmat_" << fileendname;
  std::ofstream out_grad(sg.str().c_str());
  std::ofstream out_metric(sm.str().c_str());
  std::ofstream out_ls(sl.str().c_str());
  std::ofstream out_hess(sh.str().c_str());
  std::ofstream out_hessmat(shm.str().c_str());
  out_grad << "View \"ls_gradient\"{" << std::endl;
  out_metric << "View \"metric\"{" << std::endl;
  out_ls << "View \"ls\"{" << std::endl;
  out_hess << "View \"hessian\"{" << std::endl;
  out_hessmat << "View \"hessian_mat\"{" << std::endl;
  auto itelem = _elements.begin();
  auto itelemen = _elements.end();
  for(; itelem != itelemen; itelem++) {
    MElement *e = *itelem;
    if(e->getDim() == 2) {
      out_metric << "TT(";
      out_grad << "VT(";
      out_ls << "ST(";
      out_hess << "ST(";
      out_hessmat << "TT(";
    }
    else {
      out_metric << "TS(";
      out_grad << "VS(";
      out_ls << "SS(";
      out_hess << "SS(";
      out_hessmat << "TS(";
    }
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      MVertex *ver = e->getVertex(i);
      out_metric << ver->x() << "," << ver->y() << "," << ver->z();
      out_grad << ver->x() << "," << ver->y() << "," << ver->z();
      out_ls << ver->x() << "," << ver->y() << "," << ver->z();
      out_hess << ver->x() << "," << ver->y() << "," << ver->z();
      out_hessmat << ver->x() << "," << ver->y() << "," << ver->z();
      if(i != e->getNumVertices() - 1) {
        out_metric << ",";
        out_grad << ",";
        out_ls << ",";
        out_hess << ",";
        out_hessmat << ",";
      }
      else {
        out_metric << "){";
        out_grad << "){";
        out_ls << "){";
        out_hess << "){";
        out_hessmat << "){";
      }
    }
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      MVertex *ver = e->getVertex(i);
      out_ls << vals[ver];
      out_hess << (hessians[ver](0, 0) + hessians[ver](1, 1) +
                   hessians[ver](2, 2));
      if(i == (e->getNumVertices() - 1)) {
        out_ls << "};" << std::endl;
        out_hess << "};" << std::endl;
      }
      else {
        out_ls << ",";
        out_hess << ",";
      }
      for(int k = 0; k < 3; k++) {
        out_grad << grads[ver](k);
        if((k == 2) && (i == (e->getNumVertices() - 1)))
          out_grad << "};" << std::endl;
        else
          out_grad << ",";
        for(int l = 0; l < 3; l++) {
          out_metric << _nodalMetrics[ver](k, l);
          out_hessmat << hessians[ver](k, l);
          if((k == 2) && (l == 2) && (i == (e->getNumVertices() - 1))) {
            out_metric << "};" << std::endl;
            out_hessmat << "};" << std::endl;
          }
          else {
            out_metric << ",";
            out_hessmat << ",";
          }
        }
      }
    }
  }
  out_grad << "};" << std::endl;
  out_metric << "};" << std::endl;
  out_ls << "};" << std::endl;
  out_hess << "};" << std::endl;
  out_hessmat << "};" << std::endl;
  out_grad.close();
  out_metric.close();
  out_ls.close();
  out_hess.close();
  out_hessmat.close();
}

meshMetric::~meshMetric()
{
  if(_octree) delete _octree;
  for(std::size_t i = 0; i < _elements.size(); i++) delete _elements[i];
}

void meshMetric::computeValues()
{
  auto it = _adj.begin();
  while(it != _adj.end()) {
    std::vector<MElement *> lt = it->second;
    MVertex *ver = it->first;
    vals[ver] = (*_fct)(ver->x(), ver->y(), ver->z());
    it++;
  }
}

// Determines set of vertices to use for least squares
std::vector<MVertex *> getLSBlob(std::size_t minNbPt, v2t_cont::iterator it,
                                 v2t_cont &adj)
{
  //  static const double RADFACT = 3;
  //
  //  SPoint3 p0 = it->first->point();  // Vertex coordinates (center of circle)
  //
  //  double rad = 0.;
  //  for (auto itEl = it->second.begin(); itEl != it->second.end(); itEl++)
  //    rad = std::max(rad,(*itEl)->getOuterRadius());
  //  rad *= RADFACT;

  std::vector<MVertex *> vv(1, it->first),
    bvv = vv; // Vector of vertices in blob and in boundary of blob
  do {
    std::set<MVertex *> nbvv; // Set of vertices in new boundary
    for(auto itBV = bvv.begin(); itBV != bvv.end();
        itBV++) { // For each boundary vertex...
      std::vector<MElement *> &adjBV = adj[*itBV];
      for(auto itBVEl = adjBV.begin(); itBVEl != adjBV.end(); itBVEl++) {
        for(std::size_t iV = 0; iV < (*itBVEl)->getNumVertices();
            iV++) { // ... look for adjacent vertices...
          MVertex *v = (*itBVEl)->getVertex(iV);
          //          if ((find(vv.begin(),vv.end(),v) == vv.end()) &&
          //          (p0.distance(v->point()) <= rad)) nbvv.insert(v);
          if(find(vv.begin(), vv.end(), v) == vv.end())
            nbvv.insert(v); // ... and add them in the new boundary if they are
                            // not already in the blob
        }
      }
    }
    if(nbvv.empty())
      bvv.clear();
    else {
      bvv.assign(nbvv.begin(), nbvv.end());
      vv.insert(vv.end(), nbvv.begin(), nbvv.end());
    }
    //  } while (!bvv.empty());
  } while(vv.size() < minNbPt); // Repeat until min. number of points is reached

  return vv;
}

// Compute derivatives and second order derivatives using least squares
// 2D LS system: a_i0*x^2+a_i1*x*y+a_i2*y^2+a_i3*x+a_i4*y+a_i5=b_i
// 3D LS system:
// a_i0*x^2+a_i1*x*y+a_i2*x*z+a_i3*y^2+a_i4*y*z+a_i5*z^2+a_i6*x+a_i7*y+a_i8*z+a_i9=b_i
void meshMetric::computeHessian()
{
  std::size_t sysDim = (_dim == 2) ? 6 : 10;
  std::size_t minNbPtBlob = 3 * sysDim;

  for(auto it = _adj.begin(); it != _adj.end(); it++) {
    MVertex *ver = it->first;
    std::vector<MVertex *> vv = getLSBlob(minNbPtBlob, it, _adj);
    fullMatrix<double> A(vv.size(), sysDim), ATA(sysDim, sysDim);
    fullVector<double> b(vv.size()), ATb(sysDim), coeffs(sysDim);
    for(std::size_t i = 0; i < vv.size(); i++) {
      const double &x = vv[i]->x(), &y = vv[i]->y(), &z = vv[i]->z();
      if(_dim == 2) {
        A(i, 0) = x * x;
        A(i, 1) = x * y;
        A(i, 2) = y * y;
        A(i, 3) = x;
        A(i, 4) = y;
        A(i, 5) = 1.;
      }
      else {
        A(i, 0) = x * x;
        A(i, 1) = x * y;
        A(i, 2) = x * z;
        A(i, 3) = y * y;
        A(i, 4) = y * z;
        A(i, 5) = z * z;
        A(i, 6) = x;
        A(i, 7) = y;
        A(i, 8) = z;
        A(i, 9) = 1.;
      }
      b(i) = vals[vv[i]];
    }
    ATA.gemm(A, A, 1., 0., true, false);
    A.multWithATranspose(b, 1., 0., ATb);
    ATA.luSolve(ATb, coeffs);
    const double &x = ver->x(), &y = ver->y(), &z = ver->z();
    double d2udx2, d2udy2, d2udz2, d2udxy, d2udxz, d2udyz, dudx, dudy, dudz;
    if(_dim == 2) {
      d2udx2 = 2. * coeffs(0);
      d2udy2 = 2. * coeffs(2);
      d2udz2 = 0.;
      d2udxy = coeffs(1);
      d2udxz = 0.;
      d2udyz = 0.;
      dudx = d2udx2 * x + d2udxy * y + coeffs(3);
      dudy = d2udxy * x + d2udy2 * y + coeffs(4);
      dudz = 0.;
    }
    else {
      d2udx2 = 2. * coeffs(0);
      d2udy2 = 2. * coeffs(3);
      d2udz2 = 2. * coeffs(5);
      d2udxy = coeffs(1);
      d2udxz = coeffs(2);
      d2udyz = coeffs(4);
      dudx = d2udx2 * x + d2udxy * y + d2udxz * z + coeffs(6);
      dudy = d2udxy * x + d2udy2 * y + d2udyz * z + coeffs(7);
      dudz = d2udxz * x + d2udyz * y + d2udz2 * z + coeffs(8);
    }
    double duNorm = sqrt(dudx * dudx + dudy * dudy + dudz * dudz);
    if(duNorm == 0. || _technique == meshMetric::HESSIAN ||
       _technique == meshMetric::EIGENDIRECTIONS ||
       _technique == meshMetric::EIGENDIRECTIONS_LINEARINTERP_H)
      duNorm = 1.;
    grads[ver] = SVector3(dudx / duNorm, dudy / duNorm, dudz / duNorm);
    hessians[ver](0, 0) = d2udx2;
    hessians[ver](0, 1) = d2udxy;
    hessians[ver](0, 2) = d2udxz;
    hessians[ver](1, 0) = d2udxy;
    hessians[ver](1, 1) = d2udy2;
    hessians[ver](1, 2) = d2udyz;
    hessians[ver](2, 0) = d2udxz;
    hessians[ver](2, 1) = d2udyz;
    hessians[ver](2, 2) = d2udz2;
  }
}

void meshMetric::computeMetricLevelSet(MVertex *ver, SMetric3 &hessian,
                                       SMetric3 &metric, double &size, double x,
                                       double y, double z)
{
  double signed_dist;
  SVector3 gr;
  if(ver) {
    signed_dist = vals[ver];
    gr = grads[ver];
    hessian = hessians[ver];
  }
  else {
    signed_dist = (*_fct)(x, y, z);
    _fct->gradient(x, y, z, gr(0), gr(1), gr(2));
    _fct->hessian(x, y, z, hessian(0, 0), hessian(0, 1), hessian(0, 2),
                  hessian(1, 0), hessian(1, 1), hessian(1, 2), hessian(2, 0),
                  hessian(2, 1), hessian(2, 2));
  }

  double dist = fabs(signed_dist);

  SMetric3 H;
  double norm = gr(0) * gr(0) + gr(1) * gr(1) + gr(2) * gr(2);
  if(dist < _e && norm != 0.0) {
    double h = hmin * (hmax / hmin - 1) * dist / _e + hmin;
    double C = 1. / (h * h) - 1. / (hmax * hmax);
    H(0, 0) += C * gr(0) * gr(0) / norm;
    H(1, 1) += C * gr(1) * gr(1) / norm;
    H(2, 2) += C * gr(2) * gr(2) / norm;
    H(1, 0) = H(0, 1) = C * gr(1) * gr(0) / norm;
    H(2, 0) = H(0, 2) = C * gr(2) * gr(0) / norm;
    H(2, 1) = H(1, 2) = C * gr(2) * gr(1) / norm;
  }

  fullMatrix<double> V(3, 3);
  fullVector<double> S(3);
  H.eig(V, S);

  double lambda1, lambda2, lambda3;
  lambda1 = S(0);
  lambda2 = S(1);
  lambda3 = (_dim == 3) ? S(2) : 1.;

  SVector3 t1(V(0, 0), V(1, 0), V(2, 0));
  SVector3 t2(V(0, 1), V(1, 1), V(2, 1));
  SVector3 t3(V(0, 2), V(1, 2), V(2, 2));

  size =
    std::min(std::min(1 / sqrt(lambda1), 1 / sqrt(lambda2)), 1 / sqrt(lambda3));
  metric = SMetric3(lambda1, lambda2, lambda3, t1, t2, t3);
}

void meshMetric::computeMetricHessian(MVertex *ver, SMetric3 &hessian,
                                      SMetric3 &metric, double &size, double x,
                                      double y, double z)
{
  SVector3 gr;
  if(ver != nullptr) {
    gr = grads[ver];
    hessian = hessians[ver];
  }
  else if(ver == nullptr) {
    _fct->gradient(x, y, z, gr(0), gr(1), gr(2));
    _fct->hessian(x, y, z, hessian(0, 0), hessian(0, 1), hessian(0, 2),
                  hessian(1, 0), hessian(1, 1), hessian(1, 2), hessian(2, 0),
                  hessian(2, 1), hessian(2, 2));
  }

  double _epsilonP = 1.;
  double hminP = 1.e-12;
  double hmaxP = 1.e+12;

  fullMatrix<double> V(3, 3);
  fullVector<double> S(3);
  hessian.eig(V, S);

  double lambda1 =
    std::min(std::max(fabs(S(0)) / _epsilonP, 1. / (hmaxP * hmaxP)),
             1. / (hminP * hminP));
  double lambda2 =
    std::min(std::max(fabs(S(1)) / _epsilonP, 1. / (hmaxP * hmaxP)),
             1. / (hminP * hminP));
  double lambda3 =
    (_dim == 3) ?
      std::min(std::max(fabs(S(2)) / _epsilonP, 1. / (hmaxP * hmaxP)),
               1. / (hminP * hminP)) :
      1.;

  SVector3 t1(V(0, 0), V(1, 0), V(2, 0));
  SVector3 t2(V(0, 1), V(1, 1), V(2, 1));
  SVector3 t3 =
    (_dim == 3) ? SVector3(V(0, 2), V(1, 2), V(2, 2)) : SVector3(0., 0., 1.);

  size =
    std::min(std::min(1 / sqrt(lambda1), 1 / sqrt(lambda2)), 1 / sqrt(lambda3));
  metric = SMetric3(lambda1, lambda2, lambda3, t1, t2, t3);
}

void meshMetric::computeMetricFrey(MVertex *ver, SMetric3 &hessian,
                                   SMetric3 &metric, double &size, double x,
                                   double y, double z)
{
  double signed_dist;
  SVector3 gr;
  if(ver) {
    signed_dist = vals[ver];
    gr = grads[ver];
    hessian = hessians[ver];
  }
  else {
    signed_dist = (*_fct)(x, y, z);
    _fct->gradient(x, y, z, gr(0), gr(1), gr(2));
    _fct->hessian(x, y, z, hessian(0, 0), hessian(0, 1), hessian(0, 2),
                  hessian(1, 0), hessian(1, 1), hessian(1, 2), hessian(2, 0),
                  hessian(2, 1), hessian(2, 2));
  }

  double dist = fabs(signed_dist);

  SMetric3 H(1. / (hmax * hmax));
  double norm = gr(0) * gr(0) + gr(1) * gr(1) + gr(2) * gr(2);
  if(dist < _e && norm != 0.0) {
    double h = hmin * (hmax / hmin - 1.0) * dist / _e + hmin;
    double C = 1. / (h * h) - 1. / (hmax * hmax);
    double kappa = hessian(0, 0) + hessian(1, 1) + hessian(2, 2);
    double epsGeom = 4.0 * 3.14 * 3.14 / (kappa * _np * _np);
    H(0, 0) += C * gr(0) * gr(0) / (norm) + hessian(0, 0) / epsGeom;
    H(1, 1) += C * gr(1) * gr(1) / (norm) + hessian(1, 1) / epsGeom;
    H(2, 2) += C * gr(2) * gr(2) / (norm) + hessian(2, 2) / epsGeom;
    H(1, 0) = H(0, 1) = C * gr(1) * gr(0) / (norm) + hessian(1, 0) / epsGeom;
    H(2, 0) = H(0, 2) = C * gr(2) * gr(0) / (norm) + hessian(2, 0) / epsGeom;
    H(2, 1) = H(1, 2) = C * gr(2) * gr(1) / (norm) + hessian(2, 1) / epsGeom;
  }

  fullMatrix<double> V(3, 3);
  fullVector<double> S(3);
  H.eig(V, S);

  double lambda1, lambda2, lambda3;
  lambda1 = S(0);
  lambda2 = S(1);
  lambda3 = (_dim == 3) ? S(2) : 1.;

  if(dist < _e) {
    lambda1 = std::min(std::max(fabs(S(0)) / _epsilon, 1. / (hmax * hmax)),
                       1. / (hmin * hmin));
    lambda2 = std::min(std::max(fabs(S(1)) / _epsilon, 1. / (hmax * hmax)),
                       1. / (hmin * hmin));
    lambda3 = (_dim == 3) ?
                std::min(std::max(fabs(S(2)) / _epsilon, 1. / (hmax * hmax)),
                         1. / (hmin * hmin)) :
                1.;
  }

  SVector3 t1(V(0, 0), V(1, 0), V(2, 0));
  SVector3 t2(V(0, 1), V(1, 1), V(2, 1));
  SVector3 t3(V(0, 2), V(1, 2), V(2, 2));

  size =
    std::min(std::min(1 / sqrt(lambda1), 1 / sqrt(lambda2)), 1 / sqrt(lambda3));
  metric = SMetric3(lambda1, lambda2, lambda3, t1, t2, t3);
}

void meshMetric::computeMetricEigenDir(MVertex *ver, SMetric3 &hessian,
                                       SMetric3 &metric, double &size, double x,
                                       double y, double z)
{
  double signed_dist;
  SVector3 gVec;
  if(ver) {
    signed_dist = vals[ver];
    gVec = grads[ver];
    hessian = hessians[ver];
  }
  else {
    signed_dist = (*_fct)(x, y, z);
    _fct->gradient(x, y, z, gVec(0), gVec(1), gVec(2));
    _fct->hessian(x, y, z, hessian(0, 0), hessian(0, 1), hessian(0, 2),
                  hessian(1, 0), hessian(1, 1), hessian(1, 2), hessian(2, 0),
                  hessian(2, 1), hessian(2, 2));
  }

  double dist = fabs(signed_dist);

  const double metric_value_hmax = 1. / (hmax * hmax);
  const double gMag = gVec.norm(), invGMag = 1. / gMag;

  if(signed_dist < _e && signed_dist > _e_moins && gMag != 0.0) {
    const double metric_value_hmin = 1. / (hmin * hmin);
    const SVector3 nVec = invGMag * gVec; // Unit normal vector
    double lambda_n =
      0.; // Eigenvalues of metric for normal & tangential directions
    if(_technique == meshMetric::EIGENDIRECTIONS_LINEARINTERP_H) {
      // const double h_dist = hmin + ((hmax-hmin)/_e)*dist;
      // // Characteristic element size in the normal direction - linear interp
      // between hmin and hmax  lambda_n = 1./(h_dist*h_dist);
      double beta = CTX::instance()->mesh.smoothRatio;
      double h_dista = std::min((hmin + (dist * log(beta))), hmax);
      lambda_n = 1. / (h_dista * h_dista);
    }
    else if(_technique == meshMetric::EIGENDIRECTIONS) {
      const double maximum_distance =
        (signed_dist > 0.) ? _e : fabs(_e_moins); // ... or linear interpolation
                                                  // between 1/h_min^2 and
                                                  // 1/h_max^2
      lambda_n =
        metric_value_hmin +
        ((metric_value_hmax - metric_value_hmin) / maximum_distance) * dist;
    }
    std::vector<SVector3> tVec; // Unit tangential vectors
    std::vector<double> kappa; // Curvatures
    if(_dim == 2) { // 2D curvature formula: cf. R. Goldman, "Curvature formulas
                    // for implicit curves and surfaces", Computer Aided
                    // Geometric Design 22 (2005), pp. 632–658
      kappa.resize(2);
      kappa[0] =
        fabs(-gVec(1) * (-gVec(1) * hessian(0, 0) + gVec(0) * hessian(0, 1)) +
             gVec(0) * (-gVec(1) * hessian(1, 0) + gVec(0) * hessian(1, 1))) *
        pow(invGMag, 3);
      kappa[1] = 1.;
      tVec.resize(2);
      tVec[0] = SVector3(-nVec(1), nVec(0), 0.);
      tVec[1] = SVector3(0., 0., 1.);
    }
    else { // 3D curvature formula: cf. A.G. Belyaev, A.A. Pasko and T.L. Kunii,
           // "Ridges and Ravines on Implicit Surfaces," CGI, pp.530-535,
           // Computer Graphics International 1998 (CGI'98), 1998
      fullMatrix<double> ImGG(3, 3);
      ImGG(0, 0) = 1. - gVec(0) * gVec(0);
      ImGG(0, 1) = -gVec(0) * gVec(1);
      ImGG(0, 2) = -gVec(0) * gVec(2);
      ImGG(1, 0) = -gVec(1) * gVec(0);
      ImGG(1, 1) = 1. - gVec(1) * gVec(1);
      ImGG(1, 2) = -gVec(1) * gVec(2);
      ImGG(2, 0) = -gVec(2) * gVec(0);
      ImGG(2, 1) = -gVec(2) * gVec(1);
      ImGG(2, 2) = 1. - gVec(2) * gVec(2);
      fullMatrix<double> hess(3, 3);
      hessian.getMat(hess);
      fullMatrix<double> gN(3, 3); // Gradient of unit normal
      gN.gemm(ImGG, hess, 1., 0.);
      gN.scale(invGMag);
      fullMatrix<double> eigVecL(3, 3), eigVecR(3, 3);
      fullVector<double> eigValRe(3), eigValIm(3);
      gN.eig(eigValRe, eigValIm, eigVecL, eigVecR,
             false); // Eigendecomp. of gradient of unit normal
      kappa.resize(3); // Store abs. val. of eigenvalues (= principal curvatures
                       // only in non-normal directions)
      kappa[0] = fabs(eigValRe(0));
      kappa[1] = fabs(eigValRe(1));
      kappa[2] = fabs(eigValRe(2));
      tVec.resize(3); // Store normalized eigenvectors (= principal directions
                      // only in non-normal directions)
      tVec[0] = SVector3(eigVecR(0, 0), eigVecR(1, 0), eigVecR(2, 0));
      tVec[0].normalize();
      tVec[1] = SVector3(eigVecR(0, 1), eigVecR(1, 1), eigVecR(2, 1));
      tVec[1].normalize();
      tVec[2] = SVector3(eigVecR(0, 2), eigVecR(1, 2), eigVecR(2, 2));
      tVec[2].normalize();
      std::vector<double> tVecDotNVec(3); // Store dot products with normal
                                          // vector to look for normal direction
      tVecDotNVec[0] = fabs(dot(tVec[0], nVec));
      tVecDotNVec[1] = fabs(dot(tVec[1], nVec));
      tVecDotNVec[2] = fabs(dot(tVec[2], nVec));
      const int i_N = max_element(tVecDotNVec.begin(), tVecDotNVec.end()) -
                      tVecDotNVec.begin(); // Index of normal dir. = max. dot
                                           // products (close to 0. in
                                           // tangential dir.)
      kappa.erase(kappa.begin() + i_N); // Remove normal dir.
      tVec.erase(tVec.begin() + i_N);
    }
    const double invh_t0 = (_np * kappa[0]) / 6.283185307,
                 invh_t1 = (_np * kappa[1]) /
                           6.283185307; // Inverse of tangential size 0
    const double lambda_t0 = invh_t0 * invh_t0, lambda_t1 = invh_t1 * invh_t1;
    const double lambdaP_n =
      std::min(std::max(lambda_n, metric_value_hmax),
               metric_value_hmin); // Truncate eigenvalues
    const double lambdaP_t0 =
      std::min(std::max(lambda_t0, metric_value_hmax), metric_value_hmin);
    const double lambdaP_t1 =
      (_dim == 2) ?
        1. :
        std::min(std::max(lambda_t1, metric_value_hmax), metric_value_hmin);
    metric =
      SMetric3(lambdaP_n, lambdaP_t0, lambdaP_t1, nVec, tVec[0], tVec[1]);
    const double h_n = 1. / sqrt(lambdaP_n), h_t0 = 1. / sqrt(lambdaP_t0),
                 h_t1 = 1. / sqrt(lambdaP_t1);
    size = std::min(std::min(h_n, h_t0), h_t1);
  }
  else { // isotropic metric !
    SMetric3 mymetric(metric_value_hmax);
    metric = mymetric;
    size = hmax;
  }
}

void meshMetric::computeMetricIsoLinInterp(MVertex *ver, SMetric3 &hessian,
                                           SMetric3 &metric, double &size,
                                           double x, double y, double z)
{
  double signed_dist;
  SVector3 gr;
  if(ver) {
    signed_dist = vals[ver];
    gr = grads[ver];
    hessian = hessians[ver];
  }
  else {
    signed_dist = (*_fct)(x, y, z);
    _fct->gradient(x, y, z, gr(0), gr(1), gr(2));
    _fct->hessian(x, y, z, hessian(0, 0), hessian(0, 1), hessian(0, 2),
                  hessian(1, 0), hessian(1, 1), hessian(1, 2), hessian(2, 0),
                  hessian(2, 1), hessian(2, 2));
  }

  double dist = fabs(signed_dist);
  double norm = gr.normalize();
  size = hmax; // the characteristic element size in all directions - linear
               // interp between hmin and hmax
  if(norm != 0.) {
    if((signed_dist >= 0) && (signed_dist < _e))
      size = hmin + ((hmax - hmin) / _e) * dist;
    else if((signed_dist < 0) && (signed_dist > _e_moins))
      size = hmin - ((hmax - hmin) / _e_moins) * dist;
  }

  double lambda = 1. / size / size;
  metric(0, 0) = lambda;
  metric(0, 1) = 0.;
  metric(0, 2) = 0.;
  metric(1, 0) = 0.;
  metric(1, 1) = lambda;
  metric(1, 2) = 0.;
  metric(2, 0) = 0.;
  metric(2, 1) = 0.;
  metric(2, 2) = (_dim == 3) ? lambda : 1.;
}

// this function scales the mesh metric in order
// to reach a target number of elements
// We know that the number of elements in the final
// mesh will be (assuming M_e the metric at centroid of element e)
//   N = \sum_e \sqrt {\det (M_e)} V_e
// where V_e is the volume of e
// assuming that N_{target} = K N, we have
//   K N = K \sum_e \sqrt {\det (M_e)} V_e
//       =   \sum_e \sqrt {K^2 \det (M_e)} V_e
//       =   \sum_e \sqrt {\det (K^{2/d} M_e)} V_e
//  where d is the dimension of the problem.
// This means that the metric should be scaled by K^{2/d} where
// K is N_target / N
void meshMetric::scaleMetric(int nbElementsTarget, nodalMetricTensor &nmt)
{
  // compute N
  double N = 0;
  for(std::size_t i = 0; i < _elements.size(); i++) {
    MElement *e = _elements[i];
    SMetric3 m1 = nmt[e->getVertex(0)];
    SMetric3 m2 = nmt[e->getVertex(1)];
    SMetric3 m3 = nmt[e->getVertex(2)];
    if(_dim == 2) {
      SMetric3 m = interpolation(m1, m2, m3, 0.3333, 0.3333);
      N += sqrt(m.determinant()) * e->getVolume() * 4. / sqrt(3.0); // 3.0
    }
    else {
      SMetric3 m4 = nmt[e->getVertex(3)];
      SMetric3 m = interpolation(m1, m2, m3, m4, 0.25, 0.25, 0.25);
      N += sqrt(m.determinant()) * e->getVolume() * 12. / sqrt(2.0); // 4.0;
    }
  }
  double scale = pow((double)nbElementsTarget / N, 2.0 / _dim);
  for(auto it = nmt.begin(); it != nmt.end(); ++it) {
    if(_dim == 3) { it->second *= scale; }
    else {
      it->second(0, 0) *= scale;
      it->second(1, 0) *= scale;
      it->second(1, 1) *= scale;
    }
    SMetric3 &m = it->second;
    fullMatrix<double> V(3, 3);
    fullVector<double> S(3);
    m.eig(V, S);
    S(0) = std::min(std::max(S(0), 1 / (hmax * hmax)), 1 / (hmin * hmin));
    S(1) = std::min(std::max(S(1), 1 / (hmax * hmax)), 1 / (hmin * hmin));
    if(_dim == 3)
      S(2) = std::min(std::max(S(2), 1 / (hmax * hmax)), 1 / (hmin * hmin));
    SVector3 t1(V(0, 0), V(1, 0), V(2, 0));
    SVector3 t2(V(0, 1), V(1, 1), V(2, 1));
    SVector3 t3(V(0, 2), V(1, 2), V(2, 2));
    m = SMetric3(S(0), S(1), S(2), t1, t2, t3);
  }
}

void meshMetric::computeMetric(int metricNumber)
{
  _fct = setOfFcts[metricNumber];
  std::vector<double> parameters = setOfParameters[metricNumber];
  int technique = setOfTechniques[metricNumber];

  hmin = parameters.size() >= 3 ? parameters[1] : CTX::instance()->mesh.lcMin;
  hmax = parameters.size() >= 3 ? parameters[2] : CTX::instance()->mesh.lcMax;
  _e = parameters[0];
  _e_moins = (parameters.size() >= 5) ? parameters[4] : -parameters[0];
  if(_e_moins > 0.) _e_moins *= -1.;
  _epsilon = parameters[0];
  _technique = (MetricComputationTechnique)technique;
  _np = (parameters.size() >= 4) ? parameters[3] : 15.;

  computeValues();
  computeHessian();

  for(auto it = _adj.begin(); it != _adj.end(); it++) {
    MVertex *ver = it->first;
    SMetric3 hessian, metric;
    double size;
    switch(_technique) {
    case(LEVELSET): computeMetricLevelSet(ver, hessian, metric, size); break;
    case(HESSIAN): computeMetricHessian(ver, hessian, metric, size); break;
    case(FREY): computeMetricFrey(ver, hessian, metric, size); break;
    case(EIGENDIRECTIONS):
      computeMetricEigenDir(ver, hessian, metric, size);
      break;
    case(EIGENDIRECTIONS_LINEARINTERP_H):
      computeMetricEigenDir(ver, hessian, metric, size);
      break;
    case(ISOTROPIC_LINEARINTERP_H):
      computeMetricIsoLinInterp(ver, hessian, metric, size);
      break;
    }

    setOfSizes[metricNumber].insert(std::make_pair(ver, size));
    setOfMetrics[metricNumber].insert(std::make_pair(ver, metric));
  }

  if(_technique == HESSIAN) scaleMetric(_epsilon, setOfMetrics[metricNumber]);
}

double meshMetric::operator()(double x, double y, double z, GEntity *ge)
{
  if(needMetricUpdate) updateMetrics();
  if(!setOfMetrics.size()) {
    Msg::Error("No metric defined");
    return 0.;
  }
  SPoint3 xyz(x, y, z), uvw;
  double initialTol =  CTX::instance()->mesh.toleranceReferenceElement;
  CTX::instance()->mesh.toleranceReferenceElement = 1.e-4;
  MElement *e = _octree->find(x, y, z, _dim);
  CTX::instance()->mesh.toleranceReferenceElement = initialTol;
  double value = 0.;
  if(e) {
    e->xyz2uvw(xyz, uvw);
    double *val = new double[e->getNumVertices()];
    for(std::size_t i = 0; i < e->getNumVertices(); i++) {
      val[i] = _nodalSizes[e->getVertex(i)];
    }
    value = e->interpolate(val, uvw[0], uvw[1], uvw[2]);
    delete[] val;
  }
  else {
    Msg::Warning("point %g %g %g not found, looking for nearest node", x, y, z);
    double minDist = 1.e100;
    for(auto it = _nodalSizes.begin(); it != _nodalSizes.end(); it++) {
      const double dist = xyz.distance(it->first->point());
      if(dist <= minDist) {
        minDist = dist;
        value = it->second;
      }
    }
  }
  return value;
}

void meshMetric::operator()(double x, double y, double z, SMetric3 &metr,
                            GEntity *ge)
{
  if(needMetricUpdate) { updateMetrics(); }
  if(!setOfMetrics.size()) {
    Msg::Error("No metric defined");
    return;
  }
  metr = SMetric3(1.e-22);

  // RECOMPUTE MESH METRIC AT XYZ
  if(hasAnalyticalMetric) {
    int nbMetrics = setOfMetrics.size();
    std::vector<SMetric3> newSetOfMetrics(nbMetrics);
    for(int iMetric = 0; iMetric < nbMetrics; iMetric++) {
      _fct = setOfFcts[iMetric];
      _technique = (MetricComputationTechnique)setOfTechniques[iMetric];
      if(_fct->hasDerivatives()) {
        SMetric3 hessian, metric;
        double size;
        switch(_technique) {
        case(LEVELSET):
          computeMetricLevelSet(nullptr, hessian, metric, size, x, y, z);
          break;
        case(HESSIAN):
          computeMetricHessian(nullptr, hessian, metric, size, x, y, z);
          break;
        case(FREY):
          computeMetricFrey(nullptr, hessian, metric, size, x, y, z);
          break;
        case(EIGENDIRECTIONS):
          computeMetricEigenDir(nullptr, hessian, metric, size, x, y, z);
          break;
        case(EIGENDIRECTIONS_LINEARINTERP_H):
          computeMetricEigenDir(nullptr, hessian, metric, size, x, y, z);
          break;
        case(ISOTROPIC_LINEARINTERP_H):
          computeMetricIsoLinInterp(nullptr, hessian, metric, size, x, y, z);
          break;
        }
        newSetOfMetrics[iMetric] = metric;
      }
      else {
        // find other metrics here
        SMetric3 metric;
        SPoint3 xyz(x, y, z), uvw;
        double initialTol =  CTX::instance()->mesh.toleranceReferenceElement;
        CTX::instance()->mesh.toleranceReferenceElement = 1.e-4;
        MElement *e = _octree->find(x, y, z, _dim);
        CTX::instance()->mesh.toleranceReferenceElement = initialTol;
        if(e) {
          e->xyz2uvw(xyz, uvw);
          SMetric3 m1 = setOfMetrics[iMetric][e->getVertex(0)];
          SMetric3 m2 = setOfMetrics[iMetric][e->getVertex(1)];
          SMetric3 m3 = setOfMetrics[iMetric][e->getVertex(2)];
          if(_dim == 2)
            metric = interpolation(m1, m2, m3, uvw[0], uvw[1]);
          else {
            SMetric3 m4 = setOfMetrics[iMetric][e->getVertex(3)];
            metric = interpolation(m1, m2, m3, m4, uvw[0], uvw[1], uvw[2]);
          }
          newSetOfMetrics[iMetric] = metric;
        }
        else {
          Msg::Warning("point %g %g %g not found, looking for nearest node", x,
                       y, z);
        }
      }
    }
    // intersect metrics here
    metr = newSetOfMetrics[0];
    for(int i = 1; i < nbMetrics; i++)
      metr = intersection_conserve_mostaniso(metr, newSetOfMetrics[i]);
  }
  // INTERPOLATE DISCRETE MESH METRIC
  else {
    SPoint3 xyz(x, y, z), uvw;
    double initialTol =  CTX::instance()->mesh.toleranceReferenceElement;
    CTX::instance()->mesh.toleranceReferenceElement = 1.e-4;
    MElement *e = _octree->find(x, y, z, _dim);
    CTX::instance()->mesh.toleranceReferenceElement = initialTol;

    if(e) {
      e->xyz2uvw(xyz, uvw);
      SMetric3 m1 = _nodalMetrics[e->getVertex(0)];
      SMetric3 m2 = _nodalMetrics[e->getVertex(1)];
      SMetric3 m3 = _nodalMetrics[e->getVertex(2)];
      if(_dim == 2)
        metr = interpolation(m1, m2, m3, uvw[0], uvw[1]);
      else {
        SMetric3 m4 = _nodalMetrics[e->getVertex(3)];
        metr = interpolation(m1, m2, m3, m4, uvw[0], uvw[1], uvw[2]);
      }
    }
    else {
      Msg::Warning("point %g %g %g not found, looking for nearest node", x, y,
                   z);
      double minDist = 1.e100;
      for(auto it = _nodalMetrics.begin(); it != _nodalMetrics.end(); it++) {
        const double dist = xyz.distance(it->first->point());
        if(dist <= minDist) {
          minDist = dist;
          metr = it->second;
        }
      }
    }
  }
}

double meshMetric::getLaplacian(MVertex *v)
{
  MVertex *vNew = _vertexMap[v->getNum()];
  auto it = hessians.find(vNew);
  SMetric3 h = it->second;
  return h(0, 0) + h(1, 1) + h(2, 2);
}

SVector3 meshMetric::getGradient(MVertex *v)
{
  MVertex *vNew = _vertexMap[v->getNum()];
  auto it = grads.find(vNew);
  SVector3 gr = it->second;
  return gr;
}
