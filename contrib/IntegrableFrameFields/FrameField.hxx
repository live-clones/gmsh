// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <odecoFrames.hxx>
#include <IffTools.hxx>
#include <Visualization.hxx>
#include <ObjectiveFunctions.hxx>
#include <Solver.hxx>
#include <random>

namespace IFF{
  template <class T>
  class FrameField{
    static_assert(std::is_base_of<Frame, T>::value, "FrameField<T>: T must derive from Frame");
    
  public:
    FrameField(Mesh *m): m_m(m){
      m_dirichletEnergy = new DirichletEnergieVectCR(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      if(std::is_same<T, GLIso2D>::value){
        m_frameConstraint = new GLframeConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_integrabilityEnergy = new DirichletEnergieVectCR(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else if(std::is_same<T, OdecoIso2D>::value){
        m_frameConstraint = new OdecoIso2DConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_integrabilityEnergy = new LBOdecoIso2D(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else if(std::is_same<T, OdecoAniso2D>::value){
        m_frameConstraint = new OdecoAniso2DConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_integrabilityEnergy = new LBOdecoAniso2D(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else{
        std::cout << "IFF::FrameField: unknown frame type" << std::endl;
        exit(0);
      }
    }
    ~FrameField(){}

    void generate(){
      // double penaltyConstraint = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
      // double h = m_m->getMaxEdgeLength()*0.5;
      double h = m_m->getMaxEdgeLength();
      double penaltyConstraint = 1.0/(4*h*h);
      ObjectiveFunction *GLobj;
      GLobj = *m_dirichletEnergy + *(penaltyConstraint*(*m_frameConstraint));

      //Check gradient for dbg
      double lower_bound = -2;
      double upper_bound = 2;
      std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      std::default_random_engine re;

      for(Element *e: m_m->getElements()){
        std::vector<std::vector<double>> solEl;
        solEl.resize(e->getNumEdges());
        for(auto &v: solEl)
          v.resize(T::nUnknown);
        for(size_t nTry=0; nTry<2; nTry++){
          for(size_t iN=0; iN<3; iN++)
            for(size_t iF=0; iF<T::nUnknown; iF++){
              solEl[iN][iF] = unif(re);
            }
          std::cout << "------" << std::endl;
          GLobj->checkGradient(e, solEl);
        }
        break;
      }

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      for(Edge* e: m_m->getEdges()){
        std::vector<double> solInitEdge;
        if(std::is_same<T, GLIso2D>::value){
          solInitEdge.resize(2, 0.0);
          solInitEdge[0] = 1.0;
        }
        else if(std::is_same<T, OdecoIso2D>::value){
          solInitEdge.resize(3, 0.0);
          solInitEdge[0] = 1.0;
          solInitEdge[1] = 1.0;
        }
        else if(std::is_same<T, OdecoAniso2D>::value){
          solInitEdge.resize(5, 0.0);
          solInitEdge[0] = 1.0;
        }
        sol[e] = solInitEdge;
      }
      for(Element *l: m_m->getLines()){
        Edge* e=l->getEdge(0);
        std::vector<std::vector<double>> dirBC;
        dirBC.resize(1);
        dirBC[0].resize(2, 0.0);
        dirBC[0][0] = 1.0, dirBC[0][1] = 0.0;
        T f(dirBC);
        for(int k=0; k<T::nUnknown; k++)
          s.addBCDirichlet(std::make_pair(e, k), f.m_frame[k]);
        sol[e] = f.m_frame;//Put BC in initial solution
      }

      s.solveLBFGS(sol); //compute framefield
      s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
    }

    void generateIntegrableFrameField(){
      // double penaltyConstraint = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
      // double h = m_m->getMaxEdgeLength()*0.5;
      double h = m_m->getMaxEdgeLength();
      double penaltyConstraint = 1.0/(4*h*h);
      ObjectiveFunction *GLobj;
      GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));
      
      //Check gradient for dbg
      double lower_bound = -2;
      double upper_bound = 2;
      std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      std::default_random_engine re;

      for(Element *e: m_m->getElements()){
        std::vector<std::vector<double>> solEl;
        solEl.resize(e->getNumEdges());
        for(auto &v: solEl)
          v.resize(T::nUnknown);
        for(size_t nTry=0; nTry<2; nTry++){
          for(size_t iN=0; iN<3; iN++)
            for(size_t iF=0; iF<T::nUnknown; iF++){
              solEl[iN][iF] = unif(re);
            }
          for(auto &v: solEl)
            std::cout << v.size()<< std::endl;
          GLobj->checkGradient(e, solEl);
        }
        break;
      }

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      for(Edge* e: m_m->getEdges()){
        sol[e] = m_mapEdgeFrames[e].m_frame;
      }
      for(Element *l: m_m->getLines()){
        Edge* e=l->getEdge(0);
        std::vector<std::vector<double>> dirBC;
        dirBC.resize(1);
        dirBC[0].resize(2, 0.0);
        dirBC[0][0] = 1.0, dirBC[0][1] = 0.0;
        T f(dirBC);
        for(int k=0; k<T::nUnknown; k++)
          s.addBCDirichlet(std::make_pair(e, k), f.m_frame[k]);
        sol[e] = f.m_frame;//Put BC in initial solution
      }
      // std::vector<double> schedule{0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
      std::vector<double> schedule{1.0};
      for(double gamma: schedule){
        GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        s.setObjectiveFunction(GLobj);
        s.solveLBFGS(sol); //compute framefield
      }
      s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
      _generateIntegrableFrameFieldImposedDIrections();
    }

    void _generateIntegrableFrameFieldImposedDIrections(){
      // double penaltyConstraint = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
      // double h = m_m->getMaxEdgeLength()*0.5;
      double h = m_m->getMaxEdgeLength();
      double penaltyConstraint = 1.0/(4*h*h);
      ObjectiveFunction *GLobj;
      GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));
      
      //Check gradient for dbg
      double lower_bound = -2;
      double upper_bound = 2;
      std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      std::default_random_engine re;

      for(Element *e: m_m->getElements()){
        std::vector<std::vector<double>> solEl;
        solEl.resize(e->getNumEdges());
        for(auto &v: solEl)
          v.resize(T::nUnknown);
        for(size_t nTry=0; nTry<2; nTry++){
          for(size_t iN=0; iN<3; iN++)
            for(size_t iF=0; iF<T::nUnknown; iF++){
              solEl[iN][iF] = unif(re);
            }
          for(auto &v: solEl)
            std::cout << v.size()<< std::endl;
          GLobj->checkGradient(e, solEl);
        }
        break;
      }

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      for(Edge* e: m_m->getEdges()){
        sol[e] = m_mapEdgeFrames[e].m_frame;
        if(e->getLines().size() == 0){
          std::vector<double> dirBC = e->getDir();
          std::vector<std::vector<double>> mat = T::getAlignmentLinConstr(dirBC);
          std::vector<double> vect; vect.resize(mat.size(), 0.0);
          std::vector<std::pair<Edge*, int>> pairEdgeField;
          pairEdgeField.reserve(T::nUnknown);
          for(size_t k=0; k<T::nUnknown; k++)
            pairEdgeField.push_back(std::make_pair(e, k));
          s.addBCLinearCombination(mat, vect, pairEdgeField);
        }
        else
          for(size_t k=0; k<T::nUnknown; k++)
            s.addBCDirichlet(std::make_pair(e, k), m_mapEdgeFrames[e].m_frame[k]);
      }
      // for(Element *l: m_m->getLines()){
      //   Edge* e=l->getEdge(0);
      //   std::vector<std::vector<double>> dirBC;
      //   dirBC.resize(1);
      //   dirBC[0].resize(2, 0.0);
      //   dirBC[0][0] = 1.0, dirBC[0][1] = 0.0;
      //   T f(dirBC);
      //   for(int k=0; k<T::nUnknown; k++)
      //     s.addBCDirichlet(std::make_pair(e, k), f.m_frame[k]);
      //   sol[e] = f.m_frame;//Put BC in initial solution
      // }
      // std::vector<double> schedule{0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
      std::vector<double> schedule{1.0};
      for(double gamma: schedule){
        GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        s.setObjectiveFunction(GLobj);
        s.solveLBFGS(sol); //compute framefield
      }
      s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
    }
    
    std::map<Element *, std::vector<std::vector<double>>> getDirectionsPerElem(){
      std::map<Element *, std::vector<std::vector<double>>> mapElemDir;
      for(Element *e: m_m->getElements()){
        int m_nFields = T::nUnknown;
        int nEdges = e->getNumEdges();
      
        std::vector<std::vector<double>> solEl;
        solEl.resize(nEdges);
        for(size_t l=0; l<solEl.size(); l++)
          solEl[l].resize(m_nFields, 0.0);

        for(size_t l=0; l<solEl.size(); l++)
          solEl[l] = m_mapEdgeFrames[e->getEdge(l)].m_frame;

        std::vector<double> vRef = e->getDirEdg(0);
        std::vector<double> n = e->getNormal();
        std::vector<double> t = tools::crossprod(n, vRef);

        std::vector<std::vector<double>> solTriRotated;
        T::getRotatedSolEl(e, solEl, solTriRotated);

        std::vector<std::vector<double>> dirsEdges;
        dirsEdges.resize(3);
        for(auto &v: dirsEdges)
          v.resize(3*4, 0.0);
        for(size_t iEdg=0; iEdg<e->getNumEdges(); iEdg++){
          T frame(solTriRotated[iEdg]);
          std::vector<std::vector<double>> dirs = frame.getDirectionsFromRef(vRef, n);
          for(size_t k=0; k<dirs.size(); k++){
            for(size_t iX=0; iX<3; iX++){
              dirsEdges[iEdg][3*k+iX] = dirs[k][iX];
            }
          }
        }
        mapElemDir[e] = dirsEdges;
      }
      return mapElemDir;
    }

    std::map<Element*, double> getIntegrabilityErrorDensity(){
      std::map<Element*, double> mapError;
      int nFields = T::nUnknown;
      for(Element *e: m_m->getElements()){
        int nEdges = e->getNumEdges();
        std::vector<std::vector<double>> solEl;
        solEl.resize(nEdges);
        for(size_t l=0; l<solEl.size(); l++)
          solEl[l].resize(nFields, 0.0);

        for(size_t l=0; l<solEl.size(); l++){
          solEl[l] = m_mapEdgeFrames[e->getEdge(l)].m_frame;
        }
        
        double valFunc = 0.0;
        m_integrabilityEnergy->evaluateFunction(e, solEl, valFunc);
        mapError[e] = valFunc/e->getArea();
      }
      return mapError;
    }

    void _locateSingularitiesVertices(){// Old version, seems to not work when looking for sing on vertices. Probably normal
      if(m_mapEdgeFrames.size() == 0){
        std::cout << "IFF::FrameField::_locateSingularities: no framefield sorted, exiting." << std::endl;
        exit(0);
      }
      else{
        std::vector<T*> edgeIndToFrame;
        edgeIndToFrame.resize(m_mapEdgeFrames.size());
        for(auto &kv: m_mapEdgeFrames)
          edgeIndToFrame[kv.first->getIndex()] = &(kv.second);
        
        for(Vertex *v: m_m->getVertices()){
          if(v->getOrientedElements().size() == 0){
            std::cout << "no edges for vertex" << std::endl;
            exit(0);
          }
          if(v->getOrientedElements().size() == 0){
            std::cout << "no elements found" << std::endl;
            exit(0);
          }
          std::vector<Element*> orientedElements = v->getOrientedElements();
          // Element *currentElem = orientedElements[0];

          int indDirInit = 0;
          std::vector<double> dirInit;
          std::vector<double> dirRef;
          std::vector<double> edgRefTransport;
          std::vector<std::vector<double>> dirsInitTransport;
          Element *previousElem = NULL;
          for(Element *elem: orientedElements){
            int nEdges = elem->getNumEdges();
            
            std::vector<std::vector<double>> solEl;
            solEl.resize(nEdges);
            for(size_t l=0; l<solEl.size(); l++)
              solEl[l].resize(T::nUnknown, 0.0);

            for(size_t l=0; l<solEl.size(); l++)
              solEl[l] = edgeIndToFrame[elem->getEdge(l)->getIndex()]->m_frame;

            std::vector<double> vRef = elem->getDirEdg(0);
            std::vector<double> n = elem->getNormal();
            std::vector<double> t = tools::crossprod(n, vRef);

            std::vector<std::vector<double>> solTriRotated;
            T::getRotatedSolEl(elem, solEl, solTriRotated);

            int locIndVInCurrentElem = v->getLocIndexInElem(elem);
            // Edge* edgCurrent = currentElem->getEdge(locIndVInCurrentElem);
            // Edge* edgNext = currentElem->getEdge((locIndVInCurrentElem+nEdges-1)%nEdges);
            int indEdgCurrent = locIndVInCurrentElem;
            int indEdgNext = (locIndVInCurrentElem+nEdges-1)%nEdges;

            // T *frameCurrent = edgeIndToFrame[edgCurrent->getIndex()];
            // T *frameNext = edgeIndToFrame[edgNext->getIndex()];
            T frameCurrent(solTriRotated[indEdgCurrent]);
            T frameNext(solTriRotated[indEdgNext]);

            if(indDirInit == 0){
              std::vector<std::vector<double>> dirsCurrent = frameCurrent.getDirectionsFromRef(vRef, n);
              dirInit = dirsCurrent[indDirInit];
              dirsInitTransport = dirsCurrent;
              dirRef = dirInit;
              edgRefTransport = elem->getDirEdg(locIndVInCurrentElem);
              std::vector<double> currentDir = dirsCurrent[indDirInit];
              indDirInit = 1;
            }
            else{
              dirRef = manifoldTools::transportToNeighbourElement(previousElem, elem, dirRef);
              edgRefTransport = manifoldTools::transportToNeighbourElement(previousElem, elem, edgRefTransport);
              for(std::vector<double> &v: dirsInitTransport)
                v = manifoldTools::transportToNeighbourElement(previousElem, elem, v);
            }
            std::vector<std::vector<double>> dirsNext = frameNext.getDirectionsFromRef(vRef, n);
            std::vector<double> dirNext = tools::getClosestVect(dirsNext, dirRef);

            // if(v->getGmshTag()==63){//DBG
            //   std::cout << "DirRef" << std::endl;
            //   std::cout << dirRef << std::endl;
            //   std::cout << "currentEdg: " << elem->getEdge(indEdgCurrent)->getIndex() << std::endl;
            //   std::cout << "DirsNext" << std::endl;
            //   std::cout << dirsNext << std::endl;
            //   std::cout << "DirNext" << std::endl;
            //   std::cout << dirNext << std::endl;
            //   std::cout << "nextEdg: " << elem->getEdge(indEdgNext)->getIndex() << std::endl;
            // }
            dirRef = dirNext;
            previousElem = elem;
          }
          int indClosest;
          if(!v->isGeometryBoundary()){
            Element *elem = orientedElements[0];
            int nEdges = elem->getNumEdges();

            int locIndVInCurrentElem = v->getLocIndexInElem(elem);
            int indEdgCurrent = locIndVInCurrentElem;
            std::vector<std::vector<double>> solEl;
            solEl.resize(nEdges);
            for(size_t l=0; l<solEl.size(); l++)
              solEl[l].resize(T::nUnknown, 0.0);
            
            for(size_t l=0; l<solEl.size(); l++)
              solEl[l] = edgeIndToFrame[elem->getEdge(l)->getIndex()]->m_frame;

            std::vector<double> vRef = elem->getDirEdg(0);
            std::vector<double> n = elem->getNormal();
            std::vector<double> t = tools::crossprod(n, vRef);

            std::vector<std::vector<double>> solTriRotated;
            T::getRotatedSolEl(elem, solEl, solTriRotated);

            dirRef = manifoldTools::transportToNeighbourElement(previousElem, elem, dirRef);
            T frameCurrent(solTriRotated[indEdgCurrent]);
            std::vector<std::vector<double>> dirsCurrent = frameCurrent.getDirectionsFromRef(vRef, n);
            indClosest = tools::getIndexClosestVect(dirsCurrent, dirRef);
          }
          else{
            Element *elem = orientedElements[orientedElements.size() - 1];
            int nEdges = elem->getNumEdges();

            int locIndVInCurrentElem = v->getLocIndexInElem(elem);
            int indEdgCurrent = (locIndVInCurrentElem + nEdges - 1)%nEdges;
            std::vector<double> dirCurrentEdg = elem->getDirEdg(indEdgCurrent);
            // tools::scale(dirCurrentEdg, -1.0);
            std::vector<double> normal = elem->getNormal();
            double alpha = tools::getAngleRotationAlongDirection(normal, dirCurrentEdg, edgRefTransport);
            std::vector<double> dirRefRotated = tools::rotateAlongDirection(normal, alpha, dirRef);
            indClosest = tools::getIndexClosestVect(dirsInitTransport, dirRefRotated);
            // if(v->getGmshTag() == 456){
            //   std::cout << "alpha: " << alpha << std::endl;
            //   std::cout << "dirEdgTransportes: " << edgRefTransport << std::endl;
            //   std::cout << "dirCurrentEdge: " << dirCurrentEdg << std::endl;
            //   std::cout << "indClosest: " << indClosest << std::endl;
            //   std::cout << "dirRef: " << dirRef << std::endl;
            //   std::cout << "dirInit: " << dirInit << std::endl;
            //   std::cout << "dirsInit: " << dirsInitTransport << std::endl;
              
            //   exit(0);
            // }
          }
          if(indClosest == 1)
            m_singularitiesVertices[v] = 1;
          else if(indClosest == 3)
            m_singularitiesVertices[v] = -1;
          else if(indClosest != 0){
            std::cout << "Unknown singularity type" << std::endl;
            std::cout << indClosest << std::endl;
            m_singularitiesVertices[v] = 0;
          }
        }
      }
      Vertex *v = m_m->getLines()[0]->getVertices()[0];
      std::cout << "vertex: " << v->getGmshTag() << std::endl;
      std::cout << "vertex elements" << std::endl;
      for(Element *e: v->getElements()){
        std::cout << e->getGmshTag() << " ";
      }
      std::cout << std::endl;
      std::cout << "vertex oriented elements" << std::endl;
      for(Element *e: v->getOrientedElements()){
        std::cout << e->getGmshTag() << " ";
      }
      std::cout << std::endl;
      std::cout << "nEdge: " << v->getEdges().size() << ", nEdgesSorted: " << v->getOrientedEdges().size() << std::endl;
    }

    // void _locateSingularities(){//Old version to detex singularities on edges, not working but probably normal
    //   if(m_mapEdgeFrames.size() == 0){
    //     std::cout << "IFF::FrameField::_locateSingularities: no framefield sorted, exiting." << std::endl;
    //     exit(0);
    //   }
    //   else{
    //     std::vector<T*> edgeIndToFrame;
    //     edgeIndToFrame.resize(m_mapEdgeFrames.size());
    //     for(auto &kv: m_mapEdgeFrames)
    //       edgeIndToFrame[kv.first->getIndex()] = &(kv.second);

    //     for(Edge *e: m_m->getEdges()){
    //       std::vector<Element*> elements = e->getElements();
    //       if(elements.size() == 2){ //Ignoring boundary of non manifold edges, not relevant for building cutgraph
    //         std::vector<double> dirInit;
    //         std::vector<double> dirRef;
    //         bool haveDirInit = false;
    //         Element *previousElem = NULL;
    //         for(Element *elem: elements){
    //           int nEdges = elem->getNumEdges();
    //           std::vector<std::vector<double>> solEl;
    //           solEl.resize(nEdges);
    //           for(size_t l=0; l<solEl.size(); l++)
    //             solEl[l].resize(T::nUnknown, 0.0);

    //           for(size_t l=0; l<solEl.size(); l++)
    //             solEl[l] = edgeIndToFrame[elem->getEdge(l)->getIndex()]->m_frame;

    //           std::vector<double> vRef = elem->getDirEdg(0);
    //           std::vector<double> n = elem->getNormal();
    //           std::vector<double> t = tools::crossprod(n, vRef);

    //           std::vector<std::vector<double>> solTriRotated;
    //           T::getRotatedSolEl(elem, solEl, solTriRotated);

    //           if(haveDirInit){
    //             dirRef = manifoldTools::transportToNeighbourElement(previousElem, elem, dirRef);
    //           }
    //           int locIndEdgInCurrentElem = e->getLocIndexInElem(elem);
    //           for(size_t k=1; k<nEdges; k++){
    //             int indEdgCurrent = (locIndEdgInCurrentElem+k)%nEdges;
    //             T frameCurrent(solTriRotated[indEdgCurrent]);
    //             std::vector<std::vector<double>> dirsCurrent = frameCurrent.getDirectionsFromRef(vRef, n);
    //             if(haveDirInit){
    //               dirRef = tools::getClosestVect(dirsCurrent, dirRef);
    //             }
    //             else{
    //               dirInit = dirsCurrent[0];
    //               dirRef = dirInit;
    //               haveDirInit = true;
    //             }                
    //           }
    //           previousElem = elem;
    //         }
    //         Element *elem = elements[0];
    //         int nEdges = elem->getNumEdges();
    //         std::vector<std::vector<double>> solEl;
    //         solEl.resize(nEdges);
    //         for(size_t l=0; l<solEl.size(); l++)
    //           solEl[l].resize(T::nUnknown, 0.0);

    //         for(size_t l=0; l<solEl.size(); l++)
    //           solEl[l] = edgeIndToFrame[elem->getEdge(l)->getIndex()]->m_frame;

    //         std::vector<double> vRef = elem->getDirEdg(0);
    //         std::vector<double> n = elem->getNormal();
    //         std::vector<double> t = tools::crossprod(n, vRef);

    //         std::vector<std::vector<double>> solTriRotated;
    //         T::getRotatedSolEl(elem, solEl, solTriRotated);
    //         dirRef = manifoldTools::transportToNeighbourElement(previousElem, elem, dirRef);
    //         int locIndEdgInCurrentElem = e->getLocIndexInElem(elem);
    //         int indEdgCurrent = (locIndEdgInCurrentElem+1)%nEdges;
    //         T frameCurrent(solTriRotated[indEdgCurrent]);
    //         std::vector<std::vector<double>> dirsCurrent = frameCurrent.getDirectionsFromRef(vRef, n);
    //         int indClosest = tools::getIndexClosestVect(dirsCurrent, dirRef);
            
    //         if(indClosest == 1)
    //           m_singularities[e] = 1;
    //         else if(indClosest == 3)
    //           m_singularities[e] = -1;
    //         else if(indClosest != 0){
    //           std::cout << "Unknown singularity type" << std::endl;
    //           std::cout << indClosest << std::endl;
    //           m_singularities[e] = 0;
    //         }
    //       }
    //     }
    //   }
    //   Vertex *v = m_m->getLines()[0]->getVertices()[0];
    //   std::cout << "vertex: " << v->getGmshTag() << std::endl;
    //   std::cout << "vertex elements" << std::endl;
    //   for(Element *e: v->getElements()){
    //     std::cout << e->getGmshTag() << " ";
    //   }
    //   std::cout << std::endl;
    //   std::cout << "vertex oriented elements" << std::endl;
    //   for(Element *e: v->getOrientedElements()){
    //     std::cout << e->getGmshTag() << " ";
    //   }
    //   std::cout << std::endl;
    //   std::cout << "nEdge: " << v->getEdges().size() << ", nEdgesSorted: " << v->getOrientedEdges().size() << std::endl;
    // }

    void _locateSingularities(){
      if(m_mapEdgeFrames.size() == 0){
        std::cout << "IFF::FrameField::_locateSingularities: no framefield sorted, exiting." << std::endl;
        exit(0);
      }
      else{
        std::vector<T*> edgeIndToFrame;
        edgeIndToFrame.resize(m_mapEdgeFrames.size());
        for(auto &kv: m_mapEdgeFrames)
          edgeIndToFrame[kv.first->getIndex()] = &(kv.second);

        for(Element *e: m_m->getElements()){
          int nEdges = e->getNumEdges();
          std::vector<std::vector<double>> solEl;
          solEl.resize(nEdges);
          for(size_t l=0; l<solEl.size(); l++)
            solEl[l].resize(T::nUnknown, 0.0);

          for(size_t l=0; l<solEl.size(); l++)
            solEl[l] = edgeIndToFrame[e->getEdge(l)->getIndex()]->m_frame;

          std::vector<double> vRef = e->getDirEdg(0);
          std::vector<double> n = e->getNormal();
          std::vector<double> t = tools::crossprod(n, vRef);

          std::vector<std::vector<double>> solTriRotated;
          T::getRotatedSolEl(e, solEl, solTriRotated);
          
          T frameEdgeRef(solTriRotated[0]);
          std::vector<std::vector<double>> dirsEdge = frameEdgeRef.getDirectionsFromRef(vRef, n);
          std::vector<double> dirRef = dirsEdge[0];
          for(size_t k=1; k<nEdges; k++){
            T frameCurrent(solTriRotated[k]);
            std::vector<std::vector<double>> dirsCurrent = frameCurrent.getDirectionsFromRef(vRef, n);
            dirRef = tools::getClosestVect(dirsCurrent, dirRef);
          }
          int indClosest = tools::getIndexClosestVect(dirsEdge, dirRef);
          if(indClosest == 1)
            m_singularities[e] = 1;
          else if(indClosest == 3)
            m_singularities[e] = -1;
          else if(indClosest != 0){
            std::cout << "Unknown singularity type" << std::endl;
            std::cout << indClosest << std::endl;
            m_singularities[e] = 0;
          }
        }
      }
      Vertex *v = m_m->getLines()[0]->getVertices()[0];
      std::cout << "vertex: " << v->getGmshTag() << std::endl;
      std::cout << "vertex elements" << std::endl;
      for(Element *e: v->getElements()){
        std::cout << e->getGmshTag() << " ";
      }
      std::cout << std::endl;
      std::cout << "vertex oriented elements" << std::endl;
      for(Element *e: v->getOrientedElements()){
        std::cout << e->getGmshTag() << " ";
      }
      std::cout << std::endl;
      std::cout << "nEdge: " << v->getEdges().size() << ", nEdgesSorted: " << v->getOrientedEdges().size() << std::endl;
    }

    std::map<Element*, double> m_singularities;
    std::map<Vertex*, double> m_singularitiesVertices;
  private:
    Mesh *m_m;
    std::map<Edge*, T> m_mapEdgeFrames;

    
    ObjectiveFunction *m_dirichletEnergy;
    ObjectiveFunction *m_frameConstraint;
    ObjectiveFunction *m_integrabilityEnergy;
    

  };
}
