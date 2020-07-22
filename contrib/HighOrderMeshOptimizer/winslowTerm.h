// Gmsh - Copyright (C) 1997-2020 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#ifndef WINSLOW_TERM_H
#define WINSLOW_TERM_H

#include "femTerm.h"
#include "GmshGlobal.h"
#include "GModel.h"
#include "polynomialBasis.h"
#include "SElement.h"
#include "fullMatrix.h"

struct winslowDataAtGaussPoint {
  std::vector<fullMatrix<double> > gradSF;
  std::vector<double> u, v, w, weight;
};

struct winslowDataAtNode {
  std::vector<fullMatrix<double> > gradSF;
  std::vector<double> u, v, w;
};

/*
  Formulation of winslow with mesh elements as parametric space
*/

class winslowTerm : public femTerm<double> {
protected:
  std::map<MVertex *, SVector3> *_currentSolution;
  std::map<MVertex *, SVector3> *_alpha;
  int _idComponent;
  int _iFieldR, _iFieldC;
  mutable std::map<int, winslowDataAtGaussPoint> _data;
  mutable std::map<int, winslowDataAtNode> _dataNode;
  void createData(MElement *) const;
  void createDataNode(MElement *) const;

public:
  void setFieldC(int i) { _iFieldC = i; }
  void setFieldR(int i) { _iFieldR = i; }
  // element matrix size : 3 dofs per vertex
  virtual int sizeOfR(SElement *se) const
  {
    return se->getMeshElement()->getNumShapeFunctions();
  }
  virtual int sizeOfC(SElement *se) const
  {
    return se->getMeshElement()->getNumShapeFunctions();
  }
  // order dofs in the local matrix :
  // dx1, dx2 ... dxn, dy1, ..., dyn, dz1, ... dzn
  Dof getLocalDofR(SElement *se, int iRow) const
  {
    MElement *e = se->getMeshElement();
    int iCompR = iRow / (int)e->getNumShapeFunctions();
    int ithLocalVertex = iRow % (int)e->getNumShapeFunctions();
    return Dof(e->getShapeFunctionNode(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iCompR, _iFieldR));
  }
  Dof getLocalDofC(SElement *se, int iCol) const
  {
    MElement *e = se->getMeshElement();
    int iCompC = iCol / (int)e->getNumShapeFunctions();
    int ithLocalVertex = iCol % (int)e->getNumShapeFunctions();
    return Dof(e->getShapeFunctionNode(ithLocalVertex)->getNum(),
               Dof::createTypeWithTwoInts(iCompC, _iFieldC));
  }
  /* void computeMetricContrav(fullMatrix<double> &metricContrav, double GradsComput[100][3], MElement *newEl) const; */
  void computeMetricContrav(fullMatrix<double> &metricContrav, int i, MElement *newEl, MElement *linEl) const;
  
public:
 winslowTerm(GModel *gm, std::map<MVertex *, SVector3> *alpha, std::map<MVertex *, SVector3> *currentSolution, int idComponent, int fieldr, int fieldc)
   : femTerm<double>(gm), _alpha(alpha), _currentSolution(currentSolution), _idComponent(idComponent), _iFieldR(fieldr), _iFieldC(fieldc)
  {
  }
  
 winslowTerm(GModel *gm, std::map<MVertex *, SVector3> *alpha, std::map<MVertex *, SVector3> *currentSolution, int idComponent, int fieldr)
    : femTerm<double>(gm), _alpha(alpha), _currentSolution(currentSolution), _idComponent(idComponent),  _iFieldR(fieldr), _iFieldC(fieldr)
  {
  }
  
  void elementMatrix(SElement *se, fullMatrix<double> &m) const;
  void elementVector(SElement *se, fullVector<double> &m) const;
};

#endif
