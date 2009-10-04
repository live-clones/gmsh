// Gmsh - Copyright (C) 1997-2009 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// bugs and problems to <gmsh@geuz.org>.

#ifndef _LINEAR_SYSTEM_TAUCS_H_
#define _LINEAR_SYSTEM_TAUCS_H_

#include "linearSystemCSR.h"

template <class scalar>
class linearSystemCSRTaucs : public linearSystemCSR<scalar> {
 public:
  linearSystemCSRTaucs(){}
  virtual ~linearSystemCSRTaucs(){}
  virtual void addToMatrix(int il, int ic, double val)
  {
    if (il <= ic)
      linearSystemCSR<scalar>::addToMatrix(il, ic, val);
  }
  virtual int systemSolve() 
#if !defined(HAVE_TAUCS)
  {
    Msg::Error("TAUCS is not available in this version of Gmsh");
    return 0;
  }
#endif
  ;
};

#endif
