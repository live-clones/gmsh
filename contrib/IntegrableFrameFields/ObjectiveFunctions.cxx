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
        solTriPerturbed[iN][iF] -= epsilon;
      }
  }

  // ------------------------------- Dirichlet energy for CR GL framefield objective function
  void DirichletEnergieVectCR::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = 4;
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
    int pOrder = 4;
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
    int pOrder = 4;
    size_t nEdges = element->getNumEdges();
    
    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco isotrope 2D framefield constraint
  void OdecoIso2DConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = 4;
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
    int pOrder = 4;
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
    int pOrder = 4;//Warning!! Do not pick an integratino rule with negative integratino weights... Subintegration + negative integration weight can break stability of solver...
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }

  // ------------------------------- Odeco anisotrope 2D framefield constraint
  void OdecoAniso2DConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = 4;
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
    int pOrder = 4;
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
    int pOrder = 4;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }
  
  // ------------------------------- GL framefield constraint
  void GLframeConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = 4;
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
    int pOrder = 4;
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
    int pOrder = 4;
    size_t nEdges = element->getNumEdges();

    std::vector<std::vector<double>> solTriRotated;
    _getRotatedSolEl(element, solTri, solTriRotated);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);
    _getInvertRotatedGradient(element, localRhsRotated, localRhs);
  }
}
