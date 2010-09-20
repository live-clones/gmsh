// Gmsh - Copyright (C) 1997-2010 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LAPLACE_TERM_H_
#define _LAPLACE_TERM_H_

#include "helmholtzTerm.h"

// \nabla \cdot k \nabla U 
class laplaceTerm : public helmholtzTerm<double> {
 protected:
 std::map<MVertex*, SPoint3> *_coordView;
  const int _iField;
 public:
 laplaceTerm(GModel *gm, int iField, simpleFunction<double> *k,  
	     std::map<MVertex*, SPoint3> *coord=NULL)
   : helmholtzTerm<double>(gm, iField, iField, k, 0), _iField(iField), _coordView(coord) {}
 void elementVector(SElement *se, fullVector<double> &m) const
  {

    MElement *e = se->getMeshElement();
    int nbNodes = e->getNumVertices(); 

    fullMatrix<double> *mat;
    mat = new fullMatrix<double>(nbNodes,nbNodes);
    elementMatrix(se, *mat);

    fullVector<double> val(nbNodes);
    val.scale(0.);
    for (int i = 0; i < nbNodes; i++){
      std::map<MVertex*, SPoint3>::iterator it = _coordView->find(e->getVertex(i));
      SPoint3 UV = it->second;
      if (_iField == 1)  val(i) = UV.x();
      else if (_iField == 2)  val(i) = UV.y();
    }

    m.scale(0.);
    for (int i = 0; i < nbNodes; i++)
      for (int j = 0; j < nbNodes; j++)
    	m(i)  +=  -(*mat)(i,j)*val(j);
      
  }
};

// a \nabla U 
class massTerm : public helmholtzTerm<double> {
 public:
  massTerm(GModel *gm, int iField, simpleFunction<double> *a)
    : helmholtzTerm<double>(gm, iField, iField, 0, a) {}
};


#endif
