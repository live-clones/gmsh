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

/*
  Formulation of winslow with mesh elements as parametric space
*/

class winslowTerm : public femTerm<double> {
protected:
  double _e, _nu;
  int _iFieldR, _iFieldC;
  SVector3 _volumeForce;
  mutable std::map<int, winslowDataAtGaussPoint> _data;
  void createData(MElement *) const;

public:
  void setFieldC(int i) { _iFieldC = i; }
  void setFieldR(int i) { _iFieldR = i; }
  // element matrix size : 3 dofs per vertex
  virtual int sizeOfR(SElement *se) const
  {
    return 3 * se->getMeshElement()->getNumShapeFunctions();
  }
  virtual int sizeOfC(SElement *se) const
  {
    return 3 * se->getMeshElement()->getNumShapeFunctions();
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

public:
  winslowTerm(GModel *gm, double E, double nu, int fieldr, int fieldc)
    : femTerm<double>(gm), _e(E), _nu(nu), _iFieldR(fieldr), _iFieldC(fieldc)
  {
  }
  winslowTerm(GModel *gm, double E, double nu, int fieldr)
    : femTerm<double>(gm), _e(E), _nu(nu), _iFieldR(fieldr), _iFieldC(fieldr)
  {
  }
  void setVector(const SVector3 &f) { _volumeForce = f; }
  void elementMatrix(SElement *se, fullMatrix<double> &m) const;
  void elementVector(SElement *se, fullVector<double> &m) const;
};

#endif
