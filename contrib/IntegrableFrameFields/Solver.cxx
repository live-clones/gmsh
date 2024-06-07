// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#include <Solver.hxx>
#include <IffTools.hxx>
#include <gmsh.h>

//Alglib includes
#include <stdafx.h>
#include <optimization.h>
//

namespace IFF{
  Solver::Solver(Mesh *m, int nFields, ObjectiveFunction *objFunc, TYPEUNKNOWN unknownType){
    m_mesh = m;
    m_elements = m->getElements();
    m_vertices = m->getVertices();
    m_edges = m->getEdges();
    m_unknownType = unknownType;
    if(unknownType == TYPEUNKNOWN::VERTEX || unknownType == TYPEUNKNOWN::ELEMENT){
      std::cout << "Unknown type not implemented" << std::endl;
      exit(0);
    }
    m_nFields = nFields;
    m_objFunc = objFunc;
    switch(unknownType){
    case TYPEUNKNOWN::EDGE:
      m_nDof = m_edges.size()*nFields;
      for(Element* e: m_elements)
        e->setNumUnknown(e->getNumEdges());
      //DBG: Check numbering of unkown
      for(size_t k=0; k<m_edges.size(); k++)
        if(m_edges[k]->getIndex() != k){
          std::cout << "problem in edge index generation." << std::endl;
          exit(0);
        }
      break;
    default:
      std::cout << "Unknown type not implemented" << std::endl;
      exit(0);      
    }
    m_alglibrep = 0;
    m_func_prec = 0.0;
    m_maxItLbfgs = 15000;
    m_lbfgsGradPrec = 1e-10;
    m_lbfgsFuncPrec = 0.0;
    m_lbfgsXPrec = 0.0;
  }

  void Solver::addBCDirichlet(const std::pair<Edge*, int> &pairEdgeField, double valBC){
    std::vector<std::vector<double>> mat;
    mat.resize(1); mat[0].resize(1); mat[0][0] = 1.0;
    std::vector<double> vect;
    vect.resize(1); vect[0] = valBC;
    std::vector<std::pair<Edge*, int>> pairVF;
    pairVF.resize(1, pairEdgeField);
    addBCLinearCombination(mat, vect, pairVF);
  }
  
  void Solver::addBCDirichlet(const std::vector<std::pair<Edge*, int>> &pairEdgeField, const std::vector<double> &valBC){
    for(size_t k=0; k<pairEdgeField.size(); k++)
      addBCDirichlet(pairEdgeField[k], valBC[k]);
  }

  void Solver::addBCLinearCombination(const std::vector<std::vector<double>> &mat, const std::vector<double> &vect, const std::vector<std::pair<Edge*, int>> &pairEdgeField){
    bool validConstraint = true;
    //Add a check if edge is in solver mesh    
    if(validConstraint){
      LinearBC bc;
      m_linearBC.push_back(bc);
      m_linearBC[m_linearBC.size()-1].mat = mat;
      m_linearBC[m_linearBC.size()-1].vect = vect;
      std::vector<size_t> dofIndices;
      dofIndices.reserve(vect.size());
      for(auto &vf: pairEdgeField)
	dofIndices.push_back(_getIndex(vf));
      m_linearBC[m_linearBC.size()-1].dofIndices = dofIndices;
  
      m_nLagMult += vect.size();
    }
    else{
      gmsh::logger::write("IFF::SOLVER: Imposed linear constraint involves a vertex not present in the element set. Constraint ignored", "warning");
    }
  }
  
  void _lbfgs_callback(const alglib::real_1d_array &x, double &func, alglib::real_1d_array &grad, void *ptr){ // Callback for lbfgs, compute objective function value and it's gradient
    Solver *solver = (Solver*) ptr;

    func = 0.0;
#pragma omp parallel for reduction(+:func)
    for(size_t k=0; k<solver->m_elements.size(); k++){
      Element *el = solver->m_elements[k];
      std::vector<std::vector<double>> solEl;
      solEl.resize(el->getNumUnknown());
      for(size_t l=0; l<solEl.size(); l++)
	solEl[l].resize(solver->m_nFields, 0.0);

      for(size_t l=0; l<solEl.size(); l++)
	for(size_t m=0; m<solver->m_nFields; m++){
	  solEl[l][m] = x[solver->_getIndex(el, l, m)];
	}

      double funcElem = 0.0;
      solver->m_objFunc->evaluateFunction(solver->m_elements[k], solEl, funcElem);
      func += funcElem;
    }
    
    //Now computing gradient
    for(size_t k=0; k<solver->getNDof(); k++)
      grad[k] = 0.0;
    std::vector<std::vector<double>> localRhs;
    localRhs.resize(solver->m_elements.size());
  
#pragma omp parallel for
    for(size_t k=0; k<solver->m_elements.size(); k++){
      Element *el = solver->m_elements[k];
      std::vector<std::vector<double>> solEl;
      solEl.resize(el->getNumUnknown());
      for(size_t l=0; l<solEl.size(); l++)
	solEl[l].resize(solver->m_nFields, 0.0);

      for(size_t l=0; l<solEl.size(); l++)
	for(size_t m=0; m<solver->m_nFields; m++){
          solEl[l][m] = x[solver->_getIndex(el, l, m)];
	}
      solver->m_objFunc->getGradient(solver->m_elements[k], solEl, localRhs[k]);
    }
  
    //Assemble gradient
    double *pDataGrad = grad.getcontent();
#pragma omp parallel for reduction(+:pDataGrad[:solver->getNDof()])
    for(size_t k=0; k<solver->m_elements.size(); k++){
      for(size_t l=0; l<solver->m_elements[k]->getNumUnknown(); l++){
	for(size_t m=0; m<solver->m_nFields; m++){
	  size_t dofIndex = solver->_getIndex(solver->m_elements[k], l, m);
	  size_t localIndex = solver->m_nFields*l + m;
	  pDataGrad[dofIndex] += localRhs[k][localIndex];
	}
      }
    }
  
    // Project gradient on linear admissible set
    #pragma omp parallel for reduction(-:pDataGrad[:solver->getNDof()])
    for(size_t k=0; k<solver->m_linearBC.size(); k++){
      size_t nLocalLagMult = solver->m_linearBC[k].mat.size();
      for(size_t i=0; i<nLocalLagMult; i++){
	size_t nLocalDof = solver->m_linearBC[k].dofIndices.size();
	std::vector<double> normalSet(solver->m_linearBC[k].mat[i]);
	tools::normalize(normalSet);
	double dotprod = 0.0;
	for(size_t j=0; j<nLocalDof; j++)
	  dotprod += normalSet[j]*grad[solver->m_linearBC[k].dofIndices[j]];
	for(size_t j=0; j<nLocalDof; j++)
	  pDataGrad[solver->m_linearBC[k].dofIndices[j]] -= dotprod*normalSet[j];
      }
    }

  }
  
  void _lbfgs_rep_callback(const alglib::real_1d_array &x, double func, void *ptr){ // Callback for lbfgs report
    Solver *solver = (Solver*) ptr;
    double deltaF = (func - solver->m_func_prec) / func;
    if(solver->m_alglibrep == 0){
      std::cout << "f init = " << func << std::endl;
    }
    if(solver->m_alglibrep%1 == 0){
      //       std::cout << "It: " << solver->m_alglibrep << ", f = " << solver->m_funcs << ", df = " << deltaF << "\t\r" << std::flush;
      std::cout << "It: " << solver->m_alglibrep << ", f = " << func << ", df = " << deltaF << std::endl;
    }
    solver->m_alglibrep++;
    solver->m_func_prec = func;
  }
  
  void Solver::solveLBFGS(std::map<Edge*, std::vector<double>> &mapSolution){
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNDof(), 0.0);
    for(auto &kv: mapSolution){
      for(size_t k=0; k<kv.second.size(); k++)
	solution[_getIndex(std::make_pair(kv.first, k))] = kv.second[k];
    }
    alglib::ae_int_t dim = getNDof();
    alglib::ae_int_t corr = 3; // Num of corrections in the scheme in [3,7]. Set to 2 in GFace.cpp
    alglib::minlbfgsstate state;
    alglib::real_1d_array x;
    x.setcontent(dim, solution.data());

    minlbfgscreate(dim, corr, x, state);
    minlbfgssetxrep(state, true);
    
    // Set stopping criteria
    // const double epsg = 1.e-10 * getNDof();
    const double epsg = m_lbfgsGradPrec;
    const double epsf = m_lbfgsFuncPrec;
    const double epsx = m_lbfgsXPrec;
    const alglib::ae_int_t maxits = m_maxItLbfgs;
    // const alglib::ae_int_t maxits = 10;
    // const alglib::ae_int_t maxits = 1;
    std::cout << "epsg: " << epsg << std::endl;
    std::cout << "epsf: " << epsf << std::endl;
    minlbfgssetcond(state, epsg, epsf, epsx, maxits);

    // Modify linear BC to make it work with LBFGS
    // _modifyLinearBCForLBFGS(); // this function has to be optimized before being used
    // Solve problem
    // minlbfgsoptimize(state, _lbfgs_callback, nullptr, (void*)this);

    // testGrad(mapSolution);
    minlbfgsoptimize(state, _lbfgs_callback, _lbfgs_rep_callback, (void*)this);
    std::cout << std::endl;
  
    // Retreive solution
    alglib::minlbfgsreport rep;
    minlbfgsresults(state, x, rep);

    //export solution
    for(auto &pel: m_elements)
      for(auto &pv: pel->getEdges()){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = x[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
  }


}
