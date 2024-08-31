#include <IffTools.hxx>
#include <iostream>
#include <MVertex.h>
#include <MTriangle.h>
#include <MQuadrangle.h>
#include <GaussIntegration.h>
#include <fullMatrix.h>
#include <GModel.h>
#include <Visualization.hxx>
#include <queue>

namespace IFF{
  namespace tools{
    void normalize(std::vector<double> &v){
      double norm = 0.0;
      for(size_t k=0; k<v.size(); k++)
        norm += v[k]*v[k];
      norm = sqrt(norm);
      if(norm > 1e-12){
        for(size_t k=0; k<v.size(); k++)
          v[k] /= norm;
      }
    }

    void scale(std::vector<double> &v, double scaling){
      for(size_t k=0; k<v.size(); k++)
        v[k] *= scaling;
    }
  
    std::vector<double> getNormalizedVector(const std::vector<double> &v){
      std::vector<double> vCopy = v;
      normalize(vCopy);
      return vCopy;
    }

    std::vector<double> crossprod(const std::vector<double> &v0, const std::vector<double> &v1){
      std::vector<double> res{0.0, 0.0, 0.0};
      if(v0.size() == 3 && v1.size() == 3){
        res[0] = v0[1]*v1[2] - v0[2]*v1[1];
        res[1] = v0[2]*v1[0] - v0[0]*v1[2];
        res[2] = v0[0]*v1[1] - v0[1]*v1[0];
      }
      else{
        std::cout << "TOOLS: Wrong use of crossprod" << std::endl;
        exit(0);
      }
      return res;
    }

    double dotprod(const std::vector<double> &v0, const std::vector<double> &v1){
      double val = 0.0;
      for(size_t k=0; k<v0.size(); k++)
        val += v1[k]*v0[k];
      return val;
    }

    double cosAngle(const std::vector<double> &v0, const std::vector<double> &v1){
      return dotprod(v0, v1) / norm(v0) / norm(v1);
    }

    std::vector<double> diff(const std::vector<double> &v0, const std::vector<double> &v1){
      if(v0.size() != v1.size()){
        std::cout << "Wrong use of tools::diff. v0 and v1 sizes not matching" << std::endl;
      }
      else{
        std::vector<double> res(v0.size(), 0.0);
        for(size_t k=0; k<v0.size(); k++)
          res[k] = v0[k] - v1[k];
        return res;
      }
    }

    std::vector<double> sum(const std::vector<double> &v0, const std::vector<double> &v1){
      if(v0.size() != v1.size()){
        std::cout << "Wrong use of tools::sum. v0 and v1 sizes not matching" << std::endl;
      }
      else{
        std::vector<double> res(v0.size(), 0.0);
        for(size_t k=0; k<v0.size(); k++)
          res[k] = v0[k] + v1[k];
        return res;
      }
    }
    
    double norm(const std::vector<double> &v){
      double norm = 0.0;
      for(size_t k=0; k<v.size(); k++)
        norm += v[k]*v[k];
      norm = sqrt(norm);
      return norm;
    }

    double norm2(const std::vector<double> &v) {
      double norm = 0.0;
      for(size_t k=0; k<v.size(); k++)
        norm += v[k]*v[k];
      return norm;
    }

    double norm(const double *v, const size_t &size){
      double norm = 0.0;
      for(size_t k=0; k<size; k++)
        norm += v[k]*v[k];
      norm = sqrt(norm);
      return norm;
    }

    double distance(const std::vector<double> &v0, const std::vector<double> &v1){
      std::vector<double> diff;
      diff.resize(v0.size(), 0.0);
      for(size_t k=0; k<v0.size(); k++)
        diff[k] = v1[k] - v0[k];
      return norm(diff);
    }
    std::vector<double> rotateAlongDirection(const std::vector<double> &vectAxis, const double &theta, const std::vector<double> &v){
      std::vector<double> uVectAxis = getProjectionOnDirection(vectAxis, v);
      std::vector<double> uOrth = getProjectionOnHyperPlan(vectAxis, v);
      double normuOrth = norm(uOrth);
      std::vector<double> normalizeduOrth = getNormalizedVector(uOrth);
      std::vector<double> normalizedVectAxis = getNormalizedVector(vectAxis);

      std::vector<double> t = crossprod(normalizedVectAxis, normalizeduOrth);
      std::vector<double> res(3, 0.0);
      for(size_t j=0; j<3; j++)
        res[j] = normuOrth*(cos(theta)*normalizeduOrth[j] + sin(theta)*t[j]) + uVectAxis[j];
      
      return res;
    }
    double getAngleRotationAlongDirection(const std::vector<double> &vectAxis, const std::vector<double> &vInit, const std::vector<double> &vRotated){
      std::vector<double> vectAxisNorm = getNormalizedVector(vectAxis);
      std::vector<double> vInitNorm = getProjectionOnHyperPlan(vectAxisNorm, vInit);
      tools::normalize(vInitNorm);
      std::vector<double> vRotatedNorm = getProjectionOnHyperPlan(vectAxisNorm, vRotated);
      tools::normalize(vRotatedNorm);
      std::vector<double> t = crossprod(vectAxisNorm, vInitNorm);
      double alpha = atan2(dotprod(vRotatedNorm, t), dotprod(vRotatedNorm, vInitNorm));
      return alpha;
    }
    std::vector<double> getProjectionOnDirection(const std::vector<double> &dirProj, const std::vector<double> &v){
      if(dirProj.size() != v.size()){
        std::cout << "Uncorrect used of IFF::tools:getProjectionOnDirection. sizes do not match" << std::endl;
        exit(0);
      }
      std::vector<double> normalizedDir = getNormalizedVector(dirProj);
      double dp = dotprod(normalizedDir, v);
      std::vector<double> res(v.size(), 0.0);
      for(size_t j=0; j<v.size(); j++)
        res[j] = dp*normalizedDir[j];
      
      return res; 
    }
    std::vector<double> getProjectionOnHyperPlan(const std::vector<double> &normalHyperPlan, const std::vector<double> &v){
      if(normalHyperPlan.size() != v.size()){
        std::cout << "Uncorrect used of IFF::tools:getProjectionOnHyperPlan. sizes do not match" << std::endl;
        exit(0);
      }
      std::vector<double> normalizedDir = getNormalizedVector(normalHyperPlan);
      double dp = dotprod(normalizedDir, v);
      std::vector<double> res(v.size(), 0.0);
      for(size_t j=0; j<v.size(); j++)
        res[j] = v[j] - dp*normalizedDir[j];
      
      return res; 
    }
    void projectOnHyperPlan(const std::vector<double> &normalHyperPlan, std::vector<double> &v){
      if(normalHyperPlan.size() != v.size()){
        std::cout << "Uncorrect used of IFF::tools:getProjectionOnHyperPlan. sizes do not match" << std::endl;
        exit(0);
      }
      std::vector<double> normalizedDir = getNormalizedVector(normalHyperPlan);
      double dp = dotprod(normalizedDir, v);
      std::vector<double> res(v.size(), 0.0);
      for(size_t j=0; j<v.size(); j++)
        v[j] -= dp*normalizedDir[j];
    }
    std::vector<double> getVectInNewBase(const std::vector<double> &u, const std::vector<double> &v, const std::vector<double> &w, const std::vector<double> &vect){
      bool isBaseOk = true;
      if(u.size() != 3 || v.size() != 3 || w.size() != 3 || vect.size() != 3)
        isBaseOk = false;
      if(fabs(norm(u)-1.0) > 1e-10 || fabs(norm(v)-1.0) > 1e-10 || fabs(norm(w)-1.0) > 1e-10)
        isBaseOk = false;
      if(fabs(dotprod(u,v)) > 1e-10 || fabs(dotprod(u,w)) > 1e-10 || fabs(dotprod(v,w)) > 1e-10)
        isBaseOk = false;
      if(!isBaseOk){
        std::cout << "tools::getVectInNewBase: Base provided is not orthonormal, or vectors with dim !=3 provided" << std::endl;
        exit(0);
      }
      else{
        std::vector<double> res(3, 0.0);
        res[0] = dotprod(u, vect);
        res[1] = dotprod(v, vect);
        res[2] = dotprod(w, vect);
        return res;
      }
    }
    std::vector<double> getClosestVect(const std::vector<std::vector<double>> &listVects, const std::vector<double> &dirRef){
      int indClosest = getIndexClosestVect(listVects, dirRef);
      return listVects[indClosest];
    }
    int getIndexClosestVect(const std::vector<std::vector<double>> &listVects, const std::vector<double> &dirRef){
      int indClosest = 0;
      double maxDotProd = -1e-10;
      std::vector<double> normalizedDirRef = getNormalizedVector(dirRef);
      for(size_t k=0; k<listVects.size(); k++){
        std::vector<double> candidateDir = getNormalizedVector(listVects[k]);
        double candidateDotProd = dotprod(normalizedDirRef, candidateDir);
        if(candidateDotProd > maxDotProd){
          maxDotProd = candidateDotProd;
          indClosest = k;
        }
      }
      return indClosest;
    }
  }
  
  namespace manifoldTools{
    std::vector<double> transportToNeighbourElement(Element *eRef, Element *eTarget, const std::vector<double> &vectToTransport){
      std::vector<double> normalRef = eRef->getNormal();
      std::vector<double> normalTarget = eTarget->getNormal();
      Edge* commonEdge = NULL;
      // std::cout << "Edg point prev: " << commonEdge << std::endl;
      for(Edge *edg: eRef->getEdges()){
        int locIndEdgTarget = edg->getLocIndexInElem(eTarget);
        if(locIndEdgTarget >= 0){
          commonEdge = eTarget->getEdge(locIndEdgTarget);
          break;
        }
      }
      // std::cout << "Edg point next: " << commonEdge << std::endl;
      if(commonEdge){
        // std::cout << "edg index: " << commonEdge->getIndex() << std::endl;
        std::vector<double> dirEdg = commonEdge->getDir();
        double alpha = tools::getAngleRotationAlongDirection(dirEdg, normalRef, normalTarget);
        std::vector<double> vectTransported = tools::rotateAlongDirection(dirEdg, alpha, vectToTransport);
        return vectTransported;
      }
      else{
        std::cout << "IFF::mnifoldTools: asked to transport vect on two elements with no common edges. Exiting" << std::endl;
        exit(0);
        std::vector<double> vectTransported;
        return vectTransported;
      }
    }
  }

  std::vector<Vertex*> Vertex::vertexCollector;
  std::vector<Element*> Element::elementCollector;
  std::vector<double> Element::integrationWeights;
  std::vector<std::vector<double>> Element::integrationPoints;
  std::vector<Edge*> Edge::edgeCollector;
  std::vector<MVertex*> Mesh::hangingGmshVerticesCollector;
  std::vector<MElement*> Mesh::hangingGmshElementsCollector;

  Element::Element(Mesh *m, MElement* el){
    m_e = el;
    std::vector<MVertex *> vert;
    el->getVertices(vert);
    m_vertices.reserve(vert.size());
    for(MVertex *v: vert){
      m_vertices.push_back(m->m_vertices[v->getIndex()]);
    }
  }

  std::vector<std::vector<double>> Element::getEdgesParamCoordInParentElem(){
    std::vector<std::vector<double>> coordEdgesInParentElem;
    switch(m_childType){
    case CHILDTYPE::HALF0:
      coordEdgesInParentElem.resize(getNumEdges());
      if(m_childID == 0){
        coordEdgesInParentElem[0] = {0.25, 0.0, 0.0};
        coordEdgesInParentElem[1] = {0.25, 0.5, 0.0};
        coordEdgesInParentElem[2] = {0.0, 0.5, 0.0};
      }
      else if(m_childID == 1){
        coordEdgesInParentElem[0] = {0.75, 0.0, 0.0};
        coordEdgesInParentElem[1] = {0.5, 0.5, 0.0};
        coordEdgesInParentElem[2] = {0.25, 0.5, 0.0};
      }
      else{
        std::cout << "HALF0: Unknown child type" << std::endl;
        exit(0);
      }
      break;
    case CHILDTYPE::HALF1:
      coordEdgesInParentElem.resize(getNumEdges());
      if(m_childID == 0){
        coordEdgesInParentElem[0] = {0.75, 0.25, 0.0};
        coordEdgesInParentElem[1] = {0.25, 0.25, 0.0};
        coordEdgesInParentElem[2] = {0.5, 0.0, 0.0};
      }
      else if(m_childID == 1){
        coordEdgesInParentElem[0] = {0.25, 0.75, 0.0};
        coordEdgesInParentElem[1] = {0.0, 0.5, 0.0};
        coordEdgesInParentElem[2] = {0.25, 0.25, 0.0};
      }
      else{
        std::cout << "HALF1: Unknown child type" << std::endl;
        exit(0);
      }
      break;
    case CHILDTYPE::HALF2:
      coordEdgesInParentElem.resize(getNumEdges());
      if(m_childID == 0){
        coordEdgesInParentElem[0] = {0.0, 0.75, 0.0};
        coordEdgesInParentElem[1] = {0.5, 0.25, 0.0};
        coordEdgesInParentElem[2] = {0.5, 0.5, 0.0};
      }
      else if(m_childID == 1){
        coordEdgesInParentElem[0] = {0.0, 0.25, 0.0};
        coordEdgesInParentElem[1] = {0.5, 0.0, 0.0};
        coordEdgesInParentElem[2] = {0.5, 0.25, 0.0};
      }
      else{
        std::cout << "HALF2: Unknown child type" << std::endl;
        exit(0);
      }
      break;
    case CHILDTYPE::FRACTAL:
      coordEdgesInParentElem.resize(getNumEdges());
      if(m_childID == 0){
        coordEdgesInParentElem[0] = {0.5, 0.25, 0.0};
        coordEdgesInParentElem[1] = {0.25, 0.5, 0.0};
        coordEdgesInParentElem[2] = {0.25, 0.25, 0.0};
      }
      else if(m_childID == 1){
        coordEdgesInParentElem[0] = {0.25, 0.0, 0.0};
        coordEdgesInParentElem[1] = {0.25, 0.25, 0.0};
        coordEdgesInParentElem[2] = {0.0, 0.25, 0.0};
      }
      else if(m_childID == 2){
        coordEdgesInParentElem[0] = {0.75, 0.0, 0.0};
        coordEdgesInParentElem[1] = {0.75, 0.25, 0.0};
        coordEdgesInParentElem[2] = {0.5, 0.25, 0.0};
      }
      else if(m_childID == 3){
        coordEdgesInParentElem[0] = {0.25, 0.5, 0.0};
        coordEdgesInParentElem[1] = {0.25, 0.75, 0.0};
        coordEdgesInParentElem[2] = {0.0, 0.75, 0.0};
      }
      else{
        std::cout << "FRACTAL: Unknown child type" << std::endl;
        exit(0);
      }
      break;
    default:
      return coordEdgesInParentElem;
    }
    return coordEdgesInParentElem;
  }
  
  std::vector<double> Element::getDirEdg(int iEdg){
    if(iEdg > m_e->getNumEdges()){
      std::cout << "Error in Element::getDirEdg. Request for the direction of an unexisting edge." << std::endl;
      exit(0);
    }
    std::vector<double> v = tools::diff(m_vertices[(iEdg+1)%m_e->getNumEdges()]->getCoord(), m_vertices[iEdg]->getCoord());
    tools::normalize(v);
    return v;
  }

  Edge* Element::getCommonEdge(Element* otherEl){
    for(size_t k=0; k<m_edges.size(); k++){
      int locIndEdg = m_edges[k]->getLocIndexInElem(otherEl);
      if(locIndEdg >= 0)
        return m_edges[k];
    }
    return NULL;
  }
  
  double Element::getArea(){
    if(getNumEdges() == 3){
      std::vector<double> v0 = tools::diff(m_vertices[1]->getCoord(), m_vertices[0]->getCoord());
      std::vector<double> v1 = tools::diff(m_vertices[getNumEdges()-1]->getCoord(), m_vertices[0]->getCoord());
      std::vector<double> scaledN = tools::crossprod(v0, v1);
      return tools::norm(scaledN)/2.0;
    }
    else{
      std::cout << "Area computation not implement for elements with " << m_vertices.size() << " vertices. Exiting." << std::endl;
      exit(0);
      return 1.0;
    }
  }
  
  std::vector<double> Element::getNormal(){
    if(m_normal.size() == 0)
      _computeNormal();
    return m_normal;
  }
  
  void Element::_computeNormal(){
    size_t nEdges = m_e->getNumEdges();
    if(nEdges != 3){
      std::cout << "Compute normal only available for triangles for now" << std::endl;
      exit(0);
    }
    else{
      std::vector<double> v01 = tools::diff(m_vertices[1]->getCoord(), m_vertices[0]->getCoord());
      std::vector<double> v02 = tools::diff(m_vertices[2]->getCoord(), m_vertices[0]->getCoord());
      tools::normalize(v01); tools::normalize(v02);
      m_normal = tools::crossprod(v01, v02);
      tools::normalize(m_normal);
    }
  }

  std::vector<double> Element::getDet(int pOrder){
    if(m_det.size() == 0){
      getCRGradSF(pOrder);
      return m_det;
    }
    else
      return m_det;
  }

  std::vector<std::vector<double>> Element::getIntegrationPoints(int pOrder){
    if(integrationPoints.size() == 0){
      int nptsG=0;
      IntPt *ptsW = NULL;
      m_e->getIntegrationPoints(pOrder, &nptsG, &ptsW);
      integrationPoints.resize(nptsG);
      for(std::vector<double> &v: integrationPoints)
        v.resize(3, 0.0);
      for(size_t k=0; k<nptsG; k++){
        integrationPoints[k][0] = ptsW[k].pt[0];
        integrationPoints[k][1] = ptsW[k].pt[1];
        integrationPoints[k][2] = ptsW[k].pt[2];
      }
      return integrationPoints;
    }
    else
      return integrationPoints;
  }
  
  std::vector<double> Element::getIntegrationWeights(int pOrder){
    if(integrationWeights.size() == 0){
      int nptsG=0;
      IntPt *ptsW = NULL;
      m_e->getIntegrationPoints(pOrder, &nptsG, &ptsW);
      integrationWeights.resize(nptsG, 0.0);
      for(size_t k=0; k<nptsG; k++){
        integrationWeights[k] = ptsW[k].weight;
      }
      return integrationWeights;
    }
    else
      return integrationWeights;
  }

  std::vector<double> Element::_computeCRSF(double u, double v){
    size_t nEdges = m_edges.size();
    if(nEdges==3){
      std::vector<double> CRsf;
      CRsf.resize(getNumEdges(), 0.0);
      CRsf[0] = 1.0-2*v;
      CRsf[1] = 2.0*u+2.0*v-1.0;
      CRsf[2] = 1.0-2.0*u;
      return CRsf;
    }
    else{
      std::cout << "Crouzeix raviart shape functions not implement for element with " << nEdges << " edges." << std::endl;
      exit(0);
    }
  }
  
  std::vector<std::vector<double>> Element::getCRSF(int pOrder){
    if(m_CRsf.size()==0){
      size_t nEdges = m_edges.size();
      if(nEdges==3){
        int nptsG=0;
        IntPt *ptsW = NULL;
        m_e->getIntegrationPoints(pOrder, &nptsG, &ptsW);
        m_CRsf.resize(nptsG);
        for(std::vector<double> &v: m_CRsf)
          v.resize(nEdges, 0.0);

        for(int k=0; k<nptsG; k++){
          m_CRsf[k] = _computeCRSF(ptsW[k].pt[0], ptsW[k].pt[1]);
          // m_CRsf[k][0] = 1.0-2*ptsW[k].pt[1];
          // m_CRsf[k][1] = 2.0*ptsW[k].pt[0]+2.0*ptsW[k].pt[1]-1.0;
          // m_CRsf[k][2] = 1.0-2.0*ptsW[k].pt[0];
        }
        return m_CRsf;
      }
      else if(nEdges==4){
        std::cout << "Crouzeix raviart grad shape functions not implement for element with " << nEdges << " edges." << std::endl;
        exit(0);
      }
      else{
        std::cout << "Crouzeix raviart grad shape functions not implement for element with " << nEdges << " edges." << std::endl;
        exit(0);
      }
    }
    else
      return m_CRsf;
  }
  
  std::vector<std::vector<std::vector<double>>> Element::getCRGradSF(int pOrder){
    if(m_CRgsf.size()==0){
      size_t nEdges = m_edges.size();
      if(nEdges==3){
        int nptsG=0;
        IntPt *ptsW = NULL;
        m_e->getIntegrationPoints(pOrder, &nptsG, &ptsW);
        m_det.resize(nptsG, 0.0);
        m_CRgsf.resize(nptsG);
        for(std::vector<std::vector<double>> &vv: m_CRgsf){
          vv.resize(nEdges);
          for(std::vector<double> &v: vv)
            v.resize(3, 0.0);
        }
        for(int k=0; k<nptsG; k++){
          double gsfRef[nEdges][3];
          gsfRef[0][0] =  0.0; gsfRef[0][1] = -2.0; gsfRef[0][2] = 0.0;
          gsfRef[1][0] =  2.0; gsfRef[1][1] =  2.0; gsfRef[1][2] = 0.0;
          gsfRef[2][0] = -2.0; gsfRef[2][1] =  0.0; gsfRef[2][2] = 0.0;
          double jacT[3][3];
          m_e->getJacobian(ptsW[k].pt[0], ptsW[k].pt[1], ptsW[k].pt[2], jacT);
          fullMatrix<double> jac(3, 3);
          for(int i=0; i<3; i++)
            for(int j=0; j<3; j++)
              jac(i,j) = jacT[j][i];
          double det = jac.determinant();
          m_det[k] = det;
          fullMatrix<double> invJac(3, 3);
          jac.invert(invJac);
          for(size_t i=0; i<nEdges; i++)
            for(size_t j=0; j<3; j++)
              for(size_t l=0; l<3; l++)
                m_CRgsf[k][i][j] += gsfRef[i][l]*invJac(l,j);
        }
        return m_CRgsf;
      }
      else if(nEdges==4){
        std::cout << "Crouzeix raviart grad shape functions not implement for element with " << nEdges << " edges." << std::endl;
      }
      else{
        std::cout << "Crouzeix raviart grad shape functions not implement for element with " << nEdges << " edges." << std::endl;
        exit(0);
      }
    }
    else
      return m_CRgsf;
  }

  std::vector<double> Element::interpolateCR(double u, double v, const std::vector<std::vector<double>> &solTri){
    std::vector<double> interpolatedSol;
    interpolatedSol.resize(solTri[0].size(), 0.0);
    std::vector<double> sf = _computeCRSF(u, v);
    for(size_t iEdg=0; iEdg<solTri.size(); iEdg++)
      for(size_t iF=0; iF<solTri[0].size(); iF++)
        interpolatedSol[iF] += sf[iEdg]*solTri[iEdg][iF];
    return interpolatedSol;
  }
  
  double Edge::getLength(){
    std::vector<double> v = tools::diff(m_vertices[0]->getCoord(), m_vertices[1]->getCoord());
    return tools::norm(v);
  }
  
  Mesh::Mesh(std::vector<MElement*> &elts, std::vector<MLine*> &bndLines, std::vector<MVertex*> &geoNodes){
    //Number vertices and Build vertices vector
    size_t nMaxVert = 0;
    size_t nMaxEdges = 0;
    for(MElement* e: elts){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      nMaxVert += verts.size();
      for(MVertex *v: verts)
        v->setIndex(-1);
      nMaxEdges += e->getNumEdges();
    }
    for(MLine* e: bndLines){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      nMaxVert += verts.size();
      for(MVertex *v: verts)
        v->setIndex(-1);
      nMaxEdges += e->getNumEdges();
    }
    for(MVertex *v: geoNodes){
      v->setIndex(-1);
    }
    m_vertices.reserve(nMaxVert);
    size_t cptVert=0;
    for(MElement* e: elts){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      for(MVertex *v: verts)
        if(v->getIndex() == -1){
          v->setIndex(cptVert);
          cptVert++;
          Vertex *myV = Vertex::create(v);
          m_vertices.push_back(myV);
          myV->m_index = v->getIndex();
        }
    }
    for(MLine* e: bndLines){
      std::vector<MVertex *> verts;
      e->getVertices(verts);
      for(MVertex *v: verts)
        if(v->getIndex() == -1){
          v->setIndex(cptVert);
          cptVert++;
          Vertex *myV = Vertex::create(v);
          m_vertices.push_back(myV);
          myV->m_index = v->getIndex();
        }
    }
    m_vertices.shrink_to_fit();
    //Tag vertices which are geoNodes
    for(MVertex *v: geoNodes)
      if(v->getIndex() != -1)
        m_vertices[v->getIndex()]->m_isGeoNode = true;
    //Build Elements vector
    m_elements.reserve(elts.size());
    for(MElement* e: elts){
      Element *myE = Element::create(this, e);
      // std::vector<MVertex *> vert;
      // e->getVertices(vert);
      m_elements.push_back(myE);
      myE->m_index = m_elements.size()-1;
    }
    //Build Line vector
    m_lines.reserve(bndLines.size());
    for(MLine* l: bndLines){
      Element *myE = Element::create(this, l);
      m_lines.push_back(myE);
      myE->m_index = m_lines.size()-1;
    }
    //Build Edges and struct
    _buildStructure(nMaxEdges);

    //DBG check sanity
    _checkSanity();
  }

  Mesh::Mesh(Mesh &origMesh){
    minimalCopy(origMesh);
    size_t nMaxEdges = 0;
    for(Element *e: m_elements)
      nMaxEdges += e->getNumEdges();
    for(Element *l: m_lines)
      nMaxEdges += l->getNumEdges();
    //Build edges
    _buildStructure(nMaxEdges);

    //DBG check sanity
    _checkSanity(); 
  }

  void Mesh::minimalCopy(Mesh &origMesh){
    MElementFactory elemfact;

    size_t nMaxEdges = 0;
    //Build Vertex vector
    m_vertices.reserve(origMesh.m_vertices.size());
    for(Vertex *origV: origMesh.m_vertices){
      MVertex *newGmshV = new MVertex(*(origV->m_v));
      hangingGmshVerticesCollector.push_back(newGmshV);

      Vertex *v = Vertex::create(newGmshV);
      m_vertices.push_back(v);
      v->m_index = m_vertices.size()-1;
      v->m_v->setIndex(v->m_index);
      v->m_isGeoNode = origV->m_isGeoNode;
    }
    //Build Elements vector
    GModel *gm = GModel::current();
    m_elements.reserve(origMesh.m_elements.size());
    for(Element* eOrig: origMesh.m_elements){
      std::vector<MVertex *> verts;
      verts.reserve(eOrig->m_vertices.size());

      for(Vertex *origV: eOrig->getVertices()){
        verts.push_back(m_vertices[origV->m_index]->m_v);
      }
      
      MElement *newGmshElem = elemfact.create(eOrig->m_e->getTypeForMSH(), verts);
      for(auto gf: gm->getFaces()){//TODO: this is temporary, we have to add new elements to the good face. Let Gmsh handle memory for Elements created
        gf->addElement(newGmshElem);
        break;
      }
      hangingGmshElementsCollector.push_back(newGmshElem);
      
      Element *myE = Element::create(this, newGmshElem);
      m_elements.push_back(myE);
      myE->m_index = m_elements.size()-1;
      nMaxEdges += myE->getNumEdges();
    }
    gm->rebuildMeshElementCache();
    //Build Line vector
    m_lines.reserve(origMesh.m_lines.size());
    for(Element* lOrig: origMesh.m_lines){
      std::vector<MVertex *> verts;
      verts.reserve(lOrig->m_vertices.size());

      for(Vertex *origV: lOrig->getVertices())
        verts.push_back(m_vertices[origV->m_index]->m_v);
        
      MElement *newGmshElem = elemfact.create(lOrig->m_e->getTypeForMSH(), verts);
      hangingGmshElementsCollector.push_back(newGmshElem);
        
      Element *myL = Element::create(this, newGmshElem);
      m_lines.push_back(myL);
      myL->m_index = m_lines.size()-1;
      nMaxEdges += myL->getNumEdges();
    }
  }
  
  void Mesh::_buildStructure(size_t nMaxEdges){
    //Build Edges vector
    std::vector<std::pair<std::array<size_t, 2>, Element*>> edgesList;
    edgesList.reserve(nMaxEdges);
    for(Element* e: m_elements){
      size_t nEdges = e->m_e->getNumEdges();
      for(size_t k=0; k<nEdges; k++){
        std::array<size_t, 2> vNum;
        if(e->m_vertices[k]->m_index < e->m_vertices[(k+1)%nEdges]->m_index){
          vNum[0] = e->m_vertices[k]->m_index;
          vNum[1] = e->m_vertices[(k+1)%nEdges]->m_index;
        }
        else{
          vNum[0] = e->m_vertices[(k+1)%nEdges]->m_index;
          vNum[1] = e->m_vertices[k]->m_index;
        }
        edgesList.push_back(std::make_pair(vNum, e));
      }
    }
    for(Element* e: m_lines){
      size_t nEdges = e->m_e->getNumEdges();
      for(size_t k=0; k<nEdges; k++){
        std::array<size_t, 2> vNum;
        if(e->m_vertices[k]->m_index < e->m_vertices[k+1]->m_index){
          vNum[0] = e->m_vertices[k]->m_index;
          vNum[1] = e->m_vertices[k+1]->m_index;
        }
        else{
          vNum[0] = e->m_vertices[k+1]->m_index;
          vNum[1] = e->m_vertices[k]->m_index;
        }
        edgesList.push_back(std::make_pair(vNum, e));
      }
    }
    
    std::sort(edgesList.begin(), edgesList.end(), [&](std::pair<std::array<size_t, 2>, Element*> i1, std::pair<std::array<size_t, 2>, Element*> i2){
      if(i1.first[0] == i2.first[0])
        return i1.first[1] < i2.first[1];
      else
        return i1.first[0] < i2.first[0];});

    m_edges.reserve(nMaxEdges);
    std::array<size_t, 2> edgPrec;
    edgPrec[0] = -1;
    Edge *edgK = NULL;
    for(const std::pair<std::array<size_t, 2>, Element*> &pair: edgesList){
      if(edgPrec != pair.first){
        edgK = Edge::create(m_vertices[pair.first[0]], m_vertices[pair.first[1]]);
        m_edges.push_back(edgK);
        edgK->m_index = m_edges.size()-1;
        edgPrec = pair.first;
      }
      if(pair.second->m_e->getNumEdges() == 1)
        edgK->m_lines.push_back(pair.second);
      else
        edgK->m_elements.push_back(pair.second);
      pair.second->m_edges.push_back(edgK);
    }
    m_edges.shrink_to_fit();
    //Compute min and max edge length
    m_minEdgeLenght = 1e50;
    m_maxEdgeLenght = 0.0;
    for(Edge *e: m_edges){
      double l = e->getLength();
      if(l < m_minEdgeLenght)
        m_minEdgeLenght = l;
      if(l > m_maxEdgeLenght)
        m_maxEdgeLenght = l;
    }

    //Sort m_edges for elements
    for(Element *e: m_elements){
      std::vector<Edge *> sortedEdges;
      sortedEdges.reserve(e->m_edges.size());
      for(size_t k=0; k<e->m_edges.size(); k++){
        for(size_t l=0; l<e->m_edges.size(); l++){
          if((e->m_vertices[k]->m_index == e->m_edges[l]->m_vertices[0]->m_index) || (e->m_vertices[k]->m_index == e->m_edges[l]->m_vertices[1]->m_index))
            if((e->m_vertices[(k+1)%e->m_edges.size()]->m_index == e->m_edges[l]->m_vertices[0]->m_index) || (e->m_vertices[(k+1)%e->m_edges.size()]->m_index == e->m_edges[l]->m_vertices[1]->m_index)){
              sortedEdges.push_back(e->m_edges[l]);
              break;
            }
        }
      }
      e->m_edges = sortedEdges;
    }

    //Fill Vertex sorted edges and sorted elements. Tag vertices belonging to geometry boundary
    for(Edge *e: m_edges)
      if(e->getElements().size() == 1){
        for(Vertex *v: e->getVertices())
          v->m_isGeometryBoundary = true;
      }
    
    for(Edge *e: m_edges)
      for(Vertex *v: e->getVertices())
        v->m_edges.push_back(e);
    for(Element *e: m_elements)
      for(Vertex *v: e->getVertices())
        v->m_elements.push_back(e);
    for(Element *l: m_lines)
      for(Vertex *v: l->getVertices())
        v->m_lines.push_back(l);

    for(Vertex *v: m_vertices){
      std::vector<Edge*> vertEdges = v->getEdges();
      int locIndEdgeStart = 0;
      for(size_t k=0; k<vertEdges.size(); k++){
        Edge *edg = vertEdges[k];
        if(edg->getElements().size() == 1){
          Element *elem = edg->getElements()[0];
          if(edg->getLocIndexInElem(elem) == v->getLocIndexInElem(elem)){
            locIndEdgeStart = k;
          }
        }
      }
      Edge *edgCurrent = vertEdges[locIndEdgeStart];

      v->m_sortedEdges.clear();
      v->m_sortedEdges.reserve(vertEdges.size());
      v->m_sortedElements.clear();
      v->m_sortedElements.reserve(v->m_elements.size());
      // std::cout << "treating vert ind: " << v->m_index << std::endl;
      // std::cout << "vert ind: " << v->m_index << " has " << v->m_elements.size() << " elements" << std::endl;
      while(v->m_sortedElements.size() != v->m_elements.size()){
        // std::cout << "sorted elem size: " << v->m_sortedElements.size() << std::endl;
        Element *nextElem = NULL;
        for(Element *elem: edgCurrent->getElements()){
          if(edgCurrent->getLocIndexInElem(elem) == v->getLocIndexInElem(elem)){
            v->m_sortedEdges.push_back(edgCurrent);
            v->m_sortedElements.push_back(elem);
            nextElem = elem;
            break;
          }
        }
        if(nextElem){
          int locIndNextEdge = (edgCurrent->getLocIndexInElem(nextElem) + nextElem->getNumEdges() - 1)%nextElem->getNumEdges();
          edgCurrent = nextElem->getEdge(locIndNextEdge);
          if(edgCurrent->getElements().size() == 1)
            v->m_sortedEdges.push_back(edgCurrent);
        }
        else{
          std::cout << "Error in ordering edges and elements" << std::endl;
          std::cout << nextElem << std::endl;
          exit(0);
        }
      }
    }

    _buildNeighbourElements();
    _buildLineGroups();
  }

  void Mesh::_buildNeighbourElements(){
    for(Element *e: m_elements){
      for(Edge *edg: e->m_edges){
        Element *neighElem = NULL;
        for(Element *eTest: edg->m_elements)
          if(eTest->getIndex() != e->getIndex()){
            e->m_neighbourElements.push_back(eTest);
          }
      }
    }
  }

  void Mesh::_buildLineGroups(){
    m_lineGroups.clear();
    std::vector<bool> lineTreated(m_lines.size(), false);

    std::queue<Element*> lineQueue;
    if(m_lines.size() > 0){
      lineQueue.push(m_lines[0]);
      lineTreated[m_lines[0]->getIndex()] = true;
    }
    std::vector<Element*> currentLineGroup;

    while(lineQueue.size() > 0){
      while(lineQueue.size() > 0){
        Element *l = lineQueue.front();
        lineQueue.pop();
        currentLineGroup.push_back(l);
        for(Vertex *v: l->getVertices())
          if(v->m_lines.size() == 2 && !v->isGeoNode())
            for(Element *lNext: v->m_lines)
              if(lNext->getIndex() != l->getIndex() && !lineTreated[lNext->getIndex()]){
                lineQueue.push(lNext);
                lineTreated[lNext->getIndex()] = true;
              }
      }
      m_lineGroups.push_back(currentLineGroup);
      currentLineGroup.clear();
      for(Element *l: m_lines)
        if(!lineTreated[l->getIndex()]){
          lineQueue.push(l);
          lineTreated[l->getIndex()] = true;
          break;
        }
    }
    std::cout << "n line groups: " << m_lineGroups.size() << std::endl;

  }

  void Mesh::_checkSanity(){
    //Checks for dbg
    std::cout << "Checking mesh sanity" << std::endl;
    for(Element *e: m_elements){
      //Check number of edge el
      if(e->m_edges.size() != 3){
        std::cout << "Problem number edges: " << e->m_edges.size() << std::endl;
        exit(0);
      }
      for(size_t k=0; k<3; k++){
        Edge *edg = e->m_edges[k];
        //Check edges per el ordering
        bool isOrderOk = false;
        if(edg->m_vertices[0]->getGmshTag() == e->m_vertices[k]->getGmshTag())
          if(edg->m_vertices[1]->getGmshTag() == e->m_vertices[(k+1)%3]->getGmshTag())
            isOrderOk = true;
        if(edg->m_vertices[1]->getGmshTag() == e->m_vertices[k]->getGmshTag())
          if(edg->m_vertices[0]->getGmshTag() == e->m_vertices[(k+1)%3]->getGmshTag())
            isOrderOk = true;
        if(!isOrderOk){
          std::cout << "problem in ordering edges" << std::endl;
          exit(0);
        }
        //Check if duplicate edge on el
        bool edgDuplicate = false;
        for(size_t l=0; l<3; l++){
          if(l!=k){
            Edge *edg2 = e->m_edges[l];
            if(edg->m_vertices[0]->getGmshTag() == edg2->m_vertices[0]->getGmshTag())
              if(edg->m_vertices[1]->getGmshTag() == edg2->m_vertices[1]->getGmshTag())
                edgDuplicate = true;
            if(edg->m_vertices[1]->getGmshTag() == edg2->m_vertices[0]->getGmshTag())
              if(edg->m_vertices[0]->getGmshTag() == edg2->m_vertices[1]->getGmshTag())
                edgDuplicate = true;
          }
        }
        if(edgDuplicate){
          std::cout << "One edg is duplicated" << std::endl;
          exit(0);
        }
      }
      //Reset gmsh indices (not tags)
      for(Vertex *v: m_vertices)
        v->m_v->setIndex(-1);
    }
  }
  
  Mesh::~Mesh(){

  }

  void MeshRefiner::refineMesh(const std::vector<size_t> &indicesElemToRefine){
    std::vector<Element*> coarseElemToRefineUnmodified;
    coarseElemToRefineUnmodified.reserve(indicesElemToRefine.size());
    for(size_t indEl: indicesElemToRefine)
      coarseElemToRefineUnmodified.push_back(m_origMesh->m_elements[indEl]);
      
    std::vector<bool> coarseElementsRefined(m_origMesh->m_elements.size(), false);
    //Flag elements to refine fractal
    std::vector<bool> flagElemToRefine;
    flagElemToRefine.resize(m_origMesh->m_elements.size(), false);
    //Add one layer to elements to refine 
    for(size_t indE: indicesElemToRefine){
      flagElemToRefine[indE] = true;
      for(Vertex *v: m_origMesh->m_elements[indE]->getVertices()){
        for(Element *e: v->getOrientedElements())
          flagElemToRefine[e->getIndex()] = true;
      }
      // for(Element *e: m_origMesh->m_elements[indE]->getNeighboursElements()){
      //   flagElemToRefine[e->getIndex()] = true;
      // }
    }
    //Add elements having 2 neighbours to be refined
    bool flagModified = true;
    while(flagModified){
      flagModified = false;
      for(Element *e: m_origMesh->m_elements){
        if(!flagElemToRefine[e->getIndex()]){
          int nNeigToRefine = 0;
          for(Element *eNeig: e->getNeighboursElements())
            if(flagElemToRefine[eNeig->getIndex()])
              nNeigToRefine++;
          if(nNeigToRefine > 1){
            flagElemToRefine[e->getIndex()] = true;
            flagModified = true;
          }
        }
      }
    }
    //Store elements to refine fractal
    std::vector<Element*> elementsFractalRefine;
    elementsFractalRefine.reserve(m_origMesh->m_elements.size());
    for(Element *e: m_origMesh->m_elements)
      if(flagElemToRefine[e->getIndex()])
        elementsFractalRefine.push_back(e);
    elementsFractalRefine.shrink_to_fit();
    //Store pairs (element to refine half split, localIndexEdg).
    std::vector<std::pair<Element*, int>> elementsHalfRefine;
    elementsHalfRefine.reserve(m_origMesh->m_elements.size());
    for(Element *e: elementsFractalRefine){
      for(Element *eNeigh: e->getNeighboursElements())
        if(!flagElemToRefine[eNeigh->getIndex()]){
          Edge *commonEdg = eNeigh->getCommonEdge(e);
          elementsHalfRefine.push_back(std::make_pair(eNeigh, commonEdg->getLocIndexInElem(eNeigh)));
        }
    }
    elementsHalfRefine.shrink_to_fit();
    //Flag edges to be split
    std::vector<bool> edgesToSplit(m_origMesh->m_edges.size(), false);

    for(Element *e: elementsFractalRefine)
      for(Edge*edg: e->getEdges())
        edgesToSplit[edg->getIndex()] = true;
    // std::cout << "N fractal elements: " << elementsFractalRefine.size() << std::endl;
    // std::cout << "gmsh tag element to split: " << elementsFractalRefine[0]->getGmshTag() << std::endl;
    int cpt= 0;
    for(bool isRef: edgesToSplit)
      if(isRef)
        cpt++;
    // std::cout << "edges to split size: " << cpt << std::endl;
    for(auto &kv: elementsHalfRefine)
      edgesToSplit[kv.first->getEdge(kv.second)->getIndex()] = true;
    //Create new vertices which will be added to refined mesh
    std::vector<Vertex*> newVertices(m_origMesh->m_edges.size(), NULL);
    for(size_t k=0; k<m_origMesh->m_edges.size(); k++)
      if(edgesToSplit[k]){
        Edge *e = m_origMesh->m_edges[k];
        std::vector<double> coords = e->getBarycenter();
        MVertex *newGmshV = new MVertex(coords[0], coords[1], coords[2]);
        Mesh::hangingGmshVerticesCollector.push_back(newGmshV);
        newVertices[k] = Vertex::create(newGmshV);
      }
    //TODO: add new vertices to refined mesh
    int cpt2 = 0;
    for(Vertex *v: newVertices){
      if(v){
        cpt2++;
        m_refinedMesh->m_vertices.push_back(v);
        v->m_index = m_refinedMesh->m_vertices.size() - 1;
        // std::cout << "index: " << v->m_index << std::endl;
        v->m_v->setIndex(v->m_index);
      }
    }
    // std::cout << "n new vertices: " << cpt2 << std::endl;
    // std::cout << "n lines in refined mesh before splitting: " << m_refinedMesh->m_lines.size()<<std::endl;;
    //For element creation and memory management
    GModel *gm = GModel::current();
    MElementFactory elemfact;
    //Create new lines
    for(Edge *edg: m_origMesh->getEdges()){
      if(edgesToSplit[edg->getIndex()] && edg->getNumLines() > 0){
        Element *l = edg->getLines()[0];
        std::vector<Vertex*> elemParentVertices = l->getVertices();
        std::vector<Vertex*> refinedElemParentVertices;
        refinedElemParentVertices.reserve(elemParentVertices.size());
        for(Vertex *v: elemParentVertices)
          refinedElemParentVertices.push_back(m_refinedMesh->m_vertices[v->getIndex()]);
        std::vector<Vertex*> allVertices; allVertices.reserve(elemParentVertices.size() + 1);
        for(Vertex *v: refinedElemParentVertices)
          allVertices.push_back(v);
        allVertices.push_back(newVertices[edg->getIndex()]);
        std::vector<std::vector<int>> locIndLineSplitting{{0,2},{2,1}};
        for(size_t k=0; k<locIndLineSplitting.size(); k++){
          std::vector<int> locInds = locIndLineSplitting[k];
          std::vector<Vertex *> verts{allVertices[locInds[0]], allVertices[locInds[1]]};
          std::vector<MVertex*> gmshVerts;
          gmshVerts.reserve(verts.size());
          for(Vertex *v: verts){
            gmshVerts.push_back(v->m_v);
          }
          MElement *newGmshElem = elemfact.create(l->m_e->getTypeForMSH(), gmshVerts);
          for(auto ged: gm->getEdges()){//TODO: this is temporary, we have to add new elements to the good face. Let Gmsh handle memory for Elements created
            ged->addElement(newGmshElem);
            break;
          }
          Mesh::hangingGmshElementsCollector.push_back(newGmshElem);

          Element *myE = Element::create(m_refinedMesh, newGmshElem);
          if(k == 0){
            m_refinedMesh->m_lines[l->getIndex()] = myE;
            myE->m_index = l->getIndex();
          }
          else{
            m_refinedMesh->m_lines.push_back(myE);
            myE->m_index = m_refinedMesh->m_lines.size()-1;
          }
        }
      }
    }
    //Create new elements for fractal refinement
    std::vector<std::vector<int>> locIndFractalSplitting{{3,4,5},{0,3,5},{3,1,4},{5,4,2}};
    // std::cout << "flag0" << std::endl;
    for(Element *e: elementsFractalRefine){
      coarseElementsRefined[e->getIndex()] = true;
      std::vector<Vertex*> elemParentVertices = e->getVertices();
      std::vector<Vertex*> refinedElemParentVertices;
      refinedElemParentVertices.reserve(elemParentVertices.size());
      for(Vertex *v: elemParentVertices)
        refinedElemParentVertices.push_back(m_refinedMesh->m_vertices[v->getIndex()]);
      
      std::vector<Vertex*> allVertices; allVertices.reserve(elemParentVertices.size() + e->getNumEdges());
      for(Vertex *v: refinedElemParentVertices)//TODO: change, it's wrong. Has to be refined mesh vertices. Looks right to me
        allVertices.push_back(v);
      // std::cout << "flag1" << std::endl;
      for(Edge *edg: e->getEdges())
        allVertices.push_back(newVertices[edg->getIndex()]);
      
      for(size_t k=0; k<locIndFractalSplitting.size(); k++){
        std::vector<int> locInds = locIndFractalSplitting[k];
        std::vector<Vertex *> verts{allVertices[locInds[0]], allVertices[locInds[1]], allVertices[locInds[2]]};
        std::vector<MVertex*> gmshVerts;
        gmshVerts.reserve(verts.size());
        // std::cout << "---" << std::endl;
        for(Vertex *v: verts){
          gmshVerts.push_back(v->m_v);
          // std::cout << "index: " << v->m_v->getIndex() << std::endl;
        }
        MElement *newGmshElem = elemfact.create(e->m_e->getTypeForMSH(), gmshVerts);
        for(auto gf: gm->getFaces()){//TODO: this is temporary, we have to add new elements to the good face. Let Gmsh handle memory for Elements created
          gf->addElement(newGmshElem);
          break;
        }
        Mesh::hangingGmshElementsCollector.push_back(newGmshElem);

        Element *myE = Element::create(m_refinedMesh, newGmshElem); //Attention: have to set gmsh index properly for using this function
        //TODO: add new elements to refined mesh
        if(k == 0){
          m_refinedMesh->m_elements[e->getIndex()] = myE;
          myE->m_index = e->getIndex();
        }
        else{
          m_refinedMesh->m_elements.push_back(myE);
          myE->m_index = m_refinedMesh->m_elements.size()-1;
        }
        e->m_childElem.push_back(myE);
        myE->m_childType = Element::CHILDTYPE::FRACTAL;
        myE->m_childID = k;
        myE->m_parentElem = e;
      }
    }
    // std::cout << "flag2.1" << std::endl;
    //Create new elements for helf splitting
    for(auto &kv: elementsHalfRefine){
      Element *e = kv.first;
      coarseElementsRefined[e->getIndex()] = true;
      int locIndEdg = kv.second;
      Edge *edgSplit = e->getEdge(locIndEdg);
      int nEdges = e->getNumEdges();
      std::vector<Vertex*> elemParentVertices = e->getVertices();
      int nVerts = elemParentVertices.size();
      std::vector<Vertex*> refinedElemParentVertices;
      refinedElemParentVertices.reserve(elemParentVertices.size());
      for(Vertex *v: elemParentVertices)
        refinedElemParentVertices.push_back(m_refinedMesh->m_vertices[v->getIndex()]);
      
      std::vector<Vertex*> allVertices; allVertices.reserve(elemParentVertices.size() + 1);
      for(Vertex *v: refinedElemParentVertices)
        allVertices.push_back(v);
      allVertices.push_back(newVertices[edgSplit->getIndex()]);

      std::vector<std::vector<int>> locIndHalfSplitting{{locIndEdg, nVerts, (locIndEdg+2)%nEdges},
                                                        {nVerts, (locIndEdg+1)%nEdges, (locIndEdg+2)%nEdges}};
      for(size_t k=0; k<locIndHalfSplitting.size(); k++){
        std::vector<int> locInds = locIndHalfSplitting[k];
        std::vector<Vertex *> verts{allVertices[locInds[0]], allVertices[locInds[1]], allVertices[locInds[2]]};
        std::vector<MVertex*> gmshVerts;
        gmshVerts.reserve(verts.size());
        // std::cout << "---" << std::endl;
        for(Vertex *v: verts){
          gmshVerts.push_back(v->m_v);
          // std::cout << "index: " << v->m_v->getIndex() << std::endl;
        }
        MElement *newGmshElem = elemfact.create(e->m_e->getTypeForMSH(), gmshVerts);
        for(auto gf: gm->getFaces()){//TODO: this is temporary, we have to add new elements to the good face. Let Gmsh handle memory for Elements created
          gf->addElement(newGmshElem);
          break;
        }
        Mesh::hangingGmshElementsCollector.push_back(newGmshElem);

        Element *myE = Element::create(m_refinedMesh, newGmshElem); //Attention: have to set gmsh index properly for using this function
        if(k == 0){
          m_refinedMesh->m_elements[e->getIndex()] = myE;
          myE->m_index = e->getIndex();
        }
        else{
          m_refinedMesh->m_elements.push_back(myE);
          myE->m_index = m_refinedMesh->m_elements.size()-1;
        }
        e->m_childElem.push_back(myE);
        switch(locIndEdg){
        case 0:
          myE->m_childType = Element::CHILDTYPE::HALF0;
          break;
        case 1:
          myE->m_childType = Element::CHILDTYPE::HALF1;
          break;
        case 2:
          myE->m_childType = Element::CHILDTYPE::HALF2;
          break;
        default:
          std::cout << "Error determining CHILDTYPE for HALF refinement" << std::endl;
          exit(0);
        }
        myE->m_childID = k;
        myE->m_parentElem = e;
      }
    }
    // std::cout << "flag2.2" << std::endl;
    //TODO: dont forget to store child type and element parent!!
    gm->rebuildMeshElementCache();

    //Build refined mesh structure
    // std::cout << "flag3" << std::endl;
    std::cout << "nElements orig: " << m_origMesh->m_elements.size() << std::endl;
    std::cout << "nVertices orig: " << m_origMesh->m_vertices.size() << std::endl;
    std::cout << "nElements: " << m_refinedMesh->m_elements.size() << std::endl;
    std::cout << "nVertices: " << m_refinedMesh->m_vertices.size() << std::endl;
    size_t nMaxEdges = 0;
    for(Element *e: m_refinedMesh->m_elements)
      nMaxEdges += e->getNumEdges();
    for(Element *l: m_refinedMesh->m_lines)
      nMaxEdges += l->getNumEdges();
    // std::cout << "flag4" << std::endl;
    m_refinedMesh->_buildStructure(nMaxEdges);
    // std::cout << "flag5" << std::endl;
    m_refinedMesh->_checkSanity();

    //Store coarse elements not refined
    for(Element *e: m_origMesh->m_elements)
      if(coarseElementsRefined[e->getIndex()]){
        for(Element *eChild: e->m_childElem)
          m_fineElemRefined.push_back(eChild);
        m_coarseElemRefined.push_back(e);
      }
      else{
        m_coarseElemNotRefined.push_back(e);
      }

    //Store Edges of elements to refine unmodified
    std::vector<bool> isEdgToStore;
    isEdgToStore.resize(m_refinedMesh->m_edges.size(), false);
    for(Element *e: coarseElemToRefineUnmodified)
      for(Element *eFine: e->getChildren()){
        m_fineElemRefinedUnmodified.push_back(eFine);
        for(Edge *edg: eFine->getEdges())
          isEdgToStore[edg->getIndex()] = true;
      }

    for(size_t k=0; k<m_refinedMesh->m_edges.size(); k++)
      if(isEdgToStore[k])
        m_edgesElemRefinedUnmodified.push_back(m_refinedMesh->m_edges[k]);
      else
        m_edgesElemRefinedUnmodifiedBar.push_back(m_refinedMesh->m_edges[k]);
    
    //Store common edges (pointers from corase mesh)
    std::vector<bool> isCoarseCommonEdges(m_origMesh->m_edges.size(), false);
    std::vector<bool> isFineCommonEdges(m_refinedMesh->m_edges.size(), false);
    for(Element *e: m_coarseElemNotRefined){
      for(Edge *edg: e->getEdges())
        isCoarseCommonEdges[edg->getIndex()] = true;
      Element *eFine = m_refinedMesh->m_elements[e->getIndex()];
      for(Edge *edg: eFine->getEdges()){
        isFineCommonEdges[edg->getIndex()] = true;
      }
    }
    for(Edge *edg: m_origMesh->getEdges())
      if(isCoarseCommonEdges[edg->getIndex()])
        m_coarseCommonEdges.push_back(edg);
    for(Edge *edg: m_refinedMesh->getEdges())
      if(isFineCommonEdges[edg->getIndex()])
        m_fineCommonEdges.push_back(edg);
  }
}
