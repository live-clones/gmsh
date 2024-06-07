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
    double epsilon = 1e-8;
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
        std::cout << "error grad: " << errorGrad << std::endl;
        solTriPerturbed[iN][iF] -= epsilon;
      }
  }

  // ------------------------------- Dirichlet energy for CR GL framefield objective function
  std::vector<std::vector<std::vector<double>>> DirichletEnergieVectCR::_getCRRotOperators(Element *e){
    int nEdges = e->getNumEdges();
    std::vector<std::vector<std::vector<double>>> op;
    op.resize(nEdges);
    for(std::vector<std::vector<double>> &vv: op){
      vv.resize(2);
      for(std::vector<double> &v: vv)
        v.resize(2, 0.0);
    }
    std::vector<double> vRef = e->getDirEdg(0);
    std::vector<double> n = e->getNormal();
    std::vector<double> t = tools::crossprod(n, vRef);
    op[0][0][0] = 1.0; op[0][1][1] = 1.0;
    for(int iEdg=1; iEdg<nEdges; iEdg++){
      std::vector<double> vEdg = e->getDirEdg(iEdg);
      double alpha = atan2(tools::dotprod(t,vEdg), tools::dotprod(vRef,vEdg));
      op[iEdg][0][0] = cos(4*alpha); op[iEdg][0][1] = -sin(4*alpha);
      op[iEdg][1][0] = sin(4*alpha); op[iEdg][1][1] =  cos(4*alpha);
    }
    return op;
  }

  std::vector<std::vector<double>> DirichletEnergieVectCR::_rotateSolTri(const std::vector<std::vector<double>> &solTri, const std::vector<std::vector<std::vector<double>>> &rotOp){
    std::vector<std::vector<double>> solTriRotated;
    solTriRotated.resize(solTri.size());
    for(std::vector<double> &v: solTriRotated)
      v.resize(m_nFields, 0.0);
    for(size_t iEdg=0; iEdg<solTriRotated.size(); iEdg++)
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t kField=0; kField<m_nFields; kField++)
          solTriRotated[iEdg][jField] += rotOp[iEdg][jField][kField]*solTri[iEdg][kField];
    
    return solTriRotated;
  }
  
  void DirichletEnergieVectCR::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = 2;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);

    std::vector<std::vector<std::vector<double>>> rotOp = _getCRRotOperators(element);
    std::vector<std::vector<double>> solTriRotated = _rotateSolTri(solTri, rotOp);
      
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
    int pOrder = 2;
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
    int pOrder = 2;
    size_t nEdges = element->getNumEdges();
    
    std::vector<std::vector<std::vector<double>>> rotOp = _getCRRotOperators(element);
    std::vector<std::vector<double>> solTriRotated = _rotateSolTri(solTri, rotOp);
  
    std::vector<double> localRhsRotated;
    _getRotatedGradient(element, solTriRotated, localRhsRotated);

    localRhs.resize(m_nFields*nEdges, 0.0);
    for(size_t jField=0; jField<m_nFields; jField++)
      for(size_t jEdg=0; jEdg<nEdges; jEdg++){
        size_t locIndJ = m_nFields*jEdg + jField;
        for(size_t kField=0; kField<m_nFields; kField++){
          size_t locIndK = m_nFields*jEdg + kField;
          localRhs[locIndJ] += localRhsRotated[locIndK] * rotOp[jEdg][kField][jField];
        }
      }
  }

  // ------------------------------- GL framefield constraint
  void GLframeConstraint::evaluateFunction(Element *element, const std::vector<std::vector<double>> &solTri, double &valFunc){
    int pOrder = 2;
    valFunc = 0.0;

    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<std::vector<double>> intPoints= element->getIntegrationPoints(pOrder);
    std::vector<double> dets = element->getDet(pOrder);

    for(int k=0; k<intWeights.size(); k++){
      std::vector<double> solXG = element->interpolateCR(intPoints[k][0], intPoints[k][1], solTri);
      double valXG = m_penalty*(tools::norm2(solXG)-1.0)*(tools::norm2(solXG)-1.0);
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }

  void GLframeConstraint::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    int pOrder = 2;
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
}
