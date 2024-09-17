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

#include <Eigen/Dense>
#include <Eigen/SparseLU>
#include <omp.h>

namespace IFF{
  Solver::Solver(Mesh *m, int nFields, ObjectiveFunction *objFunc, TYPEUNKNOWN unknownType, size_t maxItLbfgs, double deltaFMax){
    m_mesh = m;
    m_elements = m->getElements();
    m_vertices = m->getVertices();
    m_edges = m->getEdges();
    m_unknownType = unknownType;
    m_lagMultDataToBeGenerated = true;
    m_nLagMult = 0;
    m_linearBCorthonormalized = false;   
    if(unknownType == TYPEUNKNOWN::ELEMENT){
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
    case TYPEUNKNOWN::VERTEX:
      m_nDof = m_vertices.size()*nFields;
      for(Element* e: m_elements)
        e->setNumUnknown(e->getNumVertices());
      //DBG: Check numbering of unkown
      for(size_t k=0; k<m_vertices.size(); k++)
        if(m_vertices[k]->getIndex() != k){
          std::cout << "problem in vertices index generation." << std::endl;
          exit(0);
        }
      break;
    default:
      std::cout << "Unknown type not implemented" << std::endl;
      exit(0);      
    }
    m_alglibrep = 0;
    m_func_prec = 0.0;
    m_maxItLbfgs = maxItLbfgs;
    m_lbfgsGradPrec = 1e-10;
    // m_lbfgsGradPrec = 1e-8;
    // m_lbfgsFuncPrec = 0.0;
    // m_lbfgsFuncPrec = 1e-8;
    m_lbfgsFuncPrec = deltaFMax;
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
    m_lagMultDataToBeGenerated = true;//Useless as it's done in addBCLinearCombination but it's not to forget if we change the function
  }

  void Solver::addBCDirichlet(const std::pair<Vertex*, int> &pairVertexField, double valBC){
    std::vector<std::vector<double>> mat;
    mat.resize(1); mat[0].resize(1); mat[0][0] = 1.0;
    std::vector<double> vect;
    vect.resize(1); vect[0] = valBC;
    std::vector<std::pair<Vertex*, int>> pairVF;
    pairVF.resize(1, pairVertexField);
    addBCLinearCombination(mat, vect, pairVF);
    m_lagMultDataToBeGenerated = true;//Useless as it's done in addBCLinearCombination but it's not to forget if we change the function
  }
  
  void Solver::addBCDirichlet(const std::vector<std::pair<Edge*, int>> &pairEdgeField, const std::vector<double> &valBC){
    for(size_t k=0; k<pairEdgeField.size(); k++){
      addBCDirichlet(pairEdgeField[k], valBC[k]);
      m_lagMultDataToBeGenerated = true;//Useless as it's done in addBCLinearCombination but it's not to forget if we change the function
    }
  }

  void Solver::addBCDirichlet(const std::vector<std::pair<Vertex*, int>> &pairVertexField, const std::vector<double> &valBC){
    for(size_t k=0; k<pairVertexField.size(); k++){
      addBCDirichlet(pairVertexField[k], valBC[k]);
      m_lagMultDataToBeGenerated = true;//Useless as it's done in addBCLinearCombination but it's not to forget if we change the function
    }
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
      dofIndices.reserve(mat[0].size());
      for(auto &vf: pairEdgeField)
	dofIndices.push_back(_getIndex(vf));
      m_linearBC[m_linearBC.size()-1].dofIndices = dofIndices;
      m_lagMultDataToBeGenerated = true;
    }
    else{
      gmsh::logger::write("IFF::SOLVER: Imposed linear constraint involves a vertex not present in the element set. Constraint ignored", "warning");
    }
  }

  void Solver::addBCLinearCombination(const std::vector<std::vector<double>> &mat, const std::vector<double> &vect, const std::vector<std::pair<Vertex*, int>> &pairVertexField){
    bool validConstraint = true;
    //Add a check if edge is in solver mesh    
    if(validConstraint){
      LinearBC bc;
      m_linearBC.push_back(bc);
      m_linearBC[m_linearBC.size()-1].mat = mat;
      m_linearBC[m_linearBC.size()-1].vect = vect;
      std::vector<size_t> dofIndices;
      dofIndices.reserve(mat[0].size());
      for(auto &vf: pairVertexField)
	dofIndices.push_back(_getIndex(vf));
      m_linearBC[m_linearBC.size()-1].dofIndices = dofIndices;
      m_lagMultDataToBeGenerated = true;
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
    if(solver->m_alglibrep%100 == 0){
      //       std::cout << "It: " << solver->m_alglibrep << ", f = " << solver->m_funcs << ", df = " << deltaF << "\t\r" << std::flush;
      std::cout << "It: " << solver->m_alglibrep << ", f = " << func << ", df = " << deltaF << std::endl;
      // std::cout << "It: " << solver->m_alglibrep << ", f = " << func << ", df = " << deltaF << std::flush;
    }
    solver->m_alglibrep++;
    solver->m_func_prec = func;
  }

  void Solver::_orthonormalizeConstraints(){
    if(!m_linearBCorthonormalized){
      std::cout << "Orthonormalize constraints" << std::endl;
      if(m_linearBC.size() == 0)
        return;
      //Gram-Schmidt orthonormalization
      // if(m_linearBC[0].vect.size() > 0){
      //   double norm = tools::norm(m_linearBC[0].mat[0]);
      //   if(norm > 1e-12){
      //     tools::scale(m_linearBC[0].mat[0], 1.0/norm);
      //     tools::scale(m_linearBC[0].vect, 1.0/norm);
      //   }
      // }
      for(size_t l=0; l<m_linearBC[0].vect.size(); l++){
        for(size_t m=0; m<l; m++){
          double ps = tools::dotprod(m_linearBC[0].mat[m], m_linearBC[0].mat[l]);
          for(size_t k=0; k<m_linearBC[0].mat[l].size(); k++){
            m_linearBC[0].mat[l][k] -= ps*m_linearBC[0].mat[m][k];
          }
          m_linearBC[0].vect[l] -= ps*m_linearBC[0].vect[m];
        }
        // normalize
        double norm = tools::norm(m_linearBC[0].mat[l]);
        if(norm <= 1e-10){
          int nothing;
          // std::cout <<"Norm constr: " << norm << std::endl;
          // std::cout << "null norm" << std::endl;
          // exit(0);
        }
        else{
          // std::cout <<"Norm constr: " << norm << std::endl;
          for(size_t k=0; k<m_linearBC[0].mat[l].size(); k++){
            m_linearBC[0].mat[l][k] /= norm;
          }
          m_linearBC[0].vect[l] /= norm;
        }
      }

      for(size_t k=1; k<m_linearBC.size(); k++){
        std::vector<bool> dofTouched(m_nDof, false);
        for(size_t dofIndex: m_linearBC[k].dofIndices)
          dofTouched[dofIndex] = true;
        std::vector<size_t> listTouchingConstraints;
        for(size_t kPrec = 0; kPrec<k; kPrec++){
          bool constraintTouching = false;
          for(size_t dofIndex: m_linearBC[kPrec].dofIndices)
            if(dofTouched[dofIndex]){
              listTouchingConstraints.push_back(kPrec);
              constraintTouching = true;
              break;
            }
          if(constraintTouching){
            for(size_t dofIndex: m_linearBC[kPrec].dofIndices){
              dofTouched[dofIndex] = true;
            }
          }
        }
        // if(k==23){
        //   std::cout << "-----------> n constraints touched: " << listTouchingConstraints.size() << std::endl;

        // }
        std::vector<size_t> touchedIndices;
        for(size_t iDof=0; iDof<m_nDof; iDof++)
          if(dofTouched[iDof])
            touchedIndices.push_back(iDof);

        LinearBC newBC;
        newBC.mat.resize(m_linearBC[k].vect.size());
        for(auto &v: newBC.mat)
          v.resize(touchedIndices.size(), 0.0);
        newBC.vect = m_linearBC[k].vect;
        newBC.dofIndices = touchedIndices;
        {
          std::vector<double> extendedConstr(m_nDof, 0.0);
          for(size_t l=0; l<m_linearBC[k].vect.size(); l++){
            for(size_t iLoc=0; iLoc<m_linearBC[k].dofIndices.size(); iLoc++){
              size_t indDof = m_linearBC[k].dofIndices[iLoc];
              extendedConstr[indDof] += m_linearBC[k].mat[l][iLoc];
            }
            for(size_t iLoc=0; iLoc<newBC.dofIndices.size(); iLoc++){
              size_t indDof = newBC.dofIndices[iLoc];
              newBC.mat[l][iLoc] = extendedConstr[indDof];
            }
          }
        }
        // for(size_t l=0; l<m_linearBC[k].vect.size(); l++){
        //   std::cout << "oldBC line l: " << m_linearBC[k].mat[l] << std::endl;
        // }
        // std::cout << "old bc vect: " << m_linearBC[k].vect << std::endl;
        // std::cout << "old indices: " << m_linearBC[k].dofIndices << std::endl;
        // for(size_t l=0; l<m_linearBC[k].vect.size(); l++){
        //   std::cout << "newBC line l: " << newBC.mat[l] << std::endl;
        // }
        // std::cout << "new bc vect: " << newBC.vect << std::endl;
        // std::cout << "new indices: " << newBC.dofIndices << std::endl;
        for(size_t l=0; l<m_linearBC[k].vect.size(); l++){
          std::vector<double> extendedConstr(m_nDof, 0.0);
          // for(size_t iLoc=0; iLoc<m_linearBC[k].dofIndices.size(); iLoc++){
            // size_t indDof = m_linearBC[k].dofIndices[iLoc];
            // extendedConstr[indDof] = m_linearBC[k].mat[l][iLoc];
          for(size_t iLoc=0; iLoc<newBC.dofIndices.size(); iLoc++){
            size_t indDof = newBC.dofIndices[iLoc];
            extendedConstr[indDof] = newBC.mat[l][iLoc];
          }
          for(size_t iLoc=0; iLoc<newBC.dofIndices.size(); iLoc++){
            size_t indDof = newBC.dofIndices[iLoc];
            newBC.mat[l][iLoc] = extendedConstr[indDof];
          }
          // std::cout << "newBC line l refilled: " << newBC.mat[l] << std::endl;
          // if(k==23){
          //   std::cout << "newBC.mat: " << newBC.mat << std::endl;
          // }
          // std::cout << "list touching constraints: " << listTouchingConstraints << std::endl;
          for(size_t indPrecConstr: listTouchingConstraints){
            for(size_t indLocConstrPrec=0; indLocConstrPrec<m_linearBC[indPrecConstr].vect.size(); indLocConstrPrec++){
              std::vector<double> extendedCurrentConstr(m_nDof, 0.0);
              std::vector<double> extendedLocalConstr(m_nDof, 0.0);
              std::vector<double> halfDotProd(m_nDof, 0.0);
              for(size_t indDof=0; indDof<newBC.mat[l].size(); indDof++)
                extendedCurrentConstr[newBC.dofIndices[indDof]] = newBC.mat[l][indDof];
              for(size_t indDof=0; indDof<m_linearBC[indPrecConstr].mat[indLocConstrPrec].size(); indDof++)
                extendedLocalConstr[m_linearBC[indPrecConstr].dofIndices[indDof]] = m_linearBC[indPrecConstr].mat[indLocConstrPrec][indDof];
            
              double ps = 0.0;
              // for(size_t indDof=0; indDof<m_nDof; indDof++)
              for(size_t indDof: touchedIndices)
                ps += extendedLocalConstr[indDof]*extendedCurrentConstr[indDof];
              for(size_t indDof: touchedIndices)
                extendedCurrentConstr[indDof] -= ps*extendedLocalConstr[indDof];
            
              for(size_t indDof=0; indDof<newBC.mat[l].size(); indDof++){
                newBC.mat[l][indDof] = extendedCurrentConstr[newBC.dofIndices[indDof]];
              }
              // for(size_t indDof=0; indDof<newBC.mat[l].size(); indDof++){
              //   newBC.mat[l][indDof] -= ps*m_linearBC[indPrecConstr].mat[indLocConstrPrec][indDof];
              // }
              newBC.vect[l] -= ps*m_linearBC[indPrecConstr].vect[indLocConstrPrec];
            }
          }
          //Gram-Schmidt on the current set of constraints
          for(size_t m=0; m<l; m++){
            double ps = tools::dotprod(newBC.mat[m], newBC.mat[l]);
            for(size_t kLoc=0; kLoc<newBC.mat[l].size(); kLoc++){
              newBC.mat[l][kLoc] -= ps*newBC.mat[m][kLoc];
            }
            newBC.vect[l] -= ps*newBC.vect[m];
          }
          // normalize
          double norm = tools::norm(newBC.mat[l]);
          // if(norm < 1e-12){
          //   std::cout << "null norm 2" << std::endl;
          //   exit(0);
          // }
          if(norm > 1e-10){
            // std::cout <<"Norm constr: " << norm << std::endl;
            for(size_t kLoc=0; kLoc<newBC.mat[l].size(); kLoc++){
              newBC.mat[l][kLoc] /= norm;
            }
            newBC.vect[l] /= norm;
            // std::cout << "vect val: " << newBC.vect[l] << std::endl;
            // std::cout <<"previous vect val: " << m_linearBC[k].vect[l] << std::endl;
          }
          else{
            int nothing;
            // std::cout <<"Norm constr: " << norm << std::endl;
            // std::cout << "NULL CONSTR" << std::endl;
            // exit(0);
          }
          // if(k==23){
          //   std::cout << std::endl;
          //   std::cout << "newBC.mat end:" << newBC.mat << std::endl;
          // }
        }
        m_linearBC[k] = newBC;
      }
      std::cout << "END Orthonormalize constraints" << std::endl;
      m_linearBCorthonormalized = true;
      m_lagMultDataToBeGenerated = true;
    }
  }

  void Solver::_removeUselessConstraints(){
    std::cout << "n linear BC: " << m_linearBC.size() << std::endl;
    std::vector<LinearBC> newVectLinearBC;
    newVectLinearBC.reserve(m_linearBC.size());
    for(auto &bc: m_linearBC){
      std::vector<std::vector<double>> mat;
      mat.reserve(bc.mat.size());
      std::vector<double> vect;
      vect.reserve(bc.vect.size());
      for(size_t l=0; l<bc.mat.size(); l++){
        std::vector<double> v = bc.mat[l];
        if(tools::norm(v) > 1e-10){
          mat.push_back(v);
          vect.push_back(bc.vect[l]);
        }
        else{
          if(bc.vect[l] > 1e-10){
            std::cout << "WARNING. Problem overconstrained, removing a linear condition. Val vect: " << bc.vect[l] << std::endl;
            std::cout << "val norm: " << tools::norm(v) << ", val vect: " << bc.vect[l] << std::endl;
          }
          else{
            int nothing;
            // std::cout << "Removing null constraint" << std::endl;
          }
        }
      }
      if(mat.size() > 0){
        LinearBC newBC;
        newBC.mat = mat;
        newBC.vect = vect;
        newBC.dofIndices = bc.dofIndices;
        newVectLinearBC.push_back(newBC);
      }
    }
    m_linearBC = newVectLinearBC;
    std::cout << "n linear BC pruned: " << m_linearBC.size() << std::endl;
    m_lagMultDataToBeGenerated = true;
  }

  void Solver::_checkNormalization(){
    std::cout << "Check orthogonality constraints" << std::endl;
    for(size_t k=0; k<m_linearBC.size(); k++){
      for(size_t indLocConstr=0; indLocConstr<m_linearBC[k].vect.size(); indLocConstr++){
        for(size_t indPrecConstr=0; indPrecConstr<k; indPrecConstr++){
          for(size_t indLocConstrPrec=0; indLocConstrPrec<m_linearBC[indPrecConstr].vect.size(); indLocConstrPrec++){
            std::vector<double> extendedCurrentConstr(m_nDof, 0.0);
            std::vector<double> extendedLocalConstr(m_nDof, 0.0);
            for(size_t indDof=0; indDof<m_linearBC[k].mat[indLocConstr].size(); indDof++)
              extendedCurrentConstr[m_linearBC[k].dofIndices[indDof]] = m_linearBC[k].mat[indLocConstr][indDof];
            for(size_t indDof=0; indDof<m_linearBC[indPrecConstr].mat[indLocConstrPrec].size(); indDof++)
              extendedLocalConstr[m_linearBC[indPrecConstr].dofIndices[indDof]] = m_linearBC[indPrecConstr].mat[indLocConstrPrec][indDof];
            double ps = tools::dotprod(extendedLocalConstr, extendedCurrentConstr);
            // if(k==23 && indLocConstr==0 && indLocConstrPrec==0 && indPrecConstr==4)
            //   std::cout << "ps check: " << ps << std::endl;
            // if(k==23 && indLocConstr==0 && indLocConstrPrec==0 && indPrecConstr==1)
            //   std::cout << "ps check: " << ps << std::endl;
            // if(k==23 && indLocConstr==0 && indLocConstrPrec==0 && indPrecConstr==0)
            //   std::cout << "ps check: " << ps << std::endl;
            if(fabs(ps) > 1e-12){
              std::cout << "Constraint " << k << "," << indLocConstr << "/" << m_linearBC[k].mat.size() << " and " << indPrecConstr << "," << indLocConstrPrec << "/" << m_linearBC[indPrecConstr].mat.size() << " not orthogonal" << std::endl;
              std::cout << "ps: " << ps << std::endl;
              std::cout << "n constraints: " << m_linearBC.size() << std::endl;
              std::cout << m_linearBC[k].mat[indLocConstr] << std::endl;
              std::cout << m_linearBC[indPrecConstr].mat[indLocConstrPrec] << std::endl;
              exit(0);
            }
          }
        }
      }
    }
    std::cout << "END Check orthogonality constraints" << std::endl;
  }
  
  void Solver::solveLBFGS(std::map<Edge*, std::vector<double>> &mapSolution){
    // _orthonormalizeConstraints();
    // _checkNormalization();
    // _removeUselessConstraints();
    // _checkNormalization();
    std::cout << "n dof: " << m_nDof << std::endl;
    size_t nConstr = 0;
    for(auto &bc: m_linearBC)
      nConstr += bc.vect.size();
    std::cout << "n constraints: " << nConstr << std::endl;
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNDof(), 0.0);
    for(auto &kv: mapSolution){
      for(size_t k=0; k<kv.second.size(); k++)
	solution[_getIndex(std::make_pair(kv.first, k))] = kv.second[k];
    }
    alglib::ae_int_t dim = getNDof();
    alglib::ae_int_t corr = 5; // Num of corrections in the scheme in [3,7]. Set to 2 in GFace.cpp
    // alglib::ae_int_t corr = 20; // Num of corrections in the scheme in [3,7]. Set to 2 in GFace.cpp
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

  void Solver::solve(std::map<Vertex *, std::vector<double>> &mapSolution) {
    _orthonormalizeConstraints();
    _checkNormalization();
    _removeUselessConstraints();
    _checkNormalization();
    _generateLagMultData();
    std::vector<std::vector<std::vector<double>>> localMat;
    std::vector<std::vector<double>> localRhs;
    localMat.resize(m_elements.size());
    localRhs.resize(m_elements.size());
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNTotalDof(), 0.0);

    if(m_objFunc->m_useElementData){
      for (size_t k = 0; k < m_elements.size(); k++) {
        Element *el = m_elements[k];
        std::vector<std::vector<double>> elemData = m_elementData[el];
        m_objFunc->getFEMOperators(el, elemData, localMat[k], localRhs[k]);
      }
    }
    else
      for (size_t k = 0; k < m_elements.size(); k++) m_objFunc->getFEMOperators(m_elements[k], localMat[k], localRhs[k]);
    
    _solveLinearSys(localMat, localRhs, solution);
    for (auto &pel : m_elements)
      for (auto &pv : pel->getVertices()) {
        std::vector<double> solVert(m_nFields, 0.0);
        for (int k = 0; k < m_nFields; k++) {
          solVert[k] = solution[_getIndex(std::make_pair(pv, k))];
        }
        mapSolution[pv] = solVert;
      }
  }
  
  void Solver::solveLBFGS(std::map<Vertex*, std::vector<double>> &mapSolution){
    // _orthonormalizeConstraints();
    // _checkNormalization();
    // _removeUselessConstraints();
    // _checkNormalization();
    std::cout << "n dof: " << m_nDof << std::endl;
    size_t nConstr = 0;
    for(auto &bc: m_linearBC)
      nConstr += bc.vect.size();
    std::cout << "n constraints: " << nConstr << std::endl;
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNDof(), 0.0);
    for(auto &kv: mapSolution){
      for(size_t k=0; k<kv.second.size(); k++)
	solution[_getIndex(std::make_pair(kv.first, k))] = kv.second[k];
    }
    alglib::ae_int_t dim = getNDof();
    alglib::ae_int_t corr = 5; // Num of corrections in the scheme in [3,7]. Set to 2 in GFace.cpp
    // alglib::ae_int_t corr = 20; // Num of corrections in the scheme in [3,7]. Set to 2 in GFace.cpp
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
      for(auto &pv: pel->getVertices()){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = x[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
  }

  void Solver::_generateLagMultData(){
    if(m_lagMultDataToBeGenerated){
      m_nLagMult = 0;
      for(const auto &bc: m_linearBC){
        m_nLagMult += bc.vect.size();
      }
      m_lagMultDataToBeGenerated = false;
    }
  }

  void Solver::_solveLinearSys(std::vector<std::vector<std::vector<double>>> &localMat, std::vector<std::vector<double>> &localRhs, std::vector<double> &solution){
    m_mesh->printInfos();
    using namespace Eigen;
    size_t nTotalDof = getNTotalDof();
    solution.resize(nTotalDof);

    VectorXd rhs(nTotalDof);
    rhs.setZero();
    SparseMatrix<double> m(nTotalDof, nTotalDof);
    SparseLU<SparseMatrix<double>> solver;

    std::vector<Triplet<double>> triplets;
    Map<VectorXd> s(solution.data(), nTotalDof);
    size_t nElements = m_elements.size();
    // size_t nNodesPerEl = m_elements[0]->m_vertices.size();//DBG newton
    // size_t nNodesPerEl = m_elements[0]->getNumEdges();
    size_t nNodesPerEl = m_elements[0]->getNumUnknown();
    size_t vs = nNodesPerEl*m_nFields;
    size_t ms = vs * vs;
    triplets.reserve(nElements * ms + 2*_getLinearBCMatMemSize());
    for(size_t i=0; i<nElements; i++){
      Element *el = m_elements[i];
      for(size_t j=0; j<nNodesPerEl; j++){
	for(size_t k=0; k<m_nFields; k++){
	  // size_t indexJK = _getIndex(std::make_pair(el->getVertex(j), k));//DBG newton
          // size_t indexJK = _getIndex(std::make_pair(el->getEdge(j), k));
          size_t indexJK = _getIndex(el,j, k);
	  size_t localIndexJK = m_nFields*j + k;
	  rhs[indexJK] += localRhs[i][localIndexJK];
	  for(size_t l=0; l<nNodesPerEl; l++){
	    for(size_t m=0; m<m_nFields; m++){
	      // size_t indexLM = _getIndex(std::make_pair(el->getVertex(l), m));//DBG newton
              // size_t indexLM = _getIndex(std::make_pair(el->getEdge(l), m));
              size_t indexLM = _getIndex(el,l, m);
	      size_t localIndexLM = m_nFields*l + m;
	      triplets.emplace_back(indexJK, indexLM, localMat[i][localIndexJK][localIndexLM]);
              // std::cout << "indexJK, index LM: " << indexJK << " " << indexLM << std::endl;
              // std::cout << "nNodesPerEl: " << nNodesPerEl << std::endl;
              // std::cout << "m_nFields: " << m_nFields << std::endl;
	    }
	  }
	}
      }
    }
    for(size_t k=0; k<m_linearBC.size(); k++){
      size_t nLocalLagMult = m_linearBC[k].mat.size();
      for(size_t i=0; i<nLocalLagMult; i++){
	size_t iLagMult = _getIndexLagMult(k, i);
	size_t nLocalDof = m_linearBC[k].dofIndices.size();
	rhs[iLagMult] += m_linearBC[k].vect[i];
	for(size_t j=0; j<nLocalDof; j++){
	  size_t indexDof = m_linearBC[k].dofIndices[j];
	  triplets.emplace_back(iLagMult, indexDof, m_linearBC[k].mat[i][j]);
	  triplets.emplace_back(indexDof, iLagMult, m_linearBC[k].mat[i][j]);
          // std::cout << "iLagMult, indexDof: " << iLagMult << " " << indexDof << std::endl;
	}
      }
    }
    m.setFromTriplets(triplets.begin(), triplets.end());
    solver.compute(m);
    if(solver.info() != Success){
      printf("Solver decomposition failed !!\n");
      gmsh::logger::write(" SOLVER: " + std::to_string(solver.info()), "warning");
      gmsh::logger::write("SOLVER: Decomposition failed", "error");
    }
    s = solver.solve(rhs);
    if(solver.info() != Success){
      gmsh::logger::write("SOLVER: " + std::to_string(solver.info()), "warning");
      gmsh::logger::write("SOLVER: Solve failed", "error");
    }
  }
  
  void Solver::_solveNewtonStep(std::vector<double> &solution, double &residual){
    std::vector<std::vector<std::vector<double>>> localMat;
    std::vector<std::vector<double>> localRhs;
    localMat.resize(m_elements.size());
    localRhs.resize(m_elements.size());
    for(size_t k=0; k<m_elements.size(); k++){
      Element *el = m_elements[k];
      std::vector<std::vector<double>> solEl;
      // solEl.resize(el->m_vertices.size());//DBG newton
      solEl.resize(el->getNumEdges());
      for(size_t l=0; l<solEl.size(); l++)
	solEl[l].resize(m_nFields, 0.0);

      for(size_t l=0; l<solEl.size(); l++)
	for(size_t m=0; m<m_nFields; m++){
	  // solEl[l][m] = solution[_getIndex(std::make_pair(el->getVertex(l), m))];//DBG newton
          // solEl[l][m] = solution[_getIndex(std::make_pair(el->getEdge(l), m))];
          solEl[l][m] = solution[_getIndex(el, l, m)];
	}
      m_objFunc->getHessianAndGradient(m_elements[k], solEl, localMat[k], localRhs[k]);
    }
    std::vector<double> updateSol;
    updateSol.resize(getNTotalDof(), 0.0);
    _solveLinearSys(localMat, localRhs, updateSol);
    for(size_t k=0; k<getNDof(); k++){
      // if(k==100){
      //   std::cout << "sol: " << solution[k] << std::endl;
      //   std::cout << "Correction: " << updateSol[k] << std::endl;
      // }
      solution[k] -= updateSol[k];
    }
    for(size_t k=getNDof(); k<getNTotalDof(); k++)
      solution[k] = -updateSol[k];
    //Residual evaluation
    for(size_t k=0; k<m_elements.size(); k++){
      Element *el = m_elements[k];
      std::vector<std::vector<double>> solEl;
      // solEl.resize(el->m_vertices.size());//DBG newton
      solEl.resize(el->getNumEdges());
      for(size_t l=0; l<solEl.size(); l++)
	solEl[l].resize(m_nFields, 0.0);

      for(size_t l=0; l<solEl.size(); l++)
	for(size_t m=0; m<m_nFields; m++){
	  // solEl[l][m] = solution[_getIndex(std::make_pair(el->getVertex(l), m))];//DBG newton
          solEl[l][m] = solution[_getIndex(std::make_pair(el->getEdge(l), m))];
	}
      // m_objFunc->getGradient(m_elements[k], solEl, localRhs[k]);
      m_objFunc->getHessianAndGradient(m_elements[k], solEl, localMat[k], localRhs[k]);
    }
    std::vector<double> rhs;
    rhs.resize(getNDof(), 0.0);
    for(size_t k=0; k<m_elements.size(); k++){
      // for(size_t l=0; l<m_elements[k]->m_vertices.size(); l++){//DBG newton
      for(size_t l=0; l<m_elements[k]->getNumEdges(); l++){
	for(size_t m=0; m<m_nFields; m++){
	  // size_t dofIndex = _getIndex(std::make_pair(m_elements[k]->getVertex(l), m));//DBG newton
          size_t dofIndex = _getIndex(std::make_pair(m_elements[k]->getEdge(l), m));
	  size_t localIndex = m_nFields*l + m;
	  rhs[dofIndex] += localRhs[k][localIndex];
	}
      }
    }
    //add lagrange multiplier contribution to gradient
    size_t indLagMult = 0;
    for(LinearBC &bc: m_linearBC){
      for(size_t k=0; k<bc.mat.size(); k++){
        // std::cout << "indlagmult: " << indLagMult << std::endl;
        for(size_t l=0; l<bc.mat[k].size(); l++){
          rhs[bc.dofIndices[l]] += solution[getNDof()+indLagMult]*bc.mat[k][l];
        }
        indLagMult++;
      }
    }
    residual = 0.0;
    for(double &r: rhs)
      residual += r*r;
    residual = sqrt(residual);
  }
  
  // void Solver::solveNewton(std::map<Vertex *, std::vector<double>> &mapSolution){//DBG newton
  void Solver::solveNewton(std::map<Edge *, std::vector<double>> &mapSolution){
    // _orthonormalizeConstraints();
    // _checkNormalization();
    // _removeUselessConstraints();
    // _checkNormalization();
    
    _generateLagMultData();
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNTotalDof(), 0.0);
    for(auto &kv: mapSolution){
      for(size_t k=0; k<kv.second.size(); k++)
        solution[_getIndex(std::make_pair(kv.first, k))] = kv.second[k];
    }
    double crit = 0.0;
    double error = 0.0;
    int cpt =0;
    // int max_newton_it = 1000;
    int max_newton_it = 10;
    double tolerance_newton = 1e-10 * getNTotalDof();
    double residual=1.0;
    std::vector<LinearBC> linearBCsave = m_linearBC;
    std::cout << "Starting Newton solver" << std::endl;
    while(cpt < max_newton_it && residual > tolerance_newton){
      std::cout << "Newton solver. It: " << cpt << ", ";
      //Modify linearBC for newton solver
      // for(auto &bc: m_linearBC){
      for(size_t iBC=0; iBC<m_linearBC.size(); iBC++){
	LinearBC &bc = m_linearBC[iBC];
	for(size_t k=0; k<bc.mat.size(); k++){
	  double currentVal = 0.0;
	  for(size_t l=0; l<bc.mat[k].size(); l++){
	    currentVal += bc.mat[k][l]*solution[bc.dofIndices[l]];
	  }
	  bc.vect[k] = -(linearBCsave[iBC].vect[k] - currentVal);
	}
      }

      _solveNewtonStep(solution, residual);
      // std::cout << "residual= " << residual << std::endl;
      // std::cout << "norm sol: " << tools::norm(solution.data(), getNDof()) << std::endl;
      // std::cout << "norm lagmult: " << tools::norm(solution.data()+getNDof(), getNLagMult()) << std::endl;
      std::cout << "residual = " << residual << ", tolerance: " << tolerance_newton <<'\r' << std::flush;
      cpt++;
    }
    std::cout << std::endl;
    for(auto &pel: m_elements)
      // for(auto &pv: pel->m_vertices){//DBG newton
      for(auto &pv: pel->getEdges()){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = solution[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
    //restore bc
    m_linearBC = linearBCsave;
  }

  void Solver::solveNewton(std::map<Vertex *, std::vector<double>> &mapSolution){
    // _orthonormalizeConstraints();
    // _checkNormalization();
    // _removeUselessConstraints();
    // _checkNormalization();
    
    _generateLagMultData();
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNTotalDof(), 0.0);
    for(auto &kv: mapSolution){
      for(size_t k=0; k<kv.second.size(); k++)
        solution[_getIndex(std::make_pair(kv.first, k))] = kv.second[k];
    }
    double crit = 0.0;
    double error = 0.0;
    int cpt =0;
    // int max_newton_it = 1000;
    int max_newton_it = 10;
    double tolerance_newton = 1e-10 * getNTotalDof();
    double residual=1.0;
    std::vector<LinearBC> linearBCsave = m_linearBC;
    std::cout << "Starting Newton solver" << std::endl;
    while(cpt < max_newton_it && residual > tolerance_newton){
      std::cout << "Newton solver. It: " << cpt << ", ";
      //Modify linearBC for newton solver
      // for(auto &bc: m_linearBC){
      for(size_t iBC=0; iBC<m_linearBC.size(); iBC++){
	LinearBC &bc = m_linearBC[iBC];
	for(size_t k=0; k<bc.mat.size(); k++){
	  double currentVal = 0.0;
	  for(size_t l=0; l<bc.mat[k].size(); l++){
	    currentVal += bc.mat[k][l]*solution[bc.dofIndices[l]];
	  }
	  bc.vect[k] = -(linearBCsave[iBC].vect[k] - currentVal);
	}
      }

      _solveNewtonStep(solution, residual);
      // std::cout << "residual= " << residual << std::endl;
      // std::cout << "norm sol: " << tools::norm(solution.data(), getNDof()) << std::endl;
      // std::cout << "norm lagmult: " << tools::norm(solution.data()+getNDof(), getNLagMult()) << std::endl;
      std::cout << "residual = " << residual << ", tolerance: " << tolerance_newton <<'\r' << std::flush;
      cpt++;
    }
    std::cout << std::endl;
    for(auto &pel: m_elements)
      // for(auto &pv: pel->m_vertices){//DBG newton
      for(auto &pv: pel->getVertices()){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = solution[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
    //restore bc
    m_linearBC = linearBCsave;
  }

}
