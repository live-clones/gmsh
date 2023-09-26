#include <gmsh.h>
#include "solver.hxx"
#include "tools.hxx"
#include "timer.hxx"

//Alglib includes
#include <stdafx.h>
#include <optimization.h>
//

#include <Eigen/Dense>
#include <Eigen/SparseLU>
#include <omp.h>

using namespace IFF;

namespace IFF{
  
  void Solver::_numberVertices(){
    for(auto &line: m_lines)
      for(auto &vert: line->m_vertices)
	vert->setIndex(-1);

    for(auto &tri: m_triangles)
      for(auto &vert: tri->m_vertices)
	vert->setIndex(-1);

    m_nVertices = 0;
    for(auto &line: m_lines)
      for(auto &vert: line->m_vertices){
	if(vert->getIndex() == -1){
	  vert->setIndex(m_nVertices);
	  m_nVertices++;
	}
      }

    for(auto &tri: m_triangles)
      for(auto &vert: tri->m_vertices){
	if(vert->getIndex() == -1){
	  vert->setIndex(m_nVertices);
	  m_nVertices++;
	}
      }

    m_nDof = m_nVertices*m_nFields;
  }

  void Solver::addBCNeumann(std::vector<std::pair<Line *, int>> &pairLineField, std::vector<double> val){
    gmsh::logger::write("Neumann boundary conditions not implemented yet", "error");
  }

  void Solver::addBCDirichlet(std::vector<std::pair<Vertex *, int>> &pairVertexField, std::vector<double> valBC){
    for(size_t k=0; k<pairVertexField.size(); k++){
      std::vector<std::vector<double>> mat;
      mat.resize(1); mat[0].resize(1); mat[0][0] = 1.0;
      std::vector<double> vect;
      vect.resize(1); vect[0] = valBC[k];
      std::vector<std::pair<Vertex *, int>> pairVF;
      pairVF.resize(1, pairVertexField[k]);
      addBCLinearCombination(mat, vect, pairVF);
    }
  }

  void Solver::addBCLinearCombination(std::vector<std::vector<double>> &mat, std::vector<double> &vect, std::vector<std::pair<Vertex *, int>> &pairVertexField){
    LinearBC bc;
    m_linearBC.push_back(bc);
    m_linearBC[m_linearBC.size()-1].mat = mat;
    m_linearBC[m_linearBC.size()-1].vect = vect;
    std::vector<size_t> dofIndices;
    dofIndices.reserve(vect.size());
    for(auto &vf: pairVertexField)
      dofIndices.push_back(_getIndex(vf));
    m_linearBC[m_linearBC.size()-1].dofIndices = dofIndices;
  
    m_nLagMult += vect.size();
  }

  void Solver::solve(std::map<Vertex *, std::vector<double>> &mapSolution){
    std::vector<std::vector<std::vector<double>>> localMat;
    std::vector<std::vector<double>> localRhs;
    localMat.resize(m_triangles.size());
    localRhs.resize(m_triangles.size());
    std::vector<double> solution;
    solution.clear();
    solution.resize(getNTotalDof(), 0.0);

    //In case nodeData is needed, storing it in a vector not to lose to much time looking in the map
    if(m_objFunc->m_useNodeData){
      std::vector<double> nodeDataByIndex;
      size_t nDataPerNode = m_nodeData.begin()->second.size();
      nodeDataByIndex.resize(m_nVertices*nDataPerNode);
      for(auto &kv: m_nodeData)
	for(size_t l=0; l<kv.second.size(); l++){
	  size_t ind = nDataPerNode*kv.first->getIndex() + l;
	  nodeDataByIndex[ind] = kv.second[l];
	}
      for(size_t k=0; k<m_triangles.size(); k++){
	std::vector<std::vector<double>> nodeDataTri;
	nodeDataTri.resize(3);
	for(size_t l=0; l<3; l++)
	  nodeDataTri[l].resize(nDataPerNode, 0.0);
	for(size_t l=0; l<3; l++)
	  for(size_t m=0; m<nDataPerNode; m++){
	    size_t ind = nDataPerNode*m_triangles[k]->getVertex(l)->getIndex() + m;
	    nodeDataTri[l][m] = nodeDataByIndex[ind];
	  }
	void *pVoidData = (void*) &nodeDataTri;
	m_objFunc->getFEMOperators(m_triangles[k], localMat[k], localRhs[k], pVoidData);
      }
    }
    else
      for(size_t k=0; k<m_triangles.size(); k++)
	m_objFunc->getFEMOperators(m_triangles[k], localMat[k], localRhs[k]);
    GlobalTimer::tic("SOLVING_LINEAR_SYS");
    _solveLinearSys(localMat, localRhs, solution);
    GlobalTimer::toc();
    for(auto &ptri: m_triangles)
      for(auto &pv: ptri->m_vertices){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = solution[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
  }

  void Solver::solveNewton(std::map<Vertex *, std::vector<double>> &mapSolution){
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
    int max_newton_it = 1000;
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
      std::cout << "residual = " << residual << ", tolerance: " << tolerance_newton <<'\r' << std::flush;
      cpt++;
    }
    std::cout << std::endl;
    for(auto &ptri: m_triangles)
      for(auto &pv: ptri->m_vertices){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = solution[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
    //restore bc
    m_linearBC = linearBCsave;
  }

  void _lbfgs_rep_callback(const alglib::real_1d_array &x, double func, void *ptr) // Callback for lbfgs, compute objective function value and it's gradient
  {
    Solver *solver = (Solver*) ptr;
    double deltaF = (func - solver->m_func_prec) / func;
    if(solver->m_alglibrep == 0){
      std::cout << "f init = " << func << std::endl;;
    }
    if(solver->m_alglibrep%30 == 0){
      std::cout << "It: " << solver->m_alglibrep << ", f = " << func << ", df = " << deltaF <<'\r' << std::flush;
      // std::cout << "It: " << solver->m_alglibrep << ", f = " << func << ", df = " << deltaF << std::endl;
      // // std::vector<double> dbg{x[3*286+0], x[3*286+1], x[3*286+2]};
      // // tools::normalize(dbg);
      // // std::cout << "frame node 291: " << dbg[0] << " " << dbg[1] << " " << dbg[2] << std::endl;
      // double real_sum_sizes = 0.0;
      // for(size_t k=0; k<solver->m_nVertices; k++){
      //   // if(x[3*k] < 0.0){
      //   // 	std::cout << "negative q0 value, abort" << std::endl;
      //   // 	exit(0);
      //   // }
      //   real_sum_sizes += x[3*k];
      // }
      // std::cout << "average_size: " << real_sum_sizes/(solver->m_nVertices*(2*3*sqrt(2*M_PI)/8.0)) << std::endl;
    }
    solver->m_alglibrep++;
    solver->m_func_prec = func;
  }

  void _lbfgs_callback(const alglib::real_1d_array &x, double &func, alglib::real_1d_array &grad, void *ptr) // Callback for lbfgs, compute objective function value and it's gradient
  {
    Solver *solver = (Solver*) ptr;
    GlobalTimer::tic("LBFGS_FUNC_EVAL");
    func = 0.0;

#pragma omp parallel for reduction(+:func)
    for(size_t k=0; k<solver->m_triangles.size(); k++){
      Triangle *tri = solver->m_triangles[k];
      std::vector<std::vector<double>> solTri;
      solTri.resize(tri->m_vertices.size());
      for(size_t l=0; l<solTri.size(); l++)
	solTri[l].resize(solver->m_nFields, 0.0);

      for(size_t l=0; l<solTri.size(); l++)
	for(size_t m=0; m<solver->m_nFields; m++){
	  solTri[l][m] = x[solver->_getIndex(std::make_pair(tri->getVertex(l), m))];
	}

      double val=0.0;
      solver->m_objFunc->evaluateFunction(solver->m_triangles[k], val, solTri);
      func += val;
    }
    GlobalTimer::toc();
    GlobalTimer::tic("LBFGS_GRAD_EVAL");
    //Now computing gradient
    for(size_t k=0; k<solver->getNDof(); k++)
      grad[k] = 0.0;
    GlobalTimer::tic("GRAD_ELEM_EVAL");
    std::vector<std::vector<double>> localRhs;
    localRhs.resize(solver->m_triangles.size());
  
#pragma omp parallel for
    for(size_t k=0; k<solver->m_triangles.size(); k++){
      Triangle *tri = solver->m_triangles[k];
      std::vector<std::vector<double>> solTri;
      solTri.resize(tri->m_vertices.size());
      for(size_t l=0; l<solTri.size(); l++)
	solTri[l].resize(solver->m_nFields, 0.0);

      for(size_t l=0; l<solTri.size(); l++)
	for(size_t m=0; m<solver->m_nFields; m++){
	  solTri[l][m] = x[solver->_getIndex(std::make_pair(tri->getVertex(l), m))];
	}
      solver->m_objFunc->getFEMGradient(solver->m_triangles[k], localRhs[k], solTri);
    }
  
    GlobalTimer::toc();
    //Assemble gradient
    GlobalTimer::tic("GRAD_ASSEMBLY");

    double *pDataGrad = grad.getcontent();
#pragma omp parallel for reduction(+:pDataGrad[:solver->getNDof()])
    for(size_t k=0; k<solver->m_triangles.size(); k++){
      for(size_t l=0; l<solver->m_triangles[k]->m_vertices.size(); l++){
	for(size_t m=0; m<solver->m_nFields; m++){
	  size_t dofIndex = solver->_getIndex(std::make_pair(solver->m_triangles[k]->getVertex(l), m));
	  size_t localIndex = solver->m_nFields*l + m;
	  // grad[dofIndex] += localRhs[k][localIndex];
	  pDataGrad[dofIndex] += localRhs[k][localIndex];
	}
      }
    }
    GlobalTimer::toc();
  
    //Project gradient on linear admissible set
    // #pragma omp parallel for reduction(-:pDataGrad[:solver->getNDof()])
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
	  // grad[solver->m_linearBC[k].dofIndices[j]] -= dotprod*normalSet[j];
	  pDataGrad[solver->m_linearBC[k].dofIndices[j]] -= dotprod*normalSet[j];
      }
    }
    // double normGrad = 0.0;
    // for(size_t k=0; k<solver->getNDof(); k++)
    //   normGrad += grad[k]*grad[k];
    // normGrad = sqrt(normGrad);
    // std::cout << "normgrad: " << normGrad << std::endl;
    GlobalTimer::toc();
  }

  void Solver::testGrad(std::map<Vertex *, std::vector<double>> &mapSolution){
    std::cout << "test grad" << std::endl;
    std::vector<double> solution;
    solution.clear();
    // solution.resize(getNTotalDof(), 0.0);
    solution.resize(getNDof(), 0.0);
    for(auto &kv: mapSolution){
      for(size_t k=0; k<kv.second.size(); k++)
	solution[_getIndex(std::make_pair(kv.first, k))] = kv.second[k];
    }
    // for(size_t k=0; k<getNLagMult(); k++){
    //   solution[getNDof()+k] = 1+k;
    // }
    Solver *solver = this;
    double funcRef = 0.0;
    for(size_t k=0; k<solver->m_triangles.size(); k++){
      Triangle *tri = solver->m_triangles[k];
      std::vector<std::vector<double>> solTri;
      solTri.resize(tri->m_vertices.size());
      for(size_t l=0; l<solTri.size(); l++)
	solTri[l].resize(solver->m_nFields, 0.0);

      for(size_t l=0; l<solTri.size(); l++)
	for(size_t m=0; m<solver->m_nFields; m++){
	  solTri[l][m] = solution[solver->_getIndex(std::make_pair(tri->getVertex(l), m))];
	}
      double val=0.0;
      solver->m_objFunc->evaluateFunction(solver->m_triangles[k], val, solTri);
      funcRef += val;
    }
    std::cout << "val func: " << funcRef << std::endl;
    // //Need to add lagrange mult in the function evaluation
    // size_t indLagMult = 0;
    // for(Solver::LinearBC &bc: solver->m_linearBC){
    //   for(size_t k=0; k<bc.mat.size(); k++){
    // 	double val = 0.0;
    // 	for(size_t l=0; l<bc.mat[k].size(); l++){
    // 	  val += bc.mat[k][l]*solution[bc.dofIndices[l]];
    // 	}
    // 	funcRef += solution[solver->getNDof()+indLagMult]*(val - bc.vect[k]);
    // 	// func += x[solver->getNDof()+indLagMult]*x[solver->getNDof()+indLagMult];//test render hess definite positive
    // 	indLagMult++;
    //   }
    // }
    std::vector<double> grad;
    grad.resize(getNTotalDof(), 0.0);
    //Now computing gradient
    for(size_t k=0; k<solver->getNTotalDof(); k++)
      grad[k] = 0.0;
    std::vector<std::vector<double>> localRhs;
    localRhs.resize(solver->m_triangles.size());
    for(size_t k=0; k<solver->m_triangles.size(); k++){
      Triangle *tri = solver->m_triangles[k];
      std::vector<std::vector<double>> solTri;
      solTri.resize(tri->m_vertices.size());
      for(size_t l=0; l<solTri.size(); l++)
	solTri[l].resize(solver->m_nFields, 0.0);

      for(size_t l=0; l<solTri.size(); l++)
	for(size_t m=0; m<solver->m_nFields; m++){
	  solTri[l][m] = solution[solver->_getIndex(std::make_pair(tri->getVertex(l), m))];
	}
      solver->m_objFunc->getFEMGradient(solver->m_triangles[k], localRhs[k], solTri);
    }
    //Assemble gradient
    for(size_t k=0; k<solver->m_triangles.size(); k++){
      for(size_t l=0; l<solver->m_triangles[k]->m_vertices.size(); l++){
	for(size_t m=0; m<solver->m_nFields; m++){
	  size_t dofIndex = solver->_getIndex(std::make_pair(solver->m_triangles[k]->getVertex(l), m));
	  size_t localIndex = solver->m_nFields*l + m;
	  grad[dofIndex] += localRhs[k][localIndex];
	}
      }
    }
    // //add lagrange multiplier contribution to gradient
    // // size_t indLagMult = 0;
    // indLagMult = 0;
    // for(Solver::LinearBC &bc: solver->m_linearBC){
    //   for(size_t k=0; k<bc.mat.size(); k++){
    // 	for(size_t l=0; l<bc.mat[k].size(); l++){
    // 	  grad[bc.dofIndices[l]] += solution[solver->getNDof()+indLagMult]*bc.mat[k][l];
    // 	}
    // 	indLagMult++;
    //   }
    // }
    // for(size_t k=0; k<solver->m_linearBC.size(); k++){
    //   size_t nLocalLagMult = solver->m_linearBC[k].mat.size();
    //   for(size_t i=0; i<nLocalLagMult; i++){
    // 	size_t iLagMult = solver->_getIndexLagMult(k, i);
    // 	size_t nLocalDof = solver->m_linearBC[k].dofIndices.size();
    // 	for(size_t j=0; j<nLocalDof; j++)
    // 	  grad[iLagMult] += solver->m_linearBC[k].mat[i][j]*solution[solver->m_linearBC[k].dofIndices[j]];
    // 	grad[iLagMult] -= solver->m_linearBC[k].vect[i];
    // 	// grad[iLagMult] += 2*x[iLagMult];//test to render hess deinfite positive
    //   }
    // }
  
    double normDiff = 0.0;
    double normGrad = 0.0;
    double delta = 1e-6;
    // for(size_t iK=0; iK<solver->getNTotalDof(); iK++){
    for(size_t iK=0; iK<solver->getNDof(); iK++){
      std::cout << "index: " << iK << " / " << solver->getNTotalDof() << std::endl;
      double solSave = solution[iK];
      if(fabs(solution[iK])<1e-10)
	solution[iK] += delta;
      else
	solution[iK] *= (1+delta);
      double func = 0.0;
      for(size_t k=0; k<solver->m_triangles.size(); k++){
	Triangle *tri = solver->m_triangles[k];
	std::vector<std::vector<double>> solTri;
	solTri.resize(tri->m_vertices.size());
	for(size_t l=0; l<solTri.size(); l++)
	  solTri[l].resize(solver->m_nFields, 0.0);

	for(size_t l=0; l<solTri.size(); l++)
	  for(size_t m=0; m<solver->m_nFields; m++){
	    solTri[l][m] = solution[solver->_getIndex(std::make_pair(tri->getVertex(l), m))];
	  }
	double val=0.0;
	solver->m_objFunc->evaluateFunction(solver->m_triangles[k], val, solTri);
	func += val;
      }
      // //Need to add lagrange mult in the functino evaluation
      // size_t indLagMult = 0;
      // for(Solver::LinearBC &bc: solver->m_linearBC){
      // 	for(size_t k=0; k<bc.mat.size(); k++){
      // 	  double val = 0.0;
      // 	  for(size_t l=0; l<bc.mat[k].size(); l++){
      // 	    val += bc.mat[k][l]*solution[bc.dofIndices[l]];
      // 	  }
      // 	  func += solution[solver->getNDof()+indLagMult]*(val - bc.vect[k]);

      // 	  indLagMult++;
      // 	}
      // }
      double gradNode = (func - funcRef)/(solution[iK]-solSave);
      normDiff += (grad[iK] - gradNode)*(grad[iK] - gradNode);
      normGrad += grad[iK]*grad[iK];
      // solution[iK] -= delta;
      solution[iK] = solSave;
    }
    // normDiff = sqrt(normDiff)/getNTotalDof();
    normDiff = sqrt(normDiff);
    normGrad = sqrt(normGrad);

    std::cout << "normDiff: " << normDiff << std::endl;
    std::cout << "normGrad: " << normGrad << std::endl;
    exit(0);
  }

  void Solver::_modifyLinearBCForLBFGS(){ // To be optimized, not usable in this state
    std::vector<std::vector<double>> newMat;
    newMat.resize(m_nLagMult);
    for(size_t k=0; k<m_nLagMult; k++)
      newMat[k].resize(m_nDof, 0.0);
    size_t currentLagMult = 0;
    for(size_t k=0; k<m_linearBC.size(); k++){
      size_t nLines = m_linearBC[k].mat.size();
      for(size_t i=0; i<nLines; i++){
	size_t nCol = m_linearBC[k].mat[i].size();
	for(size_t j=0; j<nCol; j++)
	  newMat[currentLagMult][m_linearBC[k].dofIndices[j]] = m_linearBC[k].mat[i][j];
	//gram schmidt
	for(size_t iVect=0; iVect<currentLagMult; iVect++){
	  double dotprod = tools::dotprod(newMat[currentLagMult], newMat[iVect]);
	  for(size_t l=0; l<m_nDof; l++)
	    newMat[currentLagMult][l] -= dotprod*newMat[iVect][l];
	}
	tools::normalize(newMat[currentLagMult]);
	currentLagMult++;
      }
    }
  
    m_linearBC.clear();
    m_nLagMult = 0;
    for(size_t k=0; k<currentLagMult; k++){
      size_t nNonZeroEntry = 0;
      for(size_t j=0; j<m_nDof; j++)
	if(fabs(newMat[k][j]) > 1e-12)
	  nNonZeroEntry++;
      
      std::vector<std::vector<double>> mat;
      mat.resize(1);
      mat[0].resize(nNonZeroEntry, 0.0);
      std::vector<double> vect{0.0};
      std::vector<size_t> dofIndices;
      dofIndices.reserve(nNonZeroEntry);
      for(size_t j=0; j<m_nDof; j++){
	if(fabs(newMat[k][j]) > 1e-12){
	  mat[0][dofIndices.size()] = newMat[k][j];
	  dofIndices.push_back(j);
	}
      }
      LinearBC bc;
      m_linearBC.push_back(bc);
      m_linearBC[m_linearBC.size()-1].mat = mat;
      m_linearBC[m_linearBC.size()-1].vect = vect;
      m_linearBC[m_linearBC.size()-1].dofIndices = dofIndices;
      m_nLagMult += vect.size();
    }
  }

  void Solver::solveLBFGS(std::map<Vertex *, std::vector<double>> &mapSolution){
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
    for(auto &ptri: m_triangles)
      for(auto &pv: ptri->m_vertices){
	std::vector<double> solVert(m_nFields, 0.0);
	for(int k=0; k<m_nFields; k++){
	  solVert[k] = x[_getIndex(std::make_pair(pv, k))];
	}
	mapSolution[pv] = solVert;
      }
  }

  void Solver::_solveNewtonStep(std::vector<double> &solution, double &residual){
    std::vector<std::vector<std::vector<double>>> localMat;
    std::vector<std::vector<double>> localRhs;
    localMat.resize(m_triangles.size());
    localRhs.resize(m_triangles.size());
    GlobalTimer::tic("NEWTON_ELEM_OP_EVALUATION");
    for(size_t k=0; k<m_triangles.size(); k++){
      Triangle *tri = m_triangles[k];
      std::vector<std::vector<double>> solTri;
      solTri.resize(tri->m_vertices.size());
      for(size_t l=0; l<solTri.size(); l++)
	solTri[l].resize(m_nFields, 0.0);

      for(size_t l=0; l<solTri.size(); l++)
	for(size_t m=0; m<m_nFields; m++){
	  solTri[l][m] = solution[_getIndex(std::make_pair(tri->getVertex(l), m))];
	}
      m_objFunc->getFEMHessianAndGradient(m_triangles[k], localMat[k], localRhs[k], solTri);
    }
    GlobalTimer::toc();
    std::vector<double> updateSol;
    updateSol.resize(getNTotalDof(), 0.0);
    GlobalTimer::tic("NEWTON_SOLVE_SYS");
    _solveLinearSys(localMat, localRhs, updateSol);
    for(size_t k=0; k<getNDof(); k++)
      solution[k] -= updateSol[k];
    for(size_t k=getNDof(); k<getNTotalDof(); k++)
      solution[k] = -updateSol[k];
    GlobalTimer::toc();
    //Residual evaluation
    for(size_t k=0; k<m_triangles.size(); k++){
      Triangle *tri = m_triangles[k];
      std::vector<std::vector<double>> solTri;
      solTri.resize(tri->m_vertices.size());
      for(size_t l=0; l<solTri.size(); l++)
	solTri[l].resize(m_nFields, 0.0);

      for(size_t l=0; l<solTri.size(); l++)
	for(size_t m=0; m<m_nFields; m++){
	  solTri[l][m] = solution[_getIndex(std::make_pair(tri->getVertex(l), m))];
	}
      m_objFunc->getFEMGradient(m_triangles[k], localRhs[k], solTri);
    }
    std::vector<double> rhs;
    rhs.resize(getNDof(), 0.0);
    for(size_t k=0; k<m_triangles.size(); k++){
      for(size_t l=0; l<m_triangles[k]->m_vertices.size(); l++){
	for(size_t m=0; m<m_nFields; m++){
	  size_t dofIndex = _getIndex(std::make_pair(m_triangles[k]->getVertex(l), m));
	  size_t localIndex = m_nFields*l + m;
	  rhs[dofIndex] += localRhs[k][localIndex];
	}
      }
    }
    //add lagrange multiplier contribution to gradient
    size_t indLagMult = 0;
    for(LinearBC &bc: m_linearBC){
      for(size_t k=0; k<bc.mat.size(); k++){
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

  void Solver::_solveLinearSys(std::vector<std::vector<std::vector<double>>> &localMat, std::vector<std::vector<double>> &localRhs, std::vector<double> &solution){
    using namespace Eigen;
    size_t nTotalDof = getNTotalDof();
    solution.resize(nTotalDof);

    VectorXd rhs(nTotalDof);
    rhs.setZero();
    SparseMatrix<double> m(nTotalDof, nTotalDof);
    SparseLU<SparseMatrix<double>> solver;

    std::vector<Triplet<double>> triplets;
    Map<VectorXd> s(solution.data(), nTotalDof);
    size_t nElements = m_triangles.size();
    size_t nNodesPerEl = m_triangles[0]->m_vertices.size();
    size_t vs = nNodesPerEl*m_nFields;
    size_t ms = vs * vs;
    triplets.reserve(nElements * ms + 2*_getLinearBCMatMemSize());
    for(size_t i=0; i<nElements; i++){
      Triangle *tri = m_triangles[i];
      for(size_t j=0; j<nNodesPerEl; j++){
	for(size_t k=0; k<m_nFields; k++){
	  size_t indexJK = _getIndex(std::make_pair(tri->getVertex(j), k));
	  size_t localIndexJK = m_nFields*j + k;
	  rhs[indexJK] += localRhs[i][localIndexJK];
	  for(size_t l=0; l<nNodesPerEl; l++){
	    for(size_t m=0; m<m_nFields; m++){
	      size_t indexLM = _getIndex(std::make_pair(tri->getVertex(l), m));
	      size_t localIndexLM = m_nFields*l + m;
	      triplets.emplace_back(indexJK, indexLM, localMat[i][localIndexJK][localIndexLM]);
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
	}
      }
    }
    m.setFromTriplets(triplets.begin(), triplets.end());
    solver.compute(m);
    if(solver.info() != Success){
      printf("Solver decomposition failed !!\n");
      gmsh::logger::write(" SOLVER: " + solver.info(), "warning");
      gmsh::logger::write("SOLVER: Decomposition failed", "error");
    }
    s = solver.solve(rhs);
    if(solver.info() != Success){
      gmsh::logger::write("SOLVER: " + solver.info(), "warning");
      gmsh::logger::write("SOLVER: Solve failed", "error");
    }
  }

}
