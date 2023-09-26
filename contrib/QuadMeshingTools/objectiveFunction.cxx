#include "objectiveFunction.hxx"
#include "gmsh.h"
#include "timer.hxx"

namespace IFF{

  std::vector<ObjectiveFunction*> ObjectiveFunction::allpFuncContainer;

  void DirichletEnergie::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("DIR_FUNC_EVALUATE_OBJ");
    valFunc = 0.0;
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u;
      u.resize(m_nFields, 0.0);
      for(size_t m=0; m<m_nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}

      std::vector<std::vector<double>> gradU;
      gradU.resize(3);
      for(size_t m=0; m<3; m++)
	gradU[m].resize(m_nFields, 0.0);
      for(size_t m=0; m<m_nFields; m++)
	for(size_t l=0; l<sf.size(); l++)
	  for(size_t d=0; d<3; d++)
	    gradU[d][m] += (*gsf)[l][d]*solTri[l][m];
    
      for(size_t m=0; m<m_nFields; m++){
	double gradGrad = 0.0;
	for(size_t d=0; d<3; d++)
	  gradGrad += gradU[d][m]*gradU[d][m];
	valFunc += 0.5*det*w*gradGrad;
      }
    }
    // GlobalTimer::toc();
  }

  void DirichletEnergie::getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){ //integrale on tri of 1/2*||grad(u)||
    // GlobalTimer::tic("DIR_FUNC_GETFEM");
    size_t nNodes = triangle->m_vertices.size();
    localMat.clear();
    localRhs.clear();

    localMat.resize(m_nFields*nNodes);
    localRhs.resize(m_nFields*nNodes, 0.0);
    for(size_t l=0; l<m_nFields*nNodes ; l++)
      localMat[l].resize(m_nFields*nNodes, 0.0);

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(xi, det);
      std::vector<std::vector<double>> gradgradT;
      gradgradT.resize(nNodes);
      for(auto &g: gradgradT)
	g.resize(nNodes, 0.0);


      for(size_t m=0; m<nNodes; m++)
	for(size_t n=0; n<nNodes; n++)
	  for(size_t l=0; l<3; l++)
	    gradgradT[m][n] += (*gsf)[m][l]*(*gsf)[n][l];

      for(size_t iF=0; iF<m_nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = m_nFields*iN + iF;
	  for(size_t jN=0; jN<nNodes; jN++){
	    size_t locIndJ = m_nFields*jN + iF;
	    localMat[locIndI][locIndJ] += gradgradT[iN][jN]*w*det;
	  }
	}
      }
    }
    // GlobalTimer::toc();
  }

  void Potential::getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, void *voidGradPotTri){ //integrale on tri of 1/2*||grad(u) - data||
    std::vector<std::vector<double>> *gradPotTri = (std::vector<std::vector<double>> *) voidGradPotTri;
    // GlobalTimer::tic("DIR_FUNC_GETFEM");
    size_t nNodes = triangle->m_vertices.size();
    localMat.clear();
    localRhs.clear();

    localMat.resize(m_nFields*nNodes);
    localRhs.resize(m_nFields*nNodes, 0.0);
    for(size_t l=0; l<m_nFields*nNodes ; l++)
      localMat[l].resize(m_nFields*nNodes, 0.0);

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(xi, det);
      std::vector<std::vector<double>> gradgradT;
      gradgradT.resize(nNodes);
      for(auto &g: gradgradT)
	g.resize(nNodes, 0.0);

      std::vector<double> gradPotGauss = triangle->interpolate(xi, *gradPotTri);
      // gradPotGauss[0] = 1.0; //DBG
      // gradPotGauss[1] = 1.0;
      // gradPotGauss[2] = 0.0;
      // std::vector<double> physicalCoord = triangle->computePhysicalCoord(xi);
      // gradPotGauss[0] = physicalCoord[0];//DBG
      // gradPotGauss[1] = -physicalCoord[1];//DBG
      // gradPotGauss[2] = physicalCoord[2];//DBG
      // gradPotGauss[1] = -1;//DBG
      // gradPotGauss[2] = 0;//DBG
    
      for(size_t m=0; m<nNodes; m++)
	for(size_t n=0; n<nNodes; n++)
	  for(size_t l=0; l<3; l++)
	    gradgradT[m][n] += (*gsf)[m][l]*(*gsf)[n][l];

      for(size_t iN=0; iN<nNodes; iN++){
	for(size_t l=0; l<3; l++)
	  localRhs[iN] += (*gsf)[iN][l]*gradPotGauss[l]*w*det;
	for(size_t jN=0; jN<nNodes; jN++){
	  localMat[iN][jN] += gradgradT[iN][jN]*w*det;
	}
      }
    }
    // GlobalTimer::toc();
  }

  void DoublePotential::getFEMOperators(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, void *voidGradPotTri){ //integrale on tri of 1/2*||grad(u) - data||
    std::vector<std::vector<double>> *gradPotTri = (std::vector<std::vector<double>> *) voidGradPotTri;
    // GlobalTimer::tic("DIR_FUNC_GETFEM");
    size_t nNodes = triangle->m_vertices.size();
    localMat.clear();
    localRhs.clear();

    localMat.resize(m_nFields*nNodes);
    localRhs.resize(m_nFields*nNodes, 0.0);
    for(size_t l=0; l<m_nFields*nNodes ; l++)
      localMat[l].resize(m_nFields*nNodes, 0.0);

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(xi, det);
      std::vector<std::vector<double>> gradgradT;
      gradgradT.resize(nNodes);
      for(auto &g: gradgradT)
	g.resize(nNodes, 0.0);

      std::vector<double> gradPotGauss = triangle->interpolate(xi, *gradPotTri);
      // gradPotGauss[0] = 1.0; //DBG
      // gradPotGauss[1] = 1.0;
      // gradPotGauss[2] = 0.0;
      // std::vector<double> physicalCoord = triangle->computePhysicalCoord(xi);
      // gradPotGauss[0] = physicalCoord[0];//DBG
      // gradPotGauss[1] = -physicalCoord[1];//DBG
      // gradPotGauss[2] = physicalCoord[2];//DBG
      // gradPotGauss[1] = -1;//DBG
      // gradPotGauss[2] = 0;//DBG
    
      for(size_t m=0; m<nNodes; m++)
	for(size_t n=0; n<nNodes; n++)
	  for(size_t l=0; l<3; l++)
	    gradgradT[m][n] += (*gsf)[m][l]*(*gsf)[n][l];
    
      for(size_t iF=0; iF<m_nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t localIndI = m_nFields*iN + iF;
	  for(size_t l=0; l<3; l++)
	    localRhs[localIndI] += (*gsf)[iN][l]*gradPotGauss[3*iF+l]*w*det;
	  size_t jF = iF;
	  for(size_t jN=0; jN<nNodes; jN++){
	    size_t localIndJ = m_nFields*jN + jF;
	    localMat[localIndI][localIndJ] += gradgradT[iN][jN]*w*det;
	  }
	}
      }
    }
    // GlobalTimer::toc();
  }

  void GLconstraintPlanar::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("GL_FUNC_EVALUATE_OBJ");
    size_t nNodes = triangle->m_vertices.size();
    int nFields = 2;
    valFunc = 0.0;
  
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0};
      for(size_t m=0; m<2; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double uSq = u[0]*u[0] + u[1]*u[1];
      valFunc += m_penalty*w*det*(uSq-1)*(uSq-1);
    }
    // GlobalTimer::toc();
  }

  void GLconstraintPlanar::getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){ //integrale on tri of penalty*||u^2 - 1||^2
    // GlobalTimer::tic("GL_FUNC_GRADFEM");
    size_t nNodes = triangle->m_vertices.size();
    localRhs.clear();
    int nFields = 2;
    localRhs.resize(nFields*nNodes, 0.0);

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0};
      for(size_t m=0; m<2; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double uSq = u[0]*u[0] + u[1]*u[1];
      std::vector<std::vector<double>> uTu;
      uTu.resize(2);
      for(size_t l=0; l<2; l++)
	uTu[l].resize(2,0.0);
      for(size_t l=0; l<2; l++)
	for(size_t m=0; m<2; m++)
	  uTu[l][m] = u[l]*u[m];
    
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  localRhs[locIndI] += m_penalty*w*det*4*(uSq-1)*u[iF]*sf[iN];
	}
      }
    }
    // GlobalTimer::toc();
  }

  void GLconstraintPlanar::getFEMHessianAndGradient(Triangle *triangle, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){ //integrale on tri of penalty*||u^2 - 1||^2
    // GlobalTimer::tic("GL_FUNC_GETFEMHESSIANANDGRAD");
    size_t nNodes = triangle->m_vertices.size();
    localMat.clear();
    localRhs.clear();

    int nFields = 2;
    localMat.resize(nFields*nNodes);
    localRhs.resize(nFields*nNodes, 0.0);
    for(size_t l=0; l<nFields*nNodes ; l++)
      localMat[l].resize(nFields*nNodes, 0.0);

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0};
      for(size_t m=0; m<2; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double uSq = u[0]*u[0] + u[1]*u[1];
      std::vector<std::vector<double>> uTu;
      uTu.resize(2);
      for(size_t l=0; l<2; l++)
	uTu[l].resize(2,0.0);
      for(size_t l=0; l<2; l++)
	for(size_t m=0; m<2; m++)
	  uTu[l][m] = u[l]*u[m];
    
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  localRhs[locIndI] += m_penalty*w*det*4*(uSq-1)*u[iF]*sf[iN];
	  for(size_t jF=0; jF<nFields; jF++){
	    for(size_t jN=0; jN<nNodes; jN++){
	      size_t locIndJ = nFields*jN + jF;
	      localMat[locIndI][locIndJ] += m_penalty*w*det*8*uTu[iF][jF]*sf[jN]*sf[iN];
	      if(iF==jF)
		localMat[locIndI][locIndJ] += m_penalty*w*det*4*(uSq-1)*sf[iN]*sf[jN];
	    }
	  }
	}
      }
    }
    // GlobalTimer::toc();
  }

  void OdecoIso2DplanarConstraint::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("ODECOISO2DPLANARCONSTRAINT_FUNC_EVALUATE_OBJ");
    size_t nNodes = triangle->m_vertices.size();
    int nFields = 3;
    valFunc = 0.0;
  
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      valFunc += m_penalty*w*det*(u[0]*u[0] - 18*u[1]*u[1] - 18*u[2]*u[2])*(u[0]*u[0] - 18*u[1]*u[1] - 18*u[2]*u[2]);
    }
    // GlobalTimer::toc();
  }

  void OdecoIso2DplanarConstraint::getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("ODECOISO2DPLANARCONSTRAINT_FUNC_GRADFEM");
    size_t nNodes = triangle->m_vertices.size();
    localRhs.clear();
    int nFields = 3;
    localRhs.resize(nFields*nNodes, 0.0);

    double valGrad[3] = {1.0, -18.0, -18.0};
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
    
      double valFunc = (u[0]*u[0] - 18*u[1]*u[1] - 18*u[2]*u[2]);
    
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  localRhs[locIndI] += m_penalty*w*det*4*valFunc*valGrad[iF]*u[iF]*sf[iN];
	}
      }
    }
    // GlobalTimer::toc();
  }

  void OdecoAniso2DplanarConstraint::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("ODECOANISO2DPLANARCONSTRAINT_FUNC_EVALUATE_OBJ");
    size_t nNodes = triangle->m_vertices.size();
    int nFields = 5;
    valFunc = 0.0;
  
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0, 0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double c1 = m_weightsC[0]*(u[0]*u[0] - 18*u[3]*u[3] - 18*u[4]*u[4]);
      double c2 = m_weightsC[1]*(sqrt(2)*u[0]*u[1] - 6*u[1]*u[3] - 6*u[2]*u[4]);
      double c3 = m_weightsC[2]*(sqrt(2)*u[0]*u[2] - 6*u[1]*u[4] + 6*u[2]*u[3]);
      valFunc += m_penalty*det*w*(c1*c1 + c2*c2 + c3*c3);
    }
    // GlobalTimer::toc();
  }

  void OdecoAniso2DplanarConstraint::getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("ODECOANISO2DPLANARCONSTRAINT_FUNC_GRADFEM");
    size_t nNodes = triangle->m_vertices.size();
    localRhs.clear();
    int nFields = 5;
    localRhs.resize(nFields*nNodes, 0.0);

    double valGrad[3] = {1.0, -18.0, -18.0};
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      double det = 0.0;
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      triangle->getGradShapeFunctions(xi, det);
      std::vector<double> u{0.0, 0.0, 0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}

      double c1 = m_weightsC[0]*(u[0]*u[0] - 18*u[3]*u[3] - 18*u[4]*u[4]);
      double c2 = m_weightsC[1]*(sqrt(2)*u[0]*u[1] - 6*u[1]*u[3] - 6*u[2]*u[4]);
      double c3 = m_weightsC[2]*(sqrt(2)*u[0]*u[2] - 6*u[1]*u[4] + 6*u[2]*u[3]);
      double valGradC1[5] = {2*u[0], 0.0, 0.0, -18.0*2*u[3], -18.0*2*u[4]};
      for(size_t l=0; l<nFields; l++)
	valGradC1[l] *= m_weightsC[0];
      double valGradC2[5] = {sqrt(2)*u[1], sqrt(2)*u[0] - 6.0*u[3], -6.0*u[4], -6.0*u[1], -6.0*u[2]};
      for(size_t l=0; l<nFields; l++)
	valGradC2[l] *= m_weightsC[1];
      double valGradC3[5] = {sqrt(2)*u[2], -6.0*u[4], sqrt(2)*u[0] + 6.0*u[3], 6.0*u[2], -6.0*u[1]};
      for(size_t l=0; l<nFields; l++)
	valGradC3[l] *= m_weightsC[2];
      double valFunc = (c1*c1 + c2*c2 + c3*c3);
    
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  localRhs[locIndI] += m_penalty*w*det*2*(c1*valGradC1[iF]*sf[iN] + c2*valGradC2[iF]*sf[iN] + c3*valGradC3[iF]*sf[iN]);
	}
      }
    }
    // GlobalTimer::toc();
  }

  void LBOdecoIso2DplanarUnnormalized::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("LBODECOISO2DPLANAR_FUNC_EVALUATE_OBJ");
    size_t nNodes = triangle->m_vertices.size();
    int nFields = 3;
    valFunc = 0.0;
    double det = 0.0;
    std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(det);
    std::vector<std::vector<double>> gradU;
    gradU.resize(nFields);
    for(size_t m=0; m<nFields; m++)
      gradU[m].resize(3, 0.0);
    for(size_t k=0; k<nNodes; k++){
      for(size_t j=0; j<3; j++)
	for(size_t m=0; m<nFields; m++)
	  gradU[m][j] += (*gsf)[k][j]*solTri[k][m];
    }
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<double> u{0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double LBx = 2.0/(3*M_PI)*u[0]*gradU[0][1] + 4/M_PI*(-u[2]*gradU[1][0] + u[1]*gradU[1][1] + u[1]*gradU[2][0] + u[2]*gradU[2][1]);
      double LBy = -2.0/(3*M_PI)*u[0]*gradU[0][0] + 4/M_PI*(-u[2]*gradU[1][1] - u[1]*gradU[1][0] + u[1]*gradU[2][1] - u[2]*gradU[2][0]);
      valFunc += det*w*(LBx*LBx + LBy*LBy);
    }
    // GlobalTimer::toc();
  }

  void LBOdecoIso2DplanarUnnormalized::getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("LBODECOISO2DPLANAR_FUNC_GRADFEM");
    size_t nNodes = triangle->m_vertices.size();
    localRhs.clear();
    int nFields = 3;
    localRhs.resize(nFields*nNodes, 0.0);

    double det = 0.0;
    std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(det);
    std::vector<std::vector<double>> gradU;
    gradU.resize(nFields);
    for(size_t m=0; m<nFields; m++)
      gradU[m].resize(3, 0.0);
    for(size_t k=0; k<nNodes; k++){
      for(size_t j=0; j<3; j++)
	for(size_t m=0; m<nFields; m++)
	  gradU[m][j] += (*gsf)[k][j]*solTri[k][m];
    }

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<double> u{0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double LBx = 2.0/(3*M_PI)*u[0]*gradU[0][1] + 4/M_PI*(-u[2]*gradU[1][0] + u[1]*gradU[1][1] + u[1]*gradU[2][0] + u[2]*gradU[2][1]);
      double LBy = -2.0/(3*M_PI)*u[0]*gradU[0][0] + 4/M_PI*(-u[2]*gradU[1][1] - u[1]*gradU[1][0] + u[1]*gradU[2][1] - u[2]*gradU[2][0]);
      double valFunc = LBx*LBx + LBy*LBy;
    
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  if(iF==0){
	    localRhs[locIndI] += w*det*2*LBx*2.0/(3*M_PI)*(sf[iN]*gradU[0][1] + u[0]*(*gsf)[iN][1]);
	  }
	  if(iF==1){
	    localRhs[locIndI] += w*det*2*LBx*4/M_PI*(-u[2]*(*gsf)[iN][0] + sf[iN]*gradU[1][1] + u[1]*(*gsf)[iN][1] + sf[iN]*gradU[2][0]);
	  }
	  if(iF==2){
	    localRhs[locIndI] += w*det*2*LBx*4/M_PI*(-sf[iN]*gradU[1][0] + u[1]*(*gsf)[iN][0] + sf[iN]*gradU[2][1] + u[2]*(*gsf)[iN][1]);
	  }
	}
      }
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  if(iF==0){
	    localRhs[locIndI] += w*det*2*LBy*2.0/(3*M_PI)*(-sf[iN]*gradU[0][0] - u[0]*(*gsf)[iN][0]);
	  }
	  if(iF==1){
	    localRhs[locIndI] += w*det*2*LBy*4/M_PI*(-u[2]*(*gsf)[iN][1] - sf[iN]*gradU[1][0] - u[1]*(*gsf)[iN][0] + sf[iN]*gradU[2][1]);
	  }
	  if(iF==2){
	    localRhs[locIndI] += w*det*2*LBy*4/M_PI*(-sf[iN]*gradU[1][1] + u[1]*(*gsf)[iN][1] - sf[iN]*gradU[2][0] - u[2]*(*gsf)[iN][0]);
	  }
	}
      }

    }
    // GlobalTimer::toc();
  }

  void LBOdecoIso2Dplanar::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("LBODECOISO2DPLANAR_FUNC_EVALUATE_OBJ");
    size_t nNodes = triangle->m_vertices.size();
    int nFields = 3;
    valFunc = 0.0;
    double det = 0.0;
    std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(det);
    std::vector<std::vector<double>> gradU;
    gradU.resize(nFields);
    for(size_t m=0; m<nFields; m++)
      gradU[m].resize(3, 0.0);
    for(size_t k=0; k<nNodes; k++){
      for(size_t j=0; j<3; j++)
	for(size_t m=0; m<nFields; m++)
	  gradU[m][j] += (*gsf)[k][j]*solTri[k][m];
    }
    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<double> u{0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double LBx = 2.0/(3*M_PI)*u[0]*gradU[0][1] + 4/M_PI*(-u[2]*gradU[1][0] + u[1]*gradU[1][1] + u[1]*gradU[2][0] + u[2]*gradU[2][1]);
      double LBy = -2.0/(3*M_PI)*u[0]*gradU[0][0] + 4/M_PI*(-u[2]*gradU[1][1] - u[1]*gradU[1][0] + u[1]*gradU[2][1] - u[2]*gradU[2][0]);
      double N = 0.25*(64.0/(9*2*M_PI)*u[0]*u[0]);
      valFunc += 0.5*det*w*(LBx*LBx + LBy*LBy)/(N*N);
    }
    // GlobalTimer::toc();
  }

  void LBOdecoIso2Dplanar::getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("LBODECOISO2DPLANAR_FUNC_GRADFEM");
    size_t nNodes = triangle->m_vertices.size();
    localRhs.clear();
    int nFields = 3;
    localRhs.resize(nFields*nNodes, 0.0);

    double det = 0.0;
    std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(det);
    std::vector<std::vector<double>> gradU;
    gradU.resize(nFields);
    for(size_t m=0; m<nFields; m++)
      gradU[m].resize(3, 0.0);
    for(size_t k=0; k<nNodes; k++){
      for(size_t j=0; j<3; j++)
	for(size_t m=0; m<nFields; m++)
	  gradU[m][j] += (*gsf)[k][j]*solTri[k][m];
    }

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<double> u{0.0, 0.0, 0.0};
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}
      double LBx = 2.0/(3*M_PI)*u[0]*gradU[0][1] + 4/M_PI*(-u[2]*gradU[1][0] + u[1]*gradU[1][1] + u[1]*gradU[2][0] + u[2]*gradU[2][1]);
      double LBy = -2.0/(3*M_PI)*u[0]*gradU[0][0] + 4/M_PI*(-u[2]*gradU[1][1] - u[1]*gradU[1][0] + u[1]*gradU[2][1] - u[2]*gradU[2][0]);
      double N = 0.25*(64.0/(9*2*M_PI)*u[0]*u[0]);
      std::vector<double> coeffsN{0.25*64.0/(9*2*M_PI)};
      double valFunc = 0.5*(LBx*LBx + LBy*LBy)/(N*N);
    
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  if(iF==0){
	    localRhs[locIndI] += w*det*LBx*2.0/(3*M_PI)*(sf[iN]*gradU[0][1] + u[0]*(*gsf)[iN][1])/(N*N);
	    localRhs[locIndI] += -2*w*det*valFunc*(2*coeffsN[iF]*u[iF]*sf[iN])/(N);
	  }
	  if(iF==1){
	    localRhs[locIndI] += w*det*LBx*4/M_PI*(-u[2]*(*gsf)[iN][0] + sf[iN]*gradU[1][1] + u[1]*(*gsf)[iN][1] + sf[iN]*gradU[2][0])/(N*N);
	  }
	  if(iF==2){
	    localRhs[locIndI] += w*det*LBx*4/M_PI*(-sf[iN]*gradU[1][0] + u[1]*(*gsf)[iN][0] + sf[iN]*gradU[2][1] + u[2]*(*gsf)[iN][1])/(N*N);
	  }
	}
      }
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  if(iF==0){
	    localRhs[locIndI] += w*det*LBy*2.0/(3*M_PI)*(-sf[iN]*gradU[0][0] - u[0]*(*gsf)[iN][0])/(N*N);
	  }
	  if(iF==1){
	    localRhs[locIndI] += w*det*LBy*4/M_PI*(-u[2]*(*gsf)[iN][1] - sf[iN]*gradU[1][0] - u[1]*(*gsf)[iN][0] + sf[iN]*gradU[2][1])/(N*N);
	  }
	  if(iF==2){
	    localRhs[locIndI] += w*det*LBy*4/M_PI*(-sf[iN]*gradU[1][1] + u[1]*(*gsf)[iN][1] - sf[iN]*gradU[2][0] - u[2]*(*gsf)[iN][0])/(N*N);
	  }
	}
      }

    }
    // GlobalTimer::toc();
  }

  void LBOdecoAniso2Dplanar::evaluateFunction(Triangle *triangle, double &valFunc, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("LBODECOANISO2DPLANAR_FUNC_EVALUATE_OBJ");
    valFunc = 0.0;
    size_t nNodes = triangle->m_vertices.size();
    int nFields = 5;

    double det = 0.0;
    std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(det);
    std::vector<std::vector<double>> gradU;
    gradU.resize(nFields);
    for(size_t m=0; m<nFields; m++)
      gradU[m].resize(3, 0.0);
    for(size_t k=0; k<nNodes; k++){
      for(size_t j=0; j<3; j++)
	for(size_t m=0; m<nFields; m++)
	  gradU[m][j] += (*gsf)[k][j]*solTri[k][m];
    }

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<double> u(nFields, 0.0);
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}

      double H0 = 0.0;
      double H1 = 0.0;
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<nFields; l++)
	  for(size_t d=0; d<3; d++){
	    H0 += m_C0[m][l][d]*u[m]*gradU[l][d];
	    H1 += m_C1[m][l][d]*u[m]*gradU[l][d];
	  }
      double N = 0.25*(64.0/(9*2*M_PI)*u[0]*u[0] - 4.0/M_PI*u[1]*u[1] - 4/M_PI*u[2]*u[2]);
      valFunc += det*w*0.5*(H0*H0 + H1*H1)/(N*N);
      // valFunc += det*w/(N*N);//DBG GRAD
    }
    // GlobalTimer::toc();
  }
  
  void LBOdecoAniso2Dplanar::getFEMGradient(Triangle *triangle, std::vector<double> &localRhs, std::vector<std::vector<double>> &solTri){
    // GlobalTimer::tic("LBODECOANISO2DPLANAR_FUNC_GRADFEM");
    size_t nNodes = triangle->m_vertices.size();
    localRhs.clear();
    int nFields = 5;
    localRhs.resize(nFields*nNodes, 0.0);

    double det = 0.0;
    std::vector<std::vector<double>> *gsf = triangle->getGradShapeFunctions(det);
    std::vector<std::vector<double>> gradU;
    gradU.resize(nFields);
    for(size_t m=0; m<nFields; m++)
      gradU[m].resize(3, 0.0);
    for(size_t k=0; k<nNodes; k++){
      for(size_t j=0; j<3; j++)
	for(size_t m=0; m<nFields; m++)
	  gradU[m][j] += (*gsf)[k][j]*solTri[k][m];
    }

    for(size_t k=0; k<m_integrationWeights.size(); k++){
      std::vector<double> localRhsIncrement(nFields*nNodes, 0.0);
      std::vector<double> xi;
      xi.insert(xi.end(), m_localIntegrationPoint.begin() + 3*k, m_localIntegrationPoint.begin() + 3*(k+1));
      double w = m_integrationWeights[k];
      std::vector<double> sf = triangle->getShapeFunctions(xi);
      std::vector<double> u(nFields, 0.0);
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<sf.size(); l++){
	  u[m] += solTri[l][m]*sf[l];
	}

      double H0 = 0.0;
      double H1 = 0.0;
      for(size_t m=0; m<nFields; m++)
	for(size_t l=0; l<nFields; l++)
	  for(size_t d=0; d<3; d++){
	    H0 += m_C0[m][l][d]*u[m]*gradU[l][d];
	    H1 += m_C1[m][l][d]*u[m]*gradU[l][d];
	  }
      double N = 0.25*(64.0/(9*2*M_PI)*u[0]*u[0] - 4.0/M_PI*u[1]*u[1] - 4/M_PI*u[2]*u[2]);
      std::vector<double> coeffsN{0.25*64.0/(9*2*M_PI), -0.25*4.0/M_PI, -0.25*4.0/M_PI};
      double valFunc = 0.5*(H0*H0 + H1*H1)/(N*N);
      // double valFunc = 1/(N*N);//DBG GRAD
      
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  for(size_t l=0; l<nFields; l++)
	    for(size_t d=0; d<3; d++){
	      double incrH0 = 0.0;
	      if(!(m_C0[iF][l][d]==0.0))
		incrH0 = m_C0[iF][l][d]*sf[iN]*gradU[l][d];
	      if(!(m_C0[l][iF][d]==0.0))
		incrH0 += m_C0[l][iF][d]*u[l]*(*gsf)[iN][d];
	      if(!(incrH0==0.0)){
		incrH0 *= H0/(N*N);
		localRhsIncrement[locIndI] += incrH0;
	      }
	      double incrH1 = 0.0;
	      if(!(m_C1[iF][l][d]==0.0))
		incrH1 = m_C1[iF][l][d]*sf[iN]*gradU[l][d];
	      if(!(m_C1[l][iF][d]==0.0))
		incrH1 += m_C1[l][iF][d]*u[l]*(*gsf)[iN][d];
	      if(!(incrH1==0.0)){
		incrH1 *= H1/(N*N);
		localRhsIncrement[locIndI] += incrH1;
	      }
	      // localRhsIncrement[locIndI] += H0*(m_C0[iF][l][d]*sf[iN]*gradU[l][d]
	      // 				     + m_C0[l][iF][d]*u[l]*(*gsf)[iN][d])/(N*N);
	      // localRhsIncrement[locIndI] += H1*(m_C1[iF][l][d]*sf[iN]*gradU[l][d]
	      // 				     + m_C1[l][iF][d]*u[l]*(*gsf)[iN][d])/(N*N);
	      // double te=0.0;
	    }
	  if(iF < 3)
	    localRhsIncrement[locIndI] += -2*valFunc*(2*coeffsN[iF]*u[iF]*sf[iN])/(N);
	}
      }
      for(size_t iF=0; iF<nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  localRhsIncrement[locIndI] *= w*det;
	}
      }
      for(size_t iF=0; iF<nFields; iF++)
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t locIndI = nFields*iN + iF;
	  localRhs[locIndI] += localRhsIncrement[locIndI];
	}
    }
    // GlobalTimer::toc();
  }

  void LBOdecoAniso2Dplanar::_create_C(){
    m_C0.resize(5);
    for(auto &vv: m_C0){
      vv.resize(5);
      for(auto &v: vv)
	v.resize(3, 0.0);
    }
    m_C1.resize(5);
    for(auto &vv: m_C1){
      vv.resize(5);
      for(auto &v: vv)
	v.resize(3, 0.0);
    }
    m_C0[2][0][0] = sqrt(2)/(2*M_PI);
    m_C0[0][0][1] = 2/(3*M_PI);
    m_C0[1][0][1] = -sqrt(2)/(2*M_PI);
    
    m_C0[2][1][0] = 1.0/(2*M_PI);
    m_C0[4][1][0] = -1.0/(M_PI);
    m_C0[0][1][1] = sqrt(2)/(2*M_PI);
    m_C0[1][1][1] = -1.0/(M_PI);
    m_C0[3][1][1] = 1.0/(M_PI);

    m_C0[0][2][0] = -sqrt(2)/(2*M_PI);
    m_C0[1][2][0] = -1.0/(2*M_PI);
    m_C0[3][2][0] = 1.0/(M_PI);
    m_C0[2][2][1] = -1.0/(M_PI);
    m_C0[4][2][1] = 1.0/(M_PI);

    m_C0[2][3][0] = -1.0/(M_PI);
    m_C0[4][3][0] = -4.0/(M_PI);
    m_C0[1][3][1] = -1.0/(M_PI);
    m_C0[3][3][1] = 4.0/(M_PI);

    m_C0[1][4][0] = 1.0/(M_PI);
    m_C0[3][4][0] = 4.0/(M_PI);
    m_C0[2][4][1] = -1.0/(M_PI);
    m_C0[4][4][1] = 4.0/(M_PI);

    m_C1[0][0][0] = -2/(3*M_PI);
    m_C1[1][0][0] = -sqrt(2)/(2*M_PI);
    m_C1[2][0][1] = -sqrt(2)/(2*M_PI);

    m_C1[0][1][0] = sqrt(2)/(2*M_PI);
    m_C1[1][1][0] = 1.0/(M_PI);
    m_C1[3][1][0] = 1.0/(M_PI);
    m_C1[2][1][1] = 1.0/(2*M_PI);
    m_C1[4][1][1] = 1.0/(M_PI);

    m_C1[2][2][0] = 1.0/(M_PI);
    m_C1[4][2][0] = 1.0/(M_PI);
    m_C1[0][2][1] = sqrt(2)/(2*M_PI);
    m_C1[1][2][1] = -1/(2*M_PI);
    m_C1[3][2][1] = -1/(M_PI);

    m_C1[1][3][0] = -1.0/(M_PI);
    m_C1[3][3][0] = -4.0/(M_PI);
    m_C1[2][3][1] = 1.0/(M_PI);
    m_C1[4][3][1] = -4.0/(M_PI);

    m_C1[2][4][0] = -1.0/(M_PI);
    m_C1[4][4][0] = -4.0/(M_PI);
    m_C1[1][4][1] = -1.0/(M_PI);
    m_C1[3][4][1] = 4.0/(M_PI);
  }
    
}
