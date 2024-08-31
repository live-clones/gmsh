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

namespace IFF{
  double TARGETMESHSIZE(const std::vector<double> &coords){return 0.001;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.0001;};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.05*(coords[1] + 1.0);};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return 0.05*(2.0*coords[1] + 1.0);};
  // double TARGETMESHSIZE(const std::vector<double> &coords){return coords[0]+0.07;};
  
  template <class T>
  class FrameField{
    static_assert(std::is_base_of<Frame, T>::value, "FrameField<T>: T must derive from Frame");
    
  public:
    FrameField(Mesh *m, double factor, std::string typeBC = "hardBC"): m_m(m), m_fact(factor), m_typeBC(typeBC){
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
      // std::vector<double> schedule{0.1, 0.3, 0.5, 0.8, 1.0};
      std::vector<double> schedule{0.9, 0.95, 0.97, 0.99, 1.0};
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
        generateIntegrableFrameFieldFixedSize(10, true);
        // _generateIntegrableFrameFieldImposedDIrections(100, true);
        // generateIntegrableFrameField(10000, false);
        if(k%1 == 0){
          std::map<Element *, std::vector<std::vector<double>>> mapElemDir = getDirectionsPerElem();
          visu::framefield(mapElemDir, "Integrable frames Glob intermediate");
        }
      }
    }

    void generateIntegrableFrameFieldFixedSize(size_t maxItLbfgs = 100000, bool mute=false){
      double h = m_m->getMaxEdgeLength();
      // double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      double penaltyConstraint = m_fact*0.01;//Version log(1+grad^2/N)
      ObjectiveFunction *GLobj;
      // GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));
      GLobj = m_integrabilityEnergy;

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
      double penaltyConstraint = 1.0/(4*h*h)*m_fact;
      ObjectiveFunction *GLobj;
      // GLobj = *m_integrabilityEnergy + *(penaltyConstraint*(*m_frameConstraint));
      GLobj = m_integrabilityEnergy;
      
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
      //     // for(auto &v: solEl)
      //     //   std::cout << v.size()<< std::endl;
      //     std::cout << "------" << std::endl;
      //     GLobj->checkGradient(e, solEl);
      //   }
      //   break;
      // }

      //Create solver and BC
      Solver s(m_m, T::nUnknown, GLobj, Solver::TYPEUNKNOWN::EDGE, maxItLbfgs);
      std::map<Edge*, std::vector<double>> sol; //Initial solution
      _createInitialFrameField(sol);
      // for(const auto &kv: m_fixedEdges)
      //   if(kv.second || kv.first->getLines().size() != 0)
      //     _fixFrameOnEdge(&s, kv.first, sol);
      //   // if(kv.second || kv.first->getLines().size() != 0){
      //   //   if(kv.first->getBarycenter()[0] <= -0.5 + 1e-10 && kv.first->getBarycenter()[1] <= -0.5 + 1e-10 && kv.first->getBarycenter()[2] >= 0.9)
      //   //     _fixFrameOnEdge(&s, kv.first, sol);//DBG notch
      //   //   else
      //   //     _alignFrameOnEdge(&s, kv.first, sol);
      //   // }
      //   else
      //     _alignFrameOnEdge(&s, kv.first, sol);

      for(const auto &kv: m_fixedEdges)
        _alignFrameOnEdge(&s, kv.first, sol);

      _imposeBC(&s, sol);

      // _imposeContinuity(&s);
      
      if(!mute)
        std::cout << "+++ --- +++ Generate integrable framefield with fixed orientation" << std::endl;
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
    std::map<Edge*,bool> m_fixedEdges;

    void setFact(double fact){m_fact = fact;}

    std::string m_typeBC;
    
  private:
    Mesh *m_m;
    std::map<Edge*, T> m_mapEdgeFrames;

    double m_fact;
    ObjectiveFunction *m_dirichletEnergy;
    ObjectiveFunction *m_frameConstraint;
    ObjectiveFunction *m_frameConstraintSmooth;
    ObjectiveFunction *m_integrabilityEnergy;


    
    std::vector<Edge*> m_edgesWithConstraint;

    std::vector<std::pair<std::vector<Element*>, double>> m_lineGroupsSmoothConstraint;
    std::vector<std::pair<std::vector<Element*>, std::vector<double>>> m_lineGroupsHardConstraint;
  };
}
