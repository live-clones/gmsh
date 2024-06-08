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
    FrameField(Mesh *m): m_m(m){}
    ~FrameField(){}

    void generate(){
      ObjectiveFunction *GLobj;
      DirichletEnergieVectCR *dirichletEner = new DirichletEnergieVectCR(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      ObjectiveFunction *frameConstr;
      //Create objective functions
      if(std::is_same<T, GLIso2D>::value){
        double penaltyGL = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
        frameConstr = new GLframeConstraint(penaltyGL, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else if(std::is_same<T, OdecoIso2D>::value){
        // GLobj = dirichletEner;
        double penalty = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
        frameConstr = new OdecoIso2DConstraint(penalty, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else if(std::is_same<T, OdecoAniso2D>::value){
        double penalty = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
        // double penalty = 10.0;
        frameConstr = new OdecoAniso2DConstraint(penalty, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else{
        std::cout << "Unknown frame type" << std::endl;
      }
      GLobj = *dirichletEner + *frameConstr;
      // GLobj = dirichletEner;
      // GLobj = frameConstr;

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
        }
        else if(std::is_same<T, OdecoAniso2D>::value){
          solInitEdge.resize(5, 0.0);
          solInitEdge[0] = 1.0;
          // std::vector<double> customFrame(5, 0.0);
          // double norm0 = 2.0;
          // double norm1 = 1.0;
          // double theta = 0.0;
          // customFrame[0] = (norm0 + norm1)*3*sqrt(2*M_PI)/8.0;
          // customFrame[1] = (norm0 - norm1)*cos(2*theta)*sqrt(M_PI)/2.0;
          // customFrame[2] = (norm0 - norm1)*sin(2*theta)*sqrt(M_PI)/2.0;
          // customFrame[3] = (norm0 + norm1)*cos(4*theta)*sqrt(M_PI)/8.0;
          // customFrame[4] = (norm0 + norm1)*sin(4*theta)*sqrt(M_PI)/8.0;
          // solInitEdge = customFrame;
        }
        sol[e] = solInitEdge;
      }
      for(Element *l: m_m->getLines()){
        Edge* e=l->getEdge(0);
        std::vector<std::vector<double>> dirBC;
        dirBC.resize(1);
        dirBC[0] = e->getDir();
        T f(dirBC);
        for(int k=0; k<T::nUnknown; k++)
          s.addBCDirichlet(std::make_pair(e, k), f.m_frame[k]);
        sol[e] = f.m_frame;//Put BC in initial solution
        // std::vector<double> customFrame(5, 0.0);
        // double norm0 = 2.0;
        // double norm1 = 1.0;
        // double theta = 0.0;
        // customFrame[0] = (norm0 + norm1)*3*sqrt(2*M_PI)/8.0;
	// customFrame[1] = (norm0 - norm1)*cos(2*theta)*sqrt(M_PI)/2.0;
	// customFrame[2] = (norm0 - norm1)*sin(2*theta)*sqrt(M_PI)/2.0;
	// customFrame[3] = (norm0 + norm1)*cos(4*theta)*sqrt(M_PI)/8.0;
	// customFrame[4] = (norm0 + norm1)*sin(4*theta)*sqrt(M_PI)/8.0;
        // for(int k=0; k<T::nUnknown; k++)
        //   s.addBCDirichlet(std::make_pair(e, k), customFrame[k]);
        // sol[e] = customFrame;
      }

      s.solveLBFGS(sol); //compute framefield
      s.printInfos();
      for(const auto &kv: sol){ //Store solution
        m_mapEdgeFrames[kv.first] = T(kv.second);
      }
      
      ObjectiveFunction::clearAll();
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
  
  private:
    Mesh *m_m;
    std::map<Edge*, T> m_mapEdgeFrames;
    
  };
}
