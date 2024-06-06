#include <ObjectiveFunctions.hxx>
#include <vector>
#include <GaussIntegration.h>
#include <fullMatrix.h>

namespace IFF{
  std::vector<ObjectiveFunction*> ObjectiveFunction::objectiveFunctionsCollector;

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
    int pOrder = 3;
    valFunc = 0.0;
    // element->m_e->getIntegrationPoints(3, &nptsG, &ptsW);
    std::vector<double> intWeights = element->getIntegrationWeights(pOrder);
    std::vector<double> dets = element->getDet(pOrder);
    std::vector<std::vector<std::vector<double>>> CRGradSF = element->getCRGradSF(pOrder);
    for(int k=0; k<intWeights.size(); k++){
      std::vector<std::vector<std::vector<double>>> rotOp = _getCRRotOperators(element);
      std::vector<std::vector<double>> solTriRotated = _rotateSolTri(solTri, rotOp);
      
      std::vector<std::vector<double>> gradSolG;
      gradSolG.resize(m_nFields);
      for(std::vector<double> &v: gradSolG)
        v.resize(3, 0.0);
      for(size_t jField=0; jField<m_nFields; jField++)
        for(size_t jX=0; jX<3; jX++)
          for(size_t iEdg=0; iEdg<element->getNumEdges(); iEdg++)
            gradSolG[jField][jX] += CRGradSF[k][iEdg][jX] * solTriRotated[iEdg][jField] ;
      
      double valXG = 0.0;
      for(size_t jField=0; jField<m_nFields; jField++)
        valXG += tools::norm(gradSolG[jField]);
      
      valFunc += valXG*intWeights[k]*dets[k];
    }
  }
  void DirichletEnergieVectCR::getGradient(Element *element, const std::vector<std::vector<double>> &solTri, std::vector<double> &localRhs){
    
  }
}
