// Gmsh - Copyright (C) 1997-2012 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#include "meshMetric.h"
#include "meshGFaceOptimize.h"
#include "Context.h"
#include "GEntity.h"
#include "GModel.h"
#include "gmshLevelset.h"
#include "MElementOctree.h"
#include "OS.h"

/*
static void increaseStencil(MVertex *v, v2t_cont &adj, std::vector<MElement*> &lt)
{
  std::set<MElement*> stencil;
  std::set<MVertex*> vs;
  stencil.insert(lt.begin(),lt.end());
  for (unsigned int i=0;i<lt.size();i++){
    for (int j=0;j<lt[i]->getNumVertices();j++){
      MVertex *v1 = lt[i]->getVertex(j);
      if (v1 != v){
        std::vector<MElement*> &lt2 = adj[v1];
        stencil.insert(lt2.begin(),lt2.end());
      }
    }
  }
  lt.clear();
  lt.insert(lt.begin(),stencil.begin(),stencil.end());
}
*/

meshMetric::meshMetric(GModel *gm)
{
  _dim  = gm->getDim();
  std::map<MElement*, MElement*> newP;
  std::map<MElement*, MElement*> newD;

  if (_dim == 2){
    for (GModel::fiter fit = gm->firstFace(); fit != gm->lastFace(); ++fit){
      for (unsigned int i=0;i<(*fit)->getNumMeshElements();i++){
        MElement *e = (*fit)->getMeshElement(i);
        MElement *copy = e->copy(_vertexMap, newP, newD);
        _elements.push_back(copy);
      }
    }
  }
  else if (_dim == 3){
    for (GModel::riter rit = gm->firstRegion(); rit != gm->lastRegion(); ++rit){
      for (unsigned int i=0;i<(*rit)->getNumMeshElements();i++){
        MElement *e = (*rit)->getMeshElement(i);
        MElement *copy = e->copy(_vertexMap, newP, newD);
        _elements.push_back(copy);
      }
    }
  }
  _octree = new MElementOctree(_elements);
  buildVertexToElement (_elements,_adj);

}

meshMetric::meshMetric(std::vector<MElement*> elements)
{
  _dim  = elements[0]->getDim();
  std::map<MElement*, MElement*> newP;
  std::map<MElement*, MElement*> newD;

  for (unsigned int i=0;i<elements.size();i++){
    MElement *e = elements[i];
    MElement *copy = e->copy(_vertexMap, newP, newD);
    _elements.push_back(copy);
  }

  _octree = new MElementOctree(_elements);
}

void meshMetric::addMetric(int technique, simpleFunction<double> *fct,
                           std::vector<double> parameters)
{
  needMetricUpdate=true;
  _fct = fct;
  hmin = parameters.size() >=3 ? parameters[1] : CTX::instance()->mesh.lcMin;
  hmax = parameters.size() >=3 ? parameters[2] : CTX::instance()->mesh.lcMax;

  _E = parameters[0];
  _E_moins = (parameters.size() >= 5) ? parameters[4] : -parameters[0];
  if (_E_moins>0.) _E_moins *= -1.;
  _epsilon = parameters[0];
  _technique =  (MetricComputationTechnique)technique;
  _Np = (parameters.size() >= 4) ? parameters[3] : 15.;

  computeMetric();
}

void meshMetric::intersectMetrics()
{
  if (!setOfMetrics.size()){
    std::cout << " meshMetric::intersectMetrics: Can't intersect metrics, no metric registered ! " << std::endl;
    return;
  }

  v2t_cont :: iterator it = _adj.begin();
  for (;it != _adj.end();it++) {
    MVertex *ver = it->first;
    _nodalMetrics[ver] = setOfMetrics[0][ver];
    //    _detMetric[ver] = setOfDetMetric[0][ver];
    _nodalSizes[ver] = setOfSizes[0][ver];
    for (unsigned int i=1;i<setOfMetrics.size();i++){
      _nodalMetrics[ver] = intersection_conserve_mostaniso(_nodalMetrics[ver],setOfMetrics[i][ver]);
      _nodalSizes[ver] = std::min(_nodalSizes[ver],setOfSizes[i][ver]);
    }
    //    _detMetric[ver] = sqrt(_nodalMetrics[ver].determinant());
  }
  needMetricUpdate=false;

}

void meshMetric::exportInfo(const char * fileendname)
{
  if (needMetricUpdate) intersectMetrics();
  std::stringstream sg,sm,sl,sh;
  sg << "meshmetric_gradients_" << fileendname;
  sm << "meshmetric_metric_" << fileendname;
  sl << "meshmetric_levelset_" << fileendname;
  sh << "meshmetric_hessian_" << fileendname;
  std::ofstream out_grad(sg.str().c_str());
  std::ofstream out_metric(sm.str().c_str());
  std::ofstream out_ls(sl.str().c_str());
  std::ofstream out_hess(sh.str().c_str());
  out_grad << "View \"ls_gradient\"{" << std::endl;
  out_metric << "View \"metric\"{" << std::endl;
  out_ls << "View \"ls\"{" << std::endl;
  out_hess << "View \"hessian\"{" << std::endl;
  std::vector<MElement*>::iterator itelem = _elements.begin();
  std::vector<MElement*>::iterator itelemen = _elements.end();
  for (;itelem!=itelemen;itelem++){
    MElement* e = *itelem;
    out_metric << "TT(";
    out_grad << "VT(";
    out_ls << "ST(";
    out_hess << "ST(";
    for ( int i = 0; i < e->getNumVertices(); i++) {
      MVertex *ver = e->getVertex(i);
      out_metric << ver->x() << "," << ver->y() << "," << ver->z();
      out_grad << ver->x() << "," << ver->y() << "," << ver->z();
      out_ls << ver->x() << "," << ver->y() << "," << ver->z();
      out_hess << ver->x() << "," << ver->y() << "," << ver->z();
      if (i!=e->getNumVertices()-1){
        out_metric << ",";
        out_grad << ",";
        out_ls << ",";
        out_hess << ",";
      }
      else{
        out_metric << "){";
        out_grad << "){";
        out_ls << "){";
	out_hess << "){";
      }
    }
    for ( int i = 0; i < e->getNumVertices(); i++) {
      MVertex *ver = e->getVertex(i);
      out_ls << vals[ver];
      SVector3 gradudx = dgrads[0][ver];
      SVector3 gradudy = dgrads[1][ver];
      SVector3 gradudz = dgrads[2][ver];
      out_hess << (gradudx(0) + gradudy(1) + gradudz(2));
      if (i == (e->getNumVertices() - 1)){
	out_ls << "};" << std::endl;
	out_hess << "};" << std::endl;
      }
      else {
	out_ls << ",";
	out_hess << ",";
      }
      for (int k=0;k<3;k++){
        out_grad << grads[ver](k);
        if ((k == 2) && (i == (e->getNumVertices() - 1))) out_grad << "};" << std::endl;
        else out_grad << ",";
        for (int l=0;l<3;l++){
          out_metric << _nodalMetrics[ver](k,l);
          if ((k == 2) && (l == 2) && (i == (e->getNumVertices() - 1))) out_metric << "};" << std::endl;
          else out_metric << ",";
        }
      }
    }
  }
  out_grad << "};" << std::endl;
  out_metric << "};" << std::endl;
  out_ls << "};" << std::endl;
  out_hess << "};" << std::endl;
  out_grad.close();
  out_metric.close();
  out_ls.close();
  out_hess.close();
}

meshMetric::~meshMetric()
{
  if (_octree) delete _octree;
  for (unsigned int i=0; i< _elements.size(); i++)
    delete _elements[i];
}

void meshMetric::computeValues()
{
  v2t_cont :: iterator it = _adj.begin();
  while (it != _adj.end()) {
    std::vector<MElement*> lt = it->second;
    MVertex *ver = it->first;
    vals[ver]= (*_fct)(ver->x(),ver->y(),ver->z());
    it++;
  }
}

// Determines set of vertices to use for least squares
std::vector<MVertex*> getLSBlob(unsigned int minNbPt, v2t_cont::iterator it, v2t_cont &adj)
{

//  static const double RADFACT = 3;
//
//  SPoint3 p0 = it->first->point();  // Vertex coordinates (center of circle)
//
//  double rad = 0.;
//  for (std::vector<MElement*>::iterator itEl = it->second.begin(); itEl != it->second.end(); itEl++)
//    rad = std::max(rad,(*itEl)->getOuterRadius());
//  rad *= RADFACT;

  std::vector<MVertex*> vv(1,it->first), bvv = vv;                                                      // Vector of vertices in blob and in boundary of blob
  do {
    std::set<MVertex*> nbvv;                                                                            // Set of vertices in new boundary
    for (std::vector<MVertex*>::iterator itBV = bvv.begin(); itBV != bvv.end(); itBV++) {               // For each boundary vertex...
      std::vector<MElement*> &adjBV = adj[*itBV];
      for (std::vector<MElement*>::iterator itBVEl = adjBV.begin(); itBVEl != adjBV.end(); itBVEl++) {
        for (int iV=0; iV<(*itBVEl)->getNumVertices(); iV++){                                           // ... look for adjacent vertices...
          MVertex *v = (*itBVEl)->getVertex(iV);
//          if ((find(vv.begin(),vv.end(),v) == vv.end()) && (p0.distance(v->point()) <= rad)) nbvv.insert(v);
          if (find(vv.begin(),vv.end(),v) == vv.end()) nbvv.insert(v);                                  // ... and add them in the new boundary if they are not already in the blob
        }
      }
    }
    if (nbvv.empty()) bvv.clear();
    else {
      bvv.assign(nbvv.begin(),nbvv.end());
      vv.insert(vv.end(),nbvv.begin(),nbvv.end());
    }
//  } while (!bvv.empty());
  } while (vv.size() < minNbPt);                                                                        // Repeat until min. number of points is reached

  return vv;

}

// Compute derivatives and second order derivatives using least squares
// 2D LS system: a_i0*x^2+a_i1*x*y+a_i2*y^2+a_i3*x+a_i4*y+a_i5=b_i
// 3D LS system: a_i0*x^2+a_i1*x*y+a_i2*x*z+a_i3*y^2+a_i4*y*z+a_i5*z^2+a_i6*x+a_i7*y+a_i8*z+a_i9=b_i
void meshMetric::computeHessian()
{
  unsigned int sysDim = (_dim == 2) ? 6 : 10;
  unsigned int minNbPtBlob = 3*sysDim;

  for (v2t_cont::iterator it = _adj.begin(); it != _adj.end(); it++) {
    MVertex *ver = it->first;
    std::vector<MVertex*> vv = getLSBlob(minNbPtBlob, it, _adj);
    fullMatrix<double> A(vv.size(),sysDim), ATA(sysDim,sysDim);
    fullVector<double> b(vv.size()), ATb(sysDim), coeffs(sysDim);
    for(unsigned int i=0; i<vv.size(); i++) {
      const double &x = vv[i]->x(), &y = vv[i]->y(), &z = vv[i]->z();
      if (_dim == 2) {
        A(i,0) = x*x; A(i,1) = x*y; A(i,2) = y*y;
        A(i,3) = x; A(i,4) = y; A(i,5) = 1.;
      }
      else {
        A(i,0) = x*x; A(i,1) = x*y; A(i,2) = x*z; A(i,3) = y*y; A(i,4) = y*z; A(i,5) = z*z;
        A(i,6) = x; A(i,7) = y; A(i,8) = z; A(i,9) = 1.;
      }
      b(i) = vals[vv[i]];
    }
    ATA.gemmWithAtranspose(A,A,1.,0.);
    A.multWithATranspose(b,1.,0.,ATb);
    ATA.luSolve(ATb,coeffs);
    const double &x = ver->x(), &y = ver->y(), &z = ver->z();
    double d2udx2, d2udy2, d2udz2, d2udxy, d2udxz, d2udyz, dudx, dudy, dudz;
    if (_dim == 2) {
      d2udx2 = 2.*coeffs(0); d2udy2 = 2.*coeffs(2); d2udz2 = 0.;
      d2udxy = coeffs(1); d2udxz = 0.; d2udyz = 0.;
      dudx = d2udx2*x+d2udxy*y+coeffs(3);
      dudy = d2udxy*x+d2udy2*y+coeffs(4);
      dudz = 0.;
    }
    else {
      d2udx2 = 2.*coeffs(0); d2udy2 = 2.*coeffs(3); d2udz2 = 2.*coeffs(5);
      d2udxy = coeffs(1); d2udxz = coeffs(2); d2udyz = coeffs(4);
      dudx = d2udx2*x+d2udxy*y+d2udxz*z+coeffs(6);
      dudy = d2udxy*x+d2udy2*y+d2udyz*z+coeffs(7);
      dudz = d2udxz*x+d2udyz*y+d2udz2*z+coeffs(8);
    }
    double duNorm = sqrt(dudx*dudx+dudy*dudy+dudz*dudz);
    if (duNorm == 0. || _technique == meshMetric::HESSIAN) duNorm = 1.;
    grads[ver] = SVector3(dudx/duNorm,dudy/duNorm,dudz/duNorm);
    dgrads[0][ver] = SVector3(d2udx2,d2udxy,d2udxz);
    dgrads[1][ver] = SVector3(d2udxy,d2udy2,d2udyz);
    dgrads[2][ver] = SVector3(d2udxz,d2udyz,d2udz2);
  }
}

void meshMetric::computeMetricLevelSet()
{
  int metricNumber = setOfMetrics.size();

  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {

    MVertex *ver = it->first;
    double signed_dist = vals[ver];
    double dist = fabs(signed_dist);

    SVector3 gradudx = dgrads[0][ver];
    SVector3 gradudy = dgrads[1][ver];
    SVector3 gradudz = dgrads[2][ver];
    SMetric3 hessian;
    hessian(0,0) = gradudx(0); hessian(0,1) = gradudx(1); hessian(0,2) = gradudx(2);
    hessian(1,0) = gradudy(0); hessian(1,1) = gradudy(1); hessian(1,2) = gradudy(2);
    hessian(2,0) = gradudz(0); hessian(2,1) = gradudz(1); hessian(2,2) = gradudz(2);

    SVector3 gr = grads[ver];
    SMetric3 H;
    double norm = gr(0)*gr(0)+gr(1)*gr(1)+gr(2)*gr(2);
    if (dist < _E && norm != 0.0){
      double h = hmin*(hmax/hmin-1)*dist/_E + hmin;
      double C = 1./(h*h) -1./(hmax*hmax);
      H(0,0) += C*gr(0)*gr(0)/norm ;
      H(1,1) += C*gr(1)*gr(1)/norm ;
      H(2,2) += C*gr(2)*gr(2)/norm ;
      H(1,0) = H(0,1) = C*gr(1)*gr(0)/norm ;
      H(2,0) = H(0,2) = C*gr(2)*gr(0)/norm ;
      H(2,1) = H(1,2) = C*gr(2)*gr(1)/norm ;
    }

    fullMatrix<double> V(3,3);
    fullVector<double> S(3);
    H.eig(V,S);

    double lambda1, lambda2, lambda3;
    lambda1 = S(0);
    lambda2 = S(1);
    lambda3 = (_dim == 3)? S(2) : 1.;

    SVector3 t1 (V(0,0),V(1,0),V(2,0));
    SVector3 t2 (V(0,1),V(1,1),V(2,1));
    SVector3 t3 (V(0,2),V(1,2),V(2,2));

    SMetric3 metric(lambda1,lambda2,lambda3,t1,t2,t3);

    _hessian[ver] = hessian;
    setOfSizes[metricNumber].insert(std::make_pair(ver, std::min(std::min(1/sqrt(lambda1),1/sqrt(lambda2)),1/sqrt(lambda3))));
    setOfMetrics[metricNumber].insert(std::make_pair(ver,metric));
    //    setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));

  }

}

void meshMetric::computeMetricHessian( )
{
  int metricNumber = setOfMetrics.size();

  double _epsilonP = 1.;
  double hminP = 1.e-12;
  double hmaxP = 1.e+12;

  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {

    MVertex *ver = it->first;

    SMetric3 H;
    SVector3 gradudx = dgrads[0][ver];
    SVector3 gradudy = dgrads[1][ver];
    SVector3 gradudz = dgrads[2][ver];
    H(0,0) = gradudx(0); H(0,1) = gradudx(1); H(0,2) = gradudx(2);
    H(1,0) = gradudy(0); H(1,1) = gradudy(1); H(1,2) = gradudy(2);
    H(2,0) = gradudz(0); H(2,1) = gradudz(1); H(2,2) = gradudz(2);

    fullMatrix<double> V(3,3);
    fullVector<double> S(3);
    H.eig(V,S);
    

    double lambda1 = std::min(std::max(fabs(S(0))/_epsilonP,1./(hmaxP*hmaxP)),1./(hminP*hminP));
    double lambda2 = std::min(std::max(fabs(S(1))/_epsilonP,1./(hmaxP*hmaxP)),1./(hminP*hminP));
    double lambda3 = (_dim == 3) ? std::min(std::max(fabs(S(2))/_epsilonP,1./(hmaxP*hmaxP)),1./(hminP*hminP)) : 1.;

    SVector3 t1 (V(0,0),V(1,0),V(2,0));
    SVector3 t2 (V(0,1),V(1,1),V(2,1));
    SVector3 t3 (V(0,2),V(1,2),V(2,2));

    SMetric3 metric(lambda1,lambda2,lambda3,t1,t2,t3);

    _hessian[ver] = H;
    setOfSizes[metricNumber].insert(std::make_pair(ver, std::min(std::min(1/sqrt(lambda1),1/sqrt(lambda2)),1/sqrt(lambda3))));
    setOfMetrics[metricNumber].insert(std::make_pair(ver,metric));
    //    setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));

  }

  scaleMetric(_epsilon, setOfMetrics[metricNumber]);

}

void meshMetric::computeMetricFrey()
{
  int metricNumber = setOfMetrics.size();

  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {

    MVertex *ver = it->first;
    double signed_dist = vals[ver];
    double dist = fabs(signed_dist);

    SVector3 gradudx = dgrads[0][ver];
    SVector3 gradudy = dgrads[1][ver];
    SVector3 gradudz = dgrads[2][ver];
    SMetric3 hessian;
    hessian(0,0) = gradudx(0); hessian(0,1) = gradudx(1); hessian(0,2) = gradudx(2);
    hessian(1,0) = gradudy(0); hessian(1,1) = gradudy(1); hessian(1,2) = gradudy(2);
    hessian(2,0) = gradudz(0); hessian(2,1) = gradudz(1); hessian(2,2) = gradudz(2);

    SVector3 gr = grads[ver];
    SMetric3 H(1./(hmax*hmax));
    double norm = gr(0)*gr(0)+gr(1)*gr(1)+gr(2)*gr(2);
    if (dist < _E && norm != 0.0){
      double h = hmin*(hmax/hmin-1.0)*dist/_E + hmin;
      double C = 1./(h*h) -1./(hmax*hmax);
      double kappa = hessian(0,0)+hessian(1,1)+hessian(2,2);
      double epsGeom = 4.0*3.14*3.14/(kappa*_Np*_Np);
      H(0,0) += C*gr(0)*gr(0)/(norm) + hessian(0,0)/epsGeom;
      H(1,1) += C*gr(1)*gr(1)/(norm) + hessian(1,1)/epsGeom;
      H(2,2) += C*gr(2)*gr(2)/(norm) + hessian(2,2)/epsGeom;
      H(1,0) = H(0,1) = C*gr(1)*gr(0)/(norm) + hessian(1,0)/epsGeom;
      H(2,0) = H(0,2) = C*gr(2)*gr(0)/(norm) + hessian(2,0)/epsGeom;
      H(2,1) = H(1,2) = C*gr(2)*gr(1)/(norm) + hessian(2,1)/epsGeom;
    }

    fullMatrix<double> V(3,3);
    fullVector<double> S(3);
    H.eig(V,S);

    double lambda1, lambda2, lambda3;
    lambda1 = S(0);
    lambda2 = S(1);
    lambda3 = (_dim == 3)? S(2) : 1.;

    if (dist < _E) {
      lambda1 = std::min(std::max(fabs(S(0))/_epsilon,1./(hmax*hmax)),1./(hmin*hmin));
      lambda2 = std::min(std::max(fabs(S(1))/_epsilon,1./(hmax*hmax)),1./(hmin*hmin));
      lambda3 = (_dim == 3) ? std::min(std::max(fabs(S(2))/_epsilon,1./(hmax*hmax)),1./(hmin*hmin)) : 1.;
    }

    SVector3 t1 (V(0,0),V(1,0),V(2,0));
    SVector3 t2 (V(0,1),V(1,1),V(2,1));
    SVector3 t3 (V(0,2),V(1,2),V(2,2));

    SMetric3 metric(lambda1,lambda2,lambda3,t1,t2,t3);

    _hessian[ver] = hessian;
    setOfSizes[metricNumber].insert(std::make_pair(ver, std::min(std::min(1/sqrt(lambda1),1/sqrt(lambda2)),1/sqrt(lambda3))));
    setOfMetrics[metricNumber].insert(std::make_pair(ver,metric));
    //    setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));

  }
}

void meshMetric::computeMetricEigenDir()
{
  int metricNumber = setOfMetrics.size();

  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {

    MVertex *ver = it->first;
    double signed_dist = vals[ver];
    double dist = fabs(signed_dist);

    SVector3 gradudx = dgrads[0][ver];
    SVector3 gradudy = dgrads[1][ver];
    SVector3 gradudz = dgrads[2][ver];
    SMetric3 hessian;
    hessian(0,0) = gradudx(0); hessian(0,1) = gradudx(1); hessian(0,2) = gradudx(2);
    hessian(1,0) = gradudy(0); hessian(1,1) = gradudy(1); hessian(1,2) = gradudy(2);
    hessian(2,0) = gradudz(0); hessian(2,1) = gradudz(1); hessian(2,2) = gradudz(2);

    const double metric_value_hmax = 1./(hmax*hmax);
    const SVector3 gVec = grads[ver];                                                             // Gradient vector
    const double norm = gVec.norm();
    SMetric3 metric;

    if (signed_dist < _E && signed_dist > _E_moins && norm != 0.0){
      const double metric_value_hmin = 1./(hmin*hmin);
      const SVector3 nVec = (1./norm)*gVec;                                                       // Unit normal vector
      double lambda_n;                                                                            // Eigenvalues of metric for normal & tangential directions
      if (_technique==meshMetric::EIGENDIRECTIONS_LINEARINTERP_H){
        const double h_dist = hmin + ((hmax-hmin)/_E)*dist;                                       // Characteristic element size in the normal direction - linear interp between hmin and hmax
        lambda_n = 1./(h_dist*h_dist);
      }
      else if(_technique==meshMetric::EIGENDIRECTIONS){
        const double maximum_distance = (signed_dist>0.) ? _E : fabs(_E_moins);                   // ... or linear interpolation between 1/h_min^2 and 1/h_max^2
        lambda_n = metric_value_hmin + ((metric_value_hmax-metric_value_hmin)/maximum_distance)*dist;
      }
      SVector3 tVec0, tVec1 = SPoint3(0.,0.,1.);                                                  // Unit tangential vectors
      double kappa0, kappa1 = 0.;                                                                 // Curvatures
      if (_dim == 2) {                                                                            // Curvature formulas: cf. R. Goldman, "Curvature formulas for implicit curves and surfaces", Computer Aided Geometric Design 22 (2005), pp. 632–658
        tVec0 = SPoint3(-nVec(1),nVec(0),0.);
        kappa0 = fabs(-gVec(1)*(-gVec(1)*hessian(0,0)+gVec(0)*hessian(0,1))+
            gVec(0)*(-gVec(1)*hessian(1,0)+gVec(0)*hessian(1,1)))/pow(norm,3);
      }
      else {
        // TODO: Implement 3D curvatures
        tVec0 = SPoint3(0.,0.,0.);
        tVec1 = SPoint3(0.,0.,0.);
        kappa0 = 0.;
        kappa1 = 0.;
      }
      const double invh_t0 = (_Np*kappa0)/6.283185307, invh_t1 = (_Np*kappa1)/6.283185307;        // Inverse of tangential size 0
      const double lambda_t0 = invh_t0*invh_t0, lambda_t1 = invh_t1*invh_t1;
      const double lambdaP_n = std::min(std::max(lambda_n,metric_value_hmax),metric_value_hmin);  // Truncate eigenvalues
      const double lambdaP_t0 = std::min(std::max(lambda_t0,metric_value_hmax),metric_value_hmin);
      const double lambdaP_t1 = (_dim == 2) ? 1. : std::min(std::max(lambda_t1,metric_value_hmax),metric_value_hmin);
      metric = SMetric3(lambdaP_n,lambdaP_t0,lambdaP_t1,nVec,tVec0,tVec1);
      const double h_n = 1./sqrt(lambdaP_n), h_t0 = 1./sqrt(lambdaP_t0), h_t1 = 1./sqrt(lambdaP_t1);
      setOfSizes[metricNumber].insert(std::make_pair(ver,std::min(std::min(h_n,h_t0),h_t1)));
    }
    else{// isotropic metric !
      SMetric3 mymetric(metric_value_hmax);
      metric = mymetric;
      setOfSizes[metricNumber].insert(std::make_pair(ver, hmax));
    }
    _hessian[ver] = hessian;
    setOfMetrics[metricNumber].insert(std::make_pair(ver,metric));
    //    setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));

  }

}

void meshMetric::computeMetricIsoLinInterp()
{
  int metricNumber = setOfMetrics.size();

  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {

    MVertex *ver = it->first;
    double signed_dist = vals[ver];
    double dist = fabs(signed_dist);

    SVector3 gr = grads[ver];
    double norm = gr.normalize();
    double h_dist = (signed_dist < _E && signed_dist > _E_moins && norm != 0.0) ? hmin + ((hmax-hmin)/_E)*dist : hmax;  // the charcteristic element size in all directions - linear interp between hmin and hmax

    double lambda = 1./h_dist/h_dist;
    SMetric3 H;
    H(0,0) = H(1,1) = lambda;
    H(2,2) = (_dim == 3)? lambda : 1.;

    _hessian[ver] = H;
    setOfSizes[metricNumber].insert(std::make_pair(ver, lambda));
    setOfMetrics[metricNumber].insert(std::make_pair(ver,H));
    //    setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(H.determinant())));

  }

}

void meshMetric::computeMetricScaledHessian()
{
  int metricNumber = setOfMetrics.size();

  std::list<double> lambda1, lambda2, lambda3;
  std::list<SVector3> t1, t2, t3;

  // Compute and store eignvalues and eigenvectors of Hessian
  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {

    MVertex *ver = it->first;

    SMetric3 H;
    SVector3 gradudx = dgrads[0][ver];
    SVector3 gradudy = dgrads[1][ver];
    SVector3 gradudz = dgrads[2][ver];
    H(0,0) = gradudx(0); H(0,1) = gradudx(1); H(0,2) = gradudx(2);
    H(1,0) = gradudy(0); H(1,1) = gradudy(1); H(1,2) = gradudy(2);
    H(2,0) = gradudz(0); H(2,1) = gradudz(1); H(2,2) = gradudz(2);

    fullMatrix<double> V(3,3);
    fullVector<double> S(3);
    H.eig(V,S);

    lambda1.push_back(fabs(S(0)));
    lambda2.push_back(fabs(S(1)));
    if (_dim == 3) lambda3.push_back(fabs(S(2)));

    t1.push_back(SVector3(V(0,0),V(1,0),V(2,0)));
    t2.push_back(SVector3(V(0,1),V(1,1),V(2,1)));
    t3.push_back(SVector3(V(0,2),V(1,2),V(2,2)));

    _hessian[ver] = H;

  }

  // Calculate scale factor based on max. eigenvalue and min. element length
  const double maxLambda1 = *std::max_element(lambda1.begin(), lambda1.end());
  const double maxLambda2 = *std::max_element(lambda2.begin(), lambda2.end());
  double maxLambda;
  if (_dim == 3) {
    const double maxLambda3 = *std::max_element(lambda3.begin(),lambda3.end());
    maxLambda = std::max(std::max(maxLambda1, maxLambda2), maxLambda3);
  }
  else maxLambda = std::max(maxLambda1, maxLambda2);
  const double factor = 1./(hmin*hmin*maxLambda);

  // Rescale metric
  const double lMinBound = 1./(hmax*hmax);
  std::list<double>::iterator itL1 = lambda1.begin(), itL2 = lambda2.begin(), itL3 = lambda3.begin();
  std::list<SVector3>::iterator itT1 = t1.begin(), itT2 = t2.begin(), itT3 = t3.begin();
  for (v2t_cont::iterator it=_adj.begin(); it!=_adj.end(); it++) {
    MVertex *ver = it->first;
    const double l1 = std::max(*itL1*factor, lMinBound);
    const double l2 = std::max(*itL2*factor, lMinBound);
    const double l3 = (_dim == 3) ? std::max(*itL3*factor, lMinBound) : 1.;
    const double lMax = (_dim == 3) ? std::max(std::max(l1, l2), l3) : std::max(l1, l2);
    SMetric3 metric(l1,l2,l3,*itT1,*itT2,*itT3);
    setOfSizes[metricNumber].insert(std::make_pair(ver, 1./sqrt(lMax)));
    setOfMetrics[metricNumber].insert(std::make_pair(ver,metric));
    //    setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));
    itL1++; itL2++; if (_dim == 3) itL3++;
    itT1++; itT2++; itT3++;
  }

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

void meshMetric::scaleMetric( int nbElementsTarget, 
			      nodalMetricTensor &nmt )
{
  // compute N
  double N = 0;
  for (unsigned int i=0;i<_elements.size();i++){
    MElement *e = _elements[i];    
    SMetric3 m1 = nmt[e->getVertex(0)];
    SMetric3 m2 = nmt[e->getVertex(1)];
    SMetric3 m3 = nmt[e->getVertex(2)];
    if (_dim == 2){
      SMetric3 m =  interpolation(m1,m2,m3,0.3333,0.3333);
      N += sqrt(m.determinant()) * e->getVolume()  * 3.0;
      //      printf("%12.5E %12.5E\n",m.determinant(),e->getVolume());
    }
    else{
      SMetric3 m4 = nmt[e->getVertex(3)];
      SMetric3 m =  interpolation(m1,m2,m3,m4,0.25,0.25,0.25);
      N += sqrt(m.determinant()) * e->getVolume() * 4.0;
    }
  }  
  double scale = pow ((double)nbElementsTarget/N,2.0/_dim);
  //  printf("%d elements --- %d element target --- %12.5E elements with the present metric\n",
  //  	 _elements.size(),nbElementsTarget,N);	 
  //  getchar();
  for (nodalMetricTensor::iterator it = nmt.begin(); it != nmt.end() ; ++it){
    if (_dim == 3){
      it->second *= scale;
    }
    else {
      it->second(0,0) *= scale;
      it->second(1,0) *= scale;
      it->second(1,1) *= scale;
    }
    SMetric3 &m = it->second;
    fullMatrix<double> V(3,3);
    fullVector<double> S(3);
    m.eig(V,S);
    S(0) = std::min(std::max(S(0),1/(hmax*hmax)),1/(hmin*hmin));
    S(1) = std::min(std::max(S(1),1/(hmax*hmax)),1/(hmin*hmin));
    if (_dim == 3)S(2) = std::min(std::max(S(2),1/(hmax*hmax)),1/(hmin*hmin));
    SVector3 t1 (V(0,0),V(1,0),V(2,0));
    SVector3 t2 (V(0,1),V(1,1),V(2,1));
    SVector3 t3 (V(0,2),V(1,2),V(2,2));
    m = SMetric3(S(0),S(1),S(2),t1,t2,t3);
  }
}

void meshMetric::computeMetric()
{
  //printf("%d elements are considered in the meshMetric \n",(int)_elements.size());

  computeValues();
  computeHessian();

  switch(_technique) {
    case (LEVELSET) : computeMetricLevelSet(); break;
    case (HESSIAN) : computeMetricHessian(); break;
    case (FREY) : computeMetricFrey(); break;
    case (EIGENDIRECTIONS) : computeMetricEigenDir(); break;
    case (EIGENDIRECTIONS_LINEARINTERP_H) : computeMetricEigenDir(); break;
    case (ISOTROPIC_LINEARINTERP_H) : computeMetricIsoLinInterp(); break;
    case (SCALED_HESSIAN) : computeMetricScaledHessian(); break;
  }

}

double meshMetric::operator() (double x, double y, double z, GEntity *ge)
{
  if (needMetricUpdate) intersectMetrics();
  if (!setOfMetrics.size()){
    std::cout  << "meshMetric::operator() : No metric defined ! " << std::endl;
    throw;
  }
  SPoint3 xyz(x,y,z), uvw;
  double initialTol = MElement::getTolerance();
  MElement::setTolerance(1.e-4);
  MElement *e = _octree->find(x, y, z, _dim);
  MElement::setTolerance(initialTol);
  if (e){
    e->xyz2uvw(xyz,uvw);
    double *val = new double [e->getNumVertices()];
    for (int i=0;i<e->getNumVertices();i++){
      val[i] = _nodalSizes[e->getVertex(i)];
    }
    double value = e->interpolate(val,uvw[0],uvw[1],uvw[2]);
    delete [] val;
    return value;
  }
  return 1.e22;
}

void meshMetric::operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge)
{
  if (needMetricUpdate) {
    intersectMetrics();
  }
  if (!setOfMetrics.size()){
    std::cout  << "meshMetric::operator() : No metric defined ! " << std::endl;
    throw;
  }
  metr = SMetric3(1.e-22);
  SPoint3 xyz(x,y,z), uvw;
  double initialTol = MElement::getTolerance();
  MElement::setTolerance(1.e-4);
  MElement *e = _octree->find(x, y, z, _dim);
  MElement::setTolerance(initialTol);

  if (e){
    e->xyz2uvw(xyz,uvw);
    SMetric3 m1 = _nodalMetrics[e->getVertex(0)];
    SMetric3 m2 = _nodalMetrics[e->getVertex(1)];
    SMetric3 m3 = _nodalMetrics[e->getVertex(2)];
    if (_dim == 2)
      metr =  interpolation(m1,m2,m3,uvw[0],uvw[1]);
    else {
      SMetric3 m4 = _nodalMetrics[e->getVertex(3)];
      metr =  interpolation(m1,m2,m3,m4,uvw[0],uvw[1],uvw[2]);
    }
  }
  else{
    Msg::Warning("point %g %g %g not found",x,y,z);
  }
}

double meshMetric::getLaplacian (MVertex *v) {
  MVertex *vNew = _vertexMap[v->getNum()];
  std::map<MVertex*, SMetric3 >::const_iterator it = _hessian.find(vNew);
  SMetric3 h = it->second;
  return h(0,0)+h(1,1)+h(2,2);
}

/*void meshMetric::curvatureContributionToMetric (){
  std::map<MVertex*,SMetric3>::iterator it = _nodalMetrics.begin();
  std::map<MVertex*,double>::iterator its = _nodalSizes.begin();
  for (; it != _nodalMetrics.end(); ++it,++its){
  MVertex *v = it->first;
  if (v->onWhat()->dim() == 0){
  double l;
  SMetric3 curvMetric = max_edge_curvature_metric((GVertex*)v->onWhat(),l);
  it->second = intersection(it->second,curvMetric);
  its->second = std::min(l,its->second);
  }
  else if (v->onWhat()->dim() == 1){
  double u,l;
  v->getParameter(0,u);
  SMetric3 curvMetric = max_edge_curvature_metric((GEdge*)v->onWhat(),u,l);
  it->second = intersection(it->second,curvMetric);
  its->second = std::min(l,its->second);
  }
  }
  }*/

/*
   void meshMetric::smoothMetric (dgDofContainer *sol){
   return;
   dgGroupCollection *groups = sol->getGroups();
   std::set<MEdge,Less_Edge> edges;
   for (int i=0;i<groups->getNbElementGroups();i++){
   dgGroupOfElements *group = groups->getElementGroup(i);
   for (int j=0;j<group->getNbElements();j++){
   MElement *e = group->getElement(j);
   for (int k=0;k<e->getNumEdges();k++){
   edges.insert(e->getEdge(k));
   }
   }
   }

   std::set<MEdge,Less_Edge>::iterator it = edges.begin();
   double logRatio = log (CTX::instance()->mesh.smoothRatio);
   for ( ; it !=edges.end(); ++it){
   MEdge e = *it;
   std::map<MVertex*,SMetric3>::iterator it1 = _nodalMetrics.find(e.getVertex(0));
   std::map<MVertex*,SMetric3>::iterator it2 = _nodalMetrics.find(e.getVertex(1));
   SVector3 aij (e.getVertex(1)->x()-e.getVertex(0)->x(),
   e.getVertex(1)->y()-e.getVertex(0)->y(),
   e.getVertex(1)->z()-e.getVertex(0)->z());
   SMetric3 m1 = it1->second;
   double al1 = sqrt(dot(aij,m1,aij));
   SMetric3 m2 = it2->second;
   double al2 = sqrt(dot(aij,m2,aij));
//    it1->second.print("m1");
//    it2->second.print("m2");
m1 *= 1./((1+logRatio*al1)*(1+logRatio*al1));
m2 *= 1./((1+logRatio*al2)*(1+logRatio*al2));
it1->second = intersection (it1->second,m2);
it2->second = intersection (it2->second,m1);
//    it1->second.print("m1 after");
//    it2->second.print("m2 after");
//    getchar();
}
}
 */

