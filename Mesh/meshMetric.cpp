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

static void increaseStencil(MVertex *v, v2t_cont &adj, std::vector<MElement*> &lt){
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

meshMetric::meshMetric(GModel *gm){
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

meshMetric::meshMetric(std::vector<MElement*> elements){
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

void meshMetric::addMetric(int technique, simpleFunction<double> *fct, std::vector<double> parameters){
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

void meshMetric::intersectMetrics(){

  if (!setOfMetrics.size()){
    std::cout << " meshMetric::intersectMetrics: Can't intersect metrics, no metric registered ! " << std::endl;
    return;
  }

  v2t_cont :: iterator it = _adj.begin();
  for (;it != _adj.end();it++) {
    MVertex *ver = it->first;
    _nodalMetrics[ver] = setOfMetrics[0][ver];
    _detMetric[ver] = setOfDetMetric[0][ver];
    _nodalSizes[ver] = setOfSizes[0][ver];
    for (unsigned int i=1;i<setOfMetrics.size();i++){
      _nodalMetrics[ver] = intersection_conserve_mostaniso(_nodalMetrics[ver],setOfMetrics[i][ver]);
      _nodalSizes[ver] = std::min(_nodalSizes[ver],setOfSizes[i][ver]);
    }
    _detMetric[ver] = sqrt(_nodalMetrics[ver].determinant());
  }
  needMetricUpdate=false;

}

void meshMetric::exportInfo(const char * fileendname){

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
      out_hess << (gradudx(0)+gradudy(1)+gradudz(2));
      if ((i==(e->getNumVertices()-1))){
	out_ls << "};" << std::endl;
	out_hess << "};" << std::endl;
      }
      else {
	out_ls << ",";
	out_hess << ",";
      }
      for (int k=0;k<3;k++){
        out_grad << grads[ver](k);
        if ((k==2)&&(i==(e->getNumVertices()-1)))  out_grad << "};" << std::endl;
        else out_grad << ",";
        for (int l=0;l<3;l++){
          out_metric << _nodalMetrics[ver](k,l);
          if ((k==2)&&(l==2)&&(i==(e->getNumVertices()-1))) out_metric << "};" << std::endl;
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


meshMetric::~meshMetric(){
  if (_octree) delete _octree;
  for (unsigned int i=0; i< _elements.size(); i++)
    delete _elements[i];
}

void meshMetric::computeValues(){

  v2t_cont :: iterator it = _adj.begin();
  while (it != _adj.end()) {
    std::vector<MElement*> lt = it->second;
    MVertex *ver = it->first;
    vals[ver]= (*_fct)(ver->x(),ver->y(),ver->z());
    it++;
  }
}

//compute derivatives and second order derivatives using linear finite elements
void meshMetric::computeHessian_FE(){

  //compute FE Gradients
  std::map<MElement*,SPoint3> gradElems;
  for ( std::vector<MElement*>::iterator ite = _elements.begin();
	ite != _elements.end(); ite++){
    MElement *e  = *ite;
    int npts;
    IntPt *GP;
    e->getIntegrationPoints(0, &npts, &GP);
    const double u = GP[0].pt[0];
    const double v = GP[0].pt[1];
    const double w = GP[0].pt[2];
    double grade[3];
    double fj[256];
    for (int k = 0; k < e->getNumVertices(); k++){
      MVertex *v = e->getVertex(k);
      fj[k] = (*_fct)(v->x(),v->y(),v->z());
    }
    e->interpolateGrad(fj, u, v, w, grade);
    SPoint3 gr(grade[0], grade[1],grade[2]);
    gradElems.insert(std::make_pair(e,gr));
  }

  //smooth element gradients at vertices
  for(v2t_cont::const_iterator itv = _adj.begin(); itv!= _adj.end(); ++itv){
    MVertex *ver = itv->first;
    std::vector<MElement*> vElems= itv->second;
    SVector3 gradv;
    for (unsigned int i=0;i<vElems.size();i++){
      MElement *e = vElems[i];    
      gradv += gradElems[e];
    }
    gradv *= (1./vElems.size());;
    double nn = norm(gradv);
    if (nn == 0.0 || _technique == meshMetric::HESSIAN) nn = 1.0;
    grads[ver] =gradv*(1./nn); 
  }

  if (_technique == meshMetric::LEVELSET) return;

  //compute FE Hessians
  std::map<MElement*,STensor3> hessElems;
  for ( std::vector<MElement*>::iterator ite = _elements.begin();
	ite != _elements.end(); ite++){
    MElement *e  = *ite;
    int npts;
    IntPt *GP;
    e->getIntegrationPoints(0, &npts, &GP);
    const double u = GP[0].pt[0];
    const double v = GP[0].pt[1];
    const double w = GP[0].pt[2];
    double gradgradx[3];
    double gradgrady[3];
    double gradgradz[3];
    double gradxj[256];
    double gradyj[256];
    double gradzj[256];
    for (int k = 0; k < e->getNumVertices(); k++){
      MVertex *v = e->getVertex(k);
      gradxj[k] = grads[v].x();
      gradyj[k] = grads[v].y();
      gradzj[k] = grads[v].z();
    }
    e->interpolateGrad(gradxj, u, v, w, gradgradx);
    e->interpolateGrad(gradyj, u, v, w, gradgrady);
    e->interpolateGrad(gradzj, u, v, w, gradgradz);
    STensor3 hess;
    hess(0,0) = gradgradx[0]; hess(0,1)= gradgrady[0]; hess(0,2) =gradgradz[0];
    hess(1,0) = gradgradx[1]; hess(1,1)= gradgrady[1]; hess(1,2) =gradgradz[1];
    hess(2,0) = gradgradx[2]; hess(2,1)= gradgradz[2]; hess(2,2) =gradgradz[2];
    hessElems.insert(std::make_pair(e,hess));
  }

  //smooth element hessians at vertices
  for(v2t_cont::const_iterator itv = _adj.begin(); itv!= _adj.end(); ++itv){
    MVertex *ver = itv->first;
    std::vector<MElement*> vElems= itv->second;
    STensor3 hessv(0.0);
    for (unsigned int i=0;i<vElems.size();i++){
      MElement *e = vElems[i];    
      hessv += hessElems[e];
    }
    hessv *= (1./vElems.size());
    dgrads[0][ver] = SVector3(hessv(0,0), hessv(0,1),hessv(0,2));
    dgrads[1][ver] = SVector3(hessv(1,0), hessv(1,1),hessv(1,2));
    dgrads[2][ver] = SVector3(hessv(2,0), hessv(2,1),hessv(2,2)); 
  }
  
}

//compute derivatives and second order derivatives using least squares
// u = a + b(x-x_0) + c(y-y_0) + d(z-z_0)
void meshMetric::computeHessian_LS( ){
  
  //double error = 0.0;

  int DIM = _dim + 1;
  for (int ITER=0;ITER<DIM;ITER++){
    v2t_cont :: iterator it = _adj.begin();
     while (it != _adj.end()) {
      std::vector<MElement*> lt = it->second;
      MVertex *ver = it->first;
      while (lt.size() < 13) increaseStencil(ver,_adj,lt);
      fullMatrix<double> A  (lt.size(),DIM);
      fullMatrix<double> AT (DIM,lt.size());
      fullMatrix<double> ATA (DIM,DIM);
      fullVector<double> b   (lt.size());
      fullVector<double> ATb (DIM);
      fullVector<double> result (DIM);
      fullMatrix<double> f (1,1);
      for(unsigned int i = 0; i < lt.size(); i++) {
        MElement *e = lt[i];
        int npts; IntPt *pts;
        SPoint3 p;
        e->getIntegrationPoints(0,&npts,&pts);
        if (ITER == 0){
          SPoint3 p;
          e->pnt(pts[0].pt[0],pts[0].pt[1],pts[0].pt[2],p);
          b(i) = (*_fct)(p.x(),p.y(),p.z());
        }
        else {
          double value = 0.0;
          for (int j=0;j<e->getNumVertices();j++){
            SVector3 gr = grads[e->getVertex(j)];
            value += gr(ITER-1);
          }
          b(i) = value/(double)e->getNumVertices();
        }
        e->pnt(pts[0].pt[0],pts[0].pt[1],pts[0].pt[2],p);
        A(i,0) = 1.0;
        A(i,1) = p.x() - ver->x();
        A(i,2) = p.y() - ver->y();
        if (_dim == 3) A(i,3) = p.z() - ver->z();
      }
      AT = A.transpose();
      AT.mult(A,ATA);
      AT.mult(b,ATb);
      ATA.luSolve(ATb,result);
      if (ITER == 0){
        double gr1 = result(1);
        double gr2 = result(2);
        double gr3 = (_dim==2) ? 0.0:result(3);
        double norm = sqrt(gr1*gr1+gr2*gr2+gr3*gr3);
        if (norm == 0.0 || _technique == meshMetric::HESSIAN) norm = 1.0;
        grads[ver] = SVector3(gr1/norm,gr2/norm,gr3/norm);
      }
      else{
        dgrads[ITER-1][ver] = SVector3(result(1),result(2),(_dim==2)?0.0:result(3));
      }
      ++it;
    }
    if (_technique == meshMetric::LEVELSET) break;
  }

}
void meshMetric::computeMetric(){

  //printf("%d elements are considered in the meshMetric \n",(int)_elements.size());

  computeValues();
  //computeHessian_FE();
  computeHessian_LS(); 
  
  int metricNumber = setOfMetrics.size();

  v2t_cont :: iterator it = _adj.begin();
  while (it != _adj.end()) {
    MVertex *ver = it->first;
    double signed_dist = vals[ver];
    double dist = fabs(signed_dist);

    SMetric3 H;
    SVector3 gradudx = dgrads[0][ver];
    SVector3 gradudy = dgrads[1][ver];
    SVector3 gradudz = dgrads[2][ver];
    SMetric3 hessian;
    hessian(0,0) = gradudx(0);
    hessian(1,1) = gradudy(1);
    hessian(2,2) = gradudz(2);
    hessian(1,0) = hessian(0,1) = 0.5 * (gradudx(1) +gradudy(0));
    hessian(2,0) = hessian(0,2) = 0.5 * (gradudx(2) +gradudz(0));
    hessian(2,1) = hessian(1,2) = 0.5 * (gradudy(2) +gradudz(1));
    if (_technique == meshMetric::HESSIAN){
      H = hessian;
    }
    else if (_technique == meshMetric::LEVELSET ){
      SVector3 gr = grads[ver];
      SMetric3 hlevelset(1./(hmax*hmax));
      double norm = gr(0)*gr(0)+gr(1)*gr(1)+gr(2)*gr(2);
      if (dist < _E && norm != 0.0){
        double h = hmin*(hmax/hmin-1)*dist/_E + hmin;
        double C = 1./(h*h) -1./(hmax*hmax);
        hlevelset(0,0) += C*gr(0)*gr(0)/norm ;
        hlevelset(1,1) += C*gr(1)*gr(1)/norm ;
        hlevelset(2,2) += C*gr(2)*gr(2)/norm ;
        hlevelset(1,0) = hlevelset(0,1) = C*gr(1)*gr(0)/norm ;
        hlevelset(2,0) = hlevelset(0,2) = C*gr(2)*gr(0)/norm ;
        hlevelset(2,1) = hlevelset(1,2) = C*gr(2)*gr(1)/norm ;
      }
      // else if (dist > _E && dist < 2.*_E  && norm != 0.0){
      // 	double hmid = (hmax-hmin)/(1.*_E)*dist+(2.*hmin-1.*hmax);
      // 	double C = 1./(hmid*hmid) -1./(hmax*hmax);
      // 	hlevelset(0,0) += C*gr(0)*gr(0)/norm ;
      // 	hlevelset(1,1) += C*gr(1)*gr(1)/norm ;
      // 	hlevelset(2,2) += C*gr(2)*gr(2)/norm ;
      // 	hlevelset(1,0) = hlevelset(0,1) = C*gr(1)*gr(0)/norm ;
      // 	hlevelset(2,0) = hlevelset(0,2) = C*gr(2)*gr(0)/norm ;
      // 	hlevelset(2,1) = hlevelset(1,2) = C*gr(2)*gr(1)/norm ;
      // }
      H = hlevelset;
    }
    //See paper Ducrot and Frey:
    //Anisotropic levelset adaptation for accurate interface capturing,
    //ijnmf, 2010
    else if (_technique == meshMetric::FREY ){
      SVector3 gr = grads[ver];
      SMetric3 hfrey(1./(hmax*hmax));
      double norm = gr(0)*gr(0)+gr(1)*gr(1)+gr(2)*gr(2);
      if (dist < _E && norm != 0.0){
        double h = hmin*(hmax/hmin-1.0)*dist/_E + hmin;
        double C = 1./(h*h) -1./(hmax*hmax);
        double kappa = hessian(0,0)+hessian(1,1)+hessian(2,2);
        double epsGeom = 4.0*3.14*3.14/(kappa*_Np*_Np);
        hfrey(0,0) += C*gr(0)*gr(0)/(norm) + hessian(0,0)/epsGeom;
        hfrey(1,1) += C*gr(1)*gr(1)/(norm) + hessian(1,1)/epsGeom;
        hfrey(2,2) += C*gr(2)*gr(2)/(norm) + hessian(2,2)/epsGeom;
        hfrey(1,0) = hfrey(0,1) = C*gr(1)*gr(0)/(norm) + hessian(1,0)/epsGeom;
        hfrey(2,0) = hfrey(0,2) = C*gr(2)*gr(0)/(norm) + hessian(2,0)/epsGeom;
        hfrey(2,1) = hfrey(1,2) = C*gr(2)*gr(1)/(norm) + hessian(2,1)/epsGeom;
      }
      H = hfrey;
    }
    else if ((_technique == meshMetric::EIGENDIRECTIONS )||(_technique == meshMetric::EIGENDIRECTIONS_LINEARINTERP_H )){
      double metric_value_hmax = 1./hmax/hmax;
      SVector3 gr = grads[ver];
      double norm = gr.normalize();
      SMetric3 metric;

      if (signed_dist < _E && signed_dist > _E_moins && norm != 0.0){
        // first, compute the eigenvectors of the hessian, for a curvature-based metric
        fullMatrix<double> eigvec_hessian(3,3);
        fullVector<double> lambda_hessian(3);
        hessian.eig(eigvec_hessian,lambda_hessian);
        std::vector<SVector3> ti;
        ti.push_back(SVector3(eigvec_hessian(0,0),eigvec_hessian(1,0),eigvec_hessian(2,0)));
        ti.push_back(SVector3(eigvec_hessian(0,1),eigvec_hessian(1,1),eigvec_hessian(2,1)));
        ti.push_back(SVector3(eigvec_hessian(0,2),eigvec_hessian(1,2),eigvec_hessian(2,2)));

        // compute the required characteristic length relative to the curvature and the distance to iso
        double maxkappa = std::max(std::max(fabs(lambda_hessian(0)),fabs(lambda_hessian(1))),fabs(lambda_hessian(2)));
        // epsilon is set such that the characteristic element size in the tangent direction is h = 2pi R_min/_Np = sqrt(1/metric_maxmax) = sqrt(epsilon/kappa_max)
        double un_sur_epsilon = maxkappa/((2.*3.14/_Np)*(2.*3.14/_Np));
        // metric curvature-based eigenvalues
        std::vector<double> eigenvals_curvature;
        eigenvals_curvature.push_back(fabs(lambda_hessian(0))*un_sur_epsilon);
        eigenvals_curvature.push_back(fabs(lambda_hessian(1))*un_sur_epsilon);
        eigenvals_curvature.push_back(fabs(lambda_hessian(2))*un_sur_epsilon);
        // metric distance-based eigenvalue, in gradient direction
        double metric_value_hmin = 1./hmin/hmin;
        double eigenval_direction;
        if (_technique==meshMetric::EIGENDIRECTIONS_LINEARINTERP_H){
          double h_dist = hmin + ((hmax-hmin)/_E)*dist;// the charcteristic element size in the normal direction - linear interp between hmin and hmax
          eigenval_direction = 1./h_dist/h_dist;
        }
        else if(_technique==meshMetric::EIGENDIRECTIONS){
          // ... or linear interpolation between 1/h_min^2 and 1/h_max^2
          double maximum_distance = (signed_dist>0.) ? _E : fabs(_E_moins);
          eigenval_direction = metric_value_hmin + ((metric_value_hmax-metric_value_hmin)/maximum_distance)*dist;
        }

        // now, consider only three eigenvectors (i.e. (grad(LS), u1, u2) with u1 and u2 orthogonal vectors in the tangent plane to the LS)
        // and imposing directly eigenvalues and directions, instead of intersecting the two metrics based on direction and curvature
        // need to find out which one of ti's is the closest to gr, to known which eigenvalue to discard...
        std::vector<double> grad_dot_ti;
        for (int i=0;i<3;i++)
          grad_dot_ti.push_back(fabs(dot(gr,ti[i])));
        std::vector<double>::iterator itbegin = grad_dot_ti.begin();
        std::vector<double>::iterator itmax = std::max_element(itbegin,grad_dot_ti.end());
        int grad_index = std::distance(itbegin,itmax);
        std::vector<int> ti_index;
        for (int i=0;i<3;i++)
          if (i!=grad_index) ti_index.push_back(i);
        // finally, creating the metric
        std::vector<double> eigenvals;
        eigenvals.push_back(std::min(std::max(eigenval_direction,metric_value_hmax),metric_value_hmin));// in gradient direction
        eigenvals.push_back(std::min(std::max(eigenvals_curvature[ti_index[0]],metric_value_hmax),metric_value_hmin));
        eigenvals.push_back(std::min(std::max(eigenvals_curvature[ti_index[1]],metric_value_hmax),metric_value_hmin));
        metric = SMetric3(eigenvals[0],eigenvals[1],eigenvals[2],gr,ti[ti_index[0]],ti[ti_index[1]]);
        setOfSizes[metricNumber].insert(std::make_pair(ver, std::min(std::min(1/sqrt(eigenvals[0]),1/sqrt(eigenvals[1])),1/sqrt(eigenvals[2]))));
      }
      else{// isotropic metric !
        SMetric3 mymetric(metric_value_hmax);
        metric = mymetric;
        setOfSizes[metricNumber].insert(std::make_pair(ver, hmax));
      }
      _hessian[ver] = hessian;
      setOfMetrics[metricNumber].insert(std::make_pair(ver,metric));
      setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));

      it++;
    }

    if (_technique != meshMetric::EIGENDIRECTIONS && _technique!=meshMetric::EIGENDIRECTIONS_LINEARINTERP_H){

      //See paper Hachem and Coupez:
      //Finite element solution to handle complex heat and fluid flows in
      //industrial furnaces using the immersed volume technique, ijnmf, 2010

      fullMatrix<double> V(3,3);
      fullVector<double> S(3);
      H.eig(V,S);

      double lambda1, lambda2, lambda3;
      lambda1 = S(0);
      lambda2 = S(1);
      lambda3 = (_dim == 3)? S(2) : 1.;

      if (_technique == meshMetric::HESSIAN || (dist < _E && _technique == meshMetric::FREY)){
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
      setOfDetMetric[metricNumber].insert(std::make_pair(ver,sqrt(metric.determinant())));

      it++;
    }
  }

  //exportInfo("EMI");
  //exit(1);

  //Adapt epsilon
  //-----------------
  // dgDofContainer dofDet(groups, 1);
  // for (int iGroup = 0; iGroup < groups->getNbElementGroups(); iGroup++){
  //     dgGroupOfElements *group = groups->getElementGroup(iGroup);
  //     fullMatrix<double> & detgroup = dofDet.getGroupProxy(group);
  //     for (int iElement = 0 ; iElement < group->getNbElements(); iElement++){
  //       MElement* e = group->getElement(iElement);
  //         for ( int i = 0; i < e->getNumVertices(); i++) {
  // 	    MVertex *ver = e->getVertex(i);
  // 	    std::map<MVertex*, double >::iterator it = _detMetric.find(ver);
  //           detgroup (i, iElement) = it->second;
  //       }
  //     }
  //   }
  // fullMatrix<double> res(1,1);
  // dgFunctionIntegrator integ(groups, dofDet.getFunction());
  // integ.compute(res);
  //fprintf("integ =%g \n", res(0,0))

  //Smoothing
  //-----------
  //smoothMetric (sol);
  //curvatureContributionToMetric();

}

double meshMetric::operator() (double x, double y, double z, GEntity *ge) {
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

void meshMetric::operator() (double x, double y, double z, SMetric3 &metr, GEntity *ge) {
  if (needMetricUpdate) intersectMetrics();
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

