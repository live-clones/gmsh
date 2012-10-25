#ifndef _CURLBASIS_H_
#define _CURLBASIS_H_

#include "BasisVector.h"

/**
   @class CurlBasis
   @brief The Curl of an other Basis
 
   This class can instantiate a Curl Basis.
 */

class CurlBasis: public BasisVector{
 public:
  //! @param other An Other Basis
  //!
  //! Returns a new Basis, which is the curl of
  //! the given Basis
  CurlBasis(const BasisVector& other);
  
  //! Deletes this Basis
  //!
  virtual ~CurlBasis(void);
};

#endif
