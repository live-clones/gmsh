// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file in the Gmsh root directory for license information.
// Please report all issues on https://gitlab.onelab.info/gmsh/gmsh/issues.
//
// Author: Alexandre Chemin

#pragma once

#include <IffTools.hxx>
#include <ObjectiveFunctions.hxx>

namespace IFF{
  class Solver{
  public:
    
    enum class TYPEUNKNOWN{VERTEX, EDGE, ELEMENT};

    Solver(Mesh *m, int nFields, ObjectiveFunction *objFunc, TYPEUNKNOWN unknownType=TYPEUNKNOWN::VERTEX);
    ~Solver(){}

    void printInfos(){
      std::cout << "--- --- SOLVER INFOS ---" << std::endl;
      std::cout << "-- nDofs: " << getNDof() << std::endl;
      std::cout << "--- ---" << std::endl;
    }
    void solveLBFGS(std::map<Edge*, std::vector<double>> &mapSolution);
    
    void addBCDirichlet(const std::pair<Edge*, int> &pairEdgeField, double valBC);
    void addBCDirichlet(const std::vector<std::pair<Edge*, int>> &pairEdgeField, const std::vector<double> &valBC);
    void addBCLinearCombination(const std::vector<std::vector<double>> &mat, const std::vector<double> &vect, const std::vector<std::pair<Edge*, int>> &pairEdgeField);

    size_t getNDof(){return m_nDof;}

    void setObjectiveFunction(ObjectiveFunction *f){m_objFunc = f;}
    
    TYPEUNKNOWN m_unknownType;
    Mesh *m_mesh;
    size_t m_nFields;
    size_t m_nLagMult;
    size_t m_nDof;
    size_t m_nVertices;

    std::vector<Element*> m_elements;
    std::vector<Edge*> m_edges;
    std::vector<Vertex*> m_vertices;

    ObjectiveFunction *m_objFunc;
    
    size_t m_alglibrep;
    double m_func_prec;
    // std::vector<double> m_funcs; // when the objective function has multiple objectives, to pass to callback_rep
    size_t m_maxItLbfgs;
    double m_lbfgsGradPrec;
    double m_lbfgsFuncPrec;
    double m_lbfgsXPrec;

    //Public for Alglib, not to be used outside of the class
    size_t _getIndex(std::pair<Edge*, int> pairEdgeField){return m_nFields*pairEdgeField.first->getIndex() + pairEdgeField.second;}
    size_t _getIndex(Element *e, int iUnknown, int iField){
      if(m_unknownType == TYPEUNKNOWN::EDGE){
        return _getIndex(std::make_pair(e->getEdge(iUnknown), iField));
      }
      else{
        std::cout << "Unkown type not implemented" << std::endl;
        exit(0);
      }
    }

    struct LinearBC{
      std::vector<std::vector<double>> mat;
      std::vector<double> vect;
      std::vector<size_t> dofIndices;
    };

    std::vector<LinearBC> m_linearBC;
    //
    
  private:

  };
}
