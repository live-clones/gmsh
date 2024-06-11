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
  int PORDER = 4;
  std::vector<ObjectiveFunction*> ObjectiveFunction::objectiveFunctionsCollector;

  void ObjectiveFunction::checkGradient(Element *element, const std::vector<std::vector<double>> &solTri){
    double epsilon = 1e-6;
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
      valFunc += valXG*intWeights[k]*dets[k];
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
