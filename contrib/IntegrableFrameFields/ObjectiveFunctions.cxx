// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#include <ObjectiveFunctions.hxx>
#include <vector>
#include <GaussIntegration.h>
#include <fullMatrix.h>

namespace IFF{
  int PORDER = 1;
  std::vector<ObjectiveFunction*> ObjectiveFunction::objectiveFunctionsCollector;

  void ObjectiveFunction::checkGradient(Element *element, const std::vector<std::vector<double>> &solTri){
    double epsilon = 1e-10;
    std::vector<std::vector<double>> solTriPerturbed = solTri;
    std::vector<double> localRhs;
    getGradient(element, solTri, localRhs);
    double valFunc = 0.0;
    evaluateFunction(element, solTri, valFunc);
    for(size_t iN=0; iN<solTri.size(); iN++)
      for(size_t iF=0; iF<solTri[0].size(); iF++){
        size_t locIndI = solTri[0].size()*iN + iF;
        solTriPerturbed[iN][iF] += epsilon;
        double valPerturbed = 0.0;
        evaluateFunction(element, solTriPerturbed, valPerturbed);
        double gradFiniteDiff = (valPerturbed - valFunc)/epsilon;
        double errorGrad = sqrt((localRhs[locIndI] - gradFiniteDiff)*(localRhs[locIndI] - gradFiniteDiff));
        if(fabs(gradFiniteDiff) > 1e-10){
          errorGrad /= fabs(gradFiniteDiff);
            std::cout << "error grad: " << errorGrad << std::endl;
        }
        // std::cout << "grad: " << localRhs[locIndI] << ", gradDiff: " << gradFiniteDiff << std::endl;
        solTriPerturbed[iN][iF] -= epsilon;
      }
  }
  
  // ------------------------------- Coupled potential (2) objective function
  void DoublePotential::getFEMOperators(Element *element, const std::vector<std::vector<double>> &elementPots, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nNodes = element->getNumVertices();
    localMat.clear();
    localRhs.clear();

    localMat.resize(m_nFields*nNodes);
    localRhs.resize(m_nFields*nNodes, 0.0);
    for(size_t l=0; l<m_nFields*nNodes ; l++)
      localMat[l].resize(m_nFields*nNodes, 0.0);

    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    // std::cout << "intw:" << std::endl;
    // std::cout << intWeights << std::endl;
    // std::cout << "dets" << std::endl;
    // std::cout << dets << std::endl;

    std::vector<double> gradPotsXG = element->interpolateCR(0.5, 0.5, elementPots);
    
    for(int k=0; k<intWeights.size(); k++){
      // std::cout << "INt w " << k << std::endl;
      // std::cout << "w: " << intWeights[k] << ", det: " << dets[k] << std::endl;
      std::vector<std::vector<double>> gradSF = element->getGradSF(intPoints[k][0], intPoints[k][1], 0.0);//Only ok for order 1
      // std::cout << "gradsf: " << std::endl;
      // std::cout << gradSF << std::endl;
      double w = intWeights[k];
      double det = dets[k];


      std::vector<double> gradPotsXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], elementPots);
      // std::cout << "Elements Pots" << std::endl;
      // std::cout << elementPots << std::endl;
      // std::cout << "interpolated grad" << std::endl;
      // std::cout << gradPotsXG << std::endl;
      // exit(0);
      std::vector<std::vector<double>> gradgradT(nNodes);
      for(auto &v: gradgradT)
        v.resize(nNodes, 0.0);
      for(size_t m=0; m<nNodes; m++)
	for(size_t n=0; n<nNodes; n++)
	  for(size_t l=0; l<3; l++)
	    gradgradT[m][n] += gradSF[m][l]*gradSF[n][l];

      for(size_t iF=0; iF<m_nFields; iF++){
	for(size_t iN=0; iN<nNodes; iN++){
	  size_t localIndI = m_nFields*iN + iF;
	  for(size_t l=0; l<3; l++)
	    localRhs[localIndI] += gradSF[iN][l]*gradPotsXG[3*iF+l]*w*det;
	  size_t jF = iF;
	  for(size_t jN=0; jN<nNodes; jN++){
	    size_t localIndJ = m_nFields*jN + jF;
	    localMat[localIndI][localIndJ] += gradgradT[iN][jN]*w*det;
	  }
	}
      }
    }
    // exit(0);
    // std::cout << "local mat: " <<std::endl;
    // std::cout << localMat << std::endl;
  }
  
  // ------------------------------- Dirichlet energy for CR GL framefield objective function
  void DirichletEnergieVectCR::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
      
    for(int k=0; k<intWeights.size(); k++){
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++){
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++){
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;
          }
        }
      
      double valXG = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valXG += 0.5*tools::norm2(gradSolG[jField]);

      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void DirichletEnergieVectCR::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTriRotated, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();
    localRhs.resize(m_nFields*nEdges, 0.0);
    
    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);
    
    for(int k=0; k<intWeights.size(); k++){
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          for(size_t iX=0; iX<3; iX++)
            localRhs[locIndJ] += intWeights[k]*dets[k]*CRGradSF[k][jEdg][iX]*gradSolG[jField][iX];
        }
    }
  }
  
  void DirichletEnergieVectCR::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();
    
    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  void DirichletEnergieVectCR::_getRotatedFEMOperators(Element *element, std::vector<std::vector<double>> &localMat, std::vector<double> &localRhs){ //integrale on elem of 1/2*||grad(u)||
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();
    localMat.clear();
    localRhs.clear();

    localMat.resize(m_nFields*nEdges);
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(size_t l=0; l<m_nFields*nEdges ; l++)
      localMat[l].resize(m_nFields*nEdges, 0.0);

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);
    
    for(size_t k=0; k<intWeights.size(); k++){
      double w = intWeights[k];
      double det = dets[k];

      std::vector<std::vector<double>> gradgradT;
      gradgradT.resize(nEdges);
      for(auto &v: gradgradT)
        v.resize(nEdges, 0.0);
      
      for(size_t m=0; m<nEdges; m++)
	for(size_t n=0; n<nEdges; n++)
	  for(size_t l=0; l<3; l++)
	    gradgradT[m][n] += CRGradSF[k][m][l]*CRGradSF[k][n][l];

      for(size_t iF=0; iF<m_nFields; iF++){
	for(size_t iN=0; iN<nEdges; iN++){
	  size_t locIndI = m_nFields*iN + iF;
	  for(size_t jN=0; jN<nEdges; jN++){
	    size_t locIndJ = m_nFields*jN + iF;
	    localMat[locIndI][locIndJ] += gradgradT[iN][jN]*w*det;
	  }
	}
      }
    }
  }

  void DirichletEnergieVectCR::getHessianAndGradient(Element *element, const std::vector<std::vector<double>> &solEl, std::vector<std::vector<double>> &localHess, std::vector<double> &localRhs){ // TODO seems there is a bug. gradient we get do not correspond to gradient from getGradient...
    std::vector<double> localRhsRotated;
    std::vector<std::vector<double>> localHessRotated;

    _getRotatedFEMOperators(element, localHessRotated, localRhsRotated);
    if(_getInvertRotatedHessianAndGradient){
      _getInvertRotatedHessianAndGradient(element, localHessRotated, localRhsRotated, localHess, localRhs);
      std::vector<double> solOrdered;
      solOrdered.resize(element->getNumEdges() * m_nFields, 0.0);
      for(size_t k=0; k<element->getNumEdges(); k++)
        for(size_t l=0; l<m_nFields; l++){
          size_t locIndexKL = m_nFields*k + l;
          solOrdered[locIndexKL] = solEl[k][l];
        }
      std::vector<double> KU;
      KU.resize(element->getNumEdges() * m_nFields, 0.0);
      for(size_t k=0; k<localHess.size(); k++){
        for(size_t l=0; l<localHess[k].size(); l++){
          KU[k] += localHess[k][l]*solOrdered[l];
        }
      }
      for(size_t l=0; l<localRhs.size(); l++)
        localRhs[l] = KU[l] - localRhs[l];
    }
    else{
      std::cout << "DirichletEnergieVectCR: _getInvertRotatedHessianAndGradient not provided at instanciation" << std::endl;
      exit(0);
    }
  }
  
  // ------------------------------- Dirichlet energy for CR GL framefield objective function iso frame normalized
  void DirichletEnergieVectCRIsoMormalized::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
      
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++){
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++){
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;
          }
        }
      
      double valXG = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valXG += 0.5*tools::norm2(gradSolG[jField]);
      
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      valXG /= (N);
      
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void DirichletEnergieVectCRIsoMormalized::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTriRotated, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();
    localRhs.resize(m_nFields*nEdges, 0.0);
    
    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);
    
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      double coefN = 0.25*64.0/(9*2*M_PI);
      
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;

      double valFunc = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valFunc += 0.5*tools::norm2(gradSolG[jField]);
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          for(size_t iX=0; iX<3; iX++)
            localRhs[locIndJ] += intWeights[k]*dets[k]*CRGradSF[k][jEdg][iX]*gradSolG[jField][iX]/(N);
          if(jField == 0){
            localRhs[locIndJ] += -1.0*coefN*2.0*solXG[jField]*CRsf[k][jEdg]*intWeights[k]*dets[k]*valFunc/(N*N);
          }
        }
    }
  }
  
  void DirichletEnergieVectCRIsoMormalized::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();
    
    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco isotrope 2D framefield constraint
  void OdecoIso2DConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double valXG = m_penalty*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2])*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void OdecoIso2DConstraint::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    double valGrad[3] = {1.0, -18.0, -18.0};
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double valFunc = (solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg];
        }
    }
  }

  void OdecoIso2DConstraint::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized
  void OdecoIso2DConstraintNormalized::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double valXG = m_penalty*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2])*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]); //DBG investigation
      valXG /= (N*N);
      // double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]) + 0.01; //DBG investigation
      // valXG /= (N*N*N*N);
      //
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void OdecoIso2DConstraintNormalized::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    double valGrad[3] = {1.0, -18.0, -18.0};
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double valFunc = (solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]); //DBG investigation
      // double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]) + 0.01; //DBG investigation
      double coefN = 0.25*64.0/(9*2*M_PI);
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N);
          // localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N*N*N);
          if(jField == 0){
            localRhs[locIndJ] += -2.0*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N*N);
            // localRhs[locIndJ] += -4.0*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N*N*N*N);
          }
        }
    }
  }

  void OdecoIso2DConstraintNormalized::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }
  
  // ------------------------------- Odeco isotrope 2D framefield constraint normalized no area
  void OdecoIso2DConstraintNormalizedNoArea::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double valXG = m_penalty*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2])*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]); //DBG investigation
      valXG /= (N*N);
      // double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]) + 0.01; //DBG investigation
      // valXG /= (N*N*N*N);
      //
      valFunc += valXG*intWeights[k]*dets[k]/element->getArea();
    }
  }

  void OdecoIso2DConstraintNormalizedNoArea::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    double valGrad[3] = {1.0, -18.0, -18.0};
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double valFunc = (solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]); //DBG investigation
      // double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]) + 0.01; //DBG investigation
      double coefN = 0.25*64.0/(9*2*M_PI);
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]/element->getArea()*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N);
          // localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N*N*N);
          if(jField == 0){
            localRhs[locIndJ] += -2.0*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]/element->getArea()*valFunc*valFunc/(N*N*N);
            // localRhs[locIndJ] += -4.0*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N*N*N*N);
          }
        }
    }
  }

  void OdecoIso2DConstraintNormalizedNoArea::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized with log smoothness weight
  void OdecoIso2DConstraintNormalizedWithLogSmoothWeight::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);
    
    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++){
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++){
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;
          }
        }
      
      double valXG = m_penalty*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2])*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      valXG /= (N*N);

      double valWeight = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valWeight += 0.5*tools::norm2(gradSolG[jField]);
      // valWeight = log(1.0+valWeight/N)/log(2);
      valWeight = log(1.0+valWeight/N)/log(2);
      
      // valFunc += valXG*intWeights[k]*0.5;
      valFunc += valWeight*valXG*intWeights[k]*dets[k];
      // valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void OdecoIso2DConstraintNormalizedWithLogSmoothWeight::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);

    double valGrad[3] = {1.0, -18.0, -18.0};
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTri[iEdg][jField] ;
      
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double valFunc = (solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);

      double valWeightGrad = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valWeightGrad += 0.5*tools::norm2(gradSolG[jField]);
      double valWeight = log(1.0+valWeightGrad/N)/log(2);
      
      double coefN = 0.25*64.0/(9*2*M_PI);
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          // localRhs[locIndJ] += m_penalty*intWeights[k]*0.5*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N);
          localRhs[locIndJ] += m_penalty*(valWeight)*intWeights[k]*dets[k]*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N);
          for(size_t iX=0; iX<3; iX++)
            localRhs[locIndJ] += m_penalty*(1.0/(1.0+valWeightGrad/N))/log(2)*(CRGradSF[k][jEdg][iX]*gradSolG[jField][iX]/N)*intWeights[k]*dets[k]*valFunc*valFunc/(N*N);
          // if(jField == 0){
          //   localRhs[locIndJ] += -1.0*m_penalty*coefN*2.0*solXG[jField]*CRsf[k][jEdg]*intWeights[k]*dets[k]*(valWeight/(N*N))*valFunc*valFunc/(N*N);
          // }
          if(jField == 0){
            // localRhs[locIndJ] += -2.0*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*0.5*valFunc*valFunc/(N*N*N);
            localRhs[locIndJ] += -2.0*(valWeight)*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N*N);
            localRhs[locIndJ] += -(1.0/(1.0+valWeightGrad/N)/log(2))*valWeightGrad/(N*N)*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N);
          }
        }
    }
  }

  void OdecoIso2DConstraintNormalizedWithLogSmoothWeight::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized with smoothness weight
  void OdecoIso2DConstraintNormalizedWithSmoothWeight::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);
    
    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++){
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++){
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;
          }
        }
      
      double valXG = m_penalty*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2])*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      valXG /= (N*N);

      double valWeight = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valWeight += 0.5*tools::norm2(gradSolG[jField]);
      valWeight = valWeight/N*element->getArea();
      
      valFunc += valWeight*valXG*intWeights[k]*dets[k];
    }
  }

  void OdecoIso2DConstraintNormalizedWithSmoothWeight::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);

    double valGrad[3] = {1.0, -18.0, -18.0};
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTri[iEdg][jField] ;
      
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double valFunc = (solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);

      double valWeightGrad = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valWeightGrad += 0.5*tools::norm2(gradSolG[jField]);
      double valWeight = valWeightGrad/N*element->getArea();
      
      double coefN = 0.25*64.0/(9*2*M_PI);
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          // localRhs[locIndJ] += m_penalty*intWeights[k]*0.5*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N);
          localRhs[locIndJ] += m_penalty*(valWeight)*intWeights[k]*dets[k]*4*valFunc*valGrad[jField]*solXG[jField]*CRsf[k][jEdg]/(N*N);
          for(size_t iX=0; iX<3; iX++)
            localRhs[locIndJ] += m_penalty*(CRGradSF[k][jEdg][iX]*gradSolG[jField][iX]/N*element->getArea())*intWeights[k]*dets[k]*valFunc*valFunc/(N*N);
          // if(jField == 0){
          //   localRhs[locIndJ] += -1.0*m_penalty*coefN*2.0*solXG[jField]*CRsf[k][jEdg]*intWeights[k]*dets[k]*(valWeight/(N*N))*valFunc*valFunc/(N*N);
          // }
          if(jField == 0){
            // localRhs[locIndJ] += -2.0*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*0.5*valFunc*valFunc/(N*N*N);
            localRhs[locIndJ] += -2.0*(valWeight)*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N*N);
            localRhs[locIndJ] += -valWeightGrad/(N*N)*element->getArea()*coefN*2*solXG[jField]*CRsf[k][jEdg]*m_penalty*intWeights[k]*dets[k]*valFunc*valFunc/(N*N);
          }
        }
    }
  }

  void OdecoIso2DConstraintNormalizedWithSmoothWeight::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco isotrope 2D framefield constraint normalized at edges
  void OdecoIso2DConstraintNormalizedEdge::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<element->getNumEdges(); k++){
      std::vector<double> solXG = solTriRotated[k];
      double valXG = m_penalty*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2])*(solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      valXG /= (N*N);
      valFunc += valXG*1.0/3.0*element->getArea();
    }
  }

  void OdecoIso2DConstraintNormalizedEdge::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    double valGrad[3] = {1.0, -18.0, -18.0};
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<element->getNumEdges(); k++){
      std::vector<double> solXG = solTri[k];
      double valFunc = (solXG[0]*solXG[0] - 18*solXG[1]*solXG[1] - 18*solXG[2]*solXG[2]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      double coefN = 0.25*64.0/(9*2*M_PI);
      
      for(size_t jField=0; jField<m_nFields; jField++){
        // for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t jEdg = k;
        size_t locIndJ = m_nFields*jEdg + jField;
        localRhs[locIndJ] += m_penalty*1.0/3.0*element->getArea()*4*valFunc*valGrad[jField]*solXG[jField]/(N*N);
        if(jField == 0){
          localRhs[locIndJ] += -2.0*coefN*2*solXG[jField]*m_penalty*1.0/3.0*element->getArea()*valFunc*valFunc/(N*N*N);
        }
        // }
      }
    }
  }

  void OdecoIso2DConstraintNormalizedEdge::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco anisotrope 2D framefield constraint
  void OdecoAniso2DConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double c1 = m_weightsC[0]*(solXG[0]*solXG[0] - 18*solXG[3]*solXG[3] - 18*solXG[4]*solXG[4]);
      double c2 = m_weightsC[1]*(sqrt(2)*solXG[0]*solXG[1] - 6*solXG[1]*solXG[3] - 6*solXG[2]*solXG[4]);
      double c3 = m_weightsC[2]*(sqrt(2)*solXG[0]*solXG[2] - 6*solXG[1]*solXG[4] + 6*solXG[2]*solXG[3]);
      double valXG = m_penalty*(c1*c1 + c2*c2 + c3*c3);
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void OdecoAniso2DConstraint::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);

      double c1 = m_weightsC[0]*(solXG[0]*solXG[0] - 18*solXG[3]*solXG[3] - 18*solXG[4]*solXG[4]);
      double c2 = m_weightsC[1]*(sqrt(2)*solXG[0]*solXG[1] - 6*solXG[1]*solXG[3] - 6*solXG[2]*solXG[4]);
      double c3 = m_weightsC[2]*(sqrt(2)*solXG[0]*solXG[2] - 6*solXG[1]*solXG[4] + 6*solXG[2]*solXG[3]);
      double valGradC1[5] = {2*solXG[0], 0.0, 0.0, -18.0*2*solXG[3], -18.0*2*solXG[4]};
      for(size_t l=0; l<m_nFields; l++)
	valGradC1[l] *= m_weightsC[0];
      double valGradC2[5] = {sqrt(2)*solXG[1], sqrt(2)*solXG[0] - 6.0*solXG[3], -6.0*solXG[4], -6.0*solXG[1], -6.0*solXG[2]};
      for(size_t l=0; l<m_nFields; l++)
	valGradC2[l] *= m_weightsC[1];
      double valGradC3[5] = {sqrt(2)*solXG[2], -6.0*solXG[4], sqrt(2)*solXG[0] + 6.0*solXG[3], 6.0*solXG[2], -6.0*solXG[1]};
      for(size_t l=0; l<m_nFields; l++)
	valGradC3[l] *= m_weightsC[2];
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*2*(c1*valGradC1[jField]*CRsf[k][jEdg] + c2*valGradC2[jField]*CRsf[k][jEdg] + c3*valGradC3[jField]*CRsf[k][jEdg]);
        }
    }
  }

  void OdecoAniso2DConstraint::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco anisotrope 2D framefield constraint normalized
  void OdecoAniso2DConstraintNormalized::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double c1 = m_weightsC[0]*(solXG[0]*solXG[0] - 18*solXG[3]*solXG[3] - 18*solXG[4]*solXG[4]);
      double c2 = m_weightsC[1]*(sqrt(2)*solXG[0]*solXG[1] - 6*solXG[1]*solXG[3] - 6*solXG[2]*solXG[4]);
      double c3 = m_weightsC[2]*(sqrt(2)*solXG[0]*solXG[2] - 6*solXG[1]*solXG[4] + 6*solXG[2]*solXG[3]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0] - 4.0/M_PI*solXG[1]*solXG[1] - 4/M_PI*solXG[2]*solXG[2]);
      double valXG = m_penalty*(c1*c1 + c2*c2 + c3*c3);
      valXG /= (N*N);
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void OdecoAniso2DConstraintNormalized::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0] - 4.0/M_PI*solXG[1]*solXG[1] - 4/M_PI*solXG[2]*solXG[2]);
      std::vector<double> coefsN{0.25*64.0/(9*2*M_PI), -0.25*4.0/M_PI, -0.25*4.0/M_PI};
      
      double c1 = m_weightsC[0]*(solXG[0]*solXG[0] - 18*solXG[3]*solXG[3] - 18*solXG[4]*solXG[4]);
      double c2 = m_weightsC[1]*(sqrt(2)*solXG[0]*solXG[1] - 6*solXG[1]*solXG[3] - 6*solXG[2]*solXG[4]);
      double c3 = m_weightsC[2]*(sqrt(2)*solXG[0]*solXG[2] - 6*solXG[1]*solXG[4] + 6*solXG[2]*solXG[3]);
      double valXG = m_penalty*(c1*c1 + c2*c2 + c3*c3);

      double valGradC1[5] = {2*solXG[0], 0.0, 0.0, -18.0*2*solXG[3], -18.0*2*solXG[4]};
      for(size_t l=0; l<m_nFields; l++)
	valGradC1[l] *= m_weightsC[0];
      double valGradC2[5] = {sqrt(2)*solXG[1], sqrt(2)*solXG[0] - 6.0*solXG[3], -6.0*solXG[4], -6.0*solXG[1], -6.0*solXG[2]};
      for(size_t l=0; l<m_nFields; l++)
	valGradC2[l] *= m_weightsC[1];
      double valGradC3[5] = {sqrt(2)*solXG[2], -6.0*solXG[4], sqrt(2)*solXG[0] + 6.0*solXG[3], 6.0*solXG[2], -6.0*solXG[1]};
      for(size_t l=0; l<m_nFields; l++)
	valGradC3[l] *= m_weightsC[2];
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*2*(c1*valGradC1[jField]*CRsf[k][jEdg] + c2*valGradC2[jField]*CRsf[k][jEdg] + c3*valGradC3[jField]*CRsf[k][jEdg])/(N*N);
          if(jField < 3)
            localRhs[locIndJ] += -2*coefsN[jField]*2*CRsf[k][jEdg]*solXG[jField]*intWeights[k]*dets[k]*valXG/(N*N*N);
                    
        }
    }
  }

  void OdecoAniso2DConstraintNormalized::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Integrability objective function for Odeco isotrope 2D framefield representation
  void LBOdecoIso2D::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);

    std::vector<double> vRef = element->getDirEdg(0);
    std::vector<double> n = element->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      std::vector<std::vector<double>> gradSolGGlob;
      gradSolGGlob.resize(m_nFields);
      for(std::vector<double> &v: gradSolGGlob)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolGGlob[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;

      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(size_t l=0; l<gradSolG.size(); l++)
        gradSolG[l] = tools::getVectInNewBase(vRef, t, n, gradSolGGlob[l]);
      
      double LBx = 2.0/(3*M_PI)*solXG[0]*gradSolG[0][1] + 4/M_PI*(-solXG[2]*gradSolG[1][0] + solXG[1]*gradSolG[1][1] + solXG[1]*gradSolG[2][0] + solXG[2]*gradSolG[2][1]);
      double LBy = -2.0/(3*M_PI)*solXG[0]*gradSolG[0][0] + 4/M_PI*(-solXG[2]*gradSolG[1][1] - solXG[1]*gradSolG[1][0] + solXG[1]*gradSolG[2][1] - solXG[2]*gradSolG[2][0]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);

      double valXG = m_penalty*0.5*(LBx*LBx + LBy*LBy)/(N*N);
      valFunc += valXG*intWeights[k]*dets[k];//DBG equilibrium
      // valFunc += valXG*intWeights[k];
    }
  }

  void LBOdecoIso2D::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTriRotated, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSFGlob = element->getCRGradSF(pOrder);

    std::vector<double> vRef = element->getDirEdg(0);
    std::vector<double> n = element->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);

    std::vector<std::vector<std::vector<double>>> CRGradSF;
    CRGradSF.resize(CRGradSFGlob.size());
    for(size_t l=0; l<CRGradSFGlob.size(); l++)
      CRGradSF[l].resize(CRGradSFGlob[l].size());
    
    for(size_t l=0; l<CRGradSFGlob.size(); l++)
      for(size_t m=0; m<CRGradSFGlob[l].size(); m++)
      CRGradSF[l][m] = tools::getVectInNewBase(vRef, t, n, CRGradSFGlob[l][m]);
    
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      std::vector<std::vector<double>> gradSolGGlob;
      gradSolGGlob.resize(m_nFields);
      for(std::vector<double> &v: gradSolGGlob)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolGGlob[jField][jX] += CRGradSFGlob[k][iEdg][jX] * solTriRotated[iEdg][jField];

      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(size_t l=0; l<gradSolG.size(); l++)
        gradSolG[l] = tools::getVectInNewBase(vRef, t, n, gradSolGGlob[l]);
      
      double LBx = 2.0/(3*M_PI)*solXG[0]*gradSolG[0][1] + 4/M_PI*(-solXG[2]*gradSolG[1][0] + solXG[1]*gradSolG[1][1] + solXG[1]*gradSolG[2][0] + solXG[2]*gradSolG[2][1]);
      double LBy = -2.0/(3*M_PI)*solXG[0]*gradSolG[0][0] + 4/M_PI*(-solXG[2]*gradSolG[1][1] - solXG[1]*gradSolG[1][0] + solXG[1]*gradSolG[2][1] - solXG[2]*gradSolG[2][0]);
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0]);
      std::vector<double> coeffsN{0.25*64.0/(9*2*M_PI)};
      double valFunc = 0.5*(LBx*LBx + LBy*LBy)/(N*N);

      for(size_t iF=0; iF<m_nFields; iF++){
        for(size_t iN=0; iN<nEdges; iN++){
          size_t locIndI = m_nFields*iN + iF;
          if(iF==0){
            localRhs[locIndI] += m_penalty*intWeights[k]*dets[k]*LBx*2.0/(3*M_PI)*(CRsf[k][iN]*gradSolG[0][1] + solXG[0]*CRGradSF[k][iN][1])/(N*N);
            localRhs[locIndI] += -m_penalty*intWeights[k]*dets[k]*2*valFunc*(2*coeffsN[iF]*solXG[iF]*CRsf[k][iN])/(N);
          }
          if(iF==1){
            localRhs[locIndI] += m_penalty*intWeights[k]*dets[k]*LBx*4/M_PI*(-solXG[2]*CRGradSF[k][iN][0] + CRsf[k][iN]*gradSolG[1][1] + solXG[1]*CRGradSF[k][iN][1] + CRsf[k][iN]*gradSolG[2][0])/(N*N);
          }
          if(iF==2){
            localRhs[locIndI] += m_penalty*intWeights[k]*dets[k]*LBx*4/M_PI*(-CRsf[k][iN]*gradSolG[1][0] + solXG[1]*CRGradSF[k][iN][0] + CRsf[k][iN]*gradSolG[2][1] + solXG[2]*CRGradSF[k][iN][1])/(N*N);
          }
        }
      }
      for(size_t iF=0; iF<m_nFields; iF++){
        for(size_t iN=0; iN<nEdges; iN++){
          size_t locIndI = m_nFields*iN + iF;
          if(iF==0){
            localRhs[locIndI] += m_penalty*intWeights[k]*dets[k]*LBy*2.0/(3*M_PI)*(-CRsf[k][iN]*gradSolG[0][0] - solXG[0]*CRGradSF[k][iN][0])/(N*N);
          }
          if(iF==1){
            localRhs[locIndI] += m_penalty*intWeights[k]*dets[k]*LBy*4/M_PI*(-solXG[2]*CRGradSF[k][iN][1] - CRsf[k][iN]*gradSolG[1][0] - solXG[1]*CRGradSF[k][iN][0] + CRsf[k][iN]*gradSolG[2][1])/(N*N);
          }
          if(iF==2){
            localRhs[locIndI] += m_penalty*intWeights[k]*dets[k]*LBy*4/M_PI*(-CRsf[k][iN]*gradSolG[1][1] + solXG[1]*CRGradSF[k][iN][1] - CRsf[k][iN]*gradSolG[2][0] - solXG[2]*CRGradSF[k][iN][0])/(N*N);
          }
        }
      }
      // for(size_t iF=0; iF<m_nFields; iF++){//DBG equilibrium
      //   for(size_t iN=0; iN<nEdges; iN++){
      //     size_t locIndI = m_nFields*iN + iF;
      //     if(iF==0){
      //       localRhs[locIndI] += m_penalty*intWeights[k]*LBx*2.0/(3*M_PI)*(CRsf[k][iN]*gradSolG[0][1] + solXG[0]*CRGradSF[k][iN][1])/(N*N);
      //       localRhs[locIndI] += -m_penalty*intWeights[k]*2*valFunc*(2*coeffsN[iF]*solXG[iF]*CRsf[k][iN])/(N);
      //     }
      //     if(iF==1){
      //       localRhs[locIndI] += m_penalty*intWeights[k]*LBx*4/M_PI*(-solXG[2]*CRGradSF[k][iN][0] + CRsf[k][iN]*gradSolG[1][1] + solXG[1]*CRGradSF[k][iN][1] + CRsf[k][iN]*gradSolG[2][0])/(N*N);
      //     }
      //     if(iF==2){
      //       localRhs[locIndI] += m_penalty*intWeights[k]*LBx*4/M_PI*(-CRsf[k][iN]*gradSolG[1][0] + solXG[1]*CRGradSF[k][iN][0] + CRsf[k][iN]*gradSolG[2][1] + solXG[2]*CRGradSF[k][iN][1])/(N*N);
      //     }
      //   }
      // }
      // for(size_t iF=0; iF<m_nFields; iF++){
      //   for(size_t iN=0; iN<nEdges; iN++){
      //     size_t locIndI = m_nFields*iN + iF;
      //     if(iF==0){
      //       localRhs[locIndI] += m_penalty*intWeights[k]*LBy*2.0/(3*M_PI)*(-CRsf[k][iN]*gradSolG[0][0] - solXG[0]*CRGradSF[k][iN][0])/(N*N);
      //     }
      //     if(iF==1){
      //       localRhs[locIndI] += m_penalty*intWeights[k]*LBy*4/M_PI*(-solXG[2]*CRGradSF[k][iN][1] - CRsf[k][iN]*gradSolG[1][0] - solXG[1]*CRGradSF[k][iN][0] + CRsf[k][iN]*gradSolG[2][1])/(N*N);
      //     }
      //     if(iF==2){
      //       localRhs[locIndI] += m_penalty*intWeights[k]*LBy*4/M_PI*(-CRsf[k][iN]*gradSolG[1][1] + solXG[1]*CRGradSF[k][iN][1] - CRsf[k][iN]*gradSolG[2][0] - solXG[2]*CRGradSF[k][iN][0])/(N*N);
      //     }
      //   }
      // }
    }
  }
  
  void LBOdecoIso2D::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }
  
  // ------------------------------- Integrability objective function for Odeco anisotrope 2D framefield representation
  void LBOdecoAniso2D::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSFGlob = element->getCRGradSF(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);

    std::vector<double> vRef = element->getDirEdg(0);
    std::vector<double> n = element->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);

    std::vector<std::vector<std::vector<double>>> CRGradSF;
    CRGradSF.resize(CRGradSFGlob.size());
    for(size_t l=0; l<CRGradSFGlob.size(); l++)
      CRGradSF[l].resize(CRGradSFGlob[l].size());
    
    for(size_t l=0; l<CRGradSFGlob.size(); l++)
      for(size_t m=0; m<CRGradSFGlob[l].size(); m++)
        CRGradSF[l][m] = tools::getVectInNewBase(vRef, t, n, CRGradSFGlob[l][m]);
    
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      std::vector<std::vector<double>> gradSolGGlob;
      gradSolGGlob.resize(m_nFields);
      for(std::vector<double> &v: gradSolGGlob)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolGGlob[jField][jX] += CRGradSFGlob[k][iEdg][jX] * solTriRotated[iEdg][jField] ;

      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(size_t l=0; l<gradSolG.size(); l++)
        gradSolG[l] = tools::getVectInNewBase(vRef, t, n, gradSolGGlob[l]);
      
      double H0 = 0.0;
      double H1 = 0.0;
      for(size_t m=0; m<m_nFields; m++)
	for(size_t l=0; l<m_nFields; l++)
	  for(size_t d=0; d<3; d++){
	    H0 += m_C0[m][l][d]*solXG[m]*gradSolG[l][d];
	    H1 += m_C1[m][l][d]*solXG[m]*gradSolG[l][d];
	  }
      
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0] - 4.0/M_PI*solXG[1]*solXG[1] - 4/M_PI*solXG[2]*solXG[2]);
      double valXG = m_penalty*0.5*(H0*H0 + H1*H1)/(N*N);
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void LBOdecoAniso2D::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSFGlob = element->getCRGradSF(pOrder);

    std::vector<double> vRef = element->getDirEdg(0);
    std::vector<double> n = element->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);

    std::vector<std::vector<std::vector<double>>> CRGradSF;
    CRGradSF.resize(CRGradSFGlob.size());
    for(size_t l=0; l<CRGradSFGlob.size(); l++)
      CRGradSF[l].resize(CRGradSFGlob[l].size());
    
    for(size_t l=0; l<CRGradSFGlob.size(); l++)
      for(size_t m=0; m<CRGradSFGlob[l].size(); m++)
        CRGradSF[l][m] = tools::getVectInNewBase(vRef, t, n, CRGradSFGlob[l][m]);
    
    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);

      std::vector<std::vector<double>> gradSolGGlob;
      gradSolGGlob.resize(m_nFields);
      for(std::vector<double> &v: gradSolGGlob)
        v.resize(3, 0.0);

      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolGGlob[jField][jX] += CRGradSFGlob[k][iEdg][jX] * solTri[iEdg][jField] ;

      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(size_t l=0; l<gradSolG.size(); l++)
        gradSolG[l] = tools::getVectInNewBase(vRef, t, n, gradSolGGlob[l]);
      
      std::vector<double> localRhsIncrement(m_nFields*nEdges, 0.0);
      double H0 = 0.0;
      double H1 = 0.0;
      for(size_t m=0; m<m_nFields; m++)
	for(size_t l=0; l<m_nFields; l++)
	  for(size_t d=0; d<3; d++){
	    H0 += m_C0[m][l][d]*solXG[m]*gradSolG[l][d];
	    H1 += m_C1[m][l][d]*solXG[m]*gradSolG[l][d];
	  }
      double N = 0.25*(64.0/(9*2*M_PI)*solXG[0]*solXG[0] - 4.0/M_PI*solXG[1]*solXG[1] - 4/M_PI*solXG[2]*solXG[2]);
      std::vector<double> coeffsN{0.25*64.0/(9*2*M_PI), -0.25*4.0/M_PI, -0.25*4.0/M_PI};
      double valFunc = 0.5*(H0*H0 + H1*H1)/(N*N);

      for(size_t iF=0; iF<m_nFields; iF++){
	for(size_t iN=0; iN<nEdges; iN++){
	  size_t locIndI = m_nFields*iN + iF;
	  for(size_t l=0; l<m_nFields; l++)
	    for(size_t d=0; d<3; d++){
	      double incrH0 = 0.0;
	      if(!(m_C0[iF][l][d]==0.0))
		incrH0 = m_C0[iF][l][d]*CRsf[k][iN]*gradSolG[l][d];
	      if(!(m_C0[l][iF][d]==0.0))
		incrH0 += m_C0[l][iF][d]*solXG[l]*CRGradSF[k][iN][d];
	      if(!(incrH0==0.0)){
		incrH0 *= H0/(N*N);
		localRhsIncrement[locIndI] += incrH0;
	      }
	      double incrH1 = 0.0;
	      if(!(m_C1[iF][l][d]==0.0))
		incrH1 = m_C1[iF][l][d]*CRsf[k][iN]*gradSolG[l][d];
	      if(!(m_C1[l][iF][d]==0.0))
		incrH1 += m_C1[l][iF][d]*solXG[l]*CRGradSF[k][iN][d];
	      if(!(incrH1==0.0)){
		incrH1 *= H1/(N*N);
		localRhsIncrement[locIndI] += incrH1;
	      }
	    }
	  if(iF < 3)
	    localRhsIncrement[locIndI] += -2*valFunc*(2*coeffsN[iF]*solXG[iF]*CRsf[k][iN])/(N);
	}
      }
      for(size_t iF=0; iF<m_nFields; iF++){
	for(size_t iN=0; iN<nEdges; iN++){
	  size_t locIndI = m_nFields*iN + iF;
	  localRhsIncrement[locIndI] *= m_penalty*intWeights[k]*dets[k];
	}
      }
      
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += localRhsIncrement[locIndJ];
        }
    }
  }
  
  void LBOdecoAniso2D::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }
  
  void LBOdecoAniso2D::_create_C(){
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
  
  // ------------------------------- GL framefield constraint
  void GLframeConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = PORDER;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
    
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTriRotated);
      double valXG = m_penalty*(tools::norm2(solXG)-1.0)*(tools::norm2(solXG)-1.0);
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }
  
  void GLframeConstraint::_getRotatedGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<double>> CRsf = element->getCRSF(pOrder);

    localRhs.resize(m_nFields*nEdges, 0.0);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double sqrtConstr = tools::norm2(solXG) - 1.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jEdg=0; jEdg<nEdges; jEdg++){
          size_t locIndJ = m_nFields*jEdg + jField;
          localRhs[locIndJ] += m_penalty*intWeights[k]*dets[k]*4.0*(CRsf[k][jEdg]*solXG[jField])*sqrtConstr;
        }
    }
  }

  void GLframeConstraint::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = PORDER;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }
}
