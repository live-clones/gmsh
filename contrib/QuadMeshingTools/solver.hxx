#ifndef CFMB_SOLVER_H
#define CFMB_SOLVER_H

#include <vector>
#include "mesh.hxx"
#include "objectiveFunction.hxx"

//Alglib includes
#include <optimization.h>
//

namespace IFF{
  
  namespace LINEARSOLVER{
    const int EIGEN=0;
  }

  namespace SOLVEMETHOD{
    const int NEWTON=0;
    const int LBFGS=1;
  }

  class Solver
  {
  
  public:
    Solver(std::vector<Triangle *> &triangles, int nFields, ObjectiveFunction *objFunc) : m_objFunc(objFunc)
    {
      m_triangles = triangles;
      m_nFields = nFields;
      m_nLagMult = m_nDof = m_nVertices = 0;
      _solveMethod = SOLVEMETHOD::NEWTON;
      _linearSolver = LINEARSOLVER::EIGEN;
      _numberVertices();
      m_alglibrep = 0;
      m_func_prec = 0.0;
      m_maxItLbfgs = 15000;
      m_lbfgsGradPrec = 1e-10;
      m_lbfgsFuncPrec = 0.0;
      m_lbfgsXPrec = 0.0;
    }
    ~Solver(){}

    size_t m_alglibrep;
    double m_func_prec;
    size_t m_maxItLbfgs;
    double m_lbfgsGradPrec;
    double m_lbfgsFuncPrec;
    double m_lbfgsXPrec;
    std::vector<Line*> m_lines;
    std::vector<Triangle*> m_triangles;

    void addBCNeumann(std::vector<std::pair<Line *, int>> &pairLineField, std::vector<double> valBC);
    void addBCDirichlet(std::vector<std::pair<Vertex *, int>> &pairVertexField, std::vector<double> valBC);
    void addBCLinearCombination(std::vector<std::vector<double>> &mat, std::vector<double> &vect, std::vector<std::pair<Vertex *, int>> &pairVertexField);
    void clearBC(){m_linearBC.clear(); m_nLagMult = 0;}
    size_t getNVertices(){return m_nVertices;}
    size_t getNDof(){return m_nDof;}
    size_t getNLagMult(){return m_nLagMult;}
    size_t getNTotalDof(){return m_nDof+m_nLagMult;}
  
    void solve(std::map<Vertex *, std::vector<double>> &mapSolution);
    void solveNewton(std::map<Vertex *, std::vector<double>> &mapSolution);
    void testGrad(std::map<Vertex *, std::vector<double>> &mapSolution);
    void _modifyLinearBCForLBFGS();
    void solveLBFGS(std::map<Vertex *, std::vector<double>> &mapSolution);
  
    void printSolverInfos(){
      gmsh::logger::write("SOLVER: n_vertices: " + std::to_string(getNVertices()), "info");
      gmsh::logger::write("SOLVER: n_unknown: " + std::to_string(getNDof()), "info");
      gmsh::logger::write("SOLVER: n_lagmult: " + std::to_string(getNLagMult()), "info");
      gmsh::logger::write("SOLVER: n_totDof: " + std::to_string(getNTotalDof()), "info");
    }
  
    struct LinearBC{
      std::vector<std::vector<double>> mat;
      std::vector<double> vect;
      std::vector<size_t> dofIndices;
    };
  
    size_t m_nVertices;
    size_t m_nDof;
    size_t m_nLagMult;
    int m_nFields;
    std::map<Vertex*, std::vector<double>> m_nodeData;

  
    ObjectiveFunction *m_objFunc;
    int _solveMethod;
    int _linearSolver;
    std::vector<LinearBC> m_linearBC;

    void _numberVertices();
    void _solveLinearSys(std::vector<std::vector<std::vector<double>>> &localMat, std::vector<std::vector<double>> &localRhs, std::vector<double> &solution);

    void _solveNewtonStep(std::vector<double> &solution, double &residual);
    size_t _getIndex(std::pair<Vertex *, int> pairVertexField){return m_nFields*pairVertexField.first->getIndex() + pairVertexField.second;}
    size_t _getIndexLagMult(size_t linBCIndex, size_t locLagMultIndex){
      size_t index = m_nDof;
      for(size_t k=0; k<linBCIndex; k++)
	index += m_linearBC[k].mat.size();
      index += locLagMultIndex;
      return index;
    }
    size_t _getLinearBCMatMemSize(){
      size_t memSize = 0;
      for(auto bc: m_linearBC){
	memSize += bc.mat.size()*bc.mat[0].size();
      }
      return memSize;
    }

  private:
  
  };

}
#endif
