// THIS FILE WILL BE REMOVED AS SOON AS THE NEW SOLVER INTERFACE IS READY

// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _GMSH_HELMHOLTZ_H_
#define _GMSH_HELMHOLTZ_H_

#include <complex>
#include "gmshTermOfFormulation.h"
#include "gmshFunction.h"
#include "Gmsh.h"
#include "GModel.h"
#include "MElement.h"
#include "GmshMatrix.h"

class gmshHelmholtzTerm : public gmshNodalFemTerm<std::complex<double> > {
 private:
  const gmshFunction<std::complex<double> > *_waveNumber;
  const int _iField ;
 protected:
  virtual int sizeOfR(MElement *e) const { return e->getNumVertices(); }
  virtual int sizeOfC(MElement *e) const { return e->getNumVertices(); }
  void getLocalDofR(MElement *e, int iRow, MVertex **vR, int *iCompR, int *iFieldR) const
  {
    *vR = e->getVertex(iRow);
    *iCompR = 0;
    *iFieldR = _iField;
  }
 public:
  gmshHelmholtzTerm(GModel *gm, gmshFunction<std::complex<double> > *waveNumber, 
                    int iField = 0) 
  : gmshNodalFemTerm<std::complex<double> >(gm), _waveNumber(waveNumber), _iField(iField){}
  virtual void elementMatrix(MElement *e, gmshMatrix<std::complex<double> > &m) const;
};

#endif
