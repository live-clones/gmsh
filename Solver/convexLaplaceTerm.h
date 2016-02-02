// Gmsh - Copyright (C) 1997-2015 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to the public mailing list <gmsh@geuz.org>.

#ifndef _CONVEX_LAPLACE_TERM_H_
#define _CONVEX_LAPLACE_TERM_H_

#include "laplaceTerm.h"

// \nabla \cdot k \nabla U
class convexLaplaceTerm : public laplaceTerm { 
 public:
 convexLaplaceTerm(GModel *gm, int iField, simpleFunction<double> *k,std::map<MVertex*, SPoint3> *coord=NULL)
   : laplaceTerm(gm,iField,k,coord) {}
  virtual void elementMatrix(SElement *se, fullMatrix<double> &m) const
  {

    laplaceTerm::elementMatrix(se,m);

    MElement *e = se->getMeshElement();
    const int nbSF = e->getNumShapeFunctions();

    double tr = 0.;
    for (int j = 0; j<nbSF; j++)
      tr += m(j,j);
    tr /= nbSF;
    
    // thredshold, alpha in (0;1)
    double alpha = .1; 

    for (int j = 0; j < nbSF; j++){
      for (int k = 0; k < j; k++){	
	if( m(j,k) > -alpha*tr){
          double delta = m(j,k) + alpha*tr;
	  m(j,j) += delta;
	  m(k,k) += delta;
	  m(j,k) -= delta;
	  m(k,j) -= delta;
	}        
      }
    }

  }

};




#endif
