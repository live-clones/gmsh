// Gmsh - Copyright (C) 1997-2019 C. Geuzaine, J.-F. Remacle
//
// See the LICENSE.txt file for license information. Please report all
// issues on https://gitlab.onelab.info/gmsh/gmsh/issues.

#include "GmshMessage.h"
#include "ElementType.h"
#include "BergotBasis.h"
#include "CGNSCommon.h"

#if defined(HAVE_LIBCGNS)


int cgnsError(const char *file, const int line, const int fileIndex)
{
  Msg::Error("%s:%i: Error from CGNS library -- %s", file, line,
             cg_get_error());
  if(fileIndex != -1) {
    if(cg_close(fileIndex)) {
      Msg::Error("Unable to close CGNS file");
    }
  }
  return 0;
}


void printProgress(const char *cstr, std::size_t i, std::size_t num)
{
  if(num > 100) {
    if(i % 100 == 1) {
      Msg::Info("%s %d/%d", cstr, i, num);
    }
  }
  else {
    Msg::Info("%s %d/%d", cstr, i, num);
  }
}


#if defined(HAVE_LIBCGNS_CPEX0045)


int evalMonomialBasis(int mshType, const std::vector<double> &u,
                      const std::vector<double> &v,
                      const std::vector<double> &w, fullMatrix<double> &val)
{
  // get parent type and order
  const int parentType = ElementType::getParentType(mshType);
  const int order = ElementType::getOrder(mshType);
  
  // get serendipity
  const int serend = ElementType::getSerendipity(mshType);
  if(serend > 1) {
    Msg::Error("Serendipity elements are not supported in CPEX0045 mode in "
               "CGNS reader");
    return 0;
  }

  // compute values of monomials at given points
  int nbPt = u.size();
  if(parentType == TYPE_PNT) {
    val(0, 0) = 1.;
  }
  else if(parentType == TYPE_LIN) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      val(0, iPt) = 1.;
      for(int i = 1; i <= order; i++) val(i, iPt) = u[iPt] * val(i-1, iPt); 
    }
  }
  else if(parentType == TYPE_TRI) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          val(iSF, iPt) = std::pow(u[iPt], i-j) * std::pow(v[iPt], j);
          iSF++;
        }
      }
    }
  }
  else if(parentType == TYPE_QUA) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= order; j++) {
          val(iSF, iPt) = std::pow(u[iPt], i) * std::pow(v[iPt], j);
          iSF++;
        }
      }
    }
  }
  else if(parentType == TYPE_TET) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          for (int k = 0; k <= i-j; k++) {
            val(iSF, iPt) = std::pow(u[iPt], i-j-k) * std::pow(v[iPt], k) *
                            std::pow(w[iPt], j);
            iSF++;
          }
        }
      }
    }
  }
  else if(parentType == TYPE_PYR) {
    int nbSF = ElementType::getNumVertices(mshType);
    BergotBasis bb(order);
    for(int iPt = 0; iPt < nbPt; iPt++) {
      double oneVal[385];
      const double ww = 0.5 * (w[iPt] + 1.);  // use Gmsh coord for BergotBasis 
      bb.f(u[iPt], v[iPt], ww, oneVal);
      for(int iSF = 0; iSF < nbSF; iSF++) val(iSF, iPt) = oneVal[iSF];
    }
  }
  else if(parentType == TYPE_PRI) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= i; j++) {
          for (int k = 0; k <= order; k++) {
            val(iSF, iPt) = std::pow(u[iPt], i-j) * std::pow(v[iPt], j) * std::pow(w[iPt], k);  // TODO: to be clarified
            iSF++;
          }
        }
      }
    }
  }
  else if(parentType == TYPE_HEX) {
    for(int iPt = 0; iPt < nbPt; iPt++) {
      int iSF = 0;
      for(int i = 0; i <= order; i++) {
        for (int j = 0; j <= order; j++) {
          for (int k = 0; k <= order; k++) {
            val(iSF, iPt) = std::pow(u[iPt], i) * std::pow(v[iPt], j) * std::pow(w[iPt], k);
            iSF++;
          }
        }
      }
    }
  }
  else {
    Msg::Error("Element of parent type %i is not supported in CPEX0045 mode "
               "in CGNS reader", parentType);
    return 0;
  }

  return 1;
}


#endif // HAVE_LIBCGNS_CPEX0045


#endif // HAVE_LIBCGNS
