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
#include <IffTools.hxx>
#include <queue>

namespace IFF{
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.1;};
  double TARGETMESHSIZE(const std::vector<double> &coords){return 10.0;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.5;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.4;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.02*(49.0*(coords[0]+2.0)/4.0 + 1.0);};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 10.0;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.01;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.05*(coords[1] + 1.0);};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.05*(2.0*coords[1] + 1.0);};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.00833*(29.0*coords[1] + 1.0);};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return coords[0]+0.07;};
  
  template <class T>
  class FrameField{
    static_assert(std::is_base_of<Frame, T>::value, "FrameField<T>: T must derive from Frame");
    
  public:
    FrameField(Mesh *m, double factor = 0.0, std::string typeBC = "hardBC"): m_m(m), m_fact(factor), m_typeBC(typeBC){
      m_dirichletEnergy = new DirichletEnergieVectCR(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient, &T::getInvertRotatedHessianAndGradient);
      if(std::is_same<T, GLIso2D>::value){
        m_frameConstraint = new GLframeConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_integrabilityEnergy = new DirichletEnergieVectCR(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else if(std::is_same<T, OdecoIso2D>::value){
        m_frameConstraintSmooth = new OdecoIso2DConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        // m_frameConstraint = new OdecoIso2DConstraintNormalizedWithSmoothWeight(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        // m_frameConstraint = *(5.0*(*(new OdecoIso2DConstraintNormalizedWithSmoothWeight(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient)))) + *(new OdecoIso2DConstraintNormalized(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient));
        // m_frameConstraint = new OdecoIso2DConstraintNormalizedWithLogSmoothWeight(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_frameConstraint = new OdecoIso2DConstraintNormalized(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        
        // m_frameConstraint = new OdecoIso2DConstraintNormalizedNoArea(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        // m_frameConstraint = new OdecoIso2DConstraintNormalizedEdge(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        // m_frameConstraint = new OdecoIso2DConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_integrabilityEnergy = new LBOdecoIso2D(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else if(std::is_same<T, OdecoAniso2D>::value){
        m_frameConstraintSmooth = new OdecoAniso2DConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_frameConstraint = new OdecoAniso2DConstraintNormalized(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
        m_integrabilityEnergy = new LBOdecoAniso2D(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      }
      else{
        std::cout << "IFF::FrameField: unknown frame type" << std::endl;
        exit(0);
      }
      for(Edge *e: m_m->getEdges())
        m_fixedEdges[e] = false;
      // m_typeBC = "smoothBC";
      // m_typeBC = "hardBC";
      _buildSizeBC();
    }
    ~FrameField(){}

    void generateNoComp(){
      double h = m_m->getMaxEdgeLength();
      double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      ObjectiveFunction *GLobj;
      GLobj = *m_dirichletEnergy + *(penaltyConstraint*(*m_frameConstraint));

      // //Check gradient for dbg
      // double lower_bound = -2;
      // double upper_bound = 2;
      // std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      // std::default_random_engine re;

      // for(Element *e: m_m->getElements()){
      //   std::vector<std::vector<double>> solEl;
      //   solEl.resize(e->getNumEdges());
      //   for(auto &v: solEl)
      //     v.resize(T::nUnknown);
      //   for(size_t nTry=0; nTry<2; nTry++){
      //     for(size_t iN=0; iN<3; iN++)
      //       for(size_t iF=0; iF<T::nUnknown; iF++){
      //         solEl[iN][iF] = unif(re);
      //       }
      //     std::cout << "------" << std::endl;
      //     GLobj->checkGradient(e, solEl);
      //   }
      //   break;
      // }

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      _createInitialFrameField(sol);
      for(const auto &kv: m_fixedEdges)
        if(kv.second || kv.first->getLines().size() != 0)
          // _fixFrameOnEdge(&s, kv.first, sol);//DBG notch
          _alignFrameOnEdge(&s, kv.first, sol);

      // s.solveLBFGS(sol); //compute framefield
      // s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
    }

    void generateLaplacianSolution(){
      ObjectiveFunction *GLobj = m_dirichletEnergy;

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
      // _createInitialFrameField(sol, false);
      _createInitialFrameField(sol, true);
      for(const auto &kv: m_fixedEdges)
        if(kv.second || kv.first->getLines().size() != 0)
          _fixFrameOnEdge(&s, kv.first, sol);//DBG notch
      // _alignFrameOnEdge(&s, kv.first, sol);
      // _imposeContinuity(&s);

      std::cout << "+++ --- +++ Generate init laplacian framefield" << std::endl;
      s.solveNewton(sol); //compute framefield
      s.printInfos();
      // for(const auto &kv: sol){ //Store solution
      //   T f = T(kv.second);
      //   f.projectOnCrossManifold();
      //   m_mapEdgeFrames[kv.first] = f;
      // }
      int cpt = 0;
      double qprec = 0.0;
      for(const auto &kv: sol){ //Store solution
        m_mapEdgeFrames[kv.first] = kv.second;
        // if(cpt > 100 && cpt < 110)
        // std::cout << "val: " << kv.second << std::endl;
        // std::cout << "q0 - qprec: " << kv.second[0]-qprec << std::endl;
        qprec = kv.second[0];
        cpt++;
      }
      // exit(0);
    }
    
    void generate(){
      double h = m_m->getMaxEdgeLength();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      // double penaltyConstraint = 1.0/(4*h*h);
      double penaltyConstraint = 1.0;
      ObjectiveFunction *GLobj;
      GLobj = *m_dirichletEnergy + *(penaltyConstraint*(*m_frameConstraintSmooth));

      // //Check gradient for dbg
      // double lower_bound = -2;
      // double upper_bound = 2;
      // std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      // std::default_random_engine re;

      // for(Element *e: m_m->getElements()){
      //   std::vector<std::vector<double>> solEl;
      //   solEl.resize(e->getNumEdges());
      //   for(auto &v: solEl)
      //     v.resize(T::nUnknown);
      //   for(size_t nTry=0; nTry<2; nTry++){
      //     for(size_t iN=0; iN<3; iN++)
      //       for(size_t iF=0; iF<T::nUnknown; iF++){
      //         solEl[iN][iF] = unif(re);
      //       }
      //     std::cout << "------" << std::endl;
      //     GLobj->checkGradient(e, solEl);
      //   }
      //   break;
      // }

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      // _createInitialFrameField(sol, false);
      _createInitialFrameField(sol, true);
      for(const auto &kv: m_fixedEdges)
        if(kv.second || kv.first->getLines().size() != 0)
          _fixFrameOnEdge(&s, kv.first, sol);//DBG notch
          // _alignFrameOnEdge(&s, kv.first, sol);
        // else
        //   for(size_t k=0; k<T::nUnknown; k++)
        //     sol[kv.first][k] = 0.0;
      // _imposeContinuity(&s);

      std::cout << "+++ --- +++ Generate smooth framefield" << std::endl;
      s.solveLBFGS(sol); //compute framefield
      s.printInfos();
      // for(const auto &kv: sol){ //Store solution
      //   T f = T(kv.second);
      //   f.projectOnCrossManifold();
      //   m_mapEdgeFrames[kv.first] = f;
      // }
      // //DBG perturbation
      // double lower_bound = 0.0;
      // double upper_bound = 2.0;
      // std::uniform_real_distribution<double> unif(lower_bound,upper_bound);
      // std::default_random_engine re;
      // for(auto &kv: sol){
      //   if(!m_fixedEdges[kv.first] && kv.first->getLines().size() == 0){
      //     double fact = unif(re);
      //     for(size_t k=0; k<kv.second.size(); k++)
      //       kv.second[k] *= 1.0 + fact;
      //   }
      // }
      // for(auto &kv: sol){
      //   if(!m_fixedEdges[kv.first] && kv.first->getLines().size() == 0){
      //     double fact = kv.second[0];
      //     for(size_t k=0; k<kv.second.size(); k++)
      //       kv.second[k] /= fact;
      //   }
      // }
      for(const auto &kv: sol){ //Store solution
        m_mapEdgeFrames[kv.first] = kv.second;
      }
    }

    void relaxSolution(){
      ObjectiveFunction *GLobj;
      GLobj = m_dirichletEnergy;

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE, 200);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      // _createInitialFrameField(sol, false);
      _createInitialFrameField(sol, true);
      _imposeBC(&s, sol);

      std::cout << "+++ --- +++ Relax framefield" << std::endl;
      s.solveLBFGS(sol); //compute framefield
      s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
    }


    void generateIntegrableFrameField(size_t maxItLbfgs = 100000, bool withPenalty=true){
      double h = m_m->getMaxEdgeLength();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      // double penaltyConstraint = m_fact*0.1;
      double domainArea = 0.0;
      for(Element *e: m_m->getElements())
        domainArea += e->getArea();
      
      // double penaltyConstraint = m_fact*domainArea/m_m->getElements().size();
      // double penaltyConstraint = m_fact*0.001;//Version grad^2/N
      // double penaltyConstraint = m_fact*0.01;//Version log(1+grad^2/N)//Kindof working
      // double penaltyConstraint = m_fact*0.003;//Version log(1+grad^2/N)//Kindof working with init no penalty

      
      // double penaltyConstraint = m_fact*0.07;//Version log(1+grad^2/N)//Kindof working with init no penalty
      // double penaltyConstraint = m_fact*0.5;//Version normalized
      // double penaltyConstraint = m_fact*0.1;//Version smoothweight
      // double penaltyConstraint = m_fact*0.1;//Version normalized + smoothweight
      // double penaltyConstraint = m_fact*0.1;//Version normalized + smoothweight
      // double penaltyConstraint = m_fact*0.1;//Version logsmoothweight

      // double penaltyConstraint = m_fact*0.001;//Version normalized for aniso
      double penaltyConstraint = m_fact*0.1;//Version normalized for aniso
      
      // double penaltyConstraint = m_fact*10.0;//Version log(1+grad^2/N)//Test to remove discontinuous patches//DBG equilibrium
      // double penaltyConstraint = m_fact*0.05;//Version log(1+grad^2/N)//Test to remove discontinuous patches
      // double penaltyConstraint = m_fact*0.1;//Version OdecoIso2Dnormalized for volute
      // double penaltyConstraint = m_fact*0.5;//Version OdecoIso2Dnormalized for square
      
      // double penaltyConstraint = m_fact*0.5;//Version OdecoIso2DnormalizedLogSmoothWeight factor for square
      // double penaltyConstraint = m_fact*10.0;//Version OdecoIso2DnormalizedLogSmoothWeight with area factor for volute
      
      // double penaltyConstraint = m_fact*0.1*3/100.0*1*626.0/m_m->getElements().size();
      // double penaltyConstraint = m_fact*0.1*3/100.0*1*626.0/m_m->getElements().size();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact*0.1*400;
      ObjectiveFunction *GLobj;
      // GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE, maxItLbfgs);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      _createInitialFrameField(sol, true);
      _imposeBC(&s, sol);
      // _imposeContinuity(&s);
      // _createInitialFrameField(sol, false);
      // for(const auto &kv: m_fixedEdges)
      //   if(kv.second || kv.first->getLines().size() != 0){
      //     if(kv.first->getBarycenter()[0] <= -0.5 + 1e-10 && kv.first->getBarycenter()[1] <= -0.5 + 1e-10 && kv.first->getBarycenter()[2] >= 0.9)
      //       _fixFrameOnEdge(&s, kv.first, sol);//DBG notch
      //     else
      //       _alignFrameOnEdge(&s, kv.first, sol);
      //   }

      // // Here for dbg, works.
      // for(const auto &kv: m_fixedEdges)
      //   if(kv.second || kv.first->getLines().size() != 0){
      //     _fixFrameOnEdge(&s, kv.first, sol);
      //   }

      // std::vector<double> schedule{0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
      // std::vector<double> schedule{0.8, 0.9, 0.98};
      // std::vector<double> schedule{0.98, 1.0};
      // std::vector<double> schedule{0.8, 1.0};
      
      std::cout << "+++ --- +++ Generate integrable framefield" << std::endl;
      // std::vector<double> schedule{1.0};
      std::vector<double> schedule{0.95};
      // std::vector<double> schedule{0.1, 0.3, 0.5, 0.8, 1.0};
      // std::vector<double> schedule{0.9, 0.95, 0.97, 0.99, 1.0};
      int cpt = 1;
      for(double gamma: schedule){
        std::cout << "Schedule step " << cpt << "/" << schedule.size() << std::endl;
        GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        // if(withPenalty){
        //   GLobj = *(m_integrabilityEnergy) + *(penaltyConstraint*(*m_frameConstraint));
        //   // GLobj = (m_integrabilityEnergy);
        // }          
        // else{
        //   penaltyConstraint *= 0.0;
        //   GLobj = *(m_integrabilityEnergy) + *(penaltyConstraint*(*m_frameConstraint));
        //   // GLobj = m_integrabilityEnergy;
        // }

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
        
        s.setObjectiveFunction(GLobj);
        s.solveLBFGS(sol); //compute framefield
        cpt++;
      }
      s.printInfos();
      // for(const auto &kv: sol){ //Store solution
      //   T f = T(kv.second);
      //   f.projectOnCrossManifold();
      //   m_mapEdgeFrames[kv.first] = f;
      // }
      for(const auto &kv: sol){ //Store solution
        m_mapEdgeFrames[kv.first] = kv.second;
      }
      // _generateIntegrableFrameFieldImposedDIrections();
    }

    void projectFrames(){
      for(const auto &kv: m_mapEdgeFrames){
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
    }

    void generateIntegrableFrameFieldCustom(){
      size_t itMax = 100;
      int nLbfgsIt = 10;
      // int nLbfgsIt = 10;
      for(size_t k=0; k<itMax; k++){
        if(k%1 == 0)
          std::cout << "++++++++++ iteration: " << k << "/" << itMax << std::endl;
        // generateIntegrableFrameFieldFixedSize(100, true);
        // _generateIntegrableFrameFieldImposedDIrections(100, true);
        generateIntegrableFrameFieldFixedSize(100, true);
        projectFrames();
        _generateIntegrableFrameFieldImposedDIrections(100, true);
        projectFrames();
        // generateIntegrableFrameField(10000, false);
        // if(k%1 == 0){
        //   std::map<Element *, std::vector<std::vector<double>>> mapElemDir = getDirectionsPerElem();
        //   visu::framefield(mapElemDir, "Integrable frames Glob intermediate");
        // }
      }
    }

    void generateIntegrableFrameFieldFixedSize(size_t maxItLbfgs = 100000, bool mute=false){
      double h = m_m->getMaxEdgeLength();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      double penaltyConstraint = m_fact*0.1;//Version log(1+grad^2/N)
      ObjectiveFunction *GLobj;
      GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));
      // GLobj = m_integrabilityEnergy;

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE, maxItLbfgs);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      _createInitialFrameField(sol);
      for(const auto &kv: m_fixedEdges)
        if(kv.second || kv.first->getLines().size() != 0)
          _fixFrameOnEdge(&s, kv.first, sol);//DBG notch
        else
          _fixSizeFrameOnEdge(&s, kv.first, sol);

      
      // std::vector<double> schedule{0.0, 0.2, 0.4, 0.6, 0.8, 1.0};
      // std::vector<double> schedule{0.8, 0.9, 0.98};
      // std::vector<double> schedule{0.98, 1.0};
      // std::vector<double> schedule{0.8, 1.0};
      if(!mute)
        std::cout << "+++ --- +++ Generate integrable framefield with fixed size" << std::endl;
      std::vector<double> schedule{1.0};
      for(double gamma: schedule){
        // GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        s.setObjectiveFunction(GLobj);
        s.solveLBFGS(sol); //compute framefield
      }
      if(!mute)
        s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
      // _generateIntegrableFrameFieldImposedDIrections();
    }
    
    void generateIntegrableFrameFieldFixedBoundary(){
      double h = m_m->getMaxEdgeLength();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      // double penaltyConstraint = m_fact*0.1;
      double domainArea = 0.0;
      for(Element *e: m_m->getElements())
        domainArea += e->getArea();
      
      // double penaltyConstraint = m_fact*domainArea/m_m->getElements().size();
      // double penaltyConstraint = m_fact*0.001;//Version grad^2/N
      double penaltyConstraint = m_fact*0.01;//Version log(1+grad^2/N)
      
      // double penaltyConstraint = m_fact*0.1*3/100.0*1*626.0/m_m->getElements().size();
      // double penaltyConstraint = m_fact*0.1*3/100.0*1*626.0/m_m->getElements().size();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact*0.1*400;
      ObjectiveFunction *GLobj;
      // GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE, 1000);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      _createInitialFrameField(sol, true);
      for(const auto &kv: m_fixedEdges)
        if(kv.second || kv.first->getLines().size() != 0)
          _fixFrameOnEdge(&s, kv.first, sol);//DBG notch

      std::cout << "+++ --- +++ Generate integrable framefield with fixed boundaries" << std::endl;
      std::vector<double> schedule{1.0};
      for(double gamma: schedule){
        // GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        GLobj = *(m_integrabilityEnergy) + *(penaltyConstraint*(*m_frameConstraint));
        // GLobj = (m_integrabilityEnergy);

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
        
        s.setObjectiveFunction(GLobj);
        s.solveLBFGS(sol); //compute framefield
      }
      s.printInfos();
      for(const auto &kv: sol){ //Store solution
        T f = T(kv.second);
        f.projectOnCrossManifold();
        m_mapEdgeFrames[kv.first] = f;
      }
      // _generateIntegrableFrameFieldImposedDIrections();
    }

    void _generateIntegrableFrameFieldImposedDIrections(size_t maxItLbfgs = 100000, bool mute=false){
      // double penaltyConstraint = 1.0/(4*m_m->getMaxEdgeLength()*m_m->getMaxEdgeLength());
      // double h = m_m->getMaxEdgeLength()*0.5;
      double h = m_m->getMaxEdgeLength();
      double penaltyConstraint = m_fact*10.0;//Version normalized for aniso
      ObjectiveFunction *GLobj;
      // GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));
      GLobj = m_integrabilityEnergy;
      

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE, maxItLbfgs);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      _createInitialFrameField(sol);

      for(const auto &kv: m_fixedEdges)
        if(kv.first->getLines().size() == 0 && !kv.second)
          _alignFrameOnEdge(&s, kv.first, sol);

      _imposeBC(&s, sol);

      // _imposeContinuity(&s);
      
      if(!mute)
        std::cout << "+++ --- +++ Generate integrable framefield with fixed orientation" << std::endl;
      std::vector<double> schedule{0.95};
      for(double gamma: schedule){
        // GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        // GLobj = *((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy));
        GLobj = *(*((1.0 - gamma)*(*m_dirichletEnergy)) + *(gamma*(*m_integrabilityEnergy))) + *(penaltyConstraint*(*m_frameConstraint));
        s.setObjectiveFunction(GLobj);
        s.solveLBFGS(sol); //compute framefield
      }
      if(!mute)
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

    std::map<Element*, double> getIntegrabilityError(){
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
        // mapError[e] = sqrt(valFunc)/e->getArea();
        mapError[e] = valFunc;
      }
      return mapError;
    }

    double getTotalIntegrabilityError(){
      double integrabilityError = 0.0;
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
        // mapError[e] = sqrt(valFunc)/e->getArea();
        mapError[e] = valFunc;
      }
      for(auto &kv: mapError)
        integrabilityError += kv.second;
      return integrabilityError;
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
        mapError[e] = sqrt(valFunc/e->getArea());
        // mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getNormalizedOdecoPenaltyDensity(){
      ObjectiveFunction *err = new OdecoIso2DConstraintNormalized(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
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
        err->evaluateFunction(e, solEl, valFunc);
        mapError[e] = valFunc/e->getArea();
        // mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getNormalizedOdecoPenalty(){
      ObjectiveFunction *err = new OdecoIso2DConstraintNormalized(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
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
        err->evaluateFunction(e, solEl, valFunc);
        // mapError[e] = valFunc/e->getArea();
        mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getNormalizedOdecoPenaltyWithLogSmoothWeight(){
      ObjectiveFunction *err = new OdecoIso2DConstraintNormalizedWithLogSmoothWeight(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
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
        err->evaluateFunction(e, solEl, valFunc);
        // mapError[e] = valFunc/e->getArea();
        mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getNormalizedOdecoPenaltyWithSmoothWeight(){
      ObjectiveFunction *err = new OdecoIso2DConstraintNormalizedWithSmoothWeight(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
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
        err->evaluateFunction(e, solEl, valFunc);
        // mapError[e] = valFunc/e->getArea();
        mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getOdecoPenaltyDensity(){
      ObjectiveFunction *err = new OdecoIso2DConstraint(1.0, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
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
        err->evaluateFunction(e, solEl, valFunc);
        mapError[e] = valFunc/e->getArea();
        // mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getFrameConstraint(){
      ObjectiveFunction *err = m_frameConstraint;
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
        err->evaluateFunction(e, solEl, valFunc);
        // mapError[e] = valFunc/e->getArea();
        mapError[e] = valFunc;
      }
      return mapError;
    }

    std::map<Element*, double> getSmoothness(){
      DirichletEnergieVectCRIsoMormalized *smoothnessObjFunc = new DirichletEnergieVectCRIsoMormalized(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      std::map<Element*, double> mapSmoothness;
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
        smoothnessObjFunc->evaluateFunction(e, solEl, valFunc);
        // m_dirichletEnergy->evaluateFunction(e, solEl, valFunc);
        mapSmoothness[e] = sqrt(valFunc);
      }
      return mapSmoothness;
    }

    std::map<Element*, double> getSmoothnessDensity(){
      DirichletEnergieVectCRIsoMormalized *smoothnessObjFunc = new DirichletEnergieVectCRIsoMormalized(T::nUnknown, &T::getRotatedSolEl, &T::getInvertRotatedGradient);
      std::map<Element*, double> mapSmoothness;
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
        smoothnessObjFunc->evaluateFunction(e, solEl, valFunc);
        // m_dirichletEnergy->evaluateFunction(e, solEl, valFunc);
        mapSmoothness[e] = sqrt(valFunc/e->getArea());
      }
      return mapSmoothness;
    }

    //Solver methods
    //Impose frame size on Edge edg to be aligned with sol[edg], but rotation is free. Attention: Not sufficient by itself, as it can break Odeco constraint
    void _fixSizeFrameOnEdge(Solver *s, Edge *e, std::map<Edge*, std::vector<double>> &sol){
      // T f(sol[e]);
      // std::vector<std::vector<double>> dirFrames = f.getDirections();
      if(!(std::is_same<T, OdecoIso2D>::value)){
        std::cout << "fixed size constraint not implemented for frame different than OdecoIso2D" << std::endl;
        exit(0);
      }
      std::vector<std::vector<double>> mat = T::getSizeLinConstr(1.0);
      std::vector<double> vect; vect.resize(mat.size(), 0.0);
      std::vector<std::pair<Edge*, int>> pairEdgeField;
      pairEdgeField.reserve(T::nUnknown);
      for(size_t k=0; k<T::nUnknown; k++)
        pairEdgeField.push_back(std::make_pair(e, k));
      s->addBCLinearCombination(mat, vect, pairEdgeField);
    }
    
    //Impose frame on Edge edg to be aligned with sol[edg], but sizes are free
    void _alignFrameOnEdge(Solver *s, Edge *e, std::map<Edge*, std::vector<double>> &sol){
      T f(sol[e]);
      std::vector<std::vector<double>> dirFrames = f.getDirections();
      std::vector<std::vector<double>> mat = T::getAlignmentLinConstr(dirFrames[0]);
      std::vector<double> vect; vect.resize(mat.size(), 0.0);
      std::vector<std::pair<Edge*, int>> pairEdgeField;
      pairEdgeField.reserve(T::nUnknown);
      for(size_t k=0; k<T::nUnknown; k++)
        pairEdgeField.push_back(std::make_pair(e, k));
      s->addBCLinearCombination(mat, vect, pairEdgeField);
    }
    
    //Impose frame on Edge edg to be equal to sol[e] as boundary condition for the solver
    void _fixFrameOnEdge(Solver *s, Edge *e, std::map<Edge*, std::vector<double>> &sol){
      std::vector<double> solEdge = sol[e];
      for(int k=0; k<T::nUnknown; k++)
        s->addBCDirichlet(std::make_pair(e, k), solEdge[k]);
    }
    
    //Set the framefield in sol to be m_mapEdgeFrames. If m_mapEdgeFrames[edg] does not exists, initialize the frame to an isotrope one with norm 1 aligned with the associated edge.
    void _createInitialFrameField(std::map<Edge*, std::vector<double>> &sol, bool scaleBranches = false){
      sol.clear();
      for(Edge* e: m_m->getEdges()){
        if(m_mapEdgeFrames.find(e) != m_mapEdgeFrames.end()){
          sol[e] = m_mapEdgeFrames[e].m_frame;
          if(e->getLines().size() != 0){//If edg is on a line, adjust cross orientation to align it with the line. Necessary because of Crouzeix Raviart basis functions discontinuities, and solution transfer from coarse to fine.
            T f(sol[e]);
            std::vector<std::vector<double>> dirs = f.getDirections();
            int indexDir0 = tools::getIndexClosestVect(dirs, {1.0, 0.0});
            double normDir0 = tools::norm(dirs[indexDir0]);
            double normDir1 = tools::norm(dirs[(indexDir0 + 1)%2]);
            std::vector<double> edgDir0{1.0, 0.0};
            tools::scale(edgDir0, normDir0);
            std::vector<double> edgDir1{0.0, 1.0};
            tools::scale(edgDir1, normDir1);
            std::vector<std::vector<double>> newDir{edgDir0, edgDir1};
            T newF(newDir);
            sol[e] = newF.m_frame;
          }
        }
        else{
          std::vector<std::vector<double>> dirBC;
          dirBC.resize(1);
          dirBC[0].resize(2, 0.0);
          dirBC[0][0] = 1.0, dirBC[0][1] = 0.0;
          T f(dirBC);
          sol[e] = f.m_frame;
        }
      }
      if(scaleBranches){
        if(std::is_same<T, OdecoIso2D>::value || std::is_same<T, OdecoAniso2D>::value){
          for(auto &kv: m_lineGroupsSmoothConstraint){
            std::cout << "n lines in group line smooth bc: " << kv.first.size() << std::endl;
            double currentLength = 0.0;
            double targetLength = kv.second;
            for(auto &l: kv.first){
              T f(sol[l->getEdge(0)]);
              currentLength += l->getEdge(0)->getLength() * f.getLengthAlongDir({1.0, 0.0});
            }
            double factMult = targetLength/currentLength;
            for(auto &l: kv.first){
              for(size_t k=0; k<sol[l->getEdge(0)].size(); k++)
                sol[l->getEdge(0)][k] *= factMult;
            }
            std::cout << "targetLength: " << targetLength << std::endl;
            std::cout << "currentLength: " << currentLength << std::endl;
          }
          for(auto &kv: m_lineGroupsHardConstraint){
            std::cout << "n lines in group line hard bc: " << kv.first.size() << std::endl;
            for(size_t kLine = 0; kLine<kv.first.size(); kLine++){
              Element *l = kv.first[kLine];
              T f(sol[l->getEdge(0)]);
              double factCorr = kv.second[kLine]/f.getLengthAlongDir({1.0, 0.0});
              for(size_t k=0; k<sol[l->getEdge(0)].size(); k++)
                sol[l->getEdge(0)][k] *= factCorr;
            }
          }

        }
        else{
          throw std::invalid_argument("FrameField::_createInitialFrameField not implemented for this kind of frames");
        }
      }
    }
    
    //Framefield posttreatment
    void _locateSingularitiesVertices(){//Locate singular vertices (has to be done because of Crouzeix Raviart discretization)
      m_singularitiesVertices.clear();
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
            int indEdgCurrent = locIndVInCurrentElem;
            int indEdgNext = (locIndVInCurrentElem+nEdges-1)%nEdges;

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
            
            std::vector<double> normal = elem->getNormal();
            double alpha = tools::getAngleRotationAlongDirection(normal, dirCurrentEdg, edgRefTransport);
            std::vector<double> dirRefRotated = tools::rotateAlongDirection(normal, alpha, dirRef);
            indClosest = tools::getIndexClosestVect(dirsInitTransport, dirRefRotated);
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
    }

    void _locateSingularities(){//Locate singular elements (has to be done because of Crouzeix Raviart discretization)
      m_singularities.clear();
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
    }

    void _imposeBC(Solver *s, std::map<Edge*, std::vector<double>> &sol){
      if(std::is_same<T, OdecoIso2D>::value || std::is_same<T, OdecoAniso2D>::value){
        //Constraints on lines
        for(auto &kv: m_lineGroupsSmoothConstraint){
          std::vector<std::vector<double>> matMeanSize(1);
          matMeanSize[0].resize(kv.first.size()*T::nUnknown, 0.0);
          std::vector<std::pair<Edge*, int>> pairEdgeFieldMeanSize;
          pairEdgeFieldMeanSize.reserve(kv.first.size()*T::nUnknown);
          for(size_t k=0; k<kv.first.size(); k++){
            Element *l = kv.first[k];
            // matMeanSize[0][T::nUnknown*k] = l->getEdge(0)->getLength();
            std::vector<std::vector<double>> constrAlignementPlusTangentSize = T::getAlignmentPlusTangentSizeLinConstr({1.0, 0.0, 0.0});
            for(size_t iFrame = 0; iFrame<T::nUnknown; iFrame++)
              matMeanSize[0][T::nUnknown*k + iFrame] = l->getEdge(0)->getLength()*constrAlignementPlusTangentSize[0][iFrame];
            for(int jField=0; jField<T::nUnknown; jField++)
              pairEdgeFieldMeanSize.push_back(std::make_pair(l->getEdge(0), jField));
            m_edgesWithConstraint.push_back(l->getEdge(0));
          }
          for(size_t k=0; k<kv.first.size(); k++){
            Element *l = kv.first[k];
            Edge *e = l->getEdge(0);
            std::vector<std::vector<double>> mat;
            //If edge is not fixed, impose only orientation
            if(!m_fixedEdges[e]){
              T f(sol[e]);
              std::vector<std::vector<double>> dirFrames = f.getDirections();
              mat = T::getAlignmentLinConstr(dirFrames[0]);
              std::vector<double> vect; vect.resize(mat.size(), 0.0);
              std::vector<std::pair<Edge*, int>> pairEdgeField;
              pairEdgeField.reserve(T::nUnknown);
              for(size_t jField=0; jField<T::nUnknown; jField++)
                pairEdgeField.push_back(std::make_pair(e, jField));
              s->addBCLinearCombination(mat, vect, pairEdgeField);

            }
            //If edge is fixed, impose everything
            else{
              _fixFrameOnEdge(s, e, sol);
              mat.resize(T::nUnknown);
              for(auto &v: mat)
                v.resize(T::nUnknown, 0.0);
              for(size_t jField=0; jField<T::nUnknown; jField++)
                mat[jField][jField] = 1.0;
            }
            //Remove constraint component from mean size constraint
            std::vector<double> meanVproj(matMeanSize[0].begin() + T::nUnknown*k, matMeanSize[0].begin() + T::nUnknown*(k+1));
            for(auto &v: mat){
              tools::projectOnHyperPlan(v, meanVproj);
            }
            for(size_t jField=0; jField<T::nUnknown; jField++)
              matMeanSize[0][T::nUnknown*k + jField] = meanVproj[jField];
          }
          tools::normalize(matMeanSize[0]);
          std::vector<double> vectMeanSize(matMeanSize.size(), 0.0);
          s->addBCLinearCombination(matMeanSize, vectMeanSize, pairEdgeFieldMeanSize);
        }
        for(auto &kv: m_lineGroupsHardConstraint){
          // int doSomething=0;
          // std::cout << "FrameField: hard constraint not implemented" << std::endl;
          // exit(0);
          // std::cout << "n groupLine hard constraint: " << m_lineGroupsHardConstraint.size() << std::endl;
          // exit(0);
          for(size_t k=0; k<kv.first.size(); k++){
            Element *l = kv.first[k];
            Edge *e = l->getEdge(0);
            std::vector<std::vector<double>> mat;
            //If edge is not fixed, impose only orientation
            if(!m_fixedEdges[e]){
              T f(sol[e]);
              std::vector<std::vector<double>> dirFrames = f.getDirections();
              mat = T::getAlignmentLinConstr(dirFrames[0]);
              std::vector<double> vect; vect.resize(mat.size(), 0.0);
              std::vector<std::pair<Edge*, int>> pairEdgeField;
              pairEdgeField.reserve(T::nUnknown);
              for(size_t jField=0; jField<T::nUnknown; jField++)
                pairEdgeField.push_back(std::make_pair(e, jField));
              s->addBCLinearCombination(mat, vect, pairEdgeField);
              // Constraint on size
              std::vector<std::vector<double>> constrAlignementPlusTangentSize = T::getAlignmentPlusTangentSizeLinConstr({1.0, 0.0, 0.0});
              m_edgesWithConstraint.push_back(l->getEdge(0));
              // Remove constraint component from mean size constraint
              std::vector<double> meanVproj(constrAlignementPlusTangentSize[0].begin(), constrAlignementPlusTangentSize[0].begin() + T::nUnknown);
              for(auto &v: mat){
                tools::projectOnHyperPlan(v, meanVproj);
              }
              for(size_t jField=0; jField<T::nUnknown; jField++)
                constrAlignementPlusTangentSize[0][jField] = meanVproj[jField];
              std::vector<double> vectSize(1, 0.0);
              s->addBCLinearCombination(constrAlignementPlusTangentSize, vectSize, pairEdgeField);
            }
            //If edge is fixed, impose everything
            else{
              _fixFrameOnEdge(s, e, sol);
              mat.resize(T::nUnknown);
              for(auto &v: mat)
                v.resize(T::nUnknown, 0.0);
              for(size_t jField=0; jField<T::nUnknown; jField++)
                mat[jField][jField] = 1.0;
            }
          }
        }
        for(auto &kv: m_fixedEdges){
          if(kv.second && kv.first->getLines().size() == 0){
            _fixFrameOnEdge(s, kv.first, sol);
            m_edgesWithConstraint.push_back(kv.first);
          }
        }
      }
      else{
        throw std::invalid_argument("FrameField::_imposeBC not implemented for this kind of frames");
      }
    }

    void _imposeContinuity(Solver *s){
      std::cout << "impose continuity" << std::endl;
      // std::vector<bool> isEdgeConstrained(m_m->getEdges().size(), false);
      // for(Edge* e: m_edgesWithConstraint){
      //   isEdgeConstrained[e->getIndex()] = true;
      // }
      // std::vector<bool> isElemFreeOfConstraints(m_m->getElements().size(), true);
      // for(Element *e: m_m->getElements()){
      //   for(Edge* edg: e->getEdges())
      //     if(isEdgeConstrained[edg->getIndex()]){
      //       isElemFreeOfConstraints[e->getIndex()] = false;
      //       break;
      //     }
      // }
      for(Edge* edg: m_m->getEdges()){
        Element *currentElem = edg->getElements()[0];
        if(edg->getElements().size() > 1){
          Element *nextElem = edg->getElements()[1];
          // if(isElemFreeOfConstraints[currentElem->getIndex()] && isElemFreeOfConstraints[nextElem->getIndex()]){
          if(1){
            int localEdgeIndexInCurrent;
            int localEdgeIndexInNext;
            for(int k=0; k<currentElem->getEdges().size(); k++){
              Edge *edgT = currentElem->getEdge(k);
              if(edgT->getIndex() == edg->getIndex()){
                localEdgeIndexInCurrent = k;
                break;
              }
            }
            for(int k=0; k<nextElem->getEdges().size(); k++){
              Edge *edgT = nextElem->getEdge(k);
              if(edgT->getIndex() == edg->getIndex()){
                localEdgeIndexInNext = k;
                break;
              }
            }
            std::vector<std::vector<std::vector<double>>> rotOpCurrent;
            std::vector<std::vector<std::vector<double>>> rotOpNext;
            T::getCRRotOperatorWithDefinedRef(currentElem, rotOpCurrent, localEdgeIndexInCurrent);
            T::getCRRotOperatorWithDefinedRef(nextElem, rotOpNext, localEdgeIndexInNext);
            int nEdgesCurrent = currentElem->getEdges().size();
            int nEdgesNext = nextElem->getEdges().size();
            std::vector<double> currentCombinLin{1.0, -1.0, 1.0}; //evaluation in xi, eta = 0.0, 0.0
            std::vector<double> nextCombinLin{1.0, 1.0, -1.0}; //evaluation in xi, eta = 1.0, 0.0
            std::vector<std::vector<double>> mat;
            mat.resize(T::nUnknown);
            for(auto &v: mat)
              v.resize(T::nUnknown*(nEdgesCurrent+nEdgesNext-2), 0.0);
            std::vector<double> vect; vect.resize(mat.size(), 0.0);
            std::vector<std::pair<Edge*, int>> pairEdgeField;
            pairEdgeField.reserve(T::nUnknown*(nEdgesCurrent+nEdgesNext-2));

            // std::cout << currentElem->getEdge((localEdgeIndexInCurrent)%nEdgesCurrent)->getIndex() << "/" << currentElem->getEdge((localEdgeIndexInCurrent)%nEdgesCurrent)->getIndex() << std::endl;
            for(size_t iEdg= 1; iEdg<nEdgesCurrent; iEdg++)
              for(size_t k=0; k<T::nUnknown; k++)
                pairEdgeField.push_back(std::make_pair(currentElem->getEdge((iEdg+localEdgeIndexInCurrent)%nEdgesCurrent), k));
            for(size_t iEdg= 1; iEdg<nEdgesNext; iEdg++)
              for(size_t k=0; k<T::nUnknown; k++)
                pairEdgeField.push_back(std::make_pair(nextElem->getEdge((iEdg+localEdgeIndexInNext)%nEdgesNext), k));

            for(size_t iEdg=1; iEdg<nEdgesCurrent; iEdg++)//Carefull! This is writtent for two elements with the same number of edges
              for(size_t k=0; k<T::nUnknown; k++)
                for(size_t l=0; l<T::nUnknown; l++){
                  mat[k][l+T::nUnknown*(iEdg-1)] = currentCombinLin[iEdg]*rotOpCurrent[iEdg][k][l];
                  mat[k][l+T::nUnknown*(iEdg-1)+T::nUnknown*(nEdgesCurrent-1)] = -nextCombinLin[iEdg]*rotOpNext[iEdg][k][l];
                }
            s->addBCLinearCombination(mat, vect, pairEdgeField);
          }
        }
      }
      std::cout << "END impose continuity" << std::endl; 
    }
    
    void _buildSizeBC(){
      std::vector<std::vector<Element*>> lineGroups = m_m->getLineGroups();
      m_lineGroupsSmoothConstraint.clear();
      m_lineGroupsHardConstraint.clear();
      if(m_typeBC == "smoothBC"){
        for(size_t k=0; k<lineGroups.size(); k++){
          std::vector<Element*> groupLine = lineGroups[k];
          double totalLineSize = 0.0;
          double totalParametricSize = 0.0;
          size_t nLines = groupLine.size();

          for(Element *l: groupLine){
            std::vector<Vertex*> verts = l->getVertices();
            double lineLength = tools::norm(tools::diff(verts[0]->getCoord(), verts[1]->getCoord()));
            totalLineSize += lineLength;
            totalParametricSize += lineLength/TARGETMESHSIZE(l->getEdge(0)->getBarycenter());
          }
          int nElements = (int)std::round(totalParametricSize);
          nElements = std::max(nElements, 1);
          double factCorrection = totalParametricSize/(1.0*nElements);
          double averageSizeOnLine = totalLineSize/(1.0*nElements);
          double integraleSizeOnLine = averageSizeOnLine * totalLineSize;
          m_lineGroupsSmoothConstraint.push_back(std::make_pair(groupLine, integraleSizeOnLine));
        }
      }
      else if(m_typeBC == "hardBC"){
        for(size_t k=0; k<lineGroups.size(); k++){
          std::vector<Element*> groupLine = lineGroups[k];
          double totalLineSize = 0.0;
          double totalParametricSize = 0.0;
          size_t nLines = groupLine.size();

          std::vector<double> hardBCsizes;
          hardBCsizes.reserve(groupLine.size());
          for(Element *l: groupLine){
            std::vector<Vertex*> verts = l->getVertices();
            double lineLength = tools::norm(tools::diff(verts[0]->getCoord(), verts[1]->getCoord()));
            totalLineSize += lineLength;
            totalParametricSize += lineLength/TARGETMESHSIZE(l->getEdge(0)->getBarycenter());
          }

          int nElements = (int)std::round(totalParametricSize);
          nElements = std::max(nElements, 1);
          double factCorrection = totalParametricSize/(1.0*nElements);
          for(Element *l: groupLine){
            hardBCsizes.push_back(TARGETMESHSIZE(l->getEdge(0)->getBarycenter())*factCorrection);
          }
          m_lineGroupsHardConstraint.push_back(std::make_pair(groupLine, hardBCsizes));
        }
      }
      else{
        throw std::invalid_argument("FrameField::_buildSizeBC invalid size boundary condition type");
      }
    }

    FrameField<T> _getFrameFieldWithRefinmentAroundSings(FrameField<T> *origFrameField){
      FrameField<T> origFrameFieldCopy(*origFrameField);
      origFrameFieldCopy._locateSingularitiesVertices();
      origFrameFieldCopy._locateSingularities();
      
      std::vector<size_t> indicesElementsForFractalRefine;
      indicesElementsForFractalRefine.reserve(6*origFrameFieldCopy.m_singularitiesVertices.size());
      std::vector<bool> elemTouched(origFrameFieldCopy.m_m->getNumElements(), false);
      
      for(const auto &kv: origFrameFieldCopy.m_singularitiesVertices)
        for(Element *e: kv.first->getElements())
          elemTouched[e->getIndex()] = true;
      for(auto &kv: origFrameFieldCopy.m_singularities)
        elemTouched[kv.first->getIndex()] = true;
      for(size_t iE=0; iE<elemTouched.size(); iE++)
        if(elemTouched[iE])
          indicesElementsForFractalRefine.push_back(origFrameFieldCopy.m_m->getElement(iE)->getIndex());
      
      Mesh *mRefinedFractal = new Mesh;
      MeshRefiner *mr = new MeshRefiner(origFrameFieldCopy.m_m, mRefinedFractal);
      mr->refineMesh(indicesElementsForFractalRefine);
      std::map<Edge*, T> framesRefinedFractal;
      framesRefinedFractal = transferCoarseToFine(mr, origFrameFieldCopy.m_mapEdgeFrames);

      FrameField<T> frameFieldFractalRefinement(mRefinedFractal, origFrameFieldCopy.m_fact, origFrameFieldCopy.m_typeBC);
      frameFieldFractalRefinement.setInitFrameField(framesRefinedFractal);
      frameFieldFractalRefinement.projectFrames();
      //Mandatory to fix alignement loss on boundary when refinining Crouzeix Raviart
      std::map<Edge*, std::vector<double>> sol;
      frameFieldFractalRefinement._createInitialFrameField(sol, true);
      for(const auto &kv: sol){
        frameFieldFractalRefinement.m_mapEdgeFrames[kv.first] = kv.second;
      }
      //
      frameFieldFractalRefinement._locateSingularities();
      frameFieldFractalRefinement._locateSingularitiesVertices();

      return frameFieldFractalRefinement;
    }
    
    FrameField<T> _getFrameFieldWithNonTouchingSingularities(FrameField<T> *origFrameField){
      FrameField<T> origFrameFieldCopy(*origFrameField);
      
      origFrameFieldCopy._locateSingularitiesVertices();
      origFrameFieldCopy._locateSingularities();
      //Find elements to refine to separate touching sigularities
      std::vector<int> vertexTouched(origFrameFieldCopy.m_m->getVertices().size(), 0);
      for(const auto &kv: origFrameFieldCopy.m_singularities){
        for(Vertex *v: kv.first->getVertices()){
          vertexTouched[v->getIndex()] += 1;
        }
      }
      for(const auto &kv: origFrameFieldCopy.m_singularitiesVertices)
        vertexTouched[kv.first->getIndex()] += 1;
      
      std::vector<size_t> indicesElementsForFractalRefine;
      indicesElementsForFractalRefine.reserve(origFrameFieldCopy.m_singularities.size());
      for(const auto &kv: origFrameFieldCopy.m_singularities){
        bool toFractalRefine = false;
        for(Vertex *v: kv.first->getVertices()){
          if(vertexTouched[v->getIndex()] > 1)
            toFractalRefine = true;
        }
        if(toFractalRefine)
          indicesElementsForFractalRefine.push_back(kv.first->getIndex());
      }
      int cpt = 0;
      while(indicesElementsForFractalRefine.size() > 0 && cpt < 3){
        // std::cout << "n elements to fractal refine: " << indicesElementsForFractalRefine.size() << std::endl;
        Mesh *mRefinedFractal = new Mesh;
        MeshRefiner *mr = new MeshRefiner(origFrameFieldCopy.m_m, mRefinedFractal);
        mr->refineMesh(indicesElementsForFractalRefine);
        std::map<Edge*, T> framesRefinedFractal;
        framesRefinedFractal = transferCoarseToFine(mr, origFrameFieldCopy.m_mapEdgeFrames);

        FrameField<T> frameFieldFractalRefinement(mRefinedFractal, origFrameFieldCopy.m_fact, origFrameFieldCopy.m_typeBC);
        frameFieldFractalRefinement.setInitFrameField(framesRefinedFractal);
        frameFieldFractalRefinement.projectFrames();
        //Mandatory to fix alignement loss on boundary when refinining Crouzeix Raviart
        std::map<Edge*, std::vector<double>> sol;
        frameFieldFractalRefinement._createInitialFrameField(sol, true);
        for(const auto &kv: sol){
          frameFieldFractalRefinement.m_mapEdgeFrames[kv.first] = kv.second;
        }
        //
        frameFieldFractalRefinement._locateSingularities();
        frameFieldFractalRefinement._locateSingularitiesVertices();
        origFrameFieldCopy = frameFieldFractalRefinement;
        //Find elements to refine to separate touching sigularities
        vertexTouched.clear();
        vertexTouched.resize(origFrameFieldCopy.m_m->getVertices().size(), 0);
        for(const auto &kv: origFrameFieldCopy.m_singularities){
          for(Vertex *v: kv.first->getVertices()){
            vertexTouched[v->getIndex()] += 1;
          }
        }
        for(const auto &kv: origFrameFieldCopy.m_singularitiesVertices)
          vertexTouched[kv.first->getIndex()] += 1;

        indicesElementsForFractalRefine.clear();
        indicesElementsForFractalRefine.reserve(origFrameFieldCopy.m_singularities.size());
        for(const auto &kv: origFrameFieldCopy.m_singularities){
          bool toFractalRefine = false;
          for(Vertex *v: kv.first->getVertices()){
            if(vertexTouched[v->getIndex()] > 1)
              toFractalRefine = true;
          }
          if(toFractalRefine)
            indicesElementsForFractalRefine.push_back(kv.first->getIndex());
        }
        cpt++;
      }
      FrameField<T> nonTouchingSingFrameField(origFrameFieldCopy);
      return nonTouchingSingFrameField;     
    }

    FrameField<T> _getFrameFieldWithVerticesSing(FrameField<T> &frameFieldFractalRefinement){
      //Find how to refine singular triangles to get singularities only on vertices
      std::map<Element*, double> singularities = frameFieldFractalRefinement.m_singularities;
      std::map<Edge*, T> mapEdgeFrames = frameFieldFractalRefinement.getFrameField();
      
      std::vector<T*> edgeIndToFrame;
      edgeIndToFrame.resize(mapEdgeFrames.size());
      for(auto &kv: mapEdgeFrames)
        edgeIndToFrame[kv.first->getIndex()] = &(kv.second);
      
      std::vector<Edge*> listEdgesToSplit;
      listEdgesToSplit.reserve(singularities.size());
      for(const auto &kv: singularities){
        Element *e = kv.first;
        //Create element solution for interpolation
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
        //Loop on element edges. Testing split of said edge to see if singularity moved on vertex
        std::vector<std::vector<std::vector<double>>> listParamCoords(3);
        listParamCoords[0] = {{0.25, 0.0},{0.5, 0.0},{0.75, 0.0},{0.25, 0.5}};
        listParamCoords[1] = {{0.25, 0.25},{0.75, 0.25},{0.5, 0.5},{0.25, 0.75}};
        listParamCoords[2] = {{0.0, 0.25},{0.5, 0.25},{0.0, 0.75},{0.0, 0.5}};
        size_t edgToSplit = -1;
        for(size_t kEdgSplit=0; kEdgSplit<3; kEdgSplit++){
          std::vector<double> solInterp = e->interpolateCR(listParamCoords[kEdgSplit][0][0], listParamCoords[kEdgSplit][0][1], solTriRotated);
          T frameEdgeRef(solInterp);
          std::vector<std::vector<double>> dirsEdge = frameEdgeRef.getDirectionsFromRef(vRef, n);
          std::vector<double> dirRef = dirsEdge[0];
          for(size_t kVirtualEdg=1; kVirtualEdg<4; kVirtualEdg++){
            solInterp = e->interpolateCR(listParamCoords[kEdgSplit][kVirtualEdg][0], listParamCoords[kEdgSplit][kVirtualEdg][1], solTriRotated);
            T frameCurrent(solInterp);
            std::vector<std::vector<double>> dirsCurrent = frameCurrent.getDirectionsFromRef(vRef, n);
            dirRef = tools::getClosestVect(dirsCurrent, dirRef);
          }
          int indClosest = tools::getIndexClosestVect(dirsEdge, dirRef);
          if(indClosest != 0){
            edgToSplit = kEdgSplit;
            break;
          }
        }
        if(edgToSplit == -1){
          std::cout << "Problem in Framefield<T>::_splitForSingsOnVert(). Can't find an edge to split in order to move singularity on a vertex." << std::endl;
          exit(0);
        }
        listEdgesToSplit.push_back(e->getEdge(edgToSplit));
      }
      
      //Create new mesh splitting listed edges.
      Mesh *mRefinedEdges = new Mesh;
      MeshRefiner *mr2 = new MeshRefiner(frameFieldFractalRefinement.m_m, mRefinedEdges);
      mr2->customRefineMesh(listEdgesToSplit);
      std::map<Edge*, T> framesRefinedEdges;
      framesRefinedEdges = transferCoarseToFine(mr2, frameFieldFractalRefinement.m_mapEdgeFrames);

      FrameField<T> frameFieldEdgesRefinement(mRefinedEdges, m_fact, m_typeBC);
      frameFieldEdgesRefinement.setInitFrameField(framesRefinedEdges);
      // frameFieldEdgesRefinement._generateIntegrableFrameFieldImposedDIrections();
      frameFieldEdgesRefinement.projectFrames();
      frameFieldEdgesRefinement._locateSingularities();
      frameFieldEdgesRefinement._locateSingularitiesVertices();
      frameFieldEdgesRefinement.printFrameFieldData("Integrable FrameField Imposed Dir Clean");
            
      // visu::scalarField(frameFieldEdgesRefinement.m_singularities, "Sings TEST");
      // visu::scalarField(frameFieldEdgesRefinement.m_singularitiesVertices, "SingsVert TEST");
      // std::map<Element*, double> mapElemErrorInt = frameFieldEdgesRefinement.getIntegrabilityError();
      // visu::scalarField(mapElemErrorInt, "Integrability error TEST");

      // frameFieldFractalRefinement.printFrameFieldData("Fractal Refinement");
      // return frameFieldFractalRefinement;
      return frameFieldEdgesRefinement;
    }
    
    FrameField<T> getCleanedFramefield(){
      FrameField<T> frameFieldFractalRefinement = _getFrameFieldWithNonTouchingSingularities(this);
      frameFieldFractalRefinement = _getFrameFieldWithRefinmentAroundSings(&frameFieldFractalRefinement);
      FrameField<T> frameFieldEdgesRefinement = _getFrameFieldWithVerticesSing(frameFieldFractalRefinement);
      int cpt = 0;
      while(frameFieldEdgesRefinement.m_singularities.size() != 0 && cpt<5){
        frameFieldEdgesRefinement = _getFrameFieldWithVerticesSing(frameFieldEdgesRefinement);
        cpt++;
      }

      // frameFieldEdgesRefinement._generateIntegrableFrameFieldImposedDIrections();
      frameFieldEdgesRefinement.projectFrames();
      frameFieldEdgesRefinement._locateSingularities();
      frameFieldEdgesRefinement._locateSingularitiesVertices();
      return frameFieldEdgesRefinement;
    }

    std::vector<double> _computeDistanceToBndAndSing(){
      std::vector<double> distanceToBndAndSing(m_m->getNumVertices(), 0.0);
      typedef std::pair<double, Vertex*> weightedVertex;
      std::vector<std::vector<weightedVertex>> weightedConnectivity;
      weightedConnectivity.resize(m_m->getNumVertices());
      for(size_t k=0; k<weightedConnectivity.size(); k++)
        weightedConnectivity[k].reserve(6);

      std::vector<Edge*> edges = m_m->getEdges();
      for(Edge *e: edges){
        double length=e->getLength();
        weightedConnectivity[e->getVertex(0)->getIndex()].push_back(weightedVertex(length,e->getVertex(1)));
        weightedConnectivity[e->getVertex(1)->getIndex()].push_back(weightedVertex(length,e->getVertex(0)));
        distanceToBndAndSing[e->getVertex(0)->getIndex()]=std::numeric_limits<double>::max();
        distanceToBndAndSing[e->getVertex(1)->getIndex()]=std::numeric_limits<double>::max();
      }
      std::priority_queue<weightedVertex,std::vector<weightedVertex>, std::greater<weightedVertex>> priorityQueue;

      std::vector<bool> isVertexBndOrLine(m_m->getNumVertices(), false);
      for(Edge *edg: m_m->getEdges())
        if(edg->getNumElements() == 1)
          for(Vertex *v: edg->getVertices())
            isVertexBndOrLine[v->getIndex()] = true;
      for(Element *l: m_m->getLines())
        for(Vertex *v: l->getVertices())
          isVertexBndOrLine[v->getIndex()] = true;
      
      for(Vertex *v: m_m->getVertices()){
        if(isVertexBndOrLine[v->getIndex()]){
          distanceToBndAndSing[v->getIndex()]=0.0;
          priorityQueue.push(weightedVertex(0.0,v));
        }
      }
      for(auto &kv: m_singularitiesVertices){
        distanceToBndAndSing[kv.first->getIndex()]=0.0;
        priorityQueue.push(weightedVertex(0.0,kv.first));
      }
      while(!priorityQueue.empty()){
        Vertex *v=priorityQueue.top().second;
        double distV=distanceToBndAndSing[v->getIndex()];
        priorityQueue.pop();
        for(const weightedVertex &wV: weightedConnectivity[v->getIndex()]){
          double dist=distanceToBndAndSing[wV.second->getIndex()];
          if(dist>distV+wV.first){
            distanceToBndAndSing[wV.second->getIndex()]=distV+wV.first;
            priorityQueue.push(weightedVertex(distanceToBndAndSing[wV.second->getIndex()],wV.second));
          }
        }
      }
      return distanceToBndAndSing;
    }

    std::vector<bool> _createCleanedEdgeTree(const std::vector<double> &distanceToBndAndSing){
      typedef std::pair<double,Element *> weightedElem;
      std::vector<bool> elemPassed;
      elemPassed.resize(m_m->getNumElements(), false);
      std::vector<double> elemWeight;
      elemWeight.resize(m_m->getNumElements(), 0.0);
      std::priority_queue<weightedElem,std::vector<weightedElem>, std::less<weightedElem>> pQueue;
      std::vector<bool> edgeTree;
      edgeTree.resize(m_m->getNumEdges(), true);

      for(Element *e: m_m->getElements()){
        for(Vertex *v: e->getVertices())
          elemWeight[e->getIndex()] += distanceToBndAndSing[v->getIndex()];
        elemWeight[e->getIndex()]/=(1.0*e->getNumVertices());
      }

      //Put random element as passed (or well chosen one)
      Element *elemLeft=m_m->getElement(0);
      elemPassed[elemLeft->getIndex()]=true;
      while(elemLeft){
        for(Edge *edg: elemLeft->getEdges()){
          if(edg->getNumElements() != 1 && edg->getNumLines() == 0){
            for(Element *e: edg->getElements()){
              if(!elemPassed[e->getIndex()]){
                pQueue.push(weightedElem(elemWeight[e->getIndex()],e));
                elemPassed[e->getIndex()]=true;
                edgeTree[edg->getIndex()] = false;
              }
            }
          }
        }
        if(!pQueue.empty()){
          elemLeft = pQueue.top().second;
          pQueue.pop();
        }
        else{
          elemLeft=NULL;
          for(Element *e: m_m->getElements()){
            if(!elemPassed[e->getIndex()]){
              elemLeft=e;
              elemPassed[elemLeft->getIndex()]=true;
              break;
            }
          }
        }
      }

      //edgeTree is now filled. There is a lot of floating leaves, trimming it now
      std::vector<int> multVert;
      multVert.resize(m_m->getNumVertices(), 0);
      std::vector<std::vector<size_t>> vertToEdg;
      vertToEdg.resize(m_m->getNumVertices());
      for(size_t k=0; k<m_m->getEdges().size(); k++){
        if(edgeTree[k]){
          Edge *edg = m_m->getEdge(k);
          for(Vertex *v: edg->getVertices()){
            multVert[v->getIndex()]++;
            vertToEdg[v->getIndex()].push_back(edg->getIndex());
          }
        }
      }
      for(auto &kv: m_singularitiesVertices)
        multVert[kv.first->getIndex()]++;
      for(Element *l: m_m->getLines())
        for(Vertex *v: l->getVertices())
          multVert[v->getIndex()]++;
      
      bool keepCleaning = true;
      while(keepCleaning){
        size_t indexLeaf = -1;
        for(size_t k=0; k<multVert.size(); k++){
          if(multVert[k] == 1){
            indexLeaf = k;
            break;
          }
        }
        if(indexLeaf != -1){
          while(indexLeaf != -1){
            Edge *edg;
            for(size_t indE: vertToEdg[indexLeaf]){
              if(edgeTree[indE]){
                edg = m_m->getEdge(indE);
                break;
              }
            }
            edgeTree[edg->getIndex()] = false;
            for(Vertex *v: edg->getVertices())
              multVert[v->getIndex()] -= 1;
            
            Vertex *newV;
            if(edg->getVertex(0)->getIndex() == indexLeaf)
              newV = edg->getVertex(1);
            else
              newV = edg->getVertex(0);
            
            if(multVert[newV->getIndex()] == 1)
              indexLeaf = newV->getIndex();
            else
              indexLeaf = -1;
          }
        }
        else
          keepCleaning = false;
      }
      //
      return edgeTree;
    }
    
    std::vector<Edge*> getCutGraph(){
      _locateSingularitiesVertices();
      _locateSingularities();
      if(m_singularities.size() > 0){
        throw std::invalid_argument("FrameField::getCutGraph: presence of singular triangles -> unable to create cutgraph. Consider using FrameField::getCleanedFramefield");
      }
      std::cout << "nSingularVertices: " << m_singularitiesVertices.size() << std::endl;;
      for(auto &kv: m_singularitiesVertices){
        kv.first->setVertOfInterest(true);
        kv.first->setValence(kv.second);
      }
      for(Vertex *v: m_m->getVertices()){
        int cptLines = 0;
        for(Edge *edg: v->getEdges())
          if(edg->getNumLines() == 1)
            cptLines++;
        if(cptLines==1)
          v->setVertOfInterest(true);
      }
      
      std::vector<double> distanceToBndAndSing = _computeDistanceToBndAndSing();
      std::vector<bool> isEdgeCutGraph = _createCleanedEdgeTree(distanceToBndAndSing);
      std::vector<Edge*> cutGraph;
      cutGraph.reserve(m_m->getNumEdges()/3);
      for(size_t k=0; k<m_m->getNumEdges(); k++){
        if(isEdgeCutGraph[k])
          cutGraph.push_back(m_m->getEdge(k));
      }
      cutGraph.shrink_to_fit();

      std::map<Vertex*, std::vector<int>> filterVertInterestBoundary;
      std::vector<int> init(2, 0);
      for(Vertex *v: m_m->getVertices())
        filterVertInterestBoundary[v] = init;
      for(Edge *e: m_m->getEdges()){
        if(e->getLines().size() == 1 || e->getElements().size() == 1){
          for(Vertex *v: e->getVertices())
            filterVertInterestBoundary[v][0] = 1;
        }
      }
      for(Edge *e: cutGraph)
        if(e->getLines().size() == 0 && e->getElements().size() != 1)
          for(Vertex *v: e->getVertices())
            filterVertInterestBoundary[v][1] = 1;
      for(auto &kv: filterVertInterestBoundary)
        if(kv.second[0] == 1 && kv.second[1] == 1)
          kv.first->setVertOfInterestBoundary(true);
      return cutGraph;
    }

    std::vector<std::vector<std::vector<double>>> _getFrameDirectionsOnElem(Element *e){
      int nEdges = e->getNumEdges();

      std::vector<std::vector<double>> solEl;
      solEl.resize(nEdges);
      for(size_t l=0; l<solEl.size(); l++)
        solEl[l].resize(T::nUnknown, 0.0);

      for(size_t l=0; l<solEl.size(); l++)
        solEl[l] = m_mapEdgeFrames[e->getEdge(l)].m_frame;
      std::vector<double> vRef = e->getDirEdg(0);
      std::vector<double> n = e->getNormal();
      std::vector<double> t = tools::crossprod(n, vRef);

      std::vector<std::vector<double>> solTriRotated;
      T::getRotatedSolEl(e, solEl, solTriRotated);

      std::vector<std::vector<std::vector<double>>> dirElemEdges(nEdges);
      for(size_t kEdg=0; kEdg<nEdges; kEdg++){
        Edge* edg = e->getEdge(kEdg);
        T frameEdge(solTriRotated[kEdg]);
        std::vector<std::vector<double>> dirsEdge = frameEdge.getDirectionsFromRef(vRef, n);
        dirElemEdges[kEdg] = dirsEdge;
      }
      return dirElemEdges;
    }
    
    void _createLifting(){
      m_lifting.clear();
      std::vector<std::vector<double>> initLift{{0.0, 0.0, 0.0},{0.0, 0.0, 0.0}};
      for(Element *e: m_m->getElements()){
        std::vector<std::vector<std::vector<double>>> listInitLift(e->getNumEdges(), initLift);
        m_lifting[e] = listInitLift;
      }
      // BFS
      std::vector<bool> elemPushed(m_m->getNumElements(), false);
      typedef std::pair<Element*, std::vector<std::vector<double>>> pairElemDirsRef;
      std::queue<pairElemDirsRef> queueElementDirsRef;
      //First pairElemDirsRef
      Element *initElem = m_m->getElement(0);
      std::vector<std::vector<std::vector<double>>> dirsEdgesElemInit = _getFrameDirectionsOnElem(initElem);
      std::vector<std::vector<double>> dirsEdge0(2);
      dirsEdge0[0] = dirsEdgesElemInit[0][0];
      dirsEdge0[1] = dirsEdgesElemInit[0][1];
      queueElementDirsRef.push(std::make_pair(initElem, dirsEdge0));
      elemPushed[initElem->getIndex()] = true;
      //
      while(queueElementDirsRef.size() > 0){
        auto [e, dirsRefElem] = queueElementDirsRef.front();
        queueElementDirsRef.pop();

        std::vector<std::vector<std::vector<double>>> dirsEdgesElem = _getFrameDirectionsOnElem(e);
        for(size_t kEdg=0; kEdg<e->getNumEdges(); kEdg++){
          Edge *edg= e->getEdge(kEdg);
          std::vector<std::vector<double>> dirsEdg = dirsEdgesElem[kEdg];
          std::vector<double> dirNext0 = tools::getClosestVect(dirsEdg, dirsRefElem[0]);
          std::vector<double> dirNext1 = tools::getClosestVect(dirsEdg, dirsRefElem[1]);
          //Store Lifting
          m_lifting[e][kEdg] = {dirNext0, dirNext1};
          //If next element not pushed, add it to the queue
          if(edg->getNumElements() > 1){
            Element *nextElem;
            if(e->getIndex() == edg->getElement(0)->getIndex())
              nextElem = edg->getElement(1);
            else
              nextElem = edg->getElement(0);
            if(!elemPushed[nextElem->getIndex()]){
              dirNext0 = manifoldTools::transportToNeighbourElement(e, nextElem, dirNext0);
              dirNext1 = manifoldTools::transportToNeighbourElement(e, nextElem, dirNext1);
              std::vector<std::vector<double>> refDirsNext{dirNext0, dirNext1};
              queueElementDirsRef.push(std::make_pair(nextElem, refDirsNext));
              elemPushed[nextElem->getIndex()] = true;
            }
          }
        }
        if(queueElementDirsRef.size() == 0){
          for(Element *el: m_m->getElements()){
            if(!elemPushed[el->getIndex()]){
              //Push element with arbitrary ref dirs
              std::vector<std::vector<std::vector<double>>> dirsEdgesElemInit = _getFrameDirectionsOnElem(el);
              std::vector<std::vector<double>> refDirsNext{dirsEdgesElemInit[0][0], dirsEdgesElemInit[0][1]};
              queueElementDirsRef.push(std::make_pair(el, refDirsNext));
            }
          }
        }
      }
    }

    void _getConstPotBC(std::vector<std::vector<Vertex*>> &listBCVertLift0, std::vector<std::vector<Vertex*>> &listBCVertLift1){
      listBCVertLift0.clear();
      listBCVertLift1.clear();
      //Create list of boundary vertices and give them a temporary index
      std::vector<Edge*> bndEdges;
      bndEdges.reserve(m_m->getNumEdges());
      std::vector<bool> isVertBnd(m_m->getNumVertices(), false);
      for(Edge *edg: m_m->getEdges()){
        if((edg->getNumElements() == 1 && !edg->isOnCutGraph()) || edg->getNumLines() == 1){
          bndEdges.push_back(edg);
          isVertBnd[edg->getVertex(0)->getIndex()] = true;
          isVertBnd[edg->getVertex(1)->getIndex()] = true;
        }
      }
      std::vector<Vertex*> bndVert; bndVert.reserve(m_m->getNumVertices());
      for(Vertex *v: m_m->getVertices())
        if(isVertBnd[v->getIndex()])
          bndVert.push_back(v);
      bndVert.shrink_to_fit();
      for(size_t kV=0; kV<bndVert.size(); kV++)
        bndVert[kV]->m_tempIndex = kV;
      //Get constant potential boundary bc for seamless
      std::vector<std::vector<size_t>> neighVertPot0;
      neighVertPot0.resize(bndVert.size());
      for(auto &v: neighVertPot0)
        v.reserve(2);
      std::vector<std::vector<size_t>> neighVertPot1;
      neighVertPot1.resize(bndVert.size());
      for(auto &v: neighVertPot1)
        v.reserve(2);
      for(Edge *edg: bndEdges){
        Element *elem = edg->getElement(0);
        size_t iLocEdg = edg->getLocIndexInElem(elem);
        std::vector<double> grad0 = m_lifting[elem][iLocEdg][0];
        tools::normalize(grad0);
        if(fabs(tools::dotprod(edg->getGeodesicNormal(), grad0)) > sqrt(2.0)/2.0){
          neighVertPot0[edg->getVertex(0)->m_tempIndex].push_back(edg->getVertex(1)->m_tempIndex);
          neighVertPot0[edg->getVertex(1)->m_tempIndex].push_back(edg->getVertex(0)->m_tempIndex);
        }
        else{
          neighVertPot1[edg->getVertex(0)->m_tempIndex].push_back(edg->getVertex(1)->m_tempIndex);
          neighVertPot1[edg->getVertex(1)->m_tempIndex].push_back(edg->getVertex(0)->m_tempIndex);              }
      }

      //Retreive lists of constant potential for pot0
      std::vector<bool> vertTreated0;
      vertTreated0.resize(neighVertPot0.size(), false);
      size_t indexStart = -1;
      for(size_t k=0; k<neighVertPot0.size(); k++)
        if(neighVertPot0[k].size()==1){
          indexStart = k;
          break;
        }
      while(indexStart != -1){
        std::vector<Vertex *> listVert;
        listVert.push_back(bndVert[indexStart]);
        vertTreated0[indexStart] = true;
        size_t currentIndex = indexStart;
        while(currentIndex != -1){
          size_t nextIndex = -1;
          if(vertTreated0[neighVertPot0[currentIndex][0]]){
            if(neighVertPot0[currentIndex].size() > 1)
              if(!vertTreated0[neighVertPot0[currentIndex][1]])
                nextIndex = neighVertPot0[currentIndex][1];
          }
          else
            if(!vertTreated0[neighVertPot0[currentIndex][0]])
              nextIndex = neighVertPot0[currentIndex][0];
          if(nextIndex != -1){
            listVert.push_back(bndVert[nextIndex]);
            vertTreated0[nextIndex] = true;
          }
          currentIndex = nextIndex;
        }

        listBCVertLift0.push_back(listVert);
        indexStart = -1;
        for(size_t k=0; k<neighVertPot0.size(); k++)
          if(neighVertPot0[k].size()==1 && !vertTreated0[k]){
            indexStart = k;
            break;
          }
      }

      //Retreive lists of constant potential for pot0
      std::vector<bool> vertTreated1;
      vertTreated1.resize(neighVertPot1.size(), false);
      indexStart = -1;
      for(size_t k=0; k<neighVertPot1.size(); k++)
        if(neighVertPot1[k].size()==1){
          indexStart = k;
          break;
        }
      while(indexStart != -1){
        std::vector<Vertex *> listVert;
        listVert.push_back(bndVert[indexStart]);
        vertTreated1[indexStart] = true;
        size_t currentIndex = indexStart;
        while(currentIndex != -1){
          size_t nextIndex = -1;
          if(vertTreated1[neighVertPot1[currentIndex][0]]){
            if(neighVertPot1[currentIndex].size() > 1)
              if(!vertTreated1[neighVertPot1[currentIndex][1]])
                nextIndex = neighVertPot1[currentIndex][1];
          }
          else
            if(!vertTreated1[neighVertPot1[currentIndex][0]])
              nextIndex = neighVertPot1[currentIndex][0];
          if(nextIndex != -1){
            listVert.push_back(bndVert[nextIndex]);
            vertTreated1[nextIndex] = true;
          }
          currentIndex = nextIndex;
        }

        listBCVertLift1.push_back(listVert);
        indexStart = -1;
        for(size_t k=0; k<neighVertPot1.size(); k++)
          if(neighVertPot1[k].size()==1 && !vertTreated1[k]){
            indexStart = k;
            break;
          }
      }
    }

    void _addQuantizedConditions(Solver &s, std::vector<std::pair<std::pair<Vertex*, Vertex*>, std::vector<std::pair<int, double>>>> &quantizedConditions){
      for(auto &conditions: quantizedConditions){
        auto pV = conditions.first;
        auto listCond = conditions.second;
        for(auto &cond: listCond){
          int indPot = cond.first;
          double val = cond.second;
          std::vector<std::vector<double>> mat;
          mat.resize(1);
          mat[0].resize(2, 0.0);
          mat[0][0] = 1.0;
          mat[0][1] = -1.0;
          std::vector<double> vect{val};
          std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(pV.second, indPot), std::make_pair(pV.first, indPot)};
          s.addBCLinearCombination(mat, vect, pairVertexField);

          std::cout << "indpot: " << indPot << std::endl;
          std::cout << "mat" << std::endl;
          std::cout << mat << std::endl;
          std::cout << "vect" << std::endl;
          std::cout << vect << std::endl;
        }
      }
    }

    void getQuantizedFrameFieldBC(std::vector<std::tuple<size_t, size_t, T>> &listFrameFieldBC){
      _createLifting();
      listFrameFieldBC.clear();
      //Create list of boundary vertices and give them a temporary index
      std::vector<Edge*> cgEdges;
      cgEdges.reserve(m_m->getNumEdges());
      std::vector<bool> isVertCG(m_m->getNumVertices(), false);
      std::map<Vertex *, int> constPotBnd;
      for(Edge *edg: m_m->getEdges()){
        if(edg->isOnCutGraph()){
          cgEdges.push_back(edg);
          isVertCG[edg->getVertex(0)->getIndex()] = true;
          isVertCG[edg->getVertex(1)->getIndex()] = true;
        }
        if(edg->getNumElements() == 1 && !edg->isOnCutGraph()){
          if(edg->getVertex(0)->isVertOfInterestBoundary()){
            Element *elem = edg->getElement(0);
            std::vector<double> grad0 = m_lifting[elem][edg->getLocIndexInElem(elem)][0];
            tools::normalize(grad0);
            if(fabs(tools::dotprod(edg->getGeodesicNormal(), grad0)) > sqrt(2.0)/2.0){
              constPotBnd[edg->getVertex(0)] = 0;
            }
            else
              constPotBnd[edg->getVertex(0)] = 1;
          }
          if(edg->getVertex(1)->isVertOfInterestBoundary()){
            Element *elem = edg->getElement(0);
            std::vector<double> grad0 = m_lifting[elem][edg->getLocIndexInElem(elem)][0];
            tools::normalize(grad0);
            if(fabs(tools::dotprod(edg->getGeodesicNormal(), grad0)) > sqrt(2.0)/2.0){
              constPotBnd[edg->getVertex(1)] = 0;
            }
            else
              constPotBnd[edg->getVertex(1)] = 1;
          }
        }
      }
      cgEdges.shrink_to_fit();
      std::vector<Vertex*> cgVert; cgVert.reserve(m_m->getNumVertices());
      for(Vertex *v: m_m->getVertices())
        if(isVertCG[v->getIndex()])
          cgVert.push_back(v);
      cgVert.shrink_to_fit();
      for(size_t kV=0; kV<cgVert.size(); kV++)
        cgVert[kV]->m_tempIndex = kV;
      //Get constant potential boundary bc for seamless
      std::vector<std::vector<size_t>> neighVert;
      neighVert.resize(cgVert.size());
      for(auto &v: neighVert)
        v.reserve(2);
      // std::vector<std::vector<size_t>> neighVertToVertInterest;
      // neighVertToVertInterest.resize(bndVert.size());
      // for(auto &v: neighVertToVertInterest)
      //   v.reserve(2);
      // std::vector<std::vector<size_t>> neighVertInterestToVert;
      // neighVertInterestToVert.resize(bndVert.size());
      // for(auto &v: neighVertInterestToVert)
      //   v.reserve(2);

      for(Edge *edg: cgEdges){
        neighVert[edg->getVertex(0)->m_tempIndex].push_back(edg->getVertex(1)->m_tempIndex);
        neighVert[edg->getVertex(1)->m_tempIndex].push_back(edg->getVertex(0)->m_tempIndex);
      }

      //Build loops
      std::vector<std::vector<Vertex*>> orderedVertCG;
      std::vector<bool> vertTreated;
      vertTreated.resize(neighVert.size(), false);
      size_t indexStart = -1;
      for(size_t k=0; k<neighVert.size(); k++)
        if(neighVert[k].size()==1){
          indexStart = k;
          break;
        }
      while(indexStart != -1){
        std::vector<Vertex *> listVert;
        listVert.push_back(cgVert[indexStart]);
        vertTreated[indexStart] = true;
        size_t currentIndex = indexStart;
        while(currentIndex != -1){
          size_t nextIndex = -1;
          if(vertTreated[neighVert[currentIndex][0]]){
            if(neighVert[currentIndex].size() > 1)
              if(!vertTreated[neighVert[currentIndex][1]])
                nextIndex = neighVert[currentIndex][1];
          }
          else
            if(!vertTreated[neighVert[currentIndex][0]])
              nextIndex = neighVert[currentIndex][0];
          if(nextIndex != -1){
            listVert.push_back(cgVert[nextIndex]);
            vertTreated[nextIndex] = true;
          }
          currentIndex = nextIndex;
        }

        orderedVertCG.push_back(listVert);
        indexStart = -1;
        for(size_t k=0; k<neighVert.size(); k++)
          if(neighVert[k].size()==1 && !vertTreated[k]){
            indexStart = k;
            break;
          }
      }
      //Split lists of orderedVertCG on vertices of interest
      std::vector<std::vector<Vertex*>> splitOrderedVertCG;
      for(auto &lv: orderedVertCG){
        bool keepSplitting = true;
        size_t currentInd = 0;
        while(keepSplitting){
          std::vector<Vertex*> splitList;
          splitList.reserve(lv.size());
          splitList.push_back(lv[currentInd]);
          bool keepAdding = true;
          while(keepAdding){
            currentInd++;
            Vertex *v = lv[currentInd];
            splitList.push_back(v);
            if(v->isVertOfInterest() || v->isVertOfInterestBoundary())
              keepAdding = false;
          }
          splitOrderedVertCG.push_back(splitList);
          if(currentInd == lv.size()-1)
            keepSplitting = false;
        }
      }
      std::cout << "n orderedvert: " << orderedVertCG.size() << std::endl;
      std::cout << "n plit: " << splitOrderedVertCG.size() << std::endl;

      //Define quantized conditions
      for(auto &lv: splitOrderedVertCG){
        std::pair<Vertex*, Vertex*> pairVert(lv[0], lv[lv.size()-1]);
        std::vector<int> potQuantized;
        if(pairVert.first->isVertOfInterestBoundary()){
          potQuantized = {constPotBnd[pairVert.first]};
          // potQuantized = {};
        }
        else if(pairVert.second->isVertOfInterestBoundary()){
          potQuantized = {constPotBnd[pairVert.second]};
          // potQuantized = {};
        }
        else{
          potQuantized = {};
          // potQuantized = {0,1};
        }
        if(potQuantized.size() == 1){
          for(int potInd: potQuantized){
            // if(potInd == 0){//DBG
            double valDiff = 0.0;
            for(size_t kV=0; kV<lv.size()-1; kV++){
              Vertex *v0 = lv[kV];
              Vertex *v1 = lv[kV+1];
              Edge *edg = Edge::getCommonEdge(v0, v1);
              Element *elem = edg->getElement(0);
              int iLocEdg = edg->getLocIndexInElem(elem);
              std::vector<double> grad;
              std::vector<double> secondBranch;
              if(potInd == 0){
                grad = m_lifting[elem][iLocEdg][0];
                secondBranch = m_lifting[elem][iLocEdg][1];
              }
              else{
                grad = m_lifting[elem][iLocEdg][1];
                secondBranch = m_lifting[elem][iLocEdg][0];
                tools::scale(secondBranch, -1.0);
              }
              double normGrad = tools::norm(grad);
              tools::normalize(grad);
              valDiff += tools::dotprod(grad,tools::diff(v1->getCoord(), v0->getCoord()))/normGrad;
            }
            double previousParamLength = valDiff;
            valDiff = std::round(valDiff);
            if(potQuantized.size() == 1){
              if(valDiff < 0)
                valDiff = std::min(-1.0, valDiff);
              else
                valDiff = std::max(1.0, valDiff);
            }
            double scalingToApply = previousParamLength/valDiff;
            //Build Frame BC
            for(size_t kV=0; kV<lv.size()-1; kV++){
              Vertex *v0 = lv[kV];
              Vertex *v1 = lv[kV+1];
              Edge *edg = Edge::getCommonEdge(v0, v1);
              Element *elem = edg->getElement(0);
              int iLocEdg = edg->getLocIndexInElem(elem);
              std::vector<double> grad;
              std::vector<double> secondBranch;
              if(potInd == 0){
                grad = m_lifting[elem][iLocEdg][0];
                secondBranch = m_lifting[elem][iLocEdg][1];
              }
              else{
                grad = m_lifting[elem][iLocEdg][1];
                secondBranch = m_lifting[elem][iLocEdg][0];
                tools::scale(secondBranch, -1.0);
              }
              tools::scale(grad, scalingToApply);
              std::vector<double> vRef = elem->getDirEdg(iLocEdg);
              std::vector<double> n = elem->getNormal();
              std::vector<double> t = tools::crossprod(n, vRef);
              std::vector<double> dir1{tools::dotprod(vRef, grad), tools::dotprod(t, grad)};
              std::vector<double> dir2{tools::dotprod(vRef, secondBranch), tools::dotprod(t, secondBranch)};
              T frameBC({dir1, dir2});
              listFrameFieldBC.push_back(std::make_tuple(elem->getIndex(), iLocEdg, frameBC));
            }
          }
        }
        else if(potQuantized.size() == 2){
          std::vector<double> scalingBranches;
          scalingBranches.reserve(2);

          for(int potInd: potQuantized){
            double valDiff = 0.0;
            for(size_t kV=0; kV<lv.size()-1; kV++){
              Vertex *v0 = lv[kV];
              Vertex *v1 = lv[kV+1];
              Edge *edg = Edge::getCommonEdge(v0, v1);
              Element *elem = edg->getElement(0);
              int iLocEdg = edg->getLocIndexInElem(elem);
              std::vector<double> grad;
              if(potInd == 0){
                grad = m_lifting[elem][iLocEdg][0];
              }
              else{
                grad = m_lifting[elem][iLocEdg][1];
              }
              double normGrad = tools::norm(grad);
              tools::normalize(grad);
              valDiff += tools::dotprod(grad,tools::diff(v1->getCoord(), v0->getCoord()))/normGrad;

            }
            double previousParamLength = valDiff;
            valDiff = std::round(valDiff);
            // if(potQuantized.size() == 1){
            //   if(valDiff < 0)
            //     valDiff = std::min(-1.0, valDiff);
            //   else
            //     valDiff = std::max(1.0, valDiff);
            // }
            double scalingToApply = 1.0;
            if(fabs(valDiff) > 1e-12)
              scalingToApply = previousParamLength/valDiff;
            
            scalingBranches.push_back(scalingToApply);
          }
          //Build Frame BC
          for(size_t kV=0; kV<lv.size()-1; kV++){
            Vertex *v0 = lv[kV];
            Vertex *v1 = lv[kV+1];
            Edge *edg = Edge::getCommonEdge(v0, v1);
            Element *elem = edg->getElement(0);
            int iLocEdg = edg->getLocIndexInElem(elem);
            std::vector<double> grad;
            std::vector<double> secondBranch;
            grad = m_lifting[elem][iLocEdg][0];
            secondBranch = m_lifting[elem][iLocEdg][1];
            tools::scale(grad, scalingBranches[0]);
            tools::scale(secondBranch, scalingBranches[1]);
            std::vector<double> vRef = elem->getDirEdg(iLocEdg);
            std::vector<double> n = elem->getNormal();
            std::vector<double> t = tools::crossprod(n, vRef);
            std::vector<double> dir1{tools::dotprod(vRef, grad), tools::dotprod(t, grad)};
            std::vector<double> dir2{tools::dotprod(vRef, secondBranch), tools::dotprod(t, secondBranch)};
            T frameBC({dir1, dir2});
            listFrameFieldBC.push_back(std::make_tuple(elem->getIndex(), iLocEdg, frameBC));
          }
        }
      }
      // listFrameFieldBC.clear();//DBG
    }
    
    void _getQuantizedConditions(std::map<Element*, std::vector<std::vector<double>>> &lift0, std::map<Element*, std::vector<std::vector<double>>> &lift1, std::vector<std::pair<std::pair<Vertex*, Vertex*>, std::vector<std::pair<int, double>>>> &quantizedConditions){
      //Create list of boundary vertices and give them a temporary index
      std::vector<Edge*> cgEdges;
      cgEdges.reserve(m_m->getNumEdges());
      std::vector<bool> isVertCG(m_m->getNumVertices(), false);
      std::map<Vertex *, int> constPotBnd;
      for(Edge *edg: m_m->getEdges()){
        if(edg->isOnCutGraph()){
          cgEdges.push_back(edg);
          isVertCG[edg->getVertex(0)->getIndex()] = true;
          isVertCG[edg->getVertex(1)->getIndex()] = true;
        }
        if(edg->getNumElements() == 1 && !edg->isOnCutGraph()){
          if(edg->getVertex(0)->isVertOfInterestBoundary()){
            Element *elem = edg->getElement(0);
            std::vector<double> grad0 = m_lifting[elem][edg->getLocIndexInElem(elem)][0];
            tools::normalize(grad0);
            if(fabs(tools::dotprod(edg->getGeodesicNormal(), grad0)) > sqrt(2.0)/2.0){
              constPotBnd[edg->getVertex(0)] = 0;
            }
            else
              constPotBnd[edg->getVertex(0)] = 1;
          }
          if(edg->getVertex(1)->isVertOfInterestBoundary()){
            Element *elem = edg->getElement(0);
            std::vector<double> grad0 = m_lifting[elem][edg->getLocIndexInElem(elem)][0];
            tools::normalize(grad0);
            if(fabs(tools::dotprod(edg->getGeodesicNormal(), grad0)) > sqrt(2.0)/2.0){
              constPotBnd[edg->getVertex(1)] = 0;
            }
            else
              constPotBnd[edg->getVertex(1)] = 1;
          }
        }
      }
      cgEdges.shrink_to_fit();
      std::vector<Vertex*> cgVert; cgVert.reserve(m_m->getNumVertices());
      for(Vertex *v: m_m->getVertices())
        if(isVertCG[v->getIndex()])
          cgVert.push_back(v);
      cgVert.shrink_to_fit();
      for(size_t kV=0; kV<cgVert.size(); kV++)
        cgVert[kV]->m_tempIndex = kV;
      //Get constant potential boundary bc for seamless
      std::vector<std::vector<size_t>> neighVert;
      neighVert.resize(cgVert.size());
      for(auto &v: neighVert)
        v.reserve(2);
      // std::vector<std::vector<size_t>> neighVertToVertInterest;
      // neighVertToVertInterest.resize(bndVert.size());
      // for(auto &v: neighVertToVertInterest)
      //   v.reserve(2);
      // std::vector<std::vector<size_t>> neighVertInterestToVert;
      // neighVertInterestToVert.resize(bndVert.size());
      // for(auto &v: neighVertInterestToVert)
      //   v.reserve(2);

      for(Edge *edg: cgEdges){
        neighVert[edg->getVertex(0)->m_tempIndex].push_back(edg->getVertex(1)->m_tempIndex);
        neighVert[edg->getVertex(1)->m_tempIndex].push_back(edg->getVertex(0)->m_tempIndex);
      }

      //Build loops
      std::vector<std::vector<Vertex*>> orderedVertCG;
      std::vector<bool> vertTreated;
      vertTreated.resize(neighVert.size(), false);
      size_t indexStart = -1;
      for(size_t k=0; k<neighVert.size(); k++)
        if(neighVert[k].size()==1){
          indexStart = k;
          break;
        }
      while(indexStart != -1){
        std::vector<Vertex *> listVert;
        listVert.push_back(cgVert[indexStart]);
        vertTreated[indexStart] = true;
        size_t currentIndex = indexStart;
        while(currentIndex != -1){
          size_t nextIndex = -1;
          if(vertTreated[neighVert[currentIndex][0]]){
            if(neighVert[currentIndex].size() > 1)
              if(!vertTreated[neighVert[currentIndex][1]])
                nextIndex = neighVert[currentIndex][1];
          }
          else
            if(!vertTreated[neighVert[currentIndex][0]])
              nextIndex = neighVert[currentIndex][0];
          if(nextIndex != -1){
            listVert.push_back(cgVert[nextIndex]);
            vertTreated[nextIndex] = true;
          }
          currentIndex = nextIndex;
        }

        orderedVertCG.push_back(listVert);
        indexStart = -1;
        for(size_t k=0; k<neighVert.size(); k++)
          if(neighVert[k].size()==1 && !vertTreated[k]){
            indexStart = k;
            break;
          }
      }
      //Split lists of orderedVertCG on vertices of interest
      std::vector<std::vector<Vertex*>> splitOrderedVertCG;
      for(auto &lv: orderedVertCG){
        bool keepSplitting = true;
        size_t currentInd = 0;
        while(keepSplitting){
          std::vector<Vertex*> splitList;
          splitList.reserve(lv.size());
          splitList.push_back(lv[currentInd]);
          bool keepAdding = true;
          while(keepAdding){
            currentInd++;
            Vertex *v = lv[currentInd];
            splitList.push_back(v);
            if(v->isVertOfInterest() || v->isVertOfInterestBoundary())
              keepAdding = false;
          }
          splitOrderedVertCG.push_back(splitList);
          if(currentInd == lv.size()-1)
            keepSplitting = false;
        }
      }
      std::cout << "n orderedvert: " << orderedVertCG.size() << std::endl;
      std::cout << "n plit: " << splitOrderedVertCG.size() << std::endl;

      //Define quantized conditions
      quantizedConditions.clear();
      for(auto &lv: splitOrderedVertCG){
        std::pair<Vertex*, Vertex*> pairVert(lv[0], lv[lv.size()-1]);
        std::vector<std::pair<int, double>> pairsPotval;
        std::vector<int> potQuantized;
        if(pairVert.first->isVertOfInterestBoundary()){
          potQuantized = {constPotBnd[pairVert.first]};
          // potQuantized = {};
        }
        else if(pairVert.second->isVertOfInterestBoundary()){
          potQuantized = {constPotBnd[pairVert.second]};
          // potQuantized = {};
        }
        else{
          potQuantized = {};
          // potQuantized = {0,1};
        }
        for(int potInd: potQuantized){
          // if(potInd == 0){//DBG
            double valDiff = 0.0;
            for(size_t kV=0; kV<lv.size()-1; kV++){
              Vertex *v0 = lv[kV];
              Vertex *v1 = lv[kV+1];
              Edge *edg = Edge::getCommonEdge(v0, v1);
              Element *elem = edg->getElement(0);
              int iLocEdg = edg->getLocIndexInElem(elem);
              std::vector<double> grad;
              if(potInd == 0)
                grad = lift0[elem][iLocEdg];
              else
                grad = lift1[elem][iLocEdg];
              // valDiff = tools::dotprod(grad,tools::getNormalizedVector(tools::diff(v1->getCoord(), v0->getCoord())));
              valDiff += tools::dotprod(grad,tools::diff(v1->getCoord(), v0->getCoord()));
            }
            valDiff = std::round(valDiff);
            if(potQuantized.size() == 1){
              if(valDiff < 0)
                valDiff = std::min(-1.0, valDiff);
              else
                valDiff = std::max(1.0, valDiff);
            }
            // valDiff = 8*valDiff/fabs(valDiff);//DBG
            pairsPotval.push_back(std::make_pair(potInd, valDiff));
          // }
        }
        quantizedConditions.push_back(std::make_pair(pairVert, pairsPotval));
      }
    }

    void _addBndBCforSmeamless(Solver &s, std::vector<std::vector<Vertex*>> &listBCVertLift0, std::vector<std::vector<Vertex*>> &listBCVertLift1){
      //Add boundary bc for seamless
      for(auto &vectVconst: listBCVertLift0){
        for(size_t k=1; k<vectVconst.size(); k++){
          std::vector<std::vector<double>> mat;
          mat.resize(1);
          mat[0].resize(2, 0.0);
          mat[0][0] = 1.0;
          mat[0][1] = -1.0;
          std::vector<double> vect{0.0};
          std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(vectVconst[0], 0), std::make_pair(vectVconst[k], 0)};
          s.addBCLinearCombination(mat, vect, pairVertexField);
        }
      }
      for(auto &vectVconst: listBCVertLift1){
        for(size_t k=1; k<vectVconst.size(); k++){
          std::vector<std::vector<double>> mat;
          mat.resize(1);
          mat[0].resize(2, 0.0);
          mat[0][0] = 1.0;
          mat[0][1] = -1.0;
          std::vector<double> vect{0.0};
          std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(vectVconst[0], 1), std::make_pair(vectVconst[k], 1)};
          s.addBCLinearCombination(mat, vect, pairVertexField);
        }
      }
    }

    void _addBndQuantizationBC(Solver &s, std::map<Element*, std::vector<std::vector<double>>> &lift0, std::map<Element*, std::vector<std::vector<double>>> &lift1){
      //TODO: do it for lines instead of geometric boundary edges
      //TODO: in the cut procedure of mesh refinement, rebuild lines
      for(Edge *edg: m_m->getEdges()){
        if(edg->getNumElements() == 1 && !edg->isOnCutGraph()){
          Element *elem = edg->getElement(0);
          std::vector<double> dirEdg = edg->getDir();
          size_t iLocEdg = edg->getLocIndexInElem(elem);
          std::vector<double> grad0 = lift0[elem][iLocEdg];
          tools::normalize(grad0);
          std::vector<double> grad;
          int indPot = 0;
          if(fabs(tools::dotprod(edg->getGeodesicNormal(), grad0)) > sqrt(2.0)/2.0){
            grad = lift1[elem][iLocEdg];
            // grad = m_lifting[elem][iLocEdg][1];
            indPot = 1;
          }
          else{
            grad = lift0[elem][iLocEdg];
            // grad = m_lifting[elem][iLocEdg][0];
            indPot = 0;
          }
          double ps = tools::dotprod(grad, dirEdg);
          double valDiff = tools::norm(grad)*edg->getLength();
          double sign = 1.0;
          if(ps < 0)
            sign = -1.0;
          std::vector<std::vector<double>> mat;
          mat.resize(1);
          mat[0].resize(2, 0.0);
          mat[0][0] = -1.0;
          mat[0][1] = 1.0;
          std::vector<double> vect{valDiff*sign};
          std::vector<std::pair<Vertex *, int>> pairVertexField{std::make_pair(edg->getVertex(0), indPot), std::make_pair(edg->getVertex(1), indPot)};
          s.addBCLinearCombination(mat, vect, pairVertexField);
        }
      }

    }

    void _addCutGraphBCforSeamless(Solver &s, std::map<Element*, std::vector<std::vector<double>>> &lift0, std::map<Element*, std::vector<std::vector<double>>> &lift1){
      //Add cutgraph condition for seamless
      for(Edge *edg: m_m->getEdges()){
        if(edg->isOnCutGraph()){
          Element *elem = edg->getElement(0);
          size_t nEdges = elem->getNumEdges();
          size_t iLocEdgCurrent = edg->getLocIndexInElem(elem);
          Element *elementOtherSide = edg->getNeighbourElementAcrossCut();
          size_t nEdgesOtherSide = elementOtherSide->getNumEdges();
          Edge *edgOtherSide = edg->getNeighbourEdgeAcrossCut();
          size_t iLocEdgOtherSide = edgOtherSide->getLocIndexInElem(elementOtherSide);
          std::vector<std::vector<double>> dirsOtherSide(4);
          dirsOtherSide[0] = lift0[elementOtherSide][iLocEdgOtherSide];
          dirsOtherSide[1] = lift1[elementOtherSide][iLocEdgOtherSide];
          dirsOtherSide[2] = lift0[elementOtherSide][iLocEdgOtherSide];
          dirsOtherSide[3] = lift1[elementOtherSide][iLocEdgOtherSide];
          tools::scale(dirsOtherSide[2], -1.0);
          tools::scale(dirsOtherSide[3], -1.0);
          for(size_t kDir=0; kDir<4; kDir++)
            dirsOtherSide[kDir] = manifoldTools::transportToNeighbourElement(elementOtherSide, elem, dirsOtherSide[kDir], edg);
          int indClosest0 = tools::getIndexClosestVect(dirsOtherSide, lift0[elem][iLocEdgCurrent]);
          int indClosest1 = tools::getIndexClosestVect(dirsOtherSide, lift1[elem][iLocEdgCurrent]);
          std::vector<std::vector<double>> mat(2);
          for(auto &v: mat)
            v.resize(8, 0.0);
          std::vector<double> vect(2,0.0);
          std::vector<std::pair<Vertex*, int>> listPairVF; listPairVF.reserve(8);
          listPairVF.push_back(std::make_pair(elem->getVertex(iLocEdgCurrent), 0));//Ugk 0
          listPairVF.push_back(std::make_pair(elementOtherSide->getVertex((iLocEdgOtherSide+1)%nEdgesOtherSide), 0));//Udk 1
          listPairVF.push_back(std::make_pair(elem->getVertex(iLocEdgCurrent), 1));//Vgk 2
          listPairVF.push_back(std::make_pair(elementOtherSide->getVertex((iLocEdgOtherSide+1)%nEdgesOtherSide), 1));//Vdk 3
          listPairVF.push_back(std::make_pair(elem->getVertex((iLocEdgCurrent+1)%nEdges), 0));//Ugk+1 4
          listPairVF.push_back(std::make_pair(elementOtherSide->getVertex(iLocEdgOtherSide), 0));//Udk+1 5
          listPairVF.push_back(std::make_pair(elem->getVertex((iLocEdgCurrent+1)%nEdges), 1));//Vgk+1 6
          listPairVF.push_back(std::make_pair(elementOtherSide->getVertex(iLocEdgOtherSide), 1));//Vdk+1 7
          // std::cout << "index closest: " << indClosest0 << std::endl;
          if(indClosest0 == 0){
            mat[0][0] = 1.0; mat[0][1] = -1.0; mat[0][4] = -1.0; mat[0][5] = 1.0;
            mat[1][2] = 1.0; mat[1][3] = -1.0; mat[1][6] = -1.0; mat[1][7] = 1.0;
            s.addBCLinearCombination(mat, vect, listPairVF);
            // std::cout << "indexClosest0 not implemented" << std::endl;
            // exit(0);
          }
          else if(indClosest0 == 1){
            mat[0][5] = 1.0; mat[0][6] = 1.0; mat[0][2] = -1.0; mat[0][1] = -1.0;
            mat[1][7] = 1.0; mat[1][4] = -1.0; mat[1][3] = -1.0; mat[1][0] = 1.0;
            s.addBCLinearCombination(mat, vect, listPairVF);
          }
          else if(indClosest0 == 2){
            // int nothing;
            mat[0][0] = 1.0; mat[0][1] = 1.0; mat[0][4] = -1.0; mat[0][5] = -1.0;
            mat[1][2] = 1.0; mat[1][3] = 1.0; mat[1][6] = -1.0; mat[1][7] = -1.0;
            s.addBCLinearCombination(mat, vect, listPairVF);
            // std::cout << "indexClosest2 not implemented" << std::endl;
            // exit(0);
          }
          else if(indClosest0 == 3){
            int nothing;
            // mat[0][4] = 1.0; mat[0][7] = 1.0; mat[0][0] = -1.0; mat[0][3] = -1.0;
            // mat[1][6] = 1.0; mat[1][5] = -1.0; mat[1][2] = -1.0; mat[1][1] = 1.0;
            // // s.addBCLinearCombination(mat, vect, listPairVF);
            // std::cout << "indexClosest3 not implemented" << std::endl;
            // exit(0);
          }
          else{
            std::cout << "Problem applying semsless condition on cutgraph" << std::endl;
            exit(0);
          }
          // s.addBCLinearCombination(mat, vect, listPairVF);
        }
      }
    }
    
    void _solveSeamlessPotentials(){
      std::map<Element*, std::vector<std::vector<double>>> lift0;
      std::map<Element*, std::vector<std::vector<double>>> lift1;
      for(auto &kv: m_lifting){
        size_t nEdges = kv.first->getNumEdges();
        lift0[kv.first].resize(nEdges);
        lift1[kv.first].resize(nEdges);
        for(size_t kEdg=0; kEdg<nEdges; kEdg++){
          lift0[kv.first][kEdg] = kv.second[kEdg][0];
          lift1[kv.first][kEdg] = kv.second[kEdg][1];
        }
      }
      for(auto &kv: lift0){
        for(auto &v: kv.second){
          double norm2 = tools::norm2(v);
          tools::scale(v, 1.0/norm2);
        }
      }
      for(auto &kv: lift1){
        for(auto &v: kv.second){
          double norm2 = tools::norm2(v);
          tools::scale(v, 1.0/norm2);
        }
      }
      std::vector<std::vector<Vertex*>> listBCVertLift0;
      std::vector<std::vector<Vertex*>> listBCVertLift1;
      _getConstPotBC(listBCVertLift0, listBCVertLift1);
        
      std::map<Element*, std::vector<std::vector<double>>> doubleCrossLifting;
      for(Element *e: m_m->getElements()){
        std::vector<std::vector<double>> concatLifting;
        concatLifting.resize(e->getNumEdges());
        for(auto &v: concatLifting)
          v.resize(6, 0.0);
        std::vector<std::vector<double>> liftElem0 = lift0[e];
        std::vector<std::vector<double>> liftElem1 = lift1[e];
        for(size_t k=0; k<e->getNumEdges(); k++){
          for(size_t jX=0; jX<3; jX++){
            concatLifting[k][jX] = liftElem0[k][jX];
            concatLifting[k][3+jX] = liftElem1[k][jX];
          }
        }
        doubleCrossLifting[e] = concatLifting;
      }
      
      ObjectiveFunction *fObjPot = new DoublePotential();
      Solver s(m_m, 2, fObjPot, Solver::TYPEUNKNOWN::VERTEX);
      s.setElementData(doubleCrossLifting);
      std::map<Vertex*, std::vector<double>> sol; //Initial solution
      //Fix potentials on one vertex
      s.addBCDirichlet(std::make_pair(m_m->getVertex(0), 0), 0.0);
      s.addBCDirichlet(std::make_pair(m_m->getVertex(0), 1), 0.0);
      //
      _addBndBCforSmeamless(s, listBCVertLift0, listBCVertLift1);
      _addCutGraphBCforSeamless(s, lift0, lift1);
      
      // //Quantized conditions
      // std::vector<std::pair<std::pair<Vertex*, Vertex*>, std::vector<std::pair<int, double>>>> quantizedConditions;
      // _getQuantizedConditions(lift0, lift1, quantizedConditions);
      // _addQuantizedConditions(s, quantizedConditions);
      // //

      // //Add quantization constraint on boundary
      // _addBndQuantizationBC(s, lift0, lift1);

      //Solve problem
      std::map<Vertex *, std::vector<double>> pots;
      s.solve(pots);
      m_seamLessPot0.clear();
      m_seamLessPot1.clear();
      for(auto &kv: pots){
        m_seamLessPot0[kv.first] = kv.second[0];
        m_seamLessPot1[kv.first] = kv.second[1];
      }
      std::map<Element*, std::vector<double>> elemU;
      std::map<Element*, std::vector<double>> elemV;
      for(Element *e: m_m->getElements()){
        elemU[e].clear();
        for(Vertex *v: e->getVertices()){
          elemU[e].push_back(m_seamLessPot0[v]);
          elemV[e].push_back(m_seamLessPot1[v]);
        }
      }
      visu::integerPotentialOnMesh(elemU, "U");
      visu::integerPotentialOnMesh(elemV, "V");
    }

    void _solveSeamlessPotentialsWithIntProj(std::vector<Vertex*> &listIntegerVertices, std::vector<std::pair<Vertex*, int>> listHalfIntegerVertices){
      std::map<Element*, std::vector<std::vector<double>>> lift0;
      std::map<Element*, std::vector<std::vector<double>>> lift1;
      for(auto &kv: m_lifting){
        size_t nEdges = kv.first->getNumEdges();
        lift0[kv.first].resize(nEdges);
        lift1[kv.first].resize(nEdges);
        for(size_t kEdg=0; kEdg<nEdges; kEdg++){
          lift0[kv.first][kEdg] = kv.second[kEdg][0];
          lift1[kv.first][kEdg] = kv.second[kEdg][1];
        }
      }
      for(auto &kv: lift0){
        for(auto &v: kv.second){
          double norm2 = tools::norm2(v);
          tools::scale(v, 1.0/norm2);
        }
      }
      for(auto &kv: lift1){
        for(auto &v: kv.second){
          double norm2 = tools::norm2(v);
          tools::scale(v, 1.0/norm2);
        }
      }
      std::vector<std::vector<Vertex*>> listBCVertLift0;
      std::vector<std::vector<Vertex*>> listBCVertLift1;
      _getConstPotBC(listBCVertLift0, listBCVertLift1);

      std::map<Element*, std::vector<std::vector<double>>> doubleCrossLifting;
      for(Element *e: m_m->getElements()){
        std::vector<std::vector<double>> concatLifting;
        concatLifting.resize(e->getNumEdges());
        for(auto &v: concatLifting)
          v.resize(6, 0.0);
        std::vector<std::vector<double>> liftElem0 = lift0[e];
        std::vector<std::vector<double>> liftElem1 = lift1[e];
        for(size_t k=0; k<e->getNumEdges(); k++){
          for(size_t jX=0; jX<3; jX++){
            concatLifting[k][jX] = liftElem0[k][jX];
            concatLifting[k][3+jX] = liftElem1[k][jX];
          }
        }
        doubleCrossLifting[e] = concatLifting;
      }
      
      ObjectiveFunction *fObjPot = new DoublePotential();
      Solver s(m_m, 2, fObjPot, Solver::TYPEUNKNOWN::VERTEX);
      s.setElementData(doubleCrossLifting);
      std::map<Vertex*, std::vector<double>> sol; //Initial solution
      //Fix integer potentials on singularities
      // for(Vertex *v: listIntegerVertices){
      //   // std::cout << "vert of interest previous" << std::endl;
      //   double intProjPot0 = std::round(m_seamLessPot0[v]);
      //   double intProjPot1 = std::round(m_seamLessPot1[v]);
      //   // std::cout << "true val: " << m_seamLessPot0[v] << ", " << m_seamLessPot1[v] << std::endl;
      //   // std::cout << "rounded val: " << intProjPot0 << ", " << intProjPot1 << std::endl;
      // }
      _addBndBCforSmeamless(s, listBCVertLift0, listBCVertLift1);
      _addCutGraphBCforSeamless(s, lift0, lift1);
      
      int cpt = 0;
      for(Vertex *v: listIntegerVertices){
        // std::cout << "vert of interest" << std::endl;
        double intProjPot0 = std::round(m_seamLessPot0intSing[v]);
        double intProjPot1 = std::round(m_seamLessPot1intSing[v]);
        // std::cout << "imposing rounded val: " << intProjPot0 << ", " << intProjPot1 << std::endl;
        s.addBCDirichlet(std::make_pair(v, 0), intProjPot0);
        s.addBCDirichlet(std::make_pair(v, 1), intProjPot1);
        // cpt++;
        // if(cpt > 0)
      }
      for(auto &hv: listHalfIntegerVertices){
        // std::cout << "vert of interest" << std::endl;
        double intProjPot0 = std::round(m_seamLessPot0intSing[hv.first]);
        double intProjPot1 = std::round(m_seamLessPot1intSing[hv.first]);
        // std::cout << "imposing rounded val: " << intProjPot0 << ", " << intProjPot1 << std::endl;
        if(hv.second == 0)
          s.addBCDirichlet(std::make_pair(hv.first, 0), intProjPot0);
        if(hv.second == 1)
          s.addBCDirichlet(std::make_pair(hv.first, 1), intProjPot1);
        // cpt++;
        // if(cpt > 0)
      }
      //
      // //Quantized conditions
      // std::vector<std::pair<std::pair<Vertex*, Vertex*>, std::vector<std::pair<int, double>>>> quantizedConditions;
      // _getQuantizedConditions(lift0, lift1, quantizedConditions);
      // _addQuantizedConditions(s, quantizedConditions);
      // //
      

      // //Add quantization constraint on boundary
      // _addBndQuantizationBC(s, lift0, lift1);
      
      //Solve problem
      std::map<Vertex *, std::vector<double>> pots;
      s.solve(pots);
      // for(Vertex *v: m_m->getVertices())
      //   if(v->isVertOfInterest()){
      //     std::cout << "vert of interest new compute" << std::endl;
      //     double intProjPot0 = std::round(pots[v][0]);
      //     double intProjPot1 = std::round(pots[v][1]);
      //     std::cout << "true val: " << pots[v][0] << ", " << pots[v][1] << std::endl;
      //     std::cout << "rounded val: " << intProjPot0 << ", " << intProjPot1 << std::endl;
      //   }
      // //Only for visu
      // for(Vertex *v: listIntegerVertices){
      //   pots[v][0] += 0.01;
      //   pots[v][1] += 0.01;
      //   break;
      // }
      // //

      m_seamLessPot0intSing.clear();
      m_seamLessPot1intSing.clear();
      for(auto &kv: pots){
        m_seamLessPot0intSing[kv.first] = kv.second[0];
        m_seamLessPot1intSing[kv.first] = kv.second[1];
      }
    }

    double distToInt(Vertex *v){
      double pot0 = m_seamLessPot0intSing[v];
      double pot1 = m_seamLessPot1intSing[v];
      return fabs(pot0 - std::round(pot0)) + fabs(pot1 - std::round(pot1));
    }

    double distToInt(std::pair<Vertex*, int> vF){
      double pot;
      if(vF.second == 0)
        pot = m_seamLessPot0intSing[vF.first];
      else if(vF.second == 1)
        pot = m_seamLessPot1intSing[vF.first];
      else{
        std::cout << "Wrong pot index" << std::endl;
        exit(0);
      }
      return fabs(pot - std::round(pot));
    }
    
    void _solveSeamlessPotentialsWithIntProj(){
      m_seamLessPot0intSing.clear();
      m_seamLessPot1intSing.clear();
      for(auto &kv: m_seamLessPot0)
        m_seamLessPot0intSing[kv.first] = kv.second;

      for(auto &kv: m_seamLessPot1)
        m_seamLessPot1intSing[kv.first] = kv.second;

      std::vector<Vertex*> verticesOfInterest;
      std::vector<std::pair<Vertex*, int>> verticesOfInterestHalfPair;
      for(Vertex *v: m_m->getVertices())
        if(v->isVertOfInterest()){
          verticesOfInterest.push_back(v);
          verticesOfInterestHalfPair.push_back(std::make_pair(v, 0));
          verticesOfInterestHalfPair.push_back(std::make_pair(v, 1));
        }
      std::vector<Vertex*> verticesOfInterestBoundary;
      for(Vertex *v: m_m->getVertices())
        if(v->isVertOfInterestBoundary())
          verticesOfInterestBoundary.push_back(v);
      std::vector<Vertex*> listIntegerVertices;
      listIntegerVertices.reserve(verticesOfInterest.size());
      std::vector<std::pair<Vertex*, int>> listHalfIntegerVertices;
      

      // for(size_t k=0; k<verticesOfInterest.size(); k++){
      //   std::sort(verticesOfInterest.begin(), verticesOfInterest.end(), [&](Vertex *v1, Vertex *v2){return distToInt(v1)<distToInt(v2);});
      //   Vertex *v;
      //   for(size_t l=0; l<verticesOfInterest.size(); l++){
      //     v = verticesOfInterest[l];
      //     if(std::find(listIntegerVertices.begin(), listIntegerVertices.end(), v) == listIntegerVertices.end()){
      //       listIntegerVertices.push_back(v);
      //       break;
      //     }
      //   }
      //   std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Size int vertices: " << listIntegerVertices.size() << std::endl;
      //   _solveSeamlessPotentialsWithIntProj(listIntegerVertices, listHalfIntegerVertices);
      // }

      std::vector<std::vector<Vertex*>> listBCVertLift0;
      std::vector<std::vector<Vertex*>> listBCVertLift1;
      _getConstPotBC(listBCVertLift0, listBCVertLift1);

      std::vector<std::pair<Vertex*, int>> halfIntegerVertices;
      for(const auto &v: listBCVertLift0)
        halfIntegerVertices.push_back(std::make_pair(v[0], 0));
      for(const auto &v: listBCVertLift1)
        halfIntegerVertices.push_back(std::make_pair(v[0], 1));
      //Loop on boundaries. Adding 1 by 1 a pair (vert, indexPot) to the int constraint.
      // for(auto &hv: halfIntegerVertices){
      //   listHalfIntegerVertices.push_back(hv);
      //   _solveSeamlessPotentialsWithIntProj(listIntegerVertices, listHalfIntegerVertices);
      // }
      
      std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Adding Singularities int conditions: " << std::endl;
      //Loop on singularities. Adding 1 by 1 a pair (sing, indexPot) to the int constraint.
      for(size_t k=0; k<verticesOfInterestHalfPair.size(); k++){
        std::sort(verticesOfInterestHalfPair.begin(), verticesOfInterestHalfPair.end(), [&](std::pair<Vertex*, int> vF1, std::pair<Vertex*, int> vF2){return distToInt(vF1)<distToInt(vF2);});
        std::pair<Vertex*, int> vF;
        for(size_t l=0; l<verticesOfInterestHalfPair.size(); l++){
          vF = verticesOfInterestHalfPair[l];
          if(std::find(listHalfIntegerVertices.begin(), listHalfIntegerVertices.end(), vF) == listHalfIntegerVertices.end()){
            listHalfIntegerVertices.push_back(vF);
            break;
          }
        }
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Size int vertices: " << listHalfIntegerVertices.size() << std::endl;
        _solveSeamlessPotentialsWithIntProj(listIntegerVertices, listHalfIntegerVertices);
      }

      std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Adding boundary int conditions: " << std::endl;
      for(size_t k=0; k< halfIntegerVertices.size(); k++){
        std::sort(halfIntegerVertices.begin(), halfIntegerVertices.end(), [&](std::pair<Vertex*, int> vF1, std::pair<Vertex*, int> vF2){return distToInt(vF1)<distToInt(vF2);});
        std::pair<Vertex*, int> vF;
        for(size_t l=0; l<halfIntegerVertices.size(); l++){
          vF = halfIntegerVertices[l];
          if(std::find(listHalfIntegerVertices.begin(), listHalfIntegerVertices.end(), vF) == listHalfIntegerVertices.end()){
            listHalfIntegerVertices.push_back(vF);
            break;
          }
        }
        std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ Size int vertices: " << listHalfIntegerVertices.size() << std::endl;
        _solveSeamlessPotentialsWithIntProj(listIntegerVertices, listHalfIntegerVertices);
      }

      // for(Vertex *v: verticesOfInterestBoundary){
      //   listIntegerVertices.push_back(v);
      //   _solveSeamlessPotentialsWithIntProj(listIntegerVertices);
      // }


      // //Only for visu
      // for(Vertex *v: m_m->getVertices()){
      //   double val0 = m_seamLessPot0intSing[v];
      //   double val1 = m_seamLessPot1intSing[v];
      //   if(fabs(std::round(val0)-val0) < 1e-9)
      //     m_seamLessPot0intSing[v] -= 1e-8;
      //   if(fabs(std::round(val1)-val1) < 1e-9)
      //     m_seamLessPot1intSing[v] -= 1e-8;
      // }

      //

      //Only for visu
      for(Vertex *v: m_m->getVertices()){
        if(fabs(m_seamLessPot0intSing[v] - std::round(m_seamLessPot0intSing[v])) < 1e-12)
          m_seamLessPot0intSing[v] += 1e-6;
        if(fabs(m_seamLessPot1intSing[v] - std::round(m_seamLessPot1intSing[v])) < 1e-12)
          m_seamLessPot1intSing[v] += 1e-6;
        // if(v->isVertOfInterest()){
        //   std::cout << "Coords Vert of interest " << v->getGmshTag() << std::endl;
        //   std::cout << m_seamLessPot0intSing[v] << ", " << m_seamLessPot1intSing[v] << std::endl;
        //   m_seamLessPot0intSing[v] += 1e-6;
        //   m_seamLessPot1intSing[v] += 1e-6;
        // }
      }
      

      // m_seamLessPot0intSing.clear();
      // m_seamLessPot1intSing.clear();
      // for(auto &kv: pots){
      //   m_seamLessPot0intSing[kv.first] = kv.second[0];
      //   m_seamLessPot1intSing[kv.first] = kv.second[1];
      // }
      std::map<Element*, std::vector<double>> elemU;
      std::map<Element*, std::vector<double>> elemV;
      for(Element *e: m_m->getElements()){
        elemU[e].clear();
        for(Vertex *v: e->getVertices()){
          elemU[e].push_back(m_seamLessPot0intSing[v]);
          elemV[e].push_back(m_seamLessPot1intSing[v]);
        }
      }
      visu::integerPotentialOnMesh(elemU, "U int sing");
      visu::integerPotentialOnMesh(elemV, "V int sing");
    }
    
    void computeParametrization(){
      _createLifting();
      std::map<Edge *, std::vector<double>> lift0;
      std::map<Edge *, std::vector<double>> lift1;
      for(auto &kv: m_lifting){
        for(size_t k=0; k<3; k++){
          Edge *edg = kv.first->getEdge(k);
          std::vector<double> dir0 = kv.second[k][0];
          std::vector<double> dir1 = kv.second[k][1];
          lift0[edg] = dir0;
          lift1[edg] = dir1;
        }
      }
      visu::vectorField(lift0, "Lifting 0");
      visu::vectorField(lift1, "Lifting 1");
      _solveSeamlessPotentials();
      _solveSeamlessPotentialsWithIntProj();
    }

    void printFrameFieldData(std::string name){
      std::map<Element *, std::vector<std::vector<double>>> mapElemDir = getDirectionsPerElem();
      visu::framefield(mapElemDir, name);
      _locateSingularities();
      _locateSingularitiesVertices();
      visu::scalarField(m_singularities, "Sings " + name);
      visu::scalarField(m_singularitiesVertices, "SingsVert "+ name);
      std::map<Element*, double> mapElemOdecoPenaltyDensity = getOdecoPenaltyDensity();
      visu::scalarField(mapElemOdecoPenaltyDensity, "Odeco Penalty density " + name);
      std::map<Element*, double> mapElemNormalizedOdecoPenaltyDensity = getNormalizedOdecoPenaltyDensity();
      visu::scalarField(mapElemNormalizedOdecoPenaltyDensity, "Normalized Odeco Penalty density " + name);
      std::map<Element*, double> mapElemNormalizedOdecoPenaltyWithLogSmoothWeight = getNormalizedOdecoPenaltyWithLogSmoothWeight();
      visu::scalarField(mapElemNormalizedOdecoPenaltyWithLogSmoothWeight, "Normalized Odeco Penalty with log smooth weight " + name);
      std::map<Element*, double> mapElemErrorInt = getIntegrabilityError();
      visu::scalarField(mapElemErrorInt, "Integrability error " + name);
      std::map<Element*, double> mapElemErrorIntDensity = getIntegrabilityErrorDensity();
      visu::scalarField(mapElemErrorIntDensity, "Integrability error density " + name);
      std::map<Element*, double> mapElemSmoothness = getSmoothness();
      visu::scalarField(mapElemSmoothness, "Smoothness " + name);
      std::map<Element*, double> mapElemSmoothnessDensity = getSmoothnessDensity();
      visu::scalarField(mapElemSmoothnessDensity, "Smoothness density " + name);
  
      return;
    }

    std::map<Element*, double> m_singularities;
    std::map<Vertex*, double> m_singularitiesVertices;

    void setInitFrameField(const std::map<Edge*, T> &initFrameField){m_mapEdgeFrames = initFrameField;}
    std::map<Edge*, T> getFrameField(){return m_mapEdgeFrames;}

    void setFixedEdges(const std::vector<Edge*> &listEdges){
      for(Edge *e: m_m->getEdges())
        m_fixedEdges[e] = false;
      for(Edge *e: listEdges)
        m_fixedEdges[e] = true;
    }
    void addFixedEdges(const std::vector<Edge*> &listEdges){
      for(Edge *e: listEdges)
        m_fixedEdges[e] = true;
    }
    std::map<Edge*,bool> m_fixedEdges;

    void setFact(double fact){m_fact = fact;}

    std::string m_typeBC;

    Mesh* getMesh(){return m_m;}

    std::map<Edge*, T> m_mapEdgeFrames;

    std::map<Vertex*, double> m_seamLessPot0;
    std::map<Vertex*, double> m_seamLessPot1;
    
  private:
    Mesh *m_m;


    double m_fact;
    ObjectiveFunction *m_dirichletEnergy;
    ObjectiveFunction *m_frameConstraint;
    ObjectiveFunction *m_frameConstraintSmooth;
    ObjectiveFunction *m_integrabilityEnergy;
    
    std::vector<Edge*> m_edgesWithConstraint;

    std::vector<std::pair<std::vector<Element*>, double>> m_lineGroupsSmoothConstraint;
    std::vector<std::pair<std::vector<Element*>, std::vector<double>>> m_lineGroupsHardConstraint;

    std::map<Element*, std::vector<std::vector<std::vector<double>>>> m_lifting;

    std::map<Vertex*, double> m_seamLessPot0intSing;
    std::map<Vertex*, double> m_seamLessPot1intSing;
  };
}
